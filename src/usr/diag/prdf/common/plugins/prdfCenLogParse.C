/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfCenLogParse.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2013              */
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

/** @file  prdfCenLogParse.C
 *  @brief Error log parsing code specific to the memory subsystem.
 */

#include <prdfCenLogParse.H>

#include <errlusrparser.H>
#include <cstring>
#include <utilmem.H>

#include <prdfDramRepairUsrData.H>
#include <prdfMemoryMruData.H>

namespace PRDF
{
#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
#else
namespace FSP
#endif
{
//------------------------------------------------------------------------------
// Constants/structs/enums
//------------------------------------------------------------------------------

enum
{
    // This is defined in a file we can't include into the error log parser.
    DIMM_DQ_RANK_BITMAP_SIZE = 10,

    // Used for the several functions that parse bad DQ bitmaps.
    BITMAP_RANK_SIZE  = sizeof(uint8_t),
    BITMAP_DATA_SIZE  = PORT_SLCT_PER_MBA * DIMM_DQ_RANK_BITMAP_SIZE,
    BITMAP_ENTRY_SIZE = BITMAP_RANK_SIZE + BITMAP_DATA_SIZE,

    PARSER_HEADER_SIZE  = 25,
    PARSER_DATA_SIZE    = 50,
};

//------------------------------------------------------------------------------
// Helper functions
//------------------------------------------------------------------------------

// Displays symbol value. If symbol is not valid, will display '--' in output.
void getDramRepairSymbolStr( uint8_t i_value, char * o_str, uint32_t i_strSize )
{
    if ( SYMBOLS_PER_RANK <= i_value )
    {
        snprintf( o_str, i_strSize, "--" );
    }
    else
    {
        snprintf( o_str, i_strSize, "%2u", i_value );
    }
}

// Gets the string representation for a single bad DQ bitmap entry.
void getBadDqBitmapEntry( uint8_t * i_buffer, char * o_str )
{
    UtilMem membuf( i_buffer, BITMAP_ENTRY_SIZE );

    uint8_t rank; membuf >> rank;
    snprintf( o_str, PARSER_DATA_SIZE, "R:%1d", rank );

    for ( int32_t p = 0; p < PORT_SLCT_PER_MBA; p++ )
    {
        char temp[PARSER_DATA_SIZE];

        strcat( o_str, "  " );

        for ( int32_t b = 0; b < DIMM_DQ_RANK_BITMAP_SIZE; b++ )
        {
            uint8_t byte; membuf >> byte;
            snprintf( temp, PARSER_DATA_SIZE, "%02x", byte );
            strcat( o_str, temp );
        }
    }
}

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

bool parseMemMruData( ErrlUsrParser & i_parser, uint32_t i_memMru )
{
    bool o_rc = true;

    MemoryMruData::MemMruMeld mm; mm.u = i_memMru;

    uint8_t nodePos = mm.s.nodePos;
    uint8_t cenPos  = (mm.s.procPos << 3) | mm.s.cenPos;
    uint8_t mbaPos  = mm.s.mbaPos;

    char tmp[PARSER_HEADER_SIZE] = { '\0' };
    if ( 1 == mm.s.srankValid )
        snprintf( tmp, PARSER_HEADER_SIZE, "S%d", mm.s.srank );

    char header[PARSER_HEADER_SIZE];
    snprintf( header, PARSER_HEADER_SIZE, "  mba(n%dp%dc%d)%s Rank:M%d%s",
              nodePos, cenPos, mbaPos, (cenPos < 10) ? " " : "",
              mm.s.mrank, tmp );

    char data[PARSER_DATA_SIZE];

    switch ( mm.s.symbol )
    {
        case MemoryMruData::CALLOUT_RANK:
            snprintf( data, PARSER_DATA_SIZE, "Special: CALLOUT_RANK" );
            break;
        case MemoryMruData::CALLOUT_RANK_AND_MBA:
            snprintf( data, PARSER_DATA_SIZE, "Special: CALLOUT_RANK_AND_MBA" );
            break;
        case MemoryMruData::CALLOUT_ALL_MEM:
            snprintf( data, PARSER_DATA_SIZE, "Special: CALLOUT_ALL_MEM" );
            break;
        default:
            // TODO: RTC 67358 Symbol, Pins, and Spared will be replaced with
            //       the DRAM Site Location and Wiring Type.
            snprintf( data, PARSER_DATA_SIZE, "Symbol: %d Pins: %d Spared: %s",
                      mm.s.symbol, mm.s.pins,
                      (1 == mm.s.dramSpared) ? "true" : "false" );
    }

    // Ouptut should look like:
    // |   mba(n0p0c0)  Rank:M7   : Special: CALLOUT_RANK                    |
    // |   mba(n7p63c1) Rank:M0S7 : Symbol: 71 Pins: 3 Spared: false         |

    i_parser.PrintString( header, data );

    return o_rc;
}

//------------------------------------------------------------------------------

bool parseDramRepairsData( uint8_t  * i_buffer, uint32_t i_buflen,
                           ErrlUsrParser & i_parser )
{
    bool rc = true;

    if ( NULL != i_buffer )
    {
        UtilMem l_membuf( i_buffer, i_buflen );

        DramRepairMbaData mbaData;
        l_membuf >> mbaData;

        uint8_t rankCount = mbaData.header.rankCount;

        i_parser.PrintNumber( " DRAM_REPAIRS_DATA", "0x%02x", rankCount );

        // Iterate over all ranks
        for ( uint8_t rankIdx = 0; rankIdx < rankCount; rankIdx++ )
        {
            char data[64];
            char temp[64];
            char symbolStr[10];

            DramRepairRankData rankEntry = mbaData.rankDataList[rankIdx];
            snprintf(temp, 64, "Rank: %d", rankEntry.rank);
            snprintf(data, 64, temp);

            getDramRepairSymbolStr(rankEntry.chipMark, symbolStr, 10);
            snprintf(temp, 64, "%s CM: %s", data, symbolStr);
            snprintf(data, 64, temp);

            getDramRepairSymbolStr(rankEntry.symbolMark, symbolStr, 10);
            snprintf(temp, 64, "%s SM: %s", data, symbolStr);
            snprintf(data, 64, temp);

            // Display DRAM spare information for non-ISDIMMs
            if ( !mbaData.header.isIsDimm )
            {
                getDramRepairSymbolStr(rankEntry.port0Spare, symbolStr, 10);
                snprintf(temp, 64, "%s Sp0: %s", data, symbolStr);
                snprintf(data, 64, temp);

                getDramRepairSymbolStr(rankEntry.port1Spare, symbolStr, 10);
                snprintf(temp, 64, "%s Sp1: %s", data, symbolStr);
                snprintf(data, 64, temp);

                // Display ECC spare information for X4 DRAMs
                if ( mbaData.header.isX4Dram )
                {
                    getDramRepairSymbolStr( rankEntry.eccSpare, symbolStr, 10 );
                    snprintf(temp, 64, "%s EccSp: %s", data, symbolStr);
                    snprintf(data, 64, temp);
                }
            }

            i_parser.PrintString( "", data );
        }
    }
    else
    {
        rc = false;
    }

    return rc;
}

//------------------------------------------------------------------------------

bool parseDramRepairsVpd( uint8_t * i_buffer, uint32_t i_buflen,
                          ErrlUsrParser & i_parser )
{
    bool rc = true;

    if ( NULL == i_buffer ) return false; // Something failed in parser.

    const uint32_t entries = i_buflen / BITMAP_ENTRY_SIZE;

    i_parser.PrintNumber( " DRAM_REPAIRS_VPD", "0x%02x", entries );

    for ( uint32_t i = 0; i < entries; i++ )
    {
        char data[PARSER_DATA_SIZE];
        getBadDqBitmapEntry( &i_buffer[i*BITMAP_ENTRY_SIZE], data );

        i_parser.PrintString( "", data );
    }

    return rc;
}

//------------------------------------------------------------------------------

bool parseBadDqBitmap( uint8_t  * i_buffer, uint32_t i_buflen,
                       ErrlUsrParser & i_parser )
{
    bool rc = true;

    if ( NULL == i_buffer ) return false; // Something failed in parser.

    if ( BITMAP_ENTRY_SIZE > i_buflen ) // Data is expected to be one entry.
    {
        i_parser.PrintString( " BAD_DQ_BITMAP", "" );
        i_parser.PrintHexDump(i_buffer, i_buflen);
    }
    else
    {
        char data[PARSER_DATA_SIZE];
        getBadDqBitmapEntry( i_buffer, data );

        i_parser.PrintString( " BAD_DQ_BITMAP", data );
    }

    return rc;
}

} // namespace FSP/HOSTBBOT
} // end namespace PRDF

