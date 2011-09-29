//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/testcore/kernel/vmmpagetest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
            //Dependent on block being initialized to READ_ONLY
            (*(volatile uint64_t *)(iv_va+2*PAGESIZE)) = 0x11111111; sync();
            rc = mm_remove_pages(RELEASE,
                    reinterpret_cast<void*>(iv_va),iv_size);
            if (rc != 0)
            {
                TS_FAIL("Failed to release read pages\n");
            }
        }

        void testWriteTrackPageFlush()
        {
            (*(volatile uint64_t *)iv_va) = 0x12345678; sync();
            (*(volatile uint64_t *)(iv_va+PAGESIZE)) = 0x87654321; sync();
            (*(volatile uint64_t *)(iv_va+2*PAGESIZE)) = 0x22222222; sync();
            uint64_t updPerm = (uint64_t)(WRITE_TRACKED);
            rc = mm_set_permission(reinterpret_cast<void*>(iv_va),0,updPerm);
            if (rc != 0)
            {
                TS_FAIL(
                "Failed to set WRITE_TRACKED permissions on first page.\n");
            }
            rc = mm_set_permission(reinterpret_cast<void*>((iv_va+PAGESIZE)),0,
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
            (*(volatile uint64_t *)(iv_va+2*PAGESIZE)) = 0x33333333; sync();
            (*(volatile uint64_t *)iv_va) = 0x12121212; sync();
            rc = mm_remove_pages(RELEASE,
                    reinterpret_cast<void*>(iv_va),iv_size);
            if (rc != 0)
            {
                TS_FAIL("Failed to release write track pages\n");
            }
        }

        void testSetPerm()
        {
            int rc = 1;
            uint64_t va = 0xC800000000; //800GB
            uint64_t size = 0x0;
            uint64_t access = (uint64_t)(WRITABLE | ALLOCATE_FROM_ZERO); //Access value
            printkd("Update Page Permissions. Writable/Allocate from zero to addr 800Gb and size = 0 \n");
            rc = mm_set_permission(reinterpret_cast<void*>(va), size, access);
            if (rc != 0)
            {
                TS_FAIL(" 1   Failed to Update permissions.\n");
            }

            rc = 1;
            size = PAGESIZE * 3;
            access = (uint64_t)(WRITE_TRACKED); //Access value
            printkd("Update Page Permissions. write_tracked to addr 800Gb and size = 3 pages\n");
            rc = mm_set_permission(reinterpret_cast<void*>(va), size, access);
            if (rc != 0)
            {
                TS_FAIL("2    Failed to Update permissions.\n");
            }
            rc = 1;
            va = 0xC800000000 + (PAGESIZE * 10);
            size = PAGESIZE * 2;
            access = (uint64_t)(EXECUTABLE); //Access value
            printkd("Update Page Permissions. executable to addr C800A000 and size = 2 pages\n");
            rc = mm_set_permission(reinterpret_cast<void*>(va), size, access);
            if (rc != 0)
            {
                TS_FAIL("3   Failed to Update permissions.\n");
            }
            rc = 0;
            va = 0xC800000000; //800GB
            size = 0x0;
            access = (uint64_t)(WRITABLE | EXECUTABLE); //Access value
            printkd("Update Page Permissions. Writable/executable to addr 800Gb and size = 0 \n");
            rc = mm_set_permission(reinterpret_cast<void*>(va), size, access);
            if (rc == 0)
            {
                printk("Error .. invalid combination that did not get detected\n");
                TS_FAIL(" 4   Failed to detect a bad parm condition.\n");
            }
        }

    private:

        static void testDaemon(void* unused)
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
        }

};
volatile int vmmpagetest::rc = 0;
msg_q_t vmmpagetest::iv_mq = msg_q_create();
uint64_t vmmpagetest::iv_va = VMM_VADDR_RMVPAGE_TEST;
uint64_t vmmpagetest::iv_size = VMM_SIZE_RMVPAGE_TEST;

#endif
