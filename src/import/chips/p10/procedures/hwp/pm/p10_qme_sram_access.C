/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_qme_sram_access.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
#include <multicast_group_defs.H>
#include "p10_scom_eq.H"

using namespace scomt::eq;

// ----------------------------------------------------------------------
// Constants
// ----------------------------------------------------------------------
const uint32_t QSAR_AUTO_INCREMENT_BIT = 63;
const uint32_t QSCR_SRAM_ACCESS_MODE_BIT = 0;

// These really should come from hcd_common RTC 210851
const uint32_t QME_SRAM_SIZE = 64 * 1024;
const uint32_t QME_SRAM_BASE_ADDR = 0xFFFF0000;


// -----------------------------------------------------------------------------
//  Loal Functions
// -----------------------------------------------------------------------------
fapi2::ReturnCode qme_sram_read_qsar(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_qme_target)
{
    fapi2::buffer<uint64_t> l_data64;

    auto l_chip = i_qme_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
    auto l_eq_vector = l_chip.getChildren<fapi2::TARGET_TYPE_EQ> (fapi2::TARGET_STATE_FUNCTIONAL);

    for (auto& eq : l_eq_vector)
    {
        FAPI_TRY(fapi2::getScom(eq, QME_QSAR, l_data64));
        FAPI_DBG("   QSAR = 0x%016llX", l_data64);
    }

fapi_try_exit:
    return fapi2::current_err;
}



// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

/// See doxygen in header file
fapi2::ReturnCode p10_qme_sram_access(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_qme_target,
    const uint32_t i_start_address,
    const uint32_t i_length_dword,
    const qmesram::Op i_operation,
    uint64_t*      io_data,
    uint32_t&      o_dwords_accessed)
{
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_qsar;
    qmesram::Op     l_op;

    // These are initialized before being used.
    // Not doing an initial assignment to 0 to save space on the SBE.
    uint32_t        l_norm_address;
    uint32_t        l_words_to_access;
    // Clear the core selects so that multicast to the QMEs will work
    uint32_t l_core_select = 0;

    FAPI_DBG("> p10_qme_sram_access");

    fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > l_chip =
        i_qme_target.getParent< fapi2::TARGET_TYPE_PROC_CHIP >();

    fapi2::Target < fapi2::TARGET_TYPE_EQ |
    fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > l_target =
        l_chip.getMulticast<fapi2::MULTICAST_AND>(fapi2::MCGROUP_GOOD_EQ,
                static_cast<fapi2::MulticastCoreSelect>(l_core_select));

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

    // Set the QME SRAM address as defined by 16:28 (64k)
    l_norm_address = i_start_address & 0x0000FFF8;
    l_data64.flush<0>().insertFromRight<0, 32>(l_norm_address);
    FAPI_DBG("   QME Setting address to 0x%016llX", l_data64);
    FAPI_TRY(fapi2::putScom(l_target, QME_QSAR, l_data64));

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

    // RTC 211508 Get around HW501715 where auto-increment doesn't work
    if (i_operation == qmesram::GET)
    {
        l_op = qmesram::GET_NOAUTOINC;
//        l_op = qmesram::GET;
    }
    else if (i_operation == qmesram::PUT)
    {
        l_op = qmesram::PUT_NOAUTOINC;
//        l_op = qmesram::PUT;
    }
    else
    {
        l_op = i_operation;
    }

    switch (l_op)
    {
        case qmesram::GET:
//             if (l_target.isMulticast())
//             {
//                 FAPI_ERR("   ERROR:  Multicast GET is not supported");
//                 fapi2::current_err = fapi2::FAPI2_RC_INVALID_PARAMETER;
//                 goto fapi_try_exit;
//             }

            l_data64.flush<0>().setBit<QSCR_SRAM_ACCESS_MODE_BIT>();
            FAPI_TRY(fapi2::putScom(l_target, QME_QSCR_WO_OR, l_data64));

            FAPI_DBG("   Reading %d words from 0x%.8X through 0x%.8X in autoinc mode", l_words_to_access, l_norm_address,
                     l_norm_address + l_words_to_access * 8);

            for (uint32_t x = 0; x < l_words_to_access; x++)
            {
                FAPI_TRY(fapi2::getScom(i_qme_target, QME_QSAR, l_data64));
                FAPI_DBG("   Get auto Address = 0x%016llX", l_data64);

                FAPI_TRY(fapi2::getScom(i_qme_target, QME_QSDR, l_data64));
                io_data[x] = l_data64();
                o_dwords_accessed++;
            }

            break;

        case qmesram::GET_NOAUTOINC:
//             if (l_target.isMulticast())
//             {
//                 FAPI_ERR("   ERROR:  Multicast GET is not supported");
//                 fapi2::current_err = fapi2::FAPI2_RC_INVALID_PARAMETER;
//                 goto fapi_try_exit;
//             }

            FAPI_DBG("   Reading %d words from 0x%.8X through 0x%.8X in loop mode",
                     l_words_to_access, l_norm_address,
                     l_norm_address + l_words_to_access * 8);

            for (uint32_t x = 0; x < l_words_to_access; x++)
            {
                FAPI_TRY(fapi2::getScom(i_qme_target, QME_QSAR, l_data64));
                FAPI_DBG("   Get no auto Address = 0x%016llX", l_data64);

                FAPI_TRY(fapi2::getScom(i_qme_target, QME_QSDR, l_data64));
                io_data[x] = l_data64();
                o_dwords_accessed++;
//                l_qsar += 0x0000000800000000;
                l_qsar += 0x0000001000000000;
                FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSAR, l_qsar));
            }

            break;

        case qmesram::PUT:
            l_data64.flush<0>().setBit<QSCR_SRAM_ACCESS_MODE_BIT>();
            FAPI_TRY(fapi2::putScom(l_target, QME_QSCR_WO_OR, l_data64));

            FAPI_DBG("   Writing %d words to 0x%.8X through 0x%.8X in autoinc mode",
                     l_words_to_access, l_norm_address,
                     l_norm_address + l_words_to_access * 8);

            for (uint32_t x = 0; x < l_words_to_access; x++)
            {
                FAPI_TRY(qme_sram_read_qsar(l_target));

                l_data64() = io_data[x];
                FAPI_TRY(fapi2::putScom(l_target, QME_QSDR, l_data64));
                o_dwords_accessed++;
            }

            break;

        case qmesram::PUT_NOAUTOINC:
            FAPI_DBG("   Writing %d words to 0x%.8X through 0x%.8X in loop mode",
                     l_words_to_access, l_norm_address,
                     l_norm_address + l_words_to_access * 8);

            for (uint32_t x = 0; x < l_words_to_access; x++)
            {
                FAPI_TRY(qme_sram_read_qsar(l_target));

                l_data64() = io_data[x];
                FAPI_TRY(fapi2::putScom(l_target, QME_QSDR, l_data64));
                o_dwords_accessed++;
//                l_qsar += 0x0000000800000000;
                l_qsar += 0x0000001000000000;
                FAPI_TRY(fapi2::putScom(l_target, QME_QSAR, l_qsar));
            }

            break;
    }

fapi_try_exit:
    FAPI_DBG("< p10_qme_sram_access");
    return fapi2::current_err;
}
