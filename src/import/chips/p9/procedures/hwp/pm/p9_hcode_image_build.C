/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_hcode_image_build.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <map>
#include <p9_hcode_image_build.H>
#include "p9_xip_image.h"
#include "p9_hcode_image_defines.H"
#include "p9_stop_util.H"
#include "p9_scan_ring_util.H"
#include "p9_tor.H"
#include "p9_misc_scom_addresses.H"
#include <p9_infrastruct_help.H>
#include <p9_xip_customize.H>
#include <p9_ringId.H>

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
    }                                                   \

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
        QUAD_SPEC_RING_INDEX_LEN    =   (QUAD_SPEC_RING_INDEX_SIZE * 2 * MAX_CACHE_CHIPLET),
        CORE_COMMON_RING_INDEX_SIZE =   sizeof(CoreCmnRingsList_t),
        CORE_SPEC_RING_INDEX_SIZE   =   sizeof(CoreSpecRingList_t),
        RING_START_TO_RS4_OFFSET    =   8,
        TOR_VER_ONE                 =   1,
        TOR_VER_TWO                 =   2,
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
        ImgSec( PlatId i_plat, uint8_t i_secId ):
            iv_plat( i_plat ),
            iv_secId( i_secId )
        { }
        ImgSec(): iv_plat (PLAT_SELF), iv_secId (0 )
        { }
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
            uint32_t isSizeGood( PlatId i_plat, uint8_t i_sec, uint32_t i_size );

        private:
            std::map< ImgSec, uint32_t> iv_secSize;

    };

    /**
     * @brief   constructor
     */
    ImgSizeBank::ImgSizeBank()
    {
        iv_secSize[ImgSec(PLAT_SELF, P9_XIP_SECTION_RESTORE_SELF)]    =   SELF_REST_SIZE;
        iv_secSize[ImgSec(PLAT_SELF, P9_XIP_SECTION_RESTORE_CPMR)]    =   CPMR_HEADER_SIZE;
        iv_secSize[ImgSec(PLAT_SGPE, P9_XIP_SECTION_SGPE_QPMR)]       =   HALF_KB;
        iv_secSize[ImgSec(PLAT_SGPE, P9_XIP_SECTION_SGPE_LVL1_BL)]    =   SGPE_LVL_1_BOOT_LOAD_SIZE;
        iv_secSize[ImgSec(PLAT_SGPE, P9_XIP_SECTION_SGPE_LVL2_BL)]    =   SGPE_LVL_2_BOOT_LOAD_SIZE;
        iv_secSize[ImgSec(PLAT_SGPE, P9_XIP_SECTION_SGPE_HCODE)]      =   SGPE_IMAGE_SIZE;

        iv_secSize[ImgSec(PLAT_CME, P9_XIP_SECTION_CME_HCODE)]        =   CME_SRAM_SIZE;

        //iv_secSize[ImgSec(PLAT_PGPE, P9_XIP_SECTION_PGPE_PPPMR)]    =   HALF_KB;
        iv_secSize[ImgSec(PLAT_PGPE, P9_XIP_SECTION_PGPE_LVL1_BL)]    =   PGPE_LVL_1_BOOT_LOAD_SIZE ;
        iv_secSize[ImgSec(PLAT_PGPE, P9_XIP_SECTION_PGPE_LVL2_BL)]    =   PGPE_LVL_2_BOOT_LOAD_SIZE ;
        iv_secSize[ImgSec(PLAT_PGPE, P9_XIP_SECTION_PGPE_HCODE)]      =   PGPE_MAX_AREA_SIZE;
    }

    /**
     * @brief   verifies actual section size against max size allowed.
     * @param   i_plat  platform associated with image section.
     * @param   i_sec   image section.
     * @param   i_size  actual image section size.
     * @return  zero if size within limit else max size allowed.
     */
    uint32_t ImgSizeBank::isSizeGood( PlatId i_plat, uint8_t i_sec, uint32_t i_size )
    {
        uint32_t size = -1;
        ImgSec key( i_plat, i_sec );
        std::map< ImgSec, uint32_t>::iterator it;

        for( it = iv_secSize.begin(); it != iv_secSize.end(); it++ )
        {
            if( it->first == key )
            {
                size = 0;

                if( it->second < i_size )
                {
                    size = it->second;
                }

                break;
            }
        }

        FAPI_DBG(" Sec Size 0x%08X", size);
        return size;
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

        for( uint32_t eqCnt = 0; eqCnt < MAX_CACHE_CHIPLET; eqCnt++ )
        {
            iv_idMap[CACH0_CHIPLET_ID + eqCnt] = exPairIdMap[eqCnt];
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

    uint32_t validateSramImageSize( Homerlayout_t* i_pChipHomer, uint32_t& o_sramImgSize )
    {
        FAPI_DBG(">validateSramImageSize" );
        uint32_t rc = IMG_BUILD_SUCCESS;

        do
        {
            ImgSizeBank sizebank;
            sgpeHeader_t* pSgpeHdr = (sgpeHeader_t*)& i_pChipHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECT];
            cmeHeader_t* pCmeHdr = (cmeHeader_t*) & i_pChipHomer->cpmrRegion.cmeSramRegion[CME_INT_VECTOR_SIZE];

            //FIXME size will change once SCOM and 24x7 are handled
            o_sramImgSize =  SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_scom_offset);

            rc = sizebank.isSizeGood( PLAT_SGPE, P9_XIP_SECTION_SGPE_HCODE, o_sramImgSize );
            FAPI_DBG("SGPE SRAM Image : 0x%08X Size Check : %s", o_sramImgSize, rc ? "FAILURE" : "SUCCESS" );

            if( rc )
            {
                rc = SGPE_SRAM_IMG_SIZE_ERR;
                break;
            }

            o_sramImgSize = (SWIZZLE_4_BYTE(pCmeHdr->g_cme_scom_offset) << CME_BLK_SIZE_SHIFT) +
                            SWIZZLE_4_BYTE(pCmeHdr->g_cme_scom_length);

            FAPI_DBG("CME Offset 0x%08X size 0x%08X", SWIZZLE_4_BYTE(pCmeHdr->g_cme_scom_offset), o_sramImgSize );
            rc = sizebank.isSizeGood( PLAT_CME, P9_XIP_SECTION_CME_HCODE, o_sramImgSize );
            FAPI_DBG("CME SRAM Image : 0x%08X Size Check : %s", o_sramImgSize, rc ? "FAILURE" : "SUCCESS" );

            if( rc )
            {
                rc = CME_SRAM_IMG_SIZE_ERR;
                break;
            }
        }
        while(0);

        FAPI_DBG("<validateSramImageSize" );

        return rc;
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

        FAPI_ASSERT( (( i_pImageIn != NULL ) && ( i_pImageOut != NULL ) &&
                      ( i_pImageIn != i_pImageOut )),
                     fapi2::IMG_PTR_ERROR()
                     .set_HW_IMG_BUF_PTR( i_pImageIn )
                     .set_HOMER_IMG_BUF_PTR( i_pImageOut ),
                     "Bad pointer to HW Image or HOMER Image" );
        l_rc = p9_xip_image_size( i_pImageIn, &hwImagSize );

        FAPI_DBG("size is 0x%08X; xip_image_size RC is 0x%02x HARDWARE_IMG_SIZE 0x%08X  Sz 0x%08X",
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
                     fapi2::HCODE_INVALID_TEMP_BUF()
                     .set_TEMP_BUF_PTR( i_pBuf1 ),
                     "Invalid temp buffer1 passed for hcode image build" );

        FAPI_ASSERT( (( i_bufSize1 != 0  ) && ( i_bufSize2 != 0 ) && ( i_bufSize3 != 0 )),
                     fapi2::HCODE_TEMP_BUF_SIZE()
                     .set_TEMP_BUF1_SIZE( i_bufSize1 )
                     .set_TEMP_BUF2_SIZE( i_bufSize2 )
                     .set_TEMP_BUF3_SIZE( i_bufSize3 ),
                     "Invalid work buffer size " );

        FAPI_ASSERT( ( i_pBuf2 != NULL ),
                     fapi2::HCODE_INVALID_TEMP_BUF()
                     .set_TEMP_BUF_PTR( i_pBuf2 ),
                     "Invalid temp buffer2 passed for hcode image build" );

        FAPI_ASSERT( ( i_pBuf3 != NULL ),
                     fapi2::HCODE_INVALID_TEMP_BUF()
                     .set_TEMP_BUF_PTR( i_pBuf3 ),
                     "Invalid temp buffer3 passed for hcode image build" );

        FAPI_ASSERT( ( i_imgType.isBuildValid() ),
                     fapi2::HCODE_INVALID_IMG_TYPE(),
                     "Invalid temp buffer passed for hcode image build" );
        FAPI_DBG("Exiting validateInputArguments ...");

    fapi_try_exit:
        return fapi2::current_err;
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
                                 P9XipSection&   o_ppeSection )
    {
        FAPI_INF("> copySectionToHomer");
        uint32_t retCode = IMG_BUILD_SUCCESS;
        ImgSizeBank sizebank;

        do
        {
            o_ppeSection.iv_offset = 0;
            o_ppeSection.iv_size = 0;
            uint32_t rcTemp = p9_xip_get_section( i_srcPtr, i_secId, &o_ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to get section 0x%08X of Plat 0x%08X", i_secId, i_platId );
                retCode = BUILD_FAIL_INVALID_SECTN;
                break;
            }

            FAPI_DBG("o_ppeSection.iv_offset = %X, "
                     "o_ppeSection.iv_size = %X, "
                     "i_secId %d",
                     o_ppeSection.iv_offset,
                     o_ppeSection.iv_size,
                     i_secId);

            rcTemp = sizebank.isSizeGood( i_platId, i_secId, o_ppeSection.iv_size );

            if ( rcTemp )
            {
                FAPI_ERR("??????????Size Exceeds the permissible limit???????" );
                FAPI_ERR("Max Allowed 0x%08X (%08d) Actual Size 0x%08X (%08d)",
                         rcTemp, rcTemp, o_ppeSection.iv_size, o_ppeSection.iv_size);
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
     * @brief   updates various CPMR fields which are associated with scan rings.
     * @param   i_pChipHomer    points to start of P9 HOMER.
     */
    void updateCpmrCmeRegion( Homerlayout_t* i_pChipHomer )
    {
        cpmrHeader_t* pCpmrHdr =
            (cpmrHeader_t*) & (i_pChipHomer->cpmrRegion.selfRestoreRegion.CPMR_SR.elements.CPMRHeader);
        cmeHeader_t* pCmeHdr = (cmeHeader_t*) & i_pChipHomer->cpmrRegion.cmeSramRegion[CME_INT_VECTOR_SIZE];

        //Updating CPMR Header using info from CME Header
        pCpmrHdr->cmeImgOffset              =   SWIZZLE_4_BYTE((CPMR_CME_HCODE_OFFSET >> CME_BLK_SIZE_SHIFT));
        pCpmrHdr->cmePstateOffset           =   CPMR_CME_HCODE_OFFSET + SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_offset);
        pCpmrHdr->cmePstateOffset           =   SWIZZLE_4_BYTE(pCpmrHdr->cmePstateOffset);
        pCpmrHdr->cmePstateLength           =   0;
        pCpmrHdr->cmeImgLength              =   pCmeHdr->g_cme_hcode_length;// already swizzled
        pCpmrHdr->coreScomOffset            =   SWIZZLE_4_BYTE(CORE_SCOM_START);
        pCpmrHdr->coreScomLength            =   SWIZZLE_4_BYTE(CORE_SCOM_RES_SIZE);

        if( pCmeHdr->g_cme_common_ring_length )
        {
            pCpmrHdr->cmeCommonRingOffset       =   CPMR_CME_HCODE_OFFSET + SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_offset);
            pCpmrHdr->cmeCommonRingOffset       =   SWIZZLE_4_BYTE(pCpmrHdr->cmeCommonRingOffset);
            pCpmrHdr->cmeCommonRingLength       =   pCmeHdr->g_cme_common_ring_length;
        }

        if( pCmeHdr->g_cme_max_spec_ring_length )
        {
            pCpmrHdr->coreSpecRingOffset        =   SWIZZLE_4_BYTE(CME_INST_SPEC_RING_START);
            pCpmrHdr->coreSpecRingLength        =   pCmeHdr->g_cme_max_spec_ring_length; // already swizzled
        }

        //Updating CME Image header
        pCmeHdr->g_cme_magic_number         =   SWIZZLE_8_BYTE(CME_MAGIC_NUMBER);

        pCmeHdr->g_cme_scom_offset          =   SWIZZLE_4_BYTE(pCmeHdr->g_cme_hcode_length) +
                                                SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_length) +
                                                SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_length);
        pCmeHdr->g_cme_scom_offset          =
            ((pCmeHdr->g_cme_scom_offset + CME_BLOCK_READ_LEN - 1 ) >> CME_BLK_SIZE_SHIFT);
        //Adding to it instance ring length which is already a multiple of 32B
        pCmeHdr->g_cme_scom_offset          +=  SWIZZLE_4_BYTE(pCmeHdr->g_cme_max_spec_ring_length);
        pCmeHdr->g_cme_scom_offset          =   SWIZZLE_4_BYTE(pCmeHdr->g_cme_scom_offset);
        pCmeHdr->g_cme_scom_length          =   SWIZZLE_4_BYTE(CORE_SCOM_PER_CME);

        FAPI_INF("========================= CME Header Start ==================================");
        FAPI_INF("  Magic Num       = 0x%16lx", SWIZZLE_8_BYTE(pCmeHdr->g_cme_magic_number));
        FAPI_INF("  HC Offset       = 0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_hcode_offset));
        FAPI_INF("  HC Size         = 0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_hcode_length));
        FAPI_INF("  PS Offset       = 0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_offset));
        FAPI_INF("  PS Size         = 0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_pstate_region_length));
        FAPI_INF("  CR Offset       = 0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_offset));
        FAPI_INF("  CR Ovrd Offset  = 0x%08X", SWIZZLE_4_BYTE(pCmeHdr->g_cme_cmn_ring_ovrd_offset ));
        FAPI_INF("  CR Size         = 0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_length));
        FAPI_INF("  CSR Offset      = 0x%08X (Real offset / 32) ", SWIZZLE_4_BYTE(pCmeHdr->g_cme_core_spec_ring_offset));
        FAPI_INF("  CSR Length      = 0x%08X (Real length / 32)", SWIZZLE_4_BYTE(pCmeHdr->g_cme_max_spec_ring_length) );
        FAPI_INF("  SCOM Offset     = 0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_scom_offset));
        FAPI_INF("  SCOM Area Len   = 0x%08X",  SWIZZLE_4_BYTE(pCmeHdr->g_cme_scom_length));
        FAPI_INF("  CPMR Phy Add    = 0x%016lx", SWIZZLE_8_BYTE(pCmeHdr->g_cme_cpmr_PhyAddr));
        FAPI_INF("========================= CME Header End ==================================");

        FAPI_INF("==========================CPMR Header===========================================");
        FAPI_INF(" CME HC Offset            : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmeImgOffset));
        FAPI_INF(" CME HC Length            : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmeImgLength));
        FAPI_INF(" PS  Offset               : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmePstateOffset));
        FAPI_INF(" PS  Length               : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmePstateLength));
        FAPI_INF(" CR  Offset               : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmeCommonRingOffset));
        FAPI_INF(" CR  Length               : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmeCommonRingLength));
        FAPI_INF(" CSR Offset               : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->coreSpecRingOffset));
        FAPI_INF(" CSR Length               : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->coreSpecRingLength));
        FAPI_INF(" Core SCOM Offset         : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->coreScomOffset));
        FAPI_INF(" Core SCOM Length         : 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->coreScomLength ));
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
        pCpmrHdr->fusedModeStatus = i_fusedState ? FUSED_MODE : NONFUSED_MODE;
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
    uint32_t updateQpmrHeader( Homerlayout_t* i_pChipHomer, QpmrHeaderLayout_t& io_qpmrHdr )
    {
        uint32_t rc = IMG_BUILD_SUCCESS;

        QpmrHeaderLayout_t* pQpmrHdr = ( QpmrHeaderLayout_t*) & (i_pChipHomer->qpmrRegion.sgpeRegion.qpmrHeader);
        sgpeHeader_t* pSgpeHdr = (sgpeHeader_t*)& i_pChipHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECT];
        memcpy( pQpmrHdr, &io_qpmrHdr, sizeof( QpmrHeaderLayout_t ) );

        pQpmrHdr->magic_number                  =   SWIZZLE_8_BYTE(QPMR_MAGIC_NUMBER);
        pSgpeHdr->g_sgpe_magic_number           =   SWIZZLE_8_BYTE(SGPE_MAGIC_NUMBER);

        FAPI_INF("==============================QPMR==================================");
        FAPI_INF("  Magic Num               : 0x%16lX", SWIZZLE_8_BYTE(pQpmrHdr->magic_number));
        FAPI_INF("  Build Date              : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->buildDate));
        FAPI_INF("  Version                 : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->buildVersion));
        FAPI_INF("  BC Offset               : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->bootCopierOffset));
        FAPI_INF("  BL Offset               : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->bootLoaderOffset));
        FAPI_INF("  BL Size                 : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->bootLoaderLength));
        FAPI_INF("  HC Offset               : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->sgpeImgOffset));
        FAPI_INF("  HC Size                 : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->sgpeImgLength));
        FAPI_DBG("  Cmn Ring Offset         : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadCommonRingOffset) );
        FAPI_DBG("  Cmn Ring Length         : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadCommonRingLength) );
        FAPI_DBG("  Cmn Ring Ovrd Offset    : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadCommonOvrdOffset) );
        FAPI_DBG("  Cmn Ring Ovrd Length    : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadCommonOvrdLength) );
        FAPI_DBG("  Quad Spec Ring Offset   : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadSpecRingOffset) );
        FAPI_DBG("  Quad Spec Ring Length   : 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->quadSpecRingLength) );
        FAPI_INF("==============================QPMR Ends==============================");
        FAPI_INF("===========================SGPE Image Hdr=============================");
        FAPI_INF(" Cmn Ring Offset          :  0x%08X", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_cmn_ring_occ_offset ));
        FAPI_INF(" Override Offset          :  0x%08X", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_cmn_ring_ovrd_occ_offset ));
        FAPI_INF(" Flags                    :  0x%08X", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_reserve_flags ));
        FAPI_INF(" Quad Spec Ring Offset    :  0x%08X", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_spec_ring_occ_offset ));
        FAPI_INF(" Quad SCOM SRAM Offset    :  0x%08X", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_scom_offset));
        FAPI_INF(" Quad SCOM Mem Offset     :  0x%08X", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_scom_mem_offset));
        FAPI_INF(" Quad SCOM Mem Length     :  0x%08X", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_scom_mem_length ));
        FAPI_INF(" 24x7 Offset              :  0x%08X", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_24x7_offset ));
        FAPI_INF(" 24x7 Length              :  0x%08X", SWIZZLE_4_BYTE(pSgpeHdr->g_sgpe_24x7_length ));
        FAPI_INF("========================SGPE Image Hdr Ends===========================");

        return rc;
    }

//------------------------------------------------------------------------------
    /**
     * @brief       copies image section associated with  SGPE from HW Image to HOMER
     * @param[in]   i_pImageIn      points to start of hardware image.
     * @param[in]   i_pChipHomer    points to HOMER image.
     * @param[in]   i_imgType       image sections  to be built
     */
    uint32_t buildSgpeImage( void* const i_pImageIn, Homerlayout_t* i_pChipHomer, ImageType_t i_imgType,
                             QpmrHeaderLayout_t& o_qpmrHdr )
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
            rcTemp = p9_xip_get_section( i_pImageIn, P9_XIP_SECTION_HW_SGPE, &ppeSection );

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
                                         ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy Level2 bootloader");
                retCode = BUILD_FAIL_SGPE_BL2;
                break;
            }

            o_qpmrHdr.bootLoaderOffset = o_qpmrHdr.bootCopierOffset + SGPE_LVL_1_BOOT_LOAD_SIZE;
            o_qpmrHdr.bootLoaderLength = ppeSection.iv_size;

            FAPI_INF("SGPE Boot Loader QPMR Offset = 0x%08X, Size = 0x%08X",
                     o_qpmrHdr.bootLoaderOffset, o_qpmrHdr.bootLoaderLength);

            rcTemp = copySectionToHomer( i_pChipHomer->qpmrRegion.sgpeRegion.sgpeSramImage,
                                         pSgpeImg,
                                         P9_XIP_SECTION_SGPE_HCODE,
                                         PLAT_SGPE,
                                         ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy SGPE hcode");
                retCode = BUILD_FAIL_SGPE_HCODE;
                break;
            }

            o_qpmrHdr.sgpeImgOffset = o_qpmrHdr.bootLoaderOffset + SGPE_LVL_2_BOOT_LOAD_SIZE;

            FAPI_DBG("SGPE Hcode       QPMR Offset = 0x%08X, Size = 0x%08X",
                     SWIZZLE_4_BYTE(o_qpmrHdr.sgpeImgOffset),
                     SWIZZLE_4_BYTE(o_qpmrHdr.sgpeImgLength));

            o_qpmrHdr.sgpeImgOffset = o_qpmrHdr.bootLoaderOffset + SGPE_LVL_2_BOOT_LOAD_SIZE;

            o_qpmrHdr.sgpeImgLength       = SWIZZLE_4_BYTE(ppeSection.iv_size);
            o_qpmrHdr.bootLoaderOffset    = SWIZZLE_4_BYTE(o_qpmrHdr.bootLoaderOffset);
            //let us take care of endianess now.
            o_qpmrHdr.bootCopierOffset    = SWIZZLE_4_BYTE(o_qpmrHdr.bootCopierOffset);
            o_qpmrHdr.bootLoaderLength    = SWIZZLE_4_BYTE(o_qpmrHdr.bootLoaderLength);
            o_qpmrHdr.sgpeImgOffset       = SWIZZLE_4_BYTE(o_qpmrHdr.sgpeImgOffset);


            //FIXME Need to confirm it
            o_qpmrHdr.quadScomOffset  = SWIZZLE_4_BYTE(CACHE_SCOM_START);

            sgpeHeader_t* pImgHdr = (sgpeHeader_t*)& i_pChipHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECT];
            pImgHdr->g_sgpe_cmn_ring_occ_offset         =   o_qpmrHdr.sgpeImgLength;
            pImgHdr->g_sgpe_cmn_ring_ovrd_occ_offset    =   0;
            pImgHdr->g_sgpe_spec_ring_occ_offset        =   0;
            pImgHdr->g_sgpe_scom_offset                 =   0;


            FAPI_INF("SGPE Header");
            FAPI_INF("  Magic Num       = 0x%16lX", SWIZZLE_8_BYTE(pImgHdr->g_sgpe_magic_number));
            FAPI_INF("  Reset Addr      = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_reset_address));
            FAPI_INF("  IVPR Addr       = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_ivpr_address));
            FAPI_INF("  Build Date      = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_build_date));
            FAPI_INF("  Version         = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_build_ver));
            FAPI_INF("  CR OCC Offset   = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_cmn_ring_occ_offset));
            FAPI_INF("  CR Ovrd Offset  = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_cmn_ring_ovrd_occ_offset));

        }
        while(0);

        FAPI_INF("< buildSgpeImag")
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
                                    uint8_t i_fusedState )
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
            uint32_t l_fillPattern = SWIZZLE_4_BYTE(PAD_OPCODE);

            while( wordCnt < CORE_RESTORE_SIZE )
            {
                memcpy( (uint32_t*)&i_pChipHomer->cpmrRegion.selfRestoreRegion.coreSelfRestore[wordCnt],
                        &l_fillPattern,
                        sizeof( uint32_t ));
                wordCnt += 4;
            }

            updateCpmrHeaderSR( i_pChipHomer, i_fusedState );
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
                            ImageType_t i_imgType, uint64_t i_cpmrPhyAdd )
    {
        uint32_t retCode = IMG_BUILD_SUCCESS;

        do
        {
            uint32_t rcTemp = 0;
            //Let us find XIP Header for CME Image
            P9XipSection ppeSection;
            uint8_t* pCmeImg = NULL;

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

            if( !i_imgType.cmeHcodeBuild )
            {
                break;
            }

            memset(i_pChipHomer->cpmrRegion.cmeSramRegion, 0x00, CME_REGION_SIZE);

            // The image in the HW Image has the Interrupt Vectors, CME Header and Debug
            // Pointers already included.
            rcTemp = copySectionToHomer(  i_pChipHomer->cpmrRegion.cmeSramRegion, pCmeImg,
                                          P9_XIP_SECTION_CME_HCODE,
                                          PLAT_CME,
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
            pImgHdr->g_cme_cpmr_PhyAddr             =   (i_cpmrPhyAdd | CPMR_OFFSET);
            pImgHdr->g_cme_pstate_region_offset     =   pImgHdr->g_cme_hcode_offset + pImgHdr->g_cme_hcode_length;
            pImgHdr->g_cme_pstate_region_length     =   0;
            pImgHdr->g_cme_common_ring_offset       =   pImgHdr->g_cme_pstate_region_offset + pImgHdr->g_cme_pstate_region_length;
            pImgHdr->g_cme_common_ring_length       =   0;
            pImgHdr->g_cme_scom_offset              =   0;
            pImgHdr->g_cme_scom_length              =   CORE_SCOM_PER_CME;
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
     * @param[in]   i_imgType       image sections  to be built
     * @return IMG_BUILD_SUCCESS if function succeeds, error code otherwise.
     */
    uint32_t buildPgpeImage( void* const i_pImageIn, Homerlayout_t* i_pChipHomer,
                             ImageType_t i_imgType )
    {
        uint32_t retCode = IMG_BUILD_SUCCESS;
        FAPI_INF("> PGPE Img build")

        do
        {
            uint32_t rcTemp = 0;
            //Let us find XIP Header for SGPE
            P9XipSection ppeSection;
            uint8_t* pPgpeImg = NULL;

            if(!i_imgType.pgpeImageBuild )
            {
                break;
            }

            rcTemp = p9_xip_get_section( i_pImageIn, P9_XIP_SECTION_HW_PGPE, &ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to get PGPE XIP Image Header" );
                retCode = BUILD_FAIL_PGPE_IMAGE;
                break;
            }

            pPgpeImg = ppeSection.iv_offset + (uint8_t*) (i_pImageIn );

            rcTemp = copySectionToHomer( i_pChipHomer->ppmrRegion.l1BootLoader, pPgpeImg,
                                         P9_XIP_SECTION_PGPE_LVL1_BL, PLAT_SGPE, ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy PGPE Level1 bootloader");
                retCode = BUILD_FAIL_PGPE_BL1;
                break;
            }


            rcTemp = copySectionToHomer( i_pChipHomer->ppmrRegion.l2BootLoader, pPgpeImg,
                                         P9_XIP_SECTION_PGPE_LVL2_BL, PLAT_PGPE, ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy PGPE Level2 bootloader");
                retCode = BUILD_FAIL_PGPE_BL2;
                break;
            }

            rcTemp = copySectionToHomer( i_pChipHomer->ppmrRegion.pgpeBin.hcode, pPgpeImg,
                                         P9_XIP_SECTION_PGPE_HCODE, PLAT_PGPE, ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy PGPE hcode");
                retCode = BUILD_FAIL_PGPE_HCODE;
                break;
            }

            //FIXME PGPE image header shall be populated after its definition is published.

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

            FAPI_DBG("================== Input Buffer Specs ====================");
            FAPI_DBG("Ring section (buf,size)=(0x%016llX,0x%08X)",
                     (uintptr_t)(i_ringData.iv_pRingBuffer), i_ringData.iv_ringBufSize);
            FAPI_DBG("Work buf1 (buf,size)=(0x%016llX,0x%08X)",
                     (uintptr_t)(i_ringData.iv_pWorkBuf1), i_ringData.iv_sizeWorkBuf1);
            FAPI_DBG("Work buf2 (buf,size)=(0x%016llX,0x%08X)",
                     (uintptr_t)(i_ringData.iv_pWorkBuf2), i_ringData.iv_sizeWorkBuf2);
            FAPI_DBG("================== Buffer Specs Ends ====================");

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
        sgpeHeader_t* pSgpeImgHdr = (sgpeHeader_t*)&i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECT];
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

            for( uint32_t ringIndex = 0; ringIndex < EQ::g_eqData.iv_num_common_rings;
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
                                          CACH0_CHIPLET_ID,
                                          &i_ringData.iv_pWorkBuf2,
                                          tempBufSize,
                                          1 );

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
                sgpeOvrdRings.extractRing( i_ringData.iv_pWorkBuf1, tempBufSize, sgpeOvrdRings.getCommonRingId( ringIndex ) );

                pOvrdRingPayload = pOvrdRingPayload + tempBufSize;
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

        sgpeOvrdRings.dumpOverrideRings();

        FAPI_DBG("====================SGPE Override Rings================" );
        FAPI_DBG("====================SGPE Header ========================");
        FAPI_DBG("Override Ring Offset 0x%08X", SWIZZLE_4_BYTE(pSgpeImgHdr->g_sgpe_cmn_ring_ovrd_occ_offset));

        FAPI_INF("< layoutSgpeScanOverride")
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
     * @param   io_cmnRingSize  input: CME region length populated. output: CME region length after copying cmn ring.
     * @param   IMG_BUILD_SUCCESS   if function succeeds else error code.
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

            for( uint32_t ringIndex = 0; ringIndex < EC::g_ecData.iv_num_common_rings;
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
                                          1 );

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
        uint32_t ringStartToHdrOffset = ( TOR_VER_ONE == P9_TOR::tor_version() ) ? RING_START_TO_RS4_OFFSET : 0;

        do
        {
            if( !i_imgType.cmeCoreSpecificRingBuild )
            {
                break;
            }

            for( uint32_t exId = 0; exId < MAX_CME_PER_CHIP; exId++ )
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
                                              1 );

                    if( (i_ringData.iv_sizeWorkBuf1 == tempSize) || (0 == tempSize ) ||
                        ( 0 != rc ) )
                    {
                        FAPI_DBG( "could not determine size of ring id %d of core %d",
                                  io_cmeRings.getInstRingId(0), ((2 * exId) + coreId) );
                        continue;
                    }

                    ringLength += tempSize;
                }

                ALIGN_DWORD(tempSize, ringLength)
                maxCoreSpecRingLength = ringLength > maxCoreSpecRingLength ? ringLength : maxCoreSpecRingLength;
            }

            maxCoreSpecRingLength += sizeof(CoreSpecRingList_t);
            ROUND_OFF_32B(maxCoreSpecRingLength);

            FAPI_DBG("Max Instance Spec Ring 0x%08X", maxCoreSpecRingLength);
            // Let us copy the rings now.

            uint8_t* pRingStart = NULL;
            uint8_t* pRingPayload = NULL;
            uint16_t* pScanRingIndex = NULL;

            for( uint32_t exId = 0; exId < MAX_CME_PER_CHIP; exId++ )
            {
                pRingStart = (uint8_t*)&i_pHomer->cpmrRegion.cmeSramRegion[io_ringLength + ( exId * maxCoreSpecRingLength ) ];
                pRingPayload = &i_pHomer->cpmrRegion.cmeSramRegion[ io_ringLength + ( exId * maxCoreSpecRingLength ) ];
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
                                              1 );

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

            for( uint8_t ringIndex = 0; ringIndex < EC::g_ecData.iv_num_common_rings;
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
                                          1 );

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
                cmeOvrdRings.extractRing( i_ringData.iv_pWorkBuf1, tempBufSize, cmeOvrdRings.getCommonRingId( ringIndex ) );

                pOverrideRingPayload = pOverrideRingPayload + tempBufSize;
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
                                   l_ringVariant,
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

            //get core common rings
            for( ; ringIndex < EQ::g_eqData.iv_num_common_rings; ringIndex++ )
            {
                tempBufSize = i_ringData.iv_sizeWorkBuf1;

                rc = tor_get_single_ring( i_ringData.iv_pRingBuffer,
                                          P9_XIP_MAGIC_SGPE,
                                          i_chipState.getChipLevel(),
                                          io_sgpeRings.getCommonRingId( ringIndex ),
                                          P9_TOR::SGPE,
                                          i_ringVariant,
                                          CACH0_CHIPLET_ID,
                                          &i_ringData.iv_pWorkBuf1,
                                          tempBufSize,
                                          1 );

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

            for( uint32_t cacheInst = 0; cacheInst < MAX_CACHE_CHIPLET; cacheInst++ )
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
                    chipletId = ExChipletRingMap.getInstanceId( CACH0_CHIPLET_ID + cacheInst , ringIndex );

                    rc = tor_get_single_ring( i_ringData.iv_pRingBuffer,
                                              P9_XIP_MAGIC_SGPE,
                                              i_chipState.getChipLevel(),
                                              io_sgpeRings.getInstRingId( ringIndex ),
                                              P9_TOR::SGPE,
                                              i_ringVariant,
                                              chipletId,
                                              &i_ringData.iv_pWorkBuf1,
                                              tempBufSize,
                                              1 );

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
        sgpeHeader_t* pSgpeImgHdr   =   (sgpeHeader_t*)& i_pHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECT];
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
                                    l_ringVariant,
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

        uint32_t attrVal = SWIZZLE_4_BYTE(pQpmrHdr->bootCopierOffset);
        attrVal |= (0x80000000 | ONE_MB);

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_STOPGPE_BOOT_COPIER_IVPR_OFFSET,
                               i_procTgt,
                               attrVal ),
                 "Error from FAPI_ATTR_SET for attribute ATTR_STOPGPE_BOOT_COPIER_IVPR_OFFSET");

        FAPI_DBG("Set ATTR_STOPGPE_BOOT_COPIER_IVPR_OFFSET to 0x%08X", attrVal );

        attrVal = (uint8_t*)(i_pChipHomer->ppmrRegion.l1BootLoader) - (uint8_t*)(i_pChipHomer);
        attrVal |= 0x80000000;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PSTATEGPE_BOOT_COPIER_IVPR_OFFSET,
                               i_procTgt,
                               attrVal ),
                 "Error from FAPI_ATTR_SET for attribute ATTR_PSTATEGPE_BOOT_COPIER_IVPR_OFFSET");

        FAPI_DBG("Set ATTR_PSTATEGPE_BOOT_COPIER_IVPR_OFFSET to 0x%08X", attrVal );
    fapi_try_exit:
        return fapi2::current_err;
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
        fapi2::ReturnCode retCode;

        do
        {
            FAPI_DBG("validating argument ..");

            retCode = validateInputArguments( i_pImageIn, i_pHomerImage, i_phase,
                                              i_imgType,
                                              i_pBuf1,
                                              i_sizeBuf1,
                                              i_pBuf2,
                                              i_sizeBuf2,
                                              i_pBuf3,
                                              i_sizeBuf3 );

            if( retCode )
            {
                FAPI_ERR("Invalid arguments, escaping hcode image build");
                break;
            }

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
            ppeImgRc = buildSgpeImage( i_pImageIn, pChipHomer, i_imgType, l_qpmrHdr );

            FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                         fapi2::SGPE_BUILD_FAIL()
                         .set_SGPE_FAIL_SECTN( ppeImgRc ),
                         "Failed to copy SGPE section in HOMER" );
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
            ppeImgRc = buildCoreRestoreImage( i_pImageIn, pChipHomer, i_imgType, fuseModeState );

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
            ppeImgRc = buildCmeImage( i_pImageIn, pChipHomer, i_imgType, cpmrPhyAdd );

            FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                         fapi2::CME_BUILD_FAIL()
                         .set_CME_FAIL_SECTN( ppeImgRc ),
                         "Failed to copy CME section in HOMER" );
            FAPI_INF("CME built");

            FAPI_INF("PGPE building");
            //FIXME RTC 148009 PGPE Header needs to be defined.
            ppeImgRc = buildPgpeImage( i_pImageIn, pChipHomer, i_imgType );

            FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                         fapi2::PGPE_BUILD_FAIL()
                         .set_PGPE_FAIL_SECTN( ppeImgRc ),
                         "Failed to copy PGPE section in HOMER" );

            FAPI_INF("PGPE built");

            //Let us add Scan Rings to the image.
            uint8_t l_ringDebug = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RING_DBG_MODE,
                                   FAPI_SYSTEM,
                                   l_ringDebug),
                     "Error from FAPI_ATTR_GET for attribute ATTR_SYSTEM_RING_DBG_MODE");

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

            if( ppeImgRc )
            {
                FAPI_ERR( "failed to extract core scan rings rc = 0x%08X", ppeImgRc );
                break;
            }

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

            if( ppeImgRc )
            {
                FAPI_ERR("Failed to copy core Scan rings in HOMER rc 0x%08X", ppeImgRc );
                break;
            }

            l_ringData.iv_ringBufSize = i_sizeBuf1;
            ppeImgRc = getPpeScanRings( i_pImageIn,
                                        PLAT_SGPE,
                                        i_procTgt,
                                        l_ringData,
                                        i_imgType );

            if( ppeImgRc )
            {
                FAPI_ERR( "failed to extract quad/ex scan rings" );
                break;
            }

            // create a layout of rings in HOMER for consumption of SGPE
            ppeImgRc = layoutRingsForSGPE(  pChipHomer,
                                            i_pRingOverride,
                                            l_chipFuncModel,
                                            l_ringData,
                                            (RingDebugMode_t)l_ringDebug,
                                            l_iplPhase,
                                            l_qpmrHdr,
                                            i_imgType );

            if( ppeImgRc )
            {
                FAPI_ERR("Failed to copy quad/ex Scan rings in HOMER rc 0x%08X", ppeImgRc );
                break;
            }

            //Update CPMR Header with Scan Ring details
            updateCpmrCmeRegion( pChipHomer );

            //Update QPMR Header area in HOMER
            updateQpmrHeader( pChipHomer, l_qpmrHdr );

            //validate SRAM Image Sizes of PPE's
            uint32_t sramImgSize = 0;
            ppeImgRc = validateSramImageSize( pChipHomer, sramImgSize );
            FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                         fapi2::IMG_EXCEED_SRAM_SIZE( )
                         .set_BAD_IMG_SIZE( sramImgSize ),
                         "SRAM Image Size Exceeded Max Allowed Size" );

            //Finally update the attributes storing PGPE and SGPE's boot copier offset.
            retCode = updateGpeAttributes( pChipHomer, i_procTgt );

            if( retCode )
            {
                FAPI_ERR("Failed to update SGPE/PGPE IVPR attributes");
                break;
            }
        }
        while(0);

        FAPI_IMP("Exit p9_hcode_image_build" );

    fapi_try_exit:
        return retCode;
    }

    } //namespace p9_hcodeImageBuild ends

}// extern "C"
