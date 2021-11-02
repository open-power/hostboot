/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldm_const.H $                           */
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
#ifndef PLDM_CONST_H
#define PLDM_CONST_H

/**
 * @file pldm_const.H
 * @brief Header file containing constants and types relating to PLDM
 */

typedef uint8_t mctp_eid_t;

namespace PLDM
{
    using pdr_handle_t = uint32_t;
    using terminus_id_t = uint16_t;
    using sensor_state_t = uint8_t;
    using sensor_id_t = uint16_t;
    using effecter_id_t = uint16_t;
    using state_query_id_t = uint16_t; // Either a state sensor or effecter ID
    using state_set_id_t = uint16_t;

    // used to match any terminus id
    const terminus_id_t TERMINUS_ID_ALL = 0xFFFF;

    // These are Entity Types used in Entity Association PDRs
    enum entity_type : uint16_t
    {
        // These values are from Table 15 in DSP0249 v1.1.0
        ENTITY_SYS_FIRMWARE = 31,
        ENTITY_TYPE_CHASSIS = 45,
        ENTITY_TYPE_BACKPLANE = 64,
        ENTITY_TYPE_DIMM = 66,
        ENTITY_TYPE_PROCESSOR_MODULE = 67,

        ENTITY_TYPE_PROCESSOR = 135,

        // Chassis-specific entities
        ENTITY_TYPE_LOGICAL_SYSTEM = 11521,

        // These values are defined by IBM as OEM codes
        ENTITY_TYPE_TPM = 24576,

        ENTITY_TYPE_LOGICAL_MARKER = 0x8000, //first bit means logical type
        ENTITY_TYPE_LOGICAL_PROCESSOR = ENTITY_TYPE_LOGICAL_MARKER | ENTITY_TYPE_PROCESSOR,
    };

    // These are the different types of PLDM message types we can expect
    // See DSP0245 v1.2.0 Table 1
    // When the MCTP layer creates a message to send to either inbound rsp
    // or inbound req queues it will set the msg->type to be the PLDM msg
    // type.
    enum msgq_msg_t
    {
        MSG_CONTROL_DISCOVERY = 0x00,
        MSG_SMBIOS            = 0x01,
        MSG_MONITOR_CONTROL   = 0x02,
        MSG_BIOS_CONTROL      = 0x03,
        MSG_FRU_DATA          = 0x04,
        MSG_OEM               = 0x3F
    };

    enum requester_rc_t
    {
        REQ_SUCCESS   = 0x00,
        REQ_FAILED    = 0x01
    };

    /* @brief Return an integer with a bit set in the position corresponding to
     *        the given enumeration (starting from 0 = the least significant
     *        bit) and zeroes in the other positions.  Used for libpldm
     *        enumeration constants.
     *
     * @param[in] i_enumeration  The value to encode
     * @return uint32_t          Encoded bitmask
     *
     * @example enum_bit(0) = 0x00000001
     * @example enum_bit(1) = 0x00000002
     * @example enum_bit(4) = 0x00000010
     */
    inline constexpr uint32_t enum_bit(unsigned int i_enumeration)
    {
        return 1 << i_enumeration;
    }

    // BMC currently does not support multi-part PLDM
    // transmissions so we will ALWAYS send GET_FIRST_PART
    // as the TransferOperationFlag and the data transfer
    // handle will always be 0x00000000
    const uint8_t GET_FIRST_PART = 0x01;
    const uint8_t INITIAL_TRANS_HNDL = 0x00000000;

#ifdef __HOSTBOOT_RUNTIME
    enum pldmrp_rt_rc : uint8_t
    {
        RC_PLDMRP_RT_SUCCESS   = 0,
        RC_NEXT_RESPONSE_FULL  = 1,
        RC_NEXT_REQUEST_FULL   = 2,
        RC_INVALID_MESSAGE_LEN = 3
    };
#endif
}

#endif
