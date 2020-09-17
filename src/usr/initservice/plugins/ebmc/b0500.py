# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/initservice/plugins/ebmc/b0500.py $
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
from udparsers.helpers.errludP_Helpers import hexConcat, memConcat, findNull, strConcat

class errludP_initservice:
    def InitSvcUserDetailsParserIstep(ver, data):
        # ***** Memory Layout *****
        # 1 byte   : Step
        # 1 byte   : Substep
        # N bytes  : IStep Name

        d = dict()
        i = 0

        ivStep, i=memConcat(data, i, i+2)
        ivSubStep, i=memConcat(data, i, i+2)

        # find index of null character
        indx = findNull(data, i, len(data))

        d['IStep Name'], i=strConcat(data, i, indx)
        d['Step']=ivStep
        d['Sub-step']=ivSubStep

        jsonStr = json.dumps(d)
        return jsonStr

#Dictionary with parser functions for each subtype
#Values are from InitServiceUserDetailDataSubSection enum
#in src/include/usr/initservice/initsvcreasoncodes.H
InitServiceUserDetailDataSubSection = { 1: "InitSvcUserDetailsParserIstep" }

def parseUDToJson(subType, ver, data):
    args = (ver, data)
    return getattr(errludP_initservice, InitServiceUserDetailDataSubSection[subType])(*args)
