/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/adr32s_workarounds.C $ */
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
/// @file workarounds/adr32s_workarounds.C
/// @brief Workarounds for the ADR32s logic blocks
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/mss_attribute_accessors.H>

#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/utils/conversions.H>
#include <lib/fir/fir.H>
#include <lib/workarounds/adr32s_workarounds.H>
#include <lib/phy/ddr_phy.H>
#include <generic/memory/lib/utils/find.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

// Definition of the ADR32S duty cycle distortion registers
// Note: per John Bialas, ADR32S1 and CONTROL1_P0_4 do not hook up to any logic, removing them to avoid errors
const std::vector<uint64_t> dutyCycleDistortionTraits<fapi2::TARGET_TYPE_MCA>::DUTY_CYCLE_DISTORTION_REG =
{
    MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0,
    MCA_DDRPHY_DP16_DCD_CONTROL0_P0_0,
    MCA_DDRPHY_DP16_DCD_CONTROL1_P0_0,
    MCA_DDRPHY_DP16_DCD_CONTROL0_P0_1,
    MCA_DDRPHY_DP16_DCD_CONTROL1_P0_1,
    MCA_DDRPHY_DP16_DCD_CONTROL0_P0_2,
    MCA_DDRPHY_DP16_DCD_CONTROL1_P0_2,
    MCA_DDRPHY_DP16_DCD_CONTROL0_P0_3,
    MCA_DDRPHY_DP16_DCD_CONTROL1_P0_3,
    MCA_DDRPHY_DP16_DCD_CONTROL0_P0_4,
};

// Definition of the ADR32S duty cycle distortion registers
// Note: per John Bialas, ADR32S1 and CONTROL1_P0_4 do not hook up to any logic, removing them to avoid errors
const std::vector<uint64_t> dutyCycleDistortionTraits<fapi2::TARGET_TYPE_MCA>::DLL_CONTROL_REG =
{
    MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0,
    MCA_DDRPHY_DP16_DLL_CNTL0_P0_0,
    MCA_DDRPHY_DP16_DLL_CNTL1_P0_0,
    MCA_DDRPHY_DP16_DLL_CNTL0_P0_1,
    MCA_DDRPHY_DP16_DLL_CNTL1_P0_1,
    MCA_DDRPHY_DP16_DLL_CNTL0_P0_2,
    MCA_DDRPHY_DP16_DLL_CNTL1_P0_2,
    MCA_DDRPHY_DP16_DLL_CNTL0_P0_3,
    MCA_DDRPHY_DP16_DLL_CNTL1_P0_3,
    MCA_DDRPHY_DP16_DLL_CNTL0_P0_4,
};

namespace workarounds
{

namespace adr32s
{

///
/// @brief Clears the FIRs mistakenly set by the DCD calibration
/// @param[in] i_target MCBIST target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Always needs to be run for DD1.* parts.  unsure for DD2
/// TODO:RTC169173 update DCD calibration for DD2
///
fapi2::ReturnCode clear_dcd_firs( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("%s clearing DCD FIRs!", mss::c_str(i_target));

    // Run the fir clear to reset bits that are caused by the DCD calibration
    for( const auto& l_mca : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        fir::reg<MCA_IOM_PHY0_DDRPHY_FIR_REG> l_mca_fir_reg(l_mca, fapi2::current_err);
        FAPI_TRY(fapi2::current_err, "unable to create fir::reg for %d", MCA_IOM_PHY0_DDRPHY_FIR_REG);

        // Per Steve Wyatt:
        // Bit 55 gets set during the DCD cal in the ADR
        // Bit 56/58 get set during the DCD cal in the DP's
        // Bit 59 is set due to parity errors and must be cleared, per Tim Buccholtz
        // Clearing them all here, as the DCD cal is run on the ADR/DP's in the same code in lib/adr32s.C
        FAPI_TRY(l_mca_fir_reg.clear<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_1>()); // bit 55
        FAPI_TRY(l_mca_fir_reg.clear<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_2>()); // bit 56
        FAPI_TRY(l_mca_fir_reg.clear<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_4>()); // bit 58
        FAPI_TRY(l_mca_fir_reg.clear<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_5>()); // bit 59
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets up the DLL control regs for the DCD calibration
/// @param[in] i_target MCA target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Always needs to be run for DD1.* parts.  unsure for DD2
/// TODO:RTC169173 update DCD calibration for DD2
///
fapi2::ReturnCode setup_dll_control_regs_for_dcd( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    typedef dutyCycleDistortionTraits<TARGET_TYPE_MCA> TT;

    for (const auto& r : TT::DLL_CONTROL_REG)
    {
        fapi2::buffer<uint64_t> l_data;

        FAPI_TRY(mss::getScom(i_target, r, l_data));

        // Stops cal from updating and disables cal good to keep parity good (these regs have parity issues on bits 60-63)
        l_data.clearBit<TT::DLL_CAL_UPDATE>();
        l_data.clearBit<TT::DLL_CAL_GOOD>();

        FAPI_TRY(mss::putScom(i_target, r, l_data));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Restores the DLL control regs after the DCD calibration
/// @param[in] i_target MCA target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Always needs to be run for DD1.* parts.  unsure for DD2
/// TODO:RTC169173 update DCD calibration for DD2
///
fapi2::ReturnCode restore_dll_control_regs_for_dcd( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    typedef dutyCycleDistortionTraits<TARGET_TYPE_MCA> TT;

    for (const auto& r : TT::DLL_CONTROL_REG)
    {
        fapi2::buffer<uint64_t> l_data;

        FAPI_TRY(mss::getScom(i_target, r, l_data));

        // Re-enables cal to update
        l_data.setBit<TT::DLL_CAL_UPDATE>();

        FAPI_TRY(mss::putScom(i_target, r, l_data));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

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
    typedef dutyCycleDistortionTraits<TARGET_TYPE_MCA> TT;

    constexpr uint64_t l_dcd_adjust_overflow =  0b1111111;
    constexpr uint64_t l_dcd_adjust_underflow = 0b0000000;

    constexpr uint64_t l_delay = mss::DELAY_100NS;
    const uint64_t l_delay_in_cycles = mss::ns_to_cycles(i_target, l_delay);

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
    l_read.setBit<TT::DCD_CONTROL_DLL_CORRECT_EN>();
    l_read.writeBit<TT::DCD_CONTROL_DLL_ITER_A>(i_side);
    l_read.clearBit<TT::DCD_CONTROL_DLL_COMPARE_OUT>();
    FAPI_TRY( mss::putScom(i_target, i_reg, l_read) );

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

        FAPI_TRY( fapi2::delay(l_delay, mss::cycles_to_simcycles(l_delay_in_cycles)) );

        FAPI_TRY( mss::getScom(i_target, i_reg, l_read) );

        FAPI_TRY( fapi2::delay(l_delay, mss::cycles_to_simcycles(l_delay_in_cycles)) );

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
                 "Failed DCD for %s 0x%016lx", mss::c_str(i_target), i_reg );

    // If we're here, we were done and there were no errors. So we can return back the current adjust value
    // as the output/result of our operation
    o_value = l_current_adjust;
    FAPI_INF("side: %d final adjust value: 0x%x (0x%x)", i_side, o_value, l_current_adjust);

    return FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets the value to write out to the DCD register in question
/// @param[in,out] i_a_side_rc - a side's return code - cannot be const due to the fapi logging function modifying the RC
/// @param[in] i_a_side_val - a side's value
/// @param[in,out] i_b_side_rc - b side's return code - cannot be const due to the fapi logging function modifying the RC
/// @param[in] i_b_side_val - b side's value
/// @param[out] o_value - value to use for the DCD register
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Due to DCD algorithm fails due to bad HW, the algorithm is going to do the following
/// Per the PHY team, we do not want to fail out existing HW for the DCD calibration fails
/// 1) Use prior calibrated value if a/b fail - return success
/// 2) Use a if b failed
/// 3) Use b if a failed
/// 4) Average if a and b both passed
///
fapi2::ReturnCode compute_dcd_value(fapi2::ReturnCode& io_a_side_rc,
                                    const uint64_t i_a_side_val,
                                    fapi2::ReturnCode& io_b_side_rc,
                                    const uint64_t i_b_side_val,
                                    uint64_t& o_value)
{
    // 1) return a failing RC if a and b side failed
    if(io_a_side_rc != FAPI2_RC_SUCCESS && io_b_side_rc != FAPI2_RC_SUCCESS)
    {
        // Log a-side, return b-side (chose this at random, but we want to exit)
        FAPI_ERR("Recovered from DCD calibration fail - both side A and side B failed, using prior calibrated value");
        fapi2::logError(io_a_side_rc);
        fapi2::logError(io_b_side_rc);
        return FAPI2_RC_SUCCESS;
    }

    // 2) b failed, use a
    if(io_b_side_rc != FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("Recovered from DCD calibration fail - side B failed, using side-A's value");
        fapi2::logError(io_b_side_rc);
        o_value = i_a_side_val;
        return FAPI2_RC_SUCCESS;
    }

    // 3) a failed, use b
    if(io_a_side_rc != FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("Recovered from DCD calibration fail - side A failed, using side-B's value");
        fapi2::logError(io_a_side_rc);
        o_value = i_b_side_val;
        return FAPI2_RC_SUCCESS;
    }

    // 4) average a and b as both passed
    FAPI_DBG("Both sides A/B passed - averaging");
    o_value = (i_a_side_val + i_b_side_val) / 2;
    return FAPI2_RC_SUCCESS;
}

///
/// @brief Perform ADR DCD calibration - Nimbus Only
/// @param[in] i_target the MCBIST (controler) to perform calibration on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode duty_cycle_distortion_calibration( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    typedef dutyCycleDistortionTraits<TARGET_TYPE_MCA> TT;

    const auto l_mca = mss::find_targets<TARGET_TYPE_MCA>(i_target);

    // Skips DCD calibration if we're a DD2 part
    if (!mss::chip_ec_feature_dcd_workaround(i_target))
    {
        FAPI_INF("%s Skipping DCD calibration algorithm due to part revision", mss::c_str(i_target));
        return FAPI2_RC_SUCCESS;
    }

    // Clears the FIRs created by DCD calibration, if needed
    FAPI_TRY(mss::workarounds::adr32s::clear_dcd_firs(i_target));

    // We must calibrate each of our ports. Each has 2 ADR units and each unit needs it's A-side and B-side calibrated.
    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        uint64_t l_seed = TT::DCD_ADJUST_DEFAULT;

        // Sets up the DLL control regs for DCD cal for this port
        FAPI_TRY(mss::workarounds::adr32s::setup_dll_control_regs_for_dcd( p ));

        for (const auto& r : TT::DUTY_CYCLE_DISTORTION_REG)
        {
            uint64_t l_a_side_value = 0;
            uint64_t l_b_side_value = 0;

            auto l_a_rc = dcd_cal_helper(p, r, l_seed, true, l_a_side_value);

            // Updates the seed value to avoid underflow issues
            l_seed = l_a_side_value == 0 ? l_seed : l_a_side_value - 1;

            // We want to seed the other side (and each subsequent port) with the
            // value found in the pervious iteration as that will likely reduce the number
            // of iterations to find the transition. We back up one so that if we're on
            // a transition, we don't 'bounce' from a 1 to a 0. This will give us a good
            // transition if the a-side value is really to be the b-side value too.
            auto l_b_rc = dcd_cal_helper(p, r, l_seed, false, l_b_side_value);

            // The final value is the average of the a-side and b-side values.
            FAPI_TRY(compute_dcd_value(l_a_rc, l_a_side_value, l_b_rc, l_b_side_value, l_seed));

            FAPI_INF("%s calibrated value for both sides for reg 0x%016lx cal value: 0x%02x, a_side 0x%02x b_side: 0x%02x",
                     mss::c_str(p), r, l_seed,
                     l_a_side_value, l_b_side_value);

            // Stores the final calibrated values in the register
            fapi2::buffer<uint64_t> l_buff;
            l_buff.insertFromRight<TT::DCD_CONTROL_DLL_ADJUST, TT::DCD_CONTROL_DLL_ADJUST_LEN>(l_seed);
            // The clear should not be needed as it's a new buffer but was included to show it's needed for the hardware
            l_buff.clearBit<TT::DCD_CONTROL_DLL_COMPARE_OUT>();

            // Note this writes all the other values to 0's which is OK for DD1
            FAPI_TRY( mss::putScom(p, r, l_buff) );

        }

        // Restores the DLL control regs for DCD cal for this port
        FAPI_TRY(mss::workarounds::adr32s::restore_dll_control_regs_for_dcd( p ));
    }

    // Clears the FIRs created by DCD calibration, if needed
    FAPI_TRY(mss::workarounds::adr32s::clear_dcd_firs(i_target));

    FAPI_INF("%s Cleared DCD firs", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace adr32s
} // close namespace workarounds
} // close namespace mss
