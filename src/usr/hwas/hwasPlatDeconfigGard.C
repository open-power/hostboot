/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hwasPlatDeconfigGard.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
/* [+] Google Inc.                                                        */
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
 *  @file hwasPlatDeconfigGard.C
 *
 *  @brief Platform specific deconfigGard functions
 */

#include <hwas/common/hwas.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwasCallout.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/hwasPlat.H>

#include <devicefw/driverif.H>
#include <initservice/taskargs.H>
#include <vpd/mvpdenums.H>
#include <stdio.h>
#include <sys/mm.h>
#include <initservice/istepdispatcherif.H>
#include <initservice/initserviceif.H>

#include <pnor/pnorif.H>
#include <pm/pm_common.H>                  // HBPM::resetPMComplex

#include <targeting/targplatutil.H> //assertGetToplevelTarget

#include <errl/errlreasoncodes.H> // ERRL_UDT_NOFORMAT

#ifdef __HOSTBOOT_RUNTIME
#include <runtime/interface.h>             // g_hostInterfaces
#include <runtime/hbrt_utilities.H>        // createGenericFspMsg
#include <util/runtime/rt_fwreq_helper.H>  // firmware_request_helper
#include <errl/errludtarget.H>

#endif

#ifdef CONFIG_TPMDD
#include <../usr/secureboot/trusted/trustedbootUtils.H>
#endif

namespace HWAS
{

using namespace HWAS::COMMON;
using namespace TARGETING;

const uint32_t EMPTY_GARD_RECORDID = 0xFFFFFFFF;

#if !defined(__HOSTBOOT_RUNTIME) || defined(CONFIG_FILE_XFER_VIA_PLDM)
/**
 * @brief Guard PNOR section info, obtained once for efficiency
 */
static PNOR::SectionInfo_t g_GardSectionInfo;

/**
 * @brief Flag indicating if getGardSectionInfo() was called previously
 */
static bool getGardSectionInfoCalled;
#endif

//******************************************************************************
// RUNTIME/NON-RUNTIME/HOSTBOOT/NON-HOSTBOOT methods
//******************************************************************************

void _flush(void *i_addr);
const TARGETING::Target * getFRU_Target(const TARGETING::Target * i_target);
errlHndl_t _GardRecordIdSetup(void *&io_platDeconfigGard);

errlHndl_t DeconfigGard::platLogEvent(
    const Target * const i_pTarget,
    const GardEvent i_eventType)
{
    errlHndl_t l_pErr = NULL;
    HWAS_DBG("LogEvent %d", i_eventType);

    return l_pErr;
}
/* Hostboot plat implementation of this function does not need to
 * re-log the error. Currently, it is handled by FSP since it's a
 * FSP-based-system requirement.
 */
errlHndl_t DeconfigGard::platReLogGardError (GardRecord &i_gardRecord)
{
    errlHndl_t l_pErr = NULL;
    HWAS_INF("Error Log ID: 0x%.8X", i_gardRecord.iv_errlogEid);
    return l_pErr;
}

bool isDupGardRecord(const GARD_ErrorType i_existingGardType,
                     const GARD_ErrorType i_incomingGardType)
{
    // special case for Deconfig GARDs
    // if the pre-existing record for the garded target is not a Deconfig Gard
    // we do NOT want to mark the incoming Deconfig Gard record as a duplicate.
    //   - i.e. there already exists a GARD_Unrecoverable for this target and then
    //     we receive an incoming gard with GARD_Reconfig
    // Instead we want to make a new Deconfig Gard record to indicate the
    // target is deconfigured. This is for HB to track which targets are avalible
    // for resource recovery on eBMC systems during reconfig loops
    bool l_existing_GARD_isDeconfig = isDeconfigGard(i_existingGardType);
    bool l_incoming_GARD_isDeconfig = isDeconfigGard(i_incomingGardType);

    HWAS_DBG("l_incoming_GARD_isDeconfig = %s", l_incoming_GARD_isDeconfig ? "TRUE" : "FALSE");
    HWAS_DBG("l_existing_GARD_isDeconfig = %s", l_existing_GARD_isDeconfig ? "TRUE" : "FALSE");
    HWAS_DBG("l_incoming_GARD_isDeconfig XOR l_existing_GARD_isDeconfig = %s",
              l_incoming_GARD_isDeconfig^l_existing_GARD_isDeconfig ? "TRUE" : "FALSE");
    HWAS_DBG("!(l_incoming_GARD_isDeconfig XOR l_existing_GARD_isDeconfig) = %s",
              !(l_incoming_GARD_isDeconfig^l_existing_GARD_isDeconfig) ? "TRUE" : "FALSE");

    //For FSP systems, treat any incoming gards with the same l_targetId as an existing gard as duplicates
    //For eBMC sytems, if both are a Deconfig Gard type or neither are Deconfig Gard type, then treat as duplicate
    return (INITSERVICE::spBaseServicesEnabled() || !(l_incoming_GARD_isDeconfig^l_existing_GARD_isDeconfig));
}


#ifndef __HOSTBOOT_RUNTIME

errlHndl_t DeconfigGard::platClearGardRecords(
    const Target * const i_pTarget,
    const bool i_clearOnlyDeconfig)
{
    errlHndl_t l_pErr = nullptr;
    char * tmp_str = nullptr;
    bool l_clearingAll = false;

    // For ebmc systems only,
    // if the gard we want to clear is something other than:
    //   GARD_Reconfig
    //   GARD_Sticky_deconfig
    // then we want to clear the original gard and any Deconfig GARD
    // that goes with it
    // otherwise, if it IS GARD_Sticky_deconfig or GARD_Reconfig,
    // just clear the matching deconfig record, leaving the orig
    // gard untouched
    bool only_clear_deconfig = !INITSERVICE::spBaseServicesEnabled() && i_clearOnlyDeconfig;

    EntityPath l_targetId;
    if (!i_pTarget)
    {
        HWAS_INF("platClearGardRecords: Clear all %sGARD Records",
                 only_clear_deconfig ? "Deconfig " : "");
        l_clearingAll = true;
    }
    else
    {
        l_targetId = i_pTarget->getAttr<ATTR_PHYS_PATH>();
        tmp_str = l_targetId.toString();
        HWAS_INF("platClearGardRecords: Clear %sGARD Record for %.8X %s",
            only_clear_deconfig ? "Deconfig " : "",
            get_huid(i_pTarget), tmp_str);
        free(tmp_str);
        tmp_str = nullptr;
    }

    HWAS_MUTEX_LOCK(iv_mutex);
    l_pErr = _GardRecordIdSetup(iv_platDeconfigGard);
    if (!l_pErr && iv_platDeconfigGard)
    {
        uint32_t l_gardRecordsCleared = 0;
        HBDeconfigGard *l_hbDeconfigGard =
                (HBDeconfigGard *)iv_platDeconfigGard;
        DeconfigGard::GardRecord * l_pGardRecords =
                (DeconfigGard::GardRecord *)l_hbDeconfigGard->iv_pGardRecords;
        const uint32_t l_maxGardRecords = l_hbDeconfigGard->iv_maxGardRecords;
        HWAS_INF("platClearGardRecords l_maxGardRecords=0x%X", l_maxGardRecords);
        for (uint32_t i = 0; i < l_maxGardRecords; i++)
        {
            if (l_pGardRecords[i].iv_recordId != EMPTY_GARD_RECORDID)
            {
                HWAS_INF("platClearGardRecords: Non-EMPTY i=0x%X iv_recordId=0x%X",
                    i, l_pGardRecords[i].iv_recordId);
                // specific or all
                if (!l_clearingAll)
                {
                    // if specific, check if we have a potential match
                    if (l_pGardRecords[i].iv_targetId == l_targetId)
                    {
                        // if we only want to clear deconfig records and the gard we found is
                        // not a deconfig record, continue to the next record
                        if (only_clear_deconfig && !isDeconfigGard(l_pGardRecords[i].iv_errorType))
                        {
                            continue;
                        }

                        // otherwise clear the record we found
                        HWAS_INF("platClearGardRecords: Clearing %sGARD Record for %.8X",
                                  isDeconfigGard(l_pGardRecords[i].iv_errorType) ? "Deconfig " : "",
                                  get_huid(i_pTarget));
                        l_pGardRecords[i].iv_recordId = EMPTY_GARD_RECORDID;
                        _flush(&l_pGardRecords[i]);
                        l_gardRecordsCleared++;

                        if (INITSERVICE::spBaseServicesEnabled())
                        {
                            // on FSP systems there can only be 1 GARD record per target
                            break;
                        }
                    }
                }
                else // Clear all records
                {
                    // if we only want to clear deconfig records and the gard we found is
                    // not a deconfig record, continue to the next record
                    if (only_clear_deconfig && !isDeconfigGard(l_pGardRecords[i].iv_errorType))
                    {
                        continue;
                    }

                    l_pGardRecords[i].iv_recordId = EMPTY_GARD_RECORDID;
                    _flush(&l_pGardRecords[i]);
                    l_gardRecordsCleared++;
                }
            }
        } // for

        HWAS_INF("GARD Records Cleared: %d", l_gardRecordsCleared);

        if (l_clearingAll)
        {
            // if clearing ALL reset MEMORY and BINARY to CURRENT_GARD_VERSION_LAYOUT
            // if we get here we've already cleared ALL records, so reset MEMORY version
            // on chance we fail to update BINARY version header below, next time we boot
            // it will sync up, next cycle we will handle the OLD format and proceed on
            // to clear ALL and hope things go better
            l_hbDeconfigGard->iv_GardVersion = HWAS::DeconfigGard::CURRENT_GARD_VERSION_LAYOUT;
            #ifdef __HOSTBOOT_RUNTIME
            // Nothing today, may in future.
            #else
            PNOR::SectionInfo_t l_section;
            l_pErr = getGardSectionInfo(l_section);
            if (l_pErr)
            {
                HWAS_ERR("platClearGardRecords: PROBLEM getGardSectionInfo");
                errlCommit(l_pErr, HWAS_COMP_ID);
            }
            else if (l_section.size != 0)
            {
                DeconfigGard::GardRecordsBinary *l_pGardRecordsBinary =
                    reinterpret_cast<DeconfigGard::GardRecordsBinary *> (l_section.vaddr);
                l_pGardRecordsBinary->iv_version = HWAS::DeconfigGard::CURRENT_GARD_VERSION_LAYOUT;
                // _flush the iv_version
                _flush(reinterpret_cast<void *>(&(l_pGardRecordsBinary->iv_version)));
                HWAS_INF("platClearGardRecords: Clearing ALL Gard Records BINARY RESET "
                         "to CURRENT_GARD_VERSION_LAYOUT l_pGardRecordsBinary->iv_version=0x%X",
                         l_pGardRecordsBinary->iv_version);

                HWAS_INF("platClearGardRecords: Clearing ALL Gard Records MEMORY RESET to "
                         "CURRENT_GARD_VERSION_LAYOUT l_hbDeconfigGard->iv_GardVersion=0x%X",
                         l_hbDeconfigGard->iv_GardVersion);
            }
            else
            {
                HWAS_INF("platClearGardRecords: PROBLEM in clearing ALL Gard Records and "
                         "resetting GardRecordsBinary to CURRENT_GARD_VERSION_LAYOUT");
                /*@
                 * @errortype
                 * @severity         ERRL_SEV_UNKNOWN
                 * @moduleid         HWAS::MOD_PLAT_DECONFIG_GARD
                 * @reasoncode       HWAS::RC_BAD_CLEAR_ALL_RESET_VERSION
                 * @userdata1        none
                 * @userdata2        none
                 * @devdesc          Problem clearing and reset of version
                 * @custdesc         An error occurred during the IPL of the system
                 */
                l_pErr= new ErrlEntry(ERRL_SEV_UNKNOWN,
                                      HWAS::MOD_PLAT_DECONFIG_GARD,
                                      HWAS::RC_BAD_CLEAR_ALL_RESET_VERSION,
                                      0,
                                      0,
                                      ErrlEntry::ADD_SW_CALLOUT);
                l_pErr->collectTrace("HWAS_I");
                errlCommit(l_pErr, HWAS_COMP_ID);
            }
            #endif
        }
    }

    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}

errlHndl_t DeconfigGard::platGetGardRecords(
        const Target * const i_pTarget,
        GardRecords_t &o_records)
{
    errlHndl_t l_pErr = NULL;
    o_records.clear();

    EntityPath l_targetId;
    if (!i_pTarget)
    {
        HWAS_INF("Get all GARD Records");
    }
    else
    {
        l_targetId = i_pTarget->getAttr<ATTR_PHYS_PATH>();
        HWAS_INF("platGetGardRecords: Working with HUID %.8X",
            get_huid(i_pTarget));
    }

    HWAS_MUTEX_LOCK(iv_mutex);
    l_pErr = _GardRecordIdSetup(iv_platDeconfigGard);
    if (!l_pErr && iv_platDeconfigGard)
    {
        HBDeconfigGard *l_hbDeconfigGard =
                (HBDeconfigGard *)iv_platDeconfigGard;
        DeconfigGard::GardRecord * l_pGardRecords =
                (DeconfigGard::GardRecord *)l_hbDeconfigGard->iv_pGardRecords;
        const uint32_t l_maxGardRecords = l_hbDeconfigGard->iv_maxGardRecords;
        for (uint32_t i = 0; i < l_maxGardRecords; i++)
        {
            if (l_pGardRecords[i].iv_recordId != EMPTY_GARD_RECORDID)
            {
                // specific or all
                if (i_pTarget)
                {
                    // if we have a match
                    if (l_pGardRecords[i].iv_targetId == l_targetId)
                    {
                        HWAS_INF("platGetGardRecords: Getting GARD Record for %.8X",
                                get_huid(i_pTarget));
                        o_records.push_back(l_pGardRecords[i]);

                        if (INITSERVICE::spBaseServicesEnabled())
                        {
                            // on FSP systems there can only be 1 GARD record per target
                            break;
                        }
                    }
                }
                else // get all records
                {
                    o_records.push_back(l_pGardRecords[i]);
                    HWAS_INF("platGetGardRecords: pushing back for all records (%.8X)",
                             get_huid(targetService().toTarget(l_pGardRecords[i].iv_targetId)));
                }
            }
        } // for
    }

    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}
#endif //#ifndef __HOSTBOOT_RUNTIME

errlHndl_t DeconfigGard::platCreateGardRecord(
        const Target * const i_pTarget,
        const uint32_t i_errlEid,
        const GARD_ErrorType i_errorType)
{
    HWAS_INF("Creating %sGARD Record for %.8X, errl 0x%X",
              isDeconfigGard(i_errorType) ? "Deconfig ": "",
              get_huid(i_pTarget), i_errlEid);
    errlHndl_t l_pErr = NULL;

    HWAS_MUTEX_LOCK(iv_mutex);

    do
    {
        const uint8_t lDeconfigGardable =
                i_pTarget->getAttr<ATTR_DECONFIG_GARDABLE>();
        const uint8_t lPresent =
                i_pTarget->getAttr<ATTR_HWAS_STATE>().present;
        if (!lDeconfigGardable || !lPresent)
        {
            // Target is not GARDable. Commit an error
            HWAS_ERR("Target not GARDable");

            /*@
             * @errortype
             * @moduleid     HWAS::MOD_PLAT_DECONFIG_GARD
             * @reasoncode   HWAS::RC_TARGET_NOT_GARDABLE
             * @devdesc      Attempt to create a GARD Record for a target that
             *               is not GARDable
             *               (not DECONFIG_GARDABLE or not present)
             * @custdesc     A problem occurred during the IPL of the system.
             *               Attempt to create a deconfiguration record for a
             *               target that is not deconfigurable or not present.
             * @userdata1    HUID of input target // GARD errlog EID
             * @userdata2    ATTR_DECONFIG_GARDABLE // ATTR_HWAS_STATE.present
             */
            const uint64_t userdata1 =
                (static_cast<uint64_t>(get_huid(i_pTarget)) << 32) | i_errlEid;
            const uint64_t userdata2 =
                (static_cast<uint64_t>(lDeconfigGardable) << 32) | lPresent;
            const bool hbSwError = true;
            l_pErr = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HWAS::MOD_PLAT_DECONFIG_GARD,
                HWAS::RC_TARGET_NOT_GARDABLE,
                userdata1, userdata2, hbSwError);
            break;
        }

        Target* pSys = UTIL::assertGetToplevelTarget();
        const TARGETING::Target * l_fru_target = getFRU_Target(i_pTarget);
        TARGETING::ATTR_PART_NUMBER_type l_PN = {'0'};
        TARGETING::ATTR_SERIAL_NUMBER_type l_SN = {'0'};

        // We do NOT have the attributes defined on FSP, so we will NOT perform
        // attribute handling on FSP systems.
        //
        // We also are conditionally compiling the versioning support enablement.
        //
        if (!INITSERVICE::spBaseServicesEnabled())
        {
            if (l_fru_target)
            {
                if (!(l_fru_target->tryGetAttr<TARGETING::ATTR_PART_NUMBER>(l_PN)))
                {
                    HWAS_INF("platCreateGardRecord: Unable to get PART_NUMBER target %.8X",
                        get_huid(l_fru_target));
                    memcpy(l_PN, "NONE", 4);
                    /*@
                     * @errortype
                     * @moduleid   MOD_PLAT_DECONFIG_GARD
                     * @reasoncode RC_NO_FRU_PART_NUM
                     * @devdesc    No PART NUMBER attribute found on the requested FRU target
                     * @userdata1  HUID of original input target // GARD errlog EID
                     * @userdata2  HUID of FRU target
                     * @custdesc   An unexpected error occurred during IPL
                     */
                    const uint64_t userdata1 =
                        (static_cast<uint64_t> (get_huid(i_pTarget)) << 32) |
                        i_errlEid;
                    const uint64_t userdata2 =
                        static_cast<uint64_t>(get_huid(l_fru_target));

                    l_pErr = hwasError(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        MOD_PLAT_DECONFIG_GARD,
                        RC_NO_FRU_PART_NUM,userdata1,userdata2);
                    errlCommit(l_pErr, HWAS_COMP_ID);
                }

                if (!(l_fru_target->tryGetAttr<TARGETING::ATTR_SERIAL_NUMBER>(l_SN)))
                {
                    HWAS_INF("platCreateGardRecord: Unable to get SERIAL_NUMBER target %.8X",
                        get_huid(l_fru_target));
                    memcpy(l_SN, "NONE", 4);
                    /*@
                     * @errortype
                     * @moduleid   MOD_PLAT_DECONFIG_GARD
                     * @reasoncode RC_NO_FRU_SERIAL_NUM
                     * @devdesc    No SERIAL NUMBER attribute found on the requested FRU target
                     * @userdata1  HUID of original input target // GARD errlog EID
                     * @userdata2  HUID of FRU target
                     * @custdesc   An unexpected error occurred during IPL
                     */
                    const uint64_t userdata1 =
                        (static_cast<uint64_t> (get_huid(i_pTarget)) << 32) |
                        i_errlEid;
                    const uint64_t userdata2 =
                        static_cast<uint64_t> (get_huid(l_fru_target));
                    l_pErr = hwasError(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        MOD_PLAT_DECONFIG_GARD,
                        RC_NO_FRU_SERIAL_NUM,userdata1,userdata2);
                    errlCommit(l_pErr, HWAS_COMP_ID);
                }
            }
            else
            {
                HWAS_INF("platCreateGardRecord: Unable to find a FRU target for PN/SN "
                         "populating with NONE");
                /*@
                 * @errortype
                 * @moduleid   MOD_PLAT_DECONFIG_GARD
                 * @reasoncode RC_NO_FRU_TARGET
                 * @devdesc    No FRU parent target found for PN or SN
                 * @userdata1  HUID of original input target // GARD errlog EID
                 * @custdesc   An unexpected error occurred during IPL
                 */
                const uint64_t userdata1 =
                        (static_cast<uint64_t> (get_huid(i_pTarget)) << 32) |
                        i_errlEid;
                l_pErr = hwasError(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    MOD_PLAT_DECONFIG_GARD,
                    HWAS::RC_NO_FRU_TARGET,userdata1,0);
                errlCommit(l_pErr, HWAS_COMP_ID);
                // at least stuff some default values
                memcpy(l_PN, "NONE", 4);
                memcpy(l_SN, "NONE", 4);
            }
        } // end not FSP

        // check for system CDM Policy
        const ATTR_CDM_POLICIES_type l_sys_policy =
                pSys->getAttr<ATTR_CDM_POLICIES>();
        if (l_sys_policy & CDM_POLICIES_MANUFACTURING_DISABLED)
        {
            // manufacturing records are disabled
            //  - don't process
            HWAS_INF("Manufacturing policy: disabled - skipping GARD Record create");
            break;
        }

        if ((l_sys_policy & CDM_POLICIES_PREDICTIVE_DISABLED) &&
            (i_errorType == GARD_Predictive))
        {
            // predictive records are disabled AND gard record is predictive
            //  - don't process
            HWAS_INF("Predictive policy: disabled - skipping GARD Record create");
            break;
        }

        l_pErr = _GardRecordIdSetup(iv_platDeconfigGard);
        if (l_pErr || !iv_platDeconfigGard)
        {
            break;
        }

        // Find an empty GARD Record slot
        //  AND check to make sure we don't have a GARD record already
        EntityPath l_targetId = i_pTarget->getAttr<ATTR_PHYS_PATH>();
        GardRecord * l_pRecord = NULL;
        bool l_duplicate = false;
        HBDeconfigGard *l_hbDeconfigGard =
                (HBDeconfigGard *)iv_platDeconfigGard;
        DeconfigGard::GardRecord *l_pGardRecords =
                (DeconfigGard::GardRecord *)l_hbDeconfigGard->iv_pGardRecords;
        const uint32_t l_maxGardRecords = l_hbDeconfigGard->iv_maxGardRecords;
        for (uint32_t i = 0; i < l_maxGardRecords; i++)
        {
            // found an empty guard record
            if (l_pGardRecords[i].iv_recordId == EMPTY_GARD_RECORDID)
            {
                if (!l_pRecord)
                {
                    // if l_pRecord is not set, save the first empty location we find
                    l_pRecord = &(l_pGardRecords[i]);
                }
            }
            // found a non-empty gard record, check if the targets match
            else if (l_pGardRecords[i].iv_targetId == l_targetId)
            {
                // will return true for FSP systems since the targets are the same
                // Special treatment for BMC systems to handle both Persistent and
                // Deconfig Gard Records
                if (isDupGardRecord(l_pGardRecords[i].iv_errorType, i_errorType))
                {
                    l_duplicate = true;
                    l_pRecord = &(l_pGardRecords[i]);
                    HWAS_INF("Duplicate GARD Record from error 0x%X",
                             l_pGardRecords[i].iv_errlogEid);
                    break;
                }
                // else: we could still potentially have a new incoming gard
                // or deconfig record, keep looping
            }
        } // for

        if (l_duplicate)
        {
            // there's already a GARD or Deconfig record for this target

            // for FSP systems
            if(INITSERVICE::spBaseServicesEnabled())
            {
                if (l_pRecord->iv_errorType == GARD_User_Manual)
                {
                    HWAS_INF("Duplicate is GARD_User_Manual - overwriting");
                    l_pRecord->iv_errlogEid = i_errlEid;
                    l_pRecord->iv_errorType = i_errorType;
                    _flush((void *)l_pRecord);
                }
            }
            else // for eBMC systems
            {
                switch(l_pRecord->iv_errorType)
                {
                    case GARD_User_Manual:
                        // if this GARD record was a manual gard - overwrite
                        // with this new one
                        HWAS_INF("Duplicate existing Gard is GARD_User_Manual - overwriting");
                        l_pRecord->iv_errlogEid = i_errlEid;
                        l_pRecord->iv_errorType = i_errorType;
                        _flush((void *)l_pRecord);
                        break;
                    case GARD_Reconfig:
                        // if this GARD record is a GARD_Reconfig
                        // and the incoming Gard is a Sticky Deconfig
                        if (i_errorType == GARD_Sticky_deconfig)
                        {
                            // update existing Gard to Sticky Deconfig
                            HWAS_INF("Duplicate existing Deconfig Gard is GARD_Reconfig - "
                                     "promoting to incoming GARD_Sticky_deconfig");
                            l_pRecord->iv_errlogEid = i_errlEid;
                            l_pRecord->iv_errorType = i_errorType;
                            _flush((void *)l_pRecord);
                        }
                        // if the incoming Gard is a Reconfig Gard
                        else if(i_errorType == GARD_Reconfig)
                        {
                            // don't update the existing gard record since
                            // we already have a Gard of the same error level
                            HWAS_INF("Duplicate existing and incoming Deconfig Gard records are both GARD_Reconfig - "
                                     "keeping existing Deconfig Gard record");
                        }
                        break;
                    case GARD_Sticky_deconfig:
                        // if this GARD record is a GARD_Sticky_deconfig
                        // and the incoming Gard is either a GARD_Reconfig or a Sticky Deconfig
                        if (isDeconfigGard(i_errorType))
                        {
                            // don't update the existing gard record
                            HWAS_INF("Duplicate existing Deconfig Gard is GARD_Sticky_deconfig - "
                                     "keeping existing Deconfig Gard record");
                        }
                        break;
                    case GARD_NULL:
                    case GARD_Unrecoverable:
                    case GARD_Fatal:
                    case GARD_Predictive:
                    case GARD_Power:
                    case GARD_PHYP:
                    case GARD_Void:
                        HWAS_INF("No Duplication rule for existing Gard type - "
                                 "keeping existing Deconfig Gard record");
                }
            }
            // either way, return success
            break;
        }

        if (!l_pRecord)
        {
            HWAS_ERR("GARD Record Repository full");

            // TODO RTC 96397
            // Hostboot will only write GARD Records to PNOR when it is the
            // gardRecordMaster. An error will be logged if GARD Record storage
            // exceeds 90% and the GARD Record will not be written if full. The
            // error will have a new procedure callout requesting that the
            // machine be serviced. Right now, this error log has no callouts.

            /*@
             * @errortype
             * @moduleid     HWAS::MOD_PLAT_DECONFIG_GARD
             * @reasoncode   HWAS::RC_GARD_REPOSITORY_FULL
             * @devdesc      Attempt to create a GARD Record and the GARD
             *               Repository is full
             * @custdesc     A problem occurred during the IPL of the system.
             *               Attempt to create a deconfiguration record for a
             *               target, but the deconfiguration repository is full.
             * @userdata1    HUID of input target // GARD errlog EID
             */
            const uint64_t userdata1 =
                (static_cast<uint64_t> (get_huid(i_pTarget)) << 32) |
                i_errlEid;
            l_pErr = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HWAS::MOD_PLAT_DECONFIG_GARD,
                HWAS::RC_GARD_REPOSITORY_FULL,
                userdata1);
            break;
        }

        HWAS_INF("platCreateGardRecord: iv_GardVersion=0x%X", l_hbDeconfigGard->iv_GardVersion);
        if (l_hbDeconfigGard->iv_GardVersion != HWAS::DeconfigGard::CURRENT_GARD_VERSION_LAYOUT)
        {
            // do something in the future
            HWAS_ERR("platCreateGardRecord: WRONG VERSION, skipping GARD CREATION, "
                     "INVESTIGATE l_hbDeconfigGard->iv_GardVersion=0x%X",
                     l_hbDeconfigGard->iv_GardVersion);
            /*@
             * @errortype
             * @moduleid   MOD_PLAT_DECONFIG_GARD
             * @reasoncode RC_NOT_CURRENT_GARD_VERSION
             * @devdesc    Not the CURRENT GARD VERSION LAYOUT, NEED INVESTIGATION
             * @userdata1  GARD errlog EID
             * @custdesc   An unexpected error occurred during IPL
             */
            const uint64_t userdata1 =
                static_cast<uint64_t>(i_errlEid);

            l_pErr = hwasError(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                MOD_PLAT_DECONFIG_GARD,
                HWAS::RC_NOT_CURRENT_GARD_VERSION,userdata1,0);
            errlCommit(l_pErr, HWAS_COMP_ID);
        }
        else
        {
            l_pRecord->iv_recordId = l_hbDeconfigGard->iv_nextGardRecordId++;
            l_pRecord->iv_targetId = l_targetId;
            l_pRecord->iv_errlogEid = i_errlEid;
            l_pRecord->iv_errorType = i_errorType;


            if (!INITSERVICE::spBaseServicesEnabled())
            {
                TARGETING::TYPE l_type = l_fru_target->getAttr<TARGETING::ATTR_TYPE>();
                if (TARGETING::UTIL::assertGetToplevelTarget()->getAttr<TARGETING::ATTR_USE_11S_SPD>())
                {
                    //Use Default Type for 11S VPD
                    l_type = TYPE_NA;
                }

                switch (l_type)
                {
                    // RTC 254396 - Support pluggable ISDIMMs
                    case TARGETING::TYPE_DIMM:
                        memcpy(l_pRecord->uniqueId.isddimmDDR4.serialNum, l_SN,
                            sizeof(l_pRecord->uniqueId.isddimmDDR4.serialNum));
                        memcpy(l_pRecord->uniqueId.isddimmDDR4.partNum, l_PN,
                            sizeof(l_pRecord->uniqueId.isddimmDDR4.partNum));
                        HWAS_INF("platCreateGardRecord: SN/PN isddimmDDR4 "
                                 "sizeof(l_pRecord->uniqueId.isddimmDDR4.serialNum)=0x%X "
                                 "sizeof(l_pRecord->uniqueId.isddimmDDR4.partNum)=0x%X",
                                 sizeof(l_pRecord->uniqueId.isddimmDDR4.serialNum),
                                 sizeof(l_pRecord->uniqueId.isddimmDDR4.partNum));
                        break;
                    default:
                        memcpy(l_pRecord->uniqueId.ibm11S.serialNum, l_SN,
                            sizeof(l_pRecord->uniqueId.ibm11S.serialNum));
                        memcpy(l_pRecord->uniqueId.ibm11S.partNum, l_PN,
                            sizeof(l_pRecord->uniqueId.ibm11S.partNum));
                        HWAS_INF("platCreateGardRecord: SN/PN ibm11S "
                                 "sizeof(l_pRecord->uniqueId.ibm11S.serialNum)=0x%X "
                                 "sizeof(l_pRecord->uniqueId.ibm11S.partNum)=0x%X",
                                 sizeof(l_pRecord->uniqueId.ibm11S.serialNum),
                                 sizeof(l_pRecord->uniqueId.ibm11S.partNum));
                        break;
                }
            }

            HWAS_INF_BIN("platCreateGardRecord: Pre-CREATION (hex dump follows) l_pRecord",
                l_pRecord, sizeof(DeconfigGard::GardRecord));
        } // end versioning translation

        _flush((void *)l_pRecord);

        // We wrote a new gard record, we need to make sure to increment the
        // reboot count so we can reconfigure and attempt to IPL
        // Call setNewGardRecord in initservice.
        #ifndef __HOSTBOOT_RUNTIME
        #ifdef CONFIG_PLDM
        HWAS_INF("platCreateGardRecord: New gard record committed, call INITSERVICE "
            "::setNewGardRecord()");
        INITSERVICE::setNewGardRecord();
        #endif
        #endif
    }
    while (0);

    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}


//******************************************************************************
errlHndl_t _GardRecordIdSetup( void *&io_platDeconfigGard)
{
    errlHndl_t l_pErr = nullptr;

    do
    {
        // if this is NOT the first time thru here, we're done
        if (io_platDeconfigGard != NULL)
        {
            break;
        }

#if defined(__HOSTBOOT_RUNTIME) && !defined(CONFIG_FILE_XFER_VIA_PLDM)
        HWAS_INF("_GardRecordIdSetup: No gard support at runtime except VIA PLDM FILE XFER");
        //falsify some data for compilations
        PNOR::SectionInfo_t l_section;
        l_section.size = 0x1000;
        l_section.vaddr = reinterpret_cast<uint64_t>(malloc(0x1000));
        break;
#else
        // Get the PNOR Guard information
        PNOR::SectionInfo_t l_section;
        l_pErr = getGardSectionInfo(l_section);
        if (l_pErr)
        {
            HWAS_ERR("_GardRecordIdSetup: getGardSectionInfo failed!!!");
            // no support for GARD in this configuration.
            break;
        }
        // Check if guard section exists, as certain configs ignore the above
        // error (e.g. golden side has no GARD section)
        if (l_section.size == 0)
        {
            HWAS_ERR("_GardRecordIdSetup: No guard section skipping function");
            break;
        }

#endif

        // allocate our memory and set things up
        io_platDeconfigGard = malloc(sizeof(HBDeconfigGard));
        HBDeconfigGard *l_hbDeconfigGard =
                (HBDeconfigGard *)io_platDeconfigGard;
        DeconfigGard::GardRecordsBinary *l_pGardRecordsBinary =
            reinterpret_cast<DeconfigGard::GardRecordsBinary *> (l_section.vaddr);

        l_hbDeconfigGard->iv_pGardRecords =
            reinterpret_cast<DeconfigGard::GardRecord *> (&l_pGardRecordsBinary->iv_gardRecords);
        HWAS_INF("_GardRecordIdSetup: PNOR vaddr=%p size=%d GardRecord size=0x%X",
            l_section.vaddr, l_section.size, sizeof(DeconfigGard::GardRecord));

        l_hbDeconfigGard->iv_maxGardRecords = l_section.size /
                sizeof(DeconfigGard::GardRecord);
        l_hbDeconfigGard->iv_nextGardRecordId = 0;

        // Figure out the next GARD Record ID to use
        uint32_t l_numGardRecords = 0;
        const uint32_t l_maxGardRecords = l_hbDeconfigGard->iv_maxGardRecords;
        DeconfigGard::GardRecord *l_pGardRecords =
                (DeconfigGard::GardRecord *)l_hbDeconfigGard->iv_pGardRecords;
        HWAS_INF_BIN("_GardRecordIdSetup:l_pGardRecords BINARY DUMP",
            l_pGardRecords,
            128);

        for (uint32_t i = 0; i < l_maxGardRecords; i++)
        {
            // if this gard record is already filled out
            if (l_pGardRecords[i].iv_recordId
                    != EMPTY_GARD_RECORDID)
            {
                // count how many gard records are already defined
                HWAS_INF("_GardRecordIdSetup: Non-EMPTY i=%d iv_recordId=0x%X",
                    i, l_pGardRecords[i].iv_recordId);
                l_numGardRecords++;

                // find the 'last' recordId, so that we can start after it
                if (l_pGardRecords[i].iv_recordId >
                        l_hbDeconfigGard->iv_nextGardRecordId)
                {
                    // helps in debug if needed
                    HWAS_INF("_GardRecordIdSetup: PRE iv_nextGardRecordId=0x%X i=%d",
                        l_hbDeconfigGard->iv_nextGardRecordId, i);
                    l_hbDeconfigGard->iv_nextGardRecordId =
                        l_pGardRecords[i].iv_recordId;
                    HWAS_INF("_GardRecordIdSetup: POST Setting NEXT to the LAST recordID iv_recordId=0x%X i=%d",
                        l_pGardRecords[i].iv_recordId, i);
                }
            }
        } // for

        // next record will start after the highest Id we found
        l_hbDeconfigGard->iv_nextGardRecordId++;
        HWAS_INF("_GardRecordIdSetup: INITIAL SETUP MEMORY starts as l_hbDeconfigGard->iv_GardVersion=0x%X",
            l_hbDeconfigGard->iv_GardVersion);
        HWAS_INF("_GardRecordIdSetup: INITIAL SETUP READ FROM BINARY l_pGardRecordsBinary->iv_version=0x%X",
            l_pGardRecordsBinary->iv_version);

        switch (l_pGardRecordsBinary->iv_version)
        {
            case HWAS::DeconfigGard::CURRENT_GARD_VERSION_LAYOUT:
                l_hbDeconfigGard->iv_GardVersion = HWAS::DeconfigGard::CURRENT_GARD_VERSION_LAYOUT;
                HWAS_INF("_GardRecordIdSetup: CASE CURRENT l_hbDeconfigGard->iv_GardVersion=0x%X",
                    l_hbDeconfigGard->iv_GardVersion);
                break;
            default:
                // initialize
                const uint32_t gard_ffdc_len = 512; // just a good size to capture
                // clean out any old format records
                HWAS_INF("_GardRecordIdSetup: CLEANING OLD GARD RECORDS from BINARY");
                HWAS_INF_BIN("_GardRecordIdSetup: CLEANING OLD GARD RECORDS from BINARY DUMP",
                    l_pGardRecordsBinary,
                    gard_ffdc_len);
                errlHndl_t l_gardFFDC = nullptr;
                /*@
                 * @errortype
                 * @moduleid   MOD_PLAT_DECONFIG_GARD
                 * @reasoncode RC_CLEAN_GARD_RECORDS
                 * @devdesc    Cleaning old gard records
                 * @userdata1  iv_version read from BINARY
                 * @userdata2  current iv_version expected
                 * @custdesc   Hardware deconfiguration records cleared
                 */
                const uint64_t userdata1 =
                    static_cast<uint64_t>(l_pGardRecordsBinary->iv_version);
                const uint64_t userdata2 =
                    static_cast<uint64_t>(HWAS::DeconfigGard::CURRENT_GARD_VERSION_LAYOUT);
                l_gardFFDC = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_INFORMATIONAL,
                             MOD_PLAT_DECONFIG_GARD,
                             RC_CLEAN_GARD_RECORDS,
                             userdata1,userdata2);
                l_gardFFDC->addFFDC(HWAS_COMP_ID,
                                l_pGardRecordsBinary,
                                gard_ffdc_len,
                                0, // Version
                                ERRL_UDT_NOFORMAT, // SubSect
                                true); // merge
                errlCommit(l_gardFFDC, HWAS_COMP_ID);

                l_hbDeconfigGard->iv_GardVersion = HWAS::DeconfigGard::CURRENT_GARD_VERSION_LAYOUT;
                l_pGardRecordsBinary->iv_version = HWAS::DeconfigGard::CURRENT_GARD_VERSION_LAYOUT;
                memcpy(l_pGardRecordsBinary->iv_magicNumber, "GUARDREC",
                    sizeof(l_pGardRecordsBinary->iv_magicNumber));
                HWAS_INF("_GardRecordIdSetup: CASE DEFAULT l_hbDeconfigGard->iv_GardVersion=0x%X",
                    l_hbDeconfigGard->iv_GardVersion);
                // _flush iv_version
                _flush((void *)&(l_pGardRecordsBinary->iv_version));
                //  clear the MEMORY structure
                for (uint32_t i = 0; i < l_maxGardRecords; i++)
                {
                    l_pGardRecords[i].iv_recordId = EMPTY_GARD_RECORDID;
                    _flush(&l_pGardRecords[i]);
                }
                l_hbDeconfigGard->iv_nextGardRecordId = 1;
                break;
        }
        HWAS_INF("_GardRecordIdSetup: SETUP BINARY set to l_pGardRecordsBinary->iv_version=0x%X",
            l_pGardRecordsBinary->iv_version);
        HWAS_INF("_GardRecordIdSetup: GARD setup MEMORY iv_Gardversion 0x%X iv_maxGardRecords %d iv_nextGardRecordId %d l_numGardRecords %d",
                 l_hbDeconfigGard->iv_GardVersion,
                 l_hbDeconfigGard->iv_maxGardRecords,
                 l_hbDeconfigGard->iv_nextGardRecordId,
                 l_numGardRecords);
    }
    while (0);

    return l_pErr;
}


void _flush(void *i_addr)
{
#ifndef __HOSTBOOT_RUNTIME
    HWAS_DBG("_flush: flushing GARD in PNOR: addr=%p sizeof(DeconfigGard::GardRecord)=0x%X", i_addr, sizeof(DeconfigGard::GardRecord));
    int l_rc = mm_remove_pages(FLUSH, i_addr,
                sizeof(DeconfigGard::GardRecord));
    if (l_rc)
    {
        HWAS_ERR("_flush: mm_remove_pages(FLUSH,%p,%d) returned %d",
                i_addr, sizeof(DeconfigGard::GardRecord),l_rc);
    }
#elif defined (CONFIG_FILE_XFER_VIA_PLDM)
    HWAS_DBG("_flush: flushing all GARD in PNOR addr=%p", i_addr);
    PNOR::flush(PNOR::GUARD_DATA);
#endif
}

#if !defined(__HOSTBOOT_RUNTIME) || defined(CONFIG_FILE_XFER_VIA_PLDM)
errlHndl_t getGardSectionInfo(PNOR::SectionInfo_t& o_sectionInfo)
{
    errlHndl_t l_errl = NULL;
    do
    {
        // getSectionInfo has already been called for GUARD_DATA
        if(getGardSectionInfoCalled)
        {
            o_sectionInfo = g_GardSectionInfo;
            break;
        }

        // Get Guard Section Info and set gardSectionInfo
        l_errl = PNOR::getSectionInfo(PNOR::GUARD_DATA, g_GardSectionInfo);
        if (l_errl)
        {
            g_GardSectionInfo.size = 0;

            PNOR::SideInfo_t l_sideInfo;
            errlHndl_t l_tempErr = PNOR::getSideInfo(PNOR::WORKING,l_sideInfo);
            if (l_tempErr)
            {
                HWAS_ERR("getGardSectionInfo: getSideInfo failed");
                errlCommit (l_errl,HWAS_COMP_ID);
                l_errl = l_tempErr;
            }
            if (!l_sideInfo.isGuardPresent)
            {
                HWAS_INF("getGardSectionInfo: No guard section; disabling guard support");
                delete l_errl;
                l_errl = NULL;
            }
            else
            {
                HWAS_ERR("getGardSectionInfo:getSectionInfo failed");
            }
        }
        else
        {
            HWAS_INF("getGardSectionInfo: Section %s found, size %d",
                      g_GardSectionInfo.name, g_GardSectionInfo.size);
        }

        o_sectionInfo = g_GardSectionInfo;
        getGardSectionInfoCalled = true;
    } while(0);

    return l_errl;
}
#endif //ifdef CONFIG_FILE_XFER_VIA_PLDM

/**
 * @brief This will perform any post-deconfig operations,
 *        such as syncing state with other subsystems
 */
void DeconfigGard::platPostDeconfigureTarget(
                                   TARGETING::Target * i_pTarget)
{
#ifndef __HOSTBOOT_RUNTIME
#ifdef CONFIG_TPMDD
    if(   i_pTarget->getAttr<TARGETING::ATTR_TYPE>()
       == TARGETING::TYPE_TPM)
    {
        HWAS_INF("platPostDeconfigureTarget: Deconfiguring TPM 0x%08X",
            get_huid(i_pTarget));
        errlHndl_t pError = nullptr; // No error log with FFDC
        (void)TRUSTEDBOOT::tpmMarkFailed(i_pTarget,
                                         pError);
    }
#endif  // CONFIG_TPMDD
#endif  // #ifndef __HOSTBOOT_RUNTIME

#ifdef __HOSTBOOT_RUNTIME
   // As part of keeping things in sync when a target is
   // deconfiged, HBRT will send a message down to FSP to
   // inform FSP that a target has been deconfiged
   errlHndl_t l_err = nullptr;

   // Handles to the firmware messages
   hostInterfaces::hbrt_fw_msg *l_req_fw_msg = nullptr;
   hostInterfaces::hbrt_fw_msg *l_resp_fw_msg = nullptr;

   do
   {
      // This path is only relevant for FSP systems
      if( !INITSERVICE::spBaseServicesEnabled() )
      {
          break;
      }

      // Make sure we have all of our function pointers setup right
      if ((nullptr == g_hostInterfaces) ||
          (nullptr == g_hostInterfaces->firmware_request))
      {
         HWAS_ERR("Hypervisor firmware_request interface not linked");

         /*@
          * @errortype
          * @severity         ERRL_SEV_INFORMATIONAL
          * @moduleid         HWAS::MOD_PLAT_DECONFIG_GARD
          * @reasoncode       HWAS::RC_RT_NULL_FIRMWARE_REQUEST_PTR
          * @userdata1        HUID of target
          * @userdata2        none
          * @devdesc          Post de-configuration of target failed
          */
         l_err= new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                              HWAS::MOD_PLAT_DECONFIG_GARD,
                              HWAS::RC_RT_NULL_FIRMWARE_REQUEST_PTR,
                              get_huid(i_pTarget),
                              0,
                              ErrlEntry::ADD_SW_CALLOUT);
         break;
      }

      // Create and initialize to zero a few needed variables
      uint32_t l_fsp_data_size(0);
      uint64_t l_req_fw_msg_size(0), l_resp_fw_msg_size(0);

      // Create the dynamic firmware messages
      createGenericFspMsg(sizeof(TargetDeconfigHbrtFspData_t),
                          l_fsp_data_size,
                          l_req_fw_msg_size,
                          l_req_fw_msg,
                          l_resp_fw_msg_size,
                          l_resp_fw_msg);

      // If there was an issue with creating the messages,
      // Create an Error Log entry and exit
      if (!l_req_fw_msg || !l_resp_fw_msg)
      {
         HWAS_ERR("Unable to allocate firmware request messages");

         /*@
          * @errortype
          * @severity         ERRL_SEV_INFORMATIONAL
          * @moduleid         HWAS::MOD_PLAT_DECONFIG_GARD
          * @reasoncode       HWAS::RC_RT_NULL_FIRMWARE_MSG_PTR
          * @userdata1        HUID of target
          * @userdata2        none
          * @devdesc          Post de-configuration of target failed
          */
         l_err= new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                              HWAS::MOD_PLAT_DECONFIG_GARD,
                              HWAS::RC_RT_NULL_FIRMWARE_MSG_PTR,
                              get_huid(i_pTarget),
                              0,
                              ErrlEntry::ADD_SW_CALLOUT);
         break;
      }

      // Populate the request message with given data
      l_req_fw_msg->generic_msg.msgq = MBOX::FSP_TARG_DECONFIG_MSGQ;
      l_req_fw_msg->generic_msg.msgType =
                            GenericFspMboxMessage_t::MSG_DECONFIG_TARGET;

      // Create a useful struct to populate the generic_msg::data field
      // Setting the HUID in the 1st 4 bytes (32bits) followed by the
      // HWAS state.
      TargetDeconfigHbrtFspData_t* l_fspData =
                  reinterpret_cast<TargetDeconfigHbrtFspData_t*>
                                 (&(l_req_fw_msg->generic_msg.data));
      l_fspData->huid = get_huid(i_pTarget);
      l_fspData->hwasState = i_pTarget->getAttr<ATTR_HWAS_STATE>();

      // Binary trace the request message
      HWAS_INF_BIN("Sending firmware_request",
                   l_req_fw_msg,
                   l_req_fw_msg_size);

      // Make the firmware_request call
      // Inform the FSP that this target has been deconfiged
      l_err = firmware_request_helper(l_req_fw_msg_size,
                                      l_req_fw_msg,
                                      &l_resp_fw_msg_size,
                                      l_resp_fw_msg);
   } while(0);

   if (l_err)
   {
       l_err->collectTrace("HWAS_I",1024);
      errlCommit(l_err, HWAS_COMP_ID);
   }

   // Release the firmware messages and set to NULL
   delete []l_req_fw_msg;
   delete []l_resp_fw_msg;
   l_req_fw_msg = l_resp_fw_msg = nullptr;
#endif  // __HOSTBOOT_RUNTIME
}

/******************************************************************************/
// platProcessFieldCoreOverride
/******************************************************************************/
errlHndl_t DeconfigGard::platProcessFieldCoreOverride()
{
    errlHndl_t l_pErr = NULL;

#ifndef __HOSTBOOT_RUNTIME
    HWAS_DBG("Process Field Core Override FCO: platProcessFieldCoreOverride");

    do
    {
        // otherwise, process and reduce cores.
        // find all functional NODE targets
        Target* pSys;
        targetService().getTopLevelTarget(pSys);
        PredicateCTM predNode(CLASS_ENC, TYPE_NODE);
        PredicateHwas predFunctional;
        predFunctional.functional(true);
        PredicatePostfixExpr nodeCheckExpr;
        nodeCheckExpr.push(&predNode).push(&predFunctional).And();

        TargetHandleList pNodeList;
        targetService().getAssociated(pNodeList, pSys,
                        TargetService::CHILD, TargetService::IMMEDIATE,
                        &nodeCheckExpr);

        // sort the list by ATTR_HUID to ensure that we
        //  start at the same place each time
        std::sort(pNodeList.begin(), pNodeList.end(),
                    compareTargetHuid);

        // for each of the nodes
        for (TargetHandleList::const_iterator
                pNode_it = pNodeList.begin();
                pNode_it != pNodeList.end();
                ++pNode_it
            )
        {
            const TargetHandle_t pNode = *pNode_it;

            // Get FCO value
            uint32_t l_fco(0);
            l_pErr = platGetFCO(pNode, l_fco);
            if (l_pErr)
            {
                HWAS_ERR("Error from platGetFCO");
                break;
            }

            // FCO of 0 means no overrides for this node
            if (l_fco == 0)
            {
                HWAS_INF("FCO: node %.8X: no overrides, done.",
                        get_huid(pNode));
                continue; // next node
            }
            else if (is_fused_mode())
            {
                l_fco += l_fco;
                HWAS_INF("FCO: node %.8X: Doubling EC count in fused_mode. "
                         "l_fco=0x%X", get_huid(pNode), l_fco);
            }
            else
            {
                HWAS_INF("FCO: node %.8X: value %d",
                         get_huid(pNode), l_fco);
            }

            // find all functional child PROC targets
            TargetHandleList pProcList;
            getChildAffinityTargets(pProcList, pNode,
                    CLASS_CHIP, TYPE_PROC, true);

            // sort the list by ATTR_HUID to ensure that we
            //  start at the same place each time
            std::sort(pProcList.begin(), pProcList.end(),
                    compareTargetHuid);

            // create list for restrictECunits() function
            procRestrict_t l_procEntry;
            std::vector <procRestrict_t> l_procRestrictList;
            for (TargetHandleList::const_iterator
                    pProc_it = pProcList.begin();
                    pProc_it != pProcList.end();
                    ++pProc_it
                )
            {
                const TargetHandle_t pProc = *pProc_it;

                // save info so that we can
                //  restrict the number of EC units
                HWAS_DBG("pProc %.8X - pushing to proclist",
                    get_huid(pProc));
                l_procEntry.target = pProc;
                l_procEntry.group = 0;
                l_procEntry.procs = pProcList.size();
                l_procEntry.maxECs = l_fco;
                l_procRestrictList.push_back(l_procEntry);
            } // for pProc_it

            // restrict the EC units; units turned off are marked
            //  present=true, functional=false, and marked with the
            //  appropriate deconfigure code.
            HWAS_INF("FCO: calling restrictECunits with %d entries",
                    l_procRestrictList.size());

            l_pErr = restrictECunits(l_procRestrictList,
                                     DECONFIGURED_BY_FIELD_CORE_OVERRIDE);
            if (l_pErr)
            {
                break;
            }
        } // for pNode_it
    }
    while (0);
#endif  // #ifndef __HOSTBOOT_RUNTIME
    return l_pErr;
} // platProcessFieldCoreOverride

//*****************************************************************************
bool platSystemIsAtRuntime()
{
#ifndef __HOSTBOOT_RUNTIME
    HWAS_INF("HostBoot is running so system is NOT at runtime.");
    return false;
#else
    HWAS_INF("HostBoot is NOT running so system is at runtime.");
    return true;
#endif
}

const TARGETING::Target * getFRU_Target(const TARGETING::Target * i_target)
{
    TARGETING::ATTR_FRU_ID_type l_fruid = 0;  // set to invalid FRU ID
    TARGETING::TargetHandleList l_parentList;
    const TARGETING::Target * l_target = i_target;
    uint16_t level = 0; // just a basic parent level counter
    bool foundFru = i_target->tryGetAttr<TARGETING::ATTR_FRU_ID>(l_fruid);
    while (!foundFru)
    {
        level++;

        TARGETING::targetService().getAssociated(
                                        l_parentList,
                                        l_target,
                                        TARGETING::TargetService::PARENT,
                                        TARGETING::TargetService::IMMEDIATE);

        if (l_parentList.size() != 1)
        {
            HWAS_INF("parent level=%d No Parent for HUID 0x%X target",
                level, TARGETING::get_huid(l_target));
            l_target = nullptr;
            break;
        }

        l_target = l_parentList[0];
        if (l_target->tryGetAttr<TARGETING::ATTR_FRU_ID>(l_fruid))
        {
            // Found 1st parent with a FRU ID
            foundFru = true;
        }

        l_parentList.clear();  // clear out old entry

    } // end while

    if (foundFru)
    {
        HWAS_INF("getFRU_ID: ATTR_FRU_ID=0x%X parent level=%d found for l_target=0x%X target HUID 0x%X",
            l_fruid, level, l_target, TARGETING::get_huid(l_target));
    }
    else
    {
        HWAS_INF("getFRU_ID: Failed to find a FRU ID for l_target=0x%X target HUID 0x%X. Looked at %d parent levels.",
            l_target, TARGETING::get_huid(l_target), level);
    }

    return l_target;
}

//*****************************************************************************
errlHndl_t hwasError(const uint8_t i_sev,
              const uint8_t i_modId,
              const uint16_t i_reasonCode,
              const uint64_t i_user1,
              const uint64_t i_user2)
{
    errlHndl_t l_pErr;

    l_pErr = new ERRORLOG::ErrlEntry(
                    (ERRORLOG::errlSeverity_t)i_sev, i_modId,
                    i_reasonCode,
                    i_user1, i_user2);
    l_pErr->collectTrace("HWAS_I");
    return l_pErr;
}


//******************************************************************************
// HOSTBOOT RUNTIME methods
//******************************************************************************

#ifdef __HOSTBOOT_RUNTIME
/******************************************************************************/
// platDeconfigureTargetAtRuntime
/******************************************************************************/
errlHndl_t DeconfigGard::platDeconfigureTargetAtRuntime(
        TARGETING::TargetHandle_t i_pTarget,
        const DeconfigureFlags i_deconfigureAction,
        const errlHndl_t i_deconfigErrl)
{

    HWAS_INF(">>>platDeconfigureTargetAtRuntime()");

    errlHndl_t l_errl = nullptr;

    do
    {
        if( i_pTarget == nullptr )
        {
            HWAS_ERR("Target is NULL.");
            /*@
             * @errortype
             * @moduleid     MOD_RUNTIME_DECONFIG
             * @reasoncode   RC_NULL_TARGET
             * @devdesc      Target is NULL
             * @custdesc     Host Firmware encountered an internal
             *               error
             */
            l_errl = hwasError(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    HWAS::MOD_RUNTIME_DECONFIG,
                    HWAS::RC_NULL_TARGET,0,0);

            break;
        }

        // Retrieve the target type from the given target
        TYPE l_targetType = i_pTarget->getAttr<ATTR_TYPE>();

        // Make sure we are only working with the following types
        if( (l_targetType != TYPE_EQ) &&
            (l_targetType != TYPE_FC) &&
            (l_targetType != TYPE_CORE) )
        {
            HWAS_ERR("Caller passed invalid type: 0x%08X", l_targetType);

            // only supporting cores
            /*@
             * @errortype
             * @moduleid     MOD_RUNTIME_DECONFIG
             * @reasoncode   RC_INVALID_TARGET
             * @devdesc      Target is neiter TYPE_EQ, TYPE_FC nor TYPE_CORE
             * @userdata1    target huid
             * @custdesc     Host Firmware encountered an internal
             *               error
             */
            l_errl = hwasError(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                               HWAS::MOD_RUNTIME_DECONFIG,
                               HWAS::RC_INVALID_TARGET,get_huid(i_pTarget),0);
            break;
        }

        switch(i_deconfigureAction)
        {
            case DeconfigGard::FULLY_AT_RUNTIME:

                HWAS_INF("Deconfig action FULLY_AT_RUNTIME :0x%08X",
                        DeconfigGard::FULLY_AT_RUNTIME);
                break;

            default:
                HWAS_ERR("Caller passed invalid DeconfigAction: 0x%08X",
                        i_deconfigureAction);
                /*@
                 * @errortype
                 * @moduleid     MOD_RUNTIME_DECONFIG
                 * @reasoncode   RC_INVALID_PARAM
                 * @userdata1    HUID of the target
                 * @userdata2    Target type
                 * @userdata3    Target class
                 * @userdata4    Deconfig Action
                 * @devdesc      Caller passed invalid deconfigure action
                 * @custdesc     Host firmware encountered an
                 *               internal error
                 */
                l_errl = hwasError(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        HWAS::MOD_RUNTIME_DECONFIG,
                        HWAS::RC_INVALID_PARAM,0,0);
                break;
        }

        // If an error then exit while loop
        if (l_errl)
        {
           break;
        }

        uint32_t  l_deconfigReason =  (i_deconfigErrl) ? i_deconfigErrl->eid() :
            DeconfigGard::DECONFIGURED_BY_PRD;

        HWAS_INF("deconfigureTargetAtRuntime() - "
                "Input Target HUID:0x%08X Deconfig Action"
                " 0x%08X deconfigReason:0x%08X",
                get_huid(i_pTarget),i_deconfigureAction,
                l_deconfigReason);

        bool l_isTargetDeconfigured = false;

        // deconfigureTarget() checks for targets that can be deconfigured at
        // runtime
        l_errl = theDeconfigGard().deconfigureTarget(
                                   const_cast<TARGETING::Target&>(*i_pTarget),
                                   l_deconfigReason,
                                   &l_isTargetDeconfigured,
                                   i_deconfigureAction);

        // If there was an error OR the target was not deconfigured, then
        // do not continue and exit
        if (l_errl || !l_isTargetDeconfigured)
        {
            HWAS_INF("platDeconfigureTargetAtRuntime() - deconfigure failed");
            break;
        }

        HWAS_INF("platDeconfigureTargetAtRuntime() - "
                 "deconfigure successful");

        TARGETING::TYPE  l_type = TARGETING::TYPE_PROC;
        TARGETING::Target * l_parent =
                            TARGETING::getParent(i_pTarget,l_type);

        // There might be a recursion possible with PRD and PM Reset so
        //  don't call into reset twice
        auto l_pmResetInProgress =
          l_parent->getAttr<ATTR_HB_INITIATED_PM_RESET>();
        if( HB_INITIATED_PM_RESET_IN_PROGRESS != l_pmResetInProgress )
        {
            // set ATTR_HB_INITIATED_PM_RESET to IN_PROGRESS to allow
            //  special handling for PRD
            l_parent->setAttr<ATTR_HB_INITIATED_PM_RESET>
              (HB_INITIATED_PM_RESET_IN_PROGRESS);

            HWAS_INF("platDeconfigureTargetAtRuntime() - Calling resetPMComplex");
            l_errl = HBPM::resetPMComplex(l_parent);

            if(l_errl)
            {
                HWAS_ERR("Failed call to HBPM::resetPMComplex on target "
                         "with HUID : %d",TARGETING::get_huid(l_parent));
                ERRORLOG::ErrlUserDetailsTarget(l_parent).addToLog(l_errl);

                // set ATTR_HB_INITIATED_PM_RESET back to INACTIVE to allow
                //  future recoveries to completely run
                l_parent->setAttr<ATTR_HB_INITIATED_PM_RESET>
                  (HB_INITIATED_PM_RESET_INACTIVE);

                // If an error then exit while loop
                break;
            }
            else
            {
                HWAS_INF("Successful call to HBPM::resetPMComplex on target"
                         " with HUID : %.8X, setting ATTR_HB_INITIATED_PM_RESET to"
                         " COMPLETE(%d)",
                         TARGETING::get_huid(l_parent),
                         HB_INITIATED_PM_RESET_COMPLETE);
                // set ATTR_HB_INITIATED_PM_RESET to ACTIVE (reset IS in progress)
                // and continue
                l_parent->setAttr<ATTR_HB_INITIATED_PM_RESET>
                  (HB_INITIATED_PM_RESET_COMPLETE);
            }
        }
        else
        {
            HWAS_INF("platDeconfigureTargetAtRuntime() - skippign call to resetPMComplex - ATTR_HB_INITIATED_PM_RESET=%d", l_pmResetInProgress );
        }

    }while(0);

    HWAS_INF("<<<platDeconfigureTargetAtRuntime()" );

    return l_errl ;
}

#endif // end #ifdef __HOSTBOOT_RUNTIME


} // namespace HWAS
