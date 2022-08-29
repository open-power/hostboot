/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_byte_swizzle_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
// EKB-Mirror-To: hostboot

///
/// @file exp_byte_swizzle_workarounds.C
/// @brief Workarounds for explorer byte swizzle
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup:  Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <lib/workarounds/exp_byte_swizzle_workarounds.H>

namespace mss
{
namespace exp
{
namespace workarounds
{

///
/// @brief Swizzles from the MCBIST to the DFI byte perspectives
/// @param[in] i_mcbist_byte the byte number in the MCBIST perspective
/// @return the byte number in the DFI perspective
///
uint8_t mcbist_to_dfi_byte_swizzle(const uint8_t i_mcbist_byte)
{
    // Byte perspectives
    // TYPE   | DFI/MC | MCBIST/LOGICAL
    // DATA   |      0 |              0
    // DATA   |      1 |              1
    // DATA   |      2 |              2
    // DATA   |      3 |              3
    // ECC    |      4 |              8
    // SPARE  |      5 |              9
    // DATA   |      6 |              4
    // DATA   |      7 |              5
    // DATA   |      8 |              6
    // DATA   |      9 |              7

    // The MCBIST/logical perspective is where the ECC is in byte 8, and the spare is in byte 9
    // Explorer has the DFI/MC/PHY perspective as ECC in byte 4 and spare in byte 5
    // Due to this discrepancy, there's a shift in the bytes from byte 4 and up in the PHY perspective

    constexpr uint64_t SHIFT_BYTE = 4;
    constexpr uint64_t DATA_BYTES_OFFSET = 2;
    constexpr uint64_t ECC_BYTE_CUTOFF = 8;
    constexpr uint64_t ECC_BYTE_OFFSET = ECC_BYTE_CUTOFF - SHIFT_BYTE;
    uint8_t l_dfi_byte = i_mcbist_byte;

    // Check if we're the ECC or the spare byte
    if(i_mcbist_byte >= ECC_BYTE_CUTOFF)
    {
        l_dfi_byte -= ECC_BYTE_OFFSET;
    }
    else if(i_mcbist_byte >= SHIFT_BYTE)
    {
        l_dfi_byte += DATA_BYTES_OFFSET;
    }

    FAPI_INF("Input MCBIST byte:%u. Output DFI byte: %u", i_mcbist_byte, l_dfi_byte);

    // Otherwise, no shift needed
    return l_dfi_byte;
}

} // workarounds
} // exp
} // mss
