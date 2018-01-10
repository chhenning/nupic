#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>

#include <nupic/engine/Link.hpp>
#include <nupic/engine/Network.hpp>
#include <nupic/engine/Region.hpp>
#include <nupic/engine/Spec.hpp>

namespace py = pybind11;
using namespace nupic;

namespace nupic_ext
{
    // Keys are Python modules and the values are sets of class names for the
    // regions that have been registered in the corresponding module. E.g.
    // pyRegions["nupic.regions.sample_region"] = "SampleRegion"
    static std::map<const std::string, std::set<std::string>> pyRegions;



    void init_Engine(py::module& m)
    {
        ///////////////////
        // Dimensions
        ///////////////////

        py::class_<Dimensions> py_Dimensions(m, "Dimensions");

        // constructors
        py_Dimensions.def(py::init<>())
            .def(py::init<std::vector<size_t>>())
            .def(py::init<size_t>())
            .def(py::init<size_t, size_t>())
            .def(py::init<size_t, size_t, size_t>());
            
        // members
        py_Dimensions.def("getCount", &Dimensions::getCount)
            .def("getDimensionCount", &Dimensions::getDimensionCount)
            .def("getDimension", &Dimensions::getDimension)
            .def("isUnspecified", &Dimensions::isUnspecified)
            .def("isDontcare", &Dimensions::isDontcare)
            .def("isSpecified", &Dimensions::isSpecified)
            .def("isOnes", &Dimensions::isOnes)
            .def("isValid", &Dimensions::isValid)
            .def("getIndex", &Dimensions::getIndex)
            .def("getCoordinate", &Dimensions::getCoordinate)
            .def("toString", &Dimensions::toString, "", py::arg("humanReadable") = true)
            .def("promote", &Dimensions::promote)
            ;

        // operator overloading
        py_Dimensions.def(py::self == py::self)
            .def(py::self != py::self);

        // python slots
        py_Dimensions.def("__str__", &Dimensions::toString)
            .def("__repr__", &Dimensions::toString);

        ///////////////////
        // Link
        ///////////////////
        py::class_<Link, std::shared_ptr<Link>> py_Link(m, "Link");

        // constructors
        py_Link.def(py::init<>())
            .def(py::init<const std::string&, const std::string&
                , const std::string&, const std::string&
                , const std::string&, const std::string&
                , size_t>()
                , ""
                , py::arg("linkType"), py::arg("linkParams")
                , py::arg("srcRegionName"), py::arg("destRegionName")
                , py::arg("srcOutputName") = "", py::arg("destInputName") = ""
                , py::arg("propagationDelay") = 0);




        ///////////////////
        // Spec
        ///////////////////
        py::class_<Spec> py_Spec(m, "Spec");

        ///////////////////
        // Region
        ///////////////////

        py::class_<Region, std::shared_ptr<Region>> py_Region(m, "Region");
        
        py_Region.def("getName", &Region::getName)
            .def("getType", &Region::getType)
            .def("getDimensions", &Region::getDimensions)
            .def("setDimensions", &Region::setDimensions);
        
        /*
        
        getSpec

        static member
        getSpecFromType
        */


        ///////////////////
        // Network
        ///////////////////

        py::class_<Network> py_Network(m, "Network");
        
        // constructors
        py_Network.def(py::init<>())
            .def(py::init<std::string>());

        py_Network.def("addRegion", &nupic::Network::addRegion)
            .def("getRegions", &nupic::Network::getRegions)
            .def("getLinks", &nupic::Network::getLinks);

        py_Network.def("initialize", &nupic::Network::initialize);

        py_Network.def("link", &nupic::Network::link
            , ""
            , py::arg("srcName"), py::arg("destName")
            , py::arg("linkType"), py::arg("linkParams")
            , py::arg("srcOutput") = "", py::arg("destInput") = "", py::arg("propagationDelay") = 0);


        py_Network.def_static("registerPyRegion", [](const std::string& module, const std::string& class_name)
        {
            // Verify that no regions exist with the same className in any module
            for (auto pyRegion : pyRegions)
            {
                if (pyRegion.second.find(class_name) != pyRegion.second.end())
                {
                    if (pyRegion.first != module)
                    {
                        // New region class name conflicts with previously registered region
                        NTA_THROW << "A pyRegion with name '" << class_name << "' already exists. "
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

            pyRegions[module].insert(class_name);
        });
        
        py_Network.def_static("unregisterPyRegion", [](const std::string& class_name)
        {
            for (auto pyRegion : pyRegions)
            {
                if (pyRegion.second.find(class_name) != pyRegion.second.end())
                {
                    pyRegions.erase(pyRegion.first);
                    return;
                }
            }
            NTA_WARN << "A pyRegion with name '" << class_name <<
                "' doesn't exist. Nothing to unregister...";

        });


        ///////////////////
        // Collection
        ///////////////////

        // Regions
        typedef Collection<std::shared_ptr<Region>> Region_Collection_t;
        py::class_<Region_Collection_t> py_RegionCollection(m, "RegionCollection");
        py_RegionCollection.def("getByName", &Region_Collection_t::getByName);

        // bare bone sequence protocol
        py_RegionCollection.def("__len__", &Region_Collection_t::getCount);
        py_RegionCollection.def("__getitem__", [](Region_Collection_t& coll, size_t i) 
        { 
            if (i >= coll.getCount())
            {
                throw py::index_error();
            }

            return coll.getByIndex(i); 
        });
        
        // Links
        typedef Collection<std::shared_ptr<Link>> Link_Collection_t;
        py::class_<Link_Collection_t> py_LinkCollection(m, "Link_Collection_t");
        py_LinkCollection.def("getByName", &Link_Collection_t::getByName);
        
        // bare bone sequence protocol
        py_LinkCollection.def("__len__", &Link_Collection_t::getCount);
        py_LinkCollection.def("__getitem__", [](Link_Collection_t& coll, size_t i)
        {
            if (i >= coll.getCount())
            {
                throw py::index_error();
            }

            return coll.getByIndex(i);
        });

        // not sure we need __iter__
        //py_LinkCollection.def("__iter__", [](Link_Collection_t& coll) { return py::make_iterator(coll.begin(), coll.end()); }, py::keep_alive<0, 1>());
    }

} // namespace nupix_ext
