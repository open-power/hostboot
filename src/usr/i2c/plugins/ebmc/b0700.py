# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/i2c/plugins/ebmc/b0700.py $
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
from udparsers.helpers.errludP_Helpers import memConcat, findNull, strConcat

class errludP_i2c:
    #I2c Parameters
    def UdParserI2CParms(subType, ver, data):
        # ***** Memory Layout *****
        # 1 byte   : Op Type Description
        # 1 byte   : Op Type (DeviceFW::OperationType)
        # 4 bytes  : Target HUID
        # 8 bytes  : Length of In/Out Buffer
        # 8 bytes  : Access Type (DeviceFW::AccessType)
        # 1 byte   : Port
        # 1 byte   : Engine
        # 8 bytes  : Device Address
        # 1 byte   : Flag: skip mode setup;
        # 1 byte   : Flag: with stop;
        # 1 byte   : Flag: read not write;
        # 8 bytes  : Bus Speed (kbits/sec)
        # 2 bytes  : Bit Rate Divisor
        # 8 bytes  : Polling Interval in ns
        # 8 bytes  : Timeout Count
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
            subd['I2C Operation']='Read'
        elif op == 1:
            subd['I2C Operation']='Write'
        else:
            subd['I2C Operation']='Unknown'

        subd['Op Type Value'], i=memConcat(data, i, i+1)
        subd['Target HUID'], i=memConcat(data, i, i+4)
        subd['Length I/O Buff'], i=memConcat(data, i, i+8)
        subd['Access Type'], i=memConcat(data, i, i+8)
        subd['Port'], i=memConcat(data, i, i+1)
        subd['Engine'], i=memConcat(data, i, i+1)
        subd['Device Address'], i=memConcat(data, i, i+8)
        subd['Flag: skip mode setup'], i=memConcat(data, i, i+1)
        subd['Flag: with stop'], i=memConcat(data, i, i+1)
        subd['Flag: read not write'], i=memConcat(data, i, i+1)
        subd['Bus Speed (kbits/sec)'], i=memConcat(data, i, i+8)
        subd['Bit Rate Divisor'], i=memConcat(data, i, i+2)
        subd['Polling Interval (ns)'], i=memConcat(data, i, i+8)
        subd['Timeout Count'], i=memConcat(data, i, i+8)

        if ver >= 2:
            subd['I2C Mux Selector'], i=memConcat(data, i, i+1)

        # find index of null character
        indx = findNull(data, i, len(data))
        subd['I2C Mux Path'], i=strConcat(data, i, indx)
        d['I2C Parameters']=subd

        jsonStr = json.dumps(d)
        return jsonStr

#Dictionary with parser functions for each subtype
#Values are from UserDetailsTypes in src/include/usr/i2c/i2creasoncodes.H
UserDetailsTypes = { 1: "UdParserI2CParms" }

def parseUDToJson(subType, ver, data):
    args = (subType, ver, data)
    return getattr(errludP_i2c, UserDetailsTypes[subType])(*args)
