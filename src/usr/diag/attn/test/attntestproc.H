/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attntestproc.H $
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
#ifndef __TEST_ATTNTESTPROC_H
#define __TEST_ATTNTESTPROC_H

/**
 * @file attntestproc.H
 *
 * @brief Unit test for the attnproc module.
 */

#include "../attnproc.H"
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
         * @brief testMask Unit test for the
         *        mask method.
         */
        void testMask(void)
        {
            TS_TRACE(ENTER_MRK "testMask");

            static const uint64_t iterations = 100;
            static const uint64_t targetPoolSize = 8;

            errlHndl_t err = 0;

            ProcOps ops;
            AttnData d;

            FakeProcTargetService targetSvc(targetPoolSize);
            FakeSystem system;

            TargetHandleList procs;

            targetSvc.getAllChips(procs, TYPE_PROC);

            system.installScomImpl();

            for(uint64_t it = 0; it < iterations; ++it)
            {
                d.targetHndl = *(&procs[0] + randint(0, targetPoolSize -1));
                d.attnType = getRandomAttentionType();

                // put some random data in the mask register

                uint64_t randomData = randint(0, 0xffffffffffffffffull);
                uint64_t maskbits = 0;

                if(!IPOLL::getCheckbits(d.attnType, maskbits))
                {
                    TS_FAIL("unexpected error calling getCheckbits");
                    break;
                }

                randomData = randomData & ~maskbits;

                err = putScom(
                        d.targetHndl,
                        IPOLL::address,
                        randomData);
                if(err)
                {
                    TS_FAIL("unexpected error calling putscom");
                    break;
                }

                err = ops.mask(d);

                if(err)
                {
                    TS_FAIL("unexpected error masking attention");
                    break;
                }

                uint64_t data = 0;
                err = getScom(d.targetHndl, IPOLL::address, data);
                if(err)
                {
                    TS_FAIL("unexpected error calling getscom");
                    break;
                }

                // verify that the attn was masked, and that
                // other bits weren't touched

                if(!(data & maskbits))
                {
                    TS_FAIL("attention not masked");
                    break;
                }

                if((data & ~maskbits) != randomData)
                {
                    TS_FAIL("unexpected data in mask register");
                    break;
                }

                // clean up by unmasking

                err = ops.unmask(d);

                if(err)
                {
                    TS_FAIL("unexpected error unmasking attention");
                    break;
                }
            }

            TS_TRACE(EXIT_MRK "testMask");
        }

        /**
         * @brief testUnmask Unit test for the
         *        unmask method.
         */
        void testUnmask(void)
        {
            TS_TRACE(ENTER_MRK "testUnmask");

            static const uint64_t iterations = 100;
            static const uint64_t targetPoolSize = 8;

            errlHndl_t err = 0;

            ProcOps ops;
            AttnData d;

            FakeProcTargetService targetSvc(targetPoolSize);
            FakeSystem system;

            TargetHandleList procs;

            targetSvc.getAllChips(procs, TYPE_PROC);

            system.installScomImpl();

            for(uint64_t it = 0; it < iterations; ++it)
            {
                d.targetHndl = *(&procs[0] + randint(0, targetPoolSize -1));
                d.attnType = getRandomAttentionType();

                // mask first

                err = ops.mask(d);

                if(err)
                {
                    TS_FAIL("unexpected error masking attention");
                    break;
                }

                // put some random data in the mask register

                uint64_t randomData = randint(0, 0xffffffffffffffffull);
                uint64_t maskbits = 0;

                if(!IPOLL::getCheckbits(d.attnType, maskbits))
                {
                    TS_FAIL("unexpected error calling getCheckbits");
                    break;
                }

                randomData = randomData | maskbits;

                err = putScom(d.targetHndl, IPOLL::address, randomData);
                if(err)
                {
                    TS_FAIL("unexpected error calling putscom");
                    break;
                }

                err = ops.unmask(d);

                if(err)
                {
                    TS_FAIL("unexpected error masking attention");
                    break;
                }

                uint64_t data = 0;
                err = getScom(d.targetHndl, IPOLL::address, data);
                if(err)
                {
                    TS_FAIL("unexpected error calling getscom");
                    break;
                }

                // verify that the attn was unmasked, and that
                // other bits weren't touched

                if(!(~data & maskbits))
                {
                    TS_FAIL("attention not unmasked");
                    break;
                }

                if((data | maskbits) != randomData)
                {
                    TS_FAIL("unexpected data in mask register");
                    break;
                }
            }

            TS_TRACE(EXIT_MRK "testUnmask");
        }

        /**
         * @brief testQuery Unit test for the
         *        query method.
         */
        void testQuery(void)
        {
            static const uint64_t iterations = 100;
            static const uint64_t targetPoolSize = 8;

            TS_TRACE(ENTER_MRK "testQuery");

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

            TS_TRACE(EXIT_MRK "testQuery");
        }

        /**
         * @brief testFakeAttentions Unit test for the
         *        attnproc module.
         */
        void testFakeAttentions()
        {
            static const uint64_t targetPoolSize = 8;
            static const uint64_t iterations = 5;
            static const uint64_t maxAttnsPerIteration = 5;

            TS_TRACE(ENTER_MRK "testFakeAttentions");

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

            TS_TRACE(EXIT_MRK "testFakeAttentions");
        }
};
#endif
