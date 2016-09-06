/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/rdimm/raw_cards.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file raw_cards.C
/// @brief Raw card data structure
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

// std lib
#include <vector>

// fapi2
#include <fapi2.H>

// mss lib
#include <lib/spd/rdimm/raw_cards.H>

namespace mss
{

enum raw_card_rev : uint8_t
{
    C1 = 0x22,

    // In the spec hex XF (where X - don't care)
    // means no JEDEC reference raw card design used.
    // We will want to redefine it to be VBU reference raw card
    // since it is unlikely we will use a DIMM w/o a
    // reference caw card design.

    // TODO RTC:159662 Fill in valid RCD data for power on
    VBU = 0x23,
};

// RDIMM raw card C1
// TODO RTC:159662 Fill in valid RCD data for power on
//
// The following parameters need a valid setting:
//
// RC0E - Parity, NV Mode Enable, and ALERT Configuration Control Word - TK ADD - AAM
// RC0F - Command Latency Adder Control Word - TK ADD - AAM
// RC1x - Internal VrefCA Control Word - TK ADD - AAM
// RC2x - I2C Bus Control Words - TK ADD - AAM
// RC4x - CW Selection Control Words - TK ADD - AAM
// RC5x: CW Destination Selection & Write/Read Additional QxODT[1:0] Signal High - TK ADD - AAM
// RC6x: CW Data Control Word - TK ADD - AAM ,
// RC7x: IBT Control Word - TK ADD - AAM
// RC8x: ODT Input Buffer/IBT, QxODT Output Buffer and Timing Control Word - TK ADD - AAM
// RC9x: QxODT[1:0] Write Pattern Control Word - TK ADD - AAM
// RCAx: QxODT[1:0] Read Pattern Control Word - TK ADD - AAM
// RCBx: IBT and MRS Snoop Control Word - - TK ADD - AAM
///
/// @brief raw card C1 settings
///
raw_card_t raw_card_c1( 0x00,
                        0x0B,
                        0x00,
                        0x0F,
                        0x00,
                        0x0E,
                        0x0E,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00);

///
/// @brief raw card VBU settings
///
raw_card_t raw_card_vbu(0x00,
                        0x00,
                        0x00,
                        0x0F,
                        0x03,
                        0x00,
                        0x0E,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x07 );

// TODO - RTC:160121 Catch all for adding raw card data for DIMMs
const std::vector< std::pair< uint8_t , raw_card_t> > RDIMM_RAW_CARDS =
{
    {raw_card_rev::C1, raw_card_c1},
    {raw_card_rev::VBU, raw_card_vbu},
};

}// mss
