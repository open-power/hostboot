/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/nvdimm_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file nvdimm_utils.C
/// @brief Subroutines to support nvdimm restore process.
///
// *HWP HWP Owner: Tsung Yeung <tyeung@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <vector>

#include <lib/dimm/ddr4/nvdimm_utils.H>
#include <lib/mc/mc.H>
#include <lib/ccs/ccs.H>
#include <lib/dimm/rank.H>
#include <lib/mss_attribute_accessors.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/mcbist.H>
#include <lib/mcbist/settings.H>
#include <lib/utils/mss_nimbus_conversions.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/mc/port.H>
#include <lib/phy/dp16.H>
#include <lib/dimm/mrs_load.H>
#include <lib/dimm/ddr4/pda.H>
#include <lib/dimm/ddr4/zqcal.H>
#include <lib/dimm/ddr4/control_word_ddr4.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <lib/eff_config/timing.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{

namespace nvdimm
{


///
/// @brief Wrapper to read MAINT_ADDR_MODE_EN
/// Specialization for TARGET_TYPE_MCA
/// @param[in] i_target the target associated with this subroutine
/// @param[out] o_state MAINT_ADDR_MODE_EN state
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< >
fapi2::ReturnCode get_maint_addr_mode_en( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        mss::states& o_state )
{
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    typedef mcbistTraits<TARGET_TYPE_MCBIST> TT;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( mss::getScom(l_mcbist, TT::MCBAGRAQ_REG, l_data),
              "%s Failed getScom", mss::c_str(l_mcbist) );
    o_state = l_data.getBit<TT::MAINT_ADDR_MODE_EN>() ? mss::states::HIGH : mss::states::LOW;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief change maintenance address mode
/// Specialization for TARGET_TYPE_MCA
/// @param[in] i_target the target associated with this subroutine
/// @param[in] i_state the state to change to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< >
fapi2::ReturnCode change_maint_addr_mode_en( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const mss::states i_state )
{
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    typedef mcbistTraits<TARGET_TYPE_MCBIST> TT;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( mss::getScom(l_mcbist, TT::MCBAGRAQ_REG, l_data),
              "%s Failed getScom", mss::c_str(l_mcbist) );
    l_data.writeBit<TT::MAINT_ADDR_MODE_EN>(i_state);

    FAPI_TRY( mss::putScom(l_mcbist, TT::MCBAGRAQ_REG, l_data),
              "%s Failed putScom", mss::c_str(l_mcbist) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief change ECC check and correct mode
/// Specialization for TARGET_TYPE_MCA
/// @param[in] i_target the target associated with this subroutine
/// @param[in] i_state the state to change to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< >
fapi2::ReturnCode change_ecc_check_correct_disable( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const mss::states i_state )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(mss::read_recr_register(i_target, l_data));
    mss::set_ecc_check_disable(l_data, i_state);
    FAPI_TRY(mss::write_recr_register(i_target, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief cleanup after targeted scrub
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode targeted_scrub_cleanup( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    fapi2::buffer<uint64_t> l_data;

    // Clear the command complete to make sure PRD doesn't pick this up later
    FAPI_TRY(mss::read_mcbfirq(l_mcbist, l_data));
    mss::clear_mcbist_program_complete(l_data);
    FAPI_TRY(mss::write_mcbfirq(l_mcbist, l_data));

    // Re-enable ECC check on the given port
    FAPI_TRY(change_ecc_check_correct_disable(i_target, mss::states::ON_N));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper for self_refresh_exit(). Uses scrub to make 1 address read to force
/// CKE back to high.
/// Specialization for TARGET_TYPE_MCA
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< >
fapi2::ReturnCode self_refresh_exit_helper( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{

    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    fapi2::buffer<uint64_t> l_status;
    fapi2::buffer<uint64_t> l_recr_buf;
    fapi2::buffer<uint64_t> l_mcbfirq_buf;
    fapi2::buffer<uint64_t> l_mcbfirmask_buf;
    mss::states l_complete_mask = mss::states::LOW;
    mss::states l_wat_debug_attn_mask = mss::states::LOW;

    // A small vector of addresses to poll during the polling loop
    const std::vector<mss::poll_probe<fapi2::TARGET_TYPE_MCBIST>> l_probes =
    {
        {l_mcbist, "mcbist current address", MCBIST_MCBMCATQ},
    };

    // We'll fill in the initial delay below
    // Heuristically defined and copied from the f/w version of memdiags
    mss::poll_parameters l_poll_parameters(0, 200, 100 * mss::DELAY_1MS, 200, 500);

    // Setting initial delay for 1 read (64 bytes)
    l_poll_parameters.iv_initial_delay = mss::calculate_initial_delay(l_mcbist, 64);

    // Need to disable ECC check because we are reading without the proper settings on the DRAMs
    FAPI_TRY(change_ecc_check_correct_disable(i_target, mss::states::OFF_N));

    // Save the current value to restore later
    FAPI_TRY(mss::read_mcbfirmask(l_mcbist, l_mcbfirmask_buf));
    mss::get_mcbist_program_complete_mask(l_mcbfirmask_buf, l_complete_mask);
    mss::get_mcbist_wat_debug_attn_mask(l_mcbfirmask_buf, l_wat_debug_attn_mask);

    // Mask the command complete so they don't show up in error log
    mss::set_mcbist_program_complete_mask(l_mcbfirmask_buf, mss::states::ON);
    mss::set_mcbist_wat_debug_attn_mask(l_mcbfirmask_buf, mss::states::ON);
    FAPI_TRY(mss::write_mcbfirmask(l_mcbist, l_mcbfirmask_buf));

    {
        // Force this to run on the targeted port only
        const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);
        mss::mcbist::address l_start = 0, l_end = 0;
        mss::mcbist::end_boundary l_end_boundary = mss::mcbist::end_boundary::STOP_AFTER_SLAVE_RANK;
        l_start.set_port(l_port);
        mss::mcbist::stop_conditions l_stop_conditions;

        // Read with targeted scrub
        FAPI_TRY ( mss::memdiags::targeted_scrub(l_mcbist,
                   l_stop_conditions,
                   l_start,
                   l_end,
                   l_end_boundary) );

        bool l_poll_results = mss::poll(l_mcbist, MCBIST_MCBISTFIRQ, l_poll_parameters,
                                        [&l_status](const size_t poll_remaining,
                                                const fapi2::buffer<uint64_t>& stat_reg) -> bool
        {
            FAPI_DBG("mcbist firq 0x%llx, remaining: %d", stat_reg, poll_remaining);
            l_status = stat_reg;
            return l_status.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == true;
        },
        l_probes);

        FAPI_DBG("targeted_scrub poll result: %d", l_poll_results);

        FAPI_ASSERT(l_poll_results,
                    fapi2::MSS_NVDIMM_TARGETED_SCRUB_STR_EXIT_FAILED_TO_COMPLETE().
                    set_MCA_TARGET(i_target).
                    set_MCBIST_TARGET(l_mcbist),
                    "targeted scrub failed to complete on %s", mss::c_str(i_target));
    }

    // Clean up the commmand complete and re-enable ECC check and correct
    FAPI_TRY(targeted_scrub_cleanup(i_target));

    // Restore the mask to the original value
    FAPI_TRY(mss::read_mcbfirmask(l_mcbist, l_mcbfirmask_buf));
    mss::set_mcbist_program_complete_mask(l_mcbfirmask_buf, l_complete_mask);
    mss::set_mcbist_wat_debug_attn_mask(l_mcbfirmask_buf, l_wat_debug_attn_mask);
    FAPI_TRY(mss::write_mcbfirmask(l_mcbist, l_mcbfirmask_buf));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Put target into self-refresh
/// Specialization for TARGET_TYPE_MCA
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode self_refresh_entry( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    fapi2::buffer<uint64_t> l_mbarpc0_data, l_mbastr0_data;

    // Entry time to 0 for immediate entry
    constexpr uint64_t l_str_entry_time = 0;

    // Step 1 - In MBARPC0Q, disable power domain control, set domain to MAXALL_MIN0,
    //          and disable minimum domain reduction (allow immediate entry of STR)
    FAPI_TRY(mss::mc::read_mbarpc0(i_target, l_mbarpc0_data));
    mss::mc::set_power_control_min_max_domains_enable( l_mbarpc0_data, mss::states::OFF );
    mss::mc::set_power_control_min_max_domains( l_mbarpc0_data, mss::min_max_domains::MAXALL_MIN0 );
    mss::mc::set_power_control_min_domain_reduction_enable( l_mbarpc0_data, mss::states::OFF );
    FAPI_TRY(mss::mc::write_mbarpc0(i_target, l_mbarpc0_data));

    // Step 2 - In MBASTR0Q, enable STR entry
    FAPI_TRY(mss::mc::read_mbastr0(i_target, l_mbastr0_data));
    mss::mc::set_self_time_refresh_enable( l_mbastr0_data, mss::states::ON );
    mss::mc::set_enter_self_time_refresh_time( l_mbastr0_data, l_str_entry_time );
    FAPI_TRY(mss::mc::write_mbastr0(i_target, l_mbastr0_data));

    // Step 3 - In MBARPC0Q, enable power domain control.
    mss::mc::set_power_control_min_max_domains_enable( l_mbarpc0_data, mss::states::ON );
    FAPI_TRY(mss::mc::write_mbarpc0(i_target, l_mbarpc0_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Take the target out of self-refresh and restart refresh
/// Specialization for TARGET_TYPE_MCA
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< >
fapi2::ReturnCode self_refresh_exit( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    fapi2::buffer<uint64_t> l_mbarpc0_data, l_mbastr0_data;

    // Step 1 - In MBARPC0Q, disable power domain control.
    FAPI_TRY(mss::mc::read_mbarpc0(i_target, l_mbarpc0_data));
    mss::mc::set_power_control_min_max_domains_enable( l_mbarpc0_data, mss::states::OFF );
    FAPI_TRY(mss::mc::write_mbarpc0(i_target, l_mbarpc0_data));

    // Step 2 - Run memdiags to read the port to force CKE back to high
    FAPI_TRY(self_refresh_exit_helper(i_target));

    // maint_addr_mode could be enabled by the helper. Disable it before exiting
    // otherwise it will introduce problem to other DIMMs on the same MCBIST
    FAPI_TRY(change_maint_addr_mode_en(i_target, mss::states::LOW));

    // Restore MBASTR0Q and MBARPC0Q to the original values based on MRW
    FAPI_TRY(mss::mc::set_pwr_cntrl_reg(i_target));
    FAPI_TRY(mss::mc::set_str_reg(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief PDA support for post restore transition
/// Specialization for TARGET_TYPE_DIMM
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode pda_vref_latch( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target )
{
    std::vector<uint64_t> l_ranks;
    const auto& l_mca = mss::find_target<TARGET_TYPE_MCA>(i_target);
    fapi2::buffer<uint8_t> l_value, l_range;
    fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);

    // Creates the MRS container class
    mss::ddr4::pda::commands<mss::ddr4::mrs06_data> l_container;

    // Get all the ranks in the dimm
    mss::rank::ranks(i_target, l_ranks);

    // Get the number of DRAMs
    uint8_t l_width = 0;
    mss::eff_dram_width(i_target, l_width);
    const uint64_t l_num_drams = (l_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ? MAX_DRAMS_X8 : MAX_DRAMS_X4;

    for (const auto& l_rank : l_ranks)
    {

        uint64_t l_rp = 0;
        uint64_t l_wr_vref_value = 0;
        bool l_wr_vref_range = 0;
        fapi2::buffer<uint64_t> l_data ;

        mss::rank::get_pair_from_rank(l_mca, l_rank, l_rp);

        // create mrs06
        mss::ddr4::mrs06_data l_mrs(i_target, l_rc);

        // loop through all the dram
        for(uint64_t l_dram = 0; l_dram < l_num_drams; l_dram++)
        {
            mss::dp16::wr_vref::read_wr_vref_register( l_mca, l_rp, l_dram, l_data);
            mss::dp16::wr_vref::get_wr_vref_range( l_data, l_dram, l_wr_vref_range);
            mss::dp16::wr_vref::get_wr_vref_value( l_data, l_dram, l_wr_vref_value);

            l_mrs.iv_vrefdq_train_value[mss::index(l_rank)] = l_wr_vref_value;
            l_mrs.iv_vrefdq_train_range[mss::index(l_rank)] = l_wr_vref_range;
            l_container.add_command(i_target, l_rank, l_mrs, l_dram);
        }
    }

    // Disable refresh
    FAPI_TRY( mss::change_refresh_enable(l_mca, states::LOW) );

    // execute_wr_vref_latch(l_container)
    FAPI_TRY( mss::ddr4::pda::execute_wr_vref_latch(l_container) )

    // Enable refresh
    FAPI_TRY( mss::change_refresh_enable(l_mca, states::HIGH) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Disable powerdown mode in rc09
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode rc09_disable_powerdown( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    FAPI_INF("rc09_disable_powerdown %s", mss::c_str(i_target));

    constexpr uint8_t POWER_DOWN_BIT = 4;
    constexpr bool l_sim = false;
    constexpr uint8_t FS0 = 0; // Function space 0
    constexpr uint64_t CKE_HIGH = mss::ON;
    fapi2::buffer<uint8_t> l_rc09_cw = 0;
    std::vector<uint64_t> l_ranks;

    FAPI_TRY(mss::eff_dimm_ddr4_rc09(i_target, l_rc09_cw));

    // Clear power down enable bit.
    l_rc09_cw.clearBit<POWER_DOWN_BIT>();

    FAPI_TRY( mss::rank::ranks(i_target, l_ranks) );

    // DES to ensure we exit powerdown properly
    FAPI_DBG("deselect for %s", mss::c_str(i_target));
    io_inst.push_back( ccs::des_command<TARGET_TYPE_MCBIST>() );

    static const cw_data l_rc09_4bit_data( FS0, 9, l_rc09_cw, mss::tmrd() );

    // Load RC09
    FAPI_TRY( control_word_engine<RCW_4BIT>(i_target, l_rc09_4bit_data, l_sim, io_inst, CKE_HIGH),
              "Failed to load 4-bit RC09 control word for %s",
              mss::c_str(i_target));

    // Hold the CKE high
    mss::ccs::workarounds::hold_cke_high(io_inst);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Load the rcd control words
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @Note This is similar to rcd_load_ddr4() but with minor changes to support
///       with NVDIMMs
///
fapi2::ReturnCode rcd_load_nvdimm( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                   std::vector< ccs::instruction_t<TARGET_TYPE_MCBIST> >& io_inst)
{
    FAPI_INF("rcd_load_nvdimm %s", mss::c_str(i_target));

    constexpr uint64_t CKE_LOW = mss::OFF;
    constexpr bool l_sim = false;

    // Per DDR4RCD02, tSTAB is us. We want this in cycles for the CCS.
    const uint64_t tSTAB = mss::us_to_cycles(i_target, mss::tstab());
    constexpr uint8_t FS0 = 0; // Function space 0

    // RCD 4-bit data - integral represents rc#
    static const std::vector< cw_data > l_rcd_4bit_data =
    {
        { FS0, 0,  eff_dimm_ddr4_rc00,    mss::tmrd()    },
        { FS0, 1,  eff_dimm_ddr4_rc01,    mss::tmrd()    },
        { FS0, 2,  eff_dimm_ddr4_rc02,    tSTAB          },
        { FS0, 3,  eff_dimm_ddr4_rc03,    mss::tmrd_l()  },
        { FS0, 4,  eff_dimm_ddr4_rc04,    mss::tmrd_l()  },
        { FS0, 5,  eff_dimm_ddr4_rc05,    mss::tmrd_l()  },
        // Note: the tMRC1 timing as it is larger for saftey's sake
        // The concern is that if geardown mode is ever required in the future, we would need the longer timing
        { FS0, 6,  eff_dimm_ddr4_rc06_07, mss::tmrc1()   },
        { FS0, 8,  eff_dimm_ddr4_rc08,    mss::tmrd()    },
        { FS0, 10, eff_dimm_ddr4_rc0a,    tSTAB          },
        { FS0, 11, eff_dimm_ddr4_rc0b,    mss::tmrd_l()  },
        { FS0, 12, eff_dimm_ddr4_rc0c,    mss::tmrd()    },
        { FS0, 13, eff_dimm_ddr4_rc0d,    mss::tmrd_l2() },
        { FS0, 14, eff_dimm_ddr4_rc0e,    mss::tmrd()    },
        { FS0, 15, eff_dimm_ddr4_rc0f,    mss::tmrd_l2() },
    };

    // RCD 4-bit data - integral represents rc#
    static const cw_data l_rc09_4bit_data( FS0, 9, eff_dimm_ddr4_rc09, mss::tmrd() );

    // RCD 8-bit data - integral represents rc#
    static const std::vector< cw_data > l_rcd_8bit_data =
    {
        { FS0, 1,  eff_dimm_ddr4_rc_1x, mss::tmrd()   },
        { FS0, 2,  eff_dimm_ddr4_rc_2x, mss::tmrd()   },
        { FS0, 3,  eff_dimm_ddr4_rc_3x, tSTAB         },
        { FS0, 4,  eff_dimm_ddr4_rc_4x, mss::tmrd()   },
        { FS0, 5,  eff_dimm_ddr4_rc_5x, mss::tmrd()   },
        { FS0, 6,  eff_dimm_ddr4_rc_6x, mss::tmrd()   },
        { FS0, 7,  eff_dimm_ddr4_rc_7x, mss::tmrd_l() },
        { FS0, 8,  eff_dimm_ddr4_rc_8x, mss::tmrd()   },
        { FS0, 9,  eff_dimm_ddr4_rc_9x, mss::tmrd()   },
        { FS0, 10, eff_dimm_ddr4_rc_ax, mss::tmrd()   },
        { FS0, 11, eff_dimm_ddr4_rc_bx, mss::tmrd_l() },
    };

    // Load 4-bit data
    FAPI_TRY( control_word_engine<RCW_4BIT>(i_target, l_rcd_4bit_data, l_sim, io_inst, CKE_LOW),
              "Failed to load 4-bit control words for %s",
              mss::c_str(i_target));

    // Load 8-bit data
    FAPI_TRY( control_word_engine<RCW_8BIT>(i_target, l_rcd_8bit_data, l_sim, io_inst, CKE_LOW),
              "Failed to load 8-bit control words for %s",
              mss::c_str(i_target));

    // Load RC09 with CKE_LOW
    FAPI_TRY( control_word_engine<RCW_4BIT>(i_target, l_rc09_4bit_data, l_sim, io_inst, CKE_LOW),
              "Failed to load 4-bit RC09 control word for %s",
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Restore the rcd after restoring the nvdimm data
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_MCA>
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @Note Restoring the RCD after NVDIMM restore requires a special procedure
///       The procedure from draminit would actually fail to restore the CWs
///
fapi2::ReturnCode rcd_restore( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    const auto& l_mcbist = mss::find_target<TARGET_TYPE_MCBIST>(i_target);
    std::vector<uint64_t> l_ranks;

    // A vector of CCS instructions. We'll ask the targets to fill it, and then we'll execute it
    ccs::program<TARGET_TYPE_MCBIST> l_program;

    // Clear the initial delays. This will force the CCS engine to recompute the delay based on the
    // instructions in the CCS instruction vector
    l_program.iv_poll.iv_initial_delay = 0;
    l_program.iv_poll.iv_initial_sim_delay = 0;

    // We expect to come in with the port in STR. Before proceeding with
    // restoring the RCD, power down needs to be disabled first on the RCD so
    // the rest of the CWs can be restored with CKE low
    for ( const auto& d : mss::find_targets<TARGET_TYPE_DIMM>(i_target) )
    {
        FAPI_DBG("rc09_disable_powerdown for %s", mss::c_str(d));
        FAPI_TRY( rc09_disable_powerdown(d, l_program.iv_instructions),
                  "Failed rc09_disable_powerdown() for %s", mss::c_str(d) );
    }// dimms

    // Exit STR first so CKE is back to high and rcd isn't ignoring us
    FAPI_TRY( self_refresh_exit( i_target ) );

    FAPI_TRY( ccs::execute(l_mcbist, l_program, i_target),
              "Failed to execute ccs for %s", mss::c_str(i_target) );

    // Now, drive CKE back to low via STR entry instead of pde (we have data in the drams!)
    FAPI_TRY( self_refresh_entry( i_target ) );

    l_program = ccs::program<TARGET_TYPE_MCBIST>(); //Reset the program

    // Now, fill the program with instructions to program the RCD
    for ( const auto& d : mss::find_targets<TARGET_TYPE_DIMM>(i_target) )
    {
        FAPI_DBG("rcd_load_nvdimm( for %s", mss::c_str(d));
        FAPI_TRY( rcd_load_nvdimm(d, l_program.iv_instructions),
                  "Failed rcd_load_nvdimm() for %s", mss::c_str(d) );
    }// dimms

    // Restore the rcd
    FAPI_TRY( ccs::execute(l_mcbist, l_program, i_target),
              "Failed to execute ccs for %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Execute post restore ZQCAL
/// @param[in] i_target the target associated with this cal
/// @return FAPI2_RC_SUCCESS iff setup was successful
/// @Note The original zqcal has delay that violates the refresh interval.
///       Since we now have data in the DRAMs, the command will execute
///       with delay following the spec.
///
fapi2::ReturnCode post_restore_zqcal( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    const auto& l_mcbist = mss::find_target<TARGET_TYPE_MCBIST>(i_target);
    std::vector<uint64_t> l_ranks;
    uint8_t l_trp[MAX_DIMM_PER_PORT];
    ccs::program<TARGET_TYPE_MCBIST> l_program;

    // Get tRP
    FAPI_TRY(mss::eff_dram_trp(mss::find_target<fapi2::TARGET_TYPE_MCS>(i_target), l_trp));

    // Construct the program
    for ( const auto& d : mss::find_targets<TARGET_TYPE_DIMM>(i_target) )
    {
        FAPI_TRY( mss::rank::ranks(d, l_ranks) );

        for ( const auto r : l_ranks)
        {
            FAPI_DBG("precharge_all_command for %s", mss::c_str(d));
            l_program.iv_instructions.push_back( ccs::precharge_all_command<TARGET_TYPE_MCBIST>(d, r, l_trp[0]) );
            FAPI_DBG("zqcal_command for %s", mss::c_str(d));
            l_program.iv_instructions.push_back( ccs::zqcl_command<TARGET_TYPE_MCBIST>(d, r, mss::tzqinit()) );
        }
    }// dimms

    // execute ZQCAL instructions
    FAPI_TRY( mss::ccs::execute(l_mcbist, l_program, i_target),
              "Failed to execute ccs for ZQCAL %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Post restore transition to support restoring nvdimm to
/// a functional state after the restoring the data from NAND flash
/// to DRAM
/// Specialization for TARGET_TYPE_MCA
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode post_restore_transition( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    mss::states l_maint_addr_enabled = mss::states::LOW;

    FAPI_TRY(get_maint_addr_mode_en(i_target, l_maint_addr_enabled));

    if (l_maint_addr_enabled)
    {
        //If maint addr, disable it before doing rcd_load(). RCD load
        //this bit on can interfere with other ports on the same mcbist
        FAPI_TRY(change_maint_addr_mode_en(i_target, mss::states::LOW));
    }

    // Restore the rcd
    FAPI_TRY( rcd_restore( i_target ) );

    // Exit STR
    FAPI_TRY( self_refresh_exit( i_target ) );

    // Load the MRS
    FAPI_TRY( mss::mrs_load( i_target ) );

    // Do ZQCAL
    FAPI_TRY( post_restore_zqcal(i_target) );

    // Latch the trained PDA vref values for each dimm under the port
    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY( pda_vref_latch( l_dimm ) );
    }

    //Restore main_addr_mode_en to previous setting
    FAPI_TRY(change_maint_addr_mode_en(i_target, l_maint_addr_enabled));

fapi_try_exit:
    return fapi2::current_err;
}

}//ns nvdimm

}//ns mss
