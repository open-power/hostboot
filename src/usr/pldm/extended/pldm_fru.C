/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pldm_fru.C $                            */
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

/* @file pldm_fru.C
 *
 * @brief Implementation of FRU-related utilities.
 */

#include <stdint.h>

#include <targeting/common/target.H>
#include <pldm/extended/pldm_fru.H>

#include <targeting/common/utilFilter.H>

using namespace PLDM;
using namespace TARGETING;

constexpr int target_type_bits  = 7;
constexpr int ordinal_id_bits   = 9;

static_assert(TYPE_LAST_IN_RANGE <= (1 << target_type_bits),
    "Cannot encode all target types in the given number of bits");

union encoded_rsid_t
{
    struct
    {
        TARGETING::TYPE target_type : 7;
        ATTR_ORDINAL_ID_type ordinal_id : 9;
    } __attribute__((packed));

    uint16_t packed_rsid;
};

static_assert(sizeof(encoded_rsid_t) == sizeof(PLDM::fru_record_set_id_t),
              "Encoded RSID union not packed");


PLDM::fru_record_set_id_t PLDM::getTargetFruRecordSetID(const Target* const i_target, TYPE i_target_type)
{
    const auto l_target_type = (i_target_type == TYPE_NA) ? i_target->getAttr<ATTR_TYPE>() : i_target_type;
    const auto l_ordinal_id = i_target->getAttr<ATTR_ORDINAL_ID>();

    assert(l_target_type < (1 << target_type_bits),
           "Target type for FRU Record Set ID is out of range (HUID 0x%08x)",
           get_huid(i_target));

    assert(l_ordinal_id < (1 << ordinal_id_bits),
           "Ordinal ID for FRU Record Set ID is out of range (HUID 0x%08x) - max size: 0x%08x",
           get_huid(i_target), (1 << ordinal_id_bits)-1);

    encoded_rsid_t rsid = { };

    rsid.target_type = l_target_type;
    rsid.ordinal_id = l_ordinal_id;

    return rsid.packed_rsid;
}



Target* PLDM::getTargetFromHostbootFruRecordSetID(const fru_record_set_id_t i_rsid)
{
    encoded_rsid_t encoded_rsid = { .packed_rsid = i_rsid };

    Target* result_target = nullptr;
    do {
        // no target for DCMs
        if (encoded_rsid.target_type == TYPE_DCM)
        {
            break;
        }

        TARGETING::TargetHandleList target_list;
        getClassResources(target_list,
                          CLASS_NA,
                          encoded_rsid.target_type,
                          UTIL_FILTER_PRESENT);

        for (Target* const target : target_list)
        {
            if (target->getAttr<ATTR_ORDINAL_ID>() == encoded_rsid.ordinal_id)
            {
                result_target = target;
                break;
            }
        }
    } while (0);

    return result_target;
}

