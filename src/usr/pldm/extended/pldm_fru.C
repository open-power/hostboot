/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pldm_fru.C $                            */
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

/* @file pldm_fru.C
 *
 * @brief Implementation of FRU-related utilities.
 */

#include <stdint.h>

#include <targeting/common/target.H>
#include <pldm/extended/pldm_fru.H>

using namespace TARGETING;

PLDM::fru_record_set_id_t PLDM::getTargetFruRecordSetID(const Target* const i_target)
{
    const auto targetType = i_target->getAttr<ATTR_TYPE>();
    const auto ordinal = i_target->getAttr<ATTR_ORDINAL_ID>();

    assert(targetType <= UINT8_MAX,
           "Target type for FRU Record Set ID is out of range (HUID 0x%08x)",
           get_huid(i_target));
    assert(ordinal <= UINT8_MAX,
           "Ordinal ID for FRU Record Set ID is out of range (HUID 0x%08x)",
           get_huid(i_target));

    return (targetType << 8) | ordinal;
}
