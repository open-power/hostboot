/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/omi/exp_omi_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file exp_omi_utils.C
/// @brief OMI utility functions
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <generic/memory/lib/utils/find.H>
#include <lib/omi/exp_omi_utils.H>
#include <lib/shared/exp_consts.H>
#include <lib/i2c/exp_i2c_fields.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>
#include <lib/shared/exp_consts.H>

namespace mss
{
namespace exp
{
namespace omi
{

///
/// @brief Set the OMI_DL0 configuration register for a given mode
///
/// @param[in] i_target OCMB target
/// @param[in] i_train_mode mode to use
/// @param[in] i_dl_x4_backoff_en backoff enable bit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note Algorithm from p10_omi_train.C
///
fapi2::ReturnCode setup_omi_dl0_config0(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint8_t i_train_mode,
    const uint8_t i_dl_x4_backoff_en)
{
    fapi2::buffer<uint64_t> l_config0;

    // Get the "reset" values so we can just overwrite with the changes
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_DLX_DL0_CONFIG0, l_config0),
             "Error reading EXPLR_DLX_DL0_CONFIG0 on %s", mss::c_str(i_target));

    // CFG_DL0_HALF_WIDTH_BACKOFF_ENABLE: dl0 x4 backoff enabled
    l_config0.writeBit<EXPLR_DLX_DL0_CONFIG0_CFG_HALF_WIDTH_BACKOFF_ENABLE>(i_dl_x4_backoff_en);

    // CFG_DL0_TRAIN_MODE: dl0 train mode
    l_config0.insertFromRight<EXPLR_DLX_DL0_CONFIG0_CFG_TRAIN_MODE,
                              EXPLR_DLX_DL0_CONFIG0_CFG_TRAIN_MODE_LEN>(i_train_mode);

    l_config0.writeBit<EXPLR_DLX_DL0_CONFIG0_CFG_PWRMGT_ENABLE>(0);

    FAPI_DBG("Writing 0x%16llx to EXPLR_DLX_DL0_CONFIG0 (0x%16llx) of %s",
             l_config0, EXPLR_DLX_DL0_CONFIG0, mss::c_str(i_target));

    // All other bits will be left at their default values
    FAPI_TRY( fapi2::putScom(i_target, EXPLR_DLX_DL0_CONFIG0, l_config0),
              "Error writing EXPLR_DLX_DL0_CONFIG0 on %s", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

namespace train
{

///
/// @brief Get the FW_BOOT_CONFIG from attributes
/// @param[in] i_target target on which the code is operating
/// @param[out] o_data data for the FW_BOOT_CONFIG
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode setup_fw_boot_config( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        std::vector<uint8_t>& o_data )
{
    // Variables
    uint8_t l_fw_mode = 0;
    uint8_t l_loopback_test = 0;
    uint8_t l_transport_layer = 0;
    uint8_t l_dl_layer_boot_mode = 0;
    uint8_t l_dfe_disable = 0;
    uint8_t l_lane_mode = 0;
    uint8_t l_adaptation_mode = 0;
    uint32_t l_omi_freq = 0;

    const auto& l_proc = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);

    // Read the EXP_FW_BOOT_CONFIG from the attributes
    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_adaptation_mode(i_target, l_adaptation_mode));

    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_fw_mode(i_target, l_fw_mode));

    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_opencapi_loopback_test(i_target, l_loopback_test));

    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_transport_layer(i_target, l_transport_layer));

    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_dl_layer_boot_mode(i_target, l_dl_layer_boot_mode));

    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_dfe_disable(i_target, l_dfe_disable));

    FAPI_TRY(mss::attr::get_ocmb_exp_boot_config_lane_mode(i_target, l_lane_mode));

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, l_proc, l_omi_freq) );


    // Clears o_data, just in case
    o_data.clear();
    o_data.assign(mss::exp::i2c::FW_BOOT_CONFIG_BYTE_LEN, 0);

    FAPI_TRY(mss::exp::i2c::boot_cfg::set_serdes_freq( i_target, o_data, l_omi_freq ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_lane_mode( i_target, o_data, l_lane_mode ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_dfe_disable( i_target, o_data, l_dfe_disable ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_dl_layer_boot_mode( i_target, o_data, l_dl_layer_boot_mode ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_transport_layer( i_target, o_data, l_transport_layer ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_loopback_test( i_target, o_data, l_loopback_test ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_fw_mode( i_target, o_data, l_fw_mode ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_adaptation_mode( i_target, o_data, l_adaptation_mode ));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check the OMI train status on the OCMB chip
///
/// @param[in] i_target OCMB chil
/// @param[out] o_state_machine_state training state mahcine
/// @param[out] o_omi_training_status training status
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode omi_train_status(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   uint8_t& o_state_machine_state,
                                   fapi2::buffer<uint64_t>& o_omi_training_status)
{
    fapi2::buffer<uint64_t> l_omi_status;

    // Check OMI training status
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_DLX_DL0_STATUS, l_omi_status));

    o_omi_training_status = l_omi_status;
    o_state_machine_state = 0;
    l_omi_status.extractToRight<EXPLR_DLX_DL0_STATUS_STS_TRAINING_STATE_MACHINE,
                                EXPLR_DLX_DL0_STATUS_STS_TRAINING_STATE_MACHINE_LEN>(o_state_machine_state);

fapi_try_exit:
    return fapi2::current_err;
}

} // ns train

} // ns omi

} // ns exp

} // ns mss
