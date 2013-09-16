/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/deconfigGard.C $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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

#include <hwas/common/hwas.H>                   // checkMinimumHardware()

#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>

// Trace definition
#define __COMP_TD__ g_trac_deconf

// TODO The DeconfigGard code needs to trace a target. The current recommended
// way is to get the Target's PHYS_PATH attribute and do a binary trace.
// However, the size of a EntityPath is more than 16 bytes. This code
// will trace only the first 16 bytes (which in most cases is enough) to avoid a
// multi-line binary trace. This all seems a little convoluted. Is there a
// better way to trace a Target
#define DG_DBG_TARGET(string, pPath) \
    HWAS_DBG_BIN(string, pPath, sizeof(EntityPath) - 1)
#define DG_INF_TARGET(string, pPath) \
    HWAS_INF_BIN(string, pPath, sizeof(EntityPath) - 1)
#define DG_ERR_TARGET(string, pPath) \
    HWAS_ERR_BIN(string, pPath, sizeof(EntityPath) - 1)

// TODO There are a number of error logs created in this file. Most of them
// should include the target identifier (PHYS_PATH). There is a plan in RTC
// story 4110 to provide a way to easily add a target to an error log. When that
// is done need to update the error logs

namespace HWAS
{

using namespace HWAS::COMMON;
using namespace TARGETING;

bool processDeferredDeconfig()
{
    return HWAS::theDeconfigGard()._processDeferredDeconfig();
}

errlHndl_t collectGard(const PredicateBase *i_pPredicate)
{
    HWAS_INF("collectGard entry" );
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
        HWAS_INF("collectGard failed (plid 0x%X)", errl->plid());
    }
    else
    {
        HWAS_INF("collectGard completed successfully");
    }
    return errl;
}

//******************************************************************************
DeconfigGard & theDeconfigGard()
{
    return HWAS_GET_SINGLETON(theDeconfigGardSingleton);
}

//******************************************************************************
DeconfigGard::DeconfigGard() :
    iv_platDeconfigGard(NULL)
{
    HWAS_INF("DeconfigGard Constructor");
    HWAS_MUTEX_INIT(iv_mutex);
}

//******************************************************************************
DeconfigGard::~DeconfigGard()
{
    HWAS_INF("DeconfigGard Destructor");
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
            HWAS_ERR("Error 0x%X from platGetGardRecords", l_pErr->plid());
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
                HWAS_ERR("Error 0x%X from platClearGardRecords",
                        l_pErr->plid());
                break;
            }

            // now clear our 'changed' bit
            clear_hwas_changed_bit(l_pTarget,HWAS_CHANGED_BIT_GARD);
        } // for
    }
    while (0);

    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::deconfigureTargetsFromGardRecordsForIpl(
        const PredicateBase *i_pPredicate)
{
    HWAS_INF("Deconfigure Targets from GARD Records for IPL");
    errlHndl_t l_pErr = NULL;
    GardRecords_t l_gardRecords;

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
            break;
        }

        // Get all GARD Records
        l_pErr = platGetGardRecords(NULL, l_gardRecords);
        if (l_pErr)
        {
            HWAS_ERR("Error 0x%X from platGetGardRecords", l_pErr->plid());
            break;
        }

        HWAS_INF("%d GARD Records found", l_gardRecords.size());

        if (l_gardRecords.empty())
        {
            break;
        }

        // For each GARD Record
        for (GardRecordsCItr_t l_itr = l_gardRecords.begin();
             l_itr != l_gardRecords.end();
             ++l_itr)
        {
            GardRecord l_gardRecord = *l_itr;

            if ((l_sys_policy & CDM_POLICIES_PREDICTIVE_DISABLED) &&
                (l_gardRecord.iv_errorType == GARD_Predictive))
            {
                // predictive records are disabled AND gard record is predictive
                //  - don't process
                HWAS_INF("Predictive policy: disabled - skipping GARD Record");
                continue;
            }

            if ((l_sys_policy & CDM_POLICIES_FUNCTIONAL_DISABLED) &&
                (l_gardRecord.iv_errorType == GARD_Func))
            {
                // functional records are disabled AND gard record is Functional
                //  - don't process
                HWAS_INF("Functional policy: disabled - skipping GARD Record");
                continue;
            }

            // Find the associated Target
            Target * l_pTarget =
                targetService().toTarget(l_gardRecord.iv_targetId);

            if (l_pTarget == NULL)
            {
                // could be a platform specific target for the other
                // ie, we are hostboot and this is an FSP target, or vice-versa
                DG_INF_TARGET("Could not find Target for",
                               &(l_gardRecord.iv_targetId));
                continue;
            }

            // if this does NOT match, continue to next in loop
            if (i_pPredicate && ((*i_pPredicate)(l_pTarget) == false))
            {
                HWAS_INF("skipping %.8X - predicate didn't match",
                        get_huid(l_pTarget));
                continue;
            }

            // skip if not present
            if (!l_pTarget->getAttr<ATTR_HWAS_STATE>().present)
            {
                HWAS_INF("skipping %.8X - target not present",
                        get_huid(l_pTarget));
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
        } // for

        //  check and see if we still have enough hardware to continue
        l_pErr  =   checkMinimumHardware();
        if ( l_pErr )
        {
            HWAS_ERR("Error from checkMinimumHardware ");
            break;
        }
    }
    while (0);

    return l_pErr;
}

bool compareTargetHuid(TargetHandle_t t1, TargetHandle_t t2)
{
    return (t1->getAttr<ATTR_HUID>() <
                t2->getAttr<ATTR_HUID>());
}

//******************************************************************************
errlHndl_t DeconfigGard::processFieldCoreOverride()
{
    HWAS_INF("Process Field Core Override FCO");
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
                HWAS_INF("pProc %.8X - pushing to proclist",
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
errlHndl_t DeconfigGard::createGardRecord(const Target * const i_pTarget,
                                          const uint32_t i_errlEid,
                                          const GARD_ErrorType i_errorType)
{
    errlHndl_t l_pErr = NULL;

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
             * @moduleid     HWAS::MOD_DECONFIG_GARD
             * @reasoncode   HWAS::RC_TARGET_NOT_GARDABLE
             * @devdesc      Attempt to create a GARD Record for a target that
             *               is not GARDable
             *               (not DECONFIG_GARDABLE or not present)
             * @userdata1    HUID of input target // GARD errlog EID
             * @userdata2    ATTR_DECONFIG_GARDABLE // ATTR_HWAS_STATE.present
             */
            const uint64_t userdata1 =
                (static_cast<uint64_t>(get_huid(i_pTarget)) << 32) | i_errlEid;
            const uint64_t userdata2 =
                (static_cast<uint64_t>(lDeconfigGardable) << 32) | lPresent;
            l_pErr = hwasError(
                ERRL_SEV_UNRECOVERABLE,
                HWAS::MOD_DECONFIG_GARD,
                HWAS::RC_TARGET_NOT_GARDABLE,
                userdata1,
                userdata2);
            break;
        }

        Target* pSys;
        targetService().getTopLevelTarget(pSys);
        HWAS_ASSERT(pSys, "HWAS createGardRecord: no TopLevelTarget");

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

        if ((l_sys_policy & CDM_POLICIES_FUNCTIONAL_DISABLED) &&
            (i_errorType == GARD_Func))
        {
            // functional records are disabled AND gard record is Functional
            //  - don't process
            HWAS_INF("Functional policy: disabled - skipping GARD Record create");
            break;
        }

        l_pErr = platCreateGardRecord(i_pTarget, i_errlEid, i_errorType);
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
errlHndl_t DeconfigGard::deconfigureTarget(Target & i_target,
                                           const uint32_t i_errlEid,
                                           bool i_evenAtRunTime)
{
    HWAS_INF("Deconfigure Target");
    errlHndl_t l_pErr = NULL;

    do
    {
        // Do not deconfig Target if we're NOT being asked to force AND
        //   the is System is at runtime
        if (!i_evenAtRunTime && platSystemIsAtRuntime())
        {
            HWAS_INF("Skipping deconfigTarget - System at Runtime");
            break;
        }

        const ATTR_DECONFIG_GARDABLE_type lDeconfigGardable =
                i_target.getAttr<ATTR_DECONFIG_GARDABLE>();
        const uint8_t lPresent =
                i_target.getAttr<ATTR_HWAS_STATE>().present;
        if (!lDeconfigGardable || !lPresent)
        {
            // Target is not Deconfigurable. Create an error
            HWAS_ERR("Target %.8X not Deconfigurable",
                get_huid(&i_target));

            /*@
             * @errortype
             * @moduleid     HWAS::MOD_DECONFIG_GARD
             * @reasoncode   HWAS::RC_TARGET_NOT_DECONFIGURABLE
             * @devdesc      Attempt to deconfigure a target that is not
             *               deconfigurable
             *               (not DECONFIG_GARDABLE or not present)
             * @userdata1    HUID of input target // GARD errlog EID
             * @userdata2    ATTR_DECONFIG_GARDABLE // ATTR_HWAS_STATE.present
             */
            const uint64_t userdata1 =
                (static_cast<uint64_t>(get_huid(&i_target)) << 32) | i_errlEid;
            const uint64_t userdata2 =
                (static_cast<uint64_t>(lDeconfigGardable) << 32) | lPresent;
            l_pErr = hwasError(
                ERRL_SEV_INFORMATIONAL,
                HWAS::MOD_DECONFIG_GARD,
                HWAS::RC_TARGET_NOT_DECONFIGURABLE,
                userdata1,
                userdata2);
            break;
        }

        // all ok - do the work
        HWAS_MUTEX_LOCK(iv_mutex);

        // Deconfigure the Target
        _deconfigureTarget(i_target, i_errlEid);

        // Deconfigure other Targets by association
        _deconfigureByAssoc(i_target, i_errlEid);

        HWAS_MUTEX_UNLOCK(iv_mutex);

        //  check and see if we still have enough hardware to continue
        l_pErr  =   checkMinimumHardware();
        if ( l_pErr )
        {
            HWAS_ERR("Error from checkMinimumHardware ");
            break;
        }
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
    HWAS_INF("Get Deconfigure Record(s)");
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
 * @brief       simple helper fn to find and return the list of MCS targets
 *                  that are in the same MSS_MEM_MC_IN_GROUP as the input.
 *
 * @param[in]   i_startMcs      pointer to starting MCS target
 * @param[in]   o_McsInGroup    list of functional Targets that are in the same
 *                              group as i_startMcs
 *
 * @return      none
 *
 */
void findMcsInGroup(const Target *i_startMcs, TargetHandleList &o_McsInGroup)
{
    // find the group that this MCS is in by reading the
    // group list from the proc. this is an array of 8 bitmasks.
    // the 8 elements are each a different group; the bits in each
    // element represent the MCS units in each group.

    o_McsInGroup.clear();
    const Target *l_proc = getParentChip(i_startMcs);
    ATTR_MSS_MEM_MC_IN_GROUP_type l_group;
    l_proc->tryGetAttr<ATTR_MSS_MEM_MC_IN_GROUP>(l_group);

    HWAS_DBG("findMcsInGroup MCS %.8X under proc %.8X",
                 get_huid(i_startMcs), get_huid(l_proc));
    HWAS_DBG(" groups: %.2X %.2X %.2X %.2X   %.2X %.2X %.2X %.2X",
        l_group[0], l_group[1], l_group[2], l_group[3],
        l_group[4], l_group[5], l_group[6], l_group[7]);

    const uint8_t my_bit = 0x80 >> i_startMcs->getAttr<ATTR_CHIP_UNIT>();
    uint8_t my_group = 0;
    for (;
            (my_group < 8 ) && ((l_group[my_group] & my_bit) == 0);
            ++my_group)
    {} // nothing - just looking for exit condition

    // if found a match before we hit the end, find the list.
    if (my_group != 8)
    {
        //  get MCS CHILDs that are functional
        PredicateCTM predMcs(CLASS_UNIT, TYPE_MCS);
        PredicateIsFunctional isFunctional;
        PredicatePostfixExpr checkExpr;
        checkExpr.push(&predMcs).push(&isFunctional).And();
        targetService().getAssociated(o_McsInGroup, l_proc,
            TargetService::CHILD_BY_AFFINITY, TargetService::IMMEDIATE,
            &checkExpr);

        for (TargetHandleList::iterator pMcs_it = o_McsInGroup.begin();
               pMcs_it != o_McsInGroup.end();
               /* increment will be done in loop */)
        {
            TargetHandle_t pMcs = *pMcs_it;
            const uint8_t mcs_bit = 0x80 >> pMcs->getAttr<ATTR_CHIP_UNIT>();

            // if this is a paired MEMBUF - in the same group
            if (l_group[my_group] & mcs_bit)
            {
                HWAS_INF("findMcsInGroup: MCS %.8X (0x%.2X) paired in group %d",
                     get_huid(pMcs), mcs_bit, my_group);

                // keep it in the list
                pMcs_it++;
            }
            else
            {
                HWAS_DBG("findMcsInGroup: MCS %.8X (0x%.2X) not in group %d",
                     get_huid(pMcs), mcs_bit, my_group);

                 // erase this MCS, and 'increment' to next
                pMcs_it = o_McsInGroup.erase(pMcs_it);
            }
        } // for
    }
    else
    {
        HWAS_INF("findMcsInGroup: can't find MCS %.8X in a group!",
                get_huid(i_startMcs));
        // just return an empty list
    }
} // findMcsInGroup

//******************************************************************************
void DeconfigGard::_deconfigureByAssoc(Target & i_target,
                                       const uint32_t i_errlEid)
{
    HWAS_INF("deconfigByAssoc for %.8X", get_huid(&i_target));

    // some common variables used below
    TargetHandleList pChildList;
    PredicateIsFunctional isFunctional;

    // note - ATTR_DECONFIG_GARDABLE is NOT checked for all 'by association'
    // deconfigures, as that attribute is only for direct deconfigure requests.

    // find all CHILD matches for this target and deconfigure them
    targetService().getAssociated(pChildList, &i_target,
        TargetService::CHILD, TargetService::ALL, &isFunctional);
    for (TargetHandleList::iterator pChild_it = pChildList.begin();
            pChild_it != pChildList.end();
            ++pChild_it)
    {
        TargetHandle_t pChild = *pChild_it;

        HWAS_INF("deconfigByAssoc CHILD: %.8X", get_huid(pChild));
        _deconfigureTarget(*pChild, i_errlEid);
        // Deconfigure other Targets by association
        _deconfigureByAssoc(*pChild, i_errlEid);
    } // for CHILD

    // find all CHILD_BY_AFFINITY matches for this target and deconfigure them
    targetService().getAssociated(pChildList, &i_target,
        TargetService::CHILD_BY_AFFINITY, TargetService::ALL, &isFunctional);
    for (TargetHandleList::iterator pChild_it = pChildList.begin();
            pChild_it != pChildList.end();
            ++pChild_it)
    {
        TargetHandle_t pChild = *pChild_it;

        HWAS_INF("deconfigByAssoc CHILD_BY_AFFINITY: %.8X", get_huid(pChild));
        _deconfigureTarget(*pChild, i_errlEid);
        // Deconfigure other Targets by association
        _deconfigureByAssoc(*pChild, i_errlEid);
    } // for CHILD_BY_AFFINITY

    // Memory deconfigureByAssociation rules
    // depends on the type of this target - MEMBUF, MBA, DIMM
    switch (i_target.getAttr<ATTR_TYPE>())
    {
        case TYPE_MEMBUF:
        {
            //  get parent MCS
            TargetHandleList pParentMcsList;
            getParentAffinityTargets(pParentMcsList, &i_target,
                    CLASS_UNIT, TYPE_MCS, true /*functional*/);
            HWAS_ASSERT((pParentMcsList.size() <= 1),
                "HWAS deconfigByAssoc: pParentMcsList > 1");

            // done if parent is already deconfigured
            if (pParentMcsList.empty())
            {
                break;
            }

            // deconfigure the parent
            const Target *l_parentMcs = pParentMcsList[0];
            HWAS_INF("deconfigByAssoc MEMBUF parent MCS: %.8X",
                get_huid(l_parentMcs));
            _deconfigureTarget(const_cast<Target &> (*l_parentMcs),
                i_errlEid);
            _deconfigureByAssoc(const_cast<Target &> (*l_parentMcs),
                i_errlEid);

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
            TargetHandleList pMcsList;
            findMcsInGroup(l_parentMcs, pMcsList);

            // deconfigure each paired MCS
            for (TargetHandleList::iterator pMcs_it = pMcsList.begin();
                    pMcs_it != pMcsList.end();
                    ++pMcs_it)
            {
                TargetHandle_t pMcs = *pMcs_it;

                HWAS_INF("deconfigByAssoc MCS (& MEMBUF) paired: %.8X",
                    get_huid(pMcs));
                _deconfigureTarget(*pMcs, i_errlEid);
                _deconfigureByAssoc(*pMcs, i_errlEid);
            } // for
            break;
        } // TYPE_MEMBUF

        case TYPE_MBA:
        {
            // get parent MEMBUF (Centaur)
            const Target *l_parentMembuf = getParentChip(&i_target);

            // get children DIMM that are functional
            PredicateCTM predDimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
            PredicatePostfixExpr checkExpr;
            checkExpr.push(&predDimm).push(&isFunctional).And();
            TargetHandleList pDimmList;
            targetService().getAssociated(pDimmList, l_parentMembuf,
                TargetService::CHILD_BY_AFFINITY, TargetService::ALL,
                &checkExpr);

            // if parent MEMBUF (Centaur) has no functional memory
            if (pDimmList.empty())
            {
                // deconfigure parent MEMBUF (Centaur)
                HWAS_INF("deconfigByAssoc MEMBUF parent with no memory: %.8X",
                    get_huid(l_parentMembuf));
                _deconfigureTarget(const_cast<Target &> (*l_parentMembuf),
                    i_errlEid);
                _deconfigureByAssoc(const_cast<Target &> (*l_parentMembuf),
                    i_errlEid);

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
            getParentAffinityTargets(pParentMcsList, l_parentMembuf,
                    CLASS_UNIT, TYPE_MCS, true /*functional*/);
            HWAS_ASSERT((pParentMcsList.size() <= 1),
                "HWAS deconfigByAssoc: pParentMcsList > 1");

            if (pParentMcsList.empty())
            {
                // MCS is already deconfigured, we're done
                break;
            }

            // MEMBUF only has 1 parent
            const Target *l_parentMcs = pParentMcsList[0];

            // find paired MCS / MEMBUF (Centaur)
            TargetHandleList pMcsList;
            findMcsInGroup(l_parentMcs, pMcsList);

            // how much memory does this MBA have
            ATTR_EFF_DIMM_SIZE_type l_dimmSize;
            i_target.tryGetAttr<ATTR_EFF_DIMM_SIZE>(l_dimmSize);
            const uint64_t l_mbaDimmSize =
                    l_dimmSize[0][0] + l_dimmSize[0][1] +
                    l_dimmSize[1][0] + l_dimmSize[1][1];

            if (l_mbaDimmSize == 0)
            {   // before this attribute has been set, so don't check
                break;
            }

            // now we'll walk thru MCS targets in the group, find MBAs
            // that match in memory size, and deconfigure them, and add
            // them to this list to do the deconfigByAssoc afterward.
            TargetHandleList l_deconfigList;

            // for each paired MCS in the group
            for (TargetHandleList::iterator pMcs_it = pMcsList.begin();
                    pMcs_it != pMcsList.end();
                    ++pMcs_it)
            {
                TargetHandle_t pMcs = *pMcs_it;

                if (pMcs == l_parentMcs)
                {   // this is 'my' MCS - continue
                    continue;
                }

                // search for memory on EITHER of its MBA that matchs
                TargetHandleList pMbaList;
                PredicateCTM predMba(CLASS_UNIT, TYPE_MBA);
                PredicatePostfixExpr checkExpr;
                checkExpr.push(&predMba).push(&isFunctional).And();
                targetService().getAssociated(pMbaList, pMcs,
                    TargetService::CHILD_BY_AFFINITY, TargetService::ALL,
                    &checkExpr);

                // if there are 2 functional MBA, then one of them matches
                // the MBA we just deconfigured, so we need to find the
                // match and deconfigure it.

                // assumes 2 MBA per MEMBUF. if this changes, then instead
                // of '1', count the number of MBAs under this MEMBUF and
                // use that as the comparison.
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
                            HWAS_INF("deconfigByAssoc MBA matched: %.8X",
                                get_huid(pMba));
                            _deconfigureTarget(*pMba, i_errlEid);
                            l_deconfigList.push_back(pMba);
                            break; // only need to do 1 MBA - we're done.
                        }
                    } // for MBA
                } // if 2 functional MBA
            } // for paired MCS

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
                HWAS_INF("deconfigByAssoc MBA matched (bA): %.8X",
                    get_huid(pMba));
                _deconfigureByAssoc(*pMba, i_errlEid);
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
                "HWAS deconfigByAssoc: pParentMbaList > 1");

            // if parent MBA hasn't already been deconfigured
            if (!pParentMbaList.empty())
            {
                const Target *l_parentMba = pParentMbaList[0];
                HWAS_INF("deconfigByAssoc DIMM parent MBA: %.8X",
                    get_huid(l_parentMba));
                _deconfigureTarget(const_cast<Target &> (*l_parentMba),
                    i_errlEid);
                _deconfigureByAssoc(const_cast<Target &> (*l_parentMba),
                    i_errlEid);
            }
            break;
        } // TYPE_DIMM
        default:
            // no action
        break;
    } // switch

    //HWAS_INF("deconfigByAssoc exiting: %.8X", get_huid(&i_target));
} // _deconfigByAssoc

//******************************************************************************
void DeconfigGard::_deconfigureTarget(Target & i_target,
                                      const uint32_t i_errlEid)
{
    HWAS_INF("Deconfiguring Target %.8X, errlEid 0x%X",
            get_huid(&i_target), i_errlEid);

    // Set the Target state to non-functional. The assumption is that it is
    // not possible for another thread (other than deconfigGard) to be
    // updating HWAS_STATE concurrently.
    HwasState l_state =
        i_target.getAttr<ATTR_HWAS_STATE>();

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

        // Do any necessary Deconfigure Actions
        _doDeconfigureActions(i_target);
    }

    //HWAS_DBG("Deconfiguring Target %.8X exiting", get_huid(&i_target));
} // _deconfigureTarget

//******************************************************************************
void DeconfigGard::_doDeconfigureActions(Target & i_target)
{
    // TODO
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
bool DeconfigGard::_processDeferredDeconfig()
{
    HWAS_DBG(">processDeferredDeconfig");

    // get all deconfigure records, process them, and delete them.
    HWAS_MUTEX_LOCK(iv_mutex);

    // we return true if there were targets to deconfigure.
    bool rc = !iv_deconfigureRecords.empty();

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

    HWAS_DBG("<processDeferredDeconfig returning %d", rc);
    return rc;
} // _processDeferredDeconfig

} // namespce HWAS
