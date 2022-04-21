/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mctp/mctp_message_types.H $                   */
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
 *  @file mctp_message_types.H
 *  @brief Values of different MCTP payload types, see DSP0239 v1.6.0 table 1
 */

#ifndef __MCTP_MESSAGE_TYPES_H
#define __MCTP_MESSAGE_TYPES_H

#include <memory>

#include <builtins.h>
#include <util/typed_msg.H>
#include <errl/errlentry.H>

namespace MCTP
{
    using message_type = uint8_t;

    // A flag that indicates that the MCTP message is carrying a PLDM message
    // If the 1st byte of the MCTP packet payload == MCTP_MSG_TYPE_PLDM we know
    // it is part of a PLDM message that is being transported.
    constexpr message_type MCTP_MSG_TYPE_CONTROL = 0x00;
    constexpr message_type MCTP_MSG_TYPE_PLDM    = 0x01;

    /* @brief Holds data related to the routing of an MCTP packet. */
    struct outgoing_mctp_msg_hdr
    {
        bool tag_owner = false;
        uint8_t msg_tag = 0;
        message_type mctp_msg_type = 0; // This must be the last member, so that
                                        // this byte is situated just before the
                                        // message body. (libmctp depends on
                                        // this.)
    } PACKED;

    /* @brief Contains an message header and payload of an MCTP packet. */
    struct outgoing_mctp_msg
    {
        // Can't copy or assign this structure because of the variable-size
        // array at the end.
        outgoing_mctp_msg(const outgoing_mctp_msg&) = delete;
        outgoing_mctp_msg& operator=(const outgoing_mctp_msg&) = delete;

        size_t data_size = 0;      // Size of data[]
        outgoing_mctp_msg_hdr hdr; // This must be the last member before
                                   // data[]. See the note above.
        uint8_t data[0];           // The message payload (e.g. PLDM message)
    } PACKED;

    /* @brief The result of an MCTP send operation. */
    struct mctp_outbound_result
    {
        std::unique_ptr<ERRORLOG::ErrlEntry> errl;
        std::unique_ptr<outgoing_mctp_msg> msg; // This is present to transfer
                                                // ownership of the message back
                                                // to the caller when the MCTP
                                                // sender is done with it.
    };

    using mctp_outbound_msgq_t = Util::bipipe<outgoing_mctp_msg, mctp_outbound_result>;
}

#endif
