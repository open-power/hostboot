/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ipmi/ipmiif.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
#ifndef __IPMI_IPMIIF_H
#define __IPMI_IPMIIF_H

#include <sys/msg.h>
#include <errl/errlentry.H>

namespace IPMI
{
    // Message types which travel on the IPMI message queues
    enum msg_type
    {
        // Sent when the interface goes idle *and* we had write which
        // was told the interface was busy. We won't get notified of
        // the general idle state.
        MSG_STATE_IDLE,

        // Ready to read a response
        MSG_STATE_RESP,

        // Ready to read an event/sms
        MSG_STATE_EVNT,

        // A message which needs to be sent
        MSG_STATE_SEND,

        MSG_STATE_SHUTDOWN,

        // Used to check range. Leave as last.
        MSG_LAST_TYPE = MSG_STATE_SHUTDOWN,
    };

    // IPMI network functions
    enum network_function
    {
        // These are the command network functions, the response
        // network functions are the function + 1. So to determine
        // the proper network function which issued the command
        // associated with a response, subtract 1.
        // Note: these are also shifted left to make room for the LUN.
        NETFUN_CHASSIS  = (0x00 << 2),
        NETFUN_BRIDGE   = (0x02 << 2),
        NETFUN_SENSOR   = (0x04 << 2),
        NETFUN_APP      = (0x06 << 2),
        NETFUN_FIRMWARE = (0x08 << 2),
        NETFUN_STORAGE  = (0x0a << 2),
        NETFUN_TRANPORT = (0x0c << 2),

        // Overload the OEM netfun for a "none" netfun. We use this as a
        // default for objects which will have their netfun filled in
        NETFUN_NONE     = (0x30 << 2),
    };

    /**
     * Send message asynchronously
     * @param[in] i_netfun, the network function
     * @param[in] i_cmd, the command
     * @param[in] i_len, the length of the buffer
     * @param[in] i_data, the buffer - must be new'd
     * @example uint8_t* data = new uint8_t[length];
     * @warning do *not* delete data, the resource provider will do that.
     *
     * @return errlHndl_t, NULL on success
     */
    errlHndl_t send(const network_function i_netfun,
                    const uint8_t i_cmd, const size_t i_len,
                    uint8_t* i_data);

    /**
     * Send message synchronously
     * @param[in] i_netfun, the network function
     * @param[in] i_cmd, the command
     * @param[out] o_completion_code,  the completion code
     * @param[in,out] io_len, the length of the buffer
     * @param[in] i_data, the buffer - must be new'd
     * @example uint8_t* data = new uint8_t[length];
     * @example delete[] data;
     *
     * @return errlHndl_t, NULL on success
     */
    errlHndl_t sendrecv(const network_function i_netfun,
                        const uint8_t i_cmd, uint8_t& o_completion_code,
                        size_t& io_len, uint8_t*& io_data);

    /**
     * Get the max buffer size
     * @param void
     *
     * @return the maximum space allowed for data, per message
     * (max message for the transport - the header size)
     */
    inline size_t max_buffer(void);

}; // end namespace IPMI

#endif
