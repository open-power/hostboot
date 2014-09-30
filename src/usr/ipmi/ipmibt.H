/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmibt.H $                                       */
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
#ifndef __IPMI_IPMIBT_H
#define __IPMI_IPMIBT_H

#include "ipmimsg.H"

// How many bytes are in the IPMI BT message header
#define IPMI_BT_HEADER_SIZE 3

// Per BMC Firmware Specification v3.6 James, et al the ASPEED
// is limited to a 64 byte IPMI message buffer.
#define IPMI_BT_MAX_MESSAGE_SIZE 64

#define IPMI_BT_MAX_DATA (IPMI_BT_MAX_MESSAGE_SIZE - IPMI_BT_HEADER_SIZE)

namespace IPMI
{
    // IPMI block-transfer message base class
    class BTMessage : public Message
    {
    public:
        ///
        /// @brief msg ctor
        /// @param[in] i_netfun, the network function
        /// @param[in] i_cmd, the network command
        /// @param[in] i_data, the data for the command
        /// @param[in] i_len, the length of the data
        /// @param[in] i_data, the data (new'd space)
        ///
        BTMessage(const network_function i_netfun = NETFUN_NONE,
                  const uint8_t i_cmd = 0,
                  const uint8_t i_len = 0,
                  uint8_t* i_data = NULL);

        ///
        /// @brief transmit a message.
        /// @return Error from operation
        ///
        errlHndl_t xmit(void);

        ///
        /// @brief transmit a message.
        /// @param[in] i_respondq, a map sequence->msg_t
        /// @return true iff there was no transmission error
        ///
        /// @note we're not pure abstract as we want to be able to
        /// instantiate an object of BTMessage for reading.
        ///
        virtual bool xmit(respond_q_t& i_respondq)
            {return true;};

        ///
        /// @brief receive a message.
        ///
        errlHndl_t recv(void);

        ///
        /// @brief the maximum buffer size of the underlying transport
        /// @param void
        /// @return size_t, the max buffer size
        ///
        size_t max_buffer(void)
            { return IPMI_BT_MAX_DATA; }

    };

    // IPMI BT synchronous message
    class BTSyncMessage : public BTMessage
    {
    public:
        ///
        /// @brief BTSyncMessage ctor
        /// @param[in] i_netfun, the network function
        /// @param[in] i_cmd, the network command
        /// @param[in] i_data, the data for the command
        /// @param[in] i_len, the length of the data
        /// @param[in] i_data, the data (new'd space)
        ///
        BTSyncMessage(const network_function i_netfun, const uint8_t i_cmd,
                      const uint8_t i_len, uint8_t* i_data);

        ///
        /// @brief transmit a message.
        /// @param[in] i_respondq, a map sequence->msg_t
        ///
        /// @return true iff there was no transmission error
        ///
        bool xmit(respond_q_t& i_respondq);
    };

    // IPMI BT asynchronous message
    class BTAsyncMessage : public BTMessage
    {
    public:
        ///
        /// @brief BTSyncMessage ctor
        /// @param[in] i_netfun, the network function
        /// @param[in] i_cmd, the network command
        /// @param[in] i_data, the data for the command
        /// @param[in] i_len, the length of the data
        /// @param[in] i_data, the data (new'd space)
        ///
        BTAsyncMessage(const network_function i_netfun, const uint8_t i_cmd,
                       const uint8_t i_len, uint8_t* i_data);

        ///
        /// @brief transmit a message.
        /// @param[in] respond_q_t unused
        ///
        /// @return true iff there was no transmission error
        ///
        bool xmit(respond_q_t&);
    };

}; // end namespace IPMI

#endif
