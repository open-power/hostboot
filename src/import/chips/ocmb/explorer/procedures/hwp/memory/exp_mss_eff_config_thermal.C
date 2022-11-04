/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_mss_eff_config_thermal.C $ */
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
/// @file exp_mss_eff_config_thermal.C
/// @brief The explorer thermal/power config
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <vector>
#include <exp_bulk_pwr_throttles.H>
#include <exp_mss_eff_config_thermal.H>
#include <lib/power_thermal/exp_decoder.H>
#include <lib/power_thermal/exp_throttle.H>
#include <lib/shared/exp_consts.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_explorer_attribute_setters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/plug_rules/plug_rules.H>

extern "C"
{
    ///
    /// @brief Perform thermal calculations
    /// @param[in] i_targets vector of OCMB chip
    /// @return FAPI2_RC_SUCCESS iff ok
    fapi2::ReturnCode exp_mss_eff_config_thermal( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> >&
            i_targets )
    {
        using TT = mss::power_thermal::throttle_traits<mss::mc_type::EXPLORER>;
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        FAPI_INF("Start exp_mss_eff_config_thermal");

        // For regulator power/current throttling or thermal throttling
        // Do thermal throttling last so the attributes end up representing a total power value for later usage
        //   Need to have ATTR_EXP_TOTAL_PWR_SLOPE and ATTR_EXP_TOTAL_PWR_INTERCEPT with total DIMM power
        //   (not regulator current values) after exp_mss_eff_config_thermal is run, so when OCC calls
        //   exp_bulk_pwr_throttles at runtime the total DIMM power will be used for any memory bulk supply throttling
        const std::vector<mss::throttle_type> throttle_types{ mss::throttle_type::POWER, mss::throttle_type::THERMAL};

        const uint64_t l_min_util = TT::MIN_UTIL;

        for (const auto& l_ocmb : i_targets)
        {
            // Run eff_config_thermal so that we can run plug rules.
            FAPI_INF("Running enforce_pre_eff_config_thermal on %s", mss::c_str(l_ocmb));
            FAPI_TRY( mss::plug_rule::enforce_pre_eff_config_thermal<mss::mc_type::EXPLORER>(l_ocmb),
                      "Fail encountered in enforce_pre_eff_config_thermal for %s", mss::c_str(l_ocmb));
        }

        for ( const auto& l_ocmb : i_targets)
        {
            //Restore runtime_throttles
            //Sets throttles to max_databus_util value
            FAPI_INF("Restoring throttles for %s", mss::c_str(l_ocmb));
            FAPI_TRY( mss::power_thermal::restore_runtime_throttles<mss::mc_type::EXPLORER>(l_ocmb),
                      "Fail encountered in restore runtime throttles for %s", mss::c_str(l_ocmb));
        }

        for (const auto& l_throttle_type : throttle_types )
        {
            for ( const auto& l_ocmb : i_targets)
            {
                const uint32_t l_dimm_count = mss::count_dimm(l_ocmb);

                //Not doing any work if there are no dimms installed
                if ( l_dimm_count == 0)
                {
                    FAPI_INF("Skipping eff_config thermal because no dimms for %s", mss::c_str(l_ocmb));
                    continue;
                }

                // Thermal power (OCMB+DRAM)
                uint64_t l_thermal_power_limit[TT::SIZE_OF_THERMAL_LIMIT_ATTR] = {0};
                uint64_t l_thermal_power_slope[TT::SIZE_OF_THERMAL_SLOPE_ATTR] = {0};
                uint64_t l_thermal_power_intecept[TT::SIZE_OF_THERMAL_INTERCEPT_ATTR] = {0};
                uint64_t l_safemode_throttles[TT::SIZE_OF_SAFEMODE_THROTTLE_ATTR] = {0};
                // Power (PMIC)
                uint64_t l_current_curve_with_limit[TT::SIZE_OF_CURRENT_CURVE_WITH_LIMIT_ATTR] = {0};

                // Get the data from MRW
                FAPI_TRY( mss::attr::get_mrw_ocmb_thermal_memory_power_limit (l_thermal_power_limit) );
                FAPI_TRY( mss::attr::get_mrw_ocmb_pwr_slope (l_thermal_power_slope) );
                FAPI_TRY( mss::attr::get_mrw_ocmb_pwr_intercept (l_thermal_power_intecept) );
                FAPI_TRY( mss::attr::get_mrw_ocmb_current_curve_with_limit (l_current_curve_with_limit) );
                FAPI_TRY( mss::attr::get_mrw_ocmb_safemode_util_array (l_safemode_throttles) );

                // Convert array to vector
                std::vector<uint64_t> l_thermal_power_limit_v     ( std::begin(l_thermal_power_limit),
                        std::end(l_thermal_power_limit) );
                std::vector<uint64_t> l_thermal_power_slope_v     ( std::begin(l_thermal_power_slope),
                        std::end(l_thermal_power_slope) );
                std::vector<uint64_t> l_thermal_power_intecept_v  ( std::begin(l_thermal_power_intecept),
                        std::end(l_thermal_power_intecept) );
                std::vector<uint64_t> l_current_curve_with_limit_v( std::begin(l_current_curve_with_limit),
                        std::end(l_current_curve_with_limit) );
                std::vector<uint64_t> l_safemode_throttles_v      ( std::begin(l_safemode_throttles),
                        std::end(l_safemode_throttles) );

                for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(l_ocmb))
                {
                    //Don't run if there are no dimms on the port
                    if (mss::count_dimm(l_port) == 0)
                    {
                        continue;
                    }

                    uint16_t l_slope    [TT::DIMMS_PER_PORT] = {0};
                    uint16_t l_intercept[TT::DIMMS_PER_PORT] = {0};
                    uint32_t l_limit    [TT::DIMMS_PER_PORT] = {0};
                    uint32_t l_safemode = 0;

                    // Set the thermal power throttle
                    // Set the PMIC current slope, intercept and limit
                    FAPI_TRY( mss::power_thermal::get_power_attrs (l_throttle_type,
                              l_port,
                              l_thermal_power_slope_v,
                              l_thermal_power_intecept_v,
                              l_thermal_power_limit_v,
                              l_current_curve_with_limit_v,
                              l_safemode_throttles_v,
                              l_slope,
                              l_intercept,
                              l_limit,
                              l_safemode) );

                    FAPI_TRY(mss::attr::set_total_pwr_slope(l_port, l_slope));
                    FAPI_TRY(mss::attr::set_total_pwr_intercept(l_port, l_intercept));
                    FAPI_TRY(mss::attr::set_dimm_thermal_limit(l_port, l_limit));
                    FAPI_TRY(mss::attr::set_mem_watt_target(l_port, l_limit));

                    // Return error if safemode throttle utilization is less than MIN_UTIL
                    FAPI_ASSERT( l_safemode >= TT::MIN_UTIL,
                                 fapi2::MSS_MRW_SAFEMODE_UTIL_THROTTLE_NOT_SUPPORTED()
                                 .set_MRW_SAFEMODE_UTIL(l_safemode)
                                 .set_MIN_UTIL_VALUE(l_min_util),
                                 "MRW safemode util (%d centi percent) has less util than the min util allowed (%d centi percent) for %s",
                                 l_safemode, l_min_util, mss::c_str(l_port) );

                    FAPI_TRY( mss::attr::set_safemode_dram_databus_util(l_port, l_safemode) );

                    for ( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port) )
                    {
                        const uint8_t l_dimm_pos = mss::index(l_dimm);
                        FAPI_INF( "DIMM (%d) slope is %d, intercept is %d, limit is %d for %s",
                                  l_dimm_pos, l_slope[l_dimm_pos], l_intercept[l_dimm_pos],
                                  l_limit[l_dimm_pos], mss::c_str(l_port));
                    }
                }

                FAPI_INF("Starting pwr_throttles(%s) for %s",
                         mss::throttle_type::POWER == l_throttle_type ? "POWER" : "THERMAL", mss::c_str(l_ocmb));
                //get the power limits, done per dimm and set to worst case for the slot and port throttles
                FAPI_TRY(mss::power_thermal::pwr_throttles(l_ocmb, l_throttle_type),
                         "Fail encountered in pwr_throttles for %s", mss::c_str(l_ocmb));
            }

            // Equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
            FAPI_TRY(mss::power_thermal::equalize_throttles(i_targets, l_throttle_type),
                     "Fail encountered in equalize_throttles");

            for ( const auto& l_ocmb : i_targets)
            {
                //Set runtime throttles to worst case between ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT
                //and ATTR_EXP_MEM_RUNTIME_THROTTLED_N_COMMANDS_PER_SLOT and the _PORT equivalents also
                FAPI_TRY( mss::power_thermal::update_runtime_throttle<mss::mc_type::EXPLORER>(l_ocmb),
                          "Fail encountered in update_runtime_throttle for %s", mss::c_str(l_ocmb));
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

} //extern C
