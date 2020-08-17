/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/latch_wr_vref.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory
#include <vector>

#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <lib/dimm/rank.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/workarounds/ccs_workarounds.H>
#include <lib/dimm/ddr4/mrs_load_ddr4_nimbus.H>
#include <lib/dimm/ddr4/latch_wr_vref.H>
#include <lib/dimm/nimbus_kind.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{

namespace ddr4
{

///
/// @brief Add latching commands for WR VREF to the instruction array
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_MCA>
/// @param[in] i_rank_pair, rank pair on which to latch MRS 06 - hits all ranks in the rank pair
/// @param[in] i_train_range, VREF range to setup
/// @param[in] i_train_value, VREF value to setup
/// @param[in] i_nvdimm_workaround switch to indicate nvdimm workaround. Default to false
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode latch_wr_vref_commands_by_rank_pair
( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
  const uint64_t i_rank_pair,
  const uint8_t i_train_range,
  const uint8_t i_train_value,
  const bool i_nvdimm_workaround)
{
    // Declares variables
    const auto l_mcbist = find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // Warning: l_dimm is not a valid Target and will crash Cronus if used before it gets filled in by mss::rank::get_dimm_target_from_rank
    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;
    ccs::program l_program;
    std::vector<uint64_t> l_ranks;

    // Gets the ranks on which to latch the VREF's
    FAPI_TRY(mss::rank::get_ranks_in_pair( i_target, i_rank_pair, l_ranks),
             "Failed get_ranks_in_pair in latch_wr_vref_commands_by_rank_pair %s",
             mss::c_str(i_target));

    // Adds in latching commands for all ranks
    for (const auto& l_rank : l_ranks)
    {
        // Skips this rank if no rank is configured
        if (l_rank == NO_RANK)
        {
            continue;
        }

        // Ensures we get a valid DIMM target / rank combo
        FAPI_TRY( mss::rank::get_dimm_target_from_rank(i_target, l_rank, l_dimm),
                  "%s Failed get_dimm_target_from_rank in latch_wr_vref_commands_by_rank_pair",
                  mss::c_str(i_target));

        // Adds the latching commands to the CCS program for this current rank
        FAPI_TRY(setup_latch_wr_vref_commands_by_rank<mss::mc_type::NIMBUS>(l_dimm,
                 l_rank,
                 i_train_range,
                 i_train_value,
                 l_program.iv_instructions),
                 "%s Failed setup_latch_wr_vref_commands_by_rank in latch_wr_vref_commands_by_rank_pair",
                 mss::c_str(i_target));
    }

    // Executes the CCS commands
    // Run the NVDIMM-specific execute procedure if this is for nvdimm workaround.
    // Otherwise, execute as usual.
    if (i_nvdimm_workaround)
    {
        FAPI_TRY( mss::ccs::workarounds::nvdimm::execute(l_mcbist, l_program, i_target), "Failed ccs execute %s",
                  mss::c_str(i_target) );
    }
    else
    {
        FAPI_TRY( mss::ccs::execute(l_mcbist, l_program, i_target), "Failed ccs execute %s", mss::c_str(i_target) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace DDR4
} // close namespace mss
