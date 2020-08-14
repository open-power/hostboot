#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Trace.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2020
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

package Hostboot::Trace;
use Hostboot::_DebugFrameworkVMM qw(NotFound NotPresent getPhysicalAddr);

use Exporter;
our @EXPORT_OK = ('main');

use constant TRACE_BUFFER_COUNT => 2;
use constant DAEMON_FIRST_BUFFER_PAGE_OFFSET => 8;
use constant DAEMON_FIRST_TEMP_BUFFER_PAGE_OFFSET =>
                    DAEMON_FIRST_BUFFER_PAGE_OFFSET + 16;
use constant BUFFER_FIRST_PAGE_OFFSET => 16;
use constant BUFFER_PAGE_NEXT_OFFSET => 0;
use constant BUFFER_PAGE_PREV_OFFSET => BUFFER_PAGE_NEXT_OFFSET + 8;
use constant BUFFER_PAGE_SIZE_OFFSET => BUFFER_PAGE_PREV_OFFSET + 12;
use constant BUFFER_PAGE_DATA_OFFSET => BUFFER_PAGE_SIZE_OFFSET + 4;
use constant ENTRY_COMP_OFFSET => 0;
use constant ENTRY_SIZE_OFFSET => 26;
use constant ENTRY_SIZE => 28;
use constant BIN_ENTRY_SIZE_OFFSET => 12;
use constant BIN_ENTRY_SIZE => 24;

use File::Temp qw(tempfile tempdir);
use File::Which;

sub main
{
    my ($packName,$args) = @_;

    if (not defined $args->{"fsp-trace"})
    {
        $args->{"fsp-trace"} = "fsp-trace";
        my $fspTracePath = which($args->{"fsp-trace"});
        if (not defined $fspTracePath)
        {
            ::userDisplay("Error: fsp-trace not in PATH.\n");
            die;
        }
    }
    else
    {
        if (!(-x $args->{"fsp-trace"}))
        {
            ::userDisplay("$args->{'fsp-trace'} is not executable.");
            die;
        }
    }

    my $fsptrace_options = "";
    if (defined $args->{"with-file-names"})
    {
        $fsptrace_options = $fsptrace_options."-f ";
    }

    my $traceBuffers = $args->{"components"};
    if (defined $traceBuffers)
    {
        $traceBuffers = uc $traceBuffers;
    }

    my $tmpdir = tempdir(CLEANUP => 1);
    open (my $fh, ">", $tmpdir."/tracBINARY");
    binmode($fh);
    my $foundBuffer = 0;
    print $fh "\2";

    # Make sure there is an hbotStringFile to use later
    if (!(-r ::getImgPath()."hbotStringFile"))
    {
        ::userDisplay("Couldn't read ". ::getImgPath()."hbotStringFile");
        die;
    }

    my ($daemonAddr, $daemonSize) =::findPointer("TRACEDMN",
           "Singleton<TRACEDAEMON::Daemon>::instance()::instance");

    my ($serviceAddr, $serviceSize) = ::findPointer("TRACESVC",
           "Singleton<TRACE::Service>::instance()::instance");

    if ((not defined $daemonAddr) || (not defined $serviceAddr))
    {
        ::userDisplay "Cannot find trace daemon and/or service.\n";
        die;
    }

    my @bufferPages = ();
    my %components = ();


    $daemonAddr = getPhysicalAddr($daemonAddr);
    unless (($daemonAddr eq NotFound) || ($daemonAddr eq NotPresent))
    {
        my $firstPage = ::read64($daemonAddr + DAEMON_FIRST_BUFFER_PAGE_OFFSET);
        readPage($firstPage, BUFFER_PAGE_PREV_OFFSET, \@bufferPages);

        for(my $i = 0; $i < TRACE_BUFFER_COUNT; $i++)
        {
            my $page =
                ::read64($daemonAddr + DAEMON_FIRST_TEMP_BUFFER_PAGE_OFFSET +
                         8*$i);

            readPage($page, BUFFER_PAGE_PREV_OFFSET, \@bufferPages);
        }
    }

    for(my $i = 0; $i < TRACE_BUFFER_COUNT; $i++)
    {
        my $buffer = ::read64($serviceAddr + 8*$i);
        my $page = ::read64($buffer + BUFFER_FIRST_PAGE_OFFSET);
        $page = extractABAptr($page);

        readPage($page, BUFFER_PAGE_PREV_OFFSET, \@bufferPages);
    }

    while(@bufferPages)
    {
        my $page = shift @bufferPages;

        my $size = readBuf32($page, BUFFER_PAGE_SIZE_OFFSET) +
                        BUFFER_PAGE_DATA_OFFSET;
        my $offset = BUFFER_PAGE_DATA_OFFSET;

        # Read each entry.
        while($offset < $size)
        {
            my $entry_size = readBuf16($page, ENTRY_SIZE_OFFSET + $offset);
            my $compAddr = readBuf64($page, ENTRY_COMP_OFFSET + $offset);

            if (0 ne $compAddr)
            {
                my $component = lookupComponent($compAddr,
                        \%components);

                if ((not defined $traceBuffers) ||
                    ($traceBuffers =~ m/$component/))
                {
                    $foundBuffer = 1;

                    print $fh $component;
                    print $fh "\0";

                    my $entry_data =
                        substr $page, ENTRY_SIZE + $offset, $entry_size;

                    my $bin_entry_size = BIN_ENTRY_SIZE +
                        readBuf16($entry_data, BIN_ENTRY_SIZE_OFFSET);

                    $entry_data = substr $entry_data, 0, $bin_entry_size;

                    print $fh $entry_data;
                }
            }

            $offset += $entry_size + ENTRY_SIZE;
            $offset = round8($offset);
        }

    }

    if ($foundBuffer)
    {
        # Note: 'sort -s -k 1,1' restricts the sort to only act on the first
        #   column (i.e. the timestamp) to avoid reordering traces that have
        #   identical timestamps
        open TRACE, ($args->{"fsp-trace"}." $tmpdir -s ".
                    ::getImgPath()."hbotStringFile $fsptrace_options | sort -s -k 1,1 |") or die;
        while (my $line = <TRACE>)
        {
            ::userDisplay $line;
        }
    }
    else
    {
        ::userDisplay("No matching buffers found.\n");
    }
}

sub readPage
{
    my ($addr, $offset, $pageArray) = @_;
    return if (0 == $addr);

    my $buffer = ::readData($addr, 4096);

    my $pointer = readBuf64($buffer, $offset);

    push @{$pageArray}, $buffer;

    readPage($pointer, $offset, $pageArray);
}

sub readBuf64
{
    my ($buffer, $offset) = @_;

    my $data = substr $buffer, $offset, 8;
    if (::littleendian()) { $data = reverse($data); }

    return unpack("Q", $data);
}

sub readBuf32
{
    my ($buffer, $offset) = @_;

    my $data = substr $buffer, $offset, 4;
    if (::littleendian()) { $data = reverse($data); }

    return unpack("L", $data);

}

sub readBuf16
{
    my ($buffer, $offset) = @_;

    my $data = substr $buffer, $offset, 2;
    if (::littleendian()) { $data = reverse($data); }

    return unpack("S", $data);

}

sub round8
{
    my ($val) = @_;

    if ($val % 8)
    {
        $val += (8 - ($val % 8));
    }

    return $val;
}

sub extractABAptr
{
    my ($val) = @_;

    $val = ($val & 0xFFFFFFFF);

    return $val;
}


sub lookupComponent
{
    my ($ptr, $hash) = @_;

    if (not defined $hash->{$ptr})
    {
        $hash->{$ptr} = ::readStr($ptr);
    }
    return $hash->{$ptr};
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
