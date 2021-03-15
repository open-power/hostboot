/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemCeTable.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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

#include <prdfMemCeTable.H>

#include <algorithm>

// Framwork includes
#include <iipServiceDataCollector.h>
#include <UtilHash.H>

// Platform includes
#include <prdfMemThresholds.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
using namespace CE_TABLE;

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemCeTable<T>::addEntry( const MemAddr & i_addr,
                                  const MemSymbol & i_symbol, bool i_isHard )
{
    uint32_t o_rc = NO_TH_REACHED;

    TableData data (i_addr, i_symbol.getDram(), i_symbol.getDramPins(),
                    i_symbol.getPortSlct(), i_isHard, i_symbol.isDramSpared());

    // First, check if the entry already exists. If so, increment its count and
    // move it to the end of the queue.
    typename CeTable::iterator it = std::find( iv_table.begin(), iv_table.end(),
                                               data );
    if ( iv_table.end() != it )
    {
        // Update the count only if the entry is active. Otherwise, use the
        // reset count from the contructor.
        if ( it->active )
            data.count = it->count + 1;

        // Update the DRAM pins
        data.dramPins |= it->dramPins;

        // Check the hard CE status
        if ( it->isHard ) data.isHard = true;

        // Remove the old entry
        iv_table.erase( it );
    }

    // Add the new entry to the end of the list.
    iv_table.push_back( data );

    // Check the new entry's count for single entry threshold.
    if ( TPS_ENTRY_COUNT_TH <= data.count )
    {
        o_rc |= ENTRY_TH_REACHED;
    }

    // Get number of entries in this table on the same rank as the new entry and
    // threshold if needed.
    MemRank thisRank = data.addr.getRank();
    uint32_t rankCount = 0;
    for ( auto & entry : iv_table )
    {
        if ( entry.active && (entry.addr.getRank() == thisRank) )
            rankCount++;
    }

    if ( TPS_RANK_ENTRY_TH <= rankCount )
        o_rc |= RANK_TH_REACHED;

    // Note that we intentially checked the entries-per-rank threshold before
    // removing any entries, if the table is full. This is to catch the corner
    // case where the oldest entry is on the same rank as the new entry.

    // Check MNFG thresholds, if needed.
    if ( mfgMode() )
    {
        // Get the MNFG CE thresholds.
        uint32_t dramTh, rankTh, dimmTh;
        getMnfgMemCeTh<T>( iv_chip, thisRank, dramTh, rankTh, dimmTh );

        // The returned values are the number allowed. Add 1 to get threshold.
        dramTh++; rankTh++; dimmTh++;

        // Get MNFG counts from CE table.
        uint32_t dramCount = 0, rankCount = 0, dimmCount = 0;
        for ( auto & entry : iv_table )
        {
            if ( i_symbol.getPortSlct() != entry.portSlct ) continue;

            MemRank itRank = entry.addr.getRank();

            if ( thisRank.getDimmSlct() == itRank.getDimmSlct() )
            {
                dimmCount++;

                if ( thisRank == itRank )
                {
                    rankCount++;

                    if ( i_symbol.getDram() == entry.dram )
                        dramCount++;
                }
            }
        }

        // Check thresholds. Note that the thresholds are the number allowed.
        // So we have to compare if the counts have exceeded the thresholds.
        if ( dramTh <= dramCount ) o_rc |= MNFG_TH_DRAM;
        if ( rankTh <= rankCount ) o_rc |= MNFG_TH_RANK;
        if ( dimmTh <= dimmCount ) o_rc |= MNFG_TH_DIMM;

        PRDF_INF( "MNFG CEs per DRAM TH=%d, count=%d", dramTh, dramCount );
        PRDF_INF( "MNFG CEs per rank TH=%d, count=%d", rankTh, rankCount );
        PRDF_INF( "MNFG CEs per DIMM TH=%d, count=%d", dimmTh, dimmCount );
    }

    // If the table is full, remove the oldest inactive entry
    if ( MAX_ENTRIES < iv_table.size() )
    {
        for ( typename CeTable::iterator it = iv_table.begin();
              it != iv_table.end(); it++ )
        {
            if ( !it->active )
            {
                iv_table.erase( it );
                break;
            }
        }
    }

    // If the table is still full, all entries are active. Pop off the oldest
    // active entry.
    if ( MAX_ENTRIES < iv_table.size() )
    {
        iv_table.pop_front();

        // The table is full of active entries so do TPS.
        o_rc |= TABLE_FULL;
    }

    return o_rc;
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
void MemCeTable<T>::deactivateRank( const MemRank & i_rank,
                                    AddrRangeType i_type )
{
    // NOTE: We don't want to reset the count here because it will be used for
    //       FFDC. Instead the count will be reset in addEntry() if the entry is
    //       not active.
    for ( auto & entry : iv_table )
    {
        if ( ( (SLAVE_RANK  == i_type) && (entry.addr.getRank() == i_rank) ) ||
             ( (MASTER_RANK == i_type) &&
               (entry.addr.getRank().getMaster() == i_rank.getMaster()) ) )
        {
            entry.active = false;
        }
    }
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
void MemCeTable<T>::addCapData( CaptureData & io_cd )
{
    if ( iv_table.empty() ) return; // Table is empty. Do nothing.

    static const size_t sz_word = sizeof(CPU_WORD);

    // Get the maximum capture data size and adjust the size for endianness.
    static const size_t sz_maxData = ((MAX_SIZE+sz_word-1) / sz_word) * sz_word;

    // Initialize to 0.
    uint8_t data[sz_maxData];
    memset( data, 0x00, sz_maxData );

    size_t sz_actData = 0;

    // Fill in the header info.
    // Bytes 0-7 are currently unused.

    sz_actData += METADATA_SIZE;

    // Fill in the entry info.
    for ( auto & entry : iv_table )
    {
        uint32_t mrnk = entry.addr.getRank().getMaster(); //  3-bit
        uint32_t srnk = entry.addr.getRank().getSlave();  //  3-bit
        uint32_t bnk  = entry.addr.getBank();             //  5-bit
        uint32_t row  = entry.addr.getRow();              // 18-bit
        uint32_t col  = entry.addr.getCol();              //  9-bit

        uint8_t row0_1   = (row & 0x30000) >> 16;
        uint8_t row2_9   = (row & 0x0ff00) >>  8;
        uint8_t row10_17 =  row & 0x000ff;

        uint8_t col0     = (col & 0x100) >> 8;
        uint8_t col1_8   =  col & 0x0ff;

        uint8_t active = entry.active ? 1 : 0;
        uint8_t isHard = entry.isHard ? 1 : 0;
        uint8_t isSp   = entry.isDramSpared ? 1 : 0;

        data[sz_actData  ] = entry.count;
        data[sz_actData+1] = // 5 bits spare here.
                             (isSp << 2); // 2 bits spare at end.
        data[sz_actData+2] = (isHard << 7) | (active << 6) |
                             (entry.dram & 0x3f);
        data[sz_actData+3] = entry.dramPins;
        data[sz_actData+4] = (mrnk << 5) | (srnk << 2) | row0_1;
        data[sz_actData+5] = row2_9;
        data[sz_actData+6] = row10_17;
        data[sz_actData+7] = (bnk << 3) | col0; // 2 bits to spare in between.
        data[sz_actData+8] = col1_8;

        sz_actData += ENTRY_SIZE;
    }

    if ( 0 != sz_actData )
    {
        // Fix endianness issues with non PPC machines.
        sz_actData = ((sz_actData + sz_word-1) / sz_word) * sz_word;
        for ( uint32_t i = 0; i < (sz_actData/sz_word); i++ )
            ((CPU_WORD*)data)[i] = htonl(((CPU_WORD*)data)[i]);

        // Add data to capture data.
        BitString bs ( sz_actData*8, (CPU_WORD *) &data );
        io_cd.Add( iv_chip->getTrgt(), Util::hashString("MEM_CE_TABLE"), bs );
    }
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemCeTable<TYPE_OCMB_CHIP>;

//------------------------------------------------------------------------------

} // end namespace PRDF

