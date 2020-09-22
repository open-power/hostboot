/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/arch/memorymap.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
#include <assert.h>


namespace MEMMAP
{

/**
 * @brief bit definitions for 4-bit mode 0/1 topology ID
 */
typedef union
{
    struct // GGGC
    {
        uint8_t rsvd1:4; // 0:3
        uint8_t group:3; // 4:6
        uint8_t chip :1; // 7
    } mode0;
    struct // GGCC
    {
        uint8_t rsvd1:4; // 0:3
        uint8_t group:2; // 4:5
        uint8_t chip :2; // 6:7
    } mode1;
    uint8_t topoId;
}topologyIdBits_t;

/**
 * @brief bit definitions for 5-bit mode 0/1 topology index
 */
typedef union
{
    struct // GGG0C
    {
        uint8_t rsvd1:3; // 0:2
        uint8_t group:3; // 3:5
        uint8_t rsvd2:1; // 6
        uint8_t chip :1; // 7
    } mode0;
    struct // 0GGCC
    {
        uint8_t rsvd1:4; // 0:3
        uint8_t group:2; // 4:5
        uint8_t chip :2; // 6:7
    } mode1;
    uint8_t topoIndex;
}topologyIndexBits_t;

/**
 * @brief bit definition for a complete memory address
 */
struct memoryAddress_t
{
    union
    {
        struct
        {
            uint64_t rsvd1:12;    //0:11
            uint64_t smf:1;       //12
            uint64_t memType:2;   //13:14
                                  // b00 = non-mirrored
                                  // b10 = mirrored
                                  // b11 = mmio
            uint64_t topoIndex:5; //15:19
            uint64_t chipAddr:44; //20:63
        } bits;

        uint64_t address;
    };

    memoryAddress_t() : address(0) {};
};

/**
 * Collection of constants and utility functions related to the
 * static memory map defined for the POWER9 family of processors.
 */

/**
 *  @brief  Each 5-bit topology index addresses a 16 terabyte space
 */
constexpr uint64_t  MMIO_OFFSET_PER_TOPO_INDEX =  0x0000100000000000;

/**
 *  @brief This address bit determines if the address is in SMF space.
 */
constexpr uint64_t  IS_SMF_ADDR_BIT =             0x0008000000000000;


/**
 * @brief Compute MMIO address for a 4-bit topology ID, topology Mode and
 *        base address value.
 *
 * @param[in] i_baseAddr The base MMIO address for topology index 0
 * @param[in] i_topologyMode The topology mode.
 * @param[in] i_topologyId The topology ID (or effective topology ID)
 *
 * @return The base address adjusted for the chip associated with the given
 *         topology ID.
 */
inline uint64_t computeMemoryMapOffset( const uint64_t i_baseAddr,
                                        const uint8_t i_topologyMode,
                                        const uint8_t i_topologyId)
{
    // The 5-bit topology index value must be used to calculate the
    // address.  The index value is derived from the topology ID as
    // follows:
    //
    // MODE0: GGGC -> GGG0C
    // MODE1: GGCC -> 0GGCC
    topologyIdBits_t l_idBits;
    l_idBits.topoId = i_topologyId;
    topologyIndexBits_t l_indexBits;
    l_indexBits.topoIndex = 0;

    if(i_topologyMode == 0)
    {
        l_indexBits.mode0.group = l_idBits.mode0.group;
        l_indexBits.mode0.chip = l_idBits.mode0.chip;
    }
    else
    {
        l_indexBits.mode1.group = l_idBits.mode1.group;
        l_indexBits.mode1.chip = l_idBits.mode1.chip;
    }

    return (i_baseAddr + (MMIO_OFFSET_PER_TOPO_INDEX * l_indexBits.topoIndex));
};

/**
 * @brief Compute address for a 5-bit topology index
 *
 * @param[in] i_baseAddr The base address for topology index 0
 * @param[in] i_topologyIndex The topology Index (or effective topology Index)
 *
 * @return The base address adjusted for the chip associated with the given
 *         topology Index.
 */
inline uint64_t computeMemoryMapOffset( const uint64_t i_baseAddr,
                                        const uint8_t i_topologyIndex)
{
    memoryAddress_t l_addr;
    l_addr.address = i_baseAddr;
    l_addr.bits.topoIndex = i_topologyIndex;
    return l_addr.address;
};

/**
 * @brief Make a 4-bit topology ID from a group and chip ID formatted with
 *        the given topology mode.
 *
 * @param[in] i_topologyMode The topology mode.
 * @param[in] i_group The group number
 * @param[in] i_chip The chip number
 *
 * @return The topology ID for the group and chip number
 */
inline uint8_t makeTopoId(const uint8_t i_topologyMode,
                          const uint8_t i_group,
                          const uint8_t i_chip)
{
    // NOTE: mode 0 -> GGGC
    //       mode 1 -> GGCC
    topologyIdBits_t l_idBits;
    l_idBits.topoId = 0;
    if (i_topologyMode == 0)
    {
        l_idBits.mode0.group = i_group;
        l_idBits.mode0.chip = i_chip;
    }
    else
    {
        l_idBits.mode1.group = i_group;
        l_idBits.mode1.chip = i_chip;
    }

    return l_idBits.topoId;
};

/**
 * @brief Determine topology index from an address
 * @param[in] i_addr  position-specific memory address
 * @return  Fabric Topology ID that address represents
 */
inline uint8_t getTopoIndexFromAddr( const uint64_t i_addr )
{
    memoryAddress_t l_memAddr;
    l_memAddr.address = i_addr;
    return l_memAddr.bits.topoIndex;
};

/**
 *  @brief  A few default values that will need to be known
 *          by low-level code
 */
constexpr uint64_t  MMIO_BASE =                              0x0006000000000000;
constexpr uint64_t  MMIO_GROUP0_CHIP0_XSCOM_BASE_ADDR =      0x000E03FC00000000;
constexpr uint64_t  MMIO_GROUP0_CHIP0_LPC_BASE_ADDR   =      0x0006030000000000;
constexpr uint64_t  MMIO_GROUP0_CHIP0_PSI_BRIDGE_BASE_ADDR = 0x0006030203000000;
constexpr uint64_t  MMIO_GROUP0_CHIP0_XIVE_CONTROLLER_BASE_ADDR =
                                                             0x0006030200000000;
constexpr uint64_t  MMIO_GROUP0_CHIP0_INT_CQ_TM_BASE_ADDR =  0x0006030203180000;
constexpr uint64_t  MMIO_GROUP0_CHIP0_PSI_HB_ESB_BASE_ADDR = 0x0006030202000000;

// 64 TB offset for each node, maximum of nodes possible
constexpr uint64_t  NODE_OFFSET =                            0x0000400000000000;
constexpr uint64_t  NODE_OFFSET_MASK =                       0x0000F00000000000;

} //end namespace

#endif //#ifndef _MEMORYMAP_H
