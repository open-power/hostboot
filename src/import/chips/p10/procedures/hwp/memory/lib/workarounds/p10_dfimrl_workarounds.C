/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/workarounds/p10_dfimrl_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2024                        */
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
/// @file p10_dfimrl_workarounds.C
/// @brief Workarounds for p10 DFIMRL workaround
// *HWP HWP Owner: Sneha Kadam <Sneha.Kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>

#include <lib/workarounds/p10_dfimrl_workarounds.H>

namespace mss
{
namespace workarounds
{
namespace eff_config
{

///
/// @brief Updates the DFIMRL register on an OCMB chip
/// @param[in] i_target the fapi2::Target for the OCMB chip
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode config_dfimrl(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    constexpr uint8_t  EFFECTED_HEIGHT = fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U;
    constexpr uint64_t EFFECTED_FREQ   = 4800;
    constexpr uint8_t  DFIMRL_VALUE = 2;

    // Reads out the dimm height attribute and the DRAM frequency attribute
    uint8_t l_dimm_height = 0;
    uint64_t l_freq = 0;
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_MODULE_HEIGHT, l_ocmb, l_dimm_height));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_FREQ, i_target, l_freq));

    // If DIMM height is 2U and the DRAM frequency is 4800, update the DFIMRL margin to 2
    if(l_dimm_height == EFFECTED_HEIGHT && l_freq == EFFECTED_FREQ)
    {
        FAPI_TRY(FAPI_ATTR_SET_CONST(fapi2::ATTR_ODY_PHY_DFIMRL_MARGIN, i_target, DFIMRL_VALUE));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace eff_config
} // namespace workarounds
} // namespace mss
