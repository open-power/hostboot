/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemSymbol.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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

#include <prdfMemSymbol.H>
#include <prdfTrace.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
using namespace CEN_SYMBOL;
using namespace PARSERUTILS;

// Symbol to Galois code mapping table
static const uint8_t symbol2Galois[] =
{
    0x80, 0xa0, 0x90, 0xf0, 0x08, 0x0a, 0x09, 0x0f, // symbols  0- 7
    0x98, 0xda, 0xb9, 0x7f, 0x91, 0xd7, 0xb2, 0x78, // symbols  8-15
    0x28, 0xea, 0x49, 0x9f, 0x9a, 0xd4, 0xbd, 0x76, // symbols 16-23
    0x60, 0xb0, 0xc0, 0x20, 0x06, 0x0b, 0x0c, 0x02, // symbols 24-31
    0xc6, 0xfb, 0x1c, 0x42, 0xca, 0xf4, 0x1d, 0x46, // symbols 32-39
    0xd6, 0x8b, 0x3c, 0xc2, 0xcb, 0xf3, 0x1f, 0x4e, // symbols 40-47
    0xe0, 0x10, 0x50, 0xd0, 0x0e, 0x01, 0x05, 0x0d, // symbols 48-55
    0x5e, 0x21, 0xa5, 0x3d, 0x5b, 0x23, 0xaf, 0x3e, // symbols 56-63
    0xfe, 0x61, 0x75, 0x5d, 0x51, 0x27, 0xa2, 0x38, // symbols 64-71
};

//##############################################################################
//                           class MemSymbol
//##############################################################################

template <>
MemSymbol<TYPE_MBA> MemSymbol<TYPE_MBA>::fromGalois( TargetHandle_t i_trgt,
                                                     const MemRank & i_rank,
                                                     uint8_t i_galois,
                                                     uint8_t i_mask )
{
    // Get symbol from Galois field.
    uint8_t symbol = SYMBOLS_PER_RANK;
    for ( uint32_t i = 0; i < SYMBOLS_PER_RANK; i++ )
    {
        if ( symbol2Galois[i] == i_galois )
        {
            symbol = i;
            break;
        }
    }

    // Get pins from mask (2 pins for MBA).
    uint8_t pins = NO_SYMBOL_DQS;
    if ( 0 != (i_mask & 0xaa) ) pins |= EVEN_SYMBOL_DQ;
    if ( 0 != (i_mask & 0x55) ) pins |= ODD_SYMBOL_DQ;

    return MemSymbol<TYPE_MBA>( i_trgt, i_rank, symbol, pins );
}

//------------------------------------------------------------------------------

template <>
MemSymbol<TYPE_MCA> MemSymbol<TYPE_MCA>::fromGalois( TargetHandle_t i_trgt,
                                                     const MemRank & i_rank,
                                                     uint8_t i_galois,
                                                     uint8_t i_mask )
{
    // Get symbol from Galois field.
    uint8_t symbol = SYMBOLS_PER_RANK;
    for ( uint32_t i = 0; i < SYMBOLS_PER_RANK; i++ )
    {
        if ( symbol2Galois[i] == i_galois )
        {
            symbol = i;
            break;
        }
    }

    // Get pins from mask (1 pin for MCA).
    uint8_t pins = NO_SYMBOL_DQS;
    if ( 0 != (i_mask & 0xff) ) pins |= ODD_SYMBOL_DQ;

    return MemSymbol<TYPE_MCA>( i_trgt, i_rank, symbol, pins );
}

} // end namespace PRDF
