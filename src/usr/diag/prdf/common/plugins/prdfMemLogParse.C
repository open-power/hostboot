/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfMemLogParse.C $          */
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

/** @file  prdfMemLogParse.C
 *  @brief Error log parsing code specific to the memory subsystem.
 */

#include <prdfMemLogParse.H>

#include <errlusrparser.H>
#include <cstring>
#include <UtilHash.H>
#include <utilmem.H>
#include <iipconst.h>
#include <prdfBitString.H>
#include <prdfDramRepairUsrData.H>
#include <prdfParserEnums.H>
#include <prdfParserUtils.H>

namespace PRDF
{

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN)
namespace HOSTBOOT
{
#elif defined(PRDF_FSP_ERRL_PLUGIN)
namespace FSP
{
#endif

using namespace PARSER;
using namespace PARSERUTILS;
using namespace MemoryMruData;
using namespace TARGETING;

//##############################################################################
// Support functions for looking up DRAM site locations
//##############################################################################

// Returns the DQ site index 0-71, or 72-79 if spared to DRAM
template<TARGETING::TYPE T>
uint8_t transDramSpare( uint8_t i_dq, bool i_isDramSpared )
{
    uint8_t dqIdx = i_dq;

    if ( i_isDramSpared )
    {
        // The DRAM spare indexes are 72-79, so adjust this DQ to match.
        dqIdx = DQS_PER_DIMM + (i_dq % DQS_PER_BYTE);
    }

    return dqIdx;
}

template
uint8_t transDramSpare<TYPE_MBA>( uint8_t i_dq, bool i_isDramSpared );
template
uint8_t transDramSpare<TYPE_MCA>( uint8_t i_dq, bool i_isDramSpared );

template<>
uint8_t transDramSpare<TYPE_OCMB_CHIP>( uint8_t i_dq, bool i_isDramSpared )
{
    uint8_t dqIdx = i_dq;

    if ( i_isDramSpared )
    {
        // The DRAM spare indexes are 40-47, so adjust this DQ to match.
        dqIdx = OCMB_SPARE_DQ_START + (i_dq % DQS_PER_BYTE);
    }

    return dqIdx;
}

//------------------------------------------------------------------------------

// The DRAM site index is different than the DRAM number used in symbol2Dram()
// or dram2Symbol(). This index is solely used for accessing the DRAM site
// tables above.
uint8_t dqSiteIdx2DramSiteIdx( uint8_t i_dqSiteIdx, bool i_isX4Dram )
{
    const uint8_t dqsPerDram = i_isX4Dram ? DQS_PER_NIBBLE
                                          : DQS_PER_BYTE;
    return i_dqSiteIdx / dqsPerDram;
}

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
void getBadDqBitmapEntry( uint8_t * i_buffer, char * o_str, TYPE i_type )
{
    uint32_t entrySize = DQ_BITMAP::ENTRY_SIZE;

    UtilMem membuf( i_buffer, entrySize );

    uint8_t rank; membuf >> rank;
    snprintf( o_str, DATA_SIZE, "R:%1d", rank );

    char temp[DATA_SIZE];
    uint8_t port; membuf >> port;
    snprintf( temp, DATA_SIZE, "P:%1d", port );
    strcat( o_str, temp );

    strcat( o_str, "  " );

    for ( int32_t b = 0; b < DQ_BITMAP::BITMAP_SIZE; b++ )
    {
        uint8_t byte; membuf >> byte;
        snprintf( temp, DATA_SIZE, "%02x", byte );
        strcat( o_str, temp );
    }
}

// Gets the string representation for a single row repair entry.
void getRowRepairEntry( uint8_t * i_buffer, char * o_str )
{
    uint32_t entrySize = ROW_REPAIR::ENTRY_SIZE;

    UtilMem membuf( i_buffer, entrySize );

    uint8_t rank; membuf >> rank;
    snprintf( o_str, DATA_SIZE, "R:%1d ", rank );

    char temp[DATA_SIZE];
    uint8_t port; membuf >> port;
    snprintf( temp, DATA_SIZE, "P:%1d", port );
    strcat( o_str, temp );

    strcat( o_str, "  " );

    for ( int32_t b = 0; b < ROW_REPAIR::ROW_REPAIR_SIZE; b++ )
    {
        uint8_t byte; membuf >> byte;
        snprintf( temp, DATA_SIZE, "%02x", byte );
        strcat( o_str, temp );
    }
}

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// Helper function for parseMemMruData()
void initMemMruStrings( MemoryMruData::MemMruMeld i_mm, bool & o_addDramSite,
                        char * o_header, char * o_data )
{
    o_addDramSite = false;
    memset( o_header, '\0', HEADER_SIZE );
    memset( o_data,   '\0', DATA_SIZE   );

    // Get the position info (default invalid).
    const char * compStr = "";
    uint8_t      nodePos = i_mm.s.nodePos;
    uint8_t      chipPos = 0;
    uint8_t      compPos = 0;

    if ( i_mm.s.isOcmb ) // OCMB
    {
        compStr = "omi";
        chipPos = i_mm.s.procPos;
        compPos = (i_mm.s.chnlPos * MAX_MCC_PER_PROC) + i_mm.s.omiPos;
    }

    // Build the header string.
    snprintf( o_header, HEADER_SIZE, "  %s(n%dp%dc%d) Rank:m%ds%d",
              compStr, nodePos, chipPos, compPos, i_mm.s.mrank, i_mm.s.srank );

    // Build the generic data string (no DRAM site info).
    switch ( i_mm.s.symbol )
    {
        case MemoryMruData::CALLOUT_RANK:
            snprintf( o_data, DATA_SIZE, "Special: CALLOUT_RANK" );
            break;
        case MemoryMruData::CALLOUT_ALL_MEM:
            snprintf( o_data, DATA_SIZE, "Special: CALLOUT_ALL_MEM" );
            break;
        default:

            if ( SYMBOLS_PER_RANK > i_mm.s.symbol )
            {
                o_addDramSite = true; // Only condition where a DRAM site
                                      // location is relevant.

                snprintf( o_data, DATA_SIZE,
                          "Sym:%d Pins:%d S:%c ",
                          i_mm.s.symbol, i_mm.s.pins,
                          (1 == i_mm.s.dramSpared) ? 'Y' : 'N' );
            }
    }

    // Output should look like:
    //  |   mba(n0p0c0)  Rank:M7   : Special: CALLOUT_RANK                    |
    //  |   mba(n7p63c1) Rank:M0S7 : Symbol:71 Pins:3 S:Y E:N                 |
    // DRAM site info will be added later.
}

//------------------------------------------------------------------------------

// Helper function for parseMemMruData()
void addDramSiteString( const MemoryMruData::ExtendedData & i_extMemMru,
                        char * io_data )
{
    MemoryMruData::MemMruMeld mm = i_extMemMru.mmMeld;

    // Get the DQ indexes for site location tables, adjusting for spare DRAM, if
    // needed.
    uint8_t dqIdx = symbol2Dq<TYPE_OCMB_CHIP>(mm.s.symbol);
    dqIdx = transDramSpare<TYPE_OCMB_CHIP>( dqIdx, mm.s.dramSpared );

    // Add DQ info.
    char tmp[DATA_SIZE] = { '\0' };
    strcat( io_data, "DQ:" );

    // DQs for OCMB have a 1-to-1 mapping
    snprintf( tmp, DATA_SIZE, "%d", dqIdx );

    strcat( io_data, tmp );
}

//------------------------------------------------------------------------------

void parseMemMruData( ErrlUsrParser & i_parser, uint32_t i_memMru )
{
    MemoryMruData::MemMruMeld mm; mm.u = i_memMru;

    bool addDramSite;
    char header[HEADER_SIZE]; char data[DATA_SIZE];
    initMemMruStrings( mm, addDramSite, header, data );

    // No DRAM site location data available.

    i_parser.PrintString( header, data );
}

//------------------------------------------------------------------------------

void parseMemMruData( ErrlUsrParser & i_parser,
                      const MemoryMruData::ExtendedData & i_extMemMru )
{
    bool addDramSite;
    char header[HEADER_SIZE]; char data[DATA_SIZE];
    initMemMruStrings( i_extMemMru.mmMeld, addDramSite, header, data );

    if ( addDramSite )
    {
        // Get the DRAM site location information from the extended data.
        addDramSiteString( i_extMemMru, data );
    }

    i_parser.PrintString( header, data );
}

//------------------------------------------------------------------------------

bool parseMemUeTable( uint8_t  * i_buffer, uint32_t i_buflen,
                      ErrlUsrParser & i_parser )
{
    using namespace UE_TABLE;

    bool rc = true;

    if ( nullptr == i_buffer ) return false; // Something failed in parser.

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

        uint32_t count    =  i_buffer[idx  ];                           // 8-bit
        uint32_t type     =  i_buffer[idx+1] >> 4;                      // 4-bit
        // 4 spare bits                                                 // 4-bit
        uint32_t mrnk     = (i_buffer[idx+2] >> 5) & 0x7;               // 3-bit
        uint32_t srnk     = (i_buffer[idx+2] >> 2) & 0x7;               // 3-bit
        uint32_t row0_1   =  i_buffer[idx+2]       & 0x3;               // 2-bit
        uint32_t row2_9   =  i_buffer[idx+3];                           // 8-bit
        uint32_t row10_17 =  i_buffer[idx+4];                           // 8-bit
        uint32_t bnk      = (i_buffer[idx+5] >> 3) & 0x1f;              // 5-bit
        // 2 spare bits                                                 // 2-bit
        uint32_t col0     =  i_buffer[idx+5]       & 0x1;               // 1-bit
        uint32_t col1_8   =  i_buffer[idx+6];                           // 8-bit

        uint32_t row = (row0_1 << 16) | (row2_9 << 8) | row10_17;
        uint32_t col =                  (col0   << 8) | col1_8;

        const char * type_str = "UNKNOWN      "; // 13 characters
        switch ( type )
        {
            case SCRUB_MPE: type_str = "SCRUB_MPE    "; break;
            case FETCH_MPE: type_str = "FETCH_MPE    "; break;
            case SCRUB_UE:  type_str = "SCRUB_UE     "; break;
            case FETCH_UE:  type_str = "FETCH_UE     "; break;
        }

        char header[HEADER_SIZE] = { '\0' };
        snprintf( header, HEADER_SIZE, "    %3d  %s", count, type_str );

        char data[DATA_SIZE]     = { '\0' };
        snprintf( data, DATA_SIZE, "m%ds%d 0x%02x 0x%05x  0x%03x",
                  mrnk, srnk, bnk, row, col );

        i_parser.PrintString( header, data );
    }

    return rc;
}

//------------------------------------------------------------------------------

bool parseMemCeTable( uint8_t  * i_buffer, uint32_t i_buflen,
                      ErrlUsrParser & i_parser )
{
    using namespace CE_TABLE;

    bool o_rc = true;

    if ( nullptr == i_buffer ) return false; // Something failed in parser.
    if ( i_buflen < METADATA_SIZE )
        return false; // Something failed in parser.

    const uint32_t entries = (i_buflen - METADATA_SIZE ) / ENTRY_SIZE;

    i_parser.PrintNumber( " MEM_CE_TABLE", "%d", entries );

    const char * hh = "   A H Count RC";
    const char * hd = "Rank P Bank Row     Column DRAM Pins S E Site";
    i_parser.PrintString( hh, hd );
    hh = "   - - ----- ----";
    hd = "---- - ---- ------- ------ ---- ---- - - ------";
    i_parser.PrintString( hh, hd );

    // Get the metadata info.
    // Bytes 0-7 are currently unused.

    // Get the entry info.
    for ( uint32_t idx = METADATA_SIZE, entry = 0;
          idx < i_buflen && entry < entries;
          idx += CE_TABLE::ENTRY_SIZE, entry++ )
    {
        uint32_t count    =  i_buffer[idx  ];                           // 8-bit
        // 5 spare bits                                                 // 5-bit
        uint32_t isSp     = (i_buffer[idx+1] >> 2) & 0x1;               // 1-bit
        // 2 spare bits                                                 // 2-bit
        uint32_t isHard   = (i_buffer[idx+2] >> 7) & 0x1;               // 1-bit
        uint32_t active   = (i_buffer[idx+2] >> 6) & 0x1;               // 1-bit
        uint32_t dram     =  i_buffer[idx+2]       & 0x3f;              // 6-bit
        uint32_t dramPins =  i_buffer[idx+3];                           // 8-bit
        uint32_t mrnk     = (i_buffer[idx+4] >> 5) & 0x7;               // 3-bit
        uint32_t srnk     = (i_buffer[idx+4] >> 2) & 0x7;               // 3-bit
        uint32_t row0_1   =  i_buffer[idx+4]       & 0x3;               // 2-bit
        uint32_t row2_9   =  i_buffer[idx+5];                           // 8-bit
        uint32_t row10_17 =  i_buffer[idx+6];                           // 8-bit
        uint32_t bnk      = (i_buffer[idx+7] >> 3) & 0x1f;              // 5-bit
        // 2 spare bits                                                 // 2-bit
        uint32_t col0     =  i_buffer[idx+7]       & 0x1;               // 1-bit
        uint32_t col1_8   =  i_buffer[idx+8];                           // 8-bit

        uint32_t row = (row0_1 << 16) | (row2_9 << 8) | row10_17;
        uint32_t col =                  (col0   << 8) | col1_8;

        char active_char = ( 1 == active ) ? 'Y':'N';
        char isHard_char = ( 1 == isHard ) ? 'Y':'N';
        char isSp_char   = ( 1 == isSp   ) ? 'Y':'N';

        const char * cardName_str = "";
        const char * portSlct_str = " "; // intentionally an empty space.
        const char * dramSite_str = "";

        // Build the header string.
        char header[HEADER_SIZE] = { '\0' };
        snprintf( header, HEADER_SIZE, "   %c %c  %3d  %s ", active_char,
                  isHard_char, count, cardName_str );

        // Build the data string.
        char data[DATA_SIZE] = { '\0' };
        snprintf( data, DATA_SIZE,
                  "m%ds%d %s 0x%02x 0x%05x  0x%03x   %2d 0x%02x %c %s",
                  mrnk, srnk, portSlct_str, bnk, row, col, dram, dramPins,
                  isSp_char, dramSite_str );

        // Print the line.
        i_parser.PrintString( header, data );
    }

    return o_rc;
}

//------------------------------------------------------------------------------

bool parseIueCounts( uint8_t  * i_buffer, uint32_t i_buflen,
                     ErrlUsrParser & i_parser )
{
    bool rc = true;
    // 2 bytes per entry
    const uint32_t entries = i_buflen / 2;

    i_parser.PrintNumber( " IUE COUNTS", "%d", entries );

    const char * hh = "Rank ";
    const char * hd = "Count";
    i_parser.PrintString( hh, hd );
    hh = "---- ";
    hd = "-----";
    i_parser.PrintString( hh, hd );

    for ( uint32_t i = 0; i < entries; i++ )
    {
        uint8_t idx = i*2;

        uint8_t rank  = i_buffer[idx];
        uint8_t count = i_buffer[idx+1];

        char header[HEADER_SIZE] = { '\0' };
        snprintf( header, DATA_SIZE, "%d    ", rank );

        char data[DATA_SIZE] = { '\0' };
        snprintf( header, DATA_SIZE, "%d", count );

        i_parser.PrintString( header, data );
    }

    return rc;
}

//------------------------------------------------------------------------------

bool parseDramRepairsData( uint8_t  * i_buffer, uint32_t i_buflen,
                           ErrlUsrParser & i_parser )
{
    bool rc = true;

    if ( nullptr != i_buffer )
    {
        UtilMem l_membuf( i_buffer, i_buflen );

        DramRepairUsrData usrData;
        l_membuf >> usrData;

        uint8_t rankCount = usrData.header.rankCount;

        i_parser.PrintNumber( " DRAM_REPAIRS_DATA", "%d", rankCount );

        // Iterate over all ranks
        for ( uint8_t rankIdx = 0; rankIdx < rankCount; rankIdx++ )
        {
            char data[64];
            char temp[64];
            char symbolStr[10];

            DramRepairRankData rankEntry = usrData.rankDataList[rankIdx];
            snprintf(temp, 64, "Rank: %d", rankEntry.rank);
            snprintf(data, 64, temp);

            getDramRepairSymbolStr(rankEntry.chipMark, symbolStr, 10);
            snprintf(temp, 64, "%s CM: %s", data, symbolStr);
            snprintf(data, 64, temp);

            getDramRepairSymbolStr(rankEntry.symbolMark, symbolStr, 10);
            snprintf(temp, 64, "%s SM: %s", data, symbolStr);
            snprintf(data, 64, temp);

            // Display DRAM spare information if spare DRAM is supported.
            if ( usrData.header.isSpareDram )
            {
                getDramRepairSymbolStr(rankEntry.port0Spare, symbolStr, 10);
                snprintf(temp, 64, "%s Sp0: %s", data, symbolStr);
                snprintf(data, 64, temp);

                getDramRepairSymbolStr(rankEntry.port1Spare, symbolStr, 10);
                snprintf(temp, 64, "%s Sp1: %s", data, symbolStr);
                snprintf(data, 64, temp);
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
                          ErrlUsrParser & i_parser, TARGETING::TYPE i_type )
{
    bool rc = true;

    if ( nullptr == i_buffer ) return false; // Something failed in parser.

    uint32_t entrySize = DQ_BITMAP::ENTRY_SIZE;

    const uint32_t entries = i_buflen / entrySize;

    i_parser.PrintNumber( " DRAM_REPAIRS_VPD", "%d", entries );

    for ( uint32_t i = 0; i < entries; i++ )
    {
        char data[DATA_SIZE];
        getBadDqBitmapEntry( &i_buffer[i*entrySize], data, i_type );

        i_parser.PrintString( "", data );
    }

    return rc;
}

//------------------------------------------------------------------------------

bool parseBadDqBitmap( uint8_t  * i_buffer, uint32_t i_buflen,
                       ErrlUsrParser & i_parser, TARGETING::TYPE i_type )
{
    bool rc = true;

    if ( nullptr == i_buffer ) return false; // Something failed in parser.

    uint32_t entrySize = DQ_BITMAP::ENTRY_SIZE;

    if ( entrySize > i_buflen ) // Data is expected to be one entry.
    {
        i_parser.PrintString( " BAD_DQ_BITMAP", "" );
        i_parser.PrintHexDump(i_buffer, i_buflen);
    }
    else
    {
        char data[DATA_SIZE];
        getBadDqBitmapEntry( i_buffer, data, i_type );

        i_parser.PrintString( " BAD_DQ_BITMAP", data );
    }

    return rc;
}

//------------------------------------------------------------------------------

bool parseRowRepairVpd( uint8_t * i_buffer, uint32_t i_buflen,
                        ErrlUsrParser & i_parser )
{
    bool rc = true;

    if ( nullptr == i_buffer ) return false; // Something failed in parser.

    uint32_t entrySize = ROW_REPAIR::ENTRY_SIZE;

    const uint32_t entries = i_buflen / entrySize;

    i_parser.PrintNumber( " ROW_REPAIR_VPD", "%d", entries );

    for ( uint32_t i = 0; i < entries; i++ )
    {
        char data[DATA_SIZE];
        getRowRepairEntry( &i_buffer[i*entrySize], data );

        i_parser.PrintString( "", data );
    }

    return rc;
}

//------------------------------------------------------------------------------

bool parseTdCtlrStateData( uint8_t  * i_buffer, uint32_t i_buflen,
                           ErrlUsrParser & i_parser, uint32_t i_sigId )
{
    bool o_rc = true;

    // Make sure we have a valid buffer.
    if ( (nullptr == i_buffer) || (0 == i_buflen) ) return false;

    // This is a copy of the enum in prdfMemTdQueue.H.
    enum TdType
    {
        VCM_EVENT = 0,
        DSD_EVENT,
        TPS_EVENT,
        INVALID_EVENT = 0xf,
    };

    do
    {
        const uint32_t bitLen = i_buflen * 8;
        BitString bs ( bitLen, (CPU_WORD*)i_buffer );
        uint32_t pos = 0;

        //######################################################################
        // Header data
        //######################################################################

        // Get the data state and version.
        if ( bitLen < 4 ) { o_rc = false; break; }

        uint8_t state   = bs.getFieldJustify( pos, 1 ); pos+=1;
        uint8_t version = bs.getFieldJustify( pos, 3 ); pos+=3;

        if ( (TD_CTLR_DATA::VERSION_1 != version) &&
             (TD_CTLR_DATA::VERSION_2 != version) )
        {
            o_rc = false; break;
        }

        uint32_t hdrLen = TD_CTLR_DATA::v1_HEADER;
        uint32_t entLen = TD_CTLR_DATA::v1_ENTRY;
        if ( TD_CTLR_DATA::VERSION_2 == version )
        {
            hdrLen = TD_CTLR_DATA::v2_HEADER;
            entLen = TD_CTLR_DATA::v2_ENTRY;
        }

        // Print the title and state.
        const char * state_str = ( TD_CTLR_DATA::RT == state ) ? "RT" : "IPL";

        if ( Util::hashString(TD_CTLR_DATA::START) == i_sigId )
            i_parser.PrintString( " TDCTLR_STATE_DATA_START", state_str );
        else if ( Util::hashString(TD_CTLR_DATA::END) == i_sigId )
            i_parser.PrintString( " TDCTLR_STATE_DATA_END", state_str );

        // Get the rest of the header data.
        if ( bitLen < hdrLen ) { o_rc = false; break; }

        uint8_t curMrnk    = bs.getFieldJustify( pos, 3 ); pos+=3;
        uint8_t curSrnk    = bs.getFieldJustify( pos, 3 ); pos+=3;
        uint8_t curPhase   = bs.getFieldJustify( pos, 4 ); pos+=4;
        uint8_t curType    = bs.getFieldJustify( pos, 4 ); pos+=4;
        uint8_t queueCount = bs.getFieldJustify( pos, 4 ); pos+=4;

        uint8_t curPort = 0;
        if ( TD_CTLR_DATA::VERSION_2 == version )
        {
            curPort = bs.getFieldJustify( pos, 2 ); pos+=2;
        }

        // Print the current procedure, if needed.
        if ( INVALID_EVENT != curType )
        {
            const char * curType_str = "";
            switch ( curType )
            {
                case VCM_EVENT: curType_str = "VCM"; break;
                case DSD_EVENT: curType_str = "DSD"; break;
                case TPS_EVENT: curType_str = "TPS"; break;
                default       : curType_str = "???"; break;
            }

            char curPort_str[DATA_SIZE] = "";
            if ( TD_CTLR_DATA::VERSION_2 == version )
            {
                snprintf( curPort_str, DATA_SIZE, "port %d", curPort );
            }

            char curData_str[DATA_SIZE] = "";
            snprintf( curData_str, DATA_SIZE, "%s phase %d on m%ds%d %s",
                      curType_str, curPhase, curMrnk, curSrnk, curPort_str );

            i_parser.PrintString( "   Current procedure", curData_str );
        }

        //######################################################################
        // TD Queue entries
        //######################################################################

        for ( uint8_t n = 0; n < queueCount; n++ )
        {
            // Get the entry data.
            if ( bitLen < hdrLen + (n+1) * entLen ) { o_rc = false; break; }

            uint8_t itMrnk = bs.getFieldJustify( pos, 3 ); pos+=3;
            uint8_t itSrnk = bs.getFieldJustify( pos, 3 ); pos+=3;
            uint8_t itType = bs.getFieldJustify( pos, 4 ); pos+=4;

            uint8_t itPort = 0;
            if ( TD_CTLR_DATA::VERSION_2 == version )
            {
                itPort = bs.getFieldJustify( pos, 2 ); pos+=2;
            }

            // Print the entry.
            const char * itType_str = "";
            switch ( itType )
            {
                case VCM_EVENT: itType_str = "VCM"; break;
                case DSD_EVENT: itType_str = "DSD"; break;
                case TPS_EVENT: itType_str = "TPS"; break;
                default       : itType_str = "???"; break;
            }

            char itPort_str[DATA_SIZE] = "";
            if ( TD_CTLR_DATA::VERSION_2 == version )
            {
                snprintf( itPort_str, DATA_SIZE, "port %d", itPort );
            }

            char itData_str[DATA_SIZE] = "";
            snprintf( itData_str, DATA_SIZE, "%s on m%ds%d %s",
                      itType_str, itMrnk, itSrnk, itPort_str );

            i_parser.PrintString( "   TD queue entry", itData_str );
        }

    } while (0);

    if ( !o_rc )
    {
        i_parser.PrintHexDump(i_buffer, i_buflen);
    }

    return o_rc;
}

//------------------------------------------------------------------------------

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // end namespace FSP/HOSTBOOT
#endif
} // end namespace PRDF

