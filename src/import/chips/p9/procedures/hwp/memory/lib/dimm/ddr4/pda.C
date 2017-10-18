/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/pda.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file pda.C
/// @brief Code to support per-DRAM addressability (PDA)
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/ccs/ccs.H>
#include <lib/dimm/mrs_load.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/dimm/ddr4/latch_wr_vref.H>
#include <lib/phy/write_cntrl.H>
#include <lib/phy/dp16.H>
#include <lib/dimm/ddr4/pda.H>
#include <lib/workarounds/ccs_workarounds.H>

namespace mss
{

namespace ddr4
{

namespace pda
{

const std::vector<std::pair<uint64_t, uint64_t>> pdaBitTraits<fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4>::BIT_MAP =
{
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N0},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N1},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N2},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N3},

    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_1, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N0},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_1, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N1},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_1, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N2},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_1, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N3},

    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_2, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N0},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_2, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N1},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_2, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N2},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_2, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N3},

    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_3, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N0},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_3, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N1},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_3, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N2},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_3, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N3},

    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_4, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N0},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_4, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N1},
};

const std::vector<std::pair<uint64_t, uint64_t>> pdaBitTraits<fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8>::BIT_MAP =
{
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N0},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N2},

    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_1, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N0},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_1, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N2},

    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_2, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N0},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_2, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N2},

    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_3, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N0},
    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_3, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N2},

    {MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_4, MCA_DDRPHY_DP16_DATA_BIT_ENABLE1_P0_0_01_MRS_CMD_N0},
};

///
/// @brief Helper function for changing the DRAM bit
/// @tparam W the DRAM width
/// @tparam TT the DRAM width traits class
/// @param[in] i_target - the MCA target
/// @param[in] i_dram - the DRAM on which to operate
/// @param[in] i_state - the state to write the bit(s) to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< uint8_t W, typename TT = pdaBitTraits<W> >
fapi2::ReturnCode change_dram_bit_helper( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_dram,
        const mss::states& i_state)
{
    fapi2::buffer<uint64_t> l_data;

    // Note: the following avoids "undefined reference to" errors due to the set max dram below
    // The use of traits and a const reference messes with it
    constexpr auto NUM_DRAM = TT::NUM_DRAMS;

    // Check bounds
    FAPI_ASSERT(i_dram < NUM_DRAM,
                fapi2::MSS_PDA_DRAM_OUT_OF_RANGE().
                set_MCA_TARGET(i_target).
                set_DRAM(i_dram).
                set_MAX_DRAM(NUM_DRAM),
                "%s was passed DRAM value of %lu which is not below the max value of %lu",
                mss::c_str(i_target), i_dram, NUM_DRAM);

    FAPI_TRY(mss::getScom(i_target, TT::BIT_MAP[i_dram].first, l_data));
    FAPI_TRY(l_data.writeBit(i_state, TT::BIT_MAP[i_dram].second, TT::NUM_BITS));
    FAPI_TRY(mss::putScom(i_target, TT::BIT_MAP[i_dram].first, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Writes the data bit enable for the properly inputted DRAM
/// @param[in] i_target - the MCA target
/// @param[in] i_dram - the DRAM on which to operate
/// @param[in] i_state - the state to write the bit(s) to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode change_dram_bit( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const uint64_t i_dram,
                                   const mss::states& i_state)
{
    uint8_t l_dram_width[MAX_DIMM_PER_PORT] = {0};
    FAPI_TRY(mss::eff_dram_width(i_target, &(l_dram_width[0])), "Failed to get the DRAM's width for %s",
             mss::c_str(i_target));

    {
        const auto& l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target);
        FAPI_ASSERT((l_dram_width[0] == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4) ||
                    (l_dram_width[0] == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8),
                    fapi2::MSS_INVALID_DRAM_WIDTH().
                    set_DIMM_TARGET(l_dimms[0]).
                    set_DRAM_WIDTH(l_dram_width[0]),
                    "%s DRAM width was not x4 or x8 - %lu", mss::c_str(i_target), l_dram_width[0]);
    }

    // We only need to check DIMM 0 due to the plug rules
    // x4 DIMM
    if(l_dram_width[0] == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4)
    {
        FAPI_TRY(change_dram_bit_helper<fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4>(i_target, i_dram, i_state));
    }
    // x8 DIMM. The else is ok here as we checked the widths above
    else
    {
        FAPI_TRY(change_dram_bit_helper<fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8>(i_target, i_dram, i_state));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures all DRAM level configuration bits to the inputted settings
/// @param[in] i_target a fapi2::Target MCA
/// @param[in] i_state - OFF_N - 1's, ON_N - 0's
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note PDA is LOW enable, so 0's means ON. ON will configure the register to 0's - using OFF/ON_N
///
fapi2::ReturnCode blast_dram_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const mss::states& i_state )
{
    typedef mss::dp16Traits<fapi2::TARGET_TYPE_MCA> TT;

    std::vector<fapi2::buffer<uint64_t>> l_reg_data;

    // Gets the register data
    FAPI_TRY(mss::scom_suckah(i_target, TT::DATA_BIT_ENABLE1, l_reg_data));

    // Loops and modifies the data
    for(auto& l_data : l_reg_data)
    {
        // Remember 1 = OFF
        set_dram_enable<DRAM0>(l_data, i_state);
        set_dram_enable<DRAM1>(l_data, i_state);
        set_dram_enable<DRAM2>(l_data, i_state);
        set_dram_enable<DRAM3>(l_data, i_state);
    }

    // Blasts the data back out
    FAPI_TRY(mss::scom_blastah(i_target, TT::DATA_BIT_ENABLE1, l_reg_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures PDA timings
/// @param[in] i_target a fapi2::Target MCA
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode configure_timings( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // Fun fact, we're hitting all of the bits in this reg, no need for RMW
    fapi2::buffer<uint64_t> l_data;

    // So we want to:
    // 1) Turn on the PDA on MRS bit
    // 2) Have a 0 delay between the MRS being sent and starting the 0/1 latching
    // 3) Hold the delay for as long as possible (safer and easier than figuring out how long to hold the values)
    mss::wc::set_pda_mode(l_data, mss::states::ON);
    mss::wc::set_pda_dq_on_delay(l_data, START_DELAY_VALUE);
    mss::wc::set_pda_dq_off_delay(l_data, HOLD_DELAY_VALUE);

    // Set that reg
    FAPI_TRY(mss::wc::write_config3(i_target, l_data));

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Adds a PDA enable command
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @param[in,out] io_inst the CCS instructions to update
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode add_enable( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const uint64_t i_rank,
                              std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst )
{
    mss::ddr4::mrs03_data l_mrs03( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "%s Unable to construct MRS03 data from attributes", mss::c_str(i_target));

    // Overrides the PDA value to be enabled
    l_mrs03.iv_pda = fapi2::ENUM_ATTR_EFF_PER_DRAM_ACCESS_ENABLE;

    FAPI_TRY( mss::mrs_engine(i_target, l_mrs03, i_rank, DELAY, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enters into and configures PDA mode
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode enter( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                         const uint64_t i_rank )
{
    ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;

    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    FAPI_TRY( add_enable(i_target, i_rank, l_program.iv_instructions) );

    FAPI_TRY( ccs::execute(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target),
                           l_program,
                           l_mca),
              "unable to execute CCS for MR03 rank %d %s",
              i_rank, mss::c_str(i_target) );

    // Now sets up all of the PDA regs now that we are in PDA mode
    FAPI_TRY(configure_timings(l_mca));
    FAPI_TRY(blast_dram_config(l_mca, mss::states::OFF_N));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Adds a PDA disable command
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @param[in,out] io_inst the instructions
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode add_disable( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                               const uint64_t i_rank,
                               std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst )
{
    mss::ddr4::mrs03_data l_mrs03( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "%s Unable to construct MRS03 data from attributes", mss::c_str(i_target));

    // Overrides the PDA value to be disabled
    l_mrs03.iv_pda = fapi2::ENUM_ATTR_EFF_PER_DRAM_ACCESS_DISABLE;

    FAPI_TRY( mss::mrs_engine(i_target, l_mrs03, i_rank, DELAY, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Exits out of and disables PDA mode
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode exit( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const uint64_t i_rank )
{
    ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;

    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // We need everyone to exit PDA mode, so all of them are all ON
    FAPI_TRY(blast_dram_config(l_mca, mss::states::ON_N));

    FAPI_TRY( add_disable(i_target, i_rank, l_program.iv_instructions) );

    FAPI_TRY( mss::ccs::workarounds::exit(i_target, i_rank, l_program) );

    FAPI_TRY( ccs::execute(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target),
                           l_program,
                           l_mca),
              "unable to execute CCS for MR03 PDA exit rank %d %s",
              i_rank, mss::c_str(i_target) );

    // Disables PDA mode
    {
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(mss::wc::read_config3(l_mca, l_data));
        mss::wc::set_pda_mode(l_data, mss::states::OFF);
        FAPI_TRY(mss::wc::write_config3(l_mca, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Performs a PDA WR VREF latch
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_rank the rank to send to
/// @param[in] i_mrs the MRS data to update
/// @param[in] i_drams the DRAM to update
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note A PDA latch of WR VREF settings is the most common PDA operations
/// This function adds a bit of fanciness (compression) to speed up the overall runtime
///
fapi2::ReturnCode execute_wr_vref_latch( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        const mss::ddr4::mrs06_data& i_mrs,
        const std::vector<uint64_t>& i_drams )
{
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    // If the commands passed in are empty, simply exit
    FAPI_ASSERT((!i_drams.empty()),
                fapi2::MSS_EMPTY_PDA_VECTOR().
                set_PROCEDURE(mss::ffdc_function_codes::PDA_WR_VREF_LATCH_VECTOR),
                "%s PDA commands vector is empty, exiting", mss::c_str(i_target));

    // Enable all individual DRAM
    for(const auto l_dram : i_drams)
    {
        FAPI_TRY(change_dram_bit( l_mca, l_dram, mss::states::ON_N));
    }

    // Issue MRS commands
    {
        ccs::program<fapi2::TARGET_TYPE_MCBIST> l_program;

        FAPI_TRY(mss::ddr4::add_latch_wr_vref_commands( i_target,
                 i_mrs,
                 i_rank,
                 l_program.iv_instructions));

        FAPI_TRY( ccs::execute(mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target),
                               l_program,
                               l_mca),
                  "unable to execute CCS for MR06 rank %d %s",
                  i_rank, mss::c_str(i_target) );
    }

    // Disable all individual DRAM
    for(const auto l_dram : i_drams)
    {
        FAPI_TRY(change_dram_bit( l_mca, l_dram, mss::states::OFF_N));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Performs a PDA WR VREF latch
/// @param[in] i_commands the PDA commands to issue and DRAM
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note A PDA latch of WR VREF settings is the most common PDA operations
/// This function adds a bit of fanciness (compression) to speed up the overall runtime
///
fapi2::ReturnCode execute_wr_vref_latch( const commands<mss::ddr4::mrs06_data>& i_commands )
{
    // If the commands passed in are empty, simply exit
    FAPI_ASSERT((!i_commands.empty()),
                fapi2::MSS_EMPTY_PDA_VECTOR().
                set_PROCEDURE(mss::ffdc_function_codes::PDA_WR_VREF_LATCH_CONTAINER),
                "PDA commands map is empty, exiting");

    // Loop until all commands have been issued
    for(const auto& l_commands : i_commands.get())
    {
        // PDA targetting information - stores both the DIMM and rank in a pair
        const auto& l_target_info = l_commands.first;
        const auto& l_dimm = l_target_info.first;
        const auto l_rank = l_target_info.second;

        // The PDA commands consist of MRS's and their associated DRAM's
        const auto& l_pda_commands = l_commands.second;

        // First, enter into PDA mode
        FAPI_TRY(enter(l_dimm, l_rank));

        // Now loops through all of the MRS and DRAM
        for(const auto& l_command : l_pda_commands)
        {
            const auto& l_mrs = l_command.first;
            const auto& l_drams = l_command.second;
            FAPI_TRY(execute_wr_vref_latch( l_dimm,
                                            l_rank,
                                            l_mrs,
                                            l_drams ));
        }

        // Finally, exit out of PDA
        FAPI_TRY(exit(l_dimm, l_rank));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns pda

} // ns ddr4

} // ns mss
