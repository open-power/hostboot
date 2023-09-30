/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/scominfo/odyssey_cu.H $  */
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
/// @file odyssey_cu.H
/// @brief ODYSSEY chip unit definitions
///
/// HWP Owner: thi@us.ibm.com
/// HWP Team: NEST
/// HWP Level: 1
/// HWP Consumed by: Cronus
///

#ifndef ODYSSEY_CU_H
#define ODYSSEY_CU_H

// includes
#include <stdint.h>

extern "C"
{

// DEBUG_PRINT flag can be enabled in odyssey_scom/scan_xlate.mk
// to enable debug print for odyssey's clock, scom, scan code.
#if DEBUG_PRINT
#define dbg_print printf
#else
#define dbg_print(...) /**/
#endif

    /// ODYSSEY chip unit type enumeration
    typedef enum
    {
        ODYSSEY_NO_CU            =  0,           ///< ODYSSEY chip
        ODYSSEY_PERV_CHIPUNIT    =  1,           ///< Pervasive
        ODYSSEY_MEMPORT_CHIPUNIT =  2,
        ODYSSEY_OMI_CHIPUNIT     =  3,
        ODYSSEY_NONE             = 0xFF,         ///< None/Invalid
    } odysseyChipUnits_t;

    /// ODYSSEY chip unit pairing struct
    struct odyssey_chipUnitPairing_t
    {
        /// @brief Default constructor
        odyssey_chipUnitPairing_t()
            : chipUnitType(ODYSSEY_NONE), chipUnitNum(0) {}
        /// @brief Construct from type/instance number
        odyssey_chipUnitPairing_t (odysseyChipUnits_t type, uint32_t num)
            : chipUnitType(type), chipUnitNum(num) {}

        odysseyChipUnits_t chipUnitType;  ///< chip unit type
        uint8_t chipUnitNum;             ///< chip unit instance number
    };

    struct odyssey_chipUnitDescription_t
    {
        const char*          strVal;          // Chip unit string
        const odysseyChipUnits_t enumVal;     // Chip unit enum value
        const uint8_t        maxChipUnitNum;  // Max Chip unit num value
    };


    // Max chip unit positions
    const uint8_t MAX_ODYSSEY_NO_CU             =  0;
    const uint8_t MAX_ODYSSEY_PERV_CHIPUNIT     =  8; // TP memory chiplet ID is 0x08
    const uint8_t MAX_ODYSSEY_MEMPORT_CHIPUNIT  =  1;
    const uint8_t MAX_ODYSSEY_OMI_CHIPUNIT      =  0; // 1 OMI link back to the host proc

    // Chip unit string/enum/max targes table
    const odyssey_chipUnitDescription_t odysseyChipUnitDescriptionTable[] =
    {
        { "odyssey"  , ODYSSEY_NO_CU            , MAX_ODYSSEY_NO_CU            },
        { "perv"     , ODYSSEY_PERV_CHIPUNIT    , MAX_ODYSSEY_PERV_CHIPUNIT    },
        { "mp"       , ODYSSEY_MEMPORT_CHIPUNIT , MAX_ODYSSEY_MEMPORT_CHIPUNIT },
        { "omi"      , ODYSSEY_OMI_CHIPUNIT     , MAX_ODYSSEY_OMI_CHIPUNIT     },
    };

} // extern "C"

#endif /* ODYSSEY_CU_H */
