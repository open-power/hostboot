/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_mss_voltage.C $ */
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
#include <generic/memory/lib/spd/spd_fields_ddr5.H>
#include <generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <lib/eff_config/p10_common_engine.H>
#include <generic/memory/lib/spd/spd_utils_ddr5.H>
#include <mss_generic_attribute_setters.H>

namespace mss
{
using TT4 = mss::voltage_traits<mss::mc_type::EXPLORER, mss::spd::device_type::DDR4>;
using TT5 = mss::voltage_traits<mss::mc_type::ODYSSEY, mss::spd::device_type::DDR5>;

// List of attribute setter functions for setting voltage rail values
const std::vector<fapi2::ReturnCode (*)(const fapi2::Target<TT4::VOLTAGE_TARGET_TYPE>&, uint32_t)>
TT4::voltage_setters =
{
    &set_volt_vddr,
    &set_volt_vpp,
};

///
/// @brief Determine what voltages are supported for the given memory controller and DRAM generation
/// @param[in] i_target the target for setting voltage attributes
/// @param[in] i_spd raw spd data
/// @param[out] o_supported_dram_voltages vector of supported rail voltages in millivolts to be used in set_voltage_attributes
/// @return FAPI2_RC_SUCCESS iff ok
/// @note P10, DDR4 specialization
///
template<>
fapi2::ReturnCode get_supported_voltages<mss::mc_type::EXPLORER, mss::spd::device_type::DDR4> (
    const fapi2::Target<TT4::SPD_TARGET_TYPE>& i_target,
    const std::vector<uint8_t>& i_spd,
    std::vector<uint32_t>& o_supported_dram_voltages)
{
    using F = mss::spd::fields<mss::spd::device_type::DDR4, mss::spd::module_params::BASE_CNFG>;

    o_supported_dram_voltages.clear();

    uint8_t l_dimm_nominal = 0;
    uint8_t l_dimm_endurant = 0;

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
    // Read nominal and endurant bits from SPD, 0 = 1.2V is not operable and endurant, 1 = 1.2 is valid
    FAPI_TRY(spd::get_field_spd(l_ocmb, F::OPERABLE_FLD, i_spd, SET_OPERABLE_FLD, l_dimm_nominal));
    FAPI_TRY(spd::get_field_spd(l_ocmb, F::ENDURANT_FLD, i_spd, SET_ENDURANT_FLD, l_dimm_endurant));

    // Range checks for those fields performed here
    // Check to make sure 1.2 V is both operable and endurant, fail if it is not
    FAPI_ASSERT ( (l_dimm_nominal == mss::spd::OPERABLE) && (l_dimm_endurant == mss::spd::ENDURANT),
                  fapi2::MSS_VOLT_DDR4_TYPE_REQUIRED_VOLTAGE().
                  set_ACTUAL_OPERABLE(l_dimm_nominal).
                  set_ACTUAL_ENDURANT(l_dimm_endurant).
                  set_EXPECTED_OPERABLE(mss::spd::OPERABLE).
                  set_EXPECTED_ENDURANT(mss::spd::ENDURANT).
                  set_DIMM_TARGET(i_target),
                  "%s: DIMM is not operable (%d) expected (%d)"
                  " and/or endurant (%d) expected (%d) at 1.2V",
                  mss::c_str(i_target),
                  l_dimm_nominal,
                  mss::spd::OPERABLE,
                  l_dimm_endurant,
                  mss::spd::ENDURANT);

    // Set the attributes for this port, values are in mss_const.H
    // The ordering of voltages is specified in the selected voltage_traits specialization
    o_supported_dram_voltages.push_back(TT4::DDR4_NOMINAL_VOLTAGE);
    o_supported_dram_voltages.push_back(TT4::DDR4_VPP_VOLTAGE);

fapi_try_exit:
    return fapi2::current_err;
}

// List of attribute setter functions for setting voltage rail values
const std::vector<fapi2::ReturnCode (*)(const fapi2::Target<TT5::VOLTAGE_TARGET_TYPE>&, uint32_t)>
TT5::voltage_setters =
{
    &mss::attr::set_volt_vddr,
    &mss::attr::set_volt_vddq,
    &mss::attr::set_volt_vpp,
};

///
/// @brief Determine what voltages are supported for the given memory controller and DRAM generation
/// @param[in] i_target the target for setting voltage attributes
/// @param[in] i_spd raw spd data
/// @param[out] o_supported_dram_voltages vector of supported rail voltages in millivolts to be used in set_voltage_attributes
/// @return FAPI2_RC_SUCCESS iff ok
/// @note P10, DDR5 specialization
///
template<>
fapi2::ReturnCode get_supported_voltages<mss::mc_type::ODYSSEY, mss::spd::device_type::DDR5> (
    const fapi2::Target<TT5::SPD_TARGET_TYPE>& i_target,
    const std::vector<uint8_t>& i_spd,
    std::vector<uint32_t>& o_supported_dram_voltages)
{
    using F = mss::spd::fields<mss::spd::device_type::DDR5, mss::spd::module_params::BASE_CNFG>;

    o_supported_dram_voltages.clear();

    uint8_t l_dimm_vdd_operable = 0;
    uint8_t l_dimm_vddq_operable = 0;
    uint8_t l_dimm_vpp_operable = 0;
    uint8_t l_dimm_vdd_endurant = 0;
    uint8_t l_dimm_vddq_endurant = 0;
    uint8_t l_dimm_vpp_endurant = 0;

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // Read nominal and endurant bits from SPD, 00 = 1.1V is operable and endurant, 00 = 1.1 is valid
    FAPI_TRY(spd::get_field_spd(l_ocmb, F::OPERABLE_VDD_FLD, i_spd, SET_OPERABLE_FLD, l_dimm_vdd_operable));
    FAPI_TRY(spd::get_field_spd(l_ocmb, F::OPERABLE_VDDQ_FLD, i_spd, SET_OPERABLE_FLD, l_dimm_vddq_operable));
    FAPI_TRY(spd::get_field_spd(l_ocmb, F::OPERABLE_VPP_FLD, i_spd, SET_OPERABLE_FLD, l_dimm_vpp_operable));
    FAPI_TRY(spd::get_field_spd(l_ocmb, F::ENDURANT_VDD_FLD, i_spd, SET_ENDURANT_FLD, l_dimm_vdd_endurant));
    FAPI_TRY(spd::get_field_spd(l_ocmb, F::ENDURANT_VDDQ_FLD, i_spd, SET_ENDURANT_FLD, l_dimm_vddq_endurant));
    FAPI_TRY(spd::get_field_spd(l_ocmb, F::ENDURANT_VPP_FLD, i_spd, SET_ENDURANT_FLD, l_dimm_vpp_endurant));

    // Range checks for those fields performed here
    // Check to make sure 1.1 V is both operable and endurant, fail if it is not
    FAPI_ASSERT ( (l_dimm_vdd_operable == mss::spd::ddr5::OPERABLE) &&
                  (l_dimm_vddq_operable == mss::spd::ddr5::OPERABLE) &&
                  (l_dimm_vpp_operable == mss::spd::ddr5::OPERABLE) &&
                  (l_dimm_vdd_endurant == mss::spd::ddr5::ENDURANT) &&
                  (l_dimm_vddq_endurant == mss::spd::ddr5::ENDURANT) &&
                  (l_dimm_vpp_endurant == mss::spd::ddr5::ENDURANT),
                  fapi2::MSS_VOLT_DDR5_TYPE_REQUIRED_VOLTAGE().
                  set_ACTUAL_VDD_OPERABLE(l_dimm_vdd_operable).
                  set_ACTUAL_VDDQ_OPERABLE(l_dimm_vddq_operable).
                  set_ACTUAL_VPP_OPERABLE(l_dimm_vpp_operable).
                  set_ACTUAL_VDD_ENDURANT(l_dimm_vdd_endurant).
                  set_ACTUAL_VDDQ_ENDURANT(l_dimm_vddq_endurant).
                  set_ACTUAL_VPP_ENDURANT(l_dimm_vpp_endurant).
                  set_EXPECTED_OPERABLE(mss::spd::ddr5::OPERABLE).
                  set_EXPECTED_ENDURANT(mss::spd::ddr5::ENDURANT).
                  set_DIMM_TARGET(i_target),
                  "%s: DIMM is not operable (%d,%d,%d) expected (%d)"
                  " and/or endurant (%d,%d,%d) expected (%d) at 1.1V",
                  mss::c_str(i_target),
                  l_dimm_vdd_operable,
                  l_dimm_vddq_operable,
                  l_dimm_vpp_operable,
                  mss::spd::ddr5::OPERABLE,
                  l_dimm_vdd_endurant,
                  l_dimm_vddq_endurant,
                  l_dimm_vpp_endurant,
                  mss::spd::ddr5::ENDURANT);

    // Set the attributes for this port, values are in mss_const.H
    // The ordering of voltages is specified in the selected voltage_traits specialization
    o_supported_dram_voltages.push_back(TT5::DDR5_VDD_VOLTAGE);
    o_supported_dram_voltages.push_back(TT5::DDR5_VDDQ_VOLTAGE);
    o_supported_dram_voltages.push_back(TT5::DDR5_VPP_VOLTAGE);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup the DRAM generation
/// @param[in] i_target dimm target
/// @param[out] o_spd spd data
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode spd_common_process( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      std::vector<uint8_t>& o_spd)
{
    uint8_t l_is_planar = 0;
    mss::spd::common_engine l_engine(i_target);
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
    FAPI_TRY( mss::attr::get_mem_mrw_is_planar(l_ocmb, l_is_planar) );
    FAPI_TRY(mss::spd::get_raw_data(i_target, l_is_planar, o_spd));

    // Setting up DRAM generation.
    FAPI_TRY(l_engine.process(o_spd), "%s unable to process common engine SPD", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss
