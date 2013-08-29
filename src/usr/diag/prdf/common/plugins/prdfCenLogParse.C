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
#include <prdfParserEnums.H>

namespace PRDF
{

using namespace PARSER;

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
#else
namespace FSP
#endif
{

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
    UtilMem membuf( i_buffer, DQ_BITMAP::ENTRY_SIZE );

    uint8_t rank; membuf >> rank;
    snprintf( o_str, DATA_SIZE, "R:%1d", rank );

    for ( int32_t p = 0; p < PORT_SLCT_PER_MBA; p++ )
    {
        char temp[DATA_SIZE];

        strcat( o_str, "  " );

        for ( int32_t b = 0; b < DQ_BITMAP::BITMAP_SIZE; b++ )
        {
            uint8_t byte; membuf >> byte;
            snprintf( temp, DATA_SIZE, "%02x", byte );
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

    char tmp[HEADER_SIZE] = { '\0' };
    if ( 1 == mm.s.srankValid )
        snprintf( tmp, HEADER_SIZE, "S%d", mm.s.srank );

    char header[HEADER_SIZE];
    snprintf( header, HEADER_SIZE, "  mba(n%dp%dc%d)%s Rank:M%d%s",
              nodePos, cenPos, mbaPos, (cenPos < 10) ? " " : "",
              mm.s.mrank, tmp );

    char data[DATA_SIZE];

    switch ( mm.s.symbol )
    {
        case MemoryMruData::CALLOUT_RANK:
            snprintf( data, DATA_SIZE, "Special: CALLOUT_RANK" );
            break;
        case MemoryMruData::CALLOUT_RANK_AND_MBA:
            snprintf( data, DATA_SIZE, "Special: CALLOUT_RANK_AND_MBA" );
            break;
        case MemoryMruData::CALLOUT_ALL_MEM:
            snprintf( data, DATA_SIZE, "Special: CALLOUT_ALL_MEM" );
            break;
        default:
            // TODO: RTC 67358 Symbol, Pins, and Spared will be replaced with
            //       the DRAM Site Location and Wiring Type.
            snprintf( data, DATA_SIZE, "Symbol: %d Pins: %d Spared: %s",
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

bool parseMemUeTable( uint8_t  * i_buffer, uint32_t i_buflen,
                      ErrlUsrParser & i_parser )
{
    using namespace UE_TABLE;

    bool rc = true;

    if ( NULL == i_buffer ) return false; // Something failed in parser.

    const uint32_t entries = i_buflen / ENTRY_SIZE;

    i_parser.PrintNumber( " MEM_UE_TABLE", "%d", entries );

    const char * hh = "   Count Type";
    const char * hd = "Rank Bank Row     Column";
    i_parser.PrintString( hh, hd );
    hh = "   ----- -------------";
    hd = "---- ---- ------- ------";
    i_parser.PrintString( hh, hd );

    for ( uint32_t i = 0; i < entries; i++ )
    {
        uint32_t idx = i * ENTRY_SIZE;

        uint32_t count = i_buffer[idx  ];                           //  8-bit
        uint32_t type  = i_buffer[idx+1] >> 4;                      //  4-bit

        uint32_t mrnk  = (i_buffer[idx+2] >> 5) & 0x7;              //  3-bit
        uint32_t srnk  = (i_buffer[idx+2] >> 2) & 0x7;              //  3-bit
        uint32_t svld  = (i_buffer[idx+2] >> 1) & 0x1;              //  1-bit

        uint32_t row0    = i_buffer[idx+2] & 0x1;
        uint32_t row1_8  = i_buffer[idx+3];
        uint32_t row9_16 = i_buffer[idx+4];
        uint32_t row     = (row0 << 16) | (row1_8 << 8) | row9_16;  // 17-bit

        uint32_t bnk   = i_buffer[idx+5] >> 4;                      //  4-bit

        uint32_t col0_3  = i_buffer[idx+5] & 0xf;
        uint32_t col4_11 = i_buffer[idx+6];
        uint32_t col     = (col0_3 << 8) | col4_11;                 // 12-bit

        const char * type_str = "UNKNOWN      "; // 13 characters
        switch ( type )
        {
            case SCRUB_MPE: type_str = "SCRUB_MPE    "; break;
            case FETCH_MPE: type_str = "FETCH_MPE    "; break;
            case SCRUB_UE:  type_str = "SCRUB_UE     "; break;
            case FETCH_UE:  type_str = "FETCH_UE     "; break;
        }

        char rank_str[DATA_SIZE]; // 4 characters
        if ( 1 == svld )
        {
            snprintf( rank_str, DATA_SIZE, "m%ds%d", mrnk, srnk );
        }
        else
        {
            snprintf( rank_str, DATA_SIZE, "m%d  ", mrnk );
        }

        char header[HEADER_SIZE] = { '\0' };
        snprintf( header, HEADER_SIZE, "    0x%02x %s", count, type_str );

        char data[DATA_SIZE]     = { '\0' };
        snprintf( data, DATA_SIZE, "%s  0x%01x 0x%05x  0x%03x",
                  rank_str, bnk, row, col );

        i_parser.PrintString( header, data );
    }

    return rc;
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

        i_parser.PrintNumber( " DRAM_REPAIRS_DATA", "%d", rankCount );

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

    const uint32_t entries = i_buflen / DQ_BITMAP::ENTRY_SIZE;

    i_parser.PrintNumber( " DRAM_REPAIRS_VPD", "%d", entries );

    for ( uint32_t i = 0; i < entries; i++ )
    {
        char data[DATA_SIZE];
        getBadDqBitmapEntry( &i_buffer[i*DQ_BITMAP::ENTRY_SIZE], data );

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

    if ( DQ_BITMAP::ENTRY_SIZE > i_buflen ) // Data is expected to be one entry.
    {
        i_parser.PrintString( " BAD_DQ_BITMAP", "" );
        i_parser.PrintHexDump(i_buffer, i_buflen);
    }
    else
    {
        char data[DATA_SIZE];
        getBadDqBitmapEntry( i_buffer, data );

        i_parser.PrintString( " BAD_DQ_BITMAP", data );
    }

    return rc;
}

} // namespace FSP/HOSTBBOT
} // end namespace PRDF

