/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/scominfo/p9_scominfo.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

    //Modes for scominfo functions
    static const uint32_t P9N_DD1_SI_MODE = 0x0;
    static const uint32_t PPE_MODE = 0x1;
    static const uint32_t P9N_DD2_SI_MODE = 0x2;
    static const uint32_t P9C_DD1_SI_MODE = 0x4;
    static const uint32_t P9C_DD2_SI_MODE = 0x8;
    static const uint32_t P9A_DD1_SI_MODE = 0x10;
    static const uint32_t P9A_DD2_SI_MODE = 0x20;

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
    /// @param[in] i_mode Used for special purposes, default to 0 = p9n dd1, 1 = ppe_mode, 2 = p9n dd2, 4 = p9c dd1, 8 = p9c dd2
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


    /// @brief Alter the unit/unitnum of a target for spys where the clocks-on vs clocks-off targets are different.
    /// @param[in] i_p9CU target used for the spy request
    /// @param[in] i_targetChipUnitNum the instance number of the target used for the spy request
    /// @param[in] i_scomaddr the scom from the clocks-on portion of the spy
    /// @param[out] o_modifiedScomAddr the translated scom address (none may be needed)
    /// @param[out] o_p9CU the translated target type
    /// @param[out] o_modifiedChipUnitNum the translated target instance number
    /// @param[in] i_mode Could be used in the future to indicate if the translation is from clocks-on or clocks-off state
    /// @retval uint32_t Return non-zero for error
    uint32_t p9_scominfo_fixChipUnitScomAddrOrTarget(const p9ChipUnits_t i_p9CU, const uint32_t i_targetChipUnitNum,
            const uint64_t i_scomaddr, uint64_t& o_modifiedScomAddr, p9ChipUnits_t& o_p9CU,
            uint32_t& o_modifiedChipUnitNum, const uint32_t i_mode = 0);

} // extern "C"

#endif /* P9_SCOMINFO_H */
