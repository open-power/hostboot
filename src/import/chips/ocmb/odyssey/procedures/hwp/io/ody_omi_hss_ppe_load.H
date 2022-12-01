/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_ppe_load.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file ody_omi_hss_ppe_load.H
/// @brief Load IO PPE and Memory regs images onto Odyssey SRAM
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

#pragma once

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode(*ody_omi_hss_ppe_load_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    uint8_t* const,
    uint32_t const,
    uint8_t* const);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
//
extern "C" {

///
/// @brief Load IO PPE and Mem_regs images to Odyssey SRAM
/// This HWP is called by Hostboot/Cronus platforms to load IO PPE
/// image onto the Odyssey SRAM.
///
/// @param[in]  i_target            Reference to Odyssey chip target
/// @param[in]  i_ody_ppe_image     Pointer to image data
/// @param[in]  i_img_size          The size (in bytes) of the image
/// @param[in]  i_mem_regs_image    Pointer to mem_regs image (1024-byte)
///
/// @return FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode ody_omi_hss_ppe_load(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        uint8_t* const i_ody_ppe_image,
        uint32_t const i_img_size,
        uint8_t* const i_mem_regs_image);

} //extern "C"
