#! /usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/filter_out_unwanted_attributes.pl $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2017
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
    print "     --tgt-xml [common target xml] <--tgt-xml [platform target xml]>\n";
    exit (-1);
}


$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

#Merge both the files to merge all extension target into target types and add
#new target types which is coming from platform specific target
open (FH, "<$tgt_files[0]") ||
    die "ERROR: unable to open $tgt_files[0]\n";
close (FH);

open (FH, "<$tgt_files[1]") ||
    die "ERROR: unable to open $tgt_files[1]\n";
close (FH);


my $fileCommon = XMLin("$tgt_files[0]");
my $filePlatform = XMLin("$tgt_files[1]", ForceArray=>1);

# This loop will fetch all targetTypeExtension from platform target types xml
# and push it in an array "@NewAttr"
my @NewAttr;
foreach my $Extension ( @{$filePlatform->{targetTypeExtension}} )
{
    my $id = $Extension->{id}->[0];
    foreach my $attr ( @{$Extension->{attribute}} )
    {
        my $attribute_id = $attr->{id}->[0];
        my $default = "";
        if (exists $attr->{default})
        {
            $default = $attr->{default}->[0];
        }
        if (! exists $fileCommon->{targetType}->{$id}->{attribute}->{$attribute_id})
        {
            push @NewAttr, [ $id, $attribute_id, $default ];
        }
    }
}

# Pick up all new added targets which are platform specific fsp/hb, and push the
# same into an array "@NewTargetType"
my @NewTargetType;
foreach my $newTarget ( @{$filePlatform->{targetType}} )
{
    my $targetId = $newTarget->{id}->[0];
    push @NewTargetType, [$targetId, $newTarget];
}

#Create a new file from the common target types xml, over which
#the new targets from platform target types xml will be merged,
#then the extension targets will be merged over the existing one.

# Temporary File created for merger
my $file_name  = "merged_target_types_$$.xml";
open (my $FILE, '>', $file_name );# To be updated by reading FH
open (FH, "<$tgt_files[0]"); #To read out each line

my $check = 0;
my $id = "";
my $endOfLine = 0;
while (my $line = <FH>)
{
    if ( $line =~ /^\s*<targetType>.*/)
    {
        $check = 1;
    }
    elsif ($check == 1 && $line =~ /^\s*<id>/)
    {
        $check = 0;
        $id = $line;
        $id =~ s/\n//;
        $id =~ s/.*<id>(.*)<\/id>.*/$1/;
    }
    elsif ($line =~ /^\s*<\/targetType>.*/)
    {
        for my $i ( 0 .. $#NewAttr )
        {
            if ($NewAttr[$i][0] eq $id)
            {
                print $FILE "    <attribute>\n";
                print $FILE "        <id>$NewAttr[$i][1]</id>\n";
                if ($NewAttr[$i][2] ne "")
                {
                    print $FILE "        <default>$NewAttr[$i][2]</default>\n";
                }
                print $FILE "    </attribute>\n";
            }
        }
    }
    if ($line =~ /^\s*<\/attributes>.*/)
    {
        foreach my $newTarget (@NewTargetType)
        {
            print $FILE "<targetType>\n";
            print $FILE "    <id>$newTarget->[1]->{id}->[0]</id>\n";
            print $FILE "    <parent>$newTarget->[1]->{parent}->[0]</parent>\n";
            foreach my $attrNewTarget ( @{$newTarget->[1]->{attribute}} )
            {
                print $FILE "    <attribute>\n";
                print $FILE "        <id>$attrNewTarget->{id}->[0]</id>\n";
                if (exists $attrNewTarget->{default})
                {
                    if (ref($attrNewTarget->{default}->[0])  eq "HASH")
                    {
                        if(exists $attrNewTarget->{default}->[0]->{field})
                        {
                            print $FILE "        <default>\n";
                            print $FILE "            <field>\n";
                            foreach my $attrField ( @{$attrNewTarget->{default}->[0]->{field}} )
                            {
                                print $FILE "                <id>$attrField->{id}->[0]</id><value>$attrField->{value}->[0]</value>\n";
                            }
                            print $FILE "            </field>\n";
                            print $FILE "        </default>\n";
                        }
                    }
                    else
                    {
                        print $FILE "        <default>$attrNewTarget->{default}->[0]</default>\n";
                    }
                }
                print $FILE "    </attribute>\n";
            }
            if(exists $newTarget->[1]->{fspOnly})
            {
                print $FILE "    <fspOnly/>\n";
            }
            print $FILE "</targetType>\n";
        }
    }
    print $FILE "$line";
}

close (FH);
close ($FILE);


print "Loading Merged Targeting XML: $file_name\n";
#Load all the merged (common & platform) target_type xml
my $tgt_xmls = XMLin($file_name,
                forcearray => ['attribute', 'targetType', 'field', 'targetTypeExtension']);

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

#foreach targetInstance in the MRW file
foreach my $tgt
    ($mrw_parsed->findnodes('/attributes/targetInstance'))
{
    my $tgt_type = $tgt->findnodes('./type');

    #foreach attribute defined in this target
    foreach my $attr ($tgt->findnodes('./attribute'))
    {
        my $attr_id = $attr->findnodes('./id');
        #findAttribute searches for this target and attribute
        #pair in all the target type xmls
        my $found = findAttribute($tgt_type, $attr_id);
        if ($found eq 0)
        {
            #if the attribute is not found in any of the target_type
            #xmls, then remove it from the mrw xml
            print "Removing Attr: $attr_id from Target: $tgt_type \n";
            $tgt->removeChild($attr);
        }
        else
        {
            print "Found Attr $attr_id for Target Type $tgt_type\n";
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
    my $targetType;

    if (defined $tgt_xmls->{'targetType'}{$tgt}{attribute}{$attr})
    {
        #attribute found under the passed in target in this xml
        return 1;
    }
    else
    {
        my %tgt_hash = %$tgt_xmls;
        #if not found in this target, look under parent target
        #some targets are inherrited
        if (lookAtParentAttributes (\%tgt_hash, $tgt, $attr) eq 1)
        {
            return 1;
        }
    }
    return 0;
}

# sub - lookAtParentAttributes
#       recursively looks for an attribute in current
#       target's parent because some attributes are inherrited from parents
# param[in]: tgt_xmls - hash containing the entire target type xml
# param[in]: tgt - look at the parent of this target
# param[in]: attr - attribute to look for
# retval: true == attr found, false == attr not found
sub lookAtParentAttributes
{
    my ($tgt_xmls, $tgt, $attr) = @_;

    my $parent = $tgt_xmls->{'targetType'}{$tgt}{parent};
    if ($parent eq "")
    {
        return 0;
    }
    elsif ($parent eq "base")
    {
         return (defined  $tgt_xmls->{'targetType'}{$parent}{attribute}{$attr}) ?
                        1 : 0;
    }
    else
    {
        if (defined  $tgt_xmls->{'targetType'}{$parent}{attribute}{$attr})
        {
            return 1;
        }
        else
        {
            my %tgt_hash = %$tgt_xmls;
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
unlink($file_name);
