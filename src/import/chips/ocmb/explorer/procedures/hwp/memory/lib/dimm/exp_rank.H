/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/exp_rank.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file exp_rank.H
/// @brief Explorer rank definitions
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_EXP_RANK_H_
#define _MSS_EXP_RANK_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <lib/shared/exp_consts.H>
#include <lib/exp_attribute_accessors_manual.H>

namespace mss
{
namespace rank
{

///
/// @brief Rank traits for explorer
///
template <>
class rankTraits<mss::mc_type::EXPLORER>
{
    public:
        // Number of DIMM's per port, based upon our attribute structure
        // Hypothetically, 2 DIMM's per port could be supported but only one is used at this time
        static constexpr uint8_t MAX_DIMMS_PER_PORT = 2;

        // Maximum number of ranks supported on each DIMM
        static constexpr uint8_t MAX_RANKS_PER_DIMM = 4;

        // The cosmetic indexing jump used to go from DIMM0 to DIMM1
        static constexpr uint8_t RANK_INDEX_STEP = 4;

        // Note! a configuration of 2 4-rank dimms is not possible.
        // In this hypothetical scenario, the value for phy-rank would not
        // be valid / does not apply, as there will be some rollover.
        static constexpr uint8_t PHY_RANK_INDEX_STEP = 2;

        static constexpr fapi2::TargetType MEM_PORT_TARGET_TYPE = fapi2::TARGET_TYPE_MEM_PORT;
};

///
/// @brief Works around any issues with swizzle on the PHY ranks - explorer/DIMM
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_phy_rank the PHY rank which might need to be updated
/// @return FAPI2_RC_SUCCESS iff success
///
template <>
inline fapi2::ReturnCode phy_rank_swizzle_workaround<mss::mc_type::EXPLORER>(const
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint8_t& io_phy_rank)
{
    bool l_is_quad_encoded_cs = false;
    FAPI_TRY(is_quad_encoded_cs(i_target, l_is_quad_encoded_cs));

    // Note: ranks 1/2 are swapped in the quad encoded mapping compared to the JEDEC perspective
    // The reason for this is that there is a bug in the explorer logic documented in JIRA355
    // This bug swaps the signals on the DFI interface for ranks 1/2
    // So, IBM's memory controller perspective rank 2 accesses JEDEC rank 1
    // While IBM's memory controller perspective rank 1 accesses JEDEC rank 2
    // The decision was made to swap these encodings
    // This way any row repair/CCS requests will match the memory controller rank called out in the IBM register
    // Other CCS relevant information (ODT signals, etc) should be handled via the attributes being encoded in the IBM perspective
    // We handle this fix in the rank API here by swapping PHY rank 1/2
    if(l_is_quad_encoded_cs)
    {
        // If we're rank 1, swap to rank 2
        if(io_phy_rank == 1)
        {
            io_phy_rank = 2;
        }
        // If we're rank 2, swap to rank 1
        else if(io_phy_rank == 2)
        {
            io_phy_rank = 1;
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Works around any issues with swizzle on the PHY ranks - explorer/MEM_PORT specialization
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_phy_rank the PHY rank which might need to be updated
/// @return FAPI2_RC_SUCCESS iff success
///
template <>
inline fapi2::ReturnCode phy_rank_swizzle_workaround<mss::mc_type::EXPLORER>(const
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, uint8_t& io_phy_rank)
{
    bool l_is_quad_encoded_cs = false;
    FAPI_TRY(is_quad_encoded_cs(i_target, l_is_quad_encoded_cs));

    // Note: ranks 1/2 are swapped in the quad encoded mapping compared to the JEDEC perspective
    // The reason for this is that there is a bug in the explorer logic documented in JIRA355
    // This bug swaps the signals on the DFI interface for ranks 1/2
    // So, IBM's memory controller perspective rank 2 accesses JEDEC rank 1
    // While IBM's memory controller perspective rank 1 accesses JEDEC rank 2
    // The decision was made to swap these encodings
    // This way any row repair/CCS requests will match the memory controller rank called out in the IBM register
    // Other CCS relevant information (ODT signals, etc) should be handled via the attributes being encoded in the IBM perspective
    // We handle this fix in the rank API here by swapping PHY rank 1/2
    if(l_is_quad_encoded_cs)
    {
        // If we're rank 1, swap to rank 2
        if(io_phy_rank == 1)
        {
            io_phy_rank = 2;
        }
        // If we're rank 2, swap to rank 1
        else if(io_phy_rank == 2)
        {
            io_phy_rank = 1;
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}

} // namespace rank
} // namespace mss
#endif
