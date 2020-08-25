/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/block.H $                                  */
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
/** @file block.H
 *  @brief Defines the implementation for the generic VMM block class.
 */
#ifndef __KERNEL_BLOCK_H
#define __KERNEL_BLOCK_H

#include <stdint.h>
#include <kernel/task.H>
#include <kernel/vmmmgr.H>
#include <kernel/blockmsghdlr.H>
#include <kernel/msghandler.H>
#include <kernel/ptmgr.H>
#include <sys/mm.h>

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
         * @param[in] i_mappedToPhy - boolean value indicating whether this
         *              block is a mapped to physical block.
         *                         Default: false
         * @param[in] i_spteAddr - address that the SPTE will be created
         *              at if a specific location is required.
         *                         Default: NULL
         *
         * Will allocate enough shadow PTEs to track pages in the block.
         */
        Block(uint64_t i_baseAddr, uint64_t i_size,
              MessageQueue* i_msgQueue = NULL, bool i_mappedToPhy = false,
              uint64_t *i_spteAddr = NULL) : iv_baseAddr(i_baseAddr),
              iv_size(i_size),iv_parent(NULL), iv_nextBlock(NULL),
              iv_ptes(NULL), iv_readMsgHdlr(NULL),iv_writeMsgHdlr(NULL),
              iv_mappedToPhysical(i_mappedToPhy)
            {init(i_msgQueue, i_spteAddr);};


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
         * @param[in] i_store - The fault was due to a store.
         * @param[in] o_oom - Whether the handler encountered an OOM error
         *
         * @return true - Page fault was successfully handled.
         *
         * If the page fault is not successfully handled the expectation is
         * that the VMM will perform appropriate action, such as killing the
         * task.
         *
         * If the address is not within this block, the block will attempt to
         * make calls down the block-chain if it exists.
         *
         * If o_oom is non-null, then if an OOM condition occurs, *o_oom will be
         * set to true, and the function will return. The variable is not set if
         * an OOM does not occur.
         */
        bool handlePageFault(task_t* i_task, uint64_t i_addr, bool i_store,
                             bool* o_oom);

        /**
         * @brief Locate the physical address of the given virtual address
         *
         * @param[in] i_vaddr virtual address
         *
         * @return the physical address bound to the virtual address,
         *         -EFAULT if not found @see errno.h
         */
        uint64_t findPhysicalAddress(uint64_t i_vaddr) const;

        /**
         * @brief Responsible for updating usage counts within the block [chain].
         *
         * @param[in] i_vaddr - Abbreviated Virtual Address of page
         *                      (bottom 23 bits are zero)
         * @param[in] i_stats - Usage statistics
         *
         * If the address is not within this block or a matching page cannot be
         *  found, the block will attempt to make calls down the block-chain
         *  if it exists.
         */
        void updateRefCount( uint64_t i_vaddr,
			     PageTableManager::UsageStats_t i_stats );

        /**
         * Add pointers to the global debug area
         */
        static void addDebugPointers();

        friend class Segment;
        friend class BaseSegment;
        friend class StackSegment;
        friend class BlockReadMsgHdlr;
        friend class BlockWriteMsgHdlr;

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
         *
         * @note If (i_pAddr == 0), then the virtual page is left with
         *       the current present / page-number state but the access
         *       mode is still set.
         */
        void setPhysicalPage(uint64_t i_vAddr, uint64_t i_pAddr,
                               uint64_t i_access);

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

        /**
         * @brief Release all allocated pages back to memory pool and remove
         *        from page table.
         */
        void releaseAllPages();

        /**
         * @brief Sets the page permissions for a given virtual addr
         *          and a size of memory needing updated permissions
         * @param i_va[in] - virtual address of the beginning of the
         *           pages that need updating.
         * @param i_size[in] - range of memory that needs updating
         *          if i_size equals 0 then we only need to update an
         *          individual page.
         * @param i_access_type[in] - type of permission to set using
         *             PAGE_PERMISSION enum values OR'd together
         * @return int - 0 for successful permission update,
         *             non-zero otherwise
         */
        int mmSetPermission(uint64_t i_va, uint64_t i_size, uint64_t i_access_type);


        /**
         * @brief Adds the page table entry for the given address
         *  along with setting the shadow PTE entry to present
         *  and setting the base block heap SPTE page entry
         *  permissions to NO_ACCESS
         *
         * @param[in] i_vaddr - Virtual address to add to the page table
         *
         * The permissions set within the Shadow page table are used for
         * this address
         */
        void attachSPTE(void* i_vaddr);

        /**
         * @brief Effectively removes the given page table entry from the
         * shadow page table
         * @param[in] i_pte - Shadow page table entry to release
         */
        void releaseSPTE(ShadowPTE* i_pte);

        /**
         * @brief Cast out older phyiscal memory pages
         * @param[in] i_type - Castout contraint @see VmmManager::castOutPages()
         */
        void castOutPages(uint64_t i_type);

        /**
         * @brief Evict a memory page
         * @param[in] i_pte shadow page table entry
         * @return true of page was evicted
         */
        bool evictPage(ShadowPTE* i_pte);

        /**
         * @brief Sets the page permissions for a given SPTE
         * @param i_spte[in] - i_pte shadow page table entry
         * @param i_access_type[in] - type of permission to set using
         *             PAGE_PERMISSION enum values OR'd together
         * @return int - 0 for successful update
         *               non-zero otherwise
         */
        int setPermSPTE( ShadowPTE* i_spte, uint64_t i_access_type);

        /**
         * @brief Gets the page permissions for a given SPTE
         * @param i_spte[in] - i_pte shadow page table entry
         * @return uint64_t - type of permission for that SPTE using
         *             PAGE_PERMISSION enum values OR'd together
         */
        uint64_t getPermission( ShadowPTE* i_spte);

        /**
         * @brief Removes a range of pages within a block of virtual memory
         * @param[in] i_op - Page removal operation to perform
         * @param[in] i_vaddr - Virtual address associated to page(s)
         * @param[in] i_size - Size of memory to perform page removal on
         * @param[in] i_task - Task requesting page removal.
         * @return int - 0 for successful page removal, non-zero otherwise
         */
        int removePages(VmmManager::PAGE_REMOVAL_OPS i_op, void* i_vaddr,
                        uint64_t i_size, task_t* i_task);


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
            /** Pointer to message handler(read) */
        BlockReadMsgHdlr* iv_readMsgHdlr;
            /** Pointer to message handler(write) */
        BlockWriteMsgHdlr* iv_writeMsgHdlr;

        static uint32_t cv_ro_evict_req;   //!< memstat ro eviction requests
        static uint32_t cv_rw_evict_req;   //!< memstat rw eviction requests

        bool iv_mappedToPhysical;
        /**
         * @brief Finish initialization of block.
         *
         * @param[in] i_msgQ - The message queue associated with this block
         * @param[in] i_spteAddr - address that the SPTE will be created
         *              at if a specific address is required.
         *              Default: NULL
         *
         * Construct ShadowPTE entries.
         *
         * This is defined as a separate function to reduce the code
         * footprint of the class constructors.  GCC emits an "in-charge" and
         * "not-in-charge" version of each constructor, so put as much
         * common code into an init function.
         */
        void init(MessageQueue* i_msgQ, uint64_t *i_spteAddr);

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
