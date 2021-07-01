/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTps_rt.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include <prdfMemDbUtils.H>
#include <prdfMemEccAnalysis.H>
#include <prdfMemExtraSig.H>
#include <prdfMemMark.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTdFalseAlarm.H>
#include <prdfMemTps.H>
#include <prdfMemExtraSig.H>
#include <prdfTargetServices.H>

#include <exp_defaults.H>
#include <exp_rank.H>
#include <kind.H>
#include <hwp_wrappers.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

const uint8_t CE_REGS_PER_PORT = 9;
const uint8_t SYMBOLS_PER_CE_REG = 8;

static const char *ocmbCeStatReg[CE_REGS_PER_PORT] =
                       {
                           "OCMB_MBSSYMEC0", "OCMB_MBSSYMEC1", "OCMB_MBSSYMEC2",
                           "OCMB_MBSSYMEC3", "OCMB_MBSSYMEC4", "OCMB_MBSSYMEC5",
                           "OCMB_MBSSYMEC6", "OCMB_MBSSYMEC7", "OCMB_MBSSYMEC8"
                       };

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
TpsFalseAlarm * __getTpsFalseAlarmCounter( ExtensibleChip * i_chip );

template<>
TpsFalseAlarm * __getTpsFalseAlarmCounter<TYPE_OCMB_CHIP>(
    ExtensibleChip * i_chip )
{
    return getOcmbDataBundle(i_chip)->getTpsFalseAlarmCounter();
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
void __maskMainlineNceTces( ExtensibleChip * i_chip );

template<>
void __maskMainlineNceTces<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip )
{
    getOcmbDataBundle(i_chip)->iv_maskMainlineNceTce = true;
    getOcmbDataBundle(i_chip)->getTdCtlr()->maskEccAttns();
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
bool __badDqCount(MemUtils::MaintSymbols i_nibbleStats, CeCount & io_badDqCount)
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

template <TARGETING::TYPE T>
uint32_t TpsEvent<T>::analyzeEccErrors( const uint32_t & i_eccAttns,
                                        STEP_CODE_DATA_STRUCT & io_sc,
                                        bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<T>::analyzeEccErrors] "

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
            o_rc = getMemMaintAddr<T>( iv_chip, addr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            o_rc = MemEcc::handleMemUe<T>( iv_chip, addr,
                                           UE_TABLE::SCRUB_UE, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemUe(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            // Because of the UE, any further TPS requests will likely have no
            // effect. So ban all subsequent requests.
            MemDbUtils::banTps<T>( iv_chip, addr.getRank() );

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

            o_rc = MemEcc::handleMemIue<T>( iv_chip, iv_rank, io_sc );
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

            o_rc = MemEcc::handleMpe<T>( iv_chip, iv_rank,
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

template
uint32_t TpsEvent<TYPE_OCMB_CHIP>::analyzeEccErrors(const uint32_t & i_eccAttns,
                                                  STEP_CODE_DATA_STRUCT & io_sc,
                                                  bool & o_done);

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t TpsEvent<T>::handleFalseAlarm( STEP_CODE_DATA_STRUCT & io_sc )
{
    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                      PRDFSIG_TpsFalseAlarm );

    // Increase false alarm counter and check threshold.
    if ( __getTpsFalseAlarmCounter<T>(iv_chip)->inc( iv_rank, io_sc) )
    {
        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                          PRDFSIG_TpsFalseAlarmTH );

        // Permanently mask mainline NCEs and TCEs
        __maskMainlineNceTces<T>( iv_chip );
    }

    return SUCCESS;
}

template
uint32_t TpsEvent<TYPE_OCMB_CHIP>::handleFalseAlarm(
                                            STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t TpsEvent<T>::analyzeCeSymbolCounts( CeCount i_badDqCount,
    CeCount i_badChipCount, CeCount i_sumAboveOneCount,
    CeCount i_singleSymCount, STEP_CODE_DATA_STRUCT & io_sc )
{

    #define PRDF_FUNC "[TpsEvent<T>::analyzeCeSymbolCounts] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Keep track of if there was a false alarm and if we added a VCM
        // event to the targeted diagnostics queue.
        bool tpsFalseAlarm = false;
        bool vcmQueued = false;

        // Get the Bad DQ Bitmap.
        TargetHandle_t trgt = iv_chip->getTrgt();
        MemDqBitmap dqBitmap;

        o_rc = getBadDqBitmap( trgt, iv_rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap(0x%08x, 0x%02x) failed",
                      getHuid(trgt), iv_rank.getKey() );
            break;
        }

        // Get the symbol mark.
        MemMark symMark;
        o_rc = MarkStore::readSymbolMark<T>( iv_chip, iv_rank, symMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readSymbolMark<T>(0x%08x, 0x%02x) "
                      "failed", iv_chip->getHuid(), iv_rank.getKey() );
            break;
        }

        // Get the chip mark.
        MemMark chipMark;
        o_rc = MarkStore::readChipMark<T>( iv_chip, iv_rank, chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark<T>(0x%08x, 0x%02x) "
                      "failed", iv_chip->getHuid(), iv_rank.getKey() );
            break;
        }

        // Check if a spare is available to be used
        bool spAvail = false;

        // TODO RTC 210072 - Support for multiple ports per OCMB
        o_rc = isSpareAvailable<T>( trgt, iv_rank, 0, spAvail );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "isSpareAvailable(0x%08x, 0x%02x) failed",
                    iv_chip->getHuid(), getKey() );
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
            // Place a chip mark to deploy a spare if we can.
            // Note: Placing a chip mark does not risk a UE if the sum greater
            // than 1 nibble count is 0 or the sum greater than 1 nibble count
            // is 1 and the single symbol nibble count is 1.

            bool noSpareUeRisk = (i_sumAboveOneCount.count == 0 ||
                (i_sumAboveOneCount.count == 1 && i_singleSymCount.count == 1));
            // If we can place a spare
            if ( spAvail && noSpareUeRisk )

            {
                // Placing a chip mark to deploy a spare does not risk a UE
                MemMark newCM(trgt, iv_rank, i_badDqCount.symList.at(0).symbol);
                o_rc = MarkStore::writeChipMark<T>( iv_chip, iv_rank, newCM );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "writeChipMark(0x%08x,0x%02x) "
                              "failed", iv_chip->getHuid(), getKey() );
                    break;
                }
            }
            // Else we can't place a spare
            else
            {
                // If the symbol mark is available.
                if ( !symMark.isValid() )
                {
                    // If the sum above one nibble count is <= 1 or sum above
                    // one nibble count == 2 and single sym nibble count == 2
                    if ( (i_sumAboveOneCount.count <= 1) ||
                            (i_sumAboveOneCount.count == 2 &&
                             i_singleSymCount.count == 2) )
                    {
                        // This means we have a potential future chip kill or
                        // TCE. Both are still correctable after a symbol mark
                        // is placed.
                        // Place a symbol mark on this bad DQ.
                        MemSymbol symbol = i_badDqCount.symList.at(0).symbol;
                        MemMark newSymMark( trgt, iv_rank, symbol );
                        o_rc = MarkStore::writeSymbolMark<T>( iv_chip,
                                iv_rank, newSymMark );
                        if ( SUCCESS != o_rc )
                        {
                            PRDF_ERR( PRDF_FUNC "writeSymbolMark(0x%08x,0x%02x)"
                                      " failed", iv_chip->getHuid(), getKey() );
                            break;
                        }

                        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                PRDFSIG_TpsSymbolMark );

                        // Update VPD with the symbol mark.
                        o_rc = dqBitmap.setSymbol( symbol );
                        if ( SUCCESS != o_rc )
                        {
                            PRDF_ERR( PRDF_FUNC "dqBitmap.setSymbol failed." );
                            break;
                        }
                    }
                    else
                    {
                        // Placing a symbol mark risks a UE.
                        // For nibbles under threshold with a sum greater than
                        // 1, update VPD with it's non-zero symbols.
                        o_rc = __updateVpdSumAboveOne( i_sumAboveOneCount,
                                                       dqBitmap );
                        if ( SUCCESS != o_rc )
                        {
                            PRDF_ERR( PRDF_FUNC "__updateVpdSumAboveOne() "
                                      "failed." );
                        }

                        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                PRDFSIG_TpsSymUeRisk );

                        // Make the error log predictive.
                        io_sc.service_data->setServiceCall();

                        // Permanently mask mainline NCEs and TCEs and ban TPS.
                        MemDbUtils::banTps<T>( iv_chip, iv_rank );
                    }
                }
                else
                {
                    // Otherwise assume the symbol mark is fixing this bad DQ.
                    // Set the false alarm flag to true.
                    tpsFalseAlarm = true;
                }
            }
        }
        // Else if bad DQ nibble count is 2 and bad chip nibble count is 0.
        else if ( 2 == i_badDqCount.count && 0 == i_badChipCount.count )
        {
            // Place a chip mark to deploy a spare if we can
            // Note: Placing a chip mark does not risk a UE if the sum greater
            // than 1 nibble count is == 0.
            bool noSpareUeRisk = (i_sumAboveOneCount.count == 0);

            // If we can place a spare
            if ( spAvail && noSpareUeRisk  )
            {
                // Placing a chip mark to deploy a spare does not risk a UE
                MemMark newCM(trgt, iv_rank, i_badDqCount.symList.at(0).symbol);
                o_rc = MarkStore::writeChipMark<T>( iv_chip, iv_rank, newCM );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "writeChipMark(0x%08x,0x%02x) "
                              "failed", iv_chip->getHuid(), getKey() );
                    break;
                }
            }
            // Else we can't place a spare
            else
            {
                // Permanently mask mainline NCEs and TCEs and ban TPS.
                MemDbUtils::banTps<T>( iv_chip, iv_rank );

                // If the symbol mark is available.
                if ( !symMark.isValid() )
                {
                    // If the sum above one nibble count is = 0 or sum above one
                    // nibble count = 1 and single sym nibble count = 1
                    if ( (i_sumAboveOneCount.count == 0) ||
                            (i_sumAboveOneCount.count == 1 &&
                             i_singleSymCount.count == 1) )
                    {
                        // This means we have only one more potential bad DQ,
                        // which is correctable after a symbol mark is placed.
                        // Place a symbol mark on the bad DQ with the highest
                        // count
                        MemUtils::SymbolData highSym;
                        for ( auto sym : i_badDqCount.symList )
                        {
                            if ( sym.count > highSym.count )
                                highSym = sym;
                        }

                        MemMark newSymMark( trgt, iv_rank, highSym.symbol );
                        o_rc = MarkStore::writeSymbolMark<T>( iv_chip, iv_rank,
                                                              newSymMark );
                        if ( SUCCESS != o_rc )
                        {
                            PRDF_ERR( PRDF_FUNC "writeSymbolMark(0x%08x,0x%02x)"
                                      " failed", iv_chip->getHuid(), getKey() );
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
                                PRDF_ERR( PRDF_FUNC "dqBitmap.setSymbol "
                                          "failed." );
                                break;
                            }
                        }
                        if ( SUCCESS != o_rc ) break;
                    }
                    else
                    {
                        // Placing a symbol mark risks a UE.
                        // For nibbles under threshold with a sum greater than
                        // 1, update VPD with it's non-zero symbols.
                        o_rc = __updateVpdSumAboveOne( i_sumAboveOneCount,
                                                       dqBitmap );
                        if ( SUCCESS != o_rc )
                        {
                            PRDF_ERR( PRDF_FUNC "__updateVpdSumAboveOne() "
                                     "failed." );
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
                    MemMark newChipMark( trgt, iv_rank,
                                         i_badChipCount.symList.at(0).symbol );
                    o_rc = MarkStore::writeChipMark<T>( iv_chip, iv_rank,
                                                        newChipMark );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "writeChipMark(0x%08x,0x%02x) "
                                  "failed", iv_chip->getHuid(), getKey() );
                        break;
                    }

                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                                                      PRDFSIG_TpsChipMark );

                    // Trigger VCM to see if it's contained to a single row
                    TdEntry * vcm = new VcmEvent<T>{ iv_chip, iv_rank,
                                                     newChipMark };
                    MemDbUtils::pushToQueue<T>( iv_chip, vcm );
                    vcmQueued = true;
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
                    MemDbUtils::banTps<T>( iv_chip, iv_rank );
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
            // Keep track of if the symbol mark signature needs to be added to
            // the multi-signature list instead of as the primary signature.
            bool multiSig = false;

            // If neither chip nor symbol mark is available.
            if ( chipMark.isValid() && symMark.isValid() )
            {
                // Assume the chip and symbol marks are already being used to
                // fix the bad chip and DQ and some other nibble under
                // threshold triggered TPS.
                // Make the error log predictive.
                io_sc.service_data->setServiceCall();

                // Permanently mask mainline NCEs and TCEs
                MemDbUtils::banTps<T>( iv_chip, iv_rank );
            }
            // If the chip mark is available.
            if ( !chipMark.isValid() )
            {
                // We're going to set some signature for the chip mark, so
                // any signature for the symbol mark will be added to the
                // multi-signature list.
                multiSig = true;

                // If the sum above one nibble count is 0
                if ( 0 == i_sumAboveOneCount.count )
                {
                    // This means we have no more potential bad DQ or bad chips
                    // since we can't correct those after chip mark is placed.
                    // Place a chip mark on the bad chip.
                    MemMark newChipMark( trgt, iv_rank,
                                         i_badChipCount.symList.at(0).symbol );
                    o_rc = MarkStore::writeChipMark<T>( iv_chip, iv_rank,
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
                        o_rc = MarkStore::clearSymbolMark<T>( iv_chip,
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

                    // Trigger VCM to see if it's contained to a single row
                    TdEntry * vcm = new VcmEvent<T>{ iv_chip, iv_rank,
                                                     newChipMark };
                    MemDbUtils::pushToQueue<T>( iv_chip, vcm );
                    vcmQueued = true;
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
                    MemDbUtils::banTps<T>( iv_chip, iv_rank );
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
                    MemMark newSymMark( trgt, iv_rank,
                                        i_badDqCount.symList.at(0).symbol );
                    o_rc = MarkStore::writeSymbolMark<T>( iv_chip,
                        iv_rank, newSymMark );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "writeSymbolMark(0x%08x,0x%02x) "
                                  "failed", iv_chip->getHuid(), getKey() );
                        break;
                    }

                    if ( !multiSig )
                    {
                        io_sc.service_data->setSignature(
                            iv_chip->getHuid(), PRDFSIG_TpsSymbolMark );
                    }
                    else
                    {
                        io_sc.service_data->AddSignatureList(
                            iv_chip->getTrgt(), PRDFSIG_TpsSymbolMark );
                    }

                    // Update VPD with the symbol mark.
                    o_rc = dqBitmap.setSymbol(
                        i_badDqCount.symList.at(0).symbol );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "dqBitmap.setSymbol failed." );
                        break;
                    }
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

                    if ( !multiSig )
                    {
                        io_sc.service_data->setSignature(
                            iv_chip->getHuid(), PRDFSIG_TpsSymUeRisk );
                    }
                    else
                    {
                        io_sc.service_data->AddSignatureList(
                            iv_chip->getTrgt(), PRDFSIG_TpsSymUeRisk );
                    }

                    // Make the error log predictive.
                    io_sc.service_data->setServiceCall();

                    // Permanently mask mainline NCEs and TCEs.
                    MemDbUtils::banTps<T>( iv_chip, iv_rank );
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
            MemDbUtils::banTps<T>( iv_chip, iv_rank );
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
        o_rc = setBadDqBitmap( trgt, iv_rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setBadDqBitmap(0x%08x, 0x%02x) failed",
                      getHuid(trgt), iv_rank.getKey() );
            break;
        }

        // We may have placed a chip mark so do any necessary cleanup. This must
        // be called after writing the bad DQ bitmap because this function
        // will also write it if necessary. If we added a VCM event to the
        // queue, we will skip this and let that VCM event handle the cleanup
        // of the chip mark once it finishes.
        if ( !vcmQueued )
        {
            bool junk = false;
            o_rc = MarkStore::chipMarkCleanup<T>(iv_chip, iv_rank, io_sc, junk);
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "MarkStore::chipMarkCleanup(0x%08x,0x%02x) "
                          "failed", iv_chip->getHuid(), getKey() );
                break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t TpsEvent<TYPE_OCMB_CHIP>::analyzeCeSymbolCounts( CeCount i_badDqCount,
    CeCount i_badChipCount, CeCount i_sumAboveOneCount,
    CeCount i_singleSymCount, STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<>
uint32_t TpsEvent<TYPE_OCMB_CHIP>::getSymbolCeCounts( CeCount & io_badDqCount,
    CeCount & io_badChipCount, CeCount & io_sumAboveOneCount,
    CeCount & io_singleSymCount, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_OCMB_CHIP>::getSymbolCeCounts] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get the Bad DQ Bitmap.
        TargetHandle_t ocmbTrgt = iv_chip->getTrgt();
        MemDqBitmap dqBitmap;

        o_rc = getBadDqBitmap( ocmbTrgt, iv_rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap(0x%08x,%d) failed",
                      getHuid(ocmbTrgt), iv_rank.getMaster() );
            break;
        }
        std::vector<MemSymbol> bmSymList = dqBitmap.getSymbolList();

        const char * reg_str = nullptr;
        SCAN_COMM_REGISTER_CLASS * reg = nullptr;

        for ( uint8_t regIdx = 0; regIdx < CE_REGS_PER_PORT; regIdx++ )
        {
            reg_str = ocmbCeStatReg[regIdx];
            reg     = iv_chip->getRegister( reg_str );

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
                    symData.symbol = MemSymbol::fromSymbol( ocmbTrgt, iv_rank,
                        sym );
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
                        MemoryMru mm { ocmbTrgt, iv_rank, symData.symbol };
                        io_sc.service_data->SetCallout( mm );
                    }
                }
                if ( SUCCESS != o_rc ) break;

                // Analyze the nibble of symbols.
                __analyzeNibbleSyms<TYPE_OCMB_CHIP>( nibbleStats, io_badDqCount,
                    io_badChipCount, io_sumAboveOneCount, io_singleSymCount );

            }
            if ( SUCCESS != o_rc ) break;
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t TpsEvent<T>::analyzeCeStats( STEP_CODE_DATA_STRUCT & io_sc,
                                      bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<T>::analyzeCeStats] "

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

template
uint32_t TpsEvent<TYPE_OCMB_CHIP>::analyzeCeStats(STEP_CODE_DATA_STRUCT & io_sc,
                                                  bool & o_done);

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t TpsEvent<T>::analyzePhase( STEP_CODE_DATA_STRUCT & io_sc,
                                    bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent::analyzePhase] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( TD_PHASE_0 == iv_phase ) break; // Nothing to analyze yet.

        // Analyze Ecc Attentions
        uint32_t eccAttns;
        o_rc = checkEccFirs<T>( iv_chip, eccAttns );
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
        MemDbUtils::resetEccFfdc<T>( iv_chip, iv_rank, SLAVE_RANK );
    }

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t TpsEvent<TYPE_OCMB_CHIP>::analyzePhase( STEP_CODE_DATA_STRUCT & io_sc,
                                                 bool & o_done );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t TpsEvent<T>::startNextPhase( STEP_CODE_DATA_STRUCT & io_sc )
{
    uint32_t signature = 0;

    __getNextPhase<T>( iv_chip, iv_rank, io_sc, iv_phase, signature );

    PRDF_TRAC( "[TpsEvent] Starting TPS Phase %d: 0x%08x,0x%02x",
               iv_phase, iv_chip->getHuid(), getKey() );

    io_sc.service_data->AddSignatureList( iv_chip->getTrgt(), signature );

    return startCmd();
}

template
uint32_t TpsEvent<TYPE_OCMB_CHIP>::startNextPhase(
    STEP_CODE_DATA_STRUCT & io_sc );

//##############################################################################
//
//                          Specializations for OCMB
//
//##############################################################################

template<>
uint32_t TpsEvent<TYPE_OCMB_CHIP>::startCmd()
{
    #define PRDF_FUNC "[TpsEvent::startCmd] "

    uint32_t o_rc = SUCCESS;

    // We don't need to set any stop-on-error conditions or thresholds for
    // soft/inter/hard CEs at runtime. The design is to let the command continue
    // to the end of the rank and we do diagnostics on the CE counts found in
    // the per-symbol counters. Therefore, all we need to do is tell the
    // hardware which CE types to count.

    mss::mcbist::stop_conditions<mss::mc_type::EXPLORER> stopCond;

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
    o_rc = startTdScrub<TYPE_OCMB_CHIP>(iv_chip, iv_rank, SLAVE_RANK, stopCond);
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x) failed",
                  iv_chip->getHuid(), getKey() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF

