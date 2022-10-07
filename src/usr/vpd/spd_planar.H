/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/spd_planar.H $                                    */
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
#ifndef __SPD_PLANAR
#define __SPD_PLANAR

/**
 * @file spd_planar.H
 *
 * @brief Provides the planar EEPROM field information for OCMB chip SPD
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include "spd.H"

namespace SPD
{

/**
 * @brief Pre-defined lookup table for planar Eeprom keywords and the
 *        information needed to read that data from the SPD data.
 */
const KeywordData planarEepromData[] =
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
    //
    // Normal fields supported on both DDR3 and DDR4
    { SPD_BYTES_TOTAL,                  0x00,   0x01,   0x70,   0x04, false, false, ALL },
    { SPD_BYTES_USED,                   0x00,   0x01,   0x0F,   0x00, false, false, ALL },
    { SPD_MAJOR_REVISION,               0x01,   0x01,   0xF0,   0x04, false, false, ALL },
    { SPD_MINOR_REVISION,               0x01,   0x01,   0x0F,   0x00, false, false, ALL },
    { BASIC_MEMORY_TYPE,                0x02,   0x01,   0x00,   0x00, false, false, ALL },
    { CUSTOM,                           0x03,   0x01,   0x80,   0x07, false, false, ALL },
    { MODULE_TYPE,                      0x03,   0x01,   0x0F,   0x00, false, false, ALL },

    // Note - All data below 128 is common across all DDR4 DIMMs, except DDIMM
    { MODULE_MANUFACTURER_ID,           0x200,  0x02,   0x00,   0x00, true,  false, ALL },
    { MODULE_SERIAL_NUMBER,             0x205,  0x04,   0x00,   0x00, false, false, ALL },
    { MODULE_PART_NUMBER,               0x209,  0x1E,   0x00,   0x00, false, false, ALL },
    { MODULE_REVISION_CODE,             0x277,  0x01,   0x00,   0x00, false, false, ALL },

    // 11S starts at byte 416 (0x1A0,) 22 bytes plus 4 for the CCIN
    // "11Spppppppsssssssssssscccc"
    { IBM_11S_PN,                       0x1a3,  0x07,   0x00,   0x00, false, false, ALL },
    { IBM_11S_SN,                       0x1aa,  0x0c,   0x00,   0x00, false, false, ALL },
    { IBM_11S_CC,                       0x1b6,  0x04,   0x00,   0x00, false, false, ALL },
    { EXPLORER_FW_VERSION,              0x3c0,  0x40,   0x00,   0x00, false, true,  ALL },
    { SAFE_PARK_ZONE,                   0x800,  0x01,   0x00,   0x00, false, false, ALL },

    // Module Specific fields supported on DDR4 only
    { ENTIRE_SPD_WITHOUT_EFD,           0x00,  0x0280,  0x00,   0x00, false, false, ALL },
    { ENTIRE_SPD,                       0x00,  0x1000,  0x00,   0x00, false, false, ALL },
    //---------------------------------------------------------------------------------------
};

}; // end SPD namespace

#endif  // __SPD_PLANAR
