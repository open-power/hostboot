/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemSymbol.C $           */
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
using namespace PARSERUTILS;

//##############################################################################
//                           class MemSymbol
//##############################################################################

MemSymbol::MemSymbol( TARGETING::TargetHandle_t i_trgt, const MemRank & i_rank,
                      uint8_t i_symbol ) :
    iv_trgt(i_trgt), iv_rank(i_rank), iv_symbol(i_symbol),
    iv_pins(0), iv_isSpareDram0(false), iv_isSpareDram1(false)
{
    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_trgt) );
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

    return MemSymbol( i_trgt, i_rank, symbol );
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getDq() const
{
    uint8_t dq = OCMB_DQS_PER_DIMM;
    TYPE trgtType = getTargetType( iv_trgt );

    if ( TYPE_OCMB_CHIP == trgtType )
    {
        dq = symbol2Dq<TYPE_OCMB_CHIP>( iv_symbol );
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

    if ( TYPE_OCMB_CHIP == trgtType )
    {
        portSlct = symbol2PortSlct<TYPE_OCMB_CHIP>( iv_symbol );
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
    bool isX4 = true;

    if ( TYPE_OCMB_CHIP == trgtType )
    {
        TargetHandle_t dimm = getConnectedDimm(iv_trgt, iv_rank, getPortSlct());
        isX4 = isDramWidthX4( dimm );
        dram = isX4 ? symbol2Nibble<TYPE_OCMB_CHIP>( iv_symbol )
                    : symbol2Byte  <TYPE_OCMB_CHIP>( iv_symbol );
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

    bool isX4 = true;
    if ( TYPE_OCMB_CHIP == getTargetType(iv_trgt) )
    {
        TargetHandle_t dimm = getConnectedDimm(iv_trgt, iv_rank, getPortSlct());
        isX4 = isDramWidthX4( dimm );
    }
    else
    {
        isX4 = isDramWidthX4( iv_trgt );
    }

    uint8_t l_dramWidth = ( isX4 ) ? 4 : 8;
    uint8_t l_dram = getDq() / l_dramWidth; // (x8: 0-9, x4: 0-19)

    // Adjust for spares
    if ( isDramSpared() )
    {
        bool isX4 = true;
        TYPE trgtType = getTargetType( iv_trgt );
        if ( TYPE_OCMB_CHIP == trgtType )
        {
            TargetHandle_t dimm = getConnectedDimm(iv_trgt, iv_rank,
                                                   getPortSlct());
            isX4 = isDramWidthX4( dimm );
        }
        else
        {
            PRDF_ERR( "MemSymbol::getDramSpareAdjusted: Invalid target type" );
            PRDF_ASSERT( false );
        }

        const uint8_t X4_DRAM_SPARE_LOWER = 18;
        const uint8_t X4_DRAM_SPARE_UPPER = 19;
        const uint8_t X8_DRAM_SPARE = 9;
        if ( isX4 )
        {
            l_dram = ( isDramSpared0() ) ? X4_DRAM_SPARE_LOWER
                                         : X4_DRAM_SPARE_UPPER;
        }
        else
        {
            l_dram = X8_DRAM_SPARE;
        }
    }

    return l_dram;

}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getDramPins() const
{
    TYPE trgtType = getTargetType( iv_trgt );
    bool isX4 = true;
    if ( TYPE_OCMB_CHIP == trgtType )
    {
        TargetHandle_t dimm = getConnectedDimm(iv_trgt, iv_rank, getPortSlct());
        isX4 = isDramWidthX4( dimm );
    }
    else
    {
        isX4 = isDramWidthX4( iv_trgt );
    }

    uint32_t dps = 0;
    uint32_t spd = 0;

    if ( TYPE_OCMB_CHIP == trgtType )
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
    bool isX4 = true;
    if ( TYPE_OCMB_CHIP == trgtType )
    {
        TargetHandle_t dimm = getConnectedDimm(iv_trgt, iv_rank, getPortSlct());
        isX4 = isDramWidthX4( dimm );
    }
    else
    {
        isX4 = isDramWidthX4( iv_trgt );
    }
    uint8_t dram  = getDram();

    if ( TYPE_OCMB_CHIP == trgtType )
    {
        dramSymbol = isX4 ? nibble2Symbol<TYPE_OCMB_CHIP>( dram )
                          : byte2Symbol  <TYPE_OCMB_CHIP>( dram );
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
                             const MemSymbol & i_sp1)
{
    if (!isDramSpared())
    {
        if ( i_sp0.isValid() && (i_sp0.getDram() == getDram()) )
        {
            setDramSpared0();
        }
        else if ( i_sp1.isValid() && (i_sp1.getDram() == getDram()) )
        {
            setDramSpared1();
        }
    }
}

//------------------------------------------------------------------------------
//                       Symbol Accessor Functions
//------------------------------------------------------------------------------

template<>
uint32_t getMemReadSymbol<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                           const MemRank & i_rank,
                                           MemSymbol & o_sym1,
                                           MemSymbol & o_sym2 )
{
    #define PRDF_FUNC "[getMemReadSymbol<TYPE_OCMB_CHIP>] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    o_sym1 = o_sym2 = MemSymbol(); // both initially invalid

    do
    {
        // Get the NCE/TCE galois and mask from hardware.
        SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister("MBSEVR0");
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBSEVR0: "
                      "i_chip=0x%08x", i_chip->getHuid() );
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

        MemSymbol sp0, sp1;
        o_rc = mssGetSteerMux<TYPE_OCMB_CHIP>( i_chip->getTrgt(), i_rank,
                                               sp0, sp1 );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed. HUID: 0x%08x "
                      "rank: 0x%02x", i_chip->getHuid(), i_rank.getKey() );
            break;
        }
        o_sym1.updateSpared(sp0, sp1);
        o_sym2.updateSpared(sp0, sp1);

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF
