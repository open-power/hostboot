# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/errl/parser/ebmc/bsrc.py $
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
from srcparsers.bsrc.srcdisplaydata import srcInfo

""" Parser for SRC details
    Takes the Comp ID + Module ID passed in to get the corresponding
    dictionary from srcdisplaydata.py
"""

def parseSRCToJson(ascii_str, word2, word3, word4, word5, word6, word7, word8, word9):
    #ascii_str is in the form: Bsxxyyyy
    #where yyyy = Comp ID + Reasoncode

    #word3 is in the form: ssssmmrr
    #where mm = Module ID

    #Get dictionary for corresponding Comp ID + Reasoncode + Mod ID
    d = srcInfo.get(int(ascii_str[4:8] + word3[4:6], 16))

    jsonStr = json.dumps(d, indent = 2)
    return jsonStr
