# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/secureboot/common/plugins/ebmc/b1e00.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2021
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
from udparsers.helpers.errludP_Helpers import hexDump, memConcat, hexConcat, intConcat, findNull, strConcat

class errludP_secure:

    #Constants used in parsers below
    #Values from enum in src/usr/secureboot/common/plugins/errludP_secure.H
    UDPARSER_SIZEOF_SHA512_t = 64
    UDPARSER_SIZEOF_MAX_VERIFY_IDS = 50

    #System HW Key Hash
    def UdParserSystemHwKeyHash(subType, ver, data):
        # ***** Memory Layout *****
        # bytes : SHA512 t of System HW Key Hash

        d = dict()
        subd = dict()

        subd['Hex Dump']=hexDump(data, 0, errludP_secure.UDPARSER_SIZEOF_SHA512_t)
        d['System HW Key Hash']=subd

        jsonStr = json.dumps(d, indent=2)
        return jsonStr

    #Target HW Key Hash
    def UdParserTargetHwKeyHash(subType, ver, data):
        # ***** Memory Layout *****
        # 4 bytes  : Target HUID
        # 1 byte   : SBE SEEPROM (Primary or Backup)
        # 64 bytes : SHA512 t of Target HW Key Hash

        d = dict()
        subd = dict()

        i = 0
        subd['Target HUID'], i= memConcat(data, i, i+4)

        side = data[i]
        i += 1
        if side == 0:
            subd['SBE Primary']=side
        elif side == 1:
            subd['SBE Backup']=side
        else:
            subd['Unknown SBE']=side

        #Hex Dump
        subd['Hex Dump']=hexDump(data, i, i+errludP_secure.UDPARSER_SIZEOF_SHA512_t)
        i +=errludP_secure.UDPARSER_SIZEOF_SHA512_t

        d['Target HW Key Hash']=subd

        jsonStr = json.dumps(d, indent=2)
        return jsonStr

    #Security Settings
    def UdParserSecuritySettings(subType, ver, data):
        # ***** Version 1 Memory Layout *****
        # 1 byte   : Secure Access Bit
        # 1 byte   : Security Override
        # 1 byte   : Allow Attribute Overrides
        # **** Version 2 Memory Layout ****
        # Append this to the end of Version 1:
        # 1 byte   : Minimum FW Secure Version
        # **** Version 3 Memory Layout ****
        # Append this to the end of Version 2:
        # 4 bytes  : Measurement Seeprom Version

        d = dict()
        subd = dict()

        if ver >= 1:
            i = 0
            subd['Secure Access Bit'], i= hexConcat(data, i, i+1)
            subd['Security Override'], i= hexConcat(data, i, i+1)
            subd['Allow Attribute Overrides'], i= hexConcat(data, i, i+1)

        if ver >= 2:
            subd['Minimum FW Secure Version'], i= hexConcat(data, i, i+1)

        if ver >= 3:
            subd['Measurement Seeprom Version'], i= hexConcat(data, i, i+4)

        d['Security Settings']=subd

        jsonStr = json.dumps(d, indent=2)
        return jsonStr

    #Secure Verify Info
    def UdParserVerifyInfo(subType, ver, data):
        # ***** Version 1 Memory Layout *****
        # 9 bytes Max : Component ID (8 byte string + NULL) use strlen
        # 8 bytes     : Protected Payload Size
        # 4 bytes     : Number of IDs
        # 4*N bytes   : IDs (PNOR id or LidID) multiplied by number of ids
        # 64 bytes    : Measured Hash
        # 64 bytes    : Expected Hash
        # **** Version 2 Memory Layout ****
        # Append this to the end of Version 1:
        # 1 byte      : Minimum FW Secure Version
        # 1 byte      : Input Secure Version
        # 1 byte      : Container Secure Version

        d = dict()

        parseError = False
        i = 0
        if ver >= 1:
            subd = dict()

            indx = findNull(data, i, 9)
            subd['Component ID'], i=strConcat(data, i, indx)
            subd['Protected Payload Size'], i=hexConcat(data, i, i+8)

            numIDs, i= intConcat(data, i, i+4)
            subd['Number Of IDs']=numIDs

            d['Secure Verify Info']=subd

            #Add all IDs to dict
            subd2 = dict()
            for x in range(numIDs):
                label = 'ID ' + str(x)
                subd2[label], i= hexConcat(data, i, i+4)
                #In case of bad format, don't go past max size
                if x >= errludP_secure.UDPARSER_SIZEOF_MAX_VERIFY_IDS:
                    parseError = True
                    break
            d['ID(s)']=subd2
            #In case of bad format, don't continue to parse section
            if not parseError:
                d['Measured Hash']=hexDump(data, i, i+errludP_secure.UDPARSER_SIZEOF_SHA512_t)
                i += errludP_secure.UDPARSER_SIZEOF_SHA512_t
                d['Expected Hash']=hexDump(data, i, i+errludP_secure.UDPARSER_SIZEOF_SHA512_t)
                i += errludP_secure.UDPARSER_SIZEOF_SHA512_t

        if ver >= 2:
            d['Minimum FW Secure Version 0x'], i=memConcat(data, i, i+1)
            d['Input Secure Version 0x'], i=memConcat(data, i, i+1)
            d['Container Secure Version 0x'], i=memConcat(data, i, i+1)

        jsonStr = json.dumps(d, indent=2)
        return jsonStr


    #Secure Node Comm Info
    def UdParserNodeCommInfo(subType, ver, data):
        # ***** Node Comm SECURE UDT VERSION 1 Memory Layout *****
        # 4 bytes  : Target HUID
        # 8 bytes  : Length of In/Out Buffer
        # 8 bytes  : Access Type (DeviceFW::AccessType)
        # 1 byte   : Op Type (DeviceFW::OperationType)
        # 1 byte   : Mode (XBUS or ABUS)
        # 1 byte   : LinkId
        # 1 byte   : MboxId

        d = dict()
        subd = dict()

        i = 0
        subd['Target HUID 0x'], i=memConcat(data, i, i+4)
        subd['Length I/O Buff 0x'], i=memConcat(data, i, i+8)
        subd['Access Type 0x'], i=memConcat(data, i, i+8)

        d['Secure Node Comm Info'] = subd

        subd2 = dict()
        op = data[i]
        i += 1
        subd2['Op Type Value 0x']=f'{op:02x}'

        # Keep this check in sync with DeviceFW::OperationType values
        # in src/include/usr/devicefw/driverif.H
        if op == 0:
            d['Node Comm Read']=subd2
        elif op == 1:
            d['Node Comm Write']=subd2
        else:
            d['Unknown Node Comm Operation']=subd2

        subd3 = dict()
        op2 = data[i]
        i += 1

        subd3['MODE 0x']=f'{op2:02x}'
        subd3['LinkId 0x'], i=memConcat(data, i, i+1)
        subd3['MboxID 0x'], i=memConcat(data, i, i+1)

        if op2 == 0:
            d['Node Comm Mode: XBUS']=subd3
        elif op2 == 1:
            d['Node Comm Mode: ABUS']=subd3
        else:
            d['INVALID Node Comm Mode']=subd3

        jsonStr = json.dumps(d, indent=2)
        return jsonStr

#Dictionary with parser functions for each subtype
#values are from UserDetailsTypes enum in src/include/usr/secureboot/secure_reasoncodes.H
UserDetailsTypes = { 1: "UdParserSystemHwKeyHash",
                     2: "UdParserTargetHwKeyHash",
                     3: "UdParserSecuritySettings",
                     4: "UdParserVerifyInfo",
                     5: "UdParserNodeCommInfo" }

def parseUDToJson(subType, ver, data):
    args = (subType, ver, data)
    return getattr(errludP_secure, UserDetailsTypes[subType])(*args)
