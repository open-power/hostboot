/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfP9Mca_common.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <prdfMemEccAnalysis.H>
#include <prdfPlatServices.H>
#include <prdfP9McaDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p9_mca
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the data bundle.
 * @param  i_chip An MCA chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_chip )
{
    i_chip->getDataBundle() = new McaDataBundle( i_chip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p9_mca, Initialize );

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip An MCA chip.
 * @param  io_sc  The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p9_mca::PostAnalysis] "

    return SUCCESS; // Always return SUCCESS for this plugin.

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mca, PostAnalysis );

//##############################################################################
//
//                               MCAECCFIR
//
//##############################################################################

/**
 * @brief  MCAECCFIR[14] - Mainline UE.
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t AnalyzeFetchUe( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    MemEcc::analyzeFetchUe<TYPE_MCA, McaDataBundle *>( i_chip, io_sc );
    return SUCCESS; // nothing to return to rule code
}
PRDF_PLUGIN_DEFINE( p9_mca, AnalyzeFetchUe );

} // end namespace p9_mca

} // end namespace PRDF

