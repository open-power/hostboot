/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTps_rt.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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

/** @file prdfMemTps_rt.C */

// Platform includes
#include <prdfCenMbaExtraSig.H>
#include <prdfMemDbUtils.H>
#include <prdfMemEccAnalysis.H>
#include <prdfMemExtraSig.H>
#include <prdfMemMark.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTdFalseAlarm.H>
#include <prdfMemTps.H>
#include <prdfP9McaExtraSig.H>
#include <prdfTargetServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

const uint8_t CE_REGS_PER_PORT = 9;
const uint8_t SYMBOLS_PER_CE_REG = 8;

static const char *mcbCeStatReg[CE_REGS_PER_PORT] =
                       {
                           "MCB_MBSSYMEC0", "MCB_MBSSYMEC1", "MCB_MBSSYMEC2",
                           "MCB_MBSSYMEC3", "MCB_MBSSYMEC4", "MCB_MBSSYMEC5",
                           "MCB_MBSSYMEC6", "MCB_MBSSYMEC7", "MCB_MBSSYMEC8"
                       };

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
TpsFalseAlarm * __getTpsFalseAlarmCounter( ExtensibleChip * i_chip );

template<>
TpsFalseAlarm * __getTpsFalseAlarmCounter<TYPE_MCA>( ExtensibleChip * i_chip )
{
    return getMcaDataBundle(i_chip)->getTpsFalseAlarmCounter();
}

template<>
TpsFalseAlarm * __getTpsFalseAlarmCounter<TYPE_MBA>( ExtensibleChip * i_chip )
{
    return getMbaDataBundle(i_chip)->getTpsFalseAlarmCounter();
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __getNextPhase( ExtensibleChip * i_chip, const MemRank & i_rank,
                     STEP_CODE_DATA_STRUCT & io_sc,
                     TdEntry::Phase & io_phase, uint32_t & o_signature )
{
    PRDF_ASSERT( TdEntry::Phase::TD_PHASE_0 == io_phase );

    // Only use phase 2 if the false alarm counter has exceeded threshold.
    // Otherwise, use phase 1.
    TpsFalseAlarm * faCounter = __getTpsFalseAlarmCounter<T>( i_chip );
    if ( faCounter->count(i_rank, io_sc) >= 1 )
    {
        io_phase    = TdEntry::Phase::TD_PHASE_2;
        o_signature = PRDFSIG_StartTpsPhase2;
    }
    else
    {
        io_phase    = TdEntry::Phase::TD_PHASE_1;
        o_signature = PRDFSIG_StartTpsPhase1;
    }
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
bool __badDqCount( MemUtils::MaintSymbols i_nibbleStats,
                   CeCount & io_badDqCount );

template<>
bool __badDqCount<TYPE_MCA>( MemUtils::MaintSymbols i_nibbleStats,
                             CeCount & io_badDqCount )
{
    bool badDqFound = false;

    for ( auto symData : i_nibbleStats )
    {
        // If one of the four symbols has a count of at least 8.
        if ( symData.count >= 8 )
        {
            // And the sum of the other three symbols is 1 or less.
            uint8_t sum = 0;
            for ( auto sumCheck : i_nibbleStats)
            {
                if ( !(symData.symbol == sumCheck.symbol) )
                {
                    // Check for overflow.
                    if ( (sum + sumCheck.count) > 0xFF )
                        sum = 0xFF;
                    else
                        sum += sumCheck.count;
                }
            }
            if ( sum <= 1 )
            {
                io_badDqCount.count++;
                io_badDqCount.symList.push_back(symData);
                badDqFound = true;
                break;
            }
        }
    }

    return badDqFound;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
bool __badChipCount( MemUtils::MaintSymbols i_nibbleStats,
                     CeCount & io_badChipCount );

template<>
bool __badChipCount<TYPE_MCA>( MemUtils::MaintSymbols i_nibbleStats,
                               CeCount & io_badChipCount )
{
    bool badChipFound = false;
    uint8_t nonZeroCount = 0;
    uint8_t minCountTwo = 0;
    uint8_t sum = 0;
    MemUtils::SymbolData highSym;

    for ( auto symData : i_nibbleStats )
    {
        // Check for overflow.
        if ( (sum + symData.count) > 0xFF )
            sum = 0xFF;
        else
            sum += symData.count;

        if ( symData.count > 0 )
            nonZeroCount++;
        if ( symData.count >= 2 )
            minCountTwo++;
        if ( symData.count > highSym.count )
            highSym = symData;
    }

    // If the total sum for all four symbols has a count of at least 5
    if ( sum >= 5 )
    {
        // And either:
        // 3 or more symbols have a non-zero value.
        // or 2 symbols, both with a minimum count of 2.
        if ( nonZeroCount >= 3 || minCountTwo >= 2 )
        {
            io_badChipCount.count++;
            io_badChipCount.symList.push_back(highSym);
            badChipFound = true;
        }
    }

    return badChipFound;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __sumAboveOneCount( MemUtils::MaintSymbols i_nibbleStats,
                         CeCount & io_sumAboveOneCount );

template<>
void __sumAboveOneCount<TYPE_MCA>( MemUtils::MaintSymbols i_nibbleStats,
                                   CeCount & io_sumAboveOneCount )
{
    uint8_t sum = 0;
    MemUtils::MaintSymbols symList;
    for ( auto symData : i_nibbleStats )
    {
        if ( symData.count > 0 )
        {
            if ( (sum + symData.count) > 0xFF )
                sum = 0xFF;
            else
                sum += symData.count;

            symList.push_back(symData);
        }
    }
    // If the sum is greater than 1
    if ( sum > 1 )
    {
        io_sumAboveOneCount.count++;
        for ( auto sym : symList )
        {
            io_sumAboveOneCount.symList.push_back(sym);
        }
    }
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __singleSymbolCount( MemUtils::MaintSymbols i_nibbleStats,
                          CeCount & io_singleSymCount );

template<>
void __singleSymbolCount<TYPE_MCA>( MemUtils::MaintSymbols i_nibbleStats,
                                    CeCount & io_singleSymCount )
{
    uint8_t count = 0;
    bool multNonZeroSyms = false;

    for ( auto symData : i_nibbleStats )
    {
        if ( symData.count > 0 )
        {
            if ( 0 != count )
            {
                // There are more than one symbol counts that are non-zero
                multNonZeroSyms = true;
                break;
            }
            count = symData.count;
        }
    }

    // If there is only one symbol with a non-zero count and that count > 1
    if ( count > 1 && !multNonZeroSyms )
        io_singleSymCount.count++;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __analyzeNibbleSyms( MemUtils::MaintSymbols i_nibbleStats,
    CeCount & io_badDqCount, CeCount & io_badChipCount,
    CeCount & io_sumAboveOneCount, CeCount & io_singleSymCount )
{

    do
    {
        // Check if this nibble has a bad dq.
        if ( __badDqCount<T>( i_nibbleStats, io_badDqCount ) )
            break;

        // Check if this nibble has a bad chip.
        if ( __badChipCount<T>( i_nibbleStats, io_badChipCount ) )
            break;

        // Check if this nibble is under threshold with a sum greater than 1.
        __sumAboveOneCount<T>( i_nibbleStats, io_sumAboveOneCount );

        // Check if this nibble is under threshold with only a single symbol
        // with a non-zero count, and that count is > 1.
        __singleSymbolCount<T>( i_nibbleStats, io_singleSymCount );

    }while(0);
}

//------------------------------------------------------------------------------

uint32_t __updateVpdSumAboveOne( CeCount i_sumAboveOneCount,
                                 MemDqBitmap & io_dqBitmap )
{

    #define PRDF_FUNC "[__updateVpdSumAboveOne] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // For nibbles under threshold with a sum greater than 1, update VPD
        // with it's non-zero symbols. This is so if we do TPS again, we'll
        // callout again even if the symbol counters change.
        for ( auto sym : i_sumAboveOneCount.symList )
        {
            o_rc = io_dqBitmap.setSymbol( sym.symbol );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "io_dqBitmap.setSymbol failed." );
                break;
            }
        }
    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <>
uint32_t TpsEvent<TYPE_MCA>::analyzeEccErrors( const uint32_t & i_eccAttns,
                                         STEP_CODE_DATA_STRUCT & io_sc,
                                         bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MCA>::analyzeEccErrors] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // If there was a UE.
        if ( i_eccAttns & MAINT_UE )
        {
            PRDF_TRAC( PRDF_FUNC "UE Detected: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintUE );

            // At this point we don't actually have an address for the UE. The
            // best we can do is get the address in which the command stopped.
            MemAddr addr;
            o_rc = getMemMaintAddr<TYPE_MCA>( iv_chip, addr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            o_rc = MemEcc::handleMemUe<TYPE_MCA>( iv_chip, addr,
                                                  UE_TABLE::SCRUB_UE, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemUe(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            // Because of the UE, any further TPS requests will likely have no
            // effect. So ban all subsequent requests.
            MemDbUtils::banTps<TYPE_MCA>( iv_chip, addr.getRank() );

            // Abort this procedure because additional repairs will likely
            // not help (also avoids complication of having UE and MPE at
            // the same time).
            o_done = true; break;
        }

        // If there was an IUE (MNFG only).
        if ( mfgMode() && (i_eccAttns & MAINT_IUE) )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintIUE );

            o_rc = MemEcc::handleMemIue<TYPE_MCA>( iv_chip, iv_rank, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemIue(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            // If service call is set, then IUE threshold was reached.
            if ( io_sc.service_data->queryServiceCall() )
            {
                PRDF_TRAC( PRDF_FUNC "IUE threshold detected: 0x%08x,0x%02x",
                           iv_chip->getHuid(), getKey() );

                // Abort this procedure because port failure will be triggered
                // after analysis is complete.
                o_done = true; break;
            }
        }

        // If there was an MPE.
        if ( i_eccAttns & MAINT_MPE )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintMPE );

            o_rc = MemEcc::handleMpe<TYPE_MCA>( iv_chip, iv_rank,
                                                UE_TABLE::SCRUB_MPE, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMpe<T>(0x%08x, 0x%02x) failed",
                          iv_chip->getHuid(), iv_rank.getKey() );
                break;
            }

            // Abort this procedure because the chip mark may have fixed the
            // symbol that triggered TPS
            o_done = true; break;
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_MCA>::handleFalseAlarm( STEP_CODE_DATA_STRUCT & io_sc )
{
    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                      PRDFSIG_TpsFalseAlarm );

    // Increase false alarm counter and check threshold.
    if ( __getTpsFalseAlarmCounter<TYPE_MCA>(iv_chip)->inc( iv_rank, io_sc) )
    {
        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                          PRDFSIG_TpsFalseAlarmTH );

        // Permanently mask mainline NCEs and TCEs
        getMcaDataBundle(iv_chip)->iv_maskMainlineNceTce = true;
    }

    return SUCCESS;
}

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_MCA>::analyzeCeSymbolCounts( CeCount i_badDqCount,
    CeCount i_badChipCount, CeCount i_sumAboveOneCount,
    CeCount i_singleSymCount, STEP_CODE_DATA_STRUCT & io_sc )
{

    #define PRDF_FUNC "[TpsEvent<TYPE_MCA>::analyzeCeSymbolCounts] "

    uint32_t o_rc = SUCCESS;

    do
    {
        bool tpsFalseAlarm = false;

        // Get the Bad DQ Bitmap.
        TargetHandle_t mcaTrgt = iv_chip->getTrgt();
        MemDqBitmap dqBitmap;

        o_rc = getBadDqBitmap( mcaTrgt, iv_rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap(0x%08x, 0x%02x) failed",
                      getHuid(mcaTrgt), iv_rank.getKey() );
            break;
        }

        // Get the symbol mark.
        MemMark symMark;
        o_rc = MarkStore::readSymbolMark<TYPE_MCA>( iv_chip, iv_rank, symMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readSymbolMark<TYPE_MCA>(0x%08x, 0x%02x) "
                      "failed", iv_chip->getHuid(), iv_rank.getKey() );
            break;
        }

        // Get the chip mark.
        MemMark chipMark;
        o_rc = MarkStore::readChipMark<TYPE_MCA>( iv_chip, iv_rank, chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark<TYPE_MCA>(0x%08x, 0x%02x) "
                      "failed", iv_chip->getHuid(), iv_rank.getKey() );
            break;
        }

        // If the bad DQ nibble count is 0 and the bad chip nibble count is 0.
        if ( 0 == i_badDqCount.count && 0 == i_badChipCount.count )
        {
            // There is nothing to repair. Any other non-zero counts are
            // considered acceptable noise.
            // Set false alarm flag to true.
            tpsFalseAlarm = true;
        }
        // If the bad DQ nibble count is 1 and the bad chip nibble count is 0.
        else if ( 1 == i_badDqCount.count && 0 == i_badChipCount.count )
        {
            // If the symbol mark is available.
            if ( !symMark.isValid() )
            {
                // If the sum above one nibble count is <= 1 or sum above one
                // nibble count == 2 and single sym nibble count == 2
                if ( (i_sumAboveOneCount.count <= 1) ||
                     (i_sumAboveOneCount.count == 2 &&
                      i_singleSymCount.count == 2) )
                {
                    // This means we have a potential future chip kill or
                    // TCE. Both are still correctable after a symbol mark
                    // is placed.
                    // Place a symbol mark on this bad DQ.
                    MemMark newSymMark( mcaTrgt, iv_rank,
                                        i_badDqCount.symList[0].symbol );
                    o_rc = MarkStore::writeSymbolMark<TYPE_MCA>( iv_chip,
                        iv_rank, newSymMark );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "writeSymbolMark(0x%08x,0x%02x) "
                                  "failed", iv_chip->getHuid(), getKey() );
                        break;
                    }

                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_TpsSymbolMark );

                    // Update VPD with the symbol mark.
                    o_rc = dqBitmap.setSymbol( i_badDqCount.symList[0].symbol );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "dqBitmap.setSymbol failed." );
                        break;
                    }
                }
                else
                {
                    // Placing a symbol mark risks a UE.
                    // For nibbles under threshold with a sum greater than 1,
                    // update VPD with it's non-zero symbols.
                    o_rc = __updateVpdSumAboveOne(i_sumAboveOneCount, dqBitmap);
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR(PRDF_FUNC "__updateVpdSumAboveOne() failed.");
                    }

                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_TpsSymUeRisk );

                    // Make the error log predictive.
                    io_sc.service_data->setServiceCall();

                    // Permanently mask mainline NCEs and TCEs.
                    getMcaDataBundle(iv_chip)->iv_maskMainlineNceTce = true;
                }
            }
            else
            {
                // Otherwise assume the symbol mark is fixing this bad DQ.
                // Set the false alarm flag to true.
                tpsFalseAlarm = true;
            }
        }
        // Else if bad DQ nibble count is 2 and bad chip nibble count is 0.
        else if ( 2 == i_badDqCount.count && 0 == i_badChipCount.count )
        {
            // Permanently mask mainline NCEs and TCEs.
            getMcaDataBundle(iv_chip)->iv_maskMainlineNceTce = true;

            // If the symbol mark is available.
            if ( !symMark.isValid() )
            {
                // If the sum above one nibble count is = 0 or sum above one
                // nibble count = 1 and single sym nibble count = 1
                if ( (i_sumAboveOneCount.count == 0) ||
                     (i_sumAboveOneCount.count == 1 &&
                      i_singleSymCount.count == 1) )
                {
                    // This means we have only one more potential bad DQ, which
                    // is correctable after a symbol mark is placed.
                    // Place a symbol mark on this bad DQ with the highest count
                    MemUtils::SymbolData highSym;
                    for ( auto sym : i_badDqCount.symList )
                    {
                        if ( sym.count > highSym.count )
                            highSym = sym;
                    }

                    MemMark newSymMark( mcaTrgt, iv_rank,
                                        highSym.symbol );
                    o_rc = MarkStore::writeSymbolMark<TYPE_MCA>( iv_chip,
                        iv_rank, newSymMark );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "writeSymbolMark(0x%08x,0x%02x) "
                                  "failed", iv_chip->getHuid(), getKey() );
                        break;
                    }

                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_TpsSymbolMark );

                    // Update VPD with both symbols.
                    for ( auto sym : i_badDqCount.symList )
                    {
                        o_rc = dqBitmap.setSymbol( sym.symbol );
                        if ( SUCCESS != o_rc )
                        {
                            PRDF_ERR( PRDF_FUNC "dqBitmap.setSymbol failed." );
                            break;
                        }
                    }
                    if ( SUCCESS != o_rc ) break;
                }
                else
                {
                    // Placing a symbol mark risks a UE.
                    // For nibbles under threshold with a sum greater than 1,
                    // update VPD with it's non-zero symbols.
                    o_rc = __updateVpdSumAboveOne(i_sumAboveOneCount, dqBitmap);
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR(PRDF_FUNC "__updateVpdSumAboveOne() failed.");
                    }

                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_TpsSymUeRisk );

                    // Make the error log predictive.
                    io_sc.service_data->setServiceCall();
                }

            }
            else
            {
                // Otherwise assume the symbol mark is fixing a bad DQ.
                // Update VPD with the unrepaired symbol.
                for ( auto sym : i_badDqCount.symList )
                {
                    if ( sym.symbol == symMark.getSymbol() ) continue;

                    o_rc = dqBitmap.setSymbol( sym.symbol );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "dqBitmap.setSymbol failed." );
                        break;
                    }
                }
                if ( SUCCESS != o_rc ) break;

                // Set the false alarm flag to true.
                tpsFalseAlarm = true;
            }

        }
        // Else if bad DQ nibble count is 0 and bad chip nibble count is 1
        else if ( 0 == i_badDqCount.count && 1 == i_badChipCount.count )
        {
            // If the chip mark is available.
            if ( !chipMark.isValid() )
            {
                // If the sum above one nibble count is = 0 or the sum above one
                // nibble count = 1 and the single sym nibble count = 1
                if ( (i_sumAboveOneCount.count == 0) ||
                     (i_sumAboveOneCount.count == 1 &&
                      i_singleSymCount.count == 1) )
                {
                    // This means we have only one more potential bad DQ, which
                    // is still correctable after a chip mark is placed.
                    // Place a chip mark on this bad chip.
                    MemMark newChipMark( mcaTrgt, iv_rank,
                                         i_badChipCount.symList[0].symbol );
                    o_rc = MarkStore::writeChipMark<TYPE_MCA>( iv_chip, iv_rank,
                                                               newChipMark );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "writeChipMark(0x%08x,0x%02x) "
                                  "failed", iv_chip->getHuid(), getKey() );
                        break;
                    }

                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_TpsChipMark );
                    // Update VPD with the chip mark.
                    o_rc = dqBitmap.setDram( i_badChipCount.symList[0].symbol );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "dqBitmap.setDram failed." );
                        break;
                    }
                }
                else
                {
                    // Placing a mark risks a UE.
                    // For nibbles under threshold with a sum greater than 1,
                    // update VPD with it's non-zero symbols.
                    o_rc = __updateVpdSumAboveOne(i_sumAboveOneCount, dqBitmap);
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR(PRDF_FUNC "__updateVpdSumAboveOne() failed.");
                    }

                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_TpsChipUeRisk );

                    // Make the error log predictive.
                    io_sc.service_data->setServiceCall();

                    // Permanently mask mainline NCEs and TCEs
                    getMcaDataBundle(iv_chip)->iv_maskMainlineNceTce = true;
                }
            }
            else
            {
                // Assume the chip mark is being used to fix the bad chip.
                // Set the false alarm flag to true.
                tpsFalseAlarm = true;
            }
        }
        // Else if bad DQ nibble count is 1 and bad chip nibble count is 1
        else if ( 1 == i_badDqCount.count && 1 == i_badChipCount.count )
        {
            // If neither chip nor symbol mark is available.
            if ( chipMark.isValid() && symMark.isValid() )
            {
                // Assume the chip and symbol marks are already being used to
                // fix the bad chip and DQ and some other nibble under
                // threshold triggered TPS.
                // Make the error log predictive.
                io_sc.service_data->setServiceCall();

                // Permanently mask mainline NCEs and TCEs
                getMcaDataBundle(iv_chip)->iv_maskMainlineNceTce = true;
            }
            // If the chip mark is available.
            if ( !chipMark.isValid() )
            {
                // If the sum above one nibble count is 0
                if ( 0 == i_sumAboveOneCount.count )
                {
                    // This means we have no more potential bad DQ or bad chips
                    // since we can't correct those after chip mark is placed.
                    // Place a chip mark on the bad chip.
                    MemMark newChipMark( mcaTrgt, iv_rank,
                                         i_badChipCount.symList[0].symbol );
                    o_rc = MarkStore::writeChipMark<TYPE_MCA>( iv_chip, iv_rank,
                                                               newChipMark );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "writeChipMark(0x%08x,0x%02x) "
                                  "failed", iv_chip->getHuid(), getKey() );
                        break;
                    }

                    // Check if the current symbol mark is on the same DRAM as
                    // this newly placed chip mark.
                    if ( symMark.isValid() &&
                         ( symMark.getSymbol().getDram() ==
                           newChipMark.getSymbol().getDram() ) )
                    {
                        // Since we need to set a symbol mark in addition to
                        // this chip mark, we need to clear the symbol mark now
                        // instead of at the end of the function to make room
                        // for the additional symbol mark.
                        o_rc = MarkStore::clearSymbolMark<TYPE_MCA>( iv_chip,
                                                                     iv_rank );
                        if ( SUCCESS != o_rc )
                        {
                            PRDF_ERR( PRDF_FUNC "MarkStore::clearSymbolMark("
                                      "0x%08x,0x%02x) failed",
                                      iv_chip->getHuid(), iv_rank.getKey() );
                            break;
                        }

                        // Now refresh the symMark variable since the mark has
                        // been removed.
                        symMark = MemMark();
                    }

                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_TpsChipMark );

                    // Update VPD with the chip mark.
                    o_rc = dqBitmap.setDram( i_badChipCount.symList[0].symbol );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "dqBitmap.setDram failed." );
                        break;
                    }

                    // Make the error log predictive.
                    io_sc.service_data->setServiceCall();
                }
                else
                {
                    // Placing a chip mark risks a UE.
                    // For nibbles under threshold with a sum greater than 1,
                    // update VPD with it's non-zero symbols.
                    o_rc = __updateVpdSumAboveOne(i_sumAboveOneCount, dqBitmap);
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR(PRDF_FUNC "__updateVpdSumAboveOne() failed.");
                    }

                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_TpsChipUeRisk );

                    // Make the error log predictive.
                    io_sc.service_data->setServiceCall();

                    // Permanently mask mainline NCEs and TCEs.
                    getMcaDataBundle(iv_chip)->iv_maskMainlineNceTce = true;
                }
            }
            // If the symbol mark is available.
            if ( !symMark.isValid() )
            {
                // If the sum above one nibble count is 0
                if ( 0 == i_sumAboveOneCount.count )
                {
                    // This means we have no more potential bad DQ or bad chips
                    // since we can't correct those after symbol mark is placed.
                    // Place a symbol mark on this bad DQ.
                    MemMark newSymMark( mcaTrgt, iv_rank,
                                        i_badDqCount.symList[0].symbol );
                    o_rc = MarkStore::writeSymbolMark<TYPE_MCA>( iv_chip,
                        iv_rank, newSymMark );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "writeSymbolMark(0x%08x,0x%02x) "
                                  "failed", iv_chip->getHuid(), getKey() );
                        break;
                    }

                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_TpsSymbolMark );

                    // Update VPD with the symbol mark.
                    o_rc = dqBitmap.setSymbol( i_badDqCount.symList[0].symbol );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "dqBitmap.setSymbol failed." );
                        break;
                    }

                    // Make the error log predictive.
                    io_sc.service_data->setServiceCall();
                }
                else
                {
                    // Placing the symbol mark risks a UE.
                    // For nibbles under threshold with a sum greater than 1,
                    // update VPD with it's non-zero symbols.
                    o_rc = __updateVpdSumAboveOne(i_sumAboveOneCount, dqBitmap);
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR(PRDF_FUNC "__updateVpdSumAboveOne() failed.");
                    }

                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_TpsSymUeRisk );

                    // Make the error log predictive.
                    io_sc.service_data->setServiceCall();

                    // Permanently mask mainline NCEs and TCEs.
                    getMcaDataBundle(iv_chip)->iv_maskMainlineNceTce = true;
                }
            }

        }
        else
        {
            // There are enough errors that this could be a potential UE.
            // For nibbles under threshold with a sum greater than 1,
            // update VPD with it's non-zero symbols.
            o_rc = __updateVpdSumAboveOne( i_sumAboveOneCount, dqBitmap );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__updateVpdSumAboveOne() failed." );
            }

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_TpsPotentialUe );

            // Make the error log predictive.
            io_sc.service_data->setServiceCall();

            // Permanently mask mainline NCEs and TCEs.
            getMcaDataBundle(iv_chip)->iv_maskMainlineNceTce = true;
        }

        // If analysis resulted in a false alarm.
        if ( tpsFalseAlarm )
        {
            o_rc = handleFalseAlarm( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleFalseAlarm() failed on 0x%08x, "
                          "0x%02x", iv_chip->getHuid(), getKey() );
            }
        }

        // Write any updates to VPD.
        o_rc = setBadDqBitmap( mcaTrgt, iv_rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setBadDqBitmap(0x%08x, 0x%02x) failed",
                      getHuid(mcaTrgt), iv_rank.getKey() );
            break;
        }

        // We may have placed a chip mark so do any necessary cleanup. This must
        // be called after writing the bad DQ bitmap because the this function
        // will also write it if necessary.
        o_rc = MarkStore::chipMarkCleanup<TYPE_MCA>( iv_chip, iv_rank, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "MarkStore::chipMarkCleanup(0x%08x,0x%02x) "
                      "failed", iv_chip->getHuid(), getKey() );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_MCA>::getSymbolCeCounts( CeCount & io_badDqCount,
    CeCount & io_badChipCount, CeCount & io_sumAboveOneCount,
    CeCount & io_singleSymCount, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MCA>::getSymbolCeCounts] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get the Bad DQ Bitmap.
        TargetHandle_t mcaTrgt = iv_chip->getTrgt();
        MemDqBitmap dqBitmap;

        o_rc = getBadDqBitmap( mcaTrgt, iv_rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap(0x%08x,%d) failed",
                      getHuid(mcaTrgt), iv_rank.getMaster() );
            break;
        }
        std::vector<MemSymbol> bmSymList = dqBitmap.getSymbolList();

        ExtensibleChip * mcbChip = getConnectedParent( iv_chip, TYPE_MCBIST );
        const char * reg_str = nullptr;
        SCAN_COMM_REGISTER_CLASS * reg = nullptr;

        for ( uint8_t regIdx = 0; regIdx < CE_REGS_PER_PORT; regIdx++ )
        {
            reg_str = mcbCeStatReg[regIdx];
            reg     = mcbChip->getRegister( reg_str );

            o_rc = reg->Read();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Read() failed on %s.", reg_str );
                break;
            }
            uint8_t baseSymbol = SYMBOLS_PER_CE_REG * regIdx;

            for ( uint8_t i = 0; i < SYMBOLS_PER_CE_REG;
                  i += MEM_SYMBOLS_PER_NIBBLE )
            {
                MemUtils::MaintSymbols nibbleStats;

                // Get a nibble's worth of symbols.
                for ( uint8_t n = 0; n < MEM_SYMBOLS_PER_NIBBLE; n++ )
                {
                    uint8_t sym = baseSymbol + (i+n);
                    PRDF_ASSERT( sym < SYMBOLS_PER_RANK );

                    MemUtils::SymbolData symData;
                    symData.symbol = MemSymbol::fromSymbol( mcaTrgt, iv_rank,
                        sym, CEN_SYMBOL::ODD_SYMBOL_DQ );
                    if ( !symData.symbol.isValid() )
                    {
                        PRDF_ERR( PRDF_FUNC "MemSymbol() failed: symbol=%d",
                                  sym );
                        o_rc = FAIL;
                        break;
                    }

                    // Any symbol set in the DRAM repairs VPD will have an
                    // automatic CE count of 0xFF
                    if ( std::find( bmSymList.begin(), bmSymList.end(),
                         symData.symbol ) != bmSymList.end() )
                        symData.count = 0xFF;
                    else
                        symData.count = reg->GetBitFieldJustified(((i+n)*8), 8);

                    nibbleStats.push_back( symData );

                    // Add all symbols with non-zero counts to the callout list.
                    if ( symData.count != 0 )
                    {
                        MemoryMru mm { mcaTrgt, iv_rank, symData.symbol };
                        io_sc.service_data->SetCallout( mm );
                    }
                }
                if ( SUCCESS != o_rc ) break;

                // Analyze the nibble of symbols.
                __analyzeNibbleSyms<TYPE_MCA>( nibbleStats, io_badDqCount,
                    io_badChipCount, io_sumAboveOneCount, io_singleSymCount );

            }
            if ( SUCCESS != o_rc ) break;
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

template <>
uint32_t TpsEvent<TYPE_MCA>::analyzeCeStats( STEP_CODE_DATA_STRUCT & io_sc,
                                             bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MCA>::analyzeCeStats] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // The symbol CE counts will be summarized in the following buckets:
        // Number of nibbles with a bad DQ
        // Number of nibbles with a bad chip
        // Number of nibbles under threshold with a sum greater than 1
        // Number of nibbles under threshold with only a single symbol with a
        // non-zero count, and that count is > 1
        CeCount badDqCount, badChipCount, sumAboveOneCount, singleSymCount;

        // Get the symbol CE counts.
        o_rc = getSymbolCeCounts( badDqCount, badChipCount, sumAboveOneCount,
                                  singleSymCount, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getSymbolCeCounts failed." );
            break;
        }

        // If DRAM repairs are disabled, make the error log predictive and
        // abort this procedure.
        if ( areDramRepairsDisabled() )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_TpsDramDisabled );

            io_sc.service_data->setServiceCall();
            break;
        }

        // Analyze the symbol CE counts.
        o_rc = analyzeCeSymbolCounts(badDqCount, badChipCount, sumAboveOneCount,
                                     singleSymCount, io_sc);
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeCeSymbolCounts failed." );
            break;
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_MCA>::analyzePhase( STEP_CODE_DATA_STRUCT & io_sc,
                                           bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent::analyzePhase] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( TD_PHASE_0 == iv_phase ) break; // Nothing to analyze yet.

        // Analyze Ecc Attentions
        uint32_t eccAttns;
        o_rc = checkEccFirs<TYPE_MCA>( iv_chip, eccAttns );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccFirs(0x%08x) failed",
                    iv_chip->getHuid() );
            break;
        }

        o_rc = analyzeEccErrors( eccAttns, io_sc, o_done );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeEccErrors() failed." );
            break;
        }
        if ( o_done ) break;

        // Analyze CEs
        o_rc = analyzeCeStats( io_sc, o_done );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeCeStats() failed." );
            break;
        }
        if ( o_done ) break;

        // At this point, we are done with the procedure.
        o_done = true;

    } while (0);

    if ( (SUCCESS == o_rc) && o_done )
    {
        // Clear the ECC FFDC for this master rank.
        MemDbUtils::resetEccFfdc<TYPE_MCA>( iv_chip, iv_rank, SLAVE_RANK );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//##############################################################################
//
//                          Specializations for MCA
//
//##############################################################################

template<>
uint32_t TpsEvent<TYPE_MCA>::startCmd()
{
    #define PRDF_FUNC "[TpsEvent::startCmd] "

    uint32_t o_rc = SUCCESS;

    // We don't need to set any stop-on-error conditions or thresholds for
    // soft/inter/hard CEs at runtime. The design is to let the command continue
    // to the end of the rank and we do diagnostics on the CE counts found in
    // the per-symbol counters. Therefore, all we need to do is tell the
    // hardware which CE types to count.

    mss::mcbist::stop_conditions stopCond;

    switch ( iv_phase )
    {
        case TD_PHASE_1:
            // Set the per symbol counters to count only hard CEs.
            stopCond.set_nce_hard_symbol_count_enable(mss::ON);
            break;

        case TD_PHASE_2:
            // Since there are not enough hard CEs to trigger a symbol mark, set
            // the per symbol counters to count all CE types.
            stopCond.set_nce_soft_symbol_count_enable( mss::ON);
            stopCond.set_nce_inter_symbol_count_enable(mss::ON);
            stopCond.set_nce_hard_symbol_count_enable( mss::ON);
            break;

        default: PRDF_ASSERT( false ); // invalid phase
    }

    // Start the time based scrub procedure on this slave rank.
    o_rc = startTdScrub<TYPE_MCA>( iv_chip, iv_rank, SLAVE_RANK, stopCond );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x) failed",
                  iv_chip->getHuid(), getKey() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_MCA>::startNextPhase( STEP_CODE_DATA_STRUCT & io_sc )
{
    uint32_t signature = 0;

    __getNextPhase<TYPE_MCA>( iv_chip, iv_rank, io_sc, iv_phase, signature );

    PRDF_TRAC( "[TpsEvent] Starting TPS Phase %d: 0x%08x,0x%02x",
               iv_phase, iv_chip->getHuid(), getKey() );

    io_sc.service_data->AddSignatureList( iv_chip->getTrgt(), signature );

    return startCmd();
}

//##############################################################################
//
//                          Specializations for MBA
//
//##############################################################################

template<>
uint32_t TpsEvent<TYPE_MBA>::analyzeEccErrors( const uint32_t & i_eccAttns,
                                         STEP_CODE_DATA_STRUCT & io_sc,
                                         bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent::analyzeEccErrors] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // If there was a UE.
        if ( i_eccAttns & MAINT_UE )
        {
            PRDF_TRAC( PRDF_FUNC "UE Detected: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintUE );

            // At this point we don't actually have an address for the UE. The
            // best we can do is get the address in which the command stopped.
            MemAddr addr;
            o_rc = getMemMaintAddr<TYPE_MBA>( iv_chip, addr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            o_rc = MemEcc::handleMemUe<TYPE_MBA>( iv_chip, addr,
                                                  UE_TABLE::SCRUB_UE, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemUe(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            // Because of the UE, any further TPS requests will likely have no
            // effect. So ban all subsequent requests.
            MemDbUtils::banTps<TYPE_MBA>( iv_chip, addr.getRank() );

            // An error was found, but don't abort. We want to see if any UEs
            // or MPEs exist on the rest of the rank. Also, since there was an
            // error, clear the false alarm flag.
            iv_tpsFalseAlarm = false;
        }

        // If there was an MPE.
        if ( i_eccAttns & MAINT_MPE )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintMPE );

            o_rc = MemEcc::handleMpe<TYPE_MBA>( iv_chip, iv_rank,
                                                UE_TABLE::SCRUB_MPE, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMpe<T>(0x%08x, 0x%02x) failed",
                          iv_chip->getHuid(), iv_rank.getKey() );
                break;
            }

            // Abort this procedure because the chip mark may have fixed the
            // symbol that triggered TPS.
            o_done = true; break;
        }

        if ( i_eccAttns & MAINT_RCE_ETE )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintRETRY_CTE );

            // Add the rank to the callout list.
            MemoryMru mm { iv_chip->getTrgt(), iv_rank,
                           MemoryMruData::CALLOUT_RANK };
            io_sc.service_data->SetCallout( mm );

            // Make the error log predictive.
            io_sc.service_data->setServiceCall();

            // An error was found, but don't abort. We want to see if any UEs
            // or MPEs exist on the rest of the rank. Also, since there was an
            // error, clear the false alarm flag.
            iv_tpsFalseAlarm = false;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_MBA>::analyzeCeStats( STEP_CODE_DATA_STRUCT & io_sc,
                                             bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent::analyzeCeStats] "

    uint32_t o_rc = SUCCESS;

    TargetHandle_t trgt = iv_chip->getTrgt();

    do
    {
        // Get the current threshold.
        // Phase 1 (hard CEs): 48 in the field or 1 in MNFG
        // Phase 2 (all CEs):  80 in the field or the calculated per DRAM
        //                     threshold (configurable via
        //                     ATTR_MNFG_TH_CEN_MBA_RT_SOFT_CE_TH_ALGO) in MNFG.
        uint16_t thr = ( TD_PHASE_1 == iv_phase )
                            ? (mfgMode() ? 1 : 48)
                            : getScrubCeThreshold<TYPE_MBA>(iv_chip, iv_rank);

        // Get the chip mark
        MemMark chipMark;
        o_rc = MarkStore::readChipMark<TYPE_MBA>( iv_chip, iv_rank, chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark<TYPE_MBA>(0x%08x, 0x%02x) "
                      "failed", iv_chip->getHuid(), iv_rank.getKey() );
            break;
        }
        // Get the symbol mark.
        MemMark symMark;
        o_rc = MarkStore::readSymbolMark<TYPE_MBA>( iv_chip, iv_rank, symMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readSymbolMark<TYPE_MBA>(0x%08x, 0x%02x) "
                      "failed", iv_chip->getHuid(), iv_rank.getKey() );
            break;
        }

        // Get all the symbols that have a count greater than or equal to the
        // target threshold.
        MemUtils::MaintSymbols symData;
        MemSymbol targetCm;

        o_rc = MemUtils::collectCeStats<TYPE_MBA>( iv_chip, iv_rank, symData,
                                                   targetCm, thr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "collectCeStats() failed." );
            break;
        }

        // Check for false alarms.
        if ( symData.empty() ) break; // nothing else to do

        // There is valid data so clear the false alarm flag.
        iv_tpsFalseAlarm = false;

        // Callout all DIMMs with symbol count that reached threshold.
        bool badDimms[MAX_PORT_PER_MBA] = { false, false };

        for ( auto & sym : symData )
        {
            badDimms[sym.symbol.getPortSlct()] = true;
        }
        for ( uint32_t port = 0; port < MAX_PORT_PER_MBA; port++ )
        {
            if ( badDimms[port] )
            {
                TargetHandle_t dimm = getConnectedDimm( trgt, iv_rank, port );
                io_sc.service_data->SetCallout( dimm, MRU_MED );
            }
        }

        // Check if DRAM repairs are disabled.
        if ( areDramRepairsDisabled() )
        {
            // Make the error log predictive.
            io_sc.service_data->setServiceCall();
            break; // nothing else to do
        }

        // Add all symbols to the VPD.
        MemDqBitmap bitmap;
        o_rc = getBadDqBitmap( trgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed." );
            break;
        }

        for ( auto & sym : symData )
        {
            bitmap.setSymbol( sym.symbol );
        }

        // Write updates to VPD.
        o_rc = setBadDqBitmap( trgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setBadDqBitmap() failed" );
            break;
        }

        // Check if the chip mark is available.
        bool cmPlaced = false;
        if ( !chipMark.isValid() )
        {
            if ( targetCm.isValid() )
            {
                // Use the DRAM with the highest total count.
                chipMark = MemMark ( trgt, iv_rank, targetCm );
                o_rc = MarkStore::writeChipMark<TYPE_MBA>( iv_chip, iv_rank,
                                                           chipMark );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "writeChipMark(0x%08x, 0x%02x) failed.",
                              iv_chip->getHuid(), iv_rank.getKey() );
                    break;
                }
                cmPlaced = true;
            }
            // If the symbol mark has been used then use the chip mark.
            else if ( !isDramWidthX4(trgt) && symMark.isValid() )
            {
                // symData is sorted by count with the largest entries at the
                // end of the list. So iterate backwards through the list to
                // find the symbol with the highest count that is not on the
                // same symbol as the symbol mark.
                for ( auto it = symData.end(); it-- != symData.begin(); )
                {
                    if ( !( it->symbol == symMark.getSymbol() ) )
                    {
                        chipMark = MemMark ( trgt, iv_rank, it->symbol );
                        o_rc = MarkStore::writeChipMark<TYPE_MBA>( iv_chip,
                                                                   iv_rank,
                                                                   chipMark );
                        if ( SUCCESS != o_rc )
                        {
                            PRDF_ERR( PRDF_FUNC "writeChipMark(0x%08x, 0x%02x) "
                                      "failed.", iv_chip->getHuid(),
                                      iv_rank.getKey() );
                            break;

                        }
                        cmPlaced = true;
                        break;
                    }
                }
                if ( SUCCESS != o_rc ) break;
            }
        }

        // If a chip mark was placed add a VCM procedure to the queue.
        if ( cmPlaced )
        {
            io_sc.service_data->AddSignatureList( iv_chip->getTrgt(),
                                                  PRDFSIG_TpsChipMark );

            TdEntry * e = new VcmEvent<TYPE_MBA> { iv_chip, iv_rank, chipMark };
            MemDbUtils::pushToQueue<TYPE_MBA>( iv_chip, e );

            // Abort this procedure because the chip mark may have fixed the
            // symbol that triggered TPS.
            o_done = true; break;
        }

        // Check if the symbol mark is available. Note that symbol marks are not
        // available in x4 mode. Also, we only want to place a symbol mark if we
        // did not just place a chip mark above. The reason for this is because
        // having a chip mark and symbol mark at the same time increases the
        // chance of UEs. We will want to wait until the chip mark we placed
        // above is verified and possibily steered, before placing the symbol
        // mark.
        if ( !cmPlaced && !isDramWidthX4(trgt) && !symMark.isValid() )
        {
            io_sc.service_data->AddSignatureList( iv_chip->getTrgt(),
                                                  PRDFSIG_TpsSymbolMark );

            // Use the symbol with the highest count.
            symMark = MemMark ( trgt, iv_rank, symData.back().symbol );
            o_rc = MarkStore::writeSymbolMark<TYPE_MBA>( iv_chip, iv_rank,
                                                         symMark );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "writeSymbolMark(0x%08x, 0x%02x) failed.",
                          iv_chip->getHuid(), iv_rank.getKey() );
                break;
            }
        }

        // We know with a degree of confidence that any chip mark placed in this
        // function will be verified. Therefore, we can do a early check here
        // and make a predictive callout if the chip mark and all available
        // spares have been used. This is useful because the targeted
        // diagnostics procedure will take much longer to complete due to a
        // hardware issue. By making the predictive callout now, we will send a
        // Dynamic Memory Deallocation message to PHYP sooner so that they can
        // attempt to get off the memory instead of waiting for the callout
        // after the VCM procedure.
        if ( chipMark.isValid() )
        {
            TdEntry * dsdEvent = nullptr;
            o_rc = MarkStore::applyRasPolicies<TYPE_MBA>( iv_chip, iv_rank,
                                                          io_sc, dsdEvent );
            if ( nullptr != dsdEvent )
            {
                // We don't want to do the DRAM spare procedure at this time,
                // because we haven't even run the VCM procedure yet. So just
                // delete the procedure instead of adding it to the queue.
                delete dsdEvent; dsdEvent = nullptr;
            }

            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "applyRasPolicies(0x%08x, 0x%02x) failed.",
                          iv_chip->getHuid(), iv_rank.getKey() );
                break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_MBA>::handleFalseAlarm( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[TpsEvent::handleFalseAlarm] "

    uint32_t o_rc = SUCCESS;

    do
    {
        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                          PRDFSIG_TpsFalseAlarm );

        // Callout all DIMMs that have reached threshold.
        // Centaur DIMMS: Any non-zero count, threshold on 1.
        // IS DIMMS:      Allow 1, threshold on 2 (because of limited spares).
        uint8_t thr = isMembufOnDimm<TYPE_MBA>( iv_chip->getTrgt() ) ? 1 : 2 ;
        MemUtils::MaintSymbols symData;
        MemSymbol junk;
        o_rc = MemUtils::collectCeStats<TYPE_MBA>( iv_chip, iv_rank, symData,
                                                   junk, thr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "collectCeStats failed." );
            break;
        }

        if ( symData.empty() )
        {
            // There is no data so callout the rank.
            MemoryMru memmru( iv_chip->getTrgt(), iv_rank,
                              MemoryMruData::CALLOUT_RANK );
            io_sc.service_data->SetCallout( memmru );
        }
        else
        {
            // Callout all DIMMs with symbol count that reached threshold.
            bool badDimms[MAX_PORT_PER_MBA] = { false, false };

            for ( auto & sym : symData )
            {
                badDimms[sym.symbol.getPortSlct()] = true;
            }
            for ( uint32_t port = 0; port < MAX_PORT_PER_MBA; port++ )
            {
                if ( badDimms[port] )
                {
                    TargetHandle_t dimm =
                        getConnectedDimm( iv_chip->getTrgt(), iv_rank, port );
                    io_sc.service_data->SetCallout( dimm, MRU_MED );
                }
            }
        }

        // In manufacturing, this error log will be predictive.
        if ( areDramRepairsDisabled() )
        {
            io_sc.service_data->setServiceCall();
            break; // nothing else to do
        }

        // Increase the false alarm counter. Continue only if false alarm
        // threshold is exceeded.
        if ( !__getTpsFalseAlarmCounter<TYPE_MBA>(iv_chip)->inc(iv_rank,io_sc) )
            break;

        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                          PRDFSIG_TpsFalseAlarmTH );

        // If there are no symbols in the list, exit quietly.
        if ( symData.empty() ) break;

        // Use the symbol with the highest count to place a symbol or chip mark,
        // if possible. Note that we only want to use one repair for this false
        // alarm to avoid using up all the repairs for 'weak' errors.
        MemSymbol highestSymbol = symData.back().symbol;

        // Get the chip mark
        MemMark chipMark;
        o_rc = MarkStore::readChipMark<TYPE_MBA>( iv_chip, iv_rank, chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark<TYPE_MBA>(0x%08x, 0x%02x) "
                      "failed", iv_chip->getHuid(), iv_rank.getKey() );
            break;
        }
        // Get the symbol mark.
        MemMark symMark;
        o_rc = MarkStore::readSymbolMark<TYPE_MBA>( iv_chip, iv_rank, symMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readSymbolMark<TYPE_MBA>(0x%08x, 0x%02x) "
                      "failed", iv_chip->getHuid(), iv_rank.getKey() );
            break;
        }

        // Check of the symbol mark is available. Note that symbol marks are
        // not available in x4 mode.
        if ( !isDramWidthX4(iv_chip->getTrgt()) && !symMark.isValid() )
        {
            io_sc.service_data->AddSignatureList( iv_chip->getTrgt(),
                                                  PRDFSIG_TpsSymbolMark );

            MemMark sm( iv_chip->getTrgt(), iv_rank, highestSymbol );
            o_rc = MarkStore::writeSymbolMark<TYPE_MBA>( iv_chip, iv_rank, sm );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "writeSymbolMark(0x%08x,0x%02x) "
                          "failed", iv_chip->getHuid(), iv_rank.getKey() );
                break;
            }

            // Add this symbol to the VPD.
            MemDqBitmap bitmap;
            o_rc = getBadDqBitmap( iv_chip->getTrgt(), iv_rank, bitmap );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed" );
                break;
            }

            bitmap.setSymbol( highestSymbol );

            o_rc = setBadDqBitmap( iv_chip->getTrgt(), iv_rank, bitmap );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "setBadDqBitmap() failed" );
                break;
            }
        }
        // Check if the chip mark is available
        else if ( !chipMark.isValid() )
        {
            io_sc.service_data->AddSignatureList( iv_chip->getTrgt(),
                                                  PRDFSIG_TpsChipMark );

            MemMark cm( iv_chip->getTrgt(), iv_rank, highestSymbol );
            o_rc = MarkStore::writeChipMark<TYPE_MBA>( iv_chip, iv_rank, cm );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "writeChipMark(0x%08x,0x%02x) "
                          "failed", iv_chip->getHuid(), iv_rank.getKey() );
                break;
            }

            // Add a VCM procedure to the queue.
            TdEntry * entry = new VcmEvent<TYPE_MBA>( iv_chip, iv_rank, cm );
            MemDbUtils::pushToQueue<TYPE_MBA>( iv_chip, entry );
        }
        else
        {
            // The spares have been used. Make the error log predictive.
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_AllDramRepairs );
            io_sc.service_data->setServiceCall();
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_MBA>::analyzePhase( STEP_CODE_DATA_STRUCT & io_sc,
                                           bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent::analyzePhase] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( TD_PHASE_0 == iv_phase ) break; // Nothing to analyze yet.

        // Look for any ECC errors that occurred during the command.
        uint32_t eccAttns;
        o_rc = checkEccFirs<TYPE_MBA>( iv_chip, eccAttns );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccFirs(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Analyze the ECC errors (not CEs), if needed.
        o_rc = analyzeEccErrors( eccAttns, io_sc, o_done );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeEccErrors() failed on 0x%08x,0x%02x",
                      iv_chip->getHuid(), getKey() );
            break;
        }
        if ( o_done ) break; // abort the procedure.

        // Determine if the command stopped on the last address.
        bool lastAddr = false;
        o_rc = didCmdStopOnLastAddr<TYPE_MBA>( iv_chip, SLAVE_RANK, lastAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "didCmdStopOnLastAddr(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // It is important to initialize iv_canResumeScrub here, so that we will
        // know to resume the current phase in startNextPhase() instead of
        // starting the next phase.
        iv_canResumeScrub = !lastAddr;

        // Analyze the CE statistics if the command has reached the last
        // address, there were hard CEs on phase 1 or 2, or there were
        // soft/intermittent CEs on phase 2.
        if ( lastAddr || (eccAttns & MAINT_HARD_NCE_ETE) ||
             ((TD_PHASE_2 == iv_phase) && ((eccAttns & MAINT_INT_NCE_ETE) ||
                                           (eccAttns & MAINT_SOFT_NCE_ETE)  )) )
        {
            o_rc = analyzeCeStats( io_sc, o_done );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "analyzeCeStats() failed on 0x%08x,0x%02x",
                          iv_chip->getHuid(), getKey() );
                break;
            }
            if ( o_done ) break; // abort the procedure.
        }

        // If the command reached the last address, the procedure is complete.
        if ( lastAddr )
        {
            o_done = true;

            // Handle the false alarm, if needed.
            if ( iv_tpsFalseAlarm )
            {
                o_rc = handleFalseAlarm( io_sc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "handleFalseAlarm() failed on 0x%08x, "
                              "0x%02x", iv_chip->getHuid(), getKey() );
                }
            }
        }

    } while (0);

    if ( (SUCCESS == o_rc) && o_done )
    {
        // Clear the ECC FFDC for this master rank.
        MemDbUtils::resetEccFfdc<TYPE_MBA>( iv_chip, iv_rank, SLAVE_RANK );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_MBA>::startCmd()
{
    #define PRDF_FUNC "[TpsEvent::startCmd] "

    uint32_t o_rc = SUCCESS;

    uint32_t stopCond = mss_MaintCmd::NO_STOP_CONDITIONS;

    // Due to a hardware bug in the Centaur, we must execute runtime maintenance
    // commands at a very slow rate. Because of this, we decided that we should
    // stop the command immediately on error if there is a UE or MPE so that we
    // can respond quicker and send a DMD message to the hypervisor or do chip
    // mark verification as soon as possible.

    stopCond |= mss_MaintCmd::STOP_ON_UE;
    stopCond |= mss_MaintCmd::STOP_ON_MPE;
    stopCond |= mss_MaintCmd::STOP_IMMEDIATE;

    do
    {
        ExtensibleChip * membChip = getConnectedParent( iv_chip, TYPE_MEMBUF );
        const char * reg_str = (0 == iv_chip->getPos()) ? "MBSTR_0" : "MBSTR_1";
        SCAN_COMM_REGISTER_CLASS * mbstr = membChip->getRegister( reg_str );
        o_rc = mbstr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s: 0x%08x", reg_str,
                      membChip->getHuid() );
            break;
        }

        // Stopping on CE thresholds should save us time since the TPS scrub
        // could take several hours (again, due to the Centaur bug). We want to
        // set all of the CE thresholds to the maximum value so that we can get
        // as much data as we can for analysis before stopping the command.
        // Hopefully, we can use this data to place any marks, if needed.
        mbstr->SetBitFieldJustified(  4, 12, 0xfff );
        mbstr->SetBitFieldJustified( 16, 12, 0xfff );
        mbstr->SetBitFieldJustified( 28, 12, 0xfff );

        switch ( iv_phase )
        {
            case TD_PHASE_1:
                // Set the per symbol counters to count only hard CEs.
                mbstr->SetBitFieldJustified( 55, 3, 0x1 );
                stopCond |= mss_MaintCmd::STOP_ON_HARD_NCE_ETE;
                break;

            case TD_PHASE_2:
                // Since there are not enough hard CEs to trigger a symbol mark,
                // set the per symbol counters to count all CE types.
                mbstr->SetBitFieldJustified( 55, 3, 0x7 );
                stopCond |= mss_MaintCmd::STOP_ON_SOFT_NCE_ETE;
                stopCond |= mss_MaintCmd::STOP_ON_INT_NCE_ETE;
                stopCond |= mss_MaintCmd::STOP_ON_HARD_NCE_ETE;
                break;

            default: PRDF_ASSERT( false ); // invalid phase
        }

        o_rc = mbstr->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s: 0x%08x", reg_str,
                      membChip->getHuid() );
            break;
        }

        if ( iv_canResumeScrub )
        {
            // Resume the command from the next address to the end of this
            // slave rank.
            o_rc = resumeTdScrub<TYPE_MBA>( iv_chip, SLAVE_RANK, stopCond );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "resumeTdScrub(0x%08x) failed",
                          iv_chip->getHuid() );
            }
        }
        else
        {
            // Start the time based scrub procedure on this slave rank.
            o_rc = startTdScrub<TYPE_MBA>( iv_chip, iv_rank, SLAVE_RANK,
                                           stopCond );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x) failed",
                          iv_chip->getHuid(), getKey() );
            }
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_MBA>::startNextPhase( STEP_CODE_DATA_STRUCT & io_sc )
{

    uint32_t signature = 0;

    if ( iv_canResumeScrub )
    {
        signature = PRDFSIG_TpsResume;

        PRDF_TRAC( "[TpsEvent] Resuming TPS Phase %d: 0x%08x,0x%02x",
                   iv_phase, iv_chip->getHuid(), getKey() );
    }
    else
    {
        __getNextPhase<TYPE_MBA>( iv_chip, iv_rank, io_sc, iv_phase, signature);

        PRDF_TRAC( "[TpsEvent] Starting TPS Phase %d: 0x%08x,0x%02x",
                   iv_phase, iv_chip->getHuid(), getKey() );
    }

    io_sc.service_data->AddSignatureList( iv_chip->getTrgt(), signature );

    return startCmd();
}

//------------------------------------------------------------------------------

} // end namespace PRDF

