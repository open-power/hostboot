#!/usr/bin/perl
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/PldmFr.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2021
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
package Hostboot::PldmFr;
use File::Temp;
use Class::Struct;
use Data::Dumper;
use Exporter;
our @EXPORT_OK = ('main');

struct( pldm_flight_symbols => {
    fr_debug_sym => '$',
    fr_class_sym => '$',
    next_debug_sym => '$',
    next_class_sym => '$',
    flight_name => '$',
});

sub main
{

my $max_flights= ::read64
    ::findPointer("PLDMFRMX",
                  "PldmFR::iv_frMax");

my @pldm_flight_records;
{
    push @pldm_flight_records, pldm_flight_symbols->new(fr_debug_sym => "PLDMIREQ",
                                                        fr_class_sym =>"PldmFR::iv_inReq_fr",
                                                        next_debug_sym => "PLDMIRQN",
                                                        next_class_sym => "PldmFR::iv_inReq_fr_index",
                                                        flight_name => "Incoming PLDM Requests");
    push @pldm_flight_records, pldm_flight_symbols->new(fr_debug_sym => "PLDMORSP",
                                                        fr_class_sym =>"PldmFR::iv_outRsp_fr",
                                                        next_debug_sym => "PLDMORPN",
                                                        next_class_sym => "PldmFR::iv_outRsp_fr_index",
                                                        flight_name => "Outgoing PLDM Responses");
    push @pldm_flight_records, pldm_flight_symbols->new(fr_debug_sym => "PLDMOREQ",
                                                        fr_class_sym =>"PldmFR::iv_outReq_fr",
                                                        next_debug_sym => "PLDMORQN",
                                                        next_class_sym => "PldmFR::iv_outReq_fr_index",
                                                        flight_name => "Outgoing PLDM Requests");
    push @pldm_flight_records, pldm_flight_symbols->new(fr_debug_sym => "PLDMIRSP",
                                                        fr_class_sym =>"PldmFR::iv_inRsp_fr",
                                                        next_debug_sym => "PLDMIRPN",
                                                        next_class_sym => "PldmFR::iv_inRsp_fr_index",
                                                        flight_name => "Incoming PLDM Responses");
}


foreach my $fr_info(@pldm_flight_records) {
    bless $fr_info, 'pldm_flight_symbols';
    my $fr_data_start;
    my $fr_data_len;
    ($fr_data_start, $fr_data_len) =
        ::findPointer($fr_info->fr_debug_sym,
                      $fr_info->fr_class_sym);
    my $fr_entry_sz = $fr_data_len/$max_flights;
    my @requests;
    my @request;
    my @a = (0..$fr_data_len-1);
    for my $b(@a)
    {
        push(@request, ::read8($fr_data_start + $b));
        if((($b+1)%$fr_entry_sz) == 0)
        {
            push @requests,  [ @request ];
            @request = ();
        }
    }

    my @c = (0..$max_flights-1);
    my @entries = ();
    for my $d(@c)
    {
        my $request_bit = (($requests[$d][0] & 0x80) eq 0x80) ? '1' : '0';
        my $datagram_bit = (($requests[$d][0] & 0x40) eq 0x40) ? '1' : '0';
        my $seq_id = $requests[$d][0] & 0x1F;
        my $hdr_ver = $requests[$d][1] & 0xC0;
        my $cmd_type = $requests[$d][1] & 0x3F;
        my $cmd_code = $requests[$d][2];

        if($fr_entry_sz == 3)
        {
            my $entry_string = sprintf("raw=0x%0.2X%0.2X%0.2X ",$requests[$d][0], $requests[$d][1], $requests[$d][2]);
            $entry_string = $entry_string.(sprintf("rq=%d d=%d seq_id=%.2d hdr_ver=%.2d cmd_type=0x%0.2X cmd_code=0x%0.2X",
                                          $request_bit, $datagram_bit, $seq_id, $hdr_ver, $cmd_type, $cmd_code));
            push @entries, $entry_string;
        }
        else
        {
            # Repsonses have an extra byte which includes the completion code
            my $cmp_code = $requests[$d][3];
            my $entry_string = sprintf("raw=0x%0.2X%0.2X%0.2X%0.2X ",
                                  $requests[$d][0], $requests[$d][1], $requests[$d][2], $requests[$d][3]);
            $entry_string = $entry_string.(sprintf("rq=%d d=%d seq_id=%.2d hdr_ver=%.2d cmd_type=0x%0.2X cmd_code=0x%0.2X cmp_code=0x%0.2X",
                                          $request_bit, $datagram_bit, $seq_id, $hdr_ver, $cmd_type, $cmd_code, $cmp_code));
            push @entries, $entry_string;
        }

    }

    my $next_index  = ::read64
        ::findPointer($fr_info->next_debug_sym,
                      $fr_info->next_class_sym);
    ::userDisplay "\n".($fr_info->flight_name).", next index=$next_index (buffer wraps):\n";

    my $i = 0;
    for my $entry(@entries)
    {
        my $last_entry="";
        if($i == ($next_index-1))
        {
            $last_entry = "<--------- Last Entry";
        }
        ::userDisplay sprintf("Index %0.3d: %s %s\n", $i, $entry, $last_entry);
        $i = $i+1;
    }

}

};

1;
