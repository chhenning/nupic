import pickle as pickle
import numpy
import time
import traceback
import unittest
from nupic.bindings.algorithms import SpatialPooler as CPPSpatialPooler
from nupic.bindings.math import GetNTAReal, Random as NupicRandom

from nupic.algorithms.spatial_pooler import SpatialPooler as PySpatialPooler
from nupic.support.unittesthelpers.algorithm_test_helpers \
     import getNumpyRandomGenerator, CreateSP, convertPermanences

realType = GetNTAReal()
uintType = "uint32"
numRecords = 100


class SpatialPoolerCompatibilityTest(unittest.TestCase):
  """
  Tests to ensure that the PY and CPP implementations of the spatial pooler
  are functionally identical.
  """

  def setUp(self):
    # Set to 1 for more verbose debugging output
    self.verbosity = 10


  def assertListAlmostEqual(self, alist, blist):
    self.assertEqual(len(alist), len(blist))
    for a, b in zip(alist, blist):
      diff = abs(a - b)
      self.assertLess(diff, 1e-4)


  def compare(self, pySp, cppSp):
    self.assertAlmostEqual(pySp.getNumColumns(),
                           cppSp.getNumColumns())
    self.assertAlmostEqual(pySp.getNumInputs(),
                           cppSp.getNumInputs())
    self.assertAlmostEqual(pySp.getPotentialRadius(),
                           cppSp.getPotentialRadius())
    self.assertAlmostEqual(pySp.getPotentialPct(),
                           cppSp.getPotentialPct())
    self.assertAlmostEqual(pySp.getGlobalInhibition(),
                           cppSp.getGlobalInhibition())
    self.assertAlmostEqual(pySp.getNumActiveColumnsPerInhArea(),
                           cppSp.getNumActiveColumnsPerInhArea())
    self.assertAlmostEqual(pySp.getLocalAreaDensity(),
                           cppSp.getLocalAreaDensity())
    self.assertAlmostEqual(pySp.getStimulusThreshold(),
                           cppSp.getStimulusThreshold())
    self.assertAlmostEqual(pySp.getInhibitionRadius(),
                           cppSp.getInhibitionRadius())
    self.assertAlmostEqual(pySp.getDutyCyclePeriod(),
                           cppSp.getDutyCyclePeriod())
    self.assertAlmostEqual(pySp.getBoostStrength(),
                           cppSp.getBoostStrength())
    self.assertAlmostEqual(pySp.getIterationNum(),
                           cppSp.getIterationNum())
    self.assertAlmostEqual(pySp.getIterationLearnNum(),
                           cppSp.getIterationLearnNum())
    self.assertAlmostEqual(pySp.getSpVerbosity(),
                           cppSp.getSpVerbosity())
    self.assertAlmostEqual(pySp.getUpdatePeriod(),
                           cppSp.getUpdatePeriod())
    self.assertAlmostEqual(pySp.getSynPermTrimThreshold(),
                           cppSp.getSynPermTrimThreshold())
    self.assertAlmostEqual(pySp.getSynPermActiveInc(),
                           cppSp.getSynPermActiveInc())
    self.assertAlmostEqual(pySp.getSynPermInactiveDec(),
                           cppSp.getSynPermInactiveDec())
    self.assertAlmostEqual(pySp.getSynPermBelowStimulusInc(),
                           cppSp.getSynPermBelowStimulusInc())
    self.assertAlmostEqual(pySp.getSynPermConnected(),
                           cppSp.getSynPermConnected())
    self.assertAlmostEqual(pySp.getMinPctOverlapDutyCycles(),
                           cppSp.getMinPctOverlapDutyCycles())

    numColumns = pySp.getNumColumns()
    numInputs = pySp.getNumInputs()

    pyBoost = numpy.zeros(numColumns).astype(realType)
    cppBoost = numpy.zeros(numColumns).astype(realType)
    pySp.getBoostFactors(pyBoost)
    cppSp.getBoostFactors(cppBoost)
    self.assertListAlmostEqual(list(pyBoost), list(cppBoost))

    pyOverlap = numpy.zeros(numColumns).astype(realType)
    cppOverlap = numpy.zeros(numColumns).astype(realType)
    pySp.getOverlapDutyCycles(pyOverlap)
    cppSp.getOverlapDutyCycles(cppOverlap)
    self.assertListAlmostEqual(list(pyOverlap), list(cppOverlap))

    pyActive = numpy.zeros(numColumns).astype(realType)
    cppActive = numpy.zeros(numColumns).astype(realType)
    pySp.getActiveDutyCycles(pyActive)
    cppSp.getActiveDutyCycles(cppActive)
    self.assertListAlmostEqual(list(pyActive), list(cppActive))

    pyMinOverlap = numpy.zeros(numColumns).astype(realType)
    cppMinOverlap = numpy.zeros(numColumns).astype(realType)
    pySp.getMinOverlapDutyCycles(pyMinOverlap)
    cppSp.getMinOverlapDutyCycles(cppMinOverlap)
    self.assertListAlmostEqual(list(pyMinOverlap), list(cppMinOverlap))

    for i in range(pySp.getNumColumns()):
      if self.verbosity > 2: print("Column:",i)
      pyPot = numpy.zeros(numInputs).astype(uintType)
      cppPot = numpy.zeros(numInputs).astype(uintType)
      pySp.getPotential(i, pyPot)
      cppSp.getPotential(i, cppPot)
      self.assertListEqual(list(pyPot),list(cppPot))

      pyPerm = numpy.zeros(numInputs).astype(realType)
      cppPerm = numpy.zeros(numInputs).astype(realType)
      pySp.getPermanence(i, pyPerm)
      cppSp.getPermanence(i, cppPerm)
      self.assertListAlmostEqual(list(pyPerm),list(cppPerm))

      pyCon = numpy.zeros(numInputs).astype(uintType)
      cppCon = numpy.zeros(numInputs).astype(uintType)
      pySp.getConnectedSynapses(i, pyCon)
      cppSp.getConnectedSynapses(i, cppCon)
      self.assertListEqual(list(pyCon), list(cppCon))

    pyConCounts = numpy.zeros(numColumns).astype(uintType)
    cppConCounts = numpy.zeros(numColumns).astype(uintType)
    pySp.getConnectedCounts(pyConCounts)
    cppSp.getConnectedCounts(cppConCounts)
    self.assertListEqual(list(pyConCounts), list(cppConCounts))



  def runSideBySide(self, params, seed = None,
                    learnMode = None,
                    convertEveryIteration = False):
    """
    Run the PY and CPP implementations side by side on random inputs.
    If seed is None a random seed will be chosen based on time, otherwise
    the fixed seed will be used.

    If learnMode is None learning will be randomly turned on and off.
    If it is False or True then set it accordingly.

    If convertEveryIteration is True, the CPP will be copied from the PY
    instance on every iteration just before each compute.
    """
    randomState = getNumpyRandomGenerator(seed)
    cppSp = CreateSP("cpp", params)
    pySp = CreateSP("py", params)
    self.compare(pySp, cppSp)

  def testCompatibility1(self):

    params = {
      "inputDimensions": [4,4],
      "columnDimensions": [5,3],
      "potentialRadius": 20,
      "potentialPct": 0.5,
      "globalInhibition": True,
      "localAreaDensity": 0,
      "numActiveColumnsPerInhArea": 5,
      "stimulusThreshold": 0,
      "synPermInactiveDec": 0.01,
      "synPermActiveInc": 0.1,
      "synPermConnected": 0.10,
      "minPctOverlapDutyCycle": 0.001,
      "dutyCyclePeriod": 30,
      "boostStrength": 10.0,
      "seed": 4,
      "spVerbosity": 10
    }
    # This seed used to cause problems if learnMode is set to None
    self.runSideBySide(params, seed = 63862)



if __name__ == "__main__":
  unittest.main()
