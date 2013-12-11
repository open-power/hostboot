/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMba.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
 *  @brief Contains all common plugin code for the Centaur MBA
 */

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>

// Pegasus includes
#include <prdfCalloutUtil.H>
#include <prdfCenMbaCaptureData.H>
#include <prdfCenMbaDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Mba
{
// Forward Declarations

int32_t CalloutMbaAndDimm( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc, uint32_t i_port );

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
    #define PRDF_FUNC "[Mba::MaintCmdComplete] "

    int32_t l_rc = SUCCESS;

    CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );

    // Tell the TD controller that a maintenance command complete occurred.
    l_rc = mbadb->iv_tdCtlr.handleCmdCompleteEvent( i_sc );
    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_mbaChip=0x%08x", i_mbaChip->GetId() );
        CalloutUtil::defaultError( i_sc );
    }

    // Gather capture data even if something failed above.
    // NOTE: There is no need to capture if the maintenance command complete was
    //       successful with no errors because the error log will not be
    //       committed.
    if ( !i_sc.service_data->IsDontCommitErrl() )
        CenMbaCaptureData::addMemEccData( i_mbaChip, i_sc );

    return PRD_NO_CLEAR_FIR_BITS; // FIR bits are cleared by this plugin

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Mba, MaintCmdComplete );

/**
 * @brief  Plugin to add MBA and Dimms behind port 0 to callout list.
 * @param  i_chip   mba chip
 * @param  i_sc     The step code data struct.
 * @return SUCCESS
 */
int32_t CalloutMbaAndDimmOnPort0( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    return CalloutMbaAndDimm( i_chip, i_sc, 0);
}
PRDF_PLUGIN_DEFINE( Mba, CalloutMbaAndDimmOnPort0 );

/**
 * @brief  Plugin to add MBA and Dimms behind port 1 to callout list.
 * @param  i_chip   mba chip
 * @param  i_sc     The step code data struct.
 * @return SUCCESS
 */
int32_t CalloutMbaAndDimmOnPort1( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    return CalloutMbaAndDimm( i_chip, i_sc, 1);
}
PRDF_PLUGIN_DEFINE( Mba, CalloutMbaAndDimmOnPort1 );

/**
 * @brief  Plugin to add MBA and Dimms behind given port to callout list.
 * @param  i_chip   mba chip
 * @param  i_sc     The step code data struct.
 * @param  i_port   Port Number.
 * @return SUCCESS
 */
int32_t CalloutMbaAndDimm( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & i_sc, uint32_t i_port )
{
    using namespace TARGETING;
    using namespace CalloutUtil;
    int32_t o_rc = SUCCESS;
    TargetHandle_t mbaTarget = i_chip->GetChipHandle();

    TargetHandleList calloutList = getConnectedDimms( mbaTarget, i_port );
    i_sc.service_data->SetCallout( mbaTarget, MRU_LOW );

    for ( TargetHandleList::iterator it = calloutList.begin();
          it != calloutList.end(); it++)
    {
       i_sc.service_data->SetCallout( *it,MRU_HIGH );
    }
    return o_rc;
}

/**
 * @brief  When not in MNFG mode, clear the service call flag so that
 *          thresholding will still be done, but not visible errorlog.
 * @param  i_chip   MemBuf chip
 * @param  i_sc     service data collector
 * @returns Success
 */
int32_t ClearServiceCallFlag( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    if( i_sc.service_data->IsAtThreshold() && !mfgMode() )
    {
        i_sc.service_data->ClearFlag(ServiceDataCollector::SERVICE_CALL);
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Mba, ClearServiceCallFlag );

} // end namespace Mba

} // end namespace PRDF
