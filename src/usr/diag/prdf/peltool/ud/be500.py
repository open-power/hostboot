# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/peltool/ud/be500.py $
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
from collections import OrderedDict

from udparsers.helpers.errludP_Helpers import hexConcat, intConcat, strConcat, memConcat
from pel.prd.parserdata import SignatureData, RegisterData

# ###################################################
# Used to convert attention types to readable string
# ###################################################


def attnTypeToStr(i_type):

    attnTypes = {"01": "SYSTEM_CS",
                 "02": "UNIT_CS",
                 "03": "RECOVERABLE",
                 "04": "SPECIAL",
                 "05": "HOST_ATTN"}

    attnTypeStr = "Unknown " + i_type

    if i_type.lower() in attnTypes:
        attnTypeStr = attnTypes[i_type.lower()]

    return attnTypeStr

# ###################################################
# Used to convert error log severity to a string
# ###################################################


def errlSevToStr(i_sev):

    errlSev = {"00": "INFORMATIONAL",
               "10": "RECOVERED",
               "20": "PREDICTIVE",
               "40": "UNRECOVERABLE"}

    errlSevStr = "Unknown " + i_sev

    if i_sev.lower() in errlSev:
        errlSevStr = errlSev[i_sev.lower()]

    return errlSevStr

# ###################################################
# Used to convert gard type to a string
# ###################################################


def gardTypeToStr(i_gardType):

    gardTypes = {"00": "NoGard",
                 "e6": "Predictive",
                 "e3": "Fatal"}

    gardTypeStr = "Unknown " + i_gardType

    if i_gardType.lower() in gardTypes:
        gardTypeStr = gardTypes[i_gardType.lower()]

    return gardTypeStr

# ###################################################
# Used to convert MRU priority type to a string
# ###################################################


def mruPriorityToStr(i_mruPriority):

    mruPriorities = {"00": "NONE",
                     "01": "LOW",
                     "02": "MED_C",
                     "03": "MED_B",
                     "04": "MED_A",
                     "05": "MED",
                     "06": "HIGH"}

    priorityStr = "Unknown " + i_mruPriority

    if i_mruPriority.lower() in mruPriorities:
        priorityStr = mruPriorities[i_mruPriority.lower()]

    return priorityStr


# ###################################################
# Used to convert MRU type to a string
# ###################################################

def mruTypeToStr(i_mruType):

    mruTypes = {"01": "HUID",
                "02": "MemoryMru",
                "03": "SymbolFru",
                "04": "PROCCLK0",
                "05": "PROCCLK1"}

    typeStr = "Unknown " + i_mruType

    if i_mruType.lower() in mruTypes:
        typeStr = mruTypes[i_mruType.lower()]

    return typeStr

# ###################################################
# Used to convert MRU special callouts to string
# ###################################################


def mruCalloutToStr(i_mruCallout):

    mruCallouts = {0x70: "CALLOUT_RANK",
                   0x71: "CALLOUT_ALL_MEM"}

    calloutStr = "Unknown " + hex(i_mruCallout)

    if i_mruCallout in mruCallouts:
        calloutStr = mruCallouts[i_mruCallout]

    return calloutStr

# ###################################################
# Used to convert an int UE type to string
# ###################################################


def ueTypeToStr(i_ueType):

    ueTypes = {1: "SCRUB_MPE",
               2: "FETCH_MPE",
               3: "SCRUB_UE",
               4: "FETCH_UE"}

    ueStr = "Unknown " + str(i_ueType)

    if i_ueType in ueTypes:
        ueStr = ueTypes[i_ueType]

    return ueStr

# ###################################################
# Used to convert a TOD topology int to string
# ###################################################


def todTopologyToStr(i_topology):

    topologies = {0: "No Error",
                  1: "Master Path Error",
                  2: "Internal Path Error",
                  3: "Slave Path Network Error",
                  4: "Unknown TOD Error"}

    todStr = "Unknown " + str(i_topology)

    if i_topology in topologies:
        todStr = topologies[i_topology]

    return todStr

# ###################################################
# Used to convert a Targeted Diagnostics Type to string
# ###################################################


def tdTypeToStr(i_tdType):

    # Note: This map should correspond to the 'TdType' enum defined in
    #       prdfMemTdQueue.H
    tdTypes = {0: "VCM",
               1: "RRD",
               2: "DSD",
               3: "TPS",
               0xf: "Invalid Event"}

    tdTypeStr = "Unknown " + str(i_tdType)

    if i_tdType in tdTypes:
        tdTypeStr = tdTypes[i_tdType]

    return tdTypeStr

# ###################################################
# Used to convert a symbol to its DQ value
# ###################################################


def symbol2Dq(symbol, dramSpared):

    dq = 80

    convertToDq = [39, 38, 37, 36, 35, 34, 33, 32,
                   79, 78, 77, 76, 71, 70, 69, 68,
                   63, 62, 61, 60, 55, 54, 53, 52,
                   31, 30, 29, 28, 23, 22, 21, 20,
                   15, 14, 13, 12,  7,  6,  5,  4,
                   75, 74, 73, 72, 67, 66, 65, 64,
                   59, 58, 57, 56, 51, 50, 49, 48,
                   27, 26, 25, 24, 19, 18, 17, 16,
                   11, 10,  9,  8,  3,  2,  1,  0]

    # convert the symbol to its equivalent dq
    if (symbol < 80):
        dq = convertToDq[symbol]

    # if the symbol is on a spare, convert the dq to its place on the spare
    if (1 == dramSpared):
        # The DRAM spare indexes are 72-79, so adjust the DQ to match
        dq = 72 + (dq % 8)

    return dq

# ###################################################
# Used to parse an input memory mru callout into the input dictionary
# ###################################################


def parseMemMruCallout(mruCallout, prefix, d, ver, dqMap=None):

    # We have a MemMRU, parse the 32 bits of the callout
    # autopep8: off
    valid      = (mruCallout >> 31) & 0x1
    procPos    = (mruCallout >> 28) & 0x7
    chnlPos    = (mruCallout >> 25) & 0x7
    omiPos     = (mruCallout >> 24) & 0x1
    pins       = (mruCallout >> 22) & 0x3
    nodePos    = (mruCallout >> 19) & 0x7
    prank      = (mruCallout >> 16) & 0x7
    dramSpared = (mruCallout >> 15) & 0x1
    symbol     = (mruCallout >>  8) & 0x7F
    eccSpared  = (mruCallout >>  7) & 0x1
    srank      = (mruCallout >>  4) & 0x7
    isOcmb     = (mruCallout >>  3) & 0x1
    # autopep8: on

    compPos = (chnlPos * 8) + omiPos

    if prefix not in d:
        d[prefix] = OrderedDict()

    d[prefix]['Node Pos'] = nodePos
    d[prefix]['Proc Pos'] = procPos
    d[prefix]['Component Pos'] = compPos
    d[prefix]['Primary Rank'] = prank
    d[prefix]['Secondary Rank'] = srank

    if (symbol >= 0x70):
        d[prefix]['Special Callout'] = mruCalloutToStr(symbol)
    else:
        dq = symbol2Dq(symbol, dramSpared)
        d[prefix]['Symbol'] = symbol
        d[prefix]['Pins'] = pins
        d[prefix]['Dram Spared'] = "Yes" if (dramSpared == 1) else "No"

        # Version 2 and above: translate the DQ to DIMM format if a dqMap was
        # provided.
        if (2 <= ver):
            if dqMap is not None and dramSpared == 0:
                for dimmDq, c4Dq in dqMap.items():
                    if c4Dq == dq:
                        dq = dimmDq

        d[prefix]['DQ'] = dq

# ###################################################
# Used to hash strings to get capture data IDs
# ###################################################


def hashString(string):

    # This hash is a simple "n*s[0] + (n-1)*s[1] + ... + s[n-1]" algorithm,
    # where s[i] is a two byte chunk of the input string. It is currently
    # intended to return a 16-bit hash of the input string.

    sumA = 0
    sumB = 0
    pos = 0  # to keep track of the byte position
    val = 0

    for char in string:
        val <<= 8
        val |= ord(char)
        pos += 1

        # update sum at two byte chunk
        if (2 == pos):
            pos = 0
            sumA += val
            sumB += sumA
            val = 0
    while (2 != pos):
        val <<= 8
        pos += 1

    # The sum is added to the hash value an additional time here despite the
    # defined behavior specified above to keep consistent with the behavior of
    # the hashString function in the PRD project.
    sumA += val
    sumB += sumA
    val = 0

    # return the 16-bit hash
    hexValue = '0x%04x' % (sumB & 0xFFFF)
    return hexValue

# ###################################################
# Used to decompress the capture data buffer
# ###################################################


def uncompressCdBuffer(i_buf):

    # index to keep track of our position in our input buffer
    i = 0

    # Keep track of the size and position of our look behind buffer
    lbPos = 0
    lbSize = 0

    # temporary string variable that will be used to store our hex string buffer
    # which will be converted to a memory view and returned
    tempBuf = bytearray()

    # get the size of the input buffer
    inSize = len(i_buf)

    # max size of output buffer, will be decremented to keep track of size left
    maxSize = 2052

    # variables to store the byte compressed token bundle (tokC) and the token
    # position within the bundle (tokPos)
    tokPos = 8
    tokC = 0

    while ((inSize > 0) and (maxSize > 0)):

        # Check if we need to get a new bundle of tokens
        if (tokPos == 8):
            tokPos = 0
            tokC, i = intConcat(i_buf, i, i+1)
            inSize -= 1
            continue

        # Check if the token was compressed or not
        if ((tokC >> (7-tokPos)) & 0x1):
            # Check if the input buffer has tokens
            if (inSize < 2):
                # set exit condition
                inSize = 0
                continue

            # Compressed token
            # read token from stream
            token, i = intConcat(i_buf, i, i+2)
            inSize -= 2

            # get the postion and size within the look-behind buffer
            pos = (token & 0xFFC0) >> 6
            matchSize = (token & 0x3F) + 3

            # only take as much data as we can if we are out of room
            size = min(matchSize, maxSize)

            # convert our tempBuf into a memoryview we can parse as a
            # look-behind buffer
            lbBuf = memoryview(tempBuf)

            # get the uncompressed data from the look-behind buffer at the
            # position we got from the token
            match, tmp = memConcat(lbBuf, lbPos+pos, lbPos+pos+size)
            tempBa = tempBuf + bytearray.fromhex(match)
            tempBuf = tempBa

            # fix up all our sizes
            lbSize += matchSize
            maxSize -= size

        else:
            # uncompressed token, just copy the byte and adjust sizes
            string, i = memConcat(i_buf, i, i+1)
            tempBa = tempBuf + bytearray.fromhex(string)
            tempBuf = tempBa
            maxSize -= 1
            inSize -= 1
            lbSize += 1

        # just did a token, so increment the bundle count
        tokPos += 1

        # advance the look-behind buffer as needed
        while (lbSize >= 1024):
            lbPos += 1
            lbSize -= 1

    return memoryview(tempBuf)

# ###################################################


class errludP_prdf:

    def UdParserPrdfCapData(ver, data):

        d = OrderedDict()
        i = 0

        buf = data

        # version 2 and above are compressed
        if (2 <= ver):
            buf = uncompressCdBuffer(data)

        # First 4 bytes are the capture data size
        captureDataSize, i = intConcat(buf, i, i+4)

        # CaptureData Format:
        #        capture data -> ( <chip header> <registers> )*
        #        chip header -> ( <chip id:32> <# registers:32> )
        #        registers -> ( <reg id:16> <reg byte len:16> <bytes>+ )

        while True:

            # Check if we've reached the end based on the captured data size
            if (i >= captureDataSize):
                break

            # Get the next chip HUID if it exists in the buffer
            # HUID format (32 bits):
            #
            # SSSSNNNNTTTTTTTTiiiiiiiiiiiiiiii
            # S=System
            # N=Node Number
            # T=Target Type (matches TYPE attribute)
            # i=Instance/Sequence number of target, relative to node
            #
            intHuid, i = intConcat(buf, i, i+4)
            chipHuid = '0x' + format(intHuid, 'x').rjust(8, '0')

            # Check for an invalid chip ID, reached end of input (0xFFFFFFFF)
            if (0xFFFFFFFF == chipHuid):
                break

            # Get the number of IDs for this chip
            numIDs, i = intConcat(buf, i, i+4)

            cd = 'Capture Data'
            if cd not in d:
                d[cd] = OrderedDict()

            for x in range(numIDs):
                # Check if we've reached the end based on the captured data size
                if (i >= captureDataSize):
                    break

                dataId, i = memConcat(buf, i, i+2)
                dataLength, i = intConcat(buf, i, i+2)
                hexId = '0x' + dataId
                # check for special cases where the data we have isn't registers
                if (hexId == hashString("ATTN_DATA")):
                    attnData, i = hexConcat(buf, i, i+dataLength)
                    d[cd]['ATTN_DEBUG'] = attnData

                elif (hexId == hashString("MEM_UE_TABLE")):
                    # Keep track of the length of the data we've parsed
                    parsedLength = 0

                    # 7 bytes (56 bits) per entry:
                    # 8-bits:  count
                    # 4-bits:  type
                    # 4-bits:  reserved
                    # 3-bits:  primary rank
                    # 3-bits:  secondary rank
                    # 18-bits: row (r0:17)
                    # 5-bits:  bank
                    # 2-bits:  reserved
                    # 9-bits:  column (col0:8)
                    entries = int(dataLength / 7)

                    d[cd]['UE Table'] = OrderedDict()

                    for y in range(entries):
                        entryData, i = intConcat(buf, i, i+7)
                        parsedLength += 7

                        # autopep8: off
                        count     = (entryData >> 48) & 0xff
                        entryType = (entryData >> 44) & 0xf
                        reserved1 = (entryData >> 40) & 0xf
                        prank     = (entryData >> 37) & 0x7
                        srank     = (entryData >> 34) & 0x7
                        row       = (entryData >> 16) & 0x3ffff
                        bank      = (entryData >> 11) & 0x1F
                        reserved2 = (entryData >>  9) & 0x3
                        col       = entryData & 0x1ff
                        # autopep8: on

                        d[cd]['UE Table'][y] = OrderedDict()
                        d[cd]['UE Table'][y]['Count'] = count
                        d[cd]['UE Table'][y]['Type'] = ueTypeToStr(entryType)
                        d[cd]['UE Table'][y]['Primary Rank'] = hex(prank)
                        d[cd]['UE Table'][y]['Secondary Rank'] = hex(srank)
                        d[cd]['UE Table'][y]['Bank'] = hex(bank)
                        d[cd]['UE Table'][y]['Column'] = hex(col)
                        d[cd]['UE Table'][y]['Row'] = hex(row)

                    # Collect any extra junk data at the end just in case
                    junkLength = dataLength - parsedLength
                    if (junkLength >= 1):
                        junk, i = memConcat(buf, i, i+junkLength)

                elif (hexId == hashString("MEM_CE_TABLE")):
                    # Keep track of the length of the data we've parsed
                    parsedLength = 0

                    # Skip the first 8 bytes for the table's metadata
                    ceTableMetaData, i = memConcat(buf, i, i+8)
                    parsedLength += 8

                    # 9 bytes (72 bits) per entry:
                    # 8-bits:  count
                    # 5-bits:  reserved
                    # 1-bit:   isSpare
                    # 2-bits:  reserved
                    # 1-bit:   isHardCe
                    # 1-bit:   isActive
                    # 6-bits:  dram
                    # 8-bits:  dram pins
                    # 3-bits:  primary rank
                    # 3-bits:  secondary rank
                    # 18-bits: row (r0:17)
                    # 5-bits:  bank
                    # 2-bits:  reserved
                    # 9-bits:  column (col0:8)

                    # Calculate the number of entries (subtract 8 bytes for
                    # the metadata)
                    entries = int((dataLength-8) / 9)

                    d[cd]['CE Table'] = OrderedDict()

                    for y in range(entries):
                        entryData, i = intConcat(buf, i, i+9)
                        parsedLength += 9

                        # autopep8: off
                        count     = (entryData >> 64) & 0xff
                        reserved1 = (entryData >> 59) & 0x1f
                        isSp      = (entryData >> 58) & 0x1
                        reserved2 = (entryData >> 56) & 0x3
                        isHard    = (entryData >> 55) & 0x1
                        active    = (entryData >> 54) & 0x1
                        dram      = (entryData >> 48) & 0x3f
                        dramPins  = (entryData >> 40) & 0xff
                        prank     = (entryData >> 37) & 0x7
                        srank     = (entryData >> 34) & 0x7
                        row       = (entryData >> 16) & 0x3ffff
                        bank      = (entryData >> 11) & 0x1f
                        reserved3 = (entryData >>  9) & 0x3
                        col       = entryData & 0x1ff
                        # autopep8: on

                        cet = 'CE Table'
                        d[cd][cet][y] = OrderedDict()
                        d[cd][cet][y]['Count'] = count
                        d[cd][cet][y]['Primary Rank'] = prank
                        d[cd][cet][y]['Secondary Rank'] = srank
                        d[cd][cet][y]['Bank'] = hex(bank)
                        d[cd][cet][y]['Column'] = hex(col)
                        d[cd][cet][y]['Row'] = hex(row)
                        d[cd][cet][y]['Dram Pins'] = hex(dramPins)
                        d[cd][cet][y]['Dram'] = hex(dram)
                        d[cd][cet][y]['On Spare'] = 'Yes' if (
                            isSp == 1) else 'No'
                        d[cd][cet][y]['Hard CE'] = 'Yes' if (
                            isHard == 1) else 'No'
                        d[cd][cet][y]['Is Active'] = 'Yes' if (
                            active == 1) else 'No'

                    # Collect any extra junk data at the end just in case
                    junkLength = dataLength - parsedLength
                    if (junkLength >= 1):
                        junk, i = memConcat(buf, i, i+junkLength)

                elif (hexId == hashString("IUE_COUNTS")):
                    # Keep track of the length of the data we've parsed
                    parsedLength = 0

                    # 2 bytes (16 bits) per entry:
                    # 8-bits: rank
                    # 8-bits: count
                    entries = int(dataLength / 2)
                    d[cd]['IUE Counts'] = OrderedDict()

                    for y in range(entries):

                        rank, i = intConcat(buf, i, i+1)
                        count, i = intConcat(buf, i, i+1)
                        parsedLength += 2

                        # Continue to next entry if the count is 0
                        if (count == 0):
                            continue

                        d[cd]['IUE Counts'][y] = OrderedDict()
                        d[cd]['IUE Counts'][y]['Count'] = count
                        d[cd]['IUE Counts'][y]['Rank'] = rank

                    # Collect any extra junk data at the end just in case
                    junkLength = dataLength - parsedLength
                    if (junkLength >= 1):
                        junk, i = memConcat(buf, i, i+junkLength)

                elif (hexId == hashString("DRAM_REPAIRS_DATA")):

                    # Keep track of the length of the data we've parsed
                    parsedLength = 0

                    # 2 bytes (16 bits) in header:
                    # 4-bits: rank count
                    # 1-bit:  reserved
                    # 1-bit:  isSpareDram
                    # 2-bits: reserved
                    # 8-bits: wiring type
                    headerData, i = intConcat(buf, i, i+2)
                    parsedLength += 2

                    # autopep8: off
                    rankCount   = (headerData >> 12) & 0xf
                    reserved1   = (headerData >> 11) & 0x1
                    isSpareDram = (headerData >> 10) & 0x1
                    reserved2   = (headerData >>  8) & 0x3
                    wiringType  = headerData & 0xff
                    # autopep8: on

                    d[cd]['Dram Repairs Data'] = OrderedDict()

                    for y in range(rankCount):
                        # 5 bytes (40 bits) per entry:
                        # 8-bits: rank
                        # 8-bits: chip mark
                        # 8-bits: symbol mark
                        # 8-bits: spare0
                        # 8-bits: spare1
                        rank, i = intConcat(buf, i, i+1)
                        chipMark, i = intConcat(buf, i, i+1)
                        symbolMark, i = intConcat(buf, i, i+1)
                        spare0, i = intConcat(buf, i, i+1)
                        spare1, i = intConcat(buf, i, i+1)
                        parsedLength += 5

                        d[cd]['Dram Repairs Data'][y] = OrderedDict()
                        d[cd]['Dram Repairs Data'][y]['Rank'] = rank

                        cmStr = '--' if chipMark >= 72 else chipMark
                        d[cd]['Dram Repairs Data'][y]['Chip Mark'] = cmStr

                        smStr = '--' if symbolMark >= 72 else symbolMark
                        d[cd]['Dram Repairs Data'][y]['Symbol Mark'] = smStr

                        if (0 != isSpareDram):
                            sp0Str = '--' if spare0 >= 72 else spare0
                            d[cd]['Dram Repairs Data'][y]['Spare0'] = sp0Str

                            sp1Str = '--' if spare1 >= 72 else spare1
                            d[cd]['Dram Repairs Data'][y]['Spare1'] = sp1Str

                    # Collect any extra junk data at the end just in case
                    junkLength = dataLength - parsedLength
                    if (junkLength >= 1):
                        junk, i = memConcat(buf, i, i+junkLength)

                elif (hexId == hashString("DRAM_REPAIRS_VPD")):
                    # Keep track of the length of the data we've parsed
                    parsedLength = 0

                    # 12 bytes (96 bits) per entry:
                    # 1-byte:   rank
                    # 1-byte:   port
                    # 10-bytes: bad dq bitmap
                    entries = int(dataLength / 12)

                    d[cd]['Dram Repairs VPD'] = OrderedDict()

                    for y in range(entries):
                        rank, i = intConcat(buf, i, i+1)
                        port, i = intConcat(buf, i, i+1)
                        bitmap, i = intConcat(buf, i, i+10)
                        parsedLength += 12

                        d[cd]['Dram Repairs VPD'][y] = OrderedDict()
                        d[cd]['Dram Repairs VPD'][y]['Rank'] = rank
                        d[cd]['Dram Repairs VPD'][y]['Port'] = port

                        # Pad the bitmap with 0s to 20 hex characters (80 bits)
                        formatMap = '0x{0:0{1}x}'.format(bitmap, 20)
                        d[cd]['Dram Repairs VPD'][y]['Bitmap'] = formatMap

                    # Collect any extra junk data at the end just in case
                    junkLength = dataLength - parsedLength
                    if (junkLength >= 1):
                        junk, i = memConcat(buf, i, i+junkLength)

                elif (hexId == hashString("BAD_DQ_BITMAP")):
                    # Keep track of the length of the data we've parsed
                    parsedLength = 0

                    # One 12 byte entry:
                    # 1-byte:   rank
                    # 1-byte:   port
                    # 10-bytes: bad dq bitmap
                    rank, i = intConcat(buf, i, i+1)
                    port, i = intConcat(buf, i, i+1)
                    bitmap, i = intConcat(buf, i, i+10)
                    parsedLength += 12

                    d[cd]['Bad Dq Bitmap'] = OrderedDict()
                    d[cd]['Bad Dq Bitmap']['Rank'] = rank
                    d[cd]['Bad Dq Bitmap']['Port'] = port

                    formatMap = '0x{0:0{1}x}'.format(bitmap, 20)
                    d[cd]['Bad Dq Bitmap']['Bitmap'] = formatMap

                    # Collect any extra junk data at the end just in case
                    junkLength = dataLength - parsedLength
                    if (junkLength >= 1):
                        junk, i = memConcat(buf, i, i+junkLength)

                elif (hexId == hashString("ROW_REPAIR_VPD")):
                    # Keep track of the length of the data we've parsed
                    parsedLength = 0

                    # 6 bytes (48 bits) per entry:
                    # 8-bits:  rank
                    # 8-bits:  port
                    # 32-bits: row repair
                    entries = int(dataLength / 6)
                    d[cd]['Row Repair VPD'] = OrderedDict()

                    for y in range(entries):
                        rank, i = intConcat(buf, i, i+1)
                        port, i = intConcat(buf, i, i+1)
                        repair, i = hexConcat(buf, i, i+4)
                        parsedLength += 6

                        d[cd]['Row Repair VPD'][y] = OrderedDict()
                        d[cd]['Row Repair VPD'][y]['Rank'] = rank
                        d[cd]['Row Repair VPD'][y]['Port'] = port
                        d[cd]['Row Repair VPD'][y]['Repair'] = repair

                    # Collect any extra junk data at the end just in case
                    junkLength = dataLength - parsedLength
                    if (junkLength >= 1):
                        junk, i = memConcat(buf, i, i+junkLength)

                elif (hexId == hashString("TDCTLR_STATE_DATA_START") or
                      hexId == hashString("TDCTLR_STATE_DATA_END")):
                    #  Header (22 or 24 bits):
                    #      1-bit state (IPL or RT)
                    #      3-bit version (VERSION_1/VERSION_2)
                    #      3-bit current procedure primary rank (0-7)
                    #      3-bit current procedure secondary rank (0-7)
                    #      4-bit current procedure phase (see TdEntry::Phase)
                    #      4-bit current procedure type (see TdEntry::TdType)
                    #      4-bit number of entries in the queue (0-15)
                    #      2-bit current procedure port relative to ocmb (VERSION_2 only)

                    section = ''
                    if (hexId == hashString("TDCTLR_STATE_DATA_START")):
                        section = "TDCTLR_STATE_DATA_START"
                    else:
                        section = "TDCTLR_STATE_DATA_END"

                    tdctlrData, i = intConcat(buf, i, i+dataLength)

                    shift = (dataLength*8) - 1
                    state = (tdctlrData >> shift) & 0x1
                    stateStr = 'IPL'
                    if (1 == state):
                        stateStr = 'RT'

                    shift -= 3
                    version = (tdctlrData >> shift) & 0x7

                    shift -= 3
                    prank = (tdctlrData >> shift) & 0x7

                    shift -= 3
                    srank = (tdctlrData >> shift) & 0x7

                    shift -= 4
                    phase = (tdctlrData >> shift) & 0xf

                    shift -= 4
                    tdType = (tdctlrData >> shift) & 0xf

                    shift -= 4
                    entries = (tdctlrData >> shift) & 0xf

                    d[cd][section] = OrderedDict()
                    d[cd][section]['State'] = stateStr
                    d[cd][section]['Version'] = version
                    d[cd][section]['Primary Rank'] = prank
                    d[cd][section]['Secondary Rank'] = srank
                    d[cd][section]['Phase'] = phase
                    d[cd][section]['TD Type'] = tdTypeToStr(tdType)
                    d[cd][section]['Entries in Queue'] = entries

                    if (2 == version):
                        shift -= 2
                        curPort = (tdctlrData >> shift) & 0x3
                        d[cd][section]['Port'] = curPort

                    for y in range(entries):
                        #  For each entry in the queue (10 or 12 bits):
                        #      3-bit entry master rank (0-7)
                        #      3-bit entry slave rank (0-7)
                        #      4-bit entry type (see TdEntry::TdType)
                        #      2-bit entry port relative to ocmb (VERSION_2 only)
                        shift -= 3
                        entryPrank = (tdctlrData >> shift) & 0x7

                        shift -= 3
                        entrySrank = (tdctlrData >> shift) & 0x7

                        shift -= 4
                        entryType = (tdctlrData >> shift) & 0xf

                        d[cd][section][y] = OrderedDict()
                        d[cd][section][y]['Primary Rank'] = entryPrank
                        d[cd][section][y]['Secondary Rank'] = entrySrank
                        d[cd][section][y]['TD Type'] = tdTypeToStr(entryType)

                        if (2 == version):
                            shift -= 2
                            entryPort = (tdctlrData >> shift) & 0x3
                            d[cd][section][y]['Port'] = entryPort

                elif (hexId == hashString("TOD_ERROR_DATA")):
                    # Keep track of the length of the data we've parsed
                    parsedLength = 0

                    todErrSummary, i = intConcat(buf, i, i+4)
                    activeMdmt, i = intConcat(buf, i, i+4)
                    backupMdmt, i = intConcat(buf, i, i+4)
                    parsedLength += 12

                    # TOD Error Summary Format (32-bits)
                    # 1-bit:   Master Path Failover by Hw
                    # 1-bit:   TOD error detected by Phyp
                    # 1-bit:   topology switch event detected
                    # 1-bit:   topology reset request status
                    # 1-bit:   Topology acting as Active
                    # 3-bits:  active topology error status
                    # 3-bits:  backup topology error status
                    # 2-bits:  master path for active topology
                    # 2-bits:  master path for backup topology
                    # 17-bits: reserved

                    # autopep8: off
                    hardwareSwitchFlip     = (todErrSummary >> 31) & 0x1
                    phypDetectedTodError   = (todErrSummary >> 30) & 0x1
                    topologySwitchByPhyp   = (todErrSummary >> 29) & 0x1
                    topologyResetRequested = (todErrSummary >> 28) & 0x1
                    activeTopology         = (todErrSummary >> 27) & 0x1
                    activeTopologySummary  = (todErrSummary >> 24) & 0x7
                    backUpTopologySummary  = (todErrSummary >> 21) & 0x7
                    activeTopologyMastPath = (todErrSummary >> 19) & 0x3
                    backUpTopologyMastPath = (todErrSummary >> 17) & 0x3
                    # autopep8: on

                    activeTopologySummary = activeTopologySummary % 5
                    backUpTopologySummary = backUpTopologySummary % 5

                    tod = 'TOD_ERROR_DATA'
                    d[cd][tod] = OrderedDict()
                    d[cd][tod]['Master Path Switch by HW'] = hardwareSwitchFlip
                    d[cd][tod]['Host Detected TOD Error'] = phypDetectedTodError
                    d[cd][tod]['Host Switched Topology'] = topologySwitchByPhyp
                    d[cd][tod]['Topology Reset Requested'] = topologyResetRequested
                    d[cd][tod]['Active Topology'] = activeTopology
                    d[cd][tod]['Active MDMT'] = hex(activeMdmt)
                    d[cd][tod]['Backup MDMT'] = hex(backupMdmt)
                    d[cd][tod]['Active Topology Summary'] = todTopologyToStr(
                        activeTopologySummary)
                    d[cd][tod]['Active Topology M Path'] = activeTopologyMastPath
                    d[cd][tod]['Backup Topology Summary'] = todTopologyToStr(
                        backUpTopologySummary)
                    d[cd][tod]['Backup Topology M Path'] = backUpTopologyMastPath

                    # Collect any extra junk data at the end just in case
                    junkLength = dataLength - parsedLength
                    if (junkLength >= 1):
                        junk, i = memConcat(buf, i, i+junkLength)

                elif (hexId == hashString("L2_LD_COLRPR_FFDC")):
                    # NOTE: This data has been deprecated and moved to it's own
                    #       user data section. However, the parser must remain
                    #       for legacy logs.

                    # Keep track of the length of the data we've parsed
                    parsedLength = 0

                    # L2 Line Delete/Column Repair FFDC (64-bits)
                    # 16-bits: l2reserved1
                    # 4-bits:  l2CRPresent
                    # 4-bits:  l2CRMaxAllowed
                    # 4-bits:  l2LDMaxAllowed
                    # 4-bits:  l2LDcount
                    # 6-bits:  l2reserved2
                    # 10-bits: l2errAddress
                    # 8-bits:  l2errSynCol
                    # 1-bit:   l2errBack2to1
                    # 1-bit:   l2errBank
                    # 3-bits:  l2errDW
                    # 3-bits:  l2errMember
                    l2FFDC, i = intConcat(buf, i, i+8)
                    parsedLength += 8

                    # autopep8: off
                    l2reserved1    = (l2FFDC >> 48) & 0xff
                    l2CRPresent    = (l2FFDC >> 44) & 0xf # not used in P10
                    l2CRMaxAllowed = (l2FFDC >> 40) & 0xf # not used in P10
                    l2LDMaxAllowed = (l2FFDC >> 36) & 0xf
                    l2LDcount      = (l2FFDC >> 32) & 0xf
                    l2reserved2    = (l2FFDC >> 26) & 0x3f
                    l2errAddress   = (l2FFDC >> 16) & 0x3ff
                    l2errSynCol    = (l2FFDC >> 8) & 0xff
                    l2errBack2to1  = (l2FFDC >> 7) & 0x1
                    l2errBank      = (l2FFDC >> 6) & 0x1
                    l2errDW        = (l2FFDC >> 3) & 0x7
                    l2errMember    = l2FFDC & 0x7
                    # autopep8: on

                    # autopep8: off
                    l2 = 'L2_LD_FFDC'
                    d[cd][l2] = OrderedDict()
                    d[cd][l2]['L2 LD Counts']           = l2LDcount
                    d[cd][l2]['L2 LD Max Allowed']      = l2LDMaxAllowed
                    d[cd][l2]['L2 Error Member']        = '0x%02x' % l2errMember
                    d[cd][l2]['L2 Error DW']            = '0x%02x' % l2errDW
                    d[cd][l2]['L2 Error Bank']          = '0x%02x' % l2errBank
                    d[cd][l2]['L2 Error Back of 2to1 Next Cycle'] = (0 != l2errBack2to1)
                    d[cd][l2]['L2 Error Syndrome Col']  = '0x%02x' % l2errSynCol
                    d[cd][l2]['L2 Error Address']       = '0x%04x' % l2errAddress
                    # autopep8: on

                    # Collect any extra junk data at the end just in case
                    junkLength = dataLength - parsedLength
                    if (junkLength >= 1):
                        junk, i = memConcat(buf, i, i+junkLength)

                elif (hexId == hashString("L3_LD_COLRPR_FFDC")):
                    # NOTE: This data has been deprecated and moved to it's own
                    #       user data section. However, the parser must remain
                    #       for legacy logs.

                    # Keep track of the length of the data we've parsed
                    parsedLength = 0

                    # L3 Line Delete/Column Repair FFDC (64-bits)
                    # 8-bits:  l3reserved1
                    # 8-bits:  l3errDataOut
                    # 4-bits:  l3CRPresent
                    # 4-bits:  l3CRMaxAllowed
                    # 4-bits:  l3LDMaxAllowed
                    # 4-bits:  l3LDcount
                    # 5-bits:  l3reserved2
                    # 12-bits: l3errAddress
                    # 8-bits:  l3errSynCol
                    # 1-bit:   l3errBank
                    # 3-bits:  l3errDW
                    # 3-bits:  l3errMember
                    l3FFDC, i = intConcat(buf, i, i+8)
                    parsedLength += 8

                    # autopep8: off
                    l3reserved1    = (l3FFDC >> 56) & 0xff
                    l3errDataOut   = (l3FFDC >> 48) & 0xff # not used in P10
                    l3CRPresent    = (l3FFDC >> 44) & 0xf  # not used in P10
                    l3CRMaxAllowed = (l3FFDC >> 40) & 0xf  # not used in P10
                    l3LDMaxAllowed = (l3FFDC >> 36) & 0xf
                    l3LDcount      = (l3FFDC >> 32) & 0xf
                    l3reserved2    = (l3FFDC >> 27) & 0x1f
                    l3errAddress   = (l3FFDC >> 15) & 0xfff
                    l3errSynCol    = (l3FFDC >> 7) & 0xff
                    l3errBank      = (l3FFDC >> 6) & 0x1
                    l3errDW        = (l3FFDC >> 3) & 0x7
                    l3errMember    = l3FFDC & 0x7
                    # autopep8: on

                    # NOTE: This is where the data is broken, which prompted
                    #       the new user data section.

                    # Member is a 3-bit field and should be 4.
                    tmp_member = '0x%02x (or possibly 0x%02x)' % (
                        l3errMember, l3errMember + 8)

                    # Bank is a 1-bit field and should be 2.
                    tmp_bank = '0x%02x (or possibly 0x%02x)' % (
                        l3errBank, l3errBank + 2)

                    # CL half does not exist in data.
                    tmp_cl_half = 'unknown'

                    # autopep8: off
                    l3 = 'L3_LD_FFDC'
                    d[cd][l3] = OrderedDict()
                    d[cd][l3]['L3 LD Counts']           = l3LDcount
                    d[cd][l3]['L3 LD Max Allowed']      = l3LDMaxAllowed
                    d[cd][l3]['L3 Error Member']        = tmp_member
                    d[cd][l3]['L3 Error DW']            = '0x%02x' % l3errDW
                    d[cd][l3]['L3 Error Bank']          = tmp_bank
                    d[cd][l3]['L3 Error CL Half']       = tmp_cl_half
                    d[cd][l3]['L3 Error Syndrome Col']  = '0x%02x' % l3errSynCol
                    d[cd][l3]['L3 Error Address']       = '0x%04x' % l3errAddress
                    # autopep8: on

                    # Collect any extra junk data at the end just in case
                    junkLength = dataLength - parsedLength
                    if (junkLength >= 1):
                        junk, i = memConcat(buf, i, i+junkLength)

                elif ((0 != dataLength) and (8 >= dataLength)):
                    # Get the registers name and address and print the data
                    registerData = RegisterData()
                    targetType = (intHuid >> 16) & 0xFF
                    regInfo = registerData.parseRegister(
                        format(targetType, 'x'), dataId)
                    regIndex = regInfo['name'].ljust(
                        25) + ' (' + regInfo['address'] + ')'
                    regData, i = hexConcat(buf, i, i+dataLength)

                    if 'Registers' not in d[cd]:
                        d[cd]['Registers'] = OrderedDict()

                    if chipHuid not in d[cd]['Registers']:
                        d[cd]['Registers'][chipHuid] = OrderedDict()

                    d[cd]['Registers'][chipHuid][regIndex] = regData

        return json.dumps(d)

    def UdParserPrdfString(ver, data):
        d = OrderedDict()
        i = 0

        # #############################################################
        # The input buffer contains an ASCII string which is generally
        # used when doing an assert in the code.
        # #############################################################
        d['String'], i = strConcat(data, 0, len(data))

        return json.dumps(d)

    def UdParserPrdfPfaData(ver, data):
        d = OrderedDict()
        jnk = OrderedDict()

        # #############################################################
        # Format:
        #    8 bytes - ASCII string 'MS  DUMP'
        #    4 bytes - Dump content
        #    4 bytes - HUID
        #
        #    2 bytes - Error log action
        #    1 bytes - Error log severity
        #
        #    1 bytes - Service Action Counter
        #    4 bytes - SDC Flags with first 15 bits used
        #
        #    2 bytes - Error count
        #    2 bytes - Error Threshold
        #
        #    1 byte  - Primary attn type
        #    1 byte  - Secondary  attn type
        #    1 byte  - Global Gard policy
        #    1 byte  - unused
        #
        #    4 bytes - Total number of MRUs
        #    7 bytes (per MRU) - List of MRUs
        #
        #    4 bytes - Total number of signatures
        #    8 bytes (per signature) -  Full list of multi-signatures
        #
        # #############################################################

        i = 0

        jnk['SkipAtStart'], i = memConcat(data, 0, i+8)
        d['DUMP Content'], i = hexConcat(data, i, i+4)
        d['DUMP HUID'], i = hexConcat(data, i, i+4)

        d['ERRL Actions'], i = hexConcat(data, i, i+2)
        errlSev, i = memConcat(data, i, i+1)
        d['ERRL Severity'] = errlSevToStr(errlSev)

        d['Service Action Counter'], i = hexConcat(data, i, i+1)

        # SDC flags (15 one bit fields and 17 unused)
        sdcFlags, i = intConcat(data, i, i+4)

        # autopep8: off
        sdcDump     = (sdcFlags >> 31) & 0x1
        sdcUere     = (sdcFlags >> 30) & 0x1
        sdcSue      = (sdcFlags >> 29) & 0x1
        sdcAtTh     = (sdcFlags >> 28) & 0x1
        sdcDegraded = (sdcFlags >> 27) & 0x1
        sdcServCall = (sdcFlags >> 26) & 0x1
        sdcTrackit  = (sdcFlags >> 25) & 0x1
        sdcTerm     = (sdcFlags >> 24) & 0x1
        sdcLogit    = (sdcFlags >> 23) & 0x1
        # FYI, one deprecated entry was removed. To make the parser compatible
        # with older or newer error logs, this bit must remain a hole (i.e. it
        # can be reused, but subsequent data must remain in the bit positions
        # that they are currently in).
        sdcChnlFail = (sdcFlags >> 21) & 0x1
        sdcCoreCs   = (sdcFlags >> 20) & 0x1
        sdcSavedSdc = (sdcFlags >> 19) & 0x1
        sdcLastCore = (sdcFlags >> 18) & 0x1
        sdcDeferDe  = (sdcFlags >> 17) & 0x1
        sdcSecErr   = (sdcFlags >> 16) & 0x1
        # autopep8: on

        # autopep8: off
        d['SDC Flags'] = OrderedDict()
        d['SDC Flags']['DUMP']            = "True" if (sdcDump     == 1) else "False"
        d['SDC Flags']['UERE']            = "True" if (sdcUere     == 1) else "False"
        d['SDC Flags']['SUE']             = "True" if (sdcSue      == 1) else "False"
        d['SDC Flags']['AT_THRESHOLD']    = "True" if (sdcAtTh     == 1) else "False"
        d['SDC Flags']['DEGRADED']        = "True" if (sdcDegraded == 1) else "False"
        d['SDC Flags']['SERVICE_CALL']    = "True" if (sdcServCall == 1) else "False"
        d['SDC Flags']['TRACKIT']         = "True" if (sdcTrackit  == 1) else "False"
        d['SDC Flags']['TERMINATE']       = "True" if (sdcTerm     == 1) else "False"
        d['SDC Flags']['LOGIT']           = "True" if (sdcLogit    == 1) else "False"
        d['SDC Flags']['MEM_CHNL_FAIL']   = "True" if (sdcChnlFail == 1) else "False"
        d['SDC Flags']['PROC_CORE_CS']    = "True" if (sdcCoreCs   == 1) else "False"
        d['SDC Flags']['USING_SAVED_SDC'] = "True" if (sdcSavedSdc == 1) else "False"
        d['SDC Flags']['LAST_CORE_TERM']  = "True" if (sdcLastCore == 1) else "False"
        d['SDC Flags']['DEFER_DECONFIG']  = "True" if (sdcDeferDe  == 1) else "False"
        d['SDC Flags']['SECONDARY_ERROR'] = "True" if (sdcSecErr   == 1) else "False"
        # autopep8: on

        d['Error Count'], i = intConcat(data, i, i+2)
        d['Error Threshold'], i = intConcat(data, i, i+2)

        # get attention types and decode them
        primAttnType, i = memConcat(data, i, i+1)
        secondAttnType, i = memConcat(data, i, i+1)
        d['Primary Attn Type'] = attnTypeToStr(primAttnType)
        d['Secondary Attn Type'] = attnTypeToStr(secondAttnType)

        # gard type
        gardErrType, i = memConcat(data, i, i+1)
        d['PRD GARD Error Type'] = gardTypeToStr(gardErrType)
        jnk['SkipNext_01'], i = memConcat(data, i, i+1)

        # MRU callout section  (get decimal type number)
        mruListCount, i = intConcat(data, i, i+4)
        d['PRD MRU List'] = mruListCount

        mruNum = 0
        for mruNum in range(mruListCount):
            # dump sections inside MRU as below
            mruCallout, i = intConcat(data, i, i+4)
            mruType, i = memConcat(data, i, i+1)
            mruPriority, i = memConcat(data, i, i+1)
            mruGardState, i = memConcat(data, i, i+1)

            # convert some items into readable strings
            priorityStr = mruPriorityToStr(mruPriority)
            mruTypeStr = mruTypeToStr(mruType)
            gardStateStr = gardTypeToStr(mruGardState)

            mruWithNum = "MRU #" + str(mruNum)
            d[mruWithNum] = OrderedDict()
            d[mruWithNum]['Priority'] = priorityStr
            d[mruWithNum]['Type'] = mruTypeStr
            d[mruWithNum]['Gard State'] = gardStateStr

            if "MemoryMru" == mruTypeStr:
                parseMemMruCallout(mruCallout, mruWithNum, d, ver)
            else:
                # Add the information in the MRU to the dictionary
                # Pad the bitmap with 0s to 8 hex characters (32 bits)
                formatMru = '0x{0:08x}'.format(mruCallout)
                d[mruWithNum]['Mru Callout'] = formatMru

        # Signature list section  (get decimal type number)
        sigListCount, i = intConcat(data, i, i+4)
        d['Multi-Signature List'] = OrderedDict()
        d['Multi-Signature List']['Count'] = sigListCount

        listNum = 0
        for listNum in range(sigListCount):
            chipId, i = memConcat(data, i, i+4)
            chipSig, i = memConcat(data, i, i+4)

            sigFormat = "0x" + chipId + " 0x" + chipSig

            # Chip type is the character 2:3 of the chip ID
            chipType = chipId[2] + chipId[3]
            signatureData = SignatureData()
            d['Multi-Signature List'][sigFormat] = signatureData.parseSignature(
                chipType, chipSig)

        return json.dumps(d)

    def UdParserPrdfMruData(ver, data):
        d = OrderedDict()
        i = 0

        # Parse the extended Memory Mru data
        # Extended Mem Mru Format:
        # 32-bits:  Mem Mru Callout
        # 1-bit:    isBufDimm flag
        # 1-bit:    isX4Dram flag
        # 1-bit:    isValid flag
        # 5-bits:   Reserved
        # 640-bits: Mem VPD DQ Mapping

        mruCallout, i = intConcat(data, i, i+4)

        # Parse all the additional data, 3 flags and the DQ mapping
        otherData, i = intConcat(data, i, i+1)

        isBufDimm = (otherData >> 7) & 0x1
        isX4Dram = (otherData >> 6) & 0x1
        isValid = (otherData >> 5) & 0x1
        reserved = otherData & 0x1F

        d["Extended Mem Mru"] = OrderedDict()
        d["Extended Mem Mru"]["isX4Dram"] = "Yes" if (isX4Dram == 1) else "No"

        # Version 2 and above: parse the DQ Mapping
        dqMap = None
        if (2 <= ver):
            dqMapString = ''
            dqMap = OrderedDict()
            for mapKey in range(80):
                dqMapping, i = intConcat(data, i, i+1)
                dqMapString += str(dqMapping) + ' '
                dqMap[mapKey] = dqMapping

            d["Extended Mem Mru"]["Mem VPD Dq Mapping"] = dqMapString

        parseMemMruCallout(mruCallout, "Extended Mem Mru", d, ver, dqMap)

        return json.dumps(d)

    def UdL2LineDeleteFfdc(ver: int, data: memoryview) -> str:
        i = 0
        nodePos,      i = intConcat(data, i, i+1)
        procPos,      i = intConcat(data, i, i+1)
        corePos,      i = intConcat(data, i, i+1)
        ldCount,      i = intConcat(data, i, i+2)
        ldMax,        i = intConcat(data, i, i+2)
        ce_ue,        i = intConcat(data, i, i+1)
        member,       i = hexConcat(data, i, i+1)
        dw,           i = hexConcat(data, i, i+1)
        bank,         i = hexConcat(data, i, i+1)
        nextcycle,    i = intConcat(data, i, i+1)
        syndrome_col, i = hexConcat(data, i, i+1)
        addr,         i = hexConcat(data, i, i+2)

        errType = "CE" if 0 == ce_ue else "UE" if 1 == ce_ue else "CE/UE"

        d = {
            "L2 Line Delete Data": {
                "Target": {
                    "node": nodePos,
                    "proc": procPos,
                    "core": corePos,
                },

                "Line Delete Count": ldCount,
                "Max Line Deletes":  ldMax,

                "Error Data": {
                    "Type":                    errType,
                    "Member":                  member,
                    "DW":                      dw,
                    "Bank":                    bank,
                    "Back of 2to1 Next Cycle": (0 != nextcycle),
                    "Syndrome Col":            syndrome_col,
                    "Address":                 addr,
                }
            }
        }

        return json.dumps(d)

    def UdL3LineDeleteFfdc(ver: int, data: memoryview) -> str:
        i = 0
        nodePos,      i = intConcat(data, i, i+1)
        procPos,      i = intConcat(data, i, i+1)
        corePos,      i = intConcat(data, i, i+1)
        ldCount,      i = intConcat(data, i, i+2)
        ldMax,        i = intConcat(data, i, i+2)
        ce_ue,        i = intConcat(data, i, i+1)
        member,       i = hexConcat(data, i, i+1)
        dw,           i = hexConcat(data, i, i+1)
        bank,         i = hexConcat(data, i, i+1)
        cl_half,      i = hexConcat(data, i, i+1)
        syndrome_col, i = hexConcat(data, i, i+1)
        addr,         i = hexConcat(data, i, i+2)

        errType = "CE" if 0 == ce_ue else "UE" if 1 == ce_ue else "CE/UE"

        d = {
            "L3 Line Delete Data": {
                "Target": {
                    "node": nodePos,
                    "proc": procPos,
                    "core": corePos,
                },

                "Line Delete Count": ldCount,
                "Max Line Deletes":  ldMax,

                "Error Data": {
                    "Type":         errType,
                    "Member":       member,
                    "DW":           dw,
                    "Bank":         bank,
                    "CL Half":      cl_half,
                    "Syndrome Col": syndrome_col,
                    "Address":      addr,
                }
            }
        }

        return json.dumps(d)


# Dictionary with parser functions for each subtype
# Values are from ErrlSubsect enum in:
#   src/usr/diag/prdf/common/plugins/prdfPfa5Data.h
UserDetailsTypes = {
    1: "UdParserPrdfCapData",
    10: "UdParserPrdfString",
    51: "UdParserPrdfPfaData",
    62: "UdParserPrdfMruData",
    70: "UdL2LineDeleteFfdc",
    71: "UdL3LineDeleteFfdc",
}


def parseUDToJson(subType, ver, data):
    args = (ver, data)
    return getattr(errludP_prdf, UserDetailsTypes[subType])(*args)
