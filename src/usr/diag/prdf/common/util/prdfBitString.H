/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfBitString.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

#ifndef PRDFBITSTRING_H
#define PRDFBITSTRING_H

/** @file prdBitString.H
 *  @brief BitString and BitStringBuffer class declarations
 */

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

#if !defined(PRDF_TYPES_H)
#include <prdf_types.h>
#endif

#if defined(ESW_SIM_COMPILE)
#define _USE_IOSTREAMS_
#endif

#ifdef _USE_IOSTREAMS_
  #include <iostream>
  #include <iomanip>
#endif

#if defined(NO_FSP)
    // Can not use PRD implementation of assert() in error log parsing code.
    #include <assert.h>
    #define PRDF_ASSERT(x) assert(x)
#else
    #include <prdfAssert.h>
#endif

/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  User Types                                                        */
/*--------------------------------------------------------------------*/

// Type Specification //////////////////////////////////////////////////
//
// Title:  CPU_WORD
//
// Purpose:  This type is used to take advantage of the most efficient
//           memory reference size for a specific CPU architecture.
//           This type definition is provided only to handle the case
//           where no previous defintions exists.
//
// End Type Specification //////////////////////////////////////////////

#ifndef CPU_WORD

typedef uint32_t CPU_WORD;

#endif

/*--------------------------------------------------------------------*/
/*  Constants                                                         */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Macros                                                            */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Global Variables                                                  */
/*--------------------------------------------------------------------*/

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

namespace PRDF
{

class BitStringBuffer;

/*--------------------------------------------------------------------*/
/*  Function Prototypes                                               */
/*--------------------------------------------------------------------*/

//! BitString
/*!
 BitString is general purpose class providing access to a bit string in memory.
 \remarks
 The Bit String models a contiguous sequence of bits in memory from 0 to n.
 In the BitString class the start of the string is aligned with the memory
 address provided. The BitStringOffset class allows the starting bit string
 to occur on any bit in memory. The length of the bit string may be any length up to
 the value a uint32_t can hold. ( the BitStringOffset limits the length such that
 the start bit offset + length must not exceed the max value of a uint32_t).

 The BitString and BitStringOffset classes do not own the memory storage used to hold
 the bitstring data, it only accesses and manipulate the bits in the range specified.
 The BitStringBuffer is a version of the bits string class that manages its' own storage.
 Operations are performed on the Bit String using either a single bit or a field.

 The CPU_WORD type is used internally to reference memory
 and as the interface type for the field.  This interface
 allows normal interaction with the builtin types.
 Accessing the Bit String is accomplished in units of n
 bits where n equals (sizeof(CPU_WORD) * 8).  This CPU_WORD
 type is defined to take advantage of the target CPU's
 most efficient memory access instructions.  However, the
 semantics of the Bit String class are identical
 regardless of the actual type of CPU_WORD.

 \verbatim
 Bit positions are specified  0 to (length - 1) from left to right.

 0 1 2 3 .... (length - 1)

 B B B B ....       B
 \endverbatim

 \remarks
 When the CPU_WORD is used in SetField() and GetField uses
 an identical bit order.  For example, if only 16 bits of
 the CPU_WORD were used, then the 16 left most bits would
 contain the field data and the remaining bits would be
 zero.

 \verbatim
 0 1 2 3 .... 15 16 17 ....     (sizeof(CPU_WORD) - 1)

 B B B B ....  B  0  0 ....              0
 \endverbatim

 \remarks
 A static member function RIGHT_SHIFT() is provided for
 shifting the bits the apppropriate number of positions so
 that the resulting value is right justified. For example,
 after using RIGHT_SHIFT() on the above field the result
 would be as follows.

 \verbatim
 0 1 2 3 ....              ....  (sizeof(CPU_WORD) - 1)

 0 0 0 0 ....  B B B B  B  ....             B
 \endverbatim

 \remarks
 The static member function LEFT_SHIFT() performs the
 inverse operation.  The resulting value is left justified.

 \remarks
 The length of a Bit String is only limited by the amount
 of memory that contains the bits and the representation
 of length (16-bits).
*/
class BitString
{
public:

  /*!
   Constructor
   \param Length of bitstring
   \param memory address of bit string storage
   \pre   None.
   \post  None.
   */
  BitString(uint32_t i_length, CPU_WORD * i_address)
  :
  ivLength(i_length),
  ivBuffer(i_address)
  {
  }

  /*!
   Destructor
   \notes This destructor does nothing. It is required for proper destruction
   of derived classes.
   */
  virtual ~BitString(void);

  /*!
   Comparison
   \remarks The bitstrings must be the same length and have the same bits set to be equal
   */
  int operator==(const BitString & string) const
  {
    return(IsEqual(string));
  }

  /*!
   Get the number of bits in the bitstring
   \returns length of bitstring
   \pre None
   \pos None
   */
  uint32_t GetLength(void) const { return ivLength; }

  /*!
   Get the number of bits that are set ("1")
   */
  uint32_t GetSetCount(void) const;

  /*!
   Get the number of bits that are set ("1") in a specific range
   \param starting bit position
   \param # of bits in the range
   \pre bit_position + leng <= GetLength();
   \post none
   */
  uint32_t GetSetCount(uint32_t bit_position, uint32_t leng) const;

  /*!
   Get a copy of a subfield within the bitstring
   \param starting bit position
   \param # of bits in the field
   \return Returned value is left justified (See GetFieldJustified)
   \pre (bit_position + length) <= GetLength(); length <= sizeof(CPU_WORD)*8
   \post none
   */
  CPU_WORD GetField(uint32_t bit_position,uint32_t length) const;

  /*!
   Get a copy of a subfield within the bitstring
   \param starting bit position
   \param # of bits in the field
   \return Returned value is right justified (See GetField)
   \pre (bit_position + length) <= GetLength(); length <= sizeof(CPU_WORD)*8
   \post none
   */
  CPU_WORD GetFieldJustify(uint32_t bit_position,uint32_t length) const;

  /*!
   Set value into a subfield within the bitstring
   \param starting bit position
   \param # of bits in the field
   \pre (bit_position + length) <= GetLength(); length <= sizeof(CPU_WORD)*8
   \post The bits are set from value (value assumed left justified)
   \verbatim
          this   -> '00100110011....'b
          SetField(3,5,0xf8000000)
          result -> '00111111011....'b
   \endverbatim
   */
  void SetField(uint32_t bit_position,uint32_t length,CPU_WORD value);


  /*!
   Set value into a subfield within the bitstring
   \param starting bit position
   \param # of bits in the field
   \pre (bit_position + length) <= GetLength(); length <= sizeof(CPU_WORD)*8
   \post The bits are set from value (value assumed right justified)
   \verbatim
          this   -> '00100110011....'b
          SetField(3,5,0x0000001f)
          result -> '00111111011....'b
   \endverbatim
   */
  void SetFieldJustify(uint32_t bit_position,uint32_t length,CPU_WORD value);

  /*!
   Set bits in this string based on provided string
   \param source string
   \post source bits are copied to this
   \notes if source len > this len than extra source bits ignored.
          if source len < this len than extra bits in this are uneffected
          Bit strings may specify overlapping memory
   */
  void SetBits(const BitString & string);

  /*!
   Set bits in this string based on provided string
   \param string: source string
   \param pos: bit pos in source to start copy from
   \param len: # of bits to copy
   \param dpos: start bit pos in this string to copy to (def = 0)
   \post source bits in given range are copied to this starting at dpos
   \notes only bit in the given range are effected. if more source bits are
          given than space in this string than the extra source bit are ignored.
          Bit strings may specify overlapping memory.
   */
  void SetBits(const BitString & string,
               unsigned int pos,
               unsigned int len,
               unsigned int dpos = 0);

  /*!
   Set bits in this string based on the range and pattern provided
   \param iPos: bit pos in this string to start
   \param iLen: # of bits to modify
   \param iPattern: Pattern to set
   \param iPatternLen: # of bit in pattern to use (right justfied)
   \pre  (iPos + iLen) <= GetLength()
   \post Range of specified bits filled with pattern. The pattern is repeated as needed
   \verbatim
        Examples:  iPos(0), iLen(10), iPattern(0xA), iPatternLen(4)
        Old String: 0000000000
        New String: 1010101010

        iPos(3), iLen(4), iPattern(0x3), iPatternLen(3)
        Old String: 0001001000
        New String: 0000110000
   \endverbatim
   */
  void Pattern(uint32_t iPos,
               uint32_t iLen,
               CPU_WORD iPattern,
               uint32_t pattern_bit_length);

  /*!
   Set entire string based on the pattern provided
   \param iPattern: Pattern to set
   \param iPatternLen: # of bit in pattern to use (right justfied)
   \post BitString is filled with pattern. The pattern is repeated/truncated as needed
   */
  void Pattern(CPU_WORD iPattern,
               uint32_t iPatternLen);

  /*!
   Set entire string based on the pattern provided
   \param iPattern: Pattern to set
   \post BitString is filled with pattern. The pattern is repeated/truncated as needed
   */
  void Pattern(CPU_WORD pattern);

  /*!
   Query if bit is set (1)
   \returns [true|false]
   \param iPos: bit position to test
   */
  bool IsSet(uint32_t iPos) const;

  /*!
   Set a bit (1) at the specified position
   \param iPos: bit position to test
   \post IsSet(iPos) == true
   */
  void Set( uint32_t iPos);

  /*!
   Clear or ReSet a bit (0) at the specified position
   \param iPos: bit position to clear
   \post IsSet(iPos) == false
   */
  void Clear(uint32_t bit_position);

  /*!
   Clear the entire bit string
   \post IsZero() == true
   */
  void Clear(void) { Pattern(0); }

  /*!
   Test equivalence
   \returns [true | false]
   \notes Both strings must be of equal length and have same values to be equal
   */
  bool IsEqual( const BitString & string) const;

  /*!
   Query state of no bits set(1)
   \returns [true | false]
   */
  bool IsZero(void) const;

  /*!
   Mask off (Clear) bits positions in this string that are Set in the string provided
   \param bitString containing the mask
   \post Set bit positions in string provided are cleared in this string
   \notes If the parameter string is longer than this string than extra bits are ignored.
          If the parameter string is shorter than this string than extra bits in this string
          are not modified.
   \verbatim
    Examples:  Parameter String:  1001
               Old String:       1100
               New String:       0100

               Parameter String:  100111
               Old String:       1100
               New String:       0100

               Parameter String:  1001
               Old String:       110001
               New String:       010001

   \endverbatim
   */
  void Mask(const BitString & string);

  /*!
   Utility to Right justify a "Left-justified" value
   \param iLen: length of bit field to justify
   \param iValue: the value to justify
   \pre iLen <= sizeof(CPU_WORD)*8
   */
  static CPU_WORD RIGHT_SHIFT(uint32_t iLen,
                              CPU_WORD iValue);

  /*!
   Utility to Left justify a "right-justified" value
   \param iLen: length of bit field to justify
   \param iValue: the value to justify
   \pre iLen <= sizeof(CPU_WORD)*8
   */
  static CPU_WORD LEFT_SHIFT(uint32_t l,
                             CPU_WORD value);

  /*!
   bitwise NOT
   \returns a bit-wise inverted copy of the specified bit string
   */

  friend BitStringBuffer operator~(const BitString & bs);
  BitStringBuffer operator&(const BitString & bs) const;
  BitStringBuffer operator|(const BitString & bs) const;

  /*!
   Left shift
   \returns bitstring left shifted by count
   \note: the returned bit string is the same length as the source.
   \verbatim
    Example:
                       |---|---|---|---|---|---|---|---|
    BitString content: | 0 | 1 | 1 | 1 | 0 | 0 | 0 | 0 |
                       |---|---|---|---|---|---|---|---|
           bit offset   0   1   2   3   4   5   6   7

    operator>>(5)

                       |---|---|---|---|---|---|---|---|
    BitString result:  | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |
                       |---|---|---|---|---|---|---|---|


   \endverbatim
   */
  BitStringBuffer operator>>(uint32_t count) const;

  /*!
   Right shift
   \returns a bitstring left shifted by count
   \note: the returned bit string is the same length as the source.
   \verbatim
    Example:
                       |---|---|---|---|---|---|---|---|
    BitString content: | 0 | 0 | 0 | 1 | 1 | 1 | 0 | 0 |
                       |---|---|---|---|---|---|---|---|
           bit offset   0   1   2   3   4   5   6   7

    operator<<(4)

                       |---|---|---|---|---|---|---|---|
    BitString result:  | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
                       |---|---|---|---|---|---|---|---|

   \endverbatim
   */
  BitStringBuffer operator<<(uint32_t count) const;


protected:

  /*!
   Assignment operator
   \param string Reference bit string
   */
  virtual BitString & operator=(const BitString & string);

  /*!
   Gets the CPU_WORD bounded memory address and the relative bit offset within the CPU_WORD
   that corresponds to the provided bit position in the bit string.
   \returns memory address of CPU_WORD
   \returns relative bit offset in the CPU_WORD
   \param iBitPos Bit position in the bit string
   */
  virtual CPU_WORD * GetRelativePosition(uint32_t & oBitOffset, uint32_t iBitPos) const;
  virtual CPU_WORD * GetRelativePositionAlloc(uint32_t & oBitOffset, uint32_t iBitPos);//dg02a


  /*!
   Proides address of the bit string storage
   @NOTE: WARNING!! this may return NULL if there is no storage on a BitStringBuffer because bits
          have not yet been set. - use GetRelativePositionAlloc() to force storage allocation
   */
  CPU_WORD * GetMemoryAddress(void) const { return ivBuffer; }

  /*!
   Set the memory address of the string representation
   */
  void SetMemoryAddress(CPU_WORD *iBuffer) { ivBuffer = iBuffer; }

  // Enum Specification //////////////////////////////////////////////
  //
  // Purpose:  This enummerated constant is used for member function
  //           implementation.
  //
  // End Enum Specification //////////////////////////////////////////

  enum
  {
    WORD_BIT_LENGTH = sizeof(CPU_WORD) * 8
  };

private:



  uint32_t                      ivLength;
  CPU_WORD *                    ivBuffer;

};


//! BitStringBuffer
/*!
 BitStringBuffer provides a Bit String in an associated buffer in memory.
 \remarks
 The Bit String Buffer provides all of the functionality
 of the base class along with the maintenance of memory
 allocated to hold the Bit String.  The buffer is "owned"
 by the Bit String Buffer. Sufficient memory
 is allocated and deallocted in the constructor and
 destructor, respectively.  In addition, the assignemnt
 operator will adjust the amount of memory needed as
 necessary for the assignment. A byte capacity value is also maintained.
 The internal buffer is always guaranteed to have this capacity of bytes.
*/
class BitStringBuffer : public BitString
{
public:

  /*!
   Constructor
   \param iLen: Number of bits in the string
   \param iByteCapacity: The minimum storage size to be allocated. default=0
   \notes If iByteCapcity is zero or too small than the storage size is calculated
          from iLen, rounded up to the nearest CPU_WORD.
   */
  BitStringBuffer(uint32_t iLen,
                      unsigned int iByteCapacity = 0);

  /*!
   Copy Constructor
   \param reference bits string
   */
  BitStringBuffer(const BitString & string);

  /*!
   Copy Constructor
   \param reference bits string
   */
  BitStringBuffer (const BitStringBuffer & string);

  /*!
   Destructor
   */
  virtual ~BitStringBuffer(void);

  /*!
   Assignment
   \param reference bit string
   */
  BitStringBuffer & operator=(const BitStringBuffer & string);

  /*!
   Assignment
   \param reference bit string
   */
  virtual BitStringBuffer & operator=(const BitString & string);

protected: // functions  dg02a

  virtual CPU_WORD * GetRelativePositionAlloc(uint32_t & oBitOffset, uint32_t iBitPos);//dg02a

private: // functions

  /*!
   allocate or re-allocate buffer
   */
  void SetBuffer(void);

private: // data

  unsigned int            ivByteCapacity;

};

//! BitStringOffset
/*!
 BitStringOffset provides a Bit String that allows a starting position that
 is not limited to a memory aligned boundary.
 \remarks
 The Bit String Offset provides the ability to specify a start bit offset from the
 address provided as the start position of the bit string. The class will
 not modify memory outside the bit string range.
*/
class BitStringOffset:public BitString
{
public:
  /*!
   Constructor
   \param i_offset The bit offset from address of the start of the bitstring
   \param i_len The number of bits in the bitstring
   \param i_address The memory address to base the bitstring on
   */
  BitStringOffset(uint32_t i_offset, uint32_t i_len, CPU_WORD * i_address)
  : BitString(i_len,i_address), ivOffset(i_offset) {}

  /*!
   Destructor - this class does not own it's storage
   */
  virtual ~BitStringOffset(void);

  /*!
   Copy Constructor
   */
   BitStringOffset(const BitStringOffset &i_bs);

   /*!
    Assignment
    */
   BitStringOffset & operator=(const BitStringOffset & i_bs);

   /*!
    Assignment
    */
   virtual BitStringOffset & operator=(const BitString & i_bs);


protected:  // functions

  /*!
   Gets the CPU_WORD bounded memory address and the relative bit offset within the CPU_WORD
   that corresponds to the provided bit position in the bit string.
   \returns memory address of CPU_WORD
   \returns relative bit offset in the CPU_WORD
   \param iBitPos Bit position in the bit string
   */
  virtual CPU_WORD * GetRelativePosition(uint32_t & oBitOffset, uint32_t iBitPos) const;
  virtual CPU_WORD * GetRelativePositionAlloc(uint32_t & oBitOffset, uint32_t iBitPos); //dg04a
private:  // data

  uint32_t ivOffset;
};


/*--------------------------------------------------------------------*/
/*  IO Stream Conditional Support                                     */
/*--------------------------------------------------------------------*/

#ifdef _USE_IOSTREAMS_


std::ostream & operator<<( std::ostream & out,
                      const BitString & bit_string);

#endif

/*--------------------------------------------------------------------*/
/*  Inline Member Function Definitions                                */
/*--------------------------------------------------------------------*/

// Function Specification ///////////////////////////////////////////
//
// Title:  RIGHT_SHIFT
//
// Purpose:  This function shifts the bit field right so that the
//           specified number of bits are contained in the right most
//           bits in the value.  The resulting value is right
//           justified.
//
// Side-effects:  None.
//
// Dependencies:  Parameter length(l) must be less than
//                sizeof(CPU_WORD) for proper results.
//
// End Function Specification //////////////////////////////////////

inline
CPU_WORD BitString::RIGHT_SHIFT
(
 uint32_t l,
 /*!i Length of bit field                                         */
 CPU_WORD value
 /*!i Bit field value to shift                                    */
 )
/*!o Bit field value                                             */
{
  //  assert(l <= WORD_BIT_LENGTH);

  return(value >> (WORD_BIT_LENGTH - l));
}

// Function Specification ///////////////////////////////////////////
//
// Title:  LEFT_SHIFT
//
// Purpose:  This function shifts the bit field left so that the
//           specified number of bits are contained in the left most
//           bits in the value.  The resulting value is left
//           justified.
//
// Side-effects:  None.
//
// Dependencies:  Parameter length(l) must be less than
//                sizeof(CPU_WORD) for proper results.
//
// End Function Specification //////////////////////////////////////

inline
CPU_WORD BitString::LEFT_SHIFT
(
 uint32_t l,
 CPU_WORD value
 )
{
  return(value << (WORD_BIT_LENGTH - l));
}

inline
BitString & BitString::operator=
(
 const BitString & string
 )
{
  ivLength = string.ivLength;
  ivBuffer = string.ivBuffer;
  return(*this);
}

inline
CPU_WORD * BitString::GetRelativePositionAlloc(uint32_t & oBitOffset, uint32_t iBitPos)
{
  return BitString::GetRelativePosition(oBitOffset,iBitPos);
}

// Function Specification //////////////////////////////////////////
//
//  Title:  Pattern
//
//  Purpose:  This function sets this entire Bit String with the
//            specifed pattern.  The pattern is repeated as often as
//            necessary as specified by the pattern_bit_length.
//
//  Side-effects:  Bit String is be modified.
//
//  Dependencies:  None.
//
//  Time Complexity: O(m) where m is the number of bits to modify
//                   (parameter l)
//
//  Examples:  See Pattern(uint32_t, uint32_t, CPU_WORD, uint32_t)
//
// End Function Specification //////////////////////////////////////

inline
void BitString::Pattern(CPU_WORD pattern,uint32_t pattern_bit_length)
{
  Pattern(0, GetLength(), pattern, pattern_bit_length);
}


inline
void BitString::Pattern(CPU_WORD pattern)
{
  Pattern(0, GetLength(), pattern, sizeof(CPU_WORD));
}


inline uint32_t BitString::GetSetCount(void) const
{
  return(GetSetCount(0, GetLength()));
}

inline void BitString::SetBits(const BitString & string)
{
  SetBits(string, 0, string.GetLength());
}

} // end namespace PRDF

#endif
