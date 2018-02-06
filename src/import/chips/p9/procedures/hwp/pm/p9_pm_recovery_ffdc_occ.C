/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_occ.C $ */
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
#include <p9_perv_scom_addresses.H>
#include <p9_misc_scom_addresses.H>
#include <p9n2_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fixes.H>
#include <p9_ppe_defs.H>
#include <stddef.h>
#include <endian.h>

namespace p9_stop_recov_ffdc
{
    PlatOcc::PlatOcc (
    const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt ) :
    PlatPmComplex ( i_procChipTgt, PLAT_OCC )
    { }

    //----------------------------------------------------------------------

    fapi2::ReturnCode PlatOcc::init ( void* i_pHomerBuf )
    {
        FAPI_DBG (">> PlatOcc::init" );
        FAPI_TRY ( collectFfdc( i_pHomerBuf, INIT),
        "Failed To init OCC FFDC" );

    fapi_try_exit:
        FAPI_DBG ("<< PlatOcc::init" );
        return fapi2::current_err;
    }

    //----------------------------------------------------------------------

    void PlatOcc::initRegList()
    {
        FAPI_DBG (">> PlatOcc::initRegList" );
        std::vector < uint32_t> l_scomRegList;
        l_scomRegList.push_back( PU_OCB_OCI_CCSR_SCOM );
        l_scomRegList.push_back( PU_OCB_OCI_QSSR_SCOM );
        l_scomRegList.push_back( P9N2_PU_OCB_OCI_OCCFLG_SCOM );
        l_scomRegList.push_back( P9N2_PU_OCB_OCI_OCCFLG2_SCOM );
        PlatPmComplex::updateSummaryList( l_scomRegList );
        FAPI_DBG ("<< PlatOcc::initRegList" );
    }

    //----------------------------------------------------------------------

    fapi2::ReturnCode PlatOcc::collectFfdc( void*   i_pHomerBuf,
                                            uint8_t i_ffdcType )
    {
        FAPI_DBG(">> PlatOcc::collectFfdc");
        fapi2::ReturnCode l_retCode = fapi2::FAPI2_RC_SUCCESS;
        uint8_t* l_pFfdcLoc = NULL;

        HomerFfdcRegion* l_pHomerFfdc = (HomerFfdcRegion*)
             ((uint8_t*) i_pHomerBuf + FFDC_REGION_HOMER_BASE_OFFSET );

        l_pFfdcLoc = (uint8_t*) (&l_pHomerFfdc->iv_occFfdcRegion);
        OccFfdcHeader* l_pOccFfdcHdr = ((OccFfdcHeader*)
                                       ((OccFfdcHdrRegion*) l_pFfdcLoc));
        uint16_t l_ffdcValid = l_pOccFfdcHdr->iv_sectionsValid;

        if ( i_ffdcType & INIT )
        {   // overwrite validity of OOC section header on init
            l_ffdcValid = OCC_FFDC_INVALID;
            // Mark OCC FIR FFDC bit as invalid on init
            FAPI_TRY ( updateFirFfdcHeader (
                       &l_pHomerFfdc->iv_firFfdcRegion.iv_firFfdcHeader[0],
                       PM_FFDC_FIR_VALID_POS_OCC,
                       false ) );
            // Update validity in top level header
            setPmFfdcSectionValid (i_pHomerBuf, (PM_FFDC_OCC_VALID | PM_FFDC_FIR_VALID), false);
        }

        if ( i_ffdcType & FIR_STATE )
        {
            bool l_firValid = true;

            l_retCode = collectRegisterData <fapi2::TARGET_TYPE_PROC_CHIP> (
                        getProcChip(),
                         &l_pHomerFfdc->iv_firFfdcRegion.iv_OccPbaBlock[0],
                        fapi2::PM_FIR_REGISTERS );
            if (l_retCode)
            {
                FAPI_ERR ("OCC FIR Data collection fail");
                l_firValid = false;
            }
            // Update FIR FFDC header with the OCC FIR validity status
            FAPI_TRY ( updateFirFfdcHeader (
                       &l_pHomerFfdc->iv_firFfdcRegion.iv_firFfdcHeader[0],
                       PM_FFDC_FIR_VALID_POS_OCC,
                       l_firValid ) );

            setPmFfdcSectionValid (i_pHomerBuf, PM_FFDC_FIR_VALID);
        }

        if ( i_ffdcType & TRACES )
        {
            l_ffdcValid |= OCC_FFDC_TRACE_ERR;
            l_retCode = collectTrace (l_pFfdcLoc, OCC_FFDC_TRACE_ERR);
            if( l_retCode )
            {
                FAPI_ERR ("Error collecting OCC ERR Traces");
                l_ffdcValid &= ~OCC_FFDC_TRACE_ERR;
            }

            l_ffdcValid |= OCC_FFDC_TRACE_IMP;
            l_retCode = collectTrace (l_pFfdcLoc, OCC_FFDC_TRACE_IMP);
            if( l_retCode )
            {
                FAPI_ERR ("Error collecting OCC IMP Traces");
                l_ffdcValid &= ~OCC_FFDC_TRACE_IMP;
            }

            l_ffdcValid |= OCC_FFDC_TRACE_INF;
            l_retCode = collectTrace (l_pFfdcLoc, OCC_FFDC_TRACE_INF);
            if( l_retCode )
            {
                FAPI_ERR ("Error collecting OCC INF Traces");
                l_ffdcValid &= ~OCC_FFDC_TRACE_INF;
            }

            // OCC team has not yet enabled SSX tracing
            // Avoid collecting unknown data from SRAM until it is enabled
#if 0
            l_ffdcValid |= OCC_FFDC_TRACE_SSX;
            l_retCode = readSramRegion (l_pFfdcLoc, OCC_FFDC_TRACE_SSX);
            if ( l_retCode )
            {
                FAPI_ERR ("Error collecting OCC SSX Traces");
                l_ffdcValid &= ~OCC_FFDC_TRACE_SSX;
            }
#endif

            l_ffdcValid |= OCC_FFDC_TRACE_GPE0;
            l_retCode = readSramRegion (l_pFfdcLoc, OCC_FFDC_TRACE_GPE0);
            if ( l_retCode )
            {
                FAPI_ERR ("Error collecting GPE0 Traces");
                l_ffdcValid &= ~OCC_FFDC_TRACE_GPE0;
            }

            l_ffdcValid |= OCC_FFDC_TRACE_GPE1;
            l_retCode = readSramRegion (l_pFfdcLoc, OCC_FFDC_TRACE_GPE1);
            if ( l_retCode )
            {
                FAPI_ERR ("Error collecting GPE1 Traces");
                l_ffdcValid &= ~OCC_FFDC_TRACE_GPE1;
            }

            l_ffdcValid |= OCC_FFDC_SHARED_REGION;
            l_retCode = readSramRegion (l_pFfdcLoc, OCC_FFDC_SHARED_REGION);
            if ( l_retCode )
            {
                FAPI_ERR ("Error collecting OCC Shared Region");
                l_ffdcValid &= ~OCC_FFDC_SHARED_REGION;
            }
            setPmFfdcSectionValid (i_pHomerBuf, PM_FFDC_OCC_VALID);
        }

        if ( i_ffdcType & SCOM_REG )
        {
            l_ffdcValid |= OCC_FFDC_REGISTERS;
            l_retCode = collectOccReg( l_pFfdcLoc);

            if( l_retCode )
            {
                FAPI_ERR("Error in collecting OCC scom Regs");
                l_ffdcValid &= ~OCC_FFDC_REGISTERS;
            }
            setPmFfdcSectionValid (i_pHomerBuf, PM_FFDC_OCC_VALID);
        }

        FAPI_TRY( updateOccFfdcHeader( l_pFfdcLoc, l_ffdcValid ),
                          "Failed To Update OCC FFDC Header for OCC" );

        if( !(i_ffdcType & INIT ) )
        {
            generateSummary( i_pHomerBuf );
        }

    fapi_try_exit:
        logPmResetPhase (i_pHomerBuf);
        FAPI_DBG("<< PlatOcc::collectFfdc");
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatOcc::collectOccReg( uint8_t * i_pOccReg)
    {
        FAPI_DBG(">> PlatOcc::collectOccReg" );

        OccFfdcRegion* l_pOccFfdc = ( OccFfdcRegion*) (i_pOccReg);
        uint8_t * l_pRegs = &l_pOccFfdc->iv_occRegs[0];

        FAPI_TRY(collectRegisterData<fapi2::TARGET_TYPE_PROC_CHIP> (getProcChip(),
                                     l_pRegs,
                                     static_cast<fapi2::HwpFfdcId>(fapi2::OCC_FFDC_REGISTERS)),
                      "Failed to collect register data for OCC ");


    fapi_try_exit:
        FAPI_DBG("<< PlatOcc::collectOccReg" );
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode PlatOcc::collectTrace ( uint8_t* i_pTraceBuf,
                                              uint8_t  i_occSramRegion )
    {
        FAPI_DBG ( ">> PlatOcc::collectTrace: 0x%02X", i_occSramRegion );

        OccFfdcRegion* l_pOccFfdc = ( OccFfdcRegion*) (i_pTraceBuf);
        uint8_t* l_pTraceLoc = NULL;
        uint32_t l_len = 0;
        uint32_t l_sramAddr = 0;

        switch ( i_occSramRegion )
        {
            case OCC_FFDC_TRACE_ERR:
                l_pTraceLoc = &l_pOccFfdc->iv_occTraceErr[0];
                l_sramAddr = OCC_SRAM_TRACE_BUF_BASE_ERR;
                l_len = FFDC_TRACE_ERR_SIZE;
                break;

            case OCC_FFDC_TRACE_INF:
                l_pTraceLoc = &l_pOccFfdc->iv_occTraceInf[0];
                l_sramAddr = OCC_SRAM_TRACE_BUF_BASE_INF;
                l_len = FFDC_TRACE_INF_SIZE;
                break;

            case OCC_FFDC_TRACE_IMP:
                l_pTraceLoc = &l_pOccFfdc->iv_occTraceImp[0];
                l_sramAddr = OCC_SRAM_TRACE_BUF_BASE_IMP;
                l_len = FFDC_TRACE_IMP_SIZE;
                break;

            default:
                FAPI_ERR ( "PlatOcc::collectTrace Unknown Address! 0x%08X",
                           l_sramAddr );
                // this is likely a code bug, but the overall ffdc flow
                // must carry on, so we do not break with an error
                break;
        }

        if ( l_len != 0 )
        {
            setTraceBufAddr (l_sramAddr);
            FAPI_TRY ( collectSramInfo ( getProcChip(),
                                         l_pTraceLoc,
                                         TRACES,
                                         l_len ),
                       "::collectTrace Failed Addr: 0x%08X Len: %lu bytes",
                       l_sramAddr, l_len );
        }

    fapi_try_exit:
        FAPI_DBG("<< PlatOcc::collectTrace" );
        return fapi2::current_err;
    }

    //--------------------------------------------------------------------------

    fapi2::ReturnCode PlatOcc::readSramRegion ( uint8_t* i_pHomerBuf,
                                                uint8_t  i_occSramRegion )
    {
        FAPI_DBG ( ">> PlatOcc::readSramRegion: 0x%02X", i_occSramRegion );

        OccFfdcRegion* l_pOccFfdc = ( OccFfdcRegion*) (i_pHomerBuf);
        uint8_t* l_pLoc = NULL;
        uint32_t l_len = 0;
        uint32_t l_sramAddr = 0;

        switch ( i_occSramRegion )
        {
            case OCC_FFDC_TRACE_SSX:
                l_pLoc = &l_pOccFfdc->iv_occTraceSsx[0];
                l_sramAddr = OCC_SRAM_TRACE_BUF_BASE_SSX_PTR;
                break;

            case OCC_FFDC_TRACE_GPE0:
                l_pLoc = &l_pOccFfdc->iv_occTraceGpe0[0];
                l_sramAddr = GPE0_SRAM_BASE_ADDR + GPE_DEBUG_PTR_OFFSET;
                break;

            case OCC_FFDC_TRACE_GPE1:
                l_pLoc = &l_pOccFfdc->iv_occTraceGpe1[0];
                l_sramAddr = GPE1_SRAM_BASE_ADDR + GPE_DEBUG_PTR_OFFSET;
                break;

            case OCC_FFDC_SHARED_REGION:
                l_pLoc = &l_pOccFfdc->iv_occSharedSram[0];
                l_sramAddr = OCC_SRAM_PGPE_HEADER_ADDR +
                             PGPE_SHARED_SRAM_ADDR_BYTE;
                break;

            default:
                FAPI_ERR ( "PlatOcc::readSramRegion Unknown Address! 0x%08X",
                           l_sramAddr );
                break;
        }

        // For regions where the start and size are not pre-defined
        // read the start address and size of the region from SRAM.
        // The start address and size are expected to be 4 byte apart
        fapi2::variable_buffer l_buf (128);
        uint32_t l_sramSize = 0;

        // Read from an 8B aligned address and adjust data accordingly
        uint32_t l_bytesToAlign = l_sramAddr & 0x7UL;
        uint32_t l_bitStartPos = l_bytesToAlign * 8;

        FAPI_DBG ("SRAM Region Params: %d Addr: 0x%08X Aligned Addr: 0x%08X",
                  i_occSramRegion, l_sramAddr, (l_sramAddr-l_bytesToAlign));
        l_sramAddr -= l_bytesToAlign;
        setTraceBufAddr (l_sramAddr);

        // Read 16 bytes from SRAM
        FAPI_TRY ( collectSramInfo (
                   getProcChip (),
                   reinterpret_cast<uint8_t*>(l_buf.pointer()),
                   TRACES,
                   16 ) );

        // Get the read data at an offset based on the aligned address
        FAPI_TRY (l_buf.extract (l_sramAddr, l_bitStartPos, 32));
        FAPI_TRY (l_buf.extract (l_sramSize, (l_bitStartPos+64), 32));

        FAPI_INF ("SRAM Region: 0x%08X Addr: 0x%08X Size: %d bytes",
                  i_occSramRegion, l_sramAddr, l_sramSize);

        // Ensure size of the region is not overshooting its budget in HOMER
        switch (i_occSramRegion)
        {
            case OCC_FFDC_TRACE_SSX:
                l_len = (l_sramSize > FFDC_TRACE_SSX_SIZE) ?
                        FFDC_TRACE_SSX_SIZE : l_sramSize;
                break;
            case OCC_FFDC_TRACE_GPE0:
                l_len = (l_sramSize > FFDC_TRACE_GPE0_SIZE) ?
                        FFDC_TRACE_GPE0_SIZE : l_sramSize;
                break;
            case OCC_FFDC_TRACE_GPE1:
                l_len = (l_sramSize > FFDC_TRACE_GPE1_SIZE) ?
                        FFDC_TRACE_GPE1_SIZE : l_sramSize;
                break;
            case OCC_FFDC_SHARED_REGION:
                l_len = (l_sramSize > FFDC_SHARED_SRAM_SIZE) ?
                        FFDC_SHARED_SRAM_SIZE : l_sramSize;
                break;
            default:
                FAPI_ERR ( "PlatOcc::readSramRegion bad region! 0x%08X",
                           i_occSramRegion);
                l_len = 0;
                break;
        }

        if ( l_len != 0 )
        {
            setTraceBufAddr (l_sramAddr);
            FAPI_TRY ( collectSramInfo ( getProcChip(),
                                         l_pLoc,
                                         TRACES,
                                         l_len ),
                       "::readSramRegion Failed Addr: 0x%08X Len: %lu bytes",
                       l_sramAddr, l_len );
        }

    fapi_try_exit:
        FAPI_DBG("<< PlatOcc::readSramRegion" );
        return fapi2::current_err;
    }

    //--------------------------------------------------------------------------

    fapi2::ReturnCode PlatOcc::updateOccFfdcHeader ( uint8_t * i_pHomerBuf,
                                                     uint16_t  i_ffdcValid )
    {
        FAPI_DBG(">> updateOccFfdcHeader" );

        OccFfdcHeader* l_pOccFfdcHdr = ((OccFfdcHeader*)
                                       ((OccFfdcHdrRegion*) i_pHomerBuf));
        l_pOccFfdcHdr->iv_magicWord =  htobe32( FFDC_OCC_MAGIC_NUM );
        l_pOccFfdcHdr->iv_versionMajor = 1;
        l_pOccFfdcHdr->iv_versionMinor = 0;
        l_pOccFfdcHdr->iv_headerSize = htobe16 (sizeof (OccFfdcHeader));
        l_pOccFfdcHdr->iv_sectionSize = htobe16 (sizeof (OccFfdcRegion));
        l_pOccFfdcHdr->iv_sectionsValid = htobe16 (i_ffdcValid);
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
        FAPI_DBG( "FFDC Validity Vector         :   0x%04x", REV_2_BYTE(l_pOccFfdcHdr->iv_sectionsValid ));
        FAPI_DBG( "OCC Header Size              :   0x%04x", REV_2_BYTE(l_pOccFfdcHdr->iv_headerSize ));
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

    fapi2::ReturnCode PlatOcc::generateSummary( void * i_pHomer )
    {
       HomerFfdcRegion * l_pHomerFfdc   =
                ( HomerFfdcRegion *)( (uint8_t *)i_pHomer + FFDC_REGION_HOMER_BASE_OFFSET );
       OccFfdcRegion * l_pOccLayout     =   ( OccFfdcRegion * ) &l_pHomerFfdc->iv_occFfdcRegion;
       uint8_t * l_pOccReg              =   &l_pOccLayout->iv_occRegs[0];
       FfdcScomEntry * l_pFirEntry      =   (FfdcScomEntry *)&l_pHomerFfdc->iv_firFfdcRegion.iv_OccPbaBlock[0];
       SysState * l_pSysConfig          =   &l_pHomerFfdc->iv_ffdcSummaryRegion.iv_sysState;
       OccFfdcHeader* l_pOccFfdcHdr     =   (OccFfdcHeader*) ( &l_pHomerFfdc->iv_occFfdcRegion );

       FfdcSummSubSectHdr * l_pSysConfigHdr   =
                    (FfdcSummSubSectHdr *)&l_pSysConfig->iv_subSecHdr;
       l_pSysConfigHdr->iv_subSectnId   =   PLAT_OCC;
       l_pSysConfigHdr->iv_majorNum     =   1;
       l_pSysConfigHdr->iv_minorNum     =   0;
       l_pSysConfigHdr->iv_secValid     =   l_pOccFfdcHdr->iv_sectionsValid;

       if( l_pSysConfigHdr->iv_secValid )
       {
           initRegList();
           memcpy( &l_pSysConfig->iv_occPbaFir[0],
                   &l_pFirEntry->iv_scomData,
                   FFDC_SUMMARY_SCOM_REG_SIZE ) ; //copying first FIR value

                   l_pFirEntry++;

           memcpy( &l_pSysConfig->iv_occPbaFir[FFDC_SUMMARY_SCOM_REG_SIZE],
                   &l_pFirEntry->iv_scomData,
                   FFDC_SUMMARY_SCOM_REG_SIZE ); //copying second FIR value


           PlatPmComplex::extractScomSummaryReg( l_pOccReg,
                                                 FFDC_OCC_REGS_SIZE,
                                                 &l_pSysConfig->iv_configReg[0] );
       }

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
        FAPI_TRY( l_occFfdc.collectFfdc ( i_pFfdcBuf, (TRACES | SCOM_REG)),
                  "Failed To Collect OCC FFDC" );

    fapi_try_exit:
        FAPI_DBG ("<< p9_pm_recovery_occ" );
        return fapi2::current_err;
    }
}


}//namespace p9_stop_recov_ffdc ends
