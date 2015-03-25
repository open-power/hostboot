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
 * @file array.H
 * @brief definitions for fapi2 arrays
 */

#ifndef __FAPI2_ARRAY__
#define __FAPI2_ARRAY__

#include <stdint.h>
#include <utility>
#include <assert.h>
#include <string.h>

namespace fapi2
{
    ///
    /// @brief Class representing a FAPI2 array
    /// FAPI2 arrays are defined to be very lightweight but support
    /// c++ container operations (iterators, bounds checking, assignment, etc.)
    /// To avoid the code-bloat associated with std::vector templates,
    /// fapi2::array is presently limited to 64-bit elements.
    ///
    /// To construct an array, you can either pass in an existing chunk
    /// of memory, or let the container allocate memory for you:
    ///    fapi2::array foo(3, &PIB_MEM_BLOCK);
    /// creates an array 3 x uit64_t in size, located at &PIB_MEM_BLOCK.
    /// The memory pointed to by the address passed in is untouched
    /// during creation. This allows for a light-weight overlay on top
    /// of existing memory. It also means you need to initialize the space
    /// yourself.
    ///    fapi2_array foo(3);
    /// creates an array 3 x uint64_t in size, and that memory will be
    /// allocated by the constructor and initiaized to 0's.
    ///
    ///
    class array
    {
    public:

        typedef uint64_t element_type;
        typedef element_type* iterator;
        typedef const element_type* const_iterator;

        ///
        /// @brief Create an array
        /// @param[in] the size of the array
        /// @param[in] a pointer to memory of appropriate size
        ///   defaults to nullptr which causes the platform to
        ///   allocate memory of size * element_type
        /// @warning fapi2::arrays, like arrays, can not be re-sized after
        /// creation.
        ///
        array(const uint32_t i_size, element_type* i_data = nullptr);

        ///
        /// @brief Destroy an array
        ///
        ~array(void);

        ///
        /// @brief operator[]
        /// @param[in] the index of the element
        /// @return a reference to the element in question.
        /// @note array[0] = 0 works as well as foo = array[0]
        ///
        element_type& operator[](const uint32_t i_index);

        ///
        /// @brief operator=()
        /// @param[in] the other array
        /// @return a reference to this, after the assignement
        ///
        array& operator=(const array& i_other);

        ///
        /// @brief move operator=()
        /// @note To use: new_array = std::move(old_array). old_array will be
        /// destroyed and no copy will be made (moved)
        ///
        array& operator=(array&& i_other);

        ///
        /// @brief operator==()
        ///
        bool operator==(const array& i_other);

        ///
        /// @brief operator!=()
        ///
        __attribute__ ((always_inline))
        bool operator!=(const array& i_other)
            { return ! operator==(i_other); }

        ///
        /// @brief Return an iterator the to beginning of the array
        /// @return An iterator to the beginning of the array
        ///
        __attribute__ ((always_inline))
        iterator begin(void)
            { return iv_data; }

        ///
        /// @brief Return an iterator the to end of the array
        /// @return An iterator to the end of the array
        ///
        __attribute__ ((always_inline))
        iterator end(void)
            { return iv_data + size(); }

        ///
        /// @brief Return a const_iterator the to beginning of the array
        /// @return A const_iterator to the beginning of the array
        ///
        __attribute__ ((always_inline))
        const_iterator begin(void) const
            { return iv_data; }

        ///
        /// @brief Return a const_iterator the to end of the array
        /// @return A const_iterator to the end the array
        ///
        __attribute__ ((always_inline))
        const_iterator end(void) const
            { return iv_data + size(); }

    private:

        enum
        {
            // Bit in iv_size representing whether we delete in the dtor
            delete_bit = 0x80000000,

            // The resulting size limit
            size_limit = 0x7FFFFFFF,
        };

        __attribute__ ((always_inline))
        uint32_t size(void)
        { return (iv_size & ~delete_bit); }

        __attribute__ ((always_inline))
        uint32_t size(void) const
        { return (iv_size & ~delete_bit); }

        uint32_t      iv_size;
        element_type* iv_data;
    };
}

#endif
