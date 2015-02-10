/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: $                                                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
/**
 * @file variable_buffer.H
 * @brief definitions for fapi2 variable length buffers
 */

#ifndef __FAPI2_VARIABLE_BUFFER__
#define __FAPI2_VARIABLE_BUFFER__

#include <buffer_base.H>

namespace fapi2
{
    // This is one of the main reasons we static_assert in the ctor's
    // to ensure the unit_type is 32 bits.
    inline uint32_t fast_mask32(int32_t i_pos, int32_t i_len)
    {
        // generates an arbitrary 32-bit mask using two operations, not too shabby

        static const uint32_t l_mask32[] = {
            0x00000000,
            0x80000000, 0xC0000000, 0xE0000000, 0xF0000000,
            0xF8000000, 0xFC000000, 0xFE000000, 0xFF000000,
            0xFF800000, 0xFFC00000, 0xFFE00000, 0xFFF00000,
            0xFFF80000, 0xFFFC0000, 0xFFFE0000, 0xFFFF0000,
            0xFFFF8000, 0xFFFFC000, 0xFFFFE000, 0xFFFFF000,
            0xFFFFF800, 0xFFFFFC00, 0xFFFFFE00, 0xFFFFFF00,
            0xFFFFFF80, 0xFFFFFFC0, 0xFFFFFFE0, 0xFFFFFFF0,
            0xFFFFFFF8, 0xFFFFFFFC, 0xFFFFFFFE, 0xFFFFFFFF,
        };
        return l_mask32[i_len] >> i_pos;
    }

    //
    // General set a series of bits in the buffer.
    //

    ///
    /// @cond
    /// @brief Internal bit inserting method.
    /// @tparam unit_type The type of a unit of the arrays
    /// @tparam bits_type The type of the bit counting values
    /// @param[in] i_source The incoming data
    /// @param[in] i_source_length The length in bits of the incoming data
    /// @param[in] i_target The outgoing data
    /// @param[in] i_target_length The length in bits of the outgoing data
    /// @param[in] i_source_start_bit The starting bit location in the
    ///            incoming data
    /// @param[in] i_target_start_bit The starting bit position in this
    /// @param[in] i_length The length, in bits, the user wants copied.
    /// @endcond
    ///
    template<typename unit_type, typename bits_type>
    inline fapi2::ReturnCode _insert(const unit_type* i_source,
                                     bits_type i_source_length,
                                     unit_type* i_target,
                                     bits_type i_target_length,
                                     bits_type i_source_start_bit,
                                     bits_type i_target_start_bit,
                                     bits_type i_length)
    {
        const bits_type bits_per_unit = fapi2::parameterTraits<unit_type>::bit_length;

        // tartgetStart is defaulted to the sizeof(target) - (sizeof(source) - i_source_start_bit)
        // which makes this act like insert from right
        if (i_target_start_bit == ~0)
        {
            i_target_start_bit = (i_target_length - (i_source_length - i_source_start_bit));
        }

        // len defaults to (sizeof(OT) * 8) - i_source_start_bit
        if (i_length == ~0)
        {
            i_length = i_source_length - i_source_start_bit;
        }

        // Check for overflow
        if ((i_length + i_target_start_bit > i_target_length) ||
            (i_length + i_source_start_bit > i_source_length))
        {
            return fapi2::FAPI2_RC_OVERFLOW;
        }

        do
        {
            const bits_type src_idx = i_source_start_bit / bits_per_unit;
            const bits_type trg_idx = i_target_start_bit / bits_per_unit;

            // "slop" = unaligned bits
            const bits_type src_slop = i_source_start_bit % bits_per_unit;
            const bits_type trg_slop = i_target_start_bit % bits_per_unit;

            // "cnt" = largest number of bits to be moved each pass
            bits_type cnt = std::min(i_length, bits_per_unit);
            cnt = std::min(cnt, bits_per_unit - src_slop);
            cnt = std::min(cnt, bits_per_unit - trg_slop);

            // generate the source mask only once
            bits_type mask = fast_mask32(src_slop, cnt);

            // read the source bits only once
            bits_type src_bits = i_source[src_idx] & mask;

            // "shift" = amount of shifting needed for target alignment
            int32_t shift = trg_slop - src_slop;

            // ideally (i << -1) would yield (i >> 1), but it
            // doesn't, so we need an extra branch here

            if (shift < 0)
            {
                src_bits <<= -shift;
                mask <<= -shift;
            }
            else
            {
                src_bits >>= shift;
                mask >>= shift;
            }

            // clear source '0' bits in the target
            i_target[trg_idx] &= ~mask;
            // set source '1' bits in the target
            i_target[trg_idx] |= src_bits;

            i_source_start_bit += cnt;
            i_target_start_bit += cnt;

            i_length -= cnt;
        } while (0 < i_length);

        return fapi2::FAPI2_RC_SUCCESS;
    }

    /// @brief Class representing a FAPI variable_buffer.
    /// @remark Variable buffers are buffers which can be variable in length
    /// (and "odd sized.") These best represent the FAPI 1.X ecmdDataBuffer,
    /// however they are implemented using the same template techniques
    /// as the new fapi::buffer.
    /// @note Variable buffers are not (presently) declared as std::bitset
    /// as bitsets' size is fixed at runtime. It is not clear if this is
    /// acceptable for variable_buffers at this time.
    /// @note Variable buffers are not (presently) declared as std::vector<bool>
    /// as it would need to be implemented separate from std::vector, and
    /// it's not clear it would give us any real advantage. Howevever, its is
    /// more likely this will become a std::vector<bool> than a std::bitset.
    class variable_buffer : public buffer_base<bits_container>
    {

    public:

        ///
        /// @brief Variable buffer constructor
        /// @param[in] i_value number of *bits* (sizeof(uint_type) * 8)
        /// needed.
        variable_buffer(bits_type i_value = 0);

        ///
        /// @brief Variable buffer list constructor
        /// @param[in] i_value an initializer list to initialize the container.
        ///
        variable_buffer(const std::initializer_list<unit_type>& i_value);

        /// @name Bit/Word Manipulation Functions
        ///@{

        ///
        /// @brief Return the length of the buffer in bits
        /// @return Length in bits
        ///
        inline uint32_t getBitLength(void) const
            { return iv_perceived_bit_length; }

        ///
        /// @brief Return the length of the buffer in OT units
        /// @return Length in OT units rounded up
        /// @tparam OT the type to get the length of. For example, if one
        /// wanted the length in double words, OT would be uint64_t
        /// (getLength<uint64_t>().) Similarly, to get the length in words,
        /// getLength<uin32_t>().
        ///
        template< typename OT >
        inline uint32_t getLength(void) const
        {
            static const uint32_t bits_in_ot = sizeof(OT) * 8;
            return (getBitLength() + (bits_in_ot - 1)) / bits_in_ot;
        }

        ///
        /// @brief Set a bit in the buffer
        /// @param[in] i_bit the bit number to set.
        /// @note 0 is left-most
        /// @return FAPI2_RC_SUCCESS if OK
        ///
        inline fapi2::ReturnCode setBit(const bits_type& i_bit)
        {
            const bits_type index = i_bit / bits_per_unit;

            if (index > iv_data.size())
            {
                return FAPI2_RC_INVALID_PARAMETER;
            }

            iv_data[index] |=
                unit_type(1) << (bits_per_unit - 1) -
                (i_bit - (index * bits_per_unit));

            return FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Clear a bit in buffer
        /// @tparam SB Start bit in buffer to clear.
        /// @tparam L Number of consecutive bits from start bit to
        /// clear
        /// @return FAPI2_RC_SUCCESS on success
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template< bits_type SB, bits_type L >
        fapi2::ReturnCode clearBit(void);

        ///
        /// @brief Invert bit
        /// @tparam SB Start bit in buffer to invert.
        /// @tparam L Number of consecutive bits from start bit to
        /// invert, defaults to 1
        /// @return FAPI2_RC_SUCCESS on success
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template< bits_type SB, bits_type L = 1 >
        fapi2::ReturnCode flipBit(void);

        ///
        /// @brief Get the value of a bit in the buffer
        /// @tparam B Bit in buffer to get.
        /// @return true/1 if bit is on, false/0 if bit is off
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template< bits_type B >
        inline bool getBit(void) const
        {
            const bits_type index = B / bits_per_unit;
            const unit_type mask = unit_type(1) << (bits_per_unit - 1) - (B - (index * bits_per_unit));
            return iv_data[index] & mask;
        }

        ///
        /// @brief Test if multiple bits are set
        /// @tparam SB Start bit in buffer to test.
        /// @tparam L Number of consecutive bits from start bit to
        /// test, defaults to 1
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        /// @return true if all bits in range are set - false if any
        /// bit is clear
        ///
        template< bits_type SB, bits_type L = 1 >
        bool isBitSet(void) const;

        ///
        /// @brief Test if multiple bits are clear
        /// @tparam SB Start bit in buffer to test.
        /// @tparam L Number of consecutive bits from start bit to
        /// test, defaults to 1
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        /// @return true if bit is clear - false if bit is set
        ///
        template< bits_type SB, bits_type L = 1 >
        bool isBitClear(void) const;

        ///
        /// @brief Count number of bits set in a range
        /// @tparam SB Start bit in buffer to test.
        /// @tparam L Number of consecutive bits from start bit to
        /// test, defaults to 1
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        /// @return Number of bits set in range
        ///
        template< bits_type SB, bits_type L = 1 >
        bits_type getNumBitsSet(void) const;

        ///@}

        /// @name Buffer Manipulation Functions
        ///@{

        // Note: Many (all?) of these are not needed and the compiler complains
        // as the cast to T yields a better operator. There are here mainly for
        // documenation purposes.

        ///
        /// @brief operator>>()
        ///
#ifdef DOXYGEN
        variable_buffer<T>& operator>>(bits_type i_shiftnum);
#endif

        ///
        /// @brief operator<<()
        ///
#ifdef DOXYGEN
        variable_buffer<T>& operator<<(bits_type i_shiftnum);
#endif

        ///
        /// @brief operator+()
        ///
#ifdef DOXYGEN
        variable_buffer<T>& operator+(const T& rhs);
#endif

        ///
        /// @brief operator+=()
        ///
#ifdef DOXYGEN
        variable_buffer<T>& operator+=(const T& rhs);
#endif

        ///
        /// @brief operator|=()
        ///
#ifdef DOXYGEN
        variable_buffer<T>& operator|=(const T& rhs);
#endif

        ///
        /// @brief operator&=()
        ///
#ifdef DOXYGEN
        variable_buffer<T>& operator&=(const T& rhs);
#endif

        ///
        /// @brief operator|()
        ///
#ifdef DOXYGEN
        variable_buffer<T>& operator|(const T& rhs);
#endif

        ///
        /// @brief operator&()
        ///
#ifdef DOXYGEN
        variable_buffer<T>& operator&(const T& rhs);
#endif

        ///
        /// @brief operator^=()
        ///
#ifdef DOXYGEN
        variable_buffer<T>& operator^=(const T& rhs);
#endif

        ///
        /// @brief operator!=()
        ///
#ifdef DOXYGEN
        bool operator!=(const T& rhs) const;
#endif

        ///
        /// @brief operator==()
        /// @return true if and only if lhs == rhs
        ///
        inline bool operator==(const fapi2::bits_container& rhs) const
        {
            if (&iv_data == &rhs)
            {
                return true;
            }

            return iv_data == rhs;
        }

        ///
        /// @brief Copy part of an element into the DataBuffer
        /// @param[in] i_data OT value to copy into DataBuffer
        /// @param[in] i_targetStart The position in this where the copy starts
        /// @param[in] i_len How many bits to copy
        /// @param[in] i_sourceStart The start positon in i_data, defaults to 0
        /// @return FAPI2_RC_SUCCESS on success, FAPi2_RC_OVERFLOW otherwise
        ///
        template<typename OT>
        fapi2::ReturnCode insert(const OT& i_data,
                                 bits_type i_targetStart = 0,
                                 bits_type i_len = ~0,
                                 bits_type i_sourceStart = 0);

        ///
        /// @brief Copy in a right aligned (decimal) element
        /// @param[in] i_data, the incoming data
        ///    - data is taken right aligned
        /// @param[in] i_targetStart The starting bit position in this
        ///            - Defaultst to 0
        /// @param[in] i_length The length, in bits, the user wants copied.
        ///            - Defaults to all of the bits in the source which fit
        /// @return FAPI2_RC_SUCCESS on success, FAPI2_RC_OVERFLOW otherwise
        ///
        template<typename OT>
        fapi2::ReturnCode insertFromRight(const OT& i_data,
                                          bits_type i_targetStart = 0,
                                          bits_type i_len = ~0);

        ///
        /// @brief Copy data from this buffer into an OT
        /// @tparam OT the type of the outgoing data
        /// @param[out] o_out OT to copy into - data is placed left aligned
        /// @param[in] i_start Start bit to copy from - defaults to 0
        /// @param[in] i_len Length of bits to copy - defaults to filling o_out
        /// @return FAPI2_RC_SUCCESS on success
        ///
        template< typename OT >
        fapi2::ReturnCode extract(OT& o_out,
                                  bits_type i_start = 0,
                                  bits_type i_len = ~0) const;

        ///
        /// @brief Copy data from this buffer into an OT and right justify
        /// @tparam OT the type of the outgoing data
        /// @param[out] o_out OT to copy into - data is placed right aligned
        /// @param[in] i_start Start bit to copy from - defaults to 0
        /// @param[in] i_len Length of bits to copy - defaults to filling o_out
        /// @return FAPI2_RC_SUCCESS on success
        ///
        template< typename OT >
        fapi2::ReturnCode extractToRight(OT& o_out,
                                         bits_type i_start = 0,
                                         bits_type i_len = ~0) const;
        ///@}

    private:
        // Just shorthand ...
        static const bits_type bits_per_unit =
                                   bufferTraits<bits_container>::bits_per_unit;

        // The number of bits the user asked for. The actual size of the
        // container might be larger.
        bits_type iv_perceived_bit_length;

        ///
        /// @brief Internal bit extraction method.
        /// @tparam OT The type of the destination
        /// @param[in] i_start The starting bit position in this
        /// @param[in] i_count The length, in bits, the user wants copied.
        /// @param[out] o_dest Where to put the data
        ///
        template< typename OT >
        fapi2::ReturnCode _extract(bits_type i_start,
                                   bits_type i_count,
                                   OT* o_dest) const;

        ///
        /// @brief Internal insertFromRight
        /// @param[in] i_data, the incoming data
        /// @param[in] i_data_length The length in bits of the incoming data
        /// @param[in] i_target_start_bit The starting bit position in this
        /// @param[in] i_length The length, in bits, the user wants copied.
        ///
        template<typename OT>
        fapi2::ReturnCode _insertFromRight(const OT& i_data,
                                           bits_type i_data_length,
                                           bits_type i_targetStart,
                                           bits_type i_len);

    };

    inline variable_buffer::
    variable_buffer(bits_type i_value):
        buffer_base(i_value),
        iv_perceived_bit_length(i_value)
    {
        static_assert(std::is_same<unit_type, uint32_t>::value,
                      "code currently needs unit_type to be a unit32_t");
    }

    inline variable_buffer::
    variable_buffer(const std::initializer_list<unit_type>& i_value):
        buffer_base(i_value),
        iv_perceived_bit_length(i_value.size() * sizeof(unit_type) * 8)
    {
        static_assert(std::is_same<unit_type, uint32_t>::value,
                      "code currently needs unit_type to be a unit32_t");
    }




    //
    // Generic insert
    //
    template<typename OT>
    inline fapi2::ReturnCode variable_buffer::insert(const OT& i_source,
                                                     bits_type i_targetStart,
                                                     bits_type i_len,
                                                     bits_type i_sourceStart)
    {
        return _insert((unit_type*)(&i_source), parameterTraits<OT>::bit_length,
                       &(iv_data[0]), getBitLength(),
                       i_sourceStart, i_targetStart, i_len);
    }

    //
    // Insert another variable_bufer
    //
    template<>
    inline fapi2::ReturnCode variable_buffer::insert(
        const variable_buffer& i_data,
        bits_type i_targetStart,
        bits_type i_len,
        bits_type i_sourceStart)
    {
        return _insert((unit_type*)&(i_data()[0]), i_data.getBitLength(),
                       &(iv_data[0]), getBitLength(),
                       i_sourceStart, i_targetStart, i_len);
    }

    //
    // Generic insert from right
    //
    template<typename OT>
    inline fapi2::ReturnCode variable_buffer::insertFromRight(
        const OT& i_data,
        bits_type i_targetStart,
        bits_type i_len)
    {
        _insertFromRight(i_data, parameterTraits<OT>::bit_length, i_targetStart, i_len);
    }

    //
    // variable_buffer insert from right
    //
    template<>
    inline fapi2::ReturnCode variable_buffer::insertFromRight(
        const variable_buffer& i_data,
        bits_type i_targetStart,
        bits_type i_len)
    {
        const bits_type bit_length_of_source = i_data.getBitLength();
        _insertFromRight(i_data, bit_length_of_source, i_targetStart, i_len);
    }




    //
    // Generic extract. Extract is an insert with the arguments reversed.
    //
    template<typename OT>
    inline fapi2::ReturnCode variable_buffer::extract(
        OT& i_data,
        bits_type i_start,
        bits_type i_len) const
    {
        // Needed to trick the compiler into matching the template below
        const bits_type max_length = parameterTraits<OT>::bit_length;

        // If thy didn't pass an i_len, assume they want all the data
        // which will fit.
        if (i_len == ~0)
        {
            i_len = max_length;
        }

        return _insert((container_unit*)&iv_data[0], getBitLength(),
                       &i_data, max_length,
                       i_start, 0U, i_len);
    }

    //
    // Extract in to another variable_bufer
    //
    template<>
    inline fapi2::ReturnCode variable_buffer::extract(
        variable_buffer& i_data,
        bits_type i_start,
        bits_type i_len) const
    {
        // If thy didn't pass an i_len, assume they want all the data
        // which will fit.
        if (i_len == ~0)
        {
            i_len = i_data.getBitLength();
        }
        return _insert((container_unit*)&iv_data[0], getBitLength(),
                       &(i_data()[0]), i_data.getBitLength(),
                       i_start, 0U, i_len);
    }



    template<typename OT>
    inline fapi2::ReturnCode variable_buffer::_insertFromRight(
        const OT& i_data,
        bits_type i_data_length,
        bits_type i_targetStart,
        bits_type i_len)
    {
        // If they didn't pass in a length, assume they want all the i_data
        // which will fit.
        if( i_len == ~0 )
        {
            // The longest the length can be is the length of the data
            // This is the miniumum of the length of the data or the
            // number of available bits
            i_len = std::min(i_data_length, getBitLength() - i_targetStart);
        }

        // Source start is the length, counted from the right
        return insert(i_data, i_targetStart, i_len, i_data_length - i_len);
    }

    //
    // Invalid specializations of set
    //
    /// @cond
    // Sepcialize the variable_buffer version to to "undefined" so the
    // linker complains loudly if anyone calls it.
#if 0
    template<>
    inline fapi2::ReturnCode buffer_base::set(
        const variable_buffer& i_value,
        bits_type i_offset);
#endif
    /// @endcond

};


#endif
