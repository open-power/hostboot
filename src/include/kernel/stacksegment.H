//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/stacksegment.H $
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

/** @file stacksegment.H
 *  @brief Defines the stack segment (1TB) class.
 */
#ifndef __KERNEL_STACKSEGMENT_H
#define __KERNEL_STACKSEGMENT_H

#include <kernel/types.h>
#include <kernel/segment.H>
#include <util/locked/list.H>

// Forward declaration.
class Block;

/** @struct StackBlockNode
 *  @brief Node structure for storing blocks onto a Util::Locked::List.
 */
struct StackBlockNode
{
        /** Next pointer for list. */
    StackBlockNode* next;
        /** Previous pointer for list. */
    StackBlockNode* prev;

        /** Key value (8mb adjusted address for stack). */
    uint64_t key;
        /** Pointer to block representing the stack. */
    Block* block;
};


/** @class StackSegment
 *  @brief Class to manage the stack segment at 1 TB.
 *
 *  Contains a list of blocks, one for each task, associated with the segment
 *  representing the stacks.
 */
class StackSegment : public Segment
{
    protected:
        enum
        {
            EIGHT_MEGABYTE = 8 * 1024 * 1024ul,
            ONE_TERABYTE = 1024 * 1024 * 1024 * 1024ul,
        };


        /**
         * @brief Constructor.
         * Initialize attributes and set base addresss of segment to 1 TB.
         */
        StackSegment() : Segment(ONE_TERABYTE) {};

        /**
         * @brief Destructor
         * Delete any blocks owned by this segment.
         */
        ~StackSegment();

    public:
        /**
         * @brief Initialize the segment by adding to the segment manager.
         */
        static void init();

        /**
         * @brief Implementation of the pure-virtual function from Segment.
         *
         * Calls block chain to deal with page fault.
         */
        bool handlePageFault(task_t* i_task, uint64_t i_addr);

        /**
         * @brief Locate the physical address of the given virtual address
         * @param[in] i_vaddr virtual address
         * @return the physical address bound to the virtual address, or
         *         -EFAULT if i_vaddr not found. @see errno.h
         */
        uint64_t findPhysicalAddress(uint64_t i_vaddr) const;

        /**
         * @brief Create a new stack for a task.
         *
         * @param i_task - Task ID of task to own the stack.
         *
         * @return Upper address of the newly created stack.
         */
        static void* createStack(tid_t i_task);

        /**
         * @brief Delete previously created stack for a task.
         *
         * @param i_task - Task ID of task owning the stack.
         */
        static void deleteStack(tid_t i_task);

    private:
        /** @brief Mapping of virtual address ranges to blocks representing
         *         stacks.
         *
         *  The blocks are created such that the 1TB range of this segment is
         *  divided into 8MB chunks, such that (tid*8MB + 1TB) = bottom of
         *  the stack address range.  The stack is then arranged somewhere
         *  within that range to provide protection above and below the stack
         *  and to efficiently utilize the hashed page table.
         *
         *  This list is therefore indexed by the low address of the
         *  range (tid*8MB + 1TB).
         */
        Util::Locked::List<StackBlockNode, uint64_t> iv_blockList;

            /** Internal implementation of init function. */
        void _init();
            /** Internal implementation of createStack function. */
        void* _createStack(tid_t i_task);
            /** Internal implementation of deleteStack function. */
        void _deleteStack(tid_t i_task);

        StackSegment(const StackSegment&);  // prohibit copy.
        StackSegment& operator=(const StackSegment&);  // prohibit assignment.
};

#endif
