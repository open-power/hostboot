/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ccs/ccs.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
/// @file ccs.H
/// @brief Run and manage the CCS engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CCS_H_
#define _MSS_CCS_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <generic/memory/lib/ccs/ccs_traits.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/ccs/ccs_instruction.H>

namespace mss
{

namespace ccs
{

// Generally, the CCS commands are split up into separate files for DDR4 and for DDR5
// However, the execute functions need access to a generic deselect function
// As such, a deselect helper has been created that can be specialized on a per memory controller basis

///
/// @brief Create, initialize a JEDEC Device Deselect CCS command
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the Device Deselect CCS instruction
/// @note This is a helper to allow for DDR4 and DDR5 differences
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
instruction_t<MC> des_command(const uint16_t i_idle = 0);

///
/// @brief Determines our rank configuration type
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_target the MCA target on which to operate
/// @param[out] o_rank_config the rank configuration
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline fapi2::ReturnCode get_rank_config(const fapi2::Target<TT::PORT_TARGET_TYPE>& i_target,
        rank_configuration& o_rank_config)
{
    constexpr uint8_t QUAD_RANK_ENABLE = 4;
    o_rank_config = rank_configuration::DUAL_DIRECT;

    uint8_t l_num_master_ranks[TT::CCS_MAX_DIMM_PER_PORT] = {};
    bool l_has_rcd = false;
    FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_target, l_num_master_ranks));
    FAPI_TRY(TT::get_has_rcd(i_target, l_has_rcd));

    // We only need to check DIMM0
    // Our number of ranks should be the same between DIMM's 0/1
    // Check if we have the right number for encoded mode
    // And that we have an RCD
    o_rank_config = ((l_num_master_ranks[0] == QUAD_RANK_ENABLE) && (l_has_rcd)) ?
                    rank_configuration::QUAD_ENCODED :
                    rank_configuration::DUAL_DIRECT;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines our rank configuration type across all ports
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// @param[in] i_target the MCA target on which to operate
/// @param[out] o_rank_config the rank configuration
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
inline fapi2::ReturnCode get_rank_config(const fapi2::Target<TT::MC_TARGET_TYPE>& i_target,
        std::vector<rank_configuration>& o_rank_config)
{
    o_rank_config.clear();
    // Create one per port, we then use relative indexing to get us the number we need
    o_rank_config = std::vector<rank_configuration>(TT::PORTS_PER_MC_TARGET);

    for(const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target))
    {
        rank_configuration l_config;
        FAPI_TRY(get_rank_config<MC>(l_port, l_config));
        o_rank_config[mss::relative_pos<MC, TT::MC_TARGET_TYPE>(l_port)] = l_config;
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief A class representing a series of CCS instructions, and the
/// CCS engine parameters associated with running the instructions
/// @tparam MC The memory controller type of the traits
/// @tparam TT the CCS traits related to MC
/// contains the CCS engine
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
class program
{
    public:
        // Setup our poll parameters so the CCS executer can see
        // whether to use the delays in the instruction stream or not
        program(): iv_poll(0, 0)
        {}

        // Vector of instructions
        std::vector< instruction_t<MC> > iv_instructions;
        poll_parameters                 iv_poll;

        // Vector of polling probes
        std::vector< poll_probe<TT::PORT_TARGET_TYPE> >    iv_probes;
};

//
// These functions are a little sugar to keep callers from doing the traits-dance to get the
// appropriate bit field
//

///
/// @brief Select the port(s) to be used by the CCS
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_ports the buffer representing the ports
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
fapi2::ReturnCode select_ports( const fapi2::Target<T>& i_target, uint64_t i_ports);

///
/// @brief User sets to a '1'b to tell the Hdw to stop CCS whenever failure occurs. When a
///        '0'b, Hdw will continue CCS even if a failure occurs.
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in]  the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_value true iff stop whenever failure occurs.
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
inline void stop_on_err( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer, const states i_value)
{
    io_buffer.writeBit<TT::STOP_ON_ERR>(i_value);
}

///
/// @brief Disable ECC checking on the CCS arrays
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
inline void disable_ecc( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer)
{
    io_buffer.setBit<TT::DISABLE_ECC_ARRAY_CHK>()
    .template setBit<TT::DISABLE_ECC_ARRAY_CORRECTION>();
}

///
/// @brief User sets to a '1'b to force the Hdw to ignore any array ue or sue errors
///        during CCS command fetching.
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_value true iff ignore any array ue or sue errors.
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
inline void ue_disable( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer, const states i_value)
{
    io_buffer.writeBit<TT::UE_DISABLE>(i_value);
}

///
/// @brief User sets to a '1'b to force the Hdw to delay parity a cycle
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_value mss::ON iff delay parity a cycle
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
inline void parity_after_cmd( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer, const states i_value)
{
    io_buffer.writeBit<TT::CFG_PARITY_AFTER_CMD>(i_value);
}

///
/// @brief DDr calibration counter
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_count the count to wait for DDR cal to complete.
/// @param[in] i_mult the DDR calibration time multiplaction factor
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
inline void cal_count( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer,
                       const uint64_t i_count, const uint64_t i_mult)
{
    io_buffer.insertFromRight<TT::DDR_CAL_TIMEOUT_CNT, TT::DDR_CAL_TIMEOUT_CNT_LEN>(i_count);
    io_buffer.insertFromRight<TT::DDR_CAL_TIMEOUT_CNT_MULT, TT::DDR_CAL_TIMEOUT_CNT_MULT_LEN>(i_mult);
}

///
/// @brief Copy CKE signals to CKE Spare on both ports NOTE: DOESN'T APPLY FOR NIMBUS. NO
///        SPARE CHIPS TO COPY TO. 0 - Spare CKEs not copied with values from CKE(0:1) and
///         CKE(4:5) 1 - Port A CKE(0:1) copied to Port A CKE(2:3), Port A CKE(4:5) copied
///         to Port A CKE(6:7), Port B CKE(0:1) copied to Port B CKE(2:3) and Port B CKE(4:5)
///         copied to Port B CKE(6:7)
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the ccsTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_value mss::ON iff Copy CKE signals to CKE Spare on both ports
/// @note no-op for p9n
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
void copy_cke_to_spare_cke( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer, const states i_value);

///
/// @brief Read the modeq register appropriate for this target
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
inline fapi2::ReturnCode read_mode( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& io_buffer)
{
    return mss::getScom(i_target, TT::MODEQ_REG, io_buffer);
}

///
/// @brief Write the modeq register appropriate for this target
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_buffer the buffer representing the mode register
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
inline fapi2::ReturnCode write_mode( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_buffer)
{
    return mss::putScom(i_target, TT::MODEQ_REG, i_buffer);
}

///
/// @brief config the NTTM
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_mcbist the target to operate
/// @param[in] i_nttm_mode NTTM we need to turn on or off (i.e. ON, OFF)
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
inline fapi2::ReturnCode configure_nttm( const fapi2::Target<T>& i_target,
        const mss::states i_nttm_mode)
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(read_mode<MC>(i_target, l_data));

    l_data.writeBit<TT::NTTM_MODE>(i_nttm_mode);

    FAPI_TRY(write_mode<MC>(i_target, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures the chip to properly execute CCS instructions
/// @tparam MC the MC type on which to operate
/// @tparam P  the port type for this CCS engine - derived from i_ports
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
/// @note Code location for pre CCS execute workarounds
///
template< mss::mc_type MC, fapi2::TargetType P>
fapi2::ReturnCode setup_to_execute(const std::vector< fapi2::Target<P> >& i_ports);

///
/// @brief Cleans up the chip from executing CCS instructions
/// @tparam MC the MC type on which to operate
/// @tparam P  the port type for this CCS engine - derived from i_ports
/// @param[in] i_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
/// @note Code location for post CCS execute workarounds
///
template< mss::mc_type MC, fapi2::TargetType P>
fapi2::ReturnCode cleanup_from_execute(const ccs::program<MC>& i_program,
                                       const std::vector< fapi2::Target<P> >& i_ports);

///
/// @brief Start or stop the CCS engine
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target The MCBIST containing the CCS engine
/// @param[in] i_start_stop bool MSS_CCS_START for starting MSS_CCS_STOP otherwise
/// @return FAPI2_RC_SUCCESS iff success
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
fapi2::ReturnCode start_stop( const fapi2::Target<T>& i_target, const bool i_start_stop )
{
    fapi2::buffer<uint64_t> l_buf;

    // Do we need to read this? We are setting the only bit defined in the scomdef? BRS
    FAPI_TRY(mss::getScom(i_target, TT::CNTLQ_REG, l_buf));

    FAPI_TRY( mss::putScom(i_target, TT::CNTLQ_REG,
                           i_start_stop ? l_buf.setBit<TT::CCS_START>() : l_buf.setBit<TT::CCS_STOP>()) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determine the CCS failure type
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P the target of the CCS instruction (the port)
/// @param[in] i_target MC target
/// @param[in] i_type the failure type
/// @param[in] i_port The port the CCS instruction is training
/// @return ReturnCode associated with the fail.
/// @note FFDC is handled here, caller doesn't need to do it
///
template< mss::mc_type MC, typename TT = ccsTraits<MC>, fapi2::TargetType T = TT::MC_TARGET_TYPE, fapi2::TargetType P = TT::PORT_TARGET_TYPE >
fapi2::ReturnCode fail_type( const fapi2::Target<T>& i_target,
                             const uint64_t i_type,
                             const fapi2::Target<P>& i_port );

///
/// @brief Execute a CCS array already loaded in to the engine
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P the target of the CCS instruction (the port)
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_program the MCBIST ccs program - to get the polling parameters
/// @param[in] i_port the port associated with the MCBIST array
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<MC> >
fapi2::ReturnCode execute_inst_array(const fapi2::Target<T>& i_target,
                                     ccs::program<MC>& i_program,
                                     const fapi2::Target<P>& i_port)
{
    fapi2::buffer<uint64_t> status;

    FAPI_TRY(start_stop<MC>(i_target, mss::START), "%s Error in execute_inst_array", mss::c_str(i_port) );

    mss::poll(i_target, TT::STATQ_REG, i_program.iv_poll,
              [&status](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_DBG("ccs statq 0x%016lx, remaining: %d", stat_reg, poll_remaining);
        status = stat_reg;
        return status.getBit<TT::CCS_IN_PROGRESS>() != 1;
    },
    i_program.iv_probes);

    // Check for done and success. DONE being the only bit set.
    if (status == TT::STAT_QUERY_SUCCESS)
    {
        FAPI_INF("%s CCS Executed Successfully.", mss::c_str(i_port) );
        goto fapi_try_exit;
    }

    // So we failed or we're still in progress. Mask off the fail bits
    // and run this through the FFDC generator.
    FAPI_TRY(fail_type<MC>(i_target, status & TT::STAT_ERR_MASK, i_port), "Error in execute_inst_array" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Execute CCS loaded in to the CCS engine via the MCBIST engine
/// @tparam MC the memory controller type running CCS
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T>
fapi2::ReturnCode execute_inst_via_mcbist(const fapi2::Target<T>& i_target)
{
    mss::mcbist::program<MC> l_program;

    // Will need these to configure address range, if needed
    constexpr uint64_t START = 0;
    constexpr uint64_t END = 1;

    // Push back a ccsexec subtest (0x1111)
    l_program.iv_subtests.push_back( mss::mcbist::ccsexec_subtest<MC, T>() );

    // NOTE: Unsure if needed, if required, need to discover how to set the range up
    FAPI_TRY( mcbist::config_address_range0<MC>(i_target, START, END) );

    // Setup the polling based on lab experiments
    // Looks like tests run with 5 clock cycles or 6ns for polling, rounding to 10ns
    // Unsure if this will hold for all of CCS, but its a starting point
    l_program.iv_poll.iv_initial_delay = 10 * mss::DELAY_1NS;
    l_program.iv_poll.iv_delay = 10 * mss::DELAY_1NS;
    l_program.iv_poll.iv_poll_count = 10;

    // Kick it off, wait for a result
    FAPI_TRY( mss::mcbist::execute<MC>(i_target, l_program) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Updates the initial delays based upon the total delays passed in
/// @tparam MC the memory controller type running CCS
/// @tparam fapi2::TargetType T the type of the target running CCS
/// @param[in] i_target the target type on which to operate
/// @param[in] i_delay the calculated delays from CCS
/// @param[in,out] io_program the program for which to update the delays
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T  >
fapi2::ReturnCode update_initial_delays( const fapi2::Target<T>& i_target,
        const uint64_t i_delay,
        ccs::program<MC>& io_program);

///
/// @brief Execute first part of preperation for a set of CCS instructions - multiple ports
/// @tparam MC the memory controller type running CCS
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P  the port type for this CCS engine
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in, out] io_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<MC> >
static inline fapi2::ReturnCode prelude_to_execution( const fapi2::Target<T>& i_target,
        ccs::program<MC>& io_program,
        const std::vector< fapi2::Target<P> >& i_ports)
{
    FAPI_INF("loading ccs instructions (%d) for %s", io_program.iv_instructions.size(), mss::c_str(i_target));

    // Pre CCS execution configuration
    FAPI_TRY(setup_to_execute<MC>(i_ports));

    // Stop the CCS engine just for giggles - it might be running ...
    FAPI_TRY( start_stop<MC>(i_target, mss::states::STOP), "Error stopping CCS engine before ccs::execution on %s",
              mss::c_str(i_target) );

    FAPI_ASSERT( mss::poll(i_target, TT::STATQ_REG, poll_parameters(),
                           [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("ccs statq (stop) 0x%llx, remaining: %d", stat_reg, poll_remaining);
        return stat_reg.getBit<TT::CCS_IN_PROGRESS>() != 1;
    }),
    TT::setup_trying_to_stop_err(i_target), "CCS in progress bit timed out on %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup all the CCS registers for CCS instructions passed in
/// @tparam MC the memory controller type running CCS
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P  the port type for this CCS engine
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in, out] io_inst_iter the iterator for the ccs instructions
/// @param[in, out] io_program the vector of instructions
/// @param[in] i_port the port target to effect
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<MC>, typename IT = typename std::vector< mss::ccs::instruction_t<MC> >::iterator >
static inline fapi2::ReturnCode setup_ccs_instructions( const fapi2::Target<T>& i_target,
        IT io_inst_iter,
        ccs::program<MC>& io_program,
        const fapi2::Target<P>& i_port )
{
    // Subtract one for the idle we insert at the end
    constexpr size_t CCS_INSTRUCTION_DEPTH = TT::CCS_ARRAY_LEN - 1;
    constexpr uint64_t CCS_ARR0_ZERO = TT::CCS_ARR0_START;
    constexpr uint64_t CCS_ARR1_ZERO = TT::CCS_ARR1_START;

    size_t l_inst_count = 0;
    uint64_t l_total_delay = 0;
    uint64_t l_delay = 0;
    uint64_t l_repeat = 0;
    uint8_t l_current_cke = 0;

    // Grab port index and first inst
    const auto l_port_index = mss::relative_pos<MC, T>(i_port);
    ccs::instruction_t<MC> l_des =  mss::ccs::des_command<MC>();

    std::vector<rank_configuration> l_rank_configs;
    FAPI_TRY(get_rank_config<MC>(i_target, l_rank_configs));

    // Shove the instructions into the CCS engine, in 32 instruction chunks, and execute them
    // NOTE: For concurrent CCS the CCS_INSTRUCTION_DEPTH of 32 will never be hit
    for (; io_inst_iter != io_program.iv_instructions.end()
         && l_inst_count < CCS_INSTRUCTION_DEPTH; ++l_inst_count, ++io_inst_iter)
    {
        // First, update the current instruction's chip selects for the current port
        FAPI_TRY(io_inst_iter->configure_rank(i_port, l_rank_configs[l_port_index]),
                 "Error configuring rank in ccs::execute on port %s", mss::c_str(i_port));

        // Now, configure the idles and repeats within this instructino
        FAPI_TRY(io_inst_iter->configure_idles_and_repeats(i_port),
                 "Error configuring idles and repeats in ccs::execute on port %s", mss::c_str(i_port));

        io_inst_iter->get_cke_helper(l_current_cke);

        // Make sure this instruction leads to the next. Notice this limits this mechanism to pretty
        // simple (straight line) CCS programs. Anything with a loop or such will need another mechanism.
        io_inst_iter->arr1.template insertFromRight<TT::ARR1_GOTO_CMD, TT::ARR1_GOTO_CMD_LEN>(l_inst_count + 1);
        FAPI_TRY( mss::putScom(i_target, CCS_ARR0_ZERO + l_inst_count, io_inst_iter->arr0) );
        FAPI_TRY( mss::putScom(i_target, CCS_ARR1_ZERO + l_inst_count, io_inst_iter->arr1) );

        // arr1 contains a specification of the delay and repeat after this instruction, as well
        // as a repeat. Total up the delays as we go so we know how long to wait before polling
        // the CCS engine for completion
        l_delay = io_inst_iter->iv_idles;
        l_repeat = io_inst_iter->iv_repeats;

        l_total_delay += l_delay * (l_repeat + 1);

        FAPI_INF("css inst %d: 0x%016lX 0x%016lX (0x%lx, 0x%lx) delay: 0x%x (0x%x) %s",
                 l_inst_count, io_inst_iter->arr0, io_inst_iter->arr1,
                 CCS_ARR0_ZERO + l_inst_count, CCS_ARR1_ZERO + l_inst_count,
                 l_delay, l_total_delay, mss::c_str(i_target));
    }

    // Updates the initial delays
    FAPI_TRY(update_initial_delays<MC>(i_target, l_total_delay, io_program),
             "Failed in update_initial_delays for ccs::execute_via_mcbist on %s", mss::c_str(i_target));

    FAPI_INF("executing ccs instructions via MCBIST (%d:%d, %d) for %s",
             io_program.iv_instructions.size(), l_inst_count, io_program.iv_poll.iv_initial_delay, mss::c_str(i_target));

    // Deselect
    l_des.set_cke_helper(l_current_cke);

    // Insert a DES as our last instruction. DES is idle state anyway and having this
    // here as an instruction forces the CCS engine to wait the delay specified in
    // the last instruction in this array (which it otherwise doesn't do.)
    l_des.arr1.template setBit<TT::ARR1_END>();
    FAPI_TRY( mss::putScom(i_target, CCS_ARR0_ZERO + l_inst_count, l_des.arr0) );
    FAPI_TRY( mss::putScom(i_target, CCS_ARR1_ZERO + l_inst_count, l_des.arr1) );

    FAPI_INF("css inst %d fixup: 0x%016lX 0x%016lX (0x%lx, 0x%lx) %s",
             l_inst_count, l_des.arr0, l_des.arr1,
             CCS_ARR0_ZERO + l_inst_count, CCS_ARR1_ZERO + l_inst_count, mss::c_str(i_target));

fapi_try_exit:
    io_program.iv_instructions.clear();
    return fapi2::current_err;
}


///
/// @brief Execute a set of CCS instructions - multiple ports
/// @tparam MC the memory controller type running CCS
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P  the port type for this CCS engine
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in, out] io_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<MC> >
static inline fapi2::ReturnCode execute( const fapi2::Target<T>& i_target,
        ccs::program<MC>& io_program,
        const std::vector< fapi2::Target<P> >& i_ports)
{
    FAPI_INF("Execution standalone CCS commands (%d) for %s", io_program.iv_instructions.size(), mss::c_str(i_target));

    auto l_inst_iter = io_program.iv_instructions.begin();

    // Run prelude to execution
    FAPI_TRY( prelude_to_execution<MC>(i_target, io_program, i_ports),
              "Error setting up ccs engine before execution on %s", mss::c_str(i_target) );

    // Execute via standalone CCS
    while (l_inst_iter != io_program.iv_instructions.end())
    {
        // Kick off the CCS engine - per port. No broadcast mode for CCS (per Shelton 9/23/15)
        for (const auto& p : i_ports)
        {
            const auto l_port_index = mss::relative_pos<MC, T>(p);

            // Run ccs instruction setup
            FAPI_TRY( setup_ccs_instructions<MC>(i_target, l_inst_iter, io_program, p),
                      "Error setting up ccs instructions in registers on %s", mss::c_str(i_target) );

            FAPI_INF("executing CCS array for port %d (%s)", l_port_index, mss::c_str(p));
            FAPI_TRY( select_ports<MC>( i_target, l_port_index),
                      "Error in port select for %s", mss::c_str(i_target) );
            FAPI_TRY( execute_inst_array<MC>(i_target, io_program, p),
                      "Error in executing ccs array for %s", mss::c_str(i_target) );
        }
    }

    // Cleans up after executing the CCS program (runs workarounds if needed)
    FAPI_TRY((cleanup_from_execute<MC>(io_program, i_ports)));

fapi_try_exit:
    io_program.iv_instructions.clear();
    return fapi2::current_err;
}

///
/// @brief Execute a set of CCS instructions via the MCBIST engine
/// @tparam MC the memory controller type running CCS
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P  the port type for this CCS engine
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in, out] io_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<MC> >
static inline fapi2::ReturnCode execute_via_mcbist( const fapi2::Target<T>& i_target,
        ccs::program<MC>& io_program,
        const std::vector< fapi2::Target<P> >& i_ports)
{
    // Subtract one for the idle we insert at the end
    constexpr size_t CCS_INSTRUCTION_DEPTH = TT::CCS_ARRAY_LEN - 1;

    FAPI_INF("Execution CCS commands (%d) via MCBIST for %s", io_program.iv_instructions.size(), mss::c_str(i_target));

    // Get instruction count and rank info
    const uint64_t l_inst_count = io_program.iv_instructions.size();
    auto l_inst_iter = io_program.iv_instructions.begin();

    // Check that we have less than the maximum CCS instructions
    FAPI_ASSERT(l_inst_count <= CCS_INSTRUCTION_DEPTH,
                fapi2::MSS_CONCURRENT_CCS_EXCEEDS_INSTRUCTION_LIMIT()
                .set_MC_TARGET(i_target)
                .set_REQUESTED_INSTRUCTIONS(io_program.iv_instructions.size())
                .set_MAX_INSTRUCTIONS(CCS_INSTRUCTION_DEPTH),
                "%s over CCS concurrent instructions limit, requested %d instructions",
                mss::c_str(i_target), l_inst_count);


    // Run prelude to execution
    FAPI_TRY( prelude_to_execution<MC>(i_target, io_program, i_ports), "Error setting up ccs engine before execution on %s",
              mss::c_str(i_target));

    // Stop any ongoing MCBIST command
    FAPI_TRY( mss::memdiags::stop<MC>(i_target),
              "MCBIST engine failed to stop current command in progress on %s",
              mss::c_str(i_target) );

    // Setup CCS per port
    for (const auto& p : i_ports)
    {
        const auto l_port_index = mss::relative_pos<MC, T>(p);

        // Run ccs instruction setup
        FAPI_TRY( setup_ccs_instructions<MC>(i_target, l_inst_iter, io_program, p),
                  "Error setting up ccs instructions in registers on %s", mss::c_str(i_target) );

        FAPI_INF("executing CCS via MCBIST for port %d (%s)", l_port_index, mss::c_str(p));
        FAPI_TRY( select_ports<MC>( i_target, l_port_index),
                  "Error in port select for ccs::execute_via_mcbist on %s", mss::c_str(i_target) );
        FAPI_TRY( execute_inst_via_mcbist<MC>(i_target), "Error in ccs::execute_inst_via_mcbist on %s", mss::c_str(i_target) );
    }

    // Cleans up after executing the CCS program (runs workarounds if needed)
    FAPI_TRY((cleanup_from_execute<MC>(io_program, i_ports)));

fapi_try_exit:
    io_program.iv_instructions.clear();
    return fapi2::current_err;
}

///
/// @brief Execute a set of CCS instructions - single port
/// @tparam MC the memory controller type running CCS
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P the target of the CCS instruction (the port)
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_program the vector of instructions
/// @param[in] i_port The target that's being programmed by the array
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<MC> >
static inline fapi2::ReturnCode execute( const fapi2::Target<T>& i_target,
        ccs::program<MC>& i_program,
        const fapi2::Target<P>& i_port)
{
    // Mmm. Might want to find a better way to do this - seems expensive. BRS
    std::vector< fapi2::Target<P> > l_ports{ i_port };
    return execute<MC>(i_target, i_program, l_ports);
}

///
/// @brief Execute a set of CCS instructions via the MCBIST engine - single port
/// @tparam MC the memory controller type running CCS
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P the target of the CCS instruction (the port)
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in, out] io_program the vector of instructions
/// @param[in] i_port The target that's being programmed by the array
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<MC> >
static inline fapi2::ReturnCode execute_via_mcbist( const fapi2::Target<T>& i_target,
        ccs::program<MC>& io_program,
        const fapi2::Target<P>& i_port)
{
    // Mmm. Might want to find a better way to do this - seems expensive. BRS
    std::vector< fapi2::Target<P> > l_ports{ i_port };
    return execute_via_mcbist<MC>(i_target, io_program, l_ports);
}

///
/// @brief Query the status of the CCS engine
/// @tparam MC the memory controller type running CCS
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target The MCBIST containing the CCS engine
/// @param[out] io_status The query result first being the result, second the type
/// @return FAPI2_RC_SUCCESS iff success
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
fapi2::ReturnCode status_query( const fapi2::Target<T>& i_target, std::pair<uint64_t, uint64_t>& io_status );

} // ends namespace ccs
} // ends namespace mss

#endif
