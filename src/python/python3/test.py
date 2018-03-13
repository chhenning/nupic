
import csv
import json
from datetime import datetime

from pkg_resources import resource_filename

from nupic.engine import Network
from nupic.encoders import DateEncoder

# Create network
network = Network()

# Create cpp region
consumptionSensor = network.addRegion('consumptionSensor', 'ScalarSensor', json.dumps({'n': 120, 'w': 21, 'minValue': 0.0, 'maxValue': 100.0, 'clipInput': True}))

oo = consumptionSensor._canAddAttributes



consumptionEncoderN = consumptionSensor.getParameter('n')