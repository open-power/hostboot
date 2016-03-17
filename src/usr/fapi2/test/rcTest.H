/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/rcTest.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
#ifndef __rcTest_H
#define __rcTest_H

/**
 *  @file rcTest.H
 *
 *  @brief Test case for FAPI2 return codes
*/

#include <cxxtest/TestSuite.H>
#include <fapi2.H>
#include "rcTest.C"

using namespace fapi2;

class test_Fapi2ReturnCode: public CxxTest::TestSuite
{
public:

    /**
     * @brief Test FAPI2 return codes #1
     */
    void testFapi2ReturnCode1(void)
    {
        uint32_t l_res = rcTestDefaultConstructor();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode1. Fail l_res=%d", l_res);
        }
    }


    /**
     * @brief Test FAPI2 return codes #5
     */
    void testFapi2ReturnCode5()
    {
        uint32_t l_res = rcTestComparisonOperatorWithRCValue();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode5. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #11
     */
    void testFapi2ReturnCode11(void)
    {
        uint32_t l_res = rcTestGetErrorInfo();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode11. Fail l_res=%d", l_res);
        }
    }


    /**
     * @brief Test FAPI2 return codes #12
     */
    void testFapi2ReturnCode12()
    {
        uint32_t l_res = rcTestErrorInfo();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode12. Fail l_res=%d", l_res);
        }
    }

    /**
     * @brief Test FAPI2 return codes #13
     */
    void testFapi2ReturnCode13()
    {
        uint32_t l_res = rcTestCopyConstructorwithErrorInfo();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode13. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #14
     */
    void testFapi2ReturnCode14()
    {
        uint32_t l_res = rcTestAssignmentOperatorwithErrorInfo();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode14. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #15
     */
    void testFapi2ReturnCode15()
    {
        uint32_t l_res = rcTestClearErrorInfo();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode15. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #16
     */
    void testFapi2ReturnCode16()
    {
        uint32_t l_res = rcTestAddErrorInfo();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode16. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #17
     */
    void testFapi2ReturnCode17()
    {
        uint32_t l_res = rcTestStaticCast();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode17. Fail l_res=%d", l_res);
        }
        return;
    }
};

#endif
