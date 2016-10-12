/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/timing.C $ */
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
#include <fapi2.H>
#include <mss.H>
#include <lib/utils/find.H>
#include <lib/eff_config/timing.H>

namespace mss
{

enum temp_mode : uint8_t
{
    NORMAL = 1,
    EXTENDED = 2,
};

// Proposed DDR4 Full spec update(79-4B)
// Item No. 1716.78C
// pg.46
// Table 24 - tREFI and tRFC parameters (in ps)
constexpr uint64_t TREFI_BASE = 7800000;

// Proposed DDR4 3DS Addendum
// Item No. 1727.58A
// pg. 69 - 71
// Table 42 - Refresh parameters by logical rank density
static const std::vector<std::pair<uint8_t, uint64_t> > TRFC_DLR1 =
{
    // { density in GBs, tRFC4(min) in picoseconds }
    {4, 90000},
    {8, 120000},
    // 16Gb - TBD
};

// Proposed DDR4 3DS Addendum
// Item No. 1727.58A
// pg. 69 - 71
// Table 42 - Refresh parameters by logical rank density
static const std::vector<std::pair<uint8_t, uint64_t> > TRFC_DLR2 =
{
    // { density in GBs, tRFC4(min) in picoseconds }
    {4, 55000},
    {8, 90000}
    // 16Gb - TBD
};

// Proposed DDR4 3DS Addendum
// Item No. 1727.58A
// pg. 69 - 71
// Table 42 - Refresh parameters by logical rank density
static const std::vector<std::pair<uint8_t, uint64_t> > TRFC_DLR4 =
{
    // { density in GBs, tRFC4(min) in picoseconds }
    {4, 40000},
    {8, 55000}
    // 16Gb - TBD
};

///
/// @brief Calculates refresh interval time
/// @param[in] i_mode fine refresh rate mode
/// @param[in] i_temp_refresh_range temperature refresh range
/// @param[out] o_value timing val in ps
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode calc_trefi( const refresh_rate i_mode,
                              const uint8_t i_temp_refresh_range,
                              uint64_t& o_timing )
{
    uint64_t l_multiplier = 0;

    switch(i_temp_refresh_range)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_TEMP_REFRESH_RANGE_NORMAL:
            l_multiplier = temp_mode::NORMAL;
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_TEMP_REFRESH_RANGE_EXTEND:
            l_multiplier = temp_mode::EXTENDED;
            break;

        default:
            // Temperature Refresh Range will be a platform attribute set by the MRW,
            // which they "shouldn't" mess up as long as use "attribute" enums.
            // if someone messes this up we can at least catch it
            FAPI_ERR( "Incorrect Temperature Ref. Range received: %d ", i_temp_refresh_range);
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
            break;
    }

    const uint64_t l_quotient = TREFI_BASE / ( int64_t(i_mode) * l_multiplier );
    const uint64_t l_remainder = TREFI_BASE % ( int64_t(i_mode) * l_multiplier );
    o_timing = l_quotient + (l_remainder == 0 ? 0 : 1);

    FAPI_INF( "tREFI: %d, quotient: %d, remainder: %d, tREFI_base: %d",
              o_timing, l_quotient, l_remainder, TREFI_BASE );

    return fapi2::FAPI2_RC_SUCCESS;
}

/// @brief Calculates Minimum Refresh Recovery Delay Time (different logical rank)
/// @param[in] i_mode fine refresh rate mode
/// @param[in] i_density SDRAM density
/// @param[out] o_trfc_in_ps timing val in ps
/// @return fapi2::FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode calc_trfc_dlr(const uint8_t i_refresh_mode,
                                const uint8_t i_density,
                                uint64_t& o_trfc_in_ps)
{
    bool l_is_val_found = 0;

    // Selects appropriate tRFC based on fine refresh mode
    switch(i_refresh_mode)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL:
            l_is_val_found = find_value_from_key(TRFC_DLR1, i_density, o_trfc_in_ps);
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_2X:
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_2X:
            l_is_val_found = find_value_from_key(TRFC_DLR2, i_density, o_trfc_in_ps);
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_4X:
        case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_4X:
            l_is_val_found = find_value_from_key(TRFC_DLR4, i_density, o_trfc_in_ps);
            break;

        default:
            // Fine Refresh Mode will be a platform attribute set by the MRW,
            // which they "shouldn't" mess up as long as use "attribute" enums.
            // if openpower messes this up we can at least catch it
            FAPI_ERR( "Incorrect Fine Refresh Mode received: %d ", i_refresh_mode);
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
            break;
    }// switch

    if(l_is_val_found)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_ERR("Unable to find tRFC (ps) from map with SDRAM density key %d", i_density);
    return fapi2::FAPI2_RC_FALSE;
}

}// mss
