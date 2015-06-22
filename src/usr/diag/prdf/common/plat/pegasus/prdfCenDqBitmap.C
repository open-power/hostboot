/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenDqBitmap.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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

/** @file  prdfCenDqBitmap.C */

#include <prdfCenDqBitmap.H>

#include <UtilHash.H>
#include <iipServiceDataCollector.h>
#include <prdfParserUtils.H>

namespace PRDF
{

using namespace PlatServices;
using namespace PARSERUTILS;
using namespace fapi; // for spare dram config

bool CenDqBitmap::badDqs() const
{
    bool o_badDqs = false;

    for ( uint32_t i = 0; i < PORT_SLCT_PER_MBA; i++ )
    {
        for ( uint32_t j = 0; j < DIMM_DQ_RANK_BITMAP_SIZE; j++ )
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

int32_t CenDqBitmap::badDqs( uint8_t i_portSlct, bool & o_badDqs ) const
{
    #define PRDF_FUNC "[CenDqBitmap::badDqs] "

    int32_t o_rc = SUCCESS;

    o_badDqs = false;

    do
    {
        if ( PORT_SLCT_PER_MBA <= i_portSlct )
        {
            PRDF_ERR( PRDF_FUNC "Invalid parameter: i_portSlct=%d", i_portSlct );
            o_rc = FAIL; break;
        }

        for ( uint32_t j = 0; j < DIMM_DQ_RANK_BITMAP_SIZE; j++ )
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

int32_t CenDqBitmap::setDq( uint8_t i_dq, uint8_t i_portSlct )
{
    #define PRDF_FUNC "[CenDqBitmap::setDq] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( DQS_PER_DIMM <= i_dq )
        {
            PRDF_ERR( PRDF_FUNC "Invalid parameter: i_dq=%d", i_dq );
            o_rc = FAIL; break;
        }

        if ( PORT_SLCT_PER_MBA <= i_portSlct )
        {
            PRDF_ERR( PRDF_FUNC "Invalid parameter: i_portSlct=%d", i_portSlct );
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

int32_t CenDqBitmap::setSymbol( const CenSymbol & i_symbol, uint8_t i_pins )
{
    #define PRDF_FUNC "[CenDqBitmap::setSymbol] "

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

        i_pins &= 0x3; // limit to 2 bits
        uint32_t shift = (DQS_PER_BYTE-1) - bitIdx;
        shift = (shift / DQS_PER_SYMBOL) * DQS_PER_SYMBOL; // 0,2,4,6
        iv_data[portSlct][byteIdx] |= i_pins << shift;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenDqBitmap::setDram( const CenSymbol & i_symbol, uint8_t i_pins )
{
    #define PRDF_FUNC "[CenDqBitmap::setDram] "

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

int32_t CenDqBitmap::isChipMark( const CenSymbol & i_symbol, bool & o_cm )
{
    #define PRDF_FUNC "[CenDqBitmap::isChipMark] "

    int32_t o_rc = SUCCESS;
    o_cm = false;

    do
    {
        uint8_t portSlct, byteIdx, bitIdx;
        o_rc = getPortByteBitIdx( i_symbol, portSlct, byteIdx, bitIdx );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getPortByteBitIdx() failed" );
            break;
        }

        // When PRD marks a DRAM as 'bad', it will set all bits on the DRAM in
        // VPD. Due to a bug in DRAM init training, the training procedure will
        // change the VPD to 0xee (x8) or 0xe (x4). Therefore, PRD will need to
        // compare against the value the procedure sets in order to confirm a
        // chip mark has been verified on this DRAM.

        uint8_t pinMsk = 0xee;
        uint8_t cmData = iv_data[portSlct][byteIdx];

        if ( iv_x4Dram )
        {
            pinMsk = 0xe; // limit to 4 bits
            uint32_t shift = (DQS_PER_BYTE-1) - bitIdx;
            shift = (shift / DQS_PER_NIBBLE) * DQS_PER_NIBBLE; // 0,4
            cmData = (cmData >> shift) & 0xf;
        }

        o_cm = ( (cmData & pinMsk) == pinMsk );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenDqBitmap::setDramSpare( uint8_t i_portSlct, uint8_t i_pins )
{
    #define PRDF_FUNC "[CenDqBitmap::setDramSpare] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( PORT_SLCT_PER_MBA <= i_portSlct )
        {
            PRDF_ERR( PRDF_FUNC "Invalid parameter: i_portSlct=%d", i_portSlct );
            o_rc = FAIL; break;
        }

        uint8_t spareConfig = ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE;
        o_rc = getDimmSpareConfig( iv_mba , iv_rank, i_portSlct,
                                   spareConfig );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getDimmSpareConfig() failed" );
            o_rc = FAIL; break;
        }

        if ( ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE == spareConfig )
        {
            PRDF_ERR( PRDF_FUNC "DRAM Spare is not avaiable" );
            o_rc = FAIL; break;
        }

        if ( iv_x4Dram )
        {
            i_pins &= 0xf; // limit to 4 bits

            if ( ENUM_ATTR_VPD_DIMM_SPARE_LOW_NIBBLE == spareConfig )
            {
                i_pins = i_pins << DQS_PER_NIBBLE;
            }
            iv_data[i_portSlct][DRAM_SPARE_BYTE] |= i_pins;
        }
        else
        {
            i_pins &= 0xff; // limit to 8 bits
            iv_data[i_portSlct][DRAM_SPARE_BYTE] |= i_pins;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenDqBitmap::setEccSpare( uint8_t i_pins )
{

    #define PRDF_FUNC "[CenDqBitmap::setEccSpare] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( !iv_x4Dram )
        {
            PRDF_ERR( PRDF_FUNC "MBA 0x %08x does not support x4 ECC spare",
                      getHuid(iv_mba) );
            o_rc = FAIL; break;
        }

        i_pins &= 0xf; // limit to 4 bits
        iv_data[ECC_SPARE_PORT][ECC_SPARE_BYTE] |= i_pins;

    } while( 0 );

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenDqBitmap::isSpareAvailable( uint8_t i_portSlct,
                                       bool & o_dramSpare, bool & o_eccSpare )
{
    #define PRDF_FUNC "[CenDqBitmap::isDramSpareAvailable] "

    int32_t o_rc = SUCCESS;

    o_dramSpare = false;
    o_eccSpare  = false;

    do
    {
        if ( PORT_SLCT_PER_MBA <= i_portSlct )
        {
            PRDF_ERR( PRDF_FUNC "Invalid parameter: i_portSlct=%d", i_portSlct );
            o_rc = FAIL; break;
        }

        uint8_t spareConfig = ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE;
        o_rc = getDimmSpareConfig( iv_mba , iv_rank, i_portSlct,
                                   spareConfig );
        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getDimmSpareConfig() failed" );
            break;
        }

        uint8_t spareDqBits = iv_data[i_portSlct][DRAM_SPARE_BYTE];

        if ( iv_x4Dram )
        {
            // Check for DRAM spare
            if ( ENUM_ATTR_VPD_DIMM_SPARE_LOW_NIBBLE  == spareConfig )
            {
                o_dramSpare = ( 0 == ( spareDqBits & 0xf0 ) );
            }
            else if ( ENUM_ATTR_VPD_DIMM_SPARE_HIGH_NIBBLE  == spareConfig )
            {
                o_dramSpare = ( 0 == ( spareDqBits & 0x0f ) );
            }

            // Check for ECC spare
            uint8_t eccDqBits = iv_data[ECC_SPARE_PORT][ECC_SPARE_BYTE];
            o_eccSpare = ( 0 == (eccDqBits & 0x0f) );
        }
        else
        {
            if ( ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE == spareConfig )
            {
                // spare is not available.
                o_dramSpare = false;
            }
            else
                o_dramSpare = ( 0 == spareDqBits );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void CenDqBitmap::getCaptureData( CaptureData & o_cd ) const
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

    BIT_STRING_ADDRESS_CLASS bs ( 0, sz_capData*8, (CPU_WORD *) &capData );
    o_cd.Add( iv_mba, Util::hashString("BAD_DQ_BITMAP"), bs );
}

//------------------------------------------------------------------------------

int32_t CenDqBitmap::getPortByteBitIdx( const CenSymbol & i_symbol,
                                        uint8_t & o_portSlct,
                                        uint8_t & o_byteIdx,
                                        uint8_t & o_bitIdx ) const
{
    #define PRDF_FUNC "[CenDqBitmap::getPortByteBitIdx] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( !i_symbol.isValid() )
        {
            PRDF_ERR( PRDF_FUNC "i_symbol is invalid" );
            o_rc = FAIL; break;
        }

        o_portSlct = i_symbol.getPortSlct();
        o_byteIdx  = i_symbol.getEvenDq() / DQS_PER_BYTE;
        o_bitIdx   = i_symbol.getEvenDq() % DQS_PER_BYTE;

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

} // end namespace PRDF

