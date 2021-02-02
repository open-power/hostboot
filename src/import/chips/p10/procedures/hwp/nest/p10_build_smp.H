/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_build_smp.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_build_smp.H
/// @brief Perform fabric configuration (FAPI2)
///
/// Perform fabric SMP build/reconfiguration operations.
///
/// Platform Notes:
///     This HWP has multiple IPL use cases. In all all cases the HWP input
///     is expected to contain an entry for each chip within the scope of
///     the new SMP to be constructed (with valid attribute state repesenting all
///     active links that are fully contained within the new SMP).
///
///     The p10_build_smp_operation HWP input defines the desired
///     reconfiguration option to be performed:
///
///     SMP_ACTIVATE_PHASE1 (HBI):
///         - configure to join all single chip 'island' fabrics
///           into drawer level SMP
///
///     SMP_ACTIVATE_PHASE2 (FSP):
///         - configure to join collection of drawer level SMPs
///           into full system SMP
///
///     SMP_ACTIVATE_SWITCH:
///         - issues hotplug switch command; separation of this from
///           phase1/2 requested to support secureboot
///
///     SMP_ACTIVATE_POST:
///         - configures fabric settings after a hotplug switch
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, FSP
///

#ifndef _P10_BUILD_SMP_H_
#define _P10_BUILD_SMP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <map>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint8_t P10_BUILD_SMP_MAX_SIZE = 16;

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// HWP argument, define build smp execution modes
// - phase1: used to init scope of hbi drawer, call from hb
// - phase2: used to stitch drawers, call from fsp
// - switch: used to issue hotplug switch command
// - post:   used to apply settings after hotplug switch
enum p10_build_smp_operation
{
    SMP_ACTIVATE_PHASE1 = 1,
    SMP_ACTIVATE_PHASE2 = 2,
    SMP_ACTIVATE_SWITCH = 3,
    SMP_ACTIVATE_POST   = 4
};

// Structure to represent properties for a single chip in the SMP topology
struct p10_build_smp_chip
{
    // associated target handle from HWP input vector
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* target;
    // fabric group/chip ID
    uint8_t group_id;
    uint8_t chip_id;
    // group/system master designation (curr)
    bool master_chip_group_curr;
    bool master_chip_sys_curr;
    // group/system master designation (next)
    bool master_chip_group_next;
    bool master_chip_sys_next;
    bool issue_quiesce_next;
    bool quiesced_next;
};

// Structure to represent properties for a single group in the SMP topology
struct p10_build_smp_group
{
    // chips which reside in this group
    std::map<uint8_t, p10_build_smp_chip> chips;
    // fabric group ID
    uint8_t group_id;
};

// Structure to represent collection of groups in SMP topology
struct p10_build_smp_system
{
    // groups which reside in this SMP
    std::map<uint8_t, p10_build_smp_group> groups;
};

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_build_smp_FP_t)(
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>&,
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p10_build_smp_operation);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Perform fabric SMP reconfiguration operation
///
/// @param[in] i_chips                  Vector of processor chip targets to be included in SMP
/// @param[in] i_master_chip_sys_next   Target designating chip which should be designated fabric
///                                     system master post-reconfiguration. Note: This chip must
///                                     currently be designated a master in its enclosing fabric.
///                                         - PHASE1/HB : any chip
///                                         - PHASE2/FSP: any current drawer master
///                                         - SWITCH    : any chip/current drawer master
///                                         - POST      : any chip/current drawer master
/// @param[in]     i_op                     Enumerated type representing SMP build phase (HB or FSP)
///
/// @return fapi2:ReturnCode            FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_build_smp(
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_chips,
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_master_chip_sys_next,
        const p10_build_smp_operation i_op);

} // extern "C"

#endif // _P10_BUILD_SMP_H_
