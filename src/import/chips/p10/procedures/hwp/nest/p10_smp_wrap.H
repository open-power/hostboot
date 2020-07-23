/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_smp_wrap.H $     */
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
/// @file p10_smp_wrap.H
/// @brief Perform fabric/link reconfiguration for smp wrap mode (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: Cronus
///

#ifndef _P10_SMP_WRAP_H_
#define _P10_SMP_WRAP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// mfg flags attribute constants
const uint8_t MFG_FLAGS_SMP_WRAP_CELL = 3;

// HWP argument to define smp wrap mode
enum p10_smp_wrap_mode
{
    MODEA = 0,
    MODEB = 1,
    MODEC = 2,
    MODEV = 3, // vbu sim
    MODEW = 4, // vbu sim
    MODEX = 5, // vbu sim
};

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_smp_wrap_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const enum p10_smp_wrap_mode);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Determine whether manufacturing flags indicate smp wrap config
///
/// @param[out] o_smp_wrap_config   True if mfg flags indicate smp wrap config
/// @return fapi::ReturnCode        FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_smp_wrap_mfg_mode(
        bool& o_smp_wrap_mode);

///
/// @brief Perform fabric/link reconfiguration for smp wrap mode
///
/// @param[in] i_target             Reference to processor chip target
/// @param[in] i_wrap_mode          Enumerated type representing SMP wrap mode
/// @return fapi::ReturnCode        FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_smp_wrap(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const enum p10_smp_wrap_mode i_wrap_mode);

} // extern "C"

#endif // _P10_SMP_WRAP_H_
