/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_qme_sram_access.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#include <p10_pm_sram_access_utils.H>
#include <multicast_group_defs.H>
#include "p10_scom_eq.H"

using namespace scomt::eq;
enum DELAY_VALUE
{
    NS_DELAY = 1000000,// 1,000,000 ns = 1ms
    SIM_CYCLE_DELAY = 1000
};

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

/// @brief Internal function that that read/write data from/to the targetted
///        QME's SRAM array.
///
/// @param [in]  i_qme_target         EQ target
/// @param [in]  i_start_address      Start Address is between 0xFFFF80000 and 0xFFFFFFFF and must be 8B aligned
/// @param [in]  i_length             i_useByteBuffer = true : Length in bytes
///                                                     false: Length in double words
/// @param [in]  i_operation          Access operation to perform (GET/PUT/)
/// @param [out] io_data              In/Output Data pointer
/// @param [out] o_num_accessed       i_useByteBuffer = true : Number of byte accessed
///                                                     false: Number of double words accessed
/// @param [in]  i_useByteBuffer      true: data buffer is byte wide
///                                   false: data buffer is word wide.
///
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_qme_sram_access_internal(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_qme_target,
    const uint32_t i_start_address,
    const uint32_t i_length,
    const qmesram::Op i_operation,
    uint64_t*  io_data,
    uint32_t&  o_num_accessed,
    const bool i_useByteBuf = false)
{
    FAPI_DBG("> p10_qme_sram_access_internal - i_useByteBuf %d", i_useByteBuf);

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_qsar;
    fapi2::buffer<uint64_t> l_qscr;
    qmesram::Op     l_op;
    uint32_t l_timeout = 0;

    // These are initialized before being used.
    // Not doing an initial assignment to 0 to save space on the SBE.
    uint32_t l_norm_address;
    uint32_t l_words_to_access = i_length;

    if (i_useByteBuf)
    {
        l_words_to_access = i_length % 8 ? (i_length >> 3) + 1 : i_length >> 3; // 64-bit len
    }

    // Ensure the address is between 0xFFFF0000 and 0xFFFFFFFF.
    // No need to check the upper limit, since that will overflow the uint32_t data type.
    if (i_start_address < 0xFFFF0000)
    {
        // Return Error - invalid start address
        FAPI_DBG("Invalid Start Address 0x%.8X", i_start_address);
        FAPI_ASSERT(false,
                    fapi2::QME_SRAM_ACCESS_ERROR()
                    .set_ADDRESS(i_start_address)
                    .set_LENGTH(i_length)
                    .set_OPERATION(i_operation)
                    .set_USE_BYTE_BUFFER(i_useByteBuf)
                    .set_EQ_TARGET(i_qme_target),
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

    //Check the qme sram ownership access
    FAPI_TRY(fapi2::getScom(i_qme_target, QME_FLAGS_RW, l_data64));
    FAPI_TRY(fapi2::getScom(i_qme_target, QME_QSCR_RW, l_qscr));

    l_timeout = 100; //wait for 100 ms
    FAPI_DBG("Waiting for the ownership and access mode to be cleared");

    while (l_data64.getBit(22) || l_qscr.getBit(QME_QSCR_SRAM_ACCESS_MODE))
    {
        FAPI_TRY(fapi2::delay(NS_DELAY, SIM_CYCLE_DELAY));

        if (!l_timeout)
        {
            break;
        }

        FAPI_TRY(fapi2::getScom(i_qme_target, QME_FLAGS_RW, l_data64));
        FAPI_TRY(fapi2::getScom(i_qme_target, QME_QSCR_RW, l_qscr));
        l_timeout--;
    }

    if (!l_timeout)
    {
        FAPI_ERR("QME SRAM is not accessible , need to be retried");
        l_data64.flush<0>().setBit(0);
        FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSCR_WO_CLEAR, l_data64));

        FAPI_ASSERT(false,
                    fapi2::QME_SRAM_ACCESS_DENIED()
                    .set_EQ_TARGET(i_qme_target)
                    .set_QME_FLAG(l_data64)
                    .set_QSCR(l_qscr)
                    .set_ADDRESS(i_start_address)
                    .set_LENGTH(i_length)
                    .set_OPERATION(i_operation)
                    .set_USE_BYTE_BUFFER(i_useByteBuf),
                    "Invalid QME access denied");
    }

    //Set the SBE ownership bit
    l_data64.flush<0>().setBit(21);
    FAPI_TRY(fapi2::putScom(i_qme_target, QME_FLAGS_WO_OR, l_data64));

    // Set the QME SRAM address as defined by 16:28 (64k)
    l_norm_address = i_start_address & 0x0000FFF8;
    l_qsar.flush<0>().insertFromRight<0, 32>(l_norm_address);
    FAPI_DBG("   QME Setting address to 0x%016llX", l_qsar);
    FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSAR, l_qsar));

    // Compute the number of words
    if ((l_norm_address + l_words_to_access * 8) > QME_SRAM_SIZE)
    {
        l_words_to_access = (QME_SRAM_SIZE - l_norm_address) / 8;
    }

    // o_dwords_accessed will indicate the number of words successfully accessed.
    // Increment after each access.
    o_num_accessed = 0;

    // This switch is here to allow for each switching between auto-increment
    // and non-autoincrement (NOAUTOINC) modes.
    if (i_operation == qmesram::GET)
    {
        // l_op = qmesram::GET_NOAUTOINC;  // only needed for work-arounds
        l_op = qmesram::GET;
    }
    else if (i_operation == qmesram::PUT)
    {
        // l_op = qmesram::PUT_NOAUTOINC;  // only needed for work-arounds
        l_op = qmesram::PUT;
    }
    else
    {
        l_op = i_operation;
    }

    switch (l_op)
    {
        case qmesram::GET:
            FAPI_DBG("   Reading %d words from 0x%.8X through 0x%.8X in autoinc mode",
                     l_words_to_access, l_norm_address,
                     l_norm_address + l_words_to_access * 8);

            l_data64.flush<0>().setBit<QME_QSCR_SRAM_ACCESS_MODE>();
            FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSCR_WO_OR, l_data64)); // set autoincrement

            for (uint32_t x = 0; x < l_words_to_access; x++)
            {
                FAPI_TRY(fapi2::getScom(i_qme_target, QME_QSAR, l_data64));
                FAPI_DBG("   Get auto Address = 0x%016llX", l_data64);

                FAPI_TRY(fapi2::getScom(i_qme_target, QME_QSDR, l_data64));
                loadDataToBuffer(i_useByteBuf, l_data64(), &io_data[x]);
                o_num_accessed++;
            }

            break;

        case qmesram::GET_NOAUTOINC:
            FAPI_DBG("   Reading %d words from 0x%.8X through 0x%.8X in loop mode",
                     l_words_to_access, l_norm_address,
                     l_norm_address + l_words_to_access * 8);

            l_data64.flush<0>().setBit<QME_QSCR_SRAM_ACCESS_MODE>();
            FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSCR_WO_CLEAR, l_data64));  // clear autoincrement

            for (uint32_t x = 0; x < l_words_to_access; x++)
            {
                FAPI_TRY(fapi2::getScom(i_qme_target, QME_QSAR, l_data64));
                FAPI_DBG("   Get no auto Address = 0x%016llX", l_data64);

                FAPI_TRY(fapi2::getScom(i_qme_target, QME_QSDR, l_data64));
                loadDataToBuffer(i_useByteBuf, l_data64(), &io_data[x]);
                o_num_accessed++;
                l_qsar += 0x0000000800000000;
                FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSAR, l_qsar));
            }

            break;

        case qmesram::PUT:
            FAPI_DBG("   Writing %d words to 0x%.8X through 0x%.8X in autoinc mode",
                     l_words_to_access, l_norm_address,
                     l_norm_address + l_words_to_access * 8);

            l_data64.flush<0>().setBit<QME_QSCR_SRAM_ACCESS_MODE>();
            FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSCR_WO_OR, l_data64)); // set autoincrement

            for (uint32_t x = 0; x < l_words_to_access; x++)
            {
                FAPI_TRY(qme_sram_read_qsar(i_qme_target));
                getDataFromBuffer(i_useByteBuf, &io_data[x], l_data64());
                FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSDR, l_data64()));
                o_num_accessed++;
            }

            break;

        case qmesram::PUT_NOAUTOINC:
            FAPI_DBG("   Writing %d words to 0x%.8X through 0x%.8X in loop mode",
                     l_words_to_access, l_norm_address,
                     l_norm_address + l_words_to_access * 8);

            l_data64.flush<0>().setBit<QME_QSCR_SRAM_ACCESS_MODE>();
            FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSCR_WO_CLEAR, l_data64));  // clear autoincrement

            for (uint32_t x = 0; x < l_words_to_access; x++)
            {
                FAPI_TRY(qme_sram_read_qsar(i_qme_target));

                getDataFromBuffer(i_useByteBuf, &io_data[x], l_data64());
                FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSDR, l_data64));
                o_num_accessed++;
                l_qsar += 0x0000000800000000;
                FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSAR, l_qsar));
            }

            break;
    }

    //Clear the SBE ownership bit
    l_data64.flush<0>().setBit(21);
    FAPI_TRY(fapi2::putScom(i_qme_target, QME_FLAGS_WO_CLEAR, l_data64));

    l_data64.flush<0>().setBit<QME_QSCR_SRAM_ACCESS_MODE>();
    FAPI_TRY(fapi2::putScom(i_qme_target, QME_QSCR_WO_CLEAR, l_data64));  // clear autoincrement

    // Number of bytes accessed
    if (i_useByteBuf)
    {
        o_num_accessed = o_num_accessed * 8;
    }

fapi_try_exit:
    FAPI_DBG("< p10_qme_sram_access_internal");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////////////////////////////
/// See doxygen in header file
fapi2::ReturnCode p10_qme_sram_access(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_qme_target,
    const uint32_t i_start_address,
    const uint32_t i_length_dword,
    const qmesram::Op i_operation,
    uint64_t*      io_data,
    uint32_t&      o_dwords_accessed)
{
    FAPI_DBG("> p10_qme_sram_access");
    return (p10_qme_sram_access_internal(
                i_qme_target,
                i_start_address,
                i_length_dword,
                i_operation,
                io_data,
                o_dwords_accessed));
}

////////////////////////////////////////////////////////////////////////////////
/// See doxygen in header file
fapi2::ReturnCode p10_qme_sram_access_bytes(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_qme_target,
    const uint32_t i_start_address,
    const uint32_t i_length_bytes,
    const qmesram::Op i_operation,
    uint8_t*      io_data,
    uint32_t&     o_bytes_accessed)
{
    FAPI_DBG("> p10_qme_sram_access_bytes");
    return  (p10_qme_sram_access_internal(
                 i_qme_target,
                 i_start_address,
                 i_length_bytes,
                 i_operation,
                 reinterpret_cast<uint64_t*>(io_data),
                 o_bytes_accessed,
                 true));  // Byte buffer
}
