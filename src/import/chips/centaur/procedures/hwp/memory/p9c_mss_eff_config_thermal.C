/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_eff_config_thermal.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// *HWP HWP Owner: Andre Marin <aamaring@us.ibm.com>
/// *HWP HWP Backup: Mike Pardeik <pardeik@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
//
// -- The power attributes are the slope/intercept values.  Note that these
//    values are in cW.
//    -- ISDIMM will use hardcoded values
//    -- CDIMM will get values from VPD
// -- The throttle attributes will setup values for IPL and runtime
//
//------------------------------------------------------------------------------
//  My Includes
//------------------------------------------------------------------------------
#include <p9c_mss_eff_config_thermal.H>
#include <p9c_mss_funcs.H>
#include <p9c_mss_bulk_pwr_throttles.H>
#include <generic/memory/lib/utils/c_str.H>
#include <dimmConsts.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/utils/cumulus_find.H>
//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

using fapi2::TARGET_TYPE_MEMBUF_CHIP;
using fapi2::TARGET_TYPE_MBA;
using fapi2::FAPI2_RC_SUCCESS;

// Only use values here (not any valid bits or flag bits)
constexpr uint32_t CDIMM_POWER_SLOPE_DEFAULT = 0x0358;
constexpr uint32_t CDIMM_POWER_INT_DEFAULT = 0x00CE;

// ISDIMM power curves (non-custom DIMMs)
// Hard coded values make one DIMM power curve for all configurations
// If other future systems need different hard coded values, then these will need to come from MRW
constexpr uint32_t ISDIMM_VMEM_POWER_SLOPE_DEFAULT = 0x0234;
constexpr uint32_t ISDIMM_VMEM_POWER_INT_DEFAULT = 0x027F;
constexpr uint32_t ISDIMM_VMEM_PLUS_VPP_POWER_SLOPE_DEFAULT = 0x0247;
constexpr uint32_t ISDIMM_VMEM_PLUS_VPP_POWER_INT_DEFAULT = 0x02BC;

extern "C" {
    ///
    /// @brief This function determines the
    /// power curve and throttle attribute values to use
    /// @param[in] i_target_mba:  MBA Target
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_eff_config_thermal(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {

        FAPI_INF("*** Running mss_eff_config_thermal on %s ***",
                 mss::c_str(i_target_mba));

        // If MBA has no DIMMs, return as there is nothing to do
        if (mss::count_dimm(i_target_mba) == 0)
        {
            FAPI_INF("++++ NO DIMM on %s ++++", mss::c_str(i_target_mba));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        FAPI_TRY(mss_eff_config_thermal_powercurve(i_target_mba));
        FAPI_TRY(mss_eff_config_thermal_throttles(i_target_mba));


        FAPI_INF("*** mss_eff_config_thermal COMPLETE on %s ***",
                 mss::c_str(i_target_mba));
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief This function determines the
    /// power curve attribute values to use
    /// @param[in] i_target_mba:  MBA Target
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

        // get power curve values for custom DIMMs
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
                                FAPI_INF("%s WARNING:  VMEM power curve data is lab data, not ship level data. Using data anyways.",
                                         mss::c_str(i_target_mba));
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
                                        FAPI_INF("%s WARNING:  Total power curve data is lab data, not ship level data. Using data anyways.",
                                                 mss::c_str(i_target_mba));
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
                                                    set_MASTER_SLOPE(l_cdimm_master_power_slope).
                                                    set_MASTER_INTERCEPT(l_cdimm_master_power_intercept).
                                                    set_SUPPLIER_SLOPE(l_cdimm_supplier_power_slope).
                                                    set_SUPPLIER_INTERCEPT(l_cdimm_supplier_power_intercept),
                                                    "%s CDIMM VPD power curve values not valid", mss::c_str(i_target_mba)
                                                   );
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
                                            set_MASTER_SLOPE(l_cdimm_master_power_slope).
                                            set_MASTER_INTERCEPT(l_cdimm_master_power_intercept).
                                            set_SUPPLIER_SLOPE(l_cdimm_supplier_power_slope).
                                            set_SUPPLIER_INTERCEPT(l_cdimm_supplier_power_intercept),
                                            "%s CDIMM VPD power curve values not valid", mss::c_str(i_target_mba)
                                           );
                            }
                        }

                        FAPI_DBG("%s CustomDIMM VMEM Power [P%d:D%d][SLOPE=%d:INT=%d cW][SLOPE2=%d:INT2=%d cW]",
                                 mss::c_str(i_target_mba), l_port, l_dimm,
                                 l_power_slope_array[l_port][l_dimm], l_power_int_array[l_port][l_dimm], l_power_slope2_array[l_port][l_dimm],
                                 l_power_int2_array[l_port][l_dimm]);
                        FAPI_DBG("%s CustomDIMM VMEM+VPP Power [P%d:D%d][SLOPE=%d:INT=%d cW][SLOPE2=%d:INT2=%d cW]",
                                 mss::c_str(i_target_mba), l_port, l_dimm,
                                 l_total_power_slope_array[l_port][l_dimm], l_total_power_int_array[l_port][l_dimm],
                                 l_total_power_slope2_array[l_port][l_dimm],
                                 l_total_power_int2_array[l_port][l_dimm]);
                    }
                    // non custom dimm power curves
                    else
                    {
                        l_power_slope_array[l_port][l_dimm] =
                            ISDIMM_VMEM_POWER_SLOPE_DEFAULT;
                        l_power_int_array[l_port][l_dimm] =
                            ISDIMM_VMEM_POWER_INT_DEFAULT;
                        l_power_slope2_array[l_port][l_dimm] =
                            ISDIMM_VMEM_POWER_SLOPE_DEFAULT;
                        l_power_int2_array[l_port][l_dimm] =
                            ISDIMM_VMEM_POWER_INT_DEFAULT;
                        l_total_power_slope_array[l_port][l_dimm] =
                            ISDIMM_VMEM_PLUS_VPP_POWER_SLOPE_DEFAULT;
                        l_total_power_int_array[l_port][l_dimm] =
                            ISDIMM_VMEM_PLUS_VPP_POWER_INT_DEFAULT;
                        l_total_power_slope2_array[l_port][l_dimm] =
                            ISDIMM_VMEM_PLUS_VPP_POWER_SLOPE_DEFAULT;
                        l_total_power_int2_array[l_port][l_dimm] =
                            ISDIMM_VMEM_PLUS_VPP_POWER_INT_DEFAULT;
                        FAPI_DBG("%s NonCustomDIMM VMEM Power [P%d:D%d][SLOPE=%d:INT=%d cW][SLOPE2=%d:INT2=%d cW]",
                                 mss::c_str(i_target_mba), l_port, l_dimm,
                                 l_power_slope_array[l_port][l_dimm], l_power_int_array[l_port][l_dimm], l_power_slope2_array[l_port][l_dimm],
                                 l_power_int2_array[l_port][l_dimm]);
                        FAPI_DBG("%s NonCustomDIMM VMEM+VPP Power [P%d:D%d][SLOPE=%d:INT=%d cW][SLOPE2=%d:INT2=%d cW]",
                                 mss::c_str(i_target_mba), l_port, l_dimm,
                                 l_total_power_slope_array[l_port][l_dimm], l_total_power_int_array[l_port][l_dimm],
                                 l_total_power_slope2_array[l_port][l_dimm],
                                 l_total_power_int2_array[l_port][l_dimm]);

                    }
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
    /// @brief This function determines the throttle attribute values to use
    /// @param[in] i_target_mba:  MBA Target
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
        uint8_t l_ras_increment = 0;
        uint8_t l_cas_increment = 0;
        uint32_t l_max_dram_databus_util = 0;
        uint32_t l_dimm_reg_power_limit_per_dimm_adj = 0;
        uint32_t l_dimm_reg_power_limit_per_dimm = 0;
        uint32_t l_dimm_reg_power_limit_per_dimm_ddr3 = 0;
        uint32_t l_dimm_reg_power_limit_per_dimm_ddr4 = 0;
        uint8_t l_max_number_dimms_per_reg = 0;
        uint8_t l_dimm_reg_power_limit_adj_enable = 0;
        uint8_t l_reg_max_dimm_count = 0;
        uint8_t l_dram_gen = 0;
        uint32_t l_power_slope_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_power_int_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_total_power_slope_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_total_power_int_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        fapi2::ReturnCode l_rc;
        uint8_t l_throttle_multiplier = 0;
        uint32_t l_safemode_throttle_n_per_mba = 0;
        uint32_t l_safemode_throttle_n_per_chip = 0;

        // Get Centaur target for the given MBA
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_custom_dimm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT,
                               i_target_mba, l_num_dimms_on_port));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT,
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

        // If any of these are zero and used, then we will end up with an error in p9c_mss_bulk_pwr_throttles
        //   (CEN_MSS_NOT_ENOUGH_AVAILABLE_DIMM_POWER), so no need to check these here
        // ATTR_CEN_MRW_THERMAL_MEMORY_POWER_LIMIT
        // ATTR_MRW_VMEM_REGULATOR_MEMORY_POWER_LIMIT_PER_DIMM_DDR3
        // ATTR_MRW_VMEM_REGULATOR_MEMORY_POWER_LIMIT_PER_DIMM_DDR4
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_THERMAL_MEMORY_POWER_LIMIT,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_dimm_thermal_power_limit));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_VMEM_REGULATOR_MEMORY_POWER_LIMIT_PER_DIMM_DDR3,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_dimm_reg_power_limit_per_dimm_ddr3));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_VMEM_REGULATOR_MEMORY_POWER_LIMIT_PER_DIMM_DDR4,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_dimm_reg_power_limit_per_dimm_ddr4));

        // If these are zero then the power limit adjustment just won't happen
        // Not deemed critical enough to stop the IPL, so no error will be called out
        // ATTR_MSS_MRW_MAX_NUMBER_DIMMS_POSSIBLE_PER_VMEM_REGULATOR
        // ATTR_MSS_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MAX_NUMBER_DIMMS_POSSIBLE_PER_VMEM_REGULATOR,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_max_number_dimms_per_reg));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_dimm_reg_power_limit_adj_enable));

        // Error out if we have invalid MRW attribute combination:
        // ATTR_MSS_MRW_MAX_DRAM_DATABUS_UTIL = 0 with ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS > 0 (throttling enabled) is not valid
        //   because we would end up with N=0 and M>0 for N/M throttling which will cause hangs
        // Note that M=0 has memory throttling disabled
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_runtime_throttle_d));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MAX_DRAM_DATABUS_UTIL,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_max_dram_databus_util));
        FAPI_ASSERT( !((l_runtime_throttle_d > 0) && (l_max_dram_databus_util == 0)),
                     fapi2::CEN_MSS_MRW_MAX_DRAM_DATABUS_UTIL_INVALID().
                     set_MRW_DRAM_UTIL(l_max_dram_databus_util).
                     set_MRW_M_THROTTLE(l_runtime_throttle_d),
                     "Invalid MRW values:  ATTR_MSS_MRW_MAX_DRAM_DATABUS_UTIL %d ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS %d", l_max_dram_databus_util,
                     l_runtime_throttle_d);

        // Error out if the safemode MRW attributes are zero
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_safemode_throttle_n_per_mba));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_safemode_throttle_n_per_chip));
        FAPI_ASSERT( !((l_safemode_throttle_n_per_mba == 0) || (l_safemode_throttle_n_per_chip == 0)),
                     fapi2::CEN_MSS_MRW_SAFEMODE_THROTTLES_INVALID().
                     set_MRW_SAFEMODE_N_MBA(l_safemode_throttle_n_per_mba).
                     set_MRW_SAFEMODE_N_CHIP(l_safemode_throttle_n_per_chip),
                     "Invalid MRW values:  ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA %d ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP %d",
                     l_safemode_throttle_n_per_mba, l_safemode_throttle_n_per_chip);

        // If throttling is disabled, set max util to MAX_UTIL
        if (l_runtime_throttle_d == 0)
        {
            FAPI_INF("%s Memory Throttling is Disabled with M=0", mss::c_str(i_target_mba));
            l_max_dram_databus_util = MAX_UTIL;
        }

        // get number of mba's with dimms, used below to help determine power limit values below
        // Have to have this section in braces otherwise compile fails
        {
            const auto& l_target_chip = mss::find_target<TARGET_TYPE_MEMBUF_CHIP>(i_target_mba);

            for (const auto& l_mba : mss::find_targets<TARGET_TYPE_MBA>(l_target_chip))
            {
                if (mss::count_dimm(l_mba) > 0)
                {
                    l_num_mba_with_dimms++;
                }
            }
        }

        // Set the throttle multiplier based on how throttles are used
        // CDIMMs use per mba and per chip throttles (for l_throttle_n_per_mba and l_throttle_n_per_chip), set to 2
        // ISDIMMs use per slot and per mba throttles (for l_throttle_n_per_mba and l_throttle_n_per_chip), set to 1
        l_throttle_multiplier = (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES) ? 2 : 1;

        FAPI_INF("%s [Number MBAs with DIMMs %d][Throttle Multiplier %d]", mss::c_str(i_target_mba), l_num_mba_with_dimms,
                 l_throttle_multiplier);

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
        l_dimm_reg_power_limit_per_dimm = (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4) ?
                                          l_dimm_reg_power_limit_per_dimm_ddr4 : l_dimm_reg_power_limit_per_dimm_ddr3;

        l_dimm_reg_power_limit_per_dimm_adj = l_dimm_reg_power_limit_per_dimm;

        if (l_dimm_reg_power_limit_adj_enable == fapi2::ENUM_ATTR_MSS_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE_TRUE)
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
                FAPI_INF("%s VMEM Regulator Power/DIMM Limit Adjustment from %d to %d cW (DIMMs under regulator %d/%d)",
                         mss::c_str(i_target_mba), l_dimm_reg_power_limit_per_dimm, l_dimm_reg_power_limit_per_dimm_adj,
                         l_reg_max_dimm_count, l_max_number_dimms_per_reg);
            }
        }

        // Use the smaller of the thermal limit and regulator power limit per dimm
        FAPI_INF("%s Power/DIMM:  VMEM Regulator Limit %d cW, DIMM Thermal Limit %d cW",
                 mss::c_str(i_target_mba), l_dimm_reg_power_limit_per_dimm_adj, l_dimm_thermal_power_limit);
        l_dimm_thermal_power_limit = (l_dimm_reg_power_limit_per_dimm_adj < l_dimm_thermal_power_limit) ?
                                     l_dimm_reg_power_limit_per_dimm_adj : l_dimm_thermal_power_limit;

        // Adjust the thermal/power limit to represent the power for all dimms under an MBA
        // CDIMM thermal power limit is for both MBAs, so divide by number of MBAs
        // ISDIMMs thermal power limit from MRW is per DIMM, so multiply by number of dimms on channel to get channel power and multiply by 2 to get channel pair power
        l_channel_pair_thermal_power_limit = (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES) ?
                                             (l_dimm_thermal_power_limit / l_num_mba_with_dimms) :
                                             (l_dimm_thermal_power_limit * l_num_dimms_on_port * 2);

        // Update the channel pair power limit attribute
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_MEM_WATT_TARGET,
                               i_target_mba, l_channel_pair_thermal_power_limit));

        // Initialize the runtime throttle attributes to an unthrottled value for mss_bulk_pwr_throttles
        l_runtime_throttle_n_per_mba = (static_cast<uint32_t>(l_runtime_throttle_d *
                                        ((convert_to_percent(static_cast<double>(l_max_dram_databus_util))) / PERCENT_CONVERSION) /
                                        ADDR_TO_DATA_UTIL_CONVERSION));
        l_runtime_throttle_n_per_chip = (static_cast<uint32_t>(l_runtime_throttle_d *
                                         ((convert_to_percent(static_cast<double>(l_max_dram_databus_util))) / PERCENT_CONVERSION) /
                                         ADDR_TO_DATA_UTIL_CONVERSION) * l_throttle_multiplier);

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

        FAPI_INF("%s Min Power/Thermal Limit per MBA %d cW.  Unthrottled values [%d/%d/%d].",
                 mss::c_str(i_target_mba), l_channel_pair_thermal_power_limit,
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
        FAPI_EXEC_HWP(l_rc, p9c_mss_bulk_pwr_throttles, i_target_mba);
        FAPI_TRY(l_rc, "Failed running p9c_mss_bulk_pwr_throttles on %s", mss::c_str(i_target_mba));

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

        // Avoid over-current warnings if necessary by throttling n_mba value
        {
            fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA_Type l_throttle_n_per_mba_override = {};

            fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA_Type l_throttle_n_per_mba = {};
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA,
                                   i_target_mba, l_throttle_n_per_mba));

            l_throttle_n_per_mba_override = l_throttle_n_per_mba;
            FAPI_TRY(ipl_n_mba_throttle_override(i_target_mba, l_throttle_n_per_mba_override));

            // There is no need to set the attribute if the original value didn't change
            if(l_throttle_n_per_mba_override != l_throttle_n_per_mba)
            {
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA,
                                       i_target_mba, l_throttle_n_per_mba_override));
            }
        }

        FAPI_INF("*** mss_eff_config_thermal_throttles COMPLETE on %s ***",
                 mss::c_str(i_target_mba));
    fapi_try_exit:
        return fapi2::current_err;
    }

} //end extern C
