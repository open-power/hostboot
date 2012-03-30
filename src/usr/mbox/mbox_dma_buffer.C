//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/mbox/mbox_dma_buffer.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
#include "mbox_dma_buffer.H"
#include <stdlib.h>
#include <assert.h>
#include <util/align.H>
#include <trace/interface.H>
#include <kernel/pagemgr.H>


#define ALIGN_DMAPAGE(u) (((u) + (VmmManager::MBOX_DMA_PAGESIZE-1)) & \
                          ~(VmmManager::MBOX_DMA_PAGESIZE-1))

using namespace MBOX;

// Defined in mboxdd.C
extern trace_desc_t * g_trac_mbox;

DmaBuffer::DmaBuffer() :
    iv_head(NULL),
    iv_dir(makeMask(VmmManager::MBOX_DMA_PAGES))
{
    iv_head = reinterpret_cast<void*>(VmmManager::MBOX_DMA_ADDR);
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

