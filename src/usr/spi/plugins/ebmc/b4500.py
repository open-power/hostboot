# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/spi/plugins/ebmc/b4500.py $
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
from udparsers.helpers.errludP_Helpers import hexDump, memConcat, hexConcat

class errludP_spi:
    #SPI Parameters
    def UdParserSpiEepromParameters(subType, ver, data):
        # ***** Memory Layout *****
        # 1 byte   : Op Type (DeviceFW::OperationType)
        # 4 bytes  : Controller Target HUID
        # 8 bytes  : Access Type (DeviceFW::AccessType)
        # 1 byte   : Engine
        # 8 bytes  : Offset
        # 8 bytes  : Length of In/Out Buffer
        # 8 bytes  : Adjusted Offset (to align request)
        # 8 bytes  : Adjusted Length of internal Buffer (to align request)
        # 1 byte   : Start index in adjusted buffer where requested data starts
        # 1 byte   : 1 : Adjusted Buffer used, 0: Adjusted Buffer unused

        d = dict()
        subd = dict()

        if ver == 1 and len(data) == 49:
            i  = 0
            op = data[i]
            # Keep this check in sync with DeviceFW::OperationType values
            # in src/include/usr/devicefw/driverif.H
            if op == 0:
                subd['SPI Operation']='Read'
            elif op == 1:
                subd['SPI Operation']='Write'
            else:
                subd['SPI Operation']='Unknown'

            subd['OP Type Value'], i=memConcat(data, i, i+1)
            subd['Controller Target HUID'], i=memConcat(data, i, i+4)
            subd['Access Type'], i=memConcat(data, i, i+8)
            subd['Engine'], i=memConcat(data, i, i+1)
            subd['Offset'], i=memConcat(data, i, i+8)
            subd['Length IO Buff'], i=memConcat(data, i, i+8)
            subd['Adjusted Offset'], i=memConcat(data, i, i+8)
            subd['Adjusted Length'], i=memConcat(data, i, i+8)
            subd['Start Index'], i=memConcat(data, i, i+1)
            subd['Adjusted Buffer Used'], i=memConcat(data, i, i+1)
        else:
            if ver != 1:
                subd['Unknown Parser Version']=hex(ver)
            subd['Hex Dump']=hexDump(data, 0, len(data))

        d['SPI EEPROM Parameters'], i=subd

        jsonStr = json.dumps(d)
        return jsonStr


#Dictionary with parser functions for each subtype
#Values from SpiUserDetailsTypes enum in src/include/usr/spi/spireasoncodes.H
SpiUserDetailsTypes = { 1: "UdParserSPIEepromParameters"}

def parseUDToJson(subType, ver, data):
    args = (subType, ver, data)
    return getattr(errludP_spi, SpiUserDetailsTypes[subType])(*args)
