/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_enable_4u_settings.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file pmic_enable_4u_settings.H
/// @brief PMIC 4U Settings to program
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#ifndef __PMIC_ENABLE_4U_SETTINGS_H__
#define __PMIC_ENABLE_4U_SETTINGS_H__

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>

using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
using TPS_CONSTS = mss::pmic::consts<mss::pmic::product::TPS5383X>;

// Nominal voltages, will be offset by SPD/EFD offsets

///
/// @brief PMIC0 nominal voltages
///
const std::vector<uint8_t> PMIC0_NOMINALS =
{
    0xA0, // SWA 1.2V
    0xA0, // SWB 1.2V
    0x3C, // SWC 0.95V
    0x78  // SWD 2.5V
};

// This is handy for determining nominal in pmic_bias_tool.
static constexpr uint8_t PMIC0_SWD_RANGE = 1;

///
/// @brief PMIC1 nominal voltages
///
const std::vector<uint8_t> PMIC1_NOMINALS =
{
    0xA0, // SWA 1.2V
    0xA0, // SWB 1.2V
    0x08, // SWC 0.82V
    0x00  // SWD 0.0V
};

// This is handy for determining nominal in pmic_bias_tool.
static constexpr uint8_t PMIC1_SWD_RANGE = 0;

///
/// @brief Settings for PMIC 0/2
/// @note these can directly be looped over and written to the PMIC
///
const std::vector<std::pair<uint8_t, uint8_t>> PMIC0_SETTINGS =
{
    // ADC Enable, VIN_BULK reading
    {REGS::R30, 0xA8},

    // Clear status regs
    {REGS::R14, 0x01},

    // LSB - SWD voltage range max
    // Conveniently, the SWD range bit is the LSB, so we can or it with the constant
    {REGS::R2B, 0b01000100 | PMIC0_SWD_RANGE},

    // ADC Enable, VIN_BULK reading
    {REGS::R30, 0xA8},

    // PMIC Diagnostic Mode
    {REGS::R2F, 0x06},

    // Current limiter warnings
    {REGS::R1C, 0xA0},
    {REGS::R1D, 0xA0},
    {REGS::R1E, 0x80},
    {REGS::R1F, 0x80},

    // Startup sequences, to be populated in the future if needed
    // {},

    // Soft start
    {REGS::R2C, CONSTS::R2C_R2D_4MS_ALL},
    {REGS::R2D, CONSTS::R2C_R2D_4MS_ALL},

    // Host region soft start 4ms, max undervoltage lockout tolerance
    {REGS::R22, 0b01101111},
    {REGS::R24, 0b01101111},
    {REGS::R26, 0b01101111},
    {REGS::R28, 0b01101111},

    // TPS region soft stop
    {TPS_REGS::R94_SOFT_STOP_CFG_SWA, TPS_CONSTS::MAX_SOFT_STOP_CFG},
    {TPS_REGS::R95_SOFT_STOP_CFG_SWB, TPS_CONSTS::MAX_SOFT_STOP_CFG},
    {TPS_REGS::R96_SOFT_STOP_CFG_SWC, TPS_CONSTS::MAX_SOFT_STOP_CFG},
    {TPS_REGS::R97_SOFT_STOP_CFG_SWD, TPS_CONSTS::MAX_SOFT_STOP_CFG},

    // VR Disable
    {REGS::R32, 0x00},
    {REGS::R32, 0x80},
    {REGS::R32, 0x00},
};

///
/// @brief Settings for PMIC 1/3
/// @note these can directly be looped over and written to the PMIC
///
const std::vector<std::pair<uint8_t, uint8_t>> PMIC1_SETTINGS =
{
    // ADC Enable, VIN_BULK reading
    {REGS::R30, 0xA8},

    // Clear status regs
    {REGS::R14, 0x01},

    // ADC Enable, VIN_BULK reading
    {REGS::R30, 0xA8},

    // PMIC Diagnostic Mode
    {REGS::R2F, 0x06},

    // Current limiter warnings
    {REGS::R1C, 0xA0},
    {REGS::R1D, 0xA0},
    {REGS::R1E, 0x80},
    {REGS::R1F, 0x80},

    // Startup sequences, to be populated in the future if needed
    // {},

    // Soft start
    {REGS::R2C, CONSTS::R2C_R2D_4MS_ALL},
    {REGS::R2D, CONSTS::R2C_R2D_4MS_ALL},

    // Host region soft start 4ms, max undervoltage lockout tolerance
    {REGS::R22, 0b01101111},
    {REGS::R24, 0b01101111},
    {REGS::R26, 0b01101111},
    {REGS::R28, 0b01101111},

    // TPS region soft stop
    {TPS_REGS::R94_SOFT_STOP_CFG_SWA, TPS_CONSTS::MAX_SOFT_STOP_CFG},
    {TPS_REGS::R95_SOFT_STOP_CFG_SWB, TPS_CONSTS::MAX_SOFT_STOP_CFG},
    {TPS_REGS::R96_SOFT_STOP_CFG_SWC, TPS_CONSTS::MAX_SOFT_STOP_CFG},
    {TPS_REGS::R97_SOFT_STOP_CFG_SWD, TPS_CONSTS::MAX_SOFT_STOP_CFG},

    // VR Disable
    {REGS::R32, 0x00},
    {REGS::R32, 0x80},
    {REGS::R32, 0x00},
};

#endif
