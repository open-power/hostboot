/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_eff_config_thermal.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file p9_mss_eff_config_thermal.C
/// @brief Perform thermal calculations as part of the effective configuration
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Michael Pardeik <pardeik@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <lib/shared/nimbus_defaults.H>
#include <fapi2.H>
#include <vector>
#include <p9_mss_eff_config_thermal.H>
#include <p9_mss_bulk_pwr_throttles.H>
#include <lib/power_thermal/throttle.H>
#include <lib/power_thermal/decoder.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/shared/mss_const.H>
#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <mss.H>
extern "C"
{
    ///
    /// @brief Perform thermal calculations as part of the effective configuration
    /// @param[in] i_targets an array of MCS targets all on the same VDDR domain
    /// @return FAPI2_RC_SUCCESS iff ok
    /// @note sets ATTR_MSS_MEM_WATT_TARGET, ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT and _PER_SLOT, and ATTR_MSS_PORT_MAXPOWER
    fapi2::ReturnCode p9_mss_eff_config_thermal( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_targets )
    {
        using TT = mss::power_thermal::throttle_traits<mss::mc_type::NIMBUS>;

        FAPI_INF("Start effective config thermal");
        fapi2::ReturnCode l_rc;

        std::vector< uint64_t > l_slope (TT::SIZE_OF_POWER_CURVES_ATTRS, 0);
        std::vector< uint64_t > l_intercept (TT::SIZE_OF_POWER_CURVES_ATTRS, 0);
        std::vector< uint64_t > l_thermal_power_limit (TT::SIZE_OF_THERMAL_ATTR, 0);

        FAPI_TRY( mss::mrw_pwr_slope (l_slope.data()), "Error in p9_mss_eff_config_thermal");
        FAPI_TRY( mss::mrw_pwr_intercept (l_intercept.data()), "Error in p9_mss_eff_config_thermal" );
        FAPI_TRY( mss::mrw_thermal_memory_power_limit (l_thermal_power_limit.data()), "Error in p9_mss_eff_config_thermal" );
        FAPI_TRY( mss::power_thermal::set_runtime_m_and_watt_limit (i_targets), "Error in p9_mss_eff_config_thermal");

        FAPI_INF("Size of vectors are %d %d %d", l_slope.size(), l_intercept.size(), l_thermal_power_limit.size());

        // Return error if safemode throttle utilization is less than MIN_UTIL
        // This section needs to be in braces otherwise the compile will fail
        {
            using TT = mss::power_thermal::throttle_traits<>;
            const uint64_t l_min_util = TT::MIN_UTIL;
            uint16_t l_throttle_per_port = 0;
            uint32_t l_throttle_denominator = 0;
            FAPI_TRY(mss::mrw_mem_m_dram_clocks(l_throttle_denominator), "Error in p9_mss_eff_config_thermal" );
            FAPI_TRY(mss::mrw_safemode_mem_throttled_n_commands_per_port(l_throttle_per_port),
                     "Error in p9_mss_eff_config_thermal" );
            FAPI_ASSERT( (l_throttle_per_port  >= (TT::MIN_UTIL * l_throttle_denominator /
                                                   mss::power_thermal::DRAM_BUS_UTILS / mss::power_thermal::UTIL_CONVERSION)),
                         fapi2::MSS_MRW_SAFEMODE_THROTTLE_NOT_SUPPORTED()
                         .set_MRW_SAFEMODE_N_VALUE(l_throttle_per_port)
                         .set_MRW_DRAM_CLOCK_THROTTLE_M(l_throttle_denominator)
                         .set_MIN_UTIL_VALUE(l_min_util),
                         "MRW safemode attribute (N=%d, M=%d) has less util than the min util allowed (%d centi percent)",
                         l_throttle_per_port, l_throttle_denominator, l_min_util);
        }

        //Restore runtime_throttles from safemode setting
        //Decode and set power curve attributes at the same time
        for (const auto& l_mcs : i_targets )
        {
            //Not doing any work if there are no dimms installed
            if (mss::count_dimm(l_mcs) == 0)
            {
                FAPI_INF("Skipping eff_config thermal because no dimms %s", mss::c_str(l_mcs));
                continue;
            }

            uint16_t l_vddr_slope     [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
            uint16_t l_vddr_int       [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
            uint16_t l_total_slope    [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
            uint16_t l_total_int      [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
            uint32_t l_thermal_power  [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};

            FAPI_TRY( mss::power_thermal::get_power_attrs(l_mcs,
                      l_slope,
                      l_intercept,
                      l_thermal_power_limit,
                      l_vddr_slope,
                      l_vddr_int,
                      l_total_slope,
                      l_total_int,
                      l_thermal_power));

            //Sets throttles to max_databus_util value
            FAPI_INF("Restoring throttles");
            FAPI_TRY( mss::power_thermal::restore_runtime_throttles(l_mcs), "Error in p9_mss_eff_config_thermal");

            //Set the power attribute (TOTAL_PWR) to just VDDR for the POWER bulk_pwr_throttles, restore to vddr+vpp  later for OCC
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_TOTAL_PWR_SLOPE,
                                    l_mcs,
                                    l_vddr_slope));

            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_TOTAL_PWR_INTERCEPT,
                                    l_mcs,
                                    l_vddr_int));

            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_DIMM_THERMAL_LIMIT,
                                    l_mcs,
                                    l_thermal_power));
        }

        FAPI_INF("Starting bulk_pwr");
        //get the thermal limits, done per dimm and set to worst case for the slot and port throttles
        //Bulk_pwr sets the general, all purpose ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT, _PER_PORT, and MAXPOWER ATTRs
        FAPI_EXEC_HWP(l_rc, p9_mss_bulk_pwr_throttles, i_targets, mss::throttle_type::POWER);
        FAPI_TRY(l_rc, "Failed running p9_mss_bulk_pwr_throttles");

        //Set runtime throttles to worst case between ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT
        //and ATTR_MSS_MEM_RUNTIME_THROTTLED_N_COMMANDS_PER_SLOT and the _PORT equivalents also
        FAPI_INF("Starting update");
        FAPI_TRY( mss::power_thermal::update_runtime_throttles (i_targets), "Error in p9_mss_eff_config_thermal" );
        FAPI_INF("finished update");

        //Set VDDR+VPP power curve values
        for ( const auto& l_mcs : i_targets )
        {
            if (mss::count_dimm(l_mcs) == 0)
            {
                continue;
            }

            uint16_t l_vddr_slope     [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
            uint16_t l_vddr_int       [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
            uint16_t l_total_slope    [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
            uint16_t l_total_int      [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
            uint32_t l_thermal_power  [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};

            FAPI_TRY( mss::power_thermal::get_power_attrs(l_mcs,
                      l_slope,
                      l_intercept,
                      l_thermal_power_limit,
                      l_vddr_slope,
                      l_vddr_int,
                      l_total_slope,
                      l_total_int,
                      l_thermal_power));

            FAPI_INF( "VDDR+VPP power curve slope is %d, int is %d, thermal_power is %d", l_total_slope[0][0], l_total_int[0][0],
                      l_thermal_power[0][0]);

            //Set the power curve attributes (TOTAL_PWR) to vpp+vdd power slope and intercept
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_TOTAL_PWR_SLOPE,
                                    l_mcs,
                                    l_total_slope));

            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_TOTAL_PWR_INTERCEPT,
                                    l_mcs,
                                    l_total_int));
        }

        //Run thermal throttles with the VDDR+VPP power curves
        FAPI_EXEC_HWP(l_rc, p9_mss_bulk_pwr_throttles, i_targets, mss::throttle_type::THERMAL);
        FAPI_TRY(l_rc, "Failed running p9_mss_bulk_pwr_throttles with THERMAL throttling in p9_mss_eff_config_thermal");
        //Update everything to worst case
        FAPI_TRY( mss::power_thermal::update_runtime_throttles (i_targets), "Error in p9_mss_eff_config_thermal" );

        //Done
        FAPI_INF( "End effective config thermal");

    fapi_try_exit:
        return fapi2::current_err;
    }
} //extern C
