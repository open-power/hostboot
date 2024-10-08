/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_consts.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: CI
// EKB-Mirror-To: hw/ppe

#ifndef MSS_PMIC_CONSTS_H
#define MSS_PMIC_CONSTS_H

namespace mss
{
namespace pmic
{

///
/// @brief N-mode states
///
enum n_mode : bool
{
    N_MODE          = true,
    N_PLUS_1_MODE   = false,
};

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
/// @brief IDs for PMIC0-3
///
enum id : uint8_t
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
    JEDEC_COMPLIANT,    // Common to all devices
    TPS5383X,           // TPS custom part
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

enum volt_domains
{
    VDDQ = 0,
    VDD  = 1,
    VIO  = 2,
    VPP  = 3,
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

    SET_PMIC2_SWA_VOLTAGE_SETTING           = 0x1084,
    SET_PMIC2_SWA_VOLTAGE_RANGE_SELECT      = 0x1085,
    SET_PMIC2_SWA_VOLTAGE_OFFSET            = 0x1086,
    SET_PMIC2_SWA_SEQUENCE_DELAY            = 0x1087,
    SET_PMIC2_SWA_SEQUENCE_ORDER            = 0X1088,

    SET_PMIC2_SWB_VOLTAGE_SETTING           = 0x1089,
    SET_PMIC2_SWB_VOLTAGE_RANGE_SELECT      = 0x108A,
    SET_PMIC2_SWB_VOLTAGE_OFFSET            = 0x108B,
    SET_PMIC2_SWB_SEQUENCE_DELAY            = 0x108C,
    SET_PMIC2_SWB_SEQUENCE_ORDER            = 0X108D,

    SET_PMIC2_SWC_VOLTAGE_SETTING           = 0x108E,
    SET_PMIC2_SWC_VOLTAGE_RANGE_SELECT      = 0x108F,
    SET_PMIC2_SWC_VOLTAGE_OFFSET            = 0x1090,
    SET_PMIC2_SWC_SEQUENCE_DELAY            = 0x1091,
    SET_PMIC2_SWC_SEQUENCE_ORDER            = 0X1092,

    SET_PMIC2_SWD_VOLTAGE_SETTING           = 0x1093,
    SET_PMIC2_SWD_VOLTAGE_RANGE_SELECT      = 0x1094,
    SET_PMIC2_SWD_VOLTAGE_OFFSET            = 0x1095,
    SET_PMIC2_SWD_SEQUENCE_DELAY            = 0x1096,
    SET_PMIC2_SWD_SEQUENCE_ORDER            = 0X1097,

    SET_PMIC3_SWA_VOLTAGE_SETTING           = 0x1098,
    SET_PMIC3_SWA_VOLTAGE_RANGE_SELECT      = 0x1099,
    SET_PMIC3_SWA_VOLTAGE_OFFSET            = 0x109A,
    SET_PMIC3_SWA_SEQUENCE_DELAY            = 0x109B,
    SET_PMIC3_SWA_SEQUENCE_ORDER            = 0X109C,

    SET_PMIC3_SWB_VOLTAGE_SETTING           = 0x109D,
    SET_PMIC3_SWB_VOLTAGE_RANGE_SELECT      = 0x109E,
    SET_PMIC3_SWB_VOLTAGE_OFFSET            = 0x109F,
    SET_PMIC3_SWB_SEQUENCE_DELAY            = 0x1100,
    SET_PMIC3_SWB_SEQUENCE_ORDER            = 0X1101,

    SET_PMIC3_SWC_VOLTAGE_SETTING           = 0x1102,
    SET_PMIC3_SWC_VOLTAGE_RANGE_SELECT      = 0x1103,
    SET_PMIC3_SWC_VOLTAGE_OFFSET            = 0x1104,
    SET_PMIC3_SWC_SEQUENCE_DELAY            = 0x1105,
    SET_PMIC3_SWC_SEQUENCE_ORDER            = 0X1106,

    SET_PMIC3_SWD_VOLTAGE_SETTING           = 0x1107,
    SET_PMIC3_SWD_VOLTAGE_RANGE_SELECT      = 0x1108,
    SET_PMIC3_SWD_VOLTAGE_OFFSET            = 0x1109,
    SET_PMIC3_SWD_SEQUENCE_DELAY            = 0x110A,
    SET_PMIC3_SWD_SEQUENCE_ORDER            = 0X110B,

    SET_PMIC2_PHASE_COMB                    = 0x110C,
    SET_PMIC3_PHASE_COMB                    = 0x110D,

    SET_PMIC2_MFG_ID                        = 0x110E,
    SET_PMIC3_MFG_ID                        = 0x110F,

    SET_PMIC2_SEQUENCE                      = 0x1110,
    SET_PMIC3_SEQUENCE                      = 0x1111,

    SET_PMIC2_REVISION                      = 0x1112,
    SET_PMIC3_REVISION                      = 0x1113,

    SET_PMIC0_SWA_VOLTAGE_COARSE_OFFSET     = 0x1114,
    SET_PMIC0_SWB_VOLTAGE_COARSE_OFFSET     = 0x1115,
    SET_PMIC0_SWC_VOLTAGE_COARSE_OFFSET     = 0x1116,
    SET_PMIC0_SWD_VOLTAGE_COARSE_OFFSET     = 0x1117,

    SET_PMIC1_SWA_VOLTAGE_COARSE_OFFSET     = 0x1118,
    SET_PMIC1_SWB_VOLTAGE_COARSE_OFFSET     = 0x1119,
    SET_PMIC1_SWC_VOLTAGE_COARSE_OFFSET     = 0x111A,
    SET_PMIC1_SWD_VOLTAGE_COARSE_OFFSET     = 0x111B,

    SET_PMIC2_SWA_VOLTAGE_COARSE_OFFSET     = 0x111C,
    SET_PMIC2_SWB_VOLTAGE_COARSE_OFFSET     = 0x111D,
    SET_PMIC2_SWC_VOLTAGE_COARSE_OFFSET     = 0x111E,
    SET_PMIC2_SWD_VOLTAGE_COARSE_OFFSET     = 0x111F,

    SET_PMIC3_SWA_VOLTAGE_COARSE_OFFSET     = 0x1120,
    SET_PMIC3_SWB_VOLTAGE_COARSE_OFFSET     = 0x1121,
    SET_PMIC3_SWC_VOLTAGE_COARSE_OFFSET     = 0x1122,
    SET_PMIC3_SWD_VOLTAGE_COARSE_OFFSET     = 0x1123,

    SET_PMIC0_SEQUENCE_CFG0_R40 = 0x1124,
    SET_PMIC0_SEQUENCE_CFG1_R41 = 0x1125,
    SET_PMIC0_SEQUENCE_CFG2_R42 = 0x1126,
    SET_PMIC0_SEQUENCE_CFG3_R43 = 0x1127,

    SET_PMIC1_SEQUENCE_CFG0_R40 = 0x1128,
    SET_PMIC1_SEQUENCE_CFG1_R41 = 0x1129,
    SET_PMIC1_SEQUENCE_CFG2_R42 = 0x112A,
    SET_PMIC1_SEQUENCE_CFG3_R43 = 0x112B,

    SET_PMIC2_SEQUENCE_CFG0_R40 = 0x112C,
    SET_PMIC2_SEQUENCE_CFG1_R41 = 0x112D,
    SET_PMIC2_SEQUENCE_CFG2_R42 = 0x112E,
    SET_PMIC2_SEQUENCE_CFG3_R43 = 0x112F,

    SET_PMIC3_SEQUENCE_CFG0_R40 = 0x1130,
    SET_PMIC3_SEQUENCE_CFG1_R41 = 0x1131,
    SET_PMIC3_SEQUENCE_CFG2_R42 = 0x1132,
    SET_PMIC3_SEQUENCE_CFG3_R43 = 0x1133,
};

///
/// @brief constants for PMIC procedures
///
/// @tparam P product ID (jedec, etc.)
///
template<mss::pmic::product P>
struct consts;

///
/// @brief Constants for TPS5383X PMICs
///
template<>
struct consts<mss::pmic::product::TPS5383X>
{
    static constexpr uint8_t TI_REV_23 = 0x23;

    // R78 - bits are flipped here to go with bit numbering 0:7
    // R78 - power on default values
    static constexpr uint8_t R78_SWA_VID_OFFSET_COARSE_DEFAULT = 0x01;
    static constexpr uint8_t R78_SWB_VID_OFFSET_COARSE_DEFAULT = 0x01;
    static constexpr uint8_t R78_SWC_VID_OFFSET_COARSE_DEFAULT = 0x01;
    static constexpr uint8_t R78_SWD_VID_OFFSET_COARSE_DEFAULT = 0x03;
    // R78 - bits are flipped here to go with bit numbering 0:7
    // R78 - number of ranges for each rail and values for ranges in mV
    static constexpr uint32_t R78_VOLT_SWABCD_RANGE0_MIN   = 0;
    static constexpr uint32_t R78_VOLT_SWABCD_RANGE1_MIN   = 800;
    static constexpr uint32_t R78_VOLT_SWABCD_RANGE2_MIN   = 500;
    static constexpr uint32_t R78_VOLT_SWABCD_RANGE3_MIN   = 1500;

    // R78 voltage ranges
    static constexpr uint8_t R78_NUM_RANGES                = 4;
    static constexpr uint8_t R78_RANGE_0                   = 0;
    static constexpr uint8_t R78_RANGE_1                   = 1;
    static constexpr uint8_t R78_RANGE_2                   = 2;
    static constexpr uint8_t R78_RANGE_3                   = 3;

    // R94 -> R97
    static constexpr uint8_t MAX_SOFT_STOP_CFG = 0xBF;
};

///
/// @brief constants for JEDEC_COMPLIANT PMICS
///
template<>
struct consts<mss::pmic::product::JEDEC_COMPLIANT>
{
    static constexpr uint8_t RANGE_0                    = 0;
    static constexpr uint8_t RANGE_1                    = 1;
    static constexpr uint8_t RANGE_2                    = 2;
    static constexpr uint8_t NUM_PMICS_2U               = 2;
    static constexpr uint8_t NUM_PRIMARY_PMICS          = 2; // PMIC0/2, PMIC1/3
    static constexpr uint8_t NUM_PMICS_4U               = 4; // DDR4: 2 redundant, DDR5: 1 redundant
    static constexpr uint8_t NUM_DTS_4U                 = 4; // DDR4: not present, DDR5: 1 redundant
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

    static constexpr uint8_t PWR_GOOD_IO_TYPE_OUTPUT    = 0x00;
    static constexpr uint8_t PWR_GOOD_IO_TYPE_IO        = 0x01;

    static constexpr uint8_t SINGLE_PHASE               = 0x0;
    static constexpr uint8_t DUAL_PHASE                 = 0x1;

    static constexpr uint8_t PWR_GOOD                   = 0x0;
    static constexpr uint8_t PWR_NOT_GOOD               = 0x1;

    // Sequencing
    static constexpr uint8_t DELAY_LIMIT                = 0b1000;

    // Despite the SPD max of 1000, the PMIC can only really support this value
    static constexpr uint8_t ORDER_LIMIT                = 0b0101;
    static constexpr uint8_t ORDER_RESERVED_VALUE       = 0b1111;

    // Offset voltage from spd (+/-)
    static constexpr uint8_t OFFSET_PLUS                = 0;
    static constexpr uint8_t OFFSET_MINUS               = 1;

    // Shift left 1 to match buffer position
    static constexpr uint8_t SHIFT_VOLTAGE_FOR_REG      = 1;

    static constexpr uint8_t NUM_RANGES                 = 3; // RANGE0, RANGE1, RANGE2
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
    static constexpr uint32_t SWCD_VOLT_RANGE2_MIN         = 800;
    static constexpr uint32_t SWCD_VOLT_RANGE2_MAX         = 1000;

    static constexpr uint32_t VOLT_STEP                    = 5;

    // R29 and R2A MODE SELECT (bits are flipped here)
    static constexpr uint8_t SWX_MODE_SELECT_FDCM = 1;
    static constexpr uint8_t SWX_MODE_SELECT_FCCM = 3;

    // R2C/R2D
    static constexpr uint8_t R2C_R2D_4MS_ALL = 0x44;

    // R30

    // Sets bit 7, ENABLE_ADC = 1,
    // Sets bit range 6:3 to monitor VIN_BULK = 0b0101
    static constexpr uint8_t R30_SAMPLE_VIN_BULK_ENABLE_ADC = 0xA8;

    // R31
    // each tick is 70mV
    // EFUSE_OFF_HIGH increased to 9.94 V since VIN can ramp down slowly
    static constexpr uint8_t R31_VIN_BULK_EFUSE_OFF_HIGH  = 0x8E;
    static constexpr uint8_t R31_VIN_BULK_EFUSE_ON_HIGH   = 0xBF;
    static constexpr uint8_t R31_VIN_BULK_EFUSE_ON_LOW    = 0x9D;

    // DDR5
    static constexpr uint8_t NUM_PRIMARY_PMICS_DDR5     = 3; // 1 redundant out of 4 PMICs
    static constexpr uint8_t NUM_PRIMARY_DT_DDR5        = 3; // 1 redundant out of 4 DTs

    static constexpr bool DISABLE               = false;
    static constexpr bool ENABLE                = true;
    static constexpr uint8_t SET_PMIC_EN        = 0x80;
    static constexpr uint8_t DISABLE_PMIC_EN    = 0x00;
    static constexpr uint8_t PRE_CONFIG_ON_OFF  = 0x02;
    static constexpr uint8_t POST_CONFIG_ON_OFF = 0x04;

    static constexpr uint8_t VIN_BULK_9_5V      = 0b00100000;
    static constexpr uint8_t VIN_BULK_8_5V      = 0b01000000;
    static constexpr uint8_t VIN_BULK_7_5V      = 0b01100000;
    static constexpr uint8_t VIN_BULK_6_5V      = 0b10000000;
    static constexpr uint8_t VIN_BULK_5_5V      = 0b10100000;
    static constexpr uint8_t VIN_BULK_4_25V     = 0b11000000;

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
/// @brief Constants for GENERICI2CRESPONDER devices
///
enum generic_i2c_responder_ddr4
{
    NUM_TOTAL_DEVICES = 4,
    NUM_GPIO = 2,
    NUM_ADC = 2,

    // GENERICI2CRESPONDER REL_POS orderings
    ADC1 = 0,
    ADC2 = 1,
    GPIO1 = 2,
    GPIO2 = 3,
};

///
/// @brief Constants for GENERICI2CRESPONDER devices for DDR5
///
enum generic_i2c_responder
{
    NUM_TOTAL_DEVICES_I2C_DDR5 = 1,

    // GENERICI2CRESPONDER REL_POS orderings
    ADC = 0,
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
enum fields : uint8_t
{
    INPUT_PORT_REG_PMIC_PAIR0   = 2,
    INPUT_PORT_REG_PMIC_PAIR1   = 3,
    INPUT_PORT_REG_FAULT_N      = 6,

    EFUSE_OUTPUT_SETTING        = 0xFF,
    EFUSE_OUTPUT_OFF            = 0xFC,
    EFUSE_OUTPUT_P0             = 0xFE,
    EFUSE_OUTPUT_P1             = 0xFD,
    EFUSE_OUTPUT_ON             = 0xFF,
    EFUSE_POLARITY_SETTING      = 0x00,

    // 1's are inputs, 0's are outputs
    EFUSE_EN_BIT_0    = 7,
    EFUSE_EN_BIT_1    = 6,

    CONFIGURATION_IO_MAP        = 0xFC,
    CONFIGURATION_IO_MAP_OFF    = 0xFF,

    EFUSE_P0_P2_ENABLE          = 0,
    EFUSE_P1_P3_ENABLE          = 1,
};

} // ns gpio

namespace adc
{

///
/// @brief Registers for ADC devices
///
enum regs
{
    SYSTEM_STATUS       = 0x00,
    GENERAL_CFG         = 0x01,
    DATA_CFG            = 0x02,
    OSR_CFG             = 0x03,
    OPMODE_CFG          = 0x04,
    PIN_CFG             = 0x05,
    DUMMY_BYTE_0        = 0x06,
    GPIO_CFG            = 0x07,
    DUMMY_BYTE_1        = 0x08,
    GPO_DRIVE_CFG       = 0x09,
    DUMMY_BYTE_2        = 0x0A,
    GPO_VALUE           = 0x0B,
    DUMMY_BYTE_3        = 0x0C,
    GPI_VALUE           = 0x0D,
    DUMMY_BYTE_4        = 0x0E,
    DUMMY_BYTE_5        = 0x0F,
    SEQUENCE_CFG        = 0x10,
    CHANNEL_SEQ         = 0x11,
    AUTO_SEQ_CH_SEL     = 0x12,
    DUMMY_BYTE_6        = 0x13,
    ALERT_CH_SEL        = 0x14,
    DUMMY_BYTE_7        = 0x15,
    ALERT_MAP           = 0x16,
    ALERT_PIN_CFG       = 0x17,

    EVENT_FLAG          = 0x18,

    HIGH_EVENT_FLAGS    = 0x1A,
    LOW_EVENT_FLAGS     = 0x1C,
    EVENT_RGN           = 0x1E,

    HYSTERESIS_CH0      = 0x20,
    HIGH_TH_CH0         = 0x21,
    EVENT_COUNT_CH0     = 0x22,
    LOW_TH_CH0          = 0x23,

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

    HYSTERESIS_CH6      = 0x38,
    HIGH_TH_CH6         = 0x39,
    EVENT_COUNT_CH6     = 0x3A,
    LOW_TH_CH6          = 0x3B,

    HYSTERESIS_CH7      = 0x3C,
    HIGH_TH_CH7         = 0x3D,
    EVENT_COUNT_CH7     = 0x3E,
    LOW_TH_CH7          = 0x3F,

    RECENT_CH0_LSB      = 0xA0,
    RECENT_CH1_LSB      = 0xA2,
    RECENT_CH2_LSB      = 0xA4,
    RECENT_CH3_LSB      = 0xA6,
    RECENT_CH4_LSB      = 0xA8,
    RECENT_CH5_LSB      = 0xAA,
    RECENT_CH6_LSB      = 0xAC,
    RECENT_CH7_LSB      = 0xAE,

    MAX_CH0_LSB         = 0x60,
    MAX_CH1_LSB         = 0x62,
    MAX_CH2_LSB         = 0x64,
    MAX_CH3_LSB         = 0x66,
    MAX_CH4_LSB         = 0x68,
    MAX_CH5_LSB         = 0x6A,
    MAX_CH6_LSB         = 0x6C,
    MAX_CH7_LSB         = 0x6E,

    MIN_CH0_LSB         = 0x80,
    MIN_CH1_LSB         = 0x82,
    MIN_CH2_LSB         = 0x84,
    MIN_CH3_LSB         = 0x86,
    MIN_CH4_LSB         = 0x88,
    MIN_CH5_LSB         = 0x8A,
    MIN_CH6_LSB         = 0x8C,
    MIN_CH7_LSB         = 0x8E,
};

///
/// @brief Fields and contents for ADC regs
///
enum fields
{
    GPO_DRIVE_CFG_OPEN_DRAIN                            = 0x00,
    GPO_VALUE_CH0_HIGH                                  = 0x01,
    GPIO_CFG_CH0_DIGITAL_GP0                            = 0x01,
    PIN_CFG_CH0_GPIO                                    = 0x01,
    GENERAL_CFG_EN_DIGITAL_WINDOW_COMPARATOR_AND_STATS  = 0x30,
    GENERAL_CFG_CLEAR_STATS_EN                          = 0x10,
    GENERAL_CFG_STATUS_ENABLE                           = 5,
    SEQUENCE_CFG_CHANNEL_SEQUENCING                     = 0x11,
    SEQUENCE_CFG_AUTO_SEQUENCE                          = 0x01,
    AUTO_SEQ_CH_SEL_ALL_AUTO_SEQUENCING                 = 0xFF,
    AUTO_SEQ_CH_SEL_NO_VDDR1_RAIL                       = 0x7C,
    ALERT_CH_SEL_ADC1_LOCAL_VOLTAGES_ALERT              = 0xBE,
    ALERT_CH_SEL_ADC1_NO_VDDR1_RAIL_LOCAL_VOLT_ALERT    = 0x3C,
    ALERT_CH_SEL_ADC2_LOCAL_VOLTAGES_ALERT              = 0xAC,
    ALERT_PIN_CFG_ACTIVE_HIGH                           = 0x00,
    OPMODE_CFG_AUTONOMOUS                               = 0x31,
    OSR_CFG_8_SAMPLE_OVERSAMPLING                       = 0x07,

    CLEAR_EVENTS                                        = 0xFF,

    HYSTERESIS_UNUSED                                   = 0xF0,
    HYSTERESIS_UPPER_LIMIT_MAX_ENABLE                   = 0xF1,
    HIGH_TH_DEFAULT                                     = 0xFF,

    EVENT_COUNT_CH_ENABLE_PWM                           = 0x10,

    EVENT_COUNT_UNUSED                                       = 0x00,
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

    LOW_TH_DEFAULT                                      = 0x00,
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

    // Event reg flag bits
    ADC1_PMIC0_SWA_SWB_FAIL = 1,
    ADC1_PMIC0_SWC_FAIL     = 2,
    ADC1_PMIC0_SWD_FAIL     = 3,
    ADC1_PMIC2_SWC_FAIL     = 4,
    ADC1_PMIC2_SWD_FAIL     = 5,
    ADC1_PMIC2_SWA_SWB_FAIL = 7,
    ADC2_PMIC1_SWC_FAIL     = 2,
    ADC2_PMIC1_SWA_SWB_FAIL = 7,
    ADC2_PMIC3_SWA_SWB_FAIL = 3,
    ADC2_PMIC3_SWC_FAIL     = 5,

};

///
/// @brief i2c consts for ADC devices
///
namespace i2c
{
enum opcode
{
    READ             = 0x10,
    WRITE            = 0x08,
    WRITE_CONTIGUOUS = 0x28,
    READ_CONTIGUOUS  = 0x30,
};
}; // ns i2c

} // ns adc

namespace dt
{

///
/// @brief Registers for DT devices
///
enum regs
{
    NVM_TRIM_RP_MAX      = 0x3C,
    OV_THRESHOLD_AB      = 0x5A,
    OV_THRESHOLD_CD      = 0x5C,
    VAUX_RANGE           = 0x62,
    OPS_STATE            = 0x90,
    FAULTS_STATUS_0      = 0x92,
    FAULTS_STATUS_1      = 0x94,
    FIRST_FAULT_STATUS_0 = 0x96,
    FIRST_FAULT_STATUS_1 = 0x98,
    IIN_VCC              = 0x9A,
    VINP_VIN             = 0x9C,
    VUAX_B_A             = 0x9E,
    VUAX_D_C             = 0xA0,
    VINP_MIN_MAX         = 0xA2,
    IIN_MIN_MAX          = 0xA4,
    INFET_POWER_MTP_ADDR = 0xA6,
    NVM_DATA             = 0xA8,
    VCC_VIN_VINP         = 0xB4,
    NEG_ORFET_CNT        = 0xBB,
    RO_INPUTS_1          = 0xBC,
    RO_INPUTS_0          = 0xBE,
    TRIM_LOCK            = 0xD2,
    FAULTS_CLEAR_0       = 0xD4,
    FAULTS_CLEAR_1       = 0xD6,
    NVM_COMMAND          = 0xDC,
    EN_REGISTER          = 0xDE,
    BREADCRUMB           = 0xE0,
    RECOVERY_COUNT       = 0xE1,
    TRIM_TRY_PASSWORD    = 0xE2,
    OR_FET_CNT_SEL       = 0xE6,
};

///
/// @brief Fields and contents for DT regs
///
enum fields
{
    GPI_1                          = 13,
    SWIN_FAULT_A                   = 13,
    SWIN_FAULT_B                   = 9,
    SWIN_FAULT_C                   = 5,
    SWIN_FAULT_D                   = 1,
    VAUX_A_SCALER_POSITION         = 6,
    VAUX_B_SCALER_POSITION         = 4,
    VAUX_C_SCALER_POSITION         = 2,
    VAUX_D_SCALER_POSITION         = 0,
    VAUX_SCALER_LENGTH             = 2,
    // Due to endianess of DT regs and Fapi buffers the following values differ from spec
    // In the procedure we read & reverse the contiguous reg bit field into two uint8_t buffers
    // Rail A/C bit field 11:6 in spec, written into  FAPI Buffer[0] 0:1 + FAPI Buffer[1] 4:7
    // Rail B/D bit field 5:0 in spec, written into FAPI Buffer[0] 2:7
    // 15:12 is reserved and should remain as 0x0
    // DT REG[15:0]   :    15  14  13  12     11  10  9  8     7  6  5  4     3  2  1  0
    // Bit fields     :    | - Reserved - |    |  -  - A & C -  - | | -  - B & D -  -  |
    // Default data   :     0   0   0   0      0   0  1  0     0  1  0  0     1  1  1  1  = 0x024F = 0x9 field A/C, 0xF field B/D

    //                       *** Bytes are flipped when read out to buffers ***
    // FAPI Buffers   :    | - - buffer[0] 0:7 - -|    | -  - buffer[1] 0:7 -  - |
    // Bit fields     :    |A&C| | - - B & D -  - |    |-Reserved-|    |- -A&C- -|
    // Reverse        :    0  1  0  0    1  1  1  1     0  0  0  0     0  0  1  0      = 0x4F02
    // Data is inserted to the bits relative to buffers rather than DT REG MAP
    OV_THRESH_START_AC_FIRST_BYTE  = 4,
    THRESHOLD_AC_FIRST_BYTE_LEN    = 4,
    OV_THRESH_START_AC_SECOND_BYTE = 0,
    THRESHOLD_AC_SECOND_BYTE_LEN   = 2,
    OV_THRESH_START_BD             = 2,
    OV_THRESH_LENGTH_BD            = 6,
};

///
/// @brief Constants for POWER_IC devices
///
enum dt_i2c_devices
{
    NUM_TOTAL_DEVICES = 4,

    // POWER_IC REL_POS orderings
    DT0 = 0,
    DT1 = 1,
    DT2 = 2,
    DT3 = 3,
};

} // dt
} // ns mss

#endif
