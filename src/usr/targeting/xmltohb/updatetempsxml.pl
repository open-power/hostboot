#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/xmltohb/updatetempsxml.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2016
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
# Original file, updatetargetxml.pl, created for fsp.
# File copied to Hostboot and modified
# File used as basis for updatetempsxml.pl
#
# Usage:
#
#    updatetempsxml --generic=temp_generic.xml
#                   --fapi=fapiattrs.xml
#                   --fapi_inc=fapi2PlatAttrService.H
#                   --fw_dflts=hb_temp_defaults.xml
#                   --defaults=tempdefaults.xml
#
# Purpose:
#
#   This perl script processes the fapiattrs.xml and hb_temp_defaults.xml
#   files to find any new attributes which need to be defined in the
#   generic.xml file.  It also process the tempdefaults.xml file to find the
#   <tempDefault> tags and any new attribute definitions so that generic.xml
#   can be updated with default values and attribute definitions as needed.
#   The updated generic.xml is written to the console.
#

use strict;
use XML::Simple;
use Data::Dumper;


$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

my $generic = "";
my $fapi = "";
my $fapi_inc = "";
my $fw_dflts = "";
my $defaults = "";
my $usage = 0;
use Getopt::Long;
GetOptions( "generic:s"  => \$generic,
            "fapi:s"     => \$fapi,
            "fapi_inc:s" => \$fapi_inc,
            "fw_dflts:s" => \$fw_dflts,
            "defaults:s" => \$defaults,
            "help"       => \$usage, );

if (($generic eq "") || ($fapi eq "") || ($fapi_inc eq "") ||
    ($fw_dflts eq "") || ($defaults eq ""))
{
    display_help();
    exit 1;
}
elsif ($usage)
{
    display_help();
    exit 0;
}


open (FH, "<$generic") ||
    die "ERROR: unable to open $generic\n";
close (FH);

my $genericXml = XMLin("$generic");
my $genericXmlArray = XMLin("$generic", ForceArray=>1);

open (FH, "<$fapi") ||
    die "ERROR: unable to open $fapi\n";
close (FH);

my $fapiXml = XMLin("$fapi", ForceArray=>1);

open (FH, "<$fapi_inc") ||
    die "ERROR: unable to open $fapi_inc\n";
close (FH);

open (FH, "<$fw_dflts") ||
    die "ERROR: unable to open $fw_dflts\n";
close (FH);

my $fwDfltsXml = XMLin("$fw_dflts", ForceArray=>1);

open (FH, "<$defaults") ||
    die "ERROR: unable to open $defaults\n";
close (FH);

my $defaultsXml = XMLin("$defaults", ForceArray=>1);


# Walk through temp_generic.xml file looking for target types
my @TgtTypeInfo;

foreach my $TgtType ( @{$genericXmlArray->{targetType}} )
{
    my $TgtTypeType = "";
    my $TgtTypeAttrIds = " ";

    # Find attributes for this target type
    foreach my $TgtTypeAttr ( @{$TgtType->{attribute}} )
    {
        # Find default for TYPE attribute
        if($TgtTypeAttr->{id}->[0] eq "TYPE")
        {
            if(exists $TgtTypeAttr->{default})
            {
                $TgtTypeType = $TgtTypeAttr->{default}->[0];
            }
            elsif($TgtType->{id}->[0] ne "base")
            {
                print STDERR "Target ".$TgtType->{id}->[0].
                    " has TYPE attribute without a value\n";
            }
        }
        # Record IDs of all other attributes for this target type
        else
        {
            $TgtTypeAttrIds .= $TgtTypeAttr->{id}->[0]." ";
        }
    }

    # Create entry with information for this target type
    if($TgtTypeType ne "")
    {
        push @TgtTypeInfo, [ $TgtType->{id}->[0], $TgtTypeType,
                             $TgtTypeAttrIds ];
    }
}


# Walk through hb_temp_defaults.xml file looking for new FAPI attributes
my @NewAttr;
my @UpdtTgt;

foreach my $TempAttr ( @{$fwDfltsXml->{attribute}} )
{
    my $fapi_attr = "";
    my $fapi_id = $TempAttr->{id}->[0];
#    print STDERR "Processing FAPI Id $fapi_id\n";
    my $generic_id = $fapi_id;
    $generic_id =~ s/ATTR_//;
    my $found = 0;

    my $persistency = "volatile";

    # First, check if attribute definition exists in fapiattrs.xml
    foreach my $FapiAttr ( @{$fapiXml->{attribute}} )
    {
        if ($FapiAttr->{id}->[0] eq $fapi_id)
        {
            $found = 1;
            $fapi_attr = $FapiAttr;

            # Check if FAPI attribute is associated with specific target types
            if (exists $FapiAttr->{targetType})
            {
                my @types = split(',',$FapiAttr->{targetType}->[0]);
                foreach my $type(@types)
                {
                    $type =~ s/\s//g;
                    $type =~ s/TARGET_TYPE_//;
                    $type =~ s/_ENDPOINT//;
                    $type =~ s/_CHIPLET//;
                    $type =~ s/_CHIP//;

                    # Loop through target type info from temp_generic.xml file
                    for my $i ( 0 .. $#TgtTypeInfo)
                    {
                        # Check for entry of specified target type without a
                        # definition of the given attribute
                        if(($TgtTypeInfo[$i][1] eq $type) &&
                           !($TgtTypeInfo[$i][2] =~ /\s$generic_id\s/))
                        {
                            # Determine if default exists for the update
                            if (exists $TempAttr->{default})
                            {
                                push @UpdtTgt, [ $TgtTypeInfo[$i][0], $type,
                                                 $generic_id,
                                                 $TempAttr->{default}->[0]];
                            }
                            else
                            {
                                push @UpdtTgt, [ $TgtTypeInfo[$i][0], $type,
                                                 $generic_id, ""];
                            }
                        }
                        elsif($TgtTypeInfo[$i][2] =~ /\s$generic_id\s/)
                        {
                            print STDERR "Target $TgtTypeInfo[$i][0] of type ".
                                  "$type already has attribute $generic_id\n";
                        }
                    }
                }
            }

            # Non-platInit attributes need to be volatile-zeroed
            #  or xmltohb.pl will throw an error
            if( !(exists $FapiAttr->{platInit}) )
            {
                $persistency = "volatile-zeroed";
            }

            last;
        }
    }
    die "FATAL: FAPI attribute definition not found in $fapi for "
        . "$fapi_id\n" if($found == 0);

    # Second, check if handling already exists in fapi2PlatAttrService.H
    $found = 0;
    open (FH, "<$fapi_inc");
    while (my $line = <FH>)
    {
        # Check if line starts a GETMACRO or SETMACRO #define statement
        if (($line =~ /^\s*\#define\s*(ATTR_.*)_(.ETMACRO).*/) &&
            ($1 eq $fapi_id))
        {
            print STDERR "Existing handling found in $fapi_inc for "
                . "$fapi_id\n";
            $found = 1;
            last;
        }
    }
    close (FH);
    next if($found);

    # Third, check if mapping already exists in generic.xml
    $found = 0;
    foreach my $GenericAttr ( @{$genericXmlArray->{attribute}} )
    {
        # Check for attribute mapping
        if (exists $GenericAttr->{hwpfToHbAttrMap})
        {
            my $GenericMap = $GenericAttr->{hwpfToHbAttrMap}->[0];

            # Check if FAPI and generic attributes are mapped to each other
            if ($GenericMap->{id}->[0] eq $fapi_id)
            {
                print STDERR "Existing mapping found in $generic for "
                    . "$fapi_id\n";
                $found = 1;
                last;
            }
        }
    }
    next if($found);

    # Collect information for creating attribute and enumeration definitions
    my $description = $fapi_attr->{description}->[0];

    my $valueType = $fapi_attr->{valueType}->[0];
    $valueType =~ s/(uint\d*)/$1_t/ if($valueType =~ /^uint\d*/);

    my $fwDefault = "";
    if (exists $TempAttr->{default})
    {
        $fwDefault = $TempAttr->{default}->[0];
    }

    my $array = "";
    if(exists $fapi_attr->{array})
    {
        my @dimensions = split(' ',$fapi_attr->{array}->[0]);
        $array = @dimensions[0];
        for my $i ( 1 .. $#dimensions )
        {
            $array .= ",$dimensions[$i]";
        }
    }

    # Create enumeration definition to support generic attribute if FAPI
    # attribute associated with temp FW default uses enum
    my $enum_id = "";
    my $enumDefault = "";
    if(exists $fapi_attr->{enum})
    {
        $enum_id = $generic_id;
        push @NewAttr, [ "<enumerationType>\n" ];
        push @NewAttr, [ "    <id>$enum_id</id>\n" ];
        push @NewAttr, [ "    <description>\n" ];
        push @NewAttr, [ "        Enumeration for FAPI attribute $fapi_id\n" ];
        push @NewAttr, [ "    </description>\n" ];

        my @enum_defs = split(',',$fapi_attr->{enum}->[0]);
        for my $i ( 0 .. $#enum_defs )
        {
            $enum_defs[$i] =~ /^\s*(.*)\s*=\s*(.*)\s*/;
            my $enumName = $1;
            my $enumValue = $2;
            $enumName =~ s/ //;
            $enumDefault = $enumName if($fwDefault eq $enumValue);
            push @NewAttr, [ "    <enumerator>\n" ];
            push @NewAttr, [ "        <name>$enumName</name>\n" ];
            push @NewAttr, [ "        <value>$enumValue</value>\n" ];
            push @NewAttr, [ "    </enumerator>\n" ];
        }

        push @NewAttr, [ "    <default>$enumDefault</default>\n" ]
            if($enumDefault ne "");

        push @NewAttr, [ "</enumerationType>\n\n" ];
    }

    # Create generic attribute with mapping
    push @NewAttr, [ "<attribute>\n" ];
    push @NewAttr, [ "    <id>$generic_id</id>\n" ];
    push @NewAttr, [ "    <description>\n" ];
    push @NewAttr, [ "        $description\n" ];
    push @NewAttr, [ "    </description>\n" ];
    push @NewAttr, [ "    <simpleType>\n" ];
    if($enumDefault ne "")
    {
        push @NewAttr, [ "        <enumeration>\n" ];
        push @NewAttr, [ "            <id>$enum_id</id>\n" ];
        push @NewAttr, [ "            <default>$enumDefault</default>\n" ];
        push @NewAttr, [ "        </enumeration>\n" ];
    }
    elsif($fwDefault ne "")
    {
        push @NewAttr, [ "        <$valueType>\n" ];
        push @NewAttr, [ "            <default>$fwDefault</default>\n" ];
        push @NewAttr, [ "        </$valueType>\n" ];
    }
    elsif($enum_id ne "")
    {
        push @NewAttr, [ "        <enumeration>\n" ];
        push @NewAttr, [ "            <id>$enum_id</id>\n" ];
        push @NewAttr, [ "        </enumeration>\n" ];
    }
    else
    {
        push @NewAttr, [ "        <$valueType></$valueType>\n" ];
    }
    push @NewAttr, [ "        <array>$array</array>\n" ] if($array ne "");
    push @NewAttr, [ "    </simpleType>\n" ];
    push @NewAttr, [ "    <persistency>$persistency</persistency>\n" ];
    push @NewAttr, [ "    <readable/>\n" ];
    push @NewAttr, [ "    <writeable/>\n" ] if(exists $fapi_attr->{writeable});
    push @NewAttr, [ "    <hasStringConversion/>\n" ] if($enum_id ne "");
    push @NewAttr, [ "    <hwpfToHbAttrMap>\n" ];
    push @NewAttr, [ "        <id>$fapi_id</id>\n" ];
    push @NewAttr, [ "        <macro>DIRECT</macro>\n" ];
    push @NewAttr, [ "    </hwpfToHbAttrMap>\n" ];
    push @NewAttr, [ "    <tempAttribute/>\n" ];
    push @NewAttr, [ "</attribute>\n" ];
    push @NewAttr, [ "\n" ];
}


# Check tempdefaults.xml for <tempDefault> entries which are setting temporary
# default values for existing attributes going into the generic.xml file
my @ChgAttr;

foreach my $Default ( @{$defaultsXml->{tempDefault}} )
{
    foreach my $attr ( @{$Default->{attribute}} )
    {
        my $attribute_id = $attr->{id}->[0];
        my $default = "";
        my $force = "n";

        # Check entry for setting a default value
        if (exists $attr->{default})
        {
            $default = $attr->{default}->[0];
        }

        # Check entry for forcing the default setting
        if (exists $attr->{force})
        {
            $force = "y";
        }

        # Check that the temporary default is for an existing attribute
        if (exists $genericXml->{attribute}->{$attribute_id})
        {
            # Check that temporary default was set for the attribute, that is,
            # <default> was specified and value was set
            if (($default ne "") && !($default =~ /^HASH\(0x.*\)/))
            {
#                print STDERR "[ $attribute_id, $default, $force ]\n";
                push @ChgAttr, [ $attribute_id, $default, $force ];
            }
            else
            {
                die "ERROR: Attribute $attribute_id default not specified\n";
            }
        }
        else
        {
            die "ERROR: Attribute $attribute_id definition not found\n";
        }
    }
}


# Check tempdefaults.xml for <attribute> and <enumerationType> entries to be
# appended to the generic.xml file and for <tempDefault> entries to be ignored.
# Save <attribute> and <enumerationType> entry lines in @NewAttr so that they
# can be appended to the generic.xml file later.
use constant
{
    stateFindEntry      =>  0,  # Find start of an <attribute>,
                                # <enumerationType>, or <tempDefault> entry
                                # in the tempdefaults.xml file
    stateFindID         =>  1,  # Find ID field in the current entry
    stateFindEntryEnd   =>  2,  # Find end of the current entry
    stateTempDefault    => -1,  # Find end of the <tempDefault> entry
};

my $state = stateFindEntry; # First find an entry
my $count = 0;
my $id = "";
my $type = "";

open (FH, "<$defaults");

while (my $line = <FH>)
{
    # Check if line starts an <attribute> and <enumerationType> entry
    if ($state == stateFindEntry &&
        $line =~ /^\s*<(attribute|enumerationType)>.*/)
    {
        $state = stateFindID; # Next find the ID within this entry
        $type = $1;
        push @NewAttr, [ $line ];
        $count = 1;
    }
    # Check if line specifies the ID of the entry
    elsif ($state == stateFindID && $line =~ /^\s*<id>/)
    {
        $state = stateFindEntryEnd; # Now find the end of this entry
        $id = $line;
        $id =~ s/\n//;
        $id =~ s/.*<id>(.*)<\/id>.*/$1/;

        # Check that the ID doesn't already exist in the generic.xml data
        if (exists $genericXml->{$type}->{$id})
        {
            print STDERR "Attribute $id definition already exists\n";

            # Ignore the tempdefaults.xml definition
            $state = stateFindEntry; # Find another entry
            for my $i ( 1 .. $count )
            {
                pop @NewAttr;
            }
            $count = 0;
        }
        else
        {
            push @NewAttr, [ $line ];
            $count += 1;
        }
    }
    # Check if line ends the <attribute> and <enumerationType> entry
    elsif ($state == stateFindEntryEnd && $line =~ /^\s*<\/$type>.*/)
    {
        $state = stateFindEntry; # Find another entry
        push @NewAttr, [ $line ];
        push @NewAttr, [ "\n" ];
        $count = 0;
    }
    # Save each line of the entry
    elsif ($state == stateFindID || $state == stateFindEntryEnd)
    {
        push @NewAttr, [ $line ];
        $count += 1;
    }
    # Check if line starts a <tempDefault> entry that can be ignored
    elsif ($state == stateFindEntry && $line =~ /^\s*<(tempDefault)>.*/)
    {
        $state = stateTempDefault; # Now find the end of <tempDefault> entry
        $type = $1;
    }
    # Check if line ends the <tempDefault> entry
    elsif ($state == stateTempDefault && $line =~ /^\s*<\/$type>.*/)
    {
        $state = stateFindEntry; # Find another entry
    }
}

close (FH);


# Check input temp_generic.xml file for attributes which have a temporary
# default defined in tempdefaults.xml file.  When an attribute with a temporary
# default is found, either create a default value in the generic.xml data if a
# value does not exist or substitute the default value in the generic.xml data
# if the temporary value is being forced.
#
# Check input temp_generic.xml file for targets which have a temporary default
# defined in hb_temp_defaults.xml file.  Use data from @UpdtTgt to update a
# <targetType> entry for a matching target.
#
# Append <attribute> and <enumerationType> entry lines from @NewAttr before
# ending the attributes section of the generic.xml file.
use constant
{
    stateFindEntry          =>  0,  # Find start of an <attribute> or
                                    # <targetType> entry in the
                                    # temp_generic.xml file
    stateFindAttrID         =>  1,  # Find ID field in the <attribute> entry
    stateFindAttrDataType   =>  2,  # Find data type of the <attribute> entry
    stateFindMultiTypeLns   =>  3,  # Find multiple lines for data type
    stateFindDefaultEnd     =>  4,  # Find end of the default definition
    stateMaxAttr            =>  9,  # Maximum value for attribute states
    stateFindTgtTypeID      => 11,  # Find ID field in the <targetType> entry
    stateFindTgtTypeEnd     => 12,  # Find end of the <targetType> entry
};

$state = stateFindEntry; # First find an entry

open (FH, "<$generic");

while (my $line = <FH>)
{
    # Check if line starts an <attribute> entry
    if ($state < stateMaxAttr && $line =~ /^\s*<attribute>.*/)
    {
        $state = stateFindAttrID; # Next find the ID within attribute entry
    }
    # Check if line starts a <targetType> entry
    elsif ($state == stateFindEntry && $line =~ /^\s*<targetType>.*/)
    {
        $state = stateFindTgtTypeID; # Next find ID within target type entry
    }
    # Check if line specifies the ID of the entry
    elsif (($state == stateFindAttrID || $state == stateFindTgtTypeID) &&
           $line =~ /^\s*<id>/)
    {
        $state += 1; # Increment to the next state, find data type of the
                     # <attribute> entry or end of the <targetType> entry
        $id = $line;
        $id =~ s/\n//;
        $id =~ s/.*<id>(.*)<\/id>.*/$1/;
    }
    # Check if line specifies the data type of the entry
    elsif ($state == stateFindAttrDataType &&
           $line =~ /^.*<(uint8_t|uint16_t|uint32_t|uint64_t|
                            hbmutex|enumeration)>/)
    {
        $type = $1;
        my $definition = $line;
        # If the data type is specified on a single line
        if ($definition =~ /^\s*(.*)<$type>(.*)<\/$type>(.*)/)
        {
            $state = stateFindEntry; # Find another entry
            my $pre = $1;
            $definition = $2;
            my $post = $3;
            $post =~ s/\n//;

            # Go through temporary default data
            for my $i ( 0 .. $#ChgAttr )
            {
                # If ID of temporary default data matches ID of file entry
                if ($ChgAttr[$i][0] eq $id)
                {
                    # If file entry already has a default defined
                    if ($definition =~ /^.*<default>(.*)<\/default>.*/)
                    {
                        # Check if temporary default is not being forced
                        if ($ChgAttr[$i][2] eq "n")
                        {
                            print STDERR
                                "Attribute $id default already exists\n";
                        }
                        else
                        {
                            # Substitute temporary default value
                            $line =~ s/<default>$1/<default>$ChgAttr[$i][1]/;
                        }
                    }
                    else # Create a default definition using temporary default
                    {
                        print "        $pre<$type>\n";
                        print "            <default>$ChgAttr[$i][1]";
                        print "</default>\n";
                        print "            $definition\n" if($definition ne "");
                        $line = "        </$type>$post\n";
                    }

                    last;
                }
            }
        }
        else
        {
            $state = stateFindMultiTypeLns; # Look for data type definition
                                            # across multiple lines
        }
    }
    # Check if line specifies a default value for a multi line data type def
    elsif ($state == stateFindMultiTypeLns && $line =~ /^\s*<default>.*/)
    {
        $state = stateFindEntry; # Find another entry
        # Go through temporary default data
        for my $i ( 0 .. $#ChgAttr )
        {
            # If ID of temporary default data matches ID of file entry
            if ($ChgAttr[$i][0] eq $id)
            {
                # Check if temporary default is not being forced
                if ($ChgAttr[$i][2] eq "n")
                {
                    print STDERR "Attribute $id default already exists\n";
                }
                # If the default is specified on a single line
                elsif ($line =~ /^\s*<default>(.*)<\/default>.*/)
                {
                    # Substitute temporary default value
                    $line =~ s/<default>$1/<default>$ChgAttr[$i][1]/;
                }
                else # Start a default definition using temporary default
                {
                    $state = stateFindDefaultEnd; # Look for end of default
                                                  # definition
                    print "            <default>";
                    print "                $ChgAttr[$i][1]";
                }

                last;
            }
        }
    }
    # Check if line ends a multi line data type definition
    elsif ($state == stateFindMultiTypeLns && $line =~ /^\s*<\/$type>.*/)
    {
        $state = stateFindEntry; # Find another entry
        # Go through temporary default data
        for my $i ( 0 .. $#ChgAttr )
        {
            # If ID of temporary default data matches ID of file entry
            if ($ChgAttr[$i][0] eq $id)
            {
                # Create a default definition using temporary default
                print "        <default>$ChgAttr[$i][1]</default>\n";
            }

            last;
        }
    }
    # Check if line ends default definition for multi line data type definition
    elsif ($state == stateFindDefaultEnd && $line =~ /^\s*<\/default>.*/)
    {
        $state = stateFindEntry; # Find another entry
    }
    # Check if line ends an <attribute> entry
    elsif ($state < stateMaxAttr && $line =~ /^\s*<\/attribute>.*/)
    {
        $state = stateFindEntry; # Find another entry
    }
    # Check if line ends a <targetType> entry
    elsif ($state == stateFindTgtTypeEnd && $line =~ /^\s*<\/targetType>.*/)
    {
        $state = stateFindEntry; # Find another entry
        # Go through update target data
        for my $i ( 0 .. $#UpdtTgt )
        {
            # If ID of update target data matches ID of file entry
            if ($UpdtTgt[$i][0] eq $id)
            {
                # Create new attribute entry for this target
                print "    <attribute>\n";
                print "        <id>$UpdtTgt[$i][2]</id>\n";
                if ($UpdtTgt[$i][3] ne "")
                {
                    print "        <default>$UpdtTgt[$i][3]</default>\n";
                }
                print "    </attribute>\n";
            }
        }
    }
    # Check if line ends the attributes in the input temp_generic.xml file
    elsif ($line =~ /^\s*<\/attributes>.*/)
    {
        # Go through new temporary attribute entries from tempdefaults.xml
        for my $i ( 0 .. $#NewAttr )
        {
            print "$NewAttr[$i][0]";
        }
    }

    print "$line" if $state != stateFindDefaultEnd;
}

close (FH);


sub display_help
{
    use File::Basename;
    my $scriptname = basename($0);
    print STDERR "
Description:

    This perl script processes the fapiattrs.xml and hb_temp_defaults.xml
    files to find any new attributes which need to be defined in the
    generic.xml file.  It also process the tempdefaults.xml file to find the
    <tempDefault> tags and any new attribute definitions so that generic.xml
    can be updated with default values and attribute definitions as needed.
    The updated generic.xml is written to the console.

Usage:

    $scriptname --help
    $scriptname --generic=genericfname
                --fapi=fapifname
                --fapi_inc=fapiincfname
                --fw_dflts=fwdfltsfname
                --defaults=defaultsfname
        --generic=genericfname
              genericfname is complete pathname of the generic.xml file
        --fapi=fapifname
              fapifname is complete pathname of the fapiattrs.xml file
        --fapi_inc=fapiincfname
              fapiincfname is complete pathname of the
              fapi2PlatAttrService.H file
        --fw_dflts=fwdfltsfname
              fwdfltsfname is complete pathname of the
              hb_temp_defaults.xml file
        --defaults=defaultsfname
              defaultsfname is complete pathname of the tempdefaults.xml file
\n";
}
