/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/spdenums.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
#ifndef __SPDENUMS_H
#define __SPDENUMS_H

#include <mbox/mbox_queues.H>

namespace SPD
{

/**
* @brief Enumerations for the start of each of the different sections of
*       keywords available to read.
*/
enum
{
    SPD_FIRST_NORM_KEYWORD      = 0x0,
    SPD_FIRST_MOD_SPEC          = 0x8000,
    SPD_DDR3 = 0xB,
    SPD_DDR4 = 0xC,
};

/**
* @brief Enumerations for fields that can be accessed in the SPD
*/
enum
{
    // ==============================================================
    // Normal SPD Keywords (Available for both DDR3 and DDR4 DIMMs)
    CRC_EXCLUDE                      = SPD_FIRST_NORM_KEYWORD | 0x00,
    SPD_BYTES_TOTAL                  = SPD_FIRST_NORM_KEYWORD | 0x01,
    SPD_BYTES_USED                   = SPD_FIRST_NORM_KEYWORD | 0x02,
    SPD_MAJOR_REVISION               = SPD_FIRST_NORM_KEYWORD | 0x03,
    SPD_MINOR_REVISION               = SPD_FIRST_NORM_KEYWORD | 0x04,
    BASIC_MEMORY_TYPE                = SPD_FIRST_NORM_KEYWORD | 0x05,
    CUSTOM                           = SPD_FIRST_NORM_KEYWORD | 0x06,
    MODULE_TYPE                      = SPD_FIRST_NORM_KEYWORD | 0x07,
    DENSITY                          = SPD_FIRST_NORM_KEYWORD | 0x08,
    ROW_ADDRESS                      = SPD_FIRST_NORM_KEYWORD | 0x09,
    COL_ADDRESS                      = SPD_FIRST_NORM_KEYWORD | 0x0a,
    MODULE_RANKS                     = SPD_FIRST_NORM_KEYWORD | 0x0b,
    MODULE_DRAM_WIDTH                = SPD_FIRST_NORM_KEYWORD | 0x0c,
    MODULE_MEMORY_BUS_WIDTH          = SPD_FIRST_NORM_KEYWORD | 0x0d,
    MODULE_MEMORY_BUS_WIDTH_EXT      = SPD_FIRST_NORM_KEYWORD | 0x0e,
    MODULE_MEMORY_BUS_WIDTH_PRI      = SPD_FIRST_NORM_KEYWORD | 0x0f,
    TCK_MIN                          = SPD_FIRST_NORM_KEYWORD | 0x10,
    MIN_CAS_LATENCY                  = SPD_FIRST_NORM_KEYWORD | 0x11,
    TRCD_MIN                         = SPD_FIRST_NORM_KEYWORD | 0x12,
    TRP_MIN                          = SPD_FIRST_NORM_KEYWORD | 0x13,
    TRC_MIN                          = SPD_FIRST_NORM_KEYWORD | 0x14,
    TRAS_MIN                         = SPD_FIRST_NORM_KEYWORD | 0x15,
    TFAW_MIN                         = SPD_FIRST_NORM_KEYWORD | 0x16,
    SDRAM_OPTIONAL_FEATURES          = SPD_FIRST_NORM_KEYWORD | 0x17,
    SDRAM_THERMAL_REFRESH_OPTIONS    = SPD_FIRST_NORM_KEYWORD | 0x18,
    MODULE_THERMAL_SENSOR            = SPD_FIRST_NORM_KEYWORD | 0x19,
    THERMAL_SENSOR_PRESENT           = SPD_FIRST_NORM_KEYWORD | 0x1a,
    THERMAL_SENSOR_ACCURACY          = SPD_FIRST_NORM_KEYWORD | 0x1b,
    SDRAM_DEVICE_TYPE                = SPD_FIRST_NORM_KEYWORD | 0x1c,
    SDRAM_DIE_COUNT                  = SPD_FIRST_NORM_KEYWORD | 0x1d,
    SDRAM_DEVICE_TYPE_SIGNAL_LOADING = SPD_FIRST_NORM_KEYWORD | 0x1e,
    TCKMIN_FINE_OFFSET               = SPD_FIRST_NORM_KEYWORD | 0x1f,
    TAAMIN_FINE_OFFSET               = SPD_FIRST_NORM_KEYWORD | 0x20,
    TRCDMIN_FINE_OFFSET              = SPD_FIRST_NORM_KEYWORD | 0x21,
    TRPMIN_FINE_OFFSET               = SPD_FIRST_NORM_KEYWORD | 0x22,
    TRCMIN_FINE_OFFSET               = SPD_FIRST_NORM_KEYWORD | 0x23,
    MODULE_TYPE_SPECIFIC_SECTION     = SPD_FIRST_NORM_KEYWORD | 0x24,
    MODULE_MANUFACTURER_ID           = SPD_FIRST_NORM_KEYWORD | 0x25,
    MODULE_MANUFACTURING_LOCATION    = SPD_FIRST_NORM_KEYWORD | 0x26,
    MODULE_MANUFACTURING_DATE        = SPD_FIRST_NORM_KEYWORD | 0x27,
    MODULE_SERIAL_NUMBER             = SPD_FIRST_NORM_KEYWORD | 0x28,
    MODULE_PART_NUMBER               = SPD_FIRST_NORM_KEYWORD | 0x29,
    DRAM_MANUFACTURER_ID             = SPD_FIRST_NORM_KEYWORD | 0x2a,
    MANUFACTURER_SPECIFIC_DATA       = SPD_FIRST_NORM_KEYWORD | 0x2b,
    DIMM_BAD_DQ_DATA                 = SPD_FIRST_NORM_KEYWORD | 0x2c,

    // ==============================================================
    // Normal SPD Keywords (Available for DDR3 DIMMs only)
    BANK_ADDRESS_BITS                = SPD_FIRST_NORM_KEYWORD | 0x2d,
    MODULE_NOMINAL_VOLTAGE           = SPD_FIRST_NORM_KEYWORD | 0x2e,
    FTB_DIVIDEND                     = SPD_FIRST_NORM_KEYWORD | 0x2f,
    FTB_DIVISOR                      = SPD_FIRST_NORM_KEYWORD | 0x30,
    MTB_DIVIDEND                     = SPD_FIRST_NORM_KEYWORD | 0x31,
    MTB_DIVISOR                      = SPD_FIRST_NORM_KEYWORD | 0x32,
    CAS_LATENCIES_SUPPORTED          = SPD_FIRST_NORM_KEYWORD | 0x33,
    TWR_MIN                          = SPD_FIRST_NORM_KEYWORD | 0x34,
    TRRD_MIN                         = SPD_FIRST_NORM_KEYWORD | 0x35,
    TRFC_MIN                         = SPD_FIRST_NORM_KEYWORD | 0x36,
    TWTR_MIN                         = SPD_FIRST_NORM_KEYWORD | 0x37,
    TRTP_MIN                         = SPD_FIRST_NORM_KEYWORD | 0x38,
    DLL_OFF                          = SPD_FIRST_NORM_KEYWORD | 0x39,
    RZQ_7                            = SPD_FIRST_NORM_KEYWORD | 0x3a,
    RZQ_6                            = SPD_FIRST_NORM_KEYWORD | 0x3b,
    PASR                             = SPD_FIRST_NORM_KEYWORD | 0x3c,
    ODTS                             = SPD_FIRST_NORM_KEYWORD | 0x3d,
    ASR                              = SPD_FIRST_NORM_KEYWORD | 0x3e,
    ETR_1X                           = SPD_FIRST_NORM_KEYWORD | 0x3f,
    ETR                              = SPD_FIRST_NORM_KEYWORD | 0x40,
    MODULE_CRC                       = SPD_FIRST_NORM_KEYWORD | 0x41,
    MODULE_REVISION_CODE             = SPD_FIRST_NORM_KEYWORD | 0x42,

    // ==============================================================
    // Normal SPD Keywords (Available for DDR4 DIMMs only)
    BANK_GROUP_BITS                  = SPD_FIRST_NORM_KEYWORD | 0x43,
    BANK_ADDRESS_BITS_DDR4           = SPD_FIRST_NORM_KEYWORD | 0x44,
    MODULE_NOMINAL_VOLTAGE_DDR4      = SPD_FIRST_NORM_KEYWORD | 0x45,
    TIMEBASES_MTB                    = SPD_FIRST_NORM_KEYWORD | 0x46,
    TIMEBASES_FTB                    = SPD_FIRST_NORM_KEYWORD | 0x47,
    TCK_MAX                          = SPD_FIRST_NORM_KEYWORD | 0x48,
    CAS_LATENCIES_SUPPORTED_DDR4     = SPD_FIRST_NORM_KEYWORD | 0x49,
    TRFC1_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x4a,
    TRFC2_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x4b,
    TRFC4_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x4c,
    TRRDS_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x4d,
    TRRDL_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x4e,
    TCCDL_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x4f,
    CONNECTOR_SDRAM_MAP              = SPD_FIRST_NORM_KEYWORD | 0x50,
    TCCDL_FINE_OFFSET                = SPD_FIRST_NORM_KEYWORD | 0x51,
    TRRDL_FINE_OFFSET                = SPD_FIRST_NORM_KEYWORD | 0x52,
    TRRDS_FINE_OFFSET                = SPD_FIRST_NORM_KEYWORD | 0x53,
    TCKMAX_FINE_OFFSET               = SPD_FIRST_NORM_KEYWORD | 0x54,
    BASE_CONFIG_CRC                  = SPD_FIRST_NORM_KEYWORD | 0x55,
    MODULE_REVISION_CODE_DDR4        = MODULE_REVISION_CODE,
    DRAM_STEPPING                    = SPD_FIRST_NORM_KEYWORD | 0x57,
    MANUFACTURING_SECTION_CRC        = SPD_FIRST_NORM_KEYWORD | 0x58,
    SPD_LAST_NORM_KEYWORD            = SPD_FIRST_NORM_KEYWORD | 0x58,

    // ==============================================================
    // Module Specific Keywords (Available for both DDR3 and DDR4 DIMMs)
    MODSPEC_COM_NOM_HEIGHT_MAX       = SPD_FIRST_MOD_SPEC | 0x00,
    MODSPEC_COM_MAX_THICK_BACK       = SPD_FIRST_MOD_SPEC | 0x01,
    MODSPEC_COM_MAX_THICK_FRONT      = SPD_FIRST_MOD_SPEC | 0x02,
    MODSPEC_COM_REF_RAW_CARD_EXT     = SPD_FIRST_MOD_SPEC | 0x03,
    MODSPEC_COM_REF_RAW_CARD_REV     = SPD_FIRST_MOD_SPEC | 0x04,
    MODSPEC_COM_REF_RAW_CARD         = SPD_FIRST_MOD_SPEC | 0x05,
    UMM_ADDR_MAPPING                 = SPD_FIRST_MOD_SPEC | 0x06,
    RMM_ROWS_RDIMM                   = SPD_FIRST_MOD_SPEC | 0x07,
    RMM_REGS_RDIMM                   = SPD_FIRST_MOD_SPEC | 0x08,
    RMM_HEAT_SP                      = SPD_FIRST_MOD_SPEC | 0x09,
    RMM_HEAT_SP_CHARS                = SPD_FIRST_MOD_SPEC | 0x0a,
    RMM_MFR_ID_CODE                  = SPD_FIRST_MOD_SPEC | 0x0b,
    RMM_REG_REV_NUM                  = SPD_FIRST_MOD_SPEC | 0x0c,
    LRMM_HEAT_SP                     = SPD_FIRST_MOD_SPEC | 0x0d,
    LRMM_NUM_ROWS                    = SPD_FIRST_MOD_SPEC | 0x0e,
    LRMM_MIRRORING                   = SPD_FIRST_MOD_SPEC | 0x0f,
    LRMM_REVISION_NUM                = SPD_FIRST_MOD_SPEC | 0x10,
    MODSPEC_MM_MFR_ID_CODE           = SPD_FIRST_MOD_SPEC | 0x11,

    // ==============================================================
    // Module Specific Keywords (Available for DDR3 DIMMs only)
    RMM_REG_TYPE                     = SPD_FIRST_MOD_SPEC | 0x12,
    RMM_RC1                          = SPD_FIRST_MOD_SPEC | 0x13,
    RMM_RC0                          = SPD_FIRST_MOD_SPEC | 0x14,
    RMM_RC3                          = SPD_FIRST_MOD_SPEC | 0x15,
    RMM_RC2                          = SPD_FIRST_MOD_SPEC | 0x16,
    RMM_RC5                          = SPD_FIRST_MOD_SPEC | 0x17,
    RMM_RC4                          = SPD_FIRST_MOD_SPEC | 0x18,
    RMM_RC7                          = SPD_FIRST_MOD_SPEC | 0x19,
    RMM_RC6                          = SPD_FIRST_MOD_SPEC | 0x1a,
    RMM_RC9                          = SPD_FIRST_MOD_SPEC | 0x1b,
    RMM_RC8                          = SPD_FIRST_MOD_SPEC | 0x1c,
    RMM_RC11                         = SPD_FIRST_MOD_SPEC | 0x1d,
    RMM_RC10                         = SPD_FIRST_MOD_SPEC | 0x1e,
    RMM_RC13                         = SPD_FIRST_MOD_SPEC | 0x1f,
    RMM_RC12                         = SPD_FIRST_MOD_SPEC | 0x20,
    RMM_RC15                         = SPD_FIRST_MOD_SPEC | 0x21,
    RMM_RC14                         = SPD_FIRST_MOD_SPEC | 0x22,
    LRMM_RANK_NUMBERING              = SPD_FIRST_MOD_SPEC | 0x23,
    LRMM_MEMBUF_ORIEN                = SPD_FIRST_MOD_SPEC | 0x24,
    LRMM_F0RC3_F0RC2                 = SPD_FIRST_MOD_SPEC | 0x25,
    LRMM_F0RC3                       = SPD_FIRST_MOD_SPEC | 0x26,
    LRMM_F0RC2                       = SPD_FIRST_MOD_SPEC | 0x27,
    LRMM_F0RC5_F0RC4                 = SPD_FIRST_MOD_SPEC | 0x28,
    LRMM_F0RC5                       = SPD_FIRST_MOD_SPEC | 0x29,
    LRMM_F0RC4                       = SPD_FIRST_MOD_SPEC | 0x2a,
    LRMM_F1RC11_F1RC8                = SPD_FIRST_MOD_SPEC | 0x2b,
    LRMM_F1RC11                      = SPD_FIRST_MOD_SPEC | 0x2c,
    LRMM_F1RC8                       = SPD_FIRST_MOD_SPEC | 0x2d,
    LRMM_F1RC13_F1RC12               = SPD_FIRST_MOD_SPEC | 0x2e,
    LRMM_F1RC13                      = SPD_FIRST_MOD_SPEC | 0x2f,
    LRMM_F1RC12                      = SPD_FIRST_MOD_SPEC | 0x30,
    LRMM_F1RC15_F1RC14               = SPD_FIRST_MOD_SPEC | 0x31,
    LRMM_F1RC15                      = SPD_FIRST_MOD_SPEC | 0x32,
    LRMM_F1RC14                      = SPD_FIRST_MOD_SPEC | 0x33,
    LRMM_F3RC9_F3RC8_800_1066        = SPD_FIRST_MOD_SPEC | 0x34,
    LRMM_F3RC9_800_1600              = SPD_FIRST_MOD_SPEC | 0x35,
    LRMM_F3RC8_800_1600              = SPD_FIRST_MOD_SPEC | 0x36,
    LRMM_F34RC11_F34RC10_800_1066    = SPD_FIRST_MOD_SPEC | 0x37,
    LRMM_F4RC11_800_1600             = SPD_FIRST_MOD_SPEC | 0x38,
    LRMM_F3RC11_800_1600             = SPD_FIRST_MOD_SPEC | 0x39,
    LRMM_F4RC10_800_1600             = SPD_FIRST_MOD_SPEC | 0x3a,
    LRMM_F3RC10_800_1600             = SPD_FIRST_MOD_SPEC | 0x3b,
    LRMM_F56RC11_F56RC10_800_1066    = SPD_FIRST_MOD_SPEC | 0x3c,
    LRMM_F6RC11_800_1600             = SPD_FIRST_MOD_SPEC | 0x3d,
    LRMM_F5RC11_800_1600             = SPD_FIRST_MOD_SPEC | 0x3e,
    LRMM_F6RC10_800_1600             = SPD_FIRST_MOD_SPEC | 0x3f,
    LRMM_F5RC10_800_1600             = SPD_FIRST_MOD_SPEC | 0x40,
    LRMM_F78RC11_F78RC10_800_1066    = SPD_FIRST_MOD_SPEC | 0x41,
    LRMM_F8RC11_800_1600             = SPD_FIRST_MOD_SPEC | 0x42,
    LRMM_F7RC11_800_1600             = SPD_FIRST_MOD_SPEC | 0x43,
    LRMM_F8RC10_800_1600             = SPD_FIRST_MOD_SPEC | 0x44,
    LRMM_F7RC10_800_1600             = SPD_FIRST_MOD_SPEC | 0x45,
    LRMM_F910RC11_F910RC10_800_1066  = SPD_FIRST_MOD_SPEC | 0x46,
    LRMM_F10RC11_800_1600            = SPD_FIRST_MOD_SPEC | 0x47,
    LRMM_F9RC11_800_1600             = SPD_FIRST_MOD_SPEC | 0x48,
    LRMM_F10RC10_800_1600            = SPD_FIRST_MOD_SPEC | 0x49,
    LRMM_F9RC10_800_1600             = SPD_FIRST_MOD_SPEC | 0x4a,
    LRMM_MR12_800_1066               = SPD_FIRST_MOD_SPEC | 0x4b,
    LRMM_RTT_WR_800_1600             = SPD_FIRST_MOD_SPEC | 0x4c,
    LRMM_RTT_NOM_800_1600            = SPD_FIRST_MOD_SPEC | 0x4d,
    LRMM_IMPEDANCE_800_1600          = SPD_FIRST_MOD_SPEC | 0x4e,
    LRMM_F3RC9_F3RC8_1333_1600       = SPD_FIRST_MOD_SPEC | 0x4f,
    LRMM_F3RC9_1333_1600             = SPD_FIRST_MOD_SPEC | 0x50,
    LRMM_F3RC8_1333_1600             = SPD_FIRST_MOD_SPEC | 0x51,
    LRMM_F34RC11_F34RC10_1333_1600   = SPD_FIRST_MOD_SPEC | 0x52,
    LRMM_F4RC11_1333_1600            = SPD_FIRST_MOD_SPEC | 0x53,
    LRMM_F3RC11_1333_1600            = SPD_FIRST_MOD_SPEC | 0x54,
    LRMM_F4RC10_1333_1600            = SPD_FIRST_MOD_SPEC | 0x55,
    LRMM_F3RC10_1333_1600            = SPD_FIRST_MOD_SPEC | 0x56,
    LRMM_F56RC11_F56RC10_1333_1600   = SPD_FIRST_MOD_SPEC | 0x57,
    LRMM_F6RC11_1333_1600            = SPD_FIRST_MOD_SPEC | 0x58,
    LRMM_F5RC11_1333_1600            = SPD_FIRST_MOD_SPEC | 0x59,
    LRMM_F6RC10_1333_1600            = SPD_FIRST_MOD_SPEC | 0x5a,
    LRMM_F5RC10_1333_1600            = SPD_FIRST_MOD_SPEC | 0x5b,
    LRMM_F78RC11_F78RC10_1333_1600   = SPD_FIRST_MOD_SPEC | 0x5c,
    LRMM_F8RC11_1333_1600            = SPD_FIRST_MOD_SPEC | 0x5d,
    LRMM_F7RC11_1333_1600            = SPD_FIRST_MOD_SPEC | 0x5e,
    LRMM_F8RC10_1333_1600            = SPD_FIRST_MOD_SPEC | 0x5f,
    LRMM_F7RC10_1333_1600            = SPD_FIRST_MOD_SPEC | 0x60,
    LRMM_F910RC11_F910RC10_1333_1600 = SPD_FIRST_MOD_SPEC | 0x61,
    LRMM_F10RC11_1333_1600           = SPD_FIRST_MOD_SPEC | 0x62,
    LRMM_F9RC11_1333_1600            = SPD_FIRST_MOD_SPEC | 0x63,
    LRMM_F10RC10_1333_1600           = SPD_FIRST_MOD_SPEC | 0x64,
    LRMM_F9RC10_1333_1600            = SPD_FIRST_MOD_SPEC | 0x65,
    LRMM_MR12_1333_1600              = SPD_FIRST_MOD_SPEC | 0x66,
    LRMM_RTT_WR_1333_1600            = SPD_FIRST_MOD_SPEC | 0x67,
    LRMM_RTT_NOM_1333_1600           = SPD_FIRST_MOD_SPEC | 0x68,
    LRMM_IMPEDANCE_1333_1600         = SPD_FIRST_MOD_SPEC | 0x69,
    LRMM_F3RC9_F3RC8_1866_2133       = SPD_FIRST_MOD_SPEC | 0x6a,
    LRMM_F3RC9_1866_2133             = SPD_FIRST_MOD_SPEC | 0x6b,
    LRMM_F3RC8_1866_2133             = SPD_FIRST_MOD_SPEC | 0x6c,
    LRMM_F34RC11_F34RC10_1866_2133   = SPD_FIRST_MOD_SPEC | 0x6d,
    LRMM_F4RC11_1866_2133            = SPD_FIRST_MOD_SPEC | 0x6e,
    LRMM_F3RC11_1866_2133            = SPD_FIRST_MOD_SPEC | 0x6f,
    LRMM_F4RC10_1866_2133            = SPD_FIRST_MOD_SPEC | 0x70,
    LRMM_F3RC10_1866_2133            = SPD_FIRST_MOD_SPEC | 0x71,
    LRMM_F56RC11_F56RC10_1866_2133   = SPD_FIRST_MOD_SPEC | 0x72,
    LRMM_F6RC11_1866_2133            = SPD_FIRST_MOD_SPEC | 0x73,
    LRMM_F5RC11_1866_2133            = SPD_FIRST_MOD_SPEC | 0x74,
    LRMM_F6RC10_1866_2133            = SPD_FIRST_MOD_SPEC | 0x75,
    LRMM_F5RC10_1866_2133            = SPD_FIRST_MOD_SPEC | 0x76,
    LRMM_F78RC11_F78RC10_1866_2133   = SPD_FIRST_MOD_SPEC | 0x77,
    LRMM_F8RC11_1866_2133            = SPD_FIRST_MOD_SPEC | 0x78,
    LRMM_F7RC11_1866_2133            = SPD_FIRST_MOD_SPEC | 0x79,
    LRMM_F8RC10_1866_2133            = SPD_FIRST_MOD_SPEC | 0x7a,
    LRMM_F7RC10_1866_2133            = SPD_FIRST_MOD_SPEC | 0x7b,
    LRMM_F910RC11_F910RC10_1866_2133 = SPD_FIRST_MOD_SPEC | 0x7c,
    LRMM_F10RC11_1866_2133           = SPD_FIRST_MOD_SPEC | 0x7d,
    LRMM_F9RC11_1866_2133            = SPD_FIRST_MOD_SPEC | 0x7e,
    LRMM_F10RC10_1866_2133           = SPD_FIRST_MOD_SPEC | 0x7f,
    LRMM_F9RC10_1866_2133            = SPD_FIRST_MOD_SPEC | 0x80,
    LRMM_MR12_FOR_1866_2133          = SPD_FIRST_MOD_SPEC | 0x81,
    LRMM_RTT_WR_1866_2133            = SPD_FIRST_MOD_SPEC | 0x82,
    LRMM_RTT_NOM_1866_2133           = SPD_FIRST_MOD_SPEC | 0x83,
    LRMM_IMPEDANCE_1866_2133         = SPD_FIRST_MOD_SPEC | 0x84,
    LRMM_MIN_DELAY_150V              = SPD_FIRST_MOD_SPEC | 0x85,
    LRMM_MAX_DELAY_150V              = SPD_FIRST_MOD_SPEC | 0x86,
    LRMM_MIN_DELAY_135V              = SPD_FIRST_MOD_SPEC | 0x87,
    LRMM_MAX_DELAY_135V              = SPD_FIRST_MOD_SPEC | 0x88,
    LRMM_MIN_DELAY_125V              = SPD_FIRST_MOD_SPEC | 0x89,
    LRMM_MAX_DELAY_125V              = SPD_FIRST_MOD_SPEC | 0x8a,
    LRMM_PERSONALITY_BYTE0           = SPD_FIRST_MOD_SPEC | 0x8b,
    LRMM_PERSONALITY_BYTE1           = SPD_FIRST_MOD_SPEC | 0x8c,
    LRMM_PERSONALITY_BYTE2           = SPD_FIRST_MOD_SPEC | 0x8d,
    LRMM_PERSONALITY_BYTE3           = SPD_FIRST_MOD_SPEC | 0x8e,
    LRMM_PERSONALITY_BYTE4           = SPD_FIRST_MOD_SPEC | 0x8f,
    LRMM_PERSONALITY_BYTE5           = SPD_FIRST_MOD_SPEC | 0x90,
    LRMM_PERSONALITY_BYTE6           = SPD_FIRST_MOD_SPEC | 0x91,
    LRMM_PERSONALITY_BYTE7           = SPD_FIRST_MOD_SPEC | 0x92,
    LRMM_PERSONALITY_BYTE8           = SPD_FIRST_MOD_SPEC | 0x93,
    LRMM_PERSONALITY_BYTE9           = SPD_FIRST_MOD_SPEC | 0x94,
    LRMM_PERSONALITY_BYTE10          = SPD_FIRST_MOD_SPEC | 0x95,
    LRMM_PERSONALITY_BYTE11          = SPD_FIRST_MOD_SPEC | 0x96,
    LRMM_PERSONALITY_BYTE12          = SPD_FIRST_MOD_SPEC | 0x97,
    LRMM_PERSONALITY_BYTE13          = SPD_FIRST_MOD_SPEC | 0x99,
    LRMM_PERSONALITY_BYTE14          = SPD_FIRST_MOD_SPEC | 0x99,

    // ==============================================================
    // Module Specific Keywords (Available for DDR4 DIMMs only)
    MODSPEC_COM_RAW_CARD_EXT         = SPD_FIRST_MOD_SPEC | 0x9a,
    UMM_CRC                          = SPD_FIRST_MOD_SPEC | 0x9b,
    RMM_ADDR_MAPPING                 = SPD_FIRST_MOD_SPEC | 0x9c,
    MODSPEC_MM_ATTRIBS               = SPD_FIRST_MOD_SPEC | 0x9d,
    MODSPEC_MM_ADDR_MAPPING          = SPD_FIRST_MOD_SPEC | 0x9e,
    MODSPEC_MM_DRV_STRENGTH_CNTL     = SPD_FIRST_MOD_SPEC | 0x9f,
    MODSPEC_MM_DRV_STRENGTH_CK       = SPD_FIRST_MOD_SPEC | 0xa0,
    LRMM_VREF_DQ_RANK0               = SPD_FIRST_MOD_SPEC | 0xa1,
    LRMM_VREF_DQ_RANK1               = SPD_FIRST_MOD_SPEC | 0xa2,
    LRMM_VREF_DQ_RANK2               = SPD_FIRST_MOD_SPEC | 0xa3,
    LRMM_VREF_DQ_RANK3               = SPD_FIRST_MOD_SPEC | 0xa4,
    LRMM_VREF_DQ_FOR_DRAM            = SPD_FIRST_MOD_SPEC | 0xa5,
    LRMM_MDQ_DRV_LT_1866             = SPD_FIRST_MOD_SPEC | 0xa6,
    LRMM_MDQ_DRV_1866_2400           = SPD_FIRST_MOD_SPEC | 0xa7,
    LRMM_MDQ_DRV_2400_3200           = SPD_FIRST_MOD_SPEC | 0xa8,
    LRMM_DRV_STRENGTH                = SPD_FIRST_MOD_SPEC | 0xa9,
    LRMM_ODT_RTT_WR_LT_1866          = SPD_FIRST_MOD_SPEC | 0xaa,
    LRMM_ODT_RTT_NOM_LT_1866         = SPD_FIRST_MOD_SPEC | 0xab,
    LRMM_ODT_RTT_WR_1866_2400        = SPD_FIRST_MOD_SPEC | 0xac,
    LRMM_ODT_RTT_NOM_1866_2400       = SPD_FIRST_MOD_SPEC | 0xad,
    LRMM_ODT_RTT_WR_2400_3200        = SPD_FIRST_MOD_SPEC | 0xae,
    LRMM_ODT_RTT_NOM_2400_3200       = SPD_FIRST_MOD_SPEC | 0xaf,
    LRMM_ODT_RTT_PARK_LT_1866        = SPD_FIRST_MOD_SPEC | 0xb0,
    LRMM_ODT_RTT_PARK_1866_2400      = SPD_FIRST_MOD_SPEC | 0xb1,
    LRMM_ODT_RTT_PARK_2400_3200      = SPD_FIRST_MOD_SPEC | 0xb2,
    RMM_CRC                          = SPD_FIRST_MOD_SPEC | 0xb3,
    LRMM_CRC                         = SPD_FIRST_MOD_SPEC | 0xb4,
    SPD_LAST_MOD_SPEC                = SPD_FIRST_MOD_SPEC | 0xb5,

    // This keyword should be last in the list
    // Invalid Keyword
    ENTIRE_SPD                          = 0xFFFE,  //read entire SPD
    INVALID_SPD_KEYWORD                 = 0xFFFF,
};

enum
{   
    // These are LRDIMM values for Module Type attribute
    // according to ver3 and ver4 JEDEC specs
    JEDEC_VER3_LRDIMM_VAL      = 0x0b,
    JEDEC_VER4_LRDIMM_VAL      = 0x04,
};


};  // end SPD

#endif
