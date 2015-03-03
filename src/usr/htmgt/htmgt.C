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
#ifndef __HOSTBOOT_RUNTIME
#include "genPstate.H"
#endif
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
            const uint8_t numOccs = OccManager::buildOccs();
            if (numOccs > 0)
            {
                if (NULL != OccManager::getMasterOcc())
                {
                    do
                    {
#ifndef __HOSTBOOT_RUNTIME
                        // Build pstate tables (once per IPL)
                        l_err = genPstateTables();
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
                            // Continue even if failed (poll will be retried)
                            ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
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
                     * @userdata1[0:7]  number of OCCs
                     * @devdesc         No OCC master was found
                     */
                    bldErrLog(l_err, HTMGT_MOD_LOAD_START_STATUS,
                              HTMGT_RC_OCC_MASTER_NOT_FOUND,
                              numOccs, 0, 0, 0,
                              ERRORLOG::ERRL_SEV_INFORMATIONAL);
                }
            }
            else
            {
                TMGT_ERR("Unable to find any functional OCCs");
                /*@
                 * @errortype
                 * @reasoncode      HTMGT_RC_OCC_UNAVAILABLE
                 * @moduleid        HTMGT_MOD_LOAD_START_STATUS
                 * @userdata1[0:7]  load/start completed
                 * @devdesc         No functional OCCs were found
                 */
                bldErrLog(l_err, HTMGT_MOD_LOAD_START_STATUS,
                          HTMGT_RC_OCC_UNAVAILABLE,
                          i_startCompleted, 0, 0, 0,
                          ERRORLOG::ERRL_SEV_INFORMATIONAL);
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
                      l_huid, 0, 0, 0,
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
                TMGT_ERR("OccManager:;resetOccs failed with 0x%04X",
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

    } // end processOccStartStatus()



    // Notify HTMGT that an OCC has an error to report
    void processOccError(TARGETING::Target * i_procTarget)
    {
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
        OccManager::buildOccs();

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

    } // end processOccError()



    // Notify HTMGT that an OCC has failed and needs to be reset
    void processOccReset(TARGETING::Target * i_proc)
    {
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
             * @userdata1[0:7]  Processor HUID
             * @devdesc         No OCC target found for proc Target,
             */
            bldErrLog(errl,
                      HTMGT_MOD_PROCESS_OCC_RESET,
                      HTMGT_RC_INVALID_PARAMETER,
                      huid, 0, 0, 1,
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
    } // end processOccReset()



    // Set the OCC state
    errlHndl_t enableOccActuation(bool i_occActivation)
    {
        errlHndl_t l_err = NULL;
        TARGETING::Target* sys = NULL;

        TARGETING::targetService().getTopLevelTarget(sys);
        uint8_t safeMode = 0;

        // If the system is in safemode then can't talk to OCCs -
        // ignore call to enableOccActuation
        if(sys &&
           sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode) &&
           safeMode)
        {
            /*@
             * @errortype
             * @reasoncode      HTMGT_RC_OCC_CRIT_FAILURE
             * @moduleid        HTMGT_MOD_ENABLE_OCC_ACTUATION
             * @userdata1[0:7]  OCC activate [1==true][0==false]
             * @devdesc         Invalid operation when OCCs are in safemode
             */
            bldErrLog(l_err,
                      HTMGT_MOD_ENABLE_OCC_ACTUATION,
                      HTMGT_RC_OCC_CRIT_FAILURE,
                      i_occActivation, 0, 0, 1,
                      ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        }
        else
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
                TMGT_ERR("enableOccActuation(): OCCs need to be reset");
                // Don't pass failed target as OCC should have already
                // been marked as failed during the poll.
                errlHndl_t err2 = OccManager::resetOccs(NULL);
                if(err2)
                {
                    ERRORLOG::errlCommit(err2, HTMGT_COMP_ID);
                }
            }
        }

        return l_err;

    } // end enableOccActuation()


}

