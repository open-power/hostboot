//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/testcore/kernel/slbtest.H $
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
#ifndef __SLBTEST_H
#define __SLBTEST_H
/**
 *  @file slbtest.H
 *
 *  @brief Test cases for the segment lookaside buffers
*/
#include <cxxtest/TestSuite.H>
#include <arch/ppc.H>
#include <sys/time.h>
#include <sys/task.h>
#include <sys/mmio.h>
#include <sys/mm.h>

class slbtest: public CxxTest::TestSuite
{
    public:

        static volatile int rc;

        void testDevSeg()
        {
            int rc = 0;
            uint64_t ra = 2*1024*1024;
            printkd("Map Device @ ra = 0x%lX using mmio_map\n",ra);
            uint64_t* virtAddrMMIO = static_cast<uint64_t*>
                                (mmio_map(reinterpret_cast<void*>(ra), 1));
            if (virtAddrMMIO == NULL)
            {
                TS_FAIL("Failed to map using mmio_map\n");
            }
            printkd("Unmap Device @ va = %p using mmio_unmap\n",virtAddrMMIO);
            rc = mmio_unmap(reinterpret_cast<void*>(virtAddrMMIO), 1);
            if (rc != 0)
            {
                TS_FAIL("Failed to unmap using mmio_unmap\n");
            }

            printkd("Map Device @ ra = 0x%lX using dev_map\n",ra);
            uint64_t* virtAddrDEV = static_cast<uint64_t*>
                     (mmio_dev_map(reinterpret_cast<void*>(ra), THIRTYTWO_GB));
            if (virtAddrDEV == NULL)
            {
                TS_FAIL("Failed to map using mmio_dev_map\n");
            }
            printkd("Unmap Device @ va = %p using dev_unmap\n",virtAddrDEV);
            rc = mmio_dev_unmap(reinterpret_cast<void*>(virtAddrDEV));
            if (rc != 0)
            {
                TS_FAIL("Failed to unmap using mmio_dev_unmap\n");
            }
        }

        void testSegBlock()
        {
            int rc = -1;
            msg_q_t mq = msg_q_create(); //Create empty message queue
            uint64_t va = 0xC800000000; //800GB
            uint64_t size = 0x100000; //1MB
            printkd("Allocate 1MB block with empty msgq @ vaddr = 800GB within base segment\n");
            rc = mm_alloc_block(mq,reinterpret_cast<void*>(va),size);
            if (rc != 0)
            {
                TS_FAIL("Failed to create BaseSegment block\n");
            }
            msg_q_t mq2 = msg_q_create(); //Create empty message queue
            uint64_t va2 = 0xE100000000; //900GB
            uint64_t size2 = 0x100000; //1MB
            printkd("Allocate 1MB block with empty msgq @ vaddr = 900GB within base segment\n");
            rc = mm_alloc_block(mq2,reinterpret_cast<void*>(va2),size2);
            if (rc != 0)
            {
                TS_FAIL("Failed to create BaseSegment block\n");
            }
        }

        void testPageRemoval()
        {
            int rc = -1;
            uint64_t va = 0xC800000000; //800GB
            uint64_t size = 0x100000; //1MB
            rc = mm_remove_pages(FLUSH,reinterpret_cast<void*>(va),size);
            if (rc != 0)
            {
                TS_FAIL("Failed to remove pages\n");
	    }
	}

        void testSetPerm()
        {
            int rc = -1;
            uint64_t va = 0xC800000000; //800GB
            uint64_t size = 0x0;
            PAGE_PERMISSIONS access = WRITABLE; //Access value
            printk("Update Page Permissions. but not real page or address\n");
            rc = mm_set_permission(reinterpret_cast<void*>(va), size, access);
            if (rc != 0)
            {
                TS_FAIL("Failed to Update permissions.\n");
            }
	}

    private:

};
volatile int slbtest::rc = 0;

#endif
