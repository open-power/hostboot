/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_io_load_ppe.C $  */
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
/// @file p10_io_load_ppe.C
/// @brief Load image onto IO PPE SRAM
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_io_load_ppe.H>
#include <multicast_group_defs.H>
#include <p10_putsram.H>
#include <p10_getputsram_utils.H>
#include <fapi2_subroutine_executor.H>
#include <p10_ipl_image.H>

// SRAM address offsets
const uint64_t SRAM_IO_PPE_IMAGE_OFFSET      = 0xFFFE000000000000ULL;
const uint64_t SRAM_MEM_REG_THREAD0_OFFSET   = 0xFFFF280000000000ULL;
const uint64_t SRAM_MEM_REG_THREAD1_OFFSET   = 0xFFFF2C0000000000ULL;
const uint64_t SRAM_MEM_REG_THREAD2_OFFSET   = 0xFFFF300000000000ULL;
const uint64_t SRAM_MEM_REG_THREAD3_OFFSET   = 0xFFFF340000000000ULL;
const uint64_t SRAM_MEM_REG_THREAD4_OFFSET   = 0xFFFF380000000000ULL;
const uint8_t  NUM_OF_MEM_REGS = 5;

uint64_t MEM_REG_OFFSETS[NUM_OF_MEM_REGS] =
{
    SRAM_MEM_REG_THREAD0_OFFSET,
    SRAM_MEM_REG_THREAD1_OFFSET,
    SRAM_MEM_REG_THREAD2_OFFSET,
    SRAM_MEM_REG_THREAD3_OFFSET,
    SRAM_MEM_REG_THREAD4_OFFSET
};

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
/// NOTE: doxygen in header
fapi2::ReturnCode p10_io_load_ppe(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    void* const i_hw_image)
{
    FAPI_DBG("Start");
    fapi2::ReturnCode l_rc;

    P9XipSection l_section;
    l_section.iv_offset = 0;
    l_section.iv_size = 0;
    uint8_t* l_ioppeImgPtr = NULL;
    uint8_t* l_ioImgDataPtr = NULL;
    uint32_t l_ioImgSize = 0;
    uint8_t* l_memRegsImgDataPtr = NULL;
    uint32_t l_memRegsImgSize = 0;


    // skip load if there are no functional PAUC targets on this chip
    if (i_target.getMulticast<fapi2::TARGET_TYPE_PAUC>(fapi2::MCGROUP_GOOD_PAU)
        .getChildren<fapi2::TARGET_TYPE_PAUC>().size() == 0)
    {
        FAPI_DBG("p10_io_load_ppe: Skipping load (no functional PAUC on chip)");
        goto fapi_try_exit;
    }

    FAPI_ASSERT(i_hw_image != NULL ,
                fapi2::P10_IO_LOAD_PPE_HW_IMG_ERROR()
                .set_TARGET(i_target)
                .set_HW_IMAGE(i_hw_image),
                "p10_io_load_ppe: Invalid HW XIP image");

    // reference the IOPPE (.ioppe) section in the HW image
    // this is an XIP image nested in the HW image itself
    FAPI_DBG("p10_io_load_ppe: Calling p9_xip_get_section (HW image)");
    FAPI_TRY(p9_xip_get_section(i_hw_image, P9_XIP_SECTION_HW_IOPPE, &l_section),
             "p10_io_load_ppe: Error from p9_xip_get_section (HW image)");
    l_ioppeImgPtr = l_section.iv_offset + (uint8_t*)(i_hw_image);

    // from the IOPPE image, obtain pointers to ioo and memregs sections to load
    FAPI_DBG("p10_io_load_ppe: Calling p9_xip_get_section (IOPPE image, IOO section)");
    FAPI_TRY(p9_xip_get_section(l_ioppeImgPtr, P9_XIP_SECTION_IOPPE_IOO, &l_section),
             "p10_io_load_ppe: Error from p9_xip_get_section (IOPPE image, IOO section)");
    l_ioImgDataPtr = l_section.iv_offset + (uint8_t*)(l_ioppeImgPtr);
    l_ioImgSize = l_section.iv_size;

    FAPI_DBG("p10_io_load_ppe: Calling p9_xip_get_section (IOPPE image, MEMREGS section)");
    FAPI_TRY(p9_xip_get_section(l_ioppeImgPtr, P9_XIP_SECTION_IOPPE_MEMREGS, &l_section),
             "p10_io_load_ppe: Error from p9_xip_get_section (IOPPE image, MEMREGS section)");
    l_memRegsImgDataPtr = l_section.iv_offset + (uint8_t*)(l_ioppeImgPtr);
    l_memRegsImgSize = l_section.iv_size;

    FAPI_ASSERT((l_ioImgDataPtr != NULL) &&
                (l_memRegsImgDataPtr != NULL) &&
                (l_ioImgSize != 0) &&
                (l_memRegsImgSize != 0),
                fapi2::P10_IO_LOAD_PPE_IOPPE_IMG_ERROR()
                .set_TARGET(i_target)
                .set_IOO_IMAGE(l_ioImgDataPtr)
                .set_MEMREGS_IMAGE(l_memRegsImgDataPtr)
                .set_IOO_IMAGE_SIZE(l_ioImgSize)
                .set_MEMREGS_IMAGE_SIZE(l_memRegsImgSize)
                .set_HW_IMAGE(i_hw_image),
                "p10_io_load_ppe: Invalid IOPPE XIP image");

    FAPI_DBG("p10_io_load_ppe: IO PPE img: Ptr %p, size %u.",
             l_ioImgDataPtr, l_ioImgSize);
    FAPI_DBG("p10_io_load_ppe: Mem Reg img: Ptr %p, size %u.",
             l_memRegsImgDataPtr, l_memRegsImgSize);

    // 1. Load IO PPE image with putsram chip-op
    FAPI_CALL_SUBROUTINE(fapi2::current_err,
                         p10_putsram,
                         i_target,
                         PAU0_PERV_CHIPLET_ID,  // Set to PAU0 as default for multicast.
                         // p10_putsram will find valid multicast target.
                         true,                  // Do multicast load
                         0,                     // OCC mode, not used here
                         SRAM_IO_PPE_IMAGE_OFFSET,
                         l_ioImgSize,
                         l_ioImgDataPtr);
    FAPI_TRY(fapi2::current_err,
             "p10_io_load_ppe: error loading IO PPE image to SRAM_IO_PPE_IMAGE_OFFSET.");

    // 2. Load Mem reg image
    for (uint8_t ii = 0; ii < NUM_OF_MEM_REGS; ii++)
    {
        FAPI_CALL_SUBROUTINE(fapi2::current_err,
                             p10_putsram,
                             i_target,
                             PAU0_PERV_CHIPLET_ID, // Set to PAU0 as default for multicast.
                             // p10_putsram will find valid multicast target.
                             true,                 // Do multicast load
                             0,                    // OCC mode, not used here
                             MEM_REG_OFFSETS[ii],
                             l_memRegsImgSize,
                             l_memRegsImgDataPtr);
        FAPI_TRY(fapi2::current_err,
                 "p10_io_load_ppe: error loading IO PPE image to SRAM_IO_PPE_IMAGE_OFFSET.");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
