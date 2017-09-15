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

#include <prdf_types.h>

#if defined(ESW_SIM_COMPILE)
#define _USE_IOSTREAMS_
#endif

#ifdef _USE_IOSTREAMS_
  #include <iostream>
  #include <iomanip>
#endif

namespace PRDF
{
#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN)
namespace HOSTBOOT
{
#elif defined(PRDF_FSP_ERRL_PLUGIN)
namespace FSP
{
#endif


class BitStringBuffer;

/** This type is used to take advantage of the most efficient memory reference
 *  size for a specific CPU architecture. */
typedef uint32_t CPU_WORD;

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
 * length minus one. By default, position 0 will be the first bit of the
 * buffer's start address. The optional constructor allows users to input an
 * offset anywhere within the buffer, which is then used as position 0. This is
 * useful when the data within the buffer is a right-justified.
 */
class BitString
{
  public: // constants

    /** Bit length of a CPU_WORD */
    static const uint32_t CPU_WORD_BIT_LEN;

    /** A CPU_WORD with all of the bits set to 1 */
    static const CPU_WORD CPU_WORD_MASK;

  public: // functions

    /**
     * @brief Constructor
     * @param i_bitLen  The number of bits in the bit string.
     * @param i_bufAddr The starting address of the memory buffer.
     * @param i_offset  Optional input to indicate the actual starting position
     *                  of the bit string within the memory buffer.
     * @post  It is possible that i_bitLen + i_offset may not be CPU_WORD
     *        aligned, however, the memory space allocated for i_bufAddr must be
     *        CPU_WORD aligned to avoid functions in this class accessing memory
     *        outside the available memory space. Use getNumCpuWords() to
     *        calulate the number of CPU_WORDs needed to allocate sufficient
     *        memory space.
     */
    BitString( uint32_t i_bitLen, CPU_WORD * i_bufAddr,
               uint32_t i_offset = 0 ) :
        iv_bitLen(i_bitLen), iv_bufAddr(i_bufAddr), iv_offset(i_offset)
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

    /**
     * @brief  Returns a left-justified value of the given length from the bit
     *         string starting at the given position.
     * @param  i_pos The starting position of the target range.
     * @param  i_len The number of bits of the target range.
     * @return The value of the field range specified (left-justified).
     * @pre    nullptr != getBufAddr()
     * @pre    0 < i_len
     * @pre    i_len <= CPU_WORD_BIT_LEN
     * @pre    i_pos + i_len <= getBitLen()
     */
    CPU_WORD getField( uint32_t i_pos, uint32_t i_len ) const;

    /**
     * @brief  Returns a right-justified value of the given length from the bit
     *         string starting at the given position.
     * @param  i_pos The starting position of the target range.
     * @param  i_len The number of bits of the target range.
     * @return The value of the field range specified (right-justified).
     * @pre    nullptr != getBufAddr()
     * @pre    0 < i_len
     * @pre    i_len <= CPU_WORD_BIT_LEN
     * @pre    i_pos + i_len <= getBitLen()
     */
    CPU_WORD getFieldJustify( uint32_t i_pos, uint32_t i_len ) const
    {
        return getField(i_pos, i_len) >> (CPU_WORD_BIT_LEN - i_len);
    }

    /**
     * @brief  Sets a left-justified value of the given length into the bit
     *         string starting at the given position.
     * @param i_pos The starting position of the target range.
     * @param i_len The number of bits of the target range.
     * @param i_val The left-justified value to set.
     * @pre   nullptr != getBufAddr()
     * @pre   0 < i_len
     * @pre   i_len <= CPU_WORD_BIT_LEN
     * @pre   i_pos + i_len <= getBitLen()
     */
    void setField( uint32_t i_pos, uint32_t i_len, CPU_WORD i_val );

    /**
     * @brief  Sets a right-justified value of the given length into the bit
     *         string starting at the given position.
     * @param i_pos The starting position of the target range.
     * @param i_len The number of bits of the target range.
     * @param i_val The right-justified value to set.
     * @pre   nullptr != getBufAddr()
     * @pre   0 < i_len
     * @pre   i_len <= CPU_WORD_BIT_LEN
     * @pre   i_pos + i_len <= getBitLen()
     */
    void setFieldJustify( uint32_t i_pos, uint32_t i_len, CPU_WORD i_val )
    {
        setField( i_pos, i_len, i_val << (CPU_WORD_BIT_LEN - i_len) );
    }

    /**
     * @param  i_pos The target position.
     * @return True if the bit at the given position is set(1), false otherwise.
     * @pre    i_pos < getBitLen().
     */
    bool isBitSet( uint32_t i_pos ) const { return 0 != getField(i_pos, 1); }

    /**
     * @brief Sets the target position to 1.
     * @param i_pos The target position.
     * @pre   i_pos < getBitLen().
     */
    void setBit( uint32_t i_pos ) { setFieldJustify( i_pos, 1, 1 ); }

    /** @brief Sets the entire bit string to 1's. */
    void setAll() { setPattern(CPU_WORD_MASK); }

    /**
     * @brief Sets the target position to 0.
     * @param i_pos The target position.
     * @pre   i_pos < getBitLen().
     */
    void clearBit( uint32_t i_pos ) { setFieldJustify( i_pos, 1, 0 ); }

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

    /**
     * @brief Set bits in this string based on the given string.
     * @param i_sStr The source string.
     * @param i_sPos The starting position of the source string.
     * @param i_sLen The number of bits to copy from the source string.
     * @param i_dPos The starting position of the this string.
     * @pre   nullptr != getBufAddr()
     * @pre   nullptr != i_sStr.getBufAddr()
     * @pre   0 < i_sLen
     * @pre   i_sPos + i_sLen <= i_sStr.getBitLen()
     * @pre   i_dPos < getBitLen()
     * @post  Source bits in given range are copied to this starting at i_dPos.
     * @note  If the length of the given string is greater than the length of
     *        this string, then the extra bits are ignored.
     * @note  If the length of the given string is less than the length of this
     *        string, then the extra bits in this string are not modified.
     * @note  This string and the source string may specify overlapping memory.
     */
    void setString( const BitString & i_sStr, uint32_t i_sPos,
                    uint32_t i_sLen, uint32_t i_dPos = 0 );

    /**
     * @brief Set bits in this string based on the provided string.
     * @param i_sStr The source string.
     * @note  This will try to copy as much of the source as possible to this
     *        string, starting with the first bit in each string.
     * @note  See the other definition of this function for details and
     *        restrictions.
     */
    void setString( const BitString & i_sStr )
    {
        setString( i_sStr, 0, i_sStr.getBitLen() );
    }

    /**
     * @brief Masks (clears) any bits set in this string that correspond to bits
     *        set in the given string (this & ~mask).
     * @param i_mask The mask string.
     * @note  If the length of the given string is greater than the length of
     *        this string, then the extra bits are ignored.
     * @note  If the length of the given string is less than the length of this
     *        string, then the extra bits in this string are not modified.
     */
    void maskString( const BitString & i_mask );

    /**
     * @param  i_str The string to compare.
     * @return True if the strings are equivalent, false otherwise.
     * @pre    Both strings must be of equal length and have same values to be
     *         equal.
     */
    bool isEqual( const BitString & i_str ) const;

    /** @return True if there are no bit set(1) in this bit string, false
     *          otherwise. */
    bool isZero() const;

    /**
     * @param  i_pos The starting position of the target range.
     * @param  i_len The length of the target range.
     * @return The number of bits that are set(1) in given range of this string.
     * @pre    nullptr != getBufAddr()
     * @pre    i_pos + i_len <= getBitLen()
     */
    uint32_t getSetCount( uint32_t i_pos, uint32_t i_len ) const;

    /** @return The number of bits that are set(1) in this string. */
    uint32_t getSetCount() const { return getSetCount( 0, getBitLen() ); }

    /** @brief Comparison operator. */
    bool operator==( const BitString & i_str ) const { return isEqual(i_str); }

    /** @brief Bitwise NOT operator. */
    BitStringBuffer operator~() const;

    /** @brief Bitwise AND operator. */
    BitStringBuffer operator&( const BitString & i_bs ) const;

    /** @brief Bitwise OR operator. */
    BitStringBuffer operator|( const BitString & i_bs ) const;

    /** @brief Right shift operator. */
    BitStringBuffer operator>>( uint32_t i_shift ) const;

    /** @brief Left shift operator. */
    BitStringBuffer operator<<( uint32_t i_shift ) const;

  protected: // functions

    /**
     * @param i_newBufAddr The starting address of the new bit string buffer.
     * @pre   Before calling this function, make sure you deallocate the old
     *        buffer to avoid memory leaks.
     */
    void setBufAddr( CPU_WORD * i_newBufAddr ) { iv_bufAddr = i_newBufAddr; }

    /** @param i_newBitLen The new bit length of this bit string buffer. */
    void setBitLen( uint32_t i_newBitLen ) { iv_bitLen = i_newBitLen; }

  private: // functions

    // Prevent the assignment operator and copy constructor from a
    // BitStringBuffer. While technically these could be done. We run into
    // serious problems like with the operator functions above that all return
    // a BitStringBuffer. If we allowed these, the BitString would end up
    // pointing to memory that is no longer in context.
    BitString & operator=( const BitStringBuffer & i_bsb );
    BitString( const BitStringBuffer & i_bsb );

    /**
     * @brief  Given a bit position within the bit string, this function returns
     *         the address that contains the bit position and the bit position
     *         relative to that address.
     * @param  o_relPos The returned relative position.
     * @param  i_absPos The inputted absolute position.
     * @return The relative address.
     * @pre    nullptr != getBufAddr()
     * @pre    i_absPos < getBitLen()
     */
    CPU_WORD * getRelativePosition( uint32_t & o_relPos,
                                    uint32_t   i_absPos ) const;

  private: // instance variables

    uint32_t   iv_bitLen;  ///< The bit length of this buffer.
    CPU_WORD * iv_bufAddr; ///< The beginning address of this buffer.
    uint32_t   iv_offset;  ///< Start position offset
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

/*--------------------------------------------------------------------*/
/*  IO Stream Conditional Support                                     */
/*--------------------------------------------------------------------*/

#ifdef _USE_IOSTREAMS_


std::ostream & operator<<( std::ostream & out,
                      const BitString & bit_string);

#endif

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // end namespace FSP/HOSTBOOT
#endif
} // end namespace PRDF

#endif
