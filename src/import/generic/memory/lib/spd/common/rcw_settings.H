/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/common/rcw_settings.H $     */
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
#include <vector>

namespace mss
{

///
/// @brief raw card VBU settings
/// @note contains RCD settings for hard-coded values
/// that are not application specific.
/// Application specific settings are dervied in eff_config
struct rcw_settings
{
    uint64_t iv_rc00;
    uint64_t iv_rc01;
    uint64_t iv_rc02;
    uint64_t iv_rc06_07;
    uint64_t iv_rc09;
    uint64_t iv_rc0b;
    uint64_t iv_rc0c;
    uint64_t iv_rc0f;
    uint64_t iv_rc1x;
    uint64_t iv_rc2x;
    uint64_t iv_rc4x;
    uint64_t iv_rc5x;
    uint64_t iv_rc6x;
    uint64_t iv_rc8x;
    uint64_t iv_rc9x;
    uint64_t iv_rcax;

    ///
    /// @brief default ctor
    ///
    rcw_settings() = default;

    ///
    /// @brief Equality operator
    /// @param[in] i_rhs the right-hand side of the == operation
    /// @return true iff both raw_cards are equal
    ///
    inline bool operator==(const rcw_settings& i_rhs) const
    {
        // Betting this is faster than all the conditionals ...
        return (memcmp(this, &i_rhs, sizeof(rcw_settings)) == 0);
    }

    ///
    /// @brief Logical not operator
    /// @param[in] i_rhs the right-hand side of the != operation
    /// @return true iff both raw_cards are not equal
    ///
    inline bool operator!=(const rcw_settings& i_rhs) const
    {
        // Betting this is faster than all the conditionals ...
        return !(*this == i_rhs);
    }

    ///
    /// @brief ctor
    /// @param[in] i_rc00 setting for register control word (RC00)
    /// @param[in] i_rc01 setting for register control word (RC01)
    /// @param[in] i_rc02 setting for register control word (RC02)
    /// @param[in] i_rc06_07 setting for register control word (RCO6 & RC07)
    /// @param[in] i_rc09 setting for register control word (RC09)
    /// @param[in] i_rc0b setting for register control word (RC0B)
    /// @param[in] i_rc0c setting for register control word (RC0C)
    /// @param[in] i_rc0f setting for register control word (RC0F)
    /// @param[in] i_rc1x setting for register control word (RC1X)
    /// @param[in] i_rc2x setting for register control word (RC2X)
    /// @param[in] i_rc4x setting for register control word (RC4X)
    /// @param[in] i_rc5x setting for register control word (RC5X)
    /// @param[in] i_rc6x setting for register control word (RC6X)
    /// @param[in] i_rc8x setting for register control word (RC8X)
    /// @param[in] i_rc9x setting for register control word (RC9X)
    /// @param[in] i_rcax setting for register control word (RCAX)
    ///
    constexpr rcw_settings( const uint64_t i_rc00,
                            const uint64_t i_rc01,
                            const uint64_t i_rc02,
                            const uint64_t i_rc06_07,
                            const uint64_t i_rc09,
                            const uint64_t i_rc0b,
                            const uint64_t i_rc0c,
                            const uint64_t i_rc0f,
                            const uint64_t i_rc1x,
                            const uint64_t i_rc2x,
                            const uint64_t i_rc4x,
                            const uint64_t i_rc5x,
                            const uint64_t i_rc6x,
                            const uint64_t i_rc8x,
                            const uint64_t i_rc9x,
                            const uint64_t i_rcax)
        : iv_rc00(i_rc00),
          iv_rc01(i_rc01),
          iv_rc02(i_rc02),
          iv_rc06_07(i_rc06_07),
          iv_rc09(i_rc09),
          iv_rc0b(i_rc0b),
          iv_rc0c(i_rc0c),
          iv_rc0f(i_rc0f),
          iv_rc1x(i_rc1x),
          iv_rc2x(i_rc2x),
          iv_rc4x(i_rc4x),
          iv_rc5x(i_rc5x),
          iv_rc6x(i_rc6x),
          iv_rc8x(i_rc8x),
          iv_rc9x(i_rc9x),
          iv_rcax(i_rcax)
    {}

    ///
    /// @brief default dtor
    ///
    ~rcw_settings() = default;
};

}// mss

#endif //_MSS_RAW_CARDS_H_
