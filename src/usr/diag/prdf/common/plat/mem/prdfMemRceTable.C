/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemRceTable.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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

#include <prdfMemRceTable.H>

// Framwork includes
#include <iipServiceDataCollector.h>
#include <UtilHash.H>
#include <prdfParserEnums.H>

// Platform includes
#include <prdfMemThresholds.H>

using namespace TARGETING;

namespace PRDF
{

using namespace RCE_TABLE;

//------------------------------------------------------------------------------

bool MemRceTable::addEntry( const MemRank & i_rank,
                            STEP_CODE_DATA_STRUCT & i_sc, uint8_t i_count )
{
    bool o_doTps = false;

    RceTable::iterator it = iv_table.find( i_rank );
    if ( iv_table.end() == it )
    {
        TimeBasedThreshold entry( getRceThreshold() );

        // Add a new rank entry to the table and get the iterator.
        it = iv_table.insert( std::make_pair(i_rank, entry) ).first;
    }

    o_doTps = it->second.inc( i_sc, i_count );

    return o_doTps;
}

//------------------------------------------------------------------------------

void MemRceTable::flushEntry( const MemRank & i_rank )
{
    RceTable::iterator it = iv_table.find( i_rank );
    if ( iv_table.end() != it )
        it->second.reset();
}
//------------------------------------------------------------------------------

void MemRceTable::addCapData( CaptureData & io_cd )
{
    static const size_t sz_word = sizeof(CPU_WORD);
    static const size_t sz_entryCnt = sizeof( uint8_t ); // entry count

    // Get the maximum capture data size and adjust the size for endianness.
    const size_t sz_maxData = ((( iv_table.size() * ENTRY_SIZE  + sz_entryCnt )+
                                            sz_word-1) / sz_word) * sz_word;

    // Initialize to 0.
    uint8_t data[sz_maxData];
    memset( data, 0x00, sz_maxData );

    // reserve first index for total entries
    size_t sz_actData = sz_entryCnt;

    for ( RceTable::iterator it = iv_table.begin(); it != iv_table.end(); it++ )
    {
        // skip if there is no RCE count
        if ( 0 == it->second.getCount() )
        {
            continue;
        }
        uint32_t mrnk = it->first.getMaster();            //  3-bit
        uint32_t srnk = it->first.getSlave();             //  3-bit

        data[sz_actData] = (mrnk << 5) | (srnk << 2);
        uint32_t count = it->second.getCount();
        data[sz_actData + 1] = ( count > 255 ) ? 255 : count;
        sz_actData += ENTRY_SIZE;
    }

    if ( 1 != sz_actData )
    {
        data[0] = sz_actData / ENTRY_SIZE;
        // Fix endianness issues with non PPC machines.
        sz_actData = ((sz_actData + sz_word-1) / sz_word) * sz_word;
        for ( uint32_t i = 0; i < (sz_actData/sz_word); i++ )
            ((CPU_WORD*)data)[i] = htonl(((CPU_WORD*)data)[i]);

        // Add data to capture data.
        BitString bs ( sz_actData*8, (CPU_WORD *) &data );
        io_cd.Add( iv_chip->getTrgt(), Util::hashString("MEM_RCE_TABLE"), bs );
    }
}

} // end namespace PRDF

