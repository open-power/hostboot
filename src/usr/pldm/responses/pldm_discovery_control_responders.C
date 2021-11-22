/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/responses/pldm_discovery_control_responders.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

namespace PLDM
{

errlHndl_t handleGetPldmVersionRequest(const msg_q_t i_msgQ,
                                       const pldm_msg* const i_msg,
                                       const size_t i_payload_len)
{
    errlHndl_t l_err(nullptr);

    PLDM_INF("Received a getPLDMVersion message");

    // Reply to request to avoid multiple getPLDMVersion requests.
    // Not interested in the request per se, but using the request
    // to indicate that the PLDM daemon has been restarted therefore
    // sending back 'unsupported'.
    send_cc_only_response(i_msgQ, i_msg, PLDM_ERROR_UNSUPPORTED_PLDM_CMD);

    return l_err;
}


} // namespace PLDM
