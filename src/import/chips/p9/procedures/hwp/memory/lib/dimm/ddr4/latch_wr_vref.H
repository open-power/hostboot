/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/latch_wr_vref.H $ */
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

///
/// @file latch_wr_vref.H
/// @brief Latches WR VREF according to JEDEC spec
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB Memory

#ifndef _LATCH_WR_VREF_H_
#define _LATCH_WR_VREF_H_

#include <vector>
#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/dimm/mrs_load.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/eff_config/timing.H>

namespace mss
{

namespace ddr4
{
// Declares an enum for using the default WR VREF values
enum wr_vref_override : uint8_t
{
    USE_DEFAULT_WR_VREF_SETTINGS = 0xff,
};

///
/// @brief Add latching commands for WR VREF to the instruction array - allows for custom MR06 data
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in] i_mrs06, base MRS 06 allows the user to setup custom values and pass it in
/// @param[in] i_rank, rank on which to latch MRS 06
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode add_latch_wr_vref_commands( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs06_data& i_mrs06,
        const uint64_t& i_rank,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

///
/// @brief Add latching commands for WR VREF to the instruction array
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_MCA>
/// @param[in] i_rank_pair, rank pair on which to latch MRS 06 - hits all ranks in the rank pair
/// @param[in] i_train_range, VREF range to setup
/// @param[in] i_train_value, VREF value to setup
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode latch_wr_vref_commands_by_rank_pair( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t& i_rank_pair,
        const uint8_t& i_train_range,
        const uint8_t& i_train_value);

///
/// @brief enables VREF train enable in an MRS06 class
/// @param[in,out] io_mrs06
///
inline void enable_vref_train_enable(mrs06_data& io_mrs06)
{
    // Sets up the MR information
    for(uint64_t i = 0; i < MAX_RANK_PER_DIMM; ++i)
    {
        io_mrs06.iv_vrefdq_train_enable[i] = fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE;
    }
}

///
/// @brief disables VREF train enable in an MRS06 class
/// @param[in,out] io_mrs06
///
inline void disable_vref_train_enable(mrs06_data& io_mrs06)
{
    // Sets up the MR information
    for(uint64_t i = 0; i < MAX_RANK_PER_DIMM; ++i)
    {
        io_mrs06.iv_vrefdq_train_enable[i] = fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE;
    }
}

///
/// @brief Add latching commands for WR VREF to the instruction array by a given rank
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_MCA>
/// @param[in] i_rank, rank on which to latch MRS 06 - hits all ranks in the rank pair
/// @param[in] i_train_range, VREF range to setup
/// @param[in] i_train_value, VREF value to setup
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode setup_latch_wr_vref_commands_by_rank( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t& i_rank,
        const uint8_t& i_train_range,
        const uint8_t& i_train_value,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

} // close namespace DDR4
} // close namespace mss

#endif
