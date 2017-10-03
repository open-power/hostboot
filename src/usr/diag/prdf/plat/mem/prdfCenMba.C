/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfCenMba.C $                     */
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

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginDef.H>
#include <prdfPluginMap.H>

// Platform includes
#include <prdfCenMbaDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace cen_mba
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the data bundle.
 * @param  i_mbaChip An MBA chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_mbaChip )
{
    i_mbaChip->getDataBundle() = new MbaDataBundle( i_mbaChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( cen_mba, Initialize );

//##############################################################################
//
//                                 MBASPA
//
//##############################################################################

/**
 * @brief  MBASPA[0,8] - Maintenance Command Complete.
 * @param  i_mbaChip An MBA chip.
 * @param  io_sc     The step code data struct.
 * @return SUCCESS
 */
int32_t MaintCmdComplete( ExtensibleChip * i_mbaChip,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[cen_mba::MaintCmdComplete] "

    // Tell the TD controller there was a command complete attention.
    MbaDataBundle * db = getMbaDataBundle( i_mbaChip );
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
PRDF_PLUGIN_DEFINE( cen_mba, MaintCmdComplete );

//------------------------------------------------------------------------------

} // end namespace cen_mba

} // end namespace PRDF

