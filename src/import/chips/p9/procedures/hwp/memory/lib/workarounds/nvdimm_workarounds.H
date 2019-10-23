/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/nvdimm_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file nvdimm_workarounds.H
/// @brief Workarounds for NVDIMM
/// Workarounds are very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Tsung Yeung <tyeung@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_WORKAROUNDS_NVDIMM_H_
#define _MSS_WORKAROUNDS_NVDIMM_H_

#include <fapi2.H>

namespace mss
{

namespace workarounds
{

namespace nvdimm
{

// Function pointer for HWP support in PPE
typedef fapi2::ReturnCode (*p9_flush_nvdimm_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

///
/// @brief Triggers csave on NVDIMM. This subroutine reads ATTR_SBE_NVDIMM_IN_PORT
/// and fires the trigger to all the ports with NVDIMM plugged. This is written
/// specifically for SBE.
/// @param[in] i_target - PROC_CHIP target
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode trigger_csave( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target );

///
/// @brief Program the necessary scom regs to prepare for CSAVE
/// @param[in] i_target - PROC_CHIP target
/// @param[in] i_mcbist - mcbist position relative to the proc
/// @param[out] o_addresses - list of addresses that require restore
/// @param[out] o_data - data to restore to o_addresses
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode prep_for_csave( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                  const uint8_t i_mcbist,
                                  std::vector<uint64_t>& o_addresses,
                                  std::vector<fapi2::buffer<uint64_t>>& o_data);

///
/// @brief Select which port to run CCS on
/// @param[in] i_target - PROC_CHIP target
/// @param[in] i_mca - mca position relative to the proc
/// @param[out] o_addresses - list of addresses that require restore
/// @param[out] o_data - data to restore to o_addresses
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode select_port(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                              const uint8_t i_mca,
                              std::vector<uint64_t>& o_addresses,
                              std::vector<fapi2::buffer<uint64_t>>& o_data);

///
/// @brief Start or stop CCS
/// @param[in] i_target - PROC_CHIP target
/// @param[in] i_mcbist - mcbist position relative to the proc
/// @param[in] i_start_stop - start or stop CCS
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode start_stop_ccs( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                  const uint8_t i_mcbist,
                                  const bool i_start_stop);

///
/// @brief change the BAR valid state on MCS with NVDIMM installed
/// @param[in] i_target - PROC_CHIP target
/// @param[in] i_port_bitmap - port bitmap that indicates port with nvdimm
/// @param[in] i_state - BAR state to change to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode change_bar_valid_state( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const fapi2::buffer<uint8_t> i_port_bitmap,
        const uint64_t i_state);

}//ns nvdimm
}//ns workarounds
}//ns mss

#endif
