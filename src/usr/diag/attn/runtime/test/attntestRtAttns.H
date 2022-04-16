/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/runtime/test/attntestRtAttns.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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
#ifndef __TEST_ATTNTESTRTATTNS_H
#define __TEST_ATTNTESTRTATTNS_H

/**
 * @file attntestRtAttns.H
 *
 * @brief Unit test for check for runtime attentions.
 */

#include "attnfakeprd.H"
#include "attnfakereg.H"
#include "../../common/attnproc.H"
#include <cxxtest/TestSuite.H>
#include "../../common/attntrace.H"
#include "../../common/attntarget.H"
#include <runtime/interface.h>
#include <targeting/runtime/rt_targeting.H>
#include <targeting/common/targetservice.H>

//See attn_rt.C
namespace ATTN_RT
{
    int handleAttns(uint64_t i_proc,
                    uint64_t i_ipollStatus,
                    uint64_t i_ipollMask);
}

using namespace ATTN;
using namespace TARGETING;
using namespace PRDF;

/**
 * @brief AttnCheckForRtAttentionsTest Unit test for the check for runtime
 *        attentions.
 */
class AttnCheckForRtAttentionsTest : public CxxTest::TestSuite
{
    public:

        /**
         * @brief testCheckForProcAttentions Unit test for the
         *              check for Proc Runtime attentions.
         */
        void testCheckForProcAttentions(void)
        {
            ATTN_SLOW(ENTER_MRK "AttnCheckForRtAttentionsTest::"
                                "testCheckForProcAttentions");

            FakePrd prd;
            prd.installPrd();
            FakeRegSvc fakeRegs;
            fakeRegs.installScomImpl();
            TargetHandle_t proc = NULL;
            do
            {
                TargetHandleList procList;
                getTargetService().getAllChips( procList, TYPE_PROC );
                // Get the first functional proc
                if( 0 == procList.size() )
                {
                    TS_FAIL("Not able to get Functional proc");
                    break;
                }
                proc = procList[0];

                TARGETING::rtChipId_t chipId = 0;
                errlHndl_t err = TARGETING::getRtTarget( proc, chipId );
                if( NULL != err )
                {
                    TS_FAIL("getRtTarget() failed for 0x%08X",
                             get_huid( proc ));
                    errlCommit(err, ATTN_COMP_ID);
                    break;
                }

                // Set the recoverable error
                putScom( proc, 0x570F001B, 1 );
                AttentionList expAttn;
                PRDF::AttnData attn (proc, RECOVERABLE);
                expAttn.add( Attention( attn,NULL));

                prd.setExpectedAttn( expAttn);

                // Check handle_attns runtime interface connection
                runtimeInterfaces_t * rt_intf = getRuntimeInterfaces();
                if( NULL == rt_intf )
                {
                    TS_FAIL("Not able to get run time interface object");
                    break;
                }
                else if (NULL == rt_intf->handle_attns)
                {
                    TS_FAIL("AttnCheckForRtAttentionsTest: handle_attns function pointer is not set");
                    break;
                }

                // handleAttns: do not use the runtime interface function
                int32_t rc = ATTN_RT::handleAttns(chipId, 0, 0);

                if( 0 != rc  )
                {
                    TS_FAIL("unexpected error during RT attention handling. "
                            "chipID: 0x%08X ", chipId);
                    break;
                }
            }while (0);

            ATTN_SLOW(EXIT_MRK "AttnCheckForRtAttentionsTest::"
                               "testCheckForProcAttentions");
        }
};
#endif
