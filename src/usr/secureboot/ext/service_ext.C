/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/ext/service_ext.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
#include <secureboot/service_ext.H>
#include <secureboot/service.H>
#include <targeting/common/util.H>
#include <targeting/common/target.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <secureboot/secure_reasoncodes.H>

#include "../common/securetrace.H"

#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>

#include <p10_update_security_ctrl.H>

#include <securerom/contrib/sha512.H>
#include <sbe/sbe_update.H>
#include <sbe/sbeif.H>
#include <secureboot/common/errlud_secure.H>
#include <initservice/baseinitsvc/initservice.H>
#include <isteps/istep_reasoncodes.H>
#include <targeting/common/mfgFlagAccessors.H>

namespace SECUREBOOT
{

void lockAbusSecMailboxes()
{
#ifdef CONFIG_TPMDD
    errlHndl_t l_errl = nullptr;
    TARGETING::TargetHandleList l_procs;
    getAllChips(l_procs, TARGETING::TYPE_PROC, true);

    auto l_pProc = l_procs.begin();
    while(l_pProc != l_procs.end())
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(*l_pProc);
        FAPI_INVOKE_HWP(l_errl,
                        p10_update_security_ctrl,
                        l_fapiProc,
                        false, // do not force security
                        true); // lock down Abus mailboxes

        if(l_errl)
        {
            SB_ERR("lockAbusSecMailboxes: p10_update_security_ctrl failed for"
                   " proc 0x%X!. Deconfiguring the proc.",
                   TARGETING::get_huid(*l_pProc));

            auto l_plid = l_errl->plid();

            ERRORLOG::ErrlUserDetailsTarget(*l_pProc).addToLog(l_errl);
            ERRORLOG::errlCommit(l_errl, SECURE_COMP_ID);

            /*
             * @errortype
             * @reasoncode RC_LOCK_MAILBOXES_FAILED
             * @moduleid   MOD_LOCK_ABUS_SEC_MAILBOXES
             * @userdata1  Target HUID
             * @devdesc    Failed to lock Abus secure mailboxes
             *             on target processor.
             * @custdesc   Secure Boot failure
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            SECUREBOOT::MOD_LOCK_ABUS_SEC_MAILBOXES,
                            SECUREBOOT::RC_LOCK_MAILBOXES_FAILED,
                            TARGETING::get_huid(*l_pProc),
                            0,
                            true);
            l_errl->addHwCallout(*l_pProc,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::DELAYED_DECONFIG,
                                 HWAS::GARD_NULL);
            l_errl->collectTrace(SECURE_COMP_NAME);
            l_errl->collectTrace(FAPI_TRACE_NAME);
            l_errl->plid(l_plid);
            ERRORLOG::ErrlUserDetailsTarget(*l_pProc).addToLog(l_errl);

            ERRORLOG::errlCommit(l_errl, SECURE_COMP_ID);
        }

        ++l_pProc;

    } // while
#endif
}

/**
 * @brief This structure associates SBE HW keys' hashes with names and SBE sides
 */
struct HashNode
{
    SHA512_t hash; /** SBE HW keys' hash for the named side */
    const char* name; /** Name of the side: either primary or backup */
    uint8_t side; /** A uint8_t value of 0 for primary or 1 for backup */
    uint8_t secure_version; /** Secure Version for the named side */
    HashNode(const char* i_name,
             uint8_t i_side,
             uint8_t i_secure_version)
             : name(i_name), side(i_side), secure_version(i_secure_version)
    {
        memset(hash, 0, SHA512_DIGEST_LENGTH);
    }
};


/**
 * @brief This union simplifies bitwise operations for tracking the four
 * conditions of mismatch when matching security settings of a backup processor
 * with that of the primary processor.
 */
union Mismatches
{
    uint8_t val;
    struct {
        uint8_t reserved   : 2; /** unused */

        uint8_t primisSV   : 1; /** Value of 1 indicates the primary SBE Secure Version
                                 *  did not match, 0 otherwise.
                                 */
        uint8_t bacmisSV   : 1; /** Value of 1 indicates the backup SBE Secure Version
                                 *  did not match, 0 otherwise.
                                 */
        uint8_t sabmis     : 1; /** Value of 1 indicates the SAB bit didn't match,
                                 *  0 otherwise.
                                 */
        uint8_t smdmis     : 1; /** Value of 1 indicates the SMD bit did not match,
                                 *  0 otherwise.
                                 */
        uint8_t primisHKH  : 1; /** Value of 1 indicates the primary SBE HW Keys' Hash
                                 *  did not match, 0 otherwise.
                                 */
        uint8_t bacmisHKH  : 1; /** Value of 1 indicates the backup SBE HW Keys' Hash
                                 *  did not match, 0 otherwise.
                                 */
    };
};

/** @brief Handle a processor security error.
 *  @par Detailed Description:
 *      Puts all the error handling for mismatched processor security
 *      settings in one place in order to minimize code footprint. This
 *      highly-specialized function is not intended for public consumption.
 *  @param[in] i_pProc The target processor whose secure processor settings are
 *      exhibiting a problem. Must not be null.
 *  @param[in] i_rc The reason code of the error to be handled.
 *  @param[in] i_hashes A vector containing hash/string/side triples, where
 *      the string indicates the name of the hash, and the side refers to the
 *      SBE side that the hash was taken from.
 *  @param[in] i_plid If non zero this plid from a previous error will be linked
 *      To the error created by this function, ignored otherwise.
 *  @param[in] i_continue A boolean indicating whether hostboot should continue
 *      booting (and deconfigure the processor) or stop the IPL.
 *  @param[in] i_mismatches A bitstring of mismatch bits of type Mismatches
 *      corresponding to a mismatch of the SAB or SMD register or primary or
 *      secondary SBE HW Keys'Hash or Secure Version between the supplied target and the
 *      primary processor. Optional parameter is for the RC_PROC_SECURITY_STATE_MISMATCH
 *      case only and must be left as default (value of 0) for all other cases.
 */
static void handleProcessorSecurityError(TARGETING::Target* i_pProc,
                ISTEP::istepReasonCode i_rc,
                const std::vector<HashNode>& i_hashes,
                uint32_t i_plid,
                bool i_continue,
                Mismatches i_mismatches={0})
{
    using namespace ISTEP;

    // stop the caller from passing a null target
    assert(i_pProc != nullptr, "handleProcessorSecurityError: Bug! Target pointer must not be null");

    // make sure that caller is using the Mismatches parameter at the right time
    assert( (i_rc!=RC_PROC_SECURITY_STATE_MISMATCH && !i_mismatches.val) ||
            (i_rc==RC_PROC_SECURITY_STATE_MISMATCH && i_mismatches.val),
            "handleProcessorSecurityError: Mismatches parameter is for RC_PROC_SECURITY_STATE_MISMATCH only");

    ERRORLOG::errlSeverity_t l_severity = ERRORLOG::ERRL_SEV_UNRECOVERABLE;

    // Look for the mismatch errors
    if (i_rc==RC_PRIMARY_PROC_SBE_KEYS_HASH_MISMATCH ||
        i_rc==RC_PROC_SECURITY_STATE_MISMATCH ||
        i_rc==RC_PRIMARY_PROC_SECURE_VERSION_MISMATCH)
    {
        if (i_rc==RC_PROC_SECURITY_STATE_MISMATCH)
        {
            SB_ERR("handleProcessorSecurityError: processor state doesn't match primary for processor tgt=0x%X",
                   TARGETING::get_huid(i_pProc));

            SB_INF("SMD is a %smatch", i_mismatches.smdmis? "mis": "");
            SB_INF("SAB is a %smatch", i_mismatches.sabmis? "mis": "");
            SB_INF("Primary SBE hash is a %smatch",
                   i_mismatches.primisHKH? "mis": "");
            SB_INF("Backup SBE hash is a %smatch",
                    i_mismatches.bacmisHKH? "mis": "");
            SB_INF("Primary SBE Secure Version is a %smatch",
                    i_mismatches.primisSV? "mis": "");
            SB_INF("Backup SBE Secure Version is a %smatch",
                    i_mismatches.bacmisSV? "mis": "");
        }
        else  // primary proc sbe keys' hash mismatch
        {
            SB_ERR("handleProcessorSecurityError: Primary processor sbe keys' hash doesn't match backup sbe key's hash");
        }

        // Log as informational if secure boot is disabled
        if (!SECUREBOOT::enabled())
        {
            l_severity = ERRORLOG::ERRL_SEV_INFORMATIONAL;
        }
    }
    else
    {
        SB_INF("handleProcessorSecurityError: Istep error occurred, reason code 0x%X",
               i_rc);
        SB_DBG("handleProcessorSecurityError: %s fail",
        i_rc==RC_PRIMARY_PROC_PRIMARY_HASH_READ_FAIL?"Primary proc primary SBE hash/SV read":
        i_rc==RC_PRIMARY_PROC_BACKUP_HASH_READ_FAIL?"Primary proc backup SBE hash/SV read":
        i_rc==RC_PRIMARY_PROC_CBS_CONTROL_READ_FAIL?"Primary proc CBS control read":
        i_rc==RC_PRIMARY_GET_SBE_BOOT_SEEPROM_FAIL?"Primary proc get SBE boot Seeprom":
        i_rc==RC_SECONDARY_PROC_PRIMARY_HASH_READ_FAIL?"Secondary proc primary SBE hash/SV read":
        i_rc==RC_SECONDARY_PROC_BACKUP_HASH_READ_FAIL?"Secondary proc backup SBE hash/SV read":
        i_rc==RC_SECONDARY_PROC_CBS_CONTROL_READ_FAIL?"Secondary proc CBS control read":
        i_rc==RC_SECONDARY_GET_SBE_BOOT_SEEPROM_FAIL?"Secondary proc get SBE Boot Seeprom":
        "unknown");
    }

    auto err = new ERRORLOG::ErrlEntry(l_severity,
                                       ISTEP::MOD_VALIDATE_SECURITY_SETTINGS,
                                       i_rc,
                                       TARGETING::get_huid(i_pProc),
                                       TO_UINT64(i_mismatches.val),
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

    // if a plid was given, link it to the new error.
    if (i_plid)
    {
        err->plid(i_plid);
    }

    err->collectTrace(ISTEP_COMP_NAME);

    ERRORLOG::ErrlUserDetailsTarget(i_pProc).addToLog(err);

    // Add Security related user details
    SECUREBOOT::addSecureUserDetailsToErrlog(err);

    // add hashes to log and traces
    for(auto& hsh : i_hashes)
    {
        SB_ERR("handleProcessorSecurityError: %s hash: ", hsh.name);
        SB_ERR("handleProcessorSecurityError: Secure Version = 0x%.2X",
               hsh.secure_version);
        SB_INF_BIN("Data = ",
                   hsh.hash,
                   SHA512_DIGEST_LENGTH);
        SECUREBOOT::UdTargetHwKeyHash(i_pProc,
                                      hsh.side,
                                      hsh.hash,
                                      hsh.secure_version).addToLog(err);
    }

    if (i_continue)
    {
         err->addHwCallout(i_pProc,
                           HWAS::SRCI_PRIORITY_LOW,
                           (i_mismatches.val && // for any mismatch
                           i_rc != RC_PRIMARY_PROC_SBE_KEYS_HASH_MISMATCH) ?
                                HWAS::NO_DECONFIG: // don't deconfig the processor
                                HWAS::DELAYED_DECONFIG,
                           HWAS::GARD_NULL);
    }

    // save off reason code before committing
    const auto l_reason = err->reasonCode();

    ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

    if (!i_continue)
    {
        SB_INF("Terminating because future security cannot be guaranteed.");
        INITSERVICE::doShutdown(l_reason);
    }
}

//*****************************************************************************
// validateSecuritySettings()
//*****************************************************************************
/*
 * @brief Enforce synchronized processor security states
 */
void validateSecuritySettings()
{
    SB_ENTER("validateSecuritySettings");

    errlHndl_t err = nullptr;

    // Before update procedure, trace security settings
    err = SECUREBOOT::traceSecuritySettings();
    if (err)
    {
        SB_INF("validateSecuritySettings: Error back from SECUREBOOT::traceSecuritySettings: rc=0x%X, plid=0x%X",
               ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

        // Commit log, but continue
        ERRORLOG::errlCommit( err, SECURE_COMP_ID );
    }

    #ifdef CONFIG_SECUREBOOT
    // Enforce Synchronized Proc Security State
    do {

    uint64_t l_mainCbs = 0;

    // we need to know if we're in manufacturing mode to do some logic later
    bool mnfg_mode = TARGETING::areAllSrcsTerminating();

    // a list of hashes we will be using to match primary SBE to backup SBE and
    // primary procs to secondary procs
    std::vector<HashNode> l_hashes;

    // nodes for the hashes vector only to be added to vector as needed
    auto l_primaryProcPrimarySBE = HashNode("primary proc primary SBE", SBE::SBE_SEEPROM0, INVALID_SECURE_VERSION);
    auto l_primaryProcSecondarySBE = HashNode("primary proc backup SBE", SBE::SBE_SEEPROM1, INVALID_SECURE_VERSION);
    auto l_secondaryProcPrimarySBE = HashNode("secondary proc primary SBE", SBE::SBE_SEEPROM0, INVALID_SECURE_VERSION);
    auto l_secondaryProcBackupSBE = HashNode("secondary proc backup SBE", SBE::SBE_SEEPROM1, INVALID_SECURE_VERSION);

    // obtain the primary processor target
    TARGETING::Target* mProc = nullptr;
    err = TARGETING::targetService().queryMasterProcChipTargetHandle(mProc);
    if (err)
    {
        // if this happens we are in big trouble
        const auto rc = err->reasonCode();
        ERRORLOG::errlCommit(err, ISTEP_COMP_ID);
        SB_INF("Terminating because future security cannot be guaranteed.");
        INITSERVICE::doShutdown(rc);
    }

    // read the CBS control register of the main processor
    // (has SAB/SMD bits)
    err = SECUREBOOT::getProcCbsControlRegister(l_mainCbs, mProc);
    if (err)
    {
        const auto plid = err->plid();
        ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

        /*@
         * @errortype
         * @reasoncode       ISTEP::RC_PRIMARY_PROC_CBS_CONTROL_READ_FAIL
         * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
         * @userdata1        Primary Processor Target
         * @devdesc          Unable to read the primary processor CBS control
         *                   register
         * @custdesc         Platform security problem detected
         */
        handleProcessorSecurityError(mProc,
                                     ISTEP::RC_PRIMARY_PROC_CBS_CONTROL_READ_FAIL,
                                     l_hashes,
                                     plid,
                                     false); // stop IPL and deconfig processor
    }

    SBE::sbeSeepromSide_t bootSide = SBE::SBE_SEEPROM_INVALID;
    err = SBE::getSbeBootSeeprom(mProc, bootSide);
    if (err)
    {
        const auto plid = err->plid();
        ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

        /*@
         * @errortype
         * @reasoncode       ISTEP::RC_PRIMARY_GET_SBE_BOOT_SEEPROM_FAIL
         * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
         * @userdata1        Primary Processor Target
         * @devdesc          Unable to get the primary SBE boot seeprom side
         *
         * @custdesc         Platform security problem detected
         */
        handleProcessorSecurityError(mProc,
                                     ISTEP::RC_PRIMARY_GET_SBE_BOOT_SEEPROM_FAIL,
                                     l_hashes,
                                     plid,
                                     false); // stop IPL and deconfig processor
    }

    bool primaryReadFailAllowed = false;

    // read the primary sbe HW keys' hash and secure version for the primary processor
    err = SBE::getSecuritySettingsFromSbeImage(mProc,
                                               EEPROM::SBE_PRIMARY,
                                               bootSide,
                                               l_primaryProcPrimarySBE.hash,
                                               l_primaryProcPrimarySBE.secure_version);
    if (err)
    {
        if (!mnfg_mode && bootSide != SBE::SBE_SEEPROM0)
        {
            primaryReadFailAllowed = true;
            SB_INF("It's a non-mnfg boot and we failed to read the primary proc primary HW SBE Keys' hash and Secure Version from seeprom 0. Ignoring the error since we didn't boot from that seeprom");
            err->collectTrace(ISTEP_COMP_NAME);
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);
        }
        else
        {
            const auto plid = err->plid();
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

            /*@
             * @errortype
             * @reasoncode      ISTEP::RC_PRIMARY_PROC_PRIMARY_HASH_READ_FAIL
             * @moduleid        ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
             * @userdata1       Primary Processor Target
             * @devdesc         Unable to read the primary processor primary hash
             *                  from the SBE
             * @custdesc         Platform security problem detected
             */
            handleProcessorSecurityError(mProc,
                                         ISTEP::RC_PRIMARY_PROC_PRIMARY_HASH_READ_FAIL,
                                         l_hashes,
                                         plid,
                                         false); // stop IPL and deconfig processor
        }
    }

    bool backupReadFailAllowed = false;

    // read the backup sbe HW keys' hash for the primary processor
    err = SBE::getSecuritySettingsFromSbeImage(mProc,
                                               EEPROM::SBE_BACKUP,
                                               bootSide,
                                               l_primaryProcSecondarySBE.hash,
                                               l_primaryProcSecondarySBE.secure_version);

    if (err)
    {
        if (!mnfg_mode && bootSide != SBE::SBE_SEEPROM1)
        {
            backupReadFailAllowed = true;
            SB_INF("It's a non-mnfg boot and we failed to read the primary proc backup HW SBE Keys' hash and Secure Version from seeprom 1. Ignoring the error since we didn't boot from that seeprom");
            err->collectTrace(ISTEP_COMP_NAME);
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);
        }
        else
        {
            const auto plid = err->plid();
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

            /*@
             * @errortype
             * @reasoncode       ISTEP::RC_PRIMARY_PROC_BACKUP_HASH_READ_FAIL
             * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
             * @userdata1        Processor Target
             * @devdesc          Unable to read the primary processor backup hash
             *                   from the SBE
             * @custdesc         Platform security problem detected
             */
            handleProcessorSecurityError(mProc,
                                         ISTEP::RC_PRIMARY_PROC_BACKUP_HASH_READ_FAIL,
                                         l_hashes,
                                         plid,
                                         false); // stop IPL and deconfig processor
        }
    }

    // make sure the primary processor's primary and backup SBE HW keys' hashes
    // match each other.
    if (primaryReadFailAllowed)
    {
        memcpy(l_primaryProcPrimarySBE.hash, l_primaryProcSecondarySBE.hash, SHA512_DIGEST_LENGTH);
        l_primaryProcPrimarySBE.secure_version = l_primaryProcSecondarySBE.secure_version;
    }
    else if (backupReadFailAllowed)
    {
        memcpy(l_primaryProcSecondarySBE.hash, l_primaryProcPrimarySBE.hash, SHA512_DIGEST_LENGTH);
        l_primaryProcSecondarySBE.secure_version = l_primaryProcPrimarySBE.secure_version;
    }
    else if(memcmp(l_primaryProcPrimarySBE.hash, l_primaryProcSecondarySBE.hash, SHA512_DIGEST_LENGTH)!=0)
    {
        // add only the hashes relevant to the error to hashes vector
        l_hashes.push_back(l_primaryProcPrimarySBE);
        l_hashes.push_back(l_primaryProcSecondarySBE);

       bool l_continue = !SECUREBOOT::enabled();
        /*@
         * @errortype
         * @reasoncode       ISTEP::RC_PRIMARY_PROC_SBE_KEYS_HASH_MISMATCH
         * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @userdata1        Primary Processor Target
         * @devdesc          The primary SBE HW Keys' hash does not match the
         *                   the backup SBE HW Keys' hash, so we cannot
         *                   guarantee platform security for the system
         * @custdesc         Platform security problem detected
         */
        handleProcessorSecurityError(mProc,
                                     ISTEP::RC_PRIMARY_PROC_SBE_KEYS_HASH_MISMATCH,
                                     l_hashes,
                                     0,
                                     l_continue); // stop IPL if secureboot enabled

        break;
    }
    else if (l_primaryProcPrimarySBE.secure_version != l_primaryProcSecondarySBE.secure_version)
    {
        // add only the hashes relevant to the error to hashes vector
        l_hashes.push_back(l_primaryProcPrimarySBE);
        l_hashes.push_back(l_primaryProcSecondarySBE);

       bool l_continue = !SECUREBOOT::enabled();
        /*@
         * @errortype
         * @reasoncode       ISTEP::RC_PRIMARY_PROC_SECURE_VERSION_MISMATCH
         * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @userdata1        Primary Processor Target
         * @devdesc          The primary SBE HW Keys' hash does not match
         *                   the backup SBE HW Keys' hash, so we cannot
         *                   guarantee platform security for the system
         * @custdesc         Platform security problem detected
         */
        handleProcessorSecurityError(mProc,
                                     ISTEP::RC_PRIMARY_PROC_SECURE_VERSION_MISMATCH,
                                     l_hashes,
                                     0,
                                     l_continue); // stop IPL if secureboot enabled

        break;
    }

    SB_INF("Primary proc Primary SBE HW keys' hash and Secure Version successfully match backup.");

    TARGETING::TargetHandleList l_procList;
    getAllChips(l_procList,TARGETING::TYPE_PROC,true);

    for(auto pProc : l_procList)
    {
        uint64_t l_procCbs = 0;

        if (mProc == pProc)
        {
            // skip the primary processor
            continue;
        }

        // start with empty secondary proc hashes each time through the loop
        memset(l_secondaryProcPrimarySBE.hash,0,SHA512_DIGEST_LENGTH);
        memset(l_secondaryProcBackupSBE.hash,0,SHA512_DIGEST_LENGTH);
        l_secondaryProcPrimarySBE.secure_version = INVALID_SECURE_VERSION;
        l_secondaryProcBackupSBE.secure_version = INVALID_SECURE_VERSION;

        // read the CBS control register of the current processor
        err = SECUREBOOT::getProcCbsControlRegister(l_procCbs, pProc);
        if (err)
        {
            const auto plid = err->plid();
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

            /*@
             * @errortype
             * @reasoncode       ISTEP::RC_SECONDARY_PROC_CBS_CONTROL_READ_FAIL
             * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
             * @userdata1        Secondary Processor Target
             * @devdesc          Unable to read the secondary processor CBS control
             *                   register
             *
             * @custdesc         Platform security problem detected
             */
            handleProcessorSecurityError(pProc,
                                         ISTEP::RC_SECONDARY_PROC_CBS_CONTROL_READ_FAIL,
                                         l_hashes,
                                         plid,
                                         true); // deconfigure proc and move on
            continue;
        }

        bootSide = SBE::SBE_SEEPROM_INVALID;
        err = getSbeBootSeeprom(pProc, bootSide, false);
        if (err)
        {
            const auto plid = err->plid();
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

            /*@
             * @errortype
             * @reasoncode       ISTEP::RC_SECONDARY_GET_SBE_BOOT_SEEPROM_FAIL
             * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
             * @userdata1        Secondary Processor Target
             * @devdesc          Unable to get the secondary proc SBE boot seeprom side
             *
             * @custdesc         Platform security problem detected
             */
            handleProcessorSecurityError(pProc,
                                         ISTEP::RC_SECONDARY_GET_SBE_BOOT_SEEPROM_FAIL,
                                         l_hashes,
                                         plid,
                                         true); // deconfigure proc and move on
            continue;
        }

        bool skipPrimaryMatch = false;

        // read the primary sbe HW keys' hash for the current processor
        err = SBE::getSecuritySettingsFromSbeImage(pProc,
                                                   EEPROM::SBE_PRIMARY,
                                                   bootSide,
                                                   l_secondaryProcPrimarySBE.hash,
                                                   l_secondaryProcPrimarySBE.secure_version);

        if (err)
        {

            if (!mnfg_mode && bootSide != SBE::SBE_SEEPROM0)
            {
                skipPrimaryMatch = true;
                SB_INF("It's a non-mnfg boot and we failed to read the HW SBE Keys' hash and Secure Version from seeprom 0, HUID:0x%.8X. Ignoring the error since we didn't boot from that seeprom", TARGETING::get_huid(pProc));
                err->collectTrace(ISTEP_COMP_NAME);
                ERRORLOG::errlCommit(err, ISTEP_COMP_ID);
            }
            else
            {
                const auto plid = err->plid();
                ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

                /*@
                 * @errortype
                 * @reasoncode       ISTEP::RC_SECONDARY_PROC_PRIMARY_HASH_READ_FAIL
                 * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
                 * @userdata1        Secondary Processor Target
                 * @devdesc          Unable to read the secondary processor primary
                 *                   hash from the SBE
                 * @custdesc         Platform security problem detected
                 */
                handleProcessorSecurityError(pProc,
                                             ISTEP::RC_SECONDARY_PROC_PRIMARY_HASH_READ_FAIL,
                                             l_hashes,
                                             plid,
                                             true); // deconfigure proc and move on
                continue;
            }
        }

        bool skipBackupMatch = false;

        // read the backup sbe HW keys' hash for the current processor
        err = SBE::getSecuritySettingsFromSbeImage(pProc,
                                                   EEPROM::SBE_BACKUP,
                                                   bootSide,
                                                   l_secondaryProcBackupSBE.hash,
                                                   l_secondaryProcBackupSBE.secure_version);
        if (err)
        {
            if (!mnfg_mode && bootSide != SBE::SBE_SEEPROM1)
            {
                skipBackupMatch = true;
                SB_INF("It's a non-mnfg boot and we failed to read the HW SBE Keys' hash and Secure Version from seeprom 1, HUID:0x%.8X Ignoring the error since we didn't boot from that seeprom", TARGETING::get_huid(pProc));
                err->collectTrace(ISTEP_COMP_NAME);
                ERRORLOG::errlCommit(err, ISTEP_COMP_ID);
            }
            else
            {
                const auto plid = err->plid();
                ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

                /*@
                 * @errortype
                 * @reasoncode       ISTEP::RC_SECONDARY_PROC_BACKUP_HASH_READ_FAIL
                 * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
                 * @userdata1        Secondary Processor Target
                 * @devdesc          Unable to read the secondary processor backup
                 *                   hash from the SBE
                 * @custdesc         Platform security problem detected
                 */
                handleProcessorSecurityError(pProc,
                                             ISTEP::RC_SECONDARY_PROC_BACKUP_HASH_READ_FAIL,
                                             l_hashes,
                                             plid,
                                             true); // deconfigure proc and move on

                continue;
            }
        }

        // If the current processor has a key or SAB mismatch
        // then throw a terminate error. For SMD mismatch we throw
        // an informational error
        Mismatches l_mismatches = {0};

        // SAB bit mismatch
        l_mismatches.sabmis =
                      (SECUREBOOT::ProcCbsControl::SabBit & l_mainCbs) !=
                       (SECUREBOOT::ProcCbsControl::SabBit & l_procCbs);

        // Jumper state mismatch
        l_mismatches.smdmis =
                (SECUREBOOT::ProcCbsControl::JumperStateBit & l_mainCbs) !=
                 (SECUREBOOT::ProcCbsControl::JumperStateBit & l_procCbs);

        // primary sbe hash mismatch
        if (!skipPrimaryMatch)
        {
            l_mismatches.primisHKH = memcmp(l_secondaryProcPrimarySBE.hash,
                                            l_primaryProcPrimarySBE.hash,
                                            SHA512_DIGEST_LENGTH) != 0;
        }

        // backup sbe hash mismatch
        if (!skipBackupMatch)
        {
            l_mismatches.bacmisHKH = memcmp(l_secondaryProcBackupSBE.hash,
                                            l_primaryProcPrimarySBE.hash,
                                            SHA512_DIGEST_LENGTH) != 0;
        }

        // primary sbe secure version mismatch
        if (!skipPrimaryMatch)
        {
            l_mismatches.primisSV = (l_secondaryProcPrimarySBE.secure_version != l_primaryProcPrimarySBE.secure_version);
        }

        // backup sbe secure version mismatch
        if (!skipBackupMatch)
        {
            l_mismatches.bacmisSV = (l_secondaryProcBackupSBE.secure_version != l_primaryProcPrimarySBE.secure_version);
        }

        // only provide the relevant hashes for error handling cases
        if(l_mismatches.primisHKH || l_mismatches.bacmisHKH ||
           l_mismatches.primisSV  || l_mismatches.bacmisSV)
        {
            l_hashes.push_back(l_primaryProcPrimarySBE);
        }
        if(l_mismatches.primisHKH || l_mismatches.primisSV)
        {
            l_hashes.push_back(l_secondaryProcPrimarySBE);
        }
        if(l_mismatches.bacmisHKH || l_mismatches.bacmisSV)
        {
            l_hashes.push_back(l_secondaryProcBackupSBE);
        }

        // if there was any mismatch
        if (l_mismatches.val)
        {
            auto l_continue = true;
            // do not continue booting if there is a SAB mismatch under any
            // circumstance
            if (l_mismatches.sabmis)
            {
                l_continue = false;
            }
            // In secure mode, do not continue booting when SBE HW keys' hashes
            // or Secure Verions are mismatched
            if ((l_mismatches.primisHKH || l_mismatches.bacmisHKH ||
                 l_mismatches.primisSV  || l_mismatches.bacmisSV)
                 && SECUREBOOT::enabled())
            {
                l_continue = false;
            }

            /*@
             * @errortype
             * @reasoncode       ISTEP::RC_PROC_SECURITY_STATE_MISMATCH
             * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
             * @userdata1        Processor Target
             * @userdata2[63]    Backup SBE hash mismatch
             * @userdata2[62]    Primary SBE hash mismatch
             * @userdata2[61]    Jumper (SMD) bit mismatch
             * @userdata2[60]    SAB bit mismatch
             * @userdata2[59]    Backup SBE Secure Version mismatch
             * @userdata2[58]    Primary SBE Secure Version mismatch
             * @devdesc          Mismatch processor state was detected for this
             *                   processor, so we cannot guarantee platform
             *                   security for the system
             * @custdesc         Platform security problem detected
             */
            handleProcessorSecurityError(pProc,
                                         ISTEP::RC_PROC_SECURITY_STATE_MISMATCH,
                                         l_hashes,
                                         0,
                                         l_continue,
                                         l_mismatches);

            // In non-secure mode, look for other inconsistencies and log the
            // issues
            if (l_continue)
            {
                continue;
            }
            // In secure mode,  stop checking for proc security state mismatches
            // as soon as a mismatch has been found
            break;
        }

    }

    } while(0);

    #endif // CONFIG_SECUREBOOT

    SB_EXIT("validateSecuritySettings");
}

} // namespace SECUREBOOT
