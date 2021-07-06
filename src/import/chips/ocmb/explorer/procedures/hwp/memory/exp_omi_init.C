/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_omi_init.C $ */
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
/// @file exp_omi_init.C
/// @brief Initialize Explorer OpenCAPI configuration
///
// *HWP HWP Owner: Benjamin Gass <bgass@us.ibm.com>
// *HWP HWP Backup: Daniel Crowell <dcrowell@us.ibm.com>
// *HWP Team:
// *HWP Level: 3
// *HWP Consumed by: HB

#include <lib/shared/exp_defaults.H>
#include <exp_omi_init.H>
#include <exp_oc_regs.H>
#include <lib/inband/exp_inband.H>
#include <lib/omi/exp_omi_utils.H>
#include <chips/common/utils/chipids.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_explorer_attribute_setters.H>
#include <mss_p10_attribute_getters.H>
#include <generic/memory/mss_git_data_helper.H>
#include <lib/workarounds/exp_omi_workarounds.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>

///
/// @brief Verify we know how to talk to the connected device
///
/// @param[in] i_target                 Explorer to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiDeviceVerify(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("%s Start omiDeviceVerify", mss::c_str(i_target));
    fapi2::buffer<uint32_t> l_data;

    constexpr uint32_t EXPECTED = (POWER_OCID::EXPLORER << 16) | (POWER_OCID::VENDOR_IBM);

    FAPI_TRY(mss::exp::ib::getOCCfg(i_target, EXPLR_OC_O0MBIT_O0DID_LSB, l_data));

    FAPI_ASSERT(l_data == EXPECTED,
                fapi2::OCMB_IS_NOT_EXPLORER()
                .set_OCMB_TARGET(i_target)
                .set_ID(l_data)
                .set_EXPECTED(EXPECTED),
                "%s Explorer ID was not found. Read: 0x%08X Expected 0x%08X. This could be due to the OMI link going down, or the Cronus "
                "OCMB_SCOM_MODE is overridden to I2C",
                mss::c_str(i_target), l_data(), EXPECTED);

fapi_try_exit:

    FAPI_DBG("%s Exiting with return code : 0x%08X...", mss::c_str(i_target), (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}


///
/// @brief Set the upstream templates and pacing
///
/// @param[in] i_target                 Explorer to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiSetUpstreamTemplates(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    //Expected dnstream 0,1,4 to OCMB
    //Expected upstream 0,5,9 to Axone
    fapi2::buffer<uint32_t> l_data;
    fapi2::ATTR_EXPLR_ENABLE_US_TMPL_1_Type l_enable_tmpl_1;
    fapi2::ATTR_EXPLR_ENABLE_US_TMPL_5_Type l_enable_tmpl_5;
    fapi2::ATTR_EXPLR_ENABLE_US_TMPL_9_Type l_enable_tmpl_9;
    fapi2::ATTR_EXPLR_ENABLE_US_TMPL_B_Type l_enable_tmpl_b;
    fapi2::ATTR_EXPLR_TMPL_0_PACING_Type l_tmpl_0_pacing;
    fapi2::ATTR_EXPLR_TMPL_1_PACING_Type l_tmpl_1_pacing;
    fapi2::ATTR_EXPLR_TMPL_5_PACING_Type l_tmpl_5_pacing;
    fapi2::ATTR_EXPLR_TMPL_9_PACING_Type l_tmpl_9_pacing;
    fapi2::ATTR_EXPLR_TMPL_B_PACING_Type l_tmpl_b_pacing;

    fapi2::ATTR_CHIP_EC_FEATURE_US_TEMPLATES_0159_Type l_us_only_0159;

    auto const& l_proc = i_target.getParent<fapi2::TARGET_TYPE_OMI>()
                         .getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_US_TEMPLATES_0159,
                           l_proc,
                           l_us_only_0159),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_US_TEMPLATES_0159)");

    FAPI_TRY(mss::attr::get_explr_enable_us_tmpl_1(i_target, l_enable_tmpl_1));
    FAPI_TRY(mss::attr::get_explr_enable_us_tmpl_5(i_target, l_enable_tmpl_5));
    FAPI_TRY(mss::attr::get_explr_enable_us_tmpl_9(i_target, l_enable_tmpl_9));
    FAPI_TRY(mss::attr::get_explr_enable_us_tmpl_b(i_target, l_enable_tmpl_b));

    FAPI_ASSERT(!l_us_only_0159 || !l_enable_tmpl_b,
                fapi2::PROC_DOES_NOT_SUPPORT_US_B()
                .set_PROC_TARGET(l_proc)
                .set_B(l_enable_tmpl_b)
                .set_US_TEMPLATES_0159(l_us_only_0159)
                .set_OCMB_TARGET(i_target),
                "%s Upstream template B requested, but not supported by proc. EN_TMPL_B: %u, CHIP_EC_TMPL_0159: %u",
                mss::c_str(l_proc), l_enable_tmpl_b, l_us_only_0159);

    FAPI_TRY(mss::attr::get_explr_tmpl_0_pacing(i_target, l_tmpl_0_pacing));
    FAPI_TRY(mss::attr::get_explr_tmpl_1_pacing(i_target, l_tmpl_1_pacing));
    FAPI_TRY(mss::attr::get_explr_tmpl_5_pacing(i_target, l_tmpl_5_pacing));
    FAPI_TRY(mss::attr::get_explr_tmpl_9_pacing(i_target, l_tmpl_9_pacing));
    FAPI_TRY(mss::attr::get_explr_tmpl_b_pacing(i_target, l_tmpl_b_pacing));

    l_data.setBit<EXPLR_OC_OTTCFG_MSB_TEMPLATE_0>(); //Template 0

    l_data.writeBit<EXPLR_OC_OTTCFG_MSB_TEMPLATE_1>
    (l_enable_tmpl_1 == fapi2::ENUM_ATTR_EXPLR_ENABLE_US_TMPL_1_ENABLED); //Template 1
    l_data.writeBit<EXPLR_OC_OTTCFG_MSB_TEMPLATE_5>
    (l_enable_tmpl_5 == fapi2::ENUM_ATTR_EXPLR_ENABLE_US_TMPL_5_ENABLED); //Template 5
    l_data.writeBit<EXPLR_OC_OTTCFG_MSB_TEMPLATE_9>
    (l_enable_tmpl_9 == fapi2::ENUM_ATTR_EXPLR_ENABLE_US_TMPL_9_ENABLED); //Template 9
    l_data.writeBit<EXPLR_OC_OTTCFG_MSB_TEMPLATE_11>
    (l_enable_tmpl_b == fapi2::ENUM_ATTR_EXPLR_ENABLE_US_TMPL_B_ENABLED); //Template B


    FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_OTTCFG_MSB, l_data));

    //Update template pacing
    l_data.flush<0>();
    l_data.insertFromRight<EXPLR_OC_OTRCFG76_MSB_TEMPLATE_0,
                           EXPLR_OC_OTRCFG76_MSB_TEMPLATE_0_LEN>(l_tmpl_0_pacing);
    FAPI_DBG("Upstream template 0 enabled with pacing %X", l_tmpl_0_pacing);

    if (l_enable_tmpl_1 == fapi2::ENUM_ATTR_EXPLR_ENABLE_US_TMPL_1_ENABLED)
    {
        l_data.insertFromRight<EXPLR_OC_OTRCFG76_MSB_TEMPLATE_1,
                               EXPLR_OC_OTRCFG76_MSB_TEMPLATE_1_LEN>(l_tmpl_1_pacing);
        FAPI_DBG("WARNING Upstream template 1 enabled with pacing %X", l_tmpl_1_pacing);
    }

    if (l_enable_tmpl_5 == fapi2::ENUM_ATTR_EXPLR_ENABLE_US_TMPL_5_ENABLED)
    {
        l_data.insertFromRight<EXPLR_OC_OTRCFG76_MSB_TEMPLATE_5,
                               EXPLR_OC_OTRCFG76_MSB_TEMPLATE_5_LEN>(l_tmpl_5_pacing);
        FAPI_DBG("Upstream template 5 enabled with pacing %X", l_tmpl_5_pacing);
    }

    FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_OTRCFG76_MSB, l_data));

    l_data.flush<0>();

    if (l_enable_tmpl_9 == fapi2::ENUM_ATTR_EXPLR_ENABLE_US_TMPL_9_ENABLED)
    {
        l_data.insertFromRight<EXPLR_OC_OTRCFG76_LSB_TEMPLATE_9,
                               EXPLR_OC_OTRCFG76_LSB_TEMPLATE_9_LEN>(l_tmpl_9_pacing);
        FAPI_DBG("Upstream template 9 enabled with pacing %X", l_tmpl_9_pacing);
    }

    if (l_enable_tmpl_b == fapi2::ENUM_ATTR_EXPLR_ENABLE_US_TMPL_B_ENABLED)
    {
        l_data.insertFromRight<EXPLR_OC_OTRCFG76_LSB_TEMPLATE_11,
                               EXPLR_OC_OTRCFG76_LSB_TEMPLATE_11_LEN>(l_tmpl_b_pacing);
        FAPI_DBG("Upstream template B enabled with pacing %X", l_tmpl_b_pacing);
    }

    FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_OTRCFG76_LSB, l_data));

fapi_try_exit:

    FAPI_DBG("%s Exiting with return code : 0x%08X...", mss::c_str(i_target), (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}


///
/// @brief Set the major minor version and short back-off timer values.
///
/// @param[in] i_target                 Explorer to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiTLVersionShortBackOff(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::buffer<uint32_t> l_data;
    fapi2::buffer<uint8_t> l_short_backoff;
    fapi2::ATTR_PROC_OMI_OC_MAJOR_VER_Type l_proc_oc_major;
    fapi2::ATTR_PROC_OMI_OC_MINOR_VER_Type l_proc_oc_minor;

    auto const& l_proc = i_target.getParent<fapi2::TARGET_TYPE_OMI>()
                         .getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_TRY(mss::attr::get_explr_shrt_backoff_timer(i_target, l_short_backoff));
    FAPI_TRY(mss::attr::get_omi_oc_major_ver(l_proc, l_proc_oc_major));
    FAPI_TRY(mss::attr::get_omi_oc_minor_ver(l_proc, l_proc_oc_minor));

    //Write proc's supported OC version
    l_data.insertFromRight<EXPLR_OC_OVERCFG_LSB_TL_MAJOR_VERSION_CONFIGURATION,
                           EXPLR_OC_OVERCFG_LSB_TL_MAJOR_VERSION_CONFIGURATION_LEN>(l_proc_oc_major);
    l_data.insertFromRight<EXPLR_OC_OVERCFG_LSB_TL_MINOR_VERSION_CONFIGURATION,
                           EXPLR_OC_OVERCFG_LSB_TL_MINOR_VERSION_CONFIGURATION_LEN>(l_proc_oc_minor);

    //Short back-off timer
    l_data.insertFromRight<EXPLR_OC_OVERCFG_LSB_SHORT_BACK_OFF_TIMER,
                           EXPLR_OC_OVERCFG_LSB_SHORT_BACK_OFF_TIMER_LEN>(l_short_backoff);

    FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_OVERCFG_LSB, l_data));

fapi_try_exit:

    FAPI_DBG("%s Exiting with return code : 0x%08X...", mss::c_str(i_target), (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}


///
/// @brief Check if a bit/feature is supported if we want to use it.
///
/// @param[in] i_data                Register data to check
/// @param[in] i_offset              Offset in register value starts
/// @param[in] i_useFeature          Do we want to use this feature
/// @param[in] i_warn                Warning message to display if reg value does not match attribute
/// @param[out] o_val                Value to use
///
/// @return fapi2::ReturnCode Success if no errors
///
fapi2::ReturnCode omiCheckSupportedBit(const fapi2::buffer<uint32_t>& i_data, const uint32_t i_offset,
                                       const uint8_t i_useFeature, const char* i_warn, uint8_t& o_val)
{
    uint8_t l_supported = 0;
    o_val = i_useFeature;
    FAPI_TRY(i_data.extractToRight<uint8_t>(l_supported, i_offset, 1));

    if (i_useFeature != 0 && l_supported == 0)
    {
        // This feature is not supported by the hardware even though we requested it
        // We are still be fine to proceed, but we will print an informational message
        FAPI_INF("%s", i_warn);
        o_val = 0;
    }

fapi_try_exit:
    FAPI_DBG("Exit with return code : 0x%08X", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Check if the requested pacing for a template is supported
///
/// @param[in] i_data                Register data to check
/// @param[in] i_offset              Offset in register value starts
/// @param[in] i_len                 The length of the pacing field
/// @param[in] i_usePace             The desired pacing value
/// @param[in] i_warn                Warning message to display if reg value does not match attribute
/// @param[out] o_val                The pacing value to use
///
/// @return fapi2::ReturnCode Success if no errors
///
fapi2::ReturnCode omiCheckSupportedPacing(const fapi2::buffer<uint32_t>& i_data, const uint32_t i_offset,
        const uint32_t i_len, const uint8_t i_usePace, const char* i_warn, uint8_t& o_val)
{
    uint8_t l_supported = 0;
    o_val = i_usePace;
    FAPI_TRY(i_data.extractToRight<uint8_t>(l_supported, i_offset, i_len));

    if (i_usePace < l_supported)
    {
        // This pacing is not supported by the hardware
        // We are still be fine to proceed, but we will print a warning.
        FAPI_INF("%s", i_warn);
        o_val = l_supported;
    }

fapi_try_exit:
    FAPI_DBG("Exit with return code : 0x%08X", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Validate downstream receive templates
///
/// @param[in] i_target                 Explorer to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiValidateDownstream(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    //Expected dnstream 0,1,4 to OCMB
    //Expected upstream 0,5,9 to P10
    fapi2::buffer<uint32_t> l_data;
    fapi2::ATTR_PROC_ENABLE_DL_TMPL_1_Type l_enable_tmpl_1;
    fapi2::ATTR_PROC_ENABLE_DL_TMPL_4_Type l_enable_tmpl_4;
    fapi2::ATTR_PROC_ENABLE_DL_TMPL_7_Type l_enable_tmpl_7;
    fapi2::ATTR_PROC_ENABLE_DL_TMPL_A_Type l_enable_tmpl_A;
    fapi2::ATTR_PROC_TMPL_0_PACING_Type l_tmpl_0_pace;
    fapi2::ATTR_PROC_TMPL_1_PACING_Type l_tmpl_1_pace;
    fapi2::ATTR_PROC_TMPL_4_PACING_Type l_tmpl_4_pace;
    fapi2::ATTR_PROC_TMPL_7_PACING_Type l_tmpl_7_pace;
    fapi2::ATTR_PROC_TMPL_A_PACING_Type l_tmpl_A_pace;
    uint8_t l_tmp = 0x0;

    fapi2::ATTR_CHIP_EC_FEATURE_DS_TEMPLATES_0147_Type l_ds_only_0147;

    const auto& l_proc = i_target.getParent<fapi2::TARGET_TYPE_OMI>()
                         .getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    const auto& l_mcc_target = i_target.getParent<fapi2::TARGET_TYPE_OMI>()
                               .getParent<fapi2::TARGET_TYPE_MCC>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_DS_TEMPLATES_0147,
                           l_proc,
                           l_ds_only_0147),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_DS_TEMPLATES_0147)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_1,
                           l_mcc_target,
                           l_enable_tmpl_1),
             "Error from FAPI_ATTR_GET (ATTR_PROC_ENABLE_DL_TMPL_1)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_4,
                           l_mcc_target,
                           l_enable_tmpl_4),
             "Error from FAPI_ATTR_GET (ATTR_PROC_ENABLE_DL_TMPL_4)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_7,
                           l_mcc_target,
                           l_enable_tmpl_7),
             "Error from FAPI_ATTR_GET (ATTR_PROC_ENABLE_DL_TMPL_7)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_A,
                           l_mcc_target,
                           l_enable_tmpl_A),
             "Error from FAPI_ATTR_GET (ATTR_PROC_ENABLE_DL_TMPL_A)");

    FAPI_ASSERT(!l_ds_only_0147 || !l_enable_tmpl_A,
                fapi2::PROC_DOES_NOT_SUPPORT_DS_A()
                .set_PROC_TARGET(l_proc)
                .set_DS_TEMPLATES_0147(l_ds_only_0147)
                .set_A(l_enable_tmpl_A)
                .set_OCMB_TARGET(i_target),
                "%s Downstream template A requested, but not supported by proc. EN_TMPL_A: %u CHIP_EC_TMPL_0147: %u",
                mss::c_str(l_proc), l_enable_tmpl_A, l_ds_only_0147);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_TMPL_0_PACING,
                           l_mcc_target,
                           l_tmpl_0_pace),
             "Error from FAPI_ATTR_GET (ATTR_PROC_TMPL_0_PACING)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_TMPL_1_PACING,
                           l_mcc_target,
                           l_tmpl_1_pace),
             "Error from FAPI_ATTR_GET (ATTR_PROC_TMPL_1_PACING)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_TMPL_4_PACING,
                           l_mcc_target,
                           l_tmpl_4_pace),
             "Error from FAPI_ATTR_GET (ATTR_PROC_TMPL_4_PACING)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_TMPL_7_PACING,
                           l_mcc_target,
                           l_tmpl_7_pace),
             "Error from FAPI_ATTR_GET (ATTR_PROC_TMPL_7_PACING)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_TMPL_A_PACING,
                           l_mcc_target,
                           l_tmpl_A_pace),
             "Error from FAPI_ATTR_GET (ATTR_PROC_TMPL_A_PACING)");

    FAPI_TRY(mss::exp::ib::getOCCfg(i_target, EXPLR_OC_ORTCAP_MSB, l_data));

    FAPI_TRY(omiCheckSupportedBit(l_data, EXPLR_OC_ORTCAP_MSB_TEMPLATE_1, l_enable_tmpl_1,
                                  "OCMB Template 1 requested, but not supported", l_tmp));

    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_PROC_ENABLE_DL_TMPL_1,
                             l_mcc_target,
                             l_tmp       ) );

    FAPI_TRY(omiCheckSupportedBit(l_data, EXPLR_OC_ORTCAP_MSB_TEMPLATE_4, l_enable_tmpl_4,
                                  "OCMB Template 4 requested, but not supported", l_tmp));
    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_PROC_ENABLE_DL_TMPL_4,
                             l_mcc_target,
                             l_tmp       ) );

    FAPI_TRY(omiCheckSupportedBit(l_data, EXPLR_OC_ORTCAP_MSB_TEMPLATE_7, l_enable_tmpl_7,
                                  "OCMB Template 7 requested, but not supported", l_tmp));
    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_PROC_ENABLE_DL_TMPL_7,
                             l_mcc_target,
                             l_tmp       ) );

    FAPI_TRY(omiCheckSupportedBit(l_data, EXPLR_OC_ORTCAP_MSB_TEMPLATE_10, l_enable_tmpl_A,
                                  "OCMB Template A requested, but not supported", l_tmp))
    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_PROC_ENABLE_DL_TMPL_A,
                             l_mcc_target,
                             l_tmp       ) );



    FAPI_TRY(mss::exp::ib::getOCCfg(i_target, EXPLR_OC_ORRCAP76_MSB, l_data));

    FAPI_TRY(omiCheckSupportedPacing(l_data, EXPLR_OC_ORRCAP76_MSB_TEMPLATE_0,
                                     EXPLR_OC_ORRCAP76_MSB_TEMPLATE_0_LEN, l_tmpl_0_pace,
                                     "OCMB Template 0 requested pacing not supported", l_tmp));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_TMPL_0_PACING,
                           l_mcc_target,
                           l_tmp ));

    FAPI_TRY(omiCheckSupportedPacing(l_data, EXPLR_OC_ORRCAP76_MSB_TEMPLATE_1,
                                     EXPLR_OC_ORRCAP76_MSB_TEMPLATE_1_LEN, l_tmpl_1_pace,
                                     "OCMB Template 1 requested pacing not supported", l_tmp));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_TMPL_1_PACING,
                           l_mcc_target,
                           l_tmp ));

    FAPI_TRY(omiCheckSupportedPacing(l_data, EXPLR_OC_ORRCAP76_MSB_TEMPLATE_4,
                                     EXPLR_OC_ORRCAP76_MSB_TEMPLATE_4_LEN, l_tmpl_4_pace,
                                     "OCMB Template 4 requested pacing not supported", l_tmp));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_TMPL_4_PACING,
                           l_mcc_target,
                           l_tmp ));

    FAPI_TRY(omiCheckSupportedPacing(l_data, EXPLR_OC_ORRCAP76_MSB_TEMPLATE_7,
                                     EXPLR_OC_ORRCAP76_MSB_TEMPLATE_7_LEN, l_tmpl_7_pace,
                                     "OCMB Template 7 requested pacing not supported", l_tmp));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_TMPL_7_PACING,
                           l_mcc_target,
                           l_tmp ));

    FAPI_TRY(mss::exp::ib::getOCCfg(i_target, EXPLR_OC_ORRCAP76_LSB, l_data));

    FAPI_TRY(omiCheckSupportedPacing(l_data, EXPLR_OC_ORRCAP76_LSB_TEMPLATE_10,
                                     EXPLR_OC_ORRCAP76_LSB_TEMPLATE_10_LEN, l_tmpl_A_pace,
                                     "OCMB Template A requested pacing not supported", l_tmp));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_TMPL_A_PACING,
                           l_mcc_target,
                           l_tmp ));

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}


///
/// @brief Set the MMIO BAR
///
/// @param[in] i_target                 Explorer to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiSetMMIOEnableBAR(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint8_t l_addrbit;
    fapi2::buffer<uint32_t> l_value;

    const auto& l_mcc_target = i_target.getParent<fapi2::TARGET_TYPE_OMI>()
                               .getParent<fapi2::TARGET_TYPE_MCC>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_DSTLCFG_MMIO_ADDRBIT_POS,
                           l_mcc_target,
                           l_addrbit),
             "Error from FAPI_ATTR_GET (ATTR_PROC_DSTLCFG_MMIO_ADDRBIT_POS)");

    //Mask bit should be 43 + l_addrbit in le bit ordering
    //subtract from 63 for big endian bit order
    l_value.flush<0>();
    FAPI_TRY(l_value.setBit(63 - (43 + l_addrbit)));
    FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_O1BAR0_MSB, l_value));

    //Enable the bar
    FAPI_TRY(mss::exp::ib::getOCCfg(i_target, EXPLR_OC_O1MBIT_O1DID_MSB, l_value));
    l_value.setBit<EXPLR_OC_O1MBIT_O1DID_MSB_MEMORY_SPACE>();
    FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_O1MBIT_O1DID_MSB, l_value));

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Set the actag and pasid lengths and bases, enable metadata.
///
/// @param[in] i_target                 Explorer to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiSetACTagPASIDMetaData(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::ATTR_EXPLR_METADATA_ENABLE_Type l_meta_data_ena;
    fapi2::ATTR_EXPLR_ACTAG_BASE_Type l_actag_base;
    fapi2::ATTR_EXPLR_PASID_BASE_Type l_pasid_base;
    fapi2::ATTR_EXPLR_AFU_ACTAG_LEN_Type l_afu_actag_len;
    fapi2::ATTR_EXPLR_PASID_LEN_Type l_pasid_len;
    fapi2::buffer<uint32_t> l_value;
    fapi2::buffer<uint32_t> l_afu_actag_len_supported;
    fapi2::buffer<uint32_t> l_pasid_len_supported;

    FAPI_TRY(mss::attr::get_explr_metadata_enable(i_target, l_meta_data_ena));
    FAPI_TRY(mss::attr::get_explr_pasid_base(i_target, l_pasid_base));
    FAPI_TRY(mss::attr::get_explr_actag_base(i_target, l_actag_base));
    FAPI_TRY(mss::attr::get_explr_afu_actag_len(i_target, l_afu_actag_len));
    FAPI_TRY(mss::attr::get_explr_pasid_len(i_target, l_pasid_len));

    //Set PASID Base and enable metadata
    FAPI_TRY(mss::exp::ib::getOCCfg(i_target, EXPLR_OC_OCTRLPID_MSB, l_value));
    FAPI_TRY(omiCheckSupportedBit(l_value,
                                  EXPLR_OC_OCTRLPID_MSB_METADATA_SUPPORTED,
                                  l_meta_data_ena,
                                  "Metadata requested but not supported", l_meta_data_ena));

    // If we plan on enabling metadata, make sure either upstream templates 5 or 9 are enabled
    if (l_meta_data_ena)
    {
        uint8_t l_enable_template_5 = 0;
        uint8_t l_enable_template_9 = 0;
        uint8_t l_enable_template_4 = 0;

        const auto& l_mcc = mss::find_target<fapi2::TARGET_TYPE_MCC>(i_target);

        FAPI_TRY(mss::attr::get_explr_enable_us_tmpl_5(i_target, l_enable_template_5));
        FAPI_TRY(mss::attr::get_explr_enable_us_tmpl_9(i_target, l_enable_template_9));

        FAPI_ASSERT((l_enable_template_5 == fapi2::ENUM_ATTR_EXPLR_ENABLE_US_TMPL_5_ENABLED) ||
                    (l_enable_template_9 == fapi2::ENUM_ATTR_EXPLR_ENABLE_US_TMPL_9_ENABLED),
                    fapi2::METADATA_ENABLE_REQUIRES_TEMPLATE_5_OR_9()
                    .set_OCMB_TARGET(i_target)
                    .set_TMPL_5(l_enable_template_5)
                    .set_TMPL_9(l_enable_template_9),
                    "%s METADATA_ENABLE requires upstream template either 5 or 9 to be set. "
                    "TMPL_5: %u TMPL_9: %u",
                    mss::c_str(i_target),
                    l_enable_template_5,
                    l_enable_template_9)

        // Check for downstream template 4 as well. We won't bomb out here, just have an error printout if not enabled
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_4, l_mcc, l_enable_template_4),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_ENABLE_DL_TMPL_4)");

        if (l_enable_template_4 != fapi2::ENUM_ATTR_PROC_ENABLE_DL_TMPL_4_ENABLED)
        {
            FAPI_ERR("%s Expected MCC %s TMPL_4 to be enabled for metadata enabling. Was not enabled: may be incorrectly configured",
                     mss::c_str(i_target),
                     mss::c_str(l_mcc));
        }
    }

    l_value.insertFromRight<EXPLR_OC_OCTRLPID_MSB_METADATA_ENABLED,
                            EXPLR_OC_OCTRLPID_MSB_METADATA_ENABLED_LEN>
                            (l_meta_data_ena);
    l_value.insertFromRight<EXPLR_OC_OCTRLPID_MSB_PASID_BASE,
                            EXPLR_OC_OCTRLPID_MSB_PASID_BASE_LEN>
                            (l_pasid_base);
    FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_OCTRLPID_MSB, l_value));


    //Establish PASID supported, check expected, set enabled.
    FAPI_TRY(mss::exp::ib::getOCCfg(i_target, EXPLR_OC_OCTRLPID_LSB, l_value));

    FAPI_TRY(l_value.extractToRight<uint32_t>(l_pasid_len_supported, EXPLR_OC_OCTRLPID_LSB_PASID_LENGTH_SUPPORTED,
             EXPLR_OC_OCTRLPID_LSB_PASID_LENGTH_SUPPORTED_LEN));

    //If we want a smaller PASID length than what is supported use it, otherwise
    //use the supported length.
    if (l_pasid_len_supported < l_pasid_len)
    {
        FAPI_ERR("Requested PASID value (%d) greater than supported (%d)", l_pasid_len, l_pasid_len_supported);
        l_pasid_len = l_pasid_len_supported;
    }

    l_value.insertFromRight<EXPLR_OC_OCTRLPID_LSB_PASID_LENGTH_ENABLED,
                            EXPLR_OC_OCTRLPID_LSB_PASID_LENGTH_ENABLED_LEN>
                            (l_pasid_len);
    FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_OCTRLPID_LSB, l_value));

    //Establish supported AFU ACTAG length, check expected, set
    FAPI_TRY(mss::exp::ib::getOCCfg(i_target, EXPLR_OC_OCTRLTAG_LSB, l_value));

    FAPI_TRY(l_value.extractToRight<uint32_t>(l_afu_actag_len_supported,
             EXPLR_OC_OCTRLTAG_LSB_AFU_ACTAG_LENGTH_SUPPORTED,
             EXPLR_OC_OCTRLTAG_LSB_AFU_ACTAG_LENGTH_SUPPORTED_LEN));

    //If we want a smaller ACTAG length than what is supported use it, otherwise
    //use the supported length;
    if (l_afu_actag_len_supported < l_afu_actag_len)
    {
        FAPI_ERR("Requested ACTAG length value (%d) greater than supported (%d)", l_afu_actag_len, l_afu_actag_len_supported);
        l_afu_actag_len = l_afu_actag_len_supported;
    }

    l_value.insertFromRight<EXPLR_OC_OCTRLTAG_LSB_AFU_ACTAG_LENGTH_ENABLED,
                            EXPLR_OC_OCTRLTAG_LSB_AFU_ACTAG_LENGTH_ENABLED_LEN>
                            (l_afu_actag_len);
    FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_OCTRLTAG_LSB, l_value));

    //Write the Functions actag length.  There's only 1 AFU so set
    //the function the same as the AFU.
    //(Note: on explorer this causes it to send a assign_acTag to the host)
    FAPI_TRY(mss::exp::ib::getOCCfg(i_target, EXPLR_OC_O1ACTAG_O1FNID_MSB, l_value));
    l_value.insertFromRight<EXPLR_OC_O1ACTAG_O1FNID_MSB_ACTAG_LENGTH,
                            EXPLR_OC_O1ACTAG_O1FNID_MSB_ACTAG_LENGTH_LEN>
                            (l_afu_actag_len);
    l_value.insertFromRight<EXPLR_OC_O1ACTAG_O1FNID_MSB_ACTAG_BASE,
                            EXPLR_OC_O1ACTAG_O1FNID_MSB_ACTAG_BASE_LEN>
                            (l_actag_base);
    FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_O1ACTAG_O1FNID_MSB, l_value));

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Enable the AFU
///
/// @param[in] i_target                 Explorer to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiEnableAFU(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::buffer<uint32_t> l_value;
    FAPI_TRY(mss::exp::ib::getOCCfg(i_target, EXPLR_OC_OCTRLENB_OCTRLID_MSB, l_value));
    l_value.setBit<EXPLR_OC_OCTRLENB_OCTRLID_MSB_ENABLE_AFU>();
    FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_OCTRLENB_OCTRLID_MSB, l_value));

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Initialize Explorer OpenCAPI configuration
///
/// @param[in] i_target                 Explorer to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode exp_omi_init(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    mss::display_git_commit_info("exp_omi_init");

    FAPI_DBG("Start");
    FAPI_TRY(mss::exp::workarounds::omi::gem_setup_config(i_target));
    FAPI_TRY(omiDeviceVerify(i_target));
    FAPI_TRY(omiSetUpstreamTemplates(i_target));
    FAPI_TRY(omiValidateDownstream(i_target));
    FAPI_TRY(omiTLVersionShortBackOff(i_target));
    FAPI_TRY(omiSetMMIOEnableBAR(i_target));
    FAPI_TRY(mss::exp::omi::setup_obj_handles(i_target));
    FAPI_TRY(mss::exp::omi::setup_int_cmd_flags(i_target));
    FAPI_TRY(omiSetACTagPASIDMetaData(i_target));
    FAPI_TRY(omiEnableAFU(i_target));
    FAPI_TRY(mss::unmask::after_mc_omi_init<mss::mc_type::EXPLORER>(i_target));

    // Save our new communication state
    FAPI_TRY(mss::attr::set_exp_comm_state(i_target, fapi2::ENUM_ATTR_MSS_EXP_COMM_STATE_INBAND));

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}
