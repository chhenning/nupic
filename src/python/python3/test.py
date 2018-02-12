import unittest
import random as rnd
import time

import numpy

from nupic.bindings.math import GetNTAReal
from nupic.encoders import scalar

from nupic.bindings.algorithms import SpatialPooler

class TestSPFrequency(unittest.TestCase):

  def testMe(self):
    s = 5

    # Instantiate Spatial Pooler
    spImpl = SpatialPooler(
                           columnDimensions=(42, 1),
                           inputDimensions=(1, 32),
                           potentialRadius=32//2,
                           numActiveColumnsPerInhArea=40,
                           spVerbosity=10,
                           stimulusThreshold=0,
                           potentialPct=0.5,
                           seed=42,
                           globalInhibition=True,
                           )

if __name__ == "__main__":
  unittest.main()
