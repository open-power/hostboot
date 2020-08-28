/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfMccPlugins.C $          */
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
    TargetHandle_t rxTrgt = getConnectedChild(i_chip->getTrgt(), TYPE_OMI, 0);
    TargetHandle_t txTrgt = getConnectedChild(rxTrgt, TYPE_OCMB_CHIP, 0);

    calloutBus(io_sc, rxTrgt, txTrgt, HWAS::OMI_BUS_TYPE);

    return SUCCESS;
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
    TargetHandle_t rxTrgt = getConnectedChild(i_chip->getTrgt(), TYPE_OMI, 1);
    TargetHandle_t txTrgt = getConnectedChild(rxTrgt, TYPE_OCMB_CHIP, 0);

    calloutBus(io_sc, rxTrgt, txTrgt, HWAS::OMI_BUS_TYPE);

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(p10_mcc, calloutBusInterface_1);

} // end namespace p10_mcc

} // end namespace PRDF
