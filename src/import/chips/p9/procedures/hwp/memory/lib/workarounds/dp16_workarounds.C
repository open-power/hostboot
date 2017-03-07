/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/dp16_workarounds.C $ */
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
/// @file workarounds/dp16.C
/// @brief Workarounds for the DP16 logic blocks
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/utils/scom.H>
#include <lib/utils/pos.H>
#include <lib/workarounds/dp16_workarounds.H>
#include <lib/phy/dp16.H>
#include <lib/dimm/rank.H>

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
fapi2::ReturnCode dqs_polarity( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // Receiver config provided by S. Wyatt 8/16
    constexpr uint64_t rx_config = 0x4000;

    // For Monza DDR port 2, one pair of DQS P/N is swapped polarity.  Not in DDR port 6
    // For Monza DDR port 3, one pair of DQS P/N is swapped polarity.  Not in DDR port 7
    const auto l_pos = mss::pos(i_target);

    if (! mss::chip_ec_feature_mss_dqs_polarity(i_target) )
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // So we need to make sure our position is 2 or 3 and skip for the other ports.
    if (l_pos == 2)
    {
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_DP16_RX_PEAK_AMP_P0_4, rx_config) );
    }

    if (l_pos == 3)
    {
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_DP16_RX_PEAK_AMP_P0_0, rx_config) );
    }

    // Can't just return current_err, if we're not ports 2,3 we didn't touch it ...
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Modifies the VREF sense bit based upon the passed in value
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_state the state to set bit 62 to
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note this is a helper function to reduce repeated code in cleanup and workaround functions below
///
fapi2::ReturnCode modify_vref_sense(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const mss::states i_state )
{
    // Runs the cleanup here
    static const std::vector<uint64_t> l_addrs =
    {
        MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_0,
        MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_1,
        MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_2,
        MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_3,
        MCA_DDRPHY_DP16_DATA_BIT_DIR1_P0_4,
    };

    // Note: this bit does not exist in our scom def, so constexpr'ing it here
    constexpr uint64_t VREFSENSE_BIT = 62;

    for(const auto& l_reg : l_addrs)
    {
        fapi2::buffer<uint64_t> l_data;

        // Gets the data
        FAPI_TRY(mss::getScom(i_target, l_reg, l_data));

        // Modifies the data
        l_data.writeBit<VREFSENSE_BIT>(i_state);

        // Writes the data
        FAPI_TRY(mss::putScom(i_target, l_reg, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Workarounds for after training
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note This function is called after training - it will only be run after coarse wr/rd
///
fapi2::ReturnCode rd_vref_vref_sense_cleanup( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // If the workaround does not need to be run, return success
    if(mss::chip_ec_feature_skip_rd_vref_vrefsense_override(i_target))
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Per Ryan King, this needs to be set to OFF for mainline mode
    return modify_vref_sense(i_target, mss::states::OFF);
}

///
/// @brief Sets up the VREF sense values before training
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note This function is called before training
///
fapi2::ReturnCode rd_vref_vref_sense_setup( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // If the workaround does not need to be run, return success
    if(mss::chip_ec_feature_skip_rd_vref_vrefsense_override(i_target))
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Per Ryan King, this needs to be set to ON to run training
    return modify_vref_sense(i_target, mss::states::ON);
}

///
/// @brief Workarounds for after training
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_cal_steps_enable the enabled cal steps
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note This function is called after training - it will only be run after coarse wr/rd
///
fapi2::ReturnCode post_training_workarounds( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const fapi2::buffer<uint16_t>& i_cal_steps_enabled )
{
    // Only runs on the last cal steps (coarse wr/rd)
    if (i_cal_steps_enabled.getBit<mss::cal_steps::COARSE_RD>() ||
        i_cal_steps_enabled.getBit<mss::cal_steps::COARSE_WR>())
    {
        FAPI_TRY( mss::workarounds::dp16::modify_calibration_results( i_target ) );
        FAPI_TRY( mss::workarounds::dp16::rd_vref_vref_sense_cleanup( i_target ) );
    }

    // Returns success, as we might not have run these workarounds, depending upon cal step enable
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief DP16 Read Diagnostic Configuration 5 work around
/// Not in the Model 67 spydef, so we scom them. Should be removed when they are
/// added to the spydef.
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode rd_dia_config5( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // Config provided by S. Wyatt 8/16
    // 8 corresponds to bit 52 and is a workaround for periodic calibration related fails.
    // 4 corresponds to bit 49 and is a workaround to keep the DQ/DQS always terminated
    // Currently, it looks like these workarounds will be required for all versions of Nimbus, so just hard coding it
    constexpr uint64_t rd_dia_config = 0x4810;

    // Not checking fo EC level as this isn't an EC feature workaround, it's a incorrect documentation workaround.
    static const std::vector<uint64_t> l_addrs =
    {
        MCA_DDRPHY_DP16_RD_DIA_CONFIG5_P0_0,
        MCA_DDRPHY_DP16_RD_DIA_CONFIG5_P0_1,
        MCA_DDRPHY_DP16_RD_DIA_CONFIG5_P0_2,
        MCA_DDRPHY_DP16_RD_DIA_CONFIG5_P0_3,
        MCA_DDRPHY_DP16_RD_DIA_CONFIG5_P0_4,
    };

    FAPI_TRY( mss::scom_blastah(i_target, l_addrs, rd_dia_config) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief DP16 DQSCLK Offset work around
/// Not in the Model 67 spydef, so we scom them. Should be removed when they are
/// added to the spydef.
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode dqsclk_offset( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // Config provided by S. Wyatt 9/13
    constexpr uint64_t offset_val = 0x0800;

    // Not checking fo EC level as this isn't an EC feature workaround, it's a incorrect documentation workaround.
    static const std::vector<uint64_t> l_addrs =
    {
        MCA_DDRPHY_DP16_DQSCLK_OFFSET_P0_0,
        MCA_DDRPHY_DP16_DQSCLK_OFFSET_P0_1,
        MCA_DDRPHY_DP16_DQSCLK_OFFSET_P0_2,
        MCA_DDRPHY_DP16_DQSCLK_OFFSET_P0_3,
        MCA_DDRPHY_DP16_DQSCLK_OFFSET_P0_4,
    };

    FAPI_TRY( mss::scom_blastah(i_target, l_addrs, offset_val) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief DP16 workarounds to be run after PHY reset
/// In DD1.0 Nimbus various work arounds are needed
/// @param[in] i_target the fapi2 target of the controller
/// @return fapi2::ReturnValue FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode after_phy_reset( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;

    uint8_t l_sim = 0;
    FAPI_TRY( mss::is_simulation(l_sim) );

    // This is a collection or workarounds called after phy reset is called. Each individual workaround
    // below does its own checking for applicable feature/ec levels.
    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        std::vector< std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t>> > l_vreg_coarse;
        std::vector< std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t>> > l_vref_cntl;

        // Fix up vref dac
        if (!l_sim)
        {
            FAPI_TRY( mss::scom_suckah(p, TT::RD_VREF_CNTRL_REG, l_vref_cntl) );
            std::for_each(l_vref_cntl.begin(), l_vref_cntl.end(),
                          [&p](std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> >& v)
            {
                // Checks for EC level
                v.first  = mss::workarounds::dp16::vref_dac(p, v.first);
                v.second = mss::workarounds::dp16::vref_dac(p, v.second);
            });
            FAPI_TRY( mss::scom_blastah(p, TT::RD_VREF_CNTRL_REG, l_vref_cntl) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Fixes blue waterfall values in a port
/// @param[in] i_target - the target to operate on
/// @param[in] i_always_run - ignores the attribute and always run - default = false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode fix_blue_waterfall_gate( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const bool i_always_run )
{
    // Checks if the workaround needs to be run
    const bool l_attr_value = mss::chip_ec_feature_blue_waterfall_adjust(i_target);

    if(!l_attr_value && !i_always_run)
    {
        FAPI_DBG("Skipping running fix_blue_waterfall_gate i_always_run %s attr %s", i_always_run ? "true" : "false",
                 l_attr_value ? "true" : "false" );
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Loops through the first 4 DP's as the last DP is a DP08 so we only need to do 2 quads
    // TK update to hit all rank pairs
    const std::vector<std::vector<std::pair<uint64_t, uint64_t>>> l_dp16_registers =
    {
        {
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_0},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_1, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_1},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_2, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_2},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_3, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_3},
        },
        {
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_0, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP1_P0_0},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_1, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP1_P0_1},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_2, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP1_P0_2},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_3, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP1_P0_3},
        },
        {
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_0, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP2_P0_0},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_1, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP2_P0_1},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_2, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP2_P0_2},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_3, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP2_P0_3},
        },
        {
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_0, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP3_P0_0},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_1, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP3_P0_1},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_2, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP3_P0_2},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_3, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP3_P0_3},
        },
    };
    const std::vector<std::pair<uint64_t, uint64_t>> l_dp08_registers =
    {
        {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_4, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP0_P0_4},
        {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_4, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP1_P0_4},
        {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_4, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP2_P0_4},
        {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_4, MCA_DDRPHY_DP16_DQS_GATE_DELAY_RP3_P0_4},
    };

    // Gets the number of primary ranks to loop through
    std::vector<uint64_t> l_primary_ranks;
    FAPI_TRY(mss::rank::primary_ranks(i_target, l_primary_ranks));

    // Loops through all configured rank pairs
    for(uint64_t l_rp = 0; l_rp < l_primary_ranks.size(); ++l_rp)
    {
        // Loops through all DP16s
        for(const auto& l_reg : l_dp16_registers[l_rp])
        {
            fapi2::buffer<uint64_t> l_waterfall;
            fapi2::buffer<uint64_t> l_gate_delay;

            // Getscoms
            FAPI_TRY(mss::getScom(i_target, l_reg.first, l_waterfall), "Failed to getScom from 0x%016lx", l_reg.first);
            FAPI_TRY(mss::getScom(i_target, l_reg.second, l_gate_delay), "Failed to getScom from 0x%016lx", l_reg.second);

            // Updates the data for all quads
            update_blue_waterfall_gate_delay_for_quad<0>(l_waterfall, l_gate_delay);
            update_blue_waterfall_gate_delay_for_quad<1>(l_waterfall, l_gate_delay);
            update_blue_waterfall_gate_delay_for_quad<2>(l_waterfall, l_gate_delay);
            update_blue_waterfall_gate_delay_for_quad<3>(l_waterfall, l_gate_delay);

            // Putscoms
            FAPI_TRY(mss::putScom(i_target, l_reg.first, l_waterfall), "Failed to putScom to 0x%016lx", l_reg.first);
            FAPI_TRY(mss::putScom(i_target, l_reg.second, l_gate_delay), "Failed to putScom to 0x%016lx", l_reg.second);
        }

        // Now for the odd man out - the DP08, as it only has two quads.
        // Note: We are not modifying the non-existant quads, as changing values in the non-existant DP08 has caused FIRs
        {
            fapi2::buffer<uint64_t> l_waterfall;
            fapi2::buffer<uint64_t> l_gate_delay;

            // Getscoms
            FAPI_TRY(mss::getScom(i_target, l_dp08_registers[l_rp].first, l_waterfall), "Failed to getScom from 0x%016lx",
                     l_dp08_registers[l_rp].first);
            FAPI_TRY(mss::getScom(i_target, l_dp08_registers[l_rp].second, l_gate_delay), "Failed to getScom from 0x%016lx",
                     l_dp08_registers[l_rp].second);

            // Updates the data for all quads
            update_blue_waterfall_gate_delay_for_quad<0>(l_waterfall, l_gate_delay);
            update_blue_waterfall_gate_delay_for_quad<1>(l_waterfall, l_gate_delay);

            // Putscoms
            FAPI_TRY(mss::putScom(i_target, l_dp08_registers[l_rp].first, l_waterfall), "Failed to putScom to 0x%016lx",
                     l_dp08_registers[l_rp].first);
            FAPI_TRY(mss::putScom(i_target, l_dp08_registers[l_rp].second, l_gate_delay), "Failed to putScom to 0x%016lx",
                     l_dp08_registers[l_rp].second);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Modifies HW calibration results based upon workarounds
/// @param[in]  i_target - the target to operate on
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode modify_calibration_results( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    return fix_blue_waterfall_gate( i_target );
}

namespace wr_vref
{

///
/// @brief DP16 WR VREF error latching workaround
/// In DD1 Nimbus in the WR VREF algorithm, DRAM's 2/3 latch over error information from DRAM's 0/1.
/// The workaround is to set the error mask for DRAM's 2/3 to be 0xFFFF (informational but not errors)
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode error_dram23( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // constants to pretty up code
    constexpr uint64_t DP0 = 0;
    constexpr uint64_t DP1 = 1;
    constexpr uint64_t DP2 = 2;
    constexpr uint64_t DP3 = 3;
    constexpr uint64_t DP4 = 4;
    constexpr uint64_t DRAM23 = 2;
    // disable errors in the reg
    constexpr uint64_t DISABLE_ERRORS = 0xffff;

    // EC level taken care of in the caller

    // note DRAM's 2/3 use the same scom register, so only one scom is needed per DP
    // extra paretheses keep FAPI_TRY happy for two parameter template functions
    FAPI_TRY((mss::dp16::write_wr_vref_error_mask<DP0, DRAM23>(i_target, DISABLE_ERRORS)));
    FAPI_TRY((mss::dp16::write_wr_vref_error_mask<DP1, DRAM23>(i_target, DISABLE_ERRORS)));
    FAPI_TRY((mss::dp16::write_wr_vref_error_mask<DP2, DRAM23>(i_target, DISABLE_ERRORS)));
    FAPI_TRY((mss::dp16::write_wr_vref_error_mask<DP3, DRAM23>(i_target, DISABLE_ERRORS)));
    FAPI_TRY((mss::dp16::write_wr_vref_error_mask<DP4, DRAM23>(i_target, DISABLE_ERRORS)));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief DP16 big step/small step check and modify workaround - MCA specialization
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure that the big step is divisible by the small step
/// This function converts the small step value over to the closest allowable value as to what was entered
/// @param[in] i_big_step - WR VREF big step value
/// @param[in,out] io_small_step - WR VREF small step value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template<  >
fapi2::ReturnCode modify_small_step_for_big_step<fapi2::TARGET_TYPE_MCA>(const uint8_t i_big_step,
        uint8_t& io_small_step)
{
    // EC level taken care of in the caller

    // Step size constants
    constexpr uint8_t MAX_BIG_STEP = 0x10;
    constexpr uint8_t MAX_SMALL_STEP = 0x08;

    // Conversion over to the nearest allowable small step
    // The algorithm takes the register value + 1 when it runs.
    // This avoids cases where it would infinite loop if it had a 0 value in the register
    // As such, the math to figure out if a big/small step combination is allowed is ((big_step + 1) %
    // (small_step + 1)) == 0
    // This below chart takes the allowable combinations or the next smallest allowable value.
    constexpr uint8_t SMALL_STEP_CONVERSION[MAX_BIG_STEP][MAX_SMALL_STEP] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 1, 1, 1, 1, 1, 1, 1,},
        {0, 0, 2, 2, 2, 2, 2, 2,},
        {0, 1, 1, 3, 3, 3, 3, 3,},
        {0, 0, 0, 0, 4, 4, 4, 4,},
        {0, 1, 2, 2, 2, 5, 5, 5,},
        {0, 0, 0, 0, 0, 0, 6, 6,},
        {0, 1, 1, 3, 3, 3, 3, 7,},
        {0, 0, 2, 2, 2, 2, 2, 2,},
        {0, 1, 1, 1, 4, 4, 4, 4,},
        {0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 1, 2, 3, 3, 5, 5, 5,},
        {0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 1, 1, 1, 1, 1, 6, 6,},
        {0, 0, 2, 2, 4, 4, 4, 4,},
        {0, 1, 1, 3, 3, 3, 3, 7,},
    };

    // Makes sure that the values passed in were not out of range
    if(MAX_BIG_STEP <= i_big_step)
    {
        FAPI_TRY(fapi2::FAPI2_RC_INVALID_PARAMETER, "WR VREF %s step is out of range. %s step 0x%02x max", "big", "big",
                 i_big_step);
    }

    if(MAX_SMALL_STEP <= io_small_step)
    {
        FAPI_TRY(fapi2::FAPI2_RC_INVALID_PARAMETER, "WR VREF %s step is out of range. %s step 0x%02x max", "small", "small",
                 io_small_step);
    }

    // Converts the value
    io_small_step = SMALL_STEP_CONVERSION[i_big_step][io_small_step];

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

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
                                 uint8_t& o_small_step)
{
    // EC level taken care of in the caller

    // Traits declaration
    typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;

    // Variable declaration
    fapi2::buffer<uint64_t> l_data;

    // Reads the register - note assumes ALL DP's have the same value. Will overwrite different values
    FAPI_TRY(mss::dp16::read_wr_vref_config0<0>(i_target, l_data));

    // Sets these values to 0's to avoid undesired values
    o_small_step = 0;
    o_big_step = 0;

    // Gets out the current values of the big and small step
    l_data.extractToRight<TT::WR_VREF_CONFIG0_2D_SMALL_STEP_VAL, TT::WR_VREF_CONFIG0_2D_SMALL_STEP_VAL_LEN>(o_small_step)
    .extractToRight<TT::WR_VREF_CONFIG0_2D_BIG_STEP_VAL, TT::WR_VREF_CONFIG0_2D_BIG_STEP_VAL_LEN>(o_big_step);

    // Does the workaround conversion
    FAPI_TRY(modify_small_step_for_big_step<fapi2::TARGET_TYPE_MCA>(o_big_step, o_small_step));

    // Sets up the good values
    l_data.insertFromRight<TT::WR_VREF_CONFIG0_2D_SMALL_STEP_VAL, TT::WR_VREF_CONFIG0_2D_SMALL_STEP_VAL_LEN>(o_small_step)
    .insertFromRight<TT::WR_VREF_CONFIG0_2D_BIG_STEP_VAL, TT::WR_VREF_CONFIG0_2D_BIG_STEP_VAL_LEN>(o_big_step);

    // Blasts em out
    FAPI_TRY(scom_blastah(i_target, TT::WR_VREF_CONFIG0_REG, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

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
template <>
fapi2::ReturnCode convert_train_values<fapi2::TARGET_TYPE_MCA>( const uint8_t i_big_step,
        uint8_t& io_train_range,
        uint8_t& io_train_value)
{
    // EC level taken care of in the caller

    // Number of big steps
    constexpr uint8_t NUM_BIG_STEP = 16;

    // Value at which Range 2 equals Range 1's 0 value
    constexpr uint8_t CROSSOVER_RANGE = 0b011000;

    // List of allowable maximum ranges.  The math is max = (absolute_max - (big_step_val + 1)) -
    // (absolute_max - (big_step_val + 1)) % (big_step_val + 1)
    constexpr uint8_t l_max_allowable_values[NUM_BIG_STEP] =
    {
        73, 72, 69, 68,
        65, 66, 63, 64,
        63, 60, 55, 60,
        52, 56, 45, 48,
    };

    // Declares temporary variable
    uint8_t l_continuous_range = 0;
    const uint8_t l_big_step_alg = i_big_step + 1;

    // Errors out if the big step is out of range
    FAPI_TRY(i_big_step < NUM_BIG_STEP ? fapi2::FAPI2_RC_SUCCESS : fapi2::FAPI2_RC_INVALID_PARAMETER,
             "Big step of %d passed in. Max allowable value is %d", i_big_step, NUM_BIG_STEP - 1);

    // Converts the values over to the algorithm's continuous range
    l_continuous_range = io_train_range == fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE1 ?
                         (io_train_value + CROSSOVER_RANGE) : (io_train_value);

    // Does the math for what makes a good continuous range
    // At least 1 big step away from the top of the range
    l_continuous_range = std::min(l_continuous_range, l_max_allowable_values[i_big_step]);

    // At least 1 big step away from the bottom of the range
    l_continuous_range = std::max(l_continuous_range, l_big_step_alg);

    // Moves to be an even number of big steps away
    l_continuous_range -= (l_continuous_range % l_big_step_alg);

    // Now converts the range/value from the continuous range - defaults to range 1
    // If above the crossover range, use range1. If not, use range 2.
    io_train_range = (l_continuous_range >= CROSSOVER_RANGE) ? fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE1 :
                     fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_RANGE_RANGE2;
    // If above the crossover range, convert to range 1. If not use range 2
    io_train_value = (l_continuous_range >= CROSSOVER_RANGE) ? (l_continuous_range - CROSSOVER_RANGE) :
                     (l_continuous_range);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief DP16 gets the VREF training values to start calibration
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure that the big step is divisible by the small step
/// This function converts the small step value over to the closest allowable value as to what was entered
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
                                    uint8_t& o_train_value)
{
    // EC level taken care of in the caller

    // Declares variables
    std::vector<uint64_t> l_ranks;
    uint64_t l_rank = 0;
    uint8_t l_vrefdq_train_value[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {0};
    uint8_t l_vrefdq_train_range[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM] = {0};

    // Gets the ranks on which to latch the VREF's
    FAPI_TRY(mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks));

    // Only uses the first rank in the rank pair, as there is only one set of registers per rank pair
    // If no ranks are configured, exit
    l_rank = l_ranks[0];

    if(l_rank == NO_RANK)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Now gets the train value and range for the given rank
    FAPI_TRY( mss::eff_vref_dq_train_value(i_target, &(l_vrefdq_train_value[0][0])) );
    FAPI_TRY( mss::eff_vref_dq_train_range(i_target, &(l_vrefdq_train_range[0][0])) );

    o_train_range = l_vrefdq_train_range[l_rank / MAX_RANK_PER_DIMM][l_rank % MAX_RANK_PER_DIMM];
    o_train_value = l_vrefdq_train_value[l_rank / MAX_RANK_PER_DIMM][l_rank % MAX_RANK_PER_DIMM];

    // Converts over the values
    FAPI_TRY(convert_train_values<fapi2::TARGET_TYPE_MCA>(i_big_step, o_train_range, o_train_value));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief DP16 sets up the VREF train range and value
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure the WR VREF is an integer number of big steps away from the 0 value and one big step from the top of the range
/// This function converts the WR VREF values over to be good values
/// @param[in] i_target the fapi2 target type MCA of the port
/// @param[in] i_rp - rank pair to check and modify
/// @param[out] o_train_range - JEDEC MR6 WR VREF training range
/// @param[out] o_train_value - JEDEC MR6 WR VREF training value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode setup_values( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_rp,
                                uint8_t& o_train_range,
                                uint8_t& o_train_value)
{
    // EC level taken care of in the caller

    // Traits declaration
    typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;

    // Declares variables
    uint8_t l_big_step = 0;
    uint8_t l_small_step = 0;

    // Sets up the wr_vref_config0 register and returns out the big/small step values
    FAPI_TRY(write_config0(i_target, l_big_step, l_small_step));

    // Gets the train values
    FAPI_TRY(get_train_values(i_target, i_rp, l_big_step, o_train_range, o_train_value));

    // Sets up the WR VREF values in the RP register
    {
        // Creates and sets up the buffer
        fapi2::buffer<uint64_t> l_buff;

        l_buff.writeBit<TT::WR_VREF_VALUE_RANGE_DRAM_EVEN>(o_train_range)
        .writeBit<TT::WR_VREF_VALUE_RANGE_DRAM_ODD>(o_train_range)
        .insertFromRight<TT::WR_VREF_VALUE_VALUE_DRAM_EVEN, TT::WR_VREF_VALUE_VALUE_DRAM_EVEN_LEN>(o_train_value)
        .insertFromRight<TT::WR_VREF_VALUE_VALUE_DRAM_ODD, TT::WR_VREF_VALUE_VALUE_DRAM_ODD_LEN>(o_train_value);

        // Hits only the desired RP
        switch(i_rp)
        {
            case 0:
                FAPI_TRY(mss::scom_blastah(i_target, TT::WR_VREF_VALUE_RP0_REG, l_buff));
                break;

            case 1:
                FAPI_TRY(mss::scom_blastah(i_target, TT::WR_VREF_VALUE_RP1_REG, l_buff));
                break;

            case 2:
                FAPI_TRY(mss::scom_blastah(i_target, TT::WR_VREF_VALUE_RP2_REG, l_buff));
                break;

            case 3:
                FAPI_TRY(mss::scom_blastah(i_target, TT::WR_VREF_VALUE_RP3_REG, l_buff));
                break;

            // Weird. There shouldn't be more than RP3. Error out
            default:
                FAPI_TRY(fapi2::FAPI2_RC_INVALID_PARAMETER, "%s RP%lu was passed in. Maximum allowable value is 3.",
                         mss::c_str(i_target), i_rp);
                break;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace wr_vref
} // close namespace dp16
} // close namespace workarounds
} // close namespace mss
