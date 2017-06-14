#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/xmltohb/remove_hb_fapi_maps.pl $
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
#    handle_fapi_attr_mapping --spAttrXml=attribute_types_sp.xml
#                             --spTargXml=target_types_sp.xml
#                             --hbAttrXml=attribute_types_hb.xml

#
# Purpose:
#
#    The FSP side of targeting image building doesn't consume the attribute_types_hb.xml until
#    much later in the build process. Our previous scripts aren't smart enough to not add in
#    EKB attributes which are already mapped in the attribute_types_hb.xml so when we get to
#    the step on the FSP side where we pull in these attributes we hit a fail. This script
#    walks through the target_types_sp and attribute_types_sp xmls and removes any attributes
#    that have maps defined in attribute_types_hb.xml
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


$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

my $spAttrXml = "";
my $spTargXml = "";
my $hbAttrXml = "";
my $usage = 0;

GetOptions("spAttrXml:s"   => \$spAttrXml,
           "spTargXml:s"   => \$spTargXml,
           "hbAttrXml:s"   => \$hbAttrXml,
           "help"          => \$usage);


if(   ($spAttrXml eq "")
   || ($spTargXml eq "")
   || ($hbAttrXml eq "") )
{
    display_help();
    exit 1;
}
elsif ($usage)
{
    display_help();
    exit 0;
}

my @hbMappedAttrs;
my @fixedSpAttrs;
my @fixedSpTargetAttr;

#use the XML::Simple tool to convert the xml files into hashmaps
my $xml = new XML::Simple (KeyAttr=>[]);
use Digest::MD5 qw(md5_hex);

#read in attribute_types_sp.xml and store in hashmap
my $spAttributes = $xml->XMLin($spAttrXml ,
    forcearray => ['attribute','hwpfToHbAttrMap','enumerationType','enumerator']);

#Read in HB attribute xml (attribute_types.xml)
my $hbAttributes = $xml->XMLin($hbAttrXml ,
    forcearray => ['attribute','hwpfToHbAttrMap','enumerationType','enumerator']);

#read in target_types_sp.xml and store in hashmap
my $spTargets = $xml->XMLin($spTargXml ,
    forcearray => ['attribute']);

#Create a list of all the HB-only attributes(attribute_types_hb) with a HWPF mapping
foreach my $attribute (@{$hbAttributes->{attribute}})
{
    if (exists $attribute->{hwpfToHbAttrMap} )
    {
        push (@hbMappedAttrs, $attribute->{hwpfToHbAttrMap}[0]->{id});
    }
}

#keep two list of attributes, one list to keep, one to remove
my @spAttributeToKeep;
my @spAttributeToRemove;

#The attribute_types_sp xml does not include HB srcs ,but  we dont want to add EKB
#attribute that are mapped in attribute_types_hb xml. We need to loop through
#all of the attributes and make sure we are not overwriting an HB-only attr
foreach my $spAttribute (@{$spAttributes->{attribute}})
{
    my $foundMatch = 0;
    #First check if it is an EKB attribute
    if(exists $spAttribute->{hwpfToHbAttrMap} )
    {
        #if it is an EKB attr, check if it has a mapping in Hb-only xml
        foreach my $id (@hbMappedAttrs)
        {
            if($id eq $spAttribute->{hwpfToHbAttrMap}[0]->{id})
            {
                #if it already has a mapping, add to list to remove
                $foundMatch = 1;
                push (@spAttributeToRemove, $spAttribute->{id})
            }
        }
    }
    #if no hb-only mapping is found , add to list to keep.
    if (!$foundMatch)
    {
        push (@spAttributeToKeep, $spAttribute);
    }
}

#Remove the attributes from the spAttribute hashmap and
#replace w/ list of attrs to keep
undef @{$spAttributes->{attribute}};
@{$spAttributes->{attribute}} = @spAttributeToKeep;


#loop on all of the target types defined in target_types_sp
foreach my $spTarget (@{$spTargets->{targetType}})
{
    #clear local attribute list each loop
    undef @fixedSpTargetAttr;
    #loop on each attribute of the target
    foreach my $targAttr (@{$spTarget->{attribute}})
    {
        my $foundMatch = 0;
        #check if any attributes are on the list to be removed
        foreach my $attrToRemoveId (@spAttributeToRemove)
        {
            if($attrToRemoveId eq $targAttr->{id})
            {
                $foundMatch = 1;
                print STDOUT "removing ".$attrToRemoveId."\n";
            }
        }
        if (!$foundMatch)
        {
            push (@fixedSpTargetAttr, $targAttr);
        }
    }

    #update w/ new attribute list
    undef @{$spTarget->{attribute}};
    @{$spTarget->{attribute}} = @fixedSpTargetAttr;
}

#need to write contents of both targ and attr xml hashes becuase both were modified
my $finalTargXmlOutput = $xml->XMLout(\%$spTargets, RootName => 'attributes', NoAttr => 1 );
my $finalAttrXmlOutput = $xml->XMLout(\%$spAttributes, RootName => 'attributes', NoAttr => 1 );

open(my $final_attr_output_fh_temp_w, '>', $spAttrXml ) || die;
print $final_attr_output_fh_temp_w $finalAttrXmlOutput;
close $final_attr_output_fh_temp_w;

open(my $final_targ_output_fh_temp_w, '>', $spTargXml ) || die;
print $final_targ_output_fh_temp_w $finalTargXmlOutput;
close $final_targ_output_fh_temp_w;

  sub display_help
{
    use File::Basename;
    my $scriptname = basename($0);
    print STDERR "
Description:

    The FSP side of targeting image building doesn't consume the attribute_types_hb.xml until
    much later in the build process. Our previous scripts aren't smart enough to not add in
    EKB attributes which are already mapped in the attribute_types_hb.xml so when we get to
    the step on the FSP side where we pull in these attributes we hit a fail. This script
    walks through the target_types_sp and attribute_types_sp xmls and removes any attributes
    that have maps defined in attribute_types_hb.xml

Usage:

    $scriptname --help

    $scriptname --spAttrXml
              spAttrXml is complete pathname of the attribute_types_sp.xml file,

    $scriptname --spTargXml
            spTargXml is complete pathname of the target_types_sp.xml file that

    $scriptname --hbAttrXml
              hbAttrXml is complete pathname of the attr_types_hb.xml file


\n";
}


