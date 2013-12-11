/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8Mcs.C $           */
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

/** @file  prdfP8Mcs.C
 *  @brief Contains all the plugin code for the PRD P8 MCS
 */

// Framework includes
#include <iipServiceDataCollector.h>
#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPluginMap.H>
#include <UtilHash.H>

// Pegasus includes
#include <prdfCenMbaCaptureData.H>
#include <prdfCenMembufDataBundle.H>
#include <prdfLaneRepair.H>
#include <prdfP8McsDataBundle.H>
#include <prdfCenMemUtils.H>

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

namespace PRDF
{

namespace Mcs
{

/**
 * @brief  Plugin that initializes the MCS data bundle.
 * @param  i_mcsChip An MCS chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_mcsChip )
{
    i_mcsChip->getDataBundle() = new P8McsDataBundle( i_mcsChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Mcs, Initialize );

/**
 * @brief Check for and handle a Centaur Unit Checkstop
 * @param i_mcsChip An MCS chip.
 * @param i_sc Step Code Data structure
 * @return failure or success
 */
int32_t CheckCentaurCheckstop( ExtensibleChip * i_mcsChip,
                               STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = SUCCESS;

    do
    {
        // Skip if we're already at Unit Checkstop in SDC
        if (i_sc.service_data->GetFlag(ServiceDataCollector::UNIT_CS))
            break;

        // Check MCIFIR[31] for presence of Centaur checkstop
        SCAN_COMM_REGISTER_CLASS * l_mcifir = i_mcsChip->getRegister("MCIFIR");
        l_rc = l_mcifir->Read();

        if (l_rc)
        {
            PRDF_ERR( "[CheckCentaurCheckstop] SCOM fail on 0x%08x rc=%x",
                      i_mcsChip->GetId(), l_rc);
            break;
        }

        if ( ! l_mcifir->IsBitSet(31) )  { break; }

        // Set Unit checkstop flag
        i_sc.service_data->SetFlag(ServiceDataCollector::UNIT_CS);
        i_sc.service_data->SetThresholdMaskId(0);

        // Set the cause attention type
        i_sc.service_data->SetCauseAttentionType(UNIT_CS);

    } while (0);

    return l_rc;
}

/**
 * @brief Analysis code that is called before the main analyze() function.
 * @param i_mcsChip An MCS chip.
 * @param i_sc Step Code Data structure
 * @param o_analyzed TRUE if analysis has been done on this chip
 * @return failure or success
 */
int32_t PreAnalysis( ExtensibleChip * i_mcsChip, STEP_CODE_DATA_STRUCT & i_sc,
                     bool & o_analyzed )
{
    o_analyzed = false;

    // Get memory capture data.
    CaptureData & cd = i_sc.service_data->GetCaptureData();
    P8McsDataBundle * mcsdb = getMcsDataBundle( i_mcsChip );
    ExtensibleChip * membChip = mcsdb->getMembChip();
    if ( NULL != membChip )
    {
        membChip->CaptureErrorData( cd, Util::hashString("FirRegs") );
        membChip->CaptureErrorData( cd, Util::hashString("CerrRegs") );

        CenMbaCaptureData::addMemChipletFirRegs( membChip, cd );
    }

    // Check for a Centaur Checkstop
    int32_t o_rc = CheckCentaurCheckstop( i_mcsChip, i_sc );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( "[Mcs::PreAnalysis] CheckCentaurCheckstop() failed" );
    }

    return o_rc;
}
PRDF_PLUGIN_DEFINE( Mcs, PreAnalysis );

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_mcsChip MCS chip
 * @param  i_sc      The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_mcsChip,
                      STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[Mcs::PostAnalysis] "
    int32_t l_rc = SUCCESS;

    if ( i_sc.service_data->GetFlag(ServiceDataCollector::UNIT_CS) &&
         (CHECK_STOP != i_sc.service_data->GetAttentionType()) )
    {
        P8McsDataBundle * mcsdb = getMcsDataBundle( i_mcsChip );
        ExtensibleChip * membChip = mcsdb->getMembChip();
        if ( NULL != membChip )
        {
            l_rc = MemUtils::chnlCsCleanup( membChip, i_sc );
            if( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC"ChnlCsCleanup() failed for Membuf:0x%08X",
                          membChip->GetId() );
            }
        }
    }

    return SUCCESS;
    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Mcs, PostAnalysis );

/**
 * @brief  Checks if spare deployed bit for DMI bus for this MCS is set.
 * @param  i_mcsChip MCS chip
 * @param  i_sc      The step code data struct.
 * @return SUCCESS if bit is on, FAIL otherwise.
 */
int32_t checkSpareBit( ExtensibleChip * i_mcsChip,
                       STEP_CODE_DATA_STRUCT & i_sc )
{
    using namespace LaneRepair;

    int32_t l_rc = FAIL; // Default is to handle the attention (via rule code).

    ExtensibleChip * mbChip = getMcsDataBundle( i_mcsChip )->getMembChip();

    if ( isSpareBitOnDMIBus(i_mcsChip, mbChip) )
    {
        // Ignore attention and do not commit the error log.
        i_sc.service_data->DontCommitErrorLog();
        l_rc = SUCCESS;
    }

    return l_rc;
}
PRDF_PLUGIN_DEFINE( Mcs, checkSpareBit );

/**
 * @fn ClearMbsSecondaryBits
 * @brief Clears MBS secondary Fir bits which may come up because of MCIFIR
 * @param  i_chip       The Mcs chip.
 * @param  i_sc         ServiceDataColector.
 * @return SUCCESS.

 */
int32_t ClearMbsSecondaryBits( ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & i_sc  )
{
    #define PRDF_FUNC "[ClearMbsSecondaryBits] "

    int32_t l_rc = SUCCESS;
    do
    {
        P8McsDataBundle * mcsdb = getMcsDataBundle( i_chip );
        ExtensibleChip * membChip = mcsdb->getMembChip();

        if ( NULL == membChip ) break;

        // Not checking if MBSFIR bits are set or not.
        // Clearing them blindly as it will give better performance.
        SCAN_COMM_REGISTER_CLASS * mbsAndFir =
                                membChip->getRegister("MBSFIR_AND");

        if( NULL == mbsAndFir )
        {
            PRDF_ERR( PRDF_FUNC"Can not find MBSFIR_AND "
                       "for 0x%08x", membChip->GetId());
            break;
        }
        mbsAndFir->setAllBits();

        mbsAndFir->ClearBit(3);
        mbsAndFir->ClearBit(4);
        l_rc = mbsAndFir->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"MBSFIR_AND write failed"
                       "for 0x%08x", membChip->GetId());
            break;
        }
    }while( 0 );
    return SUCCESS;

    #undef PRDF_FUNC
} PRDF_PLUGIN_DEFINE( Mcs, ClearMbsSecondaryBits );

/**
 * @brief  When not in MNFG mode, clear the service call flag so that
 *          thresholding will still be done, but not visible errorlog.
 * @param  i_chip   Mcs rulechip
 * @param  i_sc     service data collector
 * @returns Success
 */
int32_t ClearServiceCallFlag( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    if( i_sc.service_data->IsAtThreshold() && !PlatServices::mfgMode() )
    {
        i_sc.service_data->ClearFlag(ServiceDataCollector::SERVICE_CALL);
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Mcs, ClearServiceCallFlag );

} // end namespace Mcs
} // end namespace PRDF

