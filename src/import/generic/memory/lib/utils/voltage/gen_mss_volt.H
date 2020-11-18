/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/voltage/gen_mss_volt.H $  */
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
/// @file gen_mss_volt.H
/// @brief Functions used by mss_volt procedure
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _GEN_MSS_VOLT_H_
#define _GEN_MSS_VOLT_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/voltage/gen_mss_voltage_traits.H>

namespace mss
{

///
/// @brief Determine what voltages are supported for the given memory controller and DRAM generation
/// @tparam M mss::mc_type memory controller type
/// @tparam D mss::spd::device_type DRAM device type (generation)
/// @tparam TT mss::voltage_traits voltage traits for the given mc_type/device_type pairing
/// @param[in] i_target the target for accessing voltage attributes from SPD
/// @param[out] o_supported_dram_voltages vector of supported rail voltages in millivolts to be used in set_voltage_attributes
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type M, mss::spd::device_type D, typename TT = mss::voltage_traits<M, D>>
fapi2::ReturnCode get_supported_voltages(const fapi2::Target<TT::SPD_TARGET_TYPE>& i_target,
        std::vector<uint32_t>& o_supported_dram_voltages);

///
/// @brief Set voltage rail attributes
/// @tparam M mss::mc_type memory controller type
/// @tparam D mss::spd::device_type DRAM device type (generation)
/// @tparam TT mss::voltage_traits voltage traits for the given mc_type/device_type pairing
/// @param[in] i_target the target for setting voltage attributes
/// @param[in] i_selected_dram_voltages vector of selected rail voltages in millivolts for nominal voltage
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type M, mss::spd::device_type D, typename TT = mss::voltage_traits<M, D>>
inline fapi2::ReturnCode set_voltage_attributes(const fapi2::Target<TT::VOLTAGE_TARGET_TYPE>& i_target,
        const std::vector<uint32_t>& i_selected_dram_voltages)
{
    // Check that the number of supplied voltage values is correct
    const auto l_num_setters = TT::voltage_setters.size();
    const auto l_num_supplied_voltages = i_selected_dram_voltages.size();

    FAPI_ASSERT(l_num_supplied_voltages == l_num_setters,
                fapi2::MSS_VOLT_WRONG_NUMBER_OF_VOLTAGES().
                set_SUPPLIED_NUMBER(l_num_supplied_voltages).
                set_EXPECTED_NUMBER(l_num_setters).
                set_VOLT_TARGET(i_target),
                "%s: Incorrect number of voltages supplied to set_voltage_attributes function: %d (expected %d)",
                mss::c_str(i_target),
                l_num_supplied_voltages,
                l_num_setters);

    for (size_t l_setter_index = 0; l_setter_index < l_num_setters; ++l_setter_index)
    {
        FAPI_TRY( (*TT::voltage_setters[l_setter_index])(i_target, i_selected_dram_voltages[l_setter_index]) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup and save off rail voltages
/// @tparam M mss::mc_type memory controller type
/// @tparam D mss::spd::device_type DRAM device type (generation)
/// @tparam TT mss::voltage_traits voltage traits for the given mc_type/device_type pairing
/// @param[in] i_target the target for accessing voltage attributes from SPD
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type M, mss::spd::device_type D, typename TT = mss::voltage_traits<M, D>>
inline fapi2::ReturnCode setup_voltage_rail_values(const fapi2::Target<TT::SPD_TARGET_TYPE>& i_target)
{
    const auto l_voltage_target = mss::find_target<TT::VOLTAGE_TARGET_TYPE>(i_target);
    const auto l_spd_target = mss::find_target<TT::SPD_TARGET_TYPE>(i_target);
    std::vector<uint32_t> l_dram_voltages;

    FAPI_TRY( (mss::get_supported_voltages<M, D>(l_spd_target, l_dram_voltages)),
              "Failed to get supported voltages for %s", mss::c_str(l_spd_target) );

    FAPI_TRY( (mss::set_voltage_attributes<M, D>(l_voltage_target, l_dram_voltages)),
              "Failed to set volt attributes for %s", mss::c_str(l_voltage_target) );

fapi_try_exit:
    return fapi2::current_err;
}

}  // mss

#endif
