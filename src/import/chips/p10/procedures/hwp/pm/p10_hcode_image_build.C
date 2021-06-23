/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_hcode_image_build.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file   p10_hcode_image_build.C
/// @brief  Implements HWP that builds the Hcode image in HOMER.
///
// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
// *HWP Team:           PM
// *HWP Level:          2
// *HWP Consumed by:    HB: HBRT

// *INDENT-OFF*

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <map>
#include <endian.h>
#include <p10_hcode_image_build.H>
#include <p10_hcode_image_defines.H>
#include <p10_hcd_memmap_base.H>
#include <p10_scan_ring_util.H>
#include <p10_hcd_memmap_base.H>
#include <p10_ipl_image.H>
#include <p10_ipl_customize.H>
#include <p10_stop_api.H>
#include <p10_pstate_parameter_block.H>
#include <p10_qme_customize.H>
#include <p10_qme_meta_data.H>
#include <p10_qme_build_attributes.H>
#include <p10_scan_compression.H>
#include <p10_stop_util.H>
#include <p10_fbc_utils.H>
#include <p10_fbc_core_topo.H>

extern "C"
{

namespace hcodeImageBuild
{

/**
 * @brief   Misc constants local to HWP code.
 */
enum
{
    TEMP_ARRAY_SIZE     =   50,
    PLAT_NAME_SIZE      =   20,
    ENABLE_ALL_CORE     =   0xFFFFFFFF,
    BCE_RD_BLOCK_SIZE   =   0x20,
    SHIFT_RD_BLOCK_SIZE =   5,
    INST_RING_OFFSET    =   2,
    OVRD_RING_OFFSET    =   0x44,
    EXT_MEM_ADDR        =   0x80000000,
    QME_VER_BASE        =   0x00,
    BLK_SIZE_32B        =   32,
    QME_SRAM_OPT_VER    =   0x514d455f5f312e31ull,
    QME_SRAM_MAGIC_WORD =   0x514d455f5f312e30ull,
    QME_VER_BASE_ASCII  =   0x514d455f5f312e30ull,
    XGPE_RELOC_BASE     =   0xfff34000,
    XGPE_48K_VER        =   0x11,
};

/**
 * @brief Misc error code local to HWP code.
 */
enum INTERNAL_ERR_CODE
{
    BAD_SECTN_NAME      =   0x01,
    SECTN_LOOKUP_ERR    =   0x02,
    SECTN_SIZE_ERR      =   0x03,
};

/**
 * @brief models a section of HOMER.
 * @note this section may be HOMER resident only and may not be copied to
 * platform's SRAM.
 */
struct ImgSectnSumm
{
    char        iv_sectnName[TEMP_ARRAY_SIZE];
    uint32_t    iv_sectnOffset;
    uint32_t    iv_sectnLength;
    ImgSectnSumm()
      : iv_sectnOffset( 0 ),
        iv_sectnLength( 0 )
    { }
};

/**
 * @brief   struct used to manipulate scan ring in HOMER.
 */
struct RingBufData
{
    void* iv_pRingBuffer;
    uint32_t     iv_ringBufSize;
    void* iv_pWorkBuf1;
    uint32_t     iv_sizeWorkBuf1;
    void* iv_pWorkBuf2;
    uint32_t     iv_sizeWorkBuf2;
    void* iv_pWorkBuf3;
    uint32_t     iv_sizeWorkBuf3;
    void *       iv_pOverride;

    RingBufData( void* i_pRingBuf1, const uint32_t i_ringSize,
                 void* i_pWorkBuf1, const uint32_t i_sizeWorkBuf1,
                 void* i_pWorkBuf2, const uint32_t i_sizeWorkBuf2,
                 void* i_pWorkBuf3, const uint32_t i_sizeWorkBuf3, void *i_pRingOverride  ) :
        iv_pRingBuffer( i_pRingBuf1 ),
        iv_ringBufSize( i_ringSize ),
        iv_pWorkBuf1( i_pWorkBuf1 ),
        iv_sizeWorkBuf1( i_sizeWorkBuf1 ),
        iv_pWorkBuf2( i_pWorkBuf2 ),
        iv_sizeWorkBuf2( i_sizeWorkBuf2 ),
        iv_pWorkBuf3( i_pWorkBuf3 ),
        iv_sizeWorkBuf3( i_sizeWorkBuf3 ),
        iv_pOverride( i_pRingOverride )

    {}

    RingBufData():
        iv_pRingBuffer( NULL ),
        iv_ringBufSize( 0 ),
        iv_pWorkBuf1( NULL ),
        iv_sizeWorkBuf1( 0 ),
        iv_pWorkBuf2( NULL ),
        iv_sizeWorkBuf2( 0 ),
        iv_pWorkBuf3( NULL ),
        iv_sizeWorkBuf3( 0 ),
        iv_pOverride( NULL )
    { }
};

//-------------------------------------------------------------------------
/**
 * @brief captures stat pertaining to RS4 container.
 */
struct Rs4Stat
{
    uint16_t iv_cmnRingMaxSize;
    uint16_t iv_cmnRingAvgSize;
    RingId_t iv_maxSizeCmnRing;
    uint16_t iv_instRingMaxSize;
    uint16_t iv_instRingAvgSize;
    RingId_t iv_maxSizeInstRing;
    uint16_t iv_ovrdRingMaxSize;
    uint16_t iv_ovrdRingAvgSize;
    RingId_t iv_maxSizeOvrdRing;
    uint8_t  iv_reserve[2];
};
//-------------------------------------------------------------------------

class ImageBuildRecord
{
    public:

    /**
     * @brief constructor
     * @param[in]   i_homerBuf      points to base of HOMER image.
     */
    ImageBuildRecord(  uint8_t * i_homerBuf, const char * i_name )
      : iv_homerBufPtr( i_homerBuf ),
        iv_currentWriteOffset( 0 ),
        iv_regionBaseAddress( 0 )
    {
        memset( iv_currentSectn, 0, TEMP_ARRAY_SIZE );
        memset( iv_platName, 0, PLAT_NAME_SIZE );
        memcpy( iv_platName, i_name, PLAT_NAME_SIZE );
        iv_maxSizeList["XPMR Header"]       =   XPMR_HEADER_SIZE;
        iv_maxSizeList["XGPE Boot Copier"]  =   XGPE_BOOT_COPIER_SIZE;
        iv_maxSizeList["XGPE Boot Loader"]  =   XGPE_BOOT_LOADER_LENGTH;
        iv_maxSizeList["XGPE Hcode"]        =   XGPE_HCODE_SIZE;
        iv_maxSizeList["XGPE Op Trace"]     =   XGPE_OPTRACE_LENGTH;
        iv_maxSizeList["QME Hcode"]         =   QME_HCODE_SIZE;
        iv_maxSizeList["QME Common Ring"]   =   QME_COMMON_RING_SIZE;
        iv_maxSizeList["QME Override Ring"] =   QME_OVERRIDE_RING_SIZE;
        iv_maxSizeList["QME Inst Sectn"]    =   QME_INST_RING_SIZE;
        iv_maxSizeList["QME Meta Data"]     =   QME_HCODE_SIZE;
        iv_maxSizeList["QME SRAM Size"]     =   QME_SRAM_SIZE;
        iv_maxSizeList["QME SCOM Restore"]  =   SCOM_RESTORE_SIZE_PER_CORE;
        iv_maxSizeList["SELF BIN"]          =   SMF_THREAD_LAUNCHER_SIZE;
        iv_maxSizeList["SELF"]              =   SELF_SAVE_RESTORE_REGION_SIZE;
        iv_maxSizeList["PPMR Header"]       =   PPMR_HEADER_SIZE;
        iv_maxSizeList["PGPE Boot Copier"]  =   PGPE_BOOT_COPIER_SIZE;
        iv_maxSizeList["PGPE Boot Loader"]  =   PGPE_BOOT_LOADER_SIZE;
        iv_maxSizeList["PGPE Hcode"]        =   PGPE_HCODE_SIZE;
        iv_maxSizeList["GPSPB"]             =   PGPE_GLOBAL_PSTATE_PARAM_BLOCK_SIZE;
        iv_maxSizeList["PGPE SRAM Size"]    =   OCC_SRAM_PGPE_REGION_SIZE;
        iv_maxSizeList["OPSPB"]             =   OCC_PSTATE_PARAM_BLOCK_REGION_SIZE;
        iv_maxSizeList["PState Table"]      =   PGPE_PSTATE_OUTPUT_TABLES_REGION_SIZE;
        iv_maxSizeList["WOF Tables"]        =   OCC_WOF_TABLES_SIZE;
        iv_maxSizeList["PGPE Op Trace"]     =   PGPE_OPTRACE_LENGTH;
    }

    /**
     * @brief   destructor
     */
    ~ImageBuildRecord( ) { };

    /**
     * @brief   records offset to start of image section wrt HOMER region base and length.
     * @param[in]   i_sectn         name of the section
     * @param[in]   i_offset        offset to start of the section.
     * @param[in]   i_sectnLength   section length
     * @return      IMG_BUILD_SUCCESS in case of success, error code otherwise.
     */
    uint32_t setSection( const char * i_sectn, uint32_t i_offset, uint32_t i_sectnLength );

    /**
     * @brief  returns image section offset wrt to HOMER region base.
     * @param[in] i_sectn           name of the image section
     * @param[in] o_sectionOffset   an instance of ImgSectnSumm
     * @return      IMG_BUILD_SUCCESS in case of success, error code otherwise.
     */
    uint32_t getSection( const char * i_sectn, ImgSectnSumm & o_sectionOffset );
    /**
     * @brief  returns image section offset wrt to HOMER region base.
     * @param[in] i_sectn       name of the image section
     * @param[in] i_imgSectn    an instance of ImgSectnSumm
     * @return      IMG_BUILD_SUCCESS in case of success, error code otherwise.
     */
    uint32_t editSection( const char * i_sectn, ImgSectnSumm & i_imgSectn );

    /**
     * @brief generates report summarizing all sections and respective offsets.
     */
    void dumpBuildRecord ();

    /**
     * @brief   verifies image
     */
    uint32_t verifyBuild();

    /**
     * @brief   checks section size against max size expected.
     * @param[in]   i_sectionSize   size of the section
     * @return      IMG_BUILD_SUCCESS in case of success, error code otherwise.
     */
     uint32_t checkSize( uint32_t i_sectionSize );

    /**
     * @brief returns current offset to which imag ehas been built for a platform.
     * @note: if an instance monitors QME build, this returns offset to which
     *        QME image exists. It is used during image build to know current
     *        position before appending a new section.
     */
    uint32_t getCurrentOffset() { return iv_currentWriteOffset; };

    /**
     * @brief sets base addres of region in HOMER.
     * @param[in]  i_regionBase
     */
     void setsRegionBase( uint64_t i_regionBase ) { iv_regionBaseAddress = i_regionBase; }

    /**
     * @brief returns region's base address
     */
    uint64_t getRegionBase( ) { return iv_regionBaseAddress ; }

    /**
     * @brief sets the section under build.
     * @note it is not built as yet.
     */
    void setCurrentSectn( const char * i_sectn ) { memcpy( iv_currentSectn, i_sectn, ( strlen(i_sectn) + 1 ) ); }

    /**
     * @brief returns QME Image version.
     */
    uint32_t getPpeImageVer() { return iv_ppeImageVer; }

    /**
     * @brief inits QME Image version.
     */
    void setPpeImageVer( uint32_t i_ppeImgVer ) { iv_ppeImageVer = i_ppeImgVer; }

    private:
    std::vector< ImgSectnSumm > iv_sectnList;
    uint8_t * iv_homerBufPtr;
    uint32_t  iv_currentWriteOffset;
    uint64_t  iv_regionBaseAddress;
    uint8_t   iv_platName[PLAT_NAME_SIZE];
    uint8_t   iv_currentSectn[TEMP_ARRAY_SIZE];
    std::map< const char *, uint32_t>  iv_maxSizeList;
    uint32_t  iv_ppeImageVer;
};

//--------------------------------------------------------------------------------------------------------

uint32_t ImageBuildRecord::setSection( const char * i_sectn, uint32_t i_offset, uint32_t i_sectnLen )
{
    uint32_t l_rc   =   IMG_BUILD_SUCCESS;

    if( i_sectn )
    {
        ImgSectnSumm l_sectn;
        memcpy( l_sectn.iv_sectnName, i_sectn, TEMP_ARRAY_SIZE );
        l_sectn.iv_sectnOffset  =   i_offset;
        l_sectn.iv_sectnLength  =   i_sectnLen;
        iv_sectnList.push_back( l_sectn );

        iv_currentWriteOffset += i_sectnLen;
        FAPI_DBG(" After Section Index 0x%08x", iv_currentWriteOffset );
    }
    else
    {
        l_rc        =   BAD_SECTN_NAME;
    }

    return l_rc;
}

//--------------------------------------------------------------------------------------------------------

uint32_t ImageBuildRecord::getSection( const char * i_sectn, ImgSectnSumm & o_imgSectn )
{
    uint32_t l_rc   =   IMG_BUILD_SUCCESS;

    do
    {
        if( !i_sectn )
        {
            l_rc    =   BAD_SECTN_NAME;
            break;
        }

        for( auto sectn : iv_sectnList )
        {
            if( !memcmp( sectn.iv_sectnName, i_sectn, TEMP_ARRAY_SIZE ) )
            {
                o_imgSectn     =   sectn;
                break;
            }
        }

    } while(0);

    return l_rc;
}

//--------------------------------------------------------------------------------------------------------
uint32_t ImageBuildRecord::editSection( const char * i_sectn, ImgSectnSumm & i_imgSectn )
{
    uint32_t l_rc   =   IMG_BUILD_SUCCESS;

    do
    {
        if( !i_sectn )
        {
            l_rc    =   BAD_SECTN_NAME;
            break;
        }

        for( auto &sectn : iv_sectnList )
        {
            if( !memcmp( sectn.iv_sectnName, i_sectn, TEMP_ARRAY_SIZE ) )
            {
                sectn.iv_sectnOffset    = i_imgSectn.iv_sectnOffset;
                sectn.iv_sectnLength    = i_imgSectn.iv_sectnLength;
                iv_currentWriteOffset   = i_imgSectn.iv_sectnOffset + i_imgSectn.iv_sectnLength;
                FAPI_INF( "Editing Section , Offset 0x%08x Length 0x%08x Current Index 0x%08x",
                            sectn.iv_sectnOffset, sectn.iv_sectnLength, iv_currentWriteOffset );
                break;
            }
        }

    } while(0);

    return l_rc;
}
//--------------------------------------------------------------------------------------------------------

uint32_t ImageBuildRecord::checkSize( uint32_t i_sectionSize )
{
    uint32_t l_rc   =   IMG_BUILD_SUCCESS;
    ImgSectnSumm  l_imgSection;

    for ( auto sectn = iv_maxSizeList.begin(); sectn != iv_maxSizeList.end();
          sectn++ )
    {
        if( !memcmp( sectn->first, iv_currentSectn, TEMP_ARRAY_SIZE ) )
        {
            if( i_sectionSize > sectn->second )
            {
                l_rc    =   SECTN_SIZE_ERR;
                FAPI_ERR( "Section Size Error for %s ", iv_currentSectn );
                break;
            }
        }
    }

    return l_rc;
}

//--------------------------------------------------------------------------------------------------------

void ImageBuildRecord::dumpBuildRecord( )
{
    FAPI_DBG( "============================ %s Section Offsets ==============================", iv_platName );

    for( auto sectn : iv_sectnList )
    {
        FAPI_INF( "%-35s   :   0x%08x   :   Length   :   0x%08x",
                  sectn.iv_sectnName, sectn.iv_sectnOffset, sectn.iv_sectnLength );
    }

    FAPI_DBG( "Current CPMR Write Offset    :   0x%08x     ", iv_currentWriteOffset );

    FAPI_DBG( "===============================================================================" );
}

//--------------------------------------------------------------------------------------------------------

uint32_t ImageBuildRecord::verifyBuild( )
{
    return 0;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief   validates arguments passed for hcode image build
 * @param[in]   refer to p10_hcode_image_build arguments
 * @return  fapi2 return code
*/
fapi2::ReturnCode validateInputArguments( void* const i_pImageIn, void* i_pImageOut,
        SysPhase_t i_phase, ImageType_t i_imgType,
        void* i_pBuf1, uint32_t i_bufSize1, void* i_pBuf2,
        uint32_t i_bufSize2, void* i_pBuf3, uint32_t i_bufSize3,
        void* i_pBuf4, uint32_t i_bufSize4 )
{
    uint32_t l_rc = IMG_BUILD_SUCCESS;
    uint32_t hwImagSize = 0;

    FAPI_INF(">> validateInputArguments ...");

    FAPI_ASSERT( (( i_pImageIn != NULL ) &&
                  ( i_pImageIn != i_pImageOut )),
                 fapi2::HW_IMG_PTR_ERROR()
                 .set_HW_IMG_BUF_PTR( i_pImageIn )
                 .set_HOMER_IMG_BUF_PTR( i_pImageOut ),
                 "Bad pointer to HW Image" );

    FAPI_ASSERT( ( i_pImageOut != NULL ),
                 fapi2::HOMER_IMG_PTR_ERROR()
                 .set_HOMER_IMG_BUF_PTR( i_pImageOut ),
                 "Bad pointer to HOMER Image" );

    l_rc = p9_xip_image_size( i_pImageIn, &hwImagSize );

    FAPI_INF("size is 0x%08X; xip_image_size RC is 0x%02x HARDWARE_IMG_SIZE 0x%08X  Sz 0x%08X",
             hwImagSize, l_rc, HARDWARE_IMG_SIZE,  hwImagSize );

    FAPI_ASSERT( (( IMG_BUILD_SUCCESS == l_rc ) && ( hwImagSize > 0 ) &&
                  ( HARDWARE_IMG_SIZE >= hwImagSize )),
                 fapi2::HW_IMAGE_INVALID_SIZE()
                 .set_HW_IMG_SIZE( hwImagSize )
                 .set_MAX_HW_IMG_SIZE( HARDWARE_IMG_SIZE ),
                 "Hardware image size found out of range" );

    FAPI_ASSERT( (( i_phase  > PHASE_NA ) && ( i_phase < PHASE_END )),
                 fapi2::HCODE_INVALID_PHASE()
                 .set_SYS_PHASE( i_phase ),
                 "Invalid value passed as build phase" );

    FAPI_ASSERT( ( i_pBuf1 != NULL ),
                 fapi2::HCODE_INVALID_TEMP1_BUF()
                 .set_TEMP1_BUF_SIZE( i_bufSize1 ),
                 "Invalid temp buffer1 passed for hcode image build" );

    FAPI_ASSERT( ( i_pBuf2 != NULL ),
                 fapi2::HCODE_INVALID_TEMP2_BUF()
                 .set_TEMP2_BUF_SIZE( i_bufSize2 ),
                 "Invalid temp buffer2 passed for hcode image build" );

    FAPI_ASSERT( ( i_pBuf3 != NULL ),
                 fapi2::HCODE_INVALID_TEMP3_BUF()
                 .set_TEMP3_BUF_SIZE( i_bufSize3 ),
                 "Invalid temp buffer3 passed for hcode image build" );

    FAPI_ASSERT( ( i_pBuf4 != NULL ),
                 fapi2::HCODE_INVALID_TEMP4_BUF()
                 .set_TEMP4_BUF_SIZE( i_bufSize4 ),
                 "Invalid temp buffer4 passed for hcode image build" );

    FAPI_ASSERT( ( i_bufSize1 != 0  ) ,
                 fapi2::HCODE_INVALID_TEMP1_BUF_SIZE()
                 .set_TEMP1_BUF_SIZE( i_bufSize1 ),
                 "Invalid size for temp buf1 passed for hcode image build" );

    FAPI_ASSERT( ( i_bufSize2 != 0 ),
                 fapi2::HCODE_INVALID_TEMP2_BUF_SIZE()
                 .set_TEMP2_BUF_SIZE( i_bufSize2 ),
                 "Invalid size for temp buf2 passed for hcode image build" );

    FAPI_ASSERT( ( i_bufSize3 != 0 ),
                 fapi2::HCODE_INVALID_TEMP3_BUF_SIZE()
                 .set_TEMP3_BUF_SIZE( i_bufSize3 ),
                 "Invalid size for temp buf3 passed for hcode image build" );

    FAPI_ASSERT( ( i_bufSize4 != 0 ),
                 fapi2::HCODE_INVALID_TEMP4_BUF_SIZE()
                 .set_TEMP4_BUF_SIZE( i_bufSize4 ),
                 "Invalid size for temp buf4 passed for hcode image build" );

    FAPI_ASSERT( ( i_imgType.isBuildValid() ),
                 fapi2::HCODE_INVALID_IMG_TYPE(),
                 "Invalid image type passed for hcode image build" );
    FAPI_INF("<< validateInputArguments ...");

fapi_try_exit:
    return fapi2::current_err;
}

//------------------------------------------------------------------------------

/**
 * @brief returns PIR value for a given core and thread.
 * @param[in]   i_corePos       core position
 * @param[in]   i_threadPos     thread position
 * @param[in]   i_fuseMode      fuse status of core.
 * @return      PIR value
 */
uint64_t getPirValue( uint32_t i_corePos, uint32_t i_threadPos, uint32_t i_fuseMode )
{
    using namespace stopImageSection;
    uint64_t l_pir      = 0;
    uint8_t  l_tempPir  = 0;
    l_tempPir = 0;
    l_tempPir = (i_corePos / MAX_CORES_PER_QUAD ) << MAX_CORES_PER_QUAD;
    i_corePos = i_corePos % MAX_CORES_PER_QUAD;

    switch( i_corePos )
    {
        case 0:
            break;

        case 1:
            if( i_fuseMode )
            {
                l_tempPir |= FUSED_CORE_BIT3;
            }
            else
            {
                l_tempPir |= FUSED_CORE_BIT1;
            }

            break;

        case 2:
            l_tempPir |= FUSED_CORE_BIT0;
            break;

        case 3:
            if( i_fuseMode )
            {
                l_tempPir |= ( FUSED_CORE_BIT0 | FUSED_CORE_BIT3 );
            }
            else
            {
                l_tempPir |= (FUSED_CORE_BIT0 | FUSED_CORE_BIT1 );
            }

            break;
    }

    switch( i_threadPos )
    {
        case 0:
            break;

        case 1:
            if( i_fuseMode )
            {
                l_tempPir |= FUSED_CORE_BIT2;
            }
            else
            {
                l_tempPir |= FUSED_CORE_BIT3;
            }

            break;

        case 2:
            if( i_fuseMode )
            {
                l_tempPir |= FUSED_CORE_BIT1;
            }
            else
            {
                l_tempPir |= FUSED_CORE_BIT2;
            }

            break;

        case 3:
            if( i_fuseMode )
            {
                l_tempPir |= ( FUSED_CORE_BIT1 | FUSED_CORE_BIT2 );
            }
            else
            {
                l_tempPir |= ( FUSED_CORE_BIT2 | FUSED_CORE_BIT3);
            }

            break;
    }

    l_pir = l_tempPir;

    return l_pir;

}

//------------------------------------------------------------------------------

/**
 * @brief   extracts image section specific to a given EC level.
 * @param[in]   i_srcPtr        points to hardware image.
 * @param[in]   i_mainSecId     top level section of hw image( usually a XIP image of PPE )
 * @param[in]   i_secId         sub-section within a top level HW Image section
 * @return      IMG_BUILD_SUCCESS in case of success, error code otherwise
 */

uint32_t getXipImageSectn( uint8_t * i_srcPtr, uint8_t i_mainSecId, uint8_t i_secId, uint8_t i_ecLevel,
                           P9XipSection&  o_ppeSection )
{
    FAPI_DBG( ">> getXipImageSectn" );

    uint32_t rc = IMG_BUILD_SUCCESS;
    do
    {
        MyBool_t ecLvlSupported = UNDEFINED_BOOLEAN;

        rc = p9_xip_dd_section_support( i_srcPtr, i_mainSecId, i_secId, &ecLvlSupported );

        if( rc )
        {
            break;
        }

        if( ecLvlSupported )
        {
            FAPI_DBG(" Calling p9_xip_get_section 0x%08x EC 0x%08x", i_mainSecId, i_ecLevel );
            rc = p9_xip_get_section( i_srcPtr, i_mainSecId, &o_ppeSection, i_ecLevel );
        }
        else
        {
            rc = p9_xip_get_section( i_srcPtr, i_mainSecId, &o_ppeSection );
        }

        FAPI_INF("Multiple EC Level Support  : %s For Sec Id 0x%02x EC : 0x%02x",
                  ecLvlSupported ? "Yes" :"No", i_secId, i_ecLevel );
    }while(0);

    FAPI_DBG( "<< getXipImageSectn" );
    return rc;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief   Copies section of hardware image to HOMER
 * @param[in]   i_destPtr       a location in HOMER
 * @param[in]   i_srcPtr        a location in HW Image.
 * @param[in]   i_buildRecord   an instance of ImgSectnSumm
 * @param[in]   i_secId         XIP Section id to be copied.
 * @param[in]   i_ecLevel       ec level of chip
 * @param[out]  o_ppeSection    contains section details.
 * @return  IMG_BUILD_SUCCESS if successful, error code otherwise.
 */
uint32_t copySectionToHomer( uint8_t* i_destPtr, uint8_t* i_srcPtr, ImageBuildRecord & i_buildRecord, uint8_t i_secId ,
                             uint8_t i_ecLevel, P9XipSection&   o_ppeSection )
{
    FAPI_DBG( ">> copySectionToHomer" );
    uint32_t retCode = IMG_BUILD_SUCCESS;

    do
    {
        o_ppeSection.iv_offset      =   0;
        o_ppeSection.iv_size        =   0;

        uint32_t rcTemp = getXipImageSectn( i_srcPtr, i_secId, UNDEFINED_IPL_IMAGE_SID, i_ecLevel, o_ppeSection );

        if( rcTemp )
        {
            FAPI_ERR( "Failed To Get Section 0x%08X Of XIP RC 0x%08x", i_secId, rcTemp );
            retCode = BUILD_FAIL_INVALID_SECTN;
            break;
        }

        FAPI_DBG("o_ppeSection.iv_offset = %X, "
                 "o_ppeSection.iv_size = %X, "
                 "i_secId %d",
                 o_ppeSection.iv_offset,
                 o_ppeSection.iv_size,
                 i_secId);

        retCode    =   i_buildRecord.checkSize( o_ppeSection.iv_size );

        if( retCode )
        {
            break;
        }

        memcpy( i_destPtr, i_srcPtr + o_ppeSection.iv_offset, o_ppeSection.iv_size );
    }
    while(0);

    FAPI_DBG( "<< copySectionToHomer" );
    return retCode;
}

//------------------------------------------------------------------------------

/**
 * @brief   builds XPMR header in the HOMER.
 * @param[in]   i_pChipHomer        models P10's HOMER.
 * @param[in]   i_ppmrBuildRecord   XPMR region image build metadata
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildXpmrHeader( Homerlayout_t* i_pChipHomer, ImageBuildRecord & i_xpmrBuildRecord )
{
    ImgSectnSumm   l_sectn;
    XpmrHeader_t * l_pXpmrHdr   =
            (XpmrHeader_t *) i_pChipHomer->iv_xpmrRegion.iv_xpmrHeader;

    //XGPE Boot Copier
    i_xpmrBuildRecord.getSection( "XGPE Boot Copier", l_sectn );
    l_pXpmrHdr->iv_bootCopierOffset = l_sectn.iv_sectnOffset;

    //XGPE Boot Loader
    i_xpmrBuildRecord.getSection( "XGPE Boot Loader", l_sectn );
    l_pXpmrHdr->iv_bootLoaderOffset =   l_sectn.iv_sectnOffset;
    l_pXpmrHdr->iv_bootLoaderLength =   XGPE_BOOT_LOADER_LENGTH;

    //XGPE Hcode
    i_xpmrBuildRecord.getSection( "XGPE Hcode", l_sectn );
    l_pXpmrHdr->iv_xgpeHcodeOffset  =   l_sectn.iv_sectnOffset;
    l_pXpmrHdr->iv_xgpeHcodeLength  =   l_sectn.iv_sectnLength;

    //XGPE SRAM
    l_pXpmrHdr->iv_xgpeSramSize     =   l_sectn.iv_sectnLength;

    i_xpmrBuildRecord.dumpBuildRecord();

#ifndef __HOSTBOOT_MODULE
    l_pXpmrHdr->iv_bootCopierOffset     =   htobe32(l_pXpmrHdr->iv_bootCopierOffset);
    l_pXpmrHdr->iv_bootLoaderOffset     =   htobe32(l_pXpmrHdr->iv_bootLoaderOffset);
    l_pXpmrHdr->iv_bootLoaderLength     =   htobe32(l_pXpmrHdr->iv_bootLoaderLength);
    l_pXpmrHdr->iv_xgpeHcodeOffset      =   htobe32(l_pXpmrHdr->iv_xgpeHcodeOffset);
    l_pXpmrHdr->iv_xgpeHcodeLength      =   htobe32(l_pXpmrHdr->iv_xgpeHcodeLength);
    l_pXpmrHdr->iv_xgpeSramSize         =   htobe32(l_pXpmrHdr->iv_xgpeSramSize);

    FAPI_DBG( "====================== XPMR Header =======================" );
    FAPI_DBG( "XPMR BC Offset             0x%08x", htobe32(l_pXpmrHdr->iv_bootCopierOffset));
    FAPI_DBG( "XPMR BL Offset             0x%08x", htobe32(l_pXpmrHdr->iv_bootLoaderOffset));
    FAPI_DBG( "XPMR BL Length             0x%08x", htobe32(l_pXpmrHdr->iv_bootLoaderLength));
    FAPI_DBG( "XPMR Hcode Offset          0x%08x", htobe32(l_pXpmrHdr->iv_xgpeHcodeOffset));
    FAPI_DBG( "XPMR Hcode Length          0x%08x", htobe32(l_pXpmrHdr->iv_xgpeHcodeLength));
    FAPI_DBG( "XGPE SRAM Image Length     0x%08x", htobe32(l_pXpmrHdr->iv_xgpeSramSize));

    FAPI_DBG( "==========================================================" );
#endif

    return fapi2::current_err;
}

/**
 * @brief   populates few fields of XGPE image  header in HOMER.
 * @param[in]   i_procTgt       fapi2 target for P10 chip
 * @param[in]   i_pChipHomer    models P10's HOMER.
 * @return      fapi2 return code.
 */
fapi2::ReturnCode setIOAttr(CONST_FAPI2_PROC& i_procTgt,
                            Homerlayout_t* i_pChipHomer)
{
    uint16_t attrTemp16 =  0;
    uint64_t attrTemp64 =  0;
    uint8_t  attrTemp8  =  0;
    XgpeHeader_t * pXgpeHeader   =
        ( XgpeHeader_t *) &i_pChipHomer->iv_xpmrRegion.iv_xgpeSramRegion[XGPE_INT_VECTOR_SIZE];

    //Populating attribute area of XGPE Image header
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_IO_START,
                i_procTgt,
                attrTemp16),
            "Error from FAPI_ATTR_GET for ATTR_WOF_IO_START" );

    pXgpeHeader->g_xgpe_ioStart  =  attrTemp16;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_IO_STEP,
                i_procTgt,
                attrTemp16),
            "Error from FAPI_ATTR_GET for ATTR_WOF_IO_STEP" );
    pXgpeHeader->g_xgpe_ioStep   =  attrTemp16;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_IO_COUNT,
                i_procTgt,
                attrTemp16),
            "Error from FAPI_ATTR_GET for ATTR_WOF_IO_SIZE" );
    pXgpeHeader->g_xgpe_ioCount   =  attrTemp16;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDN_VOLTAGE_MV,
                i_procTgt,
                attrTemp16),
            "Error from FAPI_ATTR_GET for ATTR_VDN_VOLTAGE_MV" );
    pXgpeHeader->g_xgpe_vdnVoltage  =  attrTemp16;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_GROUNDED_CONTROLLERS,
                i_procTgt,
                attrTemp16),
            "Error from FAPI_ATTR_GET for ATTR_IO_GROUNDED_CONTROLLERS" );
    pXgpeHeader->g_xgpe_groundedCtrls  =  attrTemp16;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_GROUNDED_LINKS,
                i_procTgt,
                attrTemp64),
            "Error from FAPI_ATTR_GET for ATTR_IO_GROUNDED_LINKS" );
    pXgpeHeader->g_xgpe_groundedLinks  =  attrTemp64;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_IO_POWER_MODE,
                i_procTgt,
                attrTemp8),
            "Error from FAPI_ATTR_GET for ATTR_WOF_IO_POWER_MODE" );
    pXgpeHeader->g_xgpe_wofIoPowMode  =  attrTemp8;

    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_WOF_TDP_IO_INDEX, i_procTgt, attrTemp8 ),
              "Error from FAPI_ATTR_GET for ATTR_WOF_TDP_IO_INDEX" );
    pXgpeHeader->g_xgpe_wofTdpIoIndex  =  attrTemp8;

#ifndef __HOSTBOOT_MODULE
    pXgpeHeader->g_xgpe_ioStart             =  htobe16(pXgpeHeader->g_xgpe_ioStart);
    pXgpeHeader->g_xgpe_ioStep              =  htobe16(pXgpeHeader->g_xgpe_ioStep);
    pXgpeHeader->g_xgpe_ioCount             =  htobe16(pXgpeHeader->g_xgpe_ioCount);
    pXgpeHeader->g_xgpe_vdnVoltage          =  htobe16(pXgpeHeader->g_xgpe_vdnVoltage);
    pXgpeHeader->g_xgpe_groundedLinks       =  htobe64(pXgpeHeader->g_xgpe_groundedLinks);;
    pXgpeHeader->g_xgpe_groundedCtrls       =  htobe16(pXgpeHeader->g_xgpe_groundedCtrls);

    FAPI_DBG( "====================== XGPE Header =======================" );
    FAPI_INF( "XGPE IO Start                0x%04x", htobe16( pXgpeHeader->g_xgpe_ioStart ) );
    FAPI_INF( "XGPE IO Step                 0x%04x", htobe16( pXgpeHeader->g_xgpe_ioStep ) );
    FAPI_INF( "XGPE IO Count                0x%04x", htobe16( pXgpeHeader->g_xgpe_ioCount ) );
    FAPI_INF( "XGPE VND Voltage             0x%04x", htobe16( pXgpeHeader->g_xgpe_vdnVoltage ) );
    FAPI_INF( "XGPE Ground Links            0x%016lx", htobe64( pXgpeHeader->g_xgpe_groundedLinks ) );
    FAPI_INF( "XGPE Ground Controller       0x%04x", htobe16( pXgpeHeader->g_xgpe_groundedCtrls ) );
    FAPI_INF( "XGPE Power Mode              0x%02x", pXgpeHeader->g_xgpe_wofIoPowMode );
    FAPI_INF( "XGPE WOF TDP IO Index        0x%08x", pXgpeHeader->g_xgpe_wofTdpIoIndex );
    FAPI_DBG( "==========================================================" );
#endif

fapi_try_exit:
    return fapi2::current_err;
}
//-------------------------------------------------------------------------------------------------------

/**
 * @brief   populates few fields of XGPE image  header in HOMER.
 * @param[in]   i_procTgt       fapi2 target for P10 chip
 * @param[in]   i_pChipHomer    models P10's HOMER.
 * @param[in]   i_xpmrBuildRecord     XPMR region image build metadata
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildXgpeHeader( CONST_FAPI2_PROC& i_procTgt,
                                   Homerlayout_t* i_pChipHomer,
                                   ImageBuildRecord & i_xpmrBuildRecord )
{
    ImgSectnSumm   l_sectn;
    uint32_t attrVal    =  0;

    i_xpmrBuildRecord.getSection( "XGPE Hcode", l_sectn );
    XgpeHeader_t * pXgpeHeader   =
        ( XgpeHeader_t *) &i_pChipHomer->iv_xpmrRegion.iv_xgpeSramRegion[XGPE_INT_VECTOR_SIZE];
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CORE_THROTTLE_ASSERT_COUNT,
                i_procTgt,
                attrVal),
            "Error from FAPI_ATTR_GET for ATTR_CORE_THROTTLE_ASSERT_COUNT");
    pXgpeHeader->g_xgpe_coreThrottleAssertCnt =   htobe32(attrVal);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CORE_THROTTLE_DEASSERT_COUNT,
                i_procTgt,
                attrVal),
            "Error from FAPI_ATTR_GET for ATTR_CORE_THROTTLE_DEASSERT_COUNT");
    pXgpeHeader->g_xgpe_coreThrottleDeAssertCnt =     htobe32(attrVal);

    pXgpeHeader->g_xgpe_hcodeLength           =   l_sectn.iv_sectnLength;
    pXgpeHeader->g_xgpe_sysResetAddress       =   XGPE_SRAM_BASE_ADDR + PPE_RESET_VECTOR;
    pXgpeHeader->g_xgpe_ivprAddress           =   XGPE_SRAM_BASE_ADDR;
    pXgpeHeader->g_xgpe_gpspbLength           =   sizeof(GlobalPstateParmBlock_t);

    i_xpmrBuildRecord.getSection( "XGPE Op Trace", l_sectn );
    pXgpeHeader->g_xgpe_xgpeDeepOpTraceMemAddr   =
        ( EXT_MEM_ADDR | ( HOMER_XPMR_REGION_NUM * ONE_MB ) |  l_sectn.iv_sectnOffset );
    pXgpeHeader->g_xgpe_xgpeDeepOpTraceLength    =   l_sectn.iv_sectnLength;


#ifndef __HOSTBOOT_MODULE
    pXgpeHeader->g_xgpe_hcodeLength         =    htobe32( pXgpeHeader->g_xgpe_hcodeLength );
    pXgpeHeader->g_xgpe_sysResetAddress     =    htobe32( pXgpeHeader->g_xgpe_sysResetAddress );
    pXgpeHeader->g_xgpe_ivprAddress         =    htobe32( pXgpeHeader->g_xgpe_ivprAddress );
    pXgpeHeader->g_xgpe_gpspbLength         =    htobe32( pXgpeHeader->g_xgpe_gpspbLength );
    pXgpeHeader->g_xgpe_xgpeDeepOpTraceMemAddr = htobe32( pXgpeHeader->g_xgpe_xgpeDeepOpTraceMemAddr );
    pXgpeHeader->g_xgpe_xgpeDeepOpTraceLength  = htobe32( pXgpeHeader->g_xgpe_xgpeDeepOpTraceLength );

    FAPI_DBG( "====================== XGPE Header =======================" );
    FAPI_INF( "XGPE Hcode Length            0x%08x", htobe32( pXgpeHeader->g_xgpe_hcodeLength ) );
    FAPI_INF( "XGPE Sys Reset Address       0x%08x", htobe32( pXgpeHeader->g_xgpe_sysResetAddress ) );
    FAPI_INF( "XGPE IVPR Address            0x%08x", htobe32( pXgpeHeader->g_xgpe_ivprAddress ) );
    FAPI_INF( "XGPE GPSPB Length            0x%08x", htobe32( pXgpeHeader->g_xgpe_gpspbLength ) );
    FAPI_INF( "XGPE Thr Assert Cnt          0x%08x", htobe32( pXgpeHeader->g_xgpe_coreThrottleAssertCnt ) );
    FAPI_INF( "XGPE Thr DeAssert Cnt        0x%08x", htobe32( pXgpeHeader->g_xgpe_coreThrottleDeAssertCnt ) );
    FAPI_INF( "XGPE Deep OpTrace Mem Addr   0x%08x", htobe32( pXgpeHeader->g_xgpe_xgpeDeepOpTraceMemAddr ));
    FAPI_INF( "XGPE Deep OpTrace Length     0x%08x", htobe32( pXgpeHeader->g_xgpe_xgpeDeepOpTraceLength ) );
    FAPI_DBG( "==========================================================" );
#endif

fapi_try_exit:
    return fapi2::current_err;
}

//-------------------------------------------------------------------------------------------------------

/**
 * @brief   builds XPMR region
 * @param[in]   i_procTgt       fapi2 target for P10 chip
 * @param[in]   i_pImageIn      points to hardware reference image
 * @param[in]   i_pChipHomer    models HOMER
 * @param[in]   i_phase         IPL or Runtime
 * @param[in]   i_imgType       image type to be built
 * @param[in]   i_chipFuncModel P10 chip configuration
 * @param[in]   i_ringData      buffers to extract and process rings.
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildXpmrImage( CONST_FAPI2_PROC& i_procTgt,
                                  void* const     i_pImageIn,
                                  Homerlayout_t   *i_pChipHomer,
                                  SysPhase_t      i_phase,
                                  ImageType_t     i_imgType,
                                  P10FuncModel    &i_chipFuncModel )
{
    FAPI_INF( ">> buildXpmrImage" );
    uint32_t rcTemp     =   IMG_BUILD_SUCCESS;
    fapi2::current_err  =   fapi2::FAPI2_RC_SUCCESS;
    //Let us find XIP Header for XGPE
    P9XipSection ppeSection;
    uint8_t* pXgpeImg   =   NULL;
    ImageBuildRecord    l_xgpeBuildRecord( (uint8_t *)(&i_pChipHomer->iv_occHostRegion), "XGPE" );

    if( i_imgType.xgpeImageBuild )
    {
        //Init XGPE region with zero
        memset( i_pChipHomer->iv_xpmrRegion.iv_xpmrHeader, 0x00, ONE_MB );

        rcTemp = p9_xip_get_section( i_pImageIn, P9_XIP_SECTION_HW_XGPE, &ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::XGPE_IMG_NOT_FOUND_IN_HW_IMG()
                     .set_XIP_FAILURE_CODE( rcTemp )
                     .set_EC_LEVEL( i_chipFuncModel.getChipLevel() ),
                     "Failed To Find XGPE Sub-Image In HW Image" );

        pXgpeImg = ppeSection.iv_offset + (uint8_t*) (i_pImageIn );
        FAPI_DBG("HW image XGPE Offset = 0x%08X", ppeSection.iv_offset);

        FAPI_INF("XPMR Header");
        rcTemp = copySectionToHomer( i_pChipHomer->iv_xpmrRegion.iv_xpmrHeader,
                                     pXgpeImg,
                                     l_xgpeBuildRecord,
                                     P9_XIP_SECTION_XGPE_XPMR_HDR,
                                     i_chipFuncModel.getChipLevel(),
                                     ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::XPMR_HDR_BUILD_FAIL()
                     .set_EC_LEVEL( i_chipFuncModel.getChipLevel() )
                     .set_MAX_ALLOWED_SIZE( rcTemp )
                     .set_ACTUAL_SIZE( ppeSection.iv_size ),
                     "Failed To Update XPMR Region Of HOMER" );

        l_xgpeBuildRecord.setSection( "XPMR Header", 0, XPMR_HEADER_SIZE );

        rcTemp = copySectionToHomer( i_pChipHomer->iv_xpmrRegion.iv_bootCopier,
                                     pXgpeImg,
                                     l_xgpeBuildRecord,
                                     P9_XIP_SECTION_XGPE_LVL1_BL,
                                     i_chipFuncModel.getChipLevel(),
                                     ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::XGPE_BOOT_COPIER_BUILD_FAIL()
                     .set_EC_LEVEL( i_chipFuncModel.getChipLevel() )
                     .set_MAX_ALLOWED_SIZE( rcTemp )
                     .set_ACTUAL_SIZE( ppeSection.iv_size ),
                     "Failed To Update XGPE Boot Copier Region Of HOMER" );

        l_xgpeBuildRecord.setSection( "XGPE Boot Copier", XGPE_BOOT_COPIER_OFFSET, ppeSection.iv_size );

        rcTemp = copySectionToHomer( i_pChipHomer->iv_xpmrRegion.iv_bootLoader,
                                     pXgpeImg,
                                     l_xgpeBuildRecord,
                                     P9_XIP_SECTION_XGPE_LVL2_BL,
                                     i_chipFuncModel.getChipLevel(),
                                     ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::XGPE_BOOT_LOADER_BUILD_FAIL()
                     .set_EC_LEVEL( i_chipFuncModel.getChipLevel() )
                     .set_MAX_ALLOWED_SIZE( rcTemp )
                     .set_ACTUAL_SIZE( ppeSection.iv_size ),
                     "Failed To Update XGPE Boot Loader Region Of HOMER" );

        l_xgpeBuildRecord.setSection( "XGPE Boot Loader", XGPE_BOOT_LOADER_OFFSET, ppeSection.iv_size );
        rcTemp = copySectionToHomer( i_pChipHomer->iv_xpmrRegion.iv_xgpeSramRegion,
                                     pXgpeImg,
                                     l_xgpeBuildRecord,
                                     P9_XIP_SECTION_XGPE_HCODE,
                                     i_chipFuncModel.getChipLevel(),
                                     ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::XGPE_HCODE_BUILD_FAIL()
                     .set_EC_LEVEL( i_chipFuncModel.getChipLevel() )
                     .set_MAX_ALLOWED_SIZE( rcTemp )
                     .set_ACTUAL_SIZE( ppeSection.iv_size ),
                     "Failed To Update XGPE Hcode Region Of HOMER" );

        l_xgpeBuildRecord.setSection( "XGPE Hcode", XGPE_IMAGE_XPMR_OFFSET, ppeSection.iv_size );

        FAPI_DBG( "XGPE Hcode       0x%08x",    ppeSection.iv_size );

        l_xgpeBuildRecord.setSection( "XGPE SRAM Size", XGPE_IMAGE_XPMR_OFFSET, ppeSection.iv_size );
        l_xgpeBuildRecord.setSection( "XGPE Op Trace", XGPE_OPTRACE_XPMR_OFFSET, XGPE_OPTRACE_LENGTH );

        FAPI_TRY( buildXpmrHeader( i_pChipHomer, l_xgpeBuildRecord ),
                  "Failed To Build XPMR Header" );

        FAPI_TRY( buildXgpeHeader(i_procTgt, i_pChipHomer, l_xgpeBuildRecord ),
                  "Failed To Build XGPE Header" );
    }

fapi_try_exit:
    return fapi2::current_err;

    FAPI_INF( " << buildXpmrImage" );
}

//-------------------------------------------------------------------------------------------------------

fapi2::ReturnCode parseRingOverride( void* const  i_pRingOverride )
{
    FAPI_INF( ">> parseRingOverride" );
    TorHeader_t * l_pOvrdTorHdr =   NULL;
    uint32_t l_overrideSize     =   0;

    if( !i_pRingOverride )
    {
        goto fapi_try_exit;
    }

    l_pOvrdTorHdr   =   ( TorHeader_t * )i_pRingOverride;
    l_overrideSize  =   htobe32( l_pOvrdTorHdr->size );

    FAPI_INF( "============================ Override Details ==========================================" );
    FAPI_INF( "Override Size        0x%08x  ", l_overrideSize );
    FAPI_INF( "Override DD Level    0x%02x  ", l_pOvrdTorHdr->ddLevel );
    FAPI_INF( "Override Ver Level   0x%02x  ", l_pOvrdTorHdr->version );
    FAPI_INF( "============================ Override Details Ends =====================================" );

    FAPI_ASSERT( (l_overrideSize <= QME_OVERRIDE_RING_SIZE),
                 fapi2::BAD_OVERRIDE_SIZE()
                 .set_BAD_OVERRIDE_BIN_SIZE( l_overrideSize ),
                 "Override Binary Is Bigger Then Temp Buffer 0x%08x", l_overrideSize );
fapi_try_exit:
    FAPI_INF( "<< parseRingOverride" );
    return fapi2::current_err;
}

//------------------------------------------------------------------------------------------------------

/**
 * @brief   initializes self-save restore region of HOMER.
 * @param[in]   i_pChipHomer  a struct modelling chip's HOMER region.
 * @return  fapi2 return code in case of error, FAPI2_RC_SUCCESS otherwise.
 */
fapi2::ReturnCode initSelfRestoreRegion( Homerlayout_t* i_pChipHomer )
{
    FAPI_INF(">> initSelfRestoreRegion");
    uint32_t l_fillBlr          =   htobe32(SELF_RESTORE_BLR_INST);
    uint32_t l_fillAttn         =   htobe32(CORE_RESTORE_PAD_OPCODE);
    uint32_t l_byteCnt          =   0;
    uint32_t * l_pSelfRestLoc   =
            (uint32_t *)&i_pChipHomer->iv_cpmrRegion.iv_selfRestoreRegion.iv_coreSelfRestore[0];

    SmfSprRestoreRegion_t * l_pSaveRestore   =
            (SmfSprRestoreRegion_t *)&i_pChipHomer->iv_cpmrRegion.iv_selfRestoreRegion.iv_coreSelfRestore[0];

    while( l_byteCnt < SMF_SELF_RESTORE_CORE_REGS_SIZE )
    {
        memcpy( l_pSelfRestLoc, &l_fillAttn, sizeof( uint32_t ) );
        l_byteCnt += 4;
        l_pSelfRestLoc++;
    }

    //Initialize Core SPR and Thread SPR start boundary with BLR instruction.

    FAPI_INF( " Size Of SmfSprRestoreRegion_t 0x%08x", sizeof( SmfSprRestoreRegion_t ) );
    for( size_t l_coreId = 0; l_coreId < MAX_CORES_PER_CHIP; l_coreId++ )
    {
        memcpy( (uint32_t *)&l_pSaveRestore->iv_coreRestoreArea[0], &l_fillBlr, sizeof(uint32_t) );

        for( size_t l_threadId = 0; l_threadId < MAX_THREADS_PER_CORE; l_threadId++ )
        {
            memcpy( &l_pSaveRestore->iv_threadRestoreArea[l_threadId][0],
                    &l_fillBlr,
                    sizeof(uint32_t) );
        }

        l_pSaveRestore++;
    }

    FAPI_INF("<< initSelfRestoreRegion");

    return fapi2::FAPI2_RC_SUCCESS;
}

//------------------------------------------------------------------------------

/**
 * @brief   enables self save of SPRs
 * @param[in]   i_pChipHomer    struct modelling P10 chip's HOMER region.
 * @param[in]   i_procFuncModel functional view of P10 chip.
 * @return  fapi2 error code in case of error, FAPI2_RC_SUCCESS otherwise.
 */
fapi2::ReturnCode   initSelfSaveRestoreEntries( Homerlayout_t* i_pChipHomer,
                                                P10FuncModel & i_procFuncModel )
{
    FAPI_DBG(">> initSelfSaveRestoreEntries" );

    stopImageSection::StopReturnCode_t    l_retCode;
    uint32_t  l_corePos   =   0;

    for( l_corePos = 0; l_corePos < MAX_CORES_PER_CHIP; l_corePos++ )
    {
        if( !i_procFuncModel.isCoreFunctional( l_corePos ) )
        {
            continue;
        }

        FAPI_INF( "Core Pos 0x%02d", l_corePos );
        l_retCode   =  stopImageSection::proc_stop_init_cpureg( (void *)i_pChipHomer, l_corePos );

        FAPI_ASSERT( ( stopImageSection::STOP_SAVE_SUCCESS == l_retCode ),
                     fapi2::SELF_RESTORE_INIT_FAILED()
                     .set_HOMER_PTR( i_pChipHomer )
                     .set_CORE_POS( l_corePos )
                     .set_FAILURE_CODE( l_retCode )
                     .set_EC_LEVEL( i_procFuncModel.getChipLevel() ),
                     "Failed To Initialize The Self-Restore Region 0x%08x", l_retCode );

        l_retCode   =  stopImageSection::proc_stop_init_self_save( (void *)i_pChipHomer, l_corePos );

        FAPI_ASSERT( ( stopImageSection::STOP_SAVE_SUCCESS == l_retCode ),
                     fapi2::SELF_SAVE_INIT_FAILED()
                     .set_HOMER_PTR( i_pChipHomer )
                     .set_CORE_POS( l_corePos )
                     .set_FAILURE_CODE( l_retCode )
                     .set_EC_LEVEL( i_procFuncModel.getChipLevel() ),
                     "Failed To Initialize The Self-Save Region 0x%08x", (uint32_t)l_retCode );
    }

    fapi_try_exit:
    FAPI_DBG("<< initSelfSaveRestoreEntries" );
    return fapi2::current_err;
}

//------------------------------------------------------------------------------



/**
 * @brief       copies core self restore section from hardware image to HOMER.
 * @param[in]   i_pImageIn          points to start of hardware image.
 * @param[in]   i_pChipHomer        points to HOMER image.
 * @param[in]   i_imgType           image sections  to be built
 * @param[in]   i_fusedState        fused core status
 * @param[in]   i_qmeBuildRecord    contains QME image build details.
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildCoreRestoreImage( void* const i_pImageIn,
                                Homerlayout_t* i_pChipHomer, ImageType_t i_imgType,
                                uint8_t i_fusedState,
                                P10FuncModel & i_procFuncModel,
                                ImageBuildRecord &   i_qmeBuildRecord )
{

    FAPI_INF(">> buildCoreRestoreImage");
    uint32_t rcTemp     =   IMG_BUILD_SUCCESS;
    fapi2::current_err  =   fapi2::FAPI2_RC_SUCCESS;
    //Let us find XIP Header for Core Self Restore Image
    P9XipSection ppeSection;
    uint8_t* pSelfRestImg       =   NULL;

    rcTemp = p9_xip_get_section( i_pImageIn, P9_XIP_SECTION_HW_RESTORE, &ppeSection );

    FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                 fapi2::SELF_REST_IMG_NOT_FOUND_IN_HW_IMG()
                 .set_XIP_FAILURE_CODE( rcTemp )
                 .set_EC_LEVEL( i_procFuncModel.getChipLevel() ),
                 "Failed to find Self Restore sub-image in HW Image" );

    pSelfRestImg = ppeSection.iv_offset + (uint8_t*) (i_pImageIn );

    if( i_imgType.selfRestoreBuild )
    {
        i_qmeBuildRecord.setCurrentSectn( "SELF BIN" );
        // first 256 bytes is expected to be zero here. It is by purpose. Just after this step,
        // we will add CPMR header in that area.
        FAPI_INF("Self Restore Image install");
        FAPI_INF("  Offset = 0x%08X, Size = 0x%08X",
                 ppeSection.iv_offset, ppeSection.iv_size);
        rcTemp = copySectionToHomer( i_pChipHomer->iv_cpmrRegion.iv_selfRestoreRegion.iv_CPMR_SR.iv_region,
                                     pSelfRestImg,
                                     i_qmeBuildRecord,
                                     P9_XIP_SECTION_RESTORE_SELF_SAVE_RESTORE,
                                     i_procFuncModel.getChipLevel(),
                                     ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::SELF_REST_IMG_BUILD_FAIL()
                     .set_EC_LEVEL( i_procFuncModel.getChipLevel() )
                     .set_MAX_ALLOWED_SIZE( rcTemp  )
                     .set_ACTUAL_SIZE( ppeSection.iv_size ),
                     "Failed to update self restore image in HOMER" );

    }

    // adding CPMR header in first 256 bytes of the CPMR.
    FAPI_INF("Overlay CPMR Header at the beginning of CPMR");

    rcTemp = copySectionToHomer( i_pChipHomer->iv_cpmrRegion.iv_selfRestoreRegion.iv_CPMR_SR.iv_region,
                                 pSelfRestImg,
                                 i_qmeBuildRecord,
                                 P9_XIP_SECTION_RESTORE_CPMR_HDR,
                                 i_procFuncModel.getChipLevel(),
                                 ppeSection );

    FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                 fapi2::CPMR_HDR_BUILD_FAIL()
                 .set_EC_LEVEL( i_procFuncModel.getChipLevel() )
                 .set_MAX_ALLOWED_SIZE( rcTemp  )
                 .set_ACTUAL_SIZE( ppeSection.iv_size ),
                 "Failed to update CPMR Header in HOMER" );

    i_qmeBuildRecord.setSection( "SELF", SELF_RESTORE_CPMR_OFFSET, SELF_SAVE_RESTORE_REGION_SIZE );

    if( i_imgType.coreSprBuild )
    {
        //Pad undefined or runtime section with  ATTN Opcode
        //Padding SPR restore area with ATTN Opcode
        FAPI_INF("Padding CPMR Core Restore portion with Attn opcodes");

        FAPI_TRY( initSelfRestoreRegion( i_pChipHomer ),
                  "Failed To Initialize The Self-Restore Region" );

        FAPI_TRY( initSelfSaveRestoreEntries( i_pChipHomer, i_procFuncModel ),
                  "Failed To Initialize The Self-Save Region" );
    }


    if( i_imgType.coreScomBuild )
    {
        memset( i_pChipHomer->iv_cpmrRegion.iv_selfRestoreRegion.iv_coreScom,
                0x00, SCOM_RESTORE_SIZE_TOTAL );
        //FIXME Update SCOM restore offset to i_qmeBuildRecord
    }

    i_qmeBuildRecord.setSection( "SCOM", SCOM_RESTORE_CPMR_OFFSET, SCOM_RESTORE_SIZE_TOTAL );

fapi_try_exit:
    FAPI_INF("<< buildCoreRestoreImage")

    return fapi2::current_err;
}

//------------------------------------------------------------------------------

/**
 * @brief builds QME instance specific region in HOMER
 * @param[in]   i_procTgt           fapi2 target for P10 chip
 * @param[in]   i_pChipHomer        models P10 chip HOMER
 * @param[in]   i_ringData          various buffer pointer
 * @param[in]   i_procFuncModel     summarizes P10 chip configuration
 * @param[in]   i_qmeBuildRecord    Image build record of QME.
 * @return      fapi2 return code
 */
fapi2::ReturnCode buildQmeSpecificRing( CONST_FAPI2_PROC& i_procTgt, Homerlayout_t *i_pChipHomer, RingBufData & i_ringData,
                                        P10FuncModel & i_procFuncModel, ImageBuildRecord & i_qmeBuildRecord )
{
    FAPI_DBG(" >> buildQmeSpecificRing " );
    uint32_t l_maxQmeRingSize   =   0;
    uint32_t l_instRingOffset   =   i_qmeBuildRecord.getCurrentOffset();
    uint32_t l_localPsParam     =   0;
    uint32_t l_instSpecLength   =   l_localPsParam;
    uint32_t l_currentIndex     =   l_instRingOffset - QME_IMAGE_CPMR_OFFSET;
    uint32_t l_instSpecbase     =   0;
    uint32_t l_workBufSize      =   i_ringData.iv_sizeWorkBuf1;

    FAPI_INF( "Qme Instance Ring Start Index 0x%08x", l_instRingOffset );

    //let us make Instance Ring start a multiple of 32B for compatibility with QME BCE
    l_currentIndex      =   l_currentIndex + BCE_RD_BLOCK_SIZE - 1;
    l_currentIndex      =   (( l_currentIndex >> SHIFT_RD_BLOCK_SIZE ) << SHIFT_RD_BLOCK_SIZE );
    l_instRingOffset    =   l_currentIndex + QME_IMAGE_CPMR_OFFSET;
    l_instSpecbase      =   l_currentIndex;

    for( uint8_t l_superChiplet = 0; l_superChiplet < MAX_QUADS_PER_CHIP;
         l_superChiplet++ )
    {
        if( !i_procFuncModel.isQuadFunctional( l_superChiplet ) )
        {
            continue;
        }

        FAPI_TRY( p10_qme_customize( i_procTgt,
                                     (uint8_t *)i_ringData.iv_pRingBuffer,
                                     ( CUST_RING_OP )l_superChiplet,
                                     (uint8_t *)i_ringData.iv_pWorkBuf1,
                                     l_workBufSize,
                                     0 ),
                 "Chiplet Specific Ring Customization Failed For QME" );

        if( l_maxQmeRingSize < l_workBufSize )
        {
            l_maxQmeRingSize    =   l_workBufSize;
        }

        l_workBufSize   =   i_ringData.iv_sizeWorkBuf1;
    }

    l_instSpecLength    +=   l_maxQmeRingSize;

    l_instSpecLength     =  ( l_instSpecLength + BCE_RD_BLOCK_SIZE - 1 );
    l_instSpecLength     =  (( l_instSpecLength >> SHIFT_RD_BLOCK_SIZE ) << SHIFT_RD_BLOCK_SIZE );

    for( size_t l_superChiplet = 0; l_superChiplet < MAX_QUADS_PER_CHIP;
         l_superChiplet++ )
    {
        if( !i_procFuncModel.isQuadFunctional( l_superChiplet ) )
        {
            FAPI_DBG( "Skipping Quad %d For Core Specific Ring", l_superChiplet );
            continue;
        }

        l_workBufSize       =   i_ringData.iv_sizeWorkBuf1;

        memset( (uint8_t *)i_ringData.iv_pWorkBuf1, 0x00, i_ringData.iv_sizeWorkBuf1 );

        FAPI_TRY( p10_qme_customize( i_procTgt,
                                     (uint8_t *)i_ringData.iv_pRingBuffer,
                                     ( CUST_RING_OP ) l_superChiplet,
                                     (uint8_t *)i_ringData.iv_pWorkBuf1,
                                     l_workBufSize,
                                     0 ),
                 "Chiplet Specific Ring Customization Failed For QME" );

        l_currentIndex  =  l_instSpecbase + (l_superChiplet*l_instSpecLength);
        memcpy( &i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion[l_currentIndex],
            i_ringData.iv_pWorkBuf1, l_workBufSize );
    }

    i_qmeBuildRecord.setSection( "QME Inst Sectn", l_instRingOffset, l_instSpecLength );

fapi_try_exit:
    FAPI_DBG(" << buildQmeSpecificRing " );
    return fapi2::current_err;;
}

//------------------------------------------------------------------------------

/**
 * @brief       copies QME section from hardware image to HOMER.
 * @param[in]   i_pImageIn      points to start of hardware image.
 * @param[in]   i_pChipHomer    points to HOMER image.
 * @param[in]   i_imgType       image sections  to be built
 * @param[in]   i_procFuncModel info pertaining to P10 chip
 * @param[in]   i_imageRecord   an instance of ImageBuildRecord
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildQmeImage( void* const i_pImageIn, Homerlayout_t* i_pChipHomer,
                                 ImageType_t i_imgType,
                                 P10FuncModel & i_procFuncModel,
                                 ImageBuildRecord & i_imageRecord )
{
    FAPI_INF(">> buildQmeImage")
    uint32_t rcTemp = IMG_BUILD_SUCCESS;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    //Let us find XIP Header for QME Image
    P9XipSection ppeSection;
    uint8_t* pQmeImg = NULL;
    uint64_t l_imgVer   =   0;

    if( i_imgType.qmeHcodeBuild )
    {
        i_imageRecord.setCurrentSectn( "QME Hcode" );
        rcTemp = p9_xip_get_section( i_pImageIn, P9_XIP_SECTION_HW_QME, &ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::QME_IMG_NOT_FOUND_IN_HW_IMG()
                     .set_XIP_FAILURE_CODE( rcTemp )
                     .set_EC_LEVEL( i_procFuncModel.getChipLevel() ),
                     "Failed to find QME sub-image in HW Image" );

        pQmeImg = ppeSection.iv_offset + (uint8_t*) (i_pImageIn );
        FAPI_DBG("ppeSection.iv_offset = 0x%08X, ppeSection.iv_size = 0x%08X",
                 ppeSection.iv_offset, ppeSection.iv_size);

        memset(i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion, 0x00, QME_REGION_SIZE);

        // The image in the HW Image has the Interrupt Vectors, QME Header and Debug
        // Pointers already included.
        rcTemp = copySectionToHomer(  i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion, pQmeImg,
                                      i_imageRecord,
                                      P9_XIP_SECTION_QME_HCODE,
                                      i_procFuncModel.getChipLevel(),
                                      ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::QME_HCODE_BUILD_FAIL()
                     .set_EC_LEVEL( i_procFuncModel.getChipLevel() )
                     .set_MAX_ALLOWED_SIZE( rcTemp )
                     .set_ACTUAL_SIZE( ppeSection.iv_size ),
                     "Failed to find QME Hcode in QME XIP Image" );

        //Rounding QME hcode size to a multiple of 32B
        ppeSection.iv_size  =   ( ((ppeSection.iv_size  + BLK_SIZE_32B  - 1 ) >> SHIFT_RD_BLOCK_SIZE ) << SHIFT_RD_BLOCK_SIZE );

        i_imageRecord.setSection( "QME Hcode",
                                  ( &i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion[0] - (uint8_t *)&i_pChipHomer->iv_cpmrRegion ),
                                   ppeSection.iv_size );

        QmeHeader_t* pImgHdr        =
            (QmeHeader_t*) & i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion[QME_INT_VECTOR_SIZE];
        l_imgVer    =   htobe64( pImgHdr->g_qme_magic_number );

        FAPI_DBG( "Magic Word End 0x%016lx", l_imgVer );

        if( ( 0 == l_imgVer ) || ( QME_VER_BASE_ASCII == l_imgVer ))
        {
           l_imgVer = 0;
        }
        else
        {
               l_imgVer    =   l_imgVer - QME_VER_BASE_ASCII;
        }
        FAPI_DBG( "QME SRAM Image Ver 0x%016lx", l_imgVer );
        i_imageRecord.setPpeImageVer( l_imgVer );

    }   //i_imgType.qmeHcodeBuild

fapi_try_exit:
    FAPI_INF("<< buildQmeImage")
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

fapi2::ReturnCode buildQmeOverride( Homerlayout_t *i_pChipHomer, RingBufData & i_ringData,
                                    ImageBuildRecord & i_qmeBuildRecord )
{
    FAPI_INF( ">> buildQmeOverride" );
    ImgSectnSumm l_qmeSectn;
    l_qmeSectn.iv_sectnOffset = 0;
    l_qmeSectn.iv_sectnLength = 0;

    if( i_ringData.iv_pOverride )
    {
        TorHeader_t * l_pOvrdTorHdr =   ( TorHeader_t * )i_ringData.iv_pOverride;
        uint32_t l_overrideSize     =   htobe32( l_pOvrdTorHdr->size );
        uint32_t l_buildIndex       =   0;

        i_qmeBuildRecord.getSection( "QME Common Ring", l_qmeSectn );
        //calculating start offset of Override ring
        l_buildIndex      =   l_qmeSectn.iv_sectnOffset + l_qmeSectn.iv_sectnLength;
        l_buildIndex      =   ( ( ( l_buildIndex  + 15 )/16 ) * 16 );

        //re computed new common ring size and rounded it to 32B boundary
        l_qmeSectn.iv_sectnLength   =   ( l_buildIndex - l_qmeSectn.iv_sectnOffset ) + l_overrideSize;
        l_qmeSectn.iv_sectnLength   =   ((( l_qmeSectn.iv_sectnLength + 31 ) >> 5) << 5);

        i_qmeBuildRecord.editSection( "QME Common Ring", l_qmeSectn );

        //copying Override Rings
        memcpy( (uint8_t *)&i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion[l_buildIndex - QME_IMAGE_CPMR_OFFSET ],
                        (uint8_t *)i_ringData.iv_pOverride,
                        l_overrideSize );

        //Setting Offset and Length of Override sub-region
        l_qmeSectn.iv_sectnOffset   =   l_buildIndex; //rounded override start offset to 16B boundary
        l_qmeSectn.iv_sectnLength   =   l_overrideSize;
        FAPI_INF( "Override Offset   0x%08x  Override Length   0x%08x",
                   l_qmeSectn.iv_sectnOffset, l_qmeSectn.iv_sectnLength );
    }

    //Special Case for Overrides : Length is already accounted in common ring section
    i_qmeBuildRecord.setSection( "QME Override Ring", l_qmeSectn.iv_sectnOffset, 0 );


    FAPI_INF("<< buildQmeOverride")
     return fapi2::FAPI2_RC_SUCCESS;
}

//----------------------------------------------------------------------------------------------

/**
 * @brief       builds QME image in CPMR section of HOMER
 * @param[in]   i_procTgt       fapi2 target for P10 proc chip
 * @param[in]   i_pImageIn      points to HW Image
 * @param[in]   i_pChipHomer    models HOMER region of memory
 * @param[in]   i_procFuncModel contains P10 chip configuration details.
 * @param[in]   i_imageRecord   an instance of ImageBuildRecord
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildQmeRing( CONST_FAPI2_PROC& i_procTgt, void * const i_pImageIn, Homerlayout_t   *i_pChipHomer,
                                P10FuncModel &i_procFuncModel, RingBufData & i_ringData,
                                ImageBuildRecord & i_qmeBuildRecord )
{
    FAPI_INF( ">> buildQmeRing" );
    uint32_t l_hwImgSize       =   0;
    ImgSectnSumm    l_qmeSectn;
    p9_xip_image_size( i_pImageIn, &l_hwImgSize );

    uint32_t  l_bootCoreMask   =   ENABLE_ALL_CORE;
    uint32_t  l_workBufSize    =   i_ringData.iv_sizeWorkBuf1;
    FAPI_TRY( p10_ipl_customize( i_procTgt,
                                 i_pImageIn,
                                 i_pImageIn,
                                 l_hwImgSize,
                                 i_ringData.iv_pRingBuffer,
                                 i_ringData.iv_ringBufSize,
                                 SYSPHASE_RT_QME,
                                 i_ringData.iv_pWorkBuf1,
                                 i_ringData.iv_sizeWorkBuf1,
                                 i_ringData.iv_pWorkBuf2,
                                 i_ringData.iv_sizeWorkBuf2,
                                 i_ringData.iv_pWorkBuf3,
                                 i_ringData.iv_sizeWorkBuf3,
                                 l_bootCoreMask ),
                "p10_ipl_customize Failed For QME" );
    memset( i_ringData.iv_pWorkBuf1, 0x00, i_ringData.iv_sizeWorkBuf1 );

    FAPI_TRY( p10_qme_customize( i_procTgt,
                                 (uint8_t *)i_ringData.iv_pRingBuffer,
                                 CUST_QME_COMMON_RING,
                                 (uint8_t *)i_ringData.iv_pWorkBuf1,
                                 l_workBufSize,
                                 0 ),
             "Core Common Ring Customization Failed For QME" );

    i_qmeBuildRecord.getSection( "QME Hcode", l_qmeSectn );

    memcpy( &i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion[l_qmeSectn.iv_sectnLength],
            i_ringData.iv_pWorkBuf1, l_workBufSize );

    if( ! i_ringData.iv_pOverride )
    {
        l_workBufSize = ( (( l_workBufSize + 31 ) >> 5 ) << 5 );
    }

    i_qmeBuildRecord.setSection( "QME Common Ring",
                              ( &i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion[l_qmeSectn.iv_sectnLength] - (uint8_t *)&i_pChipHomer->iv_cpmrRegion ),
                                l_workBufSize );

    FAPI_INF( "Common Ring Size 0x%08x Customized Size 0x%08x", i_ringData.iv_ringBufSize, l_workBufSize );

    FAPI_TRY( parseRingOverride( i_ringData.iv_pOverride ),
              "Failed To Parse Override Ring" );

    FAPI_TRY( buildQmeOverride( i_pChipHomer, i_ringData, i_qmeBuildRecord ),
              "Failed To Build Scan Ring Override" );

    FAPI_TRY( buildQmeSpecificRing( i_procTgt, i_pChipHomer, i_ringData, i_procFuncModel, i_qmeBuildRecord ),
              "QME Instance Specific Section Build Failed" );

    fapi_try_exit:
    FAPI_INF( "<< buildQmeRing" );
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

/**
 * @brief       builds QME image header
 * @param[in]   i_procTgt           fapi2 target for P10 proc chip
 * @param[in]   i_pChipHomer        models HOMER region in memory
 * @param[in]   i_qmeBuildRecord    contains QME image build details.
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildQmeHeader( CONST_FAPI2_PROC& i_procTgt, Homerlayout_t   *i_pChipHomer,
                                  ImageBuildRecord & i_qmeBuildRecord )
{
    QmeHeader_t* pImgHdr        =
            (QmeHeader_t*) & i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion[QME_INT_VECTOR_SIZE];
    ImgSectnSumm    l_imgSectn;
    uint64_t l_cpmrPhyAddr      =   0;
    uint32_t l_tempWord         =   0;

    if( !i_qmeBuildRecord.getSection( "QME Hcode", l_imgSectn ) )
    {
        pImgHdr->g_qme_hcode_offset     =    0;
        pImgHdr->g_qme_hcode_length     =    htobe32( l_imgSectn.iv_sectnLength );
        l_tempWord                      =    l_imgSectn.iv_sectnOffset;
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HOMER_PHYS_ADDR, i_procTgt, l_cpmrPhyAddr ),
             "Error From FAPI_ATTR_GET For ATTR_HOMER_PHYS_ADDR");

    FAPI_DBG("HOMER base address 0x%016lX", l_cpmrPhyAddr );

    pImgHdr->g_qme_cpmr_PhyAddr        =   htobe64(l_cpmrPhyAddr);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_UNSECURE_HOMER_ADDRESS, i_procTgt, l_cpmrPhyAddr ),
             "Error From FAPI_ATTR_GET For ATTR_UNSECURE_HOMER_ADDRESS");

    FAPI_DBG("Unsecure CPMR address 0x%016lX", l_cpmrPhyAddr );

    pImgHdr->g_qme_unsec_cpmr_PhyAddr  =   htobe64(l_cpmrPhyAddr);

    if( !i_qmeBuildRecord.getSection( "QME Common Ring", l_imgSectn ) )
    {
        pImgHdr->g_qme_common_ring_offset   =   l_imgSectn.iv_sectnOffset - l_tempWord;
        pImgHdr->g_qme_common_ring_length   =   l_imgSectn.iv_sectnLength;
    }

    if( !i_qmeBuildRecord.getSection( "QME Override Ring", l_imgSectn ) )
    {
        if( l_imgSectn.iv_sectnOffset )
        {
            pImgHdr->g_qme_cmn_ring_ovrd_offset =   l_imgSectn.iv_sectnOffset - l_tempWord;
        }
    }

    if( i_qmeBuildRecord.getPpeImageVer() > QME_VER_BASE )
    {
        if( !i_qmeBuildRecord.getSection( "QME Inst Sectn", l_imgSectn ) )
        {
            //Instance ring too points to begining of temp buffer which is at 32B boundary.
            pImgHdr->g_qme_inst_spec_ring_offset    =    pImgHdr->g_qme_common_ring_offset;
            pImgHdr->g_qme_max_spec_ring_length     =   l_imgSectn.iv_sectnLength;
        }
    }
    else
    {
        if( !i_qmeBuildRecord.getSection( "QME Inst Sectn", l_imgSectn ) )
        {
            pImgHdr->g_qme_inst_spec_ring_offset    =
                        ( pImgHdr->g_qme_common_ring_offset + pImgHdr->g_qme_common_ring_length );
            pImgHdr->g_qme_inst_spec_ring_offset    =    ((( pImgHdr->g_qme_inst_spec_ring_offset  + 31 )/32) * 32);
            pImgHdr->g_qme_max_spec_ring_length     =   l_imgSectn.iv_sectnLength;
        }
    }

    pImgHdr->g_qme_coreL2ScomLength = ( (MAX_CORE_SCOM_ENTRIES + MAX_L2_SCOM_ENTRIES) * SCOM_RESTORE_ENTRY_SIZE );
    pImgHdr->g_qme_coreL2ScomLength = pImgHdr->g_qme_coreL2ScomLength * MAX_CORES_PER_QUAD;
    pImgHdr->g_qme_L3ScomLength     = ( (MAX_EQ_SCOM_ENTRIES + MAX_L3_SCOM_ENTRIES) * SCOM_RESTORE_ENTRY_SIZE );
    pImgHdr->g_qme_L3ScomLength     = pImgHdr->g_qme_L3ScomLength * MAX_CORES_PER_QUAD;

    if( i_qmeBuildRecord.getPpeImageVer() > QME_VER_BASE )
    {
        //If BCE based paging is supported, pick bigger between core-l2 Scom and
        //l3 scom
        pImgHdr->g_qme_scom_offset  =   pImgHdr->g_qme_common_ring_offset;
        pImgHdr->g_qme_scom_length  =   SCOM_RESTORE_SIZE_PER_QME;

    }
    else
    {
        //Offset and length a multiple of 32B
        pImgHdr->g_qme_scom_offset  =   pImgHdr->g_qme_inst_spec_ring_offset + pImgHdr->g_qme_max_spec_ring_length;
        pImgHdr->g_qme_scom_length  =   0; //Scom Restore not supported
    }

    i_qmeBuildRecord.setSection( "QME SCOM Restore", pImgHdr->g_qme_scom_offset, pImgHdr->g_qme_scom_length );

#ifndef __HOSTBOOT_MODULE
   pImgHdr->g_qme_common_ring_offset    =   htobe32(pImgHdr->g_qme_common_ring_offset);
   pImgHdr->g_qme_common_ring_length    =   htobe32(pImgHdr->g_qme_common_ring_length);
   pImgHdr->g_qme_inst_spec_ring_offset =   htobe32(pImgHdr->g_qme_inst_spec_ring_offset);
   pImgHdr->g_qme_max_spec_ring_length  =   htobe32(pImgHdr->g_qme_max_spec_ring_length);
   pImgHdr->g_qme_cmn_ring_ovrd_offset  =   htobe32(pImgHdr->g_qme_cmn_ring_ovrd_offset);
   pImgHdr->g_qme_scom_offset           =   htobe32(pImgHdr->g_qme_scom_offset);
   pImgHdr->g_qme_scom_length           =   htobe32(pImgHdr->g_qme_scom_length);
   pImgHdr->g_qme_coreL2ScomLength      =   htobe32(pImgHdr->g_qme_coreL2ScomLength);
   pImgHdr->g_qme_L3ScomLength          =   htobe32(pImgHdr->g_qme_L3ScomLength);

   FAPI_DBG( "===================== QME Ring Header ============================== " );
   FAPI_DBG( "Common Ring Offset        0x%08x" , htobe32(pImgHdr->g_qme_common_ring_offset));
   FAPI_DBG( "Common Ring Length        0x%08x" , htobe32(pImgHdr->g_qme_common_ring_length));
   FAPI_DBG( "Override Ring Offset      0x%08x" , htobe32(pImgHdr->g_qme_cmn_ring_ovrd_offset));
   FAPI_DBG( "Instance Ring Offset      0x%08x" , htobe32(pImgHdr->g_qme_inst_spec_ring_offset));
   FAPI_DBG( "Instance Ring Length      0x%08x" , htobe32(pImgHdr->g_qme_max_spec_ring_length));
   FAPI_DBG( "SCOM Offset               0x%08x" , htobe32(pImgHdr->g_qme_scom_offset));
   FAPI_DBG( "SCOM Length               0x%08x" , htobe32(pImgHdr->g_qme_scom_length));

   FAPI_DBG( "===================== QME Ring Header Ends ========================= " );
#endif

   fapi_try_exit:
    FAPI_INF( "<< buildQmeHeader" )
    return fapi2::current_err;
}


//----------------------------------------------------------------------------------------------

/**
 * @brief       builds QME Attributes
 * @param[in]   i_pImageIn      points to HW Image
 * @param[in]   i_procTgt       fapi2 target for P10 proc chip
 * @param[in]   i_pChipHomer    models HOMER region of memory
 * @param[in]   i_qmeBuildRecord    contains QME image build details.
 * @param[in]   i_procFuncModel contains P10 chip configuration details.
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildQmeAttributes( void* const i_pImageIn,
                                      CONST_FAPI2_PROC& i_procTgt,
                                      Homerlayout_t* i_pChipHomer,
                                      ImageBuildRecord & i_qmeBuildRecord,
                                      P10FuncModel &i_procFuncModel)
{
    FAPI_INF(">> buildQmeAttributes");

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint32_t rcTemp    = IMG_BUILD_SUCCESS;
    uint64_t       magic_number = 0;
    uint8_t        l_pair_mode  = 0;
    uint8_t*       pQmeImg      = NULL;
    uint8_t*       pQmeMeta     = NULL;
    QmeAttrMeta_t* pQmeAttrMeta = NULL;
    QmeHeader_t*   pQmeAttrTank = NULL;
    P9XipSection   ppeSection;

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_FUSED_CORE_PAIRED_DISABLE, FAPI_SYSTEM, l_pair_mode),
             "Error From FAPI_ATTR_GET For ATTR_SYSTEM_FUSED_CORE_PAIRED_DISABLE");

    // invert disable to enable
    l_pair_mode = l_pair_mode ? 0 : 1;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FUSED_CORE_PAIRED_MODE_ENABLED, FAPI_SYSTEM, l_pair_mode),
             "Error From FAPI_ATTR_SET For ATTR_FUSED_CORE_PAIRED_MODE_ENABLED");

    // =============================
    // Get QME Image XIP Section

    rcTemp = p9_xip_get_section( i_pImageIn, P9_XIP_SECTION_HW_QME, &ppeSection );

    FAPI_DBG("QME Image: ppeSection.iv_offset = 0x%08X, ppeSection.iv_size = 0x%08X",
             ppeSection.iv_offset, ppeSection.iv_size);

    FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                 fapi2::QME_IMG_NOT_FOUND_IN_HW_IMG()
                 .set_XIP_FAILURE_CODE( rcTemp )
                 .set_EC_LEVEL( i_procFuncModel.getChipLevel() ),
                 "Failed to find QME sub-image in HW Image" );

    pQmeImg = ppeSection.iv_offset + (uint8_t*) (i_pImageIn );

    // =============================
    // Get QME Meta Data XIP Section

    ppeSection.iv_offset      =   0;
    ppeSection.iv_size        =   0;

    rcTemp = p9_xip_get_section( pQmeImg, P9_XIP_SECTION_QME_META_DATA, &ppeSection );

    FAPI_DBG("QME Meta: ppeSection.iv_offset = 0x%08X, ppeSection.iv_size = 0x%08X",
             ppeSection.iv_offset, ppeSection.iv_size);

    FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                 fapi2::QME_META_NOT_FOUND_IN_HW_IMG()
                 .set_XIP_FAILURE_CODE( rcTemp )
                 .set_EC_LEVEL( i_procFuncModel.getChipLevel() ),
                 "Failed to find QME Meta Data in HW Image" );

    // pointer to QME Meta Data of Attributes
    pQmeMeta     = ppeSection.iv_offset + (uint8_t*) ( pQmeImg );
    pQmeAttrMeta = (QmeAttrMeta_t*) pQmeMeta;

    magic_number = (*((uint64_t*)pQmeAttrMeta));
    magic_number = htobe64(magic_number);
    magic_number = magic_number >> 8;

    FAPI_DBG("QME Meta Data Address 0x%08X Magic Number: %llx Magic Word: %s Version %x",
             pQmeAttrMeta, magic_number, pQmeAttrMeta->magic_word, pQmeAttrMeta->meta_data_version);
    FAPI_DBG("System    Attributes Count %x Size %x", htobe16(pQmeAttrMeta->system_num_of_attrs),
                                                      htobe16(pQmeAttrMeta->system_num_of_bytes));
    FAPI_DBG("Proc Chip Attributes Count %x Size %x", htobe16(pQmeAttrMeta->proc_chip_num_of_attrs),
                                                      htobe16(pQmeAttrMeta->proc_chip_num_of_bytes));
    FAPI_DBG("Pervasive Attributes Count %x Size %x", htobe16(pQmeAttrMeta->perv_num_of_attrs),
                                                      htobe16(pQmeAttrMeta->perv_num_of_bytes));
    FAPI_DBG("EC        Attributes Count %x Size %x", htobe16(pQmeAttrMeta->ec_num_of_attrs),
                                                      htobe16(pQmeAttrMeta->ec_num_of_bytes));
    FAPI_DBG("EX        Attributes Count %x Size %x", htobe16(pQmeAttrMeta->ex_num_of_attrs),
                                                      htobe16(pQmeAttrMeta->ex_num_of_bytes));
    FAPI_DBG("EQ        Attributes Count %x Size %x", htobe16(pQmeAttrMeta->eq_num_of_attrs),
                                                      htobe16(pQmeAttrMeta->eq_num_of_bytes));

    FAPI_ASSERT( ( magic_number == QMEATMT_MAGIC_NUMBER ),
                 fapi2::QME_META_QMEATMT_MAGIC_MISMATCH()
                 .set_QMEATMT_MAGIC_WORD(magic_number)
                 .set_QME_META_HEADER_ADDR(pQmeAttrMeta),
                 "QMEATMT Magic Word Mismatch");

    // Pointer to QME Attribute Tank in Hcode image,
    // where the value of attributes will be written to

    pQmeAttrTank = (QmeHeader_t*) & i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion[QME_ATTR_PTRS_OFFSET];

    FAPI_DBG("QME Hcode Attribute Container Address = 0x%08X", pQmeAttrTank);
    fapi2::current_err = p10_qme_build_attributes(i_procTgt, pQmeAttrTank, pQmeAttrMeta);

fapi_try_exit:

    FAPI_INF("<< buildQmeAttributes");
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

/**
 * @brief populates SCOM restore headers at the base of each EQ region
 * @param[in]   i_procTgt       fapi2 target for P10.
 * @param[in]   i_pChipHomer    points to base of P10  HOMER
 * @return fapi2 return code.
 */
fapi2::ReturnCode   buildScomHeader( CONST_FAPI2_PROC& i_procTgt, Homerlayout_t *i_pChipHomer )
{
    FAPI_INF( ">> buildScomHeader" );

    uint8_t l_eqPos = 0;
    CpmrHeader_t* pCpmrHdr      =
        (CpmrHeader_t*) & ( i_pChipHomer->iv_cpmrRegion.iv_selfRestoreRegion.iv_CPMR_SR.elements.iv_CPMRHeader);
    ScomRestoreHeader_t * l_pScomHdr    =   NULL;
    uint32_t l_eqScomRegionSize =   htobe32(pCpmrHdr->iv_maxCoreL2ScomEntry) +
                                    htobe32(pCpmrHdr->iv_maxEqL3ScomEntry);
    uint32_t l_offset   =   0;
    auto eqList         =
        i_procTgt.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);

    for( auto eq : eqList )
    {
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, eq, l_eqPos ));
        l_offset    =   ( MAX_CORES_PER_QUAD * l_eqPos * l_eqScomRegionSize * SCOM_RESTORE_ENTRY_SIZE) ;   //Header at the start of an EQ SCOM region
        l_pScomHdr  =   (ScomRestoreHeader_t *)&i_pChipHomer->iv_cpmrRegion.
                                                iv_selfRestoreRegion.iv_coreScom[l_offset];

        //FIXME Need to clarify modulus 32B mentioned in spec
        l_pScomHdr->iv_magicMark    =   htobe16(SCOM_REST_MAGIC_WORD);
        l_pScomHdr->iv_version      =   SCOM_RESTORE_VER;
        l_pScomHdr->iv_coreOffset   =   sizeof(ScomRestoreHeader_t);
        l_pScomHdr->iv_l2Offset     =   l_pScomHdr->iv_coreOffset;

        l_pScomHdr->iv_coreLength   =   (SCOM_RESTORE_L2_CORE * SCOM_RESTORE_ENTRY_SIZE * MAX_CORES_PER_QUAD);
        l_pScomHdr->iv_coreLength   =   ( l_pScomHdr->iv_coreLength + BCE_RD_BLOCK_SIZE - 1 );
        l_pScomHdr->iv_coreLength   =   ( l_pScomHdr->iv_coreLength >> SHIFT_RD_BLOCK_SIZE );
        l_pScomHdr->iv_coreLength   =   ( l_pScomHdr->iv_coreLength << SHIFT_RD_BLOCK_SIZE );

        l_pScomHdr->iv_l3Offset     =   l_pScomHdr->iv_coreOffset + l_pScomHdr->iv_coreLength;

        l_pScomHdr->iv_l3Length     =   ((SCOM_RESTORE_L3_CACHE * SCOM_RESTORE_ENTRY_SIZE) * MAX_L3_PER_QUAD);
        l_pScomHdr->iv_l3Length     =   ( l_pScomHdr->iv_l3Length + BCE_RD_BLOCK_SIZE - 1 );
        l_pScomHdr->iv_l3Length     =   ( l_pScomHdr->iv_l3Length >> SHIFT_RD_BLOCK_SIZE );
        l_pScomHdr->iv_l3Length     =   ( l_pScomHdr->iv_l3Length << SHIFT_RD_BLOCK_SIZE );

        l_pScomHdr->iv_eqOffset     =   l_pScomHdr->iv_l3Offset;
        l_pScomHdr->iv_eqLength     =   l_pScomHdr->iv_l3Length;

#ifndef __HOSTBOOT_MODULE
        l_pScomHdr->iv_coreOffset   =   htobe16(l_pScomHdr->iv_coreOffset);
        l_pScomHdr->iv_l2Offset     =   htobe16(l_pScomHdr->iv_l2Offset);
        l_pScomHdr->iv_eqOffset     =   htobe16(l_pScomHdr->iv_eqOffset);
        l_pScomHdr->iv_l3Offset     =   htobe16(l_pScomHdr->iv_l3Offset);

        l_pScomHdr->iv_coreLength   =   htobe16( l_pScomHdr->iv_coreLength );
        l_pScomHdr->iv_l2Length     =   htobe16( l_pScomHdr->iv_l2Length );
        l_pScomHdr->iv_eqLength     =   htobe16( l_pScomHdr->iv_eqLength );
        l_pScomHdr->iv_l3Length     =   htobe16( l_pScomHdr->iv_l3Length );
#endif

        FAPI_DBG( "=================== SCOM Restore Entry Header ====================" );
        FAPI_DBG( "SCOM Magic Word          0x%04x",  htobe16(l_pScomHdr->iv_magicMark) );
        FAPI_DBG( "SCOM Restore Ver         0x%02x",  l_pScomHdr->iv_version );
        FAPI_DBG( "Core SCOM Offset         0x%04x",  htobe16(l_pScomHdr->iv_coreOffset) );
        FAPI_DBG( "Core SCOM Length         0x%04x",  htobe16( l_pScomHdr->iv_coreLength ) );
        FAPI_DBG( "L3 SCOM Offset           0x%04x",  htobe16( l_pScomHdr->iv_l3Offset) );
        FAPI_DBG( "L3 SCOM Length           0x%04x",  htobe16( l_pScomHdr->iv_l3Length) );
        FAPI_DBG( "===================================================================" );

    }

   fapi_try_exit:
    FAPI_INF( "<< buildScomHeader" );
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

/**
 * @brief       builds CPMR header in HOMER
 * @param[in]   i_procTgt           fapi2 target for P10 proc chip
 * @param[in]   i_pChipHomer        models HOMER region in memory
 * @param[in]   i_qmeBuildRecord    contains QME image build details.
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildCpmrHeader( CONST_FAPI2_PROC& i_procTgt, Homerlayout_t   *i_pChipHomer, uint8_t i_fusedState, ImageBuildRecord & i_qmeBuildRecord )
{
    CpmrHeader_t* pCpmrHdr =
        (CpmrHeader_t*) & ( i_pChipHomer->iv_cpmrRegion.iv_selfRestoreRegion.iv_CPMR_SR.elements.iv_CPMRHeader);
    uint32_t l_qmeHcodeOffset           =    QME_IMAGE_CPMR_OFFSET;
    ImgSectnSumm    l_imgSectn;

    pCpmrHdr->iv_fusedMode   =   i_fusedState ? (uint8_t)(FUSED_CORE_MODE) :(uint8_t)(NONFUSED_CORE_MODE);

    if( !i_qmeBuildRecord.getSection( "QME Hcode", l_imgSectn ) )
    {
        pCpmrHdr->iv_qmeImgOffset       =    htobe32( l_qmeHcodeOffset );
        pCpmrHdr->iv_qmeImgLength       =    htobe32( l_imgSectn.iv_sectnLength );
    }

    pCpmrHdr->iv_scomRestoreOffset      =    htobe32( SCOM_RESTORE_CPMR_OFFSET );
    pCpmrHdr->iv_scomRestoreLength      =    htobe32( SCOM_RESTORE_SIZE_TOTAL );

    if( !i_qmeBuildRecord.getSection( "SELF", l_imgSectn ) )
    {
        pCpmrHdr->iv_selfRestoreOffset  =    htobe32( CPMR_HOMER_OFFSET + CPMR_HEADER_SIZE );
        pCpmrHdr->iv_selfRestoreLength  =    htobe32( l_imgSectn.iv_sectnLength );
    }

    if( !i_qmeBuildRecord.getSection( "QME Common Ring", l_imgSectn ) )
    {
        pCpmrHdr->iv_commonRingOffset   =   htobe32( l_imgSectn.iv_sectnOffset );
        pCpmrHdr->iv_commonRingLength   =   htobe32( l_imgSectn.iv_sectnLength );
    }

    pCpmrHdr->iv_maxCoreL2ScomEntry   =     htobe32(MAX_CORE_SCOM_ENTRIES + MAX_L2_SCOM_ENTRIES);
    pCpmrHdr->iv_maxEqL3ScomEntry     =     htobe32(MAX_EQ_SCOM_ENTRIES + MAX_L3_SCOM_ENTRIES);

    if( !i_qmeBuildRecord.getSection( "QME Inst Sectn", l_imgSectn ) )
    {
        pCpmrHdr->iv_specRingOffset     =   htobe32( l_imgSectn.iv_sectnOffset );
        pCpmrHdr->iv_specRingLength     =   htobe32( l_imgSectn.iv_sectnLength );
    }

    if( !i_qmeBuildRecord.getSection( "QME SCOM Restore" , l_imgSectn ) )
    {
         pCpmrHdr->iv_scomRestoreOffset  =   htobe32( l_imgSectn.iv_sectnOffset );
         pCpmrHdr->iv_scomRestoreLength  =   MAX_QUADS_PER_CHIP * l_imgSectn.iv_sectnLength;
         pCpmrHdr->iv_scomRestoreLength  =   htobe32( pCpmrHdr->iv_scomRestoreLength );
    }

    i_qmeBuildRecord.dumpBuildRecord();

    FAPI_TRY( buildScomHeader( i_procTgt, i_pChipHomer ) );

    pCpmrHdr->iv_autoWkUpVectOffset     =   htobe32(AUTO_WAKEUP_CPMR_HDR_OFFSET);
    pCpmrHdr->iv_autoWkUpVectLength     =   htobe32(AUTO_WAKEUP_CPMR_HDR_LENGTH);

#ifndef __HOSTBOOT_MODULE
    FAPI_INF( "Max Core L2 SCOM Entry       0x%08x", htobe32( pCpmrHdr->iv_maxCoreL2ScomEntry) );
    FAPI_INF( "Max Cache L3 SCOM Entry      0x%08x",  htobe32( pCpmrHdr->iv_maxEqL3ScomEntry) );
    FAPI_INF( "QME Hcode Offset             0x%08x",  htobe32( pCpmrHdr->iv_qmeImgOffset ));
    FAPI_INF( "QME Hcode Length             0x%08x",  htobe32( pCpmrHdr->iv_qmeImgLength ));
    FAPI_INF( "Core Common Ring Offset      0x%08x",  htobe32( pCpmrHdr->iv_commonRingOffset ));
    FAPI_INF( "Core Common Ring Length      0x%08x",  htobe32( pCpmrHdr->iv_commonRingLength ));
    FAPI_INF( "Core Spec Ring Offset        0x%08x",  htobe32( pCpmrHdr->iv_specRingOffset ));
    FAPI_INF( "Core Spec Ring Length        0x%08x",  htobe32( pCpmrHdr->iv_specRingLength ));
    FAPI_INF( "SCOM Restore Offset          0x%08x",  htobe32( pCpmrHdr->iv_scomRestoreOffset ));
    FAPI_INF( "SCOM Restore Length          0x%08x",  htobe32( pCpmrHdr->iv_scomRestoreLength ));

#endif
    FAPI_INF( "Auto Wakeup Vector Offset    0x%08x",  htobe32( pCpmrHdr->iv_autoWkUpVectOffset));
    FAPI_INF( "Auto Wakeup Vector Length    0x%08x",  htobe32( pCpmrHdr->iv_autoWkUpVectLength));

 fapi_try_exit:
    FAPI_INF( "<< buildCpmrHeader" )
    return fapi2::current_err;
}

//-------------------------------------------------------------------------------------------------------
/**
 * @brief creates Auto wakeup Vector.
 * @param[in]   i_pHomerImage       points to P10 chip's HOMER.
 * @param[in]   i_fuseMode          fuse status of core
 * @param[in]   i_chipFuncModel     describes config details of the P10 chip
 * @return      fapi2 return code
 */
fapi2::ReturnCode createAutoWakeupVector( void * const i_pHomerImage,
                                          uint8_t i_fuseMode,
                                          P10FuncModel & i_chipFuncModel  )
{
    FAPI_INF( ">> createAutoWakeupVector" );

    uint64_t l_pir      =   0;
    stopImageSection::StopReturnCode_t l_rc;

    for( uint8_t l_corePos = 0; l_corePos < MAX_CORES_PER_CHIP; l_corePos++ )
    {
        if( i_chipFuncModel.isCoreFunctional( l_corePos ) )
        {
            l_pir = getPirValue( l_corePos, 0, i_fuseMode );
            l_rc = stopImageSection::proc_stop_auto_wakeup( i_pHomerImage,
                                                            l_pir,
                                                            0x01 );
            FAPI_ASSERT( ( !l_rc ),
                         fapi2::AUTO_WAKEUP_VECTOR_CREATION_FAILED()
                         .set_PIR( l_pir )
                         .set_STOP_API_RC( l_rc ),
                         "Failed To Create Auto Wakeup Vector For Core %d RC: %d", l_corePos, (uint32_t)l_rc  );
        }
    }

fapi_try_exit:
    FAPI_INF( "<< createAutoWakeupVector" );
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

/**
 * @brief       initializes attributes influencing CPMR
 * @param[in]   i_pChipHomer        models HOMER region in memory
 * @param[in]   i_qmeBuildRecord    contains QME image build details.
 * @return      fapi2 return code.
 */
fapi2::ReturnCode initCpmrAttribute( Homerlayout_t   *i_pChipHomer,
                                     ImageBuildRecord & i_qmeBuildRecord )
{
    ImgSectnSumm    l_imgSectn;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_QME_HCODE_OFFSET_Type l_qmeHcodeOffset;
    fapi2::ATTR_QME_HCODE_BLOCK_COUNT_Type l_blockCount;
    uint32_t l_tempCount    =   0;

    CpmrHeader_t* pCpmrHdr =
        (CpmrHeader_t*) & ( i_pChipHomer->iv_cpmrRegion.iv_selfRestoreRegion.iv_CPMR_SR.elements.iv_CPMRHeader);

    l_qmeHcodeOffset =  htobe32( pCpmrHdr->iv_qmeImgOffset );
    FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_QME_HCODE_OFFSET,
                             FAPI_SYSTEM,
                             l_qmeHcodeOffset),
              "Failed To Set ATTR_QME_HCODE_BLOCK_COUNT");


    i_qmeBuildRecord.getSection( "QME Hcode", l_imgSectn );
    l_tempCount     =   l_imgSectn.iv_sectnLength;

    if( QME_VER_BASE == i_qmeBuildRecord.getPpeImageVer() )
    {
        i_qmeBuildRecord.getSection( "QME Common Ring", l_imgSectn );
        l_tempCount    +=   l_imgSectn.iv_sectnLength;
    }

    l_blockCount    =   (( l_tempCount + BCE_RD_BLOCK_SIZE - 1 ) >>  SHIFT_RD_BLOCK_SIZE );

    FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_QME_HCODE_BLOCK_COUNT,
                            FAPI_SYSTEM,
                            l_blockCount),
              "Failed To Set ATTR_QME_HCODE_BLOCK_COUNT");

    FAPI_DBG( "QME Image Block Count 0x%08x", l_blockCount );

fapi_try_exit:
    return fapi2::current_err;
}

//----------------------------------------------------------------------------------------------

/**
 * @brief populates Magic Word in various headers
 * @param[in]   i_pChipHomer        models HOMER region in memory
 * @return      fapi2 return code.
 */
fapi2::ReturnCode populateMagicWord( Homerlayout_t   *i_pChipHomer )
{
    //FIXME Needs to review use of this function because image edit infra is
    //available.
    FAPI_INF( ">> populateMagicWord" );
    //Populate CPMR Header's Magic Word
    CpmrHeader_t* pCpmrHdr      =
        (CpmrHeader_t*) & ( i_pChipHomer->iv_cpmrRegion.iv_selfRestoreRegion.iv_CPMR_SR.elements.iv_CPMRHeader);
    QmeHeader_t* pQmeImgHdr     =
        (QmeHeader_t*) & i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion[QME_INT_VECTOR_SIZE];
    PgpeHeader_t * pPgpeHeader   =
            ( PgpeHeader_t *) &i_pChipHomer->iv_ppmrRegion.iv_pgpeSramRegion[PGPE_INT_VECTOR_SIZE];
    PpmrHeader_t * l_pPpmrHdr   =
            (PpmrHeader_t *) i_pChipHomer->iv_ppmrRegion.iv_ppmrHeader;
    XpmrHeader_t * l_pXpmrHdr   =
            (XpmrHeader_t *) i_pChipHomer->iv_xpmrRegion.iv_xpmrHeader;
    XgpeHeader_t * pXgpeHeader  =
            ( XgpeHeader_t *) &i_pChipHomer->iv_xpmrRegion.iv_xgpeSramRegion[XGPE_INT_VECTOR_SIZE];

    pCpmrHdr->iv_cpmrMagicWord      =   htobe64(CPMR_MAGIC_NUMBER);
    pQmeImgHdr->g_qme_magic_number  =   htobe64(SCOM_RESTORE_OPT_VER);

    //QME image header magic word will come from hw image. This is for
    //managing compatibility between hw image and hcode image build.
    l_pPpmrHdr->iv_ppmrMagicWord    =   htobe64(PPMR_MAGIC_NUMBER);
    pPgpeHeader->g_pgpe_magicWord   =   htobe64(PGPE_MAGIC_NUMBER);
    l_pXpmrHdr->iv_xpmrMagicWord    =   htobe64(XPMR_MAGIC_NUMBER);
    pXgpeHeader->g_xgpe_magicWord   =   htobe64(XGPE_MAGIC_NUMBER);

    if( pXgpeHeader->g_xgpe_buildVer == htobe32(XGPE_48K_VER) )
    {
        //If magic word has been changed through an HCODE commit, move 
        //to new OCC SRAM sharing scheme of PGPE and XGPE.
        l_pXpmrHdr->iv_xgpeBaseAddress  =   htobe32(XGPE_RELOC_BASE);
    }
    else
    {
        l_pXpmrHdr->iv_xgpeBaseAddress  =  htobe32(XGPE_SRAM_BASE_ADDR);
    }

    FAPI_INF( "XGPE SRAM Base Address    0x%08x", htobe32(l_pXpmrHdr->iv_xgpeBaseAddress) );

    FAPI_INF( "<< populateMagicWord" );
    return fapi2::current_err;
}

/**
 * @brief       Inserts Runtime SCOMs into SCOM restore section
 * @param[in]   i_procTgt           fapi2 target for P10 proc chip
 * @param[in]   i_pChipHomer        models HOMER region in memory
 * @return      fapi2 return code.
 */
fapi2::ReturnCode insertRuntimeSCOMs( CONST_FAPI2_PROC& i_procTgt, Homerlayout_t   *i_pChipHomer )
{
    FAPI_INF( ">> insertRuntimeSCOMs" );

    std::vector<uint64_t> l_topo_scoms;

    // Get the register values for the SCOMs to setup the topology id table
    FAPI_TRY(topo::get_topology_table_scoms(i_procTgt, l_topo_scoms));

    for (const auto& l_core : i_procTgt.getChildren<fapi2::TARGET_TYPE_CORE>())
    {
        FAPI_INF("Put core runtime SCOM updates into HOMER ");
        FAPI_TRY( p10_fbc_core_topo( l_core,
                                     l_topo_scoms,
                                     i_pChipHomer,
                                     stopImageSection::PROC_STOP_SECTION_CORE,
                                     rt_topo::RT_TOPO_MODE_HOMER));

        FAPI_INF("Put cache runtime SCOM updates into HOMER ");
        FAPI_TRY( p10_fbc_core_topo( l_core,
                                     l_topo_scoms,
                                     i_pChipHomer,
                                     stopImageSection::PROC_STOP_SECTION_CACHE,
                                     rt_topo::RT_TOPO_MODE_HOMER));
    }

fapi_try_exit:
    FAPI_INF( "<< insertRuntimeSCOMs" );
    return fapi2::current_err;

}
//----------------------------------------------------------------------------------------------
/**
 * @brief   build CPMR region
 * @param[in]   i_procTgt       fapi2 target for P10 chip
 * @param[in]   i_pImageIn      points to hardware reference image
 * @param[in]   i_pChipHomer    models HOMER
 * @param[in]   i_phase         IPL or Runtime
 * @param[in]   i_imgType       image type to be built
 * @param[in]   i_chipFuncModel P10 chip configuration
 * @param[in]   i_ringData      buffers to extract and process rings.
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildCpmrImage( CONST_FAPI2_PROC& i_procTgt,
                                  void* const     i_pImageIn,
                                  Homerlayout_t   *i_pChipHomer,
                                  SysPhase_t      i_phase,
                                  ImageType_t     i_imgType,
                                  P10FuncModel    &i_chipFuncModel,
                                  RingBufData     &i_ringData )
{
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint8_t  l_fuseModeState    =   0;
    uint8_t  l_containedMode    =   0;
    ImageBuildRecord    l_qmeBuildRecord( (uint8_t *)(&i_pChipHomer->iv_occHostRegion), "QME" );

    // copy sections pertaining to self restore
    // Note: this creates the CPMR header portion

    // let us determine if system is configured in fuse mode. This needs to
    // be updated in a CPMR region.

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUSED_CORE_MODE,
                           FAPI_SYSTEM,
                           l_fuseModeState),
             "Error From FAPI_ATTR_GET For Attribute ATTR_FUSED_CORE_MODE");

    FAPI_INF("CPMR / Self Restore building");

    FAPI_TRY( buildCoreRestoreImage( i_pImageIn, i_pChipHomer, i_imgType, l_fuseModeState, i_chipFuncModel, l_qmeBuildRecord ),
                  "Failed To Copy Core Self Restore Section in HOMER" );

    FAPI_INF("CPMR / Self Restore built ");

    // copy sections pertaining to QME
    FAPI_INF("CPMR / QME building");
    FAPI_TRY( buildQmeImage( i_pImageIn, i_pChipHomer, i_imgType, i_chipFuncModel, l_qmeBuildRecord ),
              "Failed To Copy QME Section In HOMER" );

    FAPI_TRY( buildQmeRing( i_procTgt, i_pImageIn, i_pChipHomer, i_chipFuncModel, i_ringData, l_qmeBuildRecord ),
              "Failed To Build QME Ring Region" );

    FAPI_TRY( buildQmeHeader( i_procTgt, i_pChipHomer, l_qmeBuildRecord ),
              "Failed To Build QME Image Header" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CONTAINED_IPL_TYPE,
                           FAPI_SYSTEM,
                           l_containedMode),
             "Error From FAPI_ATTR_GET For Attribute ATTR_CONTAINED_IPL_TYPE");

    if( !l_containedMode )
    {
        FAPI_TRY( buildQmeAttributes( i_pImageIn, i_procTgt, i_pChipHomer, l_qmeBuildRecord, i_chipFuncModel ),
                  "Failed To Initialize QME Attributes In HOMER QME Hcode Image" );
    }

    FAPI_TRY( buildCpmrHeader( i_procTgt, i_pChipHomer, l_fuseModeState, l_qmeBuildRecord ),
              "Failed To Build CPMR Header" );

    FAPI_TRY( initCpmrAttribute( i_pChipHomer, l_qmeBuildRecord ),
              "Failed To Initialize CPMR Attribute" );

    FAPI_TRY( insertRuntimeSCOMs( i_procTgt, i_pChipHomer ),
              "Failed To Insert Runtime SCOMs" );

    #ifdef __AUTO_WAKEUP_TEST_

    FAPI_TRY( createAutoWakeupVector( i_pChipHomer, l_fuseModeState, i_chipFuncModel ),
              "Failed To Create Auto Wakeup Vector" );
    #endif

fapi_try_exit:

    FAPI_INF("CPMR / QME built");
    return fapi2::current_err;

}

//-------------------------------------------------------------------------------------------------------

/**
 * @brief   builds P-State parameter block region of HOMER.
 * @param[in]   i_procTgt       fapi2 target for P10 chip
 * @param[in]   i_pChipHomer        models P10's HOMER.
 * @param[in]   i_ppmrBuildRecord   PPMR region image build metadata
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildParameterBlock( CONST_FAPI2_PROC& i_procTgt, Homerlayout_t* i_pChipHomer,
                                       ImageBuildRecord & i_ppmrBuildRecord )
{
    FAPI_DBG( " >> buildParameterBlock " );
    ImgSectnSumm   l_sectn;
    i_ppmrBuildRecord.getSection( "PGPE Hcode", l_sectn );
    PstateSuperStructure  *l_pstateParamBlock = new PstateSuperStructure;
    memset( l_pstateParamBlock, 0x00, sizeof(PstateSuperStructure) );
    uint8_t * l_pWofData    =   i_pChipHomer->iv_ppmrRegion.iv_wofTable;
    uint32_t  l_pstableSize =   PGPE_PSTATE_OUTPUT_TABLES_SIZE;
    uint32_t  l_wofSize     =   (uint32_t)OCC_WOF_TABLES_SIZE;
    uint32_t  l_tempOffset  =   l_sectn.iv_sectnOffset + l_sectn.iv_sectnLength;
    FAPI_DBG( "WOF Size before 0x%08x", l_wofSize);

    FAPI_TRY( p10_pstate_parameter_block( i_procTgt, l_pstateParamBlock, l_pWofData, l_wofSize ) );

    FAPI_DBG( "PGPE Hcode Offset 0x%08x  Length 0x%08x  WOF Size 0x%08x",
                l_sectn.iv_sectnOffset, l_sectn.iv_sectnLength, l_wofSize);

    memcpy( &i_pChipHomer->iv_ppmrRegion.iv_pgpeSramRegion[l_sectn.iv_sectnLength],
            &l_pstateParamBlock->iv_globalppb, sizeof(GlobalPstateParmBlock_v1_t) );

    i_ppmrBuildRecord.setSection( "GPSPB", l_tempOffset, sizeof(GlobalPstateParmBlock_v1_t) );

    memcpy( i_pChipHomer->iv_ppmrRegion.iv_occPstateParamBlock, &l_pstateParamBlock->iv_occppb,
            sizeof( OCCPstateParmBlock_t ) );

    i_ppmrBuildRecord.setSection( "OPSPB", OCC_PSTATE_PARAM_BLOCK_PPMR_OFFSET,
                                  sizeof( OCCPstateParmBlock_t ) );

    i_ppmrBuildRecord.setSection( "PState Table", PGPE_PSTATE_OUTPUT_TABLES_PPMR_OFFSET,
                                  l_pstableSize );

    i_ppmrBuildRecord.setSection( "WOF Tables", OCC_WOF_TABLES_PPMR_OFFSET,
                                  l_wofSize );

    FAPI_DBG( " << buildParameterBlock " );

    fapi_try_exit:
    delete l_pstateParamBlock;
    return fapi2::current_err;

}
//-------------------------------------------------------------------------------------------------------

/**
 * @brief   builds PPMR header in the HOMER.
 * @param[in]   i_pChipHomer        models P10's HOMER.
 * @param[in]   i_ppmrBuildRecord   PPMR region image build metadata
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildPpmrHeader( Homerlayout_t* i_pChipHomer, ImageBuildRecord & i_ppmrBuildRecord )
{
    ImgSectnSumm   l_sectn;
    PpmrHeader_t * l_pPpmrHdr   =
            (PpmrHeader_t *) i_pChipHomer->iv_ppmrRegion.iv_ppmrHeader;

    //PGPE Boot Copier
    i_ppmrBuildRecord.getSection( "PGPE Boot Copier", l_sectn );
    l_pPpmrHdr->iv_bootCopierOffset = l_sectn.iv_sectnOffset;

    //PGPE Boot Loader
    i_ppmrBuildRecord.getSection( "PGPE Boot Loader", l_sectn );
    l_pPpmrHdr->iv_bootLoaderOffset     =   l_sectn.iv_sectnOffset;
    l_pPpmrHdr->iv_bootLoaderLength     =   PGPE_BOOT_LOADER_SIZE;

    //PGPE Hcode
    i_ppmrBuildRecord.getSection( "PGPE Hcode", l_sectn );
    l_pPpmrHdr->iv_hcodeOffset  =   l_sectn.iv_sectnOffset;
    l_pPpmrHdr->iv_hcodeLength  =   l_sectn.iv_sectnLength;

    //GPSPB
    i_ppmrBuildRecord.getSection( "GPSPB", l_sectn );
    l_pPpmrHdr->iv_gpspbOffset  =   l_sectn.iv_sectnOffset;
    l_pPpmrHdr->iv_gpspbLength  =   l_sectn.iv_sectnLength;

    //OPSPB
    i_ppmrBuildRecord.getSection( "OPSPB", l_sectn );
    l_pPpmrHdr->iv_opspbOffset  =   l_sectn.iv_sectnOffset;
    l_pPpmrHdr->iv_opspbLength  =   l_sectn.iv_sectnLength;

    //Generated Pstate Table
    i_ppmrBuildRecord.getSection( "PState Table", l_sectn );
    l_pPpmrHdr->iv_pstateOffset =   l_sectn.iv_sectnOffset;
    l_pPpmrHdr->iv_pstateLength =   l_sectn.iv_sectnLength;

    //PGPE SRAM
    l_pPpmrHdr->iv_sramSize     =   l_pPpmrHdr->iv_hcodeLength + l_pPpmrHdr->iv_gpspbLength ;


    //WOF Table
    i_ppmrBuildRecord.getSection( "WOF Tables", l_sectn );
    l_pPpmrHdr->iv_wofTableOffset   =   l_sectn.iv_sectnOffset;
    l_pPpmrHdr->iv_wofTableLength   =   l_sectn.iv_sectnLength;

    //PGPE Op Trace
    i_ppmrBuildRecord.getSection( "PGPE Op Trace", l_sectn );
    l_pPpmrHdr->iv_deepOptraceOffset =  l_sectn.iv_sectnOffset;
    l_pPpmrHdr->iv_deepOptraceLength =  l_sectn.iv_sectnLength;

    //Init start address of PGPE Image
    l_pPpmrHdr->iv_pgpeBaseAddress   =   htobe32(PGPE_SRAM_BASE_ADDR);

    i_ppmrBuildRecord.dumpBuildRecord();

#ifndef __HOSTBOOT_MODULE
    l_pPpmrHdr->iv_bootCopierOffset     =   htobe32(l_pPpmrHdr->iv_bootCopierOffset);
    l_pPpmrHdr->iv_bootLoaderOffset     =   htobe32(l_pPpmrHdr->iv_bootLoaderOffset);
    l_pPpmrHdr->iv_bootLoaderLength     =   htobe32(l_pPpmrHdr->iv_bootLoaderLength);
    l_pPpmrHdr->iv_hcodeOffset          =   htobe32(l_pPpmrHdr->iv_hcodeOffset);
    l_pPpmrHdr->iv_hcodeLength          =   htobe32(l_pPpmrHdr->iv_hcodeLength);
    l_pPpmrHdr->iv_sramSize             =   htobe32(l_pPpmrHdr->iv_sramSize);
    l_pPpmrHdr->iv_gpspbOffset          =   htobe32(l_pPpmrHdr->iv_gpspbOffset);
    l_pPpmrHdr->iv_gpspbLength          =   htobe32(l_pPpmrHdr->iv_gpspbLength);
    l_pPpmrHdr->iv_opspbOffset          =   htobe32(l_pPpmrHdr->iv_opspbOffset);
    l_pPpmrHdr->iv_opspbLength          =   htobe32(l_pPpmrHdr->iv_opspbLength);
    l_pPpmrHdr->iv_pstateOffset         =   htobe32(l_pPpmrHdr->iv_pstateOffset);
    l_pPpmrHdr->iv_pstateLength         =   htobe32(l_pPpmrHdr->iv_pstateLength);
    l_pPpmrHdr->iv_wofTableOffset       =   htobe32(l_pPpmrHdr->iv_wofTableOffset);
    l_pPpmrHdr->iv_wofTableLength       =   htobe32(l_pPpmrHdr->iv_wofTableLength);
    l_pPpmrHdr->iv_deepOptraceOffset    =   htobe32(l_pPpmrHdr->iv_deepOptraceOffset);
    l_pPpmrHdr->iv_deepOptraceLength    =   htobe32(l_pPpmrHdr->iv_deepOptraceLength);

    FAPI_DBG( "====================== PPMR Header =======================" );
    FAPI_DBG( "PPMR BC Offset             0x%08x", htobe32(l_pPpmrHdr->iv_bootCopierOffset));
    FAPI_DBG( "PPMR BL Offset             0x%08x", htobe32(l_pPpmrHdr->iv_bootLoaderOffset));
    FAPI_DBG( "PPMR BL Length             0x%08x", htobe32(l_pPpmrHdr->iv_bootLoaderLength));
    FAPI_DBG( "PPMR Hcode Offset          0x%08x", htobe32(l_pPpmrHdr->iv_hcodeOffset));
    FAPI_DBG( "PPMR Hcode Length          0x%08x", htobe32(l_pPpmrHdr->iv_hcodeLength));
    FAPI_DBG( "PPMR GPSPB Offset          0x%08x", htobe32(l_pPpmrHdr->iv_gpspbOffset));
    FAPI_DBG( "PPMR GPSPB Length          0x%08x", htobe32(l_pPpmrHdr->iv_gpspbLength));
    FAPI_DBG( "PPMR OPSPB Offset          0x%08x", htobe32(l_pPpmrHdr->iv_opspbOffset));
    FAPI_DBG( "PPMR OPSPB Length          0x%08x", htobe32(l_pPpmrHdr->iv_opspbLength));
    FAPI_DBG( "PPMR Pstate Offset         0x%08x", htobe32(l_pPpmrHdr->iv_pstateOffset));
    FAPI_DBG( "PPMR Pstate Length         0x%08x", htobe32(l_pPpmrHdr->iv_pstateLength));
    FAPI_DBG( "PGPE SRAM Image Length     0x%08x", htobe32(l_pPpmrHdr->iv_sramSize));
    FAPI_DBG( "WOF Table Offset           0x%08x", htobe32(l_pPpmrHdr->iv_wofTableOffset));
    FAPI_DBG( "WOF Table Length           0x%08x", htobe32(l_pPpmrHdr->iv_wofTableLength));
    FAPI_DBG( "Deep Op Trace Offset       0x%08x", htobe32(l_pPpmrHdr->iv_deepOptraceOffset));
    FAPI_DBG( "Deep Op Trace Length       0x%08x", htobe32(l_pPpmrHdr->iv_deepOptraceLength));
    FAPI_DBG( "PGPE SRAM Base Address     0x%08x", htobe32(l_pPpmrHdr->iv_pgpeBaseAddress));

    FAPI_DBG( "==========================================================" );
#endif

    return fapi2::current_err;
}

//-------------------------------------------------------------------------------------------------------

/**
 * @brief   populates few fields of PGPE image  header in HOMER.
 * @param[in]   i_pChipHomer    models P10's HOMER.
 * @param[in]   i_ppmrBuildRecord     PPMR region image build metadata
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildPgpeHeader( Homerlayout_t* i_pChipHomer, ImageBuildRecord & i_ppmrBuildRecord )
{
    ImgSectnSumm   l_sectn;
    i_ppmrBuildRecord.getSection( "PGPE Hcode", l_sectn );
    PgpeHeader_t * pPgpeHeader   =
            ( PgpeHeader_t *) &i_pChipHomer->iv_ppmrRegion.iv_pgpeSramRegion[PGPE_INT_VECTOR_SIZE];

    pPgpeHeader->g_pgpe_hcodeLength         =   l_sectn.iv_sectnLength;
    pPgpeHeader->g_pgpe_sysResetAddress     =   PGPE_SRAM_BASE_ADDR + PPE_RESET_VECTOR;
    pPgpeHeader->g_pgpe_ivprAddress         =   PGPE_SRAM_BASE_ADDR;
    pPgpeHeader->g_pgpe_gpspbSramAddress    =   PGPE_SRAM_BASE_ADDR + pPgpeHeader->g_pgpe_hcodeLength;
    i_ppmrBuildRecord.getSection( "GPSPB", l_sectn );
    pPgpeHeader->g_pgpe_gpspbMemOffset      =   l_sectn.iv_sectnOffset + PPMR_MEM_MASK;
    pPgpeHeader->g_pgpe_gpspbMemLength      =   l_sectn.iv_sectnLength;
    i_ppmrBuildRecord.getSection( "PState Table", l_sectn );
    pPgpeHeader->g_pgpe_genPsTableMemOffset =   l_sectn.iv_sectnOffset + PPMR_MEM_MASK;
    pPgpeHeader->g_pgpe_genPsTableMemLength =   l_sectn.iv_sectnLength;
    i_ppmrBuildRecord.getSection( "WOF Tables", l_sectn );
    pPgpeHeader->g_pgpe_wofTableAddress     =   l_sectn.iv_sectnOffset + PPMR_MEM_MASK;
    pPgpeHeader->g_pgpe_wofTableLength      =   l_sectn.iv_sectnLength;
    i_ppmrBuildRecord.getSection( "PGPE Op Trace", l_sectn );
    pPgpeHeader->g_pgpe_deepOpTraceMemAddress =
            ( EXT_MEM_ADDR | ( HOMER_PPMR_REGION_NUM * ONE_MB ) | l_sectn.iv_sectnOffset );
    pPgpeHeader->g_pgpe_deepOpTraceLength   =  l_sectn.iv_sectnLength;

#ifndef __HOSTBOOT_MODULE
    pPgpeHeader->g_pgpe_hcodeLength         =   htobe32( pPgpeHeader->g_pgpe_hcodeLength );
    pPgpeHeader->g_pgpe_sysResetAddress     =   htobe32( pPgpeHeader->g_pgpe_sysResetAddress );
    pPgpeHeader->g_pgpe_ivprAddress         =   htobe32( pPgpeHeader->g_pgpe_ivprAddress );
    pPgpeHeader->g_pgpe_gpspbSramAddress    =   htobe32( pPgpeHeader->g_pgpe_gpspbSramAddress );
    pPgpeHeader->g_pgpe_gpspbMemOffset      =   htobe32( pPgpeHeader->g_pgpe_gpspbMemOffset );
    pPgpeHeader->g_pgpe_gpspbMemLength      =   htobe32( pPgpeHeader->g_pgpe_gpspbMemLength );
    pPgpeHeader->g_pgpe_genPsTableMemOffset =   htobe32( pPgpeHeader->g_pgpe_genPsTableMemOffset );
    pPgpeHeader->g_pgpe_genPsTableMemLength =   htobe32( pPgpeHeader->g_pgpe_genPsTableMemLength );
    pPgpeHeader->g_pgpe_wofTableAddress     =   htobe32( pPgpeHeader->g_pgpe_wofTableAddress );
    pPgpeHeader->g_pgpe_wofTableLength      =   htobe32( pPgpeHeader->g_pgpe_wofTableLength );
    pPgpeHeader->g_pgpe_deepOpTraceMemAddress = htobe32( pPgpeHeader->g_pgpe_deepOpTraceMemAddress );
    pPgpeHeader->g_pgpe_deepOpTraceLength   =   htobe32( pPgpeHeader->g_pgpe_deepOpTraceLength );


    FAPI_DBG( "====================== PGPE Header =======================" );
    FAPI_INF( "PGPE Hcode Length        0x%08x", htobe32( pPgpeHeader->g_pgpe_hcodeLength ) );
    FAPI_INF( "PGPE Sys Reset Address   0x%08x", htobe32( pPgpeHeader->g_pgpe_sysResetAddress ) );
    FAPI_INF( "PGPE IVPR Address        0x%08x", htobe32( pPgpeHeader->g_pgpe_ivprAddress ) );
    FAPI_INF( "GPSPB SRAM Address       0x%08x", htobe32( pPgpeHeader->g_pgpe_gpspbSramAddress ));
    FAPI_INF( "GPSPB Mem  Address       0x%08x", htobe32( pPgpeHeader->g_pgpe_gpspbMemOffset ));
    FAPI_INF( "GPSPB Length             0x%08x", htobe32( pPgpeHeader->g_pgpe_gpspbMemLength ));
    FAPI_INF( "Gen GPSPB Mem  Address   0x%08x", htobe32( pPgpeHeader->g_pgpe_genPsTableMemOffset ));
    FAPI_INF( "Gen GPSPB Length         0x%08x", htobe32( pPgpeHeader->g_pgpe_genPsTableMemLength ));
    FAPI_INF( "WOF Table Mem Offset     0x%08x", htobe32( pPgpeHeader->g_pgpe_wofTableAddress ));
    FAPI_INF( "WOF Table Mem Length     0x%08x", htobe32( pPgpeHeader->g_pgpe_wofTableLength ));
    FAPI_INF( "PGPE Deep Optrace Offset 0x%08x", htobe32( pPgpeHeader->g_pgpe_deepOpTraceMemAddress ));
    FAPI_INF( "PGPE Deep Optrace Length 0x%08x", htobe32( pPgpeHeader->g_pgpe_deepOpTraceLength ));

    FAPI_DBG( "==========================================================" );
#endif

    return fapi2::current_err;
}

//-------------------------------------------------------------------------------------------------------

/**
 * @brief   builds PPMR region
 * @param[in]   i_procTgt       fapi2 target for P10 chip
 * @param[in]   i_pImageIn      points to hardware reference image
 * @param[in]   i_pChipHomer    models HOMER
 * @param[in]   i_phase         IPL or Runtime
 * @param[in]   i_imgType       image type to be built
 * @param[in]   i_chipFuncModel P10 chip configuration
 * @param[in]   i_ringData      buffers to extract and process rings.
 * @return      fapi2 return code.
 */
fapi2::ReturnCode buildPpmrImage( CONST_FAPI2_PROC& i_procTgt,
                                  void* const     i_pImageIn,
                                  Homerlayout_t   *i_pChipHomer,
                                  SysPhase_t      i_phase,
                                  ImageType_t     i_imgType,
                                  P10FuncModel    &i_chipFuncModel )
{
    FAPI_INF( ">> buildPpmrImage" );
    uint32_t rcTemp     =   IMG_BUILD_SUCCESS;
    fapi2::current_err  =   fapi2::FAPI2_RC_SUCCESS;
    //Let us find XIP Header for PGPE
    P9XipSection ppeSection;
    uint8_t* pPgpeImg   =   NULL;
    ImageBuildRecord    l_pgpeBuildRecord( (uint8_t *)(&i_pChipHomer->iv_occHostRegion), "PGPE" );

    if( i_imgType.pgpeImageBuild )
    {
        //Init PGPE region with zero
        memset( i_pChipHomer->iv_ppmrRegion.iv_ppmrHeader, 0x00, ONE_MB );

        rcTemp = p9_xip_get_section( i_pImageIn, P9_XIP_SECTION_HW_PGPE, &ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::PGPE_IMG_NOT_FOUND_IN_HW_IMG()
                     .set_XIP_FAILURE_CODE( rcTemp )
                     .set_EC_LEVEL( i_chipFuncModel.getChipLevel() ),
                     "Failed To Find PGPE Sub-Image In HW Image" );

        pPgpeImg = ppeSection.iv_offset + (uint8_t*) (i_pImageIn );
        FAPI_DBG("HW image PGPE Offset = 0x%08X", ppeSection.iv_offset);

        rcTemp = copySectionToHomer( i_pChipHomer->iv_ppmrRegion.iv_ppmrHeader,
                                     pPgpeImg,
                                     l_pgpeBuildRecord,
                                     P9_XIP_SECTION_PGPE_PPMR_HDR,
                                     i_chipFuncModel.getChipLevel(),
                                     ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::P10_XIP_SECTION_PGPE_PPMR()
                     .set_EC_LEVEL( i_chipFuncModel.getChipLevel() )
                     .set_MAX_ALLOWED_SIZE( rcTemp )
                     .set_ACTUAL_SIZE( ppeSection.iv_size ),
                     "Failed To Update PPMR Region Of HOMER" );

        l_pgpeBuildRecord.setSection( "PPMR Header", 0, PPMR_HEADER_SIZE );

        rcTemp = copySectionToHomer( i_pChipHomer->iv_ppmrRegion.iv_bootCopier,
                                     pPgpeImg,
                                     l_pgpeBuildRecord,
                                     P9_XIP_SECTION_PGPE_LVL1_BL,
                                     i_chipFuncModel.getChipLevel(),
                                     ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::P10_PGPE_BOOT_COPIER_BUILD_FAIL()
                     .set_EC_LEVEL( i_chipFuncModel.getChipLevel() )
                     .set_MAX_ALLOWED_SIZE( rcTemp )
                     .set_ACTUAL_SIZE( ppeSection.iv_size ),
                     "Failed To Update PGPE Boot Copier Region Of HOMER" );

        l_pgpeBuildRecord.setSection( "PGPE Boot Copier", PGPE_BOOT_COPIER_PPMR_OFFSET, ppeSection.iv_size );

        rcTemp = copySectionToHomer( i_pChipHomer->iv_ppmrRegion.iv_bootLoader,
                                     pPgpeImg,
                                     l_pgpeBuildRecord,
                                     P9_XIP_SECTION_PGPE_LVL2_BL,
                                     i_chipFuncModel.getChipLevel(),
                                     ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::P10_PGPE_BOOT_LOADER_BUILD_FAIL()
                     .set_EC_LEVEL( i_chipFuncModel.getChipLevel() )
                     .set_MAX_ALLOWED_SIZE( rcTemp )
                     .set_ACTUAL_SIZE( ppeSection.iv_size ),
                     "Failed To Update PGPE Boot Loader Region Of HOMER" );

        l_pgpeBuildRecord.setSection( "PGPE Boot Loader", PGPE_BOOT_LOADER_PPMR_OFFSET, ppeSection.iv_size );

        rcTemp = copySectionToHomer( i_pChipHomer->iv_ppmrRegion.iv_pgpeSramRegion,
                                     pPgpeImg,
                                     l_pgpeBuildRecord,
                                     P9_XIP_SECTION_PGPE_HCODE,
                                     i_chipFuncModel.getChipLevel(),
                                     ppeSection );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rcTemp ),
                     fapi2::P10_PGPE_HCODE_BUILD_FAIL()
                     .set_EC_LEVEL( i_chipFuncModel.getChipLevel() )
                     .set_MAX_ALLOWED_SIZE( rcTemp )
                     .set_ACTUAL_SIZE( ppeSection.iv_size ),
                     "Failed To Update PGPE Hcode Region Of HOMER" );

        l_pgpeBuildRecord.setSection( "PGPE Hcode", PGPE_IMAGE_PPMR_OFFSET, ppeSection.iv_size );

        FAPI_DBG( "PGPE Hcode       0x%08x",    ppeSection.iv_size );

        FAPI_TRY( buildParameterBlock( i_procTgt, i_pChipHomer, l_pgpeBuildRecord ),
                  "Failed To Build P-State Parameter Block" );

        l_pgpeBuildRecord.setSection( "PGPE Op Trace", PGPE_OP_TRACE_PPMR_OFFSET, PGPE_OPTRACE_LENGTH );

        FAPI_TRY( buildPpmrHeader( i_pChipHomer, l_pgpeBuildRecord ),
                  "Failed To Build PPMR Header" );

        FAPI_TRY( buildPgpeHeader( i_pChipHomer, l_pgpeBuildRecord ),
                  "Failed To Build PGPE Header" );

        FAPI_TRY( setIOAttr( i_procTgt, i_pChipHomer),
                  "Failed To set io attr" );
    }

fapi_try_exit:
    return fapi2::current_err;

    FAPI_INF( " << buildPpmrImage" );
}

//---------------------------------------------------------------------------

/**
 * @brief updates the IVPR attributes for PGPE, XGPE.
 * @param[in]   i_pChipHomer    points to start of HOMER
 * @param[in]   i_procTgt       target associated with P10 chip
 * @return      fapi2 return code
 */
fapi2::ReturnCode updateGpeAttributes( Homerlayout_t* i_pChipHomer,
                                       CONST_FAPI2_PROC& i_procTgt )
{
    FAPI_INF(">> updateGpeAttributes");

    PpmrHeader_t* pPpmrHdr = (PpmrHeader_t*) i_pChipHomer->iv_ppmrRegion.iv_ppmrHeader;
    XpmrHeader_t * l_pXpmrHdr   = (XpmrHeader_t *) i_pChipHomer->iv_xpmrRegion.iv_xpmrHeader;

    uint32_t attrVal = htobe32(pPpmrHdr->iv_bootCopierOffset);
    attrVal |= (0x80000000 | PPMR_HOMER_OFFSET);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PGPE_BOOT_COPIER_IVPR_OFFSET,
                           i_procTgt,
                           attrVal ),
             "Error from FAPI_ATTR_SET for attribute ATTR_PGPE_BOOT_COPIER_IVPR_OFFSET");

    FAPI_DBG("Set ATTR_PGPE_BOOT_COPIER_IVPR_OFFSET to 0x%08X", attrVal );

    attrVal = htobe32(l_pXpmrHdr->iv_bootCopierOffset);
    attrVal |= (0x80000000 | ONE_MB);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_XGPE_BOOT_COPIER_IVPR_OFFSET,
                            i_procTgt,
                            attrVal ),
              "Error from FAPI_ATTR_SET for attribute ATTR_XGPE_BOOT_COPIER_IVPR_OFFSET");

    FAPI_DBG("Set ATTR_XGPE_BOOT_COPIER_IVPR_OFFSET to 0x%08X", attrVal );

fapi_try_exit:
    FAPI_INF("<< updateGpeAttributes");
    return fapi2::current_err;
}

//-------------------------------------------------------------------------------------------------------


/**
 * @brief       verifies overall image size for XGPE, QME and PGPE
 * @param[in]   i_pChipHomer        models P10's HOMER
 * @param[in]   i_chipFuncModel P10 chip configuration
 * @return      fapi2 return code
 */
fapi2::ReturnCode verifySramImageSize( Homerlayout_t * i_pChipHomer, P10FuncModel & i_chipFuncModel )
{
    uint32_t l_imageSize    =   0;
    uint32_t l_tempSize     =   0;
    uint32_t l_bceBufSize   =   0;
    XpmrHeader_t * l_pXpmrHdr   =
            (XpmrHeader_t *) i_pChipHomer->iv_xpmrRegion.iv_xpmrHeader;
    CpmrHeader_t* pCpmrHdr      =
        (CpmrHeader_t*) & ( i_pChipHomer->iv_cpmrRegion.iv_selfRestoreRegion.iv_CPMR_SR.elements.iv_CPMRHeader);
    PpmrHeader_t * l_pPpmrHdr   =
            (PpmrHeader_t *) i_pChipHomer->iv_ppmrRegion.iv_ppmrHeader;
    QmeHeader_t* pImgHdr        =
            (QmeHeader_t*) & i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion[QME_INT_VECTOR_SIZE];

    l_imageSize     =   htobe32 (l_pXpmrHdr->iv_xgpeSramSize );

    FAPI_ASSERT( ( l_imageSize <= XGPE_REVISED_SRAM_SIZE ),
                 fapi2::XGPE_IMG_EXCEED_SRAM_SIZE()
                 .set_BAD_IMG_SIZE( l_imageSize )
                 .set_MAX_XGPE_IMG_SIZE_ALLOWED( XGPE_REVISED_SRAM_SIZE )
                 .set_EC_LEVEL( i_chipFuncModel.getChipLevel() ),
                 "XGPE Image Size Check Failed Actual 0x%08x Max Allowed 0x%08x",
                 l_imageSize, XGPE_REVISED_SRAM_SIZE );

    FAPI_INF( "----- XGPE Image Check Success -----" );

    if ( htobe64( pImgHdr->g_qme_magic_number ) == QME_SRAM_MAGIC_WORD )
    {
        l_imageSize =   htobe32( pCpmrHdr->iv_qmeImgLength ) +
                        htobe32( pCpmrHdr->iv_commonRingLength ) +
                        htobe32( pCpmrHdr->iv_localPstateLength ) +
                        htobe32( pCpmrHdr->iv_specRingLength ) +
                        htobe32( pImgHdr->g_qme_scom_length );

        FAPI_ASSERT( ( l_imageSize <= QME_SRAM_SIZE ),
                     fapi2::QME_IMG_EXCEED_SRAM_SIZE()
                     .set_BAD_IMG_SIZE( l_imageSize )
                     .set_QME_HCODE_SIZE( htobe32( pCpmrHdr->iv_qmeImgLength ) )
                     .set_CMN_RING_SIZE( htobe32( pCpmrHdr->iv_commonRingLength ) )
                     .set_INST_RING_SIZE( htobe32( pCpmrHdr->iv_specRingLength) )
                     .set_MAX_QME_IMG_SIZE_ALLOWED( QME_SRAM_SIZE )
                     .set_EC_LEVEL( i_chipFuncModel.getChipLevel() ),
                     "QME Image Size Check Failed Actual 0x%08x Max Allowed 0x%08x",
                     l_imageSize, QME_SRAM_SIZE );

    }
    else
    {
        l_bceBufSize   =  QME_SRAM_SIZE - htobe32( pCpmrHdr->iv_qmeImgLength );

        l_tempSize     =  htobe32( pCpmrHdr->iv_commonRingLength );

        if( l_tempSize < htobe32( pCpmrHdr->iv_specRingLength) )
        {
            l_tempSize = htobe32( pCpmrHdr->iv_specRingLength);
        }

        if( l_tempSize <  ( htobe32( pImgHdr->g_qme_coreL2ScomLength ) >> 2 ) )
        {
            l_tempSize = ( htobe32( pImgHdr->g_qme_coreL2ScomLength ) >> 2 );
        }

        if( l_tempSize < ( htobe32( pImgHdr->g_qme_L3ScomLength ) >> 2 ) )
        {
            l_tempSize = ( htobe32( pImgHdr->g_qme_L3ScomLength ) >> 2 );
        }

        FAPI_INF( "QME Hcode Size 0x%08x, QME SRAM Buffer Size 0x%08x Max of Rings and Scom Restore 0x%08x ",
                    htobe32( pCpmrHdr->iv_qmeImgLength ), l_bceBufSize, l_tempSize );

        FAPI_ASSERT( ( l_bceBufSize >= l_tempSize ),
                     fapi2::BCE_BUF_SMALLER_FOR_NON_HCODE_SECTION()
                     .set_BCE_BUF_SIZE( l_bceBufSize )
                     .set_QME_HCODE_SIZE( htobe32( pCpmrHdr->iv_qmeImgLength ) )
                     .set_CMN_RING_SIZE( htobe32( pCpmrHdr->iv_commonRingLength ) )
                     .set_INST_RING_SIZE( htobe32( pCpmrHdr->iv_specRingLength ) )
                     .set_SCOM_RESTORE_SIZE( htobe32( pImgHdr->g_qme_L3ScomLength ) + htobe32( pImgHdr->g_qme_coreL2ScomLength ) ),
                     "BCE Buffer cannot contain all non-hcode sections of QME image BCE Buf 0x%08x Max Non Hcode Sectn 0x%08x",
                     l_bceBufSize, l_tempSize );
    }

    FAPI_INF( "----- QME Image Check Success  -----" );

    l_imageSize     =   htobe32( l_pPpmrHdr->iv_sramSize );

    FAPI_ASSERT( ( l_imageSize +  PGPE_OCC_SHARED_SRAM_SIZE + PGPE_SRAM_BOOT_REGION  <= OCC_SRAM_PGPE_REVISED_REGION_SIZE ),
                 fapi2::PGPE_IMG_EXCEED_SRAM_SIZE()
                 .set_BAD_IMG_SIZE( l_imageSize )
                 .set_MAX_PGPE_IMG_SIZE_ALLOWED( OCC_SRAM_PGPE_REVISED_REGION_SIZE )
                 .set_EC_LEVEL( i_chipFuncModel.getChipLevel() ),
                 "PGPE Image Size Check Failed Actual 0x%08x Max Allowed 0x%08x",
                 l_imageSize, OCC_SRAM_PGPE_REVISED_REGION_SIZE );

    FAPI_INF( "----- PGPE Image Check Success -----" );

fapi_try_exit:
    return fapi2::current_err;
}

//-------------------------------------------------------------------------------------------------------

fapi2::ReturnCode traceCommonRingRs4Size( Homerlayout_t* i_pChipHomer, Rs4Stat & i_rs4Stat )
{
    CpmrHeader_t* pCpmrHdr      =
        (CpmrHeader_t*) & ( i_pChipHomer->iv_cpmrRegion.iv_selfRestoreRegion.iv_CPMR_SR.elements.iv_CPMRHeader);
    std::map < RingId_t , uint32_t> l_ringSizeMap;
    uint32_t l_cmnRingOffset    =   htobe32( pCpmrHdr->iv_commonRingOffset );
    uint8_t  * l_pRingSectn     =   (uint8_t *) i_pChipHomer + CPMR_HOMER_OFFSET + l_cmnRingOffset;
    uint16_t  * l_pSectnTor     =   (uint16_t *)( l_pRingSectn + sizeof( TorHeader_t ) );
    uint16_t * l_pRingTor       =   (uint16_t *)( l_pRingSectn + htobe16( *l_pSectnTor ) );
    uint8_t  * l_pRing          =   NULL;

    FAPI_DBG( "CPMR Ring Offset 0x%08x", (uint8_t *) l_pRingTor - (uint8_t *) i_pChipHomer );

    for( uint8_t ring = 0; ring < 25/*EQ::g_chipletData.numCommonRings */; ring++ , l_pRingTor++ )
    {
        if( !*l_pRingTor )
        {
            FAPI_DBG( "Ring TOR Slot is Zero. Skipping" );

            continue;
        }

        FAPI_DBG( "Cmn Ring Found!. TOR Offset 0x%08x", htobe16( *l_pRingTor ) );

        l_pRing = l_pRingSectn + htobe16( *l_pRingTor );
        CompressedScanData * l_pHdr = ( CompressedScanData * ) l_pRing;

        if( htobe16( l_pHdr->iv_magic ) == 0x5253 )
        {
            l_ringSizeMap[ htobe16(l_pHdr->iv_ringId) ]    =   htobe16( l_pHdr->iv_size );
        }
    }

    uint32_t l_avgSize  = 0;
    uint32_t l_maxSize  = 0;
    uint16_t l_maxSizeRingId = 0;

    for( auto ring_size = l_ringSizeMap.begin(); ring_size != l_ringSizeMap.end();
         ring_size++ )
    {
        l_avgSize += ring_size->second;

        if( l_maxSize < ring_size->second )
        {
            l_maxSize = ring_size->second;
            l_maxSizeRingId = ring_size->first;
        }

    }

    i_rs4Stat.iv_cmnRingMaxSize  = l_maxSize;

    if( l_ringSizeMap.size() > 0 )
    {
        i_rs4Stat.iv_cmnRingAvgSize = l_avgSize / l_ringSizeMap.size();
    }

    i_rs4Stat.iv_maxSizeCmnRing = l_maxSizeRingId;

    return fapi2::FAPI2_RC_SUCCESS;
}

//-------------------------------------------------------------------------------------------------------

fapi2::ReturnCode traceRs4InstRingSize( Homerlayout_t * i_pChipHomer, Rs4Stat & i_rs4Stat )
{
    FAPI_INF( ">> traceRs4InstRingSize" );
    CpmrHeader_t* pCpmrHdr      =
    (CpmrHeader_t*) & ( i_pChipHomer->iv_cpmrRegion.iv_selfRestoreRegion.iv_CPMR_SR.elements.iv_CPMRHeader);
    std::map < RingId_t , uint32_t> l_ringSizeMap;
    uint32_t l_instRingOffset   =   htobe32( pCpmrHdr->iv_specRingOffset );
    uint8_t  * l_pRingInst0     =   (uint8_t *) i_pChipHomer + CPMR_HOMER_OFFSET + l_instRingOffset;
    uint16_t * l_pSectnTor      =   NULL;
    uint16_t * l_pRingTor       =   NULL;
    uint8_t  * l_pRing          =   NULL;
    uint32_t l_avgSize    =   0;
    uint32_t l_maxSize    =   0;
    uint16_t l_maxSizeRingId   =   0;
    uint16_t l_numInstRing      =   0;

    for( uint8_t l_eq = 0; l_eq < MAX_QUADS_PER_CHIP; l_eq++ )
    {
        l_ringSizeMap.empty();
        uint8_t  * l_pRingSectn = l_pRingInst0 + ( htobe32( pCpmrHdr->iv_specRingLength ) * l_eq );
        TorHeader_t * l_pTorHdr = ( TorHeader_t * )l_pRingSectn;

        if( l_pTorHdr->magic != htobe32( TOR_MAGIC_QME ) )
        {
            continue;
        }

        l_pSectnTor = (uint16_t *)( l_pRingSectn + sizeof( TorHeader_t ) + INST_RING_OFFSET );
        l_pRingTor  = (uint16_t *)( l_pRingSectn + htobe16( *l_pSectnTor ) );

        FAPI_DBG( "CPMR Ring Offset 0x%08x",
                    (uint8_t *) l_pRingTor - (uint8_t *) i_pChipHomer );

        for( uint8_t ring = 0; ring < 8; ring++ , l_pRingTor++ )
        {
            if( !*l_pRingTor )
            {
              FAPI_DBG( "TOR Index is Zero. Skipping" );

              continue;
            }

            FAPI_DBG( "Instance Ring Found!. TOR Offset 0x%08x", htobe16( *l_pRingTor ) );

            l_pRing = l_pRingSectn + htobe16( *l_pRingTor );
            CompressedScanData * l_pHdr = ( CompressedScanData * ) l_pRing;

            if( htobe16( l_pHdr->iv_magic ) == 0x5253 )
            {
                l_ringSizeMap[ htobe16( l_pHdr->iv_ringId ) ] = htobe16( l_pHdr->iv_size );
            }
        }

        for( auto ring_size = l_ringSizeMap.begin(); ring_size != l_ringSizeMap.end();
             ring_size++ )
        {
            l_avgSize += ring_size->second;

            if( l_maxSize < ring_size->second )
            {
                l_maxSize = ring_size->second;
                l_maxSizeRingId = ring_size->first;
            }
        }

        l_numInstRing += l_ringSizeMap.size();
    }

    i_rs4Stat.iv_instRingMaxSize = l_maxSize;

    if( l_numInstRing > 0 )
    {
        i_rs4Stat.iv_instRingAvgSize = l_avgSize / l_numInstRing;
    }

    i_rs4Stat.iv_maxSizeInstRing = l_maxSizeRingId;

    FAPI_INF( "<< traceRs4InstRingSize" );
    return fapi2::FAPI2_RC_SUCCESS;
}

//-------------------------------------------------------------------------------------------------------

fapi2::ReturnCode traceRs4OverrideSize( Homerlayout_t * i_pChipHomer, Rs4Stat & i_rs4Stat )
{
    FAPI_INF( ">> traceRs4OverrideSize" );
    QmeHeader_t* pImgHdr        =
            (QmeHeader_t*) & i_pChipHomer->iv_cpmrRegion.iv_qmeSramRegion[QME_INT_VECTOR_SIZE];
    std::map < RingId_t , uint32_t> l_ringSizeMap;
    uint32_t l_ovrdOffset    =   htobe32( pImgHdr->g_qme_cmn_ring_ovrd_offset );
    uint8_t  * l_pRingSectn  =   (uint8_t *) i_pChipHomer + CPMR_HOMER_OFFSET + QME_IMAGE_CPMR_OFFSET + l_ovrdOffset;
    uint16_t * l_pRingTor    =   (uint16_t *)( l_pRingSectn + sizeof( TorHeader_t ) + OVRD_RING_OFFSET  );
    uint8_t  * l_pRing       =   NULL;
    uint32_t l_avgSize       =   0;
    uint32_t l_maxSize       =   0;
    uint16_t l_maxSizeRingId =   0;

    if( !l_ovrdOffset )
    {
        goto fapi_try_exit;
    }

    l_pRingTor  = (uint16_t *) ( l_pRingSectn + htobe16( *l_pRingTor ) );

    FAPI_DBG( "CPMR Ring Offset 0x%08x", (uint8_t *) l_pRingTor - (uint8_t *) i_pChipHomer );

    for( uint8_t ring = 0; ring < 25; ring++ , l_pRingTor++ )
    {
        if( !*l_pRingTor )
        {
            FAPI_DBG( "TOR Index is Zero. Skipping" );

            continue;
        }

        FAPI_DBG( "Ovrd Ring Found!. TOR Offset 0x%08x", htobe16( *l_pRingTor ) );

        l_pRing = l_pRingSectn + htobe16( *l_pRingTor );
        CompressedScanData * l_pHdr = ( CompressedScanData * ) l_pRing;

        if( htobe16( l_pHdr->iv_magic ) == 0x5253 )
        {
            FAPI_INF( "Ovrd Magic Word" );
            l_ringSizeMap[ htobe16( l_pHdr->iv_ringId ) ]    =   htobe16( l_pHdr->iv_size );
        }
    }

    for( auto ring_size = l_ringSizeMap.begin(); ring_size != l_ringSizeMap.end();
         ring_size++ )
    {
        l_avgSize += ring_size->second;

        if( l_maxSize < ring_size->second )
        {
            l_maxSize = ring_size->second;
            l_maxSizeRingId = ring_size->first;
        }
    }

    i_rs4Stat.iv_ovrdRingMaxSize  =  l_maxSize;

    if( l_ringSizeMap.size() > 0 )
    {
        i_rs4Stat.iv_ovrdRingAvgSize  =  l_avgSize / l_ringSizeMap.size();
    }

    i_rs4Stat.iv_maxSizeOvrdRing  =  l_maxSizeRingId;

fapi_try_exit:
    FAPI_INF( "<< traceRs4OverrideSize" );

    return fapi2::FAPI2_RC_SUCCESS;
}

//-------------------------------------------------------------------------------------------------------

fapi2::ReturnCode traceRs4ContainerSize(  void* const i_pHomerImage )
{
    FAPI_INF( ">> traceRs4ContainerSize" );

#ifdef P10_RS4_CONTANER_SIZE_TRACING

    Rs4Stat l_rs4Stat;
    memset( &l_rs4Stat, 0x00, sizeof( Rs4Stat ));
    Homerlayout_t* pChipHomer = ( Homerlayout_t*) i_pHomerImage;

    //Analyzing the common ring sizes
    FAPI_TRY( traceCommonRingRs4Size( pChipHomer, l_rs4Stat ) );

    //Analyzing the instance specific ring sizes
    FAPI_TRY( traceRs4InstRingSize( pChipHomer, l_rs4Stat ) );

    //Analyzing the Override ring sizes
    FAPI_TRY( traceRs4OverrideSize( pChipHomer, l_rs4Stat ) );

    FAPI_INF( "+++++++++++++++++++++++++ Scan Ring Stat +++++++++++++++++++++++++ " );
    FAPI_INF( "Common Ring Rs4 Max Size 0x%08x ( %08d )     Rind Id     0x%04x",
                l_rs4Stat.iv_cmnRingMaxSize, l_rs4Stat.iv_cmnRingMaxSize,
                l_rs4Stat.iv_maxSizeCmnRing );
    FAPI_INF( "Inst Ring Rs4 Max Size   0x%08x ( %08d )     Ring Id     0x%04x",
                l_rs4Stat.iv_instRingMaxSize, l_rs4Stat.iv_instRingMaxSize,
                l_rs4Stat.iv_maxSizeInstRing );
    FAPI_INF( "Ovrd Ring Rs4 Max Size   0x%08x ( %08d )     Ring Id     0x%04x",
                l_rs4Stat.iv_ovrdRingMaxSize, l_rs4Stat.iv_ovrdRingMaxSize,
                l_rs4Stat.iv_maxSizeOvrdRing );
    FAPI_INF( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " );
    FAPI_INF( "Common Ring Rs4 Avg Size 0x%08x ( %08d )",
                l_rs4Stat.iv_cmnRingAvgSize, l_rs4Stat.iv_cmnRingAvgSize );
    FAPI_INF( "Inst Ring Rs4 Avg Size   0x%08x ( %08d )",
               l_rs4Stat.iv_instRingAvgSize, l_rs4Stat.iv_instRingAvgSize );
    FAPI_INF( "Ovrd Ring Rs4 Avg Size   0x%08x ( %08d )",
               l_rs4Stat.iv_ovrdRingAvgSize, l_rs4Stat.iv_ovrdRingAvgSize );

    FAPI_INF( "+++++++++++++++++++++++++ Scan Ring Stat Ends ++++++++++++++++++++ " );

fapi_try_exit:
#endif

    FAPI_INF( "<< traceRs4ContainerSize" );
     return fapi2::current_err;
}

fapi2::ReturnCode verifyScomRestore( CONST_FAPI2_PROC& i_procTgt, void* i_pHomerImage )
{
    #ifdef __VERIFY_SCOM_RESTORE
    stopImageSection::StopReturnCode_t  l_retCode;
    uint8_t l_corePos = 0;

    uint32_t l2_fir_mask[MAX_CORES_PER_CHIP] = { 0x20028003, 0x20024003, 0x20022003, 0x20021003,
                                            0x21028003, 0x21024003, 0x21022003, 0x21021003,
                                            0x22028003, 0x22024003, 0x22022003, 0x22021003,
                                            0x23028003, 0x23024003, 0x23022003, 0x23021003,
                                            0x24028003, 0x24024003, 0x24022003, 0x24021003,
                                            0x25028003, 0x25024003, 0x25022003, 0x25021003,
                                            0x26028003, 0x26024003, 0x26022003, 0x26021003,
                                            0x27028003, 0x27024003, 0x27022003, 0x27021003 };

    uint32_t l3_fir_mask[MAX_CORES_PER_CHIP] = { 0x20018603, 0x20014603, 0x20012603, 0x20011603,
                                            0x21018603, 0x21014603, 0x21012603, 0x21011603,
                                            0x22018603, 0x22014603, 0x22012603, 0x22011603,
                                            0x23018603, 0x23014603, 0x23012603, 0x23011603,
                                            0x24018603, 0x24014603, 0x24012603, 0x24011603,
                                            0x25018603, 0x25014603, 0x25012603, 0x25011603,
                                            0x26018603, 0x26014603, 0x26012603, 0x26011603,
                                            0x27018603, 0x27014603, 0x27012603, 0x27011603  };

    uint32_t core_fir_mask[MAX_CORES_PER_CHIP] = { 0x20028443, 0x20024443, 0x20022443, 0x20021443,
                                            0x21028443, 0x21024443, 0x21022443, 0x21021443,
                                            0x22028443, 0x22024443, 0x22022443, 0x22021443,
                                            0x23028443, 0x23024443, 0x23022443, 0x23021443,
                                            0x24028443, 0x24024443, 0x24022443, 0x24021443,
                                            0x25028443, 0x25024443, 0x25022443, 0x25021443,
                                            0x26028443, 0x26024443, 0x26022443, 0x26021443,
                                            0x27028443, 0x27024443, 0x27022443, 0x27021443
                                            };
    auto coreList = i_procTgt.getChildren< fapi2::TARGET_TYPE_CORE >();

    for( auto core : coreList )
    {
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, core, l_corePos ));
        l_retCode  = stopImageSection::proc_stop_save_scom( i_pHomerImage,
                                    (l2_fir_mask[l_corePos]),
                                                                0xaabbccddeeffaabbull,
                                    stopImageSection::PROC_STOP_SCOM_APPEND,
                                    stopImageSection::PROC_STOP_SECTION_CORE );

        if( l_retCode )
        {
            FAPI_ERR( "proc_stop_save_scom Sectn Core-L2 Err 0x%08x", (uint32_t) l_retCode );
        }

        l_retCode  = stopImageSection::proc_stop_save_scom( i_pHomerImage,
                                    (core_fir_mask[l_corePos]),
                                                                0xaabbccddeeffaabbull,
                                    stopImageSection::PROC_STOP_SCOM_APPEND,
                                    stopImageSection::PROC_STOP_SECTION_CORE );

        if( l_retCode )
        {
            FAPI_ERR( "proc_stop_save_scom Sectn Core Err 0x%08x", (uint32_t) l_retCode );
        }

        l_retCode  = stopImageSection::proc_stop_save_scom( i_pHomerImage,
                                    (l3_fir_mask[l_corePos]),
                                    0xaabbccddeeffaabbull,
                                                                stopImageSection::PROC_STOP_SCOM_APPEND,
                                    stopImageSection::PROC_STOP_SECTION_L3 );

        if( l_retCode )
        {
            FAPI_ERR( "proc_stop_save_scom Sectn L3 Err 0x%08x", (uint32_t) l_retCode );
        }
    }

    fapi_try_exit:
    #endif
        return fapi2::current_err;
}

//-------------------------------------------------------------------------------------------------------

fapi2::ReturnCode p10_hcode_image_build(    CONST_FAPI2_PROC& i_procTgt,
                                            void* const     i_pImageIn,
                                            void*           i_pHomerImage,
                                            void* const     i_pRingOverride,
                                            SysPhase_t      i_phase,
                                            ImageType_t     i_imgType,
                                            void* const     i_pBuf1,
                                            const uint32_t  i_sizeBuf1,
                                            void* const     i_pBuf2,
                                            const uint32_t  i_sizeBuf2,
                                            void* const     i_pBuf3,
                                            const uint32_t  i_sizeBuf3,
                                            void* const     i_pBuf4,
                                            const uint32_t  i_sizeBuf4 )
{
    FAPI_IMP(">> p10_hcode_image_build ");
    P10FuncModel l_chipFuncModel( i_procTgt );
    Homerlayout_t* pChipHomer = ( Homerlayout_t*) i_pHomerImage;

    RingBufData l_ringData( i_pBuf1,
                            i_sizeBuf1,
                            i_pBuf2,
                            i_sizeBuf2,
                            i_pBuf3,
                            i_sizeBuf3,
                            i_pBuf4,
                            i_sizeBuf4,
                            i_pRingOverride );

    FAPI_TRY( validateInputArguments( i_pImageIn,
                                      i_pHomerImage,
                                      i_phase,
                                      i_imgType,
                                      i_pBuf1,
                                      i_sizeBuf1,
                                      i_pBuf2,
                                      i_sizeBuf2,
                                      i_pBuf3,
                                      i_sizeBuf3,
                                      i_pBuf4,
                                      i_sizeBuf4 ),
              "Invalid arguments, escaping hcode image build" );

    if( PHASE_REBUILD == i_phase )
    {
        //During Rebuild Phase keep following untouched
        //1. SPR Restore entries in Self Restore Region
        //2. SCOM restore entries in CPMR region
        FAPI_INF("HOMER Rebuild Phase");
        i_imgType.configRebuildPhase();
    }
    else
    {
        i_imgType.configBuildPhase();
    }

    FAPI_TRY( buildXpmrImage(  i_procTgt, i_pImageIn, pChipHomer, i_phase,
                               i_imgType, l_chipFuncModel ),
              "Failed To Build XPMR Region of HOMER " );


    FAPI_TRY( buildCpmrImage( i_procTgt, i_pImageIn, pChipHomer, i_phase,
                              i_imgType, l_chipFuncModel, l_ringData ),
              "Failed To Build CPMR Region of HOMER " );

    FAPI_TRY( buildPpmrImage( i_procTgt, i_pImageIn, pChipHomer, i_phase,
                              i_imgType, l_chipFuncModel ),
              "Failed To Build PPMR Region of HOMER" );
    FAPI_TRY( populateMagicWord( pChipHomer ),
              "Failed To Copy Magic Words" );

    //Update the attributes storing PGPE and XGPE's boot copier offset.
    FAPI_TRY( updateGpeAttributes( pChipHomer, i_procTgt ),
              "Failed To Update XGPE/PGPE IVPR Attributes" );

    FAPI_TRY( verifySramImageSize( pChipHomer, l_chipFuncModel ) ,
              "Image Size Check Failed " );

    FAPI_TRY( traceRs4ContainerSize( pChipHomer ),
        "Failed To Trace RS4 Size" );

    FAPI_TRY( verifyScomRestore( i_procTgt, i_pHomerImage ),
              "Failed To Create SCOM Restore Entry" );

fapi_try_exit:
    FAPI_IMP("<< p10_hcode_image_build" );
    return fapi2::current_err;
}

}//namespace hcodeImageBuild
}// extern "C"

// *INDENT-ON*
