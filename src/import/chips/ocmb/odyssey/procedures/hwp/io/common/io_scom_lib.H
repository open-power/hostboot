/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/io_scom_lib.H $ */
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
/// @file io_scom_lib.H
///
/// @brief SCOM function lib definition file for IO hwps
///
/// *HWP HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

#pragma once

#include <fapi2.H>

inline uint64_t buildAddr(const uint32_t& i_base_addr,
                          const uint8_t& i_group,
                          const uint8_t& i_lane,
                          const uint16_t& i_reg,
                          const uint8_t& i_tx = 0)
{
    uint64_t r_addr = static_cast<uint64_t>(i_base_addr);
    r_addr |= static_cast<uint64_t>(0x3F);
    r_addr |= static_cast<uint64_t>(i_reg & 0x1FF) << 43;   // 63-20=43
    r_addr |= static_cast<uint64_t>(i_tx & 0x1) << 42;      // 63-21=42
    r_addr |= static_cast<uint64_t>(i_lane & 0x1F) << 32;   // 63-31=32
    r_addr |= static_cast<uint64_t>(i_group & 0xF) << 37;   // 63-26=37
    r_addr |= static_cast<uint64_t>(0x1) << 63;

    return r_addr;
}

fapi2::ReturnCode rmwIoHardwareReg(const fapi2::Target < fapi2::TARGET_TYPE_OCMB_CHIP | fapi2::TARGET_TYPE_OMI > &,
                                   const uint64_t&,
                                   const uint32_t&,
                                   const uint32_t&,
                                   const uint32_t&);

fapi2::ReturnCode readIoHardwareReg(const fapi2::Target < fapi2::TARGET_TYPE_OCMB_CHIP | fapi2::TARGET_TYPE_OMI > &,
                                    const uint64_t&,
                                    const uint32_t&,
                                    const uint32_t&,
                                    uint32_t&);
