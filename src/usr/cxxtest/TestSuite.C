// Imported from FSP tree - /src/test/cxxtest/cxxtest/

#ifndef __cxxtest__TestSuite_cpp__
#define __cxxtest__TestSuite_cpp__

#include <cxxtest/TestSuite.H>
#include <stdarg.h>
#include <arch/ppc.H>

namespace CxxTest
{
    //
    // TestSuite members
    //
    TestSuite::~TestSuite() {}
    void TestSuite::setUp() {}
    void TestSuite::tearDown() {}

    //
    // Some non-template functions
    //
    void doTrace( const char *file, unsigned line, const char *message )
    {
        //tracker().trace( file, line, message );
        //printk("%s %u %s\n",file,line,message);
    }

    void doWarn( const char *file, unsigned line, const char *message )
    {
        //tracker().warning( file, line, message );
        //printk("%s %u %s\n",file,line,message);
    }

    void doFailTest( const char *file, unsigned line, const char *message )
    {
        //tracker().failedTest( file, line, message );
        //TS_ABORT();
    }

};

#endif // __cxxtest__TestSuite_cpp__
