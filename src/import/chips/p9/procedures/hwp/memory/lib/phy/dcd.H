/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/dcd.H $     */
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
/// @file dcd.H
/// @brief Subroutines duty cycle calibration
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef MSS_DCD_H
#define MSS_DCD_H

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <p9_mc_scom_addresses_fld_fixes.H>
#include <lib/mss_attribute_accessors_manual.H>

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
        static constexpr uint64_t DD1_DCD_ADJUST_DEFAULT = 0b1000000;
        static constexpr uint64_t DD2_DCD_ADJUST_DEFAULT = 0b10000000;

        enum
        {
            // DCD register value traits
            DCD_CONTROL_DLL_ADJUST = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ADJUST,
            DCD_DD1_CONTROL_DLL_ADJUST_LEN = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ADJUST_LEN,
            DCD_CONTROL_DLL_CORRECT_EN = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CORRECT_EN,
            DCD_CONTROL_DLL_ITER_A = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ITER_A,
            DCD_CONTROL_DLL_COMPARE_OUT = MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_COMPARE_OUT,

            // DD2 only values
            DCD_DD2_CONTROL_DLL_ADJUST_LEN = DD2_MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_ADJUST_LEN,
            DCD_DD2_CAL_ENABLE = DD2_MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CAL_ENABLE,
            DCD_DD2_POWERDOWN = DD2_MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_POWERDOWN,
            DCD_DD2_CAL_DONE = DD2_MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CAL_DONE,
            DCD_DD2_CAL_ERROR = DD2_MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0_ADR0_DLL_CAL_ERROR,

            // DLL control register settings
            DLL_CAL_UPDATE = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_INIT_RXDLL_CAL_UPDATE,
            DLL_CAL_GOOD   = MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0_ADR0_CAL_GOOD,
        };
};

namespace dcd
{

///
/// @brief Sets the DCD setting value based upon the design revision of the target
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dutyCycleDistortionTraits<T>
/// @param[in] i_target any level of the Nimbus target (below the chip level)
/// @param[in,out] io_data the value of the register
/// @param[in] i_value the DCD calibration value to set
/// @note This *slightly* breaks the register API as the get/set values vary by design revision of the Nimbus
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dutyCycleDistortionTraits<T> >
inline void set_dcd_value( const fapi2::Target<T>& i_target,
                           fapi2::buffer<uint64_t>& io_data,
                           const uint64_t i_value )
{
    FAPI_INF("DD%s i_value: 0x%lx", mss::chip_ec_nimbus_lt_2_0(i_target) ? "1" : "2", i_value);

    // DD1, use the DD1 values
    if(mss::chip_ec_nimbus_lt_2_0(i_target))
    {
        io_data.insertFromRight<TT::DCD_CONTROL_DLL_ADJUST, TT::DCD_DD1_CONTROL_DLL_ADJUST_LEN>(i_value);
    }
    // Not DD1, use the DD2 values
    else
    {
        io_data.insertFromRight<TT::DCD_CONTROL_DLL_ADJUST, TT::DCD_DD2_CONTROL_DLL_ADJUST_LEN>(i_value);
    }
}

///
/// @brief Gets the DCD setting value based upon the design revision of the target
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dutyCycleDistortionTraits<T>
/// @param[in] i_target any level of the Nimbus target (below the chip level)
/// @param[in] i_data the value of the register
/// @param[out] o_value the DCD calibration value to set
/// @note This *slightly* breaks the register API as the get/set values vary by design revision of the Nimbus
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dutyCycleDistortionTraits<T> >
inline void get_dcd_value( const fapi2::Target<T>& i_target,
                           const fapi2::buffer<uint64_t>& i_data,
                           uint64_t& o_value )
{
    // DD1, use the DD1 values
    if(mss::chip_ec_nimbus_lt_2_0(i_target))
    {
        i_data.extractToRight<TT::DCD_CONTROL_DLL_ADJUST, TT::DCD_DD1_CONTROL_DLL_ADJUST_LEN>(o_value);
    }
    // Not DD1, use the DD2 values
    else
    {
        i_data.extractToRight<TT::DCD_CONTROL_DLL_ADJUST, TT::DCD_DD2_CONTROL_DLL_ADJUST_LEN>(o_value);
    }

    FAPI_INF("DD%s o_value: 0x%lx", mss::chip_ec_nimbus_lt_2_0(i_target) ? "1" : "2", o_value);
}

///
/// @brief Sets up the DLL control regs for the DCD calibration
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dutyCycleDistortionTraits<T>
/// @param[in] i_target target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Always needs to be run for DD1.* parts.  unsure for DD2
/// TK check if this is needed for DD2
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dutyCycleDistortionTraits<T> >
fapi2::ReturnCode setup_dll_control_regs( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Restores the DLL control regs after the DCD calibration
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dutyCycleDistortionTraits<T>
/// @param[in] i_target MCA target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Always needs to be run for DD1.* parts.  unsure for DD2
/// TK check if this is needed for DD2
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dutyCycleDistortionTraits<T> >
fapi2::ReturnCode restore_dll_control_regs( const fapi2::Target<T>& i_target );

///
/// @brief Helper to iterate over a DCD register's 'sides' when performing DCD cal
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dutyCycleDistortionTraits<T>
/// @param[in] i_target the target to iterate for
/// @param[in] i_reg the register (ADR0 or ADR1's register)
/// @param[in] i_seed the seed value for the adjuster
/// @param[in] i_side bool; true if this is side a, false for side b
/// @param[out] o_value the value of the adjuster when the compare bit changes state
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dutyCycleDistortionTraits<T> >
fapi2::ReturnCode sw_cal_side_helper( const fapi2::Target<T>& i_target,
                                      const uint64_t i_reg,
                                      const uint64_t i_seed,
                                      const bool i_side,
                                      uint64_t& o_value );

///
/// @brief Helper to iterate over a DCD register's 'sides' when performing DCD cal
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dutyCycleDistortionTraits<T>
/// @param[in] i_target the target to iterate for
/// @param[in] i_reg the register (ADR0 or ADR1's register)
/// @param[in,out] io_seed the seed value for the adjuster
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dutyCycleDistortionTraits<T> >
fapi2::ReturnCode sw_cal_per_register( const fapi2::Target<T>& i_target,
                                       const uint64_t i_reg,
                                       uint64_t& io_seed);

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

///
/// @brief Polls for done on an individual DCD register and logs passing vs failing results
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dutyCycleDistortionTraits<T>
/// @param[in] i_target the target to iterate for
/// @param[in] i_reg the register (ADR0 or ADR1's register)
/// @param[in,out] io_sum the sum of all good values
/// @param[in,out] io_failing_regs a vector containing all failing registers
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dutyCycleDistortionTraits<T> >
fapi2::ReturnCode poll_for_done_and_log_reg( const fapi2::Target<T>& i_target,
        const uint64_t i_reg,
        uint64_t& io_sum,
        std::vector<uint64_t>& io_failing_regs);

///
/// @brief Polls for done on an individual DCD register and logs passing vs failing results
/// @tparam T fapi2 Target Type - defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to dutyCycleDistortionTraits<T>
/// @param[in] i_target the target to iterate for
/// @param[in] i_data the registers data
/// @param[in] i_reg the register (ADR0 or ADR1's register)
/// @param[in,out] io_sum the sum of all good values
/// @param[in,out] io_failing_regs a vector containing all failing registers
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = dutyCycleDistortionTraits<T> >
void log_reg_results( const fapi2::Target<T>& i_target,
                      const uint64_t i_reg,
                      const fapi2::buffer<uint64_t>& i_data,
                      uint64_t& io_sum,
                      std::vector<uint64_t>& io_failing_regs);

///
/// @brief Kicks off the DCD HW calibration
/// @tparam T fapi2 Target Type
/// @param[in] i_target the target to iterate for
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode execute_hw_calibration( const fapi2::Target<T>& i_target );

} // close namespace dcd
} // close namespace mss

#endif
