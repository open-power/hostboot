/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/eff_config/timing.H $      */
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
///
/// @file timing.H
/// @brief Determine effective config for mss settings
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_TIMING_H_
#define _MSS_TIMING_H_

#include <mss.H>
#include <fapi2.H>
#include <cstdint>
#include "../utils/find.H"

using fapi2::TARGET_TYPE_DIMM;

namespace mss
{

// { density in GBs, tREFI(base) in picoseconds }
static const std::vector<std::pair<uint8_t, uint64_t> > TREFI_BASE =
{
    {2, 7800},
    {4, 7800},
    {8, 7800},
    // 16Gb - TBD
};

// { density in GBs, tRFC1(min) in picoseconds }
static const std::vector<std::pair<uint8_t, uint64_t> > TRFC1_MIN =
{
    {2, 160},
    {4, 260},
    {8, 350},
    // 16Gb - TBD
};


// { density in GBs, tRFC2(min) in picoseconds }
static const std::vector<std::pair<uint8_t, uint64_t> > TRFC2_MIN =
{
    {2, 110},
    {4, 160},
    {8, 260},
    // 16Gb - TBD
};


// { density in GBs, tRFC4(min) in picoseconds }
static const std::vector<std::pair<uint8_t, uint64_t> > TRFC4_MIN =
{
    {2, 90},
    {4, 110},
    {8, 160},
    // 16Gb - TBD
};

enum GUARD_BAND
{
    // Used for caclulating spd timing values - from JEDEC rounding algorithm
    // Correction factor is 1% (for DDR3) or 2.5% (for DDR4)
    // when doing integer math, we add-in the inverse correction factor
    // Formula used for derivation:
    // Guardband = 1000 * (1000* correction_factor) - 1
    INVERSE_DDR3_CORRECTION_FACTOR = 989,
    INVERSE_DDR4_CORRECTION_FACTOR = 974,
};


///
/// @brief      Calculates timing value
/// @tparam     T input and output type
/// @param[in]  i_timing_mtb timing value in MTB units
/// @param[in]  i_mtb_multiplier SPD medium timebase
/// @param[in]  i_timing_ftb fine offset of timing value
/// @param[in]  i_ftb_multiplier SPD fine timebase
/// @return     the timing value in picoseconds
///
template<typename T>
inline T calc_timing_from_timebase(const T i_timing_mtb,
                                   const T i_mtb_multiplier,
                                   const T i_timing_ftb,
                                   const T i_ftb_multiplier)
{
    // JEDEC algorithm
    T l_timing_val = i_timing_mtb * i_mtb_multiplier;
    T l_fine_offset = i_timing_ftb * i_ftb_multiplier;

    // Needed to do integer math but attribute is uint64
    return l_timing_val + l_fine_offset;
}


///
/// @brief      Returns clock cycles
/// @tparam     T input and output type
/// @param[in]  timing_in_ps timing parameter in ps
/// @param[in]  tck_in_ps  clock period in ps
/// @param[in]  inverse_corr_factor inverse correction factor  (defined by JEDEC)
/// @return     the clock cycles of timing parameter (provided in ps)
/// @note       DDR4 SPD Contents Rounding Algorithm
/// @note       Item 2220.46
///
template<typename T>
inline T calc_nck(T timing_in_ps, T tck_in_ps, T inverse_corr_factor)
{
    // Preliminary nCK calculation, scaled by 1000
    T temp_nck = timing_in_ps * 1000 / tck_in_ps;

    // Apply inverse of correction factor percentage
    temp_nck += inverse_corr_factor;

    return temp_nck / 1000;
}


//
// TK - AAM
// These are only used in eff_config, make them non-member non-friend functions in eff_config.C?
//

/// @brief Calculates refresh interval time 1 (tREFI 1)
/// @param[in] i_target FAPI2 target
/// @param[out] o_value timing val in ps
/// @return fapi2::ReturnCode
///
inline fapi2::ReturnCode calc_trefi1(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,  uint64_t& o_value)
{
    uint8_t  l_quotient = 0;
    uint8_t l_remainder = 0;
    uint64_t l_output = 0;
    uint8_t l_temp_ref_range = 0;
    uint8_t l_dram_density = 0;


    FAPI_TRY(mss::eff_dram_density(i_target, l_dram_density));

    switch(l_temp_ref_range)
    {
        case fapi2::ENUM_ATTR_EFF_TEMP_REF_RANGE_NORMAL:
            mss::find_value_from_key(TREFI_BASE, l_dram_density, o_value);
            break;

        case fapi2::ENUM_ATTR_EFF_TEMP_REF_RANGE_EXTEND:
            mss::find_value_from_key(TREFI_BASE, l_dram_density, l_output);
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
inline fapi2::ReturnCode calc_trefi2(const fapi2::Target<TARGET_TYPE_DIMM>& i_target, uint64_t& o_value)
{
    uint8_t l_quotient = 0;
    uint8_t l_remainder = 0;
    uint64_t l_output = 0;
    uint8_t l_temp_ref_range = 0;
    uint8_t l_dram_density = 0;

    FAPI_TRY(mss::eff_temp_ref_range(i_target, l_temp_ref_range));
    FAPI_TRY(mss::eff_dram_density(i_target, l_dram_density));

    switch(l_temp_ref_range)
    {
        case fapi2::ENUM_ATTR_EFF_TEMP_REF_RANGE_NORMAL:
            mss::find_value_from_key(TREFI_BASE, l_dram_density, l_output);
            l_quotient = l_output / 2;
            l_remainder = l_output % 2;
            o_value = l_quotient + (l_remainder == 0 ? 0 : 1);
            break;

        case fapi2::ENUM_ATTR_EFF_TEMP_REF_RANGE_EXTEND:
            mss::find_value_from_key(TREFI_BASE, l_dram_density, l_output);
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
inline fapi2::ReturnCode calc_trefi4( const fapi2::Target<TARGET_TYPE_DIMM>& i_target, uint64_t& o_value)
{
    uint8_t l_quotient = 0;
    uint8_t l_remainder = 0;
    uint64_t l_output = 0;
    uint8_t l_temp_ref_range = 0;
    uint8_t l_dram_density = 0;

    FAPI_TRY(mss::eff_temp_ref_range(i_target, l_temp_ref_range));
    FAPI_TRY(mss::eff_dram_density(i_target, l_dram_density));

    switch(l_temp_ref_range)
    {
        case fapi2::ENUM_ATTR_EFF_TEMP_REF_RANGE_NORMAL:
            mss::find_value_from_key(TREFI_BASE, l_dram_density, l_output);
            l_quotient = l_output / 4;
            l_remainder = l_output % 4;
            o_value = l_quotient + (l_remainder == 0 ? 0 : 1);
            break;

        case fapi2::ENUM_ATTR_EFF_TEMP_REF_RANGE_EXTEND:
            mss::find_value_from_key(TREFI_BASE, l_dram_density, l_output);
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

} // mss

#endif
