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
/// @brief Different enable operations
///
enum enable_mode
{
    SPD = 0, // Use values from the SPD (default). Overwrite the vendor region with SPD settings
    MANUAL = 1, // Use voltage settings currently in the vendor region. (Changed via pmic_update, or factory defaults)
};

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

    PMIC0_REVISION                      = 49,
    PMIC1_REVISION                      = 50,

    // Dispatcher set to last enum value
    DISPATCHER = PMIC1_REVISION,
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

    SET_PMIC0_REVISION                      = 0x1082,
    SET_PMIC1_REVISION                      = 0x1083,
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
    static constexpr uint8_t NUM_PRIMARY_PMICS          = 2; // PMIC0/2, PMIC1/3
    static constexpr uint8_t NUM_PMICS_4U               = 4; // 2 redundant
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

    // 4U Consts

    // R30

    // Sets bit 7, ENABLE_ADC = 1,
    // Sets bit range 6:3 to monitor VIN_BULK = 0b0101
    static constexpr uint8_t R30_SAMPLE_VIN_BULK_ENABLE_ADC = 0xA8;

    // R31
    static constexpr uint8_t R31_VIN_BULK_EFUSE_OFF_HIGH  = 0x04;
    static constexpr uint8_t R31_VIN_BULK_EFUSE_ON_HIGH   = 0xBF;
    static constexpr uint8_t R31_VIN_BULK_EFUSE_ON_LOW    = 0x9D;

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

///
/// @brief Constants for GENERICI2CSLAVE devices
///
enum generic_i2c_slave
{
    NUM_TOTAL_DEVICES = 4,
    NUM_GPIO = 2,
    NUM_ADC = 2,

    // GENERICI2CSLAVE REL_POS orderings
    ADC1 = 0,
    ADC2 = 1,
    GPIO1 = 2,
    GPIO2 = 3,
};

namespace gpio
{

///
/// @brief GPIO registers
///
enum regs
{
    INPUT_PORT_REG = 0x00,
    EFUSE_OUTPUT = 0x01,
    EFUSE_POLARITY = 0x02,
    CONFIGURATION = 0x03,
};

///
/// @brief GPIO register fields
///
enum fields
{
    INPUT_PORT_REG_PMIC_PAIR0   = 2,
    INPUT_PORT_REG_PMIC_PAIR1   = 3,

    EFUSE_OUTPUT_SETTING        = 0xFF,
    EFUSE_POLARITY_SETTING      = 0x00,

    // 1's are inputs, 0's are outputs
    CONFIGURATION_IO_MAP        = 0xFC,
};

} // ns gpio

namespace adc
{

///
/// @brief Registers for ADC devices
///
enum regs
{
    GENERAL_CFG         = 0x01,
    OSR_CFG             = 0x03,
    OPMODE_CFG          = 0x04,
    SEQUENCE_CFG        = 0x10,
    AUTO_SEQ_CH_SEL     = 0x12,
    ALERT_CH_SEL        = 0x14,
    ALERT_PIN_CFG       = 0x17,

    HYSTERESIS_CH1      = 0x24,
    HIGH_TH_CH1         = 0x25,
    EVENT_COUNT_CH1     = 0x26,
    LOW_TH_CH1          = 0x27,

    HYSTERESIS_CH2      = 0x28,
    HIGH_TH_CH2         = 0x29,
    EVENT_COUNT_CH2     = 0x2A,
    LOW_TH_CH2          = 0x2B,

    HYSTERESIS_CH3      = 0x2C,
    HIGH_TH_CH3         = 0x2D,
    EVENT_COUNT_CH3     = 0x2E,
    LOW_TH_CH3          = 0x2F,

    HYSTERESIS_CH4      = 0x30,
    HIGH_TH_CH4         = 0x31,
    EVENT_COUNT_CH4     = 0x32,
    LOW_TH_CH4          = 0x33,

    HYSTERESIS_CH5      = 0x34,
    HIGH_TH_CH5         = 0x35,
    EVENT_COUNT_CH5     = 0x36,
    LOW_TH_CH5          = 0x37,

    HYSTERESIS_CH7      = 0x3C,
    HIGH_TH_CH7         = 0x3D,
    EVENT_COUNT_CH7     = 0x3E,
    LOW_TH_CH7          = 0x3F,
};

///
/// @brief Fields and contents for ADC regs
///
enum fields
{
    GENERAL_CFG_EN_DIGITAL_WINDOW_COMPARATOR_AND_STATS  = 0x30,
    SEQUENCE_CFG_CHANNEL_SEQUENCING                     = 0x11,
    SEQUENCE_CFG_AUTO_SEQUENCE                          = 0x01,
    AUTO_SEQ_CH_SEL_ALL_AUTO_SEQUENCING                 = 0xFF,
    ALERT_CH_SEL_ADC1_LOCAL_VOLTAGES_ALERT              = 0xBE,
    ALERT_CH_SEL_ADC2_LOCAL_VOLTAGES_ALERT              = 0xAC,
    ALERT_PIN_CFG_ACTIVE_HIGH                           = 0x01,
    OPMODE_CFG_AUTONOMOUS                               = 0x31,
    OSR_CFG_8_SAMPLE_OVERSAMPLING                       = 0x07,


    HYSTERESIS_UPPER_LIMIT_MAX_ENABLE                   = 0xF1,
    HIGH_TH_DEFAULT                                     = 0xFF,

    EVENT_COUNT_ADC1_CH1_ALERT_4_CONSECUTIVE_READINGS        = 0x74,
    EVENT_COUNT_ADC1_CH2_ALERT_4_CONSECUTIVE_READINGS        = 0x24,
    EVENT_COUNT_ADC1_CH3_ALERT_4_CONSECUTIVE_READINGS        = 0xB4,
    EVENT_COUNT_ADC1_CH4_ALERT_4_CONSECUTIVE_READINGS        = 0x24,
    EVENT_COUNT_ADC1_CH5_ALERT_4_CONSECUTIVE_READINGS        = 0xB4,
    EVENT_COUNT_ADC1_CH7_ALERT_4_CONSECUTIVE_READINGS        = 0x74,

    EVENT_COUNT_ADC2_CH2_ALERT_4_CONSECUTIVE_READINGS        = 0x64,
    EVENT_COUNT_ADC2_CH3_ALERT_4_CONSECUTIVE_READINGS        = 0x74,
    EVENT_COUNT_ADC2_CH5_ALERT_4_CONSECUTIVE_READINGS        = 0x64,
    EVENT_COUNT_ADC2_CH7_ALERT_4_CONSECUTIVE_READINGS        = 0x74,

    LOW_TH_CH1_1AB_VLOC_LOW_THRESHOLD_643mv             = 0x42,
    LOW_TH_CH2_1C_VLOC_LOW_THRESHOLD_476mv              = 0x31,
    LOW_TH_CH3_1D_VLOC_LOW_THRESHOLD_733mv              = 0x4B,
    LOW_TH_CH4_2C_VLOC_LOW_THRESHOLD_476mv              = 0x31,
    LOW_TH_CH5_2D_VLOC_LOW_THRESHOLD_733mv              = 0x4B,
    LOW_TH_CH7_2AB_VLOC_LOW_THRESHOLD_643mv             = 0x42,

    LOW_TH_CH2_3C_VLOC_LOW_THRESHOLD_391mv              = 0x28,
    LOW_TH_CH3_4AB_VLOC_LOW_THRESHOLD_543mv             = 0x42,
    LOW_TH_CH5_4C_VLOC_LOW_THRESHOLD_391mv              = 0x28,
    LOW_TH_CH7_3AB_VLOC_LOW_THRESHOLD_543mv             = 0x42,
};

///
/// @brief i2c consts for ADC devices
///
namespace i2c
{
enum opcode
{
    READ  = 0x10,
    WRITE = 0x08,
};
};

} // ns adc
} // ns mss

#endif
