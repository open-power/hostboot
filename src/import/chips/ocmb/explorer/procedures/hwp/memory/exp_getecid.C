/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_getecid.C $ */
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

/// @file exp_getecid.C
/// @brief Gets ECID from explorer fuse registers
///
/// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include <fapi2.H>
#include <exp_getecid.H>
#include <exp_getecid_utils.H>
#include <lib/shared/exp_consts.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <mss_explorer_attribute_setters.H>
#include <generic/memory/mss_git_data_helper.H>
#include <lib/plug_rules/exp_plug_rules.H>
#include <lib/i2c/exp_i2c.H>

extern "C"
{
    ///
    /// @brief getecid procedure for explorer chip
    /// @param[in] i_target Explorer OCMB chip
    /// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code.
    /// @note Sets ocmb_ecid, enterprise, half-dimm mode attributes. exp_omi_setup configures the chip with these attributes
    ///
    fapi2::ReturnCode exp_getecid(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        mss::display_git_commit_info("exp_getecid");

        std::vector<uint8_t> l_fw_status_data;

        // Save off the FW API version into our attribute
        FAPI_TRY(mss::exp::i2c::get_fw_status(i_target, l_fw_status_data));
        FAPI_TRY(mss::exp::i2c::save_fw_api_version(i_target, l_fw_status_data));

        {
            bool l_enterprise_fuse = false;
            bool l_enterprise_final = false;

            FAPI_TRY(mss::exp::ecid::get_enterprise_from_fuse(i_target, l_enterprise_fuse),
                     "exp_getecid: getting enterprise from fuse failed on %s",
                     mss::c_str(i_target));

            // Calculate the global enterprise mode state while verifying plug rules with policy and override attributes
            FAPI_TRY(mss::exp::plug_rule::enterprise_mode(i_target, l_enterprise_fuse, l_enterprise_final));

            // Set global enterprise mode attribute
            FAPI_TRY(mss::attr::set_ocmb_enterprise_mode(i_target, l_enterprise_final),
                     "exp_getecid: Could not set ATTR_MSS_OCMB_ENTERPRISE_MODE");
        }

        //
        // Populate OCMB_ECID attribute with:
        // EFUSE_IMAGE_OUT[261:64] – Serial number  (Wafer ID, number and XY coordinates)
        // EFUSE_IMAGE_OUT[263:262] – PSRO
        // Each register in the FUSE is 32 bits in size, but only the lower 16 bits are used, Here, we piece together
        // each set of lower 16 bits and insert these into the ECID register
        //
        // TK - Once ATTR_ECID is made large enough, we probably will not need ATTR_OCMB_ECID
        // We can remove the call to it below and remove the attribute itself.
        //
        {
            // ECID obtained from register contents
            uint16_t l_ecid[mss::exp::ecid_consts::FUSE_ARRAY_SIZE] = {0};

            FAPI_TRY(mss::exp::ecid::read_from_fuse(i_target, l_ecid),
                     "exp_getecid: Could not read ecid from FUSE on %s", mss::c_str(i_target));

            for (uint8_t l_ecid_idx = 0; l_ecid_idx < mss::exp::ecid_consts::FUSE_ARRAY_SIZE; ++l_ecid_idx)
            {
                FAPI_INF("%s ECID[%u]: 0x%04X", mss::c_str(i_target), l_ecid_idx, l_ecid[l_ecid_idx]);
            }

            // TK - Remove once ATTR_ECID is made large enough
            FAPI_TRY(mss::attr::set_ocmb_ecid(i_target, l_ecid),
                     "exp_getecid: Could not set ATTR_MSS_OCMB_ECID on %s", mss::c_str(i_target));

            FAPI_TRY(mss::exp::ecid::set_attr(i_target, l_ecid),
                     "exp_getecid: Could not set ATTR_ECID on %s", mss::c_str(i_target));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern "C"
