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
#include <endian.h>
#include <stddef.h>

 namespace p9_stop_recov_ffdc
 {
    PlatPmComplex::PlatPmComplex( const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > i_procChipTgt,
                                  uint32_t i_imageHdrBaseAddr, uint32_t i_traceBufBaseAddr,
                                  uint32_t i_globalBaseAddr, PmComplexPlatId i_plat )
      : iv_procChip( i_procChipTgt ),
        iv_imageHeaderBaseAddress( i_imageHdrBaseAddr ),
        iv_traceBufBaseAddress( i_traceBufBaseAddr ),
        iv_globalBaseAddress( i_globalBaseAddr ),
        iv_plat( i_plat )
    { }

    //---------------------------------------------------------------------------------------------

    fapi2::ReturnCode PlatPmComplex::collectFfdc( void * i_pHomerBuf )
    {
        FAPI_DBG("<< PlatPmComplex::collectFfdc");

        FAPI_DBG("<< PlatPmComplex::collectFfdc");
        return fapi2::FAPI2_RC_SUCCESS;;
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

    fapi2::ReturnCode PlatPmComplex::updatePpeFfdcHeader( PpeFfdcHeader * i_pFfdcHdr,
                                                          uint8_t i_ffdcValid, uint8_t i_haltState )
    {
        FAPI_DBG(">> updatePpeFfdcHeader" );

        i_pFfdcHdr->iv_headerSize        =  sizeof( PpeFfdcHeader );
        i_pFfdcHdr->iv_sectionSize       =  htobe16( sizeof( PpeFfdcLayout ) );
        i_pFfdcHdr->iv_ffdcValid         =  i_ffdcValid;
        i_pFfdcHdr->iv_ppeHaltCondition  =  i_haltState;
        i_pFfdcHdr->iv_dashBoardOffset   =  htobe16( offsetof( struct PpeFfdcLayout, iv_ppeGlobals[0]));
        i_pFfdcHdr->iv_sramHeaderOffset  =  htobe16( offsetof( struct PpeFfdcLayout, iv_ppeImageHeader[0]));
        i_pFfdcHdr->iv_sprOffset         =  htobe16( offsetof( struct PpeFfdcLayout, iv_ppeXirReg[0]));
        i_pFfdcHdr->iv_intRegOffset      =  htobe16( offsetof( struct PpeFfdcLayout, iv_ppeInternalReg[0]));
        i_pFfdcHdr->iv_offsetTraces      =  htobe16( offsetof( struct PpeFfdcLayout, iv_ppeTraces[0] ));

        FAPI_DBG( "================== PPE Header ==========================" );
        FAPI_DBG( "FFDC Validity Vector         :   0x%02x", i_pFfdcHdr->iv_ffdcValid );
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
 }//namespace p9_stop_recov_ffdc ends
