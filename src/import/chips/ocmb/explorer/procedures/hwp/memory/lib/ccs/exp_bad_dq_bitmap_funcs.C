/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ccs/exp_bad_dq_bitmap_funcs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
/// @file exp_bad_dq_bitmap_funcs.C
/// @brief Functions that access the Bad DQ Bitmap.
///
/// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB:CI
/// EKB-Mirror-To: hostboot
///

#include <fapi2.H>
#include <lib/shared/exp_defaults.H>
#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_rank.H>

#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/mss_generic_attribute_setters.H>
#include <lib/ccs/exp_bad_dq_bitmap_funcs.H>

namespace mss
{
namespace exp
{

///
/// @brief Row Repair Utility function that gets the Bad DQ Bitmap.
/// @param[in]  i_rank_info Rank info to get bitmap
/// @param[in,out] io_data Reference to data where Bad DQ bitmap is copied to
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode get_bad_dq_bitmap( const mss::rank::info<>& i_rank_info,
                                     uint8_t io_data[BAD_DQ_BYTE_COUNT])
{
    using RT = mss::rank::rankTraits<mss::mc_type::EXPLORER>;

    // Get the Bad DQ bitmap by querying ATTR_BAD_DQ_BITMAP.
    // Use a heap based array to avoid large stack alloc
    uint8_t l_dqBitmap[RT::MAX_RANKS_PER_DIMM][BAD_DQ_BYTE_COUNT] = {};

    FAPI_TRY( mss::attr::get_bad_dq_bitmap(i_rank_info.get_dimm_target(), l_dqBitmap) );

    // Write contents of DQ bitmap for specific rank to io_data.
    std::copy(std::begin(l_dqBitmap[i_rank_info.get_dimm_rank()]), std::end(l_dqBitmap[i_rank_info.get_dimm_rank()]),
              io_data);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Row Repair Utility function that sets the Bad DQ Bitmap.
/// @param[in] i_rank_info Rank info to get bitmap
/// @param[in] i_data Reference to data where Bad DQ bitmap is copied to
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode set_bad_dq_bitmap( const mss::rank::info<>& i_rank_info,
                                     const uint8_t i_data[BAD_DQ_BYTE_COUNT])
{
    using RT = mss::rank::rankTraits<mss::mc_type::EXPLORER>;
    const auto& l_dimm = i_rank_info.get_dimm_target();

    // Get the Bad DQ bitmap by querying ATTR_BAD_DQ_BITMAP.
    // Use a heap based array to avoid large stack alloc
    uint8_t l_dqBitmap[RT::MAX_RANKS_PER_DIMM][BAD_DQ_BYTE_COUNT] = {};

    FAPI_TRY( mss::attr::get_bad_dq_bitmap(l_dimm, l_dqBitmap) );

    // Add the rank bitmap to the DIMM bitmap and write the bitmap
    std::copy(i_data, i_data + BAD_DQ_BYTE_COUNT, std::begin(l_dqBitmap[i_rank_info.get_dimm_rank()]));

    FAPI_TRY( mss::attr::set_bad_dq_bitmap(l_dimm, l_dqBitmap) );

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace exp
} // namespace mss
