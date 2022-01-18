/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_fields_ddr5.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

// EKB-Mirror-To: hostboot
///
/// @file spd_fields_ddr5.H
/// @brief DDR5 SPD data fields
///

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_FIELDS_DDR5_H_
#define _MSS_SPD_FIELDS_DDR5_H_

#include <generic/memory/lib/spd/spd_field.H>

namespace mss
{
namespace spd
{

///
/// @class fields
/// @brief DDR5 SPD General Section fields
/// @note DDR5, BASE_CNFG specialization
///
/// @note Since these fields are used as non-type template params,
/// they need have external linkage. Currently C++11 can achieve this
/// by making them static constexpr member variables.
///
template <>
class fields<DDR5, BASE_CNFG>
{
    private:

        enum
        {
            // Byte 3
            HYBRID_START = 0,
            HYBRID_LEN = 1,
            HYBRID_MEDIA_START = 1,
            HYBRID_MEDIA_LEN = 3,
            BASE_MODULE_START = 4,
            BASE_MODULE_LEN = 4,

            // Byte 4
            DIE_PER_PACKAGE_START = 0,
            DIE_PER_PACKAGE_LEN = 3,
            DENSITY_PER_DIE_START = 3,
            DENSITY_PER_DIE_LEN = 5,

            // Byte 234
            RANK_MIX_START = 1,
            RANK_MIX_LEN = 1,
            PACKAGE_RANKS_PER_CHANNEL_START = 2,
            PACKAGE_RANKS_PER_CHANNEL_LEN = 3,
        };

    public:

        // 1st field: Byte number
        // 2nd field: Start bit
        // 3rd field: Bit length
        static constexpr mss::field_t<mss::endian::LITTLE> HYBRID{3, HYBRID_START, HYBRID_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> HYBRID_MEDIA{3, HYBRID_MEDIA_START, HYBRID_MEDIA_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BASE_MODULE{3, BASE_MODULE_START, BASE_MODULE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DIE_PER_PACKAGE{4, DIE_PER_PACKAGE_START, DIE_PER_PACKAGE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DENSITY_PER_DIE{4, DENSITY_PER_DIE_START, DENSITY_PER_DIE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> RANK_MIX{234, RANK_MIX_START, RANK_MIX_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> PACKAGE_RANKS_PER_CHANNEL{234, PACKAGE_RANKS_PER_CHANNEL_START, PACKAGE_RANKS_PER_CHANNEL_LEN};
};

}// spd
}// mss

#endif // _MSS_SPD_FIELDS_DDR5_H_
