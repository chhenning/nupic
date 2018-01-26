

import sys
import numpy
from numpy import *
import math
import os
import pickle
import copy
import time
import unittest

rgen = numpy.random.RandomState(37)


from nupic.bindings.math import *

nRows = rgen.randint(1,10)
nCols = rgen.randint(1,10)
a = rgen.randint(0,100,(nRows,nCols))
a[numpy.where(a < 75)] = 0
a[rgen.randint(0, nRows)] = 0
a[:,rgen.randint(0, nCols)] = 0
mat = SM32(a)

x = rgen.randint(2, size=nCols).astype(float32)

aNonzero = array(a)
aNonzero[where(aNonzero > 0)] = 1
expected = dot(aNonzero, x)

y = mat.rightVecSumAtNZ(x)
numpy.testing.assert_equal(y, expected, 'rightVecSumAtNZ')
y2 = zeros((nRows)).astype(float32)
mat.rightVecSumAtNZ(x, out=y2)
numpy.testing.assert_equal(y2, expected, 'rightVecSumAtNZ with out')
