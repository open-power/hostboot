/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/buffer.C $                                      */
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
#include "buffer.H"
#include "bufferpage.H"
#include "entry.H"
#include "compdesc.H"
#include "daemonif.H"

#include <assert.h>
#include <limits.h>
#include <string.h>
#include <util/align.H>

namespace TRACE
{
    Buffer::Buffer(DaemonIf* i_daemon, size_t i_maxPages) :
        iv_pagesAlloc(0), iv_pagesMax(i_maxPages),
        iv_firstPage(NULL), iv_daemon(i_daemon)
    {
        iv_counters.totals = 0;
        assert(i_maxPages > 0);
    }

    void Buffer::_producerEnter()
    {
        locklessCounter value;
        do
        {
            // Read current count.
            value = iv_counters;

            // If there is a consumer (daemon) present, must wait.
            while (value.consumerCount != 0)
            {
                futex_wait(&iv_counters.totals, value.totals);
                value = iv_counters;
            }

            // No consumers currently present, increment the producer count
            // (to include us).
            locklessCounter newValue = value;
            newValue.producerCount++;

            // Attempt to atomically update the count.
            if (__sync_bool_compare_and_swap(&iv_counters.totals,
                                             value.totals,
                                             newValue.totals)
               )
            {
                // Successful at atomic update, we're included in the count
                // so we can exit the loop.
                break;
            }

            // Failed to update count, so try again.
        } while(1);
    }

    void Buffer::_producerExit()
    {
        locklessCounter value;
        do
        {
            // Read current count.
            value = iv_counters;

            // Decrement count to remove us.
            locklessCounter newValue = value;
            newValue.producerCount--;

            // Attempt to atomically update count.
            if (!__sync_bool_compare_and_swap(&iv_counters.totals,
                                              value.totals,
                                              newValue.totals))
            {
                // Failed, try again.
                continue;
            }

            // If we're the last producer and there is a consumer waiting,
            // signal the consumer.
            if((newValue.producerCount == 0) && (newValue.consumerCount != 0))
            {
                futex_wake(&iv_counters.totals, UINT64_MAX);
            }

            // If we're here, we are successful, so exit the loop.
            break;

        } while(1);
    }

    void Buffer::_consumerEnter()
    {
        locklessCounter value;
        do
        {
            // Read current count.
            value = iv_counters;

            // Set us up as a pending consumer.
            locklessCounter newValue = value;
            newValue.consumerCount = 1;

            // Attempt to atomically update counts.
            if (!__sync_bool_compare_and_swap(&iv_counters.totals,
                                              value.totals,
                                              newValue.totals))
            {
                // Failed, try again.
                continue;
            }

            // If there were producers waiting, we need to wait for them
            // to clear out.
            if (0 != newValue.producerCount)
            {
                do
                {
                    futex_wait(&iv_counters.totals, newValue.totals);
                    newValue = iv_counters;

                } while(newValue.producerCount != 0);
            }

            // If we're here, we are successful, so exit the loop.
            break;

        } while(1);
    }

    void Buffer::_consumerExit()
    {
        locklessCounter value;
        do
        {
            // Read current count.
            value = iv_counters;

            // Remove ourself as the consumer.
            locklessCounter newValue = value;
            newValue.consumerCount = 0;

            // Atomically update the count.
            if (!__sync_bool_compare_and_swap(&iv_counters.totals,
                                              value.totals,
                                              newValue.totals))
            {
                // Failed, try again.
                continue;
            }

            // Successful.  Signal any producers that might be waiting and
            // exit the loop.
            futex_wake(&iv_counters.totals, UINT64_MAX);
            break;

        } while(1);
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

        // During the process of claiming an entry, the daemon must be
        // blocked out from tampering with the pages.
        _producerEnter();

        Entry* l_entry = NULL;

        // No we begin the search for an entry.
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

                // If there is a "next" page, another thread has already
                // allocated a new page, so just wait for it to show up.
                // (as in, some other thread is going to update iv_firstPage)
                if (first->next)
                {
                    continue;
                }
            }

            // Wasn't enough space, so try to allocate a new page.
            uint64_t pagesAllocated = iv_pagesAlloc;
            if (pagesAllocated >= iv_pagesMax)
            {
                // Not enough pages.  Wait until someone frees one.
                _producerExit();
                iv_daemon->signal();
                futex_wait(reinterpret_cast<uint64_t*>(
                                const_cast<BufferPage**>(&iv_firstPage)),
                           reinterpret_cast<uint64_t>(first));
                _producerEnter();
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

            // If there is a page already, update its next pointer to point
            // back at this new page.
            if (first)
            {
                if (!__sync_bool_compare_and_swap(&first->next,
                                                  NULL,
                                                  newPage))
                {
                    // Someone beat us to allocating the page, release it.
                    BufferPage::deallocate(newPage);
                    do
                    {
                        pagesAllocated = iv_pagesAlloc;
                        newPagesAllocated = pagesAllocated - 1;
                    }
                    while (!__sync_bool_compare_and_swap(&iv_pagesAlloc,
                                                         pagesAllocated,
                                                         newPagesAllocated));
                    continue;
                }
            }

            // Now we have a page allocated, claim our entry first and then
            // hook it up to master list.
            l_entry = newPage->claimEntry(i_size);

            if (!__sync_bool_compare_and_swap(&iv_firstPage,
                                              first,
                                              newPage))
            {
                // We got beat adding page to the master list, so release it
                // and use that page.
                BufferPage::deallocate(newPage);
                do
                {
                    pagesAllocated = iv_pagesAlloc;
                    newPagesAllocated = pagesAllocated - 1;
                }
                while (!__sync_bool_compare_and_swap(&iv_pagesAlloc,
                                                     pagesAllocated,
                                                     newPagesAllocated));

                // The entry we claimed out of the "new" page is no longer
                // valid since we've freed it.
                l_entry = NULL;
                continue;
            }

            // Since we allocated a page, signal any other tasks that might be
            // blocked waiting for a page to show up.
            futex_wake(reinterpret_cast<uint64_t*>(
                            const_cast<BufferPage**>(&iv_firstPage)),
                       UINT64_MAX);

            // And since we allocated a page, wake up the daemon if we
            // allocated the last page or if there are more than 4 pages
            // and we are an infinite buffer.  (4 pages is arbitrary).
            static const size_t SIGNAL_AFTER_N_PAGES_ALLOCATED = 4;
            if ((pagesAllocated == iv_pagesMax) ||
                ((pagesAllocated >= SIGNAL_AFTER_N_PAGES_ALLOCATED) &&
                 (iv_pagesMax == UNLIMITED)))
            {
                iv_daemon->signal();
            }


        } while(!l_entry);

        // Update component name and entry size.
        l_entry->comp = i_comp;
        l_entry->size = i_size - sizeof(Entry);

        // Leave critical section.
        _producerExit();

        return l_entry;
    }

    BufferPage* Buffer::claimPages()
    {
        // Enter critical daemon section.
        _consumerEnter();

        // Take page(s) from buffer.
        BufferPage* page = iv_firstPage;
        iv_firstPage = NULL;
        iv_pagesAlloc = 0;

        // Rewind to beginning of buffer.
        if (page)
        {
            while(page->prev) { page = page->prev; }
        }

        // Signal producers that might be waiting for pages to free up.
        futex_wake(reinterpret_cast<uint64_t*>(
                            const_cast<BufferPage**>(&iv_firstPage)),
                       UINT64_MAX);

        // Exit critical daemon section.
        _consumerExit();

        return page;
    }

    void Buffer::commitEntry(Entry* i_entry)
    {
        // Prevent daemon from making updates while we're in here.
        _producerEnter();

        // Read the component from the entry itself (added as part of claiming).
        ComponentDesc* l_comp = i_entry->comp;

        // Lockless loop to update component linked-list.
        do
        {
            // Update our entry's "next" pointer.
            i_entry->next = l_comp->iv_first;

            // If there is an entry, update its "prev" pointer to this entry.
            if (i_entry->next)
            {
                if (!__sync_bool_compare_and_swap(&i_entry->next->prev,
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
        //
        // It is possible that the committer of the preceeding entry was
        // "slow", so we need to keep trying to update until the current
        // compoment "first" points at the preceeding entry and then make
        // it point at this entry.
        //
        while (!__sync_bool_compare_and_swap(&l_comp->iv_first,
                                             i_entry->next,
                                             i_entry));


        // Atomically increment component size.
        __sync_add_and_fetch(&l_comp->iv_curSize, i_entry->size);

        // Mark entry as committed.
        i_entry->committed = 1;

        // All done, release for daemon.
        _producerExit();

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

        // Prevent daemon from changing things while we're extracting.
        _producerEnter();

        size_t l_totalSize = l_size;
        Entry* entry = i_comp->iv_first;
        Entry* orig_entry = entry;

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

                    if ((entry->next) &&
                        (entry->next->comp))
                    {
                        entry = entry->next;
                        continue;
                    }
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
            while(1)
            {
                // Copy entry data.
                memcpy(&l_data[l_size], &entry->data[0],entry->size);
                l_size += entry->size;

                // Copy entry size.
                uint32_t entry_size = entry->size + sizeof(uint32_t);
                memcpy(&l_data[l_size], &entry_size, sizeof(uint32_t));
                l_size += sizeof(uint32_t);

                l_entries++;

                if (entry == orig_entry)
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

        // Unlock for daemon.
        _producerExit();

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
                                Entry** i_condActAddr,
                                Entry* i_condActVal,
                            Entry** i_addr, Entry* i_val)
    {
        bool rc = true;

        // Get consumer lock.
        _consumerEnter();

        // Primative #1.
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

        // Primative #2.
        if (NULL != i_addr)
        {
            *i_addr = i_val;
        }

        // Release consumer lock.
        _consumerExit();

        return rc;
    }

}
