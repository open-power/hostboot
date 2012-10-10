/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/kernel/vmmpagetest.H $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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
                TS_FAIL("Unable to allocate block.\n");
            }
            rc = mm_set_permission(reinterpret_cast<void*>(iv_va),iv_size,
                                   initPerm);
            if (rc != 0)
            {
                TS_FAIL("Failed to set block permissions to READ_ONLY.\n");
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
                TS_FAIL("Failed to release read pages\n");
            }
        }

        void testWriteTrackPageFlush()
        {
            rc = mm_set_permission(reinterpret_cast<void*>(iv_va),3*PAGESIZE,WRITABLE|WRITE_TRACKED);
            if (rc != 0)
            {
                TS_FAIL(
                "Failed to set WRITE_TRACKED permissions on first page.\n");
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
                "Failed to set WRITE_TRACKED permissions on second page.\n");
            }
            rc = mm_remove_pages(FLUSH,
                                 reinterpret_cast<void*>(iv_va),iv_size);
            if (rc != 0)
            {
                TS_FAIL("Failed to flush write tracked pages\n");
            }
        }

        void testWriteTrackPageRelease()
        {
            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+2*PAGESIZE),0 ,WRITABLE);
            if (rc != 0)
            {
                TS_FAIL(
                "Failed to set WRITE_TRACKED permissions on first page.\n");
            }

            (*(volatile uint64_t *)(iv_va+2*PAGESIZE)) = 0x33333333; sync();
            (*(volatile uint64_t *)iv_va) = 0x12121212; sync();

            uint64_t updPerm = (uint64_t)(READ_ONLY);
            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+2*PAGESIZE),0,updPerm);
            if (rc != 0)
            {
                TS_FAIL(
                "Failed to set WRITE_TRACKED permissions on first page.\n");
            }

            rc = mm_remove_pages(RELEASE,
                    reinterpret_cast<void*>(iv_va),iv_size);
            if (rc != 0)
            {
                TS_FAIL("Failed to release write track pages\n");
            }
        }

        void testSetPerm()
        {

            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+4*PAGESIZE), 3*PAGESIZE, READ_ONLY);
            if (rc != 0)
            {
                TS_FAIL(" 1   Failed to Update permissions.\n");
            }

            // try to write to a read_only page
            int status;
            printk("\nTest case1: Expect to see uncaught exception! ");
            tid_t child = task_create(writeAddrWithNoPerm, NULL);
            if ((child != task_wait_tid(child, &status, NULL)) ||
                (status != TASK_STATUS_CRASHED))
            {
                TS_FAIL("ERROR! Write to READ_ONLY address not caught.");
            }

	    rc = mm_set_permission(reinterpret_cast<void*>(iv_va+4*PAGESIZE), 3*PAGESIZE, EXECUTABLE);
            if (rc != 0)
            {
                TS_FAIL("2    Failed to Update permissions.\n");
            }

            // try to write to an executable page
            printk("\nTest case2: Expect to see uncaught exception! ");
            child = task_create(writeAddrWithNoPerm2, NULL);
            if ((child != task_wait_tid(child, &status, NULL)) ||
                (status != TASK_STATUS_CRASHED))
            {
                TS_FAIL("ERROR! Write to EXECUTABLE address not caught.");
            }

            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+4*PAGESIZE), 3*PAGESIZE, NO_ACCESS);
            if (rc != 0)
            {
                TS_FAIL("3   Failed to Update permissions.\n");
            }

            // try to write to a no access page
            printk("\nTest case3: Expect to see uncaught exception! ");
            child = task_create(writeAddrWithNoPerm, NULL);
            if ((child != task_wait_tid(child, &status, NULL)) ||
                (status != TASK_STATUS_CRASHED))
            {
                TS_FAIL("ERROR!  write to a NO_ACCESS addr not caught.\n");
            }

            // test that you cannot set WRITABLE and EXECUTABLE permissions
            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+4*PAGESIZE), 3*PAGESIZE, WRITABLE|EXECUTABLE);
            if (rc == 0)
            {
                printk("Error .. invalid combination that did not get detected\n");
                TS_FAIL(" ERROR..Failed to detect a bad parm condition.\n");
            }

            rc = mm_set_permission(reinterpret_cast<void*>(iv_va+4*PAGESIZE), 3*PAGESIZE, WRITABLE);
            if (rc != 0)
            {
                TS_FAIL(" 4   Failed to detect a bad parm condition.\n");
            }


           (*(volatile uint64_t *)(iv_va+4*PAGESIZE)) = 0x34343434;


            printkd("\n%lx\n", (*(volatile uint64_t *)(iv_va+4*PAGESIZE)));
            //printkd(" Successfully read from a WRITABLE page\n");

         }

    private:

        static void* testDaemon(void* unused)
        {
            msg_t* message = NULL;
            uint64_t ea = 0;
            while (1)
            {
                message = msg_wait(iv_mq);
                if (message)
                {
                    ea = message->data[0];
                    printkd("Effective Addr: 0x%lX, %s\n",ea,
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
