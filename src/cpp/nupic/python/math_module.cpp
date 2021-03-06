#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace nupic_ext
{
    void init_array_algo(py::module&);
    void init_Domain(py::module&);
    void init_Gaussian_2D(py::module&);
    void init_Math_Functions(py::module&);
    void init_NearestNeighbor(py::module&);
    void init_Random(py::module&);
    void init_reals(py::module&);
    void init_Set(py::module&);
    void init_SM_01_32_32(py::module&);
    void init_SM32(py::module&);
    void init_SMC(py::module&);
    void init_SegmentSparseMatrix(py::module&);
    void init_SparseTensor(py::module&);
    void init_TensorIndex(py::module&);
    void init_SparseMatrixAlgorithms(py::module&);
    void init_SparseRLEMatrix(py::module&);
    void init_graph_algo(py::module&);
} // namespace nupix_ext

using namespace nupic_ext; 

PYBIND11_MODULE(math, m) {
    m.doc() = "nupic.bindings.math plugin"; // optional module docstring

    init_array_algo(m);
    init_Domain(m);
    init_graph_algo(m);
    init_Gaussian_2D(m);
    init_SM32(m); // has to be defined by before NearestNeighbor
    init_NearestNeighbor(m);
    init_Math_Functions(m);
    init_Random(m);
    init_reals(m);
    init_SegmentSparseMatrix(m);
    init_Set(m);
    init_SM_01_32_32(m);
    init_SMC(m);
    init_SparseTensor(m);
    init_SparseMatrixAlgorithms(m);
    init_SparseRLEMatrix(m);
    init_TensorIndex(m);
}
