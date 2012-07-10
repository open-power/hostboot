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
#  IBM_PROLOG_END_TAG
use strict;

package Hostboot::ContTrace;
use Exporter;
our @EXPORT_OK = ('main');

use constant MAX_NUM_CONT_TRACE_CTL_STRUCT => 2;
use constant CONT_TRACE_CTL_STRUCT_SIZE => 16;
use constant CONT_TRACE_ENABLE_FLAG_OFFSET => MAX_NUM_CONT_TRACE_CTL_STRUCT * CONT_TRACE_CTL_STRUCT_SIZE;
use constant MAX_NUM_CONT_TRACE_BUFFERS => 2;
use constant DDWORD_SIZE => 8;
use constant WORD_SIZE => 4;
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

    my $dbgMsg = 0;
    if (defined $args->{"debug"})
    {
        $dbgMsg = 1;
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

    my $on2off = 0;
    my $symAddr = 0;
    my $symSize = 0;

    if (defined $args->{"enable-cont-trace"})
    {
        my $new_enable = $args->{"enable-cont-trace"};
        $new_enable = $new_enable ? 2 : 0;
        ($symAddr, $symSize) =
                      ::findSymbolAddress("TRACE::g_cont_trace_trigger_info");
        if (not defined $symAddr)
        {
            ::userDisplay "Cannot find symbol.\n"; die;
        }
        my $enable = ::read64($symAddr + CONT_TRACE_ENABLE_FLAG_OFFSET);
        if ($dbgMsg)
        {
            ::userDisplay("current Cont Trace Enable Flag = $enable\n");
        }
        if (($enable < 2) && ($new_enable == 2))
        {
            # truncate tracMERG to 0
            system( "cp /dev/null tracMERG" );
            ::write64($symAddr + CONT_TRACE_ENABLE_FLAG_OFFSET, $new_enable);
            if ($dbgMsg)
            {
                $new_enable = ::read64($symAddr+CONT_TRACE_ENABLE_FLAG_OFFSET);
                ::userDisplay("new Cont Trace Enable Flag = $new_enable\n");
            }
            return;
        }
        elsif (($enable == 2) && ($new_enable == 0))
        {
            $on2off = 1;
            $last = 0;
        }
        else
        {
            return;
        }
    }

    my $trigger = "simGETFAC B0.C0.S0.P0.E8.TPC.FSI.FSI_MAILBOX.FSXCOMP." .
                  "FSXLOG.LBUS_MAILBOX.Q_GMB2E0.NLC.L2 32";
    $trigger = `$trigger`;
    $trigger =~ s/.*\n0xr(.*)\n.*/$1/g;
    $trigger =~ s/\n//g;
    if ($dbgMsg)
    {
        ::userDisplay("$trigger...\n");
        my $cycles = `simgetcurrentcycle`;
        $cycles =~ s/\n//g;
        $cycles =~ s/.*is ([0-9]*).*/$1/g;
        ::userDisplay("$cycles\n");
        $cycles = `date`;
        ::userDisplay("$cycles");
    }
    if (($trigger !~ /[1-9a-fA-F]+/) && ($last == 0))
    {
        if ($on2off)
        {
            ::write64($symAddr + CONT_TRACE_ENABLE_FLAG_OFFSET, 0);
            if ($dbgMsg)
            {
                $on2off = ::read64($symAddr + CONT_TRACE_ENABLE_FLAG_OFFSET);
                ::userDisplay("new Cont Trace Enable Flag = $on2off\n");
            }
        }
        if ($dbgMsg)
        {
            my $cycles = `date`;
            ::userDisplay("$cycles");
        }
        return;
    }

    ($symAddr, $symSize) =
                      ::findSymbolAddress("TRACE::g_cont_trace_trigger_info");
    if (not defined $symAddr) { ::userDisplay "Cannot find symbol.\n"; die; }

    my @fh;
    my @fname;
    ($fh[0],$fname[0]) = tempfile();
    binmode($fh[0]);
    ($fh[1],$fname[1]) = tempfile();
    binmode($fh[1]);

    # read the g_cont_trace_trigger_info structure
    my $result = ::readData($symAddr, $symSize);

    my $addrOff = 0;
    my $lenOff = $addrOff + DDWORD_SIZE;
    my $seqOff = $lenOff + WORD_SIZE;
    my $foundBuffer = 0;
    my @seqNum;

    for (my $i = 0; $i < MAX_NUM_CONT_TRACE_BUFFERS; $i++)
    {
        # get the pointer to the continuous trace buffer
        my $buffAddr = substr $result, $addrOff, DDWORD_SIZE;
        $buffAddr= hex (unpack('H*',$buffAddr));
        my $buffLen = substr $result, $lenOff, WORD_SIZE;
        $buffLen= hex (unpack('H*',$buffLen));
        $seqNum[$i] = substr $result, $seqOff, WORD_SIZE;
        $seqNum[$i]= hex (unpack('H*',$seqNum[$i]));
        if ($dbgMsg)
        {
            ::userDisplay("Trigger [".$i."] = $buffAddr\n");
            ::userDisplay("Length  [".$i."] = $buffLen\n");
            ::userDisplay("SeqNum  [".$i."] = $seqNum[$i]\n");
        }

        my $fhandle = $fh[$i];
        # If trigger bit is set, or last call and buffer has trace data
        if ((0 != ($buffAddr & TRIG_BIT)) || (($last == 1) && ($buffLen > 1)))
        {
            $foundBuffer |= (1 << $i);
            $buffAddr &= ~TRIG_BIT;
            print $fhandle (::readData($buffAddr, $buffLen));

            # reset trigger bit
            ::write64($symAddr + $addrOff, $buffAddr);

            # reset count to 1
            ::write32($symAddr + $lenOff, 1);
        }

        # increment to next element in g_cont_trace_trigger_info.triggers[]
        $addrOff += (2 * DDWORD_SIZE);
        $lenOff = $addrOff + DDWORD_SIZE;
        $seqOff = $lenOff + WORD_SIZE;
    }

    if ($dbgMsg)
    {
        my $cycles = `simgetcurrentcycle`;
        $cycles =~ s/\n//g;
        $cycles =~ s/.*is ([0-9]*).*/$1/g;
        ::userDisplay("$cycles\n");
    }

    if ($on2off)
    {
        ::write64($symAddr + CONT_TRACE_ENABLE_FLAG_OFFSET, 0);
        if ($dbgMsg)
        {
            $on2off = ::read64($symAddr + CONT_TRACE_ENABLE_FLAG_OFFSET);
            ::userDisplay("new Cont Trace Enable Flag = $on2off\n");
        }
    }

    if (($foundBuffer == 3) && ($seqNum[1] < $seqNum[0]))
    {
        my $tmp = $fname[0];
        $fname[0] =$fname[1];
        $fname[1] = $tmp;
    }

    for (my $i = 0; $i < MAX_NUM_CONT_TRACE_BUFFERS; $i++)
    {
        if (($foundBuffer & (1 << $i)))
        {
            #my $cmd = "cp " . $fname[$i] . " tracMERG." . $seqNum[$i];
            #system ( $cmd );
            open TRACE, ($args->{"fsp-trace"}." -s ".
               ::getImgPath()."hbotStringFile $fsptrace_options $fname[$i] |");
            while (my $line = <TRACE>)
            {
                ::userDisplay $line;
            }
        }
        unlink($fname[$i]);
    }

    if ($dbgMsg)
    {
        my $cycles = `date`;
        ::userDisplay("$cycles");
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
                    "enable-cont-trace=<1|0>" => ["Turn on|off continuous trace"],
                    "debug" => ["Turn on debug messages"],
                   }
    );
}
