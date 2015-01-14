/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_occ.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
#include "htmgt_occcmd.H"
#include "htmgt_cfgdata.H"
#include "htmgt_occ.H"
#include "htmgt_poll.H"

#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <console/consoleif.H>


namespace HTMGT
{

    Occ::Occ(const uint8_t   i_instance,
             const bool      i_masterCapable,
             uint8_t       * i_homer,
             TARGETING::TargetHandle_t i_target,
             const occRole   i_role)
        :iv_instance(i_instance),
        iv_masterCapable(i_masterCapable),
        iv_role(i_role),
        iv_state(OCC_STATE_UNKNOWN),
        iv_commEstablished(false),
        iv_needsReset(false),
        iv_failed(false),
        iv_seqNumber(0),
        iv_homer(i_homer),
        iv_target(i_target),
        iv_lastPollValid(false),
        iv_version(0x01)
    {
    }

    Occ::~Occ()
    {
    }


    // Return true if specified status bit is set in last poll response
    bool Occ::statusBitSet(const uint8_t i_statusBit)
    {
        bool isSet = false;

        if (iv_lastPollValid)
        {
            const occPollRspStruct_t *lastPoll =
                (occPollRspStruct_t*)iv_lastPollResponse;
            isSet = ((lastPoll->status & i_statusBit) == i_statusBit);
        }

        return isSet;
    }


    // Set state of the OCC
    errlHndl_t Occ::setState(const occStateId i_state)
    {
        errlHndl_t l_err = NULL;

        if (OCC_ROLE_MASTER == iv_role)
        {
            const uint8_t l_cmdData[3] =
            {
                0x00, // version
                i_state,
                0x00 // reserved
            };

            OccCmd cmd(this, OCC_CMD_SET_STATE,
                       sizeof(l_cmdData), l_cmdData);
            l_err = cmd.sendOccCmd();
            if (l_err != NULL)
            {
                TMGT_ERR("setState: Failed to set OCC%d state, rc=0x%04X",
                         iv_instance, l_err->reasonCode());
            }
            else
            {
                if (OCC_RC_SUCCESS != cmd.getRspStatus())
                {
                    TMGT_ERR("setState: Set OCC%d state failed"
                             " with OCC status 0x%02X",
                             iv_instance, cmd.getRspStatus());
                    /*@
                     * @errortype
                     * @moduleid HTMGT_MOD_OCC_SET_STATE
                     * @reasoncode HTMGT_RC_OCC_CMD_FAIL
                     * @userdata1[0-15] OCC instance
                     * @userdata1[16-31] Requested state
                     * @userdata2[0-15] OCC response status
                     * @userdata2[16-31] current OCC state
                     * @devdesc Set of OCC state failed
                     */
                    bldErrLog(l_err, HTMGT_MOD_OCC_SET_STATE,
                              HTMGT_RC_OCC_CMD_FAIL,
                              iv_instance, i_state,
                              cmd.getRspStatus(), iv_state,
                              ERRORLOG::ERRL_SEV_INFORMATIONAL);
                }
            }
        }
        else
        {
            TMGT_ERR("setState: State only allowed to be set on master OCC");
            /*@
             * @errortype
             * @moduleid HTMGT_MOD_OCC_SET_STATE
             * @reasoncode HTMGT_RC_INTERNAL_ERROR
             * @userdata1[0-15] OCC instance
             * @userdata1[16-31] Requested state
             * @devdesc Set state only allowed on master OCC
             */
            bldErrLog(l_err, HTMGT_MOD_OCC_SET_STATE,
                      HTMGT_RC_INTERNAL_ERROR,
                      iv_instance, i_state, 0, 0,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        return l_err;

    } // end Occ::setState()



    /////////////////////////////////////////////////////////////////



    OccManager::OccManager()
        :iv_configDataBuilt(false),
        iv_occMaster(NULL),
        iv_state(OCC_STATE_UNKNOWN),
        iv_targetState(OCC_STATE_ACTIVE)
    {
    }


    OccManager::~OccManager()
    {
    }


    // Remove all OCC objects
    void OccManager::_removeAllOccs()
    {
        iv_occMaster = NULL;
        if (iv_occArray.size() > 0)
        {
            for (std::vector<Occ*>::iterator pOcc = iv_occArray.begin();
                 pOcc < iv_occArray.end();
                 pOcc++)
            {
                TMGT_INF("removeAllOccs: Removing OCC%d",
                         (*pOcc)->getInstance());
                delete (*pOcc);
            }
            iv_occArray.clear();
        }
    }


    // Query the functional OCCs and build OCC objects
    uint32_t OccManager::_buildOccs()
    {
        TMGT_INF("buildOccs called");

        // Remove existing OCC objects
        _removeAllOccs();

        // Get all functional processors
        TARGETING::TargetHandleList pProcs;
        TARGETING::getChipResources(pProcs,
                                    TARGETING::TYPE_PROC,
                                    TARGETING::UTIL_FILTER_FUNCTIONAL);
        if (pProcs.size() > 0)
        {
            // for each functional processor
            for(TARGETING::TargetHandleList::iterator proc = pProcs.begin();
                proc != pProcs.end();
                ++proc)
            {
                // Instance number for this Processor/OCC
                const uint8_t instance =
                    (*proc)->getAttr<TARGETING::ATTR_POSITION>();
                TMGT_INF("buildOccs: PROC%d is functional", instance);
                // Get HOMER virtual address
                uint8_t * homer = (uint8_t*)
                    ((*proc)->getAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>());
                const uint8_t * homerPhys = (uint8_t*)
                    ((*proc)->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>());
                TMGT_INF("buildOccs: homer = 0x%08X (virt) / 0x%08X (phys)"
                         " for Proc%d", homer, homerPhys, instance);
#ifdef SIMICS_TESTING
                // Starting of OCCs is not supported in SIMICS, so fake out
                // HOMER memory area for testing
                if (NULL == homer)
                {
                    extern uint8_t * G_simicsHomerBuffer;

                    if (NULL == G_simicsHomerBuffer)
                    {
                        // Allocate a fake HOMER area
                        G_simicsHomerBuffer =
                            new uint8_t [OCC_CMD_ADDR+0x2000];
                    }
                    homer = G_simicsHomerBuffer;
                    TMGT_ERR("buildOccs: Using hardcoded HOMER of 0x%08lX",
                             homer);
                }
#endif

                // Get functional OCC (one per proc)
                TARGETING::TargetHandleList pOccs;
                getChildChiplets(pOccs, *proc, TARGETING::TYPE_OCC);
                if (pOccs.size() > 0)
                {
                    const unsigned long huid =
                        pOccs[0]->getAttr<TARGETING::ATTR_HUID>();
                    const bool masterCapable =
                        pOccs[0]->getAttr<TARGETING::ATTR_OCC_MASTER_CAPABLE>();

                    TMGT_INF("Found OCC %d - HUID: 0x%0lX, masterCapable: %c,"
                             " homer: 0x%0lX",
                             instance, huid, masterCapable?'Y':'N', homer);
                    _addOcc(instance, masterCapable, homer, pOccs[0]);
                }
                else
                {
                    // OCC must not be functional
                    TMGT_ERR("OCC%d not functional", instance);
                }
            }
        }
        else
        {
            TMGT_ERR("No functional processors found");
        }

        TMGT_INF("buildOccs: OCC Targets found = %d", _getNumOccs());

        return _getNumOccs();

    } // end OccManager::_buildOccs()



    // Add a functional OCC to be monitored
    void OccManager::_addOcc(const uint8_t   i_instance,
                             const bool      i_masterCapable,
                             uint8_t       * i_homer,
                             TARGETING::TargetHandle_t i_target)
    {
        TMGT_INF("addOcc(%d, masterCapable=%c)",
                 i_instance, i_masterCapable?'y':'n');

        occRole role = OCC_ROLE_SLAVE;
        if (true == i_masterCapable)
        {
            if (NULL == iv_occMaster)
            {
                // No master assigned yet, use this OCC
                TMGT_INF("addOcc: OCC%d will be the master", i_instance);
                role = OCC_ROLE_MASTER;
            }
            else
            {
                role = OCC_ROLE_BACKUP_MASTER;
            }
        }

        Occ * l_occ = new Occ(i_instance,
                              i_masterCapable,
                              i_homer,
                              i_target,
                              role);

        // Add OCC to the array
        iv_occArray.push_back(l_occ);

        if (OCC_ROLE_MASTER == role)
        {
            iv_occMaster = l_occ;
        }

    } // end OccManager::_addOcc()


    // Set the OCC state
    errlHndl_t OccManager::_setOccState(const occStateId i_state)
    {
        errlHndl_t l_err = NULL;

        occStateId requestedState = i_state;
        if (OCC_STATE_NO_CHANGE == i_state)
        {
            // If no state was requested use the target state
            requestedState = iv_targetState;
        }

        if ((requestedState == OCC_STATE_ACTIVE) ||
            (requestedState == OCC_STATE_OBSERVATION))
        {
            // Function is only called on initial IPL and when user/mfg
            // requests a new state, so we can update target here.
            iv_targetState = requestedState;

            if (NULL != iv_occMaster)
            {
                TMGT_INF("_setOccState(state=0x%02X)", requestedState);

                const uint8_t occInstance = iv_occMaster->getInstance();
                bool needsRetry = false;
                do
                {
                    l_err = iv_occMaster->setState(requestedState);
                    if (NULL == l_err)
                    {
                        needsRetry = false;
                    }
                    else
                    {
                        TMGT_ERR("_setOccState: Failed to set OCC%d state,"
                                 " rc=0x%04X",
                                 occInstance, l_err->reasonCode());
                        if (false == needsRetry)
                        {
                            ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                            l_err = NULL;
                            needsRetry = true;
                        }
                        else
                        {
                            // Only one retry, return error handle
                            needsRetry = false;
                        }
                    }
                }
                while (needsRetry);
            }
            else
            {
                /*@
                 * @errortype
                 * @moduleid HTMGT_MOD_OCCMGR_SET_STATE
                 * @reasoncode HTMGT_RC_INTERNAL_ERROR
                 * @devdesc Unable to set state of master OCC
                 */
                bldErrLog(l_err, HTMGT_MOD_OCCMGR_SET_STATE,
                          HTMGT_RC_INTERNAL_ERROR,
                          0, 0, 0, 0,
                          ERRORLOG::ERRL_SEV_INFORMATIONAL);
            }

            if (NULL == l_err)
            {
                // Send poll to query state of all OCCs
                // and flush any errors reported by the OCCs
                l_err = sendOccPoll(true);
                if (l_err)
                {
                    TMGT_ERR("_setOccState: Poll all OCCs failed");
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    l_err = NULL;
                }

                // Make sure all OCCs went to active state
                for (std::vector<Occ*>::iterator pOcc = iv_occArray.begin();
                     pOcc < iv_occArray.end();
                     pOcc++)
                {
                    if (requestedState != (*pOcc)->getState())
                    {
                        TMGT_ERR("_setOccState: OCC%d is not in 0x%02X state",
                                 (*pOcc)->getInstance(), requestedState);
                        /*@
                         * @errortype
                         * @moduleid HTMGT_MOD_OCCMGR_SET_STATE
                         * @reasoncode HTMGT_RC_OCC_UNEXPECTED_STATE
                         * @userdata1[0-15] requested state
                         * @userdata1[16-31] OCC state
                         * @userdata2[0-15] OCC instance
                         * @devdesc OCC did not change to requested state
                         */
                        bldErrLog(l_err, HTMGT_MOD_OCCMGR_SET_STATE,
                                  HTMGT_RC_OCC_UNEXPECTED_STATE,
                                  requestedState, (*pOcc)->getState(),
                                  (*pOcc)->getInstance(), 0,
                                  ERRORLOG::ERRL_SEV_INFORMATIONAL);
                        break;
                    }
                }

                if (NULL == l_err)
                {
                    TMGT_INF("_setOccState: All OCCs have reached state 0x%02X",
                             requestedState);

#ifndef __HOSTBOOT_RUNTIME
                    if (OCC_STATE_ACTIVE == requestedState)
                    {
                        CONSOLE::displayf(HTMGT_COMP_NAME,
                               "OCCs are now running in ACTIVE state");
                    }
                    else
                    {
                        CONSOLE::displayf(HTMGT_COMP_NAME,
                               "OCCs are now running in OBSERVATION state");
                    }
#endif
                }

            }
        }
        else
        {
            TMGT_ERR("_setOccState: Invalid state 0x%02X requested",
                     requestedState);
            /*@
             * @errortype
             * @moduleid HTMGT_MOD_OCCMGR_SET_STATE
             * @reasoncode HTMGT_RC_INVALID_DATA
             * @userdata1[0-15] requested state
             * @devdesc Invalid OCC state requested
             */
            bldErrLog(l_err, HTMGT_MOD_OCCMGR_SET_STATE,
                      HTMGT_RC_INVALID_DATA,
                      requestedState, 0, 0, 0,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        return l_err;

    } // end OccManager::_setOccState()


    uint8_t  OccManager::getNumOccs()
    {
        return Singleton<OccManager>::instance()._getNumOccs();
    }


    std::vector<Occ*> OccManager::getOccArray()
    {
        return Singleton<OccManager>::instance()._getOccArray();
    }


    uint32_t OccManager::buildOccs()
    {
        return Singleton<OccManager>::instance()._buildOccs();
    }


    Occ * OccManager::getMasterOcc()
    {
        return Singleton<OccManager>::instance()._getMasterOcc();
    }


    errlHndl_t OccManager::setOccState(const occStateId i_state)
    {
        return Singleton<OccManager>::instance()._setOccState(i_state);
    }


    occStateId OccManager::getTargetState()
    {
        return Singleton<OccManager>::instance()._getTargetState();
    }


#if 0
    // TODO: RTC 115296
    void update_occ_data()
    {
        if (occMgr::instance().getNumOccs() > 0)
        {
            // TBD: define as one block of data or in each OCC target?

            uint32_t dataSize = occMgr::instance().getNumOccs() *
                sizeof(occInstance);
            if (dataSize > 256)
            {
                TMGT_ERR("update_occ_data: data exceeds attr size, truncating");
                dataSize = 256;
            }
            // Update OCC_CONTROL_DATA Attribute
            bool success = ->trySetAttr<ATTR_OCC_CONTROL_DATA>(dataSize, G_occ);
            if (false == success)
            {
                TMGT_ERR("update_occ_data: failed to update OCC_CONTROL_DATA");
            }
        }
        else
        {
            TMGT_INF("update_occ_data: No OCC data to update");
        }
    } // end update_occ_data()
#endif


} // end namespace



