# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/scom/plugins/ebmc/b0300.py $
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
from udparsers.helpers.errludP_Helpers import hexDump

#SCOM PIB ERR
class errludP_scom:
    def UdParserPib(subType, ver, data):
        # ***** Memory Layout *****
        # 1 bytes       : Pib Error

        #values from src/usr/scom/plugins/errludP_scom.H
        codeToErr={ 0: "None",
                    1: "Resource Occupied",
                    2: "Chiplet Offline",
                    3: "Partial Good",
                    4: "Invalid Address",
                    5: "Clock Error",
                    6: "Parity Error",
                    7: "Timeout" }

        subd = dict()

        piberr = data[0]
        decodeStr = codeToErr.get(piberr, "Unknown")
        subd["Pib Err"] = str(piberr) + " (" + decodeStr + ")"

        d['SCOM PIB ERR'] = subd

        jsonStr = json.dumps(d)
        return jsonStr

#Dictionary with parser functions for each subtype
#Values are from UserDetailsTypes enum in src/include/usr/scom/scomreasoncodes.H
UserDetailsTypes = { 1: "UdParserPib" }

def parseUDToJson(subType, ver, data):
    args = (subType, ver, data)
    return getattr(errludP_scom, UserDetailsTypes[subType])(*args)
