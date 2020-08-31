/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemUtils.C $            */
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

/** @file  prdfMemUtils.C
 *  @brief Utility functions related to memory
 */

#include <prdfMemUtils.H>

// Framework includes
#include <iipServiceDataCollector.h>
#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal_common.H>
#include <UtilHash.H>

// Platform includes
#include <prdfCenMbaDataBundle.H>
#include <prdfOcmbDataBundle.H>
#include <prdfCenMembufDataBundle.H>
#include <prdfCenMembufExtraSig.H>
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

static const char *ocmbCeStatReg[CE_REGS_PER_PORT] =
                       {
                           "OCMB_MBSSYMEC0", "OCMB_MBSSYMEC1", "OCMB_MBSSYMEC2",
                           "OCMB_MBSSYMEC3", "OCMB_MBSSYMEC4", "OCMB_MBSSYMEC5",
                           "OCMB_MBSSYMEC6", "OCMB_MBSSYMEC7", "OCMB_MBSSYMEC8"
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
int32_t collectCeStats<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                        const MemRank & i_rank,
                                        MaintSymbols & o_maintStats,
                                        MemSymbol & o_chipMark, uint8_t i_thr )
{
    #define PRDF_FUNC "[MemUtils::collectCeStats<TYPE_OCMB_CHIP>] "

    int32_t o_rc = SUCCESS;
    o_chipMark = MemSymbol(); // Initially invalid.

    do
    {
        PRDF_ASSERT( 0 != i_thr );

        TargetHandle_t ocmbTrgt = i_chip->getTrgt();

        // TODO RTC 210072 - support for multiple ports
        TargetHandle_t memPortTrgt = getConnectedChild( ocmbTrgt,
                                                        TYPE_MEM_PORT, 0 );
        TargetHandle_t dimm = getConnectedDimm( memPortTrgt, i_rank );
        const bool isX4 = isDramWidthX4( dimm );

        // Use this map to keep track of the total counts per DRAM.
        DramCountMap dramCounts;

        const char * reg_str = NULL;
        SCAN_COMM_REGISTER_CLASS * reg = NULL;

        for ( uint8_t regIdx = 0; regIdx < CE_REGS_PER_PORT; regIdx++ )
        {
            reg_str = ocmbCeStatReg[regIdx];
            reg     = i_chip->getRegister( reg_str );

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

                uint8_t dram = isX4 ? symbol2Nibble<TYPE_OCMB_CHIP>( sym )
                                    : symbol2Byte  <TYPE_OCMB_CHIP>( sym );

                // Keep track of the total DRAM counts.
                dramCounts[dram].totalCount += count;

                // Add any symbols that have exceeded threshold to the list.
                if ( i_thr <= count )
                {
                    // Keep track of the total number of symbols per DRAM that
                    // have exceeded threshold.
                    dramCounts[dram].symbolCount++;

                    SymbolData symData;
                    symData.symbol = MemSymbol::fromSymbol( ocmbTrgt, i_rank,
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
            uint8_t sym = isX4 ? nibble2Symbol<TYPE_OCMB_CHIP>( highestDram )
                               : byte2Symbol  <TYPE_OCMB_CHIP>( highestDram );
            PRDF_ASSERT( sym < SYMBOLS_PER_RANK );

            o_chipMark  = MemSymbol::fromSymbol( ocmbTrgt, i_rank, sym );
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
uint8_t getDramSize<TYPE_MCA>( TargetHandle_t i_trgt, uint8_t i_dimmSlct )
{
    #define PRDF_FUNC "[MemUtils::getDramSize] "

    PRDF_ASSERT( TYPE_MCA == getTargetType(i_trgt) );
    PRDF_ASSERT( i_dimmSlct < DIMM_SLCT_PER_PORT );

    TargetHandle_t mcsTrgt = getConnectedParent( i_trgt, TYPE_MCS );

    PRDF_ASSERT( nullptr != mcsTrgt );

    uint8_t mcaRelPos = getTargetPosition(i_trgt) % MAX_MCA_PER_MCS;

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
uint8_t getDramSize<TYPE_MBA>( TargetHandle_t i_trgt, uint8_t i_dimmSlct )
{
    #define PRDF_FUNC "[MemUtils::getDramSize] "

    PRDF_ASSERT( TYPE_MBA == getTargetType(i_trgt) );

    uint8_t o_size = 0;

    do
    {
        TargetHandle_t membuf = getConnectedParent(i_trgt, TYPE_MEMBUF);
        ExtensibleChip * membufChip =
            (ExtensibleChip*)systemPtr->GetChip(membuf);
        PRDF_ASSERT( nullptr != membufChip );

        uint32_t pos = getTargetPosition(i_trgt);
        const char * reg_str = (0 == pos) ? "MBA0_MBAXCR" : "MBA1_MBAXCR";

        SCAN_COMM_REGISTER_CLASS * reg = membufChip->getRegister( reg_str );
        uint32_t rc = reg->Read();
        if ( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s. Target=0x%08x",
                      reg_str, getHuid(i_trgt) );
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

template<>
uint8_t getDramSize<TYPE_MEM_PORT>( TargetHandle_t i_trgt, uint8_t i_dimmSlct )
{
    #define PRDF_FUNC "[MemUtils::getDramSize] "

    PRDF_ASSERT( TYPE_MEM_PORT == getTargetType(i_trgt) );
    PRDF_ASSERT( i_dimmSlct < DIMM_SLCT_PER_PORT );

    uint8_t tmp[DIMM_SLCT_PER_PORT];

    if ( !i_trgt->tryGetAttr<TARGETING::ATTR_MEM_EFF_DRAM_DENSITY>(tmp) )
    {
        PRDF_ERR( PRDF_FUNC "Failed to get ATTR_MEM_EFF_DRAM_DENSITY" );
        PRDF_ASSERT( false );
    }

    return tmp[i_dimmSlct];

    #undef PRDF_FUNC
}

template<>
uint8_t getDramSize<TYPE_OCMB_CHIP>( TargetHandle_t i_trgt, uint8_t i_dimmSlct )
{
    #define PRDF_FUNC "[MemUtils::getDramSize] "

    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_trgt) );
    PRDF_ASSERT( i_dimmSlct < DIMM_SLCT_PER_PORT );

    // TODO RTC 210072 - Explorer only has one port, however, multiple ports
    // will be supported in the future. Updates will need to be made here so we
    // can get the relevant port.

    TargetHandle_t memPort = getConnectedChild( i_trgt, TYPE_MEM_PORT, 0 );

    return getDramSize<TYPE_MEM_PORT>( memPort, i_dimmSlct );

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

template<>
void cleanupChnlAttns<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                       STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemUtils::cleanupChnlAttns] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    // No cleanup if this is a checkstop attention.
    if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() ) return;

    #ifdef __HOSTBOOT_MODULE // only do cleanup in Hostboot, no-op in FSP

    // Get the subchannel pos (0:1)
    TargetHandle_t ocmb = i_chip->getTrgt();
    TargetHandle_t omi = getConnectedParent( ocmb, TYPE_OMI );
    uint8_t chnlPos = getTargetPosition(omi) % MAX_OMI_PER_MCC;

    // Clear the associated FIR bits for all attention types. DSTLFIR[0:3]
    // for subchannel 0 or DSTLFIR[4:7] for subchannel 1
    ExtensibleChip * mcc = getConnectedParent( i_chip, TYPE_MCC );

    SCAN_COMM_REGISTER_CLASS * dstlfir_and = mcc->getRegister( "DSTLFIR_AND" );

    dstlfir_and->setAllBits();
    dstlfir_and->SetBitFieldJustified( chnlPos*4, 4, 0 );
    dstlfir_and->Write();

    // After clearing the DSTLFIR, we now need to query the chiplet level FIRs
    // of the OCMB and re-set the appropriate bits in the DSTLFIR for any
    // attentions that are still active.
    struct firInfo
    {
        const char * firAddr; // FIR name
        const char * firMask; // FIR mask name
        uint8_t bitPos;       // Relevant bit pos in the DSTLFIR to set
    };
    static const std::vector<firInfo> firList
    {
        { "OCMB_CHIPLET_CS_FIR",  "OCMB_CHIPLET_FIR_MASK",     0 },
        { "OCMB_CHIPLET_RE_FIR",  "OCMB_CHIPLET_FIR_MASK",     1 },
        { "OCMB_CHIPLET_SPA_FIR", "OCMB_CHIPLET_SPA_FIR_MASK", 2 },
    };

    for ( const auto & fir : firList )
    {
        SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( fir.firAddr );
        SCAN_COMM_REGISTER_CLASS * msk = i_chip->getRegister( fir.firMask );

        // The attention on the OCMB had been cleared by the rule code. We must
        // do force reads to update the values stored in the register cache.
        if ( SUCCESS == ( reg->ForceRead() | msk->ForceRead() ) )
        {
            uint64_t regData = reg->GetBitFieldJustified(0,64);
            uint64_t mskData = msk->GetBitFieldJustified(0,64);

            if ( 1 == fir.bitPos )
            {
                // Shift recoverable FIR bits
                regData = regData >> 2;
            }
            if ( 0 != (regData & ~mskData) )
            {
                PRDF_TRAC( PRDF_FUNC "Re-setting DSTLFIR, attn found: %s "
                           "regData=0x%016llx, mskData=0x%016llx", fir.firAddr,
                           regData, mskData );
                // Attention on, set bits in DSTLFIR
                SCAN_COMM_REGISTER_CLASS * dstlfir_or =
                    mcc->getRegister( "DSTLFIR_OR" );
                dstlfir_or->SetBit( fir.bitPos + (4*chnlPos) );
                if ( SUCCESS != dstlfir_or->Write() )
                {
                    PRDF_ERR( PRDF_FUNC "Write() failed on DSTLFIR_OR" );
                    continue;
                }
            }
        }
    }

    #endif // Hostboot only

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __fwAssistChnlFailWorkaround( ExtensibleChip * i_chip );

template<>
uint32_t __fwAssistChnlFailWorkaround<TYPE_DMI>( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[MemUtils::__fwAssistChnlFailWorkaround] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_DMI == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE

    // On the Cumulus chip, channel failure attentions from the IOMCFIR are
    // forwarded down to CHIFIR[4] for each of the channels. Unfortunately,
    // there is a mapping bug in the hardware where the channel failures are
    // forwarded to the wrong CHIFIR, which causes the wrong channel to fail.

    // We considered making all of the channel fail attentions in the IOMCFIR
    // recoverable, but the "too many bus errors" attentions are a DI risk. We
    // also considered setting them to checkstop, but customers with mirroring
    // would be really mad at us, because mirroring should have protected their
    // system. So the compromise is to have firmware force the channel failure.

    // The goal here is to make the workaround behave like the hardware as much
    // as possible. CHIFIR[4] is no longer configured to trigger a channel
    // failure because of the bug. So what we will do is query if this channel
    // should have failed via the IOMCFIR. If so, configure CHIFIR[4] to trigger
    // a channel failure and set CHIFIR[4]. This will not actually trigger the
    // channel failure, but is necessary for the analysis to work. To actually
    // trigger the channel failure, we must set MCICFG0[25].

    // It is likely that the channel failure could cause a system checkstop or
    // PHYP/Hostboot TI. Especially, if it occurred in memory that is not
    // mirrored. This will end up killing the host and this analysis code, which
    // is ok. We would experience the same behavior if the hardware actually
    // worked the way it should. The analysis code on the FSP will pick up where
    // we left off and callout/gard the bad channel.

    SCAN_COMM_REGISTER_CLASS * chifir    = i_chip->getRegister( "CHIFIR" );
    SCAN_COMM_REGISTER_CLASS * chifir_or = i_chip->getRegister( "CHIFIR_OR" );
    SCAN_COMM_REGISTER_CLASS * mcicfg0   = i_chip->getRegister( "MCICFG0" );
    SCAN_COMM_REGISTER_CLASS * mcicfg1   = i_chip->getRegister( "MCICFG1" );

    ExtensibleChip * mcChip = getConnectedParent( i_chip, TYPE_MC );
    uint32_t dmiPos = i_chip->getPos() % MAX_DMI_PER_MC;
    uint32_t bitPos = 8 + dmiPos * 8;

    SCAN_COMM_REGISTER_CLASS * iomcfir  = mcChip->getRegister( "IOMCFIR" );
    SCAN_COMM_REGISTER_CLASS * iomc_cfg = mcChip->getRegister( "SCOM_MODE_PB" );

    do
    {
        // First, check if there are any bits for this channel that are set in
        // the IOMCFIR and configured to channel fail.
        o_rc = iomcfir->Read() | iomc_cfg->Read();
        if ( SUCCESS != o_rc ) break;

        // For reference, SCOM_MODE_PB[15:22]: 0=enabled, 1=disabled.
        if ( 0 == (  iomcfir->GetBitFieldJustified( bitPos,8) &
                    ~iomc_cfg->GetBitFieldJustified(15,    8) ) )
        {
            break; // nothing more to do.
        }

        // The channel should fail.
        o_rc = chifir->Read() | mcicfg0->Read() | mcicfg1->Read();
        if ( SUCCESS != o_rc ) break;

        // Configure CHIFIR[4] to channel fail via MCICFG1[47].
        if ( mcicfg1->IsBitSet(47) ) // 0=enabled, 1=disabled
        {
            mcicfg1->ClearBit(47);
            o_rc = mcicfg1->Write();
            if ( SUCCESS != o_rc ) break;
        }

        // Set CHIFIR[4].
        if ( !chifir->IsBitSet(4) )
        {
            chifir_or->SetBit(4);
            o_rc = chifir_or->Write();
            if ( SUCCESS != o_rc ) break;
        }

        // Force the channel failure via MCICFG0[25].
        if ( !mcicfg0->IsBitSet(25) )
        {
            mcicfg0->SetBit(25);
            o_rc = mcicfg0->Write();
            if ( SUCCESS != o_rc ) break;
        }

    } while (0);

    #endif // __HOSTBOOT_MODULE

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
bool __queryUcsCentaur( ExtensibleChip * i_chip );

template<>
bool __queryUcsCentaur<TYPE_MEMBUF>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEMBUF == i_chip->getType() );

    uint32_t o_activeAttn = false;

    // We can't use the GLOBAL_CS_FIR. It will not clear automatically when a
    // channel has failed because the hardware clocks have stopped. Also, since
    // it is a virtual register there really is no way to clear it. Fortunately
    // we have the INTER_STATUS_REG that will tell us if there is an active
    // attention. Note that we clear this register as part of the channel
    // failure cleanup. So we can rely on this register to determine if there is
    // a new channel failure.

    SCAN_COMM_REGISTER_CLASS * fir = i_chip->getRegister("INTER_STATUS_REG");

    if ( SUCCESS == fir->Read() )
    {
        o_activeAttn = fir->IsBitSet(2); // Centaur checkstop bit.
    }

    return o_activeAttn;
}

//------------------------------------------------------------------------------

// This excludes CHIFIR[16,19:21] to avoid a loop in isolation. Also excludes
// CHIFIR[61] due to a hardware workaround, see __queryUcsChifir_61().
template<TARGETING::TYPE T>
bool __queryUcsChifir( ExtensibleChip * i_chip );

template<>
bool __queryUcsChifir<TYPE_DMI>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_DMI == i_chip->getType() );

    uint32_t o_activeAttn = false;

    SCAN_COMM_REGISTER_CLASS * fir  = i_chip->getRegister( "CHIFIR"      );
    SCAN_COMM_REGISTER_CLASS * mask = i_chip->getRegister( "CHIFIR_MASK" );
    SCAN_COMM_REGISTER_CLASS * act0 = i_chip->getRegister( "CHIFIR_ACT0" );
    SCAN_COMM_REGISTER_CLASS * act1 = i_chip->getRegister( "CHIFIR_ACT1" );

    if ( SUCCESS == (fir->Read() | mask->Read() | act0->Read() | act1->Read()) )
    {
        // Make sure to ignore CHIFIR[16,19:21], which simply say there is an
        // attention on the Centaur. Otherwise, we will get stuck in a loop.
        // CHIFIR[61] is also ignored as it needs to be looked for later
        // for a special MBS timeout case.
        if ( 0 != (  fir->GetBitFieldJustified( 0,64) &
                    ~mask->GetBitFieldJustified(0,64) &
                     act0->GetBitFieldJustified(0,64) &
                     act1->GetBitFieldJustified(0,64) &
                     0xffff63fffffffffbull ) )
        {
            o_activeAttn = true;
        }
    }

    return o_activeAttn;
}

//------------------------------------------------------------------------------

// WORKAROUND:
// This function only queries for CHIFIR[61]. There is a hardware workaround
// that changes some behavior. CHIFIR[16] will no longer report channel failure
// attentions from the Centaur. Also, any time there is a channel failure
// attention from the Centaur, CHIFIR[61] will get set. In addition, CHIFIR[61]
// can report an attention on its own, no need for Centaur attention. Therefore,
// we must workaround the workaround and isolate to CHIFIR[61] only after
// analyzing the Centaur.
template<TARGETING::TYPE T>
bool __queryUcsChifir_61( ExtensibleChip * i_chip );

template<>
bool __queryUcsChifir_61<TYPE_DMI>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_DMI == i_chip->getType() );

    uint32_t o_activeAttn= false;

    // Check if there is an active UCS attention on CHIFIR[61]
    SCAN_COMM_REGISTER_CLASS * fir  = i_chip->getRegister( "CHIFIR"      );
    SCAN_COMM_REGISTER_CLASS * mask = i_chip->getRegister( "CHIFIR_MASK" );
    SCAN_COMM_REGISTER_CLASS * act0 = i_chip->getRegister( "CHIFIR_ACT0" );
    SCAN_COMM_REGISTER_CLASS * act1 = i_chip->getRegister( "CHIFIR_ACT1" );

    if ( SUCCESS == (fir->Read() | mask->Read() | act0->Read() | act1->Read()) )
    {
        if ( fir->IsBitSet(61) & !mask->IsBitSet(61) & act0->IsBitSet(61) &
             act1->IsBitSet(61) )
        {
            o_activeAttn = true;
        }
    }


    return o_activeAttn;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
bool __queryUcsIomcfir( ExtensibleChip * i_chip );

template<>
bool __queryUcsIomcfir<TYPE_DMI>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_DMI == i_chip->getType() );

    uint32_t o_activeAttn = false;

    ExtensibleChip * mcChip = getConnectedParent( i_chip, TYPE_MC );

    SCAN_COMM_REGISTER_CLASS * fir  = mcChip->getRegister( "IOMCFIR"      );
    SCAN_COMM_REGISTER_CLASS * mask = mcChip->getRegister( "IOMCFIR_MASK" );
    SCAN_COMM_REGISTER_CLASS * act0 = mcChip->getRegister( "IOMCFIR_ACT0" );
    SCAN_COMM_REGISTER_CLASS * act1 = mcChip->getRegister( "IOMCFIR_ACT1" );

    if ( SUCCESS == (fir->Read() | mask->Read() | act0->Read() | act1->Read()) )
    {
        uint32_t dmiPos = i_chip->getPos() % MAX_DMI_PER_MC;
        uint32_t bitPos = 8 + dmiPos * 8;

        if ( 0 != (  fir->GetBitFieldJustified( bitPos,8) &
                    ~mask->GetBitFieldJustified(bitPos,8) &
                     act0->GetBitFieldJustified(bitPos,8) &
                     act1->GetBitFieldJustified(bitPos,8) ) )
        {
            o_activeAttn = true;
        }
    }

    return o_activeAttn;
}

//------------------------------------------------------------------------------

// Ideally it would be nice to look at only the target reporting attentions for
// a channel fail. Unfortunately, RCD parity errors can trigger a channel fail
// anywhere on the bus. Therefore, we have to query the entire bus for at least
// one active attention returning a channel failure.

template<TARGETING::TYPE T1, TARGETING::TYPE T2>
bool __queryChnlFail( ExtensibleChip * i_chip1, ExtensibleChip * i_chip2,
                      STEP_CODE_DATA_STRUCT & io_sc );

template<>
bool __queryChnlFail<TYPE_DMI,TYPE_MEMBUF>( ExtensibleChip * i_dmiChip,
                                            ExtensibleChip * i_membChip,
                                            STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemUtils::__queryChnlFail] "

    PRDF_ASSERT( nullptr != i_dmiChip );
    PRDF_ASSERT( TYPE_DMI == i_dmiChip->getType() );

    PRDF_ASSERT( nullptr != i_membChip );
    PRDF_ASSERT( TYPE_MEMBUF == i_membChip->getType() );

    bool o_chnlFail = false;

    do
    {
        // Skip if currently analyzing a host attention. This is a required for
        // a rare scenario when a channel failure occurs after PRD is called to
        // handle the host attention.
        if ( HOST_ATTN == io_sc.service_data->getPrimaryAttnType() ) break;

        // There is a hardware bug where channel failures from the IOMCFIRs
        // don't report correctly. This workaround fixes the reporting and
        // forces a channel failure if needed. It must be called before calling
        // the query HWP in order for the hardware to be in the correct state.
        if ( SUCCESS != __fwAssistChnlFailWorkaround<TYPE_DMI>(i_dmiChip) )
        {
            PRDF_ERR( PRDF_FUNC "__fwAssistChnlFailWorkaround(0x%08x) failed",
                      i_dmiChip->getHuid() );
            // Continue on just in case there is a channel failure attention
            // somewhere else.
        }

        // Check for an active attention on the Centaur (simplest query).
        if ( __queryUcsCentaur<TYPE_MEMBUF>(i_membChip) )
        {
            o_chnlFail = true;
            break; // nothing more to do.
        }

        // There is a HWP on the processor side that will query if this channel
        // has failed. Unfortunately, it does not check for an active channel
        // fail attention (i.e. not masked). That will need to be done
        // afterwards.
        bool tmpChnlFail = false;
        if ( SUCCESS != PlatServices::queryChnlFail<TYPE_DMI>(i_dmiChip,
                                                              tmpChnlFail) )
        {
            PRDF_ERR( PRDF_FUNC "PlatServices::queryChnlFail(0x%08x) failed",
                      i_dmiChip->getHuid() );
            break;
        }
        if ( !tmpChnlFail ) break; // nothing more to do.

        // Check for an active attention on the CHIFIR or IOMCFIR.
        if ( __queryUcsChifir   <TYPE_DMI>(i_dmiChip) ||
             __queryUcsChifir_61<TYPE_DMI>(i_dmiChip) ||
             __queryUcsIomcfir  <TYPE_DMI>(i_dmiChip) )
        {
            o_chnlFail = true;
            break; // nothing more to do.
        }

        // This is possible if we are looking at a channel that has already
        // failed and had been analyzed. Will likely happen when iterating DMIs
        // in the MC analyze function.
        PRDF_INF( PRDF_FUNC "Failed channel detected on 0x%08x, but no active "
                  "attentions found", i_dmiChip->getHuid() );

    } while (0);

    if ( o_chnlFail )
    {
        // Note that we are not setting the secondary attention type at this
        // time because the channel failure could have been triggered by an RCD
        // parity error, which is a recoverable attention.

        // Set the MEM_CHNL_FAIL flag in the SDC to indicate a channel failure
        // has been detected and there is no need to check again.
        io_sc.service_data->setMemChnlFail();

        // Make the error log predictive and set threshold.
        io_sc.service_data->setFlag( ServiceDataCollector::SERVICE_CALL );
        io_sc.service_data->setFlag( ServiceDataCollector::AT_THRESHOLD );

        // Channel failures will always send SUEs.
        io_sc.service_data->setFlag( ServiceDataCollector::UERE );

        // Indicate cleanup is required on this channel.
        getMembufDataBundle(i_membChip)->iv_doChnlFailCleanup = true;
    }

    return o_chnlFail;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Channel failure analysis is designed to only look for UNIT_CS attentions and
// not associate any recoverables as the root cause. Of course, now we have a
// special case. RCD parity errors are recoverable attentions that could cause
// unit CS attentions as a side effect. Therefore, we must analyze them first
// before looking for any UNIT_CS attentions.

template<TARGETING::TYPE T>
bool __analyzeRcdParityError( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & io_sc );

template<>
bool __analyzeRcdParityError<TYPE_MEMBUF>( ExtensibleChip * i_chip,
                                           STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemUtils::__analyzeRcdParityError] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEMBUF == i_chip->getType() );

    uint32_t o_analyzed = false;

    SCAN_COMM_REGISTER_CLASS * fir  = nullptr;
    SCAN_COMM_REGISTER_CLASS * mask = nullptr;
    SCAN_COMM_REGISTER_CLASS * act0 = nullptr;
    SCAN_COMM_REGISTER_CLASS * act1 = nullptr;

    for ( auto & mbaChip : getConnected(i_chip, TYPE_MBA) )
    {
        fir  = mbaChip->getRegister( "MBACALFIR"      );
        mask = mbaChip->getRegister( "MBACALFIR_MASK" );
        act0 = mbaChip->getRegister( "MBACALFIR_ACT0" );
        act1 = mbaChip->getRegister( "MBACALFIR_ACT1" );

        if ( SUCCESS != (fir->Read()  | mask->Read() |
                         act0->Read() | act1->Read()) )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read MBACALFIRs on 0x%08x",
                      mbaChip->getHuid() );
            continue; // try the other MBA
        }

        uint32_t bits[] = { 4, 7 }; // bit 4: port 0, bit 7: port 1
        for ( auto & b : bits )
        {
            if ( !fir->IsBitSet(b) || mask->IsBitSet(b) ) continue;

            PRDF_INF( PRDF_FUNC "RCD parity error found on 0x%08x",
                      mbaChip->getHuid() );

            // Check the action registers just in case someone decides to change
            // the attention type to unit checkstop.
            ATTENTION_TYPE secAttnType = RECOVERABLE;
            if ( !act0->IsBitSet(b) && !act1->IsBitSet(b) )
                secAttnType = UNIT_CS;

            // Analyze this MBA. Note that the rule code is set up on the MBA
            // such that the RCD parity errors will always be the first
            // attentions handled.
            if ( SUCCESS == mbaChip->Analyze(io_sc, secAttnType) )
            {
                o_analyzed = true; break; // analysis complete
            }
        }
        if ( o_analyzed ) break; // nothing more to do
    }

    return o_analyzed;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Channel failure analysis is designed to only look for UNIT_CS attentions and
// not associate any recoverables as the root cause. Of course, now we have yet
// another special case. An internal timeout is a recoverable attention that
// could cause unit CS attentions as a side effect. Therefore, we must analyze
// it first before looking for any UNIT_CS attentions.

template<TARGETING::TYPE T>
bool __analyzeInternalTimeout( ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & io_sc );

template<>
bool __analyzeInternalTimeout<TYPE_MEMBUF>( ExtensibleChip * i_chip,
                                            STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemUtils::__analyzeInternalTimeout] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEMBUF == i_chip->getType() );

    uint32_t o_analyzed = false;

    SCAN_COMM_REGISTER_CLASS * fir  = i_chip->getRegister( "MBSFIR"      );
    SCAN_COMM_REGISTER_CLASS * mask = i_chip->getRegister( "MBSFIR_MASK" );

    do
    {
        if ( SUCCESS != (fir->Read() | mask->Read()) )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read MBSFIRs on 0x%08x",
                      i_chip->getHuid() );
            break;
        }

        // If there is an internal timeout that is not masked and there is not
        // an external timeout (note external timeout is always masked), then
        // there is a legit internal timeout attention.
        if ( fir->IsBitSet(4) && !mask->IsBitSet(4) && !fir->IsBitSet(3) )
        {
            // We are not going to analyze the MEMBUF chip like we do with some
            // of the other helper functions in this file because the rule code
            // priority will put the MBSFIR after the MBIFIR and DMIFIR.
            // Therefore, there is no way to guarantee this attention will be
            // analyzed. Since we do know there is a channel failure we can
            // simply make a predictive callout because the channel failure code
            // will eventually mask the entire Centaur.

            io_sc.service_data->SetCallout( i_chip->getTrgt() );

            io_sc.service_data->setSignature( i_chip->getHuid(),
                                              PRDFSIG_InternalTimeout );

            o_analyzed = true; break; // analysis complete
        }

    } while (0);

    return o_analyzed;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Handling channel failures from more than one channel at a time:
// Say we were called to handle a recoverable attention on a Centaur, but the
// channel containing that Centaur has a unit checkstop attention in the
// IOMCFIR. There is nothing in the PRD plugin code that will allow us to
// analyze the IOMCFIR directly. So the best we have is to analyze the MC target
// containing the IOMCFIR. Now, say we have a second channel reporting a unit
// checkstop from its CHIFIR (two channel failures at the same time). In order
// to ensure that we can take care of the first channel failure, we must
// prioritize the IOMCFIR over all of the CHIFIRs in the MC_CHIPLET_UCS_FIR.
//
// To complicate things further, we don't have any mechanism to target a
// specific bus in the IOMCFIR. So we have to analyze the buses in order (0-3).
// Therefore, it is still possible that the first bus we find with a unit
// checkstop attention in the IOMCFIR is not the bus we originally started to
// analyze. There isn't much we can do about this. We will have to start over
// and switch analysis to the second channel. After completing analysis and
// masking the second bus, we will then retry analysis on the first bus.
//
// So basically any time we need to look for a channel failure, we must iterate
// all four channels in the order they exist in the IOMCFIR.

template<TARGETING::TYPE T>
bool __analyzeChnlFail( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc );

template<>
bool __analyzeChnlFail<TYPE_MC>( ExtensibleChip * i_chip,
                                 STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MC == i_chip->getType() );

    uint32_t o_analyzed = false;

    // getConnected() will return the chips sorted by the unit position. This
    // will be the same order as the buses in the IOMCFIR.
    for ( auto & dmiChip : getConnected(i_chip, TYPE_DMI) )
    {
        ExtensibleChip * membChip = getConnectedChild(dmiChip, TYPE_MEMBUF, 0);
        PRDF_ASSERT( nullptr != membChip ); // shouldn't be possible

        // Check for active channel failure attention.
        if ( !__queryChnlFail<TYPE_DMI,TYPE_MEMBUF>(dmiChip, membChip, io_sc) )
        {
            continue; // nothing more to do for this channel
        }

        // First, check for RCD parity errors. They are recoverable attentions
        // that could have a channel failure attention as a side effect.
        if ( __analyzeRcdParityError<TYPE_MEMBUF>(membChip, io_sc) )
        {
            o_analyzed = true; break; // analysis complete
        }

        // Now, check for an internal timeout error. This is a recoverable
        // attention that could have a channel failure attention as a side
        // effect.
        if ( __analyzeInternalTimeout<TYPE_MEMBUF>(membChip, io_sc) )
        {
            o_analyzed = true; break; // analysis complete
        }

        // Now, look for unit checkstops in the CHIFIR, excluding
        // CHIFIR[16,19:21,61].
        if ( __queryUcsChifir<TYPE_DMI>(dmiChip) )
        {
            // Analyze UNIT_CS on the DMI chip.
            if ( SUCCESS == dmiChip->Analyze(io_sc, UNIT_CS) )
            {
                o_analyzed = true; break; // analysis complete
            }
        }

        // Now, look for unit checkstops on the Centaur.
        if ( __queryUcsCentaur<TYPE_MEMBUF>(membChip) )
        {
            // Analyze UNIT_CS on the MEMBUF chip.
            if ( SUCCESS == membChip->Analyze(io_sc, UNIT_CS) )
            {
                o_analyzed = true; break; // analysis complete
            }
        }

        // Now, look for unit checkstop from CHIFIR[61].
        if ( __queryUcsChifir_61<TYPE_DMI>(dmiChip) )
        {
            // Analyze UNIT_CS on the DMI chip.
            if ( SUCCESS == dmiChip->Analyze(io_sc, UNIT_CS) )
            {
                o_analyzed = true; break; // analysis complete
            }
        }

        // Now, look for unit checkstops in the IOMCFIR.
        if ( __queryUcsIomcfir<TYPE_DMI>(dmiChip) )
        {
            // Analyze UNIT_CS on the MC chip.
            if ( SUCCESS == i_chip->Analyze(io_sc, UNIT_CS) )
            {
                o_analyzed = true; break; // analysis complete
            }
        }
    }

    return o_analyzed;
}

//------------------------------------------------------------------------------

template<>
bool analyzeChnlFail<TYPE_MEMBUF>( ExtensibleChip * i_chip,
                                   STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEMBUF == i_chip->getType() );

    uint32_t o_analyzed = false;

    if ( !io_sc.service_data->isMemChnlFail() )
    {
        ExtensibleChip * dmiChip = getConnectedParent( i_chip,  TYPE_DMI );
        ExtensibleChip * mcChip  = getConnectedParent( dmiChip, TYPE_MC  );
        o_analyzed = __analyzeChnlFail<TYPE_MC>( mcChip, io_sc );
    }

    return o_analyzed;
}

//------------------------------------------------------------------------------

template<>
bool analyzeChnlFail<TYPE_MC>( ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MC == i_chip->getType() );

    uint32_t o_analyzed = false;

    if ( !io_sc.service_data->isMemChnlFail() )
    {
        o_analyzed = __analyzeChnlFail<TYPE_MC>( i_chip, io_sc );
    }

    return o_analyzed;
}

//------------------------------------------------------------------------------

bool __queryUcsOmic( ExtensibleChip * i_omic, ExtensibleChip * i_mcc,
                     TargetHandle_t i_omi )
{
    PRDF_ASSERT( nullptr != i_omic );
    PRDF_ASSERT( nullptr != i_mcc );
    PRDF_ASSERT( nullptr != i_omi );
    PRDF_ASSERT( TYPE_OMIC == i_omic->getType() );
    PRDF_ASSERT( TYPE_MCC  == i_mcc->getType() );
    PRDF_ASSERT( TYPE_OMI  == getTargetType(i_omi) );

    bool o_activeAttn = false;

    do
    {
        // Get the DSTLCFG2 register to check whether channel fail is enabled
        // NOTE: DSTLCFG2[22] = 0b0 to enable chnl fail for subchannel A
        // NOTE: DSTLCFG2[23] = 0b0 to enable chnl fail for subchannel B
        SCAN_COMM_REGISTER_CLASS * cnfg = i_mcc->getRegister( "DSTLCFG2" );

        // Get the position of the inputted OMI relative to the parent MCC (0-1)
        // to determine which channel we need to check.
        uint8_t omiPosRelMcc = getTargetPosition(i_omi) % MAX_OMI_PER_MCC;

        // If channel fail isn't configured, no need to continue.
        if ( cnfg->IsBitSet(22 + omiPosRelMcc) ) break;

        // Check the OMIDLFIR for UCS (relevant bits: 0,20,40)
        SCAN_COMM_REGISTER_CLASS * fir  = i_omic->getRegister("OMIDLFIR");
        SCAN_COMM_REGISTER_CLASS * mask = i_omic->getRegister("OMIDLFIR_MASK");
        SCAN_COMM_REGISTER_CLASS * act0 = i_omic->getRegister("OMIDLFIR_ACT0");
        SCAN_COMM_REGISTER_CLASS * act1 = i_omic->getRegister("OMIDLFIR_ACT1");

        if ( SUCCESS == ( fir->Read() | mask->Read() |
                         act0->Read() | act1->Read() ) )
        {
            // Get the position of the inputted OMI relative to the parent
            // OMIC (0-2). We'll need to use ATTR_OMI_DL_GROUP_POS for this.
            uint8_t omiPosRelOmic = i_omi->getAttr<ATTR_OMI_DL_GROUP_POS>();

            // Get the bit offset for the bit relevant to the inputted OMI.
            // 0 : OMI-DL 0
            // 20: OMI-DL 1
            // 40: OMI-DL 2
            uint8_t bitOff = omiPosRelOmic * 20;

            // Check if there is a UNIT_CS for the relevant bits in the OMIDLFIR
            // Note: The OMIDLFIR can't actually be set up to report UNIT_CS
            // attentions, instead, as a workaround, the relevant channel fail
            // bits will be set as recoverable bits and we will manually set
            // the attention types to UNIT_CS in our handling of those errors.
            if ( fir->IsBitSet(bitOff)  && !mask->IsBitSet(bitOff) &&
                 !act0->IsBitSet(bitOff) &&  act1->IsBitSet(bitOff) )
            {
                o_activeAttn = true;
            }
        }
    }while(0);

    return o_activeAttn;
}

bool __queryUcsMcc( ExtensibleChip * i_mcc, TargetHandle_t i_omi )
{
    PRDF_ASSERT( nullptr != i_mcc );
    PRDF_ASSERT( nullptr != i_omi );
    PRDF_ASSERT( TYPE_MCC == i_mcc->getType() );
    PRDF_ASSERT( TYPE_OMI == getTargetType(i_omi) );

    bool o_activeAttn = false;

    // Get the position of the inputted OMI relative to the parent MCC (0-1)
    // to determine which channel we need to check.
    uint8_t omiPos = getTargetPosition(i_omi) % MAX_OMI_PER_MCC;

    // Maps of the DSTLFIR UCS bits to their relevant channel fail
    // configuration bit in DSTLCFG2. Ex: {12,28} = DSTLFIR[12], DSTLCFG2[28]
    // NOTE: there is a separate map for each subchannel.
    const std::map<uint8_t,uint8_t> dstlfirMapChanA =
        { {12,28}, {16,30}, {22,24} };

    const std::map<uint8_t,uint8_t> dstlfirMapChanB =
        { {13,29}, {17,31}, {23,25} };

    // Check the DSTLFIR for UCS
    SCAN_COMM_REGISTER_CLASS * fir  = i_mcc->getRegister( "DSTLFIR" );
    SCAN_COMM_REGISTER_CLASS * mask = i_mcc->getRegister( "DSTLFIR_MASK" );
    SCAN_COMM_REGISTER_CLASS * act0 = i_mcc->getRegister( "DSTLFIR_ACT0" );
    SCAN_COMM_REGISTER_CLASS * act1 = i_mcc->getRegister( "DSTLFIR_ACT1" );
    SCAN_COMM_REGISTER_CLASS * cnfg = i_mcc->getRegister( "DSTLCFG2" );

    if ( SUCCESS == (fir->Read() | mask->Read() | act0->Read() | act1->Read() |
                     cnfg->Read()) )
    {
        // Get which relevant channel we need to check.
        std::map<uint8_t,uint8_t> dstlfirMap;
        dstlfirMap = (0 == omiPos) ? dstlfirMapChanA : dstlfirMapChanB;

        for ( auto const & bits : dstlfirMap )
        {
            uint8_t firBit  = bits.first;
            uint8_t cnfgBit = bits.second;

            // NOTE: Channel fail is enabled if the config bit is set to 0b0
            if ( !cnfg->IsBitSet(cnfgBit) &&  fir->IsBitSet(firBit) &&
                 !mask->IsBitSet(firBit)  && act0->IsBitSet(firBit) &&
                  act1->IsBitSet(firBit) )
            {
                o_activeAttn = true;
            }
        }
    }

    // Maps of the USTLFIR UCS bits to their relevant channel fail
    // config bit in USTLFAILMASK. Ex: {0,54} = USTLFIR[0], USTLFAILMASK[54]
    // NOTE: there is a separate map for each subchannel.
    const std::map<uint8_t,uint8_t> ustlfirMapChanA =
    { { 0,54}, { 2,48}, {27,56}, {35,49}, {37,50}, {39,51}, {41,52}, {43,53},
      {49,55}, {51,50}, {53,50}, {55,48}, {59,56} };
    const std::map<uint8_t,uint8_t> ustlfirMapChanB =
    { { 1,54}, { 3,48}, {28,56}, {36,49}, {38,50}, {40,51}, {42,52}, {44,53},
      {50,55}, {52,50}, {54,50}, {56,48}, {60,56} };

    // Check the USTLFIR for UCS
    fir  = i_mcc->getRegister( "USTLFIR" );
    mask = i_mcc->getRegister( "USTLFIR_MASK" );
    act0 = i_mcc->getRegister( "USTLFIR_ACT0" );
    act1 = i_mcc->getRegister( "USTLFIR_ACT1" );
    cnfg = i_mcc->getRegister( "USTLFAILMASK" );

    if ( SUCCESS == (fir->Read() | mask->Read() | act0->Read() | act1->Read() |
                     cnfg->Read()) )
    {
        // Get which relevant channel we need to check.
        std::map<uint8_t,uint8_t> ustlfirMap;
        ustlfirMap = (0 == omiPos) ? ustlfirMapChanA : ustlfirMapChanB;

        for ( auto const & bits : ustlfirMap )
        {
            uint8_t firBit  = bits.first;
            uint8_t cnfgBit = bits.second;

            // NOTE: Channel fail is enabled if the config bit is set to 0b0
            if ( !cnfg->IsBitSet(cnfgBit) &&  fir->IsBitSet(firBit) &&
                 !mask->IsBitSet(firBit)  && act0->IsBitSet(firBit) &&
                  act1->IsBitSet(firBit) )
            {
                o_activeAttn = true;
            }
        }
    }

    return o_activeAttn;
}

bool __queryUcsOcmb( ExtensibleChip * i_ocmb )
{
    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_ocmb->getType() );

    bool o_activeAttn = false;

    // Query the OCMB chiplet level FIR to determine if we have a UNIT_CS.
    SCAN_COMM_REGISTER_CLASS * fir = i_ocmb->getRegister("OCMB_CHIPLET_CS_FIR");
    SCAN_COMM_REGISTER_CLASS * mask =
            i_ocmb->getRegister("OCMB_CHIPLET_FIR_MASK");

    if ( SUCCESS == (fir->Read() | mask->Read()) )
    {
        if ( 0 != (   fir->GetBitFieldJustified(0,64) &
                    ~mask->GetBitFieldJustified(0,64) &
                    0x1fffffffffffffff ) )
        {
            o_activeAttn = true;
        }
    }

    return o_activeAttn;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
bool __analyzeChnlFail( TargetHandle_t i_trgt,
                        STEP_CODE_DATA_STRUCT & io_sc );

template<>
bool __analyzeChnlFail<TYPE_OMI>( TargetHandle_t i_omi,
                                  STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemUtils::__analyzeChnlFail<TYPE_OMI>] "

    PRDF_ASSERT( nullptr != i_omi );
    PRDF_ASSERT( TYPE_OMI == getTargetType(i_omi) );

    uint32_t o_analyzed = false;

    do
    {
        // Skip if currently analyzing a host attention. This is a required for
        // a rare scenario when a channel failure occurs after PRD is called to
        // handle the host attention.
        if ( HOST_ATTN == io_sc.service_data->getPrimaryAttnType() ) break;

        // Get the needed ExtensibleChips for analysis
        TargetHandle_t ocmb = getConnectedChild( i_omi, TYPE_OCMB_CHIP, 0 );
        ExtensibleChip * ocmbChip = (ExtensibleChip *)systemPtr->GetChip(ocmb);

        TargetHandle_t omic = getConnectedParent( i_omi, TYPE_OMIC );
        ExtensibleChip * omicChip = (ExtensibleChip *)systemPtr->GetChip(omic);

        TargetHandle_t mcc = getConnectedParent( i_omi, TYPE_MCC );
        ExtensibleChip * mccChip = (ExtensibleChip *)systemPtr->GetChip(mcc);

        // Do an initial query for channel fail attentions from the targets.
        // This is to check whether we actually have an active channel fail
        // attention before checking whether it is a side effect of some
        // recoverable attention or not.
        if ( !__queryUcsOmic(omicChip, mccChip, i_omi) &&
             !__queryUcsMcc(mccChip, i_omi) &&
             !__queryUcsOcmb(ocmbChip) )
        {
            // If no channel fail attentions found, just break out.
            break;
        }

        // There was a channel fail found, so take the following actions.

        // Set the MEM_CHNL_FAIL flag in the SDC to indicate a channel failure
        // has been detected and there is no need to check again.
        io_sc.service_data->setMemChnlFail();

        // Make the error log predictive and set threshold.
        io_sc.service_data->setFlag( ServiceDataCollector::SERVICE_CALL );
        io_sc.service_data->setFlag( ServiceDataCollector::AT_THRESHOLD );

        // Channel failures will always send SUEs.
        io_sc.service_data->setFlag( ServiceDataCollector::UERE );

        // Indicate cleanup is required on this channel.
        getOcmbDataBundle(ocmbChip)->iv_doChnlFailCleanup = true;

        // Check for recoverable attentions that could have a channel failure
        // as a side effect. These include: N/A
        // TODO RTC 243518 -requires more input from the test team to determine

        // Check OMIC for unit checkstops
        if ( __queryUcsOmic( omicChip, mccChip, i_omi ) )
        {
            // Analyze UNIT_CS on the OMIC chip
            // Note: The OMIDLFIR can't actually be set up to report UNIT_CS
            // attentions, instead, as a workaround, the relevant channel fail
            // bits will be set as recoverable bits and we will manually set
            // the attention types to UNIT_CS in our handling of those errors.
            if ( SUCCESS == omicChip->Analyze(io_sc, RECOVERABLE) )
            {
                o_analyzed = true;
                break;
            }
        }

        // Check MCC for unit checkstops
        if ( __queryUcsMcc( mccChip, i_omi ) )
        {
            // Analyze UNIT_CS on the MCC chip
            if ( SUCCESS == mccChip->Analyze(io_sc, UNIT_CS) )
            {
                o_analyzed = true;
                break;
            }
        }

        // Check OCMB for unit checkstops
        if ( __queryUcsOcmb( ocmbChip ) )
        {
            // Analyze UNIT_CS on the OCMB chip
            if ( SUCCESS == ocmbChip->Analyze(io_sc, UNIT_CS) )
            {
                o_analyzed = true;
                break;
            }

        }
        PRDF_INF( PRDF_FUNC "Failed channel detected on 0x%08x, but no active "
                  "attentions found", getHuid(i_omi) );
    }while(0);

    return o_analyzed;

    #undef PRDF_FUNC
}

template<>
bool analyzeChnlFail<TYPE_MCC>( ExtensibleChip * i_mcc,
                                STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_mcc );
    PRDF_ASSERT( TYPE_MCC == i_mcc->getType() );

    uint32_t o_analyzed = false;

    if ( !io_sc.service_data->isMemChnlFail() )
    {
        // Loop through all the connected OMIs
        for ( auto & omi : getConnected(i_mcc->getTrgt(), TYPE_OMI) )
        {
            o_analyzed = __analyzeChnlFail<TYPE_OMI>( omi, io_sc );
            if ( o_analyzed ) break;
        }
    }

    return o_analyzed;
}

template<>
bool analyzeChnlFail<TYPE_OMIC>( ExtensibleChip * i_omic,
                                 STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_omic );
    PRDF_ASSERT( TYPE_OMIC == i_omic->getType() );

    uint32_t o_analyzed = false;

    if ( !io_sc.service_data->isMemChnlFail() )
    {
        // Loop through all the connected OMIs
        for ( auto & omi : getConnected(i_omic->getTrgt(), TYPE_OMI) )
        {
            o_analyzed = __analyzeChnlFail<TYPE_OMI>( omi, io_sc );
            if ( o_analyzed ) break;
        }
    }

    return o_analyzed;
}

template<>
bool analyzeChnlFail<TYPE_OCMB_CHIP>( ExtensibleChip * i_ocmb,
                                      STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_ocmb->getType() );

    uint32_t o_analyzed = false;

    if ( !io_sc.service_data->isMemChnlFail() )
    {
        TargetHandle_t omi = getConnectedParent( i_ocmb->getTrgt(), TYPE_OMI );
        o_analyzed = __analyzeChnlFail<TYPE_OMI>( omi, io_sc );
    }

    return o_analyzed;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T1, TARGETING::TYPE T2, TARGETING::TYPE T3>
void __cleanupChnlFail( ExtensibleChip * i_chip1, ExtensibleChip * i_chip2,
                        ExtensibleChip * i_chip3,
                        STEP_CODE_DATA_STRUCT & io_sc );

template<>
void __cleanupChnlFail<TYPE_MC,TYPE_DMI,TYPE_MEMBUF>(
                                              ExtensibleChip * i_mcChip,
                                              ExtensibleChip * i_dmiChip,
                                              ExtensibleChip * i_membChip,
                                              STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemUtils::__cleanupChnlFail] "

    PRDF_ASSERT( nullptr != i_mcChip );
    PRDF_ASSERT( TYPE_MC == i_mcChip->getType() );

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
    uint32_t dmiPos = i_dmiChip->getPos() % MAX_DMI_PER_MC;

    // Mask off all attentions from the DMI target in the CHIFIR.
    reg = i_dmiChip->getRegister( "CHIFIR_MASK_OR" );
    reg->setAllBits();
    reg->Write();

    // Mask off all attentions from the DMI target in the IOMCFIR.
    reg = i_mcChip->getRegister( "IOMCFIR_MASK_OR" );
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

    // To ensure FSP ATTN doesn't think there is an active attention on this
    // Centaur, manually clear the interrupt status register.
    reg = i_membChip->getRegister( "INTER_STATUS_REG" );
    reg->clearAllBits(); // Blindly clear everything
    reg->Write();

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
void cleanupChnlFail<TYPE_MC>( ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MC == i_chip->getType() );

    for ( auto & dmiChip : getConnected(i_chip, TYPE_DMI) )
    {
        ExtensibleChip * membChip = getConnectedChild( dmiChip, TYPE_MEMBUF, 0);
        PRDF_ASSERT( nullptr != membChip ); // shouldn't be possible

        __cleanupChnlFail<TYPE_MC,TYPE_DMI,TYPE_MEMBUF>( i_chip, dmiChip,
                                                         membChip, io_sc );
    }
}

template<>
void cleanupChnlFail<TYPE_DMI>( ExtensibleChip * i_chip,
                                STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_DMI == i_chip->getType() );

    ExtensibleChip * mcChip = getConnectedParent( i_chip, TYPE_MC );

    cleanupChnlFail<TYPE_MC>( mcChip, io_sc );
}

template<>
void cleanupChnlFail<TYPE_MEMBUF>( ExtensibleChip * i_chip,
                                   STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEMBUF == i_chip->getType() );

    ExtensibleChip * dmiChip = getConnectedParent( i_chip, TYPE_DMI );

    cleanupChnlFail<TYPE_DMI>( dmiChip, io_sc );
}

template<TARGETING::TYPE T>
void __cleanupChnlFail( TargetHandle_t i_trgt, STEP_CODE_DATA_STRUCT & io_sc );

template<>
void __cleanupChnlFail<TYPE_OMI>( TargetHandle_t i_omi,
                                  STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemUtils::__cleanupChnlFail] "

    PRDF_ASSERT( nullptr != i_omi );
    PRDF_ASSERT( TYPE_OMI == getTargetType(i_omi) );

    do
    {
        // No cleanup if this is a checkstop attention.
        if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() ) break;

        TargetHandle_t ocmb = getConnectedChild(i_omi, TYPE_OCMB_CHIP, 0);
        ExtensibleChip * ocmbChip = (ExtensibleChip *)systemPtr->GetChip(ocmb);

        // Check if cleanup is still required or has already been done.
        if ( !getOcmbDataBundle(ocmbChip)->iv_doChnlFailCleanup ) break;

        // Cleanup is complete and no longer required on this channel.
        getOcmbDataBundle(ocmbChip)->iv_doChnlFailCleanup = false;

        #ifdef __HOSTBOOT_MODULE // only do cleanup in Hostboot, no-op in FSP

        TargetHandle_t omic = getConnectedParent( i_omi, TYPE_OMIC );
        ExtensibleChip * omicChip = (ExtensibleChip *)systemPtr->GetChip(omic);

        TargetHandle_t mcc  = getConnectedParent( i_omi, TYPE_MCC );
        ExtensibleChip * mccChip = (ExtensibleChip *)systemPtr->GetChip(mcc);

        // Get the OMI position relative to the OMIC (0,1,2) and the MCC (0,1)
        uint8_t omiPosRelOmic = i_omi->getAttr<ATTR_OMI_DL_GROUP_POS>();
        uint8_t omiPosRelMcc = getTargetPosition(i_omi) % MAX_OMI_PER_MCC;

        // Note that this is a clean up function. If there are any SCOM errors
        // we will just move on and try the rest.
        SCAN_COMM_REGISTER_CLASS * reg = nullptr;

        // Mask off attentions from the OMIDLFIR in the OMIC based on the
        // OMI position. 0-19, 20-39, 40-59
        reg = omicChip->getRegister( "OMIDLFIR_MASK_OR" );
        reg->SetBitFieldJustified( (omiPosRelOmic * 20), 20, 0xfffff );
        reg->Write();

        // Mask off attentions from the DSTLFIR and USTLFIR in the MCC based on
        // the OMI position.
        // DSTLFIR Generic Bits: 8,9,10,11,24,25,26,27
        uint64_t mask = 0x00f000f000000000ull;
        if ( 0 == omiPosRelMcc )
        {
            // DSTLFIR Subchannel A Bits: 0,1,2,3,12,14,16,18,20,22
            mask |= 0xf00aaa0000000000ull;
        }
        else
        {
            // DSTLFIR Subchannel B Bits: 4,5,6,7,13,15,17,19,21,23
            mask |= 0x0f05550000000000ull;
        }
        reg = mccChip->getRegister( "DSTLFIR_MASK_OR" );
        reg->SetBitFieldJustified( 0, 64, mask );
        reg->Write();

        // USTLFIR Generic Bits: 6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,
        //                       22,23,24,25,26,57,58,61,62,63
        mask = 0x03ffffe000000067ull;
        if ( 0 == omiPosRelMcc )
        {
            // USTLFIR Subchannel A Bits: 0,2,4,27,29,31,33,35,37,39,41,43,45,
            //                            47,49,51,53,55,59
            mask |= 0xa800001555555510ull;
        }
        else
        {
            // USTLFIR Subchannel B Bits: 1,3,5,28,30,32,34,36,38,40,42,44,46,
            //                            48,50,52,54,56,60
            mask |= 0x5400000aaaaaaa88ull;
        }
        reg = mccChip->getRegister( "USTLFIR_MASK_OR" );
        reg->SetBitFieldJustified( 0, 64, mask );
        reg->Write();

        // Mask off all attentions from the chiplet FIRs in the OCMB
        reg = ocmbChip->getRegister( "OCMB_CHIPLET_FIR_MASK" );
        reg->setAllBits(); // Blindly mask everything
        reg->Write();

        //   During runtime, send a dynamic memory deallocation message.
        //   During Memory Diagnostics, tell MDIA to stop pattern tests.
        #ifdef __HOSTBOOT_RUNTIME
        MemDealloc::port<TYPE_OCMB_CHIP>( ocmbChip );
        #else
        if ( isInMdiaMode() )
        {
            mdiaSendEventMsg( ocmb, MDIA::STOP_TESTING );
        }
        #endif

        #endif // Hostboot only

    }while(0);

    #undef PRDF_FUNC
}

template<>
void cleanupChnlFail<TYPE_MCC>( ExtensibleChip * i_chip,
                                STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCC == i_chip->getType() );

    for ( auto & omi : getConnected(i_chip->getTrgt(), TYPE_OMI) )
    {
        __cleanupChnlFail<TYPE_OMI>( omi, io_sc );
    }
}

template<>
void cleanupChnlFail<TYPE_OMIC>( ExtensibleChip * i_chip,
                                 STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OMIC == i_chip->getType() );

    for ( auto & omi : getConnected(i_chip->getTrgt(), TYPE_OMI) )
    {
        __cleanupChnlFail<TYPE_OMI>( omi, io_sc );
    }
}

template<>
void cleanupChnlFail<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                      STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    TargetHandle_t omi = getConnectedParent( i_chip->getTrgt(), TYPE_OMI );
    __cleanupChnlFail<TYPE_OMI>( omi, io_sc );
}

//------------------------------------------------------------------------------

uint64_t reverseBits( uint64_t i_val, uint64_t i_numBits )
{
    uint64_t o_val = 0;

    for ( uint64_t i = 0; i < i_numBits; i++ )
    {
        o_val <<= 1;
        o_val |= i_val & 0x1;
        i_val >>= 1;
    }

    return o_val;
}

//------------------------------------------------------------------------------

} // end namespace MemUtils

} // end namespace PRDF
