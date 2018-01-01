# ----------------------------------------------------------------------
# Numenta Platform for Intelligent Computing (NuPIC)
# Copyright (C) 2016, Numenta, Inc.  Unless you have an agreement
# with Numenta, Inc., for a separate license for this software code, the
# following terms and conditions apply:
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero Public License version 3 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU Affero Public License for more details.
#
# You should have received a copy of the GNU Affero Public License
# along with this program.  If not, see http://www.gnu.org/licenses.
#
# http://numenta.org/licenses/
# ----------------------------------------------------------------------

"""
A simple tutorial that shows some features of the Spatial Pooler.

The following program has the purpose of presenting some
basic properties of the Spatial Pooler. It reproduces Figs.
5, 7 and 9 from this paper: http://arxiv.org/abs/1505.02142
To learn more about the Spatial Pooler have a look at BAMI:
http://numenta.com/biological-and-machine-intelligence/
or at its class reference in the NuPIC documentation:
http://numenta.org/docs/nupic/classnupic_1_1research_1_1spatial__pooler_1_1_spatial_pooler.html
The purpose of the Spatial Pooler is to create a sparse representation
of its inputs in such a way that similar inputs will be mapped to similar
sparse representations. Thus, the Spatial Pooler should exhibit some resilience
to noise in its input.
"""

import matplotlib
import numpy as np
import random

matplotlib.use('Agg')
import matplotlib.pyplot as plt
from nupic.algorithms.spatial_pooler import SpatialPooler as SP

def percentOverlap(x1, x2, size):
  """
  Computes the percentage of overlap between vectors x1 and x2.

  @param x1   (array) binary vector
  @param x2   (array) binary vector
  @param size (int)   length of binary vectors

  @return percentOverlap (float) percentage overlap between x1 and x2
  """
  nonZeroX1 = np.count_nonzero(x1)
  nonZeroX2 = np.count_nonzero(x2)
  minX1X2 = min(nonZeroX1, nonZeroX2)
  percentOverlap = 0
  if minX1X2 > 0:
    percentOverlap = float(np.dot(x1, x2))/float(minX1X2)
  return percentOverlap



def corruptVector(vector, noiseLevel):
  """
  Corrupts a binary vector by inverting noiseLevel percent of its bits.

  @param vector     (array) binary vector to be corrupted
  @param noiseLevel (float) amount of noise to be applied on the vector.
  """
  size = len(vector)
  for i in range(size):
    rnd = random.random()
    if rnd < noiseLevel:
      if vector[i] == 1:
        vector[i] = 0
      else:
        vector[i] = 1



def resetVector(x1, x2):
  """
  Copies the contents of vector x1 into vector x2.

  @param x1 (array) binary vector to be copied
  @param x2 (array) binary vector where x1 is copied
  """
  size = len(x1)
  for i in range(size):
    x2[i] = x1[i]

random.seed(1)
uintType = "uint32"
inputDimensions = (1000,1)
columnDimensions = (2048,1)
inputSize = np.array(inputDimensions).prod()
columnNumber = np.array(columnDimensions).prod()
inputArray = np.zeros(inputSize, dtype=uintType)

for i in range(inputSize):
  inputArray[i] = random.randrange(2)

activeCols = np.zeros(columnNumber, dtype=uintType)
sp = SP(inputDimensions,
  columnDimensions,
  potentialRadius = int(0.5*inputSize),
  numActiveColumnsPerInhArea = int(0.02*columnNumber),
  globalInhibition = True,
  seed = 1,
  synPermActiveInc = 0.01,
  synPermInactiveDec = 0.008
   )
