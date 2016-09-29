/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_common_funcs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file cen_common_funcs.H
/// @brief Common functions for centaur fapi2 procedures.
///
/// @author Peng Fei GOU <shgoupf@cn.ibm.com>
///

//
// *HWP HWP Owner: Peng Fei GOU <shgoupf@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 2
// *HWP Consumed by: HB
//

#ifndef _CEN_COMMON_FUNCS_H
#define _CEN_COMMON_FUNCS_H

#include <fapi2.H>
#include <centaur_misc_scom_addresses.H>
#include <centaur_misc_constants.H>

/// @brief Determine if a chiplet id is a multicast write operation
/// @param[in] i_chiplet_id     The input chiplet id
/// @return true is a multicast write; false is not a multicast write
bool is_multicast_write(const uint64_t i_chiplet_id);

/// @brief Get the OR-combine read group from the chiplet id.
/// @param[in] i_chiplet_id     The input chiplet id
/// @return OR-combine read group
uint64_t get_multicast_read_or(const uint64_t i_chiplet_id);

/// @brief Get the AND-combine read group from the chiplet id.
/// @param[in] i_chiplet_id     The input chiplet id
/// @return AND-combine read group
uint64_t get_multicast_read_and(const uint64_t i_chiplet_id);

/// @brief Get scom addr from the chiplet id and generic addr.
///        (chiplet_id << 24 | generic_addr)
/// @param[in] i_chiplet_id     The input chiplet id
/// @param[in] i_generic_id     The generic address
/// @return the scom addr with correct chiplet id set
uint64_t get_scom_addr(const uint64_t i_chiplet_id, const uint64_t i_generic_addr);

/// @brief SCAN0 module
/// @param[in] i_target The FAPI2 target
/// @param[in] i_chiplet_id The chiplet ID
/// @param[in] i_clk_region_data The clock regions
///            (Clock Controller, Clock Region Register)
/// @param[in] i_clk_scansel_data  The scan selects
///            (Clock Controller, Scan Select Register)
/// @return The FAPI2 return code
fapi2::ReturnCode
cen_scan0_module(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                 const uint64_t i_chiplet_id, const uint64_t i_clk_region_data,
                 const uint64_t i_clk_scansel_data);

/// @brief ARRAY INIT module
/// @param[in] i_target The FAPI2 target
/// @param[in] i_chiplet_id The chiplet ID
/// @param[in] i_clk_region Clock Regions for Array Init
/// @return The FAPI2 return code
fapi2::ReturnCode
cen_arrayinit_module(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                     const uint64_t i_chiplet_id, const uint64_t i_clock_region);

/// @brief Invoke Centaur repair loader
/// @param[in] i_target The FAPI2 target
/// @param[in] i_repair_cmd_validation_entry contains Command Validation Register bits 0:15 (repair
///            command entries to process, right aligned in register)
/// @param[in] i_repair_cmd_star_addr  contains Command Register bits 4:15 (start address
///            of first repair control word entry in OTPROM, right
///            aligned in register)
/// @return The FAPI2 return code
fapi2::ReturnCode
cen_repair_loader(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
                  const uint64_t i_repair_cmd_validation_entry, const uint64_t i_repair_cmd_star_addr);

#endif
