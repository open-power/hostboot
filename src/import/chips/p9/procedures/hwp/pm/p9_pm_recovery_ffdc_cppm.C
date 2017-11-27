/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_cppm.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
/// @file   p9_pm_recovery_ffdc_cppm.C
/// @brief  PPM FFDC collection of PM complex
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    Hostboot
//
// *INDENT-OFF*
//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------

#include <p9_quad_scom_addresses.H>
#include <p9_pm_recovery_ffdc_cppm.H>
#include <collect_reg_ffdc.H>
#include <stddef.h>
#include <endian.h>

 namespace p9_stop_recov_ffdc
 {
    CppmRegs::CppmRegs( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt )
      : PlatPmComplex ( i_procChipTgt, PLAT_CPPM )
    { }

    //----------------------------------------------------------------------

    void CppmRegs::initRegList()
    {
        std::vector < uint32_t> l_scomRegList;
        l_scomRegList.push_back( C_PPM_SSHSRC );
        l_scomRegList.push_back( C_PPM_VDMCR );
        PlatPmComplex::updateSummaryList( l_scomRegList );
    }

    //----------------------------------------------------------------------

    fapi2::ReturnCode CppmRegs::init ( void* i_pHomerBuf )
    {
        FAPI_DBG (">> CppmRegs::init" );
        FAPI_TRY ( collectFfdc( i_pHomerBuf, INIT),
                   "Failed To Init CPPM REGS FFDC" );

    fapi_try_exit:
        FAPI_DBG ("<< CppmRegs::init" );
        return fapi2::current_err;
    }

    //----------------------------------------------------------------------

    fapi2::ReturnCode CppmRegs::collectFfdc( void*   i_pHomerBuf,
                                             uint8_t i_ffdcType )
    {
        FAPI_DBG(">> CppmRegs::collectFfdc");
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        uint8_t l_quadPos = 0;
        uint8_t l_corePos   = 0;
        uint8_t* l_pCppmFfdcLoc = NULL;
        uint8_t* l_pQuadFfdcLoc = NULL;
        uint16_t l_cppmFfdcValid = 0;
        uint16_t l_quadFfdcValid = 0;

        HomerFfdcRegion * l_pHomerFfdc =
                ( HomerFfdcRegion *)( (uint8_t *)i_pHomerBuf + FFDC_REGION_HOMER_BASE_OFFSET );

        auto l_quadList = getProcChip().getChildren<fapi2::TARGET_TYPE_EQ> (fapi2::TARGET_STATE_PRESENT);

        for (auto& quad : l_quadList)
        {
            // @TODO via RTC 153978: define bitsets for quad sub-section validity
            l_quadFfdcValid = 0;
            FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, quad, l_quadPos),
                                  "FAPI_ATTR_GET Failed To Read QUAD Position" );

            l_pQuadFfdcLoc = &l_pHomerFfdc->iv_quadFfdc[l_quadPos].iv_quadFfdcHeader[0];

            // @note: INIT applies to all present units, and is handled as default flow
            // @note: CPPM headers for EQs that are not functionals will not be initialized
            if (quad.isFunctional())
            {
                l_quadFfdcValid = 1;
                auto l_coreList =
                     quad.getChildren< fapi2::TARGET_TYPE_CORE > ( fapi2::TARGET_STATE_PRESENT );

                for (auto& core : l_coreList)
                {
                    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, core, l_corePos ),
                              "FAPI_ATTR_GET Failed To Read CORE Position" );
                    l_cppmFfdcValid = 0;

                    l_pCppmFfdcLoc = &l_pHomerFfdc->iv_quadFfdc[l_quadPos].iv_quadCppmRegion[l_corePos%MAX_CORES_PER_QUAD][0];

                    // Note: ( i_ffdcType & INIT ) is the default case, for all present cores
                    if( core.isFunctional() )
                    {
                        FAPI_INF("CPPM FFDC: Quad#%d Core#%d ", l_quadPos, (l_corePos%MAX_CORES_PER_QUAD));

                        if (i_ffdcType & SCOM_REG)
                        {
                            l_rc = collectRegisterData <fapi2::TARGET_TYPE_CORE> (core,
                                                            l_pCppmFfdcLoc + sizeof (PpmFfdcHeader),
                                                            fapi2::CPPM_FFDC_REGISTERS);
                            if (l_rc == fapi2::FAPI2_RC_SUCCESS)
                            {
                                l_cppmFfdcValid = 1;
                            }
                        }
                    }

                    FAPI_TRY( updateCppmFfdcHeader( l_pCppmFfdcLoc, l_corePos, l_cppmFfdcValid),
                              "Failed To Update CPPM FFDC Header for QUAD#%d CORE#%d", l_quadPos, (l_corePos%MAX_CORES_PER_QUAD));
                }
            }
            FAPI_TRY( updateQuadFfdcHeader( l_pQuadFfdcLoc,l_quadPos, l_quadFfdcValid),
                               "Failed To Update Quad FFDC Header for EQ 0x%0d", l_quadPos );

            setPmFfdcSectionValid ( i_pHomerBuf, (PM_FFDC_QUAD0_VALID << l_quadPos), l_quadFfdcValid);

        }

        if( !(i_ffdcType & INIT) )
        {
            generateSummary( i_pHomerBuf );
        }

    fapi_try_exit:
        FAPI_DBG("<< CppmRegs::collectFfdc");
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode CppmRegs::updateCppmFfdcHeader( uint8_t * i_pHomerBuf,
                                                      const uint8_t i_corePos,
                                                      const uint16_t i_ffdcValid)
    {
        FAPI_DBG(">> updateCppmFfdcHeader" );

        PpmFfdcHeader * l_CppmFfdcHdr       =   (PpmFfdcHeader *) i_pHomerBuf ;
        l_CppmFfdcHdr->iv_ppmMagicWord      =  htobe32(FFDC_CPPM_MAGIC_NUM);
        l_CppmFfdcHdr->iv_versionMajor      =  1;
        l_CppmFfdcHdr->iv_versionMinor      =  0;
        l_CppmFfdcHdr->iv_Instance          =  i_corePos; // CHIP_UNIT_POS
        l_CppmFfdcHdr->iv_ppmHeaderSize     =  htobe16 (sizeof(PpmFfdcHeader));
        l_CppmFfdcHdr->iv_sectionSize       =  htobe16 (FFDC_CPPM_REGION_SIZE);
        l_CppmFfdcHdr->iv_ffdcValid         =  htobe16 (i_ffdcValid);

        FAPI_DBG("<< updateCppmFfdcHeader" );
        return fapi2::FAPI2_RC_SUCCESS;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode CppmRegs::updateQuadFfdcHeader( uint8_t* i_pHomerBuf,
                                                      const uint8_t i_eqPos,
                                                      const uint16_t i_ffdcValid)
    {
        FAPI_DBG(">> updateQuadFfdcHeader" );

        QuadFfdcHeader* l_QuadFfdcHdr       =  (QuadFfdcHeader*) i_pHomerBuf ;
        l_QuadFfdcHdr->iv_quadMagicWord     =  htobe32(FFDC_QUAD_MAGIC_NUM);
        l_QuadFfdcHdr->iv_versionMajor      =  1;
        l_QuadFfdcHdr->iv_versionMinor      =  0;
        l_QuadFfdcHdr->iv_quadInstance      =  i_eqPos;
        l_QuadFfdcHdr->iv_quadHeaderSize    =  htobe16 (sizeof(QuadFfdcHeader));
        l_QuadFfdcHdr->iv_sectionSize       =  htobe16 (sizeof(HomerQuadFfdcRegion));
        l_QuadFfdcHdr->iv_offsetCppm0       =  htobe16(offsetof (struct HomerQuadFfdcRegion,
                                                                iv_quadCppmRegion[0][0]));
        l_QuadFfdcHdr->iv_offsetCppm1       =  htobe16(offsetof (struct HomerQuadFfdcRegion,
                                                                iv_quadCppmRegion[1][0]));
        l_QuadFfdcHdr->iv_offsetCppm2       =  htobe16(offsetof (struct HomerQuadFfdcRegion,
                                                                iv_quadCppmRegion[2][0]));
        l_QuadFfdcHdr->iv_offsetCppm3       =  htobe16(offsetof (struct HomerQuadFfdcRegion,
                                                                iv_quadCppmRegion[3][0]));
        l_QuadFfdcHdr->iv_offsetCme0        =  htobe16(offsetof(struct HomerQuadFfdcRegion,
                                                                iv_quadCmeBlock[0][0]));
        l_QuadFfdcHdr->iv_offsetCme1        =  htobe16(offsetof(struct HomerQuadFfdcRegion,
                                                                iv_quadCmeBlock[1][0]));
        l_QuadFfdcHdr->iv_offsetQppm        =  htobe16(offsetof(struct HomerQuadFfdcRegion,
                                                                iv_quadQppmRegion[0]));
        l_QuadFfdcHdr->iv_sectionsValid     =  htobe16 (i_ffdcValid);

        FAPI_DBG("<< updateQuadFfdcHeader" );
        return fapi2::FAPI2_RC_SUCCESS;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode CppmRegs::generateSummary( void * i_pHomer )
    {
        HomerFfdcRegion * l_pHomerFfdc =
                ( HomerFfdcRegion *)( (uint8_t *)i_pHomer + FFDC_REGION_HOMER_BASE_OFFSET );
        uint8_t* l_pCppmFfdcLoc    = NULL;
        PpmFfdcHeader * l_pCppmHdr = NULL;
        uint8_t * l_pCppmSummary   = NULL;
        uint8_t l_quadPos          = 0;
        uint8_t l_relCorePos       = 0;

        initRegList();
        uint32_t l_sizeLimit = FFDC_CPPM_REGION_SIZE - sizeof( PpmFfdcHeader );

        for( uint8_t l_ppmPos = 0; l_ppmPos < MAX_CORES_PER_CHIP; l_ppmPos++ )
        {
            l_relCorePos    =   l_ppmPos % MAX_CORES_PER_QUAD;
            l_quadPos       =   l_ppmPos >> 2;
            l_pCppmFfdcLoc  =
                &l_pHomerFfdc->iv_quadFfdc[l_quadPos].iv_quadCppmRegion[l_relCorePos][0];
            l_pCppmSummary  =   &l_pHomerFfdc->iv_ffdcSummaryRegion.iv_cpmmRegSummary[l_ppmPos][FFDC_SUMMARY_SEC_HDR_SIZE];
            l_pCppmHdr      =   ( PpmFfdcHeader *) &l_pHomerFfdc->iv_quadFfdc[l_quadPos].iv_quadCppmRegion[l_relCorePos][0];
            FfdcSummSubSectHdr * l_pCppmSummaryHdr   =
                        (FfdcSummSubSectHdr *)&l_pHomerFfdc->iv_ffdcSummaryRegion.iv_cpmmRegSummary[l_ppmPos][0];
            l_pCppmSummaryHdr->iv_subSectnId    =   PLAT_CPPM;
            l_pCppmSummaryHdr->iv_majorNum      =   1;
            l_pCppmSummaryHdr->iv_minorNum      =   0;
            l_pCppmSummaryHdr->iv_secValid      =   htobe16( l_pCppmHdr->iv_ffdcValid );

            if( !l_pCppmSummaryHdr->iv_secValid )
            {
                continue;
            }

            PlatPmComplex::extractScomSummaryReg( l_pCppmFfdcLoc + sizeof(PpmFfdcHeader),
                                                  l_sizeLimit, l_pCppmSummary );
        }

        return fapi2::FAPI2_RC_SUCCESS;
    }

    //-----------------------------------------------------------------------

extern "C"
{
    fapi2::ReturnCode p9_pm_recovery_ffdc_cppm( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP >& i_procChip, void * i_pFfdcBuf )
    {
        FAPI_IMP(">> p9_pm_recovery_ffdc_cppm" );
        CppmRegs l_cppmFfdc( i_procChip );
        FAPI_TRY( l_cppmFfdc.collectFfdc( i_pFfdcBuf, SCOM_REG ),
                  "Failed To Collect CPPM FFDC" );

        fapi_try_exit:
        FAPI_IMP("<< p9_pm_recovery_ffdc_cppm" );
        return fapi2::current_err;
    }

}

 }//namespace p9_stop_recov_ffdc ends
