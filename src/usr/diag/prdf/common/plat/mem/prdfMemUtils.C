/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemUtils.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#include <prdfOcmbDataBundle.H>
#include <prdfMemSymbol.H>
#include <prdfParserUtils.H>
#include <prdfPlatServices.H>

// External includes
#include <algorithm>

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

        const char * reg_str = nullptr;
        SCAN_COMM_REGISTER_CLASS * reg = nullptr;

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
uint8_t collectMceBadSyms<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                           uint8_t i_thr )
{
    uint8_t o_badSymCount = 0;

    // The MBSMSEC register contains four 8-bit counts that increment on MCE
    // when their respective symbols (0:3) under chip mark take an error.
    SCAN_COMM_REGISTER_CLASS * mbsmsec = i_chip->getRegister("MBSMSEC");
    if ( SUCCESS == mbsmsec->Read() )
    {
        const uint8_t mceSymNum = 4;
        for ( uint8_t n = 0; n < mceSymNum; n++ )
        {
            // Get each symbol count (0:3)
            uint8_t symCount = mbsmsec->GetBitFieldJustified( 8*n, 8 );
            if ( symCount >= i_thr )
            {
                o_badSymCount++;
            }
        }
    }

    return o_badSymCount;
}

//------------------------------------------------------------------------------

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

    SCAN_COMM_REGISTER_CLASS * dstlfir_and =
        mcc->getRegister( "MC_DSTL_FIR_AND" );

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
                    mcc->getRegister( "MC_DSTL_FIR_OR" );
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

        // Check the MC_OMI_DL_FIR for UCS (relevant bits: 0,20)
        SCAN_COMM_REGISTER_CLASS * fir  = nullptr;
        SCAN_COMM_REGISTER_CLASS * mask = nullptr;
        SCAN_COMM_REGISTER_CLASS * act0 = nullptr;
        SCAN_COMM_REGISTER_CLASS * act1 = nullptr;

        fir  = i_omic->getRegister("MC_OMI_DL_FIR");
        mask = i_omic->getRegister("MC_OMI_DL_FIR_MASK");
        act0 = i_omic->getRegister("MC_OMI_DL_FIR_ACT0");
        act1 = i_omic->getRegister("MC_OMI_DL_FIR_ACT1");

        if ( SUCCESS == ( fir->Read() | mask->Read() |
                         act0->Read() | act1->Read() ) )
        {
            // Get the position of the inputted OMI relative to the parent
            // OMIC (0-2). We'll need to use ATTR_REL_POS for this.
            uint8_t omiPosRelOmic = i_omi->getAttr<ATTR_REL_POS>();

            // Get the bit offset for the bit relevant to the inputted OMI.
            // 0 : OMI-DL 0
            // 20: OMI-DL 1
            uint8_t bitOff = omiPosRelOmic * 20;

            // Check if there is a UNIT_CS for the relevant bits in the
            // MC_OMI_DL_FIR.
            // Note: The MC_OMI_DL_FIR can't actually be set up to report
            // UNIT_CS attentions, instead, as a workaround, the relevant
            // channel fail bits will be set as recoverable bits and we will
            // manually set the attention types to UNIT_CS in our handling of
            // those errors.
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
        { {12,28}, {16,30}, {22,24}, {35,49} };

    const std::map<uint8_t,uint8_t> dstlfirMapChanB =
        { {13,29}, {17,31}, {23,25}, {36,50} };

    // Check the DSTLFIR for UCS
    SCAN_COMM_REGISTER_CLASS * fir  = i_mcc->getRegister( "MC_DSTL_FIR" );
    SCAN_COMM_REGISTER_CLASS * mask = i_mcc->getRegister( "MC_DSTL_FIR_MASK" );
    SCAN_COMM_REGISTER_CLASS * act0 = i_mcc->getRegister( "MC_DSTL_FIR_ACT0" );
    SCAN_COMM_REGISTER_CLASS * act1 = i_mcc->getRegister( "MC_DSTL_FIR_ACT1" );
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
    fir  = i_mcc->getRegister( "MC_USTL_FIR" );
    mask = i_mcc->getRegister( "MC_USTL_FIR_MASK" );
    act0 = i_mcc->getRegister( "MC_USTL_FIR_ACT0" );
    act1 = i_mcc->getRegister( "MC_USTL_FIR_ACT1" );
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

    // If this OCMB has been marked as masked, skip it
    if ( getOcmbDataBundle(i_ocmb)->iv_maskChnl )
    {
        return o_activeAttn;
    }

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

        // Channel fails are not supported for P10 DD1. Skip querying
        if ( (MODEL_POWER10 == getChipModel(i_omi)) &&
             (0x10 == getChipLevel(i_omi)) )
        {
            return o_analyzed;
        }

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

        // Check OMIC for unit checkstops
        if ( __queryUcsOmic( omicChip, mccChip, i_omi ) )
        {
            // Analyze UNIT_CS on the OMIC chip
            // Note: The MC_OMI_DL_FIR can't actually be set up to report
            // UNIT_CS attentions, instead, as a workaround, the relevant
            // channel fail bits will be set as recoverable bits and we will
            // manually set the attention types to UNIT_CS in our handling of
            // those errors.
            if ( SUCCESS == omicChip->Analyze(io_sc, RECOVERABLE) )
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
        for ( auto & omi : getConnectedChildren(i_mcc->getTrgt(), TYPE_OMI) )
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
        for ( auto & omi : getConnectedChildren(i_omic->getTrgt(), TYPE_OMI) )
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

        // After a channel fail, we can't be sure whether we will be able
        // to perform putscoms to the OCMB. As such, we can't mask anything
        // on the OCMB itself, so we'll need to rely on the iv_maskChnl
        // flag and the MC_DSTL_FIR being masked.

        // Set iv_maskChnl in the data bundle to indicate this chnl is masked
        getOcmbDataBundle(ocmbChip)->iv_maskChnl = true;

        TargetHandle_t omic = getConnectedParent( i_omi, TYPE_OMIC );
        ExtensibleChip * omicChip = (ExtensibleChip *)systemPtr->GetChip(omic);

        TargetHandle_t mcc  = getConnectedParent( i_omi, TYPE_MCC );
        ExtensibleChip * mccChip = (ExtensibleChip *)systemPtr->GetChip(mcc);

        // Get the OMI position relative to the OMIC (0,1) and the MCC (0,1)
        uint8_t omiPosRelOmic = i_omi->getAttr<ATTR_REL_POS>();
        uint8_t omiPosRelMcc = getTargetPosition(i_omi) % MAX_OMI_PER_MCC;

        // Note that this is a clean up function. If there are any SCOM errors
        // we will just move on and try the rest.
        SCAN_COMM_REGISTER_CLASS * reg = nullptr;

        // Mask off attentions from the MC_OMI_DL_FIR in the OMIC based on the
        // OMI position. 0-19, 20-39, 40-59
        reg = omicChip->getRegister( "MC_OMI_DL_FIR_MASK_OR" );
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
        reg = mccChip->getRegister( "MC_DSTL_FIR_MASK_OR" );
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
        reg = mccChip->getRegister( "MC_USTL_FIR_MASK_OR" );
        reg->SetBitFieldJustified( 0, 64, mask );
        reg->Write();

        //   During runtime, send a dynamic memory deallocation message.
        //   During Memory Diagnostics, tell MDIA to stop pattern tests.
        #ifdef __HOSTBOOT_RUNTIME
        MemDealloc::port<TYPE_OCMB_CHIP>( ocmbChip );
        #else
        if ( isInMdiaMode() )
        {
            mdiaSendEventMsg( ocmb, MDIA::CHNL_FAILED );
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

    for ( auto & omi : getConnectedChildren(i_chip->getTrgt(), TYPE_OMI) )
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

    for ( auto & omi : getConnectedChildren(i_chip->getTrgt(), TYPE_OMI) )
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

template<>
uint32_t getAddrConfig<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
    uint8_t i_dslct, bool & o_twoDimmConfig, uint8_t & o_prnkBits,
    uint8_t & o_srnkBits, uint8_t & o_extraRowBits, bool & o_col3Config )
{
    #define PRDF_FUNC "[MemUtils::getAddrConfig] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );
    int32_t o_rc = SUCCESS;

    OcmbDataBundle * db = getOcmbDataBundle( i_chip );
    BitStringBuffer mc_addr_trans0(64);
    o_rc = db->iv_addrConfig.getMcAddrTrans0( mc_addr_trans0 );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Unable to get address configuration data from "
                  "0x%08x", i_chip->getHuid() );
        return o_rc;
    }

    // Check for two dimm config
    o_twoDimmConfig = false;
    if ( mc_addr_trans0.isBitSet(0) && mc_addr_trans0.isBitSet(16) )
        o_twoDimmConfig = true;

    // Get the primary rank bits that are configured
    o_prnkBits = 0;
    if ( mc_addr_trans0.isBitSet(i_dslct ? 21: 5) ) o_prnkBits++;
    if ( mc_addr_trans0.isBitSet(i_dslct ? 22: 6) ) o_prnkBits++;

    // Get the secondary rank bits that are configured
    o_srnkBits = 0;
    if ( mc_addr_trans0.isBitSet(i_dslct ? 25: 9) ) o_srnkBits++;
    if ( mc_addr_trans0.isBitSet(i_dslct ? 26:10) ) o_srnkBits++;
    if ( mc_addr_trans0.isBitSet(i_dslct ? 27:11) ) o_srnkBits++;

    // According to the hardware team, B2 is used for DDR4e which went away. If
    // for some reason B2 is valid, there is definitely a bug.
    if ( mc_addr_trans0.isBitSet(i_dslct ? 28:12) )
    {
        PRDF_ERR( PRDF_FUNC "B2 enabled in MC_ADDR_TRANS: i_chip=0x%08x "
                  "i_dslct=%d", i_chip->getHuid(), i_dslct );
        return FAIL;
    }

    // Get the extra row bits that are configured
    o_extraRowBits = 0;
    if ( mc_addr_trans0.isBitSet(i_dslct ? 29:13) ) o_extraRowBits++;
    if ( mc_addr_trans0.isBitSet(i_dslct ? 30:14) ) o_extraRowBits++;
    if ( mc_addr_trans0.isBitSet(i_dslct ? 31:15) ) o_extraRowBits++;

    // Check whether the column3 bit is used
    o_col3Config = db->iv_addrConfig.getCol3Valid();

    return o_rc;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

} // end namespace MemUtils

} // end namespace PRDF
