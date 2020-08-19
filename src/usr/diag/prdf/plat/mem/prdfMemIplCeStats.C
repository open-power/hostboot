/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemIplCeStats.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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

/** @file  prdfMemIplCeStats.C
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

// Mem includes
#include <prdfMemExtraSig.H>
#include <prdfMemIplCeStats.H>
#include <prdfParserUtils.H>
#include <prdfMemThresholds.H>
#include <prdfMemUtils.H>
#include <prdfMemoryMru.H>
#include <prdfMemCaptureData.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
using namespace HWAS;
using namespace PARSERUTILS;

//------------------------------------------------------------------------------

template<>
void MemIplCeStats<TYPE_OCMB_CHIP>::banAnalysis( uint8_t i_dimmSlct,
                                                 uint8_t i_portSlct )
{
    PRDF_ASSERT( i_dimmSlct < MAX_DIMM_PER_PORT );
    PRDF_ASSERT( 0 == i_portSlct );

    DimmKey banKey = { i_dimmSlct, i_portSlct };
    iv_bannedAnalysis[banKey] = true;
}

//------------------------------------------------------------------------------

template<>
void MemIplCeStats<TYPE_OCMB_CHIP>::banAnalysis( uint8_t i_dimmSlct )
{
    // Only one DIMM per DIMM select on OCMB_CHIP.
    banAnalysis( i_dimmSlct, 0 );
}

//------------------------------------------------------------------------------

template<TYPE T>
int32_t MemIplCeStats<T>::collectStats( const MemRank & i_stopRank )
{
    #define PRDF_FUNC "[MemIplCeStats::collectStats] "
    int32_t o_rc = SUCCESS;
    do
    {
        MemUtils::MaintSymbols symData; MemSymbol junk;
        o_rc = MemUtils::collectCeStats<T>( iv_chip, i_stopRank, symData,
                                            junk );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "MemUtils::collectCeStats failed. chip:0X%08X",
                      getHuid( iv_chip->getTrgt() ) );
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

            // Check if analysis is banned
            DimmKey banKey = { dimmSlct, portSlct };
            if ( iv_bannedAnalysis[banKey] ) continue;

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
            MemRank dimmRank( dimmSlct << DIMM_SLCT_PER_PORT );
            // Increment the soft CEs per half dimm select.
            HalfRankKey dsKey = { dimmRank, portSlct };
            iv_dsMap[dsKey] += symData[i].count;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TYPE T>
bool MemIplCeStats<T>::analyzeStats()
{
    bool tmp1 = calloutCePerDram();
    bool tmp2 = calloutCePerRank();
    bool tmp3 = calloutCePerDs();

    return ( tmp1 || tmp2 || tmp3 );
}

//------------------------------------------------------------------------------

template<TYPE T>
int32_t MemIplCeStats<T>::calloutHardCes( const MemRank & i_stopRank )
{
    #define PRDF_FUNC "[MemIplCeStats::calloutHardCes] "
    TargetHandle_t trgt = iv_chip->getTrgt();
    int32_t o_rc = SUCCESS;
    do
    {
        MemUtils::MaintSymbols symData; MemSymbol junk;
        o_rc = MemUtils::collectCeStats<T>( iv_chip, i_stopRank, symData,
                                            junk );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "MemUtils::collectCeStats() failed.chip:0X%08X",
                      getHuid( iv_chip->getTrgt() ) );
            break;
        }

        for ( uint32_t i = 0; i < symData.size(); i++ )
        {
            uint8_t portSlct = symData[i].symbol.getPortSlct();

            // Check if analysis is banned.
            DimmKey banKey = { i_stopRank.getDimmSlct(), portSlct };
            if ( iv_bannedAnalysis[banKey] ) continue;

            // At this point a hard CE was found, callout the symbol.
            MemoryMru memMru ( trgt, symData[i].symbol.getRank(),
                               symData[i].symbol );

            // We are creating and committing error log here. It is different
            // from rest of attention flow. We could have set the callout
            // values in sdc but it would have created confusion in ffdc if
            // we also get vcm/ue at same time.
            errlHndl_t l_errl = nullptr;

            PRDF_CREATE_ERRL( l_errl,
                              ERRL_SEV_PREDICTIVE,
                              ERRL_ETYPE_NOT_APPLICABLE,
                              SRCI_ERR_INFO,
                              SRCI_NO_ATTR,
                              PRDF_MNFG_IPL_CE_ANALYSIS,
                              LIC_REFCODE,
                              PRDF_DETECTED_FAIL_HARDWARE,
                              getHuid( trgt ),
                              0, PRDFSIG_MnfgIplHardCE, 0);
            addMruAndCommitErrl( memMru, l_errl);

            iv_bannedAnalysis[banKey] = true; // ban this DIMM
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TYPE T>
bool MemIplCeStats<T>::calloutCePerDram()
{
    bool o_callOutsMade = false;

    TargetHandle_t trgt = iv_chip->getTrgt();

    for ( typename CePerDramMap::iterator dramIter = iv_dramMap.begin();
          dramIter != iv_dramMap.end(); dramIter++ )
    {
        // First, check if this half rank is banned from analysis
        DimmKey banKey = { dramIter->first.rank.getDimmSlct(),
                           dramIter->first.portSlct };
        if ( iv_bannedAnalysis[banKey] ) continue;

        // Get the CEs per DRAM threshold.
        uint32_t dramTh = 1, junk0, junk1;
        getMnfgMemCeTh<T>( iv_chip, dramIter->first.rank, dramTh, junk0, junk1);

        // Now, check if a threshold has been reached. If not, continue to the
        // next entry in iv_dsMap.
        if ( dramIter->second <= dramTh )
            continue;

        // At this point a threshold has been reached. Callout a single symbol
        // found in this dram.
        for ( typename CESymbols::iterator symIter = iv_ceSymbols.begin();
              symIter != iv_ceSymbols.end(); symIter++ )
        {
            if ( (dramIter->first.rank == symIter->symbol.getRank() ) &&
                 (dramIter->first.dram == symIter->symbol.getDram() ) )
            {
                MemoryMru memMru ( trgt, symIter->symbol.getRank(),
                                   symIter->symbol );

                errlHndl_t l_errl = nullptr;

                PRDF_CREATE_ERRL( l_errl,
                              ERRL_SEV_PREDICTIVE,
                              ERRL_ETYPE_NOT_APPLICABLE,
                              SRCI_ERR_INFO,
                              SRCI_NO_ATTR,
                              PRDF_MNFG_IPL_CE_ANALYSIS,
                              LIC_REFCODE,
                              PRDF_DETECTED_FAIL_HARDWARE,
                              getHuid( trgt ),
                              0, PRDFSIG_MnfgIplDramCTE, 0);

                addMruAndCommitErrl( memMru, l_errl);

                iv_bannedAnalysis[banKey] = true; // ban this DIMM

                o_callOutsMade = true;

                // Only one symbol needs to be called out, so exit on first
                // occurrence.
                break;
            }
        }
    }

    return o_callOutsMade;
}

//------------------------------------------------------------------------------

template<TYPE T>
bool MemIplCeStats<T>::calloutCePerRank()
{
    bool o_callOutsMade = false;

    TargetHandle_t trgt = iv_chip->getTrgt();

    for ( typename CePerHalfRankMap::iterator rankIter = iv_rankMap.begin();
          rankIter != iv_rankMap.end(); rankIter++ )
    {
        // First, check if this half rank is banned from analysis
        DimmKey banKey = { rankIter->first.rank.getDimmSlct(),
                           rankIter->first.portSlct };
        if ( iv_bannedAnalysis[banKey] ) continue;

        // Get the CEs per rank threshold.
        uint32_t junk0, rankTh, junk1;
        getMnfgMemCeTh<T>( iv_chip, rankIter->first.rank, junk0, rankTh, junk1);

        // Now, check if a threshold has been reached. If not, continue to the
        // next entry in iv_rankMap.
        if ( rankIter->second <= rankTh )
            continue;

        // At this point a threshold has been reached. Callout a single symbol
        // found in this rank.
        for ( typename CESymbols::iterator symIter = iv_ceSymbols.begin();
              symIter != iv_ceSymbols.end(); symIter++ )
        {
            if ( (rankIter->first.rank == symIter->symbol.getRank()) &&
                 (rankIter->first.portSlct == symIter->symbol.getPortSlct()) )
            {
                MemoryMru memMru ( trgt, symIter->symbol.getRank(),
                                   symIter->symbol );

                errlHndl_t l_errl = nullptr;

                PRDF_CREATE_ERRL( l_errl,
                              ERRL_SEV_PREDICTIVE,
                              ERRL_ETYPE_NOT_APPLICABLE,
                              SRCI_ERR_INFO,
                              SRCI_NO_ATTR,
                              PRDF_MNFG_IPL_CE_ANALYSIS,
                              LIC_REFCODE,
                              PRDF_DETECTED_FAIL_HARDWARE,
                              getHuid( trgt ),
                              0, PRDFSIG_MnfgIplRankCTE, 0);

                addMruAndCommitErrl( memMru, l_errl);

                iv_bannedAnalysis[banKey] = true; // ban this DIMM

                o_callOutsMade = true;

                // Only one symbol needs to be called out, so exit on first
                // occurrence.
                break;
            }
        }
    }

    return o_callOutsMade;
}

//------------------------------------------------------------------------------

template<TYPE T>
bool MemIplCeStats<T>::calloutCePerDs()
{
    bool o_callOutsMade = false;

    TargetHandle_t trgt = iv_chip->getTrgt();

    for ( typename CePerHalfDsMap::iterator dsIter = iv_dsMap.begin();
          dsIter != iv_dsMap.end(); dsIter++ )
    {
        // First, check if this half fimm select is banned from analysis
        DimmKey banKey = { dsIter->first.rank.getDimmSlct(),
                           dsIter->first.portSlct };
        if ( iv_bannedAnalysis[banKey] ) continue;

        // Get the CEs per dimm select threshold.
        uint32_t junk0, junk1, dsTh;
        getMnfgMemCeTh<T>( iv_chip, dsIter->first.rank, junk0, junk1, dsTh );

        // Now, check if a threshold has been reached. If not, continue to the
        // next entry in iv_dsMap.
        if ( dsIter->second <= dsTh )
            continue;

        // At this point a threshold has been reached. Callout a single symbol
        // found in this dimm select.
        for ( typename CESymbols::iterator symIter = iv_ceSymbols.begin();
              symIter != iv_ceSymbols.end(); symIter++ )
        {
            if ( (dsIter->first.rank.getDimmSlct()  ==
                                symIter->symbol.getRank().getDimmSlct()) &&
                 (dsIter->first.portSlct == symIter->symbol.getPortSlct()) )
            {
                MemoryMru memMru ( trgt, symIter->symbol.getRank() ,
                                   symIter->symbol );

                errlHndl_t l_errl = nullptr;
                PRDF_CREATE_ERRL( l_errl,
                              ERRL_SEV_PREDICTIVE,
                              ERRL_ETYPE_NOT_APPLICABLE,
                              SRCI_ERR_INFO,
                              SRCI_NO_ATTR,
                              PRDF_MNFG_IPL_CE_ANALYSIS,
                              LIC_REFCODE,
                              PRDF_DETECTED_FAIL_HARDWARE,
                              getHuid(trgt),
                              0, PRDFSIG_MnfgIplDsCTE, 0);

                addMruAndCommitErrl( memMru, l_errl);

                iv_bannedAnalysis[banKey] = true; // ban this DIMM

                o_callOutsMade = true;

                // Only one symbol needs to be called out, so exit on first
                // occurrence.
                break;
            }
        }
    }

    return o_callOutsMade;
}

//------------------------------------------------------------------------------

template<TYPE T>
void MemIplCeStats<T>::addMruAndCommitErrl( const MemoryMru & i_memmru,
                                   errlHndl_t i_errl )
{
    // Add all parts to the error log.
    TargetHandleList partList = i_memmru.getCalloutList();
    for ( auto &it : partList )
    {
        i_errl->addHwCallout( it, SRCI_PRIORITY_HIGH, HWAS::DELAYED_DECONFIG,
                              HWAS::GARD_Predictive );
    }

    // Add the MemoryMru to the capture data.
    MemCaptureData::addExtMemMruData( i_memmru, i_errl );

    // Add traces
    i_errl->collectTrace( PRDF_COMP_NAME, 512 );

    // Commit the error log
    ERRORLOG::errlCommit( i_errl, PRDF_COMP_ID );
}

//------------------------------------------------------------------------------

// need these templates to avoid linker errors
template class MemIplCeStats<TYPE_OCMB_CHIP>;

} // end namespace PRDF
