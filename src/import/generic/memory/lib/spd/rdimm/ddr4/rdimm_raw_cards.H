/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/rdimm/ddr4/rdimm_raw_cards.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_RDIMM_RAW_CARDS_H_
#define _MSS_RDIMM_RAW_CARDS_H_

#include <fapi2.H>
#include <cstdint>
#include <vector>
#include <generic/memory/lib/spd/common/rcw_settings.H>

namespace mss
{
namespace rdimm
{

///
/// @brief raw card encoding as per SPD
/// @note In the order of the vector below which needs to be sorted by enum value
///
enum raw_card_rev : uint8_t
{

    // TODO:RTC178807 - Update how NVDIMMs are handled once more are up and running in the lab
    // NVDIMM's have the same RC value as custom DIMMs, but are defined by SPD byte 03 differently
    NVDIMM = 0x1F,

    A1 = 0x20,
    B1 = 0x21,
    // RDIMM power-on
    C1 = 0x22,

    // TK - Change VBU value to a no-op value or a value that will never be reached -JLH
    VBU = 0x23,

    A2 = 0x40,
    B2 = 0x41,
    C2 = 0x42,

    B3 = 0x61,
    C3 = 0x62,

    // Default settings used for DIMMs that do not use a JEDEC raw card reference
    CUSTOM = 0xFF,
};

// Raw cards can share the same raw card # between RDIMM and LRDIMMs so
// we track them independently. Since all of these don't come from SPD for DDR4,
// we have to set some RCWs (we want limit these and derive as many as possible)
extern const std::vector< std::pair< uint8_t, rcw_settings> > RAW_CARDS;

}// rdimm

// Exposed so we can test them.
// Alphabetized list below
extern rcw_settings rdimm_rc_a1;
extern rcw_settings rdimm_rc_a2;
extern rcw_settings rdimm_rc_b1;
extern rcw_settings rdimm_rc_b2;
extern rcw_settings rdimm_rc_b3;
extern rcw_settings rdimm_rc_c1;
extern rcw_settings rdimm_rc_c2;
extern rcw_settings rdimm_rc_c3;
extern rcw_settings rdimm_rc_custom;
extern rcw_settings rdimm_rc_nvdimm;
extern rcw_settings rdimm_rc_vbu;
extern rcw_settings rdimm_rc_default;

}// mss

#endif //_MSS_RDIMM_RAW_CARDS_H_
