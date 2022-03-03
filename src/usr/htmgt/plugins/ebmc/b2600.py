# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/htmgt/plugins/ebmc/b2600.py $
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
from udparsers.helpers.errludP_Helpers import hexConcat, memConcat, intConcat, hexDump

# ###################################################
# Used to convert attention types to readable string
# ###################################################
def occCmdToStr(i_type):

    cmdTypes = { "00": "POLL",
                  "12": "CLEAR_ELOG",
                  "20": "SET_MODE_AND_STATE",
                  "21": "SET_CONFIG_DATA",
                  "22": "SET_POWER_CAP",
                  "25": "RESET_PREP",
                  "30": "SEND_AMBIENT",
                  "40": "DEBUG_PASSTHROUGH",
                  "41": "AME_PASSTHROUGH",
                  "42": "GET_FIELD_DEBUG_DATA",
                  "53": "MFG_TEST" }

    cmdTypeStr = "Unknown " + i_type

    if i_type.lower() in cmdTypes:
        cmdTypeStr = "0x" + i_type + " " + cmdTypes[i_type.lower()]

    return cmdTypeStr


class errludP_htmgt:
    def UdParserHtmgtData(ver, data):
        # ***** Memory Layout *****
        # 1 bytes   : Number of OCCs
        # 1 bytes   : Master Instance
        # 1 bytes   : State
        # 1 bytes   : Target State
        # 1 bytes   : System Reset Count
        # 1 bytes   : Cumulative Resets
        # 1 bytes   : Mode
        # 1 bytes   : In Safe Mode?
        # 4 bytes   : Safe Mode Return Code
        # 4 bytes   : Safe Mode OCC Instance
        # Data for each OCC
        # 1 bytes   : Instance
        # 1 bytes   : State
        # 1 bytes   : Role
        # 1 bytes   : Master Capable?
        # 1 bytes   : Comm Established?
        # 1 bytes   : Mode
        # 2 bytes   : Reserved
        # 1 bytes   : Failed?
        # 1 bytes   : Needs Reset?
        # 1 bytes   : Reset Reason
        # 1 bytes   : Reset Count WOF | Reset Count
        # 4 bytes   : Last Poll Header

        d = dict()
        subd = dict()
        i = 0

        numOccs = data[i]
        i += 1
        subd['Number of OCCs']=numOccs
        subd['Master OCC']=data[i]
        i += 1
        subd['State'], i=hexConcat(data, i, i+1)
        subd['Target State'], i=hexConcat(data, i, i+1)
        subd['HTMGT triggered resets']=data[i]
        i += 1
        subd['Resets since power on']=data[i]
        i += 1
        subd['Mode'], i=hexConcat(data, i, i+1)

        #Don't display if not in safe mode because the flag may not be
        #set at the time this data is added to an error log
        if data[i]:
            subd['In Safe Mode']=bool(data[i])
            i += 1
            subd['Safe Reason Code'], i=hexConcat(data, i, i+4)
            subd['Safe OCC Instance'], i=intConcat(data, i, i+4)
        else:
            #skip over this data since not in safe mode
            i += 9

        d['HTMGT']= subd

        for x in range(numOccs):
            subd2 = dict()
            occName = 'OCC' + str(data[i])
            subd2['Instance']=data[i]
            i += 1
            subd2['State'], i=hexConcat(data, i, i+1)
            subd2['Role'], i=hexConcat(data, i, i+1)
            subd2['Master Capable']=bool(data[i])
            i += 1
            subd2['Comm Established']=bool(data[i])
            i += 1
            subd2['Mode'], i=hexConcat(data, i, i+1)
            subd2['reserved'], i=hexConcat(data, i, i+2)
            subd2['Failed']=bool(data[i])
            i += 1
            subd2['Needs Reset']=bool(data[i])
            i += 1
            subd2['Reset Reason'], i=hexConcat(data, i, i+1)

            resetCounts = f'{data[i]:02x}'
            subd2['Reset Count']=int(resetCounts[1], 16)
            subd2['WOF Reset Count']=int(resetCounts[0], 16)
            i += 1

            # Keep values in this check in sync with
            # check in src/usr/htmgt/plugins/errludP_htmgt.H
            status, _= intConcat(data, i, i+2)
            if (status & 0x0ff) != 0:
                statusString, i= hexConcat(data, i, i+4)
                statusString += " -"
                if (status & 0x0080):
                    statusString += " Throttle-ProcOverTemp"
                if (status & 0x0040):
                    statusString += " Throttle-Power"
                if (status & 0x0020):
                    statusString += " MemThrot-OverTemp"
                if (status & 0x0010):
                    statusString += " QuickPowerDrop"
                if (status & 0x0008):
                    statusString +=  " Throttle-VddOverTemp"
                subd2['Last Poll Header']=statusString
            else:
                subd2['Last Poll Header'], i=hexConcat(data, i, i+4)

            d[occName]=subd2

        jsonStr = json.dumps(d, indent = 2)
        return jsonStr

    def UdParserOCCCmd(ver, data):
        d = dict()
        subd = dict()
        i = 0
        #numOccs = data[i]
        #i += 1
        subd['Sequence'], i=hexConcat(data, i, i+1)
        cmd, i=memConcat(data, i, i+1)
        subd['OCC Command String'] = occCmdToStr(cmd)
        subd['Data Length'], i=hexConcat(data, i, i+2)
        while i < len(data):
            subd['0x%0*X'%(4,i)], i=hexConcat(data, i, i+16)

        d['OCC Command']=subd
        jsonStr = json.dumps(d, indent = 2)
        return jsonStr


    def UdParserOCCRsp(ver, data):
        d = dict()
        subd = dict()
        i = 0
        #numOccs = data[i]
        #i += 1
        subd['Sequence'], i=hexConcat(data, i, i+1)
        cmd, i=memConcat(data, i, i+1)
        subd['OCC Command String'] = occCmdToStr(cmd)
        subd['Rsp Status'], i=hexConcat(data, i, i+1)
        subd['Data Length'], i=hexConcat(data, i, i+2)
        if (cmd == 0):
            status, _= intConcat(data, i, i+2)
            if (status & 0x00ff) != 0:
                statusString, i= hexConcat(data, i, i+2)
                statusString += " -"
                if (status & 0x0080):
                    statusString += " Throttle-ProcOverTemp"
                if (status & 0x0040):
                    statusString += " Throttle-Power"
                if (status & 0x0020):
                    statusString += " MemThrot-OverTemp"
                if (status & 0x0010):
                    statusString += " QuickPowerDrop"
                if (status & 0x0008):
                    statusString +=  " Throttle-VddOverTemp"
                subd['Status']=statusString
            else:
                subd['Status'], i=hexConcat(data, i, i+2)
        while i < len(data):
            subd['0x%0*X'%(4,i)], i=hexConcat(data, i, i+16)

        d['OCC Response']=subd
        jsonStr = json.dumps(d, indent = 2)
        return jsonStr


#Dictionary with parser functions for each subtype
#Values are from tmgtElogSubsecTypes in src/usr/htmgt/htmgt_utility.H
tmgtElogSubsecTypes = {
        13: "UdParserOCCCmd",
        14: "UdParserOCCRsp",
        16: "UdParserHtmgtData"
        }

def parseUDToJson(subType, ver, data):
    args = (ver, data)
    return getattr(errludP_htmgt, tmgtElogSubsecTypes[subType])(*args)

if __name__ == "__main__":
    f = open("test2/htmgtUD", "rb").read()
    mv = memoryview(f)
    print(parseUDToJson(16, 1, mv))
