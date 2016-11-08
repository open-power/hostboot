/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/dp16_workarounds.H $ */
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
/// @file workarounds/dp16.H
/// @brief Workarounds for the DP16 logic blocks
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_WORKAROUNDS_DP16_H_
#define _MSS_WORKAROUNDS_DP16_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <mss_attribute_accessors.H>

namespace mss
{

namespace workarounds
{

namespace dp16
{

///
/// @brief DQS polarity workaround
/// For Monza DDR port 2, one pair of DQS P/N is swapped polarity.  Not in DDR port 6
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note This function is called during the phy scom init procedure, after the initfile is
/// processed. It is specific to the Monza module, but can be called for all modules as it
/// will enforce its requirements internally
///
fapi2::ReturnCode dqs_polarity( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief DP16 Read Diagnostic Configuration 5 work around
/// Not in the Model 67 spydef, so we scom them. Should be removed when they are
/// added to the spydef.
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode rd_dia_config5( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief DP16 DQSCLK Offset work around
/// Not in the Model 67 spydef, so we scom them. Should be removed when they are
/// added to the spydef.
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode dqsclk_offset( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief DP16 DLL_VREG_CONTROL0
/// In DD1.0 Nimbus VREG control work arounds are needed
/// @param[in] port in question - needed to figure out whether to apply the work-around or not
/// @param[in] i_original_value a value to which we add the workaround bits
/// @return uint64_t the original value with the bits added
///
inline uint64_t vreg_control0( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_original_value )
{
    fapi2::buffer<uint64_t> l_value(i_original_value);
    uint8_t l_vccd_override = 0;

    // Check for whether we apply this workaround or not
    if (! mss::chip_ec_feature_mss_vccd_override(i_target) )
    {
        return i_original_value;
    }

    FAPI_TRY( mss::vccd_override(l_vccd_override) );

    // No VCCD override, don't mess with the DLL's
    if (fapi2::ENUM_ATTR_MSS_VCCD_OVERRIDE_YES == l_vccd_override)
    {
        l_value.insertFromRight<MCA_DDRPHY_DP16_DLL_VREG_CONTROL0_P0_0_01_RXREG_REF_SEL_DC,
                                MCA_DDRPHY_DP16_DLL_VREG_CONTROL0_P0_0_01_RXREG_REF_SEL_DC_LEN>(0b111);
    }

    FAPI_INF("vreg_control0 0x%016lx, 0x%016lx", i_original_value, uint64_t(l_value));
    return l_value;

fapi_try_exit:
    // Probably bigger problems ...
    FAPI_ERR("Unable to get vccd_override attribute");
    fapi2::Assert(false);

    // Not reached
    return 0;

}

///
/// @brief DP16 VREF DAC override
/// In DD1.0 Nimbus VREF DAC work arounds are needed
/// @param[in] i_target the port target for this override
/// @param[in] i_original_value a value to which we add the workaround bits
/// @return uint64_t the original value with the bits added
///
inline uint64_t vref_dac( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const uint64_t i_original_value )
{
    fapi2::buffer<uint64_t> l_value(i_original_value);

    // Check for whether we apply this workaround or not
    if (! mss::chip_ec_feature_mss_vref_dac(i_target) )
    {
        return i_original_value;
    }

    // We have an attribute for VREF DAC nibble, if it's 0 then we'll not do anything
    uint8_t l_vref_dac_nibble = 0;
    FAPI_TRY( mss::vref_dac_nibble(l_vref_dac_nibble) );

    // We want to set the EN_FORCE on no matter what.
    l_value.setBit<MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB0_EN_FORCE>()
    .setBit<MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB1_EN_FORCE>();

    // But we only give a new value if they asked for one in the attribute
    if (l_vref_dac_nibble != 0)
    {
        l_value.insertFromRight<MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB0,
                                MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB0_LEN>(l_vref_dac_nibble)
                                .insertFromRight<MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB1,
                                MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB1_LEN>(l_vref_dac_nibble);
    }

    FAPI_INF("vref_dac 0x%016lx, 0x%016lx", i_original_value, uint64_t(l_value));
    return l_value;

fapi_try_exit:
    // Probably bigger problems ...
    FAPI_ERR("Unable to get vref_dac_nibble attribute");
    fapi2::Assert(false);

    // Not reached
    return 0;
}

///
/// @brief DP16 VREG Coarse override
/// In DD1.0 Nimbus VREG Coarse work arounds are needed
/// @param[in] i_target the port target for this override
/// @param[in] i_original_value a value to which we add the workaround bits
/// @return uint64_t the original value with the bits added
///
inline uint64_t vreg_coarse( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const uint64_t i_original_value )
{
    fapi2::buffer<uint64_t> l_value(i_original_value);
    uint8_t l_vccd_override = 0;

    // Check for whether we apply this workaround or not
    if (! mss::chip_ec_feature_mss_vreg_coarse(i_target) )
    {
        return i_original_value;
    }

    FAPI_TRY( mss::vccd_override(l_vccd_override) );

    if (fapi2::ENUM_ATTR_MSS_VCCD_OVERRIDE_YES == l_vccd_override)
    {
        l_value.insertFromRight<MCA_DDRPHY_ADR_DLL_VREG_COARSE_P0_ADR32S0_ADR0_REGS_RXDLL_DAC,
                                MCA_DDRPHY_ADR_DLL_VREG_COARSE_P0_ADR32S0_ADR0_REGS_RXDLL_DAC_LEN>(0b0000100);
    }

    FAPI_INF("vref_coarse 0x%016lx, 0x%016lx", i_original_value, uint64_t(l_value));
    return l_value;

fapi_try_exit:
    // Probably bigger problems ...
    FAPI_ERR("Unable to get vccd_override attribute");
    fapi2::Assert(false);

    // Not reached
    return 0;
}

///
/// @brief DP16 workarounds to be run after PHY reset
/// In DD1.0 Nimbus various work arounds are needed
/// @param[in] i_target the fapi2 target of the controller
/// @return fapi2::ReturnValue FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode after_phy_reset( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

namespace wr_vref
{

///
/// @brief DP16 WR VREF error latching workaround
/// In DD1 Nimbus in the WR VREF algorithm, DRAM's 2/3 latch over error information from DRAM's 0/1.
/// The workaround is to set the error mask for DRAM's 2/3 to be 0xFFFF (informational but not errors)
/// @param[in] i_target the fapi2 target type MCA of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode error_dram23( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief DP16 big step/small step check and modify workaround
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure that the big step is divisible by the small step
/// This function converts the small step value over to the closest allowable value as to what was entered
/// @tparam T fapi2 Target Type - just here to ensure that this won't be called on a non-Nimbus system
/// @param[in] i_big_step - WR VREF big step value
/// @param[in,out] io_small_step - WR VREF small step value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode modify_small_step_for_big_step(const uint8_t i_big_step, uint8_t& io_small_step);

///
/// @brief DP16 writes config 0 overriding bad small step/big step values
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure that the big step is divisible by the small step
/// This function converts the small step value over to the closest allowable value as to what was entered
/// @param[in] i_target the fapi2 target type MCA of the port
/// @param[out] o_big_step - WR VREF big step value
/// @param[out] o_small_step - WR VREF small step value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode write_config0( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, uint8_t& o_big_step,
                                 uint8_t& o_small_step);

///
/// @brief DP16 converts the VREF training values to start calibration
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure the WR VREF is an integer number of big steps away from the 0 value and one big step from the top of the range
/// This function converts values over to the required rules
/// @tparam T fapi2 Target Type - just here to ensure that this won't be called on a non-Nimbus system
/// @param[in] i_big_step - WR VREF big step value
/// @param[in,out] io_train_range - VREF train range converted value
/// @param[in,out] io_train_value - VREF train value converted value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode convert_train_values( const uint8_t i_big_step,
                                        uint8_t& io_train_range,
                                        uint8_t& io_train_value);

///
/// @brief DP16 gets the VREF training values to start calibration
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure the WR VREF is an integer number of big steps away from the 0 value and one big step from the top of the range
/// This function gets and converts the train values over to good values
/// @param[in] i_target the fapi2 target type MCA of the port
/// @param[in] i_big_step - WR VREF big step value
/// @param[out] o_train_range - JEDEC MR6 WR VREF training range
/// @param[out] o_train_value - JEDEC MR6 WR VREF training value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode get_train_values( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const uint64_t i_rp,
                                    const uint8_t i_big_step,
                                    uint8_t& o_train_range,
                                    uint8_t& o_train_value);

///
/// @brief DP16 sets up the VREF train range and value. also sets up the VREF value registers
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure the WR VREF is an integer number of big steps away from the 0 value and one big step from the top of the range
/// This function converts the WR VREF values over to be good values and writes the good values out to the chip
/// @param[in] i_target the fapi2 target type MCA of the port
/// @param[in] i_rp - rank pair to check and modify
/// @param[out] o_train_range - JEDEC MR6 WR VREF training range
/// @param[out] o_train_value - JEDEC MR6 WR VREF training value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode setup_values( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_rp,
                                uint8_t& o_train_range,
                                uint8_t& o_train_value);

} // close namespace wr_vref
} // close namespace dp16
} // close namespace workarounds
} // close namespace mss

#endif
