# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/ebmc/errludP_Helpers.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG

""" Returns a hex dump of a section of data

@param[in] data: memoryview object to hex dump data from
@param[in] start: starting index of data to hex dump
@param[in] end: end index of data to hex dump
@returns: a list of 4 byte hex value strings

"""
def hexDump(data, start, end):
    h = []
    i = start
    j = start + 4
    while i < (end):
        if j-i <= (end-start):
            h.append("".join(str(f'{x:02x}') for x in data[i:j].tolist()))
        else:
            h.append("".join(str(f'{x:02x}') for x in data[i:end].tolist()))
        i = i+4
        j = j+4
    return h

""" Concatenates a section of data and converts it into hex

@param[in] data: memoryview object to get data from
@param[in] start: starting index of data to concatenate
@param[in/out] end: end index of data to concatenate
@returns: a hex value string of the data section, and the new offet value
          used for walking through the data

"""
def memConcat(data, start, end):
    return "".join(str(f'{x:02x}') for x in data[start:end].tolist()), end

""" Concatenates a section of data and converts it into hex

@param[in] data: memoryview object to get data from
@param[in] start: starting index of data to concatenate
@param[in/out] end: end index of data to concatenate
@returns: a hex value string, with "0x" at the front, of the data section, and
          the new offet value used for walking through the data

"""
def hexConcat(data, start, end):
    hexValue, _= memConcat(data, start, end)
    return "0x" + hexValue, end

""" Concatenates a section of data and converts it into an int

@param[in] data: memoryview object to get data from
@param[in] start: starting index of data to concatenate
@param[in/out] end: end index of data to concatenate
@returns: an int value of the data section, and the new offet value used
          for walking through the data

"""
def intConcat(data, start, end):
    hexValue, _= memConcat(data, start, end)
    return int(hexValue, 16), end

""" Finds the index of the next null character in the data

@param[in] data: memoryview object to get data from
@param[in] start: starting index of data to check for null char
@param[end] end: last index of data to check for null char
@returns: an int value of the index of the null char

"""
def findNull(data, start, end):
    index = start
    while index < end:
        # '\x00' = null
        if hex(data[index]) == '0x0':
            break
        index += 1
    return index

""" Concatenates a section of data and converts each byte into a char

@param[in] data: memoryview object to get data from
@param[in] start: starting index of data to concatenate
@param[in/out] end: end index of data to concatenate
@returns: an string of the section of data, and the new offet value used
          for walking through the data

"""
def strConcat(data, start, end):
    return "".join(chr(x) for x in data[start:end].tolist()), end+1

""" Creates a string for an unknown value to use as the default value
when searching a dictionary

@param[in] data: memoryview object to get data from
@param[in] start: starting index of data to concatenate
@param[in] end: end index of data to concatenate
@returns: a string of the unknown value

"""
def unknownStr(data, start, end):
    return "UNKNOWN: " + hex(intConcat(data, start, end)[0])
