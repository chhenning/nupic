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

import csv
import json
from datetime import datetime

from pkg_resources import resource_filename

from nupic.engine import Network
from nupic.encoders import DateEncoder


def createNetwork():
  network = Network()

  #
  # Sensors
  #

  # C++
  consumptionSensor = network.addRegion('consumptionSensor', 'ScalarSensor',
                                        json.dumps({'n': 120,
                                                    'w': 21,
                                                    'minValue': 0.0,
                                                    'maxValue': 100.0,
                                                    'clipInput': True}))

  return network

if __name__ == "__main__":
  network = createNetwork()
