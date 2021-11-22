/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/responses/pldm_discovery_control_responders.H $ */
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

/* @file  pldm_discovery_control_responders.H
 *
 * @brief Interface of the PLDM Discovery Control Commands message handlers,
 *        (see DSP0240 v1.0.0 for details).
 */

#ifndef PLDM_DISCOVERY_CONTROL_RESPONDERS_H__
#define PLDM_DISCOVERY_CONTROL_RESPONDERS_H__

#include <sys/msg.h>        // msg_q_t
#include <errl/errlentry.H> // errlHndl_t

struct pldm_msg;

namespace PLDM
{

/* @brief handleGetPldmVersionRequest
 *
 *        Handler for intercepting the getPLDMVersion requests. (See DSP0240 v1.0.0
 *        section 7.2 for details.)
 *
 * @param[in] i_msgQ          Handle to the MCTP outbound message queue
 * @param[in] i_msg           getPLDMVersion request message object
 * @param[in] i_payload_len   Length of payload in i_msg
 * @return    errlHndl_t      Error if any, otherwise nullptr.
 */
errlHndl_t handleGetPldmVersionRequest( msg_q_t i_msgQ,
                                        const pldm_msg* i_msg,
                                        size_t i_payload_len);

} // namespace PLDM

#endif // #ifndef PLDM_DISCOVERY_CONTROL_RESPONDERS_H__
