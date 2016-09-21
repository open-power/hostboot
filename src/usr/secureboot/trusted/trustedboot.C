/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedboot.C $                    */
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
#include <ipmi/ipmisensor.H>
#include <config.h>
#include "trustedboot.H"
#include "trustedTypes.H"
#include "trustedbootCmds.H"
#include "trustedbootUtils.H"
#include "tpmLogMgr.H"
#include "base/trustedbootMsg.H"
#include "../settings.H"

namespace TRUSTEDBOOT
{

extern SystemTpms systemTpms;

void getTPMs( std::list<TpmTarget>& o_info )
{
    TRACUCOMP(g_trac_trustedboot,ENTER_MRK"getTPMs()");

    for (size_t idx = 0; idx < MAX_SYSTEM_TPMS; idx ++)
    {
        if (systemTpms.tpm[idx].available && !systemTpms.tpm[idx].failed)
        {

            o_info.push_back(systemTpms.tpm[idx]);
        }
    }

    TRACUCOMP(g_trac_trustedboot,EXIT_MRK"getTPMs() : Size:%d", o_info.size());

}

errlHndl_t getTpmLogDevtreeInfo(TpmTarget & i_target,
                                uint64_t & io_logAddr,
                                size_t & o_allocationSize,
                                uint64_t & o_xscomAddr,
                                uint32_t & o_i2cMasterOffset)
{
    errlHndl_t err = NULL;
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"getTpmLogDevtreeInfo() tgt=0x%X Addr:%lX %lX",
               TARGETING::get_huid(i_target.tpmTarget),
               io_logAddr ,(uint64_t)(i_target.logMgr));

    o_allocationSize = 0;

    if (NULL != i_target.logMgr &&
        i_target.available)
    {
        err = TpmLogMgr_getDevtreeInfo(i_target.logMgr,
                                       io_logAddr,
                                       o_allocationSize,
                                       o_xscomAddr,
                                       o_i2cMasterOffset);
    }
    TRACUCOMP( g_trac_trustedboot,
               EXIT_MRK"getTpmLogDevtreeInfo() Addr:%lX",io_logAddr);
    return err;
}

void setTpmDevtreeInfo(TpmTarget & i_target,
                       uint64_t i_xscomAddr,
                       uint32_t i_i2cMasterOffset)
{
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"setTpmLogDevtreeOffset() tgt=0x%X "
               "Xscom:%lX Master:%X",
               TARGETING::get_huid(i_target.tpmTarget),
               i_xscomAddr, i_i2cMasterOffset);

    if (NULL != i_target.logMgr)
    {
        TpmLogMgr_setTpmDevtreeInfo(i_target.logMgr,
                                    i_xscomAddr, i_i2cMasterOffset);
    }
}

bool enabled()
{
    bool ret = false;
#ifdef CONFIG_TPMDD
    bool foundFunctional = false;

    for (size_t idx = 0; idx < MAX_SYSTEM_TPMS; idx ++)
    {
        if ((!systemTpms.tpm[idx].failed &&
             systemTpms.tpm[idx].available) ||
            !systemTpms.tpm[idx].initAttempted)
        {
            foundFunctional = true;
            break;
        }
    }
    // If we have a functional TPM we are enabled
    ret = foundFunctional;
#endif
    return ret;
}

void* host_update_master_tpm( void *io_pArgs )
{
    errlHndl_t err = NULL;
    bool unlock = false;

    TRACDCOMP( g_trac_trustedboot,
               ENTER_MRK"host_update_master_tpm()" );
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"host_update_master_tpm()");

    do
    {

        TARGETING::TargetService& tS = TARGETING::targetService();

        TARGETING::Target* procTarget = NULL;
        err = tS.queryMasterProcChipTargetHandle( procTarget );

        if (NULL != err)
        {
            break;
        }

        // Now get all TPM's to setup our array
        TARGETING::TargetHandleList tpmList;
        TARGETING::getAllChips(tpmList,
                               TARGETING::TYPE_TPM,
                               true); // ONLY FUNCTIONAL

        // Currently we only support a MAX of two TPMS
        assert(tpmList.size() <= 2, "Too many TPMs found");

        mutex_lock( &(systemTpms.tpm[TPM_MASTER_INDEX].tpmMutex) );
        mutex_lock( &(systemTpms.tpm[TPM_BACKUP_INDEX].tpmMutex) );
        unlock = true;

        systemTpms.tpm[TPM_MASTER_INDEX].role = TPM_PRIMARY;
        systemTpms.tpm[TPM_BACKUP_INDEX].role = TPM_BACKUP;

        if (0 == tpmList.size())
        {
            TRACFCOMP( g_trac_trustedboot,
                       "No TPM Targets found");
            systemTpms.tpm[TPM_MASTER_INDEX].initAttempted = true;
            systemTpms.tpm[TPM_MASTER_INDEX].available = false;
            systemTpms.tpm[TPM_BACKUP_INDEX].initAttempted = true;
            systemTpms.tpm[TPM_BACKUP_INDEX].available = false;
        }
        else
        {
            // Loop through the TPMs and figure out if they are attached
            //  to the master or alternate processor
            TPMDD::tpm_info_t tpmData;
            size_t tpmIdx = TPM_MASTER_INDEX;
            for (size_t tpmNum = 0; tpmNum < tpmList.size(); tpmNum++)
            {
                memset(&tpmData, 0, sizeof(tpmData));
                errlHndl_t readErr = tpmReadAttributes(tpmList[tpmNum],
                                                       tpmData);
                if (NULL != readErr)
                {
                    // We are just looking for configured TPMs here
                    //  so we ignore any errors
                    delete readErr;
                    readErr = NULL;
                }
                else
                {
                    // Is the i2c master of this TPM also the master proc?
                    tpmIdx = (tpmData.i2cTarget == procTarget) ?
                        TPM_MASTER_INDEX : TPM_BACKUP_INDEX;

                    if (NULL != systemTpms.tpm[tpmIdx].tpmTarget)
                    {
                        TRACFCOMP( g_trac_trustedboot,
                                   "Duplicate TPM target found %d",tpmIdx);
                    }
                    else
                    {
                        systemTpms.tpm[tpmIdx].tpmTarget = tpmList[tpmNum];
                        systemTpms.tpm[tpmIdx].available = true;
                    }
                }

            }
        }

        if (!systemTpms.tpm[TPM_MASTER_INDEX].failed &&
            systemTpms.tpm[TPM_MASTER_INDEX].available &&
            NULL != systemTpms.tpm[TPM_MASTER_INDEX].tpmTarget &&
            TPMDD::tpmPresence(systemTpms.tpm[TPM_MASTER_INDEX].tpmTarget))
        {
            // Initialize the TPM, this will mark it as non-functional on fail
            tpmInitialize(systemTpms.tpm[TPM_MASTER_INDEX]);

        }
        else
        {
            // Master TPM doesn't exist in the system
            systemTpms.tpm[TPM_MASTER_INDEX].initAttempted = true;
            systemTpms.tpm[TPM_MASTER_INDEX].available = false;
        }

        // Allocate the TPM log if it hasn't been already
        if (!systemTpms.tpm[TPM_MASTER_INDEX].failed &&
            systemTpms.tpm[TPM_MASTER_INDEX].available &&
            NULL == systemTpms.tpm[TPM_MASTER_INDEX].logMgr)
        {
            systemTpms.tpm[TPM_MASTER_INDEX].logMgr = new TpmLogMgr;
            err = TpmLogMgr_initialize(
                        systemTpms.tpm[TPM_MASTER_INDEX].logMgr);
            if (NULL != err)
            {
                systemTpms.tpm[TPM_MASTER_INDEX].initAttempted = true;
                systemTpms.tpm[TPM_MASTER_INDEX].failed = true;
                break;
            }
        }

        if (systemTpms.tpm[TPM_MASTER_INDEX].failed ||
            !systemTpms.tpm[TPM_MASTER_INDEX].available)
        {

            /// @todo RTC:134913 Switch to backup chip if backup TPM avail

            // Master TPM not available
            TRACFCOMP( g_trac_trustedboot,
                       "Master TPM Existence Fail");

        }

        // Lastly we will check on the backup TPM and see if it is enabled
        //  in the attributes at least
        if (NULL == systemTpms.tpm[TPM_BACKUP_INDEX].tpmTarget)
        {
            TRACUCOMP( g_trac_trustedboot,
                       "host_update_master_tpm() "
                       "Marking backup TPM unavailable "
                       "due to attribute fail");
            systemTpms.tpm[TPM_BACKUP_INDEX].available = false;
            systemTpms.tpm[TPM_BACKUP_INDEX].initAttempted = true;
        }
        else
        {
            TPMDD::tpm_info_t tpmInfo;
            memset(&tpmInfo, 0, sizeof(tpmInfo));
            errlHndl_t tmpErr = TPMDD::tpmReadAttributes(
                                 systemTpms.tpm[TPM_BACKUP_INDEX].tpmTarget,
                                 tpmInfo);
            if (NULL != tmpErr || !tpmInfo.tpmEnabled)
            {
                TRACUCOMP( g_trac_trustedboot,
                           "host_update_master_tpm() "
                           "Marking backup TPM unavailable");
                systemTpms.tpm[TPM_BACKUP_INDEX].available = false;
                systemTpms.tpm[TPM_BACKUP_INDEX].initAttempted = true;
                if (NULL != tmpErr)
                {
                    // Ignore attribute read failure
                    delete tmpErr;
                    tmpErr = NULL;
                }
            }
        }

    } while ( 0 );

    if( unlock )
    {
        mutex_unlock(&(systemTpms.tpm[TPM_MASTER_INDEX].tpmMutex));
        mutex_unlock(&(systemTpms.tpm[TPM_BACKUP_INDEX].tpmMutex));
    }

    // Make sure we are in a state
    //  where we have a functional TPM
    TRUSTEDBOOT::tpmVerifyFunctionalTpmExists();

    if (NULL == err)
    {
        // Start the task to start to handle the message queue/extends
        task_create(&TRUSTEDBOOT::tpmDaemon, NULL);
    }

    if (NULL == err)
    {
        // Log config entries to TPM - needs to be after mutex_unlock
        err = tpmLogConfigEntries(systemTpms.tpm[TPM_MASTER_INDEX]);
    }

    TRACUCOMP( g_trac_trustedboot,
               EXIT_MRK"host_update_master_tpm() - "
               "Master A:%d F:%d I:%d",
               systemTpms.tpm[TPM_MASTER_INDEX].available,
               systemTpms.tpm[TPM_MASTER_INDEX].failed,
               systemTpms.tpm[TPM_MASTER_INDEX].initAttempted);
    TRACUCOMP( g_trac_trustedboot,
               EXIT_MRK"host_update_master_tpm() - "
               "Backup A:%d F:%d I:%d",
               systemTpms.tpm[TPM_BACKUP_INDEX].available,
               systemTpms.tpm[TPM_BACKUP_INDEX].failed,
               systemTpms.tpm[TPM_BACKUP_INDEX].initAttempted);

    TRACDCOMP( g_trac_trustedboot,
               EXIT_MRK"host_update_master_tpm() - %s",
               ((NULL == err) ? "No Error" : "With Error") );
    return err;
}


void tpmInitialize(TRUSTEDBOOT::TpmTarget & io_target)
{
    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmInitialize()" );
    TRACUCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmInitialize() tgt=0x%X",
               TARGETING::get_huid(io_target.tpmTarget));

    do
    {

        // TPM Initialization sequence

        io_target.initAttempted = true;
        io_target.failed = false;

        // TPM_STARTUP
        err = tpmCmdStartup(&io_target);
        if (NULL != err)
        {
            break;
        }

        // TPM_GETCAPABILITY to read FW Version
        err = tpmCmdGetCapFwVersion(&io_target);
        if (NULL != err)
        {
            break;
        }


    } while ( 0 );


    // If the TPM failed we will mark it not functional
    if (NULL != err)
    {
        tpmMarkFailed(&io_target);
        // Log this failure
        errlCommit(err, SECURE_COMP_ID);
    }

    TRACDCOMP( g_trac_trustedboot,
               EXIT_MRK"tpmInitialize()");
}

void tpmReplayLog(TRUSTEDBOOT::TpmTarget & io_target)
{
    TRACUCOMP(g_trac_trustedboot, ENTER_MRK"tpmReplayLog()");
    errlHndl_t err = NULL;
    bool unMarshalError = false;


    // Create EVENT2 structure to be populated by getNextEvent()
    TCG_PCR_EVENT2 l_eventLog;
    // Move past header event to get a pointer to the first event
    // If there are no events besides the header, l_eventHndl = NULL
    const uint8_t* l_eventHndl = TpmLogMgr_getFirstEvent(io_target.logMgr);
    while ( l_eventHndl != NULL )
    {
        // Get next event
        l_eventHndl = TpmLogMgr_getNextEvent(io_target.logMgr,
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
                err = tpmCmdPcrExtend(&io_target,
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
        tpmMarkFailed(&io_target);
        errlCommit(err, SECURE_COMP_ID);
        delete err;
        err = NULL;
    }
}

errlHndl_t tpmLogConfigEntries(TRUSTEDBOOT::TpmTarget & io_target)
{
    TRACUCOMP(g_trac_trustedboot, ENTER_MRK"tpmLogConfigEntries()");

    errlHndl_t l_err = NULL;

    do
    {
        // Create digest buffer and set to largest config entry size.
        uint8_t l_digest[sizeof(uint64_t)];
        memset(l_digest, 0, sizeof(uint64_t));

        // Security switches
        uint64_t l_securitySwitchValue = Singleton<SECUREBOOT::Settings>::
                                                instance().getSecuritySwitch();
        TRACFCOMP(g_trac_trustedboot, "security switch value = 0x%X",
                                l_securitySwitchValue);
        // Extend to TPM - PCR_1
        memcpy(l_digest, &l_securitySwitchValue, sizeof(l_securitySwitchValue));
        l_err = pcrExtend(PCR_1, l_digest, sizeof(l_securitySwitchValue),
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
        TRACDCOMP(g_trac_trustedboot, "PVR of chip = 0x%X", l_pvr);
        // Extend to TPM - PCR_1
        memcpy(l_digest, &l_pvr, sizeof(l_pvr));
        l_err = pcrExtend(PCR_1, l_digest, sizeof(l_pvr),"PVR of Chip");
        if (l_err)
        {
            break;
        }
        memset(l_digest, 0, sizeof(uint64_t));

        // Figure out which node we are running on
        TARGETING::Target* l_masterProc = NULL;
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
            l_err = pcrExtend(l_pcrs[i], l_digest, sizeof(l_nodeid),"Node id");
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
        l_err = pcrExtend(PCR_1, l_digest, sizeof(l_tpmRequired),
                          "Tpm Required");
        if (l_err)
        {
            break;
        }

        // HW Key Hash
        sha2_hash_t l_hw_key_hash;
        SECUREBOOT::getHwHashKeys(l_hw_key_hash);
        l_err = pcrExtend(PCR_1, l_hw_key_hash,
                          sizeof(sha2_hash_t),"HW KEY HASH");
        if (l_err)
        {
            break;
        }

    } while(0);

    return l_err;
}

void pcrExtendSingleTpm(TpmTarget & io_target,
                        TPM_Pcr i_pcr,
                        TPM_Alg_Id i_algId,
                        const uint8_t* i_digest,
                        size_t  i_digestSize,
                        const char* i_logMsg)
{
    errlHndl_t err = NULL;
    TCG_PCR_EVENT2 eventLog;
    bool unlock = false;

    memset(&eventLog, 0, sizeof(eventLog));
    do
    {
        mutex_lock( &io_target.tpmMutex );
        unlock = true;

        // Log the event
        if (io_target.available &&
             !io_target.failed)
        {
            // Fill in TCG_PCR_EVENT2 and add to log
            eventLog = TpmLogMgr_genLogEventPcrExtend(i_pcr,
                                                      i_algId, i_digest,
                                                      i_digestSize,
                                                      TPM_ALG_SHA1, i_digest,
                                                      i_digestSize,
                                                      i_logMsg);
            err = TpmLogMgr_addEvent(io_target.logMgr,&eventLog);
            if (NULL != err)
            {
                break;
            }

            // Perform the requested extension and also force into the
            // SHA1 bank
            err = tpmCmdPcrExtend2Hash(&io_target,
                                       i_pcr,
                                       i_algId,
                                       i_digest,
                                       i_digestSize,
                                       TPM_ALG_SHA1,
                                       i_digest,
                                       i_digestSize);
        }
    } while ( 0 );

    if (NULL != err)
    {
        // We failed to extend to this TPM we can no longer use it
        tpmMarkFailed(&io_target);

        // Log this failure
        errlCommit(err, SECURE_COMP_ID);
    }

    if (unlock)
    {
        mutex_unlock(&io_target.tpmMutex);
    }
    return;
}

void pcrExtendSeparator(TpmTarget & io_target)
{
    errlHndl_t err = NULL;
    TCG_PCR_EVENT2 eventLog;
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
        mutex_lock( &io_target.tpmMutex );
        unlock = true;

        for (TPM_Pcr curPcr = PCR_0; curPcr <= PCR_7;
             curPcr = static_cast<TPM_Pcr>(curPcr + 1))
        {

            // Log the separator
            if (io_target.available &&
                !io_target.failed)
            {
                // Fill in TCG_PCR_EVENT2 and add to log
                eventLog = TpmLogMgr_genLogEventPcrExtend(curPcr,
                                                          TPM_ALG_SHA1,
                                                          sha1_digest,
                                                          sizeof(sha1_digest),
                                                          TPM_ALG_SHA256,
                                                          sha256_digest,
                                                          sizeof(sha256_digest),
                                                          logMsg);
                err = TpmLogMgr_addEvent(io_target.logMgr,&eventLog);
                if (NULL != err)
                {
                    break;
                }

                // Perform the requested extension
                err = tpmCmdPcrExtend2Hash(&io_target,
                                           curPcr,
                                           TPM_ALG_SHA1,
                                           sha1_digest,
                                           sizeof(sha1_digest),
                                           TPM_ALG_SHA256,
                                           sha256_digest,
                                           sizeof(sha256_digest));
                if (NULL != err)
                {
                    break;
                }

            }
        }

    } while ( 0 );

    if (NULL != err)
    {
        // We failed to extend to this TPM we can no longer use it
        tpmMarkFailed(&io_target);

        // Log this failure
        errlCommit(err, SECURE_COMP_ID);
    }

    if (unlock)
    {
        mutex_unlock(&io_target.tpmMutex);
    }
    return;
}

void tpmMarkFailed(TpmTarget * io_target)
{

    TRACFCOMP( g_trac_trustedboot,
               ENTER_MRK"tpmMarkFailed() Marking TPM as failed : "
               "tgt=0x%X",
               TARGETING::get_huid(io_target->tpmTarget));

    io_target->failed = true;
    /// @todo RTC:125287 Add fail marker to TPM log and disable TPM access

}

void tpmVerifyFunctionalTpmExists()
{
    errlHndl_t err = NULL;
    bool foundFunctional = false;

    for (size_t idx = 0; idx < MAX_SYSTEM_TPMS; idx ++)
    {
        if ((!systemTpms.tpm[idx].failed &&
             systemTpms.tpm[idx].available) ||
            !systemTpms.tpm[idx].initAttempted)
        {
            foundFunctional = true;
            break;
        }
    }

    if (!foundFunctional && !systemTpms.failedTpmsPosted)
    {
        systemTpms.failedTpmsPosted = true;
        TRACFCOMP( g_trac_trustedboot,
                   "NO FUNCTIONAL TPM FOUND");

        // Check to ensure jumper indicates we are running secure
        if (false) /// @todo Story 161916 Change to call getJumperState
        //        if (SECUREBOOT::getJumperState())
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
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_TPM_VERIFYFUNCTIONAL,
                                           RC_TPM_NOFUNCTIONALTPM_FAIL,
                                           0, 0,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( SECURE_COMP_NAME );
            uint32_t errPlid = err->plid();

            // Log this failure here
            errlCommit(err, SECURE_COMP_ID);

            if (isTpmRequired())

            {
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
    errlHndl_t err = NULL;

    // Mark as an independent daemon so if it crashes we terminate
    task_detach();

    TRACUCOMP( g_trac_trustedboot, ENTER_MRK "TpmDaemon Thread Start");

    // Register shutdown events with init service.
    //      Done at the "end" of shutdown processing.
    // This will flush any other messages (PCR extends) and terminate task
    INITSERVICE::registerShutdownEvent(systemTpms.msgQ,
                                       TRUSTEDBOOT::MSG_TYPE_SHUTDOWN);

    Message* tb_msg = NULL;
    while (true)
    {
        msg_t* msg = msg_wait(systemTpms.msgQ);

        const MessageType type =
            static_cast<MessageType>(msg->type);
        tb_msg = NULL;

        TRACUCOMP( g_trac_trustedboot, "TpmDaemon Handle CmdType %d",
                   type);

        switch (type)
        {
          case TRUSTEDBOOT::MSG_TYPE_SHUTDOWN:
              {
                  shutdownPending = true;

                  // Un-register message queue from the shutdown
                  INITSERVICE::unregisterShutdownEvent(systemTpms.msgQ);

              }
              break;
          case TRUSTEDBOOT::MSG_TYPE_PCREXTEND:
              {
                  tb_msg = static_cast<TRUSTEDBOOT::Message*>(msg->extra_data);

                  TRUSTEDBOOT::PcrExtendMsgData* msgData =
                      reinterpret_cast<TRUSTEDBOOT::PcrExtendMsgData*>
                      (tb_msg->iv_data);

                  assert(tb_msg->iv_len == sizeof(TRUSTEDBOOT::PcrExtendMsgData)
                         && msgData != NULL, "Invalid PCRExtend Message");

                  for (size_t idx = 0;
                       idx < TRUSTEDBOOT::MAX_SYSTEM_TPMS; idx++)
                  {
                      // Add the event to this TPM,
                      // if an error occurs the TPM will
                      //  be marked as failed and the error log committed
                      TRUSTEDBOOT::pcrExtendSingleTpm(
                                   TRUSTEDBOOT::systemTpms.tpm[idx],
                                   msgData->mPcrIndex,
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

                  for (size_t idx = 0;
                       idx < TRUSTEDBOOT::MAX_SYSTEM_TPMS; idx++)
                  {
                      // Add the separator to this TPM,
                      // if an error occurs the TPM will
                      //  be marked as failed and the error log committed
                      TRUSTEDBOOT::pcrExtendSeparator(
                                   TRUSTEDBOOT::systemTpms.tpm[idx]);
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
        if (NULL != tb_msg)
        {
            tb_msg->response(systemTpms.msgQ);
        }
        else
        {
            // use the HB message type to respond
            int rc = msg_respond(systemTpms.msgQ, msg);
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

                // Log this failure here since we can't reply to caller
                errlCommit(err, SECURE_COMP_ID);

            }
        }

        if (shutdownPending)
        {
            // Exit loop and terminate task
            break;
        }
    }

    TRACUCOMP( g_trac_trustedboot, EXIT_MRK "TpmDaemon Thread Terminate");
    return NULL;
}

bool isTpmRequired()
{

    bool retVal = false;
    TARGETING::Target* pTopLevel = NULL;

    (void)TARGETING::targetService().getTopLevelTarget(pTopLevel);
    assert(pTopLevel != NULL, "Unable to get top level target");

    TARGETING::ATTR_TPM_REQUIRED_type tpmRequired =
        pTopLevel->getAttr<TARGETING::ATTR_TPM_REQUIRED>();

    // TPM Required is on in the attributes, now let's check the BMC sensor
    if (tpmRequired)
    {
#ifdef CONFIG_BMC_IPMI
        uint32_t sensorNum = TARGETING::UTIL::getSensorNumber(pTopLevel,
                                        TARGETING::SENSOR_NAME_TPM_REQUIRED);
        // VALID IPMI sensors are 0-0xFE
        if (TARGETING::UTIL::INVALID_IPMI_SENSOR != sensorNum)
        {
            // Check if TPM is required by BMC
            SENSOR::getSensorReadingData tpmRequiredData;
            SENSOR::SensorBase tpmRequired(TARGETING::SENSOR_NAME_TPM_REQUIRED,
                                           pTopLevel);
            errlHndl_t err = tpmRequired.readSensorData(tpmRequiredData);
            if (NULL == err)
            {
                // 0x02 == Asserted bit (TPM is required)
                if ((tpmRequiredData.event_status &
                     (1 << SENSOR::ASSERTED)) ==
                    (1 << SENSOR::ASSERTED))
                {
                    retVal = true;
                }
            }
            else
            {
                // error reading sensor, assume TPM is required
                TRACFCOMP( g_trac_trustedboot,
                           "Unable to read Tpm Required Sensor : rc = 0x%04X",
                           err->reasonCode());
                delete err;
                err = NULL;
                retVal = true;
            }
        }
        else
        {
            // Sensor not supported so assume TPM required
            retVal = true;
        }
#else
        // IPMI support not there, assume true
        retVal = true;
#endif
    }


    TRACFCOMP( g_trac_trustedboot,
               "Tpm Required: %s",(retVal ? "Yes" : "No"));

    return retVal;
}


} // end TRUSTEDBOOT
