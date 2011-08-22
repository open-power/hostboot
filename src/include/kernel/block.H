//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/block.H $
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
/** @file block.H
 *  @brief Defines the implementation for the generic VMM block class.
 */
#ifndef __KERNEL_BLOCK_H
#define __KERNEL_BLOCK_H

#include <stdint.h>
#include <kernel/task.H>
#include <kernel/vmmmgr.H>
#include <kernel/blockmsghdlr.H>

class ShadowPTE;
class Segment;
class MessageQueue;

/** @class Block
 *  @brief Provides management of the memory pages associated with a block of
 *         virtual memory.
 *
 *  This class is organized to be either an independent block (typically
 *  managed by the Segment container in some way) or as a chain of blocks.
 *
 *  When the instance is assigned down-stream blocks, the instance will
 *  forward requests that do not belong to it down the chain for handling
 *  by a block responsible for the request.  Also, when used in this manner,
 *  this block is responsible for the ownership of all down-stream blocks,
 *  including calling their destructor when necessary.
 *
 *  There is currently no mechanism for dynamically removing blocks from the
 *  chain.  The expectation is that all known use cases would suggest either
 *  a fixed (increasing-only) chain or a known-sized array of blocks.
 */
class Block
{
    public:
        /**
         * @brief Constructor.
         *
         * @param[in] i_baseAddr - Base virtual Address of the block.
         * @param[in] i_size - Size of the block (in bytes).
         * @param[in] i_msgQueue - Message queue passed along to the handler
         *                         Default: NULL
         *
         * Will allocate enough shadow PTEs to track pages in the block.
         */
        Block(uint64_t i_baseAddr, uint64_t i_size,
              MessageQueue* i_msgQueue = NULL) :
                iv_baseAddr(i_baseAddr), iv_size(i_size),
                iv_parent(NULL), iv_nextBlock(NULL), iv_ptes(NULL),
                iv_msgHdlr(NULL)
            { init(i_msgQueue); };

        /**
         * @brief Destructor.
         *
         * Releases associated memory and down-stream blocks.
         */
        ~Block();

        /**
         * @brief Get the base address of this block.
         * @return Base address (as uint64_t).
         */
        uint64_t getBaseAddress() const { return iv_baseAddr; };

        /**
         * @brief Determines if a virtual address is in the range of the block.
         *
         * @param[in] i_addr - The virtual address in question.
         * @return true - Address is contained within the block.
         * @return false - Address is not contained within the block.
         */
        bool isContained(uint64_t i_addr) const
                { return (i_addr >= iv_baseAddr) &&
                         (i_addr < iv_baseAddr + iv_size); };

        /**
         * @brief Responsible for handling page faults within the block [chain].
         *
         * @param[in] i_task - Task causing the page fault.
         * @param[in] i_addr - Effective address accessed to cause fault.
         *
         * @return true - Page fault was successfully handled.
         *
         * If the page fault is not successfully handled the expectation is
         * that the VMM will perform appropriate action, such as killing the
         * task.
         *
         * If the address is not within this block, the block will attempt to
         * make calls down the block-chain if it exists.
         */
        bool handlePageFault(task_t* i_task, uint64_t i_addr);

        /**
         * @brief Sets the 'present' bit within the Shadow page table
         *
         * @param[in] i_vaddr - Virtual address within the Shadow page table
         */
        void setIsPresent(void* i_vaddr);

        /**
         * @brief Adds the page table entry for the given address
         *
         * @param[in] i_vaddr - Virtual address to add to the page table
         *
         * The permissions set within the Shadow page table are used for
         * this address
         */
        void addPTE(void* i_vaddr);

        /**
         * @brief Locate the physical address of the given virtual address
         *
         * @param[in] i_vaddr virtual address
         *
         * @return the physical address bound to the virtual address, 
         *         -EFAULT if not found @see errno.h
         */
        uint64_t findPhysicalAddress(uint64_t i_vaddr) const;

        friend class Segment;
        friend class BaseSegment;
        friend class StackSegment;

    protected:
        /**
         * @brief Assign a segment to a parent relationship to this block.
         *
         * @param[in] i_parent - The segment to assign as a parent.
         */
        void setParent(Segment* i_parent) { iv_parent = i_parent; };

        /**
         * @brief Add a block to the end of this block-chain.
         *
         * @param[in] i_block - The block tp append.
         */
        void appendBlock(Block* i_block)
                {
                    if (NULL == iv_nextBlock) iv_nextBlock = i_block;
                    else iv_nextBlock->appendBlock(i_block);
                }

        /**
         * @brief Set up a virtual-physical mapping for a static page.
         *
         * @param[in] i_vAddr - The virtual address of the page.
         * @param[in] i_pAddr - The physical address of the page.
         * @param[in] i_access - The permissions of the page.
         */
        void setPhysicalPage(uint64_t i_vAddr, uint64_t i_pAddr,
                             VmmManager::ACCESS_TYPES i_access);

        /**
         * @brief Adds up the total size of all blocks within the segment
         *
         * @param[in/out] io_totalSize - total size allocated within segment
         */
        void totalBlocksAlloc(uint64_t &io_totalSize)
        {
            io_totalSize=io_totalSize+this->iv_size;
            if (iv_nextBlock == NULL) return;
            else iv_nextBlock->totalBlocksAlloc(io_totalSize);
        }

    private:
            /** Base address of the block */
        const uint64_t iv_baseAddr;
            /** Size of the block */
        const uint64_t iv_size;

            /** Pointer to the parent (containing) segment. */
        Segment* iv_parent;
            /** Pointer to the next block in the chain. */
        Block* iv_nextBlock;

            /** Pointer to the Shadow PTE entries. */
        ShadowPTE* iv_ptes;
            /** Pointer to the message handler */
        BlockMsgHdlr* iv_msgHdlr;

        /**
         * @brief Finish initialization of block.
         *
         * @param[in] i_msgQ - The message queue associated with this block
         *
         * Construct ShadowPTE entries.
         *
         * This is defined as a separate function to reduce the code
         * footprint of the class constructors.  GCC emits an "in-charge" and
         * "not-in-charge" version of each constructor, so put as much
         * common code into an init function.
         */
        void init(MessageQueue* i_msgQ);

        /**
         * @brief Find the Shadow PTE for a virtual address.
         *
         * @param[in] i_addr - The virtual address to find a page for.
         * @note This function does no bounds checking.
         */
        ShadowPTE* getPTE(uint64_t i_addr) const;


        Block(const Block&);  // prohibit copy.
        Block& operator=(const Block&);  // prohibit assignment.

};

#endif
