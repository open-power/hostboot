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
#include <sys/mm.h>
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
// Const string to append to PCR extension messages
const char* FW_KEY_HASH_EXT = " FW KEY HASH";

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
    assert(i_sec < PNOR::NUM_SECTIONS,"PNOR section id %d is not a known section",
           i_sec);
    const char* l_secName = cv_EYECATCHER[i_sec];
    // Generate pcr extension message
    char l_swKeyMsg[strlen(l_secName) + strlen(FW_KEY_HASH_EXT) + 1];
    memset(l_swKeyMsg, 0, sizeof(l_swKeyMsg));
    strcat(l_swKeyMsg,l_secName);
    strcat(l_swKeyMsg,FW_KEY_HASH_EXT);

    TRACDCOMP(g_trac_trustedboot, ENTER_MRK"extendPnorSectionHash for section: %s",
              l_secName);
    do
    {
        TPM_Pcr l_pnorHashPcr = PCR_0;
        // PAYLOAD is the only section that needs its hash extended to PCR_4
        if (i_sec == PNOR::PAYLOAD)
        {
            l_pnorHashPcr = PCR_4;
        }
        // Extend swKeyHash to the next PCR after the hash extension PCR.
        TPM_Pcr l_swKeyHashPcr = (TPM_Pcr)(l_pnorHashPcr + 1);

        size_t l_protectedSize = i_conHdr.payloadTextSize();
        if (SECUREBOOT::enabled())
        {
            // If secureboot is enabled, use protected hash in header
            l_errhdl = TRUSTEDBOOT::pcrExtend(l_pnorHashPcr,
                  reinterpret_cast<const uint8_t*>(i_conHdr.payloadTextHash()),
                  sizeof(SHA512_t),
                  l_secName);
            if (l_errhdl)
            {
                break;
            }

            // Extend sw public key hash
            l_errhdl = TRUSTEDBOOT::pcrExtend(l_swKeyHashPcr,
                        reinterpret_cast<const uint8_t*>(i_conHdr.swKeyHash()),
                        sizeof(SHA512_t),
                        l_swKeyMsg);
            if (l_errhdl)
            {
                break;
            }
        }
        else
        {
            // If secureboot is not enabled, measure protected section
            SHA512_t l_hash = {0};
            SECUREBOOT::hashBlob(i_vaddr, l_protectedSize, l_hash);
            l_errhdl = TRUSTEDBOOT::pcrExtend(l_pnorHashPcr, l_hash,
                                              sizeof(SHA512_t),
                                              l_secName);
            if (l_errhdl)
            {
                break;
            }
        }
    } while(0);
#endif
    return l_errhdl;
}

errlHndl_t extendBaseImage()
{
    errlHndl_t pError = NULL;

#ifdef CONFIG_TPMDD

    TRACFCOMP(g_trac_trustedboot, ENTER_MRK "extendBaseImage()");

    do {

    // Query the HBB header and code address
    const void* pHbbHeader = NULL;

    (void)SECUREBOOT::baseHeader().getHeader(
        pHbbHeader);

    // Fatal code bug if either address is NULL
    assert(pHbbHeader!=NULL,"BUG! Cached header address is NULL");

    TRACDBIN(g_trac_trustedboot,"Base Header",pHbbHeader,128);

    // Build a container header object from the raw header
    SECUREBOOT::ContainerHeader hbbContainerHeader(pHbbHeader);

    const void* pHbbVa = NULL;
    if(!SECUREBOOT::enabled())
    {
        PNOR::SectionInfo_t l_info;
        pError = getSectionInfo(PNOR::HB_BASE_CODE, l_info);
        if(pError)
        {
            TRACFCOMP(g_trac_trustedboot, ERR_MRK "Failed in call to "
                "getSectionInfo for HBB section");
            break;
        }
        assert(l_info.vaddr != 0,"BUG! HBB virtual address was 0");
        pHbbVa = reinterpret_cast<const void*>(
            l_info.vaddr + PNOR::SBE_HEADER_SIZE);

        TRACDBIN(g_trac_trustedboot,"PNOF Base Code",pHbbVa,128);
    }

    // Extend the HBB measurement to the TPM
    pError = extendPnorSectionHash(
        hbbContainerHeader,
        pHbbVa,
        PNOR::HB_BASE_CODE);

    if(pError)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK "Failed in call to "
            "extendPnorSectionHash for HBB section.");
        break;
    }

    } while(0);

    TRACFCOMP(g_trac_trustedboot, EXIT_MRK "extendBaseImage()");

#endif

    return pError;
}

} // end TRUSTEDBOOT
