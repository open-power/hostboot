#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/xmltohb/handle_fapi_attr_mapping.pl $
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
#    handle_fapi_attr_mapping --fullAttrXml=attribute_types_full.xml
#                             --fullTargetXml=target_types_full.xml
#                             --srcTargetXml=target_types_src.xml
#                             --ekbTargetXml=target_types_ekb.xml
#                             --fapi2Header=attribute_service.H
#
# Purpose:
#
#    This perl script merges together targetExtensions from target_types_ekb and targetType tags from
#    target_types_src. The trick is to avoid adding attributes on targets where the attribute already
#    exists. Also we don't want to add function backed attributes onto targets. The last step ensures
#    that we use the Hostboot name for the attribute, as hostboot can change the name in attribute_types.xml
#    and if a mapping exists there we want to use the hostboot name.
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


my $fullTargetXmlFullPath = "";
my $fullAttrXmlFullPath     = "";
my $srcTargetXmlFullPath = "";
my $ekbTargetXmlFullPath = "";
my $fapi2HeaderFullPath    = "";
my $usage = 0;



GetOptions("fullAttrXml:s"       => \$fullAttrXmlFullPath,
           "fullTargetXml:s"   => \$fullTargetXmlFullPath,
           "srcTargetXml:s"=> \$srcTargetXmlFullPath,
           "ekbTargetXml:s"=> \$ekbTargetXmlFullPath,
           "fapi2Header:s" => \$fapi2HeaderFullPath,
           "help"          => \$usage);


if( ($fullTargetXmlFullPath eq "")
   || ($fullAttrXmlFullPath eq "")
   || ($fapi2HeaderFullPath eq "")
   || ($fullAttrXmlFullPath eq "")
   || ($fullTargetXmlFullPath eq "") )
{
    display_help();
    exit 1;
}
elsif ($usage)
{
    display_help();
    exit 0;
}


my %hwpfAttributes;

my $xml = new XML::Simple (KeyAttr=>[]);
use Digest::MD5 qw(md5_hex);

my $ekbTargetTypes = $xml->XMLin("$ekbTargetXmlFullPath", ForceArray=>['targetTypeExtension', 'attribute']);

my $srcTargetTypes = $xml->XMLin("$srcTargetXmlFullPath", ForceArray=>['targetType', 'attribute']);

#Read in HB attribute xml (attribute_types.xml)
my $allAttributes = $xml->XMLin($fullAttrXmlFullPath ,
    forcearray => ['attribute','hwpfToHbAttrMap','enumerationType','enumerator']);

my $allTargetTypes = $xml->XMLin($fullTargetXmlFullPath ,
    forcearray => ['attribute']);

#Create a list of all the HB attributes with a HWPF mapping
foreach my $attribute (@{$allAttributes->{attribute}})
{
    if (exists $attribute->{hwpfToHbAttrMap} )
    {
        push (@{$hwpfAttributes{attribute}}, $attribute);
    }
}

#Get a list of all the function backed fapi2 attributes
my %funcBackedAttr  = map { $_ => 1 } (getFuncionBackedAttrs($fapi2HeaderFullPath));

#new attributes that will be added
my @NewAttr;

#Walk through target type extensions in target_types_ekb.xml
foreach my $Extension ( @{$ekbTargetTypes->{targetTypeExtension}} )
{
    #this id is the name of the target type
    my $id = $Extension->{id};
    #walk each attribute on the target
    foreach my $attr ( @{$Extension->{attribute}} )
    {
        #keep track of attribute's id
        my $attribute_id = $attr->{id};
        #clear default each loop
        my $default = "";
        #clear out success indicator each loop
        my $attr_exists_already = 0;

        #Check if this attribute is function backed, if so, skip it
        if(exists($funcBackedAttr{("ATTR_".$attribute_id)}))
        {
            next;
        }

        #Make sure to apply defaults if we need
        if(exists $attr->{default})
        {
            $default = $attr->{default};
        }

        #Make sure we dont add attributes that already exist on the target
        foreach my $targetType (@{$srcTargetTypes->{targetType}})
        {
            if($targetType->{id} eq $id)
            {
                foreach my $targetAttr ( @{$targetType->{attribute}})
                {
                    if ($attribute_id eq $targetAttr->{id} )
                    {
                        $attr_exists_already = 1;
                        #break when we find an attribute match
                        last;
                    }
                }
                #break once we find a target match
                last;
            }
        }

        #if the attribute does not yet exist on the target, add it to list of attrs to add
        if(!$attr_exists_already)
        {
            push @NewAttr, [ $id, $attribute_id, $default ];
        }
    }
}


#add the new attributes to the correct targets
foreach my $targetType ( @{$srcTargetTypes->{targetType}})
{
    my $id = $targetType->{id};
    for my $i (0 ..$#NewAttr)
    {
        my %attrHash;
        $attrHash{'id'} = $NewAttr[$i][1];
        if($NewAttr[$i][2] ne "")
        {
            $attrHash{'default'} = $NewAttr[$i][2];
        }
        if($id eq $NewAttr[$i][0])
        {
            push (@{$targetType->{attribute}}, \%attrHash);
        }
    }
}

#Make sure we use the hostboot version of the name and not the Fapi2 version
#loop on each target type in target_types_src
foreach my $targetType (@{$srcTargetTypes->{targetType}})
{
    #loop on each attribute for every target
    foreach my $attribute (@{$targetType->{attribute}})
    {
        #check if there is a hostboot mapping w/ a different name
        foreach my $hbMappedAttr (@{$hwpfAttributes{attribute}})
        {
            my $fapiAttrId  = $hbMappedAttr->{hwpfToHbAttrMap}[0]->{id};
            $fapiAttrId = substr $fapiAttrId , 5;
            #if there is, make sure to update the id to match hostboot's xml
            if($fapiAttrId eq $attribute->{id})
            {
                $attribute->{id} = $hbMappedAttr->{id};
            }
        }
    }
}

#Write hash out to a file
my $completeTargXml = $xml->XMLout(\%$srcTargetTypes, RootName => undef, NoAttr => 1 );

#use temporary file to be clean
my $tmp_fh = new File::Temp( UNLINK => 1 );
print $tmp_fh $completeTargXml;

#open target types full in append mode
open(my $targetXmlFullFH, '+>', $fullTargetXmlFullPath) || die;
#go back to the begining of the temp file handle
seek $tmp_fh, 0, 0 or die "Seek $tmp_fh failed: $!\n";

#add \n char between each targetType
foreach my $row (<$tmp_fh>)
{
    chomp $row;
    print $targetXmlFullFH  $row."\n";
    if(index($row, "</targetType>") != -1)
    {
        print $targetXmlFullFH "\n";
    }
}

close $tmp_fh;
close $targetXmlFullFH;


sub display_help
{
    use File::Basename;
    my $scriptname = basename($0);
    print STDERR "
Description:

    This perl script merges together targetExtensions from target_types_ekb and targetType tags from
    target_types_src. The trick is to avoid adding attributes on targets where the attribute already
    exists. Also we don't want to add function backed attributes onto targets. The last step ensures
    that we use the Hostboot name for the attribute, as hostboot can change the name in attribute_types.xml
    and if a mapping exists there we want to use the hostboot name.

Usage:

    $scriptname --help

    $scriptname --fullAttrXml
              fullAttrXml is complete pathname of the attribute_types_full.xml file,
              this file is used to make sure we use hostboot's version of the attribute
              id when we add it to the target

    $scriptname --fullTargetXml
            srcAttrXml is complete pathname of the attribute_types_full.xml file that
            will be written to in this script

    $scriptname --srcTargetXml
              srcTargetXml is complete pathname of the target_types_src.xml file
              which should contain all targetType tags merged from various srcs


    $scriptname --ekbTargetXml
            ekbTargetXml is complete pathname of the target_types_ekb.xml file
            which contains targetType extensions from EKB attribute generation

    $scriptname --fapi2Header=attrServiceHeader
            attrServiceHeader is complete pathname of the attribute_service.H file from hostboot

\n";
}