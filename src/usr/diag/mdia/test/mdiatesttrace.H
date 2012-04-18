//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/test/mdiatesttrace.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
#ifndef __TEST_MDIATESTTRACE_H
#define __TEST_MDIATESTTRACE_H

/**
 * @file mdiatesttrace.H
 * @brief mdia trace unit test
 */

#include <builtins.h>
#include <cxxtest/TestSuite.H>
#include <targeting/common/attributes.H>
#include "../mdiatrace.H"

class MdiaTraceTest : public CxxTest::TestSuite
{
    public:

        void testTrace(void)
        {
            using namespace MDIA;

            TS_TRACE(ENTER_MRK "testTrace");

            MDIA_FAST("mdia trace unit test");
            MDIA_FAST("mdia trace unit test: %p", 0);
            MDIA_FAST("mdia trace unit test: %d", 1234);

            MDIA_DBG("mdia trace unit test");
            MDIA_DBG("mdia trace unit test: %p", 0);
            MDIA_DBG("mdia trace unit test: %d", 1234);

            MDIA_ERR("mdia trace unit test");
            MDIA_ERR("mdia trace unit test: %p", 0);
            MDIA_ERR("mdia trace unit test: %d", 1234);

            MDIA_SLOW("mdia trace unit test");
            MDIA_SLOW("mdia trace unit test: %p", 0);
            MDIA_SLOW("mdia trace unit test: %d", 1234);

            TS_TRACE(EXIT_MRK "testTrace");
        }
};
#endif
