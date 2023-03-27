/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/scominfo/odyssey_scominfo.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
/// @file odyssey_scominfo.H
/// @brief ODYSSEY chip unit SCOM address platform translation code
///
/// HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// HWP FW Maintainer:
/// HWP Consumed by: Cronus, HB
///

#ifndef ODYSSEY_SCOMINFO_H
#define ODYSSEY_SCOMINFO_H

// includes
#include <stdint.h>
#include <vector>
#include "odyssey_cu.H"

extern "C"
{
    // Modes of translation
    typedef enum
    {
        ODYSSEY_DEFAULT_MODE = 0,       // Default platform behavior
        ODYSSEY_ENGD_BUILD_MODE = 1,    // Apply customization for ENGD build
    } odysseyTranslationMode_t;

    typedef enum
    {
        FAILED_TRANSLATION = 0xFFFFFFFFFFFFFFF1ull
    } odysseyTranslationResult_t;

    /// @brief Creates the actual SCOM address based on the chip unit type, instance, and the input SCOM address (relative to chip unit instance 0)
    /// @param[in] i_odysseyCU    Enumeration of the chip unit type
    /// @param[in] i_ecLevel      Chip EC level represented in HEX digit value.  Example: i_ecLevel = 0x12 --> EC level 1.2
    /// @param[in] i_chipUnitNum  Instance number of the chip unit
    /// @param[in] i_scomAddr     The input SCOM address associated with the chip unit type
    /// @param[in] i_mode         Translation mode, specifying different addr translation methods.
    /// @retval uint64_t Actual SCOM address for the chip unit instance passed in
    uint64_t odyssey_scominfo_createChipUnitScomAddr(const odysseyChipUnits_t i_odysseyCU,
            const uint8_t i_ecLevel,
            const uint8_t i_chipUnitNum,
            const uint64_t i_scomAddr,
            const odysseyTranslationMode_t i_mode = ODYSSEY_DEFAULT_MODE);

    /// @brief Determine if the provided SCOM address correlates to any chip units (if so creates a list of chipUnitPairing structures which correspond)
    /// @param[in] i_odysseyCU          Enumeration of the chip unit type
    /// @param[in] i_ecLevel            Chip EC level represented in HEX digit value.  Example: i_ecLevel = 0x12 --> EC level 1.2
    /// @param[in] i_scomAddr           SCOM address to be tested
    /// @param[out] o_chipUnitRelated   Returns true if SCOM address is associated with any chip units
    /// @param[out] o_chipUnitPairing   Collection of chipUnitPairing enums
    /// @param[in] i_mode               Translation mode, specifying different addr translation methods.
    /// @retval uint32_t Return non-zero for error
    uint32_t odyssey_scominfo_isChipUnitScom(const odysseyChipUnits_t i_odysseyCU,
            const uint8_t i_ecLevel,
            const uint64_t i_scomAddr,
            bool& o_chipUnitRelated,
            std::vector<odyssey_chipUnitPairing_t>& o_chipUnitPairing,
            const odysseyTranslationMode_t i_mode = ODYSSEY_DEFAULT_MODE);

    /// @brief Qualify/screen indirect SCOM status data returned based on address requested
    ///        In general, platform code expects both the user status (bits 36:39) and PCB status (bits 32:35) are zero for a successful transaction.
    ///        This function is intended to permit per-address masking of the raw user status field to mask out benign status reporting bits that enter the
    ///        user status field, before the platform check is conducted.
    /// @param[in] i_ecLevel            Chip EC level represented in HEX digit value.  Example: i_ecLevel = 0x12 --> EC level 1.2
    /// @param[in] i_scomAddr           Fully translated/physical address associated with indirect access
    /// @param[in] i_indirectStatus     Raw indirect status data collected by platform
    /// @retval uint64_t Filtered indirect status data for platform checking
    uint64_t odyssey_scominfo_screenIndirectStatus(const uint8_t i_ecLevel,
            const uint64_t i_scomAddr,
            const uint64_t i_indirectStatus);

    /// @brief Alter the unit/unitnum of a target for spys where the clocks-on vs clocks-off targets are different.
    /// @param[in] i_odysseyCU            Target used for the spy request
    /// @param[in] i_ecLevel              Chip EC level represented in HEX digit value.  Example: i_ecLevel = 0x12 --> EC level 1.2
    /// @param[in] i_targetChipUnitNum    The instance number of the target used for the spy request
    /// @param[in] i_scomaddr             The scom from the clocks-on portion of the spy
    /// @param[out] o_modifiedScomAddr    The translated scom address (none may be needed)
    /// @param[out] o_odysseyCU           The translated target type
    /// @param[out] o_modifiedChipUnitNum The translated target instance number
    /// @param[in] i_mode                 Translation mode, specifying different addr translation methods.
    /// @retval uint32_t Return non-zero for error
    uint32_t odyssey_scominfo_fixChipUnitScomAddrOrTarget(const odysseyChipUnits_t i_odysseyCU,
            const uint8_t i_ecLevel,
            const uint32_t i_targetChipUnitNum,
            const uint64_t i_scomaddr,
            uint64_t& o_modifiedScomAddr,
            odysseyChipUnits_t& o_odysseyCU,
            uint32_t& o_modifiedChipUnitNum,
            const odysseyTranslationMode_t i_mode = ODYSSEY_DEFAULT_MODE);

} // extern "C"

#endif /* ODYSSEY_SCOMINFO_H */
