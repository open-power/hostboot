/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_sbe_chiplet_reset.H $ */
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
//------------------------------------------------------------------------------
/// @file  p9_sbe_chiplet_reset.H
///
/// @brief Steps:-
///     1) Identify Partical good chiplet and configure Multicasting register
///     2) Similar way, Configure hang pulse counter for Nest/MC/OBus/XBus/PCIe
///     3) Similar way,  set fence for Nest and MC chiplet
///     4) Similar way,  Reset sys.config and OPCG setting for Nest and MC chiplet in sync mode
///
/// Done
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V. Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Brian Silver <bsilver@us.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


#ifndef _P9_SBE_CHIPLET_RESET_H_
#define _P9_SBE_CHIPLET_RESET_H_


#include <fapi2.H>


namespace p9SbeChipletReset
{
enum P9_SBE_CHIPLET_RESET_Public_Constants
{
    MCGR0_CNFG_SETTINGS = 0xE0001C0000000000ull,
    MCGR1_CNFG_SETTINGS = 0xE4001C0000000000ull,
    MCGR2_CNFG_SETTINGS = 0xE8001C0000000000ull,
    MCGR3_CNFG_SETTINGS = 0xEC001C0000000000ull,
    NET_CNTL0_HW_INIT_VALUE = 0x7C16222000000000ull,
    HANG_PULSE_0X10 = 0x10,
    HANG_PULSE_0X0F = 0x0F,
    HANG_PULSE_0X06 = 0x06,
    HANG_PULSE_0X17 = 0x18,
    HANG_PULSE_0X18 = 0x18,
    HANG_PULSE_0X22 = 0x22,
    HANG_PULSE_0X13 = 0x13,
    HANG_PULSE_0X03 = 0x03,
    OPCG_ALIGN_SETTING = 0x5000000000003020ull,
    INOP_ALIGN_SETTING_0X5 = 0x5,
    OPCG_WAIT_CYCLE_0X020 = 0x020,
    SCAN_RATIO_0X3 = 0x3,
    SYNC_PULSE_DELAY_0X0 = 0X00,
    SYNC_CONFIG_DEFAULT = 0X0000000000000000,
    HANG_PULSE_0X00 = 0x00,
    HANG_PULSE_0X01 = 0x01,
    HANG_PULSE_0X04 = 0x04,
    HANG_PULSE_0X1A = 0x1A,
    NET_CNTL1_HW_INIT_VALUE = 0x7200000000000000ull,
    MCGR2_CACHE_CNFG_SETTINGS = 0xF0001C0000000000ull,
    MCGR3_CACHE_CNFG_SETTINGS = 0xF4001C0000000000ull,
    MCGR4_CACHE_CNFG_SETTINGS = 0xF8001C0000000000ull,
    REGIONS_EXCEPT_VITAL = 0x7FF,
    SCAN_TYPES_EXCEPT_TIME_GPTR_REPR = 0xDCE,
    SCAN_TYPES_TIME_GPTR_REPR = 0x230,
    SCAN_RATIO_0X0 = 0x0,
    SYNC_CONFIG_4TO1 = 0X0800000000000000,
    HW_NS_DELAY = 200000, // unit is nano seconds
    SIM_CYCLE_DELAY = 10000 // unit is cycles
};
}

typedef fapi2::ReturnCode (*p9_sbe_chiplet_reset_FP_t)(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

/// @brief Identify all good chiplets excluding EQ/EC
///  -- All chiplets will be reset and PLLs started
///  -- Partial bad - All nest Chiplets must be good, MC, IO can be partial bad
/// Setup multicast groups for all chiplets
///  -- Can't use the multicast for all non-nest chiplets
///  -- This is intended to be the eventual product setting
///  -- This includes the core/cache chiplets
/// For all good chiplets excluding EQ/EC
/// -- Setup Chiplet GP3 regs
///  -- Reset to default state
///  -- Set chiplet enable on all all good chiplets excluding EQ/EC
/// For all enabled chiplets excluding EQ/EC/Buses
///  -- Start vital clocks and release endpoint reset
///  -- PCB Slave error register Reset
///
///
/// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p9_sbe_chiplet_reset(const
                                           fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip);
}

fapi2::ReturnCode p9_sbe_chiplet_reset_pcie_iop_logic_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chip);

#endif
