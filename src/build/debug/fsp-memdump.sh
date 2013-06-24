#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/fsp-memdump.sh $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG


# @fn usage
# Print usage statement.
usage()
{
    echo "memdump.sh <filename> [STATE|discover]"
    echo
    echo "    STATE should be a two nibble hex value corresponding to the"
    echo "    MemSize enumeration in <kernel/memstate.H> or the ASCII string"
    echo "    'discover'."
    exit -1
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
    state_base_h=`cipgetmempba ${descriptor_h} 8 -ox -quiet | tail -n1`
    state_base=`printf "%d" ${state_base_h}`

    # Calculate offset for the state variable within the descriptor.
    #     Last byte of 3rd 8-byte entry.  (16 + 7 + BASE + HRMOR)
    state_addr=`expr 16 + 7 + ${state_base} + ${HRMOR}`
    state_addr_h=`printf "%08x" ${state_addr}`

    # Read state.
    STATE=`cipgetmempba ${state_addr_h} 1 -ox -quiet | tail -n1 | sed "s/0x//"`
}

# Read filename and state.
FILE=$1
STATE=$2
if [[ -z ${FILE} ]]; then
    usage
fi

if [[ -z ${STATE} ]]; then
    STATE=08
fi

# Calculate HRMOR (in decimal).
HRMOR=`expr 128 \* 1024 \* 1024`

# Using initial STATE, iterate through all the included states dumping each's
# appropriate memory sections.
while [[ ${STATE} != BREAK ]]
do
    case ${STATE} in
        00|0)
            dump 0 520192
            STATE=BREAK
            ;;
        ff|FF)
            dump 520192 4096
            dump 1048576 524288
            dump 2097152 524288
            dump 3145728 262144
            dump 3473408 196608
            STATE=00
            ;;
        04|4)
            dump 524288 524288
            dump 1572864 524288
            dump 2621440 524288
            dump 3670016 524288
            STATE=ff
            ;;
        08|8)
            dump 4194304 1048576
            dump 5242880 1048576
            dump 6291456 1048576
            dump 7340032 1048576
            STATE=04
            ;;
        20)
            dump 8388608 1048576
            dump 9437184 1048576
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
            STATE=08
            ;;
        discover)  # Call discover function to determine state.
            discover
            ;;
        *)
            echo Unsupported STATE.
            STATE=BREAK
            ;;
    esac
done

