#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/fsp-memdump.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2020
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


# @fn usage
# Print usage statement.
usage()
{
    echo "fsp-memdump.sh <filename> [STATE|discover|limit] [Node #]"
    echo
    echo "    STATE should be a two nibble hex value corresponding to the"
    echo "    MemSize enumeration in <kernel/memstate.H> or the ASCII strings"
    echo "    'discover', 'limit'."
    echo "    Node # (0,1,2,3) "
    exit 0
}

# @fn dump
# Extract a block of memory using cipgetmempba.
#
# @param addr - Address to extract.
# @param size - Size (in bytes) to extract.
dump()
{
    addr=$1
    size=$2

    memaddr=`expr $addr + $HRMOR`

    echo "Extracting ${size}@${addr}"

    cipgetmempba `printf "%08x" ${memaddr}` ${size} -fb /tmp/memdump.part
    dd bs=1 if=/tmp/memdump.part of=${FILE} seek=${addr} count=${size} \
        conv=notrunc
    rm /tmp/memdump.part
}

# @fn discover
# Read the HB descriptor to determine the current memory state and update the
# STATE variable.
discover()
{
    # Calculate hostboot descriptor address. (0x2000 + 8 + HRMOR)
    descriptor_addr=`expr 8200 + $HRMOR`
    descriptor_h=`printf "%08x" ${descriptor_addr}`

    # Extract descriptor base address.
    state_base_h=`cipgetmempba ${descriptor_h} 8 -ox -quiet -n$NODE | tail -n1`
    state_base=`printf "%d" ${state_base_h}`

    # Calculate offset for the state variable within the descriptor.
    #     Last byte of 3rd 8-byte entry.  (16 + 7 + BASE + HRMOR)
    state_addr=`expr 16 + 7 + ${state_base} + ${HRMOR}`
    state_addr_h=`printf "%08x" ${state_addr}`

    # Read state.
    STATE=`cipgetmempba ${state_addr_h} 1 -ox -quiet -n$NODE | tail -n1 | sed "s/0x//"`
}

# @fn limit_memory
# Limit the state to 8MB so that the memory can be dumpped in a reasonable time.
limit_memory()
{
    case ${STATE} in
        40)
            STATE=08
            ;;
        *)
            ;;
    esac
}

# Read filename and state.
FILE=$1
STATE=$2
NODE=$3
if [[ -z ${FILE} ]]; then
    usage
fi

if [[ -z ${STATE} ]]; then
    STATE=discover
fi

if [[ -z ${NODE} ]]; then
    NODE=0
fi

# HRMOR is stored in bits 4:51 of core scratch 1
# See memstate.H for details.
# Multicast to all good cores.
HRMOR=`getscom pu 4602F487 4 48 -p0 -n$NODE | grep 0x | sed 's/.*0x/0x/'`

# if there was an error reading the hrmor it will
# have mutli line output, set it to a default
if [[ "$HRMOR" =~ \ |\' ]]; then
  echo "Attempt to read HRMOR from scom failed, falling back to default 4 GB - 512 MB error found :"
  echo "$HRMOR"
  # HB HRMOR offset is at: 4 GB - 512 MB = 3584 MB
  HB_OFFSET=`expr 3584 \* 1024 \* 1024`
  # (64TB - 0x400000000000 OR 35184372088832)
  # see NODE_OFFSET in memorymap.H
  HB_BASE_HRMOR=`expr 64 \* 1024 \* 1024 \* 1024 \* 1024`
  # Calculate HRMOR (in decimal).
  HRMOR=`expr ${HB_BASE_HRMOR} \* ${NODE} + ${HB_OFFSET}`
else
  #convert string to a int
  HRMOR=$(( HRMOR ))
fi

echo "NODE: ${NODE} - HRMOR is: ${HRMOR}"

# Using initial STATE, iterate through all the included states dumping each
# appropriate memory sections.
while [[ ${STATE} != BREAK ]]
do
    # *** NOTE: Keep in sync with Dump.pm and bootloaderif.H (MAX_HBB_SIZE)
    case ${STATE} in
        00|0)
            # Size of HBB PNOR partition without ECC, page aligned down, minus 4K header
            dump 0 925696
            STATE=BREAK
            ;;
        04|4)
            dump 925696 122880
            dump 1048576 1048576
            dump 2097152 1048576
            dump 3145728 1048576
            STATE=00
            ;;
        08|8)
            dump 4194304 1048576
            dump 5242880 1048576
            dump 6291456 1048576
            dump 7340032 1048576
            STATE=04
            ;;
         0A|A)
            dump 8388608 1048576
            dump 9437184 1048576
            STATE=08
            ;;
        30)
            dump 10485760 1048576
            dump 11534336 1048576
            dump 12582912 1048576
            dump 13631488 1048576
            dump 14680064 1048576
            dump 15728640 1048576
            dump 16777216 1048576
            dump 17825792 1048576
            dump 18874368 1048576
            dump 19922944 1048576
            dump 20971520 1048576
            dump 22020096 1048576
            dump 23068672 1048576
            dump 24117248 1048576
            dump 25165824 1048576
            dump 26214400 1048576
            dump 27262976 1048576
            dump 28311552 1048576
            dump 29360128 1048576
            dump 30408704 1048576
            dump 31457280 1048576
            dump 32505856 1048576
            dump 33554432 1048576
            dump 34603008 1048576
            dump 35651584 1048576
            dump 36700160 1048576
            dump 37748736 1048576
            dump 38797312 1048576
            dump 39845888 1048576
            dump 40894464 1048576
            dump 41943040 1048576
            dump 42991616 1048576
            dump 44040192 1048576
            dump 45088768 1048576
            dump 46137344 1048576
            dump 47185920 1048576
            dump 48234496 1048576
            dump 49283072 1048576
            STATE=0A
            ;;
        40)
            dump 50331648 1048576
            dump 51380224 1048576
            dump 52428800 1048576
            dump 53477376 1048576
            dump 54525952 1048576
            dump 55574528 1048576
            dump 56623104 1048576
            dump 57671680 1048576
            dump 58720256 1048576
            dump 59768832 1048576
            dump 60817408 1048576
            dump 61865984 1048576
            dump 62914560 1048576
            dump 63963136 1048576
            dump 65011712 1048576
            dump 66060288 1048576
            STATE=30
            ;;
        discover)  # Call discover function to determine state.
            discover
            ;;
        limit) # Call discover function and then reduce to 8MB if bigger.
            discover
            limit_memory
            ;;
        *)
            echo Unsupported STATE.
            STATE=BREAK
            ;;
    esac
done

