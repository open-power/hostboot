/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_mss_utils_to_throttle.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
/// @file p10_mss_utils_to_throttle.C
/// @brief Sets throttles and power attributes for a given utilization value
/// @note TMGT will call this procedure to set the N address operations (commands)
/// allowed within a window of M DRAM clocks given the minimum dram data bus utilization.
//// If input utilization is zero, then safemode values from MRW will be used
///

// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <p10_mss_utils_to_throttle.H>
#include <lib/shared/exp_consts.H>
#include <mss_explorer_attribute_getters.H>
#include <lib/power_thermal/exp_throttle.H>
#include <lib/power_thermal/ody_throttle.H>
#include <lib/power_thermal/ody_throttle_traits.H>

// fapi2
#include <fapi2.H>

extern "C"
{
///
/// @brief Determines throttle and power values for a given port databus utilization.
/// @param[in] i_targets vector of OCMB_CHIPs to set throttle and power attributes on
/// @return FAPI2_RC_SUCCESS iff ok
/// @note ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT/PORT will be set to worst case of all slots/ports passed in
/// @note input ATTR_EXP_DATABUS_UTIL
/// @note output ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT, ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT, and ATTR_EXP_PORT_MAXPOWER
/// @note Does not set runtime throttles or set registers to throttle values
/// @note called by firmware (TMGT)
///
    fapi2::ReturnCode p10_mss_utils_to_throttle(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>& i_targets)
    {
        FAPI_INF("Entering p10_mss_utils_to_throttle");

        std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>> l_exceeded_power;
        bool l_util_error = false;

        // NOTE: This will hold the DRAM GEN of the last DIMM target processed for use with equalize_throttles_helper
        // This is ok because we do not allow mixing of DRAM generation within a power grouping
        uint8_t l_dram_gen = 0;

        for (const auto& l_ocmb : i_targets)
        {
            if (mss::count_dimm(l_ocmb) == 0)
            {
                FAPI_INF("Skipping %s because it has no DIMM targets", mss::c_str(l_ocmb));
                continue;
            }

            uint32_t l_max_databus_util = 0;
            uint32_t l_dram_clocks = 0;
            uint32_t l_safemode_util = 0;
            uint32_t l_calc_util = 0;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   l_dram_clocks));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MAX_DRAM_DATABUS_UTIL, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   l_max_databus_util));

            for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(l_ocmb))
            {
                fapi2::ReturnCode l_rc;
                uint32_t l_input_databus_util = 0;
                bool l_safemode = false;
                uint32_t l_safemode_throttle_per_port = 0;

                for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port))
                {
                    FAPI_TRY(mss::attr::get_dram_gen(l_dimm, l_dram_gen));
                    break;
                }

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_SAFEMODE_DRAM_DATABUS_UTIL, l_port, l_safemode_util));

                // TODO: Zen:MST-1818 Will need to call MC-specific version of this once BL16 is supported
                l_safemode_throttle_per_port = mss::power_thermal::calc_n_from_dram_util(l_safemode_util, l_dram_clocks);

                // Util attribute set by OCC
                FAPI_TRY( mss::attr::get_databus_util(l_port, l_input_databus_util) );

                FAPI_INF("Input databus utilization for %s is %d",
                         mss::c_str(l_port),
                         l_input_databus_util);

                // If input utilization is zero, use mrw safemode throttle values for utilization
                // else make sure we're within our maximum utilization limit
                mss::power_thermal::calc_utilization(l_port,
                                                     l_input_databus_util,
                                                     l_safemode_util,
                                                     l_max_databus_util,
                                                     l_calc_util,
                                                     l_util_error,
                                                     l_safemode);

                // Error if utilization is less than the safemode utilization
                // Don't exit, let HWP finish and return error at end
                FAPI_ASSERT_NOEXIT( !l_util_error,
                                    fapi2::MSS_MIN_UTILIZATION_ERROR()
                                    .set_INPUT_UTIL_VALUE(l_input_databus_util)
                                    .set_MIN_UTIL_VALUE(l_safemode_util),
                                    "%s Input utilization (%d) less than minimum utilization allowed (%d)",
                                    mss::c_str(l_port), l_input_databus_util, l_safemode_util);

                if (l_dram_gen == fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4)
                {
                    // Make a throttle object in order to calculate the port power
                    mss::power_thermal::throttle<mss::mc_type::EXPLORER> l_throttle(l_port, l_rc);
                    FAPI_TRY(l_rc, "%s Error calculating mss::power_thermal::throttle constructor in p10_mss_utils_to_throttles",
                             mss::c_str(l_port));

                    FAPI_TRY( l_throttle.calc_slots_and_power( l_calc_util ) );

                    FAPI_INF( "%s Calculated N commands per port %d, per slot %d, commands per dram clock window %d, maxpower is %d",
                              mss::c_str(l_port),
                              l_throttle.iv_n_port,
                              l_throttle.iv_n_slot,
                              l_throttle.iv_databus_port_max,
                              l_throttle.iv_calc_port_maxpower);

                    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_EXP_PORT_MAXPOWER, l_port, l_throttle.iv_calc_port_maxpower));
                    FAPI_TRY(FAPI_ATTR_SET_CONST(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port,
                                                 (l_safemode) ? l_safemode_throttle_per_port : l_throttle.iv_n_slot));
                    FAPI_TRY(FAPI_ATTR_SET_CONST(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_port,
                                                 (l_safemode) ? l_safemode_throttle_per_port : l_throttle.iv_n_port));
                }
                else
                {
                    // Make a throttle object in order to calculate the port power
                    mss::power_thermal::throttle<mss::mc_type::ODYSSEY> l_throttle(l_port, l_rc);
                    FAPI_TRY(l_rc, "%s Error calculating mss::power_thermal::throttle constructor in p10_mss_utils_to_throttles",
                             mss::c_str(l_port));

                    FAPI_TRY( l_throttle.calc_slots_and_power( l_calc_util ) );

                    FAPI_INF( "%s Calculated N commands per port %d, per slot %d, commands per dram clock window %d, maxpower is %d",
                              mss::c_str(l_port),
                              l_throttle.iv_n_port,
                              l_throttle.iv_n_slot,
                              l_throttle.iv_databus_port_max,
                              l_throttle.iv_calc_port_maxpower);

                    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_EXP_PORT_MAXPOWER, l_port, l_throttle.iv_calc_port_maxpower));
                    FAPI_TRY(FAPI_ATTR_SET_CONST(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port,
                                                 (l_safemode) ? l_safemode_throttle_per_port : l_throttle.iv_n_slot));
                    FAPI_TRY(FAPI_ATTR_SET_CONST(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_port,
                                                 (l_safemode) ? l_safemode_throttle_per_port : l_throttle.iv_n_port));
                }
            } // ports

            // Combine our port throttles if we're DDR5
            if (l_dram_gen == fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5)
            {
                // This HWP is used by OCC to determine throttle value to use for a memory over temperature condition
                // For Odyssey (DDR5) call using THERMAL throttling so throttle values are not optimized
                // OCC only uses Nslot to throttle due to over temperature, so its easier to have this HWP
                //   provide unoptimized throttle values instead of getting OCC to use both Nslot and Nport
                //   (if optimized ocmb throttle values are used) when over temperture throttling is needed
                FAPI_TRY(mss::power_thermal::combine_port_throttles(l_ocmb, mss::throttle_type::THERMAL));
            }

        } // ocmbs

        // Equalize throttles to prevent variable performance
        // Note that we don't do anything with any port that exceed the power limit here, as we don't have an input power limit to go from
        if (l_dram_gen == fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4)
        {
            FAPI_TRY(mss::power_thermal::equalize_throttles_helper<mss::mc_type::EXPLORER>(i_targets,
                     mss::throttle_type::POWER,
                     l_exceeded_power));
        }
        else
        {
            // This HWP is used by OCC to determine throttle value to use for a memory over temperature condition
            // For Odyssey (DDR5) call using THERMAL throttling so throttle values are not optimized
            // OCC only uses Nslot to throttle due to over temperature, so its easier to have this HWP
            //   provide unoptimized throttle values instead of getting OCC to use both Nslot and Nport
            //   (if optimized ocmb throttle values are used) when over temperture throttling is needed
            FAPI_TRY(mss::power_thermal::equalize_throttles_helper<mss::mc_type::ODYSSEY>(i_targets,
                     mss::throttle_type::THERMAL,
                     l_exceeded_power));
        }

        // Return a failing RC code if we had any input utilization values less than MIN_UTIL
        if (l_util_error)
        {
            fapi2::current_err = fapi2::RC_MSS_MIN_UTILIZATION_ERROR;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
}// extern C
