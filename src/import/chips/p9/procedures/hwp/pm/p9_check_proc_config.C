/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_check_proc_config.C $ */
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

#include <stdint.h>

///
/// @file   p9_check_proc_config.C
/// @brief  describes interface for a HWP that generates a bit vector corresponding to P9 chip config.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          3
/// *HWP Consumed by:    Hostboot:Phyp
//

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p9_check_proc_config.H>
#include <p9_hcd_memmap_base.H>
#include <endian.h>
#include <map>
#include <stdint.h>


#ifndef __HOSTBOOT_MODULE
    std::map< fapi2::TargetType, std::string > g_targetTypeMap;
#endif
/**
 * @brief   misc local constants
 */
enum
{
    INIT_CONFIG_VALUE       =       0x8000000C09800000ull,
    QPMR_PROC_CONFIG_POS    =       0xBFC18,
};

/**
 * @brief   bit position for various chiplets in config vector.
 */
enum
{
    MCS_POS             =   1,
    MBA_POS             =   9,
    MEM_BUF_POS         =   17,
    XBUS_POS            =   25,
    PHB_POS             =   30,
    CAPP_POS            =   37,
    OBUS_POS            =   41,
    NVLINK_POS          =   45,
    OBUS_BRICK_0_POS    =   0,
    OBUS_BRICK_1_POS    =   1,
    OBUS_BRICK_2_POS    =   2,
    OBUS_BRICK_9_POS    =   9,
    OBUS_BRICK_10_POS   =   10,
    OBUS_BRICK_11_POS   =   11,

};

/**
 * @brief   validates the input arguments for the HWP.
 * @param[in]   i_procTgt       fapi2 target for P9 chip.
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
 * @brief   checks Memory buf configuration and updates config vector buffer.
 * @param[in]   i_procTgt       fapi2 target for P9
 * @param[in]   i_configBuf     fapi2 buffer
 * @return      fapi2 return code
 */
fapi2::ReturnCode checkMemConfig( CONST_FAPI2_PROC& i_procTgt, uint64_t& io_configVector )
{
    FAPI_INF( ">> checkMemConfig" );
    auto l_dmiChiplets = i_procTgt.getChildren<fapi2::TARGET_TYPE_DMI>( fapi2::TARGET_STATE_PRESENT );

    uint64_t l_tempVector = 0;

    for( auto l_dmi : l_dmiChiplets )
    {
        auto l_cenChips = l_dmi.getChildren<fapi2::TARGET_TYPE_MEMBUF_CHIP>( fapi2::TARGET_STATE_PRESENT );

        for( auto l_cent : l_cenChips )
        {
            auto l_mbaChiplets = l_cent.getChildren<fapi2::TARGET_TYPE_MBA>( fapi2::TARGET_STATE_PRESENT );
            uint8_t l_memBufPos = 0;
            uint8_t l_memBufBitPos = 0;

            //DMI Pos same as membuf position
            FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, l_dmi, l_memBufPos ),
                      "Failed to get membuf position ");

            if( l_cent.isFunctional( ) )
            {
                l_tempVector = 0x8000000000000000ull;
                l_memBufBitPos = l_memBufPos + MEM_BUF_POS;
                io_configVector |= ( l_tempVector >> l_memBufBitPos ) ;

                FAPI_INF("Mem Buf Pos 0x%04x Bit Pos 0x%04x",
                         l_memBufPos, l_memBufBitPos );
            }

            for( auto l_mba : l_mbaChiplets )
            {
                if( l_mba.isFunctional( ) )
                {
                    uint8_t l_mbaPos = 0;
                    uint8_t l_mbaBitPos = 0;
                    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, l_mba, l_mbaPos ),
                              "Failed to get mba position ");

                    l_mbaBitPos = ( l_mbaChiplets.size() * l_memBufPos ) + l_mbaPos + MBA_POS;
                    l_tempVector = 0x8000000000000000ull;
                    io_configVector |= ( l_tempVector >> l_mbaBitPos );

                    FAPI_INF("Mba Pos 0x%04x Bit Pos 0x%04x",
                             l_mbaPos, l_mbaBitPos );
                }
            }
        }
    }

fapi_try_exit:
    FAPI_INF( ">> checkMemConfig" );
    return fapi2::current_err;
}

/**
 * @brief   checks Memory buf configuration and updates config vector buffer.
 * @param[in]   i_procTgt           fapi2 target for P9
 * @param[in]   io_configVector     Unit Avaialability Vector
 * @param[in]   i_oBusStartPos      start bit position for OBUS
 * @param[in]   i_nvLinkPos         start bit position for NV Link
 * @return      fapi2 return code
 */
fapi2::ReturnCode checkObusChipletHierarchy( CONST_FAPI2_PROC& i_procTgt,
        uint64_t& io_configVector, uint8_t i_oBusStartPos, uint8_t i_nvLinkPos )
{
    auto l_obusList =
        i_procTgt.getChildren < fapi2::TARGET_TYPE_OBUS > ( fapi2::TARGET_STATE_PRESENT );

    uint64_t l_tempVector = 0;

    for( auto itv : l_obusList )
    {
        uint8_t l_oBusPos = 0;

        FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, itv, l_oBusPos ),
                  "Failed to get chiplet position " );

        if( itv.isFunctional() )
        {
            uint8_t l_configMode = 0;
            auto l_oBusBrickList = itv.getChildren<fapi2::TARGET_TYPE_OBUS_BRICK>( fapi2::TARGET_STATE_FUNCTIONAL );

            l_tempVector = 0x8000000000000000ull;

            FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_OPTICS_CONFIG_MODE, itv, l_configMode ),
                      "Failed To Read ATTR_OPTICS_CONFIG_MODE" );

            for ( auto l_obusBrick : l_oBusBrickList )
            {
                uint8_t l_brickPos   = 0;
                uint8_t l_brickBitPos = 0;


                if( fapi2::ENUM_ATTR_OPTICS_CONFIG_MODE_NV == l_configMode )
                {
                    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_obusBrick, l_brickPos ),
                              "Error from FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS)" );

                    switch( l_brickPos )
                    {
                        case OBUS_BRICK_0_POS:
                        case OBUS_BRICK_1_POS:
                        case OBUS_BRICK_2_POS:

                            l_brickBitPos   =   l_brickPos + i_nvLinkPos;

                            break;

                        case OBUS_BRICK_9_POS:
                            l_brickBitPos   =   i_nvLinkPos + 3;
                            break;

                        case OBUS_BRICK_10_POS:
                            l_brickBitPos   =   i_nvLinkPos + 4;
                            break;

                        case OBUS_BRICK_11_POS:
                            l_brickBitPos   =   i_nvLinkPos + 5;
                            break;

                        default:

                            FAPI_ASSERT_NOEXIT( ( false ),
                                                fapi2::BAD_OBUS_BRICK_POSITION()
                                                .set_TARGET( l_obusBrick )
                                                .set_OBRICK_POS( l_brickPos ),
                                                "Bad or unexpected Obus brick position" );
                            break;

                    }

                    io_configVector |=  l_tempVector >> l_brickBitPos;

#ifndef __HOSTBOOT_MODULE

                    FAPI_INF( "OBus Brick Pos %02d Bit Pos 0x%02x (%d) UAV 0x%016lx",
                              l_brickPos, l_brickBitPos, l_brickBitPos, io_configVector );

#endif
                }
            }
        }
    }

fapi_try_exit:

    FAPI_INF( "<< p9_check_proc_config" );
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------------------

fapi2::ReturnCode p9_check_proc_config ( CONST_FAPI2_PROC& i_procTgt, void* i_pHomerImage )
{
    FAPI_INF( ">> p9_check_proc_config" );

    uint64_t l_configVectVal = INIT_CONFIG_VALUE;
    uint8_t* pHomer = (uint8_t*)i_pHomerImage + QPMR_HOMER_OFFSET +
                      QPMR_PROC_CONFIG_POS;
    uint8_t l_chipName = 0;
#ifndef __HOSTBOOT_MODULE
    g_targetTypeMap[fapi2::TARGET_TYPE_MCS]         =   "MCS";
    g_targetTypeMap[fapi2::TARGET_TYPE_MCA]         =   "MCA";
    g_targetTypeMap[fapi2::TARGET_TYPE_XBUS]        =   "XBUS";
    g_targetTypeMap[fapi2::TARGET_TYPE_OBUS]        =   "OBUS";
    g_targetTypeMap[fapi2::TARGET_TYPE_CAPP]        =   "CAPP";
    g_targetTypeMap[fapi2::TARGET_TYPE_PHB]         =   "PHB";
    g_targetTypeMap[fapi2::TARGET_TYPE_MEMBUF_CHIP] =   "MEM BUF";
    g_targetTypeMap[fapi2::TARGET_TYPE_MBA]         =   "MBA";
    g_targetTypeMap[fapi2::TARGET_TYPE_OBUS_BRICK]  =   "OBUS_BRICK";
#endif

    FAPI_TRY( validateInputArgs( i_procTgt, i_pHomerImage ),
              "Input Arguments Found Invalid" );

    FAPI_TRY( checkChiplet< fapi2::TARGET_TYPE_MCS >
              ( i_procTgt, fapi2::TARGET_TYPE_MCS, l_configVectVal, MCS_POS ),
              "Failed to get MCS configuration" );

    FAPI_TRY( checkChiplet< fapi2::TARGET_TYPE_XBUS>
              ( i_procTgt, fapi2::TARGET_TYPE_XBUS, l_configVectVal, XBUS_POS ),
              "Failed to get XBUS configuration" );

    FAPI_TRY( checkChiplet<fapi2::TARGET_TYPE_PHB>
              ( i_procTgt, fapi2::TARGET_TYPE_PHB, l_configVectVal, PHB_POS ),
              "Failed to get PHB configuration" );

    FAPI_TRY( checkChiplet<fapi2::TARGET_TYPE_CAPP>
              ( i_procTgt, fapi2::TARGET_TYPE_CAPP, l_configVectVal, CAPP_POS ),
              "Failed to get CAPP configuration" );

    FAPI_TRY(  checkObusChipletHierarchy ( i_procTgt, l_configVectVal, OBUS_POS, NVLINK_POS ),
               "Failed to get OBUS Hierarchy configuration" );

    FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_procTgt, l_chipName );

    if( fapi2::ENUM_ATTR_NAME_CUMULUS == l_chipName )
    {
        FAPI_TRY( checkMemConfig( i_procTgt, l_configVectVal ),
                  "Failed to get Memory  configuration" );
    }
    else
    {
        //FIXME: RTC 180154 Needs Review for Axone

        FAPI_TRY( checkChiplet< fapi2::TARGET_TYPE_MCA >
                  ( i_procTgt, fapi2::TARGET_TYPE_MCA, l_configVectVal, MBA_POS ),
                  "Failed to get MCA Position" );
    }

    FAPI_INF( "Updating Vector in HOMER" );
    *(uint64_t*)pHomer  = htobe64( l_configVectVal );

    FAPI_IMP( "Config Vector is 0x%016lx  ", l_configVectVal );
    FAPI_IMP( "Reading back 0x%016lx  ", htobe64( (*(uint64_t*)pHomer)) );

fapi_try_exit:

    FAPI_INF( "<< p9_check_proc_config" );
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------------------
