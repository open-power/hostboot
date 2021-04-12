/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_msg_queues.C $                         */
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
#include <sys/msg.h>
// VFS_ROOT_MSG_PLDM_REQ_OUT
#include <sys/vfs.h>
#include "pldm_msg_queues.H"

/**
 * @file pldm_msg_queues.C
 *
 * @brief Source code for defining and registering the 3 message queues
 *        that are used by both the pldm_base and pldm_extended modules.
 *        This code should only get compiled into the base image, which will
 *        always stay loaded. Therefore it is safe for the pldm_extended to
 *        also make external refernces to these msg qs.
 */

extern const char* VFS_ROOT_MSG_PLDM_REQ_IN;
extern const char* VFS_ROOT_MSG_PLDM_RSP_IN;

// Create global message queues which will be used throughout the
// pldm_base module
msg_q_t g_outboundPldmReqMsgQ = msg_q_create(); // pldm outbound request msgQ
msg_q_t g_inboundPldmRspMsgQ  = msg_q_create(); // pldm inbound response msgQ
msg_q_t g_inboundPldmReqMsgQ  = msg_q_create(); // pldm inbound request msgQ

namespace PLDM
{

void registerPldmMsgQs(void)
{
    // PLDM extended module will need to be able to resolve these queues
    // so register them
    msg_q_register(g_inboundPldmReqMsgQ, VFS_ROOT_MSG_PLDM_REQ_IN);
    msg_q_register(g_outboundPldmReqMsgQ, VFS_ROOT_MSG_PLDM_REQ_OUT);

    // Also register the inbound PLDM response queues for any test code that might
    // want to lookup the inbound response q to simulate inbound responses
    // coming from the bmc.
    msg_q_register(g_inboundPldmRspMsgQ, VFS_ROOT_MSG_PLDM_RSP_IN);
}

}
