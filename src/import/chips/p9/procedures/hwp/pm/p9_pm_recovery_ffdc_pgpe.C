/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_pgpe.C $ */
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
/// @file   p9_pm_recovery_ffdc_pgpe.C
/// @brief  Models PGPE platform for the FFDC collection of PM complex
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

#include <p9_pm_recovery_ffdc_pgpe.H>
#include <p9_hcd_memmap_occ_sram.H>
#include <p9_ppe_defs.H>
#include <stddef.h>
#include <endian.h>

 namespace p9_stop_recov_ffdc
 {
    PlatPgpe::PlatPgpe( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt )
      : PlatPmComplex( i_procChipTgt,
                       OCC_SRAM_PGPE_HEADER_ADDR,
                       OCC_SRAM_PGPE_TRACE_START,
                       OCC_SRAM_PGPE_DASHBOARD_START,
                       PLAT_PGPE )
    { }

    //----------------------------------------------------------------------

    fapi2::ReturnCode PlatPgpe::collectFfdc( void * i_pHomerBuf )
    {
        FAPI_DBG(">> PlatPgpe::collectFfdc");
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;
        uint8_t l_ffdcValdityVect = PPE_FFDC_ALL_VALID;

        uint8_t l_haltState = PPE_HALT_COND_UNKNOWN;
        uint8_t *l_pFfdcLoc = NULL;
        HomerFfdcRegion * l_pHomerFfdc =
                ( HomerFfdcRegion *)( (uint8_t *)i_pHomerBuf + FFDC_REGION_HOMER_BASE_OFFSET );

        l_pFfdcLoc = (uint8_t *)(&l_pHomerFfdc->iv_pgpeFfdcRegion);

        //In case of error , invalidate FFDC in header.

        l_retCode = collectPpeState ( PGPE_BASE_ADDRESS,
                                      l_pFfdcLoc );
        if ( l_retCode != fapi2::FAPI2_RC_SUCCESS )
        {
            FAPI_ERR ( "Error collecting PGPE State" );
            l_ffdcValdityVect &= ~PPE_STATE_VALID;
        }

        l_retCode = collectTrace( l_pFfdcLoc );

        if( l_retCode )
        {
            FAPI_ERR("Error in collecting PGPE Trace " );
            l_ffdcValdityVect &= ~PPE_TRACE_VALID;
        }

        l_retCode = collectGlobals( l_pFfdcLoc );

        if( l_retCode )
        {
            FAPI_ERR("Error in collecting PGPE Globals" );
            l_ffdcValdityVect &= ~PPE_DASHBOARD_VALID;
        }

        l_retCode = collectImageHeader( l_pFfdcLoc );

        if( l_retCode )
        {
            FAPI_ERR("Error in collecting PGPE Image header" );
            l_ffdcValdityVect &= ~PPE_IMAGE_HEADER_VALID;
        }


        FAPI_TRY( updatePgpeFfdcHeader( l_pFfdcLoc, l_ffdcValdityVect, l_haltState ),
                          "Failed To Update PGPE FFDC Header for PGPE " );

        fapi_try_exit:
        FAPI_DBG("<< PlatPgpe::collectFfdc");
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatPgpe::collectTrace( uint8_t * i_pTraceBuf )
    {
        FAPI_DBG(">> PlatPgpe::collectTrace" );
        PpeFfdcLayout * l_pPgpeFfdc = ( PpeFfdcLayout *) ( i_pTraceBuf );

        uint8_t * l_pTraceLoc = &l_pPgpeFfdc->iv_ppeTraces[0];

        FAPI_TRY( PlatPmComplex::collectSramInfo
                    ( PlatPmComplex::getProcChip(),
                      l_pTraceLoc,
                      TRACES,
                      FFDC_PPE_TRACES_SIZE ),
                  "Trace Collection Failed" );

        fapi_try_exit:
        FAPI_DBG("<< PlatPgpe::collectTrace" );
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode  PlatPgpe::collectGlobals( uint8_t * i_pPgpeGlobals )
    {
        FAPI_DBG(">> PlatPgpe::collectGlobals" );
        PpeFfdcLayout * l_pPgpeFfdc = ( PpeFfdcLayout *) ( i_pPgpeGlobals );
        uint8_t * l_pTraceLoc = &l_pPgpeFfdc->iv_ppeGlobals[0];

        FAPI_TRY( PlatPmComplex::collectSramInfo
                    ( PlatPmComplex::getProcChip(),
                      l_pTraceLoc,
                      DASH_BOARD_VAR,
                      OCC_SRAM_PGPE_DASHBOARD_SIZE ),
                  "Failed To Collect PGPE Global Variables" );


        fapi_try_exit:
        FAPI_DBG("<< PlatPgpe::collectGlobals" );
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatPgpe::collectInternalReg( uint8_t * i_pPgpeIntReg )
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatPgpe::collectImageHeader( uint8_t * i_pPgpeImgHdr )
    {
        FAPI_DBG(">> PlatPgpe::collectImageHeader" );
        PpeFfdcLayout *l_pPgpeFfdc = ( PpeFfdcLayout *) ( i_pPgpeImgHdr );

        uint8_t * l_pTraceLoc = &l_pPgpeFfdc->iv_ppeImageHeader[0];
        FAPI_TRY( PlatPmComplex::collectSramInfo
                  ( PlatPmComplex::getProcChip(),
                    l_pTraceLoc,
                    IMAGE_HEADER,
                    FFDC_PPE_IMG_HDR_SIZE ),
                  "Failed To Collect PGPE Image Header" );

        fapi_try_exit:
        FAPI_DBG("<< PlatPgpe::collectImageHeader" );
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatPgpe::updatePgpeFfdcHeader( uint8_t * i_pHomerBuf,
                                                      bool i_ffdcValid, uint8_t i_haltState )
    {
        FAPI_DBG(">> updatePgpeFfdcHeader" );

        PpeFfdcHeader * l_pPgpeFfdcHdr       =  ( (PpeFfdcHeader *)(( PpeFfdcHdrRegion * ) i_pHomerBuf ));
        l_pPgpeFfdcHdr->iv_ppeMagicNumber    =  htobe32( FFDC_PGPE_MAGIC_NUM );
        l_pPgpeFfdcHdr->iv_ppeNumber         =  0;
        PlatPmComplex::updatePpeFfdcHeader( l_pPgpeFfdcHdr, i_ffdcValid, i_haltState );

        FAPI_DBG("<< updatePgpeFfdcHeader" );
        return fapi2::FAPI2_RC_SUCCESS;
    }
    //-----------------------------------------------------------------------

extern "C"
{
    fapi2::ReturnCode p9_pm_recovery_ffdc_pgpe( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP >& i_procChip,
                                                void * i_pFfdcBuf )
    {
        FAPI_IMP(">> p9_pm_recovery_pgpe" );

        PlatPgpe l_pgpeFfdc( i_procChip );
        FAPI_TRY( l_pgpeFfdc.collectFfdc( i_pFfdcBuf ),
                  "Failed To Collect PGPE FFDC" );

        fapi_try_exit:
        FAPI_IMP("<< p9_pm_recovery_pgpe" );
        return fapi2::current_err;
    }

}


}//namespace p9_stop_recov_ffdc ends
