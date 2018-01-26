

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



a = rgen.randint(0,2,(6,8))
b = rgen.randint(0,10,(8,4))
c = numpy.dot(a,b)
d = SM32(a).rightDenseMatProd(b)
if (c != d).any():
    error('rightDenseMatProd')

a = rgen.randint(0,2,(6,4))
b = rgen.randint(0,10,(8,6))
c = numpy.dot(b,a)
d = SM32(a).leftDenseMatProd(b)

