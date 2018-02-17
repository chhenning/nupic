!!! THIS IS WORK IN PROGRESS !!!

python 3 version of nupic.

For the simple syntax changes I used the 2to3 tool. The command line is:

python c:\Python36\Tools\scripts\2to3.py --output-dir d:\test -W -n d:\nupic\src\python\python27





| File                                                             | python3                               | github issue | output                                                |
|------------------------------------------------------------------|---------------------------------------|--------------|-------------------------------------------------------|
| examples/sp/hello_sp.py                                          | yes                                   |              | nupic\test\python3\output\hello_sp.py.txt             |  
| examples/tm/hello_tm.py                                          | yes                                   |              | nupic\test\python3\output\hello_tm.py.txt             |
| examples/tm/sparse_matrix_how_to.py                              | yes (some modifications)              |              | nupic\test\python3\output\sparse_matrix_how_to.py.txt |
| examples/tm/svm_how_to.py                                        | yes (some modifications)              |              | nupic\test\python3\output\svm_how_to.py.txt           |
| tests/bindings/                                                  | yes                                   |              |                                                       |
| tests/bindings/array_algorithms_test.py                          | yes                                   |              |                                                       |
| tests/bindings/cast_mode_test.py                                 | yes                                   |              |                                                       |
| tests/bindings/check_test.py                                     | yes                                   |              |                                                       |
| tests/bindings/connections_test.py                               | yes                                   |              |                                                       |
| tests/bindings/network_test.py                                   | yes                                   |              |                                                       |
| tests/bindings/nupic_random_test.py                              | yes (some modifications)              |              |                                                       |
| tests/bindings/pyregion_test.py                                  | yes                                   |              |                                                       |
| tests/bindings/segment_sparse_matrix_test.py                     | yes                                   |              |                                                       |
| tests/bindings/sparse_binary_matrix_test.py                      | yes                                   |              |                                                       |
| tests/bindings/sparse_matrix_test.py                             | some AssertionErrors                  | #27          |                                                       |
| tests/bindings/temporal_memory_test.py                           | yes                                   |              |                                                       |
| tests/bindings/algorithms/cells4_test.py                         | yes                                   |              |                                                       |
| tests/bindings/algorithms/svm_test.py                            | yes                                   |              |                                                       |
| tests/unit/nupic/serializable_test.py                            | yes                                   |              |                                                       |
| tests/unit/nupic/utils.py                                        | yes                                   |              |                                                       |
| tests/unit/nupic/algorithms/anomaly_likelihood_jeff_test.py      | yes                                   |              |                                                       |
| tests/unit/nupic/algorithms/anomaly_likelihood_test.py           | yes                                   |              |                                                       |
| tests/unit/nupic/algorithms/anomaly_test.py                      | yes                                   |              |                                                                |
| tests/unit/nupic/algorithms/backtracking_tm_constant_test.py     | yes                                   |              | nupic\test\python3\output\backtracking_tm_constant_test.py.txt |
| tests/unit/nupic/algorithms/backtracking_tm_cpp.py               | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/backtracking_tm_cpp2_test.py         | AssertionError: False is not true     |              |                                             |
| tests/unit/nupic/algorithms/backtracking_tm_test.py              | yes                                   |              | nupic\test\python3\output\backtracking_tm_test.py.txt.py.txt |
| tests/unit/nupic/algorithms/connections_test.py                  | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/inhibition_object_test.py            | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/knn_classifier_test.py               | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/sdr_classifier_test.py               | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/sp_learn_inference.py                | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/sp_overlap_test.py                   | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_boost_test.py         | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_compatability_test.py | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_compute_test.py       | todo                                  |              |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_cpp_api_test.py       | todo                                  |              |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_cpp_unit_test.py      | todo                                  |              |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_py_api_test.py        | todo                                  |              |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_unit_test.py          | todo                                  |              |                                             |
| tests/unit/nupic/algorithms/temporal_memory_test.py              | yes                                   |              |                                             |
| tests/unit/nupic/data\generators\anomalyzer_test.py              | TypeError                             | #10          |                                             |
| tests/unit/nupic/data\generators\pattern_machine_test.py         | yes                                   |              |                                             |
| tests/unit/nupic/data\generators\sequence_machine_test.py        | yes                                   |              |                                             |
| tests/unit/nupic/data\aggregator_test.py                         | AssertionError                        | #11          |                                             |
| tests/unit/nupic/data\dictutils_test.py                          | yes                                   |              |                                             |
| tests/unit/nupic/data\fieldmeta_test.py                          | yes                                   |              |                                             |
| tests/unit/nupic/data\file_record_stream_test.py                 | TypeError                             | #10          |                                             |
| tests/unit/nupic/data\filters_test.py                            | yes                                   |              |                                             |
| tests/unit/nupic/data\functionsource_test.py                     | yes                                   |              |                                             |
| tests/unit/nupic/data\inference_shifter_test.py                  | yes                                   |              |                                             |
| tests/unit/nupic/data\record_stream_test.py                      | TypeError                             | #10          |                                             |
| tests/unit/nupic/data\utils_test.py                              | yes                                   |              |                                             |
| tests/unit/nupic/docs\examples_test.py                           | ModuleNotFoundError                   | #10          |                                             |
| tests/unit/nupic/encoders\adaptivescalar_test.py                 | TypeError                             | #13          |                                             |
| tests/unit/nupic/encoders\category_test.py                       | yes                                   |              |                                             |
| tests/unit/nupic/encoders\coordinate_test.py                     | yes                                   |              |                                             |
| tests/unit/nupic/encoders\date_test.py                           | AssertionError                        | #16          |                                             |
| tests/unit/nupic/encoders\delta_test.py                          | yes                                   |              |                                             |
| tests/unit/nupic/encoders\geospatial_coordinate_test.py          | AssertionError                        | #17          |                                             |
| tests/unit/nupic/encoders\logenc_test.py                         | AssertionError                        | #18          |                                             |
| tests/unit/nupic/encoders\multi_test.py                          | AssertionError                        | #18          |                                             |
| tests/unit/nupic/encoders\pass_through_encoder_test.py           | yes                                   |              |                                             |
| tests/unit/nupic/encoders\random_distributed_scalar_test.py      | AssertionError                        | #18          |                                             |
| tests/unit/nupic/encoders\scalarspace_test.py                    | yes                                   |              |                                             |
| tests/unit/nupic/encoders\scalar_test.py                         | AssertionError                        | #18          |                                             |
| tests/unit/nupic/encoders\sdrcategory_test.py                    | RuntimeError                          | #19          |                                             |
| tests/unit/nupic/encoders\sparse_pass_through_encoder_test.py    | yes                                   |              |                                             |
| tests/unit/nupic/engine\network_test.py                          | yes                                   |              |                                             | 
| tests/unit/nupic/engine\syntactic_sugar_test.py                  | AttributeError                        | #20          |                                             |
| tests/unit/nupic/engine\unified_py_parameter_test.py             | AttributeError                        | #20          |                                             |
| tests/unit/nupic/frameworks\opf\common_models\cluster_params_test.py          | AttributeError     | #20 | |
| tests/unit/nupic/frameworks\opf\htmpredictionmodel_classifier_helper_test.py  | RuntimeError       | #21 | |
| tests/unit/nupic/frameworks\opf\htmpredictionmodel_test.py                    | | | |
| tests/unit/nupic/frameworks\opf\opf_metrics_test.py                           | | | |
| tests/unit/nupic/frameworks\opf\previous_value_model_test.py                  | | | |
| tests/unit/nupic/frameworks\opf\safe_interpreter_test.py                      | | | |
| tests/unit/nupic/frameworks\opf\two_gram_model_test.py                        | RuntimeError | #22 | |
| tests/unit/nupic/math/lgamma_test.py                             | yes                                   |              |                                             |
| tests/unit/nupic/math/topology_test.py                           | disabled by default                   |              |                                             |
| tests/unit/nupic/regions/anomaly_likelihood_region_test.py       | yes                                   |              |                                             |
| tests/unit/nupic/regions/anomaly_region_test.py                  | yes                                   |              |                                             |
| tests/unit/nupic/regions/anomaly_region_test.py                  | yes                                   |              |                                             |
| tests/unit/nupic/regions/knn_anomaly_classifier_region_test.py   | RuntimeError       | #23 | | |
| tests/unit/nupic/regions/knn_classifier_region_test.py           | yes                |     | | |
| tests/unit/nupic/regions/record_sensor_region_test.py            | AttributeError     | #20 | | |
| tests/unit/nupic/regions/regions_spec_test.py                    | yes                |     | | |
| tests/unit/nupic/regions/sdr_classifier_region_test.py           | AttributeError     | #20 | | |
| tests/unit/nupic/regions/tm_region_test.py                       | yes                |     | | |
| tests/unit/nupic/support/configuration_test.py                   | RuntimeError       | #21 | | |
| tests/unit/nupic/support/consoleprinter_test                     | disabled           |     | | |
| tests/unit/nupic/support/custom_configuration_test.py            | RuntimeError       | #21 | | |
| tests/unit/nupic/support/decorators_test.py                      | yes                |     | | |
| tests/unit/nupic/support/group_by_test.py                        | yes                |     | | |
| tests/unit/nupic/support/object_json_test.py                     | AssertionError     | #24 | | |







# python 3 dependencies

pip install asteval
pip install pymysql
pip install pyproj
pip install validictory
pip install DBUtils
pip install prettytable
pip install psutil



# python 3 manual changes

from mock import MagicMock, patch
to
from unittest.mock import MagicMock, patch


__builtin__
to
builtins


Error: TypeError: 'float' object cannot be interpreted as an integer
for i in range(n / w):
to
for i in range(n // w):


Error: TypeError: Can't instantiate abstract class AdaptiveScalarEncoder with abstract methods getSchema
Add member:

  def getSchema():
     raise NotImplementedError

    
TypeError: 'float' object cannot be interpreted as an integer
 for i in range(maxZerosInARow):
 to
 for i in range(int(maxZerosInARow)):


TypeError: list indices must be integers or slices, not float     
self.assertEqual(topDown.value, e.getBucketValues()[bucketIndices[0]])
to
self.assertEqual(topDown.value, e.getBucketValues()[int(bucketIndices[0]]))



TypeError: Unicode-objects must be encoded before hashing
hash = int(int(hashlib.md5(coordinateStr).hexdigest(), 16) % (2 ** 64))
to     
hash = int(int(hashlib.md5(coordinateStr.encode('utf-8')).hexdigest(), 16) % (2 ** 64))


AttributeError: 'TypeError' object has no attribute 'message'
e.message
to
str(e)


AssertionError: False is not true
self.assertTrue(numpy.array_equal(ranges[0], [1, 1]))
to
int_list = [int(x) for x in ranges[0]]
self.assertTrue(numpy.array_equal(int_list, [1, 1]))


TypeError: a bytes-like object is required, not 'str'
outp.write(inp.read())
to
outp.write(inp.read().encode())


ResourceWarning: unclosed file <_io.TextIOWrapper name='test.bin' mode='r' encoding='cp1252'>
pickle.dump(a, open('test.bin', 'wb'))
to
with open('test.bin', 'wb') as f:
  pickle.dump(a, f)


unittest doesn't have assertItemsEqual()
* use assertCountEqual() instead


self.assertIsInstance(value, (type(None), bytes))
to
self.assertIsInstance(value, (type(None), str))

checking for int on a numpy integer does not work:
isinstance(numColumns, int)
to
isinstance(numColumns, numpy.integer)



File "D:\nupic\src\python\python3\nupic\algorithms\spatial_pooler.py", line 64, in __getitem__
return super(_SparseMatrixCorticalColumnAdapter, self).getRow(columnIndex)
AttributeError: 'super' object has no attribute 'getRow'
Solution: SparseBinaryMatrix python interface didn't define getRow() function




# Notes from dealing with pybind11

There is definately some magic going on!

## Overloading
A cpp function can be overloaded with several instanciations via lamda functions. For instance

A swig definition:

```
%pythoncode %{
def rightVecSumAtNZ(self, denseArray, out=None):
  denseArray = numpy.asarray(denseArray, dtype="float32")

  if out is None:
    out = numpy.empty(self.nRows(), dtype="float32")
  else:
    assert out.dtype == "float32"

  self._rightVecSumAtNZ(denseArray, out)

  return out


def rightVecSumAtNZ_fast(self, denseArray, out):
  """
  Deprecated. Use rightVecSumAtNZ with an 'out' specified.
  """
  self.rightVecSumAtNZ(denseArray, out)
%}

inline void _rightVecSumAtNZ(PyObject* py_denseArray, PyObject* py_out) const
{
    nupic::NumpyVectorWeakRefT<nupic::Real ## N2> denseArray(py_denseArray);
    nupic::NumpyVectorWeakRefT<nupic::Real ## N2> out(py_out);

    NTA_ASSERT(out.size() >= self->nRows());

    self->rightVecSumAtNZ(denseArray.begin(), out.begin());
}
```

can be defined in cpp via:

```
sm.def("rightVecSumAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& denseArray) { ... });
sm.def("rightVecSumAtNZ", [](const SparseMatrix32_t& sm, py::array_t<nupic::Real32>& denseArray, py::array_t<nupic::Real32>& out) { ... }, "", py::arg("denseArray"), py::arg("out"));
```

The later also defines the name of parameter so that kwargs are working as well.

```
mat.rightVecSumAtNZ(x, out=y2)
```

## Properties

To an a nonexisting property to a class, like SM32 do the following. It defines a readonly property with a getter lambda.

```
sm.def_property_readonly("shape", [](const SparseMatrix32_t& sm)
{
    return py::make_tuple(sm.nRows(), sm.nCols());
});

```

## Embedding python in cpp

Work around: AttributeError: module 'sys' has no attribute 'argv'

```
py::scoped_interpreter guard{};

try
{
    // Work around: AttributeError: module 'sys' has no attribute 'argv'
    py::exec(R"(
        import sys
        
        if not hasattr(sys, 'argv'):
            sys.argv = ['']

    )");

    // run some python code
    // py::eval_file(R"(D:\nupic\src\python\python3\test.py)");
}
catch (const py::error_already_set& e)
{
    std::cout << e.what() << std::endl;
}
catch (const std::runtime_error& e)
{
    std::cout << e.what() << std::endl;
}
catch (...)
{
    std::cout << "Unexpected error." << std::endl;
}
```
