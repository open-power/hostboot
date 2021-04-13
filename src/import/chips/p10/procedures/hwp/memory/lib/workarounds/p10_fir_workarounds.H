/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/workarounds/p10_fir_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file p10_fir_workarounds.H
/// @brief Workarounds for p10 fir workaround
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#ifndef _P10_FIR_WORKAROUNDS_H_
#define _P10_FIR_WORKAROUNDS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <p10_scom_mcc.H>
#include <p10_scom_omic.H>

namespace mss
{
namespace workarounds
{
namespace fir
{

///
/// @brief Function handling the chip_ec dependent setting of USTL_USTLCFG_LOL_DOUBLEDEAD_SUPPORT_MODE
/// @param[in] i_doubledead_support value of ATTR_CHIP_EC_FEATURE_USTLCFG_LOL_DOUBLEDEAD_SUPPORT
/// @param[in,out] io_ustlcfg_data buffer for USTLCFG data
///
void set_lol_doubledead_support( const bool i_doubledead_support,
                                 fapi2::buffer<uint64_t>& io_ustlcfg_data );

///
/// @brief Function handling the chip_ec dependent setting of P10_20_USTL_USTLCFG_WRSTUCK_MITIGATION_EN_P10D20
/// @param[in] i_wrstuck_support value of ATTR_CHIP_EC_FEATURE_USTLCFG_WRSTUCK_MITIGATION
/// @param[in,out] io_ustlcfg_data buffer for USTLCFG data
///
void set_wrstuck_mitigation( const bool i_wrstuck_support,
                             fapi2::buffer<uint64_t>& io_ustlcfg_data );

///
/// @brief Function handling the chip_ec dependent setting of USTL_USTLLOLMASK
/// @param[in] i_loldrop_support value of ATTR_CHIP_EC_FEATURE_HW555009_LOLDROP
/// @param[in,out] io_ustllolmask_data buffer for USTLLOLMASK data
///
void setup_loldrop_masks( const bool i_loldrop_support,
                          fapi2::buffer<uint64_t>& io_ustllolmask_data );

///
/// @brief Function handling the chip_ec default for ATTR_OMI_CHANNEL_FAIL_ACTION
/// @param[in] i_target the MC target of the OMI channel FIRs in question
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
fapi2::ReturnCode setup_attr_omi_channel_fail_action( const fapi2::Target<fapi2::TARGET_TYPE_MC>& i_target );

///
/// @brief Function handling the subchannel FIR settings after chiplet_scominit
/// @param[in] i_target the MCC target of the DSTL fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_CHANNEL_FAIL_ACTION
/// @param[in,out] io_mcc_dstlfir_reg the DSTLFIR FIR register instance
///
void override_subchannel_firs_after_chiplet_scominit( const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
        const uint8_t i_omi_fail_action,
        mss::fir::reg<scomt::mcc::DSTL_DSTLFIR_RW>& io_mcc_dstlfir_reg );

///
/// @brief Function handling the DSTLFIR subchannel FIR settings after omi_init
/// @param[in] i_target the MCC target of the DSTL fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_CHANNEL_FAIL_ACTION
/// @param[in,out] io_mcc_dstlfir_reg the DSTLFIR FIR register instance
///
void override_dstl_subchannel_firs_after_omi_init( const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
        const uint8_t i_omi_fail_action,
        mss::fir::reg<scomt::mcc::DSTL_DSTLFIR_RW>& io_mcc_dstlfir_reg );

///
/// @brief Function handling the USTLFIR subchannel FIR settings after omi_init
/// @param[in] i_target the MCC target of the USTL fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_CHANNEL_FAIL_ACTION
/// @param[in,out] io_mcc_ustlfir_reg the USTLFIR FIR register instance
///
void override_ustl_subchannel_firs_after_omi_init( const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
        const uint8_t i_omi_fail_action,
        mss::fir::reg<scomt::mcc::USTL_USTLFIR_RW>& io_mcc_ustlfir_reg );

///
/// @brief Function handling the Cronus mode settings for DSTLFIR
/// @param[in] i_target the MCC target of the DSTL fir
/// @param[in] i_hostboot_mode true if our platform is hostboot, false if cronus
/// @param[in,out] io_mcc_dstlfir_reg the DSTLFIR FIR register instance
///
void dstl_cronus_settings( const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
                           const bool i_hostboot_mode,
                           mss::fir::reg<scomt::mcc::DSTL_DSTLFIR_RW>& io_mcc_dstlfir_reg );

///
/// @brief Function handling the OMI FIR settings after chiplet_scominit
/// @param[in] i_target the MCC target of the DSTL fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_CHANNEL_FAIL_ACTION
/// @param[in,out] io_mc_omi_fir_reg the OMI FIR register instance
///
void override_dl_fir_actions( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                              const uint8_t i_omi_fail_action,
                              mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW>& io_mc_omi_fir_reg );

///
/// @brief Function handling the MC_OMI_FIR x4 degrade FIR settings
/// @param[in] i_target the OMIC target of the MC_OMI fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_X4_DEGRADE_ACTION
/// @param[in,out] io_mc_omi_fir_reg the MC_OMI_FIR register instance
///
void override_x4_degrade_firs( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                               const uint8_t i_omi_fail_action,
                               mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW>& io_mc_omi_fir_reg );

///
/// @brief Function handling the MC_OMI_FIR CRC FIR settings
/// @param[in] i_target the OMIC target of the MC_OMI fir
/// @param[in] i_omi_crc_debug value from ATTR_OMI_CRC_DEBUG
/// @param[in,out] io_mc_omi_fir_reg the MC_OMI_FIR register instance
///
void override_omi_crc_firs( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                            const uint8_t i_omi_crc_debug,
                            mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW>& io_mc_omi_fir_reg );

///
/// @brief Function handling the MC_OMI_FIR CRC FIR settings
/// @param[in] i_target the OCMB_CHIP target of the MC_OMI fir
/// @param[in] i_omi_crc_dd1_wkrnd value from ATTR_CHIP_EC_FEATURE_OMI_CRC_FIRS
/// @param[in] i_omi_mfg_screen_crc value from check_omi_mfg_screen_crc_setting
/// @param[in,out] io_exp_dlx_omi_fir_reg the MC_OMI_FIR register instance
///
void omi_crc_after_omi_init( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                             const bool i_omi_crc_dd1_wkrnd,
                             const bool i_omi_mfg_screen_crc,
                             mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW>& io_mc_omi_fir_reg );

///
/// @brief Function handling the MC_OMI_FIR EDPL FIR settings
/// @param[in] i_target the OCMB_CHIP target of the MC_OMI fir
/// @param[in] i_omi_edpl_dd1_wkrnd value from ATTR_CHIP_EC_FEATURE_OMI_EDPL_FIRS
/// @param[in] i_omi_mfg_screen_edpl value from check_omi_mfg_screen_edpl_setting
/// @param[in,out] io_exp_dlx_omi_fir_reg the MC_OMI_FIR register instance
///
void omi_edpl_after_omi_init( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                              const bool i_omi_edpl_dd1_wkrnd,
                              const bool i_omi_mfg_screen_edpl,
                              mss::fir::reg<scomt::omic::MC_OMI_FIR_REG_RW>& io_mc_omi_fir_reg );

} // namespace fir
} // namespace workarounds
} // namespace mss

#endif
