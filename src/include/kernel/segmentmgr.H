//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/segmentmgr.H $
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
            /** MMIO Space Segment (2-3TB). */
            MMIO_SEGMENT_ID = 2,

            MAX_SEGMENTS = 4
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
         *
         * @return true - Page fault was successfully handled.
         *
         * If the page fault is not successfully handled the expectation is
         * that the VMM will perform appropriate action, such as killing the
         * task.
         */
        static bool handlePageFault(task_t* i_task, uint64_t i_addr);

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


    private:
        /** See handlePageFault. */
        bool _handlePageFault(task_t* i_task, uint64_t i_addr);
        /** See addSegment. */
        void _addSegment(Segment* i_segment, size_t i_segId);
        /** See initSLB. */
        void _initSLB();
            /** See updateRefCount. */
	void _updateRefCount( uint64_t i_vaddr,
			      PageTableManager::UsageStats_t i_stats );

        /** See findPhysicalAddress */
        uint64_t _findPhysicalAddress(uint64_t i_vaddr) const;

        ALWAYS_INLINE inline
        size_t getSegmentIdFromAddress(uint64_t i_addr) const
        {
            return i_addr >> SLBE_s;  
        }

        /** Array of segment objects to associated segment IDs. */
        Segment* iv_segments[MAX_SEGMENTS];
};

#endif
