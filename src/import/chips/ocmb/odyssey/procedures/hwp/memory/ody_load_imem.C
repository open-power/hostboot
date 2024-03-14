/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_load_imem.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2024                        */
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
/// @file ody_load_imem.C
/// @brief Loads the imem image to the phy
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_load_imem.H>
#include <lib/phy/ody_draminit_utils.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/c_str.H>

extern "C"
{

//
/// @brief Loads the imem image into registers
/// @param[in] i_target the ocmb chip target
/// @param[in] i_imem_data imem data image
/// @param[in] i_imem_size size that needs to transferred at a time
/// @param[in] i_imem_offset address offset of this chunk within the imem image(in bytes)
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_load_imem(const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
                                    const uint8_t* i_imem_data,
                                    const uint32_t i_imem_size,
                                    const uint32_t i_imem_offset,
                                    poz_image_type /*unused*/)
    {
        mss::display_git_commit_info("ody_load_imem");

        uint8_t l_draminit_step_enable = 0;

        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_ocmb_target;
        FAPI_TRY(i_target.reduceType(l_ocmb_target));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DRAMINIT_STEP_ENABLE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_draminit_step_enable));

        if (mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_IMEM, l_draminit_step_enable))
        {
            FAPI_INF_NO_SBE(TARGTIDFORMAT " ATTR_ODY_DRAMINIT_STEP_ENABLE set to skip ody_load_imem. Exiting...", TARGTID);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        FAPI_TRY(mss::ody::phy::ody_load_imem_helper(l_ocmb_target, i_imem_data, i_imem_size, i_imem_offset));

    fapi_try_exit:
        return fapi2::current_err;

    }



}// extern C
