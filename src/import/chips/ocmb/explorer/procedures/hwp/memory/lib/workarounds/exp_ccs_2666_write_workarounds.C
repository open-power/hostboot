/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_ccs_2666_write_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
// *HWP HWP Backup:  Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <lib/ccs/ccs_traits_explorer.H>
#include <lib/ecc/ecc_traits_explorer.H>
#include <lib/dimm/exp_mrs_traits.H>
#include <lib/dimm/exp_kind.H>
#include <fapi2.H>
#include <lib/workarounds/exp_ccs_2666_write_workarounds.H>
#include <lib/workarounds/exp_mr_workarounds.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
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
    constexpr uint64_t FREQ_NEEDS_WORKAROUND = mss::DIMM_SPEED_2666;
    constexpr bool NO_RCD = false;

    uint64_t l_freq = 0;
    uint8_t l_height = 0;
    bool l_has_rcd = false;
    o_is_needed = false;
    const auto l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    FAPI_TRY(mss::attr::get_freq(i_target, l_freq));
    FAPI_TRY(mss::dimm::has_rcd<mss::mc_type::EXPLORER>(i_target, l_has_rcd));
    FAPI_TRY(mss::attr::get_dram_module_height(l_ocmb, l_height));
    FAPI_DBG("%s Ran has_rcd attribute returned as %d", mss::c_str(i_target), l_has_rcd);

    // The workaround is needed if we're at 2666 and do not have an RCD parity delay
    // 2U and 4U DDIMM's do not run in RCD parity mode but have an RCD so we do not have a delay from parity
    {
        bool l_no_rcd_delay = l_has_rcd == NO_RCD  || (l_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U)
                              || (l_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U);
        o_is_needed = (l_freq == FREQ_NEEDS_WORKAROUND) && (l_no_rcd_delay);
        FAPI_DBG("%s freq:%lu, RCD:%s, workaround %s needed",
                 mss::c_str(i_target), l_freq, l_no_rcd_delay ? "yes" : "no", o_is_needed ? "is" : "not");
    }

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

} // workarounds
} // exp
} // mss
