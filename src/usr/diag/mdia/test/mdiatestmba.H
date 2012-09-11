/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiatestmba.H $                        */
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
#ifndef __TEST_MDIATESTMBA_H
#define __TEST_MDIATESTMBA_H

/**
 * @file mdiatestmba.H
 * @brief mdiamba unit tests
 */

#include <builtins.h>
#include <cxxtest/TestSuite.H>
#include <targeting/common/target.H>
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

            DiagMode mode;
            Globals globals;
            TargetHandle_t mba = 0;

            errlHndl_t err = getMbaDiagnosticMode(
                    globals, mba, mode);

            if(err)
            {
                TS_FAIL("getMbaDiagnosticMode failed unexpectedly");
            }

            if(mode != INIT_ONLY)
            {
                TS_FAIL("mode != INIT_ONLY");
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

            errlHndl_t err = getMbaDiagnosticMode(
                    globals, mba, mode);

            if(err)
            {
                TS_FAIL("getMbaDiagnosticMode failed unexpectedly");
            }

            if(mode != INIT_ONLY)
            {
                TS_FAIL("mode != INIT_ONLY");
            }

            WorkFlow wf, expected;

            expected.push_back(RESTORE_DRAM_REPAIRS);
            expected.push_back(START_PATTERN_0);

            err = getMbaWorkFlow(mode, wf);

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
