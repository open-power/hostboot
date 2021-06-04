/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_fir_workarounds.H $ */
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
/// @file exp_fir_workarounds.H
/// @brief Workarounds for Explorer FIR settings
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#ifndef _EXP_FIR_WORKAROUNDS_H_
#define _EXP_FIR_WORKAROUNDS_H_

#include <fapi2.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <lib/fir/exp_fir_traits.H>

namespace mss
{
namespace exp
{
namespace workarounds
{
namespace fir
{

///
/// @brief Function handling the MC_OMI_FIR x4 degrade FIR settings
/// @param[in] i_target the OCMB_CHIP target of the MC_OMI fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_X4_DEGRADE_ACTION
/// @param[in,out] io_exp_mc_omi_fir_reg the MC_OMI_FIR register instance
///
void override_x4_degrade_fir( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              const uint8_t i_omi_fail_action,
                              mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG>& io_exp_mc_omi_fir_reg );

///
/// @brief Function handling the MC_OMI_FIR CRC FIR settings
/// @param[in] i_target the OCMB_CHIP target of the MC_OMI fir
/// @param[in] i_omi_crc_debug value from ATTR_OMI_CRC_DEBUG
/// @param[in,out] io_exp_mc_omi_fir_reg the MC_OMI_FIR register instance
///
void override_omi_crc_firs( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                            const uint8_t i_omi_crc_debug,
                            mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG>& io_exp_mc_omi_fir_reg );

///
/// @brief Function handling the MC_OMI_FIR CRC FIR settings
/// @param[in] i_target the OCMB_CHIP target of the MC_OMI fir
/// @param[in] i_omi_crc_dd1_wkrnd value from ATTR_CHIP_EC_FEATURE_OMI_CRC_FIRS
/// @param[in] i_omi_mfg_screen_crc value from check_omi_mfg_screen_crc_setting
/// @param[in,out] io_exp_dlx_omi_fir_reg the MC_OMI_FIR register instance
///
void omi_crc_after_omi_init( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                             const bool i_omi_crc_dd1_wkrnd,
                             const bool i_omi_mfg_screen_crc,
                             mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG>& io_exp_dlx_omi_fir_reg );

///
/// @brief Function handling the MC_OMI_FIR EDPL FIR settings
/// @param[in] i_target the OCMB_CHIP target of the MC_OMI fir
/// @param[in] i_omi_edpl_dd1_wkrnd value from ATTR_CHIP_EC_FEATURE_OMI_EDPL_FIRS
/// @param[in] i_omi_mfg_screen_edpl value from check_omi_mfg_screen_edpl_setting
/// @param[in,out] io_exp_dlx_omi_fir_reg the MC_OMI_FIR register instance
///
void omi_edpl_after_omi_init( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              const bool i_omi_edpl_dd1_wkrnd,
                              const bool i_omi_mfg_screen_edpl,
                              mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG>& io_exp_dlx_omi_fir_reg );

} // fir
} // workarounds
} // exp
} // mss

#endif
