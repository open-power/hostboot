/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/responses/pldm_oem_responders.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
#ifndef PLDM_OEM_RESPONDERS_H
#define PLDM_OEM_RESPONDERS_H

/* @file pldm_oem_responders.H
 *
 * This file contains the PLDM responders for the OEM message category
 *
 */

#include <sys/msg.h>        // msg_q_t
#include <errl/errlentry.H> // errlHndl_t
#include <pldm/pldmif.H>
#include <mctp/mctp_message_types.H>

namespace PLDM
{
/* @brief handleGetPldmAttrDumpRequest
 *
 *        Handler for intercepting the attribute dump requests from BMC.
 *
 * @param[in] i_msgQ          Handle to the MCTP outbound message queue
 * @param[in] i_msg           Request message object
 * @return    errlHndl_t      Error if any, otherwise nullptr.
 */
errlHndl_t handleGetPldmAttrDumpRequest(MCTP::mctp_outbound_msgq_t i_msgQ,
                                        const pldm_mctp_message& i_msg);

} // namespace PLDM
#endif
