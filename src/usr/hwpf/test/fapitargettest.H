#ifndef __FAPITARGETTEST_H
#define __FAPITARGETTEST_H

/**
 *  @file fapitargettest.H
 *
 *  @brief Test case for FAPI targets
*/

#include <cxxtest/TestSuite.H>
#include <fapi.H>
#include "fapiTargetTest.C"

using namespace fapi;

class FapiTargetTest: public CxxTest::TestSuite
{
public:

    /**
     * @brief Test target #1
     */
    void testTarget1()
    {
        uint32_t l_res = targetTest1();

        if (l_res != 0)
        {
            TS_FAIL("testTarget1. Fail");
        }
    }

    /**
     * @brief Test target #2
     */
    void testTarget2()
    {
        uint32_t l_res = targetTest2();

        if (l_res != 0)
        {
            TS_FAIL("testTarget2. Fail");
        }
    }

    /**
     * @brief Test target #3
     */
    void testTarget3()
    {
        uint32_t l_res = targetTest3();

        if (l_res != 0)
        {
            TS_FAIL("testTarget3. Fail");
        }
    }

    /**
     * @brief Test target #4
     */
    void testTarget4()
    {
        uint32_t l_res = targetTest4();

        if (l_res != 0)
        {
            TS_FAIL("testTarget4. Fail");
        }
    }

    /**
     * @brief Test target #5
     */
    void testTarget5()
    {
        uint32_t l_res = targetTest5();

        if (l_res != 0)
        {
            TS_FAIL("testTarget5. Fail");
        }
    }

    /**
     * @brief Test target #6
     */
    void testTarget6()
    {
        uint32_t l_res = targetTest6();

        if (l_res != 0)
        {
            TS_FAIL("testTarget6. Fail");
        }
    }
};

#endif
