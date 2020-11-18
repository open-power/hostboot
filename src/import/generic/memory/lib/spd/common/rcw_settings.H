/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/common/rcw_settings.H $     */
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
    ///
    constexpr rcw_settings( const uint64_t i_rc00,
                            const uint64_t i_rc01)
        : iv_rc00(i_rc00),
          iv_rc01(i_rc01)
    {}

    ///
    /// @brief default dtor
    ///
    ~rcw_settings() = default;
};

}// mss

#endif //_MSS_RAW_CARDS_H_
