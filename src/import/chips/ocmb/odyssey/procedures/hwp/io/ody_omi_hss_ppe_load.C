/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_ppe_load.C $ */
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
/// @file ody_omi_hss_ppe_load.C
/// @brief Load IO PPE and Memory regs images onto Odyssey SRAM
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ody_omi_hss_ppe_load.H>
#include <fapi2_subroutine_executor.H>
#include <ody_scom_omi_ioo.H>
#include <ody_putsram.H>

// Scomt definitions
SCOMT_OMI_USE_PHY_PPE_WRAP0_XIXCR
SCOMT_OMI_USE_PHY_PPE_WRAP0_SCOM_CNTL

using namespace scomt::omi;

// SRAM address offsets
const uint64_t SRAM_IO_PPE_IMAGE_OFFSET      = 0xFFFE000000000000ULL;
const uint64_t SRAM_MEM_REG_THREAD0_OFFSET   = 0xFFFF580000000000ULL;
const uint64_t SRAM_MEM_REG_THREAD1_OFFSET   = 0xFFFF5C0000000000ULL;
const uint64_t SRAM_MEM_REG_THREAD2_OFFSET   = 0xFFFF600000000000ULL;
const uint64_t SRAM_MEM_REG_THREAD3_OFFSET   = 0xFFFF640000000000ULL;
const uint64_t SRAM_MEM_REG_THREAD4_OFFSET   = 0xFFFF680000000000ULL;
const uint8_t  NUM_OF_MEM_REGS = 5;  // 4 threads + supervisor thread
const uint32_t MEM_IMG_SIZE = 1024; // Bytes

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
fapi2::ReturnCode ody_omi_hss_ppe_load(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    uint8_t* const i_ody_ppe_image,
    uint32_t const i_img_size,
    uint8_t* const i_mem_regs_image)
{
    FAPI_DBG("Start");
    PHY_PPE_WRAP0_XIXCR_t WRAP0_XIXCR;
    PHY_PPE_WRAP0_SCOM_CNTL_t WRAP0_SCOM_CNTL;

    // Validate inputs
    FAPI_ASSERT( (i_ody_ppe_image != NULL) &&
                 (i_img_size != 0) &&
                 (i_mem_regs_image != NULL),
                 fapi2::ODY_IO_LOAD_PPE_IMG_ERROR()
                 .set_TARGET(i_target)
                 .set_IO_PPE_IMAGE(i_ody_ppe_image)
                 .set_IO_PPE_IMAGE_SIZE(i_img_size)
                 .set_MEM_REGS_IMAGE(i_mem_regs_image),
                 "ody_omi_hss_ppe_load: Invalid image: PPE image ptr %p, Size 0x%.8X, MEM_REGS image %p",
                 i_ody_ppe_image, i_img_size, i_mem_regs_image);

    FAPI_DBG("IO PPE img: Ptr %p, size %u; MEM_REGS img %p.",
             i_ody_ppe_image, i_img_size, i_mem_regs_image);

    // Halt PPE
    FAPI_DBG("Halt PPE.");
    WRAP0_XIXCR.set_PPE_XIXCR_XCR(1); // Write 0b001
    FAPI_TRY(WRAP0_XIXCR.putScom(i_target),
             "Error putscom to PPE_XIXCR_XCR (halt PPE).");

    // Logic IO reset, toggle SCOM_PPE_IORESET
    FAPI_DBG("IO reset.");
    WRAP0_SCOM_CNTL.set_SCOM_PPE_IORESET(1);
    FAPI_TRY(WRAP0_SCOM_CNTL.putScom(i_target),
             "Error putscom to SCOM_PPE_IORESET (1).");
    WRAP0_SCOM_CNTL.set_SCOM_PPE_IORESET(0);
    FAPI_TRY(WRAP0_SCOM_CNTL.putScom(i_target),
             "Error putscom to SCOM_PPE_IORESET (0).");

    // Load IO PPE image to SRAM
    // The SBE will compile this HWP natively and HB will tap the SBE (with an istep chipop) to
    // execute the load -- the SBE will call the HWP and supply data read from the NOR flash
    // locally/on DIMM (There is no external data transfer through the SBE FIFO)
    FAPI_TRY(ody_putsram(i_target, SRAM_IO_PPE_IMAGE_OFFSET, i_img_size, i_ody_ppe_image),
             "Error returned from ody_putsram (IO PPE image)");

    // Load Memregs
    for (uint8_t ii = 0; ii < NUM_OF_MEM_REGS; ii++)
    {
        FAPI_TRY(ody_putsram(i_target,
                             MEM_REG_OFFSETS[ii],
                             MEM_IMG_SIZE,
                             i_mem_regs_image),
                 "Error returned from ody_putsram (Memregs %d)", ii);
    }

    // Notes:
    // ody_omi_hss_ppe_load HWP only loads image and memregs into Odyssey' SRAM.
    // PPE config and start will be done in other HWPs that follow:
    //    PPE Config (Updates Various Registers)
    //    PPE Start (Issues Hard Reset, Resume, Clearing FIRs)

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
