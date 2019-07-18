/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_utils_to_throttle.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p9_mss_utils_to_throttle.C
/// @brief Sets throttles and power attributes for a given utilization value
/// TMGT will call this procedure to set the N address operations (commands)
/// allowed within a window of M DRAM clocks given the minimum dram data bus utilization.
////If input utilization is zero, then safemode values from MRW will be used
///

// *HWP HWP Owner: Andre A. Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <lib/shared/nimbus_defaults.H>
#include <p9_mss_utils_to_throttle.H>

// fapi2
#include <fapi2.H>

// mss lib
#include <lib/power_thermal/throttle.H>
#include <generic/memory/lib/utils/index.H>
#include <lib/utils/nimbus_find.H>
#include <lib/utils/mss_nimbus_conversions.H>
#include <lib/power_thermal/throttle.H>
#include <lib/mss_attribute_accessors.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/shared/mss_const.H>

using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;

extern "C"
{
    // TK:LRDIMM Update power/thermal/throttling

    ///
    /// @brief Sets number commands allowed within a given port databus utilization.
    /// @param[in] i_targets vector of MCS to set throttle attributes on
    /// @return FAPI2_RC_SUCCESS iff ok
    /// @note ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT will be set to worst case of all slots passed in
    /// @note inpute ATTR_MSS_DATABUS_UTIL and ATTR_MSS_MEM_WATT_TARGET
    /// @note output ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT, ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT, and ATTR_MSS_PORT_MAXPOWER
    /// @note Does not set runtime throttles or set registers to throttle values`
    ///
    fapi2::ReturnCode p9_mss_utils_to_throttle( const std::vector< fapi2::Target<TARGET_TYPE_MCS> >& i_targets )
    {
        FAPI_INF("Entering p9_mss_utils_to_throttle");

        std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCA> > l_exceeded_power;
        bool l_util_error = false;

        for( const auto& l_mcs : i_targets )
        {
            if (mss::count_dimm(l_mcs) == 0)
            {
                continue;
            }

            uint32_t l_input_databus_util [mss::PORTS_PER_MCS] = {};
            uint32_t l_max_databus_util  = {};
            uint32_t l_dram_clocks = 0;
            uint16_t l_safemode_throttle_per_port = 0;
            double l_calc_util_safemode = 0;

            uint16_t l_n_port[mss::PORTS_PER_MCS] = {};
            uint16_t l_n_slot[mss::PORTS_PER_MCS] = {};
            uint32_t l_max_power[mss::PORTS_PER_MCS] = {};

            FAPI_TRY( mss::mrw_mem_m_dram_clocks(l_dram_clocks) );

            //Util attribute set by OCC
            FAPI_TRY( mss::databus_util(l_mcs, l_input_databus_util) );
            FAPI_TRY( mss::mrw_max_dram_databus_util(l_max_databus_util));

            for( const auto& l_mca : mss::find_targets<TARGET_TYPE_MCA>(l_mcs) )
            {
                FAPI_INF("Input databus utilization for %s is %d",
                         mss::c_str(l_mca),
                         l_input_databus_util[mss::index(l_mca)]);

                const auto l_port_num = mss::index(l_mca );

                if (mss::count_dimm(l_mca) == 0)
                {
                    continue;
                }

                // If input utilization is zero, use mrw safemode throttle values for utilization
                bool l_safemode = false;

                if (l_input_databus_util[l_port_num] == 0)
                {
                    FAPI_TRY(mss::mrw_safemode_mem_throttled_n_commands_per_port(l_safemode_throttle_per_port),
                             "Error in getting safemode throttles" );
                    FAPI_TRY( mss::power_thermal::calc_util_from_throttles(l_safemode_throttle_per_port, l_dram_clocks,
                              l_calc_util_safemode),
                              "%s Error calculating utilization from safemode throttle %d and mem clocks %d",
                              mss::c_str(l_mca),
                              l_safemode_throttle_per_port,
                              l_dram_clocks);
                    FAPI_INF( "%s Safemode throttles being used since input util is zero:  Using N=%d, Utilization %f",
                              mss::c_str(l_mca),
                              l_safemode_throttle_per_port,
                              l_calc_util_safemode);
                    l_safemode = true;
                    l_input_databus_util[l_port_num] = l_calc_util_safemode;
                }

                using TT = mss::power_thermal::throttle_traits<>;
                const uint64_t l_min_util = TT::MIN_UTIL;
                //Make sure MIN_UTIL <= input_utilization <= max_utilization
                const uint32_t l_databus_util = ( l_input_databus_util[l_port_num] >= l_min_util) ?
                                                std::min(l_input_databus_util[l_port_num], l_max_databus_util)
                                                : l_min_util;

                // Error if utilization is less than MIN_UTIL
                // Don't exit, let HWP finish and return error at end
                if (l_input_databus_util[l_port_num] < l_min_util)
                {
                    FAPI_ASSERT_NOEXIT( false,
                                        fapi2::MSS_MIN_UTILIZATION_ERROR()
                                        .set_INPUT_UTIL_VALUE(l_input_databus_util[l_port_num])
                                        .set_MIN_UTIL_VALUE(l_min_util),
                                        "%s Input utilization (%d) less than minimum utilization allowed (%d)",
                                        mss::c_str(l_mca), l_input_databus_util[l_port_num], l_min_util);
                    l_util_error = true;
                }

                //Make a throttle object in order to calculate the port power
                fapi2::ReturnCode l_rc;

                mss::power_thermal::throttle<> l_throttle (l_mca, l_rc);
                FAPI_TRY(l_rc, "Error calculating mss::power_thermal::throttle constructor in p9_mss_utils_to_throttles");

                FAPI_INF( "%s MRW dram clock window: %d, databus utilization: %d",
                          mss::c_str(l_mca),
                          l_dram_clocks,
                          l_databus_util);

                FAPI_TRY( l_throttle.calc_slots_and_power(l_databus_util));

                FAPI_INF( "%s Calculated N commands per port %d, per slot %d, commands per dram clock window %d, maxpower is %d",
                          mss::c_str(l_mca),
                          l_throttle.iv_n_port,
                          l_throttle.iv_n_slot,
                          l_dram_clocks,
                          l_throttle.iv_calc_port_maxpower);

                l_n_slot[l_port_num] = (l_safemode) ? l_safemode_throttle_per_port : l_throttle.iv_n_slot;
                l_n_port[l_port_num] = (l_safemode) ? l_safemode_throttle_per_port : l_throttle.iv_n_port;
                l_max_power[l_port_num] = l_throttle.iv_calc_port_maxpower;
            }// end for

            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_PORT_MAXPOWER,
                                    l_mcs,
                                    l_max_power) );
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT,
                                    l_mcs,
                                    l_n_slot) );
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT,
                                    l_mcs,
                                    l_n_port) );
        }

        // Equalize throttles to prevent variable performance
        // Note that we don't do anything with any MCA that exceed the power limit here, as we don't have an input power limit to go from
        FAPI_TRY( mss::power_thermal::equalize_throttles (i_targets, mss::throttle_type::POWER, l_exceeded_power));

        // Return a failing RC code if we had any input utilization values less than MIN_UTIL
        if (l_util_error)
        {
            fapi2::current_err = fapi2::FAPI2_RC_FALSE;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

}// extern C
