/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mc/exp_port.H $ */
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
/// @file exp_port.H
/// @brief Header file for exp_port.C
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#ifndef __MSS_EXP_PORT_H_
#define __MSS_EXP_PORT_H_

#include <fapi2.H>

namespace mss
{

///
/// @brief Helper for setting rcd protection time to minimum of DSM0Q_WRDONE_DLY & DSM0Q_RDTAG_DLY
/// @param [in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok

fapi2::ReturnCode config_exp_rcd_protect_time(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

}
#endif
