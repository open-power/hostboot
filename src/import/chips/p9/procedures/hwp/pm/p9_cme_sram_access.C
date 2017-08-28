/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_cme_sram_access.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file  p9_cme_sram_access.C
/// @brief Display data from the targetted CME's SRAM array.
///
// *HWP HWP Owner       : Brian Vanderpool <vanderp@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 3
// *HWP Consumed by     : HS:CRO:SBE
///

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <p9_cme_sram_access.H>
#include <p9_quad_scom_addresses.H>

// ----------------------------------------------------------------------
// Constants
// ----------------------------------------------------------------------
const uint8_t CSCR_AUTO_INCREMENT_BIT = 0;

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

/// See doxygen in header file
fapi2::ReturnCode p9_cme_sram_access(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_cme_target,
    const uint32_t i_start_address,
    const uint32_t i_length_dword,
    uint64_t*      o_data,
    uint32_t&      o_dwords_read)
{
    fapi2::buffer<uint64_t> l_data64;

    // These are initialized before being used.
    // Not doing an initial assignment to 0 to save space on the SBE.
    uint32_t                l_norm_address;
    uint32_t                l_words_to_read;

    FAPI_DBG("> p9_cme_sram_access");

    // Ensure the address is between 0xFFFF8000 and 0xFFFFFFFF.
    // No need to check the upper limit, since that will overflow the uint32_t data type.
    if (i_start_address < 0xFFFF8000)
    {
        // Return Error - invalid start address
        FAPI_DBG("Invalid Start Address 0x%.8X", i_start_address);
        FAPI_ASSERT(false,
                    fapi2::CME_SRAM_ACCESS_ERROR().set_ADDRESS(i_start_address),
                    "Invalid CME Start address");
    }

    if ((i_start_address & 0x00000007) != 0)
    {
        // Return Error - invalid start address alignment
        FAPI_DBG("Invalid Start Address alignment 0x%.8X", i_start_address);
        FAPI_ASSERT(false,
                    fapi2::CME_SRAM_ACCESS_ERROR().set_ADDRESS(i_start_address),
                    "Invalid CME Start address alignment");
    }

    // Enable auto increment
    FAPI_INF("  CME display enable auto increment mode");
    l_data64.flush<0>().setBit<CSCR_AUTO_INCREMENT_BIT>();
    FAPI_TRY(fapi2::putScom(i_cme_target, EX_CSCR_OR, l_data64), "Error enabling auto increment mode");

    // Set the CME address
    // The SRAM address is defined as 16:28 (64k) but the CME only supports 32k, so mask off bit 16
    l_norm_address = i_start_address & 0x00007FF8;
    l_data64 = ((uint64_t)(l_norm_address)) << 32;

    FAPI_DBG("   CME Setting Read address (CSAR) to 0x%.16llX", l_data64);
    FAPI_TRY(fapi2::putScom(i_cme_target, EX_CSAR, l_data64), "Error setting read address in CSR");

    // Compute the number of words
    if ((l_norm_address + i_length_dword * 8) > 0x8000)
    {
        l_words_to_read = (0x8000 - l_norm_address) / 8;
    }
    else
    {
        l_words_to_read = i_length_dword;
    }

    FAPI_DBG("   Reading %d words From 0x%.8X to 0x%.8X", l_words_to_read, l_norm_address,
             l_norm_address + l_words_to_read * 8);

    // o_dwords_read will indicate the number of words successfully read.   Increment after each read.
    o_dwords_read = 0;

    for (uint32_t x = 0; x < l_words_to_read; x++)
    {
        FAPI_TRY(fapi2::getScom(i_cme_target, EX_CSDR, l_data64), "Error reading data from CSDR");
        o_data[x] = l_data64();
        o_dwords_read++;
    }

fapi_try_exit:
    FAPI_DBG("< p9_cme_sram_access");
    return fapi2::current_err;
}
