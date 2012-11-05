/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/targetservice.C $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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

// This component
#include <targeting/common/targetservice.H>
#include <targeting/common/predicates/predicates.H>
#include <pnortargeting.H>
#include <targeting/attrrp.H>
#include <targeting/common/trace.H>
#include <targeting/adapters/types.H>

//******************************************************************************
// targetService
//******************************************************************************

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"

#define TARG_CLASS "targetService"

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
    iv_initialized(false), iv_maxTargets(0), iv_pPnor(NULL)
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

void TargetService::init()
{
    #define TARG_FN "init()"

    TARG_ENTER();

    // Build the association mappings
    AssociationAttrMap a1 = {PARENT, INWARDS, ATTR_PHYS_PATH};
    AssociationAttrMap a2 = {CHILD, OUTWARDS, ATTR_PHYS_PATH};
    AssociationAttrMap a3 = {PARENT_BY_AFFINITY, INWARDS, ATTR_AFFINITY_PATH};
    AssociationAttrMap a4 = {CHILD_BY_AFFINITY, OUTWARDS, ATTR_AFFINITY_PATH};
    AssociationAttrMap a5 = {VOLTAGE_SUPPLIER, INWARDS, ATTR_POWER_PATH};
    AssociationAttrMap a6 = {VOLTAGE_CONSUMER, OUTWARDS, ATTR_POWER_PATH};
    iv_associationMappings.push_back(a1);
    iv_associationMappings.push_back(a2);
    iv_associationMappings.push_back(a3);
    iv_associationMappings.push_back(a4);
    iv_associationMappings.push_back(a5);
    iv_associationMappings.push_back(a6);

    // Cache location of RO section containing all the attribute metadata
    TargetingHeader* l_pHdr = reinterpret_cast<TargetingHeader*>(
            TARG_GET_SINGLETON(TARGETING::theAttrRP).getBaseAddress());

    TARG_ASSERT((l_pHdr != NULL), TARG_ERR_LOC
                "FATAL: Targeting header is NULL!")
    TARG_ASSERT((l_pHdr->eyeCatcher == PNOR_TARG_EYE_CATCHER), TARG_ERR_LOC
                "FATAL: Targeting eyecatcher not found; "
                "expected 0x%08X but got 0x%08X",
                PNOR_TARG_EYE_CATCHER,l_pHdr->eyeCatcher);

    iv_pPnor = reinterpret_cast<uint32_t*>(
        (reinterpret_cast<char*>(l_pHdr) + l_pHdr->headerSize));

    (void)_configureTargetPool();

    iv_initialized = true;

    TARG_EXIT();

    #undef TARG_FN
}

//******************************************************************************
// TargetService::begin (non-const version)
//******************************************************************************

TargetService::iterator TargetService::begin()
{
    #define TARG_FN "begin()"

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    Target* l_pFirstTarget = (iv_maxTargets == 0) ? NULL : &(*iv_targets)[0];
    TARG_ASSERT(l_pFirstTarget != NULL, TARG_ERR_LOC
               "FATAL: Could not find any targets");

    return iterator(l_pFirstTarget);

    #undef TARG_FN
}

//******************************************************************************
// TargetService::begin (const version)
//******************************************************************************

//TargetService::const_iterator
_TargetIterator<const Target*> TargetService::begin() const
{
    #define TARG_FN "begin() const"

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    const Target* l_pFirstTarget =
        (iv_maxTargets == 0) ? NULL : &(*iv_targets)[0];
    TARG_ASSERT(l_pFirstTarget != NULL, TARG_ERR_LOC
               "FATAL: Could not find any targets");

    return const_iterator(l_pFirstTarget);

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

    bool l_found = false;

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
                "USAGE: TargetService not initialized");

    for (uint32_t i = 0; i < iv_maxTargets; ++i)
    {
        if (i_entityPath == (*iv_targets)[i].getAttr<ATTR_PHYS_PATH> ())
        {
            l_found = true;
        }
    }

    o_exists = l_found;

    #undef TARG_FN
}

//******************************************************************************
// TargetService::toTarget
//******************************************************************************

Target* TargetService::toTarget(
    const EntityPath& i_entityPath) const
{
    #define TARG_FN "toTarget(...)"

    // Used by -> operator on EntityPath for convenience (can be dangerous
    // though!)
    Target* l_pTarget = NULL;

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
                "USAGE: TargetService not initialized");

    for (uint32_t i = 0; i < iv_maxTargets; ++i)
    {
        bool found = false;
        switch(i_entityPath.type())
        {
            case EntityPath::PATH_PHYSICAL:
                found = (   (i_entityPath)
                         == (*iv_targets)[i].getAttr<ATTR_PHYS_PATH>());
                break;
            case EntityPath::PATH_AFFINITY:
                found = (   (i_entityPath)
                         == (*iv_targets)[i].getAttr<ATTR_AFFINITY_PATH>());
                break;
            default:
                break;
        }

        if (found)
        {
            l_pTarget = &(*iv_targets)[i];
            break;
        }
    }

    return l_pTarget;

    #undef TARG_FN
}

//******************************************************************************
// TargetService::masterProcChipTargetHandle
//******************************************************************************

void TargetService::masterProcChipTargetHandle(
    Target*& o_masterProcChipTargetHandle,
    const uint8_t i_node) const
{
    #define TARG_FN "masterProcChipTargetHandle(...)"

    Target* l_pTarget = NULL;

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
                "USAGE: TargetService not initialized");

    //@TODO Need to query the actual hardware and cross check it with
    // PNOR to determine the master chip
    // target; for now, just always report sys0.n0.proc0
    EntityPath l_masterProcChipEntityPath(EntityPath::PATH_PHYSICAL);
    l_masterProcChipEntityPath.addLast(TYPE_SYS, 0).addLast(TYPE_NODE, i_node)
        .addLast(TYPE_PROC, 0);

    l_pTarget = l_masterProcChipEntityPath.operator->();

    o_masterProcChipTargetHandle = l_pTarget;

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
    for (uint32_t i = 0; i < iv_associationMappings.size(); ++i)
    {
        if (i_type == iv_associationMappings[i].associationType)
        {
            EntityPath l_entityPath;

            bool l_exist = tryGetPath(iv_associationMappings[i].attr,
                i_pTarget, l_entityPath);

            if (l_exist)
            {
                if (iv_associationMappings[i].associationDir == INWARDS)
                {
                    (void) _getInwards(iv_associationMappings[i].attr,
                        i_recursionLevel, l_entityPath, i_pPredicate, o_list);
                }
                else if (iv_associationMappings[i].associationDir
                    == OUTWARDS)
                {
                    (void) _getOutwards(iv_associationMappings[i].attr,
                        i_recursionLevel, l_entityPath, i_pPredicate, o_list);
                }
                else
                {
                    TARG_ASSERT(0, TARG_LOC
                           "iv_associationMappings[i].associationDir "
                           "= 0x%X not supported",
                           iv_associationMappings[i].associationDir);
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

    TARG_INF("Targets (size=%d):",
             sizeof(Target)*iv_maxTargets);

    for (uint32_t i = 0; i < iv_maxTargets; ++i)
    {
        TARG_INF(
            "[Target %d] "
            "Class = 0x%X, "
            "Type = 0x%X, "
            "Model = 0x%X",
            i,
            (*iv_targets)[i].getAttr<ATTR_CLASS>(),
            (*iv_targets)[i].getAttr<ATTR_TYPE>(),
            (*iv_targets)[i].getAttr<ATTR_MODEL>());
        TARG_INF("Physical");
        (*iv_targets)[i].getAttr<ATTR_PHYS_PATH>().dump();

        EntityPath l_entityPath;
        if( (*iv_targets)[i].tryGetAttr<ATTR_AFFINITY_PATH>(l_entityPath) )
        {
            TARG_INF("Affinity");
            l_entityPath.dump();
        }

        if( (*iv_targets)[i].tryGetAttr<ATTR_POWER_PATH>(l_entityPath) )
        {
            TARG_INF("Power");
            l_entityPath.dump();
        }

        DUMMY_RW_ATTR l_dummyRw;
        memset(l_dummyRw,0x00,sizeof(l_dummyRw));
        if ((*iv_targets)[i].tryGetAttr<ATTR_DUMMY_RW> (l_dummyRw))
        {
            TARG_INF("Dummy = 0x%X",
                l_dummyRw[0][0][0]);
        }

        TARG_INF("Supports FSI SCOM = %d",
        (*iv_targets)[i].getAttr<ATTR_PRIMARY_CAPABILITIES>()
            .supportsFsiScom);
        TARG_INF("Supports XSCOM SCOM = %d",
        (*iv_targets)[i].getAttr<ATTR_PRIMARY_CAPABILITIES>()
            .supportsXscom);
        TARG_INF("Supports Inband SCOM = %d",
        (*iv_targets)[i].getAttr<ATTR_PRIMARY_CAPABILITIES>()
            .supportsInbandScom);

        ScomSwitches l_switches = {0};
        if ( (*iv_targets)[i].tryGetAttr<ATTR_SCOM_SWITCHES>(l_switches) )
        {
            TARG_INF("Use FSI SCOM = %d",l_switches.useFsiScom);
            TARG_INF("Use XSCOM = %d",l_switches.useXscom);
            TARG_INF("Use inband SCOM = %d",l_switches.useInbandScom);
        }

        uint64_t l_xscomBaseAddr = 0;
        if ( (*iv_targets)[i].tryGetAttr<ATTR_XSCOM_BASE_ADDRESS>(
            l_xscomBaseAddr) )
        {
            TARG_INF("XSCOM Base Address = 0x%016llX",l_xscomBaseAddr);
        }

        uint8_t l_Node_Id = 0;
        if ( (*iv_targets)[i].tryGetAttr<ATTR_FABRIC_NODE_ID>(l_Node_Id))
        {
            TARG_INF("XSCOM Node ID = 0x%X",l_Node_Id);
        }

        uint8_t l_Chip_Id = 0;
        if ( (*iv_targets)[i].tryGetAttr<ATTR_FABRIC_CHIP_ID>(l_Chip_Id))
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
        TARG_GET_SINGLETON(TARGETING::theAttrRP).writeSectionData(i_pages);
        l_response = true;
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
    const SECTION_TYPE i_sectionId)
{
    #define TARG_FN "readSectionData(...)"
    TARG_ENTER();

    TARG_GET_SINGLETON(TARGETING::theAttrRP).readSectionData(
                                                     o_pages, i_sectionId);

    TARG_EXIT();

    #undef TARG_FN
}

//******************************************************************************
// TargetService::_configureTargetPool
//******************************************************************************

void TargetService::_configureTargetPool()
{
#define TARG_FN "_configureTargetPool(...)"

    TARG_ENTER();

    _maxTargets();

    // iv_pPnor--> points to uint32_t* --> points to --> uint32_t, targets[]
    //                   (uint32_t*)+1 --> points to ------------> targets[]
    const AbstractPointer<uint32_t>* ppNumTargets
        = static_cast<const AbstractPointer<uint32_t>*>(iv_pPnor);
    iv_targets =
           reinterpret_cast< Target(*)[] > (
               (TARG_TO_PLAT_PTR_AND_INC(*ppNumTargets,1)));
    TARG_ASSERT(iv_targets, TARG_ERR_LOC
                "FATAL: Could not determine location of targets");
    TARG_INF("iv_targets = %p", iv_targets);

    // Only translate addresses on platforms where addresses are 4 bytes wide
    // (FSP). The compiler should perform dead code elimination of this path on
    // platforms with 8 byte wide addresses (Hostboot), since the "if" check
    // can be statically computed at compile time.
    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        iv_targets = static_cast<Target(*)[]>(
                TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(
                        iv_targets));
        TARG_ASSERT(iv_targets, TARG_ERR_LOC
                    "FATAL: Could not determine location of targets after "
                    "address translation");
        TARG_INF("iv_targets after translation = %p", iv_targets);
    }

    TARG_EXIT();

    #undef TARG_FN
}

//******************************************************************************
// TargetService::_maxTargets
//******************************************************************************

uint32_t TargetService::_maxTargets()
{
    #define TARG_FN "_maxTargets(...)"

    // Target count found by following the pointer pointed to by the iv_pPnor
    // pointer.
    const AbstractPointer<uint32_t>* pNumTargetsPtr
        = static_cast<const AbstractPointer<uint32_t>*>(iv_pPnor);
    uint32_t* pNumTargets = TARG_TO_PLAT_PTR(*pNumTargetsPtr);

    // Only translate addresses on platforms where addresses are 4 bytes wide
    // (FSP). The compiler should perform dead code elimination of this path on
    // platforms with 8 byte wide addresses (Hostboot), since the "if" check
    // can be statically computed at compile time.
    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        pNumTargets = static_cast<uint32_t*>(
                TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(
                        pNumTargets));
    }

    iv_maxTargets = *pNumTargets;

    TARG_INF("Max targets = %d",iv_maxTargets);

    return iv_maxTargets;

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
        for (uint32_t i = 0; i < iv_maxTargets; ++i)
        {
            EntityPath l_candidatePath;
            bool l_candidateFound = tryGetPath(i_attr, &(*iv_targets)[i],
                l_candidatePath);
            if (   l_candidateFound
                && (l_candidatePath == i_entityPath)
                && (   (i_pPredicate == NULL)
                    || (*i_pPredicate)( &(*iv_targets)[i]) ) )
            {
                o_list.push_back(&(*iv_targets)[i]);
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
    #define TARG_FN "_getOutwards()...)"

    do {

    // If at max depth (a leaf path element), no children possible
    if (i_entityPath.size() >= EntityPath::MAX_PATH_ELEMENTS)
    {
        break;
    }

    // Find the children (immediate, or all), depending on recursion level
    for (uint32_t i = 0; i < iv_maxTargets; ++i)
    {
        EntityPath l_candidatePath;
        bool l_candidateFound = tryGetPath(i_attr, &(*iv_targets)[i],
            l_candidatePath);
        if (l_candidateFound)
        {
            if (   (   (i_recursionLevel == IMMEDIATE)
                    && (l_candidatePath.size() == i_entityPath.size() + 1))
                || (   (i_recursionLevel == ALL)
                    && (l_candidatePath.size() > i_entityPath.size())))
            {
                if (   i_entityPath.equals(l_candidatePath,i_entityPath.size())
                    && (   (i_pPredicate == NULL)
                        || (*i_pPredicate)( &(*iv_targets)[i]) ) )
                {
                    o_list.push_back(&(*iv_targets)[i]);
                }
            }
        }
    }

    } while (0);

    #undef TARG_FN
}

#undef TARG_CLASS

#undef TARG_NAMESPACE

} // End namespace TARGETING

