/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/adr32s.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file adr32s.C
/// @brief Subroutines for the PHY ADR32S registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/phy/adr32s.H>

namespace mss
{

// Definition of the ADR32S DLL Config registers
const std::vector<uint64_t> adr32sTraits<fapi2::TARGET_TYPE_MCA>::DLL_CNFG_REG =
{
    MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0,
    MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S1
};

// Definition of the ADR32S output driver registers
const std::vector<uint64_t> adr32sTraits<fapi2::TARGET_TYPE_MCA>::OUTPUT_DRIVER_REG =
{
    MCA_DDRPHY_ADR_OUTPUT_DRIVER_FORCE_VALUE0_P0_ADR32S0,
    MCA_DDRPHY_ADR_OUTPUT_DRIVER_FORCE_VALUE0_P0_ADR32S1
};

}

