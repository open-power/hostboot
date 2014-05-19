/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/bufferpage.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __TRACE_BUFFERPAGE_H
#define __TRACE_BUFFERPAGE_H

#include <trace/interface.H>

namespace TRACE
{
    class Entry;

    /** @struct BufferPage
     *
     *  A structure which can be overlaid onto a page of memory to allocate
     *  entries within the page.
     */
    struct BufferPage
    {
        BufferPage* next;       //< Linked-list 'next' ptr.
        BufferPage* prev;       //< Linked-list 'prev' ptr.

        uint32_t commonPage;    //< Status used by daemon pages.
        uint32_t usedSize;      //< Size already allocated for entries.

        char data[0];           //< Data for entries.

        /** @brief Lockless-ly claim an entry from the page.
         *
         *  @param[in] i_size - Size in bytes.
         *
         *  @return Entry* or NULL, if not enough space.
         */
        Entry* claimEntry(size_t i_size);

        /** @brief Utility function to allocate a page.
         *
         *  @param[in] i_common - Page is "common" from a daemon perspective.
         *
         *  @return Pointer to page.
         */
        static BufferPage* allocate(bool i_common = false);

        /** @brief Utility function to free a page.
         *
         *  @param[in] i_page - Page to deallocate.
         */
        static void deallocate(BufferPage* i_page);

    };
}

#endif

