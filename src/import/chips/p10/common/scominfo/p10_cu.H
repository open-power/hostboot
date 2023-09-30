/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/scominfo/p10_cu.H $               */
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
/// @file p10_cu.H
/// @brief P10 chip unit definitions
///
/// HWP Owner: thi@us.ibm.com
/// HWP Team: NEST
/// HWP Level: 1
/// HWP Consumed by: FSP/HB
///

#ifndef P10_CU_H
#define P10_CU_H

// includes
#include <stdint.h>

extern "C"
{
    /// P10 chip unit type enumeration
    typedef enum
    {
        P10_NO_CU           =  0,           ///< P10 chip
        PU_PERV_CHIPUNIT    =  1,           ///< Pervasive
        PU_EQ_CHIPUNIT      =  2,           ///< Quad
        PU_C_CHIPUNIT       =  3,           ///< Core
        PU_PEC_CHIPUNIT     =  4,           ///< PCIe (PEC)
        PU_PHB_CHIPUNIT     =  5,           ///< PCIe (PHB)
        PU_NMMU_CHIPUNIT    =  6,           ///< NMMU
        PU_IOHS_CHIPUNIT    =  7,           ///< IOHS (High speed IO)
        PU_MC_CHIPUNIT      =  8,           ///< MC
        PU_MI_CHIPUNIT      =  9,           ///< MI
        PU_MCC_CHIPUNIT     = 10,           ///< MCC
        PU_OMI_CHIPUNIT     = 11,           ///< OMI
        PU_OMIC_CHIPUNIT    = 12,           ///< OMIC
        PU_PAU_CHIPUNIT     = 13,           ///< PAU
        PU_PAUC_CHIPUNIT    = 14,           ///< PAUC
        NONE                = 0xFF,         ///< TODO: Remove after HB successfuly built to avoid co-req
        PU_NONE             = 0xFF,         ///< None/Invalid
    } p10ChipUnits_t;

    /// P10 chip unit pairing struct
    struct p10_chipUnitPairing_t
    {
        /// @brief Default constructor
        p10_chipUnitPairing_t()
            : chipUnitType(PU_NONE), chipUnitNum(0) {}
        /// @brief Construct from type/instance number
        p10_chipUnitPairing_t (p10ChipUnits_t type, uint32_t num)
            : chipUnitType(type), chipUnitNum(num) {}

        p10ChipUnits_t chipUnitType;  ///< chip unit type
        uint32_t chipUnitNum;         ///< chip unit instance number
    };

    struct p10_chipUnitDescription_t
    {
        const char*          strVal;          // Chip unit string
        const p10ChipUnits_t enumVal;         // Chip unit enum value
        const uint8_t        maxChipUnitNum;  // Max Chip unit num value
    };


    // Max chip unit positions
    const uint8_t MAX_PU_CHIPUNIT_NUM      =  0;  // P10_NO_CU
    const uint8_t MAX_PU_EQ_CHIPUNIT_NUM   =  7;
    const uint8_t MAX_PU_C_CHIPUNIT_NUM    = 31;
    const uint8_t MAX_PU_PEC_CHIPUNIT_NUM  =  1;
    const uint8_t MAX_PU_PHB_CHIPUNIT_NUM  =  5;
    const uint8_t MAX_PU_NMMU_CHIPUNIT_NUM =  1;
    const uint8_t MAX_PU_PERV_CHIPUNIT_NUM = 39; // Special case, with gaps
    const uint8_t MAX_PU_IOHS_CHIPUNIT_NUM =  7;
    const uint8_t MAX_PU_PAU_CHIPUNIT_NUM  =  7;
    const uint8_t MAX_PU_MC_CHIPUNIT_NUM   =  3;
    const uint8_t MAX_PU_MI_CHIPUNIT_NUM   =  3;
    const uint8_t MAX_PU_MCC_CHIPUNIT_NUM  =  7;
    const uint8_t MAX_PU_OMIC_CHIPUNIT_NUM =  7;
    const uint8_t MAX_PU_OMI_CHIPUNIT_NUM  = 15;
    const uint8_t MAX_PU_PAUC_CHIPUNIT_NUM =  3;

    // Chip unit string/enum/max targes table
    const p10_chipUnitDescription_t ChipUnitDescriptionTable[] =
    {
        { "pu"    , P10_NO_CU,         MAX_PU_CHIPUNIT_NUM       },
        { "eq"    , PU_EQ_CHIPUNIT,    MAX_PU_EQ_CHIPUNIT_NUM    },
        { "c"     , PU_C_CHIPUNIT,     MAX_PU_C_CHIPUNIT_NUM     },
        { "pec"   , PU_PEC_CHIPUNIT,   MAX_PU_PEC_CHIPUNIT_NUM   },
        { "phb"   , PU_PHB_CHIPUNIT,   MAX_PU_PHB_CHIPUNIT_NUM   },
        { "nmmu"  , PU_NMMU_CHIPUNIT,  MAX_PU_NMMU_CHIPUNIT_NUM  },
        { "perv"  , PU_PERV_CHIPUNIT,  MAX_PU_PERV_CHIPUNIT_NUM  },  // Special case, with gaps
        { "iohs"  , PU_IOHS_CHIPUNIT,  MAX_PU_IOHS_CHIPUNIT_NUM  },
        { "mc"    , PU_MC_CHIPUNIT,    MAX_PU_MC_CHIPUNIT_NUM    },
        { "mi"    , PU_MI_CHIPUNIT,    MAX_PU_MI_CHIPUNIT_NUM    },
        { "mcc"   , PU_MCC_CHIPUNIT,   MAX_PU_MCC_CHIPUNIT_NUM   },
        { "omi"   , PU_OMI_CHIPUNIT,   MAX_PU_OMI_CHIPUNIT_NUM   },
        { "omic"  , PU_OMIC_CHIPUNIT,  MAX_PU_OMIC_CHIPUNIT_NUM  },
        { "pau"   , PU_PAU_CHIPUNIT,   MAX_PU_PAU_CHIPUNIT_NUM   },
        { "pauc"  , PU_PAUC_CHIPUNIT,  MAX_PU_PAUC_CHIPUNIT_NUM  },
    };

} // extern "C"

#endif /* P10_CU_H */
