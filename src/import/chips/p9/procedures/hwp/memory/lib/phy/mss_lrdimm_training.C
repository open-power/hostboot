/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_lrdimm_training.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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

#include <lib/shared/nimbus_defaults.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/shared/mss_const.H>
#include <lib/dimm/rank.H>
#include <lib/dimm/ddr4/control_word_ddr4_nimbus.H>
#include <lib/dimm/ddr4/data_buffer_ddr4_nimbus.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <lib/phy/mss_training.H>
#include <lib/mc/port.H>
#include <lib/rosetta_map/rosetta_map.H>
#include <lib/dimm/ddr4/pba.H>
#include <lib/eff_config/timing.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/phy/mss_lrdimm_training.H>


#ifdef LRDIMM_CAPABLE
    #include <lib/phy/mss_lrdimm_training_helper.H>
#endif

namespace mss
{

namespace training
{

namespace lrdimm
{
///
/// @brief Swizzles a DQ from the MC perspective to the DIMM perspective
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_mc_dq the DQ on the MC perspective to swizzle to the buffer's perspective
/// @param[out] o_buffer_dq the DQ number from the buffer's perspective
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mc_to_dimm_dq(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_mc_dq,
                                uint64_t& o_buffer_dq)
{
    uint64_t l_c4_dq = 0;
    uint8_t* l_dimm_dq_ptr = nullptr;
    uint8_t l_dimm_to_c4[MAX_DQ_BITS] = {};

    // First get the c4 DQ
    FAPI_TRY(rosetta_map::mc_to_c4<rosetta_type::DQ>( i_target, i_mc_dq, l_c4_dq ));

    // Now get the DIMM DQ
    FAPI_TRY(vpd_dq_map(i_target, &l_dimm_to_c4[0]));
    l_dimm_dq_ptr = std::find(l_dimm_to_c4, l_dimm_to_c4 + MAX_DQ_BITS, l_c4_dq);

    // Check that we got a good value
    FAPI_ASSERT(l_dimm_dq_ptr != l_dimm_to_c4 + MAX_DQ_BITS,
                fapi2::MSS_LOOKUP_FAILED()
                .set_KEY(l_c4_dq)
                .set_DATA(i_mc_dq)
                .set_TARGET(i_target));

    // Now return that value
    o_buffer_dq = *l_dimm_dq_ptr;

fapi_try_exit :
    return fapi2::current_err;
}

///
/// @brief Swizzles a DQ from the DRAM perspective to the buffer's perspective
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_mc_dq the DQ on the MC perspective to swizzle to the buffer's perspective
/// @param[out] o_buffer_dq the DQ number from the buffer's perspective
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mc_to_buffer(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_mc_dq,
                               uint64_t& o_buffer_dq)
{
    FAPI_TRY(mc_to_dimm_dq(i_target, i_mc_dq, o_buffer_dq));

    // Each buffer is a byte and we want the bit from the buffer's perspective
    o_buffer_dq = o_buffer_dq % BITS_PER_BYTE;

fapi_try_exit :
    return fapi2::current_err;
}

///
/// @brief Checks if a buffer's nibbles are swizzled
/// @param[in] i_target the MCA target on which to operate
/// @param[in] i_buffer the buffer on which to see if the nibbles are swizzled
/// @param[out] o_are_swizzled true if the buffer's nibbles are swizzled
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode are_buffers_nibbles_swizzled(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_buffer,
        bool& o_are_swizzled)
{
    const auto l_mc_dq = i_buffer * BITS_PER_BYTE;
    uint64_t l_buffer_dq = 0;
    FAPI_TRY(mc_to_buffer(i_target, l_mc_dq, l_buffer_dq));

    // Now, checks if the nibble is swizzled
    // We're swizzled if the 0'th DQ from the MC perspective is on buffer's nibble 1
    o_are_swizzled = (1 == (l_buffer_dq / BITS_PER_NIBBLE));
    FAPI_DBG("%s buffer:%u %s swizzled mc_dq:%u buffer_dq:%u",
             mss::c_str(i_target), i_buffer, o_are_swizzled ? "are" : "not", l_mc_dq, l_buffer_dq);

fapi_try_exit :
    return fapi2::current_err;
}

///
/// @brief Issues initial pattern write to all ranks in the rank pair
/// @param[in] i_target the MCA target on which to operate
/// @parma[in] i_rp the rank pair on which to operate
/// @parma[in] i_pattern the pattern to program into the MPR
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mpr_pattern_wr_all_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint32_t i_pattern)
{
    std::vector<uint64_t> l_ranks;

    FAPI_TRY( mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks),
              "Failed get_ranks_in_pair in mrep::run %s",
              mss::c_str(i_target) );

    // Loops over all ranks within this rank pair
    for (const auto l_rank : l_ranks)
    {
        FAPI_TRY(mpr_pattern_wr_rank(i_target, l_rank, i_pattern));
    };

fapi_try_exit :
    return fapi2::current_err;
}

///
/// @brief Issues initial pattern write a specific rank
/// @param[in] i_target the MCA target on which to operate
/// @parma[in] i_rank the rank to setup for initial pattern write
/// @parma[in] i_pattern the pattern to program into the MPR
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mpr_pattern_wr_rank(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                      const uint64_t i_rank,
                                      const uint32_t i_pattern)
{
    // Skip over invalid ranks (NO_RANK)
    if(i_rank == NO_RANK)
    {
        FAPI_DBG("%s NO_RANK was passed in %u. Skipping", mss::c_str(i_target), i_rank)
        return fapi2::FAPI2_RC_SUCCESS;
    }

    mss::ccs::program l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // Gets the DIMM target
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
    FAPI_TRY(mss::rank::get_dimm_target_from_rank(i_target, i_rank, l_dimm),
             "%s failed to get DIMM target for rank %u", mss::c_str(i_target), i_rank);

    // Ok, MPR write
    // We need to
    // 1) MRS into MPR mode
    // 2) Disable address inversion, so we set our values correctly
    //    We need to disable address inversion so both A-side and B-side get the same pattern written into the MPR registers
    // 3) Write the patterns in according to the bank address
    // 4) Restore the default address inversion
    // 5) MRS out of MPR mode

    // 1) MRS into MPR mode
    FAPI_TRY( mss::ddr4::mpr_load(l_dimm,
                                  fapi2::ENUM_ATTR_EFF_MPR_MODE_ENABLE,
                                  i_rank,
                                  l_program.iv_instructions) );

    // 2) Disable address inversion
    // We need to disable address inversion so both A-side and B-side get the same pattern written into the MPR registers
    FAPI_TRY(disable_address_inversion(l_dimm, l_program.iv_instructions));

    // 3) Write the patterns in according to the bank address
    FAPI_INF("%s are we failing here rank%u", mss::c_str(i_target), i_rank);
    FAPI_TRY(add_mpr_pattern_writes(l_dimm,
                                    i_rank,
                                    i_pattern,
                                    l_program.iv_instructions));

    // 4) Restore the default address inversion
    FAPI_TRY(restore_address_inversion(l_dimm, l_program.iv_instructions));

    // 5) MRS out of MPR mode
    FAPI_TRY( mss::ddr4::mpr_load(l_dimm,
                                  fapi2::ENUM_ATTR_EFF_MPR_MODE_DISABLE,
                                  i_rank,
                                  l_program.iv_instructions) );

    // Make sure we leave everything powered on
    mss::ccs::workarounds::hold_cke_high(l_program.iv_instructions);

    FAPI_TRY( ccs::execute(l_mcbist,
                           l_program,
                           i_target) );
fapi_try_exit:
    return fapi2::current_err;
}

//
/// @brief Does a CCS NTTM mode read
/// @param[in] i_target - the MCA target on which to operate
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode execute_nttm_mode_read(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{

    using TT = ccsTraits<mss::mc_type::NIMBUS>;

    // A hardware bug requires us to increase our delay significanlty for NTTM mode reads
    constexpr uint64_t SAFE_NTTM_READ_DELAY = 0x40;
    mss::ccs::program l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // Note: CKE are enabled by default in the NTTM mode read command, so we should be good to go
    // set the NTTM read mode
    auto l_nttm_read = mss::ccs::nttm_read_command();
    l_nttm_read.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(SAFE_NTTM_READ_DELAY);
    l_program.iv_instructions.push_back(l_nttm_read);

    // turn on NTTM mode
    FAPI_TRY( mss::ccs::configure_nttm(l_mcbist, mss::states::ON),
              "%s failed to turn on NTTM mode", mss::c_str(i_target) );

    // Issue CCS
    FAPI_TRY(ccs::execute( l_mcbist,
                           l_program,
                           i_target) );
    // turn off NTTM mode
    FAPI_TRY( mss::ccs::configure_nttm(l_mcbist, mss::states::OFF),
              "%s failed to turn off NTTM mode", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

#ifdef LRDIMM_CAPABLE
///
/// @brief Executes the pre-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode mrep::pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                        const uint64_t i_rp,
                                        const uint8_t i_abort_on_error ) const
{
    FAPI_INF("%s setting up the read pointer enable rp%u", mss::c_str(i_target), i_rp);
    FAPI_TRY( mss::setup_read_pointer_delay(i_target));

    // call function to force DQ capture in Read FIFO to support DDR4 LRDIMM calibration.
    FAPI_TRY( mss::dp16::write_force_dq_capture(i_target, mss::states::ON),
              "%s failed to write force dq capture", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes the post-cal step workaround
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode mrep::post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint8_t i_abort_on_error ) const
{
    // call function to force DQ capture in Read FIFO to support DDR4 LRDIMM calibration.
    FAPI_TRY( mss::dp16::write_force_dq_capture(i_target, mss::states::OFF),
              "%s failed to write exit dq capture", mss::c_str(i_target) );

    // Clears the FIR's that can get set by training
    // They're not real, so we want to clear them and move on
    FAPI_TRY(mss::training::lrdimm::workarounds::clear_firs(i_target), "%s failed to clear FIRs", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write the results to buffer generate PBA commands
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank number
/// @param[in] i_mrep_result a vector of the MREP result
/// @param[out] o_container the PBA commands structure
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note a little helper to allow us to unit test that we generate the PBA commands ok
///
fapi2::ReturnCode mrep::write_result_to_buffers_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_mrep_result,
        mss::ddr4::pba::commands& o_container) const
{
    uint8_t l_buffer = 0;
    // Clears out the PBA container to ensure we don't issue undesired commands
    o_container.clear();

    // Get's the MCA
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // Looops through and generates the PBA commands
    for(const auto& l_recorder : i_mrep_result)
    {
        bool l_are_nibbles_swapped = false;
        FAPI_TRY(are_buffers_nibbles_swizzled(l_mca, l_buffer, l_are_nibbles_swapped));

        {
            const auto l_result_nibble0 = l_are_nibbles_swapped ?
                                          l_recorder.second.iv_delay :
                                          l_recorder.first.iv_delay;
            const auto l_result_nibble1 = l_are_nibbles_swapped ?
                                          l_recorder.first.iv_delay :
                                          l_recorder.second.iv_delay;

            FAPI_DBG("%s MREP rank%u buffer:%u final values (0x%02x,0x%02x) %s swapped BC2x:0x%02x BC3x:0x%02x",
                     mss::c_str(l_mca), i_rank, l_buffer, l_recorder.first.iv_delay, l_recorder.second.iv_delay,
                     l_are_nibbles_swapped ? "are" : "not", l_result_nibble0, l_result_nibble1);

            // Function space is derived from the rank
            // 2 is for Nibble 0, 3 is for Nibble 1
            // Data corresponds to the final setting we have
            // Delay is for PBA, bumping it way out so we don't have issues
            constexpr uint64_t PBA_DELAY = 255;
            constexpr uint64_t BCW_NIBBLE0 = 0x02;
            constexpr uint64_t BCW_NIBBLE1 = 0x03;

            const mss::cw_info MREP_FINAL_SET_BCW_N0( i_rank,
                    BCW_NIBBLE0,
                    l_result_nibble0,
                    PBA_DELAY,
                    mss::CW8_DATA_LEN,
                    mss::cw_info::BCW);
            const mss::cw_info MREP_FINAL_SET_BCW_N1( i_rank,
                    BCW_NIBBLE1,
                    l_result_nibble1,
                    PBA_DELAY,
                    mss::CW8_DATA_LEN,
                    mss::cw_info::BCW);

            // Each buffer contains two nibbles
            // Each nibble corresponds to one BCW
            // Add in the buffer control words
            FAPI_TRY(o_container.add_command(i_target, l_buffer, MREP_FINAL_SET_BCW_N0));
            FAPI_TRY(o_container.add_command(i_target, l_buffer, MREP_FINAL_SET_BCW_N1));
        }

        ++l_buffer;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief write the result to buffer
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank number
/// @param[in] i_mrep_result a vector of the MREP results
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrep::write_result_to_buffers( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_mrep_result) const
{
    mss::ddr4::pba::commands l_container;

    // Sets up the PBA commands
    FAPI_TRY(write_result_to_buffers_helper( i_target,
             i_rank,
             i_mrep_result,
             l_container),
             "%s rank%u failed generating PBA commands",
             mss::c_str(i_target), i_rank);

    // Issue the PBA to set the final MREP results
    FAPI_TRY(mss::ddr4::pba::execute_commands(l_container));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets MREP Delay value
/// @param[in] i_target the DIMM target
/// @param[in] i_rank the rank to operate on - drives the function space select
/// @param[in] delay value /64 Tck - MREP delay value
/// @return FAPI2_RC_SUCCESS if okay
/// @note Sets DA setting for buffer control word (F[3:0]BC2x, F[3:0]BC3x)
///
fapi2::ReturnCode mrep::set_delay(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint8_t i_rank,
                                  const uint8_t i_delay ) const
{
    mss::ccs::program l_program;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    std::vector<cw_info> l_bcws =
    {
        {i_rank, NIBBLE0_BCW_NUMBER, i_delay, mss::tmrd_l2(), mss::CW8_DATA_LEN, cw_info::BCW},
        {i_rank, NIBBLE1_BCW_NUMBER, i_delay, mss::tmrd_l2(), mss::CW8_DATA_LEN, cw_info::BCW},
    };

    uint8_t l_sim = 0;
    FAPI_TRY(mss::is_simulation(l_sim));

    // Ensure our CKE's are powered on
    l_program.iv_instructions.push_back(mss::ccs::des_command());

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
/// @brief Creates the nibble flags for the invalid data callout
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @param[out] o_invalid_count number of invalid data occurances seen
/// @return invalid data nibble flags
/// @note Invalid data is defined as not having all zeros or all ones
///
uint32_t mrep::flag_invalid_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint8_t i_rank,
                                  const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders,
                                  uint64_t& o_invalid_count) const
{
    o_invalid_count = 0;
    uint8_t l_buffer = 0;

    // Per nibble invalid data flags - bitmap
    uint32_t l_per_nibble_flags = 0;

    for(const auto& l_recorder : i_recorders)
    {

        // This is a coding issue here, just break out of the loop
        // We should never have more data than recorders
        // No need to log it, just recover and continue
        if(l_buffer >= MAX_LRDIMM_BUFFERS)
        {
            FAPI_ERR("%s rank%u saw buffer%u when number of buffers is %u. Continuing gracefully",
                     mss::c_str(i_target), i_rank, l_buffer, MAX_LRDIMM_BUFFERS);
            break;
        }

        // Updates the bitmap
        o_invalid_count += l_recorder.first.iv_invalid_data_count + l_recorder.second.iv_invalid_data_count;
        append_nibble_flags(l_recorder.first.iv_invalid_data_count != mrep_dwl_recorder::CLEAN,
                            l_recorder.second.iv_invalid_data_count != mrep_dwl_recorder::CLEAN,
                            l_per_nibble_flags);

        l_buffer++;
    }

    return l_per_nibble_flags;
}

///
/// @brief Calls out if invalid data is seen during this calibration step
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return FAPI2_RC_SUCCESS if okay
/// @note Invalid data is defined as not having all zeros or all ones
///
fapi2::ReturnCode mrep::callout_invalid_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const
{
    // Per nibble invalid data - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    // We also count the number of occurances of invalid data across the port/rank
    // This count gives more insight into the fails
    // Low counts mean one off data glitches
    // High counts indicate that one or more nibbles are having issues
    uint64_t l_invalid_data_count = 0;
    const auto l_per_nibble_flags = flag_invalid_data( i_target, i_rank, i_recorders, l_invalid_data_count);

    FAPI_TRY(callout::invalid_data( i_target,
                                    i_rank,
                                    l_per_nibble_flags,
                                    l_invalid_data_count,
                                    mss::cal_steps::MREP,
                                    "MREP"));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Creates the nibble flags for the no transition callout
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return no transition nibble flags
///
uint32_t mrep::flag_no_transition( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const uint8_t i_rank,
                                   const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const
{
    uint8_t l_buffer = 0;

    // Per nibble invalid data flags - bitmap
    uint32_t l_per_nibble_flags = 0;

    for(const auto& l_recorder : i_recorders)
    {

        // This is a coding issue here, just break out of the loop
        // We should never have more data than recorders
        // No need to log it, just recover and continue
        if(l_buffer >= MAX_LRDIMM_BUFFERS)
        {
            FAPI_ERR("%s rank%u saw buffer%u when number of buffers is %u. Continuing gracefully",
                     mss::c_str(i_target), i_rank, l_buffer, MAX_LRDIMM_BUFFERS);
            break;
        }

        const bool l_nibble0_no_transition = !l_recorder.first.iv_seen0 || !l_recorder.first.iv_seen1;
        const bool l_nibble1_no_transition = !l_recorder.second.iv_seen0 || !l_recorder.second.iv_seen1;

        // Updates the bitmap
        append_nibble_flags(l_nibble0_no_transition, l_nibble1_no_transition, l_per_nibble_flags);

        l_buffer++;
    }

    return l_per_nibble_flags;
}

///
/// @brief Calls out if a rank does not see a 0->1 transition
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_rank the current rank
/// @param[in] i_recorders the recorders on which to process the data
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode mrep::callout_no_transition( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rank,
        const std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>>& i_recorders) const
{
    // Per nibble weird data and no transition flags - bitmap
    // A bitmap is used to simplify the error callouts
    // We callout one bitmap vs 18 bits
    uint32_t l_per_nibble_flags = flag_no_transition( i_target, i_rank, i_recorders);

    // Error checking here
    FAPI_ASSERT(l_per_nibble_flags == CLEAN_BITMAP,
                fapi2::MSS_LRDIMM_CAL_NO_TRANSITION()
                .set_TARGET(i_target)
                .set_RANK(i_rank)
                .set_CALIBRATION_STEP(mss::cal_steps::MREP)
                .set_NIBBLE_FLAGS(l_per_nibble_flags),
                "%s rank%u has seen invalid data on nibbles 0x%x in MREP",
                mss::c_str(i_target), i_rank, l_per_nibble_flags);


    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered
    // We "recover" by setting a default value and continuing with calibration
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::current_err;
}

///
/// @brief Sets up and runs the calibration step
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rp - the rank pair
/// @param[in] i_abort_on_error - whether or not we are aborting on cal error
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode mrep::run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                             const uint64_t i_rp,
                             const uint8_t i_abort_on_error ) const
{
    constexpr uint8_t MPR_LOCATION0 = 0;
    std::vector<uint64_t> l_ranks;
    uint8_t l_rank_index = 0;
    FAPI_INF("%s RP%d starting calibrate MREP", mss::c_str(i_target), i_rp);

    const auto& l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target);

    FAPI_TRY( mss::rank::get_ranks_in_pair( i_target, i_rp, l_ranks),
              "Failed get_ranks_in_pair in mrep::run %s",
              mss::c_str(i_target) );

    // Disable all rank of 2 dimm's before training
    for (const auto& l_dimm : l_dimms)
    {
        FAPI_TRY(set_rank_presence(l_dimm, RANK_PRESENCE_MASK));
    }

    // Loops over all ranks within this rank pair
    // MREP is a buffer to DRAM calibration step, so we need to calibrate all ranks seperately
    for (const auto& l_rank : l_ranks)
    {
        // Skip over invalid ranks (NO_RANK)
        if(l_rank == NO_RANK)
        {
            FAPI_DBG("%s RP%u l_rank_index:%u is being skipped as it's not configured (%u)",
                     mss::c_str(i_target), i_rp, l_rank_index, l_rank);
            ++l_rank_index;
            continue;
        }

        FAPI_DBG("%s RP%u rank index number %u has rank %u", mss::c_str(i_target), i_rp, l_rank_index, l_rank);
        const auto& l_dimm = l_dimms[mss::rank::get_dimm_from_rank(l_rank)];

        // Added in for cronus debug - not needed for hostboot
#ifndef __HOSTBOOT_MODULE
        // Prints the header
        FAPI_DBG("%s CARD  AAAAAAAAAA RCD BBBBBBBB", mss::c_str(i_target));
        FAPI_DBG("%s CARD  0000000000 RCD 11111111", mss::c_str(i_target));
        FAPI_DBG("%s CARD  0516273849 RCD 04152637", mss::c_str(i_target));
#endif

        // Vector represents the number of LRDIMM buffers
        // The pair represents the two nibbles that we need to calibrate within the buffer
        std::vector<std::pair<mrep_dwl_recorder, mrep_dwl_recorder>> l_results_recorder(MAX_LRDIMM_BUFFERS);
        //Loop through all of our delays multiple times to reduce noise issues
        std::vector<mrep_dwl_result> l_loop_results(MREP_DWL_LOOP_TIMES);

        const auto l_dimm_rank = mss::index(l_rank);

        // 1) Gets the ranks on which to put DRAM into MPR mode
        FAPI_TRY( mpr_load(l_dimm, fapi2::ENUM_ATTR_EFF_MPR_MODE_ENABLE, l_rank), "%s failed mpr_load rank%u",
                  mss::c_str(l_dimm), l_rank);

#ifdef LRDIMM_CAPABLE
        // 2) set the rank presence
        FAPI_TRY(set_rank_presence(l_dimm, generate_rank_presence(l_rank)),
                 "%s failed set rank%u",
                 mss::c_str(l_dimm), l_rank);

        // 3) put buffer, dram into read preamble training mode
        FAPI_TRY(set_dram_rd_preamble_mode(l_dimm, mss::states::ON, l_rank), "%s failed set_dram_rd_preamble_mode rank%u",
                 mss::c_str(l_dimm), l_rank);
        FAPI_TRY(set_buffer_rd_preamble_mode(l_dimm, mss::states::ON), "%s failed set_buffer_rd_preamble_mode rank%u",
                 mss::c_str(l_dimm), l_rank);
#endif

        // 4) Put the buffer in MREP mode -> host issues BCW's
        FAPI_TRY(set_buffer_training(l_dimm, ddr4::MREP), "%s failed set_buffer_training", mss::c_str(l_dimm));

        // Loop through all of our delays
        for(auto& l_loop_result : l_loop_results)
        {
            for(uint8_t l_delay = 0; l_delay < MREP_DWL_MAX_DELAY; ++l_delay)
            {
                // 5) Set the MREP l_delay -> host issues BCW's
                FAPI_TRY(set_delay(l_dimm, l_dimm_rank, l_delay), "%s failed set_delay rank%u delay%u", mss::c_str(l_dimm),
                         l_rank, l_delay);

                // 6) Do an MPR read -> host issues RD command to the DRAM
                FAPI_TRY( mpr_read(l_dimm, MPR_LOCATION0, l_rank), "%s failed mpr_read rank%u delay%u", mss::c_str(l_dimm),
                          l_rank, l_delay);

                // 6.1) Do an NTTM mode read -> forces the logic to read out the data
                FAPI_TRY(execute_nttm_mode_read(i_target));

                FAPI_TRY(get_result(l_dimm, mss::cal_steps::MREP, l_delay, l_loop_result, l_results_recorder));
            } //l_delay loop
        }

        // 7) Analyze the results -> host/FW read from CCS results and go
        FAPI_TRY( analyze_result(l_dimm, mss::cal_steps::MREP, l_loop_results, l_results_recorder),
                  "%s failed analyze_mrep_result rank%u",
                  mss::c_str(l_dimm), l_rank);

        // 8) Error check -> if we had stuck 1 or stuck 0 (never saw a 0 to 1 or a 1 to 0 transition) exit out with an error
        FAPI_TRY(error_check(l_dimm, l_rank, l_results_recorder), "%s failed error_check rank:%u", mss::c_str(l_dimm), l_rank);

        // 9) Apply MREP offset to ranks based upon tCK RD preamble mode
        FAPI_TRY(apply_final_offset(l_dimm, l_results_recorder), "%s failed apply_final_offset rank%u", mss::c_str(l_dimm),
                 l_rank);

        // 10) take the buffer out of MREP mode -> host issues BCW's
        FAPI_TRY(set_buffer_training(l_dimm, ddr4::NORMAL), "%s failed set_buffer_training", mss::c_str(l_dimm));

#ifdef LRDIMM_CAPABLE
        // 11) take buffer, dram out of read preamble training mode
        FAPI_TRY(set_dram_rd_preamble_mode(l_dimm, mss::states::OFF, l_rank), "%s failed set_dram_rd_preamble_mode rank%u",
                 mss::c_str(l_dimm), l_rank);
        FAPI_TRY(set_buffer_rd_preamble_mode(l_dimm, mss::states::OFF), "%s failed set_buffer_rd_preamble_mode rank%u",
                 mss::c_str(l_dimm), l_rank);
#endif

        // 12) take DRAM out of MPR -> host issues MRS
        FAPI_TRY( mpr_load(l_dimm, fapi2::ENUM_ATTR_EFF_MPR_MODE_DISABLE, l_rank), "%s failed mpr_load %u", mss::c_str(l_dimm),
                  l_rank);

        // 13) Write final values into the buffers -> host issues BCW's in PBA mode (values are calculated in step 7)
        FAPI_TRY( write_result_to_buffers(l_dimm, l_dimm_rank, l_results_recorder), "%s failed write_result_to_buffers rank%u",
                  mss::c_str(l_dimm), l_rank);

        l_rank_index++;
    }//l_rank loop

#ifdef LRDIMM_CAPABLE

    // 14) set for two or four rank dimms
    for (const auto& l_dimm : l_dimms)
    {
        uint8_t l_rank_num = 0;
        FAPI_TRY( eff_num_master_ranks_per_dimm(l_dimm, l_rank_num) );
        FAPI_TRY(set_rank_presence(l_dimm, generate_rank_presence_value(l_rank_num)));
    }

#endif

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates the number of cycles a given calibration step will take
/// @param[in] i_target - the MCA target on which to operate
/// @return l_cycles - the number of cycles a given calibration step wil take
///
uint64_t mrep::calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const
{
    return 0;
}
#endif

///
/// @brief Deconfigures calibration steps depending upon LRDIMM type
/// @param[in] i_dimm_type - DIMM type
/// @param[in] i_sim - simulation mode or not
/// @param[in,out] io_cal_steps - the bit mask of calibration steps
/// @return a vector of the calibration steps to run
///
void deconfigure_steps(const uint8_t i_dimm_type,
                       const bool i_sim,
                       fapi2::buffer<uint32_t>& io_cal_steps)
{
    // If the DIMM type is an LRDIMM, configure for LRDIMM
    if(i_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM)
    {
        FAPI_INF("LRDIMM: deconfigure WR VREF 2D and RD VREF 2D");
        // We clear WRITE_CTR_2D_VREF as the HW calibration algorithm will not work with LRDIMM
        // Same for RD VREF
        io_cal_steps.clearBit<WRITE_CTR_2D_VREF>()
        .clearBit<READ_CTR_2D_VREF>();
        return;
    }

    FAPI_INF("Not LRDIMM: deconfigure all LRDIMM specific steps");
    // Otherwise, clear all LRDIMM calibration steps
    io_cal_steps.clearBit<DB_ZQCAL>()
    .clearBit<MREP>()
    .clearBit<MRD_COARSE>()
    .clearBit<MRD_FINE>()
    .clearBit<DWL>()
    .clearBit<MWD_COARSE>()
    .clearBit<MWD_FINE>()
    .clearBit<HWL>();
}

} // ns lrdimm

} // ns training

} // ns mss
