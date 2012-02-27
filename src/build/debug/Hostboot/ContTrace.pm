#!/usr/bin/perl
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/ContTrace.pm $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
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

package Hostboot::ContTrace;
use Exporter;
our @EXPORT_OK = ('main');

use constant MAX_NUM_CONT_TRACE_BUFFERS => 2;
use constant DDWORD_SIZE => 8;
use constant TRIG_BIT => 0x8000000000000000;

use File::Temp ('tempfile');

sub main
{
    my ($packName,$args) = @_;
    #::userDisplay("args fsp-trace ".$args->{"fsp-trace"}."\n");
    #::userDisplay("args with-file-names ".$args->{"with-file-names"}."\n");
    #::userDisplay("args last ".$args->{"last"}."\n");

    if (not defined $args->{"fsp-trace"})
    {
        $args->{"fsp-trace"} = "fsp-trace";
    }

    my $fsptrace_options = "";
    if (defined $args->{"with-file-names"})
    {
        $fsptrace_options = $fsptrace_options."-f ";
    }

    my $last = 0;
    if (defined $args->{"last"})
    {
        $last = 1;
    }

    my ($symAddr, $symSize) =
                      ::findSymbolAddress("TRACE::g_cont_trace_trigger_info");
    if (not defined $symAddr) { ::userDisplay "Cannot find symbol.\n"; die; }

    my ($fh,$fname) = tempfile();
    binmode($fh);

    # read the g_cont_trace_trigger_info structure
    my $result = ::readData($symAddr, $symSize);

    my $addrOff = 0;
    my $lenOff = $addrOff + DDWORD_SIZE;
    my $foundBuffer = 0;

    for (my $i = 0; $i < MAX_NUM_CONT_TRACE_BUFFERS; $i++)
    {
        # get the pointer to the continuous trace buffer
        my $buffAddr = substr $result, $addrOff, DDWORD_SIZE;
        $buffAddr= hex (unpack('H*',$buffAddr));
        my $buffLen = substr $result, $lenOff, DDWORD_SIZE;
        $buffLen= hex (unpack('H*',$buffLen));
        #::userDisplay("Trigger [".$i."] = $buffAddr\n");
        #::userDisplay("Length  [".$i."] = $buffLen\n");

        # If trigger bit is set, or last call and buffer has trace data
        if ((0 != ($buffAddr & TRIG_BIT)) || (($last == 1) && ($buffLen > 1)))
        {
            $foundBuffer = 1;
            $buffAddr &= ~TRIG_BIT;
            print $fh (::readData($buffAddr, $buffLen));

            # reset trigger bit
            ::write64($symAddr + $addrOff, $buffAddr);

            # reset count to 1
            ::write64($symAddr + $lenOff, 1);
        }

        # increment to next element in g_cont_trace_trigger_info.triggers[]
        $addrOff += (2 * DDWORD_SIZE);
        $lenOff = $addrOff + DDWORD_SIZE;
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

}

sub helpInfo
{
    my %info = (
        name => "ContTrace",
        intro => ["Displays the continuous trace buffers."],
        options => {
                    "fsp-trace=<path>" => ["Path to non-default fsp-trace utility."],
                    "with-file-names" => ["Trace statements will include file name of place the",
                                          "trace was defined."],
                    "last" => ["Shutdown call to offload remaining traces."],
                   },
    );
}
