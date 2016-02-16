/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetOtherEnd.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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


//******************************************************************************
// fapi2GetOtherEnd
//******************************************************************************
errlHndl_t fapi2GetOtherEnd()
{
    int numTests = 0;
    int numFails = 0;
    errlHndl_t l_errl = NULL;

    do
    {
        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList chipListNonFunct;

        // Get a list of all of the xbus chips present
        TARGETING::getAllChiplets(chipListNonFunct,
                                  TARGETING::TYPE_XBUS, false);
        TARGETING::Target * l_peerTarget;
        fapi2::Target<fapi2::TARGET_TYPE_XBUS> fapi2_xbusTargetPeer;
        for(uint32_t i = 0; i < chipListNonFunct.size(); i++)
        {
            chipListNonFunct[i]->
            tryGetAttr<TARGETING::ATTR_PEER_TARGET>(l_peerTarget);
            const fapi2::Target<fapi2::TARGET_TYPE_XBUS>
                            fapi2_xbusTargetPeerPlatform(l_peerTarget);
            const fapi2::Target<fapi2::TARGET_TYPE_XBUS>
                            fapi2_xbusTarget(chipListNonFunct[i]);
            if(l_peerTarget != NULL)
            {
                numTests++;
                if(fapi2_xbusTarget.getOtherEnd<TARGET_TYPE_XBUS>(fapi2_xbusTargetPeer,TARGET_STATE_PRESENT) == FAPI2_RC_SUCCESS)
                {
                    if(fapi2_xbusTargetPeerPlatform != fapi2_xbusTargetPeer)
                    {
                        TS_FAIL("fapiGetOtherEnd:: getOtherEnd returned the incorrect target! expected %x, instead got %x ", TARGETING::get_huid(l_peerTarget),  TARGETING::get_huid(static_cast<TARGETING::Target*>(fapi2_xbusTargetPeer)));
                        numFails++;
                        break;
                    }
                }
                else
                {
                    TS_FAIL("fapiGetOtherEnd:: getOtherEnd returned failed to return a target although it should have returned %x", TARGETING::get_huid(l_peerTarget));
                    numFails++;
                    break;
                }
            }
            else
            {
                FAPI_ERR("fapiGetOtherEnd:: WARNING ! Target with HUID: %x has an unreachable peer target", chipListNonFunct[i]);
            }
        }


        for(uint32_t i = 0; i < chipListNonFunct.size(); i++)
        {
            chipListNonFunct[i]->
            tryGetAttr<TARGETING::ATTR_PEER_TARGET>(l_peerTarget);
            const fapi2::Target<fapi2::TARGET_TYPE_XBUS>
                            fapi2_xbusTargetPeerPlatform(l_peerTarget);
            const fapi2::Target<fapi2::TARGET_TYPE_XBUS>
                            fapi2_xbusTarget(chipListNonFunct[i]);
            if(l_peerTarget != NULL)
            {
                numTests++;
                fapi2_xbusTargetPeer = fapi2_xbusTarget.getOtherEnd<TARGET_TYPE_XBUS>(TARGET_STATE_PRESENT);
                if(fapi2_xbusTargetPeer)
                {
                    if(fapi2_xbusTargetPeerPlatform != fapi2_xbusTargetPeer)
                    {
                        TS_FAIL("fapiGetOtherEnd:: getOtherEnd returned the incorrect target! expected %x, instead got %x ", TARGETING::get_huid(l_peerTarget),  TARGETING::get_huid(static_cast<TARGETING::Target*>(fapi2_xbusTargetPeer)));
                        numFails++;
                        break;
                    }
                }
                else
                {
                    TS_FAIL("fapiGetOtherEnd:: getOtherEnd returned failed to return a target although it should have returned %x", TARGETING::get_huid(l_peerTarget));
                    numFails++;
                    break;
                }
            }
            else
            {
              FAPI_ERR("fapiGetOtherEnd:: WARNING ! Target with HUID: %x has an unreachable peer target", chipListNonFunct[i]);
            }
        }

        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList chipListFunct;

        // Get a list of all of the xbus chips that are functional
        TARGETING::getAllChiplets(chipListFunct, TARGETING::TYPE_XBUS, true);

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
            const fapi2::Target<fapi2::TARGET_TYPE_XBUS>
                    fapi2_xbusTargetPeerPlatform(l_peerTarget);
            const fapi2::Target<fapi2::TARGET_TYPE_XBUS>
                    fapi2_xbusTarget(chipListFunct[i]);

            if(l_peerTarget != NULL)
            {
                numTests++;
                if(fapi2_xbusTarget.getOtherEnd<TARGET_TYPE_XBUS>(fapi2_xbusTargetPeer,TARGET_STATE_FUNCTIONAL) == FAPI2_RC_SUCCESS)
                {
                    if(fapi2_xbusTargetPeerPlatform != fapi2_xbusTargetPeer)
                    {
                        TS_FAIL("fapiGetOtherEnd:: getOtherEnd returned the incorrect target! expected %x, instead got %x ", TARGETING::get_huid(l_peerTarget),  TARGETING::get_huid(static_cast<TARGETING::Target*>(fapi2_xbusTargetPeer)));
                        numFails++;
                        break;
                    }
                }
                else
                {
                    TS_FAIL("fapiGetOtherEnd:: getOtherEnd returned failed to return a target although it should have returned %x", TARGETING::get_huid(l_peerTarget));
                    numFails++;
                    break;
                }
            }
            else
            {
              FAPI_ERR("fapiGetOtherEnd:: WARNING ! Target with HUID: %x has an unreachable peer target", TARGETING::get_huid(chipListFunct[i]));
            }
        }

        for(uint32_t i = 0; i < chipListFunct.size(); i++)
        {
            chipListFunct[i]->tryGetAttr<TARGETING::ATTR_PEER_TARGET>(l_peerTarget);
            const fapi2::Target<fapi2::TARGET_TYPE_XBUS>
                    fapi2_xbusTargetPeerPlatform(l_peerTarget);
            const fapi2::Target<fapi2::TARGET_TYPE_XBUS>
                    fapi2_xbusTarget(chipListFunct[i]);

            if(l_peerTarget != NULL)
            {
                numTests++;
                fapi2_xbusTargetPeer = fapi2_xbusTarget.getOtherEnd<TARGET_TYPE_XBUS>(TARGET_STATE_FUNCTIONAL);
                if(fapi2_xbusTargetPeer)
                {
                    if(fapi2_xbusTargetPeerPlatform != fapi2_xbusTargetPeer)
                    {
                        TS_FAIL("fapiGetOtherEnd:: getOtherEnd returned the incorrect target! expected %x, instead got %x ", TARGETING::get_huid(l_peerTarget),  TARGETING::get_huid(static_cast<TARGETING::Target*>(fapi2_xbusTargetPeer)));
                        numFails++;
                        break;
                    }
                }
                else
                {
                    TS_FAIL("fapiGetOtherEnd:: getOtherEnd returned failed to return a target although it should have returned %x", TARGETING::get_huid(l_peerTarget));
                    numFails++;
                    break;
                }
            }
            else
            {
              FAPI_ERR("fapiGetOtherEnd:: WARNING ! Target with HUID: %x has an unreachable peer target", TARGETING::get_huid(chipListFunct[i]));
            }
        }

        FAPI_INF("fapi2TargetTest:: Test Complete. %d/%d fails", numFails, numTests);

    }while(0);

    return l_errl;
}

}