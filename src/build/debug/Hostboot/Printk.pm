#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Printk.pm $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2011,2014
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

package Hostboot::Printk;
use Exporter;
our @EXPORT_OK = ('main');

sub main
{
    my ($symAddr, $symSize) = ::findSymbolAddress("kernel_printk_buffer");
    if (not defined $symAddr) { ::userDisplay "Cannot find symbol.\n"; die; }
    my $data = ::readData($symAddr,$symSize);
    $data =~ s/\0+//g; #strip off nulls
    ::userDisplay "------------Kernel Printk Parser------------\n";
    ::userDisplay $data;
    ::userDisplay "\n--------------------------------------------\n";
}

sub helpInfo
{
    my %info = (
        name => "Printk",
        intro => ["Displays the printk buffer."],
    );
}
