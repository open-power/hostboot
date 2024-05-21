/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/ffdc/ody_pack_ecs_data.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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
/// @file ody_pack_ecs_data.C
/// @brief Pack ECS test data into HWP error
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_pack_ecs_data.H>

extern "C"
{
    ///
    /// @brief Pack ECS test data into HWP error
    /// @param[in] i_MR16_to_19_pat0 - pointer to array data from MR16-19 for pattern 1
    /// @param[in] i_MR16_to_19_pat0_size - size of array data from MR16-19 for pattern 1
    /// @param[in] i_MR20_pat0 - pointer to array data from MR20 for pattern 1
    /// @param[in] i_MR20_pat0_size - size of array data from MR20 for pattern 1
    /// @param[in] i_MR16_to_19_pat0 - pointer to array data from MR16-19 for pattern 1
    /// @param[in] i_MR16_to_19_pat0_size - size of array data from MR16-19 for pattern 1
    /// @param[in] i_MR20_pat0 - pointer to array data from MR20 for pattern 1
    /// @param[in] i_MR20_pat0_size - size of array data from MR20 for pattern 1
    /// @param[in,out] io_rc - return code to add FFDC data to.
    ///
    fapi2::ReturnCode ody_pack_ecs_data(
        const fapi2::ffdc_t& i_MR16_to_19_pat0,
        const fapi2::ffdc_t& i_MR16_to_19_pat0_size,
        const fapi2::ffdc_t& i_MR20_pat0,
        const fapi2::ffdc_t& i_MR20_pat0_size,
        const fapi2::ffdc_t& i_MR16_to_19_pat1,
        const fapi2::ffdc_t& i_MR16_to_19_pat1_size,
        const fapi2::ffdc_t& i_MR20_pat1,
        const fapi2::ffdc_t& i_MR20_pat1_size,
        fapi2::ReturnCode& io_rc)
    {

        fapi2::ffdc_t UNIT_FFDC_MR20_PAT0;
        UNIT_FFDC_MR20_PAT0.ptr() = (uint8_t*) * (reinterpret_cast<const size_t*>(i_MR20_pat0.ptr()));
        UNIT_FFDC_MR20_PAT0.size() = *(reinterpret_cast<const size_t*>(i_MR20_pat0_size.ptr()));
        FAPI_ADD_INFO_TO_HWP_ERROR(io_rc, RC_ODY_ECS_MR20_PAT0);

        fapi2::ffdc_t UNIT_FFDC_MR16_TO_19_PAT0;
        UNIT_FFDC_MR16_TO_19_PAT0.ptr() = (uint8_t*) * (reinterpret_cast<const size_t*>(i_MR16_to_19_pat0.ptr()));
        UNIT_FFDC_MR16_TO_19_PAT0.size() = *(reinterpret_cast<const size_t*>(i_MR16_to_19_pat0_size.ptr()));
        FAPI_ADD_INFO_TO_HWP_ERROR(io_rc, RC_ODY_ECS_MR16_TO_19_PAT0);

        fapi2::ffdc_t UNIT_FFDC_MR20_PAT1;
        UNIT_FFDC_MR20_PAT1.ptr() = (uint8_t*) * (reinterpret_cast<const size_t*>(i_MR20_pat1.ptr()));
        UNIT_FFDC_MR20_PAT1.size() = *(reinterpret_cast<const size_t*>(i_MR20_pat1_size.ptr()));
        FAPI_ADD_INFO_TO_HWP_ERROR(io_rc, RC_ODY_ECS_MR20_PAT1);

        fapi2::ffdc_t UNIT_FFDC_MR16_TO_19_PAT1;
        UNIT_FFDC_MR16_TO_19_PAT1.ptr() =  (uint8_t*) * (reinterpret_cast<const size_t*>(i_MR16_to_19_pat1.ptr()));
        UNIT_FFDC_MR16_TO_19_PAT1.size() = *(reinterpret_cast<const size_t*>(i_MR16_to_19_pat1_size.ptr()));
        FAPI_ADD_INFO_TO_HWP_ERROR(io_rc, RC_ODY_ECS_MR16_TO_19_PAT1);

        return fapi2::FAPI2_RC_SUCCESS;
    }

}// extern C
