/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_load_dmem.C $ */
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
// EKB-Mirror-To: hostboot
///
/// @file ody_load_dmem.C
/// @brief Loads the dmem image to the phy
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_load_dmem.H>
#include <lib/phy/ody_draminit_utils.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
extern "C"
{
    //
    /// @brief Loads the dmem image into registers
    /// @param[in] i_target the ocmb chip target
    /// @param[in] i_dmem_data dmem data image
    /// @param[in] i_dmem_size size that needs to transferred at a time
    /// @param[in] i_dmem_offset address offset of this chunk within the dmem image(in bytes)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode ody_load_dmem(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    uint8_t* const i_dmem_data,
                                    const uint32_t i_dmem_size,
                                    const uint32_t i_dmem_offset)
    {
        mss::display_git_commit_info("ody_load_dmem");
        FAPI_TRY(mss::ody::phy::ody_load_dmem_helper(i_target, i_dmem_data, i_dmem_size, i_dmem_offset));

    fapi_try_exit:
        return fapi2::current_err;

    }



}// extern C
