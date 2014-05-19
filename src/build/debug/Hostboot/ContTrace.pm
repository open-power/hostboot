#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/ContTrace.pm $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2012,2014
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

package Hostboot::ContTrace;
use Exporter;
our @EXPORT_OK = ('main');

use constant CONT_TRACE_ENABLE_FLAG_OFFSET => 0;
use constant CONT_TRACE_BUFFER_SIZE => CONT_TRACE_ENABLE_FLAG_OFFSET + 2;
use constant CONT_TRACE_BUFFER_ADDR => CONT_TRACE_BUFFER_SIZE + 6;

use File::Temp ('tempfile');

sub main
{
    my ($packName,$args) = @_;
    #::userDisplay("args fsp-trace ".$args->{"fsp-trace"}."\n");
    #::userDisplay("args with-file-names ".$args->{"with-file-names"}."\n");

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

    my $symAddr = 0;
    my $symSize = 0;

    ($symAddr, $symSize) = ::findSymbolAddress("TRACE::g_debugSettings");
    if (not defined $symAddr)
    {
        ::userDisplay "Cannot find symbol: TRACE::g_debugSettings.\n"; die;
    }

    if (defined $args->{"enable-cont-trace"})
    {
        my $new_enable = $args->{"enable-cont-trace"};
        $new_enable = $new_enable ? 2 : 1;

        my $enable = ::read8($symAddr + CONT_TRACE_ENABLE_FLAG_OFFSET);
        if ($dbgMsg)
        {
            ::userDisplay("current Cont Trace Enable Flag = $enable\n");
        }
        if (($enable < 2) && ($new_enable == 2))
        {
            # truncate tracMERG to 0
            system( "cp /dev/null tracMERG" );
        }

        ::write8($symAddr + CONT_TRACE_ENABLE_FLAG_OFFSET, $new_enable);
        if ($dbgMsg)
        {
            $new_enable = ::read8($symAddr+CONT_TRACE_ENABLE_FLAG_OFFSET);
            ::userDisplay("new Cont Trace Enable Flag = $new_enable\n");
        }

        return;
    }

    my $trigger = ::readScom(0x00050038);
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
    if (0 == $trigger)
    {
        if ($dbgMsg)
        {
            ::userDisplay("No new trace to gather.\n");
        }
        return;
    }

    my $fh;
    my $fname;
    ($fh,$fname) = tempfile();
    binmode($fh);

    my $buffAddr = ::read64($symAddr + CONT_TRACE_BUFFER_ADDR);
    my $buffSize = ::read16($symAddr + CONT_TRACE_BUFFER_SIZE);

    print $fh (::readData($buffAddr, $buffSize));

    if ($dbgMsg)
    {
        my $cycles = `simgetcurrentcycle`;
        $cycles =~ s/\n//g;
        $cycles =~ s/.*is ([0-9]*).*/$1/g;
        ::userDisplay("$cycles\n");
    }

    ::writeScom(0x00050038, 0x0);

    open TRACE, ($args->{"fsp-trace"}." -s ".::getImgPath().
                "hbotStringFile $fsptrace_options $fname |") || die;
    while (my $line = <TRACE>)
    {
        ::userDisplay $line;
    }

    unlink $fname;

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
                    "enable-cont-trace=<1|0>" => ["Turn on|off continuous trace"],
                    "debug" => ["Turn on debug messages"],
                   }
    );
}
