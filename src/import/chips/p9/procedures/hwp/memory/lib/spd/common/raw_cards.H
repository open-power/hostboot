/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/common/raw_cards.H $ */
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

#ifndef _MSS_RAW_CARDS_H_
#define _MSS_RAW_CARDS_H_

#include <fapi2.H>
#include <cstdint>

namespace mss
{
namespace rcd01
{

// In the order of the vector below which needs to be sorted by enum value
enum raw_card_rev : uint8_t
{
    // TODO RTC:160116 Fill in valid RCD data for LRDIMM
    B0 = 0x01,

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
};

///
/// @brief raw card VBU settings
/// @note contains RCD settings for hard-coded values
/// that are not application specific.
/// Application specific settings are dervied in eff_config
struct raw_card_t
{
    uint64_t iv_rc00;
    uint64_t iv_rc01;
    uint64_t iv_rc02;
    uint64_t iv_rc06_07;
    uint64_t iv_rc08;
    uint64_t iv_rc09;
    uint64_t iv_rc0b;
    uint64_t iv_rc0c;
    uint64_t iv_rc0e;
    uint64_t iv_rc0f;
    uint64_t iv_rc1x;
    uint64_t iv_rc2x;
    uint64_t iv_rc4x;
    uint64_t iv_rc5x;
    uint64_t iv_rc6x;
    uint64_t iv_rc8x;
    uint64_t iv_rc9x;
    uint64_t iv_rcax;
    uint64_t iv_rcbx;

    ///
    /// @brief default ctor
    ///
    raw_card_t() = default;

    ///
    /// @brief Equality operator
    /// @param[in] i_rhs the right-hand side of the == operation
    /// @return true iff both raw_cards are equal
    ///
    inline bool operator==(const raw_card_t& i_rhs) const
    {
        // Betting this is faster than all the conditionals ...
        return (memcmp(this, &i_rhs, sizeof(raw_card_t)) == 0);
    }

    ///
    /// @brief ctor
    /// @param[in] i_rc00 setting for register control word (RC00)
    /// @param[in] i_rc01 setting for register control word (RC01)
    /// @param[in] i_rc02 setting for register control word (RC02)
    /// @param[in] i_rc06_07 setting for register control word (RCO6 & RC07)
    /// @param[in] i_rc08 setting for register control word (RC08)
    /// @param[in] i_rc09 setting for register control word (RC09)
    /// @param[in] i_rc0b setting for register control word (RC0B)
    /// @param[in] i_rc0c setting for register control word (RC0C)
    /// @param[in] i_rc0e setting for register control word (RC0E)
    /// @param[in] i_rc0f setting for register control word (RC0F)
    /// @param[in] i_rc1x setting for register control word (RC1X)
    /// @param[in] i_rc2x setting for register control word (RC2X)
    /// @param[in] i_rc4x setting for register control word (RC4X)
    /// @param[in] i_rc5x setting for register control word (RC5X)
    /// @param[in] i_rc6x setting for register control word (RC6X)
    /// @param[in] i_rc8x setting for register control word (RC8X)
    /// @param[in] i_rc9x setting for register control word (RC9X)
    /// @param[in] i_rcax setting for register control word (RCAX)
    /// @param[in] i_rcbx setting for register control word (RCBX)
    ///
    constexpr raw_card_t( const uint64_t i_rc00,
                          const uint64_t i_rc01,
                          const uint64_t i_rc02,
                          const uint64_t i_rc06_07,
                          const uint64_t i_rc08,
                          const uint64_t i_rc09,
                          const uint64_t i_rc0b,
                          const uint64_t i_rc0c,
                          const uint64_t i_rc0e,
                          const uint64_t i_rc0f,
                          const uint64_t i_rc1x,
                          const uint64_t i_rc2x,
                          const uint64_t i_rc4x,
                          const uint64_t i_rc5x,
                          const uint64_t i_rc6x,
                          const uint64_t i_rc8x,
                          const uint64_t i_rc9x,
                          const uint64_t i_rcax,
                          const uint64_t i_rcbx )
        : iv_rc00(i_rc00),
          iv_rc01(i_rc01),
          iv_rc02(i_rc02),
          iv_rc06_07(i_rc06_07),
          iv_rc08(i_rc08),
          iv_rc09(i_rc09),
          iv_rc0b(i_rc0b),
          iv_rc0c(i_rc0c),
          iv_rc0e(i_rc0e),
          iv_rc0f(i_rc0f),
          iv_rc1x(i_rc1x),
          iv_rc2x(i_rc2x),
          iv_rc4x(i_rc4x),
          iv_rc5x(i_rc5x),
          iv_rc6x(i_rc6x),
          iv_rc8x(i_rc8x),
          iv_rc9x(i_rc9x),
          iv_rcax(i_rcax),
          iv_rcbx(i_rcbx)
    {}

    ///
    /// @brief default dtor
    ///
    ~raw_card_t() = default;
};

// Exposed so we can test them.
extern raw_card_t raw_card_b0;
extern raw_card_t raw_card_c1;
extern raw_card_t raw_card_a1;
extern raw_card_t raw_card_vbu;

extern const std::vector< std::pair< uint8_t, rcd01::raw_card_t> > RAW_CARDS;

}// rcd01
}// mss

#endif //_MSS_RAW_CARDS_H_
