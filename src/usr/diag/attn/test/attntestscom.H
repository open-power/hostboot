/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attntestscom.H $                       */
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
#ifndef __TEST_ATTNTESTSCOM_H
#define __TEST_ATTNTESTSCOM_H

/**
 * @file attntestscom.H
 *
 * @brief Unit test for the attnscom module.
 */

#include "attnfakesys.H"
#include "attntest.H"
#include <cxxtest/TestSuite.H>

using namespace ATTN;
using namespace TARGETING;

/**
 * @brief AttnScomTest Unit test for the attnscom module.
 */
class AttnScomTest : public CxxTest::TestSuite
{
    public:

        /**
         * @brief testFakeScom Unit test for the
         *        getScom and putScom methods.
         */
        void testFakeScom(void)
        {
            static const uint64_t iterations = 100;
            static const uint64_t targetPoolSize = 100;
            static const TargetHandle_t targetPool = 0;

            TS_TRACE(ENTER_MRK "testFakeScom");

            errlHndl_t err = 0;

            FakeSystem d;
            d.installScomImpl();

            TargetHandle_t t;
            uint64_t data, address, exp;

            for(uint64_t i = 0; i < iterations; ++i)
            {
                t = targetPool + randint(0, targetPoolSize -1);
                data = randint(0, 0xffffffffffffffffull);
                address = randint(0, 0xffffffffffffffffull);
                exp = data;

                err = putScom(t, address, data);

                if(err)
                {
                    TS_FAIL("Unexpected error calling putScom");
                    break;
                }

                data = 0;

                err = getScom(t, address, data);

                if(err)
                {
                    TS_FAIL("Unexpected error calling getScom");
                    break;
                }

                if(data != exp)
                {
                    TS_FAIL("Unexpected data from getScom %d, %d",
                            data, exp);
                    break;
                }
            }

            TS_TRACE(EXIT_MRK "testFakeScom");
        }

        /**
         * @brief testModifyScom Unit test for the modify scom method.
         */
        void testModifyScom()
        {
            static const uint64_t iterations = 100;
            static const uint64_t targetPoolSize = 100;
            static const TargetHandle_t targetPool = 0;

            TS_TRACE(ENTER_MRK "testModifyScom");

            errlHndl_t err = 0;

            FakeSystem d;

            d.installScomImpl();

            uint64_t data, mask, exp, address, op;
            TargetHandle_t t;

            for(uint64_t i = 0; i<iterations; ++i)
            {
                t = targetPool + randint(0, targetPoolSize -1);
                mask = randint(0, 0xffffffffffffffffull);
                data = randint(0, 0xffffffffffffffffull);
                address = randint(0, 0xffffffffffffffffull);
                op = randint(0, 1);
                exp = op ? mask & data : mask | data;

                err = putScom(t, address, data);

                if(err)
                {
                    TS_FAIL("Unexpected error calling putScom");
                    break;
                }

                err = modifyScom(t, address, mask, op ? SCOM_AND : SCOM_OR);

                if(err)
                {
                    TS_FAIL("Unexpected error calling modifyScom");
                    break;
                }

                data = 0;

                err = getScom(t, address, data);

                if(err)
                {
                    TS_FAIL("Unexpected error calling getScom");
                    break;
                }

                if(data != exp)
                {
                    TS_FAIL("Unexpected data after modifyScom: 0x%.16x, 0x%.16x, 0x%.16x",
                            data, mask, exp);
                    break;
                }
            }

            TS_TRACE(EXIT_MRK "testModifyScom");
        }

        /**
         * @brief testSetDriver Unit test for the setDriver method.
         */
        void testSetDriver()
        {
            static const uint64_t targetPoolSize = 100;
            static const TargetHandle_t targetPool = 0;

            TS_TRACE(ENTER_MRK "testSetDriver");

            errlHndl_t err = 0;

            struct TestImpl : public ScomImpl
            {
                errlHndl_t putScom(TARGETING::TargetHandle_t i_target,
                        uint64_t i_address, uint64_t i_data)
                {
                    called = true;
                    return 0;
                }

                bool called;

                TestImpl() : called(false) {}
            } td;

            td.installScomImpl();

            TargetHandle_t target = targetPool + randint(0, targetPoolSize -1);
            uint64_t data = 0, address = 0;

            do {

                err = putScom(target, address,data);

                if(err)
                {
                    TS_FAIL("Unexpected error calling putScom");
                    break;
                }

                if(!td.called)
                {
                    TS_FAIL("Failed to set driver");
                    break;
                }

                td.called = false;

                FakeSystem d;
                d.installScomImpl();

                err = putScom(target, address,data);

                if(err)
                {
                    TS_FAIL("Unexpected error calling putScom");
                    break;
                }

                if(td.called)
                {
                    TS_FAIL("Failed to set driver");
                    break;
                }

            } while(0);

            TS_TRACE(EXIT_MRK "testSetDriver");
        }
};
#endif
