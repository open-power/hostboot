# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/errl/plugins/ebmc/b3100/b3100.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2022
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

"""
@file b3100.py

@brief This plugin will decode the error log dump for
       the component ID 0x3100 (FIPS_ERRL_COMP_ID).
       The actual decoding of the binary data associated
       with the trace is done via file hostfw_trace.py.
"""

import json
import os.path
import struct

from udparsers.helpers.miscUtils import getLid

# Some global variables
HBOT_STRING_LID_FILE = "81e00685.lid"

class errludP_fipsErrl:
    # ***** Memory Layout Version 1 *****
    # 1 byte        : Version info
    # 3 bytes       : Header Info
    # N bytes       : HB traces

    # ***** Memory Layout Version 2 *****
    # 1 byte        : Version info
    # N bytes       : HB traces

    """ Converts the binary data into lines of printable strings.  Each string
        representing 16 bytes of data or less.  The lines are broken into 2 columns
        with the left column displaying the binary data and the right column displaying
        the ASCII value if printable. See example below.

    Example:
        01 28 00 42 50 52 44 46  00 00 00 00 00 00 00 00  |  .(.BPRDF........
        00 00 00 00 00 00 02 F8  00 00 00 00 00 00 02 F8  |  ................
        ...
        58 D9 00 0A 00 00 00 72  72 96 C5 E9 72 96 C5 E9  |  X......rr...r...
        72 96 C5 E9                                       |  r...

    @param[in] data: memoryview - the trace data in binary
    @returns: list: List of printable strings representing the data
    """
    def convertDataToList(data):
        lastAsciiChar = 127 # The value of the last ASCII character
        lines = []  # Will contain the printable strings that will be returned back
        count = 0   # Keeps track of the offset into the data
        dataPart = ""   # Will hold the printable hex values of the data
        asciiPart = ""  # Will hold the printable ASCII values of the data or "." if not printable
        # Iterate thru the data, decoding each byte
        for byte in data:
            # Convert the data to its equivalent printable hex value
            dataPart+='%.2X' % byte + " "
            # Convert the data to it's equivalent printable ASCII value or "."
            if byte <= lastAsciiChar:
                dataChar = struct.unpack_from('1s', data, count)[0].decode('UTF-8')
                if dataChar.isprintable():
                    asciiPart += dataChar
                else:
                    asciiPart += "."
            else:
                asciiPart += "."

            count = count+1

            # If 8 bytes have been seen, then add an extra blank, " ", as separation
            if count % 8 == 0:
                dataPart+= " "

            # If 16 bytes have been seen, then append the ASCII part and add to list
            if count % 16 == 0:
                dataPart += "|  "
                dataPart += asciiPart
                lines.append(dataPart)
                dataPart = ""
                asciiPart = ""

        # If the data did not land on a 16 byte boundary, then pad the data part
        while count % 16 != 0:
            count = count+1
            dataPart+= "   "
            if count % 8 == 0:
                dataPart+= " "

            if count % 16 == 0:
                dataPart += "|  "
                dataPart += asciiPart
                lines.append(dataPart)

        return lines

    """ Decode traces associated with component ID 0x3100 (FIPS_ERRL_COMP_ID).
        The actual decoding of the binary is done via API get_binary_trace_data_as_string
        from the file hostfw_trace.py.

    @param[in] ver: int - the version of the data
    @param[in] data: memoryview - the trace data in binary
    @returns: Json objects of the decoded traces
    """
    def UdParserHbTrace(ver, data):
        # For User Data with header:
        #    "Section Version":          "1",
        #    "Sub-section type":         "21",
        #    "Created by":               "0x3100",
        # NOTE: Other versions than just 1 are handled as well

        # Import the API that will be used to take the data and parse it out
        from udparsers.helpers.hostfw_trace import get_binary_trace_data_as_string

        # Create a dictionary to hold the trace output
        d = dict()

        # Get the LID file for the HB string file
        stringFile = getLid(HBOT_STRING_LID_FILE)
        if stringFile == "":
            d["File not found"]=HBOT_STRING_LID_FILE
            d["Data"] = errludP_fipsErrl.convertDataToList(data)
            jsonStr = json.dumps(d)
            return jsonStr

        d["Decode file used"] = stringFile

        startingPosition = 0     # start at the version info
        printNumberOfTraces = -1 # -1 means to get all traces
        (retVal, traceDataString) = get_binary_trace_data_as_string(data, startingPosition,
                                    printNumberOfTraces, stringFile)

        # If the data string ends with a newline, "\n", then remove it.
        # Removing the newline sets up the data string for the split
        # function below to not have an empty line at the end
        if traceDataString[-1] == "\n":
            traceDataString = traceDataString[:-1]

        # Split the data string into a list for "pretty printing"
        traces = traceDataString.split("\n")

        # If an error with parsing the binary data then return the
        # errors encountered
        if retVal != 0:
            d["Errors"] = traces
            d["Data"] = errludP_fipsErrl.convertDataToList(data)
        else: # else return the paresed data
            d["Data"] = traces

        jsonStr = json.dumps(d)
        return jsonStr


# Dictionary with parser functions for each subtype
# Value from enum errlUserDataType_t as found in file
# src/include/usr/errl/hberrltypes.H, line 385 (commit 46d25d09)
#    FIPS_ERRL_UDT_HB_TRACE          = 0x15,   // A trace buffer
fipsErrlUserDetailDataSubsection = { 0x15: "UdParserHbTrace" }

def parseUDToJson(subType, ver, data):
    # Set the Data section to the traces list and return back to caller
    return getattr(errludP_fipsErrl, fipsErrlUserDetailDataSubsection[subType])(ver, data)

