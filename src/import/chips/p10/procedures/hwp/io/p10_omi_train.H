/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_omi_train.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_omi_train.H
/// @brief Setup OMI training on P10
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#ifndef _P10_OMI_TRAIN_H_
#define _P10_OMI_TRAIN_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
///
/// @brief These values are the number of clock cycles and the times specified assume a 625ps period.
///        This timer value must be greater than the di/dt timer
///
enum rx_cdr_timer
{
    CDR_TIMER_DISABLED  = 0b0001,
    CDR_TIMER_60NS      = 0b0001,
    CDR_TIMER_125NS     = 0b0010,
    CDR_TIMER_185NS     = 0b0011,
    CDR_TIMER_250NS     = 0b0100,
    CDR_TIMER_375NS     = 0b0101,
    CDR_TIMER_500NS     = 0b0110,
    CDR_TIMER_750NS     = 0b0111,
    CDR_TIMER_1US       = 0b1000,
    CDR_TIMER_2US       = 0b1001,
    CDR_TIMER_4US       = 0b1010,
    CDR_TIMER_8US       = 0b1011,
    CDR_TIMER_16US      = 0b1100,
    CDR_TIMER_32US      = 0b1101,
    CDR_TIMER_64US      = 0b1110,
    CDR_TIMER_128US     = 0b1111
};

///
/// @brief Amount of time to wait after lane is turned on/off before another lane can be turned on/off
///
enum didt_timer
{
    DIDT_TIMER_DISABLED = 0b0000,
    DIDT_TIMER_5NS      = 0b0001,
    DIDT_TIMER_10NS     = 0b0010,
    DIDT_TIMER_15NS     = 0b0011,
    DIDT_TIMER_20NS     = 0b0100,
    DIDT_TIMER_30NS     = 0b0101,
    DIDT_TIMER_45NS     = 0b0110,
    DIDT_TIMER_60NS     = 0b0111,
    DIDT_TIMER_90NS     = 0b1000,
    DIDT_TIMER_125NS    = 0b1001,
    DIDT_TIMER_185NS    = 0b1010,
    DIDT_TIMER_250NS    = 0b1011,
    DIDT_TIMER_375NS    = 0b1100,
    DIDT_TIMER_500NS    = 0b1101,
    DIDT_TIMER_768NS    = 0b1110,
    DIDT_TIMER_1US      = 0b1111
};

///
/// @brief Calibration timer - amount of time betweem re-calibration for a given lane
///
enum recal_timer
{
    RECAL_TIMER_DISABLED  = 0b000,
    RECAL_TIMER_25MS      = 0b001,
    RECAL_TIMER_50MS      = 0b010,
    RECAL_TIMER_100MS     = 0b011,
    RECAL_TIMER_200MS     = 0b100,
    RECAL_TIMER_400MS     = 0b101,
    RECAL_TIMER_800MS     = 0b110,
    RECAL_TIMER_1600MS    = 0b111
};

///
/// @brief PMU prescalar value
///
enum pmu_prescalar
{
    PRESCALAR_16BIT = 0b000,
    PRESCALAR_8BIT  = 0b001,
    PRESCALAR_20BIT = 0b100,
};


///
/// @brief PMU cntrx pair selector
///
enum cntrl_pair_selector
{
    SEL_ODD      = 0b00,
    SEL_EVEN     = 0b01,
    SEL_BOTH_AND = 0b10,
    SEL_BOTH_XOR = 0b11
};

///
/// @brief PMU cntrx event selector
///
enum cntrl_event_selector
{
    SIG_7_6 = 0b00,
    SIG_5_4 = 0b01,
    SIG_3_2 = 0b10,
    SIG_1_0 = 0b11
};

///
/// @brief dl0 no forward progress timer
///
enum no_forward_progress_timer
{
    NO_FORWARD_TIMER_1US      = 0b0000,
    NO_FORWARD_TIMER_2US      = 0b0001,
    NO_FORWARD_TIMER_4US      = 0b0010,
    NO_FORWARD_TIMER_8US      = 0b0011,
    NO_FORWARD_TIMER_16US     = 0b0100,
    NO_FORWARD_TIMER_32US     = 0b0101,
    NO_FORWARD_TIMER_64US     = 0b0110,
    NO_FORWARD_TIMER_128US    = 0b0111,
    NO_FORWARD_TIMER_256US    = 0b1000,
    NO_FORWARD_TIMER_512US    = 0b1001,
    NO_FORWARD_TIMER_1MS      = 0b1010,
    NO_FORWARD_TIMER_2MS      = 0b1011,
    NO_FORWARD_TIMER_4MS      = 0b1100,
    NO_FORWARD_TIMER_8MS      = 0b1101,
    NO_FORWARD_TIMER_16MS     = 0b1110,
    NO_FORWARD_TIMER_DISABLED = 0b1111
};

///
/// @brief dl0 PHY control mode - determines the amount of time needed to receive pattern A or pattern B
///
enum phy_ctr_mode
{
    PHY_CTR_MODE_1US   = 0b0000,
    PHY_CTR_MODE_50US  = 0b0001,
    PHY_CTR_MODE_100US = 0b0010,
    PHY_CTR_MODE_200US = 0b0011,
    PHY_CTR_MODE_500US = 0b0100,
    PHY_CTR_MODE_1MS   = 0b0101,
    PHY_CTR_MODE_2MS   = 0b0110,
    PHY_CTR_MODE_3MS   = 0b0111,
    PHY_CTR_MODE_4MS   = 0b1000,
    PHY_CTR_MODE_5MS   = 0b1001,
    PHY_CTR_MODE_6MS   = 0b1010,
    PHY_CTR_MODE_8MS   = 0b1011,
    PHY_CTR_MODE_10MS  = 0b1100,
    PHY_CTR_MODE_15MS  = 0b1101,
    PHY_CTR_MODE_30MS  = 0b1110,
    PHY_CTR_MODE_60MS  = 0b1111
};

///
/// @brief dl0 supported link widths
///
enum link_widths
{
    LINK_WIDTHS_X4PLUS1 = 0b1000,
    LINK_WIDTHS_X16     = 0b0100,
    LINK_WIDTHS_X8      = 0b0010,
    LINK_WIDTHS_X4      = 0b0001
};

///
/// @brief dl0 train mode
///
enum train_mode
{
    TX_ZEROS             = 0b0000,
    TX_PATTERN_A         = 0b0001,
    TX_PATTERN_B         = 0b0010,
    TX_SYNC_PATTERN      = 0b0011,
    TX_TRAINING_STATE1   = 0b0100,
    TX_TRAINING_STATE2   = 0b0101,
    TX_TRAINING_STATE3   = 0b0110,
    TX_TRAINING_STATE0   = 0b0111,
    ENABLE_AUTO_TRAINING = 0b1000
};

///
/// @brief Configuration override to select lane width for dynamic lane power down modes.
///
enum lan_width_override
{
    TL_CTR_BY_SIDEBAND = 0b00,
    DL_OVERRIDE_X2     = 0b01,
    DL_OVERRIDE_X4     = 0b10,
    DL_OVERRIDE_X8     = 0b11
};

///
/// @brief Number of consecutive pattern B seen before indicating received pattern B
///
enum b_hysteresis
{
    B_HYSTERESIS_16  = 0b0000,
    B_HYSTERESIS_24  = 0b0001,
    B_HYSTERESIS_32  = 0b0010,
    B_HYSTERESIS_40  = 0b0011,
    B_HYSTERESIS_48  = 0b0100,
    B_HYSTERESIS_56  = 0b0101,
    B_HYSTERESIS_64  = 0b0110,
    B_HYSTERESIS_72  = 0b0111,
    B_HYSTERESIS_80  = 0b1000,
    B_HYSTERESIS_96  = 0b1001,
    B_HYSTERESIS_128 = 0b1010,
    B_HYSTERESIS_256 = 0b1011,
    B_HYSTERESIS_512 = 0b1100,
    B_HYSTERESIS_1K  = 0b1101,
    B_HYSTERESIS_2K  = 0b1110,
    B_HYSTERESIS_4K  = 0b1111
};

///
/// @brief Number of consecutive pattern A seen before indicating received pattern A.
///
enum a_hysteresis
{
    A_HYSTERESIS_16   = 0b0000,
    A_HYSTERESIS_24   = 0b0001,
    A_HYSTERESIS_32   = 0b0010,
    A_HYSTERESIS_48   = 0b0011,
    A_HYSTERESIS_64   = 0b0100,
    A_HYSTERESIS_96   = 0b0101,
    A_HYSTERESIS_128  = 0b0110,
    A_HYSTERESIS_256  = 0b0111,
    A_HYSTERESIS_512  = 0b1000,
    A_HYSTERESIS_1024 = 0b1001,
    A_HYSTERESIS_2K   = 0b1010,
    A_HYSTERESIS_4K   = 0b1011,
    A_HYSTERESIS_8K   = 0b1100,
    A_HYSTERESIS_16K  = 0b1101,
    A_HYSTERESIS_32K  = 0b1110,
    A_HYSTERESIS_64K  = 0b1111
};

///
/// @brief Lanes disabled
///
enum
{
    LANE_DISABLED_NONE = 0b00000000,
    LANE_DISABLED_7    = 0b00000001,
    LANE_DISABLED_6    = 0b00000010,
    LANE_DISABLED_5    = 0b00000100,
    LANE_DISABLED_4    = 0b00001000,
    LANE_DISABLED_3    = 0b00010000,
    LANE_DISABLED_2    = 0b00100000,
    LANE_DISABLED_1    = 0b01000000,
    LANE_DISABLED_0    = 0b10000000
};

///
/// @brief dl0 inject crc direction
///
enum crc_inject_dir
{
    CRC_DIR_RX = 0,
    CRC_DIR_TX = 1
};

///
/// @brief dl0 crc injection rate
///
enum crc_inject_rate
{
    CRC_INJ_RATE_1US   = 0b0000,
    CRC_INJ_RATE_8US   = 0b0001,
    CRC_INJ_RATE_64US  = 0b0010,
    CRC_INJ_RATE_512US = 0b0011,
    CRC_INJ_RATE_4MS   = 0b0100,
    CRC_INJ_RATE_32MS  = 0b0101,
    CRC_INJ_RATE_256MS = 0b0110,
    CRC_INJ_RATE_2S    = 0b0111
};

///
/// @brief CFG_DL0_EDPL_TIME: dl0 edpl time window
///
enum edpl_time_win
{
    EDPL_TIME_WIN_NO          = 0b0000,
    EDPL_TIME_WIN_4US         = 0b0001,
    EDPL_TIME_WIN_32US        = 0b0010,
    EDPL_TIME_WIN_256US       = 0b0011,
    EDPL_TIME_WIN_2MS         = 0b0100,
    EDPL_TIME_WIN_16MS        = 0b0101,
    EDPL_TIME_WIN_128MS       = 0b0110,
    EDPL_TIME_WIN_1S          = 0b0111,
    EDPL_TIME_WIN_8S          = 0b1000,
    EDPL_TIME_WIN_64S         = 0b1001,
    EDPL_TIME_WIN_512S        = 0b1010,
    EDPL_TIME_WIN_4KS         = 0b1011,
    EDPL_TIME_WIN_32KS        = 0b1100,
    EDPL_TIME_WIN_256KS       = 0b1101,
    EDPL_TIME_WIN_2MILLIONS   = 0b1110,
    EDPL_TIME_WIN_16MILLIONS  = 0b1111
};

///
/// @brief CFG_DL0_EDPL_THRESHOLD: dl0 edpl threshold
///
enum edpl_err_thres
{
    EDPL_ERR_THRES_DISABLED = 0b000,
    EDPL_ERR_THRES_2        = 0b001,
    EDPL_ERR_THRES_4        = 0b010,
    EDPL_ERR_THRES_8        = 0b011,
    EDPL_ERR_THRES_16       = 0b100,
    EDPL_ERR_THRES_32       = 0b101,
    EDPL_ERR_THRES_64       = 0b110,
    EDPL_ERR_THRES_128      = 0b111
};

///
/// @brief CONFIG1_CFG_PREIPL_PRBS_TIME: config1 pre-ipl prbs time
///
enum preipl_prbs_time
{
    PREIPL_PRBS_256US      = 0b000,
    PREIPL_PRBS_1US        = 0b001,
    PREIPL_PRBS_4MS        = 0b010,
    PREIPL_PRBS_16MS       = 0b011,
    PREIPL_PRBS_64MS       = 0b100,
    PREIPL_PRBS_256MS      = 0b101,
    PREIPL_PRBS_1S         = 0b110,
    PREIPL_PRBS_4S         = 0b111
};

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
typedef fapi2::ReturnCode (*p10_omi_train_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>&);

extern "C"
{

///
/// @brief Start DL link training on the selected OMIC
///
/// @param[in] i_target Reference to OMIC endpoint target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_omi_train(
        const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target);

} // extern "C"

#endif // _P10_OMI_TRAIN_H_
