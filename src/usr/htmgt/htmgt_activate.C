/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_activate.C $                              */
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

#include <htmgt/htmgt.H>
#include <htmgt/htmgt_reasoncodes.H>
#include "htmgt_utility.H"
#include "htmgt_activate.H"
#include "htmgt_occcmd.H"
#include "htmgt_cfgdata.H"
#include "htmgt_poll.H"
#include "htmgt_occmanager.H"

//  Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <isteps/pm/scopedHomerMapper.H>

#include <sys/time.h>
#include <console/consoleif.H>

#ifdef CONFIG_PLDM
#include <pldm/base/hb_bios_attrs.H>
#include <pldm/pldm_errl.H>
#endif

using namespace TARGETING;

namespace HTMGT
{

#define BMC_LIMIT_WAS_READ 0xFF000000

    // Wait for all OCCs to reach ready state
    errlHndl_t waitForOccReady()
    {
        errlHndl_t l_err = NULL;

        const uint8_t OCC_NONE = 0xFF;
        uint8_t waitingForInstance = OCC_NONE;
        const size_t MAX_POLL = 40;
        const size_t MSEC_BETWEEN_POLLS = 250;
        size_t numPolls = 0;
        std::vector<Occ*> occList = OccManager::getOccArray();

        // Determine which bit to check
        uint8_t targetBit = OCC_STATUS_ACTIVE_READY;
        if (OCC_STATE_OBSERVATION == OccManager::getTargetState())
        {
            targetBit = OCC_STATUS_OBS_READY;
        }

        do
        {
            // Poll all OCCs
            l_err = OccManager::sendOccPoll();
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
                if (false == occ->statusBitSet(targetBit))
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
             * @userdata1[0:15] OCC instance
             * @userdata1[16:31] poll attempts
             * @userdata2[0:15] target ready bit
             * @devdesc OCC not ready for target state
             * @custdesc An internal firmware error occurred
             */
            bldErrLog(l_err, HTMGT_MOD_WAIT_FOR_OCC_READY,
                      HTMGT_RC_OCC_NOT_READY,
                      waitingForInstance, numPolls, targetBit, 0,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        return l_err;

    } // end waitForOccReady()



    // Wait for all OCCs to reach target state
    errlHndl_t waitForOccState()
    {
        errlHndl_t l_err = NULL;

        // Wait for all OCCs to be ready for active state
        l_err = waitForOccReady();
        if (NULL == l_err)
        {
            // Send Set State command to master OCC.
            // The master will use the target state (default = ACTIVE)
            l_err = OccManager::setOccState();
        }

        return l_err;

    } // end waitForOccState()



    // Set enabled sensors for all OCCs to allow BMC to OCC communication
    errlHndl_t setOccEnabledSensors(bool i_enabled)
    {
        errlHndl_t l_err = NULL;

        TMGT_INF("setOccEnabledSensors: %s", i_enabled?"enabled":"disabled");
        std::vector<Occ*> occList = OccManager::getOccArray();
        for (std::vector<Occ*>::iterator itr = occList.begin();
             (itr < occList.end());
             ++itr)
        {
            Occ * occ = (*itr);
            l_err = occ->bmcSensor(i_enabled);
            if( l_err )
            {
                TMGT_ERR("setOccEnabledSensors failed. (OCC%d state:%d)",
                         occ->getInstance(),
                         i_enabled);

                TMGT_CONSOLE("setOccEnabledSensors failed. (OCC%d state:%d)",
                         occ->getInstance(),
                         i_enabled);

                l_err->collectTrace(HTMGT_COMP_NAME);
                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
            }
        }

        // Set internal flag indicating if the OCCs are running
        OccManager::setOccsAreRunning(i_enabled);

        return l_err;
    }


    //Sends the user selected power limit to the master OCC
    errlHndl_t sendOccUserPowerCap()
    {
        errlHndl_t err = NULL;
        Target* sys = NULL;
        bool active = false;
        uint16_t limit = 0;
        uint16_t min = 0;
        uint16_t max = 0;
        targetService().getTopLevelTarget(sys);
        assert(sys != NULL);

        do
        {

// TODO: RTC 209572 Support power caps based on power supply type
#ifdef CONFIG_PLDM
            err = PLDM::getPowerLimit(active, limit);
            if(err)
            {
                TMGT_ERR("getPowerLimit: An error occurred getting Power Limit from the BMC");
                err->collectTrace(HTMGT_COMP_NAME);
                break;
            }
            else
            {
                TMGT_INF("getPowerLimit: active=%c, limit=%dW", active?'y':'n', limit);
            }
#endif

            if (active)
            {
                //Make sure this value is between the min & max allowed
                bool is_redundant;
                min = sys->getAttr<ATTR_SOFT_MIN_POWER_CAP_WATTS>();
                max = getMaxPowerCap(sys, is_redundant);
                if ((limit != 0) && (limit < min))
                {
                    TMGT_INF("sendOccUserPowerCap:  User power cap %dW is below"
                             " the minimum of %d, clipping value",
                             limit, min);
                    limit = min;
                }
                else if (limit > max)
                {
                    TMGT_INF("sendOccUserPowerCap:  User power cap %dW is above"
                             " the maximum of %d, clipping value",
                             limit, min);
                    limit = max;
                }
                else if (limit == 0)
                {
                    TMGT_ERR("sendOccUserPowerCap: BMC is reporting that user "
                             "cap is enabled, but the value is 0W!");
                    active = false;
                }
            }
            else
            {
                //The OCC knows cap isn't active by getting a value of 0.
                limit = 0;
            }


            Occ* occ = occMgr::instance().getMasterOcc();
            if (occ)
            {
                // MAP HOMER for this OCC
                TARGETING::Target* procTarget = nullptr;
                procTarget = TARGETING::getImmediateParentByAffinity(occ->getTarget());
                HBPM::ScopedHomerMapper l_mapper(procTarget);
                err = l_mapper.map();
                if (err)
                {
                    TMGT_ERR("sendOccUserPowerCap: Unable to get HOMER virtual address for Master OCC (rc=0x%04X)",
                             err->reasonCode());
                    err->collectTrace(HTMGT_COMP_NAME);
                    break;
                }
                occ->setHomerAddr(l_mapper.getHomerVirtAddr());

                uint8_t data[2];
                data[0] = limit >> 8;
                data[1] = limit & 0xFF;

                TMGT_INF("sendOccUserPowerCap: Sending power cap %dW to OCC%d",
                         limit, occ->getInstance());
                if (limit > 0)
                {
                    TMGT_CONSOLE("User power limit has been set to %dW",
                                 limit);
                }

                OccCmd cmd(occ, OCC_CMD_SET_POWER_CAP, 2, data);

                err = cmd.sendOccCmd();
                if (err)
                {
                    TMGT_ERR("sendOccUserPowerCap: Failed sending command "
                             "to OCC%d with rc=0x%04X",
                             occ->getInstance(), err->reasonCode());
                    occ->invalidateHomer();
                    break;
                }
                occ->invalidateHomer();
            }
            else
            {
                //Other code deals with a missing master
                TMGT_ERR("sendOccUserPowerCap: No Master OCC found");
            }

        } while (0);

        return err;
    }

} // end namespace



