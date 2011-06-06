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
     * @test TS_WARN will run if the testExampleWarn_function FAILS
     */
    void testExampleWarn(void)
    {
        uint64_t    l_rc = 0;
        l_rc = example1_function();
        if(l_rc)
        {
            TS_WARN("Warning, Call to testExampleWarn returned bad value.\n");
        }
    }


    /**
     * @test TS_TRACE will run if the testExampleTrace function FAILS
     *
     */
    void testExampleTrace(void)
    {
        uint64_t    l_rc = 0;
        l_rc = example1_function();
        if(l_rc)
        {
            TS_TRACE("Tracing a failure in testExampleTrace function1\n");
        }
    }

    /**
     * @test TS_FAIL will run if the testExampleFail function FAILS
     */
    void testExampleFail(void)
    {
        uint64_t    l_rc = 0;
        l_rc = example1_function();
        if(l_rc)
        {
            TS_FAIL("Call to testExampleFail failed!\n");
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
     * @test this will always run TS_TRACE
     */
    void testExampleForceTrace(void)
    {
        uint32_t i_32test   =   0xdeadbeef;
        uint64_t i_64test   =   0xbadc0ffee0ddf00d;

        TS_TRACE("Run TS_TRACE() as part of the example test\n" );

        TS_TRACE("Run TS_TRACE() with one print parameter: %d\n", 5 );

        TS_TRACE("Run TS_TRACE() with 2 parameters: 0x%x 0x%x \n", i_32test, 0x78 );

        TS_TRACE("Run TS_TRACE() with 3 parameters:  %d, 0x%llx, %p", 328, i_64test, &i_64test );
    }



};

#endif

