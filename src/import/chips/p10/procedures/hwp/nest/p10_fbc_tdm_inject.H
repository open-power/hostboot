/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_tdm_inject.H $ */
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
/// @file p10_fbc_tdm_inject.H
/// @brief Force TDM entry on IOHS link (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: FSP
///

#ifndef _P10_FBC_TDM_INJECT_H_
#define _P10_FBC_TDM_INJECT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

enum p10_fbc_tdm_inject_step_t
{
    P10_FBC_TDM_INJECT_CONFIRM_PARTNER    = 0,
    P10_FBC_TDM_INJECT_MASK_FIRS          = 1,
    P10_FBC_TDM_INJECT_ENTER_TDM          = 2,
    P10_FBC_TDM_INJECT_CONFIRM_HALF       = 3,
    P10_FBC_TDM_INJECT_RECAL_STOP         = 4,
    P10_FBC_TDM_INJECT_CONFIRM_RECAL_STOP = 5,
    P10_FBC_TDM_INJECT_PARTIAL_RESET      = 6,
    P10_FBC_TDM_INJECT_PHY_POWERDOWN      = 7,
    P10_FBC_TDM_INJECT_END                = 8
};

// Flags controlling HWP behavior
// run_all = true:  HWP will run all injections steps
// run_all = false: User input (step) determines single injection step to run
struct p10_fbc_tdm_inject_opt_t
{
    bool run_all;
    p10_fbc_tdm_inject_step_t step;
};

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_fbc_tdm_inject_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&,
    const bool,
    const p10_fbc_tdm_inject_opt_t&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Disable selected half link, non-selected half link will enter TDM
///        (half-width) mode.
///
/// @param[in] i_target         Reference to IOHS endpoint target to operate on
/// @param[in] i_even_not_odd   Identify half-link to disable (true=even,false=odd)
/// @param[in] i_opts           HWP option structure, see struct definition
///                             for description of function
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_fbc_tdm_inject(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const bool i_even_not_odd,
        const p10_fbc_tdm_inject_opt_t& i_opts);

} // extern "C"

#endif // _P10_FBC_TDM_INJECT_H_
