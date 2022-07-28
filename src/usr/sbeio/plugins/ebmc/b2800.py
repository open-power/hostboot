# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbeio/plugins/ebmc/b2800.py $
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
from pel.hexdump import hexdump
from udparsers.helpers.errludP_Helpers import hexConcat, memConcat, findNull, strConcat

class errludP_sbeio:
    def SbeIoUserDetailsParserNoFormat(ver, data, subType):
        # All versions will do NO formatting
        mv = memoryview(data)
        return json.dumps(hexdump(mv))

    def SbeIoUserDetailsParserFFDC(ver, data, subType):
        import importlib
        d = dict()
        if ver == 0:
            try:
                # This is the SBE/BMC o3500 module for parsing SBE_TRACE
                cls = importlib.import_module("udparsers.o3500.o3500")
                mv = memoryview(data)
                output = cls.parseUDToJson(subType, ver, mv)
                if output == -1:
                    d["Data"] = "PROBLEM with decoding the SBE_TRACE from o3500 parser"
                    jsonStr = json.dumps(d)
                    return jsonStr
                else:
                    # o3500 parseUDToJson will return jsonStr in output
                    return output
            except ImportError:
                d["Data"] = "b2800.py caught Import Error from o3500 SBE_TRACE parser"
                jsonStr = json.dumps(d)
                return jsonStr
            except Exception as e:
                d["Data"] = "b2800.py caught Exception={} from o3500 SBE_TRACE parser".format(e)
                jsonStr = json.dumps(d)
                return jsonStr

#Dictionary with parser functions for each subtype
#Values are from UserDetailsTypes enum
#in src/include/usr/sbeio/sbeioreasoncodes.H
SbeIoUserDetailDataSubSection = { 0: "SbeIoUserDetailsParserNoFormat",
                                  1: "SbeIoUserDetailsParserFFDC" }

def parseUDToJson(subType, ver, data):
    args = (ver, data, subType)
    return getattr(errludP_sbeio, SbeIoUserDetailDataSubSection[subType])(*args)
