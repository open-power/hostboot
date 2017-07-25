#!/bin/bash
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbeio/runtime/test/sbemsg-utils.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017
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

#-----------------------------------------------------------------------
# print-getscom
#   Filter value returned by getscom
#
#   print-getscom <addr>
#----------------------------------------------------------------------
print-getscom(){
    getscom pu $1 | grep -e '0x[0-9A-Fa-f]\{16\}' | sed -e 's/.*0x/0x/'
}

#-----------------------------------------------------------------------
# print-getscom-32
#   Filter value returned by getscom and return lsw
#
#   print-getscom-32 <addr>
#----------------------------------------------------------------------
print-getscom-32(){
    let temp=$(dw-getscom $1)
    let temp=$(($temp >>32))
    let temp=$(($temp&0x00000000FFFFFFFF))
    printf "0x%08x\n" $temp
}

#-----------------------------------------------------------------------
# append-u8()
#   Append a u8 hex value to a binary file.
#
#   append-u8 <hex value> <file>
#
#------------------------------------------------------------------------
append-u8(){
    if [ -z "$1" ] || [ -z "$2" ]
    then
        echo "Usage: append-u8 <value> <file>"
        echo "       param value: A uint8_t value to append to <file>"
        echo "       param file: The file to which the binary uint8_t"
        echo "                   value is to be appended."
    fi

    x=$1

    if [[ "${x:0:2}" != "0x" ]]
    then
        x="0x$x"
    fi

    let x=$(($x&0x00FF))
    printf "0000000: %02x" $x | xxd -r -g0 >> $2
}

#--------------------------------------------------------------------------
# append-u16()
#   Append a u16 hex value to a binary file. The xxd utility will store the
#   value in Big Endian format.
#
#   append-u16 <hex value> <file>
#---------------------------------------------------------------------------
append-u16(){
    if [ -z "$1" ] || [ -z "$2" ]
    then
        echo "Usage: append-u16 <value> <file>"
        echo "       param value: A uint16_t value to append to <file>"
        echo "       param file: The file to which the binary uint16_t"
        echo "                   value is to be appended."
    fi

    x=$1

    if [[ "${x:0:2}" != "0x" ]]
    then
        x="0x$x"
    fi

    let x=$(($x& 0x0000FFFF))
    printf "0000000: %04x" $x | xxd -r -g0 >> $2
}

#---------------------------------------------------------------------------
# append-u32()
#   Append a u32 hex value to a binary file. The xxd utility will store the
#   value in Big Endian format.
#
#   append-u32 <hex value> <file>
#---------------------------------------------------------------------------
append-u32(){
    if [ -z "$1" ] || [ -z "$2" ]
    then
        echo "Usage: append-u32 <value> <file>"
        echo "       param value: A uint32_t value to append to <file>"
        echo "       param file: The file to which the binary uint32_t"
        echo "                   value is to be appended."
    fi

    x=$1

    if [[ "${x:0:2}" != "0x" ]]
    then
        x="0x$x"
    fi

    let x=$(($x& 0x00000000FFFFFFFF))
    printf "0000000: %08x" $x | xxd -r -g0 >> $2
}

#---------------------------------------------------------------------------
# append-u64()
#   Append a u64 hex value to a binary file. The xxd utility will store the
#   value in Big Endian format.
#
#   append-u64 <hex value> <file>
#---------------------------------------------------------------------------
append-u64(){
    if [ -z "$1" ] || [ -z "$2" ]
    then
        echo "Usage: append-u64 <value> <file>"
        echo "       param value: A uint64_t value to append to <file>"
        echo "       param file: The file to which the binary uint64_t"
        echo "                   value is to be appended."
    fi

    x=$1

    if [[ "${x:0:2}" != "0x" ]]
    then
        x="0x$x"
    fi

    let x=$(($x))
    printf "0000000: %016x" $x | xxd -r -g0 >> $2
}

#----------------------------------------------------------------------------
# write-attr-request-hdr
#   Writes an SbeMessage Header to file.
#   write-attr-request-hdr $1 <out file> $2 <payload size> $3 [sequence number]
#
# HEADER SCHEMA
#   SBE HEADER VERSION(u32) - 0x00010000
#   SBE HEADER MSG SIZE(u32) - The size of the entire message HEADER + PAYLOAD
#   SBE HEADER SEQ NUMBER(u32) - The Sequence Number for the Message.
#   CMD HEADER VERSION(u32) - 0x00010000
#   CMD HEADER STATUS(u32)  - The response status.
#   CMD HEADER DATA OFFSET(u32) - 0x14.
#   CMD HEADER DATA SIZE(u32) - The payload size.
#   CMD HEADER COMMAND(u32) - 0x00E10002 (Attribute Override Command)
#----------------------------------------------------------------------------
write-attr-request-hdr(){
    if [ -z "$1" ] || [ -z "$2" ]
    then
        echo "Usage write-attr-request-hdr <outfile> <payload size> [sequence]"
        return
    fi

    if [ -z "$3" ]
    then
        sbe_hdr_seq_id=0x00000001
    else
        sbe_hdr_seq_id=$3
    fi

    sbe_hdr_version=0x00010000
    let sbe_hdr_msg_size=$(($2 + 0x20 ))
    sbe_hdr_msg_size=$(printf "0x%08x" $sbe_hdr_msg_size)
    cmd_hdr_version=0x00010000
    cmd_hdr_status=0x00000000
    cmd_hdr_data_offset=0x00000014
    cmd_hdr_data_size=$2
    cmd_hdr_command=0x00E10002

    append-u32 $sbe_hdr_version $1
    append-u32 $sbe_hdr_msg_size $1
    append-u32 $sbe_hdr_seq_id $1
    append-u32 $cmd_hdr_version $1
    append-u32 $cmd_hdr_status $1
    append-u32 $cmd_hdr_data_offset $1
    append-u32 $cmd_hdr_data_size $1
    append-u32 $cmd_hdr_command $1
}

#------------------------------------------------------------------------
# write-attr-request
#
#   Produce a binary file that can be copied to the
#   SBE COMMS AREA for use as an SBE Pass-through
#   request. The caller should pass the path of a binary file
#   that contains attribute override information. The contents of
#   the attribute override file will be concatenated to a file
#   containing a request header. This file should be copied to
#   the SBE COMMS AREA prior to invoking sbeMsg.
#
#   write-attr-request $1 <attribute override data file>
#                      $2 <outfile>
#                      $3 [Sequence Number of the request]
#
#   Parameters:
#       attr data file: A file produced by the attributeOverride tool.
#                       This file contains attribute overrides in binary
#                       form.
#       outfile: The request file. This file is the concatenation of an
#                SBE Pass-through request header and the attribute
#                override data from the first parameter.
#       sequence : A sequence number to identify the request/response.
#-------------------------------------------------------------------------
write-attr-request(){
    if [ -z "$1" ] || [ -z "$2" ]
    then
        echo "usage write-attr-request <attr data file> <outfile> [sequence]"
        return
    fi

    #Get payload size
    attrsize=$(wc -c $1 | awk '{print $1; exit}')
    let attrsize=$(($attrsize))
    attrsize=$(printf "0x%08x" $attrsize)

    #Set sequence number
    if [ -z $3 ]
    then
        sb_hdr_seq_id=0x00000001
    else
        sb_hdr_seq_id=$3
    fi

    #write request header to temp file
    tmpfile=/tmp/attr_override_request_$$
    write-attr-request-hdr $tmpfile $attrsize $sb_hdr_seq_id

    #Create request file and remove temporary
    cat $tmpfile $1 > $2
    rm -f $tmpfile
}

#----------------------------------------------------------
# parse-attr-resp
#   Parses a binary file, the contents of which represent
#   a response to an SBE Pass-Through command. The xxd
#   utility will convert the values returned from Big Endian
#   to host byte order.
#
#   parse-attr-resp $1 <input binary file>
#----------------------------------------------------------
parse-attr-resp(){
    if [ -z "$1" ]
    then
        echo "usage parse-attr-resp <bin file>"
        return
    fi

    let sbe_hdr_version=0x$(xxd -p -l4 -s0 $1)
    let sbe_hdr_msg_size=0x$(xxd -p -l4 -s4 $1)
    let sbe_hdr_seq_id=0x$(xxd -p -l4 -s8 $1)
    let cmd_hdr_version=0x$(xxd -p -l4 -s12 $1)
    let cmd_hdr_status=0x$(xxd -p -l4 -s16 $1)
    let cmd_hdr_data_offset=0x$(xxd -p -l4 -s20 $1)
    let cmd_hdr_data_size=0x$(xxd -p -l4 -s24 $1)
    let cmd_hdr_command=0x$(xxd -p -l4 -s28 $1)

    echo ""
    echo "Attribute Override Response:"
    printf "\tSBE HDR Version: 0x%08X\n" $sbe_hdr_version
    printf "\tSBE HDR MSG Size: 0x%08X (%d)\n" $sbe_hdr_msg_size \
                                               $sbe_hdr_msg_size
    printf "\tSBE HDR SEQ ID: 0x%08X (%d)\n" $sbe_hdr_seq_id \
                                             $sbe_hdr_seq_id
    printf "\tCMD HDR VERSION: 0x%08X\n" $cmd_hdr_version
    printf "\tCMD HDR STATUS: 0x%08X\n" $cmd_hdr_status
    printf "\tCMD HDR DATA OFFSET: 0x%08X (%d)\n" $cmd_hdr_data_offset \
                                                  $cmd_hdr_data_offset
    printf "\tCMD HDR DATA SIZE: 0x%08X (%d)\n" $cmd_hdr_data_size \
                                                $cmd_hdr_data_size
    printf "\tCMD HDR CMD: 0x%08X\n" $cmd_hdr_command
    echo ""
}
