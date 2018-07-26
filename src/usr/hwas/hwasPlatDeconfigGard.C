/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hwasPlatDeconfigGard.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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
#include <config.h>
#include <initservice/istepdispatcherif.H>
#include <initservice/initserviceif.H>

#include <pnor/pnorif.H>
#include <pm/pm_common.H>                  // HBPM::resetPMComplex

#ifdef __HOSTBOOT_RUNTIME
#include <runtime/interface.h>             // g_hostInterfaces
#include <runtime/hbrt_utilities.H>        // createGenericFspMsg
#include <util/runtime/rt_fwreq_helper.H>  // firmware_request_helper
#include <errl/errludtarget.H>

// includes to support the fapi2 hwp call in
// platDeconfigureTargetAtRuntime()
#include <fapi2/target.H>
#include <p9_update_ec_eq_state.H>
#include <fapi2/plat_hwp_invoker.H>
#endif

#ifdef CONFIG_TPMDD
#include <../usr/secureboot/trusted/trustedbootUtils.H>
#endif

namespace HWAS
{

using namespace HWAS::COMMON;
using namespace TARGETING;

const uint32_t EMPTY_GARD_RECORDID = 0xFFFFFFFF;
/**
 * @brief Guard PNOR section info, obtained once for efficiency
 */
static PNOR::SectionInfo_t g_GardSectionInfo;

/**
 * @brief Flag indicating if getGardSectionInfo() was called previously
 */
static bool getGardSectionInfoCalled;

void _flush(void *i_addr);
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

errlHndl_t DeconfigGard::platClearGardRecords(
    const Target * const i_pTarget)
{
    errlHndl_t l_pErr = NULL;

    EntityPath l_targetId;
    if (!i_pTarget)
    {
        HWAS_INF("Clear all GARD Records");
    }
    else
    {
        l_targetId = i_pTarget->getAttr<ATTR_PHYS_PATH>();
        HWAS_INF("Clear GARD Records for %.8X", get_huid(i_pTarget));
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
                        HWAS_INF("Clearing GARD Record for %.8X",
                                get_huid(i_pTarget));
                        l_pGardRecords[i].iv_recordId = EMPTY_GARD_RECORDID;
                        _flush(&l_pGardRecords[i]);
                        l_gardRecordsCleared++;
                        break; // done - can only be 1 GARD record per target
                    }
                }
                else // Clear all records
                {
                    l_pGardRecords[i].iv_recordId = EMPTY_GARD_RECORDID;
                    _flush(&l_pGardRecords[i]);
                    l_gardRecordsCleared++;
                }
            }
        } // for

        HWAS_INF("GARD Records Cleared: %d", l_gardRecordsCleared);
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
                        HWAS_INF("Getting GARD Record for %.8X",
                                get_huid(i_pTarget));
                        o_records.push_back(l_pGardRecords[i]);
                        break; // done - can only be 1 GARD record per target
                    }
                }
                else // get all records
                {
                    o_records.push_back(l_pGardRecords[i]);
                }
            }
        } // for
    }

    HWAS_MUTEX_UNLOCK(iv_mutex);
    HWAS_INF("Get returning %d GARD Records", o_records.size());
    return l_pErr;
}


errlHndl_t DeconfigGard::platCreateGardRecord(
        const Target * const i_pTarget,
        const uint32_t i_errlEid,
        const GARD_ErrorType i_errorType)
{
    HWAS_INF("Creating GARD Record for %.8X, errl 0x%X",
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

        Target* pSys;
        targetService().getTopLevelTarget(pSys);
        HWAS_ASSERT(pSys, "HWAS platCreateGardRecord: no TopLevelTarget");

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
            if (l_pGardRecords[i].iv_recordId == EMPTY_GARD_RECORDID)
            {
                if (!l_pRecord)
                {
                    // save the first empty location we find
                    l_pRecord = &(l_pGardRecords[i]);
                }
            }
            else
            {
                if (l_pGardRecords[i].iv_targetId == l_targetId)
                {
                    l_duplicate = true;
                    l_pRecord = &(l_pGardRecords[i]);
                    HWAS_INF("Duplicate GARD Record from error 0x%X",
                            l_pGardRecords[i].iv_errlogEid);
                    break;
                }
            }
        } // for

        if (l_duplicate)
        {
            // there's already a GARD record for this target

            // if this GARD record was a manual gard - overwrite
            //  with this new one
            if (l_pRecord->iv_errorType == GARD_User_Manual)
            {
                HWAS_INF("Duplicate is GARD_User_Manual - overwriting");
                l_pRecord->iv_errlogEid = i_errlEid;
                l_pRecord->iv_errorType = i_errorType;
                _flush((void *)l_pRecord);
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

        l_pRecord->iv_recordId = l_hbDeconfigGard->iv_nextGardRecordId++;
        l_pRecord->iv_targetId = l_targetId;
        l_pRecord->iv_errlogEid = i_errlEid;
        l_pRecord->iv_errorType = i_errorType;
        l_pRecord->iv_padding[0] = 0;
        l_pRecord->iv_padding[1] = 0;
        l_pRecord->iv_padding[2] = 0;
        l_pRecord->iv_padding[3] = 0;
        l_pRecord->iv_padding[4] = 0;
        l_pRecord->iv_padding[5] = 0;

        _flush((void *)l_pRecord);

        // We wrote a new gard record, we need to make sure to increment the
        // reboot count so we can reconfigure and attempt to IPL
        // Call setNewGardRecord in initservice.
        #ifndef __HOSTBOOT_RUNTIME
        #ifdef CONFIG_BMC_IPMI
        HWAS_INF("New gard record committed, call INITSERVICE "
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
    HWAS_DBG("_GardRecordIdSetup: io_platDeconfigGard %p", io_platDeconfigGard);
    errlHndl_t l_pErr = NULL;

    do
    {
        // if this is NOT the first time thru here, we're done
        if (io_platDeconfigGard != NULL)
        {
            break;
        }

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

        // allocate our memory and set things up
        io_platDeconfigGard = malloc(sizeof(HBDeconfigGard));
        HBDeconfigGard *l_hbDeconfigGard =
                (HBDeconfigGard *)io_platDeconfigGard;

        l_hbDeconfigGard->iv_pGardRecords =
            reinterpret_cast<DeconfigGard::GardRecord *> (l_section.vaddr);
        HWAS_DBG("PNOR vaddr=%p size=%d", l_section.vaddr, l_section.size);

        l_hbDeconfigGard->iv_maxGardRecords = l_section.size /
                sizeof(DeconfigGard::GardRecord);
        l_hbDeconfigGard->iv_nextGardRecordId = 0;

        // Figure out the next GARD Record ID to use
        uint32_t l_numGardRecords = 0;
        const uint32_t l_maxGardRecords = l_hbDeconfigGard->iv_maxGardRecords;
        DeconfigGard::GardRecord *l_pGardRecords =
                (DeconfigGard::GardRecord *)l_hbDeconfigGard->iv_pGardRecords;
        for (uint32_t i = 0; i < l_maxGardRecords; i++)
        {
            // if this gard record is already filled out
            if (l_pGardRecords[i].iv_recordId
                    != EMPTY_GARD_RECORDID)
            {
                // count how many gard records are already defined
                l_numGardRecords++;

                // find the 'last' recordId, so that we can start after it
                if (l_pGardRecords[i].iv_recordId >
                        l_hbDeconfigGard->iv_nextGardRecordId)
                {
                    l_hbDeconfigGard->iv_nextGardRecordId =
                        l_pGardRecords[i].iv_recordId;
                }
            }
        } // for

        // next record will start after the highest Id we found
        l_hbDeconfigGard->iv_nextGardRecordId++;

        HWAS_INF("GARD setup. maxRecords %d nextID %d numRecords %d",
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
    HWAS_DBG("flushing GARD in PNOR: addr=%p", i_addr);
    int l_rc = mm_remove_pages(FLUSH, i_addr,
                sizeof(DeconfigGard::GardRecord));
    if (l_rc)
    {
        HWAS_ERR("mm_remove_pages(FLUSH,%p,%d) returned %d",
                i_addr, sizeof(DeconfigGard::GardRecord),l_rc);
    }
#else
    HWAS_DBG("flushing all GARD in PNOR due to addr=%p", i_addr);
    PNOR::flush(PNOR::GUARD_DATA);
#endif
}

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
      errlCommit(l_err, HWAS_COMP_ID);
   }

   // Release the firmware messages and set to NULL
   delete []l_req_fw_msg;
   delete []l_resp_fw_msg;
   l_req_fw_msg = l_resp_fw_msg = nullptr;
#endif  // __HOSTBOOT_RUNTIME
}

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
            (l_targetType != TYPE_EX) &&
            (l_targetType != TYPE_CORE) )
        {
            HWAS_ERR("Caller passed invalid type: 0x%08X", l_targetType);

            // only supporting cores
            /*@
             * @errortype
             * @moduleid     MOD_RUNTIME_DECONFIG
             * @reasoncode   RC_INVALID_TARGET
             * @devdesc      Target is neiter TYPE_EQ, TYPE_EX nor TYPE_CORE
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

        // get the parent proc and call the hwp to alert
        // pm not to attempt to manage this core anymore
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_proc(l_parent);

        HWAS_INF("platDeconfigureTargetAtRuntime() - "
                "calling p9_update_ec_eq_state");
        FAPI_INVOKE_HWP( l_errl,p9_update_ec_eq_state,
                         l_proc,true/*skip qssr*/);

        if(l_errl)
        {
            HWAS_ERR("platDeconfigureTargetAtRuntime() - "
                    "call to p9_update_ec_eq_state() failed on proc "
                    "with HUID : %d",TARGETING::get_huid(l_proc));
            ERRORLOG::ErrlUserDetailsTarget(l_proc).addToLog(l_errl);

            // If an error then exit while loop
            break;
        }
    }while(0);

    HWAS_INF("<<<platDeconfigureTargetAtRuntime()" );

    return l_errl ;
}

#endif // __HOSTBOOT_RUNTIME


} // namespace HWAS
