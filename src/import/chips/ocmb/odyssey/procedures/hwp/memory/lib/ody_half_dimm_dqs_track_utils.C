/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ody_half_dimm_dqs_track_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2024                        */
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
/// @file ody_half_dimm_dqs_track_utils.C
/// @brief  Tool to track and recal DQS for half dimm mode
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: SBE

#include <fapi2.H>
#include <vector>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <ody_dqs_track_utils.H>
#include <ody_half_dimm_dqs_track_utils.H>
#include <lib/dimm/ody_rank.H>
#include <ody_scom_ody_odc.H>
#include <lib/shared/ody_consts.H>
#include <lib/ccs/ody_ccs_traits.H>
#include <lib/mc/ody_port_traits.H>
#include <lib/mcbist/ody_mcbist_traits.H>
#include <lib/ccs/ody_ccs.H>
#include <lib/phy/ody_phy_access.H>
#include <generic/memory/lib/ccs/ccs_ddr5_commands.H>
#include <lib/power_thermal/ody_thermal_init_utils.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <ody_scom_mp_dbyte0_b0.H>
#include <ody_scom_mp_dbyte1_b0.H>
#include <ody_scom_mp_dbyte2_b0.H>
#include <ody_scom_mp_dbyte3_b0.H>
#include <ody_scom_mp_dbyte4_b0.H>
#include <ody_scom_mp_dbyte5_b0.H>
#include <ody_scom_mp_dbyte6_b0.H>
#include <ody_scom_mp_dbyte7_b0.H>
#include <ody_scom_mp_dbyte8_b0.H>
#include <ody_scom_mp_dbyte9_b0.H>
#include <ody_scom_ody_odc.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <lib/ody_attribute_accessors_manual.H>
#include <lib/fir/ody_fir.H>
#include <lib/fir/ody_fir_traits.H>

namespace mss
{
namespace ody
{

///
/// @brief Polls to see if the bus has quiesced
/// @param[in] i_target the target on which to operate
/// @param[out] o_is_quiesced true if the bus has quiesced
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode poll_for_quiesced(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target, bool& o_is_quiesced)
{
    // Waiting a LONG time as it can take 8ms for the chip op to filter through the Odyssey
    // The processor will wait 8ms, then set the FIR bit and the quiesce window
    mss::poll_parameters l_params;
    l_params.iv_poll_count = 10000000;

    // The quiesce has a two stage latching to avoid finding a false quiesce state
    // The MCU sets SRQ LRFIR bit 28 first to show that this is not a false quiesce
    bool l_is_fir_set = mss::poll(i_target, scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR, l_params,
                                  [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& i_data) -> bool
    {
        // The latching FIR is set
        return is_latching_fir_set(i_data);
    });

    // The quiesce state never materialized, exit out
    if(!l_is_fir_set)
    {
        o_is_quiesced = false;
        return fapi2::current_err;
    }

    // The MCU issued the quiesce. Now polls to make sure that all commands have drained out of the Odyssey
    o_is_quiesced = mss::poll(i_target, scomt::ody::ODC_SRQ_MBA_FARB6Q, l_params,
                              [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& i_data) -> bool
    {
        // The port is quiesced if no commands are present in the queue depth
        // Bus is quiesced if there are no reads queued
        return are_read_queues_empty(i_data);
    });

    return fapi2::current_err;
}

///
/// @brief Advances the algorithm to target the next configured port/channel/rank
/// @param[in] i_target the target on which to operate
/// @param[in] i_ports the ports for the target in question
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode next_port_channel_rank_info(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>& i_ports)
{
    // This is one beyond the maximum allowed value
    constexpr uint8_t ATTR_END = 16;
    constexpr uint8_t ATTR_BEGIN = 0;

    // If the card has no ports, skip running this card. We will not have any valid ranks at that point to run on
    if(i_ports.empty())
    {
        FAPI_INF_NO_SBE(TARGTIDFORMAT " has no valid ports. Unable to run. Setting error attribute and exiting", TARGTID);
        return FAPI_ATTR_SET_CONST(fapi2::ATTR_ODY_DQS_TRACKING_FAILED, i_target, fapi2::ENUM_ATTR_ODY_DQS_TRACKING_FAILED_YES);
    }

    const auto& l_port = i_ports[0];
    uint8_t l_mrank_per_dimm[mss::ody::MAX_DIMM_PER_PORT] = {};
    uint8_t l_current = 0;
    FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(l_port, l_mrank_per_dimm));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_HALF_DIMM_TARGET, i_target, l_current));

    // Increments the attribute value
    ++l_current;

    // The attribute encodes the port, channel, and rank
    // Different cards will have a differing number of ranks and ports
    // The attribute value is incremented until a valid encoding is found or the end value is reached
    // If the end value is reached, then the value is reset back to 0
    for(; l_current < ATTR_END; ++l_current)
    {
        // Checks if the rank is valid
        const auto l_current_rank = extract_rank_from_target_attr(l_current);

        if(l_current_rank >= l_mrank_per_dimm[0])
        {
            FAPI_DBG("rank is out of bounds:%u vs %u with current value of 0x%02x for " TARGTIDFORMAT,
                     l_current_rank, l_mrank_per_dimm[0], l_current, GENTARGTID(l_port));
            continue;
        }

        // Note: not checking if the channel is valid. If a single channel card is implemented and needs to be run this way, this code will have to update

        // Checks if the port is valid
        const auto l_current_port = extract_port_from_target_attr(l_current);

        if(l_current_port >= uint64_t(i_ports.size()))
        {
            FAPI_DBG("port is out of bounds:%u vs %u with current value of 0x%02x for " TARGTIDFORMAT,
                     l_current_port, i_ports.size(), l_current, GENTARGTID(l_port));
            continue;
        }

        break;
    }

    // Handles the overflow case
    l_current = l_current == ATTR_END ? ATTR_BEGIN : l_current;
    FAPI_DBG("Next value to run on is 0x%02x for " TARGTIDFORMAT, GENTARGTID(l_port));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_DQS_TRACKING_HALF_DIMM_TARGET, i_target, l_current));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the port/channel/rank targetting information from the targetting attribute
/// @param[in] i_ports the memory ports on which to operate
/// @param[in] i_attr the attribute value on which to operate
/// @param[out] o_rank_info the rank info containing the port/rank extracted from the targetting attribute
/// @param[out] o_channel the channel extracted from the targetting attribute
/// @param[out] o_mr the drift track MR value on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode get_port_channel_rank_info(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>& i_ports,
        const uint8_t i_attr,
        mss::rank::info<mss::mc_type::ODYSSEY>& o_rank_info,
        mss::ccs::channel_select& o_channel,
        drift_track_mr& o_mr )
{
    constexpr uint8_t CHANNELA_ENCODE = 0;

    const uint8_t l_rank_num = extract_rank_from_target_attr(i_attr);
    const uint8_t l_port_num = extract_port_from_target_attr(i_attr);

    o_channel = extract_channel_from_target_attr(i_attr) == CHANNELA_ENCODE ?
                mss::ccs::channel_select::CHA : mss::ccs::channel_select::CHB;
    o_mr = extract_mr_from_target_attr(i_attr);
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    FAPI_ASSERT(l_port_num < i_ports.size(),
                fapi2::MSS_INVALID_PORT_INDEX_PASSED()
                .set_INDEX(l_port_num)
                .set_FUNCTION(mss::generic_ffdc_codes::HALF_DIMM_DQS_PORT_SELECT),
                "port number selected (%u) is out of bounds for the number of confgured ports (%u)", l_port_num, i_ports.size());

    o_rank_info = mss::rank::info<mss::mc_type::ODYSSEY>(i_ports[l_port_num], l_rank_num, l_rc);
    FAPI_TRY(l_rc);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Sets up the CCS program to run the next iteration of the half-dimm DQS track algorithm
/// @param[in] i_rank_info the rank information class upon which to operate
/// @param[in] i_mr the drift track MR value on which to operate
/// @param[in,out] io_program the program to update
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_ccs_halfdimm_dqs_instructions(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
        const drift_track_mr& i_mr,
        mss::ccs::program<mss::mc_type::ODYSSEY>& io_program )
{
    // Different instructions get configured depending upon the MR
    // If this is the LSB, the oscillator start needs to be configured first
    // The LSB is the first run for a given port/channel/rank, so the oscillator must be run at the outset
    if(i_mr == drift_track_mr::LSB_MR)
    {
        FAPI_TRY(prepare_oscillator_mpc(i_rank_info, mpc_command::OSCILLATOR_START, io_program));
    }

    // Appends the MRR command
    FAPI_TRY(prepare_mrr_ccs(i_rank_info, i_mr, io_program));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures the CCS engine to run the next test
/// @param[in] i_target the OCMB chip on which to operate
/// @param[in] i_ports the ports for the target in question
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_ccs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_ports)
{
    mss::rank::info<mss::mc_type::ODYSSEY> l_rank_info;
    mss::ccs::channel_select l_channel;
    drift_track_mr l_mr;
    mss::ccs::program<mss::mc_type::ODYSSEY> l_program;
    uint8_t l_current = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_HALF_DIMM_TARGET, i_target, l_current));

    // Gets the target information for the port/channel/rank
    FAPI_TRY(get_port_channel_rank_info(i_ports, l_current, l_rank_info, l_channel, l_mr));

    // Sets up the instructions
    FAPI_TRY(setup_ccs_halfdimm_dqs_instructions(l_rank_info, l_mr, l_program));

    // Loads the instructions
    {
        auto l_inst_iter = l_program.iv_instructions.begin();
        FAPI_TRY(mss::ccs::setup_ccs_instructions<mss::mc_type::ODYSSEY>( i_target,
                 l_inst_iter,
                 l_program,
                 l_rank_info.get_port_target()));
    }

    // Gets the port's relative position and confgures the select port function
    FAPI_TRY(mss::ccs::select_ports<mss::mc_type::ODYSSEY>( i_target,
             mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(l_rank_info.get_port_target()),
             l_channel));

    // Configures the FARB2 register based upon the channel and port rank
    FAPI_TRY(mss::ccs::workarounds::configure_ccs_farb2(i_target, l_rank_info.get_port_rank()));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets up the initial CCS test and the addressing for the cleanup command
/// @param[in] i_target the OCMB chip on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note exits if the DIMM is not in half-DIMM mode
///
fapi2::ReturnCode setup_ccs_initial(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    bool l_is_half_dimm_mode = false;
    FAPI_TRY(mss::ody::half_dimm_mode(i_target, l_is_half_dimm_mode));

    // If the Odyssey is not in half-dimm mode, then skip running
    // DQS drift track will be run via the internal polling mechanism
    if(!l_is_half_dimm_mode)
    {
        FAPI_DBG(TARGTIDFORMAT " is not in half-dimm mode. Skipping setting up the initial CCS array", TARGTID);
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Configures the CCS engine
    FAPI_TRY(configure_ccs(i_target, mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target)));

    // Sets up the MCBIST addressing
    {
        constexpr uint64_t START = 0;
        constexpr uint64_t END = 0;
        fapi2::buffer<uint64_t> l_data;

        // Only run a single addressing
        FAPI_TRY( mcbist::config_address_range0<mss::mc_type::ODYSSEY>(i_target, START, END) );

        // Configures the MCBIST and CCS execute tests
        FAPI_TRY(configure_mcbist_test(i_target));

        // Configures the chip to run in maint mode for MCBIST tests
        FAPI_TRY( fapi2::getScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBAGRAQ, l_data) );
        l_data.setBit<scomt::ody::ODC_MCBIST_SCOM_MCBAGRAQ_CFG_MAINT_ADDR_MODE_EN>();
        FAPI_TRY( fapi2::putScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBAGRAQ, l_data) );
    }

    // Masks of SRQ LFIR[28] as this is a latch to help communicate and avoid a false quiesce state
    {
        mss::fir::reg2<scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR> l_fir(i_target);
        FAPI_TRY(l_fir.masked<scomt::ody::ODC_SRQ_LFIR_IN28>());
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setsup the CCS array for the next execution
/// @param[in] i_target the OCMB chip on which to operate
/// @param[in] i_ports the ports for the target in question
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_ccs_next_run(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                     const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_ports)
{
    // Advances to the next valid port/channel/rank target
    FAPI_TRY(next_port_channel_rank_info(i_target, i_ports));

    // Configures the CCS engine
    FAPI_TRY(configure_ccs(i_target, i_ports));

    // Masks of SRQ LFIR[28] as this is a latch to help communicate and avoid a false quiesce state
    {
        mss::fir::reg2<scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR> l_fir(i_target);
        FAPI_TRY(l_fir.clear<scomt::ody::ODC_SRQ_LFIR_IN28>());
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures the MCBIST and CCS execution for the second run within the chip op
/// @param[in] i_target the OCMB chip on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_mcbist_test(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    // Using hardcoded values here - each subtest is 16 bits
    // 0xF000............ -> execute the CCS test
    // 0x....C008........ -> run display command with ECC on port 0
    // 0x....C00C........ -> run display command with ECC on port 0 and exit
    // 0x........C20C.... -> run display command with ECC on port 1 and exit
    constexpr uint64_t ONE_PORT_MCBMR = 0xF000C00C00000000;
    constexpr uint64_t TWO_PORT_MCBMR = 0xF000C008C20C0000;
    const auto& l_all_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    const uint64_t DATA = l_all_ports.size() == 1 ? ONE_PORT_MCBMR : TWO_PORT_MCBMR;
    return fapi2::putScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBMR0Q, DATA);
}

///
/// @brief Execute CCS program in concurrent mode
/// @param[in] i_target the OCMB chip on which to operate
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode execute_half_dimm_concurrent_ccs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    constexpr drift_track_mr LOG_DATA_MR = drift_track_mr::MSB_MR;
    constexpr uint8_t UNUSED_LOGGING_INFO = 0;
    constexpr bool TEMP_TRIGGER = false;
    constexpr uint8_t MISSED_QUIESCE_THRESHOLD = 10;
    bool l_has_quiesced = false;
    // Consts for readability
    constexpr bool RECORD_OFFSETS = false;
    constexpr bool COMPUTE_DELTAS = true;
    fapi2::buffer<uint64_t> l_modeq_reg;
    fapi2::buffer<uint64_t> l_farb0q;
    fapi2::buffer<uint64_t> l_fir_mask_save;
    fapi2::buffer<uint64_t> l_periodics_reg;
    fapi2::buffer<uint64_t> l_power_cntl_reg;

    const auto& l_ocmb = i_target;
    mss::rank::info<mss::mc_type::ODYSSEY> l_rank_info;
    mss::ccs::channel_select l_channel;
    drift_track_mr l_mr;

    const auto& l_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
    uint8_t l_current = 0;
    uint8_t l_missed_quiesce_count = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_HALF_DIMM_TARGET, i_target, l_current));

    // The odyssey has a chip bug where an internal array error happens in half-dimm mode
    // The bus has to be cleaned up by running a mainline style read
    // Due to the risk of the cleaunup not happening first, the bus has to be quiesced for the algorithm to be run
    // Due to the timing of the quiesce in the affected systems, only a single port/rank/channel/MR is conducted each time the procedure is called
    // An attribute is used to keep track of the next item to run
    {
        FAPI_TRY(get_port_channel_rank_info(l_ports, l_current, l_rank_info, l_channel, l_mr));
        const auto& l_port_target = l_rank_info.get_port_target();

        // get_port_channel_rank_info checks for an out of bounds port, indexing here is sufficient
        // The PMIC telemetry code reads the logging information only out of port 0, so we need to grab port 0 here
        const auto& l_telemtry_log_port = l_ports[0];

        std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> > l_single_port;
        l_single_port.push_back(l_rank_info.get_port_target());

        fapi2::buffer<uint16_t> l_deltas[mss::ddr5::ATTR_ODY_DQS_TRACKING_LOG_DELTA_COUNT] __attribute__ ((__aligned__(8))) = {0};
        int16_t l_offsets[HW_MAX_RANK_PER_DIMM][ODY_NUM_DRAM_X4] __attribute__ ((__aligned__(8))) = {0};

        // Only log the data on one of the MR
        // We need to read out two MR as the deltas are 16-bits. The second MR read will cause the PHY to update
        // As such, we only need to log data on the second MR
        // Why split this up? timing. We only have 200us to do the CCS and cleanup afterwards
        if(LOG_DATA_MR == l_mr)
        {
            // Clear out deltas
            for (uint8_t l_idx = 0; l_idx < mss::ddr5::ATTR_ODY_DQS_TRACKING_LOG_DELTA_COUNT; l_idx++)
            {
                l_deltas[l_idx] = 0;
            }

            // Record the current DQS offsets - Offsets should be for the port under test
            FAPI_TRY(ody_get_dqs_offsets(l_port_target, RECORD_OFFSETS, l_offsets, l_deltas));
        }

        // Polls for quiesced complete, if not, exit out
        // The odyssey has a chip bug where an internal array error happens in half-dimm mode
        // The bus has to be cleaned up by running a mainline style read
        // Due to the risk of the cleaunup not happening first, the bus has to be quiesced for the algorithm to be run
        FAPI_TRY(poll_for_quiesced(i_target, l_has_quiesced));

        if(!l_has_quiesced)
        {
            FAPI_INF_NO_SBE("Bus did not quiesce in time. skipping procedure on " TARGTIDFORMAT, TARGTID);

            // Update our "missed quiesce" counter and return a fail if we hit the threshold
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_MISSED_QUIESCE_COUNT, i_target, l_missed_quiesce_count));
            l_missed_quiesce_count += 1;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_DQS_TRACKING_MISSED_QUIESCE_COUNT, i_target, l_missed_quiesce_count));

            FAPI_ASSERT(l_missed_quiesce_count < MISSED_QUIESCE_THRESHOLD,
                        fapi2::MSS_ODY_DQS_DRIFT_TRACK_UNABLE_TO_QUIESCE_BUS().
                        set_MC_TARGET(i_target).
                        set_MISSED_QUIESCE_COUNT(l_missed_quiesce_count).
                        set_MISSED_QUIESCE_THRESHOLD(MISSED_QUIESCE_THRESHOLD),
                        GENTARGTIDFORMAT " DQS drift track unable to detect bus quiesce state for %d attempts",
                        GENTARGTID(i_target), l_missed_quiesce_count);

            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Reset the "missed quiesce" counter since we see the bus quiesced
        FAPI_TRY(FAPI_ATTR_SET_CONST(fapi2::ATTR_ODY_DQS_TRACKING_MISSED_QUIESCE_COUNT, i_target, 0));

        // Conducts the first MCBIST/CCS run
        {

            // Asserts the snoop for this run
            FAPI_TRY(assert_mr_snoop(l_ocmb, l_mr));

            // Configure CCS regs for execution
            FAPI_TRY(mss::ccs::config_ccs_regs_for_concurrent<mss::mc_type::ODYSSEY>(l_ocmb, l_modeq_reg, mss::states::OFF ) );

            // Backup FARB0Q value before running Concurrent CCS
            FAPI_TRY(mss::ccs::pre_execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb, l_farb0q) );

            // Mask MCBISTFIRQ[MCBIST_PROGRAM_COMPLETE] to avoid unnecessary attentions
            FAPI_TRY(mss::memdiags::mask_program_complete<mss::mc_type::ODYSSEY>(l_ocmb, l_fir_mask_save) );

            // Note: scoping the use of the program to reduce the number of active vectors at a time to avoid SBE crashes
            {
                mss::ccs::program<mss::mc_type::ODYSSEY> l_program;
                FAPI_TRY(mss::ccs::setup_to_execute<mss::mc_type::ODYSSEY>(l_ocmb, l_single_port, l_program, l_periodics_reg,
                         l_power_cntl_reg));
            }

            // Run CCS via MCBIST for Concurrent CCS
            // Note: false notes that we will NOT check the data compare logs
            FAPI_TRY( mss::ccs::run_inst_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb, false) );
        }

        // Cleans up and sets up the next run
        {
            // Note: scoping the use of the program to reduce the number of active vectors at a time to avoid SBE crashes
            {
                mss::ccs::program<mss::mc_type::ODYSSEY> l_program;
                FAPI_TRY(( mss::ccs::cleanup_from_execute<mss::mc_type::ODYSSEY>(l_ocmb, l_program, l_single_port, l_periodics_reg,
                           l_power_cntl_reg)));
            }

            // Clear MCBISTFIRQ[MCBIST_PROGRAM_COMPLETE] and restore the mask
            FAPI_TRY( mss::memdiags::clear_and_restore_program_complete<mss::mc_type::ODYSSEY>(l_ocmb, l_fir_mask_save) );

            // Restore FARB0Q value after running Concurrent CCS
            FAPI_TRY( mss::ccs::post_execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb, l_farb0q) );

            // Clear the snoop bit
            FAPI_TRY(disable_mr_snoop(l_ocmb));

            // Sets up the next CCS run
            FAPI_TRY(setup_ccs_next_run(l_ocmb, l_ports));
        }

        // Compute and log the DQS tracking information
        // Only log the data on one of the MR
        // We need to read out two MR as the deltas are 16-bits. The second MR read will cause the PHY to update
        // As such, we only need to log data on the second MR
        // Why split this up? timing. We only have 200us to do the CCS and
        if(LOG_DATA_MR == l_mr)
        {
            // Compute the DQS offset deltas - use the port under test as these values should have updated
            FAPI_TRY(ody_get_dqs_offsets(l_port_target, COMPUTE_DELTAS, l_offsets, l_deltas));

            // Log the tracking info
            FAPI_TRY(ody_dqs_track_log(l_ocmb,
                                       TEMP_TRIGGER,
                                       UNUSED_LOGGING_INFO,
                                       UNUSED_LOGGING_INFO,
                                       l_deltas));

            // Write the log and count into a port's imem area - use the telemetry log port
            FAPI_TRY(ody_putscom_dqs_track_log(l_telemtry_log_port));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Wrapper that checks if the DQS tracking operation has failed. If not, runs the DQS tracking operation
/// @param[in] i_target the OCMB chip on which to operate
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode ody_half_dimm_dqs_track(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{

    // If the procedure failed before, skip it
    uint8_t l_has_failed = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_FAILED, i_target, l_has_failed));

    if (l_has_failed == fapi2::ENUM_ATTR_ODY_DQS_TRACKING_FAILED_YES)
    {
        FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Skipping DQS drift tracking due to previous fail state",
                        GENTARGTID(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(execute_half_dimm_concurrent_ccs(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    // Handles the DQS track errors
    return handle_dqs_track_error(i_target);
}
} // namespace ody
} // namespace mss
