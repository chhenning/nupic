
import numpy as np

from nupic.bindings.math import GetNTAReal
from nupic.bindings.algorithms import SpatialPooler

sp = SpatialPooler(inputDimensions=[5], columnDimensions=[5])

uintDType = "uint32"
realDType = GetNTAReal()

inputGood = np.ones(5, dtype=uintDType)
outGood = np.zeros(5, dtype=uintDType)
inputBad = np.ones(5, dtype=realDType)
outBad = np.zeros(5, dtype=realDType)

# Validate good parameters
sp.compute(inputGood, False, outGood)

sp.compute(inputBad, False, outGood)

