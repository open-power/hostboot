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

///
/// @brief raw card B0 settings
///
// TODO RTC:160116 Fill in valid RCD data for LRDIMM
raw_card_t raw_card_b0( 0x00, // RC00
                        0x00, // RC01 (C might be the right answer)
                        0x00, // RC02
                        0x0F, // RC06_7
                        0x03, // RC08
                        0x00, // RC09
                        0x0E, // RC0B
                        0x00, // RC0C
                        0x00, // RC0E
                        0x00, // RC0F
                        0x00, // RC1X
                        0x00, // RC2X
                        0x00, // RC4X
                        0x00, // RC5X
                        0x00, // RC6C
                        0x00, // RC8X
                        0x00, // RC9X
                        0x00, // RCAx
                        0x07);// RCBX

///
/// @brief raw card C1 settings
///
raw_card_t raw_card_c1( 0x00, // RC00
                        0x00, // RC01 (C might be the right answer?)
                        0x00, // RC02
                        0x0F, // RC06_07
                        0x03, // RC08
                        0x00, // RC09
                        0x0E, // RC0B
                        0x00, // RC0C
                        0x0D, // RC0E
                        0x00, // RC0F
                        0x00, // RC1X
                        0x00, // RC2X
                        0x00, // RC4X
                        0x00, // RC5X
                        0x00, // RC6X
                        0x00, // RC8X
                        0x00, // RC9X
                        0x00, // RCAX
                        0x07);// RCBX

///
/// @brief raw card A1 settings
///
raw_card_t raw_card_a1( 0x00, // RC00
                        0x00, // RC01 (C might be the right answer?)
                        0x00, // RC02
                        0x0F, // RC06_07
                        0x03, // RC08
                        0x00, // RC09
                        0x0E, // RC0B
                        0x00, // RC0C
                        0x0D, // RC0E
                        0x00, // RC0F
                        0x00, // RC1X
                        0x00, // RC2X
                        0x00, // RC4X
                        0x00, // RC5X
                        0x00, // RC6X
                        0x00, // RC8X
                        0x00, // RC9X
                        0x00, // RCAX
                        0x07);// RCBX

///
/// @brief raw card VBU settings
///
raw_card_t raw_card_vbu( 0x00, // RC00
                         0x00, // RC01
                         0x00, // RC02
                         0x0F, // RC06_07
                         0x03, // RC08
                         0x00, // RC09
                         0x0E, // RC0B
                         0x00, // RC0C
                         0x00, // RC0E
                         0x00, // RC0F
                         0x00, // RC1X
                         0x00, // RC2X
                         0x00, // RC4X
                         0x00, // RC5X
                         0x00, // RC6X
                         0x00, // RC8X
                         0x00, // RC9X
                         0x00, // RCAX
                         0x07);// RCBX


// TODO - RTC:160121 Catch all for adding raw card data for DIMMs
// Not sure if we can have the same raw card revision for rcd01 and rcd02,
// if not, then we can move this vector outside of the rcd01 namespace.
//
// !! WARNING: THIS VECTOR MUST BE SORTED BY ENUM VALUE!!
//
const std::vector< std::pair< uint8_t , rcd01::raw_card_t> > RAW_CARDS =
{
    {raw_card_rev::B0, rcd01::raw_card_b0},
    {raw_card_rev::A1, rcd01::raw_card_a1},
    {raw_card_rev::C1, rcd01::raw_card_c1},
    {raw_card_rev::VBU, rcd01::raw_card_vbu},
};

}// rcd01
}// mss
