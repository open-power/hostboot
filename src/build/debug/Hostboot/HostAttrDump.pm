#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/HostAttrDump.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2020
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

# This module implements a command that dumps HB attribute values from guest
# memory to a file, for each attribute that is accessible (i.e. paged in). If a
# target's HUID attribute cannot be read, then its attributes are not dumped.
#
# Attributes are dumped to attribute_dump.bin in the working directory.

package Hostboot::HostAttrDump;

use strict;
use warnings;
use File::Path;
use File::Basename;
use IO::Handle;

use Hostboot::_GuestStruct qw(UINT8 UINT16 UINT32 UINT64 PACKED readBytes);

use Hostboot::_DebugFrameworkVMM qw(NotFound NotPresent getPhysicalAddr);

use Exporter;
our @EXPORT_OK = ('main');

my $vector = Hostboot::_GuestStruct->new([
    [ 'begin', UINT64 ],
    [ 'end', UINT64 ],
    [ 'end_of_storage', UINT64 ],
]);

my $TargetService = Hostboot::_GuestStruct->new([
    [ 'iv_initialized', UINT8 ],
    [ 'iv_pSys', UINT64 ],
    [ 'iv_processorModel', UINT32 ],
    [ 'iv_nodeData', $vector ]
]);

my $NodeSpecificInfo = Hostboot::_GuestStruct->new([
    [ 'nodeId', UINT8 ],
    [ 'initialized', UINT8 ],
    [ 'isMasterNode', UINT8 ],
    [ 'targets', UINT64 ],
    [ 'maxTargets', UINT32 ],
    [ 'pPnor', UINT64 ],
]);

my $Target = Hostboot::_GuestStruct->new([
    [ 'iv_attrs', UINT32 ],
    [ 'iv_pAttrNames', UINT64 ],
    [ 'iv_pAttrValues', UINT64 ],
    [ 'iv_ppAssociations', UINT64, 10 ],
], PACKED);

use constant OUTPUT_FILE => 'attribute_dump.bin';

sub main
{
    defined($ENV{PROJECT_ROOT}) or die "This tool requires the environment variable PROJECT_ROOT to be set";

    my %attrIdToSize;
    my $ATTR_HUID; # Attribute ID of ATTR_HUID

    {
        open(my $attrSizes, "$ENV{PROJECT_ROOT}/src/build/tools/calc-attribute-size-info/calculate-attrs-size |")
            or die("HostAttrDump: Cannot run calculate-attrs-size");

        while (my $line = <$attrSizes>)
        {
            if ($line =~ /(\d+), (\d+)/)
            {
                $attrIdToSize{int($1)} = int($2);
            }
            elsif ($line =~ /ATTR_HUID, (\d+)/)
            {
                $ATTR_HUID = $1;
            }
            else
            {
                die "Cannot parse line from calculate-attrs-size:\n$line\n";
            }
        }

        close($attrSizes) or die;
    }

    defined($ATTR_HUID) or die "ATTR_HUID value not found in output of calculate-attrs-size";

    open(my $outputFile, '>', OUTPUT_FILE) or die "Cannot open file @{[OUTPUT_FILE]} for output";

    binmode($outputFile) or die "Cannot set binary mode on file @{[OUTPUT_FILE]}";

    my ($targetSvcAddr, $unused) =
        ::findSymbolAddress('Singleton<TARGETING::TargetService>::instance()::instance');

    my $targetSvcSingleton = $TargetService->createInstance($targetSvcAddr);

    my $node0Info = $NodeSpecificInfo->createInstance($targetSvcSingleton->{iv_nodeData}->()->{begin}->());

    my $targetsAddr = $node0Info->{targets}->();
    my $targetCount = $node0Info->{maxTargets}->();

    for (my $targetIdx = 0; $targetIdx < $targetCount; ++$targetIdx)
    {
        my $target = $Target->createInstance($targetsAddr + $targetIdx * $Target->size());
        my $attrIds = $target->{iv_pAttrNames}->();
        my $attrValues = $target->{iv_pAttrValues}->();
        my $attrCount = $target->{iv_attrs}->();

        ::userDisplay "Target has $attrCount attrs\n";

        my %attrIdToBytes;

        for (my $attrIdx = 0; $attrIdx < $attrCount; ++$attrIdx)
        {
            my $attrId = Hostboot::_GuestStruct::read32($attrIds + UINT32*$attrIdx);
            my $attrValuePtr = Hostboot::_GuestStruct::read64($attrValues + UINT64*$attrIdx);
            my $attrSize = $attrIdToSize{$attrId} // die("Attribute 0x@{[sprintf '%x', $attrId]} with unknown size");

            if (!$attrValuePtr || !$attrId || NotFound eq $attrValuePtr || NotFound eq $attrId)
            {
                ::userDisplay "Cannot read pointer to attribute with ID 0x@{[sprintf '%x', $attrId]}\n";
                next;
            }

            my $attrValue = readBytes($attrValuePtr, $attrSize);

            if (defined($attrValue))
            {
                $attrIdToBytes{$attrId} = $attrValue;
            }
            else
            {
                ::userDisplay("Cannot read value for attribute 0x@{[sprintf '%x', $attrId]}\n");
            }
        }

        my $huid = $attrIdToBytes{$ATTR_HUID};

        if (!defined($huid))
        {
            ::userDisplay("Cannot find HUID attribute of target #$targetIdx, skipping\n");
            next;
        }

        foreach my $attrId (keys %attrIdToBytes)
        {
            writeAttributeToFile($outputFile, $huid, $attrId, $attrIdToBytes{$attrId});
        }
    }

    close $outputFile or die;
}

sub writeAttributeToFile
{
    my $file = shift;
    my $huid = shift;
    my $attrId = shift;
    my $attrValue = shift;

    my $attrLen = length($attrValue);

    for (my $i = 0; $i < $attrLen; $i += 8)
    {
        my $chunk = (substr $attrValue, $i, 8);
        $chunk .= "\x00" x (8 - length($chunk));

        print $file $huid;
        print $file pack('(III)>', $attrId, $attrLen, $i);
        print $file $chunk;
    }
}

# Debug tool help info.
sub helpInfo
{
    my %info = (
        name => "HostAttrDump",
        intro => [ "Extracts attribute information."],
    );
}

1; # Last expression in a perl module must be truthy.
