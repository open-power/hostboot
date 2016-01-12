/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/variable_buffer.H $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2012,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 * @file variable_buffer.H
 * @brief definitions for fapi2 variable length buffers
 */

#ifndef __FAPI2_VARIABLE_BUFFER__
#define __FAPI2_VARIABLE_BUFFER__

#include <buffer_parameters.H>
#include <buffer_traits.H>
#include <return_code_defs.H>
#include <cassert>

namespace fapi2
{
/// @brief Get a 32 bit mask quickly
// This is one of the main reasons we static_assert in the ctor's
// to ensure the unit_type is 32 bits.
inline uint32_t fast_mask32(int32_t i_pos, int32_t i_len)
{
    // generates an arbitrary 32-bit mask using two operations, not too shabby

    static const uint32_t l_mask32[] =
    {
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
///
template<typename unit_type, typename bits_type, typename output_type>
inline fapi2::ReturnCodes _insert(const unit_type* i_source,
                                  bits_type i_source_length,
                                  output_type* i_target,
                                  bits_type i_target_length,
                                  bits_type i_source_start_bit,
                                  bits_type i_target_start_bit,
                                  bits_type i_length)
{
    const bits_type bits_per_input_unit = parameterTraits<unit_type>::bit_length();
    const bits_type bits_per_output_unit = parameterTraits<output_type>::bit_length();

    // targetStart is defaulted to the sizeof(target) - (sizeof(source) - i_source_start_bit)
    // which makes this act like insert from right
    if (i_target_start_bit == static_cast<bits_type>(~0))
    {
        i_target_start_bit = (i_target_length - (i_source_length - i_source_start_bit));
    }

    // len defaults to (sizeof(OT) * 8) - i_source_start_bit
    if (i_length == static_cast<bits_type>(~0))
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
        const bits_type src_idx = i_source_start_bit / bits_per_input_unit;
        const bits_type trg_idx = i_target_start_bit / bits_per_output_unit;

        // "slop" = unaligned bits
        const bits_type src_slop = i_source_start_bit % bits_per_input_unit;
        const bits_type trg_slop = i_target_start_bit % bits_per_output_unit;

        // "cnt" = largest number of bits to be moved each pass
        bits_type cnt = std::min(i_length, bits_per_input_unit);
        cnt = std::min(cnt, bits_per_input_unit - src_slop);
        cnt = std::min(cnt, bits_per_output_unit - trg_slop);

        // generate the source mask only once
        bits_type mask = fast_mask32(src_slop, cnt);

        // read the source bits only once
        bits_type src_bits = i_source[src_idx] & mask;

        // "shift" = amount of shifting needed for target alignment
        int32_t shift = trg_slop - src_slop;

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

    }
    while (0 < i_length);

    return fapi2::FAPI2_RC_SUCCESS;
}
/// @endcond

/// @brief Class representing a FAPI variable_buffer.
/// @remark Variable buffers are buffers which can be variable in length
/// (and "odd sized.") These best represent the FAPI 1.X ecmdDataBuffer,
/// however they are implemented using the same template techniques
/// as the new fapi::buffer.
/// @note Variable buffers are not (presently) declared as std::bitset
/// as bitsets' size is fixed at runtime. It is not clear if this is
/// acceptable for variable_buffers at this time.
/// @note Variable buffers are implemented as a std::vecor of uint32_t
/// as this keeps simple compatibility with ecmdDataBuffers. Cronus (at
//least) need to interwork the two.
class variable_buffer
{

    public:

        /// Shortcut typedef to get to our traits class
        typedef typename bufferTraits<bits_container>::bits_type bits_type;
        /// Shortcut typedef to get to our traits class
        typedef typename bufferTraits<bits_container>::unit_type unit_type;

        ///
        /// @brief Variable buffer constructor
        /// @param[in] i_value number of *bits* (sizeof(uint_type) * 8)
        /// needed.
        inline variable_buffer(bits_type i_value = 0):
            iv_data(_vector_size(i_value)),
            iv_perceived_bit_length(i_value)
        {
            static_assert(std::is_same<unit_type, uint32_t>::value,
                          "code currently needs unit_type to be a unit32_t");
        }
#ifndef NO_INITIALIZER_LIST
        ///
        /// @brief Variable buffer list constructor
        /// @param[in] i_value an initializer list to initialize the container.
        /// @warning Input data is assumed to be right-aligned and must be 32 bits
        ///
        inline variable_buffer(const std::initializer_list<unit_type>& i_value):
            iv_data(i_value),
            iv_perceived_bit_length(i_value.size() * sizeof(unit_type) * 8)
        {
            static_assert(std::is_same<unit_type, uint32_t>::value,
                          "code currently needs unit_type to be a unit32_t");
        }
#endif
        ///
        /// @brief Variable buffer copy constructor
        /// @param[in] i_buffer the buffer to copy from
        ///
        inline variable_buffer(const variable_buffer& i_buffer)
        {
            iv_perceived_bit_length = i_buffer.iv_perceived_bit_length;
            iv_data = i_buffer.iv_data;
        }

        ///
        /// @brief Variable buffer move constructor
        /// @param[in] i_buffer the buffer to move
        ///
        inline variable_buffer(variable_buffer&& i_buffer)
        {
            iv_perceived_bit_length = i_buffer.iv_perceived_bit_length;
            i_buffer.iv_perceived_bit_length = 0;
            iv_data = std::move(i_buffer.iv_data);
        }

        ///
        /// @brief Variable buffer array constructor
        /// @param[in] i_value a uint32_t array to initialize the container.
        /// @param[in] i_length the length of the array in 32-bit words
        /// @param[in] i_bit_length the length of the resulting buffer in bits.
        /// @warning This assumes the underlying container of a variable_buffer
        /// is a uint32_t - which it is.
        /// @note To use this constructor given an ecmdDataBuffer, you would
        /// ecmd.memCopyOut( buffer, ... );
        /// variable_buffer( buffer, ecmd.getCapacity(), ecmd.getBitLength());
        ///
        inline variable_buffer(const uint32_t* i_value, const uint32_t i_length,
                               const uint32_t i_bit_length):
            iv_perceived_bit_length(i_bit_length)
        {
            static_assert(std::is_same<unit_type, uint32_t>::value,
                          "code currently needs unit_type to be a unit32_t");

            // Copy the array in to our vector.
            iv_data.insert(iv_data.end(), i_value, &i_value[i_length]);
        }


#if !defined(DOXYGEN) && defined(FAPI2_DEBUG)
        /// @brief Print the contents of the buffer to stdout
        inline void print(void) const
        {
            bufferTraits<bits_container>::print(iv_data);
        }
#endif

        ///
        /// @brief Get the contents of the buffer
        /// @return The contents of the buffer
        ///
        inline operator bits_container() const
        {
            return iv_data;
        }

        ///
        /// @brief Get the contents of the buffer
        /// @return The contents of the buffer
        ///
        inline operator bits_container& ()
        {
            return iv_data;
        }

        ///
        /// @brief Get the contents of the buffer
        /// @return The contents of the buffer
        ///
        inline bits_container& operator()(void)
        {
            return iv_data;
        }

        ///
        /// @brief Get the contents of the buffer
        /// @return Reference to the contents of the buffer
        ///
        inline const bits_container& operator()(void) const
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
        ///
        template< typename OT>
        inline fapi2::ReturnCodes set(OT i_value, const bits_type i_offset = 0)
        {
            // Compile time check to make sure OT is integral
            static_assert( std::is_integral<OT>::value,
                           "Input must be an integral type" );

            const uint32_t length = bufferTraits<bits_container>:: template size<OT>(iv_data);
            static const bits_type bits_in_value = parameterTraits<OT>::bit_length();
            const bits_type bit_length = bufferTraits<bits_container>::bit_length(iv_data);

            if ((i_offset + bits_in_value) > iv_perceived_bit_length)
            {
                return FAPI2_RC_OVERFLOW;
            }

            // Create mask if part of this byte is not in the valid part of the buffer,
            // Shift it left by the amount of unused bits,
            // Clear the unused bits (doesn't use fastmask as OT isn't always 32 bits)
            if (((i_offset + 1) == length) && (bit_length % bits_in_value))
            {
                i_value &= parameterTraits<OT>::mask() << ((bits_in_value * length) - bit_length);
            }

            parameterTraits<OT>::template write_element<unit_type>(bufferTraits<bits_container>::get_address(iv_data), i_value,
                    i_offset);
            return FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Get an OT of data from buffer
        /// @tparam OT the type of the data to get
        /// @param[in] i_offset Start OT (start word, for example) in buffer
        ///            - defaults to 0 (will by default write the left most element)
        /// @return OT
        /// @note uint8_t b = get<uint8_t>(N) <- gets the N'th left byte from the buffer
        ///
        template< typename OT>
        inline OT get(const bits_type i_offset = 0);

        /// @name Bit/Word Manipulation Functions
        ///@{

        ///
        /// @brief Return the length of the buffer in bits
        /// @return Length in bits
        ///
        inline uint32_t getBitLength(void) const
        {
            return iv_perceived_bit_length;
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
        inline uint32_t getLength(void) const
        {
            static const uint32_t bits_in_ot = sizeof(OT) * 8;
            return (getBitLength() + (bits_in_ot - 1)) / bits_in_ot;
        }

        ///
        /// @brief  Set a bit in buffer
        /// @tparam SB Start bit in buffer to clear.
        /// @tparam L Number of consecutive bits from start bit to
        /// clear
        /// @return FAPI2_RC_SUCCESS on success
        inline fapi2::ReturnCodes setBit( const bits_type SB, bits_type L = 1)
        {

            ReturnCodes rc;
            // make sure we stay within our container
            assert((L > 0) && ((SB + L) <= this->iv_perceived_bit_length) );

            uint32_t mask   = 0;

            // last bit to check
            bits_type EB    = SB + L - 1;

            // index where first bit to check is located
            bits_type start_index = SB / bits_per_unit;

            // index where last bit is located
            bits_type end_index   = EB / bits_per_unit;

            if( start_index == end_index )
            {
                // normalize our SB to be within a unit
                bits_type TempSB = SB - (start_index * bits_per_unit);

                // grab a mask from SB for L number of bits.
                mask = fast_mask32(TempSB, L);

                iv_data[start_index] |= mask;

                rc = FAPI2_RC_SUCCESS;

            }
            else
            {
                // the bits span more than one internal unit, need to break
                // it up to process it.

                // make TempSB point to the start of the next unit, adjust the
                // length and go again, process the bits in the previous index
                // when we get back.
                bits_type TempSB = (start_index + 1) * bits_per_unit;
                bits_type TempL  = EB - TempSB + 1;

                rc = this->setBit( TempSB, TempL );

                if(rc == FAPI2_RC_SUCCESS)
                {
                    // now check the bits in the previous index up to the next index.
                    // normalize our SB to be within a unit
                    TempSB = SB - (start_index * bits_per_unit);

                    // get a mask for the new SB location to the end of this unit.
                    mask = fast_mask32(TempSB, L - TempL);

                    // merge theses bits with the others.
                    iv_data[start_index] |= mask;
                }

            }

            return rc;
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
        inline fapi2::ReturnCodes clearBit(bits_type SB, bits_type L = 1)
        {
            ReturnCodes rc = invert().setBit(SB, L);

            invert();

            return rc;
        }

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
        inline fapi2::ReturnCodes flipBit(void);

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
            const unit_type mask = unit_type(1) <<
                                   ((bits_per_unit - 1) - (B - (index * bits_per_unit)));
            return iv_data[index] & mask;
        }

        ///
        /// @brief Test if multiple bits are set
        /// @param SB Start bit in buffer to test.
        /// @param L Number of consecutive bits from start bit to
        /// test, defaults to 1
        /// @return true if all bits in range are set - false if any
        /// bit is clear
        /// @note Example: fapi2::buffer<uint64_t>().isBitSet(4,3);
        inline bool isBitSet( bits_type SB, bits_type L = 1 ) const
        {
            // make sure we stay within our container
            assert( ((L > 0) && ((SB + L) <= this->iv_perceived_bit_length)) );

            bool is_set     = false;
            uint32_t mask   = 0;

            // last bit to check
            bits_type EB    = SB + L - 1;

            // index where first bit to check is located
            bits_type start_index = SB / bits_per_unit;

            // index where last bit is located
            bits_type end_index   = EB / bits_per_unit;

            if( start_index == end_index )
            {
                // normalize our SB to be within a unit
                bits_type TempSB = SB - (start_index * bits_per_unit);

                // grab a mask from SB for L number of bits.
                mask = fast_mask32(TempSB, L);

                is_set =
                    (( iv_data[start_index] & mask) == mask ) ? true : false;

            }
            else
            {
                // the bits span more than one internal unit, need to break
                // it up to process it.

                // make TempSB point to the start of the next unit, adjust the
                // length and go again, process the bits in the previous index
                // when we get back.
                bits_type TempSB = (start_index + 1) * bits_per_unit;
                bits_type TempL  = EB - TempSB + 1;

                is_set = this->isBitSet( TempSB, TempL );

                // now check the bits in the previous index up to the next index.
                // normalize our SB to be within a unit
                TempSB = SB - (start_index * bits_per_unit);

                // get a mask for the new SB location to the end of this unit.
                mask = fast_mask32(TempSB, L - TempL);

                // test these bits against the others..
                is_set &=
                    (( iv_data[start_index] & mask) == mask ) ? true : false;

            }

            return is_set;
        }

        ///
        /// @brief Test if multiple bits are clear
        /// @param SB Start bit in buffer to test.
        /// @param L Number of consecutive bits from start bit to
        /// test, defaults to 1
        /// @return true if bit is clear - false if bit is set
        ///
        inline bool isBitClear( bits_type SB, bits_type L = 1 ) const
        {
            variable_buffer l_buf = *this;

            return l_buf.invert().isBitSet(SB, L);
        }

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
        inline bits_type getNumBitsSet(void) const;

        ///
        /// @brief Set and entire buffer to X's
        /// @tparam X {0,1} depending if you want to clear (0)
        /// or fill (1) a buffer
        /// @return variable_buffer&, Useful for method chaining
        ///
        template< uint8_t X >
        inline variable_buffer& flush(void)
        {
            static_assert( (X == 1) || (X == 0), "bad argument to flush" );
            (0 == X) ? bufferTraits<bits_container>::clear(iv_data) : bufferTraits<bits_container>::set(iv_data);
            return *this;
        }

        ///
        /// @brief Invert entire buffer
        /// @return variable_buffer&, Useful for method chaining
        ///
        inline variable_buffer& invert(void)
        {
            bufferTraits<bits_container>::invert(iv_data);
            return *this;
        }

        ///@}

        /// @name Buffer Manipulation Functions
        ///@{

        ///
        /// @brief Shift a buffer left a defined number of bits, from a start bit
        /// @param[in] i_shiftNum number of bits to shift
        /// @param[in] i_offset   offset from 0 to start shift, defaults to ~0 (see operator<<())
        /// @note an offset of ~(0) implies "end of the buffer"
        /// @warning there is no shiftLeftandResize - resizing the buffer is left to
        /// the caller to alight the operations with integral buffers.
        /// @return FAPI2_RC_SUCCESS on success
        ///
        inline ReturnCodes shiftLeft(bits_type i_shiftNum, bits_type i_offset = ~0);

        ///
        /// @brief Shift a buffer right a defined number of bits, from a start bit
        /// @param[in] i_shiftNum number of bits to shift
        /// @param[in] i_offset   offset from 0 to start shift, defaults to 0 (see operator>>())
        /// @warning there is no shiftRightandResize - resizing the buffer is left to
        /// the caller to alight the operations with integral buffers.
        /// @return FAPI2_RC_SUCCESS on success
        ///
        inline ReturnCodes shiftRight(bits_type i_shiftNum, bits_type i_offset = 0);

        ///
        /// @brief move operator=()
        /// @note To use: new_buffer = std::move(old_buffer). old_buffer will be
        /// destroyed and no copy will be made (moved)
        ///
        inline variable_buffer& operator=(variable_buffer&& other)
        {
            iv_perceived_bit_length = other.iv_perceived_bit_length;
            other.iv_perceived_bit_length = 0;
            iv_data = std::move(other.iv_data);
            return *this;
        }

        ///
        /// @brief operator=()
        ///
        inline variable_buffer& operator=(const variable_buffer& other)
        {
            iv_perceived_bit_length = other.iv_perceived_bit_length;
            iv_data = other.iv_data;
            return *this;
        }

        ///
        /// @brief operator>>()
        ///
        inline variable_buffer& operator>>(bits_type i_shiftnum)
        {
            // This is just a right shift from the begining of the buffer
            // Why void? Well, there's no place to return the return
            // code and in reality the only problem which can arise
            // is the offset is out of bounds. But since we're hard-wiring it
            // to 0, it can't be out of bounds. So there's no real problem
            // which can arise here.
            static_cast<void>(shiftRight(i_shiftnum));
            return *this;
        }

        ///
        /// @brief operator<<()
        ///
        inline variable_buffer& operator<<(bits_type i_shiftnum)
        {
            // This is just a left shift from the end of the buffer
            // Why void? Well, there's no place to return the return
            // code and in reality the only problem which can arise
            // is the offset is out of bounds. But since we're hard-wiring it
            // to 0, it can't be out of bounds. So there's no real problem
            // which can arise here.
            static_cast<void>(shiftLeft(i_shiftnum));
            return *this;
        }


        ///
        /// @brief operator+()
        /// @param[in] rhs A variable_buffer to append to this
        ///
        inline variable_buffer& operator+(const variable_buffer& rhs)
        {
            iv_perceived_bit_length += rhs.iv_perceived_bit_length;
            iv_data.insert(iv_data.end(), rhs.iv_data.begin(), rhs.iv_data.end());
            return *this;
        }

        ///
        /// @brief operator+()
        /// @param[in] rhs A number of bits to add to this buffer
        ///
        inline variable_buffer& operator+(const bits_type& rhs)
        {
            if (rhs != 0)
            {
                iv_perceived_bit_length += rhs;
                iv_data.resize(_vector_size(iv_perceived_bit_length));
            }

            return *this;
        }

        ///
        /// @brief resize()
        /// @param[in] rhs Desired resulting size of the buffer, in bits
        ///
        inline variable_buffer& resize(const bits_type& rhs)
        {
            return operator+(rhs - iv_perceived_bit_length);
        }

        ///
        /// @brief operator+=()
        ///
#ifdef DOXYGEN
        inline variable_buffer<T>& operator+=(const T& rhs);
#endif

        ///
        /// @brief operator|=()
        ///
#ifdef DOXYGEN
        inline variable_buffer<T>& operator|=(const T& rhs);
#endif

        ///
        /// @brief operator&=()
        ///
#ifdef DOXYGEN
        inline variable_buffer<T>& operator&=(const T& rhs);
#endif

        ///
        /// @brief operator|()
        ///
#ifdef DOXYGEN
        inline variable_buffer<T>& operator|(const T& rhs);
#endif

        ///
        /// @brief operator&()
        ///
#ifdef DOXYGEN
        inline variable_buffer<T>& operator&(const T& rhs);
#endif

        ///
        /// @brief operator^=()
        ///
#ifdef DOXYGEN
        inline variable_buffer<T>& operator^=(const T& rhs);
#endif

        ///
        /// @brief Get a pointer to the buffer bits
        /// @return Pointer to the buffer itself
        ///
        inline unit_type* pointer(void)
        {
            return &(iv_data[0]);
        }

        ///
        /// @brief operator!=()
        ///
        inline bool operator!=(const variable_buffer& rhs) const
        {
            return ! operator==(rhs);
        }

        ///
        /// @brief operator==()
        /// @return true if and only if lhs == rhs
        ///
        inline bool operator==(const variable_buffer& rhs) const
        {
            if (&iv_data == &rhs.iv_data)
            {
                return true;
            }

            return (iv_data == rhs.iv_data) &&
                   (iv_perceived_bit_length == rhs.iv_perceived_bit_length);
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
        inline fapi2::ReturnCodes insert(const OT& i_data,
                                         bits_type i_targetStart = 0,
                                         bits_type i_len = ~0,
                                         bits_type i_sourceStart = 0)
        {
            // _insert likes 32-bit sources. So lets make our source 32 bits.
            uint32_t l_source = static_cast<uint32_t>(i_data);
            bits_type l_sourceStart = i_sourceStart +
                                      parameterTraits<uint32_t>::bit_length() -
                                      parameterTraits<OT>::bit_length();

            return _insert(&l_source, parameterTraits<uint32_t>::bit_length(),
                           &(iv_data[0]), getBitLength(),
                           l_sourceStart, i_targetStart, i_len);
        }

        ///
        /// @brief Copy in a right aligned (decimal) element
        /// @param[in] i_data the incoming data
        ///    - data is taken right aligned
        /// @param[in] i_targetStart The starting bit position in this
        ///            - Defaults to 0
        /// @param[in] i_len The length, in bits, the user wants copied.
        ///            - Defaults to all of the bits in the source which fit
        /// @return FAPI2_RC_SUCCESS on success, FAPI2_RC_OVERFLOW otherwise
        ///
        template<typename OT>
        inline fapi2::ReturnCodes insertFromRight(const OT& i_data,
                bits_type i_targetStart = 0,
                bits_type i_len = ~0)
        {
            return _insertFromRight(i_data, parameterTraits<OT>::bit_length(),
                                    i_targetStart, i_len);
        }

        ///
        /// @brief Copy data from this buffer into an OT
        /// @tparam OT the type of the outgoing data
        /// @param[out] o_out OT to copy into - data is placed left aligned
        /// @param[in] i_start Start bit to copy from - defaults to 0
        /// @param[in] i_len Length of bits to copy - defaults to filling o_out
        /// @return FAPI2_RC_SUCCESS on success
        /// @warning fapi2::extract() does not extend the argument buffer. The caller
        /// should adjust the size proir to calling extract() (resize()). This is to
        /// keep the semantics the same with integral buffers, which can't be resized.
        ///
        // Generic extract. Extract is an insert with the arguments reversed.
        template< typename OT >
        inline fapi2::ReturnCodes extract(OT& o_out,
                                          bits_type i_start = 0,
                                          bits_type i_len = ~0) const
        {
            // If thy didn't pass an i_len, assume they want all the data
            // which will fit.
            if (i_len == static_cast<bits_type>(~0))
            {
                i_len = std::min(getBitLength(),
                                 parameterTraits<OT>::bit_length());
            }

            if (i_len > getBitLength())
            {
                return FAPI2_RC_INVALID_PARAMETER;
            }

            // _insert likes 32-bit targets. So lets make our target 32 bits.
            uint32_t l_data = static_cast<uint32_t>(o_out);

            ReturnCodes rc;

            if ((rc = _insert((container_unit*)&iv_data[0], getBitLength(),
                              &l_data,
                              parameterTraits<uint32_t>::bit_length(),
                              i_start, 0U, i_len)) != FAPI2_RC_SUCCESS)
            {
                return rc;
            }

            // Shift back to the original bit width.
            o_out = l_data >> (parameterTraits<uint32_t>::bit_length() -
                               parameterTraits<OT>::bit_length());
            return FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Copy data from this buffer into an OT and right justify
        /// @tparam OT the type of the outgoing data
        /// @param[out] o_out OT to copy into - data is placed right aligned
        /// @param[in] i_start Start bit to copy from - defaults to 0
        /// @param[in] i_len Length of bits to copy - defaults to filling o_out
        /// @return FAPI2_RC_SUCCESS on success
        ///
        // Extract is an insert with the arguments reversed.
        template< typename OT >
        inline fapi2::ReturnCodes extractToRight(OT& o_out,
                bits_type i_start = 0,
                bits_type i_len = ~0) const
        {
            // If thy didn't pass an i_len, assume they want all the data
            // which will fit.
            if ((i_len == static_cast<bits_type>(~0)) ||
                (i_len > parameterTraits<OT>::bit_length()))
            {
                i_len = std::min(getBitLength(),
                                 parameterTraits<OT>::bit_length());
            }

            // _insert likes 32-bit targets. So lets make our target 32 bits.
            uint32_t l_data = static_cast<uint32_t>(o_out);

            ReturnCodes rc;

            if ((rc = _insert(
                          reinterpret_cast<const container_unit*>(&iv_data[0]),
                          getBitLength(),
                          &l_data,
                          parameterTraits<uint32_t>::bit_length(),
                          i_start,
                          parameterTraits<uint32_t>::bit_length() -
                          i_len, i_len)) != FAPI2_RC_SUCCESS)
            {
                return rc;
            }

            o_out = l_data;
            return FAPI2_RC_SUCCESS;
        }

        ///@}

    private:
        // Just shorthand ...
        static const bits_type bits_per_unit = bufferTraits<bits_container>::bits_per_unit();

        ///@cond
        ///
        /// @brief Return the size of the internal vector given a desired bit size
        /// @param[in] The size in bits
        /// @return The size in units.
        ///
        inline bits_type _vector_size(const bits_type& bits_size)
        {
            // If we fit in one unit, we allocate one unit.
            if (bits_size < parameterTraits<unit_type>::bit_length())
            {
                return 1;
            }

            // Otherwise, the number of units is calculates - add one if
            // we cross the unit boundary.
            else
            {
                bits_type my_size = bits_type(bits_size / 8 / sizeof(unit_type));
                my_size += (bits_size % parameterTraits<unit_type>::bit_length() == 0) ? 0 : 1;
                return my_size;
            }
        }
        ///@endcond

        /// The contents of the buffer
        bits_container iv_data;

        // The number of bits the user asked for. The actual size of the
        // container might be larger.
        bits_type iv_perceived_bit_length;

        ///
        /// @brief Internal insertFromRight
        /// @param[in] i_data, the incoming data
        /// @param[in] i_data_length The length in bits of the incoming data
        /// @param[in] i_target_start_bit The starting bit position in this
        /// @param[in] i_length The length, in bits, the user wants copied.
        ///
        template<typename OT>
        inline fapi2::ReturnCodes _insertFromRight(const OT& i_data,
                bits_type i_data_length,
                bits_type i_targetStart,
                bits_type i_len)
        {
            // If they didn't pass in a length, assume they want all the i_data
            // which will fit.
            if( i_len == static_cast<bits_type>(~0) )
            {
                // The longest the length can be is the length of the data
                // This is the miniumum of the length of the data or the
                // number of available bits
                i_len = std::min(i_data_length, getBitLength() - i_targetStart);
            }

            // Source start is the length, counted from the right
            return insert(i_data, i_targetStart, i_len, i_data_length - i_len);
        }

};

// If the source is 64-bits, treat that as 2x32
template<>
inline fapi2::ReturnCodes variable_buffer::insert(const uint64_t& i_source,
        bits_type i_targetStart,
        bits_type i_len,
        bits_type i_sourceStart)
{
    // _insert wants 32 bit chunks, so lets turn our uint64_t into a
    // uint32_t array (of 64 bits in length). Looks like a 64 bit
    // variable_buffer.
    uint32_t l_source[2] =
    {
        static_cast<uint32_t>((i_source & 0xFFFFFFFF00000000) >> 32),
        static_cast<uint32_t>((i_source & 0x00000000FFFFFFFF))
    };

    return _insert(l_source, parameterTraits<uint64_t>::bit_length(),
                   &(iv_data[0]), getBitLength(),
                   i_sourceStart, i_targetStart, i_len);
}

// Insert another variable_bufer
template<>
inline fapi2::ReturnCodes variable_buffer::insert(
    const variable_buffer& i_data,
    bits_type i_targetStart,
    bits_type i_len,
    bits_type i_sourceStart)
{
    return _insert(reinterpret_cast<const unit_type*>(&(i_data()[0])),
                   i_data.getBitLength(),
                   &(iv_data[0]), getBitLength(),
                   i_sourceStart, i_targetStart, i_len);
}

// variable_buffer insert from right
template<>
inline fapi2::ReturnCodes variable_buffer::insertFromRight(
    const variable_buffer& i_data,
    bits_type i_targetStart,
    bits_type i_len)
{
    const bits_type bit_length_of_source = i_data.getBitLength();
    return _insertFromRight(i_data, bit_length_of_source,
                            i_targetStart, i_len);
}

template<>
inline fapi2::ReturnCodes variable_buffer::extract(
    uint64_t& i_data,
    bits_type i_start,
    bits_type i_len) const
{
    // If thy didn't pass an i_len, assume they want all the data
    // which will fit.
    if ((i_len == static_cast<bits_type>(~0)) ||
        (i_len > parameterTraits<uint64_t>::bit_length()))
    {
        i_len = std::min(getBitLength(),
                         parameterTraits<uint64_t>::bit_length());
    }

    // _insert wants 32 bit chunks, so lets turn our uint64_t into a
    // uint32_t array (of 64 bits in length). Looks like a 64 bit
    // variable_buffer.
    uint32_t l_data[2] =
    {
        static_cast<uint32_t>((i_data & 0xFFFFFFFF00000000) >> 32),
        static_cast<uint32_t>((i_data & 0x00000000FFFFFFFF))
    };

    ReturnCodes rc;

    if ((rc = _insert((container_unit*)&iv_data[0], getBitLength(),
                      l_data, parameterTraits<uint64_t>::bit_length(),
                      i_start, 0U, i_len)) != FAPI2_RC_SUCCESS)
    {
        return rc;
    }

    i_data = static_cast<uint64_t>(l_data[0]) << 32;
    i_data |= l_data[1];

    return FAPI2_RC_SUCCESS;
}

// Extract in to another variable_bufer
template<>
inline fapi2::ReturnCodes variable_buffer::extract(
    variable_buffer& i_data,
    bits_type i_start,
    bits_type i_len) const
{
    // If thy didn't pass an i_len, assume they want all the data
    // which will fit.
    if (i_len == static_cast<bits_type>(~0))
    {
        i_len = i_data.getBitLength();
    }

    return _insert(reinterpret_cast<const container_unit*>(
                       &iv_data[0]),
                   getBitLength(),
                   &(i_data()[0]), i_data.getBitLength(),
                   i_start, 0U, i_len);
}

template<>
inline fapi2::ReturnCodes variable_buffer::extractToRight(
    uint64_t& i_data,
    bits_type i_start,
    bits_type i_len) const
{
    // If thy didn't pass an i_len, assume they want all the data
    // which will fit.
    if ((i_len == static_cast<bits_type>(~0)) ||
        (i_len > parameterTraits<uint64_t>::bit_length()))
    {
        i_len = std::min(getBitLength(),
                         parameterTraits<uint64_t>::bit_length());
    }

    // _insert wants 32 bit chunks, so lets turn our uint64_t into a
    // uint32_t array (of 64 bits in length).
    uint32_t l_data[2] =
    {
        static_cast<uint32_t>((i_data & 0xFFFFFFFF00000000) >> 32),
        static_cast<uint32_t>((i_data & 0x00000000FFFFFFFF))
    };

    ReturnCodes rc;

    if ((rc = _insert(
                  reinterpret_cast<const container_unit*>(&iv_data[0]),
                  getBitLength(),
                  l_data, parameterTraits<uint64_t>::bit_length(),
                  i_start,
                  parameterTraits<uint64_t>::bit_length() - i_len, i_len))
        != FAPI2_RC_SUCCESS)
    {
        return rc;
    }

    i_data = static_cast<uint64_t>(l_data[0]) << 32;
    i_data |= l_data[1];

    return FAPI2_RC_SUCCESS;
}

inline fapi2::ReturnCodes variable_buffer::shiftLeft(
    bits_type i_shiftNum,
    bits_type i_offset)
{
    if (i_offset == 0)
    {
        return FAPI2_RC_SUCCESS;
    }

    if (i_offset == static_cast<bits_type>(~0))
    {
        i_offset = getBitLength();
    }

    else if (i_offset > getBitLength())
    {
        return FAPI2_RC_INVALID_PARAMETER;
    }

    /* To shift the data, extact the piece being shifted and then re-insert it at the new location */
    variable_buffer shiftData(i_offset);
    ReturnCodes rc;

    // Get the hunk of data
    if ((rc = extract(shiftData, 0, i_offset)) != FAPI2_RC_SUCCESS)
    {
        return rc;
    }

    // Clear the hole that was opened
    if ((rc = clearBit((i_offset - i_shiftNum), i_shiftNum)) != FAPI2_RC_SUCCESS)
    {
        return rc;
    }

    // Stick the data back in
    rc = insert(shiftData, 0, (shiftData.getBitLength() - i_shiftNum), i_shiftNum);

    return rc;
}

inline fapi2::ReturnCodes variable_buffer::shiftRight(
    bits_type i_shiftNum,
    bits_type i_offset)
{
    if (i_offset == getBitLength())
    {
        return FAPI2_RC_SUCCESS;
    }

    if (i_offset > getBitLength())
    {
        return FAPI2_RC_INVALID_PARAMETER;
    }

    /* To shift the data, extact the piece being shifted and then re-insert it at the new location */
    variable_buffer shiftData(getBitLength() - i_offset);
    ReturnCodes rc;

    // Get the hunk of data
    if ((rc = extract(shiftData, i_offset, getBitLength() - i_offset)) != FAPI2_RC_SUCCESS)
    {
        return rc;
    }

    // Clear the hole that was opened
    if ((rc = clearBit(i_offset, i_shiftNum)) != FAPI2_RC_SUCCESS)
    {
        return rc;
    }

    // Stick the data back in
    rc = insert(shiftData, (i_offset + i_shiftNum), (shiftData.getBitLength() - i_shiftNum));

    return rc;
}

template< typename OT>
inline OT variable_buffer::get(const bits_type i_offset)
{
    // Get is just an extract.
    OT l_tmp = OT(0);
    extract(l_tmp, parameterTraits<OT>::bit_length() * i_offset, parameterTraits<OT>::bit_length());
    return l_tmp;
}
}
#endif
