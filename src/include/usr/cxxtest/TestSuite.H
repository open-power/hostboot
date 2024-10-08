/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/cxxtest/TestSuite.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2024                        */
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

/** @file   TestSuite.H
 *
 *  Imported from FSP tree - /src/test/cxxtest/cxxtest/
 */
#ifndef __CXXTEST_TESTSUITE_H
#define __CXXTEST_TESTSUITE_H

#include <arch/magic.H>
#include <limits.h>

// Set by code that wants to manually execute a testcase outside of the
// normal CxxTest framework
#ifdef MANUAL_CXXTEST

trace_desc_t *g_trac_test = NULL;
TRAC_INIT(&g_trac_test, "UNIT_TEST", 4*KILOBYTE);

namespace CxxTest {

// Empty class to satisfy the compiler
class TestSuite
{
public:
  virtual ~TestSuite() {}
};

#define  TS_TRACE(...) { TRACFCOMP( g_trac_test, "TS_TRACE> " __VA_ARGS__ ); }
#define  TS_INFO(...)  { TRACFCOMP( g_trac_test, "TS_INFO> " __VA_ARGS__ ); }
#define  TS_WARN(...)  { TRACFCOMP( g_trac_test, "!TS_WARN> " __VA_ARGS__ ); }
#define  TS_FAIL(...)  { TRACFCOMP( g_trac_test, "!!!TS_FAIL> " __VA_ARGS__); }

}; //namespace CxxTest

using namespace CxxTest;

#define AUTO_CXXTEST //short-circuit the rest

#endif // MANUAL_CXXTEST


#ifndef AUTO_CXXTEST
#define AUTO_CXXTEST

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <sys/sync.h>
#include    <usr/cxxtest/cxxtest_data.H>
#include    <vector>

extern  trace_desc_t   *g_trac_test;

namespace CxxTest
{
enum ci_run_level_t
{
  CI_RUN_LEVEL_MIN = 1,  // HB_CI_RUN_LEVEL=MIN      - run only MIN
  CI_RUN_LEVEL_MED,      // HB_CI_RUN_LEVEL=MED      - run levels MIN, MED
  CI_RUN_LEVEL_MAX,      // HB_CI_RUN_LEVEL=MAX      - run levels MIN, MED, MAX
};

/**
 * @note extern declarations - see lib/cxxtest_data.C
 *
 * @see g_TotalTests, g_TraceCalls, g_Warnings, g_FailedTests, g_FailedTestList
 */
extern  uint64_t        g_TotalTests;
extern  uint64_t        g_TraceCalls;
extern  uint64_t        g_Warnings;
extern  uint64_t        g_FailedTests;
extern  barrier_t       g_CxxTestBarrier;
extern  CxxTestFailedEntry g_FailedTestList[CXXTEST_FAIL_LIST_SIZE];

/**
 * @class   TestSuite
 *
 *  class TestSuite is the base class for all test suites.
 *  To define a test suite, derive from this class and add
 *  member functions called void test*();
 *
 */
class TestSuite
{
    ci_run_level_t iv_run_level;

public:
    TestSuite();
    virtual ~TestSuite();
    virtual void setUp();
    virtual void tearDown();

    bool isRunLevelMed(void)   {return(CI_RUN_LEVEL_MED   == iv_run_level ||
                                       CI_RUN_LEVEL_MAX   == iv_run_level);}
    bool isRunLevelMax(void)   {return(CI_RUN_LEVEL_MAX   == iv_run_level);}
};

class AbortTest {};

void sortTests(std::vector<const char *> & i_list,
               std::vector<const char *> & o_serial_list,
               std::vector<const char *> & o_parallel_list);
void doTrace( );
void doWarn( );
void doFailTest( );
void doFailTest( const char *filename, uint32_t linenum );
void doFailAssert(  const char *file,
                    unsigned line,
                    const char *expression,
                    const char *message );


void reportTotalTests(  const char *suitename,
                        uint64_t numtests );

extern uint64_t g_ModulesStarted;
extern uint64_t g_ModulesCompleted;

#define _TS_TRY
#define ___TSM_CATCH(f,l,m)
#define __TSM_CATCH(f,l,m)
#define __TS_CATCH(f,l)
#define _TS_CATCH
#define _TS_CATCH_TYPE(t, b)
#define _TS_LAST_CATCH(b)
#define _TS_CATCH_ABORT(b)

// TS_TRACE
#define  TS_TRACE(...) { TRACDCOMP( g_trac_test, "TS_TRACE> " __VA_ARGS__ );     \
    CxxTest::doTrace( ); }


// TS_INFO
#define  TS_INFO(...) { TRACFCOMP( g_trac_test, "TS_INFO> " __VA_ARGS__ );     \
    CxxTest::doTrace( ); }


// TS_WARN
#define TS_WARN(...)   { TRACFCOMP( g_trac_test, "!TS_WARN> " __VA_ARGS__ );    \
    CxxTest::doWarn( ); }


// TS_FAIL
#define TS_FAIL(...)   { TRACFCOMP( g_trac_test, "!!!TS_FAIL> " __VA_ARGS__);   \
    CxxTest::doFailTest( __FILE__, __LINE__ ); }

// Statistics structure for passing original pointers to the runtime test suite.
struct CxxTestStats
{
    uint64_t* totalTests;
    uint64_t* traceCalls;
    uint64_t* warnings;
    uint64_t* failedTests;
    uint64_t* modulesStarted;
    uint64_t* modulesCompleted;
};

} // namespace CxxTest

#endif // AUTO_CXXTEST

#define TS_FAIL_FN(...)                         \
    TS_FAIL(TEST_FUNC ": " __VA_ARGS__)

#define TS_ASSERT(COND, ...)                    \
    if (!(COND)) {                              \
        TS_FAIL_FN(__VA_ARGS__);                \
    }                                           \

#define TS_ASSERT_RETURN(COND, ...)             \
    if (!(COND)) {                              \
        TS_FAIL_FN(__VA_ARGS__);                \
        return;                                 \
    }                                           \

#endif // __CXXTEST_TESTSUITE_H
