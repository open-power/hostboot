/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_resclk_defines.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file   p9_resclk_defines.H
/// @brief  Defines Resonant Clocking default values (provided by clock team).
///
// *HWP HWP Owner:
// *HWP FW Owner:
// *HWP Team:           PM
// *HWP Level:
// *HWP Consumed by:

#ifndef __P9_RESCLK_DEFINES_H__
#define __P9_RESCLK_DEFINES_H__

#include <vector>

namespace p9_resclk_defines
{
typedef struct
{
    uint16_t freq;
    uint8_t  idx;
} rsclk_freq_idx_t;
//###############################################################################
// Table 1: Resonant Clocking Control Index
// consists of 8 entries consisting of a comma-delimited pair.
// Freq(in Mhz), Index(decimal number between 0 & 63, index into the next table)
// The first entry is always 0 Mhz. Entries are in ascending order of frequency.
// Algorithm will search starting at the bottom of the index until it
// finds the first entry at or below target frequency, then walk to that index.
//###############################################################################
std::vector<rsclk_freq_idx_t> const RESCLK_INDEX_VEC =
{
    //  { Freq, Idx}
    {    0,  3 },
    { 1500,  3 },
    { 2000, 24 },
    { 2800, 48 },
    { 3400, 41 },
    { 3700, 41 },
    { 3900, 41 },
    { 4100, 41 }
};
//###############################################################################
// Table 2: Resonant (Core & L2) Grids Control Data
// 64 entries,each entry a 16-bit hex value.
// First row corresponds to Index 0 from Table 1.  Last row is Index 63.
// Left aligned hex value corresponding to the first 13-bits of the QACCR register
// 0:3 SB_STRENGTH; 4 SB_SPARE; 6:7 SB_PULSE_MODE; 8:11 SW_RESCLK; 12 SW_SPARE
//###############################################################################
std::vector<uint16_t> const RESCLK_TABLE_VEC =
{
    0x2000,
    0x3000,
    0x1000,
    0x0000,
    0x0010,
    0x0030,
    0x0020,
    0x0060,
    0x0070,
    0x0050,
    0x0040,
    0x00C0,
    0x00D0,
    0x00F0,
    0x00E0,
    0x00A0,
    0x00B0,
    0x0090,
    0x0080,
    0x8080,
    0x9080,
    0xB080,
    0xA080,
    0xE080,
    0xF080,
    0xE080,
    0xA080,
    0xB080,
    0x9080,
    0x8080,
    0x0080,
    0x0480,
    0x8480,
    0x9480,
    0xB480,
    0x9480,
    0x8480,
    0x0480,
    0x0580,
    0x8580,
    0x9580,
    0xB580,
    0x9580,
    0x8580,
    0x0580,
    0x0780,
    0x8780,
    0x9780,
    0xB780,
    0x9780,
    0x8780,
    0x0780,
    0x0680,
    0x8680,
    0x9680,
    0xB680,
    0xA680,
    0xE680,
    0xF680,
    0xD680,
    0xC680,
    0xC680,
    0xC680,
    0xC680
};
//###############################################################################
// Table 3: L3 Grid Control Data
// 4 entries, each a 8-bit hex value to transition between two modes
// Entry 0 is the "Full Power" setting
// Entry 3 is the "Low  Power" setting, for use above voltages defined by
// L3_VOLTAGE_THRESHOLD_MV (ATTR_SYSTEM_RESCLK_L3_VOLTAGE_THRESHOLD_MV)
// Hex value corresponding to L3 control bits in the QACCR(16:23)
// 0:3 SB_STRENGTH;       (Not supported: 4 SB_SPARE; 5:7 SB_PULSE_MODE)
//###############################################################################
std::vector<uint8_t> const L3CLK_TABLE_VEC
{
    0,
    1,
    3,
    2
};
//###############################################################################
// L3 Voltage Threshold (millivolts)
//###############################################################################
uint16_t const L3_VOLTAGE_THRESHOLD_MV = 580;
}

#endif //__P9_RESCLK_DEFINES_H__

