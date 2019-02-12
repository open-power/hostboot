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
#include <lib/mcbist/address.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/mcbist.H>
#include <lib/mcbist/settings.H>
#include <lib/utils/mss_nimbus_conversions.H>

#include <lib/mc/port.H>
#include <lib/phy/dp16.H>
#include <lib/dimm/rcd_load.H>
#include <lib/dimm/mrs_load.H>
#include <lib/dimm/ddr4/pda.H>
#include <lib/dimm/ddr4/zqcal.H>

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
/// @brief Helper for self_refresh_exit(). Uses memdiag to read the port to force
/// CKE back to high. Stolen from mss_lab_memdiags.C
/// Specialization for TARGET_TYPE_MCA
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< >
fapi2::ReturnCode self_refresh_exit_helper( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{

    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    fapi2::buffer<uint64_t> l_status;

    // A small vector of addresses to poll during the polling loop
    const std::vector<mss::poll_probe<fapi2::TARGET_TYPE_MCBIST>> l_probes =
    {
        {l_mcbist, "mcbist current address", MCBIST_MCBMCATQ},
    };

    // We'll fill in the initial delay below
    // Heuristically defined and copied from the f/w version of memdiags
    mss::poll_parameters l_poll_parameters(0, 200, 100 * mss::DELAY_1MS, 200, 500);
    uint64_t l_memory_size = 0;

    FAPI_TRY( mss::eff_memory_size(l_mcbist, l_memory_size) );
    l_poll_parameters.iv_initial_delay = mss::calculate_initial_delay(l_mcbist, (l_memory_size * mss::BYTES_PER_GB));

    {
        // Force this to run on the targeted port only
        const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);
        mss::mcbist::address l_start;
        mss::mcbist::end_boundary l_end_boundary = mss::mcbist::end_boundary::STOP_AFTER_SLAVE_RANK;
        l_start.set_port(l_port);
        mss::mcbist::stop_conditions l_stop_conditions;

        // Read with super fast read
        // Set up with mcbist target, stop conditions above
        // Using defaults for starting at first valid address and stop at end of slave rank
        FAPI_TRY ( mss::memdiags::sf_read(l_mcbist,
                                          l_stop_conditions,
                                          l_start,
                                          l_end_boundary,
                                          l_start) );

        bool l_poll_results = mss::poll(l_mcbist, MCBIST_MCBISTFIRQ, l_poll_parameters,
                                        [&l_status](const size_t poll_remaining,
                                                const fapi2::buffer<uint64_t>& stat_reg) -> bool
        {
            FAPI_DBG("mcbist firq 0x%llx, remaining: %d", stat_reg, poll_remaining);
            l_status = stat_reg;
            return l_status.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == true;
        },
        l_probes);

        FAPI_DBG("memdiags_read poll result: %d", l_poll_results);
    }

    return fapi2::FAPI2_RC_SUCCESS;

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

    // Subseqent restore on later nvdimms would go wonky if this goes before STR exit...
    FAPI_TRY( mss::rcd_load( i_target ) );

    // Exit STR
    FAPI_TRY( self_refresh_exit( i_target ) );

    // Load the MRS
    FAPI_TRY( mss::mrs_load( i_target ) );

    // Do ZQCAL
    {
        fapi2::buffer<uint32_t> l_cal_steps_enabled;
        l_cal_steps_enabled.setBit<mss::DRAM_ZQCAL>();

        FAPI_DBG("cal steps enabled: 0x%08x ", l_cal_steps_enabled);
        FAPI_TRY( mss::setup_and_execute_zqcal(i_target, l_cal_steps_enabled), "Error in nvdimm setup_and_execute_zqcal()" );
    }

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
