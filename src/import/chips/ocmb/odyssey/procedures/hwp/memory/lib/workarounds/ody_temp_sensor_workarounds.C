/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_temp_sensor_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file ody_temp_sensor_workarounds.C
/// @brief Workarounds for 4U temp sensor usage based on MRW attr
///
// *HWP HWP Owner: Preetham H R <preeragh@in.ibm.com>
// *HWP HWP Backup: Md Yasser <mohammed.yasser11@ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/shared/ody_consts.H>
#include <lib/power_thermal/ody_thermal_init_utils.H>

namespace mss
{
namespace ody
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
    uint8_t l_sensor_usage = fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DISABLED;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_MODULE_HEIGHT, i_target, l_module_height));

    if (l_module_height != fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U)
    {
        FAPI_INF_NO_SBE("Skipping " GENTARGTIDFORMAT " as height is not 4U", GENTARGTID(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for(uint8_t l_sensor_index = 0; l_sensor_index < NUM_DTS; l_sensor_index++ )
    {
        FAPI_TRY(mss::ody::thermal::get_therm_sensor_usage[l_sensor_index](i_target,
                 l_sensor_usage));

        if (l_sensor_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DRAM)
        {
            FAPI_DBG(" " GENTARGTIDFORMAT " Changing temperature sensor %d usage from DRAM to DRAM_AND_MEM_BUF_EXT",
                     GENTARGTID(i_target), l_sensor_index);
            FAPI_TRY(mss::ody::thermal::set_therm_sensor_usage[l_sensor_index](i_target,
                     fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DRAM_AND_MEM_BUF_EXT));

        }
        else if (l_sensor_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_PMIC)
        {
            FAPI_DBG(" " GENTARGTIDFORMAT " Changing temperature sensor %d usage from PMIC to MEM_BUF_EXT",
                     GENTARGTID(i_target), l_sensor_index);
            FAPI_TRY(mss::ody::thermal::set_therm_sensor_usage[l_sensor_index](i_target,
                     fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_MEM_BUF_EXT));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Disables DIMM Thermal sensor that are not configured to use
/// @param[in] i_target ocmb target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode disable_unused_temp_sensor(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    static constexpr uint8_t NULL_SENSOR_POS = 4;
    uint8_t l_sensor_usage = fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DISABLED;
    uint8_t l_desired_sensors[NUM_CONFIG_DTS] = {NULL_SENSOR_POS, NULL_SENSOR_POS};
    uint8_t l_therm_sensor_rd_override = fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_READ_OVERRIDE_FALSE;

    // Get ATTR_MEM_EFF_THERM_SENSOR_READ_OVERRIDE Attr Value
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_READ_OVERRIDE, i_target, l_therm_sensor_rd_override));

    // If this attribute is TRUE then we want to have ody read all available on-board temperature sensors,
    // so we don't want to set the usage to DISABLED for this case.

    if (l_therm_sensor_rd_override == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_READ_OVERRIDE_FALSE)
    {
        FAPI_TRY(mss::ody::thermal::get_desired_dts(i_target, l_desired_sensors));

        for(uint8_t l_sensor_index = 0; l_sensor_index < NUM_DTS; l_sensor_index++ )
        {
            FAPI_TRY(mss::ody::thermal::get_therm_sensor_usage[l_sensor_index](i_target,
                     l_sensor_usage));

            if ((l_sensor_usage != fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DISABLED) &&
                !(l_desired_sensors[DRAM_SENSOR_INDEX] == l_sensor_index || l_desired_sensors[PMIC_SENSOR_INDEX] == l_sensor_index))
            {
                FAPI_TRY(mss::ody::thermal::set_therm_sensor_usage[l_sensor_index](i_target,
                         fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DISABLED));
            }

        }
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

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_OVERRIDE_THERM_SENSOR_USAGE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_therm_sensor_override));

    if (l_therm_sensor_override == fapi2::ENUM_ATTR_MSS_MRW_OVERRIDE_THERM_SENSOR_USAGE_ENABLED)
    {
        FAPI_TRY(change_temp_sensor_usage_helper(i_target));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // workarounds
} // ody
} // mss
