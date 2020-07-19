/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_load_iop_xram.C $ */
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
/// @file p10_load_iop_xram.H
/// @brief Load PCIE firmware to IOP external RAM.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus
///
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_load_iop_xram.H>
#include <p10_pcie_scominit.H>
#include <multicast_group_defs.H>
#include <p10_ipl_image.H>
#include <p10_iop_xram_utils.H>
#include <p10_putsram.H>
#include <p10_getputsram_utils.H>
#include <fapi2_subroutine_executor.H>

//@TODO: RTC 214852 - Use SCOM accessors, remove workaround code

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
/// NOTE: doxygen in header
fapi2::ReturnCode p10_load_iop_xram(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    void* const i_hw_image)
{
    FAPI_DBG("Start");
    fapi2::ReturnCode l_rc;
    P9XipSection l_section;
    l_section.iv_offset = 0;
    l_section.iv_size = 0;
    uint8_t* l_xramImgPtr = NULL;
    uint8_t* l_xramFwDataPtr = NULL;
    uint32_t l_xramFwSize = 0;

    // Get PEC multicast target
    auto l_target_mcast = i_target.getMulticast<fapi2::TARGET_TYPE_PEC>(fapi2::MCGROUP_GOOD_PCI);
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PEC>> l_pecChiplets = l_target_mcast.getChildren<fapi2::TARGET_TYPE_PEC>();

    // Skip load if there are no functional PEC targets on this chip
    if (l_pecChiplets.size() == 0)
    {
        FAPI_INF("p10_load_iop_xram: Skipping load, no functional PEC on chip.");
        goto fapi_try_exit;
    }

    // Validate HW image
    FAPI_ASSERT(i_hw_image != NULL ,
                fapi2::P10_LOAD_IOP_XRAM_HW_IMG_ERROR()
                .set_TARGET(i_target)
                .set_HW_IMAGE(i_hw_image),
                "p10_load_iop_xram: Invalid HW XIP image");

    // Reference the XRAM image (.xram) section in the HW image
    // This is an XIP image nested in the HW image itself
    FAPI_INF("p10_load_iop_xram: Calling p9_xip_get_section (HW image)");
    FAPI_TRY(p9_xip_get_section(i_hw_image, P9_XIP_SECTION_HW_IOPXRAM, &l_section),
             "p10_load_iop_xram: Error from p9_xip_get_section (HW image).");
    l_xramImgPtr = l_section.iv_offset + (uint8_t*)(i_hw_image);

    // From the XRAM image, obtain pointers to IOP FW data
    FAPI_DBG("p10_load_iop_xram: Calling p9_xip_get_section (XRAM image, FW section)");
    FAPI_TRY(p9_xip_get_section(l_xramImgPtr, P9_XIP_SECTION_IOPXRAM_IOP_FW, &l_section),
             "p10_load_iop_xram: Error from p9_xip_get_section (XRAM image, FW section)");
    l_xramFwDataPtr = l_section.iv_offset + (uint8_t*)(l_xramImgPtr);
    l_xramFwSize = l_section.iv_size;

    FAPI_INF("p10_load_iop_xram: i_hw_image %p, l_xramImgPtr %p, l_xramFwDataPtr %p, l_xramFwSize %u",
             i_hw_image, l_xramImgPtr, l_xramFwDataPtr, l_xramFwSize);

    // Validate XRAM image
    FAPI_ASSERT((l_xramFwDataPtr != NULL) &&
                (l_xramFwSize != 0) &&
                (l_xramFwSize <= MAX_XRAM_IMAGE_SIZE),
                fapi2::P10_LOAD_IOP_XRAM_IMG_ERROR()
                .set_TARGET(i_target)
                .set_HW_IMAGE(i_hw_image)
                .set_XRAM_IMAGE_PTR(l_xramImgPtr)
                .set_XRAM_FW_DATA_PTR(l_xramFwDataPtr)
                .set_XRAM_FW_SIZE(l_xramFwSize),
                "p10_load_iop_xram: Invalid XRAM image: l_xramFwDataPtr %p, Size %u",
                l_xramFwDataPtr, l_xramFwSize);

    // Write img data to XRAM using PEC multicast
    FAPI_INF("p10_load_iop_xram: Write XRAM FW data: Ptr %p, size %u.",
             l_xramFwDataPtr, l_xramFwSize);

    // Reset PHYs on both PECs
    FAPI_TRY(doPhyReset(l_target_mcast),
             "p10_load_iop_xram: doPhyReset returns an error.");

    // Use multicast PEC target to load PCIE FW to all PECs
    // Loop to load to all IOP XRAM (iop_top0/1, phy0/1)
    for (uint8_t l_top = 0; l_top < NUM_OF_IO_TOPS; l_top++)
    {
        for (uint8_t l_phy = 0; l_phy < NUM_OF_PHYS; l_phy++)
        {
            FAPI_INF("p10_load_iop_xram: Attemp to write PCIE img to XRAM: iop_top %d, phy %d.",
                     l_top, l_phy);

            // Encode Top and Phy into mode
            uint8_t l_mode = 0;

            if (l_top)
            {
                l_mode = MODE_PCIE_TOP_BIT_MASK;
            }

            if (l_phy)
            {
                l_mode |= MODE_PCIE_PHY_BIT_MASK;
            }

            // Load IOP XRAM using putsram chip-op
            FAPI_CALL_SUBROUTINE(fapi2::current_err,
                                 p10_putsram,
                                 i_target,
                                 PCI0_PERV_CHIPLET_ID,  // Set to PCI0 as default for multicast.
                                 // p10_putsram will find valid multicast target.
                                 true,                  // Do multicast load
                                 l_mode,                // Access mode, not used here
                                 static_cast<uint64_t>(0), // Load at offset 0
                                 l_xramFwSize,
                                 l_xramFwDataPtr);

            FAPI_TRY(fapi2::current_err,
                     "p10_load_iop_xram: p10_write_xram returns an error: iop_top %d, phy %d.");

            FAPI_INF("p10_load_iop_xram: Successfully wrote PCIE img to XRAM: iop_top %d, phy %d.",
                     l_top, l_phy);
        }

        // Done loading this iop_top, enable XRAM scrubber
        // Note: do this here because Scrubber bit applies to both PHYs of an io_top
        FAPI_TRY(enableXramScrubber(l_target_mcast, static_cast<xramIopTopNum_t>(l_top)),
                 "p10_load_iop_xram: enableXramScrubber returns an error.");
    }

    // Write CReg overrides through the CR Parallel Interface
    // This is called here because phy reset has to be deasserted for CReg access
    FAPI_TRY(p10_load_iop_override(i_target));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
