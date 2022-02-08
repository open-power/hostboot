# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/errl/plugins/ebmc/b3100.py $
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

import json
import os.path

# Some global variables
BMC_PATCH_DIR = "/usr/local/share/hostfw/running"
BMC_LID_RUNNING_DIR = "/var/lib/phosphor-software-manager/hostfw/running"
HBOT_STRING_LID_FILE = "81e00684.lid"

class errludP_fipsErrl:
    # ***** Memory Layout Version 1 *****
    # 1 byte        : Version info
    # 3 bytes       : Header Info
    # N bytes       : HB traces

    # ***** Memory Layout Version 2 *****
    # 1 byte        : Version info
    # N bytes       : HB traces

    def UdParserHbTrace(ver, data):
        # For User Data with header:
        #    "Section Version":          "1",
        #    "Sub-section type":         "21",
        #    "Created by":               "0x3100",
        # NOTE: Other versions than just 1 are handled as well

        # Import the API that will be used to take the data and parse it out
        from udparsers.helpers.hostfw_trace import get_binary_trace_data_as_string

        # Create a dictionary and default to the data that the caller provided
        d = dict()
        d["Data"] = data

        # Default the string file to none
        stringFile = ""

        # Retrieve the hbotStringFile (81e00684.lid).  First check the patch
        # directory, if not there then retrieve from the running directory
        if os.path.exists(BMC_PATCH_DIR + '/' + HBOT_STRING_LID_FILE):
            stringFile = BMC_PATCH_DIR + '/' + HBOT_STRING_LID_FILE
        elif os.path.exists(BMC_LID_RUNNING_DIR + '/' + HBOT_STRING_LID_FILE):
            stringFile = BMC_LID_RUNNING_DIR + '/' + HBOT_STRING_LID_FILE

        # If did not find the hbotStringFile (81e00684.lid) then just return the data back to caller
        if not stringFile:
            jsonStr = json.dumps(d)
            return jsonStr

        startingPosition = 0     # start at the version info
        printNumberOfTraces = -1 # -1 means to get all traces
        (retVal, traceDataString) = get_binary_trace_data_as_string(data, startingPosition,
                                    printNumberOfTraces, stringFile)

        # If an error with getting the trace data then just return the data back to caller

        if retVal != 0:
            jsonStr = json.dumps(d)
            return jsonStr

        # If the data string ends with a newline, "\n", then remove it.
        # Removing the newline sets up the data string for the split
        # function below to not have an empty line at the end
        if traceDataString[-1] == "\n":
            traceDataString = traceDataString[:-1]

        # Split the data string into a list for "pretty printing"
        traces = traceDataString.split("\n")

        # Set the Data section to the traces list and return back to caller
        d['Data'] = traces
        jsonStr = json.dumps(d)
        return jsonStr


# Dictionary with parser functions for each subtype
# Value from enum errlUserDataType_t in src/include/usr/errl/hberrltypes.H:
#    FIPS_ERRL_UDT_HB_TRACE          = 0x15,   // A trace buffer
fipsErrlUserDetailDataSubsection = { 0x15: "UdParserHbTrace" }

def parseUDToJson(subType, ver, data):
        return getattr(errludP_fipsErrl, fipsErrlUserDetailDataSubsection[subType])(ver, data)

