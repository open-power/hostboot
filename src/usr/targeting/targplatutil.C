/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/targplatutil.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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
 *  @file targeting/targplatutil.C
 *
 *  @brief Provides implementation for general platform specific utilities
 *      to support core functions
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdlib.h>
#include <algorithm>

// TARG
#include <targeting/targplatutil.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/utilFilter.H>
#include <util/misc.H> // isTargetingLoaded

// PLDM
#include <pldm/extended/hb_pdrs.H>

// ERRL
#include <errl/errlmanager.H>

// Magic instruction
#include <arch/magic.H>

// Attribute length info
#include <mapattrmetadata.H>

// MMIO constants
#include <arch/memorymap.H>

namespace TARGETING
{

namespace UTIL
{

void dumpHBAttrs(const uint32_t i_huid)
{
    // getting top system target "SYS"
    Target* l_topSysTarget = nullptr;
    targetService().getTopLevelTarget(l_topSysTarget);
    assert(l_topSysTarget, "dumpHBAttrs: Could not get top system target");

    TargetHandleList l_targetList;

    targetService().getAssociated( l_targetList, l_topSysTarget,
                                   TargetService::CHILD, TargetService::ALL, nullptr);

    l_targetList.push_back(l_topSysTarget);

    const auto& l_attrMetaData = getMapMetadataForAllAttributes();

    // Dump every attribute of every target.
    for (const auto l_target: l_targetList)
    {
        const uint32_t l_targetHuid = get_huid(l_target);

        if (i_huid != 0 && i_huid != l_targetHuid)
        {
            continue;
        }

        // array of attr ids
        const ATTRIBUTE_ID* const l_pAttrId = TARG_TO_PLAT_PTR(l_target->iv_pAttrNames);

        const ATTRIBUTE_ID* const end = &l_pAttrId[l_target->iv_attrs];

        std::vector<uint8_t> l_attrData;

        // Iterate each attribute ID and dump it, along with its value, out to the simulator
        for (const ATTRIBUTE_ID* l_attributeId = l_pAttrId;
             l_attributeId != end;
             ++l_attributeId)
        {
            auto l_attrSizeIt = l_attrMetaData.find(*l_attributeId);

            if (l_attrSizeIt == l_attrMetaData.end())
            {
                TRACFCOMP(g_trac_targeting,
                          "dumpHBAttrs: Can't find size of attribute, ID 0x%08x", *l_attributeId);
                continue;
            }

            const uint32_t l_attrSize = l_attrSizeIt->second.size;
            l_attrData.resize(l_attrSize);

            if (!l_target->_tryGetAttrUnsafe(*l_attributeId, l_attrSize, &l_attrData[0]))
            {
                TRACFCOMP(g_trac_targeting,
                          "dumpHBAttrs: Can't get attribute ID 0x%08x (this is probably a bug)",
                          *l_attributeId);
                continue;
            }

            const uint32_t l_fixedSizes = 8;
            const uint32_t l_count = ((l_attrSize + l_fixedSizes - 1) / l_fixedSizes);

            // Iterate over 8-byte chunks of the attribute value and send them out to the simulator.
            for (uint32_t i = 0; i < l_count; ++i)
            {
                MAGIC_INST_SAVE_ATTR_VALUE(l_targetHuid,
                                           *l_attributeId,
                                           l_attrSize,
                                           i * l_fixedSizes,
                                           *(uint64_t*)(&l_attrData[i * l_fixedSizes]));
            }
        }
    }
}

#define TARG_NAMESPACE "TARGETING::UTIL"
#define TARG_CLASS ""

//******************************************************************************
// createTracingError
//******************************************************************************

void createTracingError(
    const uint8_t     i_modId,
    const uint16_t    i_reasonCode,
    const uint32_t    i_userData1,
    const uint32_t    i_userData2,
    const uint32_t    i_userData3,
    const uint32_t    i_userData4,
          errlHndl_t& io_pError)
{
    errlHndl_t pNewError = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                   i_modId,
                                   i_reasonCode,
                                   static_cast<uint64_t>(i_userData1) << 32
                                       | (i_userData2 & (0xFFFFFFFF)),
                                   static_cast<uint64_t>(i_userData3) << 32
                                       | (i_userData4 & (0xFFFFFFFF)));
    if(io_pError != NULL)
    {
        // Tie logs together; existing log primary, new log as secondary
        pNewError->plid(io_pError->plid());
        errlCommit(pNewError,TARG_COMP_ID);
    }
    else
    {
        io_pError = pNewError;
        pNewError = NULL;
    }

    return;
}

void getMasterNodeTarget(Target*& o_masterNodeTarget)
{
    Target* masterNodeTarget = NULL;
    PredicateCTM nodeFilter(CLASS_ENC, TYPE_NODE);
    TargetRangeFilter localBlueprintNodes(
                targetService().begin(),
                targetService().end(),
                &nodeFilter);
    if(localBlueprintNodes)
    {
        masterNodeTarget = *localBlueprintNodes;
    }

    o_masterNodeTarget = masterNodeTarget;
}

bool isCurrentMasterNode()
{
    // Get node target
    TARGETING::TargetHandleList l_nodelist;
    getEncResources(l_nodelist, TARGETING::TYPE_NODE,
                    TARGETING::UTIL_FILTER_FUNCTIONAL);
    assert(l_nodelist.size() == 1, "ERROR, only expect one node.");
    auto isSlave = l_nodelist[0]->getAttr<TARGETING::ATTR_IS_SLAVE_DRAWER>();

    return (isSlave == 0);
}

#ifndef __HOSTBOOT_RUNTIME
Target* getCurrentNodeTarget(void)
{
    // Get node target
    TargetHandleList l_nodelist;
    // if hostboot is active, then the node is functional
    // this will be called sometimes before nodes are marked functional
    getEncResources(l_nodelist, TARGETING::TYPE_NODE,
                    TARGETING::UTIL_FILTER_ALL);
    assert(l_nodelist.size() == 1,
           "ERROR, only expect one node, got %llu.",
           l_nodelist.size());

    Target* pTgt =  l_nodelist[0];
    assert(pTgt != nullptr, "getCurrentNodeTarget found nullptr");

    return pTgt;
}

uint8_t getCurrentNodePhysId(void)
{
    Target* pNodeTgt = getCurrentNodeTarget();
    EntityPath epath = pNodeTgt->getAttr<TARGETING::ATTR_PHYS_PATH>();
    const TARGETING::EntityPath::PathElement pe =
              epath.pathElementOfType(TARGETING::TYPE_NODE);
    return pe.instance;
}
#endif

/* @brief Structure of OCC sensor IDs.
 */
union occ_sensor_id_t
{
    uint32_t encoded = 0;
    struct
    {
        uint8_t sensor_type;
        uint8_t reserved;
        uint16_t entity_id;
    } PACKED;

    enum sensor_type_t : uint8_t
    {
        SENSOR_TYPE_CORE = 0xC0,
        SENSOR_TYPE_DIMM = 0xD0,
        SENSOR_TYPE_PROC = 0xE0,
        SENSOR_TYPE_VRM  = 0xE1,
        SENSOR_TYPE_NODE = 0xF0,
        SENSOR_TYPE_UNKNOWN = 0xFF
    };
} PACKED;

// return the sensor number from the passed in target
uint32_t getSensorNumber(const TARGETING::Target* i_pTarget,
                         TARGETING::SENSOR_NAME i_name)
{
    const uint32_t INVALID_SENSOR_NUMBER = 0xFF;

    using namespace TARGETING;

    uint32_t sensor_number = INVALID_SENSOR_NUMBER;

    do
    {

    if (!i_pTarget || !Util::isTargetingLoaded())
    {
        break;
    }

#ifdef CONFIG_PLDM
    uint8_t sensor_type = occ_sensor_id_t::SENSOR_TYPE_UNKNOWN;
    const TARGETING::TYPE target_type = i_pTarget->getAttr<ATTR_TYPE>();

    switch (target_type)
    {
    case TYPE_FC:
    case TYPE_CORE:
        sensor_type = occ_sensor_id_t::SENSOR_TYPE_CORE;
        break;
    case TYPE_OCMB_CHIP:
    case TYPE_MEM_PORT:
    {
        TargetHandleList dimm;
        getChildAffinityTargetsByState(dimm,
                                       i_pTarget,
                                       CLASS_NA,
                                       TYPE_DIMM,
                                       UTIL_FILTER_PRESENT);

        assert(dimm.size() <= 1, "Expected at most one DIMM target beneath OCMB/MEM_PORT");

        if (dimm.empty())
        {
            // Print a message and use SENSOR_TYPE_DIMM (in the TYPE_DIMM case),
            // but keep the OCMB_CHIP or MEM_PORT target in i_pTarget, which
            // will cause getEntityInstanceNumber to return "unknown."
            TRACFCOMP(g_trac_targeting,
                      "getSensorNumber(0x%08x, %d): No present DIMM children for target type %s (%d)",
                      TARGETING::get_huid(i_pTarget),
                      i_name,
                      TARGETING::attrToString<TARGETING::ATTR_TYPE>(target_type),
                      target_type);
        }
        else
        {
            i_pTarget = dimm.front();
        }
    }
    // fall through

    case TYPE_DIMM:
        sensor_type = occ_sensor_id_t::SENSOR_TYPE_DIMM;
        break;
    case TYPE_PROC:
        sensor_type = occ_sensor_id_t::SENSOR_TYPE_PROC;
        if(i_name == SENSOR_NAME_VRM_VDD_FAULT ||
           i_name == SENSOR_NAME_VRM_VDD_TEMP)
        {
            // VRM fault - the correct target is a VRM
            sensor_type = occ_sensor_id_t::SENSOR_TYPE_VRM;
        }
        break;
    case TYPE_NODE:
        if(i_name == SENSOR_NAME_BACKPLANE_FAULT ||
           i_name == SENSOR_NAME_APSS_FAULT)
        {
            // Backplane fault - the correct target is a node
            sensor_type = occ_sensor_id_t::SENSOR_TYPE_NODE;
            break;
        }
    default:
        TRACFCOMP(g_trac_targeting,
                  "getSensorNumber(0x%08x, %d): Unknown target type %s (%d)",
                  TARGETING::get_huid(i_pTarget),
                  i_name,
                  TARGETING::attrToString<TARGETING::ATTR_TYPE>(target_type),
                  target_type);
        break;
    }

    occ_sensor_id_t sensor_id { };
    sensor_id.sensor_type = sensor_type;
    sensor_id.reserved = 0;
    sensor_id.entity_id = PLDM::getEntityInstanceNumber(i_pTarget);

    sensor_number = sensor_id.encoded;
#else
    // pass back the HUID - this will be the sensor number for non-PLDM-based
    // systems
    sensor_number = get_huid( i_pTarget );
#endif

    } while (false);

    return sensor_number;
}

// convert sensor number to a target
TARGETING::Target * getSensorTarget(const uint32_t i_sensorNumber,
                                    TARGETING::Target* const i_occ)
{
    TARGETING::Target* result = nullptr;

    do
    {

    if (!i_occ || !Util::isTargetingLoaded())
    {
        break;
    }

#ifdef CONFIG_PLDM
    const occ_sensor_id_t sensor { .encoded = i_sensorNumber };
    TargetHandleList candidates;

    // If this is set to a valid targeting type, we will get the sensor target's
    // affinity parent of this type instead of the target itself.
    TARGETING::TYPE get_parent_type = TARGETING::TYPE_INVALID;

    // Figure out what targeting type the sensor is, and collect a list of
    // candidate targets based on the type
    switch (sensor.sensor_type)
    {
    case occ_sensor_id_t::SENSOR_TYPE_CORE:
    {
        const auto proc_parent = getParentChip(i_occ);
        getChildChiplets(candidates, proc_parent, TYPE_CORE, false /* don't filter non-functional */);
        TargetHandleList fcs;
        getChildChiplets(fcs, proc_parent, TYPE_FC, false /* don't filter non-functional */);
        candidates.insert(end(candidates), cbegin(fcs), cend(fcs));
        break;
    }
    case occ_sensor_id_t::SENSOR_TYPE_DIMM:
        get_parent_type = TARGETING::TYPE_OCMB_CHIP;
        getClassResources(candidates, CLASS_NA, TARGETING::TYPE_DIMM, UTIL_FILTER_PRESENT);
        break;
    case occ_sensor_id_t::SENSOR_TYPE_NODE:
        getClassResources(candidates, CLASS_NA, TARGETING::TYPE_NODE, UTIL_FILTER_PRESENT);
        break;
    case occ_sensor_id_t::SENSOR_TYPE_VRM:
        // TODO RTC: 304217
        break;
    case occ_sensor_id_t::SENSOR_TYPE_PROC:
        candidates.push_back(const_cast<Target*>(getParentChip(i_occ)));
        break;
    default:
        TRACFCOMP(g_trac_targeting,
                  "getSensorTarget(0x%08x, 0x%08x): Unknown sensor type %d",
                  i_sensorNumber, TARGETING::get_huid(i_occ), sensor.sensor_type);
        break;
    }

    // Search the target list for a target whose entity instance number matches
    // the sensor ID we were given
    for (const auto target : candidates)
    {
        if (sensor.entity_id == PLDM::getEntityInstanceNumber(target))
        {
            result = target;
            break;
        }
    }

    if (result && get_parent_type != TARGETING::TYPE_INVALID)
    {
        TargetHandleList parents;
        getParentAffinityTargets(parents, result, CLASS_NA, get_parent_type);
        assert(parents.size() == 1,
               "getSensorTarget(0x%08x, 0x%08x): Expected 0x%08x to have exactly one parent of type %d",
               i_sensorNumber, get_huid(i_occ), get_huid(result), get_parent_type);
        result = parents[0];
    }
#else
    // in non-PLDM systems the sensor number is the target's HUID
    result = Target::getTargetFromHuid( i_sensorNumber );
#endif

    } while (false);

    return result;
}

typedef struct procIds
{
    Target* proc;                                    // Proc
    ATTR_PROC_FABRIC_TOPOLOGY_ID_type topoIdDflt;    // Default Topo ID
    ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID_type topoIdEff; // Effective Topo ID
    ATTR_PROC_FABRIC_TOPOLOGY_ID_type topoId;        // Desired Topo ID
} procIds_t;

const uint8_t INVALID_PROC = 0xFF;

using namespace MEMMAP; // memorymap.H

errlHndl_t check_proc0_memory_config()
{
    errlHndl_t l_err = nullptr;

    TRACFCOMP(g_trac_targeting,
            "check_proc0_memory_config entry");

    // Get all procs
    TargetHandleList l_procsList;
    getAllChips(l_procsList, TYPE_PROC, false);

    // sort based on topology ID in order to deterministically
    // pick the processor with memory. This will also help guarantee
    // that we will attempt to use primary (or secondary) proc's memory
    // first before using another proc's memory.
    std::sort(l_procsList.begin(), l_procsList.end(),
            [] (TargetHandle_t a, TargetHandle_t b)
            {
                return a->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>() < b->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>();
            });

    // Loop through all procs getting IDs
    procIds_t l_procIds[l_procsList.size()];
    uint8_t i = 0;
    uint8_t l_proc0 = INVALID_PROC;
    uint8_t l_victim = INVALID_PROC;

    for (const auto & l_procChip : l_procsList)
    {
        l_procIds[i].proc = l_procChip;

        // Get Topology IDs
        l_procIds[i].topoIdDflt =
            l_procChip->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>();
        l_procIds[i].topoIdEff =
            l_procChip->getAttr<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>();
        l_procIds[i].topoId = l_procIds[i].topoIdDflt;

        // Check if this proc should be tracked as proc0
        if(l_proc0 == INVALID_PROC)
        {
            // No proc0, make initial assignment
            l_proc0 = i;
        }
        else if(l_procIds[i].topoId < l_procIds[l_proc0].topoId)
        {
            // Smaller topo ID, replace assignment
            l_proc0 = i;
        }

        TRACDCOMP(g_trac_targeting,
                "check_proc0_memory_config: Initial settings for "
                "Proc %.8X: topoIdDflt = %d, topoIdEff = %d, topoId = %d\n",
                get_huid(l_procIds[i].proc),
                l_procIds[i].topoIdDflt,
                l_procIds[i].topoIdEff,
                l_procIds[i].topoId);

        // Increment index
        i++;
    }

    // Get the functional DIMMs for proc0
    PredicateHwas l_functional;
    l_functional.functional(true);
    TargetHandleList l_dimms;
    PredicateCTM l_dimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
    PredicatePostfixExpr l_checkExprFunctional;
    l_checkExprFunctional.push(&l_dimm).push(&l_functional).And();
    targetService().getAssociated(l_dimms,
            l_procIds[l_proc0].proc,
            TargetService::CHILD_BY_AFFINITY,
            TargetService::ALL,
            &l_checkExprFunctional);

    TRACFCOMP(g_trac_targeting,
            "check_proc0_memory_config: %d functional dimms behind proc0 "
            "%.8X",
            l_dimms.size(), get_huid(l_procIds[l_proc0].proc) );

    if(l_dimms.empty())
    {
        TRACFCOMP(g_trac_targeting,
                "check_proc0_memory_config: proc0 %.8X has no functional "
                "dimms behind it",
                get_huid(l_procIds[l_proc0].proc) );

        // Loop through all procs to find ones for memory remap
        for (i = 0; i < l_procsList.size(); i++)
        {
            // If proc0, then continue
            if(i == l_proc0)
            {
                continue;
            }

            // Get the functional DIMMs for the proc
            targetService().getAssociated(l_dimms,
                    l_procIds[i].proc,
                    TargetService::CHILD_BY_AFFINITY,
                    TargetService::ALL,
                    &l_checkExprFunctional);

            // If proc does not have memory, then continue
            if(l_dimms.empty())
            {
                TRACFCOMP(g_trac_targeting,
                        "check_proc0_memory_config: Proc %.8X has no  "
                        "functional dimms behind it",
                        get_huid(l_procIds[i].proc) );

                continue;
            }

            // Use this proc for swapping memory with proc0
            l_victim = i;

            // Set the desired proc0 IDs from swapped proc's default IDs
            l_procIds[l_proc0].topoId = l_procIds[l_victim].topoIdDflt;
            TRACFCOMP(g_trac_targeting,
                    "check_proc0_memory_config: proc0 %.8X is set to use "
                    "topoId %d",
                    get_huid(l_procIds[l_proc0].proc),
                    l_procIds[l_proc0].topoId);

            // Set the desired IDs for the swapped proc from proc0 defaults
            l_procIds[l_victim].topoId = l_procIds[l_proc0].topoIdDflt;
            TRACFCOMP(g_trac_targeting,
                    "check_proc0_memory_config: Proc %.8X is set to use "
                    "topoId %d",
                    get_huid(l_procIds[l_victim].proc),
                    l_procIds[l_victim].topoId);

            // Leave loop after swapping memory
            break;
        }

    }

    // Loop through all procs detecting that IDs are set correctly
    bool l_swappedIds = false;
    for (i = 0; i < l_procsList.size(); i++)
    {
        TRACDCOMP(g_trac_targeting,
                "check_proc0_memory_config: Compare settings for "
                "Proc %.8X: topoIdEff = %d, topoId = %d",
                get_huid(l_procIds[i].proc),
                l_procIds[i].topoIdEff,
                l_procIds[i].topoId);

        if(l_procIds[i].topoId != l_procIds[i].topoIdEff)
        {
            // Update attributes
            TRACFCOMP(g_trac_targeting,
                "check_proc0_memory_config: updating "
                "ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID for "
                "Proc %.8X: topoIdEff = %d --> topoId = %d",
                get_huid(l_procIds[i].proc),
                l_procIds[i].topoIdEff,
                l_procIds[i].topoId);
            (l_procIds[i].proc)->
                setAttr<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>(l_procIds[i].topoId);
            l_swappedIds = true;
        }

        TRACDCOMP(g_trac_targeting,
                "check_proc0_memory_config: Current attribute "
                "settings for Proc %.8X\n"
                "  ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID = %d\n"
                "  ATTR_PROC_FABRIC_TOPOLOGY_ID = %d\n",
                get_huid(l_procIds[i].proc),
                (l_procIds[i].proc)->
                getAttr<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>(),
                (l_procIds[i].proc)->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>());
    }

    // If we have any procs where FABRIC_EFF_TOPOLOGY_ID != FABRIC_TOPOLOGY_ID
    //  then we need to recompute all of the BARs as well
    // note: This is similar to what we do in adjustMemoryMap(), but that only
    //       handles the boot processor
    if( l_swappedIds )
    {
        TARG_INF( "Recomputing BARs after topology id swap" );
        auto l_pTopLevel = TARGETING::UTIL::assertGetToplevelTarget();

        TARGETING::TargetHandleList l_funcProcs;
        getAllChips(l_funcProcs, TYPE_PROC, false );

        // Get topology mode (same for all procs)
        const auto l_topologyMode =
          l_pTopLevel->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_MODE>();
         TARG_INF( "ATTR_PROC_FABRIC_TOPOLOGY_MODE=%d", l_topologyMode );

        // Save off the base (group0-chip0) value for the BARs
        ATTR_XSCOM_BASE_ADDRESS_type l_xscomBase =
          l_pTopLevel->getAttr<ATTR_XSCOM_BASE_ADDRESS>();
        ATTR_LPC_BUS_ADDR_type l_lpcBase =
          l_pTopLevel->getAttr<ATTR_LPC_BUS_ADDR>();

        for (i = 0; i < l_procsList.size(); i++)
        {
            TARG_INF( "Proc=%.8X (eff_topo_id=0x%X)",
                      get_huid(l_procIds[i].proc),
                      l_procIds[i].topoId );

            ATTR_XSCOM_BASE_ADDRESS_type l_xscomBAR =
              computeMemoryMapOffset( l_xscomBase,
                                      l_topologyMode,
                                      l_procIds[i].topoId);
            TARG_INF( "l_xscomBase=%.8X, l_topologyMode=%d, l_xscomBAR=%.8X",
                      l_xscomBase, l_topologyMode, l_xscomBAR );

            //If Xscom addr has SMF bit on... propagate
            auto l_curXscomBAR =
              (l_procIds[i].proc)->getAttr<ATTR_XSCOM_BASE_ADDRESS>();
            if(l_curXscomBAR & IS_SMF_ADDR_BIT)
            {
                l_xscomBAR |= IS_SMF_ADDR_BIT;
            }

            TARG_INF( " XSCOM=%.16llX", l_xscomBAR );
            (l_procIds[i].proc)->setAttr<ATTR_XSCOM_BASE_ADDRESS>(l_xscomBAR);

            // Compute default LPC BAR
            ATTR_LPC_BUS_ADDR_type l_lpcBAR =
              computeMemoryMapOffset( l_lpcBase, l_topologyMode, l_procIds[i].topoId);
            TARG_INF( " LPC=%.16llX", l_lpcBAR );
            (l_procIds[i].proc)->setAttr<ATTR_LPC_BUS_ADDR>(l_lpcBAR);

            //Setup Interrupt Related Bars
            ATTR_PSI_BRIDGE_BASE_ADDR_type l_psiBridgeBAR =
              computeMemoryMapOffset(MMIO_GROUP0_CHIP0_PSI_BRIDGE_BASE_ADDR,
                                     l_topologyMode, l_procIds[i].topoId);
            TARG_INF( " PSI_BRIDGE_BAR =%.16llX", l_psiBridgeBAR );
            (l_procIds[i].proc)->setAttr<ATTR_PSI_BRIDGE_BASE_ADDR>(l_psiBridgeBAR);

            ATTR_XIVE_CONTROLLER_BAR_ADDR_type l_xiveCtrlBAR =
              computeMemoryMapOffset(MMIO_GROUP0_CHIP0_XIVE_CONTROLLER_BASE_ADDR,
                                     l_topologyMode, l_procIds[i].topoId);
            TARG_INF( " XIVE_CONTROLLER_BAR =%.16llX", l_xiveCtrlBAR );
            (l_procIds[i].proc)->setAttr<ATTR_XIVE_CONTROLLER_BAR_ADDR>(l_xiveCtrlBAR);

            ATTR_INT_CQ_TM_BAR_ADDR_type l_intCqTmBAR =
              computeMemoryMapOffset(MMIO_GROUP0_CHIP0_INT_CQ_TM_BASE_ADDR,
                                     l_topologyMode, l_procIds[i].topoId);
            TARG_INF( " INT_CQ_TM_BAR =%.16llX", l_intCqTmBAR );
            (l_procIds[i].proc)->setAttr<ATTR_INT_CQ_TM_BAR_ADDR>(l_intCqTmBAR);

            ATTR_PSI_HB_ESB_ADDR_type l_psiHbEsbBAR =
              computeMemoryMapOffset(MMIO_GROUP0_CHIP0_PSI_HB_ESB_BASE_ADDR,
                                     l_topologyMode, l_procIds[i].topoId);
            TARG_INF( " PSI_HB_ESB_BAR =%.16llX", l_psiHbEsbBAR );
            (l_procIds[i].proc)->setAttr<ATTR_PSI_HB_ESB_ADDR>(l_psiHbEsbBAR);

            ATTR_FSP_BASE_ADDR_type l_fspBAR =
              computeMemoryMapOffset(MMIO_GROUP0_CHIP0_FSP_BASE_ADDR,
                                     l_topologyMode, l_procIds[i].topoId);
            TARG_INF( " FSP_BAR =%.16llX", l_fspBAR );
            (l_procIds[i].proc)->setAttr<ATTR_FSP_BASE_ADDR>(l_fspBAR);

        }

        // If we swapped any topologies, we need to do a reconfig loop to
        //  get the memory configuration back in sync with reality since
        //  that was computed before this logic runs.
        auto l_reconfigAttr =
              l_pTopLevel->getAttr<ATTR_RECONFIGURE_LOOP>();
        l_reconfigAttr |= 0x10; //@fixme-Change to RECONFIGURE_LOOP_TOPOLOGY_SWAP after ekb change
        l_pTopLevel->setAttr<ATTR_RECONFIGURE_LOOP>(l_reconfigAttr);
    }

    return l_err;
} // end check_proc0_memory_config()


#ifndef __HOSTBOOT_RUNTIME
// Return the numerical number of the primary node
int getPrimaryNodeNumber( void )
{
    int l_primaryNode = -1;

  // the primary node is always the functional node with the lowest
  //  position number, i.e. the first bit set in this attribute
  auto hb_images = TARGETING::UTIL::assertGetToplevelTarget()
      ->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

    // This attribute is only set on multidrawer, so zero means
    //  we are a single node system
    if( hb_images == 0 )
    {
        // the node we are on now is the primary (only) node
        l_primaryNode = TARGETING::UTIL::getCurrentNodePhysId();
    }
    else
    {
        // start the 1 in the mask at leftmost position
        decltype(hb_images) l_mask = 0x1 <<
          (sizeof(hb_images)*8-1);

        for( size_t x = 0;
             x < (sizeof(hb_images)*8);
             x++ )
        {
            if( l_mask & hb_images )
            {
                l_primaryNode = x;
                break;
            }
            l_mask >>= 1;
        }
    }

    // make sure that at least 1 node is in the list
    assert( l_primaryNode != -1, "No primary node discovered" );

    return l_primaryNode;
}
#endif //#ifndef __HOSTBOOT_RUNTIME

/**
 * @brief Single entry point to access attribute metadata map
 */
const AttrMetadataMapper& getMapMetadataForAllAttributes()
{
    return theMapAttrMetadata::instance().getMapMetadataForAllAttributes();
}

#undef TARG_NAMESPACE
#undef TARG_CLASS

} // End namespace TARGETING::UTIL

} // End namespace TARGETING
