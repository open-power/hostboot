/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/cxxtest/TestSuite.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

// Imported from FSP tree - /src/test/cxxtest/cxxtest/

#ifndef __cxxtest__TestSuite_cpp__
#define __cxxtest__TestSuite_cpp__

#include <limits.h>
#include <stdarg.h>
#include <arch/ppc.H>
#include <string.h>
#include <cxxtest/TestSuite.H>

trace_desc_t *g_trac_test = NULL;
TRAC_INIT(&g_trac_test, "UNIT_TEST", 4*KILOBYTE);

namespace CxxTest
{
/******************************************************************************/
// Globals/Constants
/******************************************************************************/
//This is a list of testcases that are expected to run in a serial manner
//   example: std::vector<const char *> CxxSerialTests{"libtestrtloader.so"};
//
//   libtesthwas, libtesteeprom, and libtestspiserial in serial bucket since
//   states may be altered which may adversely affect other tests
//
std::vector<const char *> CxxSerialTests{ "libtesthwas.so",
                                          "libtesteeprom.so",
                                          "libtestspiserial.so",
                                          "libtestfapi2serial.so",
                                          "libtestvpd.so",
                                          "libtestsbeio.so" };

//
// TestSuite members
//
TestSuite::~TestSuite() {}
void TestSuite::setUp() {}
void TestSuite::tearDown() {}

/**
 *
 *   @brief Implement trace action in unit tests
 *
 *   @return void
 *
 */
void doTrace( )
{

    __sync_add_and_fetch( &g_TraceCalls, 1 );

}

/**
 *
 *   @brief Implement warn action in unit tests
 *
 *   @param [in] pointer to filename  (not used right now )
 *   @param [in] line number
 *   @param [in] warning message
 *
 *   @return void
 *
 */
void doWarn( )
{

    __sync_add_and_fetch( &g_Warnings, 1 );

}

/**
 *   @brief Implement Fail action in unit tests
 *
 *   @return none
 */

void doFailTest( )
{

    TRACDCOMP( g_trac_test,
            "!!!       > Test Failed " );
    if(g_FailedTests < CXXTEST_FAIL_LIST_SIZE)
    {
        memcpy(g_FailedTestList[g_FailedTests].failTestFile,
               "---",
               3);
    }
    __sync_add_and_fetch( &g_FailedTests, 1 );

}

void sortTests(std::vector<const char *> & i_list,
               std::vector<const char *> & o_serial_list,
               std::vector<const char *> & o_parallel_list)
{
    o_serial_list.clear();
    o_serial_list.reserve(32);
    o_parallel_list.clear();
    o_parallel_list.reserve(32);

    //Loop through list of all tests
    for(std::vector<const char *>::const_iterator i = i_list.begin();
        i != i_list.end(); ++i)
    {
        bool is_serial = false;

        for(std::vector<const char *>::const_iterator j = CxxSerialTests.begin();
            j !=  CxxSerialTests.end(); ++j)
        {
            if (0 == strcmp(*i, *j))
            {
                is_serial = true;
            }
        }

        if (is_serial)
        {
            TRACFCOMP( g_trac_test, "%s is a serial test",*i);
            o_serial_list.push_back(*i);
        }
        else
        {
            TRACFCOMP( g_trac_test, "%s is a parallel test",*i);
            o_parallel_list.push_back(*i);
        }
    }
}

/**
 *   @brief Implement Fail action in unit tests
 *
 *   @param [in] pointer to filename  (not used right now )
 *   @param [in] line number
 *
 *   @return none
 */

void doFailTest( const char *filename, uint32_t linenum )
{
    TRACFCOMP( g_trac_test,
            "!!!       > Test %s Failed at line %d ",
            filename,
            linenum );

    if(g_FailedTests < CXXTEST_FAIL_LIST_SIZE)
    {
        memcpy(g_FailedTestList[g_FailedTests].failTestFile,
               filename,
               CXXTEST_FILENAME_SIZE);
        g_FailedTestList[g_FailedTests].failTestData = linenum;
    }
    __sync_add_and_fetch( &g_FailedTests, 1 );

}
/**
 *  @brief Report total number of unit tests in a test suite
 *
 *  A unit test suite will call this to report how many tests
 *  it has.  The call itself is autogenerated
 *
 *  @param [in] pointer to filename  (not used right now )
 *  @param [in] line number
 *  @param [in] trace message
 *
 *  @return void
 *
 *  @TODO do nothing with the suite name for now, later it may be useful
 *
 */
void reportTotalTests(  const char *suitename,
                        uint64_t numtests )
{

    __sync_add_and_fetch( &g_TotalTests, numtests );
    TRACDCOMP( g_trac_test,
            "Suite %s Completed ",
            suitename  );
    return;
}


};

#endif // __cxxtest__TestSuite_cpp__
