/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_query_core_stop_state.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file  p10_query_core_stop_state.H
/// @brief query current stop state of core
///
/// *HWP HWP Owner          : David Du      <daviddu@us.ibm.com>
/// *HWP Backup HWP Owner   : Greg Still    <stillgs@us.ibm.com>
/// *HWP FW Owner           : RANGANATHPRASAD G. BRAHMASAMUDRA <prasadbgr@in.ibm.com>
/// *HWP Team               : PM
/// *HWP Consumed by        : SBE:CRO
/// *HWP Level              : 2
///

#ifndef __P10_QUERY_CORE_STOP_STATE_H__
#define __P10_QUERY_CORE_STOP_STATE_H__

#include <fapi2.H>

/// @typedef p10_query_core_stop_state_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_query_core_stop_state_FP_t) (
    const fapi2::Target <fapi2::TARGET_TYPE_CORE >&,
    const uint32_t);


extern "C"
{

/// @brief query current stop state of core
///
/// @param [in]  i_target              TARGET_TYPE_CORE target
/// @param [out] i_expected_stop_level [2-15]
///
/// @retval FAPI_RC_SUCCESS
    fapi2::ReturnCode
    p10_query_core_stop_state(
        const fapi2::Target <fapi2::TARGET_TYPE_CORE>& i_target,
        const uint32_t i_expected_stop_level);

} // extern C

#endif  // __P10_QUERY_CORE_STOP_STATE_H__
