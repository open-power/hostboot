/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attntestops.H $                        */
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
