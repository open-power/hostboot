/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/targplatutil.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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

    const auto& l_attrMetaData
        = theMapAttrMetadata::instance().getMapMetadataForAllAttributes();

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

#ifdef CONFIG_BMC_IPMI
    uint32_t getIPMISensorNumber( const TARGETING::Target*& i_targ,
        TARGETING::SENSOR_NAME i_name );
#endif


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
    getEncResources(l_nodelist, TARGETING::TYPE_NODE,
                    TARGETING::UTIL_FILTER_FUNCTIONAL);
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

// return the sensor number from the passed in target
uint32_t getSensorNumber( const TARGETING::Target* i_pTarget,
                          TARGETING::SENSOR_NAME i_name )
{

#ifdef CONFIG_BMC_IPMI
    // get the IPMI sensor number from the array, these are unique for each
    // sensor + sensor owner in an IPMI system
    return getIPMISensorNumber( i_pTarget, i_name );
#else
    // pass back the HUID - this will be the sensor number for non ipmi based
    // systems
    return get_huid( i_pTarget );

#endif

}

// convert sensor number to a target
TARGETING::Target * getSensorTarget(const uint32_t i_sensorNumber )
{

#ifdef CONFIG_BMC_IPMI
    return TARGETING::UTIL::getTargetFromIPMISensor( i_sensorNumber );
#else
    // in non ipmi systems huid == sensor number
    return Target::getTargetFromHuid( i_sensorNumber );
#endif

}

// predicate for binary search of ipmi sensors array.
// given an array[][2] compare the sensor name, located in the first column,
// to the passed in key value
static inline bool name_predicate( uint16_t (&a)[2], uint16_t key )
{
    return  a[TARGETING::IPMI_SENSOR_ARRAY_NAME_OFFSET] < key;
};

#ifdef  CONFIG_BMC_IPMI
// given a target and sensor name, return the IPMI sensor number
// from the IPMI_SENSORS attribute.
uint32_t getIPMISensorNumber( const TARGETING::Target*& i_targ,
        TARGETING::SENSOR_NAME i_name )
{
    // $TODO RTC:123035 investigate pre-populating some info if we end up
    // doing this multiple times per sensor
    //
    // Helper function to search the sensor data for the correct sensor number
    // based on the sensor name.
    //
    uint8_t l_sensor_number = INVALID_IPMI_SENSOR;

    const TARGETING::Target * l_targ = i_targ;

    if( i_targ == NULL )
    {
        TARGETING::Target * sys;
        // use the system target
        TARGETING::targetService().getTopLevelTarget(sys);

        // die if there is no system target
        assert(sys);

        l_targ = sys;
    }

    TARGETING::AttributeTraits<TARGETING::ATTR_IPMI_SENSORS>::Type l_sensors;

    // if there is no sensor attribute, we will return INVALID_IPMI_SENSOR(0xFF)
    if(  l_targ->tryGetAttr<TARGETING::ATTR_IPMI_SENSORS>(l_sensors) )
    {
        // get the number of rows by dividing the total size by the size of
        // the first row
        uint16_t array_rows = (sizeof(l_sensors)/sizeof(l_sensors[0]));

        // create an iterator pointing to the first element of the array
        uint16_t (*begin)[2]  = &l_sensors[0];

        // using the number entries as the index into the array will set the
        // end iterator to the correct position or one entry past the last
        // element of the array
        uint16_t (*end)[2] = &l_sensors[array_rows];

        uint16_t (*ptr)[2] =
            std::lower_bound(begin, end, i_name, &name_predicate);

        // we have not reached the end of the array and the iterator
        // returned from lower_bound is pointing to an entry which equals
        // the one we are searching for.
        if( ( ptr != end ) &&
                ( (*ptr)[TARGETING::IPMI_SENSOR_ARRAY_NAME_OFFSET] == i_name ) )
        {
            // found it
            l_sensor_number =
                (*ptr)[TARGETING::IPMI_SENSOR_ARRAY_NUMBER_OFFSET];

        }
    }
    return l_sensor_number;
}

class number_predicate
{
    public:

        number_predicate( const uint32_t number )
            :iv_number(number)
        {};

        bool operator()( const uint16_t (&a)[2] ) const
        {
            return  a[TARGETING::IPMI_SENSOR_ARRAY_NUMBER_OFFSET] == iv_number;
        }

    private:
        uint32_t iv_number;
};

//******************************************************************************
// getTargetFromIPMISensor()
//******************************************************************************
Target * getTargetFromIPMISensor( uint32_t i_sensorNumber )
{

    // if the size of HUID is made larger than a uint32_t the compile will fail
    CPPASSERT((sizeof(TARGETING::ATTR_HUID_type) > sizeof(i_sensorNumber)));

    // 1. find targets with IPMI_SENSOR attribute which has sensor numbers
    // 2. search array for the sensor number (not sorted on this column)
    // 3. return the target

    TARGETING::Target * l_target = NULL;

    TARGETING::AttributeTraits<TARGETING::ATTR_IPMI_SENSORS>::Type l_sensors;

    for (TargetIterator itr = TARGETING::targetService().begin();
            itr != TARGETING::targetService().end(); ++itr)
    {
        // if there is a sensors attribute, see if our number is in it
        if( (*itr)->tryGetAttr<TARGETING::ATTR_IPMI_SENSORS>(l_sensors))
        {
            uint16_t array_rows = (sizeof(l_sensors)/sizeof(l_sensors[0]));

            // create an iterator pointing to the first sensor number of the
            // array.
            uint16_t (*begin)[2] =
                &l_sensors[TARGETING::IPMI_SENSOR_ARRAY_NAME_OFFSET];

            // using the number entries as the index into the array will set the
            // end iterator to the correct position or one entry past the last
            // element of the array
            uint16_t (*end)[2] = &l_sensors[array_rows];

            uint16_t (*ptr)[2] = std::find_if(begin, end,
                                              number_predicate(i_sensorNumber));

            if ( ptr != end )
            {
                // found it
                l_target = *itr;
                break;
            }
        }
    }
    return l_target;
}

#endif

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


#undef TARG_NAMESPACE
#undef TARG_CLASS

} // End namespace TARGETING::UTIL

} // End namespace TARGETING
