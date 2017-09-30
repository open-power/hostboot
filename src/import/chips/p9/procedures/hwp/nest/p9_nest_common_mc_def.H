/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_nest_common_mc_def.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// ----------------------------------------------------------------------------
/// @file  p9_nest_common_mc_def.H
///
/// @brief Common definitions for MC related values in P9
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 3
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------
#ifndef _P9_NEST_COMMON_MC_DEF_H_
#define _P9_NEST_COMMON_MC_DEF_H_

//----------------------------------------------------------------------------
// Constant definitions
//----------------------------------------------------------------------------

// Nimbus PROC/MCS/MCA/DIMM definitions
const uint8_t MAX_MCS_PER_PROC = 4;
const uint8_t MAX_MCA_PER_PROC = 8;
const uint8_t MAX_MCA_PER_MCS  = 2;
const uint8_t MAX_DIMM_PER_MCA = 2;

#endif  // _P9_NEST_COMMON_MC_DEF_H_
