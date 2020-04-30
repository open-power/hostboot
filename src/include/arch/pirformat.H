/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/arch/pirformat.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/* A variety of PIR/PID formatting utilities */

#ifndef _PIRFORMAT_H
#define _PIRFORMAT_H

#include <assert.h>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <arch/memorymap.H>
#include <config.h>
#include <stdio.h>
#include <targeting/common/util.H>

using namespace TARGETING;
using namespace MEMMAP;

/**
 * @brief Format of Processor Id Register (PIR) for P10
 *
 *  SSSTTTTRCCCCCYY where
 *     S = spare, T = topology, C = core, Y = thread, R = reserved
 */
struct PIR_t
{
    union
    {
        uint32_t word;

        struct
        {
            // Normal Core Mode
            uint32_t reserved0:17;   // 00:16 = unused
            uint32_t spareId:3;      // 17:19 = spare
            uint32_t topologyId:4;   // 20:23 = topology id
            uint32_t reserved1:1;    //    24 = reserved
            uint32_t coreId:5;       // 25:29 = core id (normal core)
            uint32_t threadId:2;     // 30:31 = thread id (normal core)
        } PACKED;

        struct
        {
            // Fused Core Mode
            uint32_t reservedFused0:17;   // 00:16 = unused
            uint32_t spareIdFused:3;      // 17:19 = spare
            uint32_t topologyIdFused:4;   // 20:23 = topolog id
            uint32_t reservedFused1:1;    //    24 = reserved
            uint32_t coreIdFused:4;       // 25:28 = core id (fused core)
            uint32_t threadIdFused:3;     // 29:31 = thread id (fused core)
        } PACKED;
    };
    PIR_t(uint32_t i_word = 0) : word(i_word) {}

    PIR_t(uint32_t i_topologyId, uint32_t i_coreId,
            uint32_t i_thread = 0) :
        reserved0(0), spareId(0), topologyId(i_topologyId),
        reserved1(0), coreId(i_coreId), threadId(i_thread) {}

    PIR_t operator= (uint32_t i_word)
    {
        word = i_word;
        return word;
    }

    bool operator< (const PIR_t& r) const
    {
        return word < r.word;
    }

    bool operator== (const PIR_t& rhs)
    {
        return (word == rhs.word);
    }

    // Some more handy constants
    enum
    {
        // Normal (non-fused) mode
        // RTC: 246937 remove BITS_IN_CHIP + associated values
        BITS_IN_CHIP = 3,
        BITS_IN_TOPOLOGY = 4,
        BITS_IN_CORE = 5,
        BITS_IN_THREAD = 2,
        BITS_IN_RESERVED1 = 1,

        BITS_AFTER_THREAD = 0,
        BITS_AFTER_CORE = BITS_AFTER_THREAD+BITS_IN_THREAD,
        BITS_AFTER_CHIP = BITS_IN_RESERVED1+BITS_AFTER_CORE+BITS_IN_CORE,
        BITS_AFTER_GROUP = BITS_AFTER_CHIP+BITS_IN_CHIP,

        GROUP_MASK =  0x00007800,
        CHIP_MASK =   0x00000700,
        CORE_MASK =   0x0000007C,
        THREAD_MASK = 0x00000003,
        VALID_BITS =  0x00003FFF,

        // Fused mode
        BITS_IN_CORE_FUSED = 5,
        BITS_IN_THREAD_FUSED = 3,

        GROUP_MASK_FUSED =  0x00007800,
        CHIP_MASK_FUSED =   0x00000700,
        CORE_MASK_FUSED =   0x00000078,
        THREAD_MASK_FUSED = 0x00000007,
    };

    // Some handy functions

    inline static uint32_t topologyIdFromPir( PIR_t i_pir ) {
        return i_pir.topologyId;
    }
#ifdef __HOSTBOOT_MODULE
    inline static uint32_t getTopoMode() {
        TARGETING::Target* l_sys = nullptr;
        TARGETING::TargetService & l_tgtServ = TARGETING::targetService();
        l_tgtServ.getTopLevelTarget(l_sys);
        assert(l_sys != nullptr, "System target cannot be null");

        return l_sys->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_MODE>();
    }
    inline static uint32_t nodeOrdinalFromPir( PIR_t i_pir ) {
        const auto l_topoMode = getTopoMode();

        if (l_topoMode == TARGETING::PROC_FABRIC_TOPOLOGY_MODE_MODE0)
        {
            // If mode 0, ordinal id is 0
            return 0;
        }
        else
        {
            // If mode 1, ordinal id is group id
            return groupFromPir(i_pir);
        }
    }
    inline static uint32_t groupFromPir( PIR_t i_pir ) {
        const auto l_localTopoId = i_pir.topologyId;
        uint8_t l_chipId = 0;
        uint8_t l_groupId = 0;
        extractGroupAndChip(l_localTopoId, l_groupId, l_chipId);

        return l_groupId;
    }
    inline static uint32_t chipFromPir( PIR_t i_pir ) {
        const auto l_localTopoId = i_pir.topologyId;
        uint8_t l_chipId = 0;
        uint8_t l_groupId = 0;
        extractGroupAndChip(l_localTopoId, l_groupId, l_chipId);

        return l_chipId;
    }

    /**
     *  @brief Return a chip ID based on the input topology ID
     *
     *  @param[in] i_topologyId Processor topology ID
     *
     *  @return uint32_t The chip ID built from the input topology ID
     */
    inline static uint32_t createChipId(const topoId_t i_topologyId)
    {
        uint8_t groupId = 0;
        uint8_t chipId = 0;
        extractGroupAndChip(i_topologyId,groupId,chipId);
        return ((groupId << BITS_IN_CHIP) | chipId);
    }

#endif
    inline static uint32_t coreFromPir( PIR_t i_pir ) {
        return i_pir.coreId;
    }
    inline static uint32_t threadFromPir( PIR_t i_pir ) {
        return i_pir.threadId;
    }
    // Below is the right-justified portion of the PIR laid out in bits
    //     (normal core mode) along with coreId picture
    //
    //   - - - -   - - - -   - - - -   - - - -
    //    |    ^    |  ^   | ^|     ^     | ^
    //         |       |     |      |       |
    //      spare   topology |    core   thread
    //                  reserved    |
    //    |     coreId              |
    //    |_________________________|
    //
    // A coreId contains the spare, topology, reserved, and core bits.
    //   It is also right justified.
    inline static uint32_t coreFromCoreId( uint32_t i_coreId ) {
        return (i_coreId & (CORE_MASK >> BITS_AFTER_CORE));
    }
    inline static uint32_t createChipId( uint32_t i_groupId,
                                         uint32_t i_chipId ) {
        return ((i_groupId << BITS_IN_CHIP) | i_chipId);
    }
    inline static uint32_t createCoreId( uint32_t i_groupId,
                                         uint32_t i_chipId,
                                         uint32_t i_coreId )
    {
        return ((((i_groupId << BITS_IN_CHIP)
                  | i_chipId)
                 << (BITS_IN_RESERVED1 + BITS_IN_CORE)) | i_coreId);
    }
    inline static uint32_t createCoreId( uint32_t i_chipId,
                                         uint32_t i_coreId )
    {
        return ((i_chipId << (BITS_IN_CORE + BITS_IN_RESERVED1)) | i_coreId);
    }

};

#endif /* _PIRFORMAT_H */

