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
#include "../../mctp/libmctp-hostlpc.h"

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
 * @param[in] i_entity       The entity associated with the OCC sensor.
 * @param[in] i_sensor_id    Will be used to fill in the sensor id field of the pdr
 */
errlHndl_t addOccStateSensorPdrs(pldm_pdr* const io_repo,
                                 const terminus_id_t i_terminus_id,
                                 const pldm_entity* const i_entity,
                                 const uint16_t i_sensor_id)
{
    errlHndl_t errl = nullptr;
    do{

    const state_sensor_possible_states states =
    {
        .state_set_id = PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS,
        .possible_states_size = 1, // size of possible_states
        .states =
        {
            enum_bit(PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_STOPPED)
            | enum_bit(PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_IN_SERVICE)
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
        .sensor_id = i_sensor_id,

        .entity_type = i_entity->entity_type,
        .entity_instance = i_entity->entity_instance_num,
        .container_id = i_entity->entity_container_id,

        .sensor_init = PLDM_NO_INIT,
        .sensor_auxiliary_names_pdr = false,
        .composite_sensor_count = 1
    };

    size_t actual_pdr_size = 0;

    const int rc = encode_state_sensor_pdr(pdr,
                                           encoded_pdr.size(),
                                           &states,
                                           sizeof(states),
                                           &actual_pdr_size);

    assert(rc == PLDM_SUCCESS,
           "Failed to encoded OCC state sensor PDR");

    pldm_pdr_add(io_repo, encoded_pdr.data(), actual_pdr_size,
                 PDR_AUTO_CALCULATE_RECORD_HANDLE,
                 PDR_IS_NOT_REMOTE);
    }while(0);

    return errl;
}

/* @brief Add the state effecter PDRs for OCC FRUs.
 *
 * @param[in/out] io_repo    The PDR repository to add PDRs to.
 * @param[in] i_terminus_id  The Host's terminus ID.
 * @param[in] i_entity       The entity associated with the OCC sensor.
 * @param[in] i_effecter_id  Will be used to fill in the effecter id field of the pdr
 */
errlHndl_t addOccStateEffecterPdrs(pldm_pdr* const io_repo,
                                   const terminus_id_t i_terminus_id,
                                   const pldm_entity* const i_entity,
                                   const uint16_t i_effecter_id)
{
    errlHndl_t errl = nullptr;
    do{

    const state_effecter_possible_states states =
    {
        .state_set_id = PLDM_STATE_SET_BOOT_RESTART_CAUSE,
        .possible_states_size = 1, // size of possible_states
        .states =
        {
            enum_bit(PLDM_STATE_SET_BOOT_RESTART_CAUSE_WARM_RESET)
            | enum_bit(PLDM_STATE_SET_BOOT_RESTART_CAUSE_HARD_RESET)
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
        .effecter_id = i_effecter_id,

        .entity_type = i_entity->entity_type,
        .entity_instance = i_entity->entity_instance_num,
        .container_id = i_entity->entity_container_id,

        .effecter_semantic_id = 0, // PLDM defines no semantic IDs yet
        .effecter_init = PLDM_NO_INIT,
        .has_description_pdr = false,
        .composite_effecter_count = 1
    };

    size_t actual_pdr_size = 0;

    const int rc = encode_state_effecter_pdr(pdr,
                                             encoded_pdr.size(),
                                             &states,
                                             sizeof(states),
                                             &actual_pdr_size);

    assert(rc == PLDM_SUCCESS,
           "Failed to encoded OCC state effecter PDR");

    pldm_pdr_add(io_repo, encoded_pdr.data(), actual_pdr_size,
                 PDR_AUTO_CALCULATE_RECORD_HANDLE,
                 PDR_IS_NOT_REMOTE);
    }while(0);

    return errl;
}

/* @brief Add the state effecter and sensor PDRs for OCC FRUs.
 *
 * @param[in/out] io_repo    The PDR repository to add PDRs to.
 */
errlHndl_t addOccStateControlPdrs(pldm_pdr* const io_repo)
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
        const auto parent_proc_rsi = getTargetFruRecordSetID(parent_proc);
        terminus_id_t terminus_id = 0;
        const bool entity_found =
              pldm_pdr_fru_record_set_find_by_rsi(io_repo,
                                                  parent_proc_rsi,
                                                  &terminus_id,
                                                  &entity.entity_type,
                                                  &entity.entity_instance_num,
                                                  &entity.entity_container_id);

        if (!entity_found)
        {
            PLDM_ERR("addOccStateControlPdrs> Unable to find an entity matching RSI 0x%04x for HUID 0x%08x",
                      parent_proc_rsi, get_huid(parent_proc));
            /*@
            * @errortype  ERRL_SEV_UNRECOVERABLE
            * @moduleid   MOD_ADD_OCC_PDRS
            * @reasoncode RC_NO_ENTITY_FROM_RSID
            * @userdata1  record set id of occ's parent processor
            * @userdata2  HUID of target
            * @devdesc    Unable to find the entity associated with this RSI
            * @custdesc   A software error occurred during system boot
            */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                            MOD_ADD_OCC_PDRS,
                                            RC_NO_ENTITY_FROM_RSID,
                                            parent_proc_rsi,
                                            get_huid(parent_proc),
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Using the ORDINAL_ID of the target will let us associate with the
        // correct target when we send a PlatformEventMessage with the new state
        // or we receive a SetStateEffecterStates command later
        const uint16_t proc_ordinal_id = static_cast<uint16_t>(parent_proc->getAttr<ATTR_ORDINAL_ID>());

        // The OCC state sensor/effecter PDRs are "attached" to the parent PROC
        // of the OCC.
        errl = addOccStateEffecterPdrs(io_repo, terminus_id, &entity, proc_ordinal_id);
        if(errl)
        {
            PLDM_ERR("addOccStateControlPdrs> Error occurred adding occ state effecter PDR for HUID 0x%08X",
                     get_huid(parent_proc));
            break;
        }
        errl = addOccStateSensorPdrs(io_repo, terminus_id, &entity, proc_ordinal_id);
        if(errl)
        {
            PLDM_ERR("addOccStateControlPdrs> Error occurred adding occ state sensor PDR for HUID 0x%08X",
                     get_huid(parent_proc));
            break;
        }
    }

    return errl;
}

/**
 * @brief Populates the input Terminus Locator PDR with the correct data for
 *        if to be added to a PDR repository.
 *
 * @param[in] i_pdr the input PDR pointer to be populated
 */
void generateTerminusLocatorPDR(pldm_terminus_locator_pdr* const i_pdr)
{
    const uint8_t DEFAULT_CONTAINER_ID = 0;
    i_pdr->hdr.record_handle = 0; // record_handle will be generated for us
    i_pdr->hdr.version = 1;
    i_pdr->hdr.type = PLDM_TERMINUS_LOCATOR_PDR;
    i_pdr->hdr.record_change_num = 0;
    i_pdr->hdr.length = htole16(sizeof(pldm_terminus_locator_pdr) - sizeof(pldm_pdr_hdr));
    i_pdr->terminus_handle = htole16(PLDM::thePdrManager().hostbootTerminusId());
    i_pdr->validity = PLDM_TL_PDR_VALID;
    i_pdr->tid = PLDM::thePdrManager().hostbootTerminusId();
    i_pdr->container_id = DEFAULT_CONTAINER_ID;
    i_pdr->terminus_locator_type = PLDM_TERMINUS_LOCATOR_TYPE_MCTP_EID;
    i_pdr->terminus_locator_value_size = sizeof(pldm_terminus_locator_type_mctp_eid);
    auto l_locatorValue = reinterpret_cast<pldm_terminus_locator_type_mctp_eid*>(i_pdr->terminus_locator_value);
    l_locatorValue->eid = HOST_EID;
}

/**
 * @brief Adds a Terminus Locator PDR to the input PDR repository
 *
 * @param[in/out] io_repo the PDR repository to add the Terminus Locator PDR to
 */
void addTerminusLocatorPDR(pldm_pdr* const io_repo)
{
    pldm_terminus_locator_pdr l_pdr;

    generateTerminusLocatorPDR(&l_pdr);
    pldm_pdr_add(io_repo, reinterpret_cast<const uint8_t*>(&l_pdr),
                 sizeof(l_pdr),
                 PDR_AUTO_CALCULATE_RECORD_HANDLE,
                 PDR_IS_NOT_REMOTE);
}

}

namespace PLDM
{

extern const std::array<fru_inventory_class, 2> fru_inventory_classes
{{
    { TARGETING::CLASS_CHIP, TARGETING::TYPE_PROC, ENTITY_TYPE_PROCESSOR_MODULE },
    { TARGETING::CLASS_LOGICAL_CARD, TARGETING::TYPE_DIMM, ENTITY_TYPE_DIMM }
}};

errlHndl_t addHostbootPdrs(pldm_pdr* const io_repo)
{
    PLDM_ENTER("addHostbootPdrs");

    errlHndl_t errl = nullptr;

    addEntityAssociationAndFruRecordSetPdrs(io_repo,
                                            thePdrManager().hostbootTerminusId());

    errl = addOccStateControlPdrs(io_repo);

    addTerminusLocatorPDR(io_repo);

    PLDM_EXIT("addHostbootPdrs completed %s error", errl ? "with" : "without");

    return errl;
}

}
