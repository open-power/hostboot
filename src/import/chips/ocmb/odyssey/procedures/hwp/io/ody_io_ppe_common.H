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
const uint64_t PHY_ODY_OMI_BASE = 0x08010C00ull;
const uint32_t PHY_ODY_RX_LANES = 0xFF000000;
const uint32_t PHY_ODY_TX_LANES = 0xFF000000;
const uint8_t PHY_ODY_NUM_LANES = 8;
const uint8_t PHY_ODY_NUM_THREADS = 1;

namespace ody_io
{
#include <io_ppe_common.H>

///
/// @brief Checks the ATTR_MFG_FLAGS for manufacturing mode
///
/// @param[out] o_mfg_mode Indicates if the manufacturing mode flag is set
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
inline fapi2::ReturnCode get_functional_margin_mfg_mode(bool& o_mfg_mode)
{
    constexpr uint32_t MFG_FLAG = fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_POLICY_FLAG_AVAIL_05;
    constexpr size_t CELL_SIZE = 32;
    const size_t l_index = MFG_FLAG / CELL_SIZE;
    const size_t l_flag_pos = MFG_FLAG % CELL_SIZE;

    uint32_t l_mfg_flags[4] = {};
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MFG_FLAGS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_mfg_flags));

    o_mfg_mode = (l_mfg_flags[l_index] & l_flag_pos) ? true : false;

fapi_try_exit:
    return fapi2::current_err;
}

}
