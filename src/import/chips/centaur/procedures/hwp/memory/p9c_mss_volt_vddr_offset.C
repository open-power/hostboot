/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_volt_vddr_offset.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file p9c_mss_mss_volt_vddr_offset.C
/// @brief Creates VDDR voltage offsets
///
/// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
/// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB

// This procedure takes a vector of Centaurs behind the vddr voltage domain,
// reads in supported DIMM voltages from SPD and determines optimal
//  voltage bin for the DIMM voltage domain.
// supported voltage bins:  DDR3 1.35V DDR4 1.20V


//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi2.H>
#include <p9c_mss_volt_vddr_offset.H>
#include <mss_dynamic_vid_utils.H>
#include <lib/utils/cumulus_find.H>
#include <generic/memory/lib/utils/count_dimm.H>

extern "C"
{
///
/// @brief mss_volt_vddr_offset procedure. Determines operating vddr voltage for dimms behind a vddr voltage domain
/// @param[in] i_targets  Reference to vector of Centaur Targets in a particular vddr power domain
/// @return ReturnCode
///
    fapi2::ReturnCode p9c_mss_volt_vddr_offset(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>>& i_targets)
    {
        // If we're passed an empty vector, exit out
        if(i_targets.empty())
        {
            FAPI_INF("Empty vector of targets passed to VDDR offset. Exiting..");
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Constexpr's to pretty up some of the code
        constexpr double PERCENT = 100;
        constexpr uint64_t ATTR_VOLT_CONVERSION = 10000;
        // Note: per the power/thermal team, 5625 is the utilization for the max DMI speed at 1600 memory frequency
        // Please note, if dynamic VID is needed on all P9 centaur systems, then this value will become an MRW attribute
        // Currently, dynamic voltage is only needed on custom DIMM systems, if it is needed on ISDIMM systems, then the data bus utilization code will need to change:
        // ISDIMM systems could hypothetically have DIMM's on only one given MBA. In that case the data bus utilization will increase. We should then just look into using the attribute.
        constexpr uint64_t DATA_BUS_UTIL = 5625;

        // Declares variables
        fapi2::ReturnCode l_bad_vpd_rc = fapi2::FAPI2_RC_SUCCESS;
        uint32_t l_vpd_master_power_slope = 0;
        uint32_t l_vpd_master_power_intercept = 0;
        uint32_t l_volt_util_active = 0;
        uint32_t l_volt_util_inactive = 0;
        uint32_t l_volt_slope = 0;
        uint32_t l_volt_intercept = 0;
        uint32_t l_good_master_power_slope = 0;
        uint32_t l_good_master_power_intercept = 0;
        uint32_t l_num_dimms_to_add = 0;
        uint32_t l_var_power_on_vddr = 0;
        uint32_t l_num_logical_dimms = 0;
        uint8_t l_dram_gen = 0;
        uint8_t l_enable = 0;
        uint8_t l_is_functional = 0;
        uint8_t l_ec_disable_attr = 0;
        uint8_t l_percent_uplift = 0;
        uint8_t l_percent_uplift_idle = 0;
        uint32_t l_vddr_max_limit_mv = 0;
        uint32_t l_param_vddr_voltage_mv = 0;
        uint32_t l_data_bus_util = 0;

        // Gets and checks the DRAM generation and centaur configuration
        // Note: Plug rules checks haven't been done up to this point
        // The below checks that all DRAM have the same generation on this VDDR rail and returns the valid DRAM generation
        FAPI_TRY(check_dram_gen_plug(i_targets, l_dram_gen));

        // Voltage should not be updated if the disable is set
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_VDDR_OFFSET_ENABLE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_enable));

        // Attribute is disabled, just exit
        if(l_enable == fapi2::ENUM_ATTR_MSS_MRW_VDDR_OFFSET_ENABLE_DISABLE)
        {
            FAPI_INF("ATTR_MSS_MRW_VDDR_OFFSET_ENABLE is set to be disabled. Exiting....., %d", l_enable);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Checks if any MC's have the disable attribute set, if so, set to MSS_VOLT value
        // If not, continue with the code
        for(const auto& l_chip : i_targets)
        {
            //reads in the attribute
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_DISABLE_VDDR_DYNAMIC_VID, l_chip, l_ec_disable_attr));

            // Disable is set, read mss_volt and exit out of the code
            if(l_ec_disable_attr)
            {
                break;
            }
        }

        // Disable is set, sets the l_enable attribute based upon MSS_VOLT attribute
        if(l_ec_disable_attr)
        {
            FAPI_INF("Found Centaur with EC disable attribute set. Setting ATTR_CEN_MSS_VDDR_OFFSET based upon ATTR_CEN_MSS_VOLT");

            //sets the output attributes
            for(const auto& l_chip : i_targets)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VOLT, l_chip, l_param_vddr_voltage_mv));
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_VDDR_OFFSET, l_chip, l_param_vddr_voltage_mv));
            }//end for

            return  fapi2::FAPI2_RC_SUCCESS;
        }

        // Gets the attributes and computes var_power_on based upon whether the DRAM type is DDR3 or DDR4
        if(l_dram_gen == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_DDR3_VDDR_SLOPE, i_targets[0], l_volt_slope));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_DDR3_VDDR_INTERCEPT, i_targets[0], l_volt_intercept));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_DDR3_VDDR_MAX_LIMIT, i_targets[0], l_vddr_max_limit_mv));
        }
        // DDR4
        else
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_DDR4_VDDR_SLOPE, i_targets[0], l_volt_slope));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_DDR4_VDDR_INTERCEPT, i_targets[0], l_volt_intercept));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_DDR4_VDDR_MAX_LIMIT, i_targets[0], l_vddr_max_limit_mv));
        }

        // Gets the data bus utilization and picks the lower of the two values
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MAX_DRAM_DATABUS_UTIL,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_data_bus_util));
        l_data_bus_util = l_data_bus_util < DATA_BUS_UTIL ? l_data_bus_util : DATA_BUS_UTIL;

        // Computes the active and inactive attribute values
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_percent_uplift));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT_IDLE,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_percent_uplift_idle));


        l_volt_util_active = l_data_bus_util;
        l_volt_util_inactive = 0;

        // Checks to make sure that none of the values that were read were set to zeros
        FAPI_ASSERT((l_volt_util_active != 0) &&
                    (l_volt_slope != 0) &&
                    (l_volt_intercept != 0) &&
                    (l_vddr_max_limit_mv != 0),
                    fapi2::CEN_MSS_VOLT_VDDR_OFFSET_VALUE_ERROR()
                    .set_CEN_TARGET(i_targets[0])
                    .set_VDDR_UTIL_ACTIVE(l_volt_util_active)
                    .set_VDDR_SLOPE(l_volt_slope)
                    .set_VDDR_INTERCEPT(l_volt_intercept)
                    .set_VDDR_MAX_LIMIT(l_vddr_max_limit_mv),
                    "%s One or more dynamic VDD attributes is 0 slope_util_active %lu slope %lu slope_intercept %lu!  Exiting....",
                    mss::c_str(i_targets[0]), l_volt_util_active, l_volt_slope, l_volt_intercept);

        // Print to check the calculation
        FAPI_INF("l_data_bus_util %d per 10k l_volt_util_active: %d per 10k l_volt_util_inactive: %d per 10k",
                 l_data_bus_util, l_volt_util_active, l_volt_util_inactive);


        l_num_dimms_to_add = 1;

        // Computes the preliminary VDDR value
        for(const auto& l_chip : i_targets)
        {
            // Gets the functional attribute to check for an active centaur
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, l_chip, l_is_functional));

            // Gets the power slope values and does error checks if this card is functional, as it should have good VPD.  if the card is non-functional, continue using good VPD power slope values
            auto l_rc = FAPI_ATTR_GET(fapi2::ATTR_CEN_CDIMM_VPD_MASTER_POWER_SLOPE, l_chip, l_vpd_master_power_slope);

            if(l_is_functional == fapi2::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL)
            {
                FAPI_TRY(l_rc);
            }

            l_rc = FAPI_ATTR_GET(fapi2::ATTR_CEN_CDIMM_VPD_MASTER_POWER_INTERCEPT, l_chip, l_vpd_master_power_intercept);

            if(l_is_functional == fapi2::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL)
            {
                FAPI_TRY(l_rc);
            }

            // Removes leading bits from the VPD MASTER POWER attributes, leaving only the values needed for the power calculations
            l_vpd_master_power_slope &= 0x1FFF;
            l_vpd_master_power_intercept &= 0x1FFF;

            // Checks to make sure that the attribute values are non-zero - calls out all bad DIMMs
            if(((l_vpd_master_power_slope * l_vpd_master_power_intercept) == 0)
               && (l_is_functional == fapi2::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL))
            {
                FAPI_ASSERT((l_volt_util_active != 0) &&
                            (l_volt_slope != 0) &&
                            (l_volt_intercept != 0),
                            fapi2::CEN_MSS_VOLT_VDDR_OFFSET_VPD_VALUE_ERROR()
                            .set_CEN_TARGET(i_targets[0])
                            .set_VPD_MASTER_POWER_SLOPE(l_vpd_master_power_slope)
                            .set_VPD_MASTER_POWER_INTERCEPT(l_vpd_master_power_intercept),
                            "%s One or more VPD Power slope attributes is 0.  Logging error and looking for additional bad DIMMs. power_slope  %lu power_intercept %lu!  Exiting....",
                            mss::c_str(i_targets[0]), l_vpd_master_power_slope, l_vpd_master_power_intercept);

                // Using a generic error here as we already logged the other error above
                l_bad_vpd_rc = fapi2::FAPI2_RC_INVALID_PARAMETER;
                continue;
            }
            // One or more DIMM has already been called out, skip doing the calculation and continue to try to find bad DIMMs
            else if(l_bad_vpd_rc)
            {
                FAPI_INF("Already found a bad DIMM.  Skipping calculations on this DIMM.");
                continue;
            }
            // Has not found good master_power_slopes and has bad master power slopes
            else if(((l_good_master_power_slope == 0) || (l_good_master_power_intercept == 0)) &&
                    ((l_vpd_master_power_slope == 0) || (l_vpd_master_power_intercept == 0)))
            {
                l_num_dimms_to_add++;
                FAPI_INF("Found bad l_vpd_master_power_slope or l_vpd_master_power_intercept values on non-functional DIMM. Program has not found good values yet, adding one more DIMM to run when good values are found. Currently going to run %d DIMMs in the next dimm.",
                         l_num_dimms_to_add);
                continue;
            }
            // Found bad master power slope or power intercept but has good master power slope or intercepts
            else if(((l_vpd_master_power_slope == 0) || (l_vpd_master_power_intercept == 0)) &&
                    ((l_good_master_power_slope > 0) && (l_good_master_power_intercept > 0)))
            {
                // Uses assumed (last good master power slope and intercept) values for these calculations
                FAPI_INF("Found bad l_vpd_master_power_slope or l_vpd_master_power_intercept values on non-functional DIMM. Program is using the last good values for the calculations for this DIMM.");
                l_vpd_master_power_slope = l_good_master_power_slope;
                l_vpd_master_power_intercept = l_good_master_power_intercept;
            }
            // Found good master power slopes -> set the good master power slope values
            else if((l_vpd_master_power_slope > 0) && (l_vpd_master_power_intercept > 0 ))
            {
                l_good_master_power_slope = l_vpd_master_power_slope;
                l_good_master_power_intercept = l_vpd_master_power_intercept;
            }

            // Loops through all MBA chiplets to compare the compute the total number of logical dimms associated with a centaur
            l_num_logical_dimms = 0;

            for(const auto& l_mba : mss::find_targets<fapi2::TARGET_TYPE_MBA>(l_chip))
            {
                l_num_logical_dimms += mss::count_dimm(l_mba);
            }//end for

            // Multiply by total number of active logical dimms
            {
                // Temporary variables to compress the functions below
                const bool l_functional = l_is_functional == fapi2::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL;
                const auto l_volt_util = l_functional ? l_volt_util_active : l_volt_util_inactive;

                // Calculates the uplift percentage
                const auto UPLIFT = (PERCENT + l_percent_uplift) / PERCENT;
                // Note: static cast makes the entire calcuation a floating point calculation, which is what we want
                // Calculates the power usage per active DIMM
                const auto POWER_CURVE = (static_cast<double>(l_vpd_master_power_slope) * l_volt_util / ATTR_VOLT_CONVERSION) +
                                         l_vpd_master_power_intercept;

                // Calculates the power on VDDR
                l_var_power_on_vddr += static_cast<uint32_t>(l_num_dimms_to_add * POWER_CURVE * l_num_logical_dimms * UPLIFT);
                FAPI_INF("%s l_var_power_on_vddr: %d cW l_vpd_master_power_slope: %d cW l_volt_util_%sactive: %d per 10k l_vpd_master_power_intercept %d cW l_num_logical_dimms %d l_percent_uplift %d %%",
                         mss::c_str(l_chip), l_var_power_on_vddr, l_vpd_master_power_slope, l_functional ? "" : "in",
                         l_volt_util_active, l_vpd_master_power_intercept, l_num_logical_dimms, l_percent_uplift);
            }

            // Resets the number of DIMMs to add.
            l_num_dimms_to_add = 1;
        }//end for

        // Found a bad DIMM, exit
        FAPI_TRY(l_bad_vpd_rc, "Found one or more functional DIMM with bad VPD. Exiting....");

        // Debug print
        FAPI_INF("l_var_power_on_vddr: %d cW l_volt_slope: %d uV/W l_volt_intercept: %d mV",
                 l_var_power_on_vddr, l_volt_slope, l_volt_intercept);

        // Computes and converts the voltage offset into mV
        // Naked numbers are for this calculation and are a one to one port from the p8 code base
        l_param_vddr_voltage_mv = (500 + l_var_power_on_vddr * l_volt_slope / 100) / 1000 + l_volt_intercept;
        FAPI_INF("l_param_vddr_voltage_mv: %d mV", l_param_vddr_voltage_mv);

        // Found that the VDDR voltage is over the maximum limit
        if(l_param_vddr_voltage_mv > l_vddr_max_limit_mv)
        {
            FAPI_INF("l_param_vddr_voltage_mv, %d mV, is over l_vddr_max_limit_mv of %d mV.", l_param_vddr_voltage_mv,
                     l_vddr_max_limit_mv);
            FAPI_INF("Setting l_param_vddr_voltage_mv to l_vddr_max_limit_mv");
            l_param_vddr_voltage_mv = l_vddr_max_limit_mv;
        }

        // Prints out the final attribute value
        FAPI_INF("ATTR_CEN_MSS_VDDR_OFFSET: %d mV", l_param_vddr_voltage_mv);

        // Sets the output attributes
        for(const auto& l_chip : i_targets)
        {
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_VDDR_OFFSET, l_chip, l_param_vddr_voltage_mv));
        }//end for

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern "C"
