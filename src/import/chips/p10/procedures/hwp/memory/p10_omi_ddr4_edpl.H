/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_ddr4_edpl.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file p10_omi_ddr4_edpl.C
/// @brief Apply P10 OMI DDR4 EDPL changes to active systems
///
// *HWP HWP Owner: Chris Steffen  <cwsteffen@us.ibm.com>
// *HWP HWP Backup: Josh Chica <josh.chica@ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _P10_OMI_DDR4_EDPL_H_
#define _P10_OMI_DDR4_EDPL_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p10_omi_ddr4_edpl_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&, const bool);

extern "C"
{

    ///
    /// @brief Start DL link training on the selected OMIC
    /// @param[in] i_target Reference to OMIC endpoint target
    /// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode p10_omi_ddr4_edpl(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                        const bool i_enable_edpl);

} // extern "C"

#endif
