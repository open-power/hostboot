/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMembuf.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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
#include <prdfCenMbaThresholds.H>
#include <prdfCenMembufDataBundle.H>
#include <prdfCenMembufExtraSig.H>
#include <prdfLaneRepair.H>
#include <prdfCenMemUtils.H>
#if !defined(__HOSTBOOT_MODULE) || defined(__HOSTBOOT_RUNTIME)
  #include <prdfCenMbaDynMemDealloc_rt.H>
#endif
#include <prdfMemEccAnalysis.H>

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

        CenMbaCaptureData::addMemChipletFirRegs( i_mbChip, cd );
    }

    // Check for a Centaur Checkstop
    do
    {
        // Skip if we're already analyzing a unit checkstop
        if ( i_sc.service_data->IsUnitCS() )
            break;

        // Skip if we're analyzing a special attention.
        // This is a required for a rare scenario when Centaur CS bit comes
        // up after attention has called PRD and PRD was still at start of
        // analysis.
        if ( SPECIAL == i_sc.service_data->getPrimaryAttnType() )
            break;

        // MCIFIR[31] is not always reliable if the unit CS originated on the
        // Centaur. This is due to packets not getting forwarded to the MCS.
        // Instead, check for non-zero GLOBAL_CS_FIR.

        SCAN_COMM_REGISTER_CLASS * fir = i_mbChip->getRegister("GLOBAL_CS_FIR");
        o_rc = fir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read GLOBAL_CS_FIR on 0x%08x",
                      i_mbChip->GetId() );
            break;
        }

        if ( fir->BitStringIsZero() ) break; // No unit checkstop

        // Set Unit checkstop flag
        i_sc.service_data->setFlag(ServiceDataCollector::UNIT_CS);
        i_sc.service_data->SetThresholdMaskId(0);

        // Set the cause attention type
        i_sc.service_data->setSecondaryAttnType(UNIT_CS);

        // Indicate that cleanup is required.
        mbdb->iv_doChnlFailCleanup = true;

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
    int32_t l_rc;

    // In hostboot, we need to clear associated bits in the MCIFIR bits.
    l_rc = MemUtils::mcifirCleanup( i_mbChip, i_sc );
    if( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "mcifirCleanup() failed");
    }

    l_rc = MemUtils::chnlCsCleanup( i_mbChip, i_sc );
    if( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "ChnlCsCleanup() failed");
    }

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
 * @brief  MBSECCFIR[0:7] - Mailine MPE.
 * @param  i_chip MEMBUF chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
#define PLUGIN_FETCH_MPE_ERROR( POS, RANK ) \
int32_t AnalyzeFetchMpe##POS_##RANK( ExtensibleChip * i_chip, \
                                     STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    ExtensibleChip * mbaChip = getConnectedChild( i_chip, TYPE_MBA, POS ); \
    PRDF_ASSERT( nullptr != mbaChip ); \
    MemEcc::analyzeFetchMpe<TYPE_MBA, MbaDataBundle *>( mbaChip, RANK, io_sc );\
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( Membuf, AnalyzeFetchMpe##POS_##RANK );

PLUGIN_FETCH_MPE_ERROR( 0, 0 )
PLUGIN_FETCH_MPE_ERROR( 0, 1 )
PLUGIN_FETCH_MPE_ERROR( 0, 2 )
PLUGIN_FETCH_MPE_ERROR( 0, 3 )
PLUGIN_FETCH_MPE_ERROR( 0, 4 )
PLUGIN_FETCH_MPE_ERROR( 0, 5 )
PLUGIN_FETCH_MPE_ERROR( 0, 6 )
PLUGIN_FETCH_MPE_ERROR( 0, 7 )

PLUGIN_FETCH_MPE_ERROR( 1, 0 )
PLUGIN_FETCH_MPE_ERROR( 1, 1 )
PLUGIN_FETCH_MPE_ERROR( 1, 2 )
PLUGIN_FETCH_MPE_ERROR( 1, 3 )
PLUGIN_FETCH_MPE_ERROR( 1, 4 )
PLUGIN_FETCH_MPE_ERROR( 1, 5 )
PLUGIN_FETCH_MPE_ERROR( 1, 6 )
PLUGIN_FETCH_MPE_ERROR( 1, 7 )

#undef PLUGIN_FETCH_MPE_ERROR

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
            PRDF_ERR( PRDF_FUNC "getMbaChip() returned NULL" );
            l_rc = FAIL; break;
        }
        TargetHandle_t mbaTrgt = mbaChip->GetChipHandle();

        CenAddr addr;
        l_rc = getCenReadAddr( i_membChip, i_mbaPos, READ_NCE_ADDR, addr );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "getCenReadAddr() failed" );
            break;
        }
        CenRank rank = addr.getRank();

        if ( 0x20 > getChipLevel(i_membChip->GetChipHandle()) )
        {
            // There is a bug in DD1.x where the value of MBSEVR cannot be
            // trusted. The workaround is too complicated for its value so
            // callout the rank instead.
            MemoryMru memmru ( mbaTrgt, rank, MemoryMruData::CALLOUT_RANK );
            i_sc.service_data->SetCallout( memmru );
        }
        else // DD2.0+
        {
            // Get the failing symbol
            const char * reg_str = (0 == i_mbaPos) ? "MBA0_MBSEVR"
                                                   : "MBA1_MBSEVR";
            SCAN_COMM_REGISTER_CLASS * reg = i_membChip->getRegister(reg_str);
            l_rc = reg->Read();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "Read() failed on %s", reg_str );
                break;
            }

            uint8_t galois = reg->GetBitFieldJustified( 40, 8 );
            uint8_t mask   = reg->GetBitFieldJustified( 32, 8 );

            CenSymbol symbol = CenSymbol::fromGalois( mbaTrgt, rank, galois,
                                                      mask );
            if ( !symbol.isValid() )
            {
                PRDF_ERR( PRDF_FUNC "Failed to create symbol: galois=0x%02x "
                          "mask=0x%02x", galois, mask );
                break;
            }

            // Check if this symbol is on any of the spares.
            CenSymbol sp0, sp1, ecc;
            l_rc = mssGetSteerMux( mbaTrgt, rank, sp0, sp1, ecc );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed. HUID: 0x%08x "
                        "rank: %d", getHuid(mbaTrgt), rank.getMaster() );
                break;
            }
            if ( (sp0.isValid() && (sp0.getDram() == symbol.getDram())) ||
                 (sp1.isValid() && (sp1.getDram() == symbol.getDram())) )
            {
                symbol.setDramSpared();
            }
            if ( ecc.isValid() && (ecc.getDram() == symbol.getDram()) )
            {
                symbol.setEccSpared();
            }

            // Add the DIMM to the callout list
            MemoryMru memmru ( mbaTrgt, rank, symbol );
            i_sc.service_data->SetCallout( memmru, MRU_MEDA );

            // Add to CE table
            CenMbaDataBundle * mbadb = getMbaDataBundle( mbaChip );
            uint32_t ceTableRc = mbadb->iv_ceTable.addEntry( addr, symbol );
            bool doTps = false;

            // Check MNFG thresholds, if needed.
            if ( mfgMode() )
            {
                // Get the MNFG CE thresholds.
                uint32_t dramTh, hrTh, dimmTh;
                getMnfgMemCeTh( mbaChip, rank, dramTh, hrTh, dimmTh );

                // Get counts from CE table.
                uint32_t dramCount, hrCount, dimmCount;
                mbadb->iv_ceTable.getMnfgCounts( addr.getRank(), symbol,
                                                 dramCount, hrCount,
                                                 dimmCount );

                if ( dramTh < dramCount )
                {
                    i_sc.service_data->AddSignatureList( mbaTrgt,
                                                         PRDFSIG_MnfgDramCte );
                    i_sc.service_data->setServiceCall();
                    doTps = true;
                }
                else if ( hrTh < hrCount )
                {
                    i_sc.service_data->AddSignatureList( mbaTrgt,
                                                         PRDFSIG_MnfgHrCte );
                    i_sc.service_data->setServiceCall();
                    doTps = true;
                }
                else if ( dimmTh < dimmCount )
                {
                    i_sc.service_data->AddSignatureList( mbaTrgt,
                                                         PRDFSIG_MnfgDimmCte );
                    i_sc.service_data->setServiceCall();
                    doTps = true;
                }
                else if ( 0 != (CenMbaCeTable::TABLE_FULL & ceTableRc) )
                {
                    i_sc.service_data->AddSignatureList( mbaTrgt,
                                                         PRDFSIG_MnfgTableFull);

                    // The table is full and no other threshold has been met.
                    // We are in a state where we may never hit a MNFG
                    // threshold. Callout all memory behind the MBA. Also, since
                    // the counts are all over the place, there may be a problem
                    // with the MBA. So call it out as well.
                    MemoryMru all_mm ( mbaTrgt, rank,
                                       MemoryMruData::CALLOUT_ALL_MEM );
                    i_sc.service_data->SetCallout( all_mm,  MRU_MEDA );
                    i_sc.service_data->SetCallout( mbaTrgt, MRU_MEDA );
                    i_sc.service_data->setServiceCall();
                    doTps = true;
                }
                else if ( 0 != (CenMbaCeTable::ENTRY_TH_REACHED & ceTableRc) )
                {
                    i_sc.service_data->AddSignatureList( mbaTrgt,
                                                         PRDFSIG_MnfgEntryCte );

                    // There is a single entry threshold and no other threshold
                    // has been met. This is a potential flooding issue, so make
                    // the DIMM callout predictive.
                    i_sc.service_data->setServiceCall();
                    doTps = true;
                }
            }
            else // field
            {
                doTps = ( CenMbaCeTable::NO_TH_REACHED != ceTableRc );
            }

            // Initiate a TPS procedure, if needed.
            if ( doTps )
            {
                // If a MNFG threshold has been reached (predictive callout), we
                // will still try to start TPS just in case MNFG disables the
                // termination policy.

                // Will not be able to do TPS during hostboot. Note that we will
                // still call handleTdEvent() so we can get the trace statement
                // indicating TPS was requested during Hostboot.

                l_rc = mbadb->iv_tdCtlr.handleTdEvent( i_sc, rank,
                                                CenMbaTdCtlrCommon::TPS_EVENT );
                if ( SUCCESS != l_rc )
                {
                    PRDF_ERR( PRDF_FUNC "handleTdEvent() failed: rank=m%ds%d",
                              rank.getMaster(), rank.getSlave() );
                    break;
                }
            }
        }

    } while (0);

    // Add ECC capture data for FFDC.
    if ( NULL != mbaChip )
        MemCaptureData::addEccData<TYPE_MBA>( mbaChip, i_sc );

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed: i_membChip=0x%08x i_mbaPos=%d",
                  i_membChip->GetId(), i_mbaPos );
        CalloutUtil::defaultError( i_sc );
    }

    return SUCCESS; // Intentionally return SUCCESS for this plugin

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

/**
 * @brief  Fetch Retry CE / Prefetch UE Errors.
 * @param  i_membChip A Centaur chip.
 * @param  i_sc         The step code data struct.
 * @param  i_mbaPos     The MBA position.
 * @param  i_isRceError True for RCE error false otherwise.
 * @return SUCCESS
 */
int32_t AnalyzeFetchRcePue( ExtensibleChip * i_membChip,
                            STEP_CODE_DATA_STRUCT & i_sc, uint32_t i_mbaPos,
                            bool i_isRceError )
{
    #define PRDF_FUNC "[AnalyzeFetchRcePue] "

    int32_t l_rc = SUCCESS;

    ExtensibleChip * mbaChip = NULL;

    do
    {
        CenMembufDataBundle * membdb = getMembufDataBundle( i_membChip );
        mbaChip = membdb->getMbaChip( i_mbaPos );
        if ( NULL == mbaChip )
        {
            PRDF_ERR( PRDF_FUNC "getMbaChip() returned NULL" );
            l_rc = FAIL; break;
        }

        CenMbaDataBundle * mbadb = getMbaDataBundle( mbaChip );

        // WORKAROUND: Since an RCE starts as a UE, it's address is trapped in
        // MBUER (note: UE fir bit not set at this point). But since multiple
        // addresses are retried (not just the failing address), MBRCER will
        // contain the last address retried, and not necessarily the address
        // that started out with the UE.

        CenAddr addr;
        l_rc = getCenReadAddr( i_membChip, i_mbaPos, READ_UE_ADDR, addr );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "getCenReadAddr() failed" );
            break;
        }
        CenRank rank = addr.getRank();

        // Callout the rank.
        MemoryMru memmru ( mbaChip->GetChipHandle(), rank,
                           MemoryMruData::CALLOUT_RANK );
        i_sc.service_data->SetCallout( memmru );

        // Add an entry to the RCE table.
        if ( mbadb->iv_rceTable.addEntry(rank, i_sc) )
        {
            // Add a TPS request to the queue TD queue.
            l_rc = mbadb->iv_tdCtlr.handleTdEvent( i_sc, rank,
                                             CenMbaTdCtlrCommon::TPS_EVENT );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleTdEvent() failed." );
                break;
            }
        }

    } while (0);

    // Add ECC capture data for FFDC.
    if ( NULL != mbaChip )
        MemCaptureData::addEccData<TYPE_MBA>( mbaChip, i_sc );

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed: i_membChip=0x%08x i_mbaPos=%d "
                  "i_isRceError=%c", i_membChip->GetId(), i_mbaPos,
                  i_isRceError ? 'T' : 'F' );
        CalloutUtil::defaultError( i_sc );
    }

    return SUCCESS; // Intentionally return SUCCESS for this plugin

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

/**
 * @brief  MBSECCFIR[19] - Mainline UE.
 * @param  i_chip MEMBUF chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
#define PLUGIN_FETCH_UE_ERROR( POS ) \
int32_t AnalyzeFetchUe##POS( ExtensibleChip * i_chip, \
                             STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    ExtensibleChip * mbaChip = getConnectedChild( i_chip, TYPE_MBA, POS ); \
    PRDF_ASSERT( nullptr != mbaChip ); \
    MemEcc::analyzeFetchUe<TYPE_MBA, MbaDataBundle *>( mbaChip, io_sc ); \
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( Membuf, AnalyzeFetchUe##POS );

PLUGIN_FETCH_UE_ERROR( 0 )
PLUGIN_FETCH_UE_ERROR( 1 )

#undef PLUGIN_FETCH_UE_ERROR

//------------------------------------------------------------------------------

/**
 * @brief Handles MCS Channel fail bits, if they exist.
 *
 * @param  i_membChip   The Centaur chip.
 * @param  i_sc         ServiceDataColector.
 *
 * @return SUCCESS if MCS channel fail is present and properly
 *         handled, FAIL otherwise.
 */
int32_t handleMcsChnlCs( ExtensibleChip * i_membChip,
                    STEP_CODE_DATA_STRUCT & i_sc  )
{
    #define PRDF_FUNC "[handleMcsChnlCs] "

    // We will return FAIL from this function if MCS channel fail  bits
    // are not set. If MCS channel fail bits are set, we will try to analyze
    // Mcs. If MCS is not analyzed properly, we will return FAIL.
    // This will trigger rule code to execute alternate resolution.

    int32_t l_rc = SUCCESS;
    do
    {
        CenMembufDataBundle * mbdb = getMembufDataBundle( i_membChip );
        ExtensibleChip * mcsChip =    mbdb->getMcsChip();
        if( NULL == mcsChip )
        {
            l_rc = FAIL;
            break;
        }

        SCAN_COMM_REGISTER_CLASS * mciFir = mcsChip->getRegister("MCIFIR");
        SCAN_COMM_REGISTER_CLASS * mciFirMask =
                                        mcsChip->getRegister("MCIFIR_MASK");

        l_rc = mciFir->Read();
        l_rc |= mciFirMask->Read();

        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MCIFIR/MCIFIR_MASK read failed for 0x%08x",
                      mcsChip->GetId());
            break;
        }

        // If any of MCS channel fail bit is set, we will analyze
        // MCS. It is safe to do hard coded check as channel fail
        // bits are hard wired and and they can not change without HW
        // change.
        // bits 0,1, 6, 8, 9, 22, 23, 40 are channel fail bits.
        uint64_t chnlCsBitsMask = 0xC2C0030000800000ull;
        uint64_t mciFirBits     = mciFir->GetBitFieldJustified(0, 64);
        uint64_t mciFirMaskBits = mciFirMask->GetBitFieldJustified(0, 64);

        if ( mciFirBits & ~mciFirMaskBits & chnlCsBitsMask )
        {
            l_rc = mcsChip->Analyze( i_sc,
                        i_sc.service_data->getSecondaryAttnType() );

            if( SUCCESS == l_rc ) break;
        }

        l_rc = FAIL;

    }while( 0 );

    return l_rc;
    #undef PRDF_FUNC

} PRDF_PLUGIN_DEFINE( Membuf, handleMcsChnlCs );

//------------------------------------------------------------------------------

/**
 * @brief Handles MBACALFIR RCD Parity error bits, if they exist on a single mba
 *
 * @param  i_membChip   The Centaur chip.
 * @param  i_sc         ServiceDataCollector.
 * @param  i_mbaPos     The MBA position.
 *
 * @return SUCCESS if MBACALFIR Parity error is present and properly
 *         handled, FAIL otherwise.
 */
int32_t handleSingleMbaCalParityErr( ExtensibleChip * i_membChip,
                                     STEP_CODE_DATA_STRUCT & i_sc,
                                     uint32_t i_mbaPos)
{
    #define PRDF_FUNC "[handleSingleMbaCalParityErr] "

    int32_t l_rc = SUCCESS;

    CenMembufDataBundle * mbdb = getMembufDataBundle( i_membChip );

    do
    {
        ExtensibleChip * mbaChip = mbdb->getMbaChip(i_mbaPos);
        if ( NULL == mbaChip )
        {
            l_rc = FAIL;
            break;
        }

        SCAN_COMM_REGISTER_CLASS * mbaCalFir =
            mbaChip->getRegister("MBACALFIR");
        SCAN_COMM_REGISTER_CLASS * mbaCalMask =
            mbaChip->getRegister("MBACALFIR_MASK");

        l_rc  = mbaCalFir->Read();
        l_rc |= mbaCalMask->Read();

        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MBACALFIR/MBACALFIR_MASK read failed for"
                    "0x%08x", mbaChip->GetId());
            break;
        }

        // If any of the MBACALFIR parity error bits are set, we will
        // analyze the MBA.
        // bits 4 and 7 are parity error bits
        bool bit4  = mbaCalFir->IsBitSet(4);
        bool mask4 = mbaCalMask->IsBitSet(4);

        bool bit7  = mbaCalFir->IsBitSet(7);
        bool mask7 = mbaCalMask->IsBitSet(7);

        if ( ( bit4 && !mask4 ) || ( bit7 && !mask7 ) )
        {
            l_rc = mbaChip->Analyze( i_sc,
                    i_sc.service_data->getSecondaryAttnType() );
            if ( SUCCESS == l_rc ) break;
        }

        l_rc = FAIL;

    }while(0);

    return l_rc;
    #undef PRDF_FUNC

} PRDF_PLUGIN_DEFINE( Membuf, handleSingleMbaCalParityErr );

//------------------------------------------------------------------------------

/**
 * @brief  MBSFIR[4] - Internal Timeout error.
 * @param  i_mbChip The Centaur chip
 * @param  i_sc     Step code data struct
 * @return Non-SUCCESS if analysis fails. SUCCESS otherwise.
 */
int32_t internalTimeout( ExtensibleChip * i_mbChip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[internalTimeout] "

    int32_t o_rc = SUCCESS;

    do
    {
        // First, check if there are any MBACALFIR parity errors.
        for ( uint32_t i = 0; i < MAX_MBA_PER_MEMBUF; i++)
        {
            o_rc = handleSingleMbaCalParityErr( i_mbChip, i_sc, i );

            // If SUCCESS is returned, then there was a parity error and
            // analysis was successful.
            if ( SUCCESS == o_rc ) break;
        }
        if ( SUCCESS == o_rc ) break; // nothing more to do.

        // Next, check if there was an MBSFIR external timeout.
        SCAN_COMM_REGISTER_CLASS * fir = i_mbChip->getRegister("MBSFIR");
        o_rc  = fir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "failed to read MBSFIR on 0x%08x",
                      i_mbChip->GetId() );
            break;
        }

        if ( fir->IsBitSet(3) )
        {
            if ( CHECK_STOP == i_sc.service_data->getPrimaryAttnType() )
            {
                // In this case, we do not want the internal timeout to be
                // blamed as the root cause of the checkstop. So move onto the
                // next FIR bit.
                o_rc = PRD_SCAN_COMM_REGISTER_ZERO;
            }
            else
            {
                // Make the callout of the external timeout error.
                i_sc.service_data->SetCallout( LEVEL2_SUPPORT,
                                               MRU_MED, NO_GARD );
            }
        }
        else
        {
            // The internal timeout error is on by itself.
            i_sc.service_data->SetCallout( i_mbChip->GetChipHandle(), MRU_MED );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC

} PRDF_PLUGIN_DEFINE( Membuf, internalTimeout );

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

#undef PLUGIN_FETCH_ECC_ERROR

// Handling for RCE and prefetch UE is similar.
// So use common macro and function ( AnalyzeFetchRcePue ).

#define PLUGIN_FETCH_RCE_PREUE_ERROR( TYPE, MBA, IS_RCE ) \
int32_t AnalyzeFetch##TYPE##MBA( ExtensibleChip * i_membChip, \
                                 STEP_CODE_DATA_STRUCT & i_sc ) \
{ \
    return AnalyzeFetchRcePue( i_membChip, i_sc, MBA, IS_RCE ); \
} \
PRDF_PLUGIN_DEFINE( Membuf, AnalyzeFetch##TYPE##MBA );

// This is bit inefficient. 1st and 3rd argument have 1 to 1
// mapping. But to keep macro expansion simple, using extra argument.
PLUGIN_FETCH_RCE_PREUE_ERROR( Rce, 0, true )
PLUGIN_FETCH_RCE_PREUE_ERROR( Rce, 1, true )
PLUGIN_FETCH_RCE_PREUE_ERROR( PreUe, 0, false )
PLUGIN_FETCH_RCE_PREUE_ERROR( PreUe, 1, false )

#undef PLUGIN_FETCH_RCE_PREUE_ERROR

// Define the plugins for RCD parity error memory UE side-effects
#define PLUGIN_RCD_PARITY_UE_SIDEEFFECTS( MBA ) \
int32_t handleSingleMbaCalParityErr##MBA( ExtensibleChip * i_membChip, \
                                          STEP_CODE_DATA_STRUCT & i_sc) \
{ \
    return handleSingleMbaCalParityErr( i_membChip, i_sc, MBA ); \
} \
PRDF_PLUGIN_DEFINE( Membuf, handleSingleMbaCalParityErr##MBA );

PLUGIN_RCD_PARITY_UE_SIDEEFFECTS ( 0 )
PLUGIN_RCD_PARITY_UE_SIDEEFFECTS ( 1 )

//------------------------------------------------------------------------------

int32_t calloutInterface_dmi( ExtensibleChip * i_membChip,
                              STEP_CODE_DATA_STRUCT & io_sc )
{
    CalloutUtil::calloutBusInterface( i_membChip, MRU_LOW );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Membuf, calloutInterface_dmi );

} // end namespace Membuf

} // end namespace PRDF
