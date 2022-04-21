/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/responses/pldm_discovery_control_responders.H $ */
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

/* @file  pldm_discovery_control_responders.H
 *
 * @brief Interface of the PLDM Discovery Control Commands message handlers,
 *        (see DSP0240 v1.0.0 for details).
 */

#ifndef PLDM_DISCOVERY_CONTROL_RESPONDERS_H__
#define PLDM_DISCOVERY_CONTROL_RESPONDERS_H__

#include <sys/msg.h>        // msg_q_t
#include <errl/errlentry.H> // errlHndl_t
#include <pldm/pldmif.H>
#include <mctp/mctp_message_types.H>

struct pldm_msg;

namespace PLDM
{

/* Platform Level Data Model (PLDM) Base Specification
 *
 * https://www.dmtf.org/dsp/DSP0240
 *
 * See section 7 - PLDM Messaging Control and Discovery Commands
 */

/* @brief handleGetPldmVersionRequest
 *
 *        Handler for intercepting the getPLDMVersion requests.
 *
 * @param[in] i_msgQ          Handle to the MCTP outbound message queue
 * @param[in] i_msg           getPLDMVersion request message object
 * @return    errlHndl_t      Error if any, otherwise nullptr.
 */
errlHndl_t handleGetPldmVersionRequest(MCTP::mctp_outbound_msgq_t i_msgQ,
                                       const pldm_mctp_message& i_msg);

/* @brief handleUnsupportedCommandRequest
 *
 *        Handler for intercepting ANY Unsupported requests.
 *
 * @param[in] i_msgQ          Handle to the MCTP outbound message queue
 * @param[in] i_msg           Request message object
 * @return    errlHndl_t      Error if any, otherwise nullptr.
 */
errlHndl_t handleUnsupportedCommandRequest(MCTP::mctp_outbound_msgq_t i_msgQ,
                                           const pldm_mctp_message& i_msg);

} // namespace PLDM

#endif // #ifndef PLDM_DISCOVERY_CONTROL_RESPONDERS_H__
