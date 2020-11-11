/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_get_freq_compat_settings.C $ */
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
/// @file  p10_get_freq_compat_settings.C
/// @brief Se the pstate0 and nominal freq
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : HWSV
///
/// @verbatim
/// Procedure Summary:
///   - Read VPD value of each proc and compute system pstate0 and nominal frequency.
/// @endverbatim
// EKB-Mirror-To: hostboot

// *INDENT-OFF*
//
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------


#include <fapi2.H>
#include "p10_get_freq_compat_settings.H"
#include <p10_pm_utils.H>


///////////////////////////////////////////////////////////
////////    p10_get_freq_compat_settings 
///////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_get_freq_compat_settings(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_targ,
                             uint32_t *o_pstate0)
{
    FAPI_DBG("> p10_get_freq_compat_settings");
    fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ_Type l_sys_pstate0_freq_mhz = 0;

    do
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ,
                i_sys_targ,l_sys_pstate0_freq_mhz));

        *o_pstate0 = l_sys_pstate0_freq_mhz;
    }
    while(0);

fapi_try_exit:
    return fapi2::current_err;
}


// *INDENT-ON*
