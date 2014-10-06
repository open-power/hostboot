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
#include <map>

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

    // IPMI Completion Codes
    enum completion_code
    {
        CC_OK        = 0x00,
        CC_BUSY      = 0xc0,
        CC_INVALID   = 0xc1,
        CC_CMDLUN    = 0xc2,
        CC_TIMEOUT   = 0xc3,
        CC_NOSPACE   = 0xc4,
        CC_BADRESV   = 0xc5,
        CC_TRUNC     = 0xc6,
        CC_BADLEN    = 0xc7,
        CC_TOOLONG   = 0xc8,
        CC_OORANGE   = 0xc9,
        CC_LONGREPLY = 0xca,
        CC_BADSENSOR = 0xcb,
        CC_REQINVAL  = 0xcc,
        CC_CMDSENSOR = 0xcd,
        CC_CANTREPLY = 0xce,
        CC_DUPREQ    = 0xcf,
        CC_SDRUPDATE = 0xd0,
        CC_FMWUPDATE = 0xd1,
        CC_BMCINIT   = 0xd2,
        CC_BADDEST   = 0xd3,
        CC_NOPERM    = 0xd4,
        CC_NOTSUP    = 0xd5,
        CC_ILLPARAM  = 0xd6,
        CC_UNKBAD    = 0xff
    };

    //
    // Network function, command pairs.
    //
    typedef std::pair<network_function, uint8_t> command_t;


    // Application messages
    inline const command_t get_device_id(void)
    { return std::make_pair(NETFUN_APP, 0x01); }

    inline const command_t set_watchdog(void)
    { return std::make_pair(NETFUN_APP, 0x24); }

    inline const command_t get_capabilities(void)
    { return std::make_pair(NETFUN_APP, 0x36); }


    // Storage messages
    inline const command_t set_sel_time(void)
    { return std::make_pair(NETFUN_STORAGE, 0x49); }


    // Sensor messages
    inline const command_t platform_event(void)
    { return std::make_pair(NETFUN_SENSOR, 0x02); }


    // Some helper messages
    // Used to create an empty message for reception
    inline const command_t no_command(void)
    { return std::make_pair(NETFUN_NONE, 0x00); }

    // This is a message used only for testing. The ipmid responder
    // will drop this message so we can test timeouts.
    inline const command_t test_drop(void)
    { return std::make_pair(NETFUN_APP, 0x3e); }

    /**
     * Send message asynchronously
     * @param[in] i_cmd, the network function and command
     * @param[in] i_len, the length of the buffer
     * @param[in] i_data, the buffer - must be new'd
     * @example uint8_t* data = new uint8_t[length];
     * @warning do *not* delete data, the resource provider will do that.
     *
     * @return errlHndl_t, NULL on success
     */
    errlHndl_t send(const command_t& i_cmd,
                    const size_t i_len,
                    uint8_t* i_data);

    /**
     * Send message synchronously
     * @param[in] i_cmd, the command and network function
     * @param[out] o_completion_code,  the completion code
     * @param[in,out] io_len, the length of the buffer
     * @param[in] i_data, the buffer - must be new'd
     * @example uint8_t* data = new uint8_t[length];
     * @example delete[] data;
     *
     * @return errlHndl_t, NULL on success
     */
    errlHndl_t sendrecv(const command_t& i_cmd,
                        completion_code& o_completion_code,
                        size_t& io_len, uint8_t*& io_data);

    /**
     * Synchronously send an event
     * @param[in] i_sensor_type, the sensor type
     * @param[in] i_sensor_num, the sensor number
     * @param[in] i_assertion, bool true is assert, false is deassert.
     * @param[in] i_type, event type
     * @param[out] o_completion_code, completion code
     * @param[in] i_len, number of data bytes (1-3)
     * @param[in] i_data, data bytes
     *
     * @return errlHndl_t, NULL on success
     */
    errlHndl_t send_event(const uint8_t i_sensor_type,
                          const uint8_t i_sensor_number,
                          const bool i_assertion,
                          const uint8_t i_type,
                          completion_code& o_completion_code,
                          const size_t i_len,
                          uint8_t* i_data);

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
