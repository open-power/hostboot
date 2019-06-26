/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/explorer/prdfExplorerPlugins.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
//#include <prdfOcmbDataBundle.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace explorer_ocmb
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[explorer_ocmb::PostAnalysis] "

    #ifdef __HOSTBOOT_RUNTIME

    // If the IUE threshold in our data bundle has been reached, we trigger
    // a port fail. Once we trigger the port fail, the system may crash
    // right away. Since PRD is running in the hypervisor, it is possible we
    // may not get the error log. To better our chances, we trigger the port
    // fail here after the error log has been committed.
    if ( MemEcc::queryIueTh<TYPE_OCMB_CHIP>(i_chip, io_sc) )
    {
        if ( SUCCESS != MemEcc::triggerPortFail<TYPE_OCMB_CHIP>(i_chip) )
        {
            PRDF_ERR( PRDF_FUNC "triggerPortFail(0x%08x) failed",
            i_chip->getHuid() );
        }
    }

    #endif // __HOSTBOOT_RUNTIME

    return SUCCESS; // Always return SUCCESS for this plugin.

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, PostAnalysis );

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

    // TODO RTC 207273 - Do nothing for now until we have full support for
    // Axone/Explorer
    return SUCCESS;

    // Tell the TD controller there was a command complete attention.
    /*OcmbDataBundle * db = getOcmbDataBundle( i_chip );
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
    }*/

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( explorer_ocmb, McbistCmdComplete );

} // end namespace explorer_ocmb

} // end namespace PRDF

