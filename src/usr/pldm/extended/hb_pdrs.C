/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/hb_pdrs.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

/* @file hb_pdrs.C
 *
 * @brief Implementation of functions related to PDRs that Hostboot itself
 *        generates.
 */

// Standard library
#include <map>
#include <memory>
#include <algorithm>
#include <string.h>

// PLDM
#include <pldm/extended/hb_pdrs.H>
#include <pldm/extended/pldm_fru.H>
#include <pldm/extended/pdr_manager.H>
#include "../common/pldmtrace.H"
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_util.H>
#include <pldm/responses/pldm_fru_data_responders.H>
#include <pldm/responses/pldm_monitor_control_responders.H>

// libpldm headers from pldm subtree
#include <openbmc/pldm/libpldm/pdr.h>
#include <openbmc/pldm/libpldm/platform.h>
#include <openbmc/pldm/libpldm/state_set.h>

// Targeting
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/predicates/predicatehwas.H>
#include <targeting/targplatutil.H>

using namespace TARGETING;
using namespace PLDM;
using namespace ERRORLOG;

namespace
{
typedef std::map<fru_record_set_id, pldm_entity> FruRecordSetMap;
typedef std::map<TargetHandle_t, pldm_entity> SensorEntityMap;

// Allow the tree add to determine entity instance number
constexpr uint16_t DEFAULT_TREE_ADD_ENTITY_INSTANCE_NUM = 0xFFFF;

/* @brief Creates Entity Association and FRU record set PDRs
 *        for specified entity_type target
 *
 * @param[in/out] io_tree    opaque pointer acting as a handle to the PLDM association tree
 * @param[in/out] io_pdrman  The PDR manager to add to
 * @param[in]     i_parent   Entity node parent for this new record
 * @param[in]     i_association_type  relation with the parent (physical or logical)
 * @param[in]     i_entity_type  FRU entity type
 * @param[in]     i_target   Target associated with these new PDR records
 * @param[in/out] io_fru_record_set_map FRU record set PDR information (used later to create these PDRs)
 *
 * @return pldm_entity_node* - opaque pointer to added entity in association tree
 */
pldm_entity_node* createEntityAssociationAndFruRecordSetPdrs(pldm_entity_association_tree *io_tree,
                                                   PdrManager& io_pdrman,
                                                   pldm_entity_node* const i_parent,
                                                   uint8_t i_association_type,
                                                   uint16_t i_entity_type,
                                                   const TargetHandle_t i_target,
                                                   FruRecordSetMap &io_fru_record_set_map )
{
    pldm_entity pldmEntity
    {
        // The entity_instance_num and entity_container_id members of
        // this struct are filled out by
        // pldm_entity_association_tree_add below
        .entity_type = i_entity_type
    };
    uint16_t requested_entity_instance_num = getEntityInstanceNumber(i_target, i_entity_type);

    PLDM_INF("Adding entity association and FRU record set PDRs for "
             "entity_type 0x%04X, HUID 0x%x, req instance_num 0x%x",
             i_entity_type, get_huid(i_target), requested_entity_instance_num);

    // Add the Entity Association record to the tree (will be converted
    // to PDRs and stored in the repo at the end)
    pldm_entity_node * entityNode = pldm_entity_association_tree_add(io_tree,
                                                                 &pldmEntity,
                                                                 requested_entity_instance_num,
                                                                 i_parent,
                                                                 i_association_type);

    // We need the FRU Record Set ID to be unique to each target
    // instance.
    fru_record_set_id_t rsid = 0;
    if (i_entity_type == ENTITY_TYPE_PROCESSOR_MODULE)
    {
        rsid = getTargetFruRecordSetID(i_target, TYPE_DCM);
    }
    else
    {
        rsid = getTargetFruRecordSetID(i_target);
    }

    // Add the FRU record set PDR information
    io_fru_record_set_map[rsid] = pldmEntity;

    return entityNode;
}



/* @brief Add Entity Association and FRU record set PDRs for cores
 *
 * @param[in/out] io_tree    opaque pointer acting as a handle to the PLDM association tree
 * @param[in/out] io_pdrman  The PDR manager to add to
 * @param[in]     i_parentNodeEntity  Entity node parent for these new records
 * @param[in]     i_proc_target   Processor target to look under for cores
 * @param[in/out] io_fru_record_set_map FRU record set PDR information (used later to create these PDRs)
 * @param[in/out] io_core_sensor_map State sensor map to add cores into
 *
 */
void addCoreEntityAssocAndRecordSetPdrs(pldm_entity_association_tree *io_tree,
                                        PdrManager& io_pdrman,
                                        pldm_entity_node * i_parentNodeEntity,
                                        const TargetHandle_t i_proc_target,
                                        FruRecordSetMap &io_fru_record_set_map,
                                        SensorEntityMap &io_core_sensor_map )
{
    TARGETING::TYPE l_core_type = TYPE_CORE;
    if(TARGETING::is_fused_mode())
    {
        l_core_type = TYPE_FC;
    }

    // @TODO RTC 282978: Update this to only report non-ECO cores
    // find all CORE or FC chiplets of the proc
    TARGETING::TargetHandleList l_coreTargetList;
    TARGETING::getChildAffinityTargetsByState( l_coreTargetList,
                                               i_proc_target,
                                               CLASS_UNIT,
                                               l_core_type,
                                               UTIL_FILTER_PRESENT);

    std::sort(begin(l_coreTargetList), end(l_coreTargetList),
          [](const Target* const t1, const Target* const t2) {
              return t1->getAttr<ATTR_MRU_ID>() < t2->getAttr<ATTR_MRU_ID>();
          });

    for ( auto & l_core_target : l_coreTargetList )
    {
        PLDM_INF("Add entity association and FRU record set PDRs for %s HUID 0x%08X",
                 (l_core_type==TYPE_CORE)?"core":"fc", get_huid(l_core_target));

        const auto entity_node
            = createEntityAssociationAndFruRecordSetPdrs(io_tree,
                                                io_pdrman,
                                                i_parentNodeEntity,
                                                PLDM_ENTITY_ASSOCIAION_PHYSICAL,
                                                ENTITY_TYPE_LOGICAL_PROCESSOR,
                                                l_core_target,
                                                io_fru_record_set_map);
        io_core_sensor_map[l_core_target] = pldm_entity_extract(entity_node);
    }
}


/* @brief Add Entity Association and FRU Record Set PDRs for FRUs that Hostboot
 *        owns to the given PDR manager.
 *
 * @param[in/out] io_pdrman  The PDR manager to add to
 * @param[out] o_backplane_entity The base backplane entity
 */
void addEntityAssociationAndFruRecordSetPdrs(PdrManager& io_pdrman, pldm_entity & o_backplane_entity)
{
    using enttree_ptr
        = std::unique_ptr<pldm_entity_association_tree,
                          decltype(&pldm_entity_association_tree_destroy)>;

    const enttree_ptr enttree { pldm_entity_association_tree_init(),
                                pldm_entity_association_tree_destroy };

    // map so record sets can be added after associative records
    FruRecordSetMap fru_record_set_map;
    SensorEntityMap core_sensor_entity_map;

    /* Add the backplane (root node) to the tree. */
    o_backplane_entity.entity_type = ENTITY_TYPE_BACKPLANE;

    const auto backplane_node
        = pldm_entity_association_tree_add(enttree.get(),
                                           &o_backplane_entity,
                                           DEFAULT_TREE_ADD_ENTITY_INSTANCE_NUM,
                                           nullptr, // means "no parent" i.e. root
                                           PLDM_ENTITY_ASSOCIAION_PHYSICAL);
    PLDM_DBG("Backplane_entity: entity_type 0x%04X, entity_instance_num 0x%04X, container_id 0x%04X",
        o_backplane_entity.entity_type, o_backplane_entity.entity_instance_num, o_backplane_entity.entity_container_id);

    /* Now we add all the children under the backplane to the tree. */
    struct cmp_str
    {
       // note: vectors contain strings (null-terminated)
       bool operator()(std::vector<char> a, std::vector<char> b) const
       {
            return strcmp(a.data(), b.data()) > 0;
       }
    };
    // maps location code to DCM pldm entity
    // using vector for auto-memory cleanup
    std::map<std::vector<char>, pldm_entity_node*, cmp_str> l_dcmLocationMap;
    pldm_entity_node * proc_node = nullptr;
    for (const auto entity : fru_inventory_classes)
    {
        TargetHandleList targets;

        getClassResources(targets,
                          entity.targetClass,
                          entity.targetType,
                          UTIL_FILTER_PRESENT);

        std::sort(begin(targets), end(targets),
                  [](const Target* const t1, const Target* const t2) {
                      return t1->getAttr<ATTR_POSITION>() < t2->getAttr<ATTR_POSITION>();
                  });

        for (size_t i = 0; i < targets.size(); ++i)
        {
            if (entity.targetType == TYPE_PROC)
            {
                ATTR_STATIC_ABS_LOCATION_CODE_type abs_location_code { };
                assert(UTIL::tryGetAttributeInHierarchy<ATTR_STATIC_ABS_LOCATION_CODE>(targets[i], abs_location_code),
                        "Cannot get ATTR_STATIC_ABS_LOCATION_CODE from HUID = 0x%08x", get_huid(targets[i]));
                std::vector<char> vLocationStr(abs_location_code, abs_location_code + sizeof(abs_location_code)/sizeof(*abs_location_code));
                pldm_entity_node* proc_parent_entity = nullptr;
                auto it = l_dcmLocationMap.find(vLocationStr);
                if (it == l_dcmLocationMap.end())
                {
                    // no DCM yet for this processor, so create the DCM
                    PLDM_DBG("Creating DCM for HUID 0x%x, location code %s", get_huid(targets[i]), abs_location_code);
                    auto newDcmEntity = createEntityAssociationAndFruRecordSetPdrs(enttree.get(),
                                                io_pdrman,
                                                backplane_node,
                                                PLDM_ENTITY_ASSOCIAION_PHYSICAL,
                                                ENTITY_TYPE_PROCESSOR_MODULE,
                                                targets[i],
                                                fru_record_set_map);

                    l_dcmLocationMap[vLocationStr] = newDcmEntity;

                    proc_parent_entity = newDcmEntity;
                }
                else
                {
                    // Second processor target found, place this under DCM
                    PLDM_DBG("Second processor HUID 0x%x found location code %s", get_huid(targets[i]), abs_location_code);
                    // it->second = DCM_NODE entity
                    proc_parent_entity = it->second;
                }

                proc_node = createEntityAssociationAndFruRecordSetPdrs(enttree.get(),
                                                                       io_pdrman,
                                                                       proc_parent_entity,
                                                                       PLDM_ENTITY_ASSOCIAION_PHYSICAL,
                                                                       entity.entityType,
                                                                       targets[i],
                                                                       fru_record_set_map);

                // Add core entries under the processor
                addCoreEntityAssocAndRecordSetPdrs(enttree.get(), io_pdrman, proc_node, targets[i], fru_record_set_map, core_sensor_entity_map);

                /* Set ATTR_PLDM_ENTITY_ID_INFO on the processor so that it can
                 * be used when creating sensors/effecters on this target
                 * later. This attribute will be overwritten with an updated ID
                 * after hostboot fetches the normalized PDR repository from the
                 * BMC. */

                const auto entity_id = pldm_entity_extract(proc_node);

                ATTR_PLDM_ENTITY_ID_INFO_type targeting_entity_id = { };
                // These values are already in little-endian.
                targeting_entity_id.entityType = entity_id.entity_type;
                targeting_entity_id.entityInstanceNumber = entity_id.entity_instance_num;
                targeting_entity_id.containerId = entity_id.entity_container_id;

                targets[i]->setAttr<ATTR_PLDM_ENTITY_ID_INFO>(targeting_entity_id);
            }
            else
            {
                // non-proc types added to backplane
                createEntityAssociationAndFruRecordSetPdrs(enttree.get(),
                                                io_pdrman,
                                                backplane_node,
                                                PLDM_ENTITY_ASSOCIAION_PHYSICAL,
                                                entity.entityType,
                                                targets[i],
                                                fru_record_set_map);
            }
        }
    }

    // Make sure Association PDRs are added before FRU record set PDRs and core State Sensor PDRs
    /* Serialize the tree into the PDR repository. */
    io_pdrman.addEntityAssociationPdrs(*enttree.get(), false /* is_remote */);

    /* now add all the FRU record set PDRs */
    for (auto const& fru_record : fru_record_set_map)
    {
        // Add the FRU record set PDR to the repo
        io_pdrman.addFruRecordSetPdr(fru_record.first, fru_record.second);

        PLDM_DBG("FRU RECORD SET PDR: fru_rsi 0x%04X, entity_type 0x%04X, entity_instance_num 0x%04X, container_id 0x%04X",
        fru_record.first, fru_record.second.entity_type, fru_record.second.entity_instance_num, fru_record.second.entity_container_id);
    }

    /* now add the State Sensor PDRs for cores */
    for (auto const& core_sensor_entity : core_sensor_entity_map)
    {
        // Add the state sensor pdr for core target to PDR repo
        io_pdrman.addStateSensorPdr(core_sensor_entity.first, core_sensor_entity.second,
                                    PLDM_STATE_SET_HEALTH_STATE,
                                    (enum_bit(PLDM_STATE_SET_HEALTH_STATE_NORMAL)
                                     | enum_bit(PLDM_STATE_SET_HEALTH_STATE_CRITICAL)),
                                    PdrManager::STATE_QUERY_HANDLER_FUNCTIONAL_STATE_SENSOR);
    }
}


/* @brief Add the state effecter and sensor PDRs for OCC FRUs.
 *
 * @param[in/out] io_pdrman  The PDR manager to add to
 * @return errlHndl_t        Error if any, otherwise nullptr
 */
errlHndl_t addOccStateControlPdrs(PdrManager& io_pdrman)
{
    TargetHandleList targets;
    errlHndl_t errl = nullptr;

    getClassResources(targets,
                      CLASS_UNIT,
                      TYPE_OCC,
                      UTIL_FILTER_PRESENT);

    /* Get each OCC and add state effecter and sensor PDRs for it. */

    for (const auto target : targets)
    {
        Target* const parent_proc = getImmediateParentByAffinity(target);
        pldm_entity entity { };
        const auto parent_proc_rsid = getTargetFruRecordSetID(parent_proc);
        const bool entity_found = io_pdrman.findEntityByFruRecordSetId(parent_proc_rsid, entity);

        if (!entity_found)
        {
            PLDM_ERR("addOccStateControlPdrs> Unable to find an entity matching RSID 0x%04x for HUID 0x%08x",
                      parent_proc_rsid, get_huid(parent_proc));

            /*@
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_ADD_OCC_PDRS
             * @reasoncode RC_NO_ENTITY_FROM_RSID
             * @userdata1  record set id of occ's parent processor
             * @userdata2  HUID of target
             * @devdesc    Unable to find the entity associated with this RSID
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_ADD_OCC_PDRS,
                                 RC_NO_ENTITY_FROM_RSID,
                                 parent_proc_rsid,
                                 get_huid(parent_proc),
                                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        io_pdrman.addStateEffecterPdr(target, entity,
                                      PLDM_STATE_SET_BOOT_RESTART_CAUSE,
                                      (enum_bit(PLDM_STATE_SET_BOOT_RESTART_CAUSE_WARM_RESET)
                                       | enum_bit(PLDM_STATE_SET_BOOT_RESTART_CAUSE_HARD_RESET)),
                                      PdrManager::STATE_QUERY_HANDLER_OCC_STATE_QUERY);

        io_pdrman.addStateSensorPdr(target, entity,
                                    PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS,
                                    (enum_bit(PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_STOPPED)
                                     | enum_bit(PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_IN_SERVICE)),
                                    PdrManager::STATE_QUERY_HANDLER_OCC_STATE_QUERY);
    }

    return errl;
}

/* @brief Add the state effecter and sensor PDRs for graceful shutdown
 * functionality.
 *
 * @param[in/out] io_pdrman  The PDR manager to add to
 * @return errlHndl_t        Error if any, otherwise nullptr
 */
errlHndl_t addSystemStateControlPdrs(PdrManager& io_pdrman)
{
    const uint16_t CONTAINER_ID_TOPLEVEL = 0;

    pldm_entity chassis =
    {
        .entity_type = ENTITY_TYPE_CHASSIS,
        .entity_instance_num = 1, // There's only one chassis
        .entity_container_id = CONTAINER_ID_TOPLEVEL
    };

    io_pdrman.addStateEffecterPdr(UTIL::assertGetToplevelTarget(),
                                  chassis,
                                  PLDM_STATE_SET_SW_TERMINATION_STATUS,
                                  enum_bit(PLDM_SW_TERM_GRACEFUL_SHUTDOWN_REQUESTED),
                                  PdrManager::STATE_QUERY_HANDLER_GRACEFUL_SHUTDOWN);

    io_pdrman.addStateSensorPdr(UTIL::assertGetToplevelTarget(),
                                chassis,
                                PLDM_STATE_SET_SW_TERMINATION_STATUS,
                                (enum_bit(PLDM_SW_TERM_NORMAL)
                                 | enum_bit(PLDM_SW_TERM_GRACEFUL_SHUTDOWN_REQUESTED)
                                 | enum_bit(PLDM_SW_TERM_GRACEFUL_SHUTDOWN)),
                                PdrManager::STATE_QUERY_HANDLER_GRACEFUL_SHUTDOWN);

    return nullptr;
}

errlHndl_t addFruInventoryPdrs(PdrManager& io_pdrman)
{
    errlHndl_t errl = nullptr;

    for (const auto& inventory : fru_inventory_classes)
    {
        TargetHandleList targets;
        getClassResources(targets, CLASS_NA, inventory.targetType, UTIL_FILTER_PRESENT);

        /* Iterate over all present HB FRU targets */

        for (const auto target : targets)
        {
            pldm_entity entity { };
            const auto target_rsid = getTargetFruRecordSetID(target);
            const bool entity_found = io_pdrman.findEntityByFruRecordSetId(target_rsid, entity);

            if (!entity_found)
            {
                PLDM_ERR("addFruInventoryPdrs> Unable to find an entity matching RSID 0x%04x for HUID 0x%08x",
                         target_rsid, get_huid(target));

                /*@
                 * @errortype  ERRL_SEV_UNRECOVERABLE
                 * @moduleid   MOD_ADD_INVENTORY_PDRS
                 * @reasoncode RC_NO_ENTITY_FROM_RSID
                 * @userdata1  record set ID of target
                 * @userdata2  HUID of target
                 * @devdesc    Unable to find the entity associated with this RSID
                 * @custdesc   A software error occurred during system boot
                 */
                errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                     MOD_ADD_INVENTORY_PDRS,
                                     RC_NO_ENTITY_FROM_RSID,
                                     target_rsid,
                                     get_huid(target),
                                     ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }

            /* Add a state sensor PDR for the target's functional state and
             * register a callback to handle queries about it. Using the
             * PLDM_STATE_SET_HEALTH_STATE enumeration in this call will cause
             * the target and sensor ID to be registered so that when
             * PdrManager::sendAllFruFunctionalStates is called, it will include
             * information about this target via this sensor. */

            io_pdrman.addStateSensorPdr(target, entity,
                                        PLDM_STATE_SET_HEALTH_STATE,
                                        (enum_bit(PLDM_STATE_SET_HEALTH_STATE_NORMAL)
                                         | enum_bit(PLDM_STATE_SET_HEALTH_STATE_CRITICAL)),
                                        PdrManager::STATE_QUERY_HANDLER_FUNCTIONAL_STATE_SENSOR);
        }

        if (errl)
        {
            break;
        }
    }

    return errl;
}

void addSbeManagementPdrs(PdrManager& io_pdrman)
{
    TargetHandleList procs;
    TARGETING::getChildAffinityTargetsByState(procs, UTIL::assertGetToplevelTarget(), CLASS_NA, TYPE_PROC, UTIL_FILTER_PRESENT);

    // @TODO RTC 247294: Delete these constants and use the ones from libpldm
    const uint16_t PLDM_OEM_IBM_SBE_MAINTENANCE_STATE = 32775;
    const uint16_t PLDM_OEM_IBM_SBE_HRESET_STATE = 32776;

    enum ibm_oem_pldm_state_set_sbe_dump_state_values {
        SBE_DUMP_COMPLETED = 0x1,
        SBE_RETRY_REQUIRED = 0x2,
    };

    for (const auto proc : procs)
    {
        const auto entity_info = targeting_to_pldm_entity_id(proc->getAttr<ATTR_PLDM_ENTITY_ID_INFO>());

        io_pdrman.addStateEffecterPdr(proc,
                                      entity_info,
                                      PLDM_OEM_IBM_SBE_MAINTENANCE_STATE,
                                      (enum_bit(SBE_DUMP_COMPLETED)
                                       | enum_bit(SBE_RETRY_REQUIRED)),
                                      // We create a dynamic handler for this type of effecter
                                      PdrManager::STATE_QUERY_HANDLER_REQUEST_HRESET);

        static_assert(AttributeTraits<ATTR_CURRENT_SBE_HRESET_STATUS>::readable);
        static_assert(sizeof(ATTR_CURRENT_SBE_HRESET_STATUS_type) == 2,
                      "ATTR_CURRENT_SBE_HRESET_STATUS must be 2 bytes (size of a sensor value)");

        io_pdrman.addStateSensorPdr(proc,
                                    entity_info,
                                    PLDM_OEM_IBM_SBE_HRESET_STATE,
                                    (enum_bit(SBE_HRESET_STATUS_READY)
                                     | enum_bit(SBE_HRESET_STATUS_NOT_READY)
                                     | enum_bit(SBE_HRESET_STATUS_FAILED)),
                                    PdrManager::STATE_QUERY_HANDLER_ATTRIBUTE_GETTER,
                                    ATTR_CURRENT_SBE_HRESET_STATUS);
    }
}

void addBootProgressPdrs(PdrManager& io_pdrman, const pldm_entity& i_backplane_entity)
{
#ifndef __HOSTBOOT_RUNTIME
    static_assert(AttributeTraits<ATTR_BOOT_PROGRESS_STATE>::readable);
    static_assert(sizeof(ATTR_BOOT_PROGRESS_STATE_type) == 2,
        "ATTR_BOOT_PROGRESS_STATE must be 2 bytes (size of a sensor value)");

    TargetHandle_t l_node = TARGETING::UTIL::getCurrentNodeTarget();
    io_pdrman.addStateSensorPdr(l_node,
            i_backplane_entity,
            PLDM_STATE_SET_BOOT_PROGRESS,
            (enum_bit(PLDM_STATE_SET_BOOT_PROG_STATE_COMPLETED)
             | enum_bit(PLDM_STATE_SET_BOOT_PROG_STATE_PRIMARY_PROC_INITIALIZATION)
             | enum_bit(PLDM_STATE_SET_BOOT_PROG_STATE_BASE_BOARD_INITIALIZATION)
             | enum_bit(PLDM_STATE_SET_BOOT_PROG_STATE_MEM_INITIALIZATION)
             | enum_bit(PLDM_STATE_SET_BOOT_PROG_STATE_SEC_PROC_INITIALIZATION)
            ),
            PdrManager::STATE_QUERY_HANDLER_ATTRIBUTE_GETTER,
            ATTR_BOOT_PROGRESS_STATE);
#endif
}


}

namespace PLDM
{
/* Get the Entity Instance Number associated with target and entity_type */
uint16_t getEntityInstanceNumber(ConstTargetHandle_t i_target, uint16_t i_entity_type)
{
    uint16_t entityInstanceNum = DEFAULT_TREE_ADD_ENTITY_INSTANCE_NUM;

    ///////////////////////////////////////////////////////////
    // How to determine Entity Instance Number
    // --------------------------------------------------------
    // chip entity instance = chip's (ATTR_MRU_ID & 0xFFFF)
    // core entity instance = core's ATTR_CHIP_UNIT
    // module entity instance = group by proc chip location code and look up
    //                          the ATTR_POSITION/2 from one of the chip's in
    //                          each group
    // dimm entity instance = dimm's ATTR_POSITION
    ///////////////////////////////////////////////////////////
    switch(i_target->getAttr<ATTR_TYPE>())
    {
        case TYPE_PROC:
        {
            if (i_entity_type == ENTITY_TYPE_PROCESSOR_MODULE)
            {
                // DCM
                entityInstanceNum = (i_target->getAttr<ATTR_POSITION>())/2;
            }
            else
            {
                // Processor chip
                entityInstanceNum = (i_target->getAttr<ATTR_MRU_ID>() & 0xFFFF);
            }
        }
        break;

        case TYPE_FC:
        case TYPE_CORE:
        {
            entityInstanceNum = i_target->getAttr<ATTR_CHIP_UNIT>();
        }
        break;

        case TYPE_DIMM:
        {
            entityInstanceNum = i_target->getAttr<ATTR_POSITION>();
        }
        break;

        default:
        // already defaulted
        break;
    }
    return entityInstanceNum;
}

extern const std::array<fru_inventory_class, 2> fru_inventory_classes
{{
    { CLASS_CHIP,         TYPE_PROC, ENTITY_TYPE_PROCESSOR },
    { CLASS_LOGICAL_CARD, TYPE_DIMM, ENTITY_TYPE_DIMM }
}};

errlHndl_t addHostbootPdrs(PdrManager& io_pdrman)
{
    PLDM_ENTER("addHostbootPdrs");

    // Reset all sensor/effecter attributes.
    UTIL::assertGetToplevelTarget()->setAttr<ATTR_NUM_PLDM_STATE_QUERY_RECORDS>(0);

    errlHndl_t errl = nullptr;
    pldm_entity backplane_entity
    {
        .entity_type = ENTITY_TYPE_BACKPLANE
    };

    addEntityAssociationAndFruRecordSetPdrs(io_pdrman, backplane_entity);
    addBootProgressPdrs(io_pdrman, backplane_entity);
    errl = addSystemStateControlPdrs(io_pdrman);
    errl || (errl = addOccStateControlPdrs(io_pdrman));
    errl || (errl = addFruInventoryPdrs(io_pdrman));

    addSbeManagementPdrs(io_pdrman);
    io_pdrman.addTerminusLocatorPDR();

    PLDM_EXIT("addHostbootPdrs completed %s error", errl ? "with" : "without");

    return errl;
}

}
