/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pldm_watchdog.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
#include <pldm/extended/pldm_watchdog.H>
#include <pldm/pldm_trace.H>
#include <pldm/extended/pdr_manager.H>
#include <pldm/pldm_reasoncodes.H>
#include <sys/msg.h>
#include <sys/vfs.h>
#include <sys/sync.h>
#include <pldm/pldm_request.H>
#include <libpldm/platform.h>

/* @file pldm_watchdog.C
 *
 * @brief This file contains definitions of APIs related to PLDM watchdog
 *        function.
 */

namespace PLDM
{

const uint16_t DEFAULT_WATCHDOG_TIMEOUT_SEC = 10 * 60; // 10 min
const uint16_t HB_MIN_WATCHDOG_TIMEOUT_SEC = 15;
bool g_pldmWatchdogArmed = false;
uint16_t g_pldmWatchdogPeriodSec = DEFAULT_WATCHDOG_TIMEOUT_SEC;

errlHndl_t resetWatchdogTimer()
{
    errlHndl_t l_errl = nullptr;
    PLDM_INF(">>resetWatchdogTimer");

    do {
    // Watchdog is not armed, so no need to send the heartbeat
    if(!g_pldmWatchdogArmed)
    {
        PLDM_INF("resetWatchdogTimer: PLDM watchdog is not armed; not sending the heartbeat");
        break;
    }

#ifndef __HOSTBOOT_RUNTIME // No watchdog resets from HB at runtime
    // Sequence number increments monotonically and indicates to the BMC if
    // it missed a heartbeat or not.
    static uint8_t l_sequenceNumber = 0;
    uint8_t l_heartbeatElapsedData[2]{};
    l_heartbeatElapsedData[0] = PLDM_PLATFORM_EVENT_MESSAGE_FORMAT_VERSION; // formatVersion

    // We need to make sure that we send the BMC the correct sequence number.
    // To prevent possible race conditions for the sequence number, lock it
    // with a mutex while we're incrementing and sending it down.
    static mutex_t l_sequenceMutex = MUTEX_INITIALIZER;

    mutex_lock(&l_sequenceMutex);
    l_heartbeatElapsedData[1] = l_sequenceNumber++; // sequenceNumber

    std::vector<uint8_t>l_responseBytes;
    l_errl = sendrecv_pldm_request<PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES>(
                l_responseBytes,
                sizeof(l_heartbeatElapsedData),
                g_outboundPldmReqMsgQ,
                encode_platform_event_message_req,
                DEFAULT_INSTANCE_ID,
                PLDM_PLATFORM_EVENT_MESSAGE_FORMAT_VERSION,
                thePdrManager().hostbootTerminusId(),
                PLDM_HEARTBEAT_TIMER_ELAPSED_EVENT,
                l_heartbeatElapsedData,
                sizeof(l_heartbeatElapsedData));
    mutex_unlock(&l_sequenceMutex);
    if(l_errl)
    {
        PLDM_ERR("resetWatchdogTimer: Could not send message to BMC");
        break;
    }

    pldm_platform_event_message_resp l_resp {};

    l_errl = decode_pldm_response(decode_platform_event_message_resp,
                                  l_responseBytes,
                                  &l_resp.completion_code,
                                  &l_resp.platform_event_status);
    if(l_errl)
    {
        PLDM_ERR("resetWatchdogTimer: Could not decode BMC's response");
        break;
    }

    if(l_resp.completion_code != PLDM_SUCCESS)
    {
        PLDM_ERR("resetWatchdogTimer: PLDM op returned code %d", l_resp.completion_code);
        /*@
         * @errortype
         * @moduleid MOD_RESET_WATCHDOG_TIMER
         * @reasoncode RC_BAD_COMPLETION_CODE
         * @userdata1 Completion code
         * @devdesc BMC responded with a bad return code to the heartbeat timer
         *          elapsed event.
         * @custdesc A software error occurred during system boot
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_RESET_WATCHDOG_TIMER,
                                         RC_BAD_COMPLETION_CODE,
                                         l_resp.completion_code,
                                         0,
                                         ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(l_errl);
        break;
    }
#endif

    } while(0);

    if(l_errl)
    {
        PLDM_ERR("resetWatchdogTimer: an error occurred; disabling the watchdog.");
        g_pldmWatchdogArmed = false;
    }

    PLDM_INF("<<resetWatchdogTimer");
    return l_errl;
}

} // namespace PLDM
