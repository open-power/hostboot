/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiatestmba.H $                        */
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
#ifndef __TEST_MDIATESTMBA_H
#define __TEST_MDIATESTMBA_H

/**
 * @file mdiatestmba.H
 * @brief mdiamba unit tests
 */

#include <builtins.h>
#include <cxxtest/TestSuite.H>
#include <targeting/common/target.H>
#include <targeting/common/utilFilter.H>
#include "../mdiafwd.H"
#include "../mdiaglobals.H"
#include "../mdiasm.H"

class MdiaMbaTest : public CxxTest::TestSuite
{
    public:

        void testGetMbaDiagnosticMode(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testGetMbaDiagnosticMode");

            TargetHandleList mbaList;
            getAllChiplets(mbaList, TYPE_MBA);

            if( !mbaList.empty() )
            {
                DiagMode mode;
                Globals globals;
                TargetHandle_t mba = mbaList[0];

                errlHndl_t err = getMbaDiagnosticMode(
                                        globals, mba, mode);

                if(err)
                {
                    TS_FAIL("getMbaDiagnosticMode failed "
                            "unexpectedly");
                }

                if(mode != ONE_PATTERN)
                {
                    TS_FAIL("mode != ONE_PATTERN");
                }
            }

            TS_TRACE(EXIT_MRK "testGetMbaDiagnosticMode");
        }

        void testGetMbaWorkFlow(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testGetMbaWorkFlow");

            Globals globals;
            TargetHandle_t mba = 0;
            DiagMode mode;
            errlHndl_t err = NULL;
            TargetHandleList mbaList;
            getAllChiplets(mbaList, TYPE_MBA);

            if( !mbaList.empty() )
            {
                mba = mbaList[0];
                err = getMbaDiagnosticMode(
                                globals, mba, mode);

                if(err)
                {
                    TS_FAIL("getMbaDiagnosticMode "
                            "failed unexpectedly");
                }

                if(mode != ONE_PATTERN)
                {
                    TS_FAIL("mode != ONE_PATTERN");
                }
            }

            WorkFlow wf, expected;

            expected.push_back(RESTORE_DRAM_REPAIRS);
            expected.push_back(START_PATTERN_0);
            expected.push_back(START_SCRUB);
            expected.push_back(CLEAR_HW_CHANGED_STATE);

            err = getMbaWorkFlow(mode, wf, globals);

            if(err)
            {
                TS_FAIL("getMbaWorkFlow failed unexpectedly");
            }

            if(wf.size() != expected.size())
            {
                TS_FAIL("incorrect workflow size for init only mode");
            }

            int64_t index = wf.size();

            while(index-- != 0)
            {
                if(wf[index] != expected[index])
                {
                    TS_FAIL("workflow entry incorrect or out of order");
                }
            }

            TS_TRACE(EXIT_MRK "testGetMbaWorkFlow");
        }
};
#endif
