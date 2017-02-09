/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_ddr_phy_reset.H $ */
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

///
/// @file p9c_mss_ddr_phy_reset.C
/// @brief HWP header file to set up ddr phy
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
////

#ifndef MSS_DDR_PHY_RESETHWPB_H_
#define MSS_DDR_PHY_RESETHWPB_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_ddr_phy_reset_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

extern "C"
{
    ///
    /// @brief Does a soft reset of the DDR PHY logic and lock the DDR PLLs
    /// @param[in] i_target the MBA target
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    fapi2::ReturnCode p9c_mss_ddr_phy_reset(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

} // extern "C"

#endif // MSS_DDR_PHY_RESETHWPB_H_
