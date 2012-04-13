//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/basesegment.H $
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
/** @file basesegment.H
 *  @brief Defines the base segment (0TB) class.
 */
#ifndef __KERNEL_BASESEGMENT_H
#define __KERNEL_BASESEGMENT_H

#include <kernel/segment.H>
//#include <kernel/vmmmgr.H>

// Forward declaration.
class MessageQueue;
class Block;

/** @class BaseSegment
 *  @brief Class to manage the base segment at 0 TB.
 *
 *  Contains a chain of blocks associated with the first segment.
 */
class BaseSegment : public Segment
{
    protected:
        /**
         * @brief Constructor.
         * Initialize attributes and set base addresss of segment to 0 TB.
         */
        BaseSegment() : Segment(0x0), iv_block(NULL), iv_physMemSize(0) {};
        /**
         * @brief Destructor
         * Delete any blocks owned by this segment.
         */
        ~BaseSegment();

    public:
        /**
         * @brief Initialize the segment by allocating initial blocks and
         *        adding to the segment manager.
         */
        static void init();

        /**
         * @brief Implementation of the pure-virtual function from Segment.
         *
         * Calls block chain to deal with page fault.
         */
        virtual bool handlePageFault(task_t* i_task, uint64_t i_addr,
                                     bool i_store);

        /**
         * @brief Implementation of the pure-virtual function from Segment.
         *        Update LRU statistics on the block that owns the address
         *
         * @param[in] i_vaddr - Virtual Address of page
         * @param[in] i_stats - Usage statistics
         */
        virtual void updateRefCount( uint64_t i_vaddr,
				     PageTableManager::UsageStats_t i_stats );

        /**
         * @brief Allocates a block of virtual memory of the given size
         * @param i_mq[in] - Message queue to be associated with the block
         * @param i_va[in] - Page aligned base virtual address of the block
         *                   to be allocated
         * @param i_size[in] - Requested virtual memory size of the block
         * @return int - 0 for successful block allocation, non-zero otherwise
         */
        static int mmAllocBlock(MessageQueue* i_mq,void* i_va,
                                uint64_t i_size);

        /**
         * @brief Locate the physical address of the given virtual address
         * @param[in] i_vaddr virtual address
         * @return the physical address bound to the virtual address, or
         *         -EFAULT if i_vaddr not found. @see errno.h
         */
        virtual uint64_t findPhysicalAddress(uint64_t i_vaddr) const;

        /**
         * @brief Remove pages by a specified operation of the given size
         * @param[in] i_op - Page removal operation to perform
         * @param[in] i_vaddr - Virtual address associated to page(s)
         * @param[in] i_size - Size of memory to perform page removal on
         * @param[in] i_task - Task requesting page removal.
         * @return int - 0 for successful page removal, non-zero otherwise
         */
        static int mmRemovePages(VmmManager::PAGE_REMOVAL_OPS i_op,
                void* i_vaddr, uint64_t i_size, task_t* i_task);

        /**
         * @brief Sets the page permissions for a given virtual address and size.
         * @param i_va[in] - virtual address of the page(s) to set permissions
         * @param i_size[in] - range of memory that needs permissions updated...
         *           if i_size equals 0 then we only need to update an
         *           individual page.
         * @param i_access_type[in] - type of permission to set
         * @return int - 0 for successful block allocation, non-zero otherwise
         */
        static int mmSetPermission(void* i_va,
                                      uint64_t i_size,
                                      uint64_t i_access_type);
         /**
          * @breif Cast out older physical memory pages
          * @param[in] castout Constraint
          */
         virtual void castOutPages(uint64_t i_type);

    private:
        /**
         * @brief Internal implementation of init function.
         */
        void _init();

        /** Block-chain associated with this Segment. */
        Block* iv_block;

        /** Physical memory byte size */
        uint64_t iv_physMemSize;

        /**
         * @brief Allocates a block of virtual memory of the given size
         * @param i_mq[in] - Message queue to be associated with the block
         * @param i_va[in] - Base virtual address of the block to be allocated
         * @param i_size[in] - Requested virtual memory size of the block
         * @return int - 0 for successful block allocation, non-zero otherwise
         */
        int _mmAllocBlock(MessageQueue* i_mq,void* i_va,uint64_t i_size);

        /**
         * @brief Sets the page permissions for a given virtual address and size.
         * @param i_va[in] - virtual address of the page(s) to set permissions
         * @param i_size[in] - range of memory that needs permissions updated...
         *          if i_size equals 0 then we only need to update an individual
         *          page.
         * @param i_access_type[in] - type of permission to set
         * @return int - 0 for successful block allocation, non-zero otherwise
         */
         int _mmSetPermission(void* i_va,
                                 uint64_t i_size,
                                 uint64_t i_access_type);

        /**
         * @brief Remove pages by a specified operation of the given size
         * @param[in] i_op - Page removal operation to perform
         * @param[in] i_vaddr - Virtual address associated to page(s)
         * @param[in] i_size - Size of memory to perform page removal on
         * @param[in] i_task - Task requesting page removal.
         * @return int - 0 for successful page removal, non-zero otherwise
         */
        int _mmRemovePages(VmmManager::PAGE_REMOVAL_OPS i_op, void* i_vaddr,
                uint64_t i_size, task_t* i_task);

};

#endif
