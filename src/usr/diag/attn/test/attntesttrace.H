/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attntesttrace.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
