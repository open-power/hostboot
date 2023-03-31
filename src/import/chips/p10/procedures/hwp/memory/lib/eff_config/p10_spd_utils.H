/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_spd_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file p10_spd_utils.H
/// @brief SPD utility functions
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#ifndef _P10_SPD_UTILS_H_
#define _P10_SPD_UTILS_H_

#include <fapi2.H>
#include <vpd_access.H>
#include <lib/dimm/exp_rank.H>
#include <lib/dimm/ody_rank.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{
namespace spd
{

///
/// @brief A lightweight structure to pass around the necessary rank information
///
struct rank_data
{
    uint8_t iv_efd_rank;
    uint8_t iv_dimm_rank;
};

///
/// @brief Helper to to run ranks_on_dimm on the correct mc rank info using dram gen attr
/// @tparam MC the memory controller type
/// @param[in] i_dimm DIMM target
/// @param[out] o_ranks vector of ranks information
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type MC>
fapi2::ReturnCode get_efd_ranks_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                                       std::vector<rank_data>& o_efd_ranks)
{
    // Clear the vector before using
    o_efd_ranks.clear();

    // Create l_rank_infos using the dram gen attr
    std::vector<mss::rank::info<MC>> l_rank_infos;
    FAPI_TRY(mss::rank::ranks_on_dimm(i_dimm, l_rank_infos));

    // Loop through and assemble the ranks
    for(const auto& l_rank_info : l_rank_infos)
    {
        const rank_data l_rank_data = {l_rank_info.get_efd_rank(), l_rank_info.get_dimm_rank()};
        o_efd_ranks.push_back(l_rank_data);
    }

fapi_try_exit:
    return fapi2::current_err;
}
namespace ddr4
{

///
/// @brief Helper to fill in planar EFD lookup info in VPDInfo (byte 7 in DDR4 DDIMM EFD)
/// @param[in] i_dimm DIMM target
/// @param[in] i_is_planar value of ATTR_MEM_MRW_IS_PLANAR
/// @param[in,out] io_vpd_info VPDInfo to be used for EFD lookup
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode add_planar_efd_info(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const uint8_t i_is_planar,
    fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>& io_vpd_info);

} // ns ddr4
} // ns spd
} // ns mss

#endif
