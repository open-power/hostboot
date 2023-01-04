/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/poz_perv_common_params.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
//------------------------------------------------------------------------------
/// @file  poz_perv_common_params.H
/// @brief Common parameters used by pervasive module code
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#pragma once

#include <multicast_group_defs.H>
#include <target_filters.H>

namespace fapi2
{
static const MulticastGroup MCGROUP_1 = MCGROUP_GOOD;
static const MulticastGroup MCGROUP_2 = MCGROUP_GOOD_NO_TP;
static const MulticastGroup MCGROUP_4 = MCGROUP_GOOD_IOHS;
static const MulticastGroup MCGROUP_5 = MCGROUP_GOOD_PAU;
static const MulticastGroup MCGROUP_6 = MCGROUP_GOOD_PCI;
}

namespace fapi2
{
static const TargetFilter TARGET_FILTER_NEST = TARGET_FILTER_MC;
}

namespace pll
{
enum pll_lock_bits
{
    ALL_PLLS            = 0xFF,

    ODY_PERV_PLLMC      = 0x02,
};
};

namespace cc
{
constexpr uint16_t REGION(const int number)
{
    return 0x8000 >> number;
};

enum clock_region
{

    REGION_PERV = REGION(0),
    REGION_PLL  = REGION(13),

    REGION_ALL  = 0xFFFE,
    REGION_ALL_BUT_PLL = REGION_ALL & ~REGION_PLL,
    REGION_ALL_BUT_PERV_PLL = REGION_ALL & ~REGION_PERV & ~REGION_PLL,

    ODY_PERV_PERV = REGION(0),
    ODY_PERV_SBE = REGION(1),
    ODY_PERV_PIB = REGION(2),
    ODY_PERV_NET = REGION(3),
    ODY_PERV_PLLMC = REGION(13),

    ODY_MC_PERV = REGION(0),
    ODY_MC_IOO = REGION(1),
    ODY_MC_CORE = REGION(2),
    ODY_MC_CFG = REGION(3),
    ODY_MC_DFI = REGION(4),
    ODY_MC_PUB0 = REGION(5),
    ODY_MC_PUB1 = REGION(6),
    ODY_MC_PRIM0 = REGION(13),
    ODY_MC_PRIM1 = REGION(14),
};

enum clock_type
{
    CLOCK_TYPE_SL  = 0x8,
    CLOCK_TYPE_NSL = 0x4,
    CLOCK_TYPE_ARY = 0x2,
    CLOCK_TYPE_ALL = 0xE,
};

enum scan_type
{
    SCAN_TYPE_FUNC = 0x800 >> 0,
    SCAN_TYPE_MODE = 0x800 >> 1,
    SCAN_TYPE_GPTR = 0x800 >> 2,
    SCAN_TYPE_REGF = 0x800 >> 3,
    SCAN_TYPE_LBST = 0x800 >> 4,
    SCAN_TYPE_ABST = 0x800 >> 5,
    SCAN_TYPE_REPR = 0x800 >> 6,
    SCAN_TYPE_TIME = 0x800 >> 7,
    SCAN_TYPE_BNDY = 0x800 >> 8,
    SCAN_TYPE_FARR = 0x800 >> 9,
    SCAN_TYPE_CMSK = 0x800 >> 10,
    SCAN_TYPE_INEX = 0x800 >> 11,
    SCAN_TYPE_ALL  = 0xFFF,
    SCAN_TYPE_RTG  = 0x230,  // repr+time+gptr
    SCAN_TYPE_NOT_RTG = 0xDCF,
    SCAN_TYPE_NOT_REPR = 0xFDF,
};
};

namespace mux
{
enum mux_type : int
{
    FSI2PCB = 16, ///< Direct connection between FSI2PIB engine and TP chiplet, PIB+PCB bypassed
    PIB2PCB = 18, ///< Direct connection between PIB and TP chiplet, PCB bypassed
    PCB2PCB = 19, ///< Normal operation, all chiplet requests go through PCB
    I2C2PCB = 24, ///< Odyssey only, direct connection between I2C responder and TP chiplet, LBUS+PIB+PCB bypassed
};
};

/* Odyssey is super boring since it only has two chiplets and both are at the same level */
const uint8_t ody_chiplet_delay_table[64] = { 0 };

enum chiplet_type : uint8_t
{
    NO_CHIPLET = 0xFF,
};

#define ODY_SUPPORT 0

/// @brief Describes a hang pulse configuration
struct hang_pulse_t
{
    uint16_t id            : 4; ///< Hang pulse number to program
    uint16_t value         : 8; ///< Frequency value for this hang pulse
    uint16_t stop_on_xstop : 1; ///< Hang pulse should stop when a checkstop comes in
    uint16_t               : 2;
    uint16_t last          : 1; ///< Set to 1 for the last entry in an array of this struct
};

/// @brief Describes a constant hang pulse configuration
struct constant_hang_pulse_t
{
    uint16_t pre_divider   : 8; ///< Pre-divider for this hang pulse
    uint16_t value         : 6; ///< Frequency value for this hang pulse
    uint16_t stop_on_xstop : 1; ///< Hang pulse should stop when a checkstop comes in
};
