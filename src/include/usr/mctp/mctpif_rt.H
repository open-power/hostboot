/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mctp/mctpif_rt.H $                            */
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
#ifndef MCTPIF_RT_H
#define MCTPIF_RT_H

/**
 * @file mctpif_rt.H
 * @brief MCTP's interface for hostboot runtime modules to use
 */
#include <mctp/mctp_const.H>

namespace MCTP
{
    /**
    * @brief Perform MCTP_RECEIVE fw_request to get the next MCTP packet
    *        if the hypervisor has one for HBRT
    *
    * @return int                Return Code which will either be from
    *                            interface.h or from libmctp_rc.h
    *                            (there should be no overlap)
    */
    int get_next_packet(void);

    /**
    * @brief Packetize the payload passed to us into MCTP packets and send
    *        them to the BMC using the hypervsior as a virtual bridge
    *
    * @param[in] i_mctp_payload  Byte vector containing the complete MCTP
    *                            message payload. If this message exceeds the
    *                            max MCTP packet size, the MCTP core logic will
    *                            packetize the message. It is expected that the
    *                            first byte of this buffer is set to the
    *                            correct message type prior to being passed to
    *                            this function
    *
    * @return int                Return Code which will either be from
    *                            interface.h or from libmctp_rc.h
    *                            (there should be no overlap)
    *
    */
    int send_message(const byte_vector_t& i_mctp_payload);
}

#endif
