/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attntesttrace.H $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

#ifndef __TEST_ATTNTESTTRACE_H
#define __TEST_ATTNTESTTRACE_H

/**
 * @file attntesttrace.H
 *
 * @brief Unit test for the attntrace module.
 */

#include "../attnfwd.H"
#include "../attntrace.H"
#include <cxxtest/TestSuite.H>

/**
 * @brief AttnTraceTest Unit test for the attntrace module.
 */
class AttnTraceTest : public CxxTest::TestSuite
{
    public:

        /**
         * @brief testTrace Unit test for ATTN trace
         *        macros.
         */
        void testTrace(void)
        {
            using namespace ATTN;

            TS_TRACE(ENTER_MRK "testTrace");

            ATTN_FAST("attn trace unit test");
            ATTN_FAST("attn trace unit test: %p", 0);
            ATTN_FAST("attn trace unit test: %d", 1234);

            ATTN_DBG("attn trace unit test");
            ATTN_DBG("attn trace unit test: %p", 0);
            ATTN_DBG("attn trace unit test: %d", 1234);

            ATTN_ERR("attn trace unit test");
            ATTN_ERR("attn trace unit test: %p", 0);
            ATTN_ERR("attn trace unit test: %d", 1234);

            ATTN_SLOW("attn trace unit test");
            ATTN_SLOW("attn trace unit test: %p", 0);
            ATTN_SLOW("attn trace unit test: %d", 1234);

            TS_TRACE(EXIT_MRK "testTrace");
        }
};
#endif
