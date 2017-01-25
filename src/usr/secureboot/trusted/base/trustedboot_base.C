/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/base/trustedboot_base.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#include <secureboot/header.H>
#include <secureboot/containerheader.H>
#include <pnor/pnorif.H>
#include <config.h>
#include "../trustedboot.H"
#include "../trustedbootCmds.H"
#include "../trustedbootUtils.H"
#include "trustedbootMsg.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
#ifdef CONFIG_TPMDD
trace_desc_t* g_trac_trustedboot = nullptr;
TRAC_INIT( & g_trac_trustedboot, "TRBOOT", KILOBYTE );
#endif

namespace TRUSTEDBOOT
{

#ifdef CONFIG_TPMDD
// Const string to append to PCR extension messages
const char* const FW_KEY_HASH_EXT = " FW KEY HASH";

/// Global object to store TPM status
SystemTpms systemTpms;

TpmTarget::TpmTarget()
{
    memset(this, 0, sizeof(TpmTarget));
    available = true; // Default to available until we know better
    mutex_init(&tpmMutex);

}

#endif


errlHndl_t pcrExtendSeparator(bool i_sendAsync)
{
    errlHndl_t err = NULL;
#ifdef CONFIG_TPMDD
    MessageMode mode = (i_sendAsync) ? MSG_MODE_ASYNC : MSG_MODE_SYNC;

    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"pcrExtendSeparator()");

    Message* msg = Message::factory(MSG_TYPE_SEPARATOR,
                                    0,
                                    NULL,
                                    mode);
    assert(msg !=NULL, "BUG! Message is NULL");
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
             * @moduleid        MOD_TPM_SEPARATOR
             * @reasoncode      RC_SENDRECV_FAIL
             * @userdata1       rc from msq_sendrecv()
             * @devdesc         msg_sendrecv() failed
             * @custdesc        Firmware error during system boot
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_TPM_SEPARATOR,
                                          RC_SENDRECV_FAIL,
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
             * @moduleid        MOD_TPM_SEPARATOR
             * @reasoncode      RC_SEND_FAIL
             * @userdata1       rc from msq_send()
             * @devdesc         msg_send() failed
             * @custdesc        Firmware error during system boot
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_TPM_SEPARATOR,
                                          RC_SEND_FAIL,
                                          rc,
                                          0,
                                          true);
            err->collectTrace(SECURE_COMP_NAME);
        }
    }

    TRACUCOMP( g_trac_trustedboot,
               EXIT_MRK"pcrExtendSeparator() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

#endif
    return err;
}

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

    // msgData will be freed when message is freed
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
             * @reasoncode      RC_SENDRECV_FAIL
             * @userdata1       rc from msq_sendrecv()
             * @devdesc         msg_sendrecv() failed
             * @custdesc        Firmware error during system boot
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_TPM_PCREXTEND,
                                          RC_SENDRECV_FAIL,
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
             * @reasoncode      RC_SEND_FAIL
             * @userdata1       rc from msq_send()
             * @devdesc         msg_send() failed
             * @custdesc        Firmware error during system boot
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_TPM_PCREXTEND,
                                          RC_SEND_FAIL,
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

errlHndl_t extendPnorSectionHash(
    const SECUREBOOT::ContainerHeader& i_conHdr,
    const void* const                  i_vaddr,
    const PNOR::SectionId              i_sec)
{
    errlHndl_t pError = nullptr;

#ifdef CONFIG_TPMDD

    do {

    PNOR::SectionInfo_t sectionInfo;
    pError = PNOR::getSectionInfo(i_sec,sectionInfo);
    if(pError)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK " Failed in call to "
            "getSectionInfo() with section ID = %d.",
            i_sec);
        break;
    }

    TRACDCOMP(g_trac_trustedboot, ENTER_MRK " extendPnorSectionHash for "
        "section: %s",sectionInfo.name);

    const size_t protectedSize = i_conHdr.payloadTextSize();

    // Generate pcr extension message
    char swKeyMsg[strlen(sectionInfo.name) + strlen(FW_KEY_HASH_EXT) + 1];
    memset(swKeyMsg, 0, sizeof(swKeyMsg));
    strcat(swKeyMsg,sectionInfo.name);
    strcat(swKeyMsg,FW_KEY_HASH_EXT);

    TPM_Pcr pnorHashPcr = PCR_0;
    // PAYLOAD is the only section that needs its hash extended to PCR_4
    if (i_sec == PNOR::PAYLOAD)
    {
        pnorHashPcr = PCR_4;
    }
    // Extend swKeyHash to the next PCR after the hash extension PCR.
    const TPM_Pcr swKeyHashPcr = static_cast<TPM_Pcr>(pnorHashPcr + 1);

    if (SECUREBOOT::enabled())
    {
        // If secureboot is enabled, use protected hash in header
        pError = TRUSTEDBOOT::pcrExtend(pnorHashPcr,
              reinterpret_cast<const uint8_t*>(i_conHdr.payloadTextHash()),
              sizeof(SHA512_t),
              sectionInfo.name);
        if (pError)
        {
            TRACFCOMP(g_trac_trustedboot, ERR_MRK " Failed in call to "
                "pcrExtend() (extend payload text hash) for section %s.",
                sectionInfo.name);
            break;
        }

        // Extend SW public key hash
        pError = TRUSTEDBOOT::pcrExtend(swKeyHashPcr,
                    reinterpret_cast<const uint8_t*>(i_conHdr.swKeyHash()),
                    sizeof(SHA512_t),
                    swKeyMsg);
        if (pError)
        {
            TRACFCOMP(g_trac_trustedboot, ERR_MRK " Failed in call to "
                "pcrExtend() (extend SW public key hash) for section %s.",
                sectionInfo.name);
            break;
        }
    }
    else
    {
        // If secureboot is not enabled, measure protected section
        SHA512_t hash = {0};
        SECUREBOOT::hashBlob(i_vaddr, protectedSize, hash);
        pError = TRUSTEDBOOT::pcrExtend(pnorHashPcr, hash,
                                        sizeof(SHA512_t),
                                        sectionInfo.name);
        if (pError)
        {
            TRACFCOMP(g_trac_trustedboot, ERR_MRK " Failed in call to "
                "pcrExtend() (extend payload text) for section %s.",
                sectionInfo.name);
            break;
        }
    }

    } while(0);

    TRACDCOMP(g_trac_trustedboot, EXIT_MRK " extendPnorSectionHash");

#endif

    return pError;
}

errlHndl_t extendBaseImage()
{
    errlHndl_t pError = nullptr;

#ifdef CONFIG_TPMDD

    TRACFCOMP(g_trac_trustedboot, ENTER_MRK " extendBaseImage()");

    do {

    // Query the HBB header and code address
    const void* pHbbHeader = nullptr;

    (void)SECUREBOOT::baseHeader().getHeader(
        pHbbHeader);

    // Fatal code bug if either address is nullptr
    if(pHbbHeader == nullptr)
    {
        assert(false,"BUG! In extendBaseImage(), cached header address is "
            "nullptr");
    }

    TRACDBIN(g_trac_trustedboot,"Base Header",pHbbHeader,
        TRUSTEDBOOT::DEFAULT_BIN_TRACE_SIZE);

    // TODO: RTC 168021
    // Need to remove this when HBB has a secure header across all platforms
    // -or- a more general compatibility mechanism has been created allowing
    // some platforms to stage in support
    if(!PNOR::cmpSecurebootMagicNumber(
           reinterpret_cast<const uint8_t*>(pHbbHeader)))
    {
        TRACFCOMP(g_trac_trustedboot, INFO_MRK " HBB header is not a secure "
            "header; inhibiting extending base image measurement");
        break;
    }

    // Build a container header object from the raw header
    const SECUREBOOT::ContainerHeader hbbContainerHeader(pHbbHeader);

    const void* pHbbVa = nullptr;
    if(!SECUREBOOT::enabled())
    {
        PNOR::SectionInfo_t l_info;

        // @TODO RTC 168021 Remove this path since header will always be
        // cached
        pError = getSectionInfo(PNOR::HB_BASE_CODE, l_info);
        if(pError)
        {
            TRACFCOMP(g_trac_trustedboot, ERR_MRK "Failed in call to "
                "getSectionInfo for HBB section");
            break;
        }

        if(l_info.vaddr == 0)
        {
            assert(false,"BUG! In extendBaseImage(), HBB virtual address "
                "was 0");
        }

        pHbbVa = reinterpret_cast<const void*>(
            l_info.vaddr);

        TRACDBIN(g_trac_trustedboot,"PNOR Base Code",pHbbVa,
            TRUSTEDBOOT::DEFAULT_BIN_TRACE_SIZE);
    }

    // Extend the HBB measurement to the TPM
    pError = extendPnorSectionHash(
        hbbContainerHeader,
        pHbbVa,
        PNOR::HB_BASE_CODE);

    if(pError)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK "Failed in call to "
            "extendPnorSectionHash() for HBB section.");
        break;
    }

    } while(0);

    TRACFCOMP(g_trac_trustedboot, EXIT_MRK " extendBaseImage()");

#endif

    return pError;
}

} // end TRUSTEDBOOT
