/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/mbox/mbox_dma_buffer.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#if !defined(__MBOX_DMA_BUFFER_H)
#define __MBOX_DMA_BUFFER_H

/** @file mbox_dma_buffer.H
 *  @brief Provides the interfaces to the MBOX DMA buffer
 */

#include <stdint.h>
#include <builtins.h>
#include <limits.h>
#include <kernel/vmmmgr.H>


namespace MBOX
{

    class DmaBuffer
    {
        public:

            DmaBuffer();
            ~DmaBuffer();
            
            /**
             * Get DMA buffer space
             * @param[in/out] io_size, size in bytes of space needed,
             *                         0 means get all available buffers
             *                         bit map is returned showing blocks 
             *                         aquired.
             *
             * @note: There are 64 total buffers in the shared DMA pool. The
             * bit map has one bit for each buffer. The bit map returned will
             * have bits on for the buffers who's ownership is being abdicated
             * by this DMA buffer pool.
             *
             * @returns void * to the address allowcated.
             */
            void * getBuffer(uint64_t & io_size);

            /**
             * Release DMA buffer(s) back to the DMA buffer pool
             * @param[in] i_buffer, pointer to the buffer
             * @param[in] i_size,  size in bytes of buffer
             */
            void release(void * i_buffer, size_t i_size);

            /**
             * Add DMA buffers to the buffer pool
             * @param[in] i_map, bit map representing the buffers being added.
             *
             * @note: There are 64 total buffers in the shared DMA pool. The
             * bit map has one bit for each buffer. The bit map given will
             * have bits on for the buffers who's ownership is being added
             * to the HB DMA pool.
             */
            void addBuffers(uint64_t i_map);

            /**
             * Get DMA buffer start address
             * @return DMA buffer start address
             */
            ALWAYS_INLINE
            void * getDmaBufferHead() { return iv_head; }

            /**
             * Query if all the the DMA blocks are available
             * @return [true|false]
             */
            ALWAYS_INLINE
            bool ownsAllBlocks() { return iv_dir == makeMask(VmmManager::MBOX_DMA_PAGES); }

            /**
             * Query if address is a DMA address
             * @param[in] i_address, The address to query
             * @return [true - is a DMA address | false - is not a DMA address]
             */
            ALWAYS_INLINE
            bool isDmaAddress(void * i_address) const
            {
                uint64_t address = reinterpret_cast<uint64_t>(i_address);
                return
                    (address >= VmmManager::MBOX_DMA_ADDR &&
                     address < (VmmManager::MBOX_DMA_ADDR + 
                                (VmmManager::MBOX_DMA_PAGES *
                                 VmmManager::MBOX_DMA_PAGESIZE)));
            }

        private:

            /**
             * Create the bit mask for the size in DMA_PAGES
             * @param[in] i_size The size in DMA_PAGES
             * @post will assert if i_size > MAX_MASK_SIZE
             * @return The mask - left justified
             */
            static uint64_t makeMask(uint64_t i_size);

            enum
            {
                MAX_MASK_SIZE = sizeof(uint64_t) * 8,
            };

            void * iv_head;     //!< Start of DMA memory
            uint64_t iv_dir;    //!< 1 bit per 1k buffer, 1 = available

    };
}; // namespace

#endif
