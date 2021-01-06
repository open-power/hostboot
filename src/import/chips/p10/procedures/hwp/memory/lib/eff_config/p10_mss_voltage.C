/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_mss_voltage.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_mss_voltage.C
/// @brief Axone specializations for voltage library
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <vector>

// Memory libraries
#include <exp_attribute_accessors_manual.H>

// Generic libraries
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/voltage/gen_mss_voltage_traits.H>
#include <generic/memory/lib/utils/voltage/gen_mss_volt.H>
#include <generic/memory/lib/spd/spd_fields_ddr4.H>
#include <generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>

namespace mss
{

using TT = mss::voltage_traits<mss::mc_type::EXPLORER, mss::spd::device_type::DDR4>;

// List of attribute setter functions for setting voltage rail values
const std::vector<fapi2::ReturnCode (*)(const fapi2::Target<TT::VOLTAGE_TARGET_TYPE>&, uint32_t)>
TT::voltage_setters =
{
    &set_volt_vddr,
    &set_volt_vpp,
};

///
/// @brief Determine what voltages are supported for the given memory controller and DRAM generation
/// @param[in] i_target the target for setting voltage attributes
/// @param[out] o_supported_dram_voltages vector of supported rail voltages in millivolts to be used in set_voltage_attributes
/// @return FAPI2_RC_SUCCESS iff ok
/// @note P10, DDR4 specialization
///
template<>
fapi2::ReturnCode get_supported_voltages<mss::mc_type::EXPLORER, mss::spd::device_type::DDR4>(
    const fapi2::Target<TT::SPD_TARGET_TYPE>& i_target,
    std::vector<uint32_t>& o_supported_dram_voltages)
{
    using F = mss::spd::fields<mss::spd::device_type::DDR4, mss::spd::module_params::BASE_CNFG>;

    o_supported_dram_voltages.clear();

    // Get DIMM for each port
    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        std::vector<uint8_t> l_spd;
        uint8_t l_dimm_nominal = 0;
        uint8_t l_dimm_endurant = 0;

        const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_dimm);

        FAPI_TRY(mss::spd::get_raw_data(l_dimm, l_spd));

        // Read nominal and endurant bits from SPD, 0 = 1.2V is not operable and endurant, 1 = 1.2 is valid
        // TK - will need to be updated for Odyssey / DDR5
        FAPI_TRY(spd::get_field_spd(l_ocmb, F::OPERABLE_FLD, l_spd, SET_OPERABLE_FLD, l_dimm_nominal));
        FAPI_TRY(spd::get_field_spd(l_ocmb, F::ENDURANT_FLD, l_spd, SET_ENDURANT_FLD, l_dimm_endurant));

        // Range checks for those fields performed here
        // Check to make sure 1.2 V is both operable and endurant, fail if it is not
        FAPI_ASSERT ( (l_dimm_nominal == mss::spd::OPERABLE) && (l_dimm_endurant == mss::spd::ENDURANT),
                      fapi2::MSS_VOLT_DDR_TYPE_REQUIRED_VOLTAGE().
                      set_ACTUAL_OPERABLE(l_dimm_nominal).
                      set_ACTUAL_ENDURANT(l_dimm_endurant).
                      set_EXPECTED_OPERABLE(mss::spd::OPERABLE).
                      set_EXPECTED_ENDURANT(mss::spd::ENDURANT).
                      set_DIMM_TARGET(l_dimm),
                      "%s: DIMM is not operable (%d) expected (%d)"
                      " and/or endurant (%d) expected (%d) at 1.2V",
                      mss::c_str(l_dimm),
                      l_dimm_nominal,
                      mss::spd::OPERABLE,
                      l_dimm_endurant,
                      mss::spd::ENDURANT);
    } // l_dimm

    // Set the attributes for this port, values are in mss_const.H
    // The ordering of voltages is specified in the selected voltage_traits specialization
    o_supported_dram_voltages.push_back(TT::DDR4_NOMINAL_VOLTAGE);
    o_supported_dram_voltages.push_back(TT::DDR4_VPP_VOLTAGE);

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss
