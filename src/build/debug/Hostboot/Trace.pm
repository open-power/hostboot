#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/Trace.pm $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011-2012
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
#  IBM_PROLOG_END_TAG
use strict;

package Hostboot::Trace;
use Exporter;
our @EXPORT_OK = ('main');

use constant MAX_NUM_TRACE_BUFFERS => 48;
use constant DESC_ARRAY_ENTRY_SIZE => 24;
use constant OFFSET_TRAC_BUFFER_SIZE => 20;
use constant OFFSET_BUFFER_ADDRESS => 16;
use constant BUFFER_ADDRESS_SIZE => 8;

use File::Temp ('tempfile');

sub main
{
    my ($packName,$args) = @_;

    if (not defined $args->{"fsp-trace"})
    {
        $args->{"fsp-trace"} = "fsp-trace";
    }

    my $fsptrace_options = "";
    if (defined $args->{"with-file-names"})
    {
        $fsptrace_options = $fsptrace_options."-f ";
    }

    my $traceBuffers = $args->{"components"};

    my ($symAddr, $symSize) = ::findSymbolAddress("TRACE::g_desc_array");
    if (not defined $symAddr) { ::userDisplay "Cannot find symbol.\n"; die; }

    my ($fh,$fname) = tempfile();
    binmode($fh);

    # read the entire g_desc_array instead of reading each entry which is much slower in VBU
    my $result = ::readData($symAddr, $symSize);

    $symAddr = 0;
    my $foundBuffer = 0;

    for (my $i = 0; $i < MAX_NUM_TRACE_BUFFERS; $i++)
    {
        # component name is first in g_desc_array[$i]
        my $compName = substr $result, $symAddr, OFFSET_BUFFER_ADDRESS;
        # strip off null paddings
        $compName = unpack('A*', $compName);
        last if ($compName eq "");

        if ((not defined $traceBuffers) or (uc($traceBuffers) =~ m/$compName/))
        {
            # get the pointer to its trace buffer
            my $buffAddr = substr $result, $symAddr + OFFSET_BUFFER_ADDRESS, BUFFER_ADDRESS_SIZE;
            $buffAddr= hex (unpack('H*',$buffAddr));

            # get the size of this trace buffer
            my $buffSize = ::read32($buffAddr + OFFSET_TRAC_BUFFER_SIZE);

            $foundBuffer = 1;
            print $fh (::readData($buffAddr, $buffSize ));
        }

        # increment to next item in g_desc_array[]
        $symAddr += DESC_ARRAY_ENTRY_SIZE;
    }

    if ($foundBuffer)
    {
        open TRACE, ($args->{"fsp-trace"}." -s ".
                    ::getImgPath()."hbotStringFile $fsptrace_options $fname |");
        while (my $line = <TRACE>)
        {
            ::userDisplay $line;
        }
    }
    else
    {
        ::userDisplay("No matching buffers found.\n");
    }

    unlink($fname);
}

sub helpInfo
{
    my %info = (
        name => "Trace",
        intro => ["Displays the trace buffer."],
        options => {
                    "fsp-trace=<path>" => ["Path to non-default fsp-trace utility."],
                    "components=<list>" =>["Comma separated list of components to display trace",
                                           "buffers for."],
                    "with-file-names" => ["Trace statements will include file name of place the",
                                          "trace was defined."],
                   },
    );
}
