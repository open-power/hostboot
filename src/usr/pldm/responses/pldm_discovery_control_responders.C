/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/responses/pldm_discovery_control_responders.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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

/* @file pldm_discovery_control_responders.C
 *
 * @brief Implementation of the PLDM Discovery Control Commands message handlers.
 */


#include <pldm/responses/pldm_discovery_control_responders.H>
#include <pldm/pldm_trace.H>    // PLDM_INF
#include <libpldm/base.h>       // PLDM_ERROR_UNSUPPORTED_PLDM_CMD
#include <pldm/pldm_response.H> // send_cc_only_response
#include <sys/misc.h>           // SHUTDOWN_STATUS_PLDM_RESET_DETECTED
#include <initservice/initserviceif.H> // INITSERVICE::doShutdown
#include <targeting/common/targetservice.H> // TARGETING::UTIL::assertGetToplevelTarget

namespace PLDM
{

errlHndl_t handleGetPldmVersionRequest(const msg_q_t i_msgQ,
                                       const pldm_msg* const i_msg,
                                       const size_t i_payload_len)
{
    errlHndl_t l_err(nullptr);

    PLDM_INF("Received a getPLDMVersion Request message");

    // Reply to request to avoid multiple getPLDMVersion requests.
    // Not interested in the request per se, but using the request
    // to indicate that the PLDM daemon has been restarted therefore
    // sending back 'unsupported'.
    send_cc_only_response(i_msgQ, i_msg, PLDM_ERROR_UNSUPPORTED_PLDM_CMD);

#ifndef __HOSTBOOT_RUNTIME
    // Determine if HB has started a critical PLDM exchange with the BMC. If so then
    // receiving this message can be disruptive to HB and is cause for HB to shut down.
    const auto l_criticalExchangeCommencing = TARGETING::UTIL::assertGetToplevelTarget()->
         getAttr<TARGETING::ATTR_HALT_ON_BMC_PLDM_RESET>();
    if ( l_criticalExchangeCommencing )
    {
        // Receiving a getPLDMVersion request is indicative of the PLDM daemon being
        // restarted/reloaded which will reset the HB PLDM sequencing *after* a
        // critical PLDM exchange with the BMC has started (an example of a
        // critical exchange is the exchange of the PDRs).
        // Resetting the sequencing will cause issues for HB which are hard to
        // recover from, so instead of attempting recovery, HB will shut down.
        bool l_runInBackground(true);
        INITSERVICE::doShutdown(SHUTDOWN_STATUS_PLDM_RESET_DETECTED, l_runInBackground);
    }
#endif

    return l_err;
}

errlHndl_t handleUnsupportedCommandRequest(const msg_q_t i_msgQ,
                               const pldm_msg* const i_msg,
                               const size_t i_payload_len)
{
    errlHndl_t l_err(nullptr);

    /* See pldm_responder.C pldm_discovery_control_handlers */
    /* Curent list of Handlers -> GET_TID GET_PLDM_TYPES GET_PLDM_COMMANDS */
    PLDM_INF("Received Unsupported Command Request i_msg->hdr.type=0x%02x "
             "i_msg->hdr.command=0x%02x i_msg->hdr.instance_id=%d",
              i_msg->hdr.type, i_msg->hdr.command, i_msg->hdr.instance_id);

    // Reply to request to indicate 'unsupported'.
    send_cc_only_response(i_msgQ, i_msg, PLDM_ERROR_UNSUPPORTED_PLDM_CMD);

    return l_err;
}

} // namespace PLDM
