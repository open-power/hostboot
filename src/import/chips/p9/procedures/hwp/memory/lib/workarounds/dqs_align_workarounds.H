/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/dqs_align_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

#ifndef _MSS_WORKAROUNDS_DQS_ALIGN
#define _MSS_WORKAROUNDS_DQS_ALIGN

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <mss_attribute_accessors.H>

namespace mss
{

namespace workarounds
{

namespace dqs_align
{

///
/// @brief Sets tRFC cyles for sequencer
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode set_timing0_trfc(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief Set PHY sequencer to trigger refresh during init cal
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode set_init_cal_refresh(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief Set PHY sequencer to trigger refresh during init cal
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode refresh(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

}// dqs_align
}// workarounds
}// mss

#endif
