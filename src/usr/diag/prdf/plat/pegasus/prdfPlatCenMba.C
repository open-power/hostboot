/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatCenMba.C $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
            PRDF_ERR( PRDF_FUNC"PlatServices::mdiaSendEventMsg() failed" );
        }
    }

    return SUCCESS; // Intentionally return SUCCESS for this plugin

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Mba, PostAnalysis );

/**
 * @brief  Plugin to send a SKIP_MBA message for Memory Diagnositics.
 * @note   Does nothing in non-MDIA mode.
 * @note   Will stop any maintenance commands in progress.
 * @param  i_mbaChip A Centaur MBA chip.
 * @param  i_sc      The step code data struct.
 * @return SUCCESS.
 */
int32_t SkipMbaMsg( ExtensibleChip * i_mbaChip, STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[Mba::SkipMbaMsg] "

    int32_t l_rc = SUCCESS;

    TargetHandle_t mbaTrgt = i_mbaChip->GetChipHandle();

    l_rc = mdiaSendEventMsg( mbaTrgt, MDIA::SKIP_MBA );
    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC"mdiaSendEventMsg(0x%08x, SKIP_MBA) failed",
                  getHuid(mbaTrgt) );
        // Keep going.
    }

    return SUCCESS; // Intentionally return SUCCESS for this plugin

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Mba, SkipMbaMsg );

} // end namespace Mba

} // end namespace PRDF

