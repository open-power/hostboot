# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbeio/plugins/ebmc/b2800.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2024
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
        if ver >= 0:
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
            # exceptions are caught in the higher calling layers and dumped out
            except Exception as e:
                raise

    def SbeIoUserDetailsParserSPPEFFDC(ver, data, subType):
        import importlib
        d = dict()
        if ver >= 0:
            try:
                # This is the SPPE/BMC o4500 module for parsing SBE_TRACE
                cls = importlib.import_module("udparsers.o4500.o4500")
                mv = memoryview(data)
                output = cls.parseUDToJson(subType, ver, mv)
                if output == -1:
                    d["Data"] = "PROBLEM with decoding the SBE_TRACE from o4500 parser"
                    jsonStr = json.dumps(d)
                    return jsonStr
                else:
                    # o4500 parseUDToJson will return jsonStr in output
                    return output
            # exceptions are caught in the higher calling layers and dumped out
            except Exception as e:
                raise

    def SbeIoUserDetailsSPPECodeLevels(ver, data, subType):
        # 4 bytes  : OCMB HUID
        # 4 bytes  : ATTR_SBE_VERSION_INFO
        # 4 bytes  : ATTR_SBE_COMMIT_ID
        # 64 bytes : ATTR_SBE_BOOTLOADER_CODELEVEL
        # 64 bytes : ATTR_SBE_RUNTIME_CODELEVEL
        # 21 bytes : ATTR_SBE_RELEASE_TAG
        # 21 bytes : ATTR_SBE_BUILD_TAG
        # 21 bytes : ATTR_SBE_EKB_BUILD_TAG
        d = dict()
        subd = dict()
        i = 0

        subd['OCMB HUID'], i=memConcat(data, i, i+4)
        subd['ATTR_SBE_VERSION_INFO'], i=memConcat(data, i, i+4)
        subd['ATTR_SBE_COMMIT_ID'], i=memConcat(data, i, i+4)
        subd['ATTR_SBE_BOOTLOADER_CODELEVEL[0-63]'], i=memConcat(data, i, i+64)
        subd['ATTR_SBE_RUNTIME_CODELEVEL[0-63]'], i=memConcat(data, i, i+64)
        indx = findNull(data, i, i+20)
        subd['ATTR_SBE_RELEASE_TAG'], label=strConcat(data, i, indx)
        i += 21
        indx = findNull(data, i, i+20)
        subd['ATTR_SBE_BUILD_TAG'], label=strConcat(data, i, indx)
        i += 21
        indx = findNull(data, i, i+20)
        subd['ATTR_SBE_EKB_BUILD_TAG'], label=strConcat(data, i, indx)
        i += 21

        d['SPPE Code Levels']=subd

        jsonStr = json.dumps(d)
        return jsonStr

#Dictionary with parser functions for each subtype
#Values are from UserDetailsTypes enum
#in src/include/usr/sbeio/sbeioreasoncodes.H
SbeIoUserDetailDataSubSection = { 0: "SbeIoUserDetailsParserNoFormat",
                                  1: "SbeIoUserDetailsParserFFDC",
                                  2: "SbeIoUserDetailsSPPECodeLevels",
                                  3: "SbeIoUserDetailsParserSPPEFFDC",
                                  4: "SbeIoUserDetailsParserNoFormat",
                                  5: "SbeIoUserDetailsParserNoFormat",
                                  6: "SbeIoUserDetailsParserNoFormat" }

def parseUDToJson(subType, ver, data):
    args = (ver, data, subType)
    return getattr(errludP_sbeio, SbeIoUserDetailDataSubSection[subType])(*args)
