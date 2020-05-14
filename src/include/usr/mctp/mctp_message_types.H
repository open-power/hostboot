/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mctp/mctp_message_types.H $                   */
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

// A flag that indicates that the MCTP message is carrying a PLDM message
// If the 1st byte of the MCTP packet payload == MCTP_MSG_TYPE_PLDM we know
// it is part of a PLDM message that is being transported.

#ifndef __MCTP_MESSAGE_TYPES_H
#define __MCTP_MESSAGE_TYPES_H

/**
 *  @file mctp_message_types.H
 *  @brief Values of different MCTP payload types, see DSP0239 v1.6.0 table 1
 */

namespace MCTP
{
    using message_type = uint8_t;

    constexpr message_type MCTP_MSG_TYPE_CONTROL = 0x00;
    constexpr message_type MCTP_MSG_TYPE_PLDM    = 0x01;
}

#endif