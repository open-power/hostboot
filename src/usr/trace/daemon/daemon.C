/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/daemon/daemon.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
/* [+] Google Inc.                                                        */
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
#include "daemon.H"
#include "../daemonif.H"
#include "../service.H"
#include "../buffer.H"
#include "../bufferpage.H"
#include "../entry.H"
#include "../compdesc.H"
#include "../debug.H"

#include <errno.h>

#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>

#include <sys/msg.h>
#include <sys/task.h>
#include <kernel/console.H>
#include <arch/magic.H>
#include <util/align.H>

#include <targeting/common/commontargeting.H>
#include <devicefw/userif.H>

#include <mbox/mboxif.H>
#include <console/consoleif.H>
#include <util/utilmbox_scratch.H>
#include <debugpointers.H>

namespace TRACE
{
    // Functions from DaemonIf that are only used by the daemon itself,
    // so implemented here to decrease size of base module.

    void DaemonIf::start()
    {
        iv_running = true;
    }

    void DaemonIf::clearSignal()
    {
        // Atomically reset signal.
        __sync_lock_test_and_set(&iv_signalled, 0);
    }
}

namespace TRACEDAEMON
{
    using namespace TRACE;

    Daemon::Daemon() : iv_service(NULL), iv_totalPruned(0)
    {
        iv_first = iv_last = BufferPage::allocate(true);

        DEBUG::add_debug_pointer(DEBUG::TRACEDAEMON,
                                 this,
                                 sizeof(TRACEDAEMON::Daemon));
    }

    Daemon::~Daemon()
    {
        assert(0);
    }

    void Daemon::execute()
    {
        // Mark as an independent daemon so if it crashes we terminate.
        task_detach();

        // Mark the daemon as started in the interface.
        iv_service = Service::getGlobalInstance();
        iv_service->iv_daemon->start();

        // Register messages with mailbox daemon.
        {
            errlHndl_t l_errl = MBOX::msgq_register(MBOX::HB_TRACE_MSGQ,
                                            iv_service->iv_daemon->iv_queue);
            if (l_errl)
            {
                errlCommit(l_errl, TRACE_COMP_ID);
            }
        }

        // Register shutdown events with init service.
        //      Do one at the "beginning" and "end" of shutdown processesing.
        //      The one at the beginning will flush out everything prior to
        //      the shutdown sequencing and get it out the mailbox.
        //
        //      The one at the end will only be useful in non-FSP environments
        //      for continuous trace, because the mailbox is already shutdown.
        //
        INITSERVICE::registerShutdownEvent(TRACE_COMP_ID,
                                           iv_service->iv_daemon->iv_queue,
                                           DaemonIf::TRACE_DAEMON_SIGNAL,
                                           INITSERVICE::HIGHEST_PRIORITY);
        INITSERVICE::registerShutdownEvent(TRACE_COMP_ID,
                                           iv_service->iv_daemon->iv_queue,
                                           DaemonIf::TRACE_DAEMON_SIGNAL,
                                           INITSERVICE::LOWEST_PRIORITY);

        // Clear scratch register.
        Util::writeScratchReg(INITSERVICE::SPLESS::MboxScratch1_t::REG_ADDR, 0);
        Util::writeScratchReg(INITSERVICE::SPLESS::MboxScratch2_t::REG_ADDR, 0);

        // Loop handling messages.
        while (msg_t* msg = iv_service->iv_daemon->wait())
        {
            switch (msg->type)
            {
                // Signal from client.
                case DaemonIf::TRACE_DAEMON_SIGNAL:
                {
                    // Collect trace entries from client.
                    collectTracePages();

                    // Reduce buffer space in daemon-side buffer.
                    pruneTraceEntries();
                    coalescePages();

#ifdef CONFIG_CONSOLE_OUTPUT_TRACE
                    // Flush console.
                    CONSOLE::flush();
#endif

                    msg->data[0] = msg->data[1] = 0;
                    break;
                }

                // Shutdown message.
                case DaemonIf::TRACE_DAEMON_SHUTDOWN:
                {
                    // The main daemon should never shut down.
                    assert(0);
                    break;
                }

                // Continuous trace state.
                case DaemonIf::TRACE_CONT_TRACE_STATE:
                {
                    if (msg->data[0] == 0)
                    {
                        g_debugSettings.contTraceOverride =
                            DebugSettings::CONT_TRACE_FORCE_DISABLE;
                    }
                    else if (msg->data[0] == 1) //enable from FSP
                    {
                        g_debugSettings.contTraceOverride =
                            DebugSettings::CONT_TRACE_FORCE_ENABLE;
                    }
                    else if (msg->data[0] == 2) //enable from debugComm
                    {
                        g_debugSettings.contTraceOverride =
                            DebugSettings::CONT_TRACE_FORCE_ENABLE_DEBUG_COMM;
                    }

                    msg->data[0] = msg->data[1] = 0;
                    break;
                }

                // Reset trace buffers.
                case DaemonIf::TRACE_RESET_BUFFERS:
                {
                    // Collect current trace entries from client.
                    collectTracePages();

                    // Prune all trace entries.
                    pruneTraceEntries(true);
                    coalescePages();

                    msg->data[0] = msg->data[1] = 0;
                    break;
                }

                // Enable / disable debug state.
                case DaemonIf::TRACE_ENABLE_DEBUG:
                case DaemonIf::TRACE_DISABLE_DEBUG:
                {
                    bool enable = (msg->type == DaemonIf::TRACE_ENABLE_DEBUG);

                    // An empty string indicates request to modify the global
                    // override setting.
                    if ('\0' == *reinterpret_cast<char*>(&msg->data[0]))
                    {
                        g_debugSettings.globalDebugEnable = enable;
                        msg->data[0] = msg->data[1] = 0;
                    }
                    // Otherwise, data0/1 are a 16-char array of the
                    // component name.  extra_data gives us the '\0'
                    // terminator if the full 16 are needed.
                    else
                    {
                        ComponentDesc* iv_comp =
                            iv_service->iv_compList->getDescriptor(
                                reinterpret_cast<const char*>(&msg->data[0]),
                                0);

                        if (iv_comp == NULL)
                        {
                            msg->data[0] = EBADF;
                            msg->data[1] = 0;
                        }
                        else
                        {
                            iv_comp->iv_debugEnabled = enable;
                            msg->data[0] = msg->data[1] = 0;
                        }
                    }
                    break;
                }

                case DaemonIf::TRACE_EXTRACT_BUFFERS:
                {
                    // Collect current trace entries from client.
                    collectTracePages();

                    // Extract trace buffers.
                    extractTraceBuffer();

                    msg->data[0] = msg->data[1] = 0;
                    break;
                }


                default:
                {
                    // Since we can get messages from the FSP (of unknown
                    // quality), we don't want to assert here.  Not really
                    // much we can do, so blindly ignore this condition.
                    msg->data[0] = EINVAL;
                    break;
                }
            }

            // Delete or respond as appropriate.
            if (msg_is_async(msg))
            {
                msg_free(msg);
            }
            else
            {
                msg_respond(iv_service->iv_daemon->iv_queue, msg);
            }
        }
    }

    void* Daemon::start(void* unused)
    {
        Singleton<Daemon>::instance().execute();
        return NULL;
    }

    void daemonProcess(errlHndl_t& o_errl)
    {
        task_create(&Daemon::start, NULL);
    }


    void Daemon::collectTracePages()
    {
        // Clear indication from clients.
        iv_service->iv_daemon->clearSignal();

        // Collect buffer pages from front-end.
        BufferPage* srcPages[BUFFER_COUNT];
        for (size_t i = 0; i < BUFFER_COUNT; i++)
        {
            iv_curPages[i] = srcPages[i] =
                iv_service->iv_buffers[i]->claimPages();

            iv_curOffset[i] = 0;
        }

        char* contBuffer = NULL;
        size_t contBufferSize = 0;

        // Process buffer pages.
        do
        {
            size_t whichBuffer = BUFFER_COUNT;
            Entry* whichEntry = NULL;
            uint64_t minTimeStamp = UINT64_MAX;

            // Find the entry with the earliest timestamp.
            for (size_t i = 0; i < BUFFER_COUNT; i++)
            {
                if (NULL == iv_curPages[i]) continue;

                Entry* entry =
                    reinterpret_cast<Entry*>(
                        &((&(iv_curPages[i]->data[0]))[iv_curOffset[i]])
                    );

                trace_bin_entry_t* binEntry =
                    reinterpret_cast<trace_bin_entry_t*>(
                        &(entry->data[0])
                    );

                // Wait for entry to be committed.
                while(unlikely(entry->committed == 0))
                {
                    task_yield();
                }
                isync();

                uint64_t curTimeStamp =
                    TWO_UINT32_TO_UINT64(binEntry->stamp.tbh,
                                         binEntry->stamp.tbl);

                if (curTimeStamp < minTimeStamp)
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

            // Increment pointers to next buffer entry.
            iv_curOffset[whichBuffer] += whichEntry->size + sizeof(Entry);
            if (iv_curOffset[whichBuffer] >= iv_curPages[whichBuffer]->usedSize)
            {
                iv_curPages[whichBuffer] = iv_curPages[whichBuffer]->next;
                iv_curOffset[whichBuffer] = 0;
            }

            trace_bin_entry_t* contEntry =
                reinterpret_cast<trace_bin_entry_t*>(&whichEntry->data[0]);

            // Calculate the sizes of the entry.
            size_t contEntryDataLength = contEntry->head.length +
                                         sizeof(trace_bin_entry_t);

            size_t contEntrySize = whichEntry->comp->iv_compNameLen +
                                   contEntryDataLength;

            // Allocate a new continuous trace page if needed.
            if ((NULL == contBuffer) ||
                ((contBufferSize + contEntrySize) >= PAGESIZE))
            {
                if (NULL != contBuffer)
                {
                    sendContBuffer(contBuffer, contBufferSize);
                    // contBuffer pointer is transferred to mailbox now.
                }

                // We need this to be contiguous and identity-mapped
                //  to physical address space, so that our simics
                //  handler can extract them (it uses physical
                //  addresses).
                contBuffer = reinterpret_cast<char*>(contiguous_malloc(PAGESIZE));
                memset(contBuffer, '\0', PAGESIZE);
                contBuffer[0] = TRACE_BUF_CONT;
                contBufferSize = 1;
            }

            // Add entry to continuous trace.
            memcpy(&contBuffer[contBufferSize],
                   whichEntry->comp->iv_compName,
                   whichEntry->comp->iv_compNameLen);
            contBufferSize += whichEntry->comp->iv_compNameLen;

            memcpy(&contBuffer[contBufferSize],
                   &whichEntry->data[0],
                   contEntryDataLength);
            contBufferSize += contEntryDataLength;

            // Allocate a new back-end entry.
            Entry* mainBuffEntry = NULL;
            while (NULL ==
                (mainBuffEntry =
                    iv_last->claimEntry(whichEntry->size + sizeof(Entry))))
            {
                BufferPage* n = BufferPage::allocate(true);

                n->next = iv_last;
                iv_last->prev = n;
                iv_last = n;
            }

            // Move entry from front-end buffer to back-end.
            replaceEntry(whichEntry, mainBuffEntry);

        } while(1);

        // Send remainder of continuous trace buffer.
        if (NULL != contBuffer)
        {
            if (contBufferSize > 1)
            {
                sendContBuffer(contBuffer, contBufferSize);
                // contBuffer pointer is transferred to mailbox now.
            }
            else
            {
                free(contBuffer);
            }
        }

        // Release pages.
        for (size_t i = 0; i < BUFFER_COUNT; i++)
        {
            // Toggle lock to ensure no trace extract currently going on.
            iv_service->iv_buffers[i]->consumerOp();

            while(srcPages[i])
            {
                BufferPage* tmp = srcPages[i]->next;
                BufferPage::deallocate(srcPages[i]);
                srcPages[i] = tmp;
            }
        }

    }


    void Daemon::sendContBuffer(void* i_buffer, size_t i_size)
    {
        // Write debug structure with buffer information.
        g_debugSettings.bufferSize = i_size;
        g_debugSettings.bufferPage = i_buffer;

        // Signal for simics.
        asm volatile("mr 4, %0; mr 5, %1" ::
                     "r" (i_buffer), "r" (i_size) : "4", "5");
        MAGIC_INSTRUCTION(MAGIC_CONTINUOUS_TRACE);

        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);

        TARGETING::HbSettings hbSettings =
            sys->getAttr<TARGETING::ATTR_HB_SETTINGS>();

        // Determine if continuous trace is currently enabled.
        bool contEnabled = hbSettings.traceContinuous;
        if (g_debugSettings.contTraceOverride !=
                DebugSettings::CONT_TRACE_USE_ATTR)
        {
            contEnabled = (g_debugSettings.contTraceOverride >=
                            DebugSettings::CONT_TRACE_FORCE_ENABLE);
        }

        if(contEnabled)
        {
            //Only send via debugComm if tool has explicitly enabled
            //otherwise this will "hang" hostboot while it waits for the tool
            if(g_debugSettings.contTraceOverride ==
                            DebugSettings::CONT_TRACE_FORCE_ENABLE_DEBUG_COMM)
            {
                // Write scratch register indicating is available.
                uint64_t l_addr = reinterpret_cast<uint64_t>(i_buffer);
                Util::writeDebugCommRegs(Util::MSG_TYPE_TRACE,
                                         l_addr,
                                         i_size);
            }

            //Always attempt to send to FSP if enabled
            if (MBOX::mailbox_enabled())
            {
                msg_t* msg = msg_allocate();
                msg->type = DaemonIf::TRACE_CONT_TRACE_BUFFER;
                msg->data[1] = i_size;
                msg->extra_data = MBOX::allocate(i_size);
                memcpy(msg->extra_data,i_buffer,i_size);

                errlHndl_t l_errl = MBOX::send(MBOX::FSP_TRACE_MSGQ, msg);
                if (l_errl)
                {
                    errlCommit(l_errl, TRACE_COMP_ID);
                    msg_free(msg);
                }
            }
        }

        //Always free the buf
        free(i_buffer);
    }

    void Daemon::sendExtractBuffer(void* i_buffer, size_t i_size)
    {
        // Send buffer message.
        //    We don't need to check for mailbox attributes or readiness
        //    because we should only be sending this message if we were
        //    requested to by the SP.

        msg_t* msg = msg_allocate();
        msg->type = DaemonIf::TRACE_BUFFER;
        msg->data[1] = i_size;
        msg->extra_data = i_buffer;

        errlHndl_t l_errl = MBOX::send(MBOX::FSP_TRACE_MSGQ, msg);
        if (l_errl)
        {
            errlCommit(l_errl, TRACE_COMP_ID);
            MBOX::deallocate(i_buffer);
            msg_free(msg);
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
                to->comp->iv_last = to;
            }
            lwsync();  // Ensure pointer update is globally visible
                       // (to order before 'prev' object updates).

            // Update prev object's pointer.
            //     Buffer ensures that an entries "next" is written before
            //     the "next->prev", so we can be certain that if to->prev
            //     then to->prev->next is finalized.
            if (to->prev)
            {
                to->prev->next = to;
            }
            else // If there is no previous, this is the first (most recent)
                 // for the component, so update the component object.
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

                entry->comp = NULL; // Invalidate entry.

                __sync_sub_and_fetch(&component->iv_curSize, entry->size);
                pruned += entry->size;

                entry = entry->prev;
            }

            if (entry != orig_entry)
            {
                printkd("%s,", component->iv_compName);

                // Break chain of linked list.
                if (entry != NULL)
                {
                    entry->next = NULL;
                }

                // Update component pointers.
                Buffer* b =
                    iv_service->iv_buffers[component->iv_bufferType];

                // consumerOp pseudo-code:
                //    if (entry == NULL) component->first = NULL;
                //    component->last = entry;
                b->consumerOp(&entry, NULL,
                              &component->iv_first, NULL,
                              &component->iv_last, entry);
            }

            // Get next component.
            more = iv_service->iv_compList->next(component);
        }

        // Record size of pruned entries in a global.
        if (pruned)
        {
            printkd(": pruned %ld\n", pruned);
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
        while(currentPage != NULL)
        {

            // Look at all the entries on the back-end pages.
            size_t offset = 0;
            while (offset < currentPage->usedSize)
            {
                Entry* entry =
                    reinterpret_cast<Entry*>(&currentPage->data[offset]);

                if (NULL != entry->comp) // Ensure entry is valid.
                {
                    Entry* newEntry = NULL;

                    // Allocate space on new back-end pages.
                    while (NULL == (newEntry =
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

        // Toggle client buffers to ensure no trace extract is going on
        // on the old back-end pages.
        for (size_t i = 0; i < BUFFER_COUNT; i++)
        {
            iv_service->iv_buffers[i]->consumerOp();
        }

        // Delete the old back-end pages.
        while(oldPage)
        {
            BufferPage* temp = oldPage->prev;
            BufferPage::deallocate(oldPage);
            oldPage = temp;
        }

    }

    void Daemon::extractTraceBuffer()
    {
        char* curBuffer = NULL;
        size_t curBufferSize = 0;

        for(BufferPage* page = iv_first; page != NULL; page = page->prev)
        {
            size_t offset = 0;
            while (offset < page->usedSize)
            {
                Entry* entry = reinterpret_cast<Entry*>(&page->data[offset]);

                if (NULL != entry->comp)
                {
                    trace_bin_entry_t* entryBin =
                        reinterpret_cast<trace_bin_entry_t*>(&entry->data[0]);
                    // Calculate entry size.
                    size_t entryDataLength = entryBin->head.length +
                                             sizeof(trace_bin_entry_t);

                    size_t entrySize = entry->comp->iv_compNameLen +
                                       entryDataLength;

                    // Allocate new page / send old page, if needed.
                    if ((NULL == curBuffer) ||
                        ((curBufferSize + entrySize) >= PAGESIZE))
                    {
                        if (NULL != curBuffer)
                        {
                            sendExtractBuffer(curBuffer, curBufferSize);
                            // curBuffer pointer is transferred to mailbox now.
                        }

                        curBuffer = reinterpret_cast<char*>
                            (MBOX::allocate(PAGESIZE));

                        memset(curBuffer, '\0', PAGESIZE);
                        curBuffer[0] = TRACE_BUF_CONT;
                        curBufferSize = 1;
                    }

                    // Copy entry into buffer.
                    memcpy(&curBuffer[curBufferSize],
                           entry->comp->iv_compName,
                           entry->comp->iv_compNameLen);
                    curBufferSize += entry->comp->iv_compNameLen;

                    memcpy(&curBuffer[curBufferSize],
                           &entry->data[0],
                           entryDataLength);
                    curBufferSize += entryDataLength;
                }

                offset += entry->size + sizeof(Entry);
            }
        }

        // Send remaining buffer page to SP.
        if (NULL != curBuffer)
        {
            sendExtractBuffer(curBuffer, curBufferSize);
            // curBuffer pointer is transferred to mailbox now.
        }

        // Send one last message to the SP to indicate we're done.
        sendExtractBuffer(NULL, 0);

    }
}

// Define an entry point for the trace daemon module.
TASK_ENTRY_MACRO( TRACEDAEMON::daemonProcess );
