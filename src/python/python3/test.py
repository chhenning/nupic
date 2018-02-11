import numpy as np
import tempfile
import unittest

from nupic.bindings.math import (NearestNeighbor, min_score_per_category, SparseMatrix, SM32)
from nupic.algorithms.knn_classifier import KNNClassifier

class KNNClassifierTest(unittest.TestCase):

  def testMe(self):
    s = SparseMatrix(0, 4)
    s.addRowNZ([1], [1])
    s.addRowNZ([2], [1.5])
    print(s.toDense())

    return

  # @unittest.SkipTest
  def testDistanceMetrics(self):
    
    classifier = KNNClassifier(distanceMethod="norm", distanceNorm=2.0)

    dimensionality = 40
    protoA = np.array([0, 1, 3, 7, 11], dtype=np.int32)
    protoB = np.array([20, 28, 30], dtype=np.int32)

    classifier.learn(protoA, 0, isSparse=dimensionality)
    classifier.learn(protoB, 0, isSparse=dimensionality)

    # input is an arbitrary point, close to protoA, orthogonal to protoB
    input = np.zeros(dimensionality)
    input[:4] = 1.0
    # input0 is used to test that the distance from a point to itself is 0
    input0 = np.zeros(dimensionality)
    input0[protoA] = 1.0

    # Test l2 norm metric
    _, _, dist, _ = classifier.infer(input)
    l2Distances = [0.65465367,  1.0]
    for actual, predicted in zip(l2Distances, dist):
      self.assertAlmostEqual(
        actual, predicted, places=5,
        msg="l2 distance norm is not calculated as expected.")

    _, _, dist0, _ = classifier.infer(input0)
    self.assertEqual(
      0.0, dist0[0], msg="l2 norm did not calculate 0 distance as expected.")

    # Test l1 norm metric
    classifier.distanceNorm = 1.0
    _, _, dist, _ = classifier.infer(input)
    l1Distances = [0.42857143,  1.0]
    for actual, predicted in zip(l1Distances, dist):
      self.assertAlmostEqual(
        actual, predicted, places=5,
        msg="l1 distance norm is not calculated as expected.")

    _, _, dist0, _ = classifier.infer(input0)
    self.assertEqual(
      0.0, dist0[0], msg="l1 norm did not calculate 0 distance as expected.")

    # Test raw overlap metric
    classifier.distanceMethod = "rawOverlap"
    _, _, dist, _ = classifier.infer(input)
    rawOverlaps = [1, 4]
    for actual, predicted in zip(rawOverlaps, dist):
      self.assertEqual(
        actual, predicted, msg="Raw overlap is not calculated as expected.")

    _, _, dist0, _ = classifier.infer(input0)
    self.assertEqual(
      0.0, dist0[0],
      msg="Raw overlap did not calculate 0 distance as expected.")

    # Test pctOverlapOfInput metric
    classifier.distanceMethod = "pctOverlapOfInput"
    _, _, dist, _ = classifier.infer(input)
    pctOverlaps = [0.25, 1.0]
    for actual, predicted in zip(pctOverlaps, dist):
      self.assertAlmostEqual(
        actual, predicted, places=5,
        msg="pctOverlapOfInput is not calculated as expected.")

    _, _, dist0, _ = classifier.infer(input0)
    self.assertEqual(
      0.0, dist0[0],
      msg="pctOverlapOfInput did not calculate 0 distance as expected.")

    # Test pctOverlapOfProto metric
    classifier.distanceMethod = "pctOverlapOfProto"
    _, _, dist, _ = classifier.infer(input)
    pctOverlaps = [0.40, 1.0]
    for actual, predicted in zip(pctOverlaps, dist):
      self.assertAlmostEqual(
        actual, predicted, places=5,
        msg="pctOverlapOfProto is not calculated as expected.")

    _, _, dist0, _ = classifier.infer(input0)
    self.assertEqual(
      0.0, dist0[0],
      msg="pctOverlapOfProto did not calculate 0 distance as expected.")

    # Test pctOverlapOfLarger metric
    classifier.distanceMethod = "pctOverlapOfLarger"
    _, _, dist, _ = classifier.infer(input)
    pctOverlaps = [0.40, 1.0]
    for actual, predicted in zip(pctOverlaps, dist):
      self.assertAlmostEqual(
      actual, predicted, places=5,
        msg="pctOverlapOfLarger is not calculated as expected.")

    _, _, dist0, _ = classifier.infer(input0)
    self.assertEqual(
      0.0, dist0[0],
      msg="pctOverlapOfLarger did not calculate 0 distance as expected.")


if __name__ == "__main__":
  unittest.main()
