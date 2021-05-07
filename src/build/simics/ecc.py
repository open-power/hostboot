# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/simics/ecc.py $
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
import array
import os
import struct

###############################################################
# ECC (Error Correction Code) helper functions
# Used src/usr/pnor/ecc.C as a reference for this python code
#
# This is specific to p8 ECC, so every 8 bytes gets a following ECC byte
#
###############################################################


###############################################################
# Matrix used for ECC calculation.
#
#  Each row of this is the set of data word bits that are used for
#  the calculation of the corresponding ECC bit.  The parity of the
#  bitset is the value of the ECC bit.
#
#  ie. ECC[n] = eccMatrix[n] & data
#
#  Note: To make the math easier (and less shifts in resulting code),
#        row0 = ECC7.  HW numbering is MSB, order here is LSB.
#
#  These values come from the HW design of the ECC algorithm.
###############################################################
eccMatrix = [
    #0000000000000000111010000100001000111100000011111001100111111111
    0x0000e8423c0f99ff,
    #0000000011101000010000100011110000001111100110011111111100000000
    0x00e8423c0f99ff00,
    #1110100001000010001111000000111110011001111111110000000000000000
    0xe8423c0f99ff0000,
    #0100001000111100000011111001100111111111000000000000000011101000
    0x423c0f99ff0000e8,
    #0011110000001111100110011111111100000000000000001110100001000010
    0x3c0f99ff0000e842,
    #0000111110011001111111110000000000000000111010000100001000111100
    0x0f99ff0000e8423c,
    #1001100111111111000000000000000011101000010000100011110000001111
    0x99ff0000e8423c0f,
    #1111111100000000000000001110100001000010001111000000111110011001
    0xff0000e8423c0f99 ];


###############################################################
# Function to find the parity of an integer
#
# @param[in] i_int_type - integer
# @return 1 if odd parity, 0 if even parity
###############################################################
def findParity( i_int_type ):
      parity = 0
      while i_int_type:
        parity = ~parity
        i_int_type = i_int_type & (i_int_type - 1)
      if (parity & 1):
          return 1;
      return 0;

###############################################################
# Create the ECC field corresponding to a 8-byte data field
#
# @param[in] i_data - The 8 byte data to generate ECC for.
# @return The 1 byte ECC corresponding to the data.
###############################################################
def generateECC( i_data ):
    result = 0;
    for x in range(8):
        tmp = findParity(eccMatrix[x] & i_data) << x;
        result |= tmp

    return result;

###############################################################
# Inject ECC into a file
#
#  @param[in]  i_noEccFile - Source file for adding ecc
#  @param[out] o_eccFile - output file with ECC added
#
#  @note i_srcSz must be a multiple of 8 bytes.
###############################################################
def injectECC(i_noEccFile, o_eccFile):
    statinfo = os.stat(i_noEccFile);
    if ( statinfo.st_size % 8 != 0 ):
        print("injectECC: ", i_noEccFile, " file size ", os.stat(i_noEccFile) ," is not divisible by 8")
        return(1)

    # break noEccFile into array of uint64_t
    numbers = array.array("L");
    with open( i_noEccFile, 'rb' ) as f:
        numbers.fromfile(f, os.stat(i_noEccFile).st_size // numbers.itemsize)
        numbers.byteswap();

    with open( o_eccFile, 'wb' ) as outfile:
      for x in numbers:
          # write out the 8-byte number first
          outfile.write(struct.pack('>Q', x));

          # calculate ECC for this number and add to destination
          ecc = generateECC(x);
          outfile.write(struct.pack('>B', ecc));
    return None;


################################################################
# Adds 0xFF to end of file until it is aligned
# @param io_filename - file to align
# @param alignmentValue - how to align the file (4096 = 4K alignment)
################################################################
def alignFileByValue( io_filename, alignmentValue ):
    statinfo = os.stat( io_filename )
    if ( statinfo.st_size % alignmentValue != 0 ):
        paddingAmount = alignmentValue - (statinfo.st_size % alignmentValue);
        #print "Adding",paddingAmount,"0xFF's to",io_filename,"for", alignmentValue,"alignment"
        with open( io_filename, 'ab') as p:
            p.write(bytes([255]) * paddingAmount)

    return None;

