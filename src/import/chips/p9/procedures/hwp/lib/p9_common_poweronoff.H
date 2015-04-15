/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_common_poweronoff.H $ */
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
/// @file  p9_common_poweronoff.H
/// @brief common procedure for power on/off
///
/// *HWP HWP Owner   : David Du      <daviddu@us.ibm.com>
/// *HWP FW Owner    : Reshmi Nair   <resnair5@in.ibm.com>
/// *HWP Team        : PM
/// *HWP Consumed by : SBE:SGPE:CME
/// *HWP Level       : 1
///

#ifndef __P9_COMMON_POWERONOFF_H__
#define __P9_COMMON_POWERONOFF_H__

extern "C"
{

/// @typedef p9_common_proweronoff_FP_t
/// function pointer typedef definition for HWP call support
    typedef fapi2::ReturnCode (*p9_common_proweronoff_FP_t) (
        const fapi2::Target < fapi2::TARGET_TYPE_EQ |
        fapi2::TARGET_TYPE_CORE > &,
        int);


/// @brief common procedure for power on/off
///
/// @param [in] i_target    TARGET_TYPE_EQ|TARGET_TYPE_CORE target
/// @param [in] i_operation ENUM(ON,OFF)
///
/// @attr
/// @attritem ATTR_PFET_TIMING - EX target, uint32
///
/// @retval FAPI_RC_SUCCESS
    fapi2::ReturnCode
    p9_common_proweronoff(
        const fapi2::Target < fapi2::TARGET_TYPE_EQ |
        fapi2::TARGET_TYPE_CORE > & i_target,
        int i_operation);


} // extern C

#endif  // __P9_COMMON_POWERONOFF_H__
