/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemCeTable.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
using namespace CE_TABLE;

//------------------------------------------------------------------------------

uint32_t MemCeTable::addEntry( const MemAddr & i_addr,
                               const MemSymbol & i_symbol, bool i_isHard )
{
    uint32_t o_rc = NO_TH_REACHED;

    TableData data ( i_addr, i_symbol.getDram(), i_symbol.getDramPins(),
                     i_symbol.getPortSlct(), i_isHard, i_symbol.isDramSpared(),
                     i_symbol.isEccSpared() );

    // First, check if the entry already exists. If so, increment its count and
    // move it to the end of the queue.
    CeTable::iterator it = std::find( iv_table.begin(), iv_table.end(), data );
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
    for ( CeTable::iterator it = iv_table.begin(); it != iv_table.end(); it++ )
    {
        if ( it->active && (it->addr.getRank() == thisRank) )
            rankCount++;
    }

    if ( TPS_RANK_ENTRY_TH <= rankCount )
        o_rc |= RANK_TH_REACHED;

    // Note that we intentially checked the entries-per-rank threshold before
    // removing any entries, if the table is full. This is to catch the corner
    // case where the oldest entry is on the same rank as the new entry.

    // If the table is full, remove the oldest inactive entry
    if ( MAX_ENTRIES < iv_table.size() )
    {
        for ( CeTable::iterator it = iv_table.begin();
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

void MemCeTable::deactivateRank( const MemRank & i_rank )
{
    // NOTE: We don't want to reset the count here because it will be used for
    //       FFDC. Instead the count will be reset in addEntry() if the entry is
    //       not active.
    for ( CeTable::iterator it = iv_table.begin(); it != iv_table.end(); it++ )
    {
        if ( it->addr.getRank() == i_rank )
            it->active = false;
    }
}

//------------------------------------------------------------------------------

void MemCeTable::getMnfgCounts( const MemRank & i_rank,
                                const MemSymbol & i_symbol,
                                uint32_t & o_dramCount,
                                uint32_t & o_rankCount,
                                uint32_t & o_dimmCount )
{
    o_dramCount = 0; o_rankCount = 0; o_dimmCount = 0;

    const uint32_t dram = i_symbol.getDram();
    const uint32_t ps   = i_symbol.getPortSlct();
    const uint32_t ds   = i_rank.getDimmSlct();

    for ( CeTable::iterator it = iv_table.begin(); it != iv_table.end(); it++ )
    {
        if ( ps != it->portSlct ) continue;

        MemRank itRank = it->addr.getRank();

        if ( ds == itRank.getDimmSlct() )
        {
            o_dimmCount++;

            if ( i_rank == itRank )
            {
                o_rankCount++;

                if ( dram == it->dram )
                    o_dramCount++;
            }
        }
    }
}

//------------------------------------------------------------------------------

void MemCeTable::addCapData( ExtensibleChip * i_chip, CaptureData & io_cd )
{
    static const size_t sz_word = sizeof(CPU_WORD);

    // Get the maximum capture data size and adjust the size for endianness.
    static const size_t sz_maxData = ((MAX_SIZE+sz_word-1) / sz_word) * sz_word;

    // Initialize to 0.
    uint8_t data[sz_maxData];
    memset( data, 0x00, sz_maxData );

    size_t sz_actData = 0;

    // Centaur specific info.
    uint8_t isMba  = 0;
    uint8_t mbaPos = 0;
    uint8_t rcType = CEN_SYMBOL::WIRING_INVALID;
    if ( TYPE_MBA == i_chip->getType() )
    {
        isMba  = 1;
        mbaPos = getTargetPosition( i_chip->getTrgt() );

        /* TODO: RTC 157888
        if ( SUCCESS != getMemBufRawCardType(i_chip->getTrgt(), rcType) )
        {
            PRDF_ERR( "[MemCeTable::addCapData] getMemBufRawCardType(0x%08x) "
                      "failed", i_chip->getHuid() );
            rcType = CEN_SYMBOL::WIRING_INVALID; // Just in case.
        }
        */
    }

    // Fill in the header info.
    data[0] = (isMba << 7) | (mbaPos << 6); // 6 spare bits
    data[1] = rcType;
    // Bytes 2-7 are currently unused.

    sz_actData += METADATA_SIZE;

    // Fill in the entry info.
    for ( CeTable::iterator it = iv_table.begin(); it != iv_table.end(); it++ )
    {
        uint32_t mrnk = it->addr.getRank().getMaster(); //  3-bit
        uint32_t srnk = it->addr.getRank().getSlave();  //  3-bit
        uint32_t bnk  = it->addr.getBank();             //  5-bit (MCA)
        uint32_t row  = it->addr.getRow();              // 18-bit
        uint32_t col  = it->addr.getCol();              //  9-bit (MBA)

        uint8_t row0_1   = (row & 0x30000) >> 16;
        uint8_t row2_9   = (row & 0x0ff00) >>  8;
        uint8_t row10_17 =  row & 0x000ff;

        uint8_t col0     = (col & 0x100) >> 8;
        uint8_t col1_8   =  col & 0x0ff;

        uint8_t active = it->active ? 1 : 0;
        uint8_t isHard = it->isHard ? 1 : 0;
        uint8_t isSp   = it->isDramSpared ? 1 : 0;
        uint8_t isEcc  = it->isEccSpared  ? 1 : 0;

        data[sz_actData  ] = it->count;
        data[sz_actData+1] = // 5 bits spare here.
                             (isSp << 2) | (isEcc << 1) | it->portSlct;
        data[sz_actData+2] = (isHard << 7) | (active << 6) | (it->dram & 0x3f);
        data[sz_actData+3] = it->dramPins;
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
        BIT_STRING_ADDRESS_CLASS bs ( 0, sz_actData*8, (CPU_WORD *) &data );
        io_cd.Add( i_chip->getTrgt(), Util::hashString("MEM_CE_TABLE"), bs );
    }
}

} // end namespace PRDF

