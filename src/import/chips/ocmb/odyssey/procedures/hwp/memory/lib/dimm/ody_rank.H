/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/dimm/ody_rank.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file ody_rank.H
/// @brief Odyssey rank definitions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _ODY_RANK_H_
#define _ODY_RANK_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/mss_rank.H>

namespace mss
{
namespace rank
{

///
/// @brief Rank traits for Odyssey
///
template <>
class rankTraits<mss::mc_type::ODYSSEY>
{
    public:
        // Number of DIMM's per port, based upon our attribute structure
        // Technically, we only have one physical DIMM per port for Odyssey,
        // but our attributes are holdovers, so this value is a 2
        static constexpr uint8_t MAX_DIMMS_PER_PORT = 2;

        // Odyssey only supports 2 ranks on each DIMM
        static constexpr uint8_t MAX_RANKS_PER_DIMM = 2;

        // Number of ranks between DIMM0 and DIMM1 for our calculations
        // We want this to be 4 to be inline w/ our other MC's (Nimbus/Explorer)
        // However, we can really only have 2 ranks per DIMM, but this should be ok as it's cosmetic
        static constexpr uint8_t RANK_INDEX_STEP = 4;

        // The indexing from DIMM0 to DIMM1 (if we ever support that which is not in the plan at this time)
        static constexpr uint8_t PHY_RANK_INDEX_STEP = 2;

        static constexpr fapi2::TargetType MEM_PORT_TARGET_TYPE = fapi2::TARGET_TYPE_MEM_PORT;
};

///
/// @brief Works around any issues with swizzle on the PHY ranks - Odyssey/DIMM
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_phy_rank the PHY rank which might need to be updated
/// @return FAPI2_RC_SUCCESS iff success
///
template <>
inline fapi2::ReturnCode phy_rank_swizzle_workaround<mss::mc_type::ODYSSEY>(const
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint8_t& io_phy_rank)
{
    // No workaround needed at this time
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Works around any issues with swizzle on the PHY ranks - Odyssey/MEM_PORT specialization
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_phy_rank the PHY rank which might need to be updated
/// @return FAPI2_RC_SUCCESS iff success
///
template <>
inline fapi2::ReturnCode phy_rank_swizzle_workaround<mss::mc_type::ODYSSEY>(const
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, uint8_t& io_phy_rank)
{
    // No workaround needed at this time
    return fapi2::FAPI2_RC_SUCCESS;
}

} // namespace rank
} // namespace mss
#endif
