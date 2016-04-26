# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/BlTrace.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016
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
use Exporter;
our @EXPORT_OK = ('main');

my %traceText = (
    "10" => "Main started",
    "11" => "Main getHBBSection returned",
    "12" => "Main handleMMIO to working location returned",
    "13" => "Main removeECC returned",
    "14" => "Main applySecureSignatureValidation returned",
    "15" => "Main copy HBB to running location done",
    "20" => "HandleMMIO started",
    "30" => "PNOR Access getHBBSection started",
    "31" => "PNOR Access findTOC handleMMIO to copy TOC ONE returned",
    "32" => "PNOR Access findTOC readTOC for TOC ONE returned",
    "33" => "PNOR Access findTOC handleMMIO to copy TOC TWO returned",
    "34" => "PNOR Access findTOC readTOC for TOC TWO returned",
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
    "F0" => "Main getHBBSection returned",
    "F1" => "Main removeECC returned",
    "F2" => "PNOR Access readTOC checkForNullBuffer null buffer",
    "F3" => "PNOR Access readTOC performHdrChecksum checksum error",
    "F4" => "PNOR Access readTOC checkHeader header error",
    "F5" => "PNOR Access readTOC parseEntries entry error",
    "F6" => "PNOR Access findTOC readTOC errors",
    "F7" => "Utils parseEntries checksum error",
    "F8" => "Utils parseEntries size extends beyond Flash",
    "F9" => "PNOR Access getHBBSection findTOC error",
    "FA" => "PNOR Access getHBBSection findTOC no HBB section",
);

sub formatTrace
{
    my $trace = shift;
    my $traceDataRaw = "";
    my $traceDataText = "";

    for (my $i = 0; $i < length($trace); $i++)
    {
        my $traceHexStr = sprintf("%02X", ord(substr($trace, $i, 1)));
        $traceDataRaw .= $traceHexStr;

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

        if ($traceText{$traceHexStr} ne "")
        {
            $traceDataText .= "$traceHexStr  $traceText{$traceHexStr}\n";
        }
    }

    return $traceDataRaw."\n\n".$traceDataText;
}

sub main
{
    ::setBootloader();

    my $btLdrHrmor  = 0x0000000008200000;

    my ($indexAddr, $indexSize) = ::findSymbolAddress("bootloader_trace_index");
    if (not defined $indexAddr) { ::userDisplay "Cannot find symbol.\n"; die; }

    my $addr = $indexAddr + $btLdrHrmor;
    ::sendIPCMsg("read-data", "$addr,1"); # Trace index is 1 byte
    my ($type1, $index) = ::recvIPCMsg();
    $index =~ s/\0+//g; #strip off nulls
    my $indexStr = sprintf("0x%02X", ord($index));

    my ($traceAddr, $traceSize) = ::findSymbolAddress("bootloader_trace");
    if (not defined $traceAddr) { ::userDisplay "Cannot find symbol.\n"; die; }

    $addr = $traceAddr + $btLdrHrmor;
    my $traceAddrStr = sprintf("0x%08X", $addr);
    ::sendIPCMsg("read-data", "$addr,64"); # Trace buffer is 64 bytes
    my ($type2, $trace) = ::recvIPCMsg();
    $trace =~ s/\0+//g; #strip off nulls
    my $traceData = formatTrace($trace);

    ::userDisplay "------------Bootloader Trace------------";
    ::userDisplay "\nNext Entry Index: ";
    ::userDisplay $indexStr;
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
    );
}
