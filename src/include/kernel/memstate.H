/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/memstate.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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

namespace KernelMemState
{
    // hb_Mem_Location struct values are defined below.
    /* Core Scratch 6 (Scom 0x10013289) will be used to indicate the memory
     state

     Register Bit Definition:
     - 0:7 - Indicator of memory mode
     NOTE:  having no bits on in this range indicated the memory is not ready.
     - - 0b00000000 = Hostboot contained in L3
     - - 0b00000001 = Hostboot expanded to mainstore
     - 8:31 - Reserved/Unused
     - 32:63 - Size of active Hostboot memory in MB
     - - 0 = Hostboot is not ready yet.
     - - 4 = Hostboot is using half a cache
     - - 8 = Hostboot is using the full cache
     - - 32 = Hostboot is using 32 MB of mainstore*/


    enum MemLocation
    {
          MEM_CONTAINED_NR  = 0x0,
          MEM_CONTAINED_L3  = 0x80,
          MEM_CONTAINED_MS  = 0x40,
    };

    // This constants must be kept in sync with the Dump.pm debug tool.
    enum MemSize
    {
          NO_MEM          =  0x0,
          HALF_CACHE      =  0x00000004,
          FULL_CACHE      =  0x00000008,
          MS_32MEG        =  0x00000020,
          PRE_SECURE_BOOT =  0x000000FF,
    };

    struct mem_location
    {

        union{
            struct {
                uint64_t memMode:8;     /**< indicator of memory mode HostBoot
                                             contained in l3 or mainstore  */

                uint64_t reserved:24;   /**< reserved */
                uint64_t memSize:32;    /**< Size of the memory */
            };
            uint64_t Scratch6Data;      /**< Full double word */
        };
   };

    /** @fn set
     *
     *  @brief Sets the Hostboot memory location and size in the scratch
     *     register 6
     *
     *  This is used to update the core scratch reg 6 with the current
     *  location of hostboot memory and the size it is.
     *
     *  @param[in] uint16_t - location of the memory (L3 or Mainstore)
     *  @param[in] uint32_t - size of the memory
     */
    void setMemScratchReg(MemLocation i_location,MemSize i_size);

};

#endif
