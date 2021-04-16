/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_smp_link_firs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_smp_link_firs.H
/// @brief Setup the FIR mask and action registers for a given SMP link
///
/// The purpose of this procedure is to setup the necessary FIR mask/action
/// registers for the requested operational state on a given SMP link. The
/// FIRs can be setup for either an unused link or for a runtime state. It
/// can also be used to clear all related FIR registers -- this zeroes all
/// bits in the FIR itself and leaves the mask/action registers untouched.
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
/// *HWP Consumed by: SBE
///

#ifndef _P10_SMP_LINK_FIRS_H_
#define _P10_SMP_LINK_FIRS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// SMP FIR Action Types
//   INACTIVE:  Mask FIR bits associated with the link
//   RUNTIME:   Unmask FIR bits associated with the link
//   CLEAR_ALL: Reset all FIR values to zero (including link trained bits)
//   CLEAR_ERR: Reset FIRs associated with errors (preserves link trained bits)
enum action_t
{
    INACTIVE  = 0,
    RUNTIME   = 1,
    CLEAR_ALL = 2,
    CLEAR_ERR = 3,
};

enum sublink_t
{
    BOTH_PAUE        = 0,
    BOTH_PAUO        = 1,
    BOTH_PAUS        = 2,
    EVEN_PAUE        = 3,
    EVEN_PAUO        = 4,
    ODD_PAUE         = 5,
    ODD_PAUO         = 6,
    NUM_SUBLINK_OPTS = 7,
    NONE             = 8,
};

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_smp_link_firs_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&,
    sublink_t,
    action_t,
    bool);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Setup the FIR mask and action registers for a given SMP link
///
/// @param[in] i_iohs_target        Reference to IOHS target
/// @param[in] i_sublink            Sub-link to apply settings to
/// @param[in] i_action             Operational state to configure the FIRs for
/// @param[in] i_mask_dl_lane_errs  Mask DL lane errors, used for HW561216
///
/// @return FAPI_RC_SUCCESS if the setup completes successfully, else error code.
///
    fapi2::ReturnCode p10_smp_link_firs(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
        sublink_t i_sublink,
        action_t i_action,
        bool i_mask_dl_lane_errs);

} //extern "C"

#endif //_P10_SMP_LINK_FIRS_H_
