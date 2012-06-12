#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/debug/Hostboot/CxxTest.pm $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011-2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END_TAG
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
