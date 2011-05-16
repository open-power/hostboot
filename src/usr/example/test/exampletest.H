#ifndef __TEST_EXAMPLETEST_H
#define __TEST_EXAMPLETEST_H

/**
 *  @file exampletest.H
 *
 *  @brief Example for people to use when writing test cases for their module.
*/

#include <cxxtest/TestSuite.H>
#include <example/example.H>

class ExampleTest: public CxxTest::TestSuite
{
public:

    /**
     * @test Test Description
     */
    void testExample1(void)
    {
        uint64_t    l_rc = 0;
        l_rc = example1_function();
        if(l_rc)
        {
            TS_FAIL("Call to example1_function1 failed!");
        }
    }

    /**
     * @test Test Description
     */
    void testExample2(void)
    {
        // Call functions and validate results
        // TS_FAIL("Failed test call to example2 function");
    }

    /**
     * @test Test Description
     */
    void testExample3(void)
    {
        // Call functions and validate results
        // TS_FAIL("Failed test call to example3 function");
    }
    void testExample4(void)
    {
        // Call functions and validate results
        // TS_FAIL("Failed test call to example3 function");
    }
    void testExample5(void)
    {
        // Call functions and validate results
        // TS_FAIL("Failed test call to example3 function");
    }

};

#endif

