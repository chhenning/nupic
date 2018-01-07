#ifndef NUPIC_EXT_BINDINGS_PY_UTILS_HPP
#define NUPIC_EXT_BINDINGS_PY_UTILS_HPP

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

namespace nupic_ext {

    template<typename T> T* get_it(py::array_t<T>& a) { return (T*)a.request().ptr; }
    template<typename T> T* get_end(py::array_t<T>& a) { return ((T*)a.request().ptr) + a.size(); }

} // namespace nupic_ext


#endif //NUPIC_EXT_BINDINGS_PY_UTILS_HPP