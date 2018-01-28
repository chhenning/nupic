

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

m = rgen.randint(1,10)
n = rgen.randint(1,10)
a = rgen.randint(0,100,(m,n))
a[numpy.where(a < 75)] = 0
a[rgen.randint(0,m)] = 0
a[:,rgen.randint(0,n)] = 0
x = rgen.randint(0,100,(n)).astype(float32)
yr = dot(a,x)
mat = SM32(a)
y = mat.rightVecProd(x)

aa = (y != yr)

if (y != yr).any():
  error('rightVecProd 1')

