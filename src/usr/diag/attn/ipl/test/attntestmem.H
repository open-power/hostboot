/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/ipl/test/attntestmem.H $                    */
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
#ifndef __TEST_ATTNTESTMEM_H
#define __TEST_ATTNTESTMEM_H

/**
 * @file attntestmem.H
 *
 * @brief Unit test for the attnmem module.
 */

#include "../../common/attnmem.H"
#include "../attnsvc.H"
#include "attntest.H"
#include "attncomp.H"
#include "attnfakesys.H"
#include "attnfakemcs.H"
#include "attnfakegp1.H"
#include "attnfakeipoll.H"
#include "attnfakepresenter.H"
#include "attnfakeprd.H"
#include "attnrandsource.H"
#include "attnfaketarget.H"
#include "attnvalidate.H"
#include "attnmeminject.H"
#include <cxxtest/TestSuite.H>
#include <sys/time.h>
#include "../../common/attntrace.H"

using namespace ATTN;
using namespace std;

/**
 * @brief AttnMemTest Unit test for the attnmem module.
 */
class AttnMemTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief testFakeAttentions Unit test for the
         *        attnmem module.
         */
        void testFakeAttentions()
        {
            ATTN_SLOW(ENTER_MRK "AttnMemTest::testFakeAttentions");

            static const uint64_t targetPoolSize = 8;
            static const uint64_t iterations = 5;
            static const uint64_t maxAttentionsPerIteration = 5;

            errlHndl_t err = 0;

            Service svc;

            FakePresenter presenter;
            FakeSystem system;

            FakeMemTargetService targetSvc(targetPoolSize);

            TargetHandleList membufs;

            targetSvc.getAllChips(membufs, TYPE_MEMBUF);

            FakeIpoll hostIpoll(PRDF::HOST_ATTN, presenter);
            FakeMcs rec(RECOVERABLE), xstp(CHECK_STOP), special(SPECIAL);
            FakeGp1 gp1;

            Validator v;

            xstp.install(system);
            special.install(system);
            rec.install(system);
            gp1.install(system);
            hostIpoll.install(system);
            v.install(system);

            system.installScomImpl();

            targetSvc.installTargetService();

            RandSource source(
                    iterations,
                    maxAttentionsPerIteration,
                    system,
                    &membufs[0],
                    &membufs[0] + membufs.size());

            FakePrd prd(system);

            prd.installPrd();

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

            ATTN_SLOW(EXIT_MRK "AttnMemTest::testFakeAttentions");
        }

        /**
         * @brief testAttentions Unit test for the
         *        attnmem module.
         */
        void testAttentions(void)
        {
            ATTN_SLOW(ENTER_MRK "AttnMemTest::testAttentions");

            static const uint64_t iterations = 1;
            static const uint64_t maxAttnsPerIteration = 1;

            errlHndl_t err = 0;

            Service svc;
            MemInjectSink sink;

            TargetHandleList membufs;

            getTargetService().getAllChips(
                    membufs,
                    TYPE_MEMBUF);

            RandSource source(
                    iterations,
                    maxAttnsPerIteration,
                    sink,
                    &membufs[0],
                    &membufs[0] + membufs.size());

            FakePrd prd(sink);

            prd.installPrd();

            do
            {
                err = svc.start();

                if(err)
                {
                    TS_FAIL("unexpected error starting service");
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

            } while(0);

            err = svc.stop();

            if(err)
            {
                TS_FAIL("unexpected error stopping service");

                delete err;
            }

            ATTN_SLOW(EXIT_MRK "AttnMemTest::testAttentions");
        }
};
#endif
