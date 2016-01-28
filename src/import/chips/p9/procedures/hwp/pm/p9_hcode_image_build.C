/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_hcode_image_build.C $           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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


using namespace fapi2;
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
    fapi2::ReturnCode validateInputArguments( void* const i_pImageIn,
            void* i_pImageOut,
            SysPhase_t i_phase,
            ImageType_t i_imgType, void* i_pBuf )
    {
        uint32_t l_rc = IMG_BUILD_SUCCESS;
        uint32_t hwImagSize = 0;

        FAPI_DBG("Entering validateInputArguments ...");

        FAPI_ASSERT( (( i_pImageIn != NULL ) && ( i_pImageOut != NULL ) &&
                      ( i_pImageIn != i_pImageOut )),
                     fapi2::P9_IMG_PTR_ERROR()
                     .set_HW_IMG_BUF_PTR( i_pImageIn )
                     .set_HOMER_IMG_BUF_PTR( i_pImageOut ),
                     "Bad pointer to HW Image or HOMER Image" );

        l_rc = p9_xip_image_size( i_pImageIn, &hwImagSize );

        FAPI_DBG("size is 0x%08x", hwImagSize);

        FAPI_ASSERT( (( IMG_BUILD_SUCCESS == l_rc ) && ( hwImagSize > 0 ) &&
                      ( HARDWARE_IMG_SIZE >= hwImagSize )),
                     fapi2::P9_HW_IMAGE_INVALID_SIZE()
                     .set_HW_IMG_SIZE( hwImagSize )
                     .set_MAX_HW_IMG_SIZE( HARDWARE_IMG_SIZE ),
                     "Hardware image size found out of range" );

        FAPI_ASSERT( (( i_phase  > PHASE_NA ) && ( i_phase < PHASE_END )),
                     fapi2::P9_HCODE_INVALID_PHASE()
                     .set_SYS_PHASE( i_phase ),
                     "Invalid value passed as build phase" );

        FAPI_ASSERT( ( i_pBuf != NULL ),
                     fapi2::P9_HCODE_INVALID_TEMP_BUF()
                     .set_TEMP_BUF_PTR( i_pBuf ),
                     "Invalid temp buffer passed for hcode image build" );

        FAPI_ASSERT( ( i_imgType.isBuildValid() ),
                     fapi2::P9_HCODE_INVALID_IMG_TYPE(),
                     "Invalid temp buffer passed for hcode image build" );
        FAPI_DBG("Exiting validateInputArguments ...");

    fapi_try_exit:
        return fapi2::current_err;
    }

//------------------------------------------------------------------------------
    uint32_t copySectionToHomer( uint8_t* i_destPtr, uint8_t* i_srcPtr, uint8_t i_secId, E_PLAT_ID i_platId ,
                                 P9XipSection&   o_ppeSection )
    {
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

            memcpy( i_destPtr, i_srcPtr + o_ppeSection.iv_offset, o_ppeSection.iv_size );
        }
        while(0);

        return retCode;
    }
//------------------------------------------------------------------------------
    uint32_t updateCpmrHeader( Homerlayout_t* i_pChipHomer, uint8_t i_fuseState )
    {
        uint32_t rc = IMG_BUILD_SUCCESS;

        do
        {
            HomerImgDesc_t* pCpmrHdr = (HomerImgDesc_t*) & (i_pChipHomer->selfRestoreRegion);

            CmeImageHeader_t* pCmeHdr =  NULL;
            pCmeHdr = (CmeImageHeader_t*) i_pChipHomer->cmeRegion.imgHeader;
            pCpmrHdr->homerMagicNumber = SWIZZLE_8_BYTE(CPMR_MAGIC_WORD);
            //populate CPMR header
            pCpmrHdr->fuseModeStatus = i_fuseState ? FUSE_STATE : UNFUSE_STATE;
            //offset is multiple of 32B for quick setting of MBASE of CME's BCE
            pCpmrHdr->cmeImgOffset = (CME_REGION_START >> CME_BLK_SIZE_SHIFT);

            // populate the CME binary's size
            pCpmrHdr->cmeImgLength = pCmeHdr->hcodeLength + CME_INT_VECTOR + CME_IMG_HEADER;
            //FIXME to be handled while adding scan ring part.
            pCpmrHdr->cmeCommonRingOffset    =  0;
            pCpmrHdr->cmeCommonRingLength    =  0;
            pCpmrHdr->cmePstateOffset        =  0;
            pCpmrHdr->cmePstateLength        =  0;
            pCpmrHdr->coreSpecRingOffset     =  0;
            pCpmrHdr->coreSpecRingLen        =  0;
            pCpmrHdr->coreScomOffset         =  (CORE_SCOM_START >> CME_BLK_SIZE_SHIFT);
            pCpmrHdr->coreScomLength         =  (CORE_SCOM_RES_SIZE >> CME_BLK_SIZE_SHIFT);
        }
        while(0);

        return rc;
    }

//------------------------------------------------------------------------------
    uint32_t updateQpmrHeader( Homerlayout_t* i_pChipHomer, QpmrHeaderLayout_t& io_qpmrHdr )
    {
        uint32_t rc = IMG_BUILD_SUCCESS;

        QpmrHeaderLayout_t* pQpmrHdr = ( QpmrHeaderLayout_t*)i_pChipHomer->sgpeRegion.qpmrHeader;
        memcpy( pQpmrHdr, &io_qpmrHdr, sizeof( QpmrHeaderLayout_t ) );
        return rc;
    }

//------------------------------------------------------------------------------
    /**
     * @brief       copies image section associated with  SGPE from HW Image to HOMER
     * @param[in]   i_pImageIn      points to start of hardware image.
     * @param[in]   i_pChipHomer    points to HOMER image in main memory.
     * @param[in]   i_imgType       image sections  to be built
     */
    uint32_t buildSgpeImage( void* const i_pImageIn, Homerlayout_t* i_pChipHomer,
                             ImageType_t i_imgType )
    {
        uint32_t retCode = IMG_BUILD_SUCCESS;

        do
        {
            uint32_t rcTemp = 0;
            //Let us find XIP Header for SGPE
            P9XipSection ppeSection;
            uint8_t* pSgpeImg = NULL;
            QpmrHeaderLayout_t qpmrHdr;

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

            rcTemp = copySectionToHomer( i_pChipHomer->sgpeRegion.qpmrHeader, pSgpeImg,
                                         P9_XIP_SECTION_SGPE_QPMR, PLAT_SGPE, ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy QPMR Header");
                rcTemp = BUILD_FAIL_SGPE_QPMR;
                break;
            }

            //updating local instance of QPMR header
            memcpy( &qpmrHdr, i_pChipHomer->sgpeRegion.qpmrHeader, sizeof(QpmrHeaderLayout_t));

            rcTemp = copySectionToHomer( i_pChipHomer->sgpeRegion.l1BootLoader, pSgpeImg,
                                         P9_XIP_SECTION_SGPE_LVL1_BL, PLAT_SGPE, ppeSection );
            qpmrHdr.bootCopierOffset = QPMR_HEADER_SIZE;

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy Level1 bootloader");
                rcTemp = BUILD_FAIL_SGPE_BL1;
                break;
            }

            rcTemp = copySectionToHomer( i_pChipHomer->sgpeRegion.l2BootLoader, pSgpeImg,
                                         P9_XIP_SECTION_SGPE_LVL2_BL, PLAT_SGPE, ppeSection );
            qpmrHdr.bootLoaderOffset = qpmrHdr.bootCopierOffset + SGPE_LVL_1_BOOT_LOAD_SIZE;
            qpmrHdr.bootLoaderLength = ppeSection.iv_size;

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy Level2 bootloader");
                rcTemp = BUILD_FAIL_SGPE_BL2;
                break;
            }

            rcTemp = copySectionToHomer( i_pChipHomer->sgpeRegion.hcodeIntVect, pSgpeImg,
                                         P9_XIP_SECTION_SGPE_INT_VECT, PLAT_SGPE, ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy SGPE Int. vectors ");
                rcTemp = BUILD_FAIL_CME_INT_VECT;
                break;
            }

            rcTemp = copySectionToHomer( i_pChipHomer->sgpeRegion.imgHeader, pSgpeImg,
                                         P9_XIP_SECTION_SGPE_IMG_HDR, PLAT_SGPE, ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy SGPE header");
                rcTemp = BUILD_FAIL_SGPE_HDR;
                break;
            }

            rcTemp = copySectionToHomer( i_pChipHomer->sgpeRegion.hcode, pSgpeImg,
                                         P9_XIP_SECTION_SGPE_HCODE, PLAT_SGPE, ppeSection );

            // FIXME Need to handle Scan Ring part here

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy SGPE hcode");
                rcTemp = BUILD_FAIL_SGPE_HCODE;
                break;
            }

            qpmrHdr.sgpeImgOffset = i_pChipHomer->sgpeRegion.hcodeIntVect -
                                    (uint8_t*)&i_pChipHomer->sgpeRegion;
            qpmrHdr.sgpeImgLength = ppeSection.iv_size + PPE_RESERVE_AREA;
            qpmrHdr.quadSpecScomOffset = CACHE_SCOM_START;

            //updating SGPE Image header in HOMER
            // FIXME Need to handle fields related SCOM OCC offsets

            uint32_t regionLimit = CACHE_SCOM_RESTORE_SIZE >> 2;

            for( uint32_t wordCnt = 0; wordCnt < regionLimit; wordCnt++ )
            {
                uint32_t l_fillPattern = PAD_OPCODE;
                memcpy( i_pChipHomer->cacheScomRegion, &l_fillPattern, sizeof(uint32_t) );
            }

            updateQpmrHeader( i_pChipHomer, qpmrHdr );
        }
        while(0);

        return retCode;
    }

//------------------------------------------------------------------------------

    /**
     * @brief       copies core self restore section from hardware image to HOMER.
     * @param[in]   i_pImageIn      points to start of hardware image.
     * @param[in]   i_pChipHomer    points to HOMER image in main memory.
     * @param[in]   i_imgType       image sections  to be built
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
                rcTemp = copySectionToHomer( i_pChipHomer->selfRestoreRegion.selfRestoreArea, pSelfRestImg,
                                             P9_XIP_SECTION_RESTORE_SELF, PLAT_SELF, ppeSection );

                if( rcTemp )
                {
                    FAPI_ERR("Failed to copy SRESET Handler");
                    retCode = BUILD_FAIL_P9_SRESET_HNDLR;
                    break;
                }

            }

            // adding CPMR header in first 256 bytes of HOMER + 2 MB.
            rcTemp = copySectionToHomer( i_pChipHomer->selfRestoreRegion.selfRestoreArea, pSelfRestImg,
                                         P9_XIP_SECTION_RESTORE_CPMR, PLAT_SELF, ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy CPMR header");
                retCode = BUILD_FAIL_P9_CPMR_HDR;
                break;
            }

            //Pad undefined or runtime section with  ATTN Opcode
            //Padding SPR restore area with ATTN Opcode

            uint32_t wordCnt = 0;

            while( wordCnt < CORE_RESTORE_SIZE )
            {
                uint32_t l_fillPattern = SWIZZLE_4_BYTE(PAD_OPCODE);
                memcpy( (uint32_t*)&i_pChipHomer->selfRestoreRegion.coreSelfRestore[wordCnt], &l_fillPattern, sizeof( uint32_t ));
                wordCnt += 4;
            }

            updateCpmrHeader( i_pChipHomer, i_fuseState );
        }
        while(0);

        return retCode;
    }

//------------------------------------------------------------------------------

    /**
     * @brief       copies cme section from hardware image to HOMER.
     * @param[in]   i_pImageIn      points to start of hardware image.
     * @param[in]   i_pChipHomer    points to HOMER image in main memory.
     * @param[in]   i_imgType       image sections  to be built
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
            rcTemp = copySectionToHomer( i_pChipHomer->cmeRegion.cmeIntVector, pCmeImg,
                                         P9_XIP_SECTION_CME_INT_VECT, PLAT_CME, ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to copy SGPE Int. vectors ");
                rcTemp = BUILD_FAIL_CME_INT_VECT;
                break;
            }

            rcTemp = copySectionToHomer( i_pChipHomer->cmeRegion.imgHeader, pCmeImg,
                                         P9_XIP_SECTION_CME_IMG_HDR, PLAT_CME, ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to append CME Image Header");
                retCode = BUILD_FAIL_CME_IMG_HDR;
                break;
            }

            rcTemp = copySectionToHomer( i_pChipHomer->cmeRegion.imgHeader, pCmeImg,
                                         P9_XIP_SECTION_CME_IMG_HDR, PLAT_CME, ppeSection );

            if( rcTemp )
            {
                FAPI_ERR("Failed to append CME Image Header");
                retCode = BUILD_FAIL_CME_IMG_HDR;
                break;
            }

            if( i_imgType.cmeHcodeBuild )
            {
                rcTemp = copySectionToHomer( i_pChipHomer->cmeRegion.hcode, pCmeImg,
                                             P9_XIP_SECTION_CME_HCODE, PLAT_CME, ppeSection );

                if( rcTemp )
                {
                    FAPI_ERR("Failed to append CME Hcode");
                    retCode = BUILD_FAIL_CME_HCODE;
                    break;
                }

                // Initializing CME Image header
                CmeImageHeader_t* pImgHdr = ( CmeImageHeader_t*)i_pChipHomer->cmeRegion.imgHeader;
                pImgHdr->hcodeOffset =  CME_HCODE_REL_OFFSET;
                pImgHdr->hcodeLength =  ppeSection.iv_size;
                pImgHdr->commonRingOffset = 0;
                pImgHdr->commonRingLength = 0;
                pImgHdr->pStateOffset = 0;
                pImgHdr->pStateLength = 0;
                pImgHdr->coreSpecificRingOffset = 0;    // multiple of 32B blocks
                pImgHdr->coreSpecificRingLength = 0;    // multiple of 32B blocks
            }
        }
        while(0);

        return retCode;
    }
//------------------------------------------------------------------------------

    fapi2::ReturnCode p9_hcode_image_build( CONST_FAPI2_PROC& i_procTgt,
                                            void* const i_pImageIn,
                                            void* o_pImageOut,
                                            SysPhase_t i_phase,
                                            ImageType_t i_imgType,
                                            void* i_pBuf )
    {
        FAPI_IMP("Entering p9_hcode_image_build ");
        fapi2::ReturnCode retCode;

        do
        {
            FAPI_DBG("validating argument ..");
            retCode = validateInputArguments( i_pImageIn, o_pImageOut, i_phase,
                                              i_imgType, i_pBuf );

            if( retCode )
            {
                FAPI_ERR("Invalid arguments, escaping hcode image build");
                break;
            }

            Homerlayout_t* pChipHomer = ( Homerlayout_t*) o_pImageOut;
            uint32_t ppeImgRc = IMG_BUILD_SUCCESS;

            // HW Image is a nested XIP Image. Let us read global TOC of hardware image
            // and find out if XIP header of PPE image is contained therein.
            // Let us start with SGPE
            ppeImgRc = buildSgpeImage( i_pImageIn, pChipHomer, i_imgType );

            FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                         fapi2::P9_SGPE_BUILD_FAIL()
                         .set_SGPE_FAIL_SECTN( ppeImgRc ),
                         "Failed to copy SGPE section in HOMER" );
            FAPI_DBG("SGPE built");

            // copy sections pertaining to CME
            ppeImgRc = buildCmeImage( i_pImageIn, pChipHomer, i_imgType );

            FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                         fapi2::P9_CME_BUILD_FAIL()
                         .set_CME_FAIL_SECTN( ppeImgRc ),
                         "Failed to copy CME section in HOMER" );
            FAPI_DBG("cme built");
            //let us determine if system is configured in fuse mode. This needs to
            //be updated in a CPMR region.
            const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
            uint8_t fuseModeState = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUSED_CORE_MODE,
                                   FAPI_SYSTEM,
                                   fuseModeState),
                     "Error from FAPI_ATTR_GET for attribute ATTR_FUSED_CORE_MODE");
            // copy sections pertaining to self restore
            ppeImgRc = buildCoreRestoreImage( i_pImageIn, pChipHomer, i_imgType, fuseModeState );

            FAPI_ASSERT( ( IMG_BUILD_SUCCESS == ppeImgRc ),
                         fapi2::P9_SELF_RESTORE_BUILD_FAIL()
                         .set_SELF_RESTORE_FAIL_SECTN( ppeImgRc ),
                         "Failed to copy core self restore section in HOMER" );
            FAPI_DBG("self restore built ");

        }
        while(0);

        FAPI_IMP("Exit p9_hcode_image_build" );

    fapi_try_exit:
        return retCode;
    }

    } //namespace p9_hcodeImageBuild ends

}// extern "C"
