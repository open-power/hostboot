/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/runtime/rt_daemon.C $                           */
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
#include "../daemon/daemon.H"
#include "../daemonif.H"
#include "../service.H"
#include "../buffer.H"
#include "../bufferpage.H"
#include "../entry.H"
#include "../compdesc.H"
#include "../debug.H"

#include <errl/hberrltypes.H>
#include <string.h>
#include <util/align.H>


namespace TRACEDAEMON
{
    using namespace TRACE;

    Daemon::Daemon() : iv_service(nullptr), iv_totalPruned(0)
    {
        iv_first = iv_last = BufferPage::allocate(true);
    }

    Daemon::~Daemon()
    {
        assert(0, "No need to destruct the trace Daemon");
    }

    void Daemon::signal_trace_daemon(void)
    {
        // Put here to avoid build issue instead of in class constructor
        // iv_service won't be used until these functions are called
        iv_service = Service::getGlobalInstance();

        // Collect trace entries from client.
        collectTracePages();

        // Reduce buffer space in daemon-side buffer.
        pruneTraceEntries();

        // combine trace buffer pages to remove pruned entries
        coalescePages();
    }


    void Daemon::collectTracePages()
    {
        // Collect buffer pages from front-end.
        BufferPage* srcPages[BUFFER_COUNT];
        for (size_t i = 0; i < BUFFER_COUNT; i++)
        {
            if (iv_service->iv_buffers[i] == nullptr)
            {
                iv_curPages[i] = srcPages[i] = nullptr;
            }
            else
            {
                iv_curPages[i] = srcPages[i] =
                    iv_service->iv_buffers[i]->claimPages();
            }
            iv_curOffset[i] = 0;
        }

        uint32_t entry_number = 0;
        // Process buffer pages.
        do
        {
            size_t whichBuffer = BUFFER_COUNT;
            Entry* whichEntry = nullptr;
            uint64_t minTimeStamp = UINT64_MAX;

            // Find the entry with the earliest timestamp.
            for (size_t i = 0; i < BUFFER_COUNT; i++)
            {
                if (nullptr == iv_curPages[i]) continue;

                Entry* entry =
                    reinterpret_cast<Entry*>(
                        &((&(iv_curPages[i]->data[0]))[iv_curOffset[i]])
                    );

                trace_bin_entry_t* binEntry =
                    reinterpret_cast<trace_bin_entry_t*>(
                        &(entry->data[0])
                    );


                uint64_t curTimeStamp =
                    TWO_UINT32_TO_UINT64(binEntry->stamp.tbh,
                                         binEntry->stamp.tbl);

                if (curTimeStamp < minTimeStamp )
                {
                    whichBuffer = i;
                    whichEntry = entry;
                    minTimeStamp = curTimeStamp;
                }
            }

            // Did not find another entry, our work is done.
            if (whichBuffer == BUFFER_COUNT)
            {
                break;
            }

            if ((whichEntry == nullptr) || (whichEntry->comp == nullptr))
            {
                break;
            }

            // Increment pointers to next buffer entry.
            iv_curOffset[whichBuffer] += whichEntry->size + sizeof(Entry);
            if (iv_curOffset[whichBuffer] >= iv_curPages[whichBuffer]->usedSize)
            {
                iv_curPages[whichBuffer] = iv_curPages[whichBuffer]->next;
                iv_curOffset[whichBuffer] = 0;
            }

            // Allocate a new back-end entry.
            Entry* mainBuffEntry = nullptr;
            while (nullptr ==
                (mainBuffEntry =
                    iv_last->claimEntry(whichEntry->size + sizeof(Entry))))
            {
                BufferPage* n = BufferPage::allocate(true);

                // Remember iv_last = Last newest combined-buffer page.
                // Set n to the newest page, and push current iv_last back
                n->next = iv_last;
                iv_last->prev = n;
                iv_last = n;
                iv_last->prev = nullptr;
            }

            // Move entry from front-end buffer to back-end.
            replaceEntry(whichEntry, mainBuffEntry);

            entry_number++;
        } while(1);

        // Release pages.
        for (size_t i = 0; i < BUFFER_COUNT; i++)
        {
            while(srcPages[i])
            {
                BufferPage* tmp = srcPages[i]->next;
                BufferPage::deallocate(srcPages[i]);
                srcPages[i] = tmp;
            }
        }
    }


    void Daemon::replaceEntry(Entry* from, Entry* to)
    {
        do
        {
            // Copy entry content to new entry.
            memcpy(to,
                   from,
                   from->size + sizeof(Entry));

            // Update next object's pointer.
            if (to->next)
            {
                to->next->prev = to;
            }
            else
            {
                if (to->comp != nullptr)
                {
                    to->comp->iv_last = to;
                }
            }

            // Update prev object's pointer.
            //     Buffer ensures that an entry's "next" is written before
            //     the "next->prev", so we can be certain that if to->prev
            //     then to->prev->next is finalized.
            if (to->prev)
            {
                to->prev->next = to;
            }
            else // If there is no previous, this is the first (most recent)
                 // for the component, so update the component object.
            {
                if (to->comp != nullptr)
                {
                    Buffer* b =
                        iv_service->iv_buffers[to->comp->iv_bufferType];

                    // Need to toggle the consumer lock on this one, so use
                    // the consumerOp to move the compoment->first from
                    // 'from' to 'to'.
                    //
                    // If it fails (first != from anymore) then retry this
                    // whole sequence.
                    if (!b->consumerOp(&to->comp->iv_first, from,
                                       &to->comp->iv_first, to))
                    {
                        continue;
                    }
                }
            }

            // Successfully updated everything, break from loop.
            break;

        } while (1);
    }


    void Daemon::pruneTraceEntries(bool i_all)
    {
        ComponentList::List::iterator component;

        size_t pruned = 0;

        // Iterate through the components...
        bool more = iv_service->iv_compList->first(component);
        while(more)
        {
            Entry* entry = component->iv_last;
            Entry* orig_entry = entry;

            // Invalidate entries until the component is small enough.
            while((entry) &&
                    ((component->iv_curSize > component->iv_maxSize) ||
                     i_all)
                 )
            {
                if (!reinterpret_cast<BufferPage*>(
                        ALIGN_PAGE_DOWN(
                            reinterpret_cast<uint64_t>(entry)))->commonPage)
                {
                    break;
                }

                entry->comp = nullptr; // Invalidate entry.

                __sync_sub_and_fetch(&component->iv_curSize, entry->size);
                pruned += entry->size;

                entry = entry->prev;
            }

            if (entry != orig_entry)
            {

                // Break chain of linked list.
                if (entry != nullptr)
                {
                    entry->next = nullptr;
                }

                // Update component pointers.
                Buffer* b =
                    iv_service->iv_buffers[component->iv_bufferType];

                // consumerOp pseudo-code:
                //    if (entry == nullptr) component->first = nullptr;
                //    component->last = entry;
                b->consumerOp(&entry, nullptr,
                              &component->iv_first, nullptr,
                              &component->iv_last, entry);
            }

            // Get next component.
            more = iv_service->iv_compList->next(component);
        }

        // Record size of pruned entries in a global.
        if (pruned)
        {
            iv_totalPruned += pruned;
        }
    }

    void Daemon::coalescePages()
    {
        // Skip if there hasn't been enough entries pruned to make this
        // worth our while.
        if (iv_totalPruned < PAGESIZE) { return; }

        iv_totalPruned = 0;

        // Allocate a new back-end page for the coalesced entries.
        BufferPage* outputPage = BufferPage::allocate(true);
        BufferPage* originalOutputPage = outputPage;

        // Get the first page from the original back-end buffer.
        BufferPage* currentPage = iv_first;

        // Iterate through the back-end pages.
        while(currentPage != nullptr)
        {
            // Look at all the entries on the back-end pages.
            size_t offset = 0;
            while (offset < currentPage->usedSize)
            {
                Entry* entry =
                    reinterpret_cast<Entry*>(&currentPage->data[offset]);

                if (nullptr != entry->comp) // Ensure entry is valid.
                {
                    Entry* newEntry = nullptr;

                    // Allocate space on new back-end pages.
                    while (nullptr == (newEntry =
                        outputPage->claimEntry(entry->size + sizeof(Entry))))
                    {
                        BufferPage* newPage = BufferPage::allocate(true);

                        newPage->next = outputPage;
                        outputPage->prev = newPage;
                        outputPage = newPage;
                    }

                    // Move entry to new back-end page.
                    replaceEntry(entry, newEntry);
                }

                offset += entry->size + sizeof(Entry);
            }

            currentPage = currentPage->prev;
        }

        BufferPage* oldPage = iv_first;

        // Update back-end buffer pointers to point to new back-end pages.
        iv_last = outputPage;
        iv_first = originalOutputPage;

        // Delete the old back-end pages.
        while(oldPage)
        {
            BufferPage* temp = oldPage->prev;
            BufferPage::deallocate(oldPage);
            oldPage = temp;
        }

    }

}
