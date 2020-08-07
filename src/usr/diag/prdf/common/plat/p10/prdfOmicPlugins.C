/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfOmicPlugins.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

// Framework includes
#include <iipServiceDataCollector.h>
#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal_common.H>
#include <prdfPluginMap.H>
#include <UtilHash.H>

// Platform includes
#include <prdfMemUtils.H>
#include <prdfPlatServices.H>

#include <stdio.h>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p10_omic
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Analysis code that is called before the main analyze() function.
 * @param  i_chip     An OMIC chip.
 * @param  io_sc      The step code data struct.
 * @param  o_analyzed True if analysis is done on this chip, false otherwise.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t PreAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                     bool & o_analyzed )
{
    // Check for a channel failure before analyzing this chip.
    o_analyzed = MemUtils::analyzeChnlFail<TYPE_OMIC>( i_chip, io_sc );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p10_omic, PreAnalysis );

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip An OMIC chip.
 * @param  io_sc  The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    // If there was a channel failure some cleanup is required to ensure
    // there are no more attentions from this channel.
    MemUtils::cleanupChnlFail<TYPE_OMIC>( i_chip, io_sc );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p10_omic, PostAnalysis );

//##############################################################################
//
//                               OMIDLFIR
//
//##############################################################################

/**
 * @brief  OMIDLFIR[0|20|40] - OMI-DL Fatal Error
 * @param  i_chip An OMIC chip.
 * @param  io_sc  The step code data struct.
 * @param  i_dl   The DL relative to the OMIC.
 * @return PRD_SCAN_COMM_REGISTER_ZERO for the bus callout, else SUCCESS
 */
int32_t DlFatalError( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                      uint8_t i_dl )
{
    #define PRDF_FUNC "[p10_omic::DlFatalError] "

    int32_t rc = SUCCESS;

    do
    {
        // Note: The OMIDLFIR can't actually be set up to report UNIT_CS
        // attentions, instead, as a workaround, the relevant channel fail
        // bits will be set as recoverable bits and we will manually set
        // the attention types to UNIT_CS in our handling of these errors.
        io_sc.service_data->setPrimaryAttnType( UNIT_CS );

        char reg[64];
        sprintf( reg, "DL%d_ERROR_HOLD", i_dl );

        // Check DL#_ERROR_HOLD[52:63] to determine callout
        SCAN_COMM_REGISTER_CLASS * dl_error_hold = i_chip->getRegister( reg );

        if ( SUCCESS != dl_error_hold->Read() )
        {
            PRDF_ERR( PRDF_FUNC "Read() Failed on DL%d_ERROR_HOLD: "
                      "i_chip=0x%08x", i_dl, i_chip->getHuid() );
            break;
        }

        if ( dl_error_hold->IsBitSet(53) ||
             dl_error_hold->IsBitSet(55) ||
             dl_error_hold->IsBitSet(57) ||
             dl_error_hold->IsBitSet(58) ||
             dl_error_hold->IsBitSet(59) ||
             dl_error_hold->IsBitSet(60) ||
             dl_error_hold->IsBitSet(62) ||
             dl_error_hold->IsBitSet(63) )
        {
            // Get and callout the OMI target
            TargetHandle_t omi = getConnectedChild( i_chip->getTrgt(), TYPE_OMI,
                                                    i_dl );
            io_sc.service_data->SetCallout( omi );
        }
        else if ( dl_error_hold->IsBitSet(54) ||
                  dl_error_hold->IsBitSet(56) ||
                  dl_error_hold->IsBitSet(61) )
        {
            // callout the OMI target, the OMI bus, and the OCMB
            // Return PRD_SCAN_COMM_REGISTER_ZERO so the rule code makes
            // the appropriate callout.
            rc = PRD_SCAN_COMM_REGISTER_ZERO;
        }

    }while(0);

    return rc;

    #undef PRDF_FUNC
}

#define DL_FATAL_ERROR_PLUGIN( POS ) \
int32_t DlFatalError_##POS( ExtensibleChip * i_chip, \
                            STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return DlFatalError( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE( p10_omic, DlFatalError_##POS );

DL_FATAL_ERROR_PLUGIN( 0 );
DL_FATAL_ERROR_PLUGIN( 1 );

/**
 * @brief  Plugin function to collect OMI fail related FFDC from the appropriate
 *         OCMB.
 * @param  i_chip An OMIC chip.
 * @param  io_sc  The step code data struct.
 * @param  i_dl   The DL relative to the OMIC.
 * @return SUCCESS.
 */
int32_t CollectOmiOcmbFfdc( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & io_sc, uint8_t i_dl )
{
    #define PRDF_FUNC "[p10_omic::CollectOmiOcmbFfdc] "

    do
    {
        TargetHandle_t omiTrgt = getConnectedChild( i_chip->getTrgt(), TYPE_OMI,
                                                    i_dl );
        if ( nullptr == omiTrgt )
        {
            PRDF_ERR( PRDF_FUNC "Failed to get connected OMI from OMIC trgt "
                      "huid=0x%08x.", i_chip->getHuid() );
            break;
        }
        TargetHandle_t ocmbTrgt = getConnectedChild(omiTrgt, TYPE_OCMB_CHIP, 0);
        if ( nullptr == ocmbTrgt )
        {
            PRDF_ERR( PRDF_FUNC "Failed to get connected OCMB from OMI trgt "
                      "huid=0x%08x.", getHuid(omiTrgt) );
            break;
        }

        ExtensibleChip * ocmbChip =
            (ExtensibleChip *)systemPtr->GetChip(ocmbTrgt);
        if ( nullptr == ocmbChip )
        {
            PRDF_ERR( PRDF_FUNC "Failed to get OCMB ExtensibleChip for trgt "
                      "huid=0x%08x", getHuid(ocmbTrgt) );
            break;
        }

        ocmbChip->CaptureErrorData( io_sc.service_data->GetCaptureData(),
                                    Util::hashString("omi_ocmb_ffdc") );

    }while(0);

    return SUCCESS;

    #undef PRDF_FUNC
}

#define OMI_OCMB_FFDC_PLUGIN( POS ) \
int32_t CollectOmiOcmbFfdc_##POS( ExtensibleChip * i_chip, \
                                  STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return CollectOmiOcmbFfdc( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE( p10_omic, CollectOmiOcmbFfdc_##POS );

OMI_OCMB_FFDC_PLUGIN( 0 );
OMI_OCMB_FFDC_PLUGIN( 1 );

} // end namespace p10_omic

} // end namespace PRDF
