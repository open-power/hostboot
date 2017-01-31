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

#define PRDFBITSTRING_CPP

#include <prdfBitString.H>

#undef PRDFBITSTRING_CPP

#include <algorithm>

namespace PRDF
{

//##############################################################################
//                             BitString class
//##############################################################################

void BitString::setPattern( uint32_t i_sPos, uint32_t i_sLen,
                            CPU_WORD i_pattern, uint32_t i_pLen )
{
    PRDF_ASSERT(nullptr != getBufAddr());        // must to have a valid address
    PRDF_ASSERT(0 < i_sLen);                     // must have at least one bit
    PRDF_ASSERT(i_sPos + i_sLen <= getBitLen()); // field must be within range
    PRDF_ASSERT(0 < i_pLen);                     // must have at least one bit
    PRDF_ASSERT(i_pLen <= CPU_WORD_BIT_LEN);     // i_pLen length must be valid

    // Get a bit string for the pattern subset (right justified).
    BitStringOffset bso ( CPU_WORD_BIT_LEN - i_pLen, i_pLen, &i_pattern );

    // Iterate the range in chunks the size of i_pLen.
    uint32_t endPos = i_sPos + i_sLen;
    for ( uint32_t pos = i_sPos; pos < endPos; pos += i_pLen )
    {
        // The true chunk size is either i_pLen or the leftovers at the end.
        uint32_t len = std::min( i_pLen, endPos - pos );

        // Get this chunk's pattern value, truncate (left justified) if needed.
        CPU_WORD pattern = bso.GetField( 0, len );

        // Set the pattern in this string.
        SetField( pos, len, pattern );
    }
}

//------------------------------------------------------------------------------

uint32_t BitString::GetSetCount(uint32_t bit_position,
                                    uint32_t leng
                                    ) const
{
  uint32_t end_position = bit_position + leng;

  PRDF_ASSERT(end_position <= iv_bitLen);

  uint32_t count = 0;

  while(bit_position < end_position)
  {
    if(IsSet(bit_position))
    {
      count++;
    }

    bit_position++;
  }

  return(count);
}

// ------------------------------------------------------------------------------------------------

CPU_WORD BitString::GetField
(
 uint32_t iBitPos,
 uint32_t iLen
 ) const
{
  PRDF_ASSERT((iBitPos + iLen) <= iv_bitLen);
  PRDF_ASSERT(iLen <= CPU_WORD_BIT_LEN);
  CPU_WORD value = 0;             //dg02a
  if(getBufAddr() != NULL)  //dg02a
  {                               //dg02a
    CPU_WORD * address = GetRelativePosition(iBitPos,iBitPos);
    value = *address << iBitPos;

    if(iBitPos + iLen > CPU_WORD_BIT_LEN) // we need the rest of the value
    {
      ++address;
      value |= *address >> (CPU_WORD_BIT_LEN - iBitPos);
    }
    if(iLen < CPU_WORD_BIT_LEN) // GNUC does not handle shift overflow as expected
    {    // zero bits outside desired field
      value &= ((((CPU_WORD) 1) << iLen) - 1) << (CPU_WORD_BIT_LEN - iLen);
    }
  }                              //dg02a

  return(value);
}

// ------------------------------------------------------------------------------------------------

CPU_WORD BitString::GetFieldJustify
(
 uint32_t bit_position,
 uint32_t length
 ) const
{
  CPU_WORD value = GetField(bit_position, length);

  value = RIGHT_SHIFT(length, value);

  return(value);
}

// ------------------------------------------------------------------------------------------------

void BitString::SetField
(
 uint32_t bit_position,
 uint32_t iLen,
 CPU_WORD value
 )
{
  PRDF_ASSERT((bit_position + iLen) <= iv_bitLen);
  PRDF_ASSERT(iLen <= CPU_WORD_BIT_LEN);

  if(iv_bufAddr != NULL || value != 0)  //dg02a
  {                                   //dg02a
    CPU_WORD * address = GetRelativePosition(bit_position,bit_position); // dg02c
    CPU_WORD mask = CPU_WORD_MASK;

    mask <<= (CPU_WORD_BIT_LEN - iLen);

    value &= mask;

    *address &= ~(mask >> bit_position);  // clear field
    *address |= value >> bit_position;    // set field

    if(bit_position + iLen > CPU_WORD_BIT_LEN) // we overflowed into the next CPU_WORD
    {
      address++;
      *address &= ~(mask << (CPU_WORD_BIT_LEN - bit_position));
      *address |=  (value << (CPU_WORD_BIT_LEN - bit_position));
    }
  }                                 //dg02a
}

// ------------------------------------------------------------------------------------------------

void BitString::SetFieldJustify
(
 uint32_t bit_position,
 uint32_t length,
 CPU_WORD value
 )
{
  value = LEFT_SHIFT(length, value);

  SetField(bit_position, length, value);
}

// ------------------------------------------------------------------------------------------------

void BitString::SetBits
(
 const BitString & string, // source string
 unsigned int iPos,               // source start pos
 unsigned int iLen,               // length
 unsigned int iDpos               // dest start pos
 )
{
  const BitString * source = &string;
  bool copyforward = true;

  // How Much to really move
  iLen = std::min(iLen,string.getBitLen() - iPos);
  iLen = std::min(iLen,getBitLen() - iDpos);

  // copy the right direction to prevent overlapping
  uint32_t sRelativeOffset = 0;
  uint32_t dRelativeOffset = 0;
  CPU_WORD * sourceAddress = NULL;      //dg02a
  CPU_WORD * destAddress   = NULL;      //dg02a
  if(string.getBufAddr() != NULL) //dg02a
  {                                     //dg02a
    sourceAddress = string.GetRelativePosition(sRelativeOffset,iPos);
  } // else assume source is all zeros    dg02a
  if(getBufAddr() != NULL)        //dg02a
  {                                     //dg02a
    destAddress = GetRelativePosition(dRelativeOffset,iDpos);
  }                                     //dg02a
  if((sourceAddress < destAddress) ||
     ((sourceAddress == destAddress) && (sRelativeOffset < dRelativeOffset)))
  {
    copyforward = false;
  }
  // else copyforward

  if(copyforward)
  {
    while(iLen)
    {
      uint32_t len = std::min(iLen,(uint32_t)CPU_WORD_BIT_LEN);
      CPU_WORD value = string.GetField(iPos,len);
      SetField(iDpos,len,value);
      iLen -= len;
      iPos += len;
      iDpos += len;
    }
  } else
  {
    iPos += iLen;
    iDpos += iLen;
    while(iLen)
    {
      uint32_t len = std::min(iLen,(uint32_t)CPU_WORD_BIT_LEN);
      iPos -= len;
      iDpos -= len;
      CPU_WORD value = source->GetField(iPos,len);
      SetField(iDpos,len,value);
      iLen -= len;
    }
  }
}

// Function Specification //////////////////////////////////////////
//
//  Title:  Is Set
//
//  Purpose:  This function determines if the specified bit position
//            in the string is set(1).
//
//  Side-effects:  None.
//
//  Dependencies:  bit_position must be in the string
//
// End Function Specification //////////////////////////////////////

bool BitString::IsSet
(
 uint32_t bit_position
 )  const
{
  return (GetField(bit_position,1) != 0);
}

// Function Specification //////////////////////////////////////////////
//
// Title:  Set
//
//  Purpose:  This function sets(1) the specified bit position in
//            the string.
//
//  Side-effects:  Bit String may be modified.
//
//  Dependencies:  bit_position must be in the string
//
// End Function Specification //////////////////////////////////////////

void BitString::Set
(
 uint32_t bit_position
 )
{
  SetField(bit_position,1,CPU_WORD_MASK);
}

// Function Specification //////////////////////////////////////////////
//
// Title:  Clear
//
//  Purpose:  This function clears(0) the specified bit position in
//            the string.
//
//  Side-effects:  Bit String may be modified.
//
//  Dependencies:  bit_position must be in the string
//
// End Function Specification //////////////////////////////////////////

void BitString::Clear
(
 uint32_t bit_position
 )
{
  SetField(bit_position,1,0);
}

// Function Specification //////////////////////////////////////////
//
//  Title:  Is Equal
//
//  Purpose:  This function compares the values of the Bit String
//            memory for each bit position in the string. If the
//            Bit String lengths do not match, then the Bit Strings
//            are not equal.
//
//  Side-effects:  None.
//
//  Dependencies:  None.
//
// Time Complexity:  O(m) where m is the length
//
// End Function Specification //////////////////////////////////////

bool BitString::IsEqual( const BitString & i_string ) const
{
    if ( iv_bitLen != i_string.iv_bitLen )
        return false; // size not equal

    for ( uint32_t pos = 0; pos < iv_bitLen; pos += CPU_WORD_BIT_LEN )
    {
        uint32_t len = std::min( iv_bitLen - pos, (uint32_t)CPU_WORD_BIT_LEN );

        if ( GetField(pos, len) != i_string.GetField(pos, len) )
            return false; // bit strings do not match
    }

    return true; // bit strings match
}

// Function Specification //////////////////////////////////////////
//
//  Title:  Is Zero
//
//  Purpose:  This function compares the values of the Bit String
//            with zero.
//
//  Side-effects:  None.
//
//  Dependencies:  None.
//
// Time Complexity:  O(m) where m is the length
//
// End Function Specification //////////////////////////////////////

bool BitString::IsZero() const
{
    for ( uint32_t pos = 0; pos < iv_bitLen; pos += CPU_WORD_BIT_LEN )
    {
        uint32_t len = std::min( iv_bitLen - pos, (uint32_t)CPU_WORD_BIT_LEN );

        if ( 0 != GetField(pos, len) )
            return false; // something is non-zero
    }

    return true; // everything was zero
}

// Function Specification //////////////////////////////////////////
//
//  Title:  Mask
//
//  Purpose:  This function masks the bits in the string with the
//            corresponding bits in the specified Bit String.  For
//            each corresponding position, if the bit in the
//            parameter Bit String is set(1), the bit in this string
//            is cleared(0). If the length of the parameter string
//            is greater than the length of this string, then the
//            extra bits are ignored.  If the length of the
//            parameter string are less than this the length of
//            this string, then the extra bits in this string are
//            not modified.
//
//  Side-effects:  Bit String may be modified.
//
//  Dependencies:  None.
//
//  Time Complexity:  O(m) where m is the length
//
//  Examples:  Parameter String:  1001
//             Old String:       1100
//             New String:       0100
//
//             Parameter String:  100111
//             Old String:       1100
//             New String:       0100
//
//             Parameter String:  1001
//             Old String:       110001
//             New String:       010001
//
// End Function Specification //////////////////////////////////////

void BitString::Mask
(
 const BitString & string
 )
{
  CPU_WORD value, string_value;
  uint32_t current_offset;
  uint32_t l;

  /* Use smaller length                                               */
  l = std::min(iv_bitLen, string.iv_bitLen);

  current_offset = 0;
  while(true)
  {
    if(l > CPU_WORD_BIT_LEN)
    {
      /* Set values using full CPU_WORDs                              */
      value = GetField(current_offset, CPU_WORD_BIT_LEN);
      string_value = string.GetField(current_offset, CPU_WORD_BIT_LEN);
      SetField(current_offset, CPU_WORD_BIT_LEN,
               value & (~string_value));
      l -= CPU_WORD_BIT_LEN;
      current_offset += CPU_WORD_BIT_LEN;
    }
    else
    {
      /* Set value in remainder of last CPU_WORD                      */
      value = GetField(current_offset, l);
      string_value = string.GetField(current_offset, l);
      SetField(current_offset, l, value & (~string_value));
      break;
    }
  }
}

//-------------------------------------------------------------------------------------------------

CPU_WORD * BitString::GetRelativePosition(uint32_t & oBitOffset, uint32_t iBitPos) const
{
  PRDF_ASSERT(iv_bufAddr != NULL);
  oBitOffset = iBitPos % CPU_WORD_BIT_LEN;
  return iv_bufAddr + (iBitPos/CPU_WORD_BIT_LEN);
}

//-------------------------------------------------------------------------------------------------

CPU_WORD * BitStringOffset::GetRelativePosition(uint32_t & oBitOffset, uint32_t iBitPos) const
{
  iBitPos += ivOffset;
  return BitString::GetRelativePosition(oBitOffset,iBitPos);
}

//-------------------------------------------------------------------------------------------------

BitStringOffset::~BitStringOffset(void) {}

//-------------------------------------------------------------------------------------------------

BitStringOffset & BitStringOffset::operator=(const BitStringOffset & i_bs)
{
  BitString::operator=(i_bs);
  ivOffset = i_bs.ivOffset;
  return *this;
}

//-------------------------------------------------------------------------------------------------

BitStringOffset & BitStringOffset::operator=(const BitString & i_bs)
{
  BitString::operator=(i_bs);
  ivOffset = 0;
  return *this;
}

// Function Specification //////////////////////////////////////////
//
// Title:  Do a bitwise NOT of the bitstring
//
// Purpose:  This function returns the NOT'd value of the bitstring.
//
// Side-effects:  None.
//
// Dependencies:  None.
//
// Time Complexity:  O(m) where m is the length of Bit String
//
// End Function Specification //////////////////////////////////////

BitStringBuffer operator~(const BitString & bs)
{
  BitStringBuffer bsb(bs);
  for(uint32_t pos = 0; pos < bsb.getBitLen(); pos += CPU_WORD_BIT_LEN)
  {
    uint32_t len = bsb.getBitLen() - pos;
    len = std::min(len,CPU_WORD_BIT_LEN);
    CPU_WORD value = ~(bsb.GetField(pos,len));
    bsb.SetField(pos,len,value);
  }

  return bsb;
}

//-------------------------------------------------------------------------------------------------

BitStringBuffer BitString::operator&(const BitString & bs) const
{
  BitStringBuffer bsb(std::min(this->getBitLen(), bs.getBitLen()));
  for(uint32_t pos = 0;
      pos < std::min(this->getBitLen(), bs.getBitLen());
      pos += CPU_WORD_BIT_LEN)
  {
    uint32_t len = std::min(this->getBitLen(), bs.getBitLen()) - pos;
    len = std::min(len,CPU_WORD_BIT_LEN);
    CPU_WORD value = this->GetField(pos,len) & bs.GetField(pos,len);
    bsb.SetField(pos,len,value);
  }

  return bsb;
}

//-------------------------------------------------------------------------------------------------

BitStringBuffer BitString::operator|(const BitString & bs) const
{
  BitStringBuffer bsb(std::min(this->getBitLen(), bs.getBitLen()));
  for(uint32_t pos = 0;
      pos < std::min(this->getBitLen(), bs.getBitLen());
      pos += CPU_WORD_BIT_LEN)
  {
    uint32_t len = std::min(this->getBitLen(), bs.getBitLen()) - pos;
    len = std::min(len,CPU_WORD_BIT_LEN);
    CPU_WORD value = this->GetField(pos,len) | bs.GetField(pos,len);
    bsb.SetField(pos,len,value);
  }

  return bsb;
}

//-------------------------------------------------------------------------------------------------

BitStringBuffer BitString::operator>>(uint32_t count) const
{
  BitStringBuffer l_bsb(this->getBitLen());
  BitString * l_bsbp = &l_bsb; // dg03a - stupid trick to get to GetRelativePosition()
  //  l_bsb.clearAll();
  if(count < this->getBitLen())
  {
    //bso overlays bsb at offset = count
    uint32_t l_dummy;
    BitStringOffset bso(count,l_bsb.getBitLen() - count,
                            l_bsbp->GetRelativePosition(l_dummy,0)); //dg03c
    bso.SetBits(*this);
  }
  return l_bsb;
}

//-------------------------------------------------------------------------------------------------

BitStringBuffer BitString::operator<<(uint32_t count) const
{
  BitStringBuffer l_bsb(this->getBitLen());
  //  l_bsb.clearAll();
  if(count < this->getBitLen())
  {
    // bso overlays *this at offset = count
    BitStringOffset bso(count,this->getBitLen() - count,this->getBufAddr());
    l_bsb.SetBits(bso);
  }
  return l_bsb;
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
    if ( !i_bs.IsZero() ) SetBits( i_bs );
}

//------------------------------------------------------------------------------

BitStringBuffer::BitStringBuffer( const BitStringBuffer & i_bsb ) :
    BitString( i_bsb.getBitLen(), nullptr )
{
    initBuffer();
    if ( !i_bsb.IsZero() ) SetBits( i_bsb );
}

//------------------------------------------------------------------------------

BitStringBuffer & BitStringBuffer::operator=( const BitString & i_bs )
{
    setBitLen( i_bs.getBitLen() );
    initBuffer();
    if ( !i_bs.IsZero() ) SetBits( i_bs );

    return *this;
}

//------------------------------------------------------------------------------

BitStringBuffer & BitStringBuffer::operator=( const BitStringBuffer & i_bsb )
{
    if ( this != &i_bsb ) // Check for assignment to self
    {
        setBitLen( i_bsb.getBitLen() );
        initBuffer();
        if ( !i_bsb.IsZero() ) SetBits( i_bsb );
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
    if ( !IsZero() ) clearAll();
}

/*--------------------------------------------------------------------*/
/*  IO Stream Conditional Support                                     */
/*--------------------------------------------------------------------*/

#ifdef _USE_IOSTREAMS_

std::ostream & operator<<(std::ostream & out,
                          const BitString & bit_string )
{
  const uint32_t bit_field_length = CPU_WORD_BIT_LEN;
  out << std::hex;
  for(uint32_t pos = 0; pos < bit_string.getBitLen(); pos += bit_field_length)
  {
    uint32_t len = bit_string.getBitLen() - pos;
    len = std::min(len,bit_field_length);
    CPU_WORD value = bit_string.GetField(pos,len);
    out << std::setw(bit_field_length/4) << std::setfill('0') << value << " ";
  }

  return(out);
}

#endif

} // end namespace PRDF

