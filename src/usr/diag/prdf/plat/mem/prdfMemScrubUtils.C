/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemScrubUtils.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
    PRDF_ASSERT( T == i_chip->getTrgtType() );

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
    PRDF_ASSERT( TYPE_MCA == i_chip->getTrgtType() );

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
    PRDF_ASSERT( T == i_chip->getTrgtType() );

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
    PRDF_ASSERT( TYPE_MCA == i_chip->getTrgtType() );

    ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );

    return clearEccCounters<TYPE_MCBIST>( mcbChip );
}

template<>
uint32_t clearEccCounters<TYPE_MBA>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getTrgtType() );

    ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );

    uint32_t pos = getTargetPosition( i_chip->getTrgt() );
    const char * reg = (0 == pos) ? "MBA0_MBSTR" : "MBA1_MBSTR";

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

        for ( uint32_t p = 0; p < MAX_PORT_PER_MCBIST; p++ )
        {
            ExtensibleChip * mcaChip = getConnectedChild( i_chip, TYPE_MCA, p );
            if ( nullptr == mcaChip ) continue;

            // Clear MCAECCFIR[20:34,36:37,39]
            o_rc = __clearFir<TYPE_MCA>( mcaChip, "MCAECCFIR_AND",
                                         0xfffff00012ffffffull );
            if ( SUCCESS != o_rc ) break;
        }

    } while(0);

    return o_rc;
}

template<>
uint32_t clearEccFirs<TYPE_MCA>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getTrgtType() );

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

        uint32_t pos = getTargetPosition( i_chip->getTrgt() );
        const char * reg = (0 == pos) ? "MBA0_MBSECCFIR_AND"
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

} // end namespace PRDF

