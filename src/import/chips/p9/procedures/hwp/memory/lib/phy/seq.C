/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/seq.C $     */
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
/// @file seq.C
/// @brief Subroutines for the PHY SEQ registers
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/phy/seq.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/utils/bit_count.H>
#include <lib/eff_config/timing.H>
#include <lib/shared/mss_const.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{

namespace seq
{

///
/// @brief PHY SEQ register exponent helper
/// PHY SEQ fields is used as exponent of 2, to calculate the number of MEMINTCLKO clock cycles.
/// For example, if TMOD_CYCLES[0:3] = 5, the internal timers use the value 2^5 = 32 MEMINTCLKO
/// clock cycles. The maximum value per nibble is ‘A’h. This helper takes a calculated value and returns
/// the 'best' exponent.
/// @param[in] i_value a value for which to make an exponent
/// @return uint64_t right-aligned value to stick in the field
///
uint64_t exp_helper( const uint64_t i_value )
{
    // PHY exponents don't make much sense above this value so we short circuit if possible.
    constexpr uint64_t MAX_EXP = 0xA;

    if (i_value >= (1 << MAX_EXP))
    {
        return 0xA;
    }

    // If the user passes in 0, let it past.
    if (i_value == 0)
    {
        return 0;
    }

    // Find the first bit set. The subtraction from 63 switches from a left-count to a right-count (e.g., 0 (left most
    // bit) is really bit 63 if you start on the right.)
    const uint64_t l_first_bit = 63 - first_bit_set(i_value);

    // If the input is greater than 2^first bit, add one to the first_bit so 2^first_bit >= input
    // (round up)
    return l_first_bit + (uint64_t(1 << l_first_bit) < i_value ? 1 : 0);
}

///
/// @brief reset SEQ_TIMING0
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_timing0( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    typedef seqTraits<TARGET_TYPE_MCA> TT;
    fapi2::buffer<uint64_t> l_data;

    // Table 5-324. SEQ Memory Timing Parameter 0 Register Bit Definition
    // TMOD_CYCLES max(tMRD, tMOD)
    // TRCD_CYCLES tRCD
    // TRP_CYCLES  tRP
    // TRFC_CYCLES tRFC

    uint64_t l_tmod_cycles = 0;
    uint8_t l_trcd = 0;
    uint8_t l_trp = 0;
    uint16_t l_trfc_max = 0;

    l_tmod_cycles = exp_helper( std::max(mss::tmrd(), mss::tmod(i_target)) );
    l_data.insertFromRight<TT::TMOD_CYCLES, TT::TMOD_CYCLES_LEN>(l_tmod_cycles);

    FAPI_TRY( mss::eff_dram_trcd(i_target, l_trcd) );
    l_data.insertFromRight<TT::TRCD_CYCLES, TT::TRCD_CYCLES_LEN>( exp_helper(l_trcd) );

    FAPI_TRY( mss::eff_dram_trp(i_target, l_trp) );
    l_data.insertFromRight<TT::TRP_CYCLES, TT::TRP_CYCLES_LEN>( exp_helper(l_trp) );

    // It's not really clear what to put here. We can have DIMM with different tRFC as they
    // don't have to be the same (3DS v. SDP for example.) So we'll take the maximum trfc we
    // find on the DIMM connected to this port.
    for (const auto& d : mss::find_targets<TARGET_TYPE_DIMM>(i_target))
    {
        // tRFC is for non-3DS, tRFC_slr for 3DS is to the same logical rank,
        // and tRFC_dlr is to different logical ranks. Unclear which to use.
        uint16_t l_trfc = 0;
        uint8_t l_trfc_dlr = 0;

        // tRFC (or tRFC_slr) will retrieve a value for 3DS or non-3DS
        // tRFC_dlr is only set for 3DS (should be 0 otherwise)
        // so we opt to take the more aggressive timing,
        // means less chance of data being corrupted
        FAPI_TRY( mss::eff_dram_trfc(d, l_trfc) );
        FAPI_TRY( mss::eff_dram_trfc_dlr(d, l_trfc_dlr) );

        {
            // cast needed for template deduction of std::max()
            // HB doesn't support using std::min() with initializer lists
            const uint16_t l_trfc_3ds_min = std::min(l_trfc, static_cast<uint16_t>(l_trfc_dlr));
            l_trfc_max = std::min( l_trfc_3ds_min, l_trfc_max);
        }
    }

    l_data.insertFromRight<TT::TRFC_CYCLES, TT::TRFC_CYCLES_LEN>( exp_helper(l_trfc_max) );

    FAPI_TRY( mss::putScom(i_target, TT::SEQ_TIMING0_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief reset SEQ_TIMING1
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_timing1( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    typedef seqTraits<TARGET_TYPE_MCA> TT;
    fapi2::buffer<uint64_t> l_data;

    // Table 5-325. SEQ Memory Timing Parameter 1 Register
    // TZQINIT_CYCLES  max(tZQINIT,tZQOPER)
    // TZQCS_CYCLES  tZQCS
    // TWLDQSEN_CYCLES tWLDQSEN
    // TWRMRD_CYCLES tWLMRD

    uint64_t l_tzqint = std::max( mss::tzqinit(), mss::tzqoper() );
    uint8_t l_twldqsen = 0;
    FAPI_TRY( mss::twldqsen(i_target, l_twldqsen), "%s Failed to calculate tWLDQSEN", mss::c_str(i_target) );

    l_data.insertFromRight<TT::TZQINIT_CYCLES, TT::TZQINIT_CYCLES_LEN>( exp_helper(l_tzqint) );
    l_data.insertFromRight<TT::TZQCS_CYCLES, TT::TZQCS_CYCLES_LEN>( exp_helper(mss::tzqcs()) );
    l_data.insertFromRight<TT::TWLDQSEN_CYCLES, TT::TWLDQSEN_CYCLES_LEN>( exp_helper(l_twldqsen) );
    l_data.insertFromRight<TT::TWRMRD_CYCLES, TT::TWRMRD_CYCLES_LEN>( exp_helper(mss::twlmrd()) );

    FAPI_TRY( mss::putScom(i_target, TT::SEQ_TIMING1_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Swizzle the MPR pattern to switch bit order in each byte
/// @param[in] i_patterns the patterns to put in SEQ_RDWR_DATA0 and _DATA1 registers
/// @param[out] The swizzle pattern
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode swizzle_mpr_pattern( const uint32_t i_pattern, uint32_t& o_swizzled)
{
    constexpr uint64_t BYTES_PER_32 = 4;
    fapi2::buffer<uint32_t> l_buf (i_pattern);

    // loop over each byte and reverse the bits
    for (size_t count = 0; count < BYTES_PER_32; ++count)
    {
        fapi2::buffer<uint8_t> l_temp;
        FAPI_TRY( l_buf.extract(l_temp, count * BITS_PER_BYTE, BITS_PER_BYTE) );

        // reverse is in swizzle.H. Reverses all of the bits in the buffer
        mss::reverse(l_temp);
        FAPI_TRY( l_buf.insert(l_temp, count * BITS_PER_BYTE, BITS_PER_BYTE) );
    }

    o_swizzled = l_buf;

    FAPI_INF("0x%08x unswizzle 0x%08x swizzled that dizzle", i_pattern, o_swizzled);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief reset SEQ_TIMING2
/// @param[in] i_target fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode reset_timing2( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    typedef seqTraits<TARGET_TYPE_MCA> TT;

    // Reset value of SEQ_TIMING2 is lucky 7's - we'll fix up the first nibble with ODT info
    fapi2::buffer<uint64_t> l_data(0x7777);

    // Table 5-327. SEQ Memory Timing Parameter 2 Register
    // TODTLON_OFF_CYCLES max(ODTLon, ODTLoff)
    uint8_t l_odtlon = 0;
    uint8_t l_odtloff = 0;
    uint64_t l_odt = 0;
    FAPI_TRY( mss::max_dodt_on(i_target, l_odtlon) );
    FAPI_TRY( mss::max_dodt_off(i_target, l_odtloff) );

    l_odt = std::max( l_odtlon, l_odtloff );
    l_data.insertFromRight<TT::TODTLON_OFF_CYCLES, TT::TODTLON_OFF_CYCLES_LEN>( exp_helper(l_odt) );

    FAPI_TRY( mss::putScom(i_target, TT::SEQ_TIMING2_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}


} // close namespace seq
} // close namespace mss
