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
 * @file buffer.H
 * @brief definitions for fapi2 variable integral buffers
 */

#ifndef __FAPI2_INTEGRAL_BUFFER__
#define __FAPI2_INTEGRAL_BUFFER__

#include <buffer_base.H>
#include <return_code.H>

namespace fapi2
{
    /// @brief Class representing a FAPI buffer<T>
    /// @note Buffers support method chaining. So, rather than
    /// this
    /// @code
    /// buffer<T> mask;
    /// mask.setBit<B>();
    /// mask.invert();
    /// my_buffer &= mask;
    /// @endcode
    /// You can do
    /// @code
    /// my_buffer &= buffer<T>().setBit<B>.invert();
    /// @endcode
    template <typename T>
    class buffer : public buffer_base<T>
    {
    public:
        /// Shortcut typedef to map to our traits class
        typedef typename buffer_base<T, buffer>::bits_type bits_type;

        ///
        /// @brief Integral buffer assignment constructor
        /// @param[in] i_value initial value of the buffer
        /// Meaningless for variable types and thus protected.
        ///
        inline buffer(T i_value = 0)
            {
                // Why not an initializer list? That would force buffer_base<T>
                // to have a ctor which took a T, and I want to avoid that in
                // the generic case: this makes it more clear that the two
                // ctor's (integral and container) behave very differently.
                // variable_buffers also have a ctor which takes a single
                // numerical value, and that represents a bit count, not an
                // initial value.
                this->iv_data = i_value;
            }


        /// @name Bit/Word Manipulation Functions
        ///@{

        ///
        /// @brief Return the length of the buffer in bits
        /// @return Length in bits
        ///
        inline constexpr uint32_t getBitLength(void) const
            { return bufferTraits<T>::bit_length(this->iv_data); }

        ///
        /// @brief Return the length of the buffer in OT units
        /// @return Length in OT units rounded up
        /// @tparam OT the type to get the length of. For example, if one
        /// wanted the length in double words, OT would be uint64_t
        /// (getLength<uint64_t>().) Similarly, to get the length in words,
        /// getLength<uin32_t>().
        ///
        template< typename OT >
        inline constexpr uint32_t getLength(void) const
        {
            return bufferTraits<T>::template size<OT>(this->iv_data);
        }

        ///
        /// @brief Templated setBit for integral types
        /// @tparam B the bit number to set.
        /// @return buffer& Useful for method chaining
        /// @note 0 is left-most
        /// @note Example: fapi2::buffer<uint64_t>().setBit<3>();
        ///
        template <bits_type B>
        inline buffer& setBit(void)
        {
            static_assert((B >= 0) &&
                          (B < bufferTraits<T>::bits_per_unit()), "failed range check");

            // Force iv_data to be dependent on the template type to force
            // its look up in the second phase
            this->iv_data |= (static_cast<T>(1)) << (bufferTraits<T>::bits_per_unit() - B - 1);
            return *this;
        }

        ///
        /// @brief Clear a bit in buffer
        /// @tparam B Bit in buffer to clear.
        /// @return buffer& Useful for method chaining
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template< bits_type B >
        inline buffer& clearBit(void)
        {
            static_assert((B >= 0) &&
                          (B < bufferTraits<T>::bits_per_unit()), "failed range check");

            this->iv_data &= buffer<T>().setBit<B>().invert();
            return *this;
        }

        ///
        /// @brief Write a bit in buffer to a given value
        /// @tparam B Bit in buffer to write
        /// @return buffer& Useful for method chaining
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template< bits_type B >
        inline buffer& writeBit(const bool i_value)
        {
            static_assert((B >= 0) &&
                          (B < bufferTraits<T>::bits_per_unit()), "failed range check");

            (i_value == 0) ? clearBit<B>() : setBit<B>();
            return *this;
        }


        ///
        /// @brief Invert bit
        /// @tparam B Bit in buffer to invert.
        /// @return buffer& Useful for method chaining
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template< bits_type B >
        inline buffer& flipBit(void)
        {
            static_assert((B >= 0) &&
                          (B < bufferTraits<T>::bits_per_unit()), "failed range check");

            this->iv_data ^= buffer<T>().setBit<B>();
            return *this;
        }

        ///
        /// @brief Set a bit in the buffer
        /// @param[in] i_bit the bit number to set.
        /// @note 0 is left-most
        /// @return FAPI2_RC_SUCCESS if OK
        ///
        inline fapi2::ReturnCode setBit(const bits_type& i_bit)
            {
                if (i_bit >= bufferTraits<T>::bits_per_unit())
                {
                    return FAPI2_RC_INVALID_PARAMETER;
                }

                // Force iv_data to be dependent on the template type to force
                // its look up in the second phase
                this->iv_data |=
                    (static_cast<T>(1)) << (bufferTraits<T>::bits_per_unit() - i_bit - 1);
                return FAPI2_RC_SUCCESS;
            }

        ///
        /// @brief Get the value of a bit in the buffer
        /// @tparam B Bit in buffer to get.
        /// @return true if bit is on, false if bit is off
        ///
        template< bits_type B >
        inline bool getBit(void) const
            {
                return buffer<T>().setBit<B>() & this->iv_data;
            }

        ///
        /// @brief Set and entire buffer to X's
        /// @tparam X {0,1} depending if you want to clear (0)
        /// or fill (1) a buffer
        /// @return buffer_base&, Useful for method chaining
        ///
        template< uint8_t X >
        inline buffer& flush(void)
            {
                static_assert( (X == 1) || (X == 0), "bad argument to flush" );
                (0 == X) ? bufferTraits<T>::clear(this->iv_data) : bufferTraits<T>::set(this->iv_data);
                return *this;
            }

        ///
        /// @brief Invert entire buffer
        /// @return buffer_base&, Useful for method chaining
        ///
        inline buffer& invert(void)
            { bufferTraits<T>::invert(this->iv_data); return *this; }

        ///
        /// @brief Bit reverse entire buffer
        /// @return buffer_base&, Useful for method chaining
        ///
        inline buffer& reverse(void)
            { bufferTraits<T>::reverse(this->iv_data); return *this; }


        ///@}

        /// @name Buffer Manipulation Functions
        ///@{

        ///
        /// @brief Get a pointer to the buffer bits
        /// @return Pointer to the buffer itself
        ///
        inline T* pointer(void) { return &this->iv_data; }

        // Note: Many (all?) of these are not needed and the compiler complains
        // as the cast to T yields a better operator. There are here mainly for
        // documenation purposes.

        ///
        /// @brief operator>>()
        ///
#ifdef DOXYGEN
        buffer<T>& operator>>(bits_type i_shiftnum);
#endif

        ///
        /// @brief operator<<()
        ///
#ifdef DOXYGEN
        buffer<T>& operator<<(bits_type i_shiftnum);
#endif

        ///
        /// @brief operator+()
        ///
#ifdef DOXYGEN
        buffer<T>& operator+(const T& rhs);
#endif

        ///
        /// @brief operator+=()
        ///
#ifdef DOXYGEN
        buffer<T>& operator+=(const T& rhs);
#endif

        ///
        /// @brief operator|=()
        ///
#ifdef DOXYGEN
        buffer<T>& operator|=(const T& rhs);
#endif

        ///
        /// @brief operator&=()
        ///
#ifdef DOXYGEN
        buffer<T>& operator&=(const T& rhs);
#endif

        ///
        /// @brief operator|()
        ///
#ifdef DOXYGEN
        buffer<T>& operator|(const T& rhs);
#endif

        ///
        /// @brief operator&()
        ///
#ifdef DOXYGEN
        buffer<T>& operator&(const T& rhs);
#endif

        ///
        /// @brief operator^=()
        ///
#ifdef DOXYGEN
        buffer<T>& operator^=(const T& rhs);
#endif

        ///
        /// @brief operator~()
        ///
#ifdef DOXYGEN
        buffer<T>& operator~(const T& rhs) const;
#endif

        ///
        /// @brief operator==()
        ///
#ifdef DOXYGEN
        bool operator==(const T& rhs) const;
#endif

        ///
        /// @brief operator!=()
        ///
#ifdef DOXYGEN
        bool operator!=(const T& rhs) const;
#endif

        ///
        /// @brief Copy part of a OT into the DataBuffer
        /// @tparam TS Start bit to insert into (target start)
        /// @tparam L Length of bits to insert
        /// @tparam SS Start bit in source - defaults to bit 0
        /// @tparam OT the type of the incoming (origin) data
        /// @param[in] i_datain OT value to copy into DataBuffer
        ///    - data is taken left aligned
        /// @return buffer& Useful for method chaining
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template<bits_type TS, bits_type L, bits_type SS = 0, typename OT>
        inline buffer& insert(const OT i_datain)
        {
            const bits_type target_length = parameterTraits<T>::bit_length();
            const bits_type source_length = parameterTraits<OT>::bit_length();

            // Error if input data don't make sense
            static_assert((TS + L) <= target_length,
                          "insert(): (Target Start + Len) is out of bounds");
            static_assert((SS + L) <= source_length,
                          "insert(): (Source Start + Len) is out of bounds");
            static_assert(TS < target_length,
                          "insert(): Target Start is out of bounds");
            static_assert(SS < source_length,
                          "insert(): Source Start is out of bounds");

            // Normalize the input to 2 64 bit integers and adjust the starts accordingly
            uint64_t source = static_cast<uint64_t>(i_datain);
            const uint64_t target = static_cast<uint64_t>(this->iv_data);

            const bits_type source_start = parameterTraits<uint64_t>::bit_length() - (source_length - SS);
            const bits_type target_start = parameterTraits<uint64_t>::bit_length() - (target_length - TS);

            // Get mask value for Target buffer
            // Note: Need "& 0UL" because bit shift left for Target buffer doesn't roll off
            uint64_t mask = ((~0UL << (parameterTraits<uint64_t>::bit_length() - L)) & ~0UL) >> target_start;

            // Align the source to the target. Make things signed so we know which way to shift.
            int32_t shift = source_start - target_start;
            if (shift > 0)
            {
                source <<= shift;
            }
            else
            {
                shift = target_start - source_start;
                source >>= shift;
            }

            this->iv_data = ((target & ~mask) | (source & mask));
            return *this;
        }

        ///
        /// @brief Copy in a right aligned value
        /// @tparam SB Start bit to insert into
        /// @tparam L Length of bits to insert
        /// @tparam OT the type of the incoming (origin) data
        /// @param[in] i_datain OT value to copy into DataBuffer
        ///    - data is taken right aligned
        /// @return buffer& Useful for method chaining
        /// @note Data is assumed to be aligned on the word boundary of L
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template<bits_type TS, bits_type L, typename OT>
        inline buffer& insertFromRight(const OT i_datain)
        {
            // Error if input data don't make sense
            static_assert(L < parameterTraits<OT>::bit_length(),
                          "insertFromRight(): Len >= input buffer");
            static_assert(TS < parameterTraits<T>::bit_length(),
                          "insertFromRight(): Target Start is out of bounds");
            static_assert((TS + L) <= parameterTraits<T>::bit_length(),
                          "InsertFromRight(): (Target Start + Len) is out of bounds");

            this->insert<TS, L, parameterTraits<OT>::bit_length() - L>(i_datain);
            return *this;
        }

        ///
        /// @brief Copy data from this buffer into an OT
        /// @tparam TS Start bit to insert into (target start)
        /// @tparam L Length of bits to insert
        /// @tparam SS Start bit in source
        /// @tparam OT the type of the outgoing (target)
        /// @param[out] o_out OT to copy into - data is placed left aligned
        /// @return buffer& Useful for method chaining
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template<bits_type TS, bits_type L, bits_type SS, typename OT>
        inline buffer& extract(OT& o_out)
        {
            // Extraction is just an insert into o_out

            buffer<OT> out(o_out);
            out.insert<TS, L, SS>(this->iv_data);
            o_out = out;
            return *this;
        }

        ///
        /// @brief Copy data from this buffer into an OT and right justify
        /// @tparam SS Start bit to insert into (source start)
        /// @tparam L Length of bits to insert
        /// @tparam OT the type of the outgoing (target)
        /// @param[out] o_out OT to copy into - data is placed right aligned
        /// @return buffer& Useful for method chaining
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template<bits_type SS, bits_type L, typename OT>
        inline buffer& extractToRight(OT& o_out)
        {
            extract<parameterTraits<OT>::bit_length() - L, L, SS>(o_out);
            return *this;
        }

        ///@}
    };
}

#endif
