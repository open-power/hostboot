/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaCeTable.C $   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#include <prdfCenMbaCeTable.H>

#include <algorithm>

// Framwork includes
#include <iipServiceDataCollector.h>
#include <UtilHash.H>

// Pegasus includes
#include <prdfCenMarkstore.H>

using namespace TARGETING;

namespace PRDF
{

using namespace CE_TABLE;

//------------------------------------------------------------------------------

bool CenMbaCeTable::addEntry( const CenAddr & i_addr,
                              const CenSymbol & i_symbol )
{
    bool o_doTps = false;

    TableData data ( i_addr, i_symbol.getDram(), i_symbol.getDramPins(),
                     i_symbol.getPortSlct(), i_symbol.getWiringType() );

    // First, check if the entry already exists. If so, increment its count and
    // move it to the end of the queue.
    CeTable::iterator it = std::find( iv_table.begin(), iv_table.end(), data );
    if ( iv_table.end() != it )
    {
        // Update the count
        data.count = it->count + 1;

        // Update the DRAM pins
        data.dramPins |= it->dramPins;

        // Remove the old entry
        iv_table.erase( it );
    }

    // Add the new entry to the end of the list.
    iv_table.push_back( data );

    // Check the new entry's count for single entry threshold.
    if ( TPS_ENTRY_COUNT_TH <= data.count )
    {
        o_doTps = true;
    }

    // Get number of entries in this table on the same rank as the new entry and
    // threshold if needed.
    if ( !o_doTps ) // no point iterating the table if o_doTps is already true
    {
        CenRank thisRank = data.addr.getRank();
        uint32_t rankCount = 0;
        for ( CeTable::iterator it = iv_table.begin();
              it != iv_table.end(); it++ )
        {
            if ( it->addr.getRank() == thisRank )
                rankCount++;
        }

        if ( TPS_RANK_ENTRY_TH <= rankCount )
            o_doTps = true;
    }

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
        iv_table.pop_front();

    // Do TPS if the table is full.
    if ( MAX_ENTRIES == iv_table.size() )
        o_doTps = true;

    return o_doTps;
}

//------------------------------------------------------------------------------

void CenMbaCeTable::deactivateAll()
{
    for ( CeTable::iterator it = iv_table.begin(); it != iv_table.end(); it++ )
        it->active = false;
}

//------------------------------------------------------------------------------

void CenMbaCeTable::deactivateRank( const CenRank & i_rank )
{
    for ( CeTable::iterator it = iv_table.begin(); it != iv_table.end(); it++ )
    {
        if ( it->addr.getRank() == i_rank )
            it->active = false;
    }
}

//------------------------------------------------------------------------------

void CenMbaCeTable::getMnfgCounts( const CenRank & i_rank,
                                   const CenSymbol & i_symbol,
                                   uint32_t & o_dramCount,
                                   uint32_t & o_hrCount,
                                   uint32_t & o_dimmCount )
{
    o_dramCount = 0; o_hrCount = 0; o_dimmCount = 0;

    const uint32_t dram = i_symbol.getDram();
    const uint32_t ps   = i_symbol.getPortSlct();
    const uint32_t ds   = i_rank.getDimmSlct();

    for ( CeTable::iterator it = iv_table.begin(); it != iv_table.end(); it++ )
    {
        if ( ps != it->portSlct ) continue;

        CenRank itRank = it->addr.getRank();

        if ( ds == itRank.getDimmSlct() )
        {
            o_dimmCount++;

            if ( i_rank == itRank )
            {
                o_hrCount++;

                if ( dram == it->dram )
                    o_dramCount++;
            }
        }
    }
}

//------------------------------------------------------------------------------

void CenMbaCeTable::addCapData( TargetHandle_t i_mbaTrgt, CaptureData & io_cd )
{
    static const size_t sz_word = sizeof(CPU_WORD);

    // Get the maximum capture data size and adjust the size for endianess.
    static const size_t sz_maxData = ((MAX_SIZE+sz_word-1) / sz_word) * sz_word;

    // Initialize to 0.
    uint8_t data[sz_maxData];
    memset( data, 0x00, sz_maxData );

    size_t sz_actData = 0;

    for ( CeTable::iterator it = iv_table.begin(); it != iv_table.end(); it++ )
    {
        uint32_t mrnk = it->addr.getRank().getMaster();            //  3-bit
        uint32_t srnk = it->addr.getRank().getSlave();             //  3-bit
        uint32_t svld = it->addr.getRank().isSlaveValid() ? 1 : 0; //  1-bit
        uint32_t bnk  = it->addr.getBank();                        //  4-bit
        uint32_t row  = it->addr.getRow();                         // 17-bit
        uint32_t col  = it->addr.getCol();                         // 12-bit

        uint8_t row0    = (row & 0x10000) >> 16;
        uint8_t row1_8  = (row & 0x0ff00) >>  8;
        uint8_t row9_16 =  row & 0x000ff;

        uint8_t col0_3  = (col & 0xf00) >> 8;
        uint8_t col4_11 =  col & 0x0ff;

        uint8_t active = it->active ? 1 : 0;

        data[sz_actData  ] = it->count;
        data[sz_actData+1] = it->type << 4;                     // 4 spare bits
        data[sz_actData+2] = (active << 6) | (it->dram & 0x3f); // 1 spare bit
        data[sz_actData+3] = it->dramPins;
        data[sz_actData+4] = (mrnk << 5) | (srnk << 2) | (svld << 1) | row0;
        data[sz_actData+5] = row1_8;
        data[sz_actData+6] = row9_16;
        data[sz_actData+7] = (bnk << 4) | col0_3;
        data[sz_actData+8] = col4_11;

        sz_actData += ENTRY_SIZE;
    }

    if ( 0 != sz_actData )
    {
        // Fix endianess issues with non PPC machines.
        sz_actData = ((sz_actData + sz_word-1) / sz_word) * sz_word;
        for ( uint32_t i = 0; i < (sz_actData/sz_word); i++ )
            ((CPU_WORD*)data)[i] = htonl(((CPU_WORD*)data)[i]);

        // Add data to capture data.
        BIT_STRING_ADDRESS_CLASS bs ( 0, sz_actData*8, (CPU_WORD *) &data );
        io_cd.Add( i_mbaTrgt, Util::hashString("MEM_CE_TABLE"), bs );
    }
}

} // end namespace PRDF

