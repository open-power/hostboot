/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/cxxtest_data.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#include <stdint.h>
/**
 * @brief global vars to keep track of unit tests,
 *
 * @see TestSuite.H and TestSuite.C
 *
 *  These are now also being used in the main code to record failed modules.
 *
 * @var g_TotalTests    -   initialized to 0, updated by reportTotalTests().
 *      Each test suite will call reporttotaltests after all tests have
 *      run with the total number of tests for that suite.
 *      Once all the testsuites have run, the global totaltests will hold
 *      the total of number of unit tests for that run.
 *
 *      Each unit test macro (TS_TRACE, TS_WARN, and TS_FAIL) will update
 *      the proper variable.  At the end the unit tester will print out
 *      the totals.
 *
 * @var g_TraceCalls    -   updated by TS_TRACE macro
 *
 * @var g_Warnings      -   updated by TS_WARN macro
 *
 * @var g_FailedTests   -   updated by TS_FAIL macro in the unit test image.
 *  This variable is also used to allow a code in a binary image
 *  not containing the testcase modules to query the number of failed tests
 *
 */

namespace CxxTest
{

uint64_t        g_TotalTests      =     0;
uint64_t        g_TraceCalls      =     0;
uint64_t        g_Warnings        =     0;
uint64_t        g_FailedTests     =     0;
uint64_t        g_ModulesStarted  =     0;
uint64_t        g_ModulesCompleted=     0;

}

