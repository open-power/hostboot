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

#include <lib/omi/exp_omi_utils.H>
#include <lib/shared/exp_consts.H>
#include <lib/i2c/exp_i2c_fields.H>

namespace mss
{
namespace exp
{
namespace omi
{
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
    uint8_t l_boot_mode = 0;
    uint8_t l_lane_mode = 0;
    uint8_t l_serdes_freq = 0;

    // Read the EXP_FW_BOOT_CONFIG from the attributes
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_BOOT_CONFIG_FW_MODE,
                           i_target,
                           l_fw_mode),
             "Error from FAPI_ATTR_GET (ATTR_MSS_OCMB_EXP_BOOT_CONFIG_FW_MODE) on %s", mss::c_str(i_target));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_BOOT_CONFIG_OPENCAPI_LOOPBACK_TEST,
                           i_target,
                           l_loopback_test),
             "Error from FAPI_ATTR_GET (ATTR_MSS_OCMB_EXP_BOOT_CONFIG_OPENCAPI_LOOPBACK_TEST) on %s", mss::c_str(i_target));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_BOOT_CONFIG_TRANSPORT_LAYER,
                           i_target,
                           l_transport_layer),
             "Error from FAPI_ATTR_GET (ATTR_MSS_OCMB_EXP_BOOT_CONFIG_TRANSPORT_LAYER) on %s", mss::c_str(i_target));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_BOOT_CONFIG_DL_LAYER_BOOT_MODE,
                           i_target,
                           l_dl_layer_boot_mode),
             "Error from FAPI_ATTR_GET (ATTR_MSS_OCMB_EXP_BOOT_CONFIG_DL_LAYER_BOOT_MODE) on %s", mss::c_str(i_target));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_BOOT_CONFIG_BOOT_MODE,
                           i_target,
                           l_boot_mode),
             "%s Error from FAPI_ATTR_GET (ATTR_MSS_OCMB_EXP_BOOT_CONFIG_BOOT_MODE) on %s", mss::c_str(i_target));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_BOOT_CONFIG_LANE_MODE,
                           i_target,
                           l_lane_mode),
             "Error from FAPI_ATTR_GET (ATTR_MSS_OCMB_EXP_BOOT_CONFIG_LANE_MODE) on %s", mss::c_str(i_target));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_BOOT_CONFIG_SERDES_FREQUENCY,
                           i_target,
                           l_serdes_freq),
             "Error from FAPI_ATTR_GET (ATTR_MSS_OCMB_EXP_BOOT_CONFIG_SERDES_FREQUENCY) on %s", mss::c_str(i_target));


    // Clears o_data, just in case
    o_data.clear();
    o_data.assign(mss::exp::i2c::FW_BOOT_CONFIG_BYTE_LEN, 0);

    FAPI_TRY(mss::exp::i2c::boot_cfg::set_serdes_freq( i_target, o_data, l_serdes_freq ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_lane_mode( i_target, o_data, l_lane_mode ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_boot_mode( i_target, o_data, l_boot_mode ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_dl_layer_boot_mode( i_target, o_data, l_dl_layer_boot_mode ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_transport_layer( i_target, o_data, l_transport_layer ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_loopback_test( i_target, o_data, l_loopback_test ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_fw_mode( i_target, o_data, l_fw_mode ));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns train

} // ns omi

} // ns exp

} // ns mss
