/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmibt.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

/// So, IPMI_BT_MAX_DATA == BMC receive size - IPMI_BT_HEADER_SIZE;
#define IPMI_BT_HEADER_SIZE 3

namespace IPMI
{
    // IPMI block-transfer message base class
    class BTMessage : public Message
    {
    public:
        ///
        /// @brief msg ctor
        /// @param[in] i_cmd, the network function & command
        /// @param[in] i_data, the data for the command
        /// @param[in] i_len, the length of the data
        /// @param[in] i_data, the data (new'd space)
        ///
        BTMessage(const command_t& i_cmd = no_command(),
                  const uint8_t i_len = 0,
                  uint8_t* i_data = NULL);

        virtual ~BTMessage(void)
            {}

        ///
        /// @brief transmit a message.
        /// @return Error from operation
        ///
        errlHndl_t phy_xmit(void);

        ///
        /// @brief transmit a message.
        /// @return true iff there was no transmission error
        ///
        /// @note we're not pure abstract as we want to be able to
        /// instantiate an object of BTMessage for reading.
        ///
        virtual bool xmit(void)
            {return true;}

        ///
        /// @brief receive a message.
        ///
        errlHndl_t recv(void);

        ///
        /// @brief complete the processing when a response arrives
        /// @param[in] i_msgQ, the resource providers message queue
        /// @return void
        /// @note we're not pure abstract as we want to be able to
        /// instantiate an object of BTMessage for reading.
        ///
        virtual void response(msg_q_t i_msgQ)
            {return;}

        ///
        /// @brief the size of the BT header
        /// @param void
        /// @return size_t, the header size
        /// @note IPMI_BT_MAX_DATA == BMC receive size - IPMI_BT_HEADER_SIZE;
        ///
        size_t header_size(void)
            { return IPMI_BT_HEADER_SIZE; }
    };

    // IPMI BT synchronous message
    class BTSyncMessage : public BTMessage
    {
    public:
        ///
        /// @brief BTSyncMessage ctor
        /// @param[in] i_cmd, the network function & command
        /// @param[in] i_len, the length of the data
        /// @param[in] i_data, the data (new'd space)
        ///
        BTSyncMessage(const command_t& i_cmd,
                      const uint8_t i_len, uint8_t* i_data);

        ///
        /// @brief transmit a message.
        ///
        /// @return true iff there was no transmission error
        ///
        bool xmit(void);

        ///
        /// @brief complete the processing when a response arrives
        /// @param[in] i_msgQ, the resource providers message queue
        /// @return void
        ///
        void response(msg_q_t i_msgQ);

    };

    // IPMI BT asynchronous message
    class BTAsyncMessage : public BTMessage
    {
    public:
        ///
        /// @brief BTSyncMessage ctor
        /// @param[in] i_cmd, the network function & command
        /// @param[in] i_len, the length of the data
        /// @param[in] i_data, the data (new'd space)
        ///
        BTAsyncMessage(const command_t& i_cmd,
                       const uint8_t i_len, uint8_t* i_data);

        ///
        /// @brief BTSyncMessage dtor
        ///
        virtual ~BTAsyncMessage(void)
            { delete[] iv_data; }

        ///
        /// @brief transmit a message.
        ///
        /// @return true iff there was no transmission error
        ///
        bool xmit(void);

        ///
        /// @brief complete the processing when a response arrives
        /// @param[in] i_msgQ, the resource providers message queue
        /// @return void
        ///
        void response(msg_q_t i_msgQ);
    };

    // IPMI BT asynchronous read event message. Reading events is sort
    // of an asynch message; we fire the request from the resource
    // provider thread (so we don't want to wait.) The response is
    // special in that we don't just delete ourselves, but rather turn
    // the response (OEM SEL) into a message for an event handler.
    class BTAsyncReadEventMessage : public BTAsyncMessage
    {
    public:
        ///
        /// @brief BTASyncReadEventMessage ctor
        /// @param[in] i_cmd, the network function & command
        /// @param[in] i_len, the length of the data
        /// @param[in] i_data, the data (new'd space)
        ///
        BTAsyncReadEventMessage(const command_t& i_cmd,
                                const uint8_t i_len, uint8_t* i_data);

        ///
        /// @brief complete the processing when a response arrives
        /// @param[in] i_msgQ, the resource providers message queue
        /// @return void
        ///
        void response(msg_q_t i_msgQ);
    };

}; // end namespace IPMI

#endif
