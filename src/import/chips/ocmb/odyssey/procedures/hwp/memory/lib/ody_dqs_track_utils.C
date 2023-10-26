/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ody_dqs_track_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

// EKB-Mirror-To: hostboot

///
/// @file ody_dqs_track_utils.C
/// @brief DQS tracking utils
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: David J Chung <dj.chung@ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <vector>

#include <ody_dqs_track_utils.H>
#include <lib/dimm/ody_rank.H>
#include <ody_scom_ody_odc.H>
#include <lib/shared/ody_consts.H>
#include <lib/ccs/ody_ccs_traits.H>
#include <lib/mc/ody_port_traits.H>
#include <lib/mcbist/ody_mcbist_traits.H>
#include <lib/ccs/ody_ccs.H>
#include <generic/memory/lib/ccs/ccs_ddr5_commands.H>

namespace mss
{
namespace ody
{

///
/// @brief Maps DQS interval timer value to MR value encoding
/// @param [in] i_timer_val timer value in clocks from attribute
/// @return encoded MR value representing i_timer_val
///
uint8_t map_dqs_timer_val(const uint16_t i_timer_val)
{
    // Values taken from Jedec DDR5 spec JESD79-5B_v1.20 MR45 table
    // All values up to 1008 are just value/16
    if (i_timer_val <= 1008)
    {
        return i_timer_val / 16;
    }

    // Set all values between 1009 and 2048 clocks to the 2048 value
    if (i_timer_val <= 2048)
    {
        return 0x40;
    }

    // Set all values between 2049 and 4096 clocks to the 4096 value
    if (i_timer_val <= 4096)
    {
        return 0x80;
    }

    // Set all higher values to the 8192 value
    return 0xC0;
}

///
/// @brief Asserts snoop on MSB or LSB for DQS->DQ tracking
/// @param [in] i_target OCMB to assert snoop on
/// @param [in] i_mr_number mr to asset snoop on, should only be 46 or 47
/// @return fapi2::FAPI2_RC_SUCCESS iff successful, fapi2 error code otherwise
///
fapi2::ReturnCode assert_mr_snoop (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const drift_track_mr i_mr_number)
{
    fapi2::buffer<uint64_t> l_farb2q_data;
    FAPI_TRY(getScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB2Q, l_farb2q_data));

    // Clear both bits first
    l_farb2q_data.clearBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_SNOOP_EN_LSB>();
    l_farb2q_data.clearBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_SNOOP_EN_MSB>();

    if (i_mr_number == drift_track_mr::LSB_MR)
    {
        l_farb2q_data.setBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_SNOOP_EN_LSB>();
    }
    else
    {
        l_farb2q_data.setBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_SNOOP_EN_MSB>();
    }

    FAPI_TRY(putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB2Q, l_farb2q_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Disables snoop on MSB or LSB for DQS->DQ tracking
/// @param [in] i_target OCMB to assert snoop on
/// @return fapi2::FAPI2_RC_SUCCESS iff successful, fapi2 error code otherwise
///
fapi2::ReturnCode disable_mr_snoop(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_farb2q_data;
    FAPI_TRY(getScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB2Q, l_farb2q_data));

    l_farb2q_data.clearBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_SNOOP_EN_LSB>();
    l_farb2q_data.clearBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_SNOOP_EN_MSB>();

    FAPI_TRY(putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB2Q, l_farb2q_data));

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Prepares mrr ccs instructions for given mr
/// @param [in] i_rank_info rank info
/// @param [in] i_mr_number mr to to be read
/// @param[in,out] io_program the ccs program
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode prepare_mrr_ccs(
    const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
    const drift_track_mr i_mr_number,
    mss::ccs::program<mss::mc_type::ODYSSEY>& io_program)
{
    // Idling until the data is returned by the DRAM to ensure it's logged by the PHY
    constexpr uint64_t IDLES = 128;
    const auto& l_port_rank = i_rank_info.get_port_rank();
    // Create local mrr instruction for LSB/MSB snoop
    mss::ccs::instruction_t<mss::mc_type::ODYSSEY> l_inst;

    l_inst = mss::ccs::ddr5::mrr_command<mss::mc_type::ODYSSEY>(l_port_rank, uint64_t(i_mr_number), IDLES);
    io_program.iv_instructions.push_back(l_inst);

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Prepares mrw ccs instructions for given mr
/// @param [in] i_rank_info rank info
/// @param [in,out] io_program the ccs program
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_dqs_timer_val(
    const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
    mss::ccs::program<mss::mc_type::ODYSSEY>& io_program)
{
    constexpr uint64_t DQS_INTERVAL_MR = 45;
    constexpr uint16_t TMRD = 34;

    mss::ccs::instruction_t<mss::mc_type::ODYSSEY> l_inst;
    uint16_t l_dqs_interval = 0;
    uint8_t l_encoded = 0;
    const auto& l_port_rank = i_rank_info.get_port_rank();
    const auto& l_port_target = i_rank_info.get_port_target();

    // Grab dqs value from attr
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_OSC_RUNTIME_SEL, l_port_target, l_dqs_interval));
    l_encoded = map_dqs_timer_val(l_dqs_interval);

    FAPI_DBG(GENTARGTIDFORMAT " DQS interval: 0x%04X (encoded to: 0x%02X)",
             GENTARGTID(l_port_target), l_dqs_interval, l_encoded);

    l_inst = mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>(l_port_rank, DQS_INTERVAL_MR, l_encoded, TMRD);
    io_program.iv_instructions.push_back(l_inst);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Prepares oscillator start mpc command for ccs inst
/// @param [in] i_rank_info rank info
/// @param [in] i_op the operator for this MPC command OP[7:0]
/// @param [in,out] io_program the ccs program
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode prepare_oscillator_mpc(
    const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
    const mpc_command i_op,
    mss::ccs::program<mss::mc_type::ODYSSEY>& io_program)
{
    mss::ccs::instruction_t<mss::mc_type::ODYSSEY> l_inst;
    uint16_t l_dqs_interval = 0;
    const auto& l_port_rank = i_rank_info.get_port_rank();
    const auto& l_port_target = i_rank_info.get_port_target();

    if (i_op == mpc_command::OSCILLATOR_START)
    {
        // Oscillator time delay is tMRD + the DQS interval
        // using the maximum tMRD (34 clocks at 4800)
        constexpr uint64_t tMRD = 34;

        // Grab dqs value to delay to cover timer setting programmed into mr45
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_OSC_RUNTIME_SEL, l_port_target, l_dqs_interval));

        // Start Oscillator
        l_inst = mss::ccs::ddr5::mpc_command<mss::mc_type::ODYSSEY>(l_port_rank, uint64_t(i_op), l_dqs_interval + tMRD);
    }
    else
    {
        // Stop oscillator (no delay needed)
        l_inst = mss::ccs::ddr5::mpc_command<mss::mc_type::ODYSSEY>(l_port_rank, uint64_t(i_op));
    }

    io_program.iv_instructions.push_back(l_inst);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Execute CCS program in concurrent mode
/// @param [in] i_rank_info rank info
/// @param [in,out] io_program the ccs program
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode execute_concurrent_ccs(
    const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
    mss::ccs::program<mss::mc_type::ODYSSEY>& io_program)
{
    fapi2::buffer<uint64_t> l_modeq_reg;
    fapi2::buffer<uint64_t> l_farb0q;

    const auto& l_port = i_rank_info.get_port_target();
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port);

    FAPI_TRY(mss::ccs::stop_ccs_and_mcbist<mss::mc_type::ODYSSEY>(l_ocmb));

    FAPI_DBG(GENTARGTIDFORMAT " Executing DQS drift track and recal via concurrent CCS", GENTARGTID(l_ocmb));

    // Configure CCS regs for execution
    FAPI_TRY( mss::ccs::config_ccs_regs_for_concurrent<mss::mc_type::ODYSSEY>(l_ocmb, l_modeq_reg, mss::states::OFF ) );

    // Backup FARB0Q value before running Concurrent CCS
    FAPI_TRY( mss::ccs::pre_execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb, l_farb0q) );

    // Run CCS via MCBIST for Concurrent CCS
    FAPI_TRY( mss::ccs::execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb, io_program, l_port) );

    // Restore FARB0Q value after running Concurrent CCS
    FAPI_TRY( mss::ccs::post_execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb, l_farb0q) );

    // Revert CCS regs after execution
    FAPI_TRY( mss::ccs::revert_config_regs<mss::mc_type::ODYSSEY>(l_ocmb, l_modeq_reg) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Tracks dqs and recalibrates to ATTR_ODY_DQS_OSC_RUNTIME_SEL
/// @param [in] i_rank_info rank info
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dqs_recal(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info)
{
    const auto& l_port_target = i_rank_info.get_port_target();
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    mss::ccs::program<mss::mc_type::ODYSSEY> l_program;

    // Assert LSB snoop on MRR
    FAPI_TRY(assert_mr_snoop(l_ocmb_target, drift_track_mr::LSB_MR));

    // We need two CCS programs since we can only snoop LSB or MSB individually
    // First CCS program: run the oscillator, then read/snoop MR46
    {
        // Prepares mpc command to start oscillator
        FAPI_TRY(prepare_oscillator_mpc(i_rank_info, mpc_command::OSCILLATOR_START, l_program));

        // MRR for the LSB
        FAPI_TRY(prepare_mrr_ccs(i_rank_info, drift_track_mr::LSB_MR, l_program));

        // Executes the CCS program in concurrent mode
        FAPI_TRY(execute_concurrent_ccs(i_rank_info, l_program));
    }

    // Assert MSB snoop on MRR
    FAPI_TRY(assert_mr_snoop(l_ocmb_target, drift_track_mr::MSB_MR));

    l_program.iv_instructions.clear();

    // Second CCS program: read/snoop MR47
    {
        // MRR for the LSB
        FAPI_TRY(prepare_mrr_ccs(i_rank_info, drift_track_mr::MSB_MR, l_program));

        // Executes the CCS program in concurrent mode
        FAPI_TRY(execute_concurrent_ccs(i_rank_info, l_program));
    }

    // Clear the snoop bit
    FAPI_TRY(disable_mr_snoop(l_ocmb_target));

fapi_try_exit:
    return fapi2::current_err;

}


///
/// @brief Ody DQS track procedure
/// @param [in] i_target OCMB target
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode ody_dqs_track(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    std::vector<mss::rank::info<mss::mc_type::ODYSSEY>> l_rank_infos;

    for(auto& l_port_target : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target) )
    {
        FAPI_TRY(mss::rank::ranks_on_port<mss::mc_type::ODYSSEY>(l_port_target, l_rank_infos));

        for(auto l_rank_info : l_rank_infos)
        {
            FAPI_TRY(dqs_recal(l_rank_info));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // end ns ody
} // end ns mss
