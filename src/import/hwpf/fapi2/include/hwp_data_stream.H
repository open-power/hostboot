/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/hwp_data_stream.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
 * @file hwp_data_stream.H
 * @brief Utility classes for streaming data into and out of HWPs
 *
 * These utility classes enable procedures to stream their input and output data
 * as opposed to using fixed-size buffers. This will be useful for procedures that
 * are being used to transfer large amounts of data in an SBE chipop context, such
 * as putring, getring, fastarray, putmem, getmem, ...
 *
 * Abstract base classes are provided that procedures should use in their function
 * arguments. The idea is that platforms can derive specific implementations from
 * these base classes; Cronus wrappers could stream into or out of arrays or FAPI
 * buffers whereas the SBE could stream through the SBE FIFO.
 *
 * Encapsulating these details in here means the HWP can be agnostic of whether
 * it's shoving data into a buffer or the SBE FIFO, and the SBE has hooks inside
 * the HWP to add its FIFO enqueue/dequeue calls.
 *
 * Example implementations are also provided that stream data into / out of simple
 * C arrays. These implementations should be useful in a Cronus wrapper environment
 * as well as in an SBE environment, since they provide a simple means to supply
 * data from a compiled-in table.
 *
 * Last but not least, this header provides wrapper classes around such a data
 * stream that allow writing and reading data at a byte granularity (as opposed to
 * stream data units which correspond to SBE FIFO entries of 32 bits). HWPs can use
 * these wrappers if the data they process is of non-uniform granularity.
 */

#ifndef HWP_DATA_STREAM_H_
#define HWP_DATA_STREAM_H_

#include <return_code_defs.H>
#include <algorithm>

namespace fapi2
{

// @brief A unit of data that can be read/written at a time, chosen to match an SBE FIFO granule.
typedef uint32_t hwp_data_unit;

/**
 * @brief Rotate an integer value to the left
 *
 * This looks like a lot of operations in C but the compiler should
 * recognize it for what it is and emit a single rotate instruction.
 */
template<typename T>
static inline T rotate_left(T x, int shift)
{
    constexpr int mask = 8 * sizeof(T) - 1;
    return (x << (shift & mask)) | (x >> ((-shift) & mask));
}

/**
 * @name Abstract base classes to be used in function headers
 * @{
 */

/**
 * @brief Stream data into a HWP
 *
 * This class can be used to stream an arbitrary amount of data units into a HWP.
 * It has no predetermined notion of "length", only of "end of stream", so HWPs
 * should either accept an additional "length" parameter or be independent of
 * actual stream length.
 */
class hwp_data_istream
{
    public:
        /**
         * @brief Retrieve the next unit of data from the stream
         *
         * This method will return the next unit of data from the stream
         * and advance the read pointer. If data is temporarily unavailable,
         * this method might block waiting for data.
         *
         * @param[out] o_data The next data unit is returned here
         *
         * @return
         *    FAPI2_RC_SUCCESS if data is available
         *    FAPI2_RC_FALSE   if the end of the stream has been reached
         *    any other RC     if an error occurred
         */
        virtual ReturnCodes get(hwp_data_unit& o_data) = 0;
};

/**
 * @brief Stream data out of a HWP
 *
 * Procedures can shove data into this stream until they're done. This stream
 * has no notion of "length", but implementations may start returning error codes
 * from put() if their underlying transport or data structure has reached a limit.
 */
class hwp_data_ostream
{
    public:
        /**
         * @brief Write a unit of data to the stream
         *
         * This method will insert one unit of data into the stream. If the stream
         * is backed up for any reason, it will block until the data can be written.
         *
         * Implementations may collect multiple units of data before sending anything
         * out, so a successful return code is not a guarantee that the data has
         * arrived at the remote end of the stream.
         *
         * @param[in] i_data The data unit to write to the stream
         *
         * @return
         *    FAPI2_RC_SUCCESS if the data has successfully been written
         *    any other RC     if an error occurred and the data could not be written
         */
        virtual ReturnCodes put(hwp_data_unit i_data) = 0;
};

/**
 * @}
 *
 * @name Implementations using arrays of data units
 * @{
 */

/**
 * @brief Input stream that reads from an array of predetermined size.
 *
 * The class will return successive array entries until the array size is
 * exhausted, which will be considered the end of the stream.
 */
class hwp_array_istream : public hwp_data_istream
{
    public:
        /**
         * @brief Initialize the input stream from an array of data
         *
         * @param[in] i_data   Pointer to the data array
         * @param[in] i_length Length of the array in data units
         */
        hwp_array_istream(const hwp_data_unit* i_data, size_t i_length) :
            iv_data(i_data), iv_remaining(i_length) {};

        virtual ReturnCodes get(hwp_data_unit& o_data)
        {
            if (iv_remaining)
            {
                iv_remaining--;
                o_data = *(iv_data++);
                return FAPI2_RC_SUCCESS;
            }
            else
            {
                return FAPI2_RC_FALSE;
            }
        }

    private:
        const hwp_data_unit* iv_data;
        size_t iv_remaining;
};

/**
 * @brief Output stream that writes to an array of data units
 *
 * The class will write to a buffer of fixed size and return FAPI2_RC_OVERFLOW
 * if the buffer size is exhausted and no more data can be written to it.
 *
 * The final amount of data written into the buffer can be retrieved using
 * getLength().
 */
class hwp_array_ostream : public hwp_data_ostream
{
    public:
        /**
         * @brief Initialize the stream
         *
         * @param[in] i_buffer     The buffer to write data into
         * @param[in] i_max_length The maximum amount of data units the buffer can hold
         */
        hwp_array_ostream(hwp_data_unit* i_buffer, size_t i_max_length) :
            iv_buffer(i_buffer), iv_length(0), iv_max_length(i_max_length) {};

        virtual ReturnCodes put(hwp_data_unit i_data)
        {
            if (iv_length >= iv_max_length)
            {
                return FAPI2_RC_OVERFLOW;
            }
            else
            {
                *(iv_buffer++) = i_data;
                iv_length++;
                return FAPI2_RC_SUCCESS;
            }
        }

        /**
         * @brief Determine the amount of data written to the array
         * @return The amount of data written, in data units (not bytes)
         */
        size_t getLength()
        {
            return iv_length;
        }

    private:
        hwp_data_unit* iv_buffer;
        size_t iv_length, iv_max_length;
};


/**
 * @}
 *
 * @name Wrappers to insert/extract data of non-unit size
 * @{
 */

/**
 * @brief Helper macro for the abort-on-error idiom
 */
#define HWP_STREAM_TRY(cond) {     \
        const ReturnCodes l_rc = cond; \
        if (l_rc != FAPI2_RC_SUCCESS)  \
        {                              \
            return l_rc;               \
        }                              \
    }

/**
 * @brief Extract data from a stream at bit granularity
 *
 * This class will wrap around any hwp_data_istream and provide get() methods
 * to retrieve between one and 64 bits of data in one go.
 *
 * Retrieving larger blocks of data would go against the "streaming" concept
 * where pieces of information are being read from the stream as they are needed,
 * and is therefore not supported.
 */
class hwp_bit_istream
{
    public:
        /**
         * @brief Initialize the stream
         *
         * The underlying stream must no longer be accessed directly once it has
         * been wrapped by this class.
         *
         * @param[in] i_stream The hwp_data_istream to wrap around.
         */
        hwp_bit_istream(hwp_data_istream& i_stream) :
            iv_stream(i_stream), iv_buf_ptr(buf_size) {};

        /**
         * @brief Retrieve a value of 1-64 bits from the stream
         * @param[out] o_value  The retrieved value will be placed here, aligned according to i_left_aligned
         * @param[in]  i_nbits  The size (in bits) of the value to be read
         * @param[in]  i_left_aligned if true, o_value will be left-aligned, otherwise right-aligned
         * @return
         *    FAPI2_RC_SUCCESS on success
         *    FAPI2_RC_FALSE   if the stream has ended
         *    anything else    if an error occurred
         */
        ReturnCodes get(uint64_t& o_value, int i_nbits, bool i_left_aligned = false)
        {
            uint64_t l_value = 0;
            int l_nbits = i_nbits;

            // While we still need data, refill the buffer if necessary and grab data from it
            while (l_nbits)
            {
                if (iv_buf_ptr >= buf_size)
                {
                    HWP_STREAM_TRY(iv_stream.get(iv_buf));
                    iv_buf_ptr = 0;
                }

                // In each round, read what's left in the buffer, up to the number of bytes we need
                const int l_shift = std::min(buf_size - iv_buf_ptr, l_nbits);

                // Shift the temp value to make space for new data
                l_value <<= l_shift;

                // Rotate the buffer to move the bytes we'd like to read to the rightmost position
                iv_buf = rotate_left(iv_buf, l_shift);

                // Now copy the data and do some bookkeeping
                l_value |= iv_buf & ((1ULL << l_shift) - 1);
                iv_buf_ptr += l_shift;
                l_nbits -= l_shift;
            }

            o_value = i_left_aligned ? (l_value << (64 - i_nbits)) : l_value;
            return FAPI2_RC_SUCCESS;
        }

        /**
         * @brief Retrieve a single byte from the stream
         * @param[out] o_value The retrieved byte will be placed here
         * @return
         *    FAPI2_RC_SUCCESS on success
         *    FAPI2_RC_FALSE   if the stream has ended
         *    anything else    if an error occurred
         */
        ReturnCodes get8(uint8_t& o_value)
        {
            uint64_t l_tmp = 0;
            const ReturnCodes l_rc = get(l_tmp, 8);
            o_value = l_tmp;
            return l_rc;
        }

        /**
         * @brief Retrieve a 16-bit value from the stream
         * @param[out] o_value The retrieved value will be placed here
         * @return
         *    FAPI2_RC_SUCCESS on success
         *    FAPI2_RC_FALSE   if the stream has ended
         *    anything else    if an error occurred
         */
        ReturnCodes get16(uint16_t& o_value)
        {
            uint64_t l_tmp = 0;
            const ReturnCodes l_rc = get(l_tmp, 16);
            o_value = l_tmp;
            return l_rc;
        }

        /**
         * @brief Retrieve a 32-bit value from the stream
         * @param[out] o_value The retrieved value will be placed here
         * @return
         *    FAPI2_RC_SUCCESS on success
         *    FAPI2_RC_FALSE   if the stream has ended
         *    anything else    if an error occurred
         */
        ReturnCodes get32(uint32_t& o_value)
        {
            uint64_t l_tmp = 0;
            const ReturnCodes l_rc = get(l_tmp, 32);
            o_value = l_tmp;
            return l_rc;
        }

        /**
         * @brief Retrieve a 64-bit value from the stream
         * @param[out] o_value The retrieved value will be placed here
         * @return
         *    FAPI2_RC_SUCCESS on success
         *    FAPI2_RC_FALSE   if the stream has ended
         *    anything else    if an error occurred
         */
        ReturnCodes get64(uint64_t& o_value)
        {
            return get(o_value, 64);
        }

        /**
         * @brief Read a variable length integer from the stream
         *
         * For variable length integers, we store only as many bytes as are needed
         * for a given value. One bit out of each byte is used to indicate more bytes
         * are coming (1) or the value is finished (0).
         *
         * @param[out] o_value The final value is returned in here
         * @return
         *    FAPI2_RC_SUCCESS  on success
         *    FAPI2_RC_FALSE    if the stream has ended
         *    FAPI2_RC_OVERFLOW if the value is malformed (no "last byte" after 5 bytes)
         *    anything else     if an error occurred
         */
        ReturnCodes get_var_len_int(uint32_t& o_value)
        {
            uint32_t l_result = 0;
            uint8_t  l_maxbytes = 5;

            while (l_maxbytes--)
            {
                uint8_t l_next_byte;
                HWP_STREAM_TRY(get8(l_next_byte));
                l_result = (l_result << 7) | (l_next_byte & 0x7F);

                if (!(l_next_byte & 0x80))
                {
                    o_value = l_result;
                    return FAPI2_RC_SUCCESS;
                }
            }

            return FAPI2_RC_OVERFLOW;
        }

    private:
        static constexpr int buf_size = 8 * sizeof(hwp_data_unit);
        hwp_data_istream& iv_stream;
        hwp_data_unit iv_buf;
        int iv_buf_ptr;
};

/**
 * @brief Append data to a stream at bit granularity
 *
 * This class will wrap around any hwp_data_ostream and provide put() methods
 * to append between one and 64 bits of data in one go.
 *
 * Appending larger blocks of data would go against the "streaming" concept
 * where pieces of information are being written to the stream as they are produced,
 * and is therefore not supported.
 */
class hwp_bit_ostream
{
    public:
        /**
         * @brief Initialize the stream
         *
         * The underlying stream must no longer be accessed directly once it has
         * been wrapped by this class.
         *
         * @param[in] i_stream The hwp_data_ostream to wrap around.
         */
        hwp_bit_ostream(hwp_data_ostream& i_stream) :
            iv_stream(i_stream), iv_buf(0), iv_buf_ptr(0) {};

        /**
         * @brief Close the stream, flush all partial data
         *
         * This implicitly flushes the buffer in case the stream is destructed.
         * HWPs are still expected to call flush() explicitly and evaluate its
         * return code. This implicit flush is only for easier error handling
         * (if the stream gets destroyed due to a FAPI_TRY).
         */
        ~hwp_bit_ostream()
        {
            flush();
        }

        /**
         * @brief Append a value of 1-64 bits to the stream
         * @param[in] i_value        The value to append, left or right aligned depending on i_left_aligned
         * @param[in] i_nbits        The number of bytes to write
         * @param[in] i_left_aligned If true, i_value is considered left-aligned, otherwise right-aligned
         * @return FAPI2_RC_SUCCESS or an error code
         */
        ReturnCodes put(uint64_t i_value, int i_nbits, bool i_left_aligned = false)
        {
            // If the value is right aligned, we need to shift it so it's left-aligned
            if (!i_left_aligned)
            {
                i_value <<= 64 - i_nbits;
            }

            // Repeat writing as many bits as possible to the buffer and flushing it until all is written
            while (i_nbits)
            {
                // Each round, fill the available buffer space, up to the number of bits to still write
                const int l_shift = std::min(buf_size - iv_buf_ptr, i_nbits);

                // Rotate the value to expose the bytes we want to write at the rightmost position
                i_value = rotate_left(i_value, l_shift);

                // Make room in the buffer and copy in the new bits
                iv_buf <<= l_shift;
                iv_buf |= i_value & ((1ULL << l_shift) - 1);

                // Bookkeeping
                iv_buf_ptr += l_shift;
                i_nbits -= l_shift;

                // Flush out the buffer if we just filled it up
                if (iv_buf_ptr >= buf_size)
                {
                    HWP_STREAM_TRY(iv_stream.put(iv_buf));
                    iv_buf_ptr = 0;
                    iv_buf = 0;
                }
            }

            return FAPI2_RC_SUCCESS;
        }

        /**
         * @brief Append a single byte to the stream
         * @param[in] i_value The value to append
         * @return FAPI2_RC_SUCCESS or an error code
         */
        ReturnCodes put8(uint8_t i_value)
        {
            return put(i_value, 8);
        }

        /**
         * @brief Append a 16-bit value to the stream
         * @param[in] i_value The value to append
         * @return FAPI2_RC_SUCCESS or an error code
         */
        ReturnCodes put16(uint16_t i_value)
        {
            return put(i_value, 16);
        }

        /**
         * @brief Append a 32-bit value to the stream
         * @param[in] i_value The value to append
         * @return FAPI2_RC_SUCCESS or an error code
         */
        ReturnCodes put32(uint32_t i_value)
        {
            return put(i_value, 32);
        }

        /**
         * @brief Append a 64-bit value to the stream
         * @param[in] i_value The value to append
         * @return FAPI2_RC_SUCCESS or an error code
         */
        ReturnCodes put64(uint64_t i_value)
        {
            return put(i_value, 64);
        }

        /**
         * @brief Append a variable length integer to the stream
         *
         * For variable length integers, we store only as many bytes as are needed
         * for a given value. One bit out of each byte is used to indicate more bytes
         * are coming (1) or the value is finished (0).
         *
         * @param[in] i_value The value to write
         * @return FAPI2_RC_SUCCESS or an error code
         */
        ReturnCodes put_var_len_int(uint32_t i_value)
        {
            bool l_writing = false;

            // Go through the value in order of descending significance,
            // and start writing bytes once we encounter a nonzero value
            for (int i = 4; i; i--)
            {
                const uint32_t l_masked = (i_value >> (7 * i)) & 0x7F;

                if (l_masked || l_writing)
                {
                    // Once we hit a nonzero section we have to keep writing
                    // even if later sections are zero.
                    l_writing = true;
                    HWP_STREAM_TRY(put8(l_masked | 0x80));
                }
            }

            // The lowest-order bits always get written
            HWP_STREAM_TRY(put8(i_value & 0x7F));
            return FAPI2_RC_SUCCESS;
        }

        /**
         * @brief Flush any partially written data to the underlying stream
         *
         * If there are bits in the internal buffer that don't make up a full data
         * unit, the remaining space in the data unit will be filled with zeros and
         * the data unit will be pushed out to the underlying stream.
         *
         * @return FAPI2_RC_SUCCESS or an error code
         */
        ReturnCodes flush()
        {
            if (iv_buf_ptr)
            {
                // Shift the buffer so the written bits are left aligned
                iv_buf <<= buf_size - iv_buf_ptr;
                HWP_STREAM_TRY(iv_stream.put(iv_buf));
                iv_buf_ptr = 0;
                iv_buf = 0;
            }

            return FAPI2_RC_SUCCESS;
        }

    private:
        static constexpr int buf_size = 8 * sizeof(hwp_data_unit);
        hwp_data_ostream& iv_stream;
        hwp_data_unit iv_buf;
        int iv_buf_ptr;
};

#undef HWP_STREAM_TRY

} /* namespace fapi2 */

#endif /* HWP_DATA_STREAM_H_ */
