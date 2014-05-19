/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/kernel/vmmbasetest.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
/** @file vmmbasetest.H
 *  @brief Test cases for permission settings on the base block of the VMM.
 */
#ifndef __KERNEL_VMMBASETEST_H
#define __KERNEL_VMMBASETEST_H

#include <cxxtest/TestSuite.H>
#include <sys/task.h>
#include <kernel/console.H>
#include <kernel/pagemgr.H>
#include <arch/ppc.H>
#include <sys/mm.h>
#include <usr/vmmconst.h>
#include <targeting/common/util.H>

class VmmBaseTest : public CxxTest::TestSuite
{
    public:
        static msg_q_t iv_mq;

        void testNullAccess()
        {
            int status;

            printk("Test case: Expect to see uncaught exception! ");
            tid_t child = task_create(readFromNULL, NULL);

            if ((child != task_wait_tid(child, &status, NULL)) ||
                (status != TASK_STATUS_CRASHED))
            {
                TS_FAIL("Write to NULL not caught.");
            }

            printk("Test case: Expect to see uncaught exception! ");
            child = task_create(writeToNULL, NULL);
            if ((child != task_wait_tid(child, &status, NULL)) ||
                (status != TASK_STATUS_CRASHED))
            {
                TS_FAIL("Write to NULL not caught.");
            }
        }

        void testWriteToKernelCode()
        {
            int status;

            printk("Test case: Expect to see uncaught exception! ");
            tid_t child = task_create(writeToKernelCode, NULL);
            if ((child != task_wait_tid(child, &status, NULL)) ||
                (status != TASK_STATUS_CRASHED))
            {
                TS_FAIL("Write to kernel code not caught.");
            }
        }

        void testExecuteKernelDataSpace()
        {
            // @TODO. VMM not ready.
        }

        void testWriteModuleText()
        {
            // @TODO. VMM not ready.
        }

        void testExecuteModuleDataSpace()
        {
            // @TODO. VMM not ready.
        }

        // Do not run this test by default since we now have a lot of
        //  mainstore to fill up.  We know that this function gets
        //  tested during the IPL so the unit test isn't required.
        //  However, leaving it here in case we want to run some
        //  targeted tests at a later date.
        void skipme_testCastOutPages()
        {
            uint64_t l_testAddr = VMM_VADDR_RMVPAGE_TEST;
            uint64_t l_testSize = VMM_SIZE_RMVPAGE_TEST;
            uint64_t vaddr = l_testAddr+l_testSize;
            uint64_t vsize = PageManager::availPages()*PAGESIZE;
            int rc = mm_alloc_block(iv_mq,reinterpret_cast<void*>(vaddr),vsize);
            if (rc != 0)
            {
                TS_FAIL("Unable to allocate block.\n");
            }
            //TODO - Mix READ_ONLY and WRITE_TRACKED pages to cast out test
            rc = mm_set_permission(reinterpret_cast<void*>(vaddr),vsize,
                                   (uint64_t)(READ_ONLY));
            if (rc != 0)
            {
                TS_FAIL("Failed to set block permissions to READ_ONLY.\n");
            }
            task_create(msgDaemon, NULL);
            //Touch each page until less than 10% free pages remain
            //printk("Page Percent Avail: 0x%lX\n",PageManager::queryAvail());
            for(uint64_t i = vaddr; i < (vaddr + vsize); i += PAGESIZE)
            {
                if (PageManager::queryAvail() < 10)
                {
                    printkd("Less than 10 percent pages remain\n");
                    break;
                }
                (*(volatile uint64_t *)i); sync();
            }

            // Don't delay in VPO because it will take VERY long to
            // run the simulator
            if( !TARGETING::is_vpo() )
            {
                nanosleep(1,0);
            }
        }

    private:

        static void* readFromNULL(void* unused)
        {
            printk("%lx", (*(uint64_t*)NULL));
            return NULL;
        }

        static void* writeToNULL(void* unused)
        {
            (*(uint64_t*)NULL) = 0x12345678;
            return NULL;
        }

        static void* writeToKernelCode(void* unused)
        {
            uint64_t value = 0x12345678;

            union fn_ptr
            {
                void (*opd)(const char*, ...);
                uint64_t** data;
            };
            fn_ptr function = { printk };

            memcpy(*function.data, &value, sizeof(value));
            return NULL;
        }

        static void* msgDaemon(void* unused)
        {
            msg_t* message = NULL;
            while (1)
            {
                message = msg_wait(iv_mq);
                if (message)
                {
                    /*printkd("Effective Addr: 0x%lX, %s\n",message->data[0],
                            message->type==MSG_MM_RP_READ?"READ":"WRITE");*/
                    message->data[1] = 0;
                    msg_respond(iv_mq, message);
                }
            }
            return NULL;
        }

};
msg_q_t VmmBaseTest::iv_mq = msg_q_create();

#endif
