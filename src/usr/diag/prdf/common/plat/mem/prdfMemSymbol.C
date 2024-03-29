/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemSymbol.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2023                        */
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
    iv_pins(1), iv_isSpareDram0(false), iv_isSpareDram1(false)
{
    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( TYPE_MEM_PORT == getTargetType(i_trgt) );
}

//------------------------------------------------------------------------------

MemSymbol MemSymbol::fromGalois( TargetHandle_t i_trgt, const MemRank & i_rank,
                                 uint8_t i_galois, uint8_t i_mask )
{
    #define PRDF_FUNC "[MemSymbol::fromGalois] "

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

    MemSymbol o_sym( i_trgt, i_rank, symbol );

    MemSymbol sp0, sp1;
    int32_t rc = mssGetSteerMux<TYPE_MEM_PORT>( i_trgt, i_rank, sp0, sp1 );
    if ( SUCCESS != rc )
    {
        PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed. HUID: 0x%08x "
                  "rank: 0x%02x", getHuid(i_trgt), i_rank.getKey() );
    }
    else
    {
        o_sym.updateSpared(sp0, sp1);
    }

    return o_sym;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

MemSymbol MemSymbol::fromSymbol( TARGETING::TargetHandle_t i_trgt,
                                 const MemRank & i_rank, uint8_t i_symbol )
{
    #define PRDF_FUNC "[MemSymbol::fromSymbol] "

    MemSymbol o_sym( i_trgt, i_rank, i_symbol );
    MemSymbol sp0, sp1;

    int32_t rc = mssGetSteerMux<TARGETING::TYPE_MEM_PORT>( i_trgt, i_rank,
                                                           sp0, sp1 );
    if ( SUCCESS != rc )
    {
        PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed. HUID: 0x%08x "
                  "rank: 0x%02x", getHuid(i_trgt), i_rank.getKey() );
    }
    else
    {
        o_sym.updateSpared(sp0, sp1);
    }

    return o_sym;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

MemSymbol MemSymbol::fromSparedSymbol( TARGETING::TargetHandle_t i_trgt,
                                       const MemRank & i_rank, uint8_t i_symbol,
                                       bool i_sp0, bool i_sp1 )
{
    #define PRDF_FUNC "[MemSymbol::fromSparedSymbol] "

    MemSymbol o_sym( i_trgt, i_rank, i_symbol );

    if ( i_sp0 )
    {
        o_sym.setDramSpared0();
    }
    else if ( i_sp1 )
    {
        o_sym.setDramSpared1();
    }

    return o_sym;

    #undef PRDF_FUNC
}
//------------------------------------------------------------------------------

uint8_t MemSymbol::getDq() const
{
    uint8_t dq = DQS_PER_DIMM;
    TYPE trgtType = getTargetType( iv_trgt );

    if ( TYPE_MEM_PORT == trgtType )
    {
        TargetHandle_t dimm = getConnectedChild(iv_trgt, TYPE_DIMM,
                                                iv_rank.getDimmSlct());
        bool isX4 = isDramWidthX4( dimm );
        dq = symbol2Dq<TYPE_OCMB_CHIP>( iv_symbol, isX4 );
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

    if ( TYPE_MEM_PORT == trgtType )
    {
        portSlct = iv_trgt->getAttr<ATTR_REL_POS>();
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

    if ( TYPE_MEM_PORT == trgtType )
    {
        TargetHandle_t dimm = getConnectedChild(iv_trgt, TYPE_DIMM,
                                                iv_rank.getDimmSlct());
        isX4 = isDramWidthX4( dimm );
        dram = symbol2Dram<TYPE_OCMB_CHIP>( iv_symbol, isX4 );
    }
    else
    {
        PRDF_ERR( "MemSymbol::getDram: Invalid target type" );
        PRDF_ASSERT( false );
    }

    return dram;
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getDramSpareAdjusted() const
{
    uint8_t dram = getDram();

    // Adjust for spares
    if ( isDramSpared() )
    {
        bool isX4 = true;
        TYPE trgtType = getTargetType( iv_trgt );
        if ( TYPE_MEM_PORT == trgtType )
        {
            TargetHandle_t dimm = getConnectedChild(iv_trgt, TYPE_DIMM,
                                                    iv_rank.getDimmSlct());
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
            dram = ( isDramSpared0() ) ? X4_DRAM_SPARE_LOWER
                                       : X4_DRAM_SPARE_UPPER;
        }
        else
        {
            dram = X8_DRAM_SPARE;
        }
    }

    return dram;
}

//------------------------------------------------------------------------------

uint8_t MemSymbol::getDramPins() const
{
    TYPE trgtType = getTargetType( iv_trgt );
    bool isX4 = true;
    if ( TYPE_MEM_PORT == trgtType )
    {
        TargetHandle_t dimm = getConnectedChild(iv_trgt, TYPE_DIMM,
                                                iv_rank.getDimmSlct());
        isX4 = isDramWidthX4( dimm );
    }
    else
    {
        isX4 = isDramWidthX4( iv_trgt );
    }

    uint32_t dps = 0;
    uint32_t spd = 0;

    if ( TYPE_MEM_PORT == trgtType )
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
    if ( TYPE_MEM_PORT == trgtType )
    {
        TargetHandle_t dimm = getConnectedChild(iv_trgt, TYPE_DIMM,
                                                iv_rank.getDimmSlct());
        isX4 = isDramWidthX4( dimm );
    }
    else
    {
        isX4 = isDramWidthX4( iv_trgt );
    }
    uint8_t dram  = getDram();

    if ( TYPE_MEM_PORT == trgtType )
    {
        dramSymbol = dram2Symbol<TYPE_OCMB_CHIP>( dram, isX4 );
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
uint32_t getMemReadSymbol<TYPE_OCMB_CHIP>( ExtensibleChip * i_ocmb,
                                           const MemRank & i_rank,
                                           uint8_t i_port,
                                           MemSymbol & o_sym1,
                                           MemSymbol & o_sym2 )
{
    #define PRDF_FUNC "[getMemReadSymbol<TYPE_OCMB_CHIP>] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_ocmb->getType() );

    uint32_t o_rc = SUCCESS;

    o_sym1 = o_sym2 = MemSymbol(); // both initially invalid

    do
    {
        // Get the NCE/TCE galois and mask from hardware.
        SCAN_COMM_REGISTER_CLASS * reg = i_ocmb->getRegister("MBSEVR0");
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBSEVR0: "
                      "i_ocmb=0x%08x", i_ocmb->getHuid() );
            break;
        }

        // MBSEVR[0:7]   = port0 mainline NCE galois field
        // MBSEVR[8:15]  = port0 mainline NCE mask field
        // MBSEVR[16:23] = port0 mainline TCE galois field
        // MBSEVR[24:31] = port0 mainline TCE mask field
        // Odyssey OCMBs only:
        // MBSEVR[32:39] = port1 mainline NCE galois field
        // MBSEVR[40:47] = port1 mainline NCE mask field
        // MBSEVR[48:55] = port1 mainline TCE galois field
        // MBSEVR[56:63] = port1 mainline TCE mask field

        uint8_t nceGalois = reg->GetBitFieldJustified((i_port ? 32 :  0), 8);
        uint8_t nceMask   = reg->GetBitFieldJustified((i_port ? 40 :  8), 8);
        uint8_t tceGalois = reg->GetBitFieldJustified((i_port ? 48 : 16), 8);
        uint8_t tceMask   = reg->GetBitFieldJustified((i_port ? 56 : 24), 8);

        TargetHandle_t memport = getConnectedChild(i_ocmb->getTrgt(),
                                                   TYPE_MEM_PORT, i_port);

        // Get the NCE/TCE symbol.
        o_sym1 = MemSymbol::fromGalois( memport, i_rank, nceGalois, nceMask );
        o_sym2 = MemSymbol::fromGalois( memport, i_rank, tceGalois, tceMask );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF
