# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/GcovModuleUnload.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019
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
#!/usr/bin/perl
use strict;
use File::Path;
use File::Basename;

package Hostboot::GcovModuleUnload;
use Hostboot::Gcov qw(parseGcovInfo init);

use Exporter;
our @EXPORT_OK = ('main', 'parseGcovInfo');

sub main
{
    my ($packName, $args) = @_;

    my $gcov_info_address = $args->{"address"};

    ::userDisplay("Dumping gcov module info from " . (sprintf "0x%x", $gcov_info_address) . "\n");

    if ($gcov_info_address <= 0) {
        ::userDisplay("Can't dump from NULL\n");
        return -1;
    }

    if (!Hostboot::Gcov::init()) {
        return -2;
    }

    Hostboot::Gcov::parseGcovInfo($gcov_info_address);

    ::userDisplay("Done.\n");

    return 0;
}

# Debug tool help info.
sub helpInfo
{
    my %info = (
        name => "GcovModuleUnload",
        intro => [ "Extracts the GCOV information from modules as they are being unloaded."],
    );
}

1; # Last expression in a perl module must be truthy.
