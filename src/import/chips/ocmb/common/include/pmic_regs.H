/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/include/pmic_regs.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file pmic_regs.H
/// @brief PMIC Registers
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __PMIC_REGS__
#define __PMIC_REGS__

#include <lib/utils/pmic_consts.H>

///
/// @brief Registers for PMIC devices
/// @class pmicRegs
/// @tparam P pmic_product
///
template<mss::pmic::product P>
struct pmicRegs;


///
/// @brief Registers for TPS53830/1 PMICS
///
template<>
struct pmicRegs<mss::pmic::product::TPS5383X>
{
    static constexpr uint8_t R94_SOFT_START_CFG_SWA = 0x94;
    static constexpr uint8_t R95_SOFT_START_CFG_SWB = 0x95;
    static constexpr uint8_t R96_SOFT_START_CFG_SWC = 0x96;
    static constexpr uint8_t R97_SOFT_START_CFG_SWD = 0x97;

    static constexpr uint8_t R9C_ON_OFF_CONFIG_GLOBAL = 0x9C;
};

///
/// @brief JEDEC Common Registers
/// @note These registers are not defined with any particular name other than RXX.
/// Their purposes and bit-mappings are outlined in any of the JEDEC compliant PMIC specs.
///
template<>
struct pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>
{
    static constexpr uint8_t BROADCAST                           = 0x0;
    /* R00 - R03 RESERVED */
    static constexpr uint8_t R04                                 = 0x04;
    static constexpr uint8_t R05                                 = 0x05;
    static constexpr uint8_t R06                                 = 0x06;
    /* R07 RESERVED */
    static constexpr uint8_t R08                                 = 0x08;
    static constexpr uint8_t R09                                 = 0x09;
    static constexpr uint8_t R0A                                 = 0x0A;
    static constexpr uint8_t R0B                                 = 0x0B;
    static constexpr uint8_t R0C                                 = 0x0C;
    static constexpr uint8_t R0D                                 = 0x0D;
    static constexpr uint8_t R0E                                 = 0x0E;
    static constexpr uint8_t R0F                                 = 0x0F;
    static constexpr uint8_t R10                                 = 0x10;
    static constexpr uint8_t R11                                 = 0x11;
    static constexpr uint8_t R12                                 = 0x12;
    static constexpr uint8_t R13                                 = 0x13;
    static constexpr uint8_t R14                                 = 0x14;
    static constexpr uint8_t R15                                 = 0x15;
    static constexpr uint8_t R16                                 = 0x16;
    static constexpr uint8_t R17                                 = 0x17;
    static constexpr uint8_t R18                                 = 0x18;
    static constexpr uint8_t R19                                 = 0x19;
    static constexpr uint8_t R1A                                 = 0x1A;
    static constexpr uint8_t R1B                                 = 0x1B;
    static constexpr uint8_t R1C                                 = 0x1C;
    static constexpr uint8_t R1D                                 = 0x1D;
    static constexpr uint8_t R1E                                 = 0x1E;
    static constexpr uint8_t R1F                                 = 0x1F;
    static constexpr uint8_t R20                                 = 0x20;
    static constexpr uint8_t R21_SWA_VOLTAGE_SETTING             = 0x21;
    static constexpr uint8_t R22                                 = 0x22;
    static constexpr uint8_t R23_SWB_VOLTAGE_SETTING             = 0x23;
    static constexpr uint8_t R24                                 = 0x24;
    static constexpr uint8_t R25_SWC_VOLTAGE_SETTING             = 0x25;
    static constexpr uint8_t R26                                 = 0x26;
    static constexpr uint8_t R27_SWD_VOLTAGE_SETTING             = 0x27;
    static constexpr uint8_t R28                                 = 0x28;
    static constexpr uint8_t R29                                 = 0x29;
    static constexpr uint8_t R2A                                 = 0x2A;
    static constexpr uint8_t R2B                                 = 0x2B;
    static constexpr uint8_t R2C                                 = 0x2C;
    static constexpr uint8_t R2D                                 = 0x2D;
    static constexpr uint8_t R2E                                 = 0x2E;
    static constexpr uint8_t R2F                                 = 0x2F;
    static constexpr uint8_t R30                                 = 0x30;
    static constexpr uint8_t R31                                 = 0x31;
    static constexpr uint8_t R32                                 = 0x32;
    static constexpr uint8_t R33                                 = 0x33;
    static constexpr uint8_t R34                                 = 0x34;
    static constexpr uint8_t R35                                 = 0x35;
    /* R36 RESERVED */
    static constexpr uint8_t R37_PASSWORD_LOWER_BYTE_0           = 0x37;
    static constexpr uint8_t R38_PASSWORD_UPPER_BYTE_1           = 0x38;
    static constexpr uint8_t R39_COMMAND_CODES                   = 0x39;
    static constexpr uint8_t R3A                                 = 0x3A;
    static constexpr uint8_t R3B_REVISION                        = 0x3B;
    static constexpr uint8_t R3C_VENDOR_ID_BYTE_0                = 0x3C;
    static constexpr uint8_t R3D_VENDOR_ID_BYTE_1                = 0x3D;

    /* ----- DIMM VENDOR REGION ----- */

    /* R3E - R3F RESERVED */
    static constexpr uint8_t R40_POWER_ON_SEQUENCE_CONFIG_1      = 0x40;
    static constexpr uint8_t R41_POWER_ON_SEQUENCE_CONFIG_2      = 0x41;
    static constexpr uint8_t R42_POWER_ON_SEQUENCE_CONFIG_3      = 0x42;
    static constexpr uint8_t R43_POWER_ON_SEQUENCE_CONFIG_4      = 0x43;
    /* R44 RESERVED */
    static constexpr uint8_t R45_SWA_VOLTAGE_SETTING             = 0x45;
    static constexpr uint8_t R46                                 = 0x46;
    static constexpr uint8_t R47_SWB_VOLTAGE_SETTING             = 0x47;
    static constexpr uint8_t R48                                 = 0x48;
    static constexpr uint8_t R49_SWC_VOLTAGE_SETTING             = 0x49;
    static constexpr uint8_t R4A                                 = 0x4A;
    static constexpr uint8_t R4B_SWD_VOLTAGE_SETTING             = 0x4B;
    static constexpr uint8_t R4C                                 = 0x4C;
    static constexpr uint8_t R4D                                 = 0x4D;
    static constexpr uint8_t R4E                                 = 0x4E;
    static constexpr uint8_t R4F                                 = 0x4F;
    static constexpr uint8_t R50                                 = 0x50;
    static constexpr uint8_t R51                                 = 0x51;
    /* R52 - R57 RESERVED */
    static constexpr uint8_t R58_POWER_OFF_SEQUENCE_CONFIG_1     = 0x58;
    static constexpr uint8_t R59_POWER_OFF_SEQUENCE_CONFIG_2     = 0x59;
    static constexpr uint8_t R5A_POWER_OFF_SEQUENCE_CONFIG_3     = 0x5A;
    static constexpr uint8_t R5B_POWER_OFF_SEQUENCE_CONFIG_4     = 0x5B;
    /* R5C RESERVED */
    static constexpr uint8_t R5D                                 = 0x5D;
    static constexpr uint8_t R5E                                 = 0x5E;
    static constexpr uint8_t R5F_PRIMARY_INFERFACE_IO_TYPE       = 0x5F;
    /* R60 - R6C RESERVED */
    static constexpr uint8_t R6D                                 = 0x6D;
    static constexpr uint8_t R6E                                 = 0x6E;
    /* R6F RESERVED */
};

#endif
