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

use constant MAX_NUM_TRACE_BUFFERS => 24;
use constant DESC_ARRAY_ENTRY_ADDR_SIZE => 8;
use constant DESC_ARRAY_ENTRY_COMP_NAME_SIZE => 16;
use constant TRAC_DEFAULT_BUFFER_SIZE => 0x0800;

use File::Temp ('tempfile');

sub main
{
    my ($packName,$args) = @_;

    if (not defined $args->{"fsp-trace"})
    {
        $args->{"fsp-trace"} = "fsp-trace";
    }

    my $traceBuffers = $args->{"components"};

    my ($symAddr, $symSize) = ::findSymbolAddress("TRACE::g_desc_array");
    if (not defined $symAddr) { ::userDisplay "Cannot find symbol.\n"; die; }

    my ($fh,$fname) = tempfile();
    binmode($fh);

    my $foundBuffer = 0;

    for (my $i = 0; $i < MAX_NUM_TRACE_BUFFERS; $i++)
    {
        my $compName = ::readStr($symAddr);
        last if ($compName eq "");

        $symAddr += DESC_ARRAY_ENTRY_COMP_NAME_SIZE;

        my $buffAddr = ::read64($symAddr);
        $symAddr += DESC_ARRAY_ENTRY_ADDR_SIZE;

        if ((not defined $traceBuffers) or ($traceBuffers =~ m/$compName/))
        {
            $foundBuffer = 1;            
            print $fh (::readData($buffAddr, TRAC_DEFAULT_BUFFER_SIZE));
        }
    }
    
    if ($foundBuffer)
    {
        open TRACE, ($args->{"fsp-trace"}." -s ".
                    ::getImgPath()."hbotStringFile -f $fname |");
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
}
