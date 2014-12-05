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

#include <sys/time.h>

namespace HTMGT
{

// TODO RTC 118875
#ifdef SIMICS_TESTING
    uint8_t * G_simicsHomerBuffer = NULL;
#endif


    // Wait for all OCCs to reach active ready state
    errlHndl_t waitForOccReady()
    {
        errlHndl_t l_err = NULL;

        const uint8_t OCC_NONE = 0xFF;
        uint8_t waitingForInstance = OCC_NONE;
        const size_t MAX_POLL = 40;
        const size_t MSEC_BETWEEN_POLLS = 250;
        size_t numPolls = 0;
        std::vector<Occ*> occList = occMgr::instance().getOccArray();

        do
        {
            // Poll all OCCs
            l_err = sendOccPoll();
            ++numPolls;
            if (NULL != l_err)
            {
                TMGT_ERR("waitForOccReady: Poll #%d failed w/rc=0x%04X",
                         numPolls, l_err->reasonCode());
                break;
            }

            // Check each OCC for ready state
            waitingForInstance = OCC_NONE;
            for (std::vector<Occ*>::iterator itr = occList.begin();
                 (itr < occList.end());
                 ++itr)
            {
                Occ * occ = (*itr);
                if (false == occ->statusBitSet(OCC_STATUS_ACTIVE_READY))
                {
                    waitingForInstance = occ->getInstance();
                    break;
                }
            }

            if ((OCC_NONE != waitingForInstance) && (numPolls < MAX_POLL))
            {
                // Still waiting for at least one OCC, delay and try again
                nanosleep(0,  NS_PER_MSEC * MSEC_BETWEEN_POLLS);
            }
        } while ((OCC_NONE != waitingForInstance) && (numPolls < MAX_POLL));

        if ((OCC_NONE != waitingForInstance) && (NULL == l_err))
        {
            TMGT_ERR("waitForOccReady: OCC%d is not in ready state",
                     waitingForInstance);
            /*@
             * @errortype
             * @reasoncode HTMGT_RC_OCC_NOT_READY
             * @moduleid HTMGT_MOD_WAIT_FOR_OCC_READY
             * @userdata1[0-15] OCC instance
             * @userdata1[16-31] poll attempts
             * @devdesc OCC not ready for active state
             */
            bldErrLog(l_err, HTMGT_MOD_WAIT_FOR_OCC_READY,
                      HTMGT_RC_OCC_NOT_READY,
                      waitingForInstance, numPolls, 0, 0,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        return l_err;

    } // end waitForOccReady()



    // Wait for all OCCs to reach active state
    errlHndl_t waitForOccsActive()
    {
        errlHndl_t l_err = NULL;

        TMGT_INF("wait_for_occs_active called");

        // Wait for all OCCs to be ready for active state
        l_err = waitForOccReady();
        if (NULL == l_err)
        {
            // Send Set State (ACTIVE) to master
            l_err = occMgr::instance().setOccState(OCC_STATE_ACTIVE);
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
        // TODO RTC 119073

        return l_err;
    }



} // end namespace



