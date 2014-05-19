/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiatest.H $                           */
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
#ifndef __TEST_MDIATESTMDIA_H
#define __TEST_MDIATESTMDIA_H

/**
 * @file mdiatestmdia.H
 * @brief mdia.C unit tests
 */

#include <builtins.h>
#include <cxxtest/TestSuite.H>
#include <targeting/common/target.H>
#include "../mdiafwd.H"

class MdiaTest : public CxxTest::TestSuite
{
    public:

        void testRunStep(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testRunStep");

            TargetHandleList list;

            errlHndl_t err = runStep(list);

            if(err)
            {
                TS_FAIL("runStep failed unexpectedly");
            }

            TS_TRACE(EXIT_MRK "testRunStep");
        }
};
#endif
