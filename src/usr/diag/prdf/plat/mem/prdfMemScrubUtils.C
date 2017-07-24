/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemScrubUtils.C $              */
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

/** @file  prdfMemScrubUtils.C
 *  @brief Define the functionality necessary to start initial background scrub
 */

// Framework includes
#include <prdfMemScrubUtils.H>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>
#include <fapi2.H>
#include <prdfTargetServices.H>
#include <prdfRegisterCache.H>
#include <lib/mcbist/memdiags.H>

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
uint32_t clearCmdCompleteAttn<TYPE_MCBIST>( ExtensibleChip * i_chip )
{
    // Clear MCBISTFIR[10,12].
    return __clearFir<TYPE_MCBIST>( i_chip, "MCBISTFIR_AND",
                                    0xffd7ffffffffffffull );
}

template<>
uint32_t clearCmdCompleteAttn<TYPE_MCA>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );

    return clearCmdCompleteAttn<TYPE_MCBIST>( mcbChip );
}

template<>
uint32_t clearCmdCompleteAttn<TYPE_MBA>( ExtensibleChip * i_chip )
{
    // Clear MBASPA[0,8].
    return __clearFir<TYPE_MBA>( i_chip, "MBASPA_AND", 0x7f7fffffffffffffull );
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
uint32_t clearEccCounters<TYPE_MCBIST>( ExtensibleChip * i_chip )
{
    return __clearEccCounters<TYPE_MCBIST>( i_chip, "MCB_CNTL", 7 );
}

template<>
uint32_t clearEccCounters<TYPE_MCA>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );

    return clearEccCounters<TYPE_MCBIST>( mcbChip );
}

template<>
uint32_t clearEccCounters<TYPE_MBA>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );

    const char * reg = (0 == i_chip->getPos()) ? "MBA0_MBSTR" : "MBA1_MBSTR";

    return __clearEccCounters<TYPE_MEMBUF>( membChip, reg, 53 );
}

//------------------------------------------------------------------------------

template<>
uint32_t clearEccFirs<TYPE_MCBIST>( ExtensibleChip * i_chip )
{
    uint32_t o_rc = SUCCESS;

    do
    {
        // Clear MCBISTFIR[5:9]
        o_rc = __clearFir<TYPE_MCBIST>( i_chip, "MCBISTFIR_AND",
                                        0xf83fffffffffffffull );
        if ( SUCCESS != o_rc ) break;

        for ( auto mcaChip : getConnected(i_chip, TYPE_MCA) )
        {
            // Maintenance AUEs/IAUEs will be reported as system checkstops.
            // Maintenance IMPEs will be reported as recoverable attentions at
            // all times. Maintence IUEs will be masked during Memory
            // Diagnostics and handled in the Targeted diagnostics code. After
            // Memory Diagnostics, maintenance IUEs will be reported as
            // recoverable in the field (no stop-on-error), but will remain
            // masked if MNFG thresholds are enabled. In this case, the command
            // will stop on RCE ETE in order to get a more accuracy callout. So
            // clear MCAECCFIR[20:32,34:35,38] always and MCAECCFIR[37] in MNFG
            // mode or during Memory Diagnostics.
            uint64_t              mask  = 0xfffff0004dffffffull;
            if ( mfgMode() )      mask &= 0xfffffffffbffffffull;
            #ifndef __HOSTBOOT_RUNTIME
            if ( isInMdiaMode() ) mask &= 0xfffffffffbffffffull;
            #endif

            o_rc = __clearFir<TYPE_MCA>( mcaChip, "MCAECCFIR_AND", mask );
            if ( SUCCESS != o_rc ) break;
        }

    } while(0);

    return o_rc;
}

template<>
uint32_t clearEccFirs<TYPE_MCA>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );

    return clearEccFirs<TYPE_MCBIST>( mcbChip );
}

template<>
uint32_t clearEccFirs<TYPE_MBA>( ExtensibleChip * i_chip )
{
    uint32_t o_rc = SUCCESS;

    do
    {
        ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );

        const char * reg = (0 == i_chip->getPos()) ? "MBA0_MBSECCFIR_AND"
                                                   : "MBA1_MBSECCFIR_AND";

        // Clear MBSECCFIR[20:27,36:41]
        o_rc = __clearFir<TYPE_MEMBUF>( membChip, reg, 0xfffff00ff03fffffull );
        if ( SUCCESS != o_rc ) break;

        // Clear MBASPA[1:4]
        o_rc = __clearFir<TYPE_MBA>( i_chip, "MBASPA_AND",
                                     0x87ffffffffffffffull );
        if ( SUCCESS != o_rc ) break;

    } while(0);

    return o_rc;
}

//------------------------------------------------------------------------------

template<>
uint32_t checkEccFirs<TYPE_MCA>( ExtensibleChip * i_chip,
                                 uint32_t & o_eccAttns )
{
    #define PRDF_FUNC "[checkEccFirs<TYPE_MCA>] "

    uint32_t o_rc = SUCCESS;

    o_eccAttns = MAINT_NO_ERROR;

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );

    SCAN_COMM_REGISTER_CLASS * mcaeccfir = i_chip->getRegister(  "MCAECCFIR" );
    SCAN_COMM_REGISTER_CLASS * mcbistfir = mcbChip->getRegister( "MCBISTFIR" );

    do
    {
        o_rc = mcaeccfir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCAECCFIR: i_chip=0x%08x",
                      i_chip->getHuid() );
            break;
        }

        // We can assume that any chip mark placed by a maintenance command was
        // done on the rank in which the command stopped. So we can blindly
        // check all bits to determine if there was an MPE on the stopped rank.
        if ( 0 != mcaeccfir->GetBitFieldJustified(20,8) )
            o_eccAttns |= MAINT_MPE;

        if ( mcaeccfir->IsBitSet(30) ) o_eccAttns |= MAINT_SCE;
        if ( mcaeccfir->IsBitSet(31) ) o_eccAttns |= MAINT_MCE;
        if ( mcaeccfir->IsBitSet(34) ) o_eccAttns |= MAINT_UE;
        if ( mcaeccfir->IsBitSet(37) ) o_eccAttns |= MAINT_IUE;
        if ( mcaeccfir->IsBitSet(39) ) o_eccAttns |= MAINT_IMPE;

        o_rc = mcbistfir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCBISTFIR: mcbChip=0x%08x",
                      mcbChip->getHuid() );
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

template<>
uint32_t checkEccFirs<TYPE_MBA>( ExtensibleChip * i_chip,
                                 uint32_t & o_eccAttns )
{
    #define PRDF_FUNC "[checkEccFirs<TYPE_MBA>] "

    uint32_t o_rc = SUCCESS;

    o_eccAttns = MAINT_NO_ERROR;

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );

    const char * reg = (0 == i_chip->getPos()) ? "MBA0_MBSECCFIR"
                                               : "MBA1_MBSECCFIR";

    SCAN_COMM_REGISTER_CLASS * mbseccfir = membChip->getRegister( reg );
    SCAN_COMM_REGISTER_CLASS * mbspa     = i_chip->getRegister( "MBASPA" );

    do
    {
        o_rc = mbseccfir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s: membChip=0x%08x",
                      reg, membChip->getHuid() );
            break;
        }

        // We can assume that any chip mark placed by a maintenance command was
        // done on the rank in which the command stopped. So we can blindly
        // check all bits to determine if there was an MPE.
        if ( 0 != mbseccfir->GetBitFieldJustified(20,8) )
            o_eccAttns |= MAINT_MPE;

        if ( mbseccfir->IsBitSet(37) ) o_eccAttns |= MAINT_SCE;
        if ( mbseccfir->IsBitSet(38) ) o_eccAttns |= MAINT_MCE;
        if ( mbseccfir->IsBitSet(41) ) o_eccAttns |= MAINT_UE;

        o_rc = mbspa->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBASPA: i_chip=0x%08x",
                      i_chip->getHuid() );
            break;
        }

        if ( mbspa->IsBitSet(1) ) o_eccAttns |= MAINT_HARD_NCE_ETE;
        if ( mbspa->IsBitSet(2) ) o_eccAttns |= MAINT_SOFT_NCE_ETE;
        if ( mbspa->IsBitSet(3) ) o_eccAttns |= MAINT_INT_NCE_ETE;
        if ( mbspa->IsBitSet(4) ) o_eccAttns |= MAINT_RCE_ETE;

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t isBgScrubConfig<TYPE_MCBIST>( ExtensibleChip * i_chip,
                                       bool & o_isBgScrub )
{
    #define PRDF_FUNC "[isBgScrubConfig] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCBIST == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    o_isBgScrub = false;

    do
    {
        // There really is not a good way of doing this. A scrub command is a
        // scrub command the only difference is the speed. Unfortunately, that
        // speed can change depending on how the hardware team tunes it. For
        // now, we can use the stop conditions, which should be unique for
        // background scrub, to determine if it has been configured.

        SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( "MBSTR" );
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBSTR: i_chip=0x%08x",
                      i_chip->getHuid() );
            break;
        }

        if ( 0xf != reg->GetBitFieldJustified(0,4) && // NCE int TH
             0xf != reg->GetBitFieldJustified(4,4) && // NCE soft TH
             0xf != reg->GetBitFieldJustified(8,4) && // NCE hard TH
             reg->IsBitSet(34)                     && // pause on MPE
             reg->IsBitSet(35)                     )  // pause on UE
        {
            o_isBgScrub = true;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t isBgScrubConfig<TYPE_MCA>( ExtensibleChip * i_chip,
                                    bool & o_isBgScrub )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );

    return isBgScrubConfig<TYPE_MCBIST>( mcbChip, o_isBgScrub );
}

template<>
uint32_t isBgScrubConfig<TYPE_MBA>( ExtensibleChip * i_chip,
                                    bool & o_isBgScrub )
{
    #define PRDF_FUNC "[isBgScrubConfig] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    o_isBgScrub = false;

    do
    {
        // There really is not a good way of doing this. A scrub command is a
        // scrub command the only difference is the speed. Unfortunately, that
        // speed can change depending on how the hardware team tunes it. For
        // now, we can use the stop conditions, which should be unique for
        // background scrub, to determine if it has been configured.

        // TODO RTC 157888

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF

