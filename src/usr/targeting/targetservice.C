
/**
 *  @file targetservice.C
 *
 *  @brief Implementation of the TargetService class
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Other components
#include <sys/task.h>
#include <trace/interface.H>
#include <initservice/taskargs.H>

// This component
#include <targeting/targetservice.H>
#include "trace.H"
#include "fakepnordata.H"

//******************************************************************************
// targetService
//******************************************************************************

namespace TARGETING
{


#define TARG_NAMESPACE "TARGETING::"


//******************************************************************************
// _start
//******************************************************************************

#define TARG_CLASS ""


/**
 *  @brief Entry point for initialization service to initialize the targeting
 *      code
 *
 *  @note: Link register is configured to automatically invoke task_end() when
 *      this routine returns
 */
extern "C"
void _start(void* io_pArgs)
{
    INITSERVICE::TaskArgs::TaskArgs *pTaskArgs  =
            reinterpret_cast<INITSERVICE::TaskArgs::TaskArgs *>(io_pArgs);

    #define TARG_FN "_start(...)"

    TARG_ENTER();

    TargetService& l_targetService = targetService();
    (void)l_targetService.init();

    TARG_EXIT();

    if  ( pTaskArgs )
    {
        pTaskArgs->waitChildSync();
    }

    task_end();

    #undef TARG_FN
}

//******************************************************************************
// targetService
//******************************************************************************

TARGETING::TargetService& targetService()
{
    #define TARG_FN "targetService()"

    return TARGETING::theTargetService::instance();

    #undef TARG_FN
}

//******************************************************************************
// Component trace buffer
//******************************************************************************

trace_desc_t* g_trac_targeting = NULL;
TRAC_INIT(&g_trac_targeting, "TARG", 4096);

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

    // Get+save pointer to beginning of targeting's swappable config in
    // PNOR.  Note that this will change once PNOR is accessible
    (void)thePnorBuilderService::instance()
        .getTargetingImageBaseAddress(iv_pPnor);

    (void)_configureTargetPool();

    iv_initialized = true;

    TARG_EXIT();

    #undef TARG_FN
}

//******************************************************************************
// TargetService::getTopLevelTarget
//******************************************************************************

void TargetService::getTopLevelTarget(
    Target*& o_targetHandle) const
{
    #define TARG_FN "getTopLevelTarget(...)"

    if (iv_initialized)
    {
        EntityPath l_topLevelPhysicalPath(EntityPath::PATH_PHYSICAL);
        l_topLevelPhysicalPath.addLast(TYPE_SYS, 0);
        o_targetHandle = toTarget(l_topLevelPhysicalPath);
    }
    else
    {
        o_targetHandle = NULL;
        assert(iv_initialized);
    }

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
    if (iv_initialized)
    {
        for (uint32_t i = 0; i < iv_maxTargets; ++i)
        {
            if (i_entityPath == (*iv_targets)[i].getAttr<ATTR_PHYS_PATH> ())
            {
                l_found = true;
            }
        }
    }
    else
    {
        assert(iv_initialized);
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
    if (iv_initialized)
    {
        for (uint32_t i = 0; i < iv_maxTargets; ++i)
        {
            if (i_entityPath == (*iv_targets)[i].getAttr<ATTR_PHYS_PATH> ())
            {
                l_pTarget = &(*iv_targets)[i];
                break;
            }
        }
    }
    else
    {
        assert(iv_initialized);
    }

    return l_pTarget;

    #undef TARG_FN
}

//******************************************************************************
// TargetService::masterProcChipTarget
//******************************************************************************

void TargetService::masterProcChipTargetHandle(
    Target*& o_masterProcChipTargetHandle) const
{
    #define TARG_FN "masterProcChipTargetHandle(...)"

    Target* l_pTarget = NULL;
    if (iv_initialized)
    {
        //@TODO Need to query the actual hardware and cross check it with
        // PNOR to determine the master chip
        // target; for now, just always report sys0.n0.proc0
        EntityPath l_masterProcChipEntityPath(EntityPath::PATH_PHYSICAL);
        l_masterProcChipEntityPath.addLast(TYPE_SYS, 0).addLast(TYPE_NODE, 0)
            .addLast(TYPE_PROC, 0);

        l_pTarget = l_masterProcChipEntityPath.operator->();
    }
    else
    {
        assert(iv_initialized);
    }

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
    if (iv_initialized)
    {
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
                TARG_ERR("BUG; i_attr = 0x%08X does not map to an entity "
                         "path");
                assert(0);
                break;
        }
    }
    else
    {
        assert(iv_initialized);
    }

    return l_exist;

    #undef TARG_FN
}

//******************************************************************************
// TargetService::getAssociated
//******************************************************************************

void TargetService::getAssociated(
    const Target* const     i_pTarget,
    const ASSOCIATION_TYPE  i_type,
    const RECURSION_LEVEL   i_recursionLevel,
          TargetHandleList& o_list) const
{
    #define TARG_FN "getAssociated(...)"

    do {

    assert(iv_initialized);

    if(   (i_pTarget == NULL)
       || (i_pTarget == MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) )
    {
        TARG_ERR("BUG; caller tried to get association using a NULL target "
                 "handle or the master processor chip target handle sentinel. "
                 "i_pTarget = %p",i_pTarget);
        assert(0);
    }

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
                        i_recursionLevel, l_entityPath, o_list);
                }
                else if (iv_associationMappings[i].associationDir
                    == OUTWARDS)
                {
                    (void) _getOutwards(iv_associationMappings[i].attr,
                        i_recursionLevel, l_entityPath, o_list);
                }
                else
                {
                    TARG_ERR("BUG; iv_associationMappings[i].associationDir "
                             "= 0x%X not supported",
                             iv_associationMappings[i].associationDir);
                    assert(0);
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

    if (iv_initialized)
    {
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

            uint8_t l_dummyRw = 0;
            if ((*iv_targets)[i].tryGetAttr<ATTR_DUMMY_RW> (l_dummyRw))
            {
                TARG_INF("Dummy = 0x%X",
                    l_dummyRw);
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
                TARG_INF("XSCOM Base Address = 0x%X",l_xscomBaseAddr);
            }

            XscomChipInfo l_xscomChipInfo = {0};
            if ( (*iv_targets)[i].tryGetAttr<ATTR_XSCOM_CHIP_INFO>(
                l_xscomChipInfo) )
            {
                TARG_INF("XSCOM Node ID = 0x%X",l_xscomChipInfo.nodeId);
                TARG_INF("XSCOM Chip ID = 0x%X",l_xscomChipInfo.chipId);
            }

            I2cChipInfo l_i2cChipInfo = {0};
            if( (*iv_targets)[i].tryGetAttr<ATTR_I2C_CHIP_INFO>( l_i2cChipInfo ) )
            {
                TARG_INF( "I2C Bus Speed = 0x%X",
                          l_i2cChipInfo.busSpeed );
                TARG_INF( "I2C Device Address = 0x%X",
                          l_i2cChipInfo.deviceAddr );
                TARG_INF( "I2C Device Port = 0x%X",
                          l_i2cChipInfo.devicePort );
                TARG_INF( "I2C Master Engine = 0x%X",
                          l_i2cChipInfo.deviceMasterEng );
            }
        }
    }
    else
    {
        assert(iv_initialized);
    }

    return;

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

    iv_targets =
        reinterpret_cast< Target(*)[] > (
            *(reinterpret_cast<uint32_t**>(
                  const_cast<void*>(iv_pPnor))) + 1);
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
    iv_maxTargets = *(*(reinterpret_cast<const uint32_t * const *>(iv_pPnor)));
    return iv_maxTargets;

    #undef TARG_FN
}

//******************************************************************************
// TargetService::_getInwards
//******************************************************************************

void TargetService::_getInwards(
    const ATTRIBUTE_ID      i_attr,
    const RECURSION_LEVEL   i_recursionLevel,
          EntityPath        i_entityPath,
          TargetHandleList& o_list) const
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
            if (l_candidateFound && (l_candidatePath == i_entityPath))
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
    const ATTRIBUTE_ID      i_attr,
    const RECURSION_LEVEL   i_recursionLevel,
          EntityPath        i_entityPath,
          TargetHandleList& o_list) const
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
                if (i_entityPath.equals(l_candidatePath,i_entityPath.size()))
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
