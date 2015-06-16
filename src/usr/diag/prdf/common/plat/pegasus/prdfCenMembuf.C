/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMembuf.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
            switch ( i_sc.service_data->getSecondaryAttnType() )
            {
                case CHECK_STOP:
                    l_memcFir = i_membChip->getRegister("MEM_CHIPLET_CS_FIR");
                    // mba1 CS: bits 7, 8, 10, 13
                    l_checkBits = 0x01A40000;
                    break;
                case RECOVERABLE:
                    l_memcFir = i_membChip->getRegister("MEM_CHIPLET_RE_FIR");
                    // mba1 RE: bits 5, 6, 8, 11
                    l_checkBits = 0x06900000;
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
                                i_sc.service_data->getSecondaryAttnType() );
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

        CenMbaCaptureData::addMemChipletFirRegs( i_mbChip, cd );
    }

    // Check for a Centaur Checkstop
    do
    {
        // Skip if we're already analyzing a unit checkstop
        if ( i_sc.service_data->GetFlag(ServiceDataCollector::UNIT_CS) )
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
        i_sc.service_data->SetFlag(ServiceDataCollector::UNIT_CS);
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
 * @brief  MBSECCFIR[0:7] - Fetch Mark Placed Event (MPE).
 * @param  i_membChip A Centaur chip.
 * @param  i_sc       The step code data struct.
 * @param  i_mbaPos   The MBA position.
 * @param  i_rank     The target rank.
 * @return SUCCESS
 */
int32_t AnalyzeFetchMpe( ExtensibleChip * i_membChip,
                         STEP_CODE_DATA_STRUCT & i_sc,
                         uint32_t i_mbaPos, uint8_t i_rank )
{
    #define PRDF_FUNC "[AnalyzeFetchMpe] "

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
        TargetHandle_t mbaTrgt = mbaChip->GetChipHandle();

        CenAddr addr;
        l_rc = getCenReadAddr( i_membChip, i_mbaPos, READ_MPE_ADDR, addr );
        if ( SUCCESS != l_rc )
        {
           PRDF_ERR( PRDF_FUNC "getCenReadAddr() failed" );
           break;
        }

        // If the address does not match the rank that reported the attention,
        // there are multiple MPE attentions and the address was overwritten.
        // In this case, add an invalid dummy address to the UE table.
        if ( addr.getRank().getMaster() != i_rank )
        {
            addr = CenAddr( i_rank, 0, 0xffffffff, 0xffffffff, 0xffffffff );
        }

        mbadb->iv_ueTable.addEntry( UE_TABLE::FETCH_MPE, addr );

        // Get the current mark in hardware.
        CenRank rank ( addr.getRank() );
        CenMark mark;
        l_rc = mssGetMarkStore( mbaTrgt, rank, mark );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetMarkStore() failed");
            break;
        }

        if ( !mark.getCM().isValid() )
        {
            PRDF_ERR( PRDF_FUNC "FIR bit set but no valid chip mark" );
            l_rc = FAIL; break;
        }

        // Callout the mark.
        CalloutUtil::calloutMark( mbaTrgt, rank, mark, i_sc );

        // Tell TD controller to handle VCM event.
        l_rc = mbadb->iv_tdCtlr.handleTdEvent( i_sc, rank,
                                               CenMbaTdCtlrCommon::VCM_EVENT );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "handleTdEvent() failed." );
            break;
        }

    } while (0);

    // Add ECC capture data for FFDC.
    if ( NULL != mbaChip )
        CenMbaCaptureData::addMemEccData( mbaChip, i_sc );

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed: i_membChip=0x%08x i_mbaPos=%d i_rank=%d",
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
                uint16_t dramTh, hrTh, dimmTh;
                l_rc = getMnfgMemCeTh( mbaChip, rank, dramTh, hrTh, dimmTh );
                if ( SUCCESS != l_rc )
                {
                    PRDF_ERR( PRDF_FUNC "getMnfgMemCeTh() failed: rank=m%ds%d",
                              rank.getMaster(), rank.getSlave() );
                    break;
                }

                // Get counts from CE table.
                uint32_t dramCount, hrCount, dimmCount;
                mbadb->iv_ceTable.getMnfgCounts( addr.getRank(), symbol,
                                                 dramCount, hrCount,
                                                 dimmCount );

                if ( dramTh < dramCount )
                {
                    i_sc.service_data->AddSignatureList( mbaTrgt,
                                                         PRDFSIG_MnfgDramCte );
                    i_sc.service_data->SetServiceCall();
                    doTps = true;
                }
                else if ( hrTh < hrCount )
                {
                    i_sc.service_data->AddSignatureList( mbaTrgt,
                                                         PRDFSIG_MnfgHrCte );
                    i_sc.service_data->SetServiceCall();
                    doTps = true;
                }
                else if ( dimmTh < dimmCount )
                {
                    i_sc.service_data->AddSignatureList( mbaTrgt,
                                                         PRDFSIG_MnfgDimmCte );
                    i_sc.service_data->SetServiceCall();
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
                    i_sc.service_data->SetServiceCall();
                    doTps = true;
                }
                else if ( 0 != (CenMbaCeTable::ENTRY_TH_REACHED & ceTableRc) )
                {
                    i_sc.service_data->AddSignatureList( mbaTrgt,
                                                         PRDFSIG_MnfgEntryCte );

                    // There is a single entry threshold and no other threshold
                    // has been met. This is a potential flooding issue, so make
                    // the DIMM callout predictive.
                    i_sc.service_data->SetServiceCall();
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
        CenMbaCaptureData::addMemEccData( mbaChip, i_sc );

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
        CenMbaCaptureData::addMemEccData( mbaChip, i_sc );

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
            PRDF_ERR( PRDF_FUNC "getMbaChip() returned NULL" );
            l_rc = FAIL; break;
        }

        CenAddr addr;
        l_rc = getCenReadAddr( i_membChip, i_mbaPos, READ_UE_ADDR, addr );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "getCenReadAddr() failed" );
            break;
        }
        CenRank rank = addr.getRank();

        // Add address to UE table.
        CenMbaDataBundle * mbadb = getMbaDataBundle( mbaChip );
        mbadb->iv_ueTable.addEntry( UE_TABLE::FETCH_UE, addr );

        // Callout the rank.
        MemoryMru memmru ( mbaChip->GetChipHandle(), rank,
                           MemoryMruData::CALLOUT_RANK );
        i_sc.service_data->SetCallout( memmru );

        if ( CHECK_STOP != i_sc.service_data->getPrimaryAttnType() )
        {
            // Add a TPS request to the TD queue and ban any further TPS
            // requests for this rank.
            l_rc = mbadb->iv_tdCtlr.handleTdEvent( i_sc, rank,
                                                  CenMbaTdCtlrCommon::TPS_EVENT,
                                                  true );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleTdEvent() failed: rank=m%ds%d",
                          rank.getMaster(), rank.getSlave() );
                // We are not adding break here as we still want to do lmbGard
                // If you want to add any code after this which depends on
                // result of handleTdEvent result, add the code judicially.
            }

            #if !defined(__HOSTBOOT_MODULE) || defined(__HOSTBOOT_RUNTIME)
            // Send lmb gard message to hypervisor.
            int32_t lmbRc =  DEALLOC::lmbGard( mbaChip, addr );
            if ( SUCCESS != lmbRc )
            {
                PRDF_ERR( PRDF_FUNC "lmbGard() failed" );
                l_rc = lmbRc; break;
            }
            #endif
        }

    } while (0);

    // Add ECC capture data for FFDC.
    if ( NULL != mbaChip )
        CenMbaCaptureData::addMemEccData( mbaChip, i_sc );

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
 * @fn ClearMbsSecondaryBits
 * @brief Clears MBS secondary Fir bits which may come up because of primary
 *        MBS/MBI FIR bits.
 * @param  i_chip       The Centaur chip.
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
        SCAN_COMM_REGISTER_CLASS * mbsFir = i_chip->getRegister("MBSFIR");
        SCAN_COMM_REGISTER_CLASS * mbsFirMask =
                                        i_chip->getRegister("MBSFIR_MASK");
        SCAN_COMM_REGISTER_CLASS * mbsFirAnd =
                                        i_chip->getRegister("MBSFIR_AND");
        l_rc = mbsFir->Read();
        l_rc |= mbsFirMask->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MBSFIR/MBSFIR_MASK read failed"
                     "for 0x%08x", i_chip->GetId());
            break;
        }

        mbsFirAnd->setAllBits();

        if ( mbsFir->IsBitSet(26)
             && mbsFir->IsBitSet(9) && ( ! mbsFirMask->IsBitSet(9)))
        {
            mbsFirAnd->ClearBit(26);
        }

        if( mbsFir->IsBitSet(3) ||  mbsFir->IsBitSet(4) )
        {
            SCAN_COMM_REGISTER_CLASS * mbiFir = i_chip->getRegister("MBIFIR");
            SCAN_COMM_REGISTER_CLASS * mbiFirMask =
                                            i_chip->getRegister("MBIFIR_MASK");
            l_rc = mbiFir->Read();
            l_rc |= mbiFirMask->Read();
            if ( SUCCESS != l_rc )
            {
                // Do not break from here, just print error trace.
                // If there are other secondary bits ( e.g. 26, 27 ),
                // we want to clear them.
                PRDF_ERR( PRDF_FUNC "MBIFIR/MASK read failed"
                         "for 0x%08x", i_chip->GetId());
            }
            else if ( mbiFir->IsBitSet( 0 ) && ( ! mbiFirMask->IsBitSet( 0 )) )
            {
                mbsFirAnd->ClearBit(3);
                mbsFirAnd->ClearBit(4);
            }
        }

        l_rc = mbsFirAnd->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MBSFIR_AND write failed"
                     "for 0x%08x", i_chip->GetId());
            break;
        }

    }while( 0 );
    return SUCCESS;

    #undef PRDF_FUNC
} PRDF_PLUGIN_DEFINE( Membuf, ClearMbsSecondaryBits );

//------------------------------------------------------------------------------

/**
 * @fn ClearMbaCalSecondaryBits
 * @brief Clears MBACAL secondary Fir bits which may come up because of MBSFIR
 * @param  i_chip       The Centaur chip.
 * @param  i_sc         ServiceDataColector.
 * @return SUCCESS.

 */
int32_t ClearMbaCalSecondaryBits( ExtensibleChip * i_chip,
                                  STEP_CODE_DATA_STRUCT & i_sc  )
{
    #define PRDF_FUNC "[ClearMbaCalSecondaryBits ] "
    int32_t l_rc = SUCCESS;

    do
    {
        SCAN_COMM_REGISTER_CLASS * mbsFir = i_chip->getRegister("MBSFIR");
        SCAN_COMM_REGISTER_CLASS * mbsFirMask =
                                        i_chip->getRegister("MBSFIR_MASK");
        l_rc = mbsFir->Read();
        l_rc |= mbsFirMask->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MBSFIR/MBSFIR_MASK read failed"
                     "for 0x%08x", i_chip->GetId());
            break;
        }

        CenMembufDataBundle * membdb = getMembufDataBundle( i_chip );

        for( uint32_t i = 0; i < MAX_MBA_PER_MEMBUF; i++ )
        {
            ExtensibleChip * mbaChip = membdb->getMbaChip(i);
            if ( NULL == mbaChip ) continue;

            SCAN_COMM_REGISTER_CLASS * mbaCalFir =
                                mbaChip->getRegister("MBACALFIR");

            if( SUCCESS != mbaCalFir->Read() )
            {
                // Do not break. Just print error trace and look for
                // other MBA.
                PRDF_ERR( PRDF_FUNC "MBACALFIR read failed"
                         "for 0x%08x", mbaChip->GetId());
                continue;
            }

            if( !( mbaCalFir->IsBitSet( 10 ) || mbaCalFir->IsBitSet( 14 ) ))
                continue;

            SCAN_COMM_REGISTER_CLASS * mbaCalAndFir =
                                mbaChip->getRegister("MBACALFIR_AND");

            mbaCalAndFir->setAllBits();

            mbaCalAndFir->ClearBit(10);
            mbaCalAndFir->ClearBit(14);

            l_rc = mbaCalAndFir->Write();
            if ( SUCCESS != l_rc )
            {
                // Do not break. Just print error trace and look for
                // other MBA.
                PRDF_ERR( PRDF_FUNC "MBACALFIR_AND write failed"
                              "for 0x%08x", mbaChip->GetId());
            }
        }

    }while( 0 );

    return SUCCESS;
    #undef PRDF_FUNC

} PRDF_PLUGIN_DEFINE( Membuf, ClearMbaCalSecondaryBits );

//------------------------------------------------------------------------------

/**
 * @fn MaskMbsSecondaryBits
 * @brief Mask MBS secondary Fir bits which may come up because of L4 UE.
 * @param  i_chip       The Centaur chip.
 * @param  i_sc         ServiceDataColector.
 * @return SUCCESS.
 */
int32_t MaskMbsSecondaryBits( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc  )
{
    #define PRDF_FUNC "[MaskMbsSecondaryBits] "

    int32_t l_rc = SUCCESS;
    do
    {
        SCAN_COMM_REGISTER_CLASS * mbsFirMaskOr =
                                        i_chip->getRegister("MBSFIR_MASK_OR");
        mbsFirMaskOr->SetBit(27);
        l_rc = mbsFirMaskOr->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MBSFIR_MASK_OR write failed"
                     "for 0x%08x", i_chip->GetId());
            break;
        }

    }while( 0 );

    return SUCCESS;
    #undef PRDF_FUNC

} PRDF_PLUGIN_DEFINE( Membuf, MaskMbsSecondaryBits );

//------------------------------------------------------------------------------

/**
 * @fn MaskMbaCalSecondaryBits
 * @brief Mask MBACAL secondary Fir bits which may come up because of L4 UE.
 * @param  i_chip       The Centaur chip.
 * @param  i_sc         ServiceDataColector.
 * @return SUCCESS.
 */
int32_t MaskMbaCalSecondaryBits( ExtensibleChip * i_chip,
                                 STEP_CODE_DATA_STRUCT & i_sc  )
{
    #define PRDF_FUNC "[MaskMbaCalSecondaryBits ] "
    int32_t l_rc = SUCCESS;

    do
    {
        CenMembufDataBundle * membdb = getMembufDataBundle( i_chip );

        for( uint32_t i = 0; i < MAX_MBA_PER_MEMBUF; i++ )
        {
            ExtensibleChip * mbaChip = membdb->getMbaChip(i);
            if ( NULL == mbaChip ) continue;

            SCAN_COMM_REGISTER_CLASS * mbaCalFirMaskOr =
                                mbaChip->getRegister("MBACALFIR_MASK_OR");

            mbaCalFirMaskOr->SetBit(9);
            mbaCalFirMaskOr->SetBit(15);
            l_rc = mbaCalFirMaskOr->Write();
            if ( SUCCESS != l_rc )
            {
                // Do not break. Just print error trace and look for
                // other MBA.
                PRDF_ERR( PRDF_FUNC "MBACALFIR_MASK_OR write failed"
                         "for 0x%08x", mbaChip->GetId());
            }
        }
    }while( 0 );

    return SUCCESS;
    #undef PRDF_FUNC

} PRDF_PLUGIN_DEFINE( Membuf, MaskMbaCalSecondaryBits );

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
 * @brief   When not in MNFG mode, clear the service call flag so that
 *          thresholding will still be done, but no visible error log committed.
 * @param   i_chip Centaur chip
 * @param   i_sc   Step code data struct
 * @returns SUCCESS always
 */
int32_t ClearServiceCallFlag( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    if ( i_sc.service_data->IsAtThreshold() && !mfgMode() )
    {
        i_sc.service_data->ClearFlag(ServiceDataCollector::SERVICE_CALL);
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Membuf, ClearServiceCallFlag );

//------------------------------------------------------------------------------

/**
 * @brief   Captures trapped address for L4 cache ECC errors.
 * @param   i_mbChip Centaur chip
 * @param   i_sc     Step code data struct
 * @returns SUCCESS always
 * @note    This function also reset ECC trapped address regsiters so that HW
 *          can capture address for next L4 ecc error.
 */
int32_t CaptureL4CacheErr( ExtensibleChip * i_mbChip,
                           STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[CaptureL4CacheErr] "
    do
    {
        i_mbChip->CaptureErrorData( i_sc.service_data->GetCaptureData(),
                                    Util::hashString( "L4CacheErr" ) );

        // NOTE: FW should write on MBCELOG so that HW can capture
        // address for next L4 CE error.

        // NOTE: Line delete feature for L4 cache may not be available during
        // P8. But if it is incorporated in P8, we need to make sure following
        // should be the order of events:
        // 1. Capture group of registers associated with group L4CacheErr
        // 2. do L4 line delete.
        // 3. clear register MBCELOG

        // If we clear register MBCELOG before doing line delete, it is possible
        // that hardware procedures shall run into erroneous scenarios. One
        // probable order of events from PRDF's perspective which can cause
        // this is below:
        // 1. Receives an attention due to failure at cache address X.
        // 2. captures all relevant register including MBCELOG.
        // 3. cleares MBCELOG - i.e. failed address info is lost. HW populates
        //    this register with another L4 CE address say Y.
        // 4. requestes HWP for line delete operation on address X but it
        //    actually  deletes Y. It's because MBCELOG now contains address Y.

        SCAN_COMM_REGISTER_CLASS * mbcelogReg =
                                i_mbChip->getRegister("MBCELOG");
        mbcelogReg->clearAllBits();

        if ( SUCCESS != mbcelogReg->Write() )
        {
            PRDF_ERR( PRDF_FUNC "MBCELOG write failed for 0x%08x",
                      i_mbChip->GetId());
            break;
        }
    }while( 0 );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Membuf, CaptureL4CacheErr );

//------------------------------------------------------------------------------

/**
 * @brief   Checks DD level. If DD1, implements the DD1 callout actions for
 *          MBSFIR bit 30.
 * @param   i_membChip Centaur chip
 * @param   i_sc       Step code data struct
 * @returns SUCCESS if DD1, FAIL otherwise
 */
int32_t mbsfirBit30_dd1( ExtensibleChip * i_membChip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = FAIL;
    TargetHandle_t l_membTrgt = i_membChip->GetChipHandle();
    if(0x20 > getChipLevel(l_membTrgt))
    {
        i_sc.service_data->SetCallout(l_membTrgt, MRU_MED);
        ClearServiceCallFlag(i_membChip, i_sc);
        i_sc.service_data->SetErrorSig( PRDFSIG_MbsFir_30_DD1Signature );
        l_rc = SUCCESS;
    }

    return l_rc;
}
PRDF_PLUGIN_DEFINE( Membuf, mbsfirBit30_dd1 );

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
PLUGIN_FETCH_ECC_ERROR( Ue,  0 )
PLUGIN_FETCH_ECC_ERROR( Ue,  1 )

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

// Define the plugins for memory MPE errors.
#define PLUGIN_MEMORY_MPE_ERROR( MBA, RANK ) \
int32_t AnalyzeFetchMpe##MBA##_##RANK( ExtensibleChip * i_membChip, \
                                       STEP_CODE_DATA_STRUCT & i_sc ) \
{ \
    return AnalyzeFetchMpe( i_membChip, i_sc, MBA, RANK ); \
} \
PRDF_PLUGIN_DEFINE( Membuf, AnalyzeFetchMpe##MBA##_##RANK );

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
