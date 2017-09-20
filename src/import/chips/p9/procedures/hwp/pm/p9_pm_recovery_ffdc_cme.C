/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_cme.C $ */
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
#include <stddef.h>
#include <endian.h>

 namespace p9_stop_recov_ffdc
 {
    PlatCme::PlatCme( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt )
      : PlatPmComplex( i_procChipTgt,
                       FFDC_PPE_IMG_HDR_START,
                       FFDC_CME_TRACE_START,
                       FFDC_CME_DASH_BOARD_START,
                       PLAT_CME )
    { }

    //----------------------------------------------------------------------

    fapi2::ReturnCode PlatCme::collectFfdc( void * i_pHomerBuf )
    {
        FAPI_DBG(">> PlatCme::collectFfdc");
        fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;
        auto l_exList =
            getProcChip().getChildren< fapi2::TARGET_TYPE_EX > ( fapi2::TARGET_STATE_PRESENT );
        uint8_t l_quadPos = 0;
        uint8_t l_exPos   = 0;
        uint8_t l_cmePos  = 0;
        uint8_t l_ffdcValdityVect = PPE_FFDC_ALL_VALID;
        uint8_t l_haltState = 0; //FIXME Needs update when PPE State gets handled
        uint8_t *l_pFfdcLoc = NULL;
        HomerFfdcRegion * l_pHomerFfdc =
                ( HomerFfdcRegion *)( (uint8_t *)i_pHomerBuf + FFDC_REGION_HOMER_BASE_OFFSET );

        for( auto ex : l_exList )
        {
            l_ffdcValdityVect = PPE_FFDC_ALL_VALID;

            FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, ex, l_cmePos ),
                      "FAPI_ATTR_GET Failed To Read EX Position" );

            if( !ex.isFunctional() )
            {
                //Marking CME FFDC region as Invalid
                FAPI_TRY( updateCmeFfdcHeader( l_pFfdcLoc, l_cmePos, l_ffdcValdityVect, l_haltState ),
                          "Failed To Update CME FFDC Header for CME 0x%0d", l_cmePos );
                continue;
            }

            l_exPos     =   l_cmePos % 2;
            l_quadPos   =   l_cmePos >> 1;
            l_pFfdcLoc = &l_pHomerFfdc->iv_quadFfdc[l_quadPos].iv_quadCmeBlock[l_exPos][0];

            FAPI_INF("CME FFDC Quad Pos %d Ex Pos %d ", l_quadPos, l_exPos );

            //In case of error , invalidate FFDC in header.

            l_retCode = collectTrace( l_pFfdcLoc, ex );

            if( l_retCode )
            {
                FAPI_ERR("Error in collecting CME Trace CME Pos 0x%08x", l_cmePos );
                l_ffdcValdityVect &= ~PPE_TRACE_VALID;
            }

            l_retCode = collectGlobals( l_pFfdcLoc, ex );

            if( l_retCode )
            {
                FAPI_ERR("Error in collecting CME Globals, CME Pos 0x%08x", l_cmePos );
                l_ffdcValdityVect &= ~PPE_DASHBOARD_VALID;
            }

            l_retCode = collectImageHeader( l_pFfdcLoc, ex );

            if( l_retCode )
            {
                FAPI_ERR("Error in collecting CME Image header, CME Pos 0x%08x", l_cmePos );
                l_ffdcValdityVect &= ~PPE_IMAGE_HEADER_VALID;
            }

            FAPI_TRY( updateCmeFfdcHeader( l_pFfdcLoc, l_cmePos, l_ffdcValdityVect, l_haltState ),
                      "Failed To Update CME FFDC Header for CME 0x%0d", l_cmePos );
        }

        fapi_try_exit:
        FAPI_DBG("<< PlatCme::collectFfdc");
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatCme::collectTrace( uint8_t * i_pTraceBuf,
                                             const fapi2::Target<fapi2::TARGET_TYPE_EX >& i_exTgt  )
    {
        FAPI_DBG(">> PlatCme::collectTrace" );
        PpeFfdcLayout * l_pCmeFfdc = ( PpeFfdcLayout *) ( i_pTraceBuf );

        uint8_t * l_pTraceLoc = &l_pCmeFfdc->iv_ppeTraces[0];

        FAPI_TRY( PlatPmComplex::collectSramInfo
                    ( i_exTgt,
                      l_pTraceLoc,
                      TRACES,
                      FFDC_PPE_TRACES_SIZE ),
                  "Trace Collection Failed" );

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

    fapi2::ReturnCode  PlatCme::collectCmeState( uint8_t * i_pCmeState,
                                                 const fapi2::Target<fapi2::TARGET_TYPE_EX >& i_exTgt )
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatCme::collectInternalReg( uint8_t * i_pCmeIntReg,
                                                   const fapi2::Target<fapi2::TARGET_TYPE_EX >& i_exTgt )
    {
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

    fapi2::ReturnCode PlatCme::updateCmeFfdcHeader( uint8_t * i_pHomerBuf, uint8_t i_cmePos,
                                                    uint8_t l_ffdcValdityVect, uint8_t i_haltState )
    {
        FAPI_DBG(">> updateCmeFfdcHeader" );

        PpeFfdcHeader * l_pCmeFfdcHdr =  ( (PpeFfdcHeader *)(( PpeFfdcHdrRegion * ) i_pHomerBuf ));
        l_pCmeFfdcHdr->iv_ppeMagicNumber    =  htobe32(FFDC_CME_MAGIC_NUM);
        l_pCmeFfdcHdr->iv_ppeNumber         =  i_cmePos;
        PlatPmComplex::updatePpeFfdcHeader( l_pCmeFfdcHdr, l_ffdcValdityVect, i_haltState );

        FAPI_DBG("<< updateCmeFfdcHeader" );
        return fapi2::FAPI2_RC_SUCCESS;
    }
    //-----------------------------------------------------------------------

extern "C"
{
    fapi2::ReturnCode p9_pm_recovery_ffdc_cme( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP >& i_procChip, void * i_pFfdcBuf )
    {
        FAPI_IMP(">> p9_pm_recovery_ffdc_cme" );
        PlatCme l_cmeFfdc( i_procChip );
        FAPI_TRY( l_cmeFfdc.collectFfdc( i_pFfdcBuf ),
                  "Failed To Collect CME FFDC" );

        fapi_try_exit:
        FAPI_IMP("<< p9_pm_recovery_ffdc_cme" );
        return fapi2::current_err;
    }

}

 }//namespace p9_stop_recov_ffdc ends
