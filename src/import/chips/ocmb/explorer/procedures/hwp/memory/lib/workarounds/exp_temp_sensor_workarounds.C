/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_temp_sensor_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file exp_temp_sensor_workarounds.C
/// @brief Workarounds for 4U temp sensor usage based on MRW attr
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_attribute_setters.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_explorer_attribute_setters.H>
#include <mss_generic_system_attribute_getters.H>

namespace mss
{
namespace exp
{
namespace workarounds
{

///
/// @brief Changes temp sensor usage depending on MRW attr and height of DIMM
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note 4U DDIMMs would use MEMCTRL, MC_EXT, and MC_DRAM sensor types
/// (where MC_EXT is really PMIC, and MC_DRAM is really DIMM).
/// Helper function to unit test this functionality
///
fapi2::ReturnCode change_temp_sensor_usage_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint8_t l_module_height = 0;
    uint8_t l_sensor_0_usage = 0;
    uint8_t l_sensor_1_usage = 0;

    FAPI_TRY(mss::attr::get_dram_module_height(i_target, l_module_height));

    if (l_module_height != fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U)
    {
        FAPI_INF("Skipping as height is not 4U %s", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(mss::attr::get_therm_sensor_0_usage(i_target, l_sensor_0_usage));
    FAPI_TRY(mss::attr::get_therm_sensor_1_usage(i_target, l_sensor_1_usage));

    if (l_sensor_0_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DRAM)
    {
        FAPI_DBG("%s Changing temperature sensor 0 usage from DRAM to DRAM_AND_MEM_BUF_EXT",
                 mss::c_str(i_target));
        FAPI_TRY(mss::attr::set_therm_sensor_0_usage(i_target,
                 fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DRAM_AND_MEM_BUF_EXT));
    }
    else if (l_sensor_0_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_PMIC)
    {
        FAPI_DBG("%s Changing temperature sensor 0 usage from PMIC to MEM_BUF_EXT",
                 mss::c_str(i_target));
        FAPI_TRY(mss::attr::set_therm_sensor_0_usage(i_target, fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_MEM_BUF_EXT));
    }

    if (l_sensor_1_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_1_USAGE_DRAM)
    {
        FAPI_DBG("%s Changing temperature sensor 1 usage from DRAM to DRAM_AND_MEM_BUF_EXT",
                 mss::c_str(i_target));
        FAPI_TRY(mss::attr::set_therm_sensor_1_usage(i_target,
                 fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_1_USAGE_DRAM_AND_MEM_BUF_EXT));
    }
    else if (l_sensor_1_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_1_USAGE_PMIC)
    {
        FAPI_DBG("%s Changing temperature sensor 1 usage from PMIC to MEM_BUF_EXT",
                 mss::c_str(i_target));
        FAPI_TRY(mss::attr::set_therm_sensor_1_usage(i_target, fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_1_USAGE_MEM_BUF_EXT));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Changes temp sensor usage depending on MRW attr and height of DIMM
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note 4U DDIMMs would use MEMCTRL, MC_EXT, and MC_DRAM sensor types
/// (where MC_EXT is really PMIC, and MC_DRAM is really DIMM)
///
fapi2::ReturnCode change_temp_sensor_usage(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint8_t l_therm_sensor_override = 0;

    FAPI_TRY(mss::attr::get_mrw_orverride_therm_sensor_usage(l_therm_sensor_override));

    if (l_therm_sensor_override == fapi2::ENUM_ATTR_MSS_MRW_OVERRIDE_THERM_SENSOR_USAGE_ENABLED)
    {
        FAPI_TRY(change_temp_sensor_usage_helper(i_target));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // workarounds
} // exp
} // mss
