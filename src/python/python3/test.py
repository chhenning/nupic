import csv
import json
from datetime import datetime

from pkg_resources import resource_filename

from nupic.engine import Network
from nupic.encoders import DateEncoder

network = Network()

params = json.dumps({'n': 120,'w': 21,'minValue': 0.0,'maxValue': 100.0,'clipInput': True})
cpp_sensor = network.addRegion('consumptionSensor', 'ScalarSensor', params)

# sensor_name = sensor.name
# self = sensor.getSelf()

py_sensor = network.addRegion("timestampSensor", 'py.PluggableEncoderSensor', "")
self = py_sensor.getSelf()
print(type(self))
# print(help(self))

en = self.encoder
en = DateEncoder(timeOfDay=(21, 9.5), name="timestamp_timeOfDay")

