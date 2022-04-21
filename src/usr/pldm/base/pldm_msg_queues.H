/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_msg_queues.H $                         */
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

/**
 * @file pldm_msg_queues.H
 *
 * @brief Provide interface for pldm_base_init to call into which will
 *        register all of the messages queues associated with PLDM
 */

#ifndef PLDM_MSG_QUEUES_H
#define PLDM_MSG_QUEUES_H

#include <util/typed_msg.H>
#include <pldm/pldmif.H>

namespace PLDM
{
/*
 * @brief This function will register the pldm message queues that
 *        get instantiated in pldm_msg_queues.C with their corresponding
 *        const str values defined in vfs_main.C. This allows external modules
 *        to easily resolve these queues
 *
 * @return void
*/
void registerPldmMsgQs(void);

extern Util::unipipe<pldm_mctp_message> g_inboundPldmRspMsgQ; // pldm inbound response msgQ
extern Util::unipipe<pldm_mctp_message> g_inboundPldmReqMsgQ; // pldm inbound request msgQ
extern Util::bipipe<MCTP::outgoing_mctp_msg, pldm_mctp_response> g_outboundPldmReqMsgQ; // pldm outbound request msgQ

}

#endif
