/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaRceTable.C $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

#include <prdfCenMbaRceTable.H>

// Framwork includes
#include <iipServiceDataCollector.h>
#include <UtilHash.H>
#include <prdfParserEnums.H>

// Pegasus includes
#include <prdfCenMbaThresholds.H>
#include <prdfCenAddress.H>

using namespace TARGETING;

namespace PRDF
{

using namespace RCE_TABLE;
using namespace LineDelete;

//------------------------------------------------------------------------------

bool CenMbaRceTable::addEntry( const CenRank & i_rank ,
                               STEP_CODE_DATA_STRUCT & i_sc, uint8_t i_count )
{
    bool o_doTps = false;

    RceTable::iterator it = iv_table.find( i_rank );
    if ( iv_table.end() == it )
    {
        // TODO via RTC 89386 PrdfCacheCETable implementation is not very
        // efficient. Need to find a better way.

        PrdfCacheCETable entry( getRceThreshold() );

        // Add a new rank entry to the table and get the iterator.
        it = iv_table.insert( std::make_pair(i_rank, entry) ).first;
    }

    for ( uint32_t i = 0; i < i_count; i++ )
    {
        // Insert all entries even if threshold is crossed
        // for better FFDC.
        o_doTps |= it->second.addAddress( 0, i_sc );
    }

    return o_doTps;
}

//------------------------------------------------------------------------------

void CenMbaRceTable::flushEntry( const CenRank & i_rank )
{
    RceTable::iterator it = iv_table.find( i_rank );
    if ( iv_table.end() != it )
        it->second.flushTable();
}
//------------------------------------------------------------------------------

void CenMbaRceTable::addCapData( CaptureData & io_cd )
{
    static const size_t sz_word = sizeof(CPU_WORD);
    static const size_t sz_entryCnt = sizeof( uint8_t ); // entry count

    // Get the maximum capture data size and adjust the size for endianess.
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
        if( 0 == it->second.getTotalCount() )
        {
            continue;
        }
        uint32_t mrnk = it->first.getMaster();            //  3-bit
        uint32_t srnk = it->first.getSlave();             //  3-bit
        uint32_t svld = it->first.isSlaveValid() ? 1 : 0; //  1-bit

        data[sz_actData] = (mrnk << 5) | (srnk << 2) | (svld << 1);
        uint32_t count = it->second.getTotalCount();
        data[sz_actData + 1] = ( count > 255 ) ? 255 : count;
        sz_actData += ENTRY_SIZE;
    }

    if ( 1 != sz_actData )
    {
        data[0] = sz_actData / ENTRY_SIZE;
        // Fix endianess issues with non PPC machines.
        sz_actData = ((sz_actData + sz_word-1) / sz_word) * sz_word;
        for ( uint32_t i = 0; i < (sz_actData/sz_word); i++ )
            ((CPU_WORD*)data)[i] = htonl(((CPU_WORD*)data)[i]);

        // Add data to capture data.
        BIT_STRING_ADDRESS_CLASS bs ( 0, sz_actData*8, (CPU_WORD *) &data );
        io_cd.Add( iv_mbaTrgt, Util::hashString("MEM_RCE_TABLE"), bs );
    }
}

} // end namespace PRDF

