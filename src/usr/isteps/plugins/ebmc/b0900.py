# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/plugins/ebmc/b0900.py $
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
from udparsers.helpers.errludP_Helpers import hexConcat, intConcat

class errludP_hwpistep:
    #Generated Parser Functions
    from udparsers.b0900.hbfwPlatHwpErrParser import hbfwErrLookupHwpRc
    from udparsers.b0900.hbfwPlatHwpErrParserFFDC import hbfwParseHwpFfdc

    def HwpUserDetailsParserIstep(ver, data):
        d = dict()
        i = 0
        d['See error log ID'], i=hexConcat(data, i, i+4)
        reasoncode, i=intConcat(data, i, i+4)
        d['Reasoncode']=f'0x{reasoncode:x}'

        jsonStr = json.dumps(d)
        return jsonStr

    # The following are basic hex dumps for BAD DQ UserDetail Sections
    # see hwpf_fapi2_reasoncodes.H

    def HwpUserDetailsParserSpecialOneByte(ver, data):
        # 1 byte   :  ONE BYTE OF DATA
        d = dict()
        i = 0
        d['ONE_BYTE'], i=hexConcat(data, i, i+1)

        jsonStr = json.dumps(d)
        return jsonStr

#Dictionary with parser functions for each subtype
#Values are from hwpfUserDetailDataSubSection enum in src/include/usr/isteps/hwpf_reasoncodes.H
hwpfUserDetailDataSubSection = { 1: "hbfwErrLookupHwpRc", #Generated
                                 2: "hbfwParseHwpFfdc",  #Generated
                                 3: "HwpUserDetailsParserIstep",
                                 10: "HwpUserDetailsParserSpecialOneByte",
                                 11: "HwpUserDetailsParserSpecialOneByte",
                                 12: "HwpUserDetailsParserSpecialOneByte",
                                 13: "HwpUserDetailsParserSpecialOneByte",
                                 14: "HwpUserDetailsParserSpecialOneByte",
                                 15: "HwpUserDetailsParserSpecialOneByte",
                                 16: "HwpUserDetailsParserSpecialOneByte",
                                 17: "HwpUserDetailsParserSpecialOneByte" }

def parseUDToJson(subType, ver, data):
    args = (ver, data)
    return getattr(errludP_hwpistep, hwpfUserDetailDataSubSection[subType])(*args)
