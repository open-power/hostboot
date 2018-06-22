/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemUtils.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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

/** @file  prdfMemUtils.C
 *  @brief Utility functions related to memory
 */

#include <prdfMemUtils.H>

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>

// Platform includes
#include <prdfCenMbaDataBundle.H>
#include <prdfCenMembufDataBundle.H>
#include <prdfMemSymbol.H>
#include <prdfParserUtils.H>
#include <prdfPlatServices.H>

#if __HOSTBOOT_RUNTIME
  #include <prdfMemDynDealloc.H>
#endif

using namespace TARGETING;

namespace PRDF
{

namespace MemUtils
{

using namespace PlatServices;
using namespace PARSERUTILS;
using namespace CEN_SYMBOL;

const uint8_t CE_REGS_PER_PORT = 9;
const uint8_t SYMBOLS_PER_CE_REG = 8;

static const char *mbsCeStatReg[][ CE_REGS_PER_PORT ] = {
                       { "MBA0_MBSSYMEC0", "MBA0_MBSSYMEC1","MBA0_MBSSYMEC2",
                         "MBA0_MBSSYMEC3", "MBA0_MBSSYMEC4", "MBA0_MBSSYMEC5",
                         "MBA0_MBSSYMEC6", "MBA0_MBSSYMEC7", "MBA0_MBSSYMEC8" },
                       { "MBA1_MBSSYMEC0", "MBA1_MBSSYMEC1","MBA1_MBSSYMEC2",
                         "MBA1_MBSSYMEC3", "MBA1_MBSSYMEC4", "MBA1_MBSSYMEC5",
                         "MBA1_MBSSYMEC6", "MBA1_MBSSYMEC7", "MBA1_MBSSYMEC8" }
                          };


static const char *mcbCeStatReg[CE_REGS_PER_PORT] =
                       {
                           "MCB_MBSSYMEC0", "MCB_MBSSYMEC1", "MCB_MBSSYMEC2",
                           "MCB_MBSSYMEC3", "MCB_MBSSYMEC4", "MCB_MBSSYMEC5",
                           "MCB_MBSSYMEC6", "MCB_MBSSYMEC7", "MCB_MBSSYMEC8"
                       };

//------------------------------------------------------------------------------

// Helper structs for collectCeStats()
struct DramCount_t
{
    uint8_t totalCount; uint8_t symbolCount;
    DramCount_t() : totalCount(0), symbolCount(0) {}
};
typedef std::map<uint32_t, DramCount_t> DramCountMap;

//------------------------------------------------------------------------------
template<>
int32_t collectCeStats<TYPE_MCA>( ExtensibleChip * i_chip,
                        const MemRank & i_rank, MaintSymbols & o_maintStats,
                        MemSymbol & o_chipMark, uint8_t i_thr )
{
    #define PRDF_FUNC "[MemUtils::collectCeStats<TYPE_MCA>] "

    int32_t o_rc = SUCCESS;
    o_chipMark = MemSymbol(); // Initially invalid.

    do
    {
        PRDF_ASSERT( 0 != i_thr );

        TargetHandle_t mcaTrgt = i_chip->getTrgt();
        ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );

        const bool isX4 = isDramWidthX4(mcaTrgt);

        // Use this map to keep track of the total counts per DRAM.
        DramCountMap dramCounts;

        const char * reg_str = NULL;
        SCAN_COMM_REGISTER_CLASS * reg = NULL;

        for ( uint8_t regIdx = 0; regIdx < CE_REGS_PER_PORT; regIdx++ )
        {
            reg_str = mcbCeStatReg[regIdx];
            reg     = mcbChip->getRegister( reg_str );

            o_rc = reg->Read();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Read() failed on %s", reg_str );
                break;
            }

            uint8_t baseSymbol = SYMBOLS_PER_CE_REG * regIdx;

            for ( uint8_t i = 0; i < SYMBOLS_PER_CE_REG; i++ )
            {
                uint8_t count = reg->GetBitFieldJustified( (i*8), 8 );

                if ( 0 == count ) continue; // nothing to do

                uint8_t sym  = baseSymbol + i;
                PRDF_ASSERT( sym < SYMBOLS_PER_RANK );

                uint8_t dram = isX4 ? symbol2Nibble<TYPE_MCA>( sym )
                                    : symbol2Byte  <TYPE_MCA>( sym );

                // Keep track of the total DRAM counts.
                dramCounts[dram].totalCount += count;

                // Add any symbols that have exceeded threshold to the list.
                if ( i_thr <= count )
                {
                    // Keep track of the total number of symbols per DRAM that
                    // have exceeded threshold.
                    dramCounts[dram].symbolCount++;

                    SymbolData symData;
                    symData.symbol = MemSymbol::fromSymbol( mcaTrgt, i_rank,
                                               sym, CEN_SYMBOL::ODD_SYMBOL_DQ );
                    if ( !symData.symbol.isValid() )
                    {
                        PRDF_ERR( PRDF_FUNC "MemSymbol() failed: symbol=%d",
                                  sym );
                        o_rc = FAIL;
                        break;
                    }
                    else
                    {
                        // Add the symbol to the list.
                        symData.count = count;
                        o_maintStats.push_back( symData );
                    }
                }
            }
            if ( SUCCESS != o_rc ) break;
        }
        if ( SUCCESS != o_rc ) break;

        if ( o_maintStats.empty() ) break; // no need to continue

        // Sort the list of symbols.
        std::sort( o_maintStats.begin(), o_maintStats.end(), sortSymDataCount );

        // Get the DRAM with the highest count.
        uint32_t highestDram  = 0;
        uint32_t highestCount = 0;
        const uint32_t symbolTH = isX4 ? 1 : 2;
        for ( DramCountMap::iterator it = dramCounts.begin();
              it != dramCounts.end(); ++it )
        {
            if ( (symbolTH     <= it->second.symbolCount) &&
                 (highestCount <  it->second.totalCount ) )
            {
                highestDram  = it->first;
                highestCount = it->second.totalCount;
            }
        }

        if ( 0 != highestCount )
        {
            uint8_t sym = isX4 ? nibble2Symbol<TYPE_MCA>( highestDram )
                               : byte2Symbol  <TYPE_MCA>( highestDram );
            PRDF_ASSERT( sym < SYMBOLS_PER_RANK );

            o_chipMark  = MemSymbol::fromSymbol( mcaTrgt, i_rank, sym );
        }

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed: i_chip=0x%08x i_rank=m%ds%d i_thr=%d",
                  i_chip->GetId(), i_rank.getMaster(), i_rank.getSlave(),
                  i_thr );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
int32_t collectCeStats<TYPE_MBA>( ExtensibleChip * i_chip,
                        const MemRank & i_rank, MaintSymbols & o_maintStats,
                        MemSymbol & o_chipMark, uint8_t i_thr )
{
    #define PRDF_FUNC "[MemUtils::collectCeStats<TYPE_MBA>] "

    int32_t o_rc = SUCCESS;

    o_chipMark = MemSymbol(); // Initially invalid.

    do
    {
        if ( 0 == i_thr ) // Must be non-zero
        {
            PRDF_ERR( PRDF_FUNC "i_thr %d is invalid", i_thr );
            o_rc = FAIL; break;
        }

        TargetHandle_t mbaTrgt = i_chip->getTrgt();
        ExtensibleChip * membufChip = getConnectedParent(i_chip, TYPE_MEMBUF);
        if ( nullptr == membufChip )
        {
            PRDF_ERR( PRDF_FUNC "getMembChip() failed" );
            o_rc = FAIL; break;
        }

        uint8_t mbaPos = getTargetPosition( mbaTrgt );
        if ( MAX_MBA_PER_MEMBUF <= mbaPos )
        {
            PRDF_ERR( PRDF_FUNC "mbaPos %d is invalid", mbaPos );
            o_rc = FAIL; break;
        }

        const bool isX4 = isDramWidthX4(mbaTrgt);

        // Get the current spares on this rank.
        MemSymbol sp0, sp1, ecc;
        o_rc = mssGetSteerMux<TYPE_MBA>( mbaTrgt, i_rank, sp0, sp1, ecc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed." );
            break;
        }


        // Use this map to keep track of the total counts per DRAM.
        DramCountMap dramCounts;

        const char * reg_str = NULL;
        SCAN_COMM_REGISTER_CLASS * reg = NULL;

        for ( uint8_t regIdx = 0; regIdx < CE_REGS_PER_PORT; regIdx++ )
        {
            reg_str = mbsCeStatReg[mbaPos][regIdx];
            reg     = membufChip->getRegister( reg_str );

            o_rc = reg->Read();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Read() failed on %s", reg_str );
                break;
            }

            uint8_t baseSymbol = SYMBOLS_PER_CE_REG * regIdx;

            for ( uint8_t i = 0; i < SYMBOLS_PER_CE_REG; i++ )
            {
                uint8_t count = reg->GetBitFieldJustified( (i*8), 8 );

                if ( 0 == count ) continue; // nothing to do

                uint8_t sym  = baseSymbol + i;

                uint8_t dram = isX4 ? symbol2Nibble<TYPE_MBA>( sym )
                                    : symbol2Byte  <TYPE_MBA>( sym );


                // Keep track of the total DRAM counts.
                dramCounts[dram].totalCount += count;

                // Add any symbols that have exceeded threshold to the list.
                if ( i_thr <= count )
                {
                    // Keep track of the total number of symbols per DRAM that
                    // have exceeded threshold.
                    dramCounts[dram].symbolCount++;

                    SymbolData symData;
                    symData.symbol = MemSymbol::fromSymbol( mbaTrgt, i_rank,
                                            sym, CEN_SYMBOL::BOTH_SYMBOL_DQS );
                    if ( !symData.symbol.isValid() )
                    {
                        PRDF_ERR( PRDF_FUNC "MemSymbol() failed: symbol=%d",
                                  sym );
                        o_rc = FAIL;
                        break;
                    }
                    else
                    {
                        // Check if this symbol is on any of the spares.
                        symData.symbol.updateSpared(sp0, sp1, ecc);

                        // Add the symbol to the list.
                        symData.count = count;
                        o_maintStats.push_back( symData );
                    }
                }
            }
            if ( SUCCESS != o_rc ) break;
        }
        if ( SUCCESS != o_rc ) break;

        if ( o_maintStats.empty() ) break; // no need to continue

        // Sort the list of symbols.
        std::sort( o_maintStats.begin(), o_maintStats.end(), sortSymDataCount );

        // Get the DRAM with the highest count.
        uint32_t highestDram  = 0;
        uint32_t highestCount = 0;
        const uint32_t symbolTH = isX4 ? 1 : 2;
        for ( DramCountMap::iterator it = dramCounts.begin();
              it != dramCounts.end(); ++it )
        {
            if ( (symbolTH     <= it->second.symbolCount) &&
                 (highestCount <  it->second.totalCount ) )
            {
                highestDram  = it->first;
                highestCount = it->second.totalCount;
            }
        }

        if ( 0 != highestCount )
        {
            uint8_t sym = isX4 ? nibble2Symbol<TYPE_MBA>( highestDram )
                               : byte2Symbol  <TYPE_MBA>( highestDram );
            PRDF_ASSERT( sym < SYMBOLS_PER_RANK );

            o_chipMark  = MemSymbol::fromSymbol( mbaTrgt, i_rank, sym );

            // Check if this symbol is on any of the spares.
            o_chipMark.updateSpared(sp0, sp1, ecc);
        }

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed: i_mbaChip=0x%08x i_rank=m%ds%d i_thr=%d",
                  i_chip->GetId(), i_rank.getMaster(), i_rank.getSlave(),
                  i_thr );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint8_t getDramSize<TYPE_MCA>(ExtensibleChip *i_chip, uint8_t i_dimmSlct)
{
    #define PRDF_FUNC "[MemUtils::getDramSize] "

    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );
    PRDF_ASSERT( i_dimmSlct < DIMM_SLCT_PER_PORT );

    TargetHandle_t mcaTrgt = i_chip->getTrgt();
    TargetHandle_t mcsTrgt = getConnectedParent( mcaTrgt, TYPE_MCS );

    PRDF_ASSERT( nullptr != mcsTrgt );

    uint8_t mcaRelPos = i_chip->getPos() % MAX_MCA_PER_MCS;

    uint8_t tmp[MAX_MCA_PER_MCS][DIMM_SLCT_PER_PORT];

    if ( !mcsTrgt->tryGetAttr<TARGETING::ATTR_EFF_DRAM_DENSITY>(tmp) )
    {
        PRDF_ERR( PRDF_FUNC "Failed to get ATTR_EFF_DRAM_DENSITY" );
        PRDF_ASSERT( false );
    }

    return tmp[mcaRelPos][i_dimmSlct];

    #undef PRDF_FUNC
}

template<>
uint8_t getDramSize<TYPE_MBA>(ExtensibleChip *i_chip, uint8_t i_dimmSlct)
{
    #define PRDF_FUNC "[MemUtils::getDramSize] "

    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint8_t o_size = 0;

    do
    {
        ExtensibleChip * membufChip = getConnectedParent(i_chip, TYPE_MEMBUF);

        uint32_t pos = i_chip->getPos();
        const char * reg_str = (0 == pos) ? "MBA0_MBAXCR" : "MBA1_MBAXCR";

        SCAN_COMM_REGISTER_CLASS * reg = membufChip->getRegister( reg_str );
        uint32_t rc = reg->Read();
        if ( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s. Target=0x%08x",
                      reg_str, i_chip->getHuid() );
            break;
        }

        // The value of MBAXCR[6:7] is 0 = 2Gb, 1 = 4Gb, 2 = 8Gb, and 3 = 16 Gb.
        // Therefore, to get the DRAM size do the following:
        //      DRAM size = 2 ^ (MBAXCR[6:7] + 1)
        o_size = 1 << (reg->GetBitFieldJustified(6,2) + 1);

    } while(0);

    return o_size;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
void cleanupChnlAttns<TYPE_MEMBUF>( ExtensibleChip * i_chip,
                                    STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemUtils::cleanupChnlAttns] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEMBUF == i_chip->getType() );

    // No cleanup if this is a checkstop attention.
    if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() ) return;

    #ifdef __HOSTBOOT_MODULE // only do cleanup in Hostboot, no-op in FSP

    ExtensibleChip * dmiChip = getConnectedParent( i_chip, TYPE_DMI );

    // Clear the associated FIR bits for all attention types.
    // NOTE: If there are any active attentions left in the Centaur the
    //       associated FIR bits in the CHIFIR will be redriven with the
    //       next packet on the bus.

    SCAN_COMM_REGISTER_CLASS * reg = dmiChip->getRegister("CHIFIR_AND");

    reg->setAllBits();
    reg->ClearBit(16); // CS
    reg->ClearBit(19); // RE
    reg->ClearBit(20); // SPA
    reg->ClearBit(21); // maintenance command complete

    reg->Write();

    #endif // Hostboot only

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __queryChnlFail( ExtensibleChip * i_chip, bool & o_chnlFail );

template<>
uint32_t __queryChnlFail<TYPE_MEMBUF>( ExtensibleChip * i_chip,
                                       bool & o_chnlFail )
{
    #define PRDF_FUNC "[MemUtils::__queryChnlFail] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEMBUF == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    o_chnlFail = false;

    do
    {
        // Simply check the Centaur CS global reg for active attentions.
        SCAN_COMM_REGISTER_CLASS * fir = i_chip->getRegister("GLOBAL_CS_FIR");
        o_rc = fir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read GLOBAL_CS_FIR on 0x%08x",
                      i_chip->getHuid() );
            break;
        }

        o_chnlFail = !fir->BitStringIsZero();

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t __queryChnlFail<TYPE_DMI>( ExtensibleChip * i_chip, bool & o_chnlFail )
{
    #define PRDF_FUNC "[MemUtils::__queryChnlFail] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_DMI == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    o_chnlFail = false;

    SCAN_COMM_REGISTER_CLASS * fir  = nullptr;
    SCAN_COMM_REGISTER_CLASS * mask = nullptr;
    SCAN_COMM_REGISTER_CLASS * act0 = nullptr;
    SCAN_COMM_REGISTER_CLASS * act1 = nullptr;

    do
    {
        // There is a HWP on the processor side that will query if this channel
        // has failed. Unfortunately, it does not check for an active channel
        // fail attention (i.e. not masked). That will need to be done
        // afterwards.
        bool tmpChnlFail = false;
        o_rc = PlatServices::queryChnlFail<TYPE_DMI>( i_chip, tmpChnlFail );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read GLOBAL_CS_FIR on 0x%08x",
                      i_chip->getHuid() );
            break;
        }
        if ( !tmpChnlFail ) break; // nothing more to do.

        // Check for an active attention on the CHIFIR.
        fir  = i_chip->getRegister( "CHIFIR" );
        mask = i_chip->getRegister( "CHIFIR_MASK" );
        act0 = i_chip->getRegister( "CHIFIR_ACT0" );
        act1 = i_chip->getRegister( "CHIFIR_ACT1" );
        o_rc = fir->Read() | mask->Read() | act0->Read() | act1->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read CHIFIRs on 0x%08x",
                      i_chip->getHuid() );
            break;
        }

        if ( 0 != (  fir->GetBitFieldJustified( 0,64) &
                    ~mask->GetBitFieldJustified(0,64) &
                     act0->GetBitFieldJustified(0,64) &
                     act1->GetBitFieldJustified(0,64) ) )
        {
            o_chnlFail = true;
            break; // nothing more to do.
        }

        // Check for an active attention on the IOMCFIR.
        ExtensibleChip * mcChip = getConnectedParent( i_chip, TYPE_MC );
        uint32_t dmiPos = i_chip->getPos() % MAX_DMI_PER_MC;
        uint32_t bitPos = 8 + dmiPos * 8;

        fir  = mcChip->getRegister( "IOMCFIR" );
        mask = mcChip->getRegister( "IOMCFIR_MASK" );
        act0 = mcChip->getRegister( "IOMCFIR_ACT0" );
        act1 = mcChip->getRegister( "IOMCFIR_ACT1" );
        o_rc = fir->Read() | mask->Read() | act0->Read() | act1->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read IOMCFIRs on 0x%08x",
                      mcChip->getHuid() );
            break;
        }

        if ( 0 != (  fir->GetBitFieldJustified( bitPos,8) &
                    ~mask->GetBitFieldJustified(bitPos,8) &
                     act0->GetBitFieldJustified(bitPos,8) &
                     act1->GetBitFieldJustified(bitPos,8) ) )
        {
            o_chnlFail = true;
            break; // nothing more to do.
        }

        PRDF_INF( PRDF_FUNC "Failed channel detected on 0x%08x, but no active "
                  "attentions found", i_chip->getHuid() );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __setChnlFailCleanup( ExtensibleChip * i_chip );

template<>
void __setChnlFailCleanup<TYPE_MEMBUF>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEMBUF == i_chip->getType() );

    getMembufDataBundle(i_chip)->iv_doChnlFailCleanup = true;
}

template<>
void __setChnlFailCleanup<TYPE_DMI>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_DMI == i_chip->getType() );

    ExtensibleChip * membChip = getConnectedChild( i_chip, TYPE_MEMBUF, 0 );
    PRDF_ASSERT( nullptr != membChip ); // shouldn't be possible

    __setChnlFailCleanup<TYPE_MEMBUF>( membChip );
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t handleChnlFail( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // Skip if already handling channel failure.
        if ( io_sc.service_data->IsUnitCS() ) break;

        // Skip if currently analyzing a host attention. This is a required for
        // a rare scenario when a channel failure occurs after PRD is called to
        // handle the host attention.
        if ( HOST_ATTN == io_sc.service_data->getPrimaryAttnType() ) break;

        // Look for the channel fail attention.
        bool isChnlFail = false;
        uint32_t o_rc = __queryChnlFail<T>( i_chip, isChnlFail );
        if ( SUCCESS != o_rc ) break;

        if ( ! isChnlFail ) break; // No channel fail, nothing more to do.

        // Change the secondary attention type to UNIT_CS so the rule code will
        // start looking for UNIT_CS attentions instead of recoverable.
        io_sc.service_data->setSecondaryAttnType( UNIT_CS );

        // Set the UNIT_CS flag in the SDC to indicate a channel failure has
        // been detected and there is no need to check again.
        io_sc.service_data->setFlag( ServiceDataCollector::UNIT_CS );

        // Make the error log predictive and set threshold.
        io_sc.service_data->setFlag( ServiceDataCollector::SERVICE_CALL );
        io_sc.service_data->setFlag( ServiceDataCollector::AT_THRESHOLD );

        // Channel failures will always send SUEs.
        io_sc.service_data->setFlag( ServiceDataCollector::UERE );

        // Indicate cleanup is required on this channel.
        __setChnlFailCleanup<T>( i_chip );

    } while (0);

    return o_rc;
}

template
uint32_t handleChnlFail<TYPE_MEMBUF>( ExtensibleChip * i_chip,
                                      STEP_CODE_DATA_STRUCT & io_sc );
template
uint32_t handleChnlFail<TYPE_DMI>( ExtensibleChip * i_chip,
                                   STEP_CODE_DATA_STRUCT & io_sc );

template<>
uint32_t handleChnlFail<TYPE_MC>( ExtensibleChip * i_chip,
                                  STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MC == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    for ( auto & dmiChip : getConnected(i_chip, TYPE_DMI) )
    {
        o_rc = handleChnlFail<TYPE_DMI>( dmiChip, io_sc );
        if ( SUCCESS != o_rc ) break;
    }

    return o_rc;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T1, TARGETING::TYPE T2>
void __cleanupChnlFail( ExtensibleChip * i_chip1, ExtensibleChip * i_chip2,
                        STEP_CODE_DATA_STRUCT & io_sc );

template<>
void __cleanupChnlFail<TYPE_DMI,TYPE_MEMBUF>( ExtensibleChip * i_dmiChip,
                                              ExtensibleChip * i_membChip,
                                              STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemUtils::__cleanupChnlFail] "

    PRDF_ASSERT( nullptr != i_dmiChip );
    PRDF_ASSERT( TYPE_DMI == i_dmiChip->getType() );

    PRDF_ASSERT( nullptr != i_membChip );
    PRDF_ASSERT( TYPE_MEMBUF == i_membChip->getType() );

    // No cleanup if this is a checkstop attention.
    if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() ) return;

    // Check if cleanup is still required or has already been done.
    if ( ! getMembufDataBundle(i_membChip)->iv_doChnlFailCleanup ) return;

    // Cleanup is complete and no longer required on this channel.
    getMembufDataBundle(i_membChip)->iv_doChnlFailCleanup = false;

    #ifdef __HOSTBOOT_MODULE // only do cleanup in Hostboot, no-op in FSP

    // Note that this is a clean up function. If there are any SCOM errors
    // we will just move on and try the rest.

    SCAN_COMM_REGISTER_CLASS * reg = nullptr;
    ExtensibleChip * mcChip = getConnectedParent( i_dmiChip, TYPE_MC );
    uint32_t dmiPos = i_dmiChip->getPos() % MAX_DMI_PER_MC;

    // Mask off all attentions from the DMI target in the CHIFIR.
    reg = i_dmiChip->getRegister( "CHIFIR_MASK_OR" );
    reg->setAllBits();
    reg->Write();

    // Mask off all attentions from the DMI target in the IOMCFIR.
    reg = mcChip->getRegister( "IOMCFIR_MASK_OR" );
    reg->SetBitFieldJustified( 8 + (dmiPos * 8), 8, 0xff ); // 8, 16, 24, 32
    reg->Write();

    // Mask off all attentions from the MEMBUF target in the chiplet FIRs.
    const char * reg_strs[] { "TP_CHIPLET_FIR_MASK",
                              "NEST_CHIPLET_FIR_MASK",
                              "MEM_CHIPLET_FIR_MASK",
                              "MEM_CHIPLET_SPA_FIR_MASK" };
    for ( auto & reg_str : reg_strs )
    {
        reg = i_membChip->getRegister( reg_str );
        reg->setAllBits(); // Blindly mask everything
        reg->Write();
    }

    // For all attached MBAs:
    //   During runtime, send a dynamic memory deallocation message.
    //   During Memory Diagnostics, tell MDIA to stop pattern tests.
    for ( auto & mbaChip : getConnected(i_membChip, TYPE_MBA) )
    {
        #ifdef __HOSTBOOT_RUNTIME
        MemDealloc::port<TYPE_MBA>( mbaChip );
        #else
        if ( isInMdiaMode() )
            mdiaSendEventMsg( mbaChip->getTrgt(), MDIA::STOP_TESTING );
        #endif
    }

    #endif // Hostboot only

    #undef PRDF_FUNC
}

template<>
void cleanupChnlFail<TYPE_MEMBUF>( ExtensibleChip * i_chip,
                                   STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEMBUF == i_chip->getType() );

    ExtensibleChip * dmiChip = getConnectedParent( i_chip, TYPE_DMI );

    __cleanupChnlFail<TYPE_DMI,TYPE_MEMBUF>( dmiChip, i_chip, io_sc );
}

template<>
void cleanupChnlFail<TYPE_DMI>( ExtensibleChip * i_chip,
                                STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_DMI == i_chip->getType() );

    ExtensibleChip * membChip = getConnectedChild( i_chip, TYPE_MEMBUF, 0 );
    PRDF_ASSERT( nullptr != membChip ); // shouldn't be possible

    __cleanupChnlFail<TYPE_DMI,TYPE_MEMBUF>( i_chip, membChip, io_sc );
}

template<>
void cleanupChnlFail<TYPE_MC>( ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MC == i_chip->getType() );

    for ( auto & dmiChip : getConnected(i_chip, TYPE_DMI) )
    {
        cleanupChnlFail<TYPE_DMI>( dmiChip, io_sc );
    }
}

//------------------------------------------------------------------------------

} // end namespace MemUtils

} // end namespace PRDF
