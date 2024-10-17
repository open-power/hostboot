# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/SimpleTraceCommon.pm $
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

# common functions to display a kernel SimpleTrace

use strict;
use Switch;

package Hostboot::SimpleTraceCommon;
use Exporter;

our @EXPORT = ( 'st_dump_bytes_32',
                'st_display_string',
                'st_display_tid',
                'st_print_trace',
              );

################################################################################
# read and dump bytes from the addr passed in, for debug
sub st_dump_bytes_32
{
    my $addr = shift @_;
    my $num  = shift @_;
    my $d;
    my $str;
    ::userDisplay "------------------\n";
    for (my $i=0; $i<$num; $i++)
    {
        $d = ::read32 ($addr);
        $str = sprintf("%08x %08x\n", $addr, $d);
        ::userDisplay "$str";
        $addr += 4;
    }
}

################################################################################
# read and dump bytes from the addr passed in, for debug
sub st_dump_bytes_64
{
    my $addr = shift @_;
    my $num  = shift @_;
    my $d;
    my $str;
    ::userDisplay "------------------\n";
    for (my $i=0; $i<$num; $i++)
    {
        $d = ::read64 ($addr);
        $str = sprintf("%08x %016x\n", $addr, $d);
        ::userDisplay "$str";
        $addr += 8;
    }
}

################################################################################
# print the string, if one was passed in
sub st_display_string
{
    my ($str) = (@_);
    $str or return;
    ::userDisplay "$str\n";
}

################################################################################
# print the istep/substep, if passed in
sub st_display_istep
{
    my ($istep, $substep) = (@_);
    my $str1;
    my $str2;
    $str1 = sprintf(" IStep:%3d", $istep);
    $str2 = sprintf("%d", $substep);
    $str2 = sprintf("%-2s", $str2);
    ::userDisplay "$str1.$str2";
}

################################################################################
# print the tid, if one was passed in
sub st_display_tid
{
    my $tid = shift;
    my $str1 = sprintf(" TID:   %d", $tid);
    my $str2 = sprintf("%-8s", $str1);
    ::userDisplay "$str2";
}

################################################################################
# print the tid in summary format
sub st_display_tid_summary
{
    my $tid = shift;
    my $str1 = sprintf("%5d|", $tid);
    ::userDisplay "$str1";
}

################################################################################
# print the cpuid in summary format
sub st_display_cpuid_summary
{
    my $cpuid = shift;
    my $str1 = sprintf("|%4d| ", $cpuid);
    ::userDisplay "$str1";
}

################################################################################
# print the time in seconds.milliseconds for a trace
sub st_display_time
{
    my $sec  = shift;
    my $nsec = shift;
    my $str1 = sprintf("%08d.", $sec);
    my $nano = sprintf("%d",    $nsec);
    my $str2 = sprintf("%-9s",  $nano);
    ::userDisplay "$str1$str2|";
}

################################################################################
# print a msg for the data, if passed in
sub st_display_req_pages
{
    my $pages = shift || 0;
    $pages or return;
    my $str = sprintf(" Pages:%3d", $pages);
    ::userDisplay "$str";
}

################################################################################
# print a msg telling the pages summary
sub st_display_pages_summary
{
    my $data = shift;
    my $str = sprintf(" Small:[%5d:%5d:%3d]", $data->{cv_pagesAvail_heap},
                                              $data->{cv_low_page_count_heap},
                                              $data->{cv_pagesAvail_res});
    my $str2 = sprintf("%-22s",  $str);
    ::userDisplay "$str2";
}

################################################################################
# print a msg telling the Big/Huge summary
sub st_display_BigHuge_summary
{
    my $data = shift;
    my $str = sprintf(" Big:%4d Huge:%4d", $data->{cv_largeheap_page_count},
                                           $data->{cv_hugeblock_page_count});
    ::userDisplay "$str";
}

################################################################################
# read all the trace entries from the addr passed in
# print each trace entry using functions passed in
sub st_print_trace
{
    my $args             = shift @_; # input parms which may determine how to display
    my $addr             = shift @_; # addr of the SimpleTrace
    my $fcn_get_data     = shift @_; # fcn ptr to get data and put into a hash
    my $fcn_display_data = shift @_; # fcn ptr to display data from a hash
    my %data;

    # read SimpleTrace iv_header contents
    my $eyecatcher = ::read32 ($addr); $addr+=4;
    my $version    = ::read16 ($addr); $addr+=2;
    my $format     = ::read16 ($addr); $addr+=2;
    my $level      = ::read32 ($addr); $addr+=4;
    my $e_size     = ::read32 ($addr); $addr+=4;
    my $size       = ::read32 ($addr); $addr+=4;
    my $max        = ::read32 ($addr); $addr+=4;
    my $hdr_idx = ::read64 ($addr); $addr+=8;

    my $base_addr = $addr;

    if ($eyecatcher != 0xABCDDCBA)
    {
        my $str = sprintf("Invalid eyecatcher in iv_header: 0x%x", $eyecatcher);
        ::userDisplay "$str\n";
        return;
    }

    # loop through the elements in the kmem trace and print
    for (my $i=0; $i<$max; $i++)
    {
        %data = ();
        defined $args->{"summary"} or  $data{trace}=1;
        defined $args->{"summary"} and $data{summary}=1;
        # start at the current hdr_idx and move on from there using i
        my $idx  = ($hdr_idx + $i) % $max;
        $addr    = $base_addr + ($idx * $e_size);
        $fcn_get_data->(\%data, $idx, $addr) and $fcn_display_data->(\%data);
    }
}
