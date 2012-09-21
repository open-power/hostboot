#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Dump.pm $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2012
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

use strict;

package Hostboot::Printk;
use Exporter;
our @EXPORT_OK = ('main');

use constant    L3_SIZE =>  0x800000;

sub main
{
    my ($packName,$args) = @_;

    #Get current timestamp
    my $timeStamp = `date +%Y%m%d%H%M`;
    chomp $timeStamp;
    #::userDisplay "timestamp: $timeStamp\n";

    my  $hbDumpFile =   "hbdump.$timeStamp";

    ::userDisplay "Dumping L3 to Open output file $hbDumpFile..\n";
    open( OUTFH, ">$hbDumpFile" )   or die "can't open $hbDumpFile: $!\n";

    ## read in 8 MB!!
    my $data = ::readData( 0, L3_SIZE );
    write( OUTFH, $data );
    close( OUTFH )  or die "can't close $hbDumpFile: $!\n";


    #Check if hbDumpFile exists and is not empty
    if (-s "$hbDumpFile" )
    {
        ::userDisplay "\nHostBoot dump saved to $hbDumpFile.\n";
        ::userDisplay "Use hb-parsedump.pl program to parse the dump.\n";
    }
    else
    {
        ::userDisplay "\nWARNING: Cannot dump L3.  Did you stop instructions?\n\n";
        unlink $hbDumpFile;
    }
}

sub helpInfo
{
    my %info = (
        name => "Dump",
        intro => ["Dumps the entire L3 buffer to a file."],
    );
}
