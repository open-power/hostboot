/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_deploy_row_repairs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
/// @file exp_deploy_row_repairs.C
/// @brief API for row repair HWP
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <exp_deploy_row_repairs.H>
#include <fapi2.H>
#include <lib/ecc/ecc_traits_explorer.H>
#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_mrs_traits.H>
#include <lib/ccs/exp_row_repair.H>

#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
#include <mss_generic_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>
#include <map>

extern "C"
{

    ///
    /// @brief Deploy SPPR row repair
    /// @param[in] i_target_ocmb ocmb target
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode exp_deploy_row_repairs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_ocmb)
    {
        // Consts and vars
        bool l_test_all_spares = false;
        bool l_no_rbs = false;

        // This table contains a row repair entry for each DIMM/mrank combination
        std::map< fapi2::Target<fapi2::TARGET_TYPE_DIMM>,
            std::vector<mss::row_repair::repair_entry<mss::mc_type::EXPLORER>> > l_row_repairs;

        // Check MNFG flags
        FAPI_TRY(mss::check_mfg_flag(fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_TEST_ALL_SPARE_DRAM_ROWS, l_test_all_spares));
        FAPI_TRY(mss::check_mfg_flag(fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_NO_RBS, l_no_rbs));

        // If mfg flag is set to test all spare rows, we need to do row repair on all dimm/ranks/DRAMs
        if (l_test_all_spares)
        {
            return mss::exp::row_repair::activate_all_spare_rows(i_target_ocmb);
        }

        FAPI_TRY( mss::exp::row_repair::map_repairs_per_dimm(i_target_ocmb, l_row_repairs),
                  "Failed to map repairs on dimms for %s",
                  mss::c_str(i_target_ocmb) );

        // If DRAM repairs are disabled (mfg flag), we're done (but need to callout DIMM if it has row repair data)
        if (l_no_rbs)
        {
            FAPI_INF("%s DRAM repairs are disabled, so skipping row repair deployment", mss::c_str(i_target_ocmb));

            for (const auto l_pair : l_row_repairs)
            {
                const auto& l_dimm = l_pair.first;
                const auto& l_repairs = l_pair.second;

                // Loops through repairs
                for (const auto& l_repair : l_repairs)
                {
                    // If we have a valid repair, call out this DIMM
                    FAPI_TRY( mss::exp::row_repair::log_repairs_disabled_errors(l_dimm, l_repair) );
                }
            }

            return fapi2::FAPI2_RC_SUCCESS;
        }

        FAPI_TRY( mss::exp::row_repair::deploy_mapped_repairs(l_row_repairs, MAINT_REPAIR),
                  "Failed to deploy maint repairs from repair map for %s", mss::c_str(i_target_ocmb) );

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Deploy SPPR row repair at runtime
    /// @param[in] i_target_ocmb ocmb target
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode exp_deploy_dynamic_row_repairs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_ocmb)
    {
        // Consts and vars
        bool l_no_rbs = false;

        // This table contains a row repair entry for each DIMM/mrank combination
        std::map< fapi2::Target<fapi2::TARGET_TYPE_DIMM>,
            std::vector<mss::row_repair::repair_entry<mss::mc_type::EXPLORER>> > l_row_repairs;

        // Check MNFG flags
        FAPI_TRY(mss::check_mfg_flag(fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_NO_RBS, l_no_rbs));

        // Map repairs to dimm
        FAPI_TRY( mss::exp::row_repair::map_repairs_per_dimm(i_target_ocmb, l_row_repairs) );

        // If DRAM repairs are disabled (mfg flag), we're done (but need to callout DIMM if it has row repair data)
        if (l_no_rbs)
        {
            FAPI_INF("%s DRAM repairs are disabled, so skipping row repair deployment", mss::c_str(i_target_ocmb));

            for (const auto& l_pair : l_row_repairs)
            {
                const auto& l_dimm = l_pair.first;
                const auto& l_repairs = l_pair.second;

                // Loops through repairs
                for (const auto& l_repair : l_repairs)
                {
                    // If we have a valid repair, call out this DIMM
                    FAPI_TRY( mss::exp::row_repair::log_repairs_disabled_errors(l_dimm, l_repair) );
                }
            }

            return fapi2::FAPI2_RC_SUCCESS;
        }

        FAPI_TRY( mss::exp::row_repair::deploy_mapped_repairs(l_row_repairs, RUNTIME_REPAIR),
                  "Failed to deploy repairs from repair map for %s", mss::c_str(i_target_ocmb));

    fapi_try_exit:
        return fapi2::current_err;
    }

}
