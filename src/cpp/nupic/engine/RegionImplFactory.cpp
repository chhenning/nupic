/* ---------------------------------------------------------------------
 * Numenta Platform for Intelligent Computing (NuPIC)
 * Copyright (C) 2013-2015, Numenta, Inc.  Unless you have an agreement
 * with Numenta, Inc., for a separate license for this software code, the
 * following terms and conditions apply:
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Affero Public License for more details.
 *
 * You should have received a copy of the GNU Affero Public License
 * along with this program.  If not, see http://www.gnu.org/licenses.
 *
 * http://numenta.org/licenses/
 * ---------------------------------------------------------------------
 */

#include <stdexcept>

#include <nupic/engine/RegionImplFactory.hpp>
#include <nupic/engine/RegionImpl.hpp>
#include <nupic/engine/Region.hpp>
#include <nupic/engine/RegisteredRegionImpl.hpp>
#include <nupic/engine/Spec.hpp>
#include <nupic/os/DynamicLibrary.hpp>
#include <nupic/os/Path.hpp>
#include <nupic/os/OS.hpp>
#include <nupic/os/Env.hpp>
#include <nupic/ntypes/Value.hpp>
#include <nupic/ntypes/BundleIO.hpp>
#include <nupic/encoders/ScalarSensor.hpp>
#include <nupic/engine/YAMLUtils.hpp>
#include <nupic/engine/TestNode.hpp>
#include <nupic/regions/VectorFileEffector.hpp>
#include <nupic/regions/VectorFileSensor.hpp>
#include <nupic/utils/Log.hpp>
#include <nupic/utils/StringUtils.hpp>

// from http://stackoverflow.com/a/9096509/1781435
#define stringify(x)  #x
#define expand_and_stringify(x) stringify(x)

namespace nupic
{
  // Keys are Python modules and the values are sets of class names for the
  // regions that have been registered in the corresponding module. E.g.
  // pyRegions["nupic.regions.sample_region"] = "SampleRegion"
  static std::map<const std::string, std::set<std::string>> pyRegions;

  // Mappings for C++ regions
  static std::map<const std::string, GenericRegisteredRegionImpl*> cppRegions;

  bool initializedRegions = false;

  // Allows the user to add custom regions
  void RegionImplFactory::registerPyRegion(const std::string module, const std::string className)
  {
    // Verify that no regions exist with the same className in any module
    for (auto pyRegion : pyRegions)
    {
      if (pyRegion.second.find(className) != pyRegion.second.end())
      {
        if (pyRegion.first != module)
        {
          // New region class name conflicts with previously registered region
          NTA_THROW << "A pyRegion with name '" << className << "' already exists. "
                    << "Unregister the existing region or register the new region using a "
                    << "different name.";
        } else {
          // Same region registered again, ignore
          return;
        }
      }
    }

    // Module hasn't been added yet
    if (pyRegions.find(module) == pyRegions.end())
    {
      pyRegions[module] = std::set<std::string>();
    }

    pyRegions[module].insert(className);
  }

  void RegionImplFactory::registerPyBindRegion(const std::string& module, const std::string& className)
  {
      // Verify that no regions exist with the same className in any module
      for (auto pyRegion : pyRegions)
      {
          if (pyRegion.second.find(className) != pyRegion.second.end())
          {
              if (pyRegion.first != module)
              {
                  // New region class name conflicts with previously registered region
                  NTA_THROW << "A pyRegion with name '" << className << "' already exists. "
                      << "Unregister the existing region or register the new region using a "
                      << "different name.";
              }
              else {
                  // Same region registered again, ignore
                  return;
              }
          }
      }

      // Module hasn't been added yet
      if (pyRegions.find(module) == pyRegions.end())
      {
          pyRegions[module] = std::set<std::string>();
      }

      pyRegions[module].insert(className);
  }

  void RegionImplFactory::registerCPPRegion(const std::string name,
                                            GenericRegisteredRegionImpl * wrapper)
  {
    if (cppRegions.find(name) != cppRegions.end())
    {
      NTA_WARN << "A CPPRegion already exists with the name '"
               << name << "'. Overwriting it...";
    }
    cppRegions[name] = wrapper;
  }

  void RegionImplFactory::unregisterPyRegion(const std::string className)
  {
    for (auto pyRegion : pyRegions)
    {
      if (pyRegion.second.find(className) != pyRegion.second.end())
      {
        pyRegions.erase(pyRegion.first);
        return;
      }
    }
    NTA_WARN << "A pyRegion with name '" << className <<
    "' doesn't exist. Nothing to unregister...";
  }
  
  void RegionImplFactory::unregisterPyBindRegion(const std::string& className)
  {
      for (auto pyRegion : pyRegions)
      {
          if (pyRegion.second.find(className) != pyRegion.second.end())
          {
              pyRegions.erase(pyRegion.first);
              return;
          }
      }
      NTA_WARN << "A pyRegion with name '" << className <<
          "' doesn't exist. Nothing to unregister...";
  }

  void RegionImplFactory::unregisterCPPRegion(const std::string name)
  {
    if (cppRegions.find(name) != cppRegions.end())
    {
      cppRegions.erase(name);
      return;
    }
  }

RegionImplFactory & RegionImplFactory::getInstance()
{
  static RegionImplFactory instance;

  // Initialize Regions
  if (!initializedRegions)
  {
    // Create C++ regions
    cppRegions["ScalarSensor"] = new RegisteredRegionImpl<ScalarSensor>();
    cppRegions["TestNode"] = new RegisteredRegionImpl<TestNode>();
    cppRegions["VectorFileEffector"] = new RegisteredRegionImpl<VectorFileEffector>();
    cppRegions["VectorFileSensor"] = new RegisteredRegionImpl<VectorFileSensor>();

    initializedRegions = true;
  }

  return instance;
}


RegionImpl* RegionImplFactory::createRegionImpl(const std::string nodeType,
    const std::string nodeParams,
    Region* region)
{

    RegionImpl *impl = nullptr;
    Spec *ns = getSpec(nodeType);
    ValueMap vm = YAMLUtils::toValueMap(
        nodeParams.c_str(),
        ns->parameters,
        nodeType,
        region->getName());

    if (cppRegions.find(nodeType) != cppRegions.end())
    {
        impl = cppRegions[nodeType]->createRegionImpl(vm, region);
    }
    //@todo
    //else if ((nodeType.find(std::string("py.")) == 0))
    //{
    //    if (!pyLib_)
    //        pyLib_ = std::shared_ptr<DynamicPythonLibrary>(new DynamicPythonLibrary());

    //    impl = createPyNode(pyLib_.get(), nodeType, &vm, region);
    //}
    else
    {
        NTA_THROW << "Unsupported node type '" << nodeType << "'";
    }

    return impl;
}


RegionImpl* RegionImplFactory::deserializeRegionImpl(const std::string nodeType,
    BundleIO& bundle,
    Region* region)
{

    RegionImpl *impl = nullptr;

    if (cppRegions.find(nodeType) != cppRegions.end())
    {
        impl = cppRegions[nodeType]->deserializeRegionImpl(bundle, region);
    }
    //@todo
    //else if (StringUtils::startsWith(nodeType, "py."))
    //{
    //    if (!pyLib_)
    //        pyLib_ = std::shared_ptr<DynamicPythonLibrary>(new DynamicPythonLibrary());

    //    impl = deserializePyNode(pyLib_.get(), nodeType, bundle, region);
    //}
    else
    {
        NTA_THROW << "Unsupported node type '" << nodeType << "'";
    }
    return impl;

}


Spec * RegionImplFactory::getSpec(const std::string nodeType)
{
    std::map<std::string, Spec*>::iterator it;
    // return from cache if we already have it
    it = nodespecCache_.find(nodeType);
    if (it != nodespecCache_.end())
        return it->second;

    // grab the nodespec and cache it
    // one entry per supported node type
    Spec * ns = nullptr;
    if (cppRegions.find(nodeType) != cppRegions.end())
    {
        ns = cppRegions[nodeType]->createSpec();
    }
    //@todo
    //else if (nodeType.find(std::string("py.")) == 0)
    //{
    //    if (!pyLib_)
    //        pyLib_ = std::shared_ptr<DynamicPythonLibrary>(new DynamicPythonLibrary());

    //    ns = getPySpec(pyLib_.get(), nodeType);
    //}
    else
    {
        NTA_THROW << "getSpec() -- Unsupported node type '" << nodeType << "'";
    }

    if (!ns)
        NTA_THROW << "Unable to get node spec for: " << nodeType;

    nodespecCache_[nodeType] = ns;
    return ns;
}

void RegionImplFactory::cleanup()
{
    std::map<std::string, Spec*>::iterator ns;
    // destroy all nodespecs
    for (ns = nodespecCache_.begin(); ns != nodespecCache_.end(); ns++)
    {
        assert(ns->second != nullptr);
        // PyNode node specs are destroyed by the C++ PyNode
        if (ns->first.substr(0, 3) == "py.")
        {
            std::string noClass = "";
            //@todo
            //pyLib_->destroySpec(ns->first, noClass);
        }
        else
        {
            delete ns->second;
        }

        ns->second = nullptr;
    }

    nodespecCache_.clear();

    // destroy all RegisteredRegionImpls
    for (auto rri = cppRegions.begin(); rri != cppRegions.end(); rri++)
    {
        NTA_ASSERT(rri->second != nullptr);
        delete rri->second;
        rri->second = nullptr;
    }

    cppRegions.clear();
    initializedRegions = false;

    // Never release the Python dynamic library!
    // This is due to cleanup issues of Python itself
    // See: http://docs.python.org/c-api/init.html#Py_Finalize
    //pyLib_.reset();
}



}
