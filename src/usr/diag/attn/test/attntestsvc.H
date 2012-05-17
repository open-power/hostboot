//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/attn/test/attntestsvc.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __TEST_ATTNTESTSVC_H
#define __TEST_ATTNTESTSVC_H

/**
 * @file attntestsvc.H
 *
 * @brief Unit test for the attnsvc module.
 */

#include "../attnfwd.H"
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
            TS_TRACE(ENTER_MRK "testAttentions");

            errlHndl_t err = 0;

            FakeSystem hooks;
            Service svc;

            hooks.install();

            do
            {
                err = svc.start();

                if(err)
                {
                    TS_FAIL("unexpected error starting service");
                    break;
                }

                static const int64_t iterations = 20;

                for(int64_t it = 0; it < iterations; ++it)
                {
                    int64_t count = randint(1, 10);

                    TS_TRACE("raising %d attentions", count);

                    hooks.raiseAttentions(svc.iv_intrTaskQ, count);
                }

                err = svc.stop();

                if(err)
                {
                    TS_FAIL("unexpected error stopping service");
                    break;
                }

                if(!hooks.validate())
                {
                    TS_FAIL("unexpected result after injecting attentions");
                    break;
                }

            } while(0);

            TS_TRACE(EXIT_MRK "testAttentions");
        }
};
#endif
