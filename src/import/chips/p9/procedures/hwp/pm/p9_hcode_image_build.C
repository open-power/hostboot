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
#include <p9_hcode_image_build.H>
#include "p9_xip_image.h"
#include "p9_hcode_image_defines.H"
#include "p9_stop_util.H"
#include "p9_tor.H"

using namespace stopImageSection;
extern "C"
{
    namespace p9_hcodeImageBuild
    {

    enum E_PLAT_ID
    {
        PLAT_SELF   =   0,
        PLAT_CME    =   1,
        PLAT_SGPE   =   2,
        PLAT_PGPE   =   3,
    };

    /**
     * @brief   validates arguments passed for hcode image build
     * @param   refer to p9_hcode_image_build arguments
     * @return  fapi2 return code
     */
    fapi2::ReturnCode validateInputArguments( void* const i_pImageIn, void* i_pImageOut,
            SysPhase_t i_phase, ImageType_t i_imgType,
            void* i_pBuf1, uint32_t i_bufSize1, void* i_pBuf2,
            uint32_t i_bufSize2 )
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

        FAPI_DBG("size is 0x%08x; xip_image_size RC is 0x%02x HARDWARE_IMG_SIZE 0x%08x  Sz 0x%08x",
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

        FAPI_ASSERT( (( i_bufSize1 != 0  ) && ( i_bufSize2 != 0 )),
                     fapi2::HCODE_TEMP_BUF_SIZE()
                     .set_TEMP_BUF1_SIZE( i_bufSize1 )
                     .set_TEMP_BUF2_SIZE( i_bufSize2 ),
                     "Invalid work buffer size " );

        FAPI_ASSERT( ( i_pBuf2 != NULL ),
                     fapi2::HCODE_INVALID_TEMP_BUF()
                     .set_TEMP_BUF_PTR( i_pBuf2 ),
                     "Invalid temp buffer2 passed for hcode image build" );

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
    uint32_t copySectionToHomer( uint8_t* i_destPtr, uint8_t* i_srcPtr, uint8_t i_secId, E_PLAT_ID i_platId ,
                                 P9XipSection&   o_ppeSection )
    {
        FAPI_INF("> copySectionToHomer");
        uint32_t retCode = IMG_BUILD_SUCCESS;

        do
        {
            o_ppeSection.iv_offset = 0;
            o_ppeSection.iv_size = 0;
            uint32_t rcTemp = p9_xip_get_section( i_srcPtr, i_secId, &o_ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to get section 0x%08x of Plat 0x%08x", i_secId, i_platId );
                break;
            }

            FAPI_DBG("o_ppeSection.iv_offset = %X, "
                     "o_ppeSection.iv_size = %X, "
                     "i_secId %d",
                     o_ppeSection.iv_offset,
                     o_ppeSection.iv_size,
                     i_secId);
            memcpy( i_destPtr, i_srcPtr + o_ppeSection.iv_offset, o_ppeSection.iv_size );
        }
        while(0);

        FAPI_INF("< copySectionToHomer");
        return retCode;
    }

//------------------------------------------------------------------------------

    /**
     * @brief   updates various CPMR fields which are not associated with scan rings.
     * @param   i_pChipHomer    points to start of P9 HOMER.
     */
    void updateCpmrHeaderCME( Homerlayout_t* i_pChipHomer)
    {
        FAPI_INF("> updateCpmrHeaderCME");

        cpmrHeader_t* pCpmrHdr =
            (cpmrHeader_t*) & (i_pChipHomer->cpmrRegion.selfRestoreRegion.CPMR_SR.elements.CPMRHeader);

        cmeHeader_t* pCmeHdr =  NULL;
        pCmeHdr = (cmeHeader_t*) & i_pChipHomer->cpmrRegion.cmeBin.elements.imgHeader;


        //offset is multiple of 32B for quick setting of MBASE of CME's BCE
        pCpmrHdr->cmeImgOffset = SWIZZLE_4_BYTE((CPMR_CME_HCODE_OFFSET >> CME_BLK_SIZE_SHIFT));
        // populate the CME binary's size
        pCpmrHdr->cmeImgLength = pCmeHdr->g_cme_hcode_length;

        pCpmrHdr->cmePstateOffset        =  0;
        pCpmrHdr->cmePstateLength        =  0;
        pCpmrHdr->coreScomOffset         =  SWIZZLE_4_BYTE((CORE_SCOM_START >> CME_BLK_SIZE_SHIFT));
        pCpmrHdr->coreScomLength         =  SWIZZLE_4_BYTE((CORE_SCOM_RES_SIZE >> CME_BLK_SIZE_SHIFT));

        FAPI_INF("CPMR CME Hcode");
        FAPI_INF("  CME Offset              = 0x%08X (Real offset / 32)", SWIZZLE_4_BYTE(pCpmrHdr->cmeImgOffset));
        FAPI_INF("  CME Size                = 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->cmeImgLength));
        FAPI_INF("  CME SCOM Offset         = 0x%08x", SWIZZLE_4_BYTE(pCpmrHdr->coreScomOffset) );
        FAPI_INF("  CME SCOM Length         = 0x%08x", SWIZZLE_4_BYTE(pCpmrHdr->coreScomLength) );


        FAPI_INF("< updateCpmrHeaderCME");
    }

//------------------------------------------------------------------------------

    /**
     * @brief   updates various CPMR fields which are associated with scan rings.
     * @param   i_pChipHomer    points to start of P9 HOMER.
     */
    void updateCpmrScanRing( Homerlayout_t* i_pChipHomer )
    {
        cpmrHeader_t* pCpmrHdr =
            (cpmrHeader_t*) & (i_pChipHomer->cpmrRegion.selfRestoreRegion.CPMR_SR.elements.CPMRHeader);
        cmeHeader_t* pCmeHdr =  NULL;
        pCmeHdr = (cmeHeader_t*) & i_pChipHomer->cpmrRegion.cmeBin.elements.imgHeader;
        pCpmrHdr->cmeCommonRingOffset    =  (uint8_t*) i_pChipHomer->cpmrRegion.commonRings -
                                            (uint8_t*) &i_pChipHomer->cpmrRegion;
        pCpmrHdr->cmeCommonRingOffset    =  SWIZZLE_4_BYTE(pCpmrHdr->cmeCommonRingOffset);

        pCpmrHdr->cmeCommonRingLength    =  pCmeHdr->g_cme_common_ring_length;
        pCpmrHdr->coreSpecRingOffset     =  SWIZZLE_4_BYTE(CME_INST_SPEC_RING_START);
        pCpmrHdr->coreSpecRingLength     =  pCmeHdr->g_cme_max_spec_ring_length; // already swizzled

        FAPI_INF("CPMR CME Scan Rings");
        FAPI_INF("  CME CMN Ring Offset     = 0x%08x", SWIZZLE_4_BYTE(pCpmrHdr->cmeCommonRingOffset) );
        FAPI_INF("  CME CMN Ring Length     = 0x%08x", SWIZZLE_4_BYTE(pCpmrHdr->cmeCommonRingLength) );
        FAPI_INF("  CME Spec Ring Length    = 0x%08x", SWIZZLE_4_BYTE(pCpmrHdr->coreSpecRingLength) );

        FAPI_INF("CME Header Scan Rings");
        FAPI_INF("  CME Cmn Ring Offset         = 0x%08x", SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_offset));
        FAPI_INF("  CME Cmn Ring Length         = 0x%08x", SWIZZLE_4_BYTE(pCmeHdr->g_cme_common_ring_length) );
        FAPI_INF("  Core Instance Ring Offset   = 0x%08x (Real offset / 32) ",
                 SWIZZLE_4_BYTE(pCmeHdr->g_cme_core_spec_ring_offset));
        FAPI_INF("  Core Instance Ring Length   = 0x%08x (Real length / 32)",
                 SWIZZLE_4_BYTE(pCmeHdr->g_cme_max_spec_ring_length) );
        FAPI_INF("  Core Spec Ovrd Ring Offset  = 0x%08x", SWIZZLE_4_BYTE(pCmeHdr->g_cme_core_spec_ring_ovrd_offset ));

    }

//------------------------------------------------------------------------------
    /**
     * @brief   updates various CPMR fields which are associated with self restore code.
     * @param   i_pChipHomer    points to start of P9 HOMER.
     * @param   i_fuseState     core fuse status
     */
    void updateCpmrHeaderSR( Homerlayout_t* i_pChipHomer, uint8_t i_fuseState )
    {
        FAPI_INF("> updateCpmrHeaderSR");
        cpmrHeader_t* pCpmrHdr =
            (cpmrHeader_t*) & (i_pChipHomer->cpmrRegion.selfRestoreRegion.CPMR_SR.elements.CPMRHeader);

        cmeHeader_t* pCmeHdr =  NULL;
        pCmeHdr = (cmeHeader_t*) & i_pChipHomer->cpmrRegion.cmeBin.elements.imgHeader;
        //populate CPMR header
        pCpmrHdr->fuseModeStatus = SWIZZLE_4_BYTE(i_fuseState ? FUSE_STATE : UNFUSE_STATE);

        pCmeHdr->g_cme_mode_flags = SWIZZLE_4_BYTE(i_fuseState ? 1 : 0);

        FAPI_INF("CPMR SR");
        FAPI_INF("  Fuse Mode = 0x%08X CME Image Flag = 0x%08X", SWIZZLE_4_BYTE(pCpmrHdr->fuseModeStatus),
                 SWIZZLE_4_BYTE(pCmeHdr->g_cme_mode_flags));
        FAPI_DBG("  Offset    = 0x%08X (Real offset / 32)", SWIZZLE_4_BYTE(pCpmrHdr->cmeImgOffset));
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
        memcpy( pQpmrHdr, &io_qpmrHdr, sizeof( QpmrHeaderLayout_t ) );
        pQpmrHdr->quadCommonRingOffset = (uint8_t*) i_pChipHomer->qpmrRegion.sgpeRegion.commonRings -
                                         (uint8_t*) &i_pChipHomer->qpmrRegion.sgpeRegion;

        pQpmrHdr->quadCommonRingOffset = SWIZZLE_4_BYTE(pQpmrHdr->quadCommonRingOffset);

        FAPI_INF("QPMR");
        FAPI_INF("  Magic Num       = 0x%16lX", SWIZZLE_8_BYTE(pQpmrHdr->magic_number));
        FAPI_INF("  Build Date      = 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->buildDate));
        FAPI_INF("  Version         = 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->buildVersion));
        FAPI_INF("  BC Offset       = 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->bootCopierOffset));
        FAPI_INF("  BL Offset       = 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->bootLoaderOffset));
        FAPI_INF("  BL Size         = 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->bootLoaderLength));
        FAPI_INF("  HC Offset       = 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->sgpeImgOffset));
        FAPI_INF("  HC Size         = 0x%08X", SWIZZLE_4_BYTE(pQpmrHdr->sgpeImgLength));
        FAPI_DBG("  Cmn Ring Offset = 0x%08x", SWIZZLE_4_BYTE(pQpmrHdr->quadCommonRingOffset) );
        FAPI_DBG("  Cmn Ring Length = 0x%08x", SWIZZLE_4_BYTE(pQpmrHdr->quadCommonRingLength) );

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
                rcTemp = BUILD_FAIL_SGPE_QPMR;
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
                rcTemp = BUILD_FAIL_SGPE_BL1;
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
                rcTemp = BUILD_FAIL_SGPE_BL2;
                break;
            }

            o_qpmrHdr.bootLoaderOffset = o_qpmrHdr.bootCopierOffset + SGPE_LVL_1_BOOT_LOAD_SIZE;
            o_qpmrHdr.bootLoaderLength = ppeSection.iv_size;

            FAPI_INF("SGPE Boot Loader QPMR Offset = 0x%08X, Size = 0x%08X",
                     o_qpmrHdr.bootLoaderOffset, o_qpmrHdr.bootLoaderLength);

            // The image in the HW Image has the Interrupt Vectors, SGPE Header and Debug
            // Pointer already included.  Thus, load the "Hcode Image" starting at the
            // sgpeRegion.hcodeIntVect location.
            rcTemp = copySectionToHomer( i_pChipHomer->qpmrRegion.sgpeRegion.hcodeIntVect,
                                         pSgpeImg,
                                         P9_XIP_SECTION_SGPE_HCODE,
                                         PLAT_SGPE,
                                         ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy SGPE hcode");
                rcTemp = BUILD_FAIL_SGPE_HCODE;
                break;
            }

            FAPI_DBG("SGPE Hcode       QPMR Offset = 0x%08X, Size = 0x%08X",
                     SWIZZLE_4_BYTE(o_qpmrHdr.sgpeImgOffset),
                     SWIZZLE_4_BYTE(o_qpmrHdr.sgpeImgLength));

            o_qpmrHdr.sgpeImgOffset = o_qpmrHdr.bootLoaderOffset + SGPE_LVL_2_BOOT_LOAD_SIZE;

            //let us take care of endianess now.
            o_qpmrHdr.sgpeImgLength       = SWIZZLE_4_BYTE(ppeSection.iv_size);
            o_qpmrHdr.bootLoaderOffset    = SWIZZLE_4_BYTE(o_qpmrHdr.bootLoaderOffset);
            o_qpmrHdr.bootCopierOffset    = SWIZZLE_4_BYTE(o_qpmrHdr.bootCopierOffset);
            o_qpmrHdr.sgpeImgOffset       = SWIZZLE_4_BYTE(o_qpmrHdr.sgpeImgOffset);
            o_qpmrHdr.bootLoaderLength    = SWIZZLE_4_BYTE(o_qpmrHdr.bootLoaderLength);

            //FIXME Need to confirm it
            o_qpmrHdr.quadSpecScomOffset  = SWIZZLE_4_BYTE(CACHE_SCOM_START);

            sgpeHeader_t* pImgHdr = (sgpeHeader_t*)& i_pChipHomer->qpmrRegion.sgpeRegion.imgHeader;
            pImgHdr->g_sgpe_cmn_ring_occ_offset = o_qpmrHdr.sgpeImgLength;

            FAPI_INF("SGPE Header");
            FAPI_INF("  Magic Num     = 0x%16lX", SWIZZLE_8_BYTE(pImgHdr->g_sgpe_magic_number));
            FAPI_INF("  Reset Addr    = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_reset_address));
            FAPI_INF("  IVPR Addr     = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_ivpr_address));
            FAPI_INF("  Build Date    = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_build_date));
            FAPI_INF("  Version       = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_build_ver));
            FAPI_INF("  CR OCC Offset = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_cmn_ring_occ_offset));
            FAPI_INF("  SR OCC Offset = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_spec_ring_occ_offset));
            FAPI_INF("  SCOM Offset   = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_sgpe_cmn_scom_offset));

            //updating SGPE Image header in HOMER
            // FIXME Need to handle fields related SCOM OCC offsets

            uint32_t regionLimit = CACHE_SCOM_RESTORE_SIZE >> 2;

            FAPI_DBG("Padding SCOM region starting for 0x%08X bytes", CACHE_SCOM_RESTORE_SIZE);
            uint32_t l_fillPattern = PAD_OPCODE;

            for( uint32_t wordCnt = 0; wordCnt < regionLimit; wordCnt++ )
            {
                memcpy( i_pChipHomer->qpmrRegion.cacheScomRegion, &l_fillPattern, sizeof(uint32_t) );
            }
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
                                    uint8_t i_fuseState )
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

            updateCpmrHeaderSR( i_pChipHomer, i_fuseState );
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
                            ImageType_t i_imgType )
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

            if( i_imgType.cmeHcodeBuild )
            {
                // The image in the HW Image has the Interrupt Vectors, CME Header and Debug
                // Pointers already included.
                rcTemp = copySectionToHomer(  i_pChipHomer->cpmrRegion.cmeBin.hcode, pCmeImg,
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
                cmeHeader_t* pImgHdr = (cmeHeader_t*) & i_pChipHomer->cpmrRegion.cmeBin.elements.imgHeader;
                pImgHdr->g_cme_hcode_offset =  SWIZZLE_4_BYTE(CME_SRAM_HCODE_OFFSET);
                pImgHdr->g_cme_hcode_length =  SWIZZLE_4_BYTE(ppeSection.iv_size);

                //Populating common ring offset here. So, that other scan ring related field can be updated.
                pImgHdr->g_cme_common_ring_offset =  SWIZZLE_4_BYTE(pImgHdr->g_cme_hcode_offset) +
                                                     SWIZZLE_4_BYTE(pImgHdr->g_cme_hcode_length);
                pImgHdr->g_cme_common_ring_offset =  SWIZZLE_4_BYTE(pImgHdr->g_cme_common_ring_offset);
                pImgHdr->g_cme_common_ring_length       = 0;
                pImgHdr->g_cme_pstate_region_offset     = 0;
                pImgHdr->g_cme_pstate_region_length     = 0;
                pImgHdr->g_cme_core_spec_ring_offset    = 0;    // multiple of 32B blocks
                pImgHdr->g_cme_max_spec_ring_length     = 0;    // multiple of 32B blocks

                FAPI_INF("CME Header");
                FAPI_INF("  Magic Num = 0x%16lX", SWIZZLE_8_BYTE(pImgHdr->g_cme_magic_number));
                FAPI_INF("  HC Offset = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_cme_hcode_offset));
                FAPI_INF("  HC Size   = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_cme_hcode_length));
                FAPI_INF("  CR Offset = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_cme_common_ring_offset));
                FAPI_INF("  CR Size   = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_cme_common_ring_length));
                FAPI_INF("  PS Offset = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_cme_pstate_region_offset));
                FAPI_INF("  PS Size   = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_cme_pstate_region_length));
                FAPI_INF("  SR Offset = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_cme_core_spec_ring_offset));
                FAPI_INF("  SR Size   = 0x%08X", SWIZZLE_4_BYTE(pImgHdr->g_cme_max_spec_ring_length));
            }
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
                rcTemp = BUILD_FAIL_PGPE_BL1;
                break;
            }


            rcTemp = copySectionToHomer( i_pChipHomer->ppmrRegion.l2BootLoader, pPgpeImg,
                                         P9_XIP_SECTION_PGPE_LVL2_BL, PLAT_PGPE, ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy PGPE Level2 bootloader");
                rcTemp = BUILD_FAIL_SGPE_BL2;
                break;
            }

            rcTemp = copySectionToHomer( i_pChipHomer->ppmrRegion.pgpeBin.hcode, pPgpeImg,
                                         P9_XIP_SECTION_PGPE_HCODE, PLAT_PGPE, ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy PGPE hcode");
                rcTemp = BUILD_FAIL_PGPE_HCODE;
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
     * @brief   copies Base flavor of scan rings
     * @param   i_pImageIn          points to start of hardware image.
     * @param   i_pChipHomerLoc     points to HOMER image.
     * @param   i_ddLevel           dd level of P9 chip.
     * @param   i_pBuf1             work buffer.
     * @param   io_copyLength       buffer max length[in]/length copied[out].
     * @param   i_platId            platform associated with scan ring.
     * @param   i_instanceId        chiplet id.
     * @param   i_ringQuery         query for ring presence.
     * @return IMG_BUILD_SUCCESS if function succeeds, error code otherwise.
     */
    uint32_t copyScanRings(
        void* const i_pImageIn,
        uint8_t* i_pChipHomerLoc,
        uint8_t i_ddLevel,
        void* i_pBuf1,
        uint32_t& io_copyLength,
        E_PLAT_ID i_platId,
        uint8_t i_instanceId,
        bool i_ringQuery = false )
    {
        FAPI_INF("> copyScanRings")
        uint32_t rc = IMG_BUILD_SUCCESS;
        uint32_t tempBufLength = io_copyLength;
        P9_TOR::RingType ringType = (i_instanceId == IGNORE_CHIPLET_INSTANCE ) ? P9_TOR::COMMON : P9_TOR::INSTANCE;

        do
        {
            P9XipSection ppeSection;
            rc = p9_xip_get_section( i_pImageIn, P9_XIP_SECTION_HW_RINGS, &ppeSection );

            if( rc )
            {
                FAPI_ERR("Failed to access common scan rings Plat 0x%08x", i_platId );
                rc = BUILD_FAIL_CMN_RINGS;
                break;
            }

            uint8_t* pScanRing = ppeSection.iv_offset + (uint8_t*) (i_pImageIn );

            if( ( PLAT_CME != i_platId ) && ( PLAT_SGPE != i_platId ) )
            {
                FAPI_ERR(" scan ring not supported for platform 0x%d", i_platId );
                break;
            }

            rc = tor_get_block_of_rings( pScanRing,
                                         i_ddLevel,
                                         ((PLAT_CME == i_platId) ? P9_TOR::CME : P9_TOR::SGPE),
                                         ringType,
                                         P9_TOR::BASE,
                                         i_instanceId,
                                         &i_pBuf1,
                                         tempBufLength );
            FAPI_INF("Ring type 0x%08x instance 0x%08x  buf len 0x%08x", ringType, i_instanceId, tempBufLength );

            if( rc )
            {
                FAPI_ERR(" common scan ring block not copied rc 0x%08x Length  0x%08x", rc, tempBufLength );
                break;
            }

            if( tempBufLength == io_copyLength )
            {
                FAPI_DBG(" Scan ring block size not updated");
                io_copyLength = 0;
                rc = BUILD_FAIL_CMN_RINGS;
                break;
            }

            if( !i_ringQuery )
            {
                memcpy( i_pChipHomerLoc, (uint8_t*)i_pBuf1, tempBufLength );
            }

            io_copyLength = tempBufLength;

            FAPI_DBG("Copied Ring For:   %s", (PLAT_CME == i_platId) ? "CME" : "SGPE" );
            FAPI_DBG("Ring Type:           %s",
                     ( i_instanceId == IGNORE_CHIPLET_INSTANCE ) ? "Common" : "Instance");
            FAPI_DBG("Chiplet Id:          %d",
                     ( i_instanceId == IGNORE_CHIPLET_INSTANCE ) ? IGNORE_CHIPLET_INSTANCE : i_instanceId );
            FAPI_DBG("Ring Length:       0x%08x", io_copyLength );
            FAPI_DBG("DD Level:          0x%08x", i_ddLevel );
            FAPI_DBG("Action:            %s", i_ringQuery ? "Query" : "Copy", i_ddLevel );
        }
        while(0);

        FAPI_INF("< copyScanRings")
        return rc;
    }

    //---------------------------------------------------------------------------

    /**
     * @brief   copies override flavor of scan rings.
     * @param   i_pOverride         points to override scanrings.
     * @param   i_pHomerLoc         points to HOMER image.
     * @param   i_ddLevel           dd level of P9 chip.
     * @param   i_ringType          COMMON/INSTANCE
     * @param   i_pTempBuf          Work buffer
     * @param   io_copyLength       Work buffer max length[in]/length copied[out].
     * @param   i_platId            platform associated with scan ring.
     * @param   i_instanceId        chiplet id.
     * @param   i_ringQuery         query for ring presence.
     * @return IMG_BUILD_SUCCESS if function succeeds, error code otherwise.
     */
    uint32_t copyScanOverrideRing( void* const  i_pOverride,
                                   void* const  i_pHomerLoc,
                                   uint8_t const i_ddLevel,
                                   P9_TOR::RingType_t i_ringType,
                                   void* i_pTempBuf,
                                   uint32_t&      io_bufLength,
                                   E_PLAT_ID i_platId,
                                   uint8_t i_instanceId,
                                   bool i_queryRing = false )
    {
        uint32_t rc = IMG_BUILD_SUCCESS;

        do
        {
            if( ( PLAT_CME != i_platId ) && ( PLAT_SGPE != i_platId ) )
            {
                FAPI_ERR(" scan ring not supported for platform 0x%d", i_platId );
                break;
            }

            if( !i_pOverride )
            {
                FAPI_DBG( "Override not defined");
                io_bufLength = 0;
                break;
            }

            uint32_t tempBufLength = io_bufLength;

            rc = tor_get_block_of_rings( i_pOverride,
                                         i_ddLevel,
                                         ((PLAT_CME == i_platId) ? P9_TOR::CME : P9_TOR::SGPE),
                                         i_ringType,
                                         P9_TOR::OVERRIDE,
                                         i_instanceId,
                                         &i_pTempBuf,
                                         io_bufLength );

            if( IMGBUILD_TGR_AMBIGUOUS_API_PARMS == rc )
            {
                FAPI_ERR("Invalid parameter, Overrides for %s ,rc 0x%08x",
                         ((PLAT_CME == i_platId) ? "CME" : "SGPE" ), rc );
                rc = BUILD_FAIL_CMN_RINGS;
                io_bufLength = 0;
                break;
            }

            if( tempBufLength == io_bufLength )
            {
                FAPI_DBG(" %s Overrides not found for %s",
                         ((i_instanceId == IGNORE_CHIPLET_INSTANCE ) ? "Common" : "Inst Speccific"),
                         ((PLAT_CME == i_platId) ? "CME" : "SGPE" ));

                io_bufLength = 0;
                //Not finding overrides cannot be regarded as error.
                //Production Systems will not have scan overrides. So, let us continue.
                rc = IMG_BUILD_SUCCESS;
            }

            if( !i_queryRing )
            {
                memcpy( i_pHomerLoc, (uint8_t*)i_pTempBuf, io_bufLength );
            }

            FAPI_DBG("Override Ring For:   %s", (PLAT_CME == i_platId) ? "CME" : "SGPE" );
            FAPI_DBG("Ring Type:           %s",
                     ( i_instanceId == IGNORE_CHIPLET_INSTANCE ) ? "Common" : "Instance");
            FAPI_DBG("Chiplet Id:          %d",
                     ( i_instanceId == IGNORE_CHIPLET_INSTANCE ) ? IGNORE_CHIPLET_INSTANCE : i_instanceId );
            FAPI_DBG("Ring Length:        0x%08x", io_bufLength );
            FAPI_DBG("DD Level:           0x%08x", i_ddLevel );
            FAPI_DBG("Action:             %s", i_queryRing ? "Query" : "Copy" );
        }
        while(0);

        return rc;
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
    uint32_t copyRingsFromHwImage(
        void* const i_pImageIn,
        void* const i_pOverride,
        void* const o_pImageOut,
        uint8_t i_ddLevel,
        void* const i_pBuf1,
        const uint32_t i_bufSize1,
        void*    i_pBuf2,
        const uint32_t i_bufSize2,
        ImageType_t i_imgType,
        QpmrHeaderLayout_t& o_qpmr,
        E_PLAT_ID i_platId )
    {
        uint32_t rc = IMG_BUILD_SUCCESS;
        FAPI_INF( "> copyRingsFromHwImage");

        do
        {
            Homerlayout_t* i_pChipHomer = (Homerlayout_t*) o_pImageOut;
            uint32_t tempLength = i_bufSize1;
            uint32_t copyLength = 0;

            if( PLAT_SGPE == i_platId )
            {
                // TOR structure arrange cache rings in terms of SGPE instance. Since there is only one
                // instance of SGPE per P9 chip, entire cache instance specific rings need to be accessed
                // as 1 block. It has not been arranged per instance of cache chiplet. Below
                // is the representation:
                //------------------------------------SGPE RING IN HW IMAGE -------------------------
                //                                  Common Ring TOR                     |           |
                // -------------------------------------------------------------------- | Region A  |
                //                                                                      |           |
                //                                  Rings                               |           |
                //--------------------------------------------------------------------- |---------- |
                //                                  Cache Inst Spec Ring TOR            |           |
                //--------------------------------------------------------------------- |           |
                //                                                                      |           |
                //                                   Cache 0 Rings                      |           |
                //----------------------------------------------------------------------|           |
                //                                                                      |           |
                //                                   Cache 1 Rings                      |           |
                //----------------------------------------------------------------------| Region B  |
                //                                                                      |           |
                //                                   Cache 2 Rings                      |           |
                //----------------------------------------------------------------------|           |
                //                                         .                            |           |
                //                                         .                            |           |
                //                                         .                            |           |
                //----------------------------------------------------------------------|-----------|


                //------------------------------OVERRDIDE RINGS ------------------------|-----------|
                //                            Common Ring TOR                           |           |
                //----------------------------------------------------------------------|Region A   |
                //                             cache common override                    |           |
                //                                                                      |           |
                //----------------------------------------------------------------------|-----------|
                //                             Cache Inst. Spec Override Ring TOR       |           |
                //----------------------------------------------------------------------| Region B  |
                //                             cache 0 override                         |           |
                //----------------------------------------------------------------------|           |
                //                             cache 1 override                         |           |
                //----------------------------------------------------------------------|------------
                //                                  .
                //                                  .
                //---------------------------------------------------------------------
                //
                // Copying common quad rings of all flavors. In first go get base, CC,RL
                //
                // --------------------------------------------------------------------
                sgpeHeader_t* pSgpeImgHdr = ( sgpeHeader_t*) i_pChipHomer->qpmrRegion.sgpeRegion.imgHeader;
                pSgpeImgHdr->g_sgpe_cmn_ring_ovrd_occ_offset = 0;


                if( i_imgType.sgpeCommonRingBuild )
                {
                    rc = copyScanRings( i_pImageIn,
                                        i_pChipHomer->qpmrRegion.sgpeRegion.commonRings,
                                        i_ddLevel,
                                        i_pBuf1,
                                        tempLength,
                                        PLAT_SGPE,
                                        IGNORE_CHIPLET_INSTANCE );

                    if( rc )
                    {
                        FAPI_ERR(" failed to copy the SGPE common ring rc: 0x%08x", rc );
                        break;
                    }

                    FAPI_DBG(" Quad common scan ring copied offset 0x%08x, Length 0x%08x",
                             ((uint8_t*)i_pChipHomer->qpmrRegion.sgpeRegion.commonRings - (uint8_t*)i_pChipHomer),
                             tempLength );

                    copyLength = tempLength;
                    tempLength = i_bufSize1;

                    rc = copyScanOverrideRing( i_pOverride,
                                               &i_pChipHomer->qpmrRegion.sgpeRegion.commonRings[copyLength],
                                               i_ddLevel,
                                               P9_TOR::COMMON,
                                               i_pBuf1,
                                               tempLength,
                                               PLAT_SGPE,
                                               IGNORE_CHIPLET_INSTANCE );

                    if( rc )
                    {
                        FAPI_INF(" No quad common override ring ");
                        tempLength = 0;
                        rc = IMG_BUILD_SUCCESS;
                    }

                    FAPI_DBG(" Quad common scan override ring offset 0x%08x, Length 0x%08x",
                             ((((uint8_t*)&i_pChipHomer->qpmrRegion.sgpeRegion.commonRings[copyLength] ) -
                               (uint8_t*)i_pChipHomer->qpmrRegion.sgpeRegion.commonRings)), tempLength );

                    o_qpmr.quadCommonRingLength = SWIZZLE_4_BYTE( tempLength + copyLength);
                    //putring running on SGPE needs to know the start of .overrides for quad common rings
                    //in SGPE Image.
                    pSgpeImgHdr->g_sgpe_cmn_ring_ovrd_occ_offset = SWIZZLE_4_BYTE(tempLength); // offset from start of .ring section
                }

                if( i_imgType.sgpeCacheSpecificRingBuild )
                {
                    // for region B
                    tempLength = i_bufSize1;
                    rc = copyScanRings( i_pImageIn,
                                        i_pChipHomer->qpmrRegion.sgpeRegion.cacheSpecificRing,
                                        i_ddLevel,
                                        i_pBuf1,
                                        tempLength,
                                        PLAT_SGPE,
                                        CACH0_CHIPLET_ID );

                    if( rc )
                    {
                        FAPI_ERR(" failed to copy the Cache chiplet specific ring rc: 0x%08x", rc );
                        break;
                    }

                    FAPI_DBG(" Quad specific ring copied offset 0x%08x, Length 0x%08x",
                             ((uint8_t*)i_pChipHomer->qpmrRegion.sgpeRegion.cacheSpecificRing - (uint8_t*)i_pChipHomer),
                             tempLength );

                    copyLength = tempLength;
                    tempLength = i_bufSize1;

                    // for region B
                    rc = copyScanOverrideRing( i_pOverride,
                                               &i_pChipHomer->qpmrRegion.sgpeRegion.cacheSpecificRing[copyLength],
                                               i_ddLevel,
                                               P9_TOR::INSTANCE,
                                               i_pBuf1,
                                               tempLength,
                                               PLAT_SGPE,
                                               CACH0_CHIPLET_ID );

                    if( rc )
                    {
                        FAPI_INF(" No quad specific override ring ");
                        tempLength = 0;
                        rc = IMG_BUILD_SUCCESS;
                    }

                    FAPI_DBG(" Quad specific scan override ring offset 0x%08x, Length 0x%08x",
                             ((((uint8_t*)&i_pChipHomer->qpmrRegion.sgpeRegion.cacheSpecificRing[copyLength] ) -
                               (uint8_t*)i_pChipHomer->qpmrRegion.sgpeRegion.cacheSpecificRing)), tempLength );
                    //putring running on SGPE needs to know the start of .overrides for quad specific rings
                    //in SGPE Image.
                    pSgpeImgHdr->g_sgpe_spec_ring_ovrd_occ_offset = SWIZZLE_4_BYTE( tempLength + copyLength );
                    pSgpeImgHdr->g_sgpe_spec_ring_occ_offset =
                        SWIZZLE_4_BYTE(SWIZZLE_4_BYTE(pSgpeImgHdr->g_sgpe_cmn_ring_occ_offset) +
                                       SWIZZLE_4_BYTE(o_qpmr.quadCommonRingLength));
                }
            }
            else if( PLAT_CME == i_platId )
            {
                //------------------------------------CME RING IN HW IMAGE -------------------------
                //                                                                      |           |
                //                                   Core Common Rings                  | Region A  |
                //                                                                      |           |
                //-----------------------------------------------------------------------------------
                //                                                                      |           |
                //                                   CME 0 Rings                        | Region 0  |
                //----------------------------------------------------------------------|---------- |
                //                                                                      |           |
                //                                   CME 1 Rings                        | Region 1  |
                //----------------------------------------------------------------------|---------  |
                //                                                                      |           |
                //                                   CME 2 Rings                        | Region 2  |
                //----------------------------------------------------------------------|---------- |
                //                                         .                            |     .     |
                //                                         .                            |     .     |
                //                                         .                            |     .     |
                //----------------------------------------------------------------------|-----------|


                //------------------------------OVERRDIDE RINGS ------------------------------------------
                //                             cache common override
                //----------------------------------------------------------------------------------
                //                             cache 0 override
                //----------------------------------------------------------------------------------
                //                             cache 1 override
                //----------------------------------------------------------------------------------
                //                                  .
                //                                  .
                //---------------------------------------------------------------------
                //
                // Copying common quad rings of all flavors. In first go get base, CC,RL
                //
                // --------------------------------------------------------------------
                cmeHeader_t* pCmeImgHdr = &i_pChipHomer->cpmrRegion.cmeBin.elements.imgHeader;
                pCmeImgHdr->g_cme_cmn_ring_ovrd_offset       =  0;
                pCmeImgHdr->g_cme_core_spec_ring_ovrd_offset =  0;
                //---------------------------------------------------------------------
                //
                // Copying common core rings of all flavors. In first go base, CC,RL
                // and in second step copy override and overlay rings.
                //
                // --------------------------------------------------------------------

                if( i_imgType.cmeCommonRingBuild )
                {
                    tempLength = i_bufSize1;
                    rc = copyScanRings( i_pImageIn,
                                        i_pChipHomer->cpmrRegion.commonRings,
                                        i_ddLevel,
                                        i_pBuf1,
                                        tempLength,
                                        PLAT_CME,
                                        IGNORE_CHIPLET_INSTANCE);

                    if( rc  )
                    {
                        FAPI_ERR(" failed to copy the CME common ring rc: 0x%08x", rc );
                        break;
                    }

                    FAPI_INF(" Core Cmn Ring copied Offset 0x%08x Length 0x%08x",
                             ( (uint8_t*)i_pChipHomer->cpmrRegion.commonRings - (uint8_t*)i_pChipHomer ),
                             tempLength );

                    copyLength = tempLength;
                    tempLength = i_bufSize1;

                    rc = copyScanOverrideRing( i_pOverride,
                                               &i_pChipHomer->cpmrRegion.commonRings[copyLength],
                                               i_ddLevel,
                                               P9_TOR::COMMON,
                                               i_pBuf1,
                                               tempLength,
                                               PLAT_CME,
                                               IGNORE_CHIPLET_INSTANCE );

                    if( rc )
                    {
                        FAPI_INF(" No common core override ring");
                        tempLength = 0;
                        rc = IMG_BUILD_SUCCESS;
                    }

                    FAPI_DBG(" Core common ring override: length 0x%08x", tempLength );
                    pCmeImgHdr->g_cme_common_ring_length = SWIZZLE_4_BYTE(tempLength + copyLength);
                    pCmeImgHdr->g_cme_cmn_ring_ovrd_offset = SWIZZLE_4_BYTE(tempLength);
                }

                if( i_imgType.cmeCoreSpecificRingBuild )
                {
                    uint32_t cmeId = 0;
                    uint32_t maxRingLength = 0;
                    uint32_t maxOverrideLength = 0;

                    //to facilitate seemless copy of CME's instance specific ring by CME BCE in to CME's SRAM,
                    //find out the max size for Core pair's Instance specific rings (odd and even core
                    //pair put together). Use this max size as standard size of instance specific ring block
                    //for all the core-pairs.
                    //
                    //Same logic is used for scan ring overrides too.
                    for( cmeId = 0; cmeId < MAX_CME_PER_CHIP; cmeId++ )
                    {
                        tempLength = i_bufSize1;

                        rc = copyScanRings( i_pImageIn,
                                            &i_pChipHomer->cpmrRegion.instSpecificRing[0], //don't care here
                                            i_ddLevel,
                                            i_pBuf1,
                                            tempLength,
                                            PLAT_CME,
                                            (CORE0_CHIPLET_ID + (2 * cmeId)),
                                            true ); // querying size of the ring

                        if( rc  )
                        {
                            FAPI_ERR(" failed to query CME instance specific ring rc: 0x%08x core id %d",
                                     rc, cmeId );
                            break;
                        }

                        if( tempLength > maxRingLength )
                        {
                            maxRingLength = tempLength;
                        }

                        tempLength = i_bufSize1;
                        rc = copyScanOverrideRing( i_pOverride,
                                                   &i_pChipHomer->cpmrRegion.instSpecificRing[0], // don't care here
                                                   i_ddLevel,
                                                   P9_TOR::INSTANCE,
                                                   i_pBuf1,
                                                   tempLength,
                                                   PLAT_CME,
                                                   (CORE0_CHIPLET_ID + ( 2 * cmeId)),
                                                   true );  // querying size of the ring

                        if( rc )
                        {
                            FAPI_DBG(" didn't find core specific override ring core id %d", cmeId );
                            rc = IMG_BUILD_SUCCESS;
                            continue;
                        }

                        if( tempLength > maxOverrideLength )
                        {
                            maxOverrideLength = tempLength;
                        }
                    }

                    if( rc )
                    {
                        // failed to access core specific rings
                        break;
                    }

                    copyLength = maxRingLength + maxOverrideLength;

                    if( 0 != ( copyLength % CME_BLOCK_READ_LEN ) )
                    {
                        FAPI_DBG("Core specific ring before rounding 0x%08x", copyLength );
                        // rounding off size of ring to 32B boundary
                        copyLength = (( copyLength + (CME_BLOCK_READ_LEN - 1 ) ) >> CME_BLK_SIZE_SHIFT );
                        copyLength = copyLength << CME_BLK_SIZE_SHIFT;
                        FAPI_DBG("Core specific ring after rounding 0x%08x", copyLength );
                    }

                    for( cmeId = 0; cmeId < MAX_CME_PER_CHIP; cmeId++ )
                    {
                        tempLength = i_bufSize1;

                        // Copying base flavor of instance specific ring for core-pair. Pass chiplet id of even core
                        // e.g. for core0 and core1, pass chiplet id of core0 i.e. CORE0_CHIPLET_ID (0x20).
                        rc = copyScanRings( i_pImageIn,
                                            &i_pChipHomer->cpmrRegion.instSpecificRing[( cmeId * copyLength )],
                                            i_ddLevel,
                                            i_pBuf1,
                                            tempLength,
                                            PLAT_CME,
                                            (CORE0_CHIPLET_ID + ( 2 * cmeId)) );

                        if( rc  )
                        {
                            FAPI_ERR(" failed to copy the CME instance ring rc: 0x%08x core id %d",
                                     rc, cmeId );
                            break;
                        }

                        // Copying override  flavor of instance specific ring for core-pair. Pass chiplet id of
                        // even core e.g. for core0 and core1, pass chiplet id of core0 i.e. CORE0_CHIPLET_ID (0x20).
                        // copy ring override at the end of base rings
                        tempLength = i_bufSize1;
                        rc = copyScanOverrideRing( i_pOverride,
                                                   &i_pChipHomer->cpmrRegion.instSpecificRing[ ((cmeId * copyLength) + maxRingLength) ],
                                                   i_ddLevel,
                                                   P9_TOR::INSTANCE,
                                                   i_pBuf1,
                                                   tempLength,
                                                   PLAT_CME,
                                                   (CORE0_CHIPLET_ID + ( 2 * cmeId)) );

                        if( rc )
                        {
                            FAPI_DBG(" didn't find core specific override ring core id %d", cmeId );
                            rc = IMG_BUILD_SUCCESS;
                            continue;
                        }
                    }

                    FAPI_DBG(" Core specific rings Offset 0x%08x max len per cme (base + ovrd) 0x%08x",
                             ( (uint8_t*)i_pChipHomer->cpmrRegion.instSpecificRing - (uint8_t*)i_pChipHomer ),
                             copyLength );

                    FAPI_DBG(" Core specific rings Override: Length 0x%08x", tempLength );

                    pCmeImgHdr->g_cme_max_spec_ring_length = SWIZZLE_4_BYTE( copyLength >> CME_BLK_SIZE_SHIFT );
                    //field below contains an offset wrt to common ring at which respective override area starts

                    pCmeImgHdr->g_cme_core_spec_ring_ovrd_offset = SWIZZLE_4_BYTE(maxOverrideLength);
                    tempLength = SWIZZLE_4_BYTE(pCmeImgHdr->g_cme_common_ring_offset) + //Unswizzle first to do math
                                 SWIZZLE_4_BYTE(pCmeImgHdr->g_cme_common_ring_length);

                    //Swizzling again
                    tempLength = SWIZZLE_4_BYTE(( tempLength + CME_BLOCK_READ_LEN - 1 ) >> CME_BLK_SIZE_SHIFT );
                    //Instance Specific ring needs to be copied at an offset which is a multiple of 32B. This offset
                    //will become an SBASE value of CME's BCE. Doing this math here to keep CME hcode simple.
                    pCmeImgHdr->g_cme_core_spec_ring_offset = tempLength;
                }
            }
        }
        while(0);

        FAPI_INF( "< copyRingsFromHwImage");

        return rc;
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
                                            const uint32_t    i_sizeBuf2 )
    {
        FAPI_IMP("Entering p9_hcode_image_build ");
        fapi2::ReturnCode retCode;

        do
        {
            FAPI_DBG("validating argument ..");
            retCode = validateInputArguments( i_pImageIn, i_pHomerImage, i_phase,
                                              i_imgType, i_pBuf1, i_sizeBuf1, i_pBuf2,
                                              i_sizeBuf2 );

            if( retCode )
            {
                FAPI_ERR("Invalid arguments, escaping hcode image build");
                break;
            }

            Homerlayout_t* pChipHomer = ( Homerlayout_t*) i_pHomerImage;
            uint32_t ppeImgRc = IMG_BUILD_SUCCESS;

            // HW Image is a nested XIP Image. Let us read global TOC of hardware image
            // and find out if XIP header of PPE image is contained therein.
            // Let us start with SGPE
            FAPI_INF("SGPE building");
            QpmrHeaderLayout_t qpmrHdr;
            ppeImgRc = buildSgpeImage( i_pImageIn, pChipHomer, i_imgType, qpmrHdr );
            ppeImgRc = IMG_BUILD_SUCCESS;

            FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                         fapi2::SGPE_BUILD_FAIL()
                         .set_SGPE_FAIL_SECTN( ppeImgRc ),
                         "Failed to copy SGPE section in HOMER" );
            FAPI_INF("SGPE built");

            // copy sections pertaining to self restore
            // Note: this creates the CPMR header portion

            //let us determine if system is configured in fuse mode. This needs to
            //be updated in a CPMR region.
            const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
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
            ppeImgRc = buildCmeImage( i_pImageIn, pChipHomer, i_imgType );
            ppeImgRc = IMG_BUILD_SUCCESS;

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

            //Update CPMR Header area n HOMER with CME Image related information.
            updateCpmrHeaderCME( pChipHomer );

            uint8_t ecLevel = 0;
            FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC,
                                              i_procTgt,
                                              ecLevel),
                     "Error from for attribute ATTR_EC");
#if 0
            ppeImgRc = copyRingsFromHwImage( i_pImageIn,
                                             i_pRingOverride,
                                             i_pHomerImage,
                                             ecLevel,
                                             i_pBuf1,
                                             i_sizeBuf1,
                                             i_pBuf2,
                                             i_sizeBuf2,
                                             i_imgType,
                                             qpmrHdr,
                                             PLAT_SGPE );

            FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                         fapi2::SCAN_RING_BUILD_FAIL()
                         .set_RING_FAIL_RC( ppeImgRc ),
                         "Failed to copy SGPE's scan ring in HOMER" );

            FAPI_DBG("SGPE scan rings added ");
            ppeImgRc = copyRingsFromHwImage( i_pImageIn,
                                             i_pRingOverride,
                                             i_pHomerImage,
                                             ecLevel,
                                             i_pBuf1,
                                             i_sizeBuf1,
                                             i_pBuf2,
                                             i_sizeBuf2,
                                             i_imgType,
                                             qpmrHdr,
                                             PLAT_CME );

            FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                         fapi2::SCAN_RING_BUILD_FAIL()
                         .set_RING_FAIL_RC( ppeImgRc ),
                         "Failed to copy CME's scan ring in HOMER" );

            FAPI_DBG("CME scan rings added ");
#endif
            //Update CPMR Header with Scan Ring details
            updateCpmrScanRing( pChipHomer );

            //Update QPMR Header area in HOMER
            updateQpmrHeader( pChipHomer, qpmrHdr );

            //Finally update the attributes storing PGPE and SGPE's boot copier offset.
            QpmrHeaderLayout_t* pQpmrHdr = (QpmrHeaderLayout_t*)pChipHomer->qpmrRegion.sgpeRegion.qpmrHeader;

            uint32_t attrVal = SWIZZLE_4_BYTE(pQpmrHdr->bootCopierOffset);
            attrVal |= (0x80000000 | ONE_MB);

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_STOPGPE_BOOT_COPIER_IVPR_OFFSET,
                                   i_procTgt,
                                   attrVal ),
                     "Error from FAPI_ATTR_SET for attribute ATTR_STOPGPE_BOOT_COPIER_IVPR_OFFSET");

            FAPI_DBG("Set ATTR_STOPGPE_BOOT_COPIER_IVPR_OFFSET to 0x%08x", attrVal );

            attrVal = (uint8_t*)(pChipHomer->ppmrRegion.l1BootLoader) - (uint8_t*)(pChipHomer);
            attrVal |= 0x80000000;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PSTATEGPE_BOOT_COPIER_IVPR_OFFSET,
                                   i_procTgt,
                                   attrVal ),
                     "Error from FAPI_ATTR_SET for attribute ATTR_PSTATEGPE_BOOT_COPIER_IVPR_OFFSET");

            FAPI_DBG("Set ATTR_PSTATEGPE_BOOT_COPIER_IVPR_OFFSET to 0x%08x", attrVal );
        }
        while(0);

        FAPI_IMP("Exit p9_hcode_image_build" );

    fapi_try_exit:
        return retCode;
    }

    } //namespace p9_hcodeImageBuild ends

}// extern "C"
