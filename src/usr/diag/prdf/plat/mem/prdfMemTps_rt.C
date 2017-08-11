/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTps_rt.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include <prdfMemEccAnalysis.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTdFalseAlarm.H>
#include <prdfMemTps.H>
#include <prdfP9McaExtraSig.H>
#include <prdfP9McaDataBundle.H>
#include <prdfTargetServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

const uint8_t CE_REGS_PER_PORT = 9;
const uint8_t SYMBOLS_PER_CE_REG = 8;

//TODO RTC 166802
/*
static const char *mbsCeStatReg[][ CE_REGS_PER_PORT ] = {
                       { "MBA0_MBSSYMEC0", "MBA0_MBSSYMEC1","MBA0_MBSSYMEC2",
                         "MBA0_MBSSYMEC3", "MBA0_MBSSYMEC4", "MBA0_MBSSYMEC5",
                         "MBA0_MBSSYMEC6", "MBA0_MBSSYMEC7", "MBA0_MBSSYMEC8" },
                       { "MBA1_MBSSYMEC0", "MBA1_MBSSYMEC1","MBA1_MBSSYMEC2",
                         "MBA1_MBSSYMEC3", "MBA1_MBSSYMEC4", "MBA1_MBSSYMEC5",
                         "MBA1_MBSSYMEC6", "MBA1_MBSSYMEC7", "MBA1_MBSSYMEC8" }
                          };
*/

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

//------------------------------------------------------------------------------

template<>
TpsFalseAlarm * __getTpsFalseAlarmCounter<TYPE_MBA>( ExtensibleChip * i_chip )
{
    // TODO RTC 157888
    //return getMbaDataBundle(i_chip)->getTpsFalseAlarmCounter();
    return nullptr;
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
                    sum += sumCheck.count;
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
void __nonZeroSumCount( MemUtils::MaintSymbols i_nibbleStats,
                        CeCount & io_nonZeroSumCount );

template<>
void __nonZeroSumCount<TYPE_MCA>( MemUtils::MaintSymbols i_nibbleStats,
                                  CeCount & io_nonZeroSumCount )
{
    for ( auto symData : i_nibbleStats )
    {
        // If there is a non-zero sum.
        if ( symData.count != 0 )
        {
            io_nonZeroSumCount.count++;
            break;
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
    // Count to keep track of the number of symbols whose CE count was > 1
    uint8_t count = 0;

    for ( auto symData : i_nibbleStats )
    {
        if ( symData.count > 1 )
            count++;
    }

    // If there was only 1 symbol whose CE count was > 1.
    if ( 1 == count )
        io_singleSymCount.count++;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __analyzeNibbleSyms( MemUtils::MaintSymbols i_nibbleStats,
    CeCount & io_badDqCount, CeCount & io_badChipCount,
    CeCount & io_nonZeroSumCount, CeCount & io_singleSymCount )
{

    do
    {
        // Check if this nibble has a bad dq.
        if ( __badDqCount<T>( i_nibbleStats, io_badDqCount ) )
            break;

        // Check if this nibble has a bad chip.
        if ( __badChipCount<T>( i_nibbleStats, io_badChipCount ) )
            break;

        // Check if this nibble is under threshold with a non-zero sum.
        __nonZeroSumCount<T>( i_nibbleStats, io_nonZeroSumCount );

        // Check if this nibble is under threshold with a single symbol count
        // greater than 1.
        __singleSymbolCount<T>( i_nibbleStats, io_singleSymCount );

    }while(0);
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t TpsEvent<T>::startTpsPhase1_rt( STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_TRAC( "[TpsEvent] Starting TPS Phase 1: 0x%08x,0x%02x",
               iv_chip->getHuid(), getKey() );

    iv_phase = TD_PHASE_1;
    io_sc.service_data->AddSignatureList( iv_chip->getTrgt(),
                                          PRDFSIG_StartTpsPhase1 );
    bool countAllCes = false;
    if ( __getTpsFalseAlarmCounter<T>(iv_chip)->count(iv_rank, io_sc) >= 1 )
        countAllCes = true;

    return PlatServices::startTpsRuntime<T>( iv_chip, iv_rank, countAllCes);
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t TpsEvent<T>::analyzeTpsPhase1_rt( STEP_CODE_DATA_STRUCT & io_sc,
                                           bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<T>::analyzeTpsPhase1_rt] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Analyze Ecc Attentions
        uint32_t eccAttns;
        o_rc = checkEccFirs<T>( iv_chip, eccAttns );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccFirs(0x%08x) failed",
                    iv_chip->getHuid() );
            break;
        }

        o_rc = analyzeEcc( eccAttns, io_sc, o_done );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeEcc() failed." );
            break;
        }
        if ( o_done ) break;


        // Analyze CEs
        o_rc = analyzeCe( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeCe() failed." );
            break;
        }

        // At this point, we are done with the procedure.
        o_done = true;

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <>
uint32_t TpsEvent<TYPE_MCA>::analyzeEcc( const uint32_t & i_eccAttns,
                                         STEP_CODE_DATA_STRUCT & io_sc,
                                         bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MCA>::analyzeEcc] "

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

            o_rc = MemEcc::handleMemIue<TYPE_MCA, McaDataBundle *>( iv_chip,
                                                                    iv_rank,
                                                                    io_sc );
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

            o_rc = MemEcc::handleMpe<TYPE_MCA, McaDataBundle *>( iv_chip,
                iv_rank, io_sc );
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
uint32_t TpsEvent<TYPE_MCA>::getSymbolCeCounts( CeCount & io_badDqCount,
    CeCount & io_badChipCount, CeCount & io_nonZeroSumCount,
    CeCount & io_singleSymCount, MemUtils::MaintSymbols & o_symList,
    STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MCA>::getSymbolCeCounts] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get the Bad DQ Bitmap.
        TargetHandle_t mcaTrgt = iv_chip->getTrgt();
        MemDqBitmap<DIMMS_PER_RANK::MCA> dqBitmap;

        o_rc = getBadDqBitmap<DIMMS_PER_RANK::MCA>(mcaTrgt, iv_rank, dqBitmap);
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap<DIMMS_PER_RANK::MCA>"
                      "(0x%08x,%d) failed", getHuid(mcaTrgt),
                      iv_rank.getMaster() );
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
                  i += MCA_SYMBOLS_PER_NIBBLE )
            {
                MemUtils::MaintSymbols nibbleStats;

                // Get a nibble's worth of symbols.
                for ( uint8_t n = 0; n < MCA_SYMBOLS_PER_NIBBLE; n++ )
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
                    if ( symData.count > 0 )
                        o_symList.push_back( symData );

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
                    io_badChipCount, io_nonZeroSumCount, io_singleSymCount );

            }
            if ( SUCCESS != o_rc ) break;
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

template <>
uint32_t TpsEvent<TYPE_MCA>::analyzeCe( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MCA>::analyzeCe] "

    uint32_t o_rc = SUCCESS;

    do
    {



        // The symbol CE counts will be summarized in the following buckets:
        // Number of nibbles with a bad DQ
        // Number of nibbles with a bad chip
        // Number of nibbles under threshold with a non-zero sum
        // Number of nibbles under threshold with a single symbol count > 1
        CeCount badDqCount, badChipCount, nonZeroSumCount, singleSymCount;
        MemUtils::MaintSymbols symList;

        // Get the symbol CE counts.
        o_rc = getSymbolCeCounts( badDqCount, badChipCount, nonZeroSumCount,
                                  singleSymCount, symList, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getSymbolCeCounts failed." );
            break;
        }

        // If DRAM repairs are disabled, make the error log predictive and
        // abort this procedure.
        if ( areDramRepairsDisabled() )
        {
            io_sc.service_data->setServiceCall();
            break;
        }

        // Analyze the symbol CE counts.
        //TODO RTC 171914

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

// TODO: RTC 171914 Actual implementation of this procedure will be done later.
template<>
uint32_t TpsEvent<TYPE_MCA>::nextStep( STEP_CODE_DATA_STRUCT & io_sc,
                                       bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MCA>::nextStep] "

    uint32_t o_rc = SUCCESS;

    o_done = false;

    switch ( iv_phase )
    {
        case TD_PHASE_0:
            // Start TPS phase 1
            o_rc = startTpsPhase1_rt( io_sc );
            break;
        case TD_PHASE_1:
            // Analyze TPS phase 1
            o_rc = analyzeTpsPhase1_rt( io_sc, o_done );
            break;
        default: PRDF_ASSERT( false ); // invalid phase

    }

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "TPS failed: 0x%08x,0x%02x", iv_chip->getHuid(),
                  getKey() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// TODO: RTC 157888 Actual implementation of this procedure will be done later.
template<>
uint32_t TpsEvent<TYPE_MBA>::nextStep( STEP_CODE_DATA_STRUCT & io_sc,
                                       bool & o_done )
{
    #define PRDF_FUNC "[TpsEvent<TYPE_MBA>::nextStep] "

    uint32_t o_rc = SUCCESS;

    o_done = true;

    PRDF_ERR( PRDF_FUNC "function not implemented yet" );

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF

