/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/arch/memorymap.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef _MEMORYMAP_H
#define _MEMORYMAP_H

#include <limits.h>

/**
 * Collection of constants and utility functions related to the
 * static memory map defined for the POWER9 family of processors.
 */

/**
 *  @brief  Static offsets into other chips
 */
constexpr uint64_t  MMIO_OFFSET_PER_CHIP  = (4*TERABYTE);  //0x40000000000
constexpr uint64_t  MMIO_OFFSET_PER_GROUP = (32*TERABYTE); //0x200000000000

/**
 * @brief Compute MMIO value for a given chip and base value
 */
inline uint64_t computeMemoryMapOffset( uint64_t i_baseAddr,
                                        uint8_t i_group,
                                        uint8_t i_chip )
{
    return (i_baseAddr +
      (MMIO_OFFSET_PER_GROUP * i_group) +
      (MMIO_OFFSET_PER_CHIP * i_chip));
};

/**
 *  @brief  A few default values that will need to be known
 *          by low-level code
 */
constexpr uint64_t  MMIO_GROUP0_CHIP0_XSCOM_BASE_ADDR = 0x000603FC00000000;
constexpr uint64_t  MMIO_GROUP0_CHIP0_LPC_BASE_ADDR   = 0x0006030000000000;
constexpr uint64_t  MMIO_GROUP0_CHIP0_PSI_BRIDGE_BASE_ADDR = 0x0006030203000000;
constexpr uint64_t  MMIO_GROUP0_CHIP0_XIVE_CONTROLLER_BASE_ADDR = 0x0006030203100000;
constexpr uint64_t  MMIO_GROUP0_CHIP0_XIVE_THREAD_MGMT1_BASE_ADDR = 0x0006020000000000;
constexpr uint64_t  MMIO_GROUP0_CHIP0_PSI_HB_ESB_BASE_ADDR = 0x00060302031C0000;
constexpr uint64_t  MMIO_GROUP0_CHIP0_INTP_BASE_ADDR = 0x0003FFFF80000000;


#endif //#ifndef _MEMORYMAP_H
