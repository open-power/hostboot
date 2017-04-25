/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/arch/pvrformat.H $                                */
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
#ifndef _PVRFORMAT_H
#define _PVRFORMAT_H

/**
 * @brief Format of Processor Version Register (PVR) for P9
 */
struct PVR_t
{
    union
    {
        // Layout of the PVR is (32-bit):
        uint32_t word;

        //Nimbus DD1.0
        //     2 nibbles reserved.
        //     2 nibbles chip family.
        //       = x'4E' - P9
        //     1 nibble technology.
        //     1 nibble major DD.
        //     1 nibble reserved.
        //     1 nibble minor DD.
        struct
        {
            uint32_t dd1_reserved0:8;    // 00:07 = unused
            uint32_t dd1_chipFamily:8;   // 08:15 = chip type
            uint32_t dd1_tech:4;         // 16:19 = technology
            uint32_t dd1_majorDD:4;      // 20:23 = Major DD
            uint32_t dd1_reserved1:4;    // 24:27 = unused
            uint32_t dd1_minorDD:4;      // 28:31 = Minor DD
        } PACKED;


        //Nimbus DD2+, Cumulus
        //     2 nibbles reserved.
        //     2 nibbles chip family.
        //       = x'4E' - P9
        //     2 bits Simics indicator.
        //     1 bit chip type.
        //       = x'0' - Nimbus
        //       = x'1' - Cumulus
        //     1 bit SMT mode.
        //       = x'0' - 12 core  (SMT8)
        //       = x'1' - 24 core  (SMT4)
        //     1 nibble major DD.
        //     1 nibble reserved.
        //     1 nibble minor DD.
        struct
        {
            uint32_t reserved0:8;    // 00:07 = unused
            uint32_t chipFamily:8;   // 08:15 = chip family
            uint32_t simics:2;       // 16:17 = Simics flag
            uint32_t chipType:1;     // 18 = chip type
            uint32_t smt:1;          // 19 = SMT mode
            uint32_t majorDD:4;      // 20:23 = Major DD
            uint32_t reserved1:4;    // 24:27 = unused
            uint32_t minorDD:4;      // 28:31 = Minor DD
        } PACKED;
    };

    // Populate with a 32-bit data word
    PVR_t(uint32_t i_word = 0) : word(i_word) {}

    // Populate with a 64-bit data word
    PVR_t(uint64_t i_word = 0)
      : word(static_cast<uint32_t>(i_word & 0xFFFFFFFF)) {}

    PVR_t operator= (uint32_t i_word)
    {
        word = i_word;
        return word;
    }

    PVR_t operator= (uint64_t i_word)
    {
        word = static_cast<uint32_t>(i_word & 0xFFFFFFFF);
        return word;
    }

    /**
     * @brief Return Major.Minor DD level
     * @return 8-bit DD level
     */
    inline uint8_t getDDLevel() {
        return (majorDD << 4) | minorDD;
    }

    /**
     * @brief  A bunch of constants
     */
    enum
    {
        CHIP_DD_MASK  = 0x00FF0F0F,
        IS_NIMBUS_DD1 = 0x004E0100,

        // Field: chipType
        NIMBUS_CHIP = 0,
        CUMULUS_CHIP = 1,

        // Field: smt
        SMT8_MODE = 0,
        SMT4_MODE = 1,
        SMT_MASK  = 0x00001000,
        SMT_SHIFT = 12,

        // Field: chipFamily
        P8_MURANO = 0x4B,
        P8_NAPLES = 0x4C,
        P8_VENICE = 0x4D,
        P9_ALL    = 0x4E,
    };
};

#endif //_PVRFORMAT_H
