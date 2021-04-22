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

/* @brief Adds Hostboot's PDRs to the given PDR repository.
 *        These PDRs are:
 *        1) FRU Record Set PDRs, one for each DIMM and PROC
 *        2) Entity Association PDRs, one for each relationship between the
 *           DIMMs/PROCs and the Backplane.
 *
 * @param[in/out] io_repository        The repository to add the PDRs to. Must not
 *                                     be nullptr.
 * @return errlHndl_t    Error if any, otherwise nullptr.
 */
errlHndl_t addHostbootPdrs(pldm_pdr* io_repository);

}

#endif
