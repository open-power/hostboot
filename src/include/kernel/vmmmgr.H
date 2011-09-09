//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/vmmmgr.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
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
#ifndef __KERNEL_VMMMGR_H
#define __KERNEL_VMMMGR_H

#include <limits.h>
#include <sys/mmio.h>
#include <sys/mm.h>
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

        /**
         * @brief Find the phyiscal address bound to the given address
         * @param[in] i_vaddr The address
         * @return the physical address or -EFAULT @see errno.h
         */
        static uint64_t findPhysicalAddress(uint64_t i_vaddr);
        
        /**
         * @brief Remove pages by a specified operation of the given size
         * @param[in] i_op - Page removal operation to perform
         * @param[in] i_vaddr - Virtual address associated to page(s)
         * @param[in] i_size - Size of memory to perform page removal on
         * @return int - 0 for successful page removal, non-zero otherwise
         *
         * The given virtual address will be 'rounded' down to the nearest page
         * boundary, along with the given size will be 'rounded' up to the
         * nearest divisible page size.
         */
        static int mmRemovePages(PAGE_REMOVAL_OPS i_op, void* i_vaddr,
                                 uint64_t i_size);

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

        /** See findPhysicalAddress */
        uint64_t _findPhysicalAddress(uint64_t i_vaddr);

    public:
        friend class Block;

};

#endif
