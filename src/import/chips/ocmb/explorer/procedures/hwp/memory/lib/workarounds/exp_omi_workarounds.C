/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_omi_workarounds.C $ */
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
/// @file exp_omi_workarounds.C
/// @brief Workarounds for exp_omi_* procedures
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/workarounds/exp_omi_workarounds.H>
#include <lib/shared/exp_consts.H>
#include <lib/omi/exp_omi_utils.H>
#include <lib/i2c/exp_i2c_fields.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>
#include <lib/inband/exp_inband.H>
#include <exp_oc_regs.H>

namespace mss
{
namespace exp
{
namespace workarounds
{
namespace omi
{

///
/// @brief Determine if the OCMB is an explorer
///
/// @param[in] i_ocmb_chip OCMB chip
/// @param[out] o_explorer true/false is explorer
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note Used for exp_omi_train procedure to differentiate fw_status behavior with gemini
///
fapi2::ReturnCode ocmb_is_explorer(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_chip, bool& o_explorer)
{
    uint8_t l_name = 0;
    FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_ocmb_chip, l_name));

    o_explorer = (l_name == fapi2::ENUM_ATTR_NAME_EXPLORER);

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Set configurable delay based on the PRBS ATTR and SIM mode
///
/// @param[in] i_ocmb_chip OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode prbs_delay(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_chip)
{
    uint8_t l_sim = 0;
    uint32_t l_prbs_time = 0;
    uint64_t l_prbs_time_scaled = 0;

    FAPI_TRY( mss::attr::get_is_simulation( l_sim) );

    FAPI_TRY(mss::attr::get_omi_dl_preipl_prbs_time(mss::find_target<fapi2::TARGET_TYPE_OMI>(i_ocmb_chip), l_prbs_time),
             "Error from FAPI_ATTR_GET (ATTR_OMI_DL_PREIPL_PRBS_TIME)");
    l_prbs_time_scaled = l_prbs_time * mss::common_timings::DELAY_1MS;

    FAPI_TRY(fapi2::delay(l_prbs_time_scaled, mss::common_timings::DELAY_1US));
    FAPI_DBG("OMI Training Pre-ipl PRBS Time = %dns",
             (l_sim ? mss::common_timings::DELAY_1US : l_prbs_time_scaled));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determine if we need to bypass MENTERP register reads/writes
///
/// @param[in] i_target OCMB chip
/// @param[out] o_workaround true (1) for gemini, else false (0)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode gem_menterp(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_target,
                              uint8_t& o_workaround)
{
    o_workaround = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_GEMINI_MENTERP_WORKAROUND, i_target, o_workaround),
             "Error getting ATTR_CHIP_EC_FEATURE_GEMINI_MENTERP_WORKAROUND");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Determine if / perform the gemini workaround to setup the OMI config registers
///
/// @param[in] i_target OCMB (gemini)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
/// @note Gemini workaround to setup METADATA and TEMPLATE bits before doing reads
///
fapi2::ReturnCode gem_setup_config(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint8_t l_gemini_config_workaround = 0;

    // Check if gemini workaround should be performed
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_GEMINI_OMI_SETUP_CONFIG_WORKAROUND, i_target,
                           l_gemini_config_workaround),
             "Error getting ATTR_CHIP_EC_FEATURE_GEMINI_OMI_SETUP_CONFIG_WORKAROUND");

    if (l_gemini_config_workaround)
    {
        // Set metadata bits
        fapi2::buffer<uint32_t> l_value;
        l_value.setBit<EXPLR_OC_OCTRLPID_MSB_METADATA_SUPPORTED>();
        l_value.setBit<EXPLR_OC_OCTRLPID_MSB_METADATA_ENABLED>();
        FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_OCTRLPID_MSB, l_value));

        // Set template bits
        l_value.flush<0>();
        l_value.setBit<EXPLR_OC_OTTCFG_MSB_TEMPLATE_0>();
        l_value.setBit<EXPLR_OC_OTTCFG_MSB_TEMPLATE_5>();
        FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_OTTCFG_MSB, l_value));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Workaround for exp_omi_train to perform dlx_config0 setup
///
/// @param[in] i_target OCMB chip
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode training_prbs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint8_t l_dl_x4_backoff_en = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE, i_target, l_dl_x4_backoff_en),
             "Error getting ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE");

    // Train mode 1 (PATTERN_A)
    FAPI_TRY(mss::exp::omi::setup_omi_dl0_config0(i_target,
             mss::omi::train_mode::TX_PATTERN_A,
             l_dl_x4_backoff_en));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Workaround for exp_omi_setup to perform dlx_config0 setup
///
/// @param[in] i_target OCMB chip
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode pre_training_prbs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint8_t l_dl_x4_backoff_en = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE, i_target, l_dl_x4_backoff_en),
             "Error getting ATTR_CHIP_EC_FEATURE_OMI_DL_X4_BACKOFF_ENABLE");

    // State 6
    FAPI_TRY(mss::exp::omi::setup_omi_dl0_config0(i_target,
             mss::omi::train_mode::TX_TRAINING_STATE3,
             l_dl_x4_backoff_en));

    // Set configurable delay based on the PRBS ATTR and SIM mode
    FAPI_TRY(prbs_delay(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Workaround for exp_omi-setup to set explorer cdr bw value
/// @param[in] i_target OCMB chip
/// @param[in] i_omi_freq OMI operating frequency
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode cdr_bw_override(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  const uint32_t i_omi_freq)
{
    fapi2::buffer<uint64_t> l_exp_mdsp_pcib_tr_config_0;
    fapi2::buffer<uint64_t> l_exp_mdsp_pcib_tr_config_1;
    constexpr uint32_t EXPLR_MDSP_PCIB_TR_CONFIG_0_BASE = 0x200A00;
    constexpr uint32_t EXPLR_MDSP_PCIB_TR_CONFIG_1_BASE = 0x200A04;
    uint32_t l_addr_explr_mdsp_pcib_tr_config_0 = EXPLR_MDSP_PCIB_TR_CONFIG_0_BASE;
    uint32_t l_addr_explr_mdsp_pcib_tr_config_1 = EXPLR_MDSP_PCIB_TR_CONFIG_1_BASE;
    constexpr uint8_t EXP_NUM_LANES = 8;
    constexpr uint8_t CDR_BW_OVERRIDE_START = 57;
    constexpr uint8_t CDR_BW_OVERRIDE_LEN = 7;
    constexpr uint8_t CONFIG_UPDATE_START = 54;
    constexpr uint8_t CONFIG_UPDATE_LEN = 1;
    uint8_t ENABLE_WORKAROUND = fapi2::ENUM_ATTR_MSS_EXP_CDR_BW_OVERRIDE_ENABLE_ENABLE;
    uint8_t l_cdr_bw_enable = 0;
    uint8_t l_cdr_bw_val = 47;   //ideal default value found by Chris Steffen experiments
    uint8_t lane = 0;


    //only perform workaround if OMI Freq is less than 25600
    if ( i_omi_freq < fapi2::ENUM_ATTR_FREQ_OMI_MHZ_25600 )
    {
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_EXP_CDR_BW_OVERRIDE_ENABLE, i_target, ENABLE_WORKAROUND),
                  "Error setting ATTR_MSS_EXP_CDR_BW_OVERRIDE_ENABLE");
    }

    // get cdr bw override enable from attribute
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_EXP_CDR_BW_OVERRIDE_ENABLE, i_target, l_cdr_bw_enable),
              "Error getting ATTR_MSS_EXP_CDR_BW_OVERRIDE_ENABLE");
    // get cdr bw override value from attribute
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_EXP_CDR_BW_OVERRIDE_VALUE, i_target, l_cdr_bw_val),
              "Error getting ATTR_MSS_EXP_CDR_BW_OVERRIDE");


    if ( l_cdr_bw_enable )
    {
        // Set configurable exp CDR BW value
        lane = 0;

        while (lane < EXP_NUM_LANES)
        {
            // set local config addresses based on lane value
            l_addr_explr_mdsp_pcib_tr_config_0 = EXPLR_MDSP_PCIB_TR_CONFIG_0_BASE + (lane << 12);
            l_addr_explr_mdsp_pcib_tr_config_1 = EXPLR_MDSP_PCIB_TR_CONFIG_1_BASE + (lane << 12);

            // Update the CDR Values:
            FAPI_TRY(fapi2::getScom(i_target, l_addr_explr_mdsp_pcib_tr_config_1, l_exp_mdsp_pcib_tr_config_1),
                     "Error reading EXPLR_DLX_DL0_CONFIG1 on %s", mss::c_str(i_target));
            l_exp_mdsp_pcib_tr_config_1.insertFromRight<CDR_BW_OVERRIDE_START,
                                                        CDR_BW_OVERRIDE_LEN>(l_cdr_bw_val);
            FAPI_TRY(fapi2::putScom(i_target, l_addr_explr_mdsp_pcib_tr_config_1, l_exp_mdsp_pcib_tr_config_1),
                     "Error writing EXPLR_DLX_DL0_CONFIG1 on %s", mss::c_str(i_target));


            // Toggle the config update bit:
            FAPI_TRY(fapi2::getScom(i_target, l_addr_explr_mdsp_pcib_tr_config_0, l_exp_mdsp_pcib_tr_config_0),
                     "Error reading EXPLR_DLX_DL0_CONFIG0 on %s", mss::c_str(i_target));
            l_exp_mdsp_pcib_tr_config_0.insertFromRight<CONFIG_UPDATE_START,
                                                        CONFIG_UPDATE_LEN>(1);
            FAPI_TRY(fapi2::putScom(i_target, l_addr_explr_mdsp_pcib_tr_config_0, l_exp_mdsp_pcib_tr_config_0),
                     "Error writing EXPLR_DLX_DL0_CONFIG0 on %s", mss::c_str(i_target));
            l_exp_mdsp_pcib_tr_config_0.insertFromRight<CONFIG_UPDATE_START,
                                                        CONFIG_UPDATE_LEN>(0);
            FAPI_TRY(fapi2::putScom(i_target, l_addr_explr_mdsp_pcib_tr_config_0, l_exp_mdsp_pcib_tr_config_0),
                     "Error writing EXPLR_DLX_DL0_CONFIG0 on %s", mss::c_str(i_target));

            lane++;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Disable Explorer PHY optimization step in BOOT_CONFIG0
///
/// @param[in] i_target OCMB_CHIP target
/// @param[in,out] io_boot_config_data BOOT_CONFIG0 data
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode disable_phy_opt(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    std::vector<uint8_t>& io_boot_config_data)
{
    FAPI_DBG("Disabling OMI PHY optimization on %s", mss::c_str(i_target));

    FAPI_TRY(mss::exp::i2c::boot_cfg::set_phy_opt_disable(i_target, io_boot_config_data, 1));

fapi_try_exit:
    return fapi2::current_err;
}

} // omi
} // workarounds
} // exp
} // mss
