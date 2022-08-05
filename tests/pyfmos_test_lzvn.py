#!/usr/bin/env python
#
# Python-bindings LZVN (un)compression functions test script
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


class LZVNFunctionsTests(unittest.TestCase):
  """Tests the LZVN (un)compression functions."""

  _COMPRESSED_DATA = bytes(bytearray([
      0xe0, 0x03, 0x4d, 0x79, 0x20, 0x63, 0x6f, 0x6d, 0x70, 0x72, 0x65, 0x73,
      0x73, 0x65, 0x64, 0x20, 0x66, 0x69, 0x6c, 0x65, 0x0a, 0x06, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00]))

  _UNCOMPRESSED_DATA = bytes(bytearray([
      0x4d, 0x79, 0x20, 0x63, 0x6f, 0x6d, 0x70, 0x72, 0x65, 0x73, 0x73, 0x65,
      0x64, 0x20, 0x66, 0x69, 0x6c, 0x65, 0x0a]))

  def test_lzvn_decompress(self):
    """Tests the lzvn_decompress function."""
    uncompressed_data = pyfmos.lzvn_decompress(
        self._COMPRESSED_DATA, uncompressed_data_size=32)

    self.assertEqual(uncompressed_data, self._UNCOMPRESSED_DATA)


if __name__ == "__main__":
  unittest.main(verbosity=2)
