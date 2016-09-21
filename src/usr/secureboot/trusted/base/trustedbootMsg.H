/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/base/trustedbootMsg.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
 * @file trustedbootMsg.H
 *
 * @brief Trustedboot Message
 *
 */
#ifndef __TRUSTEDBOOTMSG_H
#define __TRUSTEDBOOTMSG_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <errl/errlentry.H>
#include <sys/msg.h>
#include "../trustedTypes.H"

namespace TRUSTEDBOOT
{

    /// Message mode
    enum MessageMode
    {
        MSG_MODE_SYNC,
        MSG_MODE_ASYNC
    };

    /// Message Command type
    enum MessageType
    {
        MSG_TYPE_NOOP,
        MSG_TYPE_PCREXTEND,
        MSG_TYPE_SEPARATOR,
        MSG_TYPE_SHUTDOWN,
        MSG_TYPE_LAST = MSG_TYPE_SHUTDOWN
    };

    /// PCREXTEND message data
    struct PcrExtendMsgData
    {
        TPM_Pcr    mPcrIndex;
        TPM_Alg_Id mAlgId;
        EventTypes mEventType;
        size_t     mDigestSize;
        uint8_t    mDigest[TPM_ALG_SHA256_SIZE];
        char       mLogMsg[MAX_TPM_LOG_MSG];
    };

    // Trustedboot message class
    class Message
    {
    public:
        /// @brief Static factory
        /// @param[in] i_type Trustedboot TYPE
        /// @param[in] i_len Byte length of i_data
        /// @param[in] i_data The data as required by the specific command
        /// @param[in] i_mode Message mode
        static Message* factory(MessageType i_type = MSG_TYPE_NOOP,
                                size_t i_len = 0,
                                uint8_t* i_data = NULL,
                                MessageMode i_mode = MSG_MODE_SYNC);

        /// @brief Constructor
        /// @param[in] i_type Message type
        /// @param[in] i_len Byte length of i_data
        /// @param[in] i_data The data as required by the specific command
        /// @param[in] i_mode Message mode
        Message(MessageType i_type = MSG_TYPE_NOOP,
                size_t i_len = 0,
                uint8_t* i_data = NULL,
                MessageMode i_mode = MSG_MODE_SYNC);

        /// @brief Message dtor
        virtual ~Message(void)
        {
            if (NULL != iv_data)
            {
                delete[] iv_data;
                iv_data = NULL;
            }

            // Do NOT delete iv_errl here.  For synchronous messages
            // iv_errl is returned to the caller to commit and for
            // asynchronous messages the error log is committed
            // during the response processing
            msg_free(iv_msg);
        }

        /// @brief complete the processing when a response arrives
        virtual void response(msg_q_t i_msgQ) = 0;

        msg_t*     iv_msg;     ///< Pointer back to our msg_q msg_t
        errlHndl_t iv_errl;    ///< Pointer to the errlHandl_t if needed
        size_t     iv_len;     ///< Data Length
        MessageMode iv_mode;  ///< Message Mode
        uint8_t*   iv_data;    ///< Pointer to the message data

    private:
        // Disallow copying this class. Should suffice for disabling copy for
        // all subclasses too.
        Message& operator=(const Message&);
        Message(const Message&);

    };

    /// Trustedboot synchronous message
    class SyncMessage : public Message
    {
    public:
        /// @brief Constructor
        /// @param[in] i_type Trustedboot TYPE
        /// @param[in] i_len Byte length of i_data
        /// @param[in] i_data The data as required by the specific command
        SyncMessage(MessageType i_type = MSG_TYPE_NOOP,
                    size_t i_len = 0,
                    uint8_t* i_data = NULL);

        /// @brief Dtor
        virtual ~SyncMessage(void)
        {
        }

        /// @brief complete the processing when a response arrives
        virtual void response(msg_q_t i_msgQ);

    };

    /// Trustedboot asynchronous message
    class AsyncMessage : public Message
    {
    public:
        /// @brief Constructor
        /// @param[in] i_type Trustedboot TYPE
        /// @param[in] i_len Byte length of i_data
        /// @param[in] i_data The data as required by the specific command
        AsyncMessage(MessageType i_type = MSG_TYPE_NOOP,
                     size_t i_len = 0,
                     uint8_t* i_data = NULL);

        /// @brief Dtor
        virtual ~AsyncMessage(void)
        {
        }

        /// @brief complete the processing when a response arrives
        virtual void response(msg_q_t i_msgQ);
    };

};

#endif
