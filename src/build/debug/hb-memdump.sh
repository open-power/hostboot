#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/hb-memdump.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2022
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
    echo "hb-memdump.sh <filename> [MEMSIZE|discover|discovernotrace|limit] [Node #] [Chunk Size] "
    echo "    MEMSIZE is a two nibble hex value corresponding to the MemSize enumeration          "
    echo "    in <kernel/memstate.H> or the ASCII strings 'discover', 'discovernotrace', or       "
    echo "    'limit' (the default is Node 0).                                                    "
    echo "                                                                                        "
    echo "    MEMSIZE=40 from memstate.H -> 0x40, VMM_MEMORY_SIZE (64*MEGABYTE)                   "
    echo "                                                                                        "
    echo "    Node # (0,1,2,3) If non-zero Node you MUST include the MEMSIZE parameter.           "
    echo "                                                                                        "
    echo "    Chunk Size is a decimal value representing the MAX getmempba size (1MB default).    "
    echo "                                                                                        "
    echo "                           *** SAMPLES ***                                              "
    echo "                                                                                        "
    echo "              Default Single Node     -> hb-memdump.sh /nfs/hbdump.n0                   "
    echo "                                                                                        "
    echo "              Node 2                  -> hb-memdump.sh /nfs/hbdump.n2 40 2              "
    echo "                                                                                        "
    echo "              Node 3                  -> hb-memdump.sh /nfs/hbdump.n3 discover 3        "
    echo "                                                                                        "
    echo "              Limit to minimum 8MB    -> hb-memdump.sh /nfs/hbdump.n3 limit 3           "
    echo "                                                                                        "
    echo "              Custom MEMSIZE in HEX   -> hb-memdump.sh /nfs/hbdump.n0 10 0              "
    echo "                                                                                        "
    echo "              No Tracing              -> hb-memdump.sh /nfs/hbdump.n0 discovernotrace 0 "
    echo "                                                                                        "
    echo "              Custom CHUNK_SIZE       -> hb-memdump.sh /nfs/hbdump.n0 20 2097152        "
    echo "                  ^^ chunks are placed in /tmp/memdump.part, so limited by file system  "
    echo "                                                                                        "
    echo "              ADVANCED -> If system is checkstopped and you have maybe one chance       "
    echo "                          to pull dump use a limit on the memory pull                   "
    echo "                                                                                        "
    echo "                          -> hb-memdump.sh /nfs/hbdump.n3 limit 3                       "
    echo "                             - If checkstop, be sure to ecmdchipcleanup pu -n3          "
    echo "                                                                                        "
    echo "    Notes:                                                                              "
    echo "       It is usually fastest to write output to /tmp/ on the BMC.                       "
    echo "       For FSPs the /tmp/ space is limited so use /maint/ if /nfs/ is not available.    "
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
      printf "HBDUMP set_total_dump_size: MEMSIZE=0x${MEMSIZE}, dumping total_dump_size=$total_dump_size bytes.\n\n" >> ${LOG_LOCATION}
      copied_so_far=0
      update_progress_bar $copied_so_far
    fi
}

CHIP_POS=0;
get_boot_proc_chip_pos()
{
    # Determine boot proc chip position
    # - Depends on which FSP is Primary (this script always runs on Primary FSP)
    # - Default set to 0 above for when runninig on FSP-A or eBMC
    # - Only set to 1 when running on FSP-B

    # If rmgrcmd does not exist, assume running on eBMC
    if ! command -v rmgrcmd &> /dev/null ; then
      printf "HBDUMP get_boot_proc_chip_pos: CHIP_POS=${CHIP_POS}\n" >> ${LOG_LOCATION}
    else
      # Use rmgrcmd to determine current FSP's role
      FSP_POS=`rmgrcmd -i pos | awk '{print $2}'`
      if [[ ${FSP_POS} = "B" ]]; then
        CHIP_POS=1;
        printf "HBDUMP get_boot_proc_chip_pos: FSP-B CHIP_POS=${CHIP_POS}\n" >> ${LOG_LOCATION}
      else
        printf "HBDUMP get_boot_proc_chip_pos: FSP-A CHIP_POS=${CHIP_POS}\n" >> ${LOG_LOCATION}
      fi
    fi
}

set_hrmor()
{
    # Get boot proc chip position
    get_boot_proc_chip_pos

    # HRMOR is stored in bits 4:51 of core scratch 1 of boot proc
    # See memstate.H for details.
    # Multicast to all good cores.
    printf "HBDUMP set_hrmor pulling HRMOR -> getscom pu 4602F487 4 48 -p${CHIP_POS} -n${NODE}\n" >> ${LOG_LOCATION}
    HRMOR=`getscom pu 4602F487 4 48 -p${CHIP_POS} -n${NODE} | grep 0x | sed 's/.*0x/0x/'`
    printf "HBDUMP set_hrmor pulled HRMOR=${HRMOR}\n" >> ${LOG_LOCATION}

    # if there was an error reading the hrmor it will
    # have multi-line output, set it to a default
    # We may have various flavors of formatting coming back on failures, with BMC powered off only detected
    # with the search below
    if [[ $HRMOR == *$'\n'* ]]; then
      printf "HBDUMP set_hrmor PROBLEM getting HRMOR, using default 4 GB - 512 MB: ${HRMOR}\n" >> ${LOG_LOCATION}
      # HB HRMOR offset is at: 4 GB - 512 MB = 3584 MB
      HB_OFFSET=`expr 3584 \* 1024 \* 1024`
      # (64TB - 0x400000000000 OR 35184372088832)
      # see NODE_OFFSET in memorymap.H
      HB_BASE_HRMOR=`expr 64 \* 1024 \* 1024 \* 1024 \* 1024`
      # Calculate HRMOR (in decimal).
      HRMOR=`expr ${HB_BASE_HRMOR} \* ${NODE} + ${HB_OFFSET}`
    else
      #convert hex string to a decimal
      HRMOR=$(printf "%lld" $HRMOR )
    fi
}

# @fn update_progress_bar
# Print an update to the progress bar displayed to the user
#
# @param current - Current amount of bytes written to output file so far
update_progress_bar() (
    if [[ ${DISPLAY} -eq 1 ]]; then
        current=$1
        product=`expr $current \* $total_dump_size`
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
    printf "HBDUMP dump: HRMOR=${HRMOR} memaddr=$memaddr memaddr_h=$memaddr_h\n" >> ${LOG_LOCATION}

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
    printf "HBDUMP dump: addr=$addr size=$size blocksize=$blocksize blockcount=$blockcount seekcount=$seekcount\n" >> ${LOG_LOCATION}
    printf "HBDUMP dump: ---> ${GETMEM_COMMAND} ${memaddr_h} ${size} -p${CHIP_POS} -n${NODE} -fb /tmp/memdump.part\n" >> ${LOG_LOCATION}

    touch /tmp/memdump.part 2> /dev/null

    `${GETMEM_COMMAND} ${memaddr_h} ${size} -p${CHIP_POS} -n${NODE} -fb /tmp/memdump.part >> ${LOG_LOCATION} 2>&1`
    # if requesting more than available check for the file to reduce noise from file not found spam
    if [ -e /tmp/memdump.part ]; then
        fs_mempba=`filesize "/tmp/memdump.part"`
        printf "HBDUMP dump: fs_mempba=$fs_mempba filesize=${filesize}\n" >> ${LOG_LOCATION}
        if [ ${fs_mempba} -eq 0 ]; then
            if [ -e /tmp/memdump.part ]; then
                # cleanup in case something failed previously
                rm -f /tmp/memdump.part 2>/dev/null
                printf "\nHBDUMP dump: PROBLEM with GETMEM_COMMAND, probably UNABLE to perform command, manually check running command, TRACE=${LOG_LOCATION}\n"
                printf "\t\t${GETMEM_COMMAND} ${memaddr_h} ${size} -p${CHIP_POS} -n${NODE} -fb /tmp/memdump.part\n"
                printf "\nHBDUMP dump: Check that the system is in the proper state (is Hostboot LIVE to pull memory ??)\n"
                printf "\nHBDUMP dump: PROBLEM with GETMEM_COMMAND, cleaned up, manually try running commands\n" >> ${LOG_LOCATION}
                exit 1
            fi
         fi
    else
        fs_mempba=0
        printf "HBDUMP dump: SET fs_mempba to ZERO so /tmp/memdump.part did NOT exist\n" >> ${LOG_LOCATION}
    fi

    if [ ${fs_mempba} -eq 0 ]; then
        if [ -e /tmp/memdump.part ]
        then
            printf "HBDUMP dump: SET fs_mempba=$fs_mempba and /tmp/memdump.part exists\n" >> ${LOG_LOCATION}
            # cleanup in case something failed previously
            rm -f /tmp/memdump.part 2>/dev/null
        fi
        printf "\nHBDUMP dump: CAUTION: You may have a partial dump, CHECK TRACE=${LOG_LOCATION})\n"
        printf "CAUTION: GETMEM_COMMAND ---> ${GETMEM_COMMAND} ${memaddr_h} ${size} -n${NODE} -fb /tmp/memdump.part\n"
        exit 1
    else
        # stdin set to be "<" comes from memdump.part
        # stdout set to be t "1<>"  opens ${FILE} in r/w without truncating it
        # stderr set to be t "2>>"  appends error output to end of ${LOG_LOCATION}
        printf "HBDUMP dump: dd seek=${seekcount} count=${blockcount} bs=${blocksize} < /tmp/memdump.part 1<> ${FILE} 2>> ${LOG_LOCATION}\n" >> ${LOG_LOCATION}
        `dd seek=${seekcount} count=${blockcount} bs=${blocksize} < /tmp/memdump.part 1<> ${FILE} 2>> ${LOG_LOCATION}`
        fs_after=`filesize ${FILE}`
    fi


    if [ 0 -eq ${fs_after} ] ; then
        printf "\nHBDUMP dump: ERROR WITH FOLLOWING DD COMMAND : \n\n"
        printf "\tdd seek=${seekcount} count=${blockcount} bs=${blocksize} < /tmp/memdump.part 1<> ${FILE} >> ${LOG_LOCATION}\n\n"
        printf "HBDUMP dump: CHECK TRACE=${LOG_LOCATION}\n"
        exit 1
    else
        rm -f /tmp/memdump.part 2>/dev/null
        copied_so_far=$((copied_so_far+size))
        printf "HBDUMP dump: copied_so_far=$copied_so_far size=$size\n" >> ${LOG_LOCATION}
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
        #echo "dumpInChunks dumpAddr=$dumpAddr dumpSize=$dumpSize chunkSize=$chunkSize"
        if [ $dumpSize -gt $chunkSize ]
        then
            #echo "dumpInChunks dumpSize=${dumpSize} chunkSize=${chunSize}"
            dump $dumpAddr $chunkSize
            dumpSize=`expr $dumpSize - $chunkSize`
            dumpAddr=`expr $dumpAddr + $chunkSize`
            #echo "dumpInChunks UPDATED dumpSize=${dumpSize} ${dumpAddr}"
        else
            #echo "dumpInChunks ELSE SET TO ZERO NEXT dumpAddr=${dumpAddr} dumpSize=${dumpSize} chunkSize=${chunSize}"
            dump $dumpAddr $dumpSize
            dumpSize=0
        fi
    done
}


# @fn discover
# Read the HB descriptor to determine the current memory state and update the
# MEMSIZE variable.
discover()
{
    # Calculate hostboot descriptor address. (0x2000 + 8 + HRMOR)
    printf "HBDUMP discover: HRMOR=${HRMOR} for NODE=${NODE} CHIP_POS=${CHIP_POS}\n" >> ${LOG_LOCATION}
    descriptor_addr=`expr 8200 + $HRMOR`
    descriptor_h=`printf "%X" ${descriptor_addr}`
    printf "HBDUMP discover: descriptor_addr=$descriptor_addr descriptor_h=$descriptor_h\n" >> ${LOG_LOCATION}

    printf "HBDUMP discover: DESCRIPTOR COMMAND: ${GETMEM_COMMAND} ${descriptor_h} 8 -ox -quiet -p${CHIP_POS} -n${NODE}\n" >> ${LOG_LOCATION}
    # Extract descriptor base address.
    memsize_base_h=`${GETMEM_COMMAND} ${descriptor_h} 8 -ox -quiet -p${CHIP_POS} -n${NODE}  | tail -n1`

    y="${memsize_base_h//[^\n]}";
    if [ ${#y} -eq 1 ]; then
      memsize_base_h=`${GETMEM_COMMAND} ${descriptor_h} 1 -ox -quiet -p${CHIP_POS} -n${NODE}  | tail -n1`
      if [ 1 -eq ${DISPLAY} ]; then
          printf "HBDUMP discover: PROBLEMS, will TRY something, but you may want to TRY with your NODE -> hb-memdump.sh /tmp/memdump.bin 40 3 (where 3 is the Node, 0x40 is MEMSIZE)\n"
      fi
      MEMSIZE=40
      return
    fi

    memsize_base=`printf "%d" ${memsize_base_h}`
    printf "HBDUMP discover: DESCRIPTOR RESULTS: memsize_base_h=$memsize_base_h memsize_base=$memsize_base\n" >> ${LOG_LOCATION}

    # Calculate offset for the memsize variable within the descriptor.
    #     Last byte of 3rd 8-byte entry.  (16 + 7 + BASE + HRMOR)
    memsize_addr=`expr 16 + 7 + ${memsize_base} + ${HRMOR}`
    memsize_addr_h=`printf "%X" ${memsize_addr}`
    printf "HBDUMP discover: HOSTBOOT DESCRIPTOR OFFSETS: memsize_base=$memsize_base memsize_addr=$memsize_addr memsize_addr_h=$memsize_addr_h\n" >> ${LOG_LOCATION}

    # Read memory size
    printf "HBDUMP discover: GETMEM_COMMAND: ${GETMEM_COMMAND} ${memsize_addr_h} 1 -ox -quiet -p${CHIP_POS} -n${NODE} | tail -n1 | sed \"s/0x//\"\n" >> ${LOG_LOCATION}
    MEMSIZE=`${GETMEM_COMMAND} ${memsize_addr_h} 1 -ox -quiet -p${CHIP_POS} -n${NODE} | tail -n1 | sed "s/0x//"`
    z="${MEMSIZE//[^\n]}";
    if [ ${#z} -eq 1 ]; then
      printf "HBDUMP discover: PROBLEMS with RUNNING discover reading MEMSIZE, setting MEMSIZE=40 (0x40) as DEFAULT\n" >> ${LOG_LOCATION}
      MEMSIZE=40
      return
    fi
    printf "HBDUMP discover: GETMEM_COMMAND RESULTS: ${MEMSIZE}\n" >> ${LOG_LOCATION}

}

# @fn limit_memory
# Limit to 8MB so that the memory can be dumpped in a reasonable time.
limit_memory()
{
    case ${MEMSIZE} in
        *)
            printf "HBDUMP limit_memory -> Setting dump to 8MB for time efficiency\n" >> ${LOG_LOCATION}
            MEMSIZE=08
            ;;
    esac
}

# Read filename and memory size
FILE=$1
MEMSIZE=$2
NODE=$3
CHUNK_SIZE=$4

LOG_LOCATION="/tmp/memdumpoutput.tmp"
`rm -f ${LOG_LOCATION}`
`touch ${LOG_LOCATION}`

if [[ -z ${FILE} ]]; then
    usage
fi

if [ "$1" == "-h" ] || [ "$1" == "--help" ]; then
    usage
fi

if [[ -z ${MEMSIZE} ]]; then
    MEMSIZE=discover
    printf "HBDUMP main: Setting MEMSIZE=discover\n" >> ${LOG_LOCATION}
fi

if [[ -z ${NODE} ]]; then
    NODE=0
fi
if [[ -z ${CHUNK_SIZE} ]]; then
    # default to 1 MB chunk reads at a time
    CHUNK_SIZE=`expr 1024 \* 1024`
fi
printf "HBDUMP main: Setting CHUNK_SIZE=${CHUNK_SIZE}\n" >> ${LOG_LOCATION}

GETMEM_COMMAND="cipgetmempba"
if ! [ -x "$(command -v ${GETMEM_COMMAND})" ]; then
   GETMEM_COMMAND="getmempba"
fi

DISPLAY=1
HRMOR=0

# Set the HRMOR variable based on the NODE set above
set_hrmor

# create the output file
`touch ${FILE}`

case ${MEMSIZE} in
    (discovernotrace) # Call discover function to determine memory size
        # do not allow any fail output or progress updates
        # set_hrmor and other dependencies have already logged, so cleanup
        `rm -f ${LOG_LOCATION}`
        LOG_LOCATION="/dev/null"
        DISPLAY=0
        discover
        printf "HBDUMP -> discovernotrace MEMSIZE=0x$MEMSIZE\n" >> ${LOG_LOCATION}
        ;;
    (discover)  # Call discover function to determine memory size
        discover
        printf "HBDUMP -> discover MEMSIZE=0x$MEMSIZE\n" >> ${LOG_LOCATION}
        ;;
    (limit) # Call discover function and then reduce to 8MB if bigger.
        discover
        limit_memory
        printf "HBDUMP -> limit MEMSIZE=0x$MEMSIZE\n" >> ${LOG_LOCATION}
        ;;
    *[0-9])
        printf "HBDUMP -> Using MEMSIZE=0x$MEMSIZE\n" >> ${LOG_LOCATION}
        ;;
    (*)
        printf "HBDUMP -> Unsupported MEMSIZE=$MEMSIZE\n" >> ${LOG_LOCATION}
        exit 1
        ;;
esac

if [ 1 -eq ${DISPLAY} ]; then
    printf "HBDUMP -> FILE=${FILE} MEMSIZE=${MEMSIZE} NODE=${NODE} CHUNK_SIZE=${CHUNK_SIZE} where HRMOR=0x%X\n\n" ${HRMOR}
fi

if [[ $MEMSIZE == '00' ]] || [[ $MEMSIZE == '0' ]]; then
  # MEMSIZE has not been set, just dump HBB
  # The size of the HBB section in PNOR
  # *** NOTE: Keep in sync with Dump.pm and bootloaderif.H (MAX_HBB_SIZE)
  MAX_HBB_SIZE=925696
  set_total_dump_size $MAX_HBB_SIZE
  printf "\nHBDUMP -> setting MAX total_dump_size=$total_dump_size \n\n" >> ${LOG_LOCATION}
else
  # otherwise MEMSIZE is the number of MB we need to dump
  mb_count_decimal=`printf '%d' 0x$MEMSIZE`
  printf "\nHBDUMP main: checking mb_count_decimal=$mb_count_decimal MEMSIZE=0x${MEMSIZE}\n\n" >> ${LOG_LOCATION}
  MEGABYTE_DECIMAL=1048576
  set_total_dump_size `expr $mb_count_decimal \* $MEGABYTE_DECIMAL`
fi

dumpInChunks 0 $total_dump_size ${CHUNK_SIZE}

if [[ 1 -eq ${DISPLAY} ]]; then
    printf "HBDUMP ---> ${FILE} TRACE=${LOG_LOCATION}\n\n"
fi
