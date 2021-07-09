/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_async_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file p10_fbc_utils.H
/// @brief Fabric async boundary crossing utility functions (FAPI2)
///
/// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///
// EKB-Mirror-To: hostboot

#ifndef _P10_FBC_ASYNC_UTILS_H_
#define _P10_FBC_ASYNC_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

enum rt2pa_ratio
{
    RT2PA_RATIO_NOMINAL,
    RT2PA_RATIO_SAFE
};

enum pa2rt_ratio
{
    PA2RT_RATIO_TURBO,
    PA2RT_RATIO_NOMINAL,
    PA2RT_RATIO_SAFE
};

enum rt2mc_ratio
{
    RT2MC_RATIO_ULTRATURBO,
    RT2MC_RATIO_TURBO,
    RT2MC_RATIO_NOMINAL,
    RT2MC_RATIO_SAFE
};

enum mc2rt_ratio
{
    MC2RT_RATIO_ULTRATURBO,
    MC2RT_RATIO_TURBO,
    MC2RT_RATIO_NOMINAL,
    MC2RT_RATIO_SAFE
};

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

///
/// @brief Calculate PAU interface async ratio settings
/// @param[in]  i_target_sys     Reference to system target
/// @param[out] o_rt2pa          Racetrack-to-PAU ratio
/// @param[out] o_pa2rt          PAU-to-racetrack ratio
/// @return fapi::ReturnCode     FAPI2_RC_SUCCESS on success, error otherwise
///
fapi2::ReturnCode p10_fbc_async_utils_calc_pau_ratios(
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
    rt2pa_ratio& o_rt2pa,
    pa2rt_ratio& o_pa2rt);

///
/// @brief Calculate MC interface async ratio settings
/// @param[in]  i_target_proc    Reference to processor chip target
/// @param[in]  i_target_sys     Reference to system target
/// @param[in]  o_mc_freq_mhz    MC mesh clock frequency, in MHz
/// @param[out] o_rt2mc          Racetrack-to-MC ratio
/// @param[out] o_mc2rt          MC-to-racetrack ratio
/// @return fapi::ReturnCode     FAPI2_RC_SUCCESS on success, error otherwise
///
fapi2::ReturnCode p10_fbc_async_utils_calc_mc_ratios(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_proc,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
    uint32_t& o_mc_freq_mhz,
    rt2mc_ratio& o_rt2mc,
    mc2rt_ratio& o_mc2rt);


#endif // _P10_FBC_ASYNC_UTILS_H_
