/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_qppm.C $ */
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
/// @file   p9_pm_recovery_ffdc_qppm.C
/// @brief  QPPM FFDC collection of PM complex
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

#include <p9_pm_recovery_ffdc_qppm.H>
#include <collect_reg_ffdc.H>
#include <p9_quad_scom_addresses.H>
#include <stddef.h>
#include <endian.h>

 namespace p9_stop_recov_ffdc
 {
    QppmRegs::QppmRegs( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt )
      : PlatPmComplex ( i_procChipTgt, PLAT_QPPM )
    { }

    //----------------------------------------------------------------------

    fapi2::ReturnCode QppmRegs::init ( void* i_pHomerBuf )
    {
        FAPI_DBG (">> QppmRegs::init" );

        FAPI_TRY ( collectFfdc( i_pHomerBuf, INIT),
                   "Failed To init QPPM REGS FFDC" );

    fapi_try_exit:
        FAPI_DBG ("<< QppmRegs::init" );
        return fapi2::current_err;
    }

    //----------------------------------------------------------------------

    void QppmRegs::initRegList()
    {
        std::vector < uint32_t> l_scomRegList;
        l_scomRegList.push_back( EQ_PPM_GPMMR_SCOM );
        l_scomRegList.push_back( EQ_PPM_SSHSRC );
        l_scomRegList.push_back( EQ_QPPM_DPLL_FREQ );
        PlatPmComplex::updateSummaryList( l_scomRegList );
    }

    //----------------------------------------------------------------------

    fapi2::ReturnCode QppmRegs::collectFfdc ( void*   i_pHomerBuf,
                                              uint8_t i_ffdcType )
    {
        FAPI_DBG(">> QppmRegs::collectFfdc");

        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        uint8_t* l_pFfdcLoc     =   NULL;
        auto l_quadList         =
            getProcChip().getChildren< fapi2::TARGET_TYPE_EQ > ( fapi2::TARGET_STATE_PRESENT );
        uint8_t l_quadPos    = 0;
        uint16_t l_ffdcValid = FFDC_SUMMARY_SUB_SEC_VALID;
        HomerFfdcRegion * l_pHomerFfdc =
                ( HomerFfdcRegion *)( (uint8_t *)i_pHomerBuf + FFDC_REGION_HOMER_BASE_OFFSET );

        for( auto quad : l_quadList )
        {

            FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS, quad, l_quadPos ),
                      "FAPI_ATTR_GET Failed To Read QUAD Position" );

            l_pFfdcLoc = &l_pHomerFfdc->iv_quadFfdc[l_quadPos].iv_quadQppmRegion[0];

            // On INIT, update the headers just as in case of not functional
            if (quad.isFunctional())
            {
                // Note: ( i_ffdcType & INIT ) is the default case
                if ( i_ffdcType & SCOM_REG )
                {
                    l_ffdcValid = FFDC_SUMMARY_SUB_SEC_VALID;
                    FAPI_INF("QPPM FFDC Pos %d ", l_quadPos);

                    l_rc = collectRegisterData <fapi2::TARGET_TYPE_EQ> (
                           quad,
                           l_pFfdcLoc + sizeof(PpmFfdcHeader),
                           static_cast<fapi2::HwpFfdcId>(fapi2::QPPM_FFDC_REGISTERS));

                    if ( l_rc )
                    {
                        l_ffdcValid = FFDC_SUMMARY_SUB_SEC_INVALID;
                    }
                }

            }

            FAPI_TRY( updateQppmFfdcHeader( l_pFfdcLoc, l_quadPos, l_ffdcValid),
                      "Failed To Update QPPM FFDC Header for quad 0x%0d", l_quadPos);

        }

        if( !( i_ffdcType & INIT ) )
        {
            generateSummary( i_pHomerBuf );
        }

    fapi_try_exit:
        logPmResetPhase (i_pHomerBuf);
        FAPI_DBG("<< QppmRegs::collectFfdc");
        return fapi2::current_err;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode QppmRegs::updateQppmFfdcHeader( uint8_t * i_pHomerBuf,
                                                      const uint8_t i_quadPos,
                                                      const uint16_t i_ffdcValid)
    {
        FAPI_DBG(">> updateQppmFfdcHeader" );

        PpmFfdcHeader * l_QppmFfdcHdr     =  (PpmFfdcHeader *) i_pHomerBuf ;
        l_QppmFfdcHdr->iv_ppmMagicWord    =  htobe32(FFDC_QPPM_MAGIC_NUM);
        l_QppmFfdcHdr->iv_versionMajor    =  1;
        l_QppmFfdcHdr->iv_versionMinor    =  0;
        l_QppmFfdcHdr->iv_Instance        =  i_quadPos;
        l_QppmFfdcHdr->iv_ppmHeaderSize   =  htobe16(sizeof(PpmFfdcHeader));
        l_QppmFfdcHdr->iv_sectionSize     =  htobe16(FFDC_QPPM_REGION_SIZE);
        l_QppmFfdcHdr->iv_ffdcValid       =  htobe16 (i_ffdcValid);

        FAPI_DBG("<< updateQppmFfdcHeader" );
        return fapi2::FAPI2_RC_SUCCESS;
    }

    //-----------------------------------------------------------------------

    fapi2::ReturnCode QppmRegs::generateSummary( void * i_pHomer )
    {
        HomerFfdcRegion * l_pHomerFfdc =
                ( HomerFfdcRegion *)( (uint8_t *)i_pHomer + FFDC_REGION_HOMER_BASE_OFFSET );
        uint8_t* l_pQppmFfdcLoc     = NULL;
        uint8_t * l_pQppmSummary    = NULL;
        PpmFfdcHeader * l_pQppmHdr  = NULL;
        uint32_t  l_regionSizeLimit = FFDC_QPPM_REGION_SIZE - sizeof( PpmFfdcHeader );
        initRegList();

        for( uint8_t l_ppmPos = 0; l_ppmPos < MAX_QUADS_PER_CHIP; l_ppmPos++ )
        {
            l_pQppmFfdcLoc  =  &l_pHomerFfdc->iv_quadFfdc[l_ppmPos].iv_quadQppmRegion[0];
            l_pQppmSummary  =  &l_pHomerFfdc->iv_ffdcSummaryRegion.iv_qpmmRegSummary[l_ppmPos][FFDC_SUMMARY_SEC_HDR_SIZE];
            l_pQppmHdr      = ( PpmFfdcHeader * ) &l_pHomerFfdc->iv_quadFfdc[l_ppmPos].iv_quadQppmRegion[0];
            FfdcSummSubSectHdr * l_pQppmSummaryHdr
                            =  (FfdcSummSubSectHdr *)&l_pHomerFfdc->iv_ffdcSummaryRegion.iv_qpmmRegSummary[l_ppmPos][0];
            l_pQppmSummaryHdr->iv_subSectnId    =   PLAT_QPPM;
            l_pQppmSummaryHdr->iv_majorNum      =   1;
            l_pQppmSummaryHdr->iv_minorNum      =   0;
            l_pQppmSummaryHdr->iv_secValid      =   htobe16(l_pQppmHdr->iv_ffdcValid);

            if( !l_pQppmSummaryHdr->iv_secValid )
            {
                continue;
            }

            PlatPmComplex::extractScomSummaryReg( l_pQppmFfdcLoc + sizeof( PpmFfdcHeader ),
                                                  l_regionSizeLimit, l_pQppmSummary );
        }

        return fapi2::FAPI2_RC_SUCCESS;
    }

    //-----------------------------------------------------------------------

extern "C"
{
    fapi2::ReturnCode p9_pm_recovery_ffdc_qppm( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP >& i_procChip, void * i_pFfdcBuf )
    {
        FAPI_IMP(">> p9_pm_recovery_ffdc_qppm" );

        QppmRegs l_qppmFfdc( i_procChip );
        FAPI_TRY( l_qppmFfdc.collectFfdc( i_pFfdcBuf, SCOM_REG ),
                  "Failed To Collect QPPM FFDC" );

        fapi_try_exit:
        FAPI_IMP("<< p9_pm_recovery_ffdc_qppm" );
        return fapi2::current_err;
    }

}

 }//namespace p9_stop_recov_ffdc ends
