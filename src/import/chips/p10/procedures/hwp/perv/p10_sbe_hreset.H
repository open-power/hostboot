/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_sbe_hreset.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
//------------------------------------------------------------------------------
/// @file  p10_sbe_hreset.H
///
/// @brief Restart SBE runtime
//------------------------------------------------------------------------------
// *HWP HW Owner        : Manish Chowdhary <manichow@in.ibm.com>
// *HWP HW Backup Owner : Rajees Rahman <rajerpp1@in.ibm.com>
// *HWP FW Owner        : Manish Chowdhary <manichow@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------
#ifndef _p10_SBE_HRESET_H_
#define _p10_SBE_HRESET_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

/// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_sbe_hreset_FP_t)(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
        bool);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/// @brief Issuing an HRESET to restart SBE code execution
///
/// @param[in]     i_target         Reference to TARGET_TYPE_PROC_CHIP target
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p10_sbe_hreset(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        bool i_is_fsp = false);
}

#endif
