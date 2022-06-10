/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfBufferStream.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
#ifndef __prdfBufferStream_H
#define __prdfBufferStream_H

#include <endian.h>
#include <stdint.h>
#include <string.h>

namespace PRDF
{

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN)
namespace HOSTBOOT
{
#elif defined(PRDF_FSP_ERRL_PLUGIN)
namespace FSP
{
#endif

/**
 * @brief An abstract class containing data for a buffer stream.
 */
class BufferStream
{
  public:
    /** @brief Pure virtual destructor. */
    virtual ~BufferStream() = 0;

  protected:
    /**
     * @brief Constructor.
     * @param i_buffer     A pointer to the first address of the buffer.
     * @param i_bufferSize The buffer size (in bytes).
     */
    BufferStream(void* i_buffer, size_t i_bufferSize) :
        iv_buffer{static_cast<uint8_t*>(i_buffer)}, iv_bufferSize{i_bufferSize},
        iv_isGood{(nullptr != i_buffer) && (0 < i_bufferSize)}
    {}

  protected:
    /** A pointer to the first address of the buffer. */
    uint8_t* const iv_buffer;

    /** The buffer size (in bytes). */
    const size_t iv_bufferSize;

    /** Current byte index within the buffer. */
    size_t iv_currentIndex = 0;

    /** True, if state of the stream is good. */
    bool iv_isGood;

  public:
    /** @return True, if state of the stream is good. False, if the buffer is
     *          invalid or if the user tries to read beyond the buffer size. */
    bool good()
    {
        return iv_isGood;
    }
};

inline BufferStream::~BufferStream() {}

/**
 * @brief A streaming utility to read data out of a buffer. Note that all
 *        integers in the buffer are assumed big endian format and will be
 *        converted to host format before they are returned.
 */
class BufferReadStream : public BufferStream
{
  public:
    /**
     * @brief Constructor.
     * @param i_buffer     A pointer to the first address of the buffer.
     * @param i_bufferSize The buffer size (in bytes).
     * @post  Users should check good() to ensure the buffer is valid.
     */
    BufferReadStream(void* i_buffer, size_t i_bufferSize) :
        BufferStream{i_buffer, i_bufferSize}
    {}

    /** @brief Destructor. */
    ~BufferReadStream() = default;

    /** @brief Copy constructor. */
    BufferReadStream(const BufferReadStream&) = delete;

    /** @brief Assignment operator. */
    BufferReadStream& operator=(const BufferReadStream&) = delete;

  public:
    /**
     * @brief Input stream extraction operator.
     * @note  This default template will not do any endianess conversion because
     *        it does not know what the given data is. See the template
     *        specializations below for integers and other defined objects.
     */
    template <class D>
    BufferReadStream& operator>>(D& o_right)
    {
        read(&o_right, sizeof(D));
        return *this;
    }

  private:
    /**
     * @brief Copies the given number of bytes from the current index of the
     *        buffer to the returned data and then increments the index.
     * @param o_data The output data.
     * @param i_size The number of bytes to copy.
     * @post  Users should check good() to ensure there was not a request beyond
     *        the buffer size.
     */
    void read(void* const o_data, size_t i_size)
    {
        // Check for buffer overflow.
        if ((iv_currentIndex + i_size) <= iv_bufferSize)
        {
            // Copy the buffer.
            memcpy(o_data, iv_buffer + iv_currentIndex, i_size);

            // Increment the current index for the next piece of data.
            iv_currentIndex += i_size;
        }
        else
        {
            iv_isGood = false;
        }
    }
};

/** @brief Template specialization for uint16_t. */
template <>
inline BufferReadStream& BufferReadStream::operator>>(uint16_t& o_right)
{
    read(&o_right, sizeof(o_right));
    o_right = be16toh(o_right); // buffer is big-endian
    return *this;
}

/** @brief Template specialization for int16_t. */
template <>
inline BufferReadStream& BufferReadStream::operator>>(int16_t& o_right)
{
    read(&o_right, sizeof(o_right));
    o_right = be16toh(o_right); // buffer is big-endian
    return *this;
}

/** @brief Template specialization for uint32_t. */
template <>
inline BufferReadStream& BufferReadStream::operator>>(uint32_t& o_right)
{
    read(&o_right, sizeof(o_right));
    o_right = be32toh(o_right); // buffer is big-endian
    return *this;
}

/** @brief Template specialization for int32_t. */
template <>
inline BufferReadStream& BufferReadStream::operator>>(int32_t& o_right)
{
    read(&o_right, sizeof(o_right));
    o_right = be32toh(o_right); // buffer is big-endian
    return *this;
}

/** @brief Template specialization for uint64_t. */
template <>
inline BufferReadStream& BufferReadStream::operator>>(uint64_t& o_right)
{
    read(&o_right, sizeof(o_right));
    o_right = be64toh(o_right); // buffer is big-endian
    return *this;
}

/** @brief Template specialization for int64_t. */
template <>
inline BufferReadStream& BufferReadStream::operator>>(int64_t& o_right)
{
    read(&o_right, sizeof(o_right));
    o_right = be64toh(o_right); // buffer is big-endian
    return *this;
}

/**
 * @brief A streaming utility to write data into a buffer. Note that all
 *        integers will be converted from their host format to big endian before
 *        being written to the buffer.
 */
class BufferWriteStream : public BufferStream
{
  public:
    /**
     * @brief Constructor.
     * @param i_buffer     A pointer to the first address of the buffer.
     * @param i_bufferSize The buffer size (in bytes).
     * @post  Users should check good() to ensure the buffer is valid.
     */
    BufferWriteStream(void* i_buffer, size_t i_bufferSize) :
        BufferStream{i_buffer, i_bufferSize}
    {}

    /** @brief Destructor. */
    ~BufferWriteStream() = default;

    /** @brief Copy constructor. */
    BufferWriteStream(const BufferWriteStream&) = delete;

    /** @brief Assignment operator. */
    BufferWriteStream& operator=(const BufferWriteStream&) = delete;

  public:
    /**
     * @brief Output stream insertion operator.
     * @note  This default template will not do any endianess conversion because
     *        it does not know what the given data is. See the template
     *        specializations below for integers and other defined objects.
     */
    template <class D>
    BufferWriteStream& operator<<(const D& i_right)
    {
        write(&i_right, sizeof(D));
        return *this;
    }

  private:
    /**
     * @brief Copies the given number of bytes from the given data to the
     *        current index of the buffer and then increments the index.
     * @param i_data The input data data.
     * @param i_size The number of bytes to copy.
     * @post  Users should check good() to ensure there was not a request beyond
     *        the buffer size.
     */
    void write(const void* const i_data, size_t i_size)
    {
        // Check for buffer overflow.
        if ((iv_currentIndex + i_size) <= iv_bufferSize)
        {
            // Copy the buffer.
            memcpy(iv_buffer + iv_currentIndex, i_data, i_size);

            // Increment the current index for the next piece of data.
            iv_currentIndex += i_size;
        }
        else
        {
            iv_isGood = false;
        }
    }
};

/** @brief Template specialization for uint16_t. */
template <>
inline BufferWriteStream& BufferWriteStream::operator<<(const uint16_t& i_right)
{
    auto tmp = htobe16(i_right); // buffer is big-endian
    write(&tmp, sizeof(tmp));
    return *this;
}

/** @brief Template specialization for int16_t. */
template <>
inline BufferWriteStream& BufferWriteStream::operator<<(const int16_t& i_right)
{
    auto tmp = htobe16(i_right); // buffer is big-endian
    write(&tmp, sizeof(tmp));
    return *this;
}

/** @brief Template specialization for uint32_t. */
template <>
inline BufferWriteStream& BufferWriteStream::operator<<(const uint32_t& i_right)
{
    auto tmp = htobe32(i_right); // buffer is big-endian
    write(&tmp, sizeof(tmp));
    return *this;
}

/** @brief Template specialization for int32_t. */
template <>
inline BufferWriteStream& BufferWriteStream::operator<<(const int32_t& i_right)
{
    auto tmp = htobe32(i_right); // buffer is big-endian
    write(&tmp, sizeof(tmp));
    return *this;
}

/** @brief Template specialization for uint64_t. */
template <>
inline BufferWriteStream& BufferWriteStream::operator<<(const uint64_t& i_right)
{
    auto tmp = htobe64(i_right); // buffer is big-endian
    write(&tmp, sizeof(tmp));
    return *this;
}

/** @brief Template specialization for int64_t. */
template <>
inline BufferWriteStream& BufferWriteStream::operator<<(const int64_t& i_right)
{
    auto tmp = htobe64(i_right); // buffer is big-endian
    write(&tmp, sizeof(tmp));
    return *this;
}

#if defined(PRDF_HOSTBOOT_ERRL_PLUGIN) || defined(PRDF_FSP_ERRL_PLUGIN)
} // namespace FSP/HOSTBOOT
#endif

} // namespace PRDF

#endif // __prdfBufferStream_H
