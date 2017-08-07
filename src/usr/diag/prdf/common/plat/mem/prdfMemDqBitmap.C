/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemDqBitmap.C $         */
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

/** @file  prdfMemDqBitmap.C */

#include <prdfMemDqBitmap.H>

#include <UtilHash.H>
#include <iipServiceDataCollector.h>
#include <prdfParserUtils.H>

namespace PRDF
{

using namespace PlatServices;
using namespace PARSERUTILS;
using namespace fapi2; // for spare dram config

template <DIMMS_PER_RANK T>
bool MemDqBitmap<T>::badDqs() const
{
    bool o_badDqs = false;

    for ( uint32_t i = 0; i < T; i++ )
    {
        for ( uint32_t j = 0; j < DQ_BITMAP::BITMAP_SIZE; j++ )
        {
            if ( 0 != iv_data[i][j] )
            {
                o_badDqs = true;
                break;
            }
        }
        if ( o_badDqs ) break;
    }

    return o_badDqs;
}

//------------------------------------------------------------------------------

template <DIMMS_PER_RANK T>
int32_t MemDqBitmap<T>::badDqs( bool & o_badDqs, uint8_t i_portSlct ) const
{
    #define PRDF_FUNC "[MemDqBitmap::badDqs] "

    int32_t o_rc = SUCCESS;

    o_badDqs = false;

    do
    {
        if ( T <= i_portSlct )
        {
            PRDF_ERR(PRDF_FUNC "Invalid parameter: i_portSlct=%d", i_portSlct);
            o_rc = FAIL; break;
        }

        for ( uint32_t j = 0; j < DQ_BITMAP::BITMAP_SIZE; j++ )
        {
            if ( 0 != iv_data[i_portSlct][j] )
            {
                o_badDqs = true;
                break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <DIMMS_PER_RANK T>
int32_t MemDqBitmap<T>::setDq( uint8_t i_dq, uint8_t i_portSlct )
{
    #define PRDF_FUNC "[MemDqBitmap::setDq] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( DQS_PER_DIMM <= i_dq )
        {
            PRDF_ERR( PRDF_FUNC "Invalid parameter: i_dq=%d", i_dq );
            o_rc = FAIL; break;
        }

        if ( T <= i_portSlct )
        {
            PRDF_ERR(PRDF_FUNC "Invalid parameter: i_portSlct=%d", i_portSlct);
            o_rc = FAIL; break;
        }

        uint8_t byteIdx = i_dq / DQS_PER_BYTE;
        uint8_t bitIdx  = i_dq % DQS_PER_BYTE;

        uint32_t shift = (DQS_PER_BYTE-1) - bitIdx; // 0-7
        iv_data[i_portSlct][byteIdx] |= 0x01 << shift;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <DIMMS_PER_RANK T>
int32_t MemDqBitmap<T>::setSymbol( const MemSymbol & i_symbol, uint8_t i_pins )
{
    #define PRDF_FUNC "[MemDqBitmap::setSymbol] "

    int32_t o_rc = SUCCESS;

    do
    {
        uint8_t portSlct, byteIdx, bitIdx;
        o_rc = getPortByteBitIdx( i_symbol, portSlct, byteIdx, bitIdx );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getPortByteBitIdx() failed" );
            break;
        }

        uint32_t shift = (DQS_PER_BYTE-1) - bitIdx;
        if ( DIMMS_PER_RANK::MBA == T )
        {
            i_pins &= 0x3; // limit to 2 bits for MBA
            shift = (shift / MBA_DQS_PER_SYMBOL) * MBA_DQS_PER_SYMBOL; //0,2,4,6
        }
        else
        {
            i_pins &= 0x1; // limit to 1 bit for MCA
            shift = (shift / MCA_DQS_PER_SYMBOL) * MCA_DQS_PER_SYMBOL; //0-7
        }

        iv_data[portSlct][byteIdx] |= i_pins << shift;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <DIMMS_PER_RANK T>
int32_t MemDqBitmap<T>::setDram( const MemSymbol & i_symbol, uint8_t i_pins )
{
    #define PRDF_FUNC "[MemDqBitmap::setDram] "

    int32_t o_rc = SUCCESS;

    do
    {
        uint8_t portSlct, byteIdx, bitIdx;
        o_rc = getPortByteBitIdx( i_symbol, portSlct, byteIdx, bitIdx );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getPortByteBitIdx() failed" );
            break;
        }

        if ( iv_x4Dram )
        {
            i_pins &= 0xf; // limit to 4 bits
            uint32_t shift = (DQS_PER_BYTE-1) - bitIdx;
            shift = (shift / DQS_PER_NIBBLE) * DQS_PER_NIBBLE; // 0,4
            iv_data[portSlct][byteIdx] |= i_pins << shift;
        }
        else
        {
            i_pins &= 0xff; // limit to 8 bits
            iv_data[portSlct][byteIdx] |= i_pins;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <DIMMS_PER_RANK T>
void MemDqBitmap<T>::getCaptureData( CaptureData & o_cd ) const
{
    uint8_t rank   = iv_rank.getMaster();
    size_t sz_rank = sizeof(rank);

    size_t sz_capData = sz_rank + sizeof(iv_data);

    // Adjust the size for endianness.
    const size_t sz_word = sizeof(CPU_WORD);
    sz_capData = ((sz_capData + sz_word-1) / sz_word) * sz_word;

    uint8_t capData[sz_capData];
    memset( capData, 0x00, sz_capData );

    capData[0] = rank;
    memcpy( &capData[1], iv_data, sizeof(iv_data) );

    // Fix endianness issues with non PPC machines.
    for ( uint32_t i = 0; i < (sz_capData/sz_word); i++ )
        ((CPU_WORD*)capData)[i] = htonl(((CPU_WORD*)capData)[i]);

    BitString bs ( sz_capData*8, (CPU_WORD *) &capData );
    o_cd.Add( iv_trgt, Util::hashString("BAD_DQ_BITMAP"), bs );
}

//------------------------------------------------------------------------------

template <DIMMS_PER_RANK T>
int32_t MemDqBitmap<T>::getPortByteBitIdx( const MemSymbol & i_symbol,
                                           uint8_t & o_portSlct,
                                           uint8_t & o_byteIdx,
                                           uint8_t & o_bitIdx ) const
{
    #define PRDF_FUNC "[MemDqBitmap::getPortByteBitIdx] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( !i_symbol.isValid() )
        {
            PRDF_ERR( PRDF_FUNC "i_symbol is invalid" );
            o_rc = FAIL; break;
        }

        o_portSlct = i_symbol.getPortSlct();
        o_byteIdx  = i_symbol.getDq() / DQS_PER_BYTE;
        o_bitIdx   = i_symbol.getDq() % DQS_PER_BYTE;

        if ( i_symbol.isDramSpared() )
        {
            o_byteIdx = DRAM_SPARE_BYTE;
        }
        else if ( i_symbol.isEccSpared() )
        {
            o_portSlct = ECC_SPARE_PORT;
            o_byteIdx  = ECC_SPARE_BYTE;

            // x4 ECC spare is the second nibble of the byte.
            o_bitIdx = (o_bitIdx % DQS_PER_NIBBLE) + DQS_PER_NIBBLE;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
int32_t MemDqBitmap<DIMMS_PER_RANK::MCA>::isChipMark(
    const MemSymbol & i_symbol, bool & o_cm )
{
    #define PRDF_FUNC "[MemDqBitmap<DIMMS_PER_RANK::MCA>::isChipMark] "

    int32_t o_rc = SUCCESS;
    o_cm = false;

    do
    {
        // If 2 or more symbols are set in a nibble, the chip mark is present.

        uint8_t portSlct, byteIdx, bitIdx;
        o_rc = getPortByteBitIdx( i_symbol, portSlct, byteIdx, bitIdx );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getPortByteBitIdx() failed" );
            break;
        }

        uint8_t cmData = iv_data[portSlct][byteIdx];

        // Find which nibble to check.
        uint8_t nibble;
        if ( bitIdx < 4 )
            nibble = ( (cmData>>4) & 0xf );
        else
            nibble = cmData & 0xf;

        // This nibble must have 2 or more symbols set.
        o_cm = ( (0x0 != nibble) &&
                 (0x8 != nibble) &&
                 (0x4 != nibble) &&
                 (0x2 != nibble) &&
                 (0x1 != nibble) );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
int32_t MemDqBitmap<DIMMS_PER_RANK::MBA>::isChipMark(
    const MemSymbol & i_symbol, bool & o_cm )
{
    #define PRDF_FUNC "[MemDqBitmap<DIMMS_PER_RANK::MBA>::isChipMark] "

    int32_t o_rc = SUCCESS;
    o_cm = false;

    do
    {
        // If 2 or more symbols are set in a nibble, the chip mark is present.

        uint8_t portSlct, byteIdx, bitIdx;
        o_rc = getPortByteBitIdx( i_symbol, portSlct, byteIdx, bitIdx );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getPortByteBitIdx() failed" );
            break;
        }

        uint8_t cmData = iv_data[portSlct][byteIdx];

        // x4 Drams
        if ( iv_x4Dram )
        {
            // Find which nibble to check.
            uint8_t nibble;
            if ( bitIdx < 4 )
                nibble = ( (cmData>>4) & 0xf );
            else
                nibble = cmData & 0xf;

            // This nibble must have 2 or more symbols set.
            o_cm = ( (0x0 != nibble) &&
                     (0x8 != nibble) &&
                     (0x4 != nibble) &&
                     (0x2 != nibble) &&
                     (0x1 != nibble) );
        }
        // x8 Drams
        else
        {
            uint32_t count = 0;
            while ( 0 != cmData )
            {
                if ( 0 != (cmData & 0x3) )
                    count++;

                cmData >>= 2;
            }
            o_cm = ( count >= 2 );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <>
std::vector<MemSymbol> MemDqBitmap<DIMMS_PER_RANK::MCA>::getSymbolList(
    uint8_t i_portSlct )
{
    #define PRDF_FUNC "[MemDqBitmap::getSymbolList] "

    std::vector<MemSymbol> o_symbolList;

    // loop through all dimms
    for ( uint8_t dimm = 0; dimm < DIMMS_PER_RANK::MCA; dimm++ )
    {
        // loop through each byte in the bitmap
        for ( uint8_t byte = 0; byte < DQ_BITMAP::BITMAP_SIZE; byte++ )
        {
            // loop through each symbol index
            for ( uint8_t symIdx = 0; symIdx < MCA_SYMBOLS_PER_BYTE; symIdx++ )
            {
                uint8_t shift = ((MCA_SYMBOLS_PER_BYTE - 1) - symIdx) *
                                MCA_DQS_PER_SYMBOL;

                // if the bit is active
                if ( ((iv_data[dimm][byte] >> shift) & 0x1) != 0 )
                {
                    // get the dq
                    uint8_t dq = (byte * DQS_PER_BYTE) +
                                 (symIdx * MCA_DQS_PER_SYMBOL);

                    // convert the dq to symbol
                    uint8_t symbol = dq2Symbol<TARGETING::TYPE_MCA>( dq,
                        i_portSlct );

                    // add symbol to output
                    o_symbolList.push_back( MemSymbol::fromSymbol(iv_trgt,
                                            iv_rank, symbol) );
                }
            }
        }
    }

    return o_symbolList;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

template <>
std::vector<MemSymbol> MemDqBitmap<DIMMS_PER_RANK::MBA>::getSymbolList(
    uint8_t i_portSlct )
{
    #define PRDF_FUNC "[MemDqBitmap::getSymbolList] "

    std::vector<MemSymbol> o_symbolList;

    // loop through all dimms
    for ( uint8_t dimm = 0; dimm < DIMMS_PER_RANK::MBA; dimm++ )
    {
        // loop through each byte in the bitmap
        for ( uint8_t byte = 0; byte < DQ_BITMAP::BITMAP_SIZE; byte++ )
        {
            // loop through each bit pair
            for (uint8_t symIdx = 0; symIdx < MBA_SYMBOLS_PER_BYTE; symIdx++)
            {
                uint8_t shift = ((MBA_SYMBOLS_PER_BYTE - 1) - symIdx) *
                                MBA_DQS_PER_SYMBOL;

                // if the bit pair is active
                if ( ((iv_data[dimm][byte] >> shift) & 0x3) != 0 )
                {
                    // get the dq
                    uint8_t dq = (byte * DQS_PER_BYTE) +
                                 (symIdx * MBA_DQS_PER_SYMBOL);

                    // convert the dq to symbol
                    uint8_t symbol = dq2Symbol<TARGETING::TYPE_MBA>( dq,
                        i_portSlct );

                    // add symbol to output
                    o_symbolList.push_back( MemSymbol::fromSymbol(iv_trgt,
                                            iv_rank, symbol) );
                }

            }
        }
    }

    return o_symbolList;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemDqBitmap<DIMMS_PER_RANK::MCA>;
template class MemDqBitmap<DIMMS_PER_RANK::MBA>;

//------------------------------------------------------------------------------

} // end namespace PRDF

