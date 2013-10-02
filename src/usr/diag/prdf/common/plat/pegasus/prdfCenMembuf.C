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

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>
#include <prdfGlobal.H>
#include <iipSystem.h>
#include <UtilHash.H>

// Pegasus includes
#include <prdfCalloutUtil.H>
#include <prdfCenAddress.H>
#include <prdfCenMarkstore.H>
#include <prdfCenMbaCaptureData.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfCenMbaTdCtlr_common.H>
#include <prdfCenMembufDataBundle.H>
#include <prdfLaneRepair.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

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

        CenMbaCaptureData::addMbaFirRegs( i_mbChip, cd );
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

//##############################################################################
//
//                               DMIFIR
//
//##############################################################################

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

//##############################################################################
//
//                               MBSECCFIRs
//
//##############################################################################

/**
 * @brief  MBSECCFIR[0-7,20:27] - Fetch/Maintenance Mark Placed Event (MPE).
 * @param  i_membChip A Centaur chip.
 * @param  i_sc       The step code data struct.
 * @param  i_mbaPos   The MBA position.
 * @param  i_rank     The target rank.
 * @return SUCCESS
 */
int32_t AnalyzeMpe( ExtensibleChip * i_membChip, STEP_CODE_DATA_STRUCT & i_sc,
                    uint32_t i_mbaPos, uint8_t i_rank, bool isFetchError )
{
    #define PRDF_FUNC "[AnalyzeMpe] "

    int32_t l_rc = SUCCESS;

    ExtensibleChip * mbaChip = NULL;

    do
    {
        CenMembufDataBundle * membdb = getMembufDataBundle( i_membChip );
        mbaChip = membdb->getMbaChip( i_mbaPos );
        if ( NULL == mbaChip )
        {
            PRDF_ERR( PRDF_FUNC"getMbaChip() returned NULL" );
            l_rc = FAIL; break;
        }

        CenMbaDataBundle * mbadb = getMbaDataBundle( mbaChip );
        TargetHandle_t mbaTrgt = mbaChip->GetChipHandle();

        // Add address to UE table.
        if ( isFetchError )
        {
            CenAddr addr;
            l_rc = getCenReadAddr( i_membChip, i_mbaPos, READ_MPE_ADDR, addr );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC"getCenReadAddr() failed" );
                break;
            }
            mbadb->iv_ueTable.addEntry( UE_TABLE::FETCH_MPE, addr );
        }
        else
        {
            CenAddr addr;
            l_rc = getCenMaintStartAddr( mbaChip, addr );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC"getCenMaintStartAddr() failed" );
                break;
            }
            mbadb->iv_ueTable.addEntry( UE_TABLE::SCRUB_MPE, addr );
        }

        // Get the current mark in hardware.
        CenRank rank ( i_rank );
        CenMark mark;
        l_rc = mssGetMarkStore( mbaTrgt, rank, mark );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"mssGetMarkStore() failed");
            break;
        }

        if ( !mark.getCM().isValid() )
        {
            PRDF_ERR( PRDF_FUNC"FIR bit set but no valid chip mark" );
            l_rc = FAIL; break;
        }

        // Callout the mark.
        CalloutUtil::calloutMark( mbaTrgt, rank, mark, i_sc );

        // Tell TD controller to handle VCM event.
        l_rc = mbadb->iv_tdCtlr.handleTdEvent( i_sc, rank,
                                               CenMbaTdCtlrCommon::VCM_EVENT );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"handleTdEvent() failed." );
            break;
        }

    } while (0);

    // Add ECC capture data for FFDC.
    if ( NULL != mbaChip )
        CenMbaCaptureData::addMemEccData( mbaChip, i_sc );

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_membChip=0x%08x i_mbaPos=%d i_rank=%d",
                  i_membChip->GetId(), i_mbaPos, i_rank );
        CalloutUtil::defaultError( i_sc );
    }

    return SUCCESS; // Intentionally return SUCCESS for this plugin

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

/**
 * @brief  MBSECCFIR[16] - Fetch New CE (NCE).
 * @param  i_membChip A Centaur chip.
 * @param  i_sc       The step code data struct.
 * @param  i_mbaPos   The MBA position.
 * @return SUCCESS
 */
int32_t AnalyzeFetchNce( ExtensibleChip * i_membChip,
                         STEP_CODE_DATA_STRUCT & i_sc, uint32_t i_mbaPos )
{
    #define PRDF_FUNC "[AnalyzeFetchNce] "

    int32_t l_rc = SUCCESS;

    ExtensibleChip * mbaChip = NULL;

    do
    {
        CenMembufDataBundle * membdb = getMembufDataBundle( i_membChip );
        mbaChip = membdb->getMbaChip( i_mbaPos );
        if ( NULL == mbaChip )
        {
            PRDF_ERR( PRDF_FUNC"getMbaChip() returned NULL" );
            l_rc = FAIL; break;
        }

        CenAddr addr;
        l_rc = getCenReadAddr( i_membChip, i_mbaPos, READ_NCE_ADDR, addr );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"getCenReadAddr() failed" );
            break;
        }

        // FIXME: RTC 47289 Need to read MBSEVR to get the symbol. There is a
        //        bug in DD1.x so we can't use this register. There is a
        //        workaround but is it complicated. Need to check with Ken if it
        //        is ok to just callout the rank for DD1.x.

        MemoryMru memmru ( mbaChip->GetChipHandle(), addr.getRank(),
                           MemoryMruData::CALLOUT_RANK );
        i_sc.service_data->SetCallout( memmru );

    } while (0);

    // Add ECC capture data for FFDC.
    if ( NULL != mbaChip )
        CenMbaCaptureData::addMemEccData( mbaChip, i_sc );

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_membChip=0x%08x i_mbaPos=%d",
                  i_membChip->GetId(), i_mbaPos );
        CalloutUtil::defaultError( i_sc );
    }

    return SUCCESS; // Intentionally return SUCCESS for this plugin

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

/**
 * @brief  MBSECCFIR[17] - Fetch Retry CE (RCE).
 * @param  i_membChip A Centaur chip.
 * @param  i_sc       The step code data struct.
 * @param  i_mbaPos   The MBA position.
 * @return SUCCESS
 */
int32_t AnalyzeFetchRce( ExtensibleChip * i_membChip,
                         STEP_CODE_DATA_STRUCT & i_sc, uint32_t i_mbaPos )
{
    #define PRDF_FUNC "[AnalyzeFetchRce] "

    int32_t l_rc = SUCCESS;

    ExtensibleChip * mbaChip = NULL;

    do
    {
        CenMembufDataBundle * membdb = getMembufDataBundle( i_membChip );
        mbaChip = membdb->getMbaChip( i_mbaPos );
        if ( NULL == mbaChip )
        {
            PRDF_ERR( PRDF_FUNC"getMbaChip() returned NULL" );
            l_rc = FAIL; break;
        }

        CenAddr addr;
        l_rc = getCenReadAddr( i_membChip, i_mbaPos, READ_RCE_ADDR, addr );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"getCenReadAddr() failed" );
            break;
        }

        // Callout the rank and the attached MBA.
        MemoryMru memmru ( mbaChip->GetChipHandle(), addr.getRank(),
                           MemoryMruData::CALLOUT_RANK_AND_MBA );
        i_sc.service_data->SetCallout( memmru );

    } while (0);

    // Add ECC capture data for FFDC.
    if ( NULL != mbaChip )
        CenMbaCaptureData::addMemEccData( mbaChip, i_sc );

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_membChip=0x%08x i_mbaPos=%d",
                  i_membChip->GetId(), i_mbaPos );
        CalloutUtil::defaultError( i_sc );
    }

    return SUCCESS; // Intentionally return SUCCESS for this plugin

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

/**
 * @brief  MBSECCFIR[19] - Fetch UE.
 * @param  i_membChip A Centaur chip.
 * @param  i_sc       The step code data struct.
 * @param  i_mbaPos   The MBA position.
 * @return SUCCESS
 */
int32_t AnalyzeFetchUe( ExtensibleChip * i_membChip,
                        STEP_CODE_DATA_STRUCT & i_sc, uint32_t i_mbaPos )
{
    #define PRDF_FUNC "[AnalyzeFetchUe] "

    int32_t l_rc = SUCCESS;

    ExtensibleChip * mbaChip = NULL;

    do
    {
        // All memory UEs should be customer viewable. Normally, this would be
        // done by setting the threshold to 1, but we do not want to mask UEs
        // on the first occurrence.
        i_sc.service_data->SetServiceCall();

        CenMembufDataBundle * membdb = getMembufDataBundle( i_membChip );
        mbaChip = membdb->getMbaChip( i_mbaPos );
        if ( NULL == mbaChip )
        {
            PRDF_ERR( PRDF_FUNC"getMbaChip() returned NULL" );
            l_rc = FAIL; break;
        }

        CenAddr addr;
        l_rc = getCenReadAddr( i_membChip, i_mbaPos, READ_UE_ADDR, addr );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"getCenReadAddr() failed" );
            break;
        }

        // Add address to UE table.
        CenMbaDataBundle * mbadb = getMbaDataBundle( mbaChip );
        mbadb->iv_ueTable.addEntry( UE_TABLE::FETCH_UE, addr );

        // Callout the rank.
        MemoryMru memmru ( mbaChip->GetChipHandle(), addr.getRank(),
                           MemoryMruData::CALLOUT_RANK );
        i_sc.service_data->SetCallout( memmru );

    } while (0);

    // Add ECC capture data for FFDC.
    if ( NULL != mbaChip )
        CenMbaCaptureData::addMemEccData( mbaChip, i_sc );

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_membChip=0x%08x i_mbaPos=%d",
                  i_membChip->GetId(), i_mbaPos );
        CalloutUtil::defaultError( i_sc );
    }

    return SUCCESS; // Intentionally return SUCCESS for this plugin

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Define the plugins for memory ECC errors.
#define PLUGIN_FETCH_ECC_ERROR( TYPE, MBA ) \
int32_t AnalyzeFetch##TYPE##MBA( ExtensibleChip * i_membChip, \
                                 STEP_CODE_DATA_STRUCT & i_sc ) \
{ \
    return AnalyzeFetch##TYPE( i_membChip, i_sc, MBA ); \
} \
PRDF_PLUGIN_DEFINE( Membuf, AnalyzeFetch##TYPE##MBA );

PLUGIN_FETCH_ECC_ERROR( Nce, 0 )
PLUGIN_FETCH_ECC_ERROR( Nce, 1 )
PLUGIN_FETCH_ECC_ERROR( Rce, 0 )
PLUGIN_FETCH_ECC_ERROR( Rce, 1 )
PLUGIN_FETCH_ECC_ERROR( Ue,  0 )
PLUGIN_FETCH_ECC_ERROR( Ue,  1 )

#undef PLUGIN_FETCH_ECC_ERROR

// Define the plugins for memory MPE errors.
#define PLUGIN_MEMORY_MPE_ERROR( MBA, RANK ) \
int32_t AnalyzeFetchMpe##MBA##_##RANK( ExtensibleChip * i_membChip, \
                                       STEP_CODE_DATA_STRUCT & i_sc ) \
{ \
    return AnalyzeMpe( i_membChip, i_sc, MBA, RANK, true ); \
} \
PRDF_PLUGIN_DEFINE( Membuf, AnalyzeFetchMpe##MBA##_##RANK ); \
\
int32_t AnalyzeMaintMpe##MBA##_##RANK( ExtensibleChip * i_membChip, \
                                       STEP_CODE_DATA_STRUCT & i_sc ) \
{ \
    return AnalyzeMpe( i_membChip, i_sc, MBA, RANK, false ); \
} \
PRDF_PLUGIN_DEFINE( Membuf, AnalyzeMaintMpe##MBA##_##RANK );

PLUGIN_MEMORY_MPE_ERROR( 0, 0 )
PLUGIN_MEMORY_MPE_ERROR( 0, 1 )
PLUGIN_MEMORY_MPE_ERROR( 0, 2 )
PLUGIN_MEMORY_MPE_ERROR( 0, 3 )
PLUGIN_MEMORY_MPE_ERROR( 0, 4 )
PLUGIN_MEMORY_MPE_ERROR( 0, 5 )
PLUGIN_MEMORY_MPE_ERROR( 0, 6 )
PLUGIN_MEMORY_MPE_ERROR( 0, 7 )

PLUGIN_MEMORY_MPE_ERROR( 1, 0 )
PLUGIN_MEMORY_MPE_ERROR( 1, 1 )
PLUGIN_MEMORY_MPE_ERROR( 1, 2 )
PLUGIN_MEMORY_MPE_ERROR( 1, 3 )
PLUGIN_MEMORY_MPE_ERROR( 1, 4 )
PLUGIN_MEMORY_MPE_ERROR( 1, 5 )
PLUGIN_MEMORY_MPE_ERROR( 1, 6 )
PLUGIN_MEMORY_MPE_ERROR( 1, 7 )

#undef PLUGIN_MEMORY_MPE_ERROR

} // end namespace Membuf

} // end namespace PRDF
