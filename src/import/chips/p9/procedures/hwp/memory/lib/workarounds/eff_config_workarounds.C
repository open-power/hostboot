/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/eff_config_workarounds.C $ */
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


#include <fapi2.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/workarounds/eff_config_workarounds.H>

namespace mss
{

namespace workarounds
{

namespace eff_config
{

///
/// @brief Checks if the NVDIMM RC drive strength workaround is needed
/// @param[in] i_target DIMM target on which to operate
/// @param[out] o_is_needed true if the workaround is needed
/// @return SUCCESS if the code executes successfully
///
fapi2::ReturnCode is_nvdimm_rc_drive_strength_needed(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool& o_is_needed)
{
    o_is_needed = false;

    uint8_t l_hybrid = 0;
    uint8_t l_hybrid_type = 0;
    uint32_t l_size = 0;

    FAPI_TRY(mss::eff_hybrid(i_target, l_hybrid));
    FAPI_TRY(mss::eff_hybrid_memory_type(i_target, l_hybrid_type));
    FAPI_TRY(mss::eff_dimm_size(i_target, l_size));

    if(l_hybrid == fapi2::ENUM_ATTR_EFF_HYBRID_IS_HYBRID &&
       l_hybrid_type == fapi2::ENUM_ATTR_EFF_HYBRID_MEMORY_TYPE_NVDIMM &&
       l_size == fapi2::ENUM_ATTR_EFF_DIMM_SIZE_32GB)
    {
        o_is_needed = true;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Updates the RC drive strength if the workaround is needed
/// @param[in] i_target DIMM target on which to operate
/// @param[in] i_override_value the value to override if the workaround needs to be applied
/// @param[in,out] io_rc_value Register Control word value to update
/// @return SUCCESS if the code executes successfully
///
fapi2::ReturnCode nvdimm_rc_drive_strength(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_override_value,
        fapi2::buffer<uint8_t>& io_rc_value)
{
    bool l_is_needed = false;
    FAPI_TRY(is_nvdimm_rc_drive_strength_needed(i_target, l_is_needed));

    // If the workaround is needed, overwrite it to be ALL_MODERATE values
    // Otherwise keep it as it is
    io_rc_value = l_is_needed ? fapi2::buffer<uint8_t>(i_override_value) : io_rc_value;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns eff_config
} // ns workarounds
} // ns mss
