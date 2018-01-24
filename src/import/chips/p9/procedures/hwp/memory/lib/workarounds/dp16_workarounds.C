/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/dp16_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
/// Workarounds are very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/workarounds/dp16_workarounds.H>
#include <lib/phy/dp16.H>
#include <lib/phy/ddr_phy.H>
#include <lib/phy/phy_cntrl.H>
#include <lib/phy/mss_training.H>
#include <lib/dimm/rank.H>
#include <lib/utils/bit_count.H>
#include <lib/fir/check.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/dimm/eff_dimm.H>

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
        const fapi2::buffer<uint32_t>& i_cal_steps_enabled )
{
    // Only runs on the last cal steps (coarse wr/rd)
    if (i_cal_steps_enabled.getBit<mss::cal_steps::COARSE_RD>() ||
        i_cal_steps_enabled.getBit<mss::cal_steps::COARSE_WR>())
    {
        FAPI_TRY( mss::workarounds::dp16::modify_calibration_results( i_target ) );
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
        std::vector< fapi2::buffer<uint64_t> > l_vref_cntl;

        // Fix up vref dac
        if (!l_sim)
        {
            const auto& RD_VREF_CNTRL_REG = mss::chip_ec_nimbus_lt_2_0(i_target) ? TT::DD1_RD_VREF_CNTRL_REG :
                                            TT::DD2_RD_VREF_CNTRL_REG;
            FAPI_TRY( mss::scom_suckah(p, RD_VREF_CNTRL_REG, l_vref_cntl) );
            std::for_each(l_vref_cntl.begin(), l_vref_cntl.end(),
                          [&p](fapi2::buffer<uint64_t>& b)
            {
                // Checks for EC level
                b  = mss::workarounds::dp16::vref_dac(p, b);
            });
            FAPI_TRY( mss::scom_blastah(p, RD_VREF_CNTRL_REG, l_vref_cntl) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Fixes red waterfall values in a port
/// @param[in] i_target - the target to operate on
/// @param[in] i_rp - the rank pair to change
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode fix_red_waterfall_gate( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const uint64_t i_rp)
{
    // Checks if the workaround needs to be run
    const bool l_attr_value = mss::chip_ec_feature_red_waterfall_adjust(i_target);

    if(!l_attr_value)
    {
        FAPI_DBG("Skipping running fix_red_waterfall_gate %s", mss::c_str(i_target) );
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Loops through the first 4 DP's as the last DP is a DP08 so we only need to do 2 quads
    const std::vector<std::vector<uint64_t>> l_dp16_registers =
    {
        {
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_1},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_2},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_3},
        },
        {
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_0},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_1},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_2},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_3},
        },
        {
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_0},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_1},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_2},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_3},
        },
        {
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_0},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_1},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_2},
            {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_3},
        }
    };
    const std::vector<uint64_t> l_dp08_registers =
    {
        {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_4},
        {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR1_P0_4},
        {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR2_P0_4},
        {MCA_DDRPHY_DP16_DQS_RD_PHASE_SELECT_RANK_PAIR3_P0_4},
    };

    // Gets the number of primary ranks to loop through
    std::vector<uint64_t> l_rank_pairs;
    FAPI_TRY(mss::rank::get_rank_pairs(i_target, l_rank_pairs));

    FAPI_INF("Changing red waterfalls for %s", mss::c_str(i_target));

    // Loops through all DP16s
    for(const auto& l_reg : l_dp16_registers[i_rp])
    {
        fapi2::buffer<uint64_t> l_waterfall;

        // Getscoms
        FAPI_TRY(mss::getScom(i_target, l_reg, l_waterfall), "%s Failed to getScom from 0x%016lx",
                 mss::c_str(i_target), l_reg);

        // Updates the data for all quads
        update_red_waterfall_for_quad<0>(l_waterfall);
        update_red_waterfall_for_quad<1>(l_waterfall);
        update_red_waterfall_for_quad<2>(l_waterfall);
        update_red_waterfall_for_quad<3>(l_waterfall);

        // Putscoms
        FAPI_TRY(mss::putScom(i_target, l_reg, l_waterfall), "%s Failed to putScom to 0x%016lx",
                 mss::c_str(i_target), l_reg);
    }

    // Now for the odd man out - the DP08, as it only has two quads.
    // Note: We are not modifying the non-existant quads, as changing values in the non-existant DP08 has caused FIRs
    {
        fapi2::buffer<uint64_t> l_waterfall;

        // Getscoms
        FAPI_TRY(mss::getScom(i_target, l_dp08_registers[i_rp], l_waterfall), "%s Failed to getScom from 0x%016lx",
                 mss::c_str(i_target), l_dp08_registers[i_rp]);

        // Updates the data for all quads
        update_red_waterfall_for_quad<0>(l_waterfall);
        update_red_waterfall_for_quad<1>(l_waterfall);

        // Putscoms
        FAPI_TRY(mss::putScom(i_target, l_dp08_registers[i_rp], l_waterfall), "%s Failed to putScom to 0x%016lx",
                 mss::c_str(i_target), l_dp08_registers[i_rp]);
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
    std::vector<uint64_t> l_rank_pairs;
    FAPI_TRY(mss::rank::get_rank_pairs(i_target, l_rank_pairs));

    // Loops through all configured rank pairs
    for(const auto& l_rp : l_rank_pairs)
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

namespace dqs_align
{

///
/// @brief Runs the DQS workaround
/// @param[in] i_target MCA target
/// @param[in] i_rp the rank pair
/// @param[in] i_abort_on_error CAL_ABORT_ON_ERROR override
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode dqs_align_workaround(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                       const uint64_t i_rp,
                                       const uint8_t i_abort_on_error)
{
    constexpr uint64_t MAX_LOOPS = 10;

    // Variable declarations
    auto l_skip = mss::states::ON;
    std::map<uint64_t, uint64_t> l_passing_values;
    uint64_t l_num_loops = 0;
    uint8_t l_dram_width[mss::PORTS_PER_MCS] = {};
    bool l_is_x8 = false;

    // Let's check to see if we can run the workaround
    // If we can't, exit with success
    if (! chip_ec_feature_mss_dqs_workaround(i_target) )
    {
        FAPI_DBG("%s Skipping DQS workaround because of ec feature attribute", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Boolean to keep track of if a fail was calibration related, or scom related
    bool l_cal_fail = false;

    // Create a DQS align calibration step, as it might need to be used in the loop below
    const auto l_dqs_align_step = mss::training::dqs_align();

    FAPI_TRY( eff_dram_width( i_target, l_dram_width) );

    l_is_x8 = ((l_dram_width[0] == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ||
               (l_dram_width[1] == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) );

    // First check if the workaround is needed - we could have fails, just not due to DQS align
    FAPI_TRY(mss::workarounds::dp16::dqs_align::check_workaround(i_target, i_rp, l_skip));

    FAPI_INF("%s i_rp %lu %s the DQS align workaround", mss::c_str(i_target), i_rp,
             l_skip == mss::states::OFF ? "running" : "skipping");

    // Skip the workaround
    if(l_skip == mss::states::ON)
    {
        // Clear the disable registers so we can keep running calibration on other ranks
        FAPI_TRY(mss::workarounds::dp16::dqs_align::reset_disables(i_target, i_rp));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Now the fun begins....
    // Note: adding this call outside the loop to avoid hitting calibration an extra time in case we're fully passing
    FAPI_TRY(mss::workarounds::dp16::dqs_align::record_passing_values(i_target, i_rp, l_passing_values));

    // Loop until we pass or timeout
    while(!mss::workarounds::dp16::dqs_align::check_completed(l_passing_values, l_is_x8 ? MAX_DRAMS_X8 : MAX_DRAMS_X4)
          && l_num_loops < MAX_LOOPS)
    {
        FAPI_INF("%s i_rp %lu starting DQS align workaround loop number %lu", mss::c_str(i_target), i_rp, l_num_loops);

        // I'm making the bold(?) assumption that whenever we fail, disable bits get set. If that's not the case, this workaround will break - SPG

        // Clear all disable bits - this will cause calibration to re-run everything that failed, including WR LVL fails
        FAPI_TRY(mss::workarounds::dp16::dqs_align::reset_disables(i_target, i_rp));

        // Hit calibration one more time
        FAPI_TRY(l_dqs_align_step.execute(i_target, i_rp, i_abort_on_error));

        // Get the current passing states
        // We override any states that were passing previously and are still passing
        // We really just want to add on new passing values
        FAPI_TRY(mss::workarounds::dp16::dqs_align::record_passing_values(i_target, i_rp, l_passing_values));

        ++l_num_loops;
    }

    // Clear all disable bits - this will cause calibration to re-run everything that failed, including WR LVL fails
    FAPI_TRY(mss::workarounds::dp16::dqs_align::reset_disables(i_target, i_rp));

    // Next, we're checking for CAL fails, so make sure to check the FIR's below
    l_cal_fail = true;

    // If the loop timed out, bomb out
    // If this is firmware, they'll log it as info and run to memdiags
    // If we're cronus, we're bombing out
    // Either way, let's do ffdc and collect the regs
    FAPI_ASSERT( l_num_loops < MAX_LOOPS,
                 fapi2::MSS_DRAMINIT_TRAINING_DQS_ALIGNMENT_WORKAROUND_FAILED()
                 .set_NUM_LOOPS(l_num_loops)
                 .set_RP(i_rp)
                 .set_ABORT_ON_ERROR(i_abort_on_error)
                 .set_MCA_TARGET(i_target),
                 "%s i_rp %lu DQS workaround failed! 10 loops reached without everything passing",
                 mss::c_str(i_target), i_rp);

    // Below, the errors are scom related, no need to check the FIR's
    l_cal_fail = false;

    // Now plop the delays back in to the registers
    FAPI_TRY(mss::workarounds::dp16::dqs_align::set_passing_values( i_target, i_rp, l_passing_values));

fapi_try_exit:

    // If the FIR's are cal fails, then check to see if FIR's or PLL's could be the cause
    return mss::check::fir_or_pll_fail(i_target, fapi2::current_err, l_cal_fail);
}

///
/// @brief Checks if the DQS align workaround needs to be run
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rp the rank pair to check
/// @param[out] o_skip_workaround - YES if cal should be skipped
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note the workaround needs to be run IFF we failed DQS align
///
fapi2::ReturnCode check_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const uint64_t i_rp,
                                    mss::states& o_skip_workaround )
{
    // bit location of the two DQS error bits in the dp16 error register
    // Looking at NO_DQS and NO_LOCK which comes right after NO_DQS
    constexpr uint64_t NO_DQS = MCA_DDRPHY_DP16_RD_STATUS0_P0_0_01_NO_DQS;
    constexpr uint64_t NO_LOCK = MCA_DDRPHY_DP16_RD_STATUS0_P0_0_01_NO_LOCK;

    static const std::vector<uint64_t> RD_STATUS0 =
    {
        MCA_DDRPHY_DP16_RD_STATUS0_P0_0,
        MCA_DDRPHY_DP16_RD_STATUS0_P0_1,
        MCA_DDRPHY_DP16_RD_STATUS0_P0_2,
        MCA_DDRPHY_DP16_RD_STATUS0_P0_3,
        MCA_DDRPHY_DP16_RD_STATUS0_P0_4,
    };

    // Default to skip
    o_skip_workaround = mss::states::ON;
    std::vector<fapi2::buffer<uint64_t>> l_data;

    // Gets the reg
    FAPI_TRY(mss::scom_suckah(i_target, RD_STATUS0, l_data), "%s failed to read RD_STATUS0 regs", mss::c_str(i_target));

    // See if either of the the error bits signaling a DQS fail were triggered
    for(const auto& l_val : l_data)
    {
        if(l_val.getBit<NO_DQS>() || l_val.getBit<NO_LOCK>())
        {
            o_skip_workaround = mss::states::OFF;
            break;
        }
    }

    FAPI_INF("%s the DQS workaround will be %s", mss::c_str(i_target),
             o_skip_workaround == mss::states::OFF ? "run" : "skipped");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Resets bad DQ/DQS bits
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rp - the rank pair to operate on
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode reset_disables( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const uint64_t i_rp )
{
    // Traits declaration
    typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;
    constexpr uint64_t RESET_VAL = 0;

    return mss::scom_blastah(i_target, TT::BIT_DISABLE_REG[i_rp], RESET_VAL);
}

///
/// @brief Sets the passing values from the map into the registers
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rp - the rank pair to operate on
/// @param[in] i_passing_values - the passing values, a map from the DQS number to the value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode set_passing_values( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const uint64_t i_rp,
                                      std::map<uint64_t, uint64_t>& i_passing_values)
{
    // Declares constexprs to beautify the code
    constexpr uint64_t NUM_BYTES = MAX_DQ_BITS / BITS_PER_BYTE;
    constexpr uint64_t EVEN_START = MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_0_01_ROT_CLK_N0;
    constexpr uint64_t ODD_START = MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_0_01_ROT_CLK_N1;
    constexpr uint64_t LEN = MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_0_01_ROT_CLK_N0_LEN;

    // Registers in terms of RP, then 0/1
    static const std::vector<std::vector<uint64_t>> RD_CLK_REGS
    {
        // RANK_PAIR0
        {
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_0, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR0_P0_0,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_1, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR0_P0_1,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_2, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR0_P0_2,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_3, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR0_P0_3,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_4, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR0_P0_4,
        },
        // RANK_PAIR1
        {
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR1_P0_0, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR1_P0_0,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR1_P0_1, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR1_P0_1,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR1_P0_2, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR1_P0_2,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR1_P0_3, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR1_P0_3,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR1_P0_4, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR1_P0_4,
        },
        // RANK_PAIR2
        {
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR2_P0_0, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR2_P0_0,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR2_P0_1, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR2_P0_1,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR2_P0_2, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR2_P0_2,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR2_P0_3, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR2_P0_3,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR2_P0_4, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR2_P0_4,
        },
        // RANK_PAIR3
        {
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR3_P0_0, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR3_P0_0,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR3_P0_1, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR3_P0_1,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR3_P0_2, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR3_P0_2,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR3_P0_3, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR3_P0_3,
            MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR3_P0_4, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR3_P0_4,
        },
    };

    // Loop through all of the DP values
    for(uint64_t l_byte = 0; l_byte < NUM_BYTES; ++l_byte)
    {
        const auto l_nibble = l_byte * NIBBLES_PER_BYTE;
        const auto l_even = l_nibble;
        const auto l_odd = l_nibble + 1;

        // Sets up the data to plop into the register
        fapi2::buffer<uint64_t> l_data;
        const auto l_even_val = i_passing_values[l_even];
        const auto l_odd_val = i_passing_values[l_odd];

        // TK should we add get/insert into the API? we can then just call that function
        l_data.insertFromRight<EVEN_START, LEN>(l_even_val);
        l_data.insertFromRight<ODD_START, LEN>(l_odd_val);

        FAPI_INF("%s setting good values for i_rp %lu  l_byte %lu to register 0x%016lx", mss::c_str(i_target), i_rp, l_byte,
                 RD_CLK_REGS[i_rp][l_byte]);

        // Scoms that reg
        FAPI_TRY(mss::putScom(i_target, RD_CLK_REGS[i_rp][l_byte], l_data), "%s failed getscom 0x%016lx", mss::c_str(i_target),
                 RD_CLK_REGS[i_rp][l_byte]);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Records the passing values into a map
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rp - the rank pair to operate on
/// @param[in,out] io_passing_values - the passing values, a map from the DQS number to the value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode record_passing_values( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        std::map<uint64_t, uint64_t>& io_passing_values)
{
    // Traits declaration
    typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;

    constexpr uint64_t MAX_DP = 4;

    // Registers in terms of RP, then 0/1
    static const std::vector<std::vector<std::pair<uint64_t, uint64_t>>> RD_CLK_REGS
    {
        // RANK_PAIR0
        {
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_0, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR0_P0_0,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_1, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR0_P0_1,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_2, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR0_P0_2,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_3, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR0_P0_3,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_4, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR0_P0_4,},
        },
        // RANK_PAIR1
        {
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR1_P0_0, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR1_P0_0,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR1_P0_1, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR1_P0_1,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR1_P0_2, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR1_P0_2,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR1_P0_3, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR1_P0_3,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR1_P0_4, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR1_P0_4,},
        },
        // RANK_PAIR2
        {
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR2_P0_0, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR2_P0_0,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR2_P0_1, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR2_P0_1,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR2_P0_2, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR2_P0_2,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR2_P0_3, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR2_P0_3,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR2_P0_4, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR2_P0_4,},
        },
        // RANK_PAIR3
        {
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR3_P0_0, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR3_P0_0,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR3_P0_1, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR3_P0_1,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR3_P0_2, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR3_P0_2,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR3_P0_3, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR3_P0_3,},
            {MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR3_P0_4, MCA_DDRPHY_DP16_DQSCLK_PR1_RANK_PAIR3_P0_4,},
        },
    };

    // Gets out the values for DQS CLK and the disable bits
    std::vector<std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t>>> l_rd_clk_values;
    std::vector<std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t>>> l_disable_bits;

    FAPI_TRY(mss::scom_suckah(i_target, RD_CLK_REGS[i_rp], l_rd_clk_values));
    FAPI_TRY(mss::scom_suckah(i_target, TT::BIT_DISABLE_REG[i_rp], l_disable_bits));

    FAPI_ASSERT( l_disable_bits.size() == l_rd_clk_values.size(),
                 fapi2::MSS_RDCLK_ALIGN_VECTOR_MISMATCH()
                 .set_BITVECTOR_SIZE(l_disable_bits.size())
                 .set_RDCLK_SIZE(l_rd_clk_values.size()),
                 "%s disable bit vector size %lu is not the same as rd clk vector size %lu", mss::c_str(i_target),
                 l_disable_bits.size(), l_rd_clk_values.size());

    // Now, loops through both vectors and checks the errors
    {
        auto l_rd_it = l_rd_clk_values.begin();
        auto l_disable_it = l_disable_bits.begin();
        uint64_t l_dp = 0;

        FAPI_ASSERT( l_dp <= MAX_DP,
                     fapi2::MSS_EXCEED_NUMBER_OF_DP()
                     .set_BAD_DP_NUM(l_dp)
                     .set_MAX_DP(MAX_DP)
                     .set_TARGET(i_target),
                     "%s error looping over DP's, found dp %d, max is %d?",
                     mss::c_str(i_target),
                     l_dp,
                     MAX_DP);

        // rd_clk_values == disabled_bits, asserted above
        for(; l_rd_it < l_rd_clk_values.end(); ++ l_rd_it, ++l_dp, ++l_disable_it)
        {
            FAPI_INF("%s i_rp %lu checking on DP%lu for good values", mss::c_str(i_target), i_rp, l_dp);

            FAPI_TRY(record_passing_values_per_dqs<0>(i_target,
                     i_rp,
                     l_dp,
                     *l_disable_it,
                     *l_rd_it,
                     io_passing_values));

            FAPI_TRY(record_passing_values_per_dqs<1>(i_target,
                     i_rp,
                     l_dp,
                     *l_disable_it,
                     *l_rd_it,
                     io_passing_values));

            FAPI_TRY(record_passing_values_per_dqs<2>(i_target,
                     i_rp,
                     l_dp,
                     *l_disable_it,
                     *l_rd_it,
                     io_passing_values));

            FAPI_TRY(record_passing_values_per_dqs<3>(i_target,
                     i_rp,
                     l_dp,
                     *l_disable_it,
                     *l_rd_it,
                     io_passing_values));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace dqs_align

namespace rd_dq
{

///
/// @brief Reads out the read dq registers and stores the values in a vector
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rank_pair the rank pair to operate on
/// @param[out] o_reg_data register conglomerate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode get_delay_data(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                 const uint64_t i_rank_pair,
                                 std::vector<delay_data>& o_reg_data)
{
    static const std::vector<std::vector<uint64_t>> REGISTER =
    {
        // RANK_PAIR0
        {
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR0_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR0_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR0_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR0_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR0_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR0_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR0_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR0_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR0_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR0_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR0_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR0_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR0_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR0_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR0_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR0_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR0_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR0_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR0_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR0_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR0_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR0_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR0_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR0_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR0_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR0_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR0_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR0_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR0_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR0_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR0_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR0_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR0_P0_4,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR0_P0_4,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR0_P0_4,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR0_P0_4,
        },
        // RANK_PAIR1
        {
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR1_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR1_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR1_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR1_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR1_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR1_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR1_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR1_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR1_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR1_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR1_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR1_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR1_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR1_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR1_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR1_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR1_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR1_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR1_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR1_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR1_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR1_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR1_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR1_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR1_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR1_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR1_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR1_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR1_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR1_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR1_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR1_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR1_P0_4,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR1_P0_4,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR1_P0_4,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR1_P0_4,
        },
        // RANK_PAIR2
        {
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR2_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR2_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR2_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR2_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR2_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR2_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR2_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR2_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR2_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR2_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR2_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR2_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR2_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR2_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR2_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR2_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR2_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR2_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR2_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR2_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR2_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR2_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR2_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR2_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR2_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR2_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR2_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR2_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR2_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR2_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR2_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR2_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR2_P0_4,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR2_P0_4,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR2_P0_4,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR2_P0_4,
        },
        // RANK_PAIR3
        {
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR3_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR3_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR3_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR3_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR3_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR3_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR3_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR3_P0_0,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR3_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR3_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR3_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR3_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR3_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR3_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR3_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR3_P0_1,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR3_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR3_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR3_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR3_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR3_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR3_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR3_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR3_P0_2,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR3_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR3_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR3_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR3_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY4_RANK_PAIR3_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY5_RANK_PAIR3_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY6_RANK_PAIR3_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY7_RANK_PAIR3_P0_3,
            MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR3_P0_4,
            MCA_DDRPHY_DP16_READ_DELAY1_RANK_PAIR3_P0_4,
            MCA_DDRPHY_DP16_READ_DELAY2_RANK_PAIR3_P0_4,
            MCA_DDRPHY_DP16_READ_DELAY3_RANK_PAIR3_P0_4,
        },
    };
    // Bombs out if the rank pair is out of range

    FAPI_ASSERT( i_rank_pair < MAX_RANK_PAIRS,
                 fapi2::MSS_INVALID_RANK_PAIR()
                 .set_RANK_PAIR(i_rank_pair)
                 .set_MCA_TARGET(i_target)
                 .set_FUNCTION(RD_CTR_WORKAROUND_READ_DATA),
                 "%s Invalid rank pair (%d) in get_ranks_in_pair",
                 mss::c_str(i_target),
                 i_rank_pair);

    // loops and gets the registers
    o_reg_data.clear();

    for(const auto l_reg : REGISTER[i_rank_pair])
    {
        constexpr uint64_t EVEN_START = MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR0_P0_0_01_RD;
        constexpr uint64_t ODD_START = MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR0_P0_0_01_RD_DELAY1;
        fapi2::buffer<uint64_t> l_buff;
        uint64_t l_data = 0;

        // Reads the register information
        FAPI_TRY(mss::getScom(i_target, l_reg, l_buff), "%s failed getscom to register 0x%016lx", mss::c_str(i_target), l_reg);

        // Gets out the specific information and stores it
        // Even delay
        l_buff.extractToRight<EVEN_START, delay_data::LEN>(l_data);
        o_reg_data.push_back({l_reg, EVEN_START, l_data});

        // Odd delay
        l_buff.extractToRight<ODD_START, delay_data::LEN>(l_data);
        o_reg_data.push_back({l_reg, ODD_START, l_data});
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Finds the median and sorts the vector
/// @param[in,out] io_reg_data register data
/// @param[out] o_median the median value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode find_median_and_sort(std::vector<delay_data>& io_reg_data, uint64_t& o_median)
{

    // The fapi_try is in an if statement, this ensures we have a good value
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Note: the null constructor is deleted
    // We need to return the data value, so we're creating a temporary variable with 0's for it's values to get the median positon
    // Below, we'll get the data and return it to o_median
    delay_data l_temp(0, 0, 0);

    // Sorts first
    std::sort(io_reg_data.begin(), io_reg_data.end());

    // Returns the median value
    FAPI_TRY(find_median(io_reg_data, l_temp));
    o_median = l_temp.iv_data;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Overrides any bad (out of range) read delay values with the median value
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rank_pair the rank pair to operate on
/// @param[in] i_percent the percentage below the median outside of which to override values to be the median - OPTIONAL - defaults to 66
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode fix_delay_values(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const uint64_t i_rank_pair,
                                   const uint64_t i_percent)
{
    if(!mss::chip_ec_feature_mss_run_rd_ctr_workaround(i_target))
    {
        FAPI_INF("%s skipping the rd centering workaround!", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    std::vector<delay_data> l_reg_data;
    uint64_t l_median = 0;

    FAPI_TRY(get_delay_data(i_target, i_rank_pair, l_reg_data), "%s i_rank_pair %d failed to get the delay data",
             mss::c_str(i_target), i_rank_pair);

    FAPI_TRY(find_median_and_sort(l_reg_data, l_median), "%s i_rank_pair %d failed to find median value and sort",
             mss::c_str(i_target), i_rank_pair);

    FAPI_INF("%s i_rank_pair %d found a median of 0x%02x any value below %d %% of the median will be modified",
             mss::c_str(i_target), i_rank_pair, l_median, i_percent);

    // Overrides the bad delay values - the ones that are i_percent below the median
    {
        // Finds the iterator corresponding to the first location where we are within i_percent of the median
        const auto l_last = std::find_if(l_reg_data.begin(), l_reg_data.end(), [ i_percent,
                                         l_median]( const delay_data & i_rhs) -> bool
        {
            // Does this funky compare to avoid underflow
            const auto l_comp_value = (i_percent * l_median) / 100;
            return l_comp_value < i_rhs.iv_data;
        });

        // Loops and does the overrides
        // Note: does a simple RMW, we can speed this up by doing a more complex algorithm to sort registers together.
        // Keeping it simple for now
        for( auto l_it = l_reg_data.begin(); l_it < l_last; ++l_it)
        {
            fapi2::buffer<uint64_t> l_buff;
            FAPI_INF("%s i_rank_pair %d modifying delay position %d on register 0x%016lx from 0x%02x to be 0x%02x",
                     mss::c_str(i_target), i_rank_pair, l_it->iv_bit, l_it->iv_register, l_it->iv_data, l_median);

            // Read
            FAPI_TRY(mss::getScom(i_target, l_it->iv_register, l_buff));

            // Modify
            FAPI_TRY(l_buff.insertFromRight(l_median, l_it->iv_bit, delay_data::LEN));

            // Write
            FAPI_TRY(mss::putScom(i_target, l_it->iv_register, l_buff));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace rd_dq

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
    FAPI_ASSERT( MAX_BIG_STEP > i_big_step,
                 fapi2::MSS_WR_VREF_WORKAROUND_BIG_STEPS_OUTOFBOUNDS()
                 .set_MAX_BIG_STEP(MAX_BIG_STEP)
                 .set_ACTUAL_BIG_STEP(i_big_step),
                 "WR VREF %s step is out of range. %s step 0x%02x max", "big", "big",
                 i_big_step);
    FAPI_ASSERT( MAX_SMALL_STEP > io_small_step,
                 fapi2::MSS_WR_VREF_WORKAROUND_SMALL_STEPS_OUTOFBOUNDS()
                 .set_MAX_SMALL_STEP(MAX_SMALL_STEP)
                 .set_ACTUAL_SMALL_STEP(io_small_step),
                 "WR VREF %s step is out of range. %s step 0x%02x max", "big", "big",
                 i_big_step);

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

    // Makes sure that the values passed in were not out of range
    FAPI_ASSERT( NUM_BIG_STEP > i_big_step,
                 fapi2::MSS_WR_VREF_TRAIN_WORKAROUND_BIG_STEPS_OUTOFBOUNDS()
                 .set_MAX_BIG_STEP(NUM_BIG_STEP)
                 .set_ACTUAL_BIG_STEP(i_big_step),
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

///
/// @brief Gets the disable register and bit position for the DRAM
/// @param[in] i_target the fapi2 target type MCA of the port
/// @param[in] i_rp - rank pair to check and modify
/// @param[in] i_dram - the DRAM to be checked
/// @param[out] o_reg - the register to access from
/// @param[out] o_bit_pos - the bit position in the register to access from
/// @param[out] o_bit_len - the bit length to access
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode get_disable_reg_and_pos_for_dram( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint64_t i_dram,
        uint64_t& o_reg,
        uint64_t& o_bit_pos,
        uint64_t& o_bit_len)
{
    // Gets the DRAM width
    uint8_t l_width[MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( mss::eff_dram_width(i_target, l_width) );

    // Checks inputs
    FAPI_TRY(mss::dp16::wr_vref::check_rp_and_dram(i_target,
             i_rp,
             i_dram,
             ffdc_function_codes::GET_DRAM_DISABLE_REG_AND_POS));

    // Get the register and bit positions
    {
        typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;

        // Gets the DP associated with the DRAM and the DRAM's position in the DP
        const auto l_dram_per_dp = (l_width[0] == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ? BYTES_PER_DP : NIBBLES_PER_DP;
        const auto l_dp = i_dram / l_dram_per_dp;
        const auto l_dram_pos = i_dram % l_dram_per_dp;

        // Bit position and length
        o_bit_pos = TT::BIT_DISABLE + (l_dram_pos * l_width[0]);
        o_bit_len = l_width[0];

        // Gets the register address to read
        o_reg = TT::BIT_DISABLE_REG[i_rp][l_dp].first;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the disables for a specific DRAM
/// @param[in] i_target the fapi2 target type MCA of the port
/// @param[in] i_rp - rank pair to check and modify
/// @param[in] i_dram - the DRAM to be checked
/// @param[out] o_disables - true if the whole DRAM is disabled
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode get_disables_for_dram( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint64_t i_dram,
        uint64_t& o_disables)
{
    uint64_t l_reg = 0;
    uint64_t l_bit_pos = 0;
    uint64_t l_len = 0;
    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(get_disable_reg_and_pos_for_dram(i_target, i_rp, i_dram, l_reg, l_bit_pos, l_len));

    // Reads
    FAPI_TRY( mss::getScom(i_target, l_reg, l_data) );

    // Gets the DRAM's data
    FAPI_TRY(l_data.extractToRight(o_disables, l_bit_pos, l_len));

    FAPI_INF("%s RP%lu DRAM%lu reg:0x%016lx reg_value:0x%016lx DRAM disables: 0x%lx", mss::c_str(i_target), i_rp, i_dram,
             l_reg, l_data, o_disables);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Identifies if an inputted DRAM is wholely disabled
/// @param[in] i_target the fapi2 target type MCA of the port
/// @param[in] i_rp - rank pair to check and modify
/// @param[in] i_dram - the DRAM to be checked
/// @param[out] o_disabled - true if the whole DRAM is disabled
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode is_dram_disabled( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const uint64_t i_rp,
                                    const uint64_t i_dram,
                                    bool& o_disabled)
{
    // Checks inputs
    uint8_t l_width[MAX_DIMM_PER_PORT] = {};
    uint64_t l_disables = 0;
    FAPI_TRY( mss::eff_dram_width(i_target, l_width) );

    // Gets the disables for this DRAM
    FAPI_TRY(get_disables_for_dram(i_target, i_rp, i_dram, l_disables));

    // A DRAM is disabled if all of it's bits are disabled
    {
        const uint64_t l_disabled_value = (l_width[0] == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ? 0xff : 0xf;
        o_disabled = (l_disables == l_disabled_value);
        FAPI_INF("%s RP%lu DRAM%lu DRAM disables: 0x%lx check value: 0x%lx %s disabled", mss::c_str(i_target), i_rp, i_dram,
                 l_disables, l_disabled_value, o_disabled ? "is" : "isn't");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Identifies if an inputted DRAM has any disables
/// @param[in] i_target the fapi2 target type MCA of the port
/// @param[in] i_rp - rank pair to check and modify
/// @param[in] i_dram - the DRAM to be checked
/// @param[out] o_has_disables - true if the whole DRAM has any disables
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode dram_has_disables( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                     const uint64_t i_rp,
                                     const uint64_t i_dram,
                                     bool& o_has_disables)
{
    // Checks inputs
    uint64_t l_disables = 0;

    // Gets the disables for this DRAM
    FAPI_TRY(get_disables_for_dram(i_target, i_rp, i_dram, l_disables));

    // A DRAM is disabled if all of it's bits are disabled
    {
        constexpr uint64_t CLEAR = 0;
        o_has_disables = (CLEAR != l_disables);
        FAPI_INF("%s RP%lu DRAM%lu DRAM disables: 0x%lx clear value: 0x%lx %s disables", mss::c_str(i_target), i_rp, i_dram,
                 l_disables, CLEAR, o_has_disables ? "has" : "has no");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Disables bits based upon RD VREF values that differ from the median significantly
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair on which to operate
/// @param[in] i_dram - the DRAM that needs to have the workaround applied to it
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note The differing values can cause WR VREF fail, so the bit(s) that differ are disabled temporarily
///
fapi2::ReturnCode disable_bits( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_rp,
                                const uint64_t i_dram )
{
    // Gets the register for the disable bits
    uint64_t l_reg = 0;
    uint64_t l_dram_start_pos = 0;
    uint64_t l_len = 0;
    FAPI_TRY(get_disable_reg_and_pos_for_dram(i_target, i_rp, i_dram, l_reg, l_dram_start_pos, l_len));

    // Sets up this DRAM's disable bits
    {
        // Gets the bit to test
        uint64_t l_bit = 0;
        fapi2::buffer<uint64_t> l_data;
        std::vector<uint64_t> l_rd_vref_values;
        FAPI_TRY(read_rd_vref_for_dram( i_target, i_rp, i_dram, l_rd_vref_values ));
        FAPI_TRY(identify_first_good_rd_vref( i_target, i_rp, i_dram, l_rd_vref_values, l_bit ));

        // Read...
        FAPI_TRY(mss::getScom(i_target, l_reg, l_data));

        // Modify...
        // First of all, disable all bits - for the workaround, we only want to run one bit in the DRAM
        FAPI_TRY(l_data.setBit(l_dram_start_pos, l_len));
        // Next, clear the bit (set it as good)
        FAPI_TRY(l_data.clearBit(l_dram_start_pos + l_bit));

        // Write...
        FAPI_TRY(mss::putScom(i_target, l_reg, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clears all disable bits for a recovered DRAM
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair on which to operate
/// @param[in] i_dram - the DRAM that needs to have the workaround applied to it
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode clear_dram_disable_bits( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint64_t i_dram )
{
    // Gets the register for the disable bits
    uint64_t l_reg = 0;
    uint64_t l_bit_pos = 0;
    uint64_t l_len = 0;
    FAPI_TRY(get_disable_reg_and_pos_for_dram(i_target, i_rp, i_dram, l_reg, l_bit_pos, l_len));

    // Restores the disabled bits
    {
        // Read...
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(mss::getScom(i_target, l_reg, l_data));

        // Modify...
        FAPI_TRY(l_data.clearBit(l_bit_pos, l_len));

        // Write...
        FAPI_TRY(mss::putScom(i_target, l_reg, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures the WR VREF value of a DRAM to be the nominal values
/// @param[in] i_target the fapi2 target type DIMM
/// @param[in] i_rp - rank pair to check and modify
/// @param[in] i_dram - the DRAM
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode configure_wr_vref_to_nominal( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rp,
        const uint64_t i_dram)
{
    typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    uint64_t l_reg = 0;

    // Get the WR VREF register
    FAPI_TRY(mss::dp16::wr_vref::get_wr_vref_rp_reg(l_mca, i_rp, i_dram, l_reg));

    {

        const auto l_dram_pos = i_dram % TT::NUM_DRAM_PER_REG;
        const auto l_range_pos = (l_dram_pos == 0) ? TT::WR_VREF_VALUE_RANGE_DRAM_EVEN : TT::WR_VREF_VALUE_RANGE_DRAM_ODD;
        const auto l_value_pos = (l_dram_pos == 0) ? TT::WR_VREF_VALUE_VALUE_DRAM_EVEN : TT::WR_VREF_VALUE_VALUE_DRAM_ODD;

        // Now for read modify write
        fapi2::buffer<uint64_t> l_data;

        // Gets the VPD JEDEC WR VREF information
        fapi2::buffer<uint8_t> l_train_value;
        fapi2::buffer<uint8_t> l_train_range;
        FAPI_TRY(mss::get_vpd_wr_vref_range_and_value(i_target, l_train_range, l_train_value));

        FAPI_TRY(mss::getScom(l_mca, l_reg, l_data));

        // Sends the data
        FAPI_TRY(l_data.writeBit(l_train_range, l_range_pos));
        FAPI_TRY(l_data.insertFromRight(l_train_value, l_value_pos, TT::WR_VREF_VALUE_VALUE_DRAM_EVEN_LEN));

        FAPI_TRY(mss::putScom(l_mca, l_reg, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures the skip bits to be 0x7 for an entire port for the workaround
/// @param[in] i_target the fapi2 target type DIMM
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode configure_skip_bits( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;
    constexpr uint64_t SKIP_ALL = 0x7;

    std::vector<fapi2::buffer<uint64_t>> l_wr_vref_config;
    FAPI_TRY( mss::scom_suckah(i_target, TT::WR_VREF_CONFIG0_REG, l_wr_vref_config) );

    // Loops and sets or clears the 2D VREF bit on all DPs
    for(auto& l_data : l_wr_vref_config)
    {
        // Updates the skip bits to be skip all
        l_data.insertFromRight<TT::WR_VREF_CONFIG0_NUM_BITS_TO_SKIP, TT::WR_VREF_CONFIG0_NUM_BITS_TO_SKIP_LEN>(SKIP_ALL);
    }

    FAPI_TRY(mss::scom_blastah(i_target, TT::WR_VREF_CONFIG0_REG, l_wr_vref_config));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Modifies the WR VREF value in an MRS06 to have the VPD, not eff_config attribute values
/// @param[in] i_target - the DIMM target on which to operate
/// @param[in,out] io_mrs06 - the MRS data class to modify
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note The differing values can cause WR VREF fail, so the bit(s) that differ are disabled temporarily
///
fapi2::ReturnCode modify_mrs_vref_to_vpd( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        mss::ddr4::mrs06_data& io_mrs06 )
{
    // Gets the VPD JEDEC WR VREF information
    uint8_t l_train_value = 0;
    uint8_t l_train_range = 0;
    FAPI_TRY(mss::get_vpd_wr_vref_range_and_value(i_target, l_train_range, l_train_value));

    FAPI_INF("%s setting MRS06 to have the correct VPD value from 0x%02lx to range: %lu value 0x%02lx from 0x%02x",
             mss::c_str(i_target), io_mrs06.iv_vrefdq_train_range[0], l_train_range, io_mrs06.iv_vrefdq_train_value[0],
             l_train_value);

    for(uint64_t l_rank = 0; l_rank < MAX_RANK_PER_DIMM; ++l_rank)
    {
        io_mrs06.iv_vrefdq_train_value[l_rank] = l_train_value;
        io_mrs06.iv_vrefdq_train_range[l_rank] = l_train_range;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Resets the WR DQ delays for a given DRAM to be a quarter clock before the DQS
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair on which to operate
/// @param[in] i_dram - the DRAM that needs to have the workaround applied to it
/// @param[in] i_delay - the write DQ delay value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note The differing values can cause WR VREF fail, so the bit(s) that differ are disabled temporarily
///
fapi2::ReturnCode reset_wr_dq_delay( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                     const uint64_t i_rp,
                                     const uint64_t i_dram,
                                     const uint64_t i_delay )
{
    typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;

    // Gets the DRAM width
    uint8_t l_width[MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( mss::eff_dram_width(i_target, l_width) );

    // Checks inputs
    FAPI_TRY(mss::dp16::wr_vref::check_rp_and_dram(i_target, i_rp, i_dram, ffdc_function_codes::RESET_WR_DQ_DELAY));

    // Restores the inputted delay values
    {
        const uint64_t l_start_bit = i_dram * l_width[0];
        const uint64_t l_end_bit   = l_start_bit + l_width[0];

        // And restore the good DQ values
        for(uint64_t l_bit = l_start_bit; l_bit < l_end_bit; ++l_bit)
        {
            const auto l_dq_reg = TT::WR_DQ_DELAY_REG[i_rp][l_bit];
            fapi2::buffer<uint64_t> l_data;
            l_data.insertFromRight<TT::WR_DELAY, TT::WR_DELAY_LEN>(i_delay);

            FAPI_INF("%s RP%lu DRAM %lu DQ reg 0x%016lx DQ val 0x%lx reg val 0x%016lx",
                     mss::c_str(i_target), i_rp, i_dram, l_dq_reg, i_delay, l_data);
            FAPI_TRY(mss::putScom(i_target, l_dq_reg, l_data));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads out the RD VREF values for a given DRAM
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair on which to operate
/// @param[in] i_dram - the DRAM that needs to have the workaround applied to it
/// @param[out] o_rd_vref_values - the RD VREF values for a given DRAM
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note The differing values can cause WR VREF fail, so the bit(s) that differ are disabled temporarily
///
fapi2::ReturnCode read_rd_vref_for_dram( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint64_t i_dram,
        std::vector<uint64_t>& o_rd_vref_values )
{
    typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;

    // Clears the output, just in case
    o_rd_vref_values.clear();

    // Gets the DRAM width
    uint8_t l_width[MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( mss::eff_dram_width(i_target, l_width) );

    // Checks inputs
    FAPI_TRY(mss::dp16::wr_vref::check_rp_and_dram(i_target, i_rp, i_dram,
             ffdc_function_codes::READ_RD_VREF_VALUES_FOR_DRAM));

    // Gets the RD VREF values
    {
        // There are two RD VREF values stored per register
        // One RD VREF value corresponds to one bit
        // For a x4 DRAM, there are 4 bits per DRAM, meaning two registers need to be read
        // For a x8 DRAM, there are 8 bits per DRAM, meaning four registers need to be read
        constexpr uint64_t NUM_REGS_X4 = 2;
        constexpr uint64_t NUM_REGS_X8 = 4;
        const auto NUM_REGS = (l_width[0] == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ? NUM_REGS_X8 : NUM_REGS_X4;

        // Computes the starting register's position
        const uint64_t START_REG = i_dram * NUM_REGS;

        // Loops through all of the registers
        for(uint64_t l_reg = 0; l_reg < NUM_REGS; ++l_reg)
        {
            const auto l_reg_pos = l_reg + START_REG;
            uint64_t l_value = 0;
            fapi2::buffer<uint64_t> l_buff;

            FAPI_TRY(mss::getScom(i_target, TT::DD2_RD_VREF_CNTRL_REG[l_reg_pos], l_buff));
            l_buff.extractToRight<TT::RD_VREF_BYTE0_NIB0, TT::RD_VREF_BYTE0_NIB0_LEN>(l_value);
            FAPI_INF("%s RP%lu DRAM%lu has RD VREF value of 0x%02lx", mss::c_str(i_target), i_rp, i_dram, l_value);
            o_rd_vref_values.push_back(l_value);
            l_buff.extractToRight<TT::RD_VREF_BYTE0_NIB1, TT::RD_VREF_BYTE0_NIB1_LEN>(l_value);
            FAPI_INF("%s RP%lu DRAM%lu has RD VREF value of 0x%02lx", mss::c_str(i_target), i_rp, i_dram, l_value);
            o_rd_vref_values.push_back(l_value);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Identifies the first good RD VREF bit
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair on which to operate
/// @param[in] i_dram - the DRAM that needs to have the workaround applied to it
/// @param[in] i_rd_vref_values - the RD VREF values for a given DRAM
/// @param[out] o_bit - the bit for the first good RD VREF
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note The differing values can cause WR VREF fail, so the bit(s) that differ are disabled temporarily
///
fapi2::ReturnCode identify_first_good_rd_vref( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint64_t i_dram,
        const std::vector<uint64_t>& i_rd_vref_values,
        uint64_t& o_bit )
{
    constexpr uint64_t THRESHOLD = 3;
    // Loop through all RD VREF values
    uint64_t l_bit = 0;

    // Gets the median value
    uint64_t l_median = 0;
    FAPI_TRY(rd_dq::find_median(i_rd_vref_values, l_median));

    for(const auto l_value : i_rd_vref_values)
    {
        // Error case, continue on...
        if((l_median > (l_value + THRESHOLD)) || (l_value > (l_median + THRESHOLD)))
        {
            FAPI_INF("%s RP%lu DRAM%lu bit: %lu with value of %lu is out of the median (%lu) +/- threshold range (%lu). Testing the next bit",
                     mss::c_str(i_target), i_rp, i_dram, l_bit, l_value, l_median, THRESHOLD);
        }
        // The first bit inside the threshold is good, note it and exit out successfully
        else
        {
            FAPI_INF("%s RP%lu DRAM%lu bit: %lu with value of %lu is inside of the median (%lu) +/- threshold range (%lu). Returning this as the bit to test",
                     mss::c_str(i_target), i_rp, i_dram, l_bit, l_value, l_median, THRESHOLD);
            o_bit = l_bit;
            break;
        }

        ++l_bit;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads out the WR DQ delay value for a given DRAM
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair on which to operate
/// @param[in] i_dram - the DRAM that needs to have the workaround applied to it
/// @param[out] o_wr_dq_delay - the WR DQ delay value for a given DRAM
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note At this point, WR CTR hasn't been run, so all WR DQ delays should be the same on the DRAM
///
fapi2::ReturnCode get_starting_wr_dq_delay( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint64_t i_dram,
        uint64_t& o_wr_dq_delay )
{
    typedef dp16Traits<fapi2::TARGET_TYPE_MCA> TT;

    // Gets the DRAM width
    uint8_t l_width[MAX_DIMM_PER_PORT] = {};
    FAPI_TRY( mss::eff_dram_width(i_target, l_width) );

    // Checks inputs
    FAPI_TRY(mss::dp16::wr_vref::check_rp_and_dram(i_target, i_rp, i_dram,
             ffdc_function_codes::GET_STARTING_WR_DQ_DELAY_VALUE));

    // Gets the data
    {
        // Gets the register - we only want bit 0 of the DRAM
        const auto l_first_bit = i_dram * l_width[0];
        const auto l_reg = TT::WR_DQ_DELAY_REG[i_rp][l_first_bit];

        // Gets the register
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(mss::getScom(i_target, l_reg, l_data));

        // Returns the data
        o_wr_dq_delay = 0;
        l_data.extractToRight<TT::WR_DELAY, TT::WR_DELAY_LEN>(o_wr_dq_delay);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Logs an informational callout detailing if we were able to recover
/// @param[in] i_target - the MCA target under calibration
/// @param[in] i_rp - the rank pair under calibration
/// @param[in] i_dram - the DRAM in question
/// @param[in] i_bad - true iff the DRAM failed to recover
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode log_dram_results( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const uint64_t i_rp,
                                    const uint64_t i_dram,
                                    const bool i_bad )
{
    // Log this information for cronus, as the logs are normally supressed
#ifndef __HOSTBOOT_MODULE
    FAPI_ERR("%s WR VREF workaround recovery %s on RP%lu DRAM%lu",
             mss::c_str(i_target), i_bad ? "failed" : "succeeded", i_rp, i_dram);
#endif

    // If we call this function, we have a fail
    FAPI_ASSERT( true,
                 fapi2::MSS_WR_VREF_DRAM_RECOVERY()
                 .set_TARGET(i_target)
                 .set_RP(i_rp)
                 .set_DRAM(i_dram)
                 .set_IS_BAD(i_bad),
                 "%s WR VREF workaround recovery %s on RP%lu DRAM%lu",
                 mss::c_str(i_target),
                 i_bad ? "failed" : "succeeded",
                 i_rp,
                 i_dram
               );

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:

    // Log the error as recovered - we want this error to be informational
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::current_err;
}

///
/// @brief Clears the PHY training FIRs for a given port
/// @param[in] i_target - the MCA target under calibration
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode clear_training_firs( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{

    fapi2::buffer<uint64_t> l_phyfir_mask;
    l_phyfir_mask.setBit<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_2>();

    // Clear the PHY FIR ERROR 2 bit so we don't keep failing training and training advance on this port
    FAPI_TRY( mss::putScom(i_target, MCA_IOM_PHY0_DDRPHY_FIR_REG_AND, l_phyfir_mask.invert()) );

    FAPI_TRY( mss::getScom(i_target, MCA_IOM_PHY0_DDRPHY_FIR_REG, l_phyfir_mask));

fapi_try_exit:
    return fapi2::current_err;
}


} // close namespace wr_vref
} // close namespace dp16
} // close namespace workarounds
} // close namespace mss
