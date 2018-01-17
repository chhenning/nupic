!!! THIS IS WORK IN PROGRESS !!!

python 3 version of nupic.

For the simple syntax changes I used the 2to3 tool. The command line is:

python c:\Python36\Tools\scripts\2to3.py --output-dir d:\test -W -n d:\nupic\src\python\python27





| File                                                             | python3                               | github issue | output                                      |
|------------------------------------------------------------------|---------------------------------------|--------------|---------------------------------------------|
| examples/sp/hello_sp.py                                          | yes                                   |              | nupic\test\python3\output\hello_sp.py.txt   |  
| examples/tm/hello_tm.py                                          | yes                                   |              | nupic\test\python3\output\hello_tm.py.txt   |
| tests/unit/nupic/algorithms/anomaly_likelihood_jeff_test.py      | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/anomaly_likelihood_test.py           | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/anomaly_test.py                      | yes                                   |              | nupic\test\python3\output\backtracking_tm_constant_test.py.txt |
| tests/unit/nupic/algorithms/backtracking_tm_constant_test.py     | TypeError: getSegmentActivityLevel()  | #1           |                                             |
| tests/unit/nupic/algorithms/backtracking_tm_cpp.py               | python crashes                        | #5           |                                             |
| tests/unit/nupic/algorithms/backtracking_tm_cpp2_test.py         | AssertionError: False is not true     |              |                                             |
| tests/unit/nupic/algorithms/connections_test.py                  | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/inhibition_object_test.py            | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/knn_classifier_test.py               | exceptions                            | #2           |                                             |
| tests/unit/nupic/algorithms/sdr_classifier_test.py               | AssertionError                        | #6           |                                             |
| tests/unit/nupic/algorithms/sp_learn_inference.py                | yes                                   |              |                                             |
| tests/unit/nupic/algorithms/sp_overlap_test.py                   | cpp argument errors                   | #7           |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_boost_test.py         | InvalidSPParamValueError              | #8           |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_compatability_test.py | cpp argument errors                   | #9           |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_compute_test.py       | todo                                  |              |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_cpp_api_test.py       | todo                                  |              |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_cpp_unit_test.py      | todo                                  |              |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_py_api_test.py        | todo                                  |              |                                             |
| tests/unit/nupic/algorithms/spatial_pooler_unit_test.py          | todo                                  |              |                                             |
| tests/unit/nupic/algorithms/temporal_memory_test.py              | yes                                   |              |                                             |
| tests\unit\nupic\data\generators\anomalyzer_test.py              | TypeError                             | #10          |                                             |
| tests\unit\nupic\data\generators\pattern_machine_test.py         | yes                                   |              |                                             |
| tests\unit\nupic\data\generators\sequence_machine_test.py        | yes                                   |              |                                             |
| tests\unit\nupic\data\aggregator_test.py                         | AssertionError                        | #11          |                                             |
| tests\unit\nupic\data\dictutils_test.py                          | yes                                   |              |                                             |
| tests\unit\nupic\data\fieldmeta_test.py                          | yes                                   |              |                                             |
| tests\unit\nupic\data\file_record_stream_test.py                 | TypeError                             | #10          |                                             |
| tests\unit\nupic\data\filters_test.py                            | yes                                   |              |                                             |
| tests\unit\nupic\data\functionsource_test.py                     | yes                                   |              |                                             |
| tests\unit\nupic\data\inference_shifter_test.py                  | yes                                   |              |                                             |
| tests\unit\nupic\data\record_stream_test.py                      | TypeError                             | #10          |                                             |
| tests\unit\nupic\data\utils_test.py                              | yes                                   |              |                                             |
| tests\unit\nupic\docs\examples_test.py                           | ModuleNotFoundError                   | #10          |                                             |
| tests\unit\nupic\encoders\adaptivescalar_test.py                 | TypeError                             | #13          |                                             |
| tests\unit\nupic\encoders\category_test.py                       | yes                                   |              |                                             |
| tests\unit\nupic\encoders\coordinate_test.py                     | yes                                   |              |                                             |
| tests\unit\nupic\encoders\date_test.py                           | AssertionError                        | #16          |                                             |
| tests\unit\nupic\encoders\delta_test.py                          | yes                                   |              |                                             |
| tests\unit\nupic\encoders\geospatial_coordinate_test.py          | AssertionError                        | #17          |                                             |
| tests\unit\nupic\encoders\logenc_test.py                         | AssertionError                        | #18          |                                             |
| tests\unit\nupic\encoders\multi_test.py                          | AssertionError                        | #18          |                                             |
| tests\unit\nupic\encoders\pass_through_encoder_test.py           | yes                                   |              |                                             |
| tests\unit\nupic\encoders\random_distributed_scalar_test.py      | AssertionError                        | #18          |                                             |
| tests\unit\nupic\encoders\scalarspace_test.py                    | yes                                   |              |                                             |
| tests\unit\nupic\encoders\scalar_test.py                         | AssertionError                        | #18          |                                             |
| tests\unit\nupic\encoders\sdrcategory_test.py                    | RuntimeError                          | #19          |                                             |
| tests\unit\nupic\encoders\sparse_pass_through_encoder_test.py    | yes                                   |              |                                             |
| tests\unit\nupic\engine\network_test.py                          | yes                                   |              |                                             | 
| tests\unit\nupic\engine\syntactic_sugar_test.py                  | AttributeError                        | #20          |                                             |
| tests\unit\nupic\engine\unified_py_parameter_test.py             |                                       |              |                                             |
| tests\unit\nupic\math/lgamma_test.py                             | yes                                   |              |                                             |
| tests\unit\nupic\math/topology_test.py                           | disabled by default                   |              |                                             |
| tests\unit\nupic\regions/anomaly_likelihood_region_test.py       | yes                                   |              |                                             |
| tests\unit\nupic\regions/anomaly_region_test.py                  | yes                                   |              |                                             |
| tests\unit\nupic\regions/anomaly_region_test.py                  | yes                                   |              |                                             |
| tests\unit\nupic\regions/knn_anomaly_classifier_region_test.py   | Classification vector type must be either 'tpc' or 'sp_tpe', current value is 3 |                  |
| tests\unit\nupic\regions/knn_classifier_region_test.py           | yes                                   |              |                                             |


# python 3 dependencies

pip install asteval
pip install pymysql
pip install pyproj
pip install validictory
pip install DBUtils


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



