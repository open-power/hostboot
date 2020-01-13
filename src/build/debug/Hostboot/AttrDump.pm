# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/AttrDump.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2020
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
    push( @dumpparms, $huid );

    # dumpHBAttrs can take a really long time, so we give the simulation plenty
    # of cycles to run it before we bail out.
    use constant MAX_CYCLES_TO_EXECUTE => 100000000000;

    Hostboot::CallFunc::execFunc( "TARGETING::UTIL::dumpHBAttrs(unsigned int)",
                                  $debug,
                                  $force,
                                  \@dumpparms,
                                  MAX_CYCLES_TO_EXECUTE );

    return 0;
}

sub helpInfo
{
    my %info = (
        name => "AttrDump",
        intro => ["Dumps all Attributes to trace."],
        options => {
                    "huid" =>  ["HUID of target to dump (default is to dump all targets)."],
                    "force" => ["Run command even if state does not appear correct."],
                    "debug" => ["More debug output."],
                   },
    );
}
