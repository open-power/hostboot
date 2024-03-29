/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/vmmmgr.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2019                        */
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
            SINGLE_CACHE_SIZE_BYTES = 4*MEGABYTE,

            // Place the page table at the top side of the cache, 256k in size.
            PTSIZE = 256*KILOBYTE,
            PT_ALIGNMENT = 256*KILOBYTE,

            // Put the DMA Pages just after the Page Table
            MBOX_DMA_PAGES = 64,    // must be <= 64
            MBOX_DMA_PAGESIZE = (1 * KILOBYTE),
            MBOX_DMA_SIZE = MBOX_DMA_PAGES * MBOX_DMA_PAGESIZE,

            // Tells processor to ignore HRMOR
            FORCE_PHYS_ADDR = 0x8000000000000000,
        };

        enum castout_t
        {
            NORMAL,
            CRITICAL,
        };

        /**
         * Kernel mapped page removal operations
         *
         * RELEASE : Writes dirty&write-tracked pages out to a storage device
         *           and removes other pages
         * FLUSH   : Only writes dirty&write-tracked pages out to a storage
         *           device
         * EVICT   : (Kernel) Writes dirty&write-tracked pages out to a storage
         *           device and removes other pages
         */
        enum PAGE_REMOVAL_OPS
        {
            RELEASE = 0,
            FLUSH = 1,
            EVICT = 2,
        };

        static void init();
        static void init_slb();

        /**
         * @brief Responsible for handling PTE misses.
         *
         * @param[in] t - Task causing the page fault.
         * @param[in] effAddr - Effective address accessed to cause fault.
         * @param[in] store - The PTE miss was due to a store.
         *
         * @return true - PTE miss was successfully handled.
         *
         * If the PTE miss is not successfully handled, the exception
         * handler should collect debug information and kill the task.
         */
        static bool pteMiss(task_t* t, uint64_t effAddr, bool store);

        /**
         * @brief Map a device into the device segment
         * @param ra[in] - Void pointer to real address to be mapped in
         * @param i_devDataSize[in] - Size of device segment block
         * @param i_nonCI[in] - Device should be mapped cacheable instead of CI
         * @param i_guarded[in] - Whether to prevent out-of-order acces to
         *     instructions or data in the segment.  Ignored if CI.
         * @return void* - Pointer to beginning virtual address, NULL otherwise
         */
        static void* devMap(void* ra, uint64_t i_devDataSize, bool i_nonCI,
            bool i_guarded);

        /**
         * @brief Unmap a device from the device segment
         * @param ea[in] - Void pointer to effective address
         * @return int - 0 for successful unmap, non-zero otherwise
         */
        static int devUnmap(void* ea);

        /**
         * @brief Allocates a block of virtual memory of the given size
         * @param i_mq[in] - Message queue to be associated with the block
         * @param i_va[in] - Page aligned base virtual address of the block
         *                   to be allocated
         * @param i_size[in] - Requested virtual memory size of the block
         * @return int - 0 for successful block allocation, non-zero otherwise
         */
        static int mmAllocBlock(MessageQueue* i_mq,void* i_va,uint64_t i_size);

        /**
         * @brief Find the physical address bound to the given address
         * @param[in] i_vaddr The address
         * @return the physical address or -EFAULT @see errno.h
         */
        static uint64_t findPhysicalAddress(uint64_t i_vaddr);

        /**
         * @brief Cast out older physical memory pages
         * @param[in] castout constraint
         */
        static void castOutPages(castout_t i_ct);

        /**
         * @brief Flush pagetable, Update shadow page info
         */
        static void flushPageTable( void);

        /**
         * @brief Remove pages by a specified operation of the given size
         * @param[in] i_op - Page removal operation to perform
         * @param[in] i_vaddr - Virtual address associated to page(s)
         * @param[in] i_size - Size of memory to perform page removal on
         * @param[in] i_task - OPTIONAL:Task requesting page removal.
         * @return int - 0 for successful page removal, non-zero otherwise
         *
         * The given virtual address will be 'rounded' down to the nearest page
         * boundary, along with the given size will be 'rounded' up to the
         * nearest divisible page size.
         *
         * When a task is given, it will be deferred until all pages requested
         * for removal have completed.
         */
        static int mmRemovePages(VmmManager::PAGE_REMOVAL_OPS i_op,
                                 void* i_vaddr, uint64_t i_size,
                                 task_t* i_task = NULL);
        /**
         * @brief Sets the permissions for a given page or range of pages
         * @param i_va[in] - Virtual address of the page to update permission
         * @param i_size[in] - range of memory that needs permissions updated...
         *             if i_size equals 0 then we only need to update an
         *            individual page.
         * @return int - 0 for successful permission update, non-zero otherwise
         *
         * The given virtual address will be 'rounded' down to the nearest page
         * boundary, along with the given size will be 'rounded' up to the
         * nearest divisible page size.
         */
        static int mmSetPermission(void* i_va,uint64_t i_size, uint64_t i_access_type);

        /**
         * @brief Retrieve the current HTABORG value
         * @return uint64_t - value of HTABORG
         */
        static uint64_t HTABORG();

        /**
         * @brief Find the kernel addressable address bound to the
         *     given virtual address
         * @param[in] i_vaddr The address
         * @return the kernel address or -EFAULT @see errno.h
         */
        static uint64_t findKernelAddress(uint64_t i_vaddr);

        /**
         * @brief Allocates a block of virtual memory that extends the VMM
         *          snto Mainstore (up to VMM_MEMORY_SIZE).
         */
        static int mmExtend( void);

        /** @fn mm_linear_map()
         *  @brief   Allocates a block of memory of the given size
         *           to at a specified address (direct pa to va  mapping)
         *  @param[in] i_paddr - physical address of the location for the block
         *  @param[in] i_size - size of the block requested
         *
         *  @return int - 0 for successful add, non-zero otherwise
         */
         static int mmLinearMap(void *i_paddr, uint64_t i_size);

        /** @fn pageTableOffset()
         *  @brief   Gets starting address of Page Table
         *
         *  @return uint64_t - starting address of Page Table
         */
        static uint64_t pageTableOffset();

        /** @fn BlToHbPreserveDataOffset()
         *  @brief   Gets starting address of BltoHB preserved data area
         *
         *  @return uint64_t - starting address of VMM area
         */
        static uint64_t BlToHbPreserveDataOffset();

        /** @fn endPreservedOffset()
         *  @brief   Gets ending address of preserved data area
         *
         *  @return uint64_t - ending address of VMM preserved area
         */
        static uint64_t endPreservedOffset();

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

        // Partition Table
        // 64K-aligned, each entry is 2 double words
        // We only need one entry in the table
        // So just use a 64K-aligned variable
        static uint64_t g_patb[2] __attribute__ ((aligned (65536)));

        Spinlock lock;

        void initPTEs();
        void initPartitionTable();
        void initSDR1();

        bool _pteMiss(task_t*, uint64_t, bool);

        /** See findPhysicalAddress */
        uint64_t _findPhysicalAddress(uint64_t i_vaddr);

        /** See mmSetPermission */
        int _mmSetPermission(void* i_va,uint64_t i_size, uint64_t i_access_type);

        /** See castOutPages */
        void _castOutPages(castout_t i_ct);

        /** See flushPageTable */
        void _flushPageTable( void );

        /** See mmAllocBlock */
        int _mmAllocBlock(MessageQueue* i_mq,void* i_va,uint64_t i_size);

        /** See mmRemovePages */
        int _mmRemovePages(VmmManager::PAGE_REMOVAL_OPS i_op,void* i_vaddr,
                           uint64_t i_size,task_t* i_task);

        /** See mmExtend */
        int _mmExtend( void );

        /** See devMap */
        void* _devMap(
            void* ra, uint64_t i_devDataSize, bool i_nonCI, bool i_guarded);

        /** See devUnmap */
        int _devUnmap(void* ea);

        /** See mmLinearMap */
        int _mmLinearMap(void*, uint64_t);

        /** See pageTableOffset */
        uint64_t _pageTableOffset() const;

        /** See BlToHbPreserveDataOffset */
        uint64_t _BlToHbPreserveDataOffset() const;

        /** See endPreservedOffset */
        uint64_t _endPreservedOffset() const;

    public:
        friend class Block;
        friend class StackSegment;
        friend class MessageHandler;

};

#endif
