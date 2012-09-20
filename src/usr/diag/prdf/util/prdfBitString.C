/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/util/prdfBitString.C $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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

/** @file prdfBitString.C
 *  @brief prdfBitString and prdfBitStringBuffer class Definitions
 */

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

#define PRDFBITSTRING_CPP

#include <prdfBitString.H>

#undef PRDFBITSTRING_CPP

#include <algorithm>

/*--------------------------------------------------------------------*/
/*  User Types                                                        */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Constants                                                         */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Macros                                                            */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Internal Function Prototypes                                      */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Global Variables                                                  */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Static Variables                                                  */
/*--------------------------------------------------------------------*/


prdfBitString::~prdfBitString(void)
{
}

// ------------------------------------------------------------------------------------------------

uint32_t prdfBitString::GetSetCount(uint32_t bit_position,
                                    uint32_t leng
                                    ) const
{
  uint32_t end_position = bit_position + leng;

  PRDF_ASSERT(end_position <= ivLength);

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

CPU_WORD prdfBitString::GetField
(
 uint32_t iBitPos,
 uint32_t iLen
 ) const
{
  PRDF_ASSERT((iBitPos + iLen) <= ivLength);
  PRDF_ASSERT(iLen <= WORD_BIT_LENGTH);
  CPU_WORD value = 0;             //dg02a
  if(GetMemoryAddress() != NULL)  //dg02a
  {                               //dg02a
    CPU_WORD * address = GetRelativePosition(iBitPos,iBitPos);
    value = *address << iBitPos;

    if(iBitPos + iLen > WORD_BIT_LENGTH) // we need the rest of the value
    {
      ++address;
      value |= *address >> (WORD_BIT_LENGTH - iBitPos);
    }
    if(iLen < WORD_BIT_LENGTH) // GNUC does not handle shift overflow as expected
    {    // zero bits outside desired field
      value &= ((((CPU_WORD) 1) << iLen) - 1) << (WORD_BIT_LENGTH - iLen);
    }
  }                              //dg02a

  return(value);
}

// ------------------------------------------------------------------------------------------------

CPU_WORD prdfBitString::GetFieldJustify
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

void prdfBitString::SetField
(
 uint32_t bit_position,
 uint32_t iLen,
 CPU_WORD value
 )
{
  PRDF_ASSERT((bit_position + iLen) <= ivLength);
  PRDF_ASSERT(iLen <= WORD_BIT_LENGTH);

  if(ivBuffer != NULL || value != 0)  //dg02a
  {                                   //dg02a
    CPU_WORD * address = GetRelativePositionAlloc(bit_position,bit_position); // dg02c
    CPU_WORD mask = (CPU_WORD) -1;

    mask <<= (WORD_BIT_LENGTH - iLen);

    value &= mask;

    *address &= ~(mask >> bit_position);  // clear field
    *address |= value >> bit_position;    // set field

    if(bit_position + iLen > WORD_BIT_LENGTH) // we overflowed into the next CPU_WORD
    {
      address++;
      *address &= ~(mask << (WORD_BIT_LENGTH - bit_position));
      *address |=  (value << (WORD_BIT_LENGTH - bit_position));
    }
  }                                 //dg02a
}

// ------------------------------------------------------------------------------------------------

void prdfBitString::SetFieldJustify
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

void prdfBitString::SetBits
(
 const prdfBitString & string, // source string
 unsigned int iPos,               // source start pos
 unsigned int iLen,               // length
 unsigned int iDpos               // dest start pos
 )
{
  const prdfBitString * source = &string;
  bool copyforward = true;

  // How Much to really move
  iLen = std::min(iLen,string.GetLength() - iPos);
  iLen = std::min(iLen,GetLength() - iDpos);

  // copy the right direction to prevent overlapping
  uint32_t sRelativeOffset = 0;
  uint32_t dRelativeOffset = 0;
  CPU_WORD * sourceAddress = NULL;      //dg02a
  CPU_WORD * destAddress   = NULL;      //dg02a
  if(string.GetMemoryAddress() != NULL) //dg02a
  {                                     //dg02a
    sourceAddress = string.GetRelativePosition(sRelativeOffset,iPos);
  } // else assume source is all zeros    dg02a
  if(GetMemoryAddress() != NULL)        //dg02a
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
      uint32_t len = std::min(iLen,(uint32_t)WORD_BIT_LENGTH);
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
      uint32_t len = std::min(iLen,(uint32_t)WORD_BIT_LENGTH);
      iPos -= len;
      iDpos -= len;
      CPU_WORD value = source->GetField(iPos,len);
      SetField(iDpos,len,value);
      iLen -= len;
    }
  }
}

// ------------------------------------------------------------------------------------------------

// Function Specification //////////////////////////////////////////
//
//  Title:  Pattern
//
//  Purpose:  This function sets the the specified bits with the
//            specifed pattern.  The number of bits sets is
//            specified by the length and begins at the specified
//            offest.  The pattern is repeated as often as necessary
//            as specified by the pattern_bit_length.
//
//  Side-effects:  Bit String may be modified.
//
//  Dependencies:  Parameters must specifiy valid bits in both the
//                 bit string and the pattern.
//
// Time Complexity:  O(m) where m is the number of bits to modify
//                   (paramter l)
//
//  Examples:  o(0), l(10), pattern(0xA), pattern_bit_length(4)
//             Old String: 0000000000
//             New String: 1010101010
//
//             o(3), l(4), pattern(0x3), pattern_bit_length(3)
//             Old String: 0001001000
//             New String: 0000110000
//
// End Function Specification //////////////////////////////////////

void prdfBitString::Pattern
(
 uint32_t o,
 uint32_t l,
 CPU_WORD pattern,
 uint32_t pattern_bit_length
 )
{
  PRDF_ASSERT(((o + l) <= ivLength) &&
         (pattern_bit_length <= WORD_BIT_LENGTH));

  uint32_t current_offset;

  //  current_offset = offset + o;
  current_offset = o;
  while(true)
  {
    if(l > pattern_bit_length)
    {
      /* Set values using full CPU_WORDs                              */
      SetField(current_offset, pattern_bit_length, pattern);
      l -= pattern_bit_length;
      current_offset += pattern_bit_length;
    }
    else
    {
      /* Set value in remainder of last CPU_WORD                      */
      SetField(current_offset, l, pattern);
      break;
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

bool prdfBitString::IsSet
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

void prdfBitString::Set
(
 uint32_t bit_position
 )
{
  SetField(bit_position,1,(CPU_WORD)-1);
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

void prdfBitString::Clear
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

bool prdfBitString::IsEqual
(
 const prdfBitString& string
 ) const
{
  uint32_t o;
  uint32_t l;

  bool equal = false;

  if(ivLength == string.ivLength)
  {
    o = 0;
    l = ivLength;
    while(true)
    {
      if(l < WORD_BIT_LENGTH)
      {
        equal = (GetField(o, l) == string.GetField(o, l));
        break;
      }

      if(!(equal = (GetField(o, WORD_BIT_LENGTH) ==
                    string.GetField(o, WORD_BIT_LENGTH))))
      {
        break;
      }

      o += WORD_BIT_LENGTH;
      l -= WORD_BIT_LENGTH;
    }
  }

  return(equal);
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

bool prdfBitString::IsZero(void) const
{
  uint32_t o = 0;
  uint32_t l = ivLength;

  bool zero;

  while(true)
  {
    if(l < WORD_BIT_LENGTH)
    {
      zero = (GetField(o, l) == 0);
      break;
    }

    if(!(zero = (GetField(o, WORD_BIT_LENGTH) == 0)))
    {
      break;
    }

    o += WORD_BIT_LENGTH;
    l -= WORD_BIT_LENGTH;
  }

  return(zero);
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
//  Examples:  Paramter String:  1001
//             Old String:       1100
//             New String:       0100
//
//             Paramter String:  100111
//             Old String:       1100
//             New String:       0100
//
//             Paramter String:  1001
//             Old String:       110001
//             New String:       010001
//
// End Function Specification //////////////////////////////////////

void prdfBitString::Mask
(
 const prdfBitString & string
 )
{
  CPU_WORD value, string_value;
  uint32_t current_offset;
  uint32_t l;

  /* Use smaller length                                               */
  l = std::min(ivLength, string.ivLength);

  current_offset = 0;
  while(true)
  {
    if(l > WORD_BIT_LENGTH)
    {
      /* Set values using full CPU_WORDs                              */
      value = GetField(current_offset, WORD_BIT_LENGTH);
      string_value = string.GetField(current_offset, WORD_BIT_LENGTH);
      SetField(current_offset, WORD_BIT_LENGTH,
               value & (~string_value));
      l -= WORD_BIT_LENGTH;
      current_offset += WORD_BIT_LENGTH;
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

CPU_WORD * prdfBitString::GetRelativePosition(uint32_t & oBitOffset, uint32_t iBitPos) const
{
  PRDF_ASSERT(ivBuffer != NULL);
  oBitOffset = iBitPos % WORD_BIT_LENGTH;
  return ivBuffer + (iBitPos/WORD_BIT_LENGTH);
}

//-------------------------------------------------------------------------------------------------
// dg02a - start
CPU_WORD * prdfBitStringBuffer::GetRelativePositionAlloc(uint32_t & oBitOffset, uint32_t iBitPos)
{
  // The non-constant version of GetRelativePostion
  if(GetMemoryAddress() == NULL) SetBuffer();  // alocate memory
  return GetRelativePosition(oBitOffset, iBitPos);
}
// dg02a - end
//-------------------------------------------------------------------------------------------------

CPU_WORD * prdfBitStringOffset::GetRelativePosition(uint32_t & oBitOffset, uint32_t iBitPos) const
{
  iBitPos += ivOffset;
  return prdfBitString::GetRelativePosition(oBitOffset,iBitPos);
}

//dg04a -start
CPU_WORD * prdfBitStringOffset::GetRelativePositionAlloc(uint32_t & oBitOffset, uint32_t iBitPos)
{
  iBitPos += ivOffset;
  return prdfBitString::GetRelativePosition(oBitOffset, iBitPos);
}
//dg04a - end

//-------------------------------------------------------------------------------------------------

prdfBitStringOffset::~prdfBitStringOffset(void) {}

//-------------------------------------------------------------------------------------------------

prdfBitStringOffset & prdfBitStringOffset::operator=(const prdfBitStringOffset & i_bs)
{
  prdfBitString::operator=(i_bs);
  ivOffset = i_bs.ivOffset;
  return *this;
}

//-------------------------------------------------------------------------------------------------

prdfBitStringOffset & prdfBitStringOffset::operator=(const prdfBitString & i_bs)
{
  prdfBitString::operator=(i_bs);
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

prdfBitStringBuffer operator~(const prdfBitString & bs)
{
  prdfBitStringBuffer bsb(bs);
  for(uint32_t pos = 0; pos < bsb.GetLength(); pos += prdfBitString::WORD_BIT_LENGTH)
  {
    uint32_t len = bsb.GetLength() - pos;
    len = std::min(len,(uint32_t)prdfBitString::WORD_BIT_LENGTH);
    CPU_WORD value = ~(bsb.GetField(pos,len));
    bsb.SetField(pos,len,value);
  }

  return bsb;
}

//-------------------------------------------------------------------------------------------------

prdfBitStringBuffer prdfBitString::operator&(const prdfBitString & bs) const
{
  prdfBitStringBuffer bsb(std::min(this->GetLength(), bs.GetLength()));
  for(uint32_t pos = 0;
      pos < std::min(this->GetLength(), bs.GetLength());
      pos += prdfBitString::WORD_BIT_LENGTH)
  {
    uint32_t len = std::min(this->GetLength(), bs.GetLength()) - pos;
    len = std::min(len,(uint32_t)prdfBitStringBuffer::WORD_BIT_LENGTH);
    CPU_WORD value = this->GetField(pos,len) & bs.GetField(pos,len);
    bsb.SetField(pos,len,value);
  }

  return bsb;
}

//-------------------------------------------------------------------------------------------------

prdfBitStringBuffer prdfBitString::operator|(const prdfBitString & bs) const
{
  prdfBitStringBuffer bsb(std::min(this->GetLength(), bs.GetLength()));
  for(uint32_t pos = 0;
      pos < std::min(this->GetLength(), bs.GetLength());
      pos += prdfBitString::WORD_BIT_LENGTH)
  {
    uint32_t len = std::min(this->GetLength(), bs.GetLength()) - pos;
    len = std::min(len,(uint32_t)prdfBitStringBuffer::WORD_BIT_LENGTH);
    CPU_WORD value = this->GetField(pos,len) | bs.GetField(pos,len);
    bsb.SetField(pos,len,value);
  }

  return bsb;
}

//-------------------------------------------------------------------------------------------------

prdfBitStringBuffer prdfBitString::operator>>(uint32_t count) const
{
  prdfBitStringBuffer l_bsb(this->GetLength());
  prdfBitString * l_bsbp = &l_bsb; // dg03a - stupid trick to get to GetRelativePositionAlloc()
  //  l_bsb.Clear();
  if(count < this->GetLength())
  {
    //bso overlays bsb at offset = count
    uint32_t l_dummy;
    prdfBitStringOffset bso(count,l_bsb.GetLength() - count,
                            l_bsbp->GetRelativePositionAlloc(l_dummy,0)); //dg03c
    bso.SetBits(*this);
  }
  return l_bsb;
}

//-------------------------------------------------------------------------------------------------

prdfBitStringBuffer prdfBitString::operator<<(uint32_t count) const
{
  prdfBitStringBuffer l_bsb(this->GetLength());
  //  l_bsb.Clear();
  if(count < this->GetLength())
  {
    // bso overlays *this at offset = count
    prdfBitStringOffset bso(count,this->GetLength() - count,this->GetMemoryAddress());
    l_bsb.SetBits(bso);
  }
  return l_bsb;
}

// Function Specification //////////////////////////////////////////
//
// Title:  prdfBitStringBuffer (Constructor)
//
// Purpose:  This constuctor initializes the data members.
//
// Side-effects:  This instance is initialized.
//                Memory is allocated.
//                Bit String values are undefined.
//
// Dependencies:  None.
//
// End Function Specification //////////////////////////////////////

prdfBitStringBuffer::prdfBitStringBuffer
(
 uint32_t iLen,
 unsigned int ibc
 )
:
prdfBitString(iLen, NULL),
ivByteCapacity(ibc)
{
//  SetBuffer();  //dg02d
}

// Function Specification ///////////////////////////////////////////
//
// Title:  prdfBitStringBuffer (Copy constructor)
//
// Purpose:  This constuctor initializes the data members.  This copy
//           constructor uses a "deep" copy.  This constructor will
//           also handle any class derived from the Bit String base
//           class.
//
// Side-effects:  This instance is initialized.
//                Bit String values are are copied.
//
// Dependencies:  None.
//
// Time Complexity:  Dominated by the time complexity of SetBits()
//
// End Function Specification //////////////////////////////////////

prdfBitStringBuffer::prdfBitStringBuffer(const prdfBitString & string)
:
prdfBitString(string.GetLength(),NULL),
ivByteCapacity(0)
{
  if(!string.IsZero())  //dg02a - only allocate if bits are on
  {                     //dg02a
    SetBuffer();
    SetBits(string);
  }                     //dg02a
}

// The True copy constructor  mk00a
prdfBitStringBuffer::prdfBitStringBuffer(const prdfBitStringBuffer & string)
:
prdfBitString(string.GetLength(),NULL),
ivByteCapacity(string.ivByteCapacity)
{
  if(!string.IsZero())  //dg02a - only allocate if bits are on
  {                     //dg02a
    SetBuffer();
    SetBits(string);
  }                     //dg02a
}

// Function Specification ///////////////////////////////////////////
//
// Title:  ~prdfBitStringBuffer (Virtual Destructor)
//
// Purpose:  This destructor deallocates the buffer memory.
//
//  Side-effects:  Memory is deallocated.
//
//  Dependencies:  None.
//
// End Function Specification //////////////////////////////////////

prdfBitStringBuffer::~prdfBitStringBuffer(void)
{
  delete [] GetMemoryAddress();
}

// Function Specification ///////////////////////////////////////////
//
// Title:  operator= (Assignment operator)
//
// Purpose:  This assignment operator assigns the offset and length
//           data members.  A new buffer is allocated for the and
//           the assinged Bit String contents are assigned.
//
// Side-effects:  Data members are modified.
//                Memory is allocated.
//
// Dependencies:  None.
//
// Time Complexity:  Proportional to time complexity of SetBits()
//
// End Function Specification //////////////////////////////////////

prdfBitStringBuffer & prdfBitStringBuffer::operator=
(
 const prdfBitStringBuffer & string
 )
{
  // Check for assignment to self
  if(this != &string)
  {
    delete[] GetMemoryAddress();
    // Assign base class part
    prdfBitString::operator=(string);
    SetMemoryAddress(NULL);

    // Assign derived class part
    ivByteCapacity = string.ivByteCapacity;

    // Allocate memory and copy the Bits
    if(!string.IsZero())  //dg02a - only allocate if bits are on
    {                     //dg02a
      SetBuffer();
      SetBits(string);
    }                     //dg02a
  }

  return(*this);
}

prdfBitStringBuffer & prdfBitStringBuffer::operator=(const prdfBitString & string)
{
  delete [] GetMemoryAddress();

  // Assign base class part
  prdfBitString::operator=(string); //copy it to this
  SetMemoryAddress(NULL);

  // Assign derived class part
  ivByteCapacity = 0;

  // Allocate memory and copy the Bits
  if(!string.IsZero())  //dg02a - only allocate if bits are on
  {                     //dg02a
    SetBuffer();
    SetBits(string);
  }                     //dg02a

  return(*this);
}
// Function Specification //////////////////////////////////////////
//
// Title:  Set Buffer
//
// Purpose:  This function allocates memory for the buffer.  Any
//           memory that has been previously allocated is
//           deallocated.
//
// Side-effects:  Memory is allocated.
//
// Dependencies:  This function must be called at least once prior
//                to the first Bit String access.
//
// End Function Specification //////////////////////////////////////

void prdfBitStringBuffer::SetBuffer(void)
{
  uint32_t byte_count = GetLength() / (sizeof(CPU_WORD) * 8);

  // Account for remainder of division with an additional byte
  if((GetLength() % (sizeof(CPU_WORD) * 8)) != 0)
  {
    byte_count++;
  }

  byte_count = std::max(ivByteCapacity, byte_count);

  delete [] GetMemoryAddress();
  SetMemoryAddress(new CPU_WORD[byte_count]);
  Clear();
}
/*--------------------------------------------------------------------*/
/*  IO Stream Conditional Support                                     */
/*--------------------------------------------------------------------*/

#ifdef _USE_IOSTREAMS_

std::ostream & operator<<(std::ostream & out,
                          const prdfBitString & bit_string )
{
  const uint32_t bit_field_length = sizeof(CPU_WORD) * 8;
  out << std::hex;
  for(uint32_t pos = 0; pos < bit_string.GetLength(); pos += bit_field_length)
  {
    uint32_t len = bit_string.GetLength() - pos;
    len = std::min(len,bit_field_length);
    CPU_WORD value = bit_string.GetField(pos,len);
    out << std::setw(bit_field_length/4) << std::setfill('0') << value << " ";
  }

  return(out);
}

#endif

