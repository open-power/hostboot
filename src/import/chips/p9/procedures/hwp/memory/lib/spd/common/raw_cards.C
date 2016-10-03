/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/common/raw_cards.C $ */
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
#include <lib/spd/common/raw_cards.H>

namespace mss
{
namespace rcd01
{

enum raw_card_rev : uint8_t
{
    // TODO RTC:160116 Fill in valid RCD data for LRDIMM
    B0 = 0x01,

    // RDIMM power-on
    C1 = 0x22,

    // TK - Change to 0xFF -  AAM
    // In the spec hex XF (where X - don't care)
    // means no JEDEC reference raw card design used.
    // We will want to redefine it to be VBU reference raw card
    // since it is unlikely we will use a DIMM w/o a
    // reference caw card design.
    VBU = 0x23,
};

///
/// @brief raw card B0 settings
///
// TODO RTC:160116 Fill in valid RCD data for LRDIMM
raw_card_t raw_card_b0( 0x00,
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
                        0x07);

///
/// @brief raw card C1 settings
///
raw_card_t raw_card_c1( 0x00,
                        0x0B,
                        0x00,
                        0x0F,
                        0x03,
                        0x0F,
                        0x0E,
                        0x00,
                        0x0D,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x07);

///
/// @brief raw card VBU settings
///
raw_card_t raw_card_vbu( 0x00,
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
                         0x07);


// TODO - RTC:160121 Catch all for adding raw card data for DIMMs
// Not sure if we can have the same raw card revision for rcd01 and rcd02,
// if not, then we can move this vector outside of the rcd01 namespace.
const std::vector< std::pair< uint8_t , rcd01::raw_card_t> > RAW_CARDS =
{
    {raw_card_rev::B0, rcd01::raw_card_b0},
    {raw_card_rev::C1, rcd01::raw_card_c1},
    {raw_card_rev::VBU, rcd01::raw_card_vbu},
};

}// rcd01
}// mss
