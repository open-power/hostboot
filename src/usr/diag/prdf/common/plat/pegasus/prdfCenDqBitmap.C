/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenDqBitmap.C $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

/** @file  prdfCenDqBitmap.C */

#include <prdfCenDqBitmap.H>

#include <UtilHash.H>
#include <iipServiceDataCollector.h>

namespace PRDF
{

using namespace PlatServices;

int32_t CenDqBitmap::badDqs( uint8_t i_portSlct, bool & o_badDqs ) const
{
    #define PRDF_FUNC "[CenDqBitmap::badDqs] "

    int32_t o_rc = SUCCESS;

    o_badDqs = false;

    do
    {
        if ( PORT_SLCT_PER_MBA <= i_portSlct )
        {
            PRDF_ERR( PRDF_FUNC"Invalid parameter: i_portSlct=%d", i_portSlct );
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
            PRDF_ERR( PRDF_FUNC"Invalid parameter: i_dq=%d", i_dq );
            o_rc = FAIL; break;
        }

        if ( PORT_SLCT_PER_MBA <= i_portSlct )
        {
            PRDF_ERR( PRDF_FUNC"Invalid parameter: i_portSlct=%d", i_portSlct );
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

int32_t CenDqBitmap::setSymbol( uint8_t i_symbol, uint8_t i_pins )
{
    #define PRDF_FUNC "[CenDqBitmap::setSymbol] "

    int32_t o_rc = SUCCESS;

    do
    {
        uint8_t evenDq   = CenSymbol::symbol2CenDq(    i_symbol );
        uint8_t portSlct = CenSymbol::symbol2PortSlct( i_symbol );
        if ( DQS_PER_DIMM <= evenDq || PORT_SLCT_PER_MBA <= portSlct )
        {
            PRDF_ERR( PRDF_FUNC"Invalid parameter: i_symbol=%d", i_symbol );
            o_rc = FAIL; break;
        }

        uint8_t byteIdx = evenDq / DQS_PER_BYTE;
        uint8_t bitIdx  = evenDq % DQS_PER_BYTE;

        i_pins &= 0x3; // limit to 2 bits
        uint32_t shift = (((DQS_PER_BYTE-1) - bitIdx) % 2) * 2; // 0,2,4,6
        iv_data[portSlct][byteIdx] |= i_pins << shift;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenDqBitmap::setDram( uint8_t i_symbol, uint8_t i_pins )
{
    #define PRDF_FUNC "[CenDqBitmap::setDram] "

    int32_t o_rc = SUCCESS;

    do
    {
        uint8_t evenDq   = CenSymbol::symbol2CenDq(    i_symbol );
        uint8_t portSlct = CenSymbol::symbol2PortSlct( i_symbol );
        if ( DQS_PER_DIMM <= evenDq || PORT_SLCT_PER_MBA <= portSlct )
        {
            PRDF_ERR( PRDF_FUNC"Invalid parameter: i_symbol=%d", i_symbol );
            o_rc = FAIL; break;
        }

        uint8_t byteIdx = evenDq / DQS_PER_BYTE;
        uint8_t bitIdx  = evenDq % DQS_PER_BYTE;

        if ( isDramWidthX4(iv_mba) )
        {
            i_pins &= 0xf; // limit to 4 bits
            uint32_t shift = (((DQS_PER_BYTE-1) - bitIdx) % 4) * 4; // 0,4
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

int32_t CenDqBitmap::isChipMark( uint8_t i_symbol, bool & o_cm )
{
    #define PRDF_FUNC "[CenDqBitmap::isChipMark] "

    int32_t o_rc = SUCCESS;
    o_cm = false;

    do
    {
        uint8_t evenDq   = CenSymbol::symbol2CenDq(    i_symbol );
        uint8_t portSlct = CenSymbol::symbol2PortSlct( i_symbol );
        if ( DQS_PER_DIMM <= evenDq || PORT_SLCT_PER_MBA <= portSlct )
        {
            PRDF_ERR( PRDF_FUNC"Invalid parameter: i_symbol=%d", i_symbol );
            o_rc = FAIL; break;
        }

        uint8_t byteIdx = evenDq / DQS_PER_BYTE;
        uint8_t bitIdx  = evenDq % DQS_PER_BYTE;

        uint8_t pins   = 0xff;
        uint8_t cmData = iv_data[portSlct][byteIdx];

        if ( isDramWidthX4(iv_mba) )
        {
            pins = 0xf; // limit to 4 bits
            uint8_t shift = (((DQS_PER_BYTE-1) - bitIdx) % 4) * 4; // 0,4
            cmData = (cmData >> shift) & 0xf;
        }

        o_cm = ( cmData == pins );

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
            PRDF_ERR( PRDF_FUNC"Invalid parameter: i_portSlct=%d", i_portSlct );
            o_rc = FAIL; break;
        }

        if ( isDramWidthX4(iv_mba) )
        {
            i_pins &= 0xf; // limit to 4 bits
            // TODO: RTC 68096 Need to check if this is correct behavior.
            iv_data[i_portSlct][DIMM_DQ_RANK_BITMAP_SIZE-1] |= i_pins << 4;
        }
        else
        {
            i_pins &= 0xff; // limit to 8 bits
            iv_data[i_portSlct][DIMM_DQ_RANK_BITMAP_SIZE-1] |= i_pins;
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
        // TODO: RTC 68096 Need to add x4 ECC support.

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenDqBitmap::isDramSpareAvailable( uint8_t i_portSlct,
                                           bool & o_available )
{
    #define PRDF_FUNC "[CenDqBitmap::isDramSpareAvailable] "

    int32_t o_rc = SUCCESS;

    o_available = false;

    do
    {
        if ( PORT_SLCT_PER_MBA <= i_portSlct )
        {
            PRDF_ERR( PRDF_FUNC"Invalid parameter: i_portSlct=%d", i_portSlct );
            o_rc = FAIL; break;
        }

        if ( isDramWidthX4(iv_mba) )
        {
            // TODO: RTC 68096 Need to add x4 ECC support.
        }
        else
        {
            o_available =
                      ( 0 == iv_data[i_portSlct][DIMM_DQ_RANK_BITMAP_SIZE-1] );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void CenDqBitmap::getCaptureData( CaptureData & o_cd ) const
{
    uint8_t rank   = iv_rank.flatten();
    size_t sz_rank = sizeof(rank);

    size_t sz_capData = sz_rank + sizeof(iv_data);

    // Adjust the size for endianess.
    const size_t sz_word = sizeof(CPU_WORD);
    sz_capData = ((sz_capData + sz_word-1) / sz_word) * sz_word;

    uint8_t capData[sz_capData];
    memset( capData, 0x00, sz_capData );

    capData[0] = rank;
    memcpy( &capData[1], iv_data, sizeof(iv_data) );

    // Fix endianess issues with non PPC machines.
    for ( uint32_t i = 0; i < (sz_capData/sz_word); i++ )
        ((CPU_WORD*)capData)[i] = htonl(((CPU_WORD*)capData)[i]);

    BIT_STRING_ADDRESS_CLASS bs ( 0, sz_capData*8, (CPU_WORD *) &capData );
    o_cd.Add( iv_mba, Util::hashString("MBA_BAD_DQ_BITMAP"), bs );
}

} // end namespace PRDF

