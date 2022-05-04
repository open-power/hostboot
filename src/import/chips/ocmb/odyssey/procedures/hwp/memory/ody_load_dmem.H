/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_load_dmem.H $ */
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
/// @file ody_load_dmem.H
/// @brief Loads the dmem image to the phy
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#ifndef _ODY_LOAD_DMEM_H_
#define _ODY_LOAD_DMEM_H_

// Required for Cronus
typedef fapi2::ReturnCode (*ody_load_dmem_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        uint8_t* const i_dmem_data,
        const uint32_t i_dmem_size,
        const uint32_t i_dmem_offset);
extern "C"
{

//
/// @brief Runs the dram initialization on the SPPE
/// @param[in] i_target the ocmb chip target
/// @param[in] i_dmem_data dmem data image
/// @param[in] i_dmem_size size that needs to transferred at a time
/// @param[in] i_dmem_offset address offset of this chunk within the dmem image(in bytes)
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_load_dmem(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    uint8_t* const i_dmem_data,
                                    const uint32_t i_dmem_size,
                                    const uint32_t i_dmem_offset);
}

#endif
