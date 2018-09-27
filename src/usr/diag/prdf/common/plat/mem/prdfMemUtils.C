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
#include <UtilHash.H>

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
        // that could has a channel failure attention as a side effect.
        if ( __analyzeRcdParityError<TYPE_MEMBUF>(membChip, io_sc) )
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
