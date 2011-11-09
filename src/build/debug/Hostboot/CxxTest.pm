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

sub help
{
    ::userDisplay "Tool: CxxTest\n";
    ::userDisplay "\tDisplays the number of CxxTest cases executed and their\n";
    ::userDisplay "\tresults, warnings, etc.\n";
}
