/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemBgScrub.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2023                        */
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
 * @param  i_chip OCMB.
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
        // Get the port we want to start scrub on. Default to port0
        uint8_t port = 0;

        // If port0 doesn't exist, switch to port1
        if (nullptr == PlatServices::getConnectedChild(i_chip->getTrgt(),
            TYPE_MEM_PORT, port))
        {
            port = 1;
            // If port1 also doesn't exist, something's wrong, return FAIL.
            if (nullptr == PlatServices::getConnectedChild(i_chip->getTrgt(),
                TYPE_MEM_PORT, port))
            {
                PRDF_ERR(PRDF_FUNC "No port enabled on 0x%08x",
                         i_chip->getHuid());
                return FAIL;
            }
        }

        // Get the first configured rank.
        std::vector<MemRank> ranklist;
        PlatServices::getMasterRanks<T>( i_chip->getTrgt(), port, ranklist );
        PRDF_ASSERT( !ranklist.empty() ); // i_chip configured with no ranks
        MemRank rank = ranklist.front();

        // Start background scrubbing.
        o_rc = PlatServices::startBgScrub<T>( i_chip, rank, port );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startBgScrub(0x%08x,%d,%d) failed",
                      i_chip->getHuid(), rank.getMaster(), port );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

} // end namespace PRDF

#endif // __prdfMemBgScrub_H
