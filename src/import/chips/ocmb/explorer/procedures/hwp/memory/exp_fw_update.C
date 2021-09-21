/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_fw_update.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file exp_fw_update.C
/// @brief Procedure definition to update explorer firmware
///
// *HWP HWP Owner: Glenn Miles <milesg@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <exp_fw_update.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/inband/exp_flash_utils.H>

extern "C"
{

///
/// @brief Updates explorer firmware
/// @param[in] i_target the controller
/// @param[in] i_image_ptr pointer to the binary image
/// @param[in] i_image_sz size of the binary image
/// @return FAPI2_RC_SUCCESS if ok
///
    fapi2::ReturnCode exp_fw_update(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const uint8_t* i_image_ptr,
                                    const size_t i_image_sz)
    {
        FAPI_INF("Entering exp_fw_update(%s). imageSize[0x%08x]",
                 mss::c_str(i_target), i_image_sz);

        FAPI_TRY(mss::exp::write_fw_image_to_flash(i_target, i_image_ptr, i_image_sz));

        FAPI_TRY(mss::exp::commit_fw_image(i_target, i_image_sz));

    fapi_try_exit:
        FAPI_INF("Exiting exp_fw_update(%s) with return code : 0x%08x...",
                 mss::c_str(i_target), (uint64_t) fapi2::current_err);
        return fapi2::current_err;
    }

///
/// @brief Updates explorer firmware on all OCMB_CHIPs under a PROC_CHIP
/// @param[in] i_target the processor target
/// @param[in] i_image_ptr pointer to the binary image
/// @param[in] i_image_sz size of the binary image
/// @return FAPI2_RC_SUCCESS if ok
///
    fapi2::ReturnCode exp_fw_update_all(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                        const uint8_t* i_image_ptr,
                                        const size_t i_image_sz)
    {
        FAPI_INF("Entering exp_fw_update_all(%s). imageSize[0x%08x]",
                 mss::c_str(i_target), i_image_sz);

        for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
        {
            for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
            {
                FAPI_TRY(exp_fw_update(l_ocmb, i_image_ptr, i_image_sz));
            }
        }

        FAPI_INF("Finished exp_fw_update_all(%s)",
                 mss::c_str(i_target));

    fapi_try_exit:
        return fapi2::current_err;
    }

} //extern "C"
