/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/arch/pvrformat.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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

#include <stdint.h>

/**
 * @brief Format of Processor Version Register (PVR) for P10
 */
struct PVR_t
{
    /**
     * @brief  Constants for the PVR_t::smt field
     */
    enum SMT_SCALING_t
    {
        SMT8_MODE = 0,
        SMT4_MODE = 1
    };

    /**
     * @brief Constant values representing chip families
     */
    enum chipFamily_t : uint16_t
    {
        P10 = 0x80
    };

    union
    {
        // Layout of the PVR is 32-bits:
        uint32_t word;

        struct
        {
            chipFamily_t chipFamily: 16;/* Processor version number. POWER10
                                           version is 0x0080. */
            uint32_t reserved1 : 3; // Zero.
            SMT_SCALING_t smt  : 1; /* POWER10 chip scaling factor (0 ->
                                       8-threaded cores, 1 -> 4-threaded
                                       cores). */
            uint32_t majorDD   : 4; /* Major revision level. The major processor
                                       revision level starts at 1, indicating
                                       major revision 1. Subsequent revisions
                                       will be 2, 3, and so on. */
            uint32_t reserved2 : 4; // Zero.
            uint32_t minorDD   : 4; /* Minor revision level. Each major revision
                                       will reset the minor revision field to 0
                                       and each minor revision will increment
                                       this field by 1. */
        } PACKED;
    };

    /**
     * @brief Constructor for PVR_t
     *
     * @param[in] i_word PVR register value.
     */
    PVR_t(const uint32_t i_word = 0)
      : word(i_word) {}

    /**
     * @brief Constant values representing DD levels (4 bits for major version,
     *        4 bits for minor).
     */
    enum DD_t : uint8_t
    {
        DD10 = 0x10,
        DD20 = 0x20
    };

    /**
     * @brief Get PVR DD level
     *
     * @return 8-bit DD level (4 bits major version, 4 bits minor)
     */
    DD_t getDDLevel() const
    {
        return static_cast<DD_t>((majorDD << 4) | minorDD);
    }

    /**
     * @brief Check whether the current DD level is DD1.0
     *
     * @return True if and only if the current DD level is DD1.0
     */
    bool isP10DD10() const
    {
        return (chipFamily == P10)
            && (getDDLevel() == DD10);
    }

    /**
     * @brief Check whether the current DD level is DD2.0
     *
     * @return True if and only if the current DD level is DD2.0
     */
    bool isP10DD20() const
    {
        return (chipFamily == P10)
            && (getDDLevel() == DD20);
    }
};

#endif //_PVRFORMAT_H
