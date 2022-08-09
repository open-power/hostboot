/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/dwc_ddrphy_phyinit_I_loadPIEImage.H $ */
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
/// @file dwc_ddrphy_phyinit_I_loadPIEImage.H
/// @brief Odyssey PHY init engine procedure implements Step I of initialization sequence
///
/// This file contains the implementation of dwc_ddrphy_phyinit_I_initPhyConfig
/// function.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB


#ifndef _ODY_STEPI_LOAD_PIE_IMAGE_H_
#define _ODY_STEPI_LOAD_PIE_IMAGE_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/c_str.H>

#include <lib/phy/ody_ddrphy_phyinit_structs.H>

///
/// @brief Generates structures, loads registers and programs the PHY initialization engine (PIE) after training
/// @param[in] i_target - the memory port on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dwc_ddrphy_phyinit_I_loadPIEImage( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Loads registers and programs the PHY initialization engine (PIE) after training
/// @param[in] i_target - the memory port on which to operate
/// @param[in,out] io_runtime_config - the runtime configuration
/// @param[in] i_user_input_basic - Synopsys basic user input structure
/// @param[in] i_user_input_advanced - Synopsys advanced user input structure
/// @param[in] i_dram_config the draminit message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dwc_ddrphy_phyinit_I_loadPIEImage( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        runtime_config_t& io_runtime_config,
        const user_input_basic_t& i_user_input_basic,
        const user_input_advanced_t& i_user_input_advanced,
        const user_input_dram_config_t& i_dram_config);

#endif
