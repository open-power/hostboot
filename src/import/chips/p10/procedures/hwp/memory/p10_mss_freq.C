/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_mss_freq.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
// *HWP Level: 3
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
#include <lib/eff_config/p10_factory.H>

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

    // DRAM gen declared outside of loop because it will be reused later
    // This is ok since we prohibit DRAM gen mixing
    uint8_t l_dram_gen = 0;

    // We will first set pre-eff_config attributes
    // Note that we have to go through the MEM_PORT to get to the DIMM targets because of the
    // target hierarchy on P10
    for(const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        for(const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(p))
        {
            const auto l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(d);
            std::vector<uint8_t> l_raw_spd;
            uint8_t l_spd_rev = 0;
            uint8_t l_is_planar = 0;

            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_MRW_IS_PLANAR, l_ocmb, l_is_planar) );
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_SPD_REVISION, p, l_spd_rev) );
            FAPI_TRY( mss::attr::get_dram_gen(d, l_dram_gen) );
            FAPI_TRY(mss::spd::get_raw_data(d, l_is_planar, l_raw_spd));
            {
                std::shared_ptr<mss::spd::base_cnfg_base> l_base_cfg;

                FAPI_TRY(mss::spd::base_module_factory(d, l_spd_rev, l_dram_gen, l_base_cfg));
                FAPI_TRY(l_base_cfg->process_data_init_fields(l_raw_spd));
            }
        }
    }

    // Check plug rules.
    FAPI_TRY( mss::plug_rule::enforce_pre_freq(i_target),
              "Failed enforce_plug_rules for %s", mss::c_str(i_target) );

    // Set frequency attributes
    if (l_dram_gen == fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4)
    {
        FAPI_INF("%s Processing memory frequencies for DDR4", mss::c_str(i_target));
        FAPI_TRY((mss::generate_freq<mss::mc_type::EXPLORER, mss::proc_type::PROC_P10>(i_target)));
    }
    else // We only support DDR4 and DDR5 so DDR5 is the only other option
    {
        FAPI_INF("%s Processing memory frequencies for DDR5", mss::c_str(i_target));
        FAPI_TRY((mss::generate_freq<mss::mc_type::ODYSSEY, mss::proc_type::PROC_P10>(i_target)));
    }

fapi_try_exit:
    return fapi2::current_err;
}
