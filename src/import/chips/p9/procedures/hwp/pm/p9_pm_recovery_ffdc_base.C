/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_base.C $ */
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

#include <p9_pm_recovery_ffdc_base.H>
#include <p9_pm_recovery_ffdc_defines.H>

#include <p9_pm_recovery_ffdc_cme.H>
#include <p9_pm_recovery_ffdc_sgpe.H>
#include <p9_pm_recovery_ffdc_pgpe.H>
#include <p9_pm_recovery_ffdc_occ.H>
#include <p9_pm_recovery_ffdc_cppm.H>
#include <p9_pm_recovery_ffdc_qppm.H>

#include <p9_ppe_state.H>
#include <p9_pm_ocb_indir_access.H>
#include <p9_cme_sram_access.H>
#include <p9_pm_ocb_indir_setup_linear.H>

#include <endian.h>
#include <stddef.h>

namespace p9_stop_recov_ffdc
{
    PlatPmComplex::PlatPmComplex( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt,
                                  PmComplexPlatId i_plat, uint32_t i_imageHdrBaseAddr,
                                  uint32_t i_traceBufBaseAddr, uint32_t i_globalBaseAddr )
      : iv_procChip( i_procChipTgt ),
        iv_imageHeaderBaseAddress( i_imageHdrBaseAddr ),
        iv_traceBufBaseAddress( i_traceBufBaseAddr ),
        iv_globalBaseAddress( i_globalBaseAddr ),
        iv_plat( i_plat )
    { }

    //---------------------------------------------------------------------------------------------

    fapi2::ReturnCode PlatPmComplex::init ( void* i_pHomerBuf )
    {
        FAPI_DBG ( ">> PlatPmComplex::init" );

        HomerFfdcRegion* l_pHomerFfdc = ( HomerFfdcRegion* )
             ((uint8_t*) i_pHomerBuf + FFDC_REGION_HOMER_BASE_OFFSET );

        uint8_t* l_pFfdcLoc = (uint8_t*) (&l_pHomerFfdc->iv_pmFfdcHdrRegion);
        PmFfdcHeader* l_pPmFfdcHdr = (PmFfdcHeader*)
                                     ((PmFfdcHdrRegion*) l_pFfdcLoc);
        uint32_t l_procPosition = 0xDEADC0DE;

        if (FAPI_ATTR_GET (fapi2::ATTR_FAPI_POS, iv_procChip, l_procPosition) !=
            fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR ("Could not read ATTR_FAPI_POS for the chip!");
        }

        l_pPmFfdcHdr->iv_magicNumber = htobe32 (FFDC_MAGIC_NUM);
        l_pPmFfdcHdr->iv_versionMajor = 0x01;
        l_pPmFfdcHdr->iv_versionMinor = 0x00;
        l_pPmFfdcHdr->iv_headerSize = htobe16 (sizeof (PmFfdcHeader));
        l_pPmFfdcHdr->iv_sectionSize = htobe32 (sizeof (HomerFfdcRegion));
        l_pPmFfdcHdr->iv_procPosition = htobe32 (l_procPosition);
        l_pPmFfdcHdr->iv_ffdcValid = 0x01;
        l_pPmFfdcHdr->iv_phase = PM_RESET_FFDC_SEC_INIT;
        l_pPmFfdcHdr->iv_errorMarker = htobe16 (0x0000);
        l_pPmFfdcHdr->iv_sectionsValid = htobe16 (PM_FFDC_INVALID);

        uint16_t l_sectionOffset = sizeof (PmFfdcHeader);
        l_pPmFfdcHdr->iv_firOffset = htobe16 (l_sectionOffset);
        l_sectionOffset+= sizeof (FirFfdcRegion);

        for ( int i=0; i<MAX_QUADS_PER_CHIP; ++i )
        {
            l_pPmFfdcHdr->iv_quadOffset[i] = htobe16 (l_sectionOffset);
            l_sectionOffset += sizeof (HomerQuadFfdcRegion);
        }

        l_pPmFfdcHdr->iv_sgpeOffset = htobe16 (l_sectionOffset);
        l_sectionOffset += sizeof (PpeFfdcLayout);
        l_pPmFfdcHdr->iv_pgpeOffset = htobe16 (l_sectionOffset);
        l_sectionOffset += sizeof (PpeFfdcLayout);
        l_pPmFfdcHdr->iv_occOffset = htobe16 (l_sectionOffset);
        l_pPmFfdcHdr->iv_ccsr = 0; // @TODO via RTC 153978
        l_pPmFfdcHdr->iv_qcsr = 0; // @TODO via RTC 153978

        FAPI_DBG( "================== PM FFDC Header ==========================" );
        FAPI_DBG( "Magic Number                 :   0x%08X", l_pPmFfdcHdr->iv_magicNumber );
        FAPI_DBG( "Version Major                :   0x%02X", l_pPmFfdcHdr->iv_versionMajor );
        FAPI_DBG( "Version Minor                :   0x%02X", l_pPmFfdcHdr->iv_versionMinor);
        FAPI_DBG( "Header Size                  :   0x%02X", l_pPmFfdcHdr->iv_headerSize );
        FAPI_DBG(" FFDC Section Size            :   0x%08X", l_pPmFfdcHdr->iv_sectionSize );
        FAPI_DBG(" Proc Position                :   0x%08X", l_pPmFfdcHdr->iv_procPosition );
        FAPI_DBG(" PM FFDC Valid                :   0x%02X", l_pPmFfdcHdr->iv_ffdcValid );
        FAPI_DBG(" PM RESET Phase               :   0x%02X", l_pPmFfdcHdr->iv_phase );
        FAPI_DBG(" Error Marker                 :   0x%04X", l_pPmFfdcHdr->iv_errorMarker );
        FAPI_DBG(" Sub-section Validity Vector  :   0x%04X", l_pPmFfdcHdr->iv_sectionsValid );
        FAPI_DBG(" FIR Sub-section Offset       :   0x%04X", l_pPmFfdcHdr->iv_firOffset );
        FAPI_DBG(" Quad 0 Sub-section Offset    :   0x%04X", l_pPmFfdcHdr->iv_quadOffset[0] );
        FAPI_DBG(" Quad 1 Sub-section Offset    :   0x%04X", l_pPmFfdcHdr->iv_quadOffset[1] );
        FAPI_DBG(" Quad 2 Sub-section Offset    :   0x%04X", l_pPmFfdcHdr->iv_quadOffset[2] );
        FAPI_DBG(" Quad 3 Sub-section Offset    :   0x%04X", l_pPmFfdcHdr->iv_quadOffset[3] );
        FAPI_DBG(" Quad 4 Sub-section Offset    :   0x%04X", l_pPmFfdcHdr->iv_quadOffset[4] );
        FAPI_DBG(" Quad 5 Sub-section Offset    :   0x%04X", l_pPmFfdcHdr->iv_quadOffset[5] );
        FAPI_DBG(" SGPE Sub-section Offset      :   0x%04X", l_pPmFfdcHdr->iv_sgpeOffset );
        FAPI_DBG(" PGPE Sub-section Offset      :   0x%04X", l_pPmFfdcHdr->iv_pgpeOffset );
        FAPI_DBG(" OCC Sub-section Offset       :   0x%04X", l_pPmFfdcHdr->iv_occOffset );
        FAPI_DBG( "================== PM FFDC Header End ====================" );

        FAPI_DBG ("<< PlatPmComplex::init");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    //---------------------------------------------------------------------------------------------

    fapi2::ReturnCode PlatPmComplex::collectFfdc( void*   i_pHomerBuf,
                                                  uint8_t i_ffdcType )
    {
        FAPI_DBG ( ">> PlatPmComplex::collectFfdc" );
        FAPI_INF ( "PlatPmComplex::collectFfdc No-Op. Plat Type 0x%02X",
                   iv_plat );
        FAPI_DBG("<< PlatPmComplex::collectFfdc");

        return fapi2::FAPI2_RC_SUCCESS;
    }

    //---------------------------------------------------------------------------------------------
    #ifndef __HOSTBOOT_MODULE   // for manual examination of info on cronus

    fapi2::ReturnCode PlatPmComplex::debugSramInfo( uint8_t * i_pSramLoc, uint32_t i_dataLen )
    {
        FAPI_DBG(">>PlatPmComplex::debugSramInfo");
        uint32_t l_data = 0;
        uint32_t l_doubleWordLength  =   i_dataLen >> 3;
        uint64_t * l_pDoubleWord     =   (uint64_t *)i_pSramLoc;
        uint64_t tempWord = 0;

        for ( l_data = 0; l_data < l_doubleWordLength; l_data++ )
        {
             tempWord    =   htobe64(*l_pDoubleWord);
             *l_pDoubleWord    =   tempWord;
              l_pDoubleWord++;

        }

        return fapi2::FAPI2_RC_SUCCESS;

    }
     #endif
    //---------------------------------------------------------------------------------------------

    fapi2::ReturnCode PlatPmComplex::updatePpeFfdcHeader ( PpeFfdcHeader * i_pFfdcHdr,
                                                           uint16_t i_sectionsValid )
    {
        FAPI_DBG(">> updatePpeFfdcHeader" );

        i_pFfdcHdr->iv_versionMajor      = 1;
        i_pFfdcHdr->iv_versionMinor      = 0;
        i_pFfdcHdr->iv_headerSize        = htobe16 (sizeof(PpeFfdcHeader));
        i_pFfdcHdr->iv_sectionSize       = htobe16 (sizeof(PpeFfdcLayout ));
        i_pFfdcHdr->iv_sectionsValid         = htobe16 (i_sectionsValid);
        i_pFfdcHdr->iv_dashBoardOffset   = htobe16( offsetof( struct PpeFfdcLayout, iv_ppeGlobals[0]));
        i_pFfdcHdr->iv_sramHeaderOffset  = htobe16( offsetof( struct PpeFfdcLayout, iv_ppeImageHeader[0]));
        i_pFfdcHdr->iv_sprOffset         = htobe16( offsetof( struct PpeFfdcLayout, iv_ppeXirReg[0]));
        i_pFfdcHdr->iv_intRegOffset      = htobe16( offsetof( struct PpeFfdcLayout, iv_ppeInternalReg[0]));
        i_pFfdcHdr->iv_offsetTraces      = htobe16( offsetof( struct PpeFfdcLayout, iv_ppeTraces[0] ));

        FAPI_DBG( "================== PPE Header ==========================" );
        FAPI_DBG( "FFDC Validity Vector         :   0x%04x", i_pFfdcHdr->iv_sectionsValid );
        FAPI_DBG( "PPE Header Size              :   0x%02x", i_pFfdcHdr->iv_headerSize );
        FAPI_DBG( "PPE FFDC Section Size        :   0x%04x", REV_2_BYTE(i_pFfdcHdr->iv_sectionSize) );
        FAPI_DBG( "PPE Halt State               :   0x%02x", i_pFfdcHdr->iv_ppeHaltCondition );
        FAPI_DBG( "Dash Board Offset            :   0x%04x", REV_2_BYTE( i_pFfdcHdr->iv_dashBoardOffset ));
        FAPI_DBG( "SRAM Header Offset           :   0x%04x", REV_2_BYTE( i_pFfdcHdr->iv_sramHeaderOffset ));
        FAPI_DBG( "SPR Offset                   :   0x%04x", REV_2_BYTE( i_pFfdcHdr->iv_sprOffset ));
        FAPI_DBG( "Internal Register  Offset    :   0x%04x", REV_2_BYTE( i_pFfdcHdr->iv_intRegOffset ));
        FAPI_DBG( "Trace  Offset                :   0x%04x", REV_2_BYTE( i_pFfdcHdr->iv_offsetTraces ));
        FAPI_DBG( "================== PPE Header Ends ====================" );

        FAPI_DBG("<< updatePpeFfdcHeader" );
        return fapi2::FAPI2_RC_SUCCESS;
    }

//------------------------------------------------------------------------------

    void PlatPmComplex::setPmFfdcSectionValid ( void*    i_pHomerBuf,
                                                uint16_t i_pmFfdcSectionState,
                                                bool     i_valid )
    {
        FAPI_DBG ( ">> PlatPmComplex::setPmFfdcSectionValid 0x%02X Valid %d",
                   i_pmFfdcSectionState, i_valid );
        HomerFfdcRegion* l_pHomerFfdc = ( HomerFfdcRegion* )
             ((uint8_t*) i_pHomerBuf + FFDC_REGION_HOMER_BASE_OFFSET );

        uint16_t* l_pSectionsValid = &l_pHomerFfdc->iv_pmFfdcHdrRegion.iv_pmFfdcHdr.iv_sectionsValid;

        if (i_valid == true)
            *l_pSectionsValid |= htobe16 (i_pmFfdcSectionState);
        else
            *l_pSectionsValid &= htobe16 (~i_pmFfdcSectionState);

        FAPI_DBG ( "<<  PlatPmComplex::setPmFfdcSectionValid 0x%02X",
                   *l_pSectionsValid );
    }

//------------------------------------------------------------------------------

    fapi2::ReturnCode PlatPmComplex::readPpeHaltState (
                      const uint64_t  i_xirBaseAddress,
                       const uint8_t* i_pHomerOffset )
    {
        FAPI_DBG ( ">> PlatPmComplex::getPpeHaltState XIR Base: 0x%08llX",
                   i_xirBaseAddress );

        fapi2::ReturnCode l_rc;
        fapi2::buffer<uint64_t> l_data64;
        uint8_t l_ppeHaltState = PPE_HALT_COND_UNKNOWN;

        PpeFfdcHeader* l_pPpeFfdcHdr =  (PpeFfdcHeader*) i_pHomerOffset;

        // Read the PPE XIR pair for XSR+SPRG0
        l_rc = getScom ( iv_procChip,
                         (i_xirBaseAddress + PPE_XIRAMDBG),
                         l_data64 );

        if ( l_rc == fapi2::FAPI2_RC_SUCCESS )
        {
            if ( l_data64.getBit <PU_PPE_XIRAMDBG_XSR_HS>() )
            {   // Halt exists, get all bits 0:3
                l_data64.getBit <PU_PPE_XIRAMDBG_XSR_HS, 4>();
                l_ppeHaltState = static_cast<uint8_t> (l_data64());
            }
            else
            {   // PPE is not halted
                l_ppeHaltState = PPE_HALT_COND_NONE;
            }
        }
        else
        {
            FAPI_ERR ("::readPpeHaltState: Error reading PPE XIRAMDBG");
        }

       l_pPpeFfdcHdr->iv_ppeHaltCondition = l_ppeHaltState;

        FAPI_DBG ( "<< PlatPmComplex::getPpeHaltState: 0x%02X",
                   l_ppeHaltState );
        return fapi2::FAPI2_RC_SUCCESS;
    }

//------------------------------------------------------------------------------
    fapi2::ReturnCode PlatPmComplex::collectPpeState (
                      const uint64_t i_xirBaseAddress,
                      const uint8_t* i_pHomerOffset,
                      const PPE_DUMP_MODE i_mode )
    {
        FAPI_DBG (">> PlatPmComplex:collectPpeState");
        PpeFfdcLayout* l_pPpeFfdc = (PpeFfdcLayout*) (i_pHomerOffset);
        PPERegValue_t* l_pPpeRegVal = NULL;

        std::vector<PPERegValue_t> l_vSprs;
        std::vector<PPERegValue_t> l_vGprs;
        std::vector<PPERegValue_t> l_vXirs;

        FAPI_TRY ( p9_ppe_state (
                   iv_procChip,
                   i_xirBaseAddress,
                   i_mode,
                   l_vSprs,
                   l_vXirs,
                   l_vGprs) );

        l_pPpeRegVal = (PPERegValue_t*) &l_pPpeFfdc->iv_ppeXirReg[0];
        for ( auto& it : l_vXirs )
        {
            l_pPpeRegVal->number = it.number;
            l_pPpeRegVal->value = it.value;
            ++l_pPpeRegVal;
        }

        l_pPpeRegVal = (PPERegValue_t*) &l_pPpeFfdc->iv_ppeSpr[0];
        for ( auto& it : l_vSprs )
        {
            l_pPpeRegVal->number = it.number;
            l_pPpeRegVal->value = it.value;
            ++l_pPpeRegVal;
        }

        l_pPpeRegVal = (PPERegValue_t*) &l_pPpeFfdc->iv_ppeGprs[0];
        for ( auto& it : l_vGprs )
        {
            l_pPpeRegVal->number = it.number;
            l_pPpeRegVal->value = it.value;
            ++l_pPpeRegVal;
        }

    fapi_try_exit:
        FAPI_DBG ( "<< PlatPmComplex::collectPpeState XIRs:%d SPRs:%d GPRs:%d",
                   l_vXirs.size(), l_vSprs.size(), l_vGprs.size() );

       return fapi2::current_err;
    }


    //---------------------------------------------------------------------------------------------
    fapi2::ReturnCode PlatPmComplex::collectSramInfo( const fapi2::Target< fapi2::TARGET_TYPE_EX > & i_exTgt,
                                                      uint8_t * i_pSramData,
                                                      FfdcDataType i_dataType,
                                                      uint32_t i_sramLength )
    {
       FAPI_DBG(">> PlatPmComplex::collectSramInfo" );

       uint32_t l_rows          =   i_sramLength / sizeof(uint64_t);
       uint64_t * l_pSramBuf    =   (uint64_t *)(i_pSramData);
       uint32_t l_actualDoubleWord = 0;
       uint32_t l_sramAddress = 0;

       switch( i_dataType )
       {
            case IMAGE_HEADER:
                l_sramAddress = iv_imageHeaderBaseAddress;
                break;
            case DASH_BOARD_VAR:
                l_sramAddress = iv_globalBaseAddress;
                break;
            case TRACES:
                 l_sramAddress = iv_traceBufBaseAddress;
                break;
            default:
                FAPI_ERR("Bad FFDC Data type. Skipping 0x%d", (uint32_t)i_dataType );
                goto fapi_try_exit;
                break;
       }

       FAPI_INF( "CME Start Add 0x%08x Length 0x%08x", l_sramAddress, i_sramLength );

       //handle SRAM

       FAPI_TRY( p9_cme_sram_access( i_exTgt,
                                     l_sramAddress,
                                     l_rows,
                                     l_pSramBuf,
                                     l_actualDoubleWord ),
                  "HWP to access CME SRAM Failed" );

       #ifndef __HOSTBOOT_MODULE

       debugSramInfo( i_pSramData, i_sramLength );

       #endif

       fapi_try_exit:
       FAPI_DBG("<< PlatPmComplex::collectSramInfo" );
       return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------------------

    fapi2::ReturnCode PlatPmComplex::collectSramInfo( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > & i_procTgt,
                                                      uint8_t * i_pSramData,
                                                      FfdcDataType i_dataType,
                                                      uint32_t i_sramLength )
    {
       FAPI_DBG(">> PlatPmComplex::collectSramInfo" );

       uint32_t l_rows          =   i_sramLength / sizeof(uint64_t);
       uint64_t * l_pSramBuf    =   (uint64_t *)(i_pSramData);
       uint32_t l_actualDoubleWord = 0;
       uint32_t l_sramAddress = 0;

       switch( i_dataType )
       {
            case IMAGE_HEADER:
                l_sramAddress = iv_imageHeaderBaseAddress;
                break;
            case DASH_BOARD_VAR:
                l_sramAddress = iv_globalBaseAddress;
                break;
            case TRACES:
                 l_sramAddress = iv_traceBufBaseAddress;
                break;
            default:
                FAPI_ERR("Bad FFDC Data type. Skipping 0x%d", (uint32_t)i_dataType );
                goto fapi_try_exit;
                break;
       }

       //handle OCC SRAM

       FAPI_DBG("OCC SRAM Collection" );
       FAPI_TRY( p9_pm_ocb_indir_setup_linear( iv_procChip,     // Compiler error  work around
                                               p9ocb::OCB_CHAN0,
                                               p9ocb::OCB_TYPE_LINSTR,
                                               l_sramAddress ),
                 "HWP To Setup OCB Indirect Access Failed" );

       FAPI_TRY( p9_pm_ocb_indir_access ( iv_procChip,  //Compiler error workaround
                                          p9ocb::OCB_CHAN0,
                                          p9ocb::OCB_GET,
                                          l_rows,
                                          true,
                                          l_sramAddress,
                                          l_actualDoubleWord,
                                          l_pSramBuf ),
                 "HWP To Access OCC SRAM Failed" );

        FAPI_DBG("Actual Length Read from OCC  SRAM is 0x%016lx", ( l_actualDoubleWord * sizeof(uint64_t)) );

       #ifndef __HOSTBOOT_MODULE

       debugSramInfo( i_pSramData, i_sramLength );

       #endif

       fapi_try_exit:
       FAPI_DBG("<< PlatPmComplex::collectSramInfo" );
       return fapi2::current_err;
    }

    //---------------------------------------------------------------------------------------------

    fapi2::ReturnCode PlatPmComplex::updateFirFfdcHeader (
                                     uint8_t* i_pFfdcHdr,
                                     uint8_t  i_pos,
                                     bool     i_ffdcValid )
    {
        FAPI_DBG(">> PlatPmComplex::updateFirFfdcHeader: Pos %d", i_pos );

        FirFfdcHeader* l_FirFfdcHdr =  (FirFfdcHeader*) i_pFfdcHdr;
        l_FirFfdcHdr->iv_magicWord =  htobe32 (FFDC_FIR_MAGIC_NUM);
        l_FirFfdcHdr->iv_versionMajor = 1;
        l_FirFfdcHdr->iv_versionMinor = 0;
        l_FirFfdcHdr->iv_headerSize = htobe16 (sizeof(FirFfdcHeader));
        l_FirFfdcHdr->iv_sectionSize =  htobe16 (sizeof(FirFfdcRegion));

        if (i_pos < PM_FFDC_FIR_VALID_POS_MAX)
        {
            uint16_t l_validBit = PM_FFDC_FIR_VALID_POS_0 >> i_pos;

            if (i_ffdcValid)
            {
                l_FirFfdcHdr->iv_validityVector |= htobe16 (l_validBit);
            }
            else
            {
                l_FirFfdcHdr->iv_validityVector &= htobe16 (~l_validBit);
            }
        }
        else
        {
            FAPI_ERR ( "Bad Pos %d for FIR FFDC Validity Vector", i_pos );
        }

        FAPI_DBG("<< PlatPmComplex::updateFirFfdcHeader" );
        return fapi2::FAPI2_RC_SUCCESS;
    }

    //---------------------------------------------------------------------------------------------

extern "C"
{
    fapi2::ReturnCode p9_pm_recovery_ffdc_base (
           const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procChipTarget,
           void* i_pHomerImage )
    {
        FAPI_IMP(">> p9_pm_recovery_ffdc_base" );
        std::vector<PlatPmComplex*> l_pPlatList;

        // init all the platform FFDC headers
        l_pPlatList.push_back (new PlatPmComplex(i_procChipTarget));
        l_pPlatList.push_back (new PlatCme(i_procChipTarget));
        l_pPlatList.push_back (new PlatSgpe(i_procChipTarget));
        l_pPlatList.push_back (new PlatPgpe(i_procChipTarget));
        l_pPlatList.push_back (new PlatOcc(i_procChipTarget));
        l_pPlatList.push_back (new CppmRegs(i_procChipTarget));
        l_pPlatList.push_back (new QppmRegs(i_procChipTarget));

        FAPI_INF ("p9_pm_recovery_ffdc_base: Initializing PM FFDC sections");
        for ( auto& it : l_pPlatList )
        {
            FAPI_TRY ( it->init (i_pHomerImage),
                       "::init Failed to init plat %d",
                       it->getPlatId() );
        }

        // Grab FIRs and PPE Halt State in FFDC, before entering Reset Flow
        FAPI_INF ("p9_pm_recovery_ffdc_base: Collecting FIR & PPE Halt States");
        for ( auto& it : l_pPlatList )
        {
            FAPI_TRY ( it->collectFfdc (i_pHomerImage, (PPE_HALT_STATE | FIR_STATE)),
            "p9_pm_recovery_ffdc_base: Failed to collect FOR & PPE Halt State. Plat %d",
            it->getPlatId () );
        }

    fapi_try_exit:
        for ( auto& it : l_pPlatList )
            delete it;

        FAPI_IMP("<< p9_pm_recovery_ffdc_base" );
        return  fapi2::FAPI2_RC_SUCCESS;
    }
}


} //namespace p9_stop_recov_ffdc ends
