/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_init.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file p10_omi_init.C
/// @brief Finalize the OMI
///
// *HWP HW Maintainer: Benjamin Gass <bgass@us.ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by: HB

#include <p10_omi_init.H>
#include <p10_omi_init_scom.H>
#include <p10_scom_mcc_4.H>
#include <p10_scom_mcc_d.H>
#include <lib/fir/p10_fir.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>
#include <lib/inband/exp_fw_adapter_properties.H>

///
/// @brief Run initfile to enable templates and set pacing.
/// @param[in] i_target MCC target
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_init_scominit(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    fapi2::ReturnCode l_rc;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_EXEC_HWP(l_rc, p10_omi_init_scom, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from p10.omi_init.scom.initfile");
        fapi2::current_err = l_rc;
    }

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Check and enable supported templates
/// @param[in] i_target MCC target
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_init_enable_templates(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    fapi2::ATTR_PROC_ENABLE_DL_TMPL_1_Type l_enable_tmpl_1;
    fapi2::ATTR_PROC_ENABLE_DL_TMPL_4_Type l_enable_tmpl_4;
    fapi2::ATTR_PROC_ENABLE_DL_TMPL_7_Type l_enable_tmpl_7;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_1,
                           i_target,
                           l_enable_tmpl_1),
             "Error from FAPI_ATTR_GET (ATTR_PROC_ENABLE_DL_TMPL_1)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_4,
                           i_target,
                           l_enable_tmpl_4),
             "Error from FAPI_ATTR_GET (ATTR_PROC_ENABLE_DL_TMPL_4)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_7,
                           i_target,
                           l_enable_tmpl_7),
             "Error from FAPI_ATTR_GET (ATTR_PROC_ENABLE_DL_TMPL_7)");

    FAPI_ASSERT(l_enable_tmpl_1 != 0,
                fapi2::P10_DOWNSTREAM_TMPL1_REQUIRED_ERR()
                .set_TARGET(i_target),
                "Downstream template 1 is required.");

    FAPI_ASSERT(l_enable_tmpl_4 != 0 || l_enable_tmpl_7 != 0,
                fapi2::P10_DOWNSTREAM_TMPL4OR7_REQUIRED_ERR()
                .set_TARGET(i_target),
                "Downstream template 4 and/or 7 is required.");

    //Turn off temp0_only
    FAPI_TRY(scomt::mcc::GET_DSTL_DSTLCFG(i_target, l_data));
    scomt::mcc::CLEAR_DSTL_DSTLCFG_TMPL0_ONLY(l_data);
    FAPI_TRY(scomt::mcc::PUT_DSTL_DSTLCFG(i_target, l_data));

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Enable ibm buffer chip low latency mode
///
/// @param[in] i_target                 p10 channel to work on
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_init_enable_lol(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    fapi2::buffer<uint64_t> l_data;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_OMI>> l_omi_targets;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_omi_pos;

    l_omi_targets = i_target.getChildren<fapi2::TARGET_TYPE_OMI>();

    FAPI_TRY(scomt::mcc::GET_USTL_USTLCFG(i_target, l_data));

    for (const auto l_omi_target : l_omi_targets)
    {
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                l_omi_target,
                                l_omi_pos));

        // Set for proper channel
        if ((l_omi_pos % 2) == 0)
        {
            scomt::mcc::SET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE(l_data);
        }
        else
        {
            scomt::mcc::SET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE(l_data);
        }
    }

    FAPI_TRY(scomt::mcc::PUT_USTL_USTLCFG(i_target, l_data));

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

// Putting unmask function in mss::unmask for consistency with p9/EXPL/etc.
namespace mss
{
namespace unmask
{

///
/// @brief Initialize Axone DSTLFIR mask bits after p9a omi init
/// @param[in] i_target MCC target to find targets to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
fapi2::ReturnCode after_p10_omi_init(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    // Unmask MC_OMI_FIR per FIR XML spec
    const auto& l_mc = mss::find_target<fapi2::TARGET_TYPE_MC>(i_target);
    FAPI_TRY(after_p10_omi_init_omi_fir_helper(l_mc));

    // Unmask MCC DSTLFIR per FIR XML spec
    FAPI_TRY(after_p10_omi_init_dstlfir_helper(i_target));

    // Unmask MCC USTLFIR per FIR XML spec
    FAPI_TRY(after_p10_omi_init_ustlfir_helper(i_target));

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

} // end unmask ns
} // end mss ns

///
/// @brief Finalize the OMI
/// @param[in] i_target MCC target
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_init(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    uint8_t l_enable_fir_unmasking = 0;
    uint8_t l_sim = 0;

    FAPI_TRY(p10_omi_init_scominit(i_target));
    FAPI_TRY(p10_omi_init_enable_templates(i_target));
    FAPI_TRY(p10_omi_init_enable_lol(i_target));
    FAPI_TRY(mss::attr::get_is_simulation(l_sim));

    // Perform fir unmasking if attribute is set to enabled, default disabled
    FAPI_TRY(mss::attr::get_enable_fir_unmasking(l_enable_fir_unmasking));

    if (l_enable_fir_unmasking == fapi2::ENUM_ATTR_ENABLE_FIR_UNMASKING_ENABLED)
    {
        FAPI_TRY(mss::unmask::after_p10_omi_init(i_target));
    }

#ifdef __HOSTBOOT_MODULE

    // NOTE: We're calling run_fw_adapter_properties_get here so we get the Explorer FW version into attributes
    // for use in the FFDC in the update_omi_firmware step. We cannot run this in Cronus here because we haven't yet
    // transitioned Explorer access to mmio/inband mode so our endianness attributes are not set correctly.
    if (!l_sim)
    {
        for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
        {
            for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
            {
                bool l_image_a_good = true;
                bool l_image_b_good = true;
                bool l_mfg_thresholds = false;

                // Check MNFG THRESHOLDS Policy flag
                FAPI_TRY(mss::check_mfg_flag(fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_THRESHOLDS, l_mfg_thresholds));

                // Print and record Explorer FW version info into attributes
                FAPI_INF("run_fw_adapter_properties_get %s", mss::c_str(l_ocmb));
                FAPI_TRY( mss::exp::ib::run_fw_adapter_properties_get(l_ocmb, l_image_a_good, l_image_b_good) );

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
                                    set_OCMB_TARGET(l_ocmb).
                                    set_IMAGE(l_image_num).
                                    set_EXP_ACTIVE_LOG_SIZE(4096),
                                    "%s Explorer SPI flash authentication failed for image %s in MFG test",
                                    mss::c_str(l_ocmb), (!l_image_a_good ? "A" : "B"));
                    }
                    else
                    {
                        // In normal IPL, this fail should produce a recovered log and pass the procedure
                        FAPI_ASSERT_NOEXIT(false,
                                           fapi2::EXP_SPI_FLASH_AUTH_FAIL(fapi2::FAPI2_ERRL_SEV_RECOVERED).
                                           set_OCMB_TARGET(l_ocmb).
                                           set_IMAGE(l_image_num).
                                           set_EXP_ACTIVE_LOG_SIZE(4096),
                                           "%s Explorer SPI flash authentication failed for image %s",
                                           mss::c_str(l_ocmb), (!l_image_a_good ? "A" : "B"));

                        // FAPI_ASSERT_NOEXIT already logs the error, so set current_err back to success so we pass the procedure
                        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                    }
                }
            }
        }
    }

#endif

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}
