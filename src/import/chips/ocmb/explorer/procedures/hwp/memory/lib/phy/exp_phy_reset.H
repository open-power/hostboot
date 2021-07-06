/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/exp_phy_reset.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file exp_phy_reset.H
/// @brief Procedures to reset the Explorer PHY
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef __EXP_PHY_RESET_H__
#define __EXP_PHY_RESET_H__

#include <target.H>
#include <return_code.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/exp_draminit_utils.H>

namespace mss
{
namespace exp
{
namespace phy
{

///
/// @brief Send Host phy_init_cmd and check resp
/// @param[in] i_target an explorer chip
/// @param[in] i_phy_info phy information of interest
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode send_phy_reset(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                 const mss::exp::phy_param_info& i_phy_info);

///
/// @brief Resets the explorer's PHY if needed
/// @param[in] i_target the explorer chip target in question
/// @return FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode reset(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Checks if the Explorer FW supports the separate reset procedure
/// @param[in] i_target the explorer chip target in question
/// @param[out] o_is_ext_reset_supported YES if the external PHY reset is needed, otherwise no
/// @return FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode is_reset_supported( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      mss::states& o_is_reset_supported );

} // ns phy
} // ns exp
} // ns mss

#endif
