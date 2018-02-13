import pickle as pickle
import random
import tempfile
import types
import unittest

import numpy

from nupic.algorithms.sdr_classifier import SDRClassifier

class SDRClassifierTest(unittest.TestCase):
  """Unit tests for SDRClassifier class."""


  def setUp(self):
    self._classifier = SDRClassifier

  def testComputeCategory(self):
    c = self._classifier([1], 0.1, 0.1, 0)
    c.compute(recordNum=0, patternNZ=[1, 5, 9],
              classification={"bucketIdx": 4, "actValue": "D"},
              learn=True, infer=True)
    result = c.compute(recordNum=1, patternNZ=[1, 5, 9],
                       classification={"bucketIdx": 4, "actValue": "D"},
                       learn=True, infer=True)
    self.assertSetEqual(set(result.keys()), set(("actualValues", 1)))
    self.assertEqual(result["actualValues"][4], "D")

    predictResult = c.compute(recordNum=2, patternNZ=[1, 5, 9],
                              classification={"bucketIdx": 5,
                                              "actValue": None},
                              learn=True, infer=True)
    for value in predictResult["actualValues"]:
      self.assertIsInstance(value, (type(None), str))


if __name__ == "__main__":
  unittest.main()
