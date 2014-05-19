# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/AttrDump.pm $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2012,2014
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

package Hostboot::AttrDump;
use Exporter;
our @EXPORT_OK = ('main');
require Hostboot::CallFunc;

sub main
{
    my ($packName,$args) = @_;

    # Parse 'debug' option.
    my $debug = 0;
    if (defined $args->{"debug"})
    {
        $debug = 1;
    }

    # Parse 'force' argument.
    my $force = 0;
    if (defined $args->{"force"})
    {
        $force = 1;
    }

    # Parse 'trace' argument.
    my $trace = (::findSymbolAddress("TARGETING::g_trac_targeting"))[0];
    if (defined $args->{"trace"})
    {
        $trace = (::findSymbolAddress($args->{"trace"}))[0];
    }
    if( $debug )
    {
        my $tmp2 = $args->{"trace"};
        ::userDisplay("\ntrace: $trace ($tmp2)\n");
    }

    # Parse 'target' argument.
    my $huid = 0; # dump all targets
    if (defined $args->{"huid"})
    {
        $huid = hex($args->{"huid"});
    }
    if( $debug )
    {
        ::userDisplay("huid: $huid\n");
    }

    my @dumpparms;
    push( @dumpparms, $trace );
    push( @dumpparms, $huid );
    Hostboot::CallFunc::execFunc( "TARGETING::dumpAllAttributes2(trace_buf_head**, unsigned int)", $debug, $force, \@dumpparms );

    return 0;
}

sub helpInfo
{
    my %info = (
        name => "AttrDump",
        intro => ["Dumps all Attributes to trace."],
        options => {
                    "huid" =>  ["HUID of target to dump (default is to dump all targets)."],
                    "trace" => ["Trace buffer to use (default=g_trac_targ)."],
                    "force" => ["Run command even if state does not appear correct."],
                    "debug" => ["More debug output."],
                   },
    );
}
