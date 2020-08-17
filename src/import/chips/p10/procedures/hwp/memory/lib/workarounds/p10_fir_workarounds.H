/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/workarounds/p10_fir_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

namespace mss
{
namespace workarounds
{
namespace fir
{

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

} // namespace fir
} // namespace workarounds
} // namespace mss

#endif
