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

// Standard library
#include <memory>

// PLDM
#include <pldm/extended/hb_pdrs.H>
#include "../extern/pdr.h"

// Targeting
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/predicates/predicatehwas.H>

using namespace TARGETING;

// These are Entity Types used in Entity Association PDRs
enum entity_type : uint8_t
{
    // These values are from Table 15 in DSP0249 v1.1.0
    ENTITY_TYPE_BACKPLANE = 64,
    ENTITY_TYPE_DIMM = 66,
    ENTITY_TYPE_PROCESSOR_MODULE = 67
};

namespace PLDM
{

void addHostbootPdrs(pldm_pdr* const io_repo,
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

    /* Now we add all the children of the backplane to the tree.
     *
     * This table contains info on how to add each target type's info to the
     * assocation tree.
     */
    struct
    {
        ATTR_CLASS_type targetClass;
        TARGETING::TYPE targetType;
        entity_type entityType;
    }
    entities[] =
    {
        { CLASS_CHIP,         TYPE_PROC, ENTITY_TYPE_PROCESSOR_MODULE },
        { CLASS_LOGICAL_CARD, TYPE_DIMM, ENTITY_TYPE_DIMM }
    };

    uint16_t next_fru_record_set_id = 0;

    for (const auto entity : entities)
    {
        TargetHandleList targets;

        {
            PredicateHwas l_predPres;
            l_predPres.present(true);
            PredicateCTM l_CtmFilter(entity.targetClass, entity.targetType);
            PredicatePostfixExpr l_present;
            l_present.push(&l_CtmFilter).push(&l_predPres).And();
            TargetRangeFilter l_presTargetList(targetService().begin(),
                                               targetService().end(),
                                               &l_present);
            for ( ; l_presTargetList; ++l_presTargetList)
            {
                targets.push_back(*l_presTargetList);
            }
        }

        for (size_t i = 0; i < targets.size(); ++i)
        {
            pldm_entity pldmEntity
            {
                // The entity_instance_num and entity_container_id members of
                // this struct are filled out by
                // pldm_entity_association_tree_add below
                .entity_type = entity.entityType
            };

            // Add the Entity Assocation record to the tree (will be converted
            // to PDRs and stored in the repo at the end of this function)
            pldm_entity_association_tree_add(enttree.get(),
                                             &pldmEntity,
                                             backplane_node,
                                             PLDM_ENTITY_ASSOCIAION_PHYSICAL);

            ++next_fru_record_set_id;

            // Add the FRU record set PDR to the repo
            pldm_pdr_add_fru_record_set(io_repo,
                                        i_terminus_id,
                                        next_fru_record_set_id,
                                        pldmEntity.entity_type,
                                        pldmEntity.entity_instance_num,
                                        pldmEntity.entity_container_id);
        }
    }

    /* Serialize the tree into the PDR repository. */

    pldm_entity_association_pdr_add(enttree.get(), io_repo);
}

}
