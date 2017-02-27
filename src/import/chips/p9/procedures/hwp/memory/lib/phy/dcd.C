/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/dcd.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file dcd.C
/// @brief Subroutines duty cycle calibration
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/phy/dcd.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/utils/poll.H>
#include <lib/utils/conversions.H>
#include <lib/workarounds/adr32s_workarounds.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCBIST;
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

namespace dcd
{

///
/// @brief Sets up the DLL control regs for the DCD calibration - specialization for MCA
/// @param[in] i_target MCA target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Always needs to be run for DD1.* parts.  unsure for DD2
///
template< >
fapi2::ReturnCode setup_dll_control_regs( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
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

        FAPI_TRY(mss::workarounds::adr32s::setup_dll_control_regs( i_target, r ), "%s failed to setup DLL control reg 0x%016lx",
                 mss::c_str(i_target), r);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Restores the DLL control regs after the DCD calibration - specialization for MCA
/// @param[in] i_target MCA target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Always needs to be run for DD1.* parts.  unsure for DD2
///
template< >
fapi2::ReturnCode restore_dll_control_regs( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
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
/// @brief Helper to iterate over ADR32S 'sides' when performing DCD cal - MCA specialization
/// @param[in] i_target the MCA to iterate for
/// @param[in] i_reg the register (ADR0 or ADR1's register)
/// @param[in] i_seed the seed value for the adjuster
/// @param[in] i_side bool; true if this is side a, false for side b
/// @param[out] o_value the value of the adjuster when the compare bit changes state
/// @return FAPI2_RC_SUCCESS iff ok
///
template< >
fapi2::ReturnCode sw_cal_side_helper( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                      const uint64_t i_reg,
                                      const uint64_t i_seed,
                                      const bool i_side,
                                      uint64_t& o_value )
{
    typedef dutyCycleDistortionTraits<TARGET_TYPE_MCA> TT;

    constexpr uint64_t DD1_OVERFLOW = 0b1111111;
    constexpr uint64_t DD2_OVERFLOW = 0b11111111;

    // Having an extra bit in DD2 means that the overflow value changes
    const uint64_t l_dcd_adjust_overflow =  mss::chip_ec_nimbus_lt_2_0(i_target) ? DD1_OVERFLOW : DD2_OVERFLOW;
    constexpr uint64_t l_dcd_adjust_underflow = 0b0000000;

    constexpr uint64_t l_delay = mss::DELAY_100NS;
    const uint64_t l_delay_in_cycles = mss::ns_to_cycles(i_target, l_delay);

    // The DCD algorithm steps until we see a 0 to 1 or 1 to 0 transition
    // 1 means that we need to decrease to get to the 50/50 duty cycle case
    // 0 means that we need to increase to get to the 50/50 duty cycle case
    // If compare out is 0, we tick up ...
    // Signed value which helps us increment or decrement the adjustment
    int64_t l_tick = 1;
    // ... and we expect a transition to 1 (need to decrease to get to the 50/50 duty cycle)
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
    set_dcd_value(i_target, l_read, l_current_adjust);
    l_read.setBit<TT::DCD_CONTROL_DLL_CORRECT_EN>();
    l_read.writeBit<TT::DCD_CONTROL_DLL_ITER_A>(i_side);
    l_read.clearBit<TT::DCD_CONTROL_DLL_COMPARE_OUT>();

    // Sets the DCD calibration bit enable to a 0 if we're in DD2
    if(!mss::chip_ec_nimbus_lt_2_0(i_target))
    {
        l_read.clearBit<TT::DCD_DD2_CAL_ENABLE>();
    }

    FAPI_TRY( mss::putScom(i_target, i_reg, l_read) );

    // Read. Note the register is volatile in that l_read which we just wrote isn't what we'll read
    // as the distortion logic will take the seeded adjustment value and give us information on the next
    // read (so don't get cute and remove this getScom.)
    FAPI_TRY( mss::getScom(i_target, i_reg, l_read) );

    // Based on the 'direction' we're going, we have some values to setup. We setup the bit == 0 case
    // when we initialized these variables above.
    if (l_read.getBit<TT::DCD_CONTROL_DLL_COMPARE_OUT>())
    {
        // If compare out is 1, we tick down ...
        l_tick = -1;

        // ... and we expect a transition to 0 (need to increase to get to the 50/50 duty cycle)
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
        set_dcd_value(i_target, l_read, l_current_adjust + l_tick);
        l_read.clearBit<TT::DCD_CONTROL_DLL_COMPARE_OUT>();
        FAPI_TRY( mss::putScom(i_target, i_reg, l_read) );

        // Wait for valid results...
        FAPI_TRY( fapi2::delay(l_delay, mss::cycles_to_simcycles(l_delay_in_cycles)) );

        // Check our results
        FAPI_TRY( mss::getScom(i_target, i_reg, l_read) );

        // Includes an extra wait for the next loop
        FAPI_TRY( fapi2::delay(l_delay, mss::cycles_to_simcycles(l_delay_in_cycles)) );

        // Gets the current adjustment value
        get_dcd_value(i_target, l_read, l_current_adjust);

    }
    while (l_current_adjust != l_overrun);

    FAPI_ASSERT( l_current_adjust != l_overrun,
                 fapi2::MSS_DUTY_CLOCK_DISTORTION_CAL_FAILED()
                 .set_MCA_TARGET(i_target)
                 .set_CURRENT_ADJUST(l_current_adjust)
                 .set_SIDE(i_side)
                 .set_REGISTER(i_reg)
                 .set_REGISTER_VALUE(l_read),
                 "%s Failed DCD for %s 0x%016lx", mss::c_str(i_target), mss::c_str(i_target), i_reg );

    // If we're here, we were done and there were no errors. So we can return back the current adjust value
    // as the output/result of our operation
    o_value = l_current_adjust;
    FAPI_INF("%s side: %d final adjust value: 0x%x (0x%x)", mss::c_str(i_target), i_side, o_value, l_current_adjust);

    return FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper to iterate over a DCD register's 'sides' when performing DCD cal - MCA specialization
/// @param[in] i_target the target to iterate for
/// @param[in] i_reg the register (ADR0 or ADR1's register)
/// @param[in,out] io_seed the seed value for the adjuster
/// @return FAPI2_RC_SUCCESS iff ok
///
template< >
fapi2::ReturnCode sw_cal_per_register( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                       const uint64_t i_reg,
                                       uint64_t& io_seed)
{
    constexpr bool A_SIDE = true;
    constexpr bool B_SIDE = false;
    typedef dutyCycleDistortionTraits<TARGET_TYPE_MCA> TT;
    uint64_t l_a_side_value = 0;
    uint64_t l_b_side_value = 0;
    fapi2::buffer<uint64_t> l_buff;

    // Fixes the default seed values
    const uint64_t l_default_seed = mss::chip_ec_nimbus_lt_2_0(i_target) ? TT::DD1_DCD_ADJUST_DEFAULT :
                                    TT::DD2_DCD_ADJUST_DEFAULT;

    // Note: per the design and lab teams, we should always start out at our nominal value
    // This is a bit of a workaround given some broken HW in the lab, not sure if it should go in the workaround file
    io_seed = l_default_seed;

    auto l_a_rc = sw_cal_side_helper(i_target, i_reg, io_seed, A_SIDE, l_a_side_value);

    // Updates the seed value to avoid bad hardware issues
    io_seed = (l_a_side_value == 0) ? (io_seed) : (l_a_side_value - 1);

    // We want to seed the other side (and each subsequent port) with the
    // value found in the pervious iteration as that will likely reduce the number
    // of iterations to find the transition. We back up one so that if we're on
    // a transition, we don't 'bounce' from a 1 to a 0. This will give us a good
    // transition if the a-side value is really to be the b-side value too.
    auto l_b_rc = sw_cal_side_helper(i_target, i_reg, io_seed, B_SIDE, l_b_side_value);

    // The final value is the average of the a-side and b-side values.
    FAPI_TRY(compute_dcd_value(l_a_rc, l_a_side_value, l_b_rc, l_b_side_value, io_seed));

    FAPI_INF("%s calibrated value for both sides for reg 0x%016lx cal value: 0x%02x, a_side 0x%02x b_side: 0x%02x",
             mss::c_str(i_target),
             i_reg,
             io_seed,
             l_a_side_value,
             l_b_side_value);

    // Stores the final calibrated values in the register with a RMW
    FAPI_TRY( mss::getScom(i_target, i_reg, l_buff) );
    set_dcd_value(i_target, l_buff, io_seed);
    l_buff.clearBit<TT::DCD_CONTROL_DLL_COMPARE_OUT>();

    // Note this writes all the other values to 0's which is OK for DD1 and DD2
    FAPI_TRY( mss::putScom(i_target, i_reg, l_buff) );

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
    // 1) per lab/design team, we want to return a passing RC
    //  We pass this  hardware as a large amount of HW fails DCD calibration but runs fine without it
    if((io_a_side_rc != FAPI2_RC_SUCCESS) &&
       (io_b_side_rc != FAPI2_RC_SUCCESS))
    {
        // Log a-side and b-side RC's leave the seed as it is
        // Currently not logging a-side b-side issue due to bad hardware?
        // We can still run even if we fail DCD cal fail
        // Recovered flag will make it informational. Deconfigs won't happen and the customer won't see
        // But we will ;)
        FAPI_ERR("Recovered from DCD calibration fail - both side A and side B failed, using prior calibrated value");
        fapi2::logError(io_a_side_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
        fapi2::logError(io_b_side_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
        return FAPI2_RC_SUCCESS;
    }

    // 2) b failed, use a's value
    if(io_b_side_rc != FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("Recovered from DCD calibration fail - side B failed, using side-A's value");
        fapi2::logError(io_b_side_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
        o_value = i_a_side_val;
        return FAPI2_RC_SUCCESS;
    }

    // 3) a failed, use b's value
    if(io_a_side_rc != FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("Recovered from DCD calibration fail - side A failed, using side-B's value");
        fapi2::logError(io_a_side_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
        o_value = i_b_side_val;
        return FAPI2_RC_SUCCESS;
    }

    // 4) average a and b as both passed
    FAPI_DBG("Both sides A/B passed - averaging");
    o_value = (i_a_side_val + i_b_side_val) / 2;
    return FAPI2_RC_SUCCESS;
}

///
/// @brief Logs the passing vs failing results from the hardware DCD calibration
/// @param[in] i_target the target to iterate for
/// @param[in] i_reg the register (ADR0 or ADR1's register)
/// @param[in] i_data the registers data
/// @param[in,out] io_sum the sum of all good values
/// @param[in,out] io_failing_regs a vector containing all failing registers
///
template< >
void log_reg_results( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                      const uint64_t i_reg,
                      const fapi2::buffer<uint64_t>& i_data,
                      uint64_t& io_sum,
                      std::vector<uint64_t>& io_failing_regs)
{
    // Traits definition
    typedef dutyCycleDistortionTraits<TARGET_TYPE_MCA> TT;

    const bool l_failed = i_data.getBit<TT::DCD_DD2_CAL_ERROR>();

    FAPI_INF("%s DCD calibration %s on reg 0x%016lx", mss::c_str(i_target), l_failed ? "passed" : "failed", i_reg);

    // Updates the failing registers if the error bit is set
    if(l_failed)
    {
        io_failing_regs.push_back(i_reg);

        // Set current error, and log it
        FAPI_ASSERT(false,
                    fapi2::MSS_HARDWARE_DUTY_CLOCK_DISTORTION_CAL_FAILED()
                    .set_MCA_TARGET(i_target)
                    .set_REGISTER(i_reg),
                    "DCD hardware calibration failed on %s. register 0x%016lx. Attempting software recovery",
                    mss::c_str(i_target), i_reg);
    }
    // Updates sum if we passed
    else
    {
        uint64_t l_result = 0;
        get_dcd_value(i_target, i_data, l_result);
        io_sum += l_result;
    }

    // Exits out before error handling
    return;

    // Handles the error
fapi_try_exit:
    // Logs the error
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = FAPI2_RC_SUCCESS;
}

///
/// @brief Polls for done on an individual DCD register and logs passing vs failing results - MCA specialization
/// @param[in] i_target the target to iterate for
/// @param[in] i_reg the register (ADR0 or ADR1's register)
/// @param[in,out] io_sum the sum of all good values - note: will not update if DCD calibration fails
/// @param[in,out] io_failing_regs a vector containing all failing registers - note: will not add a value if DCD cal passes
/// @return FAPI2_RC_SUCCESS iff ok
///
template< >
fapi2::ReturnCode poll_for_done_and_log_reg( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        const uint64_t i_reg,
        uint64_t& io_sum,
        std::vector<uint64_t>& io_failing_regs)
{
    // Traits definition
    typedef dutyCycleDistortionTraits<TARGET_TYPE_MCA> TT;

    // Sets fapi2::current_err for safety
    fapi2::current_err = FAPI2_RC_SUCCESS;

    // Poll limit declaration
    // Max number of loops we can have and still pass is going to the bottom (128 down) ,seeing the transition
    // Then going all the way to the top and seeing the transition (256 steps up)
    // Realistically, this is not very likely at all
    constexpr uint64_t POLL_LIMIT = 128 + 256;

    // Declares parameters for the polling
    auto l_poll = mss::poll_parameters(DELAY_100NS,
                                       DELAY_100NS,
                                       DELAY_100NS,
                                       DELAY_100NS,
                                       POLL_LIMIT);
    fapi2::buffer<uint64_t> l_result;

    // Polls for DCD finished
    const auto l_poll_finished = mss::poll(i_target,
                                           i_reg,
                                           l_poll,
                                           [&l_result, &i_reg](const size_t poll_remaining,
                                                   const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("DCD register 0x%016lx calibration reg value 0x%016llx, remaining: %d", i_reg, stat_reg, poll_remaining);
        l_result = stat_reg;
        return stat_reg.getBit<TT::DCD_DD2_CAL_DONE>();
    });

    // If the polling didn't finish, exit out with an error
    FAPI_ASSERT( l_poll_finished,
                 fapi2::MSS_HARDWARE_DUTY_CLOCK_DISTORTION_CAL_TIMEOUT()
                 .set_MCA_TARGET(i_target)
                 .set_REGISTER(i_reg),
                 "Timed out in hardware DCD for %s 0x%016lx", mss::c_str(i_target), i_reg );

    // Otherwise, log the information about these results
    log_reg_results(i_target, i_reg, l_result, io_sum, io_failing_regs);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Kicks off the DCD HW calibration - MCA specialization
/// @param[in] i_target the target to iterate for
/// @return FAPI2_RC_SUCCESS iff ok
///
template< >
fapi2::ReturnCode execute_hw_calibration( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    // Traits definition
    typedef dutyCycleDistortionTraits<TARGET_TYPE_MCA> TT;

    // DCD hardware calibration is a three step process:
    // 1) kick off cal on all the registers
    // 2) poll for done on all of the registers - add failing regs into a vector for the workaround/log the results and make an average of all good regs
    //    Note: step 2 is done separately from 1 to speed up the polling process - it will take some time to kick off all DCD's, so all calibrations are started before polling
    // 3) loop through the list of failing DCD regs and do the software calibration

    // Variable declaration
    uint64_t l_good_sum = 0;
    uint64_t l_good_average = 0;
    std::vector<uint64_t> l_failing_registers;

    // 1) kick off cal on all the registers
    {
        // Default value of the mid point of our range, hit the SW cal enable and is present bits (bits 8/10 in phy nomenclature)
        constexpr uint64_t DCD_CAL_ON = 0x80a0;
        FAPI_TRY(mss::scom_blastah(i_target, TT::DUTY_CYCLE_DISTORTION_REG, DCD_CAL_ON), "%s failed to start DCD calibration",
                 mss::c_str(i_target));
    }

    // 2) poll for done on all of the registers - add failing regs into a vector for the workaround/log the results and make an average of all good regs
    // Loops through each DCD register and checks to see if calibration is done
    // Additionally, updates the sum if this DCD call error is cleared, but logs a failing register if the error bit is set
    for(const auto& l_reg : TT::DUTY_CYCLE_DISTORTION_REG)
    {
        FAPI_TRY(poll_for_done_and_log_reg(i_target, l_reg, l_good_sum, l_failing_registers),
                 "%s failed to poll for DCD done properly on reg 0x%016lx", mss::c_str(i_target), l_reg);
    }

    // Computes the average - current we have the sum of all good values, we need to divide by the number of passing regs
    {
        // The number of good registers is the number of registers minus the number of failing registers
        const uint64_t l_num_good_regs = TT::DUTY_CYCLE_DISTORTION_REG.size() - l_failing_registers.size();
        l_good_average = l_good_sum / l_num_good_regs;
        FAPI_INF("%s the number of failing regs %lu the number of good regs %lu the sum %lu and the good average %lu",
                 mss::c_str(i_target), l_failing_registers.size(), l_num_good_regs, l_good_sum, l_good_average);
    }

    // 3) loop through the list of failing DCD regs and do the software calibration
    for(const auto& l_reg : l_failing_registers)
    {
        // Copies the seed so we can preserve the average
        uint64_t l_seed = l_good_average;
        FAPI_INF("%s executing software calibration on failing register 0x%016lx with seed of %lu",
                 mss::c_str(i_target), l_reg, l_seed);
        FAPI_TRY(sw_cal_per_register(i_target, l_reg, l_seed),
                 "%s failed to execute the software DCD calibration on register 0x%016lx", mss::c_str(i_target), l_reg);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Kicks off the DCD HW calibration - MCBIST specialization
/// @param[in] i_target the target to iterate for
/// @return FAPI2_RC_SUCCESS iff ok
///
template< >
fapi2::ReturnCode execute_hw_calibration( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    // First, check if we're a DD1 level of a Nimbus part, if so, skip this calibration as it does not exist
    if(mss::chip_ec_nimbus_lt_2_0(i_target))
    {
        FAPI_INF("%s skipping hardware DCD calibration as this is a DD2 module", mss::c_str(i_target));
        return FAPI2_RC_SUCCESS;
    }

    // Now that we know we are a DD2 Nimbus part, run DCD calibration on each port individually
    // Note: we might have been able to speed this up by running on all ports at the same time, but it would make the code much more complex
    for(const auto& l_mca : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        FAPI_TRY(setup_dll_control_regs(l_mca), "%s failed to setup the DLLs for DCD calibration!", mss::c_str(l_mca));
        FAPI_TRY(execute_hw_calibration(l_mca), "%s failed to run DCD calibration!", mss::c_str(l_mca));
        FAPI_TRY(restore_dll_control_regs(l_mca), "%s failed to restore the DLLs for DCD calibration!", mss::c_str(l_mca));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace dcd
} // close namespace mss
