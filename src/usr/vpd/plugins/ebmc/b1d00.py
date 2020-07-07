# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/vpd/plugins/ebmc/b1d00.py $
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
from udparsers.helpers.errludP_Helpers import memConcat

class errludP_vpd:
    #VPD Parameters
    def UdParserVpdParms(subType, ver, data):
        #***** Memory Layout *****
        # 1 byte   : Read / Not-Write
        # 4 bytes  : Target HUID
        # 8 bytes  : Length of In/Out Buffer
        # 8 bytes  : Record
        # 8 bytes  : Keyword
        d = dict()
        subd = dict()
        i = 0

        op = data[i]
        i += 1

        # Keep this check in sync with DeviceFW::OperationType values
        # in src/include/usr/devicefw/driverif.H
        if op == 1:
            subd['VPD Operation']='Read'
        elif op == 0:
            subd['VPD Operation']='Write'
        else:
            subd['VPD Operation']='Unknown'

        subd['Target'], i=memConcat(data, i, i+4)
        subd['Length of I/O Buffer'], i=memConcat(data, i, i+8)
        subd['Record'], i=memConcat(data, i, i+8)
        subd['Keyword'], i=memConcat(data, i, i+8)

        d['VPD Parameters']=subd

        jsonStr = json.dumps(d)
        return jsonStr

    #VPD Config Parameters
    def UdParserConfigParms(subType, ver, data):
        # ***** Memory Layout *****
        # 4 bytes  : Target HUID
        # 8 bytes  : Record
        # 8 bytes  : Keyword
        # 8 bytes  : Location
        # 8 bytes  : Read PNOR Config
        # 8 bytes  : Read HW Config
        # 8 bytes  : Write PNOR Config
        # 8 bytes  : Write HW Config

        d = dict()
        subd = dict()

        i = 0
        subd['Target'], i=memConcat(data, i, i+4)
        subd['Record'], i=memConcat(data, i, i+8)
        subd['Keyword'], i=memConcat(data, i, i+8)
        subd['Location'], i=memConcat(data, i, i+8)
        subd['Read PNOR Config'], i=memConcat(data, i, i+8)
        subd['Read HW Config'], i=memConcat(data, i, i+8)
        subd['Write PNOR Config'], i=memConcat(data, i, i+8)
        subd['Write HW Config'], i=memConcat(data, i, i+8)

        d['VPD Config Parameters']=subd

        jsonStr = json.dumps(d)
        return jsonStr


#Dictionary with parser functions for each subtype
#values are from UserDetailsTypes enum in src/include/usr/vpd/vpdreasoncodes.H
UserDetailsTypes = { 1: "UdParserVpdParms",
                     2: "UdParserConfigParms" }

def parseUDToJson(subType, ver, data):
    args = (subType, ver, data)
    return getattr(errludP_vpd, UserDetailsTypes[subType])(*args)
