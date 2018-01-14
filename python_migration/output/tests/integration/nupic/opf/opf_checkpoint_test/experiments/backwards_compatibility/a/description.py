# ----------------------------------------------------------------------
# Numenta Platform for Intelligent Computing (NuPIC)
# Copyright (C) 2011-2015, Numenta, Inc.  Unless you have an agreement
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

## This file defines parameters for a prediction experiment.

###############################################################################
#                                IMPORTANT!!!
# This params file is dynamically generated by the RunExperimentPermutations
# script. Any changes made manually will be over-written the next time
# RunExperimentPermutations is run!!!
###############################################################################


from nupic.frameworks.opf.exp_description_helpers import importBaseDescription

# the sub-experiment configuration
config ={
  'modelParams' : {'sensorParams': {'encoders': {'c0_timeOfDay': None, 'c0_dayOfWeek': None, 'c1': {'name': 'c1', 'clipInput': True, 'n': 275, 'fieldname': 'c1', 'w': 21, 'type': 'AdaptiveScalarEncoder'}, 'c0_weekend': None}}, 'inferenceType': 'NontemporalMultiStep', 'spParams': {'synPermInactiveDec': 0.052500000000000005}, 'tmParams': {'minThreshold': 11, 'activationThreshold': 14, 'pamLength': 3}, 'clParams': {'alpha': 0.050050000000000004}},

  'firstRecord': 0,
  'lastRecord': 10,
}

mod = importBaseDescription('../base.py', config)
locals().update(mod.__dict__)