/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfMccPlugins.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>

// Platform includes
#include <prdfMemUtils.H>
#include <prdfPlatServices.H>
#include <prdfMemExtraSig.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p10_mcc
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Analysis code that is called before the main analyze() function.
 * @param  i_chip     A MCC chip.
 * @param  io_sc      The step code data struct.
 * @param  o_analyzed True if analysis is done on this chip, false otherwise.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t PreAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                     bool & o_analyzed )
{
    // Check for a channel failure before analyzing this chip.
    o_analyzed = MemUtils::analyzeChnlFail<TYPE_MCC>( i_chip, io_sc );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p10_mcc, PreAnalysis );

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip A MCC chip.
 * @param  io_sc  The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    // If there was a channel failure some cleanup is required to ensure
    // there are no more attentions from this channel.
    MemUtils::cleanupChnlFail<TYPE_MCC>( i_chip, io_sc );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p10_mcc, PostAnalysis );

/**
 * @brief  Plugin called to analyze to a connected OCMB_CHIP
 * @param  i_chip A MCC chip.
 * @param  io_sc  The step code data struct.
 * @param  i_pos  The position of the connected OCMB (0:1)
 * @return PRD_NO_CLEAR_FIR_BITS if analysis successful, else the RC from
 *         analyze().
 */
int32_t analyzeConnectedOcmb( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & io_sc,
                              uint8_t i_pos )
{
    int32_t o_rc = SUCCESS;
    ExtensibleChip * ocmb = getConnectedChild( i_chip, TYPE_OCMB_CHIP, i_pos );
    if (nullptr == ocmb)
    {
        return PRD_UNRESOLVED_CHIP_CONNECTION;
    }

    o_rc = ocmb->Analyze( io_sc,
                          io_sc.service_data->getSecondaryAttnType() );
    if ( SUCCESS == o_rc )
    {
        // If analysis was successful, the PostAnalysis function of the
        // OCMB should have cleared the MC_DSTL_FIR bits as needed, or set
        // them again if there are still attentions to handle. As such, return
        // PRD_NO_CLEAR_FIR_BITS here so we don't clear the bits that may have
        // been set.
        o_rc = PRD_NO_CLEAR_FIR_BITS;
    }

    return o_rc;
}

#define PLUGIN_ANALYZE_OCMB( POS ) \
int32_t analyzeConnectedOcmb_##POS( ExtensibleChip * i_chip, \
                                    STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return analyzeConnectedOcmb( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE( p10_mcc, analyzeConnectedOcmb_##POS );

PLUGIN_ANALYZE_OCMB(0);
PLUGIN_ANALYZE_OCMB(1);

//##############################################################################
//
//                             Callout plugins
//
//##############################################################################

/**
 * @brief  Calls out the entire bus interface for OMI 0.
 * @param  i_chip An MCC chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t calloutBusInterface_0(ExtensibleChip* i_chip,
                              STEP_CODE_DATA_STRUCT& io_sc)
{
    #define PRDF_FUNC "[p10_mcc::calloutBusInterface_0] "

    TargetHandle_t rxTrgt = getConnectedChild(i_chip->getTrgt(), TYPE_OMI, 0);
    if ( nullptr == rxTrgt )
    {
        PRDF_ERR( PRDF_FUNC "Unable to get connected OMI from parent MCC "
                  "0x%08x", i_chip->getHuid() );
        return SUCCESS;
    }

    TargetHandle_t txTrgt = getConnectedChild(rxTrgt, TYPE_OCMB_CHIP, 0);
    if ( nullptr == txTrgt )
    {
        PRDF_ERR( PRDF_FUNC "Unable to get connected OCMB from parent OMI "
                  "0x%08x", getHuid(rxTrgt) );
        return SUCCESS;
    }

    calloutBus(io_sc, rxTrgt, txTrgt, HWAS::OMI_BUS_TYPE);

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE(p10_mcc, calloutBusInterface_0);

/**
 * @brief  Calls out the entire bus interface for OMI 1.
 * @param  i_chip An MCC chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t calloutBusInterface_1(ExtensibleChip* i_chip,
                              STEP_CODE_DATA_STRUCT& io_sc)
{
    #define PRDF_FUNC "[p10_mcc::calloutBusInterface_1] "

    TargetHandle_t rxTrgt = getConnectedChild(i_chip->getTrgt(), TYPE_OMI, 1);
    if ( nullptr == rxTrgt )
    {
        PRDF_ERR( PRDF_FUNC "Unable to get connected OMI from parent MCC "
                  "0x%08x", i_chip->getHuid() );
        return SUCCESS;
    }

    TargetHandle_t txTrgt = getConnectedChild(rxTrgt, TYPE_OCMB_CHIP, 0);
    if ( nullptr == txTrgt )
    {
        PRDF_ERR( PRDF_FUNC "Unable to get connected OCMB from parent OMI "
                  "0x%08x", getHuid(rxTrgt) );
        return SUCCESS;
    }

    calloutBus(io_sc, rxTrgt, txTrgt, HWAS::OMI_BUS_TYPE);

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE(p10_mcc, calloutBusInterface_1);

/**
 * @brief  Calls out the entire bus interface for OMI 0, with the OCMB as
 *         high priority
 * @param  i_chip An MCC chip.
 * @param  io_sc  The step code data struct.
 * @param  i_pos  The OMI pos (0:1)
 * @return SUCCESS
 */
int32_t chnlTimeout( ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc,
                     uint8_t i_pos )
{
    #define PRDF_FUNC "[p10_mcc::chnlTimeout] "

    TargetHandle_t rxTrgt = getConnectedChild( i_chip->getTrgt(), TYPE_OMI,
                                               i_pos );
    if ( nullptr == rxTrgt )
    {
        PRDF_ERR( PRDF_FUNC "Unable to get connected OMI from parent MCC "
                  "0x%08x", i_chip->getHuid() );
        return SUCCESS;
    }

    TargetHandle_t txTrgt = getConnectedChild( rxTrgt, TYPE_OCMB_CHIP, 0 );
    if ( nullptr == txTrgt )
    {
        PRDF_ERR( PRDF_FUNC "Unable to get connected OCMB from parent OMI "
                  "0x%08x", getHuid(rxTrgt) );
        return SUCCESS;
    }

    // Since we have no way to directly check the PMIC, we assume the PMIC is
    // the likely cause. As such, we want the OCMB to be the high priority
    // callout, and the OMI and bus to be low priority callouts.
    calloutBus( io_sc, rxTrgt, txTrgt, HWAS::OMI_BUS_TYPE, HWAS::FLAG_NONE,
                MRU_LOW, MRU_HIGH );

    return SUCCESS;

    #undef PRDF_FUNC
}

#define PLUGIN_CHNL_TIMEOUT(POS) \
int32_t chnlTimeout_##POS(ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc)\
{ \
    return chnlTimeout(i_chip, io_sc, POS); \
} \
PRDF_PLUGIN_DEFINE(p10_mcc, chnlTimeout_##POS);

PLUGIN_CHNL_TIMEOUT(0);
PLUGIN_CHNL_TIMEOUT(1);

} // end namespace p10_mcc

} // end namespace PRDF

