/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_occ.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
#include <sys/time.h>
#include <ecmdDataBufferBase.H>
#include <hwpf/hwp/occ/occAccess.H>
#include <hwpf/hwp/occ/occ.H>
#include <hwpf/hwp/occ/occ_common.H>
#include <errl/errludlogregister.H>

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
        iv_occsPresent(1 << i_instance),
        iv_resetReason(OCC_RESET_REASON_NONE),
        iv_exceptionLogged(0),
        iv_resetCount(0),
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
                     * @userdata1[0-31] OCC instance
                     * @userdata1[32-63] Requested state
                     * @userdata2[0-31] OCC response status
                     * @userdata2[32-63] current OCC state
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
             * @userdata1  OCC instance
             * @userdata2  Requested state
             * @devdesc Set state only allowed on master OCC
             */
            bldErrLog(l_err, HTMGT_MOD_OCC_SET_STATE,
                      HTMGT_RC_INTERNAL_ERROR,
                      0, iv_instance, 0, i_state,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        return l_err;

    } // end Occ::setState()


    // Update master occsPresent bits for poll rsp validataion
    void Occ::updateOccPresentBits(uint8_t i_slavePresent)
    {
        if (iv_occsPresent & i_slavePresent)
        {
            // Flag error because multiple OCCs have same chip ID
            TMGT_ERR("updateOccPresentBits: slave 0x%02X already "
                     "exists (0x%02X)",
                     i_slavePresent, iv_occsPresent);
            iv_needsReset = true;
        }
        else
        {
            iv_occsPresent |= i_slavePresent;
        }
    };


    // Reset OCC
    bool Occ::resetPrep()
    {
        errlHndl_t err = NULL;
        bool atThreshold = false;

        // Send resetPrep command
        uint8_t cmdData[2];
        cmdData[0] = OCC_RESET_CMD_VERSION;

        TMGT_INF("resetPrep: OCC%d (failed=%c, reset count=%d)",
                 iv_instance, iv_failed?'y':'n', iv_resetCount);
        if(iv_failed)
        {
            cmdData[1] = OCC_RESET_FAIL_THIS_OCC;
            ++iv_resetCount;
            TMGT_INF("resetPrep: OCC%d failed, incrementing reset count to %d",
                     iv_instance, iv_resetCount);
            if(iv_resetCount > OCC_RESET_COUNT_THRESHOLD)
            {
                atThreshold = true;
            }
        }
        else
        {
            cmdData[1] = OCC_RESET_FAIL_OTHER_OCC;
        }

        OccCmd cmd(this, OCC_CMD_RESET_PREP, sizeof(cmdData), cmdData);
        err = cmd.sendOccCmd();
        if(err)
        {
            // log error and keep going
            TMGT_ERR("OCC::resetPrep: OCC%d resetPrep failed with rc = 0x%04x",
                     iv_instance,
                     err->reasonCode());

            ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
        }

        // poll and flush error logs from OCC - Check Ex return code
        err = pollForErrors(true);
        if(err)
        {
            ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
        }

        return atThreshold;
    }


    void Occ::postResetClear()
    {
        iv_state = OCC_STATE_UNKNOWN;
        iv_commEstablished = false;
        iv_needsReset = false;
        iv_failed = false;
        iv_lastPollValid = false;
        iv_resetReason = OCC_RESET_REASON_NONE;
        iv_exceptionLogged = 0;
    }


    // Add channel 1 (circular buffer) SCOM data to elog
    void Occ::collectCheckpointScomData(errlHndl_t i_err)
    {
        if (i_err)
        {
            TARGETING::ConstTargetHandle_t procTarget =
                TARGETING::getParentChip(iv_target);
            ERRORLOG::ErrlUserDetailsLogRegister l_scom_data(procTarget);
            // Grab circular buffer scom data: (channel 1)
            //0006B031  OCBCSR1 (Control/Status [1]  Register)
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6B031));
            //0006A211  OCBSLCS1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6A211));
            //0006A214  OCBSHCS1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6A214));
            //0006A216  OCBSES1 (Indicates error that occur in an indirect ch)
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6A216));
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6A210));
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6A213));
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6A217));
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6B034));
            l_scom_data.addToLog(i_err);
        }
        else
        {
            TMGT_ERR("collectCheckpointScomData: No error "
                     "handle supplied for OCC%d", iv_instance);
        }
    } // end Occ::collectCheckpointScomData()



    /////////////////////////////////////////////////////////////////


    uint32_t OccManager::cv_safeReturnCode = 0;
    uint32_t OccManager::cv_safeOccInstance = 0;


    OccManager::OccManager()
        :iv_occMaster(NULL),
        iv_state(OCC_STATE_UNKNOWN),
        iv_targetState(OCC_STATE_ACTIVE),
        iv_resetCount(0),
        iv_normalPstateTables(true)
    {
    }


    OccManager::~OccManager()
    {
        _removeAllOccs();
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
    errlHndl_t OccManager::_buildOccs()
    {
        errlHndl_t err = NULL;
        bool safeModeNeeded = false;
        TMGT_INF("_buildOccs called");

        // Only build OCC objects once.
        if((iv_occArray.size() > 0) && (iv_occMaster != NULL))
        {
            TMGT_INF("_buildOccs: Existing OCC Targets kept = %d",
                     iv_occArray.size());
            return err;
        }

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
                TMGT_INF("_buildOccs: PROC%d is functional", instance);
                // Get HOMER virtual address
                uint8_t * homer = (uint8_t*)
                    ((*proc)->getAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>());
                const uint8_t * homerPhys = (uint8_t*)
                    ((*proc)->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>());
                TMGT_INF("_buildOccs: homer = 0x%08llX (virt) / 0x%08llX (phys)"
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
                    TMGT_ERR("_buildOccs: Using hardcoded HOMER of 0x%08lX",
                             homer);
                }
#endif

                if ((NULL != homer) && (NULL != homerPhys))
                {
                    // Get functional OCC (one per proc)
                    TARGETING::TargetHandleList pOccs;
                    getChildChiplets(pOccs, *proc, TARGETING::TYPE_OCC);
                    if (pOccs.size() > 0)
                    {
                        const unsigned long huid =
                            pOccs[0]->getAttr<TARGETING::ATTR_HUID>();
                        const bool masterCapable =
                            pOccs[0]->
                            getAttr<TARGETING::ATTR_OCC_MASTER_CAPABLE>();

                        TMGT_INF("_buildOccs: Found OCC%d - HUID: 0x%0lX, "
                                 "masterCapable: %c, homer: 0x%0lX",
                                 instance, huid, masterCapable?'Y':'N', homer);
                        _addOcc(instance, masterCapable, homer, pOccs[0]);
                    }
                    else
                    {
                        // OCC must not be functional
                        TMGT_ERR("_buildOccs: OCC%d not functional", instance);
                    }
                }
                else
                {
                    // OCC will not be functional with no HOMER address
                    TMGT_ERR("_buildOccs: HOMER address for OCC%d is NULL!",
                             instance);
                    safeModeNeeded = true;
                    if (NULL == err)
                    {
                        /*@
                         * @errortype
                         * @moduleid HTMGT_MOD_BUILD_OCCS
                         * @reasoncode HTMGT_RC_OCC_CRIT_FAILURE
                         * @userdata1  OCC Instance
                         * @userdata2  homer virtual address
                         * @devdesc Homer pointer is NULL, unable to communicate
                         *          with the OCCs.  Leaving system in safe mode.
                         */
                        bldErrLog(err,
                                  HTMGT_MOD_BUILD_OCCS,
                                  HTMGT_RC_OCC_CRIT_FAILURE,
                                  0, instance,
                                  (uint64_t)homer>>32,
                                  (uint64_t)homer&0xFFFFFFFF,
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                    }
                }

                if (NULL != iv_occMaster)
                {
                    // update master occsPresent bit for each slave OCC
                    for(occList_t::const_iterator occ = iv_occArray.begin();
                        occ != iv_occArray.end();
                        ++occ)
                    {
                        if((*occ) != iv_occMaster)
                        {
                            iv_occMaster->
                                updateOccPresentBits((*occ)->getPresentBits());
                        }
                    }
                }
            } // for each processor
        }
        else
        {
            TMGT_ERR("_buildOccs: No functional processors found");
        }

        if (0 == _getNumOccs())
        {
            TMGT_ERR("_buildOccs: Unable to find any functional OCCs");
            if (NULL == err)
            {
                /*@
                 * @errortype
                 * @reasoncode      HTMGT_RC_OCC_UNAVAILABLE
                 * @moduleid        HTMGT_MOD_BUILD_OCCS
                 * @userdata1       functional processor count
                 * @devdesc         No functional OCCs were found
                 */
                bldErrLog(err, HTMGT_MOD_BUILD_OCCS,
                          HTMGT_RC_OCC_UNAVAILABLE,
                          0, pProcs.size(), 0, 0,
                          ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            }
            safeModeNeeded = true;
        }

        if (safeModeNeeded)
        {
            // Clear OCC active sensors
            errlHndl_t err2 = setOccActiveSensors(false);
            if (err2)
            {
                TMGT_ERR("_buildOccs: Set OCC active sensor to false failed.");
                ERRORLOG::errlCommit(err2, HTMGT_COMP_ID);
            }

            // Reset all OCCs
            TMGT_INF("_buildOccs: Calling HBOCC::stopAllOCCs");
            err2 = HBOCC::stopAllOCCs();
            if (NULL != err2)
            {
                TMGT_ERR("_buildOccs: stopAllOCCs failed with rc 0x%04X",
                         err2->reasonCode());
                err2->collectTrace("HTMGT");
                ERRORLOG::errlCommit(err2, HTMGT_COMP_ID);
            }

            updateForSafeMode(err);
        }

        TMGT_INF("_buildOccs: OCC Targets found = %d", _getNumOccs());

        return err;

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


    // Get pointer to specified OCC
    Occ * OccManager::_getOcc(const uint8_t i_instance)
    {
        Occ *targetOcc = NULL;
        for (std::vector<Occ*>::iterator pOcc = iv_occArray.begin();
             pOcc < iv_occArray.end();
             pOcc++)
        {
            if ((*pOcc)->getInstance() == i_instance)
            {
                targetOcc = (*pOcc);
                break;
            }
        }

        return targetOcc;

    } // eng OccManager::_getOcc()


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

            l_err = _buildOccs(); // if not already built.
            if (NULL == l_err)
            {
                // Send poll cmd to confirm comm has been established.
                // Flush old errors to ensure any new errors will be collected
                l_err = _sendOccPoll(true, NULL);
                if (l_err)
                {
                    TMGT_ERR("_setOccState: Poll OCCs failed.");
                    // Proceed with reset even if failed
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                }

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
                    }

                    // Make sure all OCCs went to active state
                    for (std::vector<Occ*>::iterator pOcc = iv_occArray.begin();
                         pOcc < iv_occArray.end();
                         pOcc++)
                    {
                        if (requestedState != (*pOcc)->getState())
                        {
                            TMGT_ERR("_setOccState: OCC%d is not in 0x%02X "
                                     "state",
                                     (*pOcc)->getInstance(), requestedState);
                            /*@
                             * @errortype
                             * @moduleid HTMGT_MOD_OCCMGR_SET_STATE
                             * @reasoncode HTMGT_RC_OCC_UNEXPECTED_STATE
                             * @userdata1[0-31] requested state
                             * @userdata1[32-63] OCC state
                             * @userdata2 OCC instance
                             * @devdesc OCC did not change to requested state
                             */
                            bldErrLog(l_err, HTMGT_MOD_OCCMGR_SET_STATE,
                                      HTMGT_RC_OCC_UNEXPECTED_STATE,
                                      requestedState, (*pOcc)->getState(),
                                      0, (*pOcc)->getInstance(),
                                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
                            break;
                        }
                    }

                    if (NULL == l_err)
                    {
                        TMGT_INF("_setOccState: All OCCs have reached state "
                                 "0x%02X", requestedState);
                        iv_state = requestedState;

                        if (OCC_STATE_ACTIVE == requestedState)
                        {
                            TMGT_CONSOLE("OCCs are now running in ACTIVE "
                                         "state");
                        }
                        else
                        {
                            TMGT_CONSOLE("OCCs are now running in OBSERVATION "
                                         "state");
                        }
                    }

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
             * @userdata1 requested state
             * @devdesc Invalid OCC state requested
             */
            bldErrLog(l_err, HTMGT_MOD_OCCMGR_SET_STATE,
                      HTMGT_RC_INVALID_DATA,
                      0, requestedState, 0, 0,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        return l_err;

    } // end OccManager::_setOccState()


    errlHndl_t OccManager::_resetOccs(TARGETING::Target * i_failedOccTarget,
                                      bool i_skipCountIncrement,
                                      bool i_skipComm)
    {
        errlHndl_t err = NULL;
        bool atThreshold = false;

        err = _buildOccs(); // if not a already built.
        if (NULL == err)
        {
            if (false == int_flags_set(FLAG_RESET_DISABLED))
            {
                err = setOccActiveSensors(false); // Set OCC sensor to inactive
                if( err )
                {
                    TMGT_ERR("_resetOccs: Set OCC sensors to inactive failed.");
                    // log and continue
                    ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                }

                if (false == i_skipComm)
                {
                    // Send poll cmd to all OCCs to establish comm
                    err = _sendOccPoll(false,NULL);
                    if (err)
                    {
                        TMGT_ERR("_resetOccs: Poll OCCs failed.");
                        // Proceed with reset even if failed
                        ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                    }
                }

                for(occList_t::const_iterator occ = iv_occArray.begin();
                    occ != iv_occArray.end();
                    ++occ)
                {
                    if((*occ)->getTarget() == i_failedOccTarget)
                    {
                        (*occ)->failed(true);
                    }

                    if (false == i_skipComm)
                    {
                        // Send reset prep cmd to all OCCs
                        if((*occ)->resetPrep())
                        {
                            atThreshold = true;
                        }
                    }
                }

                if ((false == i_skipCountIncrement) && (false == _occFailed()))
                {
                    // No OCC has been marked failed, increment sys reset count
                    ++iv_resetCount;

                    TMGT_INF("_resetOCCs: Incrementing system OCC reset count"
                             " to %d", iv_resetCount);

                    if(iv_resetCount > OCC_RESET_COUNT_THRESHOLD)
                    {
                        atThreshold = true;
                    }
                }
                // else failed OCC reset count will be incremented automatically

                // Update OCC states to RESET
                for(occList_t::const_iterator occ = iv_occArray.begin();
                    occ != iv_occArray.end();
                    ++occ)
                {
                    (*occ)->iv_state = OCC_STATE_RESET;
                }

                uint64_t retryCount = OCC_RESET_COUNT_THRESHOLD;
                while(retryCount)
                {
                    // Reset all OCCs
                    TMGT_INF("_resetOccs: Calling HBOCC::stopAllOCCs");
                    err = HBOCC::stopAllOCCs();
                    if(!err)
                    {
                        break;
                    }
                    --retryCount;

                    if (int_flags_set(FLAG_HALT_ON_RESET_FAIL))
                    {
                        TMGT_ERR("_resetOCCs: stopAllOCCs failed with 0x%04X "
                                 "and HALT_ON_RESET_FAIL is set.  Resets will "
                                 "be disabled", err->reasonCode());
                        set_int_flags(get_int_flags() | FLAG_RESET_DISABLED);
                        break;
                    }

                    if(retryCount)
                    {
                        // log if not last retry
                        ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                    }
                    else
                    {
                        TMGT_ERR("_resetOCCs: stopAllOCCs failed. "
                                 "Leaving OCCs in reset state");
                        // pass err handle back
                        err->collectTrace("HTMGT");
                    }
                }

                if(!atThreshold && !err)
                {
                    for(occList_t::const_iterator occ = iv_occArray.begin();
                        occ != iv_occArray.end();
                        ++occ)
                    {
                        // After OCCs have been reset, clear flags
                        (*occ)->postResetClear();
                    }

                    TMGT_INF("_resetOccs: Calling HBOCC::activateOCCs");
                    err = HBOCC::activateOCCs();
                    if(err)
                    {
                        TMGT_ERR("_resetOCCs: activateOCCs failed. ");
                        err->collectTrace("HTMGT");
                    }
                }
                else if (!err) // Reset Threshold reached and no other err
                {
                    // Create threshold error
                    TMGT_ERR("_resetOCCs: Retry Threshold reached. "
                             "Leaving OCCs in reset state");
                    /*@
                     * @errortype
                     * @moduleid HTMGT_MOD_OCC_RESET
                     * @reasoncode HTMGT_RC_OCC_RESET_THREHOLD
                     * @userdata1  return code triggering safe mode
                     * @userdata2  OCC instance
                     * @devdesc OCC reset threshold reached.
                     *          Leaving OCCs in reset state
                     */
                    bldErrLog(err,
                              HTMGT_MOD_OCC_RESET,
                              HTMGT_RC_OCC_CRIT_FAILURE,
                              0, cv_safeReturnCode, 0, cv_safeOccInstance,
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                }

                // Any error at this point means OCCs were not reactivated
                if(err)
                {
                    updateForSafeMode(err);
                }
            }
            else
            {
                TMGT_INF("_resetOccs: Skipping OCC reset due to "
                         "internal flags 0x%08X", get_int_flags());
            }
        }

        return err;

    } // end OccManager::_resetOccs()


    void OccManager::updateForSafeMode(errlHndl_t & io_err)
    {
        io_err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);

        // Add level 2 support callout
        io_err->addProcedureCallout(HWAS::EPUB_PRC_LVL_SUPP,
                                    HWAS::SRCI_PRIORITY_MED);
        // Add HB firmware callout
        io_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_MED);

        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        const uint8_t safeMode = 1;

        // Mark system as being in safe mode
        if(sys)
        {
            sys->setAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
        }
        iv_state = OCC_STATE_SAFE;

        _updateSafeModeReason(io_err->reasonCode(), 0);

        TMGT_ERR("updateForSafeMode: Safe Mode (RC: 0x%04X OCC%d)",
                 cv_safeReturnCode, cv_safeOccInstance);

        TMGT_CONSOLE("OCCs are not active. The system will remain in "
                     "safe mode (RC: 0x%04x  for OCC%d)",
                     cv_safeReturnCode,
                     cv_safeOccInstance);

    } // end  OccManager::updateForSafeMode()


    // Wait for all OCCs to reach communications checkpoint
    errlHndl_t OccManager::_waitForOccCheckpoint()
    {
        errlHndl_t checkpointElog = NULL;
#ifdef CONFIG_HTMGT
        // Wait up to 15 seconds for all OCCs to be ready (150 * 100ms = 15s)
        const size_t NS_BETWEEN_READ = 100 * NS_PER_MSEC;
        const size_t READ_RETRY_LIMIT = 150;

        if (iv_occArray.size() > 0)
        {
            uint8_t retryCount = 0;
            bool throttleErrors = false;

            for (std::vector<Occ*>::iterator pOcc = iv_occArray.begin();
                 pOcc < iv_occArray.end();
                 pOcc++)
            {
                bool occReady = false;
                uint16_t lastCheckpoint = 0x0000;

                while ((!occReady) && (retryCount++ < READ_RETRY_LIMIT))
                {
                    nanosleep(0, NS_BETWEEN_READ);

                    // Read SRAM response buffer to check for OCC checkpoint
                     errlHndl_t l_err = NULL;
                    const uint16_t l_length = 8;
                    ecmdDataBufferBase l_buffer(l_length*8); // convert to bits
                    l_err = HBOCC::readSRAM((*pOcc)->getTarget(),
                                            OCC_RSP_SRAM_ADDR,
                                            l_buffer);
                    if (NULL == l_err)
                    {
                        // Check response status for checkpoint (byte 6-7)
                        const uint16_t checkpoint = l_buffer.getHalfWord(3);
                        if (checkpoint != lastCheckpoint)
                        {
                            TMGT_INF("_waitForOccCheckpoint: OCC%d Checkpoint "
                                     "0x%04X",
                                     (*pOcc)->getInstance(), checkpoint);
                            lastCheckpoint = checkpoint;
                        }
                        if (0x0EFF == checkpoint)
                        {
                            TMGT_INF("_waitForOccCheckpoint OCC%d ready!",
                                     (*pOcc)->getInstance());

                            occReady = true;
                            break;
                        }
                    }
                    else
                    {
                        if (false == throttleErrors)
                        {
                            throttleErrors = true;
                            TMGT_ERR("_waitForOccCheckpoint: error trying to "
                                     "read OCC%d SRAM (rc=0x%04X)",
                                     (*pOcc)->getInstance(),
                                     l_err->reasonCode());
                            ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                        }
                        else
                        {
                            delete l_err;
                            l_err = NULL;
                        }
                    }
                }

                if (!occReady)
                {
                    TMGT_CONSOLE("Final OCC%d Checkpoint NOT reached (0x%04X)",
                                 (*pOcc)->getInstance(), lastCheckpoint);
                    TMGT_ERR("_waitForOccCheckpoint OCC%d still NOT ready! "
                             "(last checkpoint=0x%04X)",
                             (*pOcc)->getInstance(), lastCheckpoint);
                    errlHndl_t l_err = NULL;
                    /*@
                     * @errortype
                     * @moduleid HTMGT_MOD_WAIT_FOR_CHECKPOINT
                     * @reasoncode HTMGT_RC_OCC_NOT_READY
                     * @userdata1 OCC instance
                     * @userdata2 last OCC checkpoint
                     * @devdesc Set of OCC state failed
                     */
                    bldErrLog(l_err, HTMGT_MOD_WAIT_FOR_CHECKPOINT,
                              HTMGT_RC_OCC_NOT_READY,
                              0, (*pOcc)->getInstance(), 0, lastCheckpoint,
                              ERRORLOG::ERRL_SEV_PREDICTIVE);

                    (*pOcc)->collectCheckpointScomData(l_err);
                    if (NULL == checkpointElog)
                    {
                        // return the first elog
                        checkpointElog = l_err;
                        l_err = NULL;
                    }
                    else
                    {
                        ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    }
                    TMGT_ERR("waitForOccCheckpoint OCC%d still NOT ready!",
                             (*pOcc)->getInstance());
                }
            }
        }
#endif
        return checkpointElog;
    }


    void OccManager::_updateSafeModeReason(uint32_t i_src,
                                           uint32_t i_instance)
    {
        if ((cv_safeReturnCode == 0) ||
            ((i_src == 0) && (i_instance == 0)))
        {
            // Only update safe mode reason for the first failure,
            // or if trying to clear safe mode
            cv_safeReturnCode = i_src;
            cv_safeOccInstance = i_instance;
        }
    }


    uint32_t OccManager::_getSafeModeReason(uint32_t & o_instance)
    {
        o_instance = cv_safeOccInstance;
        return cv_safeReturnCode;
    }


    bool OccManager::_occNeedsReset()
    {
        bool needsReset = false;

        for (std::vector<Occ*>::iterator pOcc = iv_occArray.begin();
             pOcc < iv_occArray.end();
             pOcc++)
        {
            if ((*pOcc)->needsReset())
            {
                needsReset = true;
                break;
            }
        }

        return needsReset;
    }


    // Return true if any OCC has been marked as failed
    bool OccManager::_occFailed()
    {
        bool failed = false;

        for (std::vector<Occ*>::iterator pOcc = iv_occArray.begin();
             pOcc < iv_occArray.end();
             pOcc++)
        {
            if ((*pOcc)->iv_failed)
            {
                failed = true;
                break;
            }
        }

        return failed;
    }


    // Collect HTMGT Status Information for debug
    // NOTE: o_data is pointer to 4096 byte buffer
    void OccManager::_getOccData(uint16_t & o_length, uint8_t *o_data)
    {
        uint16_t index = 0;

        // If the system is in safemode then can't talk to OCCs (no build/poll)
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        uint8_t safeMode = 0;
        if (sys &&
            sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode) &&
            (0 == safeMode))
        {
            // Make sure OCCs were built first (so data is valid)
            errlHndl_t err = _buildOccs(); // if not a already built.
            if (err)
            {
                TMGT_ERR("_getOccData: failed to build OCC structures "
                         "rc=0x%04X", err->reasonCode());
                ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
            }
            // Send poll to confirm comm, update states and flush errors
            err = _sendOccPoll(true, NULL);
            if (err)
            {
                TMGT_ERR("_getOccData: Poll OCCs failed.");
                ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
            }
        }

        // First add HTMGT specific data
        o_data[index++] = _getNumOccs();
        o_data[index++] = (NULL!=iv_occMaster)?iv_occMaster->getInstance():0xFF;
        o_data[index++] = iv_state;
        o_data[index++] = iv_targetState;
        o_data[index++] = iv_resetCount;
        o_data[index++] = iv_normalPstateTables ? 0 : 1;
        index += 1; // reserved for expansion
        o_data[index++] = safeMode;
        UINT32_PUT(&o_data[index], cv_safeReturnCode);
        index += 4;
        UINT32_PUT(&o_data[index], cv_safeOccInstance);
        index += 4;

        // Now add OCC specific data (for each OCC)
        for (std::vector<Occ*>::iterator pOcc = iv_occArray.begin();
             (pOcc < iv_occArray.end()) && (index+16 < 4096);
             pOcc++)
        {
            o_data[index++] = (*pOcc)->getInstance();
            o_data[index++] = (*pOcc)->getState();
            o_data[index++] = (*pOcc)->getRole();
            o_data[index++] = (*pOcc)->iv_masterCapable;
            o_data[index++] = (*pOcc)->iv_commEstablished;
            index += 3; // reserved for expansion
            o_data[index++] = (*pOcc)->iv_failed;
            o_data[index++] = (*pOcc)->needsReset();
            o_data[index++] = (*pOcc)->iv_resetReason;
            o_data[index++] = (*pOcc)->iv_resetCount;
            if ((*pOcc)->iv_lastPollValid)
            {
                memcpy(&o_data[index], (*pOcc)->iv_lastPollResponse, 4);
            }
            else
            {
                memset(&o_data[index], 0xFF, 4);
            }
            index += 4;
        }

        o_length = index;
    }


    // Set default pstate table type and reset all OCCs to pick them up
    errlHndl_t OccManager::_loadPstates(bool i_normalPstates)
    {
        errlHndl_t err = NULL;

        // Set default pstate table type
        _setPstateTable(i_normalPstates);

        // Reset OCCs to pick up new tables (skip incrementing reset count)
        TMGT_INF("_loadPstates: Resetting OCCs");
        err = _resetOccs(NULL, true);

        return err;
    }


    // Consolidate all OCC states
    void OccManager::_syncOccStates()
    {
        occStateId currentState = OCC_STATE_NO_CHANGE;

        for(occList_t::const_iterator occ_itr = iv_occArray.begin();
            (occ_itr != iv_occArray.end());
            ++occ_itr)
        {
            Occ * occ = *occ_itr;
            if (OCC_STATE_NO_CHANGE == currentState)
            {
                currentState = occ->getState();
            }
            else
            {
                if (currentState != occ->getState())
                {
                    // States do not match yet...
                    currentState = OCC_STATE_NO_CHANGE;
                    break;
                }
            }
        }
        if (OCC_STATE_NO_CHANGE != currentState)
        {
            if (iv_state != currentState)
            {
                TMGT_INF("syncOccStates: All OCCs are in 0x%02X", currentState);
                iv_state = currentState;
            }
        }
    }


    // Clear all OCC reset counts
    void OccManager::_clearResetCounts()
    {
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        uint8_t safeMode = 0;
        if (sys)
        {
            sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
        }
        for (std::vector<Occ*>::iterator pOcc = iv_occArray.begin();
             pOcc < iv_occArray.end();
             pOcc++)
        {
            if ((*pOcc)->iv_resetCount != 0)
            {
                TMGT_INF("_clearResetCounts: Clearing OCC%d reset count "
                         "(was %d)",
                         (*pOcc)->getInstance(), (*pOcc)->iv_resetCount);
                (*pOcc)->iv_resetCount = 0;
                if (safeMode)
                {
                    // Clear OCC flags (failed, commEstablished, etc)
                    (*pOcc)->postResetClear();
                }
            }
        }

        if (iv_resetCount != 0)
        {
            TMGT_INF("_clearResetCounts: Clearing system reset count "
                     "(was %d)", iv_resetCount);
            iv_resetCount = 0;
        }
    }


    uint8_t  OccManager::getNumOccs()
    {
        return Singleton<OccManager>::instance()._getNumOccs();
    }


    std::vector<Occ*> OccManager::getOccArray()
    {
        return Singleton<OccManager>::instance()._getOccArray();
    }


    errlHndl_t OccManager::buildOccs()
    {
        return Singleton<OccManager>::instance()._buildOccs();
    }


    Occ * OccManager::getMasterOcc()
    {
        return Singleton<OccManager>::instance()._getMasterOcc();
    }


    Occ * OccManager::getOcc(const uint8_t i_instance)
    {
        return Singleton<OccManager>::instance()._getOcc(i_instance);
    }


    errlHndl_t OccManager::setOccState(const occStateId i_state)
    {
        return Singleton<OccManager>::instance()._setOccState(i_state);
    }


    errlHndl_t OccManager::resetOccs(TARGETING::Target * i_failedOccTarget,
                                     bool i_skipCountIncrement,
                                     bool i_skipComm)
    {
        return
            Singleton<OccManager>::instance()._resetOccs(i_failedOccTarget,
                                                         i_skipCountIncrement,
                                                         i_skipComm);
    }


    occStateId OccManager::getTargetState()
    {
        return Singleton<OccManager>::instance()._getTargetState();
    }


    errlHndl_t OccManager::waitForOccCheckpoint()
    {
        return Singleton<OccManager>::instance()._waitForOccCheckpoint();
    }

    void OccManager::updateSafeModeReason(uint32_t i_src,
                                          uint32_t i_instance)
    {
        Singleton<OccManager>::instance().
            _updateSafeModeReason(i_src, i_instance);
    }

    uint32_t OccManager::getSafeModeReason(uint32_t & o_instance)
    {
        return Singleton<OccManager>::instance().
            _getSafeModeReason(o_instance);
    }

    bool OccManager::occNeedsReset()
    {
        return Singleton<OccManager>::instance()._occNeedsReset();
    }

    bool OccManager::occFailed()
    {
        return Singleton<OccManager>::instance()._occFailed();
    }

    void OccManager::getOccData(uint16_t & o_length, uint8_t *o_data)
    {
        Singleton<OccManager>::instance()._getOccData(o_length, o_data);
    }

    errlHndl_t OccManager::loadPstates(bool i_normalPstates)
    {
        return Singleton<OccManager>::instance()._loadPstates(i_normalPstates);
    }

    bool OccManager::isNormalPstate()
    {
        return Singleton<OccManager>::instance()._isNormalPstate();
    }

    void OccManager::setPstateTable(bool i_useNormal)
    {
        Singleton<OccManager>::instance()._setPstateTable(i_useNormal);
    }

    void OccManager::clearResetCounts()
    {
        Singleton<OccManager>::instance()._clearResetCounts();
    }

    void OccManager::syncOccStates()
    {
        Singleton<OccManager>::instance()._syncOccStates();
    }

} // end namespace



