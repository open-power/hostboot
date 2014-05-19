#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/genNodeMrwXml.pl $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2013,2014
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
# Usage:
#
# genNodeMrwXml.pl --system=systemname --mrwdir=pathname
#                  --build=hb/fsp --nodeCount=nodeCount
#                  [--help]
#                  
#        --system=systemname
#              Specify which system MRW XML to be generated. 
#              The file name will be set as uppercase 
#        --mrwdir=pathname
#              Specify the complete dir pathname of the MRW. Colon-delimited
#              list accepted to specify multiple directories to search.
#        --outfileDir=pathname
#              Specify the complete dir pathname to where output files should
#              be created
#        --build=hb/fsp
#              Specify if HostBoot build (hb) or FSP build (fsp)
#        --nodeCount
#              Specify the max number of nodes for the system
#        --help 
#             displays usage
#
# Purpose:
#
#   This perl script processes the various xml files of the Tuleta MRW to
#   extract the needed information for generating the final xml file.
#

use strict;
use XML::Simple;
use Data::Dumper;

################################################################################
# Set PREFERRED_PARSER to XML::Parser. Otherwise it uses XML::SAX which contains
# bugs that result in XML parse errors that can be fixed by adjusting white-
# space (i.e. parse errors that do not make sense).
################################################################################
$XML::Simple::PREFERRED_PARSER = 'XML::Parser';

################################################################################
#main
################################################################################
my $mrwdir = "";
my $sysname = "";
my $usage = 0;
my $nodeCount = 0;
my $outFileDir = "";
my $build = "fsp";
use Getopt::Long;

GetOptions( "mrwdir:s"  => \$mrwdir,
            "system:s"  => \$sysname,
            "nodeCount:i" => \$nodeCount,
            "outfileDir:s" => \$outFileDir,
            "build:s"   => \$build,
            "help"      => \$usage, );


if ($usage || ($mrwdir eq "") || ($sysname eq "") || ($outFileDir eq ""))
{
    display_help();
    exit 0;
}

if ($nodeCount ==0)
{
    #no nodes so don't need to create node xml files
    exit 0;
}

my $SYSNAME = uc($sysname);

my $outFile = "";
my @nodeOutFiles;

my $sysInfo;
my $fileSuffix;

if ($build eq "fsp")
{
    $fileSuffix="fsp";
}
elsif ($build eq "hb")
{
    $fileSuffix="hb";
}
else
{
    die "ERROR: $build is not valid. Valid values are fsp or hb\n";
}


#create files
my $mrw_file = open_mrw_file($mrwdir, "${SYSNAME}_${fileSuffix}.mrw.xml");
$sysInfo = XMLin($mrw_file,
                ForceArray=>1);
#print Dumper($sysInfo);
for my $j(0..($nodeCount))
{
    $outFile = "$outFileDir/${SYSNAME}_node_$j"."_${fileSuffix}.mrw.xml";
    push @nodeOutFiles, [$outFile];
}

#create file discriptor array
my @nodeFD;

for my $k(0..$#nodeOutFiles)
{
    my $filename= sprintf("%s",@{$nodeOutFiles[$k]});

    open $nodeFD[$k], '>', $filename ||
        die "ERROR: unable to create $filename\n";
}

#read in the targeting data from system xml files
foreach my $targetInstance (@{$sysInfo->{targetInstance}})
{
    my $Id = $targetInstance->{'id'};
    my $targetId = sprintf("%s",@{$Id});
    #print("targetId =", $targetId, "\n");
    my $xmlData= XMLout($targetInstance,RootName => "targetInstance");  
    #print Dumper($xmlData);
    if ($targetId eq "sys0")
    {
        for my $node(0..$nodeCount)
        {
            print {$nodeFD[$node]} $xmlData;
        }
    }
    else 
    {
        my $nodeValue = $targetId;
        $nodeValue =~ s/.*node(\d?).*/$1/;

        if ($nodeValue < $#nodeFD ) 
        {
            print {$nodeFD[$nodeValue]} $xmlData;
        }
        elsif ($nodeValue == $#nodeFD)
        {
            print {$nodeFD[0]} $xmlData;
        }
        else
        {
            die "ERROR: node value($nodeValue) is not in the range of possible nodes\n";
        }
    }

}

#close file descriptors
for my $k(0..$#nodeOutFiles)
{
    my $filename= sprintf("%s",@{$nodeOutFiles[$k]});

    close $nodeFD[$k] ||
        die "ERROR: unable to close $filename\n";
}

exit 0;

################################################################################
#subroutines below
################################################################################
#subroutines below

sub open_mrw_file
{
    my ($paths, $filename) = @_;

    #Need to get list of paths to search
    my @paths_to_search = split /:/, $paths;
    my $file_found = "";

    #Check for file at each directory in list
    foreach my $path (@paths_to_search)
    {
        if ( open (FH, "<$path/$filename") )
        {
            $file_found = "$path/$filename";
            close(FH);
            last; #break out of loop
        }
    }

    if ($file_found eq "")
    {
        #If the file was not found, build up error message and exit
        my $err_msg = "Could not find $filename in following paths:\n";
        foreach my $path (@paths_to_search)
        {
            $err_msg = $err_msg."  $path\n";
        }
        die $err_msg;
    }
    else
    {
        #Return the full path to the file found
        return $file_found;
    }
}

sub display_help
{
    use File::Basename;
    my $scriptname = basename($0);
    print STDERR "
Usage:
    $scriptname --help
        --help
             displays usage


    $scriptname --system=sysname --mrwdir=pathname
                     --build=hb --nodeCount=nodeCount
        --system=systemname
              Specify which system MRW XML to be generated
               The system name will be set as uppercase
        --mrwdir=pathname
              Specify the complete dir pathname of the MRW. Colon-delimited
              list accepted to specify multiple directories to search.
        --outfileDir=pathname
              Specify the complete dir pathname to where output files should
              be created
        --build=hb/fsp
              Specify if HostBoot build (hb) or FSP build (fsp)
        --nodeCount
              Specify the max number of nodes for the system

\n";
}

