/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/scominfo/p9_scominfo.H $           */
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
///
/// @file p9_scominfo.H
/// @brief P9 chip unit SCOM address platform translation code
///
/// HWP HWP Owner: jmcgill@us.ibm.com
/// HWP FW Owner: dcrowell@us.ibm.com
/// HWP Team: Infrastructure
/// HWP Level: 1
/// HWP Consumed by: FSP/HB
///

#ifndef P9_SCOMINFO_H
#define P9_SCOMINFO_H

// includes
#include <stdint.h>
#include <vector>
#include "p9_cu.H"

extern "C"
{

    static const uint32_t PPE_MODE = 1;

    typedef enum
    {
        STANDARD_MODE = 0
    } p9TranslationMode_t;

    typedef enum
    {
        FAILED_TRANSLATION = 0xFFFFFFFFFFFFFFF1ull
    } p9TranslationResult_t;

    /// @brief Creates the actual SCOM address based on the chip unit type, instance, and the input SCOM address (relative to chip unit instance 0)
    /// @param[in] i_p9CU Enumeration of the chip unit type
    /// @param[in] i_chipUnitNum Instance number of the chip unit
    /// @param[in] i_scomAddr The input SCOM address associated with the chip unit type
    /// @param[in] i_mode Used for special purposes, default to 0
    /// @retval uint64_t Actual SCOM address for the chip unit instance passed in
    uint64_t p9_scominfo_createChipUnitScomAddr(const p9ChipUnits_t i_p9CU, const uint8_t i_chipUnitNum,
            const uint64_t i_scomAddr, const uint32_t i_mode = 0);

    /// @brief Determine if the provided SCOM address correlates to any chip units (if so creates a list of chipUnitPairing structures which correspond)
    /// @param[in] i_scomAddr SCOM address to be tested
    /// @param[out] o_chipUnitRelated Returns true if SCOM address is associated with any chip units
    /// @param[out] o_chipUnitPairing Collection of chipUnitPairing enums
    /// @param[in] i_mode Used for special purposes, default to 0
    /// @retval uint32_t Return non-zero for error
    uint32_t p9_scominfo_isChipUnitScom(const uint64_t i_scomAddr, bool& o_chipUnitRelated,
                                        std::vector<p9_chipUnitPairing_t>& o_chipUnitPairing, const uint32_t i_mode = 0);

} // extern "C"

#endif /* P9_SCOMINFO_H */
