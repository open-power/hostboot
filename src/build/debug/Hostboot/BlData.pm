# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/BlData.pm $
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

use strict;

package Hostboot::BlData;
use Exporter;
our @EXPORT_OK = ('main');

sub formatData
{
    my $data = shift;
    my $dataRaw = "";

    for (my $i = 0; $i < length($data); $i++)
    {
        my $dataHexStr = sprintf("%02X", ord(substr($data, $i, 1)));
        $dataRaw .= $dataHexStr;

        if ($i % 16 == 15)
        {
            $dataRaw .= "\n";
        }
        elsif ($i % 4 == 3)
        {
            $dataRaw .= "   ";
        }
    }

    return $dataRaw."\n";
}

sub main
{
    ::setBootloader();

    my $btLdrHrmor  = 0x0000000008200000;

    my ($dataSym, $dataSize) = ::findSymbolAddress("Bootloader::g_blData");
    if (not defined $dataSym) { ::userDisplay "Cannot find symbol.\n"; die; }
    my $dataSymStr = sprintf("0x%08X", $dataSym);

    ::userDisplay "------------Bootloader Data------------";
    ::userDisplay "\nData Symbol Address: ";
    ::userDisplay $dataSymStr;

    my ($scratchSym, $scratchSize) =
        ::findSymbolAddress("Bootloader::g_blScratchSpace");
    if (not defined $scratchSym) { ::userDisplay "Cannot find symbol.\n"; die; }
    my $scratchSymStr = sprintf("0x%08X", $scratchSym);

    ::userDisplay "\nScratch Space Symbol Address: ";
    ::userDisplay $scratchSymStr;
    ::userDisplay "\n--------------------------------------------\n";

    my $dataAddr = 0x0000000008208000;

    my $traceAddr = $dataAddr;
    my $traceAddrStr = sprintf("0x%08X", $traceAddr);
    ::sendIPCMsg("read-data", "$traceAddr,64"); # Trace buffer is 64 bytes
    my ($type1, $trace) = ::recvIPCMsg();
    my $traceData = formatData($trace);

    ::userDisplay "\nTrace Buffer Address: ";
    ::userDisplay $traceAddrStr;
    ::userDisplay "\n\nTrace Data:\n";
    ::userDisplay $traceData;
    ::userDisplay "\n--------------------------------------------\n";


    my $indexAddr = $dataAddr + 64;
    my $indexAddrStr = sprintf("0x%08X", $indexAddr);
    ::sendIPCMsg("read-data", "$indexAddr,1"); # Trace index is 1 byte
    my ($type2, $index) = ::recvIPCMsg();
    $index =~ s/\0+//g; #strip off nulls
    my $indexStr = sprintf("0x%02X", ord($index));

    ::userDisplay "\nTrace Index Address: ";
    ::userDisplay $indexAddrStr;
    ::userDisplay "\n\nTrace Index (Next Entry): ";
    ::userDisplay $indexStr;
    ::userDisplay "\n\n--------------------------------------------\n";


    my $tiDataAreaAddr = $dataAddr + 80;
    my $tiDataAreaAddrStr = sprintf("0x%08X", $tiDataAreaAddr);
    ::sendIPCMsg("read-data", "$tiDataAreaAddr,48"); # TI Data Area is 48 bytes
    my ($type6, $tiDataArea) = ::recvIPCMsg();
    my $tiDataAreaData = formatData($tiDataArea);

    ::userDisplay "\nTI Data Area Address: ";
    ::userDisplay $tiDataAreaAddrStr;
    ::userDisplay "\n\nTI Data Area:\n";
    ::userDisplay $tiDataAreaData;
    ::userDisplay "\n--------------------------------------------\n";


    my $hbbPnorSecAddr = $dataAddr + 128;
    my $hbbPnorSecAddrStr = sprintf("0x%08X", $hbbPnorSecAddr);
    ::sendIPCMsg("read-data", "$hbbPnorSecAddr,32"); # Section data is 32 bytes
    my ($type5, $hbbPnorSec) = ::recvIPCMsg();
    my $hbbPnorSecData = formatData($hbbPnorSec);

    ::userDisplay "\nHBB PNOR Section Data Address: ";
    ::userDisplay $hbbPnorSecAddrStr;
    ::userDisplay "\n\nHBB PNOR Section Data:\n";
    ::userDisplay $hbbPnorSecData;
    ::userDisplay "\n--------------------------------------------\n";


    my $secRomValAddr = $dataAddr + 160;
    my $secRomValAddrStr = sprintf("0x%08X", $secRomValAddr);
    ::sendIPCMsg("read-data", "$secRomValAddr,1"); # Secure ROM Valid is 1 byte
    my ($type4, $secRomVal) = ::recvIPCMsg();
    $secRomVal =~ s/\0+//g; #strip off nulls
    my $secRomValStr = sprintf("0x%02X", ord($secRomVal));

    ::userDisplay "\nSecure ROM Valid Address: ";
    ::userDisplay $secRomValAddrStr;
    ::userDisplay "\n\nSecure ROM Valid: ";
    ::userDisplay $secRomValStr;
    ::userDisplay "\n\n--------------------------------------------\n";


    my $blToHbAddr = $dataAddr + 176;
    my $blToHbAddrStr = sprintf("0x%08X", $blToHbAddr);
    ::sendIPCMsg("read-data", "$blToHbAddr,89"); # BL to HB data is 89 bytes
    my ($type3, $blToHb) = ::recvIPCMsg();
    my $blToHbData = formatData($blToHb);

    ::userDisplay "\nBL to HB Data Address: ";
    ::userDisplay $blToHbAddrStr;
    ::userDisplay "\n\nBootloader to Hostboot Data:\n";
    ::userDisplay $blToHbData;
    ::userDisplay "\n--------------------------------------------\n";

    ::clearBootloader();
}

sub helpInfo
{
    my %info = (
        name => "BlData",
        intro => ["Displays Bootloader data."],
    );
}
