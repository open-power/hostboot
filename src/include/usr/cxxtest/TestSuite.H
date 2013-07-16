/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/cxxtest/TestSuite.H $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/** @file   TestSuite.H
 *
 *  Imported from FSP tree - /src/test/cxxtest/cxxtest/
 */


#ifndef __cxxtest__TestSuite_h__
#define __cxxtest__TestSuite_h__

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <sys/sync.h>

extern  trace_desc_t   *g_trac_test;

namespace CxxTest
{

/**
 * @note extern declarations - see lib/cxxtest_data.C
 *
 * @see g_TotalTests, g_TraceCalls, g_Warnings, g_FailedTests
 */
extern  uint64_t        g_TotalTests;
extern  uint64_t        g_TraceCalls;
extern  uint64_t        g_Warnings;
extern  uint64_t        g_FailedTests;
extern  barrier_t       g_CxxTestBarrier;

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
public:
    virtual ~TestSuite();
    virtual void setUp();
    virtual void tearDown();
};

class AbortTest {};

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
#define  TS_TRACE(...)  TRACDCOMP( g_trac_test, "TS_TRACE> "__VA_ARGS__ );     \
    CxxTest::doTrace( )


// TS_WARN
#define TS_WARN(...)    TRACFCOMP( g_trac_test, "!TS_WARN> " __VA_ARGS__ );    \
    CxxTest::doWarn( )


// TS_FAIL
#define TS_FAIL(...)    TRACFCOMP( g_trac_test, "!!!TS_FAIL> " __VA_ARGS__);   \
    CxxTest::doFailTest( __FILE__, __LINE__ )

// These are all implemented in the cxxtest_data.C that gets put into the base
// image.
extern uint64_t g_TotalTests;
extern uint64_t g_TraceCalls;
extern uint64_t g_Warnings;
extern uint64_t g_FailedTests;
extern uint64_t g_ModulesStarted;
extern uint64_t g_ModulesCompleted;

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

}

#endif // __cxxtest__TestSuite_h__
