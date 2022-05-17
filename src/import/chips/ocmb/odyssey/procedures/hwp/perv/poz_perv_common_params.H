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
static const MulticastGroup MCGROUP_2 = MCGROUP_GOOD_NO_TP;
static const MulticastGroup MCGROUP_4 = MCGROUP_GOOD_PCI;
static const MulticastGroup MCGROUP_6 = MCGROUP_GOOD;
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
    FSI2PCB = 16,
    PIB2PCB = 18,
    PCB2PCB = 19,
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

struct bist_params
{
    char program[16];                    ///< Name of program for image selection
    char ring_patch[16];                 ///< Name of patch ring image
    uint64_t chiplets;                   ///< Mask of chiplets to test

    /// Option flags
    enum bist_flags : uint32_t
    {
        ABIST_NOT_LBIST   = 0x80000000,
        DO_SCAN0          = 0x40000000,
        DO_ARRAYINIT      = 0x20000000,
        DO_RING_SETUP     = 0x10000000,
        DO_RING_PATCH     = 0x08000000,
        DO_REG_SETUP      = 0x04000000,
        DO_GO             = 0x02000000,
        DO_POLL           = 0x01000000,
        DO_REG_CLEANUP    = 0x00800000,
        DO_COMPARE        = 0x00400000,
        SCAN0_REPR        = 0x00200000,
        SKIP_FIRST_CLOCK  = 0x00100000,
        SKIP_LAST_CLOCK   = 0x00080000,
        UNICAST_GO        = 0x00040000,  ///< Trigger OPCG_GO via unicast as opposed to multicast
        POLL_ABIST_DONE   = 0x00020000,  ///< Poll on ABIST_DONE in addition to OPCG_DONE and external abort scratch register
    } flags;

    uint64_t opcg_count;                    ///< Amount of total RUNN cycles to clock - 0 means infinite / until ABIST_DONE
    uint64_t idle_count;                    ///< Base idle RUNN cycles before BIST starts on any chiplet
    uint64_t linear_stagger;                ///< Increase idle count by this much for each successive chiplet
    uint64_t zigzag_stagger;                ///< Increase idle count by this much on any odd chiplet
    uint32_t timeout;                       ///< Polling timeout in microseconds; not guaranteed to be exact!
    uint16_t regions;                       ///< Mask of clock regions to test (TODO make this a 26-index array (one per pervasive address))


    //    final_idle_count = idle_count + (linear_stagger * target_number) + (zigzag_stagger * (target_number & 1));

    //  no burnin type, that is handled by providing different setup and check image names
    //  no DTS mode, that shall be handled by outside code

    // TODO: Add LBIST parameters
};

constexpr bist_params::bist_flags operator|(const bist_params::bist_flags a, const bist_params::bist_flags b)
{
    return static_cast<bist_params::bist_flags>(static_cast<uint16_t>(a) | static_cast<uint16_t>(b));
}
