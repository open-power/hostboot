/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_poll.C $                                  */
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
#include "htmgt_activate.H"
#include "htmgt_poll.H"
#include "htmgt_occcmd.H"
#include "htmgt_cfgdata.H"
#include "occError.H"
#include <console/consoleif.H>

//  Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>


namespace HTMGT
{

    errlHndl_t OccManager::_sendOccPoll(const bool i_flushAllErrors,
                                        TARGETING::Target * i_occTarget)
    {
        errlHndl_t err = NULL;

        TMGT_INF("sendOccPoll(flush=%c)", i_flushAllErrors?'y':'n');

        for(occList_t::const_iterator occ_itr = iv_occArray.begin();
            (occ_itr != iv_occArray.end()) && (NULL == err);
            ++occ_itr)
        {
            Occ * occ = *occ_itr;
            if(NULL == i_occTarget || occ->iv_target == i_occTarget)
            {
                err = occ->pollForErrors(i_flushAllErrors);
            }
        }

        if (occNeedsReset())
        {
            TMGT_ERR("_sendOccPoll(): OCCs need to be reset");
        }

        return err;
    }


    errlHndl_t OccManager::sendOccPoll(const bool i_flushAllErrors,
                                       TARGETING::Target * i_occTarget)
    {
        return
            Singleton<OccManager>::instance()._sendOccPoll(i_flushAllErrors,
                                                           i_occTarget);
    }


    errlHndl_t Occ::pollForErrors(const bool i_flushAllErrors)
    {
        errlHndl_t err = NULL;
        uint8_t * poll_rsp = NULL;

        // Only send poll if OCC has not logged an exception
        if (0 == iv_exceptionLogged)
        {
            TMGT_INF("sendOccPoll: Polling OCC%d", iv_instance);
            bool continuePolling = false;
            size_t elogCount = 10;

            do
            {
                // create 1 byte buffer for poll command data
                const uint8_t l_cmdData[1] = { 0x10 /*version*/ };

                OccCmd cmd(this,
                           OCC_CMD_POLL,
                           sizeof(l_cmdData),
                           l_cmdData);

                err = cmd.sendOccCmd();
                if (err != NULL)
                {
                    // Poll failed
                    TMGT_ERR("sendOccPoll: OCC%d poll failed with rc=0x%04X",
                             iv_instance,
                             err->reasonCode());

                    continuePolling = false;
                }
                else
                {
                    // Poll succeeded, check response
                    uint32_t poll_rsp_size = cmd.getResponseData(poll_rsp);
                    if (poll_rsp_size >= OCC_POLL_DATA_MIN_SIZE)
                    {
                        if (i_flushAllErrors)
                        {
                            const occPollRspStruct_t *currentPollRsp =
                                (occPollRspStruct_t *) poll_rsp;
                            if (currentPollRsp->errorId != 0)
                            {
                                if (--elogCount > 0)
                                {
                                    // An error was returned, keep polling OCC
                                    continuePolling = true;
                                }
                                else
                                {
                                    // Limit number of elogs retrieved so
                                    // we do not get stuck in loop
                                    TMGT_INF("sendOccPoll: OCC%d still has"
                                             "more errors to report.",
                                             iv_instance);
                                    continuePolling = false;
                                }
                            }
                            else
                            {
                                continuePolling = false;
                            }
                        }
                        pollRspHandler(poll_rsp, poll_rsp_size);
                    }
                    else
                    {
                        TMGT_ERR("sendOccPoll: OCC%d poll command response "
                                 "failed with invalid data length %d",
                                 iv_instance, poll_rsp_size);
                        /*@
                         * @errortype
                         * @reasoncode HTMGT_RC_INVALID_LENGTH
                         * @moduleid  HTMGT_MOD_OCC_POLL
                         * @userdata1 OCC instance
                         * @devdesc Invalid POLL response length
                         */
                        bldErrLog(err,
                                  HTMGT_MOD_OCC_POLL,
                                  HTMGT_RC_INVALID_LENGTH,
                                  iv_instance, 0, 0, 0,
                                  ERRORLOG::ERRL_SEV_INFORMATIONAL);

                        continuePolling = false;
                    }
                }
            }
            while (continuePolling);
        }

        return err;
    }


    // Handle OCC poll response
    void Occ::pollRspHandler(const uint8_t * i_pollResponse,
                             const uint16_t i_pollResponseSize)
    {
        static uint32_t L_elog_retry_count = 0;
        TMGT_DBG("OCC Poll Response", i_pollResponse, i_pollResponseSize);

        const occPollRspStruct_t *pollRsp =
            (occPollRspStruct_t *) i_pollResponse;
        const occPollRspStruct_t *lastPollRsp =
            (occPollRspStruct_t *) iv_lastPollResponse;

        // Trace if any data changed
        if ((false == iv_lastPollValid) ||
            (memcmp(pollRsp,
                    lastPollRsp,
                    OCC_POLL_DATA_MIN_SIZE) != 0))
        {
            TMGT_INF("OCC%d Poll change: Status:%04X Occs:%02X Cfg:%02X "
                     "State:%02X Error:%06X/%08X",
                     iv_instance,
                     (pollRsp->status << 8) | pollRsp->extStatus,
                     pollRsp->occsPresent,
                     pollRsp->requestedCfg, pollRsp->state,
                     (pollRsp->errorId<<16) | pollRsp->errorLength,
                     pollRsp->errorAddress);
#ifdef CONFIG_CONSOLE_OUTPUT_OCC_COMM
            TMGT_CONSOLE("OCC%d Poll change: Status:%04X Occs:%02X Cfg:%02X "
                         "State:%02X Error:%06X/%08X",
                         iv_instance,
                         (pollRsp->status << 8) | pollRsp->extStatus,
                         pollRsp->occsPresent,
                         pollRsp->requestedCfg, pollRsp->state,
                         (pollRsp->errorId<<16) | pollRsp->errorLength,
                         pollRsp->errorAddress);
#endif
        }

        do
        {
            if (false == iv_commEstablished)
            {
                // 1st poll response, so comm has been established for this OCC
                iv_commEstablished = true;
                TMGT_INF("pollRspHandler: FW Level for OCC%d: %.16s",
                         iv_instance, pollRsp->codeLevel);
            }

            // Check for Error Logs
            if (pollRsp->errorId != 0)
            {
                if ((pollRsp->errorId != lastPollRsp->errorId) ||
                    (L_elog_retry_count < 3))

                {
                    if (pollRsp->errorId == lastPollRsp->errorId)
                    {
                        // Only retry same errorId a few times...
                        L_elog_retry_count++;
                        TMGT_ERR("pollRspHandler: Requesting elog 0x%02X"
                                 " (retry %d)",
                                 pollRsp->errorId, L_elog_retry_count);
                    }
                    else
                    {
                        L_elog_retry_count = 0;
                    }

                    // Handle a new error log from the OCC
                    occProcessElog(pollRsp->errorId,
                                   pollRsp->errorAddress,
                                   pollRsp->errorLength);
                    if (iv_needsReset)
                    {
                        // Update state if changed...
                        // (since dropping out of poll rsp handler)
                        if (iv_state != pollRsp->state)
                        {
                            iv_state = (occStateId)pollRsp->state;
                            TMGT_INF("pollRspHandler: updating OCC%d state"
                                     " to %s",
                                     iv_instance, state_string(iv_state));
                        }
                        break;
                    }
                }
            }

            if ((OCC_STATE_ACTIVE == pollRsp->state) ||
                (OCC_STATE_OBSERVATION == pollRsp->state))
            {
                errlHndl_t l_err = NULL;

                // Check role status
                if (((OCC_ROLE_SLAVE == iv_role) &&
                     ((pollRsp->status & OCC_STATUS_MASTER) != 0)) ||
                    ((OCC_ROLE_MASTER == iv_role) &&
                     ((pollRsp->status & OCC_STATUS_MASTER) == 0)))
                {
                    TMGT_ERR("pollRspHandler: OCC%d Status role mismatch"
                             " (role:0x%02X, status:0x%02X 0x%02X)",
                             iv_instance, iv_role, pollRsp->status,
                             pollRsp->extStatus);
                    iv_needsReset = true;
                    /*@
                     * @errortype
                     * @reasoncode HTMGT_RC_INVALID_ROLE
                     * @moduleid  HTMGT_MOD_OCC_POLL
                     * @userdata1[0-15] OCC instance
                     * @userdata[16-31] response state
                     * @userdata2[0-15] expected role
                     * @userdata2[16-31] response status byte
                     * @devdesc Invalid role is POLL response
                     */
                    bldErrLog(l_err, HTMGT_MOD_OCC_POLL,
                              HTMGT_RC_INVALID_ROLE,
                              iv_instance, pollRsp->state,
                              iv_role, pollRsp->status,
                              ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    iv_resetReason = OCC_RESET_REASON_ERROR;
                    break;
                }

                if (pollRsp->occsPresent != iv_occsPresent)
                {
                    TMGT_ERR("pollRspHandler: OCC%d present mismatch"
                             " (expected 0x%02X, but received 0x%02X)",
                             iv_instance, iv_occsPresent,
                             pollRsp->occsPresent);
                    iv_needsReset = true;
                    /*@
                     * @errortype
                     * @reasoncode HTMGT_RC_INVALID_DATA
                     * @moduleid  HTMGT_MOD_OCC_POLL
                     * @userdata1[0-15] OCC instance
                     * @userdata1[16-31] response OCC present
                     * @userdata2[0-15] expected OCC present
                     * @userdata2[16-31] response status byte
                     * @devdesc Invalid OCC present data in POLL response
                     */
                    bldErrLog(l_err, HTMGT_MOD_OCC_POLL,
                              HTMGT_RC_INVALID_DATA,
                              iv_instance, pollRsp->occsPresent,
                              iv_occsPresent, pollRsp->status,
                              ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    iv_resetReason = OCC_RESET_REASON_ERROR;
                }
            }

            if (pollRsp->requestedCfg != 0x00)
            {
                TMGT_INF("pollRspHandler: OCC%d is requesting cfg format"
                         " 0x%02X", iv_instance, pollRsp->requestedCfg);
            }

            // Check for state change
            if (iv_state != pollRsp->state)
            {
                iv_state = (occStateId)pollRsp->state;
                TMGT_INF("pollRspHandler: updating OCC%d state to %s",
                         iv_instance, state_string(iv_state));
            }

            // Copy rspData to lastPollResponse
            memcpy(iv_lastPollResponse, pollRsp, OCC_POLL_DATA_MIN_SIZE);
            iv_lastPollValid = true;
        }
        while(0);

        // NOTE: When breaking out of the above while loop, the new poll
        //       response is NOT copied to lastPollResponse (should only
        //       break when reset required)

        if (true == iv_needsReset)
        {
            // Save full poll response
            memcpy(iv_lastPollResponse, pollRsp, OCC_POLL_DATA_MIN_SIZE);
            iv_lastPollValid = true;
            iv_state = (occStateId)pollRsp->state;
        }

    } // end Occ::pollRspHandler()


} // end namespace



