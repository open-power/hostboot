#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/xmltohb/create_ekb_targattr.pl $
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

#
#
# Usage:
#
#    create_ekb_targattr.pl --fapi=fapiattrs.xml --attr=attribute_types_ekb.xml
#                    --targ=target_types.xmltohb --default=hb_temp_default.xml
#
# Purpose:
#
#    This perl script processes the FAPI attributes (from the EKB repo) in
#    fapiattrs.xml, and the temporary defaults in hb_temp_defaults.xml and
#    creates attribute_types_ekb.xml, and target_types_ekb.xml with
#    equivalent Hostboot attribute definitions.
#

use strict;
use XML::Simple;
use Data::Dumper;

require "fapi_utils.pl";

$XML::Simple::PREFERRED_PARSER = 'XML::Parser';
use Digest::MD5 qw(md5_hex);

#init variables
my $generic = "";
my $fapi_filename = "";
my $targ_filename = "";
my $attr_filename = "";
my $hbCustomize_filename = "";

my $usage = 0;
use Getopt::Long;
GetOptions( "fapi:s"     => \$fapi_filename,
            "attr:s"     => \$attr_filename,
            "targ:s"     => \$targ_filename,
            "default:s"  => \$hbCustomize_filename,
            "help"       => \$usage, );

if( ($fapi_filename eq "")
   || ($attr_filename eq "")
   || ($targ_filename eq "") )
{
    display_help();
    exit 1;
}
elsif ($usage)
{
    display_help();
    exit 0;
}

#use the XML::Simple tool to convert the xml files into hashmaps
my $xml = new XML::Simple (KeyAttr=>[]);

#data from the ekb fapi attributes
my $fapiXml = $xml->XMLin("$fapi_filename" ,
                          forcearray => ['attribute'],
                          NoAttr => 1);

#data from the temporary default xml
my $hbCustomizeXml = $xml->XMLin("$hbCustomize_filename" ,
                                 forcearray => ['attribute'],
                                 NoAttr => 1);

####################
##### Generate attribute_types #####

print "\nGenerating attribute_types\n";
my $numattrs = 0;

open (my $ATTR_FH, ">$attr_filename") ||
    die "ERROR: unable to open $attr_filename\n";

print $ATTR_FH "<attributes>\n\n";

# Walk attribute definitions in fapiattrs.xml
foreach my $FapiAttr ( @{$fapiXml->{attribute}} )
{
    #we dont need to worry about EC FEATURE attributes
    if( $FapiAttr->{id} =~ /_EC_FEATURE/ )
    {
        next;
    }
    #print "====" . $FapiAttr->{id} . "\n";

    #Check if there are any defaults values we need to add to fapi attrs before generating HB
    foreach my $customizedAttr(@{$hbCustomizeXml->{attribute}})
    {
        #if we find a match, then add update the attribute w/ customized values
        if ($customizedAttr->{id} eq $FapiAttr->{id})
        {
            if(exists $customizedAttr->{default})
            {
                #print "Found match for ".$customizedAttr->{id}." default val is ".$customizedAttr->{default}."\n";
                $FapiAttr->{default} = $customizedAttr->{default};
            }
        }
    }

    #use utility functions to generate enum xml, if possible
    my $enum = createEnumFromAttr($FapiAttr);
    #use utility functions to generate attribute xml
    my $attr = createAttrFromFapi($FapiAttr);

    #Check if there are additional tags besides default we need to add to fapi attrs
    foreach my $customizedAttr(@{$hbCustomizeXml->{attribute}})
    {
        #if we find a match, then add update the attribute w/ customized values
        if ($customizedAttr->{id} eq $attr->{hwpfToHbAttrMap}->{id})
        {
            foreach my $tag (keys %$customizedAttr)
            {
                if($tag ne "default" && $tag ne "id" )
                {
                    #print "Found match for ".$customizedAttr->{id}." $tag val is ".$customizedAttr->{$tag}."\n";
                    $attr->{$tag} = $customizedAttr->{$tag};
                }
            }
            #Do not exit loop yet, continue in case there are more than 1 attr customization tags
        }
    }

    #not all attribute have enumaterated values, so enums are optional
    if($enum ne "0"  && $enum ne "")
    {
        printTargEnum($ATTR_FH, $enum);
    }

    #write to the attribute xml file
    printTargAttr($ATTR_FH,$attr);
    print $ATTR_FH "\n";
    $numattrs++;
}

print "...$numattrs fapi attributes generated from EKB\n";
print $ATTR_FH "</attributes>";
close $ATTR_FH;


####################
##### Generate target_types #####

print "\nGenerating target_types\n";

open (my $TARG_FH, ">$targ_filename") ||
    die "ERROR: unable to open $targ_filename\n";

my $allTargetExt = {};

# Walk attribute definitions in fapiattrs.xml
foreach my $FapiAttr ( @{$fapiXml->{attribute}} )
{
    #print "====" . $FapiAttr->{id} . "\n";
    #like when generating attributes, skip the _EC_FEATURES
    if( $FapiAttr->{id} =~ /_EC_FEATURE/ )
    {
        next;
    }
    #use the utility function to generate a target extension xml
    createTargetExtensionFromFapi($FapiAttr,$allTargetExt);
}

#begin writing the file
print $TARG_FH "<attributes>\n\n";

# Print out all the generated stuff
foreach my $targ (@{$allTargetExt->{targetTypeExtension}})
{
    #print $targ->{id} ."\n";
    printTargExt($TARG_FH,$targ);
    print $TARG_FH "\n";
}

print $TARG_FH "</attributes>";
close $TARG_FH;


###########################################################
###########################################################


sub display_help
{
    use File::Basename;
    my $scriptname = basename($0);
    print STDERR "
Description:

   This perl script processes the FAPI attributes in fapiattrs.xml, and the
   temporary defaults in hb_temp_defaults.xml and creates attribute_types_ekb.xml,
   and target_types_ekb.xml with equivalent Hostboot attribute definitions.

Usage:

    $scriptname --help

    $scriptname --fapi=fapifname
              fapifname is complete pathname of the fapiattrs.xml file

    $scriptname --attr=attrofname
            attrofname is complete pathname of the attribute_types_ekb.xml

    $scriptname --targ=targofname
            targofname is complete pathname of the target_types_ekb.xml

    $scriptname --default=defaultifname
            defaultifname is the complete pathname of the hb_temp_defaults.xml
\n";
}
