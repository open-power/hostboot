# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/htmgt/plugins/ebmc/b2a00.py $
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
import os.path
import struct

from udparsers.helpers.errludP_Helpers import hexConcat, memConcat, intConcat, hexDump

OCC_STRING_LID_FILE = "81e00687.lid"

####################################################
# Used to convert data to readable string
####################################################
occStateList = { "01": "STANDBY",
                 "02": "OBSERVATION",
                 "03": "ACTIVE",
                 "04": "SAFE",
                 "05": "CHARACTERIZATION" }
occRoleList = { "00": "SLAVE",
                "01": "MASTER" }
occModeList = { "01": "STATIC",
                "03": "STATICFREQPOINT",
                "04": "SAFE",
                "05": "POWERSAVER",
                "09": "MAXFREQUENCY",
                "0b": "FIXEDFREQUENCY",
                "0c": "MAXPERFORMANCE" }
occUdTypeList = { "01": "TRACE",
                  "02": "CALLHOME",
                  "03": "BINARY",
                  "04": "HISTORY",
                  "05": "WOF" ,
                  "06": "PGPE PK TRACE" ,
                  "07": "PGPE" }
calloutPriorityList = { "01": "LOW",
                        "02": "MEDIUM",
                        "03": "HIGH" }
calloutTypeList = { "01": "HUID",
                    "02": "COMPONENT",
                    "03": "GPU ID" }

def dataToString(list, value):
    if (value.lower() in list):
        dataString = "0x" + value + " " + list[value.lower()]
    else:
        dataString = "0x" + value + " unknown"
    return dataString


class errludP_occ:

    # Print Call Home Sensor Data
    def printSensor(head, data, i):
        scur,i = memConcat(data, i, i+2)
        smin,i = memConcat(data, i, i+2)
        smax,i = memConcat(data, i, i+2)
        savg,i = memConcat(data, i, i+2)
        saccum,i = memConcat(data, i, i+4)
        if head == "":
            head="sensor"
        line="  "+head.ljust(20)+": Sample:["+str(int(scur,16)).rjust(5)+ \
             "] Avg:["+str(int(savg,16)).rjust(5)+ \
             "] Min:["+str(int(smin,16)).rjust(5)+ \
             "] Max:["+str(int(smax,16)).rjust(5)+"]"

        return i, line


    # Parse call home data
    def parseCallhome(data, i):
        lines = []  # stores the parsed data to be returned
        divider = "-------------------------------------------------------------------------------";
        eye,i = memConcat(data, i, i+4)
        eyeArray = bytearray.fromhex(eye)
        lines.append("Eyecatcher: 0x"+str(eye)+" '"+eyeArray.decode()+"'")
        version = data[i]
        lines.append("Version: "+str(hex(version)))
        i += 1
        lines.append("Current Power Mode: "+dataToString(occModeList,str(hex(data[i])[2:]).zfill(2)))
        i += 1
        value,i = memConcat(data, i, i+4)
        lines.append("Total Time (seconds): "+str(int(value,16)))
        nummodes = data[i]
        i += 1
        lines.append("Modes in Log: "+str(nummodes))
        if nummodes > 2:
            lines.append("Invalid number of modes (using 2)")
            nummodes = 2

        if version != 16:
            lines.append("Unsupported Call Home Version")
            i -= 11
            return i, lines

        funcIdOffset = i
        i += 16
        value,i = memConcat(data, i, i+2)
        lines.append("Num Sensors: "+str(int(value,16)))
        lines.append("Slave Error History Counts:")
        for occ in range(0,7):
            histString=""
            for entry in range(0,4):
                i += 2
                histString += str(" {:02x}".format(data[i])) + str("{:02x}".format(data[i+1]))
            lines.append("Slave "+str(occ+1)+" ERRHIST Counts:["+histString+" ]")
        lines.append("Slave Frequency Clip History:")
        for occ in range(0,7):
            value,i = memConcat(data, i, i+4)
            lines.append("Slave "+str(occ+1)+":["+str(value)+"]")
        ddsMinOffset = i
        i += 8;
        for occ in range(0,8):
            ### DEBUG:
            #value  = (data[i]<<24) + (data[i+1]<<16) + (data[i+2]<<8) + data[i+3]
            #lines.append("ocsDirtyTypeAct DEBUG: i="+str(i)+" data: "+"0x{:08x}".format(value))
            if 1 == 0:
                ### NOT WORKING:
                value,i = memConcat(data, i, i+4)
            else:
                value = (data[i]<<24) + (data[i+1]<<16) + (data[i+2]<<8) + data[i+3]
                i += 4
            lines.append("ocsDirtyTypeAct["+str(occ)+"]:["+str("0x{:08x}".format(value))+"]")
        for occ in range(0,8):
            value = (data[i]<<24) + (data[i+1]<<16) + (data[i+2]<<8) + data[i+3]
            lines.append("ocsDirtyTypeHold["+str(occ)+"]:["+str("0x{:08x}".format(value))+"]")
            i += 4

        for m in range(0,nummodes):
            lines.append(divider);
            mode = hex(data[i])[2:].zfill(2)
            i += 1
            value,i = memConcat(data, i, i+4)
            if m == 0:
                lines.append("Current Mode: "+dataToString(occModeList,mode)+" ("+str(int(value,16))+" samples)")
            else:
                lines.append("Previous Mode: "+dataToString(occModeList,mode)+" ("+str(int(value,16))+" samples)")
            lines.append(divider);
            lines.append("Total System Power:")
            i, line = errludP_occ.printSensor("CHOMPWR", data, i)
            lines.append(line)
            lines.append("APSS Channels:")
            for s in range(0,16):
                i, line = errludP_occ.printSensor("CHOMPWRAPSSCH"+str(s).zfill(2)+ \
                        " FID:["+str(data[funcIdOffset+s]).rjust(2)+"] ", data, i)
                lines.append(line)
            lines.append("Processor Frequency:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMFREQP"+str(s), data, i)
                lines.append(line)
            lines.append("Processor Utilization:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMUTILP"+str(s), data, i)
                lines.append(line)
            lines.append("Processor Temps:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMTEMPPROC"+str(s), data, i)
                lines.append(line)
            lines.append("Processor IO Temps:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMTEMPIOP"+str(s), data, i)
                lines.append(line)
            lines.append("Membuff Temps:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMTEMPMEMBUFP"+str(s), data, i)
                lines.append(line)
            lines.append("DIMM Temps:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMTEMPDIMMP"+str(s), data, i)
                lines.append(line)
            lines.append("MC/DRAM Temps:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMTEMPMCDIMMP"+str(s), data, i)
                lines.append(line)
            lines.append("PMIC Temps:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMTEMPPMICP"+str(s), data, i)
                lines.append(line)
            lines.append("Exernal Membuf Temps:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMTEMPMCEXTP"+str(s), data, i)
                lines.append(line)
            lines.append("VRM VDD Temps:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMTEMPVDDP"+str(s), data, i)
                lines.append(line)
            lines.append("Instructions per Second:")
            ### DEBUG:
            #value  = (data[i]<<24) + (data[i+1]<<16) + (data[i+2]<<8) + data[i+3]
            #value2 = (data[i+4]<<24) + (data[i+5]<<16) + (data[i+6]<<8) + data[i+7]
            #value3 = (data[i+8]<<24) + (data[i+9]<<16) + (data[i+10]<<8) + data[i+11]
            #lines.append("CHOMIPS DEBUG: i="+str(i)+" data: "+"0x{:08x}".format(value)+" "+ \
            #        "0x{:08x}".format(value2)+" "+"0x{:08x}".format(value3))
            if m == 1:
                ### NOT WORKING RIGHT
                if 1 == 0:
                    ### WHY DOESNT THIS WORK????
                    i, line = errludP_occ.printSensor("CHOMIPS**", data, i)
                elif 1 == 1:
                    i += 2 ### THIS MAKES IT WORK!!! (any increment from 1-5...) BUT OFF AFTER THIS POINT
                    i, line = errludP_occ.printSensor("CHOMIPS**", data, i)
                else:
                    ### THIS ALSO DOES NOT - TRYING TO DEBUG
                    saccum = 0
                    scur = (data[i]<<8) + data[i+1]
                    i += 2
                    smin = (data[i]<<8) + data[i+1]
                    i += 2
                    smax = (data[i]<<8) + data[i+1]
                    i += 2
                    savg = (data[i]<<8) + data[i+1]
                    i += 2
                    i += 3
                    lines.append("i="+str(i))
                    break
                    lines.append("i="+str(i)+"cur="+str(cur))
                    lines.append("i="+str(i)+"cur="+str(cur)+", min="+str(min))
                    i += 1
                    #smin = (data[i+2]<<8) + data[i+3]
                    #smax = (data[i+4]<<8) + data[i+5]
                    #savg = (data[i+6]<<8) + data[i+7]
                    #i += 12
                    line="  CHOMIPS****: Sample:["+str(int(scur,16)).rjust(5)+ \
                        "] Avg:["+str(int(savg,16)).rjust(5)+ \
                        "] Min["+str(int(smin,16)).rjust(5)+ \
                        "] Max["+str(int(smax,16)).rjust(5)+"] acc["+str(saccum)+"]"
            else:
                i, line = errludP_occ.printSensor("CHOMIPS", data, i)
            lines.append(line)
            lines.append("Memory Bandwidth:")
            for p in range(0,8):
                for s in range(0,16):
                    i, line = errludP_occ.printSensor("CHOMBWP"+str(p)+"M"+str(s).zfill(2), data, i)
                    lines.append(line)
            lines.append("Digital Droop Sensors:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMDDSAVGP"+str(s), data, i)
                lines.append(line)
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMDDSMINP"+str(s), data, i)
                line += " Core:["+str(data[ddsMinOffset+s])+"]"
                lines.append(line)
            lines.append("Vdd Current (0.01A):")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMCURVDDP"+str(s), data, i)
                lines.append(line)
            lines.append("Vdd Ceff ratio (0.01 percent):")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMCEFFRATIOVDDP"+str(s), data, i)
                lines.append(line)
            lines.append("Under volting sensors (0.1 percent):")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMUVAVGP"+str(s), data, i)
                lines.append(line)
            lines.append("Over volting sensors (0.1 percent):")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMOVAVGP"+str(s), data, i)
                lines.append(line)
            lines.append("Power Vdd:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMPWRVDDP"+str(s), data, i)
                lines.append(line)
            lines.append("Power Vcs:")
            for s in range(0,8):
                i, line = errludP_occ.printSensor("CHOMPWRVCSP"+str(s), data, i)
                lines.append(line)

        return i, lines


    # Parse OCC Trace data
    def parseTrace(tracedata, i):
        # Import the API that will be used to take the data and parse it out
        from udparsers.helpers.hostfw_trace import get_binary_trace_data_as_string
        from udparsers.helpers.hostfw_trace import BUFFER_EMPTY_STRING
        from udparsers.helpers.miscUtils import getLid

        lines = []  # stores the parsed data to be returned
        parsed = 0

        # Get the LID file for the HB string file
        stringFile = getLid(OCC_STRING_LID_FILE)
        if stringFile == "":
            lines.append("OCC String Lid: "+OCC_STRING_LID_FILE)
            lines.append("Lid not found - Unable to parse trace")
        else:
            lines.append("occStringFile: "+stringFile)
            lines.append("TRACE Version: "+str(tracedata[i]))
            buffSize, _= intConcat(tracedata, i+20, i+24)
            endOffset, _= intConcat(tracedata, i+28, i+32)
            lines.append("TRACE BufferSize: "+str(buffSize)+", EndOffset: "+str(endOffset))

            startingPosition = 0 # start at the version info
            printNumberOfTraces = -1 # -1 means to get all traces
            retVal, traceDataString, warningMessages = get_binary_trace_data_as_string(tracedata,
                                                startingPosition, printNumberOfTraces, stringFile)

            # If the data string ends with a newline, "\n", then remove it.
            # Removing the newline sets up the data string for the split
            # function below to not have an empty line at the end
            if traceDataString[-1] == "\n":
                traceDataString = traceDataString[:-1]

            # Split the data string into a list for "pretty printing"
            traces = traceDataString.split("\n")

            # If an error with parsing the binary data then return the
            # errors encountered
            if retVal != 0:
                lines.append("TRACE Errors:")
                for l in traces:
                    lines.append(l)
            else:
                if (len(warningMessages)):
                    # Remove newline at end of string if it exists
                    if warningMessages[-1] == "\n":
                        warningMessages = warningMessages[:-1]
                    warnings = warningMessages.split("\n")
                    lines.append("TRACE Warnings:")
                    for w in warnings:
                        lines.append(w)

                if traces[-1] == BUFFER_EMPTY_STRING:
                    lines.append("TRACE Data Empty: Data has no parseable traces")
                else:
                    for l in traces:
                        lines.append(l)
                    i += buffSize
                    parsed = 1

        return lines, i


    # Parse OCC Error logs
    def UdParserOccFfdc(ver, data):
        d = dict()
        errhdr = dict()
        i = 0
        errhdr['Checksum'], i=hexConcat(data, i, i+2)
        errhdr['Version'], i=hexConcat(data, i, i+1)
        errhdr['Error Log Id'], i=hexConcat(data, i, i+1)
        errhdr['Reason Code'], i=hexConcat(data, i, i+1)
        errhdr['Severity'], i=hexConcat(data, i, i+1)
        errhdr['Actions'], i=hexConcat(data, i, i+1)
        maxCallouts, _= intConcat(data, i, i+1)
        errhdr['Max Callouts'], i=hexConcat(data, i, i+1)
        errhdr['Extended RC'], i=hexConcat(data, i, i+2)
        errhdr['Max Elog Size'], i=hexConcat(data, i, i+2)
        errhdr['Reserved'], i=hexConcat(data, i, i+4)
        d['OCC Error Header']=errhdr

        # Parse OCC Callouts
        errco = dict()
        j = 0
        while j < maxCallouts:
            callstring = 'Callout['+str(j)+']'
            valid = 0
            for c in range(i, i+16):
                if data[c] != 0:
                    valid = 1
                    break
            if valid:
                errco[callstring], i=hexConcat(data, i, i+8)
                value, i=memConcat(data, i, i+1)
                errco[callstring+' Type'] = dataToString(calloutTypeList, value)
                value, i=memConcat(data, i, i+1)
                errco[callstring+' Priority'] = dataToString(calloutPriorityList, value)
                errco[callstring+' Reserved'], i=hexConcat(data, i, i+6)
            else:
                errco[callstring]="empty"
                i += 16
            j += 1
        d['OCC Error Callouts']=errco

        erruhdr = dict()
        erruhdr['Version'], i=hexConcat(data, i, i+1)
        erruhdr['Reserved'], i=hexConcat(data, i, i+1)
        erruhdr['Module Id'], i=hexConcat(data, i, i+2)
        erruhdr['FClip History'], i=hexConcat(data, i, i+4)
        erruhdr['TimeStamp'], i=hexConcat(data, i, i+8)
        erruhdr['OCC Id'], i=hexConcat(data, i, i+1)
        value, i=memConcat(data, i, i+1)
        erruhdr['Role'] = dataToString(occRoleList, value)
        value, i=memConcat(data, i, i+1)
        erruhdr['State'] = dataToString(occStateList, value)
        erruhdr['Committed'], i=hexConcat(data, i, i+1)
        erruhdr['User Data 1'], i=hexConcat(data, i, i+4)
        erruhdr['User Data 2'], i=hexConcat(data, i, i+4)
        erruhdr['User Data 3'], i=hexConcat(data, i, i+4)
        erruhdr['Total Log Size'], i=hexConcat(data, i, i+2)
        erruhdr['User Details Size'], i=hexConcat(data, i, i+2)
        erruhdr['Reserved2'], i=hexConcat(data, i, i+4)
        d['OCC Error User Details Header']=erruhdr

        # Parse the OCC user details sections
        errud = {}
        j = 0
        while i < len(data):
            errud[j] = dict()
            udstring='UserDetail['+str(j)+']'
            udVersion, _= intConcat(data, i, i+1)
            errud[j]['Version'], i=hexConcat(data, i, i+1)
            udType, i=memConcat(data, i, i+1)
            errud[j]['Type'] = dataToString(occUdTypeList, udType)
            udSize, _= intConcat(data, i, i+2)
            errud[j]['Size'], i=hexConcat(data, i, i+2)
            errud[j]['reserved'], i=hexConcat(data, i, i+4)
            endUd = i + udSize

            if udType == "01": # TRACE
                parsed = 0
                to = 0
                tracedata = data[i:udSize]
                traceresults,to = errludP_occ.parseTrace(tracedata, to)
                i += to
                udSize -= to
                d['OCC TRACE'] = traceresults
                if udSize > 0:
                    to = 0
                    tracedata = data[i:udSize]
                    traceresults,to = errludP_occ.parseTrace(tracedata, to)
                    i += to
                    udSize -= to
                    d['OCC TRACE2'] = traceresults

            elif udType == "02": # CALLHOME
                chStart = i
                i,details = errludP_occ.parseCallhome(data, i)
                errud[j]['CALLHOME'] = details
                if i < chStart + udSize:
                    chend = dict()
                    chend['Extra data length']=hex(udSize-(i-chStart))
                    while i < chStart + udSize:
                        chend['0x%0*X'%(4,i-chStart)], i=hexConcat(data, i, i+16)
                    errud[j]['CALLHOME Extra data']=chend

            if endUd > len(data):
                errud[j]['DATA TRUNCATED']=hex(endUd-len(data))
                endUd = len(data)
            k = 0
            while i < endUd:
                errud[j]['0x%0*X'%(4,k)], i=hexConcat(data, i, i+16)
                k += 16
            d[udstring]=errud[j]
            j += 1

        # Dump remaining unparsed data (if any)
        if i < len(data):
            errend = dict()
            errend['remaining length']=len(data)
            while i < len(data):
                errend['0x%0*X'%(4,i)], i=hexConcat(data, i, i+16)
            d['OCC Error Extra']=errend

        jsonStr = json.dumps(d, indent = 2)
        return jsonStr


#Dictionary with parser functions for each subtype
occElogSubsecTypes = {
        0: "UdParserOccFfdc"
        }

def parseUDToJson(subType, ver, data):
    args = (ver, data)
    return getattr(errludP_occ, occElogSubsecTypes[subType])(*args)

if __name__ == "__main__":
    f = open("test2/htmgtUD", "rb").read()
    mv = memoryview(f)
    print(parseUDToJson(16, 1, mv))
