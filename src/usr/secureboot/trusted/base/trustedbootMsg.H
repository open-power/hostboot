/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/base/trustedbootMsg.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include <secureboot/trustedbootif.H>

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
        MSG_TYPE_FLUSH,
        MSG_TYPE_SHUTDOWN,
        MSG_TYPE_INIT_BACKUP_TPM,
        MSG_TYPE_GETRANDOM,
        MSG_TYPE_CREATE_ATT_KEYS,
        MSG_TYPE_READ_AK_CERT,
        MSG_TYPE_GEN_QUOTE,
        MSG_TYPE_FLUSH_CONTEXT,
        MSG_TYPE_PCR_READ,
        MSG_TYPE_EXPAND_TPM_LOG,
        MSG_TYPE_SYNCHRONIZE_TPM_LOG,
        MSG_TYPE_LOG_SBE_MEASUREMENT_REGS,
        MSG_TYPE_LAST = MSG_TYPE_LOG_SBE_MEASUREMENT_REGS,
    };

    /// SEPARATOR message data
    struct SeparatorMsgData
    {
        bool             mExtendToTpm;
        bool             mExtendToSwLog;
        SeparatorMsgData(bool i_extendToTpm,
                         bool i_extendToSwLog) :
                         mExtendToTpm(i_extendToTpm),
                         mExtendToSwLog(i_extendToSwLog)
        {
        }

    };


    /// PCREXTEND message data
    struct PcrExtendMsgData
    {
        TPM_Pcr          mPcrIndex;
        TPM_Alg_Id       mAlgId;
        EventTypes       mEventType;
        size_t           mDigestSize;
        uint8_t          mDigest[TPM_ALG_SHA256_SIZE];
        uint8_t          mLogMsg[MAX_TPM_LOG_MSG];
        size_t           mLogMsgSize;
        const TpmTarget* mSingleTpm;
        bool             mExtendToTpm;
        bool             mExtendToSwLog;
        bool             mInhibitNodeMirroring;
    };

    struct GetRandomMsgData
    {
        TARGETING::Target* i_pTpm; // the TPM to obtain random data from
        size_t i_randNumSize;      // the size (in bytes) of the rand number
        uint8_t* o_randNum;        // the random data is populated here
    };

    // Pure Target* cannot be sent as extra_data through a synchronous message
    // because the act of deleting the sync mesage attempts to delete the ptr
    // to the target as well, which causes hostboot crashes. This struct is
    // a simple wrapper around the Target* for the messages requiring just the
    // TPM target to be passed.
    struct TpmTargetData
    {
        TpmTarget* tpm;
        TpmTargetData(TpmTarget* i_tpm) :
            tpm(i_tpm)
        {
        }
    };

    // The struct used to read the AK ceritificate from TPM's NVRAM
    struct ReadAKCertData
    {
        TpmTarget* tpm;
        TPM2B_MAX_NV_BUFFER* data; // The output of NVRAM read
        ReadAKCertData(TpmTarget* i_tpm, TPM2B_MAX_NV_BUFFER* i_data) :
            tpm(i_tpm), data(i_data)
        {
        }
    };

    // The struct used to generate TPM quote
    struct GenQuoteData
    {
        TpmTarget* tpm;
        const TpmNonce_t* const Nonce; // 32-byte nonce value
        QuoteDataOut* data; // Output - the quote and signature fields
        GenQuoteData(TpmTarget* i_tpm,
                     const TpmNonce_t* const i_nonce,
                     QuoteDataOut* o_data) :
                     tpm(i_tpm),
                     Nonce(i_nonce),
                     data(o_data)
        {
        }
    };

    // The struct used to read a PCR from TPM
    struct PcrReadData
    {
        TpmTarget* tpm; // TPM target whose PCRs are to be read
        TPM_Pcr pcr; // The PCR to read
        TPM_Alg_Id alg; // The PCR bank to read
        uint8_t* digest; // The buffer to hold the PCR contents
        size_t digestSize; // The size of the digest buffer
        PcrReadData(TpmTarget* i_tpm,
                    TPM_Pcr i_pcr,
                    TPM_Alg_Id i_alg,
                    uint8_t* o_digest,
                    size_t i_digestSize) :
                    tpm(i_tpm),
                    pcr(i_pcr),
                    alg(i_alg),
                    digest(o_digest),
                    digestSize(i_digestSize)
        {
        }
    };

    // The struct used to log the SBE Measurement Regs
    struct LogSbeMeasurementRegs
    {
        TpmTarget* tpm; // TPM target for the extend/log
        TARGETING::Target* proc; // Processor target of the SBE
        TPM_sbe_measurements_regs_grouped regs; // struct holding the data to extend/log
        bool extendToTpm; // Whether or not to extend the data to the TPM
        LogSbeMeasurementRegs(TpmTarget* i_tpm,
                              TARGETING::Target* i_proc,
                              TPM_sbe_measurements_regs_grouped i_regs,
                              bool i_extendToTpm) :
                              tpm(i_tpm),
                              proc(i_proc),
                              regs(i_regs),
                              extendToTpm(i_extendToTpm)
        {
        }
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
