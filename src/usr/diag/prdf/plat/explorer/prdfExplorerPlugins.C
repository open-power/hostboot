/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/explorer/prdfExplorerPlugins.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
#include <prdfMemDbUtils.H>
#include <prdfMemEccAnalysis.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace explorer_ocmb
{

//##############################################################################
//
//                                 MCBISTFIR
//
//##############################################################################

/**
 * @brief  MCBISTFIR[10] - MCBIST Command Complete.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t McbistCmdComplete( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[explorer_ocmb::McbistCmdComplete] "

    // Tell the TD controller there was a command complete attention.
    OcmbDataBundle * db = getOcmbDataBundle( i_chip );
    if ( SUCCESS != db->getTdCtlr()->handleCmdComplete(io_sc) )
    {
        // Something failed. It is possible the command complete attention has
        // not been cleared. Make the rule code do it.
        return SUCCESS;
    }
    else
    {
        // Everything was successful. Whether we started a new command or told
        // MDIA to do it, the command complete bit has already been cleared.
        // Don't do it again.
        return PRD_NO_CLEAR_FIR_BITS;
    }

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, McbistCmdComplete );

/**
 * @brief   Whenever an OMI link has degraded, the bus must be reconfigured to
 *          avoid infinite retrains.
 * @param   i_chip An OCMB chip.
 * @param   io_sc  The step code data struct.
 * @returns SUCCESS always.
 */
int32_t omiDegradeRetrainWorkaround(ExtensibleChip* i_chip,
                                    STEP_CODE_DATA_STRUCT& io_sc)
{
    auto omiTarget = getConnectedParent(i_chip->getTrgt(), TYPE_OMI);

    if (nullptr != omiTarget)
    {
        PlatServices::omiDegradeDlReconfig(omiTarget);
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(explorer_ocmb, omiDegradeRetrainWorkaround);

} // end namespace explorer_ocmb

} // end namespace PRDF

