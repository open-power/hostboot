/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_process_image_status.C $ */
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
/// EKB-Mirror-To: hostboot

///
/// @file exp_process_image_status.C
/// @brief Procedure to run explorer fw_adapter_properties_get in order to gather information about
/// the explorer firmware images (i.e. version, authentication status). This will save some
/// information into attributes as well as perform checks for image failures.
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <exp_process_image_status.H>
#include <mss_generic_attribute_getters.H>
#include <lib/inband/exp_fw_adapter_properties.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>

extern "C"
{

///
/// @brief Run explorer fw_adapter_properties_get
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS if ok
/// @note This procedure must be called before running exp_flash_read_test and mss_draminit
///
    fapi2::ReturnCode exp_process_image_status(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        FAPI_INF("Entering exp_process_image_status(%s)", mss::c_str(i_target));

        uint8_t l_sim = 0;
        bool l_image_a_good = true;
        bool l_image_b_good = true;
        bool l_mfg_thresholds = false;

        FAPI_TRY(mss::attr::get_is_simulation(l_sim));

        if (l_sim)
        {
            FAPI_INF("Skipping exp_process_image_status(%s) due to being in sim mode...",
                     mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Check MNFG THRESHOLDS Policy flag
        FAPI_TRY(mss::check_mfg_flag(fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_THRESHOLDS, l_mfg_thresholds));

        // Print and record Explorer FW version info into attributes
        FAPI_TRY( mss::exp::ib::run_fw_adapter_properties_get(i_target, l_image_a_good, l_image_b_good) );

        // Assert MNFG_SPI_FLASH_AUTHENTICATION_FAIL if fw_adapter_properties says one of the images is bad
        if (!l_image_a_good || !l_image_b_good)
        {
            // Note: there is no way we could see both images bad here, because then we would not have booted this far
            const uint8_t l_image_num = !l_image_a_good ? 0 : 1;

            if (l_mfg_thresholds)
            {
                // In MFG test, this fail should call out and deconfigure the DIMM, and fail the procedure
                FAPI_ASSERT(false,
                            fapi2::EXP_SPI_FLASH_AUTH_FAIL_MFG().
                            set_OCMB_TARGET(i_target).
                            set_IMAGE(l_image_num).
                            set_EXP_ACTIVE_LOG_SIZE(4096),
                            "%s Explorer SPI flash authentication failed for image %s in MFG test",
                            mss::c_str(i_target), (!l_image_a_good ? "A" : "B"));
            }
            else
            {
                // In normal IPL, this fail should produce a recovered log and pass the procedure
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::EXP_SPI_FLASH_AUTH_FAIL(fapi2::FAPI2_ERRL_SEV_RECOVERED).
                                   set_OCMB_TARGET(i_target).
                                   set_IMAGE(l_image_num).
                                   set_EXP_ACTIVE_LOG_SIZE(4096),
                                   "%s Explorer SPI flash authentication failed for image %s",
                                   mss::c_str(i_target), (!l_image_a_good ? "A" : "B"));

                // FAPI_ASSERT_NOEXIT already logs the error, so set current_err back to success so we pass the procedure
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }

    fapi_try_exit:
        FAPI_INF("Exiting exp_process_image_status(%s) with return code : 0x%08x...",
                 mss::c_str(i_target), (uint64_t) fapi2::current_err);
        return fapi2::current_err;
    }


} //extern "C"
