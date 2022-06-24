/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/targetservice.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
#include <algorithm>

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
#include <attributestrings.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/util.H>
#include <memoize.H>

#ifdef __HOSTBOOT_MODULE
// System
#include <sys/mm.h>
// Generated

#include <arch/pirformat.H>
#include <mutexattributes.H>
#include <sys/task.h>
#include <sys/misc.h>

// Console
#include <console/uartif.H>
#include <console/consoleif.H>
#endif

#undef EXTRA_SANITY_CHECKING

// display macros
#define FORMAT_WIDTH_2 2
#define FORMAT_WIDTH_4 4
#define FORMAT_WIDTH_8 8
#define FORMAT_WIDTH_16 16
#define STRINGIFY(x) #x

// builds a format string like "%10s=%08llX" or "%10s=%016llX"
#define BUILD_FORMAT_STRING2(num1, num2) STRINGIFY(%10s=%0##num1##llX %s=%0##num2##llX)

#define TRACE_TARGET_INFO(name1, bits1, width1, name2, bits2, width2)   \
            TARG_INF(BUILD_FORMAT_STRING2(width1, width2),              \
                     name1, bits1, name2, bits2)                        \

#define CONSOLE_TARGET_INFO(name1, bits1, width1, name2, bits2, width2) \
            CONSOLE::displayf(CONSOLE::DEFAULT, "TARG",                 \
                              BUILD_FORMAT_STRING2(width1, width2),     \
                              name1, bits1, name2, bits2)               \

//******************************************************************************
// Utility functions
//******************************************************************************
namespace TARGETING
{
    namespace UTIL
    {
        /**
         *  @brief Returns the top level physical target
         *
         *  Returns the top level (usually system) target. If there is no top
         *  level target, an assertion failure is triggered. Caller does not
         *  need to check for a nullptr top level target
         *
         *  @returns  The top level target, never nullptr.
         */
        Target* assertGetToplevelTarget()
        {
            Target* toplevelTarget(nullptr);
            targetService().getTopLevelTarget(toplevelTarget);
            TARG_ASSERT(toplevelTarget, "Toplevel target is nullptr!");
            return toplevelTarget;
        };

        /**
         *  @brief Returns the max number of targets of TYPE i_targType that could be found
         *         under a proc on the current system configuration
         *
         *  @param[in] i_targetType, the target TYPE to get the count of
         *
         *  @returns count of possible TYPE i_targetType targets under a proc
         *  @note    returns 0 for TYPEs that are not a CHILD of TYPE_PROC;
         *           ie TYPE_SYS, TYPE_NODE, TYPE_PROC
         */
        size_t maxNumTargetsPerProc(const TYPE i_targType)
        {
            if (i_targType == TYPE_SYS  ||
                i_targType == TYPE_NODE ||
                i_targType == TYPE_PROC )
            {
                return 0;
            }
            return (targetService().getMaxNumTargets(i_targType)/targetService().getMaxNumTargets(TYPE_PROC));
        }

        /**
         *  @brief Displays the bit string of the targets under each Proc that match
         *         the given i_pPredicate
         *
         *  @param[in] i_pPredicate, predicate used to determine if a bit should be
         *                           set for a target in the bit string.
         */
        void displayProcChildrenBitmasks(const PredicateBase* const i_pPredicate)
        {
            /* Example Output:
             *
             * |TARG|PROCS=C0000000
             * |TARG|PROC[00]:
             * |TARG|      CORE=F0000000 DIMM=FF00000000000000
             * |TARG|     CACHE=F0000000 OCMB=FF00
             * |TARG|PROC[01]:
             * |TARG|      CORE=F0000000 DIMM=0000000000000000
             * |TARG|     CACHE=F0000000 OCMB=0000
             *      etc.
             */

            struct targetMetadata_t {
                const char * name;
                size_t bitStringSizeBits; // number of bits in bitString needed for display
                uint64_t numPerProc;
                uint64_t bitString;
            };

            typedef std::map<TARGETING::TYPE, targetMetadata_t> targetData_t;
            std::map<ATTR_FAPI_POS_type, targetData_t > l_procChildTargsMap;

            targetData_t procChildData = {
                {TYPE_DIMM,      {"DIMM",  64, maxNumTargetsPerProc(TYPE_DIMM), 0}},
                {TYPE_OCMB_CHIP, {"OCMB",  16, maxNumTargetsPerProc(TYPE_OCMB_CHIP), 0}},
                {TYPE_CORE,      {"CORE",  32, maxNumTargetsPerProc(TYPE_CORE), 0}},
                {TYPE_L3,        {"CACHE", 32, maxNumTargetsPerProc(TYPE_CORE), 0}}
                // use TYPE_L3 as a placeholder for tracking functional CORE cache
            };

            // quick check to make sure there aren't more targets then we can handle for displaying
            for (auto pair: procChildData)
            {
                TARG_ASSERT(pair.second.numPerProc <= pair.second.bitStringSizeBits,
                            "Update displayProcChildrenBitmasks() to display more than %d targets of type %s per PROC",
                            pair.second.numPerProc,
                            pair.second.name);
            }

            // build the predicate to get the proc children to to display
            TargetHandleList l_proc_children;
            PredicatePostfixExpr l_procChildrenPred;
            PredicateCTM l_isDimm(CLASS_NA, TYPE_DIMM);
            PredicateCTM l_isOcmb(CLASS_NA, TYPE_OCMB_CHIP);
            PredicateCTM l_isCore(CLASS_NA, TYPE_CORE);
            l_procChildrenPred.push(&l_isDimm)
                              .push(&l_isOcmb).Or()
                              .push(&l_isCore).Or()
                              .push(i_pPredicate).And();

            TargetHandleList l_procsPres;
            getAllChips(l_procsPres,
                        TYPE_PROC,
                        false);

            for (auto l_currentProc : l_procsPres)
            {
                targetData_t l_targetData = procChildData;

                targetService().getAssociated(l_proc_children, l_currentProc,
                                TargetService::CHILD_BY_AFFINITY, TargetService::ALL,
                                &l_procChildrenPred);

                for (auto l_procChild : l_proc_children)
                {
                    TYPE l_type = l_procChild->getAttr<ATTR_TYPE>();

                    // check if the target is an ECO small core
                    if ( (l_type == TYPE_CORE) &&
                         (l_procChild->getAttr<ATTR_ECO_MODE>() == ECO_MODE_ENABLED) )
                    {
                        l_type = TYPE_L3;
                    }

                    ATTR_FAPI_POS_type l_pos = 0;
                    if( l_procChild->tryGetAttr<ATTR_FAPI_POS>(l_pos) )
                    {
                        // get position relative to proc
                        l_pos = l_pos % l_targetData[l_type].bitStringSizeBits;

                        // shift the bits marked into the lower end of bitString (if applicable)
                        // to reduce the amount of trailing 0's in the number displayed later
                        l_targetData[l_type].bitString |= (0x8000000000000000 >> (l_pos + (64 - (l_targetData[l_type].bitStringSizeBits))));
                    }
                }

                // update the the cache list for l_targetData to
                // include the cache from non-ECO cores as well
                l_targetData[TYPE_L3].bitString |= l_targetData[TYPE_CORE].bitString;

                l_procChildTargsMap[l_currentProc->getAttr<ATTR_FAPI_POS>()] = l_targetData;
            }

            // display proc bit string
            TARG_INF("PROCS=%08X", targetListToBitString<ATTR_POSITION>(l_procsPres, i_pPredicate));

        #if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
            CONSOLE::displayf(CONSOLE::DEFAULT, "TARG", "PROCS=%08X",
                              targetListToBitString<ATTR_POSITION>(l_procsPres, i_pPredicate));
        #endif

            // display the info for each proc
            for( auto l_procData : l_procChildTargsMap)
            {
                // proc num
                ATTR_FAPI_POS_type l_procNum = l_procData.first;
                TARG_INF("PROC[%02d]:", l_procNum);

                targetData_t l_childData = l_procData.second;
                // display the child info
                TRACE_TARGET_INFO(l_childData[TYPE_CORE].name,      l_childData[TYPE_CORE].bitString, FORMAT_WIDTH_8,
                                  l_childData[TYPE_DIMM].name,      l_childData[TYPE_DIMM].bitString, FORMAT_WIDTH_16);
                TRACE_TARGET_INFO(l_childData[TYPE_L3].name,        l_childData[TYPE_L3].bitString, FORMAT_WIDTH_8,
                                  l_childData[TYPE_OCMB_CHIP].name, l_childData[TYPE_OCMB_CHIP].bitString, FORMAT_WIDTH_4);


            #if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
                // proc num
                CONSOLE::displayf(CONSOLE::DEFAULT, "TARG", "PROC[%02d]:", l_procNum);

                // display the child info
                CONSOLE_TARGET_INFO(l_childData[TYPE_CORE].name,      l_childData[TYPE_CORE].bitString, FORMAT_WIDTH_8,
                                    l_childData[TYPE_DIMM].name,      l_childData[TYPE_DIMM].bitString, FORMAT_WIDTH_16);
                CONSOLE_TARGET_INFO(l_childData[TYPE_L3].name,        l_childData[TYPE_L3].bitString, FORMAT_WIDTH_8,
                                    l_childData[TYPE_OCMB_CHIP].name, l_childData[TYPE_OCMB_CHIP].bitString, FORMAT_WIDTH_4);
            #endif
            }

        }

    }; // namespace Util
};

//******************************************************************************
// targetService
//******************************************************************************

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"

#define TARG_CLASS "targetService"

// It is defined here to limit the scope
#define MAX_NODE_ID  iv_nodeData.size()

#define MAX_ENABLED_NODE_ID iv_nodeData.size()

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
    iv_initialized(false),
    iv_pSys(NULL),
    iv_processorModel(MODEL_NA)
{
    #define TARG_FN "TargetService()"

    // Target class in targeting/common/target.H has an array of pointers to
    // target handles.  Currently there is one pointer for each supported
    // association type.  The currently supported association types are PARENT,
    // CHILD. PARENT_BY_AFFINITY, and CHILD_BY_AFFINTY.  The number of pointers
    // should exactly equal value of TargetService::MAX_ASSOCIATION_TYPES
    // defined in targeting/common/targetservice.H.  Due to the huge code
    // changes necessary to directly use that enum value, this compile time
    // assert enforces that restriction.
    CPPASSERT(
     (   (  sizeof( reinterpret_cast<Target*>(0)->iv_ppAssociations)
          / sizeof( reinterpret_cast<Target*>(0)->iv_ppAssociations[0]) )
      == (TargetService::MAX_ASSOCIATION_TYPES) ));

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

        for(uint8_t l_nodeCnt=0; l_nodeCnt<i_maxNodes; l_nodeCnt++)
        {
            NodeSpecificInfo l_nodeData;
            l_nodeData.nodeId = static_cast<NODE_ID>(l_nodeCnt);

            // Cache location of RO section containing all the attribute
            // metadata
            TargetingHeader* l_pHdr = reinterpret_cast<TargetingHeader*>(
                    TARG_GET_SINGLETON(TARGETING::theAttrRP).getBaseAddress(
                            static_cast<NODE_ID>(l_nodeCnt)));

            if(NULL == l_pHdr)
            {
                TARG_INF("Targeting header is NULL for Node Id [%d].. skipping",
                    l_nodeCnt);
                  continue;
            }
            else
            {
                TARG_ASSERT((l_pHdr->eyeCatcher == PNOR_TARG_EYE_CATCHER),
                     TARG_ERR_LOC "FATAL: Targeting eyecatcher not found; "
                     "expected 0x%08X but got 0x%08X",
                      PNOR_TARG_EYE_CATCHER,l_pHdr->eyeCatcher);

                l_nodeData.pPnor = reinterpret_cast<uint32_t*>(
                        (reinterpret_cast<char*>(l_pHdr) + l_pHdr->headerSize));

                (void)_configureTargetPool(l_nodeData);

                l_nodeData.initialized = true;
            }

            Target* l_pFirstTarget = &(*(l_nodeData.targets))[0];
            TARG_INF("TargetService::init: Pushing info for node %d with first "
                     "target huid 0x%.8x and %d total targets",
                      l_nodeData.nodeId,
                      get_huid(l_pFirstTarget),
                      l_nodeData.maxTargets);
            iv_nodeData.push_back(l_nodeData);
        }

        bool masterNodeCapable = false;
        (void)UTIL::subsystemIsMasterNodeCapable(masterNodeCapable);
        if(masterNodeCapable)
        {
            (void)initDefaultMasterNode();
        }

        iv_initialized = true;

        // call to set the top TYPE_SYS target
        _setTopLevelTarget();

        // Lookup the master processor's ATTR_MODEL attribute and set
        // the instance variable on the targetService object for quick
        // future reference
        _setProcessorModel();
    }

#if defined(__HOSTBOOT_MODULE) && !defined( __HOSTBOOT_RUNTIME)
    errlHndl_t l_errl = TARGETING::AttrRP::mergeAttributes();
    if(l_errl)
    {
        TARG_ERR("TargetService::init: could not merge attributes");
        l_errl->collectTrace(TARG_COMP_NAME);
        errlCommit(l_errl, TARG_COMP_ID);
    }
#endif

    TARG_EXIT();

    #undef TARG_FN
}

//******************************************************************************
// TargetService:: _setProcessorModel
//******************************************************************************
void TargetService::_setProcessorModel(void)
{
    #define TARG_FN "setProcessorModel()"
    TARG_ENTER();

    TargetHandle_t masterProc = NULL;
    masterProcChipTargetHandle( masterProc );

    TARG_ASSERT(masterProc, "Failed to find master processor, SW error, check MRW / XML " );

    iv_processorModel = masterProc->getAttr<ATTR_MODEL>();

    TARG_EXIT();
    #undef TARG_FN
    return;
}

//******************************************************************************
// TargetService:: getProcessorModel
//******************************************************************************
ATTR_MODEL_type TargetService::getProcessorModel(void)
{
    return iv_processorModel;
}

//******************************************************************************
// TargetService:: _setTopLevelTarget
//******************************************************************************

void TargetService::_setTopLevelTarget()
{
    #define TARG_FN "_setTopLevelTarget()"
    TARG_ENTER();

    // compute TopLevelTarget
    EntityPath l_topLevelPhysicalPath(EntityPath::PATH_PHYSICAL);
    l_topLevelPhysicalPath.addLast(TYPE_SYS, 0);
    iv_pSys = toTarget(l_topLevelPhysicalPath);

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
        if((iv_nodeData[l_nodeCnt].initialized == true) &&
            (iv_nodeData[l_nodeCnt].maxTargets > 0))
        {
            /* Assumption -
             * Here we are assuming that the first target of any binary is not
             * the system target, to make sure this ithe binary compiler needs
             * to compile the binary in this specific order.
             */
            o_firstTargetPtr = &(*(iv_nodeData[l_nodeCnt].targets))[0];

            TARG_ASSERT(o_firstTargetPtr != NULL, TARG_ERR_LOC
                   "FATAL: Could not find any targets");
            break;
        }
    }
    #undef TARG_FN
}

#if defined (__HOSTBOOT_MODULE) && !defined (__HOSTBOOT_RUNTIME)
void TargetService::_getMasterProcChipTargetHandle(
                                Target*& o_masterProcChipTargetHandle,
                                bool i_onlyFunctional) const
{
    #define TARG_FN "_getMasterProcChipTargetHandle()"
    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    task_affinity_pin();
    task_affinity_migrate_to_master();
    uint64_t cpuid = task_getcpuid();
    task_affinity_unpin();

    uint64_t l_masterTopologyID = PIR_t::topologyIdFromPir(cpuid);

    // Get all Proc targets
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC, i_onlyFunctional);

    // Find the master chip pointer
    TARGETING::Target* l_masterChip = nullptr;
    for (auto & l_chip: l_procTargetList)
    {
        TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID_type l_topologyId =
            (l_chip)->getAttr<TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>();

        if (l_topologyId == l_masterTopologyID)
        {
            l_masterChip = (l_chip);
            break;
        }
    }

    o_masterProcChipTargetHandle = l_masterChip;
    #undef TARG_FN
}
#endif

#ifdef __HOSTBOOT_RUNTIME
//******************************************************************************
// TargetService:: _getFirstTargetForIterators
//******************************************************************************

void TargetService::_getFirstTargetForIterators(Target*& o_firstTargetPtr,
                                                NODE_ID i_nodeId) const
{
    #define TARG_FN "_getFirstTargetForIterators()"
    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    /* This will come inside for initialized node only.. Just for safety we
     * are checking for maxTargets & whether it is initialized or not */
    if( (i_nodeId < MAX_NODE_ID) &&
        (iv_nodeData[i_nodeId].initialized == true) &&
        (iv_nodeData[i_nodeId].maxTargets > 0))
    {
        /* Assumption -
         * Here we are assuming that the first target of any binary is not
         * the system target, to make sure this ithe binary compiler needs
         * to compile the binary in this specific order.
         */
        o_firstTargetPtr = &(*(iv_nodeData[i_nodeId].targets))[0];

        TARG_ASSERT(o_firstTargetPtr != NULL, TARG_ERR_LOC
               "FATAL: Could not find any targets");
    }
    else
    {
        o_firstTargetPtr = nullptr;
    }

    #undef TARG_FN
}
#endif

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

#ifdef __HOSTBOOT_RUNTIME
//******************************************************************************
// TargetService::begin (non-const version)
//******************************************************************************

TargetService::iterator TargetService::begin(NODE_ID i_nodeId)
{
    #define TARG_FN "begin()"
    Target* l_pFirstTarget = nullptr;

    TARG_ASSERT(iv_initialized, TARG_ERR_LOC
               "USAGE: TargetService not initialized");

    _getFirstTargetForIterators(l_pFirstTarget, i_nodeId);
    return iterator(l_pFirstTarget);

    #undef TARG_FN
}
#endif

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
            if((iv_nodeData[l_nodeCnt].initialized) &&
                    (iv_nodeData[l_nodeCnt].maxTargets > 0))
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
        for(uint8_t l_node=0; l_node<MAX_NODE_ID; ++l_node)
        {
            // Node data is not initialized or has 0 targets
            if( !(iv_nodeData[l_node].initialized) ||
                (iv_nodeData[l_node].maxTargets == 0))
            {
                TARG_ERR("getNextTarget: For node %d, initialized %d, "
                         "maximum targets %d",
                         l_node,
                         iv_nodeData[l_node].initialized,
                         iv_nodeData[l_node].maxTargets);
            }
            // Starting target is last target on its node
            else if( l_pTarget == &(*(iv_nodeData[l_node].targets))[iv_nodeData[
                            l_node].maxTargets - 1] )
            {
                // Go for next node
                uint8_t l_nextNode = getNextInitializedNode(
                                        static_cast<NODE_ID>(l_node));
                if(l_nextNode < MAX_NODE_ID)
                {
                    TARG_DBG("getNextTarget: Switched to node %d", l_nextNode);
                    l_pTarget = &(*(iv_nodeData[l_nextNode].targets))[0];
                    l_targetFound = true;
                    break;
                }
                else
                {
                    l_targetFound = false;
                    break;
                }
            }
            // Starting target is in range for its node, but not last target
            else if((l_pTarget >= &(*(iv_nodeData[l_node].targets))[0]) &&
                    (l_pTarget < &(*(iv_nodeData[l_node].targets))[
                                iv_nodeData[l_node].maxTargets - 1]))
            {
                ++l_pTarget;
                l_targetFound = true;
                break;
            }
        }
    }
    if(l_targetFound == false)
    {
        TARG_DBG("getNextTarget: Target not found");
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

    o_targetHandle = iv_pSys;

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
// TargetService::_toTarget
//******************************************************************************

Target* TargetService::_toTarget(
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
// TargetService::_memoizeTarget
//******************************************************************************
int TargetService::_memoizeTarget(
          EntityPath i_entityPath,
          TARGETING::Target*& o_target)
{
    o_target = TARGETING::targetService()._toTarget(i_entityPath);
    return 0;
}

//******************************************************************************
// TargetService::toTarget
//******************************************************************************
Target* TargetService::toTarget(
    const EntityPath& i_entityPath) const
{
    Target* o_target = nullptr;
#ifdef __HOSTBOOT_MODULE
    Util::Memoize::memoize<int>(TargetService::_memoizeTarget, i_entityPath, o_target);
#else
    // Use of the memoizer inhibited on FSP compiles because the memoizer has no
    // hooks into the primary node election algorithm.  If a new primary node
    // were to be elected, the memoizer would potentially return a stale system
    // target pointer.
    TargetService::_memoizeTarget(i_entityPath, o_target);
#endif
    return o_target;
}

//******************************************************************************
// TargetService::_memoizeTargetCount
//******************************************************************************
int TargetService::_memoizeTargetCount( const TYPE i_targetType, size_t & o_count)
{
    TargetHandleList l_allTargetsByType;
    PredicateCTM l_isTargetType(CLASS_NA, i_targetType);

    targetService().getAssociated(l_allTargetsByType, UTIL::assertGetToplevelTarget(),
                    TargetService::CHILD_BY_AFFINITY, TargetService::ALL,
                    &l_isTargetType);

    o_count = l_allTargetsByType.size();
    return 0;
}

//******************************************************************************
// TargetService::getMaxNumTargets
//******************************************************************************
size_t TargetService::getMaxNumTargets(const TYPE i_targetType)
{
    size_t o_count = 0;
    Util::Memoize::memoize<int>(TargetService::_memoizeTargetCount, i_targetType, o_count);

    return o_count;
}

//******************************************************************************
// TargetService::masterProcChipTargetHandle
//******************************************************************************

void TargetService::masterProcChipTargetHandle(
          Target*& o_masterProcChipTargetHandle,
    const Target*  i_pNodeTarget,
    const bool     i_onlyFunctional) const
{
    #define TARG_FN "masterProcChipTargetHandle(...)"
    errlHndl_t pError = NULL;

    pError = queryMasterProcChipTargetHandle(
        o_masterProcChipTargetHandle,
        i_pNodeTarget,
        i_onlyFunctional);
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
    const Target* const i_pNodeTarget,
    const bool          i_onlyFunctional) const
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

        if(!pActingMasterTarget
           || PLAT::PROPERTIES::MULTINODE_AWARE
           || i_onlyFunctional )
        {

#if defined (__HOSTBOOT_MODULE) && !defined (__HOSTBOOT_RUNTIME)
            _getMasterProcChipTargetHandle(pMasterProc, i_onlyFunctional);
            pActingMasterTarget = pMasterProc;
#else

            // Create filter that finds acting master processors
            PredicateCTM procFilter(CLASS_CHIP, TYPE_PROC);
            PredicateAttrVal<ATTR_PROC_MASTER_TYPE> actingMasterFilter(
                PROC_MASTER_TYPE_ACTING_MASTER);
            PredicateHwas functionalFilter;
            functionalFilter.functional(true);
            PredicatePostfixExpr actingMasterProcFilter;
            actingMasterProcFilter.push(&procFilter).push(
                        &actingMasterFilter).And();

            // Limit to only functional procs if requested
            if (i_onlyFunctional)
            {
                actingMasterProcFilter.push(&functionalFilter).And();
            }

            // Find all the acting master processors (max one per physical
            // node), sorted by fabric node ID, and return the one with the
            // lowest fabric node ID
            TargetRangeFilter blueprintProcs(
                targetService().begin(),
                targetService().end(),
                &actingMasterProcFilter);

            uint8_t minFabricTopologyId = INVALID_NODE;
            for(; blueprintProcs; ++blueprintProcs)
            {
                uint8_t fabricTopologyId =
                    blueprintProcs->getAttr<
                        TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>();
                if(fabricTopologyId < minFabricTopologyId)
                {
                    minFabricTopologyId = fabricTopologyId;
                    pMasterProc = *blueprintProcs;
                }
            }

            if(   (pMasterProc)
               && (!PLAT::PROPERTIES::MULTINODE_AWARE)
               && (!i_onlyFunctional))
            {
                pActingMasterTarget = pMasterProc;
            }
#endif
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
#if defined (__HOSTBOOT_MODULE) && !defined (__HOSTBOOT_RUNTIME)
        TARGETING::Target* l_masterChip = NULL;
        _getMasterProcChipTargetHandle(l_masterChip, i_onlyFunctional);

        //To hook back in with the implementation below for commonality --
        // either return an empty list (error) or push the master proc as
        // the one and only element to the list
        TARGETING::TargetHandleList l_masterProclist;
        if (l_masterChip)
        {
            l_masterProclist.push_back(l_masterChip);
        }

        TRACFCOMP( g_trac_targeting, "Found Master chip with HUID: %08x", l_masterChip->getAttr<ATTR_HUID>());

#else
        // Create predicate which looks for an acting master processor chip
        PredicateAttrVal<ATTR_PROC_MASTER_TYPE> l_procMasterMatches(
            PROC_MASTER_TYPE_ACTING_MASTER);
        PredicateCTM
              l_procPredicate(TARGETING::CLASS_CHIP,TARGETING::TYPE_PROC);
        PredicateHwas functionalFilter;
        functionalFilter.functional(true);
        PredicatePostfixExpr  l_masterProcFilter;
        l_masterProcFilter.push(&l_procPredicate).push(
            &l_procMasterMatches).And();

        // Limit to only functional procs if requested
        if (i_onlyFunctional)
        {
            l_masterProcFilter.push(&functionalFilter).And();
        }

        // Find the acting master within the node
        TARGETING::TargetHandleList l_masterProclist;
        getAssociated(l_masterProclist,
            const_cast<const Target*>(i_pNodeTarget), CHILD, ALL,
                    &l_masterProcFilter);

#endif
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
         * @devdesc    The caller passed an invalid node target to find the
         *             master proc handle.
         * @custdesc   Error occurred during system boot
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
         * @devdesc    The caller passed an invalid node target to find the
         *             master proc handle
         * @custdesc   Error occurred during system boot
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
// TargetService::_getAssociationsViaDfs
//******************************************************************************

void TargetService::_getAssociationsViaDfs(
          TargetHandleList&    o_list,
    const Target* const        i_pSourceTarget,
    const ASSOCIATION_TYPE     i_type,
    const RECURSION_LEVEL      i_recursionLevel,
    const PredicateBase* const i_pPredicate) const
{
    AbstractPointer<Target>* pDestinationTargetItr =
        TARG_TO_PLAT_PTR(i_pSourceTarget->iv_ppAssociations[i_type]);

    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        pDestinationTargetItr = static_cast< AbstractPointer<Target>* >(
            TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(
                pDestinationTargetItr, i_pSourceTarget));
    }

    while( static_cast<uint64_t>(*pDestinationTargetItr) )
    {
        Target* pDestinationTarget = TARG_TO_PLAT_PTR(
            *pDestinationTargetItr);

        if(TARG_ADDR_TRANSLATION_REQUIRED)
        {
            NODE_ID node = (*pDestinationTargetItr).TranslationEncoded.nodeId;
            if(!node)
            {
                pDestinationTarget = static_cast<Target*>(
                    TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(
                        pDestinationTarget, i_pSourceTarget));
            }
            else
            {
                // Node IDs indexed from 1, so decrement to compensate
                pDestinationTarget = static_cast<Target*>(
                    TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(
                        pDestinationTarget, --node));
            }
        }

        if(   (!i_pPredicate)
           || ((*i_pPredicate)(pDestinationTarget)))
        {
            o_list.push_back(pDestinationTarget);
        }

        if(i_recursionLevel == ALL)
        {
            (void)_getAssociationsViaDfs(
                o_list,
                pDestinationTarget,
                i_type,
                i_recursionLevel,
                i_pPredicate);
        }

        ++pDestinationTargetItr;
    }
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

    (void)_getAssociationsViaDfs(
        o_list,i_pTarget,i_type,i_recursionLevel,i_pPredicate);
    } while (0);

    // If target vector contains more than one element, sorty by HUID
    if (o_list.size() > 1)
    {
        std::sort(o_list.begin(),o_list.end(),compareTargetHuid);
    }

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
            TARG_INF("Use SBE SCOM = %d",l_switches.useSbeScom);
        }

        uint64_t l_xscomBaseAddr = 0;
        if ( l_allTargets->tryGetAttr<
                ATTR_XSCOM_BASE_ADDRESS>(l_xscomBaseAddr) )
        {
            TARG_INF("XSCOM Base Address = 0x%016llX",l_xscomBaseAddr);
        }

        TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID_type topoId = 0;
        if(l_allTargets->tryGetAttr<TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>(topoId))
        {
            TARGETING::groupId_t groupId = 0;
            TARGETING::chipId_t chipId = 0;
            TARGETING::extractGroupAndChip(topoId, groupId, chipId);
            TARG_INF("XSCOM topology ID = 0x%02X",topoId);
            TARG_INF("XSCOM node ID = 0x%02X",groupId);
            TARG_INF("XSCOM chip ID = 0x%02X",chipId);
        }
    }

    return;

    #undef TARG_FN
}

#ifndef __HOSTBOOT_RUNTIME
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
#endif

//******************************************************************************
// TargetService::_configureTargetPool
//******************************************************************************

void TargetService::_configureTargetPool(
    NodeSpecificInfo& i_nodeContainer,
    AttrRP *i_attrRP)
{
#define TARG_FN "_configureTargetPool(...)"

    TARG_ENTER();

    AttrRP *l_attrRP = (i_attrRP == NULL)
                     ? &TARG_GET_SINGLETON(TARGETING::theAttrRP) : i_attrRP;

    _maxTargets(i_nodeContainer);

    // iv_pPnor--> points to uint32_t* --> points to --> uint32_t, targets[]
    //                   (uint32_t*)+1 --> points to ------------> targets[]
    const AbstractPointer<uint32_t>* ppNumTargets
        = static_cast<const AbstractPointer<uint32_t>*>(
              i_nodeContainer.pPnor);

    i_nodeContainer.targets =
           reinterpret_cast< Target(*)[] > (
               (TARG_TO_PLAT_PTR_AND_INC(*ppNumTargets,1)));

    TARG_ASSERT(i_nodeContainer.targets, TARG_ERR_LOC
                "FATAL: Could not determine location of targets");
    TARG_INF("i_nodeContainer.targets = %p", i_nodeContainer.targets);

    // Only translate addresses on platforms where addresses are 4 bytes wide
    // (FSP). The compiler should perform dead code elimination of this path on
    // platforms with 8 byte wide addresses (Hostboot), since the "if" check
    // can be statically computed at compile time.
    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        i_nodeContainer.targets = static_cast<Target(*)[]>(
             l_attrRP->translateAddr(
                    i_nodeContainer.targets, i_nodeContainer.nodeId));
        TARG_ASSERT(i_nodeContainer.targets, TARG_ERR_LOC
                    "FATAL: Could not determine location of targets after "
                    "address translation");
        TARG_INF("i_nodeContainer.targets after translation = %p",
                 i_nodeContainer.targets);
    }

    TARG_EXIT();

    #undef TARG_FN
}

//******************************************************************************
// TargetService::_maxTargets
//******************************************************************************

void TargetService::_maxTargets(NodeSpecificInfo& io_nodeContainer,
                                AttrRP *i_attrRP)
{
    #define TARG_FN "_maxTargets(...)"

    AttrRP *l_attrRP = (i_attrRP == NULL)
                     ? &TARG_GET_SINGLETON(TARGETING::theAttrRP) : i_attrRP;

    // Target count found by following the pointer pointed to by the iv_pPnor
    // pointer.
    const AbstractPointer<uint32_t>* pNumTargetsPtr
        = static_cast<const AbstractPointer<uint32_t>*>(
                io_nodeContainer.pPnor);
    uint32_t* pNumTargets = TARG_TO_PLAT_PTR(*pNumTargetsPtr);

    // Only translate addresses on platforms where addresses are 4 bytes wide
    // (FSP). The compiler should perform dead code elimination of this path on
    // platforms with 8 byte wide addresses (Hostboot), since the "if" check
    // can be statically computed at compile time.
    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        pNumTargets =
            static_cast<uint32_t*>(l_attrRP->translateAddr(
                        pNumTargets, io_nodeContainer.nodeId));
    }

    TARG_ASSERT(pNumTargets, TARG_ERR_LOC
                "FATAL: Could not determine location of targets after "
                "address translation");

    io_nodeContainer.maxTargets = *pNumTargets;

    TARG_INF("Max targets = %d", io_nodeContainer.maxTargets);

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
        else
        {
            // call to set the top TYPE_SYS target
            _setTopLevelTarget();
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
         * @devdesc    The caller passed an invalid node target.
         * @custdesc   Error occurred during system boot
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
            if((iv_nodeData[l_nodeCnt].initialized) &&
                    (iv_nodeData[l_nodeCnt].maxTargets > 0))
            {
                for(uint32_t l_targetCnt=0;
                        l_targetCnt<iv_nodeData[l_nodeCnt].maxTargets;
                        ++l_targetCnt)
                {
                    if(((*(iv_nodeData[l_nodeCnt].targets))[
                            l_targetCnt].getAttr<ATTR_CLASS>() == CLASS_ENC) &&
                            ((*(iv_nodeData[l_nodeCnt].targets))[
                             l_targetCnt].getAttr<ATTR_TYPE>() == TYPE_NODE))
                    {
                        if(UTIL::isThisMasterNodeTarget(
                           &((*(iv_nodeData[l_nodeCnt].targets))[l_targetCnt])))
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
                if((iv_nodeData[l_nodeCnt].initialized) &&
                        (iv_nodeData[l_nodeCnt].maxTargets > 0))
                {
                    // Need to go over each target to search for Node, cannot
                    // use rangefilter here since targeting is yet not
                    // initialized.
                    for(uint32_t l_targetCnt=0;
                            l_targetCnt<iv_nodeData[l_nodeCnt].maxTargets;
                            ++l_targetCnt)
                    {
                        if(((*(iv_nodeData[l_nodeCnt].targets))[
                             l_targetCnt].getAttr<ATTR_CLASS>() == CLASS_ENC) &&
                              ((*(iv_nodeData[l_nodeCnt].targets))[
                               l_targetCnt].getAttr<ATTR_TYPE>() == TYPE_NODE))
                        {
                            // Just do bare minimum stuff i.e. just set the
                            // Master Node Attribute
                            pError = UTIL::setDefaultMasterNodeWithoutSync(
                                &((*(iv_nodeData[l_nodeCnt].targets))[
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
                        _setTopLevelTarget();
                        TARG_ASSERT(iv_pSys != NULL, TARG_ERR_LOC
                            "Top Level Target cannot be NULL");
                        pError = UTIL::SyncMasterSystemTarget(iv_pSys);
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

//******************************************************************************
// TargetService::getTargetArray
//******************************************************************************

Target* TargetService::getTargetArray(void *i_attrData,
                                      NODE_ID i_nodeId,
                                      AttrRP *i_attrRP,
                                      uint32_t &o_maxTargets)
{
    #define TARG_FN "getTargetArray(...)"
    TARG_ENTER();

    // Get pointer to TargetingHeader for attribute data
    TargetingHeader* l_header =
        reinterpret_cast<TargetingHeader*>(i_attrData);

    // Verify TargetingHeader
    TARG_ASSERT(l_header != NULL, TARG_ERR_LOC
                "TargetingHeader for attribute data is NULL");
    TARG_ASSERT(l_header->eyeCatcher == PNOR_TARG_EYE_CATCHER, TARG_ERR_LOC
                "TargetingHeader eyecatcher 0x%16llX is incorrect",
                l_header->eyeCatcher)

    // Save away the address of the targeting data in l_pPnor variable
    // l_pPnor--> points to uint32_t* --> points to --> uint32_t, targets[]
    //                  (uint32_t*)+1 --> points to ------------> targets[]
    const void *l_pPnor =
        reinterpret_cast<const void*>(reinterpret_cast<char*>(l_header) +
                                      l_header->headerSize);

    // Target count found by following the l_pPnor pointer
    const AbstractPointer<uint32_t>* pNumTargetsPtr =
        static_cast<const AbstractPointer<uint32_t>*>(l_pPnor);
    uint32_t* pNumTargets = TARG_TO_PLAT_PTR(*pNumTargetsPtr);

    // Only translate addresses on platforms where addresses are 4 bytes wide
    // (FSP). The compiler should perform dead code elimination of this path on
    // platforms with 8 byte wide addresses (Hostboot), since the "if" check
    // can be statically computed at compile time.
    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        pNumTargets =
            static_cast<uint32_t*>(i_attrRP->translateAddr(pNumTargets,
                                                           i_nodeId));
    }

    TARG_ASSERT(pNumTargets, TARG_ERR_LOC
                "FATAL: Could not determine location of targets after "
                "address translation");

    // Set maximum number of targets output
    o_maxTargets = *pNumTargets;

    TARG_INF("Max targets = %d", o_maxTargets);

    // Targets array found by following the l_pPnor pointer
    Target (*l_targets)[] = reinterpret_cast< Target(*)[] > (
               (TARG_TO_PLAT_PTR_AND_INC(*pNumTargetsPtr,1)));

    TARG_ASSERT(l_targets, TARG_ERR_LOC
                "FATAL: Could not determine location of targets");
    TARG_INF("l_targets = %p", l_targets);

    // Only translate addresses on platforms where addresses are 4 bytes wide
    // (FSP). The compiler should perform dead code elimination of this path on
    // platforms with 8 byte wide addresses (Hostboot), since the "if" check
    // can be statically computed at compile time.
    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        l_targets =
            static_cast<Target(*)[]>(i_attrRP->translateAddr(l_targets,
                                                             i_nodeId));
        TARG_ASSERT(l_targets, TARG_ERR_LOC
                    "FATAL: Could not determine location of targets after "
                    "address translation");
        TARG_INF("l_targets after translation = %p",
                 l_targets);
    }

    TARG_EXIT();
    #undef TARG_FN

    // Return pointer to first target in array
    return &(*(l_targets))[0];
}

//******************************************************************************
// TargetService::getTargetAttributes
//******************************************************************************

uint32_t TargetService::getTargetAttributes(Target*i_target,
                                            AttrRP *i_attrRP,
                                            ATTRIBUTE_ID* &o_pAttrId,
                                            AbstractPointer<void>*
                                                &o_ppAttrAddr)
{
    #define TARG_FN "getTargetAttributes(...)"
    // TARG_ENTER();

    // Transform platform neutral pointers into platform specific pointers, and
    // optimize processing by not having to do the conversion in the loop below
    // (it's guaranteed that attribute metadata will be in the same contiguous
    // VMM region)
    o_pAttrId = TARG_TO_PLAT_PTR(i_target->iv_pAttrNames);
    o_ppAttrAddr = TARG_TO_PLAT_PTR(i_target->iv_pAttrValues);
    TARG_DBG("o_pAttrId before translation = %p, "
             "o_ppAttrAddr before translation = %p",
             o_pAttrId,
             o_ppAttrAddr);

    // Only translate addresses on platforms where addresses are 4 bytes wide
    // (FSP). The compiler should perform dead code elimination of this path on
    // platforms with 8 byte wide addresses (Hostboot), since the "if" check can
    // be statically computed at compile time.
    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        o_pAttrId = static_cast<ATTRIBUTE_ID*>(
            i_attrRP->translateAddr(o_pAttrId, i_target));
        o_ppAttrAddr = static_cast<AbstractPointer<void>*>(
            i_attrRP->translateAddr(o_ppAttrAddr, i_target));
        TARG_DBG("o_pAttrId after translation = %p, "
                 "o_ppAttrAddr after translation = %p",
                 o_pAttrId,
                 o_ppAttrAddr);
    }

    // TARG_EXIT();
    #undef TARG_FN

    // Return the number of attributes for this target
    return i_target->iv_attrs;
}

#ifdef __HOSTBOOT_MODULE

#ifndef __HOSTBOOT_RUNTIME
errlHndl_t TargetService::modifyReadOnlyPagePermissions(bool i_allowWrites)
{
    #define TARG_FN "modifyReadOnlyPagePermissions(...)"
    TARG_ENTER();
    errlHndl_t l_errl = NULL;
    TARGETING::AttrRP *l_pAttrRP = &TARG_GET_SINGLETON(TARGETING::theAttrRP);
    if(i_allowWrites)
    {
        l_errl = l_pAttrRP->editPagePermissions(SECTION_TYPE_PNOR_RO, WRITABLE);
    }
    else
    {
        l_errl = l_pAttrRP->editPagePermissions(SECTION_TYPE_PNOR_RO, READ_ONLY);
    }
    TARG_EXIT();
    #undef TARG_FN
    return l_errl;
}
#endif

bool TargetService::updatePeerTarget(const Target* i_pTarget)
{
    #define TARG_FN "updatePeerTarget(...)"
    // Variable which holds return value
    bool l_peerTargetUpdated = false;
    do
    {
        TARGETING::Target * l_peer =  static_cast<Target*>(NULL);
        if(! i_pTarget->tryGetAttr<ATTR_PEER_TARGET>(l_peer))
        {
            // This is a normal path, many targets do not have PEERS
            TRACDCOMP(g_trac_targeting, "No PEER_TARGET found for target 0x%x",
                      get_huid(i_pTarget));
            // Skip the rest of the function in this case
            break;
        }
        else
        {
            TRACFCOMP(g_trac_targeting, "Initial PEER_TARGET address for HUID 0x%x found to be %p",
                      get_huid(i_pTarget), l_peer);
        }

        TARGETING::ATTR_PEER_PATH_type l_peerPath;
        if(i_pTarget->tryGetAttr<ATTR_PEER_PATH>(l_peerPath))
        {
            // If we find a PEER_PATH we need to next look up the PEER_TARGET with toTarget
            l_peer = targetService().toTarget(l_peerPath);

            TRACFCOMP(g_trac_targeting, "Updated PEER_TARGET address for HUID 0x%x found to be %p",
                      get_huid(i_pTarget), l_peer);
            // Set the address even if it is NULL for if it is NULL
            // PRD will not attempt to use it during data collection
            l_peerTargetUpdated = i_pTarget->_trySetAttr(ATTR_PEER_TARGET,
                                                         sizeof(l_peer),
                                                         &l_peer);
        }
        else
        {
            // This is unexpected so make the trace visible, but no need to assert
            TRACFCOMP(g_trac_targeting,
                      "No PEER_PATH found for target 0x%x which does have a PEER_TARGET attribute",
                      get_huid(i_pTarget));
        }
    } while(0);

    return l_peerTargetUpdated;
    #undef TARG_FN
}

uint32_t TargetService::resetMutexAttributes(const Target* i_pTarget)
{
    #define TARG_FN "resetMutexAttributes(...)"
    TARGETING::AttrRP *l_pAttrRP = &TARG_GET_SINGLETON(TARGETING::theAttrRP);
    ATTRIBUTE_ID* l_pAttrIds = nullptr;
    AbstractPointer<void>* l_ppAttrAddrs = nullptr;
    uint32_t l_numberMutexAttrsReset = 0;
    uint32_t l_attrCount = 0;
    l_attrCount = targetService().getTargetAttributes(const_cast<TARGETING::Target*>(i_pTarget),
                                                      l_pAttrRP,
                                                      l_pAttrIds,
                                                      l_ppAttrAddrs );

    for ( uint32_t l_attrIndex = 0; l_attrIndex < l_attrCount; l_attrIndex++)
    {
        const ATTRIBUTE_ID l_attrId = l_pAttrIds[l_attrIndex];
        for( const auto mutex : hbMutexAttrIds)
        {
            if(l_attrId == mutex.id)
            {
                mutex_t* l_mutex;
                if(i_pTarget->_tryGetHbMutexAttr(l_attrId, l_mutex))
                {
#ifdef __HOSTBOOT_MODULE
                    if (mutex.isRecursive)
                    {
                        recursive_mutex_init(l_mutex);
                    }
                    else
#endif
                    {
                        mutex_init(l_mutex);
                    }
                    l_numberMutexAttrsReset++;
                }
                else
                {
                    /*@
                    *   @errortype         ERRORLOG::ERRL_SEV_PREDICTIVE
                    *   @moduleid          TARG_SVC_RESET_MUTEX
                    *   @reasoncode        TARG_SVC_MISSING_ATTR
                    *   @userdata1         Attribute Id we attempted to read
                    *   @userdata2         Huid of target we attempted to read
                    *
                    *   @devdesc   For some reason attr IDs in hbMutexAttrIds list
                    *              are not matching the attribute IDs that target
                    *              service is seeing. This is causing incorrect matching.
                    *              Make sure mutexattribute.H in genfiles has good values
                    *
                    *   @custdesc  Attempted to conduct an invalid attribute look up.
                    */
                    errlHndl_t l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                                        TARG_SVC_RESET_MUTEX,
                                                        TARG_SVC_MISSING_ATTR,
                                                        l_attrId,
                                                        get_huid(i_pTarget),
                                                        true); // software error
                    errlCommit(l_errl, TARG_COMP_ID);
                }
            }
        }
    }
    #undef TARG_FN
    return l_numberMutexAttrsReset;
}

//******************************************************************************
// getSysToNodeAssociations
//******************************************************************************
SysToNodeContainer TargetService::getSysToNodeAssociations(
    const bool i_anyNodeType)
{
    TARGETING::TYPE nodeType = TARGETING::TYPE_NODE;
    if(i_anyNodeType)
    {
        nodeType = TARGETING::TYPE_NA;
    }

    PredicateCTM isaSystemTarget(CLASS_SYS, TYPE_SYS);
    PredicateCTM isaNodeTarget(CLASS_ENC, nodeType);
    SysToNodeContainer nodeContainer;
    SysToNodeContainer sysContainer;

    NODE_ID l_node = targetService().getNumInitializedNodes();

    TargetRawIterator pRawTarget = targetService().raw_begin();
    for(;
        pRawTarget != targetService().raw_end();
        ++pRawTarget)
    {
        if(isaSystemTarget(*pRawTarget))
        {
            // Get node ID only in non-IPL case
            #if defined(__HOSTBOOT_RUNTIME) || !defined(__HOSTBOOT_MODULE)
            TARG_GET_SINGLETON(TARGETING::theAttrRP).getNodeId(
                *pRawTarget,l_node);
            #else
            l_node = 0;
            #endif
            SysToNode sysOnly(NULL, *pRawTarget, l_node);
            sysContainer.push_back(sysOnly);
        }
        else if(isaNodeTarget(*pRawTarget))
        {
            // Get node ID only in non-IPL case
            #if defined(__HOSTBOOT_RUNTIME) || !defined(__HOSTBOOT_MODULE)
            TARG_GET_SINGLETON(TARGETING::theAttrRP).getNodeId(
                *pRawTarget,l_node);
            #else
            l_node = 0;
            #endif
            SysToNode nodeOnly(*pRawTarget, NULL, l_node);
            nodeContainer.push_back(nodeOnly);
        }
    }

    typedef SysToNodeContainerIt nodeIterator;
    typedef SysToNodeContainerIt sysIterator;

    for(nodeIterator pNodeTarget = nodeContainer.begin();
        pNodeTarget != nodeContainer.end();
        ++pNodeTarget)
    {
        for(sysIterator pSysTarget = sysContainer.begin();
            pSysTarget != sysContainer.end();
            ++pSysTarget)
        {
            if(pNodeTarget->nodeId == pSysTarget->nodeId)
            {
                pNodeTarget->pSysTarget = pSysTarget->pSysTarget;
                break;
            }
        }
    }

    return nodeContainer;
}
#endif

#ifdef __HOSTBOOT_RUNTIME
bool isThisMasterNodeTarget(const Target* const i_pTarget)
{
    bool l_masterFound = false;

    TARG_ASSERT(i_pTarget != nullptr,
        "Passed Node Target as nullptr");

    // Check if node Target
    PredicateCTM l_nodePredicate(CLASS_ENC, TYPE_NODE);
    if(l_nodePredicate(i_pTarget))
    {
        Target* l_masterNode = nullptr;
        TARGETING::UTIL::getMasterNodeTarget(l_masterNode);
        if(i_pTarget == l_masterNode)
        {
            l_masterFound = true;
        }
    }
    else
    {
        TARG_INF("Passed Target is not a Node Target, HUID [0x%08X]",
            i_pTarget->getAttr<ATTR_HUID>());
    }

    return l_masterFound;
}

#endif

#undef TARG_CLASS

#undef TARG_NAMESPACE


} // End namespace TARGETING

