#ifndef __KERNEL_VMMMGR_H
#define __KERNEL_VMMMGR_H

#include <limits.h>
#include <sys/mmio.h>
#include <kernel/types.h>
#include <kernel/spinlock.H>

class MessageQueue;

class VmmManager
{
    public:
        /**
         * Constants used throughout the virtual memory management classes
         */
        enum VMM_CONSTS
        {
            ONE_MEG = 1 * 1024 * 1024,
            FOUR_MEG = 4 * ONE_MEG,
            EIGHT_MEG = 8 * ONE_MEG,

            FULL_MEM_SIZE = FOUR_MEG,

            // put the Page Table at the end of our memory space
            PTSIZE = (1 << 18),
            HTABORG = (FULL_MEM_SIZE - PTSIZE),
        };

        enum ACCESS_TYPES
        {
            NO_USER_ACCESS,
            READ_O_ACCESS,
            NORMAL_ACCESS,
            CI_ACCESS,
            RO_EXE_ACCESS,
        };

        static void init();
        static void init_slb();

        /**
         * @brief Responsible for handling PTE misses.
         *
         * @param[in] t - Task causing the page fault.
         * @param[in] effAddr - Effective address accessed to cause fault.
         *
         * @return true - PTE miss was successfully handled.
         *
         * If the PTE miss is not successfully handled, the exception
         * handler should collect debug information and kill the task.
         */
        static bool pteMiss(task_t* t, uint64_t effAddr);

        static void* mmioMap(void*, size_t);
        static int mmioUnmap(void*, size_t);

        /**
         * @brief Map a device into the device segment(2TB)
         * @param ra[in] - Void pointer to real address to be mapped in
         * @param i_devDataSize[in] - Size of device segment block
         * @return void* - Pointer to beginning virtual address, NULL otherwise
         */
        static void* devMap(void* ra, SEG_DATA_SIZES i_devDataSize);

        /**
         * @brief Unmap a device from the device segment(2TB)
         * @param ea[in] - Void pointer to effective address
         * @return int - 0 for successful unmap, non-zero otherwise
         */
        static int devUnmap(void* ea);

        /**
         * @brief Allocates a block of virtual memory of the given size
         * @param i_mq[in] - Message queue to be associated with the block
         * @param i_va[in] - Base virtual address of the block to be allocated
         * @param i_size[in] - Requested virtual memory size of the block
         * @return int - 0 for successful block allocation, non-zero otherwise
         */
        static int mmAllocBlock(MessageQueue* i_mq,void* i_va,uint64_t i_size);


    protected:
        VmmManager();
        ~VmmManager() {};

        /** @brief Get spinlock for memory subsystem.
         *  This is useful for passing to a deferred user-space message
         *  handler so that the subsystem code is SMP-safe when the message
         *  response is obtained.
         */
        static Spinlock* getLock();

    private:
        Spinlock lock;

        void initPTEs();
        void initSDR1();

        bool _pteMiss(task_t*, uint64_t);

    public:
        friend class Block;

};

#endif
