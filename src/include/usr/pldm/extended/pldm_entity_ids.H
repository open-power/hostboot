/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/extended/pldm_entity_ids.H $             */
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

/* @file pldm_entity_ids.H
 *
 * @brief API for working with PLDM Entity IDs
 */

#ifndef PLDM_ENTITY_IDS_H
#define PLDM_ENTITY_IDS_H

#include <errl/errlentry.H>

namespace PLDM
{

/* @brief Update the PLDM Entity ID attributes of all PLDM-aware targets (PROC,
 *        DIMM, etc.)
 *
 * @return errlHndl_t  Error if any, otherwise nullptr.
 */

errlHndl_t assignTargetEntityIds();

}

#endif
