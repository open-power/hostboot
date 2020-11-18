/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/eff_config/explorer_efd_processing.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file explorer_efd_processing.H
/// @brief Processing for EFD for eff config
///

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI

#ifndef _MSS_EXPLORER_EFD_PROCESSING_H_
#define _MSS_EXPLORER_EFD_PROCESSING_H_

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_explorer_attribute_setters.H>

namespace mss
{
namespace exp
{
namespace efd
{

///
/// @brief Processes the Host INIT RD VREF DQ
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
/// @note this is pulled in for exp_draminit. The individual fields are pulled into the SI engine
///
fapi2::ReturnCode init_vref_dq(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                               const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the Host INIT PHY VREF
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode init_phy_vref(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the CAC delay A side
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode cac_delay_a(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the CAC delay A side
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode cac_delay_b(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the CS command latency
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode cs_cmd_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the CA parity latency
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode ca_parity_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the DFIMRL_DDRCLK
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode dfimrl_ddrclk(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Process the EFD data and set attributes
/// @param[in] i_target DIMM target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode process(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);
} // ns efd
} // ns exp
} // ns mss
#endif
