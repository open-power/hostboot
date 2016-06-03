/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/base/trustedbootMsg.C $            */
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
 * @file trustedbootMsg.C
 * @brief Trusted boot message implemenation
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <sys/msg.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <secureboot/trustedboot_reasoncodes.H>
#include "trustedbootMsg.H"
#include "../trustedboot.H"

namespace TRUSTEDBOOT
{
    Message::Message(MessageType i_type, size_t i_len,
                     uint8_t* i_data, MessageMode i_mode):
        iv_msg(msg_allocate()),
        iv_errl(NULL),
        iv_len(i_len),
        iv_mode(i_mode),
        iv_data(i_data)
    {
        iv_msg->type = i_type;
        iv_msg->extra_data = static_cast<void*>(this);
    }

    SyncMessage::SyncMessage(MessageType i_type, size_t i_len,
                             uint8_t* i_data):
        Message(i_type, i_len, i_data, MSG_MODE_SYNC)
    {
    }

    void SyncMessage::response(msg_q_t i_msgQ)
    {
        errlHndl_t err = NULL;
        // Send the response to the original caller of sendrecv()
        int rc = msg_respond(i_msgQ, iv_msg);
        if (rc)
        {
            TRACFCOMP( g_trac_trustedboot,
                       ERR_MRK "SyncMessage::response msg_respond failure %d",
                       rc);
            /*@
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        MOD_TPM_SYNCRESPONSE
             * @reasoncode      RC_MSGRESPOND_FAIL
             * @userdata1       rc from msq_respond()
             * @devdesc         msg_respond() failed
             * @custdesc        Firmware error during system boot
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_TPM_SYNCRESPONSE,
                                          RC_MSGRESPOND_FAIL,
                                          rc,
                                          0,
                                          true);
            err->collectTrace(SECURE_COMP_NAME);

            // Log this failure here since we can't reply to caller
            errlCommit(err, SECURE_COMP_ID);

        }
    }

    AsyncMessage::AsyncMessage(MessageType i_type, size_t i_len,
                               uint8_t* i_data):
        Message(i_type, i_len, i_data, MSG_MODE_ASYNC)
    {
    }

    void AsyncMessage::response(msg_q_t i_msgQ)
    {
        if (NULL != iv_errl)
        {
            TRACFCOMP(g_trac_trustedboot,
                      ERR_MRK "AsyncMessage::respond with error log");
            // Since we can't pass back to the caller we will commit the log
            errlCommit(iv_errl, SECURE_COMP_ID);

            delete iv_errl;
            iv_errl = NULL;
        }
        delete this;
    }

    Message* Message::factory(MessageType i_type, size_t i_len,
                              uint8_t* i_data, MessageMode i_mode)
    {
        Message* msg = NULL;
        switch (i_mode)
        {
          case MSG_MODE_SYNC:
            msg = new SyncMessage(i_type, i_len, i_data);
            break;
          case MSG_MODE_ASYNC:
            msg = new AsyncMessage(i_type, i_len, i_data);
            break;
          default:
            assert(false, "trustedboot msg factory invalid mode");
            break;
        }
        return msg;
    }

};
