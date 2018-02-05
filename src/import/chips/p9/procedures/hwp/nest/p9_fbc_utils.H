/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_fbc_utils.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
/// @file p9_fbc_utils.H
/// @brief Fabric library functions/constants (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: SBE,HB,FSP
//

#ifndef _P9_FBC_UTILS_H_
#define _P9_FBC_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

enum p9_fbc_utils_addr_mode_t
{
    EFF_FBC_GRP_CHIP_IDS,  // effective FBC group/chip ID attributes
    EFF_FBC_GRP_ID_ONLY,   // effective FBC group ID attribute (chip ID=0)
    ABS_FBC_GRP_CHIP_IDS,  // absolute FBC group/chip ID attributes
    ABS_FBC_GRP_ID_ONLY    // absolute FBC group ID attribute (chip ID=0)
};

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// address range definitions
const uint64_t P9_FBC_UTILS_FBC_MAX_ADDRESS = ((1ULL << 56) - 1ULL);
const uint64_t P9_FBC_UTILS_CACHELINE_MASK = 0x7FULL;
const uint64_t P9_FBC_UTILS_LAST_ADDR_IN_CACHELINE = 0x78ULL;

// cacheline size = 128B
const uint64_t FABRIC_CACHELINE_SIZE = 0x80;

// chip address extension mask, for HW423589_OPTION2
// repurposes chip ID(2) as address bits
const uint8_t CHIP_ADDRESS_EXTENSION_GROUP_ID_MASK_HW423589_OPTION2 = 0x0;
const uint8_t CHIP_ADDRESS_EXTENSION_CHIP_ID_MASK_HW423589_OPTION2 = 0x1;

const uint64_t MAX_INTERLEAVE_GROUP_SIZE                  = 0x40000000000ULL; // 4_TB
const uint64_t MAX_INTERLEAVE_GROUP_SIZE_HW423589_OPTION2 = 0x8000000000ULL;  // 512_GB

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

///
/// @brief Read FBC/ADU registers to determine state of fabric init and stop
/// control signals
///
/// @param[in] i_target Reference to processor chip target
/// @param[out] o_is_initialized State of fabric init signal
/// @param[out] o_is_running State of fabric pervasive stop control
/// @return fapi::ReturnCode, FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p9_fbc_utils_get_fbc_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    bool& o_is_initialized,
    bool& o_is_running);

///
/// @brief Use ADU pMisc Mode register to clear fabric stop signal, overriding
/// a stop condition caused by a checkstop
///
/// @param[in] i_target Reference to processor chip target
/// @return fapi::ReturnCode, FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p9_fbc_utils_override_fbc_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

///
/// @brief Return set of base addresses (non-mirrored/mirrored/MMIO) for this chip,
///        accounting for fixed msel assignments, but not aliasing
///        enabled by chip address extension facility
///
/// @param[in] i_target Reference to processor chip target
/// @param[in] i_addr_mode Specifies mode for chip base/origin address calculations
/// @param[out] o_base_address_nm0 Non-mirrored base address for
///             this chip (covering msel=0b00)
/// @param[out] o_base_address_nm1 Non-mirrored base address for
///             this chip (covering msel=0b01)
/// @param[out] o_base_address_m Mirrored base address for
///             this chip (covering msel=0b10)
/// @param[out] o_base_address_mmio MMIO base address for this chip (msel=0b11)
/// @return fapi::ReturnCode, FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p9_fbc_utils_get_chip_base_address_no_aliases(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_utils_addr_mode_t i_addr_mode,
    uint64_t& o_base_address_nm0,
    uint64_t& o_base_address_nm1,
    uint64_t& o_base_address_m,
    uint64_t& o_base_address_mmio);

///
/// @brief Return set of base addresses (non-mirrored/mirrored/MMIO) for this chip,
///        accounting for fixed msel assignments as well as variable aliasing
///        enabled by chip address extension facility
///
/// @param[in] i_target Reference to processor chip target
/// @param[in] i_addr_mode Specifies mode for chip base/origin address calculations
/// @param[out] o_base_address_nm0 List of non-mirrored base addresses for
///             this chip (covering msel=0b00), ordered from smallest->largest
/// @param[out] o_base_address_nm1 List of non-mirrored base addresses for
///             this chip (covering msel=0b01), ordered from smallest->largest
/// @param[out] o_base_address_m List of mirrored base addresses for
///             this chip (covering msel=0b10), ordered from
///             smallest->largest
/// @param[out] o_base_address_mmio MMIO base address for this chip (msel=0b11)
/// @return fapi::ReturnCode, FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p9_fbc_utils_get_chip_base_address(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_utils_addr_mode_t i_addr_mode,
    std::vector<uint64_t>& o_base_address_nm0,
    std::vector<uint64_t>& o_base_address_nm1,
    std::vector<uint64_t>& o_base_address_m,
    uint64_t& o_base_address_mmio);

#endif // _P9_FBC_UTILS_H_
