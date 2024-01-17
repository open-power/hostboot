/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/io_scom_lib.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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

/// @brief                      Builds address to access SCOMs
/// @param i_base_addr          The chip's base address
/// @param i_group              The group being accessed
/// @param i_lane               The lane being accessed
/// @param i_reg                The reg being accessed & tx direction. Specify register in hex then append 0 (Rx) or 1 (Tx)
///                                         111111
///                               0123456789012345
///                               xxxRRRRRRRRRTxxx
///
///                             R : register address bits
///                             T : TX bit
///                             x : don't care
/// @return                     Returns the address that's been built from the input parameters
inline uint64_t buildAddr(const uint32_t i_base_addr,
                          const uint8_t i_group,
                          const uint8_t i_lane,
                          const uint16_t i_reg)
{
    uint64_t r_addr = static_cast<uint64_t>(i_base_addr);
    r_addr |= static_cast<uint64_t>(0x3F);
    r_addr |= static_cast<uint64_t>(i_reg & 0x1FF8) << 39;  // 63-21-3=39
    // 21 is the starting location for Tx, but need to shift back another 3 bits so the
    //  direction bit of the nibble is in the correct position
    r_addr |= static_cast<uint64_t>(i_lane & 0x1F) << 32;   // 63-31=32
    r_addr |= static_cast<uint64_t>(i_group & 0x1F) << 37;   // 63-26=37
    r_addr |= static_cast<uint64_t>(0x1) << 63;

    return r_addr;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode rmwIoHardwareReg(const fapi2::Target<K, M, V>& i_target,
                                   const uint64_t i_addr,
                                   const uint32_t i_data,
                                   const uint32_t i_dataBit,
                                   const uint32_t i_dataLen)
{
    FAPI_DBG("Start - RMW register at 0x%08X%08X, bit %d, for %d bits", (i_addr >> 32) & 0xFFFFFFFF, i_addr & 0xFFFFFFFF,
             i_dataBit, i_dataLen);

    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY(getScom(i_target, i_addr, l_buffer),
             "Error getscom to address 0x%08X%08X.", (i_addr >> 32) & 0xFFFFFFFF, i_addr & 0xFFFFFFFF);
    l_buffer.insertFromRight(i_data, i_dataBit, i_dataLen);
    FAPI_TRY(putScom(i_target, i_addr, l_buffer),
             "Error putscom to address 0x%08X%08X.", (i_addr >> 32) & 0xFFFFFFFF, i_addr & 0xFFFFFFFF);

fapi_try_exit:
    FAPI_DBG("End - RMW");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode readIoHardwareReg(const fapi2::Target<K, M, V>& i_target,
                                    const uint64_t i_addr,
                                    const uint32_t i_dataBit,
                                    const uint32_t i_dataLen,
                                    uint32_t& o_data)
{
    FAPI_DBG("Start - Reading register at 0x%08X%08X, bit %d, for %d bits", (i_addr >> 32) & 0xFFFFFFFF,
             i_addr & 0xFFFFFFFF, i_dataBit, i_dataLen);

    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY(getScom(i_target, i_addr, l_buffer),
             "Error getscom to address 0x%08X%08X.", (i_addr >> 32) & 0xFFFFFFFF, i_addr & 0xFFFFFFFF);
    FAPI_TRY(l_buffer.extractToRight(o_data, i_dataBit, i_dataLen));

fapi_try_exit:
    FAPI_DBG("End - Read");
    return fapi2::current_err;
}
