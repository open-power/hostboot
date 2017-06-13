/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_hcode_image_build.C $ */
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
/// @file   p9_hcode_image_build.C
/// @brief  Implements HWP that builds the Hcode image in HOMER.
///
// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
// *HWP Team:           PM
// *HWP Level:          2
// *HWP Consumed by:    Hostboot: Phyp

// *INDENT-OFF*

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <map>
#include <p9_hcode_image_build.H>
#include "p9_xip_image.h"
#include "p9_hcode_image_defines.H"
#include "p9_pm_hcd_flags.h"
#include "p9_stop_util.H"
#include "p9_scan_ring_util.H"
#include "p9_tor.H"
#include "p9_quad_scom_addresses.H"
#include "p9_stop_api.H"
#include <p9_infrastruct_help.H>
#include <p9_xip_customize.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>
#include <p9_fbc_utils.H>
#include "p9_pstate_parameter_block.H"

#ifdef __CRONUS_VER
    #include <string>
#endif
using namespace stopImageSection;

extern "C"
{
/**
 * @brief   aligns DATA_SIZE  to 8B.
 * @param   TEMP_LEN    temp storage
 * @param   DATA_SIZE   size to be aligned. Aligned size is saved in same variable.
 */
#define ALIGN_DWORD(TEMP_LEN, DATA_SIZE)                \
    {TEMP_LEN = (DATA_SIZE % RING_ALIGN_BOUNDARY);      \
        if( TEMP_LEN )                                  \
        {                                               \
            (DATA_SIZE = DATA_SIZE + (RING_ALIGN_BOUNDARY - TEMP_LEN));\
        }                                               \
    }

/**
 * @brief aligns start of scan ring to 8B boundary.
 * @param   RING_REGION_BASE start location of scan ring region in HOMER.
 * @param   RING_LOC         start of scan ring.
 */
#define ALIGN_RING_LOC(RING_REGION_BASE, RING_LOC)  \
    {                                                   \
        uint8_t tempDiff =                              \
                (uint8_t *) RING_LOC - (uint8_t *) RING_REGION_BASE; \
        tempDiff = tempDiff %8;                                      \
        if( ( tempDiff > 0 ) && ( tempDiff < 8 ))                    \
        {   RING_LOC = RING_LOC + 8 - tempDiff;                      \
        }                                                            \
    }

/**
 * @brief       round of ring size to multiple of 32B
 */
#define ROUND_OFF_32B( ROUND_SIZE)                          \
    {                                                       \
        uint32_t tempSize = ROUND_SIZE;                     \
        if( tempSize )                                      \
        {                                                   \
            ROUND_SIZE = (( ( tempSize + 31 )/32 ) * 32 );  \
        }                                                   \
    }
namespace p9_hcodeImageBuild
{

/**
 * @brief   some misc local constants
 */
enum
{
    ENABLE_ALL_CORE             =   0x000FFFF,
    RISK_LEVEL                  =   0x01,
    QUAD_COMMON_RING_INDEX_SIZE =   sizeof(QuadCmnRingsList_t),
    QUAD_SPEC_RING_INDEX_SIZE   =   ((sizeof(QuadSpecRingsList_t)) / sizeof(uint16_t)),
    QUAD_SPEC_RING_INDEX_LEN    =   (QUAD_SPEC_RING_INDEX_SIZE * 2 * MAX_QUADS_PER_CHIP),
    CORE_COMMON_RING_INDEX_SIZE =   sizeof(CoreCmnRingsList_t),
    CORE_SPEC_RING_INDEX_SIZE   =   sizeof(CoreSpecRingList_t),
    RING_START_TO_RS4_OFFSET    =   8,
    TOR_VER_ONE                 =   1,
    TOR_VER_TWO                 =   2,
    QUAD_BIT_POS                =   24,
    ODD_EVEN_EX_POS             =   0x00000400,
    SECTN_NAME_MAX_LEN          =   20,
    SGPE_AUX_FUNC_INERVAL_SHIFT =   24,
    CME_SRAM_IMAGE              =   P9_XIP_SECTIONS + 1,
    SGPE_SRAM_IMAGE             =   P9_XIP_SECTIONS + 2,
    PGPE_SRAM_IMAGE             =   P9_XIP_SECTIONS + 3,
    EQ_INEX_INDEX               =   3, //Using position of erstwhile eq_mode
    EQ_INEX_BUCKET_1            =   0,
    EQ_INEX_BUCKET_2            =   1,
    EQ_INEX_BUCKET_3            =   2,
    EQ_INEX_BUCKET_4            =   3,
    L3_EPS_DIVIDER              =   1,
    L2_EPS_DIVIDER              =   1,
    MAX_HOMER_HEADER            =   6,
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

    RingBufData( void* i_pRingBuf1, const uint32_t i_ringSize,
                 void* i_pWorkBuf1, const uint32_t i_sizeWorkBuf1,
                 void* i_pWorkBuf2, const uint32_t i_sizeWorkBuf2 ) :
        iv_pRingBuffer( i_pRingBuf1),
        iv_ringBufSize(i_ringSize),
        iv_pWorkBuf1( i_pWorkBuf1 ),
        iv_sizeWorkBuf1( i_sizeWorkBuf1 ),
        iv_pWorkBuf2( i_pWorkBuf2 ),
        iv_sizeWorkBuf2( i_sizeWorkBuf2 )

    {}

    RingBufData():
        iv_pRingBuffer( NULL ),
        iv_ringBufSize( 0 ),
        iv_pWorkBuf1( NULL ),
        iv_sizeWorkBuf1( 0 ),
        iv_pWorkBuf2( NULL ),
        iv_sizeWorkBuf2( 0 )
    { }
};

/**
 * @brief   models a section in HOMER.
 */
struct ImgSec
{
    PlatId iv_plat;
    uint8_t iv_secId;
    char iv_secName[SECTN_NAME_MAX_LEN];
    ImgSec( PlatId i_plat, uint8_t i_secId, char* i_secName ):
        iv_plat( i_plat ),
        iv_secId( i_secId )
    {
        memset( iv_secName, 0x00, SECTN_NAME_MAX_LEN );
        uint8_t secLength = strlen(i_secName);
        secLength = ( secLength > SECTN_NAME_MAX_LEN ) ? SECTN_NAME_MAX_LEN : secLength;
        memcpy( iv_secName, i_secName, secLength );
    }

    ImgSec( PlatId i_plat, uint8_t i_secId ):
        iv_plat( i_plat ),
        iv_secId( i_secId )
    {
        memset( iv_secName, 0x00, SECTN_NAME_MAX_LEN );
    }

    ImgSec(): iv_plat (PLAT_SELF), iv_secId (0 )
    {
        memcpy( iv_secName, "Self Restore", 12 );
    }
};

/**
 * @brief operator < overloading for ImgSec.
 */
bool operator < ( const ImgSec& i_lhs, const ImgSec& i_rhs )
{
    if( i_lhs.iv_plat == i_rhs.iv_plat )
    {
        return i_lhs.iv_secId < i_rhs.iv_secId;
    }
    else
    {
        return i_lhs.iv_plat < i_rhs.iv_plat;
    }
}

/**
 * @brief operator == overloading for ImgSec.
 */
bool operator == ( const ImgSec& i_lhs, const ImgSec& i_rhs )
{
    bool equal = false;

    if( i_lhs.iv_plat == i_rhs.iv_plat )
    {
        if( i_lhs.iv_secId == i_rhs.iv_secId )
        {
            equal = true;
        }
    }

    return equal;
}

/**
 * @brief compares size of a given image's section with maximum allowed size.
 */
class ImgSizeBank
{
    public:
        ImgSizeBank();
        ~ImgSizeBank() {};
        uint32_t isSizeGood( PlatId i_plat, uint8_t i_sec, uint32_t i_size,
                             char* i_secName, uint8_t i_bufLength );
        uint32_t getImgSectn( PlatId i_plat, uint8_t i_sec, uint32_t& o_secSize,
                              char* i_secName, uint8_t i_bufLength );

    private:
        std::map< ImgSec, uint32_t> iv_secSize;

};

/**
 * @brief   constructor
 */
ImgSizeBank::ImgSizeBank()
{
    //A given section can be uniquely identified by platform to which it belongs, section id
    //within the platform image. Name too has been added to assist debug in case of a failure.
    //To identify a given image section say a bootloader, we are using it's id as defined in
    //p9_xip_images.h. Inorder to identify a full SRAM Image, we introduced a new ID
    //xxx_SRAM_IMAGE.

    iv_secSize[ImgSec(PLAT_SELF, P9_XIP_SECTION_RESTORE_SELF, (char*)"Self Restore")]      =   SELF_RESTORE_CODE_SIZE;
    iv_secSize[ImgSec(PLAT_SELF, P9_XIP_SECTION_RESTORE_CPMR, (char*)"CPMR Header")]       =   CPMR_HEADER_SIZE;
    iv_secSize[ImgSec(PLAT_SGPE, P9_XIP_SECTION_SGPE_QPMR,    (char*)"QPMR Header")]       =   HALF_KB;
    iv_secSize[ImgSec(PLAT_SGPE, P9_XIP_SECTION_SGPE_LVL1_BL, (char*)"SGPE Boot Copier")]  =   SGPE_BOOT_COPIER_SIZE;
    iv_secSize[ImgSec(PLAT_SGPE, P9_XIP_SECTION_SGPE_LVL2_BL, (char*)"SGPE Boot Loader")]  =   SGPE_BOOT_LOADER_SIZE;
    iv_secSize[ImgSec(PLAT_SGPE, P9_XIP_SECTION_SGPE_HCODE,   (char*)"SGPE Hcode")]        =   SGPE_IMAGE_SIZE;
    iv_secSize[ImgSec(PLAT_SGPE, SGPE_SRAM_IMAGE,             (char*)"SGPE SRAM Image")]   =   SGPE_IMAGE_SIZE;

    iv_secSize[ImgSec(PLAT_CME,  P9_XIP_SECTION_CME_HCODE,     (char*)"CME Hcode")]        =   CME_SRAM_SIZE;
    iv_secSize[ImgSec(PLAT_CME,  CME_SRAM_IMAGE,               (char*)"CME SRAM Image")]   =   CME_SRAM_SIZE;

    iv_secSize[ImgSec(PLAT_PGPE, P9_XIP_SECTION_PGPE_PPMR,    (char*)"PPMR Header")]       =   HALF_KB;
    iv_secSize[ImgSec(PLAT_PGPE, P9_XIP_SECTION_PGPE_LVL1_BL, (char*)"PGPE Boot Copier")]  =   PGPE_BOOT_COPIER_SIZE;
    iv_secSize[ImgSec(PLAT_PGPE, P9_XIP_SECTION_PGPE_LVL2_BL, (char*)"PGPE Boot Loader")]  =   PGPE_BOOT_LOADER_SIZE;;
    iv_secSize[ImgSec(PLAT_PGPE, P9_XIP_SECTION_PGPE_HCODE,   (char*)"PGPE Hcode")]        =   PGPE_IMAGE_SIZE;
    iv_secSize[ImgSec(PLAT_PGPE, PGPE_SRAM_IMAGE,             (char*)"PGPE SRAM Image")]   =   PGPE_IMAGE_SIZE;
}

/**
 * @brief   verifies actual section size against max size allowed.
 * @param   i_plat  platform associated with image section.
 * @param   i_sec   image section.
 * @param   i_size  actual image section size.
 * @param   i_pSecName  points to a buffer with section name.
 * @param   i_bufLength length of the buffer.
 * @return  zero if size within limit else max size allowed.
 */
uint32_t ImgSizeBank::isSizeGood( PlatId i_plat, uint8_t i_sec,
                                  uint32_t i_size, char* i_pSecName,
                                  uint8_t i_bufLength )
{
    uint32_t rc = 0;
    uint32_t tempSize = 0;
    ImgSec key( i_plat, i_sec );
    std::map< ImgSec, uint32_t>::iterator it;

    do
    {
        rc = getImgSectn( i_plat, i_sec, tempSize, i_pSecName, i_bufLength );
        FAPI_DBG(" Sec: %s Max Size 0x%08X", i_pSecName ? i_pSecName : "--", tempSize );

        if( rc )
        {
            FAPI_ERR( "Image Sectn not found i_plat 0x%08x i_sec 0x%08x",
                      (uint32_t) i_plat, i_sec );
            break;
        }

        if( i_size > tempSize )
        {
            rc = tempSize; // returning Max Allowed size  as return code
            break;
        }

    }
    while(0);

    return rc;
}
/**
 * @brief   returns max size for a given image section
 * @param   i_plat      platform associated with image section.
 * @param   i_sec       image section.
 * @param   i_size      actual image section size.
 * @param   i_pSecName  points to a buffer with section name.
 * @param   i_bufLength length of the buffer.
 * @return  zero if section found, error code otherwise.
 */
uint32_t ImgSizeBank::getImgSectn( PlatId i_plat, uint8_t i_sec, uint32_t& o_secSize,
                                   char* i_pSecName, uint8_t i_bufLength )
{
    uint32_t rc = -1;
    ImgSec key( i_plat, i_sec );
    std::map< ImgSec, uint32_t>::iterator it;
    o_secSize = 0;

    for( it = iv_secSize.begin(); it != iv_secSize.end(); it++ )
    {
        if( key == it->first )
        {
            rc = 0;
            o_secSize = it->second; //Max Size allowed for section

            //Image section found and maximum size info obtained.
            if( i_pSecName )
            {
                //Copying Sectn name to assist debug
                memcpy( i_pSecName, it->first.iv_secName, i_bufLength );
            }

            break;
        }

    }

    return rc;
}

/**
 * @brief   models an Ex pair.
 */
struct ExpairId
{
    uint16_t iv_evenExId;
    uint16_t iv_oddExId;
    /**
     * @brief constructor
     */
    ExpairId( uint32_t i_evenExId, uint32_t i_oddExId ):
        iv_evenExId( i_evenExId ),
        iv_oddExId( i_oddExId )
    { }

    /**
     * @brief constructor
     */
    ExpairId() { };
};

/**
 * @brief   a map to resolve Ex chiplet Id associated with all six quads in P9.
 */
class ExIdMap
{
    public:
        ExIdMap();
        ~ExIdMap() {};
        uint32_t getInstanceId( uint32_t i_eqId, uint32_t i_ringOrder );
    private:
        std::map<uint32_t, ExpairId> iv_idMap;
};

#define     ALIGN_DBWORD( OUTSIZE, INSIZE )         \
    {                                               \
        OUTSIZE = INSIZE;                           \
        if( 0 != (INSIZE/8) )                       \
        {                                           \
            OUTSIZE = ((( INSIZE + 7 )/ 8) << 3 );  \
        }                                           \
    }

/**
 * @brief constructor
 */
ExIdMap::ExIdMap()
{
    ExpairId exPairIdMap[6] = {  { 0x10, 0x11},
        { 0x12, 0x13 },
        { 0x14, 0x15 },
        { 0x16, 0x17 },
        { 0x18, 0x19 },
        { 0x1A, 0x1B }
    };

    for( uint32_t eqCnt = 0; eqCnt < MAX_QUADS_PER_CHIP; eqCnt++ )
    {
        iv_idMap[CACHE0_CHIPLET_ID + eqCnt] = exPairIdMap[eqCnt];
    }
}

//-------------------------------------------------------------------------

/**
 * @brief   returns ex chiplet ID associated with a scan ring and EQ id.
 * @param   i_eqId      chiplet id for a given quad.
 * @param   i_ringOrder serial number associated with a scan ring in HOMER.
 * @return  chiplet Id associated with a scan ring.
 */
uint32_t ExIdMap::getInstanceId( uint32_t i_eqId, uint32_t i_ringOrder )
{
    uint32_t exChipletId = 0xFFFFFFFF;
    std::map<uint32_t, ExpairId>::iterator itChipId = iv_idMap.find( i_eqId );

    do
    {
        if ( itChipId == iv_idMap.end() )
        {
            break;
        }
        else
        {
            switch( i_ringOrder )
            {
                case 0:
                    exChipletId = i_eqId;
                    break;

                case 1:
                case 3:
                case 5:
                case 7:
                    exChipletId = itChipId->second.iv_evenExId;
                    break;

                case  2:
                case  4:
                case  6:
                case  8:
                    exChipletId = itChipId->second.iv_oddExId;
                    break;

                default:
                    break;
            }
        }

    }
    while(0);

    FAPI_DBG("Resolved Ex Id 0x%02x", exChipletId );
    return exChipletId;
}

//-------------------------------------------------------------------------
fapi2::ReturnCode validateSramImageSize( Homerlayout_t* i_pChipHomer, uint32_t& o_sramImgSize )
{
    FAPI_DBG(">validateSramImageSize" );
    uint32_t rc = IMG_BUILD_SUCCESS;

    ImgSizeBank sizebank;
    cmeHeader_t* pCmeHdr = (cmeHeader_t*) & i_pChipHomer->cpmrRegion.cmeSramRegion[CME_INT_VECTOR_SIZE];
    QpmrHeaderLayout_t* pQpmrHdr = ( QpmrHeaderLayout_t*) & (i_pChipHomer->qpmrRegion.sgpeRegion.qpmrHeader);
    PpmrHeader_t* pPpmrHdr = ( PpmrHeader_t* ) i_pChipHomer->ppmrRegion.ppmrHeader;
    o_sramImgSize =  SWIZZLE_4_BYTE(pQpmrHdr->sgpeSramImageSize);

    rc = sizebank.isSizeGood( PLAT_SGPE, SGPE_SRAM_IMAGE, o_sramImgSize, NULL , 0 );
    FAPI_IMP("SGPE SRAM Image Size : 0x%08X Size Check : %s", o_sramImgSize, rc ? "FAILURE" : "SUCCESS" );

    FAPI_ASSERT( ( IMG_BUILD_SUCCESS ==  rc ),
                 fapi2::SGPE_IMG_EXCEED_SRAM_SIZE( )
                 .set_BAD_IMG_SIZE( o_sramImgSize )
                 .set_MAX_SGPE_IMG_SIZE_ALLOWED( rc ),
                 "SGPE Image Size Exceeded Max Allowed Size" );

    o_sramImgSize = (SWIZZLE_4_BYTE(pCmeHdr->g_cme_scom_offset) << CME_BLK_SIZE_SHIFT) +
                    SWIZZLE_4_BYTE(pCmeHdr->g_cme_scom_length);

    FAPI_DBG("CME Offset 0x%08X size 0x%08X", SWIZZLE_4_BYTE(pCmeHdr->g_cme_scom_offset), o_sramImgSize );

    rc = sizebank.isSizeGood( PLAT_CME, CME_SRAM_IMAGE, o_sramImgSize, NULL, 0 );
    FAPI_IMP("CME SRAM Image Size : 0x%08X Size Check : %s", o_sramImgSize, rc ? "FAILURE" : "SUCCESS" );

    FAPI_ASSERT( ( IMG_BUILD_SUCCESS ==  rc ),
                 fapi2::CME_IMG_EXCEED_SRAM_SIZE( )
                 .set_BAD_IMG_SIZE( o_sramImgSize )
                 .set_MAX_CME_IMG_SIZE_ALLOWED( rc ),
                 "CME Image Size Exceeded Max Allowed Size" );


    o_sramImgSize = SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_pgpe_sram_img_size);

    rc = sizebank.isSizeGood( PLAT_PGPE, PGPE_SRAM_IMAGE, o_sramImgSize, NULL, 0 );
    FAPI_IMP("PGPE SRAM Image Size : 0x%08X Size Check : %s", o_sramImgSize, rc ? "FAILURE" : "SUCCESS" );

    FAPI_ASSERT( ( IMG_BUILD_SUCCESS ==  rc ),
                 fapi2::PGPE_IMG_EXCEED_SRAM_SIZE( )
                 .set_BAD_IMG_SIZE( o_sramImgSize )
                 .set_MAX_PGPE_IMG_SIZE_ALLOWED( rc ),
                 "PGPE Image Size Exceeded Max Allowed Size" );

    FAPI_DBG("<validateSramImageSize" );

fapi_try_exit:
    return fapi2::current_err;
}


//-------------------------------------------------------------------------

/**
 * @brief   validates arguments passed for hcode image build
 * @param   refer to p9_hcode_image_build arguments
 * @return  fapi2 return code
*/
fapi2::ReturnCode validateInputArguments( void* const i_pImageIn, void* i_pImageOut,
        SysPhase_t i_phase, ImageType_t i_imgType,
        void* i_pBuf1, uint32_t i_bufSize1, void* i_pBuf2,
        uint32_t i_bufSize2, void* i_pBuf3, uint32_t i_bufSize3 )
{
    uint32_t l_rc = IMG_BUILD_SUCCESS;
    uint32_t hwImagSize = 0;

    FAPI_DBG("Entering validateInputArguments ...");

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

    FAPI_ASSERT( ( i_imgType.isBuildValid() ),
                 fapi2::HCODE_INVALID_IMG_TYPE(),
                 "Invalid image type passed for hcode image build" );
    FAPI_DBG("Exiting validateInputArguments ...");

fapi_try_exit:
    return fapi2::current_err;
}

//------------------------------------------------------------------------------

uint32_t getXipImageSectn( uint8_t * i_srcPtr, uint8_t i_secId, uint8_t i_ecLevel,
                           P9XipSection&  o_ppeSection )
{
    uint32_t rc = IMG_BUILD_SUCCESS;
    do
    {
        bool ecLvlSupported = false;

        rc = p9_xip_dd_section_support( i_srcPtr, i_secId, ecLvlSupported );

        if( rc )
        {
            break;
        }

        if( ecLvlSupported )
        {
            rc = p9_xip_get_section( i_srcPtr, i_secId, &o_ppeSection, i_ecLevel );
        }
        else
        {
            rc = p9_xip_get_section( i_srcPtr, i_secId, &o_ppeSection );
        }

        FAPI_INF("Multiple EC Level Support  : %s For Sec Id 0x%02x EC : 0x%02x",
                  ecLvlSupported ? "Yes" :"No", i_secId, i_ecLevel );
    }while(0);

    return rc;
}

//------------------------------------------------------------------------------

/**
 * @brief   Copies section of hardware image to HOMER
 * @param   i_destPtr       a location in HOMER
 * @param   i_srcPtr        a location in HW Image.
 * @param   i_secId         XIP Section id to be copied.
 * @param   i_platId        platform associated with the given section.
 * @param   o_ppeSection    contains section details.
 * @return  IMG_BUILD_SUCCESS if successful, error code otherwise.
 */
uint32_t copySectionToHomer( uint8_t* i_destPtr, uint8_t* i_srcPtr, uint8_t i_secId, PlatId i_platId ,
                             uint8_t i_ecLevel, P9XipSection&   o_ppeSection )
{
    FAPI_INF("> copySectionToHomer");
    uint32_t retCode = IMG_BUILD_SUCCESS;
    ImgSizeBank sizebank;

    do
    {
        char secName[SECTN_NAME_MAX_LEN] = {0};
        o_ppeSection.iv_offset = 0;
        o_ppeSection.iv_size = 0;

        uint32_t rcTemp = getXipImageSectn( i_srcPtr, i_secId, i_ecLevel, o_ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to get section 0x%08X of Plat 0x%08X xip RC 0x%08x",
                      i_secId, i_platId, rcTemp );
            retCode = BUILD_FAIL_INVALID_SECTN;
            break;
        }

        FAPI_DBG("o_ppeSection.iv_offset = %X, "
                 "o_ppeSection.iv_size = %X, "
                 "i_secId %d",
                 o_ppeSection.iv_offset,
                 o_ppeSection.iv_size,
                 i_secId);

        rcTemp = sizebank.isSizeGood( i_platId, i_secId, o_ppeSection.iv_size, secName, SECTN_NAME_MAX_LEN );

        if ( rcTemp )
        {
            FAPI_ERR("??????????Size Exceeds the permissible limit???????" );
            FAPI_ERR("Sec Name: %s Max Allowed 0x%08X (%08d) Actual Size 0x%08X (%08d)",
                     secName, rcTemp, rcTemp, o_ppeSection.iv_size, o_ppeSection.iv_size);
            retCode = BUILD_SEC_SIZE_OVERFLOW;
            break;
        }

        memcpy( i_destPtr, i_srcPtr + o_ppeSection.iv_offset, o_ppeSection.iv_size );
    }
    while(0);

    FAPI_INF("< copySectionToHomer");
    return retCode;
}

//------------------------------------------------------------------------------

/**
 * @brief   Update the CME/SGPE Image Header Flag field.
 * @param   i_pChipHomer    points to HOMER image.
 * @return  fapi2 return code.
 */
fapi2::ReturnCode updateImageFlags( Homerlayout_t* i_pChipHomer, CONST_FAPI2_PROC& i_procTgt )
{
    uint8_t      attrVal   = 0;
    uint64_t     chtmVal   = 0;
    uint32_t     cmeFlag   = 0;
    uint32_t     sgpeFlag  = 0;
    uint16_t     qmFlags   = 0;
    pgpe_flags_t pgpeFlags;
    pgpeFlags.value = 0;

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    cmeHeader_t* pCmeHdr = (cmeHeader_t*) & i_pChipHomer->cpmrRegion.cmeSramRegion[CME_INT_VECTOR_SIZE];
    sgpeHeader_t* pSgpeHdr = (sgpeHeader_t*)& i_pChipHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECTOR_SIZE];
    PgpeHeader_t* pPgpeHdr = (PgpeHeader_t*)& i_pChipHomer->ppmrRegion.pgpeSramImage[PGPE_INT_VECTOR_SIZE];
    //Handling flags common to CME and SGPE

    FAPI_DBG(" ==================== CME/SGPE Flags =================");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_STOP4_DISABLE,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_STOP4_DISABLE");

    if( attrVal )
    {
        cmeFlag |= CME_STOP_4_TO_2_BIT_POS;
        sgpeFlag |= SGPE_STOP_4_TO_2_BIT_POS;
    }

    FAPI_DBG("STOP_4_to_2           :   %s", attrVal ? "TRUE" : "FALSE" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_STOP5_DISABLE,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_STOP5_DISABLE");

    if( attrVal )
    {
        cmeFlag |= CME_STOP_5_TO_4_BIT_POS;
        sgpeFlag |= SGPE_STOP_5_TO_4_BIT_POS;
    }

    FAPI_DBG("STOP_5_to_4           :   %s", attrVal ? "TRUE" : "FALSE");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_STOP8_DISABLE,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_STOP8_DISABLE");

    if( attrVal )
    {
        cmeFlag |= CME_STOP_8_TO_5_BIT_POS;
        sgpeFlag |= SGPE_STOP_8_TO_5_BIT_POS;
    }

    FAPI_DBG("STOP_8_to_5           :   %s", attrVal ? "TRUE" : "FALSE" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_STOP11_DISABLE,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_STOP11_DISABLE");

    if( attrVal )
    {
        cmeFlag |= CME_STOP_11_TO_8_BIT_POS;
        sgpeFlag |= SGPE_STOP_11_TO_8_BIT_POS;
    }

    FAPI_DBG("STOP_11_to_8                  :   %s", attrVal ? "TRUE" : "FALSE" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CME_INSTRUCTION_TRACE_ENABLE,
                           i_procTgt,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_CME_INSTRUCTION_TRACE_ENABLE");

    if( attrVal )
    {
        sgpeFlag |= SGPE_ENABLE_CME_TRACE_ARRAY_BIT_POS;
    }

    FAPI_DBG("CME Instruction Trace Enabled :   %s", attrVal ? "TRUE" : "FALSE" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CME_CHTM_TRACE_ENABLE,
                           i_procTgt,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_CME_CHTM_TRACE_ENABLE");

    if( attrVal )
    {
        sgpeFlag |= SGPE_ENABLE_CHTM_TRACE_CME_BIT_POS;
    }

    FAPI_DBG("CME CHTM Trace Enabled :   %s", attrVal ? "TRUE" : "FALSE" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CME_CHTM_TRACE_MEMORY_CONFIG,
                           i_procTgt,
                           chtmVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_CME_CHTM_TRACE_MEMORY_CONFIG" );

    if( chtmVal )
    {
        pSgpeHdr->g_sgpe_chtm_mem_cfg = SWIZZLE_8_BYTE(chtmVal);
    }

    FAPI_DBG("CME CHTM Memory Config :   %016llx", chtmVal);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_ENABLE,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_SYSTEM_RESCLK_ENABLE" );

    if( attrVal )
    {
        qmFlags |= CME_QM_FLAG_RESCLK_ENABLE;
        pgpeFlags.fields.resclk_enable = 1;
    }

    FAPI_DBG("Resonant Clock Enable  :   %s", attrVal ? "TRUE" : "FALSE" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_IVRMS_ENABLED,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_SYSTEM_IVRMS_ENABLED" );

    if( attrVal )
    {
        qmFlags |= CME_QM_FLAG_SYS_IVRM_ENABLE;
        pgpeFlags.fields.ivrm_enable = 1;
    }

    FAPI_DBG("System IVRM Enable   :   %s", attrVal ? "TRUE" : "FALSE" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_ENABLE,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_VDM_ENABLE" );

    if( attrVal )
    {
        qmFlags |= CME_QM_FLAG_SYS_VDM_ENABLE;
        sgpeFlag |= SGPE_VDM_ENABLE_BIT_POS;
        pgpeFlags.fields.vdm_enable = 1;
    }

    FAPI_DBG("System VDM Enable   :   %s", attrVal ? "TRUE" : "FALSE" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_PROC_FABRIC_PUMP_MODE_MODE");

    //Attribute set to 0x01 for CHIP_IS_NODE, 0x02 for CHIP_IS_GROUP
    if( attrVal == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE )
    {
        sgpeFlag |= SGPE_PROC_FAB_PUMP_MODE_BIT_POS;
    }

    FAPI_DBG("FAB_PUMP_MODE       :   %s", (attrVal == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE) ? "TRUE" : "FALSE" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_WOF_ENABLED,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_SYSTEM_WOF_ENABLED" );

    if( attrVal )
    {
        qmFlags |= CME_QM_FLAG_SYS_WOF_ENABLE;
        pgpeFlags.fields.wof_enable = 1;
    }

    FAPI_DBG("System WOF Enable   :   %s", attrVal ? "TRUE" : "FALSE" );

    // Set PGPE Header Flags from Attributes
    FAPI_DBG(" -------------------- PGPE Flags -----------------");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PGPE_HCODE_FUNCTION_ENABLE,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_PGPE_HCODE_FUNCTION_ENABLE");

    // If 0 (Hcode disabled), then set the occ_opc_immed_response flag bit
    if( !attrVal )
    {
        pgpeFlags.fields.occ_ipc_immed_response = 1;
    }

    FAPI_DBG("PGPE Hcode Mode        :   %s", attrVal ? "PSTATES Enabled" : "OCC IPC Immediate Response Mode" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_ENABLE_FRATIO,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_WOF_ENABLE_FRATIO" );

    if( attrVal )
    {
        pgpeFlags.fields.enable_fratio = 1;
    }

    FAPI_DBG("System FRATIO ENABLE   :   %s", attrVal ? "TRUE" : "FALSE" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_ENABLE_VRATIO,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_WOF_ENABLE_VRATIO" );

    if( attrVal )
    {
        pgpeFlags.fields.enable_vratio = 1;
    }

    FAPI_DBG("System VRATIO ENABLE   :   %s", attrVal ? "TRUE" : "FALSE" );

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_VRATIO_SELECT,
                           FAPI_SYSTEM,
                           attrVal),
             "Error from FAPI_ATTR_GET for attribute ATTR_WOF_VRATIO_SELECT" );

    if( attrVal )
    {
        pgpeFlags.fields.vratio_modifier = 1;
    }

    FAPI_DBG("System VRATIO SELECT:   %s", attrVal ? "TRUE" : "FALSE" );



    // Updating flag fields in the headers
    pCmeHdr->g_cme_mode_flags       =   SWIZZLE_4_BYTE(cmeFlag);
    pCmeHdr->g_cme_qm_mode_flags    =   SWIZZLE_2_BYTE(qmFlags);
    pSgpeHdr->g_sgpe_reserve_flags  =   SWIZZLE_4_BYTE(sgpeFlag);
    pPgpeHdr->g_pgpe_flags          =   SWIZZLE_2_BYTE(pgpeFlags.value);

    FAPI_INF("CME Flag Value        : 0x%08x", SWIZZLE_4_BYTE(pCmeHdr->g_cme_mode_flags));
    FAPI_INF("CME QM Flag Value     : 0x%08x", SWIZZLE_2_BYTE(pCmeHdr->g_cme_qm_mode_flags));
    FAPI_INF("SGPE Flag Value       : 0x%08x", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_reserve_flags));
    FAPI_INF("SGPE Chtm Config      : 0x%016llx", SWIZZLE_8_BYTE(pSgpeHdr->g_sgpe_chtm_mem_cfg));
    FAPI_INF("PGPE Flag Value       : 0x%08x", SWIZZLE_2_BYTE(pPgpeHdr->g_pgpe_flags));
    FAPI_DBG(" -------------------- CME/SGPE Flags Ends ---------------==");

fapi_try_exit:
    return fapi2::current_err;
}

//------------------------------------------------------------------------------

/**
 * @brief   updates various CPMR fields which are associated with scan rings.
 * @param   i_pChipHomer    points to start of P9 HOMER.
 */
void updateCpmrCmeRegion( Homerlayout_t* i_pChipHomer )
{
    cpmrHeader_t* pCpmrHdr =
        (cpmrHeader_t*) & (i_pChipHomer->cpmrRegion.selfRestoreRegion.CPMR_SR.elements.CPMRHeader);
    cmeHeader_t* pCmeHdr = (cmeHeader_t*) & i_pChipHomer->cpmrRegion.cmeSramRegion[CME_INT_VECTOR_SIZE];

    //Updating CPMR Header using info from CME Header
    pCpmrHdr->cmeImgOffset              =   SWIZZLE_4_BYTE((CME_IMAGE_CPMR_OFFSET >> CME_BLK_SIZE_SHIFT));
    pCpmrHdr->cmePstateOffset           =   CME_IMAGE_CPMR_OFFSET + SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_offset);
    pCpmrHdr->cmePstateOffset           =   SWIZZLE_4_BYTE(pCpmrHdr->cmePstateOffset);
    pCpmrHdr->cmePstateLength           =   pCmeHdr->g_cme_pstate_region_length;
    pCpmrHdr->cmeImgLength              =   pCmeHdr->g_cme_hcode_length;// already swizzled
    pCpmrHdr->coreScomOffset            =   SWIZZLE_4_BYTE(CORE_SCOM_RESTORE_CPMR_OFFSET);
    pCpmrHdr->coreScomLength            =   SWIZZLE_4_BYTE(CORE_SCOM_RESTORE_SIZE_TOTAL);

    if( pCmeHdr->g_cme_common_ring_length )
    {
        pCpmrHdr->cmeCommonRingOffset       =   CME_IMAGE_CPMR_OFFSET + SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_offset);
        pCpmrHdr->cmeCommonRingOffset       =   SWIZZLE_4_BYTE(pCpmrHdr->cmeCommonRingOffset);
        pCpmrHdr->cmeCommonRingLength       =   pCmeHdr->g_cme_common_ring_length;
    }

    if( pCmeHdr->g_cme_max_spec_ring_length )
    {
        pCpmrHdr->coreSpecRingOffset        =   ( SWIZZLE_4_BYTE(pCpmrHdr->cmeImgOffset) << CME_BLK_SIZE_SHIFT ) +
                                                SWIZZLE_4_BYTE( pCpmrHdr->cmeImgLength) +
                                                SWIZZLE_4_BYTE(pCpmrHdr->cmePstateLength) +
                                                SWIZZLE_4_BYTE(pCpmrHdr->cmeCommonRingLength);
        pCpmrHdr->coreSpecRingOffset        =   (pCpmrHdr->coreSpecRingOffset + CME_BLOCK_READ_LEN - 1) >> CME_BLK_SIZE_SHIFT;
        pCpmrHdr->coreSpecRingOffset        =   SWIZZLE_4_BYTE(pCpmrHdr->coreSpecRingOffset);
        pCpmrHdr->coreSpecRingLength        =   pCmeHdr->g_cme_max_spec_ring_length; // already swizzled
    }

    //Updating CME Image header
    pCmeHdr->g_cme_scom_offset          =   SWIZZLE_4_BYTE(pCmeHdr->g_cme_hcode_length) +
                                            SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_length) +
                                            SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_length);
    pCmeHdr->g_cme_scom_offset          =
        ((pCmeHdr->g_cme_scom_offset + CME_BLOCK_READ_LEN - 1 ) >> CME_BLK_SIZE_SHIFT);
    //Adding to it instance ring length which is already a multiple of 32B
    pCmeHdr->g_cme_scom_offset          +=  SWIZZLE_4_BYTE(pCmeHdr->g_cme_max_spec_ring_length);
    pCmeHdr->g_cme_scom_offset          =   SWIZZLE_4_BYTE(pCmeHdr->g_cme_scom_offset);
    pCmeHdr->g_cme_scom_length          =   SWIZZLE_4_BYTE(CORE_SCOM_RESTORE_SIZE_PER_CME);

    FAPI_INF("========================= CME Header Start ==================================");
    FAPI_INF("  HC Offset       :   0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_hcode_offset));
    FAPI_INF("  HC Size         :   0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_hcode_length));
    FAPI_INF("  PS Offset       :   0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_offset));
    FAPI_INF("  PS Size         :   0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_length));
    FAPI_INF("  CR Offset       :   0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_offset));
    FAPI_INF("  CR Ovrd Offset  :   0x%08X", SWIZZLE_4_BYTE(pCmeHdr->g_cme_cmn_ring_ovrd_offset ));
    FAPI_INF("  CR Size         :   0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_length));
    FAPI_INF("  CSR Offset      :   0x%08X (Real offset / 32) ", SWIZZLE_4_BYTE(pCmeHdr->g_cme_core_spec_ring_offset));
    FAPI_INF("  CSR Length      :   0x%08X (Real length / 32)", SWIZZLE_4_BYTE(pCmeHdr->g_cme_max_spec_ring_length) );
    FAPI_INF("  SCOM Offset     :   0x%08X (Real offset / 32)",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_scom_offset));
    FAPI_INF("  SCOM Area Len   :   0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_scom_length));
    FAPI_INF("  CPMR Phy Add    :   0x%016lx", SWIZZLE_8_BYTE(pCmeHdr->g_cme_cpmr_PhyAddr));
    FAPI_INF("========================= CME Header End ==================================");

    FAPI_INF("==========================CPMR Header===========================================");
    FAPI_INF(" CME HC Offset    : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmeImgOffset));
    FAPI_INF(" CME HC Length    : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmeImgLength));
    FAPI_INF(" PS  Offset       : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmePstateOffset));
    FAPI_INF(" PS  Length       : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmePstateLength));
    FAPI_INF(" CR  Offset       : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmeCommonRingOffset));
    FAPI_INF(" CR  Length       : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmeCommonRingLength));
    FAPI_INF(" CSR Offset       : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->coreSpecRingOffset));
    FAPI_INF(" CSR Length       : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->coreSpecRingLength));
    FAPI_INF(" Core SCOM Offset : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->coreScomOffset));
    FAPI_INF(" Core SCOM Length : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->coreScomLength ));
    FAPI_INF("==================================CPMR Ends=====================================");

}

//------------------------------------------------------------------------------
/**
 * @brief   updates various CPMR fields which are associated with self restore code.
 * @param   i_pChipHomer    points to start of P9 HOMER.
 * @param   i_fuseState     core fuse status
 */
void updateCpmrHeaderSR( Homerlayout_t* i_pChipHomer, uint8_t i_fusedState )
{
    FAPI_INF("> updateCpmrHeaderSR");
    cpmrHeader_t* pCpmrHdr =
        (cpmrHeader_t*) & (i_pChipHomer->cpmrRegion.selfRestoreRegion.CPMR_SR.elements.CPMRHeader);

    cmeHeader_t* pCmeHdr = (cmeHeader_t*) & i_pChipHomer->cpmrRegion.cmeSramRegion[CME_INT_VECTOR_SIZE];
    //populate CPMR header
    pCpmrHdr->fusedModeStatus = i_fusedState ? uint32_t(FUSED_CORE_MODE) :
                                uint32_t(NONFUSED_CORE_MODE);
    pCmeHdr->g_cme_mode_flags = SWIZZLE_4_BYTE(i_fusedState ? 1 : 0);

    FAPI_INF("CPMR SR");
    FAPI_INF("  Fuse Mode = 0x%08X CME Image Flag = 0x%08X", pCpmrHdr->fusedModeStatus,
             SWIZZLE_4_BYTE(pCmeHdr->g_cme_mode_flags));
    FAPI_DBG("  Offset    = 0x%08X, Header value 0x%08X (Real offset / 32)",
             SWIZZLE_4_BYTE(pCpmrHdr->cmeImgOffset) * 32,
             SWIZZLE_4_BYTE(pCpmrHdr->cmeImgOffset));
    FAPI_DBG("  Size      = 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmeImgLength));

    FAPI_INF("< updateCpmrHeaderSR");
}

//------------------------------------------------------------------------------
/**
 * @brief   updates various QPMR header region in HOMER.
 * @param   i_pChipHomer    points to start of P9 HOMER.
 * @param   io_qpmrHdr      temp instance of QpmrHeaderLayout_t used for data collection.
 */
void updateQpmrHeader( Homerlayout_t* i_pChipHomer, QpmrHeaderLayout_t& io_qpmrHdr )
{
    QpmrHeaderLayout_t* pQpmrHdr = ( QpmrHeaderLayout_t*) & (i_pChipHomer->qpmrRegion.sgpeRegion.qpmrHeader);
    sgpeHeader_t* pSgpeHdr = (sgpeHeader_t*)& i_pChipHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECTOR_SIZE];
    io_qpmrHdr.sgpeSramImageSize = SWIZZLE_4_BYTE(io_qpmrHdr.sgpeImgLength) +
                                   SWIZZLE_4_BYTE(io_qpmrHdr.quadCommonRingLength) +
                                   SWIZZLE_4_BYTE(io_qpmrHdr.quadSpecRingLength);

    io_qpmrHdr.sgpeSramImageSize = SWIZZLE_4_BYTE(io_qpmrHdr.sgpeSramImageSize);
    memcpy( pQpmrHdr, &io_qpmrHdr, sizeof( QpmrHeaderLayout_t ) );
    pSgpeHdr->g_sgpe_scom_mem_offset        =   SWIZZLE_4_BYTE(QPMR_HOMER_OFFSET + QUAD_SCOM_RESTORE_QPMR_OFFSET );

    FAPI_INF("==============================QPMR==================================");
    FAPI_DBG("  Build Date              : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->buildDate));
    FAPI_DBG("  Version                 : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->buildVersion));
    FAPI_DBG("  BC Offset               : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->bootCopierOffset));
    FAPI_DBG("  BL Offset               : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->bootLoaderOffset));
    FAPI_DBG("  BL Size                 : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->bootLoaderLength));
    FAPI_DBG("  HC Offset               : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->sgpeImgOffset));
    FAPI_DBG("  HC Size                 : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->sgpeImgLength));
    FAPI_DBG("  Cmn Ring Offset         : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadCommonRingOffset) );
    FAPI_DBG("  Cmn Ring Length         : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadCommonRingLength) );
    FAPI_DBG("  Cmn Ring Ovrd Offset    : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadCommonOvrdOffset) );
    FAPI_DBG("  Cmn Ring Ovrd Length    : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadCommonOvrdLength) );
    FAPI_DBG("  Quad Spec Ring Offset   : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadSpecRingOffset) );
    FAPI_DBG("  Quad Spec Ring Length   : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadSpecRingLength) );
    FAPI_INF("  Quad SCOM Offset        : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadScomOffset) );
    FAPI_INF("  Quad SCOM Length        : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadScomLength) );
    FAPI_DBG("  SGPE SRAM Img Size      : 0x%08x", SWIZZLE_4_BYTE(pQpmrHdr->sgpeSramImageSize ) );
    FAPI_DBG("==============================QPMR Ends==============================");

    FAPI_DBG("===========================SGPE Image Hdr=============================");
    FAPI_DBG(" Cmn Ring Offset          :  0x%08x", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_cmn_ring_occ_offset ));
    FAPI_DBG(" Override Offset          :  0x%08x", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_cmn_ring_ovrd_occ_offset ));
    FAPI_DBG(" Flags                    :  0x%08x", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_reserve_flags ));
    FAPI_DBG(" Quad Spec Ring Offset    :  0x%08x", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_spec_ring_occ_offset ));
    FAPI_DBG(" Quad SCOM SRAM Offset    :  0x%08x", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_scom_offset));
    FAPI_DBG(" Quad SCOM Mem Offset     :  0x%08x", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_scom_mem_offset));
    FAPI_DBG(" Quad SCOM Mem Length     :  0x%08x", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_scom_mem_length ));
    FAPI_DBG(" Auxiliary Func Offset    :  0x%08x", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_aux_offset ));
    FAPI_DBG(" Auxiliary Func Length    :  0x%08x", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_aux_length ));
    FAPI_DBG("========================SGPE Image Hdr Ends===========================");

}

//------------------------------------------------------------------------------
/**
 * @brief       copies image section associated with  SGPE from HW Image to HOMER
 * @param[in]   i_pImageIn      points to start of hardware image.
 * @param[in]   i_pChipHomer    points to HOMER image.
 * @param[in]   i_imgType       image sections  to be built
 */
uint32_t buildSgpeImage( void* const i_pImageIn, Homerlayout_t* i_pChipHomer, ImageType_t i_imgType,
                         QpmrHeaderLayout_t& o_qpmrHdr, uint8_t i_ecLevel )
{
    FAPI_INF("> buildSgpeImage");
    uint32_t retCode = IMG_BUILD_SUCCESS;

    do
    {
        uint32_t rcTemp = 0;
        //Let us find XIP Header for SGPE
        P9XipSection ppeSection;
        uint8_t* pSgpeImg = NULL;

        if(!i_imgType.sgpeHcodeBuild )
        {
            break;
        }

        // Let us start with a clean slate in quad common ring area.
        memset( (uint8_t*)&i_pChipHomer->qpmrRegion.sgpeRegion.sgpeSramImage, 0x00, SGPE_IMAGE_SIZE );

        rcTemp = p9_xip_get_section( i_pImageIn, P9_XIP_SECTION_HW_SGPE, &ppeSection );;

        if( rcTemp )
        {
            FAPI_ERR("Failed to get SGPE XIP Image Header" );
            retCode = BUILD_FAIL_SGPE_IMAGE;
            break;
        }

        pSgpeImg = ppeSection.iv_offset + (uint8_t*) (i_pImageIn );
        FAPI_DBG("HW image SGPE Offset = 0x%08X", ppeSection.iv_offset);

        FAPI_INF("QPMR Header");
        rcTemp = copySectionToHomer( i_pChipHomer->qpmrRegion.sgpeRegion.qpmrHeader,
                                     pSgpeImg,
                                     P9_XIP_SECTION_SGPE_QPMR,
                                     PLAT_SGPE,
                                     i_ecLevel,
                                     ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to copy QPMR Header");
            retCode = BUILD_FAIL_SGPE_QPMR;
            break;
        }

        //updating local instance of QPMR header
        memcpy( &o_qpmrHdr, i_pChipHomer->qpmrRegion.sgpeRegion.qpmrHeader, sizeof(QpmrHeaderLayout_t));

        FAPI_DBG("SGPE Boot Copier");
        rcTemp = copySectionToHomer( i_pChipHomer->qpmrRegion.sgpeRegion.l1BootLoader,
                                     pSgpeImg,
                                     P9_XIP_SECTION_SGPE_LVL1_BL,
                                     PLAT_SGPE,
                                     i_ecLevel,
                                     ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to copy Level1 bootloader");
            retCode = BUILD_FAIL_SGPE_BL1;
            break;
        }

        o_qpmrHdr.bootCopierOffset = QPMR_HEADER_SIZE;
        FAPI_DBG("SGPE Boot Copier Size = 0x%08X",
                 o_qpmrHdr.bootCopierOffset);

        FAPI_DBG("  SGPE Boot Loader");

        rcTemp = copySectionToHomer( i_pChipHomer->qpmrRegion.sgpeRegion.l2BootLoader,
                                     pSgpeImg,
                                     P9_XIP_SECTION_SGPE_LVL2_BL,
                                     PLAT_SGPE,
                                     i_ecLevel,
                                     ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to copy Level2 bootloader");
            retCode = BUILD_FAIL_SGPE_BL2;
            break;
        }

        o_qpmrHdr.bootLoaderOffset = o_qpmrHdr.bootCopierOffset + SGPE_BOOT_COPIER_SIZE;
        o_qpmrHdr.bootLoaderLength = ppeSection.iv_size;

        FAPI_INF("SGPE Boot Loader QPMR Offset = 0x%08X, Size = 0x%08X",
                 o_qpmrHdr.bootLoaderOffset, o_qpmrHdr.bootLoaderLength);

        rcTemp = copySectionToHomer( i_pChipHomer->qpmrRegion.sgpeRegion.sgpeSramImage,
                                     pSgpeImg,
                                     P9_XIP_SECTION_SGPE_HCODE,
                                     PLAT_SGPE,
                                     i_ecLevel,
                                     ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to copy SGPE hcode");
            retCode = BUILD_FAIL_SGPE_HCODE;
            break;
        }

        memset( i_pChipHomer->qpmrRegion.cacheScomRegion, 0x00,
                QUAD_SCOM_RESTORE_SIZE_TOTAL );

        o_qpmrHdr.sgpeImgOffset = o_qpmrHdr.bootLoaderOffset + SGPE_BOOT_LOADER_SIZE;

        FAPI_DBG("SGPE Hcode       QPMR Offset = 0x%08X, Size = 0x%08X",
                 SWIZZLE_4_BYTE(o_qpmrHdr.sgpeImgOffset),
                 SWIZZLE_4_BYTE(o_qpmrHdr.sgpeImgLength));

        o_qpmrHdr.sgpeImgOffset = o_qpmrHdr.bootLoaderOffset + SGPE_BOOT_LOADER_SIZE;

        o_qpmrHdr.sgpeImgLength       = SWIZZLE_4_BYTE(ppeSection.iv_size);
        o_qpmrHdr.bootLoaderOffset    = SWIZZLE_4_BYTE(o_qpmrHdr.bootLoaderOffset);
        //let us take care of endianess now.
        o_qpmrHdr.bootCopierOffset    = SWIZZLE_4_BYTE(o_qpmrHdr.bootCopierOffset);
        o_qpmrHdr.bootLoaderLength    = SWIZZLE_4_BYTE(o_qpmrHdr.bootLoaderLength);
        o_qpmrHdr.sgpeImgOffset       = SWIZZLE_4_BYTE(o_qpmrHdr.sgpeImgOffset);

        o_qpmrHdr.quadScomOffset  =   SWIZZLE_4_BYTE(QUAD_SCOM_RESTORE_QPMR_OFFSET);
        o_qpmrHdr.quadScomLength  =   SWIZZLE_4_BYTE(QUAD_SCOM_RESTORE_SIZE_TOTAL);

        sgpeHeader_t* pImgHdr = (sgpeHeader_t*)& i_pChipHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECTOR_SIZE];
        pImgHdr->g_sgpe_ivpr_address                =   OCC_SRAM_SGPE_BASE_ADDR;
        pImgHdr->g_sgpe_cmn_ring_occ_offset         =   o_qpmrHdr.sgpeImgLength;
        pImgHdr->g_sgpe_cmn_ring_ovrd_occ_offset    =   0;
        pImgHdr->g_sgpe_spec_ring_occ_offset        =   0;
        pImgHdr->g_sgpe_scom_offset                 =   0;

        FAPI_INF("SGPE Header");
        FAPI_INF("  Reset Addr      = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_reset_address));
        FAPI_INF("  IVPR Addr       = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_ivpr_address));
        FAPI_INF("  Build Date      = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_build_date));
        FAPI_INF("  Version         = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_build_ver));
        FAPI_INF("  CR OCC Offset   = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_cmn_ring_occ_offset));
        FAPI_INF("  CR Ovrd Offset  = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_cmn_ring_ovrd_occ_offset));

    }
    while(0);

    FAPI_INF("< buildSgpeImage")
    return retCode;
}

//------------------------------------------------------------------------------

/**
 * @brief       copies core self restore section from hardware image to HOMER.
 * @param[in]   i_pImageIn      points to start of hardware image.
 * @param[in]   i_pChipHomer    points to HOMER image.
 * @param[in]   i_imgType       image sections  to be built
 * @param[in]   i_fuseState     fuse state of core.
 * @return IMG_BUILD_SUCCESS if function succeeds, error code otherwise.
 */
uint32_t buildCoreRestoreImage( void* const i_pImageIn,
                                Homerlayout_t* i_pChipHomer, ImageType_t i_imgType,
                                uint8_t i_fusedState, uint8_t i_ecLevel )
{
    uint32_t retCode = IMG_BUILD_SUCCESS;

    do
    {
        uint32_t rcTemp = 0;
        //Let us find XIP Header for Core Self Restore Image
        P9XipSection ppeSection;
        uint8_t* pSelfRestImg = NULL;

        rcTemp = p9_xip_get_section( i_pImageIn, P9_XIP_SECTION_HW_RESTORE, &ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to get P9 Self restore Image Header" );
            retCode = BUILD_FAIL_SELF_REST_IMAGE;
            break;
        }

        pSelfRestImg = ppeSection.iv_offset + (uint8_t*) (i_pImageIn );

        if( i_imgType.selfRestoreBuild )
        {
            // first 256 bytes is expected to be zero here. It is by purpose. Just after this step,
            // we will add CPMR header in that area.
            FAPI_INF("Self Restore Image install");
            FAPI_INF("  Offset = 0x%08X, Size = 0x%08X",
                     ppeSection.iv_offset, ppeSection.iv_size);
            rcTemp = copySectionToHomer( i_pChipHomer->cpmrRegion.selfRestoreRegion.CPMR_SR.region,
                                         pSelfRestImg,
                                         P9_XIP_SECTION_RESTORE_SELF,
                                         PLAT_SELF,
                                         i_ecLevel,
                                         ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy SRESET Handler");
                retCode = BUILD_FAIL_SRESET_HNDLR;
                break;
            }
        }

        // adding CPMR header in first 256 bytes of the CPMR.
        FAPI_INF("Overlay CPMR Header at the beginning of CPMR");
        rcTemp = copySectionToHomer( i_pChipHomer->cpmrRegion.selfRestoreRegion.CPMR_SR.region,
                                     pSelfRestImg,
                                     P9_XIP_SECTION_RESTORE_CPMR,
                                     PLAT_SELF,
                                     i_ecLevel,
                                     ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to copy CPMR header");
            retCode = BUILD_FAIL_CPMR_HDR;
            break;
        }

        //Pad undefined or runtime section with  ATTN Opcode
        //Padding SPR restore area with ATTN Opcode
        FAPI_INF("Padding CPMR Core Restore portion with Attn opcodes");
        uint32_t wordCnt = 0;
        uint32_t l_fillBlr  = SWIZZLE_4_BYTE(SELF_RESTORE_BLR_INST);
        uint32_t l_fillAttn = SWIZZLE_4_BYTE(CORE_RESTORE_PAD_OPCODE);

        while( wordCnt < SELF_RESTORE_CORE_REGS_SIZE )
        {

            uint32_t l_fillPattern = 0;

            if( ( 0 == wordCnt ) || ( 0 == ( wordCnt % CORE_RESTORE_SIZE_PER_THREAD ) ))
            {
                l_fillPattern = l_fillBlr;
            }
            else
            {
                l_fillPattern = l_fillAttn;
            }

            //Lab Need: First instruction in thread SPR restore region should be a blr instruction.
            //This helps in a specific lab scenario. If Self Restore region is populated only for
            //select number of threads, other threads will not hit attention during the self restore
            //sequence. Instead, execution will hit a blr and control should return to thread launcher
            //region.

            memcpy( (uint32_t*)&i_pChipHomer->cpmrRegion.selfRestoreRegion.coreSelfRestore[wordCnt],
                    &l_fillPattern,
                    sizeof( uint32_t ));
            wordCnt += 4;
        }

        updateCpmrHeaderSR( i_pChipHomer, i_fusedState );

        memset( i_pChipHomer->cpmrRegion.selfRestoreRegion.coreScom,
                0x00, CORE_SCOM_RESTORE_SIZE_TOTAL );
    }
    while(0);

    return retCode;
}

//------------------------------------------------------------------------------

/**
 * @brief       copies cme section from hardware image to HOMER.
 * @param[in]   i_pImageIn      points to start of hardware image.
 * @param[in]   i_pChipHomer    points to HOMER image.
 * @param[in]   i_imgType       image sections  to be built
 * @return IMG_BUILD_SUCCESS if function succeeds, error code otherwise.
 */
uint32_t buildCmeImage( void* const i_pImageIn, Homerlayout_t* i_pChipHomer,
                        ImageType_t i_imgType, uint64_t i_cpmrPhyAdd, uint8_t i_ecLevel )
{
    uint32_t retCode = IMG_BUILD_SUCCESS;

    do
    {
        uint32_t rcTemp = 0;
        //Let us find XIP Header for CME Image
        P9XipSection ppeSection;
        uint8_t* pCmeImg = NULL;

        if( !i_imgType.cmeHcodeBuild )
        {
            break;
        }

        rcTemp = p9_xip_get_section( i_pImageIn, P9_XIP_SECTION_HW_CME, &ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to get CME Image XIP header" );
            retCode = BUILD_FAIL_CME_IMAGE;
            break;
        }

        pCmeImg = ppeSection.iv_offset + (uint8_t*) (i_pImageIn );
        FAPI_DBG("ppeSection.iv_offset = 0x%08X, ppeSection.iv_size = 0x%08X",
                 ppeSection.iv_offset, ppeSection.iv_size);


        memset(i_pChipHomer->cpmrRegion.cmeSramRegion, 0x00, CME_REGION_SIZE);

        // The image in the HW Image has the Interrupt Vectors, CME Header and Debug
        // Pointers already included.
        rcTemp = copySectionToHomer(  i_pChipHomer->cpmrRegion.cmeSramRegion, pCmeImg,
                                      P9_XIP_SECTION_CME_HCODE,
                                      PLAT_CME,
                                      i_ecLevel,
                                      ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to append CME Hcode");
            retCode = BUILD_FAIL_CME_HCODE;
            break;
        }

        // Initializing CME Image header
        // Names have g_ prefix as these global variables for CME Hcode
        // Note: Only the *memory* addresses are updated
        cmeHeader_t* pImgHdr = (cmeHeader_t*) & i_pChipHomer->cpmrRegion.cmeSramRegion[CME_INT_VECTOR_SIZE];
        pImgHdr->g_cme_hcode_offset =  CME_SRAM_HCODE_OFFSET;
        pImgHdr->g_cme_hcode_length =  ppeSection.iv_size;

        //Populating common ring offset here. So, that other scan ring related field can be updated.
        pImgHdr->g_cme_cpmr_PhyAddr             =   (i_cpmrPhyAdd | CPMR_HOMER_OFFSET);
        pImgHdr->g_cme_pstate_region_offset     =   pImgHdr->g_cme_hcode_offset + pImgHdr->g_cme_hcode_length;
        pImgHdr->g_cme_pstate_region_length     =   0;
        pImgHdr->g_cme_common_ring_offset       =   pImgHdr->g_cme_pstate_region_offset + pImgHdr->g_cme_pstate_region_length;
        pImgHdr->g_cme_common_ring_length       =   0;
        pImgHdr->g_cme_scom_offset              =   0;
        pImgHdr->g_cme_scom_length              =   CORE_SCOM_RESTORE_SIZE_PER_CME;
        pImgHdr->g_cme_core_spec_ring_offset    =   0;    // multiple of 32B blocks
        pImgHdr->g_cme_max_spec_ring_length     =   0;    // multiple of 32B blocks

        //Let us handle the endianess at the end
        pImgHdr->g_cme_pstate_region_offset =  SWIZZLE_4_BYTE(pImgHdr->g_cme_pstate_region_offset);
        pImgHdr->g_cme_common_ring_offset   =  SWIZZLE_4_BYTE(pImgHdr->g_cme_common_ring_offset);
        pImgHdr->g_cme_hcode_offset         =  SWIZZLE_4_BYTE(pImgHdr->g_cme_hcode_offset);
        pImgHdr->g_cme_hcode_length         =  SWIZZLE_4_BYTE(pImgHdr->g_cme_hcode_length);
        pImgHdr->g_cme_scom_length          =  SWIZZLE_4_BYTE(pImgHdr->g_cme_scom_length);
        pImgHdr->g_cme_cpmr_PhyAddr         =  SWIZZLE_8_BYTE(pImgHdr->g_cme_cpmr_PhyAddr);
    }
    while(0);

    return retCode;
}

//------------------------------------------------------------------------------
/**
 * @brief       copies PGPE section from hardware image to HOMER.
 * @param[in]   i_pImageIn      points to start of hardware image.
 * @param[in]   i_pChipHomer    points to HOMER image in main memory.
 * @param[io]   io_ppmrHdr      an instance of PpmrHeader_t
 * @param[in]   i_imgType       image sections  to be built
 * @return IMG_BUILD_SUCCESS if function succeeds, error code otherwise.
 */
uint32_t buildPgpeImage( void* const i_pImageIn, Homerlayout_t* i_pChipHomer,
                         PpmrHeader_t& io_ppmrHdr, ImageType_t i_imgType, uint8_t i_ecLevel )
{
    uint32_t retCode = IMG_BUILD_SUCCESS;
    FAPI_INF("> PGPE Img build")

    do
    {
        uint32_t rcTemp = 0;

        if(!i_imgType.pgpeImageBuild )
        {
            break;
        }

        //Let us find XIP Header for SGPE
        P9XipSection ppeSection;
        uint8_t* pPgpeImg = NULL;

        rcTemp = p9_xip_get_section( i_pImageIn, P9_XIP_SECTION_HW_PGPE, &ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to get PGPE XIP Image Header" );
            retCode = BUILD_FAIL_PGPE_IMAGE;
            break;
        }

        //Init PGPE region with zero
        memset( i_pChipHomer->ppmrRegion.ppmrHeader, 0x00, ONE_MB );
        PpmrHeader_t* pPpmrHdr = ( PpmrHeader_t* ) i_pChipHomer->ppmrRegion.ppmrHeader;

        pPgpeImg = ppeSection.iv_offset + (uint8_t*) (i_pImageIn );
        FAPI_DBG("HW image PGPE Offset = 0x%08X", ppeSection.iv_offset);

        FAPI_INF("PPMR Header");
        rcTemp = copySectionToHomer( i_pChipHomer->ppmrRegion.ppmrHeader,
                                     pPgpeImg,
                                     P9_XIP_SECTION_PGPE_PPMR,
                                     PLAT_PGPE,
                                     i_ecLevel,
                                     ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to copy PPMR Header");
            retCode = BUILD_FAIL_PGPE_PPMR;
            break;
        }

        memcpy( &io_ppmrHdr, pPpmrHdr, sizeof(PpmrHeader_t));

        rcTemp = copySectionToHomer( i_pChipHomer->ppmrRegion.l1BootLoader,
                                     pPgpeImg,
                                     P9_XIP_SECTION_PGPE_LVL1_BL,
                                     PLAT_PGPE,
                                     i_ecLevel,
                                     ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to copy PGPE Level1 bootloader");
            retCode = BUILD_FAIL_PGPE_BL1;
            break;
        }

        io_ppmrHdr.g_ppmr_bc_offset = PPMR_HEADER_SIZE;


        rcTemp = copySectionToHomer( i_pChipHomer->ppmrRegion.l2BootLoader,
                                     pPgpeImg,
                                     P9_XIP_SECTION_PGPE_LVL2_BL,
                                     PLAT_PGPE,
                                     i_ecLevel,
                                     ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to copy PGPE Level2 bootloader");
            retCode = BUILD_FAIL_PGPE_BL2;
            break;
        }

        io_ppmrHdr.g_ppmr_bl_offset = io_ppmrHdr.g_ppmr_bc_offset + PGPE_BOOT_COPIER_SIZE;
        io_ppmrHdr.g_ppmr_bl_length = ppeSection.iv_size;

        rcTemp = copySectionToHomer( i_pChipHomer->ppmrRegion.pgpeSramImage,
                                     pPgpeImg,
                                     P9_XIP_SECTION_PGPE_HCODE,
                                     PLAT_PGPE,
                                     i_ecLevel,
                                     ppeSection );

        if( rcTemp )
        {
            FAPI_ERR("Failed to copy PGPE hcode");
            retCode = BUILD_FAIL_PGPE_HCODE;
            break;
        }

        io_ppmrHdr.g_ppmr_hcode_offset = io_ppmrHdr.g_ppmr_bl_offset + PGPE_BOOT_LOADER_SIZE;
        io_ppmrHdr.g_ppmr_hcode_length = ppeSection.iv_size;

        //Finally let us take care of endianess
        io_ppmrHdr.g_ppmr_bc_offset    = SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_bc_offset);
        io_ppmrHdr.g_ppmr_bl_offset    = SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_bl_offset);
        io_ppmrHdr.g_ppmr_bl_length    = SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_bl_length);
        io_ppmrHdr.g_ppmr_hcode_offset = SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_hcode_offset);
        io_ppmrHdr.g_ppmr_hcode_length = SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_hcode_length);
    }
    while(0);

    FAPI_INF("< PGPE Img build")
    return retCode;
}

//------------------------------------------------------------------------------

/**
 * @brief   get a blob of platform rings in a temp buffer.
 * @param   i_hwImage   points to hardware image.
 * @param   i_procTgt   processor target
 * @param   i_ringData  temp data struct
 */
uint32_t getPpeScanRings( void* const     i_pHwImage,
                          PlatId          i_ppeType,
                          CONST_FAPI2_PROC& i_procTgt,
                          RingBufData&       i_ringData,
                          ImageType_t i_imgType )
{
    FAPI_INF(">getPpeScanRings");
    uint32_t retCode = IMG_BUILD_SUCCESS;
    uint32_t hwImageSize = 0;

    do
    {
        if(( !i_imgType.cmeCommonRingBuild && !i_imgType.cmeCoreSpecificRingBuild ) ||
           ( i_imgType.sgpeCommonRingBuild && !i_imgType.sgpeCacheSpecificRingBuild ))
        {
            break;
        }

        p9_xip_image_size( i_pHwImage, &hwImageSize );

        P9XipSection ppeSection;
        retCode = p9_xip_get_section( i_pHwImage, P9_XIP_SECTION_HW_RINGS, &ppeSection );

        if( retCode )
        {
            FAPI_ERR("Failed to access scan rings for %s", (i_ppeType == PLAT_CME ) ? "CME" : "SGPE" );
            retCode = BUILD_FAIL_RING_EXTRACTN;
            break;
        }

        if( 0 == ppeSection.iv_size )
        {
            retCode = BUILD_FAIL_RING_EXTRACTN;
            FAPI_ERR("Empty .rings section not allowed: <.rings>.iv_size = %d Plat %s",
                     ppeSection.iv_size, (i_ppeType == PLAT_CME ) ? "CME" : "SGPE" );
            break;
        }

        FAPI_DBG("------------------ Input Buffer Specs --------------------");
        FAPI_DBG("Ring section (buf,size)=(0x%016llX,0x%08X)",
                 (uintptr_t)(i_ringData.iv_pRingBuffer), i_ringData.iv_ringBufSize);
        FAPI_DBG("Work buf1 (buf,size)=(0x%016llX,0x%08X)",
                 (uintptr_t)(i_ringData.iv_pWorkBuf1), i_ringData.iv_sizeWorkBuf1);
        FAPI_DBG("Work buf2 (buf,size)=(0x%016llX,0x%08X)",
                 (uintptr_t)(i_ringData.iv_pWorkBuf2), i_ringData.iv_sizeWorkBuf2);
        FAPI_DBG("---------------=== Buffer Specs Ends --------------------");

        FAPI_DBG("--------------- Buffer Initializaiton to 0 --------------------");
        //Init all temp buffers before using.
        memset( (uint8_t*) i_ringData.iv_pRingBuffer,  0x00, i_ringData.iv_ringBufSize );
        memset( (uint8_t*) i_ringData.iv_pWorkBuf1, 0x00, i_ringData.iv_sizeWorkBuf1 );
        memset( (uint8_t*) i_ringData.iv_pWorkBuf2, 0x00, i_ringData.iv_sizeWorkBuf2 );

        uint32_t l_bootMask = ENABLE_ALL_CORE;
        fapi2::ReturnCode l_fapiRc = fapi2::FAPI2_RC_SUCCESS;

        FAPI_EXEC_HWP( l_fapiRc,
                       p9_xip_customize,
                       i_procTgt,
                       i_pHwImage,
                       hwImageSize,
                       i_ringData.iv_pRingBuffer,
                       i_ringData.iv_ringBufSize,
                       (i_ppeType == PLAT_CME) ? SYSPHASE_RT_CME : SYSPHASE_RT_SGPE,
                       MODEBUILD_IPL,
                       i_ringData.iv_pWorkBuf1,
                       i_ringData.iv_sizeWorkBuf1,
                       i_ringData.iv_pWorkBuf2,
                       i_ringData.iv_sizeWorkBuf2,
                       l_bootMask );

        if( l_fapiRc )
        {
            retCode = BUILD_FAIL_RING_EXTRACTN;
            FAPI_ERR("p9_xip_customize failed to extract rings for  %s",
                     (i_ppeType == PLAT_CME ) ? "CME" : "SGPE" );
            break;
        }
    }
    while(0);

    FAPI_INF("<getPpeScanRings " );
    return retCode;
}

//------------------------------------------------------------------------------

uint32_t layoutSgpeScanOverride( Homerlayout_t*   i_pHomer,
                                 void* i_pOverride,
                                 const P9FuncModel& i_chipState,
                                 RingBufData& i_ringData,
                                 RingDebugMode_t i_debugMode,
                                 QpmrHeaderLayout_t& i_qpmrHdr,
                                 ImageType_t i_imgType )
{
    FAPI_INF("> layoutSgpeScanOverride ");
    uint32_t rc = IMG_BUILD_SUCCESS;
    sgpeHeader_t* pSgpeImgHdr = (sgpeHeader_t*)&i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECTOR_SIZE];
    RingBucket sgpeOvrdRings( PLAT_SGPE,
                              (uint8_t*)&i_pHomer->qpmrRegion,
                              i_debugMode );

    do
    {
        if( !i_imgType.sgpeCommonRingBuild )
        {
            break;
        }

        if( !i_pOverride )
        {
            break;
        }

        uint32_t commonRingLength = i_qpmrHdr.quadCommonRingLength;

        //Start override ring from the actual end of base common rings. Remeber overrides reside within area
        //earmarked for common rings
        uint8_t* pOverrideStart =
            &i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[commonRingLength + SWIZZLE_4_BYTE(i_qpmrHdr.sgpeImgLength)];
        uint16_t*  pScanRingIndex = (uint16_t*)pOverrideStart;

        //get core common rings
        uint8_t* pOvrdRingPayload = pOverrideStart + QUAD_COMMON_RING_INDEX_SIZE;
        uint32_t tempRingLength = 0;
        uint32_t tempBufSize = 0;
        bool overrideNotFound = true;
        uint32_t ringStartToHdrOffset = ( TOR_VER_ONE == P9_TOR::tor_version() ) ? RING_START_TO_RS4_OFFSET : 0;
        FAPI_DBG("TOR Version :  0x%02x", P9_TOR::tor_version() );

        for( uint32_t ringIndex = 0; ringIndex < MAX_HOMER_QUAD_CMN_RINGS;
             ringIndex++ )
        {
            tempBufSize = i_ringData.iv_sizeWorkBuf1;

            FAPI_DBG("Calling P9_TOR::tor_get_single_ring ring 0x%08X", ringIndex);
            rc = tor_get_single_ring( i_pOverride,
                                      P9_XIP_MAGIC_SEEPROM,
                                      i_chipState.getChipLevel(),
                                      sgpeOvrdRings.getCommonRingId( ringIndex ),
                                      P9_TOR::SBE,
                                      OVERRIDE,
                                      CACHE0_CHIPLET_ID,
                                      &i_ringData.iv_pWorkBuf2,
                                      tempBufSize,
                                      i_debugMode );

            if( (i_ringData.iv_sizeWorkBuf2 == tempBufSize) || (0 == tempBufSize ) ||
                ( 0 != rc ) )
            {
                tempBufSize = 0;
                continue;
            }

            overrideNotFound = false;
            ALIGN_DWORD(tempRingLength, tempBufSize)
            ALIGN_RING_LOC( pOverrideStart, pOvrdRingPayload );


            memcpy( pOvrdRingPayload, i_ringData.iv_pWorkBuf2, tempBufSize);
            *(pScanRingIndex + ringIndex) = SWIZZLE_2_BYTE((pOvrdRingPayload - pOverrideStart) + ringStartToHdrOffset);

            sgpeOvrdRings.setRingOffset(pOvrdRingPayload, sgpeOvrdRings.getCommonRingId( ringIndex ));
            sgpeOvrdRings.setRingSize( sgpeOvrdRings.getCommonRingId( ringIndex ), tempBufSize );
            sgpeOvrdRings.extractRing( i_ringData.iv_pWorkBuf2, tempBufSize, sgpeOvrdRings.getCommonRingId( ringIndex ) );

            pOvrdRingPayload = pOvrdRingPayload + tempBufSize;

            //cleaning up what we wrote in temp buffer last time
            memset( i_ringData.iv_pWorkBuf2, 0x00, tempBufSize );
        }

        if( overrideNotFound )
        {
            FAPI_INF("Overrides not found for SGPE");
            rc = BUILD_FAIL_OVERRIDE;   // Not considered an error
            break;
        }

        tempRingLength = (pOvrdRingPayload - pOverrideStart );
        pSgpeImgHdr->g_sgpe_cmn_ring_ovrd_occ_offset =
            SWIZZLE_4_BYTE(pSgpeImgHdr->g_sgpe_cmn_ring_occ_offset) + commonRingLength;
        i_qpmrHdr.quadCommonRingLength = commonRingLength + tempRingLength;
        i_qpmrHdr.quadCommonOvrdLength = tempRingLength;
        i_qpmrHdr.quadCommonOvrdOffset = i_qpmrHdr.quadCommonRingOffset + commonRingLength;
        pSgpeImgHdr->g_sgpe_cmn_ring_ovrd_occ_offset = SWIZZLE_4_BYTE(pSgpeImgHdr->g_sgpe_cmn_ring_ovrd_occ_offset);

    }
    while(0);

    FAPI_DBG("--------------------SGPE Override Rings---------------=" );
    FAPI_DBG("--------------------SGPE Header --------------------====");
    FAPI_DBG("Override Ring Offset 0x%08X", SWIZZLE_4_BYTE(pSgpeImgHdr->g_sgpe_cmn_ring_ovrd_occ_offset));

    sgpeOvrdRings.dumpOverrideRings();

    FAPI_INF("< layoutSgpeScanOverride")
    return rc;
}

/**
 * @brief   update fields of PGPE image header region with parameter block info.
 * @param   i_pHomer    points to start of chip's HOMER.
 */


void updatePgpeHeader( void* const i_pHomer )
{
    FAPI_DBG("> updatePgpeHeader");
    Homerlayout_t* pHomerLayout = (Homerlayout_t*)i_pHomer;
    PgpeHeader_t*  pPgpeHdr = (PgpeHeader_t*)&pHomerLayout->ppmrRegion.pgpeSramImage[PGPE_INT_VECTOR_SIZE];
    PpmrHeader_t* pPpmrHdr = ( PpmrHeader_t* ) pHomerLayout->ppmrRegion.ppmrHeader;

    //Updating PGPE Image Header
    pPgpeHdr->g_pgpe_ivpr_addr                    =     OCC_SRAM_PGPE_BASE_ADDR;

    //Global P-State Parameter Block SRAM address
    pPgpeHdr->g_pgpe_gppb_sram_addr               =     0;      // set by PGPE Hcode

    //PGPE Hcode length
    pPgpeHdr->g_pgpe_hcode_length                 =     SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_hcode_length);

    //Global P-State Parameter Block HOMER address
    pPgpeHdr->g_pgpe_gppb_mem_offset              =     (HOMER_PPMR_BASE_ADDR |
            (SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_gppb_offset)));

    //Global P-State Parameter Block length
    pPgpeHdr->g_pgpe_gppb_length                  =     SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_gppb_length);

    //P-State Parameter Block HOMER offset
    pPgpeHdr->g_pgpe_gen_pstables_mem_offset      =     (HOMER_PPMR_BASE_ADDR |
            (SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_pstables_offset)));

    //P-State Table length
    pPgpeHdr->g_pgpe_gen_pstables_length          =     SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_pstables_length);

    //OCC P-State Table SRAM address
    pPgpeHdr->g_pgpe_occ_pstables_sram_addr       =     0;

    //OCC P-State Table Length
    pPgpeHdr->g_pgpe_occ_pstables_len             =     0;

    //PGPE Beacon SRAM address
    pPgpeHdr->g_pgpe_beacon_addr                  =     0;
    pPgpeHdr->g_quad_status_addr                  =     0;
    pPgpeHdr->g_pgpe_wof_state_address            =     0;
    pPgpeHdr->g_pgpe_req_active_quad_address      =     0;
    pPgpeHdr->g_wof_table_addr                    =     0;
    pPgpeHdr->g_wof_table_length                  =     0;

    //Finally handling the endianess
    pPgpeHdr->g_pgpe_gppb_sram_addr                 =   SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_gppb_sram_addr);
    pPgpeHdr->g_pgpe_hcode_length                   =   SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_hcode_length);
    pPgpeHdr->g_pgpe_gppb_mem_offset                =   SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_gppb_mem_offset);
    pPgpeHdr->g_pgpe_gppb_length                    =   SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_gppb_length);
    pPgpeHdr->g_pgpe_gen_pstables_mem_offset        =   SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_gen_pstables_mem_offset);
    pPgpeHdr->g_pgpe_gen_pstables_length            =   SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_gen_pstables_length);
    pPgpeHdr->g_pgpe_occ_pstables_sram_addr         =   SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_occ_pstables_sram_addr);
    pPgpeHdr->g_pgpe_occ_pstables_len               =   SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_occ_pstables_len);
    pPgpeHdr->g_pgpe_beacon_addr                    =   SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_beacon_addr);
    pPgpeHdr->g_quad_status_addr                    =   SWIZZLE_4_BYTE(pPgpeHdr->g_quad_status_addr);
    pPgpeHdr->g_wof_table_addr                      =   SWIZZLE_4_BYTE(pPgpeHdr->g_wof_table_addr);
    pPgpeHdr->g_wof_table_length                    =   SWIZZLE_4_BYTE(pPgpeHdr->g_wof_table_length);

    FAPI_DBG("================================PGPE Image Header==========================================")
    FAPI_DBG("Hcode Length              :       0x%08x", SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_gppb_length));
    FAPI_DBG("GPPB SRAM                 :       0x%08x", SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_gppb_sram_addr));
    FAPI_DBG("GPPB Mem Offset           :       0x%08x", SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_gppb_mem_offset));
    FAPI_DBG("GPPB Length               :       0x%08x", SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_gppb_length));
    FAPI_DBG("PS Table Mem Offset       :       0x%08x", SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_gen_pstables_mem_offset));
    FAPI_DBG("PS Table Length           :       0x%08x", SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_gen_pstables_length));
    FAPI_DBG("OCC PST SRAM              :       0x%08x", SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_occ_pstables_sram_addr));
    FAPI_DBG("OCC PST Length            :       0x%08x", SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_occ_pstables_len));
    FAPI_DBG("Beacon  Offset            :       0x%08x", SWIZZLE_4_BYTE(pPgpeHdr->g_pgpe_beacon_addr));
    FAPI_DBG("Quad Status               :       0x%08x", SWIZZLE_4_BYTE(pPgpeHdr->g_quad_status_addr));
    FAPI_DBG("WOF Addr                  :       0x%08x", SWIZZLE_4_BYTE(pPgpeHdr->g_wof_table_addr));
    FAPI_DBG("WOF Length                :       0x%08x", SWIZZLE_4_BYTE(pPgpeHdr->g_wof_table_length));
    FAPI_DBG("==============================PGPE Image Header End========================================")

    FAPI_DBG("< updatePgpeHeader");
}

//---------------------------------------------------------------------------

void updatePpmrHeader( void* const i_pHomer, PpmrHeader_t& io_ppmrHdr )
{
    FAPI_DBG("> updatePpmrHeader");
    Homerlayout_t* pHomerLayout = (Homerlayout_t*)i_pHomer;
    PpmrHeader_t*  pPpmrHdr = (PpmrHeader_t*) &pHomerLayout->ppmrRegion.ppmrHeader;
    memcpy( pPpmrHdr, &io_ppmrHdr, sizeof(PpmrHeader_t) );

    FAPI_DBG("=========================== PPMR Header  ====================================" );
    FAPI_DBG("BC Offset             :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_bc_offset));
    FAPI_DBG("BL Offset             :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_bl_offset));
    FAPI_DBG("BL Length             :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_bl_length));
    FAPI_DBG("Hcode Offset          :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_hcode_offset));
    FAPI_DBG("Hcode Length          :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_hcode_length));
    FAPI_DBG("GPPB Offset           :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_gppb_offset));
    FAPI_DBG("GPPB Length           :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_gppb_length));
    FAPI_DBG("LPPB Offset           :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_lppb_offset));
    FAPI_DBG("LPPB Length           :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_lppb_length));
    FAPI_DBG("OPPB Offset           :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_oppb_offset));
    FAPI_DBG("OPPB Length           :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_oppb_length));
    FAPI_DBG("PS Table Offset       :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_pstables_offset));
    FAPI_DBG("PS Table Length       :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_pstables_length));
    FAPI_DBG("PSGPE SRAM Size       :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_pgpe_sram_img_size));
    FAPI_DBG("WOF Table Offset      :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_wof_table_offset));
    FAPI_DBG("WOF Table End         :    0x%08x", SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_wof_table_length));
    FAPI_DBG("=========================== PPMR Header ends ==================================" );

    updatePgpeHeader( i_pHomer );

    FAPI_DBG("< updatePpmrHeader");
}

//---------------------------------------------------------------------------

/**
 * @brief   updates the PState parameter block info in CPMR and PPMR region.
 * @param   i_pHomer    points to start of of chip's HOMER.
 * @param   i_procTgt   fapi2 target associated with P9 chip.
 * @param   i_imgType   image type to be built.
 * return   fapi2::Returncode
 */
fapi2::ReturnCode buildParameterBlock( void* const i_pHomer, CONST_FAPI2_PROC& i_procTgt,
                                       PpmrHeader_t& io_ppmrHdr, ImageType_t i_imgType,
                                       void * const i_pBuf1, uint32_t i_sizeBuf1 )
{
    FAPI_INF("buildParameterBlock entered");

    do
    {
        if( !i_imgType.pgpePstateParmBlockBuild )
        {
            break;
        }

        fapi2::ReturnCode retCode;
        Homerlayout_t* pHomerLayout = (Homerlayout_t*)i_pHomer;
        PPMRLayout_t*  pPpmr = (PPMRLayout_t*) &pHomerLayout->ppmrRegion;
        cmeHeader_t* pCmeHdr = (cmeHeader_t*) &pHomerLayout->cpmrRegion.cmeSramRegion[CME_INT_VECTOR_SIZE];

        uint32_t ppmrRunningOffset = SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_hcode_offset) +
                                     SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_hcode_length);

        FAPI_DBG("Hcode ppmrRunningOffset 0x%08x", ppmrRunningOffset );

        uint32_t pgpeRunningOffset = SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_hcode_length);

        FAPI_DBG(" PGPE Hcode End 0x%08x", pgpeRunningOffset );

        uint32_t sizeAligned = 0;
        uint32_t sizePStateBlock = 0;
        uint32_t wofTableSize = i_sizeBuf1;
        PstateSuperStructure pStateSupStruct;
        memset( &pStateSupStruct, 0x00, sizeof(PstateSuperStructure) );
        memset(i_pBuf1,0x00,i_sizeBuf1);

        //Building P-State Parameter block info by calling a HWP
        FAPI_DBG("Generating P-State Parameter Block" );
        FAPI_EXEC_HWP( retCode, p9_pstate_parameter_block, i_procTgt,
                       &pStateSupStruct, (uint8_t*)i_pBuf1, wofTableSize );
        FAPI_TRY(retCode);

        //Check if WOF Table is copied properly
        FAPI_ASSERT( ( wofTableSize <= OCC_WOF_TABLES_SIZE ),
                     fapi2::PARAM_WOF_TABLE_SIZE_ERR()
                     .set_ACTUAL_WOF_TABLE_SIZE(wofTableSize)
                     .set_MAX_SIZE_ALLOCATED(OCC_WOF_TABLES_SIZE),
                     "Size of WOF Table Exceeds Max Size Allowed" );

        //-------------------------- Local P-State Parameter Block ------------------------------

        uint32_t localPspbStartIndex = SWIZZLE_4_BYTE(pCmeHdr->g_cme_hcode_length);
        uint8_t* pLocalPState = &pHomerLayout->cpmrRegion.cmeSramRegion[localPspbStartIndex];

        sizePStateBlock = sizeof(LocalPstateParmBlock);

        //Note: Not checking size here. Once entire CME Image layout is complete, there is a
        //size check at last. WE are safe as long as everthing put together doesn't exceed
        //maximum SRAM image size allowed(32KB). No need to check size of Local P-State
        //parameter block individually.

        FAPI_DBG("Copying Local P-State Parameter Block into CPMR" );
        memcpy( pLocalPState, &pStateSupStruct.localppb, sizePStateBlock );

        ALIGN_DBWORD( sizeAligned, sizePStateBlock )
        uint32_t localPStateBlock = sizeAligned;
        FAPI_DBG("LPSPB Actual size 0x%08x After Alignment 0x%08x", sizePStateBlock, sizeAligned  );

        pCmeHdr->g_cme_pstate_region_length = localPStateBlock;
        pCmeHdr->g_cme_common_ring_offset  = SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_offset) + localPStateBlock;

        //-------------------------- Local P-State Parameter Block Ends --------------------------

        //-------------------------- Global P-State Parameter Block ------------------------------

        FAPI_DBG("Copying Global P-State Parameter Block" );
        sizePStateBlock = sizeof(GlobalPstateParmBlock);

        FAPI_ASSERT( ( sizePStateBlock <= PGPE_PSTATE_OUTPUT_TABLES_SIZE ),
                     fapi2::PARAM_BLOCK_SIZE_ERR()
                     .set_SUPER_STRUCT_SIZE(sizeof(PstateSuperStructure))
                     .set_MAX_SIZE_ALLOCATED(PGPE_PSTATE_OUTPUT_TABLES_SIZE)
                     .set_ACTUAL_SIZE( sizePStateBlock ),
                     "Size of Global Parameter Block Exceeds Max Size Allowed" );

        FAPI_DBG("GPPBB pgpeRunningOffset 0x%08x", pgpeRunningOffset );
        memcpy( &pPpmr->pgpeSramImage[pgpeRunningOffset], &pStateSupStruct.globalppb, sizePStateBlock );

        ALIGN_DBWORD( sizeAligned, sizePStateBlock )
        FAPI_DBG("GPSPB Actual size 0x%08x After Alignment 0x%08x", sizePStateBlock, sizeAligned  );

        //Updating PPMR header info with GPSPB offset and length
        io_ppmrHdr.g_ppmr_gppb_offset =  ppmrRunningOffset;
        io_ppmrHdr.g_ppmr_gppb_length =  sizeAligned;

        ppmrRunningOffset += sizeAligned;
        pgpeRunningOffset += sizeAligned;
        FAPI_DBG("OPPB pgpeRunningOffset 0x%08x OPPB ppmrRunningOffset 0x%08x",
                 pgpeRunningOffset, ppmrRunningOffset );

        //------------------------------ Global P-State Parameter Block Ends ----------------------

        //------------------------------ OCC P-State Parameter Block ------------------------------

        FAPI_INF("Copying OCC P-State Parameter Block" );
        sizePStateBlock = sizeof(OCCPstateParmBlock);
        ALIGN_DBWORD( sizeAligned, sizePStateBlock )

        FAPI_DBG("OPPB size 0x%08x (%d)", sizeAligned, sizeAligned );
        FAPI_DBG("OPSPB Actual size = 0x%08x (%d);  After Alignment = 0x%08x (%d)",
                 sizePStateBlock, sizePStateBlock,
                 sizeAligned, sizeAligned );

        FAPI_ASSERT( ( sizePStateBlock <= OCC_PSTATE_PARAM_BLOCK_SIZE ),
                     fapi2::PARAM_BLOCK_SIZE_ERR()
                     .set_SUPER_STRUCT_SIZE(sizeof(OCCPstateParmBlock))
                     .set_MAX_SIZE_ALLOCATED(PGPE_PSTATE_OUTPUT_TABLES_SIZE)
                     .set_ACTUAL_SIZE( sizePStateBlock ),
                     "Size of OCC Parameter Block Exceeds Max Size Allowed" );

        //  The PPMR offset is from the begining --- which is the ppmrHeader
        io_ppmrHdr.g_ppmr_oppb_offset = pPpmr->occParmBlock - pPpmr->ppmrHeader;
        io_ppmrHdr.g_ppmr_oppb_length = sizeAligned;
        FAPI_DBG("OPPB ppmrRunningOffset 0x%08x", io_ppmrHdr.g_ppmr_oppb_offset);

        memcpy( &pPpmr->occParmBlock, &pStateSupStruct.occppb, sizePStateBlock );

        //-------------------------- OCC P-State Parameter Block Ends ------------------------------

        io_ppmrHdr.g_ppmr_lppb_offset  =  CPMR_HOMER_OFFSET + CME_IMAGE_CPMR_OFFSET + localPspbStartIndex;
        io_ppmrHdr.g_ppmr_lppb_length  =  localPStateBlock;

        //------------------------------ OCC P-State Table Allocation ------------------------------

        //  The PPMR offset is from the begining --- which is the ppmrHeader
        io_ppmrHdr.g_ppmr_pstables_offset    =   pPpmr->pstateTable - pPpmr->ppmrHeader;;
        io_ppmrHdr.g_ppmr_pstables_length    =   sizeof(GeneratedPstateInfo);

        //------------------------------ Copying WOF Table ----------------------------------------------

        io_ppmrHdr.g_ppmr_wof_table_offset  =   OCC_WOF_TABLES_PPMR_OFFSET;
        io_ppmrHdr.g_ppmr_wof_table_length  =   OCC_WOF_TABLES_SIZE;

        memcpy( &pPpmr->wofTableSize, i_pBuf1, wofTableSize );

        //------------------------------ Copying WOF Table ----------------------------------------------

        //------------------------------ Calculating total PGPE Image Size in SRAM ----------------------

        io_ppmrHdr.g_ppmr_pgpe_sram_img_size =  SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_hcode_length) +
                                                io_ppmrHdr.g_ppmr_gppb_length;

        FAPI_DBG("OPPB pgpeRunningOffset 0x%08x io_ppmrHdr.g_ppmr_pgpe_sram_img_size 0x%08x",
                 pgpeRunningOffset, io_ppmrHdr.g_ppmr_pgpe_sram_img_size );

        //Finally let us handle endianess
        //CME Header
        pCmeHdr->g_cme_pstate_region_length  =   SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_length);
        pCmeHdr->g_cme_common_ring_offset    = SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_offset);

        //PPMR Header
        io_ppmrHdr.g_ppmr_gppb_offset        =   SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_gppb_offset);
        io_ppmrHdr.g_ppmr_gppb_length        =   SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_gppb_length);
        io_ppmrHdr.g_ppmr_oppb_offset        =   SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_oppb_offset);
        io_ppmrHdr.g_ppmr_oppb_length        =   SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_oppb_length);
        io_ppmrHdr.g_ppmr_lppb_offset        =   SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_lppb_offset);
        io_ppmrHdr.g_ppmr_lppb_length        =   SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_lppb_length);
        io_ppmrHdr.g_ppmr_pstables_offset    =   SWIZZLE_4_BYTE( io_ppmrHdr.g_ppmr_pstables_offset);
        io_ppmrHdr.g_ppmr_pstables_length    =   SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_pstables_length);
        io_ppmrHdr.g_ppmr_pgpe_sram_img_size =   SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_pgpe_sram_img_size);
        io_ppmrHdr.g_ppmr_wof_table_offset   =   SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_wof_table_offset);
        io_ppmrHdr.g_ppmr_wof_table_length   =   SWIZZLE_4_BYTE(io_ppmrHdr.g_ppmr_wof_table_length);
    }
    while(0);

fapi_try_exit:
    FAPI_INF("buildParameterBlock exit");

    return fapi2::current_err;
}

//---------------------------------------------------------------------------

/**
 * @brief   copies override flavor of scan rings
 * @param   i_pImageIn          points to start of hardware image.
 * @param   i_pOverride         points to override rings.
 * @param   o_pImageOut         points to HOMER image.
 * @param   i_ddLevel           dd level associated with P9 chip.
 * @param   i_pBuf1             work buffer1
 * @param   i_bufSize1          work buffer1 size.
 * @param   i_pBuf2             work buffer2
 * @param   i_bufSize2          work buffer2 size.
 * @param   i_imgType           image type to be built.
 * @param   o_qpmr              temp instance of QpmrHeaderLayout_t
 * @param   i_platId            platform associated with scan ring.
 * @return  IMG_BUILD_SUCCESS if successful else error code.
 */
uint32_t layoutCmnRingsForCme( Homerlayout_t*   i_pHomer,
                               const P9FuncModel& i_chipState,
                               RingBufData& i_ringData,
                               RingDebugMode_t i_debugMode,
                               RingVariant_t i_ringVariant,
                               ImageType_t i_imgType,
                               RingBucket& io_cmeRings,
                               uint32_t& io_cmnRingSize )
{
    FAPI_DBG( "> layoutCmnRingsForCme");
    uint32_t rc = IMG_BUILD_SUCCESS;

    do
    {

        uint32_t tempSize = 0;
        uint32_t ringSize = 0;
        uint8_t* pRingStart = &i_pHomer->cpmrRegion.cmeSramRegion[io_cmnRingSize];
        uint16_t* pScanRingIndex = (uint16_t*) pRingStart;
        uint8_t* pRingPayload = pRingStart + CORE_COMMON_RING_INDEX_SIZE;
        uint32_t ringStartToHdrOffset = ( TOR_VER_ONE == P9_TOR::tor_version() ) ? RING_START_TO_RS4_OFFSET : 0;

        if( !i_imgType.cmeCommonRingBuild )
        {
            break;
        }

        for( uint32_t ringIndex = 0; ringIndex < MAX_HOMER_CORE_CMN_RINGS;
             ringIndex++ )
        {
            ringSize = i_ringData.iv_sizeWorkBuf1;
            rc = tor_get_single_ring( i_ringData.iv_pRingBuffer,
                                      P9_XIP_MAGIC_CME,
                                      i_chipState.getChipLevel(),
                                      io_cmeRings.getCommonRingId( ringIndex ),
                                      P9_TOR::CME,
                                      i_ringVariant,
                                      CORE0_CHIPLET_ID ,
                                      &i_ringData.iv_pWorkBuf1,
                                      ringSize,
                                      i_debugMode );

            if( ( i_ringData.iv_sizeWorkBuf1 == ringSize ) || ( 0 == ringSize ) ||
                ( 0 != rc ) )
            {
                FAPI_INF( "Did not find core common ring Id %d ", ringIndex );
                rc = 0;
                ringSize = 0;
                continue;
            }

            ALIGN_DWORD(tempSize, ringSize)
            ALIGN_RING_LOC( pRingStart, pRingPayload );

            memcpy( pRingPayload, i_ringData.iv_pWorkBuf1, ringSize );
            *(pScanRingIndex + ringIndex) = SWIZZLE_2_BYTE((pRingPayload - pRingStart) + ringStartToHdrOffset);


            io_cmeRings.setRingOffset( pRingPayload, io_cmeRings.getCommonRingId( ringIndex ));
            io_cmeRings.setRingSize( io_cmeRings.getCommonRingId( ringIndex ), ringSize );
            io_cmeRings.extractRing( i_ringData.iv_pWorkBuf1, ringSize, io_cmeRings.getCommonRingId( ringIndex ) );

            pRingPayload = pRingPayload + ringSize;

            //cleaning up what we wrote in temp buffer last time.
            memset( i_ringData.iv_pWorkBuf1, 0x00, ringSize );
        }

        ringSize = (pRingPayload - pRingStart);

        if( ringSize > CORE_COMMON_RING_INDEX_SIZE )
        {
            io_cmnRingSize += (pRingPayload - pRingStart);
            ALIGN_DWORD(tempSize, io_cmnRingSize)
        }
    }
    while(0);

    FAPI_DBG( "< layoutCmnRingsForCme");

    return rc;
}

//------------------------------------------------------------------------------
/**
 * @brief   creates a lean scan ring layout for core specific rings in HOMER.
 * @param   i_pHOMER        points to HOMER image.
 * @param   i_chipState     functional state of all cores within P9 chip
 * @param   i_ringData      scan ring related data
 * @param   i_debugMode     debug type set for scan rings
 * @param   i_ringVariant   scan ring flavor
 * @param   i_imgType       image type to be built
 * @param   io_cmeRings     instance of RingBucket
 * @param   io_ringLength   input: CME region length populated. Output: Max possible size of instance spec ring
 * @param   IMG_BUILD_SUCCESS   if function succeeds else error code.
 */

uint32_t layoutInstRingsForCme(    Homerlayout_t*   i_pHomer,
                                   const P9FuncModel& i_chipState,
                                   RingBufData& i_ringData,
                                   RingDebugMode_t i_debugMode,
                                   RingVariant_t i_ringVariant,
                                   ImageType_t i_imgType,
                                   RingBucket& io_cmeRings,
                                   uint32_t& io_ringLength )
{
    FAPI_DBG( "> layoutInstRingsForCme");
    uint32_t rc = IMG_BUILD_SUCCESS;
    // Let us find out ring-pair which is biggest in list of 12 ring pairs
    uint32_t maxCoreSpecRingLength = 0;
    uint32_t ringLength = 0;
    uint32_t tempSize = 0;
    uint32_t tempRepairLength = 0;
    uint32_t ringStartToHdrOffset = ( TOR_VER_ONE == P9_TOR::tor_version() ) ? RING_START_TO_RS4_OFFSET : 0;

    do
    {
        if( !i_imgType.cmeCoreSpecificRingBuild )
        {
            break;
        }

        for( uint32_t exId = 0; exId < MAX_CMES_PER_CHIP; exId++ )
        {
            if( !i_chipState.isExFunctional( exId ) )
            {
                FAPI_DBG( "ignoring ex %d for instance ring size consideration", exId);
                continue;
            }

            ringLength = 0;

            for( uint32_t coreId = 0; coreId < MAX_CORES_PER_EX; coreId++ )
            {
                if( !i_chipState.isCoreFunctional( ((2 * exId ) + coreId)) )
                {
                    FAPI_DBG( "ignoring core %d for instance ring size consideration", (2 * exId ) + coreId );
                    continue;
                }

                tempSize = i_ringData.iv_sizeWorkBuf1;
                rc = tor_get_single_ring( i_ringData.iv_pRingBuffer,
                                          P9_XIP_MAGIC_CME,
                                          i_chipState.getChipLevel(),
                                          io_cmeRings.getInstRingId(0),
                                          P9_TOR::CME,
                                          i_ringVariant,
                                          CORE0_CHIPLET_ID + ((2 * exId) + coreId),
                                          &i_ringData.iv_pWorkBuf1,
                                          tempSize,
                                          i_debugMode );

                if( (i_ringData.iv_sizeWorkBuf1 == tempSize) || (0 == tempSize ) ||
                    ( 0 != rc ) )
                {
                    FAPI_DBG( "could not determine size of ring id %d of core %d",
                              io_cmeRings.getInstRingId(0), ((2 * exId) + coreId) );
                    continue;
                }

                ALIGN_DWORD(tempRepairLength, tempSize);
                ringLength += tempSize;
            }

            maxCoreSpecRingLength = ringLength > maxCoreSpecRingLength ? ringLength : maxCoreSpecRingLength;
        }

        if( maxCoreSpecRingLength > 0 )
        {
            maxCoreSpecRingLength += sizeof(CoreSpecRingList_t);
            ROUND_OFF_32B(maxCoreSpecRingLength);
        }

        FAPI_DBG("Max Instance Spec Ring 0x%08X", maxCoreSpecRingLength);
        // Let us copy the rings now.

        uint8_t* pRingStart = NULL;
        uint8_t* pRingPayload = NULL;
        uint16_t* pScanRingIndex = NULL;

        for( uint32_t exId = 0; exId < MAX_CMES_PER_CHIP; exId++ )
        {
            pRingStart = (uint8_t*)&i_pHomer->cpmrRegion.cmeSramRegion[io_ringLength + ( exId * maxCoreSpecRingLength ) ];
            pRingPayload = pRingStart + sizeof(CoreSpecRingList_t);
            pScanRingIndex = (uint16_t*)pRingStart;

            if( !i_chipState.isExFunctional( exId ) )
            {
                FAPI_DBG("skipping copy of core specific rings of ex %d", exId);
                continue;
            }

            for( uint32_t coreId = 0; coreId < MAX_CORES_PER_EX; coreId++ )
            {
                if( !i_chipState.isCoreFunctional( ((2 * exId ) + coreId)) )
                {
                    FAPI_DBG( "ignoring core %d for instance ring size consideration", (2 * exId ) + coreId );
                    continue;
                }

                tempSize = i_ringData.iv_sizeWorkBuf1;
                rc = tor_get_single_ring( i_ringData.iv_pRingBuffer,
                                          P9_XIP_MAGIC_CME,
                                          i_chipState.getChipLevel(),
                                          io_cmeRings.getInstRingId(0),
                                          P9_TOR::CME,
                                          i_ringVariant,
                                          CORE0_CHIPLET_ID + ((2 * exId) + coreId),
                                          &i_ringData.iv_pWorkBuf1,
                                          tempSize,
                                          i_debugMode );

                if( (i_ringData.iv_sizeWorkBuf1 == tempSize) || (0 == tempSize ) ||
                    ( 0 != rc ) )
                {
                    FAPI_INF("Instance ring Id %d not found for EX %d core %d",
                             io_cmeRings.getInstRingId(0), exId, coreId );
                    rc = 0;
                    tempSize = 0;
                    continue;
                }

                ALIGN_RING_LOC( pRingStart, pRingPayload );
                memcpy( pRingPayload, i_ringData.iv_pWorkBuf1, tempSize);
                io_cmeRings.extractRing( i_ringData.iv_pWorkBuf1, tempSize, io_cmeRings.getInstRingId(0) );
                io_cmeRings.setRingOffset( pRingPayload,
                                           io_cmeRings.getInstRingId(0),
                                           ( MAX_CORES_PER_EX * exId ) + coreId );
                *(pScanRingIndex + coreId) = SWIZZLE_2_BYTE((pRingPayload - pRingStart ) + ringStartToHdrOffset);

                pRingPayload = pRingPayload + tempSize;
                io_cmeRings.setRingSize( io_cmeRings.getInstRingId(0), tempSize, ((MAX_CORES_PER_EX * exId) + coreId) );

                //cleaning up what we wrote in temp buffer last time.
                memset( i_ringData.iv_pWorkBuf1, 0x00, tempSize );
            }
        }

        io_ringLength = maxCoreSpecRingLength;
    }
    while(0);

    FAPI_DBG( "< layoutInstRingsForCme");

    return rc;
}

//------------------------------------------------------------------------------

uint32_t layoutCmeScanOverride( Homerlayout_t*   i_pHomer,
                                void* i_pOverride,
                                const P9FuncModel& i_chipState,
                                RingBufData& i_ringData,
                                RingDebugMode_t i_debugMode,
                                ImageType_t i_imgType,
                                uint32_t& io_ovrdRingLength )
{
    FAPI_INF("> layoutCmeScanOverride" );
    uint32_t rc = IMG_BUILD_SUCCESS;
    uint32_t tempRingLength = io_ovrdRingLength;
    uint32_t tempBufSize = 0;
    uint32_t ringStartToHdrOffset = ( TOR_VER_ONE == P9_TOR::tor_version() ) ? RING_START_TO_RS4_OFFSET : 0;

    RingBucket cmeOvrdRings( PLAT_CME,
                             (uint8_t*)&i_pHomer->cpmrRegion,
                             i_debugMode );

    do
    {
        if( !i_imgType.cmeCommonRingBuild )
        {
            break;
        }

        //Start override ring from the actual end of base common rings. Remember overrides reside within
        //common rings region
        uint8_t* pOverrideStart = &i_pHomer->cpmrRegion.cmeSramRegion[tempRingLength];
        uint16_t* pScanRingIndex = (uint16_t*)pOverrideStart;

        //get core common rings
        uint8_t* pOverrideRingPayload = pOverrideStart + CORE_COMMON_RING_INDEX_SIZE;
        bool overrideNotFound = true;

        for( uint8_t ringIndex = 0; ringIndex < MAX_HOMER_CORE_CMN_RINGS;
             ringIndex++ )
        {
            tempBufSize = i_ringData.iv_sizeWorkBuf2;

            FAPI_DBG("Calling P9_TOR::tor_get_single_ring ring 0x%08X", ringIndex);
            rc = tor_get_single_ring( i_pOverride,
                                      P9_XIP_MAGIC_SEEPROM,
                                      i_chipState.getChipLevel(),
                                      cmeOvrdRings.getCommonRingId( ringIndex ),
                                      P9_TOR::SBE,
                                      OVERRIDE,
                                      CORE0_CHIPLET_ID,
                                      &i_ringData.iv_pWorkBuf2,
                                      tempBufSize,
                                      i_debugMode );

            if( (i_ringData.iv_sizeWorkBuf2 == tempBufSize) || (0 == tempBufSize ) ||
                ( 0 != rc ) )

            {
                tempBufSize = 0;
                continue;
            }

            overrideNotFound = false;
            ALIGN_DWORD(tempRingLength, tempBufSize)
            ALIGN_RING_LOC( pOverrideStart, pOverrideRingPayload );

            memcpy( pOverrideRingPayload, i_ringData.iv_pWorkBuf2, tempBufSize);
            *(pScanRingIndex + ringIndex) = SWIZZLE_2_BYTE((pOverrideRingPayload - pOverrideStart) + ringStartToHdrOffset);

            cmeOvrdRings.setRingOffset(pOverrideRingPayload, cmeOvrdRings.getCommonRingId( ringIndex ));
            cmeOvrdRings.setRingSize( cmeOvrdRings.getCommonRingId( ringIndex ), tempBufSize );
            cmeOvrdRings.extractRing( i_ringData.iv_pWorkBuf2, tempBufSize, cmeOvrdRings.getCommonRingId( ringIndex ) );

            pOverrideRingPayload = pOverrideRingPayload + tempBufSize;

            //cleaning up what we wrote in temp bufffer last time.
            memset( i_ringData.iv_pWorkBuf2, 0x00, tempBufSize );
        }

        if( overrideNotFound )
        {
            FAPI_INF("Overrides not found for CME");
            rc = BUILD_FAIL_OVERRIDE;   // Not considered an error
            break;
        }

        io_ovrdRingLength += (pOverrideRingPayload - pOverrideStart );
        ALIGN_DWORD(tempRingLength, io_ovrdRingLength)

        FAPI_DBG( "Override Ring Length 0x%08X", io_ovrdRingLength );
    }
    while(0);

    cmeOvrdRings.dumpOverrideRings();

    FAPI_INF("< layoutCmeScanOverride" );
    return rc;
}

//------------------------------------------------------------------------------

/**
 * @brief   creates a lean scan ring layout for core rings in HOMER.
 * @param   i_pHOMER        points to HOMER image.
 * @param   i_chipState     functional state of all cores within P9 chip
 * @param   i_ringData      processor target
 * @param   i_debugMode     debug mode type for scan rings
 * @param   i_riskLevel     IPL type
 * @param   i_imgType       image type to be built
 * @param   i_pOverride     points to override binary.
 * @param   IMG_BUILD_SUCCESS   if function succeeds else error code.
 */
uint32_t layoutRingsForCME( Homerlayout_t*   i_pHomer,
                            const P9FuncModel& i_chipState,
                            RingBufData& i_ringData,
                            RingDebugMode_t i_debugMode,
                            uint32_t i_riskLevel,
                            ImageType_t i_imgType,
                            void* i_pOverride )
{
    FAPI_DBG( "> layoutRingsForCME");
    uint32_t rc = IMG_BUILD_SUCCESS;
    uint32_t ringLength = 0;
    uint32_t tempLength = 0;
    RingVariant_t l_ringVariant = BASE;
    cmeHeader_t* pCmeHdr = (cmeHeader_t*) &i_pHomer->cpmrRegion.cmeSramRegion[CME_INT_VECTOR_SIZE];
    RingBucket cmeRings( PLAT_CME,
                         (uint8_t*)&i_pHomer->cpmrRegion,
                         i_debugMode );

    do
    {
        if( !i_imgType.cmeCommonRingBuild )
        {
            break;
        }

        // get all the rings pertaining to CME in a work buffer first.
        if( i_riskLevel )
        {
            l_ringVariant = RL;
        }

        ringLength  =  SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_offset) + SWIZZLE_4_BYTE(
                           pCmeHdr->g_cme_pstate_region_length);
        //save the length where hcode ends
        tempLength  =  ringLength;

        layoutCmnRingsForCme( i_pHomer,
                              i_chipState,
                              i_ringData,
                              i_debugMode,
                              l_ringVariant,
                              i_imgType,
                              cmeRings,
                              ringLength );

        if( i_pOverride )
        {
            uint32_t temp = 0;
            uint32_t tempRc = 0;
            ALIGN_DWORD( temp, ringLength );
            temp = ringLength;

            tempRc = layoutCmeScanOverride( i_pHomer,
                                            i_pOverride,
                                            i_chipState,
                                            i_ringData,
                                            i_debugMode,
                                            i_imgType,
                                            ringLength );

            if( BUILD_FAIL_OVERRIDE == tempRc )
            {
                //found no core overrides
                pCmeHdr->g_cme_cmn_ring_ovrd_offset = 0;
            }
            else
            {
                pCmeHdr->g_cme_cmn_ring_ovrd_offset = temp;
            }
        }

        pCmeHdr->g_cme_common_ring_length = ringLength - tempLength; //cmn ring end - hcode end

        if( !pCmeHdr->g_cme_common_ring_length )
        {
            //No common ring , so force offset to be 0
            pCmeHdr->g_cme_common_ring_offset = 0;
        }

        tempLength = ringLength;
        tempLength = (( tempLength + CME_BLOCK_READ_LEN - 1 ) >> CME_BLK_SIZE_SHIFT ); //multiple of 32B
        ringLength = tempLength << CME_BLK_SIZE_SHIFT; //start position of instance rings

        layoutInstRingsForCme( i_pHomer,
                               i_chipState,
                               i_ringData,
                               i_debugMode,
                               BASE,           // VPD rings are always BASE
                               i_imgType,
                               cmeRings,
                               ringLength );

        if( ringLength )
        {
            pCmeHdr->g_cme_max_spec_ring_length     =
                ( ringLength + CME_BLOCK_READ_LEN - 1 ) >> CME_BLK_SIZE_SHIFT;
            pCmeHdr->g_cme_core_spec_ring_offset    =   tempLength;
        }

        //Let us handle endianess now
        pCmeHdr->g_cme_common_ring_length       =   SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_length);
        pCmeHdr->g_cme_core_spec_ring_offset    =   SWIZZLE_4_BYTE(pCmeHdr->g_cme_core_spec_ring_offset);
        pCmeHdr->g_cme_max_spec_ring_length     =   SWIZZLE_4_BYTE(pCmeHdr->g_cme_max_spec_ring_length);
        pCmeHdr->g_cme_cmn_ring_ovrd_offset     =   SWIZZLE_4_BYTE(pCmeHdr->g_cme_cmn_ring_ovrd_offset);
    }
    while(0);

    cmeRings.dumpRings();
    FAPI_DBG("CME Header Ring Details ");
    FAPI_DBG( "PS Offset %d (0x%08X)", SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_offset),
              SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_offset));
    FAPI_DBG("PS Lengtrh %d (0x%08X)", SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_length),
             SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_length) );
    FAPI_DBG("Common Ring Offset            %d (0x%08X) ", SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_offset),
             SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_offset));
    FAPI_DBG("Common Ring Length            %d (0x%08X) ", SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_length),
             SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_length));
    FAPI_DBG("Instance Ring Offset / 32     %d (0x%08X) ", SWIZZLE_4_BYTE(pCmeHdr->g_cme_core_spec_ring_offset),
             SWIZZLE_4_BYTE(pCmeHdr->g_cme_core_spec_ring_offset));
    FAPI_DBG("Instance Ring Length / 32     %d (0x%08X) ", SWIZZLE_4_BYTE(pCmeHdr->g_cme_max_spec_ring_length),

             SWIZZLE_4_BYTE(pCmeHdr->g_cme_max_spec_ring_length));

    FAPI_DBG( "< layoutRingsForCME");

    return rc;
}


//------------------------------------------------------------------------------

/**
 * @brief   selects the bucked id for EQ_INEX ring.
 * @param   o_bucketId bucket Id selected for eq_inex ring.
 * @return  fapi2 return code.
 */
fapi2::ReturnCode getSelectEqInexBucketAttr( uint32_t& o_bucketId )
{
    FAPI_DBG( "> getSelectEqInexBucketAttr");
    uint8_t l_fabAsyncSafeMode;
    uint8_t l_fabCoreFloorRatio;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_ASYNC_SAFE_MODE,
                           FAPI_SYSTEM,
                           l_fabAsyncSafeMode),
             "Error from FAPI_ATTR_GET for ATTR_PROC_FABRIC_ASYNC_SAFE_MODE");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CORE_FLOOR_RATIO,
                           FAPI_SYSTEM,
                           l_fabCoreFloorRatio),
             "Error from FAPI_ATTR_GET for ATTR_PROC_FABRIC_CORE_FLOOR_RATIO");


    if( fapi2::ENUM_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE_SAFE_MODE == l_fabAsyncSafeMode )
    {
        o_bucketId = EQ_INEX_BUCKET_1;
    }
    else
    {
        if ( fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_8_8 == l_fabCoreFloorRatio )
        {
            o_bucketId = EQ_INEX_BUCKET_4;
        }
        else if (( fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_7_8 == l_fabCoreFloorRatio ) ||
                 ( fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_6_8 == l_fabCoreFloorRatio ) ||
                 ( fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_5_8 == l_fabCoreFloorRatio ) ||
                 ( fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_4_8 == l_fabCoreFloorRatio ))
        {
            o_bucketId = EQ_INEX_BUCKET_3;
        }
        else if ( fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_2_8 == l_fabCoreFloorRatio )
        {
            o_bucketId = EQ_INEX_BUCKET_2;
        }
        else
        {
            o_bucketId = EQ_INEX_BUCKET_1;
        }
    }

    FAPI_DBG( "Safe Mode 0x%08x Fab Core Floor Ratio 0x%08x",
              l_fabAsyncSafeMode, l_fabCoreFloorRatio );

    FAPI_DBG( "< getSelectEqInexBucketAttr");
fapi_try_exit:
    return fapi2::current_err;
}

//------------------------------------------------------------------------------

/**
 * @brief   returns ringId based on bucket no. selcected for eq_inex ring.
 * @param   o_eqInexBucketId ring id for the selected bucket.
 * @return  IMG_BUILD_SUCCESS if success, error code otherwise.
 */

uint32_t resolveEqInexBucket( RingID& o_eqInexBucketId )
{
    uint32_t rc = IMG_BUILD_SUCCESS;
    fapi2::ReturnCode fapiRc ;
    uint32_t bucketId = 0;

    do
    {
        fapiRc = getSelectEqInexBucketAttr( bucketId );

        if( fapiRc )
        {
            rc = BUILD_FAIL_RING_SEL_EQ_INEX;
            break;
        }

        switch( bucketId )
        {
            case EQ_INEX_BUCKET_1:
                o_eqInexBucketId = eq_inex_bucket_1;
                break;

            case EQ_INEX_BUCKET_2:
                o_eqInexBucketId = eq_inex_bucket_2;
                break;

            case EQ_INEX_BUCKET_3:
                o_eqInexBucketId = eq_inex_bucket_3;
                break;

            case EQ_INEX_BUCKET_4:
                o_eqInexBucketId = eq_inex_bucket_4;
                break;
        }

        FAPI_DBG("Selected Bucket %x Ring Id %x",
                 bucketId + 1, (uint32_t)o_eqInexBucketId );
    }
    while(0);

    return rc;
}

//------------------------------------------------------------------------------

/**
 * @brief   creates a scan ring layout for quad common rings in HOMER.
 * @param   i_pHOMER        points to HOMER image.
 * @param   i_chipState     functional state of all cores within P9 chip
 * @param   i_ringData      contains ring buffers and respective sizes
 * @param   i_debugMode     scan ring debug state
 * @param   i_ringVariant   variant of the scan ring to be copied.
 * @param   io_qpmrHdr       instance of QPMR header.
 * @param   i_imgType       image type to be built
 * @param   io_sgpeRings    stores position and length of all quad common rings.
 * @param   IMG_BUILD_SUCCESS   if function succeeds else error code.
 */
uint32_t layoutCmnRingsForSgpe( Homerlayout_t*     i_pHomer,
                                const P9FuncModel& i_chipState,
                                RingBufData&       i_ringData,
                                RingDebugMode_t i_debugMode,
                                RingVariant_t i_ringVariant,
                                QpmrHeaderLayout_t& io_qpmrHdr,
                                ImageType_t i_imgType,
                                RingBucket& io_sgpeRings )
{
    FAPI_DBG("> layoutCmnRingsForSgpe");

    uint32_t rc = IMG_BUILD_SUCCESS;
    uint32_t sgpeHcodeSize      =   SWIZZLE_4_BYTE(io_qpmrHdr.sgpeImgLength);
    uint8_t* pCmnRingPayload    =   &i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[sgpeHcodeSize +
                                    QUAD_COMMON_RING_INDEX_SIZE];;
    uint16_t* pCmnRingIndex     =   (uint16_t*)&i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[sgpeHcodeSize];
    uint8_t* pRingStart         =   &i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[sgpeHcodeSize];
    uint32_t ringIndex          =   0;
    RingID torRingId;
    uint32_t tempLength         =   0;
    uint32_t tempBufSize        =   i_ringData.iv_sizeWorkBuf1;
    uint32_t ringStartToHdrOffset = ( TOR_VER_ONE == P9_TOR::tor_version() ) ? RING_START_TO_RS4_OFFSET : 0;

    RingBucket sgpeRings( PLAT_SGPE,
                          (uint8_t*)&i_pHomer->qpmrRegion,
                          i_debugMode );

    do
    {
        if( !i_imgType.sgpeCommonRingBuild )
        {
            break;
        }

        RingID eqInexBucketId;

        rc = resolveEqInexBucket( eqInexBucketId );

        if( rc )
        {
            break;
        }

        //get core common rings
        for( ; ringIndex < MAX_HOMER_QUAD_CMN_RINGS; ringIndex++ )
        {
            tempBufSize = i_ringData.iv_sizeWorkBuf1;

            //For eq_inex, request selected ring bucket else query
            //the ring that needs to be at this position in the layout.

            torRingId = (EQ_INEX_INDEX  == ringIndex) ? eqInexBucketId :
                        io_sgpeRings.getCommonRingId( ringIndex );

            rc = tor_get_single_ring( i_ringData.iv_pRingBuffer,
                                      P9_XIP_MAGIC_SGPE,
                                      i_chipState.getChipLevel(),
                                      torRingId,
                                      P9_TOR::SGPE,
                                      i_ringVariant,
                                      CACHE0_CHIPLET_ID,
                                      &i_ringData.iv_pWorkBuf1,
                                      tempBufSize,
                                      i_debugMode );

            if( (i_ringData.iv_sizeWorkBuf1 == tempBufSize) || (0 == tempBufSize ) ||
                ( 0 != rc ) )
            {
                FAPI_INF( "did not find quad common ring %d", ringIndex );
                rc = IMG_BUILD_SUCCESS;
                tempBufSize = 0;
                continue;
            }

            ALIGN_DWORD(tempLength, tempBufSize)
            ALIGN_RING_LOC( pRingStart, pCmnRingPayload );

            memcpy( pCmnRingPayload, i_ringData.iv_pWorkBuf1, tempBufSize);
            io_sgpeRings.setRingOffset( pCmnRingPayload, io_sgpeRings.getCommonRingId( ringIndex ) );
            *(pCmnRingIndex + ringIndex) = SWIZZLE_2_BYTE((pCmnRingPayload - pRingStart ) + ringStartToHdrOffset);
            io_sgpeRings.setRingSize( io_sgpeRings.getCommonRingId( ringIndex ), tempBufSize );
            io_sgpeRings.extractRing( i_ringData.iv_pWorkBuf1, tempBufSize, io_sgpeRings.getCommonRingId( ringIndex ) );
            pCmnRingPayload = pCmnRingPayload + tempBufSize;

            //cleaning up what we wrote in temp buffer last time.
            memset( i_ringData.iv_pWorkBuf1, 0x00, tempBufSize );

        }//for common rings

        tempLength = pCmnRingPayload - pRingStart;
        io_qpmrHdr.quadCommonRingLength          =   tempLength;
        io_qpmrHdr.quadCommonRingOffset          =   i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage -
                (uint8_t*)&i_pHomer->qpmrRegion;
        io_qpmrHdr.quadCommonRingOffset          +=  sgpeHcodeSize;
        FAPI_DBG("Quad Cmn Ring Length 0x%08X", io_qpmrHdr.quadCommonRingLength );

    }
    while(0);   //building common rings

    FAPI_DBG("< layoutCmnRingsForSgpe");

    return rc;
}

//------------------------------------------------------------------------------

/**
 * @brief   creates a scan ring layout for quad common rings in HOMER.
 * @param   i_pHOMER        points to HOMER image.
 * @param   i_chipState     functional state of all cores within P9 chip
 * @param   i_ringData      contains ring buffers and respective sizes
 * @param   i_debugMode     scan ring debug state
 * @param   i_ringVariant   variant of the scan ring to be copied.
 * @param   io_qpmrHdr       instance of QPMR header.
 * @param   i_imgType       image type to be built
 * @param   io_sgpeRings    stores position and length of all quad common rings.
 * @param   IMG_BUILD_SUCCESS   if function succeeds else error code.
 */
uint32_t layoutInstRingsForSgpe( Homerlayout_t*     i_pHomer,
                                 const P9FuncModel& i_chipState,
                                 RingBufData&       i_ringData,
                                 RingDebugMode_t i_debugMode,
                                 RingVariant_t i_ringVariant,
                                 QpmrHeaderLayout_t& io_qpmrHdr,
                                 ImageType_t i_imgType,
                                 RingBucket& io_sgpeRings )
{
    uint32_t rc = IMG_BUILD_SUCCESS;

    do
    {
        if( !i_imgType.sgpeCacheSpecificRingBuild )
        {
            break;
        }

        uint32_t quadSpecRingStart = SWIZZLE_4_BYTE(io_qpmrHdr.sgpeImgLength) + io_qpmrHdr.quadCommonRingLength;
        uint16_t* pCmnRingIndex   = (uint16_t*)&i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[ quadSpecRingStart ];
        uint8_t* pRingStart       = &i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[quadSpecRingStart];
        uint8_t* instRingPayLoad  = &i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[ quadSpecRingStart +
                                    QUAD_SPEC_RING_INDEX_LEN ];
        uint32_t ringStartToHdrOffset = ( TOR_VER_ONE == P9_TOR::tor_version() ) ? RING_START_TO_RS4_OFFSET : 0;

        for( uint32_t cacheInst = 0; cacheInst < MAX_QUADS_PER_CHIP; cacheInst++ )
        {
            if( !i_chipState.isQuadFunctional( cacheInst ) )
            {
                pCmnRingIndex = pCmnRingIndex + QUAD_SPEC_RING_INDEX_SIZE; // Jump to next Quad Index
                //Quad is not functional. Don't populate rings. Ring Index will be zero by design
                FAPI_INF("Skipping copy of cache chiplet%d", cacheInst);
                continue;
            }

            ExIdMap ExChipletRingMap;
            uint32_t chipletId = 0;
            uint32_t tempBufSize = 0;
            uint32_t tempLength = 0;

            for( uint32_t ringIndex = 0; ringIndex < EQ::g_eqData.iv_num_instance_rings_scan_addrs;
                 ringIndex++ )
            {
                tempBufSize = i_ringData.iv_sizeWorkBuf1;
                chipletId = ExChipletRingMap.getInstanceId( CACHE0_CHIPLET_ID + cacheInst , ringIndex );

                rc = tor_get_single_ring( i_ringData.iv_pRingBuffer,
                                          P9_XIP_MAGIC_SGPE,
                                          i_chipState.getChipLevel(),
                                          io_sgpeRings.getInstRingId( ringIndex ),
                                          P9_TOR::SGPE,
                                          i_ringVariant,
                                          chipletId,
                                          &i_ringData.iv_pWorkBuf1,
                                          tempBufSize,
                                          i_debugMode );

                if( (i_ringData.iv_sizeWorkBuf1 == tempBufSize) || (0 == tempBufSize ) ||
                    ( 0 != rc ) )
                {
                    FAPI_DBG( "did not find quad spec ring %d for cache Inst %d", ringIndex , cacheInst );
                    rc = 0;
                    tempBufSize = 0;
                    continue;
                }

                ALIGN_DWORD(tempLength, tempBufSize)
                ALIGN_RING_LOC( pRingStart, instRingPayLoad );

                memcpy( instRingPayLoad, i_ringData.iv_pWorkBuf1, tempBufSize);
                io_sgpeRings.setRingOffset( instRingPayLoad, io_sgpeRings.getInstRingId( ringIndex ), chipletId );
                *(pCmnRingIndex + ringIndex) = SWIZZLE_2_BYTE((instRingPayLoad - pRingStart ) + ringStartToHdrOffset);
                io_sgpeRings.setRingSize( io_sgpeRings.getInstRingId( ringIndex ), tempBufSize, chipletId );
                instRingPayLoad = instRingPayLoad + tempBufSize;
                io_sgpeRings.extractRing( i_ringData.iv_pWorkBuf1, tempBufSize, io_sgpeRings.getInstRingId( ringIndex ) );

                //cleaning up what we wrote in temp buffer last time.
                memset( i_ringData.iv_pWorkBuf1, 0x00, tempBufSize );

            }//for quad spec rings

            pCmnRingIndex = pCmnRingIndex + QUAD_SPEC_RING_INDEX_SIZE; // Jump to next Quad Index
        }

        io_qpmrHdr.quadSpecRingOffset                =   io_qpmrHdr.quadCommonRingOffset + io_qpmrHdr.quadCommonRingLength;
        io_qpmrHdr.quadSpecRingLength                =   (instRingPayLoad - pRingStart);
        FAPI_DBG("Instance Ring Length 0x%08X", io_qpmrHdr.quadSpecRingLength);
    }
    while(0);

    return rc;
}

//------------------------------------------------------------------------------

/**
 * @brief   creates a scan ring layout for quad common rings in HOMER.
 * @param   i_pHOMER        points to HOMER image.
 * @param   i_chipState     functional state of all cores within P9 chip
 * @param   i_ringData      contains ring buffers and respective sizes
 * @param   i_debugMode     scan ring debug state
 * @param   i_riskLevel     true if system IPL is in risk level mode else false.
 * @param   io_qpmrHdr      instance of QPMR header.
 * @param   i_imgType       image type to be built
 * @param   IMG_BUILD_SUCCESS   if function succeeds else error code.
 */
uint32_t layoutRingsForSGPE( Homerlayout_t*     i_pHomer,
                             void* i_pOverride,
                             const P9FuncModel& i_chipState,
                             RingBufData&       i_ringData,
                             RingDebugMode_t i_debugMode,
                             uint32_t i_riskLevel,
                             QpmrHeaderLayout_t& io_qpmrHdr,
                             ImageType_t i_imgType )
{
    FAPI_DBG( "> layoutRingsForSGPE");
    uint32_t rc = IMG_BUILD_SUCCESS;
    RingVariant_t l_ringVariant = BASE;
    sgpeHeader_t* pSgpeImgHdr   =   (sgpeHeader_t*)& i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECTOR_SIZE];
    RingBucket sgpeRings( PLAT_SGPE,
                          (uint8_t*)&i_pHomer->qpmrRegion,
                          i_debugMode );

    do
    {

        // get all the rings pertaining to CME in a work buffer first.
        if( i_riskLevel )
        {
            l_ringVariant = RL;
        }

        //Manage the Quad Common rings in HOMER
        layoutCmnRingsForSgpe( i_pHomer,
                               i_chipState,
                               i_ringData,
                               i_debugMode,
                               l_ringVariant,
                               io_qpmrHdr,
                               i_imgType,
                               sgpeRings );

        //Manage the Quad Override rings in HOMER
        layoutSgpeScanOverride( i_pHomer,
                                i_pOverride,
                                i_chipState,
                                i_ringData,
                                i_debugMode,
                                io_qpmrHdr,
                                i_imgType );

        //Manage the Quad specific rings in HOMER
        layoutInstRingsForSgpe( i_pHomer,
                                i_chipState,
                                i_ringData,
                                i_debugMode,
                                BASE,           // VPD rings are always BASE
                                io_qpmrHdr,
                                i_imgType,
                                sgpeRings );

        if( 0 == io_qpmrHdr.quadCommonRingLength )
        {
            //If quad common rings don't exist ensure its offset in image header  is zero
            pSgpeImgHdr->g_sgpe_cmn_ring_occ_offset = 0;
        }

        if( io_qpmrHdr.quadSpecRingLength > 0 )
        {
            pSgpeImgHdr->g_sgpe_spec_ring_occ_offset    =   io_qpmrHdr.quadCommonRingLength +
                    SWIZZLE_4_BYTE(io_qpmrHdr.sgpeImgLength);
            pSgpeImgHdr->g_sgpe_scom_offset             =
                SWIZZLE_4_BYTE(io_qpmrHdr.sgpeImgLength) + io_qpmrHdr.quadCommonRingLength +
                io_qpmrHdr.quadSpecRingLength;
        }
    }
    while(0);   //building instance rings

    //Let us handle endianes at last
    io_qpmrHdr.quadCommonRingOffset              =   SWIZZLE_4_BYTE(io_qpmrHdr.quadCommonRingOffset);
    io_qpmrHdr.quadCommonRingLength              =   SWIZZLE_4_BYTE(io_qpmrHdr.quadCommonRingLength);
    io_qpmrHdr.quadCommonOvrdOffset              =   SWIZZLE_4_BYTE(io_qpmrHdr.quadCommonOvrdOffset);
    io_qpmrHdr.quadCommonOvrdLength              =   SWIZZLE_4_BYTE(io_qpmrHdr.quadCommonOvrdLength);
    io_qpmrHdr.quadSpecRingOffset                =   SWIZZLE_4_BYTE(io_qpmrHdr.quadSpecRingOffset);
    io_qpmrHdr.quadSpecRingLength                =   SWIZZLE_4_BYTE(io_qpmrHdr.quadSpecRingLength);
    pSgpeImgHdr->g_sgpe_spec_ring_occ_offset     =   SWIZZLE_4_BYTE(pSgpeImgHdr->g_sgpe_spec_ring_occ_offset);
    pSgpeImgHdr->g_sgpe_scom_offset              =   SWIZZLE_4_BYTE(pSgpeImgHdr->g_sgpe_scom_offset);
    sgpeRings.dumpRings();

    FAPI_DBG("SGPE Header Ring Details ");
    FAPI_DBG("Common Ring Offset            %d (0x%08X) ",
             SWIZZLE_4_BYTE(pSgpeImgHdr->g_sgpe_cmn_ring_occ_offset),
             SWIZZLE_4_BYTE(pSgpeImgHdr->g_sgpe_cmn_ring_occ_offset));
    FAPI_DBG("Instance Ring Offset          %d (0x%08X) ",
             SWIZZLE_4_BYTE(pSgpeImgHdr->g_sgpe_spec_ring_occ_offset),
             SWIZZLE_4_BYTE(pSgpeImgHdr->g_sgpe_spec_ring_occ_offset));


    return rc;
}
//---------------------------------------------------------------------------
/**
 * @brief updates the IVPR attributes for SGPE, PGPE.
 * @brief   i_pChipHomer points to start of HOMER
 */
fapi2::ReturnCode updateGpeAttributes( Homerlayout_t* i_pChipHomer, CONST_FAPI2_PROC& i_procTgt )
{
    QpmrHeaderLayout_t* pQpmrHdr = (QpmrHeaderLayout_t*)i_pChipHomer->qpmrRegion.sgpeRegion.qpmrHeader;
    PpmrHeader_t* pPpmrHdr = (PpmrHeader_t*) i_pChipHomer->ppmrRegion.ppmrHeader;

    uint32_t attrVal = SWIZZLE_4_BYTE(pQpmrHdr->bootCopierOffset);
    attrVal |= (0x80000000 | ONE_MB);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_STOPGPE_BOOT_COPIER_IVPR_OFFSET,
                           i_procTgt,
                           attrVal ),
             "Error from FAPI_ATTR_SET for attribute ATTR_STOPGPE_BOOT_COPIER_IVPR_OFFSET");

    FAPI_DBG("Set ATTR_STOPGPE_BOOT_COPIER_IVPR_OFFSET to 0x%08X", attrVal );

    attrVal = SWIZZLE_4_BYTE(pPpmrHdr->g_ppmr_bc_offset);
    attrVal |= (0x80000000 | PPMR_HOMER_OFFSET);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PSTATEGPE_BOOT_COPIER_IVPR_OFFSET,
                           i_procTgt,
                           attrVal ),
             "Error from FAPI_ATTR_SET for attribute ATTR_PSTATEGPE_BOOT_COPIER_IVPR_OFFSET");

    FAPI_DBG("Set ATTR_PSTATEGPE_BOOT_COPIER_IVPR_OFFSET to 0x%08X", attrVal );

fapi_try_exit:
    return fapi2::current_err;
}

//---------------------------------------------------------------------------
/**
 * @brief Set the Fabric System, Group and Chip IDs into SGPE and CME headers
 * @brief   i_pChipHomer points to start of HOMER
 */
fapi2::ReturnCode setFabricIds( Homerlayout_t* i_pChipHomer, CONST_FAPI2_PROC& i_procTgt )
{

    uint32_t l_system_id;
    uint8_t  l_group_id;
    uint8_t  l_chip_id;
    fapi2::buffer<uint16_t> l_location_id = 0;
    uint16_t l_locationVal = 0;

    cmeHeader_t* pCmeHdr = (cmeHeader_t*) & i_pChipHomer->cpmrRegion.cmeSramRegion[CME_INT_VECTOR_SIZE];
    sgpeHeader_t* pSgpeHdr = (sgpeHeader_t*)& i_pChipHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECTOR_SIZE];

    FAPI_DBG(" ==================== Fabric IDs =================");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SYSTEM_ID,
                           i_procTgt,
                           l_system_id),
             "Error from FAPI_ATTR_GET for attribute ATTR_PROC_FABRIC_SYSTEM_ID");

    FAPI_DBG("Fabric System ID       :   0x%04X", l_system_id);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_GROUP_ID,
                           i_procTgt,
                           l_group_id),
             "Error from FAPI_ATTR_GET for attribute ATTR_PROC_FABRIC_GROUP_ID");

    FAPI_DBG("Fabric Group ID        :   0x%01X", l_group_id);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CHIP_ID,
                           i_procTgt,
                           l_chip_id),
             "Error from FAPI_ATTR_GET for attribute ATTR_PROC_FABRIC_CHIP_ID");

    FAPI_DBG("Fabric Chip ID         :   0x%01X", l_chip_id);

    // Create a unit16_t Location Ids in the form of:
    //    0:3    Group ID (loaded from ATTR_PROC_FABRIC_GROUP_ID)
    //    4:6    Chip ID (loaded from ATTR_PROC_FABRIC_CHIP_ID)
    //    7       0
    //    8:12   System ID (loaded from ATTR_PROC_FABRIC_SYSTEM_ID)
    //    13:15  00

    l_location_id.insert < 0, 4, 8 - 4,  uint8_t > ( l_group_id );
    l_location_id.insert < 4, 3, 8 - 3,  uint8_t > ( l_chip_id );
    l_location_id.insert < 8, 5, 32 - 5, uint32_t > ( l_system_id );

    FAPI_DBG("Location ID            :   0x%04X", l_location_id);

    l_location_id.extract<0, 16>(l_locationVal);
    // Populate the CME Header
    pCmeHdr->g_cme_location_id = SWIZZLE_2_BYTE(l_locationVal);

    // Populate the SGPE Header
    pSgpeHdr->g_sgpe_location_id = SWIZZLE_2_BYTE(l_locationVal);

fapi_try_exit:
    return fapi2::current_err;

}

//---------------------------------------------------------------------------------------------------

/**
 * @brief   populates EQ SCOM restore region of HOMER with SCOM restore value for NCU RNG BAR ENABLE.
 * @param   i_pChipHomer    points to start of P9 HOMER
 * @param   i_procTgt       fapi2 target for p9 chip.
 * @return  faip2 return code.
 */
fapi2::ReturnCode populateNcuRingBarScomReg( void* i_pChipHomer, CONST_FAPI2_PROC& i_procTgt )
{
    FAPI_DBG("> populateNcuRingBarScomReg");

    do
    {
        uint8_t  attrVal = 0;
        uint64_t nxRangeBarAddrOffset = 0;
        uint64_t regNcuRngBarData   = 0;
        uint64_t baseAddressNm0     = 0;
        uint64_t baseAddressNm1     = 0;
        uint64_t baseAddressMirror  = 0;
        uint32_t ncuBarRegisterAddr = 0;
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_BAR_ENABLE,
                               i_procTgt,
                               attrVal ),
                 "Error from FAPI_ATTR_GET for attribute ATTR_PROC_NX_RNG_BAR_ENABLE");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_BAR_BASE_ADDR_OFFSET,
                               FAPI_SYSTEM,
                               nxRangeBarAddrOffset ),
                 "Error from FAPI_ATTR_GET for attribute ATTR_PROC_NX_RNG_BAR_BASE_ADDR_OFFSET");

        FAPI_TRY(p9_fbc_utils_get_chip_base_address(i_procTgt,
                 EFF_FBC_GRP_CHIP_IDS,
                 baseAddressNm0,
                 baseAddressNm1,
                 baseAddressMirror,
                 regNcuRngBarData),
                 "Failed in p9_fbc_utils_get_chip_base_address" );


        if( fapi2::ENUM_ATTR_PROC_NX_RNG_BAR_ENABLE_ENABLE == attrVal )
        {
            //Set bit0 which corresponds to bit DARN_BAR_EN of reg NCU_DAR_BAR
            regNcuRngBarData |= DARN_BAR_EN_POS ;
        }

        regNcuRngBarData += nxRangeBarAddrOffset;

        for( uint32_t exIndex = 0; exIndex < MAX_CMES_PER_CHIP; exIndex++ )
        {
            ncuBarRegisterAddr = EX_0_NCU_DARN_BAR_REG;
            ncuBarRegisterAddr |= (( exIndex >> 1) << 24 );
            ncuBarRegisterAddr |= ( exIndex & 0x01 ) ? 0x0400 : 0x0000;

            FAPI_DBG("CME%d NCU_DARN_BAR Addr 0x%08x Data 0x%016lx ",
                     exIndex, ncuBarRegisterAddr, regNcuRngBarData );

            StopReturnCode_t stopRc =
                stopImageSection::p9_stop_save_scom( i_pChipHomer,
                        ncuBarRegisterAddr,
                        regNcuRngBarData ,
                        stopImageSection::P9_STOP_SCOM_REPLACE,
                        stopImageSection::P9_STOP_SECTION_EQ_SCOM );

            if( stopRc )
            {
                FAPI_ERR("Failed to update CME%d NCU_DARN_RNG_BAR Reg RC: 0x%08x",
                         exIndex, stopRc );
                break;
            }
        }

    }
    while(0);

    FAPI_DBG("< populateNcuRingBarScomReg");
fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------------------------

/**
 * @brief   populate L2 Epsilon SCOM register.
 * @param   i_pChipHomer    points to start of P9 HOMER.
 * @return  fapi2 return code.
 */
fapi2::ReturnCode populateEpsilonL2ScomReg( void*    i_pChipHomer )
{
    FAPI_DBG("> populateEpsilonL2ScomReg");

    do
    {
        uint32_t attrValT0 = 0;
        uint32_t attrValT1 = 0;
        uint32_t attrValT2 = 0;
        uint32_t scomAddr = 0;
        uint32_t rc = IMG_BUILD_SUCCESS;

        uint64_t l_epsilonScomVal;
        fapi2::buffer<uint64_t> epsilonValBuf;

        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

        //=============================================================================
        //Determine SCOM register data value for EX_L2_RD_EPS_REG by reading attributes
        //=============================================================================

        //----------------------------- Tier0(T0)--------------------------------------

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0,
                               FAPI_SYSTEM,
                               attrValT0 ),
                 "Error from FAPI_ATTR_GET for attribute ATTR_PROC_EPS_READ_CYCLES_T0");

        attrValT0 = attrValT0 / 8 / L2_EPS_DIVIDER + 1;
        epsilonValBuf.insert<0, 12, 20, uint32_t>( attrValT0 );

        //----------------------------- Tier1(T1)--------------------------------------

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1,
                               FAPI_SYSTEM,
                               attrValT1 ),
                 "Error from FAPI_ATTR_GET for attribute ATTR_PROC_EPS_READ_CYCLES_T1");

        attrValT1 = attrValT1 / 8 / L2_EPS_DIVIDER + 1;
        epsilonValBuf.insert<12, 12, 20, uint32_t>( attrValT1 );

        //----------------------------- Tier2(T2)--------------------------------------

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2,
                               FAPI_SYSTEM,
                               attrValT2 ),
                 "Error from FAPI_ATTR_GET for attribute ATTR_PROC_EPS_READ_CYCLES_T2");


        attrValT2 = attrValT2 / 8 / L2_EPS_DIVIDER + 1;
        epsilonValBuf.insert<24, 12, 20, uint32_t>( attrValT2 );

        epsilonValBuf.extract<0, 64>(l_epsilonScomVal);

        //----------------------- Updating SCOM Registers using STOP API --------------------
        uint32_t eqCnt = 0;

        for( ; eqCnt < MAX_QUADS_PER_CHIP; eqCnt++ )
        {
            scomAddr = (EX_L2_RD_EPS_REG | (eqCnt << QUAD_BIT_POS));
            rc = stopImageSection::p9_stop_save_scom( i_pChipHomer,
                    scomAddr,
                    l_epsilonScomVal,
                    stopImageSection::P9_STOP_SCOM_APPEND,
                    stopImageSection::P9_STOP_SECTION_EQ_SCOM );

            if( rc )
            {
                FAPI_DBG(" p9_stop_save_scom Failed rc 0x%08x", rc );
                break;
            }

            scomAddr |= ODD_EVEN_EX_POS;
            rc = stopImageSection::p9_stop_save_scom(   i_pChipHomer,
                    scomAddr,
                    l_epsilonScomVal,
                    stopImageSection::P9_STOP_SCOM_APPEND,
                    stopImageSection::P9_STOP_SECTION_EQ_SCOM );

            if( rc )
            {
                FAPI_DBG(" p9_stop_save_scom Failed rc 0x%08x", rc );
                break;
            }
        }

        //===============================================================================
        //Determine SCOM register data value for EX_L2_WR_EPS_REG by reading attributes
        //===============================================================================
        l_epsilonScomVal = 0;
        epsilonValBuf.flush<0>();

        //----------------------------- Tier1(T1)--------------------------------------

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1,
                               FAPI_SYSTEM,
                               attrValT1 ),
                 "Error from FAPI_ATTR_GET for attribute ATTR_PROC_EPS_WRITE_CYCLES_T1");

        attrValT1 = attrValT1 / 8 / L2_EPS_DIVIDER + 1;
        epsilonValBuf.insert< 0, 12, 20, uint32_t >(attrValT1);

        //----------------------------- Tier2(T2)--------------------------------------

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2,
                               FAPI_SYSTEM,
                               attrValT2 ),
                 "Error from FAPI_ATTR_GET for attribute ATTR_PROC_EPS_WRITE_CYCLES_T2");

        attrValT2 = attrValT2 / 8 / L2_EPS_DIVIDER + 1;
        epsilonValBuf.insert< 12, 12, 20, uint32_t >(attrValT2);

        // p9.l2.scom.inifile:
        // EPS_DIVIDER_MODE          = L2_EPS_DIVIDER
        // EPS_MODE_SEL              = 0
        // EPS_CNT_USE_L2_DIVIDER_EN = 0
        // L2_EPS_STEP_MODE          = 0000
        epsilonValBuf.insert<24, 4, 28, uint32_t>(L2_EPS_DIVIDER);

        epsilonValBuf.extract<0, 64>(l_epsilonScomVal);

        //----------------------- Updating SCOM Registers using STOP API --------------------

        for( eqCnt = 0; eqCnt < MAX_QUADS_PER_CHIP; eqCnt++ )
        {
            scomAddr = (EX_L2_WR_EPS_REG | (eqCnt << QUAD_BIT_POS));
            FAPI_DBG("Calling STOP API to update SCOM reg 0x%08x value 0x%016llx",
                     scomAddr, l_epsilonScomVal);

            rc = stopImageSection::p9_stop_save_scom(   i_pChipHomer,
                    scomAddr,
                    l_epsilonScomVal,
                    stopImageSection::P9_STOP_SCOM_APPEND,
                    stopImageSection::P9_STOP_SECTION_EQ_SCOM );

            if( rc )
            {
                FAPI_DBG(" p9_stop_save_scom Failed rc 0x%08x", rc );
                break;
            }

            scomAddr |= ODD_EVEN_EX_POS;
            FAPI_DBG("Calling STOP API to update SCOM reg 0x%08x value 0x%016llx",
                     scomAddr, l_epsilonScomVal);

            rc = stopImageSection::p9_stop_save_scom(   i_pChipHomer,
                    scomAddr,
                    l_epsilonScomVal,
                    stopImageSection::P9_STOP_SCOM_APPEND,
                    stopImageSection::P9_STOP_SECTION_EQ_SCOM );

            if( rc )
            {
                FAPI_DBG(" p9_stop_save_scom Failed rc 0x%08x", rc );
                break;
            }
        }

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rc ),
                     fapi2::EPSILON_SCOM_UPDATE_FAIL()
                     .set_STOP_API_SCOM_ERR( rc )
                     .set_EPSILON_REG_ADDR( scomAddr )
                     .set_EPSILON_REG_DATA( l_epsilonScomVal ),
                     "Failed to create restore entry for L2 Epsilon register" );

    }
    while(0);

    FAPI_DBG("< populateEpsilonL2ScomReg");
fapi_try_exit:
    return fapi2::current_err;
}

//---------------------------------------------------------------------------

/**
 * @brief   populate L3 Epsilon SCOM register.
 * @param   i_pChipHomer    points to start of P9 HOMER.
 * @return  fapi2 return code.
 */
fapi2::ReturnCode populateEpsilonL3ScomReg( void*    i_pChipHomer )
{
    FAPI_DBG("> populateEpsilonL3ScomReg");

    do
    {
        uint32_t attrValT0 = 0;
        uint32_t attrValT1 = 0;
        uint32_t attrValT2 = 0;
        uint32_t scomAddr = 0;
        uint32_t rc = IMG_BUILD_SUCCESS;
        uint64_t l_epsilonScomVal;
        fapi2::buffer<uint64_t> epsilonValBuf;

        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

        //=====================================================================================
        //Determine SCOM register data value for EX_L3_RD_EPSILON_CFG_REG by reading attributes
        //=====================================================================================

        //----------------------------- Tier0(T0)--------------------------------------

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0,
                               FAPI_SYSTEM,
                               attrValT0 ),
                 "Error from FAPI_ATTR_GET for attribute ATTR_PROC_EPS_READ_CYCLES_T0");

        attrValT0 = attrValT0 / 8 / L3_EPS_DIVIDER + 1;
        epsilonValBuf.insert<0, 12, 20, uint32_t>( attrValT0 );

        //----------------------------- Tier1(T1)--------------------------------------

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1,
                               FAPI_SYSTEM,
                               attrValT1 ),
                 "Error from FAPI_ATTR_GET for attribute ATTR_PROC_EPS_READ_CYCLES_T1");

        attrValT1 = attrValT1 / 8 / L3_EPS_DIVIDER + 1;
        epsilonValBuf.insert<12, 12, 20, uint32_t>( attrValT1 );

        //----------------------------- Tier2(T2)--------------------------------------

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2,
                               FAPI_SYSTEM,
                               attrValT2 ),
                 "Error from FAPI_ATTR_GET for attribute ATTR_PROC_EPS_READ_CYCLES_T2");

        attrValT2 = attrValT2 / 8 / L3_EPS_DIVIDER + 1;
        epsilonValBuf.insert<24, 12, 20, uint32_t>( attrValT2 );

        epsilonValBuf.extract<0, 64>(l_epsilonScomVal);

        //----------------------- Updating SCOM Registers using STOP API --------------------

        uint32_t eqCnt = 0;

        for( ; eqCnt < MAX_QUADS_PER_CHIP; eqCnt++ )
        {
            scomAddr = (EX_L3_RD_EPSILON_CFG_REG | (eqCnt << QUAD_BIT_POS));

            FAPI_DBG("Calling STOP API to update SCOM reg 0x%08x value 0x%016llx",
                     scomAddr, l_epsilonScomVal);
            rc = stopImageSection::p9_stop_save_scom( i_pChipHomer,
                    scomAddr,
                    l_epsilonScomVal,
                    stopImageSection::P9_STOP_SCOM_APPEND,
                    stopImageSection::P9_STOP_SECTION_EQ_SCOM );

            if( rc )
            {
                FAPI_DBG(" p9_stop_save_scom Failed rc 0x%08x", rc );
                break;
            }

            scomAddr |= ODD_EVEN_EX_POS;
            FAPI_DBG("Calling STOP API to update SCOM reg 0x%08x value 0x%016llx",
                     scomAddr, l_epsilonScomVal);
            rc = stopImageSection::p9_stop_save_scom(   i_pChipHomer,
                    scomAddr,
                    l_epsilonScomVal,
                    stopImageSection::P9_STOP_SCOM_APPEND,
                    stopImageSection::P9_STOP_SECTION_EQ_SCOM );

            if( rc )
            {
                FAPI_DBG(" p9_stop_save_scom Failed rc 0x%08x", rc );
                break;
            }
        }

        //=====================================================================================
        //Determine SCOM register data value for EX_L3_L3_WR_EPSILON_CFG_REG by reading attributes
        //=====================================================================================

        l_epsilonScomVal = 0;
        epsilonValBuf.flush<0>();

        //----------------------------- Tier1(T1)--------------------------------------

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1,
                               FAPI_SYSTEM,
                               attrValT1 ),
                 "Error from FAPI_ATTR_GET for attribute ATTR_PROC_EPS_WRITE_CYCLES_T1");

        attrValT1 = attrValT1 / 8 / L3_EPS_DIVIDER + 1;
        epsilonValBuf.insert< 0, 12, 20, uint32_t >(attrValT1);

        //----------------------------- Tier2(T2)--------------------------------------

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2,
                               FAPI_SYSTEM,
                               attrValT2 ),
                 "Error from FAPI_ATTR_GET for attribute ATTR_PROC_EPS_WRITE_CYCLES_T2");

        attrValT2 = attrValT2 / 8 / L3_EPS_DIVIDER + 1;
        epsilonValBuf.insert< 12, 12, 20, uint32_t >(attrValT2);

        // p9.l3.scom.initfile:
        // L3_EPS_STEP_MODE          = 0000
        // L3_EPS_DIVIDER_MODE       = L3_EPS_DIVIDER
        // EPS_CNT_USE_L3_DIVIDER_EN = 0
        epsilonValBuf.insert<30, 4, 28, uint32_t>(L3_EPS_DIVIDER);

        epsilonValBuf.extract<0, 64>(l_epsilonScomVal);

        //----------------------- Updating SCOM Registers using STOP API --------------------

        for( eqCnt = 0; eqCnt < MAX_QUADS_PER_CHIP; eqCnt++ )
        {
            scomAddr = (EX_L3_L3_WR_EPSILON_CFG_REG | (eqCnt << QUAD_BIT_POS));

            FAPI_DBG("Calling STOP API to update SCOM reg 0x%08x value 0x%016llx",
                     scomAddr, l_epsilonScomVal);
            rc = stopImageSection::p9_stop_save_scom(   i_pChipHomer,
                    scomAddr,
                    l_epsilonScomVal,
                    stopImageSection::P9_STOP_SCOM_APPEND,
                    stopImageSection::P9_STOP_SECTION_EQ_SCOM );

            if( rc )
            {
                FAPI_DBG(" p9_stop_save_scom Failed rc 0x%08x", rc );
                break;
            }

            scomAddr |= ODD_EVEN_EX_POS;

            FAPI_DBG("Calling STOP API to update SCOM reg 0x%08x value 0x%016llx",
                     scomAddr, l_epsilonScomVal);

            rc = stopImageSection::p9_stop_save_scom(  i_pChipHomer,
                    scomAddr,
                    l_epsilonScomVal,
                    stopImageSection::P9_STOP_SCOM_APPEND,
                    stopImageSection::P9_STOP_SECTION_EQ_SCOM );

            if( rc )
            {
                FAPI_DBG(" p9_stop_save_scom Failed rc 0x%08x", rc );
                break;
            }
        }

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rc ),
                     fapi2::EPSILON_SCOM_UPDATE_FAIL()
                     .set_STOP_API_SCOM_ERR( rc )
                     .set_EPSILON_REG_ADDR( scomAddr )
                     .set_EPSILON_REG_DATA( l_epsilonScomVal ),
                     "Failed to create restore entry for L3 Epsilon register" );

    }
    while(0);

    FAPI_DBG("< populateEpsilonL3ScomReg");
fapi_try_exit:
    return fapi2::current_err;
}


//---------------------------------------------------------------------------

/**
 * @brief   populate L3 Refresh Timer Control register
 * @param   i_pChipHomer    points to start of P9 HOMER.
 * @return  fapi2 return code.
 */
fapi2::ReturnCode populateL3RefreshScomReg( void*    i_pChipHomer )
{
    FAPI_DBG("> populateL3RefreshScomReg");

    do
    {
        uint32_t l_nest_freq_mhz = 0;
        uint32_t scomAddr = 0;
        uint32_t rc = IMG_BUILD_SUCCESS;
        uint64_t l_refreshScomVal ;
        // set defaults:
        // DIVIDE_MAJOR = DIV_BY_3
        // DIVIDE_MINOR = DIV_BY_10
        fapi2::buffer<uint64_t> refreshValBuf = 0x2000000000000000ULL;

        //=====================================================================================
        //Determine SCOM register data value for EX_DRAM_REF_REG by reading attributes
        //=====================================================================================

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB_MHZ,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_nest_freq_mhz),
                 "Error from FAPI_ATTR_GET for attribute ATTR_FREQ_PB_MHZ");

        // above 2GHz, set DIVIDE_MINOR = DIV_BY_12 = 0x2
        if (l_nest_freq_mhz >= 2000)
        {
            refreshValBuf.insertFromRight<EX_DRAM_REF_REG_L3_TIMER_DIVIDE_MINOR,
                EX_DRAM_REF_REG_L3_TIMER_DIVIDE_MINOR_LEN>(0x2);
        }

        l_refreshScomVal = refreshValBuf();

        //----------------------- Updating SCOM Registers using STOP API --------------------

        for( uint32_t eqCnt = 0; eqCnt < MAX_QUADS_PER_CHIP; eqCnt++ )
        {
            scomAddr = (EX_DRAM_REF_REG | (eqCnt << QUAD_BIT_POS));

            FAPI_DBG("Calling STOP API to update SCOM reg 0x%08x value 0x%016llx",
                     scomAddr, l_refreshScomVal);
            rc = stopImageSection::p9_stop_save_scom( i_pChipHomer,
                    scomAddr,
                    l_refreshScomVal,
                    stopImageSection::P9_STOP_SCOM_APPEND,
                    stopImageSection::P9_STOP_SECTION_EQ_SCOM );

            if( rc )
            {
                FAPI_DBG(" p9_stop_save_scom Failed rc 0x%08x", rc );
                break;
            }

            scomAddr |= ODD_EVEN_EX_POS;
            FAPI_DBG("Calling STOP API to update SCOM reg 0x%08x value 0x%016llx",
                     scomAddr, l_refreshScomVal);
            rc = stopImageSection::p9_stop_save_scom(   i_pChipHomer,
                    scomAddr,
                    l_refreshScomVal,
                    stopImageSection::P9_STOP_SCOM_APPEND,
                    stopImageSection::P9_STOP_SECTION_EQ_SCOM );

            if( rc )
            {
                FAPI_DBG(" p9_stop_save_scom Failed rc 0x%08x", rc );
                break;
            }
        }

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == rc ),
                     fapi2::REFRESH_SCOM_UPDATE_FAIL()
                     .set_STOP_API_SCOM_ERR( rc )
                     .set_REFRESH_REG_ADDR( scomAddr )
                     .set_REFRESH_REG_DATA( l_refreshScomVal ),
                     "Failed to create restore entry for L3 Refresh Timer Divider register" );
    }
    while(0);

    FAPI_DBG("< populateL3RefreshScomReg");
fapi_try_exit:
    return fapi2::current_err;
}


//---------------------------------------------------------------------------

/**
 * @brief   Reads an attribute to determine aux function invocation interval.
 * @param   i_pHomer                points to HOMER.
 * @param   o_auxFuncIntControl     Invocation interval for the auxiliary function.
 * return   fapi2 return code.
 */
fapi2::ReturnCode initReadIntervalForAuxFunc( Homerlayout_t*     i_pHomer, uint32_t& o_auxFuncIntControl )
{
    FAPI_DBG("> initReadIntervalForAuxFunc");
    uint8_t readInterAttr = 0;
    o_auxFuncIntControl = 0;

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PERF_24x7_INVOCATION_TIME_MS,
                           FAPI_SYSTEM,
                           readInterAttr),
             "Error from FAPI_ATTR_GET for attribute ATTR_PERF_24x7_INVOCATION_TIME_MS");

    if( readInterAttr )
    {
        o_auxFuncIntControl = ( readInterAttr << SGPE_AUX_FUNC_INERVAL_SHIFT );
        FAPI_DBG("sgpeReadAttrInterval 0x%08x", o_auxFuncIntControl );
    }

    FAPI_DBG("< initReadIntervalForAuxFunc");
fapi_try_exit:
    return fapi2::current_err;
}

//---------------------------------------------------------------------------

/**
 * @brief   builds HOMER section supporting Auxiliary functions.
 * @param   i_procTgt   fapi2 target for P9 chip
 * @param   i_pHomer    points to HOMER.
 * @param   o_qpmrHdr   instance of QpmrHeaderLayout_t
 */
fapi2::ReturnCode buildSgpeAux( CONST_FAPI2_PROC& i_procTgt, Homerlayout_t*     i_pHomer,
                                QpmrHeaderLayout_t& o_qpmrHdr )
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    sgpeHeader_t* pSgpeHdr = (sgpeHeader_t*)& i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECTOR_SIZE];
    uint32_t l_sgpeAuxFunc = 0;

    //SGPE Image Header
    //Offset represented as OCI PBA memory address
    pSgpeHdr->g_sgpe_aux_offset  = SWIZZLE_4_BYTE(HOMER_AUX_BASE_ADDR);
    pSgpeHdr->g_sgpe_aux_length  = SWIZZLE_4_BYTE(QPMR_AUX_LENGTH);

    //QPMR Header
    o_qpmrHdr.quadAuxOffset  =  SWIZZLE_4_BYTE(QPMR_AUX_OFFSET);
    o_qpmrHdr.quadAuxLength  =  SWIZZLE_4_BYTE(QPMR_AUX_LENGTH);

    FAPI_TRY(initReadIntervalForAuxFunc( i_pHomer, l_sgpeAuxFunc ),
             "Failed in initReadIntervalForAuxFunc" );
    pSgpeHdr->g_sgpe_aux_control = SWIZZLE_4_BYTE(l_sgpeAuxFunc);

fapi_try_exit:
    return fapi2::current_err;

}

//---------------------------------------------------------------------------

/**
 * @brief customizes the magic words in various HOMER headers.
 * @param[in]   i_pHomer    points to HOMER
 * @param[in]   i_ecLevel   ec level of the chip.
 */

void customizeMagicWord( Homerlayout_t*     i_pHomer, uint8_t i_ecLevel )
{
    FAPI_INF( ">> customizeMagicWord")
    cpmrHeader_t* pCpmrHdr =
        (cpmrHeader_t*) & (i_pHomer->cpmrRegion.selfRestoreRegion.CPMR_SR.elements.CPMRHeader);
    cmeHeader_t* pCmeHdr = (cmeHeader_t*) & i_pHomer->cpmrRegion.cmeSramRegion[CME_INT_VECTOR_SIZE];
    QpmrHeaderLayout_t* pQpmrHdr = (QpmrHeaderLayout_t*)i_pHomer->qpmrRegion.sgpeRegion.qpmrHeader;
    sgpeHeader_t* pSgpeImgHdr   =   (sgpeHeader_t*)& i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECTOR_SIZE];
    PpmrHeader_t* pPpmrHdr = (PpmrHeader_t*) i_pHomer->ppmrRegion.ppmrHeader;
    PgpeHeader_t*  pPgpeHdr = (PgpeHeader_t*)&i_pHomer->ppmrRegion.pgpeSramImage[PGPE_INT_VECTOR_SIZE];

    uint64_t magicWordCustom[MAX_HOMER_HEADER];
    uint64_t * pMagicWord[MAX_HOMER_HEADER];
    pMagicWord[0]   =   &pQpmrHdr->magic_number;
    pMagicWord[1]   =   &pSgpeImgHdr->g_sgpe_magic_number;
    pMagicWord[2]   =   &pCpmrHdr->magic_number;
    pMagicWord[3]   =   &pCmeHdr->g_cme_magic_number;
    pMagicWord[4]   =   &pPpmrHdr->g_ppmr_magic_number;
    pMagicWord[5]   =   &pPgpeHdr->g_pgpe_magic_number;

    magicWordCustom[0]  =  QPMR_MAGIC_NUMBER_BASE;
    magicWordCustom[1]  =  SGPE_MAGIC_NUMBER_BASE;
    magicWordCustom[2]  =  CPMR_MAGIC_NUMBER_BASE;
    magicWordCustom[3]  =  CME_MAGIC_NUMBER_BASE;
    magicWordCustom[4]  =  PPMR_MAGIC_NUMBER_BASE;
    magicWordCustom[5]  =  PGPE_MAGIC_NUMBER_BASE;

    uint32_t ecMajor = (i_ecLevel & 0xf0 );
    ecMajor = ecMajor << 12;
    uint8_t ecMinor = (i_ecLevel & 0x0f);

    FAPI_INF("=========== Header Magic Words Info ===========");

    for( uint32_t i = 0; i < MAX_HOMER_HEADER; i++ )
    {
        char magicWord[MAX_HOMER_HEADER][20] = { "QPMR Magic Word ", "SGPE Magic Word ", "CPMR Magic Word ",
                                        "CME Magic Word ", "PPMR Magic Word ", "PGPE Magic Word " };
        char tempBuf[10] ;
        memset( tempBuf, 0x00, 10 );
        magicWordCustom[i] += ecMinor;
        magicWordCustom[i] += ecMajor;
        *pMagicWord[i]     = SWIZZLE_8_BYTE( magicWordCustom[i]);
        memcpy( tempBuf, pMagicWord[i], sizeof(uint64_t) );
        FAPI_INF("%s\t\t:\t\t %s ( 0x%016lx ) ", &magicWord[i], tempBuf, SWIZZLE_8_BYTE(*pMagicWord[i]) );
    }

    FAPI_INF("=========== Header Magic Words Info Ends ===========");
    FAPI_INF( "<< customizeMagicWord")

}

//---------------------------------------------------------------------------

fapi2::ReturnCode p9_hcode_image_build( CONST_FAPI2_PROC& i_procTgt,
                                        void* const     i_pImageIn,
                                        void*           i_pHomerImage,
                                        void* const i_pRingOverride,
                                        SysPhase_t i_phase,
                                        ImageType_t i_imgType,
                                        void* const i_pBuf1,
                                        const uint32_t    i_sizeBuf1,
                                        void* const i_pBuf2,
                                        const uint32_t    i_sizeBuf2,
                                        void* const i_pBuf3,
                                        const uint32_t    i_sizeBuf3 )


{
    FAPI_IMP("Entering p9_hcode_image_build ");

    do
    {
        FAPI_DBG("validating argument ..");

        FAPI_TRY( validateInputArguments( i_pImageIn, i_pHomerImage, i_phase,
                                          i_imgType,
                                          i_pBuf1,
                                          i_sizeBuf1,
                                          i_pBuf2,
                                          i_sizeBuf2,
                                          i_pBuf3,
                                          i_sizeBuf3 ),
                  "Invalid arguments, escaping hcode image build" );

        uint8_t ecLevel = 0;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC,
                                          i_procTgt,
                                          ecLevel),
                 "Error from for attribute ATTR_EC");

        FAPI_INF("Creating chip functional model");

        P9FuncModel l_chipFuncModel( i_procTgt, ecLevel );
        Homerlayout_t* pChipHomer = ( Homerlayout_t*) i_pHomerImage;
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        uint32_t ppeImgRc = IMG_BUILD_SUCCESS;
        QpmrHeaderLayout_t l_qpmrHdr;
        // HW Image is a nested XIP Image. Let us read global TOC of hardware image
        // and find out if XIP header of PPE image is contained therein.
        // Let us start with SGPE
        FAPI_INF("SGPE building");
        ppeImgRc = buildSgpeImage( i_pImageIn, pChipHomer, i_imgType, l_qpmrHdr, ecLevel );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                     fapi2::SGPE_BUILD_FAIL()
                     .set_SGPE_FAIL_SECTN( ppeImgRc ),
                     "Failed to copy SGPE section in HOMER" );

        FAPI_TRY( buildSgpeAux( i_procTgt, pChipHomer, l_qpmrHdr ),
                  "Failed to build Auxiliary section" );

        FAPI_INF("SGPE built");

        // copy sections pertaining to self restore
        // Note: this creates the CPMR header portion

        //let us determine if system is configured in fuse mode. This needs to
        //be updated in a CPMR region.
        uint8_t fuseModeState = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUSED_CORE_MODE,
                               FAPI_SYSTEM,
                               fuseModeState),
                 "Error from FAPI_ATTR_GET for attribute ATTR_FUSED_CORE_MODE");

        FAPI_INF("CPMR / Self Restore building");
        ppeImgRc = buildCoreRestoreImage( i_pImageIn, pChipHomer, i_imgType, fuseModeState, ecLevel );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                     fapi2::SELF_RESTORE_BUILD_FAIL()
                     .set_SELF_RESTORE_FAIL_SECTN( ppeImgRc ),
                     "Failed to copy core self restore section in HOMER" );
        FAPI_INF("Self Restore built ");

        // copy sections pertaining to CME
        FAPI_INF("CPMR / CME building");
        uint64_t cpmrPhyAdd = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HOMER_PHYS_ADDR, i_procTgt, cpmrPhyAdd ),
                 "Error from FAPI_ATTR_GET for ATTR_HOMER_PHYS_ADDR");
        FAPI_DBG("HOMER base address 0x%016lX", cpmrPhyAdd );
        ppeImgRc = buildCmeImage( i_pImageIn, pChipHomer, i_imgType, cpmrPhyAdd, ecLevel );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                     fapi2::CME_BUILD_FAIL()
                     .set_CME_FAIL_SECTN( ppeImgRc ),
                     "Failed to copy CME section in HOMER" );

        FAPI_INF("CME built");

        FAPI_INF("PGPE building");
        PpmrHeader_t l_ppmrHdr;
        ppeImgRc = buildPgpeImage( i_pImageIn, pChipHomer, l_ppmrHdr, i_imgType, ecLevel );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                     fapi2::PGPE_BUILD_FAIL()
                     .set_PGPE_FAIL_SECTN( ppeImgRc ),
                     "Failed to copy PGPE section in HOMER" );

        //Update P State parameter block info in HOMER
        FAPI_TRY( buildParameterBlock( pChipHomer, i_procTgt, l_ppmrHdr, i_imgType, i_pBuf1, i_sizeBuf1 ),
                  "Failed to add parameter block" );

        FAPI_INF("PGPE built");
        //Let us add Scan Rings to the image.
        uint8_t l_ringDebug = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RING_DBG_MODE,
                               FAPI_SYSTEM,
                               l_ringDebug),
                 "Error from FAPI_ATTR_GET for attribute ATTR_SYSTEM_RING_DBG_MODE");
        FAPI_DBG("Ring Debug Level 0x%02x", l_ringDebug );

        RingBufData l_ringData( i_pBuf1,
                                i_sizeBuf1,
                                i_pBuf2,
                                i_sizeBuf2,
                                i_pBuf3,
                                i_sizeBuf3 );

        //Extract all the rings for CME platform from HW Image and VPD
        ppeImgRc = getPpeScanRings( i_pImageIn,
                                    PLAT_CME,
                                    i_procTgt,
                                    l_ringData,
                                    i_imgType );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                     fapi2::SCAN_RING_EXTRACTION_FAIL()
                     .set_EXTRACTION_FAIL_PLAT( PLAT_CME )
                     .set_EXTRACTION_FAILURE_CODE( ppeImgRc ),
                     "Failed to extract core scan rings" );

        uint8_t l_iplPhase = 0 ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RISK_LEVEL,
                               FAPI_SYSTEM,
                               l_iplPhase),
                 "Error from FAPI_ATTR_GET for ATTR_RISK_LEVEL");

        // create a layout of rings in HOMER for consumption of CME
        ppeImgRc = layoutRingsForCME(  pChipHomer,
                                       l_chipFuncModel,
                                       l_ringData,
                                       (RingDebugMode_t)l_ringDebug,
                                       l_iplPhase,
                                       i_imgType,
                                       i_pRingOverride );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                     fapi2::SCAN_RING_PLACEMENT_FAIL()
                     .set_PLACEMENT_FAIL_PLAT( PLAT_CME )
                     .set_PLACEMENT_FAILURE_CODE( ppeImgRc ),
                     "Failed to place core scan rings" );

        l_ringData.iv_ringBufSize = i_sizeBuf1;
        ppeImgRc = getPpeScanRings( i_pImageIn,
                                    PLAT_SGPE,
                                    i_procTgt,
                                    l_ringData,
                                    i_imgType );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                     fapi2::SCAN_RING_EXTRACTION_FAIL()
                     .set_EXTRACTION_FAIL_PLAT( PLAT_SGPE )
                     .set_EXTRACTION_FAILURE_CODE( ppeImgRc ),
                     "Failed to extract quad scan rings" );

        // create a layout of rings in HOMER for consumption of SGPE
        ppeImgRc = layoutRingsForSGPE(  pChipHomer,
                                        i_pRingOverride,
                                        l_chipFuncModel,
                                        l_ringData,
                                        (RingDebugMode_t)l_ringDebug,
                                        l_iplPhase,
                                        l_qpmrHdr,
                                        i_imgType );

        FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                     fapi2::SCAN_RING_PLACEMENT_FAIL()
                     .set_PLACEMENT_FAIL_PLAT( PLAT_SGPE )
                     .set_PLACEMENT_FAILURE_CODE( ppeImgRc ),
                     "Failed to place quad scan rings" );

        //Update CPMR Header with Scan Ring details
        updateCpmrCmeRegion( pChipHomer );

        //Update QPMR Header area in HOMER
        updateQpmrHeader( pChipHomer, l_qpmrHdr );

        //update PPMR Header area in HOMER
        updatePpmrHeader( pChipHomer, l_ppmrHdr );

        //Update L2 Epsilon SCOM Registers
        FAPI_TRY( populateEpsilonL2ScomReg( pChipHomer ),
                  "populateEpsilonL2ScomReg failed" );

        //Update L3 Epsilon SCOM Registers
        FAPI_TRY( populateEpsilonL3ScomReg( pChipHomer ),
                  "populateEpsilonL3ScomReg failed" );

        //Update L3 Refresh Timer Control SCOM Registers
        FAPI_TRY( populateL3RefreshScomReg( pChipHomer ),
                  "populateL3RefreshScomReg failed" );

        //populate HOMER with SCOM restore value of NCU RNG BAR SCOM Register
        FAPI_TRY( populateNcuRingBarScomReg( pChipHomer, i_procTgt ),
                  "populateNcuRingBarScomReg failed" );

        //validate SRAM Image Sizes of PPE's
        uint32_t sramImgSize = 0;
        FAPI_TRY( validateSramImageSize( pChipHomer, sramImgSize ),
                  "Final SRAM Image Size Check Failed" );

        //Update CME/SGPE Flags in respective image header.
        FAPI_TRY( updateImageFlags( pChipHomer, i_procTgt ),
                  "updateImageFlags Failed" );

        //Set the Fabric IDs
        FAPI_TRY(setFabricIds( pChipHomer, i_procTgt ),
                 "Failed to set Fabric IDs");

        //Update the attributes storing PGPE and SGPE's boot copier offset.
        FAPI_TRY( updateGpeAttributes( pChipHomer, i_procTgt ),
                  "Failed to update SGPE/PGPE IVPR attributes" );

        //customize magic word based on endianess
        customizeMagicWord( pChipHomer, ecLevel );
    }
    while(0);

    FAPI_IMP("Exit p9_hcode_image_build" );

fapi_try_exit:
    return fapi2::current_err;
}

} //namespace p9_hcodeImageBuild ends

}// extern "C"

// *INDENT-ON*
