/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemScrubUtils.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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

// HWP includes
#include <lib/shared/nimbus_defaults.H>
#include <lib/mcbist/memdiags.H>

// Framework includes
#include <prdfMemScrubUtils.H>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>
#include <fapi2.H>
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
uint32_t clearCmdCompleteAttn<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip )
{
    // Clear MCBISTFIR[10].
    return __clearFir<TYPE_OCMB_CHIP>( i_chip, "MCBISTFIR_AND",
                                       0xffdfffffffffffffull );
}

template<>
uint32_t clearCmdCompleteAttn<TYPE_MEM_PORT>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEM_PORT == i_chip->getType() );

    ExtensibleChip * ocmbChip = getConnectedParent( i_chip, TYPE_OCMB_CHIP );

    return clearCmdCompleteAttn<TYPE_OCMB_CHIP>( ocmbChip );
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
uint32_t clearEccCounters<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip )
{
    return __clearEccCounters<TYPE_OCMB_CHIP>( i_chip, "MCB_CNTL", 7 );
}

template<>
uint32_t clearEccCounters<TYPE_MEM_PORT>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEM_PORT == i_chip->getType() );

    ExtensibleChip * ocmbChip = getConnectedParent( i_chip, TYPE_OCMB_CHIP );

    return clearEccCounters<TYPE_OCMB_CHIP>( ocmbChip );
}

template<>
uint32_t clearEccCounters<TYPE_MBA>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );

    const char * reg = (0 == i_chip->getPos()) ? "MBSTR_0" : "MBSTR_1";

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

template<>
uint32_t clearEccFirs<TYPE_MEM_PORT>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEM_PORT == i_chip->getType() );

    ExtensibleChip * ocmbChip = getConnectedParent( i_chip, TYPE_OCMB_CHIP );

    return clearEccFirs<TYPE_OCMB_CHIP>( ocmbChip );
}

template<>
uint32_t clearEccFirs<TYPE_MBA>( ExtensibleChip * i_chip )
{
    uint32_t o_rc = SUCCESS;

    do
    {
        ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );

        const char * reg = (0 == i_chip->getPos()) ? "MBSECCFIR_0_AND"
                                                   : "MBSECCFIR_1_AND";

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

        if ( mcaeccfir->IsBitSet(28) ) o_eccAttns |= MAINT_NCE;
        if ( mcaeccfir->IsBitSet(29) ) o_eccAttns |= MAINT_TCE;
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
uint32_t checkEccFirs<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                       uint32_t & o_eccAttns )
{
    #define PRDF_FUNC "[checkEccFirs<TYPE_MEM_PORT>] "

    uint32_t o_rc = SUCCESS;

    o_eccAttns = MAINT_NO_ERROR;

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEM_PORT == i_chip->getType() );

    SCAN_COMM_REGISTER_CLASS * rdffir    = i_chip->getRegister( "RDFFIR" );
    SCAN_COMM_REGISTER_CLASS * mcbistfir = i_chip->getRegister( "MCBISTFIR" );

    do
    {
        o_rc = rdffir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCAECCFIR: i_chip=0x%08x",
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

    const char * reg = (0 == i_chip->getPos()) ? "MBSECCFIR_0" : "MBSECCFIR_1";

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

        if ( mbseccfir->IsBitSet(36) ) o_eccAttns |= MAINT_NCE;
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
uint32_t conditionallyClearEccCounters<TYPE_MBA>( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[conditionallyClearEccCounters] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // Check for maintenance ECC errors.
        uint32_t eccAttns = 0;
        o_rc = checkEccFirs<TYPE_MBA>( i_chip, eccAttns );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccFirs<TYPE_MBA>(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );
        uint8_t mbaPos = i_chip->getPos();

        const char * ec0Reg_str = (0 == mbaPos) ? "MBA0_MBSEC0" : "MBA1_MBSEC0";
        SCAN_COMM_REGISTER_CLASS * ec0Reg = membChip->getRegister( ec0Reg_str );
        o_rc = ec0Reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s", ec0Reg_str );
            break;
        }

        const char * mbstr_str = (0 == mbaPos) ? "MBSTR_0" : "MBSTR_1";
        SCAN_COMM_REGISTER_CLASS * mbstr = membChip->getRegister( mbstr_str );
        o_rc = mbstr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s", mbstr_str );
            break;
        }

        bool updateEc0     = false;
        bool clearSymCntrs = false;

        if ( eccAttns & MAINT_SOFT_NCE_ETE )
        {
            // Clear Soft CE total count.
            ec0Reg->SetBitFieldJustified( 0, 12, 0 );
            updateEc0 = true;

            if ( mbstr->IsBitSet(55) ) clearSymCntrs = true;
        }

        if ( eccAttns & MAINT_INT_NCE_ETE )
        {
            // Clear Intermittent CE total count.
            ec0Reg->SetBitFieldJustified( 12, 12, 0 );
            updateEc0 = true;

            if ( mbstr->IsBitSet(56) ) clearSymCntrs = true;
        }

        if ( eccAttns & MAINT_HARD_NCE_ETE )
        {
            // Clear the hard CE total count.
            ec0Reg->SetBitFieldJustified( 24, 12, 0 );
            updateEc0 = true;

            if ( mbstr->IsBitSet(57) ) clearSymCntrs = true;
        }

        if ( updateEc0 )
        {
            o_rc = ec0Reg->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on %s", ec0Reg_str );
                break;
            }
        }

        if ( clearSymCntrs )
        {
            // Clear all of the per symbol counters. Note that there are a total
            // of 9 MBSSYMECx registers (MBSSYMEC0-MBSSYMEC8) per MBA.
            for ( uint8_t i = 0; i < 9; i++ )
            {
                char reg_str[20];
                snprintf( reg_str, 20, "MBA%d_MBSSYMEC%d", mbaPos, i );

                SCAN_COMM_REGISTER_CLASS * reg = membChip->getRegister(reg_str);

                reg->clearAllBits();

                o_rc = reg->Write();
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "Write() failed on %s", reg_str );
                    break;
                }
            }
            if ( SUCCESS != o_rc ) break;
        }

        if ( eccAttns & MAINT_RCE_ETE )
        {
            // Clear only the RCE total count.
            const char * ec1Reg_str =
                            (0 == mbaPos) ? "MBA0_MBSEC1" : "MBA1_MBSEC1";
            SCAN_COMM_REGISTER_CLASS * ec1Reg =
                            membChip->getRegister( ec1Reg_str );

            o_rc = ec1Reg->Read();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Read() failed on %s", ec1Reg_str );
                break;
            }

            ec1Reg->SetBitFieldJustified( 0, 12, 0 );

            o_rc = ec1Reg->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on %s", ec1Reg_str );
                break;
            }
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t setBgScrubThresholds<TYPE_MBA>( ExtensibleChip * i_chip,
                                         const MemRank & i_rank )
{
    #define PRDF_FUNC "[setBgScrubThresholds] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );
        const char * reg_str = (0 == i_chip->getPos()) ? "MBSTR_0" : "MBSTR_1";
        SCAN_COMM_REGISTER_CLASS * mbstr = membChip->getRegister( reg_str );
        o_rc = mbstr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s", reg_str );
            break;
        }

        uint32_t softIntCe = getScrubCeThreshold<TYPE_MBA>( i_chip, i_rank );

        // Only care about retry CEs if there are a lot of them. So the
        // threshold will be high in the field. However, in MNFG the retry CEs
        // will be handled differently by putting every occurrence in the RCE
        // table and doing targeted diagnostics when needed.
        uint16_t retryCe = mfgMode() ? 1 : 2047;

        uint16_t hardCe = 1; // Always stop on first occurrence.

        mbstr->SetBitFieldJustified(  4, 12, softIntCe );
        mbstr->SetBitFieldJustified( 16, 12, softIntCe );
        mbstr->SetBitFieldJustified( 28, 12, hardCe    );
        mbstr->SetBitFieldJustified( 40, 12, retryCe   );

        // Set the per symbol counters to count hard CEs only. This is so that
        // when the scrub stops on the first hard CE, we can use the per symbol
        // counters to tell us which symbol reported the hard CE.
        mbstr->SetBitFieldJustified( 55, 3, 0x1 );

        o_rc = mbstr->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s", reg_str );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t didCmdStopOnLastAddr<TYPE_MBA>( ExtensibleChip * i_chip,
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
        o_rc = getMemMaintAddr<TYPE_MBA>( i_chip, curAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Get the end address of the current rank.
        MemAddr junk, endAddr;
        o_rc = getMemAddrRange<TYPE_MBA>( i_chip, curAddr.getRank(), junk,
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

//------------------------------------------------------------------------------

} // end namespace PRDF

