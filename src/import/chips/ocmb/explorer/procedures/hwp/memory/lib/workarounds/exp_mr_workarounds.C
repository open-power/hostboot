/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_mr_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file exp_mr_workarounds.H
/// @brief MR related workarounds for explorer
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <lib/shared/exp_defaults.H>
#include <lib/ccs/ccs_traits_explorer.H>
#include <lib/dimm/exp_mrs_traits.H>
#include <lib/dimm/exp_kind.H>
#include <fapi2.H>
#include <lib/workarounds/exp_ccs_2666_write_workarounds.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_explorer_attribute_setters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
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
/// @brief Updates LPASR setting depending on MRW refresh rate attribute
/// @param[in] i_target port target on which to operate
/// @param[out] o_update_needed set to true if MR2 needs to be updated
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note Unit test helper
///
fapi2::ReturnCode update_lpasr(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                               bool& o_update_needed)
{

    uint8_t l_lpasr_from_exp_resp = 0;
    uint8_t l_refresh_rate_request = 0;
    uint8_t l_lpasr = 0;

    o_update_needed = false;

    FAPI_TRY(mss::attr::get_exp_resp_dram_lpasr(i_target, l_lpasr_from_exp_resp));
    FAPI_TRY(mss::attr::get_mrw_refresh_rate_request(l_refresh_rate_request));

    switch(l_refresh_rate_request)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_DOUBLE:
        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_DOUBLE_10_PERCENT_FASTER:
            l_lpasr = fapi2::ENUM_ATTR_MSS_EXP_RESP_DRAM_LPASR_MANUAL_EXTENDED;
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_SINGLE:
        case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_SINGLE_10_PERCENT_FASTER:
            l_lpasr = fapi2::ENUM_ATTR_MSS_EXP_RESP_DRAM_LPASR_MANUAL_NORMAL;
            break;

        default:
            // Will catch incorrect MRW value set
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_REFRESH_RATE_REQUEST()
                        .set_PORT_TARGET(i_target)
                        .set_REFRESH_RATE_REQUEST(l_refresh_rate_request),
                        "Incorrect refresh request rate received: %d for %s",
                        l_refresh_rate_request, mss::c_str(i_target));
            break;
    }

    if (l_lpasr != l_lpasr_from_exp_resp)
    {
        o_update_needed = true;
        FAPI_TRY(mss::attr::set_exp_resp_dram_lpasr(i_target, l_lpasr));
    }

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
    bool l_2666_update_is_needed = false;
    bool l_lpasr_update_is_needed = false;

    FAPI_TRY(is_ccs_2666_write_needed(i_target, l_2666_update_is_needed));
    FAPI_TRY(update_lpasr(i_target, l_lpasr_update_is_needed));

    // If the workarounds are not needed, skip MRS write
    if ((l_2666_update_is_needed == false) && (l_lpasr_update_is_needed == false))
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Update the CWL and/or LPASR to the workaround value
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
