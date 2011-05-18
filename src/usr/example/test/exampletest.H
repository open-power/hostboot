#ifndef __TEST_EXAMPLETEST_H
#define __TEST_EXAMPLETEST_H

/**
 *  @file exampletest.H
 *
 *  @brief Example for people to use when writing test cases for their module.
 *  @todo  add more doxygen blocks
*/

#include <cxxtest/TestSuite.H>
#include <example/example.H>


class ExampleTest: public CxxTest::TestSuite
{
public:


    /**
     * @test TS_WARN will run if the example1_function FAILS
     *      */
    void testExampleWarn(void)
    {
        uint64_t    l_rc = 0;
        l_rc = example1_function();
        if(l_rc)
        {
                TS_WARN("Warning, Call to example1_function1 returned bad value.\n");
        }
    }


    /**
          * @test TS_TRACE will run if the example1_function FAILS
          *      */
    void testExampleTrace(void)
    {
        uint64_t    l_rc = 0;
        l_rc = example1_function();
        if(l_rc)
        {
                TS_TRACE("Tracing something in example1_function1\n");
        }
    }

    /**
          * @test TS_FAIL will run if the example1_function FAILS
     */
    void testExampleFail(void)
    {
        uint64_t    l_rc = 0;
        l_rc = example1_function();
        if(l_rc)
        {
                TS_FAIL("Call to example1_function1 failed!\n");
        }
    }
    /**
          * @test this will always run TS_FAIL
     */
    void testExampleForceFail(void)
    {

        TS_FAIL("Run TS_FAIL() as part of the example test.\n" );
    }

    /**
          * @test this will always run TS_WARN
     */
    void testExampleForceWarn(void)
    {

        TS_WARN("Run TS_WARN() as part of the example test\n" );
    }
    /**
          * @test this will always run TS_WARN
     */
    void testExampleForceTrace(void)
    {

        TS_TRACE("Run TS_TRACE() as part of the example test\n" );
    }



};

#endif

