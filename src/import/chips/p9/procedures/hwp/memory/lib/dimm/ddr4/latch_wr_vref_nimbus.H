/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/latch_wr_vref_nimbus.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
// *HWP HWP Backup: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory

#ifndef _LATCH_WR_VREF_NIMBUS_H_
#define _LATCH_WR_VREF_NIMBUS_H_

#include <vector>
#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <generic/memory/lib/utils/c_str.H>

#include <lib/dimm/ddr4/mrs_load_ddr4_nimbus.H>
#include <lib/eff_config/timing.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <generic/memory/lib/dimm/ddr4/latch_wr_vref.H>

namespace mss
{
namespace ddr4
{

///
/// @brief Add latching commands for WR VREF to the instruction array
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_MCA>
/// @param[in] i_rank_pair, rank pair on which to latch MRS 06 - hits all ranks in the rank pair
/// @param[in] i_train_range, VREF range to setup
/// @param[in] i_train_value, VREF value to setup
/// @param[in] i_nvdimm_workaround switch to indicate nvdimm workaround. Default to false
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Not needed for explorer (will be blank, TK #421)
///
fapi2::ReturnCode latch_wr_vref_commands_by_rank_pair( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rank_pair,
        const uint8_t i_train_range,
        const uint8_t i_train_value,
        const bool i_nvdimm_workaround = false);

} // ddr4
} // mss

#endif
