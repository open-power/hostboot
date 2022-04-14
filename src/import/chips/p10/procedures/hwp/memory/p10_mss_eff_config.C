/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_mss_eff_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file p10_mss_eff_config.C
/// @brief Command and Control for the memory subsystem - populate attributes
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p10_mss_eff_config.H>
#include <lib/ecc/ecc_traits_explorer.H>
#include <lib/dimm/exp_rank.H>
#include <lib/eff_config/p10_spd_utils.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <generic/memory/lib/utils/find.H>
#include <vpd_access.H>
#include <mss_generic_attribute_getters.H>

#include <lib/freq/p10_freq_traits.H>
#include <lib/freq/p10_sync.H>
#include <generic/memory/mss_git_data_helper.H>
#include <lib/workarounds/exp_ccs_2666_write_workarounds.H>
#include <lib/plug_rules/p10_plug_rules.H>

#include <lib/eff_config/p10_factory.H>
#include <lib/eff_config/p10_base_engine.H>
#include <lib/eff_config/p10_ddimm_engine.H>
#include <lib/eff_config/p10_ddimm_efd_engine.H>
///
/// @brief Configure the attributes for each controller
/// @param[in] i_target port target
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p10_mss_eff_config( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target )
{
    mss::display_git_commit_info("p10_mss_eff_config");

    uint8_t l_spd_rev = 0;
    uint8_t l_is_planar = 0;
    const auto l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    FAPI_TRY( mss::attr::get_spd_revision(i_target, l_spd_rev) );
    FAPI_TRY( mss::attr::get_mem_mrw_is_planar(l_ocmb, l_is_planar) );

    for(const auto& dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        uint8_t l_dram_gen = 0;
        uint8_t l_dimm_type = 0;
        std::vector<uint8_t> l_raw_spd;

        FAPI_TRY( mss::attr::get_dram_gen(dimm, l_dram_gen) );
        FAPI_TRY( mss::attr::get_dimm_type(dimm, l_dimm_type));

        // We run the base module + the DDIMM module first as our rank API needs to know if we are in quad encoded CS mode or not
        {
            FAPI_TRY(mss::spd::get_raw_data(dimm, l_is_planar, l_raw_spd));

            {
                // Create the module decoder objects
                std::shared_ptr<mss::spd::base_cnfg_base> l_base_cfg;
                std::shared_ptr<mss::spd::module_specific_base> l_ddimm_module;

                FAPI_TRY(mss::spd::base_module_factory(dimm, l_spd_rev, l_dram_gen, l_base_cfg));
                FAPI_TRY(mss::spd::module_specific_factory(dimm, l_spd_rev, l_dram_gen, l_dimm_type, l_ddimm_module));

                FAPI_TRY(l_base_cfg->process(l_raw_spd));
                FAPI_TRY(l_ddimm_module->process(l_raw_spd));
                FAPI_TRY(l_base_cfg->process_derived(l_raw_spd));
            }
        }
    }// dimm

    for(const auto& dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        std::vector<uint8_t> l_raw_spd;
        uint64_t l_freq = 0;
        uint32_t l_omi_freq = 0;
        uint8_t l_dram_gen = 0;
        std::vector<mss::rank::info<mss::mc_type::EXPLORER>> l_rank_infos;

        FAPI_TRY( mss::attr::get_freq(i_target, l_freq) );
        FAPI_TRY( mss::convert_ddr_freq_to_omi_freq(i_target, l_freq, l_omi_freq));
        FAPI_TRY( mss::attr::get_dram_gen(dimm, l_dram_gen) );

        FAPI_TRY(mss::spd::get_raw_data(dimm, l_is_planar, l_raw_spd));

        // Make sure to run ranks_on_dimm AFTER the base and DDIMM module data has been processed!
        // This is so we handle the decoding of the ranks properly
        FAPI_TRY(mss::rank::ranks_on_dimm(dimm, l_rank_infos));

        for (const auto& l_rank_info : l_rank_infos)
        {
            std::shared_ptr<mss::efd::ddimm_efd_base> l_ddimm_efd;

            // Get EFD size
            fapi2::MemVpdData_t l_vpd_type(fapi2::MemVpdData::EFD);
            fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP> l_vpd_info(l_vpd_type);

            // Our EFD is stored in terms of our PHY ranks (and DIMM config for planar)
            l_vpd_info.iv_rank = l_rank_info.get_phy_rank();
            l_vpd_info.iv_omi_freq_mhz = l_omi_freq;

            // Add planar EFD lookup info if we need it
            FAPI_TRY(mss::spd::ddr4::add_planar_efd_info(dimm, l_is_planar, l_vpd_info));

            FAPI_TRY( fapi2::getVPD(l_ocmb, l_vpd_info, nullptr), "failed getting VPD size from getVPD" );

            // Get EFD data
            std::vector<uint8_t> l_vpd_raw (l_vpd_info.iv_size, 0);
            FAPI_TRY( fapi2::getVPD(l_ocmb, l_vpd_info, l_vpd_raw.data()) );

            // Instantiate EFD engine
            {
                // We pass in our rank information class - we need to know both the PHY perspective and IBM perspective ranks
                // The EFD data is stored in terms of the PHY perspective
                // The attributes use the IBM perspective, which aligns to the DIMM rank
                // Knowing both allows us to decode from the SPD and encode the data for the attributes
                // The encode/decode is in accordance with fixes for JIRA355
                FAPI_TRY(mss::efd::factory(dimm, l_spd_rev, l_dram_gen, l_is_planar, l_rank_info, l_ddimm_efd));
                FAPI_TRY(l_ddimm_efd->process(l_vpd_raw));
                FAPI_TRY(l_ddimm_efd->process_overrides(l_raw_spd));
            }
        }
    }// dimm

    // Enforces plug rules
    FAPI_TRY(mss::plug_rule::enforce_post_eff_config(i_target));

    // Conducts the workaround for CCS writes at 2666
    FAPI_TRY(mss::exp::workarounds::update_cwl(i_target));

fapi_try_exit:
    return fapi2::current_err;
}
