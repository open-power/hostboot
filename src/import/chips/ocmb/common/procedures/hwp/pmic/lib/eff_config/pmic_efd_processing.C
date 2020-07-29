/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/eff_config/pmic_efd_processing.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file pmic_efd_processing.C
/// @brief Processing for EFD for eff config
///

// *HWP HWP Owner: Mark Pizzutillo Mark.Pizzutillo@ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI

#include <fapi2.H>
#include <lib/mss_pmic_attribute_setters.H>
#include <lib/eff_config/pmic_efd_processing.H>
#include <lib/utils/pmic_consts.H>
#include <lib/utils/pmic_common_utils.H>

namespace mss
{
namespace pmic
{

///
/// @brief Convert unsigned offset from SPD to signed offset for attributes
///
/// @param[in] i_offset - unsigned offset
/// @param[in] i_direction - direction
/// @return int8_t signed equivalent
/// @note Should be used with SPD data where the offset is 7 bits such that overflow could not be possible
///
int8_t convert_to_signed_offset(const uint8_t i_offset, const uint8_t i_direction)
{
    // Since offset value must be 7 bits (from SPD), we can directly cast it to an int8_t
    int8_t l_signed_offset = static_cast<int8_t>(i_offset);

    if (i_direction == CONSTS::OFFSET_MINUS)
    {
        // Can't overflow since signed_offset was only 7 bits
        l_signed_offset = 0 - l_signed_offset;
    }

    return l_signed_offset;
}

namespace efd
{

using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
///
/// @brief Processes the EFD PMIC0 SWA Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic0_swa_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_offset = 0;
    uint8_t l_direction = 0;
    FAPI_TRY(i_efd_data->pmic0_swa_offset(l_offset));
    FAPI_TRY(i_efd_data->pmic0_swa_offset_direction(l_direction));
    {
        int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
        FAPI_TRY(mss::attr::set_efd_pmic0_swa_voltage_offset(i_target, l_signed_offset));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC0 SWB Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic0_swb_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_offset = 0;
    uint8_t l_direction = 0;
    FAPI_TRY(i_efd_data->pmic0_swb_offset(l_offset));
    FAPI_TRY(i_efd_data->pmic0_swb_offset_direction(l_offset));
    {
        int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
        FAPI_TRY(mss::attr::set_efd_pmic0_swb_voltage_offset(i_target, l_signed_offset));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC0 SWC Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic0_swc_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_offset = 0;
    uint8_t l_direction = 0;
    FAPI_TRY(i_efd_data->pmic0_swc_offset(l_offset));
    FAPI_TRY(i_efd_data->pmic0_swc_offset_direction(l_offset));
    {
        int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
        FAPI_TRY(mss::attr::set_efd_pmic0_swc_voltage_offset(i_target, l_signed_offset));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC0 SWD Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic0_swd_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_offset = 0;
    uint8_t l_direction = 0;
    FAPI_TRY(i_efd_data->pmic0_swd_offset(l_offset));
    FAPI_TRY(i_efd_data->pmic0_swd_offset_direction(l_offset));
    {
        int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
        FAPI_TRY(mss::attr::set_efd_pmic0_swd_voltage_offset(i_target, l_signed_offset));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC1 SWA Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic1_swa_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_offset = 0;
    uint8_t l_direction = 0;
    FAPI_TRY(i_efd_data->pmic1_swa_offset(l_offset));
    FAPI_TRY(i_efd_data->pmic1_swa_offset_direction(l_offset));
    {
        int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
        FAPI_TRY(mss::attr::set_efd_pmic1_swa_voltage_offset(i_target, l_signed_offset));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC1 SWB Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic1_swb_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_offset = 0;
    uint8_t l_direction = 0;
    FAPI_TRY(i_efd_data->pmic1_swb_offset(l_offset));
    FAPI_TRY(i_efd_data->pmic1_swb_offset_direction(l_offset));
    {
        int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
        FAPI_TRY(mss::attr::set_efd_pmic1_swb_voltage_offset(i_target, l_signed_offset));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC1 SWC Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic1_swc_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_offset = 0;
    uint8_t l_direction = 0;
    FAPI_TRY(i_efd_data->pmic1_swc_offset(l_offset));
    FAPI_TRY(i_efd_data->pmic1_swc_offset_direction(l_offset));
    {
        int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
        FAPI_TRY(mss::attr::set_efd_pmic1_swc_voltage_offset(i_target, l_signed_offset));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC1 SWD Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic1_swd_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_offset = 0;
    uint8_t l_direction = 0;
    FAPI_TRY(i_efd_data->pmic1_swd_offset(l_offset));
    FAPI_TRY(i_efd_data->pmic1_swd_offset_direction(l_offset));
    {
        int8_t l_signed_offset = mss::pmic::convert_to_signed_offset(l_offset, l_direction);
        FAPI_TRY(mss::attr::set_efd_pmic1_swd_voltage_offset(i_target, l_signed_offset));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC0 SWA Current Consumption Warning Threshold
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic0_swa_current_warning(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_warning = 0;
    FAPI_TRY(i_efd_data->pmic0_swa_current_warning(l_warning));
    FAPI_TRY(mss::attr::set_pmic0_swa_current_warning(i_target, l_warning));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC0 SWB Current Consumption Warning Threshold
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic0_swb_current_warning(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_warning = 0;
    FAPI_TRY(i_efd_data->pmic0_swb_current_warning(l_warning));
    FAPI_TRY(mss::attr::set_pmic0_swb_current_warning(i_target, l_warning));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC0 SWC Current Consumption Warning Threshold
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic0_swc_current_warning(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_warning = 0;
    FAPI_TRY(i_efd_data->pmic0_swc_current_warning(l_warning));
    FAPI_TRY(mss::attr::set_pmic0_swc_current_warning(i_target, l_warning));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC0 SWD Current Consumption Warning Threshold
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic0_swd_current_warning(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_warning = 0;
    FAPI_TRY(i_efd_data->pmic0_swd_current_warning(l_warning));
    FAPI_TRY(mss::attr::set_pmic0_swd_current_warning(i_target, l_warning));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC1 SWA Current Consumption Warning Threshold
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic1_swa_current_warning(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_warning = 0;
    FAPI_TRY(i_efd_data->pmic1_swa_current_warning(l_warning));
    FAPI_TRY(mss::attr::set_pmic1_swa_current_warning(i_target, l_warning));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC1 SWB Current Consumption Warning Threshold
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic1_swb_current_warning(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_warning = 0;
    FAPI_TRY(i_efd_data->pmic1_swb_current_warning(l_warning));
    FAPI_TRY(mss::attr::set_pmic1_swb_current_warning(i_target, l_warning));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC1 SWC Current Consumption Warning Threshold
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic1_swc_current_warning(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_warning = 0;
    FAPI_TRY(i_efd_data->pmic1_swc_current_warning(l_warning));
    FAPI_TRY(mss::attr::set_pmic1_swc_current_warning(i_target, l_warning));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the EFD PMIC1 SWD Current Consumption Warning Threshold
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic1_swd_current_warning(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    uint8_t l_warning = 0;
    FAPI_TRY(i_efd_data->pmic1_swd_current_warning(l_warning));
    FAPI_TRY(mss::attr::set_pmic1_swd_current_warning(i_target, l_warning));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Process the EFD data and set attributes
/// @param[in] i_target DIMM target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode process(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                          const std::shared_ptr<mss::efd::base_decoder>& i_efd_data)
{
    FAPI_TRY(pmic0_swa_voltage_offset(i_target, i_efd_data));
    FAPI_TRY(pmic0_swb_voltage_offset(i_target, i_efd_data));
    FAPI_TRY(pmic0_swc_voltage_offset(i_target, i_efd_data));
    FAPI_TRY(pmic0_swd_voltage_offset(i_target, i_efd_data));

    FAPI_TRY(pmic1_swa_voltage_offset(i_target, i_efd_data));
    FAPI_TRY(pmic1_swb_voltage_offset(i_target, i_efd_data));
    FAPI_TRY(pmic1_swc_voltage_offset(i_target, i_efd_data));
    FAPI_TRY(pmic1_swd_voltage_offset(i_target, i_efd_data));

    FAPI_TRY(pmic0_swa_current_warning(i_target, i_efd_data));
    FAPI_TRY(pmic0_swb_current_warning(i_target, i_efd_data));
    FAPI_TRY(pmic0_swc_current_warning(i_target, i_efd_data));
    FAPI_TRY(pmic0_swd_current_warning(i_target, i_efd_data));

    FAPI_TRY(pmic1_swa_current_warning(i_target, i_efd_data));
    FAPI_TRY(pmic1_swb_current_warning(i_target, i_efd_data));
    FAPI_TRY(pmic1_swc_current_warning(i_target, i_efd_data));
    FAPI_TRY(pmic1_swd_current_warning(i_target, i_efd_data));

fapi_try_exit:
    return fapi2::current_err;
}

} // efd
} // pmic
} // mss
