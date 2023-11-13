/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_load_imem.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2023                        */
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
/// @file ody_load_imem.H
/// @brief Loads the imem image to the phy
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB


#ifndef _ODY_LOAD_IMEM_H_
#define _ODY_LOAD_IMEM_H_

#include <fapi2.H>
#include <poz_common_image_load.H>

// Required for Cronus
typedef fapi2::ReturnCode (*ody_load_imem_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        const uint8_t* i_imem_data,
        const uint32_t i_imem_size,
        const uint32_t i_imem_offset,
        poz_image_type i_image_type);

extern "C"
{

//
/// @brief Runs the dram initialization on the SPPE
/// @param[in] i_target the ocmb chip target
/// @param[in] i_imem_data imem data image
/// @param[in] i_imem_size size that needs to transferred at a time
/// @param[in] i_imem_offset address offset of this chunk within the imem image(in bytes)
/// @param[in] i_image_type type of image being loaded
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_load_imem(const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
                                    const uint8_t* i_imem_data,
                                    const uint32_t i_imem_size,
                                    const uint32_t i_imem_offset,
                                    poz_image_type i_image_type);
}

ASSERT_COMMON_IMAGE_LOAD(ody_load_imem);

#endif
