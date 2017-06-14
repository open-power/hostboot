#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/xmltohb/handle_duplicate.pl $
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

#
#
# Usage:
#
#    handle_duplicate --ekbXmlFile=attribute_types_ekb.xml --hbXmlFile=attribute_types_src.xml
#                     --fapi2Header=attribute_service.H --outFile=attribute_types_full.xml
#
# Purpose:
#
#    This perl script merges together attribute_types_ekb and attribute_types_src into one output
#    file that can be consumed by either the FIPS build or the op-build process. The trick is that
#    we don't want the EKB attributes to override fapi-mapped attributes we have already defined in
#    hostboot's xml.
#

use strict;

use Getopt::Long;
use XML::Simple;
use Text::Wrap;
use Data::Dumper;
use POSIX;
use Env;
use XML::LibXML;
use File::Temp qw(tempfile);

require "fapi_utils.pl";

$XML::Simple::PREFERRED_PARSER = 'XML::Parser';


my $ekbXmlFullPath = "";
my $hbXmlFullPath    = "";
my $fapi2HeaderFullPath    = "";
my $outFullPath    = "";
my $usage = 0;


GetOptions("ekbXmlFile:s"  => \$ekbXmlFullPath,
           "hbXmlFile:s"   => \$hbXmlFullPath,
           "fapi2Header:s" => \$fapi2HeaderFullPath,
           "outFile:s"     => \$outFullPath,
           "help"          => \$usage);


if( ($ekbXmlFullPath eq "")
   || ($hbXmlFullPath eq "")
   || ($fapi2HeaderFullPath eq "")
   || ($outFullPath eq "") )
{
    display_help();
    exit 1;
}
elsif ($usage)
{
    display_help();
    exit 0;
}


my %completeAttr;

#attributes defined in attribute_types.xml w/ fapi2 mapping
my %hwpfAttributes;


#use the XML::Simple tool to convert the xml files into hashmaps
my $xml = new XML::Simple (KeyAttr=>[]);
use Digest::MD5 qw(md5_hex);


#Read in EKB attribute xml (fapiattrs.xml)
my $allEKBAttributes = $xml->XMLin($ekbXmlFullPath ,
    forcearray => ['attribute','hwpfToHbAttrMap','enumerationType','enumerator']);

#Read in HB attribute xml (attribute_types.xml)
my $allHBAttributes = $xml->XMLin($hbXmlFullPath ,
    forcearray => ['attribute','hwpfToHbAttrMap','enumerationType','enumerator']);


#Get a list of all the function backed fapi2 attributes
my @funcBackedAttr = getFuncionBackedAttrs($fapi2HeaderFullPath);

#Create a list of all the HB attributes with a HWPF mapping
foreach my $attribute (@{$allHBAttributes->{attribute}})
{
    if (exists $attribute->{hwpfToHbAttrMap} )
    {
        push (@{%hwpfAttributes->{attribute}}, $attribute);
    }
}


#Looping variable
my $matchFound = 0;

#Loop over all of the EKB attributes and look for a duplcate in HB list
foreach my $ekbAttr (@{$allEKBAttributes->{attribute}})
{
    my $isFuncBacked = 0;
    $matchFound = 0;
    my $theHbAttr;
    my $ekbAttrId = $ekbAttr->{hwpfToHbAttrMap}[0]->{id};

    #check if this matches any in our list of func backed attrs
    foreach my $id (@funcBackedAttr)
    {
        if ($id eq $ekbAttrId)
        {
            $isFuncBacked = 1;
            last;
        }
    }

    #If it is a function backed attribute , no need to add it
    #we want the function to overrule anything else.
    if($isFuncBacked)
    {
        print "SKIPPING EKB $ekbAttrId - function backed\n";
        next;
    }

    #Loop over HB attrs until we find a match
    foreach my $hbAttr (@{%hwpfAttributes->{attribute}})
    {
        my $hbFapiId  = $hbAttr->{hwpfToHbAttrMap}[0]->{id};

        if($ekbAttrId eq $hbFapiId)
        {
            $matchFound = 1;
            $theHbAttr = $hbAttr;
            last;
        }
    }

    #if no match was found we will assume this is a new attribute and add it
    if(!$matchFound)
    {
        push (@{$completeAttr{attribute}}, $ekbAttr);
    }
    #otherwise we need to check what was updated and handle it accordingly
    else
    {
        #Special case big hammer will ignore the generated version and
        # always choose what HB coded up
        my $ignoreEkb = 0;
        if( exists $theHbAttr->{ignoreEkb} )
        {
            $ignoreEkb;
        }

        #if the EKB's description was updated we will assume their description
        # to be more correct so just update the HB attr's description
        my $ekbDesc = $ekbAttr->{description};
        my $hbDesc  = $theHbAttr->{description};
        if($ekbDesc ne $hbDesc)
        {
            $theHbAttr->{description} = $ekbDesc;
        }

        #if persistancy has changed we want to notify the developer so cause a fail
        my $ekbPersist = $ekbAttr->{persistancy};
        my $hbPersist = $theHbAttr->{persistancy};
        if($ekbPersist ne $hbPersist)
        {
            die "ERROR Hostboot says persistancy of ".$ekbAttrId." is ".$hbPersist." and Fapi says it is ".$ekbPersist."\n";
        }

        #if array dimmensions have changed we want to notify the developer so cause a fail
        my $hbArrayDimmensions = getArrayDimmensions(%$theHbAttr);
        my $ekbArrayDimmensions = getArrayDimmensions(%$ekbAttr);
        if($hbArrayDimmensions ne $ekbArrayDimmensions)
        {
            die "ERROR Hostboot says array dimmensions of ".$ekbAttrId." is ".$hbArrayDimmensions." and Fapi says it is ".$ekbArrayDimmensions."\n";
        }

        #if attribute type has changed we want to notify the developer so cause a fail
        my $hbAttrType = getAttrType(%$theHbAttr);
        my $ekbAttrType = getAttrType(%$ekbAttr);
        if($hbAttrType ne $ekbAttrType)
        {
            die "ERROR Hostboot says type of ".$ekbAttrId." is ".$hbAttrType." and Fapi says it is ".$ekbAttrType."\n";
        }
    }
}

#also need to add all of the EKB enumerations
foreach my $ekbEnum (@{$allEKBAttributes->{enumerationType}})
{
    $matchFound = 0;
    my $ekbEnumId = $ekbEnum->{id};
    my $theHbEnum;
    #we dont want to add duplicates so check if the enumeration exists already in HB
    foreach my $hbEnum (@{%$allHBAttributes->{enumerationType}})
    {
        my $hbEnumId  = $hbEnum->{id};

        if($ekbEnumId eq $hbEnumId)
        {
            $matchFound = 1;
            $theHbEnum = $hbEnum;
            last;
        }
    }

    #if not found already, then add the enum
    if(!$matchFound)
    {
        push (@{$completeAttr{enumerationType}}, $ekbEnum);
    }
    #if a copy already exists in HB then we just want to update the values and description
    else
    {
        $theHbEnum->{description} = $ekbEnum->{description};
        $theHbEnum->{enumerator} = $ekbEnum->{enumerator};
    }
}

#add all HB attributes to completeAttr (the hash holding output xml)
foreach my $hbAttr (@{$allHBAttributes->{attribute}})
{
    push (@{$completeAttr{attribute}}, $hbAttr);
}

#also add the HB enums to completeAttr hash
foreach my $hbEnum (@{$allHBAttributes->{enumerationType}})
{
    push (@{$completeAttr{enumerationType}}, $hbEnum);
}


#To make things look nicer we add a newline after each attribute or enumerationType
my $completeXml = $xml->XMLout(\%completeAttr, RootName => 'attributes', NoAttr => 1 );
my $complete_fh_temp = new File::Temp( UNLINK => 1 );

print $complete_fh_temp $completeXml;

seek $complete_fh_temp, 0, 0 or die "Seek $complete_fh_temp failed: $!\n";

open(my $complete_fh, '>', $outFullPath) || die;

foreach my $row (<$complete_fh_temp>)
{
    chomp $row;
    print $complete_fh  $row."\n";
    if(index($row, "</enumerationType>") != -1 ||
       index($row, "</attribute>") != -1)
    {
        print $complete_fh "\n";
    }
}

close $complete_fh;



sub display_help
{
    use File::Basename;
    my $scriptname = basename($0);
    print STDERR "
Description:

    This perl script merges together attribute_types_ekb and attribute_types_src into one output
    file that can be consumed by either the FIPS build or the op-build process. The trick is that
    we don't want the EKB attributes to override fapi-mapped attributes we have already defined in
    hostboot's xml.

Usage:

    $scriptname --help

    $scriptname --ekbXmlFile=generatedEkbAttrXml
              generatedEkbAttrXml is complete pathname of the attribute_types_ekb.xml file
              that is generated by create_ekb_targattr.pl

    $scriptname --hbXmlFile=srcAttrXml
            srcAttrXml is complete pathname of the attribute_types_src.xml, or file that
            consists of all the relevent srcs cat'ed together

    $scriptname --fapi2Header=attrServiceHeader
            attrServiceHeader is complete pathname of the attribute_service.H file from hostboot

    $scriptname --outFile=completeAttrXml
            completeAttrXml is the complete pathname of the attribute_types_full.xml , or file
            that will be consumed by downstream repo (FIPS or op-build)
\n";
}
