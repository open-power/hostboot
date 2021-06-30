/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_eff_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

//
// PAU: 2588 MHz (20% GB)
//

// Low-end Epsilons (4 chips/group, 1 group), DLR disabled/half
// Product offerings: Rainier (low-end with DCMs)
const uint32_t EPSILON_2588_R_T0_LE[] = {  10,  10,  10,  10,  10,  10,  10,  11,  11 };
const uint32_t EPSILON_2588_R_T1_LE[] = {  10,  10,  10,  10,  10,  10,  10,  11,  11 };
const uint32_t EPSILON_2588_R_T2_LE[] = { 300, 318, 318, 342, 342, 376, 376, 427, 427 };
const uint32_t EPSILON_2588_W_T0_LE[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
const uint32_t EPSILON_2588_W_T1_LE[] = { 207, 212, 212, 219, 219, 228, 228, 243, 243 };

// Low-end Epsilons (4 chips/group, 1 group), DLR quarter-width
// Product offerings: Rainier (low-end with DCMs)
const uint32_t EPSILON_2588_R_T0_LQ[] = {  10,  10,  10,  10,  10,  10,  10,  11,  11 };
const uint32_t EPSILON_2588_R_T1_LQ[] = {  10,  10,  10,  10,  10,  10,  10,  11,  11 };
const uint32_t EPSILON_2588_R_T2_LQ[] = { 375, 393, 393, 417, 417, 451, 451, 502, 502 };
const uint32_t EPSILON_2588_W_T0_LQ[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
const uint32_t EPSILON_2588_W_T1_LQ[] = { 282, 287, 287, 294, 294, 303, 303, 318, 318 };

// Mid-range Epsilons (8 chips/group, 1 group)
// Product offerings: Everest (mid-range with DCMs), Denali Flat-8
const uint32_t EPSILON_2588_R_T0_MR[] = {  10,  10,  10,  10,  10,  10,  10,  11,  11 };
const uint32_t EPSILON_2588_R_T1_MR[] = {  10,  10,  10,  10,  10,  10,  10,  11,  11 };
const uint32_t EPSILON_2588_R_T2_MR[] = { 293, 307, 307, 327, 327, 354, 354, 394, 394 };
const uint32_t EPSILON_2588_W_T0_MR[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
const uint32_t EPSILON_2588_W_T1_MR[] = { 156, 154, 154, 151, 151, 147, 147, 142, 142 };

// High-end Epsilons (4 chips/group, 4 groups)
// Product offerings: Denali (high-end with SCMs)
const uint32_t EPSILON_2588_R_T0_HE[] = {  10,  10,  10,  10,  10,  10,  10,  11,  11 };
const uint32_t EPSILON_2588_R_T1_HE[] = { 304, 322, 322, 346, 346, 380, 380, 431, 431 };
const uint32_t EPSILON_2588_R_T2_HE[] = { 526, 559, 559, 604, 604, 665, 665, 758, 758 };
const uint32_t EPSILON_2588_W_T0_HE[] = { 197, 202, 202, 209, 209, 219, 219, 233, 233 };
const uint32_t EPSILON_2588_W_T1_HE[] = { 401, 422, 422, 450, 450, 490, 490, 550, 550 };

//
// PAU: 2167 MHz (15% GB)
//

// Low-end Epsilons (4 chips/group, 1 group), DLR disabled/half
// Product offerings: Rainier (low-end with DCMs)
const uint32_t EPSILON_2167_R_T0_LE[] = {   9,   9,   9,  10,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2167_R_T1_LE[] = {   9,   9,   9,  10,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2167_R_T2_LE[] = { 261, 269, 276, 286, 295, 309, 323, 343, 364 };
const uint32_t EPSILON_2167_W_T0_LE[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
const uint32_t EPSILON_2167_W_T1_LE[] = { 187, 189, 191, 194, 196, 200, 204, 210, 215 };

// Low-end Epsilons (4 chips/group, 1 group), DLR quarter-width
// Product offerings: Rainier (low-end with DCMs)
// NOT UPDATED 6/30
const uint32_t EPSILON_2167_R_T0_LQ[] = {  10,  10,  10,  10,  10,  10,  10,  11,  11 };
const uint32_t EPSILON_2167_R_T1_LQ[] = {  10,  10,  10,  10,  10,  10,  10,  11,  11 };
const uint32_t EPSILON_2167_R_T2_LQ[] = { 375, 393, 393, 417, 417, 451, 451, 502, 502 };
const uint32_t EPSILON_2167_W_T0_LQ[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
const uint32_t EPSILON_2167_W_T1_LQ[] = { 282, 287, 287, 294, 294, 303, 303, 318, 318 };

// Mid-range Epsilons (8 chips/group, 1 group)
// Product offerings: Everest (mid-range with DCMs), Denali Flat-8
const uint32_t EPSILON_2167_R_T0_MR[] = {   9,   9,   9,  10,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2167_R_T1_MR[] = {   9,   9,   9,  10,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2167_R_T2_MR[] = { 257, 262, 268, 276, 284, 294, 305, 321, 338 };
const uint32_t EPSILON_2167_W_T0_MR[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
const uint32_t EPSILON_2167_W_T1_MR[] = { 146, 145, 145, 144, 142, 141, 139, 137, 135 };

// High-end Epsilons (4 chips/group, 4 groups)
// Product offerings: Denali (high-end with SCMs)
const uint32_t EPSILON_2167_R_T0_HE[] = {   9,   9,   9,  10,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2167_R_T1_HE[] = { 265, 273, 280, 290, 299, 313, 327, 347, 368 };
const uint32_t EPSILON_2167_R_T2_HE[] = { 455, 468, 481, 499, 517, 542, 566, 603, 641 };
const uint32_t EPSILON_2167_W_T0_HE[] = { 180, 182, 184, 186, 189, 193, 197, 203, 208 };
const uint32_t EPSILON_2167_W_T1_HE[] = { 353, 361, 370, 381, 393, 408, 424, 448, 472 };

//
// PAU: 2133 MHz (15% GB)
//

// Low-end Epsilons (4 chips/group, 1 group), DLR disabled/half
// Product offerings: Rainier (low-end with DCMs)
const uint32_t EPSILON_2133_R_T0_LE[] = {   9,   9,   9,  10,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2133_R_T1_LE[] = {   9,   9,   9,  10,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2133_R_T2_LE[] = { 259, 266, 274, 283, 293, 306, 320, 340, 360 };
const uint32_t EPSILON_2133_W_T0_LE[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
const uint32_t EPSILON_2133_W_T1_LE[] = { 186, 188, 190, 192, 195, 199, 203, 208, 214 };

// Low-end Epsilons (4 chips/group, 1 group), DLR quarter-width
// Product offerings: Rainier (low-end with DCMs)
// NOT UPDATED 6/30
const uint32_t EPSILON_2133_R_T0_LQ[] = {  10,  10,  10,  10,  10,  10,  10,  11,  11 };
const uint32_t EPSILON_2133_R_T1_LQ[] = {  10,  10,  10,  10,  10,  10,  10,  11,  11 };
const uint32_t EPSILON_2133_R_T2_LQ[] = { 375, 393, 393, 417, 417, 451, 451, 502, 502 };
const uint32_t EPSILON_2133_W_T0_LQ[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
const uint32_t EPSILON_2133_W_T1_LQ[] = { 282, 287, 287, 294, 294, 303, 303, 318, 318 };

// Mid-range Epsilons (8 chips/group, 1 group)
// Product offerings: Everest (mid-range with DCMs), Denali Flat-8
const uint32_t EPSILON_2133_R_T0_MR[] = {   9,   9,   9,  10,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2133_R_T1_MR[] = {   9,   9,   9,  10,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2133_R_T2_MR[] = { 255, 260, 266, 274, 281, 292, 302, 318, 334 };
const uint32_t EPSILON_2133_W_T0_MR[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
const uint32_t EPSILON_2133_W_T1_MR[] = { 146, 145, 144, 143, 142, 141, 139, 137, 135 };

// High-end Epsilons (4 chips/group, 4 groups)
// Product offerings: Denali (high-end with SCMs)
const uint32_t EPSILON_2133_R_T0_HE[] = {   9,   9,   9,  10,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2133_R_T1_HE[] = { 263, 270, 278, 287, 297, 310, 324, 344, 364 };
const uint32_t EPSILON_2133_R_T2_HE[] = { 451, 464, 477, 494, 512, 536, 560, 597, 634 };
const uint32_t EPSILON_2133_W_T0_HE[] = { 179, 181, 183, 186, 188, 192, 196, 201, 207 };
const uint32_t EPSILON_2133_W_T1_HE[] = { 350, 358, 367, 378, 389, 405, 421, 444, 468 };

//
// PAU: 2050 MHz (15% GB)
//

// Low-end Epsilons (4 chips/group, 1 group), DLR disabled/half
// Product offerings: Rainier (low-end with DCMs)
const uint32_t EPSILON_2050_R_T0_LE[] = {   9,   9,   9,   9,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2050_R_T1_LE[] = {   9,   9,   9,   9,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2050_R_T2_LE[] = { 254, 261, 268, 277, 286, 299, 312, 331, 351 };
const uint32_t EPSILON_2050_W_T0_LE[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
const uint32_t EPSILON_2050_W_T1_LE[] = { 183, 185, 187, 190, 192, 196, 200, 205, 210 };

// Low-end Epsilons (4 chips/group, 1 group), DLR quarter-width
// Product offerings: Rainier (low-end with DCMs)
const uint32_t EPSILON_2050_R_T0_LQ[] = {   9,   9,   9,  10,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2050_R_T1_LQ[] = {   9,   9,   9,  10,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2050_R_T2_LQ[] = { 325, 340, 340, 359, 359, 386, 386, 426, 426 };
const uint32_t EPSILON_2050_W_T0_LQ[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
const uint32_t EPSILON_2050_W_T1_LQ[] = { 251, 256, 256, 261, 261, 268, 268, 280, 280 };

// Mid-range Epsilons (8 chips/group, 1 group)
// Product offerings: Everest (mid-range with DCMs), Denali Flat-8
const uint32_t EPSILON_2050_R_T0_MR[] = {   9,   9,   9,   9,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2050_R_T1_MR[] = {   9,   9,   9,   9,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2050_R_T2_MR[] = { 250, 255, 261, 268, 275, 286, 296, 311, 326 };
const uint32_t EPSILON_2050_W_T0_MR[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
const uint32_t EPSILON_2050_W_T1_MR[] = { 145, 144, 144, 143, 142, 140, 139, 137, 135 };

// High-end Epsilons (4 chips/group, 4 groups)
// Product offerings: Denali (high-end with SCMs)
const uint32_t EPSILON_2050_R_T0_HE[] = {   9,   9,   9,   9,  10,  10,  10,  10,  10 };
const uint32_t EPSILON_2050_R_T1_HE[] = { 258, 265, 272, 281, 290, 303, 316, 335, 355 };
const uint32_t EPSILON_2050_R_T2_HE[] = { 441, 453, 466, 483, 499, 523, 546, 581, 617 };
const uint32_t EPSILON_2050_W_T0_HE[] = { 177, 179, 181, 183, 186, 189, 193, 199, 204 };
const uint32_t EPSILON_2050_W_T1_HE[] = { 344, 352, 360, 371, 381, 397, 412, 434, 457 };

// LCO constants
const uint8_t MAX_L3_TARGETS = 32;

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

        if (io_target_value)
        {
            io_target_value += 1;
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
    fapi2::ATTR_PROC_FABRIC_DLR_PSAVE_MODE_Type l_dlr_mode;
    fapi2::ATTR_FREQ_PAU_MHZ_Type l_pau_freq;
    uint32_t l_eps_r[NUM_EPSILON_READ_TIERS];
    uint32_t l_eps_w[NUM_EPSILON_WRITE_TIERS];
    const uint32_t* EPSILON_R_T0_LE;
    const uint32_t* EPSILON_R_T1_LE;
    const uint32_t* EPSILON_R_T2_LE;
    const uint32_t* EPSILON_W_T0_LE;
    const uint32_t* EPSILON_W_T1_LE;
    const uint32_t* EPSILON_R_T0_LQ;
    const uint32_t* EPSILON_R_T1_LQ;
    const uint32_t* EPSILON_R_T2_LQ;
    const uint32_t* EPSILON_W_T0_LQ;
    const uint32_t* EPSILON_W_T1_LQ;
    const uint32_t* EPSILON_R_T0_MR;
    const uint32_t* EPSILON_R_T1_MR;
    const uint32_t* EPSILON_R_T2_MR;
    const uint32_t* EPSILON_W_T0_MR;
    const uint32_t* EPSILON_W_T1_MR;
    const uint32_t* EPSILON_R_T0_HE;
    const uint32_t* EPSILON_R_T1_HE;
    const uint32_t* EPSILON_R_T2_HE;
    const uint32_t* EPSILON_W_T0_HE;
    const uint32_t* EPSILON_W_T1_HE;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_TABLE_TYPE, FAPI_SYSTEM, l_eps_table_type),
             "Error from FAPI_ATTR_GET(ATTR_PROC_EPS_TABLE_TYPE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, FAPI_SYSTEM, l_broadcast_mode),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_BROADCAST_MODE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CORE_FREQ_RATIO, FAPI_SYSTEM, l_freq_ratio),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_CORE_FREQ_RATIO)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_DLR_PSAVE_MODE, FAPI_SYSTEM, l_dlr_mode),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_DLR_PSAVE_MODE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PAU_MHZ, FAPI_SYSTEM, l_pau_freq),
             "Error from FAPI_ATTR_GET(ATTR_FREQ_PAU_MHZ)");

    FAPI_DBG("Using epsilons for freq (%d MHz), table type (0x%.2X), broadcast mode (0x%.2X), freq ratio (0x%.2X), dlr mode (0x%.2X)",
             l_pau_freq, l_eps_table_type, l_broadcast_mode, l_freq_ratio, l_dlr_mode);

    switch(l_pau_freq)
    {
        case 2050:
            EPSILON_R_T0_LE = EPSILON_2050_R_T0_LE;
            EPSILON_R_T1_LE = EPSILON_2050_R_T1_LE;
            EPSILON_R_T2_LE = EPSILON_2050_R_T2_LE;
            EPSILON_W_T0_LE = EPSILON_2050_W_T0_LE;
            EPSILON_W_T1_LE = EPSILON_2050_W_T1_LE;

            EPSILON_R_T0_LQ = EPSILON_2050_R_T0_LQ;
            EPSILON_R_T1_LQ = EPSILON_2050_R_T1_LQ;
            EPSILON_R_T2_LQ = EPSILON_2050_R_T2_LQ;
            EPSILON_W_T0_LQ = EPSILON_2050_W_T0_LQ;
            EPSILON_W_T1_LQ = EPSILON_2050_W_T1_LQ;

            EPSILON_R_T0_MR = EPSILON_2050_R_T0_MR;
            EPSILON_R_T1_MR = EPSILON_2050_R_T1_MR;
            EPSILON_R_T2_MR = EPSILON_2050_R_T2_MR;
            EPSILON_W_T0_MR = EPSILON_2050_W_T0_MR;
            EPSILON_W_T1_MR = EPSILON_2050_W_T1_MR;

            EPSILON_R_T0_HE = EPSILON_2050_R_T0_HE;
            EPSILON_R_T1_HE = EPSILON_2050_R_T1_HE;
            EPSILON_R_T2_HE = EPSILON_2050_R_T2_HE;
            EPSILON_W_T0_HE = EPSILON_2050_W_T0_HE;
            EPSILON_W_T1_HE = EPSILON_2050_W_T1_HE;
            break;

        case 2133:
            EPSILON_R_T0_LE = EPSILON_2133_R_T0_LE;
            EPSILON_R_T1_LE = EPSILON_2133_R_T1_LE;
            EPSILON_R_T2_LE = EPSILON_2133_R_T2_LE;
            EPSILON_W_T0_LE = EPSILON_2133_W_T0_LE;
            EPSILON_W_T1_LE = EPSILON_2133_W_T1_LE;

            EPSILON_R_T0_LQ = EPSILON_2133_R_T0_LQ;
            EPSILON_R_T1_LQ = EPSILON_2133_R_T1_LQ;
            EPSILON_R_T2_LQ = EPSILON_2133_R_T2_LQ;
            EPSILON_W_T0_LQ = EPSILON_2133_W_T0_LQ;
            EPSILON_W_T1_LQ = EPSILON_2133_W_T1_LQ;

            EPSILON_R_T0_MR = EPSILON_2133_R_T0_MR;
            EPSILON_R_T1_MR = EPSILON_2133_R_T1_MR;
            EPSILON_R_T2_MR = EPSILON_2133_R_T2_MR;
            EPSILON_W_T0_MR = EPSILON_2133_W_T0_MR;
            EPSILON_W_T1_MR = EPSILON_2133_W_T1_MR;

            EPSILON_R_T0_HE = EPSILON_2133_R_T0_HE;
            EPSILON_R_T1_HE = EPSILON_2133_R_T1_HE;
            EPSILON_R_T2_HE = EPSILON_2133_R_T2_HE;
            EPSILON_W_T0_HE = EPSILON_2133_W_T0_HE;
            EPSILON_W_T1_HE = EPSILON_2133_W_T1_HE;
            break;

        case 2167:
            EPSILON_R_T0_LE = EPSILON_2167_R_T0_LE;
            EPSILON_R_T1_LE = EPSILON_2167_R_T1_LE;
            EPSILON_R_T2_LE = EPSILON_2167_R_T2_LE;
            EPSILON_W_T0_LE = EPSILON_2167_W_T0_LE;
            EPSILON_W_T1_LE = EPSILON_2167_W_T1_LE;

            EPSILON_R_T0_LQ = EPSILON_2167_R_T0_LQ;
            EPSILON_R_T1_LQ = EPSILON_2167_R_T1_LQ;
            EPSILON_R_T2_LQ = EPSILON_2167_R_T2_LQ;
            EPSILON_W_T0_LQ = EPSILON_2167_W_T0_LQ;
            EPSILON_W_T1_LQ = EPSILON_2167_W_T1_LQ;

            EPSILON_R_T0_MR = EPSILON_2167_R_T0_MR;
            EPSILON_R_T1_MR = EPSILON_2167_R_T1_MR;
            EPSILON_R_T2_MR = EPSILON_2167_R_T2_MR;
            EPSILON_W_T0_MR = EPSILON_2167_W_T0_MR;
            EPSILON_W_T1_MR = EPSILON_2167_W_T1_MR;

            EPSILON_R_T0_HE = EPSILON_2167_R_T0_HE;
            EPSILON_R_T1_HE = EPSILON_2167_R_T1_HE;
            EPSILON_R_T2_HE = EPSILON_2167_R_T2_HE;
            EPSILON_W_T0_HE = EPSILON_2167_W_T0_HE;
            EPSILON_W_T1_HE = EPSILON_2167_W_T1_HE;
            break;

        case 2588:
            EPSILON_R_T0_LE = EPSILON_2588_R_T0_LE;
            EPSILON_R_T1_LE = EPSILON_2588_R_T1_LE;
            EPSILON_R_T2_LE = EPSILON_2588_R_T2_LE;
            EPSILON_W_T0_LE = EPSILON_2588_W_T0_LE;
            EPSILON_W_T1_LE = EPSILON_2588_W_T1_LE;

            EPSILON_R_T0_LQ = EPSILON_2588_R_T0_LQ;
            EPSILON_R_T1_LQ = EPSILON_2588_R_T1_LQ;
            EPSILON_R_T2_LQ = EPSILON_2588_R_T2_LQ;
            EPSILON_W_T0_LQ = EPSILON_2588_W_T0_LQ;
            EPSILON_W_T1_LQ = EPSILON_2588_W_T1_LQ;

            EPSILON_R_T0_MR = EPSILON_2588_R_T0_MR;
            EPSILON_R_T1_MR = EPSILON_2588_R_T1_MR;
            EPSILON_R_T2_MR = EPSILON_2588_R_T2_MR;
            EPSILON_W_T0_MR = EPSILON_2588_W_T0_MR;
            EPSILON_W_T1_MR = EPSILON_2588_W_T1_MR;

            EPSILON_R_T0_HE = EPSILON_2588_R_T0_HE;
            EPSILON_R_T1_HE = EPSILON_2588_R_T1_HE;
            EPSILON_R_T2_HE = EPSILON_2588_R_T2_HE;
            EPSILON_W_T0_HE = EPSILON_2588_W_T0_HE;
            EPSILON_W_T1_HE = EPSILON_2588_W_T1_HE;
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::P10_FBC_EFF_CONFIG_EPSILON_UNSUPPORTED_PAU_FREQ_ERR()
                        .set_PAU_FREQ(l_pau_freq),
                        "Unsupported PAU frequency specified for epsilon table lookup!");
            break;
    }

    switch(l_eps_table_type)
    {
        case fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_LE:

            if ((l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_DISABLED)
                || (l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_HALF)
                || (l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_FULL_HALF))
            {
                // Low-end with DCMs
                if (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
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
            }
            else // DLR quarter-width psave mode
            {
                // Low-end with DCMs
                if (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                {
                    l_eps_r[0] = EPSILON_R_T0_LQ[l_freq_ratio];
                    l_eps_r[1] = EPSILON_R_T1_LQ[l_freq_ratio];
                    l_eps_r[2] = EPSILON_R_T2_LQ[l_freq_ratio];
                    l_eps_w[0] = EPSILON_W_T0_LQ[l_freq_ratio];
                    l_eps_w[1] = EPSILON_W_T1_LQ[l_freq_ratio];
                }
                // Low-end with SCMs (lab only)
                else if (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_NODE)
                {
                    l_eps_r[0] = EPSILON_R_T0_LQ[l_freq_ratio];
                    l_eps_r[1] = EPSILON_R_T2_LQ[l_freq_ratio];
                    l_eps_r[2] = EPSILON_R_T2_LQ[l_freq_ratio];
                    l_eps_w[0] = EPSILON_W_T0_LQ[l_freq_ratio];
                    l_eps_w[1] = EPSILON_W_T1_LQ[l_freq_ratio];
                }
                else
                {
                    FAPI_ASSERT(false,
                                fapi2::P10_FBC_EFF_CONFIG_EPSILON_UNSUPPORTED_BROADCAST_MODE_ERR()
                                .set_TABLE_TYPE(l_eps_table_type)
                                .set_BROADCAST_MODE(l_broadcast_mode),
                                "Unsupported broadcast mode for the epsilon table type!");
                }
            }

            break;

        case fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_MR:

            // Mid-range with DCMs (same as Flat-8 configuration)
            if (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
            {
                if (l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_DISABLED)
                {
                    l_eps_r[0] = EPSILON_R_T0_MR[l_freq_ratio];
                    l_eps_r[1] = EPSILON_R_T1_MR[l_freq_ratio];
                    l_eps_r[2] = EPSILON_R_T2_MR[l_freq_ratio];
                    l_eps_w[0] = EPSILON_W_T0_MR[l_freq_ratio];
                    l_eps_w[1] = EPSILON_W_T1_MR[l_freq_ratio];
                }
                // Mid-range uses single 1x9 links, psave half mode looks like quarter of full width
                else if ((l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_HALF)
                         || (l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_FULL_HALF))
                {
                    l_eps_r[0] = EPSILON_R_T0_LQ[l_freq_ratio];
                    l_eps_r[1] = EPSILON_R_T2_LQ[l_freq_ratio];
                    l_eps_r[2] = EPSILON_R_T2_LQ[l_freq_ratio];
                    l_eps_w[0] = EPSILON_W_T0_LQ[l_freq_ratio];
                    l_eps_w[1] = EPSILON_W_T1_LQ[l_freq_ratio];
                }
                else // Quarter-width psave is not valid for mid-range
                {
                    FAPI_ASSERT(false,
                                fapi2::P10_FBC_EFF_CONFIG_EPSILON_UNSUPPORTED_DLR_PSAVE_MODE_ERR()
                                .set_TABLE_TYPE(l_eps_table_type)
                                .set_DLR_PSAVE_MODE(l_dlr_mode),
                                "Unsupported dlr psave mode for the epsilon table type!");
                }
            }
            else // 1HOP/2HOP_CHIP_IS_NODE not supported for EPS_TYPE_MR
            {
                FAPI_ASSERT(false,
                            fapi2::P10_FBC_EFF_CONFIG_EPSILON_UNSUPPORTED_BROADCAST_MODE_ERR()
                            .set_TABLE_TYPE(l_eps_table_type)
                            .set_BROADCAST_MODE(l_broadcast_mode),
                            "Unsupported broadcast mode for the epsilon table type!");
            }

            break;

        case fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_HE:

            // High-end with SCMs
            if (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE)
            {
                if ((l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_DISABLED)
                    || (l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_HALF)
                    || (l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_FULL_HALF))
                {
                    l_eps_r[0] = EPSILON_R_T0_HE[l_freq_ratio];
                    l_eps_r[1] = EPSILON_R_T1_HE[l_freq_ratio];
                    l_eps_r[2] = EPSILON_R_T2_HE[l_freq_ratio];
                    l_eps_w[0] = EPSILON_W_T0_HE[l_freq_ratio];
                    l_eps_w[1] = EPSILON_W_T1_HE[l_freq_ratio];
                }
                else // DLR quarter-width psave mode is not supported on HE configurations
                {
                    FAPI_ASSERT(false,
                                fapi2::P10_FBC_EFF_CONFIG_EPSILON_UNSUPPORTED_DLR_PSAVE_MODE_ERR()
                                .set_TABLE_TYPE(l_eps_table_type)
                                .set_DLR_PSAVE_MODE(l_dlr_mode),
                                "Unsupported dlr psave mode for the epsilon table type!");
                }
            }
            // High-end Flat-8 (lab only)
            else if(l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
            {
                if (l_dlr_mode == fapi2::ENUM_ATTR_PROC_FABRIC_DLR_PSAVE_MODE_DISABLED)
                {
                    l_eps_r[0] = EPSILON_R_T0_MR[l_freq_ratio];
                    l_eps_r[1] = EPSILON_R_T1_MR[l_freq_ratio];
                    l_eps_r[2] = EPSILON_R_T2_MR[l_freq_ratio];
                    l_eps_w[0] = EPSILON_W_T0_MR[l_freq_ratio];
                    l_eps_w[1] = EPSILON_W_T1_MR[l_freq_ratio];
                }
                else // DLR psave is not supported for 8-chips/group configuration
                {
                    FAPI_ASSERT(false,
                                fapi2::P10_FBC_EFF_CONFIG_EPSILON_UNSUPPORTED_DLR_PSAVE_MODE_ERR()
                                .set_TABLE_TYPE(l_eps_table_type)
                                .set_DLR_PSAVE_MODE(l_dlr_mode),
                                "Unsupported dlr psave mode for the epsilon table type!");
                }
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
    // breakpoint ratio: floor 4.0, ceiling 4.0 (floor::ceiling ratio = 16/16)
    if ((16 * l_freq_floor) >= (16 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_16_16;
    }
    // breakpoint ratio: floor 3.75, ceiling 4.0 (floor::ceiling ratio = 15/16)
    else if ((16 * l_freq_floor) >= (15 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_15_16;
    }
    // breakpoint ratio: floor 3.5, ceiling 4.0 (floor::ceiling ratio = 14/16)
    else if ((16 * l_freq_floor) >= (14 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_14_16;
    }
    // breakpoint ratio: floor 3.25, ceiling 4.0 (floor::ceiling ratio = 13/16)
    else if ((16 * l_freq_floor) >= (13 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_13_16;
    }
    // breakpoint ratio: floor 3.0, ceiling 4.0 (floor::ceiling ratio = 12/16)
    else if ((16 * l_freq_floor) >= (12 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_12_16;
    }
    // breakpoint ratio: floor 2.75, ceiling 4.0 (floor::ceiling ratio = 11/16)
    else if ((16 * l_freq_floor) >= (11 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_11_16;
    }
    // breakpoint ratio: floor 2.5, ceiling 4.0 (floor::ceiling ratio = 10/16)
    else if ((16 * l_freq_floor) >= (10 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_10_16;
    }
    // breakpoint ratio: floor 2.25, ceiling 4.0 (floor::ceiling ratio = 9/16)
    else if ((16 * l_freq_floor) >= (9 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_09_16;
    }
    // breakpoint ratio: floor 2.0, ceiling 4.0 (floor::ceiling ratio = 8/16)
    else if ((16 * l_freq_floor) >= (8 * l_freq_ceiling))
    {
        l_freq_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FREQ_RATIO_RATIO_08_16;
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
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target = FAPI_SYSTEM.getChildren<fapi2::TARGET_TYPE_PROC_CHIP>().front();

    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_pos;
    fapi2::ATTR_FREQ_PROC_IOHS_MHZ_Type l_freq_proc_iohs_mhz;
    fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_link_inactive = fapi2::ENUM_ATTR_PROC_FABRIC_LINK_ACTIVE_FALSE;
    fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_broadcast_mode;
    fapi2::ATTR_PROC_FABRIC_PRESENT_GROUPS_Type l_present_groups;
    fapi2::ATTR_PROC_FABRIC_A_INDIRECT_Type l_a_indirect;
    fapi2::ATTR_CHIP_EC_FEATURE_HW543384_Type l_hw543384;
    fapi2::ATTR_HW543384_WAR_MODE_Type l_hw543384_war_mode;
    uint8_t l_num_groups = 0;

    for (auto l_proc_target : FAPI_SYSTEM.getChildren<fapi2::TARGET_TYPE_PROC_CHIP>())
    {
        for (auto l_iohs_target : l_proc_target.getChildren<fapi2::TARGET_TYPE_IOHS>())
        {
            fapi2::ATTR_IOHS_LINK_SPLIT_Type l_link_split;
            // reset fabric link active for concurrent repairs
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE, l_iohs_target, l_link_inactive),
                     "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_LINK_ACTIVE");

            // shadow iohs frequency to proc scope for fabric initfiles
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_SPLIT, l_iohs_target, l_link_split),
                     "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_SPLIT)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_iohs_pos),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_IOHS_MHZ, l_iohs_target, l_freq_proc_iohs_mhz[l_iohs_pos]),
                     "Error from FAPI_ATTR_GET (ATTR_FREQ_IOHS_MHZ)");

            if ((l_iohs_pos % 2) && (l_link_split == fapi2::ENUM_ATTR_IOHS_LINK_SPLIT_TRUE))
            {
                l_freq_proc_iohs_mhz[l_iohs_pos - 1] = l_freq_proc_iohs_mhz[l_iohs_pos];
            }

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_PROC_IOHS_MHZ, l_proc_target, l_freq_proc_iohs_mhz),
                     "Error form FAPI_ATTR_GET (ATTR_FREQ_PROC_IOHS_MHZ)");
        }
    }

    // set indirect data routing for alinks (chip_is_group pump and >= 4 groups)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, FAPI_SYSTEM, l_broadcast_mode),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_BROADCAST_MODE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PRESENT_GROUPS, FAPI_SYSTEM, l_present_groups),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_PRESENT_GROUPS)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW543384, l_target, l_hw543384),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW543384)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HW543384_WAR_MODE, FAPI_SYSTEM, l_hw543384_war_mode),
             "Error from FAPI_ATTR_GET (ATTR_HW543384_WAR_MODE)");

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

    if(l_hw543384 && (l_hw543384_war_mode == fapi2::ENUM_ATTR_HW543384_WAR_MODE_NONE))
    {
        l_a_indirect = fapi2::ENUM_ATTR_PROC_FABRIC_A_INDIRECT_OFF;
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_INDIRECT, FAPI_SYSTEM, l_a_indirect),
             "Error form FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_INDIRECT)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Initialize attributes related to LCO configuration
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_eff_config_lco_attrs(void)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    for (auto& l_target : FAPI_SYSTEM.getChildren<fapi2::TARGET_TYPE_PROC_CHIP>())
    {
        fapi2::ATTR_PROC_LCO_TARGETS_COUNT_Type l_lco_count = {0};
        fapi2::ATTR_PROC_LCO_TARGETS_VECTOR_Type l_lco_targets = {0};
        fapi2::ATTR_PROC_LCO_TARGETS_MIN_Type l_lco_min = {0};
        fapi2::ATTR_PROC_LCO_TARGETS_MIN_Type l_lco_min_threshold = {0};

        // lco_targets_count: number of valid L3 targets
        // lco_targets_vector: enable only valid L3s
        for (auto& l_core : l_target.getChildren<fapi2::TARGET_TYPE_CORE>())
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_core_id;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_core, l_core_id),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            l_lco_count[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_COUNT_CHIP]++;
            l_lco_targets[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_VECTOR_CHIP] |= (0x1 << (31 - l_core_id));

            if((l_core_id / 4) % 2)
            {
                l_lco_count[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_COUNT_EAST]++;
                l_lco_targets[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_VECTOR_EAST] |= (0x1 << (31 - l_core_id));
            }
            else
            {
                l_lco_count[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_COUNT_WEST]++;
                l_lco_targets[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_VECTOR_WEST] |= (0x1 << (31 - l_core_id));
            }
        }

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_LCO_TARGETS_COUNT, l_target, l_lco_count),
                 "Error from FAPI_ATTR_SET (ATTR_PROC_LCO_TARGETS_COUNT)");
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_LCO_TARGETS_VECTOR, l_target, l_lco_targets),
                 "Error from FAPI_ATTR_SET (ATTR_PROC_LCO_TARGETS_VECTOR)");

        // lco_targets_min:
        // let lco_min_threshold = 2/3 of max possible L3s in a chip/hemisphere
        //   if 0 L3s or 1 L3, set to zero/one respectively
        //   if lco_min_threshold or less, set to one less than number of L3s
        //   if more than lco_min_threshold, set to lco_min_threshold
        l_lco_min_threshold[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_MIN_CHIP] = ((2 * MAX_L3_TARGETS) / 3);
        l_lco_min_threshold[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_MIN_WEST] = ((2 * (MAX_L3_TARGETS / 2)) / 3);
        l_lco_min_threshold[fapi2::ENUM_ATTR_PROC_LCO_TARGETS_MIN_EAST] = ((2 * (MAX_L3_TARGETS / 2)) / 3);

        for(uint8_t l_domain = 0; l_domain < fapi2::ENUM_ATTR_PROC_LCO_TARGETS_MIN_NUM_DOMAINS; l_domain++)
        {
            if ((l_lco_count[l_domain] == 0) || (l_lco_count[l_domain] == 1))
            {
                l_lco_min[l_domain] = l_lco_count[l_domain];
            }
            else if (l_lco_count[l_domain] < l_lco_min_threshold[l_domain])
            {
                l_lco_min[l_domain] = l_lco_count[l_domain] - 1;
            }
            else
            {
                l_lco_min[l_domain] = l_lco_min_threshold[l_domain];
            }
        }

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_LCO_TARGETS_MIN, l_target, l_lco_min),
                 "Error from FAPI_ATTR_SET (ATTR_PROC_LCO_TARGETS_MIN)");
    }

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
    FAPI_TRY(p10_fbc_eff_config_lco_attrs(),
             "Error from p10_fbc_eff_config_lco_attrs");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
