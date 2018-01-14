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

"""
Template file used by ExpGenerator to generate the actual
permutations.py file by replacing $XXXXXXXX tokens with desired values.

This permutations.py file was generated by:
'/Users/ronmarianetti/nupic/eng/lib/python2.6/site-packages/nupic/frameworks/opf/expGenerator/experiment_generator.py'
"""

import os

from nupic.swarming.permutation_helpers import *

# The name of the field being predicted.  Any allowed permutation MUST contain
# the prediction field.
# (generated from PREDICTION_FIELD)
predictedField = 'consumption'

permutations = {

  'modelParams': {
    'sensorParams': {
      'encoders': {
        'consumption': PermuteEncoder(fieldName='consumption',
                                      encoderClass='ScalarEncoder',
                                       maxval=PermuteInt(100, 300, 1),
                                       n=PermuteInt(13, 500, 1),
                                       w=7,
                                       minval=0),
      },
    },


    'tmParams': {
      'minThreshold': PermuteInt(9, 12),
      'activationThreshold': PermuteInt(12, 16),
    },


    }
}


# Fields selected for final hypersearch report;
# NOTE: These values are used as regular expressions by RunPermutations.py's
#       report generator
# (fieldname values generated from PERM_PREDICTED_FIELD_NAME)
report = [
          '.*consumption.*',
         ]

# Permutation optimization setting: either minimize or maximize metric
# used by RunPermutations.
# NOTE: The value is used as a regular expressions by RunPermutations.py's
#       report generator
# (generated from minimize = 'prediction:rmse:field=consumption')
minimize = 'prediction:rmse:field=consumption'



def dummyModelParams(perm):
  """ This function can be used for Hypersearch algorithm development. When
  present, Hypersearch doesn't actually run the CLA model in the OPF, but instead run
  a dummy model. This function returns the dummy model params that will be
  used. See the OPFDummyModelRunner class source code (in
  nupic.swarming.ModelRunner) for a description of the schema for
  the dummy model params.
  """

  errScore = 50

  #errScore += abs(perm['modelParams']['sensorParams']['encoders']\
  #                ['consumption']['maxval'] - 250)
  #errScore += abs(perm['modelParams']['sensorParams']['encoders']\
  #                ['consumption']['n'] - 53)


  # Make models that contain the __timestamp_timeOfDay encoder run a bit
  #  slower so we can test that we successfully kill running models
  waitTime = 0.01

  dummyModelParams = dict(
                metricValue = errScore,
                iterations = int(os.environ.get('NTA_TEST_numIterations', '5')),
                waitTime = waitTime,
                sysExitModelRange = os.environ.get('NTA_TEST_sysExitModelRange',
                                                   None),
                delayModelRange = os.environ.get('NTA_TEST_delayModelRange',
                                                   None),
                errModelRange = os.environ.get('NTA_TEST_errModelRange',
                                               None),
                jobFailErr = bool(os.environ.get('NTA_TEST_jobFailErr', False))
                )
  return dummyModelParams



def permutationFilter(perm):
  """ This function can be used to selectively filter out specific permutation
  combinations. It is called by RunPermutations for every possible permutation
  of the variables in the permutations dict. It should return True for valid a
  combination of permutation values and False for an invalid one.

  Parameters:
  ---------------------------------------------------------
  perm: dict of one possible combination of name:value
        pairs chosen from permutations.
  """

  # An example of how to use this
  limit = int(os.environ.get('NTA_TEST_maxvalFilter', 300))
  if perm['modelParams']['sensorParams']['encoders']['consumption']['maxval'] > limit:
    return False;

  return True
