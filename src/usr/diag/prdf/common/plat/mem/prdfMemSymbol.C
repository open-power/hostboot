/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemSymbol.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2019                        */
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
                 TYPE_MCA == getTargetType(i_trgt) ||
                 TYPE_MEM_PORT == getTargetType(i_trgt) );
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
    TYPE trgtType = getTargetType( i_trgt );
    if ( TYPE_MBA == trgtType )
    {
        // 2 pins for MBA.
        if ( 0 != (i_mask & 0xaa) ) pins |= EVEN_SYMBOL_DQ;
        if ( 0 != (i_mask & 0x55) ) pins |= ODD_SYMBOL_DQ;
    }
    else if ( TYPE_MCA == trgtType || TYPE_MEM_PORT == trgtType )
    {
        // 1 pin for MCA/MEM_PORT.
        if ( 0 != (i_mask & 0xff) ) pins |= ODD_SYMBOL_DQ;
    }
    else
    {
        PRDF_ERR( "MemSymbol::fromGalois: Invalid target type" );
        PRDF_ASSERT(false);
    }

    return MemSymbol( i_trgt, i_rank, symbol, pins );
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getDq() const
{
    uint8_t dq = DQS_PER_DIMM;
    TYPE trgtType = getTargetType( iv_trgt );

    if ( TYPE_MBA == trgtType )
    {
        dq = symbol2Dq<TYPE_MBA>( iv_symbol );
    }
    else if ( TYPE_MCA == trgtType )
    {
        dq = symbol2Dq<TYPE_MCA>( iv_symbol );
    }
    else if ( TYPE_MEM_PORT == trgtType )
    {
        dq = symbol2Dq<TYPE_MEM_PORT>( iv_symbol );
    }
    else
    {
        PRDF_ERR( "MemSymbol::getDq: Invalid target type." );
        PRDF_ASSERT( false );
    }

    return dq;
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getPortSlct() const
{
    uint8_t portSlct = 0;
    TYPE trgtType = getTargetType( iv_trgt );

    if ( TYPE_MBA == trgtType )
    {
        portSlct = symbol2PortSlct<TYPE_MBA>( iv_symbol );
    }
    else if ( TYPE_MCA == trgtType )
    {
        portSlct = symbol2PortSlct<TYPE_MCA>( iv_symbol );
    }
    else if ( TYPE_MEM_PORT == trgtType )
    {
        portSlct = symbol2PortSlct<TYPE_MEM_PORT>( iv_symbol );
    }
    else
    {
        PRDF_ERR( "MemSymbol::getPortSlct: Invalid target type" );
        PRDF_ASSERT( false );
    }

    return portSlct;
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getDram() const
{
    uint8_t dram = 0;
    TYPE trgtType = getTargetType( iv_trgt );
    bool isX4  = isDramWidthX4( iv_trgt );

    if ( TYPE_MBA == trgtType )
    {
        dram = isX4 ? symbol2Nibble<TYPE_MBA>( iv_symbol )
                    : symbol2Byte  <TYPE_MBA>( iv_symbol );
    }
    else if ( TYPE_MCA == trgtType )
    {
        dram = isX4 ? symbol2Nibble<TYPE_MCA>( iv_symbol )
                    : symbol2Byte  <TYPE_MCA>( iv_symbol );
    }
    else if ( TYPE_MEM_PORT == trgtType )
    {
        dram = isX4 ? symbol2Nibble<TYPE_MEM_PORT>( iv_symbol )
                    : symbol2Byte  <TYPE_MEM_PORT>( iv_symbol );
    }
    else
    {
        PRDF_ERR( "MemSymbol::getDram: Invalid target type" );
        PRDF_ASSERT( false );
    }

    return dram;
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getDramRelCenDqs() const
{
    // This function will return the DRAM position for this symbol relative
    // to the Centaur DQs. Mainly this is needed for the DRAM position input
    // of Row Repair.

    const uint8_t X4_ECC_SPARE = 17;
    const uint8_t X8_ECC_SPARE = 8;

    const uint8_t X4_DRAM_SPARE_LOWER = 18;
    const uint8_t X4_DRAM_SPARE_UPPER = 19;
    const uint8_t X8_DRAM_SPARE = 9;


    uint8_t l_dramWidth = ( isDramWidthX4(iv_trgt) ) ? 4 : 8;
    uint8_t l_dram = getDq() / l_dramWidth; // (x8: 0-9, x4: 0-19)

    // Adjust for spares
    if ( isDramSpared() )
    {
        if ( isDramWidthX4(iv_trgt) )
        {
            uint8_t l_bit  = getDq() % DQS_PER_BYTE;
            l_dram = ( l_bit < 4 ) ? X4_DRAM_SPARE_LOWER : X4_DRAM_SPARE_UPPER;
        }
        else
        {
            l_dram = X8_DRAM_SPARE;
        }
    }
    else if ( isEccSpared() )
    {
        l_dram = ( isDramWidthX4(iv_trgt) ) ? X4_ECC_SPARE : X8_ECC_SPARE;
    }

    return l_dram;

}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getDramPins() const
{
    TYPE trgtType = getTargetType( iv_trgt );
    bool isX4  = isDramWidthX4( iv_trgt );

    uint32_t dps = 0;
    uint32_t spd = 0;

    if ( TYPE_MBA == trgtType )
    {
        dps = MBA_DQS_PER_SYMBOL;
        spd = isX4 ? MBA_SYMBOLS_PER_NIBBLE : MBA_SYMBOLS_PER_BYTE;
    }
    else if ( TYPE_MCA == trgtType || TYPE_MEM_PORT == trgtType )
    {
        dps = MEM_DQS_PER_SYMBOL;
        spd = isX4 ? MEM_SYMBOLS_PER_NIBBLE : MEM_SYMBOLS_PER_BYTE;
    }
    else
    {
        PRDF_ERR( "MemSymbol::getDramPins: Invalid target type" );
        PRDF_ASSERT( false );
    }

    return iv_pins << (((spd - 1) - (iv_symbol % spd)) * dps);
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getDramSymbol() const
{
    uint8_t dramSymbol = SYMBOLS_PER_RANK;
    TYPE trgtType = getTargetType( iv_trgt );
    bool    isX4  = isDramWidthX4( iv_trgt );
    uint8_t dram  = getDram();

    if ( TYPE_MBA == trgtType )
    {
        dramSymbol = isX4 ? nibble2Symbol<TYPE_MBA>( dram )
                          : byte2Symbol  <TYPE_MBA>( dram );
    }
    else if ( TYPE_MCA == trgtType )
    {
        dramSymbol = isX4 ? nibble2Symbol<TYPE_MCA>( dram )
                          : byte2Symbol  <TYPE_MCA>( dram );
    }
    else if ( TYPE_MEM_PORT == trgtType )
    {
        dramSymbol = isX4 ? nibble2Symbol<TYPE_MEM_PORT>( dram )
                          : byte2Symbol  <TYPE_MEM_PORT>( dram );
    }
    else
    {
        PRDF_ERR( "MemSymbol::getDramSymbol: Invalid target type" );
        PRDF_ASSERT( false );
    }

    return dramSymbol;
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getGalois() const
{
    return symbol2Galois[iv_symbol];
}

//------------------------------------------------------------------------------

void MemSymbol::updateSpared(const MemSymbol & i_sp0,
                             const MemSymbol & i_sp1,
                             const MemSymbol & i_ecc)
{
    if (!iv_isDramSpared)
    {
        if ( ( i_sp0.isValid() && (i_sp0.getDram() == getDram()) ) ||
             ( i_sp1.isValid() && (i_sp1.getDram() == getDram()) ) )
        {
            setDramSpared();
        }
    }

    if ( (!iv_isEccSpared) &&
         ( i_ecc.isValid() && (i_ecc.getDram() == getDram())) )
    {
        setEccSpared();
    }
}

//------------------------------------------------------------------------------
//                       Symbol Accessor Functions
//------------------------------------------------------------------------------

template<>
uint32_t getMemReadSymbol<TYPE_MCA>( ExtensibleChip * i_chip,
                                     const MemRank & i_rank,
                                     MemSymbol & o_sym1, MemSymbol & o_sym2 )
{
    #define PRDF_FUNC "[getMemReadSymbol<TYPE_MCA>] "

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

    // o_sym2 is just a placeholder for TYPE_MBA
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

        MemSymbol sp0, sp1, ecc;
        o_rc = mssGetSteerMux<TYPE_MBA>( i_chip->getTrgt(), i_rank,
                                         sp0, sp1, ecc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed. HUID: 0x%08x "
                      "rank: 0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }
        o_sym1.updateSpared(sp0, sp1, ecc);

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t getMemReadSymbol<TYPE_MEM_PORT>( ExtensibleChip * i_chip,
                                          const MemRank & i_rank,
                                          MemSymbol & o_sym1,
                                          MemSymbol & o_sym2 )
{
    #define PRDF_FUNC "[getMemReadSymbol<TYPE_MEM_PORT>] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEM_PORT == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    o_sym1 = o_sym2 = MemSymbol(); // both initially invalid

    do
    {
        // Get the NCE/TCE galois and mask from hardware.
        ExtensibleChip * ocmbChip = getConnectedParent(i_chip, TYPE_OCMB_CHIP);

        SCAN_COMM_REGISTER_CLASS * reg = ocmbChip->getRegister("MBSEVR0");
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBSEVR0: "
                      "ocmbChip=0x%08x", ocmbChip->getHuid() );
            break;
        }

        // MBSEVR[0:7]   = mainline NCE galois field
        // MBSEVR[8:15]  = mainline NCE mask field
        // MBSEVR[16:23] = mainline TCE galois field
        // MBSEVR[24:31] = mainline TCE mask field
        uint8_t nceGalois = reg->GetBitFieldJustified( 0,  8 );
        uint8_t nceMask   = reg->GetBitFieldJustified( 8,  8 );
        uint8_t tceGalois = reg->GetBitFieldJustified( 16, 8 );
        uint8_t tceMask   = reg->GetBitFieldJustified( 24, 8 );

        // Get the NCE/TCE symbol.
        o_sym1 = MemSymbol::fromGalois( i_chip->getTrgt(), i_rank,
                                        nceGalois, nceMask );
        o_sym2 = MemSymbol::fromGalois( i_chip->getTrgt(), i_rank,
                                        tceGalois, tceMask );

        MemSymbol sp0, sp1, ecc;
        o_rc = mssGetSteerMux<TYPE_MEM_PORT>( i_chip->getTrgt(), i_rank,
                                              sp0, sp1, ecc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed. HUID: 0x%08x "
                      "rank: 0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }
        o_sym1.updateSpared(sp0, sp1, ecc);
        o_sym2.updateSpared(sp0, sp1, ecc);

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF
