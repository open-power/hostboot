# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbe/plugins/ebmc/b2200.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2023
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
from udparsers.helpers.errludP_Helpers import memConcat

class errludP_sbe:

    def UdParserNoFormat(subType, ver, data):
        # All versions will not format the data
        mv = memoryview(data)
        return json.dumps(hexdump(mv))

    def UdParserSbeMessageCommand(subType, ver, data):

        # ***** Memory Layout *****
        # Sbe Message Header
        # 4 Bytes : Sbe Header Version
        # 4 Bytes : Sbe Message Size (Pass-through cmd or rsp) includes SBE & CMD headers
        # 4 Bytes : Sequence ID
        # Command Header
        # 4 Bytes : Command Header Version
        # 4 Bytes : Status of processing
        # 4 Bytes : Data Offset from beginning of command header
        # 4 Bytes : Data Size excl. header fields
        # 4 Bytes : Pass-through command
        if ver == 1:
            d = dict()
            i = 0
            labels = {0 : "SBE Message Header Version",
                      1 : "Message Size",
                      2 : "Sequence ID",
                      3 : "Command Header Version",
                      4 : "Status",
                      5 : "Data Offset",
                      6 : "Data Size",
                      7 : "Command" }
            for x in range(8):
                word, i=memConcat(data, i, i+4)
                d[labels[x]] = word
            return json.dumps(d)

    def UdParserSbeMessageData(subType, ver, data):
        # For this parser the version given to the parser is acting as a unique key to trace back
        # from which SBE message header this data originates. By cross-referencing the version in the
        # PEL with the code, readers should be able to tell which message this was for. In an error
        # there isn't any other trustworthy data to use and we don't want the data section grouped
        # with the rest of the header as it could be large enough to be discarded by the error log for
        # space reasons.
        if ver >= 1:
            d = dict()
            mv = memoryview(data)
            d["SBE Message Data - See Ver+Code for hdr"] = hexdump(mv)
            return json.dumps(d)

# Dictionary with parser functions for each subtype
# values are taken from UserDetailsTypes enum in src/include/usr/sbe/sbereasoncodes.H
# Note: The values defined in that file will be what are passed into the parser so they must be
#       kept in sync between this file and the listed one.
UserDetailsTypes = { 0 : "UdParserNoFormat",
                     1 : "UdParserSbeMessageCommand",
                     2 : "UdParserSbeMessageData" }

# Required function which handles calling the appropriate class function from above.
def parseUDToJson(subType, ver, data):
    args = (subType, ver, data)
    return getattr(errludP_sbe, UserDetailsTypes[subType])(*args)
