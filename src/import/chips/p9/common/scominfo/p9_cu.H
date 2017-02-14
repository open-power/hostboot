/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/scominfo/p9_cu.H $                 */
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
/// @file p9_cu.H
/// @brief P9 chip unit definitions
///
/// HWP HWP Owner: jmcgill@us.ibm.com
/// HWP FW Owner: dcrowell@us.ibm.com
/// HWP Team: Infrastructure
/// HWP Level: 2
/// HWP Consumed by: FSP/HB
///

#ifndef P9_CU_H
#define P9_CU_H

// includes
#include <stdint.h>

extern "C"
{

    /// P9 chip unit type enumeration
    typedef enum
    {
        P9C_CHIP,            ///< Cumulus chip (included for future expansion)
        P9N_CHIP,            ///< Nimbus chip (included for future expansion)
        PU_C_CHIPUNIT,       ///< Core
        PU_EQ_CHIPUNIT,      ///< Quad
        PU_EX_CHIPUNIT,      ///< EX
        PU_XBUS_CHIPUNIT,    ///< XBUS
        PU_OBUS_CHIPUNIT,    ///< OBUS
        PU_NV_CHIPUNIT,      ///< NV Link Brick
        PU_PEC_CHIPUNIT,     ///< PCIe (PEC)
        PU_PHB_CHIPUNIT,     ///< PCIe (PHB)
        PU_MI_CHIPUNIT,      ///< MI (Cumulus only)
        PU_DMI_CHIPUNIT,     ///< DMI (Cumulus only)
        PU_MCS_CHIPUNIT,     ///< MCS (Nimbus only)
        PU_MCA_CHIPUNIT,     ///< MCA (Nimbus only)
        PU_MCBIST_CHIPUNIT,  ///< MCBIST (Nimbus only)
        PU_PERV_CHIPUNIT,    ///< Pervasive
        PU_PPE_CHIPUNIT,     ///< PPE
        PU_SBE_CHIPUNIT,     ///< SBE
        PU_CAPP_CHIPUNIT,    ///< CAPP
        NONE,                ///< None/Invalid
    } p9ChipUnits_t;

    /// P9 chip unit pairing struct
    struct p9_chipUnitPairing_t
    {
        /// @brief Default constructor
        p9_chipUnitPairing_t()
            : chipUnitType(NONE), chipUnitNum(0) {}
        /// @brief Construct from type/instance number
        p9_chipUnitPairing_t (p9ChipUnits_t type, uint32_t num)
            : chipUnitType(type), chipUnitNum(num) {}

        p9ChipUnits_t chipUnitType;  ///< chip unit type
        uint32_t chipUnitNum;        ///< chip unit instance number
    };

    /// P9 PPE Chip Unit Instance Number enumeration
    /// PPE name        Nimbus    Cumulus
    /// SBE             0         0
    /// GPE0..3         10..13    10..13
    /// CME0            20..25    20..25
    /// CME1            30..35    30..35
    /// IO PPE (xbus)   40        40
    /// IO PPE (obus)   41,42     41,42
    /// IO PPE (dmi)    NA        43,44
    /// Powerbus PPEs   50        50..52
    typedef enum
    {
        PPE_SBE_CHIPUNIT_NUM         =  0,
        PPE_GPE0_CHIPUNIT_NUM        = 10,
        PPE_GPE3_CHIPUNIT_NUM        = 13,
        PPE_EQ0_CME0_CHIPUNIT_NUM    = 20,   // Quad0-CME0
        PPE_EQ5_CME0_CHIPUNIT_NUM    = 25,   // Quad5-CME0
        PPE_EQ0_CME1_CHIPUNIT_NUM    = 30,   // Quad0-CME1
        PPE_EQ5_CME1_CHIPUNIT_NUM    = 35,   // Quad5-CME1
        PPE_IO_XBUS_CHIPUNIT_NUM     = 40,
        PPE_IO_OB0_CHIPUNIT_NUM      = 41,
        PPE_IO_OB1_CHIPUNIT_NUM      = 42,
        PPE_IO1_DMI_CHIPUNIT_NUM     = 44,
        PPE_PB0_CHIPUNIT_NUM         = 50,
        PPE_PB2_CHIPUNIT_NUM         = 52,
        PPE_LAST_CHIPUNIT_NUM        = PPE_PB2_CHIPUNIT_NUM,
    } p9_ppe_chip_unit_instance_num_t;

} // extern "C"

#endif /* P9_CU_H */
