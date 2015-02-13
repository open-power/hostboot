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
                          (B < bufferTraits<T>::bits_per_unit), "failed range check");

            // Force iv_data to be dependent on the template type to force
            // its look up in the second phase
            this->iv_data |= (static_cast<T>(1)) << (bufferTraits<T>::bits_per_unit - B - 1);
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
                          (B < bufferTraits<T>::bits_per_unit), "failed range check");

            this->iv_data &= buffer<T>().setBit<B>().invert();
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
                          (B < bufferTraits<T>::bits_per_unit), "failed range check");

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
                if (i_bit >= bufferTraits<T>::bits_per_unit)
                {
                    return FAPI2_RC_INVALID_PARAMETER;
                }

                // Force iv_data to be dependent on the template type to force
                // its look up in the second phase
                this->iv_data |=
                    (static_cast<T>(1)) << (bufferTraits<T>::bits_per_unit - i_bit - 1);
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
        /// @brief operator==()
        ///
#ifdef DOXYGEN
        buffer<T>& operator==(const T& rhs) const;
#endif

        ///
        /// @brief operator!=()
        ///
#ifdef DOXYGEN
        bool operator!=(const T& rhs) const;
#endif

        ///
        /// @brief operator~()
        ///
#ifdef DOXYGEN
        bool operator~(const T& rhs) const;
#endif
        ///
        /// @brief Copy part of a OT into the DataBuffer
        /// @tparam TS Start bit to insert into (target start)
        /// @tparam L Length of bits to insert
        /// @tparam SS Start bit in source
        /// @tparam OT the type of the incoming (origin) data
        /// @param[in] i_datain OT value to copy into DataBuffer
        ///    - data is taken left aligned
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template<bits_type TS, bits_type L, bits_type SS, typename OT>
        inline void insert(const OT i_datain)
        {
            const bits_type target_length = parameterTraits<T>::bit_length;
            const bits_type source_length = parameterTraits<OT>::bit_length;

            // Error if input data don't make sense
            static_assert((TS + L) <= target_length,
                          "insert(): (Target Start + Len) is out of bounds");
            static_assert((SS + L) <= source_length,
                          "insert(): (Source Start + Len) is out of bounds");
            static_assert(TS < target_length,
                          "insert(): Target Start is out of bounds");
            static_assert(SS < source_length,
                          "insert(): Source Start is out of bounds");

            // Get mask value for Target buffer
            // Note: Need "& ((T)-1) because bit shift left for Target buffer doesn't roll off
            T mask =((T(~0) << (target_length - L)) & T(~0)) >> TS;

            // Calculate the equivalent position of the input Source start for the size of the Target buffer.

            // Assume OT is smaller (sizeof(T) > sizeof(OT))
            uint64_t sourceShift = abs(TS - ((target_length - source_length) + SS));
            uint64_t sourceAlign = T(i_datain) << sourceShift;

            if (sizeof(T) == sizeof(OT))
            {
                sourceShift = abs(SS - TS);
                sourceAlign = (SS > TS) ? ((T)i_datain) << sourceShift : ((T)i_datain) >> sourceShift;
            }

            if (sizeof(T) < sizeof(OT))
            {
                sourceShift = source_length - target_length;
                if (SS <= sourceShift)
                {
                    sourceShift = sourceShift +  TS - SS;
                    sourceAlign = ((OT)i_datain) >> sourceShift;
                }

                // (SS > sourceShift)
                else
                {
                    if (sourceShift > TS)
                    {
                        sourceShift = SS - sourceShift - TS;
                        sourceAlign = OT(i_datain) << sourceShift;
                    }
                    else
                    {
                        sourceShift = SS - sourceShift;
                        sourceAlign = (sourceShift < TS) ? OT(i_datain) >> sourceShift : OT(i_datain);
                    }
                }
            }

            this->iv_data = (this->iv_data & ~mask) | (sourceAlign & mask);
            return;
        }

        ///
        /// @brief Copy in a right aligned value
        /// @tparam SB Start bit to insert into
        /// @tparam L Length of bits to insert
        /// @tparam OT the type of the incoming (origin) data
        /// @param[in] i_datain OT value to copy into DataBuffer
        ///    - data is taken right aligned
        /// @note Data is assumed to be aligned on the word boundary of L
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template<bits_type TS, bits_type L, typename OT>
        inline void insertFromRight(const OT i_datain)
        {
            // Error if input data don't make sense
            static_assert(L < parameterTraits<OT>::bit_length,
                          "insertFromRight(): Len >= input buffer");
            static_assert(TS < parameterTraits<T>::bit_length,
                          "insertFromRight(): Target Start is out of bounds");
            static_assert((TS + L) <= parameterTraits<T>::bit_length,
                          "InsertFromRight(): (Target Start + Len) is out of bounds");

            this->insert<TS, L, parameterTraits<OT>::bit_length - L>(i_datain);
            return;
        }

        ///
        /// @brief Copy data from this buffer into an OT
        /// @tparam TS Start bit to insert into (target start)
        /// @tparam L Length of bits to insert
        /// @tparam SS Start bit in source
        /// @tparam OT the type of the outgoing (target)
        /// @param[out] o_out OT to copy into - data is placed left aligned
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template<bits_type TS, bits_type L, bits_type SS, typename OT>
        inline void extract(OT& o_out)
        {
            // Extraction is just an insert into o_out

            buffer<OT> out(o_out);
            out.insert<TS, L, SS>(this->iv_data);
            o_out = out;
            return;
        }

#if 0
        ///
        /// @brief Copy data from this buffer into an OT and right justify
        /// @tparam OT the type of the outgoing data - defaults to T
        /// @tparam SB Start bit to insert into - defaults to 0
        /// @tparam SS Start bit in o_out - default value is zero
        /// @tparam L Length of bits to copy - defaults to sizeof(OT) * 8
        /// @param[out] o_out OT to copy into - data is placed right aligned
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        /// @post Data is copied from specified location to o_out, right
        /// aligned. Data is only right aligned if L < sizeof(bits_type)
        ///
        template< typename OT = T, bits_type L = parameterTraits<OT>::bit_length,
                  bits_type SB = 0, bits_type SS = 0 >
        void extractFromRight(OT& o_out);
#endif
        ///@}
    };
};

#endif
