#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Errl.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2022
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

use strict;
use File::Temp;

package Hostboot::Errl;
use Exporter;
our @EXPORT_OK = ('main');


sub getTempFileName
{
    my $fh = File::Temp->new( TEMPLATE => 'tempXXXXX',
                              DIR => '/tmp',
                              SUFFIX => '.bin', );
    return $fh->filename;
}



sub main
{
    my $moduleName = shift;
    # print "Module name: $moduleName\n";

    my $listArg = " -l "; #  default action is to list
    my $displayArg = "";  #  for -d <error log id>
    my $traceArg = "";    #  for the name of the hbot string file
    my $errlpathArg = ""; #  path to errl exe
    my $verboseArg = ""; #  verbosity arg

    my %hashh = %{(shift)};
    my $temp;
    foreach $temp (keys(%hashh))
    {
        # print "$temp=" . $hashh{$temp} . "\n";

        if ( $temp eq "display" )
        {
            $displayArg = " -d ".$hashh{$temp};

            # display <id> overrides default behavior to list them all
            $listArg = "";
        }
        elsif( $temp eq "trace" )
        {
            $traceArg = " -t ".$hashh{$temp};
        }
        elsif( $temp eq "errl" )
        {
            $errlpathArg = " -e ".$hashh{$temp};
        }
        elsif( $temp eq "verbose" )
        {
            $verboseArg = "-v";
        }
        elsif( length($temp) eq 0  )
        {
           ; # apparently $temp can be empty
        }
        else
        {
            ::userDisplay "Unknown parameter $temp\n";
            die;
        }
    }

    my ($symAddr, $symSize) = ::findPointer("ERRORLOG",
                                            "ERRORLOG::g_ErrlStorage");
    if (not defined $symAddr)
    {
        ::userDisplay "Couldn't find symbol ERRORLOG::g_ErrlStorage\n";
        die;
    }
    $symAddr = ::read64($symAddr); # Dereference g_ErrlStorage pointer.

    # Size of buffer resides at offset zero of buffer for length of 4
    my $errlSize;
    $errlSize = ::read32( $symAddr );

    # read entire buffer
    my $errlBuffer;
    $errlBuffer = ::readData( $symAddr, $errlSize );

    # write buffer to a temporary file
    my $tempFile = getTempFileName();
    open( ERRLDATA, "> $tempFile" ) or die "Can not write temporary file $tempFile\n";
    binmode ERRLDATA;
    print ERRLDATA $errlBuffer;
    close( ERRLDATA );

    my $imagePath;
    $imagePath = ::getImgPath();
    if (not defined $imagePath)
    {
        ::userDisplay "Can not find img path to errlparser binary.\n";
        die;
    }

    my $errlParser;
    $errlParser = $imagePath."/errlparser";
    if( not  -x  $errlParser )
    {
        ::userDisplay "Can not find errlparser binary in img directory.\n";
        die;
    }

    if( length( $traceArg ) eq 0 )
    {
        # string file not given; supply a default if possible
        my $defaultStringFile = $imagePath."/hbotStringFile";
        if( -f  $defaultStringFile )
        {
            $traceArg = " -t ".$defaultStringFile;
        }
    }


    my $cmdLine;
    $cmdLine = "$errlParser $tempFile $displayArg $traceArg $listArg $errlpathArg $verboseArg";
    # ::userDisplay "$cmdLine\n";
    open ERRLPARSER, "$cmdLine |";
    while (my $line = <ERRLPARSER>)
    {
        ::userDisplay $line;
    }

    # delete temporary file
    unlink( $tempFile );


    return 0;
}

sub helpInfo
{
    my %info = (
        name => "Errl",
        intro => ["List or display the error log entries."],
        options => {
                    "display=<id>|all" => ["<id> - Display a specific error log by id.",
                                           "all - Display all error logs in the repository."],
                    "trace=<hbotStringFile>" => ["Path to hbotStringFile"],
                    "errl=<errl exe>" => ["Path to errl executable"],
                    "verbose" => ["Verbose output"],
                   },
        notes => ["The default behavior is to list all the committed error logs unless",
                  "requested to display a specific error log or all error logs."]
    );
}

