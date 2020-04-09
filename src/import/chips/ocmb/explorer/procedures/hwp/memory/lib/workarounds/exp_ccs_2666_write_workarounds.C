/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_ccs_2666_write_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file exp_ccs_2666_workarounds.H
/// @brief Workarounds for explorer CCS write issue at 2666
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup:  Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#include <lib/shared/exp_defaults.H>
#include <lib/ccs/ccs_traits_explorer.H>
#include <lib/dimm/exp_mrs_traits.H>
#include <fapi2.H>
#include <lib/workarounds/exp_ccs_2666_write_workarounds.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/dimm/exp_rank.H>
#include <lib/ccs/ccs_explorer.H>

namespace mss
{
namespace exp
{
namespace workarounds
{

///
/// @brief Determine if the CCS 2666 write workaround is needed
/// @param[in] i_target port target on which to operate
/// @param[out] o_is_needed true if the workaround needs to be run
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode is_ccs_2666_write_needed(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        bool& o_is_needed)
{
    constexpr uint64_t FREQ_NEEDS_WORKAROUND = 2666;
    constexpr bool NO_RCD = false;

    uint64_t l_freq = 0;
    bool l_has_rcd = false;
    o_is_needed = false;

    FAPI_TRY(mss::attr::get_freq(i_target, l_freq));
    FAPI_TRY(mss::unmask::has_rcd(i_target, l_has_rcd));

    // The workaround is needed if we're at 2666 and do not have an RCD
    o_is_needed = (l_freq == FREQ_NEEDS_WORKAROUND) &&
                  (l_has_rcd == NO_RCD);
    FAPI_DBG("%s freq:%lu, RCD:%s, workaround %s needed",
             mss::c_str(i_target), l_freq, l_has_rcd ? "yes" : "no", o_is_needed ? "is" : "not");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Updates CAS write latency if the workaround is needed
/// @param[in] i_target port target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note This is the first part of the CCS 2666 write workaround
/// The CWL needs to be increased to 18 for 2666 (non RDIMM)
/// This will put a non-zero value in the WRDATA_DLY, allowing for good CCS writes
///
fapi2::ReturnCode update_cwl(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    constexpr uint64_t WORKAROUND_CWL = 18;
    bool l_is_needed = false;

    FAPI_TRY(is_ccs_2666_write_needed(i_target, l_is_needed));

    // If the workaround is not needed, skip it
    if(l_is_needed == false)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Update the CWL to the workaround value
    FAPI_TRY(mss::attr::set_dram_cwl(i_target, WORKAROUND_CWL));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper that adds the MR2 commands
/// @param[in] i_target port target on which to operate
/// @param[out] o_instructions CCS instructions
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note Unit test helper
///
fapi2::ReturnCode updates_mode_registers_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        std::vector<ccs::instruction_t>& o_instructions)
{
    // The PHY puts us into self time refresh mode prior
    // We need to exit self time refresh mode by holding the CKE high
    // The time for this is tXPR = tRFC(min) + 10 ns
    // This is 560ns -> 746 clocks. rounded up to 750 for saftey
    constexpr uint16_t TXPR_SAFE_MARGIN = 750;

    o_instructions.clear();

    o_instructions.push_back(mss::ccs::des_command(TXPR_SAFE_MARGIN));

    for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        fapi2::ReturnCode l_mrs_rc = fapi2::FAPI2_RC_SUCCESS;
        mss::ddr4::mrs02_data<mss::mc_type::EXPLORER> l_data(l_dimm, l_mrs_rc);

        std::vector<mss::rank::info<>> l_ranks;
        FAPI_TRY(mss::rank::ranks_on_dimm(l_dimm, l_ranks));
        FAPI_TRY(l_mrs_rc);

        // Loops through all ranks on this DIMM and adds them to the CCS instructions to execute
        for(const auto& l_rank_info : l_ranks)
        {
            FAPI_TRY(mss::mrs_engine( l_dimm,
                                      l_data,
                                      l_rank_info.get_port_rank(),
                                      mrsTraits<mss::mc_type::EXPLORER>::mrs_tmod(i_target),
                                      o_instructions ));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Updates MR2 to have the proper CWL value if the workaround is needed
/// @param[in] i_target port target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note This is the second part of the CCS 2666 write workaround
/// The CWL needs to be programmed into MR2
/// This cannot be done with the Microchip FW as we do not have a parameter for CWL
///
fapi2::ReturnCode updates_mode_registers(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    bool l_is_needed = false;

    FAPI_TRY(is_ccs_2666_write_needed(i_target, l_is_needed));

    // If the workaround is not needed, skip it
    if(l_is_needed == false)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Update the CWL to the workaround value
    {
        mss::ccs::program l_program;

        // Adds the instructions
        FAPI_TRY(updates_mode_registers_helper(i_target, l_program.iv_instructions));

        // Executes the CCS commands
        FAPI_TRY(mss::ccs::execute(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target),
                                   l_program,
                                   i_target));
    }

fapi_try_exit:
    return fapi2::current_err;
}


} // workarounds
} // exp
} // mss
