/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_field.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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

///
/// @file spd_field.H
/// @brief SPD data fields
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_FIELD_H_
#define _MSS_SPD_FIELD_H_

#include <cstdint>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_field.H>

namespace mss
{
namespace spd
{

///
/// @class init_fields
/// @brief Initial fields needed to know how to parse the SPD
/// @note These are preliminary fields that need to be independently
/// decoded from any specific DRAM generation SPEC (e.g. SPD factory)
///
class init_fields
{
    private:

        enum
        {
            // Byte 1
            REVISION_START = 0,
            REVISION_LEN = 8,

            // Byte 2
            DEVICE_TYPE_START = 0,
            DEVICE_TYPE_LEN = 8,

            // Byte 3
            HYBRID_START = 0,
            HYBRID_LEN = 1,
            HYBRID_MEDIA_START = 1,
            HYBRID_MEDIA_LEN = 3,
            BASE_MODULE_START = 4,
            BASE_MODULE_LEN = 4,

            // Byte 130
            REF_RAW_CARD_START = 0,
            REF_RAW_CARD_LEN = 8,
        };

    public:

        // 1st field: Byte number
        // 2nd field: Start bit
        // 3rd field: Bit length
        static constexpr mss::field_t<mss::endian::LITTLE> REVISION{1, REVISION_START, REVISION_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DEVICE_TYPE{2, DEVICE_TYPE_START, DEVICE_TYPE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BASE_MODULE{3, BASE_MODULE_START, BASE_MODULE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> HYBRID{3, HYBRID_START, HYBRID_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> HYBRID_MEDIA{3, HYBRID_MEDIA_START, HYBRID_MEDIA_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> REF_RAW_CARD{130, REF_RAW_CARD_START, REF_RAW_CARD_LEN};
};

///
/// @class fields
/// @brief Collection of SPD fields
/// @tparam D DRAM device type (e.g. DDR4)
/// @tparam S SPD parameter (e.g. RDIMM_MODULE, NVDIMM_MODULE)
///
template <device_type D, module_params S>
class fields;

}// spd
}// mss

#endif // _MSS_SPD_FIELD_H_
