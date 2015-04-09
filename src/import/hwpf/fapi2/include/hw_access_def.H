/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: $                                                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
///
/// @file hw_access_def.H
/// @brief Hardware access definitions
///

#ifndef FAPI2_HWACCESSDEF_H_
#define FAPI2_HWACCESSDEF_H_

#include <stdint.h>

/// @cond
typedef uint64_t spyId_t;
typedef uint64_t scanRingId_t;
/// @endcond

namespace fapi2
{
    ///
    /// @enum fapi2::ChipOpModifyMode
    /// @brief Enumeration of modify modes used in HW access modify operations
    ///
    enum ChipOpModifyMode
    {
        CHIP_OP_MODIFY_MODE_OR = 1,  ///< Modify or mode
        CHIP_OP_MODIFY_MODE_AND = 2, ///< Modify and mode
        CHIP_OP_MODIFY_MODE_XOR = 3, ///< Modify xor mode
    };

    ///
    /// @enum fapi2::RingMode
    /// @brief Enumeration of Ring access operation modes
    ///        This is a bitmap to allow the user to specify multiple modes.
    ///
    enum RingMode
    {
        RING_MODE_SET_PULSE       = 0x00000001, ///< Set pulse
        RING_MODE_NO_HEADER_CHECK = 0x00000002, ///< Dont' check header
        // FUTURE_MODE            = 0x00000004,
        // FUTURE_MODE            = 0x00000008,
    };

    /// @enum OpModes operational Mode Error Functions
    enum OpModes
    {
        // These are bit-masks in case they need to be or'd together
        NORMAL           = 0x00,
        IGNORE_HW_ERROR  = 0x01,
        DO_NOT_DO_WAKEUP = 0x02,
    };

}

#endif
