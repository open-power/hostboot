/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/runtime/prdfCenMbaTdRankData.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

/** @file prdfCenMbaTdRankData.C */

#include <prdfCenMbaTdRankData.H>

// Framework includes
#include <prdfTrace.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

int32_t TdRankList::initialize( TargetHandle_t i_mbaTrgt )
{
    #define PRDF_FUNC "[TdRankList::initialize] "

    int32_t o_rc = SUCCESS;

    iv_list.clear();

    do
    {
        // Get the list of master ranks for this MBA.
        std::vector<CenRank> ranks;
        o_rc = getMasterRanks( i_mbaTrgt, ranks );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMasterRanks() failed" );
            break;
        }

        // Make sure the list is not empty for some reason.
        if ( ranks.empty() )
        {
            PRDF_ERR( PRDF_FUNC "getMasterRanks() returned an empty list" );
            o_rc = FAIL; break;
        }

        // Sort the list of ranks.
        std::sort( ranks.begin(), ranks.end() );

        // Initialize iv_list.
        for ( std::vector<CenRank>::iterator it = ranks.begin();
              it != ranks.end(); it++ )
        {
            iv_list.push_back( Entry(*it) );
        }

    } while (0);

    // Initially set iv_curRank to an invalid value.
    iv_curRank = iv_list.end();

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

TdRankList::Entry TdRankList::findNextGoodRank()
{
    if ( iv_list.end() == iv_curRank )
    {
        // It is possible to get a maintenance command complete attention
        // without having an error. A prime example, is the maintenance command
        // complete after the initial fast scrub. In this case, back iv_curRank
        // up to the last rank in the list so that the next good rank will be
        // the first rank in the list.
        iv_curRank--;
    }

    // Only want to iterate the list once, so keep track of where we started.
    const ListItr startItr = iv_curRank;

    do
    {
        // Increment to the next rank and wrap to the beginning if needed.
        iv_curRank++;
        if ( iv_list.end() == iv_curRank )
            iv_curRank = iv_list.begin();

    } while ( !iv_curRank->isGood && (startItr != iv_curRank) );

    return *(iv_curRank);
}

//------------------------------------------------------------------------------

int32_t TdRankList::setInterruptedRank( const CenRank & i_rank )
{
    #define PRDF_FUNC "[TdRankList::setInterruptedRank] "

    int32_t o_rc = SUCCESS;

    ListItr it = findRank( i_rank );
    if ( iv_list.end() == it )
    {
        PRDF_ERR( PRDF_FUNC "findRank() failed: i_rank=%d", i_rank.getMaster() );
        o_rc = FAIL;
    }
    else
    {
        iv_curRank = it;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t TdRankList::setRankStatus( const CenRank & i_rank, bool i_isGood )
{
    #define PRDF_FUNC "[TdRankList::setRankStatus] "

    int32_t o_rc = SUCCESS;

    ListItr it = findRank( i_rank );
    if ( iv_list.end() == it )
    {
        PRDF_ERR( PRDF_FUNC "findRank() failed: i_rank=%d i_isGood=%c",
                  i_rank.getMaster(), i_isGood ? 'T' : 'F' );
        o_rc = FAIL;
    }
    else
    {
        it->isGood = i_isGood;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint8_t VcmRankData::getFalseAlarmCount( const CenRank & i_rank )
{
    uint8_t o_count = 0;

    // Using [] will add an entry to the map if it does not exist. Use find()
    // instead so it won't add a bunch of unused entries.
    std::map<uint8_t, Entry>::iterator it = iv_map.find(getKey(i_rank));
    if ( iv_map.end() != it )
    {
        o_count = (it->second).falseAlarms.getCount();
    }

    return o_count;
}

//------------------------------------------------------------------------------

uint8_t TpsRankData::getFalseAlarmCount( const CenRank & i_rank )
{
    uint8_t o_count = 0;

    // Using [] will add an entry to the map if it does not exist. Use find()
    // instead so it won't add a bunch of unused entries.
    std::map<CenRank, Entry>::iterator it = iv_map.find(i_rank);
    if ( iv_map.end() != it )
    {
        o_count = (it->second).falseAlarms.getCount();
    }

    return o_count;
}

//------------------------------------------------------------------------------

bool TpsRankData::checkCeTypeTh( const CenRank & i_rank )
{
    bool th = false;

    // Using [] will add an entry to the map if it does not exist. Use find()
    // instead so it won't add a bunch of unused entries.
    std::map<CenRank, Entry>::iterator it = iv_map.find( i_rank );
    if ( iv_map.end() != it )
    {
        th = ( 1 <= (it->second).falseAlarms.getCount() );
    }

    return th;
}

//------------------------------------------------------------------------------

bool TpsRankData::isBanned( const CenRank & i_rank,
                            STEP_CODE_DATA_STRUCT & i_sc )
{
    bool isBanned = false;

    // Using [] will add an entry to the map if it does not exist. Use find()
    // instead so it won't add a bunch of unused entries.
    std::map<CenRank, Entry>::iterator it = iv_map.find( i_rank );
    if ( iv_map.end() != it &&
         ( (it->second).isBanned || (it->second).falseAlarms.thReached(i_sc) ) )
    {
        isBanned = true;
    }

    return isBanned;
}

} // end namespace PRDF

