/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attntestipl.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __TEST_ATTNTESTIPL_H
#define __TEST_ATTNTESTIPL_H

/**
 * @file attntestipl.H
 *
 * @brief Unit test for check for ipl attentions module.
 */

#include "attnfakesys.H"
#include "attnfakegfir.H"
#include "attnfakemcs.H"
#include "attnfakegp1.H"
#include "attnfaketarget.H"
#include "attnrandsource.H"
#include "attnfakeprd.H"
#include "attntest.H"
#include "../attnproc.H"
#include <cxxtest/TestSuite.H>

using namespace ATTN;
using namespace TARGETING;
using namespace PRDF;

/**
 * @brief AttnCheckForIplAttentionsTest Unit test for the check for ipl attentions module.
 */
class AttnCheckForIplAttentionsTest : public CxxTest::TestSuite
{
    public:

        /**
         * @brief testCheckForIplAttentions Unit test for the
         *              check for ipl attentions module.
         */
        void testCheckForIplAttentions(void)
        {
            static const uint64_t targetPoolSize = 8;
            static const uint64_t iterations = 100;
            static const uint64_t maxAttnsPerIteration = 5;

            TS_TRACE(ENTER_MRK "testCheckForIplAttentions");

            errlHndl_t err = 0;

            FakeSystem system;

            FakeGfir xstpGfir(CHECK_STOP),
                     spclGfir(SPECIAL),
                     recGfir(RECOVERABLE);

            xstpGfir.install(system);
            spclGfir.install(system);
            recGfir.install(system);

            FakeMcs rec(RECOVERABLE), xstp(CHECK_STOP), special(SPECIAL);
            FakeGp1 gp1;

            xstp.install(system);
            special.install(system);
            rec.install(system);
            gp1.install(system);

            system.installScomImpl();

            FakeMemTargetService targetSvc(
                    targetPoolSize);

            TargetHandleList membufs, procs;

            targetSvc.getAllChips(procs, TYPE_PROC);
            targetSvc.getAllChips(membufs, TYPE_MEMBUF);

            RandSource procSource(iterations,
                    maxAttnsPerIteration,
                    system,
                    &procs[0],
                    &procs[0] + procs.size());

            RandSource memSource(
                    iterations,
                    maxAttnsPerIteration,
                    system,
                    &membufs[0],
                    &membufs[0] + membufs.size());

            targetSvc.installTargetService();

            FakePrd prd(system);

            prd.installPrd();
            getProcOps().enable();

            do
            {
                memSource.run();
                procSource.run();

                err = checkForIplAttentions();

                if(err)
                {
                    TS_FAIL("unexpected error checking for ipl attentions.");
                    break;
                }

                uint64_t count = system.count();
                if(count)
                {
                    TS_FAIL("%d unexpected attentions present after check for ipl attentions.", count);

                    system.dump();
                    break;
                }

            } while(0);

            TS_TRACE(EXIT_MRK "testCheckForIplAttentions");
        }
};
#endif
