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
 * @brief Performs all actions necessary to start the background scrub
 * @param mcbChip The mcbist chip
 * @return SUCCESS when background scrub is started correctly, else Non-SUCCESS
 */
template<TARGETING::TYPE T>
int32_t startInitialBgScrub(ExtensibleChip* chip)
{
    #define PRDF_FUNC "[PRDF::startInitialBgScrub] "

    int32_t o_rc = SUCCESS;

    // NOTE: It is possible for a chip mark to have been placed between MDIA
    //       and the initial start scrub. Those unverified chip marks will be
    //       found in the runtime TD controller's initialize() function. The
    //       chip marks will then be verified after the initial fast scrub is
    //       complete.

    do
    {
        // Cleanup hardware before starting the maintenance command.
        o_rc = clearCmdCompleteAttn<T>(chip);
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearCmdCompleteAttn failed" );
            break;
        }

        o_rc = clearEccCounters<T>(chip);
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearEccCounters failed" );
            break;
        }

        o_rc = clearEccFirs<T>(chip);
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearEccFirs failed" );
            break;
        }

        TARGETING::TargetHandle_t trgt = chip->GetChipHandle();

        // We can use the default constructor for MemRank to start rank 0
        MemRank rank;

        o_rc = PlatServices::startBgScrub<T>(trgt, rank, 0);

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "chip:0x%08x", chip->GetId() );

        int32_t l_rc = clearCmdCompleteAttn<T>(chip); // Just in case.
        if ( SUCCESS != l_rc )
            PRDF_ERR( PRDF_FUNC "clearCmdCompleteAttn() failed" );
    }
    return o_rc;

    #undef PRDF_FUNC
}

} //end namespace PRDF

#endif // __prdfMemBgScrub_H
