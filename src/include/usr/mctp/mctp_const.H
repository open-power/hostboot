/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mctp/mctp_const.H $                           */
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
#ifndef MCTP_CONST_H
#define MCTP_CONST_H

/**
 *  @file mctp_const.H
 *  @brief constants and types used in MCTP related code
 */

#include <vector>
#include <mctp/mctp_message_types.H>

namespace MCTP
{
    using byte_vector_t = std::vector<uint8_t>;
    using eid_t = uint8_t;

    // EID is the MCTP endpoint ID, which aids in routing MCTP packets
    // theoretically we could assign these dynamically but for now
    // we are saying that BMC is EID 8 and hostboot IPL time is HOST_EID 9
    #define BMC_EID 8
    #define HOST_EID 9
    #define HBRT_EID 10

    // The maximum amount of memory we will allocate for a message
    // context we are building for an incoming MCTP message made
    // of multiple MCTP packets. We will se this to be 128KB as the
    // largest message we expect is the response to 127KB +1 PLDM
    // file read requests HB makes during lid verification in istep 21
    // We cannot use 127KB+1 directly because this value must be a
    // 8KB, 16KB, 32KB, 64KB, 128KB, 256KB etc. due the the way we currently
    // grow the memory buffer allotted for a given message context.
    // See extern/core.c mctp_msg_ctx_add_pkt for more info.
    #define HOST_MAX_INCOMING_MESSAGE_ALLOCATION 131072

    // Bits we care about in STATUS register
    const uint8_t KCS_STATUS_BMC_READY      = 0x80;
    const uint8_t KCS_STATUS_CHANNEL_ACTIVE = 0x40;
    const uint8_t KCS_STATUS_COMMAND_DATA   = 0x08;
    const uint8_t KCS_STATUS_IBF            = 0x02;
    const uint8_t KCS_STATUS_OBF            = 0x01;

    enum inbound_msgq_msg_t : uint8_t
    {
        MSG_INIT        = 0x00,
        MSG_TX_BEGIN    = 0x01,
        MSG_RX_COMPLETE = 0x02,
        MSG_DUMMY       = 0xFF
    };

    enum outbound_msgq_msg_t
    {
        MSG_SEND_PLDM        = 0x00
    };
}

#endif