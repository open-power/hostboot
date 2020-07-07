# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/runtime/plugins/ebmc/b1a00.py $
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
from udparsers.helpers.errludP_Helpers import hexDump, memConcat, hexConcat, findNull, strConcat

class errludP_hdat:
    #NACA
    def UdParserNaca(subType, ver, data):
        # ***** Memory Layout *****
        # 4 byte   : Physical Address Hi
        # 4 bytes  : Physical Address Lo
        # 4 bytes  : Virtual Address Hi
        # 4 bytes  : Virtual Address Lo
        d = dict()
        subd = dict()

        i = 0
        subd['Phys Addr Hi'], i=memConcat(data, i, i+4)
        subd['Phys Add Lo'], i=memConcat(data, i, i+4)
        subd['Virt Addr Hi'], i=memConcat(data, i, i+4)
        subd['Virt Addr Lo'], i=memConcat(data, i, i+4)
        subd['Byte Size']=f'{len(data):08x}'

        #Skip the rest if we don't have the data
        expectedSize = 8*2 #sizeof(uint64 t)*2
        buflen = len(data) - expectedSize
        if buflen != 0:
            #Hex Dump the whole thing first
            subd['Hex Dump']=hexDump(data, i, len(data))

            tmp = i
            # 0x0000 Spira-H offset (if non-zero)
            if buflen >= 0x0008:
                tmp = i + 0x0000
                subd['SPIRA-H'], _=memConcat(data, tmp, tmp+8)
            # 0x0030 Legacy SPIRA offset
            if buflen >= 0x0038:
                tmp = i + 0x0030
                subd['Legacy Spira'], _=memConcat(data, tmp, tmp+8)
            # 0x00A0 Actual Legacy SPIRA size in bytes
            if buflen >= 0x00A4:
                tmp = i + 0x00A0
                subd['Legacy SPIRA size'], _=memConcat(data, tmp, tmp+4)
            # 0x01B7 PHYP supports PCIA format
            if buflen >= 0x01B8:
                tmp = i + 0x01B7
                subd['Legacy Spira']=data[tmp]

        d['NACA']=subd

        jsonStr = json.dumps(d)
        return jsonStr

    #SPIRA
    def UdParserSpira(subType, ver, data):
        # ***** Memory Layout *****
        # 4 byte   : Physical Address Hi
        # 4 bytes  : Physical Address Lo
        # 4 bytes  : Virtual Address Hi
        # 4 bytes  : Virtual Address Lo

        d = dict()
        subd = dict()

        i = 0
        subd['Phys Addr Hi'], i=memConcat(data, i, i+4)
        subd['Phys Add Lo'], i=memConcat(data, i, i+4)
        subd['Virt Addr Hi'], i=memConcat(data, i, i+4)
        subd['Virt Addr Lo'], i=memConcat(data, i, i+4)
        subd['Byte Size']=f'{len(data):08x}'

        #Skip the rest if we don't have the data
        expectedSize = 8*2 #sizeof(uint64 t)*2
        buflen = len(data) - expectedSize
        if buflen != 0:
            subd['Hex Dump']=hexDump(data, i, len(data))
            #** 0x0000 Common HDIF header
            # 0x0002 Structure eye catcher
            if buflen >= 0x0008:
                tmp = i + 0x0002
                indx = findNull(data, tmp, tmp+6)
                subd['Eyecatcher'], _=strConcat(data, tmp, indx)
            # 0x000A Structure version
            if buflen >= 0x000C:
                tmp = i + 0x000A
                subd['Version'], i=memConcat(data, tmp, tmp+4)
            # ** 0x0030 Info on 5-tuple array
            # 0x0004 Number of array entries
            numTuples = 0
            if buflen >= 0x0038:
                tmp = i + 0x0034
                numTuples = memConcat(data, tmp, tmp+4)
                subd['Num Tuples'], i=numTuples

            d['SPIRA'] = subd

            #** 0x0040 5-tuple arrays
            for x in range(numTuples):
                label = 'Tuple #' + str(x)
                if buflen < (0x0040 + (x * 0x20)):
                    break
                tmp = i + 0x0040 + (x * 0x20)

                subd2 = dict()
                # 0x0000  Absolute address to a structure
                subd2['Address'], _=memConcat(data, tmp, tmp+8)
                # 0x0008  Allocated count
                temp = i + 0x0008
                subd2['Allocated Count'], _=memConcat(data, tmp, tmp+2)
                # 0x000A  Actual count
                temp = i + 0x000A
                subd2['Actual Count'], _=memConcat(data, tmp, tmp+2)
                # 0x000C  Allocated size in bytes
                temp = i + 0x000C
                subd2['Allocated Size'], _=memConcat(data, tmp, tmp+4)
                # 0x0010  Actual size in bytes
                temp = i + 0x0010
                subd2['Acutal Size'], _=memConcat(data, tmp, tmp+4)

                d[label]=subd2
        else:
            d['SPIRA'] = subd

        jsonStr = json.dumps(d)
        return jsonStr

    #TUPLE
    def UdParserTuple(subType, ver, data):
        # ***** Memory Layout *****
        # 4 byte   : Physical Address Hi
        # 4 bytes  : Physical Address Lo
        # 4 bytes  : Virtual Address Hi
        # 4 bytes  : Virtual Address Lo

        d = dict()
        subd = dict()
        i = 0
        subd['Phys Addr Hi'], i=memConcat(data, i, i+4)
        subd['Phys Add Lo'], i=memConcat(data, i, i+4)
        subd['Virt Addr Hi'], i=memConcat(data, i, i+4)
        subd['Virt Addr Lo'], i=memConcat(data, i, i+4)
        subd['Byte Size']= f'{len(data):08x}'

        #Skip the rest if we don't have the data

        expectedSize = 8*2 #sizeof(uint64 t)*2
        buflen = len(data) - expectedSize
        if buflen >= 0x0018:
            subd['Hex Dump']=hexDump(data, i, len(data))

            if buflen >= 0x0020:
                # 0x0000  Absolute address to a structure
                tmp = i + 0x0000
                subd['Address'], _=memConcat(data, tmp, tmp+8)
                # 0x0008  Allocated count
                tmp = i + 0x0008
                subd['Allocated Count'], _=memConcat(data, tmp, tmp+2)
                # 0x000A  Actual count
                tmp = i + 0x000A
                subd['Actual Count'], _=memConcat(data, tmp, tmp+2)
                # 0x000C  Allocated size in bytes
                tmp = i + 0x000C
                subd['Allocated Size'], _=memConcat(data, tmp, tmp+4)
                # 0x0010  Actual size in bytes
                tmp = i + 0x0010
                subd['Acutal Size'], _=memConcat(data, tmp, tmp+4)

        d['Tuple'] = subd

        jsonStr = json.dumps(d)
        return jsonStr

#Dictionary with parser functions for each subtype
#values are from UserDetailsTypes enum in src/include/usr/runtime/runtime_reasoncodes.H
UserDetailsTypes= { 1: "UdParserNaca",
                    2: "UdParserSpira",
                    3: "UdParserTuple"}

def parseUDToJson(subType, ver, data):
    args = (subType, ver, data)
    return getattr(errludP_hdat, UserDetailsTypes[subType])(*args)
