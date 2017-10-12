/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/lrdimm/ddr4/lrdimm_raw_cards.C $ */
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
/// @brief LRDIMM raw card data structure
/// Contains RCW settings per raw card rev
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

// std lib
#include <vector>

// fapi2
#include <fapi2.H>

// mss lib
#include <generic/memory/lib/spd/lrdimm/ddr4/lrdimm_raw_cards.H>

namespace mss
{

///
/// @brief raw card B0 settings
///
// TODO RTC:160116 Fill in valid RCD data for LRDIMM
rcw_settings lrdimm_rc_b0( 0x00, // RC00
                           0x00); // RC01

rcw_settings lrdimm_rc_default( 0x00, // RC00
                                0x00); // RC01


namespace lrdimm
{

// TODO - RTC:160121 Catch all for adding raw card data for DIMMs
const std::vector< std::pair< uint8_t , rcw_settings> > RAW_CARDS =
{
    // I expect this to grow as Warren M. expects us to have
    // settings for every raw card that JEDEC puts out.  Openpower
    // can't break due to a missing raw card...
    {raw_card_rev::B0, lrdimm_rc_b0},
};

}// lrdimm
}// mss
