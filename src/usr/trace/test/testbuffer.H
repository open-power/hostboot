/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/test/testbuffer.H $                             */
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
