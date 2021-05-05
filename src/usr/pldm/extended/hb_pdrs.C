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
#include <memory>
#include <algorithm>

// PLDM
#include <pldm/extended/hb_pdrs.H>
#include <pldm/extended/pldm_fru.H>
#include <pldm/extended/pdr_manager.H>
#include "../common/pldmtrace.H"
#include <pldm/pldm_reasoncodes.H>
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

/* @brief Add Entity Association and FRU Record Set PDRs for FRUs that Hostboot
 *        owns to the given PDR manager.
 *
 * @param[in/out] io_pdrman  The PDR manager to add to
 * @param[in] i_terminus_id  The host's terminus ID
 */
void addEntityAssociationAndFruRecordSetPdrs(PdrManager& io_pdrman, const terminus_id_t i_terminus_id)
{
    using enttree_ptr
        = std::unique_ptr<pldm_entity_association_tree,
                          decltype(&pldm_entity_association_tree_destroy)>;

    const enttree_ptr enttree { pldm_entity_association_tree_init(),
                                pldm_entity_association_tree_destroy };

    /* Add the backplane (root node) to the tree. */

    pldm_entity backplane_entity
    {
        .entity_type = ENTITY_TYPE_BACKPLANE
    };

    const auto backplane_node
        = pldm_entity_association_tree_add(enttree.get(),
                                           &backplane_entity,
                                           nullptr, // means "no parent" i.e. root
                                           PLDM_ENTITY_ASSOCIAION_PHYSICAL);

    /* Now we add all the children of the backplane to the tree. */

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
            pldm_entity pldmEntity
            {
                // The entity_instance_num and entity_container_id members of
                // this struct are filled out by
                // pldm_entity_association_tree_add below
                .entity_type = entity.entityType
            };

            PLDM_INF("Adding entity association and FRU record set PDRs for %s HUID 0x%x",
                     attrToString<ATTR_TYPE>(entity.targetType),
                     get_huid(targets[i]));

            // Add the Entity Assocation record to the tree (will be converted
            // to PDRs and stored in the repo at the end of this function)
            pldm_entity_association_tree_add(enttree.get(),
                                             &pldmEntity,
                                             backplane_node,
                                             PLDM_ENTITY_ASSOCIAION_PHYSICAL);

            // We need the FRU Record Set ID to be unique to each target
            // instance.
            const fru_record_set_id_t rsid = getTargetFruRecordSetID(targets[i]);

            // Add the FRU record set PDR to the repo
            io_pdrman.addFruRecordSetPdr(rsid, pldmEntity);
        }
    }

    /* Serialize the tree into the PDR repository. */

    io_pdrman.addEntityAssociationPdrs(*enttree.get(), false /* is_remote */);
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


}

namespace PLDM
{

extern const std::array<fru_inventory_class, 2> fru_inventory_classes
{{
    { CLASS_CHIP,         TYPE_PROC, ENTITY_TYPE_PROCESSOR_MODULE },
    { CLASS_LOGICAL_CARD, TYPE_DIMM, ENTITY_TYPE_DIMM }
}};

errlHndl_t addHostbootPdrs(PdrManager& io_pdrman)
{
    PLDM_ENTER("addHostbootPdrs");

    { // Reset all sensor/effecter attributes.
        const ATTR_PLDM_EFFECTER_INFO_type default_effecter_info { };
        const ATTR_PLDM_SENSOR_INFO_type default_sensor_info { };

        for (const auto target : targetService())
        {
            target->trySetAttr<ATTR_PLDM_EFFECTER_INFO>(default_effecter_info);
            target->trySetAttr<ATTR_PLDM_SENSOR_INFO>(default_sensor_info);
        }
    }

    errlHndl_t errl = nullptr;

    addEntityAssociationAndFruRecordSetPdrs(io_pdrman,
                                            io_pdrman.hostbootTerminusId());

    errl = addOccStateControlPdrs(io_pdrman);

    if (!errl)
    {
        errl = addFruInventoryPdrs(io_pdrman);
    }

    io_pdrman.addTerminusLocatorPDR();

    PLDM_EXIT("addHostbootPdrs completed %s error", errl ? "with" : "without");

    return errl;
}

}
