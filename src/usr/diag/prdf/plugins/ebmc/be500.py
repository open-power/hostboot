# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/plugins/ebmc/be500.py $
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
from udparsers.helpers.errludP_Helpers import hexConcat, intConcat, strConcat

class errludP_prdf:

    def UdParserPrdfCapData(ver, data):
        d = dict()
        # TODO
        jsonStr = json.dumps(d)
        return jsonStr

    def UdParserPrdfString(ver, data):
        d = dict()
        # TODO
        jsonStr = json.dumps(d)
        return jsonStr

    def UdParserPrdfPmFfdcData(ver, data):
        d = dict()
        # TODO
        jsonStr = json.dumps(d)
        return jsonStr

    def UdParserPrdfPfaData(ver, data):
        d = dict()
        # TODO
        jsonStr = json.dumps(d)
        return jsonStr

    def UdParserPrdfMruData(ver, data):
        d = dict()
        # TODO
        jsonStr = json.dumps(d)
        return jsonStr

# Dictionary with parser functions for each subtype
# Values are from ErrlSubsect enum in:
#   src/usr/diag/prdf/common/plugins/prdfPfa5Data.h
UserDetailsTypes = {
     1: "UdParserPrdfCapData",
    10: "UdParserPrdfString",
    20: "UdParserPrdfPmFfdcData",
    51: "UdParserPrdfPfaData",
    62: "UdParserPrdfMruData",
}

def parseUDToJson(subType, ver, data):
    args = (ver, data)
    return getattr(errludP_prdf, UserDetailsTypes[subType])(*args)

