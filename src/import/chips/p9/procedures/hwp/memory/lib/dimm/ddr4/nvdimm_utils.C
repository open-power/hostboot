/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/nvdimm_utils.C $ */
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
/// @file nvdimm_utils.C
/// @brief Subroutines to support nvdimm restore process.
///
// *HWP HWP Owner: Tsung Yeung <tyeung@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
#include <vector>

#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <lib/power_thermal/throttle.H>
#include <lib/mc/mc.H>
#include <lib/dimm/rank.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/mcbist/mcbist.H>
#include <lib/utils/mss_nimbus_conversions.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/settings.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/mc/port.H>
#include <lib/phy/dp16.H>

#include <lib/dimm/ddr4/zqcal.H>
#include <lib/dimm/ddr4/control_word_ddr4_nimbus.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <lib/eff_config/timing.H>
#include <lib/dimm/ddr4/latch_wr_vref_nimbus.H>
#include <lib/dimm/ddr4/nvdimm_utils.H>

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
    typedef mcbistTraits<> TT;
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
    typedef mcbistTraits<> TT;
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
        mss::mcbist::stop_conditions<> l_stop_conditions;

        // Read with targeted scrub
        FAPI_TRY ( mss::memdiags::targeted_scrub<mss::mc_type::NIMBUS>(l_mcbist,
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
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // Entry time to 0 for immediate entry
    constexpr uint64_t l_str_entry_time = 0;

    // Stop mcbist (scrub) in case of MPIPL. It will get restarted in the later istep
    FAPI_TRY(mss::mcbist::start_stop(l_mcbist, mss::states::STOP));

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
    FAPI_TRY(mss::power_thermal::set_pwr_cntrl_reg<mss::mc_type::NIMBUS>(i_target));
    FAPI_TRY(mss::power_thermal::set_str_reg<mss::mc_type::NIMBUS>(i_target));

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
                                   std::vector< ccs::instruction_t >& io_inst)
{
    FAPI_INF("rcd_load_nvdimm %s", mss::c_str(i_target));

    constexpr uint64_t CKE_HIGH = mss::ON;
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
    // Keeping the CKE high as this will be done not in powerdown/STR mode. Not affected for
    // the RCD supplier on nvdimm
    FAPI_TRY( control_word_engine<RCW_4BIT>(i_target, l_rcd_4bit_data, l_sim, io_inst, CKE_HIGH),
              "Failed to load 4-bit control words for %s",
              mss::c_str(i_target));

    // Load 8-bit data
    FAPI_TRY( control_word_engine<RCW_8BIT>(i_target, l_rcd_8bit_data, l_sim, io_inst, CKE_HIGH),
              "Failed to load 8-bit control words for %s",
              mss::c_str(i_target));

    // Load RC09 with CKE_LOW
    FAPI_TRY( control_word_engine<RCW_4BIT>(i_target, l_rc09_4bit_data, l_sim, io_inst, CKE_HIGH),
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
    ccs::program l_program;

    // Clear the initial delays. This will force the CCS engine to recompute the delay based on the
    // instructions in the CCS instruction vector
    l_program.iv_poll.iv_initial_delay = 0;
    l_program.iv_poll.iv_initial_sim_delay = 0;

    // Now, fill the program with instructions to program the RCD
    for ( const auto& d : mss::find_targets<TARGET_TYPE_DIMM>(i_target) )
    {
        FAPI_DBG("rcd_load_nvdimm( for %s", mss::c_str(d));
        FAPI_TRY( rcd_load_nvdimm(d, l_program.iv_instructions),
                  "Failed rcd_load_nvdimm() for %s", mss::c_str(d) );
    }// dimms

    // Restore the rcd
    FAPI_TRY( mss::ccs::workarounds::nvdimm::execute(l_mcbist, l_program, i_target),
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
    ccs::program l_program;

    // Get tRP
    FAPI_TRY(mss::eff_dram_trp(mss::find_target<fapi2::TARGET_TYPE_MCS>(i_target), l_trp));

    // Construct the program
    for ( const auto& d : mss::find_targets<TARGET_TYPE_DIMM>(i_target) )
    {
        FAPI_TRY( mss::rank::ranks(d, l_ranks) );

        for ( const auto r : l_ranks)
        {
            FAPI_DBG("precharge_all_command for %s", mss::c_str(d));
            l_program.iv_instructions.push_back( ccs::precharge_all_command(r, l_trp[0]) );
            FAPI_DBG("zqcal_command for %s", mss::c_str(d));
            l_program.iv_instructions.push_back( ccs::zqcl_command(r, mss::tzqinit()) );
        }
    }// dimms

    // execute ZQCAL instructions
    FAPI_TRY( mss::ccs::workarounds::nvdimm::execute(l_mcbist, l_program, i_target),
              "Failed to execute ccs for ZQCAL %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Latch write vref
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode wr_vref_latch( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    std::vector<uint64_t> l_pairs;
    const bool NVDIMM_WORKAROUND = true;

    // We are latching in the averaged value and we should have the averaged value
    // (this step should be run after all the draminit) so just the first dram is fine
    constexpr uint64_t l_dram = 0;

    // Get our rank pairs.
    FAPI_TRY( mss::rank::get_rank_pairs(i_target, l_pairs) );

    for (const auto& l_rp : l_pairs)
    {
        FAPI_INF("NVDIMM wr_vref_latch on rp %d %s", l_rp, mss::c_str(i_target));
        fapi2::buffer<uint64_t> l_data ;
        uint64_t l_wr_vref_value = 0;
        bool l_wr_vref_range = 0;

        mss::dp16::wr_vref::read_wr_vref_register( i_target, l_rp, l_dram, l_data);
        mss::dp16::wr_vref::get_wr_vref_range( l_data, l_dram, l_wr_vref_range);
        mss::dp16::wr_vref::get_wr_vref_value( l_data, l_dram, l_wr_vref_value);

        FAPI_TRY( mss::ddr4::latch_wr_vref_commands_by_rank_pair(i_target,
                  l_rp,
                  l_wr_vref_range,
                  l_wr_vref_value,
                  NVDIMM_WORKAROUND) );

    }// rank pairs

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
    mss::states l_refresh_overrun_mask = mss::states::OFF;
    const bool NVDIMM_WORKAROUND = true;

    FAPI_TRY(get_maint_addr_mode_en(i_target, l_maint_addr_enabled));

    if (l_maint_addr_enabled)
    {
        //If maint addr, disable it before doing rcd_load(). RCD load
        //this bit on can interfere with other ports on the same mcbist
        FAPI_TRY(change_maint_addr_mode_en(i_target, mss::states::LOW));
    }

    // Save the current mask value and mask the refresh overrun error
    FAPI_TRY(get_refresh_overrun_mask(i_target, l_refresh_overrun_mask));
    FAPI_TRY(change_refresh_overrun_mask(i_target, mss::states::ON));

    // Exit STR
    FAPI_TRY( self_refresh_exit( i_target ) );

    // Restore the rcd
    FAPI_TRY( rcd_restore( i_target ) );

    // Load the MRS
    FAPI_TRY( mss::mrs_load( i_target, NVDIMM_WORKAROUND ) );

    // Do ZQCAL
    FAPI_TRY( post_restore_zqcal(i_target) );

    // Latch in the rank averaged vref value
    FAPI_TRY(wr_vref_latch(i_target));

    // Restore main_addr_mode_en to previous setting
    FAPI_TRY(change_maint_addr_mode_en(i_target, l_maint_addr_enabled));

    // Restore the refresh overrun mask to previous and clear the fir
    FAPI_TRY(clear_refresh_overrun_fir(i_target));
    FAPI_TRY(change_refresh_overrun_mask(i_target, l_refresh_overrun_mask));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper to change the BAR valid state. Consumed by hostboot
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode change_bar_valid_state( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint8_t i_state)
{
    const auto& l_mcs = mss::find_target<fapi2::TARGET_TYPE_MCS>(i_target);
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( mss::getScom(l_mcs, MCS_MCFGP, l_data) );
    l_data.writeBit<MCS_MCFGP_VALID>(i_state);
    FAPI_INF("Changing MCS_MCFGP_VALID to %d on %s", i_state, mss::c_str(l_mcs));
    FAPI_TRY( mss::putScom(l_mcs, MCS_MCFGP, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Preload the CCS with the EPOW sequence
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
/// @note This is written specifically to support EPOW on NVDIMM and
///       should only be called after all the draminit.
///
fapi2::ReturnCode preload_epow_sequence( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    typedef ccsTraits<mss::mc_type::NIMBUS> TT;
    const auto& l_mcbist = mss::find_target<TARGET_TYPE_MCBIST>(i_target);
    const auto& l_dimms = mss::find_targets<TARGET_TYPE_DIMM>(i_target);
    constexpr uint64_t CS_N_ACTIVE = 0b00;
    uint8_t l_trp = 0;
    uint16_t l_trfc = 0;
    std::vector<uint64_t> l_ranks;
    ccs::program l_program;
    ccs::instruction_t l_inst;

    // Get tRP and tRFC
    FAPI_TRY(mss::eff_dram_trp(i_target, l_trp));
    FAPI_TRY(mss::eff_dram_trfc(i_target, l_trfc));

    l_program.iv_poll.iv_initial_delay = 0;
    l_program.iv_poll.iv_initial_sim_delay = 0;

    // Start the program with DES and wait for tRFC
    // All CKE = high, all CSn = high, Reset_n = high, wait tRFC
    l_inst = ccs::des_command(l_trfc);
    l_inst.arr0.setBit<TT::ARR0_DDR_RESETN>();
    FAPI_INF("des_command() arr0 = 0x%016lx , arr1 = 0x%016lx", l_inst.arr0, l_inst.arr1);
    l_program.iv_instructions.push_back(l_inst);

    // Precharge all command
    // All CKE = high, all CSn = low, Reset_n = high, wait tRP
    l_inst = ccs::precharge_all_command(0, l_trp);
    l_inst.arr0.insertFromRight<TT::ARR0_DDR_CSN_0_1, TT::ARR0_DDR_CSN_0_1_LEN>(CS_N_ACTIVE);
    l_inst.arr0.insertFromRight<TT::ARR0_DDR_CSN_2_3, TT::ARR0_DDR_CSN_2_3_LEN>(CS_N_ACTIVE);
    l_inst.arr0.setBit<TT::ARR0_DDR_RESETN>();
    FAPI_INF("precharge_all_command() arr0 = 0x%016lx , arr1 = 0x%016lx", l_inst.arr0, l_inst.arr1);
    l_program.iv_instructions.push_back(l_inst);

    // Self-refresh entry command
    // All CKE = low, all CSn = low, Reset_n = high, wait tCKSRE
    l_inst = ccs::self_refresh_entry_command(0, mss::tcksre(l_dimms[0]));
    l_inst.arr0.insertFromRight<TT::ARR0_DDR_CSN_0_1, TT::ARR0_DDR_CSN_0_1_LEN>(CS_N_ACTIVE);
    l_inst.arr0.insertFromRight<TT::ARR0_DDR_CSN_2_3, TT::ARR0_DDR_CSN_2_3_LEN>(CS_N_ACTIVE);
    l_inst.arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(mss::CKE_LOW);
    l_inst.arr0.setBit<TT::ARR0_DDR_RESETN>();
    FAPI_INF("self_refresh_entry_command() arr0 = 0x%016lx , arr1 = 0x%016lx", l_inst.arr0, l_inst.arr1);
    l_program.iv_instructions.push_back(l_inst);

    // Push in an empty instruction for RESETn
    // All CKE = low, all CSn = high (default), Reset_n = low
    l_inst = ccs::instruction_t();
    FAPI_INF("Assert RESETn arr0 = 0x%016lx , arr1 = 0x%016lx", l_inst.arr0, l_inst.arr1);
    l_program.iv_instructions.push_back(l_inst);

    // Load the program
    FAPI_TRY( mss::ccs::workarounds::preload_ccs_for_epow(l_mcbist, l_program),
              "Failed to preload the ccs for epow %s", mss::c_str(i_target) );

    // The actual execution of this program will be trigger by EPOW. When EPOW occurs,
    // OCC will change the mux and hit the go button to execute CCS

fapi_try_exit:
    return fapi2::current_err;
}

}//ns nvdimm

}//ns mss
