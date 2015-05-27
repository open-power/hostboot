/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatCenMba_ipl.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

/** @file  prdfCenMba.C
 *  @brief Contains all Hostboot specific plugin code for the PRD Centaur MBA.
 */

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>

// Pegasus includes
#include <prdfCenMbaCaptureData.H>
#include <prdfCenMbaDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Mba
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_mbaChip A Centaur MBA chip.
 * @param  i_sc      The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_mbaChip,
                      STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[Mba::PostAnalysis] "

    // Send command complete to MDIA.
    // This must be done in post analysis after attentions have been cleared.

    TargetHandle_t mbaTarget = i_mbaChip->GetChipHandle();
    CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );

    if ( mbadb->iv_sendCmdCompleteMsg )
    {
        mbadb->iv_sendCmdCompleteMsg = false;

        int32_t l_rc = mdiaSendEventMsg( mbaTarget,
                                         mbadb->iv_cmdCompleteMsgData );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "PlatServices::mdiaSendEventMsg() failed" );
        }
    }

    return SUCCESS; // Intentionally return SUCCESS for this plugin

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Mba, PostAnalysis );

} // end namespace Mba

} // end namespace PRDF

