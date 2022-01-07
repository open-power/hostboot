/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/shared/ody_consts.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file ody_consts.H
/// @brief Odyssey specific constants definitions
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#ifndef _MSS_ODY_CONSTS_H_
#define _MSS_ODY_CONSTS_H_

#ifndef __PPE__
    #include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#endif

namespace mss
{

namespace ody
{

// This constant is for MMIO scoms. MMIO addresses are addressed by byte,
// while scoms are numbered by register. So multiply by 8, aka shift by 3
constexpr uint32_t OCMB_ADDR_SHIFT = 3;

#ifndef __PPE__

///
/// @brief common Odyssey sizes
///
enum sizes
{
    MAX_PORT_PER_OCMB = 2,

    // This is used for targeting only (attribute arrays, target positions) so needs to be 2 for P10
    MAX_DIMM_PER_PORT = 2,

    // This is the maximum number of DIMM per port that the hardware supports
    HW_MAX_DIMM_PER_PORT = 1,

    // Technically this is 2 for Odyssey, but this value is used for attribute array indexing which requires 4
    // Any code that converts DIMM ranks to port ranks should use the rank API
    MAX_RANK_PER_DIMM = 4,

    // This is the maximum number of main ranks per DIMM supported by the hardware
    HW_MAX_RANK_PER_DIMM = 2,

    // This is used in the row repair code to determine how many sPPRs we can do. We used an artificial limit of one
    // per bank group on DDR4, but it's technically one per bank, per DRAM, so 40*16 per DIMM
    // TODO: Zen:MST-1422 Update this for Odyssey
    MAX_BG_PER_DIMM = 4,

    MAX_DQ_BITS_PER_PORT = 80,
    MAX_SYMBOLS_PER_PORT = 72,
    MAX_MRANK_PER_PORT = MAX_DIMM_PER_PORT * MAX_RANK_PER_DIMM,
    MAX_BYTES_PER_PORT = MAX_DQ_BITS_PER_PORT / BITS_PER_BYTE,
    MAX_NIBBLES_PER_PORT = MAX_DQ_BITS_PER_PORT / BITS_PER_NIBBLE,

    // Enumerations for the Odyssey serial number attribute
    // The hostboot team requested that we only use enumerations for attribute values
    // These are attribute positions in an array, so moving them here
    // TODO: Zen:MST-1413 Update these for Odyssey
    SERIAL_PART_NUMBER = 3,
    SERIAL_PART_NUMBER_LEN = 7,
    SERIAL_RAW_CARD = 12,
    SERIAL_RAW_CARD_LEN = 2,
    SERIAL_SERIAL_NUMBER = 14,
    SERIAL_SERIAL_NUMBER_LEN = 12,
};

#endif

///
/// @brief Odyssey ffdc codes
///
enum ffdc_codes : uint16_t
{
// Note: uncomment these when they get used in the HWP code
#if 0
    EXP_I2C_GET_FIELD = 0x0000,
    EXP_I2C_SET_FIELD = 0x0001,
    READ_HOST_FW_RESPONSE_STRUCT = 0x0003,
    READ_SENSOR_CACHE_STRUCT = 0x0004,
    READ_CRCT_ENDIAN = 0x0005,
    READ_TRAINING_RESPONSE_STRUCT = 0x0006,
    READ_FW_ADAPTER_PROPERTIES_STRUCT = 0x0007,
    READ_MDS_TRAINING_RESPONSE_STRUCT = 0x0008,

    SET_EXP_DRAM_ADDRESS_MIRRORING = 0x1040,
    SET_BYTE_ENABLES = 0x1041,
    SET_NIBBLE_ENABLES = 0x1042,
    SET_TAA_MIN = 0x1043,
    SET_FOUR_RANK_MODE = 0x1044,
    SET_DDP_COMPATIBILITY = 0x1045,
    SET_TSV_8H_SUPPORT = 0x1046,
    SET_VREF_DQ_TRAIN_RANGE = 0x1047,
    SET_PSTATES = 0x1048,
    SET_MRAM_SUPPORT = 0x1049,

    SET_SERDES_FREQ = 0x1051,
    SET_MODULE_THERMAL_SENSORS = 0x1052,

    SET_THERM_SENSOR_0_AVAIL = 0x1053,
    SET_THERM_SENSOR_0_TYPE = 0x1054,
    SET_THERM_SENSOR_0_USAGE = 0x1055,
    SET_THERM_SENSOR_0_I2C_ADDR = 0x1056,

    SET_THERM_SENSOR_1_AVAIL = 0x1057,
    SET_THERM_SENSOR_1_TYPE = 0x1058,
    SET_THERM_SENSOR_1_USAGE = 0x1059,
    SET_THERM_SENSOR_1_I2C_ADDR = 0x105A,

    SET_THERM_SENSOR_DIFF_AVAIL = 0x105B,
    SET_THERM_SENSOR_DIFF_TYPE = 0x105C,
    SET_THERM_SENSOR_DIFF_USAGE = 0x105D,
    SET_THERM_SENSOR_DIFF_I2C_ADDR = 0x105E,

    READ_RC_RSP_FIELD = 0x105F,
    SET_F0RC00 = 0x1060,
    SET_F0RC01 = 0x1061,
    SET_F0RC03 = 0x1062,
    SET_F0RC04 = 0x1063,
    SET_F0RC05 = 0x1064,
    SET_F0RC0B = 0x1065,
    SET_F0RC0E = 0x1066,
    SET_F0RC0F = 0x1067,
    SET_F0RC1X = 0x1068,
    SET_F0RC7X = 0x1069,
    SET_F1RC00 = 0x106A,
    SET_F1RC02 = 0x106B,
    SET_F1RC03 = 0x106C,
    SET_F1RC04 = 0x106D,
    SET_F1RC05 = 0x106E,
    SET_SUPPORTED_RCD = 0x106F,

    SET_THERM_SENSOR_0_SECOND_AVAIL = 0x1070,
    SET_THERM_SENSOR_1_SECOND_AVAIL = 0x1071,
    SET_THERM_SENSOR_0_SECOND_I2C_ADDR = 0x1072,
    SET_THERM_SENSOR_1_SECOND_I2C_ADDR = 0x1073,
    SET_THERM_SENSOR_1_SECOND_LOCATION = 0x1074,
    SET_THERM_SENSOR_0_SECOND_LOCATION = 0x1075,
    SET_THERM_SENSOR_1_LOCATION = 0x1076,
    SET_THERM_SENSOR_0_LOCATION = 0x1077,
#endif
};

///
/// @brief constants for getecid procedure
/// TODO: Zen:MST-1414 Update these when we do ody_getecid
///
enum ecid_consts
{
    FUSE_ARRAY_SIZE = 14,
    DATA_IN_SIZE = 16,
    ATTR_ECID_SIZE = 2,
};

///
/// @brief constants for getidec procedure
/// TODO: Zen:MST-1415 Update these when we do ody_getidec
///
enum idec_consts
{
    ODY_CHIP_INFO_REG = 0x2134,
    LOCATION_BIT_START = 44,
    LOCATION_BIT_LENGTH = 4,
    CHIPID_BIT_START = 56,
    CHIPID_BIT_LENGTH = 8,

    REVISION_BIT_START  = 50,
    REVISION_BIT_LENGTH = 4,
};



///
/// @brief generic Odyssey constants
///
enum generic_consts
{
    // Number of DRAM for x4 vs x8
    ODY_NUM_DRAM_X4 = 20,
    ODY_NUM_DRAM_X8 = 10,

    // Map MDS into Power Thermal decoder mapping
    DIMM_TYPE_MDS = 20,

    // Note: restore repairs and our ECC logic use the MC/DFI perspective
    // As such, our spare is located on byte 5
    // Byte where the spare DRAM(s) are located
    SPARE_DQ_BYTE = 5,
};

} // namespace ody

} // namespace mss

#endif
