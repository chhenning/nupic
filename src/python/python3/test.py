

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

m = rgen.randint(2,10)
n = rgen.randint(1,10)
a = rgen.randint(0,100,(m,n))
a[numpy.where(a < 75)] = 0
a[rgen.randint(0,m)] = 0
a[:,rgen.randint(0,n)] = 0
x = list(set(rgen.randint(0,m,(4))))
y = list(set(rgen.randint(0,n,(3))))
b = copy.deepcopy(a)
for j in x:
  for k in y:
    b[j,k] += 2
c = SM32(a)

x = [int(o) for o in x]
y = [int(o) for o in y]

print(c)
c.incrementOnOuterProductVal(x, y, -2)
print()
print(c)
print()
print(c.toDense())


print((c.toDense() != b))



if (c.toDense() != b).any():
  assert(false)
