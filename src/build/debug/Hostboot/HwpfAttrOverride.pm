#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/HwpfAttrOverride.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2019
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

# From src/import/hwpf/fapi2/include/target_types.H
use constant TARGET_TYPE_SYSTEM => 0x00000001;
use constant TARGET_TYPE_DIMM => 0x00000002;
use constant TARGET_TYPE_PROC_CHIP => 0x00000004;
use constant TARGET_TYPE_MEMBUF_CHIP => 0x00000008;
use constant TARGET_TYPE_EX_CHIPLET => 0x00000010;
use constant TARGET_TYPE_MBA_CHIPLET => 0x00000020;
use constant TARGET_TYPE_MCS_CHIPLET => 0x00000040;
use constant TARGET_TYPE_XBUS_ENDPOINT => 0x00000080;
use constant TARGET_TYPE_ABUS_ENDPOINT => 0x00000100;
use constant TARGET_TYPE_CORE => 0x00000400;
use constant TARGET_TYPE_EQ => 0x00000800;
use constant TARGET_TYPE_MCA => 0x00001000;
use constant TARGET_TYPE_MCBIST => 0x00002000;
use constant TARGET_TYPE_MI => 0x00004000;
use constant TARGET_TYPE_CAPP => 0x00008000;
use constant TARGET_TYPE_DMI => 0x00010000;
use constant TARGET_TYPE_OBUS => 0x00020000;
use constant TARGET_TYPE_OBUS_BRICK => 0x00040000;
use constant TARGET_TYPE_SBE => 0x00080000;
use constant TARGET_TYPE_PPE => 0x00100000;
use constant TARGET_TYPE_PERV => 0x00200000;
use constant TARGET_TYPE_PEC => 0x00400000;
use constant TARGET_TYPE_PHB => 0x00800000;
use constant TARGET_TYPE_L4 =>  0x00000200;
use constant TARGET_TYPE_MC => 0x01000000;
use constant TARGET_TYPE_MCC => 0x08000000;
use constant TARGET_TYPE_OMIC => 0x04000000;
use constant TARGET_TYPE_OMI => 0x02000000;
use constant TARGET_TYPE_OMIC => 0x04000000;
use constant TARGET_TYPE_OCMB => 0x10000000;
use constant TARGET_TYPE_MEM_PORT =>  0x20000000;

# From attributeTank.H
use constant ATTR_POS_NA => 0xffff;
use constant ATTR_UNIT_POS_NA => 0xff;
use constant ATTR_NODE_NA => 0xf;
use constant ATTR_FLAG_CONST => 1;

# From plat_attr_override_sync.C
use constant MAX_DIRECT_OVERRIDE_ATTR_SIZE_BYTES => 64;
my $overrideHeaderSymbol = 'fapi2::g_attrOverrideHeader';
my $overrideSymbol = 'fapi2::g_attrOverride';
my $overrideFapiTankSymbol = 'fapi2::g_attrOverrideFapiTank';

# Expected filenames
my $fapiAttrInfoFileName = 'attrInfo.csv';
my $fapiAttrEnumInfoFileName = 'attrEnumInfo.csv';
my $targAttrInfoFileName = 'targAttrInfo.csv';
my $overrideFileName = 'OverrideAttrs.txt';

sub main
{
    my ($packName,$args) = @_;
    my $debug = 0;
    if (defined $args->{"debug"})
    {
        $debug = 1;
    }

    #--------------------------------------------------------------------------
    # Get the address of the Hostboot Attribute Override variables
    #--------------------------------------------------------------------------
    my $overrideHeaderSymAddr = (::findSymbolAddress("$overrideHeaderSymbol"))[0];

    if (not defined $overrideHeaderSymAddr)
    {
        ::userDisplay "Cannot find Hostboot symbol '$overrideHeaderSymbol'\n";
        die;
    }

    my $overrideHeaderAddr = Hostboot::_DebugFrameworkVMM::getPhysicalAddr(
        $overrideHeaderSymAddr, $debug, 0);

    if ($overrideHeaderAddr eq Hostboot::_DebugFrameworkVMM::NotFound)
    {
        ::userDisplay "Cannot translate '$overrideHeaderSymbol' to a phys addr\n";
        die;
    }

    #--------------------------------------------------------------------------
    my $overrideSymAddr = (::findSymbolAddress("$overrideSymbol"))[0];

    if (not defined $overrideSymAddr)
    {
        ::userDisplay "Cannot find Hostboot symbol '$overrideSymbol'\n";
        die;
    }

    my $overrideAddr = Hostboot::_DebugFrameworkVMM::getPhysicalAddr(
        $overrideSymAddr, $debug, 0);

    if ($overrideAddr eq Hostboot::_DebugFrameworkVMM::NotFound)
    {
        ::userDisplay "Cannot translate '$overrideSymbol' to a phys addr\n";
        die;
    }

    #--------------------------------------------------------------------------
    my $overrideFapiTankSymAddr = (::findSymbolAddress("$overrideFapiTankSymbol"))[0];

    if (not defined $overrideFapiTankSymAddr)
    {
        ::userDisplay "Cannot find Hostboot symbol '$overrideFapiTankSymbol'\n";
        die;
    }

    my $overrideFapiTankAddr = Hostboot::_DebugFrameworkVMM::getPhysicalAddr(
        $overrideFapiTankSymAddr, $debug, 0);

    if ($overrideFapiTankAddr eq Hostboot::_DebugFrameworkVMM::NotFound)
    {
        ::userDisplay "Cannot translate '$overrideFapiTankSymbol' to a phys addr\n";
        die;
    }

    #--------------------------------------------------------------------------
    # Check if the Attribute info and Override files exist
    #--------------------------------------------------------------------------
    my $fapiAttrInfoFile = ::getImgPath();
    $fapiAttrInfoFile .= "$fapiAttrInfoFileName";
    unless (-e $fapiAttrInfoFile)
    {
        die "Cannot find file '$fapiAttrInfoFile'";
    }

    my $fapiAttrEnumInfoFile = ::getImgPath();
    $fapiAttrEnumInfoFile .= "$fapiAttrEnumInfoFileName";
    unless (-e $fapiAttrEnumInfoFile)
    {
        die "Cannot find file '$fapiAttrEnumInfoFile'";
    }

    my $targAttrInfoFile = ::getImgPath();
    $targAttrInfoFile .= "$targAttrInfoFileName";
    unless (-e $targAttrInfoFile)
    {
        die "Cannot find file '$targAttrInfoFile'";
    }

    my $overrideFile = ::getImgPath();
    $overrideFile = $overrideFile."$overrideFileName";
    unless (-e $overrideFile)
    {
        die "Cannot find file '$overrideFile'";
    }

    #--------------------------------------------------------------------------
    # Process the FAPI Attribute Info file. Record the ATTR-ID-VAL and
    # ATTR-TYPE in a hash indexed by ATTR-ID-STR. Note that for FAPI Attributes
    # FAPI-ATTR-ID-STR and LAYER-ATTR-ID-STR will be identical
    #
    # Format: <FAPI-ATTR-ID-STR>,<LAYER-ATTR-ID-STR>,<ATTR-ID-VAL>,<ATTR-TYPE>
    #--------------------------------------------------------------------------
    my %fapiAttrInfo;

    open(FAPIATTFILE, "< $fapiAttrInfoFile") or die
        "Cannot open file '$fapiAttrInfoFile'";
    while (my $line = <FAPIATTFILE>)
    {
        chomp($line);

        # Skip comment lines
        if (!($line =~ /^#/))
        {
            if ($line =~ /(ATTR_\S+),ATTR_\S+,0x(\S+),(\S+)/)
            {
                $fapiAttrInfo{$1}->{idVal} = hex $2;
                $fapiAttrInfo{$1}->{typeStr} = $3;
            }
        }
    }
    close(FAPIATTFILE);

    #--------------------------------------------------------------------------
    # Process the TARG Attribute Info file. Record the ATTR-ID-VAL and
    # ATTR-TYPE in a hash indexed by ATTR-ID-STR. Note that for TARG Attributes
    # FAPI-ATTR-ID-STR and LAYER-ATTR-ID-STR may be different and if the
    # TARG attribute does not map to a FAPI attribute then FAPI-ATTR-ID-STR
    # will be NO-FAPI-ID
    #
    # Format: <FAPI-ATTR-ID-STR>,<LAYER-ATTR-ID-STR>,<ATTR-ID-VAL>,<ATTR-TYPE>
    #--------------------------------------------------------------------------
    my %targAttrInfo;

    open(TARGATTFILE, "< $targAttrInfoFile") or die
        "Cannot open file '$targAttrInfoFile'";
    while (my $line = <TARGATTFILE>)
    {
        chomp($line);

        # Skip comment lines
        if (!($line =~ /^#/))
        {
            if ($line =~ /(\S+),(ATTR_\S+),0x(\S+),(\S+)/)
            {
                if ($1 ne "NO-FAPI-ID")
                {
                    $targAttrInfo{$1}->{idVal} = hex $3;
                    $targAttrInfo{$1}->{typeStr} = $4;
                }

                $targAttrInfo{$2}->{idVal} = hex $3;
                $targAttrInfo{$2}->{typeStr} = $4;
            }
        }
    }
    close(TARGATTFILE);

    #--------------------------------------------------------------------------
    # Process the FAPI Attribute Enum Info file. Record the values of the
    # Attribute ENUMs in a hash
    #--------------------------------------------------------------------------
    my %fapiAttrEnumVals;

    open(ENUMFILE, "< $fapiAttrEnumInfoFile") or die
        "Cannot open file '$fapiAttrEnumInfoFile'";
    while (my $line = <ENUMFILE>)
    {
        # Note that enumerated values can end with 'ULL'
        if ($line =~ /(ATTR_\S+) = 0x([a-fA-F0-9]+)/)
        {
            # Found a hex attribute value enumeration
            $fapiAttrEnumVals{$1} = hex $2;
        }
        elsif ($line =~ /(ATTR_\S+) = ([0-9]+)/)
        {
            # Found a decimal attribute value enumeration
            $fapiAttrEnumVals{$1} = $2;
        }
    }
    close(ENUMFILE);

    #--------------------------------------------------------------------------
    # Process the Attribute Overrides file
    #--------------------------------------------------------------------------
    my $targLine = "";
    my $numOverrides = 0;
    my $attrString = "";
    my @attrLines;

    #--------------------------------------------------------------------------
    # Iterate over all lines in the Attribute Overrides file
    #--------------------------------------------------------------------------
    open(OVFILE, "< $overrideFile") or die "Cannot open file '$overrideFile'";
    my $line = <OVFILE>;
    while ($line ne "")
    {
        #----------------------------------------------------------------------
        # Find all lines making up a single attribute override. There are
        # multiple lines for a multi-dimensional attribute
        #----------------------------------------------------------------------
        $attrString = "";
        @attrLines = ();

        while ($line ne "")
        {
            chomp($line);

            if ($line =~ /^target/)
            {
                if ($attrString eq "")
                {
                    # Not currently processing attribute lines, save the target
                    # line, it is for following attribute lines
                    $targLine = $line;
                    $line = <OVFILE>;
                    last;
                }
                else
                {
                    # Currently processing attribute lines. Break out of the
                    # loop to process the current set and look at this target
                    # line in the next iteration
                    last;
                }
            }
            elsif ($line =~ /^(ATTR_\w+)/)
            {
                # Found an attribute override line
                if ($attrString eq "")
                {
                    # First override line for an attribute
                    $attrString = $1;
                }
                elsif ($attrString ne $1)
                {
                    # Override line for a different attribute. Break out of the
                    # loop to process the current attribute override and look
                    # at this line in the next main loop
                    last;
                }

                # Add the attribute override line to the set of lines to
                # process for a single override and get the next line
                push(@attrLines, $line);
                $line = <OVFILE>;
            }
            else
            {
                # Not a target or attribute line, get the next line
                $line = <OVFILE>;
            }
        } # end of finding all lines making up a single attr override

        if (scalar(@attrLines) > 0)
        {
            #------------------------------------------------------------------
            # Process the set of lines making up a single attribute override
            #------------------------------------------------------------------
            my $attrIdStr = "";
            my $attrIdVal = 0;
            my $fapiTank = 0;
            my $elemSize = 0;
            my $d1 = 1; # First dimension of the attribute
            my $d2 = 1;
            my $d3 = 1;
            my $d4 = 1;
            my $valSize = 0;
            my $flags = 0;

            foreach my $attrLine(@attrLines)
            {
                my $td1 = 0; # First dimension of this line's element
                my $td2 = 0;
                my $td3 = 0;
                my $td4 = 0;
                my $val = 0;

                if ($attrIdStr eq "")
                {
                    # This is the first line, figure out the attrIdStr
                    if ($attrLine =~ /^(ATTR_\w+)/)
                    {
                        $attrIdStr = $1;
                    }
                    else
                    {
                        ::userDisplay "Cannot find attr id str in '$attrLine'\n";
                        die;
                    }

                    # Use the data gathered from the AttrInfo files to figure out
                    # the attrIdVal, typeStr and tank Info
                    my $typeStr = "";

                    if (exists $targAttrInfo{$attrIdStr})
                    {
                        $attrIdVal = $targAttrInfo{$attrIdStr}->{idVal};
                        $typeStr = $targAttrInfo{$attrIdStr}->{typeStr};
                        $fapiTank = 0;
                    }
                    elsif (exists $fapiAttrInfo{$attrIdStr})
                    {
                        $attrIdVal = $fapiAttrInfo{$attrIdStr}->{idVal};
                        $typeStr = $fapiAttrInfo{$attrIdStr}->{typeStr};
                        $fapiTank = 1;
                    }
                    else
                    {
                        ::userDisplay "Cannot find '$attrIdStr' in attribute info files\n";
                        die;
                    }

                    # Figure out the attribute element size
                    if ($typeStr =~ /^u8/)
                    {
                        $elemSize = 1;
                    }
                    elsif ($typeStr =~ /^u16/)
                    {
                        $elemSize = 2;
                    }
                    elsif ($typeStr =~ /^u32/)
                    {
                        $elemSize = 4;
                    }
                    elsif ($typeStr =~ /^u64/)
                    {
                        $elemSize = 8;
                    }
                    else
                    {
                        ::userDisplay "Bad type string '$typeStr' in attribute info file\n";
                        die;
                    }

                    # Remove the attribute element type from typeStr
                    $typeStr =~ s/u\w+//;

                    # Figure out the attribute array dimensions
                    if ($typeStr =~ /^\[(\d+)\]/)
                    {
                        $d1 = $1;
                    }
                    if ($typeStr =~ /^\[\d+\]\[(\d+)\]/)
                    {
                        $d2 = $1;
                    }
                    if ($typeStr =~ /^\[\d+\]\[\d+\]\[(\d+)\]/)
                    {
                        $d3 = $1;
                    }
                    if ($typeStr =~ /^\[\d+\]\[\d+\]\[\d+\]\[(\d+)\]/)
                    {
                        $d4 = $1;
                    }

                    # Calculate the attribute value size
                    $valSize = $elemSize * $d1 * $d2 * $d3 * $d4;

                    if ($valSize > MAX_DIRECT_OVERRIDE_ATTR_SIZE_BYTES)
                    {
                        ::userDisplay "Attribute size too big ($valSize bytes) to directly override\n";
                        die;
                    }
                }

                # Figure out this element's dimensions
                if ($attrLine =~ /^ATTR_\w+\[(\d+)\]/)
                {
                    $td1 = $1;
                }
                if ($attrLine =~ /^ATTR_\w+\[\d+\]\[(\d+)\]/)
                {
                    $td2 = $1;
                }
                if ($attrLine =~ /^ATTR_\w+\[\d+\]\[\d+\]\[(\d+)\]/)
                {
                    $td3 = $1;
                }
                if ($attrLine =~ /^ATTR_\w+\[\d+\]\[\d+\]\[\d+\]\[(\d+)\]/)
                {
                    $td4 = $1;
                }

                # Check for overflow
                if (($td1 >= $d1) || ($td2 >= $d2) || ($td3 >= $d3) ||
                    ($td4 >= $d4))
                {
                    ::userDisplay "Attribute '$attrLine' overflows its array\n";
                    ::userDisplay "$td1:$d1:$td2:$d2:$td3:$d3:$td4:$d4\n";
                    die;
                }

                # Remove the Attribute ID and any dimensions from the line
                $attrLine =~ s/^ATTR_\S+\s+//;

                # If the line includes a type field then remove it
                $attrLine =~ s/^u8\S*\s+//;
                $attrLine =~ s/^u16\S*\s+//;
                $attrLine =~ s/^u32\S*\s+//;
                $attrLine =~ s/^u64\S*\s+//;

                # Figure out the override value
                if ($attrLine =~ /^([A-Za-z]+\S*)/)
                {
                    # enumerator
                    my $enum = "$attrIdStr"."_$1";
                    if (exists $fapiAttrEnumVals{$enum})
                    {
                        $val = $fapiAttrEnumVals{$enum};
                    }
                    else
                    {
                        ::userDisplay "Cannot find enum '$enum' in '$fapiAttrEnumInfoFile'\n";
                        die;
                    }
                }
                elsif ($attrLine =~ /^0x([0-9A-Za-z]+)/)
                {
                    # Hex value
                    $val = hex $1;
                }
                elsif ($attrLine =~ /^(\d+)/)
                {
                    # Decimal Value
                    $val = $1;
                }
                else
                {
                    ::userDisplay "Cannot find override value for '$attrIdStr'\n";
                    die;
                }

                # Figure out if it is a const override
                if ($attrLine =~ /CONST\s*/)
                {
                    $flags = ATTR_FLAG_CONST;
                }

                # Write element to Hostboot memory
                my $addr = $overrideAddr;

                my $elemNum = $td4 + ($td3*$d4) + ($td2*$d3*$d4) +
                              ($td1*$d2*$d3*$d4);
                $addr += $elemNum * $elemSize;

                if ($elemSize == 1)
                {
                    ::write8($addr, $val);
                }
                elsif ($elemSize == 2)
                {
                    ::write16($addr, $val);
                }
                elsif ($elemSize == 4)
                {
                    ::write32($addr, $val);
                }
                elsif ($elemSize == 8)
                {
                    ::write64($addr, $val);
                }

            } # end of processing all lines making up a single attr override

            #------------------------------------------------------------------
            # Figure out the Target node/type/pos/unitpos
            #------------------------------------------------------------------
            my $targType = TARGET_TYPE_SYSTEM;
            my $targPos = ATTR_POS_NA;
            my $targUnitPos = ATTR_UNIT_POS_NA;
            my $targNode = ATTR_NODE_NA;
            my $targ = $targLine;

            # Figure out the node number
            if ($targ =~ /target = k0:n0:s0:?\s*$/)
            {
                # String representing system target
                $targNode = ATTR_NODE_NA;
            }
            elsif ($targ =~ /target = k0:n(\d+)/)
            {
                $targNode = $1;
            }

            # Figure out the target type
            if ($targ =~ /pu.ex/)
            {
                $targType = TARGET_TYPE_EX_CHIPLET;
                $targ =~ s/^.*pu.ex//;
            }
            elsif ($targ =~ /pu.core/)
            {
                $targType = TARGET_TYPE_CORE;
                $targ =~ s/^.*pu.core//;
            }
            elsif ($targ =~ /pu.dmi/)
            {
                $targType = TARGET_TYPE_DMI;
                $targ =~ s/^.*pu.dmi//;
            }
            elsif ($targ =~ /pu.mcs/)
            {
                $targType = TARGET_TYPE_MCS_CHIPLET;
                $targ =~ s/^.*pu.mcs//;
            }
            elsif ($targ =~ /pu.xbus/)
            {
                $targType = TARGET_TYPE_XBUS_ENDPOINT;
                $targ =~ s/^.*pu.xbus//;
            }
            elsif ($targ =~ /pu.abus/)
            {
                $targType = TARGET_TYPE_ABUS_ENDPOINT;
                $targ =~ s/^.*pu.abus//;
            }
            elsif ($targ =~ /dimm/)
            {
                $targType = TARGET_TYPE_DIMM;
                $targ =~ s/^.*dimm//;
            }
            elsif ($targ =~ /pu/)
            {
                $targType = TARGET_TYPE_PROC_CHIP;
                $targ =~ s/^.*pu//;
            }
            elsif ($targ =~ /pu.obus/)
            {
                $targType = TARGET_TYPE_OBUS;
                $targ =~ s/^.*pu.obus//;
            }
            elsif ($targ =~ /pu.mcbist/)
            {
                $targType = TARGET_TYPE_MCBIST;
                $targ =~ s/^.*pu.mcbist//;
            }
            elsif ($targ =~ /pu.mca/)
            {
                $targType = TARGET_TYPE_MCA;
                $targ =~ s/^.*pu.mca//;
            }
            elsif ($targ =~ /pu.pec/)
            {
                $targType = TARGET_TYPE_PEC;
                $targ =~ s/^.*pu.pec//;
            }
            elsif ($targ =~ /pu.phb/)
            {
                $targType = TARGET_TYPE_PHB;
                $targ =~ s/^.*pu.phb//;
            }
            elsif ($targ =~ /pu.obrick/)
            {
                $targType = TARGET_TYPE_OBUS_BRICK;
                $targ =~ s/^.*pu.obrick//;
            }
            elsif ($targ =~ /pu.ppe/)
            {
                $targType = TARGET_TYPE_PPE;
                $targ =~ s/^.*pu.ppe//;
            }
            elsif ($targ =~ /pu.perv/)
            {
                $targType = TARGET_TYPE_PERV;
                $targ =~ s/^.*pu.perv//;
            }
            elsif ($targ =~ /pu.capp/)
            {
                $targType = TARGET_TYPE_CAPP;
                $targ =~ s/^.*pu.capp//;
            }
            elsif ($targ =~ /pu.eq/)
            {
                $targType = TARGET_TYPE_EQ;
                $targ =~ s/^.*pu.eq//;
            }
            elsif ($targ =~ /memb.l4/)
            {
                $targType = TARGET_TYPE_L4;
                $targ =~ s/^.*memb.l4//;
            }
            elsif ($targ =~ /pu.mc/)
            {
                $targType = TARGET_TYPE_MC;
                $targ =~ s/^.*pu.mc//;
            }
            elsif ($targ =~ /pc.mcc/)
            {
                $targType = TARGET_TYPE_MCC;
                $targ =~ s/^.*pu.mcc//;
            }
            elsif ($targ =~ /pu.omi/)
            {
                $targType = TARGET_TYPE_OMI;
                $targ =~ s/^.*pu.omi//;
            }
            elsif ($targ =~ /memb.omic/)
            {
                $targType = TARGET_TYPE_OMIC;
                $targ =~ s/^.*memb.omic//;
            }
            elsif ($targ =~ /ocmb/)
            {
                $targType = TARGET_TYPE_OCMB;
                $targ =~ s/^.*ocmb//;
            }
            elsif ($targ =~ /ocmb.mp/)
            {
                $targType = TARGET_TYPE_MEM_PORT;
                $targ =~ s/^.*ocmb.mp//;
            }

            # Figure out the position
            if ($targ =~ /:p(\d+)/)
            {
                $targPos = $1;
            }
            else
            {
                $targPos = ATTR_POS_NA;
            }

            # Figure out the unit position
            if ($targ =~ /:c(\d+)/)
            {
                $targUnitPos = $1;
            }
            else
            {
                $targUnitPos = ATTR_UNIT_POS_NA;
            }

            # Debug output
            if ($debug)
            {
                if ($fapiTank)
                {
                    ::userDisplay "FAPI OVERRIDE.";
                }
                else
                {
                    ::userDisplay "TARG OVERRIDE.";
                }
                ::userDisplay "ID: $attrIdVal, Node: $targNode,";
                ::userDisplay "TargType: $targType, Pos: $targPos,";
                ::userDisplay "UPos: $targUnitPos, Flags: $flags\n";
            }

            #------------------------------------------------------------------
            # Write the overide to Hostboot memory
            #------------------------------------------------------------------
            # From attributeTank.H
            # struct AttributeHeader
            # {
            #     uint32_t iv_attrId;     // Attribute ID
            #     uint32_t iv_targetType; // Target Type attribute is for
            #     uint16_t iv_pos;        // For chips/dimms the position
            #                             // For chiplets the parent chip position
            #     uint8_t  iv_unitPos;    // For chiplets the position
            #     uint8_t  iv_node  : 4;  // Target Node number
            #     uint8_t  iv_flags : 4;  // AttributeFlags enum value(s)
            #     uint32_t iv_valSize;    // Size of the attribute value in bytes
            # };
            my $addr = $overrideHeaderAddr;
            ::write32($addr, $attrIdVal);
            $addr += 4;
            ::write32($addr, $targType);
            $addr += 4;
            ::write16($addr, $targPos);
            $addr += 2;
            ::write8($addr, $targUnitPos);
            $addr += 1;
            ::write8($addr, (($targNode << 4) + $flags));
            $addr += 1;
            ::write32($addr, $valSize);

            $addr = $overrideFapiTankAddr;
            ::write8($addr, $fapiTank);

            #------------------------------------------------------------------
            # Tell Hostboot to apply the override
            #------------------------------------------------------------------
            my $callFuncForce = 0;
            my @callFuncParms;
            Hostboot::CallFunc::execFunc("fapi2::directOverride()",
                $debug, $callFuncForce, \@callFuncParms);

            if ($debug)
            {
                ::userDisplay "$attrIdStr sent\n";
            }

            $numOverrides++;

        } # end of if there is an atribute override to process

    } # end of iterating over all lines in an attr override file

    close(OVFILE);

    ::userDisplay "All $numOverrides override(s) successfully sent to Hostboot\n";
}

sub helpInfo
{
    my %info = (
        name => "HwpfAttrOverride",
        intro => ["Applies HWPF Attribute Overrides to Hostboot"],
        options => {
                    "debug" => ["More debug output."],
                   },
        notes => ["Looks for four files in the image directory",
                  "$fapiAttrInfoFileName: Contains FAPI attribute info",
                  "$fapiAttrEnumInfoFileName: Contains FAPI attribute enum info",
                  "$targAttrInfoFileName: Contains TARG attribute info",
                  "$overrideFileName: Contains the attribute overrides"]
    );
}

