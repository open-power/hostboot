/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfCenMbaIplCeStats.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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

/** @file  prdfCenMbaIplCeStats.C
 *  @brief Contains IPL CE related code.
 */

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfEnums.H>
#include <prdfErrlUtil.H>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPfa5Data.h>
#include <prdf_service_codes.H>

// Pegasus includes
#include <prdfCenMbaExtraSig.H>
#include <prdfCenMbaIplCeStats.H>
#include <prdfCenMbaThresholds.H>
#include <prdfCenMemUtils.H>
#include <prdfMemoryMru.H>
#include <prdfPlatCalloutUtil.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
using namespace HWAS;

//------------------------------------------------------------------------------

void CenMbaIplCeStats::banAnalysis( const CenRank & i_rank )
{

    for ( uint8_t i = 0; i < MAX_PORT_PER_MBA; i++ )
    {
        HalfRankKey banKey = { i_rank, i };
        iv_bannedAnalysis[banKey] = true;
    }
}

//------------------------------------------------------------------------------

int32_t CenMbaIplCeStats::banAnalysis( const CenRank & i_rank,
                                       uint8_t i_portSlct )
{
    int32_t o_rc = SUCCESS;

    do
    {
        if ( i_portSlct >= MAX_PORT_PER_MBA  )
        {
            PRDF_ERR("[banAnalysis] i_portSlct (0x%02x) is invalid",
                      i_portSlct );
            o_rc = FAIL;
            break;
        }

        HalfRankKey banKey = { i_rank, i_portSlct };
        iv_bannedAnalysis[banKey] = true;

    } while (0);

    return o_rc;
}

//------------------------------------------------------------------------------

int32_t CenMbaIplCeStats::collectStats( const CenRank & i_stopRank )
{
    #define PRDF_FUNC "[CenMbaIplCeStats::collectStats] "
    int32_t o_rc = SUCCESS;
    do
    {
        MemUtils::MaintSymbols symData; CenSymbol junk;
        o_rc = MemUtils::collectCeStats( iv_mbaChip, i_stopRank, symData, junk);
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "MemUtils::collectCeStats() failed. MBA:0X%08X",
                      getHuid( iv_mbaChip->GetChipHandle() ) );
            break;
        }

        // if size of stats collected is zero, it may mean some symbol
        // has gone beyond maximum value. But this is only valid for DD1
        // and has a very low probability. So ignoring this case.

        for ( uint32_t i = 0; i < symData.size(); i++ )
        {
            uint8_t dimmSlct = i_stopRank.getDimmSlct();
            uint8_t dram = symData[i].symbol.getDram();
            uint8_t portSlct = symData[i].symbol.getPortSlct();

            // Check if analysis is banned.
            HalfRankKey banKey = { i_stopRank, portSlct };

            // Check if the rank has already been banned. Note that [] will
            // create an entry if one does not exist, so used find() instead to
            // check for existence in the map.
            if ( iv_bannedAnalysis.end() != iv_bannedAnalysis.find(banKey) )
                continue;

            // Update iv_ceSymbols with the new symbol data.
            SymbolKey symkey = { symData[i].symbol };
            iv_ceSymbols.push_back (symkey );

            // Increment the soft CEs per DRAM.
            DramKey dramKey = { i_stopRank, dram, portSlct };
            iv_dramMap[dramKey] += symData[i].count;

            // Increment the soft CEs per half rank.
            HalfRankKey rankKey = { i_stopRank, portSlct };
            iv_rankMap[rankKey] += symData[i].count;

            // In case of dimm select, rank select does not matter
            CenRank dimmRank( dimmSlct << DIMM_SLCT_PER_MBA );
            // Increment the soft CEs per half dimm select.
            HalfRankKey dsKey = { dimmRank, portSlct };
            iv_dsMap[dsKey] += symData[i].count;
        }

    } while (0);

    // We have to clear all stats before giving control back to MDIA..
    // This is done by setting up MBSTRQ[53] bit
    // We are doing cleanup in TdController code,
    // So not clearing up stats here.
    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaIplCeStats::analyzeStats( bool & o_callOutsMade )
{
    #define PRDF_FUNC "CenMbaIplCeStats::analyzeStats "
    int32_t o_rc = SUCCESS;

    o_callOutsMade = false;

    do
    {
        TargetHandle_t mbaTrgt = iv_mbaChip->GetChipHandle();

        o_rc = calloutCePerDram( o_callOutsMade );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC " calloutCePerDram() failed. MBA:0X%08X",
                      getHuid( mbaTrgt ) );
            break;
        }

        o_rc = calloutCePerRank( o_callOutsMade );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "calloutCePerRank() failed. MBA:0X%08X",
                      getHuid( mbaTrgt ) );
            break;
        }

        o_rc = calloutCePerDs( o_callOutsMade );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC " calloutCePerDs() failed. MBA:0X%08X",
                      getHuid( mbaTrgt ) );
            break;
        }

    } while (0);

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaIplCeStats::calloutHardCes( const CenRank & i_stopRank )
{
    #define PRDF_FUNC "[CenMbaIplCeStats::calloutHardCes] "
    TargetHandle_t mbaTrgt = iv_mbaChip->GetChipHandle();
    int32_t o_rc = SUCCESS;
    do
    {
        MemUtils::MaintSymbols symData; CenSymbol junk;
        o_rc = MemUtils::collectCeStats( iv_mbaChip, i_stopRank, symData, junk);
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "MemUtils::collectCeStats() failed. MBA:0X%08X",
                      getHuid( iv_mbaChip->GetChipHandle() ) );
            break;
        }

        for ( uint32_t i = 0; i < symData.size(); i++ )
        {
            uint8_t portSlct = symData[i].symbol.getPortSlct();

            // Check if analysis is banned.
            HalfRankKey banKey = { i_stopRank, portSlct };

            bool& isBanned = iv_bannedAnalysis[banKey];

            if ( isBanned )
                continue;

            // At this point a hard CE was found, callout the symbol.
            MemoryMru memMru ( mbaTrgt, symData[i].symbol.getRank(),
                               symData[i].symbol );

            // We are creating and committing error log here. It is different
            // from rest of attention flow. We could have set the callout
            // values in sdc but it would have created confusion in ffdc if
            // we also get vcm/ue at same time.
            errlHndl_t l_errl = NULL;

            PRDF_CREATE_ERRL( l_errl,
                              ERRL_SEV_PREDICTIVE,
                              ERRL_ETYPE_NOT_APPLICABLE,
                              SRCI_ERR_INFO,
                              SRCI_NO_ATTR,
                              PRDF_MNFG_IPL_CE_ANALYSIS,
                              LIC_REFCODE,
                              PRDF_DETECTED_FAIL_HARDWARE,
                              getHuid( mbaTrgt ),
                              0, PRDFSIG_MnfgIplHardCE, 0);
            addMruAndCommitErrl( memMru, l_errl);

            // Ban the half rank.
            isBanned = true;
        }
    }while(0);
    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaIplCeStats::calloutCePerDram( bool & o_callOutsMade )
{
    #define PRDF_FUNC "[CenMbaIplCeStats::calloutCePerDram] "
    int32_t o_rc = SUCCESS;

    TargetHandle_t mbaTrgt = iv_mbaChip->GetChipHandle();

    for ( CePerDramMap::iterator dramIter = iv_dramMap.begin();
          dramIter != iv_dramMap.end(); dramIter++ )
    {
        // First, check if this half rank is banned from analysis.
        HalfRankKey banKey = { dramIter->first.rank,
                               dramIter->first.portSlct };

        // Check if the rank has already been banned. Note that [] will create
        // the an entry if one does not exist, so used find() instead to check
        // for existence in the map.
        if ( iv_bannedAnalysis.end() != iv_bannedAnalysis.find(banKey) )
            continue;

        // Get the CEs per DRAM threshold.
        uint16_t dramTh, junk0, junk1;
        o_rc = getMnfgMemCeTh( iv_mbaChip, dramIter->first.rank, dramTh,
                                       junk0, junk1 );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMnfgMemCeTh() failed. MBA:0x%08X",
                      getHuid( mbaTrgt ) );
            break;
        }

        // Now, check if a threshold has been reached. If not, continue to the
        // next entry in iv_dsMap.
        if ( dramIter->second <= dramTh )
            continue;

        // At this point a threshold has been reached. Callout a single symbol
        // found in this dram.
        for ( CESymbols::iterator symIter = iv_ceSymbols.begin();
              symIter != iv_ceSymbols.end(); symIter++ )
        {
            if ( (dramIter->first.rank == symIter->symbol.getRank() ) &&
                 (dramIter->first.dram == symIter->symbol.getDram() ) )
            {
                MemoryMru memMru ( mbaTrgt, symIter->symbol.getRank() ,
                                   symIter->symbol );

                errlHndl_t l_errl = NULL;

                PRDF_CREATE_ERRL( l_errl,
                              ERRL_SEV_PREDICTIVE,
                              ERRL_ETYPE_NOT_APPLICABLE,
                              SRCI_ERR_INFO,
                              SRCI_NO_ATTR,
                              PRDF_MNFG_IPL_CE_ANALYSIS,
                              LIC_REFCODE,
                              PRDF_DETECTED_FAIL_HARDWARE,
                              getHuid( mbaTrgt ),
                              0, PRDFSIG_MnfgIplDramCTE, 0);

                addMruAndCommitErrl( memMru, l_errl);

                // Ban the half rank.
                iv_bannedAnalysis[banKey] = true;
                o_callOutsMade = true;

                // Only one symbol needs to be called out, so exit on first
                // occurrence.
                break;
            }
        }
    }
    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaIplCeStats::calloutCePerRank( bool & o_callOutsMade )
{
    #define PRDF_FUNC "[CenMbaIplCeStats::calloutCePerRank] "
    int32_t o_rc = SUCCESS;

    TargetHandle_t mbaTrgt = iv_mbaChip->GetChipHandle();

    for ( CePerHalfRankMap::iterator rankIter = iv_rankMap.begin();
          rankIter != iv_rankMap.end(); rankIter++ )
    {
        // First, check if this half rank is banned from analysis.
        HalfRankKey banKey = { rankIter->first.rank,
                               rankIter->first.portSlct };

        // Check if the rank has already been banned. Note that [] will create
        // the an entry if one does not exist, so used find() instead to check
        // for existence in the map.
        if ( iv_bannedAnalysis.end() != iv_bannedAnalysis.find(banKey) )
            continue;

        // Get the CEs per rank threshold.
        uint16_t junk0, rankTh, junk1;
        o_rc = getMnfgMemCeTh( iv_mbaChip, rankIter->first.rank, junk0,
                               rankTh, junk1 );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMnfgMemCeTh() failed. MBA:0x%08X",
                      getHuid( mbaTrgt ) );
            break;
        }

        // Now, check if a threshold has been reached. If not, continue to the
        // next entry in iv_rankMap.
        if ( rankIter->second <= rankTh )
            continue;

        // At this point a threshold has been reached. Callout a single symbol
        // found in this rank.
        for ( CESymbols::iterator symIter = iv_ceSymbols.begin();
              symIter != iv_ceSymbols.end(); symIter++ )
        {
            if ( (rankIter->first.rank == symIter->symbol.getRank() ) &&
                 (rankIter->first.portSlct ==
                                        symIter->symbol.getPortSlct()) )
            {
                MemoryMru memMru ( mbaTrgt, symIter->symbol.getRank() ,
                                   symIter->symbol );

                errlHndl_t l_errl = NULL;

                PRDF_CREATE_ERRL( l_errl,
                              ERRL_SEV_PREDICTIVE,
                              ERRL_ETYPE_NOT_APPLICABLE,
                              SRCI_ERR_INFO,
                              SRCI_NO_ATTR,
                              PRDF_MNFG_IPL_CE_ANALYSIS,
                              LIC_REFCODE,
                              PRDF_DETECTED_FAIL_HARDWARE,
                              getHuid( mbaTrgt ),
                              0, PRDFSIG_MnfgIplRankCTE, 0);

                addMruAndCommitErrl( memMru, l_errl);
                // Ban the half rank.
                iv_bannedAnalysis[banKey] = true;
                o_callOutsMade = true;

                // Only one symbol needs to be called out, so exit on first
                // occurrence.
                break;
            }
        }
    }
    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaIplCeStats::calloutCePerDs( bool & o_callOutsMade )
{
    #define PRDF_FUNC "[CenMbaIplCeStats::calloutCePerDs] "
    int32_t o_rc = SUCCESS;

    TargetHandle_t mbaTrgt = iv_mbaChip->GetChipHandle();

    for ( CePerHalfDsMap::iterator dsIter = iv_dsMap.begin();
          dsIter != iv_dsMap.end(); dsIter++ )
    {
        // First, check if this half dimm select is banned from analysis.
        HalfRankKey banKey = { dsIter->first.rank,
                               dsIter->first.portSlct };

        // Check if the rank has already been banned. Note that [] will create
        // the an entry if one does not exist, so used find() instead to check
        // for existence in the map.
        if ( iv_bannedAnalysis.end() != iv_bannedAnalysis.find(banKey) )
            continue;

        // Get the CEs per dimm select threshold.
        uint16_t junk0, junk1, dsTh;
        o_rc = getMnfgMemCeTh( iv_mbaChip, dsIter->first.rank, junk0,
                               junk1, dsTh );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMnfgMemCeTh() failed. MBA:0x%08X",
                      getHuid( mbaTrgt ) );
            break;
        }

        // Now, check if a threshold has been reached. If not, continue to the
        // next entry in iv_dsMap.
        if ( dsIter->second <= dsTh )
            continue;

        // At this point a threshold has been reached. Callout a single symbol
        // found in this dimm select.
        for ( CESymbols::iterator symIter = iv_ceSymbols.begin();
              symIter != iv_ceSymbols.end(); symIter++ )
        {
            if ( (dsIter->first.rank.getDimmSlct()  ==
                                symIter->symbol.getRank().getDimmSlct() )
                && (dsIter->first.portSlct ==
                                          symIter->symbol.getPortSlct()) )
            {
                MemoryMru memMru ( mbaTrgt, symIter->symbol.getRank() ,
                                   symIter->symbol );

                errlHndl_t l_errl = NULL;
                PRDF_CREATE_ERRL( l_errl,
                              ERRL_SEV_PREDICTIVE,
                              ERRL_ETYPE_NOT_APPLICABLE,
                              SRCI_ERR_INFO,
                              SRCI_NO_ATTR,
                              PRDF_MNFG_IPL_CE_ANALYSIS,
                              LIC_REFCODE,
                              PRDF_DETECTED_FAIL_HARDWARE,
                              getHuid(mbaTrgt),
                              0, PRDFSIG_MnfgIplDsCTE, 0);

                addMruAndCommitErrl( memMru, l_errl);
                // Ban the half dimm select.
                iv_bannedAnalysis[banKey] = true;
                o_callOutsMade = true;

                // Only one symbol needs to be called out, so exit on first
                // occurrence.
                break;
            }
        }
    }
    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void CenMbaIplCeStats::addMruAndCommitErrl( const MemoryMru & i_memmru,
                                            errlHndl_t i_errl )
{
    // Add MemoryMru callouts and FFDC
    CalloutUtil::calloutMemoryMru( i_errl, i_memmru,
                                   SRCI_PRIORITY_HIGH,
                                   HWAS::DELAYED_DECONFIG,
                                   HWAS::GARD_Predictive );

    // Add traces
    i_errl->collectTrace( PRDF_COMP_NAME, 512 );

    // Commit the error log
    ERRORLOG::errlCommit( i_errl, PRDF_COMP_ID );
}

} // end namespace PRDF
