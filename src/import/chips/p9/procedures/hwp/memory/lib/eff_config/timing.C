/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/eff_config/timing.C $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <fapi2.H>
#include <mss.H>
#include <lib/utils/find.H>
#include <lib/eff_config/timing.H>

namespace mss
{

// Proposed DDR4 Full spec update(79-4A)
// Item No. 1716.78C
// pg.46
// Table 24 - tREFI and tRFC parameters
static const std::vector<std::pair<uint8_t, uint64_t> > TREFI_BASE =
{
    // { density in GBs, tREFI(base) in nanoseconds }
    {2, 7800},
    {4, 7800},
    {8, 7800},
    // 16Gb - TBD
};

// Proposed DDR4 Full spec update(79-4A)
// Item No. 1716.78C
// pg.46
// Table 24 - tREFI and tRFC parameters
static const std::vector<std::pair<uint8_t, uint64_t> > TRFC1_MIN =
{
    // { density in GBs, tRFC1(min) in nanoseconds }
    {2, 160},
    {4, 260},
    {8, 350},
    // 16Gb - TBD
};

// Proposed DDR4 Full spec update(79-4A)
// Item No. 1716.78C
// pg.46
// Table 24 - tREFI and tRFC parameters
static const std::vector<std::pair<uint8_t, uint64_t> > TRFC2_MIN =
{
    // { density in GBs, tRFC2(min) in nanoseconds }
    {2, 110},
    {4, 160},
    {8, 260},
    // 16Gb - TBD
};

// Proposed DDR4 Full spec update(79-4A)
// Item No. 1716.78C
// pg.46
// Table 24 - tREFI and tRFC parameters
static const std::vector<std::pair<uint8_t, uint64_t> > TRFC4_MIN =
{
    // { density in GBs, tRFC4(min) in nanoseconds }
    {2, 90},
    {4, 110},
    {8, 160},
    // 16Gb - TBD
};

// Proposed DDR4 3DS Addendum
// Item No. 1727.58A
// pg. 69 - 71
// Table 42 - Refresh parameters by logical rank density
static const std::vector<std::pair<uint8_t, uint64_t> > TRFC_DLR1 =
{
    // { density in GBs, tRFC4(min) in nanoseconds }
    {4, 90},
    {8, 120},
    // 16Gb - TBD
};

// Proposed DDR4 3DS Addendum
// Item No. 1727.58A
// pg. 69 - 71
// Table 42 - Refresh parameters by logical rank density
static const std::vector<std::pair<uint8_t, uint64_t> > TRFC_DLR2 =
{
    // { density in GBs, tRFC4(min) in nanoseconds }
    {4, 55},
    {8, 90}
    // 16Gb - TBD
};

// Proposed DDR4 3DS Addendum
// Item No. 1727.58A
// pg. 69 - 71
// Table 42 - Refresh parameters by logical rank density
static const std::vector<std::pair<uint8_t, uint64_t> > TRFC_DLR4 =
{
    // { density in GBs, tRFC4(min) in nanoseconds }
    {4, 40},
    {8, 55}
    // 16Gb - TBD
};

/// @brief Calculates refresh interval time 1 (tREFI 1)
/// @param[in] i_target FAPI2 target
/// @param[out] o_value timing val in ps
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode calc_trefi1(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              uint64_t& o_value)
{
    uint8_t  l_quotient = 0;
    uint8_t l_remainder = 0;
    uint64_t l_output = 0;
    uint8_t l_temp_ref_range = 0;
    uint8_t l_dram_density = 0;
    bool l_found_value = true;

    FAPI_TRY( mss::eff_dram_density(i_target, l_dram_density) );
    FAPI_TRY( mss::mrw_temp_ref_range(l_temp_ref_range) );

    switch(l_temp_ref_range)
    {
        case fapi2::ENUM_ATTR_MRW_TEMP_REF_RANGE_NORMAL:
            l_found_value = mss::find_value_from_key(TREFI_BASE, l_dram_density, l_output);
            FAPI_TRY( check::fail_for_invalid_map(i_target,
                                                  l_found_value,
                                                  l_dram_density,
                                                  l_temp_ref_range,
                                                  "Could not find sdram density given"
                                                  "normal temp_ref_range.") );
            break;

        case fapi2::ENUM_ATTR_MRW_TEMP_REF_RANGE_EXTEND:
            l_found_value = mss::find_value_from_key(TREFI_BASE, l_dram_density, l_output);
            FAPI_TRY( check::fail_for_invalid_map(i_target,
                                                  l_found_value,
                                                  l_dram_density,
                                                  l_temp_ref_range,
                                                  "Could not find sdram density given"
                                                  "extended temp_ref_range.") );
            l_quotient = l_output / 2;
            l_remainder = l_output % 2;
            o_value = l_quotient + (l_remainder == 0 ? 0 : 1);
            break;

        default:
            // l_temp_ref_range will be a platform attribute set by the MRW,
            // which they "shouldn't" mess up as long as use "attribute" enums.
            // if openpower messes this up we can at least catch it
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_TEMP_REF_RANGE().
                        set_TEMP_REF_RANGE(l_temp_ref_range),
                        "%s Incorrect Temperature Ref. Range received: %d ",
                        mss::c_str(i_target),
                        l_temp_ref_range);

            break;
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Calculates refresh interval time 2 (tREFI 2)
/// @param[in] i_target FAPI2 target
/// @param[out] o_value timing val in ps
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode calc_trefi2(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              uint64_t& o_value)
{
    uint8_t l_quotient = 0;
    uint8_t l_remainder = 0;
    uint64_t l_output = 0;
    uint8_t l_temp_ref_range = 0;
    uint8_t l_dram_density = 0;
    bool l_found_value = true;

    FAPI_TRY( mss::mrw_temp_ref_range(l_temp_ref_range) );
    FAPI_TRY( mss::eff_dram_density(i_target, l_dram_density) );

    switch(l_temp_ref_range)
    {
        case fapi2::ENUM_ATTR_MRW_TEMP_REF_RANGE_NORMAL:
            l_found_value = mss::find_value_from_key(TREFI_BASE, l_dram_density, l_output);
            FAPI_TRY( check::fail_for_invalid_map(i_target,
                                                  l_found_value,
                                                  l_dram_density,
                                                  l_temp_ref_range,
                                                  "Could not find sdram density given"
                                                  "normal temp_ref_range.") );

            l_remainder = l_output % 2;
            o_value = l_quotient + (l_remainder == 0 ? 0 : 1);
            break;

        case fapi2::ENUM_ATTR_MRW_TEMP_REF_RANGE_EXTEND:
            l_found_value = mss::find_value_from_key(TREFI_BASE, l_dram_density, l_output);
            FAPI_TRY( check::fail_for_invalid_map(i_target,
                                                  l_found_value,
                                                  l_dram_density,
                                                  l_temp_ref_range,
                                                  "Could not find sdram density given"
                                                  "extended temp_ref_range.") );
            l_quotient = l_output / 4;
            l_remainder = l_output % 4;
            o_value = l_quotient + (l_remainder == 0 ? 0 : 1);
            break;

        default:
            // l_temp_ref_range will be a platform attribute set by the MRW,
            // which they "shouldn't" mess up as long as use "attribute" enums.
            // if openpower messes this up we can at least catch it
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_TEMP_REF_RANGE().
                        set_TEMP_REF_RANGE(l_temp_ref_range),
                        "%s Incorrect Temperature Ref. Range received: %d ",
                        mss::c_str(i_target),
                        l_temp_ref_range);

            break;
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Calculates refresh interval time 4 (tREFI 4)
/// @param[in] i_target FAPI2 target
/// @param[out] o_value timing val in ps
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode calc_trefi4( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                               uint64_t& o_value)
{
    uint8_t l_quotient = 0;
    uint8_t l_remainder = 0;
    uint64_t l_output = 0;
    uint8_t l_temp_ref_range = 0;
    uint8_t l_dram_density = 0;
    bool l_found_value = true;

    FAPI_TRY( mss::mrw_temp_ref_range(l_temp_ref_range) );
    FAPI_TRY( mss::eff_dram_density(i_target, l_dram_density) );

    switch(l_temp_ref_range)
    {
        case fapi2::ENUM_ATTR_MRW_TEMP_REF_RANGE_NORMAL:
            l_found_value = mss::find_value_from_key(TREFI_BASE, l_dram_density, l_output);
            FAPI_TRY( check::fail_for_invalid_map(i_target,
                                                  l_found_value,
                                                  l_dram_density,
                                                  l_temp_ref_range,
                                                  "Could not find sdram density given"
                                                  "normal temp_ref_range.") );
            l_quotient = l_output / 4;
            l_remainder = l_output % 4;
            o_value = l_quotient + (l_remainder == 0 ? 0 : 1);
            break;

        case fapi2::ENUM_ATTR_MRW_TEMP_REF_RANGE_EXTEND:
            l_found_value = mss::find_value_from_key(TREFI_BASE, l_dram_density, l_output);
            FAPI_TRY( check::fail_for_invalid_map(i_target,
                                                  l_found_value,
                                                  l_dram_density,
                                                  l_temp_ref_range,
                                                  "Could not find sdram density given"
                                                  "extended temp_ref_range.") );
            l_quotient = l_output / 8;
            l_remainder = l_output % 8;
            o_value = l_quotient + (l_remainder == 0 ? 0 : 1);
            break;

        default:
            // l_temp_ref_range will be a platform attribute set by the MRW,
            // which they "shouldn't" mess up as long as use "attribute" enums.
            // if openpower messes this up we can at least catch it
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_TEMP_REF_RANGE().
                        set_TEMP_REF_RANGE(l_temp_ref_range),
                        "%s Incorrect Temperature Ref. Range received: %d ",
                        mss::c_str(i_target),
                        l_temp_ref_range);

            break;
    }

fapi_try_exit:
    return fapi2::current_err;
}

}// mss
