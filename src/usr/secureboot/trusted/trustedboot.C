/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedboot.C $                    */
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
#include <targeting/targplatutil.H>
#include <targeting/common/targetservice.H>
#include <secureboot/service.H>
#include <secureboot/trustedbootif.H>
#include <secureboot/trustedboot_reasoncodes.H>
#include <sys/mmio.h>
#include <sys/task.h>
#include <initservice/initserviceif.H>
#ifdef CONFIG_BMC_IPMI
#include <ipmi/ipmisensor.H>
#endif
#include <config.h>
#include <devicefw/driverif.H>
#include <i2c/tpmddif.H>
#include "trustedboot.H"
#include "trustedTypes.H"
#include "trustedbootCmds.H"
#include "trustedbootUtils.H"
#include "tpmLogMgr.H"
#include "base/trustedbootMsg.H"
#include <secureboot/settings.H>
#ifdef CONFIG_DRTM
#include <secureboot/drtm.H>
#endif
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <p9_update_security_ctrl.H>
#include <targeting/common/commontargeting.H>
#include <algorithm>
#include <util/misc.H>

namespace TRUSTEDBOOT
{

extern SystemData systemData;

errlHndl_t getTpmLogDevtreeInfo(
    const TpmTarget* const i_pTpm,
          uint64_t &       io_logAddr,
          size_t &         o_allocationSize,
          uint64_t &       o_xscomAddr,
          uint32_t &       o_i2cMasterOffset)
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
                                       o_i2cMasterOffset);
    }
    TRACUCOMP( g_trac_trustedboot,
               EXIT_MRK"getTpmLogDevtreeInfo() Addr:0x%016lX",io_logAddr);
    return err;
}

void setTpmDevtreeInfo(
    const TpmTarget* const i_pTpm,
    const uint64_t         i_xscomAddr,
    const uint32_t         i_i2cMasterOffset)
{
    assert(i_pTpm != nullptr,"setTpmLogDevtreeInfo: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "setTpmLogDevtreeInfo: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());

    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"setTpmLogDevtreeOffset() tgt=0x%08X "
               "Xscom:0x%016lX Master:0x%08X",
               TARGETING::get_huid(i_pTpm),
               i_xscomAddr, i_i2cMasterOffset);

    auto * const pTpmLogMgr = getTpmLogMgr(i_pTpm);
    if (nullptr != pTpmLogMgr)
    {
        TpmLogMgr_setTpmDevtreeInfo(pTpmLogMgr,
                                    i_xscomAddr, i_i2cMasterOffset);
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

bool enabled()
{
    bool enabled = false;
#ifdef CONFIG_TPMDD
    TARGETING::TargetHandleList tpmList;
    getTPMs(tpmList,TPM_FILTER::ALL_IN_BLUEPRINT);

    TARGETING::PredicateHwas presentAndFunctional;
    presentAndFunctional.present(true);
    presentAndFunctional.functional(true);

    TARGETING::PredicateAttrVal<TARGETING::ATTR_HB_TPM_INIT_ATTEMPTED>
        initialized(true);

    auto itr = std::find_if(tpmList.begin(),tpmList.end(),
        [&presentAndFunctional,&initialized](
            const TARGETING::Target* const i_pTpm)
        {
            return (   presentAndFunctional(i_pTpm)
                    || !initialized(i_pTpm));
        });

    enabled = (itr!=tpmList.end()) ? true : false;
#endif
    return enabled;
}

void* host_update_master_tpm( void *io_pArgs )
{
    errlHndl_t err = nullptr;
    bool unlock = false;

    TRACDCOMP( g_trac_trustedboot,
               ENTER_MRK"host_update_master_tpm()" );
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"host_update_master_tpm()");

    // Get all TPMs to setup our array
    TARGETING::TargetHandleList tpmList;
    getTPMs(tpmList,TPM_FILTER::ALL_IN_BLUEPRINT);

    // Currently we only support a MAX of two TPMS per node
    assert(tpmList.size() <= MAX_TPMS_PER_NODE, "Too many TPMs found");

    do
    {
        if (tpmList.empty())
        {
            TRACFCOMP( g_trac_trustedboot,
                       "No TPM Targets found");
            break;
        }

        TARGETING::TargetService& tS = TARGETING::targetService();

        TARGETING::Target* procTarget = nullptr;
        err = tS.queryMasterProcChipTargetHandle( procTarget );
        if (nullptr != err)
        {
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
                // If TPM connected to acting master processor, it is
                // primary; otherwise it is backup
                TARGETING::TPM_ROLE tpmRole =
                    (tpmData.i2cTarget == procTarget) ?
                          TARGETING::TPM_ROLE_TPM_PRIMARY
                        : TARGETING::TPM_ROLE_TPM_BACKUP;
                tpm->setAttr<TARGETING::ATTR_TPM_ROLE>(tpmRole);
            }
        }

        // Initialize primary TPM
        TARGETING::Target* pPrimaryTpm = nullptr;
        (void)getPrimaryTpm(pPrimaryTpm);
        if(pPrimaryTpm)
        {
            auto hwasState = pPrimaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>();
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

            // Allocate TPM log if it hasn't been already
            auto pTpmLogMgr = getTpmLogMgr(pPrimaryTpm);
            // Need to grab state again, as it could have changed
            hwasState = pPrimaryTpm->getAttr<
                TARGETING::ATTR_HWAS_STATE>();
            if(   hwasState.present
               && hwasState.functional
               && nullptr == pTpmLogMgr)
            {
                // @todo RTC:145689 For DRTM we locate the previous SRTM log
                // and reuse.  We must also allocate a DRTM log to be used
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

        bool primaryTpmAvail = (pPrimaryTpm != nullptr);
        if(primaryTpmAvail)
        {
            auto primaryHwasState = pPrimaryTpm->getAttr<
                TARGETING::ATTR_HWAS_STATE>();
            if (!primaryHwasState.functional ||
                !primaryHwasState.present)
            {
                primaryTpmAvail = false;
            }
        }

        if(!primaryTpmAvail)
        {
            /// @todo RTC:134913 Switch to backup chip if backup TPM avail

            // Primary TPM not available
            TRACFCOMP( g_trac_trustedboot,
                       "Primary TPM Existence Fail");
        }

        TARGETING::Target* pBackupTpm = nullptr;
        getBackupTpm(pBackupTpm);
        if(pBackupTpm == nullptr)
        {
            TRACUCOMP( g_trac_trustedboot,
                       "host_update_master_tpm() "
                       "Backup TPM unavailable "
                       "since it's not in the system blueprint.");
        }
        else
        {
            TPMDD::tpm_info_t tpmInfo;
            memset(&tpmInfo, 0, sizeof(tpmInfo));
            errlHndl_t tmpErr = TPMDD::tpmReadAttributes(
                                 pBackupTpm,
                                 tpmInfo,
                                 TPM_LOCALITY_0);
            if (nullptr != tmpErr || !tpmInfo.tpmEnabled)
            {
                TRACUCOMP( g_trac_trustedboot,
                           "host_update_master_tpm() "
                           "Marking backup TPM unavailable");

                auto backupHwasState = pBackupTpm->getAttr<
                    TARGETING::ATTR_HWAS_STATE>();
                backupHwasState.present = false;
                backupHwasState.functional = false;
                pBackupTpm->setAttr<
                    TARGETING::ATTR_HWAS_STATE>(backupHwasState);


                pBackupTpm->setAttr<TARGETING::ATTR_HB_TPM_INIT_ATTEMPTED>(
                    true);
                if (nullptr != tmpErr)
                {
                    // Ignore attribute read failure
                    delete tmpErr;
                    tmpErr = nullptr;
                }
            }
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
    TRUSTEDBOOT::tpmVerifyFunctionalTpmExists();

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
                   "host_update_master_tpm() - "
                   "Primary TPM Present:%d Functional:%d Init Attempted:%d",
                   pPrimaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().
                       present,
                   pPrimaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().
                       functional,
                   pPrimaryTpm->getAttr<
                       TARGETING::ATTR_HB_TPM_INIT_ATTEMPTED>());
    }

    TARGETING::Target* pBackupTpm = nullptr;
    (void)getBackupTpm(pBackupTpm);
    if(pBackupTpm)
    {
        TRACUCOMP( g_trac_trustedboot,
                   "host_update_master_tpm() - "
                   "Backup TPM Present:%d Functional:%d Init Attempted:%d",
                   pBackupTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().
                       present,
                   pBackupTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().
                       functional,
                   pBackupTpm->getAttr<
                       TARGETING::ATTR_HB_TPM_INIT_ATTEMPTED>());
    }

    TRACDCOMP( g_trac_trustedboot,
               EXIT_MRK"host_update_master_tpm() - %s",
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

    TRACDCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmInitialize()" );
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmInitialize() tgt=0x%08X",
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

        // read + write
        bool sendStartup = true;

#ifdef CONFIG_DRTM
        bool drtmMpipl = false;
        (void)SECUREBOOT::DRTM::isDrtmMpipl(drtmMpipl);
        if(drtmMpipl)
        {
            sendStartup = false;
        }
#endif
        // Don't run STARTUP during DRTM
        if (sendStartup)
        {
            // TPM_STARTUP
            err = tpmCmdStartup(i_pTpm);
            if (nullptr != err)
            {
                break;
            }
        }

        // TPM_GETCAPABILITY to read FW Version
        err = tpmCmdGetCapFwVersion(i_pTpm);
        if (nullptr != err)
        {
            break;
        }

#ifdef CONFIG_TPM_NVIDX_VALIDATE
        // Find out if in manufacturing mode
        TARGETING::Target* pTopLevel = nullptr;
        TARGETING::targetService().getTopLevelTarget(pTopLevel);
        assert(pTopLevel != nullptr,"Top level target was nullptr");

        auto mnfgFlags =
            pTopLevel->getAttr<TARGETING::ATTR_MNFG_FLAGS>();

        // Only validate during MFG IPL
        if (mnfgFlags & TARGETING::MNFG_FLAG_SRC_TERM &&
            !Util::isSimicsRunning()) {
            // TPM_GETCAPABILITY to validate NV Indexes
            err = tpmCmdGetCapNvIndexValidate(i_pTpm);
            if (nullptr != err)
            {
                break;
            }
        }
#endif

#ifdef CONFIG_DRTM
        // For a DRTM we need to reset PCRs 17-22
        if (drtmMpipl)
        {
            err = tpmDrtmReset(i_pTpm);
            if (nullptr != err)
            {
                break;
            }
        }
#endif

    } while ( 0 );


    // If the TPM failed we will mark it not functional
    if (nullptr != err)
    {
        tpmMarkFailed(i_pTpm);
        // Log this failure
        errlCommit(err, TRBOOT_COMP_ID);
    }

    TRACDCOMP( g_trac_trustedboot,
               EXIT_MRK"tpmInitialize()");
}

void tpmReplayLog(TRUSTEDBOOT::TpmTarget* const i_pTpm)
{
    assert(i_pTpm != nullptr,"tpmReplayLog: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "tpmReplayLog: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());

    TRACUCOMP(g_trac_trustedboot, ENTER_MRK"tpmReplayLog()");
    errlHndl_t err = nullptr;
    bool unMarshalError = false;


    // Create EVENT2 structure to be populated by getNextEvent()
    TCG_PCR_EVENT2 l_eventLog = {0};
    // Move past header event to get a pointer to the first event
    // If there are no events besides the header, l_eventHndl = nullptr
    auto * const pTpmLogMgr = getTpmLogMgr(i_pTpm);
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
            break;
        }

        // Extend to tpm
        if (EV_ACTION == l_eventLog.eventType)
        {
            TRACUBIN(g_trac_trustedboot, "tpmReplayLog: Extending event:",
                     &l_eventLog, sizeof(TCG_PCR_EVENT2));
            for (size_t i = 0; i < l_eventLog.digests.count; i++)
            {

                TPM_Alg_Id l_algId = (TPM_Alg_Id)l_eventLog.digests.digests[i]
                                                                .algorithmId;
                err = tpmCmdPcrExtend(i_pTpm,
                            (TPM_Pcr)l_eventLog.pcrIndex,
                            l_algId,
                            reinterpret_cast<uint8_t*>
                                      (&(l_eventLog.digests.digests[i].digest)),
                            getDigestSize(l_algId));
                if (err)
                {
                    break;
                }
            }
            if (err)
            {
                break;
            }
        }
    }
    // If the TPM failed we will mark it not functional and commit errl
    if (err)
    {
        tpmMarkFailed(i_pTpm);
        errlCommit(err, TRBOOT_COMP_ID);
        delete err;
        err = nullptr;
    }
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
            break;
        }
        TRACFCOMP(g_trac_trustedboot, "security switch value = 0x%016lX",
                                l_securitySwitchValue);
        // Extend to TPM - PCR_1
        memcpy(l_digest, &l_securitySwitchValue, sizeof(l_securitySwitchValue));
        l_err = pcrExtend(PCR_1, EV_PLATFORM_CONFIG_FLAGS,
                          l_digest, sizeof(l_securitySwitchValue),
                          "Security Switches");
        if (l_err)
        {
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
        l_err = pcrExtend(PCR_1, EV_PLATFORM_CONFIG_FLAGS,
                          l_digest, sizeof(l_pvr),"PVR of Chip");
        if (l_err)
        {
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
        const TPM_Pcr l_pcrs[] = {PCR_1,PCR_4,PCR_5,PCR_6};
        for (size_t i = 0; i < (sizeof(l_pcrs)/sizeof(TPM_Pcr)) ; ++i)
        {
            l_err = pcrExtend(l_pcrs[i],
                              (l_pcrs[i] == PCR_1 ?
                               EV_PLATFORM_CONFIG_FLAGS : EV_COMPACT_HASH),
                              l_digest, sizeof(l_nodeid),"Node id");
            if (l_err)
            {
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
        l_err = pcrExtend(PCR_1, EV_PLATFORM_CONFIG_FLAGS,
                          l_digest, sizeof(l_tpmRequired),
                          "Tpm Required");
        if (l_err)
        {
            break;
        }

        // HW Key Hash
        SHA512_t l_hw_key_hash;
        SECUREBOOT::getHwKeyHash(l_hw_key_hash);
        l_err = pcrExtend(PCR_1, EV_PLATFORM_CONFIG_FLAGS,
                          l_hw_key_hash,
                          sizeof(SHA512_t),"HW KEY HASH");
        if (l_err)
        {
            break;
        }

    } while(0);

    return l_err;
}

void pcrExtendSingleTpm(TpmTarget* const i_pTpm,
                        const TPM_Pcr i_pcr,
                        const EventTypes i_eventType,
                        TPM_Alg_Id i_algId,
                        const uint8_t* i_digest,
                        size_t  i_digestSize,
                        const char* i_logMsg)
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

#ifdef CONFIG_DRTM
    // In a DRTM flow, all extensions must be re-rerouted to PCR 17
    // (which will end up using locality 2).
    bool drtmMpipl = false;
    (void)SECUREBOOT::DRTM::isDrtmMpipl(drtmMpipl);
    if(drtmMpipl)
    {
        TRACFCOMP(g_trac_trustedboot,
            INFO_MRK " pcrExtendSingleTpm(): DRTM active; re-routing PCR %d "
            "extend to PCR 17",
            i_pcr);

        pcr = PCR_DRTM_17;
        useStaticLog = false;
    }
#endif

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
            // Fill in TCG_PCR_EVENT2 and add to log
            eventLog = TpmLogMgr_genLogEventPcrExtend(pcr, i_eventType,
                                                      i_algId, i_digest,
                                                      i_digestSize,
                                                      TPM_ALG_SHA1, i_digest,
                                                      i_digestSize,
                                                      i_logMsg);
            if(useStaticLog)
            {
                auto * const pTpmLogMgr = getTpmLogMgr(i_pTpm);
                err = TpmLogMgr_addEvent(pTpmLogMgr,&eventLog);
                if (nullptr != err)
                {
                    break;
                }
            }

            // TODO: RTC 145689: Add DRTM support for using dynamic
            // log instead of static log; until then, inhibit DRTM logging
            // entirely

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
        tpmMarkFailed(i_pTpm);

        // Log this failure
        errlCommit(err, TRBOOT_COMP_ID);
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
    const char logMsg[] = { 0xFF, 0xFF, 0xFF, 0xFF, '\0'};

    memset(&eventLog, 0, sizeof(eventLog));
    do
    {
        mutex_lock( i_pTpm->getHbMutexAttr<TARGETING::ATTR_HB_TPM_MUTEX>() ) ;
        unlock = true;

        std::vector<TPM_Pcr> pcrs =
            {PCR_0,PCR_1,PCR_2,PCR_3,PCR_4,PCR_5,PCR_6,PCR_7};
        bool useStaticLog = true;

#ifdef CONFIG_DRTM
        // In a DRTM flow, all extensions must be re-rerouted to PCR 17
        // (which will end up using locality 2).
        bool drtmMpipl = false;
        (void)SECUREBOOT::DRTM::isDrtmMpipl(drtmMpipl);
        if(drtmMpipl)
        {
            TRACFCOMP(g_trac_trustedboot,
                INFO_MRK " pcrExtendSeparator(): DRTM active; extending "
                "separator to PCR 17 instead of PCR 0..7.");

            pcrs = { PCR_DRTM_17 };
            useStaticLog = false;
        }
#endif

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
                                                          logMsg);

                if(useStaticLog)
                {
                    auto * const pTpmLogMgr = getTpmLogMgr(i_pTpm);
                    err = TpmLogMgr_addEvent(pTpmLogMgr,&eventLog);
                    if (nullptr != err)
                    {
                        break;
                    }
                }

                // TODO: RTC 145689: Add DRTM support for using dynamic
                // log (which will happen any time useStaticLog is false).
                // Until then, we cannot log DRTM events, since they are only
                // allowed to go to the dynamic log

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
        tpmMarkFailed(i_pTpm);

        // Log this failure
        errlCommit(err, TRBOOT_COMP_ID);
    }

    if (unlock)
    {
        mutex_unlock( i_pTpm->getHbMutexAttr<TARGETING::ATTR_HB_TPM_MUTEX>() ) ;
    }
    return;
}

void tpmMarkFailed(TpmTarget* const i_pTpm)
{
    assert(i_pTpm != nullptr,"tpmMarkFailed: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "tpmMarkFailed: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());

    TRACFCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmMarkFailed() Marking TPM as failed : "
               "tgt=0x%08X",
               TARGETING::get_huid(i_pTpm));

    auto hwasState = i_pTpm->getAttr<
        TARGETING::ATTR_HWAS_STATE>();
    hwasState.functional = false;
    i_pTpm->setAttr<
        TARGETING::ATTR_HWAS_STATE>(hwasState);

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

    auto l_tpmInfo = l_tpm->getAttr<TARGETING::ATTR_TPM_INFO>();

    for(auto it : l_procList)
    {
        auto l_physPath = it->getAttr<TARGETING::ATTR_PHYS_PATH>();
        if (l_tpmInfo.i2cMasterPath == l_physPath)
        {
            // found processor to deconfigure
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

    // do not deconfigure the processor if it already deconfigured
    TARGETING::PredicateHwas isNonFunctional;
    isNonFunctional.functional(false);
    if (isNonFunctional(l_proc))
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
    // yet, so we will let istep 10.3 call p9_update_security_control HWP
    // if the SBE lock bit is set, then we will call the HWP here
    if (!(l_regValue & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::SULBit)))
    {
        break;
    }

    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapiTarg(l_proc);

    FAPI_INVOKE_HWP(l_err, p9_update_security_ctrl, l_fapiTarg);

    if (l_err)
    {
        TRACFCOMP(g_trac_trustedboot,
            ERR_MRK"tpmMarkFailed - call to p9_update_security_ctrl failed ");
    }

    } while(0);

    if (l_err)
    {
        TRACFCOMP(g_trac_trustedboot,
            ERR_MRK "Processor tgt=0x%08X TPM tgt=0x%08X. Deconfiguring "
            "processor because future security cannot be guaranteed.",
            TARGETING::get_huid(l_proc),
            TARGETING::get_huid(l_tpm));

        // save the plid from the error before commiting
        auto plid = l_err->plid();

        ERRORLOG::ErrlUserDetailsTarget(l_proc).addToLog(l_err);

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

        l_err->addHwCallout(l_proc,
                            HWAS::SRCI_PRIORITY_LOW,
                            HWAS::DELAYED_DECONFIG,
                            HWAS::GARD_NULL);

        l_err->collectTrace(SECURE_COMP_NAME);
        l_err->collectTrace(TRBOOT_COMP_NAME);

        // pass on the plid from the previous error log to the new one
        l_err->plid(plid);

        ERRORLOG::ErrlUserDetailsTarget(l_proc).addToLog(l_err);

        ERRORLOG::errlCommit(l_err, TRBOOT_COMP_ID);
    }
    #endif
}

void tpmVerifyFunctionalTpmExists()
{
    errlHndl_t err = nullptr;
    bool foundFunctional = enabled();

    if (!foundFunctional && !systemData.failedTpmsPosted)
    {
        systemData.failedTpmsPosted = true;
        TRACFCOMP( g_trac_trustedboot,
                   "NO FUNCTIONAL TPM FOUND");

        // Check to ensure jumper indicates we are running secure
        SECUREBOOT::SecureJumperState l_state
                          = SECUREBOOT::SecureJumperState::SECURITY_DEASSERTED;
        err = SECUREBOOT::getJumperState(l_state);
        if (err)
        {
            errlCommit(err, TRBOOT_COMP_ID);

            auto errPlid = err->plid();

            // we should not continue if we could not read the jumper state
            INITSERVICE::doShutdown(errPlid);
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
                 * @devdesc        No functional TPMs exist in the system
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              MOD_TPM_VERIFYFUNCTIONAL,
                                              RC_TPM_NOFUNCTIONALTPM_FAIL);

                // Add low priority HB SW callout
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_LOW);
                err->collectTrace( SECURE_COMP_NAME );
                err->collectTrace(TRBOOT_COMP_NAME);
                uint32_t errPlid = err->plid();

                // HW callout TPMs
                TARGETING::TargetHandleList l_tpmList;
                TRUSTEDBOOT::getTPMs(l_tpmList, TPM_FILTER::ALL_IN_BLUEPRINT);
                for(const auto &tpm : l_tpmList)
                {
                    err->addHwCallout(tpm,
                                      HWAS::SRCI_PRIORITY_HIGH,
                                      HWAS::NO_DECONFIG,
                                      HWAS::GARD_NULL);
                }
                errlCommit(err, TRBOOT_COMP_ID);
                // terminating the IPL with this fail
                // Terminate IPL immediately
                INITSERVICE::doShutdown(errPlid);
            }
            else
            {
                TRACUCOMP( g_trac_trustedboot,
                           "No functional TPM's found but TPM not Required");
            }
        }
        else
        {
            TRACUCOMP( g_trac_trustedboot,
                       "No functional TPM's found but not running secure");
        }

    }

    return;
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
    INITSERVICE::registerShutdownEvent(systemData.msgQ,
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
                  getTPMs(tpmList);
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
                                   msgData->mLogMsg);
                  }

                  // Lastly make sure we are in a state
                  //  where we have a functional TPM
                  TRUSTEDBOOT::tpmVerifyFunctionalTpmExists();
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
                      TRUSTEDBOOT::pcrExtendSeparator(
                                   tpm);
                  }

                  // Lastly make sure we are in a state
                  //  where we have a functional TPM
                  TRUSTEDBOOT::tpmVerifyFunctionalTpmExists();
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

bool isTpmRequired()
{
    bool retVal = false;

    do
    {
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


        // Since sensor isn't available, use ATTR_TPM_REQUIRED
        TARGETING::Target* pTopLevel = nullptr;
        (void)TARGETING::targetService().getTopLevelTarget(pTopLevel);
        assert(pTopLevel != nullptr, "Unable to get top level target");

        retVal = pTopLevel->getAttr<TARGETING::ATTR_TPM_REQUIRED>();

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
#else
    // IPMI support not there, so consider sensor not available
    retVal = false;
    TRACUCOMP( g_trac_trustedboot, "getTpmRequiredSensorValue: IPMI Support "
               "not found; retVal=%d",
               retVal );
#endif


    TRACFCOMP( g_trac_trustedboot,
               "getTpmRequiredSensorValue: isAvail=%s, o_isTpmRequired=%s",
               (retVal ? "Yes" : "No"),
               (o_isTpmRequired ? "Yes" : "No") );

    return retVal;
}


#ifdef CONFIG_DRTM
errlHndl_t tpmDrtmReset(TpmTarget* const i_pTpm)
{
    assert(i_pTpm != nullptr,"tpmDrtmReset: BUG! i_pTpm was nullptr");
    assert(i_pTpm->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM,
           "tpmDrtmReset: BUG! Expected target to be of TPM type, but "
           "it was of type 0x%08X",i_pTpm->getAttr<TARGETING::ATTR_TYPE>());

    errlHndl_t err = nullptr;

    // Send to the TPM
    size_t len = 0;
    err = deviceRead(i_pTpm,
                     nullptr,
                     len,
                     DEVICE_TPM_ADDRESS(TPMDD::TPM_OP_DRTMRESET,
                                        0,
                                        TPM_LOCALITY_4));

    if (nullptr == err)
    {
        /// @todo RTC: 145689 reset the dynamic tpm log
    }

    return err;
}
#endif

} // end TRUSTEDBOOT
