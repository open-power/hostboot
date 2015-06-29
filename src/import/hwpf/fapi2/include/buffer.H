/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/buffer.H $                                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2012,2015                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 * @file buffer.H
 * @brief definitions for fapi2 variable integral buffers
 */

#ifndef __FAPI2_INTEGRAL_BUFFER__
#define __FAPI2_INTEGRAL_BUFFER__

#include <buffer_parameters.H>
#include <buffer_traits.H>
#include <return_code.H>

namespace fapi2
{
/// @brief Class representing a FAPI buffer<T>
/// @tparam T, the integral type of the buffer (uint16_t, uint64_t, etc.)
template <typename T, typename TT = bufferTraits<T> >
class buffer
{
    public:
        /// Shortcut typedef to get to our traits class
        typedef typename TT::bits_type bits_type;

        ///
        /// @brief Integral buffer assignment constructor
        /// @param[in] i_value initial value of the buffer
        /// Meaningless for variable types and thus protected.
        ///
        inline buffer(T i_value = 0):
            iv_data(i_value)
        {
        }

        ~buffer(void) = default;

        #if !defined(DOXYGEN) && defined(FAPI2_DEBUG)
        /// @brief Print the contents of the buffer to stdout
        inline void print(void) const
        {
            TT::print(iv_data);
        }
        #endif

        ///
        /// @brief Get the contents of the buffer
        /// @return The contents of the buffer
        ///
        inline operator T() const
        {
            return iv_data;
        }

        ///
        /// @brief Get the contents of the buffer
        /// @return The contents of the buffer
        ///
        inline operator T&()
        {
            return iv_data;
        }

        ///
        /// @brief Get the contents of the buffer
        /// @return The contents of the buffer
        ///
        inline T& operator()(void)
        {
            return iv_data;
        }

        ///
        /// @brief Get the contents of the buffer
        /// @return Reference to the contents of the buffer
        ///
        inline const T& operator()(void) const
        {
            return iv_data;
        }

        /// @name Buffer Manipulation Functions
        ///@{

        ///
        /// @brief Set an OT of data in buffer
        /// @param[in] i_value sizeof(OT) bits of data
        /// @param[in] i_offset Start OT (start word, for example) in buffer
        ///            - defaults to 0 (will by default write the left most element)
        /// @return FAPI2_RC_SUCCESS on success, FAPI2_RC_OVERFLOW otherwise
        /// @note This is is only available for integral types. To set a
        ///    variable_buffer into a variable_buffer, use insert()
        ///
        template< typename OT>
        inline fapi2::ReturnCode set(OT i_value, const bits_type i_offset = 0)
        {
            // Compile time check to make sure OT is integral
            static_assert( std::is_integral<OT>::value,
                           "Input must be an integral type" );

            const uint32_t length = TT:: template size<OT>(iv_data);
            static const bits_type bits_in_value = parameterTraits<OT>::bit_length();
            const bits_type bit_length = TT::bit_length(iv_data);

            if (i_offset + bits_in_value >= bit_length)
            {
                return FAPI2_RC_OVERFLOW;
            }

            // Create mask if part of this byte is not in the valid part of the buffer,
            // Shift it left by the amount of unused bits,
            // Clear the unused bits
            if (((i_offset + 1) == length) && (bit_length % bits_in_value))
            {
                i_value &= parameterTraits<OT>::mask() << ((bits_in_value * length) -
                           bit_length);
            }

            parameterTraits<OT>::template write_element<typename TT::unit_type>
            (TT::get_address(iv_data), i_value, i_offset);
            return FAPI2_RC_SUCCESS;
        }

        /// @name Bit/Word Manipulation Functions
        ///@{

        ///
        /// @brief Return the length of the buffer in bits
        /// @return Length in bits
        ///
        inline constexpr uint32_t getBitLength(void) const
        {
            return TT::bit_length(iv_data);
        }

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
            return TT::template size<OT>(iv_data);
        }

        ///
        /// @brief Templated setBit for integral types
        /// @tparam B the bit number to set.
        /// @tparam C the count of bits to set, defaults to 1
        /// @return buffer& Useful for method chaining
        /// @note 0 is left-most
        /// @note Example: fapi2::buffer<uint64_t>().setBit<3>();
        ///
        template< bits_type B, bits_type C = 1 >
        inline buffer& setBit(void)
        {
            static_assert((B >= 0) &&
                          ((B + C - 1) < TT::bits_per_unit()), "failed range check");

            // This would be a candidate for a fast_mask (see variable_buffer) but
            // we'd need tables for all the integral types which maybe we need to
            // do ...
            iv_data |= (T(~0) >> (TT::bits_per_unit() - C)) << (TT::bits_per_unit() - B -
                       C);
            return *this;
        }

        ///
        /// @brief Set a bit in the buffer
        /// @param[in] i_bit the bit number to set.
        /// @param[in] i_count the count of bits to set, defaults to 1
        /// @note 0 is left-most
        /// @return FAPI2_RC_SUCCESS if OK
        ///
        inline fapi2::ReturnCode setBit(const bits_type& i_bit,
                                        const bits_type& i_count = 1)
        {
            if ((i_count + i_bit - 1) >= TT::bits_per_unit())
            {
                return FAPI2_RC_INVALID_PARAMETER;
            }

            iv_data |= (T(~0) >> (TT::bits_per_unit() - i_count)) <<
                       (TT::bits_per_unit() - i_bit - i_count);

            return FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Clear a bit in buffer
        /// @tparam B Bit in buffer to clear.
        /// @tparam C the count of bits to clear, defaults to 1
        /// @return buffer& Useful for method chaining
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template< bits_type B, bits_type C = 1>
        inline buffer& clearBit(void)
        {
            static_assert((B >= 0) &&
                          ((B + C - 1)< TT::bits_per_unit()), "failed range check");

            iv_data &= buffer<T>().setBit<B, C>().invert();
            return *this;
        }

        ///
        /// @brief Clear a bit in the buffer
        /// @param[in] i_bit the bit number to clear.
        /// @param[in] i_count the count of bits to clear, defaults to 1
        /// @note 0 is left-most
        /// @return FAPI2_RC_SUCCESS if OK
        ///
        inline fapi2::ReturnCode clearBit(const bits_type& i_bit,
                                          const bits_type& i_count = 1)
        {
            if ((i_count + i_bit - 1) >= TT::bits_per_unit())
            {
                return FAPI2_RC_INVALID_PARAMETER;
            }

            fapi2::buffer<T> l_scratch;

            if (l_scratch.setBit(i_bit, i_count) != FAPI2_RC_SUCCESS)
            {
                return FAPI2_RC_INVALID_PARAMETER;
            }

            iv_data &= l_scratch.invert();

            return FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Write a bit in buffer to a given value
        /// @tparam B Bit in buffer to write
        /// @tparam C the count of bits to write, defaults to 1
        /// @return buffer& Useful for method chaining
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template< bits_type B, bits_type C = 1 >
        inline buffer& writeBit(const bool i_value)
        {
            static_assert((B >= 0) &&
                          ((B + C - 1)< TT::bits_per_unit()), "failed range check");

            (i_value == 0) ? clearBit<B, C>() : setBit<B, C>();
            return *this;
        }


        ///
        /// @brief Invert bit
        /// @tparam B Bit in buffer to invert.
        /// @tparam C the count of bits to flip, defaults to 1
        /// @return buffer& Useful for method chaining
        /// @note Asserting that all the parameters are known at
        /// compile time so this can be templated only. If that is not
        /// the case we can add a function parameter version.
        ///
        template< bits_type B, bits_type C = 1 >
        inline buffer& flipBit(void)
        {
            static_assert((B >= 0) &&
                          ((B + C - 1) < TT::bits_per_unit()), "failed range check");

            iv_data ^= buffer<T>().setBit<B, C>();
            return *this;
        }

        ///
        /// @brief Get the value of a bit in the buffer
        /// @tparam B Bit in buffer to get.
        /// @tparam C the count of bits to get, defaults to 1
        /// @return true if *any* bit is on, false if *every* bit is off
        ///
        template< bits_type B, bits_type C = 1>
        inline bool getBit(void) const
        {
            return buffer<T>().setBit<B, C>() & iv_data;
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
            (0 == X) ? TT::clear(iv_data) : TT::set(iv_data);
            return *this;
        }

        ///
        /// @brief Invert entire buffer
        /// @return buffer_base&, Useful for method chaining
        ///
        inline buffer& invert(void)
        {
            TT::invert(iv_data);
            return *this;
        }

        ///
        /// @brief Bit reverse entire buffer
        /// @return buffer_base&, Useful for method chaining
        ///
        inline buffer& reverse(void)
        {
            TT::reverse(iv_data);
            return *this;
        }


        ///@}

        /// @name Buffer Manipulation Functions
        ///@{

        ///
        /// @brief Get a pointer to the buffer bits
        /// @return Pointer to the buffer itself
        ///
        inline T* pointer(void)
        {
            return &iv_data;
        }

        // Note: Many (all?) of these are not needed and the compiler complains
        // as the cast to T yields a better operator. There are here mainly for
        // documenation purposes.

        ///
        /// @brief operator>>()
        ///
        #ifdef DOXYGEN
        inline buffer<T>& operator>>(bits_type i_shiftnum);
        #endif

        ///
        /// @brief operator<<()
        ///
        #ifdef DOXYGEN
        inline buffer<T>& operator<<(bits_type i_shiftnum);
        #endif

        ///
        /// @brief operator+()
        ///
        #ifdef DOXYGEN
        inline buffer<T>& operator+(const T& rhs);
        #endif

        ///
        /// @brief operator+=()
        ///
        #ifdef DOXYGEN
        inline buffer<T>& operator+=(const T& rhs);
        #endif

        ///
        /// @brief operator|=()
        ///
        #ifdef DOXYGEN
        inline buffer<T>& operator|=(const T& rhs);
        #endif

        ///
        /// @brief operator&=()
        ///
        #ifdef DOXYGEN
        inline buffer<T>& operator&=(const T& rhs);
        #endif

        ///
        /// @brief operator|()
        ///
        #ifdef DOXYGEN
        inline buffer<T>& operator|(const T& rhs);
        #endif

        ///
        /// @brief operator&()
        ///
        #ifdef DOXYGEN
        inline buffer<T>& operator&(const T& rhs);
        #endif

        ///
        /// @brief operator^=()
        ///
        #ifdef DOXYGEN
        inline buffer<T>& operator^=(const T& rhs);
        #endif

        ///
        /// @brief operator~()
        ///
        #ifdef DOXYGEN
        inline buffer<T>& operator~(const T& rhs) const;
        #endif

        ///
        /// @brief operator==()
        ///
        #ifdef DOXYGEN
        inline bool operator==(const T& rhs) const;
        #endif

        ///
        /// @brief operator!=()
        ///
        #ifdef DOXYGEN
        inline bool operator!=(const T& rhs) const;
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
            const uint64_t target = static_cast<uint64_t>(iv_data);

            const bits_type source_start = parameterTraits<uint64_t>::bit_length() -
                                           (source_length - SS);
            const bits_type target_start = parameterTraits<uint64_t>::bit_length() -
                                           (target_length - TS);

            // Get mask value for Target buffer
            // Note: Need "& 0UL" because bit shift left for Target buffer doesn't roll off
            uint64_t mask = ((~0UL << (parameterTraits<uint64_t>::bit_length() - L)) & ~0UL)
                            >> target_start;

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

            iv_data = ((target & ~mask) | (source & mask));
            return *this;
        }

        ///
        /// @brief Copy part of a OT into the DataBuffer
        /// @tparam OT the type of the incoming (origin) data
        /// @param[in] i_datain OT value to copy into DataBuffer
        ///    - data is taken left aligned
        /// @param[in] Start bit to insert into (target start)
        /// @param[in] Length of bits to insert
        /// @param[in] Start bit in source - defaults to bit 0

        /// @return FAPI2_RC_SUCCESS if successful
        ///
        template<typename OT>
        fapi2::ReturnCode insert(const OT i_datain, const bits_type i_targetStart,
                                 const bits_type i_len, const bits_type i_sourceStart = 0)
        {
            const bits_type target_length = parameterTraits<T>::bit_length();
            const bits_type source_length = parameterTraits<OT>::bit_length();

            // Error if input data don't make sense
            if ((i_targetStart + i_len) > target_length)
            {
                FAPI_ERR("insert(): (Target Start + Len) is out of bounds");
                return FAPI2_RC_INVALID_PARAMETER;
            }

            if ((i_sourceStart + i_len) > source_length)
            {
                FAPI_ERR("insert(): (Source Start + Len) is out of bounds");
                return FAPI2_RC_INVALID_PARAMETER;
            }

            if (i_targetStart >= target_length)
            {
                FAPI_ERR("insert(): Target Start is out of bounds");
                return FAPI2_RC_INVALID_PARAMETER;
            }

            if (i_sourceStart >= source_length)
            {
                FAPI_ERR("insert(): Source Start is out of bounds");
                return FAPI2_RC_INVALID_PARAMETER;
            }

            // Normalize the input to 2 64 bit integers and adjust the starts accordingly
            uint64_t source = static_cast<uint64_t>(i_datain);
            const uint64_t target = static_cast<uint64_t>(iv_data);

            const bits_type source_start = parameterTraits<uint64_t>::bit_length() -
                                           (source_length - i_sourceStart);
            const bits_type target_start = parameterTraits<uint64_t>::bit_length() -
                                           (target_length - i_targetStart);

            // Get mask value for Target buffer
            // Note: Need "& 0UL" because bit shift left for Target buffer doesn't roll off
            uint64_t mask = ((~0UL << (parameterTraits<uint64_t>::bit_length() - i_len)) &
                             ~0UL) >> target_start;

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

            iv_data = ((target & ~mask) | (source & mask));
            return FAPI2_RC_SUCCESS;
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
        ///
        template<bits_type TS, bits_type L, typename OT>
        inline buffer& insertFromRight(const OT i_datain)
        {
            // Error if input data don't make sense
            static_assert(L <= parameterTraits<OT>::bit_length(),
                          "insertFromRight(): Len > input buffer");
            static_assert(TS < parameterTraits<T>::bit_length(),
                          "insertFromRight(): Target Start is out of bounds");
            static_assert((TS + L) <= parameterTraits<T>::bit_length(),
                          "InsertFromRight(): (Target Start + Len) is out of bounds");

            this->insert<TS, L, parameterTraits<OT>::bit_length() - L>(i_datain);
            return *this;
        }

        ///
        /// @brief Copy in a right aligned value
        /// @tparam OT the type of the incoming (origin) data
        /// @param[in] i_datain OT value to copy into DataBuffer
        ///    - data is taken right aligned
        /// @param[in] Start bit to insert into
        /// @param[in] Length of bits to insert
        /// @return FAPi2_RC_SUCCESS if no error
        /// @note Data is assumed to be aligned on the word boundary of L
        ///
        template<typename OT>
        fapi2::ReturnCode insertFromRight(const OT i_datain,
                                          const bits_type i_targetStart,
                                          const bits_type i_len)
        {
            // Error if input data don't make sense
            if ((i_targetStart + i_len) > parameterTraits<T>::bit_length())
            {
                FAPI_ERR("insertFromRight(): (Target Start + Len) is out of bounds");
                return FAPI2_RC_INVALID_PARAMETER;
            }

            if (i_targetStart >= parameterTraits<T>::bit_length())
            {
                FAPI_ERR("insertFromRight(): Target Start is out of bounds");
                return FAPI2_RC_INVALID_PARAMETER;
            }

            if (i_len > parameterTraits<OT>::bit_length())
            {
                FAPI_ERR("insertFromRight(): Len > input buffer");
                return FAPI2_RC_INVALID_PARAMETER;
            }

            return this->insert(i_datain, i_targetStart, i_len,
                                parameterTraits<OT>::bit_length() - i_len);
        }

        ///
        /// @brief Copy data from this buffer into an OT
        /// @tparam SS Start bit in source
        /// @tparam L Length of bits to insert
        /// @tparam TS Start bit to insert into (target start)
        /// @tparam OT the type of the outgoing (target)
        /// @param[out] o_out OT to copy into - data is placed left aligned
        /// @return const buffer& Useful for method chaining
        ///
        template<bits_type SS, bits_type L, bits_type TS = 0, typename OT>
        inline const buffer& extract(OT& o_out) const
        {
            // Extraction is just an insert into o_out

            buffer<OT> out(o_out);
            out.insert<TS, L, SS>(iv_data);
            o_out = out;
            return *this;
        }

        ///
        /// @brief Copy data from this buffer into an OT
        /// @tparam SS Start bit in source
        /// @tparam L Length of bits to insert
        /// @tparam TS Start bit to insert into (target start)
        /// @tparam OT the type of the outgoing (target)
        /// @param[out] o_out OT to copy into - data is placed left aligned
        /// @return buffer& Useful for method chaining
        ///
        template<bits_type SS, bits_type L, bits_type TS = 0, typename OT>
        inline buffer& extract(OT& o_out)
        {
            // Extraction is just an insert into o_out

            buffer<OT> out(o_out);
            out.insert<TS, L, SS>(iv_data);
            o_out = out;
            return *this;
        }

        ///
        /// @brief Copy data from this buffer into an OT
        /// @tparam OT the type of the outgoing (target)
        /// @param[out] o_out OT to copy into - data is placed left aligned
        /// @param[in] Start bit in source
        /// @param[in] Length of bits to extract
        /// @param[in] Start bit to insert into (target start)
        /// @return FAPI2_RC_SUCCESS if ok
        ///
        template<typename OT>
        fapi2::ReturnCode extract(OT& o_out, const bits_type i_sourceStart,
                                  const bits_type i_len, const bits_type i_targetStart = 0) const
        {
            // Extraction is just an insert into o_out

            buffer<OT> out(o_out);

            if (out.insert(iv_data, i_targetStart, i_len,
                           i_sourceStart) != FAPI2_RC_SUCCESS)
            {
                return FAPI2_RC_INVALID_PARAMETER;
            }

            o_out = out;
            return FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Copy data from this buffer into an OT and right justify
        /// @tparam SS Start bit to insert into (source start)
        /// @tparam L Length of bits to extract
        /// @tparam OT the type of the outgoing (target)
        /// @param[out] o_out OT to copy into - data is placed right aligned
        /// @return const buffer& Useful for method chaining
        ///
        template<bits_type SS, bits_type L, typename OT>
        inline const buffer& extractToRight(OT& o_out) const
        {
            extract<SS, L, parameterTraits<OT>::bit_length() - L>(o_out);
            return *this;
        }

        ///
        /// @brief Copy data from this buffer into an OT and right justify
        /// @tparam SS Start bit to insert into (source start)
        /// @tparam L Length of bits to extract
        /// @tparam OT the type of the outgoing (target)
        /// @param[out] o_out OT to copy into - data is placed right aligned
        /// @return buffer& Useful for method chaining
        ///
        template<bits_type SS, bits_type L, typename OT>
        inline buffer& extractToRight(OT& o_out)
        {
            extract<SS, L, parameterTraits<OT>::bit_length() - L>(o_out);
            return *this;
        }

        ///
        /// @brief Copy data from this buffer into an OT and right justify
        /// @tparam OT the type of the outgoing (target)
        /// @param[out] o_out OT to copy into - data is placed right aligned
        /// @param[in] Start bit to insert into (source start)
        /// @param[in] Length of bits to insert
        /// @return FAPI2_RC_SUCCESS if ok
        ///
        template<typename OT>
        fapi2::ReturnCode extractToRight(OT& o_out, const bits_type i_sourceStart,
                                         const bits_type i_len) const
        {
            return extract(o_out, i_sourceStart, i_len,
                           parameterTraits<OT>::bit_length() - i_len);
        }

        ///@}

    private:
        /// The contents of the buffer
        T iv_data;
};
}

#endif
