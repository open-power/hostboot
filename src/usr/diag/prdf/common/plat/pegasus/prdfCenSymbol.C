/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenSymbol.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

#include <prdfCenSymbol.H>

#include <prdfPlatServices.H>
#include <prdfTrace.H>
#include <prdfCenMemUtils.H>
#include <prdfParserUtils.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
using namespace CEN_SYMBOL;
using namespace PARSERUTILS;

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
//                           class CenSymbol
//##############################################################################

CenSymbol CenSymbol::fromSymbol( TargetHandle_t i_mba, const CenRank & i_rank,
                                 uint8_t i_symbol, uint8_t i_pins )
{
    #define PRDF_FUNC "[CenSymbol::fromSymbol] "

    CenSymbol o_symbol; // default contructor is invalid.

    do
    {
        if ( TYPE_MBA != getTargetType(i_mba) )
        {
            PRDF_ERR( PRDF_FUNC"i_mba is invalid: i_mba=0x%08x",
                      getHuid(i_mba) );
            break;
        }

        WiringType wiringType = WIRING_INVALID;
        int32_t l_rc = getWiringType( i_mba, i_rank, wiringType );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"getWiringType() failed" );
            break;
        }

        if ( BOTH_SYMBOL_DQS < i_pins )
        {
            PRDF_ERR( PRDF_FUNC"i_pins is invalid" );
            break;
        }

        o_symbol = CenSymbol ( i_mba, i_rank, wiringType, i_symbol, i_pins,
                               isDramWidthX4(i_mba) );

    } while (0);

    return o_symbol;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

CenSymbol CenSymbol::fromDimmDq( TargetHandle_t i_mba, const CenRank & i_rank,
                                 uint8_t i_dimmDq, uint8_t i_portSlct )
{
    #define PRDF_FUNC "[CenSymbol::fromDimmDq] "

    CenSymbol o_symbol; // default contructor is invalid.

    do
    {
        if ( TYPE_MBA != getTargetType(i_mba) )
        {
            PRDF_ERR( PRDF_FUNC"i_mba is invalid" );
            break;
        }

        WiringType wiringType = WIRING_INVALID;
        int32_t l_rc = getWiringType( i_mba, i_rank, wiringType );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"getWiringType() failed" );
            break;
        }

        uint8_t symbol;
        l_rc = getSymbol( i_rank, wiringType, i_dimmDq, i_portSlct, symbol );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"getSymbol() failed" );
            break;
        }

        uint8_t pins = (0 == (i_dimmDq & ODD_SYMBOL_DQ)) ? EVEN_SYMBOL_DQ :
                                                           ODD_SYMBOL_DQ;

        o_symbol = CenSymbol ( i_mba, i_rank, wiringType, symbol, pins,
                               isDramWidthX4(i_mba) );

    } while (0);

    return o_symbol;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

CenSymbol CenSymbol::fromGalois( TargetHandle_t i_mba, const CenRank & i_rank,
                                 uint8_t i_galois, uint8_t i_mask )
{
    #define PRDF_FUNC "[CenSymbol::fromGalois] "

    CenSymbol o_symbol; // default contructor is invalid.

    do
    {
        if ( TYPE_MBA != getTargetType(i_mba) )
        {
            PRDF_ERR( PRDF_FUNC"i_mba=0x%08x is invalid", getHuid(i_mba) );
            break;
        }

        WiringType wiringType = WIRING_INVALID;
        int32_t l_rc = getWiringType( i_mba, i_rank, wiringType );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"getWiringType() failed" );
            break;
        }

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
        if ( 0 != (i_mask & 0xaa) ) pins |= EVEN_SYMBOL_DQ;
        if ( 0 != (i_mask & 0x55) ) pins |= ODD_SYMBOL_DQ;

        // Create symbol object.
        o_symbol = CenSymbol ( i_mba, i_rank, wiringType, symbol, pins,
                               isDramWidthX4(i_mba) );

    } while (0);

    return o_symbol;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenSymbol::getWiringType( TargetHandle_t i_mba, const CenRank & i_rank,
                                  WiringType & o_type )
{
    #define  PRDF_FUNC "CenSymbol::getWiringType "

    int32_t o_rc = SUCCESS;
    o_type = WIRING_INVALID;

    do
    {
        bool isCenDimm = false;
        o_rc = isMembufOnDimm( i_mba, isCenDimm );

        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC" isMembufOnDimm() Failed " );
            break;
        }

        if( isCenDimm )
        {
            //It is a centaur DIMM. Let us find out card type
            o_rc = getMemBufRawCardType( i_mba, o_type );

            if( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"getMemBufRawCardType returned error" );
                o_type = WIRING_INVALID;
                break;
            }
        }
        //else it is a IS DIMM
    }while(0);

    return o_rc;

    #undef  PRDF_FUNC
}

//------------------------------------------------------------------------------

uint8_t CenSymbol::getDramPins() const
{
    uint32_t spd = iv_x4Dram ? SYMBOLS_PER_X4DRAM : SYMBOLS_PER_X8DRAM;

    return iv_pins << (((spd - 1) - (iv_symbol % spd)) * DQS_PER_SYMBOL);
}

//------------------------------------------------------------------------------

int32_t CenSymbol::getSymbol( const CenRank & i_rank, WiringType i_wiringType,
                              uint8_t i_dimmDq, uint8_t i_portSlct,
                              uint8_t & o_symbol )
{
    #define PRDF_FUNC "[CenSymbol::getSymbol] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( DQS_PER_DIMM <= i_dimmDq )
        {
            PRDF_ERR( PRDF_FUNC"i_dimmDq is invalid" );
            o_rc = FAIL; break;
        }

        if ( PORT_SLCT_PER_MBA <= i_portSlct )
        {
            PRDF_ERR( PRDF_FUNC"i_portSlct is invalid" );
            o_rc = FAIL; break;
        }

        // Get the Centaur DQ.
        uint8_t cenDq = i_dimmDq;

        // TODO: RTC 67376 Add wiring type support for IS DIMMs to convert from
        //       i_dimmDq to cenDq.

        o_symbol = cenDq2Symbol( cenDq, i_portSlct );

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_rank=M%dS%d i_wiringType=%d i_dimmDq=%d "
                  "i_portSlct=%d", i_rank.getMaster(), i_rank.getSlave(),
                  i_wiringType, i_dimmDq, i_portSlct );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenSymbol::setPins( uint8_t i_pins )
{
    #define PRDF_FUNC "[CenSymbol::setPins] "
    int32_t o_rc = SUCCESS;

    do
    {
        if ( BOTH_SYMBOL_DQS < i_pins )
        {
            PRDF_ERR( PRDF_FUNC"i_pins %u is invalid", i_pins );
            o_rc = FAIL;
            break;
        }

        iv_pins = i_pins;

    } while (0);

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint8_t CenSymbol::getEvenDq() const
{
    return symbol2CenDq( iv_symbol );
}

//------------------------------------------------------------------------------

uint8_t CenSymbol::getPortSlct() const
{
    return symbol2PortSlct( iv_symbol );
}

//------------------------------------------------------------------------------

uint8_t CenSymbol::getDramSymbol() const
{
    return dram2Symbol( symbol2Dram(iv_symbol, iv_x4Dram), iv_x4Dram);
}

uint8_t CenSymbol::getDram() const
{
    return symbol2Dram( iv_symbol, iv_x4Dram );
}

} // end namespace PRDF
