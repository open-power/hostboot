/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_bulk_pwr_throttles.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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


/// @file p9c_mss_bulk_pwr_throttles.C
/// @brief  Sets the throttle attributes based on a power limit for the dimms on the channel pair
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Mike Pardeik <pardeik@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
///

// DESCRIPTION:
// The purpose of this procedure is to set the throttle attributes based on a
// power limit for the dimms on the channel pair
// At the end, output attributes will be updated with throttle values that will
// have dimms at or below the limit
// NOTE:  ISDIMMs and CDIMMs are handled differently
//   ISDIMMs use a power per DIMM for the thermal power limit from the MRW
//   CDIMM will use power per CDIMM (power for all virtual dimms) for the
//    thermal power limit from the MRW
// Plan is to have ISDIMM use the per-slot throttles (thermal throttles) or
//  per-mba throttles (power throttles), and CDIMM to use the per-chip throttles
// Note that throttle_n_per_mba takes on different meanings depending on how
// cfg_nm_per_slot_enabled is set
//   Can be slot0/slot1 OR slot0/MBA throttling
// Note that throttle_n_per_chip takes on different meaning depending on how
// cfg_count_other_mba_dis is set
//  Can be per-chip OR per-mba throttling
// These inits here are done in mss_scominit
// ISDIMM:  These registers need to be setup to these values, will be able to
//  do per slot or per MBA throttling
//   cfg_nm_per_slot_enabled = 1
//   cfg_count_other_mba_dis = 1
// CDIMM:  These registers need to be setup to these values, will be able to
//  do per mba or per chip throttling
//   cfg_nm_per_slot_enabled = 0
//   cfg_count_other_mba_dis = 0

//------------------------------------------------------------------------------
//  My Includes
//------------------------------------------------------------------------------
#include <p9c_mss_bulk_pwr_throttles.H>
#include <generic/memory/lib/utils/c_str.H>
#include <dimmConsts.H>
//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

extern "C" {
    /// @brief mss_bulk_pwr_throttles(): This function determines the throttle values power limit for the dimms on the channel pair
    /// @param[in]   const fapi2::Target<fapi2::TARGET_TYPE_MBA> & i_target_mba:  MBA Target<fapi2::TARGET_TYPE_MBA> passed in
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode p9c_mss_bulk_pwr_throttles(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {
        FAPI_INF("*** Running mss_bulk_pwr_throttles ***");
        float l_idle_util = 0; // in percent
        float l_min_util = 1; // in percent
        // These are the constants to use for ISDIMM power/throttle support
        // Note that these are hardcoded and ISDIMMs will not use power curves
        // No Throttling if available power is >= ISDIMM_MAX_DIMM_POWER
        // Throttle when ISDIMM_MIN_DIMM_POWER <= available power <= ATTR_MSS_MEM_WATT_TARGET
        // Throttle value will be maximum throttle * ISDIMM_MEMORY_THROTTLE_PERCENT
        constexpr uint32_t ISDIMM_MAX_DIMM_POWER = 1200;  // cW, max ISDIMM power for no throttling
        constexpr uint32_t ISDIMM_MIN_DIMM_POWER = 800;   // cW, min ISDIMM power for throttling
        constexpr uint8_t ISDIMM_MEMORY_THROTTLE_PERCENT =
            65;  // percent, throttle impact when limit is between min and max power.  A value of 0 would be for no throttle impact.

        uint32_t l_total_power_slope_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_total_power_int_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_dimm_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_port = 0;
        uint8_t l_dimm = 0;
        float l_dimm_power_array_idle[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        float l_dimm_power_array_max[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        float l_channel_power_array_idle[MAX_PORTS_PER_MBA] = {0};
        float l_max_util = 0;
        float l_channel_power_array_max[MAX_PORTS_PER_MBA] = {0};
        uint8_t l_power_curve_percent_uplift = 0;
        uint8_t l_power_curve_percent_uplift_idle = 0;
        uint32_t l_max_dram_databus_util = 0;
        uint8_t l_num_mba_with_dimms = 0;
        uint8_t l_custom_dimm = 0;
        uint32_t l_throttle_d = 0;
        float l_channel_pair_power_idle = 0;
        float l_channel_pair_power_max = 0;
        uint32_t l_channel_pair_watt_target = 0;
        float l_utilization = 0;
        uint32_t l_number_of_dimms = 0;
        float l_channel_power_slope = 0;
        float l_channel_power_intercept = 0;
        uint32_t l_throttle_n_per_mba = 0;
        uint32_t l_throttle_n_per_chip = 0;
        uint32_t l_channel_pair_power = 0;
        uint32_t l_runtime_throttle_n_per_mba = 0;
        uint32_t l_runtime_throttle_n_per_chip = 0;
        uint8_t l_dram_gen = 0;

        // get input attributes
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba,  l_custom_dimm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_MAX_DRAM_DATABUS_UTIL,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_max_dram_databus_util));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_MEM_THROTTLE_DENOMINATOR, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_throttle_d));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_MEM_WATT_TARGET,
                               i_target_mba, l_channel_pair_watt_target));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA,
                               i_target_mba, l_runtime_throttle_n_per_mba));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP,
                               i_target_mba, l_runtime_throttle_n_per_chip));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN,
                               i_target_mba, l_dram_gen));

        // other attributes for custom dimms to get
        if (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT,
                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_power_curve_percent_uplift));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT_IDLE,
                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_power_curve_percent_uplift_idle));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_SLOPE,
                                   i_target_mba, l_total_power_slope_array));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_INT,
                                   i_target_mba, l_total_power_int_array));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM,
                                   i_target_mba, l_dimm_ranks_array));
        }

        // Maximum theoretical data bus utilization (percent of max) (for ceiling)
        // Comes from MRW value in c% - convert to %
        l_max_util = (float) l_max_dram_databus_util / 100;

        // determine the dimm power
        // For custom dimms, use the VPD power curve data
        if (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
        {
            // get number of mba's with dimms
            // Get Centaur target for the given MBA
            const auto l_target_chip = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
            // Get MBA targets from the parent chip centaur
            const auto l_target_mba_array = l_target_chip.getChildren<fapi2::TARGET_TYPE_MBA>();
            l_num_mba_with_dimms = 0;

            for (const auto& l_mba : l_target_mba_array)
            {
                const auto l_target_dimm_array = l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

                if (l_target_dimm_array.size() > 0)
                {
                    l_num_mba_with_dimms++;
                }
            }

            // add up the power from all dimms for this MBA (across both channels)
            // for IDLE (utilization=0) and maximum utilization
            l_channel_pair_power_idle = 0;
            l_channel_pair_power_max = 0;

            for (l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
            {
                l_channel_power_array_idle[l_port] = 0;
                l_channel_power_array_max[l_port] = 0;

                for (l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++)
                {
                    // default dimm power is zero (used for dimms that are not physically present)
                    l_dimm_power_array_idle[l_port][l_dimm] = 0;
                    l_dimm_power_array_max[l_port][l_dimm] = 0;

                    // See if there are any ranks present on the dimm (configured or deconfigured)
                    if (l_dimm_ranks_array[l_port][l_dimm] > 0)
                    {
                        l_dimm_power_array_idle[l_port][l_dimm] = l_dimm_power_array_idle[l_port][l_dimm] +
                                (l_idle_util / 100 * l_total_power_slope_array[l_port][l_dimm]) + l_total_power_int_array[l_port][l_dimm];
                        l_dimm_power_array_max[l_port][l_dimm] = l_dimm_power_array_max[l_port][l_dimm] + (l_max_util / 100 *
                                l_total_power_slope_array[l_port][l_dimm]) + l_total_power_int_array[l_port][l_dimm];
                    }

                    // Include any system uplift here too
                    if (l_dimm_power_array_idle[l_port][l_dimm] > 0)
                    {
                        l_dimm_power_array_idle[l_port][l_dimm] =
                            l_dimm_power_array_idle[l_port][l_dimm] *
                            (1 + (float)l_power_curve_percent_uplift_idle / 100);
                    }

                    if (l_dimm_power_array_max[l_port][l_dimm] > 0)
                    {
                        l_dimm_power_array_max[l_port][l_dimm] =
                            l_dimm_power_array_max[l_port][l_dimm] *
                            (1 + (float)l_power_curve_percent_uplift / 100);
                    }

                    // calculate channel power by adding up the power of each dimm
                    l_channel_power_array_idle[l_port] = l_channel_power_array_idle[l_port] + l_dimm_power_array_idle[l_port][l_dimm];
                    l_channel_power_array_max[l_port] = l_channel_power_array_max[l_port] + l_dimm_power_array_max[l_port][l_dimm];
                    FAPI_DBG("[P%d:D%d][CH Util %4.2f/%4.2f][Slope:Int %d:%d][UpliftPercent idle/max %d/%d)][Power min/max %4.2f/%4.2f cW]",
                             l_port, l_dimm, l_idle_util, l_max_util, l_total_power_slope_array[l_port][l_dimm],
                             l_total_power_int_array[l_port][l_dimm],
                             l_power_curve_percent_uplift_idle, l_power_curve_percent_uplift, l_dimm_power_array_idle[l_port][l_dimm],
                             l_dimm_power_array_max[l_port][l_dimm]);
                }

                FAPI_DBG("[P%d][CH Util %4.2f/%4.2f][Power %4.2f/%4.2f cW]", l_port, l_min_util, l_max_util,
                         l_channel_power_array_idle[l_port], l_channel_power_array_max[l_port]);
                l_channel_pair_power_idle = l_channel_pair_power_idle + l_channel_power_array_idle[l_port];
                l_channel_pair_power_max = l_channel_pair_power_max + l_channel_power_array_max[l_port];
            }

            // calculate the slope/intercept values from power values just calculated above
            l_channel_power_slope = (l_channel_pair_power_max - l_channel_pair_power_idle) / ( (l_max_util / 100) -
                                    (l_idle_util / 100) );
            l_channel_power_intercept = l_channel_pair_power_idle;

            // calculate the utilization needed to be under power limit
            l_utilization = 0;

            if (l_channel_pair_watt_target > l_channel_power_intercept)
            {
                l_utilization = (l_channel_pair_watt_target - l_channel_power_intercept) / l_channel_power_slope * 100;

                if (l_utilization > l_max_util)
                {
                    l_utilization = l_max_util;
                }
            }

            // Calculate the NperChip and NperMBA Throttles
            l_throttle_n_per_chip = int((l_utilization / 100 * l_throttle_d / 4) * l_num_mba_with_dimms);

            if (l_throttle_n_per_chip > (l_max_util / 100 * l_throttle_d / 4) )
            {
                l_throttle_n_per_mba = int((l_max_util / 100 * l_throttle_d / 4));
            }
            else
            {
                l_throttle_n_per_mba = l_throttle_n_per_chip;
            }

            // Calculate the channel power at the utilization determined
            l_channel_pair_power = int(l_utilization / 100 * l_channel_power_slope + l_channel_power_intercept);

            FAPI_DBG("[Channel Pair Power min/max %4.2f/%4.2f cW][Slope/Intercept %4.2f/%4.2f cW][Utilization Percent %4.2f, Power %d cW]",
                     l_channel_pair_power_idle, l_channel_pair_power_max, l_channel_power_slope, l_channel_power_intercept, l_utilization,
                     l_channel_pair_power);
        }

        // for non custom dimms, use hardcoded values
        // If power limit is at or above max power, use unthrottled settings
        // If between min and max power, use a static throttle point
        // If below min power, return an error
        else
        {
            // get number of dimms attached to this mba
            const auto l_target_dimm_array = i_target_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();
            l_number_of_dimms = l_target_dimm_array.size();

            // ISDIMMs, set to a value of one since throttles are handled on a per MBA basis
            l_num_mba_with_dimms = 1;

            // MBA Power Limit is higher than dimm power, run unthrottled
            if (l_channel_pair_watt_target >= (ISDIMM_MAX_DIMM_POWER * l_number_of_dimms))
            {
                l_utilization = l_max_util;
                l_channel_pair_power = ISDIMM_MAX_DIMM_POWER * l_number_of_dimms;
            }
            else if (l_channel_pair_watt_target >= (ISDIMM_MIN_DIMM_POWER * l_number_of_dimms))
            {
                if (ISDIMM_MEMORY_THROTTLE_PERCENT > 99)
                {
                    l_utilization = l_min_util;
                }
                else
                {
                    l_utilization = l_max_util * (1 - (float)ISDIMM_MEMORY_THROTTLE_PERCENT / 100);
                }

                l_channel_pair_power = ISDIMM_MIN_DIMM_POWER * l_number_of_dimms;
            }
            else
            {
                // error case, available power less than allocated minimum dimm power
                l_utilization = 0;
                l_channel_pair_power = ISDIMM_MIN_DIMM_POWER * l_number_of_dimms;
            }

            l_throttle_n_per_mba = int(l_utilization / 100 * l_throttle_d / 4);
            l_throttle_n_per_chip = l_throttle_n_per_mba;

            FAPI_DBG("[Power/DIMM min/max %d/%d cW][Utilization Percent %4.2f][Number of DIMMs %d]", ISDIMM_MIN_DIMM_POWER,
                     ISDIMM_MAX_DIMM_POWER, l_utilization, l_number_of_dimms);

        }

        // adjust the throttles to minimum utilization if needed
        if (l_utilization < l_min_util)
        {
            l_throttle_n_per_mba = int(l_min_util / 100 * l_throttle_d / 4);
            l_throttle_n_per_chip = l_throttle_n_per_mba * l_num_mba_with_dimms;
        }

        // ensure that N throttle values are not zero, if so set to lowest values possible
        if ( (l_throttle_n_per_mba == 0) || (l_throttle_n_per_chip == 0))
        {
            l_throttle_n_per_mba = 1;
            l_throttle_n_per_chip = l_throttle_n_per_mba * l_num_mba_with_dimms;
        }

        // for better custom dimm performance for DDR4, set the per mba throttle to the per chip throttle
        // Not planning on doing this for DDR3
        if ( (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
             && (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES) )
        {
            l_throttle_n_per_mba = l_throttle_n_per_chip;
        }

        // adjust the throttles to the MRW thermal limit throttles (ie.  thermal/power limit less than available power)
        if ( (l_throttle_n_per_mba > l_runtime_throttle_n_per_mba) ||
             (l_throttle_n_per_chip > l_runtime_throttle_n_per_chip) )
        {
            FAPI_DBG("Throttles [%d/%d/%d] will be limited by power/thermal limit [%d/%d/%d].", l_throttle_n_per_mba,
                     l_throttle_n_per_chip, l_throttle_d, l_runtime_throttle_n_per_mba, l_runtime_throttle_n_per_chip, l_throttle_d);

            if (l_throttle_n_per_mba > l_runtime_throttle_n_per_mba)
            {
                l_throttle_n_per_mba = l_runtime_throttle_n_per_mba;
            }

            if (l_throttle_n_per_chip > l_runtime_throttle_n_per_chip)
            {
                l_throttle_n_per_chip = l_runtime_throttle_n_per_chip;
            }

        }

        // Calculate out the utilization at the final throttle settings
        l_utilization = (float)l_throttle_n_per_chip * 4 / l_throttle_d / l_num_mba_with_dimms * 100;

        // Calculate out the utilization at this new utilization setting for custom dimms
        // does not matter for non custom dimms since those do not use power curves
        if (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
        {
            l_channel_pair_power = int(l_utilization / 100 * l_channel_power_slope + l_channel_power_intercept);
        }

        FAPI_INF("[Available Channel Pair Power %d cW][UTIL %4.2f][Channel Pair Power %d cW]", l_channel_pair_watt_target,
                 l_utilization, l_channel_pair_power);
        FAPI_INF("[Throttles %d/%d/%d]", l_throttle_n_per_mba, l_throttle_n_per_chip, l_throttle_d);

        // Update output attributes
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA,
                               i_target_mba, l_throttle_n_per_mba));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP,
                               i_target_mba, l_throttle_n_per_chip));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_DENOMINATOR,
                               i_target_mba, l_throttle_d));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_CHANNEL_PAIR_MAXPOWER,
                               i_target_mba, l_channel_pair_power));

        // Check to see if there is not enough available power at l_min_util or higher
        if (l_channel_pair_power > l_channel_pair_watt_target)
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_NOT_ENOUGH_AVAILABLE_DIMM_POWER().
                        set_PAIR_POWER(l_channel_pair_power).
                        set_PAIR_WATT_TARGET(l_channel_pair_watt_target).
                        set_MEM_MBA(i_target_mba),
                        "Not enough available memory power [Channel Pair Power %d/%d cW]", l_channel_pair_power, l_channel_pair_watt_target);
        }

        FAPI_INF("*** mss_bulk_pwr_throttles COMPLETE ***");
    fapi_try_exit:
        return fapi2::current_err;
    }
} //end extern C


