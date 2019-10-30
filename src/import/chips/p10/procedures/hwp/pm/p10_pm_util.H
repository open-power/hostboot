/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_util.H $        */
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
/// @file  p10_pm_util.H
/// @brief Get deconfigured core target list from ATTR_PG_MVPD
///        and ATTR_PG attribute
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
///
#ifndef _P10_PM_UTIL_H_
#define _P10_PM_UTIL_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*getDeconfiguredTargets_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE> >&);

// -----------------------------------------------------------------------------
//  Function prototype
// -----------------------------------------------------------------------------
extern "C" {

/// @addtogroup pm_fapi
/// @{

/// @brief Get deconfigured core targets
///
/// @param [in] i_target    Chip target
/// @param [out] o_list     core target list
///
/// @retval FAPI2_RC_SUCCESS on success, else error RC
///
    fapi2::ReturnCode getDeconfiguredTargets(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE> >& o_list);

/// @}  end addtogroup

} // extern "C"

#endif // _P10_PM_UTIL_H_
