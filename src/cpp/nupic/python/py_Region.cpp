#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include <nupic/python/PyBindRegion.hpp>


namespace py = pybind11;

namespace nupic_ext
{
    void init_PyBindRegion(py::module& m)
    {
        typedef nupic::PyBindRegion Region_t;

        py::class_<Region_t> py_Region(m, "PyBindRegion");

        py_Region.def("initialize", &Region_t::initialize)
            .def("compute", &Region_t::compute);

        py_Region.def("getSpec", &Region_t::getSpec);
    }
} // namespace nupix_ext
