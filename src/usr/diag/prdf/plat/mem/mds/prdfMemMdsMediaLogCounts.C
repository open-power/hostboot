/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/mds/prdfMemMdsMediaLogCounts.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#include <prdfExtensibleChip.H>
#include <prdfMemMdsMediaLogCounts.H>
#include <prdfMemMdsUtils.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace MDS
{

//------------------------------------------------------------------------------

uint32_t MediaLogCounts::updateCounts( const MemRank & i_rank )
{
    #define PRDF_FUNC "[MediaLogCounts::updateCounts] "

    uint32_t o_rc = SUCCESS;

    // Get the primary and secondary rank
    uint8_t prank = i_rank.getRankSlct();
    uint8_t srank = i_rank.getSlave();

    // Read the UE and non-UE counts from the media error logs
    uint8_t ueCount = 0;
    uint8_t nonUeCount = 0;

    o_rc = readMediaErrLogErrCount( iv_ocmb, ueCount, nonUeCount );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "readMediaErrLogErrCount(0x%08x) failed.",
                  iv_ocmb->getHuid() );
    }
    else
    {
        // If the read was successful, update iv_errMap's counts
        iv_errMap[prank][srank].ueCount += ueCount;
        iv_errMap[prank][srank].nonUeCount += nonUeCount;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

bool MediaLogCounts::checkPrankCount( uint8_t & o_prank, uint8_t i_th )
{
    #define PRDF_FUNC "[MediaLogCounts::checkPrankCount] "

    bool thresholdHit = false;

    o_prank = 0xff;

    // Loop through each primary rank in iv_errMap
    for ( const auto & prankMap : iv_errMap )
    {
        uint32_t prankErrCount = 0;

        // Loop through each secondary rank for each primary rank
        for ( const auto & srankMap : prankMap.second )
        {
            prankErrCount += srankMap.second.ueCount;
            prankErrCount += srankMap.second.nonUeCount;
        }

        // Check if this primary rank has hit threshold
        if ( prankErrCount >= i_th )
        {
            thresholdHit = true;
            o_prank = prankMap.first;
            break;
        }
    }

    return thresholdHit;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

bool MediaLogCounts::checkSrankCount( uint8_t i_prank, uint8_t & o_srank,
                                      uint8_t i_th )
{
    #define PRDF_FUNC "[MediaLogCounts::checkSrankCount] "

    bool blameSrank = false;
    o_srank = 0xff;

    // We can classify the errors as a single bad srank if one of the sranks
    // has a count equal or greater than the threshold (default 8) while the
    // remaining sranks each have a count of 1 or less.

    // Loop through each secondary rank for the input primary rank
    for ( const auto & srankMap : iv_errMap[i_prank] )
    {
        uint32_t count = srankMap.second.ueCount + srankMap.second.nonUeCount;

        // Check if this srank has a count that hit threshold
        if ( count >= i_th )
        {
            // Save the srank we can potentially blame
            o_srank = srankMap.first;
            blameSrank = true;
        }
        // Check if this srank has a count of 2 or more
        else if ( count >= 2 )
        {
            // Since we have an srank with a count between 2 and the threshold,
            // we won't be able to blame a single srank.
            o_srank = 0xff;
            blameSrank = false;
            break;
        }
    }

    return blameSrank;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void MediaLogCounts::captureMediaLogCounts( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MediaLogCounts::captureMediaLogCounts] "

    // TODO RTC 294645 - This will need to be updated to properly capture the
    // FFDC information here and add it to the error log. For now, just trace
    // out the infromation.
    for ( const auto & prankMap : iv_errMap )
    {
        for ( const auto & srankMap : prankMap.second )
        {
            PRDF_TRAC( PRDF_FUNC "FFDC for media errors: huid=0x%08x, "
                       "primary rank=%d, secondary rank=%d, UE count=%d, "
                       "non-UE count=%d", iv_ocmb->getHuid(), prankMap.first,
                       srankMap.first, srankMap.second.ueCount,
                       srankMap.second.nonUeCount );
        }
    }

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace MDS

} // end namespace PRDF
