/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/wr_vref_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file wr_vref_workarounds.C
/// @brief Workarounds for the WR VREF calibration logic
/// Workarounds are very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <lib/workarounds/wr_vref_workarounds.H>
#include <lib/phy/dp16.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <lib/dimm/ddr4/nvdimm_utils.H>
#include <lib/dimm/ddr4/latch_wr_vref_nimbus.H>
#include <lib/workarounds/dp16_workarounds.H>

namespace mss
{

namespace workarounds
{

namespace wr_vref
{

///
/// @brief Executes WR VREF workarounds
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rp - the rank pair to execute the override on
/// @param[in] i_wr_vref_enabled - true if WR VREF is enabled
/// @param[out] o_vrefdq_train_range - training range value
/// @param[out] o_vrefdq_train_value - training value value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
// TODO RTC:166422 update training code to set cal step enable and consume it everywhere locally
fapi2::ReturnCode execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                           const uint64_t i_rp,
                           const bool i_wr_vref_enabled,
                           uint8_t& o_vrefdq_train_range,
                           uint8_t& o_vrefdq_train_value )
{
    // Skip running WR VREF workarounds if:
    // 1) the chip does not need to have the workaround run
    // 2) WR VREF has not been requested in the calibration steps
    if ((! mss::chip_ec_feature_mss_wr_vref(i_target)) || (!i_wr_vref_enabled))
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(mss::workarounds::dp16::wr_vref::error_dram23(i_target));
    FAPI_TRY(mss::workarounds::dp16::wr_vref::setup_values(i_target, i_rp, o_vrefdq_train_range, o_vrefdq_train_value));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes the nvdimm workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode nvdimm_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                     const uint64_t i_rp,
                                     const uint8_t i_abort_on_error )
{
    FAPI_INF("nvdimm_workaround() on %s RP%lu ", mss::c_str(i_target), i_rp);

    // traits definition
    typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;
    constexpr uint64_t DRAMS_PER_RP = 18;
    std::vector<std::pair<uint64_t, uint64_t>> l_wr_vref_regs;
    std::vector<std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t>>> l_wr_vref_regs_values;
    std::vector<uint64_t> l_composite_values;

    // Get the wr_vref regs by rp and then suck out all the data
    FAPI_TRY(mss::dp16::wr_vref::get_wr_vref_regs_by_rp(i_rp, l_wr_vref_regs));
    FAPI_TRY(mss::scom_suckah(i_target, l_wr_vref_regs, l_wr_vref_regs_values));

    for (const auto l_wr_vref_pair : l_wr_vref_regs_values)
    {
        // Get the composite values from the first reg. We don't really care which value belongs to which
        // dram here since we only need the median value
        mss::nvdimm::wr_vref::get_wr_vref_composite_value_helper(l_wr_vref_pair.first, l_composite_values);

        // Abort if we have enough...
        // This excludes the non-existent on DP4
        if (l_composite_values.size() == DRAMS_PER_RP)
        {
            break;
        }

        // Repeat for the second reg
        mss::nvdimm::wr_vref::get_wr_vref_composite_value_helper(l_wr_vref_pair.second, l_composite_values);
    }

    // Get the median
    {
        // Sort by the "first" of each pair
        std::sort(l_composite_values.begin(), l_composite_values.end());

        // I'm assuming we always have even number of DRAMs here...
        const uint64_t MID_POINT = DRAMS_PER_RP / 2;

        // Average the two mid-point values
        const uint64_t l_wr_vref_med_avg = ( l_composite_values[MID_POINT] +
                                             l_composite_values[MID_POINT - 1] ) / 2;

        FAPI_INF("nvdimm_workaround() - l_wr_vref_med_avg: 0x%016lx", l_wr_vref_med_avg);

        // Convert to JEDEC language
        const uint8_t l_jedec_med_value = mss::dp16::wr_vref::get_value(l_wr_vref_med_avg);
        const uint8_t l_jedec_med_range = mss::dp16::wr_vref::get_range(l_wr_vref_med_avg);
        fapi2::buffer<uint64_t> l_wr_vref_med_data;

        FAPI_INF("nvdimm_workaround() - median jedec: value = 0x%02x, range = 0x%02x", l_jedec_med_value, l_jedec_med_range);

        // Set up the reg with the median value
        l_wr_vref_med_data.insertFromRight<TT::WR_VREF_VALUE_VALUE_DRAM_EVEN, TT::WR_VREF_VALUE_VALUE_DRAM_EVEN_LEN>
        (l_jedec_med_value);
        l_wr_vref_med_data.insertFromRight<TT::WR_VREF_VALUE_VALUE_DRAM_ODD, TT::WR_VREF_VALUE_VALUE_DRAM_ODD_LEN>
        (l_jedec_med_value);

        l_wr_vref_med_data.writeBit<TT::WR_VREF_VALUE_RANGE_DRAM_EVEN>(l_jedec_med_range);
        l_wr_vref_med_data.writeBit<TT::WR_VREF_VALUE_RANGE_DRAM_ODD>(l_jedec_med_range);

        // Set the phy with the median value
        FAPI_TRY(mss::scom_blastah(i_target, l_wr_vref_regs, l_wr_vref_med_data));

        // Latches the median wr_vref
        FAPI_TRY( mss::ddr4::latch_wr_vref_commands_by_rank_pair(i_target,
                  i_rp,
                  l_jedec_med_range,
                  l_jedec_med_value) );
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace wr_vref
} // close namespace workarounds
} // close namespace mss
