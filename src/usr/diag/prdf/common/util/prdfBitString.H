/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfBitString.H $               */
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

#ifndef PRDFBITSTRING_H
#define PRDFBITSTRING_H

/** @file prdBitString.H
 *  @brief BitString and BitStringBuffer class declarations
 */

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

#include <prdfAssert.h>

namespace PRDF
{

class BitStringBuffer;

/** This type is used to take advantage of the most efficient memory reference
 *  size for a specific CPU architecture. */
typedef uint32_t CPU_WORD;

/** Size of a CPU_WORD */
constexpr uint32_t CPU_WORD_SIZE = sizeof(CPU_WORD);

/** Bit length of a CPU_WORD */
constexpr uint32_t CPU_WORD_BIT_LEN = CPU_WORD_SIZE * 8;

/** A CPU_WORD with all of the bits set to 1. */
constexpr CPU_WORD CPU_WORD_MASK = static_cast<CPU_WORD>(-1);

//##############################################################################
//                             BitString class
//##############################################################################

/**
 * A BitString is general purpose class providing the ability to manipulate
 * individual bits within an allocated section of contiguous memory.
 *
 * A BitString does not "own" the memory, it only accesses and manipulates the
 * bits in the range specified. Users will need to ensure memory is allocated
 * and deallocated appropriately. As an alternative, a BitStringBuffer is a
 * BitString that will allocate and maintain its own memory.
 *
 * The length of a BitString is only limited by the amount of memory that
 * contains the data buffer.
 *
 * The CPU_WORD type is used internally to reference memory and as the interface
 * type for the field. Ensure that any buffer allocated for a BitString is
 * CPU_WORD aligned so that the BitString does not accidentally access memory
 * beyond availability. For example, say we have a buffer allocated for 6 byte
 * (48 bits) and those 6 bytes are allocated at the very end of accessible
 * memory. When the BitString tries to access the second CPU_WORD, which
 * contains the last 2 bytes of the buffer, an expection will be thrown because
 * the BitString always access an entire CPU_WORD (4 bytes) at a time and the
 * last two bytes are not accessible. Utilize the static function
 * getNumCpuWords() to get the minimum number of CPU_WORDs required to allocate
 * sufficient space in the buffer. For example, getNumCpuWords(48) returns 2.
 *
 * The bit positions are ordered 0 to n (left to right), where n is the bit
 * length minus one. Be default, position 0 will be the first bit of the
 * buffer's start address. The BitStringOffset class allows users to input an
 * offset anywhere within the buffer, which is then used as position 0. This is
 * useful when the data within the buffer is a right-justified.
 */
class BitString
{
  public: // functions

    /**
     * @brief Constructor
     * @param i_bitLen  The number of bits in the bit string.
     * @param i_bufAddr The starting address of the memory buffer.
     * @post  It is possible that i_bitLen may not be CPU_WORD
     *        aligned, however, the memory space allocated for i_bufAddr must be
     *        CPU_WORD aligned to avoid functions in this class accessing memory
     *        outside the available memory space. Use getNumCpuWords() to
     *        calulate the number of CPU_WORDs needed to allocate sufficient
     *        memory space.
     */
    BitString( uint32_t i_bitLen, CPU_WORD * i_bufAddr ) :
        iv_bitLen(i_bitLen), iv_bufAddr(i_bufAddr)
    {}

    /** @brief Destructor */
    virtual ~BitString() {}

    /** @return The number of bits in the bit string buffer. */
    uint32_t getBitLen() const { return iv_bitLen; }

    /** @return The address of the bit string buffer. Note that this may
     *          return nullptr. */
    CPU_WORD * getBufAddr() const { return iv_bufAddr; }

    /**
     * @param i_bitLen The number of bits for a bit string.
     * @param i_offset Optional starting position of the bit string within the
     *                 memory buffer.
     * @return The minimum number of CPU_WORDs required to allocate sufficient
     *         memory space for a bit string.
     */
    static uint32_t getNumCpuWords( uint32_t i_bitLen, uint32_t i_offset = 0 )
    {
        return (i_bitLen + i_offset + CPU_WORD_BIT_LEN-1) / CPU_WORD_BIT_LEN;
    }

    /** @brief Sets the entire bit string to 1's. */
    void setAll() { setPattern(CPU_WORD_MASK); }

    /** @brief Sets the entire bit string to 0's. */
    void clearAll() { setPattern(0); }

    /**
     * @brief Sets a range within the string based on the pattern and length
     *        provided.
     * @param i_sPos    Starting position of this string.
     * @param i_sLen    The length of the target range.
     * @param i_pattern The pattern to set (right justified).
     * @param i_pLen    The length of the pattern.
     * @pre   nullptr != getBufAddr()
     * @pre   0 < i_sLen
     * @pre   i_sPos + i_sLen <= getBitLen()
     * @pre   0 < i_pLen <= CPU_WORD_BIT_LEN
     * @post  The pattern is repeated/truncated as needed.
     *
     * Examples:  i_sPos(0), i_sLen(10), i_pattern(0xA), i_pLen(4)
     *            Old String: 0000000000
     *            New String: 1010101010
     *
     *            i_sPos(3), i_sLen(4), i_pattern(0x3), i_pLen(3)
     *            Old String: 0001001000
     *            New String: 0000110000
     */
    void setPattern( uint32_t i_sPos, uint32_t i_sLen,
                     CPU_WORD i_pattern, uint32_t i_pLen );

    /**
     * @brief Sets entire string based on the pattern and length provided.
     * @param i_pattern The pattern to set (right justified).
     * @param i_pLen    The length of the pattern.
     * @note  See definition above for prerequisites.
     * @post  The entire string is filled with the pattern.
     * @post  The pattern is repeated/truncated as needed.
     */
    void setPattern( CPU_WORD i_pattern, uint32_t i_pLen )
    {
        setPattern( 0, getBitLen(), i_pattern, i_pLen );
    }

    /**
     * @brief Sets entire string based on the pattern provided (length of
     *        CPU_WORD).
     * @param i_pattern The pattern to set.
     * @note  See definition above for prerequisites.
     * @post  The entire string is filled with the pattern.
     * @post  The pattern is repeated/truncated as needed.
     */
    void setPattern( CPU_WORD i_pattern )
    {
        setPattern( i_pattern, CPU_WORD_BIT_LEN );
    }

  /*!
   Comparison
   \remarks The bitstrings must be the same length and have the same bits set to be equal
   */
  int operator==(const BitString & string) const
  {
    return(IsEqual(string));
  }

  /*!
   Get the number of bits that are set ("1")
   */
  uint32_t GetSetCount(void) const;

  /*!
   Get the number of bits that are set ("1") in a specific range
   \param starting bit position
   \param # of bits in the range
   \pre bit_position + leng <= getBitLen();
   \post none
   */
  uint32_t GetSetCount(uint32_t bit_position, uint32_t leng) const;

  /*!
   Get a copy of a subfield within the bitstring
   \param starting bit position
   \param # of bits in the field
   \return Returned value is left justified (See GetFieldJustified)
   \pre (bit_position + length) <= getBitLen(); length <= CPU_WORD_BIT_LEN
   \post none
   */
  CPU_WORD GetField(uint32_t bit_position,uint32_t length) const;

  /*!
   Get a copy of a subfield within the bitstring
   \param starting bit position
   \param # of bits in the field
   \return Returned value is right justified (See GetField)
   \pre (bit_position + length) <= getBitLen(); length <= CPU_WORD_BIT_LEN
   \post none
   */
  CPU_WORD GetFieldJustify(uint32_t bit_position,uint32_t length) const;

  /*!
   Set value into a subfield within the bitstring
   \param starting bit position
   \param # of bits in the field
   \pre (bit_position + length) <= getBitLen(); length <= CPU_WORD_BIT_LEN
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
   \pre (bit_position + length) <= getBitLen(); length <= CPU_WORD_BIT_LEN
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
   \pre iLen <= CPU_WORD_BIT_LEN
   */
  static CPU_WORD RIGHT_SHIFT(uint32_t iLen,
                              CPU_WORD iValue);

  /*!
   Utility to Left justify a "right-justified" value
   \param iLen: length of bit field to justify
   \param iValue: the value to justify
   \pre iLen <= CPU_WORD_BIT_LEN
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

  protected: // functions

    /**
     * @param i_newBufAddr The starting address of the new bit string buffer.
     * @pre   Before calling this function, make sure you deallocate the old
     *        buffer to avoid memory leaks.
     */
    void setBufAddr( CPU_WORD * i_newBufAddr ) { iv_bufAddr = i_newBufAddr; }

    /** @param i_newBitLen The new bit length of this bit string buffer. */
    void setBitLen( uint32_t i_newBitLen ) { iv_bitLen = i_newBitLen; }

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

  private: // instance variables

    uint32_t   iv_bitLen;  ///< The bit length of this buffer.
    CPU_WORD * iv_bufAddr; ///< The beginning address of this buffer.
};

//##############################################################################
//                          BitStringBuffer class
//##############################################################################

/** A BitStringBuffer is a BitString that maintains its own buffer in memory. It
 *  guarantees that sufficient memory is allocated and deallocated in the
 *  constructor and destructor, respectively. In addition, the assignment
 *  operator will adjust the amount of memory needed, as necessary, for the
 *  assignment. */
class BitStringBuffer : public BitString
{
  public: // functions

    /**
     * @brief Constructor
     * @param i_bitLen Number of bits in the string.
     */
    explicit BitStringBuffer( uint32_t i_bitLen );

    /** @brief Destructor */
    ~BitStringBuffer();

    /** @brief Copy constructor from BitString */
    BitStringBuffer( const BitString & i_bs );

    /** @brief Copy constructor from BitStringBuffer */
    BitStringBuffer( const BitStringBuffer & i_bsb );

    /** @brief Assignment from BitString */
    BitStringBuffer & operator=( const BitString & i_bs );

    /** @brief Assignment from BitStringBuffer */
    BitStringBuffer & operator=( const BitStringBuffer & i_bsb );

  private: // functions

    /** @brief Deallocates the old buffer, if needed, and initializes the new
     *         buffer. */
    void initBuffer();
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
//                CPU_WORD_SIZE for proper results.
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
  //  assert(l <= CPU_WORD_BIT_LEN);

  return(value >> (CPU_WORD_BIT_LEN - l));
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
//                CPU_WORD_SIZE for proper results.
//
// End Function Specification //////////////////////////////////////

inline
CPU_WORD BitString::LEFT_SHIFT
(
 uint32_t l,
 CPU_WORD value
 )
{
  return(value << (CPU_WORD_BIT_LEN - l));
}

inline
BitString & BitString::operator=
(
 const BitString & string
 )
{
  iv_bitLen = string.iv_bitLen;
  iv_bufAddr = string.iv_bufAddr;
  return(*this);
}

inline uint32_t BitString::GetSetCount(void) const
{
  return(GetSetCount(0, getBitLen()));
}

inline void BitString::SetBits(const BitString & string)
{
  SetBits(string, 0, string.getBitLen());
}

} // end namespace PRDF

#endif
