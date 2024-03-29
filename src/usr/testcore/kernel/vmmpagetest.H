/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/kernel/vmmpagetest.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2019                        */
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
#ifndef __VMMPAGETEST_H
#define __VMMPAGETEST_H
/**
 *  @file vmmpagetest.H
 *
 *  @brief Test cases for handling pages within virtual memory
*/
#include <cxxtest/TestSuite.H>
#include <arch/ppc.H>
#include <sys/time.h>
#include <sys/task.h>
#include <sys/mm.h>
#include <usr/vmmconst.h>

class vmmpagetest: public CxxTest::TestSuite
{
    public:

        static volatile int rc;
        //Testing page removal variables
        static msg_q_t iv_mq;
        static uint64_t iv_va;
        static uint64_t iv_size;

        void testPageSetup()
        {
            uint64_t initPerm = (uint64_t)(READ_ONLY);
            rc = mm_alloc_block(iv_mq,reinterpret_cast<void*>(iv_va),iv_size);
            if (rc != 0)
            {
                TS_FAIL("Unable to allocate block - rc=%d.\n",rc);
            }
            rc = mm_set_permission(reinterpret_cast<void*>(iv_va),iv_size,
                                   initPerm);
            if (rc != 0)
            {
                TS_FAIL("Failed to set block permissions to READ_ONLY - rc=%d.\n",rc);
            }
            task_create(testDaemon, NULL);
        }

        void testReadPageRelease()
        {
            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+2*PAGESIZE),0,
                                   WRITABLE);

            //Dependent on block being initialized to READ_ONLY
            (*(volatile uint64_t *)(iv_va+2*PAGESIZE)) = 0x11111111; sync();

            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+2*PAGESIZE),0,
                                   READ_ONLY);

            rc = mm_remove_pages(RELEASE,
                    reinterpret_cast<void*>(iv_va),iv_size);
            if (rc != 0)
            {
                TS_FAIL("Failed to release read pages - rc=%d.\n",rc);
            }
        }

        void testWriteTrackPageFlush()
        {
            rc = mm_set_permission(reinterpret_cast<void*>(iv_va),3*PAGESIZE,WRITABLE|WRITE_TRACKED);
            if (rc != 0)
            {
                TS_FAIL(
                "Failed to set WRITE_TRACKED permissions on first page - rc=%d.\n",rc);
            }

            (*(volatile uint64_t *)iv_va) = 0x12345678; sync();
            (*(volatile uint64_t *)(iv_va+PAGESIZE)) = 0x87654321; sync();
            (*(volatile uint64_t *)(iv_va+2*PAGESIZE)) = 0x22222222; sync();
            uint64_t updPerm = (uint64_t)(READ_ONLY);

            rc = mm_set_permission(reinterpret_cast<void*>((iv_va+2*PAGESIZE)),0,
                                   updPerm);
            if (rc != 0)
            {
                TS_FAIL(
                "Failed to set WRITE_TRACKED permissions on second page - rc=%d.\n",rc);
            }
            rc = mm_remove_pages(FLUSH,
                                 reinterpret_cast<void*>(iv_va),iv_size);
            if (rc != 0)
            {
                TS_FAIL("Failed to flush write tracked pages - rc=%d.\n",rc);
            }
        }

        void testWriteTrackPageRelease()
        {
            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+2*PAGESIZE),0 ,WRITABLE);
            if (rc != 0)
            {
                TS_FAIL(
                "Failed to set WRITE_TRACKED permissions on first page - rc=%d.\n",rc);
            }

            (*(volatile uint64_t *)(iv_va+2*PAGESIZE)) = 0x33333333; sync();
            (*(volatile uint64_t *)iv_va) = 0x12121212; sync();

            uint64_t updPerm = (uint64_t)(READ_ONLY);
            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+2*PAGESIZE),0,updPerm);
            if (rc != 0)
            {
                TS_FAIL(
                "Failed to set WRITE_TRACKED permissions on first page - rc=%d.\n",rc);
            }

            rc = mm_remove_pages(RELEASE,
                    reinterpret_cast<void*>(iv_va),iv_size);
            if (rc != 0)
            {
                TS_FAIL("Failed to release write track pages - rc=%d.\n",rc);
            }
        }

        void testSetPerm()
        {

            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+4*PAGESIZE), 3*PAGESIZE, READ_ONLY);
            if (rc != 0)
            {
                TS_FAIL(" 1   Failed to Update permissions - rc=%d.\n",rc);
            }

            // try to write to a read_only page
            int status;
            printk("\nTest case1: Expect to see uncaught exception! ");
            tid_t child = task_create(writeAddrWithNoPerm, NULL);
            if ((child != task_wait_tid(child, &status, NULL)) ||
                (status != TASK_STATUS_CRASHED))
            {
                TS_FAIL("ERROR! Write to READ_ONLY address not caught - status=%d.",status);
            }

	    rc = mm_set_permission(reinterpret_cast<void*>(iv_va+4*PAGESIZE), 3*PAGESIZE, EXECUTABLE);
            if (rc != 0)
            {
                TS_FAIL("2    Failed to Update permissions - rc=%d.\n",rc);
            }

            // try to write to an executable page
            printk("\nTest case2: Expect to see uncaught exception! ");
            child = task_create(writeAddrWithNoPerm2, NULL);
            if ((child != task_wait_tid(child, &status, NULL)) ||
                (status != TASK_STATUS_CRASHED))
            {
                TS_FAIL("ERROR! Write to EXECUTABLE address not caught - status=%d",status);
            }

            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+4*PAGESIZE), 3*PAGESIZE, NO_ACCESS);
            if (rc != 0)
            {
                TS_FAIL("3   Failed to Update permissions - rc=%d.\n",rc);
            }

            // try to write to a no access page
            printk("\nTest case3: Expect to see uncaught exception! ");
            child = task_create(writeAddrWithNoPerm, NULL);
            if ((child != task_wait_tid(child, &status, NULL)) ||
                (status != TASK_STATUS_CRASHED))
            {
                TS_FAIL("ERROR!  write to a NO_ACCESS addr not caught - status=%d",status);
            }

            // test that you cannot set WRITABLE and EXECUTABLE permissions
            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+4*PAGESIZE), 3*PAGESIZE, WRITABLE|EXECUTABLE);
            if (rc == 0)
            {
                printk("Error .. invalid combination that did not get detected\n");
                TS_FAIL(" ERROR..Failed to detect a bad parm condition - rc=%d.\n",rc);
            }

            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+4*PAGESIZE), 3*PAGESIZE, WRITABLE);
            if (rc != 0)
            {
                TS_FAIL(" 4   Failed to detect a bad parm condition - rc=%d.\n",rc);
            }


           (*(volatile uint64_t *)(iv_va+4*PAGESIZE)) = 0x34343434;


            printkd("\n%lx\n", (*(volatile uint64_t *)(iv_va+4*PAGESIZE)));
            //printkd(" Successfully read from a WRITABLE page\n");

         }

    private:

        static void* testDaemon(void* unused)
        {
            msg_t* message = NULL;
            while (1)
            {
                message = msg_wait(iv_mq);
                if (message)
                {
                    printkd("Effective Addr: 0x%lX, %s\n",message->data[0],
                            message->type==MSG_MM_RP_READ?"READ":"WRITE");
                    message->data[1] = 0;
                    rc = msg_respond(iv_mq, message);
                }
            }
            return NULL;
        }


        static void* writeAddrWithNoPerm(void* unused)
        {
            (*(volatile uint64_t *)(iv_va+4*PAGESIZE)) = 0x11111111; sync();
            return NULL;
        }

        static void* writeAddrWithNoPerm2(void* unused)
        {
            (*(volatile uint64_t *)(iv_va+4*PAGESIZE+2*PAGESIZE)) = 0x22222222; sync();
            return NULL;
        }


};
volatile int vmmpagetest::rc = 0;
msg_q_t vmmpagetest::iv_mq = msg_q_create();
uint64_t vmmpagetest::iv_va = VMM_VADDR_RMVPAGE_TEST;
uint64_t vmmpagetest::iv_size = VMM_SIZE_RMVPAGE_TEST;

#endif
