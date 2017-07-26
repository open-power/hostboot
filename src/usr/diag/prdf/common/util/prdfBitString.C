/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfBitString.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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

/** @file BitString.C
 *  @brief BitString and BitStringBuffer class Definitions
 */

#include <prdfBitString.H>

#include <prdfAssert.h>

#include <algorithm>

namespace PRDF
{
#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN)
namespace HOSTBOOT
{
#elif defined(PRDF_FSP_ERRL_PLUGIN)
namespace FSP
{
#endif


//##############################################################################
//                             BitString class
//##############################################################################

const uint32_t BitString::CPU_WORD_BIT_LEN = sizeof(CPU_WORD) * 8;

const CPU_WORD BitString::CPU_WORD_MASK = static_cast<CPU_WORD>(-1);

//------------------------------------------------------------------------------

CPU_WORD BitString::getField( uint32_t i_pos, uint32_t i_len ) const
{
    PRDF_ASSERT( nullptr != getBufAddr() );      // must to have a valid address
    PRDF_ASSERT( 0 < i_len );                    // must have at least one bit
    PRDF_ASSERT( i_len <= CPU_WORD_BIT_LEN );    // i_len length must be valid
    PRDF_ASSERT( i_pos + i_len <= getBitLen() ); // field must be within range

    // The returned value.
    CPU_WORD o_val = 0;

    // Get the relative address and position of the field.
    uint32_t relPos = 0;
    CPU_WORD * relAddr = getRelativePosition( relPos, i_pos );

    // The return value may cross two CPU_WORD addresses. Get length of each
    // chunk, mask to clear the right-handed bits, and the shift value to make
    // each chunk left-justified.
    uint32_t len0 = i_len, len1 = 0;
    if ( CPU_WORD_BIT_LEN < relPos + i_len )
    {
        len0 = CPU_WORD_BIT_LEN - relPos;
        len1 = i_len - len0;
    }

    CPU_WORD mask0 = CPU_WORD_MASK << (CPU_WORD_BIT_LEN - len0);
    CPU_WORD mask1 = CPU_WORD_MASK << (CPU_WORD_BIT_LEN - len1);

    uint32_t shift0 = relPos;
    uint32_t shift1 = CPU_WORD_BIT_LEN - relPos;

    // Get first half of the value.
    o_val = (*relAddr << shift0) & mask0;

    // Get the second half of the value, if needed
    if ( CPU_WORD_BIT_LEN < relPos + i_len )
    {
        ++relAddr;
        o_val |= (*relAddr & mask1) >> shift1;
    }

    return o_val;
}

//------------------------------------------------------------------------------

void BitString::setField( uint32_t i_pos, uint32_t i_len, CPU_WORD i_val )
{
    PRDF_ASSERT( nullptr != getBufAddr() );      // must to have a valid address
    PRDF_ASSERT( 0 < i_len );                    // must have at least one bit
    PRDF_ASSERT( i_len <= CPU_WORD_BIT_LEN );    // i_len length must be valid
    PRDF_ASSERT( i_pos + i_len <= getBitLen() ); // field must be within range

    // Get the relative address and position of the field.
    uint32_t relPos = 0;
    CPU_WORD * relAddr = getRelativePosition( relPos, i_pos );

    // The value is left-justified. Ignore all other bits.
    CPU_WORD mask = CPU_WORD_MASK << (CPU_WORD_BIT_LEN - i_len);
    CPU_WORD val  = i_val & mask;

    // Set first half of the value.
    *relAddr &= ~(mask >> relPos); // Clear field
    *relAddr |=  (val  >> relPos); // Set field

    // Get the second half of the value, if needed
    if ( CPU_WORD_BIT_LEN < relPos + i_len )
    {
        relAddr++;
        *relAddr &= ~(mask << (CPU_WORD_BIT_LEN - relPos)); // Clear field
        *relAddr |=  (val  << (CPU_WORD_BIT_LEN - relPos)); // Set field
    }
}

//------------------------------------------------------------------------------

void BitString::setPattern( uint32_t i_sPos, uint32_t i_sLen,
                            CPU_WORD i_pattern, uint32_t i_pLen )
{
    PRDF_ASSERT(nullptr != getBufAddr());        // must to have a valid address
    PRDF_ASSERT(0 < i_sLen);                     // must have at least one bit
    PRDF_ASSERT(i_sPos + i_sLen <= getBitLen()); // field must be within range
    PRDF_ASSERT(0 < i_pLen);                     // must have at least one bit
    PRDF_ASSERT(i_pLen <= CPU_WORD_BIT_LEN);     // i_pLen length must be valid

    // Get a bit string for the pattern subset (right justified).
    BitString bso ( i_pLen, &i_pattern, CPU_WORD_BIT_LEN - i_pLen );

    // Iterate the range in chunks the size of i_pLen.
    uint32_t endPos = i_sPos + i_sLen;
    for ( uint32_t pos = i_sPos; pos < endPos; pos += i_pLen )
    {
        // The true chunk size is either i_pLen or the leftovers at the end.
        uint32_t len = std::min( i_pLen, endPos - pos );

        // Get this chunk's pattern value, truncate (left justified) if needed.
        CPU_WORD pattern = bso.getField( 0, len );

        // Set the pattern in this string.
        setField( pos, len, pattern );
    }
}

//------------------------------------------------------------------------------

void BitString::setString( const BitString & i_sStr, uint32_t i_sPos,
                           uint32_t i_sLen, uint32_t i_dPos )
{
    // Ensure the source parameters are valid.
    PRDF_ASSERT( nullptr != i_sStr.getBufAddr() );
    PRDF_ASSERT( 0 < i_sLen ); // at least one bit to copy
    PRDF_ASSERT( i_sPos + i_sLen <= i_sStr.getBitLen() );

    // Ensure the destination has at least one bit available to copy.
    PRDF_ASSERT( nullptr != getBufAddr() );
    PRDF_ASSERT( i_dPos < getBitLen() );

    // If the source length is greater than the destination length than the
    // extra source bits are ignored.
    uint32_t actLen = std::min( i_sLen, getBitLen() - i_dPos );

    // The bit strings may be in overlapping memory spaces. So we need to copy
    // the data in the correct direction to prevent overlapping.
    uint32_t sRelOffset = 0, dRelOffset = 0;
    CPU_WORD * sRelAddr = i_sStr.getRelativePosition( sRelOffset, i_sPos );
    CPU_WORD * dRelAddr =        getRelativePosition( dRelOffset, i_dPos );

    // Copy the data.
    if ( (dRelAddr == sRelAddr) && (dRelOffset == sRelOffset) )
    {
        // Do nothing. The source and destination are the same.
    }
    else if ( (dRelAddr < sRelAddr) ||
              ((dRelAddr == sRelAddr) && (dRelOffset < sRelOffset)) )
    {
        // Copy the data forward.
        for ( uint32_t pos = 0; pos < actLen; pos += CPU_WORD_BIT_LEN )
        {
            uint32_t len = std::min( actLen - pos, CPU_WORD_BIT_LEN );

            CPU_WORD value = i_sStr.getField( i_sPos + pos, len );
            setField( i_dPos + pos, len, value );
        }
    }
    else // Copy the data backwards.
    {
        // Get the first position of the last chunk (CPU_WORD aligned).
        uint32_t lastPos = ((actLen-1) / CPU_WORD_BIT_LEN) * CPU_WORD_BIT_LEN;

        // Start with the last chunk and work backwards.
        for ( int32_t pos = lastPos; 0 <= pos; pos -= CPU_WORD_BIT_LEN )
        {
            uint32_t len = std::min( actLen - pos, CPU_WORD_BIT_LEN );

            CPU_WORD value = i_sStr.getField( i_sPos + pos, len );
            setField( i_dPos + pos, len, value );
        }
    }
}

//------------------------------------------------------------------------------

void BitString::maskString( const BitString & i_mask )
{
    // Get the length of the smallest string.
    uint32_t actLen = std::min( getBitLen(), i_mask.getBitLen() );

    for ( uint32_t pos = 0; pos < actLen; pos += CPU_WORD_BIT_LEN )
    {
        uint32_t len = std::min( actLen - pos, CPU_WORD_BIT_LEN );

        CPU_WORD dVal =        getField( pos, len );
        CPU_WORD sVal = i_mask.getField( pos, len );

        setField( pos, len, dVal & ~sVal );
    }
}

//------------------------------------------------------------------------------

bool BitString::isEqual( const BitString & i_str ) const
{
    if ( getBitLen() != i_str.getBitLen() )
        return false; // size not equal

    for ( uint32_t pos = 0; pos < getBitLen(); pos += CPU_WORD_BIT_LEN )
    {
        uint32_t len = std::min( getBitLen() - pos, CPU_WORD_BIT_LEN );

        if ( getField(pos, len) != i_str.getField(pos, len) )
            return false; // bit strings do not match
    }

    return true; // bit strings match
}

//------------------------------------------------------------------------------

bool BitString::isZero() const
{
    for ( uint32_t pos = 0; pos < getBitLen(); pos += CPU_WORD_BIT_LEN )
    {
        uint32_t len = std::min( getBitLen() - pos, CPU_WORD_BIT_LEN );

        if ( 0 != getField(pos, len) )
            return false; // something is non-zero
    }

    return true; // everything was zero
}

//------------------------------------------------------------------------------

uint32_t BitString::getSetCount( uint32_t i_pos, uint32_t i_len ) const
{
    uint32_t endPos = i_pos + i_len;

    PRDF_ASSERT( endPos <= getBitLen() );

    uint32_t count = 0;

    for ( uint32_t i = i_pos; i < endPos; i++ )
    {
        if ( isBitSet(i) ) count++;
    }

    return count;
}

//------------------------------------------------------------------------------

BitStringBuffer BitString::operator~() const
{
    BitStringBuffer bsb( getBitLen() );

    for ( uint32_t pos = 0; pos < getBitLen(); pos += CPU_WORD_BIT_LEN )
    {
        uint32_t len = std::min( getBitLen() - pos, CPU_WORD_BIT_LEN );

        CPU_WORD dVal = getField( pos, len );

        bsb.setField( pos, len, ~dVal );
    }

    return bsb;
}

//------------------------------------------------------------------------------

BitStringBuffer BitString::operator&( const BitString & i_bs ) const
{
    // Get the length of the smallest string.
    uint32_t actLen = std::min( getBitLen(), i_bs.getBitLen() );

    BitStringBuffer bsb( actLen );

    for ( uint32_t pos = 0; pos < actLen; pos += CPU_WORD_BIT_LEN )
    {
        uint32_t len = std::min( actLen - pos, CPU_WORD_BIT_LEN );

        CPU_WORD dVal =      getField( pos, len );
        CPU_WORD sVal = i_bs.getField( pos, len );

        bsb.setField( pos, len, dVal & sVal );
    }

    return bsb;
}

//------------------------------------------------------------------------------

BitStringBuffer BitString::operator|( const BitString & i_bs ) const
{
    // Get the length of the smallest string.
    uint32_t actLen = std::min( getBitLen(), i_bs.getBitLen() );

    BitStringBuffer bsb( actLen );

    for ( uint32_t pos = 0; pos < actLen; pos += CPU_WORD_BIT_LEN )
    {
        uint32_t len = std::min( actLen - pos, CPU_WORD_BIT_LEN );

        CPU_WORD dVal =      getField( pos, len );
        CPU_WORD sVal = i_bs.getField( pos, len );

        bsb.setField( pos, len, dVal | sVal );
    }

    return bsb;
}

//------------------------------------------------------------------------------

BitStringBuffer BitString::operator>>( uint32_t i_shift ) const
{
    BitStringBuffer bsb( getBitLen() ); // default all zeros

    if ( i_shift < getBitLen() )
    {
        // bso overlays bsb, containing the shifted offset.
        BitString bso ( bsb.getBitLen() - i_shift, bsb.getBufAddr(), i_shift );

        // Copy this into bso.
        bso.setString( *this );
    }

    return bsb;
}

//------------------------------------------------------------------------------

BitStringBuffer BitString::operator<<( uint32_t i_shift ) const
{
    BitStringBuffer bsb( getBitLen() ); // default all zeros

    if ( i_shift < getBitLen() )
    {
        // bso overlays *this, containing the shifted offset.
        BitString bso ( this->getBitLen() - i_shift, this->getBufAddr(),
                        i_shift );

        // Copy bso into bsb.
        bsb.setString( bso );
    }

    return bsb;
}

//------------------------------------------------------------------------------

CPU_WORD * BitString::getRelativePosition( uint32_t & o_relPos,
                                           uint32_t   i_absPos ) const
{
    PRDF_ASSERT( nullptr != getBufAddr() ); // must to have a valid address
    PRDF_ASSERT( i_absPos < getBitLen() );  // must be a valid position

    o_relPos = (i_absPos + iv_offset) % CPU_WORD_BIT_LEN;

    return iv_bufAddr + ((i_absPos + iv_offset) / CPU_WORD_BIT_LEN);
}

//##############################################################################
//                          BitStringBuffer class
//##############################################################################

BitStringBuffer::BitStringBuffer( uint32_t i_bitLen ) :
    BitString( i_bitLen, nullptr )
{
    initBuffer();
}

//------------------------------------------------------------------------------

BitStringBuffer::~BitStringBuffer()
{
    delete [] getBufAddr();
}

//------------------------------------------------------------------------------

BitStringBuffer::BitStringBuffer( const BitString & i_bs ) :
    BitString( i_bs.getBitLen(), nullptr )
{
    initBuffer();
    if ( !i_bs.isZero() ) setString( i_bs );
}

//------------------------------------------------------------------------------

BitStringBuffer::BitStringBuffer( const BitStringBuffer & i_bsb ) :
    BitString( i_bsb.getBitLen(), nullptr )
{
    initBuffer();
    if ( !i_bsb.isZero() ) setString( i_bsb );
}

//------------------------------------------------------------------------------

BitStringBuffer & BitStringBuffer::operator=( const BitString & i_bs )
{
    // The initBuffer() function will deallocate the buffer as well, however we
    // also need to deallocate the buffer here before we set the length.
    delete [] getBufAddr();
    setBufAddr( nullptr );

    setBitLen( i_bs.getBitLen() );
    initBuffer();
    if ( !i_bs.isZero() ) setString( i_bs );

    return *this;
}

//------------------------------------------------------------------------------

BitStringBuffer & BitStringBuffer::operator=( const BitStringBuffer & i_bsb )
{
    if ( this != &i_bsb ) // Check for assignment to self
    {
        // The initBuffer() function will deallocate the buffer as well, however
        // we also need to deallocate the buffer here before we set the length.
        delete [] getBufAddr();
        setBufAddr( nullptr );

        setBitLen( i_bsb.getBitLen() );
        initBuffer();
        if ( !i_bsb.isZero() ) setString( i_bsb );
    }

    return *this;
}

//------------------------------------------------------------------------------

void BitStringBuffer::initBuffer()
{
    // Deallocate the current buffer.
    delete [] getBufAddr();

    // Allocate the new buffer.
    setBufAddr( new CPU_WORD[ getNumCpuWords(getBitLen()) ] );

    // Clear the new buffer.
    if ( !isZero() ) clearAll();
}

/*--------------------------------------------------------------------*/
/*  IO Stream Conditional Support                                     */
/*--------------------------------------------------------------------*/

#ifdef _USE_IOSTREAMS_

std::ostream & operator<<(std::ostream & out,
                          const BitString & bit_string )
{
  const uint32_t bit_field_length = BitString::CPU_WORD_BIT_LEN;
  out << std::hex;
  for(uint32_t pos = 0; pos < bit_string.getBitLen(); pos += bit_field_length)
  {
    uint32_t len = bit_string.getBitLen() - pos;
    len = std::min(len,bit_field_length);
    CPU_WORD value = bit_string.getField(pos,len);
    out << std::setw(bit_field_length/4) << std::setfill('0') << value << " ";
  }

  return(out);
}

#endif

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // end namespace FSP/HOSTBOOT
#endif
} // end namespace PRDF

