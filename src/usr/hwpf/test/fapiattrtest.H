/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/test/fapiattrtest.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
