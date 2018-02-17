import cPickle as pickle
import numpy
import unittest2 as unittest
from nupic.bindings.math import Random

from nupic.algorithms import fdrutilities as fdrutils
from nupic.algorithms.backtracking_tm import BacktrackingTM
from nupic.algorithms.backtracking_tm_cpp import BacktrackingTMCPP

VERBOSITY = 0  # how chatty the unit tests should be
INFERENCE_VERBOSITY = 0  # Chattiness during inference test
SEED = 12
_RGEN = Random(SEED)



def checkCell0(tm):
  """Check that cell 0 has no incoming segments"""
  for c in range(tm.numberOfCols):
    assert tm.getNumSegmentsInCell(c, 0) == 0



def setVerbosity(verbosity, tm, tmPy):
  """Set verbosity levels of the TM's"""
  tm.cells4.setVerbosity(verbosity)
  tm.verbosity = verbosity
  tmPy.verbosity = verbosity


class BacktrackingTMCPP2Test(unittest.TestCase):


    def test_me(self):
        # Create cpp tm
        tm = BacktrackingTMCPP(numberOfCols=10, cellsPerColumn=1, verbosity=VERBOSITY)
        tm.cells4.setCellSegmentOrder(True)

        # Create Python tm from same characteristics
        tmPy = BacktrackingTM(numberOfCols=tm.numberOfCols,
                              cellsPerColumn=tm.cellsPerColumn,
                              initialPerm=tm.initialPerm,
                              connectedPerm=tm.connectedPerm,
                              minThreshold=tm.minThreshold,
                              newSynapseCount=tm.newSynapseCount,
                              permanenceInc=tm.permanenceInc,
                              permanenceDec=tm.permanenceDec,
                              permanenceMax=tm.permanenceMax,
                              globalDecay=tm.globalDecay,
                              activationThreshold=tm.activationThreshold,
                              doPooling=tm.doPooling,
                              segUpdateValidDuration=tm.segUpdateValidDuration,
                              pamLength=tm.pamLength, maxAge=tm.maxAge,
                              maxSeqLength=tm.maxSeqLength,
                              maxSegmentsPerCell=tm.maxSegmentsPerCell,
                              maxSynapsesPerSegment=tm.maxSynapsesPerSegment,
                              seed=tm.seed, verbosity=tm.verbosity)

        # Check if both tm's are equal
        self.assertTrue(fdrutils.tmDiff2(tm, tmPy, VERBOSITY, False))

        # Build up sequences
        numPatterns=1
        numRepetitions=1
        activity=1

        sequence = fdrutils.generateCoincMatrix(nCoinc=numPatterns, length=tm.numberOfCols, activity=activity)
        # print(sequence)

        sequence_row = sequence.getRow(0)

        y1 = tm.learn(sequence_row)
        y2 = tmPy.learn(sequence_row)

        num_segments_cpp = tm.getNumSegments()
        num_segments_py = tmPy.getNumSegments()

        # fails since num_segments_cpp = 0 and num_segments_py = 1
        self.assertTrue(num_segments_cpp = num_segments_py)

if __name__ == '__main__':
  unittest.main()

