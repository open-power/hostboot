/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_occ.C $ */
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
/// @file   p9_pm_recovery_ffdc_occ.C
/// @brief  Model OCC platform for the FFDC collection of PM complex
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Amit Tendolkar <amit.tendolkar@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    Hostboot
//
// *INDENT-OFF*
//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------

#include <p9_pm_recovery_ffdc_occ.H>
#include <p9_hcd_memmap_occ_sram.H>
#include <p9_ppe_defs.H>
#include <stddef.h>
#include <endian.h>

 namespace p9_stop_recov_ffdc
 {
    PlatOcc::PlatOcc (
    const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt ) :
    PlatPmComplex(i_procChipTgt, 0, 0, 0, PLAT_OCC)
    { }

    //----------------------------------------------------------------------

    fapi2::ReturnCode PlatOcc::collectFfdc( void * i_pHomerBuf )
    {
        FAPI_DBG(">> PlatOcc::collectFfdc");
        fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;
        uint8_t l_ffdcValid = OCC_FFDC_INVALID;
        uint8_t* l_pFfdcLoc = NULL;

        HomerFfdcRegion* l_pHomerFfdc = (HomerFfdcRegion*)
             ((uint8_t*) i_pHomerBuf + FFDC_REGION_HOMER_BASE_OFFSET );

        l_pFfdcLoc = (uint8_t*) (&l_pHomerFfdc->iv_occFfdcRegion);

        l_retCode = collectTrace (l_pFfdcLoc, OCC_SRAM_TRACE_BUF_BASE_ERR);
        if( l_retCode )
        {
            FAPI_ERR ("Error collecting OCC ERR Traces");
        }
        l_ffdcValid |= OCC_FFDC_TRACE_ERR_VALID;

        l_retCode = collectTrace (l_pFfdcLoc, OCC_SRAM_TRACE_BUF_BASE_IMP);
        if( l_retCode )
        {
            FAPI_ERR ("Error collecting OCC IMP Traces");
        }
        l_ffdcValid |= OCC_FFDC_TRACE_IMP_VALID;

        l_retCode = collectTrace (l_pFfdcLoc, OCC_SRAM_TRACE_BUF_BASE_INF);
        if( l_retCode )
        {
            FAPI_ERR ("Error collecting OCC INF Traces");
        }
        l_ffdcValid |= OCC_FFDC_TRACE_INF_VALID;

        // @TODO Read SRAM for Base and Size of other undefined regions
        //       before collectTrace

        // @TODO Collect OCC Registers

        FAPI_TRY( updateOccFfdcHeader( l_pFfdcLoc, l_ffdcValid ),
                          "Failed To Update OCC FFDC Header for OCC" );

    fapi_try_exit:
        FAPI_DBG("<< PlatSgpe::collectFfdc");
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatOcc::collectTrace ( uint8_t* i_pTraceBuf,
                                              uint32_t i_sramAddr )
    {
        FAPI_DBG ( ">> PlatOcc::collectTrace: 0x%08X",
                   i_sramAddr );

        OccFfdcRegion* l_pOccFfdc = ( OccFfdcRegion*) (i_pTraceBuf);
        uint8_t* l_pTraceLoc = NULL;
        uint32_t l_len = 0;

        switch (i_sramAddr)
        {
            case OCC_SRAM_TRACE_BUF_BASE_ERR:
                l_pTraceLoc = &l_pOccFfdc->iv_occTraceErr[0];
                setTraceBufAddr (OCC_SRAM_TRACE_BUF_BASE_ERR);
                l_len = FFDC_TRACE_ERR_SIZE;
                break;

            case OCC_SRAM_TRACE_BUF_BASE_INF:
               l_pTraceLoc = &l_pOccFfdc->iv_occTraceInf[0];
                setTraceBufAddr (OCC_SRAM_TRACE_BUF_BASE_INF);
                l_len = FFDC_TRACE_INF_SIZE;
                break;

            case OCC_SRAM_TRACE_BUF_BASE_IMP:
                l_pTraceLoc = &l_pOccFfdc->iv_occTraceImp[0];
                setTraceBufAddr (OCC_SRAM_TRACE_BUF_BASE_IMP);
                l_len = FFDC_TRACE_IMP_SIZE;
                break;

            // @TODO will have to collect other OCC SRAM regions once
            // the util to read and get base + size is done

            default:
                FAPI_ERR ( "PlatOcc::collectTrace Unknown Address! 0x%08X",
                           i_sramAddr );
                // this is likely a code bug, but the overall ffdc flow
                // must carry on, so we do not break with an error
                break;
        }

        if ( l_len != 0 )
        {
            FAPI_TRY ( collectSramInfo ( getProcChip(),
                                         l_pTraceLoc,
                                         TRACES,
                                         l_len ),
                       "::collectTrace Failed Addr: 0x%08X Len: %lu bytes",
                       i_sramAddr, l_len );
        }

    fapi_try_exit:
        FAPI_DBG("<< PlatOcc::collectTrace" );
        return fapi2::current_err;
    }

    //--------------------------------------------------------------------------

    fapi2::ReturnCode PlatOcc::updateOccFfdcHeader ( uint8_t * i_pHomerBuf,
                                                     uint8_t  i_ffdcValid )
    {
        FAPI_DBG(">> updateOccFfdcHeader" );

        OccFfdcHeader* l_pOccFfdcHdr = ((OccFfdcHeader*)
                                       ((OccFfdcHdrRegion*) i_pHomerBuf));
        l_pOccFfdcHdr->iv_magicWord =  htobe32( FFDC_OCC_MAGIC_NUM );
        l_pOccFfdcHdr->iv_ffdcValid = i_ffdcValid;
        l_pOccFfdcHdr->iv_headerSize = sizeof (OccFfdcHeader);
        l_pOccFfdcHdr->iv_sectionSize = htobe16 (sizeof (OccFfdcRegion));
        l_pOccFfdcHdr->iv_offsetErrTrace =
              htobe16 (offsetof (struct OccFfdcRegion, iv_occTraceErr[0]));
        l_pOccFfdcHdr->iv_offsetImpTrace =
              htobe16 (offsetof (struct OccFfdcRegion, iv_occTraceImp[0]));
        l_pOccFfdcHdr->iv_offsetInfTrace =
              htobe16 (offsetof (struct OccFfdcRegion, iv_occTraceInf[0]));
        l_pOccFfdcHdr->iv_offsetSsxTrace =
              htobe16 (offsetof (struct OccFfdcRegion, iv_occTraceSsx[0]));
        l_pOccFfdcHdr->iv_offsetGpe0Trace =
              htobe16 (offsetof (struct OccFfdcRegion, iv_occTraceGpe0[0]));
        l_pOccFfdcHdr->iv_offsetGpe1Trace =
              htobe16 (offsetof (struct OccFfdcRegion, iv_occTraceGpe1[0]));
        l_pOccFfdcHdr->iv_offsetSharedSram =
              htobe16 (offsetof (struct OccFfdcRegion, iv_occSharedSram[0]));
        l_pOccFfdcHdr->iv_offsetOccRegs =
              htobe16 (offsetof (struct OccFfdcRegion, iv_occRegs[0]));

        FAPI_DBG( "================== OCC Header ==========================" );
        FAPI_DBG( "FFDC Validity Vector         :   0x%02x", l_pOccFfdcHdr->iv_ffdcValid );
        FAPI_DBG( "OCC Header Size              :   0x%02x", l_pOccFfdcHdr->iv_headerSize );
        FAPI_DBG( "OCC FFDC Section Size        :   0x%04x", REV_2_BYTE(l_pOccFfdcHdr->iv_sectionSize) );
        FAPI_DBG( "OCC ERR Trace Offset         :   0x%04x", REV_2_BYTE(l_pOccFfdcHdr->iv_offsetErrTrace));
        FAPI_DBG( "OCC IMP Trace Offset         :   0x%04x", REV_2_BYTE(l_pOccFfdcHdr->iv_offsetImpTrace));
        FAPI_DBG( "OCC INF Trace Offset         :   0x%04x", REV_2_BYTE(l_pOccFfdcHdr->iv_offsetInfTrace));
        FAPI_DBG( "OCC SSX Trace Offset         :   0x%04x", REV_2_BYTE(l_pOccFfdcHdr->iv_offsetSsxTrace));
        FAPI_DBG( "OCC GPE0 Trace Offset        :   0x%04x", REV_2_BYTE(l_pOccFfdcHdr->iv_offsetGpe0Trace));
        FAPI_DBG( "OCC GPE1 Trace Offset        :   0x%04x", REV_2_BYTE(l_pOccFfdcHdr->iv_offsetGpe1Trace));
        FAPI_DBG( "OCC Shared SRAM Offset       :   0x%04x", REV_2_BYTE(l_pOccFfdcHdr->iv_offsetSharedSram));
        FAPI_DBG( "OCC OCC Regs Offset          :   0x%04x", REV_2_BYTE(l_pOccFfdcHdr->iv_offsetOccRegs));
        FAPI_DBG( "================== OCC Header Ends ====================" );

        FAPI_DBG("<< updateOccFfdcHeader" );
        return fapi2::FAPI2_RC_SUCCESS;
    }
    //--------------------------------------------------------------------------

extern "C"
{
    fapi2::ReturnCode p9_pm_recovery_ffdc_occ (
           const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP >& i_procChip,
           void*                                               i_pFfdcBuf )
    {
        FAPI_DBG (">> p9_pm_recovery_occ" );

        PlatOcc l_occFfdc( i_procChip );
        FAPI_TRY( l_occFfdc.collectFfdc( i_pFfdcBuf ),
                  "Failed To Collect OCC FFDC" );

    fapi_try_exit:
        FAPI_DBG ("<< p9_pm_recovery_occ" );
        return fapi2::current_err;
    }
}


}//namespace p9_stop_recov_ffdc ends
