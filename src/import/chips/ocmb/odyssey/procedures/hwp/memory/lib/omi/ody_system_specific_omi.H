/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/omi/ody_system_specific_omi.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_system_specific_omi.H
/// @brief OMI EC Feature template check P10
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB


#ifndef _ODY_SYSTEM_SPECIFIC_OMI_H_
#define _ODY_SYSTEM_SPECIFIC_OMI_H_

#include <fapi2.H>
#include <generic/memory/proc_specific/mss_target_abstractions.H>

namespace mss
{
namespace omi
{
///
/// @brief Retrieves ec feature template from attr p10 specific
/// @param[in] i_proc PROC Chip we are operating on
/// @param[in,out] io_us_only_0159 EC FEATURE TEMPLATE VALUE
/// @return fapi2::FAPI2_RC_SUCCESS
///
fapi2::ReturnCode get_us_template_support(const fapi2::Target<PROC_TYPE>& i_proc,
        uint8_t& io_us_only_0159)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_US_TEMPLATES_0159,
                           i_proc,
                           io_us_only_0159),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_US_TEMPLATES_0159)");

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Retrieves ec feature template from attr p10 specific
/// @param[in] i_proc PROC Chip we are operating on
/// @param[in,out] io_ds_only_0147 EC FEATURE TEMPLATE VALUE
/// @return fapi2::FAPI2_RC_SUCCESS
///
fapi2::ReturnCode get_ds_template_support(const fapi2::Target<PROC_TYPE>& i_proc,
        uint8_t& io_ds_only_0147)
{
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_DS_TEMPLATES_0147,
                           i_proc,
                           io_ds_only_0147),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_US_TEMPLATES_0147)");

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}
} // namespace omi
} // namespace mss

# endif
