//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/testcore/kernel/vmmbasetest.H $
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
#include <targeting/targetservice.H>

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

        void testCastOutPages()
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
            TARGETING::EntityPath syspath(TARGETING::EntityPath::PATH_PHYSICAL);
            syspath.addLast(TARGETING::TYPE_SYS,0);
            TARGETING::Target* sys = TARGETING::targetService().toTarget(syspath);
            uint8_t vpo_mode = 0;
            if( sys
                && sys->tryGetAttr<TARGETING::ATTR_IS_SIMULATION>(vpo_mode)
                && (vpo_mode == 0) )
            {
                nanosleep(1,0);
            }
        }

    private:

        static void readFromNULL(void* unused)
        {
            printk("%lx", (*(uint64_t*)NULL));
            task_end();
        }

        static void writeToNULL(void* unused)
        {
            (*(uint64_t*)NULL) = 0x12345678;
            task_end();
        }

        static void writeToKernelCode(void* unused)
        {
            (*(*(uint64_t**)&printk)) = 0x12345678;
            task_end();
        }

        static void msgDaemon(void* unused)
        {
            msg_t* message = NULL;
            uint64_t ea = 0;
            while (1)
            {
                message = msg_wait(iv_mq);
                if (message)
                {
                    ea = message->data[0];
                    /*printkd("Effective Addr: 0x%lX, %s\n",ea,
                            message->type==MSG_MM_RP_READ?"READ":"WRITE");*/
                    message->data[1] = 0;
                    msg_respond(iv_mq, message);
                }
            }
        }

};
msg_q_t VmmBaseTest::iv_mq = msg_q_create();

#endif
