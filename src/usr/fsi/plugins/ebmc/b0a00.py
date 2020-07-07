# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/fsi/plugins/ebmc/b0a00.py $
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
from udparsers.helpers.errludP_Helpers import memConcat, intConcat

#FSI Parsers
class errludP_fsi:
    #FSI Presence
    def UdParserPresence(subType, ver, data):
        #***** Memory Layout *****
        # 4 bytes  : Secondary HUID
        # 4 bytes  : Primary HUID
        # 1 byte   : FSI Primary TYPE
        # 1 byte   : port
        # 1 byte   : cascade
        # 2 bytes  : flags
        # 4 bytes  : linkid (node+proc+type+port)
        # 2 bytes  : Size of iv secondary[]
        # 8 bytes  : secondary enable Index
        # X bytes  : iv secondary[]

        d = dict()
        subd = dict()
        i = 0

        subd['Secondary'], i=memConcat(data, i, i+4)
        subd['Primary'], i=memConcat(data, i, i+4)
        subd['Type'], i=memConcat(data, i, i+1)
        subd['Port'], i=memConcat(data, i, i+1)
        subd['Cascade'], i=memConcat(data, i, i+1)
        subd['Flags'], i=memConcat(data, i, i+2)
        secondarySize, i=intConcat(data, i, i+2)
        index, i=intConcat(data, i, i+8)

        d['FSI Presence']=subd

        subd2 = dict()
        for x in range(secondarySize):
            if x == index:
                label = '*Primary ' + str(x) + '*'
            else:
                label = 'Primary ' + str(x)

            subd2[label], i=memConcat(data, i, i+1)

        d['Detected Secondaries']=subd2

        jsonStr = json.dumps(d)
        return jsonStr

    #Operation
    def UdParserOperation(subType, ver, data):
        # ***** Memory Layout *****
        # 4 bytes  : Target HUID
        # 8 bytes  : FSI Address
        # 1 byte   : 1=read, 0=write

        d = dict()
        subd = dict()
        i = 0

        targ, i=memConcat(data, i, i+4)
        addr, i=memConcat(data, i, i+8)
        op = data[i]
        i += 1

        subd['OP Target']=targ
        subd['Address']=addr

        # Keep this check in sync with DeviceFW::OperationType values
        # in src/include/usr/devicefw/driverif.H
        if op == 1:
           d['FSI Read']=subd
        elif op == 0:
            d['FSI Write']=subd
        else:
            d['Unknown FSI Operation']=subd

        jsonStr = json.dumps(d)
        return jsonStr

#Dictionary with parser functions for each subtype
#Values are from enum in src/include/usr/fsi/fsi_reasoncodes.H
UserDetailsTypes = { 1: "UdParserPresence",
                     2: "UdParserOperation" }

def parseUDToJson(subType, ver, data):
    args = (subType, ver, data)
    return getattr(errludP_fsi, UserDetailsTypes[subType])(*args)
