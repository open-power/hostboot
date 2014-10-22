/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_activate.C $                              */
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

#include <htmgt/htmgt.H>
#include <htmgt/htmgt_reasoncodes.H>
#include "htmgt_utility.H"
#include "htmgt_activate.H"
#include "htmgt_occcmd.H"
#include "htmgt_cfgdata.H"
#include "htmgt_poll.H"

//  Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>


namespace HTMGT
{

// TODO RTC 118875
#ifdef SIMICS_TESTING
    uint8_t * G_simicsHomerBuffer = NULL;
#endif


    // Send all config data to the OCCs
    // (see ToifNode::toif_manager_config() in src/tmgt/fsp/tmgt_toifnode.C)
    void sendOccConfigData()
    {
        TMGT_INF("sendOccConfigData: STUB");
        // TODO RTC 109066
    }



    // Wait for all OCCs to reach active ready state
    // (see ToifNode::wait_for_occ_ready() in tmgt_toifnode.C)
    errlHndl_t waitForOccReady()
    {
        errlHndl_t l_err = NULL;

        l_err = sendOccPoll();

        // TODO RTC 109066
        if (NULL == l_err)
        {
            TMGT_ERR("waitForOccReady: Stub forcing failure");
            /*@
             * @errortype
             * @reasoncode      HTMGT_RC_OCC_UNAVAILABLE
             * @moduleid        HTMGT_MOD_WAIT_FOR_OCC_READY
             * @devdesc         OCCs did not reach active ready state
             */
            bldErrLog(l_err, HTMGT_MOD_WAIT_FOR_OCC_READY,
                      HTMGT_RC_OCC_UNAVAILABLE,
                      0, 0, 0, 0,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        return l_err;
    }



    errlHndl_t setOccState(const occStateId i_state)
    {
        errlHndl_t l_err = NULL;

        TMGT_INF("setOccState: STUB");
        // TODO RTC 109066

        return l_err;
    }



    // Wait for all OCCs to reach active state
    errlHndl_t waitForOccsActive()
    {
        errlHndl_t l_err = NULL;

        TMGT_INF("wait_for_occs_active called");

        // Wait for attns - not needed?

        // Wait for all OCCs to be ready for active state
        l_err = waitForOccReady();
        if (NULL == l_err)
        {
            // Send Set State (ACTIVE) to master
            l_err = setOccState(OCC_STATE_ACTIVE);
            if (NULL == l_err)
            {
                TMGT_INF("waitForOccsActive: OCCs are all active");
            }
        }
        else
        {
            TMGT_ERR("waitForOccsActive: OCC(s) are not in active ready");
        }

        return l_err;

    } // end waitForOccsActive()



    // Set active sensors for all OCCs so BMC can start communication
    errlHndl_t setOccActiveSensors()
    {
        errlHndl_t l_err = NULL;

        TMGT_INF("setOccActiveSensors: STUB");
        // TODO RTC 109066

        return l_err;
    }



} // end namespace



