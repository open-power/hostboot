/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/adr32s.C $  */
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
/// @file adr32s.C
/// @brief Subroutines for the PHY ADR32S registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/phy/adr32s.H>
#include <lib/utils/find.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

// Definition of the ADR32S DLL Config registers
const std::vector<uint64_t> adr32sTraits<fapi2::TARGET_TYPE_MCA>::DLL_CNFG_REG =
{
    MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0,
    MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S1
};

// Definition of the ADR32S output driver registers
const std::vector<uint64_t> adr32sTraits<fapi2::TARGET_TYPE_MCA>::OUTPUT_DRIVER_REG =
{
    MCA_DDRPHY_ADR_OUTPUT_DRIVER_FORCE_VALUE0_P0_ADR32S0,
    MCA_DDRPHY_ADR_OUTPUT_DRIVER_FORCE_VALUE0_P0_ADR32S1
};

// Definition of the ADR32S duty cycle distortion registers
const std::vector<uint64_t> adr32sTraits<fapi2::TARGET_TYPE_MCA>::DUTY_CYCLE_DISTORTION_REG =
{
    MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0,
    MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S1,
    MCA_DDRPHY_DP16_DCD_CONTROL0_P0_0,
    MCA_DDRPHY_DP16_DCD_CONTROL1_P0_0,
    MCA_DDRPHY_DP16_DCD_CONTROL0_P0_1,
    MCA_DDRPHY_DP16_DCD_CONTROL1_P0_1,
    MCA_DDRPHY_DP16_DCD_CONTROL0_P0_2,
    MCA_DDRPHY_DP16_DCD_CONTROL1_P0_2,
    MCA_DDRPHY_DP16_DCD_CONTROL0_P0_3,
    MCA_DDRPHY_DP16_DCD_CONTROL1_P0_3,
    MCA_DDRPHY_DP16_DCD_CONTROL0_P0_4,
    MCA_DDRPHY_DP16_DCD_CONTROL1_P0_4,
};

// Definition of the ADR32S write clock static offset registers
const std::vector<uint64_t> adr32sTraits<fapi2::TARGET_TYPE_MCA>::PR_STATIC_OFFSET_REG =
{
    MCA_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S0,
    MCA_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S1,
};

namespace adr32s
{

///
/// @brief Helper to iterate over ADR32S 'sides' when performing DCD cal
/// @param[in] i_target the MCA to iterate for
/// @param[in] i_reg the register (ADR0 or ADR1's register)
/// @param[in] i_seed the seed value for the adjuster
/// @param[in] i_side bool; true if this is side a, false for side b
/// @param[out] o_value the value of the adjuster when the compare bit changes state
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode dcd_cal_helper( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                  const uint64_t i_reg,
                                  const uint64_t i_seed,
                                  const bool i_side,
                                  uint64_t& o_value )
{
    typedef adr32sTraits<TARGET_TYPE_MCA> TT;

    constexpr uint64_t l_dcd_adjust_overflow =  0b1111111;
    constexpr uint64_t l_dcd_adjust_underflow = 0b0000000;

    // If compare out is 0, we tick up ...
    // Signed value which helps us increment or decrement the adjustment
    int64_t l_tick = 1;
    // ... and we expect a transition to 1
    bool l_expected = 1;
    // ... and we don't expect to overflow
    uint64_t l_overrun = l_dcd_adjust_overflow;

    fapi2::buffer<uint64_t> l_read;
    uint64_t l_current_adjust = i_seed;
    size_t l_iter = 0;

    // More or less mirror's Bialas's logic for DD2 so we can kind of try out the algorithm on DD1.

    FAPI_INF("enter dcd_cal_helper %s 0x%016lx seed: 0x%016lx side: %d",
             mss::c_str(i_target), i_reg, i_seed, i_side );

    // Prime the system with the starting values. We don't need to read/modify/write here as we're resetting
    // the world and saving a scom here is likely benificial. Clear the compare out bit as writing it set
    // will cause the PHY to throw a parity error
    l_read.insertFromRight<TT::DCD_CONTROL_DLL_ADJUST, TT::DCD_CONTROL_DLL_ADJUST_LEN>(l_current_adjust);
    l_read.writeBit<TT::DCD_CONTROL_DLL_ITER_A>(i_side);
    l_read.clearBit<TT::DCD_CONTROL_DLL_COMPARE_OUT>();
    FAPI_TRY( mss::putScom(i_target, i_reg, l_read) );

    // Algorithm waits 128ck (~100ns) between steps. However, scom takes so long (and rippling up thru
    // the platforms takes time too) that there's no need to actually delay - plenty of time has elapsed.

    // Read. Note the register is volatile in that l_read which we just wrote isn't what we'll read
    // as the distortion logic will take the seeded adjustment value and give us information on the next
    // read (so don't get cute and remove this getScom.)
    FAPI_TRY( mss::getScom(i_target, i_reg, l_read) );

    // Based on the 'direction' we're going, we have some values to setup. We setup the bit == 0 case
    // when we initialized these variables above.
    if (l_read.getBit<TT::DCD_CONTROL_DLL_COMPARE_OUT>() != 0)
    {
        // If compare out is 1, we tick down ...
        l_tick = -1;

        // ... and we expect a transition to 0
        l_expected = 0;

        // ... and we don't expect to underflow
        l_overrun = l_dcd_adjust_underflow;
    }

    do
    {
        l_iter += 1;
        bool l_current_compare = l_read.getBit<TT::DCD_CONTROL_DLL_COMPARE_OUT>();

        FAPI_INF("dcd_cal_helper: iter %d tick: %d expected: %d overrun: 0x%x out: %d adj: 0x%x",
                 l_iter, l_tick, l_expected, l_overrun, l_current_compare, l_current_adjust);

        if (l_current_compare == l_expected)
        {
            break;
        }

        // If we're here we're not done, so just adjust and try again. Clear the compare out bit, it must
        // always be 0 or the PHY will parity error
        l_read.insertFromRight<TT::DCD_CONTROL_DLL_ADJUST, TT::DCD_CONTROL_DLL_ADJUST_LEN>(l_current_adjust + l_tick);
        l_read.clearBit<TT::DCD_CONTROL_DLL_COMPARE_OUT>();
        FAPI_TRY( mss::putScom(i_target, i_reg, l_read) );

        // Wait 128ck (~100ns) ...

        FAPI_TRY( mss::getScom(i_target, i_reg, l_read) );

        l_read.extractToRight<TT::DCD_CONTROL_DLL_ADJUST, TT::DCD_CONTROL_DLL_ADJUST_LEN>(l_current_adjust);

    }
    while (l_current_adjust != l_overrun);

    FAPI_ASSERT( l_current_adjust != l_overrun,
                 fapi2::MSS_DUTY_CLOCK_DISTORTION_CAL_FAILED()
                 .set_TARGET(i_target)
                 .set_CURRENT_ADJUST(l_current_adjust)
                 .set_SIDE(i_side)
                 .set_REGISTER(i_reg)
                 .set_REGISTER_VALUE(l_read),
                 "Failed ADR DCD for %s 0x%016lx", mss::c_str(i_target), i_reg );

    // If we're here, we were done and there were no errors. So we can return back the current adjust value
    // as the output/result of our operation
    o_value = l_current_adjust;
    FAPI_INF("side: %d final adjust value: 0x%x (0x%x)", i_side, o_value, l_current_adjust);

    return FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Perform ADR DCD calibration - Nimbus Only
/// @param[in] i_target the MCBIST (controler) to perform calibration on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode duty_cycle_distortion_calibration( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    typedef adr32sTraits<TARGET_TYPE_MCA> TT;

    const auto l_mca = mss::find_targets<TARGET_TYPE_MCA>(i_target);
    fapi2::buffer<uint64_t> l_read;
    uint8_t is_sim = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    // Nothing works here in cycle sim ...
    if (is_sim)
    {
        return FAPI2_RC_SUCCESS;
    }

    if (l_mca.size() == 0)
    {
        FAPI_INF("No MCA, skipping duty cycle distortion calibration");
        return FAPI2_RC_SUCCESS;
    }

    // Do a quick check to make sure this chip doesn't have the DCD logic built in (e.g., DD1 Nimbus)
    // TODO RTC:159687 For DD2 all we need to do is kick off the h/w cal and wait. We can check any ADR_DCD
    // register, they all should reflect the inclusion of the DCD logic.

    FAPI_TRY( mss::getScom(l_mca[0], TT::DUTY_CYCLE_DISTORTION_REG[0], l_read) );

    if (l_read.getBit<TT::DCD_CONTROL_DLL_CORRECT_EN>() == 1)
    {
        FAPI_ERR("seeing ADR DCD algorithm is in the logic but we didn't code it?");
        fapi2::Assert(false);
    }

    // We must calibrate each of our ports. Each has 2 ADR units and each unit needs it's A-side and B-side calibrated.
    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        uint64_t l_seed = TT::DCD_ADJUST_DEFAULT;

        for (const auto& r : TT::DUTY_CYCLE_DISTORTION_REG)
        {
            uint64_t l_a_side_value = 0;
            uint64_t l_b_side_value = 0;

            FAPI_TRY( dcd_cal_helper(p, r, l_seed, true, l_a_side_value) );

            // We want to seed the other side (and each subsequent port) with the
            // value found in the pervious iteration as that will likely reduce the number
            // of iterations to find the transition. We back up one so that if we're on
            // a transition, we don't 'bounce' from a 1 to a 0. This will give us a good
            // transition if the a-side value is really to be the b-side value too.
            FAPI_TRY( dcd_cal_helper(p, r, l_a_side_value - 1, false, l_b_side_value) );

            // The final value is the average of the a-side and b-side values.
            l_seed = (l_a_side_value + l_b_side_value) / 2;

            FAPI_INF("average for both sides 0x%02x", l_seed);

            // Note this writes all the other values to 0's which is OK for DD1
            FAPI_TRY( mss::putScom(p, r, l_seed) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace adrs32

} // close namespace mss
