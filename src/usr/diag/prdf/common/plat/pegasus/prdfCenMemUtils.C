/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMemUtils.C $     */
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

/** @file  prdfCenMemUtils.C
 *  @brief Utility functions related to Centaur
 */

#include <prdfCenMemUtils.H>
#include <prdfExtensibleChip.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfP8McsDataBundle.H>
#include <prdfPlatServices.H>
#include <prdfCenMembufDataBundle.H>
#include <prdfParserUtils.H>

#if defined(__HOSTBOOT_RUNTIME) || !defined(__HOSTBOOT_MODULE)
  #include <prdfCenMbaDynMemDealloc_rt.H>
#endif

using namespace TARGETING;

namespace PRDF
{

namespace MemUtils
{

using namespace PlatServices;
using namespace PARSERUTILS;
using namespace CEN_SYMBOL;

const uint8_t CE_REGS_PER_MBA = 9;
const uint8_t SYMBOLS_PER_CE_REG = 8;

static const char *mbsCeStatReg[][ CE_REGS_PER_MBA ] = {
                       { "MBA0_MBSSYMEC0", "MBA0_MBSSYMEC1","MBA0_MBSSYMEC2",
                         "MBA0_MBSSYMEC3", "MBA0_MBSSYMEC4", "MBA0_MBSSYMEC5",
                         "MBA0_MBSSYMEC6", "MBA0_MBSSYMEC7", "MBA0_MBSSYMEC8" },
                       { "MBA1_MBSSYMEC0", "MBA1_MBSSYMEC1","MBA1_MBSSYMEC2",
                         "MBA1_MBSSYMEC3", "MBA1_MBSSYMEC4", "MBA1_MBSSYMEC5",
                         "MBA1_MBSSYMEC6", "MBA1_MBSSYMEC7", "MBA1_MBSSYMEC8" }
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

int32_t collectCeStats( ExtensibleChip * i_mbaChip, const CenRank & i_rank,
                        MaintSymbols & o_maintStats, CenSymbol & o_chipMark,
                        uint8_t i_thr )
{
    #define PRDF_FUNC "[MemUtils::collectCeStats] "

    int32_t o_rc = SUCCESS;

    o_chipMark = CenSymbol(); // Initially invalid.

    do
    {
        if ( 0 == i_thr ) // Must be non-zero
        {
            PRDF_ERR( PRDF_FUNC "i_thr %d is invalid", i_thr );
            o_rc = FAIL; break;
        }

        TargetHandle_t mbaTrgt = i_mbaChip->GetChipHandle();
        CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );
        ExtensibleChip * membufChip = mbadb->getMembChip();
        if ( NULL == membufChip )
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
        CenSymbol sp0, sp1, ecc;
        o_rc = mssGetSteerMux( mbaTrgt, i_rank, sp0, sp1, ecc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed." );
            break;
        }

        // Use this map to keep track of the total counts per DRAM.
        DramCountMap dramCounts;

        const char * reg_str = NULL;
        SCAN_COMM_REGISTER_CLASS * reg = NULL;

        for ( uint8_t regIdx = 0; regIdx < CE_REGS_PER_MBA; regIdx++ )
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
                uint8_t dram = symbol2Dram( sym, isX4 );

                // Keep track of the total DRAM counts.
                dramCounts[dram].totalCount += count;

                // Add any symbols that have exceeded threshold to the list.
                if ( i_thr <= count )
                {
                    // Keep track of the total number of symbols per DRAM that
                    // have exceeded threshold.
                    dramCounts[dram].symbolCount++;

                    SymbolData symData;
                    symData.symbol = CenSymbol::fromSymbol( mbaTrgt, i_rank,
                                            sym, CEN_SYMBOL::BOTH_SYMBOL_DQS );
                    if ( !symData.symbol.isValid() )
                    {
                        PRDF_ERR( PRDF_FUNC "CenSymbol() failed: symbol=%d",
                                  sym );
                        o_rc = FAIL;
                        break;
                    }
                    else
                    {
                        // Check if this symbol is on any of the spares.
                        if ( ( sp0.isValid() &&
                               (sp0.getDram() == symData.symbol.getDram()) ) ||
                             ( sp1.isValid() &&
                               (sp1.getDram() == symData.symbol.getDram()) ) )
                        {
                            symData.symbol.setDramSpared();
                        }
                        if ( ecc.isValid() &&
                             (ecc.getDram() == symData.symbol.getDram()) )
                        {
                            symData.symbol.setEccSpared();
                        }

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
            uint8_t sym = dram2Symbol( highestDram, isX4 );
            o_chipMark  = CenSymbol::fromSymbol( mbaTrgt, i_rank, sym );

            // Check if this symbol is on any of the spares.
            if ( ( sp0.isValid() && (sp0.getDram() == o_chipMark.getDram()) ) ||
                 ( sp1.isValid() && (sp1.getDram() == o_chipMark.getDram()) ) )
            {
                o_chipMark.setDramSpared();
            }
            if ( ecc.isValid() && (ecc.getDram() == o_chipMark.getDram()) )
            {
                o_chipMark.setEccSpared();
            }
        }

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed: i_mbaChip=0x%08x i_rank=m%ds%d i_thr=%d",
                  i_mbaChip->GetId(), i_rank.getMaster(), i_rank.getSlave(),
                  i_thr );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t clearPerSymbolCounters( ExtensibleChip * i_membChip, uint32_t i_mbaPos )
{
    #define PRDF_FUNC "[MemUtils::clearPerSymbolCounters] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( MAX_MBA_PER_MEMBUF <= i_mbaPos )
        {
            PRDF_ERR( PRDF_FUNC "i_mbaPos %d is invalid", i_mbaPos );
            o_rc = FAIL;
            break;
        }

        const char * reg_str = NULL;
        SCAN_COMM_REGISTER_CLASS * reg = NULL;

        for ( uint8_t regIdx = 0; regIdx < CE_REGS_PER_MBA; regIdx++ )
        {
            reg_str = mbsCeStatReg[i_mbaPos][regIdx];
            reg     = i_membChip->getRegister( reg_str );

            reg->clearAllBits();

            o_rc = reg->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on %s", reg_str );
                break;
            }
        }

        if ( SUCCESS != o_rc ) break;

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed. i_membChip=0x%08x i_mbaPos=%d",
                  i_membChip->GetId(), i_mbaPos );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t getDramSize( ExtensibleChip *i_mbaChip, uint8_t & o_size )
{
    #define PRDF_FUNC "[MemUtils::getDramSize] "

    int32_t o_rc = SUCCESS;
    o_size = SIZE_2GB;

    do
    {
        TargetHandle_t mbaTrgt = i_mbaChip->GetChipHandle();
        CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );
        ExtensibleChip * membufChip = mbadb->getMembChip();
        if ( NULL == membufChip )
        {
            PRDF_ERR( PRDF_FUNC "getMembChip() failed: MBA=0x%08x",
                      getHuid(mbaTrgt) );
            o_rc = FAIL; break;
        }

        uint32_t pos = getTargetPosition(mbaTrgt);
        const char * reg_str = (0 == pos) ? "MBA0_MBAXCR" : "MBA1_MBAXCR";

        SCAN_COMM_REGISTER_CLASS * reg = membufChip->getRegister( reg_str );
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s. Target=0x%08x",
                      reg_str, getHuid(mbaTrgt) );
            break;
        }
        o_size = reg->GetBitFieldJustified( 6, 2 );

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t checkMcsChannelFail( ExtensibleChip * i_mcsChip,
                             STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemUtils::checkMcsChannelFail] "

    int32_t o_rc = SUCCESS;

    do
    {
        // Skip if already handling unit checkstop.
        if ( io_sc.service_data->IsUnitCS() )
            break;

        // Must be an MCS.
        if ( TYPE_MCS != getTargetType(i_mcsChip->GetChipHandle()) )
        {
            PRDF_ERR( PRDF_FUNC "i_mcsChip is not TYPE_MCS" );
            o_rc = FAIL; break;
        }

        // Check MCIFIR[31] for presence of channel fail.
        SCAN_COMM_REGISTER_CLASS * mcifir = i_mcsChip->getRegister("MCIFIR");
        o_rc = mcifir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCIFIR" );
            break;
        }

        if ( !mcifir->IsBitSet(31) ) break; // No channel fail, so exit.

        // Set unit checkstop flag and cause attention type.
        io_sc.service_data->setFlag(ServiceDataCollector::UNIT_CS);
        io_sc.service_data->setSecondaryAttnType(UNIT_CS);
        io_sc.service_data->SetThresholdMaskId(0);

        // Indicate that cleanup is required.
        P8McsDataBundle * mcsdb = getMcsDataBundle( i_mcsChip );
        ExtensibleChip * membChip = mcsdb->getMembChip();
        if ( NULL == membChip )
        {
            PRDF_ERR( PRDF_FUNC "getMembChip() returned NULL" );
            o_rc = FAIL; break;
        }
        CenMembufDataBundle * mbdb = getMembufDataBundle( membChip );
        mbdb->iv_doChnlFailCleanup = true;

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed: i_mcsChip=0x%08x", i_mcsChip->GetId() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t chnlCsCleanup( ExtensibleChip *i_mbChip,
                       STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[MemUtils::chnlCsCleanup] "

    int32_t o_rc = SUCCESS;

    do
    {
        if( (  NULL == i_mbChip ) ||
            ( TYPE_MEMBUF != getTargetType( i_mbChip->GetChipHandle() )))
        {
            PRDF_ERR( PRDF_FUNC "Invalid parameters" );
            o_rc = FAIL; break;
        }

        if (( ! i_sc.service_data->IsUnitCS() ) ||
              (CHECK_STOP == i_sc.service_data->getPrimaryAttnType()) )
            break;

        CenMembufDataBundle * mbdb = getMembufDataBundle( i_mbChip );
        if ( !mbdb->iv_doChnlFailCleanup )
            break; // Cleanup has already been done.

        // Set it as SUE generation point.
        i_sc.service_data->SetUERE();

        ExtensibleChip * mcsChip = mbdb->getMcsChip();
        if ( NULL == mcsChip )
        {
            PRDF_ERR( PRDF_FUNC "MCS chip is NULL for Membuf:0x%08X",
                      i_mbChip->GetId() );
            o_rc = FAIL; break;
        }

        TargetHandle_t mcs = mcsChip->GetChipHandle();
        ExtensibleChip * procChip = NULL;
        uint8_t pos = getTargetPosition( mcs );
        TargetHandle_t proc = getParentChip ( mcs );

        if ( NULL == proc )
        {
            PRDF_ERR( PRDF_FUNC "Proc is NULL for Mcs:0x%08X", getHuid( mcs ) );
            o_rc = FAIL; break;
        }

        procChip = (ExtensibleChip *)systemPtr->GetChip( proc );

        if( NULL == procChip )
        {
            PRDF_ERR( PRDF_FUNC "Can not find Proc chip for HUID:0x%08X",
                      getHuid( proc) );
            o_rc = FAIL; break;
        }

        // This is a cleanup function. If we get any error from scom
        // operations, we will still continue with cleanup.
        SCAN_COMM_REGISTER_CLASS * l_tpMask =
              procChip->getRegister("TP_CHIPLET_FIR_MASK");
        o_rc |= l_tpMask->Read();
        if ( SUCCESS == o_rc )
        {
            // Bits 5-12 maps to attentions from MCS0-MCS7.
            l_tpMask->SetBit( 5 + pos );
            o_rc |= l_tpMask->Write();
        }

        // Mask attentions from the Centaur
        const char *iomcFirMask = ( pos < 4 )?
                                  "IOMCFIR_0_MASK_OR":"IOMCFIR_1_MASK_OR";

        SCAN_COMM_REGISTER_CLASS * iomcMask =
                                 procChip->getRegister( iomcFirMask);
        if ( pos >= 4 ) pos -= 4;

        // 8 bits are reserved for each Centaur in IOMCFIR.
        // There are total 4 ( for P system ) centaur supported
        // in MCS. Bits for first centaur starts from bit 8.

        iomcMask->SetBitFieldJustified( 8+ ( pos*8 ), 8, 0xff);

        o_rc |= iomcMask->Write();

        SCAN_COMM_REGISTER_CLASS * l_tpfirmask   = NULL;
        SCAN_COMM_REGISTER_CLASS * l_nestfirmask = NULL;
        SCAN_COMM_REGISTER_CLASS * l_memfirmask  = NULL;
        SCAN_COMM_REGISTER_CLASS * l_memspamask  = NULL;

        l_tpfirmask   = i_mbChip->getRegister("TP_CHIPLET_FIR_MASK");
        l_nestfirmask = i_mbChip->getRegister("NEST_CHIPLET_FIR_MASK");
        l_memfirmask  = i_mbChip->getRegister("MEM_CHIPLET_FIR_MASK");
        l_memspamask  = i_mbChip->getRegister("MEM_CHIPLET_SPA_MASK");

        l_tpfirmask->setAllBits();   o_rc |= l_tpfirmask->Write();
        l_nestfirmask->setAllBits(); o_rc |= l_nestfirmask->Write();
        l_memfirmask->setAllBits();  o_rc |= l_memfirmask->Write();
        l_memspamask->setAllBits();  o_rc |= l_memspamask->Write();


        for ( uint32_t i = 0; i < MAX_MBA_PER_MEMBUF; i++ )
        {
            ExtensibleChip * mbaChip = mbdb->getMbaChip( i );
            if( NULL != mbaChip )
            {
                TargetHandle_t mba = mbaChip->GetChipHandle();
                if ( NULL != mba )
                {
                    #if  defined(__HOSTBOOT_MODULE) && \
                        !defined(__HOSTBOOT_RUNTIME)
                    // This is very small platform specific code. So not
                    // creating a separate file for this.
                    int32_t l_rc = mdiaSendEventMsg( mba, MDIA::SKIP_MBA );
                    if ( SUCCESS != l_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(0x%08x, SKIP_MBA) "
                                  "failed", getHuid( mba ) );
                        o_rc |= l_rc;
                    }
                    #else
                    int32_t l_rc = DEALLOC::mbaGard( mbaChip  );
                    if ( SUCCESS != l_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "mbaGard failed. HUID: 0x%08x",
                                  getHuid( mba ) );
                        o_rc |= l_rc;
                    }
                    #endif // __HOSTBOOT_MODULE
                }
            }
        }

        // Clean up complete an is no longer required.
        mbdb->iv_doChnlFailCleanup = false;

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace MemUtils

} // end namespace PRDF
