/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_spd_utils.C $ */
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

///
/// @file p10_spd_utils.C
/// @brief SPD utility functions
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#include <fapi2.H>

#include <lib/eff_config/p10_spd_utils.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <mss_generic_attribute_getters.H>

namespace mss
{
namespace spd
{
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
    fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>& io_vpd_info)
{
    const auto& l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_dimm);
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm);
    const uint8_t l_pos = mss::relative_pos<mss::mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm);

    uint8_t l_stack_type = 0;
    uint8_t l_dimm_type = 0;
    uint8_t l_type_encoding = 0;
    fapi2::ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_Type l_master_ranks_per_dimm = {0};
    fapi2::buffer<uint8_t> l_efd_dimm_type;

    if (!i_is_planar)
    {
        // Nothing to do here if we're not a planar system
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY( mss::attr::get_prim_stack_type(i_dimm, l_stack_type));
    FAPI_TRY( mss::attr::get_dimm_type(i_dimm, l_dimm_type));
    FAPI_TRY( mss::attr::get_num_master_ranks_per_dimm(l_port, l_master_ranks_per_dimm) );

    l_efd_dimm_type.writeBit<1>(l_stack_type == fapi2::ENUM_ATTR_MEM_EFF_PRIM_STACK_TYPE_3DS);
    l_efd_dimm_type.writeBit<2>(l_stack_type == fapi2::ENUM_ATTR_MEM_EFF_PRIM_STACK_TYPE_DDP_QDP);
    l_efd_dimm_type.writeBit<3>(l_master_ranks_per_dimm[l_pos] == fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_4R);
    l_type_encoding = (l_dimm_type == fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_RDIMM) ? 0b01 : 0b00;
    l_efd_dimm_type.insertFromRight<4, 2>(l_type_encoding);
    l_efd_dimm_type.writeBit<6>(l_pos == 1);
    l_efd_dimm_type.writeBit<7>(l_pos == 0);

    io_vpd_info.iv_dimm_count = mss::count_dimm(l_ocmb);
    io_vpd_info.iv_total_ranks_dimm0 = l_master_ranks_per_dimm[0];
    io_vpd_info.iv_total_ranks_dimm1 = l_master_ranks_per_dimm[1];
    io_vpd_info.iv_dimm_type = l_efd_dimm_type;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns ddr4
} // ns spd
} // ns mss
