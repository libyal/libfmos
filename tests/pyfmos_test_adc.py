#!/usr/bin/env python
#
# Python-bindings ADC (un)compression functions test script
#
# Copyright (C) 2019-2022, Joachim Metz <joachim.metz@gmail.com>
#
# Refer to AUTHORS for acknowledgements.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

import unittest

import pyfmos


class ADCFunctionsTests(unittest.TestCase):
  """Tests the ADC (un)compression functions."""

  _COMPRESSED_DATA = bytes(bytearray([
      0x83, 0xfe, 0xed, 0xfa, 0xce, 0x00, 0x00, 0x40, 0x00, 0x06]))

  _UNCOMPRESSED_DATA = bytes(bytearray([
      0xfe, 0xed, 0xfa, 0xce, 0xce, 0xce, 0xce, 0xfe, 0xed, 0xfa, 0xce]))

  def test_adc_decompress(self):
    """Tests the adc_decompress function."""
    uncompressed_data = pyfmos.adc_decompress(
        self._COMPRESSED_DATA, uncompressed_data_size=16)

    self.assertEqual(uncompressed_data, self._UNCOMPRESSED_DATA)


if __name__ == "__main__":
  unittest.main(verbosity=2)
