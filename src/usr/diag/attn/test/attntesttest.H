/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attntesttest.H $                       */
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

#ifndef __TEST_ATTNTESTTEST_H
#define __TEST_ATTNTESTTEST_H

/**
 * @file attntesttest.H
 *
 * @brief Unit test for the attntest module.
 */

#include "../attnfwd.H"
#include "attntest.H"
#include <cxxtest/TestSuite.H>

using namespace ATTN;

/**
 * @brief AttnTest Unit test for the attntest module.
 */
class AttnTestTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief Unit test for the randint function.
         */
        void testRand(void)
        {
            TS_TRACE(ENTER_MRK "testRand");

            int64_t lower, upper;

            for(int64_t iteration = 1; iteration < 100; ++iteration)
            {
                lower = iteration;
                upper = iteration * iteration;

                int64_t val = randint(lower, upper);

                if(val < lower || upper < val)
                {
                    TS_FAIL("rand %d not between bounds %d and %d");
                }

                lower = iteration;
                upper = iteration + iteration;

                val = randint(lower, upper);

                if(val < lower || upper < val)
                {
                    TS_FAIL("rand %d not between bounds %d and %d");
                }
            }

            TS_TRACE(EXIT_MRK "testRand");
        }
};
#endif
