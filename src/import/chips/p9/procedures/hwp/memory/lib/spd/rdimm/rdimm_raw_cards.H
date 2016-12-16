/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/rdimm/rdimm_raw_cards.H $ */
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
/// @file raw_cards.H
/// @brief Raw card data structure
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_RDIMM_RAW_CARDS_H_
#define _MSS_RDIMM_RAW_CARDS_H_

#include <fapi2.H>
#include <cstdint>
#include <vector>
#include <lib/spd/common/rcw_settings.H>

namespace mss
{
namespace rdimm
{

// In the order of the vector below which needs to be sorted by enum value
enum raw_card_rev : uint8_t
{
    A1 = 0x20,

    // RDIMM power-on
    C1 = 0x22,

    // TK - Change to 0xFF -  AAM
    // In the spec hex XF (where X - don't care)
    // means no JEDEC reference raw card design used.
    // We will want to redefine it to be VBU reference raw card
    // since it is unlikely we will use a DIMM w/o a
    // reference caw card design.
    VBU = 0x23,

    C2 = 0x42,
};

// Raw cards can share the same raw card # between RDIMM and LRDIMMs so
// we track them independently. Since all of these don't come from SPD for DDR4,
// we have to set some RCWs (we want limit these and derive as many as possible)
extern const std::vector< std::pair< uint8_t, rcw_settings> > RAW_CARDS;

}// rdimm

// Exposed so we can test them.
extern rcw_settings rdimm_rc_c1;
extern rcw_settings rdimm_rc_c2;
extern rcw_settings rdimm_rc_a1;
extern rcw_settings rdimm_rc_vbu;

}// mss

#endif //_MSS_RDIMM_RAW_CARDS_H_
