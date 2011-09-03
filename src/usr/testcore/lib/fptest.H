//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/testcore/lib/fptest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __TESTCORE_LIB_FPTEST_H
#define __TESTCORE_LIB_FPTEST_H

/** @file fptest.H
 *  @brief Test cases for floating point support.
 */
#include <math.h>

class FloatingPointTest : public CxxTest::TestSuite
{
    public:

        void testSqrt()
        {
            if (2.0 != sqrt(4.0))
            {
                TS_FAIL("SQRT(4) != 2");
            }

            if (3.0 != sqrt(9.0))
            {
                TS_FAIL("SQRT(9) != 3");
            }
        }
};

#endif
