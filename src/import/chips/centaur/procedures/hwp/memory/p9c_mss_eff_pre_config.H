/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_eff_pre_config.H $ */
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

/// @file p9c_mss_eff_pre_config.C
/// @brief This procedure puts in required attributes for mss_eff_config_thermal which are based on "worst case" config in case these attributes were not able to be setup by mss_eff_config
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#ifndef MSS_EFF_PRE_CONFIG_H_
#define MSS_EFF_PRE_CONFIG_H_

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi2.H>


typedef fapi2::ReturnCode (*mss_eff_pre_config_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

extern "C" {

    ///
    /// @brief This procedure puts in required attributes for mss_eff_config_thermal which are based on "worst case" config in case these attributes were not able to be setup by mss_eff_config
    /// @param[in] i_target_mba
    /// @return ReturnCode
    ///
    fapi2::ReturnCode mss_eff_pre_config(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

} // extern "C"

#endif // MSS_EFF_PRE_CONFIG_H_
