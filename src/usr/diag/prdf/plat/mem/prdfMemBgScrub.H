/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemBgScrub.H $                 */
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

/** @file  prdfMemBgScrub.H
 *  @brief Define the functionality necessary to start initial background scrub
 */

#ifndef __prdfMemBgScrub_H
#define __prdfMemBgScrub_H

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>
#include <prdfMemScrubUtils.H>

namespace PRDF
{

/**
 * @brief  Performs all actions necessary to start the background scrubbing on
 *         the first configured address of the given target.
 * @param  i_chip MCBIST, MCA, or MBA.
 * @return SUCCESS when background scrub is started correctly, else Non-SUCCESS.
 */
template<TARGETING::TYPE T>
uint32_t startInitialBgScrub( ExtensibleChip * i_chip )
{
    using namespace TARGETING;

    #define PRDF_FUNC "[startInitialBgScrub] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    // NOTE: It is possible for a chip mark to have been placed between MDIA
    //       and the initial start scrub. Those unverified chip marks will be
    //       found in the runtime TD controller's initialize() function. The
    //       chip marks will then be verified after the initial fast scrub is
    //       complete.

    do
    {
        // Cleanup hardware before starting the maintenance command.
        o_rc = clearCmdCompleteAttn<T>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearCmdCompleteAttn<T>(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        o_rc = clearEccCounters<T>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearEccCounters<T>(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        o_rc = clearEccFirs<T>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearEccFirs<T>(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Get the first configured rank.
        std::vector<MemRank> ranklist;
        PlatServices::getMasterRanks<T>( i_chip->getTrgt(), ranklist );
        PRDF_ASSERT( !ranklist.empty() ); // i_chip configured with no ranks
        MemRank rank = ranklist.front();

        // Start background scrubbing.
        o_rc = PlatServices::startBgScrub<T>( i_chip->getTrgt(), rank );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startBgScrub(0x%08x,%d) failed",
                      i_chip->getHuid(), rank.getMaster() );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

/** @brief Specialization for MCBIST. */
template<>
uint32_t startInitialBgScrub<TARGETING::TYPE_MCBIST>( ExtensibleChip * i_chip )
{
    using namespace TARGETING;

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCBIST == i_chip->getType() );

    // Find the first configured MCA.
    ExtensibleChip * mcaChip = nullptr;
    for ( uint32_t p = 0; p < MAX_PORT_PER_MCBIST; p++ )
    {
        mcaChip = PlatServices::getConnectedChild( i_chip, TYPE_MCA, p );
        if ( nullptr != mcaChip ) break;
    }
    PRDF_ASSERT( nullptr != mcaChip ); // MCBIST configured with no MCAs

    return startInitialBgScrub<TYPE_MCA>( mcaChip );
}

} // end namespace PRDF

#endif // __prdfMemBgScrub_H
