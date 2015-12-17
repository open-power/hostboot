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
#include <pnor_const.H>
#include <pnor_utils.H>
#include <common/ffs_hb.H>

extern "C" void task_end_stub();
extern "C" void enterHBB(uint64_t i_hbb_hrmor, uint64_t i_hbb_offset);

#define assert(expr) \
{\
    if (unlikely(!(expr)))\
    {\
        task_end_stub();\
    }\
}

#define printk(format...)

namespace Bootloader{
    /**
     * @brief Pointer to bootloader scratch space
     *
     * Pointer to location in main storage which bootloader uses as
     * scratch space
     */
    extern uint8_t *g_blScratchSpace;

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

    /** @enum HbbLengths
     *  @brief List of HBB lengths.
     *
     *  These are the lengths of the Hostboot Base data or instructions
     *  with and without ECC.
     */
    enum HbbLengths
    {
        /** LENGTH_WO_ECC */
        LENGTH_WO_ECC = 8,
        /** LENGTH_W_ECC */
        LENGTH_W_ECC = 9
    };

    /** @enum HbAddrs
     *  @brief List of addresses where HBB and HBBL code is stored.
     *
     *  These specify locations where the Hostboot Bootloader code is
     *  stored and where it stores the Hostboot Base code.  The HBB code
     *  is copied to various locations as the HBBL works with it.  Then
     *  HBB is copied to its running location and its execution is started.
     */
    enum HbAddrs
    {
        // @TODO-RTC:138273-Support multiple nodes using relative HRMOR

        /** HRMOR */
        HBBL_HRMOR = 130*MEGABYTE,
        HBB_HRMOR = 128*MEGABYTE,

        /** Location of working copy of HBB with ECC */
        HBB_ECC_WORKING_ADDR = (HBBL_HRMOR + 1*MEGABYTE),

        /** Location of HBBL */
        HBBL_ADDR = HBBL_HRMOR,
        /** Location of HBBL exception vectors */
        HBBL_EXCEPTION_VECTORS_ADDR = HBBL_ADDR,
        /** Location of HBBL code */
        HBBL_CODE_ADDR = HBBL_ADDR + 12*KILOBYTE,
        /** Location of HBBL scratch space */
        HBBL_SCRATCH_SPACE_ADDR = HBBL_ADDR + 64*KILOBYTE,

        /** Location of working copy of HBB without ECC */
        HBB_WORKING_ADDR = (HBBL_HRMOR - 1*MEGABYTE),
        /** Location of running copy of HBB */
        HBB_RUNNING_ADDR = (HBBL_HRMOR - 2*MEGABYTE),
        /** Offset for starting running copy of HBB */
        HBB_RUNNING_OFFSET = 0,
        /** Mask to indicate HRMOR should be ignored for the address */
        IGNORE_HRMOR_MASK = 0x8000000000000000ul
    };
} // end namespace Bootloader

#endif
