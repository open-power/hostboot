/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/bufferpage.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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

#include "bufferpage.H"

#include <limits.h>
#include <stdlib.h>
#include <string.h>

#ifndef __HOSTBOOT_RUNTIME
#include <kernel/pagemgr.H>
#endif

namespace TRACE
{

    Entry* BufferPage::claimEntry(size_t i_size)
    {
        uint64_t l_usedSize = this->usedSize;

        // Verify there is enough space.
        while ((usedSize + i_size) < (PAGESIZE - sizeof(BufferPage)))
        {
            // Atomically attempt to claim i_size worth.
            uint64_t newSize = l_usedSize + i_size;
            if (!__sync_bool_compare_and_swap(&this->usedSize,
                                              l_usedSize,
                                              newSize))
            {
                // Failed race to atomically update.
                //    Re-read size, try again.
                l_usedSize = this->usedSize;
                continue;
            }

            // Successful at claiming an entry, return pointer to it.
            return reinterpret_cast<Entry*>(&this->data[0] + l_usedSize);
        }

        return NULL;
    }

    BufferPage* BufferPage::allocate(bool i_common)
    {
        BufferPage* page = NULL;

#ifndef __HOSTBOOT_RUNTIME
        page = reinterpret_cast<BufferPage*>(PageManager::allocatePage());
#else
        page = reinterpret_cast<BufferPage*>(malloc(PAGESIZE));
#endif
        memset(page, '\0', PAGESIZE);

        if (i_common)
        {
            page->commonPage = 1;
        }

        return page;
    }

    void BufferPage::deallocate(BufferPage* i_page)
    {
#ifndef __HOSTBOOT_RUNTIME
        PageManager::freePage(i_page);
#else
        if (i_page != nullptr)
        {
           free(i_page);
           i_page = nullptr;
        }
#endif
    }

}
