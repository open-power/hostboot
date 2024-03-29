/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_pba_bar_config.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file p10_pm_pba_bar_config.H
///
/// @brief Initialize PAB and PAB_MSK of PBA
///
// *HWP HWP Owner: Greg Still <stillgs @us.ibm.com>
// *HWP FW Owner:  Prem Shanker Jha <premjha2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 3
// *HWP Consumed by: HS
//

#ifndef _P10_PM_PBA_CONFIG_H_
#define _P10_PM_PBA_CONFIG_H_

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_pm_pba_init.H>

///
/// @brief Determine if a number is a power of two or not
///
/// @param [in] i_value        Input number
/// @return True if value is a power of two
///         False otherwise.
///
inline bool isPowerOfTwo (uint64_t i_value);

///
/// @brief Round up to next higher power of 2
///
/// @param [in] i_value        Input value
/// @return Next higher power of 2 of i_value.
///         If i_value is already a power of 2, return i_value.
///
uint64_t PowerOf2Roundedup (uint64_t i_value);

// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pm_pba_bar_config_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const uint32_t,
 const uint64_t,
 const uint64_t,
 const p10pba::CMD_SCOPE,
 const uint16_t);

extern "C"
{

// -----------------------------------------------------------------------------
//  Function prototype
// -----------------------------------------------------------------------------

///
/// @brief Initialize PBA_BAR (cmd_scope & address) and PBA_BARMSK (mask/size)
///
/// @param [in] i_target        Reference to Proc chip target
/// @param [in] i_index         Identifies the set of BAR/BARMSK registers [0-3]
/// @param [in] i_pba_bar_addr  PBA base address - 1MB granularity
/// @param [in] i_pba_bar_size  PBA region size in MB; If not a power of two,
///                             the value will be rounded up to the next power
///                             of 2 for setting hardware mask
/// @param [in] i_pba_cmd_scope Command scope according to pba spec
/// @param [in] i_vectorTarget  Indicates which target should be searched for
///                             the information when the command scope specified
///                             is "Vectored".
///                             Possible Values      : Significance
///                             ------------------------------------------------
///                             FF                   : PBA will always drive
///                                                    Target value to FF
///                             Values other than FF : PBA will update Target
///                                                    value based on the CRESP
///                                                    of the request
///
/// @return FAPI_RC_SUCCESS on success or error return code
///
    fapi2::ReturnCode p10_pm_pba_bar_config(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint32_t i_index,
        const uint64_t i_pba_bar_addr,
        const uint64_t i_pba_bar_size,
        const p10pba::CMD_SCOPE i_pba_cmd_scope,
        const uint16_t i_vectorTarget);
}

#endif // _P10_PM_PBA_CONFIG_H_
