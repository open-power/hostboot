# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/debug/Hostboot/CxxTest.pm $
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

package Hostboot::CxxTest;
use Exporter;
our @EXPORT_OK = ('main');

sub main
{
    my $modules_started =
        ::read64 ::findSymbolAddress("CxxTest::g_ModulesStarted");
    my $modules_complete =
        ::read64 ::findSymbolAddress("CxxTest::g_ModulesCompleted");

    my $total_tests =
        ::read64 ::findSymbolAddress("CxxTest::g_TotalTests");
    my $failed_tests =
        ::read64 ::findSymbolAddress("CxxTest::g_FailedTests");
    my $test_warnings =
        ::read64 ::findSymbolAddress("CxxTest::g_Warnings");
    my $test_traces =
        ::read64 ::findSymbolAddress("CxxTest::g_TraceCalls");

    ::userDisplay "===================================================\n";
    ::userDisplay "    Modules started:   $modules_started\n";
    ::userDisplay "    Modules completed: $modules_complete\n";
    ::userDisplay "\n";
    ::userDisplay "    Total tests:       $total_tests\n";
    ::userDisplay "    Failed tests:      $failed_tests\n";
    ::userDisplay "    Warnings:          $test_warnings\n";
    ::userDisplay "    Trace calls:       $test_traces\n";
    ::userDisplay "===================================================\n";

}

sub helpInfo
{
    my %info = (
        name => "CxxTest",
        intro => ["Displays the number of CxxTest cases executed and their results,",
                 "warnings, etc."],
    );
}
