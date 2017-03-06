/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/latch_wr_vref.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file latch_wr_vref.C
/// @brief Latches WR VREF according to JEDEC spec
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB Memory

#include <vector>
#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/dimm/ddr4/latch_wr_vref.H>
#include <lib/dimm/rank.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{

namespace ddr4
{

///
/// @brief Add latching commands for WR VREF to the instruction array - allows for custom MR06 data
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in] i_mrs06, base MRS 06 allows the user to setup custom values and pass it in
/// @param[in] i_rank, rank on which to latch MRS 06
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode add_latch_wr_vref_commands( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs06_data& i_mrs06,
        const uint64_t& i_rank,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    // JEDEC has a 3 step latching process for WR VREF
    // 1) enter into VREFDQ training mode, with the desired range value is XXXXXX
    // 2) set the VREFDQ value while in training mode - this actually latches the value
    // 3) exit VREFDQ training mode and go into normal operation mode

    // Adds both VREFDQ train enables
    // Note: this isn't general - assumes Nimbus via MCBIST instruction here BRS
    auto l_mr_override = i_mrs06;

    // Add both to the CCS program - JEDEC step 1
    enable_vref_train_enable(l_mr_override);
    FAPI_TRY( mrs_engine(i_target, l_mr_override, i_rank, mss::tvrefdqe(i_target), io_inst) );

    // Add both to the CCS program - JEDEC step 2
    FAPI_TRY( mrs_engine(i_target, l_mr_override, i_rank, mss::tvrefdqe(i_target), io_inst) );

    // Hits VREFDQ train disable - putting the DRAM's back in mainline mode
    // Add both to the CCS program - JEDEC step 3
    disable_vref_train_enable(l_mr_override);
    FAPI_TRY( mrs_engine(i_target, l_mr_override, i_rank, mss::tvrefdqe(i_target), io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Add latching commands for WR VREF to the instruction array
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_MCA>
/// @param[in] i_rank_pair, rank pair on which to latch MRS 06 - hits all ranks in the rank pair
/// @param[in] i_train_range, VREF range to setup
/// @param[in] i_train_value, VREF value to setup
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode latch_wr_vref_commands_by_rank_pair( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t& i_rank_pair,
        const uint8_t& i_train_range,
        const uint8_t& i_train_value)
{
    // Declares variables
    const auto l_mcbist = find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    // Warning: l_dimm is not a valid Target and will crash Cronus if used before it gets filled in by mss::rank::get_dimm_target_from_rank
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST, fapi2::TARGET_TYPE_MCA> l_program;
    std::vector<uint64_t> l_ranks;

    // Gets the ranks on which to latch the VREF's
    FAPI_TRY(mss::rank::get_ranks_in_pair( i_target, i_rank_pair, l_ranks));

    // Adds in latching commands for all ranks
    for (const auto& l_rank : l_ranks)
    {
        // Skips this rank if no rank is configured
        if (l_rank == NO_RANK)
        {
            continue;
        }

        // Ensures we get a valid DIMM target / rank combo
        FAPI_TRY( mss::rank::get_dimm_target_from_rank(i_target, l_rank, l_dimm) );

        // Adds the latching commands to the CCS program for this current rank
        FAPI_TRY(setup_latch_wr_vref_commands_by_rank(l_dimm,
                 l_rank,
                 i_train_range,
                 i_train_value,
                 l_program.iv_instructions));
    }

    // Executes the CCS commands
    FAPI_TRY( mss::ccs::execute(l_mcbist, l_program, i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Add latching commands for WR VREF to the instruction array by a given rank
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_MCA>
/// @param[in] i_rank, rank on which to latch MRS 06 - hits all ranks in the rank pair
/// @param[in] i_train_range, VREF range to setup
/// @param[in] i_train_value, VREF value to setup
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode setup_latch_wr_vref_commands_by_rank( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t& i_rank,
        const uint8_t& i_train_range,
        const uint8_t& i_train_value,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    // Check to make sure our ctor worked ok
    mrs06_data l_mrs06( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "Unable to construct MRS06 data from attributes");

    // Setup training range if the value is not the default
    if(i_train_range != wr_vref_override::USE_DEFAULT_WR_VREF_SETTINGS)
    {
        FAPI_INF("%s Overriding vrefdq train %s data to be 0x%02x for rank %lu", mss::c_str(i_target), "range", i_train_value,
                 i_rank);

        // Sets up the MR information
        for(uint64_t i = 0; i < MAX_RANK_PER_DIMM; ++i)
        {
            l_mrs06.iv_vrefdq_train_range[i] = i_train_range;
        }
    }

    // Setup training value if the value is not the default
    if(i_train_value != wr_vref_override::USE_DEFAULT_WR_VREF_SETTINGS)
    {
        FAPI_INF("%s Overriding vrefdq train %s data to be 0x%02x for rank %lu", mss::c_str(i_target), "value", i_train_value,
                 i_rank);

        // Sets up the MR information
        for(uint64_t i = 0; i < MAX_RANK_PER_DIMM; ++i)
        {
            l_mrs06.iv_vrefdq_train_value[i] = i_train_value;
        }
    }

    // Adds the latching commands
    FAPI_TRY(add_latch_wr_vref_commands(i_target,
                                        l_mrs06,
                                        i_rank,
                                        io_inst));

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace DDR4
} // close namespace mss
