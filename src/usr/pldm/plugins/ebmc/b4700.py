# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/pldm/plugins/ebmc/b4700.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2022
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

'''
Defines UD parsing classes for PLDM FFDC to be used on BMC
'''

import json
from udparsers.helpers.errludP_Helpers import hexDump, memConcat, hexConcat, intConcat

'''
Supported PLDM types
From: src/subtree/openbmc/pldm/libpldm/base.h
'''
pldm_supported_types = {
    0x00 : "PLDM_BASE",
    0x02 : "PLDM_PLATFORM",
    0x03 : "PLDM_BIOS",
    0x04 : "PLDM_FRU",
    0x05 : "PLDM_FWUP",
    0x3F : "PLDM_OEM"
}

'''
Supported commands for PLDM_BASE type
From: src/subtree/openbmc/pldm/libpldm/base.h
'''
pldm_base_commands = {
    0x02 : "PLDM_GET_TID",
    0x03 : "PLDM_GET_PLDM_VERSION",
    0x04 : "PLDM_GET_PLDM_TYPES",
    0x05 : "PLDM_GET_PLDM_COMMANDS"
}

'''
Supported commands for PLDM_PLATFORM type
From: src/subtree/openbmc/pldm/libpldm/platform.h
'''
pldm_platform_commands = {
    0x04 : "PLDM_SET_EVENT_RECEIVER",
    0x0A : "PLDM_PLATFORM_EVENT_MESSAGE",
    0x11 : "PLDM_GET_SENSOR_READING",
    0x21 : "PLDM_GET_STATE_SENSOR_READINGS",
    0x31 : "PLDM_SET_NUMERIC_EFFECTER_VALUE",
    0x32 : "PLDM_GET_NUMERIC_EFFECTER_VALUE",
    0x39 : "PLDM_SET_STATE_EFFECTER_STATES",
    0x50 : "PLDM_GET_PDR_REPOSITORY_INFO",
    0x51 : "PLDM_GET_PDR"
}

'''
Supported commands for PLDM_BIOS type
From: src/subtree/openbmc/pldm/libpldm/bios.h
'''
pldm_bios_commands = {
    0x01 : "PLDM_GET_BIOS_TABLE",
    0x02 : "PLDM_SET_BIOS_TABLE",
    0x07 : "PLDM_SET_BIOS_ATTRIBUTE_CURRENT_VALUE",
    0x08 : "PLDM_GET_BIOS_ATTRIBUTE_CURRENT_VALUE_BY_HANDLE",
    0x0c : "PLDM_GET_DATE_TIME",
    0x0d : "PLDM_SET_DATE_TIME"
}

'''
Supported commands for PLDM_FRU type
From: src/subtree/openbmc/pldm/libpldm/fru.h
'''
pldm_fru_commands = {
    0x01 : "PLDM_GET_FRU_RECORD_TABLE_METADATA",
    0x02 : "PLDM_GET_FRU_RECORD_TABLE",
    0x03 : "PLDM_SET_FRU_RECORD_TABLE",
    0x04 : "PLDM_GET_FRU_RECORD_BY_OPTION"
}

'''
Supported commands for PLDM_FWUP type
From: src/subtree/openbmc/pldm/libpldm/firmware_update.h
'''
pldm_firmware_update_commands = {
    0x01 : "PLDM_QUERY_DEVICE_IDENTIFIERS",
    0x02 : "PLDM_GET_FIRMWARE_PARAMETERS",
    0x10 : "PLDM_REQUEST_UPDATE",
    0x13 : "PLDM_PASS_COMPONENT_TABLE",
    0x14 : "PLDM_UPDATE_COMPONENT",
    0x15 : "PLDM_REQUEST_FIRMWARE_DATA",
    0x16 : "PLDM_TRANSFER_COMPLETE",
    0x17 : "PLDM_VERIFY_COMPLETE",
    0x18 : "PLDM_APPLY_COMPLETE",
    0x1A : "PLDM_ACTIVATE_FIRMWARE",
    0x1B : "PLDM_GET_STATUS",
    0x1C : "PLDM_CANCEL_UPDATE_COMPONENT",
    0x1D : "PLDM_CANCEL_UPDATE"
}

'''
Supported commands for IBM PLDM_OEM type
From:
pldm_fileio_commands : src/subtree/openbmc/pldm/oem/ibm/libpldm/file_io.h
pldm_host_commands   : src/subtree/openbmc/pldm/oem/ibm/libpldm/host.h
'''
pldm_oem_commands = {
    0x01 : "PLDM_GET_FILE_TABLE",
    0x04 : "PLDM_READ_FILE",
    0x05 : "PLDM_WRITE_FILE",
    0x06 : "PLDM_READ_FILE_INTO_MEMORY",
    0x07 : "PLDM_WRITE_FILE_FROM_MEMORY",
    0x08 : "PLDM_READ_FILE_BY_TYPE_INTO_MEMORY",
    0x09 : "PLDM_WRITE_FILE_BY_TYPE_FROM_MEMORY",
    0x0A : "PLDM_NEW_FILE_AVAILABLE",
    0x0B : "PLDM_READ_FILE_BY_TYPE",
    0x0C : "PLDM_WRITE_FILE_BY_TYPE",
    0x0D : "PLDM_FILE_ACK",
    0xF0 : "PLDM_HOST_GET_ALERT_STATUS"
}

'''
Associate PLDM type with its supported command codes
'''
pldm_type_to_commands = {
    "PLDM_BASE"     : pldm_base_commands,
    "PLDM_PLATFORM" : pldm_platform_commands,
    "PLDM_BIOS"     : pldm_bios_commands,
    "PLDM_FRU"      : pldm_fru_commands,
    "PLDM_FWUP"     : pldm_firmware_update_commands,
    "PLDM_OEM"      : pldm_oem_commands
}

'''
@brief Parses header fields into a dictionary (pldm_msg_field)
     pldm_msg_hdr = fields for first 3 bytes
     pldm_rsp_hdr = 4th byte = completion_code

     pldm_msg_field hash members:

     hex values:
        request_bit
        datagram_bit
        instance_id
        header_ver
        cmd_type
        (completion_code) <- if response data

      human-readable string (PLDM_...) values:
        cmd_type_str
        command_str
'''
def grabPldmHdrFields(data):
    pldm_msg_field = {}

    if (len(data) > 2):
        firstByte   = data[0]
        pldm_msg_field["request_bit"] = (firstByte & 0x80) >> 8
        pldm_msg_field["datagram_bit"] = (firstByte & 0x40) >> 6
        pldm_msg_field["instance_id"] = firstByte & 0x1F

        secondByte  = data[1]
        pldm_msg_field["header_ver"] = (secondByte & 0xC0) >> 6
        pldm_msg_field["cmd_type"] = secondByte & 0x3F

        # convert cmd_type into human-readable type str
        if pldm_msg_field["cmd_type"] in pldm_supported_types:
            pldm_msg_field["cmd_type_str"] = pldm_supported_types.get(pldm_msg_field["cmd_type"])
        else:
            pldm_msg_field["cmd_type_str"] = "UNSUPPORTED"

        cmdByte = data[2]
        pldm_msg_field["command"] = cmdByte

        # convert command byte into human-readable PLDM command str
        if (pldm_msg_field["cmd_type_str"] in pldm_type_to_commands):
            if (cmdByte in pldm_type_to_commands[pldm_msg_field["cmd_type_str"]]):
                pldm_msg_field['command_str'] = pldm_type_to_commands[pldm_msg_field['cmd_type_str']].get(cmdByte)

        if (len(data) > 3):
            pldm_msg_field['completion_code'] = data[3]

    return pldm_msg_field

'''
@brief parseHeaderData - parses the flight recorder header data
@param[in] data - array of flight recorder header data
@param[in] hdrByteSize - size in bytes of headers (3 = request hdr, 4 = response hdr)
@return dictorary with Index ###, parsed header info

Example of dictionary entries:
"Index 000": "raw=0x16020a00 seq_id=22 cmd_type=0x02 (PLDM_PLATFORM) cmd=0A (PLDM_PLATFORM_EVENT_MESSAGE) cmp_code=0x00",
"Index 001": "raw=0x173f0c00 seq_id=23 cmd_type=0x3F (PLDM_OEM) cmd=0C (PLDM_WRITE_FILE_BY_TYPE) cmp_code=0x00",
'''
def parseHeaderData(data, hdrByteSize):
    subd2 = dict()
    i = 0
    index = 0

    while i < len(data):
        hdr_field_data = grabPldmHdrFields(data[i:i+hdrByteSize])
        rawData, i = memConcat(data, i, i+hdrByteSize)

        # build up parsed string
        # example: raw=0x802004 seq_id=00 cmd_type=0x02 (PLDM_PLATFORM) cmd=04 (PLDM_SET_EVENT_RECEIVER)
        fullStr = "raw=0x"+rawData+" seq_id="+'{:02}'.format( hdr_field_data['instance_id'] )
        fullStr += " cmd_type=0x"+'{:02X}'.format( hdr_field_data['cmd_type'] )
        fullStr += " ("+hdr_field_data['cmd_type_str']+") cmd="+'{:02X}'.format(hdr_field_data['command'])
        if "command_str" in hdr_field_data:
            fullStr += " (" + hdr_field_data['command_str'] + ")"
        if 'completion_code' in hdr_field_data:
            fullStr += " cmp_code=0x"+'{:02X}'.format(hdr_field_data['completion_code'])

        indexHdr = 'Index '+ '{:03}'.format(index)
        subd2[indexHdr] = fullStr
        index = index+1

    return subd2

'''
@brief Parse flight recorder information (version 1)
       - checks for at least the 2-byte fr size
       - checks the remaining data is divisible by hbdrByteSize
@param[in] Data (2-byte fr size)+(flight recorder header data)
@param[in] hdrByteSize - byte size of fr header type (3 = request hdr, 4 = response hdr)
@return dictionary entry with data parsed into human-readable format
'''
def parseFrDumpVersion1(data, hdrByteSize):
    subd = dict()

    frDataLen = 0
    if (len(data) < 2):
        subd['Missing fr data size'] = len(data)
        subd['Hex Dump']=hexDump(data, 0, len(data))
    else:
        frDataLen, i=intConcat(data, 0, 2)
        if (frDataLen % hdrByteSize != 0):
            subd['Indivisible fr length ('+hdrByteSize+'-byte msg hdrs)'] = frDataLen
            subd['Hex Dump']=hexDump(data, 0, len(data))
        else:
            if (frDataLen == 0):
                subd['Empty']
            else:
                subd = parseHeaderData(data[2:frDataLen+2], hdrByteSize)
    return subd

class errludP_pldm:

    def UdPldmMsgIncomplete(subType, ver, data):
        d = dict()
        subd = dict()

        subd['Hex Dump']=hexDump(data, 0, len(data))
        d['Partial PLDM msg data'] = subd

        jsonStr = json.dumps(d)
        return jsonStr

    def UdPldmMsg(subType, ver, data):
        d = dict()
        subd = dict()

        subd['Hex Dump']=hexDump(data, 0, len(data))
        d['Full PLDM msg data'] = subd

        jsonStr = json.dumps(d)
        return jsonStr

    def UdPldmFrInRequestParameters(subType, ver, data):
        d = dict()
        subd = dict()

        if (ver >= 1):
            subd = parseFrDumpVersion1(data, 3);
        else:
            subd['Unexpected version'] = hex(ver)
            subd['Hex Dump']=hexDump(data, 0, len(data))

        d['Incoming PLDM Requests (HB<-BMC)'] = subd

        jsonStr = json.dumps(d)
        return jsonStr

    def UdPldmFrOutRequestParameters(subType, ver, data):
        d = dict()
        subd = dict()

        if (ver >= 1):
            subd = parseFrDumpVersion1(data, 3);
        else:
            subd['Unexpected version'] = hex(ver)
            subd['Hex Dump']=hexDump(data, 0, len(data))

        d['Outgoing PLDM Requests (HB->BMC)'] = subd

        jsonStr = json.dumps(d)
        return jsonStr

    def UdPldmFrInResponseParameters(subType, ver, data):
        d = dict()
        subd = dict()

        if (ver >= 1):
            subd = parseFrDumpVersion1(data, 4);
        else:
            subd['Unexpected version'] = hex(ver)
            subd['Hex Dump']=hexDump(data, 0, len(data))

        d['Incoming PLDM Responses (HB<-BMC)'] = subd

        jsonStr = json.dumps(d)
        return jsonStr

    def UdPldmFrOutResponseParameters(subType, ver, data):
        d = dict()
        subd = dict()

        if (ver >= 1):
            subd = parseFrDumpVersion1(data, 4);
        else:
            subd['Unexpected version'] = hex(ver)
            subd['Hex Dump']=hexDump(data, 0, len(data))

        d['Outgoing PLDM Responses (HB->BMC)'] = subd

        jsonStr = json.dumps(d)
        return jsonStr

#Dictionary with parser functions for each subtype
#Values from pldmUserDetailDataSubsection enum in src/include/usr/pldm/pdlm_reasoncodes.H
PldmUserDetailsTypes = { 1: "UdPldmMsgIncomplete",
                         2: "UdPldmMsg",
                         3: "UdPldmFrInRequestParameters",
                         4: "UdPldmFrOutRequestParameters",
                         5: "UdPldmFrInResponseParameters",
                         6: "UdPldmFrOutResponseParameters"}

def parseUDToJson(subType, ver, data):
    args = (subType, ver, data)
    return getattr(errludP_pldm, PldmUserDetailsTypes[subType])(*args)
