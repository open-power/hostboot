/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/ipl/test/attntestproc.H $                   */
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
#ifndef __TEST_ATTNTESTPROC_H
#define __TEST_ATTNTESTPROC_H

/**
 * @file attntestproc.H
 *
 * @brief Unit test for the attnproc module.
 */

#include "../../common/attnproc.H"
#include "../attnsvc.H"
#include "attnfakesys.H"
#include "attnfakeprd.H"
#include "attnfakegfir.H"
#include "attnfakeipoll.H"
#include "attnrandsource.H"
#include "attnfaketarget.H"
#include "attnfakepresenter.H"
#include "attntest.H"
#include "attnvalidate.H"
#include <cxxtest/TestSuite.H>
#include <sys/time.h>
#include "../../common/attntrace.H"
#include <targeting/common/targetservice.H>

using namespace ATTN;
using namespace PRDF;
using namespace std;

/**
 * @brief AttnProcTest Unit test for the attnproc module.
 */
class AttnProcTest: public CxxTest::TestSuite
{
    public:
        /**
         * @brief testQuery Unit test for the
         *        query method.
         */
        void testQuery(void)
        {
            ATTN_SLOW(ENTER_MRK "AttnProcTest::testQuery");
#if 0  // asdf bjs @TODO: RTC:151004

            static const uint64_t iterations = 100;
            static const uint64_t targetPoolSize = 8;

            errlHndl_t err = 0;

            ProcOps ops;
            AttnData d;

            FakeSystem system;
            FakeProcTargetService targetSvc(targetPoolSize);

            TargetHandleList procs;

            targetSvc.getAllChips(procs, TYPE_PROC);

            FakeGfir xstpGfir(CHECK_STOP),
                     spclGfir(SPECIAL),
                     recGfir(RECOVERABLE);

            xstpGfir.install(system);
            spclGfir.install(system);
            recGfir.install(system);

            system.installScomImpl();
            targetSvc.installTargetService();

            for(uint64_t it = 0; it < iterations; ++it)
            {
                bool result;

                d.targetHndl = *(&procs[0] + randint(0, targetPoolSize -1));
                d.attnType = getRandomAttentionType();

                // set the error in hardware

                err = system.putAttentions(AttnList(1, d));
                if(err)
                {
                    TS_FAIL("unexpected error calling putAttentions");
                    break;
                }

                err = ops.query(d, result);

                if(err)
                {
                    TS_FAIL("unexpected error calling query");
                    break;
                }

                if(!result)
                {
                    TS_FAIL("expected attention");
                    break;
                }

                // clear the error in hardware

                err = system.clearAttention(d);
                if(err)
                {
                    TS_FAIL("unexpected error calling clearAttention");
                    break;
                }

                err = ops.query(d, result);

                if(err)
                {
                    TS_FAIL("unexpected error calling query");
                    break;
                }

                if(result)
                {
                    TS_FAIL("did not expect attention");
                    break;
                }
            }
#endif

            ATTN_SLOW(EXIT_MRK "AttnProcTest::testQuery");
        }

        /**
         * @brief testFakeAttentions Unit test for the
         *        attnproc module.
         */
        void testFakeAttentions()
        {
            ATTN_SLOW(ENTER_MRK "AttnProcTest::testFakeAttentions");
#if 0 // asdf bjs @TODO: RTC:151004
            static const uint64_t targetPoolSize = 8;
            static const uint64_t iterations = 5;
            static const uint64_t maxAttnsPerIteration = 5;

            errlHndl_t err = 0;

            Service svc;

            FakePresenter presenter;
            FakeSystem system;

            FakeGfir xstpGfir(CHECK_STOP),
                     spclGfir(SPECIAL),
                     recGfir(RECOVERABLE);

            xstpGfir.install(system);
            spclGfir.install(system);
            recGfir.install(system);

            FakeIpoll xstpIpoll(CHECK_STOP, presenter),
                      spclIpoll(SPECIAL, presenter),
                      recIpoll(RECOVERABLE, presenter);

            xstpIpoll.install(system);
            spclIpoll.install(system);
            recIpoll.install(system);

            Validator v;

            v.install(system);

            system.installScomImpl();

            FakeProcTargetService targetSvc(targetPoolSize);

            TargetHandleList procs;

            targetSvc.getAllChips(procs, TYPE_PROC);

            RandSource source(
                    iterations,
                    maxAttnsPerIteration,
                    system,
                    &procs[0],
                    &procs[0] + procs.size());

            targetSvc.installTargetService();

            FakePrd prd(system);

            prd.installPrd();

            getProcOps().enable();

            do
            {
                err = svc.start();

                if(err)
                {
                    TS_FAIL("unexpected error starting service");
                    break;
                }

                if(!presenter.start(svc.iv_intrTaskQ))
                {
                    TS_FAIL("unexpected error starting fake presenter");
                    break;
                }

                if(!source.start())
                {
                    TS_FAIL("unexpected error starting source");
                    break;
                }

                // wait for the testcase to finish injecting attentions

                if(!source.wait())
                {
                    TS_FAIL("unexpected error waiting for source");
                    break;
                }

                // wait for the the service to handle all the attentions
                TS_TRACE("Waiting for attentions to be cleared.");

                if(!system.wait(TEN_CTX_SWITCHES_NS * iterations * 50))
                {
                    TS_FAIL("Attentions still present on system.");

                    system.dump();
                    break;
                }

            } while(0);

            err = svc.stop();

            if(err)
            {
                TS_FAIL("unexpected error stopping service");
                delete err;
            }

            presenter.stop();

            if(!v.empty())
            {
                TS_FAIL("unexpected result after injecting attentions");

                v.dump();
            }
#endif

            ATTN_SLOW(EXIT_MRK "AttnProcTest::testFakeAttentions");
        }


        // Want to verify the HW workaround on NIMBUS
        // for clearing F001A reg on RECOV errors.
        void testRecovAttnWorkaround()
        {
            static const uint64_t targetPoolSize = 1;
            static const uint64_t iterations = 1;
            static const uint64_t maxAttnsPerIteration = 1;
            uint64_t l_intrAddrReg  = 0x00000000000F001Aull;
            uint64_t l_intrAddrData = 0xE000000000000000ull;
            uint64_t l_intrDataRead = l_intrAddrData;



            ATTN_SLOW("AttnProcTest::testRecovAttnWorkaround");

            errlHndl_t err = 0;

            // Verify RECOV error goes thru the workaround
            ATTN_SLOW("AttnProcTest::RECOV TEST");

            FakeSystem system;

            FakeGfir recGfir(RECOVERABLE);
            recGfir.install(system);

            Validator v;
            v.install(system);
            system.installScomImpl();

            FakeProcTargetService targetSvc(targetPoolSize);
            TargetHandleList procs;
            targetSvc.getAllChips(procs, TYPE_PROC);

            RandSource source(
                    iterations,
                    maxAttnsPerIteration,
                    system,
                    &procs[0],
                    &procs[0] + procs.size());

            targetSvc.installTargetService();

            FakePrd prd(system);
            prd.installPrd();

            getProcOps().enable();

            ATTN_SLOW("AttnProcTest::testRecovAttnWorkaround ready to go");

            do
            {
                // ---------------------------------------
                // Alter the combined global interrupt reg
                // so we can verify it later
                err = putScom( procs[0],
                               l_intrAddrReg,
                               l_intrAddrData
                             );

                if (NULL != err)
                {
                    TS_FAIL("Error1 setting Reg %016llx Data:%016llx",
                            l_intrAddrReg, l_intrAddrData );
                    break;
                }
                // ---------------------------------------

                source.run(RECOVERABLE);

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

                // ---------------------------------------
                // The combined global interrupt reg should get
                // reset (at least on certain level of hardware)
                err = getScom( procs[0],
                               l_intrAddrReg,
                               l_intrDataRead
                             );

                if (NULL != err)
                {
                    TS_FAIL("Error1 getting Reg %016llx Data:%016llx",
                            l_intrAddrReg, l_intrAddrData );
                    break;
                }

                // Verify REG is MODIFIED this time
                if (0 != l_intrDataRead)
                {
                    TS_FAIL("Int Reg1 Not cleared: Orig:%016llx  Read:%016llx",
                            l_intrAddrData, l_intrDataRead );
                    break;
                }
                // ---------------------------------------


            } while(0);


            // Verify HOST_ATTN skips the workaround
            FakeSystem systemHA;

            FakeGfir haGfir(HOST_ATTN);
            haGfir.install(systemHA);

            Validator vHA;
            vHA.install(systemHA);
            systemHA.installScomImpl();

            RandSource sourceHA(
                    iterations,
                    maxAttnsPerIteration,
                    systemHA,
                    &procs[0],
                    &procs[0] + procs.size());

            FakePrd prdHA(systemHA);
            prdHA.installPrd();

            getProcOps().enable();

            ATTN_SLOW("AttnProcTest::testRecovAttnWorkaround2  ready to go");

            do
            {
                // ---------------------------------------
                // Alter the combined global interrupt reg
                // so we can verify it later
                err = putScom( procs[0],
                               l_intrAddrReg,
                               l_intrAddrData
                             );

                if (NULL != err)
                {
                    TS_FAIL("Error2 setting Reg %016llx Data:%016llx",
                            l_intrAddrReg, l_intrAddrData );
                    break;
                }
                // ---------------------------------------

                sourceHA.run(HOST_ATTN);

                err = checkForIplAttentions();

                if(err)
                {
                    TS_FAIL("unexpected error checking for ipl attentions2.");
                    break;
                }

                uint64_t count = systemHA.count();
                if(count)
                {
                    TS_FAIL("%d unexpected attentions present after check for "
                            "ipl attentions2.", count);

                    systemHA.dump();
                    break;
                }

                // ---------------------------------------
                // The combined global interrupt reg should not
                // change
                err = getScom( procs[0],
                               l_intrAddrReg,
                               l_intrDataRead
                             );

                if (NULL != err)
                {
                    TS_FAIL("Error2 getting Reg %016llx Data:%016llx",
                            l_intrAddrReg, l_intrAddrData );
                    break;
                }

                // Verify REG is MODIFIED this time
                if (l_intrAddrData != l_intrDataRead)
                {
                    TS_FAIL("Int Reg2 altered rig:%016llx  Read:%016llx",
                            l_intrAddrData, l_intrDataRead );
                    break;
                }
                // ---------------------------------------

            } while(0);


            ATTN_SLOW("AttnProcTest::testRecovAttnWorkaround  ending");

        }  // end testRecovAttnWorkaround

};
#endif
