/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_check_proc_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

#include <stdint.h>

///
/// @file   p10_check_proc_config.C
/// @brief  describes interface for a HWP that generates a bit vector corresponding to P10 chip config.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Sumit Kumar <sumit_kumar@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          3
/// *HWP Consumed by:    Hostboot:Phyp
///
/// EKB-Mirror-To: hostboot
//

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p10_check_proc_config.H>
#include <p10_hcd_memmap_homer.H>
#include <endian.h>
#include <map>
#include <stdint.h>


#ifndef __HOSTBOOT_MODULE
    std::map< fapi2::TargetType, std::string > g_targetTypeMap;
#endif
/**
 * @brief   misc local constants
 */
/**
 * @brief   bit position for various chiplets in config vector.
 * PB     = 0x8000000000000000 //Bit-0
 * MC00   = 0x4000000000000000 //Bit-1
 * MC01   = 0x2000000000000000 //Bit-2
 * MC10   = 0x1000000000000000 //Bit-3
 * MC11   = 0x0800000000000000 //Bit-4
 * MC20   = 0x0400000000000000 //Bit-5
 * MC21   = 0x0200000000000000 //Bit-6
 * MC30   = 0x0100000000000000 //Bit-7
 * MC31   = 0x0080000000000000 //Bit-8
 * PEC-0  = 0x0040000000000000 //Bit-9
 * PEC-1  = 0x0020000000000000 //Bit-10
 * TLPM-0 = 0x001C000000000000 //Bit-11-13
 * TLPM-1 = 0x0003800000000000 //Bit-14-16
 * TLPM-2 = 0x0000700000000000 //Bit-17-19
 * TLPM-3 = 0x00000E0000000000 //Bit-20-22
 * TLPM-4 = 0x000001C000000000 //Bit-23-25
 * TLPM-5 = 0x0000003800000000 //Bit-26-28
 * TLPM-6 = 0x0000000700000000 //Bit-29-31
 * TLPM-7 = 0x00000000E0000000 //Bit-32-34
 * PHB-0  = 0x0000000010000000 //Bit-35
 * PHB-1  = 0x0000000008000000 //Bit-36
 * PHB-2  = 0x0000000004000000 //Bit-37
 * PHB-3  = 0x0000000002000000 //Bit-38
 * PHB-4  = 0x0000000001000000 //Bit-39
 * PHB-5  = 0x0000000000800000 //Bit-40
 * OCMB-0 = 0x0000000000400000 //Bit-41
 * OCMB-1 = 0x0000000000200000 //Bit-42
 * OCMB-2 = 0x0000000000100000 //Bit-43
 * OCMB-3 = 0x0000000000080000 //Bit-44
 * OCMB-4 = 0x0000000000040000 //Bit-45
 * OCMB-5 = 0x0000000000020000 //Bit-46
 * OCMB-6 = 0x0000000000010000 //Bit-47
 * OCMB-7 = 0x0000000000008000 //Bit-48
 * OCMB-8 = 0x0000000000004000 //Bit-49
 * OCMB-9 = 0x0000000000002000 //Bit-50
 * OCMB-10= 0x0000000000001000 //Bit-51
 * OCMB-11= 0x0000000000000800 //Bit-52
 * OCMB-12= 0x0000000000000400 //Bit-53
 * OCMB-13= 0x0000000000000200 //Bit-54
 * OCMB-14= 0x0000000000000100 //Bit-55
 * OCMB-15= 0x0000000000000080 //Bit-56
 * NX     = 0x0000000000000040 //Bit-57
 *
 * TLPM defined as below:
 * Bit [0]   - Not functional/ 1-Functional
 * Bit [1:2] - X-Link/ A-Link/ OCAPI
 * [ 0 0 0 ] - Not present/ Not configured
 * [ 0 0 1 ] - X-Link configured/ Not functional
 * [ 1 0 1 ] - X-Link configured/ Functional
 * [ 0 1 0 ] - A-Link configured/ Not functional
 * [ 1 1 0 ] - A-Link configured/ Functional
 * [ 0 1 1 ] - OCAPI configured/ Not functional
 * [ 1 1 1 ] - OCAPI configured/ Functional
 * [ 1 0 0 ] - Undefined
 */
enum
{
    MCC_POS             =   1,
    PEC_POS             =   9,
    TLPM_POS            =   11,
    PHB_POS             =   35,
    OCMB_POS            =   41,
};

enum
{
    INIT_CONFIG_VALUE        =       0x8000000000000040ull,
    XPMR_PROC_CONFIG_UAV_POS =       0xBFC18,
    TLPM_BITS_WIDTH          =       3,
    TLPM_CONFIG_POS          =       (TLPM_POS + 1)
};

/**
 * @brief   validates the input arguments for the HWP.
 * @param[in]   i_procTgt       fapi2 target for P10 chip.
 * @param[in]   i_pHomerImage   pointer to HOMER base
 */
fapi2::ReturnCode validateInputArgs( CONST_FAPI2_PROC& i_procTgt, void*  i_pHomerImage )
{
    FAPI_INF( ">> validateInputArgs" );

    FAPI_ASSERT( i_procTgt.isFunctional(),
                 fapi2::BAD_PROC_TARGET()
                 .set_TARGET( i_procTgt )
                 .set_INPUT_BUF( i_pHomerImage ),
                 "Bad Proc Target Passed As Input" );

    FAPI_ASSERT( ( i_pHomerImage != NULL ),
                 fapi2::BAD_INPUT_BUFFER()
                 .set_TARGET( i_procTgt )
                 .set_INPUT_BUF( i_pHomerImage ),
                 "Bad Buffer Is Passed As Input" );
fapi_try_exit:

    FAPI_INF( "<< validateInputArgs" );
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------------------

/**
 * @brief checks configuration of IOHS and populates UAV with X-LINK/ A-LINK/ OCAPI info
 * @param[in]   i_procTgt       fapi2 target for P10
 * @param[io]   i_configBuf     fapi2 buffer
 * @return      fapi2 return code.
 */
fapi2::ReturnCode checkIOHSConfig( CONST_FAPI2_PROC& i_procTgt, uint64_t& io_configVector )
{
    FAPI_INF( ">> checkIOHSConfig" );
    auto l_iohsList         =   i_procTgt.getChildren<fapi2::TARGET_TYPE_IOHS>( fapi2::TARGET_STATE_PRESENT );
    uint8_t l_iohsPos       =   0;
    uint8_t l_configMode    =   0;
    uint64_t l_tempVector   =   0;
    bool l_config_flag      =   0;

    for( auto l_iohs : l_iohsList )
    {
        FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_IOHS_CONFIG_MODE, l_iohs, l_configMode ),
                  "Failed To Read ATTR_IOHS_CONFIG_MODE" );

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs, l_iohsPos ),
                  "Error from FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS)" );

        FAPI_INF( "IOHS - POS: %d LINK: %s ", l_iohsPos,
                  ( l_configMode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX ) ? "X-Link" :
                  ( l_configMode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA ) ? "A-Link" :
                  ( l_configMode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_OCAPI ) ? "OCAPI" : "NOT CONFIGURED" );

        if( l_configMode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX )
        {
            l_tempVector |= ( 0x4000000000000000ull >> ( TLPM_CONFIG_POS + (TLPM_BITS_WIDTH * l_iohsPos) ) );
            l_config_flag = 1;
        }
        else if( l_configMode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA )
        {
            l_tempVector |= ( 0x8000000000000000ull >> ( TLPM_CONFIG_POS + (TLPM_BITS_WIDTH * l_iohsPos) ) );
            l_config_flag = 1;
        }
        else if( l_configMode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_OCAPI )
        {
            l_tempVector |= ( 0xC000000000000000ull >> ( TLPM_CONFIG_POS + (TLPM_BITS_WIDTH * l_iohsPos) ) );
            l_config_flag = 1;
        }

        if( l_config_flag && l_iohs.isFunctional() )
        {
            //updation of bit vector - functional/ not functional
            l_tempVector    |=   ( 0x8000000000000000ull >> ( TLPM_POS + (TLPM_BITS_WIDTH * l_iohsPos) ) );
        }

        // reset the flag
        l_config_flag = 0;
    }

    io_configVector  |= l_tempVector;

    FAPI_INF( "UAV with IOHS: 0x%016llx", io_configVector );

fapi_try_exit:
    FAPI_INF( "<< checkIOHSConfig" );
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------------------

/**
 * @brief   checks OCMB configuration and updates config vector buffer.
 * @param[in]   i_procTgt       fapi2 target for P10
 * @param[in]   i_configBuf     fapi2 buffer
 * @return      fapi2 return code
 */
fapi2::ReturnCode checkOCMBConfig( CONST_FAPI2_PROC& i_procTgt, uint64_t& io_configVector )
{
    FAPI_INF( ">> checkOCMBConfig" );
    auto l_omiChiplets = i_procTgt.getChildren<fapi2::TARGET_TYPE_OMI>( fapi2::TARGET_STATE_PRESENT );

    uint64_t l_tempVector = 0;

    for( auto l_omi : l_omiChiplets )
    {
        auto l_ocmbChips = l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>( fapi2::TARGET_STATE_PRESENT );

        for( auto l_ocmb : l_ocmbChips )
        {
            uint8_t l_ocmbPos = 0;
            uint8_t l_ocmbBitPos = 0;

            //OMI Pos same as OCMB position
            FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, l_omi, l_ocmbPos ),
                      "Failed to get OCMB position ");

            if( l_ocmb.isFunctional( ) )
            {
                l_tempVector = 0x8000000000000000ull;
                l_ocmbBitPos = l_ocmbPos + OCMB_POS;
                io_configVector |= ( l_tempVector >> l_ocmbBitPos ) ;

                FAPI_INF("OCMB Pos 0x%04x Bit Pos 0x%04x",
                         l_ocmbPos, l_ocmbBitPos );
            }
        }
    }

fapi_try_exit:
    FAPI_INF( ">> checkOCMBConfig" );
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------------------

fapi2::ReturnCode p10_check_proc_config ( CONST_FAPI2_PROC& i_procTgt, void* i_pHomerImage )
{
    FAPI_INF( ">> p10_check_proc_config" );

    uint64_t l_configVectVal = INIT_CONFIG_VALUE;
    uint8_t* pHomer;

    FAPI_TRY( validateInputArgs( i_procTgt, i_pHomerImage ),
              "Input Arguments Found Invalid" );

    pHomer = (uint8_t*)i_pHomerImage + XPMR_HOMER_OFFSET + XPMR_PROC_CONFIG_UAV_POS;

#ifndef __HOSTBOOT_MODULE
    g_targetTypeMap[fapi2::TARGET_TYPE_MCC]         =   "MCC";
    g_targetTypeMap[fapi2::TARGET_TYPE_PEC]         =   "PEC";
    g_targetTypeMap[fapi2::TARGET_TYPE_PHB]         =   "PHB";
#endif


    FAPI_TRY( checkChiplet< fapi2::TARGET_TYPE_MCC >
              ( i_procTgt, fapi2::TARGET_TYPE_MCC, l_configVectVal, MCC_POS ),
              "Failed to get MC configuration" );

    FAPI_TRY( checkChiplet< fapi2::TARGET_TYPE_PEC >
              ( i_procTgt, fapi2::TARGET_TYPE_PEC, l_configVectVal, PEC_POS ),
              "Failed to get PEC configuration" );

    FAPI_TRY( checkChiplet<fapi2::TARGET_TYPE_PHB>
              ( i_procTgt, fapi2::TARGET_TYPE_PHB, l_configVectVal, PHB_POS ),
              "Failed to get PHB configuration" );

    FAPI_TRY( checkIOHSConfig( i_procTgt, l_configVectVal ) ,
              "Failed to get IOHS configuration" );

    FAPI_TRY( checkOCMBConfig( i_procTgt, l_configVectVal ),
              "Failed to get OCMB  configuration" );

    FAPI_INF( "Updating Vector in HOMER" );
    *(uint64_t*)pHomer  = htobe64( l_configVectVal );

    FAPI_IMP( "Config Vector is 0x%016lx  ", l_configVectVal );
    FAPI_IMP( "Reading back 0x%016lx  ", htobe64( (*(uint64_t*)pHomer)) );

fapi_try_exit:

    FAPI_INF( "<< p10_check_proc_config" );
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------------------
