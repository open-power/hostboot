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

        void testSLB()
        {
            rc = 0;
            printk("Data Segment exception expected in 1TB segment test - ");
            task_create(writeEA1TB, this);
            while (rc == 0) task_yield();
            task_yield();
            if (rc == -1)
            {
                TS_FAIL("Data Segment exception expected in 1TB segment\n");
            }
        }

        void testDevSeg()
        {
            int rc = 0;
            uint64_t ra = 2*1024*1024;
            printk("Map Device @ ra = 0x%lX using mmio_map\n",ra);
            uint64_t* virtAddrMMIO = static_cast<uint64_t*>
                                (mmio_map(reinterpret_cast<void*>(ra), 1));
            if (virtAddrMMIO == NULL)
            {
                TS_FAIL("Failed to map using mmio_map\n");
            }
            printk("Unmap Device @ va = %p using mmio_unmap\n",virtAddrMMIO);
            rc = mmio_unmap(reinterpret_cast<void*>(virtAddrMMIO), 1);
            if (rc != 0)
            {
                TS_FAIL("Failed to unmap using mmio_unmap\n");
            }

            printk("Map Device @ ra = 0x%lX using dev_map\n",ra);
            uint64_t* virtAddrDEV = static_cast<uint64_t*>
                     (mmio_dev_map(reinterpret_cast<void*>(ra), THIRTYTWO_GB));
            if (virtAddrDEV == NULL)
            {
                TS_FAIL("Failed to map using mmio_dev_map\n");
            }
            printk("Unmap Device @ va = %p using dev_unmap\n",virtAddrDEV);
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
            uint64_t size = 0x40000000; //1GB
            printk("Allocate 1GB block with empty msgq @ vaddr = 800GB within base segment\n");
            rc = mm_alloc_block(mq,reinterpret_cast<void*>(va),size);
            if (rc != 0)
            {
                TS_FAIL("Failed to create BaseSegment block\n");
            }
        }

    private:

        static void writeEA1TB(void *i_p)
        {
            rc = 1;
            sync();
            *(int *)0x10000000000 = 1;
            sync();
            rc = -1;
            task_end();
        }
};
volatile int slbtest::rc = 0;

#endif
