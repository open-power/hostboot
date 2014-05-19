#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Example.pm $
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

package Hostboot::Example;
use Exporter;
our @EXPORT_OK = ('main');

sub main
{
    ::userDisplay "Welcome to the example module.\n";
    ::userDisplay "Calling 'usage', which will exit...\n";
    ::usage();
    ::userDisplay "Should never get here.\n";

    return 0;
}

sub helpInfo
{
    my %info = (
        name => "Example",
        intro => ["Doesn't really do anything special."],
    );
}
