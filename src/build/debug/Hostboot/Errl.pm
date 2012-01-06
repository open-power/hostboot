#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/Errl.pm $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END

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

    my ($symAddr, $symSize) = ::findSymbolAddress("ERRORLOG::g_ErrlStorage");
    if (not defined $symAddr)
    {
        ::userDisplay "Couldn't find symbol ERRORLOG::g_ErrlStorage\n";
        die;
    }

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
    $imagePath = ::determineImagePath();
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
    $cmdLine = "$errlParser $tempFile $displayArg $traceArg $listArg";
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
                   },
        notes => ["The default behavior is to list all the committed error logs unless",
                  "requested to display a specific error log or all error logs."]
    );
}

