/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attntesttest.H $                       */
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
