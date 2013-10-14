/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/targetservice.C $                    */
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
 *  @file targeting/common/targetservice.C
 *
 *  @brief Implementation of the TargetService which manages the pool of
 *      available targets, provides iteration support, and otherwise makes
 *      target available and usable.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

// This component
#include <targeting/common/targetservice.H>
#include <targeting/common/predicates/predicates.H>
#include <pnortargeting.H>
#include <targeting/attrrp.H>
#include <targeting/common/trace.H>
#include <targeting/adapters/types.H>
#include <targeting/targplatutil.H>
#include <targeting/targplatreasoncodes.H>
#include <attributetraits.H>

#undef EXTRA_SANITY_CHECKING

//******************************************************************************
// targetService
//******************************************************************************

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"

#define TARG_CLASS "targetService"

// It is defined here to limit the scope
#define MAX_NODE_ID  iv_nodeInfo.size()

#ifdef MULTINODE_TARGETING
#define MAX_ENABLED_NODE_ID iv_nodeInfo.size()
#else
#define MAX_ENABLED_NODE_ID 1
#endif

//******************************************************************************
// targetService
//******************************************************************************

TARGETING::TargetService& targetService()
{
    #define TARG_FN "targetService()"

    return TARG_GET_SINGLETON(TARGETING::theTargetService);

    #undef TARG_FN
}

//******************************************************************************
// Component trace buffer
//******************************************************************************

TARG_TD_t g_trac_targeting = {0};
#ifdef __HOSTBOOT_MODULE
TRAC_INIT(&g_trac_targeting, "TARG", 2*KILOBYTE, TRACE::BUFFER_SLOW);
#else
TRAC_INIT(&g_trac_targeting, "TARG", 4096);
#endif

#undef TARG_CLASS
#define TARG_CLASS "TargetService::"

//******************************************************************************
// TargetService::TargetService
//******************************************************************************

TargetService::TargetService() :
    iv_initialized(false)
{
    #define TARG_FN "TargetService()"

    #undef TARG_FN
}

//******************************************************************************
// TargetService::~TargetService
//******************************************************************************

TargetService::~TargetService()
{
    #define TARG_FN "~TargetService()"

    // Nothing to do; Target[] memory not owned by this object

    #undef TARG_FN
}

//******************************************************************************
// TargetService::init
//******************************************************************************

void TargetService::init(const size_t i_maxNodes)
{
    #define TARG_FN "init()"

    TARG_ENTER();

    if(!iv_initialized)
    {
        TARG_INF("Max Nodes to initialize is [%d]", i_maxNodes);

        // Build the association mappings
        AssociationAttrMap a1 = {PARENT, INWARDS, ATTR_PHYS_PATH};
        AssociationAttrMap a2 = {CHILD, OUTWARDS, ATTR_PHYS_PATH};
        AssociationAttrMap a3 = {PARENT_BY_AFFINITY,
            INWARDS,ATTR_AFFINITY_PATH};
        AssociationAttrMap a4 = {CHILD_BY_AFFINITY,
            OUTWARDS,ATTR_AFFINITY_PATH};
        AssociationAttrMap a5 = {VOLTAGE_SUPPLIER, INWARDS, ATTR_POWER_PATH};
        AssociationAttrMap a6 = {VOLTAGE_CONSUMER, OUTWARDS, ATTR_POWER_PATH};
        iv_associationMappings.push_back(a1);
        iv_associationMappings.push_back(a2);
        iv_associationMappings.push_back(a3);
        iv_associationMappings.push_back(a4);
        iv_associationMappings.push_back(a5);
        iv_associationMappings.push_back(a6);

        for(uint8_t l_nodeCnt=0; l_nodeCnt<i_maxNodes; l_nodeCnt++)
        {
            NodeSpecificInfo l_nodeInfo;
            l_nodeInfo.nodeId = static_cast<NODE_ID>(l_nodeCnt);

            // Cache location of RO section containing all the attribute
            // metadata
            TargetingHeader* l_pHdr = reinterpret_cast<TargetingHeader*>(
                    TARG_GET_SINGLETON(TARGETING::theAttrRP).getBaseAddress(
                            static_cast<NODE_ID>(l_nodeCnt)));

            if(NULL == l_pHdr)
            {
                TARG_INF("Targeting header is NULL for Node Id [%d]",
                    l_nodeCnt);
                TARG_ASSERT(0, TARG_ERR_LOC
                    "Targeting Header for Node [%d] cannot be NULL", l_nodeCnt);
            }
            else
            {
                TARG_ASSERT((l_pHdr->eyeCatcher == PNOR_TARG_EYE_CATCHER),
                     TARG_ERR_LOC "FATAL: Targeting eyecatcher not found; "
                     "expected 0x%08X but got 0x%08X",
                      PNOR_TARG_EYE_CATCHER,l_pHdr->eyeCatcher);

                l_nodeInfo.pPnor = reinterpret_cast<uint32_t*>(
                        (reinterpret_cast<char*>(l_pHdr) + l_pHdr->headerSize));

                (void)_configureTargetPool(l_nodeInfo);

                l_nodeInfo.initialized = true;
            }
            iv_nodeInfo.push_back(l_nodeInfo);
        }

        bool masterNodeCapable = false;
        (void)UTIL::subsystemIsMasterNodeCapable(masterNodeCapable);
        if(masterNodeCapable)
        {
            (void)initDefaultMasterNode();
        }

        iv_initialized = true;
    }

    TARG_EXIT();

    #undef TARG_FN
}

//******************************************************************************
// TargetService:: _getFirstTargetForIterators
//******************************************************************************

void TargetService::_getFirstTargetForIterators(Target*& o_firstTargetPtr) const
{
    #define TARG_FN "_getFirstTargetForIterators()"
    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    for(uint8_t l_nodeCnt=0; l_nodeCnt<MAX_NODE_ID; ++l_nodeCnt)
    {
        /* This will come inside for initialized node only.. Just for safety we
         * are checking for maxTargets & whether it is initialized or not */
        if((iv_nodeInfo[l_nodeCnt].initialized == true) &&
            (iv_nodeInfo[l_nodeCnt].maxTargets > 0))
        {
            /* Assumption -
             * Here we are assuming that the first target of any binary is not
             * the system target, to make sure this ithe binary compiler needs
             * to compile the binary in this specific order.
             */
            o_firstTargetPtr = &(*(iv_nodeInfo[l_nodeCnt].targets))[0];

            TARG_ASSERT(o_firstTargetPtr != NULL, TARG_ERR_LOC
                   "FATAL: Could not find any targets");
            break;
        }
    }
    #undef TARG_FN
}

//******************************************************************************
// TargetService::begin (non-const version)
//******************************************************************************

TargetService::iterator TargetService::begin()
{
    #define TARG_FN "begin()"
    Target* l_pFirstTarget = NULL;

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    _getFirstTargetForIterators(l_pFirstTarget);
    return iterator(l_pFirstTarget);

    #undef TARG_FN
}

//******************************************************************************
// TargetService::raw_begin (non-const version)
//******************************************************************************

TargetService::rawiterator TargetService::raw_begin()
{
    #define TARG_FN "raw_begin()"
    Target* l_pFirstTarget = NULL;

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    _getFirstTargetForIterators(l_pFirstTarget);
    return rawiterator(l_pFirstTarget);

    #undef TARG_FN
}

//******************************************************************************
// TargetService::begin (const version)
//******************************************************************************

//TargetService::const_iterator
_TargetIterator<const Target*> TargetService::begin() const
{
    #define TARG_FN "begin() const"
    Target* l_pTmpFirstTarget = NULL;

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    _getFirstTargetForIterators(l_pTmpFirstTarget);
    const Target* l_pFirstTarget = l_pTmpFirstTarget;

    return const_iterator(l_pFirstTarget);

    #undef TARG_FN
}


//******************************************************************************
// TargetService::raw_begin (const version)
//******************************************************************************

_TargetRawIterator<const Target*> TargetService::raw_begin() const
{
    #define TARG_FN "raw_begin() const"
    Target* l_pTmpFirstTarget = NULL;

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    _getFirstTargetForIterators(l_pTmpFirstTarget);
    const Target* l_pFirstTarget = l_pTmpFirstTarget;

    return const_rawiterator(l_pFirstTarget);

    #undef TARG_FN
}

//******************************************************************************
// TargetService::end (non-const version)
//******************************************************************************

TargetService::iterator TargetService::end()
{
    #define TARG_FN "end()"

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    return iterator(NULL);

    #undef TARG_FN
}

//******************************************************************************
// TargetService::raw_end (non-const version)
//******************************************************************************

TargetService::rawiterator TargetService::raw_end()
{
    #define TARG_FN "raw_end()"

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    return rawiterator(NULL);

    #undef TARG_FN
}

//******************************************************************************
// TargetService::end (const version)
//******************************************************************************

TargetService::const_iterator TargetService::end() const
{
    #define TARG_FN "end() const"

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    return const_iterator(NULL);

    #undef TARG_FN
}

//******************************************************************************
// TargetService::raw_end (const version)
//******************************************************************************

TargetService::const_rawiterator TargetService::raw_end() const
{
    #define TARG_FN "raw_end() const"

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    return const_rawiterator(NULL);

    #undef TARG_FN
}

//******************************************************************************
// TargetService::getNextInitializedNode
//******************************************************************************

uint8_t TargetService::getNextInitializedNode(const NODE_ID i_node) const
{
    #define TARG_FN "getNextInitializedNode(...)"
    uint8_t l_nodeCnt = 0;
    bool l_foundNode = false;

    if(static_cast<uint32_t>(i_node + 1) < MAX_ENABLED_NODE_ID )
    {
        for(l_nodeCnt=(i_node +1); l_nodeCnt<MAX_NODE_ID; ++l_nodeCnt)
        {
            if((iv_nodeInfo[l_nodeCnt].initialized) &&
                    (iv_nodeInfo[l_nodeCnt].maxTargets > 0))
            {
                l_foundNode = true;
                break;
            }
        }
    }
    if(l_foundNode == false)
    {
        // Assign Invalid node
        l_nodeCnt = MAX_NODE_ID;
    }
    return l_nodeCnt;
    #undef TARG_FN
}

//******************************************************************************
// TargetService::getNextTarget
//******************************************************************************

Target* TargetService::getNextTarget(const Target* i_pTarget) const
{
    #define TARG_FN "getNextTarget(...)"
    Target* l_pTarget = const_cast<Target*>(i_pTarget);
    bool l_targetFound = false;
    if(l_pTarget != NULL)
    {
        for(uint8_t i_node=0; i_node<MAX_NODE_ID; ++i_node)
        {
            if((iv_nodeInfo[i_node].initialized) &&
                (iv_nodeInfo[i_node].maxTargets > 0) &&
                ((l_pTarget >= &(*(iv_nodeInfo[i_node]).targets)[0]) &&
                    (l_pTarget <= &(*(iv_nodeInfo[i_node]).targets)[
                                iv_nodeInfo[i_node].maxTargets - 1])))
            {
                if( l_pTarget == &(*(iv_nodeInfo[i_node]).targets)[iv_nodeInfo[
                            i_node].maxTargets - 1] )
                {
                    // Go for next node
                    uint8_t l_nextNode = getNextInitializedNode(
                                            static_cast<NODE_ID>(i_node));
                    if(l_nextNode != MAX_NODE_ID)
                    {
                        l_pTarget = &(*(iv_nodeInfo[l_nextNode].targets))[0];
                        l_targetFound = true;
                        break;
                    }
                    else
                    {
                        l_targetFound = false;
                        break;
                    }
                }
                else
                {
                    ++l_pTarget;
                    l_targetFound = true;
                    break;
                }
            }
        }
    }
    if(l_targetFound == false)
    {
        l_pTarget = NULL;
    }

    return l_pTarget;
    #undef TARG_FN
}

//******************************************************************************
// TargetService::getTopLevelTarget
//******************************************************************************

void TargetService::getTopLevelTarget(
    Target*& o_targetHandle) const
{
    #define TARG_FN "getTopLevelTarget(...)"

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    EntityPath l_topLevelPhysicalPath(EntityPath::PATH_PHYSICAL);
    l_topLevelPhysicalPath.addLast(TYPE_SYS, 0);
    o_targetHandle = toTarget(l_topLevelPhysicalPath);

    #undef TARG_FN
}

//******************************************************************************
// TargetService::exists
//******************************************************************************

void TargetService::exists(
    const EntityPath& i_entityPath,
          bool&       o_exists) const
{
    #define TARG_FN "exists(...)"

    o_exists = false;

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
                "USAGE: TargetService not initialized");

    PredicateAttrVal<TARGETING::ATTR_PHYS_PATH> l_entityPathMatches(
        i_entityPath);

    TARGETING::TargetRangeFilter l_targetsWithMatchingEntityPath(
        TARGETING::targetService().begin(),
        TARGETING::targetService().end(),
        &l_entityPathMatches);

    if(l_targetsWithMatchingEntityPath)
    {
        o_exists = true;

        #ifdef EXTRA_SANITY_CHECKING
        ++l_targetsWithMatchingEntityPath;
        if(l_targetsWithMatchingEntityPath)
        {
            TARG_ASSERT(0, TARG_ERR_LOC "Should have found a single match");
        }
        #endif
    }

    #undef TARG_FN
}

//******************************************************************************
// TargetService::toTarget
//******************************************************************************

Target* TargetService::toTarget(
    const EntityPath& i_entityPath) const
{
    #define TARG_FN "toTarget(...)"

    Target* l_pTarget = NULL;

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
        "USAGE: TargetService not initialized");

    if(i_entityPath.type() == EntityPath::PATH_PHYSICAL)
    {
        PredicateAttrVal<TARGETING::ATTR_PHYS_PATH> l_physPathMatches(
            i_entityPath);

        TARGETING::TargetRangeFilter l_targetsWithMatchingPhysPath(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &l_physPathMatches);

        if(l_targetsWithMatchingPhysPath)
        {
            l_pTarget = *l_targetsWithMatchingPhysPath;

            #ifdef EXTRA_SANITY_CHECKING
            ++l_targetsWithMatchingPhysPath;
            if(l_targetsWithMatchingPhysPath)
            {
                TARG_ASSERT(0, TARG_ERR_LOC
                    "Should have found a single target with HUID of 0x%08X "
                    "when searching for physical path",
                    l_pTarget->getAttr<ATTR_HUID>());
            }
            #endif
        }
    }
    else if(i_entityPath.type() == EntityPath::PATH_AFFINITY)
    {
        PredicateAttrVal<TARGETING::ATTR_AFFINITY_PATH> l_affinityPathMatches(
            i_entityPath);

        TARGETING::TargetRangeFilter l_targetsWithMatchingAffinityPath(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &l_affinityPathMatches);

        if(l_targetsWithMatchingAffinityPath)
        {
            l_pTarget = *l_targetsWithMatchingAffinityPath;

            #ifdef EXTRA_SANITY_CHECKING
            ++l_targetsWithMatchingAffinityPath;
            if(l_targetsWithMatchingAffinityPath)
            {
                TARG_ASSERT(0, TARG_ERR_LOC
                    "Should have found a single target with HUID of 0x%08X "
                    "when searching for affinity path",
                    l_pTarget->getAttr<ATTR_HUID>());
            }
            #endif
        }
    }
    else
    {
        TARG_ERR("EntityPath Type [%s] not supported for toTarget Method",
            i_entityPath.pathTypeAsString());
    }

    return l_pTarget;

    #undef TARG_FN
}

//******************************************************************************
// TargetService::masterProcChipTargetHandle
//******************************************************************************

void TargetService::masterProcChipTargetHandle(
          Target*& o_masterProcChipTargetHandle,
    const Target*  i_pNodeTarget) const
{
    #define TARG_FN "masterProcChipTargetHandle(...)"
    errlHndl_t pError = NULL;

    pError = queryMasterProcChipTargetHandle(
        o_masterProcChipTargetHandle,
        i_pNodeTarget);
    if(pError != NULL)
    {
        /* Error is already traced w.r.t api called, not repeating here*/
        TARG_ERR("Not able to find the Master Proc Chip Target Handle");
        delete pError;
        pError = NULL;
        o_masterProcChipTargetHandle = NULL;
    }
    #undef TARG_FN
}

//******************************************************************************
// TargetService::queryMasterProcChipTargetHandle
//******************************************************************************

errlHndl_t TargetService::queryMasterProcChipTargetHandle(
          Target*&      o_masterProcChipTargetHandle,
    const Target* const i_pNodeTarget) const
{
    #define TARG_FN "queryMasterProcChipTargetHandle(...)"

    errlHndl_t pError = NULL;
    Target* pMasterProc = NULL;
    o_masterProcChipTargetHandle = NULL;

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
        "USAGE: TargetService not initialized");

    do {

    if(i_pNodeTarget == NULL)
    {
        static Target* pActingMasterTarget = NULL;

        if(!pActingMasterTarget || PLAT::PROPERTIES::MULTINODE_AWARE)
        {
            // Create filter that finds acting master processors
            PredicateCTM procFilter(CLASS_CHIP, TYPE_PROC);
            PredicateAttrVal<ATTR_PROC_MASTER_TYPE> actingMasterFilter(
                PROC_MASTER_TYPE_ACTING_MASTER);
            PredicatePostfixExpr actingMasterProcFilter;
            actingMasterProcFilter.push(&procFilter).push(
                    &actingMasterFilter).And();

            // Find all the acting master processors (max one per physical
            // node), sorted by fabric node ID, and return the one with the
            // lowest fabric node ID
            TargetRangeFilter blueprintProcs(
                targetService().begin(),
                targetService().end(),
                &actingMasterProcFilter);

            TARGETING::ATTR_FABRIC_NODE_ID_type minFabricNodeId =
                TARGETING::FABRIC_NODE_ID_NOT_FOUND;
            for(; blueprintProcs; ++blueprintProcs)
            {
                TARGETING::ATTR_FABRIC_NODE_ID_type fabricNodeId =
                    blueprintProcs->getAttr<
                        TARGETING::ATTR_FABRIC_NODE_ID>();
                if(fabricNodeId < minFabricNodeId)
                {
                    minFabricNodeId = fabricNodeId;
                    pMasterProc = *blueprintProcs;
                }
            }

            if(   (pMasterProc)
               && (!PLAT::PROPERTIES::MULTINODE_AWARE))
            {
                pActingMasterTarget = pMasterProc;
            }
        }
        else
        {
            pMasterProc = pActingMasterTarget;
        }
    }

    /* We have a valid Target at this point */
    /* Would verify if the target given by user is a node target */
    else if( (i_pNodeTarget->getAttr<ATTR_CLASS>() == CLASS_ENC) &&
        (i_pNodeTarget->getAttr<ATTR_TYPE>() == TYPE_NODE) )
    {
        // Create predicate which looks for an acting master processor chip
        PredicateAttrVal<ATTR_PROC_MASTER_TYPE> l_procMasterMatches(
            PROC_MASTER_TYPE_ACTING_MASTER);
        PredicateCTM
              l_procPredicate(TARGETING::CLASS_CHIP,TARGETING::TYPE_PROC);
        PredicatePostfixExpr  l_masterProcFilter;
        l_masterProcFilter.push(&l_procPredicate).push(
            &l_procMasterMatches).And();

        // Find the acting master within the node
        TARGETING::TargetHandleList l_masterProclist;
        getAssociated(l_masterProclist,
            const_cast<const Target*>(i_pNodeTarget), CHILD, ALL,
                    &l_masterProcFilter);

        if(!l_masterProclist.empty())
        {
            pMasterProc = l_masterProclist[0];
        }
    }
    else
    {
        TARG_ERR("Invalid Node Target to query Master Proc "
            "- NULL Master Proc Handle Returned. HUID of Target Passed "
            "[0x%08X]", i_pNodeTarget->getAttr<ATTR_HUID>());

        /*@
         * @errortype
         * @refcode    LIC_REFCODE
         * @subsys     EPUB_FIRMWARE_SP
         * @moduleid   TARG_MOD_QUERY_MASTER_PROC_CHIP
         * @reasoncode TARG_RC_INVALID_NODE
         * @userData1  HUID of Target Passed
         * @devdesc    Error: User Passed an invalid Node Target to find the
         * master proc handle
         */
        UTIL::createTracingError(
            TARG_MOD_QUERY_MASTER_PROC_CHIP,
            TARG_RC_INVALID_NODE,
            i_pNodeTarget->getAttr<ATTR_HUID>(),
            0,0,0,
            pError);
        break;
    }

    if(pMasterProc == NULL)
    {
        TARG_ERR("Failed to find acting master processor, given input node of "
            "i_pNodeTarget = %p with HUID of 0x%08X",i_pNodeTarget,
            i_pNodeTarget ? i_pNodeTarget->getAttr<ATTR_HUID>() : 0);

        /*@
         * @errortype
         * @refcode    LIC_REFCODE
         * @subsys     EPUB_FIRMWARE_SP
         * @moduleid   TARG_MOD_QUERY_MASTER_PROC_CHIP
         * @reasoncode TARG_RC_TARGET_NOT_FOUND
         * @userData1  HUID of Target Passed
         * @devdesc    Error: User Passed an invalid Node Target to find the
         *     master proc handle
         */
        UTIL::createTracingError(
            TARG_MOD_QUERY_MASTER_PROC_CHIP,
            TARG_RC_TARGET_NOT_FOUND,
            i_pNodeTarget ? i_pNodeTarget->getAttr<ATTR_HUID>() : 0,
            0,0,0,
            pError);
        break;
    }
    else
    {
        o_masterProcChipTargetHandle = pMasterProc;
    }

    } while(0);

    return pError;
    #undef TARG_FN
}

//******************************************************************************
// TargetService::tryGetPath
//******************************************************************************

bool TargetService::tryGetPath(
    const ATTRIBUTE_ID  i_attr,
    const Target* const i_pTarget,
          EntityPath&   o_entityPath) const
{
    #define TARG_FN "tryGetPath(...)"

    bool l_exist = false;

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
                "USAGE: TargetService not initialized");

    switch (i_attr)
    {
        case ATTR_PHYS_PATH:
            l_exist = i_pTarget->tryGetAttr<ATTR_PHYS_PATH> (o_entityPath);
            break;
        case ATTR_AFFINITY_PATH:
            l_exist = i_pTarget->tryGetAttr<ATTR_AFFINITY_PATH> (
                o_entityPath);
            break;
        case ATTR_POWER_PATH:
            l_exist = i_pTarget->tryGetAttr<ATTR_POWER_PATH> (o_entityPath);
            break;
        default:
            TARG_ASSERT(0, TARG_ERR_LOC
                        "i_attr = 0x%08X does not map to an entity path",
                        i_attr);
            break;
    }

    return l_exist;

    #undef TARG_FN
}

//******************************************************************************
// TargetService::getAssociated
//******************************************************************************

void TargetService::getAssociated(
          TargetHandleList&    o_list,
    const Target* const        i_pTarget,
    const ASSOCIATION_TYPE     i_type,
    const RECURSION_LEVEL      i_recursionLevel,
    const PredicateBase* const i_pPredicate) const
{
    #define TARG_FN "getAssociated(...)"

    do {

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
                "USAGE: TargetService not initialized");

    TARG_ASSERT(   (i_pTarget != NULL)
                && (i_pTarget != MASTER_PROCESSOR_CHIP_TARGET_SENTINEL),
                TARG_ERR_LOC "Caller tried to get association using a NULL "
                "target handle or the master processor chip target handle "
                "sentinel. i_pTarget = %p",i_pTarget);

    // Start with no elements
    o_list.clear();

    // Figure out which attribute to look up
    for (AssociationMappings_t::const_iterator
            assocIter = iv_associationMappings.begin();
            assocIter != iv_associationMappings.end();
            ++assocIter)
    {
        if (i_type == (*assocIter).associationType)
        {
            EntityPath l_entityPath;

            bool l_exist = tryGetPath((*assocIter).attr,
                i_pTarget, l_entityPath);

            if (l_exist)
            {
                if ((*assocIter).associationDir == INWARDS)
                {
                    (void) _getInwards((*assocIter).attr,
                        i_recursionLevel, l_entityPath, i_pPredicate, o_list);
                }
                else if ((*assocIter).associationDir == OUTWARDS)
                {
                    (void) _getOutwards((*assocIter).attr,
                        i_recursionLevel, l_entityPath, i_pPredicate, o_list);
                }
                else
                {
                    TARG_ASSERT(0, TARG_LOC
                           "(*assocIter).associationDir "
                           "= 0x%X not supported",
                           (*assocIter).associationDir);
                }
            }
            break;
        }
    }

    } while (0);

    #undef TARG_FN
}

//******************************************************************************
// TargetService::dump()
//******************************************************************************

void TargetService::dump() const
{
    #define TARG_FN "dump(...)"

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    TARGETING::TargetRangeFilter l_allTargets(
        TARGETING::targetService().raw_begin(),
        TARGETING::targetService().raw_end(),
        NULL);

    uint32_t l_totalTargetCnt = 0;
    for(;l_allTargets; ++l_allTargets)
    {
        ++l_totalTargetCnt;
        TARG_INF(
            "[Target %d] "
            "Class = 0x%X, "
            "Type = 0x%X, "
            "Model = 0x%X",
            l_totalTargetCnt,
            l_allTargets->getAttr<ATTR_CLASS>(),
            l_allTargets->getAttr<ATTR_TYPE>(),
            l_allTargets->getAttr<ATTR_MODEL>());

        TARG_INF("Physical");
        l_allTargets->getAttr<ATTR_PHYS_PATH>().dump();

        EntityPath l_entityPath;
        if( l_allTargets->tryGetAttr<ATTR_AFFINITY_PATH>(l_entityPath) )
        {
            TARG_INF("Affinity");
            l_entityPath.dump();
        }

        if( l_allTargets->tryGetAttr<ATTR_POWER_PATH>(l_entityPath) )
        {
            TARG_INF("Power");
            l_entityPath.dump();
        }

        DUMMY_RW_ATTR l_dummyRw;
        memset(l_dummyRw,0x00,sizeof(l_dummyRw));
        if (l_allTargets->tryGetAttr<ATTR_DUMMY_RW> (l_dummyRw))
        {
            TARG_INF("Dummy = 0x%X",
                l_dummyRw[0][0][0]);
        }

        TARG_INF("Supports FSI SCOM = %d",
            l_allTargets->getAttr<
            ATTR_PRIMARY_CAPABILITIES>().supportsFsiScom);
        TARG_INF("Supports XSCOM SCOM = %d",
            l_allTargets->getAttr<
            ATTR_PRIMARY_CAPABILITIES>().supportsXscom);
        TARG_INF("Supports Inband SCOM = %d",
            l_allTargets->getAttr<
            ATTR_PRIMARY_CAPABILITIES>().supportsInbandScom);

        ScomSwitches l_switches = {0};
        if ( l_allTargets->tryGetAttr<
                ATTR_SCOM_SWITCHES>(l_switches) )
        {
            TARG_INF("Use FSI SCOM = %d",l_switches.useFsiScom);
            TARG_INF("Use XSCOM = %d",l_switches.useXscom);
            TARG_INF("Use inband SCOM = %d",l_switches.useInbandScom);
        }

        uint64_t l_xscomBaseAddr = 0;
        if ( l_allTargets->tryGetAttr<
                ATTR_XSCOM_BASE_ADDRESS>(l_xscomBaseAddr) )
        {
            TARG_INF("XSCOM Base Address = 0x%016llX",l_xscomBaseAddr);
        }

        uint8_t l_Node_Id = 0;
        if ( l_allTargets->tryGetAttr<
                ATTR_FABRIC_NODE_ID>(l_Node_Id))
        {
            TARG_INF("XSCOM Node ID = 0x%X",l_Node_Id);
        }

        uint8_t l_Chip_Id = 0;
        if ( l_allTargets->tryGetAttr<
                ATTR_FABRIC_CHIP_ID>(l_Chip_Id))
        {
            TARG_INF("XSCOM Chip ID = 0x%X",l_Chip_Id);
        }

    }

    return;

    #undef TARG_FN
}


//******************************************************************************
// TargetService::writeSectionData
//******************************************************************************
bool TargetService::writeSectionData(
    const std::vector<sectionRefData>& i_pages)
{
    #define TARG_FN "writeSectionData(...)"
    TARG_ENTER();
    bool l_response = false;
    if(i_pages.size() != 0)
    {
        l_response =
            TARG_GET_SINGLETON(TARGETING::theAttrRP).writeSectionData(i_pages);
    }
    TARG_EXIT();

    return l_response;
    #undef TARG_FN
}

//******************************************************************************
// TargetService::readSectionData
//******************************************************************************
void TargetService::readSectionData(
          std::vector <sectionRefData>& o_pages,
    const SECTION_TYPE                  i_sectionId,
    const NODE_ID                       i_nodeId)
{
    #define TARG_FN "readSectionData(...)"
    TARG_ENTER();

    TARG_GET_SINGLETON(TARGETING::theAttrRP).readSectionData(
        o_pages, i_sectionId, i_nodeId);

    TARG_EXIT();

    #undef TARG_FN
}

//******************************************************************************
// TargetService::_configureTargetPool
//******************************************************************************

void TargetService::_configureTargetPool(
    NodeSpecificInfo& i_nodeInfoContainer)
{
#define TARG_FN "_configureTargetPool(...)"

    TARG_ENTER();

    _maxTargets(i_nodeInfoContainer);

    // iv_pPnor--> points to uint32_t* --> points to --> uint32_t, targets[]
    //                   (uint32_t*)+1 --> points to ------------> targets[]
    const AbstractPointer<uint32_t>* ppNumTargets
        = static_cast<const AbstractPointer<uint32_t>*>(
              i_nodeInfoContainer.pPnor);

    i_nodeInfoContainer.targets =
           reinterpret_cast< Target(*)[] > (
               (TARG_TO_PLAT_PTR_AND_INC(*ppNumTargets,1)));

    TARG_ASSERT(i_nodeInfoContainer.targets, TARG_ERR_LOC
                "FATAL: Could not determine location of targets");
    TARG_INF("i_nodeInfoContainer.targets = %p", i_nodeInfoContainer.targets);

    // Only translate addresses on platforms where addresses are 4 bytes wide
    // (FSP). The compiler should perform dead code elimination of this path on
    // platforms with 8 byte wide addresses (Hostboot), since the "if" check
    // can be statically computed at compile time.
    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        i_nodeInfoContainer.targets = static_cast<Target(*)[]>(
             TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(
                    i_nodeInfoContainer.targets, i_nodeInfoContainer.nodeId));
        TARG_ASSERT(i_nodeInfoContainer.targets, TARG_ERR_LOC
                    "FATAL: Could not determine location of targets after "
                    "address translation");
        TARG_INF("i_nodeInfoContainer.targets after translation = %p",
                 i_nodeInfoContainer.targets);
    }

    TARG_EXIT();

    #undef TARG_FN
}

//******************************************************************************
// TargetService::_maxTargets
//******************************************************************************

void TargetService::_maxTargets(NodeSpecificInfo& io_nodeInfoContainer)
{
    #define TARG_FN "_maxTargets(...)"

    // Target count found by following the pointer pointed to by the iv_pPnor
    // pointer.
    const AbstractPointer<uint32_t>* pNumTargetsPtr
        = static_cast<const AbstractPointer<uint32_t>*>(
                io_nodeInfoContainer.pPnor);
    uint32_t* pNumTargets = TARG_TO_PLAT_PTR(*pNumTargetsPtr);

    // Only translate addresses on platforms where addresses are 4 bytes wide
    // (FSP). The compiler should perform dead code elimination of this path on
    // platforms with 8 byte wide addresses (Hostboot), since the "if" check
    // can be statically computed at compile time.
    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        pNumTargets = static_cast<uint32_t*>(
                TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(
                        pNumTargets, io_nodeInfoContainer.nodeId));
    }

    TARG_ASSERT(pNumTargets, TARG_ERR_LOC
                "FATAL: Could not determine location of targets after "
                "address translation");

    io_nodeInfoContainer.maxTargets = *pNumTargets;

    TARG_INF("Max targets = %d", io_nodeInfoContainer.maxTargets);

    #undef TARG_FN
}

//******************************************************************************
// TargetService::_getInwards
//******************************************************************************

void TargetService::_getInwards(
    const ATTRIBUTE_ID         i_attr,
    const RECURSION_LEVEL      i_recursionLevel,
          EntityPath           i_entityPath,
    const PredicateBase* const i_pPredicate,
          TargetHandleList&    o_list) const
{
    #define TARG_FN "_getInwards(...)"

    while (i_entityPath.size() > 1)
    {
        i_entityPath.removeLast();

        TargetIterator l_allTargets;

        for(l_allTargets = targetService().begin();
            l_allTargets != targetService().end();
            ++l_allTargets)
        {
            EntityPath l_candidatePath;
            bool l_candidateFound = false;

            l_candidateFound = tryGetPath(i_attr,
                                   (*l_allTargets),
                                   l_candidatePath);

            if ( (l_candidateFound)
                    && (l_candidatePath == i_entityPath)
                    && (   (i_pPredicate == NULL)
                        || (*i_pPredicate)(*l_allTargets) ) )
            {
                o_list.push_back(*l_allTargets);
                break;
            }
        }

        if (i_recursionLevel == IMMEDIATE)
        {
            break;
        }
    }

    #undef TARG_FN
}

//******************************************************************************
// TargetService::_getOutwards
//******************************************************************************

void TargetService::_getOutwards(
    const ATTRIBUTE_ID         i_attr,
    const RECURSION_LEVEL      i_recursionLevel,
          EntityPath           i_entityPath,
    const PredicateBase* const i_pPredicate,
          TargetHandleList&    o_list) const
{
    #define TARG_FN "_getOutwards(...)"
    do
    {
        // If at max depth (a leaf path element), no children possible
        if (i_entityPath.size() >= EntityPath::MAX_PATH_ELEMENTS)
        {
            break;
        }

        // Find the children (immediate, or all), depending on recursion level
        TargetIterator l_allTargets;

        for(l_allTargets = targetService().begin();
            l_allTargets != targetService().end();
            ++l_allTargets)
        {
            EntityPath l_candidatePath;
            bool l_candidateFound = tryGetPath(i_attr, *l_allTargets,
                                        l_candidatePath);
            if (l_candidateFound)
            {
                if ( ( (i_recursionLevel == IMMEDIATE)
                          && (l_candidatePath.size() == i_entityPath.size() +1))
                        || (   (i_recursionLevel == ALL)
                            && (l_candidatePath.size() > i_entityPath.size())))
                {
                    if (i_entityPath.equals(l_candidatePath,i_entityPath.size())
                           && (  (i_pPredicate == NULL)
                                || (*i_pPredicate)(*l_allTargets) ) )
                    {
                        o_list.push_back(*l_allTargets);
                    }
                }
            }
        }

    } while (0);

    #undef TARG_FN
}

//******************************************************************************
// TargetService::setMasterNode
//******************************************************************************
errlHndl_t TargetService::setMasterNode(const Target* i_pTarget)
{
    #define TARG_FN "setMasterNode(...)"
    errlHndl_t pError = NULL;

    TARG_ASSERT(i_pTarget != NULL, TARG_ERR_LOC
        "Error: User cannot pass NULL Target in place of Node Target");

    // Check for Node Target
    PredicateCTM l_nodePredicate(CLASS_ENC, TYPE_NODE);
    if(l_nodePredicate(i_pTarget))
    {
        pError = UTIL::setMasterNode(const_cast<Target*>(i_pTarget));
        if(pError)
        {
            TARG_ERR("Master Node Attribute Set Failed for Node [0x%08X]",
                    i_pTarget->getAttr<ATTR_HUID>());
        }
    }
    else
    {
        // Create Error
        /*@
         * @errortype
         * @refcode    LIC_REFCODE
         * @subsys     EPUB_FIRMWARE_SP
         * @moduleid   TARG_MOD_SET_MASTER_NODE
         * @reasoncode TARG_RC_INVALID_NODE
         * @userData1  HUID of Target Passed
         * @devdesc    Error: User Passed an invalid Node Target
         */
        UTIL::createTracingError(
                TARG_MOD_SET_MASTER_NODE,
                TARG_RC_INVALID_NODE,
                i_pTarget->getAttr<ATTR_HUID>(),
                0,0,0,
                pError);
    }

    return pError;
    #undef TARG_FN
}

//******************************************************************************
// TargetService::isNonMasterNodeSystemTarget
//******************************************************************************

bool TargetService::isNonMasterNodeSystemTarget(const Target* i_pTarget) const
{
    #define TARG_FN "isNonMasterNodeSystemTarget(...)"

    Target* l_pTarget = const_cast<Target*>(i_pTarget);
    bool l_isNonMasterNodeSystemTarget = false;
    TARG_ASSERT(l_pTarget != NULL, TARG_ERR_LOC
            "Cannot pass a NULL Target");

    if( (l_pTarget->getAttr<ATTR_CLASS>() == CLASS_SYS) &&
         (l_pTarget->getAttr<ATTR_TYPE>() == TYPE_SYS) )
    {
        if(true == UTIL::isNonMasterNodeSystemTarget(i_pTarget))
        {
            l_isNonMasterNodeSystemTarget = true;
        }
    }
    return l_isNonMasterNodeSystemTarget;
    #undef TARG_FN
}

//******************************************************************************
// TargetService::getNumInitializedNodes
//******************************************************************************

uint8_t TargetService::getNumInitializedNodes() const
{
    #define TARG_FN "getNumInitializedNodes(...)"
    return MAX_NODE_ID;
    #undef TARG_FN
}

//******************************************************************************
// TargetService::initDefaultMasterNode
//******************************************************************************

void TargetService::initDefaultMasterNode()
{
    #define TARG_FN "initDefaultMasterNode(...)"
    TARG_ENTER();
    errlHndl_t pError = NULL;
    if(!iv_initialized)
    {
        TARG_INF("Default Master Node Selection Mode");

        // See if we already have a persistent Master node from previous run
        // We have to go via this route since iv_initialized flag is not set,
        // so we can't use any targetservice api to do this. Have to manual go
        // over.
        for(uint8_t l_nodeCnt=0; l_nodeCnt<MAX_NODE_ID; ++l_nodeCnt)
        {
            if((iv_nodeInfo[l_nodeCnt].initialized) &&
                    (iv_nodeInfo[l_nodeCnt].maxTargets > 0))
            {
                for(uint32_t l_targetCnt=0;
                        l_targetCnt<iv_nodeInfo[l_nodeCnt].maxTargets;
                        ++l_targetCnt)
                {
                    if(((*(iv_nodeInfo[l_nodeCnt].targets))[
                            l_targetCnt].getAttr<ATTR_CLASS>() == CLASS_ENC) &&
                            ((*(iv_nodeInfo[l_nodeCnt].targets))[
                             l_targetCnt].getAttr<ATTR_TYPE>() == TYPE_NODE))
                    {
                        if(UTIL::isThisMasterNodeTarget(
                           &((*(iv_nodeInfo[l_nodeCnt].targets))[l_targetCnt])))
                        {
                            // We have found a previous instance of master node
                            // target, no need for sync here, since it would
                            // have been taken care of when we updated the
                            // master node last time around.
                            iv_initialized = true;
                            TARG_INF("Previous Master Node Instance Found - "
                               "Node [%d]", l_nodeCnt);
                            break;
                        }
                    }
                }
                if(iv_initialized)
                {
                    break;
                }
            }
        }
        if(!iv_initialized)
        {
            TARG_INF("No previous master node found.. Setting a default one");
            for(uint8_t l_nodeCnt=0; l_nodeCnt<MAX_NODE_ID; ++l_nodeCnt)
            {
                if((iv_nodeInfo[l_nodeCnt].initialized) &&
                        (iv_nodeInfo[l_nodeCnt].maxTargets > 0))
                {
                    // Need to go over each target to search for Node, cannot
                    // use rangefilter here since targeting is yet not
                    // initialized.
                    for(uint32_t l_targetCnt=0;
                            l_targetCnt<iv_nodeInfo[l_nodeCnt].maxTargets;
                            ++l_targetCnt)
                    {
                        if(((*(iv_nodeInfo[l_nodeCnt].targets))[
                             l_targetCnt].getAttr<ATTR_CLASS>() == CLASS_ENC) &&
                              ((*(iv_nodeInfo[l_nodeCnt].targets))[
                               l_targetCnt].getAttr<ATTR_TYPE>() == TYPE_NODE))
                        {
                            // Just do bare minimum stuff i.e. just set the
                            // Master Node Attribute
                            pError = UTIL::setDefaultMasterNodeWithoutSync(
                                &((*(iv_nodeInfo[l_nodeCnt].targets))[
                                    l_targetCnt]));
                            if(pError)
                            {
                                TARG_ERR("Setting of default master node "
                                    "target failed");
                                TARG_ASSERT(0, TARG_ERR_LOC
                                    "Default Master Node Set Failed at"
                                    " Init time");
                            }
                            iv_initialized = true;
                            break;
                        }
                    }
                    if(iv_initialized == true)
                    {
                        // We have setted the default Master Node, let's just
                        // sync it up.
                        // Above we had to callup special mode to set Master
                        // node, since targeting is not initalized yet, cannot
                        // use the basic features of predicates, rangefilter
                        // and all.
                        Target* l_pSysTarget = NULL;
                        getTopLevelTarget(l_pSysTarget);
                        TARG_ASSERT(l_pSysTarget != NULL, TARG_ERR_LOC
                            "Top Level Target cannot be NULL");
                        pError = UTIL::SyncMasterSystemTarget(l_pSysTarget);
                        if(pError)
                        {
                            TARG_ASSERT(0, TARG_ERR_LOC
                                "System Target Sync has failed at Init Time");
                        }
                        break;
                    }
                }
            }
        }
    }
    else
    {
        TARG_INF("TargetService already initialized");
    }
    TARG_EXIT();
    #undef TARG_FN
}

//******************************************************************************
// TargetService::getMasterNodeTarget
//******************************************************************************

void TargetService::getMasterNodeTarget(
    Target*& o_masterNodeTarget) const
{
    #define TARG_FN "getMasterNodeTarget(...)"

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    // Keep the user target handle initialize to NULL
    o_masterNodeTarget = NULL;
    UTIL::getMasterNodeTarget(o_masterNodeTarget);

    TARG_ASSERT(o_masterNodeTarget != NULL, TARG_ERR_LOC
           "Node Target of the System's Master Node cannot be NULL");

    #undef TARG_FN
}

#undef TARG_CLASS

#undef TARG_NAMESPACE

} // End namespace TARGETING

