/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_lrdimm_training_helper.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file lib/phy/mss_lrdimm_training.C
/// @brief LRDIMM training implementation
/// Training is very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/phy/mss_lrdimm_training_helper.H>

namespace mss
{

namespace training
{

namespace lrdimm
{

///
/// @brief Sets the comparison on a per-nibble or per-bit level
/// @param[in] i_target the DIMM target
/// @param[in] i_training_level the buffer's training level
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note Sets up buffer control word F6BC4x to do compares on a per-bit level
///
fapi2::ReturnCode set_training_level(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const uint64_t i_training_level)
{
    // Values taken from the JEDEC spec
    constexpr uint64_t TRAINING_LEVEL_POS = 7;
    constexpr uint64_t TRAINING_LEVEL_LEN = 1;

    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    fapi2::buffer<uint8_t> l_bcw_value;
    std::vector<cw_info> l_bcws;
    uint8_t l_sim = 0;

    // Gets the BCW value for the buffer training control word
    FAPI_TRY(eff_dimm_ddr4_f6bc4x(i_target, l_bcw_value));

    // Modifies the BCW value accordingly
    l_bcw_value.insertFromRight<TRAINING_LEVEL_POS, TRAINING_LEVEL_LEN>(i_training_level);
    l_bcws.push_back(cw_info(FUNC_SPACE_6, BUFF_TRAIN_CONFIG_CW, l_bcw_value, mss::tmrc(), mss::CW8_DATA_LEN,
                             cw_info::BCW));

    FAPI_TRY(mss::is_simulation(l_sim));

    // Ensure our CKE's are powered on
    l_program.iv_instructions.push_back(mss::ccs::des_command<fapi2::TARGET_TYPE_MCBIST>());

    // Inserts the function space selects
    FAPI_TRY(mss::ddr4::insert_function_space_select(l_bcws));

    // Sets up the CCS instructions
    FAPI_TRY(control_word_engine(i_target,
                                 l_bcws,
                                 l_sim,
                                 l_program.iv_instructions));

    // Make sure we leave everything powered on
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    // Issue CCS
    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Creates the control words to set the expected MPR pattern into the buffer
/// @param[in] i_pattern the pattern to program into the buffer
/// @return cw_info vector containing the control words used to setup the MPR pattern into the buffer
/// @note Sets up the expected data pattern in buffer control words (F5BC0x,F5BC1x,F5BC2x,F5BC3x, F6BC0x,F6BC1x,F6BC2x,F6BC3x)
///
std::vector<cw_info> set_expected_mpr_pattern(const fapi2::buffer<uint8_t>& i_pattern )
{
    // BCW numbers
    constexpr uint8_t UI0_BCW_NUMBER = 0x0;
    constexpr uint8_t UI1_BCW_NUMBER = 0x1;
    constexpr uint8_t UI2_BCW_NUMBER = 0x2;
    constexpr uint8_t UI3_BCW_NUMBER = 0x3;
    constexpr uint8_t UI4_BCW_NUMBER = 0x0;
    constexpr uint8_t UI5_BCW_NUMBER = 0x1;
    constexpr uint8_t UI6_BCW_NUMBER = 0x2;
    constexpr uint8_t UI7_BCW_NUMBER = 0x3;

    // Pattern being converted into BCW values
    const uint8_t UI0_DATA = i_pattern.getBit<0>() ? 0xFF : 0x00;
    const uint8_t UI1_DATA = i_pattern.getBit<1>() ? 0xFF : 0x00;
    const uint8_t UI2_DATA = i_pattern.getBit<2>() ? 0xFF : 0x00;
    const uint8_t UI3_DATA = i_pattern.getBit<3>() ? 0xFF : 0x00;
    const uint8_t UI4_DATA = i_pattern.getBit<4>() ? 0xFF : 0x00;
    const uint8_t UI5_DATA = i_pattern.getBit<5>() ? 0xFF : 0x00;
    const uint8_t UI6_DATA = i_pattern.getBit<6>() ? 0xFF : 0x00;
    const uint8_t UI7_DATA = i_pattern.getBit<7>() ? 0xFF : 0x00;
    std::vector<cw_info> l_bcws =
    {
        {FUNC_SPACE_5, UI0_BCW_NUMBER, UI0_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_5, UI1_BCW_NUMBER, UI1_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_5, UI2_BCW_NUMBER, UI2_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_5, UI3_BCW_NUMBER, UI3_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_6, UI4_BCW_NUMBER, UI4_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_6, UI5_BCW_NUMBER, UI5_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_6, UI6_BCW_NUMBER, UI6_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
        {FUNC_SPACE_6, UI7_BCW_NUMBER, UI7_DATA, mss::tmrc(), mss::CW8_DATA_LEN, cw_info::BCW},
    };

    return l_bcws;
}

///
/// @brief Sets expected mpr pattern into the buffer
/// @param[in] i_target the DIMM target
/// @param[in] i_pattern the pattern to program into the buffer
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
/// @note Sets up the expected data pattern in buffer control words (F5BC0x,F5BC1x,F5BC2x,F5BC3x, F6BC0x,F6BC1x,F6BC2x,F6BC3x)
///
fapi2::ReturnCode set_expected_mpr_pattern(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const fapi2::buffer<uint8_t>& i_pattern )
{
    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // Creates the BW's for the given pattern
    auto l_bcws = set_expected_mpr_pattern(i_pattern);

    uint8_t l_sim = 0;
    FAPI_TRY(mss::is_simulation(l_sim));

    // Ensure our CKE's are powered on
    l_program.iv_instructions.push_back(mss::ccs::des_command<fapi2::TARGET_TYPE_MCBIST>());

    // Inserts the function space selects
    FAPI_TRY(mss::ddr4::insert_function_space_select(l_bcws));

    // Sets up the CCS instructions
    FAPI_TRY(control_word_engine(i_target,
                                 l_bcws,
                                 l_sim,
                                 l_program.iv_instructions));

    // Make sure we leave everything powered on
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    // Issue CCS
    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           l_mca) );

fapi_try_exit:
    return fapi2::current_err;
}

} // ns training

} // ns lrdimm

} // ns mss
