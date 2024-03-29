/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/extended/hb_pdrs.H $                     */
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

/* @file hb_pdrs.H
 *
 * Defines the interface for adding Hostboot's PDRs to a PDR repository.
 */

#ifndef HB_PDRS_H
#define HB_PDRS_H

#include <pldm/requests/pldm_pdr_requests.H>
#include <targeting/common/target.H>
#include <pldm/pldm_const.H>
#include <errl/errlentry.H>

namespace PLDM
{

/*
 * This table contains info on how to add each target type's info to the
 * assocation tree.
 */

struct fru_inventory_class
{
    TARGETING::ATTR_CLASS_type targetClass;
    TARGETING::TYPE targetType;
    entity_type entityType;
};

extern const std::array<fru_inventory_class, 2> fru_inventory_classes;

class PdrManager;

/* @brief Adds Hostboot's PDRs to the given PDR repository.
 *        These PDRs are:
 *        1) FRU Record Set PDRs
 *        2) Entity Association PDRs
 *        3) State sensor and effecter PDRs
 *
 * @param[in/out] io_pdrman       The PDR manager to add to.
 * @return errlHndl_t             Error if any, otherwise nullptr.
 */
errlHndl_t addHostbootPdrs(PdrManager& io_pdrman);

/* @brief Get the Entity Instance Number associated with target and entity_type
 * @param[in] i_target      Target associated with entity
 * @param[in] i_entity_type FRU entity type. A value of 0 means that PROC targets
 *                          will always be treated as processors rather than DCMs.
 * @return entity instance number
 */
uint16_t getEntityInstanceNumber(TARGETING::ConstTargetHandle_t i_target, uint16_t i_entity_type = 0);

}

#endif
