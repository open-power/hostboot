/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attntestops.H $                        */
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

#ifndef __TEST_ATTNTESTOPS_H
#define __TEST_ATTNTESTOPS_H

/**
 * @file attntestops.H
 *
 * @brief Unit test for the attnops module.
 */

#include "../attnfwd.H"
#include "../attnops.H"
#include <cxxtest/TestSuite.H>

using namespace ATTN;
using namespace TARGETING;
using namespace PRDF;

/**
 * @brief AttnOpsTest Unit test for the attnops module.
 */
class AttnOpsTest : public CxxTest::TestSuite
{
    public:

        /**
         * @brief testCompare Unit test for the
         *        compare method.
         */
        void testCompare(void)
        {
            static const TargetHandle_t nullTarget = 0;

            static const struct Test
            {
                TargetHandle_t targetA;
                TargetHandle_t targetB;
                ATTENTION_VALUE_TYPE typeA;
                ATTENTION_VALUE_TYPE typeB;
                int64_t expected;

            } tests[] = {

                {nullTarget, nullTarget, CHECK_STOP, SPECIAL, -1},
                {nullTarget, nullTarget, SPECIAL, CHECK_STOP, 1},
                {nullTarget, nullTarget, CHECK_STOP, CHECK_STOP, 0},
                {nullTarget, nullTarget, SPECIAL, SPECIAL, 0},
                {nullTarget, nullTarget +1, SPECIAL, SPECIAL, -1},
                {nullTarget +1, nullTarget +1, SPECIAL, SPECIAL, 0},
                {nullTarget +1, nullTarget, SPECIAL, SPECIAL, 1},
                {nullTarget, nullTarget +1, CHECK_STOP, SPECIAL, -1},
                {nullTarget, nullTarget +1, SPECIAL, CHECK_STOP, 1},
                {nullTarget +1, nullTarget, CHECK_STOP, SPECIAL, -1},
                {nullTarget +1, nullTarget, SPECIAL, CHECK_STOP, 1},
            };

            static const Test * testsEnd = tests
                + sizeof(tests)/sizeof(*tests);

            TS_TRACE(ENTER_MRK "testCompare");

            const Test * testIt = tests;

            AttnData a, b;

            while(testIt != testsEnd)
            {
                a.targetHndl = testIt->targetA;
                b.targetHndl = testIt->targetB;
                a.attnType = testIt->typeA;
                b.attnType = testIt->typeB;

                AttentionOps * nullOps = 0;

                Attention lhs(a, nullOps), rhs(b, nullOps);

                if(lhs.compare(rhs) != testIt->expected)
                {
                    TS_FAIL("Unexpected result comparing attentions");
                    break;
                }

                ++testIt;
            }

            TS_TRACE(EXIT_MRK "testCompare");
        }
};
#endif
