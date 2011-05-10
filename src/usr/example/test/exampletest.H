#include <cxxtest/TestSuite.H>
#include <example/example.H>

class ExampleTest: public CxxTest::TestSuite
{
public:
    void testExample1(void)
    {
        uint64_t    l_rc = 0;
        l_rc = example1_function();
        if(l_rc)
        {
            TS_FAIL("Call to example1_function1 failed!");
        }
    }
    void testExample2(void)
    {
        // Call functions and validate results
        // TS_FAIL("Failed test call to example2 function");
    }
    void testExample3(void)
    {
        // Call functions and validate results
        // TS_FAIL("Failed test call to example3 function");
    }

};

