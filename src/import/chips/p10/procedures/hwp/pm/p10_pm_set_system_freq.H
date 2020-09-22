/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_set_system_freq.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

#ifndef __P10_PM_SYSTEM_SET_FREQ_H__
#define __P10_PM_SYSTEM_SET_FREQ_H__

#include <fapi2.H>
#include "p10_pm_get_poundv_bucket.H"


/// @typedef p10_pm_set_system_freq_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pm_set_system_freq_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_targ);


extern "C"
{

    /// -------------------------------------------------------------------
    /// @brief Set system pstate0 and nominal freq
    /// @return   FAPI2::SUCCESS
    /// -------------------------------------------------------------------
    fapi2::ReturnCode
    p10_pm_set_system_freq(
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_targ);

} // extern C


#endif  // __P10_PM_SYSTEM_SET_FREQ_H__
