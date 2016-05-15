#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/ContTrace.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2016
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

package Hostboot::ContTrace;
use Exporter;
our @EXPORT_OK = ('main');

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


    if (defined $args->{"enable-cont-trace"})
    {
        ::userDisplay("enable-cont-trace not supported anymore\n")
        ::userDisplay("Use istep control with istep 255.0 to disable\n"
        ::userDisplay("Use istep control with istep 255.1 to enable\n"

        return;
    }

    #HB will place the trace buffer address in MBOX_SCRATCH1 (0x50038) when
    #there is a buf to be extracted.  Trigger off of this
    my $trigger = ::readScom(0x00050038, 8);
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

    #Trigger has the buffer, address MBOX_SCRATCH2 has size
    my $buffAddr = $trigger >> 32;
    my $buffSize = ::readScom(0x00050039, 8) >> 32;

    print $fh (::readData($buffAddr, $buffSize));

    if ($dbgMsg)
    {
        my $cycles = `simgetcurrentcycle`;
        $cycles =~ s/\n//g;
        $cycles =~ s/.*is ([0-9]*).*/$1/g;
        ::userDisplay("$cycles\n");
    }

    #Write MBOX_SCRATCH1 to zero to indicate to HB that we have
    #extracted the buffer and it can continue on its way
    ::writeScom(0x00050038, 8, 0x0);

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
                    "debug" => ["Turn on debug messages"],
                   }
    );
}
