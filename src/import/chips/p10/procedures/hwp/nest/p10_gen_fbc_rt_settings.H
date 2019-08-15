/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_gen_fbc_rt_settings.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file p10_gen_fbc_rt_settings.H
/// @brief Trigger SBE assist to apply fabric runtime settings
///

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by  : HB
//

#ifndef _P10_GEN_FBC_RT_SETTINGS_H_
#define _P10_GEN_FBC_RT_SETTINGS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_gen_fbc_rt_settings_FP_t)(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_targets,
    std::vector<std::pair<uint64_t, uint64_t>>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{

///
/// @brief Trigger SBE assist to apply fabric runtime settings
///
/// @param[in] i_targets   Collection of processor chip targets in drawer scope
/// @param[in] o_reg_inits Set of register inits to be performed via XSCOM
///                        Each pair is expected to contain a fully
///                        formed XSCOM address (first) + associated data
///                        (second)
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_gen_fbc_rt_settings(
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_targets,
        std::vector<std::pair<uint64_t, uint64_t>>& o_reg_inits);

} // extern "C"

#endif // _P10_GEN_FBC_RT_SETTINGS_H_
