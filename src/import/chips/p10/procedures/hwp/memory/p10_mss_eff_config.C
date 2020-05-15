/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_mss_eff_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p10_mss_eff_config.H>
#include <lib/shared/exp_defaults.H>
#include <lib/dimm/exp_rank.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/spd/ddimm/efd_factory.H>
#include <vpd_access.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/data_engine/attr_engine_traits.H>
#include <lib/eff_config/explorer_attr_engine_traits.H>
#include <lib/eff_config/pmic_attr_engine_traits.H>
#include <lib/eff_config/explorer_efd_processing.H>
#include <lib/eff_config/pmic_efd_processing.H>
#include <lib/freq/p10_freq_traits.H>
#include <lib/freq/p10_sync.H>
#include <generic/memory/mss_git_data_helper.H>
#include <lib/workarounds/exp_ccs_2666_write_workarounds.H>
#include <lib/plug_rules/p10_plug_rules.H>

///
/// @brief Configure the attributes for each controller
/// @param[in] i_target port target
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p10_mss_eff_config( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target )
{
    using mss::DEFAULT_MC_TYPE;

    mss::display_git_commit_info("p10_mss_eff_config");

    for(const auto& dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        uint64_t l_freq = 0;
        uint32_t l_omi_freq = 0;
        FAPI_TRY( mss::attr::get_freq(i_target, l_freq) );
        FAPI_TRY( mss::convert_ddr_freq_to_omi_freq(i_target, l_freq, l_omi_freq));

        // Get ranks via rank API
        std::vector<mss::rank::info<>> l_ranks;
        mss::rank::ranks_on_dimm(dimm, l_ranks);

        for (const auto& l_rank : l_ranks)
        {
            uint8_t l_spd_rev = 0;
            std::shared_ptr<mss::efd::base_decoder> l_efd_data;

            // Get EFD size
            const auto l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
            fapi2::MemVpdData_t l_vpd_type(fapi2::MemVpdData::EFD);
            fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP> l_vpd_info(l_vpd_type);
            l_vpd_info.iv_rank = l_rank.get_dimm_rank();
            l_vpd_info.iv_omi_freq_mhz = l_omi_freq;
            FAPI_TRY( fapi2::getVPD(l_ocmb, l_vpd_info, nullptr), "failed getting VPD size from getVPD" );

            // Get EFD data
            std::vector<uint8_t> l_vpd_raw (l_vpd_info.iv_size, 0);
            FAPI_TRY( fapi2::getVPD(l_ocmb, l_vpd_info, l_vpd_raw.data()) );

            // Instantiate EFD decoder
            FAPI_TRY( mss::attr::get_spd_revision(i_target, l_spd_rev) );
            FAPI_TRY( mss::efd::factory(l_ocmb, l_spd_rev, l_vpd_raw, l_vpd_info.iv_rank, l_efd_data) );

            // Set up SI ATTRS
            FAPI_TRY( (mss::gen::attr_engine<mss::proc_type::PROC_P10, mss::attr_si_engine_fields>::set(l_efd_data)) );

            // Explorer EFD
            FAPI_TRY( mss::exp::efd::process(dimm, l_efd_data));

            // PMIC EFD fields do not change per dimm. These attributes and processes will ocurr at the OCMB level,
            // and we will just choose the fields from DIMM 0 to use as the efd_data
            if (l_rank.get_dimm_rank() == 0)
            {
                // PMIC EFD
                FAPI_TRY(mss::pmic::efd::process(l_ocmb, l_efd_data));
            }
        }

        {
            std::vector<uint8_t> l_raw_spd;
            FAPI_TRY(mss::spd::get_raw_data(dimm, l_raw_spd));
            {
                // Gets the SPD facade
                fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);
                mss::spd::facade l_spd_decoder(dimm, l_raw_spd, l_rc);

                // Checks that the facade was setup correctly
                FAPI_TRY( l_rc, "Failed to initialize SPD facade for %s", mss::spd::c_str(dimm) );

                // Set up generic SPD ATTRS
                FAPI_TRY( (mss::gen::attr_engine<mss::proc_type::PROC_P10, mss::attr_eff_engine_fields>::set(l_spd_decoder)) );

                // Set up explorer SPD ATTRS
                FAPI_TRY( (mss::gen::attr_engine<mss::proc_type::PROC_P10, mss::exp::attr_eff_engine_fields>::set(l_spd_decoder)) );

                // Set up pmic SPD ATTRS
                FAPI_TRY( (mss::gen::attr_engine<mss::proc_type::PROC_P10, mss::pmic::attr_eff_engine_fields>::set(l_spd_decoder)) );
            }
        }

        // Set up derived ATTRS
        FAPI_TRY( (mss::gen::attr_engine<mss::proc_type::PROC_P10, mss::attr_engine_derived_fields>::set(dimm)) );

    }// dimm

    // Enforces plug rules
    FAPI_TRY(mss::plug_rule::enforce_post_eff_config(i_target));

    // Conducts the workaround for CCS writes at 2666
    FAPI_TRY(mss::exp::workarounds::update_cwl(i_target));

fapi_try_exit:
    return fapi2::current_err;
}
