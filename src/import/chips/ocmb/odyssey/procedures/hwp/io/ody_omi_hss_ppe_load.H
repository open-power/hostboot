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
/// *HWP Consumed by: SBE, Cronus
///

#pragma once

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

// Constants
const uint32_t SIZE_32K_BYTES = 32768;
const uint32_t SIZE_1K_BYTES  = 1024;
const uint32_t OFFSET_0K      = 0x00000000;
const uint32_t OFFSET_32K     = 0x00008000;
const uint32_t OFFSET_64K     = 0x00010000;

typedef enum IO_PPE_image_types
{
    IOPPE_BASE_IMAGE,
    IOPPE_MEMREGS_IMAGE
} IO_PPE_Image_Type_t;

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode(*ody_omi_hss_ppe_load_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    uint8_t* const,
    uint32_t const,
    uint32_t const,
    IO_PPE_Image_Type_t);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
//
extern "C" {

///
/// @brief Load IO PPE and Mem_regs images to Odyssey SRAM
/// This HWP is called by SBE/Cronus platforms to load IO PPE
/// image onto the Odyssey SRAM.
/// Due to memory limitation of 32K on PPE, SBE/Cronus need to call
/// this function 4 times as described below to load IO PPE:
///    odc_omi_phy_ppe_load(base_img,      32KB,    0, IOPPE_BASE_IMAGE)
///    odc_omi_phy_ppe_load(base_img+32KB, 32KB, 32KB, IOPPE_BASE_IMAGE)
///    odc_omi_phy_ppe_load(base_img+64KB, 32KB, 64KB, IOPPE_BASE_IMAGE)
///    odc_omi_phy_ppe_load(memregs_img,   1KB,     0, IOPPE_MEMREGS_IMAGE)
///
/// @param[in]  i_target          Reference to Odyssey chip target
/// @param[in]  i_img_data        Pointer to image data
/// @param[in]  i_img_size        The size (in bytes) of the data
/// @param[in]  i_offset          Load offset
/// @param[in]  i_type            Type of image to load (base or memregs)
///
/// @return FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode ody_omi_hss_ppe_load(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        uint8_t* const i_img_data,
        uint32_t const i_img_size,
        uint32_t const i_offset,
        IO_PPE_Image_Type_t i_type);

} //extern "C"
