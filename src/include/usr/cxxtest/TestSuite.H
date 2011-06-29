/** @file   TestSuite.H
 *
 *  Imported from FSP tree - /src/test/cxxtest/cxxtest/
 */


#ifndef __cxxtest__TestSuite_h__
#define __cxxtest__TestSuite_h__

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>

#include    <trace/interface.H>

extern  trace_desc_t   *g_trac_test;

namespace CxxTest
{

extern  uint64_t        g_TotalTests;
extern  uint64_t        g_TraceCalls;
extern  uint64_t        g_Warnings;
extern  uint64_t        g_FailedTests;

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

void doTrace( void );
void doWarn( const char *file, unsigned line, const char *message );
void doFailTest( const char *file, unsigned line, const char *message );
void doFailAssert( const char *file, unsigned line, const char *expression, const char *message );


void        reportTotalTests( const char *suitename, uint64_t numtests );

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
#define  TS_TRACE(...)   TRACDCOMP( g_trac_test, __VA_ARGS__); CxxTest::doTrace()


// TS_WARN
#define _TS_WARN(f,l,e) CxxTest::doWarn( (f), (l), e )
#define TS_WARN(e) _TS_WARN( __FILE__, __LINE__, e )

// TS_FAIL
#define _TS_FAIL(f,l,e) CxxTest::doFailTest( (f), (l), e )
#define TS_FAIL(e) _TS_FAIL( __FILE__, __LINE__, e )

}

#endif // __cxxtest__TestSuite_h__
