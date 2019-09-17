/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_eff_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file p10_fbc_eff_config.C
/// @brief Set fabric system-wide effective config attributes (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_fbc_eff_config.H>
#include <p10_fbc_utils.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

const uint32_t EPSILON_MIN_VALUE = 0x1;
const uint32_t EPSILON_MAX_VALUE = 0xFFFFFFFF;

const uint8_t NUM_EPSILON_READ_TIERS = 3;
const uint8_t NUM_EPSILON_WRITE_TIERS = 2;

// Low-end Epsilons (2 chips/group, 1 group)
const uint32_t EPSILON_R_T0_LE[] = {   9,   9,  10,  10,  11 };
const uint32_t EPSILON_R_T1_LE[] = {   9,   9,  10,  10,  11 };
const uint32_t EPSILON_R_T2_LE[] = { 172, 179, 189, 204, 225 };
const uint32_t EPSILON_W_T0_LE[] = {   0,   0,   0,   0,   0 };
const uint32_t EPSILON_W_T1_LE[] = {  96,  93,  89,  83,  75 };

// Low-end Epsilons (2 chips/group, 2 groups)
const uint32_t EPSILON_R_T0_LD[] = {   9,   9,  10,  10,  11 };
const uint32_t EPSILON_R_T1_LD[] = { 155, 163, 173, 188, 210 };
const uint32_t EPSILON_R_T2_LD[] = { 298, 311, 329, 353, 390 };
const uint32_t EPSILON_W_T0_LD[] = {  78,  75,  72,  67,  59 };
const uint32_t EPSILON_W_T1_LD[] = { 202, 205, 210, 217, 227 };

// Mid-range Epsilons (4 chips/group, 1 group)
// @TODO RTC210056 Currently using F8 values; revisit when new values available
const uint32_t EPSILON_R_T0_MR[] = {   9,   9,  10,  10,  11 };
const uint32_t EPSILON_R_T1_MR[] = {   9,   9,  10,  10,  11 };
const uint32_t EPSILON_R_T2_MR[] = { 208, 221, 237, 261, 295 };
const uint32_t EPSILON_W_T0_MR[] = {   0,   0,   0,   0,   0 };
const uint32_t EPSILON_W_T1_MR[] = {  93,  92,  91,  89,  87 };

// Flat-8 Epsilons (8 chips/group, 1 group)
const uint32_t EPSILON_R_T0_F8[] = {   9,   9,  10,  10,  11 };
const uint32_t EPSILON_R_T1_F8[] = {   9,   9,  10,  10,  11 };
const uint32_t EPSILON_R_T2_F8[] = { 208, 221, 237, 261, 295 };
const uint32_t EPSILON_W_T0_F8[] = {   0,   0,   0,   0,   0 };
const uint32_t EPSILON_W_T1_F8[] = {  93,  92,  91,  89,  87 };

// High-end Epsilons (4 chips/group, 4 groups)
const uint32_t EPSILON_R_T0_HE[] = {   9,   9,  10,  10,  11 };
const uint32_t EPSILON_R_T1_HE[] = { 174, 184, 196, 214, 240 };
const uint32_t EPSILON_R_T2_HE[] = { 328, 344, 365, 395, 440 };
const uint32_t EPSILON_W_T0_HE[] = {  85,  84,  82,  80,  76 };
const uint32_t EPSILON_W_T1_HE[] = { 219, 226, 234, 246, 264 };

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Utility function to apply positive/negative scaling factor
///        to base epsilon value
///
/// @param[in] i_gb_percentage      Scaling factor (e.g. 20% = 20)
/// @param[in/out] io_target_value  Input is the current input epsilon value.
///                                 Output is the adjusted epsilon value after applying
///                                 scaling factor. Note: Scaling will be clamped to
///                                 min/max epsilon value if thresholds are exceeded.
/// @return void.
///
void p10_fbc_eff_config_guardband_epsilon(
    const int8_t i_gb_percentage,
    uint32_t& io_target_value)
{
    if (i_gb_percentage >= 0)
    {
        uint32_t l_delta =  ((io_target_value * i_gb_percentage) / 100) +
                            (((io_target_value * i_gb_percentage) % 100) ? (1) : (0));

        if (l_delta > (EPSILON_MAX_VALUE - io_target_value))
        {
            FAPI_DBG("Guardband application generated out-of-range target value, clamping to maximum value!");
            io_target_value = EPSILON_MAX_VALUE;
        }
        else
        {
            io_target_value += l_delta;
        }
    }
    else
    {
        uint32_t l_delta =  ((io_target_value * (-1) * i_gb_percentage) / 100) +
                            (((io_target_value * (-1) * i_gb_percentage) % 100) ? (1) : (0));

        if (l_delta > (io_target_value - EPSILON_MIN_VALUE))
        {
            FAPI_DBG("Guardband application generated out-of-range target value, clamping to minimum value!");
            io_target_value = EPSILON_MIN_VALUE;
        }
        else
        {
            io_target_value -= l_delta;
        }
    }

    return;
}

///
/// @brief Calculate target epsilon settings to apply based on system configuration
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_eff_config_calc_epsilons(void)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_PROC_EPS_GB_PERCENTAGE_Type l_eps_gb;
    fapi2::ATTR_PROC_EPS_TABLE_TYPE_Type l_eps_table_type;
    fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_broadcast_mode;
    fapi2::ATTR_PROC_FABRIC_CORE_FREQ_RATIO_Type l_freq_ratio;
    uint32_t l_eps_r[NUM_EPSILON_READ_TIERS];
    uint32_t l_eps_w[NUM_EPSILON_WRITE_TIERS];

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_TABLE_TYPE, FAPI_SYSTEM, l_eps_table_type),
             "Error from FAPI_ATTR_GET(ATTR_PROC_EPS_TABLE_TYPE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, FAPI_SYSTEM, l_broadcast_mode),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_BROADCAST_MODE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CORE_FREQ_RATIO, FAPI_SYSTEM, l_freq_ratio),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_CORE_FREQ_RATIO)");

    FAPI_DBG("Using epsilons for table type (0x%.2X), broadcast mode (0x%.2X), freq ratio (0x%.2X)",
             l_eps_table_type, l_broadcast_mode, l_freq_ratio);

    // @TODO RTC210056 Update interpretation of epsilon values for P10
    switch(l_eps_table_type)
    {
        case fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_LE:

            // Low-end with DCMs
            if (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE)
            {
                l_eps_r[0] = EPSILON_R_T0_LD[l_freq_ratio];
                l_eps_r[1] = EPSILON_R_T1_LD[l_freq_ratio];
                l_eps_r[2] = EPSILON_R_T2_LD[l_freq_ratio];
                l_eps_w[0] = EPSILON_W_T0_LD[l_freq_ratio];
                l_eps_w[1] = EPSILON_W_T1_LD[l_freq_ratio];
            }
            // Low-end with SCMs
            else if (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
            {
                l_eps_r[0] = EPSILON_R_T0_LE[l_freq_ratio];
                l_eps_r[1] = EPSILON_R_T1_LE[l_freq_ratio];
                l_eps_r[2] = EPSILON_R_T2_LE[l_freq_ratio];
                l_eps_w[0] = EPSILON_W_T0_LE[l_freq_ratio];
                l_eps_w[1] = EPSILON_W_T1_LE[l_freq_ratio];
            }
            // Low-end with SCMs (lab only)
            else if (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_NODE)
            {
                l_eps_r[0] = EPSILON_R_T0_LE[l_freq_ratio];
                l_eps_r[1] = EPSILON_R_T2_LE[l_freq_ratio];
                l_eps_r[2] = EPSILON_R_T2_LE[l_freq_ratio];
                l_eps_w[0] = EPSILON_W_T0_LE[l_freq_ratio];
                l_eps_w[1] = EPSILON_W_T1_LE[l_freq_ratio];
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::P10_FBC_EFF_CONFIG_EPSILON_UNSUPPORTED_BROADCAST_MODE_ERR()
                            .set_TABLE_TYPE(l_eps_table_type)
                            .set_BROADCAST_MODE(l_broadcast_mode),
                            "Unsupported broadcast mode for the epsilon table type!");
            }

            break;

        case fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_MR:

            // Mid-range with SCMs
            if (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
            {
                l_eps_r[0] = EPSILON_R_T0_MR[l_freq_ratio];
                l_eps_r[1] = EPSILON_R_T1_MR[l_freq_ratio];
                l_eps_r[2] = EPSILON_R_T2_MR[l_freq_ratio];
                l_eps_w[0] = EPSILON_W_T0_MR[l_freq_ratio];
                l_eps_w[1] = EPSILON_W_T1_MR[l_freq_ratio];
            }
            // Mid-range with SCMs (lab only)
            else if (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_NODE)
            {
                l_eps_r[0] = EPSILON_R_T0_MR[l_freq_ratio];
                l_eps_r[1] = EPSILON_R_T2_MR[l_freq_ratio];
                l_eps_r[2] = EPSILON_R_T2_MR[l_freq_ratio];
                l_eps_w[0] = EPSILON_W_T0_MR[l_freq_ratio];
                l_eps_w[1] = EPSILON_W_T1_MR[l_freq_ratio];
            }
            else // Mid-range with DCMs should use EPS_TYPE_HE instead
            {
                FAPI_ASSERT(false,
                            fapi2::P10_FBC_EFF_CONFIG_EPSILON_UNSUPPORTED_BROADCAST_MODE_ERR()
                            .set_TABLE_TYPE(l_eps_table_type)
                            .set_BROADCAST_MODE(l_broadcast_mode),
                            "Unsupported broadcast mode for the epsilon table type!");
            }

            break;

        case fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_HE:

            // High-end with SCMs, Mid-range with DCMs (lab only)
            if (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE)
            {
                l_eps_r[0] = EPSILON_R_T0_HE[l_freq_ratio];
                l_eps_r[1] = EPSILON_R_T1_HE[l_freq_ratio];
                l_eps_r[2] = EPSILON_R_T2_HE[l_freq_ratio];
                l_eps_w[0] = EPSILON_W_T0_HE[l_freq_ratio];
                l_eps_w[1] = EPSILON_W_T1_HE[l_freq_ratio];
            }
            // High-end Flat-8, Mid-range with DCMs (lab only)
            else if(l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
            {
                l_eps_r[0] = EPSILON_R_T0_F8[l_freq_ratio];
                l_eps_r[1] = EPSILON_R_T1_F8[l_freq_ratio];
                l_eps_r[2] = EPSILON_R_T2_F8[l_freq_ratio];
                l_eps_w[0] = EPSILON_W_T0_F8[l_freq_ratio];
                l_eps_w[1] = EPSILON_W_T1_F8[l_freq_ratio];
            }
            else // 1HOP_CHIP_IS_NODE not supported for EPS_TYPE_HE
            {
                FAPI_ASSERT(false,
                            fapi2::P10_FBC_EFF_CONFIG_EPSILON_UNSUPPORTED_BROADCAST_MODE_ERR()
                            .set_TABLE_TYPE(l_eps_table_type)
                            .set_BROADCAST_MODE(l_broadcast_mode),
                            "Unsupported broadcast mode for the epsilon table type!");
            }

            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::P10_FBC_EFF_CONFIG_EPSILON_UNSUPPORTED_TABLE_TYPE_ERR()
                        .set_TABLE_TYPE(l_eps_table_type),
                        "Unsupported epsilon table type specified!");
            break;
    }

    // dump base epsilon values
    FAPI_DBG("Base epsilon values read from table:");

    for (uint32_t ii = 0; ii < NUM_EPSILON_READ_TIERS; ii++)
    {
        FAPI_DBG("  R_T[%d] = %d", ii, l_eps_r[ii]);
    }

    for (uint32_t ii = 0; ii < NUM_EPSILON_WRITE_TIERS; ii++)
    {
        FAPI_DBG("  W_T[%d] = %d", ii, l_eps_w[ii]);
    }

    // get gardband attribute to pickup any user adjustments
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_GB_PERCENTAGE, FAPI_SYSTEM, l_eps_gb),
             "Error from FAPI_ATTR_GET (ATTR_PROC_EPS_GB_PERCENTAGE)");

    // scale based on guardband, and output final values
    FAPI_DBG("Scaled epsilon values based on %d percent guardband:", l_eps_gb);

    for (uint32_t ii = 0; ii < NUM_EPSILON_READ_TIERS; ii++)
    {
        p10_fbc_eff_config_guardband_epsilon(l_eps_gb, l_eps_r[ii]);
        FAPI_DBG("  R_T[%d] = %d", ii, l_eps_r[ii]);
    }

    for (uint32_t ii = 0; ii < NUM_EPSILON_WRITE_TIERS; ii++)
    {
        p10_fbc_eff_config_guardband_epsilon(l_eps_gb, l_eps_w[ii]);
        FAPI_DBG("  W_T[%d] = %d", ii, l_eps_w[ii]);
    }

    // check relationship of epsilon counters:
    //   read tier values are strictly increasing
    //   write tier values are strictly increaing
    FAPI_ASSERT((l_eps_r[0] <= l_eps_r[1]) &&
                (l_eps_r[1] <= l_eps_r[2]) &&
                (l_eps_w[0] <= l_eps_w[1]),
                fapi2::P10_FBC_EFF_CONFIG_EPSILON_INVALID_VALUES_ERR()
                .set_TABLE_TYPE(l_eps_table_type)
                .set_EPS_GB_PERCENTAGE(l_eps_gb)
                .set_BROADCAST_MODE(l_broadcast_mode)
                .set_R_T0(l_eps_r[0])
                .set_R_T1(l_eps_r[1])
                .set_R_T2(l_eps_r[2])
                .set_W_T0(l_eps_w[0])
                .set_W_T1(l_eps_w[1]),
                "Invalid relationship between base epsilon values!");

    // write attributes
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, FAPI_SYSTEM, l_eps_r[0]),
             "Error from FAPI_ATTR_SET (ATTR_PROC_EPS_READ_CYCLES_T0)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, FAPI_SYSTEM, l_eps_r[1]),
             "Error from FAPI_ATTR_SET (ATTR_PROC_EPS_READ_CYCLES_T1)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, FAPI_SYSTEM, l_eps_r[2]),
             "Error from FAPI_ATTR_SET (ATTR_PROC_EPS_READ_CYCLES_T2)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1, FAPI_SYSTEM, l_eps_w[0]),
             "Error from FAPI_ATTR_SET (ATTR_PROC_EPS_WRITE_CYCLES_T1)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2, FAPI_SYSTEM, l_eps_w[1]),
             "Error from FAPI_ATTR_SET (ATTR_PROC_EPS_WRITE_CYCLES_T2)");

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}

///
/// @brief Process fabric/core frequency attributes to drive fabric configuration
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_eff_config_freq_attrs(void)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_Type l_freq_floor;
    fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_Type l_freq_ceiling;
    fapi2::ATTR_PROC_FABRIC_CORE_FREQ_RATIO_Type l_freq_ratio;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ, FAPI_SYSTEM, l_freq_floor),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ, FAPI_SYSTEM, l_freq_ceiling),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ)");

    FAPI_ASSERT(l_freq_ceiling >= l_freq_floor,
                fapi2::P10_FBC_EFF_CONFIG_CORE_FREQ_RANGE_ERR()
                .set_FREQ_CORE_FLOOR(l_freq_floor)
                .set_FREQ_CORE_CEILING(l_freq_ceiling),
                "Invalid core frequency ranges! Floor: 0x%.8X, Ceiling: 0x%.8X",
                l_freq_floor, l_freq_ceiling);

    // determine table index based on core floor/ceiling frequency ratio
    // breakpoint ratio: floor 4.0, ceiling 4.0 (floor::ceiling ratio = 8/8)
    if ((8 * l_freq_floor) >= (8 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_8_8;
    }
    // breakpoint ratio: floor 3.5, ceiling 4.0 (floor::ceiling ratio = 7/8)
    else if ((8 * l_freq_floor) >= (7 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_7_8;
    }
    // breakpoint ratio: floor 3.0, ceiling 4.0 (floor::ceiling ratio = 6/8)
    else if ((8 * l_freq_floor) >= (6 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_6_8;
    }
    // breakpoint ratio: floor 2.5, ceiling 4.0 (floor::ceiling ratio = 5/8)
    else if ((8 * l_freq_floor) >= (5 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_5_8;
    }
    // breakpoint ratio: floor 2.0, ceiling 4.0 (floor::ceiling ratio = 4/8)
    else if (8 * l_freq_floor >= 4 * l_freq_ceiling)
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_4_8;
    }
    // Under-range, raise error
    else
    {
        FAPI_ASSERT(false,
                    fapi2::P10_FBC_EFF_CONFIG_CORE_FREQ_RATIO_ERR()
                    .set_FREQ_CORE_FLOOR(l_freq_floor)
                    .set_FREQ_CORE_CEILING(l_freq_ceiling),
                    "Unsupported core floor/ceiling frequency ratio = (%d/%d)",
                    l_freq_floor, l_freq_ceiling);
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_CORE_FREQ_RATIO, FAPI_SYSTEM, l_freq_ratio),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_CORE_FREQ_RATIO)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Initialize attributes related to link usage
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_eff_config_link_attrs(void)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_pos;
    fapi2::ATTR_FREQ_PROC_IOHS_MHZ_Type l_freq_proc_iohs_mhz;
    fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_link_inactive = fapi2::ENUM_ATTR_PROC_FABRIC_LINK_ACTIVE_FALSE;
    fapi2::ATTR_PROC_FABRIC_ASYNC_MODE_Type l_async_perf_mode = fapi2::ENUM_ATTR_PROC_FABRIC_ASYNC_MODE_PERF_MODE;
    fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_broadcast_mode;
    fapi2::ATTR_PROC_FABRIC_PRESENT_GROUPS_Type l_present_groups;
    fapi2::ATTR_PROC_FABRIC_A_INDIRECT_Type l_a_indirect;
    uint8_t l_num_groups = 0;

    for (auto l_proc_target : FAPI_SYSTEM.getChildren<fapi2::TARGET_TYPE_PROC_CHIP>())
    {
        for (auto l_iohs_target : l_proc_target.getChildren<fapi2::TARGET_TYPE_IOHS>())
        {
            // reset fabric link active for concurrent repairs
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE, l_iohs_target, l_link_inactive),
                     "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_LINK_ACTIVE");

            // shadow iohs frequency to proc scope for fabric initfiles
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_iohs_pos),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_IOHS_MHZ, l_iohs_target, l_freq_proc_iohs_mhz[l_iohs_pos]),
                     "Error from FAPI_ATTR_GET (ATTR_FREQ_IOHS_MHZ)");
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_PROC_IOHS_MHZ, l_proc_target, l_freq_proc_iohs_mhz),
                     "Error form FAPI_ATTR_GET (ATTR_FREQ_PROC_IOHS_MHZ)");
        }
    }

    // set async mode
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_ASYNC_MODE, FAPI_SYSTEM, l_async_perf_mode),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_ASYNC_MODE)");

    // set indirect data routing for alinks (chip_is_group pump and >= 4 groups)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, FAPI_SYSTEM, l_broadcast_mode),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_BROADCAST_MODE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PRESENT_GROUPS, FAPI_SYSTEM, l_present_groups),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_PRESENT_GROUPS)");

    for (uint8_t ii = 0; ii < P10_FBC_UTILS_MAX_CHIPS; ii++)
    {
        if(l_present_groups & 0x01)
        {
            l_num_groups++;
        }

        l_present_groups >>= 1;
    }

    l_a_indirect = ((l_num_groups >= 4)
                    && (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)) ?
                   (fapi2::ENUM_ATTR_PROC_FABRIC_A_INDIRECT_ON) : (fapi2::ENUM_ATTR_PROC_FABRIC_A_INDIRECT_OFF);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_INDIRECT, FAPI_SYSTEM, l_a_indirect),
             "Error form FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_INDIRECT)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_fbc_eff_config(void)
{
    FAPI_DBG("Start");

    FAPI_TRY(p10_fbc_eff_config_freq_attrs(),
             "Error from p10_fbc_eff_config_freq_attrs");
    FAPI_TRY(p10_fbc_eff_config_calc_epsilons(),
             "Error from p10_fbc_eff_config_calc_epsilons");
    FAPI_TRY(p10_fbc_eff_config_link_attrs(),
             "Error from p10_fbc_eff_config_link_attrs");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
