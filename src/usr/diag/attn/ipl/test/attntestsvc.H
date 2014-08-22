/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/hostboot/test/attntestsvc.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef __TEST_ATTNTESTSVC_H
#define __TEST_ATTNTESTSVC_H

/**
 * @file attntestsvc.H
 *
 * @brief Unit test for the attnsvc module.
 */

#include "../attnsvc.H"
#include "attnfakesys.H"
#include "attntest.H"
#include <cxxtest/TestSuite.H>

using namespace ATTN;
using namespace std;

/**
 * @brief AttnSvcTest Unit test for the attnsvc module.
 */
class AttnSvcTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief testStartStop Unit test for the
         *        start and stop methods.
         */
        void testStartStop(void)
        {
            return; // FIXME RTC: 67008

            TS_TRACE(ENTER_MRK "testStartStop");

            errlHndl_t err = 0;

            Service svc;

            do {

                err = svc.start();

                if(err)
                {
                    TS_FAIL("unexpected error starting service");
                    break;
                }

                if(!svc.iv_intrTask)
                {
                    TS_FAIL("interrupt task not started");
                }

                if(!svc.iv_prdTask)
                {
                    TS_FAIL("prd task not started");
                }

                if(svc.iv_shutdownPrdTask)
                {
                    TS_FAIL("shutdown variable set");
                }

                if(!svc.iv_intrTaskQ)
                {
                    TS_FAIL("no message q created");
                }

                // should be able to call start again

                err = svc.start();

                if(err)
                {
                    TS_FAIL("unexpected error starting service");
                    break;
                }

                if(!svc.iv_intrTask)
                {
                    TS_FAIL("interrupt task not started");
                }

                if(!svc.iv_prdTask)
                {
                    TS_FAIL("prd task not started");
                }

                if(svc.iv_shutdownPrdTask)
                {
                    TS_FAIL("shutdown variable set");
                }

                if(!svc.iv_intrTaskQ)
                {
                    TS_FAIL("no message q created");
                }

                err = svc.stop();

                if(err)
                {
                    TS_FAIL("unexpected error stopping service");
                    break;
                }

                if(svc.iv_intrTask)
                {
                    TS_FAIL("interrupt task not stopped");
                }

                if(svc.iv_prdTask)
                {
                    TS_FAIL("prd task not stopped");
                }

                if(svc.iv_shutdownPrdTask)
                {
                    TS_FAIL("shutdown variable set");
                }

                if(svc.iv_intrTaskQ)
                {
                    TS_FAIL("message q not reclaimed");
                }

                // should be able to call stop again

                err = svc.stop();

                if(err)
                {
                    TS_FAIL("unexpected error stopping service");
                    break;
                }

                if(svc.iv_intrTask)
                {
                    TS_FAIL("interrupt task not stopped");
                }

                if(svc.iv_prdTask)
                {
                    TS_FAIL("prd task not stopped");
                }

                if(svc.iv_shutdownPrdTask)
                {
                    TS_FAIL("shutdown variable set");
                }

                if(svc.iv_intrTaskQ)
                {
                    TS_FAIL("message q not reclaimed");
                }

            } while(0);

            TS_TRACE(EXIT_MRK "testStartStop");
        }

        /**
         * @brief testAttentions Unit test for the attnsvc module.
         */
        void testAttentions()
        {
            static const uint64_t targetPoolSize = 8;
            static const uint64_t iterations = 5;
            static const uint64_t maxAttnsPerIteration = 5;

            TS_TRACE(ENTER_MRK "testAttentions");

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

            FakeMcs rec(RECOVERABLE), xstp(CHECK_STOP), special(SPECIAL);
            FakeGp1 gp1;

            xstp.install(system);
            special.install(system);
            rec.install(system);
            gp1.install(system);

            FakeIpoll xstpIpoll(CHECK_STOP, presenter),
                      spclIpoll(SPECIAL, presenter),
                      recIpoll(RECOVERABLE, presenter),
                      hostIpoll(HOST, presenter);

            xstpIpoll.install(system);
            spclIpoll.install(system);
            recIpoll.install(system);
            hostIpoll.install(system);

            Validator v;

            v.install(system);

            system.installScomImpl();

            FakeMemTargetService targetSvc(targetPoolSize);

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

                if(!memSource.start())
                {
                    TS_FAIL("unexpected error starting source");
                    break;
                }

                if(!procSource.start())
                {
                    TS_FAIL("unexpected error starting source");
                    break;
                }

                // wait for the testcase to finish injecting attentions

                if(!memSource.wait())
                {
                    TS_FAIL("unexpected error waiting for source");
                    break;
                }

                if(!procSource.wait())
                {
                    TS_FAIL("unexpected error waiting for source");
                    break;
                }

                // wait for the the service to handle all the attentions
                TS_TRACE("Waiting for attentions to be cleared.");

                if(!system.wait(TEN_CTX_SWITCHES_NS * iterations * 100))
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

            TS_TRACE(EXIT_MRK "testAttentions");
        }
};
#endif
