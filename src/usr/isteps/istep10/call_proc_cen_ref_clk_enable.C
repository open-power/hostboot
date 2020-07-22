/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_cen_ref_clk_enable.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
 *  @file call_proc_cen_ref_clk_enable.C
 *
 *  Support file for IStep: slave_sbe
 *   Slave SBE
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <initservice/initsvcreasoncodes.H>
#include <sys/time.h>
#include <devicefw/userif.H>
#include <i2c/i2cif.H>
#include <p9_cen_ref_clk_enable.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/namedtarget.H>
#include <targeting/attrsync.H>

//  fapi support
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <isteps/hwpisteperror.H>

#include <errl/errludtarget.H>

// Note: The following secureboot-related includes will be kept separate from
// any other includes in this file in spite of the resulting duplicate includes.
// This will make it easier going forward to relocate the code that requires
// these includes. In the past isteps have been moved around, causing the
// security code below to slip farther away from the SBE update step. For
// maximal security, we want the secure boot code to happen immediately after
// SBE update and keeping the code relocateable facilitates this.

// begin includes for post sbe secureboot steps
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/istep_reasoncodes.H>
#include <initservice/initserviceif.H>

// targeting support
#include <targeting/common/target.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <errl/errludtarget.H>
#include <attributetraits.H>

#include <util/align.H>
#include <util/algorithm.H>

// Fapi Support
#include <fapi2.H>
#include <target_types.H>
#include <plat_hwp_invoker.H>
#include <attributeenums.H>
#include <istepHelperFuncs.H>

//HWP
#include <p9_update_security_ctrl.H>

#ifdef CONFIG_AXONE
#include <p9a_ocmb_enable.H>
#include <exp_check_for_ready.H>
#endif

// secureboot
#include <secureboot/service.H>
#include <secureboot/settings.H>
#include <i2c/eepromif.H>
#include <sbe/sbeif.H>
#include "../../secureboot/common/errlud_secure.H"
#include <sbe/sbe_update.H>

#ifdef CONFIG_SECUREBOOT
#include <secureboot/service.H>
#include <scom/centaurScomCache.H>
#endif

// end includes for post sbe secureboot steps

const uint64_t MS_TO_WAIT_FIRST = 2500; //(2.5 s)
const uint64_t MS_TO_WAIT_OTHERS= 100; //(100 ms)

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_10
{

#ifdef CONFIG_SECUREBOOT
/**
 * @brief This structure associates SBE HW keys' hashes with names and SBE sides
 */
struct HashNode
{
    uint8_t* hash; /** SBE HW keys' hash for the named side */
    const char* name; /** Name of the side: either primary or backup */
    uint8_t side; /** A uint8_t value of 0 for primary or 1 for backup */
    uint8_t* secure_version; /** Secure Version for the named side */
    HashNode(uint8_t* i_hash,
             const char* i_name,
             uint8_t i_side,
             uint8_t* i_secure_version)
             : hash(i_hash), name(i_name), side(i_side), secure_version(i_secure_version)
    {
    }
};

/**
 * @brief This union simplifies bitwise operations for tracking the four
 * conditions of mismatch when matching security settings of a slave processor
 * with that of the master processor.
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
 *      master processor. Optional parameter is for the RC_PROC_SECURITY_STATE_MISMATCH
 *      case only and must be left as default (value of 0) for all other cases.
 */
void handleProcessorSecurityError(TARGETING::Target* i_pProc,
                ISTEP::istepReasonCode i_rc,
                const std::vector<HashNode>& i_hashes,
                uint16_t i_plid,
                bool i_continue,
                Mismatches i_mismatches={0})
{
    using namespace ISTEP;

    // stop the caller from passing a null target
    assert(i_pProc != nullptr, "Bug! Target pointer must not be null");

    // make sure that caller is using the Mismatches parameter at the right time
    assert( (i_rc!=RC_PROC_SECURITY_STATE_MISMATCH && !i_mismatches.val) ||
            (i_rc==RC_PROC_SECURITY_STATE_MISMATCH && i_mismatches.val),
            "Mismatches parameter is for RC_PROC_SECURITY_STATE_MISMATCH only");

    ERRORLOG::errlSeverity_t l_severity = ERRORLOG::ERRL_SEV_UNRECOVERABLE;

    // Look for the mismatch errors
    if (i_rc==RC_MASTER_PROC_SBE_KEYS_HASH_MISMATCH ||
        i_rc==RC_PROC_SECURITY_STATE_MISMATCH ||
        i_rc==RC_MASTER_PROC_SECURE_VERSION_MISMATCH)
    {
        if (i_rc==RC_PROC_SECURITY_STATE_MISMATCH)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    ERR_MRK"handleProcessorSecurityError: processor state doesn't match master for processor tgt=0x%X",
                    TARGETING::get_huid(i_pProc));

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "SMD is a %smatch", i_mismatches.smdmis? "mis": "");
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "SAB is a %smatch", i_mismatches.sabmis? "mis": "");
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Primary SBE hash is a %smatch",
                    i_mismatches.primisHKH? "mis": "");
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Backup SBE hash is a %smatch",
                    i_mismatches.bacmisHKH? "mis": "");
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Primary SBE Secure Version is a %smatch",
                    i_mismatches.primisSV? "mis": "");
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Backup SBE Secure Version is a %smatch",
                    i_mismatches.bacmisSV? "mis": "");
        }
        else  // master proc sbe keys' hash mismatch
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK"handleProcessorSecurityError: Master processor sbe keys' hash doesn't match master backup sbe key's hash");
        }

        // Log as informational if secure boot is disabled
        if (!SECUREBOOT::enabled())
        {
            l_severity = ERRORLOG::ERRL_SEV_INFORMATIONAL;
        }
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "handleProcessorSecurityError: Istep error occurred, reason code 0x%X"
            ,i_rc);
        TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            ERR_MRK"handleProcessorSecurityError: %s fail",

        i_rc==RC_MASTER_PROC_PRIMARY_HASH_READ_FAIL?"Master primary hash/SV read":
        i_rc==RC_MASTER_PROC_BACKUP_HASH_READ_FAIL?"Master backup hash/SV read":
        i_rc==RC_MASTER_PROC_CBS_CONTROL_READ_FAIL?"Master CBS control read":
        i_rc==RC_MASTER_GET_SBE_BOOT_SEEPROM_FAIL?"Master get SBE boot Seeprom":
        i_rc==RC_SLAVE_PROC_PRIMARY_HASH_READ_FAIL?"Slave primary hash/SV read":
        i_rc==RC_SLAVE_PROC_BACKUP_HASH_READ_FAIL?"Slave backup hash/SV read":
        i_rc==RC_SLAVE_PROC_CBS_CONTROL_READ_FAIL?"Slave CBS control read":
        i_rc==RC_SLAVE_GET_SBE_BOOT_SEEPROM_FAIL?"Slave get SBE Boot Seeprom":
        "unknown");
    }

    auto err = new ERRORLOG::ErrlEntry(l_severity,
                ISTEP::MOD_VALIDATE_SECURITY_SETTINGS,
                i_rc,
                TARGETING::get_huid(i_pProc),
                TO_UINT64(i_mismatches.val),
                true);

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
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK"handleProcessorSecurityError: %s hash: ", hsh.name);
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK"handleProcessorSecurityError: Secure Version = 0x%.2X", *hsh.secure_version);
        TRACFBIN(ISTEPS_TRACE::g_trac_isteps_trace,
                "Data = ",
                reinterpret_cast<void*>(hsh.hash),
                SHA512_DIGEST_LENGTH);
        SECUREBOOT::UdTargetHwKeyHash(
                i_pProc,
                hsh.side,
                hsh.hash,
                *hsh.secure_version).addToLog(err);
    }

    if (i_continue)
    {
         err->addHwCallout(i_pProc,
                HWAS::SRCI_PRIORITY_LOW,
                    (i_mismatches.val && // for any mismatch
                    i_rc != RC_MASTER_PROC_SBE_KEYS_HASH_MISMATCH) ?
                    HWAS::NO_DECONFIG: // don't deconfig the processor
                    HWAS::DELAYED_DECONFIG,
                HWAS::GARD_NULL);
    }

    // save off reason code before committing
    const auto l_reason = err->reasonCode();

    ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

    if (!i_continue)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Terminating because future security cannot be guaranteed.");
        INITSERVICE::doShutdown(l_reason);
    }
}
#endif

//*****************************************************************************
// validateSecuritySettings()
//*****************************************************************************
/*
 * @brief Lock the SUL bit and enforce synchronized processor security states
 */
void validateSecuritySettings()
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ENTER_MRK"validateSecuritySettings");

    errlHndl_t err = nullptr;

    // Before update procedure, trace security settings
    err = SECUREBOOT::traceSecuritySettings();
    if (err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "validateSecuritySettings: Error back from "
                   "SECUREBOOT::traceSecuritySettings: rc=0x%X, plid=0x%X",
                   ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));

        // Commit log, but continue
        ERRORLOG::errlCommit( err, SECURE_COMP_ID );
    }

    // Always lock SBE SEEPROM
    bool l_force = true;

    TARGETING::TargetHandleList l_procList;
    getAllChips(l_procList,TARGETING::TYPE_PROC,true);

    // call p9_update_security_ctrl.C HWP
    do {

    if (!SECUREBOOT::enabled() && !l_force)
    {
        break;
    }

    TARGETING::TargetHandleList l_tpmList;
    getAllChips(l_tpmList,TARGETING::TYPE_TPM,false);

    // loop through the processors
    auto pProcItr = l_procList.begin();
    while (pProcItr != l_procList.end())
    {
        bool l_notInMrw = true;
        TARGETING::Target* l_tpm = nullptr;

        // check if processor has a TPM according to the mrw

        // for each TPM in the list compare i2c master path with
        // the path of the current processor
        for (auto itpm : l_tpmList)
        {
            auto l_physPath = (*pProcItr)->getAttr<TARGETING::ATTR_PHYS_PATH>();

            auto l_tpmInfo = itpm->getAttr<TARGETING::ATTR_TPM_INFO>();

            if (l_tpmInfo.i2cMasterPath == l_physPath)
            {
                l_notInMrw = false;
                l_tpm = itpm;
                break;
            }
        }

        if (l_notInMrw)
        {
            uint8_t l_protectTpm = 1;
            (*pProcItr)->setAttr<
                TARGETING::ATTR_SECUREBOOT_PROTECT_DECONFIGURED_TPM
                                                                >(l_protectTpm);
        }

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapiTarg(*pProcItr);

        FAPI_INVOKE_HWP(err, p9_update_security_ctrl, l_fapiTarg, l_force);

        if (err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK"validateSecuritySettings - "
                "p9_update_security_ctrl failed for processor tgt=0x%X, "
                "TPM tgt=0x%X. Deconfiguring processor because future "
                "security cannot be guaranteed.",
                TARGETING::get_huid(*pProcItr),
                TARGETING::get_huid(l_tpm));

            // save the plid from the error before commiting
            const auto plid = err->plid();

            ERRORLOG::ErrlUserDetailsTarget(*pProcItr).addToLog(err);

            // commit this error log first before creating the new one
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

            /*@
             * @errortype
             * @reasoncode       ISTEP::RC_UPDATE_SECURITY_CTRL_HWP_FAIL
             * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @userdata1        Processor Target
             * @userdata2        TPM Target
             * @devdesc          Failed to set SEEPROM lock and/or TPM deconfig
             *                   protection for this processor, so we cannot
             *                   guarrantee platform secuirty for this processor
             * @custdesc         Platform security problem detected
            */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                ISTEP::MOD_VALIDATE_SECURITY_SETTINGS,
                ISTEP::RC_UPDATE_SECURITY_CTRL_HWP_FAIL,
                TARGETING::get_huid(*pProcItr),
                TARGETING::get_huid(l_tpm),
                true);

            err->addHwCallout(*pProcItr,
                            HWAS::SRCI_PRIORITY_LOW,
                            HWAS::DELAYED_DECONFIG,
                            HWAS::GARD_NULL);

            err->collectTrace(ISTEP_COMP_NAME);

            // pass on the plid from the previous error log to the new one
            err->plid(plid);

            ERRORLOG::ErrlUserDetailsTarget(*pProcItr).addToLog(err);

            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

            // remove the deconfigured processor from the list so that we can
            // reuse this list later to enforce processor security state below
            pProcItr = l_procList.erase(pProcItr);

            // we don't break here. we need to continue on to the next
            // processor and run the HWP on that one
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "p9_update_security_ctrl successful for proc: 0x%X tpm: 0x%X",
                TARGETING::get_huid(*pProcItr),
                TARGETING::get_huid(l_tpm));
            // only move on to the next processor if we didn't erase the
            // current one, since erasing the current one automatically gives us
            // the next one
            ++pProcItr;
        }
    }

    } while(0);
    // end of p9_update_security_ctrl procedure

    #ifdef CONFIG_SECUREBOOT
    // Enforce Synchronized Proc Security State
    do {

    uint64_t l_mainCbs = 0;

    // we need to know if we're in manufacturing mode to do some logic later
    TARGETING::Target* sys = nullptr;
    (void) targetService().getTopLevelTarget(sys);
    assert(sys, "validateSecuritySettings() system target is null");
    const auto mnfg_flags = sys->getAttr<ATTR_MNFG_FLAGS>();
    bool mnfg_mode = false;
    if(mnfg_flags & MNFG_FLAG_SRC_TERM)
    {
        mnfg_mode = true;
    }

    // a list of hashes we will be using to match primary to backups and
    // masters to slaves
    std::vector<HashNode> l_hashes;

    // master processor primary hash and secure version
    SHA512_t l_masterHash = {0};
    uint8_t l_masterSecureVersion[] = {INVALID_SECURE_VERSION};

    // master processor backup hash and secure version
    SHA512_t l_backupHash = {0};
    uint8_t l_backupSecureVersion[] = {INVALID_SECURE_VERSION};

    // slave processor primary hash and secure version
    // (reset each time through the loop)
    SHA512_t l_slaveHashPri = {0};
    uint8_t l_slaveSecureVersionPri[] = {INVALID_SECURE_VERSION};

    // slave processor backup hash and secure version
    // (reset each time through the loop)
    SHA512_t l_slaveHashBac = {0};
    uint8_t l_slaveSecureVersionBac[] = {INVALID_SECURE_VERSION};

    // nodes for the hashes vector only to be added to vector as needed
    auto l_master = HashNode(l_masterHash, "master primary", SBE::SBE_SEEPROM0,
                             l_masterSecureVersion);
    auto l_backup = HashNode(l_backupHash, "master backup", SBE::SBE_SEEPROM1,
                             l_backupSecureVersion);
    auto l_slave = HashNode(l_slaveHashPri, "slave primary", SBE::SBE_SEEPROM0,
                            l_slaveSecureVersionPri);
    auto l_slaveb = HashNode(l_slaveHashBac, "slave backup", SBE::SBE_SEEPROM1,
                             l_slaveSecureVersionBac);

    // obtain the master processor target
    TARGETING::Target* mProc = nullptr;
    err = TARGETING::targetService().queryMasterProcChipTargetHandle(mProc);
    if (err)
    {
        // if this happens we are in big trouble
        const auto rc = err->reasonCode();
        ERRORLOG::errlCommit(err, ISTEP_COMP_ID);
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Terminating because future security cannot be guaranteed.");
        INITSERVICE::doShutdown(rc);
        break;
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
         * @reasoncode       ISTEP::RC_MASTER_PROC_CBS_CONTROL_READ_FAIL
         * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
         * @userdata1        Master Processor Target
         * @devdesc          Unable to read the master processor CBS control
         *                   register
         * @custdesc         Platform security problem detected
         */
        handleProcessorSecurityError(mProc,
                                  ISTEP::RC_MASTER_PROC_CBS_CONTROL_READ_FAIL,
                                  l_hashes,
                                  plid,
                                  false); // stop IPL and deconfig processor
        break;
    }

    SBE::sbeSeepromSide_t bootSide = SBE::SBE_SEEPROM_INVALID;
    err = SBE::getSbeBootSeeprom(mProc, bootSide);
    if (err)
    {
        const auto plid = err->plid();
        ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

        /*@
         * @errortype
         * @reasoncode       ISTEP::RC_MASTER_GET_SBE_BOOT_SEEPROM_FAIL
         * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
         * @userdata1        Master Processor Target
         * @devdesc          Unable to get the master SBE boot seeprom side
         *
         * @custdesc         Platform security problem detected
         */
        handleProcessorSecurityError(mProc,
                              ISTEP::RC_MASTER_GET_SBE_BOOT_SEEPROM_FAIL,
                              l_hashes,
                              plid,
                              false); // stop IPL and deconfig processor
        break;
    }

    bool primaryReadFailAllowed = false;

    // read the primary sbe HW keys' hash and secure version for the master processor
    err = SBE::getSecuritySettingsFromSbeImage(
                                      mProc,
                                      EEPROM::SBE_PRIMARY,
                                      bootSide,
                                      l_masterHash,
                                      *l_masterSecureVersion);
    if (err)
    {
        if (!mnfg_mode && bootSide != SBE::SBE_SEEPROM0)
        {
            primaryReadFailAllowed = true;
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "It's a non-mnfg boot and we failed to read the master primary HW SBE Keys' hash and Secure Version from seeprom 0. Ignoring the error since we didn't boot from that seeprom");
            err->collectTrace(ISTEP_COMP_NAME);
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);
        }
        else
        {
            const auto plid = err->plid();
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

            /*@
             * @errortype
             * @reasoncode      ISTEP::RC_MASTER_PROC_PRIMARY_HASH_READ_FAIL
             * @moduleid        ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
             * @userdata1       Master Processor Target
             * @devdesc         Unable to read the master processor primary hash
             *                  from the SBE
             * @custdesc         Platform security problem detected
             */
            handleProcessorSecurityError(mProc,
                                  ISTEP::RC_MASTER_PROC_PRIMARY_HASH_READ_FAIL,
                                  l_hashes,
                                  plid,
                                  false); // stop IPL and deconfig processor
        }
    }

    bool backupReadFailAllowed = false;

    // read the backup sbe HW keys' hash for the master processor
    err = SBE::getSecuritySettingsFromSbeImage(
                                      mProc,
                                      EEPROM::SBE_BACKUP,
                                      bootSide,
                                      l_backupHash,
                                      *l_backupSecureVersion);

    if (err)
    {
        if (!mnfg_mode && bootSide != SBE::SBE_SEEPROM1)
        {
            backupReadFailAllowed = true;
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "It's a non-mnfg boot and we failed to read the master backup HW SBE Keys' hash and Secure Version from seeprom 1. Ignoring the error since we didn't boot from that seeprom");
            err->collectTrace(ISTEP_COMP_NAME);
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);
        }
        else
        {
            const auto plid = err->plid();
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

            /*@
             * @errortype
             * @reasoncode       ISTEP::RC_MASTER_PROC_BACKUP_HASH_READ_FAIL
             * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
             * @userdata1        Processor Target
             * @devdesc          Unable to read the master processor backup hash
             *                   from the SBE
             * @custdesc         Platform security problem detected
             */
            handleProcessorSecurityError(mProc,
                                  ISTEP::RC_MASTER_PROC_BACKUP_HASH_READ_FAIL,
                                  l_hashes,
                                  plid,
                                  false); // stop IPL and deconfig processor
            break;
        }
    }

    // make sure the master processor primary and backup SBE HW keys' hashes
    // match each other.
    if (primaryReadFailAllowed)
    {
        memcpy(l_masterHash, l_backupHash, SHA512_DIGEST_LENGTH);
        *l_masterSecureVersion = *l_backupSecureVersion;
    }
    else if (backupReadFailAllowed)
    {
        memcpy(l_backupHash, l_masterHash, SHA512_DIGEST_LENGTH);
        *l_backupSecureVersion = *l_masterSecureVersion;
    }
    else if(memcmp(l_masterHash,l_backupHash, SHA512_DIGEST_LENGTH)!=0)
    {
        // add only the hashes relevant to the error to hashes vector
        l_hashes.push_back(l_master);
        l_hashes.push_back(l_backup);

       bool l_continue = !SECUREBOOT::enabled();
        /*@
         * @errortype
         * @reasoncode       ISTEP::RC_MASTER_PROC_SBE_KEYS_HASH_MISMATCH
         * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @userdata1        Master Processor Target
         * @devdesc          The primary SBE HW Keys' hash does not match the
         *                   the backup SBE HW Keys' hash, so we cannot
         *                   guarrantee platform security for the system
         * @custdesc         Platform security problem detected
         */
        handleProcessorSecurityError(mProc,
                                  ISTEP::RC_MASTER_PROC_SBE_KEYS_HASH_MISMATCH,
                                  l_hashes,
                                  0,
                                  l_continue); // stop IPL if secureboot enabled

        break;
    }
    else if (*l_masterSecureVersion != *l_backupSecureVersion)
    {
        // add only the hashes relevant to the error to hashes vector
        l_hashes.push_back(l_master);
        l_hashes.push_back(l_backup);

       bool l_continue = !SECUREBOOT::enabled();
        /*@
         * @errortype
         * @reasoncode       ISTEP::RC_MASTER_PROC_SECURE_VERSION_MISMATCH
         * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @userdata1        Master Processor Target
         * @devdesc          The primary SBE HW Keys' hash does not match
         *                   the backup SBE HW Keys' hash, so we cannot
         *                   guarantee platform security for the system
         * @custdesc         Platform security problem detected
         */
        handleProcessorSecurityError(mProc,
                                  ISTEP::RC_MASTER_PROC_SECURE_VERSION_MISMATCH,
                                  l_hashes,
                                  0,
                                  l_continue); // stop IPL if secureboot enabled

        break;
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
        "Master Primary SBE HW keys' hash and Secure Version successfully match backup.");

    for(auto pProc : l_procList)
    {
        uint64_t l_procCbs = 0;

        if (mProc == pProc)
        {
            // skip the master processor
            continue;
        }

        // start with empty slave hashes each time through the loop
        memset(l_slaveHashPri,0,SHA512_DIGEST_LENGTH);
        memset(l_slaveHashBac,0,SHA512_DIGEST_LENGTH);
        *l_slaveSecureVersionPri = INVALID_SECURE_VERSION;
        *l_slaveSecureVersionBac = INVALID_SECURE_VERSION;

        // read the CBS control register of the current processor
        err = SECUREBOOT::getProcCbsControlRegister(l_procCbs, pProc);
        if (err)
        {
            const auto plid = err->plid();
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

            /*@
             * @errortype
             * @reasoncode       ISTEP::RC_SLAVE_PROC_CBS_CONTROL_READ_FAIL
             * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
             * @userdata1        Slave Processor Target
             * @devdesc          Unable to read the slave processor CBS control
             *                   register
             *
             * @custdesc         Platform security problem detected
             */
            handleProcessorSecurityError(pProc,
                                  ISTEP::RC_SLAVE_PROC_CBS_CONTROL_READ_FAIL,
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
             * @reasoncode       ISTEP::RC_SLAVE_GET_SBE_BOOT_SEEPROM_FAIL
             * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
             * @userdata1        Slave Processor Target
             * @devdesc          Unable to get the slave SBE boot seeprom side
             *
             * @custdesc         Platform security problem detected
             */
            handleProcessorSecurityError(pProc,
                                  ISTEP::RC_SLAVE_GET_SBE_BOOT_SEEPROM_FAIL,
                                  l_hashes,
                                  plid,
                                  true); // deconfigure proc and move on
            continue;
        }

        bool skipPrimaryMatch = false;

        // read the primary sbe HW keys' hash for the current processor
        err = SBE::getSecuritySettingsFromSbeImage(
                                          pProc,
                                          EEPROM::SBE_PRIMARY,
                                          bootSide,
                                          l_slaveHashPri,
                                          *l_slaveSecureVersionPri);

        if (err)
        {

            if (!mnfg_mode && bootSide != SBE::SBE_SEEPROM0)
            {
                skipPrimaryMatch = true;
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "It's a non-mnfg boot and we failed to read the HW SBE Keys' hash and Secure Version from seeprom 0, HUID:0x%.8X. Ignoring the error since we didn't boot from that seeprom", TARGETING::get_huid(pProc));
                err->collectTrace(ISTEP_COMP_NAME);
                ERRORLOG::errlCommit(err, ISTEP_COMP_ID);
            }
            else
            {
                const auto plid = err->plid();
                ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

                /*@
                 * @errortype
                 * @reasoncode       ISTEP::RC_SLAVE_PROC_PRIMARY_HASH_READ_FAIL
                 * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
                 * @userdata1        Slave Processor Target
                 * @devdesc          Unable to read the slave processor primary
                 *                   hash from the SBE
                 * @custdesc         Platform security problem detected
                 */
                handleProcessorSecurityError(pProc,
                                  ISTEP::RC_SLAVE_PROC_PRIMARY_HASH_READ_FAIL,
                                  l_hashes,
                                  plid,
                                  true); // deconfigure proc and move on
                continue;
            }
        }

        bool skipBackupMatch = false;

        // read the backup sbe HW keys' hash for the current processor
        err = SBE::getSecuritySettingsFromSbeImage(
                                          pProc,
                                          EEPROM::SBE_BACKUP,
                                          bootSide,
                                          l_slaveHashBac,
                                          *l_slaveSecureVersionBac);
        if (err)
        {
            if (!mnfg_mode && bootSide != SBE::SBE_SEEPROM1)
            {
                skipBackupMatch = true;
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "It's a non-mnfg boot and we failed to read the HW SBE Keys' hash and Secure Version from seeprom 1, HUID:0x%.8X Ignoring the error since we didn't boot from that seeprom", TARGETING::get_huid(pProc));
                err->collectTrace(ISTEP_COMP_NAME);
                ERRORLOG::errlCommit(err, ISTEP_COMP_ID);
            }
            else
            {
                const auto plid = err->plid();
                ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

                /*@
                 * @errortype
                 * @reasoncode       ISTEP::RC_SLAVE_PROC_BACKUP_HASH_READ_FAIL
                 * @moduleid         ISTEP::MOD_VALIDATE_SECURITY_SETTINGS
                 * @userdata1        Slave Processor Target
                 * @devdesc          Unable to read the slave processor backup
                 *                   hash from the SBE
                 * @custdesc         Platform security problem detected
                 */
                handleProcessorSecurityError(pProc,
                                  ISTEP::RC_SLAVE_PROC_BACKUP_HASH_READ_FAIL,
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
            l_mismatches.primisHKH = memcmp(l_slaveHashPri,
                                            l_masterHash,
                                            SHA512_DIGEST_LENGTH) != 0;
        }

        // backup sbe hash mismatch
        if (!skipBackupMatch)
        {
            l_mismatches.bacmisHKH = memcmp(l_slaveHashBac,
                                            l_masterHash,
                                            SHA512_DIGEST_LENGTH) != 0;
        }

        // primary sbe secure version mismatch
        if (!skipPrimaryMatch)
        {
            l_mismatches.primisSV = (*l_slaveSecureVersionPri != *l_masterSecureVersion);
        }

        // backup sbe secure version mismatch
        if (!skipBackupMatch)
        {
            l_mismatches.bacmisSV = (*l_slaveSecureVersionBac != *l_masterSecureVersion);
        }

        // only provide the relevant hashes for error handling cases
        if(l_mismatches.primisHKH || l_mismatches.bacmisHKH ||
           l_mismatches.primisSV  || l_mismatches.bacmisSV)
        {
            l_hashes.push_back(l_master);
        }
        if(l_mismatches.primisHKH || l_mismatches.primisSV)
        {
            l_hashes.push_back(l_slave);
        }
        if(l_mismatches.bacmisHKH || l_mismatches.bacmisSV)
        {
            l_hashes.push_back(l_slaveb);
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
             * @userdata2[58:58] Primary SBE Secure Version mismatch
             * @userdata2[59:59] Backup SBE Secure Version mismatch
             * @userdata2[60:60] SAB bit mismatch
             * @userdata2[61:61] Jumper (SMD) bit mismatch
             * @userdata2[62:62] Primary SBE hash mismatch
             * @userdata2[63:63] Backup SBE hash mismatch
             * @devdesc          Mismatch processor state was detected for this
             *                   processor, so we cannot guarrantee platform
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

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                EXIT_MRK"validateSecuritySettings");
}

uint8_t getMembufsAttachedBitMask( TARGETING::Target * i_procChipHandle  );
void fenceAttachedMembufs( TARGETING::Target * i_procChipHandle  );

//******************************************************************************
// call_proc_cen_ref_clock_enable
//******************************************************************************
void* call_proc_cen_ref_clk_enable(void *io_pArgs )
{
    errlHndl_t  l_errl = NULL;

    IStepError  l_stepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_cen_ref_clock_enable enter" );

    validateSecuritySettings();

#ifdef CONFIG_SECUREBOOT
    if(SECUREBOOT::enabled())
    {
        SECUREBOOT::CENTAUR_SECURITY::ScomCache& centaurCache =
            SECUREBOOT::CENTAUR_SECURITY::ScomCache::getInstance();
        centaurCache.init();
        centaurCache.enableCache();
    }
#endif

    TARGETING::TargetHandleList functionalProcChipList;

    getAllChips(functionalProcChipList, TYPE_PROC, true);

    // loop thru the list of processors
    for (TARGETING::TargetHandleList::const_iterator
            l_proc_iter = functionalProcChipList.begin();
            l_proc_iter != functionalProcChipList.end();
            ++l_proc_iter)
    {
        //Raise fences on centaurs to prevent FSP from analyzing
        // if HB TIs for recoverable errors
        fenceAttachedMembufs( *l_proc_iter );

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "START: p9_cen_ref_clk_enable started on target HUID %.8X",
                TARGETING::get_huid( *l_proc_iter ) );

        // Cumulus only
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapiProcTarget( *l_proc_iter );

        // Invoke the HWP passing in the proc target
        // Cumulus only
        FAPI_INVOKE_HWP(l_errl,
                        p9_cen_ref_clk_enable,
                        l_fapiProcTarget);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR : proc_cen_ref_clk_enable"
                    "failed, returning errorlog" );

            // capture the target data in the elog
            ErrlUserDetailsTarget( *l_proc_iter ).addToLog( l_errl );

            // Create IStep error log and cross ref error that occurred
            l_stepError.addErrorDetails( l_errl );

            // Commit error log
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS : proc_cen_ref_clk_enable"
                    "completed ok");
        }

#ifdef CONFIG_AXONE
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "START : p9a_ocmb_enable"
                    "starting on 0x%.08X", TARGETING::get_huid( *l_proc_iter ));

        // Invoke the HWP passing in the proc target
        // HWP loops on child OCMB targets
        FAPI_INVOKE_HWP(l_errl,
                        p9a_ocmb_enable,
                        l_fapiProcTarget);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR : p9a_ocmb_enable"
                    "failed, committing errorlog" );

            // capture the target data in the elog
            ErrlUserDetailsTarget( *l_proc_iter ).addToLog( l_errl );

            // Create IStep error log and cross ref error that occurred
            l_stepError.addErrorDetails( l_errl );

            // Commit error log
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS : p9a_ocmb_enable"
                    "completed ok on 0x%.08X", TARGETING::get_huid( *l_proc_iter ));
        }

        TARGETING::TargetHandleList l_functionalOcmbChipList;
        getChildAffinityTargets( l_functionalOcmbChipList,
                                 const_cast<TARGETING::Target*>(*l_proc_iter),
                                 TARGETING::CLASS_CHIP,
                                 TARGETING::TYPE_OCMB_CHIP,
                                 true);

        for (const auto & l_ocmb : l_functionalOcmbChipList)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Start : exp_check_for_ready "
                        "for 0x%.08X", TARGETING::get_huid(l_ocmb));

            fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target(l_ocmb);

            // TODO CQ:SW482291 Remove this retry workaround when ocmb check_for_ready timeout issue is resolved
            for(uint8_t i = 0; i < 10; i++)
            {
                FAPI_INVOKE_HWP(l_errl,
                                exp_check_for_ready,
                                l_fapi_ocmb_target);

                // Preserve the error log if this is the last loop.
                if(l_errl == NULL || i == 9)
                {
                    break;
                }
                else
                {
                    delete l_errl;
                    l_errl = NULL;
                }
            }

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : exp_check_for_ready"
                          "failed for target 0x%.08X , committing errorlog", TARGETING::get_huid(l_ocmb) );

                // capture the target data in the elog
                ErrlUserDetailsTarget( l_ocmb ).addToLog( l_errl );

                // Create IStep error log and cross ref error that occurred
                l_stepError.addErrorDetails( l_errl );

                // Commit error log
                errlCommit( l_errl, HWPF_COMP_ID );
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS : exp_check_for_ready "
                          "completed ok");

                size_t size = 0;

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Read IDEC from OCMB 0x%.8X",
                          TARGETING::get_huid(l_ocmb));

                // This write gets translated into a read of the explorer chip
                // in the device driver. First, a read of the chip's IDEC
                // register occurs then ATTR_EC, ATTR_HDAT_EC, and ATTR_CHIP_ID
                // are set with the values found in that register. So, this
                // deviceWrite functions more as a setter for an OCMB target's
                // attributes.
                // Pass 2 as a va_arg to signal the ocmbIDEC function to execute
                // phase 2 of it's read process.
                const uint64_t Phase2 = 2;
                l_errl = DeviceFW::deviceWrite(l_ocmb,
                                   nullptr,
                                   size,
                                   DEVICE_IDEC_ADDRESS(),
                                   Phase2);
                if (l_errl)
                {
                    // read of ID/EC failed even though we THOUGHT we were
                    // present.
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "OCMB 0x%.8X - read IDEC failed (eid 0x%X) - bad",
                              TARGETING::get_huid(l_ocmb), l_errl->eid());

                    // commit the error but keep going
                    errlCommit(l_errl, HWAS_COMP_ID);
                    // l_errl is now nullptr
                }
            }
        }
#endif

    }   // endfor

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_cen_ref_clock_enable exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

//******************************************************************************
// getMembufsAttachedBitMask - helper function for hwp proc_cen_ref_clk_enable
//******************************************************************************
uint8_t getMembufsAttachedBitMask( TARGETING::Target * i_procTarget  )
{
    const uint8_t DMI_WITH_ATTACHED_CENTAUR_MASK = 0x80;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Finding functional membuf chips downstream from "
            "proc chip with HUID of 0x%08X",
            i_procTarget->getAttr<TARGETING::ATTR_HUID>());

    uint8_t l_attachedMembufs = 0;

    // Get list of functional membuf chips downstream from the given
    // proc chip
    TARGETING::TargetHandleList functionalMembufChipList;

    getChildAffinityTargets( functionalMembufChipList,
                      const_cast<TARGETING::Target*>(i_procTarget ),
                      TARGETING::CLASS_CHIP,
                      TARGETING::TYPE_MEMBUF,
                      true);

    // loop through the functional membufs
    for(TARGETING::TargetHandleList::const_iterator pTargetItr
                            = functionalMembufChipList.begin();
                            pTargetItr != functionalMembufChipList.end();
                            pTargetItr++)
    {
        // Find each functional membuf chip's upstream functional DMI
        // unit, if any, and accumulate it into the attached membuf
        // chips mask
        TARGETING::TargetHandleList functionalDmiUnitList;

        getParentAffinityTargets( functionalDmiUnitList, *pTargetItr,
                                  TARGETING::CLASS_UNIT, TARGETING::TYPE_DMI,
                                  true );

        if(functionalDmiUnitList.empty())
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Functional membuf chip with HUID of 0x%08X "
                    "is not attached to an upstream functional DMI",
                    (*pTargetItr)->getAttr<
                    TARGETING::ATTR_HUID>());
            continue;
        }

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Found functional DMI unit with HUID of 0x%08X "
                "upstream from functional membuf chip with HUID of 0x%08X",
                ((*functionalDmiUnitList.begin())->getAttr<
                 TARGETING::ATTR_CHIP_UNIT>()),
                (*pTargetItr)->getAttr<
                TARGETING::ATTR_HUID>());
        l_attachedMembufs |=
            ((DMI_WITH_ATTACHED_CENTAUR_MASK) >>
             ((*functionalDmiUnitList.begin())->getAttr<
              TARGETING::ATTR_CHIP_UNIT>()));
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Proc chip with HUID of 0x%08X has attached membuf "
            "mask (l_attachedMembufs) of 0x%02X",
            i_procTarget->getAttr<TARGETING::ATTR_HUID>(),
            l_attachedMembufs);

    // return the bitmask
    return l_attachedMembufs;

}

//******************************************************************************
// fenceAttachedMembufs - helper function for hwp proc_cen_ref_clk_enable
//******************************************************************************
void fenceAttachedMembufs( TARGETING::Target * i_procTarget  )
{
     errlHndl_t  l_errl = NULL;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Fencing attached (present) membuf chips downstream from "
            "proc chip with HUID of 0x%08X",
            i_procTarget->getAttr<TARGETING::ATTR_HUID>());


    // Get list of membuf chips downstream from the given proc chip
    TARGETING::TargetHandleList MembufChipList;

    getChildAffinityTargetsByState( MembufChipList,
                      const_cast<TARGETING::Target*>(i_procTarget ),
                      TARGETING::CLASS_CHIP,
                      TARGETING::TYPE_MEMBUF,
                      TARGETING::UTIL_FILTER_PRESENT);

    // loop through the membufs
    for(TARGETING::TargetHandleList::const_iterator pTargetItr
                            = MembufChipList.begin();
                            pTargetItr != MembufChipList.end();
                            pTargetItr++)
    {
        //Get CFAM "1012" -- FSI GP3 and set bits 23-27 (various fence bits)
        //Note 1012 is ecmd addressing, real address is 0x1048 (byte)
        uint64_t l_addr = 0x1048;
        const uint32_t l_fence_bits= 0x000001F0;
        uint32_t l_data = 0;
        size_t l_size = sizeof(uint32_t);
        l_errl = deviceRead(*pTargetItr,
                         &l_data,
                         l_size,
                         DEVICE_FSI_ADDRESS(l_addr));
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
             "Failed getcfam 1012 to HUID 0x%08X, ignoring, skipping",
             (*pTargetItr)->getAttr<TARGETING::ATTR_HUID>());
            delete l_errl;
            l_errl = NULL;
            continue;
        }

        l_data |= l_fence_bits;

        l_errl = deviceWrite(*pTargetItr,
                         &l_data,
                         l_size,
                         DEVICE_FSI_ADDRESS(l_addr));
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Failed putcfam 1012 to HUID 0x%08X, ignoring, skipping",
                      (*pTargetItr)->getAttr<TARGETING::ATTR_HUID>());
            delete l_errl;
            l_errl = NULL;
            continue;
        }
    }

}

}
