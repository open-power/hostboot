#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/HwpfAttrOverride.pm $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END_TAG

#
# This perl module will be used in a standalone Hostboot environment
# (Simics or VBU) to process a FAPI Attribute Override Text File and
# send the overrides to Hostboot
#
# Author: Mike Jones
#

use strict;
package Hostboot::HwpfAttrOverride;
use Hostboot::_DebugFrameworkVMM;
use Hostboot::CallFunc;
use Exporter;
our @EXPORT_OK = ('main');

#------------------------------------------------------------------------------
# Constants
#------------------------------------------------------------------------------

# From fapiTarget.H
use constant TARGET_TYPE_SYSTEM => 0x00000001;
use constant TARGET_TYPE_DIMM => 0x00000002;
use constant TARGET_TYPE_PROC_CHIP => 0x00000004;
use constant TARGET_TYPE_MEMBUF_CHIP => 0x00000008;
use constant TARGET_TYPE_EX_CHIPLET => 0x00000010;
use constant TARGET_TYPE_MBA_CHIPLET => 0x00000020;
use constant TARGET_TYPE_MCS_CHIPLET => 0x00000040;
use constant TARGET_TYPE_XBUS_ENDPOINT => 0x00000080;
use constant TARGET_TYPE_ABUS_ENDPOINT => 0x00000100;

# From fapiAttributeOverride.H
use constant ATTR_POS_NA => 0xffff;
use constant ATTR_UNIT_POS_NA => 0xff;
use constant ATTR_ARRAYD_NA => 0xff;
use constant ATTR_OVERRIDE_CONST => 1;
use constant ATTR_OVERRIDE_NON_CONST => 2;
use constant ATTR_OVERRIDE_CLEAR_ALL => 3;

# From fapiPlatAttrOverrideDirect.C
my $overrideSymbol = 'fapi::g_attrOverride';

# Expected filenames
my $attributeIdFileName = 'fapiAttributeIds.H';
my $overrideFileName = 'hwpfAttributeOverrides.txt';

sub main
{
    my ($packName,$args) = @_;
    my $debug = 0;
    if (defined $args->{"debug"})
    {
        $debug = 1;
    }

    #--------------------------------------------------------------------------
    # Check if the Attribute ID and Attribute Overrides files exist
    #--------------------------------------------------------------------------
    my $attributeIdFile = ::getImgPath();
    $attributeIdFile = $attributeIdFile."$attributeIdFileName";
    unless (-e $attributeIdFile)
    {
        die "Cannot find file $attributeIdFile";
    }

    my $overrideFile = ::getImgPath();
    $overrideFile = $overrideFile."$overrideFileName";
    unless (-e $overrideFile)
    {
        die "Cannot find file $overrideFile";
    }

    #--------------------------------------------------------------------------
    # Process the Attribute ID file. Record the values of the Attribute IDs and
    # the Attribute Enumeration Values in hashes
    #--------------------------------------------------------------------------
    my %attributeIdVals;
    my %attributeEnumVals;

    open(IDFILE, "< $attributeIdFile") or die "Cannot open file $attributeIdFile";
    while (my $line = <IDFILE>)
    {
        chomp($line);

        if ($line =~ /^\s+(ATTR_\S+) = 0x(\S+),/)
        {
            # Found an attribute ID
            $attributeIdVals{$1} = hex $2
        }
        # Note that enumerated values can end with 'ULL'
        elsif ($line =~ /\s+(ENUM_ATTR_\S+) = 0x([a-fA-F0-9]+)/)
        {
            # Found a hex attribute value enumeration
            $attributeEnumVals{$1} = hex $2;
        }
        elsif ($line =~ /\s+(ENUM_ATTR_\S+) = ([0-9]+)/)
        {
            # Found a decimal attribute value enumeration
            $attributeEnumVals{$1} = $2;
        }
    }
    close(IDFILE);

    # Debug output
    if ($debug)
    {
        foreach my $key (keys %attributeIdVals)
        {
            ::userDisplay "AttrIdVal: $key => $attributeIdVals{$key}\n";
        }
        foreach my $key (keys %attributeEnumVals)
        {
            ::userDisplay "AttrEnumVal: $key => $attributeEnumVals{$key}\n";
        }
    }

    #--------------------------------------------------------------------------
    # Process the Attribute Overrides file. Record the information for each
    # override in arrays
    #--------------------------------------------------------------------------
    my @attrIdString;
    my @overrideVal;
    my @attrId;
    my @targetType;
    my @pos;
    my @unitPos;
    my @overrideType;
    my @arrayD1;
    my @arrayD2;
    my @arrayD3;
    my @arrayD4;

    # Setup the initial override to be an instruction to "clear all overrides"
    $attrIdString[0] = "CLEAR_ALL_OVERRIDES";
    $overrideVal[0] = 0;
    $attrId[0] = 0;
    $targetType[0] = 0;
    $pos[0] = 0;
    $unitPos[0] = 0;
    $overrideType[0] = ATTR_OVERRIDE_CLEAR_ALL;
    $arrayD1[0] = 0;
    $arrayD2[0] = 0;
    $arrayD3[0] = 0;
    $arrayD4[0] = 0;

    my $numOverrides = 1;
    my $curTargetType = TARGET_TYPE_SYSTEM;
    my $curPos = ATTR_POS_NA;
    my $curUnitPos = ATTR_UNIT_POS_NA;

    open(OVFILE, "< $overrideFile") or die "Cannot open file $overrideFile";

    while (my $line = <OVFILE>)
    {
        chomp($line);

        if ($line =~ /^target = /)
        {
            # Found a target
            my $p8pres = 0;

            # Figure out the target type
            if ($line =~ /p8.ex/)
            {
                $p8pres = 1;
                $curTargetType = TARGET_TYPE_EX_CHIPLET;
            }
            elsif ($line =~ /centaur.mba/)
            {
                $curTargetType = TARGET_TYPE_MBA_CHIPLET;
            }
            elsif ($line =~ /p8.mcs/)
            {
                $p8pres = 1;
                $curTargetType = TARGET_TYPE_MCS_CHIPLET;
            }
            elsif ($line =~ /p8.xbus/)
            {
                $p8pres = 1;
                $curTargetType = TARGET_TYPE_XBUS_ENDPOINT;
            }
            elsif ($line =~ /p8.abus/)
            {
                $p8pres = 1;
                $curTargetType = TARGET_TYPE_ABUS_ENDPOINT;
            }
            elsif ($line =~ /centaur/)
            {
                $curTargetType = TARGET_TYPE_MEMBUF_CHIP;
            }
            elsif ($line =~ /p8/)
            {
                $p8pres = 1;
                $curTargetType = TARGET_TYPE_PROC_CHIP;
            }
            elsif ($line =~ /dimm/)
            {
                $curTargetType = TARGET_TYPE_DIMM;
            }
            else
            {
                $curTargetType = TARGET_TYPE_SYSTEM;
            }

            # Figure out the position
            if ($p8pres == 1)
            {
                # Do not confuse 'p8' for position 8
                if ($line =~ /p8\S*:p(\d+)/)
                {
                    $curPos = $1;
                }
                else
                {
                    $curPos = ATTR_POS_NA;
                }
            }
            else
            {
                if ($line =~ /:p(\d+)/)
                {
                    $curPos = $1;
                }
                else
                {
                    $curPos = ATTR_POS_NA;
                }
            }

            # Figure out the unit position
            if ($line =~ /:c(\d+)/)
            {
                $curUnitPos = $1;
            }
            else
            {
                $curUnitPos = ATTR_UNIT_POS_NA;
            }
        }
        elsif ($line =~ /^(ATTR_\w+)/)
        {
            # Found an override
            $attrIdString[$numOverrides] = $1;
            $targetType[$numOverrides] = $curTargetType;
            $pos[$numOverrides] = $curPos;
            $unitPos[$numOverrides] = $curUnitPos;

            # Figure out the attribute ID
            if (exists $attributeIdVals{$1})
            {
                $attrId[$numOverrides] = $attributeIdVals{$1};
            }
            else
            {
                ::userDisplay "Cannot find ID $1 in $attributeIdFile\n";
                die; 
            }

            # Figure out the attribute array dimensions
            if ($line =~ /^ATTR_\w+\[(\d)\]\[(\d)\]\[(\d)\]\[(\d)\] /)
            {
                # 4D array override
                $arrayD1[$numOverrides] = $1;
                $arrayD2[$numOverrides] = $2;
                $arrayD3[$numOverrides] = $3;
                $arrayD4[$numOverrides] = $4;
            }
            elsif ($line =~ /^ATTR_\w+\[(\d)\]\[(\d)\]\[(\d)\] /)
            {
                # 3D array override
                $arrayD1[$numOverrides] = $1;
                $arrayD2[$numOverrides] = $2;
                $arrayD3[$numOverrides] = $3;
                $arrayD4[$numOverrides] = ATTR_ARRAYD_NA;
            }
            elsif ($line =~ /^ATTR_\w+\[(\d)\]\[(\d)\] /)
            {
                # 2D array override
                $arrayD1[$numOverrides] = $1;
                $arrayD2[$numOverrides] = $2;
                $arrayD3[$numOverrides] = ATTR_ARRAYD_NA;
                $arrayD4[$numOverrides] = ATTR_ARRAYD_NA;
            }
            elsif ($line =~ /^ATTR_\w+\[(\d)\] /)
            {
                # 1D array override
                $arrayD1[$numOverrides] = $1;
                $arrayD2[$numOverrides] = ATTR_ARRAYD_NA;
                $arrayD3[$numOverrides] = ATTR_ARRAYD_NA;
                $arrayD4[$numOverrides] = ATTR_ARRAYD_NA;
            }
            else
            {
                # Non-array attribute
                $arrayD1[$numOverrides] = ATTR_ARRAYD_NA;
                $arrayD2[$numOverrides] = ATTR_ARRAYD_NA;
                $arrayD3[$numOverrides] = ATTR_ARRAYD_NA;
                $arrayD4[$numOverrides] = ATTR_ARRAYD_NA;
            }

            # Figure out the override value
            if ($line =~ /^ATTR_\S+\s+\S+\s+([A-Za-z]+\S*)/)
            {
                # enumerator
                my $enum = "ENUM_"."$attrIdString[$numOverrides]"."_$1";
                if (exists $attributeEnumVals{$enum})
                {
                    $overrideVal[$numOverrides] = $attributeEnumVals{$enum};
                }
                else
                {
                    ::userDisplay "Cannot find enum $enum in $attributeIdFile\n";
                    die;
                }
            }
            elsif ($line =~ /^ATTR_\S+\s+\S+\s+0x([0-9A-Za-z]+)/)
            {
                # Hex value
                $overrideVal[$numOverrides] = hex $1;
            }
            elsif ($line =~ /^ATTR_\S+\s+\S+\s+(\d+)/)
            {
                # Decimal Value
                $overrideVal[$numOverrides] = $1;
            }
            else
            {
                ::userDisplay "Cannot find override value for $attrIdString[$numOverrides]\n";
                die;
            }

            # Figure out the override type
            if ($line =~ /CONST\s*/)
            {
                $overrideType[$numOverrides] = ATTR_OVERRIDE_CONST;
            }
            else
            {
                $overrideType[$numOverrides] = ATTR_OVERRIDE_NON_CONST;
            }

            # Debug output
            if ($debug)
            {
                ::userDisplay "OVERRIDE. Val: $overrideVal[$numOverrides]. ";
                ::userDisplay "ID: $attrId[$numOverrides]. ";
                ::userDisplay "TargType: $targetType[$numOverrides]. ";
                ::userDisplay "Pos: $pos[$numOverrides].$unitPos[$numOverrides].\n";
                ::userDisplay "          OType: $overrideType[$numOverrides]. ";
                ::userDisplay "Dims: $arrayD1[$numOverrides].";
                ::userDisplay "$arrayD2[$numOverrides].";
                ::userDisplay "$arrayD3[$numOverrides].";
                ::userDisplay "$arrayD4[$numOverrides]\n";
            }

            $numOverrides++;
        }
    }
    close(OVFILE);

    #--------------------------------------------------------------------------
    # Get the address of the Hostboot Attribute Override variable
    #--------------------------------------------------------------------------
    my $overrideSymAddr = (::findSymbolAddress("$overrideSymbol"))[0];

    if (not defined $overrideSymAddr)
    {
        ::userDisplay "Cannot find Hostboot symbol $overrideSymbol\n";
        die;
    }

    my $overrideAddr =
        Hostboot::_DebugFrameworkVMM::getPhysicalAddr($overrideSymAddr, $debug, 0);

    if ($overrideAddr eq Hostboot::_DebugFrameworkVMM::NotFound)
    {
        ::userDisplay "Cannot translate $overrideSymbol to a physical address\n";
        die;
    }

    # From fapiAttributeOverride.H
    # struct AttributeOverride
    # {
    #     uint64_t iv_overrideVal;  // Large enough to hold the biggest attribute size
    #     uint32_t iv_attrId;       // fapi::AttributeId enum value
    #     uint32_t iv_targetType;   // fapi::TargetType enum value
    #     uint16_t iv_pos;          // For chips/dimms the position
    #                               // For chiplets the parent chip position
    #     uint8_t  iv_unitPos;      // For chiplets the position
    #     uint8_t  iv_overrideType; // fapi::AttributeOverrideType enum value
    #     uint8_t  iv_arrayD1;      // Applies to element D1 in 1D or more array atts
    #     uint8_t  iv_arrayD2;      // Applies to element D2 in 2D or more array atts
    #     uint8_t  iv_arrayD3;      // Applies to element D3 in 3D or more array atts
    #     uint8_t  iv_arrayD4;      // Applies to element D4 in 4D array atts
    # };

    #--------------------------------------------------------------------------
    # Send the overrides to Hostboot
    #--------------------------------------------------------------------------    
    for (my $i = 0; $i < $numOverrides; $i++)
    {
        # Write override to Hostboot
        my $addr = $overrideAddr;
        ::write64($addr, $overrideVal[$i]);
        $addr += 8;
        ::write32($addr, $attrId[$i]);
        $addr += 4;
        ::write32($addr, $targetType[$i]);
        $addr += 4;
        ::write16($addr, $pos[$i]);
        $addr += 2;
        ::write8($addr, $unitPos[$i]);
        $addr++;
        ::write8($addr, $overrideType[$i]);
        $addr++;
        ::write8($addr, $arrayD1[$i]);
        $addr++;
        ::write8($addr, $arrayD2[$i]);
        $addr++;
        ::write8($addr, $arrayD3[$i]);
        $addr++;
        ::write8($addr, $arrayD4[$i]);

        # Tell Hostboot to process the override
        my $callFuncForce = 0;
        my @callFuncParms;
        Hostboot::CallFunc::execFunc("fapi::platAttrOverrideDirect()",
            $debug, $callFuncForce, \@callFuncParms);

        if ($debug)
        {
            ::userDisplay "$attrIdString[$i] sent\n";
        }
    }

    # The first override is actually an instruction to clear all overrides
    my $actualNum = $numOverrides - 1;
    ::userDisplay "All $actualNum override(s) successfully sent to Hostboot\n";
}

sub helpInfo
{
    my %info = (
        name => "HwpfAttrOverride",
        intro => ["Applies HWPF Attribute Overrides to Hostboot"],
        options => {
                    "debug" => ["More debug output."],
                   },
        notes => ["Looks for two files in the image directory",
                  "$attributeIdFileName: Contains attribute id/enum values",
                  "$overrideFileName: Contains the attribute overrides"]
    );
}
