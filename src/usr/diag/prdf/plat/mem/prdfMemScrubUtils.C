/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemScrubUtils.C $              */
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

/** @file  prdfMemScrubUtils.C
 *  @brief Define the functionality necessary to start initial background scrub
 */

// Framework includes
#include <prdfMemScrubUtils.H>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>
#include <target_types.H>
#include <prdfTargetServices.H>
#include <prdfRegisterCache.H>

// Platform includes
#include <prdfMemThresholds.H>

using namespace TARGETING;

namespace PRDF
{
using namespace PlatServices;

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __clearFir( ExtensibleChip * i_chip, const char * i_firAnd,
                     uint64_t i_pattern )
{
    #define PRDF_FUNC "[__clearFir] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( i_firAnd );
    reg->SetBitFieldJustified( 0, 64, i_pattern );

    uint32_t o_rc = reg->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on %s: i_chip=0x%08x",
                  i_firAnd, i_chip->getHuid() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t clearCmdCompleteAttn<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip )
{
    // Clear MCBISTFIR[10].
    return __clearFir<TYPE_OCMB_CHIP>( i_chip, "MCBISTFIR_AND",
                                       0xffdfffffffffffffull );
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __clearEccCounters( ExtensibleChip * i_chip, const char * i_reg,
                             uint32_t i_bit )
{
    #define PRDF_FUNC "[__clearEccCounters] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( i_reg );
        o_rc = reg->ForceRead(); // force required
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "ForceRead() failed on %s: i_chip=0x%08x",
                      i_reg, i_chip->getHuid() );
            break;
        }

        reg->SetBit( i_bit ); // Setting this bit clears all counters.

        o_rc = reg->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s: i_chip=0x%08x",
                      i_reg, i_chip->getHuid() );
            break;
        }

        // Hardware automatically clears this bit. So flush this register out
        // of the register cache to avoid clearing the counters again with
        // a write from the out-of-date cached copy.
        RegDataCache & cache = RegDataCache::getCachedRegisters();
        cache.flush( i_chip, reg );

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t clearEccCounters<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip )
{
    return __clearEccCounters<TYPE_OCMB_CHIP>( i_chip, "MCB_CNTL", 7 );
}

//------------------------------------------------------------------------------

template<>
uint32_t clearEccFirs<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip )
{
    uint32_t o_rc = SUCCESS;

    do
    {
        // Clear MCBISTFIR[5:9]
        o_rc = __clearFir<TYPE_OCMB_CHIP>( i_chip, "MCBISTFIR_AND",
                                           0xf83fffffffffffffull );
        if ( SUCCESS != o_rc ) break;

        // Maintenance AUEs/IAUEs will be reported as system checkstops.
        // Maintenance IMPEs will be reported as recoverable attentions at
        // all times. Maintence IUEs will be masked during Memory
        // Diagnostics and handled in the Targeted diagnostics code. After
        // Memory Diagnostics, maintenance IUEs will be reported as
        // recoverable in the field (no stop-on-error), but will remain
        // masked if MNFG thresholds are enabled. In this case, the command
        // will stop on RCE ETE in order to get a more accuracy callout. So
        // clear RDFFIR[20:32,34:35,38] always and RDFFIR[37] in MNFG
        // mode or during Memory Diagnostics.
        uint64_t              mask  = 0xfffff0004dffffffull;
        if ( mfgMode() )      mask &= 0xfffffffffbffffffull;
        #ifndef __HOSTBOOT_RUNTIME
        if ( isInMdiaMode() ) mask &= 0xfffffffffbffffffull;
        #endif

        o_rc = __clearFir<TYPE_OCMB_CHIP>( i_chip, "RDFFIR_AND", mask );
        if ( SUCCESS != o_rc ) break;

    } while(0);

    return o_rc;
}

//------------------------------------------------------------------------------

template<>
uint32_t checkEccFirs<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                       uint32_t & o_eccAttns )
{
    #define PRDF_FUNC "[checkEccFirs<TYPE_OCMB_CHIP>] "

    uint32_t o_rc = SUCCESS;

    o_eccAttns = MAINT_NO_ERROR;

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    SCAN_COMM_REGISTER_CLASS * rdffir    = i_chip->getRegister( "RDFFIR" );
    SCAN_COMM_REGISTER_CLASS * mcbistfir = i_chip->getRegister( "MCBISTFIR" );

    do
    {
        o_rc = rdffir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on RDFFIR: i_chip=0x%08x",
                      i_chip->getHuid() );
            break;
        }

        // We can assume that any chip mark placed by a maintenance command was
        // done on the rank in which the command stopped. So we can blindly
        // check all bits to determine if there was an MPE on the stopped rank.
        if ( 0 != rdffir->GetBitFieldJustified(20,8) ) o_eccAttns |= MAINT_MPE;

        if ( rdffir->IsBitSet(28) ) o_eccAttns |= MAINT_NCE;
        if ( rdffir->IsBitSet(29) ) o_eccAttns |= MAINT_TCE;
        if ( rdffir->IsBitSet(30) ) o_eccAttns |= MAINT_SCE;
        if ( rdffir->IsBitSet(31) ) o_eccAttns |= MAINT_MCE;
        if ( rdffir->IsBitSet(32) ) o_eccAttns |= MAINT_SUE;
        if ( rdffir->IsBitSet(34) ) o_eccAttns |= MAINT_UE;
        if ( rdffir->IsBitSet(37) ) o_eccAttns |= MAINT_IUE;
        if ( rdffir->IsBitSet(39) ) o_eccAttns |= MAINT_IMPE;

        o_rc = mcbistfir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCBISTFIR: mcbChip=0x%08x",
                      i_chip->getHuid() );
            break;
        }

        if ( mcbistfir->IsBitSet(5) ) o_eccAttns |= MAINT_HARD_NCE_ETE;
        if ( mcbistfir->IsBitSet(6) ) o_eccAttns |= MAINT_SOFT_NCE_ETE;
        if ( mcbistfir->IsBitSet(7) ) o_eccAttns |= MAINT_INT_NCE_ETE;
        if ( mcbistfir->IsBitSet(8) ) o_eccAttns |= MAINT_RCE_ETE;

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t didCmdStopOnLastAddr( ExtensibleChip * i_chip,
                               AddrRangeType i_rangeType,
                               bool & o_stoppedOnLastAddr,
                               bool i_rowRepair )
{
    #define PRDF_FUNC "[didCmdStopOnLastAddr] "

    uint32_t o_rc = SUCCESS;

    o_stoppedOnLastAddr = false;

    do
    {
        // Get the current address.
        MemAddr curAddr;
        o_rc = getMemMaintAddr<T>( i_chip, curAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Get the end address of the current rank.
        MemAddr junk, endAddr;
        o_rc = getMemAddrRange<T>( i_chip, curAddr.getRank(), junk,
                                          endAddr, i_rangeType );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%02x) failed",
                      i_chip->getHuid(), curAddr.getRank().getKey() );
            break;
        }

        // For row repair, compare just the rank and row.
        if ( i_rowRepair )
        {
            curAddr = MemAddr( curAddr.getRank(), 0, curAddr.getRow(), 0 );
            endAddr = MemAddr( endAddr.getRank(), 0, endAddr.getRow(), 0 );
        }

        // Compare the addresses.
        o_stoppedOnLastAddr = ( curAddr == endAddr );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}
template
uint32_t didCmdStopOnLastAddr<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                               AddrRangeType i_rangeType,
                                               bool & o_stoppedOnLastAddr,
                                               bool i_rowRepair );
//------------------------------------------------------------------------------

} // end namespace PRDF

