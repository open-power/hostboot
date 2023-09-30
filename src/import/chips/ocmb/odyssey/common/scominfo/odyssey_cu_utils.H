/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/scominfo/odyssey_cu_utils.H $ */
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
/// @file odyssey_cu_utils.H
/// @brief ODYSSEY chip unit utility definitions
///
/// HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// HWP FW Maintainer:
/// HWP Consumed by: CRONUS
///

#ifndef ODYSSEY_CU_UTILS_H
#define ODYSSEY_CU_UTILS_H

// includes
#include <string>
#include <odyssey_cu.H>
#include <odyssey_scom_addr.H>

extern "C"
{
    /// @brief Convert chip unit enumeration to string
    /// @param[in] i_ODYSSEY_CU Enumeration of chip unit type
    /// @param[out] o_chipUnitType String description of chip unit type
    /// @retval uint32_t Return non-zero for error
    uint32_t odyssey_convertCUEnum_to_String(const odysseyChipUnits_t i_ODYSSEY_CU,
            std::string& o_chipUnitType);

    /// @brief Convert string description of chip unit type to enumeration
    /// @param[out] i_chipUnitType String description of chip unit type
    /// @param[out] o_ODYSSEY_CU Enumeration of chip unit type
    /// @retval uint32_t Return non-zero for error
    uint32_t odyssey_convertCUString_to_enum(const std::string& i_chipUnitType,
            odysseyChipUnits_t& o_ODYSSEY_CU);

    /// @brief Debug utility that prints out address fields
    /// @param[in] i_addr         Address value
    /// @param[in] i_chipUnitType Chip unit type
    /// @param[in] i_chipEcLevel  Chip EC level
    /// @retval None
    void odyssey_displayAddrFields(uint64_t i_addr,
                                   odysseyChipUnits_t i_chipUnitType,
                                   uint32_t i_chipEcLevel);

} // extern "C"

#endif /* ODYSSEY_CU_UTILS_H */
