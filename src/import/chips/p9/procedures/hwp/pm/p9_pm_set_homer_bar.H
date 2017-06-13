/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_set_homer_bar.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

/// @file  p9_pm_set_homer_bar.H
/// @brief Set/reset the BLOCK_REG_WKUP_SOURCES bit in the PPM
///         associated with an EX chiplet

// *HWP Owner           : Greg Still <stillgs@us.ibm.com>
// *HWP Backup Owner    : Prasad BGR <prasadbgr.in.ibm.com>
// *HWP FW Owner        : Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 3
// *HWP Consumed by     : HS
///
///-----------------------------------------------------------------------------

#ifndef _P9_SET_HOMER_BAR_H_
#define _P9_SET_HOMER_BAR_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_set_homer_bar_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const uint64_t,
    const uint64_t);


extern "C"
{
//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \param[in] i_target     Procesor Chip target
/// \param[in] i_mem_bar    Base address of the region where image is located
/// \param[in] i_mem_size   Size (in MB) of the region where image is located
///                         if not a power of two value, the value will be
///                         rounded up to the next power of 2 for setting the
///                         hardware mask

    fapi2::ReturnCode p9_pm_set_homer_bar(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_mem_bar,
        const uint64_t i_mem_size);

}//extern
#endif // _P9_SET_HOMER_BAR_H_
