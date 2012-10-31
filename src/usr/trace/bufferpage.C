/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/bufferpage.C $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#include "bufferpage.H"

#include <limits.h>
#include <stdlib.h>
#include <kernel/pagemgr.H>

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

        page = reinterpret_cast<BufferPage*>(PageManager::allocatePage());
        memset(page, '\0', PAGESIZE);

        if (i_common)
        {
            page->commonPage = 1;
        }

        return page;
    }

    void BufferPage::deallocate(BufferPage* i_page)
    {
        PageManager::freePage(i_page);
    }

}
