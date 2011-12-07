#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/Trace.pm $
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

package Hostboot::Trace;
use Exporter;
our @EXPORT_OK = ('main');

use constant MAX_NUM_TRACE_BUFFERS => 48;
use constant DESC_ARRAY_ENTRY_SIZE => 24;
use constant OFFSET_TRAC_BUFFER_SIZE => 20;
use constant OFFSET_BUFFER_ADDRESS => 16;

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

    my $foundBuffer = 0;

    for (my $i = 0; $i < MAX_NUM_TRACE_BUFFERS; $i++)
    {
        # component name is first in g_desc_array[$i]
        my $compName = ::readStr($symAddr);
        last if ($compName eq "");

        # get the pointer to its trace buffer
        my $buffAddr = ::read64($symAddr  + OFFSET_BUFFER_ADDRESS);

        # get the size of this trace buffer 
        my $buffSize = ::read32($buffAddr + OFFSET_TRAC_BUFFER_SIZE);

        if ((not defined $traceBuffers) or (uc($traceBuffers) =~ m/$compName/))
        {
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

sub help
{
    ::userDisplay "Tool: Trace\n";
    ::userDisplay "\tDisplays the trace buffer.\n";
    ::userDisplay "\n    Options:\n";
    ::userDisplay "\tfsp-trace=<path> - Path to non-default ".
                      "fsp-trace utility.\n";
    ::userDisplay "\tcomponents=<list> - Comma separated list of components\n".
                  "\t                    to display trace buffers for.\n";
    ::userDisplay "\twith-file-names - Trace statements will include file\n".
                  "\t                  name of place the trace was defined.\n";
}
