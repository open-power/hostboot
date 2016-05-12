/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/arch/pirformat.H $                                */
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
/* A variety of PIR/PID formatting utilities */

#ifndef _PIRFORMAT_H
#define _PIRFORMAT_H

/**
 * @brief Format of Processor Id Register (PIR) for P9
 *
 *  GGGGCCCRPPPPPTT where
 *     G = group, C = chip, P = proc, T = thread, R = reserved
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
            uint32_t groupId:4;      // 17:20 = group id
            uint32_t chipId:3;       // 21:23 = chip id
            uint32_t reserved1:1;    //    24 = reserved
            uint32_t coreId:5;       // 25:29 = core id (normal core)
            uint32_t threadId:2;     // 30:31 = thread id (normal core)
        } PACKED;

        struct
        {
            // Fused Core Mode
            uint32_t reservedFused0:17;   // 00:16 = unused
            uint32_t groupIdFused:4;      // 17:20 = group id
            uint32_t chipIdFused:3;       // 21:23 = chip id
            uint32_t reservedFused1:1;    //    24 = reserved
            uint32_t coreIdFused:4;       // 25:28 = core id (fused core)
            uint32_t threadIdFused:3;     // 29:31 = thread id (fused core)
        } PACKED;
    };
    PIR_t(uint32_t i_word = 0) : word(i_word) {}

    PIR_t(uint32_t i_groupId, uint32_t i_chipId,
          uint32_t i_coreId, uint32_t i_thread = 0) :
      reserved0(0),
    groupId(i_groupId), chipId(i_chipId),
      reserved1(0),
    coreId(i_coreId), threadId(i_thread) {}

    PIR_t operator= (uint32_t i_word)
    {
        word = i_word;
        return word;
    }

    bool operator< (const PIR_t& r) const
    {
        return word < r.word;
    }

    // Some more handy constants
    enum
    {
        // Normal (non-fused) mode
        BITS_IN_GROUP = 4,
        BITS_IN_CHIP = 3,
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
    // TODO RTC 154162 Add testcases for the below functions
    inline static uint32_t groupFromPir( uint32_t i_pir ) {
        return (static_cast<PIR_t>(i_pir)).groupId;
    }
    inline static uint32_t chipFromPir( uint32_t i_pir ) {
        return (static_cast<PIR_t>(i_pir)).chipId;
    }
    inline static uint32_t coreFromPir( uint32_t i_pir ) {
        return (static_cast<PIR_t>(i_pir)).coreId;
    }
    inline static uint32_t threadFromPir( uint32_t i_pir ) {
        return (static_cast<PIR_t>(i_pir)).threadId;
    }

    inline static uint32_t groupFromChipId( uint32_t i_chipId ) {
        return (i_chipId >> BITS_IN_CHIP);
    }
    inline static uint32_t chipFromChipId( uint32_t i_chipId ) {
        return (i_chipId & (CHIP_MASK >>
                            (BITS_AFTER_CHIP)));
    }

    inline static uint32_t groupFromCoreId( uint32_t i_chipId ) {
        return (i_chipId >> (BITS_AFTER_GROUP));
    }
    inline static uint32_t chipFromCoreId( uint32_t i_chipId ) {
        return (i_chipId >> BITS_AFTER_CHIP);
    }
    inline static uint32_t coreFromCoreId( uint32_t i_chipId ) {
        return (i_chipId & (CORE_MASK >> BITS_IN_THREAD));
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

