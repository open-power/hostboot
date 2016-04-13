/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/base/trustedboot_base.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
 * @file trustedboot_base.C
 *
 * @brief Trusted boot base interfaces
 * This file is compiled in regardless of CONFIG_TPMDD
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <sys/time.h>
#include <sys/msg.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include <secureboot/trustedbootif.H>
#include <secureboot/trustedboot_reasoncodes.H>
#include "../trustedboot.H"
#include "../trustedbootCmds.H"
#include "../trustedbootUtils.H"
#include "trustedbootMsg.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
#ifdef CONFIG_TPMDD
trace_desc_t* g_trac_trustedboot = NULL;
TRAC_INIT( & g_trac_trustedboot, "TRBOOT", KILOBYTE );
// Eyecatcher strings for PNOR TOC entries
extern const char* cv_EYECATCHER[];
#endif

namespace TRUSTEDBOOT
{

#ifdef CONFIG_TPMDD
/// Global object to store TPM status
SystemTpms systemTpms;

TpmTarget::TpmTarget()
{
    memset(this, 0, sizeof(TpmTarget));
    available = true; // Default to available until we know better
    mutex_init(&tpmMutex);

}

#endif


errlHndl_t pcrExtend(TPM_Pcr i_pcr,
                     const uint8_t* i_digest,
                     size_t  i_digestSize,
                     const char* i_logMsg,
                     bool i_sendAsync)
{
    errlHndl_t err = NULL;
#ifdef CONFIG_TPMDD
    MessageMode mode = MSG_MODE_ASYNC;

    TRACDCOMP( g_trac_trustedboot, ENTER_MRK"pcrExtend()" );
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"pcrExtend() pcr=%d msg='%s'", i_pcr, i_logMsg);
    TRACUBIN(g_trac_trustedboot, "pcrExtend() digest:", i_digest, i_digestSize);

    // msgData will be freed when message is processed for async
    //   or below for sync message
    PcrExtendMsgData* msgData = new PcrExtendMsgData;
    memset(msgData, 0, sizeof(PcrExtendMsgData));
    msgData->mPcrIndex = i_pcr;
    msgData->mAlgId = TPM_ALG_SHA256;
    msgData->mEventType = EV_ACTION;
    msgData->mDigestSize = (i_digestSize < sizeof(msgData->mDigest) ?
                            i_digestSize : sizeof(msgData->mDigest));


    // copy over the incoming digest and truncate to what we need
    memcpy(msgData->mDigest, i_digest, msgData->mDigestSize);

    // Truncate logMsg if required
    memcpy(msgData->mLogMsg, i_logMsg,
           (strlen(i_logMsg) < sizeof(msgData->mLogMsg) ? strlen(i_logMsg) :
            sizeof(msgData->mLogMsg)-1)  // Leave room for NULL termination
           );

    if (!i_sendAsync)
    {
        mode = MSG_MODE_SYNC;
    }

    Message* msg = Message::factory(MSG_TYPE_PCREXTEND,
                                    sizeof(PcrExtendMsgData),
                                    reinterpret_cast<uint8_t*>(msgData),
                                    mode);
    // Message owns msgData now
    msgData = NULL;

    if (!i_sendAsync)
    {
        int rc = msg_sendrecv(systemTpms.msgQ, msg->iv_msg);
        if (0 == rc)
        {
            err = msg->iv_errl;
            msg->iv_errl = NULL;
        }
        // Sendrecv failure
        else
        {
            /*@
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        MOD_TPM_PCREXTEND
             * @reasoncode      RC_PCREXTEND_SENDRECV_FAIL
             * @userdata1       rc from msq_sendrecv()
             * @devdesc         msg_sendrecv() failed
             * @custdesc        Firmware error during system boot
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_TPM_PCREXTEND,
                                          RC_PCREXTEND_SENDRECV_FAIL,
                                          rc,
                                          0,
                                          true);
            err->collectTrace(SECURE_COMP_NAME);
        }
        delete msg;
        msg = NULL;
    }
    else
    {
        int rc = msg_send(systemTpms.msgQ, msg->iv_msg);
        if (rc)
        {
            /*@
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        MOD_TPM_PCREXTEND
             * @reasoncode      RC_PCREXTEND_SEND_FAIL
             * @userdata1       rc from msq_send()
             * @devdesc         msg_send() failed
             * @custdesc        Firmware error during system boot
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_TPM_PCREXTEND,
                                          RC_PCREXTEND_SEND_FAIL,
                                          rc,
                                          0,
                                          true);
            err->collectTrace(SECURE_COMP_NAME);
        }
    }

    TRACUCOMP( g_trac_trustedboot,
               EXIT_MRK"pcrExtend() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

#endif
    return err;
}

errlHndl_t extendPnorSectionHash(const SECUREBOOT::ContainerHeader& i_conHdr,
                                 const void* i_vaddr,
                                 const PNOR::SectionId i_sec)
{
    errlHndl_t l_errhdl = NULL;
#ifdef CONFIG_TPMDD
    TRACFCOMP(g_trac_trustedboot, ENTER_MRK"extendPnorSectionHash for section: %s",
              cv_EYECATCHER[i_sec]);
#endif
    return l_errhdl;
}

} // end TRUSTEDBOOT
