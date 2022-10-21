#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/xmltohb/fapi_utils.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017,2022
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
# A collection of utility functions to convert fapi attributes to targeting attributes

use XML::Simple;
use Digest::MD5 qw(md5_hex);
use strict;
$XML::Simple::PREFERRED_PARSER = 'XML::Parser';
my $xml = new XML::Simple (KeyAttr=>[]);


# Convert a FAPI2 target type to the equivalent TARGETING type
#   Input: fapi2 type
#   Output: targeting type
sub convertTargetFapi2Targ
{
    my $fapitype = shift;
    my $targtype;

    $targtype =~ s/\s//g;
    $targtype =~ s/TARGET_TYPE_//;
    $targtype =~ s/_ENDPOINT//;
    $targtype =~ s/_CHIPLET//;
    $targtype =~ s/_CHIP//;
    $targtype =~ s/^SYSTEM$/SYS/;

    #todo - check result against list of types from target_types?

    return $targtype;
}


# Convert a FAPI2 value type to the equivalent TARGETING type
#   Input: fapi2 type
#   Output: targeting type
sub convertValueFapi2Targ
{
    my $fapitype = shift;
    my $targtype = $fapitype;

    $targtype =~ s/(uint\d+)/$1_t/ if($fapitype =~ /^uint\d+$/);
    $targtype =~ s/(int\d+)/$1_t/  if($fapitype =~ /^int\d+$/);

    #todo - check result against list of types from target_types?

    return $targtype;
}

# Create a TARGETING style enumeration based on the enum tag from
#  a FAPI2 attribute definition
#   Input: fapi2 attribute
#   Output: targeting enumeration
sub createEnumFromAttr(\%)
{
    my($fapiattr) = @_;
    my @enums;

    if (exists $fapiattr->{enum})
    {
        # description: passed as-is
        my $fapiattr_id = $fapiattr->{id};
        my $id = $fapiattr_id;
        $id =~ s/ATTR_//;
        my $description = $fapiattr->{description};
        $description =~ s/^\s+|\s+$//g;


        my $enum = $fapiattr->{enum};
        my @enumerators = split( /,/, $enum);
        my @enumeratorHashArray;

        foreach my $enumerator (@enumerators)  {
            my %enumeratorHash;
            chomp($enumerator);
            $enumerator =~ s/^\s+|\s+$//g;

            my @nameVal = split( /=/, $enumerator);

            my $name = $nameVal[0];
            $name =~ s/^\s+|\s+$//g;
            my $value = $nameVal[1];
            $value =~ s/^\s+|\s+$//g;

            my %enumeratorHash = (
                name => $name,
                value => $value
            );

            push @enumeratorHashArray, \%enumeratorHash;
        }

        my %enumToAdd = (
            id => $id,
            description => $description,
        );
        $enumToAdd{'enumerator'} = [@enumeratorHashArray];
        return \%enumToAdd
    }
}

# Create full attribute definition from a fapi2 attribute definition
#   Input: hashmap of a single fapi attribute
#   Output: hashmap of a single targeting attribute
sub createAttrFromFapi(\%)
{
    my($fapiattr) = @_;
    my $targattr = {};

    # id: passed as-is
    my $fapiattr_id = $fapiattr->{id};
    my $id = $fapiattr_id;
    $id =~ s/ATTR_//;
    $targattr->{id} = $id;

    # description: passed as-is
    my $description = $fapiattr->{description};
    if(ref $fapiattr->{description} && eval {keys %{$fapiattr->{description}} == 0} )
    {
        $targattr->{description} = "place holder description";
    }
    else
    {
        $targattr->{description} = $description;
    }

    # valueType: convert
    my $valueType = convertValueFapi2Targ($fapiattr->{valueType});
    $targattr->{simpleType}->{$valueType} = {};

    # writeable: passed as-is
    if( exists $fapiattr->{writeable} )
    {
        $targattr->{writeable} = {};
    }

    #default: modifies simpleType
    if( exists $fapiattr->{default} )
    {
        $targattr->{simpleType}->{$valueType}->{default} =
            $fapiattr->{default};
    }

    #array: modifies simpleType
    if( exists $fapiattr->{array} )
    {
        my @dimensions = split(' ',$fapiattr->{array});
        my $dimensions_cs = @dimensions[0];
        for my $i ( 1 .. $#dimensions )
        {
            $dimensions_cs .= ",$dimensions[$i]";
        }
        $dimensions_cs =~ s/,,/,/g;
        $targattr->{simpleType}->{array} = $dimensions_cs;
    }

    #platInit: influences persistency
    #initToZero: influences persistency
    #overrideOnly: influences persistency
    if( exists $fapiattr->{platInit} )
    {
        if( exists $fapiattr->{overrideOnly} )
        {
            if( exists $fapiattr->{default} )
            {
                $targattr->{persistency} = "volatile";
            }
            else
            {
                $targattr->{persistency} = "volatile-zeroed";
            }
        }
        else
        {
            $targattr->{persistency} = "non-volatile";
        }
    }
    elsif( exists $fapiattr->{initToZero} )
    {
        if( exists $fapiattr->{default} )
        {
            print "INVALID - $fapiattr_id has initToZero and a default\n";
        }
        $targattr->{persistency} = "volatile-zeroed";
    }
    elsif( exists $fapiattr->{default} )
    {
        $targattr->{persistency} = "volatile";
    }
    else
    {
        $targattr->{persistency} = "volatile-zeroed";
    }

    #mrwHide:  convert to no_export to hide from ServerWiz
    if( exists $fapiattr->{mrwHide} )
    {
        $targattr->{no_export} = {};
    }

    #mssUnits: ignore
    #mssAccessorName: ignore
    #odmVisible: ignore
    #odmChangeable: ignore
    #persistent: ignore
    #persistRuntime: ignore

    #enum: ignored here
    #targetType: ignored here

    #always add these
    $targattr->{readable} = {};
    $targattr->{hwpfToHbAttrMap}->{id} = $fapiattr_id;
    $targattr->{hwpfToHbAttrMap}->{macro} = "DIRECT";

#    print Dumper($targattr);

#    printTargAttr($targattr);

    return $targattr;
}

# Create targetTypeExtensions from a fapi2 attribute definition
#   Input: hashmap of a single fapi attribute
#          array of all targetTypeExtensions
sub createTargetExtensionFromFapi(\%,\%)
{
    my($fapiattr,$alltargext) = @_;
    #print "createTargetExtensionFromFapi---\n";
    open my $FHSTDOUT, ">&STDOUT";

    # Conversions from FAPI2 to TARGETING types
    my $fapi2targ = {
    TARGET_TYPE_SYSTEM        => "sys-sys-power10",
    TARGET_TYPE_DIMM          => "lcard-dimm",
    TARGET_TYPE_PROC_CHIP     => "chip-processor",
    TARGET_TYPE_CORE          => "unit-core",
    TARGET_TYPE_EQ            => "unit-eq",
    TARGET_TYPE_MI            => "unit-mi",
    TARGET_TYPE_PERV          => "unit-perv",
    TARGET_TYPE_PEC           => "unit-pec",
    TARGET_TYPE_PHB           => "unit-phb",
    TARGET_TYPE_MC            => "unit-mc",
    TARGET_TYPE_OMI           => "unit-omi",
    TARGET_TYPE_OMIC          => "unit-omic",
    TARGET_TYPE_MCC           => "unit-mcc",
    TARGET_TYPE_OCMB_CHIP     => "chip-ocmb-generic",
    TARGET_TYPE_MEM_PORT      => "unit-mem_port",
    TARGET_TYPE_PMIC          => "pmic",
    TARGET_TYPE_NMMU          => "unit-nmmu",
    TARGET_TYPE_FC            => "unit-fc",
    TARGET_TYPE_PAUC          => "unit-pauc",
    TARGET_TYPE_IOHS          => "unit-iohs",
    TARGET_TYPE_PAU           => "unit-pau",
    TARGET_TYPE_GENERICI2CSLAVE => "generic_i2c_device",
    TARGET_TYPE_IOLINK        => "unit-smpgroup",
    TARGET_TYPE_MDS_CTLR      => "unit-mds-ctlr",
    TARGET_TYPE_TEMP_SENSOR   => "temp_sensor",
    TARGET_TYPE_POWER_IC      => "power_ic",
    };

    # Loop through all of the targets that this attribute
    #  is needed on (per fapi xml)
    my @types = split(',',$fapiattr->{targetType});
    foreach my $type(@types)
    {
        my $foundmatch = 0;
        $type =~ s/\s//g;
        my $targtype = $fapi2targ->{$type};
        # print "type = $type -> $targtype\n";
        my $attrid = $fapiattr->{id};
        $attrid =~ s/ATTR_//;

        # create new attribute element
        my $newattr = {};
        $newattr->{id} = $attrid;

        # look for an existing targetTypeExtension entry
        #  to modify with new attribute
        foreach my $targ (@{$alltargext->{targetTypeExtension}})
        {
            if( $targ->{id} =~ /^$targtype$/ )
            {
                #print "-Found it\n";
                $foundmatch = 1;
                #printTargExt($FHSTDOUT,$targ);
                my $attrlist = $targ->{attribute};
                push @$attrlist, $newattr;
                #printTargExt($FHSTDOUT,$targ);
                last;
            }
        }

        # no existing entry for this kind of target, make a new one
        if( $foundmatch == 0 )
        {
            #print "-No entry found for $targtype, creating new entry\n";
            my $newext = {};
            $newext->{id} = $targtype;
            my $newarray = [];
            push @$newarray, $newattr;
            $newext->{attribute} = $newarray;
            my $allext = $alltargext->{targetTypeExtension};
            push @$allext, $newext;
            #printTargExt($FHSTDOUT,$newext);
        }
    }


    #print Dumper($alltargets);


#    print "---\n";
#    printTargTarg($targtarg);
#    print "---done\n";
}



# Print string representation of a targeting attribute
#   Input: hashmap of a single targeting attribute
#   Output: string of xml tags
sub printTargAttr
{
    my($FH1,$targattr) = @_;
    print $FH1 $xml->XMLout( $targattr, RootName => 'attribute', NoAttr => 1 );
}

# Print string representation of a targeting enumeration
#   Input: hashmap of a single targeting enumeration
#   Output: string of xml tags
sub printTargEnum
{
    my($FH1,$targattr) = @_;
    print $FH1 $xml->XMLout( $targattr, RootName => 'enumerationType', NoAttr => 1 );
}

# Print string representation of a targeting target
#   Input: hashmap of a single targeting target
#   Output: string of xml tags
sub printTargTarg
{
    my($FH1,$targtarg) = @_;
    print $FH1 $xml->XMLout( $targtarg, RootName => 'targetType', NoAttr => 1 );
}

# Print string representation of a targeting targetExtension
#   Input: hashmap of a single targeting target
#   Output: string of xml tags
sub printTargExt
{
    my($FH1,$targtarg) = @_;
    print $FH1 $xml->XMLout( $targtarg, RootName => 'targetTypeExtension', NoAttr => 1 );
}

# getArrayDimmensions
# Description: for a given attribute hashMap , return the array dimmensions
#              if the attribute type is an array
# input      : hashMap of attribute xml
# return     : String of CSV list that lists the array dimmensions
sub getArrayDimmensions{
    my (%attrHash) = @_;
    my $retValue = "";

    my $simpleType = $attrHash{simpleType};

    my @keys = keys (%$simpleType);

    for my $key (@keys)
    {
        if( $key eq "array")
           {
                $retValue .= $attrHash{simpleType}->{$key};
           }
    }
    #eat whitespace
    $retValue =~ s/\s+//g;
    return $retValue;
}

# getFuncionBackedAttrs
# Description: Lookup all of the attributes that HB is backing with functions
# input      : full path to attribute_service.H
# return     : array of attribute IDs that are function backed
sub getFuncionBackedAttrs {
    my ($headerFile) = @_;
    my @attrIdArray;
    open(my $attr_service_fh, '<', $headerFile) || die "unable to open $headerFile";

    foreach my $row (<$attr_service_fh>)
    {
        my $attrIndex = index($row, "ATTR_");
        my $getMacroIndex = index($row, "_GETMACRO(ID");
        if($getMacroIndex != -1)
        {
            my $attrToAdd = substr $row, $attrIndex, $getMacroIndex - $attrIndex;
            push @attrIdArray, $attrToAdd;
            print " $0> FOUND $attrToAdd GETMACRO\n";
        }
    }
    return @attrIdArray;
}

# getAttrType
# Description: for a given attribute hashMap , return the attribute type
# input      : hashMap of attribute xml
# return     : string represention attribute type
sub getAttrType {
    my (%attrHash) = @_;
    my $retValue = "";

    my $simpleType = $attrHash{simpleType};

    my @keys = keys (%$simpleType);

    for my $key (@keys)
    {
        if( $key ne "array")
           {
                $retValue .= $key;
           }
    }
    return $retValue;
}


# need to return 1 for other modules to include this
1;
