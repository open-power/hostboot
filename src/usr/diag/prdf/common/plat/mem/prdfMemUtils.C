/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemUtils.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2019                        */
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
#include <UtilHash.H>

// Platform includes
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

const uint8_t CE_REGS_PER_PORT = 9;
const uint8_t SYMBOLS_PER_CE_REG = 8;

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
                                               sym );
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
                        sym );
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
uint8_t getDramSize<TYPE_MEM_PORT>(ExtensibleChip *i_chip, uint8_t i_dimmSlct)
{
    #define PRDF_FUNC "[MemUtils::getDramSize] "

    PRDF_ASSERT( TYPE_MEM_PORT == i_chip->getType() );
    PRDF_ASSERT( i_dimmSlct < DIMM_SLCT_PER_PORT );

    TargetHandle_t memPortTrgt = i_chip->getTrgt();

    uint8_t tmp[DIMM_SLCT_PER_PORT];

    if ( !memPortTrgt->tryGetAttr<TARGETING::ATTR_MEM_EFF_DRAM_DENSITY>(tmp) )
    {
        PRDF_ERR( PRDF_FUNC "Failed to get ATTR_MEM_EFF_DRAM_DENSITY" );
        PRDF_ASSERT( false );
    }

    return tmp[i_dimmSlct];

    #undef PRDF_FUNC
}

template<>
uint8_t getDramSize<TYPE_OCMB_CHIP>(ExtensibleChip * i_chip, uint8_t i_dimmSlct)
{
    #define PRDF_FUNC "[MemUtils::getDramSize] "

    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );
    PRDF_ASSERT( i_dimmSlct < DIMM_SLCT_PER_PORT );

    // TODO RTC 210072 - Explorer only has one port, however, multiple ports
    // will be supported in the future. Updates will need to be made here so we
    // can get the relevant port.

    ExtensibleChip * memPort = getConnectedChild( i_chip, TYPE_MEM_PORT, 0 );

    return getDramSize<TYPE_MEM_PORT>( memPort, i_dimmSlct );

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
