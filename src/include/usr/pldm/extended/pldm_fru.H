/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/extended/pldm_fru.H $                    */
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

#ifndef PLDM_FRU_H__
#define PLDM_FRU_H__

#include <stdint.h>

/* @file pldm_fru.H
 *
 * @brief Constants and types related to FRU records.
 */

namespace TARGETING
{
class Target;
}

namespace PLDM
{

using fru_record_set_id_t = uint16_t;

// currently we support version 1.0 of fru table
constexpr uint8_t SUPPORTED_FRU_VERSION_MAJOR = 1;
constexpr uint8_t SUPPORTED_FRU_VERSION_MINOR = 0;

/* @brief Gets a Target's FRU Record Set ID.
 *
 * @note The Record Set ID is encoded as the target's Targeting type in the
 *       most-significant octet, and the target's ordinal ID in the
 *       least-significant octet of the 16-bit RSID.
 *
 * @param[in] i_target  The target to get the FRU RSID for.
 * @param[in] i_target_type Optional target type (used if i_target's type doesn't match)
 * @return fru_record_set_id_t  The encoded FRU Record Set ID.
 */
fru_record_set_id_t getTargetFruRecordSetID(const TARGETING::Target* i_target, TARGETING::TYPE i_target_type = TARGETING::TYPE_NA);

/* @brief Returns a Target handle from a given FRU Record Set ID.
 *        The RSID must have been encoded by getTargetFruRecordSetID.
 *
 * @param[in] i_rsid  The RSID to use to find the Target
 * @return Target*    Handle to the Target with the given RSID,
 *                    or nullptr if none match
 */
TARGETING::Target* getTargetFromHostbootFruRecordSetID(fru_record_set_id_t i_rsid);



}

#endif
