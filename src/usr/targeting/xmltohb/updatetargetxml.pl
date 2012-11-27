#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/xmltohb/updatetargetxml.pl $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG

#
# Original file created by Van Lee for fsp.
# File copied to Hostboot and modified by CamVan Nguyen
#
# Usage:
#
#    updatetargetxml --hb=target_types_hb.xml --common=target_types.xml
#
# Purpose:
#
#   This perl script processes the target_types_hb.xml file to find the
#   <targetTypeExtension> tags, and update target_types.xml if needed.
#   The updated target_types.xml is written to the console.
#

use strict;
use XML::Simple;
use Data::Dumper;

my $hb = "";
my $common = "";
my $usage = 0;
use Getopt::Long;
GetOptions( "hb:s"       => \$hb,
            "common:s"   => \$common,
            "help"       => \$usage, );

if ($usage || ($hb eq "") || ($common eq ""))
{
    display_help();
    exit 0;
}

open (FH, "<$hb") ||
    die "ERROR: unable to open $hb\n";
close (FH);

my $generic = XMLin("$hb", ForceArray=>1);

open (FH, "<$common") ||
    die "ERROR: unable to open $common\n";
close (FH);

my $generic1 = XMLin("$common");

my @NewAttr;
foreach my $Extension ( @{$generic->{targetTypeExtension}} )
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
        #print "$id, $attribute_id $default\n";
        if (! exists $generic1->{targetType}->{$id}->{attribute}->{$attribute_id})
        {
            push @NewAttr, [ $id, $attribute_id, $default ];
        }
    }
}

open (FH, "<$common");

my $check = 0;
my $id = "";
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
                print "    <attribute>\n";
                print "        <id>$NewAttr[$i][1]</id>\n";
                if ($NewAttr[$i][2] ne "")
                {
                    print "        <default>$NewAttr[$i][2]</default>\n";
                }
                print "    </attribute>\n";
            }
        }
    }
    print "$line";
}

close (FH);

sub display_help
{
    use File::Basename;
    my $scriptname = basename($0);
    print STDERR "
Usage:

    $scriptname --help
    $scriptname --hb=hbfname --hb=commonfname
        --hb=hbfname
              hbfname is the complete pathname of the target_types_hb.xml file
        --common=commonfname
              commonfname is the complete pathname of the target_types.xml file
\n";
}
