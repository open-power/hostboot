/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/ipl/test/attntestipl.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#include "../../common/attnproc.H"
#include <cxxtest/TestSuite.H>
#include "../../common/attntrace.H"
#include <targeting/common/targetservice.H>

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
            ATTN_SLOW(ENTER_MRK "AttnCheckForIplAttentionsTest::"
                                "testCheckForIplAttentions");

            static const uint64_t targetPoolSize = 8;
            static const uint64_t iterations = 100;
            static const uint64_t maxAttnsPerIteration = 5;
            uint8_t              l_useAllProcs = 0;
            uint8_t              l_saveAttrProcs = 0;
            TARGETING::Target   *l_sys = NULL;


            // We have an ATTRIBUTE that indicates all procs
            // or just the master proc.
            TARGETING::targetService().getTopLevelTarget( l_sys );
            assert(l_sys != NULL);
            // want to save/restore this
            l_sys->tryGetAttr<ATTR_ATTN_CHK_ALL_PROCS>(l_saveAttrProcs);
            l_sys->trySetAttr<ATTR_ATTN_CHK_ALL_PROCS>(l_useAllProcs);

            errlHndl_t err = 0;

            FakeSystem system;

            FakeGfir xstpGfir(CHECK_STOP),
                     spclGfir(SPECIAL),
                     recGfir(RECOVERABLE),
                     lxstpGfir(UNIT_CS),
                     hostGfir((PRDF::ATTENTION_VALUE_TYPE)HOST_ATTN);

            xstpGfir.install(system);
            spclGfir.install(system);
            recGfir.install(system);
            lxstpGfir.install(system);
            hostGfir.install(system);

            // No Centaurs to mess with for now

            system.installScomImpl();
            FakeMemTargetService targetSvc(targetPoolSize);

            TargetHandleList  procs;
            targetSvc.getAllChips(procs, TYPE_PROC);

            RandSource procSource(iterations,
                    maxAttnsPerIteration,
                    system,
                    &procs[0],
                    &procs[0] + 1);  // just one proc


            targetSvc.installTargetService();

            FakePrd prd(system);

            prd.installPrd();
            getProcOps().enable();

            do
            {
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
                    TS_FAIL("%d unexpected attentions present after check for "
                            "ipl attentions.", count);

                    system.dump();
                    break;
                }

            } while(0);

            // Put back the attribute's original value
            l_sys->trySetAttr<ATTR_ATTN_CHK_ALL_PROCS>(l_saveAttrProcs);

            ATTN_SLOW(EXIT_MRK "AttnCheckForIplAttentionsTest::"
                               "testCheckForIplAttentions");
        }

        /**
         * @brief testCheckForIplAttentions Unit test for the
         *              check for ipl attentions module.
         */
        void testCheckForIplAttentionsAllProcs(void)
        {
            ATTN_SLOW(ENTER_MRK "AttnCheckForIplAttentionsTest::"
                                "testCheckForIplAttentionsAllProcs");

            static const uint64_t targetPoolSize = 8;
            static const uint64_t iterations = 100;
            static const uint64_t maxAttnsPerIteration = 5;
            uint8_t              l_useAllProcs = 1;
            uint8_t              l_saveAttrProcs = 0;
            TARGETING::Target   *l_sys = NULL;


            // We have an ATTRIBUTE that indicates all procs
            // or just the master proc.
            TARGETING::targetService().getTopLevelTarget( l_sys );
            assert(l_sys != NULL);
            // want to save/restore this
            l_sys->tryGetAttr<ATTR_ATTN_CHK_ALL_PROCS>(l_saveAttrProcs);
            l_sys->trySetAttr<ATTR_ATTN_CHK_ALL_PROCS>(l_useAllProcs);

            errlHndl_t err = 0;

            FakeSystem system;

            FakeGfir xstpGfir(CHECK_STOP),
                     spclGfir(SPECIAL),
                     recGfir(RECOVERABLE),
                     lxstpGfir(UNIT_CS),
                     hostGfir((PRDF::ATTENTION_VALUE_TYPE)HOST_ATTN);

            xstpGfir.install(system);
            spclGfir.install(system);
            recGfir.install(system);
            lxstpGfir.install(system);
            hostGfir.install(system);

            // No Centaurs to mess with for now

            system.installScomImpl();
            FakeMemTargetService targetSvc(targetPoolSize);

            TargetHandleList  procs;
            targetSvc.getAllChips(procs, TYPE_PROC);

            RandSource procSource(iterations,
                    maxAttnsPerIteration,
                    system,
                    &procs[0],
                    &procs[0] + procs.size());  // many procs possible


            targetSvc.installTargetService();

            FakePrd prd(system);

            prd.installPrd();
            getProcOps().enable();

            do
            {
                procSource.run();

                err = checkForIplAttentions();

                if(err)
                {
                    TS_FAIL("unexpected error checking for ALL ipl attns.");
                    break;
                }

                uint64_t count = system.count();
                if(count)
                {
                    TS_FAIL("%d unexpected attentions present after check for "
                            "ALL ipl attentions.", count);

                    system.dump();
                    break;
                }

            } while(0);

            // Put back the attribute's original value
            l_sys->trySetAttr<ATTR_ATTN_CHK_ALL_PROCS>(l_saveAttrProcs);

            ATTN_SLOW(EXIT_MRK "AttnCheckForIplAttentionsTest::"
                               "testCheckForIplAttentionsAllProcs");
        }


};
#endif
