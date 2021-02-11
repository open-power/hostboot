/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedboot.C $                    */
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
 * @file trustedboot.C
 *
 * @brief Trusted boot interfaces
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <sys/time.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include <targeting/attrsync.H>
#include <targeting/attrrp.H>
#include <targeting/targplatutil.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <secureboot/service.H>
#include <secureboot/trustedbootif.H>
#include <secureboot/trustedboot_reasoncodes.H>
#include <sys/mmio.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <initservice/initserviceif.H>
#ifdef CONFIG_BMC_IPMI
#include <ipmi/ipmisensor.H>
#endif
#include <devicefw/driverif.H>
#include <spi/tpmddif.H>
#include "trustedboot.H"
#include "trustedTypes.H"
#include "trustedbootCmds.H"
#include "trustedbootUtils.H"
#include "tpmLogMgr.H"
#include "base/trustedbootMsg.H"
#include <secureboot/settings.H>
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <p10_update_security_ctrl.H>
#include <algorithm>
#include <util/misc.H>
#include <hwas/common/hwasCommon.H>
#include <kernel/bltohbdatamgr.H>

namespace TRUSTEDBOOT
{

extern SystemData systemData;

errlHndl_t getTpmLogDevtreeInfo(
    const TpmTarget* const i_pTpm,
          uint64_t &       io_logAddr,
          size_t &         o_allocationSize,
          uint64_t &       o_xscomAddr,
          uint32_t &       o_spiControllerOffset)
{
    assert(i_pTpm != nullptr,"getTpmLogDevtreeInfo: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "getTpmLogDevtreeInfo: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());

    errlHndl_t err = nullptr;
    auto * const pTpmLogMgr = getTpmLogMgr(i_pTpm);
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"getTpmLogDevtreeInfo() tgt=0x%08X Addr:0x%016lX "
               "0x%016lX",
               TARGETING::get_huid(i_pTpm),
               io_logAddr ,reinterpret_cast<uint64_t>(pTpmLogMgr));

    o_allocationSize = 0;

    auto hwasState = i_pTpm->getAttr<TARGETING::ATTR_HWAS_STATE>();

    if (nullptr != pTpmLogMgr &&
        hwasState.present)
    {
        err = TpmLogMgr_getDevtreeInfo(pTpmLogMgr,
                                       io_logAddr,
                                       o_allocationSize,
                                       o_xscomAddr,
                                       o_spiControllerOffset);
    }
    TRACUCOMP( g_trac_trustedboot,
               EXIT_MRK"getTpmLogDevtreeInfo() Addr:0x%016lX",io_logAddr);
    return err;
}

void setTpmDevtreeInfo(
    const TpmTarget* const i_pTpm,
    const uint64_t         i_xscomAddr,
    const uint32_t         i_spiControllerOffset)
{
    assert(i_pTpm != nullptr,"setTpmLogDevtreeInfo: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "setTpmLogDevtreeInfo: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());

    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"setTpmLogDevtreeOffset() tgt=0x%08X "
               "Xscom:0x%016lX Controller:0x%08X",
               TARGETING::get_huid(i_pTpm),
               i_xscomAddr, i_spiControllerOffset);

    auto * const pTpmLogMgr = getTpmLogMgr(i_pTpm);
    if (nullptr != pTpmLogMgr)
    {
        TpmLogMgr_setTpmDevtreeInfo(pTpmLogMgr,
                                    i_xscomAddr, i_spiControllerOffset);
    }
}

void getTpmWithRoleOf(
    TARGETING::TPM_ROLE const i_tpmRole,
    TARGETING::Target*&       o_pTpm)
{
    o_pTpm = nullptr;
    TARGETING::TargetHandleList tpmList;
    getTPMs(tpmList,TPM_FILTER::ALL_IN_BLUEPRINT);

    TARGETING::PredicateAttrVal<TARGETING::ATTR_TPM_ROLE>
        hasMatchingTpmRole(i_tpmRole);
    auto itr = std::find_if(tpmList.begin(),tpmList.end(),
        [&hasMatchingTpmRole](const TARGETING::Target* const i_pTpm)
        {
            return hasMatchingTpmRole(i_pTpm);
        });
    if(itr!=tpmList.end())
    {
        o_pTpm=*itr;
    }
}

void getPrimaryTpm(TARGETING::Target*& o_pPrimaryTpm)
{
    getTpmWithRoleOf(TARGETING::TPM_ROLE_TPM_PRIMARY,
        o_pPrimaryTpm);
}

void getBackupTpm(TARGETING::Target*& o_pBackupTpm)
{
    getTpmWithRoleOf(TARGETING::TPM_ROLE_TPM_BACKUP,
        o_pBackupTpm);
}

bool functionalPrimaryTpmExists()
{
    bool exists = false;
#ifdef CONFIG_TPMDD
    TARGETING::TargetHandleList tpmList;
    getTPMs(tpmList,TPM_FILTER::ALL_IN_BLUEPRINT);

    TARGETING::PredicateHwas present;
    present.present(true);

    TARGETING::PredicateHwas functional;
    functional.functional(true);

    TARGETING::PredicateAttrVal<TARGETING::ATTR_HB_TPM_INIT_ATTEMPTED>
        initialized(true);

    // Only look for primary TPM
    TARGETING::PredicateAttrVal<TARGETING::ATTR_TPM_ROLE>
                    isPrimaryTpm(TARGETING::TPM_ROLE_TPM_PRIMARY);

    auto itr = std::find_if(tpmList.begin(),tpmList.end(),
        [&present,&functional, &initialized, &isPrimaryTpm](
            const TARGETING::Target* const i_pTpm)
        {
            const auto isPresent = present(i_pTpm);
            const auto isFunctional = functional(i_pTpm);
            const auto isInitialized = initialized(i_pTpm);
            const auto isPrimary = isPrimaryTpm(i_pTpm);

            TRACFCOMP(g_trac_trustedboot,INFO_MRK
                "functionalPrimaryTpmExists(): TPM HUID 0x%08X's state = "
                "{present=%d,functional=%d,initialized=%d,primary=%d}",
                TARGETING::get_huid(i_pTpm),
                isPresent,isFunctional,isInitialized,isPrimary);

            return (   isPrimaryTpm(i_pTpm)
                    && (   (present(i_pTpm) && functional(i_pTpm))
                        || !initialized(i_pTpm)));
        });

    exists = (itr!=tpmList.end()) ? true : false;
#endif
    return exists;
}

void* host_update_primary_tpm( void *io_pArgs )
{
    errlHndl_t err = nullptr;
    bool unlock = false;

    TRACFCOMP(g_trac_trustedboot,ENTER_MRK
        "host_update_primary_tpm()");

    // Get all TPMs to setup our array
    TARGETING::TargetHandleList tpmList;
    getTPMs(tpmList,TPM_FILTER::ALL_IN_BLUEPRINT);

    // Currently we only support a MAX of two TPMS per node
    assert(tpmList.size() <= MAX_TPMS_PER_NODE, "Too many TPMs found");

    TRACFCOMP(g_trac_trustedboot,INFO_MRK
        "host_update_primary_tpm: Found %d TPM(s) in blueprint",
        tpmList.size());

    do
    {
        if (tpmList.empty())
        {
            TRACFCOMP(g_trac_trustedboot,INFO_MRK
                "No TPM targets found");
            break;
        }

        TARGETING::TargetService& tS = TARGETING::targetService();

        TARGETING::Target* procTarget = nullptr;
        err = tS.queryMasterProcChipTargetHandle( procTarget );
        if (nullptr != err)
        {
            TRACFCOMP(g_trac_trustedboot,ERR_MRK
                "Failed to find master processor target");
            break;
        }

        for(auto tpm : tpmList)
        {
            mutex_lock(tpm->getHbMutexAttr<TARGETING::ATTR_HB_TPM_MUTEX>());
        }
        unlock = true;

        // Loop through the TPMs and figure out if they are attached
        //  to the master or alternate master processor
        TPMDD::tpm_info_t tpmData;
        for (auto tpm : tpmList)
        {
            memset(&tpmData, 0, sizeof(tpmData));
            errlHndl_t readErr = tpmReadAttributes(tpm,
                                                   tpmData,
                                                   TPM_LOCALITY_0);
            if (nullptr != readErr)
            {
                // We are just looking for configured TPMs here
                //  so we ignore any errors
                delete readErr;
                readErr = nullptr;
            }
            else
            {
                const auto originalTpmRole =
                    tpm->getAttr<TARGETING::ATTR_TPM_ROLE>();

                // If TPM connected to acting master processor, it is
                // primary; otherwise it is backup
                TARGETING::TPM_ROLE tpmRole =
                    (tpmData.spiTarget == procTarget) ?
                          TARGETING::TPM_ROLE_TPM_PRIMARY
                        : TARGETING::TPM_ROLE_TPM_BACKUP;
                tpm->setAttr<TARGETING::ATTR_TPM_ROLE>(tpmRole);

                TRACFCOMP(g_trac_trustedboot,INFO_MRK
                    "TPM HUID 0x%08X's original role: %d, new role: %d",
                    TARGETING::get_huid(tpm),
                    originalTpmRole,tpmRole);
            }
        }

        // Initialize primary TPM
        TARGETING::Target* pPrimaryTpm = nullptr;
        (void)getPrimaryTpm(pPrimaryTpm);
        if(pPrimaryTpm)
        {
            auto hwasState = pPrimaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>();
            TRACFCOMP(g_trac_trustedboot,INFO_MRK
                "Prior to init, TPM HUID 0x%08X has state of {present=%d, "
                "functional=%d}",
                TARGETING::get_huid(pPrimaryTpm),
                hwasState.present,hwasState.functional);

            if(   hwasState.present
               && hwasState.functional)
            {
                // API call will set TPM init attempted appropriately
                tpmInitialize(pPrimaryTpm);
            }
            else
            {
                pPrimaryTpm->setAttr<
                    TARGETING::ATTR_HB_TPM_INIT_ATTEMPTED>(true);
            }

            // Allocate TPM log if it hasn't been already; note that
            // during MPIPL, the targeting init will attempt to re-use old
            // values, but then has logic to set the log manager pointer back to
            // 0.
            auto pTpmLogMgr = getTpmLogMgr(pPrimaryTpm);
            // Need to grab state again, as it could have changed
            hwasState = pPrimaryTpm->getAttr<
                TARGETING::ATTR_HWAS_STATE>();
            TRACFCOMP(g_trac_trustedboot,INFO_MRK
                "Prior to log init, TPM HUID 0x%08X has state of {present=%d, "
                "functional=%d}.  Log pointer is %p",
                TARGETING::get_huid(pPrimaryTpm),
                hwasState.present,hwasState.functional,pTpmLogMgr);

            if(   hwasState.present
               && hwasState.functional
               && nullptr == pTpmLogMgr)
            {
                pTpmLogMgr = new TpmLogMgr;
                setTpmLogMgr(pPrimaryTpm,pTpmLogMgr);
                err = TpmLogMgr_initialize(pTpmLogMgr);
                if (nullptr != err)
                {
                    hwasState = pPrimaryTpm->getAttr<
                        TARGETING::ATTR_HWAS_STATE>();
                    hwasState.functional = false;
                    pPrimaryTpm->setAttr<TARGETING::ATTR_HWAS_STATE>(
                        hwasState);
                    break;
                }
            }
        }
        else
        {
            TRACFCOMP(g_trac_trustedboot,INFO_MRK
                "No primary TPM found");
        }

        bool primaryTpmAvail = (pPrimaryTpm != nullptr);
        if(primaryTpmAvail)
        {
            auto primaryHwasState = pPrimaryTpm->getAttr<
                TARGETING::ATTR_HWAS_STATE>();

            TRACFCOMP(g_trac_trustedboot,INFO_MRK
                "Prior to usability determination, Primary TPM HUID 0x%08X has state "
                "of {present=%d, functional=%d}",
                TARGETING::get_huid(pPrimaryTpm),
                primaryHwasState.present,primaryHwasState.functional);

            if (!primaryHwasState.functional ||
                !primaryHwasState.present)
            {
                primaryTpmAvail = false;
            }
        }

        if(!primaryTpmAvail)
        {
            // Primary TPM not available
            TRACFCOMP( g_trac_trustedboot,INFO_MRK
                       "Primary TPM Existence Fail");
        }

        TARGETING::Target* pBackupTpm = nullptr;
        getBackupTpm(pBackupTpm);
        if(pBackupTpm == nullptr)
        {
            TRACFCOMP( g_trac_trustedboot,INFO_MRK
                       "host_update_primary_tpm() "
                       "Backup TPM unavailable "
                       "since it's not in the system blueprint.");
        }

    } while ( 0 );

    if( unlock )
    {
        for(auto tpm : tpmList)
        {
            mutex_unlock(tpm->getHbMutexAttr<
                TARGETING::ATTR_HB_TPM_MUTEX>());
        }
        unlock = false;
    }

    // Make sure we are in a state
    //  where we have a functional TPM
    TRUSTEDBOOT::tpmVerifyFunctionalPrimaryTpmExists();

    if (nullptr == err)
    {
        // Start the task to start to handle the message queue/extends
        task_create(&TRUSTEDBOOT::tpmDaemon, nullptr);
    }

    TARGETING::Target* pPrimaryTpm = nullptr;
    (void)getPrimaryTpm(pPrimaryTpm);

    if (nullptr == err)
    {
        // Log config entries to TPM - needs to be after mutex_unlock
        if(pPrimaryTpm)
        {
            err = tpmLogConfigEntries(pPrimaryTpm);
        }
    }

    if(pPrimaryTpm)
    {
        TRACUCOMP( g_trac_trustedboot,
                   "host_update_primary_tpm() - "
                   "Primary TPM Present:%d Functional:%d Init Attempted:%d"
                   " Usable:%d",
                   pPrimaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().
                       present,
                   pPrimaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().
                       functional,
                   pPrimaryTpm->getAttr<
                       TARGETING::ATTR_HB_TPM_INIT_ATTEMPTED>(),
                   !(pPrimaryTpm->getAttr<TARGETING::ATTR_TPM_UNUSABLE>()));
    }

    TARGETING::Target* pBackupTpm = nullptr;
    (void)getBackupTpm(pBackupTpm);
    if(pBackupTpm)
    {
        TRACUCOMP( g_trac_trustedboot,
                   "host_update_primary_tpm() - "
                   "Backup TPM Present:%d Functional:%d Init Attempted:%d "
                   "Usable: %d. "
                   "Backup TPM initialization is deferred to istep 10.14.",
                   pBackupTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().
                       present,
                   pBackupTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().
                       functional,
                   pBackupTpm->getAttr<
                       TARGETING::ATTR_HB_TPM_INIT_ATTEMPTED>(),
                   !(pPrimaryTpm->getAttr<TARGETING::ATTR_TPM_UNUSABLE>()));
    }

    TRACFCOMP( g_trac_trustedboot,EXIT_MRK
        "host_update_primary_tpm() - %s",
        ((nullptr == err) ? "No Error" : "With Error") );

    return err;
}

void tpmInitialize(TRUSTEDBOOT::TpmTarget* const i_pTpm)
{
    assert(i_pTpm != nullptr,"tpmInitialize: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "tpmInitialize: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());

    errlHndl_t err = nullptr;

    TRACFCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmInitialize() TPM HUID = 0x%08X",
               TARGETING::get_huid(i_pTpm));

    do
    {
        // TPM Initialization sequence
        i_pTpm->setAttr<TARGETING::ATTR_HB_TPM_INIT_ATTEMPTED>(true);
        auto hwasState = i_pTpm->getAttr<
            TARGETING::ATTR_HWAS_STATE>();
        hwasState.functional = true;
        i_pTpm->setAttr<
            TARGETING::ATTR_HWAS_STATE>(hwasState);

        // TPM_STARTUP
        err = tpmCmdStartup(i_pTpm);
        if (nullptr != err)
        {
            break;
        }

        // TPM_GETCAPABILITY to read FW Version
        err = tpmCmdGetCapFwVersion(i_pTpm);
        if (nullptr != err)
        {
            break;
        }

#ifdef CONFIG_TPM_NVIDX_VALIDATE
        // Find out if in manufacturing mode
        // Only validate during MFG IPL
        if ( TARGETING::areAllSrcsTerminating() &&
             !Util::isSimicsRunning())
        {
            // TPM_GETCAPABILITY to validate NV Indexes
            err = tpmCmdGetCapNvIndexValidate(i_pTpm);
            if (nullptr != err)
            {
                break;
            }
        }
#endif
    } while ( 0 );


    // If the TPM failed we will mark it not functional and commit err
    if (nullptr != err)
    {
        // err will be committed and set to nullptr
        tpmMarkFailed(i_pTpm, err);
    }

    TRACFCOMP( g_trac_trustedboot,
               EXIT_MRK"tpmInitialize()");
}

void tpmReplayLog(TRUSTEDBOOT::TpmTarget* const i_primaryTpm,
                  TRUSTEDBOOT::TpmTarget* const i_backupTpm)
{
    assert(i_primaryTpm != nullptr,
                                 "tpmReplayLog: BUG! i_primaryTpm was nullptr");
    assert(i_backupTpm != nullptr,
                               "tpmReplayLog: BUG! i_backupTpm was nullptr");
    assert(i_primaryTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "tpmReplayLog: BUG! Expected primary target to be of TPM type, but "
           "it was of type 0x%08X",
                                 i_primaryTpm->getAttr<TARGETING::ATTR_TYPE>());
    assert(i_backupTpm->getAttr<TARGETING::ATTR_TYPE>()
                                                         == TARGETING::TYPE_TPM,
           "tpmReplayLog: BUG! Expected secondary target to be of TPM type, but"
           " it was of type 0x%08X",
                               i_backupTpm->getAttr<TARGETING::ATTR_TYPE>());
    TRACUCOMP(g_trac_trustedboot, ENTER_MRK"tpmReplayLog()");

    errlHndl_t err = nullptr;
    bool unMarshalError = false;


    // Create EVENT2 structure to be populated by getNextEvent()
    TCG_PCR_EVENT2 l_eventLog = {0};
    // Move past header event to get a pointer to the first event
    // If there are no events besides the header, l_eventHndl = nullptr
    auto * const pTpmLogMgr = getTpmLogMgr(i_primaryTpm);
    auto * const bTpmLogMgr = getTpmLogMgr(i_backupTpm);
    assert(pTpmLogMgr != nullptr, "tpmReplayLog: BUG! Primary TPM's log manager"
           " is nullptr!");
    assert(bTpmLogMgr != nullptr, "tpmReplayLog: BUG! Backup TPM's log manager"
           " is nullptr!");
    const uint8_t* l_eventHndl = TpmLogMgr_getFirstEvent(pTpmLogMgr);
    while ( l_eventHndl != nullptr )
    {
        // Get next event
        l_eventHndl = TpmLogMgr_getNextEvent(pTpmLogMgr,
                                             l_eventHndl, &l_eventLog,
                                             &unMarshalError);
        if (unMarshalError)
        {
            /*@
             * @errortype
             * @reasoncode     RC_TPM_UNMARSHALING_FAIL
             * @severity       ERRL_SEV_UNRECOVERABLE
             * @moduleid       MOD_TPM_REPLAY_LOG
             * @userdata1      Starting address of event that caused error
             * @userdata2      0
             * @devdesc        Unmarshal error while replaying tpm log.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        MOD_TPM_REPLAY_LOG,
                                        RC_TPM_UNMARSHALING_FAIL,
                                        reinterpret_cast<uint64_t>(l_eventHndl),
                                        0,
                                        true /*Add HB SW Callout*/ );

            err->collectTrace( SECURE_COMP_NAME );
            err->collectTrace(TRBOOT_COMP_NAME);
            tpmMarkFailed(i_primaryTpm, err);
            break;
        }

        err = TpmLogMgr_addEvent(bTpmLogMgr, &l_eventLog);
        if(err)
        {
            tpmMarkFailed(i_backupTpm, err);
            break;
        }

        TRACUBIN(g_trac_trustedboot, "tpmReplayLog: Extending event:",
                 &l_eventLog, sizeof(TCG_PCR_EVENT2));
        for (size_t i = 0; i < l_eventLog.digests.count; i++)
        {
            TPM_Alg_Id l_algId = (TPM_Alg_Id)l_eventLog.digests.digests[i]
                                                                   .algorithmId;
            err = tpmCmdPcrExtend(i_backupTpm,
                                  (TPM_Pcr)l_eventLog.pcrIndex,
                                  l_algId,
                                  reinterpret_cast<uint8_t*>
                                      (&(l_eventLog.digests.digests[i].digest)),
                                  getDigestSize(l_algId));
            if (err)
            {
                tpmMarkFailed(i_backupTpm, err);
                break;
            }
        }
        if (err)
        {
            break;
        }
    }

    TRACUCOMP(g_trac_trustedboot, EXIT_MRK"tpmReplayLog()");
}

errlHndl_t tpmLogConfigEntries(TRUSTEDBOOT::TpmTarget* const i_pTpm)
{
    assert(i_pTpm != nullptr,"tpmLogConfigEntries: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "tpmLogConfigEntries: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());

    TRACUCOMP(g_trac_trustedboot, ENTER_MRK"tpmLogConfigEntries()");

    errlHndl_t l_err = nullptr;

    do
    {
        // Create digest buffer and set to largest config entry size.
        uint8_t l_digest[sizeof(uint64_t)];
        memset(l_digest, 0, sizeof(uint64_t));

        // Security switches
        uint64_t l_securitySwitchValue = 0;
        l_err = SECUREBOOT::getSecuritySwitch(l_securitySwitchValue,
                            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);
        if (l_err)
        {
            TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmLogConfigEntries() - "
                      "Call to SECUREBOOT::getSecuritySwitch Failed: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));
            break;
        }
        TRACFCOMP(g_trac_trustedboot, "security switch value = 0x%016lX",
                                l_securitySwitchValue);
        // Extend to TPM - PCR_1
        memcpy(l_digest, &l_securitySwitchValue, sizeof(l_securitySwitchValue));
        uint8_t l_sswitchesLogMsg[] = "Security Switches";
        l_err = pcrExtend(PCR_1, EV_PLATFORM_CONFIG_FLAGS,
                          l_digest, sizeof(l_securitySwitchValue),
                          l_sswitchesLogMsg, sizeof(l_sswitchesLogMsg));
        if (l_err)
        {
            TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmLogConfigEntries() - "
                      "Call to pcrExtend for Security Switches Failed: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));
            break;
        }
        memset(l_digest, 0, sizeof(uint64_t));

        // Chip type and EC
        // Fill in the actual PVR of chip
        // Layout of the PVR is (32-bit): (see cpuid.C for latest format)
        //     2 nibbles reserved.
        //     2 nibbles chip type.
        //     1 nibble technology.
        //     1 nibble major DD.
        //     1 nibble reserved.
        //     1 nibble minor D
        uint32_t l_pvr = mmio_pvr_read() & 0xFFFFFFFF;
        TRACDCOMP(g_trac_trustedboot, "PVR of chip = 0x%08X", l_pvr);
        // Extend to TPM - PCR_1
        memcpy(l_digest, &l_pvr, sizeof(l_pvr));
        uint8_t l_pvrLogMsg[] = "PVR of Chip";
        l_err = pcrExtend(PCR_1, EV_PLATFORM_CONFIG_FLAGS,
                          l_digest, sizeof(l_pvr), l_pvrLogMsg,
                          sizeof(l_pvrLogMsg));
        if (l_err)
        {
            TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmLogConfigEntries() - "
                      "Call to pcrExtend for PVR of Chip Failed: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));
            break;
        }
        memset(l_digest, 0, sizeof(uint64_t));

        // Figure out which node we are running on
        TARGETING::Target* l_masterProc = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(l_masterProc);

        TARGETING::EntityPath l_entityPath =
                        l_masterProc->getAttr<TARGETING::ATTR_PHYS_PATH>();
        const TARGETING::EntityPath::PathElement l_pathElement =
                        l_entityPath.pathElementOfType(TARGETING::TYPE_NODE);
        uint64_t l_nodeid = l_pathElement.instance;
        // Extend to TPM - PCR_1,4,5,6
        memcpy(l_digest, &l_nodeid, sizeof(l_nodeid));
        const TPM_Pcr l_pcrs[] = {PCR_1,PCR_4,PCR_5};
        for (size_t i = 0; i < (sizeof(l_pcrs)/sizeof(TPM_Pcr)) ; ++i)
        {
            uint8_t l_nodeIdLogMsg[] = "Node id";
            l_err = pcrExtend(l_pcrs[i],
                              (l_pcrs[i] == PCR_1 ?
                               EV_PLATFORM_CONFIG_FLAGS : EV_COMPACT_HASH),
                              l_digest, sizeof(l_nodeid), l_nodeIdLogMsg,
                              sizeof(l_nodeIdLogMsg));
            if (l_err)
            {
                TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmLogConfigEntries() - "
                          "Call to pcrExtend for Node id Failed for "
                          "l_pcrs[i=%d]: %d. "
                          TRACE_ERR_FMT,
                          i, l_pcrs[i],
                          TRACE_ERR_ARGS(l_err));
                break;
            }
        }
        if (l_err)
        {
            break;
        }

        // TPM Required
        memset(l_digest, 0, sizeof(uint64_t));
        bool l_tpmRequired = isTpmRequired();
        l_digest[0] = static_cast<uint8_t>(l_tpmRequired);
        uint8_t l_tpmRequiredLogMsg[] = "Tpm Required";
        l_err = pcrExtend(PCR_1, EV_PLATFORM_CONFIG_FLAGS,
                          l_digest, sizeof(l_tpmRequired),
                          l_tpmRequiredLogMsg,
                          sizeof(l_tpmRequiredLogMsg));
        if (l_err)
        {
            TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmLogConfigEntries() - "
                      "Call to pcrExtend for TPM Required Failed: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));
            break;
        }

        // HW Key Hash
        SHA512_t l_hw_key_hash;
        SECUREBOOT::getHwKeyHash(l_hw_key_hash);
        uint8_t l_hwKeyHashLogMsg[] = "HW KEY HASH";
        const TPM_Pcr l_pcrs2[] = {PCR_1,PCR_6};
        for (size_t i = 0; i < (sizeof(l_pcrs2)/sizeof(TPM_Pcr)) ; ++i)
        {
            l_err = pcrExtend(l_pcrs2[i],
                              EV_PLATFORM_CONFIG_FLAGS,
                              l_hw_key_hash,
                              sizeof(SHA512_t),
                              l_hwKeyHashLogMsg,
                              sizeof(l_hwKeyHashLogMsg));
            if (l_err)
            {
                TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmLogConfigEntries() - "
                          "Call to pcrExtend for HW Key Hash "
                          "l_pcrs2[i=%d]: %d. "
                          TRACE_ERR_FMT,
                          i, l_pcrs2[i],
                          TRACE_ERR_ARGS(l_err));
                break;
            }
        }
        if (l_err)
        {
            break;
        }

        // Put Security jumper state boolean into PCR_6
        bool l_jumper_state = (l_securitySwitchValue &
                               static_cast<uint64_t>(
                                 SECUREBOOT::ProcCbsControl::JumperStateBit));

        memset(l_digest, 0, sizeof(uint64_t));
        l_digest[0] = static_cast<uint8_t>(l_jumper_state);
        uint8_t l_jumperStateLogMsg[] = "Security Jumper State";
        l_err = pcrExtend(PCR_6, EV_PLATFORM_CONFIG_FLAGS,
                          l_digest, sizeof(l_jumper_state),
                          l_jumperStateLogMsg,
                          sizeof(l_jumperStateLogMsg));
        if (l_err)
        {
            TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmLogConfigEntries() - "
                      "Call to pcrExtend for Jumper State Bit Failed: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));
            break;
        }

        // Put truncated SHA512 hash of SBE secureboot validation code
        // (aka SecureROM) into PCR_6
        if (g_BlToHbDataManager.isValid())
        {
            // Get location and size of SecureROM and then hash it
            const void * l_secureRomLocation = g_BlToHbDataManager.getSecureRom();
            size_t l_secureRomSize = g_BlToHbDataManager.getSecureRomSize();

            SHA512_t l_secure_rom_hash={0};
            SECUREBOOT::hashBlob(l_secureRomLocation, l_secureRomSize, l_secure_rom_hash);

            // Extend hash to PCR_6
            uint8_t l_secureRomLogMsg[] = "SecureROM HASH";
            l_err = pcrExtend(PCR_6,
                              EV_PLATFORM_CONFIG_FLAGS,
                              l_secure_rom_hash,
                              sizeof(SHA512_t),
                              l_secureRomLogMsg,
                              sizeof(l_secureRomLogMsg));
            if (l_err)
            {
                TRACFCOMP(g_trac_trustedboot, ERR_MRK"tpmLogConfigEntries() - "
                          "Call to pcrExtend for SecureROM Hash Failed: "
                          TRACE_ERR_FMT,
                          TRACE_ERR_ARGS(l_err));
                break;
            }
        }

    } while(0);

    TRACUCOMP(g_trac_trustedboot, EXIT_MRK"tpmLogConfigEntries()");

    return l_err;
}

void pcrExtendSingleTpm(TpmTarget* const i_pTpm,
                        const TPM_Pcr i_pcr,
                        const EventTypes i_eventType,
                        TPM_Alg_Id i_algId,
                        const uint8_t* i_digest,
                        size_t  i_digestSize,
                        const uint8_t* i_logMsg,
                        const size_t i_logMsgSize)
{
    assert(i_pTpm != nullptr,"pcrExtendSingleTpm: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "pcrExtendSingleTpm: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());

    errlHndl_t err = nullptr;
    TCG_PCR_EVENT2 eventLog;
    bool unlock = false;

    TPM_Pcr pcr = i_pcr;
    bool useStaticLog = true;

    memset(&eventLog, 0, sizeof(eventLog));
    do
    {
        mutex_lock( i_pTpm->getHbMutexAttr<TARGETING::ATTR_HB_TPM_MUTEX>() ) ;
        unlock = true;

        auto hwasState = i_pTpm->getAttr<TARGETING::ATTR_HWAS_STATE>();

        // Log the event
        if (hwasState.present &&
             hwasState.functional)
        {
            if (i_logMsg != nullptr) // null log indicates we don't log
            {
                // Fill in TCG_PCR_EVENT2 and add to log
                eventLog = TpmLogMgr_genLogEventPcrExtend(pcr, i_eventType,
                                                          i_algId, i_digest,
                                                          i_digestSize,
                                                          TPM_ALG_SHA1,
                                                          i_digest,
                                                          i_digestSize,
                                                          i_logMsg,
                                                          i_logMsgSize);
                if(useStaticLog)
                {
                    auto * const pTpmLogMgr = getTpmLogMgr(i_pTpm);
                    err = TpmLogMgr_addEvent(pTpmLogMgr,&eventLog);
                    if (nullptr != err)
                    {
                        break;
                    }
                }
            }

            // Perform the requested extension and also force into the
            // SHA1 bank
            err = tpmCmdPcrExtend2Hash(i_pTpm,
                                       pcr,
                                       i_algId,
                                       i_digest,
                                       i_digestSize,
                                       TPM_ALG_SHA1,
                                       i_digest,
                                       i_digestSize);
        }
    } while ( 0 );

    if (nullptr != err)
    {
        // We failed to extend to this TPM we can no longer use it
        // Mark TPM as not functional, commit err and set it to nullptr
        tpmMarkFailed(i_pTpm, err);
    }

    if (unlock)
    {
        mutex_unlock( i_pTpm->getHbMutexAttr<TARGETING::ATTR_HB_TPM_MUTEX>() ) ;
    }
    return;
}

void pcrExtendSeparator(TpmTarget* const i_pTpm)
{
    assert(i_pTpm != nullptr,"pcrExtendSeparator: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "pcrExtendSeparator: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());

    TRACUCOMP(g_trac_trustedboot, ENTER_MRK"pcrExtendSeparator()");

    errlHndl_t err = nullptr;
    TCG_PCR_EVENT2 eventLog = {0};
    bool unlock = false;

    // Separators are always the same values
    // The digest is a sha1 hash of 0xFFFFFFFF
    const uint8_t sha1_digest[] = {
        0xd9, 0xbe, 0x65, 0x24, 0xa5, 0xf5, 0x04, 0x7d,
        0xb5, 0x86, 0x68, 0x13, 0xac, 0xf3, 0x27, 0x78,
        0x92, 0xa7, 0xa3, 0x0a};
    // The digest is a sha256 hash of 0xFFFFFFFF
    const uint8_t sha256_digest[] = {
        0xAD, 0x95, 0x13, 0x1B, 0xC0, 0xB7, 0x99, 0xC0,
        0xB1, 0xAF, 0x47, 0x7F, 0xB1, 0x4F, 0xCF, 0x26,
        0xA6, 0xA9, 0xF7, 0x60, 0x79, 0xE4, 0x8B, 0xF0,
        0x90, 0xAC, 0xB7, 0xE8, 0x36, 0x7B, 0xFD, 0x0E};
    // The event message is 0xFFFFFFFF
    const uint8_t logMsg[] = { 0xFF, 0xFF, 0xFF, 0xFF };

    memset(&eventLog, 0, sizeof(eventLog));
    do
    {
        mutex_lock( i_pTpm->getHbMutexAttr<TARGETING::ATTR_HB_TPM_MUTEX>() ) ;
        unlock = true;

        std::vector<TPM_Pcr> pcrs =
            {PCR_0,PCR_1,PCR_2,PCR_3,PCR_4,PCR_5,PCR_6,PCR_7};
        bool useStaticLog = true;

        for (const auto &pcr : pcrs)
        {
            auto hwasState = i_pTpm->getAttr<
                TARGETING::ATTR_HWAS_STATE>();

            // Log the separator
            if (hwasState.present &&
                hwasState.functional)
            {
                // Fill in TCG_PCR_EVENT2 and add to log
                eventLog = TpmLogMgr_genLogEventPcrExtend(pcr,
                                                          EV_SEPARATOR,
                                                          TPM_ALG_SHA1,
                                                          sha1_digest,
                                                          sizeof(sha1_digest),
                                                          TPM_ALG_SHA256,
                                                          sha256_digest,
                                                          sizeof(sha256_digest),
                                                          logMsg,
                                                          sizeof(logMsg));

                if(useStaticLog)
                {
                    auto * const pTpmLogMgr = getTpmLogMgr(i_pTpm);
                    err = TpmLogMgr_addEvent(pTpmLogMgr,&eventLog);
                    if (nullptr != err)
                    {
                        break;
                    }
                }

                // Perform the requested extension
                err = tpmCmdPcrExtend2Hash(i_pTpm,
                                           pcr,
                                           TPM_ALG_SHA1,
                                           sha1_digest,
                                           sizeof(sha1_digest),
                                           TPM_ALG_SHA256,
                                           sha256_digest,
                                           sizeof(sha256_digest));
                if (nullptr != err)
                {
                    break;
                }

            }
        }

    } while ( 0 );

    if (nullptr != err)
    {
        // We failed to extend to this TPM we can no longer use it
        // Mark TPM as not functional, commit err and set it to nullptr
        tpmMarkFailed(i_pTpm, err);

        // Log this failure
        errlCommit(err, TRBOOT_COMP_ID);
    }

    if (unlock)
    {
        mutex_unlock( i_pTpm->getHbMutexAttr<TARGETING::ATTR_HB_TPM_MUTEX>() ) ;
    }

    TRACUCOMP(g_trac_trustedboot, EXIT_MRK"pcrExtendSeparator()");

    return;
}

void forceTpmDeconfigCallout(TpmTarget* const i_pTpm,
                             errlHndl_t& i_err)
{
    const auto search_results = i_err->queryCallouts(i_pTpm);
    using compare_enum = ERRORLOG::ErrlEntry::callout_search_criteria;
    // Check if we found any callouts for this TPM
    if((search_results & compare_enum::TARGET_MATCH) == compare_enum::TARGET_MATCH)
    {
        // If we found a callout for this TPM w/o a DECONFIG,
        // edit the callout to include a deconfig
        if((search_results & compare_enum::DECONFIG_FOUND) != compare_enum::DECONFIG_FOUND)
        {
            i_err->setDeconfigState(i_pTpm, HWAS::DELAYED_DECONFIG);
        }
    }
    else
    {
        // Add HW callout for TPM with low priority
        i_err->addHwCallout(i_pTpm,
                            HWAS::SRCI_PRIORITY_LOW,
                            HWAS::DELAYED_DECONFIG,
                            HWAS::GARD_NULL);
    }
}

void tpmMarkFailed(TpmTarget* const i_pTpm,
                   errlHndl_t& io_err)
{
    assert(i_pTpm != nullptr,"tpmMarkFailed: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "tpmMarkFailed: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());

    TRACFCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmMarkFailed() Marking TPM as failed : "
               "tgt=0x%08X; io_err rc=0x%04X, plid=0x%08X",
               TARGETING::get_huid(i_pTpm), ERRL_GETRC_SAFE(io_err),
               ERRL_GETPLID_SAFE(io_err));

    #ifdef CONFIG_SECUREBOOT
    TARGETING::Target* l_tpm = i_pTpm;

    errlHndl_t l_err = nullptr;
    TARGETING::Target* l_proc = nullptr;

    do {

    if (!SECUREBOOT::enabled())
    {
        break;
    }

    // for the given tpm target, find the processor target
    TARGETING::TargetHandleList l_procList;
    getAllChips(l_procList,TARGETING::TYPE_PROC,false);

    auto l_tpmInfo = l_tpm->getAttr<TARGETING::ATTR_SPI_TPM_INFO>();

    for(auto it : l_procList)
    {
        auto l_physPath = it->getAttr<TARGETING::ATTR_PHYS_PATH>();
        if (l_tpmInfo.spiMasterPath == l_physPath)
        {
            // found processor acting as SPI master for this TPM
            l_proc = it;
            break;
        }
    }
    if (l_proc == nullptr)
    {
        assert(false,"tpmMarkFailed - TPM with non-existent processor indicates"
            " a bad MRW. TPM tgt=0x%08X", TARGETING::get_huid(l_tpm));
    }

    // set ATTR_SECUREBOOT_PROTECT_DECONFIGURED_TPM for the processor
    uint8_t l_protectTpm = 1;
    l_proc->setAttr<TARGETING::ATTR_SECUREBOOT_PROTECT_DECONFIGURED_TPM>(
        l_protectTpm);

    // There is no way to fence off a TPM when its SPI master
    // processor is not functional. If the SPI master is not scommable
    // the scom accesses below will fail so we must defer them to when the
    // processor is up.
    TARGETING::PredicateHwas isNonFunctional;
    isNonFunctional.functional(false);
    if (isNonFunctional(l_proc) || !l_proc->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom)
    {
        // Note: at this point l_err is nullptr so
        // no error log is created on break
        break;
    }

    uint64_t l_regValue = 0;
    l_err = SECUREBOOT::getSecuritySwitch(l_regValue, l_proc);
    if (l_err)
    {
        TRACFCOMP(g_trac_trustedboot,
            ERR_MRK"tpmMarkFailed - call to getSecuritySwitch failed");
        break;
    }
    // if the SBE lock bit is not set, it means that istep 10.3 hasn't executed
    // yet, so we will let istep 10.3 call p10_update_security_control HWP
    // if the SBE lock bit is set, then we will call the HWP here
    if (!(l_regValue & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::SULBit)))
    {
        break;
    }

    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapiTarg(l_proc);

    FAPI_INVOKE_HWP(l_err, p10_update_security_ctrl, l_fapiTarg);

    if (l_err)
    {
        TRACFCOMP(g_trac_trustedboot,
            ERR_MRK"tpmMarkFailed - call to p10_update_security_ctrl failed ");
    }

    } while(0);

    // If we got a local error log, link it to input error log and then
    // commit it
    if (l_err)
    {
        // commit this error log first before creating the new one
        auto plid = l_err->plid();

        // If we have an input error log then link these all together
        if (io_err)
        {
           TRACFCOMP(g_trac_trustedboot,
                ERR_MRK "tpmMarkFailed(): Processor tgt=0x%08X TPM tgt=0x%08X. "
                "Deconfiguring proc because future security cannot be "
                "guaranteed. Linking new l_err rc=0x%04X eid=0x%08X to "
                "io_err rc=0x%04X, plid=0x%08X",
                TARGETING::get_huid(l_proc),
                TARGETING::get_huid(l_tpm),
                l_err->reasonCode(), l_err->eid(),
                io_err->reasonCode(), io_err->plid());

            // Use io_err's plid to link all errors together
            plid = io_err->plid();
            l_err->plid(plid);
        }
        else
        {
            TRACFCOMP(g_trac_trustedboot,
                ERR_MRK "tpmMarkFailed(): Processor tgt=0x%08X TPM tgt=0x%08X: "
                "Deconfiguring proc because future security cannot be "
                "guaranteed due to new l_err rc=0x%04X plid=0x%08X",
                TARGETING::get_huid(l_proc),
                TARGETING::get_huid(l_tpm),
                l_err->reasonCode(), l_err->plid());
        }

        ERRORLOG::ErrlUserDetailsTarget(l_proc).addToLog(l_err);
        l_err->collectTrace(SECURE_COMP_NAME);
        l_err->collectTrace(TRBOOT_COMP_NAME);

        // commit this error log first before creating the new one
        errlCommit(l_err, TRBOOT_COMP_ID);

       /*@
        * @errortype
        * @reasoncode       TRUSTEDBOOT::RC_UPDATE_SECURITY_CTRL_HWP_FAIL
        * @moduleid         TRUSTEDBOOT::MOD_TPM_MARK_FAILED
        * @severity         ERRL_SEV_UNRECOVERABLE
        * @userdata1        Processor Target
        * @userdata2        TPM Target
        * @devdesc          Failed to set SEEPROM lock and/or TPM deconfig
        *                   protection for this processor, so we cannot
        *                   guarrantee platform secuirty for this processor
        * @custdesc         Platform security problem detected
        */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            TRUSTEDBOOT::MOD_TPM_MARK_FAILED,
            TRUSTEDBOOT::RC_UPDATE_SECURITY_CTRL_HWP_FAIL,
            TARGETING::get_huid(l_proc),
            TARGETING::get_huid(l_tpm));

        // Pass on the plid to connect all previous error(s)
        l_err->plid(plid);

       TRACFCOMP(g_trac_trustedboot,
            ERR_MRK "tpmMarkFailed(): Processor tgt=0x%08X TPM tgt=0x%08X. "
            "Deconfiguring proc errorlog is rc=0x%04X plid=0x%08X, eid=0x%08X",
            TARGETING::get_huid(l_proc),
            TARGETING::get_huid(l_tpm),
            l_err->reasonCode(), l_err->plid(), l_err->eid());

        l_err->addHwCallout(l_proc,
                            HWAS::SRCI_PRIORITY_LOW,
                            HWAS::DELAYED_DECONFIG,
                            HWAS::GARD_NULL);

        l_err->collectTrace(SECURE_COMP_NAME);
        l_err->collectTrace(TRBOOT_COMP_NAME);

        ERRORLOG::ErrlUserDetailsTarget(l_proc).addToLog(l_err);

        ERRORLOG::errlCommit(l_err, TRBOOT_COMP_ID);
    }
    #endif

    // Commit input error log
    if (io_err)
    {
       TRACFCOMP(g_trac_trustedboot,
            ERR_MRK "Committing io_err rc=0x%04X plid=0x%08X, eid=0x%08X",
            io_err->reasonCode(), io_err->plid(), io_err->eid());
        // ensure there is, at minimum, a low priority hw callout for the TPM
        // that has a deconfigure action associated with it.
        forceTpmDeconfigCallout(i_pTpm,io_err);

        io_err->collectTrace(SECURE_COMP_NAME);
        io_err->collectTrace(TRBOOT_COMP_NAME);

        ERRORLOG::errlCommit(io_err, TRBOOT_COMP_ID);
    }

}

void tpmVerifyFunctionalPrimaryTpmExists(
    const NoTpmShutdownPolicy i_noTpmShutdownPolicy)
{
    errlHndl_t err = nullptr;
    bool foundFunctional = functionalPrimaryTpmExists();
    const bool isBackgroundShutdown =
        (i_noTpmShutdownPolicy == NoTpmShutdownPolicy::BACKGROUND_SHUTDOWN);

    if (!foundFunctional && !systemData.failedTpmsPosted)
    {
        systemData.failedTpmsPosted = true;
        TRACFCOMP( g_trac_trustedboot,
                   "NO FUNCTIONAL PRIMARY TPM FOUND ON THE NODE");

        // Check to ensure jumper indicates we are running secure
        SECUREBOOT::SecureJumperState l_state
                          = SECUREBOOT::SecureJumperState::SECURITY_DEASSERTED;
        err = SECUREBOOT::getJumperState(l_state);
        if (err)
        {
            auto errEid = err->eid();
            errlCommit(err, TRBOOT_COMP_ID);

            // we should not continue if we could not read the jumper state
            INITSERVICE::doShutdown(errEid,isBackgroundShutdown);
        }
        else if (l_state == SECUREBOOT::SecureJumperState::SECURITY_ASSERTED)
        {
            if (isTpmRequired())
            {
                /*@
                 * @errortype
                 * @reasoncode     RC_TPM_NOFUNCTIONALTPM_FAIL
                 * @severity       ERRL_SEV_UNRECOVERABLE
                 * @moduleid       MOD_TPM_VERIFYFUNCTIONAL
                 * @userdata1      0
                 * @userdata2      0
                 * @devdesc        The system (or node, if multi-node system)
                 *                 is configured in the hardware (via processor
                 *                 secure jumpers) to enable Secure Boot, and
                 *                 the system's/node's "TPM required" policy is
                 *                 configured to require at least one
                 *                 functional boot processor TPM in order to
                 *                 boot with Trusted Boot enabled. Therefore,
                 *                 the system (or node, if multi-node system)
                 *                 will terminate due to lack of functional
                 *                 boot processor TPM.
                 * @custdesc       The system is configured for Secure Boot and
                 *                 trusted platform module required mode; a
                 *                 functional boot processor trusted platform
                 *                 module is required to boot the system (or
                 *                 node, if multi-node system), but none are
                 *                 available.  Therefore, the system (or node,
                 *                 if multi-node system) will terminate.
                 *                 Trusted platform module required mode may be
                 *                 disabled via the appropriate systems
                 *                 management interface to allow platform boot
                 *                 without the remote trusted attestation
                 *                 capability. Look for other errors which call
                 *                 out the trusted platform module and follow
                 *                 the repair actions for these errors.
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              MOD_TPM_VERIFYFUNCTIONAL,
                                              RC_TPM_NOFUNCTIONALTPM_FAIL);

                TRACFCOMP(g_trac_trustedboot, ERR_MRK
                          "tpmVerifyFunctionalPrimaryTpmExists: Shutting down "
                          "system because no Functional Primary TPM was found "
                          "but system policy required it. errl EID 0x%08X",
                          err->eid());

                // Add low priority HB SW callout
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_LOW);
                err->collectTrace(TRBOOT_COMP_NAME);
                err->collectTrace(TPMDD_COMP_NAME );
                err->collectTrace(SPI_COMP_NAME );
                err->collectTrace(SECURE_COMP_NAME );
                const auto reasonCode = err->reasonCode();

                // Add Security Registers to the error log
                SECUREBOOT::addSecurityRegistersToErrlog(err);

                // HW callout TPM
                TARGETING::Target* l_primaryTpm = nullptr;
                getPrimaryTpm(l_primaryTpm);
                if(l_primaryTpm)
                {
                    err->addHwCallout(l_primaryTpm,
                                      HWAS::SRCI_PRIORITY_HIGH,
                                      HWAS::NO_DECONFIG,
                                      HWAS::GARD_NULL);
                }
                errlCommit(err, TRBOOT_COMP_ID);

                // Sync the attributes to FSP or BMC if applicable.
                // This will allow for FSP to attempt to perform
                // TPM alignment check.
                err = TARGETING::AttrRP::syncAllAttributesToSP();
                if(err)
                {
                    TRACFCOMP(g_trac_trustedboot, ERR_MRK
                              "tpmVerifyFunctionalPrimaryTpmExists: Could "
                              "not sync attributes to FSP/BMC; errl EID 0x%08X",
                              err->eid());
                    errlCommit(err, TRBOOT_COMP_ID);
                }

                // terminating the IPL with this fail
                // Terminate IPL immediately
                INITSERVICE::doShutdown(reasonCode,isBackgroundShutdown);
            }
            else
            {
                TRACUCOMP(g_trac_trustedboot,
                          "tpmVerifyFunctionalPrimaryTpmExists: No functional "
                          "primary TPM found but TPM not Required");
            }
        }
        else
        {
            TRACUCOMP(g_trac_trustedboot,"tpmVerifyFunctionalPrimaryTpmExists: "
                      "No functional primary TPM found but not running secure");
        }

    }

    return;
}

void doInitBackupTpm()
{
    TARGETING::Target* l_backupTpm = nullptr;
    errlHndl_t l_errl = nullptr;
    TRUSTEDBOOT::getBackupTpm(l_backupTpm);

    do {
    if(l_backupTpm)
    {
        auto l_backupHwasState = l_backupTpm->getAttr<
                                                  TARGETING::ATTR_HWAS_STATE>();
        // Presence-detect the secondary TPM
        TARGETING::TargetHandleList l_targetList;

        TARGETING::Target* pSysTarget = nullptr;
        TARGETING::targetService().getTopLevelTarget(pSysTarget);
        assert(pSysTarget, "doInitBackupTpm(): System target was nullptr");
        const auto mpipl = pSysTarget->getAttr<
                               TARGETING::ATTR_IS_MPIPL_HB>();
        if(mpipl)
        {
            // If previously determined not to be available, nothing to do
            if(   (!l_backupHwasState.present)
               || (!l_backupHwasState.functional) )
            {
                break;
            }
        }
        else
        {
            l_targetList.push_back(l_backupTpm);
            l_errl = HWAS::platPresenceDetect(l_targetList);
            if(l_errl)
            {
                errlCommit(l_errl, SECURE_COMP_ID);
                break;
            }

            // The TPM target would have been deleted from the list if it's
            // not present.
            if(l_targetList.size())
            {
                l_backupHwasState.present = true;
                l_backupTpm->setAttr<TARGETING::ATTR_HWAS_STATE>(
                    l_backupHwasState);
            }
            else
            {
                l_backupHwasState.present = false;
                l_backupTpm->setAttr<TARGETING::ATTR_HWAS_STATE>(
                    l_backupHwasState);
                break;
            }
        }

        mutex_lock(l_backupTpm->getHbMutexAttr<TARGETING::ATTR_HB_TPM_MUTEX>());
        tpmInitialize(l_backupTpm);
        TpmLogMgr* l_tpmLogMgr = getTpmLogMgr(l_backupTpm);
        if(!l_tpmLogMgr)
        {
            l_tpmLogMgr = new TpmLogMgr;
            setTpmLogMgr(l_backupTpm, l_tpmLogMgr);
            l_errl = TpmLogMgr_initialize(l_tpmLogMgr);
            if(l_errl)
            {
                l_backupHwasState.functional = false;
                l_backupTpm->setAttr<TARGETING::ATTR_HWAS_STATE>
                                                            (l_backupHwasState);
                errlCommit(l_errl, SECURE_COMP_ID);
                mutex_unlock(l_backupTpm->
                                getHbMutexAttr<TARGETING::ATTR_HB_TPM_MUTEX>());
                break;
            }
        }
        mutex_unlock(l_backupTpm->
                                getHbMutexAttr<TARGETING::ATTR_HB_TPM_MUTEX>());

        TARGETING::Target* l_primaryTpm = nullptr;
        getPrimaryTpm(l_primaryTpm);
        if(l_primaryTpm)
        {
            auto l_primaryHwasState = l_primaryTpm->getAttr<
                                                  TARGETING::ATTR_HWAS_STATE>();
            if(l_primaryHwasState.functional && l_primaryHwasState.present)
            {
                tpmReplayLog(l_primaryTpm, l_backupTpm);
            }
        }

        l_errl = TRUSTEDBOOT::testCmpPrimaryAndBackupTpm();
        if(l_errl)
        {
            errlCommit(l_errl, SECURE_COMP_ID);
            break;
        }
    }
    else
    {
        TRACFCOMP(g_trac_trustedboot, "tpmDaemon: Backup TPM init message was"
                  " received but the backup TPM cannot be found.");
    }

    } while(0);

    // Always mark that the init was attempted even if it didn't succeed
    if(l_backupTpm)
    {
        l_backupTpm->setAttr<TARGETING::ATTR_HB_TPM_INIT_ATTEMPTED>(true);
    }
}

errlHndl_t doCreateAttKeys(TpmTarget* i_tpm)
{
    errlHndl_t l_errl = nullptr;

    do {
    l_errl = validateTpmHandle(i_tpm);
    if(l_errl)
    {
        break;
    }

    l_errl = tpmCmdCreateAttestationKeys(i_tpm);
    if(l_errl)
    {
        break;
    }

    } while(0);

    return l_errl;
}

errlHndl_t doReadAKCert(TpmTarget* i_tpm, TPM2B_MAX_NV_BUFFER* o_data)
{
    errlHndl_t l_errl = nullptr;

    do {
    l_errl = validateTpmHandle(i_tpm);
    if(l_errl)
    {
        break;
    }

    l_errl = tpmCmdReadAKCertificate(i_tpm, o_data);
    if(l_errl)
    {
        break;
    }
    } while(0);

    return l_errl;
}

errlHndl_t doGenQuote(TpmTarget* i_tpm,
                      const MasterTpmNonce_t* const i_masterNonce,
                      QuoteDataOut* o_data)
{
    errlHndl_t l_errl = nullptr;

    do {
    l_errl = validateTpmHandle(i_tpm);
    if(l_errl)
    {
        break;
    }

    l_errl = tpmCmdGenerateQuote(i_tpm, i_masterNonce, o_data);
    if(l_errl)
    {
        break;
    }
    } while(0);

    return l_errl;
}

errlHndl_t doFlushContext(TpmTarget* i_tpm)
{
    errlHndl_t l_errl = nullptr;

    do {
    l_errl = validateTpmHandle(i_tpm);
    if(l_errl)
    {
        break;
    }

    l_errl = tpmCmdFlushContext(i_tpm);
    if(l_errl)
    {
        break;
    }
    } while(0);

    return l_errl;
}

errlHndl_t doPcrRead(TpmTarget* i_target,
                     const TPM_Pcr i_pcr,
                     const TPM_Alg_Id i_algId,
                     const size_t i_digestSize,
                     uint8_t* const o_digest)
{
    errlHndl_t l_errl = nullptr;

    do {
    l_errl = validateTpmHandle(i_target);
    if(l_errl)
    {
        break;
    }

    l_errl = tpmCmdPcrRead(i_target,
                           i_pcr,
                           i_algId,
                           o_digest,
                           i_digestSize);
    if(l_errl)
    {
        break;
    }

    } while(0);
    return l_errl;
}

errlHndl_t doExpandTpmLog(TpmTarget* i_target)
{
    errlHndl_t l_errl = nullptr;

    do {
    l_errl = validateTpmHandle(i_target);
    if(l_errl)
    {
        break;
    }

    l_errl = tpmCmdExpandTpmLog(i_target);
    if(l_errl)
    {
        break;
    }
    } while(0);
    return l_errl;
}

void* tpmDaemon(void* unused)
{
    bool shutdownPending = false;
    errlHndl_t err = nullptr;

    // Mark as an independent daemon so if it crashes we terminate
    task_detach();

    TRACUCOMP( g_trac_trustedboot, ENTER_MRK "TpmDaemon Thread Start");

    // Register shutdown events with init service.
    //      Done at the "end" of shutdown processing.
    // This will flush any other messages (PCR extends) and terminate task
    INITSERVICE::registerShutdownEvent(TRBOOT_COMP_ID,
                                       systemData.msgQ,
                                       TRUSTEDBOOT::MSG_TYPE_SHUTDOWN);

    Message* tb_msg = nullptr;
    while (true)
    {
        msg_t* msg = msg_wait(systemData.msgQ);

        const MessageType type =
            static_cast<MessageType>(msg->type);
        tb_msg = nullptr;

        TRACUCOMP( g_trac_trustedboot, "TpmDaemon Handle CmdType %d",
                   type);

        switch (type)
        {
          case TRUSTEDBOOT::MSG_TYPE_SHUTDOWN:
              {
                  shutdownPending = true;

                  // Un-register message queue from the shutdown
                  INITSERVICE::unregisterShutdownEvent(systemData.msgQ);

              }
              break;
          case TRUSTEDBOOT::MSG_TYPE_PCREXTEND:
              {
                  tb_msg = static_cast<TRUSTEDBOOT::Message*>(msg->extra_data);

                  TRUSTEDBOOT::PcrExtendMsgData* msgData =
                      reinterpret_cast<TRUSTEDBOOT::PcrExtendMsgData*>
                      (tb_msg->iv_data);

                  assert(tb_msg->iv_len == sizeof(TRUSTEDBOOT::PcrExtendMsgData)
                         && msgData != nullptr, "Invalid PCRExtend Message");

                  TARGETING::TargetHandleList tpmList;
                  // if null TPM was passed extend all TPMs.  Otherwise, extend
                  // only the TPM that was passed
                  if (msgData->mSingleTpm == nullptr)
                  {
                      getTPMs(tpmList);
                  }
                  else
                  {
                      tpmList.push_back(const_cast<TpmTarget*>(
                                                         msgData->mSingleTpm));
                  }
                  for (auto tpm : tpmList)
                  {
                      // Add the event to this TPM,
                      // if an error occurs the TPM will
                      //  be marked as failed and the error log committed
                      TRUSTEDBOOT::pcrExtendSingleTpm(
                                   tpm,
                                   msgData->mPcrIndex,
                                   msgData->mEventType,
                                   msgData->mAlgId,
                                   msgData->mDigest,
                                   msgData->mDigestSize,
                                   msgData->mMirrorToLog? msgData->mLogMsg:
                                                                      nullptr,
                                   msgData->mMirrorToLog? msgData->mLogMsgSize:
                                                                      0);
                  }

                  // Lastly make sure we are in a state
                  //  where we have a functional TPM
                  TRUSTEDBOOT::tpmVerifyFunctionalPrimaryTpmExists(
                      NoTpmShutdownPolicy::BACKGROUND_SHUTDOWN);
              }
              break;
          case TRUSTEDBOOT::MSG_TYPE_SEPARATOR:
              {
                  tb_msg = static_cast<TRUSTEDBOOT::Message*>(msg->extra_data);

                  TARGETING::TargetHandleList tpmList;
                  getTPMs(tpmList);
                  for (auto tpm : tpmList)
                  {
                      // Add the separator to this TPM,
                      // if an error occurs the TPM will
                      //  be marked as failed and the error log committed
                      TRUSTEDBOOT::pcrExtendSeparator(tpm);
                  }

                  // Lastly make sure we are in a state
                  //  where we have a functional TPM
                  TRUSTEDBOOT::tpmVerifyFunctionalPrimaryTpmExists(
                      NoTpmShutdownPolicy::BACKGROUND_SHUTDOWN);
              }
              break;
          case TRUSTEDBOOT::MSG_TYPE_INIT_BACKUP_TPM:
              {
                  doInitBackupTpm();
              }
              break;
          case TRUSTEDBOOT::MSG_TYPE_GETRANDOM:
              {
                  errlHndl_t err = nullptr;
                  tb_msg = static_cast<TRUSTEDBOOT::Message*>(msg->extra_data);
                  assert(tb_msg != nullptr,
                      "Trusted boot message pointer absent in the extra data");
                  tb_msg->iv_errl = nullptr;

                  auto msgData =
                      reinterpret_cast<struct GetRandomMsgData*>
                      (tb_msg->iv_data);
                  assert(msgData != nullptr,
                      "Trusted boot message data pointer is null");
                  auto l_pTpm = msgData->i_pTpm;
                  size_t l_randNumSize = msgData->i_randNumSize;

                  if(l_randNumSize > sizeof(TPM2B_DIGEST))
                  {
                      TRACFCOMP( g_trac_trustedboot,
                        ERR_MRK"TPM GetRandom: The size of the requested random number (%d) is larger than max size the TPM can return (%d).", l_randNumSize, sizeof(TPM2B_DIGEST));
                      /*@
                       * @errortype  ERRL_SEV_UNRECOVERABLE
                       * @moduleid   MOD_TPM_TPMDAEMON
                       * @reasoncode RC_RAND_NUM_TOO_BIG
                       * @userdata1  The size of requested random number
                       * @userdata2  The maximum random number size
                       * @devdesc    Attempted to request a random number that
                       *             is bigger than the max a TPM can provide
                       * @custdesc   Trusted boot failure
                       */
                      err = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_TPM_TPMDAEMON,
                                           RC_RAND_NUM_TOO_BIG,
                                           l_randNumSize,
                                           sizeof(TPM2B_DIGEST),
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                      tb_msg->iv_errl = err;
                      err = nullptr;
                      break;
                  }

                  err = validateTpmHandle(l_pTpm);
                  if (err)
                  {
                      tb_msg->iv_errl = err;
                      err = nullptr;
                      break;
                  }
                  uint8_t dataBuf[sizeof(TPM2_GetRandomOut)] = {0};
                  size_t dataSize = sizeof(dataBuf);
                  auto cmd = reinterpret_cast<TPM2_GetRandomIn*>(dataBuf);
                  auto resp = reinterpret_cast<TPM2_GetRandomOut*>(dataBuf);

                  cmd->base.tag = TPM_ST_NO_SESSIONS;
                  cmd->base.commandCode = TPM_CC_GetRandom;
                  cmd->bytesRequested = l_randNumSize;

                  err = tpmTransmitCommand(l_pTpm, dataBuf, dataSize,
                                           TPM_LOCALITY_0);
                  if (err != nullptr)
                  {
                      TRACFCOMP( g_trac_trustedboot,
                          ERR_MRK"TPM GetRandom Transmit Fail! huid = 0x%08X",
                          TARGETING::get_huid(l_pTpm));
                      auto l_errPlid = err->plid();
                      tpmMarkFailed(l_pTpm, err);
                      /*@
                       * @errortype       ERRL_SEV_UNRECOVERABLE
                       * @moduleid        MOD_TPM_TPMDAEMON
                       * @reasoncode      RC_UNREACHABLE_TPM
                       * @userdata1       TPM HUID or nullptr
                       * @devdesc         Unable to reach the TPM
                       * @custdesc        Trusted boot failure
                       */
                      err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_TPM_TPMDAEMON,
                                          RC_UNREACHABLE_TPM,
                                          TARGETING::get_huid(l_pTpm),
                                          0,
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                      err->plid(l_errPlid);
                      tb_msg->iv_errl = err;
                      err = nullptr;
                  }
                  else
                  {
                      memcpy(msgData->o_randNum,
                             resp->randomBytes.buffer,
                             l_randNumSize);
                  }
              }
              break;
          case TRUSTEDBOOT::MSG_TYPE_FLUSH:
              {
                  TRACFCOMP(g_trac_trustedboot, "Flushing TPM message queue");
              }
              break;

          case TRUSTEDBOOT::MSG_TYPE_CREATE_ATT_KEYS:
              {
                  tb_msg = static_cast<TRUSTEDBOOT::Message*>(msg->extra_data);
                  TpmTargetData* l_data =
                           reinterpret_cast<TpmTargetData*>(tb_msg->iv_data);
                  tb_msg->iv_errl = doCreateAttKeys(l_data->tpm);
              }
              break;

          case TRUSTEDBOOT::MSG_TYPE_READ_AK_CERT:
              {
                  tb_msg = static_cast<TRUSTEDBOOT::Message*>(msg->extra_data);
                  ReadAKCertData* l_data =
                             reinterpret_cast<ReadAKCertData*>(tb_msg->iv_data);
                  tb_msg->iv_errl = doReadAKCert(l_data->tpm, l_data->data);
              }
              break;

          case TRUSTEDBOOT::MSG_TYPE_GEN_QUOTE:
              {
                  tb_msg = static_cast<TRUSTEDBOOT::Message*>(msg->extra_data);
                  GenQuoteData* l_data =
                               reinterpret_cast<GenQuoteData*>(tb_msg->iv_data);
                  tb_msg->iv_errl = doGenQuote(l_data->tpm,
                                               l_data->masterNonce,
                                               l_data->data);
              }
              break;

          case TRUSTEDBOOT::MSG_TYPE_FLUSH_CONTEXT:
              {
                  tb_msg = static_cast<TRUSTEDBOOT::Message*>(msg->extra_data);
                  TpmTargetData* l_data =
                              reinterpret_cast<TpmTargetData*>(tb_msg->iv_data);
                  tb_msg->iv_errl = doFlushContext(l_data->tpm);
              }
              break;

          case TRUSTEDBOOT::MSG_TYPE_PCR_READ:
              {
                  tb_msg = static_cast<TRUSTEDBOOT::Message*>(msg->extra_data);
                  PcrReadData* l_data =
                                reinterpret_cast<PcrReadData*>(tb_msg->iv_data);
                  tb_msg->iv_errl = doPcrRead(l_data->tpm,
                                              l_data->pcr,
                                              l_data->alg,
                                              l_data->digestSize,
                                              l_data->digest);
              }
              break;
          case TRUSTEDBOOT::MSG_TYPE_EXPAND_TPM_LOG:
              {
                  tb_msg = static_cast<TRUSTEDBOOT::Message*>(msg->extra_data);
                  TpmTargetData* l_data =
                              reinterpret_cast<TpmTargetData*>(tb_msg->iv_data);
                  tb_msg->iv_errl = doExpandTpmLog(l_data->tpm);
              }
              break;

          default:
            assert(false, "Invalid msg command");
            break;
        };

        // Reply back, if we have a tb_msg do that way
        if (nullptr != tb_msg)
        {
            tb_msg->response(systemData.msgQ);
        }
        else
        {
            // use the HB message type to respond
            int rc = msg_respond(systemData.msgQ, msg);
            if (rc)
            {
                TRACFCOMP( g_trac_trustedboot,
                           ERR_MRK "TpmDaemon: response msg_respond failure %d",
                           rc);
                /*@
                 * @errortype       ERRL_SEV_UNRECOVERABLE
                 * @moduleid        MOD_TPM_TPMDAEMON
                 * @reasoncode      RC_MSGRESPOND_FAIL
                 * @userdata1       rc from msq_respond()
                 * @devdesc         msg_respond() failed
                 * @custdesc        Firmware error during system boot
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              MOD_TPM_TPMDAEMON,
                                              RC_MSGRESPOND_FAIL,
                                              rc,
                                              0,
                                              true);
                err->collectTrace(SECURE_COMP_NAME);
                err->collectTrace(TRBOOT_COMP_NAME);

                // Log this failure here since we can't reply to caller
                errlCommit(err, TRBOOT_COMP_ID);

            }
        }

        if (shutdownPending)
        {
            // Exit loop and terminate task
            break;
        }
    }

    TRACUCOMP( g_trac_trustedboot, EXIT_MRK "TpmDaemon Thread Terminate");
    return nullptr;
}

errlHndl_t validateTpmHandle(const TpmTarget* i_pTpm)
{
    errlHndl_t err = nullptr;

    do {

    if (i_pTpm == nullptr ||
        i_pTpm->getAttr<TARGETING::ATTR_TYPE>() != TARGETING::TYPE_TPM)
    {
        TRACFCOMP(g_trac_trustedboot,
            ERR_MRK"Invalid TPM handle passed to validateTpmHandle: huid = 0x%08X",
            TARGETING::get_huid(i_pTpm));
        /*@
         * @errortype       ERRL_SEV_UNRECOVERABLE
         * @moduleid        MOD_VALIDATE_TPM_HANDLE
         * @reasoncode      RC_INVALID_TPM_HANDLE
         * @userdata1       TPM HUID if it's not nullptr
         * @devdesc         Caller attempted to get a random number from a TPM
         *                  using an invalid TPM target.
         * @custdesc        Trusted boot failure
         */
        err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_VALIDATE_TPM_HANDLE,
                                          RC_INVALID_TPM_HANDLE,
                                          TARGETING::get_huid(i_pTpm),
                                          0,
                                          true);

        break;
    }

    auto l_tpmHwasState = i_pTpm->getAttr<TARGETING::ATTR_HWAS_STATE>();
    if (!l_tpmHwasState.functional)
    {
        TRACFCOMP(g_trac_trustedboot,
            ERR_MRK"Non functional TPM handle passed to validateTpmHandle: huid = 0x%08X",
            TARGETING::get_huid(i_pTpm));
       /*@
         * @errortype       ERRL_SEV_UNRECOVERABLE
         * @moduleid        MOD_VALIDATE_TPM_HANDLE
         * @reasoncode      RC_NON_FUNCTIONAL_TPM_HANDLE
         * @userdata1       TPM HUID if it's not nullptr
         * @devdesc         Call attempted to get a random number from a TPM
         *                  that was not functional
         * @custdesc        Trusted boot failure
         */
        err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_VALIDATE_TPM_HANDLE,
                                          RC_NON_FUNCTIONAL_TPM_HANDLE,
                                          TARGETING::get_huid(i_pTpm),
                                          0,
                                          true);
        break;
    }

    } while(0);
    return err;
}

bool isTpmRequired()
{
    bool retVal = false;
    do
    {
/* TODO RTC: 259970 Fetch TPM Required sensor value via PLDM
        // First check if sensor is available
        if ( getTpmRequiredSensorValue(retVal) )
        {
            // Sensor is available so use its setting of retVal
            TRACUCOMP( g_trac_trustedboot, "isTpmRequired: Sensor is "
                       "available: using retVal=%d",
                       retVal );
            break;
        }
        else
        {
            // Sensor not available; reset retVal to be safe
            retVal = false;
        }
*/

        // TPM always required in simics
        if(Util::isSimicsRunning())
        {
            retVal = true;
        }
        else
        {
            // On HW, use ATTR_TPM_REQUIRED
            TARGETING::Target* pTopLevel =
                TARGETING::UTIL::assertGetToplevelTarget();
            retVal = pTopLevel->getAttr<TARGETING::ATTR_TPM_REQUIRED>();
        }

        TRACUCOMP( g_trac_trustedboot, "isTpmRequired: Using ATTR_TPM_REQUIRED:"
                   " retVal=%d",
                   retVal );

    } while(0);

    TRACFCOMP( g_trac_trustedboot,
               "Tpm Required: %s",(retVal ? "Yes" : "No") );

    return retVal;
}

bool getTpmRequiredSensorValue(bool& o_isTpmRequired)
{
    bool retVal = false;
    o_isTpmRequired = false;

    // Get TPM Required Sensor
#ifdef CONFIG_BMC_IPMI

    TARGETING::Target* pTopLevel = nullptr;
    (void)TARGETING::targetService().getTopLevelTarget(pTopLevel);
    assert(pTopLevel != nullptr, "Unable to get top level target");

    uint32_t sensorNum = TARGETING::UTIL::getSensorNumber(pTopLevel,
                                        TARGETING::SENSOR_NAME_TPM_REQUIRED);

    TRACUCOMP( g_trac_trustedboot,"getTpmRequiredSensorValue: sensorNum=0x%X, "
               "enum=0x%X",
               sensorNum, TARGETING::SENSOR_NAME_TPM_REQUIRED);

    // VALID IPMI sensors are 0-0xFE
    if (TARGETING::UTIL::INVALID_IPMI_SENSOR != sensorNum)
    {
        // Check if TPM is required by BMC
        SENSOR::getSensorReadingData tpmRequiredData;
        SENSOR::SensorBase tpmRequired(TARGETING::SENSOR_NAME_TPM_REQUIRED,
                                       pTopLevel);

        errlHndl_t err = tpmRequired.readSensorData(tpmRequiredData);
        if (nullptr == err)
        {
            // Sensor is available and found without error
            retVal = true;

            // 0x02 == Asserted bit (TPM is required)
            if ((tpmRequiredData.event_status &
                 (1 << SENSOR::ASSERTED)) ==
                (1 << SENSOR::ASSERTED))
            {
                o_isTpmRequired = true;
            }
        }
        else
        {
            // error reading sensor, so consider sensor not available
            TRACFCOMP( g_trac_trustedboot,ERR_MRK"getTpmRequiredSensorValue: "
                       "Unable to read Tpm Required Sensor: rc = 0x%04X "
                       "(sensorNum=0x%X, enum=0x%X) Deleting Error plid=0x%04X."
                       " Considering Sensor NOT required",
                       err->reasonCode(), sensorNum,
                       TARGETING::SENSOR_NAME_TPM_REQUIRED,
                       err->plid());
            delete err;
            err = nullptr;
            retVal = false;
        }
    }
    else
    {
        // Sensor not available
        retVal = false;
        TRACUCOMP( g_trac_trustedboot, "getTpmRequiredSensorValue: Sensor "
                   "not available: retVal=%d (sensorNum=0x%X)",
                   retVal, sensorNum );
    }

    TRACFCOMP( g_trac_trustedboot,
               "getTpmRequiredSensorValue: isAvail=%s, o_isTpmRequired=%s",
               (retVal ? "Yes" : "No"),
               (o_isTpmRequired ? "Yes" : "No") );
#else
    // IPMI support not there, so consider sensor not available
    retVal = false;
    TRACUCOMP( g_trac_trustedboot, "getTpmRequiredSensorValue: IPMI Support "
               "not found; retVal=%d",
               retVal );
#endif

    return retVal;
}


#ifdef CONFIG_TPMDD
errlHndl_t GetRandom(const TpmTarget* i_pTpm,
                     const size_t i_randNumSize,
                     uint8_t* o_randNum)
{
    errlHndl_t err = nullptr;
    Message* msg = nullptr;

    auto pData = new struct GetRandomMsgData;

    do {

    memset(pData, 0, sizeof(*pData));
    pData->i_pTpm = const_cast<TpmTarget*>(i_pTpm);
    pData->i_randNumSize = i_randNumSize;
    pData->o_randNum = new uint8_t[i_randNumSize];
    memset(pData->o_randNum, 0, i_randNumSize);

    msg = Message::factory(MSG_TYPE_GETRANDOM, sizeof(*pData),
                           reinterpret_cast<uint8_t*>(pData), MSG_MODE_SYNC);

    assert(msg != nullptr, "BUG! Message is null");
    pData = nullptr; // Message owns msgData now

    int rc = msg_sendrecv(systemData.msgQ, msg->iv_msg);
    if (0 == rc)
    {
        err = msg->iv_errl;
        msg->iv_errl = nullptr; // taking over ownership of error log
        if (err != nullptr)
        {
            break;
        }
    }
    else // sendrecv failure
    {
        /*@
         * @errortype       ERRL_SEV_UNRECOVERABLE
         * @moduleid        MOD_TPM_GETRANDOM
         * @reasoncode      RC_SENDRECV_FAIL
         * @userdata1       rc from msq_sendrecv()
         * @userdata2       TPM HUID if it's not nullptr
         * @devdesc         msg_sendrecv() failed
         * @custdesc        Trusted boot failure
         */
        err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      MOD_TPM_GETRANDOM,
                                      RC_SENDRECV_FAIL,
                                      rc,
                                      TARGETING::get_huid(i_pTpm),
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        break;
    }

    pData = reinterpret_cast<struct GetRandomMsgData*>(msg->iv_data);
    assert(pData != nullptr,
        "BUG! Completed send/recv to random num generator has null data ptr!");

    memcpy(o_randNum, pData->o_randNum, pData->i_randNumSize);

    } while (0);

    // If an error occurs before the reponse is written, then pData
    // will be nullptr and dereferencing o_randNum will cause crashes.
    // So, we need to check for pData before attempting to delete the
    // o_randNum.
    if(pData)
    {
        if(pData->o_randNum)
        {
            delete[](pData->o_randNum);
            pData->o_randNum = nullptr;
        }
    }

    if (msg != nullptr)
    {
        delete msg; // also deletes the msg->iv_data
        msg = nullptr;
    }

    if (err)
    {
        err->collectTrace(SECURE_COMP_NAME);
        err->collectTrace(TRBOOT_COMP_NAME);
    }

    return err;
}
#endif // CONFIG_TPMDD

errlHndl_t poisonTpm(TpmTarget* i_pTpm)
{
    uint64_t l_randNum = 0;
    errlHndl_t l_errl = nullptr;

#ifdef CONFIG_TPMDD

    do {

    l_errl = validateTpmHandle(i_pTpm);
    if(l_errl)
    {
        break;
    }

    i_pTpm->setAttr<TARGETING::ATTR_TPM_POISONED>(true);

    // Note: GetRandom validates the TPM handle internally and returns an
    // error log if invalid
    l_errl = GetRandom(i_pTpm,
                       sizeof(l_randNum),
                       reinterpret_cast<uint8_t*>(&l_randNum));

    if (l_errl)
    {
        break;
    }

    const TPM_Pcr l_pcrRegs[] = {PCR_0, PCR_1, PCR_2, PCR_3,
                                 PCR_4, PCR_5, PCR_6, PCR_7};

    // poison all PCR banks
    for (const auto l_pcrReg : l_pcrRegs)
    {
        l_errl = pcrExtend(l_pcrReg,
                           TRUSTEDBOOT::EV_INVALID,
                           reinterpret_cast<sha2_byte*>(&l_randNum),
                           sizeof(l_randNum),
                           nullptr, // log not needed for poison operation
                           0,       // log size is 0
                           false,   // call synchronously to daemon
                           i_pTpm,  // only extend to pcr banks for this TPM
                           false);  // don't add PCR measurement to the log
        if (l_errl)
        {
            break;
        }

    }

    } while (0);

    TRACFCOMP(g_trac_trustedboot, "%ssuccessfully poisoned TPM with huid 0x%X",
              l_errl? "Un":"", TARGETING::get_huid(i_pTpm));

#endif
    return l_errl;
}

errlHndl_t poisonAllTpms()
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    do {

    TARGETING::TargetHandleList l_tpms;
    getTPMs(l_tpms, TRUSTEDBOOT::TPM_FILTER::ALL_FUNCTIONAL);
    for(auto l_tpm : l_tpms)
    {
        l_errl = poisonTpm(l_tpm);
        if(l_errl)
        {
            break;
        }
    }

    } while(0);
#endif
    return l_errl;
}

void markTpmUnusable(TARGETING::Target* i_tpm,
                     const errlHndl_t i_associatedErrl)
{
    do {

    if(i_tpm->getAttr<TARGETING::ATTR_TPM_UNUSABLE>())
    {
        TRACFCOMP(g_trac_trustedboot, "TPM HUID 0x%08x is already set as UNUSABLE; will not create additional error logs",
                  TARGETING::get_huid(i_tpm));
        break;
    }

    TRACFCOMP(g_trac_trustedboot, "Marking TPM HUID 0x%08x as UNUSABLE",
              TARGETING::get_huid(i_tpm));
    i_tpm->setAttr<TARGETING::ATTR_TPM_UNUSABLE>(true);
    /* @
     * @errortype
     * @reasoncode RC_TPM_IS_UNUSABLE
     * @moduleid   MOD_MARK_TPM_UNUSABLE
     * @severity   ERRL_SEV_UNRECOVERABLE
     * @userdata1  The HUID of the affected TPM
     * @devdesc    One of the TPMs on the system has been diabled and flagged as
     *             UNUSABLE. The affected TPM will remain UNUSABLE until it has
     *             been explicitly re-enabled.  To re-enable the TPM, power the
     *             system off, disable the TPM Required policy, and boot the
     *             system.  With the TPM back in service, power the system off,
     *             restore the original TPM Required policy, and boot one final
     *             time.
     *             Potential reasons:
     *             - TPM was not detected present
     *             - TPM was detected by later failed
     *             - TPM was disabled by the OS due to error
     * @custdesc   One of the TPMs on the system has been diabled and flagged as
     *             UNUSABLE. The affected TPM will remain UNUSABLE until it has
     *             been explicitly re-enabled.  To re-enable the TPM, power the
     *             system off, disable the TPM Required policy, and boot the
     *             system.  With the TPM back in service, power the system off,
     *             restore the original TPM Required policy, and boot one final
     *             time.
     */
    errlHndl_t l_errl =
                   new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_MARK_TPM_UNUSABLE,
                                           RC_TPM_IS_UNUSABLE,
                                           TARGETING::get_huid(i_tpm));
    // High priority callout for TPM
    l_errl->addHwCallout(i_tpm,
                         HWAS::SRCI_PRIORITY_HIGH,
                         HWAS::NO_DECONFIG,
                         HWAS::GARD_NULL);

    // Medium priority callout for Hostboot firmware
    l_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                HWAS::SRCI_PRIORITY_MED);

    ERRORLOG::ErrlUserDetailsTarget(i_tpm).addToLog(l_errl);

    l_errl->collectTrace(SECURE_COMP_NAME);
    l_errl->collectTrace(TRBOOT_COMP_NAME);
    l_errl->collectTrace(SPI_COMP_NAME);
    l_errl->collectTrace(HWAS_COMP_NAME);

    if(i_associatedErrl)
    {
        l_errl->plid(i_associatedErrl->plid());
    }

    errlCommit(l_errl, TRBOOT_COMP_ID);
    }while(0);
}

} // end TRUSTEDBOOT
