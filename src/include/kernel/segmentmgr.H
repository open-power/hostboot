/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/segmentmgr.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
/** @file segmentmgr.H
 *  Provides definition of the SegmentManager class.
 */

#ifndef __KERNEL_SEGMENTMGR_H
#define __KERNEL_SEGMENTMGR_H

#include <kernel/task.H>
#include <builtins.h>
#include <kernel/ptmgr.H>
#include <usr/vmmconst.h>

// Forward declaration.
class Segment;

/** @class SegmentManager
 *  @brief Container of Segments.  Responsible for managing the SLB.
 *
 *  @note This class is not thread-safe on its own.  Expectation is that
 *        the virtual memory manager will serialize internal operations.
 */
class SegmentManager
{
    public:
        /** Segment Identifiers */
        enum SegmentIds
        {
            /** Base Segment (0-1TB). */
            BASE_SEGMENT_ID = 0,
            /** Task Stack Segment (1-2TB). */
            STACK_SEGMENT_ID = 1,
            /** MMIO Space Segments (2-11TB). */
            MMIO_FIRST_SEGMENT_ID = 2,
            MMIO_LAST_SEGMENT_ID = MMIO_FIRST_SEGMENT_ID + 8,

            MAX_SEGMENTS = 16
        };

        enum
        {
            CI_ACCESS = 0xFFFFFFFF
            // Set to all F's to identify this type
        };

        /**
         * Constructor.  Initializes instance variables.
         */
        SegmentManager()
            {
                for(int i = 0; i < MAX_SEGMENTS; i++)
                    iv_segments[i] = NULL;
            };
        /**
         * Destructor.
         * No action necessary.  Associated segments are owned externally,
         * such as in Singletons.
         */
        ~SegmentManager() {};

        /**
         * @brief Responsible for directing page faults to the owning segment.
         *
         * @param[in] i_task - Task causing the page fault.
         * @param[in] i_addr - Effective address accessed to cause fault.
         * @param[in] i_store - The page fault was due to a store.
         * @param[out] o_oom - Whether the handler failed due to OOM condition
         *
         * @return true - Page fault was successfully handled.
         *
         * If the page fault is not successfully handled the expectation is
         * that the VMM will perform appropriate action, such as killing the
         * task.
         *
         * If o_oom is non-null, it will be set to true of an OOM occurs. If an
         * OOM does not occur, it will not be altered. If it is null, then an
         * OOM may trigger a kernel assert.
         */
        static bool handlePageFault(task_t* i_task, uint64_t i_addr,
                                    bool i_store, bool* o_oom);

        /**
         * @brief Adds a segment to the container.
         *
         * @param[in] i_segment - Segment object to associate to segment.
         * @param[in] i_segId - Segment identifier (which TB) to associate.
         *
         * @note Ownership of the Segment object (for freeing memory) remains
         *       with the callee.
         */
        static void addSegment(Segment* i_segment, size_t i_segId);

        /**
         * @brief Update SLB on this hardware thread with associated segments.
         */
        static void initSLB();

        /**
         * @brief Find the phyiscal address bound to the given address
         * @param[in] i_vaddr The address
         * @return the physical address or -EFAULT @see errno.h
         */
        static uint64_t findPhysicalAddress(uint64_t i_vaddr);

        /**
         * @brief Update LRU statistics on the block that owns the page
         *
         * @param[in] i_vaddr - Virtual Address of page
         * @param[in] i_stats - Usage statistics
         */
        static void updateRefCount( uint64_t i_vaddr,
				    PageTableManager::UsageStats_t i_stats );

        /**
         * @brief Cast out oldest physical memory pages
         * @param[in] castout type
         */
        static void castOutPages(uint64_t i_type);

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
         * Add pointers to the global debug area
         */
        static void addDebugPointers();


    private:
        /** See handlePageFault. */
        bool _handlePageFault(task_t* i_task, uint64_t i_addr, bool i_store, bool* o_oom);
        /** See addSegment. */
        void _addSegment(Segment* i_segment, size_t i_segId);
        /** See getSegment. */
        Segment* _getSegment(size_t i_segId);
        /** See initSLB. */
        void _initSLB();
            /** See updateRefCount. */
	void _updateRefCount( uint64_t i_vaddr,
			      PageTableManager::UsageStats_t i_stats );
        /** See castOutPages */
        void _castOutPages(uint64_t i_type);

        /** See devMap */
        void* _devMap(
            void* ra, uint64_t i_devDataSize, bool i_nonCI, bool i_guarded);

        /** See devUnmap */
        int _devUnmap(void* ea);


        /** See findPhysicalAddress */
        uint64_t _findPhysicalAddress(uint64_t i_vaddr) const;

        ALWAYS_INLINE
        static size_t getSegmentIdFromAddress(uint64_t i_addr)
        {
            return i_addr >> SLBE_s;
        }

        /** See addDebugPointers */
        void _addDebugPointers();

        /** Array of segment objects to associated segment IDs. */
        Segment* iv_segments[MAX_SEGMENTS];
};

#endif
