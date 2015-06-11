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
#include <sys/time.h>
#include <ecmdDataBufferBase.H>
#include <hwpf/hwp/occ/occAccess.H>

#include <hwpf/hwp/occ/occ.H>
#include <hwpf/hwp/occ/occ_common.H>

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
    }



    /////////////////////////////////////////////////////////////////


    uint32_t OccManager::cv_safeReturnCode = 0;
    uint32_t OccManager::cv_safeOccInstance = 0;


    OccManager::OccManager()
        :iv_occMaster(NULL),
        iv_state(OCC_STATE_UNKNOWN),
        iv_targetState(OCC_STATE_ACTIVE),
        iv_resetCount(0)
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
        TMGT_INF("buildOccs called");

        // Only build OCC objects once.
        if((iv_occArray.size() > 0) && (iv_occMaster != NULL))
        {
            TMGT_INF("buildOccs: Existing OCC Targets kept = %d",
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
                TMGT_INF("buildOccs: PROC%d is functional", instance);
                // Get HOMER virtual address
                uint8_t * homer = (uint8_t*)
                    ((*proc)->getAttr<TARGETING::ATTR_HOMER_VIRT_ADDR>());
                const uint8_t * homerPhys = (uint8_t*)
                    ((*proc)->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>());
                TMGT_INF("buildOccs: homer = 0x%08llX (virt) / 0x%08llX (phys)"
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

                        TMGT_INF("Found OCC%d - HUID: 0x%0lX, masterCapable:"
                                 " %c, homer: 0x%0lX",
                                 instance, huid, masterCapable?'Y':'N', homer);
                        _addOcc(instance, masterCapable, homer, pOccs[0]);
                    }
                    else
                    {
                        // OCC must not be functional
                        TMGT_ERR("OCC%d not functional", instance);
                    }
                }
                else
                {
                    // OCC will not be functional with no HOMER address
                    TMGT_ERR("HOMER address for OCC%d is NULL!", instance);
                    safeModeNeeded = true;
                    if (NULL == err)
                    {
                        /*@
                         * @errortype
                         * @moduleid HTMGT_MOD_BUILD_OCCS
                         * @reasoncode HTMGT_RC_OCC_CRIT_FAILURE
                         * @devdesc Homer pointer is NULL, unable to communicate
                         *          with the OCCs.  Leaving system in safe mode.
                         */
                        bldErrLog(err,
                                  HTMGT_MOD_BUILD_OCCS,
                                  HTMGT_RC_OCC_CRIT_FAILURE,
                                  0, 0, 0, 0,
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                    }
                }
            } // for each processor
        }
        else
        {
            TMGT_ERR("No functional processors found");
        }

        if (0 == _getNumOccs())
        {
            TMGT_ERR("Unable to find any functional OCCs");
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
            TMGT_INF("Calling HBOCC::stopAllOCCs");
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

        TMGT_INF("buildOccs: OCC Targets found = %d", _getNumOccs());

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
                        TMGT_INF("_setOccState: All OCCs have reached state "
                                 "0x%02X", requestedState);

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


    errlHndl_t OccManager::_resetOccs(TARGETING::Target * i_failedOccTarget)
    {
        errlHndl_t err = NULL;
        bool atThreshold = false;

        err = _buildOccs(); // if not a already built.
        if (NULL == err)
        {
            err = setOccActiveSensors(false); // Set OCC sensor to inactive
            if( err )
            {
                TMGT_ERR("_resetOccs: Set OCC sensors to inactive failed.");
                // log and continue
                ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
            }

            // Send poll cmd to all OCCs to establish comm
            err = _sendOccPoll(false,NULL);
            if (err)
            {
                TMGT_ERR("_resetOccs: Poll OCCs failed.");
                // Proceed with reset even if failed
                ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
            }

            for(occList_t::const_iterator occ = iv_occArray.begin();
                occ != iv_occArray.end();
                ++occ)
            {
                if((*occ)->getTarget() == i_failedOccTarget)
                {
                    (*occ)->failed(true);
                }

                if((*occ)->resetPrep())
                {
                    atThreshold = true;
                }
            }

            if(false == _occNeedsReset())
            {
                // No occ target needs reset - increment system reset count
                ++iv_resetCount;

                TMGT_INF("resetOCCs: Incrementing system OCC reset count to %d",
                         iv_resetCount);

                if(iv_resetCount > OCC_RESET_COUNT_THRESHOLD)
                {
                    atThreshold = true;
                }

            }

            uint64_t retryCount = OCC_RESET_COUNT_THRESHOLD;
            while(retryCount)
            {
                // Reset all OCCs
                TMGT_INF("Calling HBOCC::stopAllOCCs");
                err = HBOCC::stopAllOCCs();
                if(!err)
                {
                    break;
                }
                --retryCount;

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

                TMGT_INF("Calling HBOCC::activateOCCs");
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
                 * @devdesc OCC reset threshold reached.
                 *          Leaving OCCs in reset state
                 */
                bldErrLog(err,
                          HTMGT_MOD_OCC_RESET,
                          HTMGT_RC_OCC_CRIT_FAILURE,
                          0, 0, 0, 0,
                          ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            }

            // Any error at this point means OCCs were not reactivated
            if(err)
            {
                updateForSafeMode(err);
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

        // Put into safemode
        if(sys)
        {
            sys->setAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
        }

        _updateSafeModeReason(io_err->reasonCode(), 0);

        TMGT_ERR("updateForSafeMode: Safe Mode (RC: 0x%04X OCC%d)",
                 cv_safeReturnCode, cv_safeOccInstance);

        TMGT_CONSOLE("OCCs are not active. The system will remain in "
                     "safe mode (RC: 0x%04x  for OCC%d)",
                     cv_safeReturnCode,
                     cv_safeOccInstance);

    } // end  OccManager::updateForSafeMode()


    // Wait for all OCCs to reach communications checkpoint
    void OccManager::_waitForOccCheckpoint()
    {
#ifdef CONFIG_HTMGT
        // Wait up to 10 seconds for all OCCs to be ready (100 * 100ms = 10s)
        const size_t NS_BETWEEN_READ = 100 * NS_PER_MSEC;
        const size_t READ_RETRY_LIMIT = 100;

        if (iv_occArray.size() > 0)
        {
            uint8_t retryCount = 0;
            bool throttleErrors = false;

            for (std::vector<Occ*>::iterator pOcc = iv_occArray.begin();
                 pOcc < iv_occArray.end();
                 pOcc++)
            {
                bool occReady = false;

                while ((!occReady) && (retryCount++ < READ_RETRY_LIMIT))
                {
                    // Read SRAM response buffer to check for OCC checkpoint
                     errlHndl_t l_err = NULL;
                    const uint16_t l_length = 8;
                    ecmdDataBufferBase l_buffer(l_length*8); // convert to bits
                    l_err = HBOCC::readSRAM((*pOcc)->getTarget(),
                                            OCC_RSP_SRAM_ADDR,
                                            l_buffer);
                    if (NULL == l_err)
                    {
                        // Check response status for checkpoint
                        if ((0x0E == l_buffer.getByte(6)) &&
                            (0xFF == l_buffer.getByte(7)))
                        {
                            TMGT_INF("waitForOccCheckpoint OCC%d ready!",
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
                            TMGT_ERR("waitForOccCheckpoint: error trying to "
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

                    nanosleep(0, NS_BETWEEN_READ);
                }

                if (!occReady)
                {
                    TMGT_ERR("waitForOccCheckpoint OCC%d still NOT ready!",
                             (*pOcc)->getInstance());
                }

                if ((OCC_ROLE_MASTER != (*pOcc)->getRole()) &&
                    (NULL != iv_occMaster))
                {
                    // update master occsPresent bit for each slave OCC
                    iv_occMaster->
                        updateOccPresentBits((*pOcc)->getPresentBits());
                }
            }
        }
#endif
    }


    void OccManager::_updateSafeModeReason(uint32_t i_src,
                                           uint32_t i_instance)
    {
        if (cv_safeReturnCode == 0)
        {
            // Only update safe mode reason for the first failure
            cv_safeReturnCode = i_src;
            cv_safeOccInstance = i_instance;
        }
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


    errlHndl_t OccManager::setOccState(const occStateId i_state)
    {
        return Singleton<OccManager>::instance()._setOccState(i_state);
    }

    errlHndl_t OccManager::resetOccs(TARGETING::Target * i_failedOccTarget)
    {
        return
            Singleton<OccManager>::instance()._resetOccs(i_failedOccTarget);
    }


    occStateId OccManager::getTargetState()
    {
        return Singleton<OccManager>::instance()._getTargetState();
    }


    void OccManager::waitForOccCheckpoint()
    {
        return Singleton<OccManager>::instance()._waitForOccCheckpoint();
    }

    void OccManager::updateSafeModeReason(uint32_t i_src,
                                          uint32_t i_instance)
    {
        return Singleton<OccManager>::instance().
            _updateSafeModeReason(i_src, i_instance);
    }

    bool OccManager::occNeedsReset()
    {
        return Singleton<OccManager>::instance()._occNeedsReset();
    }

} // end namespace



