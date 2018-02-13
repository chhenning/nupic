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

class SpatialPoolerCompatibilityTest(unittest.TestCase):


  def setUp(self):
    # Set to 1 for more verbose debugging output
    self.verbosity = 1

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
      "spVerbosity": 0
    }
    # This seed used to cause problems if learnMode is set to None
    self.runSideBySide(params, seed = 63862)



if __name__ == "__main__":
  unittest.main()
