/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_deploy_row_repairs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
/// @file ody_deploy_row_repairs.C
/// @brief API for row repair HWP
///
// *HWP HWP Owner: Sneha Kadam <Sneha.Kadam1@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <ody_deploy_row_repairs.H>
#include <fapi2.H>
#include <lib/ecc/ecc_traits_odyssey.H>
#include <lib/shared/ody_consts.H>
#include <lib/ccs/ody_row_repair.H>
#ifndef __PPE__
    #include <generic/memory/lib/dimm/mrs_load.H>
#endif
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>

///
/// @brief Indicating runtime execution or not
///
enum runtime_exec
{
    MAINT_REPAIR = false,
    RUNTIME_REPAIR = true,
};

extern "C"
{

    ///
    /// @brief Deploy SPPR row repair
    /// @param[in] i_target_ocmb ocmb target
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode ody_deploy_row_repairs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_ocmb)
    {
        // Consts and vars
        bool l_test_all_spares = false;
        bool l_no_rbs = false;

        // This table contains a row repair entry for each DIMM/mrank combination
        mss::ody::row_repair::REPAIR_MAP l_row_repairs;

        // Check MNFG flags
        FAPI_TRY(mss::check_mfg_flag(fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_TEST_ALL_SPARE_DRAM_ROWS, l_test_all_spares));
        FAPI_TRY(mss::check_mfg_flag(fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_NO_RBS, l_no_rbs));

        // If mfg flag is set to test all spare rows, we need to do row repair on all dimm/ranks/DRAMs
        if (l_test_all_spares)
        {
            return mss::ody::row_repair::activate_all_spare_rows(i_target_ocmb);
        }

        FAPI_TRY( mss::ody::row_repair::map_repairs_per_dimm(i_target_ocmb, l_row_repairs),
                  "Failed to map repairs on dimms for " GENTARGTIDFORMAT,
                  GENTARGTID(i_target_ocmb));

        // If DRAM repairs are disabled (mfg flag), we're done (but need to callout DIMM if it has row repair data)
        if (l_no_rbs)
        {
            FAPI_INF_NO_SBE( GENTARGTIDFORMAT " DRAM repairs are disabled, so skipping row repair deployment",
                             GENTARGTID(i_target_ocmb));

            // Iterate through DRAM repairs structure
            for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target_ocmb))
            {
                uint8_t l_port_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>
                                     (mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm));

                // Loops thru repairs
                for (const auto& l_repair : l_row_repairs[l_port_pos])
                {
                    // If we have a valid repair, call out this DIMM
                    FAPI_TRY( mss::ody::row_repair::log_repairs_disabled_errors(l_dimm, l_repair) );
                }
            }

            return fapi2::FAPI2_RC_SUCCESS;
        }

        FAPI_TRY( mss::ody::row_repair::deploy_mapped_repairs(i_target_ocmb, l_row_repairs, MAINT_REPAIR),
                  "Failed to deploy maint repairs from repair map for " GENTARGTIDFORMAT,  GENTARGTID(i_target_ocmb) );

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Deploy SPPR row repair at runtime
    /// @param[in] i_target_ocmb ocmb target
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode ody_deploy_dynamic_row_repairs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_ocmb)
    {
        // Consts and vars
        bool l_no_rbs = false;

        // This table contains a row repair entry for each DIMM/mrank combination
        mss::ody::row_repair::REPAIR_MAP l_row_repairs;

        // Check MNFG flags
        FAPI_TRY(mss::check_mfg_flag(fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_NO_RBS, l_no_rbs));

        // Map repairs to dimm
        FAPI_TRY( mss::ody::row_repair::map_repairs_per_dimm(i_target_ocmb, l_row_repairs) );

        // If DRAM repairs are disabled (mfg flag), we're done (but need to callout DIMM if it has row repair data)
        if (l_no_rbs)
        {
            FAPI_INF_NO_SBE( GENTARGTIDFORMAT" DRAM repairs are disabled, so skipping row repair deployment",
                             GENTARGTID(i_target_ocmb));

            // Iterate through DRAM repairs structure
            for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target_ocmb))
            {
                uint8_t l_port_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>
                                     (mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm));

                // Loops thru repairs
                for (const auto& l_repair : l_row_repairs[l_port_pos])
                {
                    // If we have a valid repair, call out this DIMM
                    FAPI_TRY( mss::ody::row_repair::log_repairs_disabled_errors(l_dimm, l_repair) );
                }
            }

            return fapi2::FAPI2_RC_SUCCESS;
        }

        FAPI_TRY( mss::ody::row_repair::deploy_mapped_repairs(i_target_ocmb, l_row_repairs, RUNTIME_REPAIR),
                  "Failed to deploy repairs from repair map for " GENTARGTIDFORMAT, GENTARGTID(i_target_ocmb));

    fapi_try_exit:
        return fapi2::current_err;
    }

}
