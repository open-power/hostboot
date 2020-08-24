# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/BlTrace.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2020
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

package Hostboot::BlTrace;
use Exporter qw(import);
our @EXPORT_OK = ('main', 'formatTrace');

my %traceText = (
    "10" => "Main started",
    "11" => "Main getHBBSection returned",
    "12" => "Main handleMMIO to working location returned",
    "13" => "Main removeECC returned",
    "14" => "Main verify started",
    "15" => "Main verify succeeded",
    "16" => "Main copy HBB to running location done",
    "17" => "Main verify skip verification - no eyecatch ",
    # @TODO RTC:167740 TI on failed magic # check once signing is widespread
    "18" => "Main verify skip verification - no magic number ",
    "19" => "Main verify skip verification - SAB unset ",
    "1A" => "Main verify component ID succeeded",
    "1B" => "Main verify component ID failed",
    "1C" => "Main working length too big",
    "20" => "HandleMMIO started",
    "21" => "HandleMMIO started using BYTESIZE",
    "24" => "HandleMMIO started using WORDSIZE",
    "28" => "HandleMMIO started using DBLWORDSIZE",
    "30" => "PNOR Access getHBBSection started",
    "31" => "PNOR Access findTOC handleMMIO to copy TOC ONE returned",
    "32" => "PNOR Access findTOC readTOC for TOC ONE returned",
    "33" => "PNOR Access findTOC use PNOR start address",
    "34" => "PNOR Access findTOC adjust PNOR address",
    "35" => "PNOR Access getHBBSection findTOC returned",
    "41" => "PNOR Access readTOC zeroSection returned",
    "42" => "PNOR Access readTOC checkForNullBuffer returned",
    "43" => "PNOR Access readTOC performHdrChecksum returned",
    "44" => "PNOR Access readTOC checkHeader returned",
    "45" => "PNOR Access readTOC parseEntries returned",
    "D0" => "Main removeECC returned corrected ECC rc",
    "E0" => "Utils checkHeader magic invalid",
    "E1" => "Utils checkHeader version invalid",
    "E2" => "Utils checkHeader entry size invalid",
    "E3" => "Utils checkHeader entry count invalid",
    "E4" => "Utils checkHeader block size invalid",
    "E5" => "Utils checkHeader block count invalid",
    "E6" => "Utils checkHeader header size invalid",
    "E7" => "Utils parseEntries invalid section",
    "E8" => "Utils SectionIdToString PNOR section id out of range",
    "E9" => "Utils cmpSecurebootMagicNumber requested address to compare is a nullptr",
    "F0" => "Main getHBBSection returned",
    "F1" => "Main removeECC returned error",
    "F2" => "PNOR Access readTOC checkForNullBuffer null buffer",
    "F3" => "PNOR Access readTOC performHdrChecksum checksum error",
    "F4" => "PNOR Access readTOC checkHeader header error",
    "F5" => "PNOR Access readTOC parseEntries entry error",
    "F6" => "PNOR Access findTOC readTOC errors",
    "F7" => "Utils parseEntries checksum error",
    "F8" => "Utils parseEntries size extends beyond Flash",
    "F9" => "PNOR Access getHBBSection findTOC error",
    "FA" => "PNOR Access getHBBSection findTOC no HBB section",
    "FB" => "main verifyBaseImage failed",
    "FC" => "main verifyBaseImage secure rom invalid",
    "FD" => "PNOR Access findTOC handleMMIO LPC ERR returned",
);

sub formatTrace
{
    my $trace = shift;
    my $traceDataRaw = "";
    my $traceDataText = "";
    my $byteWordCount = 0;

    for (my $i = 0; $i < length($trace); $i++)
    {
        my $traceHexStr = sprintf("%02X", ord(substr($trace, $i, 1)));
        $traceDataRaw .= $traceHexStr;

        if ($i % 4 == 0)
        {
            $traceDataText .= "Word #$byteWordCount\n";
            $byteWordCount += 1;
        }

        if ($i % 16 == 15)
        {
            $traceDataRaw .= "\n";
        }
        elsif ($i % 4 == 3)
        {
            $traceDataRaw .= "   ";
        }
        else
        {
            $traceDataRaw .= " ";
        }

        if (exists $traceText{$traceHexStr})
        {
            if ($traceText{$traceHexStr} ne "")
            {
                $traceDataText .= "$traceHexStr  $traceText{$traceHexStr}\n";
            }
            else
            {
                $traceDataText .= "$traceHexStr  NO TRACE TEXT FOUND - check BlTrace.pm\n";
            }
        }
        else
        {
            $traceDataText .= "$traceHexStr  UNKNOWN HEX FOUND - check BlTrace.pm\n";
        }
    }

    return $traceDataRaw."\n\n".$traceDataText;
}

sub main
{
    ::setBootloader();

    my ($packName,$args) = @_;

    # Offset from Hostboot's HRMOR (2MB + HBBL_MAX_SIZE + 12K exception vectors + size of TI area (128B))
    my $traceAddr = 0x20B080;
    # refer to bootloader_trace.H @sync_trace_size for the Trace size
    my $traceSize = 64;

    # Parse trace address from options.
    if (defined $args->{"address"})
    {
        $traceAddr = $args->{"address"};
    }
    elsif (defined $args->{"addr"})
    {
        $traceAddr = $args->{"addr"};
    }

    my $indexAddr = $traceAddr + $traceSize;
    my $index = ::read8($indexAddr);
    my $indexStr = sprintf("0x%02X", $index);

    ::userDisplay "\n------------Bootloader Trace------------";
    ::userDisplay "\nNext Entry Index: ";
    ::userDisplay $indexStr;

    my $traceAddrStr = sprintf("0x%08X", $traceAddr);
    my $trace = ::readData($traceAddr,$traceSize);
    $trace =~ s/\0+//g; #strip off nulls
    my $traceData = formatTrace($trace);

    ::userDisplay "\n\nTrace Buffer Address: ";
    ::userDisplay $traceAddrStr;
    ::userDisplay "\n\nTrace Data:\n";
    ::userDisplay $traceData;
    ::userDisplay "\n--------------------------------------------\n";

    ::clearBootloader();
}

sub helpInfo
{
    my %info = (
        name => "BlTrace",
        intro => ["Displays the Bootloader trace buffer."],
        options => {
                    "address='trace address'" => ["Address of trace buffer."],
                   },
        notes => ["addr can be used as a short-name for 'address'."]
    );
}
