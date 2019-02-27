/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/p9a_mss_eff_config.C $ */
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
/// @file p9a_mss_eff_config.C
/// @brief Command and Control for the memory subsystem - populate attributes
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

// fapi2
#include <fapi2.H>
#include <p9a_mss_eff_config.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/spd/ddimm/efd_factory.H>
#include <vpd_access.H>
#include <mss_generic_attribute_getters.H>
#include <lib/eff_config/explorer_attr_engine_traits.H>

///
/// @brief Configure the attributes for each controller
/// @param[in] i_target port target
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9a_mss_eff_config( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target )
{
    // Workaround until DIMM level attrs work
    uint8_t l_ranks[mss::exp::MAX_DIMM_PER_PORT] = {};

    // Get EFD size - should only need to do it once
    const auto l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
    fapi2::MemVpdData_t l_vpd_type(fapi2::EFD);
    fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP> l_vpd_info(l_vpd_type);
    FAPI_TRY( fapi2::getVPD(l_ocmb, l_vpd_info, nullptr) );

    FAPI_TRY( mss::attr::get_num_master_ranks_per_dimm(i_target, l_ranks) );

    for(const auto& dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        uint8_t l_dimm_index = 0;
        uint64_t l_freq = 0;
        FAPI_TRY( mss::attr::get_freq(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(dimm), l_freq) );

        // Quick hack to get the index until DIMM level attrs work
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_REL_POS, dimm, l_dimm_index) );

        for( auto rank = 0; rank < l_ranks[l_dimm_index]; ++rank )
        {
            std::shared_ptr<mss::efd::base_decoder> l_efd_data;

            // Get EFD data
            l_vpd_info.iv_rank = rank;
            l_vpd_info.iv_omi_freq_mhz = l_freq;
            std::vector<uint8_t> l_vpd_raw (l_vpd_info.iv_size, 0);
            FAPI_TRY( fapi2::getVPD(l_ocmb, l_vpd_info, l_vpd_raw.data()) );

            // Instantiate EFD decoder
            FAPI_TRY( mss::efd::factory(l_ocmb, l_vpd_raw, l_vpd_info.iv_rank, l_efd_data) );

            // Set up SI ATTRS
            FAPI_TRY( mss::attr_si_engine<mss::attr_si_engine_fields>::set(l_efd_data) );
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
                FAPI_TRY( mss::attr_eff_engine<mss::attr_eff_engine_fields>::set(l_spd_decoder) );

                // Set up explorer SPD ATTRS
                FAPI_TRY( mss::attr_eff_engine<mss::exp::attr_eff_engine_fields>::set(l_spd_decoder) );
            }
        }
    }// dimm

fapi_try_exit:
    return fapi2::current_err;
}
