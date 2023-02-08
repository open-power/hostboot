/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_io_ppe_common.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file ody_io_ppe_common.H
///
/// @brief Odyssey IO PPE function/constant definitions for IO hwps
///
/// *HWP HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

#pragma once

#include <fapi2.H>

#include <ody_io_ppe_regs.H>
#include <io_ppe_lib.H>

const uint64_t PHY_PPE_WRAP0_ARB_CSAR = 0x8010C0Dull;
const uint64_t PHY_PPE_WRAP0_ARB_CSDR = 0x8010C0Eull;
const uint64_t PHY_PPE_WRAP0_XIXCR = 0x8010C10ull;

namespace ody_io
{
#include <io_ppe_common.H>
}
