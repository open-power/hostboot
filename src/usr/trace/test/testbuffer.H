/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/test/testbuffer.H $                             */
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
#include "../buffer.H"
#include "../bufferpage.H"
#include "../compdesc.H"
#include "../entry.H"
#include "../daemonif.H"

#include <cxxtest/TestSuite.H>
#include <limits.h>
#include <sys/task.h>
#include <sys/time.h>
#include <kernel/pagemgr.H>

namespace TRACE
{

class BufferTest : public CxxTest::TestSuite
{
    public:
        void testClaimEntry()
        {
            DaemonIf d;
            Buffer b(&d, 1);

            tid_t child = task_create(testClaimEntryThread, &b);
            msg_free(d.wait());

            BufferPage* page = b.claimPages();
            PageManager::freePage(page);

            task_wait_tid(child, NULL, NULL);

            page = b.claimPages();
            if (NULL == page)
            {
                TS_FAIL("Not enough pages created in trace buffer.\n");
            }
            PageManager::freePage(page);

            page = b.claimPages();
            if (NULL != page)
            {
                TS_FAIL("Too many pages created in trace buffer.\n");
            }

        }

        static void* testClaimEntryThread(void* _buffer)
        {
            Buffer* b = reinterpret_cast<Buffer*>(_buffer);

            ComponentList l;
            ComponentDesc* t = l.getDescriptor("TEST", 2048);

            static const size_t ALLOC_SIZE = 128;

            for(size_t i = 0; i < PAGESIZE/ALLOC_SIZE; i++)
            {
                Entry* e = b->claimEntry(t, ALLOC_SIZE - sizeof(Entry));
                if (e->comp != t)
                {
                    TS_FAIL("Component ID is not updated in entry.");
                }
            }

            return NULL;

        }
};

}
