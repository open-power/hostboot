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
 * @file buffer_traits.H
 * @brief trait definitions for fapi2 buffer base class
 */

#ifndef __FAPI2_BUFFER_TRAITS__
#define __FAPI2_BUFFER_TRAITS__

#include <stdint.h>
#include <vector>
#include <algorithm>
#include <buffer_parameters.H>

#ifdef FAPI2_DEBUG
#include <iostream>
#endif

#include <iterator>

namespace fapi2
{
    /// @cond
    /// Types representing a container of bits. Used to create
    /// variable_buffer. container_unit must remain 32-bits
    /// for now - there will be a lot of code to change if it
    /// changes. There are assertions helping to enforce this
    /// in places in the code.
    typedef uint32_t container_unit;
    typedef std::vector<container_unit> bits_container;

    /// @brief Traits of buffers
    // In general, we try to give buffers traits reflecting integral types. If
    // this fails, the compiler will let someone know.
    ///
    /// @tparam T is the type of iv_data (std::vector, etc)
    /// @tparam B is the type of the bit-specifier, typically uint32_t
    template<typename T, typename B = uint32_t>
    class bufferTraits
    {
    public:

#if !defined(DOXYGEN) && defined(FAPI2_DEBUG)
        ///
        /// @brief Print a container of bits
        /// @param[in] i_data the container of bits
        ///
        static inline void print(const T& i_data)
        {
            // convert to uint64_t to prevent uint8_t from being
            // printed as a char.
            std::cout << "\tdata is "
                      << std::hex
                      << static_cast<uint64_t>(i_data)
                      << std::dec << std::endl;
        }
#endif

        ///
        /// @brief Return the size of the buffer in E units
        /// @tparam E, the element size.
        /// @param[in] io_buffer the buffer which to size
        /// @return The size of the buffer in E's rounded up
        ///
        template<typename E>
        constexpr static B size(const T& i_buffer)
            {
                return (bit_length(i_buffer) +
                        (parameterTraits<E>::bit_length() - 1)) /
                    parameterTraits<E>::bit_length();
            }

        ///
        /// @brief Return the size of the buffer itself
        /// @param[in] io_buffer the buffer which to size
        /// @return The size of the buffer in bits (not units)
        ///
        constexpr static B bit_length(const T&)
            { return sizeof(T) * 8; }

        ///
        /// @brief Clear the buffer
        /// @param[in,out] io_buffer the buffer which to clear
        ///
        static inline void clear(T& io_buffer)
            { io_buffer = static_cast<T>(0); }

        ///
        /// @brief Set the buffer
        /// @param[in,out] io_buffer the buffer which to set
        ///
        static inline void set(T& io_buffer)
            { io_buffer = static_cast<T>(~0); }

        ///
        /// @brief Invert the buffer
        /// @param[in,out] io_buffer the buffer which to invert
        ///
        static inline void invert(T& io_buffer)
            { io_buffer = ~io_buffer; }

        ///
        /// @brief Reverse the buffer
        /// @param[in,out] io_buffer the buffer which to reverse
        ///
        static inline void reverse(T& io_buffer)
            {
                io_buffer =
                    ((io_buffer & 0xAAAAAAAAAAAAAAAA) >> 1) |
                    ((io_buffer & 0x5555555555555555) << 1);
            }

        ///
        /// @brief Get the address of the buffer as an array
        /// @param[in] i_buffer the buffer which to invert
        /// @return The address of the first element of the buffer
        ///
        static inline void* get_address(T& i_buffer)
            { return (void*)&i_buffer; }

        typedef B bits_type;
        typedef T unit_type;
        constexpr static uint32_t bits_per_unit(void)
            { return sizeof(unit_type) * 8; }
    };

    //
    //
    /// @brief Traits for buffers which are a container of bits
    //
    //
    template<>
    class bufferTraits<bits_container, uint32_t>
    {
    public:
#if !defined(DOXYGEN) && defined(FAPI2_DEBUG)
        ///
        /// @brief Print a container of bits
        /// @param[in] i_data the container of bits
        ///
        static inline void print(const bits_container& i_data)
        {
            std::cout << "\tdata is " << std::hex;
            std::copy(i_data.begin(), i_data.end(),
                      std::ostream_iterator<container_unit>(std::cout, " "));
            std::cout << std::dec << std::endl;
        }
#endif

        ///
        /// @brief Return the size of the buffer in E units
        /// @tparam E, the element size.
        /// @param[in] io_buffer the buffer which to size
        /// @return The size of the buffer in E's rounded up
        ///
        template<typename E>
        constexpr static uint32_t size(const bits_container& i_buffer)
            {
                return (bit_length(i_buffer) +
                        (parameterTraits<E>::bit_length() - 1)) /
                    parameterTraits<E>::bit_length();
            }

        ///
        /// @brief Return the size of the buffer itself
        /// @param[in,out] io_buffer the buffer which to size
        /// @return The size of the buffer in bits (not units)
        ///
        static inline uint32_t bit_length(const bits_container& i_buffer)
            { return i_buffer.size() * sizeof(container_unit) * 8; }

        ///
        /// @brief Clear the buffer
        /// @param[in,out] io_buffer the buffer which to clear
        ///
        static inline void clear(bits_container& io_buffer)
            { io_buffer.assign(io_buffer.size(), 0); }

        ///
        /// @brief Set the buffer
        /// @param[in,out] io_buffer the buffer which to set
        ///
        static inline void set(bits_container& io_buffer)
            { io_buffer.assign(io_buffer.size(), ~0); }

        ///
        /// @brief Invert the buffer
        /// @param[in,out] io_buffer the buffer which to invert
        ///
        static inline void invert(bits_container& io_buffer)
            {
                std::transform(io_buffer.begin(), io_buffer.end(),
                               io_buffer.begin(),
                               [](container_unit u) { return ~u; });
            }

        ///
        /// @brief Get the address of the buffer as an array
        /// @param[in] i_buffer the buffer which to invert
        /// @return The address of the first element of the buffer
        ///
        static inline void* get_address(bits_container& i_buffer)
            {
                return (void*)&(i_buffer[0]);
            }

        typedef uint32_t bits_type;
        typedef container_unit unit_type;
        constexpr static uint32_t bits_per_unit(void)
            { return sizeof(unit_type) * 8; }
    };
    /// @endcond
}



#endif
