/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/test/fapiattrtest.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef FAPIATTRTEST_H
#define FAPIATTRTEST_H

/**
 *  @file fapiattrtanktest.H
 *
 *  @brief Test case for FAPI AttributeTank
*/

#include <cxxtest/TestSuite.H>
#include "fapiAttrTest.C"

using namespace fapi;

class FapiAttrTest: public CxxTest::TestSuite
{
public:

    void test1(void)
    {
        if (attrTest1() != 0)
        {
            TS_FAIL("attrTest1. Fail");
        }
    }

    void test2(void)
    {
        if (attrTest2() != 0)
        {
            TS_FAIL("attrTest2. Fail");
        }
    }

    void test3(void)
    {
        if (attrTest3() != 0)
        {
            TS_FAIL("attrTest3. Fail");
        }
    }

    void test4(void)
    {
        if (attrTest4() != 0)
        {
            TS_FAIL("attrTest4. Fail");
        }
    }

    void test5(void)
    {
        if (attrTest5() != 0)
        {
            TS_FAIL("attrTest5. Fail");
        }
    }

    void test6(void)
    {
        if (attrTest6() != 0)
        {
            TS_FAIL("attrTest6. Fail");
        }
    }

    void test7(void)
    {
        if (attrTest7() != 0)
        {
            TS_FAIL("attrTest7. Fail");
        }
    }
};

#endif
