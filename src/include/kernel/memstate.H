/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/memstate.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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
/** @file misc.H
 *  @brief Misc. Kernel functions and utilities.
 */

#ifndef __KERNEL_MEMSTATE_H
#define __KERNEL_MEMSTATE_H

#include <usr/vmmconst.h>

namespace KernelMemState
{
    /* see mmio.h for scratch reg definitions */

    enum MemLocation
    {
          MEM_CONTAINED_NR  = 0x0,
          MEM_CONTAINED_L3  = 0x8,
          MEM_CONTAINED_MS  = 0x4,
    };

    // This constants must be kept in sync with the Dump.pm debug tool.
    enum MemSize
    {
          NO_MEM          =  0x000,
          HALF_CACHE      =  0x004,
          REDUCED_CACHE   =  0x008,
          FULL_CACHE      =  0x00A,
          FULL_MEM        =  (VMM_MEMORY_SIZE/MEGABYTE),
          MAX_MEMORY      =  0xFFF  //max space allocated for size
    };

    struct MemState_t
    {

        union{
            struct {
                // 00:03 - Indicator of memory mode
                uint64_t location:4;    /**< Indicator of memory mode HostBoot
                                             contained in L3 or mainstore  */
                // 04:51 - Current HRMOR
                uint64_t hrmor:48;      /**< Current HRMOR in MB */
                // 52:63 - Size of active Hostboot memory
                uint64_t size:12;       /**< Size of the memory in MB */
            };
            uint64_t fullData;          /**< Full double word */
        };
   } PACKED;

    /** @fn setMemScratchReg
     *
     *  @brief Sets the Hostboot memory location and size
     *
     *  This is used to update the core scratch reg with the current
     *  location of hostboot memory and the size it is.
     *
     *  @param[in] uint16_t - location of the memory (L3 or Mainstore)
     *  @param[in] uint32_t - size of the memory
     */
    void setMemScratchReg( MemLocation i_location,
                           MemSize i_size );

};

#endif
