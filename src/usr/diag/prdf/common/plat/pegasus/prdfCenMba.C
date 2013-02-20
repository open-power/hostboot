/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMba.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
 *  @brief Contains all the plugin code for the PRD Centaur MBA
 */

#include <iipServiceDataCollector.h>
#include <prdfCalloutUtil.H>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>

#include <prdfCenMbaCaptureData.H>
#include <prdfCenMbaDataBundle.H>

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
 * @brief  Plugin that initializes the P8 Centaur MBA data bundle.
 * @param  i_mbaChip A Centaur MBA chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_mbaChip )
{
    i_mbaChip->getDataBundle() = new CenMbaDataBundle( i_mbaChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Mba, Initialize );

//------------------------------------------------------------------------------

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
    #ifdef __HOSTBOOT_MODULE

    using namespace TARGETING;

    // Send command complete to MDIA.
    // This must be done in post analysis after attentions have been cleared.

    TargetHandle_t mbaTarget = i_mbaChip->GetChipHandle();
    CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );

    if ( mbadb->iv_sendCmdCompleteMsg )
    {
        mbadb->iv_sendCmdCompleteMsg = false;

        int32_t l_rc = mdiaSendEventMsg( mbaTarget,
                                         mbadb->iv_cmdCompleteMsgData );

        if ( l_rc )
        {
            PRDF_ERR( "[Mba::PostAnalysis] PlatServices::mdiaSendEventMsg"
                      " failed" );
        }
    }

    #endif // __HOSTBOOT_MODULE

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Mba, PostAnalysis );

//##############################################################################
//
//                                   MBASPA
//
//##############################################################################

/**
 * @brief  MBASPA[0] - Maintenance command complete.
 * @param  i_mbaChip A Centaur MBA chip.
 * @param  i_sc      The step code data struct.
 * @return SUCCESS
 */
int32_t MaintCmdComplete( ExtensibleChip * i_mbaChip,
                          STEP_CODE_DATA_STRUCT & i_sc )
{
    using namespace TARGETING;

    int32_t l_rc = SUCCESS;
    TargetHandle_t mbaTarget = i_mbaChip->GetChipHandle();

    do
    {
        #ifdef __HOSTBOOT_MODULE

        if ( PlatServices::isInMdiaMode() )
        {
            // Immediately inform mdia that the command
            // has finished.

            l_rc = PlatServices::mdiaSendEventMsg( mbaTarget,
                    MDIA::RESET_TIMER );

            if(l_rc)
            {
                PRDF_ERR( "[Mba::MaintCmdComplete] "
                        "PlatServices::mdiaSendEventMsg"
                        " failed" );

                // keep going
            }

            // Determine for mdia whether or not the command
            // finished at the end of the last rank or if
            // the command will need to be restarted.
            // Tuck this away until PostAnalysis.

            CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );

            SCAN_COMM_REGISTER_CLASS * MBMACA =
                i_mbaChip->getRegister("MBMACA");
            SCAN_COMM_REGISTER_CLASS * MBMEA = i_mbaChip->getRegister("MBMEA");

            l_rc = MBMACA->Read();
            if (l_rc != SUCCESS) break;

            l_rc = MBMEA->Read();
            if (l_rc != SUCCESS) break;

            mbadb->iv_sendCmdCompleteMsg = true;
            mbadb->iv_cmdCompleteMsgData =
                (MBMACA->GetBitFieldJustified(0, 40)
                 == MBMEA->GetBitFieldJustified(0, 40))
                ? MDIA::COMMAND_COMPLETE
                : MDIA::COMMAND_STOPPED;

            // Do not commit error log for a successful command complete.
            if ( MDIA::COMMAND_COMPLETE == mbadb->iv_cmdCompleteMsgData )
	            i_sc.service_data->DontCommitErrorLog();
        }

        #endif // __HOSTBOOT_MODULE

        // Get DRAM repairs capture data
        CenMbaCaptureData::addDramRepairsData( mbaTarget, i_sc );

    } while (0);

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( "[Mba::MaintCmdComplete] failed on MBA 0x%08x",
                  PlatServices::getHuid(mbaTarget) );
        CalloutUtil::defaultError( i_sc );
    }

    return l_rc;
}
PRDF_PLUGIN_DEFINE( Mba, MaintCmdComplete );

/**
 * @brief  Plugin to send a Skip MBA message for Memory Diagnositics.
 * @note   Does nothing in non-MDIA mode.
 * @note   Will stop any maintenance commands in progress.
 * @param  i_chip   mba target
 * @param  i_sc     The step code data struct.
 * @return SUCCESS
 */
// FIXME: Story 51702 will implement this
int32_t SkipMbaMsg( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    using namespace TARGETING;
    int32_t o_rc = SUCCESS;
    TargetHandle_t mbaTarget = i_chip->GetChipHandle();

    PRDF_ERR("[SkipMbaMsg] MBA 0x%08x : this function is not yet implemented!",
                 PlatServices::getHuid(mbaTarget));

    return o_rc;
}
PRDF_PLUGIN_DEFINE( Mba, SkipMbaMsg );

} // end namespace Mba
} // end namespace PRDF
