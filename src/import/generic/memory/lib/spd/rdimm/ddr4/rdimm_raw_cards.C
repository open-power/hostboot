/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/rdimm/ddr4/rdimm_raw_cards.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @brief RDIMM raw card data structure
/// Contains RCW settings per raw card rev
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
#include <generic/memory/lib/spd/rdimm/ddr4/rdimm_raw_cards.H>

namespace mss
{

///
/// @brief raw card C1 settings
///
rcw_settings rdimm_rc_c1( 0x02, // RC00
                          0x0C, // RC01
                          0x0F, // RC06_07
                          0x0C, // RC09
                          0x0E, // RC0B
                          0x00, // RC0C
                          0x00, // RC0F
                          0x00, // RC1X
                          0x00, // RC2X
                          0x00, // RC4X
                          0x00, // RC5X
                          0x00, // RC6X
                          0x00, // RC8X
                          0x00, // RC9X
                          0x00); // RCAX

///
/// @brief raw card C2 settings
/// @note same settings as C1
///
rcw_settings rdimm_rc_c2( 0x02, // RC00
                          0x0C, // RC01
                          0x0F, // RC06_07
                          0x0C, // RC09
                          0x0E, // RC0B
                          0x00, // RC0C
                          0x00, // RC0F
                          0x00, // RC1X
                          0x00, // RC2X
                          0x00, // RC4X
                          0x00, // RC5X
                          0x00, // RC6X
                          0x00, // RC8X
                          0x00, // RC9X
                          0x00); // RCAX

///
/// @brief raw card A1 settings
///
rcw_settings  rdimm_rc_a1( 0x02, // RC00
                           0x00, // RC01
                           0x0F, // RC06_07
                           0x0C, // RC09
                           0x0E, // RC0B
                           0x00, // RC0C
                           0x00, // RC0F
                           0x00, // RC1X
                           0x00, // RC2X
                           0x00, // RC4X
                           0x00, // RC5X
                           0x00, // RC6X
                           0x00, // RC8X
                           0x00, // RC9X
                           0x00); // RCAX

///
/// @brief raw card B1 settings
/// @note need to verify, copy from b2, need to verify with b1 annex
///
rcw_settings rdimm_rc_b1( 0x02, // RC00
                          0x00, // RC01
                          0x0F, // RC06_07
                          0x0C, // RC09 Could be set in eff_config for CKE power DOWN mode
                          0x0E, // RC0B
                          0x00, // RC0C
                          0x00, // RC0F
                          0x00, // RC1X
                          0x00, // RC2X
                          0x00, // RC4X
                          0x00, // RC5X
                          0x00, // RC6X
                          0x00, // RC8X
                          0x00, // RC9X
                          0x00);// RCAX


///
/// @brief raw card B2 settings
///
rcw_settings rdimm_rc_b2( 0x02, // RC00
                          0x00, // RC01
                          0x0F, // RC06_07
                          0x0C, // RC09
                          0x0E, // RC0B
                          0x00, // RC0C
                          0x00, // RC0F
                          0x00, // RC1X
                          0x00, // RC2X
                          0x00, // RC4X
                          0x00, // RC5X
                          0x00, // RC6X
                          0x00, // RC8X
                          0x00, // RC9X
                          0x00);// RCAX


////
/// @brief raw card for custom dimms
///
rcw_settings rdimm_rc_custom ( 0x02, // RC00
                               0x00, // RC01
                               0x0F, // RC06_07
                               0x0C, // RC09
                               0x0E, // RC0B
                               0x00, // RC0C
                               0x00, // RC0F
                               0x00, // RC1X
                               0x00, // RC2X
                               0x00, // RC4X
                               0x00, // RC5X
                               0x00, // RC6X
                               0x00, // RC8X
                               0x00, // RC9X
                               0x00);// RCAX


///
/// @brief raw card VBU settings
///
rcw_settings rdimm_rc_vbu( 0x02, // RC00
                           0x00, // RC01
                           0x0F, // RC06_07
                           0x0C, // RC09
                           0x0E, // RC0B
                           0x00, // RC0C
                           0x00, // RC0F
                           0x00, // RC1X
                           0x00, // RC2X
                           0x00, // RC4X
                           0x00, // RC5X
                           0x00, // RC6X
                           0x00, // RC8X
                           0x00, // RC9X
                           0x00); // RCAX

namespace rdimm
{

const std::vector< std::pair< uint8_t , rcw_settings> > RAW_CARDS =
{
    // I expect this to grow as Warren M. expects us to have
    // settings for every raw card that JEDEC puts out.  Openpower
    // can't break due to a missing raw card...
    {raw_card_rev::A1, rdimm_rc_a1},
    {raw_card_rev::B1, rdimm_rc_b1},
    {raw_card_rev::C1, rdimm_rc_c1},
    {raw_card_rev::VBU, rdimm_rc_vbu},
    {raw_card_rev::B2, rdimm_rc_b2},
    {raw_card_rev::C2, rdimm_rc_c2},
    {raw_card_rev::CUSTOM, rdimm_rc_custom},
};

}// rdimm
}// mss
