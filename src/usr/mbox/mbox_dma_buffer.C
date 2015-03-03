/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/mbox_dma_buffer.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
#include "mbox_dma_buffer.H"
#include <stdlib.h>
#include <assert.h>
#include <util/align.H>
#include <trace/interface.H>
#include <kernel/pagemgr.H>
#include <kernel/misc.H>
#include <targeting/common/targetservice.H>

#define ALIGN_DMAPAGE(u) (((u) + (VmmManager::MBOX_DMA_PAGESIZE-1)) & \
                          ~(VmmManager::MBOX_DMA_PAGESIZE-1))

using namespace MBOX;

// Defined in mboxdd.C
extern trace_desc_t * g_trac_mbox;

DmaBuffer::DmaBuffer() :
    iv_head(NULL),
    iv_dir(makeMask(VmmManager::MBOX_DMA_PAGES)),
    iv_dma_req_sent(false)
{
    iv_head = reinterpret_cast<void*>(VmmManager::MBOX_DMA_ADDR);
    initPhysicalArea(iv_head, iv_phys_head);
}


DmaBuffer::~DmaBuffer()
{
}

void DmaBuffer::release(void * i_buffer, size_t i_size)
{
    if(!i_buffer)
    {
        return;
    }

    // Make sure this buffer falls inside the DMA space
    // If not then it's not a DMA buffer - exit.
    if(i_buffer < iv_head ||
       i_buffer >= (static_cast<uint8_t*>(iv_head) +
                    (VmmManager::MBOX_DMA_PAGES *
                     VmmManager::MBOX_DMA_PAGESIZE)))
    {
        TRACDCOMP(g_trac_mbox,
                  ERR_MRK"MBOX DMA buffer address %p out of range",
                  i_buffer
                  );
        return;
    }

    // Calculate the # of chunks
    size_t chunks = ALIGN_DMAPAGE(i_size)/VmmManager::MBOX_DMA_PAGESIZE;

    uint64_t offset =
        (static_cast<uint8_t *>(i_buffer) - static_cast<uint8_t *>(iv_head)) /
        VmmManager::MBOX_DMA_PAGESIZE;

    // makeMask will assert if chunks > total possible # of chunks in the dir
    uint64_t mask = makeMask(chunks);

    mask >>= offset;

    iv_dir |= mask;
    TRACDCOMP(g_trac_mbox,"MBOX DMA free dir: %016lx",iv_dir);
}


void DmaBuffer::addBuffers(uint64_t i_map)
{
    iv_dir |= i_map;
    TRACDCOMP(g_trac_mbox,"MBOXDMA addBuffers. dir: %016lx",iv_dir);
}


void * DmaBuffer::getBuffer(uint64_t & io_size)
{
    // Note: Due to this check, makeMask() will never assert while trying to
    // make a mask for the requested size. Instead, getBuffer will just return
    // NULL if the requested size is larger than the total possible DMA buffer
    // space.
    if(io_size == 0 ||
       io_size > (VmmManager::MBOX_DMA_PAGES * VmmManager::MBOX_DMA_PAGESIZE))
    {
        io_size = 0;
        return NULL;
    }

    void * r_addr = NULL;

    size_t chunks = ALIGN_DMAPAGE(io_size)/VmmManager::MBOX_DMA_PAGESIZE;
    size_t start_page = 0;
    size_t shift_count = (MAX_MASK_SIZE + 1) - chunks;
    uint64_t mask = makeMask(chunks);

    io_size = 0;

    // look for a contiguous block of DMA space.
    // If shift_count goes to zero, the request could not be granted.
    while(shift_count)
    {
        if((mask & iv_dir) == mask)
        {
            break;
        }
        mask >>= 1;
        ++start_page;
        --shift_count;
    }

    if(shift_count)
    {
        iv_dir &= ~mask;
        io_size = mask;
        uint64_t offset = start_page * VmmManager::MBOX_DMA_PAGESIZE;
        r_addr = static_cast<void*>(static_cast<uint8_t*>(iv_head) + offset);
    }
    TRACDCOMP(g_trac_mbox,"MBOX DMA allocate dir: %016lx",iv_dir);

    return r_addr;
}

uint64_t DmaBuffer::makeMask(uint64_t i_size)
{
    assert(i_size <= MAX_MASK_SIZE);
    uint64_t mask = 0;

    // For some reason (1ul << 64) returns 1, not zero
    // The math function pow() converts things to float then back again - bad
    if(i_size < MAX_MASK_SIZE)
    {
        mask = 1ul << i_size;
    }
    mask -= 1;

    mask <<= MAX_MASK_SIZE - i_size;

    return mask;
}

void DmaBuffer::initPhysicalArea(void*& io_addr, uint64_t& o_phys)
{
    // Get the original physical address (includes HRMOR).
    o_phys = mm_virt_to_phys(io_addr);

    // Remove original address from VMM maps.
    mm_set_permission(io_addr, VmmManager::MBOX_DMA_SIZE, NO_ACCESS);

    // Find the amount of the node offset.
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != NULL);
    uint64_t hrmor_base =
        sys->getAttr<TARGETING::ATTR_HB_HRMOR_NODAL_BASE>();

    // Move the physical address to the start of the node (unsecure) and
    // add on the DMA buffer offset inside the node.
    o_phys &= ~(hrmor_base-1);
    o_phys += reinterpret_cast<uint64_t>(io_addr) +
              VMM_UNSECURE_RESERVED_MEMORY_BASEADDR;

    // Allocate a new VMM block for the buffer.
    io_addr = mm_guarded_block_map(reinterpret_cast<void*>(o_phys),
                           VmmManager::MBOX_DMA_SIZE);
        // Note: We do not plan on deleting this block, even when the buffer
        //       is destructed, because we have fundamentally changed the
        //       underlying memory by populating the addresses in a different
        //       physical location (see populate_cache_lines call below).

    // Populate cache lines in unsecure memory.
    KernelMisc::populate_cache_lines(
        reinterpret_cast<uint64_t*>(io_addr),
        reinterpret_cast<uint64_t*>(VmmManager::MBOX_DMA_SIZE +
            reinterpret_cast<uint64_t>(io_addr)));

    memset(io_addr, '\0', VmmManager::MBOX_DMA_SIZE);

}

