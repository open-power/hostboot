/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_factory.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file p10_factory.H
/// @brief P10 eff_config decoder factory
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#ifndef _P10_FACTORY_H_
#define _P10_FACTORY_H_

#include <fapi2.H>
#include <lib/eff_config/p10_base_engine.H>
#include <lib/eff_config/p10_ddimm_engine.H>
#include <lib/eff_config/p10_ddimm_efd_engine.H>

#include <lib/eff_config/p10_ddr5_base_engine.H>
#include <lib/eff_config/p10_ddr5_ddimm_efd_engine.H>
#include <lib/eff_config/p10_ddr5_ddimm_engine.H>

namespace mss
{
namespace efd
{

///
/// @brief Generates the EFD engine based upon the EFD type
/// @param[in] i_target DIMM target
/// @param[in] i_rev SPD revision
/// @param[in] i_gen DRAM generation
/// @param[in] i_rank_info the current rank info class
/// @param[out] o_efd_engine shared pointer to the EFD engine in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
///
fapi2::ReturnCode factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const uint8_t i_rev,
                          const uint8_t i_gen,
                          const mss::rank::info<mss::mc_type::EXPLORER>& i_rank_info,
                          std::shared_ptr<mss::efd::ddimm_efd_base>& o_efd_engine);

} // ns efd

namespace spd
{

///
/// @brief Generates the base module SPD engine based upon the rev/DRAM generation
/// @param[in] i_target DIMM target
/// @param[in] i_rev SPD revision
/// @param[in] i_gen DRAM generation
/// @param[out] o_base_engine shared pointer to the Base cnfg engine in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
///
fapi2::ReturnCode base_module_factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const uint8_t i_rev,
                                      const uint8_t i_gen,
                                      std::shared_ptr<mss::spd::base_cnfg_base>& o_base_engine);

///
/// @brief Generates the module specific SPD engines based upon the rev/DRAM generation/DIMM type
/// @param[in] i_target DIMM target
/// @param[in] i_rev SPD revision
/// @param[in] i_gen DRAM generation
/// @param[in] i_dimm_type DIMM type
/// @param[out] o_module_specific_engine shared pointer to the module specific cnfg engine in question
/// @return fapi2::ReturnCode SUCCESS iff the procedure executes successfully
///
fapi2::ReturnCode module_specific_factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_rev,
        const uint8_t i_gen,
        const uint8_t i_dimm_type,
        std::shared_ptr<mss::spd::module_specific_base>& o_module_specific_engine);

} // ns spd
} // ns mss

#endif
