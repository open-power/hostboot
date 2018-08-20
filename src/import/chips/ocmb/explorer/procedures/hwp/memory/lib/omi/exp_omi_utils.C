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
/// @brief Sets up the OMI training
/// @param[in] i_target target on which the code is operating
/// @param[in] i_manufacturing_mode manufacturing mode control
/// @param[in] i_loopback_testing loopback testing control
/// @param[in] i_transport_layer transport layer configuration
/// @param[in] i_dl_layer DL layer boot mode
/// @param[in] i_boot_mode true if step-by-step mode
/// @param[in] i_lane_mode lane mode configuration
/// @param[in] i_serdes serdes frequency
/// @param[out] o_data data for the FW_BOOT_CONFIG
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode setup_fw_boot_config( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        const uint8_t i_manufacturing_mode,
                                        const uint8_t i_loopback_testing,
                                        const uint8_t i_transport_layer,
                                        const uint8_t i_dl_layer,
                                        const uint8_t i_boot_mode,
                                        const uint8_t i_lane_mode,
                                        const uint8_t i_serdes,
                                        std::vector<uint8_t>& o_data )
{
    // Clears o_data, just in case
    o_data.clear();
    o_data.assign(mss::exp::i2c::FW_BOOT_CONFIG_BYTE_LEN, 0);

    FAPI_TRY(mss::exp::i2c::boot_cfg::set_serdes_freq( i_target, o_data, i_serdes ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_lane_mode( i_target, o_data, i_lane_mode ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_boot_mode( i_target, o_data, i_boot_mode ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_dl_layer_boot_mode( i_target, o_data, i_dl_layer ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_transport_layer( i_target, o_data, i_transport_layer ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_loopback_test( i_target, o_data, i_loopback_testing ));
    FAPI_TRY(mss::exp::i2c::boot_cfg::set_fw_mode( i_target, o_data, i_manufacturing_mode ));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns train

} // ns omi

} // ns exp

} // ns mss
