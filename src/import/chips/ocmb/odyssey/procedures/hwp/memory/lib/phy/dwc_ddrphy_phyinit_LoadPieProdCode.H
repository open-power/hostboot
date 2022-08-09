/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/dwc_ddrphy_phyinit_LoadPieProdCode.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
/* [+] International Business Machines Corp.                              */
/* [+] Synopsys, Inc.                                                     */
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

// Note: Synopsys, Inc. owns the original copyright of the code
// This file is ported into IBM's code stream with the permission of Synopsys, Inc.

// EKB-Mirror-To: hostboot
///
/// @file dwc_ddrphy_phyinit_LoadPieProdCode.H
/// @brief Odyssey PHY init loading PIE production code procedures
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB


#ifndef _ODY_LOAD_PIE_PROD_CODE_H_
#define _ODY_LOAD_PIE_PROD_CODE_H_

#include <stdint.h>
#include <stddef.h>

#include <fapi2.H>

#include <lib/phy/dwc_ddrphy_phyinit_LoadPieProdCode.H>
#include <lib/phy/ody_ddrphy_phyinit_structs.H>
#include <lib/phy/ody_snps_dram_train_msg_blk.H>
#include <lib/phy/ody_ddrphy_phyinit_config.H>

#define COUNTOF(a) (sizeof(a)/sizeof(a[0]))

// Must match pie_ext.c
#define NORMAL_SECTION          0x00
#define START_ADDRESS           0x01
#define ENABLE_BITS_ANY_BITS    0x02
#define ENABLE_BITS_NO_BITS     0x03
#define ENABLE_BITS_ALL_BITS    0x04

typedef struct code_section
{
    union
    {
        uint32_t start_address;
        uint32_t enable_bits;
    };
    uint16_t section_len;
    uint8_t enable_type;
    uint8_t section_type;
} code_section_t;
typedef struct code_marker
{
    uint16_t section_index;
    uint32_t* marker_location;
} code_marker_t;

///
/// @brief Set enable bits based on PUB revision
/// @param[in] i_target - the memory port on which to operate
/// @param[in,out] io_runtime_config - the runtime configuration
/// @param[in] i_user_input_advanced - Synopsys advanced user input structure
/// @param[in] i_dram_config the draminit message block
///
void initRuntimeConfigEnableBits(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 runtime_config_t& io_runtime_config,
                                 const user_input_advanced_t& i_user_input_advanced,
                                 const user_input_dram_config_t& i_dram_config);

///
/// @brief Generates calls to dwc_ddrphy_phyinit_userCustom_io_write16
/// @param[in] i_target - the memory port on which to operate
/// @param[in] i_runtime_config - the runtime configuration
/// @param[in] code_sections Array of structures for continuous address sections of code
/// @param[in] code_section_count Size of the code_sections array
/// @param[in] code_data     Array of words that make up data for the code sections
/// @param[in] code_data_count Size of the code_data array
/// @param[in] code_markers  Array of code_markers, sorted by code index
/// @param[in] code_marker_count Size of the code_markers array
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note This function translates the code section and code data (word) arrays
/// into calls to dwc_ddrphy_phyinit_userCustom_io_write16 that create the PIE
/// and (for DDR5) ACSM images.
/// This function also fills in code markers with the start address of each
/// given code section.
/// IBM note: leaving the pointers in here to keep code inline with what was provided by Synopsys
///
fapi2::ReturnCode dwc_ddrphy_phyinit_LoadPIECodeSections(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const runtime_config_t& i_runtime_config,
        code_section_t* code_sections, size_t code_section_count,
        uint16_t* code_data, size_t code_data_count,
        code_marker_t* code_markers, size_t code_marker_count);

///
/// @brief Loads the PHY Initialization Engine (PIE) code
/// @param[in] i_target - the memory port on which to operate
/// @param[in] i_runtime_config - the runtime configuration
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dwc_ddrphy_phyinit_LoadPieProdCode(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const runtime_config_t& i_runtime_config);

///
/// @brief Loads the PHY Initialization Engine (PIE) code for RDIMM's
/// @param[in] i_target - the memory port on which to operate
/// @param[in] i_runtime_config - the runtime configuration
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dwc_ddrphy_phyinit_LoadPieProdCode_rdimm(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const runtime_config_t& i_runtime_config);

///
/// @brief Tests that the given enable bits are set in the phyctx
/// @param[in] i_runtime_config - the runtime configuration
/// @param[in] enable_bits Bitmap to test against the contents of phyctx
/// @param[in] mode        Comparison mode
/// @param[in] type        Type of enable bits field to use
/// @return int - 1 if enable_bits are set in phyctx
/// @note This function allows the PHY Initialization Engine (PIE) and ACSM
/// instructions and the associated registers to be programmed conditionally.
///
int dwc_ddrphy_phyinit_TestPIEProdEnableBits( const runtime_config_t& i_runtime_config,
        uint32_t enable_bits,
        int mode,
        int type);

#endif
