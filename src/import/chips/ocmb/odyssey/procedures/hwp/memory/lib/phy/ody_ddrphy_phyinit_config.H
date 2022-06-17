/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_ddrphy_phyinit_config.H $ */
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
/// @file ody_ddrphy_phyinit_config.H
/// @brief Odyssey PHY init procedure functions
/// @note Using a separate file as simulation might need a different PHY init procedure for now
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _ODY_DDRPHY_PHYINIT_CONFIG_H_
#define _ODY_DDRPHY_PHYINIT_CONFIG_H_

#include <fapi2.H>

#include <lib/phy/ody_ddrphy_phyinit_structs.H>

///
/// @brief Maps from drive strength in Ohms to the register value
/// @param[in] DrvStren_ohm drive strength in ohms
/// @return The register setting to be used
///
int dwc_ddrphy_phyinit_mapDrvStren (const float DrvStren_ohm);

///
/// @brief Checks if a dbyte is disabled
/// @param[in] i_user_input_basic - Synopsys basic user input structure
/// @param[in] i_user_input_advanced - Synopsys advanced user input structure
/// @param[in] i_user_input_dram_config - DRAM configuration inputs needed for PHY init (MRS/RCW)
/// @param[in] DbyteNumber the Dbyte to check to see if it is disabled
/// @param[out] o_rc fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @return 0 if enabled, 1 if disabled
///
int dwc_ddrphy_phyinit_IsDbyteDisabled(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                       const user_input_basic_t& i_user_input_basic,
                                       const user_input_advanced_t& i_user_input_advanced,
                                       const user_input_dram_config_t& i_user_input_dram_config,
                                       const int DbyteNumber,
                                       fapi2::ReturnCode& o_rc);

///
/// @brief Checks if 2T timing is needed for this configuration
/// @param[in] i_user_input_dram_config - DRAM configuration inputs needed for PHY init (MRS/RCW)
/// @return 0 if in 2N mode, otherwise 1
///
int dwc_ddrphy_phyinit_is2Ttiming(const user_input_dram_config_t& i_user_input_dram_config);

///
/// @brief Translates from the Synopsys register information and does the scom
/// @param[in] i_target - the memory port on which to operate
/// @param[in] i_addr - the Synopsys address on which to operate on
/// @param[in] i_data - the data to write out to the register
///
fapi2::ReturnCode dwc_ddrphy_phyinit_userCustom_io_write16(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint64_t i_addr,
        const int i_data);

///
/// @brief Helper function to compute the globalVrefInDAD
/// @param[in] i_phy_vref the PHY vref from the data structure
/// @return the register setting for the global VREF DAC
///
int compute_global_vref_in_dac(const uint8_t i_phy_vref);

///
/// @brief Computes the ps count of the passed in value at a given frequency
/// @param[in] i_value the value to count
/// @param[in] i_freq the frequency
/// @return the ps count
///
int compute_ps_count(const int i_value, const int i_freq);

///
/// @brief Calculates the ticks per 1us
/// @param[in] i_mem_clock_freq - half the DDR frequency rate
/// @return calculates the number of ticks per 1 uS, rounding up
///
int calculate_clk_tick_per_1us(const int i_mem_clock_freq);

///
/// @brief Configures the PHY to be ready for DRAMINIT
/// @param[in] i_target - the memory port on which to operate
/// @param[in] i_user_input_basic - Synopsys basic user input structure
/// @param[in] i_user_input_advanced - Synopsys advanced user input structure
/// @parampin i_user_input_dram_config - DRAM configuration inputs needed for PHY init (MRS/RCW)
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode init_phy_config( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                   const user_input_basic_t& i_user_input_basic,
                                   const user_input_advanced_t& i_user_input_advanced,
                                   const user_input_dram_config_t& i_user_input_dram_config);

///
/// @brief Initializes all of the PHY init structures
/// @param[in] i_target - the memory port on which to operate
/// @param[in,out] io_user_input_basic - Synopsys basic user input structure
/// @param[in,out] io_user_input_advanced - Synopsys advanced user input structure
/// @param[in,out] io_user_input_dram_config - DRAM configuration inputs needed for PHY init (MRS/RCW)
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Currently, hardcoding these structures for simulation purposes
/// TODO:ZEN:MST-1591 Convert PY init structures to be initialized from attributes
///
fapi2::ReturnCode init_phy_structs( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                    user_input_basic_t& io_user_input_basic,
                                    user_input_advanced_t& io_user_input_advanced,
                                    user_input_dram_config_t& io_user_input_dram_config);

///
/// @brief Runs PHY init on a specific port
/// @param[in] i_target - the memory port on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Using a helper function here so we can get accurate target trace
/// TRGTID uses i_target in a macro and we want the port target (not i_target)
///
fapi2::ReturnCode run_phy_init( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

#endif
