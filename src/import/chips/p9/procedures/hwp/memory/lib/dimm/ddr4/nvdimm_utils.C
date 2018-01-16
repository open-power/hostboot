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
/// @brief Subroutines to support nvdimm backup/restore process
///
// *HWP HWP Owner: Tsung Yeung <tyeung@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <vector>

#include <lib/dimm/ddr4/nvdimm_utils.H>
#include <lib/ccs/ccs.H>
#include <lib/mc/port.H>
#include <lib/phy/dp16.H>
#include <lib/dimm/rank.H>
#include <lib/dimm/rcd_load.H>
#include <lib/dimm/mrs_load.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/workarounds/ccs_workarounds.H>
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
/// @brief Put target into self-refresh
/// Specializaton for TARGET_TYPE_DIMM
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode self_refresh_entry( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target )
{
    std::vector<uint64_t> l_ranks;
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    mss::ccs::program<TARGET_TYPE_MCBIST> l_program;
    // Timings on these guys should be pretty short
    l_program.iv_poll.iv_initial_delay = DELAY_100NS;
    l_program.iv_poll.iv_initial_sim_delay = DELAY_100NS;

    // Get all the ranks in the dimm
    FAPI_TRY( mss::rank::ranks(i_target, l_ranks) );

    // Prep the instructions to put each rank into self refresh
    for ( const auto& l_rank : l_ranks )
    {
        l_program.iv_instructions.push_back( mss::ccs::self_refresh_entry_command<TARGET_TYPE_MCBIST>(i_target, l_rank) );
    }

    // Hacks to hold low order ranks CKE low in higher order rank instruction
    mss::ccs::workarounds::hold_cke_low(l_program);

    // Setup the CKE to latch for the final command with the CKE from our final true command
    l_program.set_last_cke_value();

    // Sets the CCS address mux register to latch in the CKE state that was on the bus last
    // This is needed to keep the DIMM in self-time refresh mode
    FAPI_TRY(mss::change_addr_mux_sel(l_mca, mss::states::HIGH));

    // Disable refresh
    FAPI_TRY( mss::change_refresh_enable(l_mca, states::LOW) );

    // Execute CCS
    FAPI_TRY( mss::ccs::execute( l_mcbist, l_program, l_mca ) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Take the target out of self-refresh and restart refresh
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< >
fapi2::ReturnCode self_refresh_exit( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target )
{

    std::vector<uint64_t> l_ranks;
    const auto& l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);
    const auto& l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    mss::ccs::program<TARGET_TYPE_MCBIST> l_program;
    l_program.iv_poll.iv_initial_delay = DELAY_100NS;
    l_program.iv_poll.iv_initial_sim_delay = DELAY_100NS;

    // Get all the ranks in the dimm
    mss::rank::ranks(i_target, l_ranks);

    // Prep the instructions to take each rank out of self refresh
    for ( const auto& l_rank : l_ranks )
    {
        l_program.iv_instructions.push_back( mss::ccs::self_refresh_exit_command<fapi2::TARGET_TYPE_MCBIST>(i_target, l_rank) );
    }

    // Hacks to hold CKE high, so we don't put any ranks accidentally into power down mode
    mss::ccs::workarounds::hold_cke_high(l_program);

    // Setup the CKE to latch for the final command with the CKE from our final true command
    l_program.set_last_cke_value();

    // Restores the CCS address mux select to its mainline setting
    FAPI_TRY(mss::change_addr_mux_sel(l_mca, mss::states::LOW));

    // Execute CCS
    FAPI_TRY( mss::ccs::execute( l_mcbist, l_program, l_mca ) );

    // Enable refresh
    FAPI_TRY( mss::change_refresh_enable(l_mca, states::HIGH) );

fapi_try_exit:
    return fapi2::current_err;
}

}//ns nvdimm

}//ns mss
