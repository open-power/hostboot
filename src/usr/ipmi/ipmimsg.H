/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmimsg.H $                                      */
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
#ifndef __IPMI_IPMIMSG_H
#define __IPMI_IPMIMSG_H

#include <map>
#include <list>
#include <sys/msg.h>
#include <errl/errlentry.H>
#include <ipmi/ipmiif.H>

namespace IPMI
{
    // Used in the factory for creating the proper subclass.
    enum message_type
    {
        TYPE_SYNC = 0,
        TYPE_ASYNC = 1,
    };

    typedef std::list<msg_t*> send_q_t;
    typedef std::map<uint8_t,msg_t*> respond_q_t;

    // IPMI message base class. A thing which expects to be sent down a
    // msg_q (so has a msg_t) and defines operations performed by a generic
    // IPMI resource manager. Details are left to the subclasses.
    class Message
    {
    public:
        ///
        /// @brief static factory
        /// @param[in] i_netfun, the network function
        /// @param[in] i_cmd, the network command
        /// @param[in] i_data, the data for the command
        /// @param[in] i_len, the length of the data
        /// @param[in] i_data, the data (allocated space)
        /// @param[in] i_type, synchronous or async
        ///
        static Message* factory(const network_function i_netfun = NETFUN_NONE,
                                const uint8_t i_cmd = 0,
                                const uint8_t i_len = 0,
                                uint8_t* i_data = NULL,
                                const message_type i_type = TYPE_SYNC);

        ///
        /// @brief Message ctor
        ///
        Message(const network_function i_netfun = NETFUN_NONE,
                const uint8_t i_cmd = 0,
                const uint8_t i_len = 0,
                uint8_t* i_data = NULL);

        ///
        /// @brief Message dtor
        ///
        virtual ~Message(void)
            {
                msg_free(iv_msg);
            }

        ///
        /// @brief the maximum buffer size of the underlying transport
        /// @param void
        /// @return size_t, the max buffer size
        ///
        virtual size_t max_buffer(void) = 0;

        ///
        /// @brief transmit a message.
        /// @param[in] i_respondq, a map: iv_key->msg_t
        /// @return true iff there was no transmission error
        ///
        virtual bool xmit(respond_q_t& i_respondq) = 0;

        ///
        /// @brief receive a message.
        /// @return Error from operation
        /// @note fills our iv_key with the proper information
        ///
        virtual errlHndl_t recv(void) = 0;

        msg_t*   iv_msg;     // Pointer back to our msg_q msg_t
        uint8_t  iv_key;     // key used by the respond queue

        // Note: Some of these might turn out to be transport specific
        // if so, we'll just move them down in to the subclasses
        uint8_t    iv_len;     // Length
        uint8_t    iv_netfun;  // Network Function
        uint8_t&   iv_seq;     // Sequence number, reference to iv_key
        uint8_t    iv_cmd;     // Command
        uint8_t    iv_cc;      // Completion Code
        uint8_t    iv_state;   // Driver things, like EAGAIN
        errlHndl_t iv_errl;    // Pointer to the errlHandl_t if needed
        uint8_t*   iv_data;    // Pointer to the message data

    private:
        // Disallow copying this class. Should suffice for disabling copy for
        // all subclasses too.
        Message& operator=(const Message&);
        Message(const Message&);
    };

}; // end namespace IPMI

#endif
