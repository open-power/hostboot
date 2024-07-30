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
    my $d;
    my $str;
    for (my $i=0; $i<24; $i++)
    {
        $d = ::read32 ($addr);
        $str = sprintf("%08x %08x\n", $addr, $d);
        ::userDisplay "$str";
        $addr += 4;
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
    $istep or return;
    ::userDisplay "  IStep: $istep";
    $substep and ::userDisplay ".$substep";
}

################################################################################
# print the tid, if one was passed in
sub st_display_tid
{
    my $tid = shift || 0;
    $tid or return;
    ::userDisplay "  TID:   $tid";
}

################################################################################
# print a msg for the data, if passed in
sub st_display_req_pages
{
    my $pages = shift || 0;
    $pages or return;
    ::userDisplay "  Pages: $pages";
}

################################################################################
# read all the trace entries from the addr passed in
# print each trace entry using functions passed in
sub st_print_trace
{
    my $args             = shift @_; # input parms which may determin how to display
    my $addr             = shift @_; # addr of the SimpleTrace
    my $fcn_get_data     = shift @_; # fcn ptr to get data and put into a hash
    my $fcn_display_data = shift @_; # fcn ptr to display data from a hash
    my %data;

    # read hdr contents
    my $version = ::read16 ($addr); $addr+=2;
    my $format  = ::read16 ($addr); $addr+=2;
    my $level   = ::read32 ($addr); $addr+=4;
    my $e_size  = ::read32 ($addr); $addr+=4;
    my $size    = ::read32 ($addr); $addr+=4;
    my $max     = ::read32 ($addr); $addr+=4;
    $addr += 4;  # pad
    my $hdr_idx = ::read64 ($addr); $addr+=8;

    my $base_addr = $addr;

    # loop through the elements in the kmem trace and print
    for (my $i=0; $i<$max; $i++)
    {
        %data = ();
        defined $args->{"summary"} and $data{summary}=1;
        # start at the current hdr_idx and move on from there using i
        my $idx  = ($hdr_idx + $i) % $max;
        $addr    = $base_addr + ($idx * $e_size);
        $fcn_get_data->(\%data, $idx, $addr) and $fcn_display_data->(\%data);
    }
}
