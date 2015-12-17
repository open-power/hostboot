/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/bootloader.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

#ifndef __BOOT_LOADER_H
#define __BOOT_LOADER_H

/**
 * @file    bootloader.H
 *
 *  TaskInfo structs for each task that will run.
 */

#include <builtins.h>
#include <arch/ppc.H>

extern "C" void task_end_stub();

#define assert(expr) \
{\
    if (unlikely(!(expr)))\
    {\
        MAGIC_INSTRUCTION(MAGIC_BREAK); /* @TODO RTC:133821 temp bringup */ \
        task_end_stub();\
    }\
}

#define printk(format...)

namespace Bootloader{
    /** @enum MMIOLoadStoreSizes
     *  @brief List of MMIO Load and Store Sizes.
     *
     *  These are the sizes (in bytes) for the load and store commands used
     *  to read and write data when handling an MMIO.
     */
    enum MMIOLoadStoreSizes
    {
        /** BYTESIZE */
        BYTESIZE = 1,
        /** WORDSIZE */
        WORDSIZE = 4,
        /** DBLWORDSIZE */
        DBLWORDSIZE = 8
    };

    /**
     * @brief Handle MMIO to copy code/data from one location to another
     *
     * @param[in] i_srcAddr     MMIO address to copy from
     * @param[in] i_destAddr    address to copy to
     * @param[in] i_size        number of bytes to copy
     * @param[in] i_ld_st_size  size of data in ld and st instructions
     *        BYTESIZE     => copy 1 byte at a time
     *        WORDSIZE     => copy 4 bytes at a time
     *        DBLWORDSIZE  => copy 8 bytes at a time
     */
    extern void handleMMIO(uint64_t i_srcAddr,
                           uint64_t i_destAddr,
                           uint32_t i_size,
                           MMIOLoadStoreSizes i_ld_st_size);

    /**
     * @brief Pointer to bootloader scratch space
     *
     * Pointer to location in main storage which bootloader uses as
     * scratch space
     */
    extern uint8_t *g_blScratchSpace;
} // end namespace Bootloader

#endif
