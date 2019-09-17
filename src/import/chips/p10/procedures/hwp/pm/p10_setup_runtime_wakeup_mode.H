/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_setup_runtime_wakeup_mode.H $ */
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

#ifndef __RUN_TIME_WAKEUP_MODE_
#define __RUN_TIME_WAKEUP_MODE_

///
/// @file   p10_setup_runtime_wakeup_mode.H
/// @brief  describes HWP interface that configures runtime wakeup mode of core.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    Hostboot
//


#include <fapi2.H>

extern "C"
{

    typedef fapi2::ReturnCode( *p10_setup_runtime_wakeup_mode_FP_t ) (
        const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget );

    /// @brief      sets runtime wakeup mode for all functional cores in the proc.
    /// @param[in]  i_procTarget        fapi2 target for P9 chip.
    /// @return     FAPI2_RC_SUCCESS    if HWP succeeds, error code otherwise.
    fapi2::ReturnCode p10_setup_runtime_wakeup_mode( const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget );

} //extern "C"

#endif  //__RUN_TIME_WAKEUP_MODE_
