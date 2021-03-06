#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace nupic_ext
{
    void init_Random(py::module&);
    void init_SM32(py::module&);
    void init_SM_01_32_32(py::module&);
    void init_Math_Functions(py::module&);
    void init_SMC(py::module&);
    void init_SegmentSparseMatrix(py::module&);

    void init_Engine(py::module&);
    void init_HTM(py::module&);
    void init_SVM(py::module&);
    void init_reals(py::module&);
    void init_Cells4(py::module&);
    void init_SDR_Classifier(py::module&);
    void init_Spatial_Pooler(py::module&);
    void init_NearestNeighbor(py::module&);
    void init_SparseTensor(py::module&);
    void init_Domain(py::module&);
    void init_TensorIndex(py::module&);
    void init_algorithms(py::module&);
    void init_array_algo(py::module&);
    void init_Regions(py::module&);
} // namespace nupix_ext


using namespace nupic_ext; 

PYBIND11_MODULE(bindings, m) {
    m.doc() = "nupic plugin"; // optional module docstring

    init_reals(m);

    auto utils_module = m.def_submodule("utils");
    
    auto math_module = m.def_submodule("math");
    init_reals(math_module);
    init_Random(math_module);
    init_SM32(math_module);
    init_SM_01_32_32(math_module);
    init_Math_Functions(math_module);
    init_SMC(math_module);
    init_SegmentSparseMatrix(math_module);
    init_NearestNeighbor(math_module);
    init_SparseTensor(math_module);
    init_TensorIndex(math_module);
    init_Domain(math_module);
    init_array_algo(math_module);

    auto engine_module = m.def_submodule("engine");
    init_Engine(engine_module);

    auto regions_module = m.def_submodule("regions");
    init_Regions(regions_module);

    auto algorithms_module = m.def_submodule("algorithms");
    init_algorithms(algorithms_module);
    init_HTM(algorithms_module);
    init_SVM(algorithms_module);
    init_Cells4(algorithms_module);
    init_SDR_Classifier(algorithms_module);
    init_Spatial_Pooler(algorithms_module);
}
