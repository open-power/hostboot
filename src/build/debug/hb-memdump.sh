#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/hb-memdump.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2021
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
    echo "hb-memdump.sh <filename> [STATE|discover|discovernotrace|limit] [Node #] [Chunk Size]"
    echo
    echo "    STATE should be a two nibble hex value corresponding to the"
    echo "    MemSize enumeration in <kernel/memstate.H> or the ASCII strings"
    echo "    'discover', 'discovernotrace', or 'limit'. (defaults discover)"
    echo "    Node # (0,1,2,3)  (defaults Node 0, if non-0 node is specified, must include STATE parameter as well) "
    echo "    Chunk Size is a decimal value representing the max getmempba size (defaults 1MB)"
    echo
    echo "    Notes:"
    echo "       It is usually fastest to write output to /tmp/ on the BMC."
    echo "       For FSPs the /tmp/ space is limited so use /maint/ if /nfs/ is not available."
    exit 0
}

# @fn gcd
# Get greatest common denominator between two integers
# Use the Euclidean Algorith
# https://en.wikipedia.org/wiki/Euclidean_algorithm
#
# @param integer_a
# @param integer_b
# @return gcd of integer_a and integer_b
gcd()
{
    if [[ $2 -eq 0 ]]; then
        echo $1
    else
        gcd $2 $(( $1 % $2 ))
    fi
}

# @fn filesize
# Get the file's size in bytes
#
# @param file path - Path to file we want to get the size of
filesize()
{
  # busybox stat(1) doesn't support --format=%s
  wc -c "$1" | awk '{print $1}'
}

# @fn set_total_dump_size
# Set value for $total_dump_size if it is not yet set.
#
# @param Value to potentially set $total_dump_size with
set_total_dump_size()
{
    if [[ -z ${total_dump_size} ]]; then
      total_dump_size=$1
      if [[ ${DISPLAY} -eq 1 ]]; then
          printf "Host State: ${STATE}, dumping 0x%X bytes.\n\n" $total_dump_size;
      fi
      copied_so_far=0
      update_progress_bar $copied_so_far
    fi
}

set_hrmor()
{
    # HRMOR is stored in bits 4:51 of core scratch 1
    # See memstate.H for details.
    # Multicast to all good cores.
    HRMOR=`getscom pu 4602F487 4 48 -p0 -n${NODE} | grep 0x | sed 's/.*0x/0x/'`

    # if there was an error reading the hrmor it will
    # have multi-line output, set it to a default
    n="${HRMOR//[^\n]}";
    if [ ${#n} -eq 1 ]; then
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
}

# @fn update_progress_bar
# Print an update to the progress bar displayed to the user
#
# @param current - Current amount of bytes written to output file so far
update_progress_bar() (
    if [[ ${DISPLAY} -eq 1 ]]; then
        current=$1
        product=$((current * total_dump_size))
        # figure out what percentage 'p' we have completed
        # check for zero to ensure we avoid a divide-by-zero case
        if [[ $product -ne 0 ]]; then
            # calculate percentage
            awkout=`awk -v cur=$current -v tot=$total_dump_size 'BEGIN {print (100/tot*cur)}'`
            # trim decimal
            p=`echo $awkout | cut -d . -f 1`
        else
            p=0
        fi
        #width of fixed space for progress bar
        local w=80
        numdots=$(( $p*$w/100 ))
        # create a string of spaces, then change them to dots
        if [[ $numdots -ne 0 ]]; then
            dots=$(printf "%0.s." $(seq 1 $numdots))
        else
            dots=""
        fi
        # print those dots on a fixed-width space plus the percentage etc.
        printf "\r\e |%-*s| %3d %% %s of %s" "$w" "$dots" "$p" "$*" "$total_dump_size";

        # print a newline when we reach the end
        if [[ $current -eq $total_dump_size ]]; then
            printf "\n\n"
        fi
    fi
)

# @fn dump
# Extract a block of memory using getmempba.
#
# @param addr - Address to extract.
# @param size - Size (in bytes) to extract.
dump()
{
    addr=$1
    size=$2

    memaddr=`expr $addr + $HRMOR`
    memaddr_h=`printf "%08x" ${memaddr}`

    MAX_BLOCKSIZE=8192

    # Get the maximum blocksize, up to 8192 bytes, that we can use for the dd
    # operation. We want something that can cleanly divide both the addrs and
    # the number of bytes want to dump. That way we can fill in the blockcount
    # and seek parameters for the dd command with the correct integer values.
    # Testing showed that blocksizes over 8192 started seeing lower performance.
    blocksize=`gcd $addr $size` > /dev/null 2>&1
    blocksize=`gcd $blocksize $MAX_BLOCKSIZE` > /dev/null 2>&1
    blockcount=$((size / blocksize))
    seekcount=$((addr / blocksize))

    rm /tmp/memdumpoutput.tmp 2> /dev/null && touch /tmp/memdump.part
    printf "${GETMEM_COMMAND}  ${memaddr_h} ${size} -n${NODE} -fb /tmp/memdump.part \n\n" > ${LOG_LOCATION}
    `${GETMEM_COMMAND} ${memaddr_h} ${size} -n ${NODE} -fb /tmp/memdump.part >> ${LOG_LOCATION} 2>&1`
    fs_mempba=`filesize "/tmp/memdump.part"`

    if [ ${fs_mempba} -eq 0 ]; then
        printf "\nERROR WITH FOLLOWING COMMAND : \n\n\t"
        printf "${GETMEM_COMMAND} ${memadd_h} ${size} -n${NODE} -fb /tmp/memdump.part"
        printf "\nSee failure output and memory output at ${LOG_LOCATION}"
        exit 1
    else
        # stdin set to be "<" comes from memdump.part
        # stdout set to be t "1<>"  opens ${FILE} in r/w without truncating it
        # stderr set to be t "2>>"  appends error output to end of ${LOG_LOCATION}
        printf  "dd seek=${seekcount} count=${blockcount} bs=${blocksize} < /tmp/memdump.part 1<> ${FILE} 2>> ${LOG_LOCATION} \n\n" >> ${LOG_LOCATION}
        `dd seek=${seekcount} count=${blockcount} bs=${blocksize} < /tmp/memdump.part 1<> ${FILE} 2>> ${LOG_LOCATION}`
        fs_after=`filesize ${FILE}`
    fi

    if [ 0 -eq ${fs_after} ] ; then
        printf "\nERROR WITH FOLLOWING COMMAND : \n\n"
        printf "\tdd seek=${seekcount} count=${blockcount} bs=${blocksize} < /tmp/memdump.part 1<> ${FILE} 2>> ${LOG_LOCATION}\n\n"
        printf "See failure output and memory output at ${LOG_LOCATION} and /tmp/memdump.part respectively\n"
        exit 1
    else
        rm /tmp/memdump.part
        rm /tmp/memdumpoutput.tmp 2> /dev/null
        copied_so_far=$((copied_so_far+size))
        if [ 1 -eq ${DISPLAY} ]; then
            update_progress_bar $copied_so_far
        fi
    fi
}

# @fn dumpInChunks
# Extract a block of memory using (multiple) getmempba calls
#
# @param addr - Address to extract.
# @param size - Full Size (in bytes) to extract.
# @param chunksize - extract data this many bytes at a time
dumpInChunks()
{
    dumpAddr=$1
    dumpSize=$2
    chunkSize=$3

    #echo "-------------------------------------------------------"
    #echo "dumpChunkSize( ${dumpAddr}, ${dumpSize}, ${chunkSize} )"
    while  [ $dumpSize -gt 0 ]
    do
        #echo "Individual: dumpChunkSize( ${dumpAddr}, ${dumpSize} - ${chunkSize})"
        if [ $dumpSize -gt $chunkSize ]
        then
            #echo "dump ${dumpAddr} ${chunkSize}"
            dump $dumpAddr $chunkSize
            dumpSize=`expr $dumpSize - $chunkSize`
            dumpAddr=`expr $dumpAddr + $chunkSize`
        else
            #echo "ELSE: dump ${dumpAddr} ${dumpSize}"
            dump $dumpAddr $dumpSize
            dumpSize=0
        fi
    done
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
    state_base_h=`${GETMEM_COMMAND} ${descriptor_h} 8 -ox -quiet -n${NODE}  | tail -n1`
    state_base=`printf "%d" ${state_base_h}`

    # Calculate offset for the state variable within the descriptor.
    #     Last byte of 3rd 8-byte entry.  (16 + 7 + BASE + HRMOR)
    state_addr=`expr 16 + 7 + ${state_base} + ${HRMOR}`
    state_addr_h=`printf "%08x" ${state_addr}`

    # Read state.
    #echo "READ STATE: getmempba ${state_addr_h} 1 -ox -quiet | tail -n1 | sed \"s/0x//\""
    STATE=`${GETMEM_COMMAND} ${state_addr_h} 1 -ox -quiet -n${NODE} | tail -n1 | sed "s/0x//"`

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
CHUNK_SIZE=$4

if [[ -z ${FILE} ]]; then
    usage
fi

if [ "$1" == "-h" ] || [ "$1" == "--help" ]; then
    usage
fi

if [[ -z ${STATE} ]]; then
    STATE=discover
fi

if [[ -z ${NODE} ]]; then
    NODE=0
fi
if [[ -z ${CHUNK_SIZE} ]]; then
    # default to 1 MB chunk reads at a time
    CHUNK_SIZE=`expr 1024 \* 1024`
fi

GETMEM_COMMAND="cipgetmempba"
if ! [ -x "$(command -v ${GETMEM_COMMAND})" ]; then
   GETMEM_COMMAND="getmempba"
fi

DISPLAY=1
LOG_LOCATION="/tmp/memdumpoutput.tmp"

# Set the HRMOR variable based on the NODE set above
set_hrmor

printf "\nDumping hostboot memory for NODE%d where HRMOR is 0x%X. " ${NODE} ${HRMOR}

# create the output file
`touch ${FILE}`

case ${STATE} in
    (discovernotrace) # Call discover function to determine state.
        # do not allow any fail output or progress updates
        LOG_LOCATION="/dev/null"
        DISPLAY=0
        discover
        ;;
    (discover)  # Call discover function to determine state.
        discover
        ;;
    (limit) # Call discover function and then reduce to 8MB if bigger.
        discover
        limit_memory
        ;;
    *[0-9])
        echo "Requested to dump $STATE MB"
        ;;
    (*)
        echo "Unsupported STATE: $STATE"
        exit 1
        ;;
esac

if [[ $STATE == '00' ]] || [[ $STATE == '0' ]]; then
  # STATE has not been set, just dump HBB
  # The size of the HBB section in PNOR
  # *** NOTE: Keep in sync with Dump.pm and bootloaderif.H (MAX_HBB_SIZE)
  MAX_HBB_SIZE=925696
  set_total_dump_size $MAX_HBB_SIZE
else
  # otherwise STATE is the number of MB we need to dump
  mb_count_decimal=`printf '%d' 0x$STATE`
  MEGABYTE_DECIMAL=1048576
  set_total_dump_size `expr $mb_count_decimal \* $MEGABYTE_DECIMAL`
fi

dumpInChunks 0 $total_dump_size ${CHUNK_SIZE}

printf "SUCCESS! Dump completed and can be found at ${FILE}\n\n"

