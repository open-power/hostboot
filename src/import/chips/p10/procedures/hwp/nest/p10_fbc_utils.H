/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_utils.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file p10_fbc_utils.H
/// @brief Fabric library functions/constants (FAPI2)
///
/// The functions in this file provide:
/// - Information about the instantaneous state of the fabric
/// - Means to restart the fabric after a checkstop condition
/// - Determination of the chip's base address in the real address map
/// - Ability to set all instances of a fabric racetrack scom
/// - Extraction of group/chip bits from a topology id
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///
/// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: SBE,HB,FSP
///

#ifndef _P10_FBC_UTILS_H_
#define _P10_FBC_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

enum p10_fbc_utils_addr_mode
{
    EFF_TOPOLOGY_ID,  // effective FBC topology ID attributes
    HB_BOOT_ID        // address 0 of drawer
};

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// address range definitions
const uint64_t P10_FBC_UTILS_FBC_MAX_ADDRESS = ((1ULL << 56) - 1ULL);
const uint64_t P10_FBC_UTILS_CACHELINE_MASK = 0x7FULL;
const uint64_t P10_FBC_UTILS_LAST_ADDR_IN_CACHELINE = 0x78ULL;

// cacheline size = 128B
const uint64_t FABRIC_CACHELINE_SIZE = 0x80;

// fbc racetrack stations
const uint8_t FABRIC_NUM_STATIONS = 16;

// fbc max number of iohs links
const uint8_t FABRIC_NUM_IOHS_LINKS = 8;

// max memory interleave = 16TB
const uint64_t MAX_INTERLEAVE_GROUP_SIZE = 0x0000100000000000ULL;

// fbc base address determination constants
const uint8_t FABRIC_ADDR_SMF_BIT = 12;
const uint64_t FABRIC_ADDR_SMF_MASK = 0x0008000000000000ULL;
const uint8_t FABRIC_ADDR_MSEL_START_BIT = 13;
const uint8_t FABRIC_ADDR_MSEL_END_BIT = 14;
const uint8_t FABRIC_ADDR_TOPO_ID_INDEX_START_BIT = 15;
const uint8_t FABRIC_ADDR_TOPO_ID_INDEX_END_BIT = 19;

// smp configuration definitions
const uint8_t P10_FBC_UTILS_MAX_LINKS = 8;
const uint8_t P10_FBC_UTILS_MAX_CHIPS = 8;

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

namespace topo
{
///
/// @brief Determine this chip's unique 5b index into the fabric topology id
///        table from the 4b topology id.
///        Note: this 5b index represents RA[15:19]
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_addr_mode      HB_BOOT_ID or EFF_TOPOLOGY_ID (chip 0 of
///                             drawer vs eff topology id)
/// @param[out] o_topology_idx  5b index into the topology id table
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS on success, error otherwise
///
fapi2::ReturnCode get_topology_idx(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p10_fbc_utils_addr_mode& i_addr_mode,
    uint8_t& o_topology_idx);

///
/// @brief Initialize chip's entry in the topology id table.
/// @param[in] i_target         Reference to processor chip target
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS on success, error otherwise
///
fapi2::ReturnCode init_topology_id_table(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

///
/// @brief Initialize each chips' entry in the topology id table.
/// @param[in] i_target         Reference to processor chip target
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS on success, error otherwise
///
fapi2::ReturnCode init_topology_id_table(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_targets);

///
/// @brief Return the topology id table formatted as SCOM register values.
/// @param[in] i_target                     Reference to processor chip target
/// @param[out] o_topology_id_table_scoms   Vector of register values to setup the topology id
///                                         entries in fabric unit SCOM registers:
///                                         *TOPOLOGY_TBL0_SCOM_*
///                                         *TOPOLOGY_TBL1_SCOM_*
///                                         *TOPOLOGY_TBL2_SCOM_*
///                                         *TOPOLOGY_TBL3_SCOM_*
/// @return fapi::ReturnCode                FAPI2_RC_SUCCESS on success, error otherwise
///
fapi2::ReturnCode get_topology_table_scoms(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    std::vector<uint64_t>& o_topology_id_table_scoms);

///
/// @brief Applies topology ID table attribute values to all unit scom registers
/// @param[in]  i_target        Reference to processor chip target
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error.
///
fapi2::ReturnCode set_topology_id_tables(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

}; // namespace topo

///
/// @brief Read FBC/ADU registers to determine state of fabric init and stop
/// control signals
///
/// @param[in] i_target             Reference to processor chip target
/// @param[out] o_is_initialized    State of fabric init signal
/// @param[out] o_is_running        State of fabric pervasive stop control
/// @return fapi::ReturnCode        FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_utils_get_fbc_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    bool& o_is_initialized,
    bool& o_is_running);

///
/// @brief Use ADU pMisc Mode register to clear fabric stop signal, overriding
/// a stop condition caused by a checkstop
///
/// @param[in] i_target             Reference to processor chip target
/// @return fapi::ReturnCode        FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_utils_override_fbc_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

///
/// @brief Dynamically determine base address for a given chip
///
/// @param[in] i_target             Reference to processor chip target
/// @param[in] i_addr_mode          HB_BOOT_ID or EFF_TOPOLOGY_ID (chip 0 of
///                                 drawer vs eff topology id)
/// @param[out] o_base_address_nm0  base address of nm0 region of memory map
/// @param[out] o_base_address_nm1  base address of nm1 region of memory map
/// @param[out] o_base_address_m    base address of m region of memory map
/// @param[out] o_base_address_mmio base address of mmio region of memory map
/// @return fapi2::ReturnCode       FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_utils_get_chip_base_address(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p10_fbc_utils_addr_mode i_addr_mode,
    uint64_t& o_base_address_nm0,
    uint64_t& o_base_address_nm1,
    uint64_t& o_base_address_m,
    uint64_t& o_base_address_mmio);

///
/// @brief Write to all instances of a given racetrack scom register
///
/// @param[in] i_target             Reference to processor chip target
/// @param[in] i_scom_addr          Scom address for EQ0 instance of racetrack regs
/// @param[in] i_scom_data          Scom data to write, assumes 64-bit value
/// @return fapi2::ReturnCode       FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fbc_utils_set_racetrack_regs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_scom_addr,
    const uint64_t i_scom_data);

///
/// @brief Extract group/chip bits from fabric topology ID based on topology mode
///
/// @param[in]  i_target            Reference to processor chip target
/// @param[out] o_topology_group_id Topology ID group bits, right-aligned
/// @param[out] o_topology_chip_id  Topology ID chip bits, right-aligned
/// @return fapi2::ReturnCode       FAPI2_RC_SUCCESS if success, else error.
///
fapi2::ReturnCode p10_fbc_utils_get_topology_id(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    uint8_t& o_topology_group_id,
    uint8_t& o_topology_chip_id);

#endif // _P10_FBC_UTILS_H_
