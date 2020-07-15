/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/rcTest.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
     * @brief Test FAPI2 return codes #2
     */
    void testFapi2ReturnCode2(void)
    {
// FIXME RTC:257497
// RC_TEST_ERROR_A required, in p9 comes from src/import/chips/p9/procedures/
// xml/error_info/proc_example_errors.xml
// There's no equivalent file in ekb-p10 yet.
#if 0
        uint32_t l_res = rcTestReturnCodeCreator();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode2. Fail l_res=%d", l_res);
        }
# endif
return;
    }


    /**
     * @brief Test FAPI2 return codes #3
     */
    void testFapi2ReturnCode3()
    {
        uint32_t l_res = rcTestComparisonOperatorWithRCValue();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode3. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #4
     */
    void testFapi2ReturnCode4()
    {
        uint32_t l_res = rcTestComparisonOperator();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode4. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #5
     */
    void testFapi2ReturnCode5()
    {
        uint32_t l_res = rcTestCopyConstructor();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode5. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #6
     */
    void testFapi2ReturnCode6()
    {
        uint32_t l_res = rcTestReturnCodeConstructor();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode6. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #7
     */
    void testFapi2ReturnCode7(void)
    {
        uint32_t l_res = rcTestGetErrorInfo();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode7. Fail l_res=%d", l_res);
        }
    }


    /**
     * @brief Test FAPI2 return codes #8
     */
    void testFapi2ReturnCode8()
    {
        uint32_t l_res = rcTestErrorInfo();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode8. Fail l_res=%d", l_res);
        }
    }

    /**
     * @brief Test FAPI2 return codes #9
     */
    void testFapi2ReturnCode9()
    {
        uint32_t l_res = rcTestCopyConstructorwithErrorInfo();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode9. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #10
     */
    void testFapi2ReturnCode10()
    {
        uint32_t l_res = rcTestAssignmentOperatorwithErrorInfo();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode10. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #11
     */
    void testFapi2ReturnCode11()
    {
        uint32_t l_res = rcTestClearErrorInfo();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode11. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #12
     */
    void testFapi2ReturnCode12()
    {
        uint32_t l_res = rcTestAddErrorInfo();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode12. Fail l_res=%d", l_res);
        }
        return;
    }

    /**
     * @brief Test FAPI2 return codes #13
     */
    void testFapi2ReturnCode13()
    {
        uint32_t l_res = rcTestStaticCast();

        if (l_res != 0)
        {
            TS_FAIL("testFapi2ReturnCode13. Fail l_res=%d", l_res);
        }
        return;
    }



    void testFapi2ReturnCodeAttrErrls(void)
    {
// FIXME RTC:257497
// RC_TEST_ERROR_A required, in p9 comes from src/import/chips/p9/procedures/
// xml/error_info/proc_example_errors.xml
// There's no equivalent file in ekb-p10 yet.
#if 0
        uint32_t l_res = rcTestReturnCodeAttrErrls();

        if (l_res != 0)
        {
            TS_FAIL("rcTestReturnCodeAttrErrls. Fail l_res=%d", l_res);
        }
#endif
return;
    }

};

#endif
