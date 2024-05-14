/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/discontiguous.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2024                        */
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
#ifndef __DISCONTIGUOUS_H
#define __DISCONTIGUOUS_H

#include <stdint.h>
#include <memory>

#ifndef __HOSTBOOT_RUNTIME
#include <kernel/pagemgr.H>
#endif

namespace BUFFER
{

/*
 * @brief A Buffer backed by discontiguous physical pages.
 */
class discontiguous_t
{
public:
    /** @brief Append a byte to the buffer. */
    void append(const uint8_t i_byte)
    {
        *get_ptr(iv_bytes_contained++) = i_byte;
    }

    /** @brief Append data to this buffer. */
    void append(const void* i_data, size_t i_amt)
    {
        const uint8_t* data_bytes = static_cast<const uint8_t*>(i_data);

        while (i_amt > 0)
        {
            append(*data_bytes);
            --i_amt;
            ++data_bytes;
        }
    }

    /** @brief Retrieve the 32-bit value at a given offset in the
     *  buffer.
     *
     *  Asserts on out-of-bounds accesses.
     */
    uint32_t word32_at(const size_t i_word_offset) const
    {
        uint32_t word = 0;
        const size_t begin_copy = i_word_offset * sizeof(uint32_t);

        this->memcpy(&word, begin_copy, sizeof(uint32_t));
        return word;
    }

    /** @brief Retrieve the size of the buffer in bytes.
     */
    size_t size() const
    {
        return iv_bytes_contained;
    }

    /**
     * @brief Copy data out of the buffer at the given offset.
     *
     * @param[in] i_dest    The destination buffer.
     * @param[in] i_offset  The offset in the source buffer to copy from.
     * @param[in] i_count   The number of bytes to copy.
     *
     * @note Asserts on out-of-bounds access in the source buffer.
     */
    void memcpy(void* const i_dest, size_t i_offset, size_t i_count) const
    {
        if ( (i_offset + i_count < i_offset) ||
             (i_offset > iv_bytes_contained) ||
             (i_offset + i_count > iv_bytes_contained) )
        {
            assert(false,
                   "discontiguous_t::memcpy index %ld + count %ld out of bounds %ld",
                   i_offset, i_count, iv_bytes_contained);
        }

        uint8_t* dest_bytes = static_cast<uint8_t*>(i_dest);

        while (i_offset < iv_bytes_contained && i_count > 0)
        {
            *dest_bytes = *get_ptr(i_offset);
            ++dest_bytes;
            ++i_offset;
            --i_count;
        }
    }

private:
    /** @brief Deleter class for a page. */
    struct free_page
    {
        void operator()(uint8_t* const i_page) const {
#ifdef __HOSTBOOT_RUNTIME
            free(i_page);
#else
            return PageManager::freePage(i_page);
#endif
        }
    };

    using page_ptr = std::unique_ptr<uint8_t, free_page>;
    std::vector<page_ptr> iv_pages;

    // The number of bytes actually used.
    size_t iv_bytes_contained = 0;

    /** @brief Allocate a single page of data. */
    static uint8_t* allocate_page()
    {
#ifdef __HOSTBOOT_RUNTIME
        return static_cast<uint8_t*>(malloc(PAGE_SIZE));
#else
        return static_cast<uint8_t*>(PageManager::allocatePage(1, /*userspace=*/true));
#endif
    }

    /**
     * @brief Retrieve a pointer to the byte at the given index in the
     * buffer.
     *
     * @note Automatically resizes when the index is out-of-bounds.
     */
    uint8_t* get_ptr(const size_t i_idx)
    {
        const size_t page = i_idx / PAGE_SIZE;
        const size_t offset = i_idx % PAGE_SIZE;

        while (iv_pages.size() <= page)
        {
            iv_pages.push_back(page_ptr(allocate_page(), free_page { }));
        }

        return iv_pages[page].get() + offset;
    }

    /**
     * @brief Retrieve a pointer to the byte at the given index in the
     * buffer.
     *
     * @note Asserts when the index is out-of-bounds.
     */
    const uint8_t* get_ptr(const size_t i_idx) const
    {
        const size_t page = i_idx / PAGE_SIZE;
        const size_t offset = i_idx % PAGE_SIZE;

        if (page >= iv_pages.size())
        {
            assert(false, "discontiguous_t::get_ptr() const: Index %ld out of bounds (pages = %ld)",
                   i_idx, iv_pages.size());
        }

        return iv_pages[page].get() + offset;
    }
};

}

#endif
