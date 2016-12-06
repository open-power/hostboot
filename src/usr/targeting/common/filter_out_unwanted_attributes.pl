#! /usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/filter_out_unwanted_attributes.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016
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

#The purpose of this script is to filter out attributes that
#hostboot doesn't know about (openBMC and FSP only attributes)
#from the mrw xml. This is accomplished by referencing target_types_*.xml
#files consumed by hostboot. Any attribute not referenced in hostboot's
#target_types.xml are deleted from mrw xml.
use strict;
use XML::Simple;
use XML::LibXML;
use XML::Parser;
use Data::Dumper;
use feature "state";
use Getopt::Long qw(GetOptions);

my @tgt_files;
my $mrw_file;
my $help;

GetOptions(
    "tgt-xml=s"    => \@tgt_files,
    "mrw-xml=s"    => \$mrw_file,
    "help"         => \$help,
);

if ((scalar @tgt_files eq 0) || ($mrw_file eq ""))
{
    print "ERROR: tgt-xml or mrw-xml is not specified\n";
    print "tgt-xml: \n";
    print Dumper @tgt_files;
    print "mrw-xml: $mrw_file\n";
    usage();
}

if ($help)
{
    usage();
}

sub usage
{
    print "The purpose of this script is to filter out attributes that\n";
    print "hostboot doesn't know about (openBMC and FSP only attributes)\n";
    print "from the mrw xml. This is accomplished by referencing\n";
    print "target_types_*.xml files consumed by hostboot. \n";
    print "Any attribute not referenced in hostboot's target_types.xml\n";
    print "are deleted from mrw xml.\n";
    print "Usage: ./filter_out_unwanted_attributes.pl --mrw-xml [mrw xml]\\\n";
    print "     --tgt-xml [target xml] <--tgt-xml [target xml]>\n";
    exit (-1);
}


#Load all the target_type xmls
my @tgt_xmls;
$XML::Simple::PREFERRED_PARSER = 'XML::Parser';
foreach my $i (0 .. $#tgt_files)
{
    my $tgt_file  = $tgt_files[$i];
    print "Loading TGT XML: $tgt_file in $i\n";
    $tgt_xmls[$i] =
           XMLin($tgt_file,
                forcearray => ['attribute', 'targetType', 'field']);
}

#Load MRW XML
#Using LibXML parser to parse mrw xml to keep the order of the input xml in the
#output xml. Simple parser doesn't keep the order of the input file, so, it's
#harder to output that xml as is.
print "Loading MRW XML: $mrw_file\n";
$XML::LibXML::skipXMLDeclaration = 1;
my $parser      = XML::LibXML->new();
my $mrw_parsed  = $parser->parse_file($mrw_file);

print "The following target and attribute pairs are being removed from";
print " SYSTEM_hb.mrw.xml as they are not used by hostboot:\n";

#foreach targetInstance
foreach my $tgt
    ($mrw_parsed->findnodes('/attributes/targetInstance'))
{
    #get target type
    my $tgt_type = $tgt->findnodes('./type');

    #foreach attribute defined in this target
    foreach my $attr ($tgt->findnodes('./attribute'))
    {
        #get attribute id == attribute name
        my $attr_id = $attr->findnodes('./id');

        #findAttribute searches for this target and attribute
        #pair in all the target type xmls
        my $found = findAttribute($tgt_type, $attr_id);
        if ($found eq 0)
        {
            #if the attribute is not found in any of the target_type
            #xmls, then remove it from the mrw xml
            print "Target: $tgt_type Attr: $attr_id\n";
            $tgt->removeChild($attr);
        }
    }
}

# sub - findAttribute
# param[in] target -- the target to find the attribute under
# param[in] attr   -- the attribute to find
# retval: true == attr found, false == attr not found
sub findAttribute
{
    my $tgt  = shift;
    my $attr = shift;
    #foreach target type xml
    foreach my $i (0 .. $#tgt_xmls)
    {
        my $tgt_xml = $tgt_xmls[$i];
        if (defined $tgt_xml->{targetType}{$tgt}{attribute}{$attr})
        {
            #attribute found under the passed in target in this xml
            return 1;
        }
        else
        {
            my %tgt_hash = %$tgt_xml;
            #if not found in this target, look under parent target
            #some targets are inherrited
            if (lookAtParentAttributes (\%tgt_hash, $tgt, $attr) eq 1)
            {
                return 1;
            }
        }
    }
    return 0;
}

# sub - lookAtParentAttributes
#       recursively looks for an attribute in current
#       target's parent because some attributes are inherrited from parents
# param[in]: tgt_xml - hash containing the entire target type xml
# param[in]: tgt - look at the parent of this target
# param[in]: attr - attribute to look for
# retval: true == attr found, false == attr not found
sub lookAtParentAttributes
{
    my ($tgt_xml, $tgt, $attr) = @_;

    my $parent = $tgt_xml->{targetType}{$tgt}{parent};
    if ($parent eq "")
    {
        return 0;
    }
    elsif ($parent eq "base")
    {
         return (defined  $tgt_xml->{targetType}{$parent}{attribute}{$attr}) ?
                        1 : 0;
    }
    else
    {
        if (defined  $tgt_xml->{targetType}{$parent}{attribute}{$attr})
        {
            return 1;
        }
        else
        {
            my %tgt_hash = %$tgt_xml;
            #attribute not found, maybe it is inherrited from the parent
            #recursively look for the attribute in this target's parent
            #We will look until we find the attribute, or there is no parent
            #(parent == "") or we have reached the "base" target
            #"base" is the topmost target defined in target_type xml
            return lookAtParentAttributes(\%tgt_hash, $parent, $attr);
        }
    }
}
#OUTPUT
my $xml_fh;
my $filename = $mrw_file . ".updated";
print "Creating XML: $filename\n";
open($xml_fh, ">$filename") || die "Unable to create: $filename";
print {$xml_fh} $mrw_parsed->toString();
close($xml_fh);
