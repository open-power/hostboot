#!/usr/bin/env python3
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p10/procedures/ppe/fw_tools/udparsers/b2f00/b2f00.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2023,2024
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
import sys
import os

from udparsers.helpers.miscUtils import getLid
from udparsers.helpers.hostfw_trace import get_binary_trace_data_as_string
import  udparsers.b2900.pmPpe2fsp

#PARSER Version
parserVersion = 1.0
XGPE_STRING_LID_FILE = "81e00690.lid"
ERRL_BIN_XIR_SECT_VER_OFFSET = 153
ERRL_BIN_XIR_OFFSET = 160
ERRL_BIN_TRACE_SECTN  = 0x01
ERRL_BIN_XIR_SECTN  = 0x0b
PROC_VER_OFFSET = 116
ELOG_SIZE       = 2048
MAX_UD_SECTN = 2
elog_sectn_list = {  'XIR_REG' : 0x0b, 'TRACE_SECTN': 0x01 }

##############################################################################
# Function - Functions - Functions - Functions - Functions
##############################################################################

# @brief verifies the integrity of trace parser buffer
def checkForPpeTraceBuff():
    #buffer magic word
    bufferMagicWord = "xgpe_p10dd"
    bufferMagicWordHexCode = bytes(bufferMagicWord, 'utf-8')

    fBin = open( "/tmp/xgpe.bin", 'rb' )
    data_read = fBin.read()

    magicWordOffset = data_read.find( bufferMagicWordHexCode )
    if magicWordOffset != -1:
        fBin.seek( magicWordOffset - 4 )
        version = fBin.read(2)
        version = int.from_bytes( version, "big" )

        if version != 0x0002 :
            sys.exit( "Corrupt Trace File Buffer. Ver Read is " + str(version)  )
    else:
        sys.exit("XGPE Trace Buffer Not Found" )

    fBin.close()

    return magicWordOffset

# @brief    finds start of XGPE trace buffer
# @param    content of error log
def parseXgpeUserDataSection(data):

    with open( "/tmp/xgpe.bin", "wb" ) as xgpeTraceBinFile:
        xgpeTraceBinFile.write( data )
    magicWordOffset = checkForPpeTraceBuff()
    cmd = "dd skip=" + str(magicWordOffset - 4 ) + " count=" + str(2048) + " if=" + "/tmp/xgpe.bin " + " of=" + "/tmp/xgpeTrace.bin" + " bs=1 >/dev/null 2>&1"
    rc = os.system( cmd )
    if( rc ):
        print( "Failed To Extract XGPE Trace Section. RC : " + str( rc ) )

#----------------------------------------------------------------------------------------------------------------------

# @brief        parses XIR section of error log binary
# @param[in]    content of error log binary
def parsePpeRegSection( xgpeReg ):
    xgpeReg.seek( ERRL_BIN_XIR_OFFSET )
    xgpe_xir_val = "[\n"
    xgpe_xir_val += "XCR-CTR    :  " + '{:016x}'.format( int.from_bytes(xgpeReg.read( 8 ), byteorder='big' )) + "\n"
    xgpe_xir_val += "XSR-SPRG0  :  " + '{:016x}'.format( int.from_bytes(xgpeReg.read( 8 ), byteorder='big' )) + "\n"
    xgpe_xir_val += "IR-EDR     :  " + '{:016x}'.format( int.from_bytes(xgpeReg.read( 8 ), byteorder='big' )) + "\n"
    xgpe_xir_val += "XSR-IAR    :  " + '{:016x}'.format( int.from_bytes(xgpeReg.read( 8 ), byteorder='big' )) + "\n"
    xgpe_xir_val += "SRR0-LR    :  " + '{:016x}'.format( int.from_bytes(xgpeReg.read( 8 ), byteorder='big' )) + "\n"
    xgpe_xir_val += "]\n"
    xgpeReg.seek( 0 )
    return xgpe_xir_val

#----------------------------------------------------------------------------------------------------------------------

# @brief parses XGPE error log's user data section
# @param subType userdata section type
# @param ver     version of user data section
# @param data    content of uder data section
def parseUDToJson(subType, ver, data):
    traceDict = dict()
    xgpeReg = open( "/tmp/xgpe.bin", "wb" )
    xgpeReg.write(data)
    xgpeReg.close()
    xgpeReg = open( "/tmp/xgpe.bin", "rb" )

    #print( "Gen = " + chipGen + " " + '{:016x}'.format( procVer ) )
    size_parsed = ERRL_BIN_XIR_SECT_VER_OFFSET;
    l_sectn = 0;
    xgpe_xir_reg =""

    while size_parsed < ELOG_SIZE  and l_sectn < MAX_UD_SECTN :

        xgpeReg.seek( size_parsed )
        udType = int.from_bytes( xgpeReg.read( 1 ), byteorder='big' )
        udSize = int.from_bytes( xgpeReg.read( 2 ), byteorder='big' )
        udSize += 8
        size_parsed += udSize

        if udType == elog_sectn_list.get( "XIR_REG" ) :
            xgpe_xir_reg = parsePpeRegSection( xgpeReg )
            traceDict["XIRs"] = xgpe_xir_reg.split( "\n" )

        if udType == elog_sectn_list.get( "TRACE_SECTN" ) :
            parseXgpeUserDataSection( data )
            #Execute pmPpe2fsp tool to convert ppe trace to fsp trace.
            #This provide the right path to the tool as per BMC env
            ppeFormatFile = "/tmp/xgpeTrace.bin"
            fspFormatFile = "/tmp/xgpeTrace_fsp.bin"
            udparsers.b2900.pmPpe2fsp.get_pm_trace_data_as_string(ppeFormatFile, fspFormatFile)

            with open( fspFormatFile, 'rb' ) as fspFormat:
                readData = fspFormat.read()

            traceStringFile = getLid(XGPE_STRING_LID_FILE)
            print( traceStringFile )

            if traceStringFile == "":
                traceDict["File not found"] = XGPE_STRING_LID_FILE
                traceStr = json.dumps(traceDict)
                return traceStr

            startPos = 0
            numTraces = -1
            ( retVal, traceDataString, warningMessages ) = udparsers.helpers.hostfw_trace.get_binary_trace_data_as_string( readData, startPos, numTraces, traceStringFile )

            traceDict["XGPE Traces" ]  = traceDataString.split( "\n" )


    traceStr = json.dumps( traceDict, indent = 4, sort_keys=True )

    if os.path.exists( "/tmp/xgpeTrace_fsp.bin" ) :
        os.remove( "/tmp/xgpeTrace_fsp.bin" )
    if os.path.exists( "/tmp/xgpeTrace.bin" ):
        os.remove( "/tmp/xgpeTrace.bin" )
    if os.path.exists( "/tmp/xgpe.bin" ):
        os.remove( "/tmp/xgpe.bin" )

    return traceStr
