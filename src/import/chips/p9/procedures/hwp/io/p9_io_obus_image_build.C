/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_image_build.C $ */
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
/// @file   p9_io_obus_image_build.C
/// @brief  Implements HWP that builds the Hcode image in IO Obus PPE Sram.
///----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HPW Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 1
/// *HWP Consumed by      : FSP:HB
///----------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p9_io_obus_image_build.H>
#include "p9_xip_image.h"

//---------------------------------------------------------------------------
fapi2::ReturnCode getBaseAddress(
    const fapi2::Target < fapi2::TARGET_TYPE_OBUS > i_tgt,
    uint64_t& o_baseAddr )
{
    FAPI_IMP( "Entering get_base_scom_address." );

    uint8_t unitPos = 0;

    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, i_tgt, unitPos ),
              "Fapi Attr Get Chip Unit Pos Failed." );

    switch( unitPos )
    {
        case 0:
            o_baseAddr = 0x0000000009011040ull;
            break;

        case 1:
            o_baseAddr = 0x000000000A011040ull;
            break;

        case 2:
            o_baseAddr = 0x000000000B011040ull;
            break;

        case 3:
            o_baseAddr = 0x000000000C011040ull;
            break;

        default:
            o_baseAddr = 0x0000000000000000ull;
            break;

    }

    FAPI_IMP( "Exiting get_base_scom_address." );
fapi_try_exit:
    return fapi2::current_err;
}

//---------------------------------------------------------------------------
fapi2::ReturnCode getObusImageFromHcode( void* const i_pImage, uint8_t* i_pObusImg, uint32_t& o_size )
{
    uint8_t*     pIoSection;
    P9XipSection ppeSection;

    ppeSection.iv_offset = 0;
    ppeSection.iv_size = 0;


    FAPI_ASSERT( i_pImage != NULL ,
                 fapi2::P9_IO_PPE_OBUS_IMG_PTR_ERROR().set_HW_IMG_PTR( i_pImage ),
                 "Bad pointer to HW Image." );

    // Pulls the IO PPE Section from the HW/XIP Image
    // XIP(Execution In Place) -- Points to Seeprom
    FAPI_TRY( p9_xip_get_section( i_pImage, P9_XIP_SECTION_HW_IOPPE, &ppeSection ) );

    // Point to the Io Section in the HW/XIP Image
    pIoSection = ppeSection.iv_offset + (uint8_t*) ( i_pImage );

    // From the Io Section, lets pull the IOO Image.
    // TODO : Need to get an updated section for IOO Image.
    FAPI_TRY( p9_xip_get_section( pIoSection, P9_XIP_SECTIONS_IOPPE, &ppeSection ) );

    // Point to the IOO PPE Image of the Io Section
    i_pObusImg = ppeSection.iv_offset + (uint8_t*) ( pIoSection );

    // Set the Size of the IOO Image
    o_size = ppeSection.iv_size;

fapi_try_exit:
    return fapi2::current_err;
}

//---------------------------------------------------------------------------
fapi2::ReturnCode scomWrite(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_tgt,
    const uint64_t i_addr,
    const uint64_t i_data )
{
    fapi2::buffer<uint64_t> data64( i_data );

    // Xscom -- Scom from core in Hostboot mode
    return fapi2::putScom( i_tgt, i_addr, data64 );
}


//---------------------------------------------------------------------------
fapi2::ReturnCode p9_io_obus_image_build(
    const fapi2::Target < fapi2::TARGET_TYPE_OBUS >& i_tgt,
    void* const     i_pImage )
{
    FAPI_IMP( "Entering p9_io_ioo_ppe_hcode_build." );

    const uint64_t SRAM_BASE_ADDR       = 0xFFFF000000000000ull;
    const uint64_t PPE_AUTOINC_EN       = 0x8000000000000000ull;
    const uint64_t PPE_AUTOINC_DIS      = 0x0000000000000000ull;
    const uint64_t PPE_HARD_RESET       = 0x6000000000000000ull; // xcr cmd=110
    const uint64_t PPE_RESUME_FROM_HALT = 0x2000000000000000ull; // xcr cmd=010
    // PPE Address
    const uint64_t MEM_ARB_CSAR = 0x0D; // Sram Address Reg
    const uint64_t MEM_ARB_SCR  = 0x0A; // Sram Source Control Reg
    const uint64_t MEM_ARB_CSDR = 0x0E; // Sram Data Reg
    const uint64_t XCR_NONE     = 0x10; // External Control Reg

    uint64_t data      = 0;
    uint64_t baseAddr  = 0;
    uint8_t* pObusImg  = NULL;
    uint32_t imgSize   = 0;

    // Sets the base address based on the chip unit position
    FAPI_TRY( getBaseAddress( i_tgt, baseAddr ),
              "getBaseAddress Failed." );

    // Get Image from Hcode
    FAPI_TRY( getObusImageFromHcode( i_pImage, pObusImg, imgSize ),
              "Get Obus PPE Image Failed." );

    // Set PPE Base Address
    FAPI_TRY( scomWrite( i_tgt, baseAddr | MEM_ARB_CSAR, SRAM_BASE_ADDR ),
              "I/O Obus PPE Set Base Address Failed." );

    // Set PPE into Autoincrement Mode
    FAPI_TRY( scomWrite( i_tgt, baseAddr | MEM_ARB_SCR, PPE_AUTOINC_EN ),
              "I/O Obus PPE Auto Increment Enable Failed." );

    for( uint32_t i = 0; i < imgSize; i += 8 )
    {
        data = ( ( (uint64_t)pObusImg[i + 0] << 56 ) & 0xFF00000000000000ull ) |
               ( ( (uint64_t)pObusImg[i + 1] << 48 ) & 0x00FF000000000000ull ) |
               ( ( (uint64_t)pObusImg[i + 2] << 40 ) & 0x0000FF0000000000ull ) |
               ( ( (uint64_t)pObusImg[i + 3] << 32 ) & 0x000000FF00000000ull ) |
               ( ( (uint64_t)pObusImg[i + 4] << 24 ) & 0x00000000FF000000ull ) |
               ( ( (uint64_t)pObusImg[i + 5] << 16 ) & 0x0000000000FF0000ull ) |
               ( ( (uint64_t)pObusImg[i + 6] <<  8 ) & 0x000000000000FF00ull ) |
               ( ( (uint64_t)pObusImg[i + 7] <<  0 ) & 0x00000000000000FFull );
        // Write Data, as the address will be autoincremented.
        FAPI_TRY( scomWrite( i_tgt, baseAddr | MEM_ARB_CSDR, data ),
                  "I/O Obus PPE Data Write Failed." );
    }

    // Disable Auto Increment
    FAPI_TRY( scomWrite( i_tgt, baseAddr | MEM_ARB_SCR, PPE_AUTOINC_DIS ),
              "I/O Obus PPE Auto-Increment Disable Failed." );

    // PPE Reset
    FAPI_TRY( scomWrite( i_tgt, baseAddr | XCR_NONE, PPE_HARD_RESET ),
              "I/O Obus PPE Hard Reset Failed. " );

    // PPE Resume From Halt
    FAPI_TRY( scomWrite( i_tgt, baseAddr | XCR_NONE, PPE_RESUME_FROM_HALT ),
              "I/O Obus PPE Resume From Halt Failed." );

    FAPI_IMP( "Exit p9_hcode_image_build." );

fapi_try_exit:
    return fapi2::current_err;
}
