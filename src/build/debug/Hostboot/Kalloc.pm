# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Kalloc.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2024
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

# Functions to print the Kernel Memory Allocation Trace
#  The data is held in the global array: g_kalloc_trace

use strict;
use Switch;

package Hostboot::Kalloc;
use Exporter;
use Hostboot::SimpleTraceCommon;
our @EXPORT_OK = ('main');

################################################################################
# print a msg for the tag passed in
sub display_tag
{
    my $tag = shift || 0;
    switch ($tag)
    {
        case 0x1001 {::userDisplay "K_ALLOC_PAGES_FAIL";}
    }
}

################################################################################
# print the data from the hash passed in
sub display_trace_data
{
    my %data = %{$_[0]};
    my $str;

    $data{summary} or ::userDisplay "=========================================================\n";
    display_tag($data{tag});
    $data{summary} or ::userDisplay "\n";
    Hostboot::SimpleTraceCommon::st_display_tid($data{tid});

    $data{summary} and return;

    $str = sprintf("  %6d which_bucket\n", $data{which_bucket});
    ::userDisplay "$str";
    $str = sprintf("  %6d bucket_size\n", $data{bucket_size});
    ::userDisplay "$str";
    $str = sprintf("  %6d page_count\n", $data{page_count});
    ::userDisplay "$str";
    $str = sprintf("  %6d stats_count\n", $data{stats_count});
    ::userDisplay "$str";
    $str = sprintf("  %6d coalesce_state\n", $data{coalesce_state});
    ::userDisplay "$str";
    $str = sprintf("  %08x  <= first\n", $data{first});
    ::userDisplay "$str";
}

################################################################################
# read the data for a trace entry
sub get_trace_data
{
    my ($data, $idx, $addr) = (@_);
    my $str;
    my $EMPTY_TAG = 0xDEAD;

    $data->{tag} = ::read16 ($addr); $addr+=2;
    if ($data->{tag} == $EMPTY_TAG)
    {
        return 0;
    }

    $data->{which_bucket}   = ::read32 ($addr); $addr+=4;
    $data->{bucket_size}    = ::read32 ($addr); $addr+=4;
    $data->{page_count}     = ::read32 ($addr); $addr+=4;
    $data->{stats_count}    = ::read32 ($addr); $addr+=4;
    $data->{coalesce_state} = ::read32 ($addr); $addr+=4;
    $data->{first}          = ::read64 ($addr); $addr+=8;
    $data->{tid}            = ::read16 ($addr);

    return 1;
}

################################################################################
sub main
{
    my ($packName, $args) = @_;

    my %data = ();
    my ($addr, $symSize) = ::findPointer("KALLTRC",
                                         "g_kalloc_trace");
    if (not defined $addr)
    {
        ::userDisplay "Couldn't find PageManager::g_kalloc_trace";
        return;
    }

    my $hdr = ::read64 ($addr);
    $data{hdr_addr} = $hdr;

    # call a common fcn to read and print the SimpleTrace entries
    Hostboot::SimpleTraceCommon::st_print_trace($args,
                                                $hdr,
                                                \&get_trace_data,
                                                \&display_trace_data);
}

################################################################################
sub helpInfo
{
    my %info = (
        name => "Kalloc",
        intro => ["Displays Hostboot kernel alloc trace usage information."],
    );
}
