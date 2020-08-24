# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/BlParseDump.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2020
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
use strict;

package Hostboot::BlParseDump;
use Hostboot::BlTrace qw(formatTrace);
use Hostboot::TiParser qw(parseTiData formatDataForPrinting formatData shiftMultiple mapSafe);
use Exporter;
our @EXPORT_OK = ('main');

# The size of the TI area
# refer to bootloader_data.H @sync_ti_area_size for the Ti area size
use constant TI_AREA_SIZE_BYTES => 128;
# The size of the trace area
# refer to bootloader_trace.H @sync_trace_size for the Trace size
use constant TRACE_SIZE_BYTES => 64;
# The size of the remaining blData in the dumpfile
#     since bl_terminate.C dumps data from the beginning of the blData up until the bl_hbbSection,
#     we need to calulate the number of bytes remaining which are between the bl_trace and
#     bl_hbbSection in bootloader_data.H. This comes out to 16 bytes
use constant BL_DATA_DUMP_SIZE_BYTES => 16;

sub main
{
    ::userDisplay "\n-----------Bootloader Parse Dump------------\n";
    ::userDisplay("Minor warning: as of 9/10/2020, should changes\n"
                  "be made to the formating found in bl_terminate.C,\n"
                  "or the sizes of the data in bootloader_data.H,\n"
                  "then this parser may no longer be correct\n");

    # skip the data/bytes after 'Fatal Error SRC:' since that info is given
    # later and parsed in the data following 'Dump:'
    my $index = 4;
    while(not (::readData($index - 4, 4) =~ m/Dump/) and (::readData($index, 1) ne ""))
    {
       $index += 1;
    }

    # find the data after 'Dump:'
    if (::readData($index, 1) eq "")
    {
        die "Reached end of file before starting mark 'Dump:' was found!\n";
    }

    # look for the next [0-9] or [A-F] which reperesents the start of the
    # dump data
    while(not (::readData($index, 1) =~ m/[0-9A-F]/) and (::readData($index, 1) ne ""))
    {
       $index += 1;
    }

    if (::readData($index, 1) eq "")
    {
        die "Reached end of file before data was found!\n";
    }


    ############################# - Bl Ti Data - ################################

    ::userDisplay "\n-------------Parsing Bl TI Data-------------\n";
    # pass the $index by reference so that we can use it later for parsing the trace data
    # $tiData is a byte data stream of the data dumped to the console - no spaces, new lines, etc
    my $tiData = preFormatDumpData(\$index, TI_AREA_SIZE_BYTES);
    my $tiDataFormatted = formatDataForPrinting($tiData);
    ::userDisplay("Unparsed binary HB TI Data:\n");
    ::userDisplay $tiDataFormatted;
    $tiDataFormatted = formatData($tiData);
    parseTiData($tiDataFormatted);

    ::userDisplay "\n-------------Parsed Bl TI Data--------------\n";

    ########################### - Bl_Trace Data - ###############################

    ::userDisplay "\n-----------Parsing Bl Trace Data------------\n";

    my $traceData = preFormatDumpData(\$index, TRACE_SIZE_BYTES);
    my $traceDataFormatted = formatTrace($traceData);
    ::userDisplay "\nTrace Data:\n";
    ::userDisplay $traceDataFormatted;

    ::userDisplay "\n------------Parsed Bl Trace Data------------\n";

    ################ - last 16 bytes of Data from bl_data - #####################

    ::userDisplay "\n------------Parsing Bl Data part------------\n";
    my $blDataPart = preFormatDumpData(\$index, BL_DATA_DUMP_SIZE_BYTES);
    my $blDataFormatted = formatDataForPrinting($blDataPart);
    ::userDisplay("\nUnparsed binary Bl Data:\n");
    ::userDisplay $blDataFormatted;
    $blDataFormatted = formatData($blDataPart);
    parseBlDataPart($blDataFormatted);

    ::userDisplay "\n------------Parsed Bl Data part-------------\n";

}

# @sub preFormatDumpData formats the dumpfile input stream into a raw byte data stream which
# is accepted by the formatting logic in TiParser::formatData, ::formatDataForPrinting, and
# BlTrace::formatTrace.
# @param[in/out] index scalar reference to the offset into file from which to start reading
# @param[in] numBytes number of bytes to read in from the file
# @return preFormattedData
sub preFormatDumpData
{
    my $index = shift;
    my $numBytes = shift;

    # read in 2 nibbles (1 byte) at a time, skipping over whitespace chars
    my $numConsummed = 0;
    my $preFormatedData = "";
    while($numConsummed < $numBytes && ("" ne ::readData($$index, 1)))
    {
        if(::readData($$index, 2) =~ m/[0-9A-F]{2}/)
        {
            # convert to ascii for the ord() call in the TiParser::formatData
            $preFormatedData .= chr(hex ::readData($$index, 2));
            $numConsummed += 1;
        }
        # if there is a whitespace character, only move the index over by one.
        # otherwise, move over two for the next 'byte'
        $$index = ::readData($$index, 2) =~ m/\s/ ? $$index + 1: $$index + 2;
    }

    return $preFormatedData;

} # end preFormatDumpData


# @sub parseBlDataPart parses the bl data after the trace data; the bl_data gets printed to screen
# @param[in] blDataStr formatted binary bl_data
sub parseBlDataPart
{
    my $blDataStr = shift;

    # Create an array of bytes
    my @bytes = split(/ /, $blDataStr);

    ############################################################################
    # Parse out the last part of the dumpfile which is part of the Struct
    # bl_Data and print. This part of the bl_Data is right after the bl_trace[]
    # section. See bootloader_data.H for current format.
    ############################################################################

    #==========================================================================
    #                                Word 0
    #==========================================================================
    my $index = shift @bytes;
    ::userDisplay ("\nTrace Index (Next Entry): 0x". $index ."\n");

    my $reserved1 = shift @bytes;
    ::userDisplay ("(Reserved 1: 0x". $reserved1 .")\n");


    my $saved = shift @bytes;
    ::userDisplay "\nSaved Trace Index: 0x". $saved ."\n";

    my $reserved2 = shift @bytes;
    ::userDisplay ("(Reserved 2: 0x". $reserved2 .")\n");

    #==========================================================================
    #                                Word 1
    #==========================================================================

    my $loopCnt = shiftMultiple(\@bytes, 4);
    ::userDisplay "\nPNOR Loop Counter: 0x". $loopCnt ."\n";

    #==========================================================================
    #                              Word 2 & 3
    #==========================================================================
    my $pnorMmio = shiftMultiple(\@bytes, 8);

    ::userDisplay "\nFirst PNOR MMIO: 0x". $pnorMmio ."\n";
    ::userDisplay "\n--------------------------------------------\n";

}

# @sub helpInfo prints the usage info
sub helpInfo
{
    my %info = (
        name => "BlParseDump",
        intro => ["Parses a dumpfile of the output copied from the LPC console."],
        notes => ["Usage example:",
                  "For HB dump: hb-dump-debug --file=<dump file> --tool=BlParseDump",
                 ],
    );
}

