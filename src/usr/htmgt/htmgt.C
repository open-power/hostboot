/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt.C $                                       */
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
#include "htmgt_activate.H"
#include "htmgt_cfgdata.H"
#include "htmgt_utility.H"
#include "genPstate.H"
#include "htmgt_memthrottles.H"
#include "htmgt_poll.H"
#include <devicefw/userif.H>
#include <config.h>
#include <console/consoleif.H>

//  Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>

// HBOCC support
#include <hwpf/hwp/occ/occ_common.H>


#include <sys/time.h>

namespace HTMGT
{

    // Move the OCCs to active state or log unrecoverable error and
    // stay in safe mode
    void processOccStartStatus(const bool i_startCompleted,
                               TARGETING::Target * i_failedOccTarget)
    {
        TMGT_INF(">>processOccStartStatus(%d,0x%p)",
                 i_startCompleted, i_failedOccTarget);
        errlHndl_t l_err = NULL;
        uint32_t l_huid = 0;
        if (i_failedOccTarget)
        {
            l_huid = TARGETING::get_huid(i_failedOccTarget);
        }
        TMGT_INF("processOccStartStatus(Start Success=%c, failedOcc=0x%08X)",
                 i_startCompleted?'y':'n', l_huid);
        if (i_startCompleted)
        {
            // Query functional OCCs
            l_err = OccManager::buildOccs();
            if (NULL == l_err)
            {
                if (NULL != OccManager::getMasterOcc())
                {
                    do
                    {
#ifndef __HOSTBOOT_RUNTIME
                        // Build normal pstate tables (once per IPL)
                        l_err = genPstateTables(true);
                        if(l_err)
                        {
                            break;
                        }

                        // Calc memory throttles (once per IPL)
                        calcMemThrottles();
#endif

                        // Make sure OCCs are ready for communication
                        OccManager::waitForOccCheckpoint();

#ifdef __HOSTBOOT_RUNTIME
                        // TODO RTC 124738  Final solution TBD
                        //  Perhapse POLL scom 0x6a214 until bit 31 is set?
                        nanosleep(1,0);
#endif

                        // Send poll to establish comm
                        TMGT_INF("Send initial poll to all OCCs to"
                                 " establish comm");
                        l_err = OccManager::sendOccPoll();
                        if (l_err)
                        {
                            if (OccManager::occNeedsReset())
                            {
                                // No need to continue if a reset is required
                                TMGT_ERR("sendOccConfigData(): OCCs need to "
                                         "be reset");
                                break;
                            }
                            else
                            {
                                // Continue even if failed (will be retried)
                                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                            }
                        }

                        // Send ALL config data
                        sendOccConfigData();

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

                        // Set active sensors for all OCCs,
                        // so BMC can start communication with OCCs
                        l_err = setOccActiveSensors(true);
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
                // Set original error log  as unrecoverable and commit
                l_err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
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
             */
            bldErrLog(l_err, HTMGT_MOD_LOAD_START_STATUS,
                      HTMGT_RC_OCC_START_FAIL,
                      0, l_huid, 0, 0,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        if (NULL != l_err)
        {
            TMGT_ERR("OCCs not all active.  Attempting OCC Reset");
            TMGT_CONSOLE("OCCs are not active (rc=0x%04X). "
                         "Attempting OCC Reset",
                         l_err->reasonCode());
            TMGT_INF("Calling resetOccs");
            errlHndl_t err2 = OccManager::resetOccs(NULL);
            if(err2)
            {
                TMGT_ERR("OccManager::resetOccs failed with 0x%04X",
                         err2->reasonCode());

                // Set original error log  as unrecoverable and commit
                l_err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);

                // Commit occReset error
                ERRORLOG::errlCommit(err2, HTMGT_COMP_ID);
            }
            else
            {
                // retry worked - commit original error as informational
                l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
            }
        }
        TMGT_INF("<<processOccStartStatus()");

    } // end processOccStartStatus()



    // Notify HTMGT that an OCC has an error to report
    void processOccError(TARGETING::Target * i_procTarget)
    {
        TMGT_INF(">>processOccError(0x%p)", i_procTarget);

        TARGETING::Target* sys = NULL;
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

        bool polledOneOcc = false;
        errlHndl_t err = OccManager::buildOccs();
        if (NULL == err)
        {
            if (i_procTarget != NULL)
            {
                const uint32_t l_huid =
                    i_procTarget->getAttr<TARGETING::ATTR_HUID>();
                TMGT_INF("processOccError(HUID=0x%08X) called", l_huid);

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
                TMGT_ERR("processOccError(): OCCs need to be reset");
                // Don't pass failed target as OCC should have already
                // been marked as failed during the poll.
                errlHndl_t err = OccManager::resetOccs(NULL);
                if(err)
                {
                    ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                }
            }
        }
        else
        {
            // OCC build failed...
            TMGT_ERR("processOccError() called, but unable to find OCCs");
            ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
        }
        TMGT_INF("<<processOccError()");

    } // end processOccError()



    // Notify HTMGT that an OCC has failed and needs to be reset
    void processOccReset(TARGETING::Target * i_proc)
    {
        TMGT_INF(">>processOccReset(0x%p)", i_proc);
        errlHndl_t errl = NULL;
        TARGETING::Target * failedOccTarget = NULL;

        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        uint8_t safeMode = 0;

        // If the system is in safemode then ignore request to reset OCCs
        if(sys &&
           sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode) &&
           safeMode)
        {
            return;
        }

        // Get functional OCC (one per proc)
        TARGETING::TargetHandleList pOccs;
        getChildChiplets(pOccs, i_proc, TARGETING::TYPE_OCC);
        if (pOccs.size() > 0)
        {
            failedOccTarget = pOccs[0];
        }

        if(NULL != failedOccTarget)
        {
            uint32_t huid = failedOccTarget->getAttr<TARGETING::ATTR_HUID>();
            TMGT_INF("processOccReset(HUID=0x%08X) called", huid);
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
             */
            bldErrLog(errl,
                      HTMGT_MOD_PROCESS_OCC_RESET,
                      HTMGT_RC_INVALID_PARAMETER,
                      0, huid, 0, 1,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);

            // Add HB firmware callout
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_MED);
            ERRORLOG::errlCommit(errl, HTMGT_COMP_ID); // sets errl to NULL
        }

        errl = OccManager::resetOccs(failedOccTarget);
        if(errl)
        {
            ERRORLOG::errlCommit(errl, HTMGT_COMP_ID); // sets errl to NULL
        }
        TMGT_INF("<<processOccReset()");
    } // end processOccReset()



    // Set the OCC state
    errlHndl_t enableOccActuation(bool i_occActivation)
    {
        TMGT_INF(">>enableOccActuation(%c)", i_occActivation?'Y':'N');
        errlHndl_t l_err = NULL;
        TARGETING::Target* sys = NULL;

        // If the system is already in safemode then can't talk to OCCs
        TARGETING::targetService().getTopLevelTarget(sys);
        uint8_t safeMode = 0;
        if(sys)
        {
            sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
        }

        if (0 == safeMode)
        {
            occStateId targetState = OCC_STATE_ACTIVE;
            if (false == i_occActivation)
            {
                targetState = OCC_STATE_OBSERVATION;
            }

            // Set state for all OCCs
            l_err = OccManager::setOccState(targetState);
            if (NULL == l_err)
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
                l_err = OccManager::resetOccs(NULL);

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

        if ((NULL == l_err) && safeMode)
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
             */
            bldErrLog(l_err,
                      HTMGT_MOD_ENABLE_OCC_ACTUATION,
                      HTMGT_RC_OCC_CRIT_FAILURE,
                      i_occActivation, safeRc, safeMode, safeInstance,
                      ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        }

        TMGT_INF("<<enableOccActuation() returning 0x%04X",
                 (l_err==NULL) ? 0 : l_err->reasonCode());
        return l_err;

    } // end enableOccActuation()



    // Send pass-thru command to HTMGT
    errlHndl_t passThruCommand(uint16_t   i_cmdLength,
                               uint8_t *  i_cmdData,
                               uint16_t & o_rspLength,
                               uint8_t *  o_rspData)
    {
        errlHndl_t err = NULL;
        htmgtReasonCode failingSrc = HTMGT_RC_NO_ERROR;
        o_rspLength = 0;

        if ((i_cmdLength > 0) && (NULL != i_cmdData))
        {
            switch (i_cmdData[0])
            {
                case PASSTHRU_OCC_STATUS:
                    TMGT_INF("passThruCommand: OCC Status");
                    OccManager::getOccData(o_rspLength, o_rspData);
                    break;

                case PASSTHRU_GENERATE_MFG_PSTATE:
                    if (i_cmdLength == 1)
                    {
                        TMGT_INF("passThruCommand: Generate MFG pstate tables",
                                 i_cmdData[1]);
                        err = genPstateTables(false);
                    }
                    else
                    {
                        TMGT_ERR("passThruCommand: invalid generate pstate "
                                 "command length %d", i_cmdLength);
                        /*@
                         * @errortype
                         * @reasoncode   HTMGT_RC_INVALID_LENGTH
                         * @moduleid     HTMGT_MOD_PASS_THRU
                         * @userdata1    command data[0-7]
                         * @userdata2    command data length
                         * @devdesc      Invalid pass thru command data length
                         */
                        failingSrc = HTMGT_RC_INVALID_LENGTH;
                    }
                    break;

                case PASSTHRU_LOAD_PSTATE:
                    if (i_cmdLength == 2)
                    {
                        const uint8_t pstateType = i_cmdData[1];
                        if ((0 == pstateType) || (1 == pstateType))
                        {
                            TMGT_INF("passThruCommand: Load pstate tables "
                                     "(type: %d)", pstateType);
                            // 0 = Normal Pstate Tables
                            err = OccManager::loadPstates(0 == pstateType);
                        }
                        else
                        {
                            TMGT_ERR("passThruCommand: invalid pstate type "
                                     "specified: %d", pstateType);
                            /*@
                             * @errortype
                             * @reasoncode   HTMGT_RC_INVALID_PARAMETER
                             * @moduleid     HTMGT_MOD_PASS_THRU
                             * @userdata1    command data[0-7]
                             * @userdata2    command data length
                             * @devdesc      Invalid load pstate table type
                             */
                            failingSrc = HTMGT_RC_INVALID_PARAMETER;
                        }
                    }
                    else
                    {
                        TMGT_ERR("passThruCommand: invalid load pstate "
                                 "command length %d", i_cmdLength);
                        failingSrc = HTMGT_RC_INVALID_LENGTH;
                    }
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

        return err;

    } // end passThruCommand()


}

