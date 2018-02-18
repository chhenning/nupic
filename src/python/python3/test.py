# ----------------------------------------------------------------------
# Numenta Platform for Intelligent Computing (NuPIC)
# Copyright (C) 2013-15, Numenta, Inc.  Unless you have an agreement
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

from datetime import datetime
from nupic.data import SENTINEL_VALUE_FOR_MISSING_DATA
from nupic.data.field_meta import FieldMetaInfo, FieldMetaType, FieldMetaSpecial
from nupic.data.file_record_stream import FileRecordStream
from nupic.data.utils import (
    parseTimestamp, serializeTimestamp, escape, unescape)



def _getTempFileName():
  """Creates unique file name that starts with 'test' and ends with '.txt'."""
  handle = tempfile.NamedTemporaryFile(prefix='test', suffix='.txt', dir='.')
  filename = handle.name
  handle.close()

  return filename



class TestFileRecordStream(unittest.TestCase):


  def testBasic(self):
    """Runs basic FileRecordStream tests."""
    filename = _getTempFileName()

    # Write a standard file
    fields = [FieldMetaInfo('name', FieldMetaType.string,
                            FieldMetaSpecial.none),
              FieldMetaInfo('timestamp', FieldMetaType.datetime,
                            FieldMetaSpecial.timestamp),
              FieldMetaInfo('integer', FieldMetaType.integer,
                            FieldMetaSpecial.none),
              FieldMetaInfo('real', FieldMetaType.float,
                            FieldMetaSpecial.none),
              FieldMetaInfo('reset', FieldMetaType.integer,
                            FieldMetaSpecial.reset),
              FieldMetaInfo('sid', FieldMetaType.string,
                            FieldMetaSpecial.sequence),
              FieldMetaInfo('categoryField', FieldMetaType.integer,
                            FieldMetaSpecial.category),]
    fieldNames = ['name', 'timestamp', 'integer', 'real', 'reset', 'sid',
                  'categoryField']

    print('Creating temp file:', filename)

    with FileRecordStream(streamID=filename, write=True, fields=fields) as s:

      self.assertEqual(0, s.getDataRowCount())

      # Records
      records = (
        ['rec_1', datetime(day=1, month=3, year=2010), 5, 6.5, 1, 'seq-1', 10],
        ['rec_2', datetime(day=2, month=3, year=2010), 8, 7.5, 0, 'seq-1', 11],
        ['rec_3', datetime(day=3, month=3, year=2010), 12, 8.5, 0, 'seq-1', 12])

      self.assertEqual(fields, s.getFields())
      self.assertEqual(0, s.getNextRecordIdx())

      print('Writing records ...')
      for r in records:
        print(list(r))
        s.appendRecord(list(r))

      self.assertEqual(3, s.getDataRowCount())

      recordsBatch = (
        ['rec_4', datetime(day=4, month=3, year=2010), 2, 9.5, 1, 'seq-1', 13],
        ['rec_5', datetime(day=5, month=3, year=2010), 6, 10.5, 0, 'seq-1', 14],
        ['rec_6', datetime(day=6, month=3, year=2010), 11, 11.5, 0, 'seq-1', 15]
      )

      print('Adding batch of records...')
      for rec in recordsBatch:
        print(rec)
      s.appendRecords(recordsBatch)
      self.assertEqual(6, s.getDataRowCount())

    with FileRecordStream(filename) as s:

      # Read the standard file
      self.assertEqual(6, s.getDataRowCount())
      self.assertEqual(fieldNames, s.getFieldNames())

      # Note! this is the number of records read so far
      self.assertEqual(0, s.getNextRecordIdx())

      readStats = s.getStats()
      print('Got stats:', readStats)
      expectedStats = {
                       'max': [None, None, 12, 11.5, 1, None, 15],
                       'min': [None, None, 2, 6.5, 0, None, 10]
                      }
      self.assertEqual(expectedStats, readStats)

      readRecords = []
      print('Reading records ...')
      while True:
        r = s.getNextRecord()
        print(r)
        if r is None:
          break

        readRecords.append(r)

      allRecords = records + recordsBatch
      for r1, r2 in zip(allRecords, readRecords):
        self.assertEqual(r1, r2)




if __name__ == '__main__':
  unittest.main()
