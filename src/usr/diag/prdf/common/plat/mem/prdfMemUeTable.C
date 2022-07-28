/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemUeTable.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
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

#include <prdfMemUeTable.H>

#include <algorithm>

// Framework includes
#include <iipServiceDataCollector.h>
#include <UtilHash.H>

using namespace TARGETING;

namespace PRDF
{

using namespace UE_TABLE;

//------------------------------------------------------------------------------

void MemUeTable::addEntry( UE_TABLE::Type i_type, const MemAddr & i_addr )
{
    // Create the new entry.
    UeTableData data ( i_type, i_addr );

    // First, check if the entry already exists. If so, increment its count and
    // move it to the end of the queue.
    UeTable::iterator it = std::find( iv_table.begin(), iv_table.end(), data );
    if ( iv_table.end() != it )
    {
        // Update the count
        data.count = it->count;
        if ( MAX_ENTRY_COUNT > data.count )
            data.count++;

        // Remove the old entry
        iv_table.erase( it );
    }

    // Add the new entry to the end of the list.
    iv_table.push_back( data );

    // Pop off the oldest entry if the table is full.
    if ( MAX_ENTRIES < iv_table.size() )
        iv_table.pop_front();
}

//------------------------------------------------------------------------------

void MemUeTable::addCapData( CaptureData & io_cd )
{
    if ( iv_table.empty() ) return; // Table is empty. Do nothing.

    static const size_t sz_word = sizeof(CPU_WORD);

    // Get the maximum capture data size and adjust the size for endianness.
    static const size_t sz_maxData = ((MAX_SIZE+sz_word-1) / sz_word) * sz_word;

    // Initialize to 0.
    uint8_t data[sz_maxData];
    memset( data, 0x00, sz_maxData );

    size_t sz_actData = 0;

    for ( UeTable::iterator it = iv_table.begin(); it != iv_table.end(); it++ )
    {
        uint32_t mrnk = it->addr.getRank().getMaster(); //  3-bit
        uint32_t srnk = it->addr.getRank().getSlave();  //  3-bit
        uint32_t bnk  = it->addr.getBank();             //  5-bit
        uint32_t row  = it->addr.getRow();              // 18-bit
        uint32_t col  = it->addr.getCol();              //  9-bit

        uint8_t row0_1   = (row & 0x30000) >> 16;
        uint8_t row2_9   = (row & 0x0ff00) >>  8;
        uint8_t row10_17 =  row & 0x000ff;

        uint8_t col0     = (col & 0x100) >> 8;
        uint8_t col1_8   =  col & 0x0ff;

        data[sz_actData  ] = it->count;
        data[sz_actData+1] = it->type << 4; // 4 bits to spare.
        data[sz_actData+2] = (mrnk << 5) | (srnk << 2) | row0_1;
        data[sz_actData+3] = row2_9;
        data[sz_actData+4] = row10_17;
        data[sz_actData+5] = (bnk << 3) | col0; // 2 bits to spare in between.
        data[sz_actData+6] = col1_8;

        sz_actData += ENTRY_SIZE;
    }

    if ( 0 != sz_actData )
    {
        // Fix endianness issues with non PPC machines.
        sz_actData = ((sz_actData + sz_word-1) / sz_word) * sz_word;
        for ( uint32_t i = 0; i < (sz_actData/sz_word); i++ )
            ((CPU_WORD*)data)[i] = htobe32(((CPU_WORD*)data)[i]);

        // Add data to capture data.
        BitString bs ( sz_actData*8, (CPU_WORD *) &data );
        io_cd.Add( iv_chip->getTrgt(), Util::hashString("MEM_UE_TABLE"), bs );
    }
}

} // end namespace PRDF

