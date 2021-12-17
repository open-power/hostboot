/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_omi_init.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
/// @file ody_omi_init.C
/// @brief Initialize Odyssey OpenCAPI configuration
///
// *HWP HWP Owner: Geetha Pisapati <geetha.pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team:
// *HWP Level: 1
// *HWP Consumed by: HB

#include <fapi2.H>
#include <ody_omi_init.H>

///
/// @brief Verify we know how to talk to the connected device
///
/// @param[in] i_target                 Odyssey to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiDeviceVerify(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    return fapi2::FAPI2_RC_SUCCESS;
}


///
/// @brief Set the upstream templates and pacing
///
/// @param[in] i_target                 Odyssey to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiSetUpstreamTemplates(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    return fapi2::FAPI2_RC_SUCCESS;
}


///
/// @brief Set the major minor version and short back-off timer values.
///
/// @param[in] i_target                 Odyssey to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiTLVersionShortBackOff(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    return fapi2::FAPI2_RC_SUCCESS;
}


///
/// @brief Check if a bit/feature is supported if we want to use it.
///
/// @param[in] i_data                Register data to check
/// @param[in] i_offset              Offset in register value starts
/// @param[in] i_useFeature          Do we want to use this feature
/// @param[in] i_warn                Warning message to display if reg value does not match attribute
/// @param[out] o_val                Value to use
///
/// @return fapi2::ReturnCode Success if no errors
///
fapi2::ReturnCode omiCheckSupportedBit(const fapi2::buffer<uint32_t>& i_data, const uint32_t i_offset,
                                       const uint8_t i_useFeature, const char* i_warn, uint8_t& o_val)
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Check if the requested pacing for a template is supported
///
/// @param[in] i_data                Register data to check
/// @param[in] i_offset              Offset in register value starts
/// @param[in] i_len                 The length of the pacing field
/// @param[in] i_usePace             The desired pacing value
/// @param[in] i_warn                Warning message to display if reg value does not match attribute
/// @param[out] o_val                The pacing value to use
///
/// @return fapi2::ReturnCode Success if no errors
///
fapi2::ReturnCode omiCheckSupportedPacing(const fapi2::buffer<uint32_t>& i_data, const uint32_t i_offset,
        const uint32_t i_len, const uint8_t i_usePace, const char* i_warn, uint8_t& o_val)
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Validate downstream receive templates
///
/// @param[in] i_target                 Odyssey to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiValidateDownstream(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Set the actag and pasid lengths and bases, enable metadata.
///
/// @param[in] i_target                 Odyssey to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiSetACTagPASIDMetaData(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Enable the AFU
///
/// @param[in] i_target                 Odyssey to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode omiEnableAFU(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Initialize Odyssey OpenCAPI configuration
///
/// @param[in] i_target                 Odyssey to initialize
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode ody_omi_init(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    return fapi2::FAPI2_RC_SUCCESS;
}
