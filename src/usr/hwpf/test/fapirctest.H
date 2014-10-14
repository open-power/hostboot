/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/test/fapirctest.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
#ifndef __FAPItestRc_H
#define __FAPItestRc_H

/**
 *  @file fapitestRc.H
 *
 *  @brief Test case for FAPI return codes
*/

#include <cxxtest/TestSuite.H>
#include <fapi.H>
#include "fapiRcTest.C"

using namespace fapi;

class FapitestRc: public CxxTest::TestSuite
{
public:

    /**
     * @brief Test FAPI return codes #1
     */
    void testRc1(void)
    {
        uint32_t l_res = rcTest1();

        if (l_res != 0)
        {
            TS_FAIL("testRc1. Fail l_res=%d", l_res);
        }
    }


    /**
     * @brief Test FAPI return codes #2
     */
    void testRc2()
    {
        uint32_t l_res = rcTest2();

        if (l_res != 0)
        {
            TS_FAIL("testRc2. Fail l_res=%d", l_res);
        }
    }

    /**
     * @brief Test FAPI return codes #3
     */
    void testRc3()
    {
        uint32_t l_res = rcTest3();

        if (l_res != 0)
        {
            TS_FAIL("testRc3. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI return codes #4
     */
    void testRc4()
    {
        uint32_t l_res = rcTest4();

        if (l_res != 0)
        {
            TS_FAIL("testRc4. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI return codes #5
     */
    void testRc5()
    {
        uint32_t l_res = rcTest5();

        if (l_res != 0)
        {
            TS_FAIL("testRc5. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI return codes #6
     */
    void testRc6()
    {
        uint32_t l_res = rcTest6();

        if (l_res != 0)
        {
            TS_FAIL("testRc6. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI return codes #7
     */
    void testRc7()
    {
        uint32_t l_res = rcTest7();

        if (l_res != 0)
        {
            TS_FAIL("testRc7. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI return codes #8
     */
    void testRc8()
    {
        uint32_t l_res = rcTest8();

        if (l_res != 0)
        {
            TS_FAIL("testRc8. Fail l_res=%d", l_res);
        }
    }

    /**
     * @brief Test FAPI return codes #9
     */
    void testRc9()
    {
        uint32_t l_res = rcTest9();

        if (l_res != 0)
        {
            TS_FAIL("testRc9. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI return codes #10
     */
    void testRc10()
    {
        uint32_t l_res = rcTest10();

        if (l_res != 0)
        {
            TS_FAIL("testRc10. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI return codes #11
     */
    void testRc11(void)
    {
        uint32_t l_res = rcTest11();

        if (l_res != 0)
        {
            TS_FAIL("testRc11. Fail l_res=%d", l_res);
        }
    }


    /**
     * @brief Test FAPI return codes #12
     */
    void testRc12()
    {
        uint32_t l_res = rcTest12();

        if (l_res != 0)
        {
            TS_FAIL("testRc12. Fail l_res=%d", l_res);
        }
    }

    /**
     * @brief Test FAPI return codes #13
     */
    void testRc13()
    {
        uint32_t l_res = rcTest13();

        if (l_res != 0)
        {
            TS_FAIL("testRc13. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI return codes #14
     */
    void testRc14()
    {
        uint32_t l_res = rcTest14();

        if (l_res != 0)
        {
            TS_FAIL("testRc14. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI return codes #15
     */
    void testRc15()
    {
        uint32_t l_res = rcTest15();

        if (l_res != 0)
        {
            TS_FAIL("testRc15. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI return codes #16
     */
    void testRc16()
    {
        uint32_t l_res = rcTest16();

        if (l_res != 0)
        {
            TS_FAIL("testRc16. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI return codes #17
     */
    void testRc17()
    {
        uint32_t l_res = rcTest17();

        if (l_res != 0)
        {
            TS_FAIL("testRc17. Fail l_res=%d", l_res);
        }
        return;
    }
};

#endif
