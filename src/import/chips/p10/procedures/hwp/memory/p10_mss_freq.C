/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_mss_freq.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_mss_freq.C
/// @brief Calculate and save off DIMM frequencies
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

// fapi2
#include <fapi2.H>

// mss lib
#include <p10_mss_freq.H>

#include <lib/freq/p10_freq_traits.H>
#include <lib/eff_config/p10_base_engine.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/freq/gen_mss_freq.H>
#include <generic/memory/mss_git_data_helper.H>
#include <lib/plug_rules/p10_plug_rules.H>

///
/// @brief Calculate and save off DIMM frequencies
/// @param[in] i_target port target
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p10_mss_freq( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target )
{
    mss::display_git_commit_info("p10_mss_freq");

    // If there are no DIMM, we can just get out.
    if (mss::count_dimm(mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target)) == 0)
    {
        FAPI_INF("Seeing no DIMM on %s, no freq to set", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // We will first set pre-eff_config attributes
    // Note that we have to go through the MEM_PORT to get to the DIMM targets because of the
    // target hierarchy on P10
    for(const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        for(const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(p))
        {
            std::vector<uint8_t> l_raw_spd;
            FAPI_TRY(mss::spd::get_raw_data(d, l_raw_spd));
            {
                std::shared_ptr<mss::spd::base_cnfg_base> l_base_cfg = std::make_shared<mss::spd::base_0_4>(d);
                FAPI_TRY(l_base_cfg->process_data_init_fields(l_raw_spd));
            }
        }
    }

    // Check plug rules.
    FAPI_TRY( mss::plug_rule::enforce_pre_freq(i_target),
              "Failed enforce_plug_rules for %s", mss::c_str(i_target) );

    // Set frequency attributes
    FAPI_TRY(mss::generate_freq<mss::proc_type::PROC_P10>(i_target));

fapi_try_exit:
    return fapi2::current_err;
}
