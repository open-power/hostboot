/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMembuf.C $       */
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

/** @file  prdfCenMembuf.C
 *  @brief Contains all the plugin code for the PRD Centaur Membuf
 */

#include <iipServiceDataCollector.h>
#include <prdfCalloutUtil.H>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>
#include <prdfGlobal.H>
#include <iipSystem.h>
#include <prdfLaneRepair.H>
#include <UtilHash.H>

using namespace TARGETING;

#include <prdfCenMembufDataBundle.H>

namespace PRDF
{

namespace Membuf
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the P8 Centaur Membuf data bundle.
 * @param  i_mbaChip A Centaur Membuf chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_mbaChip )
{
    i_mbaChip->getDataBundle() = new CenMembufDataBundle( i_mbaChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Membuf, Initialize );

//------------------------------------------------------------------------------

/**
 * @fn CheckForRecovered
 * @brief Used when the chip has a CHECK_STOP attention to check for the
 * presence of recovered errors.
 *
 * @param  i_chip       The Centaur chip.
 * @param  o_hasRecovered TRUE if a recoverable attention exists in the Centaur.
 *
 * @return SUCCESS.

 */
int32_t CheckForRecovered(ExtensibleChip * i_chip,
                          bool & o_hasRecovered)
{
    o_hasRecovered = false;

    int32_t l_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * l_grer = i_chip->getRegister("GLOBAL_RE_FIR");
    l_rc = l_grer->Read();

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR("[CheckForRecovered] GLOBAL_RE_FIR read failed"
                 "for 0x%08x", i_chip->GetId());
    }
    else if ( 0 != l_grer->GetBitFieldJustified(1,3) )
    {
        o_hasRecovered = true;
    }

    return SUCCESS;

} PRDF_PLUGIN_DEFINE( Membuf, CheckForRecovered );

//------------------------------------------------------------------------------

/**
 * @brief  MBA0 is always analyzed before MBA1 in the rule code.
 *         This plugin will help prevent starvation of MBA1.
 * @param  i_membChip The Centaur Membuf chip.
 * @param  i_sc     The step code data struct.
 * @return FAIL if MBA1 is not analyzed.
 */
int32_t MBA1_Starvation( ExtensibleChip * i_membChip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    using namespace TARGETING;
    CenMembufDataBundle * l_membdb = getMembufDataBundle(i_membChip);

    do
    {
        ExtensibleChip * mba1Chip = l_membdb->getMbaChip(1);
        if ( NULL == mba1Chip ) break; // No MBA1 target, exit early

        if ( l_membdb->iv_analyzeMba1Starvation )
        {
            // Get the mem chiplet register
            SCAN_COMM_REGISTER_CLASS * l_memcFir = NULL;
            uint32_t l_checkBits = 0;
            switch ( i_sc.service_data->GetCauseAttentionType() )
            {
                case CHECK_STOP:
                    l_memcFir = i_membChip->getRegister("MEM_CHIPLET_CS_FIR");
                    // mba1 CS: bits 6, 8, 10, 13
                    l_checkBits = 0x02A40000;
                    break;
                case RECOVERABLE:
                    l_memcFir = i_membChip->getRegister("MEM_CHIPLET_RE_FIR");
                    // mba1 RE: bits 4, 6, 8, 11
                    l_checkBits = 0x0A900000;
                    break;
                case SPECIAL:
                    l_memcFir = i_membChip->getRegister("MEM_CHIPLET_SPA");
                    // mba1 SA: bit 1
                    l_checkBits = 0x40000000;
                    break;
                default: ;
            }

            if( NULL == l_memcFir )
            {
                break;
            }

            // Check if MBA1 from Mem Chiplet is reporting an attention
            int32_t l_rc = l_memcFir->Read();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR("[MBA1_Starvation] SCOM fail on 0x%08x",
                         i_membChip->GetId());
                break;
            }

            uint32_t l_val = l_memcFir->GetBitFieldJustified(0,32);
            if ( 0 == ( l_val & l_checkBits ) )
            {
                break; // No MBA1 attentions
            }

            // MBA0 takes priority next
            l_membdb->iv_analyzeMba1Starvation = false;

            // Analyze MBA1
            return mba1Chip->Analyze( i_sc,
                                i_sc.service_data->GetCauseAttentionType() );
        }
        else
        {
            // MBA1 takes priority next
            l_membdb->iv_analyzeMba1Starvation = true;
        }

    } while (0);

    return FAIL;
}
PRDF_PLUGIN_DEFINE( Membuf, MBA1_Starvation );

//------------------------------------------------------------------------------

/**
 * @brief Analysis code that is called before the main analyze() function.
 * @param i_mbChip A MEMBUF chip.
 * @param i_sc Step Code Data structure
 * @param o_analyzed TRUE if analysis has been done on this chip
 * @return failure or success
 */
int32_t PreAnalysis( ExtensibleChip * i_mbChip, STEP_CODE_DATA_STRUCT & i_sc,
                     bool & o_analyzed )
{
    #define PRDF_FUNC "[Membuf::PreAnalysis] "

    int32_t o_rc = SUCCESS;

    o_analyzed = false;

    // Get memory capture data.
    CaptureData & cd = i_sc.service_data->GetCaptureData();
    CenMembufDataBundle * mbdb = getMembufDataBundle( i_mbChip );
    ExtensibleChip * mcsChip = mbdb->getMcsChip();
    if ( NULL != mcsChip )
    {
        mcsChip->CaptureErrorData( cd, Util::hashString("FirRegs") );
        mcsChip->CaptureErrorData( cd, Util::hashString("CerrRegs") );

        for ( uint32_t i = 0; i < MAX_MBA_PER_MEMBUF; i++ )
        {
            ExtensibleChip * mbaChip = mbdb->getMbaChip(i);
            if ( NULL != mbaChip )
            {
                mbaChip->CaptureErrorData( cd, Util::hashString("FirRegs") );
                mbaChip->CaptureErrorData( cd, Util::hashString("CerrRegs") );
            }
        }
    }

    // Check for a Centaur Checkstop
    do
    {
        // Skip if we're already analyzing a unit checkstop
        if ( i_sc.service_data->GetFlag(ServiceDataCollector::UNIT_CS) )
            break;

        if ( NULL == mcsChip )
        {
            PRDF_ERR( PRDF_FUNC"CenMembufDataBundle::getMcsChip() failed" );
            o_rc = FAIL; break;
        }

        // Check MCIFIR[31] for presence of Centaur checkstop
        SCAN_COMM_REGISTER_CLASS * fir = mcsChip->getRegister("MCIFIR");
        o_rc = fir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Failed to read MCIFIR on 0x%08x",
                      mcsChip->GetId() );
            break;
        }

        if ( !fir->IsBitSet(31) ) break; // No unit checkstop

        // Set Unit checkstop flag
        i_sc.service_data->SetFlag(ServiceDataCollector::UNIT_CS);
        i_sc.service_data->SetThresholdMaskId(0);

        // Set the cause attention type
        i_sc.service_data->SetCauseAttentionType(UNIT_CS);

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Membuf, PreAnalysis );

//------------------------------------------------------------------------------

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_mbChip A Centaur chip.
 * @param  i_sc     The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_mbChip, STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[Membuf::PostAnalysis] "

    #ifdef __HOSTBOOT_MODULE

    // In hostboot, we need to clear associated bits in the MCIFIR bits.
    do
    {
        CenMembufDataBundle * mbdb = getMembufDataBundle(i_mbChip);
        ExtensibleChip * mcsChip = mbdb->getMcsChip();
        if ( NULL == mcsChip )
        {
            PRDF_ERR( PRDF_FUNC"CenMembufDataBundle::getMcsChip() failed" );
            break;
        }

        // Clear the associated MCIFIR bits for all attention types.
        // NOTE: If there are any active attentions left in the Centaur the
        //       associated MCIFIR bit will be redriven with the next packet on
        //       the bus.
        SCAN_COMM_REGISTER_CLASS * firand = mcsChip->getRegister("MCIFIR_AND");

        firand->setAllBits();
        firand->ClearBit(12); // CS
        firand->ClearBit(15); // RE
        firand->ClearBit(16); // SPA
        firand->ClearBit(17); // maintenance command complete

        int32_t l_rc = firand->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"MCIFIR_AND write failed" );
            break;
        }

    } while (0);

    #endif // __HOSTBOOT_MODULE

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Membuf, PostAnalysis );

/**
 * @brief Handle lane repair spare deployed
 * @param  i_membChip A Centaur chip.
 * @param  i_sc       The step code data struct
 * @return SUCCESS
 */
int32_t spareDeployed( ExtensibleChip * i_membChip,
                       STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent( i_membChip, TYPE_MEMBUF, 0, i_sc,
                                              true );
}
PRDF_PLUGIN_DEFINE( Membuf, spareDeployed );

/**
 * @brief  Handle lane repair max spares exceeded
 * @param  i_membChip A Centaur chip.
 * @param  i_sc       The step code data struct
 * @return SUCCESS
 */
int32_t maxSparesExceeded( ExtensibleChip * i_membChip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent( i_membChip, TYPE_MEMBUF, 0, i_sc,
                                              false );
}
PRDF_PLUGIN_DEFINE( Membuf, maxSparesExceeded );

/**
 * @brief  Checks if spare deployed bit for DMI bus is set.
 * @param  i_mbChip  Membuf chip
 * @param  i_sc      The step code data struct.
 * @return SUCCESS if bit is on, FAIL otherwise.
 */
int32_t checkSpareBit( ExtensibleChip * i_mbChip,
                       STEP_CODE_DATA_STRUCT & i_sc )
{
    using namespace LaneRepair;
    int32_t l_rc = FAIL;

    ExtensibleChip * mcsChip = getMembufDataBundle( i_mbChip )->getMcsChip();

    if ( true == isSpareBitOnDMIBus( mcsChip, i_mbChip ))
    {
        l_rc = SUCCESS;
    }

    return l_rc;
}
PRDF_PLUGIN_DEFINE( Membuf, checkSpareBit );

} // end namespace Membuf

} // end namespace PRDF
