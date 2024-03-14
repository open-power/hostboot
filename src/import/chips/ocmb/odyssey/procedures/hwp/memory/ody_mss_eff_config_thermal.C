/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_mss_eff_config_thermal.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2024                        */
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
/// @file ody_mss_eff_config_thermal.C
/// @brief Determine thermal throttling setttings based on system policies
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <vector>
#include <ody_mss_eff_config_thermal.H>
#include <lib/power_thermal/ody_throttle.H>
#include <lib/power_thermal/ody_throttle_traits.H>
#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/power_thermal/gen_decoder.H>
#include <generic/memory/lib/utils/power_thermal/gen_throttle.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/plug_rules/plug_rules.H>

extern "C"
{
///
/// @brief Determine thermal throttling setttings based on system policies
/// @param[in] i_targets vector of OCMB chips
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_mss_eff_config_thermal( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> >&
            i_targets)
    {
        using TT = mss::power_thermal::throttle_traits<mss::mc_type::ODYSSEY>;
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        FAPI_INF_NO_SBE("Start ody_mss_eff_config_thermal");

        // For regulator power/current throttling or thermal throttling
        // Do thermal throttling first since throttles are not optimized for thermal throttles and we want to
        //   compare them against the MRW max utilization allowed runtime throttle values to see if they can be optimized
        // Then do power throttling second so combine_runtime_port_throttles can decide if throttles can be optimized
        // Then do thermal throttling third so that resets attributes to total DIMM power values (needed when OCC calls bulk_pwr_throttles)
        //   do not recalcuate throttles as that may not provide correct throttle settings in the end with the optimizations that are done
        const std::vector<mss::throttle_type> throttle_types{ mss::throttle_type::THERMAL, mss::throttle_type::POWER, mss::throttle_type::THERMAL};

        const uint64_t l_min_util = TT::MIN_UTIL;
        uint8_t l_thermal_count = 0;

        // Enforces the plug rules on all targets passed in
        // This should be on the per-backplane level
        // Mixing of DRAM generation is not allowed w/in a backplane but is allowed in systems w/ multiple backplanes
        FAPI_TRY( mss::plug_rule::enforce_pre_eff_config_thermal<mss::mc_type::ODYSSEY>(i_targets));

        for ( const auto& l_ocmb : i_targets)
        {
            // init ocmb throttles to zero to make sure they will be power throttle optimized
            uint16_t l_ocmb_slot = 0;
            uint16_t l_ocmb_port = 0;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_ocmb, l_ocmb_slot));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_ocmb, l_ocmb_port));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_ocmb, l_ocmb_slot));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_ocmb, l_ocmb_port));

            //Restore runtime_throttles, using power optimized throttles
            //Sets throttles to max_databus_util value
            FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Restoring throttles", GENTARGTID(l_ocmb) );
            FAPI_TRY( mss::power_thermal::restore_runtime_throttles<mss::mc_type::ODYSSEY>(l_ocmb, mss::throttle_type::POWER),
                      GENTARGTIDFORMAT " Fail encountered in restore runtime throttles", GENTARGTID(l_ocmb));
        }

        for (const auto& l_throttle_type : throttle_types )
        {
            for ( const auto& l_ocmb : i_targets)
            {
                const uint32_t l_dimm_count = mss::count_dimm(l_ocmb);

                //Not doing any work if there are no dimms installed
                if ( l_dimm_count == 0)
                {
                    FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Skipping eff_config_thermal because no dimms found", GENTARGTID(l_ocmb));
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
                FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_OCMB_THERMAL_MEMORY_POWER_LIMIT, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                        l_thermal_power_limit) );
                FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_OCMB_PWR_SLOPE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                        l_thermal_power_slope) );
                FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_OCMB_PWR_INTERCEPT, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                        l_thermal_power_intecept) );
                FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_OCMB_CURRENT_CURVE_WITH_LIMIT, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                        l_current_curve_with_limit) );
                FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_OCMB_SAFEMODE_UTIL_ARRAY, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                        l_safemode_throttles) );

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
                    FAPI_TRY( mss::power_thermal::get_power_attrs<mss::mc_type::ODYSSEY> (l_throttle_type,
                              l_port,
                              l_thermal_power_slope_v,
                              l_thermal_power_intecept_v,
                              l_thermal_power_limit_v,
                              l_current_curve_with_limit_v,
                              l_safemode_throttles_v,
                              l_slope,
                              l_intercept,
                              l_limit,
                              l_safemode));

                    FAPI_TRY(mss::attr::set_total_pwr_slope(l_port, l_slope));
                    FAPI_TRY(mss::attr::set_total_pwr_intercept(l_port, l_intercept));
                    FAPI_TRY(mss::attr::set_dimm_thermal_limit(l_port, l_limit));
                    FAPI_TRY(mss::attr::set_mem_watt_target(l_port, l_limit));

                    // Return error if safemode throttle utilization is less than MIN_UTIL
                    FAPI_ASSERT( l_safemode >= TT::MIN_UTIL,
                                 fapi2::MSS_MRW_SAFEMODE_UTIL_THROTTLE_NOT_SUPPORTED()
                                 .set_MRW_SAFEMODE_UTIL(l_safemode)
                                 .set_MIN_UTIL_VALUE(l_min_util),
                                 GENTARGTIDFORMAT " MRW safemode util (%d centi percent) has less util than the min util allowed (%d centi percent)",
                                 GENTARGTID(l_port),
                                 l_safemode, l_min_util );

                    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_SAFEMODE_DRAM_DATABUS_UTIL, l_port, l_safemode) );

                    for ( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port) )
                    {
                        const uint8_t l_dimm_pos = mss::index(l_dimm);
                        FAPI_INF_NO_SBE( GENTARGTIDFORMAT " DIMM (%d) slope is %d, intercept is %d, limit is %d", GENTARGTID(l_port),
                                         l_dimm_pos, l_slope[l_dimm_pos], l_intercept[l_dimm_pos],
                                         l_limit[l_dimm_pos]);
                    }
                }

                // only do this one time for thermal throttling and do this for power throttling
                // second time thermal throttling is done is for only resetting attributes so we don't want to recalculate
                //   throttles again as that would not work correctly with the throttle optimization being done
                if ((l_thermal_count == 0) || (l_throttle_type == mss::throttle_type::POWER))
                {
                    FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Starting pwr_throttles(%s)",
                                    GENTARGTID(l_ocmb), mss::throttle_type::POWER == l_throttle_type ? "POWER" : "THERMAL");
                    //get the power limits, done per dimm and set to worst case for the slot and port throttles
                    FAPI_TRY(mss::power_thermal::pwr_throttles<mss::mc_type::ODYSSEY>(l_ocmb, l_throttle_type),
                             GENTARGTIDFORMAT " Fail encountered in pwr_throttles", GENTARGTID(l_ocmb));
                }
            }

            // only do this one time for thermal throttling and do this for power throttling
            // second time thermal throttling is done is for only resetting attributes so we don't want to recalculate
            //   throttles again as that would not work correctly with the throttle optimization being done
            if ((l_thermal_count == 0) || (l_throttle_type == mss::throttle_type::POWER))
            {

                // Combines all port-based throttles for overall OCMB equivelents
                // Then equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
                FAPI_TRY(mss::power_thermal::equalize_throttles<mss::mc_type::ODYSSEY>(i_targets, l_throttle_type),
                         "Fail encountered in equalize_throttles");

                for ( const auto& l_ocmb : i_targets)
                {
                    // Combines all port-based throttles for overall OCMB equivelents
                    // Set runtime throttles to worst case between ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT
                    // and ATTR_EXP_MEM_RUNTIME_THROTTLED_N_COMMANDS_PER_SLOT and the _PORT equivalents also
                    FAPI_TRY( mss::power_thermal::update_runtime_throttle<mss::mc_type::ODYSSEY>(l_ocmb, l_throttle_type),
                              GENTARGTIDFORMAT " Fail encountered in update_runtime_throttle", GENTARGTID(l_ocmb));
                }
            }

            // increment thermal count variable
            if (l_throttle_type == mss::throttle_type::THERMAL)
            {
                l_thermal_count++;
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

}// extern C
