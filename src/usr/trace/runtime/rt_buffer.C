/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/runtime/rt_buffer.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include "../buffer.H"
#include "../bufferpage.H"
#include "../entry.H"
#include "../compdesc.H"
#include "../daemonif.H"

#include <assert.h>
#include <limits.h>
#include <string.h>
#include <util/align.H>

#include <arch/ppc.H>



namespace TRACE
{
    Buffer::Buffer(TRACEDAEMON::Daemon * i_daemon, size_t i_maxPages) :
        iv_pagesAlloc(0), iv_pagesMax(i_maxPages),
        iv_firstPage(NULL), iv_daemon(i_daemon)
    {
        assert(i_maxPages > 0);
    }


    Entry* Buffer::claimEntry(ComponentDesc* i_comp, size_t i_size)
    {
        // Bump up the needed size to include the entry itself and
        // necessary alignment.
        // (Alignment is needed so that Entry's members can be atomically
        //  updated).
        i_size = ALIGN_8(i_size + sizeof(Entry));

        // If an entry is bigger than this amount, it can never be satisfied.
        if (i_size > (PAGESIZE - sizeof(BufferPage)))
        {
            return NULL;
        }

        Entry* l_entry = NULL;

        // Now we begin the search for an entry.
        do
        {
            BufferPage* first = iv_firstPage;

            // Attempt to claim from the current page first.
            if (first)
            {
                l_entry = first->claimEntry(i_size);
                if (l_entry)
                {
                    // Found one, great!  We're done.
                    break;
                }
            }

            // Wasn't enough space, so try to allocate a new page.
            uint64_t pagesAllocated = iv_pagesAlloc;
            if (pagesAllocated >= iv_pagesMax)
            {
                // Clean up old pages and consolidate traces
                iv_daemon->signal_trace_daemon();

                // A page might be allocated now, start over.
                continue;
            }

            // Atomically update page count.
            uint64_t newPagesAllocated = pagesAllocated + 1;
            if (!__sync_bool_compare_and_swap(&iv_pagesAlloc,
                                              pagesAllocated,
                                              newPagesAllocated))
            {
                // Someone beat us to updating the count, so start over.
                // (another thread is also trying to allocate a page, let them
                //  do it).
                continue;
            }

            // Successfully updated the count so allocate the new page.
            BufferPage* newPage = BufferPage::allocate();
            newPage->prev = first;

            // Now we have a page allocated, claim our entry first and then
            // hook it up to master list.
            l_entry = newPage->claimEntry(i_size);

            iv_firstPage = newPage;

            // If there was a page already, update its next pointer to point
            // back at this new page.
            if (first)
            {
                if (!__sync_bool_compare_and_swap(&first->next,
                                                  NULL,
                                                  newPage))
                {
                    // We were the first one to update iv_firstPage, so
                    // first->next should have been NULL and nobody was
                    // suppose to touch it.
                    assert(false);
                }
            }

            // And since we allocated a page, wake up the daemon if we
            // allocated the last page or if there are more than 4 pages
            // and we are an infinite buffer.  (4 pages is arbitrary).
            static const size_t SIGNAL_AFTER_N_PAGES_ALLOCATED = 4;

            if ((pagesAllocated == iv_pagesMax) ||
                ((pagesAllocated >= SIGNAL_AFTER_N_PAGES_ALLOCATED) &&
                 (iv_pagesMax == UNLIMITED)))
            {
                // Clean up old pages and consolidate traces
                iv_daemon->signal_trace_daemon();
            }
        } while(!l_entry);

        // Update component name and entry size.
        l_entry->comp = i_comp;
        l_entry->size = i_size - sizeof(Entry);

        return l_entry;
    }

    BufferPage* Buffer::claimPages()
    {
        BufferPage* page = iv_firstPage;

        iv_firstPage = NULL;
        iv_pagesAlloc = 0;

        // Rewind to beginning of buffer.
        int pageCnt = 0;
        if (page)
        {
            pageCnt++;
            while(page->prev) {
                page = page->prev;
                pageCnt++;
            }
        }

        return page;
    }

    void Buffer::commitEntry(Entry* i_entry)
    {
        // Read the component from the entry itself (added as part of claiming).
        ComponentDesc* l_comp = i_entry->comp;

        Entry* l_savedNext = NULL;

        // Lockless loop to update component linked-list.
        do
        {
            // Update our entry's "next" pointer.
            // Note: Our next pointer could change out from under us by the
            // daemon's replaceEntry function, but the component iv_first
            // cannot change by the daemon until we _producerExit, therefore
            // we need to save the original next pointer for the atomic update
            // of l_comp->iv_first below.
            l_savedNext = i_entry->next = l_comp->iv_first;

            // If there is an entry, update its "prev" pointer to this entry.
            if (l_savedNext)
            {
                if (!__sync_bool_compare_and_swap(&l_savedNext->prev,
                                                  NULL,
                                                  i_entry))
                {
                    // Failed lockless update, try again.
                    continue;
                }
            }
            // Otherwise, we need to update the component list since this is
            // the first entry.
            else
            {
                if (!__sync_bool_compare_and_swap(&l_comp->iv_last,
                                                  NULL,
                                                  i_entry))
                {
                    // Failed lockless update, try again.
                    continue;
                }
            }

            // Successful at our updates, break out.
            break;

        } while(1);

        // We just added the newest entry, so update component list.
        l_comp->iv_first = i_entry;

        // Atomically increment component size.
        __sync_add_and_fetch(&l_comp->iv_curSize, i_entry->size);

        // Mark entry as committed.
        i_entry->committed = 1;
    }

    size_t Buffer::getTrace(ComponentDesc* i_comp, void* o_data, size_t i_size)
    {
        char* l_data = reinterpret_cast<char*>(o_data);
        size_t l_size = 0;
        size_t l_entries = 0;

        // If either the pointer is null or the buffer is 0, we're just trying
        // to determine the size of the buffer.
        bool determineSize = ((o_data == NULL) || (i_size == 0));

        if (determineSize)
        {
            i_size = UINT64_MAX;
        }

        trace_buf_head_t* header = NULL;

        // If we're actually extracting, add the fsp-trace buffer header.
        if(!determineSize)
        {
            if (i_size < sizeof(trace_buf_head_t))
                return 0;

            header = reinterpret_cast<trace_buf_head_t*>(&l_data[l_size]);
            memset(header, '\0', sizeof(trace_buf_head_t));

            header->ver = TRACE_BUF_VERSION;
            header->hdr_len = sizeof(trace_buf_head_t);
            header->time_flg = TRACE_TIME_REAL;
            header->endian_flg = 'B'; // Big Endian.
            memcpy(&header->comp[0], &i_comp->iv_compName, TRAC_COMP_SIZE);
        }
        l_size += sizeof(trace_buf_head_t);


        size_t l_totalSize = l_size;
        Entry* entry = i_comp->iv_first;
        size_t l_entriesToExtract = 0;

        do
        {
            if ((!entry) || (!entry->comp))
            {
                break;
            }

            // First walk the list backwards to find everything that will fit.
            while(1)
            {
                // fsp-trace buffer entries have an extra word of size at the
                // end.  That is where the sizeof(uint32_t) comes from...

                if ((l_totalSize + entry->size + sizeof(uint32_t)) <= i_size)
                {
                    l_totalSize += entry->size + sizeof(uint32_t);
                    l_entriesToExtract++;

                    if ((entry->next) &&
                        (entry->next->comp))
                    {
                        entry = entry->next;
                        continue;
                    }
                }
                else // This entry was too big to fit, so roll back one.
                {
                    entry = entry->prev;
                }
                break;
            }

            // If we didn't find anything that fit, leave.
            if (l_totalSize == l_size)
            {
                break;
            }

            // If we're just trying to find the size, we're done.
            if(determineSize)
            {
                l_size = l_totalSize;
                break;
            }

            // Now we can actually copy all the entries...
            while(entry != nullptr)
            {
                // Copy entry data.
                memcpy(&l_data[l_size], &entry->data[0],entry->size);
                l_size += entry->size;

                // Copy entry size.
                uint32_t entry_size = entry->size + sizeof(uint32_t);
                memcpy(&l_data[l_size], &entry_size, sizeof(uint32_t));
                l_size += sizeof(uint32_t);

                l_entries++;

                if (l_entries == l_entriesToExtract)
                {
                    break;
                }
                else
                {
                    entry = entry->prev;
                }
            };

        }
        while(0);

        // Update header.
        if (header)
        {
            header->size = l_size;
            header->next_free = l_size;
            header->te_count = l_entries;
        }

        return l_size;
    }

    bool Buffer::consumerOp(Entry** i_condAddr, Entry* i_condVal,
                            Entry** i_condActAddr, Entry* i_condActVal,
                            Entry** i_addr, Entry* i_val)
    {
        bool rc = true;

        // Primitive #1.
        if (NULL != i_condAddr)
        {
            if (i_condVal == *i_condAddr)
            {
                if (NULL != i_condActAddr)
                {
                    *i_condActAddr = i_condActVal;
                }
            }
            else
            {
                rc = false;
            }
        }

        // Primitive #2.
        if (NULL != i_addr)
        {
            *i_addr = i_val;
        }

        return rc;
    }

}
