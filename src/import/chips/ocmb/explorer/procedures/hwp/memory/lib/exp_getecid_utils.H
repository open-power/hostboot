/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_getecid_utils.H $ */
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
/// @file exp_getecid_utils.H
/// @brief Utils to set ECID attributes according to FUSE registers
///
// *HWP HWP Owner: Mark Pizzutillo <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __MSS_EXP_GETECID_UTILS__
#define __MSS_EXP_GETECID_UTILS__

#include <fapi2.H>
#include <lib/shared/exp_consts.H>

namespace mss
{
namespace exp
{
namespace ecid
{

///
/// @brief Determines enterprise state from explorer FUSE
/// @param[in] i_target the controller
/// @param[out] o_enterprise_mode state
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_enterprise_from_fuse(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    bool& o_enterprise_mode);

///
/// @brief Reads ECID into output array from fuse
/// @param[in] i_target the controller
/// @param[out] o_array ECID contents
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode read_from_fuse(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    uint16_t (&o_ecid_array)[mss::exp::ecid_consts::FUSE_ARRAY_SIZE]);

///
/// @brief Stores ECID in ATTR_ECID
/// @param[in] i_target the controller
/// @param[in] i_ecid 16-bit array of ECID contents
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode set_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint16_t i_ecid[mss::exp::ecid_consts::FUSE_ARRAY_SIZE]);

}
}// exp
}// mss

#endif
