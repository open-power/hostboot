# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/expaccess/plugins/ebmc/b3600.py $
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

import json
from udparsers.helpers.errludP_Helpers import hexDump, memConcat, hexConcat, intConcat

class errludP_expscom:
    #Explorer Active (RAM) Log Data
    def UdParserExpActiveLog(subType, ver, data):
        # ***** Memory Layout *****
        # Header
        # 2 bytes  : Ordering byte (0=first packet)
        # 4 bytes  : Offset where data portion started in full explorer log
        # 2 bytes  : Size of data portion following header
        #
        # N bytes  : Error Data

        headerSize = 2 + 4 + 2
        d = dict()
        subd = dict()
        i = 0

        subd['Order Packet'], i=memConcat(data, i, i+2)
        subd['Data Starting Offset'], i=hexConcat(data, i, i+4)

        errorDataSize, i=intConcat(data, i, i+2)
        subd['Size Of Data Section']=f'0x{errorDataSize:04x}'

        d['Explorer Active (RAM) Log Data']=subd

        if errorDataSize <= (len(data) - headerSize):
            d['Error Data'], i=hexDump(data, i, i+errorDataSize)
        else:
            subd2 = dict()

            subd2['Expected Data Size']= hex(len(data) - headerSize)
            subd2['Hex Dump']= hexDump(data, 0, len(data))
            d['ERROR DATA MISSING - Printing entire section in Hex']=subd2

        jsonStr = json.dumps(d, indent=2)
        return jsonStr

    #Explorer Saved (SPI flash) Log Data
    def UdParserExpSavedLog(subType, ver, data):
        # ***** Memory Layout *****
        # Header
        # 2 bytes  : Ordering byte (0=first packet)
        # 4 bytes  : Offset where data portion started in full explorer log
        # 2 bytes  : Size of data portion following header
        #
        # N bytes  : Error Data

        headerSize = 2 + 4 + 2
        d = dict()
        subd = dict()
        i = 0

        subd['Order Packet'], i=memConcat(data, i, i+2)
        subd['Data Starting Offset'], i=hexConcat(data, i, i+4)

        errorDataSize, i= intConcat(data, i, i+2)
        subd['Size Of Data Section']=f'0x{errorDataSize:04x}'

        d['Explorer Saved (SPI flash) Log Data']=subd

        if errorDataSize <= (len(data) - headerSize):
            d['Error Data']=hexDump(data, i, i+errorDataSize)
        else:
            subd2 = dict()

            subd2['Expected Data Size']= hex(len(data) - headerSize)
            subd2['Hex Dump']= hexDump(data, 0, len(data))
            d['ERROR DATA MISSING - Printing entire section in Hex']=subd2

        jsonStr = json.dumps(d, indent=2)
        return jsonStr

#Dictionary with parser functions for each subtype
#Values are from UserDetailsTypes enum in src/include/usr/expscom/expscom_reasoncodes.H
UserDetailsTypes = { 1: "UdParserExpActiveLog",
                     2: "UdParserExpSavedLog" }

def parseUDToJson(subType, ver, data):
    args = (subType, ver, data)
    return getattr(errludP_expscom, UserDetailsTypes[subType])(*args)
