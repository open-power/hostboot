# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/eeprom/plugins/ebmc/b0e00.py $
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
from udparsers.helpers.errludP_Helpers import memConcat, strConcat, findNull

class errludP_eeprom:
    #EEPROM Parameters
    def UdParserEepromI2cParms(subType, ver, data):
        # ***** Memory Layout *****
        # 1 byte   : Op Type Description
        # 1 byte   : Op Type (DeviceFW::OperationType)
        # 1 byte   : Eeprom access method
        # 4 bytes  : Target HUID
        # 8 bytes  : Length of In/Out Buffer
        # 8 bytes  : Chip
        # 8 bytes  : Offset
        # 8 bytes  : Port
        # 8 bytes  : Engine
        # 8 bytes  : Device Address
        # 1 byte   : Address Size
        # 8 bytes  : Write Page Size
        # 8 bytes  : Device Size (in KB)
        # 8 bytes  : Chip Count
        # 8 bytes  : Write Cycle Time
        # 1 byte   : I2C MUX Bus Selector
        # N bytes  : I2C MUX path in string form

        d = dict()
        subd = dict()
        i = 0
        op = data[i]
        i += 1

        # Keep this check in sync with DeviceFW::OperationType values
        # in src/include/usr/devicefw/driverif.H
        if op == 0:
            subd['EEPROM']='Read'
        elif op == 1:
            subd['EEPROM']='Write'
        else:
            subd['EEPROM']='Unknown'

        subd['Op Type Value'], i=memConcat(data, i, i+1)

        if ver >= 4:
            opMethod = data[i]
            i += 1
            if opMethod == 1:
                subd['EEPROM Access: I2C']=f'{opMethod:02x}'
            elif opMethod == 0:
                subd['EEPROM Access: SPI']=f'{opMethod:02x}'
            else:
                subd['EEPROM Access: Unknown']=f'{opMethod:02x}'

        subd['Target HUID'], i=memConcat(data, i, i+4)
        subd['Length I/O Buff'], i=memConcat(data, i, i+8)
        subd['Chip'], i=memConcat(data, i, i+8)
        subd['Offset'], i=memConcat(data, i, i+8)
        subd['Port'], i=memConcat(data, i, i+8)
        subd['Engine'], i=memConcat(data, i, i+8)
        subd['Device Address'], i=memConcat(data, i, i+8)
        subd['Address Size'], i=memConcat(data, i, i+1)
        subd['Write Page Size'], i=memConcat(data, i, i+8)
        subd['Device Size (in KB)'], i=memConcat(data, i, i+8)

        if ver >= 2:
            subd['Chip Count'], i=memConcat(data, i, i+8)

        subd['Write Cycle Time'], i=memConcat(data, i, i+8)

        if ver >= 3:
            subd['I2C Mux Selector'], i=memConcat(data, i, i+1)

        # find index of null character
        indx = findNull(data, i, len(data))
        subd['I2C Mux Path'], i=strConcat(data, i, indx)

        d['EEPROM Parameters']=subd

        jsonStr = json.dumps(d)
        return jsonStr

    #EEPROM Parameters
    def UdParserEepromSpiParms(subType, ver, data):
        # ***** Memory Layout *****
        # 1 byte   : Op Type (DeviceFW::OperationType)
        # 1 byte   : Eeprom access method
        # 4 bytes  : Target HUID
        # 8 bytes  : Length of In/Out Buffer
        # 8 bytes  : eepromRole
        # 8 bytes  : Offset
        # 8 bytes  : devSize KB
        # 8 bytes  : roleOffset KB
        # 1 byte   : SPI engine
        # N bytes  : SPI master path
        # Cache the SPI path in string form for reference and easy access

        d = dict()
        subd = dict()
        i = 0
        op = data[i]
        i += 1

        # Keep this check in sync with DeviceFW::OperationType values
        # in src/include/usr/devicefw/driverif.H
        if op == 0:
            subd['EEPROM']='Read'
        elif op == 1:
            subd['EEPROM']='Write'
        else:
            subd['EEPROM']='Unknown'

        subd['Target HUID'], i=memConcat(data, i, i+4)
        subd['Length I/O Buff'], i=memConcat(data, i, i+8)
        subd['eepromRole'], i=memConcat(data, i, i+8)
        subd['Device Size (in KB)'], i=memConcat(data, i, i+8)
        subd['Start of Device Data (in KB)'], i=memConcat(data, i, i+8)
        subd['SPI Engine'], i=memConcat(data, i, i+8)

        #find index of null character
        indx = findNull(data, i, len(data))
        subd['SPI Master Path'], i=strConcat(data, i, indx)

        d['EEPROM Parameters']=subd

        jsonStr = json.dumps(d)
        return jsonStr

#Dictionary with parser functions for each subtype
#Values are from UserDetailsTypes enum in src/include/usr/eeprom/eepromddreasoncodes.H
UserDetailsTypes = { 1: "UdParserEepromI2cParms",
                     2: "UdParserEepromSpiParms" }

def parseUDToJson(subType, ver, data):
    args = (subType, ver, data)
    return getattr(errludP_eeprom, UserDetailsTypes[subType])(*args)
