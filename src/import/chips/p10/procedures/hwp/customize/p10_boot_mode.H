/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_boot_mode.H $ */
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
//------------------------------------------------------------------------------
/// @file  p10_boot_mode.H
/// @brief Calculate and return set of dynamic init features to be applied
///        at image customization time
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer   : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------

#ifndef _P10_BOOT_MODE_H_
#define _P10_BOOT_MODE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_dyninit_bitvec.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_boot_mode_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    void* const,
    uint8_t,
    p10_dyninit_bitvec&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Calculate and return set of dynamic init features to be applied
///        at image customization time
///
/// @param[in] i_target_chip     Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in] i_hw_image        Pointer to HW image
/// @param[in] i_sys_phase       {HB_SBE,RT_QME,HB_MEAS}
/// @param[out] o_feature_bvec   Dynamic init feature bit vector
///
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_boot_mode(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
        void* const i_hw_image,
        uint8_t i_sys_phase,
        p10_dyninit_bitvec& o_feature_bvec);
}

#endif // _P10_BOOT_MODE_H_
