/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/checker.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file checker.C
/// @brief Contains common functions that perform checks
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/mss_attribute_accessors.H>

namespace mss
{
namespace check
{

///
/// @brief Checks to make sure ATTR_MSS_MRW_TEMP_REFRESH_MODE and ATTR_MSS_MRW_FINE_REFRESH_MODE are set correctly
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note from DDR4 DRAM Spec (79-4B) 4.9.4 page 48
///
fapi2::ReturnCode temp_refresh_mode()
{
    uint8_t l_temp_refresh = 0;
    uint8_t l_refresh_mode = 0;

    FAPI_TRY( mrw_fine_refresh_mode (l_refresh_mode));
    FAPI_TRY( mrw_temp_refresh_mode (l_temp_refresh));

    // If the temperature refresh mode is enabled, only the normal mode (Fixed 1x mode; MRS4 A8:A7:A6= 000) is allowed for the fine refresh mode
    // Per JEDEC DDR4 DRAM spec from 07-2016 page 48 section 4.9.4
    if ( l_temp_refresh == fapi2::ENUM_ATTR_MSS_MRW_TEMP_REFRESH_MODE_ENABLE)
    {
        FAPI_ASSERT( (l_refresh_mode == fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL),
                     fapi2::MSS_INVALID_FINE_REFRESH_MODE_WITH_TEMP_REFRESH_MODE_ENABLED()
                     .set_FINE_REF_MODE(l_refresh_mode)
                     .set_TEMP_REF_MODE(l_temp_refresh),
                     "Incorrect setting for ATTR_MSS_MRW_FINE_REFRESH_MODE (%d) if ATTR_MSS_MRW_TEMP_REFRESH_MODE is enabled",
                     l_refresh_mode);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
};

}
}
