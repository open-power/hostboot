/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/spd/spdenums.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 * @file spdenums.H
 *
 * @brief Enums for the SPD fields to be requested.
 *
 */
#ifndef __SPDENUMS_H
#define __SPDENUMS_H

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
};

/**
* @brief Enumerations for fields that can be accessed in the SPD
*/
enum
{
    // ==============================================================
    // Normal SPD Kewords
    CRC_EXCLUDE                     = SPD_FIRST_NORM_KEYWORD | 0x00,
    SPD_BYTES_TOTAL                 = SPD_FIRST_NORM_KEYWORD | 0x01,
    SPD_BYTES_USED                  = SPD_FIRST_NORM_KEYWORD | 0x02,
    SPD_MAJOR_REVISION              = SPD_FIRST_NORM_KEYWORD | 0x03,
    SPD_MINOR_REVISION              = SPD_FIRST_NORM_KEYWORD | 0x04,
    BASIC_MEMORY_TYPE               = SPD_FIRST_NORM_KEYWORD | 0x05,
    MODULE_TYPE                     = SPD_FIRST_NORM_KEYWORD | 0x06,
    BANK_ADDRESS_BITS               = SPD_FIRST_NORM_KEYWORD | 0x07,
    DENSITY                         = SPD_FIRST_NORM_KEYWORD | 0x08,
    ROW_ADDRESS                     = SPD_FIRST_NORM_KEYWORD | 0x09,
    COL_ADDRESS                     = SPD_FIRST_NORM_KEYWORD | 0x0a,
    MODULE_NOMINAL_VOLTAGE          = SPD_FIRST_NORM_KEYWORD | 0x0b,
    MODULE_RANKS                    = SPD_FIRST_NORM_KEYWORD | 0x0c,
    MODULE_DRAM_WIDTH               = SPD_FIRST_NORM_KEYWORD | 0x0d,
    ECC_BITS                        = SPD_FIRST_NORM_KEYWORD | 0x0e,
    MODULE_MEMORY_BUS_WIDTH         = SPD_FIRST_NORM_KEYWORD | 0x0f,
    FTB_DIVIDEND                    = SPD_FIRST_NORM_KEYWORD | 0x10,
    FTB_DIVISOR                     = SPD_FIRST_NORM_KEYWORD | 0x11,
    MTB_DIVIDEND                    = SPD_FIRST_NORM_KEYWORD | 0x12,
    MTB_DIVISOR                     = SPD_FIRST_NORM_KEYWORD | 0x13,
    TCK_MIN                         = SPD_FIRST_NORM_KEYWORD | 0x14,
    CAS_LATENCIES_SUPPORTED         = SPD_FIRST_NORM_KEYWORD | 0x15,
    MIN_CAS_LATENCY                 = SPD_FIRST_NORM_KEYWORD | 0x16,
    TWR_MIN                         = SPD_FIRST_NORM_KEYWORD | 0x17,
    TRCD_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x18,
    TRRD_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x19,
    TRP_MIN                         = SPD_FIRST_NORM_KEYWORD | 0x1a,
    TRC_MIN                         = SPD_FIRST_NORM_KEYWORD | 0x1b,
    TRAS_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x1c,
    TRFC_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x1d,
    TWTR_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x1e,
    TRTP_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x1f,
    TFAW_MIN                        = SPD_FIRST_NORM_KEYWORD | 0x20,
    DLL_OFF                         = SPD_FIRST_NORM_KEYWORD | 0x21,
    RZQ_7                           = SPD_FIRST_NORM_KEYWORD | 0x22,
    RZQ_6                           = SPD_FIRST_NORM_KEYWORD | 0x23,
    PASR                            = SPD_FIRST_NORM_KEYWORD | 0x24,
    ODTS                            = SPD_FIRST_NORM_KEYWORD | 0x25,
    ASR                             = SPD_FIRST_NORM_KEYWORD | 0x26,
    ETR_1X                          = SPD_FIRST_NORM_KEYWORD | 0x27,
    ETR                             = SPD_FIRST_NORM_KEYWORD | 0x28,
    THERMAL_SENSOR_PRESENT          = SPD_FIRST_NORM_KEYWORD | 0x29,
    THERMAL_SENSOR_ACCURACY         = SPD_FIRST_NORM_KEYWORD | 0x2a,
    SDRAM_DEVICE_TYPE_NONSTD        = SPD_FIRST_NORM_KEYWORD | 0x2b,
    SDRAM_DEVICE_TYPE               = SPD_FIRST_NORM_KEYWORD | 0x2c,
    MODULE_TYPE_SPECIFIC_SECTION    = SPD_FIRST_NORM_KEYWORD | 0x2d,
    MODULE_MANUFACTURER_ID          = SPD_FIRST_NORM_KEYWORD | 0x2e,
    MODULE_MANUFACTURING_LOCATION   = SPD_FIRST_NORM_KEYWORD | 0x2f,
    MODULE_MANUFACTURING_DATE       = SPD_FIRST_NORM_KEYWORD | 0x30,
    MODULE_SERIAL_NUMBER            = SPD_FIRST_NORM_KEYWORD | 0x31,
    MODULE_CRC                      = SPD_FIRST_NORM_KEYWORD | 0x32,
    MODULE_PART_NUMBER              = SPD_FIRST_NORM_KEYWORD | 0x33,
    MODULE_REVISION_CODE            = SPD_FIRST_NORM_KEYWORD | 0x34,
    DRAM_MANUFACTURER_ID            = SPD_FIRST_NORM_KEYWORD | 0x35,
    MANUFACTURER_SPECIFIC_DATA      = SPD_FIRST_NORM_KEYWORD | 0x36,
    TCKMIN_FINE_OFFSET              = SPD_FIRST_NORM_KEYWORD | 0x37,
    TAAMIN_FINE_OFFSET              = SPD_FIRST_NORM_KEYWORD | 0x38,
    TRCDMIN_FINE_OFFSET             = SPD_FIRST_NORM_KEYWORD | 0x39,
    TRPMIN_FINE_OFFSET              = SPD_FIRST_NORM_KEYWORD | 0x3a,
    TRCMIN_FINE_OFFSET              = SPD_FIRST_NORM_KEYWORD | 0x3b,
    MODULE_THERMAL_SENSOR           = SPD_FIRST_NORM_KEYWORD | 0x3c,
    SDRAM_OPTIONAL_FEATURES         = SPD_FIRST_NORM_KEYWORD | 0x3d,
    SDRAM_THERMAL_REFRESH_OPTIONS   = SPD_FIRST_NORM_KEYWORD | 0x3e,
    DIMM_BAD_DQ_DATA                = SPD_FIRST_NORM_KEYWORD | 0x3f,
    SDRAM_DIE_COUNT                 = SPD_FIRST_NORM_KEYWORD | 0x40,
    SDRAM_DEVICE_TYPE_SIGNAL_LOADING = SPD_FIRST_NORM_KEYWORD | 0x41,
    SPD_LAST_NORM_KEYWORD,

    // ==============================================================
    // Module Specific Keywords
    MODSPEC_COM_NOM_HEIGHT_MAX      = SPD_FIRST_MOD_SPEC | 0x00,
    MODSPEC_COM_MAX_THICK_BACK      = SPD_FIRST_MOD_SPEC | 0x01,
    MODSPEC_COM_MAX_THICK_FRONT     = SPD_FIRST_MOD_SPEC | 0x02,
    MODSPEC_COM_RAW_CARD_EXT        = SPD_FIRST_MOD_SPEC | 0x03,
    MODSPEC_COM_RAW_CARD_REV        = SPD_FIRST_MOD_SPEC | 0x04,
    MODSPEC_COM_RAW_CARD            = SPD_FIRST_MOD_SPEC | 0x05,
    MODSPEC_COM_ADDR_MAPPING        = SPD_FIRST_MOD_SPEC | 0x06,
    RMM_ROWS_RDIMM                  = SPD_FIRST_MOD_SPEC | 0x07,
    RMM_REGS_RDIMM                  = SPD_FIRST_MOD_SPEC | 0x08,
    RMM_HEAT_SP                     = SPD_FIRST_MOD_SPEC | 0x09,
    RMM_HEAT_SP_CHARS               = SPD_FIRST_MOD_SPEC | 0x0a,
    RMM_MFR_ID_CODE                 = SPD_FIRST_MOD_SPEC | 0x0b,
    RMM_REG_REV_NUM                 = SPD_FIRST_MOD_SPEC | 0x0c,
    RMM_REG_TYPE                    = SPD_FIRST_MOD_SPEC | 0x0d,
    RMM_RC1                         = SPD_FIRST_MOD_SPEC | 0x0e,
    RMM_RC0                         = SPD_FIRST_MOD_SPEC | 0x0f,
    RMM_RC3                         = SPD_FIRST_MOD_SPEC | 0x10,
    RMM_RC2                         = SPD_FIRST_MOD_SPEC | 0x11,
    RMM_RC5                         = SPD_FIRST_MOD_SPEC | 0x12,
    RMM_RC4                         = SPD_FIRST_MOD_SPEC | 0x13,
    RMM_RC7                         = SPD_FIRST_MOD_SPEC | 0x14,
    RMM_RC6                         = SPD_FIRST_MOD_SPEC | 0x15,
    RMM_RC9                         = SPD_FIRST_MOD_SPEC | 0x16,
    RMM_RC8                         = SPD_FIRST_MOD_SPEC | 0x17,
    RMM_RC11                        = SPD_FIRST_MOD_SPEC | 0x18,
    RMM_RC10                        = SPD_FIRST_MOD_SPEC | 0x19,
    RMM_RC13                        = SPD_FIRST_MOD_SPEC | 0x1a,
    RMM_RC12                        = SPD_FIRST_MOD_SPEC | 0x1b,
    RMM_RC15                        = SPD_FIRST_MOD_SPEC | 0x1c,
    RMM_RC14                        = SPD_FIRST_MOD_SPEC | 0x1d,
    LRMM_HEAT_SP                    = SPD_FIRST_MOD_SPEC | 0x1e,
    LRMM_RANK_NUMBERING             = SPD_FIRST_MOD_SPEC | 0x1f,
    LRMM_MEMBUF_ORIEN               = SPD_FIRST_MOD_SPEC | 0x20,
    LRMM_NUM_ROWS                   = SPD_FIRST_MOD_SPEC | 0x21,
    LRMM_MIRRORING                  = SPD_FIRST_MOD_SPEC | 0x22,
    LRMM_REVISION_NUM               = SPD_FIRST_MOD_SPEC | 0x23,
    LRMM_MFR_ID_CODE                = SPD_FIRST_MOD_SPEC | 0x24,
    LRMM_F0RC3                      = SPD_FIRST_MOD_SPEC | 0x25,
    LRMM_F0RC2                      = SPD_FIRST_MOD_SPEC | 0x26,
    LRMM_F0RC5                      = SPD_FIRST_MOD_SPEC | 0x27,
    LRMM_F0RC4                      = SPD_FIRST_MOD_SPEC | 0x28,
    LRMM_F1RC11                     = SPD_FIRST_MOD_SPEC | 0x29,
    LRMM_F1RC8                      = SPD_FIRST_MOD_SPEC | 0x2a,
    LRMM_F1RC13                     = SPD_FIRST_MOD_SPEC | 0x2b,
    LRMM_F1RC12                     = SPD_FIRST_MOD_SPEC | 0x2c,
    LRMM_F1RC15                     = SPD_FIRST_MOD_SPEC | 0x2d,
    LRMM_F1RC14                     = SPD_FIRST_MOD_SPEC | 0x2e,
    LRMM_F3RC9_800_1600             = SPD_FIRST_MOD_SPEC | 0x2f,
    LRMM_F3RC8_800_1600             = SPD_FIRST_MOD_SPEC | 0x30,
    LRMM_F4RC11_800_1600            = SPD_FIRST_MOD_SPEC | 0x31,
    LRMM_F3RC11_800_1600            = SPD_FIRST_MOD_SPEC | 0x32,
    LRMM_F4RC10_800_1600            = SPD_FIRST_MOD_SPEC | 0x33,
    LRMM_F3RC10_800_1600            = SPD_FIRST_MOD_SPEC | 0x34,
    LRMM_F6RC11_800_1600            = SPD_FIRST_MOD_SPEC | 0x35,
    LRMM_F5RC11_800_1600            = SPD_FIRST_MOD_SPEC | 0x36,
    LRMM_F6RC10_800_1600            = SPD_FIRST_MOD_SPEC | 0x37,
    LRMM_F5RC10_800_1600            = SPD_FIRST_MOD_SPEC | 0x38,
    LRMM_F8RC11_800_1600            = SPD_FIRST_MOD_SPEC | 0x39,
    LRMM_F7RC11_800_1600            = SPD_FIRST_MOD_SPEC | 0x3a,
    LRMM_F8RC10_800_1600            = SPD_FIRST_MOD_SPEC | 0x3b,
    LRMM_F7RC10_800_1600            = SPD_FIRST_MOD_SPEC | 0x3c,
    LRMM_F10RC11_800_1600           = SPD_FIRST_MOD_SPEC | 0x3d,
    LRMM_F9RC11_800_1600            = SPD_FIRST_MOD_SPEC | 0x3e,
    LRMM_F10RC10_800_1600           = SPD_FIRST_MOD_SPEC | 0x3f,
    LRMM_F9RC10_800_1600            = SPD_FIRST_MOD_SPEC | 0x40,
    LRMM_RTT_WR_800_1600            = SPD_FIRST_MOD_SPEC | 0x41,
    LRMM_RTT_NOM_800_1600           = SPD_FIRST_MOD_SPEC | 0x42,
    LRMM_IMPEDANCE_800_1600         = SPD_FIRST_MOD_SPEC | 0x43,
    LRMM_F3RC9_1333_1600            = SPD_FIRST_MOD_SPEC | 0x44,
    LRMM_F3RC8_1333_1600            = SPD_FIRST_MOD_SPEC | 0x45,
    LRMM_F4RC11_1333_1600           = SPD_FIRST_MOD_SPEC | 0x46,
    LRMM_F3RC11_1333_1600           = SPD_FIRST_MOD_SPEC | 0x47,
    LRMM_F4RC10_1333_1600           = SPD_FIRST_MOD_SPEC | 0x48,
    LRMM_F3RC10_1333_1600           = SPD_FIRST_MOD_SPEC | 0x49,
    LRMM_F6RC11_1333_1600           = SPD_FIRST_MOD_SPEC | 0x4a,
    LRMM_F5RC11_1333_1600           = SPD_FIRST_MOD_SPEC | 0x4b,
    LRMM_F6RC10_1333_1600           = SPD_FIRST_MOD_SPEC | 0x4c,
    LRMM_F5RC10_1333_1600           = SPD_FIRST_MOD_SPEC | 0x4d,
    LRMM_F8RC11_1333_1600           = SPD_FIRST_MOD_SPEC | 0x4e,
    LRMM_F7RC11_1333_1600           = SPD_FIRST_MOD_SPEC | 0x4f,
    LRMM_F8RC10_1333_1600           = SPD_FIRST_MOD_SPEC | 0x50,
    LRMM_F7RC10_1333_1600           = SPD_FIRST_MOD_SPEC | 0x51,
    LRMM_F10RC11_1333_1600          = SPD_FIRST_MOD_SPEC | 0x52,
    LRMM_F9RC11_1333_1600           = SPD_FIRST_MOD_SPEC | 0x53,
    LRMM_F10RC10_1333_1600          = SPD_FIRST_MOD_SPEC | 0x54,
    LRMM_F9RC10_1333_1600           = SPD_FIRST_MOD_SPEC | 0x55,
    LRMM_RTT_WR_1333_1600           = SPD_FIRST_MOD_SPEC | 0x56,
    LRMM_RTT_NOM_1333_1600          = SPD_FIRST_MOD_SPEC | 0x57,
    LRMM_IMPEDANCE_1333_1600        = SPD_FIRST_MOD_SPEC | 0x58,
    LRMM_F3RC9_1866_2133            = SPD_FIRST_MOD_SPEC | 0x59,
    LRMM_F3RC8_1866_2133            = SPD_FIRST_MOD_SPEC | 0x5a,
    LRMM_F4RC11_1866_2133           = SPD_FIRST_MOD_SPEC | 0x5b,
    LRMM_F3RC11_1866_2133           = SPD_FIRST_MOD_SPEC | 0x5c,
    LRMM_F4RC10_1866_2133           = SPD_FIRST_MOD_SPEC | 0x5d,
    LRMM_F3RC10_1866_2133           = SPD_FIRST_MOD_SPEC | 0x5e,
    LRMM_F6RC11_1866_2133           = SPD_FIRST_MOD_SPEC | 0x5f,
    LRMM_F5RC11_1866_2133           = SPD_FIRST_MOD_SPEC | 0x60,
    LRMM_F6RC10_1866_2133           = SPD_FIRST_MOD_SPEC | 0x61,
    LRMM_F5RC10_1866_2133           = SPD_FIRST_MOD_SPEC | 0x62,
    LRMM_F8RC11_1866_2133           = SPD_FIRST_MOD_SPEC | 0x63,
    LRMM_F7RC11_1866_2133           = SPD_FIRST_MOD_SPEC | 0x64,
    LRMM_F8RC10_1866_2133           = SPD_FIRST_MOD_SPEC | 0x65,
    LRMM_F7RC10_1866_2133           = SPD_FIRST_MOD_SPEC | 0x66,
    LRMM_F10RC11_1866_2133          = SPD_FIRST_MOD_SPEC | 0x67,
    LRMM_F9RC11_1866_2133           = SPD_FIRST_MOD_SPEC | 0x68,
    LRMM_F10RC10_1866_2133          = SPD_FIRST_MOD_SPEC | 0x69,
    LRMM_F9RC10_1866_2133           = SPD_FIRST_MOD_SPEC | 0x6a,
    LRMM_RTT_WR_1866_2133           = SPD_FIRST_MOD_SPEC | 0x6b,
    LRMM_RTT_NOM_1866_2133          = SPD_FIRST_MOD_SPEC | 0x6c,
    LRMM_IMPEDANCE_1866_2133        = SPD_FIRST_MOD_SPEC | 0x6d,
    LRMM_MIN_DELAY_150V             = SPD_FIRST_MOD_SPEC | 0x6e,
    LRMM_MAX_DELAY_150V             = SPD_FIRST_MOD_SPEC | 0x6f,
    LRMM_MIN_DELAY_135V             = SPD_FIRST_MOD_SPEC | 0x70,
    LRMM_MAX_DELAY_135V             = SPD_FIRST_MOD_SPEC | 0x71,
    LRMM_MIN_DELAY_125V             = SPD_FIRST_MOD_SPEC | 0x72,
    LRMM_MAX_DELAY_125V             = SPD_FIRST_MOD_SPEC | 0x73,
    LRMM_PERSONALITY_BYTE0          = SPD_FIRST_MOD_SPEC | 0x74,
    LRMM_PERSONALITY_BYTE1          = SPD_FIRST_MOD_SPEC | 0x75,
    LRMM_PERSONALITY_BYTE2          = SPD_FIRST_MOD_SPEC | 0x76,
    LRMM_PERSONALITY_BYTE3          = SPD_FIRST_MOD_SPEC | 0x77,
    LRMM_PERSONALITY_BYTE4          = SPD_FIRST_MOD_SPEC | 0x78,
    LRMM_PERSONALITY_BYTE5          = SPD_FIRST_MOD_SPEC | 0x79,
    LRMM_PERSONALITY_BYTE6          = SPD_FIRST_MOD_SPEC | 0x7a,
    LRMM_PERSONALITY_BYTE7          = SPD_FIRST_MOD_SPEC | 0x7b,
    LRMM_PERSONALITY_BYTE8          = SPD_FIRST_MOD_SPEC | 0x7c,
    LRMM_PERSONALITY_BYTE9          = SPD_FIRST_MOD_SPEC | 0x7d,
    LRMM_PERSONALITY_BYTE10         = SPD_FIRST_MOD_SPEC | 0x7e,
    LRMM_PERSONALITY_BYTE11         = SPD_FIRST_MOD_SPEC | 0x7f,
    LRMM_PERSONALITY_BYTE12         = SPD_FIRST_MOD_SPEC | 0x80,
    LRMM_PERSONALITY_BYTE13         = SPD_FIRST_MOD_SPEC | 0x81,
    LRMM_PERSONALITY_BYTE14         = SPD_FIRST_MOD_SPEC | 0x82,
    SPD_LAST_MOD_SPEC,

    // This keyword should be last in the list
    // Invalid Keyword
    INVALID_SPD_KEYWORD                 = 0xFFFF,
};

};  // end SPD

#endif
