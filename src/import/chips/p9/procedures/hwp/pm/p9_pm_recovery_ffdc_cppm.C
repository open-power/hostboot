/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_cppm.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

#include <p9_pm_recovery_ffdc_cppm.H>
#include <collect_reg_ffdc.H>
#include <stddef.h>
#include <endian.h>

 namespace p9_stop_recov_ffdc
 {
    CppmRegs::CppmRegs( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt )
      : PlatPmComplex( i_procChipTgt,0,0,0,PLAT_PPM)
    { }

    //----------------------------------------------------------------------

    fapi2::ReturnCode CppmRegs::collectRegFfdc( void * i_pHomerBuf )
    {
        FAPI_DBG(">> CppmRegs::collectRegFfdc");
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        auto l_quadList =
            getProcChip().getChildren< fapi2::TARGET_TYPE_EQ > ( fapi2::TARGET_STATE_PRESENT );
        uint8_t l_quadPos = 0;
        uint8_t l_corePos   = 0;
        uint8_t *l_pFfdcLoc = NULL;
        uint8_t l_cppmFfdcValid = 0;
        uint8_t l_quadFfdcValid = 0;
        HomerFfdcRegion * l_pHomerFfdc =
                ( HomerFfdcRegion *)( (uint8_t *)i_pHomerBuf + FFDC_REGION_HOMER_BASE_OFFSET );

        for( auto quad : l_quadList )
        {
            l_cppmFfdcValid = 0;
            l_quadFfdcValid = 0;
            FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, quad, l_quadPos),
                                  "FAPI_ATTR_GET Failed To Read QUAD Position" );
            if( quad.isFunctional() )
            {
                l_quadFfdcValid = 1;
                auto l_exList =
                        quad.getChildren< fapi2::TARGET_TYPE_EX > ( fapi2::TARGET_STATE_PRESENT );

                for( auto ex : l_exList )
                {
                    auto l_coreList = 
                         ex.getChildren< fapi2::TARGET_TYPE_CORE > ( fapi2::TARGET_STATE_PRESENT );

                    for ( auto core : l_coreList )
                    {
                        FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, core, l_corePos ),
                                  "FAPI_ATTR_GET Failed To Read CORE Position" );

                        l_pFfdcLoc = &l_pHomerFfdc->iv_quadFfdc[l_quadPos].iv_quadCppmRegion[l_corePos][0];

                        if( core.isFunctional() )
                        {
                            l_cppmFfdcValid = 1;

                            FAPI_INF("CPPM FFDC Pos %d ", l_corePos);

                            l_rc = collectRegisterData <fapi2::TARGET_TYPE_CORE> (core,
                                                            l_pFfdcLoc + sizeof (PpmFfdcHeader),
                                                            fapi2::CPPM_FFDC_REGISTERS);
                            if (l_rc)
                            {
                                l_cppmFfdcValid = 0;
                            }
                        }


                        FAPI_TRY( updateCppmFfdcHeader( l_pFfdcLoc, l_corePos, l_cppmFfdcValid),
                                  "Failed To Update CPPM FFDC Header for CORE 0x%0d", l_corePos );
                    }
                }
            }
            FAPI_TRY( updateQuadFfdcHeader( l_pFfdcLoc,l_quadPos, l_quadFfdcValid),
                               "Failed To Update CPPM FFDC Header for CORE 0x%0d", l_corePos );
        }

        fapi_try_exit:
        FAPI_DBG("<< CppmRegs::collectRegFfdc");
        return fapi2::current_err;
    }

    fapi2::ReturnCode CppmRegs::updateCppmFfdcHeader( uint8_t * i_pHomerBuf, 
                                                      const  uint8_t i_corePos, 
                                                      const uint8_t i_ffdcValid)
    {
        FAPI_DBG(">> updateCppmFfdcHeader" );

        PpmFfdcHeader * l_CppmFfdcHdr       =   (PpmFfdcHeader *) i_pHomerBuf ;
        l_CppmFfdcHdr->iv_ppmMagicWord      =  htobe32(FFDC_CPPM_MAGIC_NUM);
        l_CppmFfdcHdr->iv_Instance          =  i_corePos;
        l_CppmFfdcHdr->iv_ppmHeaderSize     =  sizeof(PpmFfdcHeader);
        l_CppmFfdcHdr->iv_sectionSize       =  FFDC_CPPM_REGISTERS_SIZE;
        l_CppmFfdcHdr->iv_ffdcValid         =  i_ffdcValid;

        FAPI_DBG("<< updateCppmFfdcHeader" );
        return fapi2::FAPI2_RC_SUCCESS;
    }
    //-----------------------------------------------------------------------
    //
    fapi2::ReturnCode CppmRegs::updateQuadFfdcHeader( uint8_t * i_pHomerBuf, 
                                                      const  uint8_t i_eqPos, 
                                                      const uint8_t i_ffdcValid)
    {
        FAPI_DBG(">> updateQuadFfdcHeader" );

        QuadFfdcHeader* l_QuadFfdcHdr       =  (QuadFfdcHeader*) i_pHomerBuf ;
        l_QuadFfdcHdr->iv_quadMagicWord     =  htobe32(FFDC_QUAD_MAGIC_NUM);
        l_QuadFfdcHdr->iv_quadInstance      =  i_eqPos;
        l_QuadFfdcHdr->iv_quadHeaderSize    =  sizeof(QuadFfdcHeader);
        l_QuadFfdcHdr->iv_sectionSize       =  sizeof(HomerQuadFfdcRegion);
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
        l_QuadFfdcHdr->iv_ffdcValid         =  i_ffdcValid;

        FAPI_DBG("<< updateQuadFfdcHeader" );
        return fapi2::FAPI2_RC_SUCCESS;
    }


extern "C"
{
    fapi2::ReturnCode p9_pm_recovery_ffdc_cppm( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP >& i_procChip, void * i_pFfdcBuf )
    {
        FAPI_IMP(">> p9_pm_recovery_ffdc_cppm" );
        CppmRegs l_cppmFfdc( i_procChip );
        FAPI_TRY( l_cppmFfdc.collectRegFfdc( i_pFfdcBuf ),
                  "Failed To Collect CPPM FFDC" );

        fapi_try_exit:
        FAPI_IMP("<< p9_pm_recovery_ffdc_cppm" );
        return fapi2::current_err;
    }

}

 }//namespace p9_stop_recov_ffdc ends
