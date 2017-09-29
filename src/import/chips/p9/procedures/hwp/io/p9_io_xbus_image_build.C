/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_xbus_image_build.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file   p9_io_xbus_image_build.C
/// @brief  Implements HWP that builds the Hcode image in IO Xbus PPE Sram.
///----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HPW Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 3
/// *HWP Consumed by      : FSP:HB
///----------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p9_io_xbus_image_build.H>
#include "p9_xip_image.h"

//---------------------------------------------------------------------------
fapi2::ReturnCode extractPpeImgXbus(void* const iImagePtr, uint8_t*& oPpeImgPtr, uint32_t& oSize)
{
    FAPI_IMP("Entering getXbusImageFromHwImage.");
    P9XipSection ppeSection;
    ppeSection.iv_offset = 0;
    ppeSection.iv_size = 0;

    FAPI_ASSERT(iImagePtr != NULL ,
                fapi2::P9_IO_PPE_OBUS_IMG_PTR_ERROR().set_HW_IMG_PTR(iImagePtr),
                "Bad pointer to HW Image.");

    // Pulls the IO PPE Section from the HW/XIP Image
    // XIP(Execution In Place) -- Points to Seeprom
    FAPI_TRY(p9_xip_get_section(iImagePtr, P9_XIP_SECTION_HW_IOPPE, &ppeSection));

    // Point to the I/O PPE Section in the HW/XIP Image
    oPpeImgPtr = ppeSection.iv_offset + (uint8_t*)(iImagePtr);

    // From the I/O Section, lets pull the IOO Nvlink Image.
    FAPI_TRY(p9_xip_get_section(oPpeImgPtr, P9_XIP_SECTION_IOPPE_IOF, &ppeSection));

    // Point to the IOO PPE Image of the I/O PPE Section
    oPpeImgPtr = ppeSection.iv_offset + (uint8_t*)(oPpeImgPtr);

    // Set the Size of the IOO Image
    oSize = ppeSection.iv_size;

fapi_try_exit:
    FAPI_IMP("Exiting getXbusImageFromHwImage.");
    return fapi2::current_err;
}

//---------------------------------------------------------------------------
fapi2::ReturnCode scomWrite(CONST_PROC& iTgt, const uint64_t iAddr, const uint64_t iData)
{
    fapi2::buffer<uint64_t> data64(iData);
    // Xscom -- Scom from core in Hostboot mode
    return fapi2::putScom(iTgt, iAddr, data64);
}

//---------------------------------------------------------------------------
fapi2::ReturnCode p9_io_xbus_image_build(CONST_PROC& iTgt, void* const iHwImagePtr)
{
    FAPI_IMP("Entering p9_io_xbus_image_build.");

    const uint64_t SRAM_BASE_ADDR   = 0xFFFF000000000000ull;
    const uint64_t AUTOINC_EN       = 0x8000000000000000ull;
    const uint64_t AUTOINC_DIS      = 0x0000000000000000ull;
    const uint64_t HARD_RESET       = 0x6000000000000000ull; // xcr cmd=110
    const uint64_t RESUME_FROM_HALT = 0x2000000000000000ull; // xcr cmd=010
    // PPE Address
    const uint64_t BASE_ADDR    = 0x0000000006010840ull;
    const uint64_t MEM_ARB_CSAR = 0x000000000000000Dull | BASE_ADDR; // Sram Address Reg
    const uint64_t MEM_ARB_SCR  = 0x000000000000000Aull | BASE_ADDR; // Sram Source Control Reg
    const uint64_t MEM_ARB_CSDR = 0x000000000000000Eull | BASE_ADDR; // Sram Data Reg
    const uint64_t XCR_NONE     = 0x0000000000000010ull | BASE_ADDR; // External Control Reg

    uint64_t data      = 0;
    uint8_t* pPpeImg = NULL;
    uint32_t imgSize   = 0;

    // Get vector of xbus units from the processor
    auto xbusUnits = iTgt.getChildren<fapi2::TARGET_TYPE_XBUS>();

    // Make sure we have functional xbus units before we load the ppe
    if(!xbusUnits.empty())
    {
        FAPI_TRY(extractPpeImgXbus(iHwImagePtr, pPpeImg, imgSize), "Extract PPE Image Failed.");

        // PPE Reset
        FAPI_TRY(scomWrite(iTgt, XCR_NONE, HARD_RESET), "Hard Reset Failed.");

        // Set PPE Base Address
        FAPI_TRY(scomWrite(iTgt, MEM_ARB_CSAR, SRAM_BASE_ADDR), "Set Base Address Failed.");

        // Set PPE into Autoincrement Mode
        FAPI_TRY(scomWrite(iTgt, MEM_ARB_SCR, AUTOINC_EN), "Auto-Increment Enable Failed.");

        for(uint32_t i = 0; i < imgSize; i += 8)
        {
            data = (((uint64_t) * (pPpeImg + i + 0) << 56) & 0xFF00000000000000ull) |
                   (((uint64_t) * (pPpeImg + i + 1) << 48) & 0x00FF000000000000ull) |
                   (((uint64_t) * (pPpeImg + i + 2) << 40) & 0x0000FF0000000000ull) |
                   (((uint64_t) * (pPpeImg + i + 3) << 32) & 0x000000FF00000000ull) |
                   (((uint64_t) * (pPpeImg + i + 4) << 24) & 0x00000000FF000000ull) |
                   (((uint64_t) * (pPpeImg + i + 5) << 16) & 0x0000000000FF0000ull) |
                   (((uint64_t) * (pPpeImg + i + 6) <<  8) & 0x000000000000FF00ull) |
                   (((uint64_t) * (pPpeImg + i + 7) <<  0) & 0x00000000000000FFull);

            // Write Data, as the address will be autoincremented.
            FAPI_TRY(scomWrite(iTgt, MEM_ARB_CSDR, data), "Data Write Failed.");
        }

        // Disable Auto Increment
        FAPI_TRY(scomWrite(iTgt, MEM_ARB_SCR, AUTOINC_DIS), "Auto-Increment Disable Failed.");

        // PPE Reset
        FAPI_TRY(scomWrite(iTgt, XCR_NONE, HARD_RESET), "Hard Reset Failed.");

        // PPE Resume From Halt
        FAPI_TRY(scomWrite(iTgt, XCR_NONE, RESUME_FROM_HALT), "Resume From Halt Failed.");
    }
    else
    {
        FAPI_INF("No functional xbus units found. Skipping Xbus PPE Load...");
    }

fapi_try_exit:
    FAPI_IMP("Exit p9_io_xbus_image_build.");
    return fapi2::current_err;
}
