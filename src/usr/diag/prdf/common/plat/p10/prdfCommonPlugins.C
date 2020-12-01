/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfCommonPlugins.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/** @file  prdfCommonPlugins.C
 *  @brief Contains plugin code that is common for multiple chiplets
 */

#include <prdfGlobal.H>
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfPlatServices.H>
#include <UtilHash.H> // for Util::hashString
#include <xspprdService.h>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace CommonPlugins
{


/**
 * @brief   When not in MNFG mode, clear the service call flag so that
 *          thresholding will still be done, but no visible error log committed.
 * @param   i_chip EX chip
 * @param   i_sc   Step code data struct
 * @returns SUCCESS always
 */
int32_t ClearServiceCallFlag( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    if ( i_sc.service_data->IsAtThreshold() && !mfgMode() &&
         (CHECK_STOP != i_sc.service_data->getPrimaryAttnType()) &&
         (UNIT_CS    != i_sc.service_data->getSecondaryAttnType()) )
    {
        i_sc.service_data->clearServiceCall();
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( explorer_ocmb,  CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p10_proc,       CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p10_mcc,        CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p10_phb,        CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p10_eq,         CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p10_core,       CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p10_pec,        CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p10_pauc,       CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p10_omic,       CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p10_pau,        CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p10_iohs,       CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p10_nmmu,       CommonPlugins, ClearServiceCallFlag );
PRDF_PLUGIN_DEFINE_NS( p10_mc,         CommonPlugins, ClearServiceCallFlag );

/**
 * @brief   Clear the service call flag (field and MNFG) so that thresholding
 *          will still be done, but no visible error log committed.
 * @param   i_chip PROC
 * @param   i_sc   Step code data struct
 * @returns SUCCESS always
 */
int32_t ClearServiceCallFlag_mnfgInfo( ExtensibleChip * i_chip,
                                       STEP_CODE_DATA_STRUCT & i_sc )
{
    if (i_sc.service_data->IsAtThreshold() &&
        (CHECK_STOP != i_sc.service_data->getPrimaryAttnType()))
    {
        i_sc.service_data->clearServiceCall();
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS(p10_proc, CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(p10_eq,   CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(p10_core, CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(p10_pec,  CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(p10_phb,  CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(p10_pauc, CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(p10_pau,  CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(p10_iohs, CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(p10_nmmu, CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(p10_mc,   CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(p10_mcc,  CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(p10_omic, CommonPlugins, ClearServiceCallFlag_mnfgInfo);
PRDF_PLUGIN_DEFINE_NS(explorer_ocmb, CommonPlugins, ClearServiceCallFlag_mnfgInfo);

/**
 * @brief   Analyze for unit checkstops on this target.
 * @param   i_chip The chip.
 * @param   io_sc  Step code data struct
 * @returns SUCCESS always
 */
int32_t analyzeUcs( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    return i_chip->Analyze( io_sc, UNIT_CS );
}
PRDF_PLUGIN_DEFINE_NS(p10_mc, CommonPlugins, analyzeUcs);

/**
 * @brief  Plugin for CRC related error side effect handling
 * @param  i_chip   An OMIC chip.
 * @param  io_sc    The step code data struct.
 * @param  i_omiPos OMI position relative to the OMIC/MCC (0:1)
 * @return SUCCESS if a root cause is found, else PRD_SCAN_COMM_REGISTER_ZERO.
 */
int32_t CrcSideEffect( ExtensibleChip * i_chip,
                       STEP_CODE_DATA_STRUCT & io_sc,
                       uint8_t i_omiPos )
{
    #define PRDF_FUNC "[CrcSideEffect] "

    int32_t o_rc = PRD_SCAN_COMM_REGISTER_ZERO;

    do
    {
        // Get the OMIC position relative to the PAUC. This should
        // correspond to the relevant OMI PHY, either 0 or 1.
        uint8_t omicPos = i_chip->getPos() % MAX_OMIC_PER_PAUC; // 0:1

        // Get the connected PAUC
        ExtensibleChip * pauc = getConnectedParent( i_chip, TYPE_PAUC );

        // read the PAU_PHY_FIR
        SCAN_COMM_REGISTER_CLASS * pau_phy = pauc->getRegister( "PAU_PHY_FIR" );
        if ( SUCCESS != pau_phy->Read() ) break;

        // Collect the PAU_PHY_FIR for FFDC
        pauc->CaptureErrorData( io_sc.service_data->GetCaptureData(),
                                Util::hashString("crcRootCause") );

        // Get the OMI, OCMB, and OMIC targets for possible callouts.
        TargetHandle_t omicTrgt = i_chip->getTrgt();
        TargetHandle_t omiTrgt = getConnectedChild(omicTrgt, TYPE_OMI,i_omiPos);
        if ( nullptr == omiTrgt )
        {
            PRDF_ERR(PRDF_FUNC "Unable to get connected child OMI at pos %d "
                     "from parent target 0x%08x", i_omiPos, getHuid(omicTrgt));
            break;
        }

        TargetHandle_t ocmbTrgt = getConnectedChild(omiTrgt, TYPE_OCMB_CHIP, 0);
        if ( nullptr == ocmbTrgt )
        {
            PRDF_ERR( PRDF_FUNC "Unable to get connected child OCMB from "
                      "parent OMI 0x%08x", getHuid(omiTrgt) );
            break;
        }

        // Read the related possible root causes.
        // NOTE: we want to check to see if these bits are on, even if they
        // are masked off, so there is no need to check the PAU_PHY_FIR_MASK.

        // OMI PHY 0 bits: 2, 6
        if ( 0 == omicPos )
        {
            if ( pau_phy->IsBitSet(2) || pau_phy->IsBitSet(6) )
            {
                // switch callout to OMIC high, OMI plus OCMB low
                io_sc.service_data->SetCallout( omicTrgt, MRU_HIGH );
                calloutBus( io_sc, omiTrgt, ocmbTrgt, HWAS::OMI_BUS_TYPE );
                o_rc = SUCCESS;
                break;
            }
        }
        // OMI PHY 1 bits: 3, 7
        if ( 1 == omicPos )
        {
            if ( pau_phy->IsBitSet(3) || pau_phy->IsBitSet(7) )
            {
                // switch callout to OMIC high, OMI plus OCMB
                io_sc.service_data->SetCallout( omicTrgt, MRU_HIGH );
                calloutBus( io_sc, omiTrgt, ocmbTrgt, HWAS::OMI_BUS_TYPE );
                o_rc = SUCCESS;
                break;
            }
        }
        // Bits relevant to both OMI PHYs: 9,10,11,12,13,14,19,22,23
        if ( pau_phy->IsBitSet(9) || pau_phy->IsBitSet(10) ||
             pau_phy->IsBitSet(19) )
        {
            // switch callout to PAUC high, OMI plus OCMB
            io_sc.service_data->SetCallout( pauc->getTrgt(), MRU_HIGH );
            calloutBus( io_sc, omiTrgt, ocmbTrgt, HWAS::OMI_BUS_TYPE );
            o_rc = SUCCESS;
        }
        else if ( pau_phy->IsBitSet(11) || pau_phy->IsBitSet(13) ||
                  pau_phy->IsBitSet(14) )
        {
            // switch callout to PAUC high, level 2, OMI plus OCMB
            io_sc.service_data->SetCallout( pauc->getTrgt(), MRU_HIGH );
            io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_MED );
            calloutBus( io_sc, omiTrgt, ocmbTrgt, HWAS::OMI_BUS_TYPE );
            o_rc = SUCCESS;
        }
        else if ( pau_phy->IsBitSet(12) || pau_phy->IsBitSet(22) ||
                  pau_phy->IsBitSet(23))
        {
            // switch callout to level2 high, OMI plus OCMB
            io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_HIGH );
            calloutBus( io_sc, omiTrgt, ocmbTrgt, HWAS::OMI_BUS_TYPE );
            o_rc = SUCCESS;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

#define CRC_SIDE_EFFECT_PLUGIN( POS ) \
int32_t CrcSideEffect_##POS( ExtensibleChip * i_chip, \
                             STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return CrcSideEffect( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE_NS( p10_omic, CommonPlugins, CrcSideEffect_##POS );
CRC_SIDE_EFFECT_PLUGIN( 0 );
CRC_SIDE_EFFECT_PLUGIN( 1 );

/**
 * @brief  Plugin for CRC related error side effect handling
 * @param  i_chip   An MCC chip.
 * @param  io_sc    The step code data struct.
 * @param  i_omiPos OMI position relative to the OMIC/MCC (0:1)
 * @return SUCCESS if a root cause is found, else PRD_SCAN_COMM_REGISTER_ZERO.
 */
int32_t CrcSideEffect_Mcc( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc, uint8_t i_omiPos )
{
    TargetHandle_t omiTrgt = getConnectedChild( i_chip->getTrgt(), TYPE_OMI,
                                                i_omiPos );
    TargetHandle_t omicTrgt = getConnectedParent( omiTrgt, TYPE_OMIC );
    ExtensibleChip * omic = (ExtensibleChip *)systemPtr->GetChip(omicTrgt);

    return CrcSideEffect( omic, io_sc, i_omiPos );
}

#define CRC_SIDE_EFFECT_MCC_PLUGIN( POS ) \
int32_t CrcSideEffect_Mcc_##POS( ExtensibleChip * i_chip, \
                                 STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return CrcSideEffect_Mcc( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE_NS( p10_mcc, CommonPlugins, CrcSideEffect_Mcc_##POS );
CRC_SIDE_EFFECT_MCC_PLUGIN( 0 );
CRC_SIDE_EFFECT_MCC_PLUGIN( 1 );

/**
 * @brief  Plugin for CRC related error side effect handling
 * @param  i_chip   An OCMB chip.
 * @param  io_sc    The step code data struct.
 * @return SUCCESS if a root cause is found, else PRD_SCAN_COMM_REGISTER_ZERO.
 */
int32_t CrcSideEffect_Ocmb( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & io_sc )
{
    TargetHandle_t omiTrgt = getConnectedParent( i_chip->getTrgt(), TYPE_OMI );
    uint8_t omiPos = getTargetPosition(omiTrgt) % MAX_OMI_PER_MCC; // 0:1

    TargetHandle_t omicTrgt = getConnectedParent( omiTrgt, TYPE_OMIC );
    ExtensibleChip * omic = (ExtensibleChip *)systemPtr->GetChip(omicTrgt);

    return CrcSideEffect( omic, io_sc, omiPos );
}
PRDF_PLUGIN_DEFINE_NS(explorer_ocmb, CommonPlugins, CrcSideEffect_Ocmb);

} // namespace CommonPlugins ends

}// namespace PRDF ends

