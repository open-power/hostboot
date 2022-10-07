/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt.C $                                       */
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
#include "htmgt_activate.H"
#include "htmgt_cfgdata.H"
#include "htmgt_utility.H"
#include "htmgt_occmanager.H"
#include "htmgt_poll.H"
#include <devicefw/userif.H>
#include <console/consoleif.H>

//  Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <isteps/pm/scopedHomerMapper.H>

#include <sys/time.h>
#include <targeting/common/attributeTank.H>

#include <isteps/pm/pm_common_ext.H>

using namespace TARGETING;

namespace HTMGT
{

    // Move the OCCs to active state or log unrecoverable error and
    // stay in safe mode
    void processOccStartStatus(const bool i_startCompleted,
                               TARGETING::Target * i_failedOccTarget)
    {
        TMGT_INF(">>processOccStartStatus(%d,0x%p)",
                 i_startCompleted, i_failedOccTarget);
        errlHndl_t l_err = nullptr;
        uint32_t l_huid = 0;
        bool skip_comm = true;
        if (i_failedOccTarget)
        {
            l_huid = TARGETING::get_huid(i_failedOccTarget);
        }
        TMGT_INF("processOccStartStatus(Start Success=%c, failedOcc=0x%08X)",
                 i_startCompleted?'y':'n', l_huid);

        TARGETING::Target* sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(sys);
        uint8_t safeMode = 0;
        if(sys)
        {
            sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
        }
        if (safeMode == 0)
        {
            check_reset_count();
        }
        else
        {
            // OCCs were started, so clear Safe Mode
            TMGT_INF("processOccStartStatus: System was in Safe Mode, but OCCs "
                     "were started.  Clearing Safe Mode");
            safeMode = 0;
            sys->setAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
            OccManager::clearResetCounts();
        }

        if (false == int_flags_set(FLAG_HOLD_OCCS_IN_RESET))
        {
            if (i_startCompleted)
            {
                // Start listening for OCC atts
                OccManager::setOccsStarted(true);

                // Query functional OCCs (OCCs have just been started)
                l_err = OccManager::buildOccs(true);
                if (nullptr == l_err)
                {
                    if (nullptr != OccManager::getMasterOcc())
                    {
                        do
                        {
                            // Memory throttles are calculated during istep 18

                            // Make sure OCCs are ready for communication
                            l_err = OccManager::waitForOccCheckpoint();
                            if( l_err )
                            {
                                break;
                            }

#ifdef __HOSTBOOT_RUNTIME
                            nanosleep(1,0);
#endif

                            // Send poll to establish comm
                            TMGT_INF("Send initial poll to all OCCs to"
                                     " establish comm");
                            l_err = OccManager::sendOccPoll();
                            if (OccManager::occNeedsReset())
                            {
                                if (l_err == nullptr)
                                {
                                    /*@
                                     * @errortype
                                     * @reasoncode HTMGT_RC_OCC_UNEXPECTED_STATE
                                     * @moduleid  HTMGT_MOD_LOAD_START_STATUS
                                     * @devdesc OCC needs reset after initial poll
                                     * @custdesc An internal firmware error occurred
                                     */
                                    bldErrLog(l_err,
                                              HTMGT_MOD_LOAD_START_STATUS,
                                              HTMGT_RC_OCC_UNEXPECTED_STATE,
                                              0, 0, 0, 1,
                                              ERRORLOG::ERRL_SEV_INFORMATIONAL);
                                }
                                // No need to continue if reset is required
                                break;
                            }
                            else if (l_err)
                            {
                                // Continue even if polls failed (will retried)
                                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                            }
                            skip_comm = false;

                            // Send ALL config data
                            l_err = sendOccConfigData();
                            if (l_err)
                            {
                                break;
                            }

                            // Set the User PCAP
                            l_err = sendOccUserPowerCap();
                            if (l_err)
                            {
                                break;
                            }

                            // Wait for all OCCs to go to the target state
                            l_err = waitForOccState();
                            if ( l_err )
                            {
                                break;
                            }

                            if (OccManager::occNeedsReset())
                            {
                                bldErrLog(l_err,
                                          HTMGT_MOD_LOAD_START_STATUS,
                                          HTMGT_RC_OCC_UNEXPECTED_STATE,
                                          0, 0, 0, 0,
                                          ERRORLOG::ERRL_SEV_INFORMATIONAL);
                                break;
                            }

                            // Set enabled sensors for all OCCs,
                            // so BMC can start communication with OCCs
                            l_err = setOccEnabledSensors(true);
                            if (l_err)
                            {
                                // Continue even if failed to update sensor
                                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                            }

                        } while(0);
                    }
                    else
                    {
                        TMGT_ERR("Unable to find any Master capable OCCs");
                        /*@
                         * @errortype
                         * @reasoncode      HTMGT_RC_OCC_MASTER_NOT_FOUND
                         * @moduleid        HTMGT_MOD_LOAD_START_STATUS
                         * @userdata1       number of OCCs
                         * @devdesc         No OCC master was found
                         * @custdesc        An internal firmware error occurred
                         */
                        bldErrLog(l_err, HTMGT_MOD_LOAD_START_STATUS,
                                  HTMGT_RC_OCC_MASTER_NOT_FOUND,
                                  0, OccManager::getNumOccs(), 0, 0,
                                  ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    }
                }
                else
                {
                    // Failed to find functional OCCs, no need to try again
                    // Set original error log as unrecoverable/degraded performance and commit
                    l_err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE1);
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                }
            }
            else
            {
                TMGT_ERR("All OCCs were not loaded/started successfully");
                /*@
                 * @errortype
                 * @reasoncode      HTMGT_RC_OCC_START_FAIL
                 * @moduleid        HTMGT_MOD_LOAD_START_STATUS
                 * @userdata1       Failing OCC HUID
                 * @devdesc         OCCs were not loaded/started successfully
                 * @custdesc        An internal firmware error occurred
                 */
                bldErrLog(l_err, HTMGT_MOD_LOAD_START_STATUS,
                          HTMGT_RC_OCC_START_FAIL,
                          0, l_huid, 0, 0,
                          ERRORLOG::ERRL_SEV_INFORMATIONAL);

                errlHndl_t bldErr = OccManager::buildOccs(true);
                if (nullptr == bldErr)
                {
                    OccManager::addTraceToLog(l_err);
                }
                else
                {
                    TMGT_ERR("Unable to add OCC traces to log");
                    delete bldErr;
                    bldErr = nullptr;
                }
            }

            if (nullptr != l_err)
            {
                // If the start failed, HTMGT will attempt reset.
                // This will end up being a recursive call: After the
                // reset is done, this function will get called again.
                // If the reset returns success, then we know the
                // recovery was successful. When there are multiple reset
                // failures, the inital resetOcc() calls will return an
                // error.  That error can be ignored IF the OCCs were
                // actually enabled successfully in later recursive calls.
                TMGT_ERR("OCCs not all active (rc=0x%04X).  Attempting OCC "
                         "Reset", l_err->reasonCode());
                TMGT_CONSOLE("OCCs are not active (rc=0x%04X). "
                             "Attempting OCC Reset",
                             l_err->reasonCode());
                TMGT_INF("processOccStartStatus: Calling resetOccs");
                // Reset ALL OCCs, don't skip incrementing reset count, and
                // if comm has not been established, don't try to talk to OCCs
                errlHndl_t reset_err = OccManager::resetOccs(nullptr,
                                                             false,
                                                             skip_comm);
                if(reset_err)
                {
                    // reset failed and OCCs still not running yet
                    TMGT_ERR("processOccStartStatus: OccManager::resetOccs"
                             " failed with 0x%04X",
                             reset_err->reasonCode());

                    // Only make original error unrecoverable if it was cause of safe mode
                    uint32_t safeInstance = 0;
                    if (l_err->reasonCode() ==
                        OccManager::getSafeModeReason(safeInstance))
                    {
                        // Set original error log as unrecoverable/degraded and commit
                        l_err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE1);
                    }
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);

                    // Commit occReset error
                    ERRORLOG::errlCommit(reset_err, HTMGT_COMP_ID);
                }
                else
                {
                    const uint16_t l_rc = l_err->reasonCode();
                    // retry worked - commit original error as informational
                    l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    TMGT_INF("processOccStartStatus: OCC failed to go active "
                             "with 0x%04X, but recovery was successful",
                             l_rc);
                }
            }
        }
        else
        {
            // Ignore OCC attns until next StartStatus
            OccManager::setOccsStarted(false);

            TMGT_INF("processOccStartStatus: Skipping start of OCCS due to "
                     "internal flags 0x%08X", get_int_flags());
            // Reset all OCCs
            TMGT_INF("processOccStartStatus: Calling HBPM::resetPMAll()");
            l_err = HBPM::resetPMAll();
            if(l_err)
            {
                l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                l_err->collectTrace("HTMGT");
                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
            }

        }

        TMGT_INF("<<processOccStartStatus()");

    } // end processOccStartStatus()



    // Notify HTMGT that an OCC has an error to report
    void processOccError(TARGETING::Target * i_procTarget)
    {
        TMGT_INF(">>processOccAttn(0x%p)", i_procTarget);

        TARGETING::Target* sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(sys);
        uint8_t safeMode = 0;

        // If the system is in safemode then can't talk to OCCs -
        // ignore call to processOccError
        if(sys &&
           sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode) &&
           safeMode)
        {
            return;
        }

        if (!OccManager::getOccsStarted())
        {
            // OCCs have not been started, so ignore call
            TMGT_INF("<<processOccAttn: OCCs have not been started yet");
            return;
        }

        check_reset_count();

        if (OccManager::getState() == OCC_STATE_RESET)
        {
            TMGT_INF("<<processOccAttn: OCCs are in RESET state");
            return;
        }

        bool polledOneOcc = false;
        errlHndl_t err = OccManager::buildOccs();
        if (nullptr == err)
        {
            if (i_procTarget != nullptr)
            {
                const uint32_t l_huid =
                    i_procTarget->getAttr<TARGETING::ATTR_HUID>();
                TMGT_INF("processOccAttn(HUID=0x%08X) called", l_huid);

                TARGETING::TargetHandleList pOccs;
                getChildChiplets(pOccs, i_procTarget, TARGETING::TYPE_OCC);
                if (pOccs.size() > 0)
                {
                    // Poll specified OCC flushing any errors
                    errlHndl_t err = OccManager::sendOccPoll(true, pOccs[0]);
                    if (err)
                    {
                        ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                    }
                    polledOneOcc = true;
                }
            }

            if ((OccManager::getNumOccs() > 1) || (false == polledOneOcc))
            {
                // Send POLL command to all OCCs to flush any other errors
                errlHndl_t err = OccManager::sendOccPoll(true);
                if (err)
                {
                    ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                }
            }

            if (OccManager::occNeedsReset())
            {
                TMGT_ERR("processOccAttn(): OCCs need to be reset");
                // Don't pass failed target as OCC should have already
                // been marked as failed during the poll.
                errlHndl_t err = OccManager::resetOccs(nullptr);
                if(err)
                {
                    TMGT_ERR("processOccAttn(): Error when attempting"
                             " to reset OCCs");
                    ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                }
            }
        }
        else
        {
            // OCC build failed...
            TMGT_ERR("processOccAttn() called, but unable to find OCCs");
            ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
        }
        TMGT_INF("<<processOccAttn()");

    } // end processOccError()



    // Notify HTMGT that an OCC has failed and needs to be reset
    void processOccReset(TARGETING::Target * i_proc)
    {
        TMGT_INF(">>processOccReset(0x%p)", i_proc);
        errlHndl_t errl = nullptr;
        TARGETING::Target * failedOccTarget = nullptr;

        TARGETING::Target* sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(sys);
        uint8_t safeMode = 0;

        // If the system is in safemode then ignore request to reset OCCs
        if(sys &&
           sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode) &&
           safeMode)
        {
            return;
        }

        check_reset_count();

        if (OccManager::getState() == OCC_STATE_RESET)
        {
            TMGT_INF("<<processOccReset: OCCs are in RESET state");
            return;
        }

        uint8_t instance = 0;
        if( i_proc )
        {
            instance = i_proc->getAttr<TARGETING::ATTR_POSITION>();
            TARGETING::TargetHandleList pOccs;
            getChildChiplets(pOccs, i_proc, TARGETING::TYPE_OCC);
            if (pOccs.size() > 0)
            {
                failedOccTarget = pOccs[0];
            }
        }

        // Set safe mode reason in case we end up staying in reset
        OccManager::updateSafeModeReason(HTMGT_RC_EXTERNAL_RESET_REQUEST, instance);

        if(nullptr != failedOccTarget)
        {
            uint32_t huid = failedOccTarget->getAttr<TARGETING::ATTR_HUID>();
            TMGT_INF("processOccReset(HUID=0x%08X, OCC%d) called", huid, instance);
        }
        else
        {
            uint32_t huid = i_proc->getAttr<TARGETING::ATTR_HUID>();
            TMGT_INF("processOccReset: Invalid OCC target (proc huid=0x08X)"
                     "resetting OCCs anyway",
                     huid);

            /*@
             * @errortype
             * @reasoncode      HTMGT_RC_INVALID_PARAMETER
             * @moduleid        HTMGT_MOD_PROCESS_OCC_RESET
             * @userdata1       Processor HUID
             * @devdesc         No OCC target found for proc Target,
             * @custdesc        An internal firmware error occurred
             */
            bldErrLog(errl,
                      HTMGT_MOD_PROCESS_OCC_RESET,
                      HTMGT_RC_INVALID_PARAMETER,
                      0, huid, 0, 1,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);

            // Add HB firmware callout
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_MED);
            ERRORLOG::errlCommit(errl, HTMGT_COMP_ID); // sets errl to nullptr
        }

        if (false == int_flags_set(FLAG_EXT_RESET_DISABLED))
        {
            errl = OccManager::resetOccs(failedOccTarget, false, false,
                                         OCC_RESET_REASON_EXTERNAL_REQUEST);
            if(errl)
            {
                ERRORLOG::errlCommit(errl, HTMGT_COMP_ID); // sets errl to nullptr
            }
        }
        else
        {
            TMGT_INF("processOccReset: Skipping external reset due to "
                     "internal flags 0x%08X", get_int_flags());
        }
        TMGT_INF("<<processOccReset()");

    } // end processOccReset()



    // Set the OCC state
    errlHndl_t enableOccActuation(bool i_occActivation)
    {
        TMGT_INF(">>enableOccActuation(%c)", i_occActivation?'Y':'N');
        errlHndl_t l_err = nullptr;
        TARGETING::Target* sys = nullptr;

        // If the system is already in safemode then can't talk to OCCs
        TARGETING::targetService().getTopLevelTarget(sys);
        uint8_t safeMode = 0;
        if(sys)
        {
            sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
        }

        if (0 == safeMode)
        {
            check_reset_count();

            occStateId targetState = OCC_STATE_ACTIVE;
            if (false == i_occActivation)
            {
                targetState = OCC_STATE_OBSERVATION;
            }

            // Set state for all OCCs
            l_err = OccManager::setOccState(targetState);
            if (nullptr == l_err)
            {
                TMGT_INF("enableOccActuation: OCC states updated to 0x%02X",
                         targetState);
            }

            if (OccManager::occNeedsReset())
            {
                if (l_err)
                {
                    // Commit setOccState elog since OCCs will be reset
                    // and recovery attempted.
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                }

                TMGT_ERR("enableOccActuation(): OCCs need to be reset");
                // Don't pass failed target as OCC should have already
                // been marked as failed during the poll.
                l_err = OccManager::resetOccs(nullptr);

                // NOTE: If the system exceeded its reset count and ended up
                // in safe mode an error may not be returned here (if a
                // failure happened after the first reset attempt).
                // This is because the resets are recursive:
                //   HTMGT calls back into HBRT to initiate the reset, then
                //   HBRT calls into HTMGT when reset completed
                // To detected this condition we need to check for safe mode
                // after the recovery attempts and return error if in safe.
                if(sys)
                {
                    sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
                }
            }
        }

        if ((nullptr == l_err) && safeMode)
        {
            // Create an elog so the user knows the cmd failed.
            TMGT_ERR("enableOccActuation(): System is in safe mode");
            uint32_t safeInstance = 0;
            uint32_t safeRc = OccManager::getSafeModeReason(safeInstance);
            /*@
             * @errortype
             * @reasoncode      HTMGT_RC_OCC_CRIT_FAILURE
             * @moduleid        HTMGT_MOD_ENABLE_OCC_ACTUATION
             * @userdata1[0:31]  OCC activate [1==true][0==false]
             * @userdata1[32:63] return code triggering safe mode
             * @userdata2[0:31]  safeMode flag
             * @userdata2[32:63] OCC instance
             * @devdesc         Operation not allowed, system is in safe mode
             * @custdesc        A failure has occurred that is leaving the system in Safe Mode.
             *                  Performance will be impacted until the error has been resolved.
             */
            bldErrLog(l_err,
                      HTMGT_MOD_ENABLE_OCC_ACTUATION,
                      HTMGT_RC_OCC_CRIT_FAILURE,
                      i_occActivation, safeRc, safeMode, safeInstance,
                      ERRORLOG::ERRL_SEV_UNRECOVERABLE1);
        }

        TMGT_INF("<<enableOccActuation() returning 0x%04X",
                 (l_err==nullptr) ? 0 : l_err->reasonCode());
        return l_err;

    } // end enableOccActuation()


    // Send pass-thru command to HTMGT
    errlHndl_t passThruCommand(uint16_t   i_cmdLength,
                               uint8_t *  i_cmdData,
                               uint16_t & o_rspLength,
                               uint8_t *  o_rspData)
    {
        errlHndl_t err = nullptr;
        htmgtReasonCode failingSrc = HTMGT_RC_NO_ERROR;
        o_rspLength = 0;

        if ((i_cmdLength > 0) && (NULL != i_cmdData))
        {
            TMGT_INF(">>passThruCommand(0x%02X)", i_cmdData[0]);
        }
        else
        {
            TMGT_INF(">>passThruCommand()");
        }

        TARGETING::Target* sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(sys);
        uint8_t safeMode = 0;
        if(sys)
        {
            sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
        }
        if (safeMode == 0)
        {
            check_reset_count();
        }

        bool skip_occ_comm = false;
        if (safeMode ||
            (i_cmdData[0] == PASSTHRU_INTERNAL_FLAG) ||
            (i_cmdData[0] == PASSTHRU_OCC_CFG_DATA))
        {
            // No need to talk to OCC
            skip_occ_comm = true;
        }

        err = OccManager::buildOccs(false, skip_occ_comm);
        if (nullptr == err)
        {
            if ((i_cmdLength > 0) && (NULL != i_cmdData))
            {
                switch (i_cmdData[0])
                {
                    case PASSTHRU_OCC_STATUS:
                        TMGT_INF("passThruCommand: HTMGT/OCC Status");
                        if (safeMode == 0)
                        {
                            // Send poll to confirm comm, update states and
                            // flush errors
                            TMGT_INF("passThruCommand: Sending Poll(s)");
                            err = OccManager::sendOccPoll(true, nullptr);
                            if (err)
                            {
                                TMGT_ERR("passThruCommand: Poll OCCs failed.");
                                ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                            }
                        }
                        OccManager::getHtmgtData(o_rspLength, o_rspData);
                        break;

                    case PASSTHRU_INTERNAL_FLAG:
                        if (i_cmdLength == 1)
                        {
                            // get internal flag value
                            o_rspLength = 4;
                            UINT32_PUT(o_rspData, get_int_flags());
                        }
                        else if (i_cmdLength == 5)
                        {
                            // set internal flag value
                            TMGT_INF("passThruCommand: Updating internal flags "
                                    "from 0x%08X to 0x%08X",
                                    get_int_flags(), UINT32_GET(&i_cmdData[1]));
                            set_int_flags(UINT32_GET(&i_cmdData[1]));
                        }
                        else
                        {
                            TMGT_ERR("passThruCommand: invalid internal flag "
                                     "length %d", i_cmdLength);
                            failingSrc = HTMGT_RC_INVALID_LENGTH;
                        }
                        break;

                    case PASSTHRU_SEND_OCC_COMMAND:
                        if ((i_cmdLength >= 3) && (safeMode == 0))
                        {
                            const uint8_t occInstance = i_cmdData[1];
                            const occCommandType occCmd =
                                (occCommandType)i_cmdData[2];
                            const uint16_t dataLen = i_cmdLength-3;
                            Occ *occPtr = OccManager::getOcc(occInstance);
                            if (occPtr)
                            {
                                // Map HOMER for this OCC
                                TARGETING::Target* procTarget = nullptr;
                                procTarget = TARGETING::
                                    getImmediateParentByAffinity
                                    (occPtr->getTarget());
                                HBPM::ScopedHomerMapper l_mapper(procTarget);
                                err = l_mapper.map();
                                if (nullptr == err)
                                {
                                    occPtr->setHomerAddr
                                        (l_mapper.getHomerVirtAddr());

                                    TMGT_INF("passThruCommand: Send OCC%d "
                                             "command 0x%02X (%d bytes)",
                                             occInstance, occCmd, dataLen);
                                    OccCmd cmd(occPtr, occCmd, dataLen,
                                               &i_cmdData[3]);
                                    err = cmd.sendOccCmd();
                                    if (err != NULL)
                                    {
                                        TMGT_ERR("passThruCommand: OCC%d cmd "
                                                 "0x%02X failed with rc 0x%04X",
                                                 occInstance, occCmd,
                                                 err->reasonCode());
                                    }
                                    else
                                    {
                                        uint8_t *rspPtr = NULL;
                                        o_rspLength = cmd.getResponseData(rspPtr);
                                        memcpy(o_rspData, rspPtr, o_rspLength);
                                        TMGT_INF("passThruCommand: OCC%d rsp status "
                                                 "0x%02X (%d bytes)", occInstance,
                                                 o_rspData[2], o_rspLength);
                                    }
                                    occPtr->invalidateHomer();
                                }
                                else
                                {
                                    TMGT_ERR("passThruCommand: Unable to get HOMER "
                                             "virtual address for OCC%d (rc=0x%04X)",
                                             occInstance, err->reasonCode());
                                    err->collectTrace("HTMGT");
                                }
                            }
                            else
                            {
                                TMGT_ERR("passThruCommand: Unable to find OCC%d",
                                         occInstance);
                                /*@
                                 * @errortype
                                 * @reasoncode   HTMGT_RC_OCC_UNAVAILABLE
                                 * @moduleid     HTMGT_MOD_PASS_THRU
                                 * @userdata1    command data[0-7]
                                 * @userdata2    command data length
                                 * @devdesc      Specified OCC not available
                                 * @custdesc     An internal firmware error occurred
                                 */
                                failingSrc = HTMGT_RC_OCC_UNAVAILABLE;
                            }
                        }
                        else
                        {
                            if (safeMode)
                            {
                                TMGT_ERR("passThruCommand: Ignoring OCC command"
                                         " because system is in safe mode");
                                failingSrc = HTMGT_RC_OCC_CRIT_FAILURE;
                            }
                            else
                            {
                                TMGT_ERR("passThruCommand: Invalid OCC command "
                                         "length %d", i_cmdLength);
                                failingSrc = HTMGT_RC_INVALID_LENGTH;
                            }
                        }
                        break;

                    case PASSTHRU_CLEAR_RESET_COUNTS:
                        TMGT_INF("passThruCommand: Clear all OCC reset counts");
                        if (safeMode == 0)
                        {
                            OccManager::clearResetCounts();
                        }
                        else
                        {
                            TMGT_ERR("passThruCommand: Clear ignored because "
                                     "system is in safe mode");
                            failingSrc = HTMGT_RC_OCC_CRIT_FAILURE;
                        }
                        break;

                    case PASSTHRU_EXIT_SAFE_MODE:
                        TMGT_INF("passThruCommand: Clear Safe Mode");
                        if (safeMode)
                        {
                            // Clear safe mode reason
                            OccManager::updateSafeModeReason(0, 0);
                            // Clear system safe mode flag/attribute
                            if(sys)
                            {
                                safeMode = 0;
                                sys->setAttr<TARGETING::ATTR_HTMGT_SAFEMODE>
                                    (safeMode);
                            }
                            // Clear OCC reset counts and failed flags
                            OccManager::clearResetCounts();
                            // Reset the OCCs (do not increment reset count
                            // or attempt comm with OCC since they are in reset)
                            TMGT_INF("passThruCommand: Calling resetOccs");
                            err = OccManager::resetOccs(NULL, true, true);
                            if (err != NULL)
                            {
                                TMGT_ERR("passThruCommand: Exit Save Mode "
                                         "resetOccs failed with rc 0x%04X",
                                         err->reasonCode());
                            }
                        }
                        else
                        {
                            TMGT_ERR("passThruCommand: Clear ignored, "
                                     "system is NOT in safe mode");
                            failingSrc=HTMGT_RC_PRESENT_STATE_PROHIBITS;
                        }
                        break;

                    case PASSTHRU_RESET_PM_COMPLEX:
                        TMGT_INF("passThruCommand: Reset PM Complex");
                        if (safeMode == 0)
                        {
                            // Will not increment reset count or attempt comm
                            err = OccManager::
                                resetOccs(nullptr, true, true,
                                          OCC_RESET_REASON_EXTERNAL_REQUEST);
                            if(err)
                            {
                                TMGT_ERR("passThruCommand: Reset PM Complex "
                                         "FAIL with rc 0x%04X",
                                         err->reasonCode());
                            }
                        }
                        else
                        {
                            TMGT_ERR("passThruCommand: Ignoring reset because "
                                     "system is in safe mode");
                            failingSrc = HTMGT_RC_OCC_CRIT_FAILURE;
                        }
                        break;

                    case PASSTHRU_ENA_DIS_OPAL_STATE:
                        TMGT_INF("passThruCommand: set OPAL state(%d)",
                                 i_cmdData[1]);
                        if ((i_cmdLength == 2) && (safeMode == 0))
                        {
                            //0 = disable OPAL mode (i.e. run as PowerVM)
                            if (i_cmdData[1] == 0)
                            {
                                G_system_type = OCC_CFGDATA_OPENPOWER_POWERVM;
                            }
                            //1 = enable OPAL mode
                            else if (i_cmdData[1] == 1)
                            {
                                G_system_type = OCC_CFGDATA_OPENPOWER_OPALVM;
                            }
                            else
                            {
                                TMGT_ERR("passThruCommand: Invalid requested "
                                         "OPAL mode 0x%02X ", i_cmdData[1] );
                                /*@
                                 * @errortype
                                 * @reasoncode   HTMGT_RC_INVALID_PARAMETER
                                 * @moduleid     HTMGT_MOD_PASS_THRU
                                 * @userdata1    command data[0-7]
                                 * @userdata2    command data length
                                 * @devdesc      Invalid pass thru command data
                                 * @custdesc     An internal firmware error occurred
                                 */
                                failingSrc = HTMGT_RC_INVALID_PARAMETER;
                            }
                            if(failingSrc == HTMGT_RC_NO_ERROR)
                            {
                                TMGT_INF("passThruCommand: OPAL State(0x%02X), "
                                         "resetting PM Complex", G_system_type);
                                err = OccManager::resetOccs(nullptr,true,true,
                                             OCC_RESET_REASON_EXTERNAL_REQUEST);
                                if(err)
                                {
                                    TMGT_ERR("passThruCommand: PM Complex Reset"
                                             " failed with rc 0x%04X after "
                                             "updating OPAL state",
                                             err->reasonCode());
                                }
                            }
                        }
                        else
                        {
                            if (safeMode)
                            {
                                TMGT_ERR("passThruCommand: Ignoring Opal state"
                                         " because system is in safe mode");
                                failingSrc = HTMGT_RC_OCC_CRIT_FAILURE;
                            }
                            else
                            {
                                TMGT_ERR("passThruCommand: Invalid command "
                                         "length %d", i_cmdLength);
                                failingSrc = HTMGT_RC_INVALID_LENGTH;
                            }
                        }
                        break;

                    case PASSTHRU_SET_OCC_STATE:
                        TMGT_INF("passThruCommand: Set OCC State(%d)",
                                 i_cmdData[1]);
                        if ((i_cmdLength == 2) && (safeMode == 0))
                        {
                            occStateId l_targetState = (occStateId)i_cmdData[1];
                            //Validate state requested is supported.
                            if( (l_targetState == OCC_STATE_OBSERVATION) ||
                                (l_targetState == OCC_STATE_ACTIVE) ||
                                (l_targetState == OCC_STATE_CHARACTERIZATION) )
                            {
                                // Set state for all OCCs
                                err = OccManager::setOccState(l_targetState);
                                if (nullptr == err)
                                {
                                    TMGT_INF("passThruCommand: OCC states "
                                             "updated to 0x%02X",
                                             l_targetState);
                                }
                                else
                                {
                                    TMGT_ERR("passThruCommand: OCC state change"
                                             " FAIL with rc 0x%04X",
                                             err->reasonCode());
                                }
                            }
                            else
                            {
                                TMGT_ERR("passThruCommand: Invalid requested "
                                         "state 0x%08X ", l_targetState );
                                failingSrc = HTMGT_RC_INVALID_PARAMETER;
                            }
                        }
                        else
                        {
                            if (safeMode)
                            {
                                TMGT_ERR("passThruCommand: Ignoring set state"
                                         " because system is in safe mode");
                                failingSrc = HTMGT_RC_OCC_CRIT_FAILURE;
                            }
                            else
                            {
                                TMGT_ERR("passThruCommand: Invalid command "
                                         "length %d", i_cmdLength);
                                failingSrc = HTMGT_RC_INVALID_LENGTH;
                            }
                        }
                        break;


                    case PASSTHRU_WOF_RESET_REASONS:
                        TMGT_INF("passThruCommand: Query WOF Reset Reasons");
                        OccManager::getWOFResetReasons(o_rspLength, o_rspData);
                        break;


                    case PASSTHRU_OCC_CFG_DATA:
                        if (i_cmdLength == 3)
                        {
                            const uint8_t occInstance = i_cmdData[1];
                            const uint8_t format = i_cmdData[2];
                            Occ *occPtr = OccManager::getOcc(occInstance);
                            if (occPtr)
                            {
                                TMGT_INF("passThruCommand: OCC%d config format "
                                         "0x%02X",
                                         occInstance, format);
                                readConfigData(occPtr, format,
                                               o_rspLength, o_rspData);
                            }
                            else
                            {
                                TMGT_ERR("passThruCommand: Unable to find "
                                         "OCC%d", occInstance);
                                failingSrc = HTMGT_RC_OCC_UNAVAILABLE;
                            }
                        }
                        else
                        {
                            TMGT_ERR("passThruCommand: Invalid command "
                                     "length %d", i_cmdLength);
                            failingSrc = HTMGT_RC_INVALID_LENGTH;
                        }
                        break;


                    case PASSTHRU_SET_MODE:
                        TMGT_ERR("passThruCommand: Set Mode not supported");
                        /*@
                         * @errortype
                         * @reasoncode   HTMGT_RC_NO_SUPPORT
                         * @moduleid     HTMGT_MOD_PASS_THRU
                         * @userdata1    command data[0-7]
                         * @userdata2    command data length
                         * @devdesc      SET_MODE not supported (use BMC)
                         * @custdesc     An internal firmware error occurred
                         */
                        failingSrc = HTMGT_RC_NO_SUPPORT;
                        break;


                    case PASSTHRU_QUERY_MODE_FUNCTION:
                        TMGT_INF("passThruCommand: Query Mode and Function");
                        OccManager::queryModeAndFunction(o_rspLength, o_rspData);
                        break;


                    default:
                        TMGT_ERR("passThruCommand: Invalid command 0x%08X "
                              "(%d bytes)", UINT32_GET(i_cmdData), i_cmdLength);
                        /*@
                         * @errortype
                         * @reasoncode   HTMGT_RC_INVALID_DATA
                         * @moduleid     HTMGT_MOD_PASS_THRU
                         * @userdata1    command data[0-7]
                         * @userdata2    command data length
                         * @devdesc      Invalid pass thru command
                         * @custdesc     An internal firmware error occurred
                         */
                        failingSrc = HTMGT_RC_INVALID_DATA;
                        break;
                }

                if ((HTMGT_RC_NO_ERROR != failingSrc) && (NULL == err))
                {
                    bldErrLog(err, HTMGT_MOD_PASS_THRU,
                              failingSrc,
                              UINT32_GET(i_cmdData),
                              UINT32_GET(&i_cmdData[4]),
                              0, i_cmdLength,
                              ERRORLOG::ERRL_SEV_INFORMATIONAL);
                }
            }
        }
        TMGT_INF("<<passThruCommand() returning %d bytes (err=0x%04X)",
                 o_rspLength, (err==nullptr) ? 0 : err->reasonCode());

        return err;

    } // end passThruCommand()

    // Called by PLDM to get OCC enabled status for the BMC
    bool isOccRunning(TARGETING::Target * i_proc)
    {
        bool isRunning = false;

        // Query the PM_COMPLEX_LOAD_REQ to indicate if OCCs are loaded.
        // DO_NOT_LOAD indicates OCCs are loaded and the buildOCCs should
        // succeed, so try the poll.
        TARGETING::Target* l_sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(l_sys);
        if ((l_sys->getAttr<ATTR_PM_COMPLEX_LOAD_REQ>()) == PM_COMPLEX_LOAD_TYPE_DO_NOT_LOAD)
        {
            // If hostboot gets restarted, HTMGT will not have been called
            // so need to call buildOccs (no-op if objects already exist)
            errlHndl_t err = OccManager::buildOccs(false, false);
            if (nullptr == err)
            {
                // check if the OCCs are actually running
                if (OccManager::occNeedsReset() == false)
                {
                    uint8_t occInstance = i_proc->getAttr<TARGETING::ATTR_POSITION>();
                    Occ *occPtr = OccManager::getOcc(occInstance);
                    if (occPtr != nullptr)
                    {
                        const occStateId occState = occPtr->getState();
                        if( (occState == OCC_STATE_OBSERVATION) ||
                            (occState == OCC_STATE_ACTIVE) ||
                            (occState == OCC_STATE_CHARACTERIZATION) )
                        {
                            isRunning = true;
                        }
                    }
                }
            }
            else
            {
                // OCCs not started yet
                delete err;
            }
        }

        return isRunning;
    }
}
