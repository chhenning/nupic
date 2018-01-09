!!! THIS IS WORK IN PROGRESS !!!

python 3 version of nupic.

For the simple syntax changes I used the 2to3 tool. The command line is:

python c:\Python36\Tools\scripts\2to3.py --output-dir d:\test -W -n d:\nupic\src\python\python27



| File | python3 | github issue |
|------|---------|--------------|
| examples/sp/hello_sp.py | yes ||
| examples/tm/hello_tm.py | yes ||
| tests/unit/nupic/algorithms/anomaly_likelihood_jeff_test.py| yes ||
| tests/unit/nupic/algorithms/anomaly_likelihood_test.py| yes ||
| tests/unit/nupic/algorithms/anomaly_likelihood_test.py| yes ||
| tests/unit/nupic/algorithms/anomaly_test.py| yes ||
| tests/unit/nupic/algorithms/backtracking_tm_constant_test.py| TypeError: getSegmentActivityLevel() | #1 |
| tests/unit/nupic/algorithms/backtracking_tm_cpp.py| python crashes ||
| tests/unit/nupic/algorithms/backtracking_tm_cpp2_test.py| AssertionError: False is not true ||
| tests/unit/nupic/algorithms/connections_test.py | yes ||
| tests/unit/nupic/algorithms/inhibition_object_test.py | yes ||
| tests/unit/nupic/algorithms/knn_classifier_test.py | python exceptions | #2 |
| tests/unit/nupic/math/lgamma_test.py | yes ||
