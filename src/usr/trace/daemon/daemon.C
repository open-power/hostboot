/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/daemon/daemon.C $                               */
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
#include "daemon.H"
#include "../daemonif.H"
#include "../service.H"
#include "../buffer.H"
#include "../bufferpage.H"
#include "../entry.H"
#include "../compdesc.H"
#include "../debug.H"

#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>

#include <sys/msg.h>
#include <kernel/console.H>
#include <util/align.H>

#include <targeting/common/commontargeting.H>
#include <devicefw/userif.H>

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
    }

    Daemon::~Daemon()
    {
        assert(0);
    }

    void Daemon::execute()
    {
        // Mark the daemon as started in the interface.
        iv_service = Service::getGlobalInstance();
        iv_service->iv_daemon->start();

        // Register shutdown events with init service.
        //      Do one at the "beginning" and "end" of shutdown processesing.
        //      The one at the beginning will flush out everything prior to
        //      the shutdown sequencing and get it out the mailbox.
        //
        //      The one at the end will only be useful in non-FSP environments
        //      for continuous trace, because the mailbox is already shutdown.
        //
        INITSERVICE::registerShutdownEvent(iv_service->iv_daemon->iv_queue,
                                           DaemonIf::TRACE_DAEMON_SIGNAL,
                                           INITSERVICE::HIGHEST_PRIORITY);
        INITSERVICE::registerShutdownEvent(iv_service->iv_daemon->iv_queue,
                                           DaemonIf::TRACE_DAEMON_SIGNAL,
                                           INITSERVICE::LOWEST_PRIORITY);

        // Clear scratch register.
        writeScratchReg(0);

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

                    break;
                }

                // Shutdown message.
                case DaemonIf::TRACE_DAEMON_SHUTDOWN:
                {
                    // The main daemon should never shut down.
                    assert(0);
                    break;
                }


                default:
                {
                    assert(0);
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

            // Calculate the sizes of the entry.
            size_t contEntryDataLength =
                reinterpret_cast<trace_bin_entry_t*>(&whichEntry->data[0])
                    ->head.length + sizeof(trace_bin_entry_t);

            size_t contEntrySize = whichEntry->comp->iv_compNameLen +
                                   contEntryDataLength;

            // Allocate a new continuous trace page if needed.
            if ((NULL == contBuffer) ||
                ((contBufferSize + contEntrySize) >= PAGESIZE))
            {
                if (NULL != contBuffer)
                {
                    sendContBuffer(contBuffer, contBufferSize);
                }

                contBuffer = reinterpret_cast<char*>(malloc(PAGESIZE));
                memset(contBuffer, '\0', PAGESIZE);
                contBuffer[0] = TRACE_BUF_CONT;
                contBufferSize = 1;
            }

            // Add entry to continous trace.
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

        // Send remainder of continous trace buffer.
        if (NULL != contBuffer)
        {
            if (contBufferSize > 1)
            {
                sendContBuffer(contBuffer, contBufferSize);
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
        // Write scratch register indicating continuous trace is available.
        writeScratchReg(1ull << 32);

        // Signal for simics.
        asm volatile("mr 4, %0; mr 5, %1" ::
                     "r" (i_buffer), "r" (i_size) : "4", "5");
        MAGIC_INSTRUCTION(MAGIC_CONTINUOUS_TRACE);

        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);

        TARGETING::SpFunctions spFunctions =
            sys->getAttr<TARGETING::ATTR_SP_FUNCTIONS>();
        TARGETING::HbSettings hbSettings =
            sys->getAttr<TARGETING::ATTR_HB_SETTINGS>();

        // Determine if continuous trace is currently enabled.
        bool contEnabled = hbSettings.traceContinuous;
        if (g_debugSettings.contTraceOverride != 0)
        {
            contEnabled = (g_debugSettings.contTraceOverride == 2);
        }

        if (!contEnabled)
        {
            // Trace isn't enabled so just discard the buffer.
            free(i_buffer);
        }
        else
        {
            if (spFunctions.mailboxEnabled)
            {
                // TODO: Send message to FSP.
                free(i_buffer);
            }
            else
            {
                // Wait for tools to extract the buffer.
                while(0 != readScratchReg())
                {
                    task_yield();
                }
                free(i_buffer);
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

    void Daemon::pruneTraceEntries()
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
            while((entry) && (component->iv_curSize > component->iv_maxSize))
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

    void Daemon::writeScratchReg(uint64_t i_value)
    {
        size_t l_size = sizeof(uint64_t);

        errlHndl_t l_errl =
            deviceWrite(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                        &i_value, l_size,
                        DEVICE_SCOM_ADDRESS(MB_SCRATCH_REGISTER_1));

        if (l_errl)
        {
            errlCommit(l_errl, HBTRACE_COMP_ID);
        }
    }

    uint64_t Daemon::readScratchReg()
    {
        size_t l_size = sizeof(uint64_t);
        uint64_t value = 0;

        errlHndl_t l_errl =
            deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                       &value, l_size,
                       DEVICE_SCOM_ADDRESS(MB_SCRATCH_REGISTER_1));

        if (l_errl)
        {
            errlCommit(l_errl, HBTRACE_COMP_ID);
        }

        return value;
    }

}

// Define an entry point for the trace daemon module.
TASK_ENTRY_MACRO( TRACEDAEMON::daemonProcess );
