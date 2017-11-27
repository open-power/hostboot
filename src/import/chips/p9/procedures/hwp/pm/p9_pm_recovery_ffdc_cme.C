/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_cme.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
// *INDENT-OFF*


///
/// @file   p9_pm_recovery_ffdc_cme.C
/// @brief  Models CME platform for the FFDC collection of PM complex
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    Hostboot
//
// *INDENT-OFF*
//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------

#include <p9_pm_recovery_ffdc_cme.H>
#include <p9_hcd_memmap_cme_sram.H>
#include <p9_quad_scom_addresses.H>
#include <collect_reg_ffdc.H>
#include <p9_ppe_defs.H>
#include <p9_ppe_utils.H>
#include <stddef.h>
#include <endian.h>

 namespace p9_stop_recov_ffdc
 {

    PlatCme::PlatCme( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt )
      : PlatPmComplex( i_procChipTgt,
                       PLAT_CME,
                       FFDC_PPE_IMG_HDR_START,
                       FFDC_CME_TRACE_START,
                       FFDC_CME_DASH_BOARD_START )
    { }

    //----------------------------------------------------------------------

    fapi2::ReturnCode PlatCme::init ( void* i_pHomerBuf )
    {
        FAPI_DBG (">> PlatCme::init" );
        FAPI_TRY ( collectFfdc( i_pHomerBuf, INIT),
                   "Failed To init CME FFDC" );

    fapi_try_exit:
        FAPI_DBG ("<< PlatCme::init" );
        return fapi2::current_err;
    }

    //----------------------------------------------------------------------

    fapi2::ReturnCode PlatCme::collectFfdc( void*   i_pHomerBuf,
                                            uint8_t i_ffdcType )
    {
        FAPI_DBG ( ">> PlatCme::collectFfdc: i_ffdcType: 0x%02X", i_ffdcType );
        fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;
        auto l_exList =
            getProcChip().getChildren< fapi2::TARGET_TYPE_EX > ( fapi2::TARGET_STATE_PRESENT );
        uint8_t l_quadPos = 0;
        uint8_t l_exPos   = 0;
        uint8_t l_cmePos  = 0;
        uint8_t *l_pFfdcLoc = NULL;
        uint8_t* l_pFirFfdcLoc = NULL;
        HomerFfdcRegion * l_pHomerFfdc =
                ( HomerFfdcRegion *)( (uint8_t *)i_pHomerBuf + FFDC_REGION_HOMER_BASE_OFFSET );


        for( auto ex : l_exList )
        {
            FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, ex, l_cmePos ),
                      "FAPI_ATTR_GET Failed To Read EX Position" );

            l_exPos     =   l_cmePos % 2;
            l_quadPos   =   l_cmePos >> 1;
            l_pFfdcLoc = &l_pHomerFfdc->iv_quadFfdc[l_quadPos].iv_quadCmeBlock[l_exPos][0];
            l_pFirFfdcLoc = &l_pHomerFfdc->iv_firFfdcRegion.iv_firCmeBlock[l_cmePos][0];

            PpeFfdcHeader* l_pCmeFfdcHdr = (PpeFfdcHeader*) l_pFfdcLoc;
            uint16_t l_ffdcValdityVect = l_pCmeFfdcHdr->iv_sectionsValid;

            if ( !ex.isFunctional() || (i_ffdcType & INIT))
            {
                //Marking CME FFDC region as Invalid
                l_ffdcValdityVect = PPE_FFDC_INVALID;
                FAPI_TRY( updateCmeFfdcHeader( l_pFfdcLoc, l_cmePos, l_ffdcValdityVect ),
                          "Failed To Update CME FFDC Header for CME 0x%0d", l_cmePos );

                // Mark CME FIR FFDC invalid
                FAPI_TRY ( updateFirFfdcHeader (
                           &l_pHomerFfdc->iv_firFfdcRegion.iv_firFfdcHeader[0],
                           l_cmePos,
                           false ) );
                continue;
            }

            FAPI_INF("CME FFDC Quad Pos %d Ex Pos %d ", l_quadPos, l_exPos );

            //In case of error , invalidate FFDC in header.
            // INIT case handled above where only header update is needed

            if ( i_ffdcType & FIR_STATE )
            {
                bool l_firValid = true;

                l_retCode = collectRegisterData <fapi2::TARGET_TYPE_EX> (
                            ex, l_pFirFfdcLoc, fapi2::PM_CME_FIR_REGISTERS );
                if (l_retCode)
                {
                    FAPI_ERR ("CME %d FIR Data collection fail", l_cmePos);
                    l_firValid = false;
                }
                // Update CME FIR FFDC
                FAPI_TRY ( updateFirFfdcHeader (
                           &l_pHomerFfdc->iv_firFfdcRegion.iv_firFfdcHeader[0],
                           l_cmePos,
                           l_firValid ) );

                // Since the top level header FIR Section validity is an aggregate
                // of OCC FIR and multiple CME FIRs, it is updated only in OCC plat
            }

            if ( i_ffdcType & PPE_HALT_STATE )
            {
                l_ffdcValdityVect |= PPE_HALT_STATE_VALID;
                l_retCode = readPpeHaltState ( getCmeBaseAddress (l_cmePos),
                                               l_pFfdcLoc );
                if ( l_retCode != fapi2::FAPI2_RC_SUCCESS )
                {
                    FAPI_ERR ( "Error reading CME Halt State, CME Pos 0x08x",
                               l_cmePos );
                    l_ffdcValdityVect &= ~PPE_HALT_STATE_VALID;
                }
            }

            if ( i_ffdcType & PPE_STATE )
            {
                l_ffdcValdityVect |= PPE_STATE_VALID;
                l_retCode = collectPpeState ( getCmeBaseAddress (l_cmePos),
                                              l_pFfdcLoc );
                if ( l_retCode != fapi2::FAPI2_RC_SUCCESS )
                {
                    FAPI_ERR ( "Error collecting CME State, CME Pos 0x08x",
                               l_cmePos );
                    l_ffdcValdityVect &= ~PPE_STATE_VALID;
                }
            }

            if ( i_ffdcType & TRACES )
            {
                l_ffdcValdityVect |= PPE_TRACE_VALID;
                l_retCode = collectTrace( l_pFfdcLoc, ex );

                if( l_retCode )
                {
                    FAPI_ERR("Error in collecting CME Trace CME Pos 0x%08x", l_cmePos );
                    l_ffdcValdityVect &= ~PPE_TRACE_VALID;
                }
            }

            if ( i_ffdcType & DASH_BOARD_VAR )
            {
                l_ffdcValdityVect |= PPE_DASHBOARD_VALID;
                l_retCode = collectGlobals( l_pFfdcLoc, ex );

                if( l_retCode )
                {
                    FAPI_ERR("Error in collecting CME Globals, CME Pos 0x%08x", l_cmePos );
                    l_ffdcValdityVect &= ~PPE_DASHBOARD_VALID;
                }
            }

            if ( i_ffdcType & IMAGE_HEADER )
            {
                l_ffdcValdityVect |= PPE_IMAGE_HEADER_VALID;
                l_retCode = collectImageHeader( l_pFfdcLoc, ex );

                if( l_retCode )
                {
                    FAPI_ERR("Error in collecting CME Image header, CME Pos 0x%08x", l_cmePos );
                    l_ffdcValdityVect &= ~PPE_IMAGE_HEADER_VALID;
                }
            }

            if ( i_ffdcType & INTERNAL_REG )
            {
                l_ffdcValdityVect |= PPE_INT_REG_VALID;
                l_retCode = collectInternalReg( l_pFfdcLoc, ex , l_cmePos);

                if( l_retCode )
                {
                    FAPI_ERR("Error in collecting CME Internal Regs, CME Pos 0x%08x", l_cmePos );
                    l_ffdcValdityVect &= ~PPE_INT_REG_VALID;
                }
            }

            FAPI_TRY( updateCmeFfdcHeader( l_pFfdcLoc, l_cmePos, l_ffdcValdityVect ),
                      "Failed To Update CME FFDC Header for CME 0x%0d", l_cmePos );

        }

        if( !(i_ffdcType & INIT ) )
        {
            generateSummary( i_pHomerBuf );
        }

    fapi_try_exit:
        FAPI_DBG("<< PlatCme::collectFfdc");
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatCme::collectPartialFfdc( void * i_pBuf, FfdcDataType i_dataType,
                                                    fapi2::Target<fapi2::TARGET_TYPE_EX >& i_exTgt,
                                                    uint32_t & o_ffdcLength )
    {
        FAPI_DBG(">> PlatSgpe::collectPartialFfdc");
        fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;
        uint32_t l_maxSize = o_ffdcLength;
        FAPI_DBG("Max buf size %d", o_ffdcLength );

        switch( i_dataType )
        {
            case IMAGE_HEADER:
                o_ffdcLength = FFDC_PPE_IMG_HDR_SIZE;
                break;
            case DASH_BOARD_VAR:
                o_ffdcLength = FFDC_PPE_SCORE_BOARD_SIZE;
                break;
            case TRACES:
                o_ffdcLength = FFDC_PPE_TRACES_SIZE;
                break;
            default:
                FAPI_ERR("Bad FFDC Data type. Skipping 0x%d", (uint32_t)i_dataType );
                goto fapi_try_exit;
                break;
        }

        if( !i_pBuf )
        {
            FAPI_ERR("Bad FFDC Buffer" );
            goto fapi_try_exit;
        }

        if( o_ffdcLength > l_maxSize )
        {
            o_ffdcLength = l_maxSize;
        }

        FAPI_TRY( PlatPmComplex::collectSramInfo( i_exTgt,
                                                  (uint8_t*)i_pBuf,
                                                  i_dataType,
                                                  o_ffdcLength ),
                  "Failed To Collect CME SRAM FFDC" );

        fapi_try_exit:
        FAPI_DBG("<< PlatSgpe::collectPartialFfdc");
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatCme::collectTrace( uint8_t * i_pTraceBuf,
                                             const fapi2::Target<fapi2::TARGET_TYPE_EX >& i_exTgt  )
    {
        FAPI_DBG(">> PlatCme::collectTrace" );
        PpeFfdcLayout * l_pCmeFfdc  =   ( PpeFfdcLayout *) ( i_pTraceBuf );
        uint8_t * l_pTraceLoc       =   &l_pCmeFfdc->iv_ppeTraces[0];
        uint64_t l_traceBufHdr      =   0;
        uint32_t l_traceBufAddress  =   0;
        uint32_t l_doubleWordsRead  =   0;

        FAPI_TRY( PlatPmComplex::readSramInfo(  i_exTgt,
                                                getTraceBufAddr(),
                                                (uint8_t *)&l_traceBufHdr,
                                                8,
                                                l_doubleWordsRead ),
                  "Trace Buf Ptr Collection Failed" );

        l_traceBufHdr       =   htobe64(l_traceBufHdr);
        l_traceBufAddress   =   (uint32_t) l_traceBufHdr;

        FAPI_DBG( "Trace Buf Address 0x%08x Double Word 0x%016lx", l_traceBufAddress, l_traceBufHdr );

        FAPI_TRY( PlatPmComplex::readSramInfo(  i_exTgt,
                                                l_traceBufAddress,
                                                l_pTraceLoc,
                                                FFDC_PPE_TRACES_SIZE,
                                                l_doubleWordsRead ),
                  "Trace Bin Collection Failed" );

    fapi_try_exit:
        FAPI_DBG("<< PlatCme::collectTrace" );
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode  PlatCme::collectGlobals( uint8_t * i_pCmeGlobals,
                                                const fapi2::Target<fapi2::TARGET_TYPE_EX >& i_exTgt )
    {
        FAPI_DBG(">> PlatCme::collectGlobals" );
        PpeFfdcLayout * l_pCmeFfdc = ( PpeFfdcLayout *) ( i_pCmeGlobals );
        uint8_t * l_pTraceLoc = &l_pCmeFfdc->iv_ppeGlobals[0];

        FAPI_TRY( PlatPmComplex::collectSramInfo
                    ( i_exTgt,
                      l_pTraceLoc,
                      DASH_BOARD_VAR,
                      FFDC_PPE_SCORE_BOARD_SIZE ),
                  "Failed To Collect CME Global Variables" );

    fapi_try_exit:
        FAPI_DBG("<< PlatCme::collectGlobals" );
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatCme::collectInternalReg( uint8_t * i_pCmeIntReg,
                                                   const fapi2::Target<fapi2::TARGET_TYPE_EX >& i_exTgt ,
                                                   const uint8_t i_exPos)
    {
        FAPI_DBG(">> PlatCme::collectInternalReg" );

        PpeFfdcLayout * l_pCmeFfdc = ( PpeFfdcLayout *) ( i_pCmeIntReg);
        uint8_t * l_pIntRegs = &l_pCmeFfdc->iv_ppeInternalReg[0];

        FAPI_INF("CME Internal FFDC Pos %d ", i_exPos);

        FAPI_TRY(collectRegisterData<fapi2::TARGET_TYPE_EX> (i_exTgt,
                                     l_pIntRegs,
                                     static_cast<fapi2::HwpFfdcId>(fapi2::CME_INTERNAL_FFDC_REGISTERS)),
                      "Failed to collect register data for CME instance %u",i_exPos);


    fapi_try_exit:
        FAPI_DBG("<< PlatCme::collectInternalReg" );
        return fapi2::FAPI2_RC_SUCCESS;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatCme::collectImageHeader( uint8_t * i_pCmeImgHdr,
                                                   const fapi2::Target<fapi2::TARGET_TYPE_EX >& i_exTgt )
    {
        FAPI_DBG(">> PlatCme::collectImageHeader" );
        PpeFfdcLayout *l_pCmeFfdc = ( PpeFfdcLayout *) ( i_pCmeImgHdr );

        uint8_t * l_pTraceLoc = &l_pCmeFfdc->iv_ppeImageHeader[0];
        FAPI_TRY( PlatPmComplex::collectSramInfo
                  ( i_exTgt,
                    l_pTraceLoc,
                    IMAGE_HEADER,
                    FFDC_PPE_IMG_HDR_SIZE ),
                  "Failed To Collect CME Image Header" );

    fapi_try_exit:
        FAPI_DBG("<< PlatCme::collectImageHeader" );
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatCme::updateCmeFfdcHeader( uint8_t* i_pHomerBuf, uint8_t i_cmePos,
                                                    uint16_t i_sectionsValid )
    {
        FAPI_DBG(">> updateCmeFfdcHeader" );

        PpeFfdcHeader * l_pCmeFfdcHdr =  ( (PpeFfdcHeader *)(( PpeFfdcHdrRegion * ) i_pHomerBuf ));
        l_pCmeFfdcHdr->iv_ppeMagicNumber    =  htobe32(FFDC_CME_MAGIC_NUM);
        l_pCmeFfdcHdr->iv_ppeNumber         =  i_cmePos;
        PlatPmComplex::updatePpeFfdcHeader( l_pCmeFfdcHdr, i_sectionsValid );

        FAPI_DBG("<< updateCmeFfdcHeader" );
        return fapi2::FAPI2_RC_SUCCESS;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatCme::generateSummary( void * i_pHomerBuf )
    {
        FAPI_DBG(">> PlatCme::generateSummary" );

        HomerFfdcRegion * l_pHomerFfdc =
                ( HomerFfdcRegion *)( (uint8_t *)i_pHomerBuf + FFDC_REGION_HOMER_BASE_OFFSET );

        PlatPmComplex::initRegList();

        for( uint32_t l_exPos = 0; l_exPos < MAX_CMES_PER_CHIP; l_exPos++ )
        {
            uint8_t l_quadPos       =   l_exPos >> 1;
            uint8_t l_relativeExPos =   l_exPos & 0x01;
            PpeFfdcLayout * l_pCmeLayout  =
                    ( PpeFfdcLayout *)&l_pHomerFfdc->iv_quadFfdc[l_quadPos].iv_quadCmeBlock[l_relativeExPos][0];
            uint8_t *l_pCmeXir      =   &l_pCmeLayout->iv_ppeXirReg[0];
            uint8_t *l_pCmeSummary  =   &l_pHomerFfdc->iv_ffdcSummaryRegion.iv_cmeSummary[l_exPos][FFDC_SUMMARY_SEC_HDR_SIZE];
            FfdcScomEntry * l_pCmeLfirEntry  =
                        ( FfdcScomEntry* )&l_pHomerFfdc->iv_firFfdcRegion.iv_firCmeBlock[l_exPos][0];
            SysState * l_pSysState = &l_pHomerFfdc->iv_ffdcSummaryRegion.iv_sysState;

            FfdcSummSubSectHdr * l_pCmeSummaryHdr   =
                                       ( FfdcSummSubSectHdr *) &l_pHomerFfdc->iv_ffdcSummaryRegion.iv_cmeSummary[l_exPos][0];
            l_pHomerFfdc->iv_ffdcSummaryRegion.iv_cmeScoreBoard[l_exPos].iv_dataPtr     =   &l_pCmeLayout->iv_ppeGlobals[0];
            l_pHomerFfdc->iv_ffdcSummaryRegion.iv_cmeScoreBoard[l_exPos].iv_dataSize    =   FFDC_PPE_SCORE_BOARD_SIZE;

            l_pCmeSummaryHdr->iv_subSectnId     =   PLAT_CME;
            l_pCmeSummaryHdr->iv_majorNum       =   1;
            l_pCmeSummaryHdr->iv_minorNum       =   0;
            l_pCmeSummaryHdr->iv_secValid       =   l_pCmeLayout->iv_ppeFfdcHdr.iv_ppeFfdcHdr.iv_sectionsValid;

            if( !l_pCmeSummaryHdr->iv_secValid )
            {
                FAPI_DBG("Skipping CME %d For Summary", l_exPos );
                continue;
            }

            memcpy( &l_pSysState->iv_cmeFirs[l_exPos][0],
                    &l_pCmeLfirEntry->iv_scomData,
                    FFDC_SUMMARY_SCOM_REG_SIZE );

            PlatPmComplex::extractPpeSummaryReg( l_pCmeXir,
                                                 FFDC_PPE_XIR_SIZE,
                                                 l_pCmeSummary );
        }

        FAPI_DBG("<< PlatCme::generateSummary" );

        return fapi2::FAPI2_RC_SUCCESS;
    }

    //-----------------------------------------------------------------------

extern "C"
{
    fapi2::ReturnCode p9_pm_recovery_ffdc_cme( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP >& i_procChip, void * i_pFfdcBuf )
    {
        FAPI_IMP(">> p9_pm_recovery_ffdc_cme" );
        PlatCme l_cmeFfdc( i_procChip );
        FAPI_TRY( l_cmeFfdc.collectFfdc( i_pFfdcBuf,
                                         (ALL & ~(PPE_HALT_STATE | FIR_STATE))),
                  "Failed To Collect CME FFDC" );

    fapi_try_exit:
        FAPI_IMP("<< p9_pm_recovery_ffdc_cme" );
        return fapi2::current_err;
    }

}

 }//namespace p9_stop_recov_ffdc ends
