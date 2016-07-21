/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/cache/p9_hcd_l2_stopclocks.H $ */
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
///
/// @file  p9_hcd_l2_stopclocks.H
/// @brief Quad Clock Stop
///

// *HWP HWP Owner          : David Du       <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still     <stillgs@us.ibm.com>
// *HWP FW Owner           : Sangeetha T S  <sangeet2@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : HB:PERV
// *HWP Level              : 2

#ifndef __P9_HCD_L2_STOPCLOCKS_H__
#define __P9_HCD_L2_STOPCLOCKS_H__

#include <fapi2.H>

/// @typedef p9_hcd_l2_stopclocks_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_hcd_l2_stopclocks_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>&,
    const p9hcd::P9_HCD_EX_CTRL_CONSTANTS);

extern "C"
{

/// @brief Quad Clock Stop
/// @param [in] i_target TARGET_TYPE_EQ target
/// @return FAPI2_RC_SUCCESS if success, else error code
    fapi2::ReturnCode
    p9_hcd_l2_stopclocks(
        const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
        const p9hcd::P9_HCD_EX_CTRL_CONSTANTS       i_select_ex);

}

#endif  // __P9_HCD_L2_STOPCLOCKS_H__
