/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/base/trustedboot_base.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#include <secureboot/service.H>
#include <pnor/pnorif.H>
#include "../trustedboot.H"
#include "../trustedbootCmds.H"
#include "../trustedbootUtils.H"
#include "../../pnor/pnor_utils.H"
#include "trustedbootMsg.H"
#include "../tpmLogMgr.H"
#include <algorithm>

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------

trace_desc_t* g_trac_trustedboot = nullptr;
TRAC_INIT( & g_trac_trustedboot, TRBOOT_COMP_NAME, KILOBYTE );

namespace TRUSTEDBOOT
{

// Const string to append to PCR extension messages
const char* const FW_KEY_HASH_EXT = " FW KEY HASH";

#ifdef CONFIG_TPMDD

/// Global object to store system trusted boot data
SystemData systemData;

#endif

void getTPMs(
          TARGETING::TargetHandleList& o_tpmList,
    const TPM_FILTER                   i_filter)
{
    TRACUCOMP(g_trac_trustedboot,ENTER_MRK "getTPMs(): i_filter=%d",
        i_filter);

    o_tpmList.clear();

    TARGETING::getAllChips(
        o_tpmList,
        TARGETING::TYPE_TPM,
        (i_filter == TPM_FILTER::ALL_IN_BLUEPRINT) ? false : true);

    if(i_filter == TPM_FILTER::ALL_FUNCTIONAL)
    {
        // From functional TPMs, remove any TPMs that are not actually
        // initialized.  This prevents Hostboot from using the backup TPM
        // in an MPIPL when it's considered "functional" but hasn't been
        // initialized  yet.
        o_tpmList.erase(
            std::remove_if(
                o_tpmList.begin(),
                o_tpmList.end(),
                [](TARGETING::Target* i_pTpm)
                {
                    return !i_pTpm->getAttr<
                               TARGETING::ATTR_HB_TPM_INIT_ATTEMPTED>();
                }),
            o_tpmList.end());
    }

    TRACUCOMP(g_trac_trustedboot,EXIT_MRK "getTPMs(): Found %d TPMs",
        o_tpmList.size());
}

_TpmLogMgr* getTpmLogMgr(
    const TpmTarget* const i_pTpm)
{
    assert(i_pTpm != nullptr,"getTpmLogMgr: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "getTpmLogMgr: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());
    return reinterpret_cast<_TpmLogMgr*>(
        i_pTpm->getAttr<TARGETING::ATTR_HB_TPM_LOG_MGR_PTR>());
}

void setTpmLogMgr(
          TpmTarget*  const i_pTpm,
    const _TpmLogMgr* const i_pTpmLogMgr)
{
    assert(i_pTpm != nullptr,"setTpmLogMgr: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "setTpmLogMgr: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());
    auto pLogMgrPtr =
        reinterpret_cast<TARGETING::ATTR_HB_TPM_LOG_MGR_PTR_type>(
            i_pTpmLogMgr);
    i_pTpm->setAttr<
        TARGETING::ATTR_HB_TPM_LOG_MGR_PTR>(pLogMgrPtr);
}

errlHndl_t pcrExtendSeparator(bool i_sendAsync,
                              bool i_extendToTpm,
                              bool i_extendToSwLog)
{
    errlHndl_t err = nullptr;
#ifdef CONFIG_TPMDD
    MessageMode mode = (i_sendAsync) ? MSG_MODE_ASYNC : MSG_MODE_SYNC;

    TRACUCOMP( g_trac_trustedboot,ENTER_MRK
               "pcrExtendSeparator(): i_sendAsync=%d, i_extendToTpm=%d, i_extendToSwLog=%d",
               i_sendAsync, i_extendToTpm, i_extendToSwLog);


    Message* msg = nullptr;

    SeparatorMsgData* l_data = new SeparatorMsgData(i_extendToTpm,
                                                    i_extendToSwLog);

    msg = Message::factory(MSG_TYPE_SEPARATOR,
                           sizeof(*l_data),
                           reinterpret_cast<uint8_t*>(l_data),
                           mode);

    assert(msg != nullptr, "pcrExtendSeparator: msg is nullptr");
    l_data = nullptr; //l_msg now owns l_data

    if (!i_sendAsync)
    {
        int rc = msg_sendrecv(systemData.msgQ, msg->iv_msg);
        if (0 == rc)
        {
            err = msg->iv_errl;
            msg->iv_errl = nullptr;
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
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            err->collectTrace(SECURE_COMP_NAME);
            err->collectTrace(TRBOOT_COMP_NAME);
        }
        delete msg;
        msg = nullptr;
    }
    else
    {
        int rc = msg_send(systemData.msgQ, msg->iv_msg);
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
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            err->collectTrace(SECURE_COMP_NAME);
            err->collectTrace(TRBOOT_COMP_NAME);
        }
    }

    TRACUCOMP( g_trac_trustedboot,
               EXIT_MRK"pcrExtendSeparator() - %s",
               ((nullptr == err) ? "No Error" : "With Error") );

#endif
    return err;
}

errlHndl_t pcrExtend(TPM_Pcr i_pcr,
                     EventTypes i_eventType,
                     const uint8_t* i_digest,
                     size_t  i_digestSize,
                     const uint8_t* i_logMsg,
                     const size_t i_logMsgSize,
                     bool i_sendAsync,
                     const TpmTarget* i_pTpm,
                     const bool i_extendToTpm,
                     const bool i_extendToSwLog,
                     const bool i_inhibitNodeMirroring)
{
    errlHndl_t err = nullptr;
#ifdef CONFIG_TPMDD
    MessageMode mode = MSG_MODE_ASYNC;

    TRACDCOMP( g_trac_trustedboot, ENTER_MRK"pcrExtend()" );
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"pcrExtend() pcr=%d, i_extendToTpm=%d, "
               "i_extendToSwLog=%d, i_inhibitNodeMirroring=%d",
               i_pcr, i_extendToTpm, i_extendToSwLog,i_inhibitNodeMirroring);
    if(i_logMsg)
    {
        TRACUBIN(g_trac_trustedboot, "TPM log msg", i_logMsg, i_logMsgSize);
    }
    TRACUBIN(g_trac_trustedboot, "pcrExtend() digest:", i_digest, i_digestSize);

    // msgData will be freed when message is freed
    PcrExtendMsgData* msgData = new PcrExtendMsgData;
    memset(msgData, 0, sizeof(PcrExtendMsgData));
    msgData->mPcrIndex = i_pcr;
    msgData->mAlgId = TPM_ALG_SHA256;
    msgData->mEventType = i_eventType;
    msgData->mDigestSize = (i_digestSize < sizeof(msgData->mDigest) ?
                            i_digestSize : sizeof(msgData->mDigest));
    msgData->mSingleTpm = i_pTpm;
    msgData->mExtendToTpm = i_extendToTpm;
    msgData->mExtendToSwLog = i_extendToSwLog;
    msgData->mInhibitNodeMirroring = i_inhibitNodeMirroring;

    // copy over the incoming digest and truncate to what we need
    memcpy(msgData->mDigest, i_digest, msgData->mDigestSize);

    // Truncate logMsg if required
    if (i_logMsg)
    {
        memcpy(msgData->mLogMsg, i_logMsg,
            (i_logMsgSize < sizeof(msgData->mLogMsg) ?
                i_logMsgSize : sizeof(msgData->mLogMsg)));
    }
    msgData->mLogMsgSize = i_logMsgSize;

    if (!i_sendAsync)
    {
        mode = MSG_MODE_SYNC;
    }

    Message* msg = Message::factory(MSG_TYPE_PCREXTEND,
                                    sizeof(PcrExtendMsgData),
                                    reinterpret_cast<uint8_t*>(msgData),
                                    mode);
    // Message owns msgData now
    msgData = nullptr;

    if (!i_sendAsync)
    {
        int rc = msg_sendrecv(systemData.msgQ, msg->iv_msg);
        if (0 == rc)
        {
            err = msg->iv_errl;
            msg->iv_errl = nullptr;
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
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            err->collectTrace(SECURE_COMP_NAME);
            err->collectTrace(TRBOOT_COMP_NAME);
        }
        delete msg;
        msg = nullptr;
    }
    else
    {
        int rc = msg_send(systemData.msgQ, msg->iv_msg);
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
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            err->collectTrace(SECURE_COMP_NAME);
            err->collectTrace(TRBOOT_COMP_NAME);
        }
    }

    TRACUCOMP( g_trac_trustedboot,
               EXIT_MRK"pcrExtend() - %s",
               ((nullptr == err) ? "No Error" : "With Error") );

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
    EventTypes swKeyHashEventType = TRUSTEDBOOT::EV_PLATFORM_CONFIG_FLAGS;
    EventTypes pnorHashEventType = TRUSTEDBOOT::EV_POST_CODE;
    // PAYLOAD is the only section that needs its hash extended to PCR_4
    if (i_sec == PNOR::PAYLOAD)
    {
        pnorHashPcr = PCR_4;
        swKeyHashEventType = TRUSTEDBOOT::EV_COMPACT_HASH;
        pnorHashEventType = TRUSTEDBOOT::EV_COMPACT_HASH;
    }
    else if(PNOR::isCoreRootOfTrustSection(i_sec))
    {
        pnorHashEventType = TRUSTEDBOOT::EV_S_CRTM_CONTENTS;
    }
    // Extend swKeyHash to the next PCR after the hash extension PCR.
    const TPM_Pcr swKeyHashPcr = static_cast<TPM_Pcr>(pnorHashPcr + 1);

    // By default, extend and log.
    // Special case for HBB:
    // -- for pnorHashPcr  (PCR_0): only log for HBB since HBBL has already extended HBB
    // -- for swKeyHashPcr (PCR_1): extend and log HBB
    bool extendToTpm_PNOR = true;
    bool extendToTpm_SW = true;
    bool extendToSwLog = true;
    if (i_sec == PNOR::HB_BASE_CODE)
    {
        extendToTpm_PNOR = false;
        TRACUCOMP(g_trac_trustedboot, ENTER_MRK " extendPnorSectionHash for "
                  "section: %s: setting extendToTpm_PNOR to %d (extendToSwLog=%d)",
                  sectionInfo.name, extendToTpm_PNOR, extendToSwLog);
    }

    // Set other default parameters to pick up extendToTpm and extendToSwLog input parameters
    bool sendAsync = true;
    const TpmTarget* pTpm = nullptr;

    if (SECUREBOOT::enabled())
    {
        // If secureboot is enabled, use protected hash in header
        pError = TRUSTEDBOOT::pcrExtend(pnorHashPcr,
              pnorHashEventType,
              reinterpret_cast<const uint8_t*>(i_conHdr.payloadTextHash()),
              sizeof(SHA512_t),
              reinterpret_cast<const uint8_t*>(sectionInfo.name),
              strlen(sectionInfo.name) + 1,
              sendAsync,
              pTpm,
              extendToTpm_PNOR,
              extendToSwLog);
        if (pError)
        {
            TRACFCOMP(g_trac_trustedboot, ERR_MRK " Failed in call to "
                "pcrExtend() (extend payload text hash) for section %s.",
                sectionInfo.name);
            break;
        }

        // Extend SW public key hash
        pError = TRUSTEDBOOT::pcrExtend(swKeyHashPcr,
                    swKeyHashEventType,
                    reinterpret_cast<const uint8_t*>(i_conHdr.swKeyHash()),
                    sizeof(SHA512_t),
                    reinterpret_cast<const uint8_t*>(swKeyMsg),
                    strlen(swKeyMsg) + 1,
                    sendAsync,
                    pTpm,
                    extendToTpm_SW,
                    extendToSwLog);

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
        pError = TRUSTEDBOOT::pcrExtend(pnorHashPcr,
                pnorHashEventType,
                hash,
                sizeof(SHA512_t),
                reinterpret_cast<const uint8_t*>(sectionInfo.name),
                strlen(sectionInfo.name) + 1,
                sendAsync,
                pTpm,
                extendToTpm_PNOR,
                extendToSwLog);

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

    TRACDCOMP(g_trac_trustedboot, ENTER_MRK " extendBaseImage()");

    do {

    // Since this is the first HBB call to extend something, before doing anything else,
    // sync the TPM Log with what the SBE and HBBL should have already extended
    pError = synchronizeTpmLog();
    if (pError)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"extendBaseImage(): synchronizeTpmLog() failed");
        break;
    }

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

    // Build a container header object from the raw header
    SECUREBOOT::ContainerHeader hbbContainerHeader;
    pError = hbbContainerHeader.setHeader(pHbbHeader);
    if (pError)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK"extendBaseImage() setheader failed");
        break;
    }

    // TPM extension of PNOR sections operates differently when SecureMode is
    // enabled/disabled.  Provide all possible info and let TPM code handle
    // the logic
    PNOR::SectionInfo_t l_info;
    pError = getSectionInfo(PNOR::HB_BASE_CODE, l_info);
    if(pError)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK "Failed in call to "
            "getSectionInfo for HBB section");
        break;
    }

    if(l_info.vaddr == 0)
    {
        assert(false,"BUG! In extendBaseImage(), HBB virtual address was 0");
    }

    const void* pHbbVa = reinterpret_cast<const void*>(l_info.vaddr);

    TRACDBIN(g_trac_trustedboot,"PNOR Base Code",pHbbVa,
             TRUSTEDBOOT::DEFAULT_BIN_TRACE_SIZE);

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

    TRACDCOMP(g_trac_trustedboot, EXIT_MRK " extendBaseImage()");

#endif

    return pError;
}

void initBackupTpm()
{
#ifdef CONFIG_TPMDD
    errlHndl_t l_errl = nullptr;
    TARGETING::Target* l_backupTpm = nullptr;

    getBackupTpm(l_backupTpm);
    if(l_backupTpm)
    {
        Message* l_msg = Message::factory(MSG_TYPE_INIT_BACKUP_TPM,
                                          0,
                                          nullptr,
                                          MSG_MODE_SYNC);
        int l_rc = msg_sendrecv(systemData.msgQ, l_msg->iv_msg);
        if(l_rc == 0)
        {
            l_errl = l_msg->iv_errl;
            l_msg->iv_errl = nullptr;
        }
        else
        {
            TRACFCOMP(g_trac_trustedboot, ERR_MRK"initBackupTpm(): Error occurred while sending message to"
                     " the TPM daemon. RC = %d", l_rc);
            /*@
             * @errortype      ERRL_SEV_UNRECOVERABLE
             * @reasoncode     RC_SENDRECV_FAIL
             * @moduleid       MOD_INIT_BACKUP_TPM
             * @userdata1      rc from msq_sendrecv()
             * @devdesc        msg_sendrecv() failed
             * @custdesc       Trusted Boot failure
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             MOD_INIT_BACKUP_TPM,
                                             RC_SENDRECV_FAIL,
                                             l_rc,
                                             0,
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(SECURE_COMP_NAME);
            l_errl->collectTrace(TRBOOT_COMP_NAME);
        }
        delete l_msg;
        l_msg = nullptr;

        if(l_errl)
        {
            tpmMarkFailed(l_backupTpm, l_errl);
        }
    }
    else
    {
        TRACFCOMP(g_trac_trustedboot, INFO_MRK"initBackupTpm(): Backup TPM not found.");
    }
#endif
}

errlHndl_t testCmpPrimaryAndBackupTpm()
{
    errlHndl_t l_err = nullptr;
#ifdef CONFIG_TPMDD
    TARGETING::Target* l_primaryTpm = nullptr;
    TARGETING::Target* l_backupTpm = nullptr;
    bool l_errorOccurred = false;
    BackupTpmTestFailures l_rc = TPM_TEST_NO_ERROR;

    do {

    getPrimaryTpm(l_primaryTpm);
    if(!l_primaryTpm)
    {
        TRACFCOMP(g_trac_trustedboot,
                           "testCmpPrimaryAndBackupTpm: primary TPM not found;"
                           "skipping test");
        break;
    }
    getBackupTpm(l_backupTpm);
    if(!l_backupTpm)
    {
        TRACFCOMP(g_trac_trustedboot,
                            "testCmpPrimaryAndBackupTpm: backup TPM not found;"
                            "skipping test");
        break;
    }

    auto l_primaryHwasState = l_primaryTpm->getAttr<
                                                  TARGETING::ATTR_HWAS_STATE>();
    if(!(l_primaryHwasState.present && l_primaryHwasState.functional))
    {
        TRACFCOMP(g_trac_trustedboot, "testCmpPrimaryAndBackupTpm: primary TPM"
                                      "is not present or not functional;"
                                      "skipping the test.");
        break;
    }

    auto l_backupHwasState = l_backupTpm->getAttr<TARGETING::ATTR_HWAS_STATE>();
    if(!(l_backupHwasState.present && l_backupHwasState.functional))
    {
        TRACFCOMP(g_trac_trustedboot, "testCmpPrimaryAndBackupTpm: backup TPM"
                                      "is not present or not functional;"
                                      "skipping the test.");
        break;
    }

    auto * const pTpmLogMgr = getTpmLogMgr(l_primaryTpm);
    auto * const bTpmLogMgr = getTpmLogMgr(l_backupTpm);

    if(!pTpmLogMgr || !bTpmLogMgr)
    {
        TRACFCOMP(g_trac_trustedboot,
                  "testCmpPrimaryAndBackupTpm: TPM log manager(s)"
                  " is(are) uninitialized");
        l_errorOccurred = true;
        l_rc = TPM_TEST_LOGS_NOT_INITIALIZED;
        break;
    }

    if(TpmLogMgr_getLogSize(bTpmLogMgr) == TpmLogMgr_getLogSize(pTpmLogMgr))
    {
        TRACFCOMP(g_trac_trustedboot,
                     "testCmpPrimaryAndBackupTpm: the sizes of TPM logs match");
    }
    else
    {
        TRACFCOMP(g_trac_trustedboot,
                  "testCmpPrimaryAndBackupTpm: log size mismatch."
                  " Primary log size: %d; backup log size: %d.",
                  TpmLogMgr_getLogSize(pTpmLogMgr),
                  TpmLogMgr_getLogSize(bTpmLogMgr));
        l_errorOccurred = true;
        l_rc = TPM_TEST_LOG_SIZE_MISMATCH;
        break;
    }

    int l_count = 0;
    TCG_PCR_EVENT2 l_pEventLog = {0};
    TCG_PCR_EVENT2 l_bEventLog = {0};
    // Skip the first entry which is the header
    const uint8_t* l_pEventHdl = TpmLogMgr_getFirstEvent(pTpmLogMgr);
    const uint8_t* l_bEventHdl = TpmLogMgr_getFirstEvent(bTpmLogMgr);

    // Match the logs
    while(l_pEventHdl != nullptr && l_bEventHdl != nullptr)
    {
        // Other (than the header) events need to be processed
        l_pEventHdl = TpmLogMgr_getNextEvent(pTpmLogMgr, l_pEventHdl,
                                            &l_pEventLog, &l_errorOccurred);
        if(l_errorOccurred)
        {
            TRACFCOMP(g_trac_trustedboot,
                "testCmpPrimaryAndBackupTpm: Unmarshaling error occurred.");
            l_rc = TPM_TEST_UNMARSHAL_ERROR;
            break;
        }

        l_bEventHdl = TpmLogMgr_getNextEvent(bTpmLogMgr, l_bEventHdl,
                                            &l_bEventLog, &l_errorOccurred);
        if(l_errorOccurred)
        {
            TRACFCOMP(g_trac_trustedboot,
                "testCmpPrimaryAndBackupTpm: Unmarshaling error occurred.");
            l_rc = TPM_TEST_UNMARSHAL_ERROR;
            break;
        }

        if(memcmp(&l_pEventLog, &l_bEventLog, sizeof(TCG_PCR_EVENT2)))
        {
            TRACFCOMP(g_trac_trustedboot,
                      "testCmpPrimaryAndBackupTpm: log #%d does not match",
                      l_count);
            TRACFBIN(g_trac_trustedboot,
                     "testCmpPrimaryAndBackupTpm: primary TPM's log:",
                     &l_pEventLog, sizeof(TCG_PCR_EVENT2));
            TRACFBIN(g_trac_trustedboot,
                     "testCmpPrimaryAndBackupTpm: backup TPM's log:",
                     &l_bEventLog, sizeof(TCG_PCR_EVENT2));
            l_errorOccurred = true;
            l_rc = TPM_TEST_LOG_MISMATCH;
            break;
        }
        else
        {
            TRACFCOMP(g_trac_trustedboot,
                      "testCmpPrimaryAndBackupTpm: log #%d matches",
                      l_count);
        }

        l_count++;
    } //while

    if(l_err || l_errorOccurred)
    {
        break;
    }

    TPM_Pcr l_pcrRegs[8] = {PCR_0, PCR_1, PCR_2, PCR_3,
                            PCR_4, PCR_5, PCR_6, PCR_7};
    TPM_Alg_Id l_algIds[1] = {TPM_ALG_SHA256};

    size_t l_sizeToAllocate = getDigestSize(TPM_ALG_SHA256);

    uint8_t* l_pDigest = new uint8_t[l_sizeToAllocate]();
    uint8_t* l_bDigest = new uint8_t[l_sizeToAllocate]();
    size_t l_digestSize = 0;

    // Match the contents of the PCR regs
    for(const auto l_algId : l_algIds)
    {
        l_digestSize = getDigestSize(l_algId);

        for(const auto l_pcrReg : l_pcrRegs)
        {
            l_err = tpmCmdPcrRead(l_primaryTpm,
                                  l_pcrReg,
                                  l_algId,
                                  l_pDigest,
                                  l_digestSize);
            if(l_err)
            {
                TRACFCOMP(g_trac_trustedboot,
                          "testCmpPrimaryAndBackupTpm: failed to read PCR %d"
                          " of primary TPM; algId = 0x%.04x",
                          l_pcrReg,
                          l_algId);
                break;
            }

            l_err = tpmCmdPcrRead(l_backupTpm,
                                  l_pcrReg,
                                  l_algId,
                                  l_bDigest,
                                  l_digestSize);
            if(l_err)
            {
                TRACFCOMP(g_trac_trustedboot,
                          "testCmpPrimaryAndBackupTpm: failed to read PCR %d"
                          " of backup TPM; algId = 0x%.04x",
                          l_pcrReg,
                          l_algId);
                break;
            }

            if(memcmp(l_pDigest, l_bDigest, l_digestSize))
            {
                TRACFCOMP(g_trac_trustedboot,
                          "testCmpPrimaryAndBackupTpm: digests of PCR %d"
                          " algId 0x%.04x do not match!",
                          l_pcrReg,
                          l_algId);
                TRACFBIN(g_trac_trustedboot,
                         "testCmpPrimaryAndBackupTpm: contents of primary TPM's"
                         " PCR:",
                         l_pDigest, l_digestSize);
                TRACFBIN(g_trac_trustedboot,
                         "testCmpPrimaryAndBackupTpm: contents of backup TPM's"
                         " PCR:",
                         l_bDigest, l_digestSize);
                l_rc = TPM_TEST_DIGEST_MISMATCH;
                l_errorOccurred = true;
                break;
            }
            else
            {
                TRACFCOMP(g_trac_trustedboot,
                          "testCmpPrimaryAndBackupTpm: digests of PCR %d, algId"
                          " 0x%.04x match",
                          l_pcrReg,
                          l_algId);
            }
        } // pcrReg

        if(l_err || l_errorOccurred)
        {
            break;
        }
    } // algId

    delete l_pDigest;
    delete l_bDigest;
    l_pDigest = l_bDigest = nullptr;

    } while(0);

    if(!l_err && l_errorOccurred)
    {
        /*@
         * @errortype
         * @reasoncode     RC_BACKUP_TPM_TEST_FAIL
         * @severity       ERRL_SEV_UNRECOVERABLE
         * @moduleid       MOD_TEST_CMP_PRIMARY_AND_BACKUP_TPM
         * @userdata1      return code
         * @userdata2      0
         * @devdesc        TPM testcase error. See the return code for details.
         * @custdesc       Trusted Boot failure.
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      MOD_TEST_CMP_PRIMARY_AND_BACKUP_TPM,
                                      RC_BACKUP_TPM_TEST_FAIL,
                                      l_rc,
                                      0,
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        l_err->collectTrace(SECURE_COMP_NAME);
        l_err->collectTrace(TRBOOT_COMP_NAME);
    }
#endif
    return l_err;
}

errlHndl_t flushTpmQueue()
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    TRACFCOMP(g_trac_trustedboot, ENTER_MRK"flushTpmQueue()");

    Message* l_msg = Message::factory(MSG_TYPE_FLUSH,
                                      0,
                                      nullptr,
                                      MSG_MODE_SYNC);

    assert(l_msg != nullptr, "TPM flush message is nullptr");

    int l_rc = msg_sendrecv(systemData.msgQ, l_msg->iv_msg);
    if(l_rc)
    {
       /*@
        * @errortype       ERRL_SEV_UNRECOVERABLE
        * @moduleid        MOD_FLUSH_TPM_QUEUE
        * @reasoncode      RC_SENDRECV_FAIL
        * @userdata1       rc from msq_sendrecv()
        * @devdesc         msg_sendrecv() failed trying to send flush message to
        *                  TPM daemon
        * @custdesc        Trusted boot failure
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_FLUSH_TPM_QUEUE,
                                         RC_SENDRECV_FAIL,
                                         l_rc,
                                         0,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
    }
    else
    {
        l_errl = l_msg->iv_errl;
        l_msg->iv_errl = nullptr;
    }

    delete l_msg;
    l_msg = nullptr;

    TRACFCOMP(g_trac_trustedboot, EXIT_MRK"flushTpmQueue()");
#endif
    return l_errl;
}

errlHndl_t createAttestationKeys(TpmTarget* i_target)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    Message* l_msg = nullptr;

    TpmTargetData* l_data = new TpmTargetData{i_target};

    l_msg = Message::factory(MSG_TYPE_CREATE_ATT_KEYS,
                             sizeof(*l_data),
                             reinterpret_cast<uint8_t*>(l_data),
                             MSG_MODE_SYNC);
    assert(l_msg != nullptr, "createAttestationKeys: l_msg is nullptr");
    l_data = nullptr; //l_msg now owns l_data

    int l_rc = msg_sendrecv(systemData.msgQ, l_msg->iv_msg);
    if(l_rc)
    {
        /*@
         * @errortype   ERRL_SEV_UNRECOVERABLE
         * @moduleid    MOD_CREATE_ATT_KEYS
         * @reasoncode  RC_SENDRECV_FAIL
         * @userdata1   rc from msg_sendrecv
         * @userdata2   TPM HUID
         * @devdesc     msg_sendrecv failed for createAttestationKeys
         * @custdesc    trustedboot failure
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_CREATE_ATT_KEYS,
                                         RC_SENDRECV_FAIL,
                                         l_rc,
                                         TARGETING::get_huid(i_target),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
    }
    else
    {
        l_errl = l_msg->iv_errl;
        l_msg->iv_errl = nullptr;
    }

    if(l_msg)
    {
        delete l_msg;
        l_msg = nullptr;
    }

#endif
    return l_errl;
}

errlHndl_t readAKCertificate(TpmTarget* i_target, TPM2B_MAX_NV_BUFFER* o_data)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    Message* l_msg = nullptr;

    ReadAKCertData* l_data = new ReadAKCertData {i_target, o_data};

    l_msg = Message::factory(MSG_TYPE_READ_AK_CERT,
                             sizeof(*l_data),
                             reinterpret_cast<uint8_t*>(l_data),
                             MSG_MODE_SYNC);
    assert(l_msg != nullptr, "readAKCertificate: l_msg is nullptr");
    l_data = nullptr; // l_msg now owns l_data

    int l_rc = msg_sendrecv(systemData.msgQ, l_msg->iv_msg);
    if(l_rc)
    {
        /*@
         * @errortype   ERRL_SEV_UNRECOVERABLE
         * @moduleid    MOD_READ_AK_CERT
         * @reasoncode  RC_SENDRECV_FAIL
         * @userdata1   rc from msg_sendrecv
         * @userdata2   TPM HUID
         * @devdesc     msg_sendrecv failed for readAKCertificate
         * @custdesc    trustedboot failure
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_READ_AK_CERT,
                                         RC_SENDRECV_FAIL,
                                         l_rc,
                                         TARGETING::get_huid(i_target),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
    }
    else
    {
        l_errl = l_msg->iv_errl;
        l_msg->iv_errl = nullptr;
    }

    if(l_msg)
    {
        delete l_msg;
        l_msg = nullptr;
    }

#endif
    return l_errl;
}

errlHndl_t generateQuote(TpmTarget* i_target,
                         const TpmNonce_t* const i_nonce,
                         QuoteDataOut* o_data)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    Message* l_msg = nullptr;

    GenQuoteData* l_data = new GenQuoteData{i_target, i_nonce, o_data};

    l_msg = Message::factory(MSG_TYPE_GEN_QUOTE,
                             sizeof(*l_data),
                             reinterpret_cast<uint8_t*>(l_data),
                             MSG_MODE_SYNC);
    assert(l_msg != nullptr, "generateQuote: l_msg is nullptr");
    l_data = nullptr; //l_msg now owns l_data

    int l_rc = msg_sendrecv(systemData.msgQ, l_msg->iv_msg);
    if(l_rc)
    {
        /*@
         * @errortype   ERRL_SEV_UNRECOVERABLE
         * @moduleid    MOD_GEN_QUOTE
         * @reasoncode  RC_SENDRECV_FAIL
         * @userdata1   rc from msg_sendrecv
         * @userdata2   TPM HUID
         * @devdesc     msg_sendrecv failed for generateQuote
         * @custdesc    trustedboot failure
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_GEN_QUOTE,
                                         RC_SENDRECV_FAIL,
                                         l_rc,
                                         TARGETING::get_huid(i_target),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
    }
    else
    {
        l_errl = l_msg->iv_errl;
        l_msg->iv_errl = nullptr;
    }

    if(l_msg)
    {
        delete l_msg;
        l_msg = nullptr;
    }

#endif
    return l_errl;
}

errlHndl_t flushContext(TpmTarget* i_target)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    Message* l_msg = nullptr;

    TpmTargetData* l_data = new TpmTargetData{i_target};

    l_msg = Message::factory(MSG_TYPE_FLUSH_CONTEXT,
                             sizeof(*l_data),
                             reinterpret_cast<uint8_t*>(l_data),
                             MSG_MODE_SYNC);
    assert(l_msg != nullptr, "flushContext: l_msg is nullptr");
    l_data = nullptr;

    int l_rc = msg_sendrecv(systemData.msgQ, l_msg->iv_msg);
    if(l_rc)
    {
        /*@
         * @errortype   ERRL_SEV_UNRECOVERABLE
         * @moduleid    MOD_FLUSH_CONTEXT
         * @reasoncode  RC_SENDRECV_FAIL
         * @userdata1   rc from msg_sendrecv
         * @userdata2   TPM HUID
         * @devdesc     msg_sendrecv failed for TPM2_FlushContext
         * @custdesc    trustedboot failure
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_FLUSH_CONTEXT,
                                         RC_SENDRECV_FAIL,
                                         l_rc,
                                         TARGETING::get_huid(i_target),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
    }
    else
    {
        l_errl = l_msg->iv_errl;
        l_msg->iv_errl = nullptr;
    }

    if(l_msg)
    {
        delete l_msg;
        l_msg = nullptr;
    }

#endif
    return l_errl;
}

errlHndl_t pcrRead(TpmTarget* i_target,
                   const TPM_Pcr i_pcr,
                   const TPM_Alg_Id i_algId,
                   const size_t i_digestSize,
                   uint8_t* const o_digest)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    Message* l_msg = nullptr;

    PcrReadData* l_data = new PcrReadData{i_target,
                                          i_pcr,
                                          i_algId,
                                          o_digest,
                                          i_digestSize};

    l_msg = Message::factory(MSG_TYPE_PCR_READ,
                             sizeof(*l_data),
                             reinterpret_cast<uint8_t*>(l_data),
                             MSG_MODE_SYNC);
    assert(l_msg != nullptr, "pcrRead: l_msg is nullptr");
    l_data = nullptr; //l_msg now owns l_data

    int l_rc = msg_sendrecv(systemData.msgQ, l_msg->iv_msg);
    if(l_rc)
    {
        /*@
         * @errortype   ERRL_SEV_UNRECOVERABLE
         * @moduleid    MOD_PCR_READ
         * @reasoncode  RC_SENDRECV_FAIL
         * @userdata1   rc from msg_sendrecv
         * @userdata2   TPM HUID
         * @devdesc     msg_sendrecv failed for pcrRead
         * @custdesc    trustedboot failure
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_PCR_READ,
                                         RC_SENDRECV_FAIL,
                                         l_rc,
                                         TARGETING::get_huid(i_target),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
    }
    else
    {
        l_errl = l_msg->iv_errl;
        l_msg->iv_errl = nullptr;
    }

    if(l_msg)
    {
        delete l_msg;
        l_msg = nullptr;
    }

#endif
    return l_errl;
}

errlHndl_t expandTpmLog(TpmTarget* i_target)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    Message* l_msg = nullptr;

    TpmTargetData* l_data = new TpmTargetData(i_target);

    l_msg = Message::factory(MSG_TYPE_EXPAND_TPM_LOG,
                             sizeof(*l_data),
                             reinterpret_cast<uint8_t*>(l_data),
                             MSG_MODE_SYNC);
    assert(l_msg, "expandTpmLog: l_msg is nullptr");
    l_data = nullptr; // l_msg now owns l_data

    int l_rc = msg_sendrecv(systemData.msgQ, l_msg->iv_msg);
    if(l_rc)
    {
        /*@
         * @errortype ERRL_SEV_UNRECOVERABLE
         * @moduleid MOD_EXPAND_TPM_LOG
         * @reasoncode RC_SENDRECV_FAIL
         * @userdata1 rc from msg_sendrecv
         * @userdata2 TPM HUID
         * @devdesc msg_sendrecv failed for expandTpmLog
         * @custdesc trustedboot failure
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_EXPAND_TPM_LOG,
                                         RC_SENDRECV_FAIL,
                                         l_rc,
                                         TARGETING::get_huid(i_target),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
    }
    else
    {
        l_errl = l_msg->iv_errl;
        l_msg->iv_errl = nullptr;
    }

    if(l_msg)
    {
        delete l_msg;
        l_msg = nullptr;
    }
#endif
    return l_errl;
}


errlHndl_t groupSbeMeasurementRegs(TARGETING::Target*    i_proc_target,
                                   TPM_sbe_measurements_regs_grouped & o_regs)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD

    do {

    // Get the SBE Measurement Regs
    std::vector<SecureRegisterValues> sbe_regs;
    l_errl = SECUREBOOT::getSbeMeasurementRegisters(sbe_regs, i_proc_target);
    if (l_errl)
    {
        TRACFCOMP(g_trac_trustedboot, ERR_MRK "groupSbeMeasurementRegs() Failed in call to "
                  "SECUREBOOT::getSbeMeasurementRegisters() with target 0x%.08X: "
                  TRACE_ERR_FMT,
                  TARGETING::get_huid(i_proc_target),
                  TRACE_ERR_ARGS(l_errl));
        break;
    }

    // Clear the output struct
    memset(&o_regs, 0, sizeof(o_regs));

    //  Start grouping the registers into the output struct
    // - 0 (0x10010)
    memcpy(&o_regs.sbe_measurement_regs_0[0],
           &sbe_regs[0].data,
           sizeof(uint64_t));

    TRACDBIN(g_trac_trustedboot, "groupSbeMeasurementRegs - _0",
             &o_regs.sbe_measurement_regs_0,
             TPM_SBE_MEASUREMENT_REGS_0_SIZE);

    // - 1 (0x10011)
    memcpy(&o_regs.sbe_measurement_regs_1[0],
           &sbe_regs[1].data,
           sizeof(uint64_t));

    TRACDBIN(g_trac_trustedboot, "groupSbeMeasurementRegs - _1",
             &o_regs.sbe_measurement_regs_1,
             TPM_SBE_MEASUREMENT_REGS_1_SIZE);

    // - 2 (0x10012)
    memcpy(&o_regs.sbe_measurement_regs_2[0],
           &sbe_regs[2].data,
           sizeof(uint64_t));

    TRACDBIN(g_trac_trustedboot, "groupSbeMeasurementRegs - _2",
             &o_regs.sbe_measurement_regs_2[0],
             TPM_SBE_MEASUREMENT_REGS_2_SIZE);

    // - 3 (0x10013)
    memcpy(&o_regs.sbe_measurement_regs_3[0],
           &sbe_regs[3].data,
           sizeof(uint64_t));

    TRACDBIN(g_trac_trustedboot, "groupSbeMeasurementRegs - _3",
             &o_regs.sbe_measurement_regs_3[0],
             TPM_SBE_MEASUREMENT_REGS_3_SIZE);

    // - 4-7   (0x10014-0x10017)
    memcpy(&o_regs.sbe_measurement_regs_4_7[0],
           &sbe_regs[4].data,
           sizeof(uint64_t));
    memcpy(&o_regs.sbe_measurement_regs_4_7[0] + sizeof(uint64_t),
           &sbe_regs[5].data,
           sizeof(uint64_t));
    memcpy(&o_regs.sbe_measurement_regs_4_7[0] + (2*sizeof(uint64_t)),
           &sbe_regs[6].data,
           sizeof(uint64_t));
    memcpy(&o_regs.sbe_measurement_regs_4_7[0] + (3*sizeof(uint64_t)),
           &sbe_regs[7].data,
           sizeof(uint64_t));

    TRACDBIN(g_trac_trustedboot, "groupSbeMeasurementRegs - _4_7",
             &o_regs.sbe_measurement_regs_4_7[0],
             TPM_SBE_MEASUREMENT_REGS_4_7_SIZE);

    // - 8-11  (0x10018-0x1001B)
    memcpy(&o_regs.sbe_measurement_regs_8_11[0],
           &sbe_regs[8].data,
           sizeof(uint64_t));
    memcpy(&o_regs.sbe_measurement_regs_8_11[0] + sizeof(uint64_t),
           &sbe_regs[9].data,
           sizeof(uint64_t));
    memcpy(&o_regs.sbe_measurement_regs_8_11[0] + (2*sizeof(uint64_t)),
           &sbe_regs[10].data,
           sizeof(uint64_t));
    memcpy(&o_regs.sbe_measurement_regs_8_11[0] + (3*sizeof(uint64_t)),
           &sbe_regs[11].data,
           sizeof(uint64_t));

    TRACDBIN(g_trac_trustedboot, "groupSbeMeasurementRegs - _8_11",
             &o_regs.sbe_measurement_regs_8_11[0],
             TPM_SBE_MEASUREMENT_REGS_8_11_SIZE);

    // - 12-15 (0x1001C-0x1001F)
    memcpy(&o_regs.sbe_measurement_regs_12_15[0],
           &sbe_regs[12].data,
           sizeof(uint64_t));
    memcpy(&o_regs.sbe_measurement_regs_12_15[0] + sizeof(uint64_t),
           &sbe_regs[13].data,
           sizeof(uint64_t));
    memcpy(&o_regs.sbe_measurement_regs_12_15[0] + (2*sizeof(uint64_t)),
           &sbe_regs[14].data,
           sizeof(uint64_t));
    memcpy(&o_regs.sbe_measurement_regs_12_15[0] + (3*sizeof(uint64_t)),
           &sbe_regs[15].data,
           sizeof(uint64_t));

    TRACDBIN(g_trac_trustedboot, "groupSbeMeasurementRegs - _12_15",
             &o_regs.sbe_measurement_regs_12_15[0],
             TPM_SBE_MEASUREMENT_REGS_12_15_SIZE);

    TRACFBIN(g_trac_trustedboot, "groupSbeMeasurementRegs - ALL",
             &o_regs, sizeof(o_regs));

    } while(0);
#endif
    return l_errl;
}

errlHndl_t logSbeMeasurementRegs(TpmTarget* i_tpm_target,
                                 TARGETING::Target*    i_proc_target,
                                 const TPM_sbe_measurements_regs_grouped i_regs,
                                 const bool i_extendToTpm)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD

    assert(i_tpm_target != nullptr,"logSbeMeasurementRegs: BUG! i_tpm_target was nullptr");
    assert(i_tpm_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "logSbeMeasurementRegs: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_tpm_target->getAttr<TARGETING::ATTR_TYPE>());

    assert(i_proc_target != nullptr,"logSbeMeasurementRegs: BUG! i_proc_target was nullptr");
    assert(i_proc_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC,
           "logSbeMeasurementRegs: BUG! Expected target to be of PROC type, but "
           "it was of type 0x%08X",i_proc_target->getAttr<TARGETING::ATTR_TYPE>());

    TRACUCOMP(g_trac_trustedboot, ENTER_MRK "logSbeMeasurementRegs(): "
              "tpm=0x%.8X, proc=0x%.8X, i_extendToTpm=%d",
              TARGETING::get_huid(i_tpm_target),
              TARGETING::get_huid(i_proc_target),
              i_extendToTpm);

    Message* l_msg = nullptr;

    LogSbeMeasurementRegs* l_data = new LogSbeMeasurementRegs(i_tpm_target,
                                                              i_proc_target,
                                                              i_regs,
                                                              i_extendToTpm);

    l_msg = Message::factory(MSG_TYPE_LOG_SBE_MEASUREMENT_REGS,
                             sizeof(*l_data),
                             reinterpret_cast<uint8_t*>(l_data),
                             MSG_MODE_SYNC);
    assert(l_msg != nullptr, "logSbeMeasurementRegs: l_msg is nullptr");
    l_data = nullptr; //l_msg now owns l_data

    int l_rc = msg_sendrecv(systemData.msgQ, l_msg->iv_msg);
    if(l_rc)
    {
        /*@
         * @errortype        ERRL_SEV_UNRECOVERABLE
         * @moduleid         MOD_LOG_SBE_MEASUREMENT_REGS
         * @reasoncode       RC_SENDRECV_FAIL
         * @userdata1        rc from msg_sendrecv
         * @userdata2[0:31]  TPM HUID
         * @userdata2[32:63] Processor HUID
         * @devdesc          msg_sendrecv failed for logSbeMeasurementRegs
         * @custdesc         trustedboot failure
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_LOG_SBE_MEASUREMENT_REGS,
                                         RC_SENDRECV_FAIL,
                                         l_rc,
                                         TWO_UINT32_TO_UINT64(
                                           TARGETING::get_huid(i_tpm_target),
                                           TARGETING::get_huid(i_proc_target)),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
    }
    else
    {
        l_errl = l_msg->iv_errl;
        l_msg->iv_errl = nullptr;
    }

    if(l_msg)
    {
        delete l_msg;
        l_msg = nullptr;
    }

    TRACUCOMP(g_trac_trustedboot, EXIT_MRK "logSbeMeasurementRegs()");

#endif
    return l_errl;
}

errlHndl_t synchronizeTpmLog()
{
    errlHndl_t err = nullptr;
#ifdef CONFIG_TPMDD
    TRACUCOMP(g_trac_trustedboot, ENTER_MRK "synchronizeTpmLog()");

    Message* msg = Message::factory(MSG_TYPE_SYNCHRONIZE_TPM_LOG,
                                    0,
                                    nullptr,
                                    MSG_MODE_ASYNC);
    assert(msg !=nullptr, "BUG! Message is nullptr");

    int rc = msg_send(systemData.msgQ, msg->iv_msg);
    if (rc)
    {
        /*@
         * @errortype       ERRL_SEV_UNRECOVERABLE
         * @moduleid        MOD_SYNCHRONIZE_TPM_LOG
         * @reasoncode      RC_SEND_FAIL
         * @userdata1       rc from msq_send()
         * @devdesc         msg_send() failed
         * @custdesc        trustedboot failure
         */
        err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      MOD_SYNCHRONIZE_TPM_LOG,
                                      RC_SEND_FAIL,
                                      rc,
                                      0,
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        err->collectTrace(SECURE_COMP_NAME);
        err->collectTrace(TRBOOT_COMP_NAME);
    }

    TRACUCOMP(g_trac_trustedboot, EXIT_MRK "synchronizeTpmLog() - %s",
              ((nullptr == err) ? "No Error" : "With Error") );

#endif
    return err;
}



} // end TRUSTEDBOOT
