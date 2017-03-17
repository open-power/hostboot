/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/adr32s_workarounds.H $ */
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
/// @file workarounds/adr32s_workarounds.H
/// @brief Workarounds for the ADR32s logic blocks
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_WORKAROUNDS_ADR32S_H_
#define _MSS_WORKAROUNDS_ADR32S_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

namespace mss
{
///
/// @class adr32sTraits
/// @brief a collection of traits associated with the PHY duty cycle distortion interface
/// @tparam T fapi2::TargetType representing the PHY
///
template< fapi2::TargetType T >
class dutyCycleDistortionTraits;

///
/// @class dutyCycleDistortionTraits
/// @brief a collection of traits associated with the Nimbus PHY duty cycle distortion interface
/// @note normally traits are not done for workarounds, but we need to store the DCD cal registers somewhere and they cross ADR + DP's
///
template<>
class dutyCycleDistortionTraits<fapi2::TARGET_TYPE_MCA>
{
    public:

        // Number of ADR32S units
        static constexpr uint64_t ADR32S_COUNT = 2;

        // All functional duty cycle distortion regs
        static const std::vector<uint64_t> DUTY_CYCLE_DISTORTION_REG;
        static const std::vector<uint64_t> DLL_CONTROL_REG;

        // This fellow is needed for the reset_dcd template, so he's more like a real trait.
        // Default starting place for duty cycle distortion algorithm
        static constexpr uint64_t DCD_ADJUST_DEFAULT = 0b1000000;

        enum
        {
            // DCD register value traits
            DCD_CONTROL_DLL_ADJUST = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ADJUST,
            DCD_CONTROL_DLL_ADJUST_LEN = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ADJUST_LEN,
            DCD_CONTROL_DLL_CORRECT_EN = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CORRECT_EN,
            DCD_CONTROL_DLL_ITER_A = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ITER_A,
            DCD_CONTROL_DLL_COMPARE_OUT = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_COMPARE_OUT,

            // DLL control register settings
            DLL_CAL_UPDATE = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_INIT_RXDLL_CAL_UPDATE,
            DLL_CAL_GOOD   = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_CAL_GOOD,
        };
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
fapi2::ReturnCode clear_dcd_firs( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Sets up the DLL control regs for the DCD calibration
/// @param[in] i_target MCA target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Always needs to be run for DD1.* parts.  unsure for DD2
/// TODO:RTC169173 update DCD calibration for DD2
///
fapi2::ReturnCode setup_dll_control_regs_for_dcd( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Restores the DLL control regs after the DCD calibration
/// @param[in] i_target MCA target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Always needs to be run for DD1.* parts.  unsure for DD2
/// TODO:RTC169173 update DCD calibration for DD2
///
fapi2::ReturnCode restore_dll_control_regs_for_dcd( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Helper to iterate over ADR32S 'sides' when performing DCD cal
/// @param[in] i_target the MCA to iterate for
/// @param[in] i_reg the register (ADR0 or ADR1's register)
/// @param[in] i_seed the seed value for the adjuster
/// @param[in] i_side bool; true if this is side a, false for side b
/// @param[out] o_value the value of the adjuster when the compare bit changes state
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode dcd_cal_helper( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                  const uint64_t i_reg,
                                  const uint64_t i_seed,
                                  const bool i_side,
                                  uint64_t& o_value );

///
/// @brief Perform ADR DCD calibration - Nimbus Only
/// @param[in] i_target the MCBIST (controler) to perform calibration on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode duty_cycle_distortion_calibration( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Sets the value to write out to the DCD register in question
/// @param[in,out] i_a_side_rc - a side's return code - cannot be const due to the fapi logging function modifying the RC
/// @param[in] i_a_side_val - a side's value
/// @param[in,out] i_b_side_rc - b side's return code - cannot be const due to the fapi logging function modifying the RC
/// @param[in] i_b_side_val - b side's value
/// @param[out] o_value - value to use for the DCD register
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Due to DCD algorithm fails due to bad HW, the algorithm is going to do the following
/// 1) Return failing RC's if a and b both failed
/// 2) Use a if b failed
/// 3) Use b if a failed
/// 4) Average if a and b both passed
///
fapi2::ReturnCode compute_dcd_value(fapi2::ReturnCode& io_a_side_rc,
                                    const uint64_t i_a_side_val,
                                    fapi2::ReturnCode& io_b_side_rc,
                                    const uint64_t i_b_side_val,
                                    uint64_t& o_value);
} // close namespace adr32s
} // close namespace workarounds
} // close namespace mss

#endif
