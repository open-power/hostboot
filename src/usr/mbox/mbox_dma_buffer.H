/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/mbox_dma_buffer.H $                              */
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
             *                         acquired.
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
                uint64_t bufaddr = reinterpret_cast<uint64_t>(iv_head);

                return ((address >= bufaddr) &&
                        (address < (bufaddr +
                            (VmmManager::MBOX_DMA_PAGES *
                             VmmManager::MBOX_DMA_PAGESIZE))
                        )
                    );
            }

            /**
             * Get the physical address of DMA buf to send to the FSP
             * @param[in] i_address, The HB address to translate
             * @return [FSP physical address]
             */
            ALWAYS_INLINE
            uint64_t toPhysAddr(void * i_address) const
            {
                return iv_phys_head +
                    (reinterpret_cast<uint64_t>(i_address) -
                     reinterpret_cast<uint64_t>(iv_head));
            }

            /**
             * Get the virtual address of DMA buf to sent by the FSP
             * @param[in] i_address, The FSP Physical address to translate
             * @return [HB virtual address]
             */
            ALWAYS_INLINE
            void* toVirtAddr(uint64_t i_address) const
            {
                uint64_t base = reinterpret_cast<uint64_t>(iv_head);
                return reinterpret_cast<void*>(
                                    base + (i_address-iv_phys_head));
            }

            /**
             * Set the state of shutdown dma request sent
             * @param[in] The state to set [true|false]
             */
            ALWAYS_INLINE
            void setShutdownDmaRequestSent(bool i_state)
            {
                iv_dma_req_sent = i_state;
            }

            /**
             * Query if the shutdown DMA request has been sent
             * @return state [true|false]
             */
            ALWAYS_INLINE
            bool shutdownDmaRequestSent()
            {
                return iv_dma_req_sent;
            }

        private:

            /**
             * Create the bit mask for the size in DMA_PAGES
             * @param[in] i_size The size in DMA_PAGES
             * @post will assert if i_size > MAX_MASK_SIZE
             * @return The mask - left justified
             */
            static uint64_t makeMask(uint64_t i_size);

            /**
             * Perform VMM operations to allocate physical area in unsecure
             * region of memory.
             */
            void initPhysicalArea(void*& io_addr, uint64_t& o_phys);

            enum
            {
                MAX_MASK_SIZE = sizeof(uint64_t) * 8,
            };

            void * iv_head;            //!< Start of DMA memory
            uint64_t iv_phys_head;     //!< Physical translation of iv_head
            uint64_t iv_dir;           //!< 1 bit per 1k buffer, 1 = available
            bool iv_dma_req_sent;      //!< Request sent to retrieve all buffers

    };
}; // namespace

#endif
