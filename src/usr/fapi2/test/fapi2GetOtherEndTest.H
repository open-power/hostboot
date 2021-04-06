/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetOtherEndTest.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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

#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <fapi2TestUtils.H>
#include <cxxtest/TestSuite.H>
#include <targeting/common/target.H>
#include <targeting/common/util.H>


namespace fapi2
{

class Fapi2GetOtherEndTest : public CxxTest::TestSuite
{
//@TODO RTC: 151173
// Need to verify that these tests work when we have multiple chips in simics

public:
//******************************************************************************
// test_fapi2GetOtherEnd
//******************************************************************************
void test_fapi2GetOtherEnd()
{
    int numTests = 0;
    int numFails = 0;

    do
    {
        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList chipListNonFunct;

        // Get a list of all of the iolink chiplets present
        TARGETING::getChipletResources(chipListNonFunct,
                                      TARGETING::TYPE_SMPGROUP,
                                      TARGETING::UTIL_FILTER_PRESENT_NON_FUNCTIONAL);

        FAPI_INF("list of present non-functional targets is size %d " , chipListNonFunct.size());
        TARGETING::Target * l_peerTarget = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_IOLINK> fapi2_iolinkTargetPeer;
        for(uint32_t i = 0; i < chipListNonFunct.size(); i++)
        {
            chipListNonFunct[i]->tryGetAttr<TARGETING::ATTR_PEER_TARGET>(l_peerTarget);
            const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>
                            fapi2_iolinkTargetPeerPlatform(l_peerTarget);
            const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>
                            fapi2_iolinkTarget(chipListNonFunct[i]);

            //Only check try to get the target's other end if the other end is present as well
            if(l_peerTarget && l_peerTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().present)
            {
                numTests++;
                if(fapi2_iolinkTarget.getOtherEnd<TARGET_TYPE_IOLINK>(fapi2_iolinkTargetPeer,TARGET_STATE_PRESENT) == FAPI2_RC_SUCCESS)
                {
                    if(fapi2_iolinkTargetPeerPlatform != fapi2_iolinkTargetPeer)
                    {
                        TS_FAIL("fapiGetOtherEnd::test 1 getOtherEnd returned the incorrect target! expected %x, instead got %x ", TARGETING::get_huid(l_peerTarget),  TARGETING::get_huid(fapi2_iolinkTargetPeer.get()));
                        numFails++;
                        break;
                    }
                }
                else
                {
                    TS_FAIL("fapiGetOtherEnd::test 1 getOtherEnd failed to return a target although it should have returned %x", TARGETING::get_huid(l_peerTarget));
                    numFails++;
                    break;
                }
            }
            else
            {
                FAPI_ERR("fapiGetOtherEnd::test 1 WARNING ! Target with HUID: %x has an unreachable peer target", chipListNonFunct[i]);
            }
        }

        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList chipListFunct;

        // Get a list of all of the iolink chiplets that are functional
        TARGETING::getAllChiplets(chipListFunct, TARGETING::TYPE_SMPGROUP, true);

        //NOTE: This Part of the test will fail if a certain target A's
        //      PEER_TARGET attr doesn't point to target B that
        //      has a PEER_TARGET that points back to target A
        //     So basically:
        //     A.PEER_TARGET MUST EQUAL B
        //     B.PEER_TARGET MUST EQUAL A

        FAPI_ERR("list of functional targets is size %d " , chipListFunct.size());

        for(uint32_t i = 0; i < chipListFunct.size(); i++)
        {
            chipListFunct[i]->tryGetAttr<TARGETING::ATTR_PEER_TARGET>(l_peerTarget);
            const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>
                    fapi2_iolinkTargetPeerPlatform(l_peerTarget);
            const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>
                    fapi2_iolinkTarget(chipListFunct[i]);

            if(l_peerTarget && l_peerTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
            {
                numTests++;
                if(fapi2_iolinkTarget.getOtherEnd<TARGET_TYPE_IOLINK>(fapi2_iolinkTargetPeer,TARGET_STATE_FUNCTIONAL) == FAPI2_RC_SUCCESS)
                {
                    if(fapi2_iolinkTargetPeerPlatform != fapi2_iolinkTargetPeer)
                    {
                        TS_FAIL("fapiGetOtherEnd::test 3 getOtherEnd returned the incorrect target! expected %x, instead got %x ", TARGETING::get_huid(l_peerTarget),  TARGETING::get_huid(fapi2_iolinkTargetPeer.get()));
                        numFails++;
                        break;
                    }
                }
                else
                {
                    TS_FAIL("fapiGetOtherEnd::test 3 getOtherEnd returned failed to return a target although it should have returned %x", TARGETING::get_huid(l_peerTarget));
                    numFails++;
                    break;
                }
            }
            else
            {
              FAPI_ERR("fapiGetOtherEnd::test 3 WARNING ! Target with HUID: %x has an unreachable or non-functional peer target", TARGETING::get_huid(chipListFunct[i]));
            }
        }

        FAPI_INF("fapi2GetOtherEndTest:: Test Complete. %d/%d fails", numFails, numTests);

    }while(0);

}

};

}
