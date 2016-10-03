#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/Hdatfmt.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2016
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
use File::Temp;

package Hostboot::Hdatfmt;
use Exporter;
our @EXPORT_OK = ('main');


sub main
{
    my ($packName,$args) = @_;

    # Parse 'addr and length' argument.
    if ((not defined $args->{"addr"}) || (not defined $args->{"len"}))
    {
        ::userDisplay "ERROR.. Did not pass in Address and Length.\n";
        die;
    }

    my $hex_address= 0x0;
    my $hex_length= 0x0;

    $hex_address = $args->{"addr"};
    $hex_length = hex($args->{"len"});
    ::userDisplay "Passed values $hex_address  $hex_length \n";

    my $hdatfmtBuffer;

    $hdatfmtBuffer = ::readData( $hex_address, $hex_length);

    # write buffer to a temporary file
    my $timeStamp = `date +%Y%m%d%H%M%S`;
    chomp $timeStamp;

    my $tempFile = "hdatfmt.$timeStamp";

    ::userDisplay "Dumping hdat data to output file $tempFile \n";

    open( HDATFMTDATA, "> $tempFile" )
        or die "Can not write temporary file $tempFile\n";
    binmode HDATFMTDATA;
    print HDATFMTDATA $hdatfmtBuffer;
    close( HDATFMTDATA );

    #TODO RTC 137833: Hdatfmt parser tool

    return 0;
}

sub helpInfo
{
    my %info = (
        name => "Hdatfmt",
        intro => ["Dump the hdat data to a file"],
        options => {
                    "addr=<ADDR>" => ["ADDR in number"],
                    "len=<LEN>" => ["LEN in hex number"],
        },
        notes => ["The address and len should be passed always to",
                  "dump the memory area"]
        );
}

