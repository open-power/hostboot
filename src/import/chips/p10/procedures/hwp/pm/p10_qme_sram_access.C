/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_qme_sram_access.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file  p10_qme_sram_access.C
/// @brief Access data to or from the targetted QME's SRAM array.
///
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : PM
// *HWP Consumed by     : HS:CRO:SBE
///

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <p10_qme_sram_access.H>
// @todo RTC 206154 Replace with generated header when available
//#include <p10_quad_scom_addresses.H>
#include <p10_pm_address_temp.C>

// ----------------------------------------------------------------------
// Constants
// ----------------------------------------------------------------------
const uint32_t QSAR_AUTO_INCREMENT_BIT = 63;

// These really should come from hcd_common
const uint32_t QME_SRAM_SIZE = 64 * 1024;
const uint32_t QME_SRAM_BASE_ADDR = 0xFFFF0000;

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

/// See doxygen in header file
fapi2::ReturnCode p10_qme_sram_access(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_qme_target,
    const uint32_t i_start_address,
    const uint32_t i_length_dword,
    const qmesram::Op i_operation,
    uint64_t*      io_data,
    uint32_t&      o_dwords_accessed)
{
    fapi2::buffer<uint64_t> l_data64;

    // These are initialized before being used.
    // Not doing an initial assignment to 0 to save space on the SBE.
    uint32_t        l_norm_address;
    uint32_t        l_words_to_access;

    FAPI_DBG("> p10_qme_sram_access");

    // Ensure the address is between 0xFFFF0000 and 0xFFFFFFFF.
    // No need to check the upper limit, since that will overflow the uint32_t data type.
    if (i_start_address < 0xFFFF0000)
    {
        // Return Error - invalid start address
        FAPI_DBG("Invalid Start Address 0x%.8X", i_start_address);
        FAPI_ASSERT(false,
                    fapi2::QME_SRAM_ACCESS_ERROR().set_ADDRESS(i_start_address),
                    "Invalid QME Start address");
    }

    if ((i_start_address & 0x00000007) != 0)
    {
        // Return Error - invalid start address alignment
        FAPI_DBG("Invalid Start Address alignment 0x%.8X", i_start_address);
        FAPI_ASSERT(false,
                    fapi2::QME_SRAM_ACCESS_ERROR().set_ADDRESS(i_start_address),
                    "Invalid QME Start address alignment");
    }

    // Set the QME address
    // The SRAM address is defined as 16:28 (64k)
    l_norm_address = i_start_address & 0x0000FFF8;
    l_data64.flush<0>().insertFromRight<0, 32>(l_norm_address).setBit<QSAR_AUTO_INCREMENT_BIT>();
    FAPI_DBG("   QME Setting Read address to 0x%016llX", l_data64);
    FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSAR, l_data64), "Error setting QME address in QSAR");

    // Compute the number of words
    if ((l_norm_address + i_length_dword * 8) > QME_SRAM_SIZE)
    {
        l_words_to_access = (QME_SRAM_SIZE - l_norm_address) / 8;
    }
    else
    {
        l_words_to_access = i_length_dword;
    }

    // o_dwords_accessed will indicate the number of words successfully accessed.
    // Increment after each access.
    o_dwords_accessed = 0;

    switch (i_operation)
    {
        case qmesram::GET:
            FAPI_DBG("   Reading %d words from 0x%.8X through 0x%.8X", l_words_to_access, l_norm_address,
                     l_norm_address + l_words_to_access * 8);

            for (uint32_t x = 0; x < l_words_to_access; x++)
            {
                FAPI_TRY(fapi2::getScom(i_qme_target, QME_QSDR, l_data64), "Error reading data from QSDR");
                io_data[x] = l_data64();
                o_dwords_accessed++;
            }

            break;

        case qmesram::PUT:
            FAPI_DBG("   Writing %d words to 0x%.8X through 0x%.8X", l_words_to_access, l_norm_address,
                     l_norm_address + l_words_to_access * 8);

            for (uint32_t x = 0; x < l_words_to_access; x++)
            {
                l_data64() = io_data[x];
                FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSDR, l_data64), "Error writing data to QSDR");
                o_dwords_accessed++;
            }

            break;
    }

fapi_try_exit:
    FAPI_DBG("< p10_qme_sram_access");
    return fapi2::current_err;
}
