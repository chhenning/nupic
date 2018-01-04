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

}
