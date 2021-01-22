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

enum encoded_target_class_t
{
    ENCODED_CLASS_CHIP,          // PROC targets
    ENCODED_CLASS_LOGICAL_CARD,  // DIMM
    ENCODED_END                  // sentinel
};

constexpr int target_class_bits = 3;
constexpr int target_type_bits = 7;
constexpr int position_id_bits = 6;

static_assert(ENCODED_END <= (1 << target_class_bits),
              "Not enough bits in encoded rsid to encoded target class");

static_assert(TYPE_LAST_IN_RANGE <= (1 << target_type_bits),
              "Too many possible CLASS attribuet values to encode in 4 bits");

struct target_class_encoding
{
    ATTR_CLASS_type target_class;
    encoded_target_class_t encoded_class;
};

static const target_class_encoding encoded_target_classes[] =
{
    { CLASS_CHIP, ENCODED_CLASS_CHIP },
    { CLASS_LOGICAL_CARD, ENCODED_CLASS_LOGICAL_CARD },
};

static encoded_target_class_t encodeTargetClass(const TARGETING::CLASS i_class)
{
    const auto it = std::find_if(std::begin(encoded_target_classes),
                                 std::end(encoded_target_classes),
                                 [i_class](const target_class_encoding& encoding)
                                 { return encoding.target_class == i_class; });

    assert(it != std::end(encoded_target_classes),
           "Cannot ENCODE target class %d for Hostboot FRU record set ID",
           i_class);

    return it->encoded_class;
}

static ATTR_CLASS_type decodeTargetClass(const encoded_target_class_t i_encoded_class)
{
    const auto it = std::find_if(std::begin(encoded_target_classes),
                                 std::end(encoded_target_classes),
                                 [i_encoded_class](const target_class_encoding& encoding)
                                 { return encoding.encoded_class == i_encoded_class; });

    assert(it != std::end(encoded_target_classes),
           "Cannot DECODE target class %d for Hostboot FRU record set ID",
           i_encoded_class);

    return it->target_class;
}

union encoded_rsid_t
{
    struct
    {
        encoded_target_class_t encoded_class : 3;
        TARGETING::TYPE target_type : 7;
        ATTR_POSITION_type position_id : 6;
    } __attribute__((packed));

    uint16_t packed_rsid;
};

static_assert(sizeof(encoded_rsid_t) == sizeof(PLDM::fru_record_set_id_t),
              "Encoded RSID union not packed");

PLDM::fru_record_set_id_t PLDM::getTargetFruRecordSetID(const Target* const i_target)
{
    const auto target_class = i_target->getAttr<ATTR_CLASS>();
    const auto target_type = i_target->getAttr<ATTR_TYPE>();
    const auto position_id = i_target->getAttr<ATTR_POSITION>();

    assert(target_type <= (1 << target_type_bits),
           "Target type for FRU Record Set ID is out of range (HUID 0x%08x)",
           get_huid(i_target));
    assert(position_id <= (1 << position_id_bits),
           "Position ID for FRU Record Set ID is out of range (HUID 0x%08x)",
           get_huid(i_target));

    encoded_rsid_t rsid = { };

    rsid.encoded_class = encodeTargetClass(target_class);
    rsid.target_type = target_type;
    rsid.position_id = position_id;

    return rsid.packed_rsid;
}

Target* PLDM::getTargetFromHostbootFruRecordSetID(const fru_record_set_id_t i_rsid)
{
    encoded_rsid_t encoded_rsid = { .packed_rsid = i_rsid };

    const ATTR_CLASS_type target_class =  decodeTargetClass(encoded_rsid.encoded_class);

    TARGETING::TargetHandleList target_list;
    getClassResources(target_list,
                      target_class,
                      encoded_rsid.target_type,
                      UTIL_FILTER_PRESENT);

    Target* result_target = nullptr;

    for (Target* const target : target_list)
    {
        if (target->getAttr<ATTR_POSITION>() == encoded_rsid.position_id)
        {
            result_target = target;
            break;
        }
    }

    return result_target;
}
