/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_thermal_init.H $ */
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
/// @file p9_mss_thermal_init.H
/// @brief configure and start the OCC and thermal cache
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef __P9_MSS_THERMAL_INIT__
#define __P9_MSS_THERMAL_INIT__

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9_mss_thermal_init_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MCS>&);

extern "C"
{
///
/// @brief configure and start the OCC and thermal cache
/// @param[in] i_target the controller target (MCS)
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_thermal_init( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target );
}
#endif
