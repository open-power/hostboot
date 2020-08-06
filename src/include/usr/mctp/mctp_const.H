/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mctp/mctp_const.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#include <../../src/usr/mctp/extern/libmctp_rc.h>

namespace MCTP
{
    using byte_vector_t = std::vector<uint8_t>;
    using eid_t = uint8_t;

    constexpr uint8_t KCS_INIT        = 0x00;
    constexpr uint8_t KCS_TX_BEGIN    = 0x01;
    constexpr uint8_t KCS_RX_COMPLETE = 0x02;
    constexpr uint8_t KCS_DUMMY       = 0xFF;

    enum inbound_msgq_msg_t
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