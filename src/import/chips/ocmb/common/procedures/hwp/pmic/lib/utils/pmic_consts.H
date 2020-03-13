/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_consts.H $ */
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
/// @file pmic_consts.H
/// @brief Constants for PMIC procedures / i2C
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Andre A. Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: CI

#ifndef MSS_PMIC_CONSTS_H
#define MSS_PMIC_CONSTS_H

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{
namespace pmic
{

///
/// @brief Module height from SPD (1U-4U)
/// @note these values are taken directly from the SPD.
///
enum module_height
{
    HEIGHT_1U = 0b000,
    HEIGHT_2U = 0b001,
    HEIGHT_4U = 0b100,
};

///
/// @brief IDs for PMIC0 or PMIC1
///
enum id
{
    PMIC0 = 0,
    PMIC1 = 1,
    PMIC2 = 2,
    PMIC3 = 3,
    UNKNOWN_ID = 4, // default constant for wrapper procedure
};

///
/// @brief Constants for pmic product types
///
enum product
{
    JEDEC_COMPLIANT, // Only JEDEC exists
};

///
/// @brief constants for pmic vendor
///
enum vendor
{
    UNKNOWN_VENDOR,
    TI = 0x9780,
    IDT = 0xB380,

    TI_SHORT = 0x97,
    IDT_SHORT = 0xB3,
};

///
/// @brief Constants for pmic rail
///
enum rail
{
    SWA = 0,
    SWB = 1,
    SWC = 2,
    SWD = 3,
};

///
/// @brief pmic attr_eff_engine_fields
///
enum class attr_eff_engine_fields
{
    // Template recursive base case
    ATTR_EFF_BASE_CASE = 0,

    PMIC0_SWA_VOLTAGE_SETTING           = 1,
    PMIC0_SWA_VOLTAGE_RANGE_SELECT      = 2,
    PMIC0_SWA_VOLTAGE_OFFSET            = 3,
    PMIC0_SWA_SEQUENCE_DELAY            = 4,
    PMIC0_SWA_SEQUENCE_ORDER            = 5,

    PMIC0_SWB_VOLTAGE_SETTING           = 6,
    PMIC0_SWB_VOLTAGE_RANGE_SELECT      = 7,
    PMIC0_SWB_VOLTAGE_OFFSET            = 8,
    PMIC0_SWB_SEQUENCE_DELAY            = 9,
    PMIC0_SWB_SEQUENCE_ORDER            = 10,

    PMIC0_SWC_VOLTAGE_SETTING           = 11,
    PMIC0_SWC_VOLTAGE_RANGE_SELECT      = 12,
    PMIC0_SWC_VOLTAGE_OFFSET            = 13,
    PMIC0_SWC_SEQUENCE_DELAY            = 14,
    PMIC0_SWC_SEQUENCE_ORDER            = 15,

    PMIC0_SWD_VOLTAGE_SETTING           = 16,
    PMIC0_SWD_VOLTAGE_RANGE_SELECT      = 17,
    PMIC0_SWD_VOLTAGE_OFFSET            = 18,
    PMIC0_SWD_SEQUENCE_DELAY            = 19,
    PMIC0_SWD_SEQUENCE_ORDER            = 20,

    PMIC1_SWA_VOLTAGE_SETTING           = 21,
    PMIC1_SWA_VOLTAGE_RANGE_SELECT      = 22,
    PMIC1_SWA_VOLTAGE_OFFSET            = 23,
    PMIC1_SWA_SEQUENCE_DELAY            = 24,
    PMIC1_SWA_SEQUENCE_ORDER            = 25,

    PMIC1_SWB_VOLTAGE_SETTING           = 26,
    PMIC1_SWB_VOLTAGE_RANGE_SELECT      = 27,
    PMIC1_SWB_VOLTAGE_OFFSET            = 28,
    PMIC1_SWB_SEQUENCE_DELAY            = 29,
    PMIC1_SWB_SEQUENCE_ORDER            = 30,

    PMIC1_SWC_VOLTAGE_SETTING           = 31,
    PMIC1_SWC_VOLTAGE_RANGE_SELECT      = 32,
    PMIC1_SWC_VOLTAGE_OFFSET            = 33,
    PMIC1_SWC_SEQUENCE_DELAY            = 34,
    PMIC1_SWC_SEQUENCE_ORDER            = 35,

    PMIC1_SWD_VOLTAGE_SETTING           = 36,
    PMIC1_SWD_VOLTAGE_RANGE_SELECT      = 37,
    PMIC1_SWD_VOLTAGE_OFFSET            = 38,
    PMIC1_SWD_SEQUENCE_DELAY            = 39,
    PMIC1_SWD_SEQUENCE_ORDER            = 40,

    PMIC0_PHASE_COMB                    = 41,
    PMIC1_PHASE_COMB                    = 42,

    PMIC0_MFG_ID                        = 43,
    PMIC1_MFG_ID                        = 44,

    PMIC0_SEQUENCE                      = 45,
    PMIC1_SEQUENCE                      = 46,

    PMIC0_REDUNDANCY                    = 47,
    PMIC1_REDUNDANCY                    = 48,

    // Dispatcher set to last enum value
    DISPATCHER = PMIC1_REDUNDANCY,
};

///
/// @brief explorer ffdc codes
///
enum ffdc_codes
{
    SET_PMIC0_SWA_VOLTAGE_SETTING           = 0x1052,
    SET_PMIC0_SWA_VOLTAGE_RANGE_SELECT      = 0x1053,
    SET_PMIC0_SWA_VOLTAGE_OFFSET            = 0x1054,
    SET_PMIC0_SWA_SEQUENCE_DELAY            = 0x1055,
    SET_PMIC0_SWA_SEQUENCE_ORDER            = 0X1056,

    SET_PMIC0_SWB_VOLTAGE_SETTING           = 0x1057,
    SET_PMIC0_SWB_VOLTAGE_RANGE_SELECT      = 0x1058,
    SET_PMIC0_SWB_VOLTAGE_OFFSET            = 0x1059,
    SET_PMIC0_SWB_SEQUENCE_DELAY            = 0x105A,
    SET_PMIC0_SWB_SEQUENCE_ORDER            = 0X105B,

    SET_PMIC0_SWC_VOLTAGE_SETTING           = 0x105C,
    SET_PMIC0_SWC_VOLTAGE_RANGE_SELECT      = 0x105D,
    SET_PMIC0_SWC_VOLTAGE_OFFSET            = 0x105E,
    SET_PMIC0_SWC_SEQUENCE_DELAY            = 0x105F,
    SET_PMIC0_SWC_SEQUENCE_ORDER            = 0X1060,

    SET_PMIC0_SWD_VOLTAGE_SETTING           = 0x1061,
    SET_PMIC0_SWD_VOLTAGE_RANGE_SELECT      = 0x1062,
    SET_PMIC0_SWD_VOLTAGE_OFFSET            = 0x1063,
    SET_PMIC0_SWD_SEQUENCE_DELAY            = 0x1064,
    SET_PMIC0_SWD_SEQUENCE_ORDER            = 0X1065,

    SET_PMIC1_SWA_VOLTAGE_SETTING           = 0x1066,
    SET_PMIC1_SWA_VOLTAGE_RANGE_SELECT      = 0x1067,
    SET_PMIC1_SWA_VOLTAGE_OFFSET            = 0x1068,
    SET_PMIC1_SWA_SEQUENCE_DELAY            = 0x1069,
    SET_PMIC1_SWA_SEQUENCE_ORDER            = 0X106A,

    SET_PMIC1_SWB_VOLTAGE_SETTING           = 0x106B,
    SET_PMIC1_SWB_VOLTAGE_RANGE_SELECT      = 0x106C,
    SET_PMIC1_SWB_VOLTAGE_OFFSET            = 0x106D,
    SET_PMIC1_SWB_SEQUENCE_DELAY            = 0x106E,
    SET_PMIC1_SWB_SEQUENCE_ORDER            = 0X106F,

    SET_PMIC1_SWC_VOLTAGE_SETTING           = 0x1070,
    SET_PMIC1_SWC_VOLTAGE_RANGE_SELECT      = 0x1071,
    SET_PMIC1_SWC_VOLTAGE_OFFSET            = 0x1072,
    SET_PMIC1_SWC_SEQUENCE_DELAY            = 0x1073,
    SET_PMIC1_SWC_SEQUENCE_ORDER            = 0X1074,

    SET_PMIC1_SWD_VOLTAGE_SETTING           = 0x1075,
    SET_PMIC1_SWD_VOLTAGE_RANGE_SELECT      = 0x1076,
    SET_PMIC1_SWD_VOLTAGE_OFFSET            = 0x1077,
    SET_PMIC1_SWD_SEQUENCE_DELAY            = 0x1078,
    SET_PMIC1_SWD_SEQUENCE_ORDER            = 0X1079,

    SET_PMIC0_PHASE_COMB                    = 0x107A,
    SET_PMIC1_PHASE_COMB                    = 0x107B,

    SET_PMIC0_MFG_ID                        = 0x107C,
    SET_PMIC1_MFG_ID                        = 0x107D,

    SET_PMIC0_SEQUENCE                      = 0x107E,
    SET_PMIC1_SEQUENCE                      = 0x107F,

    SET_PMIC0_REDUNDANCY                    = 0x1080,
    SET_PMIC1_REDUNDANCY                    = 0x1081,
};

///
/// @brief constants for PMIC procedures
///
/// @tparam P product ID (jedec, etc.)
///
template<mss::pmic::product P>
struct consts;

///
/// @brief constants for JEDEC_COMPLIANT PMICS
///
template<>
struct consts<mss::pmic::product::JEDEC_COMPLIANT>
{
    static constexpr uint8_t RANGE_0                    = 0;
    static constexpr uint8_t RANGE_1                    = 1;
    static constexpr uint8_t NUM_UNIQUE_PMICS           = 2; // PMIC0/2, PMIC1/3
    static constexpr uint8_t NUMBER_OF_RAILS            = 4;

    static constexpr uint8_t VENDOR_PASSWORD_LOW        = 0x73;
    static constexpr uint8_t VENDOR_PASSWORD_HIGH       = 0x94;

    // Codes below for R39
    static constexpr uint8_t UNLOCK_VENDOR_REGION       = 0x40;
    static constexpr uint8_t LOCK_VENDOR_REGION         = 0x00;
    static constexpr uint8_t CLEAR_R04_TO_R07           = 0x74;
    static constexpr uint8_t BURN_R40_TO_R4F            = 0x81;
    static constexpr uint8_t BURN_R50_TO_R5F            = 0x82;
    static constexpr uint8_t BURN_R60_TO_R6F            = 0x85; // TI spec says 0x83, is that a deviation or a typo?
    static constexpr uint8_t BURN_COMPLETE              = 0x5A;

    static constexpr uint8_t PROGRAMMABLE_MODE          = 0x01;
    static constexpr uint8_t SECURE_MODE                = 0x00;

    static constexpr uint8_t SINGLE_PHASE               = 0x0;
    static constexpr uint8_t DUAL_PHASE                 = 0x1;

    static constexpr uint8_t PWR_GOOD                   = 0x0;
    static constexpr uint8_t PWR_NOT_GOOD               = 0x1;

    // Sequencing
    static constexpr uint8_t DELAY_LIMIT                = 0b1000;

    // Despite the SPD max of 1000, the PMIC can only really support this value
    static constexpr uint8_t ORDER_LIMIT                = 0b0101;

    // Offset voltage from spd (+/-)
    static constexpr uint8_t OFFSET_PLUS                = 0;
    static constexpr uint8_t OFFSET_MINUS               = 1;

    // Shift left 1 to match buffer position
    static constexpr uint8_t SHIFT_VOLTAGE_FOR_REG      = 1;

    static constexpr uint8_t NUM_RANGES                 = 2; // RANGE0 and RANGE1
    static constexpr uint8_t MAX_VOLT_BITMAP            = 0b01111111;
    static constexpr uint8_t MAX_DELAY_BITMAP           = 0b00000111;
    static constexpr uint8_t CONVERT_RANGE1_TO_RANGE0   = 40;

    // Values below are in millivolts (mV)
    static constexpr uint32_t SWABC_VOLT_RANGE0_MIN        = 800;
    static constexpr uint32_t SWABC_VOLT_RANGE0_MAX        = 1435;
    static constexpr uint32_t SWABC_VOLT_RANGE1_MIN        = 600;
    static constexpr uint32_t SWABC_VOLT_RANGE1_MAX        = 1235;

    static constexpr uint32_t SWD_VOLT_RANGE0_MIN          = 1500;
    static constexpr uint32_t SWD_VOLT_RANGE0_MAX          = 2135;
    static constexpr uint32_t SWD_VOLT_RANGE1_MIN          = 2200;
    static constexpr uint32_t SWD_VOLT_RANGE1_MAX          = 2835;

    static constexpr uint32_t VOLT_STEP                    = 5;
};

namespace i2c
{

///
/// @brief common PMIC sizes
///
enum sizes
{
    DATA_LENGTH = 1,
};

} // i2c
} // pmic
} // mss

#endif
