/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_eff_config_thermal.C $ */
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
/// @file p9c_mss_eff_config_thermal.C
/// @brief  set the default throttle and power attributes for dimms in a given system
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Mike Pardeik <pardeik@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

// attributes for dimms in a given system
// -- The power attributes are the slope/intercept values.  Note that these
//    values are in cW.
//    -- ISDIMM will calculate values based on various attributes
//    -- CDIMM will get values from VPD
// -- The throttle attributes will setup values for IPL and runtime
//
//------------------------------------------------------------------------------
//  My Includes
//------------------------------------------------------------------------------
#include <p9c_mss_eff_config_thermal.H>
#include <p9c_mss_bulk_pwr_throttles.H>
#include <generic/memory/lib/utils/c_str.H>
#include <dimmConsts.H>
//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

// Only use values here (not any valid bits or flag bits)
constexpr uint32_t CDIMM_POWER_SLOPE_DEFAULT = 0x0358;
constexpr uint32_t CDIMM_POWER_INT_DEFAULT = 0x00CE;

extern "C" {
    ///
    /// @brief mss_eff_config_thermal(): This function determines the
    /// power curve and throttle attribute values to use
    /// @param[in]   const fapi2::Target<fapi2::TARGET_TYPE_MBA> & i_target_mba:  MBA Target<fapi2::TARGET_TYPE_MBA> passed in
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_eff_config_thermal(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {

        FAPI_INF("*** Running mss_eff_config_thermal on %s ***",
                 mss::c_str(i_target_mba));

        FAPI_TRY(mss_eff_config_thermal_powercurve(i_target_mba));
        FAPI_TRY(mss_eff_config_thermal_throttles(i_target_mba));


        FAPI_INF("*** mss_eff_config_thermal COMPLETE on %s ***",
                 mss::c_str(i_target_mba));
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief mss_eff_config_thermal_powercurve(): This function determines the
    /// power curve attribute values to use
    /// @param[in]   const fapi2::Target<fapi2::TARGET_TYPE_MBA> & i_target_mba:  MBA Target<fapi2::TARGET_TYPE_MBA> passed in
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_thermal_powercurve(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {
        FAPI_INF("*** Running mss_eff_config_thermal_powercurve on %s ***",
                 mss::c_str(i_target_mba));
        uint8_t l_port = 0;
        uint8_t l_dimm = 0;
        uint8_t l_custom_dimm = 0;
        uint8_t l_dimm_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_power_slope_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_power_int_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_power_slope2_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_power_int2_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_total_power_slope_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_total_power_int_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_total_power_slope2_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_total_power_int2_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_cdimm_master_power_slope = 0;
        uint32_t l_cdimm_master_power_intercept = 0;
        uint32_t l_cdimm_supplier_power_slope = 0;
        uint32_t l_cdimm_supplier_power_intercept = 0;
        uint32_t l_cdimm_master_total_power_slope = 0;
        uint32_t l_cdimm_master_total_power_intercept = 0;
        uint32_t l_cdimm_supplier_total_power_slope = 0;
        uint32_t l_cdimm_supplier_total_power_intercept = 0;
        uint8_t l_dram_gen = 0;
        uint8_t l_logged_error_power_curve = 0;
        uint8_t l_logged_error_total_power_curve = 0;

        //------------------------------------------------------------------------------
        // Get input attributes
        //------------------------------------------------------------------------------

        // Get Centaur target for the given MBA
        const auto l_target_chip = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_custom_dimm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM,
                               i_target_mba, l_dimm_ranks_array));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN,
                               i_target_mba, l_dram_gen));

        // Only get power curve values for custom dimms to prevent errors
        if (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
        {
            // These are the CDIMM power curve values for only VMEM (DDR3 and DDR4)
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CDIMM_VPD_MASTER_POWER_SLOPE,
                                   l_target_chip, l_cdimm_master_power_slope));

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CDIMM_VPD_MASTER_POWER_INTERCEPT,
                                   l_target_chip, l_cdimm_master_power_intercept));

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CDIMM_VPD_SUPPLIER_POWER_SLOPE,
                                   l_target_chip, l_cdimm_supplier_power_slope));


            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CDIMM_VPD_SUPPLIER_POWER_INTERCEPT,
                                   l_target_chip, l_cdimm_supplier_power_intercept));


            // These are for the total CDIMM power (VMEM+VPP for DDR4)
            if (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
            {

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CDIMM_VPD_MASTER_TOTAL_POWER_SLOPE,
                                       l_target_chip, l_cdimm_master_total_power_slope));

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CDIMM_VPD_MASTER_TOTAL_POWER_INTERCEPT,
                                       l_target_chip, l_cdimm_master_total_power_intercept));

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CDIMM_VPD_SUPPLIER_TOTAL_POWER_SLOPE,
                                       l_target_chip, l_cdimm_supplier_total_power_slope));

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CDIMM_VPD_SUPPLIER_TOTAL_POWER_INTERCEPT,
                                       l_target_chip, l_cdimm_supplier_total_power_intercept));
            }
            else
            {
                // Set total power curve variables to the VMEM power curve variables for DDR3
                l_cdimm_master_total_power_slope = l_cdimm_master_power_slope;
                l_cdimm_master_total_power_intercept = l_cdimm_master_power_intercept;
                l_cdimm_supplier_total_power_slope = l_cdimm_supplier_power_slope;
                l_cdimm_supplier_total_power_intercept = l_cdimm_supplier_power_intercept;
            }
        }

        // Power Curve Determination
        // Iterate through the MBA ports to get power slope/intercept values
        for (l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
        {
            // iterate through the dimms on each port again to determine power slope and
            // intercept
            for (l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++)
            {
                // initialize dimm entries to zero
                l_power_slope_array[l_port][l_dimm] = 0;
                l_power_int_array[l_port][l_dimm] = 0;
                l_power_slope2_array[l_port][l_dimm] = 0;
                l_power_int2_array[l_port][l_dimm] = 0;
                l_total_power_slope_array[l_port][l_dimm] = 0;
                l_total_power_int_array[l_port][l_dimm] = 0;
                l_total_power_slope2_array[l_port][l_dimm] = 0;
                l_total_power_int2_array[l_port][l_dimm] = 0;

                // only update values for l_dimms that are physically present
                if (l_dimm_ranks_array[l_port][l_dimm] > 0)
                {
                    // CDIMM power slope/intercept will come from VPD
                    // Data in VPD needs to be the power per virtual dimm on the CDIMM
                    if (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
                    {
                        l_power_slope_array[l_port][l_dimm] =
                            l_cdimm_master_power_slope;
                        l_power_int_array[l_port][l_dimm] =
                            l_cdimm_master_power_intercept;
                        l_power_slope2_array[l_port][l_dimm] =
                            l_cdimm_supplier_power_slope;
                        l_power_int2_array[l_port][l_dimm] =
                            l_cdimm_supplier_power_intercept;
                        l_total_power_slope_array[l_port][l_dimm] =
                            l_cdimm_master_total_power_slope;
                        l_total_power_int_array[l_port][l_dimm] =
                            l_cdimm_master_total_power_intercept;
                        l_total_power_slope2_array[l_port][l_dimm] =
                            l_cdimm_supplier_total_power_slope;
                        l_total_power_int2_array[l_port][l_dimm] =
                            l_cdimm_supplier_total_power_intercept;

                        // check to see if VMEM power curve data is valid
                        if (
                            (((l_cdimm_master_power_slope & 0x8000) != 0) &&
                             ((l_cdimm_master_power_intercept & 0x8000) != 0))
                            &&
                            (((l_cdimm_supplier_power_slope & 0x8000) != 0) &&
                             ((l_cdimm_supplier_power_intercept & 0x8000) != 0))
                        )
                        {
                            l_power_slope_array[l_port][l_dimm] =
                                l_cdimm_master_power_slope & 0x1FFF;
                            l_power_int_array[l_port][l_dimm] =
                                l_cdimm_master_power_intercept & 0x1FFF;
                            l_power_slope2_array[l_port][l_dimm] =
                                l_cdimm_supplier_power_slope & 0x1FFF;
                            l_power_int2_array[l_port][l_dimm] =
                                l_cdimm_supplier_power_intercept & 0x1FFF;

                            // check to see if data is lab data
                            if (
                                (((l_cdimm_master_power_slope & 0x4000) == 0) ||
                                 ((l_cdimm_master_power_intercept & 0x4000) == 0))
                                ||
                                (((l_cdimm_supplier_power_slope & 0x4000) == 0) ||
                                 ((l_cdimm_supplier_power_intercept &
                                   0x4000) == 0))
                            )
                            {
                                FAPI_INF("WARNING:  VMEM power curve data is lab data, not ship level data. Using data anyways.");
                            }

                            // check total power curve (VMEM+VPP) values for DDR4
                            if (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
                            {
                                if (
                                    (((l_cdimm_master_total_power_slope & 0x8000) != 0) &&
                                     ((l_cdimm_master_total_power_intercept & 0x8000) != 0))
                                    &&
                                    (((l_cdimm_supplier_total_power_slope & 0x8000) != 0) &&
                                     ((l_cdimm_supplier_total_power_intercept & 0x8000) != 0))
                                )
                                {
                                    l_total_power_slope_array[l_port][l_dimm] =
                                        l_cdimm_master_total_power_slope & 0x1FFF;
                                    l_total_power_int_array[l_port][l_dimm] =
                                        l_cdimm_master_total_power_intercept & 0x1FFF;
                                    l_total_power_slope2_array[l_port][l_dimm] =
                                        l_cdimm_supplier_total_power_slope & 0x1FFF;
                                    l_total_power_int2_array[l_port][l_dimm] =
                                        l_cdimm_supplier_total_power_intercept & 0x1FFF;

                                    // check to see if data is lab data
                                    if (
                                        (((l_cdimm_master_total_power_slope & 0x4000) == 0) ||
                                         ((l_cdimm_master_total_power_intercept & 0x4000) == 0))
                                        ||
                                        (((l_cdimm_supplier_total_power_slope & 0x4000) == 0) ||
                                         ((l_cdimm_supplier_total_power_intercept &
                                           0x4000) == 0))
                                    )
                                    {
                                        FAPI_INF("WARNING:  Total power curve data is lab data, not ship level data. Using data anyways.");
                                    }
                                }
                                else
                                {
                                    // Set to VMEM power curve values if total values are not valid and log an error
                                    // early DDR4 CDIMMs will have the total power curve entries all zero (not valid)
                                    l_total_power_slope_array[l_port][l_dimm] =
                                        l_power_slope_array[l_port][l_dimm];
                                    l_total_power_int_array[l_port][l_dimm] =
                                        l_power_int_array[l_port][l_dimm];
                                    l_total_power_slope2_array[l_port][l_dimm] =
                                        l_power_slope2_array[l_port][l_dimm];
                                    l_total_power_int2_array[l_port][l_dimm] =
                                        l_power_int2_array[l_port][l_dimm];

                                    // only log the error once per MBA, since all dimms will have the same power curve values
                                    if (l_logged_error_total_power_curve == 0)
                                    {
                                        l_logged_error_total_power_curve = 1;
                                        FAPI_ASSERT(false,
                                                    fapi2::CEN_MSS_DIMM_POWER_CURVE_DATA_INVALID().
                                                    set_MEM_CHIP(l_target_chip).
                                                    set_FFDC_DATA_1(l_cdimm_master_power_slope).
                                                    set_FFDC_DATA_2(l_cdimm_master_power_intercept).
                                                    set_FFDC_DATA_3(l_cdimm_supplier_power_slope).
                                                    set_FFDC_DATA_4(l_cdimm_supplier_power_intercept),
                                                    "");
                                    }
                                }
                            }
                            else
                            {
                                // Set total power curve values to VMEM power curve values for anything other than DDR4 (ie.  DDR3)
                                l_total_power_slope_array[l_port][l_dimm] =
                                    l_power_slope_array[l_port][l_dimm];
                                l_total_power_int_array[l_port][l_dimm] =
                                    l_power_int_array[l_port][l_dimm];
                                l_total_power_slope2_array[l_port][l_dimm] =
                                    l_power_slope2_array[l_port][l_dimm];
                                l_total_power_int2_array[l_port][l_dimm] =
                                    l_power_int2_array[l_port][l_dimm];
                            }
                        }
                        else
                        {
                            // Set to default values and log an error if VMEM power curve values are not valid
                            l_power_slope_array[l_port][l_dimm] =
                                CDIMM_POWER_SLOPE_DEFAULT;
                            l_power_int_array[l_port][l_dimm] =
                                CDIMM_POWER_INT_DEFAULT;
                            l_power_slope2_array[l_port][l_dimm] =
                                CDIMM_POWER_SLOPE_DEFAULT;
                            l_power_int2_array[l_port][l_dimm] =
                                CDIMM_POWER_INT_DEFAULT;
                            l_total_power_slope_array[l_port][l_dimm] =
                                CDIMM_POWER_SLOPE_DEFAULT;
                            l_total_power_int_array[l_port][l_dimm] =
                                CDIMM_POWER_INT_DEFAULT;
                            l_total_power_slope2_array[l_port][l_dimm] =
                                CDIMM_POWER_SLOPE_DEFAULT;
                            l_total_power_int2_array[l_port][l_dimm] =
                                CDIMM_POWER_INT_DEFAULT;

                            // only log the error once per MBA, since all dimms will have the same power curve values
                            if (l_logged_error_power_curve == 0)
                            {
                                l_logged_error_power_curve = 1;

                                FAPI_ASSERT(false,
                                            fapi2::CEN_MSS_DIMM_POWER_CURVE_DATA_INVALID().
                                            set_MEM_CHIP(l_target_chip).
                                            set_FFDC_DATA_1(l_cdimm_master_power_slope).
                                            set_FFDC_DATA_2(l_cdimm_master_power_intercept).
                                            set_FFDC_DATA_3(l_cdimm_supplier_power_slope).
                                            set_FFDC_DATA_4(l_cdimm_supplier_power_intercept),
                                            "");
                            }
                        }

                        FAPI_DBG("CDIMM VMEM Power [P%d:D%d][SLOPE=%d:INT=%d cW][SLOPE2=%d:INT2=%d cW]", l_port, l_dimm,
                                 l_power_slope_array[l_port][l_dimm], l_power_int_array[l_port][l_dimm], l_power_slope2_array[l_port][l_dimm],
                                 l_power_int2_array[l_port][l_dimm]);
                        FAPI_DBG("CDIMM Total Power [P%d:D%d][VMEM SLOPE=%d:INT=%d cW][VMEM SLOPE2=%d:INT2=%d cW]", l_port, l_dimm,
                                 l_total_power_slope_array[l_port][l_dimm], l_total_power_int_array[l_port][l_dimm],
                                 l_total_power_slope2_array[l_port][l_dimm],
                                 l_total_power_int2_array[l_port][l_dimm]);
                    }

                    // non custom dimms will no longer use power curves
                    // These will use a simplified approach of using throttle values for certain ranges of power
                    // in mss_bulk_pwr_throttles.
                }
            }
        }

        // write output attributes
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_POWER_SLOPE,
                               i_target_mba, l_power_slope_array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_POWER_INT, i_target_mba, l_power_int_array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_POWER_SLOPE2,
                               i_target_mba, l_power_slope2_array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_POWER_INT2,
                               i_target_mba, l_power_int2_array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_SLOPE,
                               i_target_mba, l_total_power_slope_array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_INT, i_target_mba, l_total_power_int_array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_SLOPE2,
                               i_target_mba, l_total_power_slope2_array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_INT2,
                               i_target_mba, l_total_power_int2_array));
        FAPI_INF("*** mss_eff_config_thermal_powercurve COMPLETE on %s ***",
                 mss::c_str(i_target_mba));
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief mss_eff_config_thermal_throttles(): This function determines the throttle attribute values to use
    /// @l_param[in]   const fapi2::Target<fapi2::TARGET_TYPE_MBA> & i_target_mba:  MBA Target<fapi2::TARGET_TYPE_MBA> passed in
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_thermal_throttles(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {

        FAPI_INF("*** Running mss_eff_config_thermal_throttles on %s ***",
                 mss::c_str(i_target_mba));

// variables used in this function
        uint8_t l_custom_dimm = 0;
        uint8_t l_num_dimms_on_port = 0;
        uint32_t l_runtime_throttle_n_per_mba = 0;
        uint32_t l_runtime_throttle_n_per_chip = 0;
        uint32_t l_runtime_throttle_d = 0;
        uint32_t l_dimm_thermal_power_limit = 0;
        uint32_t l_channel_pair_thermal_power_limit = 0;
        uint8_t l_num_mba_with_dimms = 0;
        uint8_t l_mba_index = 0;
        uint8_t l_ras_increment = 0;
        uint8_t l_cas_increment = 0;
        uint32_t l_max_dram_databus_util = 0;
        uint32_t l_dimm_reg_power_limit_per_dimm_adj = 0;
        uint32_t l_dimm_reg_power_limit_per_dimm = 0;
        uint32_t l_dimm_reg_power_limit_per_dimm_ddr4 = 0;
        uint8_t l_max_number_dimms_per_reg = 0;
        uint8_t l_dimm_reg_power_limit_adj_enable = 0;
        uint8_t l_reg_max_dimm_count = 0;
        uint8_t l_dram_gen = 0;
        uint32_t l_power_slope_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_power_int_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_total_power_slope_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_total_power_int_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        float MAX_UTIL;
        fapi2::ReturnCode rc;

        // Get Centaur target for the given MBA
        const auto l_target_chip = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_custom_dimm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT,
                               i_target_mba, l_num_dimms_on_port));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_THERMAL_MEMORY_POWER_LIMIT,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_dimm_thermal_power_limit));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_MEM_THROTTLE_DENOMINATOR, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_runtime_throttle_d));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_MAX_DRAM_DATABUS_UTIL,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_max_dram_databus_util));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_VMEM_REGULATOR_MEMORY_POWER_LIMIT_PER_DIMM,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_dimm_reg_power_limit_per_dimm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_VMEM_REGULATOR_MEMORY_POWER_LIMIT_PER_DIMM_DDR4,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_dimm_reg_power_limit_per_dimm_ddr4));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_MAX_NUMBER_DIMMS_POSSIBLE_PER_VMEM_REGULATOR,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_max_number_dimms_per_reg));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_dimm_reg_power_limit_adj_enable));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_reg_max_dimm_count));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN,
                               i_target_mba, l_dram_gen));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_POWER_SLOPE,
                               i_target_mba, l_power_slope_array));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_POWER_INT,
                               i_target_mba, l_power_int_array));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_SLOPE,
                               i_target_mba, l_total_power_slope_array));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_INT,
                               i_target_mba, l_total_power_int_array));

        // Get number of Centaur MBAs that have dimms present
        // Custom dimms (CDIMMs) use mba/chip throttling, so count number of mbas that have dimms
        if (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
        {
            const auto l_target_mba_array = l_target_chip.getChildren<fapi2::TARGET_TYPE_MBA>();
            l_num_mba_with_dimms = 0;

            for (l_mba_index = 0; l_mba_index < l_target_mba_array.size(); l_mba_index++)
            {
                const auto l_target_dimm_array = l_target_mba_array[l_mba_index].getChildren<fapi2::TARGET_TYPE_DIMM>();

                if (l_target_dimm_array.size() > 0)
                {
                    l_num_mba_with_dimms++;
                }
            }
        }
        // ISDIMM (non custom dimm) uses dimm/mba throttling, so set num_mba_with_dimms to 1
        else
        {
            l_num_mba_with_dimms = 1;
        }


//------------------------------------------------------------------------------
// Memory Throttle Determination
//------------------------------------------------------------------------------

// Determine memory throttle settings needed based on dimm thermal power limit

//------------------------------------------------------------------------------
// Determine the thermal power limit to use, which represents a single channel
// pair power limit for the dimms on that channel pair (ie.  power for all dimms
// attached to one MBA).   The procedure mss_bulk_power_throttles takes the
// input of channel pair power to determine throttles.
// CDIMM thermal power limit from MRW is per CDIMM, so divide by number of mbas
// that have dimms to get channel pair power
// CDIMM:  Allow all commands to be directed toward one MBA to achieve the power
// limit
//   This means that the power limit for a MBA channel pair must be the total
// CDIMM power limit minus the idle power of the other MBAs logical dimms
//------------------------------------------------------------------------------

        // adjust the regulator power limit per dimm if enabled and use this if less than the thermal limit

        // If DDR4, use DDR4 regulator power limit
        if (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
        {
            l_dimm_reg_power_limit_per_dimm = l_dimm_reg_power_limit_per_dimm_ddr4;
        }

        // If reg power limit is zero, then set to thermal limit - needed for ISDIMM systems since some of these MRW attributes are not defined
        if (l_dimm_reg_power_limit_per_dimm == 0)
        {
            l_dimm_reg_power_limit_per_dimm = l_dimm_thermal_power_limit;
        }

        l_dimm_reg_power_limit_per_dimm_adj = l_dimm_reg_power_limit_per_dimm;

        if (l_dimm_reg_power_limit_adj_enable == fapi2::ENUM_ATTR_CEN_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE_TRUE)
        {
            // adjust reg power limit per cdimm only if l_reg_max_dimm_count>0 and l_reg_max_dimm_count<l_max_number_dimms_per_reg
            if (
                (l_reg_max_dimm_count > 0)
                && (l_reg_max_dimm_count < l_max_number_dimms_per_reg)
            )
            {
                l_dimm_reg_power_limit_per_dimm_adj =
                    l_dimm_reg_power_limit_per_dimm
                    * l_max_number_dimms_per_reg
                    / l_reg_max_dimm_count;
                FAPI_INF("VMEM Regulator Power/DIMM Limit Adjustment from %d to %d cW (DIMMs under regulator %d/%d)",
                         l_dimm_reg_power_limit_per_dimm, l_dimm_reg_power_limit_per_dimm_adj, l_reg_max_dimm_count, l_max_number_dimms_per_reg);
            }
        }

        // Use the smaller of the thermal limit and regulator power limit per dimm
        if (l_dimm_reg_power_limit_per_dimm_adj < l_dimm_thermal_power_limit)
        {
            l_dimm_thermal_power_limit = l_dimm_reg_power_limit_per_dimm_adj;
        }

        // Adjust the thermal/power limit to represent the power for all dimms under an MBA
        if (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
        {
            l_channel_pair_thermal_power_limit =
                l_dimm_thermal_power_limit / l_num_mba_with_dimms;
        }
        // ISDIMMs thermal power limit from MRW is per DIMM, so multiply by number of dimms on channel to get channel power and multiply by 2 to get channel pair power
        else
        {
            // ISDIMMs
            l_channel_pair_thermal_power_limit =
                l_dimm_thermal_power_limit * l_num_dimms_on_port * 2;
        }

        // Update the channel pair power limit attribute
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_MEM_WATT_TARGET,
                               i_target_mba, l_channel_pair_thermal_power_limit));





        // Initialize the runtime throttle attributes to an unthrottled value for mss_bulk_pwr_throttles
        // max utilization comes from MRW value in c% - convert to %
        MAX_UTIL = (float) l_max_dram_databus_util / 100;
        l_runtime_throttle_n_per_mba = (int)(l_runtime_throttle_d * (MAX_UTIL / 100) / 4);
        l_runtime_throttle_n_per_chip = (int)(l_runtime_throttle_d * (MAX_UTIL / 100) / 4) *
                                        l_num_mba_with_dimms;

        // for better custom dimm performance for DDR4, set the per mba throttle to the per chip throttle
        // Not planning on doing this for DDR3
        if ( (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
             && (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES) )
        {
            l_runtime_throttle_n_per_mba = l_runtime_throttle_n_per_chip;
        }

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA,
                               i_target_mba, l_runtime_throttle_n_per_mba));




        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP,
                               i_target_mba, l_runtime_throttle_n_per_chip));


        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR,
                               i_target_mba, l_runtime_throttle_d));

        FAPI_INF("Min Power/Thermal Limit per MBA %d cW.  Unthrottled values [%d/%d/%d].", l_channel_pair_thermal_power_limit,
                 l_runtime_throttle_n_per_mba, l_runtime_throttle_n_per_chip, l_runtime_throttle_d);


        // For DDR4, use the VMEM power to determine the runtime throttle settings that are based
        //  on a VMEM power limit (not a VMEM+VPP power limit which is to be used at runtime for tmgt)
        // Need to temporarily override attributes for mss_bulk_pwr_throttles to use
        // Needed to determines runtime memory throttle settings based on any VMEM power limits
        if (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
        {
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_SLOPE,
                                   i_target_mba, l_power_slope_array));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_INT, i_target_mba, l_power_int_array));
        }

        // Call the procedure function that takes a channel pair power limit and
        // converts it to throttle values
        FAPI_EXEC_HWP(rc, p9c_mss_bulk_pwr_throttles, i_target_mba);

        // Reset the total power curve attributes back to the original values
        if (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
        {
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_SLOPE,
                                   i_target_mba, l_total_power_slope_array));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_INT, i_target_mba, l_total_power_int_array));
        }

        // Read back in the updated throttle attribute values (these are now set to
        // values that will give dimm/channel power underneath the thermal power limit)
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA,
                               i_target_mba, l_runtime_throttle_n_per_mba));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP,
                               i_target_mba, l_runtime_throttle_n_per_chip));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_DENOMINATOR,
                               i_target_mba, l_runtime_throttle_d));

        // Setup the RAS and CAS increments used in the throttling register
        l_ras_increment = 0;
        l_cas_increment = 1;

        // update output attributes
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA,
                               i_target_mba, l_runtime_throttle_n_per_mba));


        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP,
                               i_target_mba, l_runtime_throttle_n_per_chip));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR,
                               i_target_mba, l_runtime_throttle_d));


        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_THROTTLE_CONTROL_RAS_WEIGHT,
                               i_target_mba, l_ras_increment));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_THROTTLE_CONTROL_CAS_WEIGHT,
                               i_target_mba, l_cas_increment));

        FAPI_INF("*** mss_eff_config_thermal_throttles COMPLETE on %s ***",
                 mss::c_str(i_target_mba));
    fapi_try_exit:
        return fapi2::current_err;
    }

} //end extern C
