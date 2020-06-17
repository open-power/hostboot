/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/hb_pdrs.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#include "../extern/pdr.h"
#include "../extern/platform.h"
#include "../common/pldmtrace.H"

// Targeting
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/predicates/predicatehwas.H>
#include <targeting/targplatutil.H>

using namespace TARGETING;
using namespace PLDM;

namespace
{

// Used with the libpldm pldm_pdr_add API
const bool PDR_IS_NOT_REMOTE = false;
const int PDR_AUTO_CALCULATE_RECORD_HANDLE = 0;

/* @brief Add Entity Association and FRU Record Set PDRs for FRUs that Hostboot
 *        owns.
 *
 * @param[in/out] io_repo    The PDR repository to add PDRs to.
 * @param[in] i_terminus_id  The host's terminus ID.
 */
void addEntityAssociationAndFruRecordSetPdrs(pldm_pdr* const io_repo,
                                             const terminus_id_t i_terminus_id)
{
    assert(io_repo != nullptr,
           "addHostbootPdrs: io_repo is nullptr");

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
                     TARGETING::attrToString<TARGETING::ATTR_TYPE>(entity.targetType),
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
            pldm_pdr_add_fru_record_set(io_repo,
                                        i_terminus_id,
                                        rsid,
                                        pldmEntity.entity_type,
                                        pldmEntity.entity_instance_num,
                                        pldmEntity.entity_container_id);
        }
    }

    /* Serialize the tree into the PDR repository. */

    pldm_entity_association_pdr_add(enttree.get(), io_repo, false);
}

/* @brief Add the state sensor PDRs for OCC FRUs.
 *
 * @param[in/out] io_repo    The PDR repository to add PDRs to.
 * @param[in] i_terminus_id  The Host's terminus ID.
 * @param[in] i_target       The target to use the entity ID from for the sensor.
 */
void addOccStateSensorPdrs(pldm_pdr* const io_repo,
                             const terminus_id_t i_terminus_id,
                             const Target* const i_target)
{
    const auto entity_id = i_target->getAttr<ATTR_PLDM_ENTITY_ID_INFO>();

    // PLDM_ENTITY_ID_INFO is stored in little-endian
    const uint16_t be_entity_type =  le16toh(entity_id.entityType);
    const uint16_t be_entity_instance =  le16toh(entity_id.entityInstanceNumber);
    const uint16_t be_container_id =  le16toh(entity_id.containerId);

    PLDM_INF("Adding state sensor PDR for HUID 0x%08x (ORDINAL_ID %d)",
             get_huid(i_target), i_target->getAttr<ATTR_ORDINAL_ID>());

    const state_sensor_possible_states states =
    {
        .state_set_id = pldm_state_set_operational_running_status,
        .possible_states_size = 1, // size of possible_states
        .states =
        {
            enum_bit(pldm_state_set_operational_running_status_stopped)
            | enum_bit(pldm_state_set_operational_running_status_in_service)
        }
    };

    std::vector<uint8_t> encoded_pdr(sizeof(pldm_state_sensor_pdr) + sizeof(states));

    const auto pdr = reinterpret_cast<pldm_state_sensor_pdr*>(encoded_pdr.data());

    *pdr =
    {
        /// Header
        .hdr =
        {
            .record_handle = 0, // ask libpldm to fill this out
            .version = 0, // will be filled out by the encoder
            .type = 0, // will be filled out by the encoder
            .record_change_num = 0,
            .length = 0 // will be filled out by the encoder
        },

        /// Body
        .terminus_handle = i_terminus_id,

        // Using the ORDINAL_ID of the target will let us associate with the
        // correct target when we send a PlatformEventMessage with the new state
        .sensor_id = static_cast<uint16_t>(i_target->getAttr<ATTR_ORDINAL_ID>()),

        .entity_type = be_entity_type,
        .entity_instance = be_entity_instance,
        .container_id = be_container_id,

        .sensor_init = state_sensor_noInit,
        .sensor_auxiliary_names_pdr = false,
        .composite_sensor_count = 1
    };

    size_t actual_pdr_size = 0;

    const int rc = encode_pldm_state_sensor_pdr(pdr,
                                                encoded_pdr.size(),
                                                &states,
                                                sizeof(states),
                                                &actual_pdr_size);

    assert(rc == PLDM_SUCCESS,
           "Failed to encoded OCC state sensor PDR");

    pldm_pdr_add(io_repo, encoded_pdr.data(), actual_pdr_size,
                 PDR_AUTO_CALCULATE_RECORD_HANDLE,
                 PDR_IS_NOT_REMOTE);
}

/* @brief Add the state effecter PDRs for OCC FRUs.
 *
 * @param[in/out] io_repo    The PDR repository to add PDRs to.
 * @param[in] i_terminus_id  The Host's terminus ID.
 * @param[in] i_target       The target to use the entity ID from for the effecter.
 */
void addOccStateEffecterPdrs(pldm_pdr* const io_repo,
                             const terminus_id_t i_terminus_id,
                             const Target* const i_target)
{
    const auto entity_id = i_target->getAttr<ATTR_PLDM_ENTITY_ID_INFO>();

    // PLDM_ENTITY_ID_INFO is stored in little-endian
    const uint16_t be_entity_type =  le16toh(entity_id.entityType);
    const uint16_t be_entity_instance =  le16toh(entity_id.entityInstanceNumber);
    const uint16_t be_container_id =  le16toh(entity_id.containerId);

    PLDM_INF("Adding state effecter PDR for 0x%08x (ORDINAL_ID %d)",
             get_huid(i_target), i_target->getAttr<ATTR_ORDINAL_ID>());

    const state_effecter_possible_states states =
    {
        .state_set_id = pldm_state_set_boot_restart_cause,
        .possible_states_size = 1, // size of possible_states
        .states =
        {
            enum_bit(pldm_state_set_boot_restart_cause_warm_reset)
            | enum_bit(pldm_state_set_boot_restart_cause_hard_reset)
        }
    };

    std::vector<uint8_t> encoded_pdr(sizeof(pldm_state_effecter_pdr) + sizeof(states));

    const auto pdr = reinterpret_cast<pldm_state_effecter_pdr*>(encoded_pdr.data());

    *pdr =
    {
        /// Header
        .hdr =
        {
            .record_handle = 0, // ask libpldm to fill this out
            .version = 0, // will be filled out by the encoder
            .type = 0, // will be filled out by the encoder
            .record_change_num = 0,
            .length = 0 // will be filled out by the encoder
        },

        /// Body
        .terminus_handle = i_terminus_id,

        // Using the ORDINAL_ID of the target will let us associate with the
        // correct target when we receive a SetStateEffecterStates command later
        .effecter_id = static_cast<uint16_t>(i_target->getAttr<ATTR_ORDINAL_ID>()),

        .entity_type = be_entity_type,
        .entity_instance = be_entity_instance,
        .container_id = be_container_id,

        .effecter_semantic_id = 0, // PLDM defines no semantic IDs yet
        .effecter_init = state_effecter_noInit,
        .has_description_pdr = false,
        .composite_effecter_count = 1
    };

    size_t actual_pdr_size = 0;

    const int rc = encode_pldm_state_effecter_pdr(pdr,
                                                  encoded_pdr.size(),
                                                  &states,
                                                  sizeof(states),
                                                  &actual_pdr_size);

    assert(rc == PLDM_SUCCESS,
           "Failed to encoded OCC state effecter PDR");

    pldm_pdr_add(io_repo, encoded_pdr.data(), actual_pdr_size,
                 PDR_AUTO_CALCULATE_RECORD_HANDLE,
                 PDR_IS_NOT_REMOTE);
}

/* @brief Add the state effecter and sensor PDRs for OCC FRUs.
 *
 * @param[in/out] io_repo    The PDR repository to add PDRs to.
 * @param[in] i_terminus_id  The Host's terminus ID.
 */
void addOccStateControlPdrs(pldm_pdr* const io_repo,
                            const terminus_id_t i_terminus_id)
{
    TargetHandleList targets;

    getClassResources(targets,
                      CLASS_UNIT,
                      TYPE_OCC,
                      UTIL_FILTER_PRESENT);

    /* Get each OCC and add state effecter and sensor PDRs for it. */

    for (const auto target : targets)
    {
        Target* const parent_proc = getImmediateParentByAffinity(target);

        // The OCC state sensor/effecter PDRs are "attached" to the parent PROC
        // of the OCC.
        addOccStateEffecterPdrs(io_repo, i_terminus_id, parent_proc);
        addOccStateSensorPdrs(io_repo, i_terminus_id, parent_proc);
    }
}

}

namespace PLDM
{

extern const std::array<fru_inventory_class, 2> fru_inventory_classes
{{
    { TARGETING::CLASS_CHIP, TARGETING::TYPE_PROC, ENTITY_TYPE_PROCESSOR_MODULE },
    { TARGETING::CLASS_LOGICAL_CARD, TARGETING::TYPE_DIMM, ENTITY_TYPE_DIMM }
}};

void addHostbootPdrs(pldm_pdr* const io_repo,
                     const terminus_id_t i_terminus_id)
{
    PLDM_INF(ENTER_MRK"addHostbootPdrs");

    addEntityAssociationAndFruRecordSetPdrs(io_repo, i_terminus_id);

    addOccStateControlPdrs(io_repo, i_terminus_id);

    PLDM_INF(EXIT_MRK"addHostbootPdrs");
}

}
