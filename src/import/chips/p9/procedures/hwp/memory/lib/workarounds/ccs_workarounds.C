/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/ccs_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
/// @file ccs_workarounds.H
/// @brief Contains CCS workarounds
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#include <lib/workarounds/ccs_workarounds.H>
#include <lib/dimm/rank.H>
#include <p9_mc_scom_addresses.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/eff_config/timing.H>

namespace mss
{

namespace ccs
{

namespace workarounds
{

///
/// @brief Re-enables PDA mode on a given rank in the shadow registers
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
///
fapi2::ReturnCode enable_pda_shadow_reg( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rank )
{
    static const std::vector<uint64_t> RP_TO_REG =
    {
        MCA_DDRPHY_PC_MR3_PRI_RP0_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP1_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP2_P0,
        MCA_DDRPHY_PC_MR3_PRI_RP3_P0,
    };

    uint64_t l_rp = 0;
    FAPI_TRY( mss::rank::get_pair_from_rank( i_target, i_rank, l_rp ), "%s failed to get pair from rank %lu",
              mss::c_str(i_target), i_rank );

    // Reads, modifies, and writes the value back out
    {
        // The bits in the shadow register are one block, we only want to set the PDA enable bit, which corresponds to bit 59
        constexpr uint64_t PDA_BIT = 59;
        fapi2::buffer<uint64_t> l_data;

        // Read
        FAPI_TRY( mss::getScom(i_target, RP_TO_REG[l_rp], l_data) );

        // Modify
        l_data.setBit<PDA_BIT>();

        // Write
        FAPI_TRY( mss::putScom(i_target, RP_TO_REG[l_rp], l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Issues the PDA exit command
/// @param[in] i_target - the DIMM target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @param[in,out] io_program - the CCS program
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
/// @note The PHY traps both the a-side and b-side MRS's into the same shadow register
/// After the a-side MRS exits PDA, the b-side MRS will not be taken out of PDA mode
/// To workaround this problem, a-side MRS is issued, then the shadow register is modified to have PDA mode enabled
/// Then the b-side MRS is issued
///
fapi2::ReturnCode exit( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const uint64_t i_rank,
                        ccs::program<fapi2::TARGET_TYPE_MCBIST>& io_program )
{
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);
    // Issues A-side MRS
    {
        auto l_a_side = io_program;
        l_a_side.iv_instructions.clear();
        l_a_side.iv_instructions.push_back(io_program.iv_instructions[0]);

        FAPI_TRY( ccs::execute(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target),
                               l_a_side,
                               l_mca),
                  "unable to execute CCS for MR03 a-side PDA exit rank %d %s",
                  i_rank, mss::c_str(i_target) );
    }

    // Re-enable PDA mode in the PHY
    {
        FAPI_TRY( enable_pda_shadow_reg(l_mca, i_rank) );
    }

    // Sets up the B-side MRS - the outside code will issue it
    // This allows the workaround to be encapuslated and the exit code to function properly for cases where the workaround should not be executed
    {
        auto l_b_side = io_program;
        l_b_side.iv_instructions.clear();
        l_b_side.iv_instructions.push_back(io_program.iv_instructions[1]);
        io_program = l_b_side;
    }

fapi_try_exit:
    return fapi2::current_err;
}

namespace wr_lvl
{

///
/// @brief Updates an MRS to have the desired Qoff value
/// @param[in,out] io_mrs - the MRS to update
/// @param[in] i_state - the state for the qoff in the MRS
///
void update_mrs(mss::ddr4::mrs01_data& io_mrs, const mss::states i_state)
{
    io_mrs.iv_qoff = i_state;
    io_mrs.iv_wl_enable = i_state;
}

///
/// @brief Adds in an MRS on a per-rank basis based upon qoff
/// @param[in] i_target - the target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @param[in] i_state - the state of qoff
/// @param[in,out] io_inst the instruction to fixup
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode add_mrs(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                          const uint64_t i_rank,
                          const mss::states& i_state,
                          std::vector<ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>>& io_inst)
{
    // First, get the DIMM target
    // Note: the target is setup below based upon the rank
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm(0);
    FAPI_TRY( mss::rank::get_dimm_target_from_rank(i_target, i_rank, l_dimm) );

    // Updates and adds in the MRS information
    {
        // Get the MRS data
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        mss::ddr4::mrs01_data l_mrs(l_dimm, l_rc);
        FAPI_TRY( l_rc, "%s failed to create MRS for rank %lu", mss::c_str(l_dimm), i_rank);

        // Update the MRS data for qoff
        update_mrs(l_mrs, i_state);

        // Add the MRS data to the ccs instructions
        FAPI_TRY( mrs_engine(l_dimm, l_mrs, i_rank, mss::tmod(i_target), io_inst) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets a vector of ranks that are not going to be calibrated in the given rank pair
/// @param[in] i_target - the MCA target on which to oparate
/// @param[in] i_rp - the rank pair that is currently being calibrated
/// @param[out] o_ranks - the vector of ranks that are not being calibrated
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode get_non_calibrating_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        std::vector<uint64_t>& o_ranks)
{
    o_ranks.clear();
    std::vector<uint64_t> l_pairs;

    // Get our rank pairs
    FAPI_TRY( mss::rank::get_rank_pairs(i_target, l_pairs) );

    // Loops through all of the rank pairs
    for(const auto l_rp : l_pairs)
    {
        // If this is our current rank pair, add in all non-primary ranks
        if(l_rp == i_rp)
        {
            FAPI_TRY( add_non_primary_ranks(i_target, l_rp, o_ranks) );
        }
        else
        {
            FAPI_TRY( add_ranks_from_pair(i_target, l_rp, o_ranks) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Adds the non-primary ranks from a rank pair to a ranks vector
/// @param[in] i_target - the MCA target on which to oparate
/// @param[in] i_rp - the rank pair that is currently being calibrated
/// @param[in,out] io_ranks - the vector of ranks that are not being calibrated
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode add_non_primary_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                        const uint64_t i_rp,
                                        std::vector<uint64_t>& io_ranks)
{
    std::vector<uint64_t> l_ranks_in_pair;
    FAPI_TRY( mss::rank::get_ranks_in_pair(i_target, i_rp, l_ranks_in_pair) );

    // Loops through the ranks and adds them as need be
    {
        // Primary rank is first, so we skip that one
        const auto l_begin = l_ranks_in_pair.begin() + 1;
        const auto l_end = l_ranks_in_pair.end();

        // Loops through the ranks
        for(auto l_it = l_begin; l_it < l_end; ++l_it)
        {
            const auto l_rank = *l_it;
            add_rank_to_vector(l_rank, io_ranks);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Adds all ranks from a rank pair to a ranks vector
/// @param[in] i_target - the MCA target on which to oparate
/// @param[in] i_rp - the rank pair that is currently being calibrated
/// @param[in,out] io_ranks - the vector of ranks that are not being calibrated
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode add_ranks_from_pair(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                      const uint64_t i_rp,
                                      std::vector<uint64_t>& io_ranks)
{
    std::vector<uint64_t> l_ranks_in_pair;
    FAPI_TRY( mss::rank::get_ranks_in_pair(i_target, i_rp, l_ranks_in_pair) );

    // Loops through the ranks
    for(const auto l_rank : l_ranks_in_pair)
    {
        add_rank_to_vector(l_rank, io_ranks);
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Adds a rank to the ranks vector if it is valid
/// @param[in] i_rank - the rank to add to the vector
/// @param[in,out] io_ranks - the vector of ranks that are not being calibrated
///
void add_rank_to_vector(const uint64_t i_rank, std::vector<uint64_t>& io_ranks)
{
    if(i_rank != mss::NO_RANK)
    {
        io_ranks.push_back(i_rank);
    }
}

///
/// @brief Enables or disables the DQ outputs on all non-calibrating ranks
/// @param[in] i_target - the MCA target on which to oparate
/// @param[in] i_rp - the rank pair that is currently being calibrated
/// @param[in] i_state - the state of qoff
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode configure_non_calibrating_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const mss::states& i_state)
{
    // Declares variables
    mss::ccs::program<fapi2::TARGET_TYPE_MCBIST, fapi2::TARGET_TYPE_MCA> l_program;
    std::vector<uint64_t> l_ranks;
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // Gets the ranks to configure
    FAPI_TRY( get_non_calibrating_ranks(i_target, i_rp, l_ranks) );

    // Adds in the MRS instructions to configure qoff
    for(const auto l_rank : l_ranks)
    {
        FAPI_TRY( add_mrs(i_target, l_rank, i_state, l_program.iv_instructions) );
    }

    // Executes the CCS instructions
    FAPI_TRY( mss::ccs::execute(l_mcbist, l_program, i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

} // ns wr_lvl

} // ns workarounds

} // ns ccs

} // ns mss
