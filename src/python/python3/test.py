# ----------------------------------------------------------------------
# Numenta Platform for Intelligent Computing (NuPIC)
# Copyright (C) 2013, Numenta, Inc.  Unless you have an agreement
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

import tempfile
import unittest

import numpy
from array import array

from nupic.data import SENTINEL_VALUE_FOR_MISSING_DATA
from nupic.encoders.adaptive_scalar import AdaptiveScalarEncoder
from nupic.encoders.base import defaultDtype

try:
  import capnp
except ImportError:
  capnp = None
if capnp:
  from nupic.encoders.adaptive_scalar_capnp import AdaptiveScalarEncoderProto



class AdaptiveScalarTest(unittest.TestCase):
  """Tests for AdaptiveScalarEncoder"""


  def setUp(self):
    # forced: it's strongly recommended to use w>=21, in the example we force
    # skip the check for readibility
    self._l = AdaptiveScalarEncoder(name="scalar", n=14, w=5, minval=1,
                                    maxval=10, periodic=False, forced=True)

  def testTopDownDecode(self):
    """Test the input description generation and topDown decoding"""
    l = self._l
    v = l.minval

    l.verbosity = 10

    while v < l.maxval:
      output = l.encode(v)
      decoded = l.decode(output)

      (fieldsDict, _) = decoded
      self.assertEqual(len(fieldsDict), 1)

      (ranges, _) = list(fieldsDict.values())[0]
      self.assertEqual(len(ranges), 1)

      (rangeMin, rangeMax) = ranges[0]
      self.assertEqual(rangeMin, rangeMax)
      self.assertLess(abs(rangeMin - v), l.resolution)

      topDown = l.topDownCompute(output)[0]
      self.assertLessEqual(abs(topDown.value - v), l.resolution)

      # Test bucket support
      bucketIndices = l.getBucketIndices(v)
      topDown = l.getBucketInfo(bucketIndices)[0]
      self.assertLessEqual(abs(topDown.value - v), l.resolution / 2)
      self.assertEqual(topDown.value, l.getBucketValues()[int(bucketIndices[0])])
      self.assertEqual(topDown.scalar, topDown.value)
      self.assertTrue(numpy.array_equal(topDown.encoding, output))

      # Next value
      v += l.resolution / 4


if __name__ == '__main__':
  unittest.main()

#arr = numpy.ones(10, 'uint8')
## s = array('c','.'*len(arr))
#s = array('b')

#placeholders = '.'*len(arr)
#s.frombytes(placeholders.encode())

#for i in range(len(arr)):
#  if arr[i] == 1:
#    s[i]= ord('*')

#print(s.tobytes().decode())

