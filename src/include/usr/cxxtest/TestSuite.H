// Imported from FSP tree - /src/test/cxxtest/cxxtest/

#ifndef __cxxtest__TestSuite_h__
#define __cxxtest__TestSuite_h__

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>

//
// class TestSuite is the base class for all test suites.
// To define a test suite, derive from this class and add
// member functions called void test*();
//

namespace CxxTest
{
    class TestSuite
    {
    public:
        virtual ~TestSuite();
        virtual void setUp();
        virtual void tearDown();
    };

    class AbortTest {};

    void doTrace( const char *file, unsigned line, const char *message );
    void doWarn( const char *file, unsigned line, const char *message );
    void doFailTest( const char *file, unsigned line, const char *message );
    void doFailAssert( const char *file, unsigned line, const char *expression, const char *message );


    void        reportTotalTests( const char *suitename, uint64_t numtests );

    // $$ these should be set up as readonly accessors
    uint64_t    getTotalTests(void);
    uint64_t    getFailedTests(void);
    uint64_t    getWarnings(void);
    uint64_t    getTraceCalls(void);

#       define _TS_TRY
#       define ___TSM_CATCH(f,l,m)
#       define __TSM_CATCH(f,l,m)
#       define __TS_CATCH(f,l)
#       define _TS_CATCH
#       define _TS_CATCH_TYPE(t, b)
#       define _TS_LAST_CATCH(b)
#       define _TS_CATCH_ABORT(b)

    // TS_TRACE
#   define _TS_TRACE(f,l,e) CxxTest::doTrace( (f), (l), e )
#   define TS_TRACE(e) _TS_TRACE( __FILE__, __LINE__, e )

    // TS_WARN
#   define _TS_WARN(f,l,e) CxxTest::doWarn( (f), (l), e )
#   define TS_WARN(e) _TS_WARN( __FILE__, __LINE__, e )

    // TS_FAIL
#   define _TS_FAIL(f,l,e) CxxTest::doFailTest( (f), (l), e )
#   define TS_FAIL(e) _TS_FAIL( __FILE__, __LINE__, e )

}

#endif // __cxxtest__TestSuite_h__
