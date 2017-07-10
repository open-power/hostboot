/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_eff_config_thermal.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <vector>
#include <p9_mss_eff_config_thermal.H>
#include <p9_mss_bulk_pwr_throttles.H>
#include <lib/power_thermal/throttle.H>
#include <lib/power_thermal/decoder.H>
#include <lib/dimm/kind.H>
#include <lib/utils/count_dimm.H>
#include <lib/shared/mss_const.H>
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

        FAPI_INF("Start effective config thermal");

        uint16_t l_vddr_slope     [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
        uint16_t l_vddr_int       [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
        uint16_t l_total_slope    [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
        uint16_t l_total_int      [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
        uint32_t l_thermal_power  [mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
        fapi2::ReturnCode l_rc;

        //Gotta convert into fapi2::buffers. Not very elegant
        //Do it here or in the encode and decode functions
        //Not that pretty :(
        std::vector< uint64_t > l_tslope (mss::power_thermal::SIZE_OF_POWER_CURVES_ATTRS, 0);
        std::vector< uint64_t > l_tintercept (mss::power_thermal::SIZE_OF_POWER_CURVES_ATTRS, 0);
        std::vector< uint64_t > l_tthermal_power_limit (mss::power_thermal::SIZE_OF_THERMAL_ATTR, 0);

        std::vector<fapi2::buffer< uint64_t>> l_slope = {};
        std::vector<fapi2::buffer< uint64_t>> l_intercept = {};
        std::vector<fapi2::buffer< uint64_t>> l_thermal_power_limit = {};

        //Get the vectors of power curves and thermal power limits to convert to buffers
        FAPI_TRY( mss::mrw_pwr_slope (l_tslope.data()), "Error in p9_mss_eff_config_thermal");
        FAPI_TRY( mss::mrw_pwr_intercept (l_tintercept.data()), "Error in p9_mss_eff_config_thermal" );
        FAPI_TRY( mss::mrw_thermal_memory_power_limit (l_tthermal_power_limit.data()), "Error in p9_mss_eff_config_thermal" );
        FAPI_TRY( mss::power_thermal::set_runtime_m_and_watt_limit(i_targets), "Error in p9_mss_eff_config_thermal");

        for (size_t i = 0; i < mss::power_thermal::SIZE_OF_POWER_CURVES_ATTRS; ++i)
        {
            for (const auto l_cur : l_tslope)
            {
                fapi2::buffer<uint64_t> l_slope_buf = l_cur;

                if (l_slope_buf != 0)
                {
                    l_slope.push_back(l_slope_buf);
                }
            }

            for (auto l_cur : l_tintercept)
            {
                fapi2::buffer<uint64_t> l_intercept_buf = l_cur;

                if (l_intercept_buf != 0)
                {
                    l_intercept.push_back(l_intercept_buf);
                }
            }

            for (auto l_cur : l_tthermal_power_limit)
            {
                fapi2::buffer<uint64_t> l_tthermal_buf = l_cur;

                if (l_tthermal_buf != 0)
                {
                    l_thermal_power_limit.push_back(l_tthermal_buf);
                }
            }
        }

        //Restore runtime_throttles from safemode setting
        //Decode and set power curve attributes at the same time
        for (const auto& l_mcs : i_targets )
        {
            //Not doing any work if there are no dimms installed
            if (mss::count_dimm(l_mcs) == 0)
            {
                continue;
            }

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
