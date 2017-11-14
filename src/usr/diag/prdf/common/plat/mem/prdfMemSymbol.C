/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemSymbol.C $           */
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

#include <prdfMemSymbol.H>

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfTrace.H>

// Parser includes
#include <prdfParserUtils.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
using namespace CEN_SYMBOL;
using namespace PARSERUTILS;

//##############################################################################
//                           class MemSymbol
//##############################################################################

MemSymbol::MemSymbol( TARGETING::TargetHandle_t i_trgt, const MemRank & i_rank,
                      uint8_t i_symbol, uint8_t i_pins ) :
    iv_trgt(i_trgt), iv_rank(i_rank), iv_symbol(i_symbol),
    iv_pins(i_pins), iv_isDramSpared(false), iv_isEccSpared(false)
{
    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( TYPE_MBA == getTargetType(i_trgt) ||
                 TYPE_MCA == getTargetType(i_trgt) );
    // Allowing an invalid symbol. Use isValid() to check validity.
    PRDF_ASSERT( i_pins <= CEN_SYMBOL::BOTH_SYMBOL_DQS );
}

//------------------------------------------------------------------------------

MemSymbol MemSymbol::fromGalois( TargetHandle_t i_trgt, const MemRank & i_rank,
                                 uint8_t i_galois, uint8_t i_mask )
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

    // Get pins from mask.
    uint8_t pins = NO_SYMBOL_DQS;
    if ( TYPE_MBA == getTargetType(i_trgt) )
    {
        // 2 pins for MBA.
        if ( 0 != (i_mask & 0xaa) ) pins |= EVEN_SYMBOL_DQ;
        if ( 0 != (i_mask & 0x55) ) pins |= ODD_SYMBOL_DQ;
    }
    else
    {
        // 1 pin for MCA.
        if ( 0 != (i_mask & 0xff) ) pins |= ODD_SYMBOL_DQ;
    }

    return MemSymbol( i_trgt, i_rank, symbol, pins );
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getDq() const
{
    bool isMba = TYPE_MBA == getTargetType(iv_trgt);

    return isMba ? symbol2Dq<TYPE_MBA>(iv_symbol)
                 : symbol2Dq<TYPE_MCA>(iv_symbol);
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getPortSlct() const
{
    bool isMba = TYPE_MBA == getTargetType(iv_trgt);

    return isMba ? symbol2PortSlct<TYPE_MBA>(iv_symbol)
                 : symbol2PortSlct<TYPE_MCA>(iv_symbol);
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getDram() const
{
    bool isMba = TYPE_MBA == getTargetType(iv_trgt);
    bool isX4  = isDramWidthX4( iv_trgt );

    return isMba ? isX4 ? symbol2Nibble<TYPE_MBA>( iv_symbol )
                        : symbol2Byte  <TYPE_MBA>( iv_symbol )
                 : isX4 ? symbol2Nibble<TYPE_MCA>( iv_symbol )
                        : symbol2Byte  <TYPE_MCA>( iv_symbol );
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getDramPins() const
{
    bool isMba = TYPE_MBA == getTargetType(iv_trgt);
    bool isX4  = isDramWidthX4( iv_trgt );

    uint32_t dps = isMba ? MBA_DQS_PER_SYMBOL : MCA_DQS_PER_SYMBOL;
    uint32_t spd = isMba ? isX4 ? MBA_SYMBOLS_PER_NIBBLE : MBA_SYMBOLS_PER_BYTE
                         : isX4 ? MCA_SYMBOLS_PER_NIBBLE : MCA_SYMBOLS_PER_BYTE;

    return iv_pins << (((spd - 1) - (iv_symbol % spd)) * dps);
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getGalois() const
{
    return symbol2Galois[iv_symbol];
}

//------------------------------------------------------------------------------
//                       Symbol Accessor Functions
//------------------------------------------------------------------------------

template<>
uint32_t getMemReadSymbol<TYPE_MCA>( ExtensibleChip * i_chip,
                                     const MemRank & i_rank,
                                     MemSymbol & o_sym1, MemSymbol & o_sym2 )
{
    #define PRDF_FUNC "[getMemReadSymbol<TYPE_MBA>] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    o_sym1 = o_sym2 = MemSymbol(); // both initially invalid

    do
    {
        // Get the NCE/TCE galois and mask from hardware.
        ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );

        uint8_t port      = i_chip->getPos() % MAX_MCA_PER_MCBIST; // 0,1,2,3
        uint8_t mcsRelMcb = port / MAX_MCA_PER_MCS;                // 0,1
        uint8_t mcaRelMcs = port % MAX_MCA_PER_MCS;                // 0,1

        const char * reg_str = (0 == mcsRelMcb) ? "MBSEVR0" : "MBSEVR1";

        SCAN_COMM_REGISTER_CLASS * reg = mcbChip->getRegister(reg_str);
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s: mcbChip=0x%08x", reg_str,
                      mcbChip->getHuid() );
            break;
        }

        uint32_t bitPos = mcaRelMcs * 32;
        uint8_t g1 = reg->GetBitFieldJustified( bitPos,      8 );
        uint8_t m1 = reg->GetBitFieldJustified( bitPos +  8, 8 );
        uint8_t g2 = reg->GetBitFieldJustified( bitPos + 16, 8 );
        uint8_t m2 = reg->GetBitFieldJustified( bitPos + 24, 8 );

        // Get the NCE/TCE symbol.
        o_sym1 = MemSymbol::fromGalois( i_chip->getTrgt(), i_rank, g1, m1 );
        o_sym2 = MemSymbol::fromGalois( i_chip->getTrgt(), i_rank, g2, m2 );

        // TODO: RTC 157888 Check if the symbol is on a spare DRAM.

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t getMemReadSymbol<TYPE_MBA>( ExtensibleChip * i_chip,
                                     const MemRank & i_rank,
                                     MemSymbol & o_sym1, MemSymbol & o_sym2 )
{
    #define PRDF_FUNC "[getMemReadSymbol<TYPE_MBA>] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    o_sym1 = o_sym2 = MemSymbol(); // both initially invalid

    do
    {
        // Get the NCE galois and mask from hardware.
        ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );

        const char * reg_str = (0 == i_chip->getPos()) ? "MBA0_MBSEVR"
                                                       : "MBA1_MBSEVR";

        SCAN_COMM_REGISTER_CLASS * reg = membChip->getRegister(reg_str);
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s: membChip=0x%08x", reg_str,
                      membChip->getHuid() );
            break;
        }

        uint8_t g1 = reg->GetBitFieldJustified( 40, 8 );
        uint8_t m1 = reg->GetBitFieldJustified( 32, 8 );

        // Get the NCE symbol.
        o_sym1 = MemSymbol::fromGalois( i_chip->getTrgt(), i_rank, g1, m1 );

        // TODO: RTC 157888 Check if the symbol is on a spare DRAM.

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF
