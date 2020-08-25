/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/stacksegment.C $                                   */
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

#include <assert.h>
#include <util/singleton.H>

#include <kernel/stacksegment.H>
#include <kernel/segmentmgr.H>
#include <kernel/block.H>
#include <errno.h>
#include <usr/vmmconst.h>

void StackSegment::init()
{
    Singleton<StackSegment>::instance()._init();
}

void* StackSegment::createStack(tid_t i_task)
{
    return Singleton<StackSegment>::instance()._createStack(i_task);
}

void StackSegment::deleteStack(tid_t i_task)
{
    Singleton<StackSegment>::instance()._deleteStack(i_task);
}

StackSegment::~StackSegment()
{
        // Release all blocks and associated pages.
    StackBlockNode* l_node = NULL;
    do
    {
        l_node = iv_blockList.remove();
        if (NULL != l_node)
        {
            l_node->block->releaseAllPages();
            delete l_node->block;
            delete l_node;
        }
    } while (l_node != NULL);
}

bool StackSegment::handlePageFault(task_t* i_task, uint64_t i_addr,
                                   bool i_store, bool* o_oom)
{
    uint64_t l_addr_8mb = i_addr & ~((8*MEGABYTE) - 1);

    StackBlockNode* l_node = iv_blockList.find(l_addr_8mb);

    return (NULL == l_node ?
                false :
                l_node->block->handlePageFault(i_task, i_addr, i_store, o_oom));
}

uint64_t StackSegment::findPhysicalAddress(uint64_t i_vaddr) const
{
    uint64_t l_addr_8mb = i_vaddr & ~((8*MEGABYTE) - 1);

    StackBlockNode* l_node = iv_blockList.find(l_addr_8mb);

    return (NULL == l_node ?
                -EFAULT :
                l_node->block->findPhysicalAddress(i_vaddr));
}

void StackSegment::_init()
{
    // Assign segment to segment manager.
    SegmentManager::addSegment(this, SegmentManager::STACK_SEGMENT_ID);
}

void* StackSegment::_createStack(tid_t i_task)
{
    /* The segment is broken out into 8MB blocks so we need to place the
     * stack somewhere within an 8MB range.  The constraints are ensuring
     * we have adequate protection and that the hashed page table does not
     * have a large number of collisions.  If we were to place all of the
     * stacks at (8MB - 64k) there would be a large amount of contention on
     * the same PTEG in the hashed page table.
     *
     * Design:
     *     - Provide 64k of protection minimum at the top and bottom of the
     *       stack.
     *     - Allow stack sizes up to 256k.
     *     - Expect typical (well performing) stacks of under 128k.
     *
     * Therefore, place stacks at:
     *     Bottom = 64k + 128k * (tid % 61).
     *     Top = Bottom + 256k - 8.
     *
     * This provides a possible range of 64k to (8MB - 64k), giving 64k of
     * protection at each end.  It also cycles the stacks through the 8MB
     * range, and therefore the hashed page table, at 128k blocks.  Finally,
     * it provides for stack sizes up to 256k.
     *
     * Any attempt to grow the stack above 256k can be caught by killing the
     * task (so we can re-write the offending code to not waste so much stack
     * space).
     */

    uint64_t l_addr_8mb = i_task * (8*MEGABYTE) + VMM_VADDR_STACK_SEGMENT;
        // Ensure block doesn't already exist.
    kassert(NULL == iv_blockList.find(l_addr_8mb));

        // Calculate offset bounds of stack.
    uint64_t l_offset_bottom = (64 + 128 * (i_task % 61)) * 1024;
    uint64_t l_offset_top = l_offset_bottom + (256 * 1024) - 8;

    uint64_t l_addr_bottom = l_addr_8mb + l_offset_bottom;
    uint64_t l_addr_top = l_addr_8mb + l_offset_top;

        // Create block.
    Block* l_block = new Block(l_addr_bottom, 256 * 1024);
        // Set pages to be allocate-from-zero.
    for(uint64_t i = l_addr_bottom; i <= l_addr_top; i += PAGE_SIZE)
    {
        l_block->setPhysicalPage(i, 0, WRITABLE | ALLOCATE_FROM_ZERO);
    }

        // Insert block to list.
    StackBlockNode* l_node = new StackBlockNode();
    l_node->key = l_addr_8mb;
    l_node->block = l_block;
    iv_blockList.insert(l_node);

        // Return pointer to top of stack, since stacks grow down.
    return reinterpret_cast<void*>(l_addr_top);
}

void StackSegment::_deleteStack(tid_t i_task)
{
    VmmManager::getLock()->lock();

    uint64_t l_addr_8mb = i_task * (8*MEGABYTE) + VMM_VADDR_STACK_SEGMENT;

    StackBlockNode* l_node = iv_blockList.find(l_addr_8mb);
    kassert(NULL != l_node);
    iv_blockList.erase(l_node);

    l_node->block->releaseAllPages();
    delete l_node->block;
    delete l_node;

    VmmManager::getLock()->unlock();

    return;
}
