/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/deconfigGard.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
 *  @file deconfigGard.C
 *
 *  @brief Implements the DeconfigGard class
 */
#include <stdint.h>
#include <algorithm>

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <targeting/common/utilFilter.H>

#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>

// Trace definition
#define __COMP_TD__ g_trac_deconf

namespace HWAS
{

using namespace HWAS::COMMON;
using namespace TARGETING;

//******************************************************************************
errlHndl_t collectGard(const PredicateBase *i_pPredicate)
{
    HWAS_DBG("collectGard entry" );
    errlHndl_t errl = NULL;

    do
    {
        errl = theDeconfigGard().clearGardRecordsForReplacedTargets();
        if (errl)
        {
            HWAS_ERR("ERROR: collectGard failed to clear GARD Records for replaced Targets");
            break;
        }

        errl = theDeconfigGard().
                    deconfigureTargetsFromGardRecordsForIpl(i_pPredicate);
        if (errl)
        {
            HWAS_ERR("ERROR: collectGard failed to deconfigure Targets from GARD Records for IPL");
            break;
        }

        errl = theDeconfigGard().processFieldCoreOverride();
        if (errl)
        {
            HWAS_ERR("ERROR: collectGard failed to process Field Core Override");
            break;
        }
    }
    while(0);

    if (errl)
    {
        HWAS_ERR("collectGard failed (plid 0x%X)", errl->plid());
    }
    else
    {
        HWAS_INF("collectGard completed successfully");
    }
    return errl;
} // collectGard

//******************************************************************************
DeconfigGard & theDeconfigGard()
{
    return HWAS_GET_SINGLETON(theDeconfigGardSingleton);
}

//******************************************************************************
DeconfigGard::DeconfigGard()
: iv_platDeconfigGard(NULL),
  iv_XABusEndpointDeconfigured(false)
{
    HWAS_DBG("DeconfigGard Constructor");
    HWAS_MUTEX_INIT(iv_mutex);
}

//******************************************************************************
DeconfigGard::~DeconfigGard()
{
    HWAS_DBG("DeconfigGard Destructor");
    HWAS_MUTEX_DESTROY(iv_mutex);
    free(iv_platDeconfigGard);
}

//******************************************************************************
errlHndl_t DeconfigGard::clearGardRecordsForReplacedTargets()
{
    HWAS_INF("User Request: Clear GARD Records for replaced Targets");
    errlHndl_t l_pErr = NULL;

    // Create the predicate with HWAS changed state and our GARD bit
    PredicateHwasChanged l_predicateHwasChanged;
    l_predicateHwasChanged.changedBit(HWAS_CHANGED_BIT_GARD, true);

    do
    {
        GardRecords_t l_gardRecords;
        l_pErr = platGetGardRecords(NULL, l_gardRecords);
        if (l_pErr)
        {
            HWAS_ERR("Error from platGetGardRecords");
            break;
        }

        // For each GARD Record
        for (GardRecordsCItr_t l_itr = l_gardRecords.begin();
             l_itr != l_gardRecords.end();
             ++l_itr)
        {
            GardRecord l_gardRecord = *l_itr;

            // Find the associated Target
            Target* l_pTarget = targetService().
                            toTarget(l_gardRecord.iv_targetId);

            if (l_pTarget == NULL)
            {
                // could be a platform specific target for the other
                // ie, we are hostboot and this is an FSP target, or vice-versa
                HWAS_INF("Could not find Target for %.8X",
                        get_huid(l_pTarget));

                // we just skip this GARD record
                continue;
            }

            // if this does NOT match, continue to next in loop
            if (l_predicateHwasChanged(l_pTarget) == false)
            {
                HWAS_INF("skipping %.8X - GARD changed bit false",
                        get_huid(l_pTarget));
                continue;
            }

            // Clear the gard record
            HWAS_INF("clearing GARD for %.8X, recordId %d",
                        get_huid(l_pTarget),
                        l_gardRecord.iv_recordId);

            l_pErr = platClearGardRecords(l_pTarget);
            if (l_pErr)
            {
                HWAS_ERR("Error from platClearGardRecords");
                break;
            }
        } // for

        // now we need to go thru and clear all of the GARD bits in the
        // changed flags for all targets
        for (TargetIterator t_iter = targetService().begin();
                t_iter != targetService().end();
                ++t_iter)
        {
            Target* l_pTarget = *t_iter;
            if (l_predicateHwasChanged(l_pTarget))
            {
                clear_hwas_changed_bit(l_pTarget,HWAS_CHANGED_BIT_GARD);
            }
        }
    }
    while (0);

    return l_pErr;
} // clearGardRecordsForReplacedTargets

//******************************************************************************
errlHndl_t DeconfigGard::deconfigureTargetsFromGardRecordsForIpl(
        const PredicateBase *i_pPredicate)
{
    HWAS_INF("Deconfigure Targets from GARD Records for IPL");
    errlHndl_t l_pErr = NULL;

    do
    {
        Target* pSys;
        targetService().getTopLevelTarget(pSys);
        HWAS_ASSERT(pSys, "HWAS deconfigTargetsFromGardRecordsForIpl: no TopLevelTarget");

        // check for system CDM Policy
        const ATTR_CDM_POLICIES_type l_sys_policy =
                pSys->getAttr<ATTR_CDM_POLICIES>();
        if (l_sys_policy & CDM_POLICIES_MANUFACTURING_DISABLED)
        {
            // manufacturing records are disabled
            //  - don't process
            HWAS_INF("Manufacturing policy: disabled - skipping GARD Records");
            l_pErr = platLogEvent(NULL, MFG);
            if (l_pErr)
            {
                HWAS_ERR("platLogEvent returned an error");
            }
            break;
        }

        // Get all GARD Records
        GardRecords_t l_gardRecords;
        l_pErr = platGetGardRecords(NULL, l_gardRecords);
        if (l_pErr)
        {
            HWAS_ERR("Error from platGetGardRecords");
            break;
        }

        HWAS_DBG("%d GARD Records found", l_gardRecords.size());

        std::vector<uint32_t> errlLogEidList;
        // For each GARD Record
        for (GardRecordsCItr_t l_itr = l_gardRecords.begin();
             l_itr != l_gardRecords.end();
             ++l_itr)
        {
            GardRecord l_gardRecord = *l_itr;

            // Find the associated Target
            Target * l_pTarget =
                targetService().toTarget(l_gardRecord.iv_targetId);

            if (l_pTarget == NULL)
            {
                // could be a platform specific target for the other
                // ie, we are hostboot and this is an FSP target, or vice-versa
                // Binary trace the iv_targetId (EntityPath)
                HWAS_INF_BIN("Could not find Target for:",
                             &(l_gardRecord.iv_targetId),
                             sizeof(l_gardRecord.iv_targetId));
                continue;
            }

            // if this does NOT match, continue to next in loop
            if (i_pPredicate && ((*i_pPredicate)(l_pTarget) == false))
            {
                HWAS_INF("skipping %.8X - predicate didn't match",
                        get_huid(l_pTarget));
                l_pErr = platLogEvent(l_pTarget, PREDICATE);
                if (l_pErr)
                {
                    HWAS_ERR("platLogEvent returned an error");
                    break;
                }
                continue;
            }

            if ((l_sys_policy & CDM_POLICIES_PREDICTIVE_DISABLED) &&
                (l_gardRecord.iv_errorType == GARD_Predictive))
            {
                // predictive records are disabled AND gard record is predictive
                //  - don't process
                HWAS_INF("Predictive policy: disabled - skipping GARD Record");
                l_pErr = platLogEvent(l_pTarget, PREDICTIVE);
                if (l_pErr)
                {
                    HWAS_ERR("platLogEvent returned an error");
                    break;
                }
                continue;
            }

            // skip if not present
            if (!l_pTarget->getAttr<ATTR_HWAS_STATE>().present)
            {
                HWAS_INF("skipping %.8X - target not present",
                        get_huid(l_pTarget));
                l_pErr = platLogEvent(l_pTarget, GARD_NOT_APPLIED);
                if (l_pErr)
                {
                    HWAS_ERR("platLogEvent returned an error");
                    break;
                }
                continue;
            }

            // special case - use errlogEid UNLESS it's a Manual Gard
            const uint32_t l_errlogEid =
                (l_gardRecord.iv_errorType == GARD_User_Manual) ?
                    DECONFIGURED_BY_MANUAL_GARD : l_gardRecord.iv_errlogEid;

            // all ok - do the work
            HWAS_MUTEX_LOCK(iv_mutex);

            // Deconfigure the Target
            // don't need to check ATTR_DECONFIG_GARDABLE -- if we get
            //  here, it's because of a gard record on this target
            _deconfigureTarget(*l_pTarget, l_errlogEid);

            // Deconfigure other Targets by association
            _deconfigureByAssoc(*l_pTarget, l_errlogEid);

            HWAS_MUTEX_UNLOCK(iv_mutex);

            //If the errlogEid is already in the errLogEidList, then
            //don't need to log it again as a single error log can
            //create multiple guard records and we only need to repost
            //it once.
            std::vector<uint32_t>::iterator low =
                std::lower_bound(errlLogEidList.begin(),
                errlLogEidList.end(), l_errlogEid);
            if((low == errlLogEidList.end()) || ((*low) != l_errlogEid))
            {
                errlLogEidList.insert(low, l_errlogEid);
                l_pErr = platReLogGardError(l_gardRecord);
                if (l_pErr)
                {
                    HWAS_ERR("platReLogGardError returned an error");
                    break;
                }
            }

            l_pErr = platLogEvent(l_pTarget, GARD_APPLIED);
            if (l_pErr)
            {
                HWAS_ERR("platLogEvent returned an error");
                break;
            }
        } // for

        if (l_pErr)
        {
            break;
        }

        if (iv_XABusEndpointDeconfigured)
        {
            // Check if Abus decofigures should be considered in algorithm
            bool l_doAbusDeconfig = pSys->getAttr<ATTR_DO_ABUS_DECONFIG>();
            // Get all functional nodes
            TargetHandleList l_funcNodes;
            getEncResources(l_funcNodes, TYPE_NODE, UTIL_FILTER_FUNCTIONAL);

            for (TargetHandleList::const_iterator
                 l_nodesIter = l_funcNodes.begin();
                 l_nodesIter != l_funcNodes.end();
                 ++l_nodesIter)
            {
                l_pErr = _invokeDeconfigureAssocProc(*l_nodesIter,
                                                      l_doAbusDeconfig);
                if (l_pErr)
                {
                    HWAS_ERR("Error from _invokeDeconfigureAssocProc");
                    break;
                }
                // Set for deconfigure algorithm to run on every node even if
                // no buses deconfigured (needed for multi-node systems)
                setXABusEndpointDeconfigured(true);
            }
            setXABusEndpointDeconfigured(false);
        }
    }
    while (0);

    return l_pErr;
} // deconfigureTargetsFromGardRecordsForIpl

//******************************************************************************
errlHndl_t DeconfigGard::processFieldCoreOverride()
{
    HWAS_DBG("Process Field Core Override FCO");
    errlHndl_t l_pErr = NULL;

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
            uint32_t l_fco = 0;
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

            HWAS_INF("FCO: node %.8X: value %d",
                get_huid(pNode), l_fco);

            // find all functional child PROC targets
            TargetHandleList pProcList;
            getChildAffinityTargets(pProcList, pNode,
                    CLASS_CHIP, TYPE_PROC, true);

            // sort the list by ATTR_HUID to ensure that we
            //  start at the same place each time
            std::sort(pProcList.begin(), pProcList.end(),
                    compareTargetHuid);

            // create list for restrictEXunits() function
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
                //  restrict the number of EX units
                HWAS_DBG("pProc %.8X - pushing to proclist",
                    get_huid(pProc));
                l_procEntry.target = pProc;
                l_procEntry.group = 0;
                l_procEntry.procs = pProcList.size();
                l_procEntry.maxEXs = l_fco;
                l_procRestrictList.push_back(l_procEntry);
            } // for pProc_it

            // restrict the EX units; units turned off are marked
            //  present=true, functional=false, and marked with the
            //  appropriate deconfigure code.
            HWAS_INF("FCO: calling restrictEXunits with %d entries",
                    l_procRestrictList.size());
            l_pErr = restrictEXunits(l_procRestrictList,
                        true, DECONFIGURED_BY_FIELD_CORE_OVERRIDE);
            if (l_pErr)
            {
                break;
            }
        } // for pNode_it
    }
    while (0);

    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::clearGardRecords(
    const Target * const i_pTarget)
{
    errlHndl_t l_pErr = platClearGardRecords(i_pTarget);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::getGardRecords(
    const Target * const i_pTarget,
    GardRecords_t & o_records)
{
    errlHndl_t l_pErr = platGetGardRecords(i_pTarget, o_records);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::deconfigureTarget(
        Target & i_target,
        const uint32_t i_errlEid,
        bool *o_targetDeconfigured,
        const DeconfigureRuntime i_runTimeDeconfigRule)
{
    HWAS_DBG("Deconfigure Target");
    errlHndl_t l_pErr = NULL;

    do
    {
        // Do not deconfig Target if we're NOT being asked to force AND
        //   the is System is at runtime
        if ((i_runTimeDeconfigRule == NOT_AT_RUNTIME) &&
                platSystemIsAtRuntime())
        {
            HWAS_INF("Skipping deconfigureTarget: at Runtime; target %.8X",
                get_huid(&i_target));
            break;
        }

        // just to make sure that we haven't missed anything in development
        //  AT RUNTIME: we should only be called to deconfigure these types.
        if (i_runTimeDeconfigRule != NOT_AT_RUNTIME)
        {
            TYPE target_type = i_target.getAttr<ATTR_TYPE>();
            // TODO RTC 88471: use attribute vs hardcoded list.
            if (!((target_type == TYPE_MEMBUF) ||
                  (target_type == TYPE_NX) ||
                  (target_type == TYPE_EX) ||
                  (target_type == TYPE_PORE)))
            {
                HWAS_INF("Skipping deconfigureTarget: atRuntime with unexpected target %.8X type %d -- SKIPPING",
                    get_huid(&i_target), target_type);
                break;
            }
        }

        const ATTR_DECONFIG_GARDABLE_type lDeconfigGardable =
                i_target.getAttr<ATTR_DECONFIG_GARDABLE>();
        const uint8_t lPresent =
                i_target.getAttr<ATTR_HWAS_STATE>().present;
        if (!lDeconfigGardable || !lPresent)
        {
            // Target is not Deconfigurable. Create an error
            HWAS_ERR("Target %.8X not Deconfigurable (ATTR_DECONFIG_GARDABLE=%d, present=%d)",
                get_huid(&i_target), lDeconfigGardable, lPresent);

            /*@
             * @errortype
             * @moduleid          HWAS::MOD_DECONFIG_GARD
             * @reasoncode        HWAS::RC_TARGET_NOT_DECONFIGURABLE
             * @devdesc           Attempt to deconfigure a target that is not
             *                    deconfigurable
             *                    (not DECONFIG_GARDABLE or not present)
             * @userdata1[00:31]  HUID of input target
             * @userdata1[32:63]  GARD errlog EID
             * @userdata2[00:31]  ATTR_DECONFIG_GARDABLE
             * @userdata2[32:63]  ATTR_HWAS_STATE.present

             */
            const uint64_t userdata1 =
                (static_cast<uint64_t>(get_huid(&i_target)) << 32) | i_errlEid;
            const uint64_t userdata2 =
                (static_cast<uint64_t>(lDeconfigGardable) << 32) | lPresent;
            l_pErr = hwasError(
                ERRL_SEV_INFORMATIONAL,
                HWAS::MOD_DECONFIG_GARD,
                HWAS::RC_TARGET_NOT_DECONFIGURABLE,
                userdata1, userdata2);
            break;
        }

        // all ok - do the work
        HWAS_MUTEX_LOCK(iv_mutex);

        // Deconfigure the Target
        _deconfigureTarget(i_target, i_errlEid, o_targetDeconfigured,
                i_runTimeDeconfigRule);

        // Deconfigure other Targets by association
        _deconfigureByAssoc(i_target, i_errlEid, i_runTimeDeconfigRule);

        HWAS_MUTEX_UNLOCK(iv_mutex);
    }
    while (0);

    return l_pErr;
} // deconfigureTarget

//******************************************************************************
void DeconfigGard::registerDeferredDeconfigure(
        const Target & i_target,
        const uint32_t i_errlEid)
{
    HWAS_INF("registerDeferredDeconfigure Target %.8X, errlEid 0x%X",
            get_huid(&i_target), i_errlEid);

    // Create a Deconfigure Record
    HWAS_MUTEX_LOCK(iv_mutex);

    _createDeconfigureRecord(i_target, i_errlEid);

    HWAS_MUTEX_UNLOCK(iv_mutex);
}

//******************************************************************************
errlHndl_t DeconfigGard::_getDeconfigureRecords(
    const Target * const i_pTarget,
    DeconfigureRecords_t & o_records)
{
    HWAS_DBG("Get Deconfigure Record(s)");
    o_records.clear();

    HWAS_MUTEX_LOCK(iv_mutex);
    DeconfigureRecordsCItr_t l_itr = iv_deconfigureRecords.begin();

    if (i_pTarget == NULL)
    {
        HWAS_INF("Getting all %d Deconfigure Records",
                 iv_deconfigureRecords.size());

        for (; l_itr != iv_deconfigureRecords.end(); ++l_itr)
        {
            o_records.push_back(*l_itr);
        }
    }
    else
    {
        // Look for a Deconfigure Record for the specified Target (there can
        // only be one record)
        for (; l_itr != iv_deconfigureRecords.end(); ++l_itr)
        {
            if ((*l_itr).iv_target == i_pTarget)
            {
                HWAS_INF("Getting Deconfigure Record for %.8X",
                               get_huid(i_pTarget));
                o_records.push_back(*l_itr);
                break;
            }
        }

        if (l_itr == iv_deconfigureRecords.end())
        {
            HWAS_INF("Did not find a Deconfigure Record for %.8X",
                           get_huid(i_pTarget));
        }
    }

    HWAS_MUTEX_UNLOCK(iv_mutex);
    return NULL;
}


//******************************************************************************
/**
 * @brief       simple helper fn to find and return the MCS which is paired to
 *              the input MCS
 *
 * @param[in]   i_startMcs      pointer to starting MCS target
 *
 * @return      Target          Pointer to Partner MCS of i_startMcs
 *
 */
Target * findPartnerForMcs(const Target *i_startMcs)
{
    // Get CHIP_UNIT of the input MCS (0..7)
    const ATTR_CHIP_UNIT_type startMcsUnit = i_startMcs->getAttr<ATTR_CHIP_UNIT>();
    // Declare partner MCS CHIP_UNIT
    ATTR_CHIP_UNIT_type partnerMcsUnit = 0;

    // If CHIP_UNIT is even, its partner will be the next MCS
    if (!(startMcsUnit % 2))
    {
        partnerMcsUnit = startMcsUnit + 1;
    }
    // else, partner will be the previous MCS
    else
    {
        partnerMcsUnit = startMcsUnit - 1;
    }

    // Get parent proc of i_startMcs to get other child MCSs
    const Target *l_proc = getParentChip(i_startMcs);
    HWAS_INF("findPartnerForMcs MCS %.8X (%d) under proc %.8X",
                 get_huid(i_startMcs), startMcsUnit, get_huid(l_proc));

    // Retrieve MCS target whose CHIP_UNIT matches partnerMcsUnit
    TargetHandleList l_funcMcsList;
    PredicateCTM predMcs(CLASS_UNIT, TYPE_MCS);
    PredicateIsFunctional isFunctional;
    PredicateAttrVal<ATTR_CHIP_UNIT> unitPosAttr(partnerMcsUnit);
    PredicatePostfixExpr checkExpr;
    checkExpr.push(&predMcs).push(&isFunctional).
              push(&unitPosAttr).And().And();
    targetService().getAssociated(l_funcMcsList, l_proc,
        TargetService::CHILD_BY_AFFINITY, TargetService::IMMEDIATE,
        &checkExpr);

    // List should either be empty or contain one element
    HWAS_ASSERT((l_funcMcsList.size() <= 1),
        "HWAS _deconfigureByAssoc: pParentMcsList > 1");

    // If no partner found (partner MCS already deconfigured)
    if (l_funcMcsList.empty())
    {
        HWAS_INF("findPartnerMcs: Partner for MCS %.8X was not found in"
                 " functional list. Returning NULL",
                 get_huid(i_startMcs));
        return NULL;
    }
    else
    {
        HWAS_INF("findPartnerForMcs found partner: MCS %.8X (%d)",
                 get_huid(l_funcMcsList[0]),
                 l_funcMcsList[0]->getAttr<ATTR_CHIP_UNIT>());
        return l_funcMcsList[0];
    }
} // findPartnerForMcs

//******************************************************************************

errlHndl_t DeconfigGard::deconfigureAssocProc()
{
    HWAS_INF("Deconfiguring chip resources "
             "based on fabric bus deconfigurations");

    HWAS_MUTEX_LOCK(iv_mutex);
    // call _invokeDeconfigureAssocProc() to obtain state of system,
    // call algorithm function, and then deconfigure targets
    // based on output
    errlHndl_t l_pErr = _invokeDeconfigureAssocProc();
    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::_invokeDeconfigureAssocProc(
            TARGETING::ConstTargetHandle_t i_node,
            bool i_doAbusDeconfig)
{
    HWAS_INF("Preparing data for _deconfigureAssocProc");
    // Return error
    errlHndl_t l_pErr = NULL;

    // Define vector of ProcInfo structs to be used by
    // _deconfigAssocProc algorithm. Declared here so
    // "delete" can be used outside of do {...} while(0)
    ProcInfoVector l_procInfo;

    do
    {
        // If flag indicating deconfigured bus endpoints is not set,
        // then there's no work for _invokeDeconfigureAssocProc to do
        // as this implies there are no deconfigured endpoints or
        // processors.
        if (!(iv_XABusEndpointDeconfigured))
        {
            HWAS_INF("_invokeDeconfigureAssocProc: No deconfigured x/a"
                     " bus endpoints. Deconfiguration of "
                     "associated procs unnecessary.");
            break;
        }

        // Clear flag as this function is called multiple times
        iv_XABusEndpointDeconfigured = false;

        // Get top 'starting' level target - use top level target if no
        // i_node given (hostboot)
        Target *pTop;
        if (i_node == NULL)
        {
            HWAS_INF("_invokeDeconfigureAssocProc: i_node not specified");
            targetService().getTopLevelTarget(pTop);
            HWAS_ASSERT(pTop, "_invokeDeconfigureAssocProc: no TopLevelTarget");
        }
        else
        {
            HWAS_INF("_invokeDeconfigureAssocProc: i_node 0x%X specified",
                     i_node->getAttr<ATTR_HUID>());
            pTop = const_cast<Target *>(i_node);
        }

        // Define and populate vector of procs
        // Define predicate
        PredicateCTM predProc(CLASS_CHIP, TYPE_PROC);
        PredicateHwas predPres;
        predPres.present(true);

        // Populate vector
        TargetHandleList l_procs;
        targetService().getAssociated(l_procs,
                                      pTop,
                                      TargetService::CHILD,
                                      TargetService::ALL,
                                      &predProc);

        // Sort by HUID
        std::sort(l_procs.begin(),
                  l_procs.end(), compareTargetHuid);

        // General predicate to determine if target is functional
        PredicateIsFunctional isFunctional;

        // Define and populate vector of present A bus endpoint chiplets and
        // all X bus endpoint chiplets
        PredicateCTM predXbus(CLASS_UNIT, TYPE_XBUS);
        PredicateCTM predAbus(CLASS_UNIT, TYPE_ABUS);
        PredicatePostfixExpr busses;
        busses.push(&predAbus).push(&predPres).And().push(&predXbus).Or();

        // Iterate through procs and populate l_procInfo vector with system
        // information regarding procs to be used by _deconfigAssocProc
        // algorithm.
        ProcInfoVector l_procInfo;
        for (TargetHandleList::const_iterator
             l_procsIter = l_procs.begin();
             l_procsIter != l_procs.end();
             ++l_procsIter)
        {
            ProcInfo l_ProcInfo = ProcInfo();
            // Iterate through present procs and populate structs in l_procInfo
            // Target pointer
            l_ProcInfo.iv_pThisProc =
                *l_procsIter;
            // HUID
            l_ProcInfo.procHUID =
                (*l_procsIter)->getAttr<ATTR_HUID>();
            // FABRIC_NODE_ID
            l_ProcInfo.procFabricNode =
                (*l_procsIter)->getAttr<ATTR_FABRIC_NODE_ID>();
            // FABRIC_CHIP_ID
            l_ProcInfo.procFabricChip =
                (*l_procsIter)->getAttr<ATTR_FABRIC_CHIP_ID>();
            // HWAS state
            l_ProcInfo.iv_deconfigured =
                !(isFunctional(*l_procsIter));
            // iv_masterCapable - this includes both master and alternate master
            // This is done to ensure that both the master and alt master don't
            // get deconfigured in _deconfigAssocProc()
            if ( (*l_procsIter)->getAttr<ATTR_PROC_MASTER_TYPE>() ==
                 PROC_MASTER_TYPE_NOT_MASTER)
            {
                l_ProcInfo.iv_masterCapable = false;
            }
            else
            {
                l_ProcInfo.iv_masterCapable = true;
            }
            l_procInfo.push_back(l_ProcInfo);
        }
        // Iterate through l_procInfo and populate child bus endpoint
        // chiplet information
        for (ProcInfoVector::iterator
             l_procInfoIter = l_procInfo.begin();
             l_procInfoIter != l_procInfo.end();
             ++l_procInfoIter)
        {
            // Populate vector of bus endpoints associated with this proc
            TargetHandleList l_busChiplets;
            targetService().getAssociated(l_busChiplets,
                                         (*l_procInfoIter).iv_pThisProc,
                                         TargetService::CHILD,
                                         TargetService::IMMEDIATE,
                                         &busses);
            // Sort by HUID
            std::sort(l_busChiplets.begin(),
                l_busChiplets.end(), compareTargetHuid);
            // iv_pA/XProcs[] and iv_A/XDeconfigured[] indexes
            uint8_t xBusIndex = 0;
            uint8_t aBusIndex = 0;

            // Iterate through bus endpoint chiplets
            for (TargetHandleList::const_iterator
                 l_busIter = l_busChiplets.begin();
                 l_busIter != l_busChiplets.end();
                 ++l_busIter)
            {
                // Declare peer endpoint target
                const Target * l_pTarget = *l_busIter;
                // Get peer endpoint target
                const Target * l_pDstTarget = l_pTarget->
                              getAttr<ATTR_PEER_TARGET>();
                // Only interested in endpoint chiplets which lead to a
                // present proc:
                // If no peer for this endpoint or peer endpoint
                // is not present, continue
                if ((!l_pDstTarget) ||
                    (!(l_pDstTarget->getAttr<ATTR_HWAS_STATE>().present)))
                {
                    continue;
                }
                // Chiplet has a valid (present) peer
                // Handle iv_pA/XProcs[]:
                // Define target for peer proc
                const Target* l_pPeerProcTarget;
                // Get parent chip from xbus chiplet
                l_pPeerProcTarget = getParentChip(l_pDstTarget);
                // Find matching ProcInfo struct
                for (ProcInfoVector::iterator
                     l_matchProcInfoIter = l_procInfo.begin();
                     l_matchProcInfoIter != l_procInfo.end();
                     ++l_matchProcInfoIter)
                {
                    // If Peer proc target matches this ProcInfo struct's
                    // Identifier target
                    if (l_pPeerProcTarget ==
                        (*l_matchProcInfoIter).iv_pThisProc)
                    {
                        // Update struct of current proc to point to this
                        // struct, and also handle iv_A/XDeconfigured[]
                        // and increment appropriate index:
                        if (TYPE_XBUS == (*l_busIter)->getAttr<ATTR_TYPE>())
                        {
                            (*l_procInfoIter).iv_pXProcs[xBusIndex] =
                                &(*l_matchProcInfoIter);
                            // HWAS state
                            (*l_procInfoIter).iv_XDeconfigured[xBusIndex] =
                                !(isFunctional(*l_busIter));
                            xBusIndex++;
                        }
                        // If subsystem owns abus deconfigs consider them
                        else if (i_doAbusDeconfig &&
                                TYPE_ABUS == (*l_busIter)->getAttr<ATTR_TYPE>())
                        {
                            (*l_procInfoIter).iv_pAProcs[aBusIndex] =
                                &(*l_matchProcInfoIter);
                            // HWAS state
                            (*l_procInfoIter).iv_ADeconfigured[aBusIndex] =
                               !(isFunctional(*l_busIter));
                            aBusIndex++;
                        }
                        break;
                    }
                }
            }
        }

        // call _deconfigureAssocProc() to run deconfig algorithm
        // based on current state of system obtained above
        l_pErr = _deconfigureAssocProc(l_procInfo);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
            break;
        }

        // Iterate through l_procInfo and deconfigure any procs
        // which _deconfigureAssocProc marked for deconfiguration
        for (ProcInfoVector::const_iterator
             l_procInfoIter = l_procInfo.begin();
             l_procInfoIter != l_procInfo.end();
             ++l_procInfoIter)
        {
            if ((*l_procInfoIter).iv_deconfigured &&
                (isFunctional((*l_procInfoIter).iv_pThisProc)))
            {
                // Deconfigure marked procs
                HWAS_INF("_invokeDeconfigureAssocProc is "
                                "deconfiguring proc: %.8X",
                    get_huid((*l_procInfoIter).iv_pThisProc));
                _deconfigureTarget(*(*l_procInfoIter).
                                iv_pThisProc, DECONFIGURED_BY_BUS_DECONFIG);
                _deconfigureByAssoc(*(*l_procInfoIter).
                                iv_pThisProc, DECONFIGURED_BY_BUS_DECONFIG);
            }
        }
    }while(0);

    return l_pErr;
}

//******************************************************************************

void DeconfigGard::_deconfigureByAssoc(
        Target & i_target,
        const uint32_t i_errlEid,
        const DeconfigureRuntime i_runTimeDeconfigRule)
{
    HWAS_INF("_deconfigureByAssoc for %.8X (i_runTimeDeconfigRule %d)",
            get_huid(&i_target), i_runTimeDeconfigRule);

    // some common variables used below
    TargetHandleList pChildList;
    PredicateIsFunctional isFunctional;

    // note - ATTR_DECONFIG_GARDABLE is NOT checked for all 'by association'
    // deconfigures, as that attribute is only for direct deconfigure requests.

    // find all CHILD targets and deconfigure them
    targetService().getAssociated(pChildList, &i_target,
        TargetService::CHILD, TargetService::ALL, &isFunctional);
    for (TargetHandleList::iterator pChild_it = pChildList.begin();
            pChild_it != pChildList.end();
            ++pChild_it)
    {
        TargetHandle_t pChild = *pChild_it;

        HWAS_INF("_deconfigureByAssoc CHILD: %.8X", get_huid(pChild));
        _deconfigureTarget(*pChild, i_errlEid, NULL,
                i_runTimeDeconfigRule);
        // Deconfigure other Targets by association
        _deconfigureByAssoc(*pChild, i_errlEid, i_runTimeDeconfigRule);
    } // for CHILD

    if (i_runTimeDeconfigRule == NOT_AT_RUNTIME)
    {
        // if the rule is NOT_AT_RUNTIME and we got here, then we are
        // not at runtime.
        // only do these 'by association' checks if we are NOT at runtime
        // reason is, we're not really deconfigureing anything, we're just
        // marking them as non-functional. we only want to do that for the
        // desired target and it's CHILD

        // find all CHILD_BY_AFFINITY targets and deconfigure them
        targetService().getAssociated(pChildList, &i_target,
            TargetService::CHILD_BY_AFFINITY, TargetService::ALL,
            &isFunctional);
        for (TargetHandleList::iterator pChild_it = pChildList.begin();
                pChild_it != pChildList.end();
                ++pChild_it)
        {
            TargetHandle_t pChild = *pChild_it;

            HWAS_INF("_deconfigureByAssoc CHILD_BY_AFFINITY: %.8X",
                    get_huid(pChild));
            _deconfigureTarget(*pChild, i_errlEid, NULL,
                    i_runTimeDeconfigRule);
            // Deconfigure other Targets by association
            _deconfigureByAssoc(*pChild, i_errlEid, i_runTimeDeconfigRule);
        } // for CHILD_BY_AFFINITY

        // Handles bus endpoint (TYPE_XBUS, TYPE_ABUS, TYPE_PSI) and
        // memory (TYPE_MEMBUF, TYPE_MBA, TYPE_DIMM)
        // deconfigureByAssociation rules
        switch (i_target.getAttr<ATTR_TYPE>())
        {
            case TYPE_MEMBUF:
            {
                //  get parent MCS
                TargetHandleList pParentMcsList;
                getParentAffinityTargetsByState(pParentMcsList, &i_target,
                        CLASS_UNIT, TYPE_MCS, UTIL_FILTER_PRESENT);
                HWAS_ASSERT((pParentMcsList.size() == 1),
                    "HWAS _deconfigureByAssoc: pParentMcsList > 1");
                const Target *l_parentMcs = pParentMcsList[0];

                // If parent is functional, deconfigure it
                if (isFunctional(l_parentMcs))
                {
                    // deconfigure the parent
                    HWAS_INF("_deconfigureByAssoc MEMBUF parent MCS: %.8X",
                        get_huid(l_parentMcs));
                    _deconfigureTarget(const_cast<Target &> (*l_parentMcs),
                        i_errlEid, NULL, i_runTimeDeconfigRule);
                    _deconfigureByAssoc(const_cast<Target &> (*l_parentMcs),
                        i_errlEid, i_runTimeDeconfigRule);
                }

                Target *pSys;
                targetService().getTopLevelTarget(pSys);
                HWAS_ASSERT(pSys, "HWAS _deconfigureByAssoc: no TopLevelTarget");

                // done if not in interleaved mode
                if (!pSys->getAttr<ATTR_ALL_MCS_IN_INTERLEAVING_GROUP>())
                {
                    break;
                }
                // if paired mode (interleaved)
                //      deconfigure paired MCS and MEMBUF (Centaur)
                // find paired MCS / MEMBUF (Centaur)
                const Target *l_partnerMcs = findPartnerForMcs(l_parentMcs);

                // If partner MCS is functional (NULL otherwise)
                if (l_partnerMcs)
                {
                    // deconfigure the paired MCS
                    HWAS_INF("_deconfigureByAssoc MCS (& MEMBUF) paired: %.8X",
                        get_huid(l_partnerMcs));
                    _deconfigureTarget(const_cast<Target &> (*l_partnerMcs),
                        i_errlEid, NULL,i_runTimeDeconfigRule);
                    _deconfigureByAssoc(const_cast<Target &> (*l_partnerMcs),
                        i_errlEid,i_runTimeDeconfigRule);
                }
                break;
            } // TYPE_MEMBUF

            case TYPE_MBA:
            {
                // get parent MEMBUF (Centaur)
                const Target *l_parentMembuf = getParentChip(&i_target);

                // get children DIMM that are functional
                TargetHandleList pDimmList;
                getChildAffinityTargetsByState(pDimmList,l_parentMembuf,
                                               CLASS_LOGICAL_CARD,
                                               TYPE_DIMM,
                                               UTIL_FILTER_FUNCTIONAL);

                // if parent MEMBUF (Centaur) has no functional memory
                if (pDimmList.empty())
                {
                    // deconfigure parent MEMBUF (Centaur)
                    HWAS_INF("_deconfigureByAssoc MEMBUF parent with no memory: %.8X",
                        get_huid(l_parentMembuf));
                    _deconfigureTarget(const_cast<Target &> (*l_parentMembuf),
                        i_errlEid, NULL, i_runTimeDeconfigRule);
                    _deconfigureByAssoc(const_cast<Target &> (*l_parentMembuf),
                        i_errlEid, i_runTimeDeconfigRule);

                    // and we're done, so break;
                    break;
                }

                // parent MEMBUF still has functional memory
                Target *pSys;
                targetService().getTopLevelTarget(pSys);
                HWAS_ASSERT(pSys, "HWAS _deconfigureByAssoc: no TopLevelTarget");

                // done if not in interleaved mode
                if (!pSys->getAttr<ATTR_ALL_MCS_IN_INTERLEAVING_GROUP>())
                {
                    break;
                }

                // we need to make sure that MBA memory is balanced.

                // find parent MCS
                TargetHandleList pParentMcsList;
                getParentAffinityTargetsByState(pParentMcsList, l_parentMembuf,
                        CLASS_UNIT, TYPE_MCS, UTIL_FILTER_FUNCTIONAL);
                HWAS_ASSERT((pParentMcsList.size() <= 1),
                    "HWAS _deconfigureByAssoc: pParentMcsList > 1");

                if (pParentMcsList.empty())
                {
                    // MCS is already deconfigured, we're done
                    break;
                }

                // MEMBUF only has 1 parent
                const Target *l_parentMcs = pParentMcsList[0];

                // find paired MCS / MEMBUF (Centaur)
                const Target *l_partnerMcs = findPartnerForMcs(l_parentMcs);

                // If partner MCS is non-functional
                // (findPartnerForMcs returned NULL)
                if (!l_partnerMcs)
                {
                    // We're done.
                    break;
                }

                // Obtain MBA targets related to paired MCS
                TargetHandleList pMbaList;
                getChildAffinityTargetsByState(pMbaList,l_partnerMcs,
                                               CLASS_UNIT,
                                               TYPE_MBA,
                                               UTIL_FILTER_FUNCTIONAL);

                // Declare list to hold any MBA targets we need to deconfigure
                // as we look for matches.  This list will be used to run
                // the subsequent _deconfigureByAssoc
                TargetHandleList l_deconfigList;

                // Now we will check the memory size of each MBA target
                // of the paired MCS.  If an MBAs memory size matches that
                // of the original MBA (i_target), then we will deconfigure it
                // If ATTR_EFF_DIMM_SIZE has not been set yet (returns 0), then
                // we will deconfigure the MBA whose position matches that of
                // the original.

                // how much memory does this MBA have
                ATTR_EFF_DIMM_SIZE_type l_dimmSize;
                i_target.tryGetAttr<ATTR_EFF_DIMM_SIZE>(l_dimmSize);
                const uint64_t l_mbaDimmSize =
                        l_dimmSize[0][0] + l_dimmSize[0][1] +
                        l_dimmSize[1][0] + l_dimmSize[1][1];

                if (l_mbaDimmSize == 0)
                {
                    // before this attribute has been set
                    HWAS_INF("ATTR_EFF_DIMMSIZE not set (returned 0)."
                        " Deconfiguring same-position MBA of paried MCS.");

                    // Get this MBAs position
                    const ATTR_CHIP_UNIT_type l_mbaPos =
                        i_target.getAttr<ATTR_CHIP_UNIT>();

                    // Assumes 2 MBA per MEMBUF. if this changes, then instead
                    // of '1', count the number of MBAs under this MEMBUF and
                    // use that as the comparison.
                    if (pMbaList.size() != 1) // this != myMbaCount
                    {
                        // Iterate through MBAs looking for position match
                        for (TargetHandleList::iterator
                                pMba_it = pMbaList.begin();
                                pMba_it != pMbaList.end();
                                ++pMba_it)
                        {
                            // Capture current MBA
                            TargetHandle_t pMba = *pMba_it;

                            // If position matches
                            if (l_mbaPos == pMba->getAttr<ATTR_CHIP_UNIT>())
                            {
                                // Deconfigure it
                                HWAS_INF("_deconfigureByAssoc MBA matched: %.8X",
                                    get_huid(pMba));
                                _deconfigureTarget(*pMba, i_errlEid,
                                    NULL, i_runTimeDeconfigRule);
                                l_deconfigList.push_back(pMba);
                                break; // only need to do 1 MBA - we're done.
                            }
                        }// 2 functional MBAs
                    }// size != 1
                }// ATTR_EFF_DIMM_SIZE not set
                else
                {
                    // ATTR_EFF_DIMM_SIZE was set
                    if (pMbaList.size() != 1) // this != myMbaCount
                    {
                        // unbalanced, so lets find one to deconfigure
                        for (TargetHandleList::iterator
                                pMba_it = pMbaList.begin();
                                pMba_it != pMbaList.end();
                                ++pMba_it)
                        {
                            TargetHandle_t pMba = *pMba_it;
                            pMba->tryGetAttr<ATTR_EFF_DIMM_SIZE>(l_dimmSize);
                            const uint64_t l_thisDimmSize =
                                l_dimmSize[0][0] + l_dimmSize[0][1] +
                                l_dimmSize[1][0] + l_dimmSize[1][1];

                            // if this MBA matches, deconfigure it.
                            if (l_mbaDimmSize == l_thisDimmSize)
                            {
                                HWAS_INF("_deconfigureByAssoc MBA matched: %.8X",
                                    get_huid(pMba));
                                _deconfigureTarget(*pMba, i_errlEid,
                                    NULL, i_runTimeDeconfigRule);
                                l_deconfigList.push_back(pMba);
                                break; // only need to do 1 MBA - we're done.
                            }
                        } // for MBA
                    } // if 2 functional MBA
                }// else

                // now loop thru and do the ByAssoc deconfig for each of the
                // MBA targets. this should get the CHILD associations, but
                // won't cause any pair deconfigs, since we coverered that
                // already.
                for (TargetHandleList::iterator
                        pMba_it = l_deconfigList.begin();
                        pMba_it != l_deconfigList.end();
                        ++pMba_it)
                {
                    TargetHandle_t pMba = *pMba_it;
                    HWAS_INF("_deconfigureByAssoc MBA matched (bA): %.8X",
                        get_huid(pMba));
                    _deconfigureByAssoc(*pMba, i_errlEid,i_runTimeDeconfigRule);
                } // for
                break;
            } // TYPE_MBA

            case TYPE_DIMM:
            {
                //  get deconfigure parent MBA
                TargetHandleList pParentMbaList;
                getParentAffinityTargets(pParentMbaList, &i_target,
                        CLASS_UNIT, TYPE_MBA, true /*functional*/);
                HWAS_ASSERT((pParentMbaList.size() <= 1),
                    "HWAS _deconfigureByAssoc: pParentMbaList > 1");

                // if parent MBA hasn't already been deconfigured
                if (!pParentMbaList.empty())
                {
                    const Target *l_parentMba = pParentMbaList[0];
                    HWAS_INF("_deconfigureByAssoc DIMM parent MBA: %.8X",
                        get_huid(l_parentMba));
                    _deconfigureTarget(const_cast<Target &> (*l_parentMba),
                        i_errlEid, NULL, i_runTimeDeconfigRule);
                    _deconfigureByAssoc(const_cast<Target &> (*l_parentMba),
                        i_errlEid, i_runTimeDeconfigRule);
                }
                break;
            } // TYPE_DIMM

            // If target is a bus endpoint, deconfigure its peer
            case TYPE_XBUS:
            case TYPE_ABUS:
            case TYPE_PSI:
            {
                // Get peer endpoint target
                const Target * l_pDstTarget = i_target.
                              getAttr<ATTR_PEER_TARGET>();
                // If target is valid
                if (l_pDstTarget)
                {
                    // Deconfigure peer endpoint
                    HWAS_INF("_deconfigureByAssoc BUS Peer: %.8X",
                        get_huid(l_pDstTarget));
                    _deconfigureTarget(const_cast<Target &> (*l_pDstTarget),
                                       i_errlEid, NULL,
                                       i_runTimeDeconfigRule);
                }
                break;
            } // TYPE_XBUS, TYPE_ABUS
            case TYPE_PORE:
            {
                // Get parent proc target of PORE
                const Target * l_pParentProc = getParentChip(&i_target);
                // Deconfigure parent proc
                HWAS_INF("deconfigByAssoc parent proc: %.8X",
                    get_huid(l_pParentProc));
                _deconfigureTarget(const_cast<Target &> (*l_pParentProc),
                                   i_errlEid, NULL,
                                   i_runTimeDeconfigRule);
                _deconfigureByAssoc(const_cast<Target &> (*l_pParentProc),
                                    i_errlEid, i_runTimeDeconfigRule);
                break;
            } // TYPE_PORE
            default:
                // no action
            break;
        } // switch
    } // !i_Runkime

    HWAS_DBG("_deconfigureByAssoc exiting: %.8X", get_huid(&i_target));
} // _deconfigByAssoc

//******************************************************************************
void DeconfigGard::_deconfigureTarget(
        Target & i_target,
        const uint32_t i_errlEid,
        bool *o_targetDeconfigured,
        const DeconfigureRuntime i_runTimeDeconfigRule)
{
    HWAS_INF("Deconfiguring Target %.8X, errlEid 0x%X",
            get_huid(&i_target), i_errlEid);

    // Set the Target state to non-functional. The assumption is that it is
    // not possible for another thread (other than deconfigGard) to be
    // updating HWAS_STATE concurrently.
    HwasState l_state = i_target.getAttr<ATTR_HWAS_STATE>();

    // if the rule is DUMP_AT_RUNTIME and we got here, then we are at runtime.
    if (i_runTimeDeconfigRule == DUMP_AT_RUNTIME)
    {
        l_state.dumpfunctional = 1;
    }
    else
    {
        l_state.dumpfunctional = 0;
    }

    if (!l_state.functional)
    {
        HWAS_DBG(
        "Target HWAS_STATE already has functional=0; deconfiguredByEid=0x%X",
                l_state.deconfiguredByEid);
    }
    else
    {
        HWAS_INF(
        "Setting Target HWAS_STATE: functional=0, deconfiguredByEid=0x%X",
            i_errlEid);
        l_state.functional = 0;

        l_state.deconfiguredByEid = i_errlEid;
        i_target.setAttr<ATTR_HWAS_STATE>(l_state);
        if (o_targetDeconfigured)
        {
            *o_targetDeconfigured = true;
        }

        // if this is a real error, deconfigure
        if (i_errlEid & DECONFIGURED_BY_PLID_MASK)
        {
            // Set RECONFIGURE_LOOP attribute to indicate it was caused by
            // a hw deconfigure
            TARGETING::Target* l_pTopLevel = NULL;
            TARGETING::targetService().getTopLevelTarget(l_pTopLevel);
            TARGETING::ATTR_RECONFIGURE_LOOP_type l_reconfigAttr =
                    l_pTopLevel->getAttr<ATTR_RECONFIGURE_LOOP>();
            // 'OR' values in case of multiple reasons for reconfigure
            l_reconfigAttr |= TARGETING::RECONFIGURE_LOOP_DECONFIGURE;
            l_pTopLevel->setAttr<ATTR_RECONFIGURE_LOOP>(l_reconfigAttr);
        }

        // Do any necessary Deconfigure Actions
        _doDeconfigureActions(i_target);
    }

    // If target being deconfigured is an x/a bus endpoint
    if ((TYPE_XBUS == i_target.getAttr<ATTR_TYPE>()) ||
        (TYPE_ABUS == i_target.getAttr<ATTR_TYPE>()))
    {
        // Set flag indicating x/a bus endpoint deconfiguration
        iv_XABusEndpointDeconfigured = true;
    }

    //HWAS_DBG("Deconfiguring Target %.8X exiting", get_huid(&i_target));
} // _deconfigureTarget

//******************************************************************************
void DeconfigGard::_doDeconfigureActions(Target & i_target)
{
    // Placeholder for any necessary deconfigure actions
}

//******************************************************************************
void DeconfigGard::_createDeconfigureRecord(
    const Target & i_target,
    const uint32_t i_errlEid)
{
    // Look for an existing Deconfigure Record for the Target
    DeconfigureRecordsCItr_t l_itr = iv_deconfigureRecords.begin();

    for (; l_itr != iv_deconfigureRecords.end(); ++l_itr)
    {
        if ((*l_itr).iv_target == &i_target)
        {
            HWAS_DBG("Not creating Deconfigure Record, one exists errlEid 0x%X",
                (*l_itr).iv_errlogEid);
            break;
        }
    }

    // didn't find a match
    if (l_itr == iv_deconfigureRecords.end())
    {
        // Create a DeconfigureRecord
        HWAS_INF("Creating a Deconfigure Record");

        DeconfigureRecord l_record;
        l_record.iv_target = &i_target;
        l_record.iv_errlogEid = i_errlEid;

        iv_deconfigureRecords.push_back(l_record);
    }
}

//******************************************************************************
void DeconfigGard::clearDeconfigureRecords(
        const Target * const i_pTarget)
{
    if (i_pTarget == NULL)
    {
        HWAS_INF("Clearing all %d Deconfigure Records",
                 iv_deconfigureRecords.size());
        iv_deconfigureRecords.clear();
    }
    else
    {
        // Look for a Deconfigure Record for the specified Target (there can
        // only be one record)
        bool l_foundRecord = false;

        for (DeconfigureRecordsItr_t l_itr = iv_deconfigureRecords.begin();
             l_itr != iv_deconfigureRecords.end(); ++l_itr)
        {
            if ((*l_itr).iv_target == i_pTarget)
            {
                HWAS_INF("Clearing Deconfigure Record for %.8X",
                                get_huid(i_pTarget));
                iv_deconfigureRecords.erase(l_itr);
                l_foundRecord = true;
                break;
            }
        }

        if (!l_foundRecord)
        {
            HWAS_INF("Did not find a Deconfigure Record to clear for %.8X",
                           get_huid(i_pTarget));
        }
    }
}


//******************************************************************************
void DeconfigGard::processDeferredDeconfig()
{
    HWAS_DBG(">processDeferredDeconfig");

    // get all deconfigure records, process them, and delete them.
    HWAS_MUTEX_LOCK(iv_mutex);

    for (DeconfigureRecordsItr_t l_itr = iv_deconfigureRecords.begin();
            l_itr != iv_deconfigureRecords.end();
            ++l_itr)
    {
        // do the deconfigure
        DeconfigureRecord l_record = *l_itr;
        _deconfigureTarget(const_cast<Target &> (*(l_record.iv_target)),
                l_record.iv_errlogEid);
        _deconfigureByAssoc(const_cast<Target &> (*(l_record.iv_target)),
                l_record.iv_errlogEid);
    } // for

    // clear the list - handled them all
    iv_deconfigureRecords.clear();

    HWAS_MUTEX_UNLOCK(iv_mutex);

    HWAS_DBG("<processDeferredDeconfig");
} // processDeferredDeconfig

//******************************************************************************
errlHndl_t DeconfigGard::_deconfigureAssocProc(ProcInfoVector &io_procInfo)
{
    // Defined for possible use in future applications
    errlHndl_t l_errlHdl = NULL;

    do
    {
        // STEP 1:
        // Find master proc and iterate through its bus endpoint chiplets.
        // For any chiplets which are deconfigured, mark peer proc as
        // deconfigured

        // Find master proc
        ProcInfo * l_pMasterProcInfo = NULL;
        for (ProcInfoVector::iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            if ( ((*l_procInfoIter).iv_masterCapable) &&
                 (!(*l_procInfoIter).iv_deconfigured) )
            {
                // Save for subsequent use
                l_pMasterProcInfo = &(*l_procInfoIter);
                // Iterate through bus endpoints, and if deconfigured,
                // mark peer proc to be deconfigured
                for (uint8_t i = 0; i < NUM_A_BUSES; i++)
                {
                    if ((*l_procInfoIter).iv_ADeconfigured[i])
                    {
                        HWAS_INF("deconfigureAssocProc marked proc: "
                                 "%.8X for deconfiguration "
                                 "due to deconfigured abus endpoint "
                                 "on master proc.",
                                 (*l_procInfoIter).iv_pAProcs[i]->procHUID);
                        (*l_procInfoIter).iv_pAProcs[i]->
                                        iv_deconfigured = true;
                    }
                }
                for (uint8_t i = 0; i < NUM_X_BUSES; i++)
                {
                    if ((*l_procInfoIter).iv_XDeconfigured[i])
                    {
                        HWAS_INF("deconfigureAssocProc marked proc: "
                                 "%.8X for deconfiguration "
                                 "due to deconfigured xbus endpoint "
                                 "on master proc.",
                                 (*l_procInfoIter).iv_pXProcs[i]->procHUID);
                        (*l_procInfoIter).iv_pXProcs[i]->
                                        iv_deconfigured = true;
                    }
                }
                break;
            }
        } // STEP 1

        // If no master proc found, abort
        HWAS_ASSERT(l_pMasterProcInfo, "HWAS _deconfigureAssocProc:"
                                       "Master proc not found");

        // STEP 2:
        // Iterate through procs, and mark deconfigured any
        // non-master proc which has more than one bus endpoint
        // chiplet deconfigured
        for (ProcInfoVector::iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // Don't deconfigure master proc
            if ((*l_procInfoIter).iv_masterCapable)
            {
                continue;
            }
            // Don't examine previously marked proc
            if ((*l_procInfoIter).iv_deconfigured)
            {
                continue;
            }
            // Deconfigured bus chiplet counter
            uint8_t deconfigBusCounter = 0;
            // Check and increment counter if A/X bus endpoints found
            // which are deconfigured
            for (uint8_t i = 0; i < NUM_A_BUSES; i++)
            {
                if ((*l_procInfoIter).iv_ADeconfigured[i])
                {
                    // Only increment deconfigBusCounter if peer proc exists
                    //  and is functional
                    if((*l_procInfoIter).iv_pAProcs[i] &&
                      (!(*l_procInfoIter).iv_pAProcs[i]->iv_deconfigured))
                    {
                        deconfigBusCounter++;
                    }
                }
            }
            for (uint8_t i = 0; i < NUM_X_BUSES; i++)
            {
                if ((*l_procInfoIter).iv_XDeconfigured[i])
                {
                    // Only increment deconfigBusCounter if peer proc exists
                    // and is functional
                    if((*l_procInfoIter).iv_pXProcs[i] &&
                      (!(*l_procInfoIter).iv_pXProcs[i]->iv_deconfigured))
                    {
                        deconfigBusCounter++;
                    }
                }
            }
            // If number of endpoints deconfigured is > 1
            if (deconfigBusCounter > 1)
            {
                // Mark current proc to be deconfigured
                HWAS_INF("deconfigureAssocProc marked proc: "
                                 "%.8X for deconfiguration "
                                 "due to %d deconfigured bus endpoints "
                                 "on this proc.",
                                 (*l_procInfoIter).procHUID,
                                  deconfigBusCounter);
                (*l_procInfoIter).iv_deconfigured = true;
            }
        }// STEP 2


        // STEP 3:
        // If a deconfigured bus connects two non-master procs,
        // both of which are in the master-containing logical node,
        // mark proc with higher HUID to be deconfigured.

        // Iterate through procs and check xbus chiplets
        for (ProcInfoVector::iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // Master proc handled in STEP 1
            if ((*l_procInfoIter).iv_masterCapable)
            {
                continue;
            }
            // Don't examine previously marked proc
            if ((*l_procInfoIter).iv_deconfigured)
            {
                continue;
            }
            // If current proc is on master logical node
            if (l_pMasterProcInfo->procFabricNode ==
                (*l_procInfoIter).procFabricNode)
            {
                // Check xbus endpoints
                for (uint8_t i = 0; i < NUM_X_BUSES; i++)
                {
                    // If endpoint deconfigured and endpoint peer proc is
                    // not already marked deconfigured
                    if (((*l_procInfoIter).iv_XDeconfigured[i]) &&
                        (!((*l_procInfoIter).iv_pXProcs[i]->iv_deconfigured)))
                    {
                        // Mark proc with higher HUID to be deconfigured
                        if ((*l_procInfoIter).iv_pXProcs[i]->procHUID >
                            (*l_procInfoIter).procHUID)
                        {
                            HWAS_INF("deconfigureAssocProc marked remote proc:"
                                 " %.8X for deconfiguration "
                                 "due to higher HUID than peer "
                                 "proc on same master-containing logical "
                                 "node.",
                                 (*l_procInfoIter).iv_pXProcs[i]->procHUID);
                            (*l_procInfoIter).iv_pXProcs[i]->
                                               iv_deconfigured = true;
                        }
                        else
                        {
                            HWAS_INF("deconfigureAssocProc marked proc: "
                                 "%.8X for deconfiguration "
                                 "due to higher HUID than peer "
                                 "proc on same master-containing logical "
                                 "node.",
                                 (*l_procInfoIter).procHUID);
                            (*l_procInfoIter).iv_deconfigured = true;
                        }
                    }
                }
            }
        }// STEP 3


        // STEP 4:
        // If a deconfigured bus connects two procs, both in the same
        // non-master-containing logical node, mark current proc
        // deconfigured if there is a same position proc marked deconfigured
        // in the master logical node, else mark remote proc if there is
        // a same position proc marked deconfigured in the master logical
        // node otherwise, mark the proc with the higher HUID.

        // Iterate through procs and, if in non-master
        // logical node, check xbus chiplets
        for (ProcInfoVector::iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // Don't examine previously marked proc
            if ((*l_procInfoIter).iv_deconfigured)
            {
                continue;
            }
            // Don't examine procs on master logical node
            if (l_pMasterProcInfo->procFabricNode ==
                (*l_procInfoIter).procFabricNode)
            {
                continue;
            }
            // Check xbuses because they connect procs which
            // are in the same logical node
            for (uint8_t i = 0; i < NUM_X_BUSES; i++)
            {
                // If endpoint deconfigured and endpoint peer proc
                // is not already marked deconfigured
                if (((*l_procInfoIter).iv_XDeconfigured[i]) &&
                    (!((*l_procInfoIter).iv_pXProcs[i]->iv_deconfigured)))
                {
                    // Variable to indicate If this step results in
                    // finding a proc to mark deconfigured
                    bool l_chipIDmatch = false;
                    // Iterate through procs and examine ones found to
                    // be on the master-containing logical node
                    for (ProcInfoVector::const_iterator
                         l_mNodeProcInfoIter = io_procInfo.begin();
                         l_mNodeProcInfoIter != io_procInfo.end();
                         ++l_mNodeProcInfoIter)
                    {
                        if (l_pMasterProcInfo->procFabricNode ==
                            (*l_mNodeProcInfoIter).procFabricNode)
                        {
                            // If master logical node proc deconfigured with
                            // same FABRIC_CHIP_ID as current proc
                            if (((*l_mNodeProcInfoIter).iv_deconfigured) &&
                                ((*l_mNodeProcInfoIter).procFabricChip ==
                                 (*l_procInfoIter).procFabricChip))
                            {
                                // Mark current proc to be deconfigured
                                // and set chipIDmatch
                                HWAS_INF("deconfigureAssocProc marked proc: "
                                 "%.8X for deconfiguration "
                                 "due to same position deconfigured "
                                 "proc on master-containing logical "
                                 "node.",
                                 (*l_procInfoIter).procHUID);
                                (*l_procInfoIter).iv_deconfigured =\
                                                                  true;
                                l_chipIDmatch = true;
                                break;
                            }
                            // If master logical node proc deconfigured with
                            // same FABRIC_CHIP_ID as current proc's xbus peer
                            // proc
                            else if (((*l_mNodeProcInfoIter).
                                        iv_deconfigured) &&
                                    ((*l_mNodeProcInfoIter).
                                        procFabricChip ==
                                    (*l_procInfoIter).iv_pXProcs[i]->
                                        procFabricChip))
                            {
                                // Mark peer proc to be deconfigured
                                // and set chipIDmatch
                                HWAS_INF("deconfigureAssocProc marked remote "
                                 "proc: %.8X for deconfiguration "
                                 "due to same position deconfigured "
                                 "proc on master-containing logical "
                                 "node.",
                                 (*l_procInfoIter).iv_pXProcs[i]->procHUID);
                                (*l_procInfoIter).iv_pXProcs[i]->
                                 iv_deconfigured = true;
                                l_chipIDmatch = true;
                                break;
                            }
                        }
                    }
                    // If previous step did not find a proc to mark
                    if (!(l_chipIDmatch))
                    {
                        // Deconfigure proc with higher HUID
                        if ((*l_procInfoIter).procHUID >
                            (*l_procInfoIter).iv_pXProcs[i]->procHUID)
                        {
                             HWAS_INF("deconfigureAssocProc marked proc:"
                             " %.8X for deconfiguration "
                             "due to higher HUID than peer "
                             "proc on same non master-containing logical "
                             "node.",
                             (*l_procInfoIter).procHUID);
                            (*l_procInfoIter).iv_deconfigured =
                                                          true;
                        }
                        else
                        {
                            HWAS_INF("deconfigureAssocProc marked remote proc:"
                             " %.8X for deconfiguration "
                             "due to higher HUID than peer "
                             "proc on same non master-containing logical "
                             "node.",
                             (*l_procInfoIter).iv_pXProcs[i]->procHUID);
                            (*l_procInfoIter).iv_pXProcs[i]->
                            iv_deconfigured = true;
                        }
                    }
                }
            }
        }// STEP 4

        // STEP 5:
        // If a deconfigured bus conects two procs on different logical nodes,
        // and neither proc is the master proc: If current proc's xbus peer
        // proc is marked as deconfigured, mark current proc. Else, mark
        // abus peer proc.

        // Iterate through procs and check for deconfigured abus endpoints
        for (ProcInfoVector::iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // Master proc handled in STEP 1
            if ((*l_procInfoIter).iv_masterCapable)
            {
                continue;
            }
            // Don't examine procs which are already marked
            if ((*l_procInfoIter).iv_deconfigured)
            {
                continue;
            }
            // Check abuses because they connect procs which are in
            // different logical nodes
            for (uint8_t i = 0; i < NUM_A_BUSES; i++)
            {
                // If endpoint deconfigured and endpoint peer proc
                // is not already marked deconfigured
                if (((*l_procInfoIter).iv_ADeconfigured[i]) &&
                    (!((*l_procInfoIter).iv_pAProcs[i]->iv_deconfigured)))
                {
                    // Check XBUS peer
                    bool l_xbusPeerProcDeconfigured = false;
                    for (uint8_t j = 0; j < NUM_X_BUSES; j++)
                    {
                        // If peer proc exists
                        if ((*l_procInfoIter).iv_pXProcs[j])
                        {
                            // If xbus peer proc deconfigured
                            if ((*l_procInfoIter).iv_pXProcs[j]->
                                                    iv_deconfigured)
                            {
                                // Set xbusPeerProcDeconfigured and deconfigure
                                // current proc
                                 HWAS_INF("deconfigureAssocProc marked proc:"
                                 " %.8X for deconfiguration "
                                 "due to deconfigured xbus peer proc.",
                                 (*l_procInfoIter).procHUID);
                                l_xbusPeerProcDeconfigured = true;
                                (*l_procInfoIter).iv_deconfigured = true;
                                break;
                            }
                        }
                    }
                    // If previous step did not result in marking a proc
                    // mark abus peer proc
                    if (!(l_xbusPeerProcDeconfigured))
                    {
                        HWAS_INF("deconfigureAssocProc marked "
                             "remote proc: %.8X for deconfiguration "
                             "due to functional xbus peer proc.",
                             (*l_procInfoIter).iv_pAProcs[i]->procHUID);
                        (*l_procInfoIter).iv_pAProcs[i]->
                                          iv_deconfigured = true;
                    }
                }
            }
        }// STEP 5
    }while(0);
    if (!l_errlHdl)
    {
        // Perform SMP node balancing
        l_errlHdl = _symmetryValidation(io_procInfo);
    }
    return l_errlHdl;

}

//******************************************************************************

errlHndl_t DeconfigGard::_symmetryValidation(ProcInfoVector &io_procInfo)
{
    // Defined for possible use in future applications
    errlHndl_t l_errlHdl = NULL;

    // Perform SMP node balancing
    do
    {
        // STEP 1:
        // If a proc is deconfigured in a logical node
        // containing the master proc, iterate through all procs
        // and mark as deconfigured those in other logical nodes
        // with the same FABRIC_CHIP_ID (procFabricChip)

        // Find master proc
        ProcInfo * l_pMasterProcInfo = NULL;
        for (ProcInfoVector::iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // If master proc
            if ((*l_procInfoIter).iv_masterCapable)
            {
                // Save for subsequent use
                l_pMasterProcInfo = &(*l_procInfoIter);
                break;
            }
        }
        // If no master proc found, abort
        HWAS_ASSERT(l_pMasterProcInfo, "HWAS _symmetryValidation:"
                                       "Master proc not found");
        // Iterate through procs and check if in master logical node
        for (ProcInfoVector::const_iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // Skip master proc
            if ((*l_procInfoIter).iv_masterCapable)
            {
                continue;
            }
            // If current proc is on master logical node
            // and marked as deconfigured
            if ((l_pMasterProcInfo->procFabricNode ==
                (*l_procInfoIter).procFabricNode) &&
                ((*l_procInfoIter).iv_deconfigured))
            {
                // Iterate through procs and mark any same-
                // position procs as deconfigured
                for (ProcInfoVector::iterator
                     l_posProcInfoIter = io_procInfo.begin();
                     l_posProcInfoIter != io_procInfo.end();
                     ++l_posProcInfoIter)
                {
                    if ((*l_procInfoIter).procFabricChip ==
                        (*l_posProcInfoIter).procFabricChip)
                    {
                        HWAS_INF("symmetryValidation step 1 marked proc: "
                             "%.8X for deconfiguration.",
                             (*l_posProcInfoIter).procHUID);
                        (*l_posProcInfoIter).iv_deconfigured = true;
                    }
                }
            }
        }// STEP 1

        // STEP 2:
        // If a deconfigured proc is found on a non-master-containing node
        // and has the same position (FABRIC_CHIP_ID) as a functional
        // non-master chip on the master logical node,
        // mark its xbus peer proc(s) for deconfiguration

        // Iterate through procs, if marked deconfigured, compare chip
        // position to functional chip on master node.
        for (ProcInfoVector::const_iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // If proc is marked deconfigured
            if ((*l_procInfoIter).iv_deconfigured)
            {
                // Iterate through procs, examining those on
                // the master logical node
                for (ProcInfoVector::const_iterator
                     l_mNodeProcInfoIter = io_procInfo.begin();
                     l_mNodeProcInfoIter != io_procInfo.end();
                     ++l_mNodeProcInfoIter)
                {
                    // If proc found is on the master-containing logical node
                    // functional, and matches the position of the deconfigured
                    // proc from the outer loop
                    if ((l_pMasterProcInfo->procFabricNode ==
                        (*l_mNodeProcInfoIter).procFabricNode) &&
                        (!((*l_mNodeProcInfoIter).iv_deconfigured)) &&
                        ((*l_mNodeProcInfoIter).procFabricChip ==
                                (*l_procInfoIter).procFabricChip))
                    {
                        // Find xbus peer proc to mark deconfigured
                        for (uint8_t i = 0; i < NUM_X_BUSES; i++)
                        {
                            // If xbus peer proc exists, mark it
                            if ((*l_procInfoIter).iv_pXProcs[i])
                            {
                                HWAS_INF("symmetryValidation step 2 "
                                    "marked proc: %.8X for "
                                    "deconfiguration.",
                                    (*l_procInfoIter).
                                    iv_pXProcs[i]->procHUID);
                                (*l_procInfoIter).iv_pXProcs[i]->
                                    iv_deconfigured = true;
                            }
                        }
                    }
                }
            }
        }// STEP 2
    }while(0);
    return l_errlHdl;
}

//******************************************************************************

void DeconfigGard::setXABusEndpointDeconfigured(bool deconfig)
{
    HWAS_INF("Set iv_XABusEndpointDeconfigured");
    iv_XABusEndpointDeconfigured = deconfig;
}

} // namespce HWAS

