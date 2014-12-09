/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/spdDDR3.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
#ifndef __SPDDDR3_H
#define __SPDDDR3_H

/**
 * @file spdDDR3.H
 *
 * @brief brief Provides the DDR3 field information
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include "spd.H"

namespace SPD
{

/**
 * @brief Pre-defined lookup table for DDR3 keywords and the
 *      information needed to read that data from the SPD data.
 */
const KeywordData ddr3Data[] =
{
    // ----------------------------------------------------------------------------------
    // NOTE: This list must remain an ordered list! The Keyword must be in numerical 
    //       order (values defined in spdenums.H) to allow efficient searching, a unit
    //       test enforces this.
    // ----------------------------------------------------------------------------------
    // Bit order for each byte is [7:0] as defined by the JEDEC spec (little endian)
    //
    // For multi-byte fields, the offset specifies the byte that is placed at offset 0 in
    // the output buffer.
    // - If SpecialCase=false then the next byte in SPD is placed at the next offset in
    //   the output buffer until complete. Any bitmask/shift only affects the byte at
    //   offset 0
    // - If SpecialCase=true then spd.C handles the field in a custom way (e.g. working
    //   backwards through SPD bytes).
    // Typically for a 2-byte field consisting of (LSB,MSB), the offset points to MSB and
    // it is a SpecialCase where spd.C first copies the MSB to the output buffer then
    // copies the previous byte (LSB) to the output buffer (big endian).
    // ------------------------------------------------------------------------------------------
    // Keyword                          offset  size    Bitmsk  Shift  Spec  Writ-  Mod
    //                                                          Number Case  able   Spec
    // ------------------------------------------------------------------------------------------
    // Normal fields supported on both DDR3 and DDR4
    { CRC_EXCLUDE,                      0x00,   0x01,   0x80,   0x07, false, false, NA },
    { SPD_BYTES_TOTAL,                  0x00,   0x01,   0x70,   0x04, false, false, NA },
    { SPD_BYTES_USED,                   0x00,   0x01,   0x0F,   0x00, false, false, NA },
    { SPD_MAJOR_REVISION,               0x01,   0x01,   0xF0,   0x04, false, false, NA },
    { SPD_MINOR_REVISION,               0x01,   0x01,   0x0F,   0x00, false, false, NA },
    { BASIC_MEMORY_TYPE,                0x02,   0x01,   0x00,   0x00, false, false, NA },
    { CUSTOM,                           0x03,   0x01,   0x80,   0x07, false, false, NA },
    { MODULE_TYPE,                      0x03,   0x01,   0x0F,   0x00, false, false, NA },
    { DENSITY,                          0x04,   0x01,   0x0F,   0x00, false, false, NA },
    { ROW_ADDRESS,                      0x05,   0x01,   0x38,   0x03, false, false, NA },
    { COL_ADDRESS,                      0x05,   0x01,   0x07,   0x00, false, false, NA },
    { MODULE_RANKS,                     0x07,   0x01,   0x38,   0x03, false, false, NA },
    { MODULE_DRAM_WIDTH,                0x07,   0x01,   0x07,   0x00, false, false, NA },
    { MODULE_MEMORY_BUS_WIDTH,          0x08,   0x01,   0x1f,   0x00, false, false, NA },
    { MODULE_MEMORY_BUS_WIDTH_EXT,      0x08,   0x01,   0x18,   0x03, false, false, NA },
    { MODULE_MEMORY_BUS_WIDTH_PRI,      0x08,   0x01,   0x07,   0x00, false, false, NA },
    { TCK_MIN,                          0x0c,   0x01,   0x00,   0x00, false, false, NA },
    { MIN_CAS_LATENCY,                  0x10,   0x01,   0x00,   0x00, false, false, NA },
    { TRCD_MIN,                         0x12,   0x01,   0x00,   0x00, false, false, NA },
    { TRP_MIN,                          0x14,   0x01,   0x00,   0x00, false, false, NA },
    { TRC_MIN,                          0x15,   0x02,   0xF0,   0x04, true,  false, NA },
    { TRAS_MIN,                         0x15,   0x02,   0x0F,   0x00, false, false, NA },
    { TFAW_MIN,                         0x1c,   0x02,   0x0F,   0x00, false, false, NA },
    { SDRAM_OPTIONAL_FEATURES,          0x1e,   0x01,   0x00,   0x00, false, false, NA },
    { SDRAM_THERMAL_REFRESH_OPTIONS,    0x1f,   0x01,   0x00,   0x00, false, false, NA },
    { MODULE_THERMAL_SENSOR,            0x20,   0x01,   0x00,   0x00, false, false, NA },
    { THERMAL_SENSOR_PRESENT,           0x20,   0x01,   0x80,   0x07, false, false, NA },
    { THERMAL_SENSOR_ACCURACY,          0x20,   0x01,   0x7F,   0x00, false, false, NA },
    { SDRAM_DEVICE_TYPE,                0x21,   0x01,   0x80,   0x07, false, false, NA },
    { SDRAM_DIE_COUNT,                  0x21,   0x01,   0x70,   0x04, false, false, NA },
    { SDRAM_DEVICE_TYPE_SIGNAL_LOADING, 0x21,   0x01,   0x03,   0x00, false, false, NA },
    { TCKMIN_FINE_OFFSET,               0x22,   0x01,   0x00,   0x00, false, false, NA },
    { TAAMIN_FINE_OFFSET,               0x23,   0x01,   0x00,   0x00, false, false, NA },
    { TRCDMIN_FINE_OFFSET,              0x24,   0x01,   0x00,   0x00, false, false, NA },
    { TRPMIN_FINE_OFFSET,               0x25,   0x01,   0x00,   0x00, false, false, NA },
    { TRCMIN_FINE_OFFSET,               0x26,   0x01,   0x00,   0x00, false, false, NA },
    { MODULE_TYPE_SPECIFIC_SECTION,     0x3c,   0x39,   0x00,   0x00, false, false, NA },
    { MODULE_MANUFACTURER_ID,           0x76,   0x02,   0x00,   0x00, true,  false, NA },
    { MODULE_MANUFACTURING_LOCATION,    0x77,   0x01,   0x00,   0x00, false, false, NA },
    { MODULE_MANUFACTURING_DATE,        0x78,   0x02,   0x00,   0x00, false, false, NA },
    { MODULE_SERIAL_NUMBER,             0x7a,   0x04,   0x00,   0x00, false, false, NA },
    { MODULE_PART_NUMBER,               0x80,   0x12,   0x00,   0x00, false, false, NA },
    { DRAM_MANUFACTURER_ID,             0x95,   0x02,   0x00,   0x00, true,  false, NA },
    { MANUFACTURER_SPECIFIC_DATA,       0x96,   0x1a,   0x00,   0x00, false, false, NA },
    { DIMM_BAD_DQ_DATA,                 0xb0,   0x50,   0x00,   0x00, false, true,  NA },
    // Normal fields supported on DDR3 only
    { BANK_ADDRESS_BITS,                0x04,   0x01,   0x70,   0x04, false, false, NA },
    { MODULE_NOMINAL_VOLTAGE,           0x06,   0x01,   0x07,   0x00, false, false, NA },
    { FTB_DIVIDEND,                     0x09,   0x01,   0xF0,   0x04, false, false, NA },
    { FTB_DIVISOR,                      0x09,   0x01,   0x0F,   0x00, false, false, NA },
    { MTB_DIVIDEND,                     0x0a,   0x01,   0x00,   0x00, false, false, NA },
    { MTB_DIVISOR,                      0x0b,   0x01,   0x00,   0x00, false, false, NA },
    { CAS_LATENCIES_SUPPORTED,          0x0f,   0x02,   0x7F,   0x00, true,  false, NA },
    { TWR_MIN,                          0x11,   0x01,   0x00,   0x00, false, false, NA },
    { TRRD_MIN,                         0x13,   0x01,   0x00,   0x00, false, false, NA },
    { TRFC_MIN,                         0x19,   0x02,   0x00,   0x00, true,  false, NA },
    { TWTR_MIN,                         0x1a,   0x01,   0x00,   0x00, false, false, NA },
    { TRTP_MIN,                         0x1b,   0x01,   0x00,   0x00, false, false, NA },
    { DLL_OFF,                          0x1e,   0x01,   0x80,   0x07, false, false, NA },
    { RZQ_7,                            0x1e,   0x01,   0x02,   0x01, false, false, NA },
    { RZQ_6,                            0x1e,   0x01,   0x01,   0x00, false, false, NA },
    { PASR,                             0x1f,   0x01,   0x80,   0x07, false, false, NA },
    { ODTS,                             0x1f,   0x01,   0x08,   0x03, false, false, NA },
    { ASR,                              0x1f,   0x01,   0x04,   0x02, false, false, NA },
    { ETR_1X,                           0x1f,   0x01,   0x02,   0x01, false, false, NA },
    { ETR,                              0x1f,   0x01,   0x01,   0x00, false, false, NA },
    { MODULE_CRC,                       0x7f,   0x02,   0x00,   0x00, true,  false, NA },
    { MODULE_REVISION_CODE,             0x93,   0x02,   0x00,   0x00, true,  false, NA },
    // Module Specific fields supported on both DDR3 and DDR4
    { MODSPEC_COM_NOM_HEIGHT_MAX,       0x3c,   0x01,   0x1f,   0x00, false, false, ALL },
    { MODSPEC_COM_MAX_THICK_BACK,       0x3d,   0x01,   0xf0,   0x04, false, false, ALL },
    { MODSPEC_COM_MAX_THICK_FRONT,      0x3d,   0x01,   0x0f,   0x00, false, false, ALL },
    { MODSPEC_COM_REF_RAW_CARD_EXT,     0x3e,   0x01,   0x80,   0x07, false, false, ALL },
    { MODSPEC_COM_REF_RAW_CARD_REV,     0x3e,   0x01,   0x60,   0x05, false, false, ALL },
    { MODSPEC_COM_REF_RAW_CARD,         0x3e,   0x01,   0x1f,   0x00, false, false, ALL },
    { UMM_ADDR_MAPPING,                 0x3f,   0x01,   0x01,   0x00, false, false, UMM },
    { RMM_ROWS_RDIMM,                   0x3f,   0x01,   0x0c,   0x02, false, false, RMM },
    { RMM_REGS_RDIMM,                   0x3f,   0x01,   0x03,   0x00, false, false, RMM },
    { RMM_HEAT_SP,                      0x40,   0x01,   0x80,   0x07, false, false, RMM },
    { RMM_HEAT_SP_CHARS,                0x40,   0x01,   0x7F,   0x00, false, false, RMM },
    { RMM_MFR_ID_CODE,                  0x42,   0x02,   0x00,   0x00, true,  false, RMM },
    { RMM_REG_REV_NUM,                  0x43,   0x01,   0x00,   0x00, false, false, RMM },
    { LRMM_HEAT_SP,                     0x3f,   0x01,   0x80,   0x07, false, false, LRMM },
    { LRMM_NUM_ROWS,                    0x3f,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_MIRRORING,                   0x3f,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_REVISION_NUM,                0x40,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_MFR_ID_CODE,                 0x42,   0x02,   0x00,   0x00, true,  false, LRMM },
    // Module Specific fields supported on DDR3 only
    { RMM_REG_TYPE,                     0x44,   0x01,   0x07,   0x00, false, false, RMM },
    { RMM_RC1,                          0x45,   0x01,   0xf0,   0x04, false, false, RMM },
    { RMM_RC0,                          0x45,   0x01,   0x0f,   0x00, false, false, RMM },
    { RMM_RC3,                          0x46,   0x01,   0xf0,   0x04, false, false, RMM },
    { RMM_RC2,                          0x46,   0x01,   0x0f,   0x00, false, false, RMM },
    { RMM_RC5,                          0x47,   0x01,   0xf0,   0x04, false, false, RMM },
    { RMM_RC4,                          0x47,   0x01,   0x0f,   0x00, false, false, RMM },
    { RMM_RC7,                          0x48,   0x01,   0xf0,   0x04, false, false, RMM },
    { RMM_RC6,                          0x48,   0x01,   0x0f,   0x00, false, false, RMM },
    { RMM_RC9,                          0x49,   0x01,   0xf0,   0x04, false, false, RMM },
    { RMM_RC8,                          0x49,   0x01,   0x0f,   0x00, false, false, RMM },
    { RMM_RC11,                         0x4a,   0x01,   0xf0,   0x04, false, false, RMM },
    { RMM_RC10,                         0x4a,   0x01,   0x0f,   0x00, false, false, RMM },
    { RMM_RC13,                         0x4b,   0x01,   0xf0,   0x04, false, false, RMM },
    { RMM_RC12,                         0x4b,   0x01,   0x0f,   0x00, false, false, RMM },
    { RMM_RC15,                         0x4c,   0x01,   0xf0,   0x04, false, false, RMM },
    { RMM_RC14,                         0x4c,   0x01,   0x0f,   0x00, false, false, RMM },
    { LRMM_RANK_NUMBERING,              0x3f,   0x01,   0x20,   0x05, false, false, LRMM },
    { LRMM_MEMBUF_ORIEN,                0x3f,   0x01,   0x10,   0x04, false, false, LRMM },
    { LRMM_F0RC3_F0RC2,                 0x43,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F0RC3,                       0x43,   0x01,   0xf0,   0x04, false, false, LRMM },
    { LRMM_F0RC2,                       0x43,   0x01,   0x0f,   0x00, false, false, LRMM },
    { LRMM_F0RC5_F0RC4,                 0x44,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F0RC5,                       0x44,   0x01,   0xf0,   0x04, false, false, LRMM },
    { LRMM_F0RC4,                       0x44,   0x01,   0x0f,   0x00, false, false, LRMM },
    { LRMM_F1RC11_F1RC8,                0x45,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F1RC11,                      0x45,   0x01,   0xf0,   0x04, false, false, LRMM },
    { LRMM_F1RC8,                       0x45,   0x01,   0x0f,   0x00, false, false, LRMM },
    { LRMM_F1RC13_F1RC12,               0x46,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F1RC13,                      0x46,   0x01,   0xf0,   0x04, false, false, LRMM },
    { LRMM_F1RC12,                      0x46,   0x01,   0x0f,   0x00, false, false, LRMM },
    { LRMM_F1RC15_F1RC14,               0x47,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F1RC15,                      0x47,   0x01,   0xf0,   0x04, false, false, LRMM },
    { LRMM_F1RC14,                      0x47,   0x01,   0x0f,   0x00, false, false, LRMM },
    { LRMM_F3RC9_F3RC8_800_1066,        0x48,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F3RC9_800_1600,              0x48,   0x01,   0xf0,   0x04, false, false, LRMM },
    { LRMM_F3RC8_800_1600,              0x48,   0x01,   0x0f,   0x00, false, false, LRMM },
    { LRMM_F34RC11_F34RC10_800_1066,    0x49,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F4RC11_800_1600,             0x49,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_F3RC11_800_1600,             0x49,   0x01,   0x30,   0x04, false, false, LRMM },
    { LRMM_F4RC10_800_1600,             0x49,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_F3RC10_800_1600,             0x49,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_F56RC11_F56RC10_800_1066,    0x4a,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F6RC11_800_1600,             0x4a,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_F5RC11_800_1600,             0x4a,   0x01,   0x30,   0x04, false, false, LRMM },
    { LRMM_F6RC10_800_1600,             0x4a,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_F5RC10_800_1600,             0x4a,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_F78RC11_F78RC10_800_1066,    0x4b,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F8RC11_800_1600,             0x4b,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_F7RC11_800_1600,             0x4b,   0x01,   0x30,   0x04, false, false, LRMM },
    { LRMM_F8RC10_800_1600,             0x4b,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_F7RC10_800_1600,             0x4b,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_F910RC11_F910RC10_800_1066,  0x4c,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F10RC11_800_1600,            0x4c,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_F9RC11_800_1600,             0x4c,   0x01,   0x30,   0x04, false, false, LRMM },
    { LRMM_F10RC10_800_1600,            0x4c,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_F9RC10_800_1600,             0x4c,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_MR12_800_1066,               0x4d,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_RTT_WR_800_1600,             0x4d,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_RTT_NOM_800_1600,            0x4d,   0x01,   0x1c,   0x02, false, false, LRMM },
    { LRMM_IMPEDANCE_800_1600,          0x4d,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_F3RC9_F3RC8_1333_1600,       0x4e,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F3RC9_1333_1600,             0x4e,   0x01,   0xF0,   0x04, false, false, LRMM },
    { LRMM_F3RC8_1333_1600,             0x4e,   0x01,   0x0F,   0x00, false, false, LRMM },
    { LRMM_F34RC11_F34RC10_1333_1600,   0x4f,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F4RC11_1333_1600,            0x4f,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_F3RC11_1333_1600,            0x4f,   0x01,   0x30,   0x04, false, false, LRMM },
    { LRMM_F4RC10_1333_1600,            0x4f,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_F3RC10_1333_1600,            0x4f,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_F56RC11_F56RC10_1333_1600,   0x50,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F6RC11_1333_1600,            0x50,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_F5RC11_1333_1600,            0x50,   0x01,   0x30,   0x04, false, false, LRMM },
    { LRMM_F6RC10_1333_1600,            0x50,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_F5RC10_1333_1600,            0x50,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_F78RC11_F78RC10_1333_1600,   0x51,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F8RC11_1333_1600,            0x51,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_F7RC11_1333_1600,            0x51,   0x01,   0x30,   0x04, false, false, LRMM },
    { LRMM_F8RC10_1333_1600,            0x51,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_F7RC10_1333_1600,            0x51,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_F910RC11_F910RC10_1333_1600, 0x52,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F10RC11_1333_1600,           0x52,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_F9RC11_1333_1600,            0x52,   0x01,   0x30,   0x04, false, false, LRMM },
    { LRMM_F10RC10_1333_1600,           0x52,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_F9RC10_1333_1600,            0x52,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_MR12_1333_1600,              0x53,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_RTT_WR_1333_1600,            0x53,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_RTT_NOM_1333_1600,           0x53,   0x01,   0x1c,   0x02, false, false, LRMM },
    { LRMM_IMPEDANCE_1333_1600,         0x53,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_F3RC9_F3RC8_1866_2133,       0x54,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F3RC9_1866_2133,             0x54,   0x01,   0xf0,   0x04, false, false, LRMM },
    { LRMM_F3RC8_1866_2133,             0x54,   0x01,   0x0f,   0x00, false, false, LRMM },
    { LRMM_F34RC11_F34RC10_1866_2133,   0x55,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F4RC11_1866_2133,            0x55,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_F3RC11_1866_2133,            0x55,   0x01,   0x30,   0x04, false, false, LRMM },
    { LRMM_F4RC10_1866_2133,            0x55,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_F3RC10_1866_2133,            0x55,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_F56RC11_F56RC10_1866_2133,   0x56,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F6RC11_1866_2133,            0x56,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_F5RC11_1866_2133,            0x56,   0x01,   0x30,   0x04, false, false, LRMM },
    { LRMM_F6RC10_1866_2133,            0x56,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_F5RC10_1866_2133,            0x56,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_F78RC11_F78RC10_1866_2133,   0x57,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F8RC11_1866_2133,            0x57,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_F7RC11_1866_2133,            0x57,   0x01,   0x30,   0x04, false, false, LRMM },
    { LRMM_F8RC10_1866_2133,            0x57,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_F7RC10_1866_2133,            0x57,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_F910RC11_F910RC10_1866_2133, 0x58,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_F10RC11_1866_2133,           0x58,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_F9RC11_1866_2133,            0x58,   0x01,   0x30,   0x04, false, false, LRMM },
    { LRMM_F10RC10_1866_2133,           0x58,   0x01,   0x0c,   0x02, false, false, LRMM },
    { LRMM_F9RC10_1866_2133,            0x58,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_MR12_FOR_1866_2133,          0x59,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_RTT_WR_1866_2133,            0x59,   0x01,   0xc0,   0x06, false, false, LRMM },
    { LRMM_RTT_NOM_1866_2133,           0x59,   0x01,   0x1c,   0x02, false, false, LRMM },
    { LRMM_IMPEDANCE_1866_2133,         0x59,   0x01,   0x03,   0x00, false, false, LRMM },
    { LRMM_MIN_DELAY_150V,              0x5a,   0x01,   0x7f,   0x00, false, false, LRMM },
    { LRMM_MAX_DELAY_150V,              0x5b,   0x01,   0x7f,   0x00, false, false, LRMM },
    { LRMM_MIN_DELAY_135V,              0x5c,   0x01,   0x7f,   0x00, false, false, LRMM },
    { LRMM_MAX_DELAY_135V,              0x5d,   0x01,   0x7f,   0x00, false, false, LRMM },
    { LRMM_MIN_DELAY_125V,              0x5e,   0x01,   0x7f,   0x00, false, false, LRMM },
    { LRMM_MAX_DELAY_125V,              0x5f,   0x01,   0x7f,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE0,           0x66,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE1,           0x67,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE2,           0x68,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE3,           0x69,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE4,           0x6a,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE5,           0x6b,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE6,           0x6c,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE7,           0x6d,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE8,           0x6e,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE9,           0x6f,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE10,          0x70,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE11,          0x71,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE12,          0x72,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE13,          0x73,   0x01,   0x00,   0x00, false, false, LRMM },
    { LRMM_PERSONALITY_BYTE14,          0x74,   0x01,   0x00,   0x00, false, false, LRMM },
    { ENTIRE_SPD,                       0x00,  0x100,   0x00,   0x00, false, false,  ALL },
    //---------------------------------------------------------------------------------------
};


}; // end SPD namespace

#endif  // __SPDDDR3_H
