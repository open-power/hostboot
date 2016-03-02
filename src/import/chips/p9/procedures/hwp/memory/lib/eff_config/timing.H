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

#include <cstdint>

#include <fapi2.H>



namespace mss
{

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

/// @brief Calculates refresh interval time 1 (tREFI 1)
/// @param[in] i_target FAPI2 target
/// @param[out] o_value timing val in ps
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode calc_trefi1(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              uint64_t& o_value);

/// @brief Calculates refresh interval time 2 (tREFI 2)
/// @param[in] i_target FAPI2 target
/// @param[out] o_value timing val in ps
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode calc_trefi2(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              uint64_t& o_value);

/// @brief Calculates refresh interval time 4 (tREFI 4)
/// @param[in] i_target FAPI2 target
/// @param[out] o_value timing val in ps
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode calc_trefi4( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                               uint64_t& o_value);


} // mss

#endif
