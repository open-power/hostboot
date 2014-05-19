/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/test/fapitargettest.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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

    /**
     * @brief Test target #7
     */
    void testTarget7()
    {
        uint32_t l_res = targetTest7();

        if (l_res != 0)
        {
            TS_FAIL("testTarget7. Fail");
        }
    }

    /**
     * @brief Test target #8
     */
    void testTarget8()
    {
        uint32_t l_res = targetTest8();

        if (l_res != 0)
        {
            TS_FAIL("testTarget8. Fail");
        }
    }
};

#endif
