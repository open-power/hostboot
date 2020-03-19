/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/nimbus_mss_voltage.C $ */
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
/// @file nimbus_mss_voltage.C
/// @brief Nimbus specializations for voltage library
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <vector>

// Memory libraries
#include <lib/mss_attribute_accessors.H>
#include <lib/shared/mss_const.H>

// Generic libraries
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/utils/nimbus_find.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/utils/voltage/gen_mss_voltage_traits.H>
#include <generic/memory/lib/utils/voltage/gen_mss_volt.H>

namespace mss
{

using TT = mss::voltage_traits<mss::mc_type::NIMBUS, mss::spd::device_type::DDR4>;

// List of attribute setter functions for setting voltage rail values
// Note that this list needs to be ordered the same way as the list returned by mss::get_supported_voltages
const std::vector<fapi2::ReturnCode (*)(const fapi2::Target<TT::VOLTAGE_TARGET_TYPE>&, uint32_t)> TT::voltage_setters =
{
    &set_volt_vddr,
    &set_volt_vpp,
};

///
/// @brief Determine what voltages are supported for the given memory controller and DRAM generation
/// @param[in] i_target the target for setting voltage attributes
/// @param[out] o_supported_dram_voltages vector of supported rail voltages in millivolts to be used in set_voltage_attributes
/// @return FAPI2_RC_SUCCESS iff ok
/// @note NIMBUS, DDR4 specialization
///
template<>
fapi2::ReturnCode get_supported_voltages<mss::mc_type::NIMBUS, mss::spd::device_type::DDR4>
(const fapi2::Target<TT::SPD_TARGET_TYPE>& i_target,
 std::vector<uint32_t>& o_supported_dram_voltages)
{
    o_supported_dram_voltages.clear();

    FAPI_INF("Populating decoder cache for %s", mss::c_str(i_target));

    //Factory cache is per MCS
    std::vector< mss::spd::facade > l_spd_facades;
    FAPI_TRY( get_spd_decoder_list(i_target, l_spd_facades) );

    // Get dimms for each MCS
    for ( const auto& l_cache : l_spd_facades )
    {
        const auto l_dimm = l_cache.get_target();
        uint8_t l_dimm_nominal = 0;
        uint8_t l_dimm_endurant = 0;

        // Read nominal and endurant bits from SPD, 0 = 1.2V is not operable and endurant, 1 = 1.2 is valid
        FAPI_TRY( l_cache.operable_nominal_voltage(l_dimm_nominal) );
        FAPI_TRY( l_cache.endurant_nominal_voltage(l_dimm_endurant) );

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

    // Set the attributes for this MCS, values are in mss_const.H
    // The ordering of voltages is specified in the selected voltage_traits specialization
    o_supported_dram_voltages.push_back(mss::DDR4_NOMINAL_VOLTAGE);
    o_supported_dram_voltages.push_back(mss::DDR4_VPP_VOLTAGE);

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss
