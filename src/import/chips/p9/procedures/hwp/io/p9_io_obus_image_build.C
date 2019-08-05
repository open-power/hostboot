/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_image_build.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file   p9_io_obus_image_build.C
/// @brief  Implements HWP that builds the Hcode image in IO Obus PPE Sram.
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
#include <p9_io_obus_image_build.H>
#include "p9_xip_image.h"

#include "p9_obus_scom_addresses.H"
#include "p9_obus_scom_addresses_fld.H"

//--------------------------------------------------------------------------
fapi2::ReturnCode extractPpeImgObus(void* const iImagePtr, const int iSectionId, uint8_t*& oObusImgPtr, uint32_t& oSize)
{
    FAPI_IMP("Entering getObusImageFromHwImage.");
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
    oObusImgPtr = ppeSection.iv_offset + (uint8_t*)(iImagePtr);

    // From the I/O Section, lets pull the IOO Nvlink Image.
    FAPI_TRY(p9_xip_get_section(oObusImgPtr, iSectionId, &ppeSection));

    // Point to the IOO PPE Image of the I/O PPE Section
    oObusImgPtr = ppeSection.iv_offset + (uint8_t*)(oObusImgPtr);

    // Set the Size of the IOO Image
    oSize = ppeSection.iv_size;

fapi_try_exit:
    FAPI_IMP("Exiting getObusImageFromHwImage.");
    return fapi2::current_err;
}

//---------------------------------------------------------------------------
fapi2::ReturnCode scomWrite(CONST_OBUS& iTgt, const uint64_t iAddr, const uint64_t iData)
{
    fapi2::buffer<uint64_t> data64(iData);
    // Xscom -- Scom from core in Hostboot mode
    return fapi2::putScom(iTgt, iAddr, data64);
}


//---------------------------------------------------------------------------
fapi2::ReturnCode p9_io_obus_image_build(CONST_OBUS& iTgt, void* const iHwImagePtr)
{
    FAPI_IMP("Entering p9_io_obus_image_build.");

    const uint64_t SRAM_BASE_ADDR   = 0xFFFF000000000000ull;
    const uint64_t AUTOINC_EN       = 0x8000000000000000ull;
    const uint64_t AUTOINC_DIS      = 0x0000000000000000ull;
    const uint64_t HARD_RESET       = 0x6000000000000000ull; // xcr cmd=110
    const uint64_t RESUME_FROM_HALT = 0x2000000000000000ull; // xcr cmd=010
    // PPE Address
    const uint64_t BASE_ADDR    = 0x0000000009011040ull;
    const uint64_t MEM_ARB_CSAR = 0x000000000000000Dull | BASE_ADDR; // Sram Address Reg
    const uint64_t MEM_ARB_SCR  = 0x000000000000000Aull | BASE_ADDR; // Sram Source Control Reg
    const uint64_t MEM_ARB_CSDR = 0x000000000000000Eull | BASE_ADDR; // Sram Data Reg
    const uint64_t XCR_NONE     = 0x0000000000000010ull | BASE_ADDR; // External Control Reg

    uint64_t data      = 0;
    uint8_t* pObusImg = NULL;
    uint32_t imgSize   = 0;
    uint8_t configMode = 0;
    int xipSectionId = 0;
    bool loadImage = false;
    fapi2::ATTR_CHIP_EC_FEATURE_HW446279_USE_PPE_Type l_hw446279_use_ppe;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OPTICS_CONFIG_MODE, iTgt, configMode),
             "Error from FAPI_ATTR_GET(ATTR_OPTICS_CONFIG_MODE)");

    if(fapi2::ENUM_ATTR_OPTICS_CONFIG_MODE_NV == configMode)
    {

        FAPI_IMP("NV IMAGE.");
        xipSectionId = P9_XIP_SECTION_IOPPE_IOO_NV;
        //
        // As of now there is no intended use of the nv ppe image.
        //
        //loadImage = true;
    }
    else if(fapi2::ENUM_ATTR_OPTICS_CONFIG_MODE_SMP == configMode)
    {
        FAPI_IMP("ABUS IMAGE.");
        xipSectionId = P9_XIP_SECTION_IOPPE_IOO_ABUS;
        auto l_chip = iTgt.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW446279_USE_PPE,
                               l_chip,
                               l_hw446279_use_ppe));

        if(l_hw446279_use_ppe)
        {
            FAPI_IMP("ABUS IMAGE LOAD.");
            loadImage = true;

            // Enable the PPE to communicate with the PHY
            fapi2::buffer<uint64_t> data64;
            FAPI_TRY(fapi2::getScom(iTgt, OBUS_SCOM_MODE_PB, data64));
            data64.setBit<OBUS_SCOM_MODE_PB_PPE_GCR>();
            FAPI_TRY(fapi2::putScom(iTgt, OBUS_SCOM_MODE_PB, data64));
        }
    }
    else // fapi2::ENUM_ATTR_OPTICS_CONFIG_MODE_CAPI
    {
        FAPI_IMP("p9_io_obus_image_build:: Skipping I/O Image Load for CAPI interface.");
    }

    if(loadImage)
    {
        FAPI_IMP("LOADING...");

        FAPI_TRY(extractPpeImgObus(iHwImagePtr, xipSectionId, pObusImg, imgSize), "Extract PPE Image Failed.");

        // PPE Reset
        FAPI_TRY(scomWrite(iTgt, XCR_NONE, HARD_RESET), "Hard Reset Failed.");

        // Set PPE Base Address
        FAPI_TRY(scomWrite(iTgt, MEM_ARB_CSAR, SRAM_BASE_ADDR), "Set Base Address Failed.");

        // Set PPE into Autoincrement Mode
        FAPI_TRY(scomWrite(iTgt, MEM_ARB_SCR, AUTOINC_EN), "Auto-Increment Enable Failed.");

        for(uint32_t i = 0; i < imgSize; i += 8)
        {
            data = (((uint64_t) * (pObusImg + i + 0) << 56) & 0xFF00000000000000ull) |
                   (((uint64_t) * (pObusImg + i + 1) << 48) & 0x00FF000000000000ull) |
                   (((uint64_t) * (pObusImg + i + 2) << 40) & 0x0000FF0000000000ull) |
                   (((uint64_t) * (pObusImg + i + 3) << 32) & 0x000000FF00000000ull) |
                   (((uint64_t) * (pObusImg + i + 4) << 24) & 0x00000000FF000000ull) |
                   (((uint64_t) * (pObusImg + i + 5) << 16) & 0x0000000000FF0000ull) |
                   (((uint64_t) * (pObusImg + i + 6) <<  8) & 0x000000000000FF00ull) |
                   (((uint64_t) * (pObusImg + i + 7) <<  0) & 0x00000000000000FFull);

            // Write Data, as the address will be autoincremented.
            FAPI_TRY(scomWrite(iTgt, MEM_ARB_CSDR, data), "Data Write Failed.");
        }

        // Disable Auto Increment
        FAPI_TRY(scomWrite(iTgt, MEM_ARB_SCR, AUTOINC_DIS), "Auto-Increment Disable Failed.");

        // If we are in Abus SMP mode, we do not want to start the PPE before link training.
        if(fapi2::ENUM_ATTR_OPTICS_CONFIG_MODE_SMP != configMode)
        {
            // PPE Reset
            FAPI_TRY(scomWrite(iTgt, XCR_NONE, HARD_RESET), "Hard Reset Failed.");

            // PPE Resume From Halt
            FAPI_TRY(scomWrite(iTgt, XCR_NONE, RESUME_FROM_HALT), "Resume From Halt Failed.");
        }
    }

fapi_try_exit:
    FAPI_IMP("Exit p9_io_obus_image_build.");
    return fapi2::current_err;
}
