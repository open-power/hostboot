/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_ocb_indir_access.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
/// @file p10_pm_ocb_indir_access.C
/// @brief Performs the data transfer to/from an OCB indirect channel

// *HWP HW Owmer        : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : PM
// *HWP Consumed by     : SBE:HS

///
/// High-level procedure flow:
/// @verbatim
///     1) Check if the channel for access is valid.
///     2) For the PUT operation, the data from the buffer will be written
///        into the OCB Data register in blocks of 64bits;
///        from where eventually the data will be written to SRAM.
///     3) For GET operation, the data read from the SRAM will be retrieved from
///        the DATA register and written into the buffer in blocks of 64 bits.
/// @endverbatim
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p10_pm_ocb_indir_access.H>
#include <p10_pm_sram_access_utils.H>
#include "p10_scom_proc.H"

using namespace scomt::proc;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

enum
{
    OCB_FULL_POLL_MAX = 4,
    OCB_FULL_POLL_DELAY_HDW = 0,
    OCB_FULL_POLL_DELAY_SIM = 0
};

enum
{
    OCBSCR_STREAM_MODE_DISABLE = 0,
    OCBSCR_STREAM_MODE_ENABLE  = 1,
    OCBSCR_STREAM_TYPE_LINEAR  = 0,
    OCBSCR_STREAM_TYPE_STREAM  = 1
};

const static uint32_t OCBSCR_STREAM_MODE_BIT = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_MODE;
const static uint32_t OCBSCR_STREAM_TYPE_BIT = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_OCB_STREAM_TYPE;
const static uint32_t OCBSHCS_PUSH_ENABLE_BIT = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0_PUSH_ENABLE;

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

/// @brief Internal function that provides for the abstract access to an OCB
/// indirect channel that has been configured previously via
/// p9_pm_ocb_indir_setup_[linear/circular] procedures
///
/// @param[in]     &i_target           Chip target
/// @param[in]     i_ocb_chan          OCB channel number (0, 1, 2, 3)
/// @param[in]     i_ocb_op            Operation (Get, Put)
/// @param[in]     i_ocb_req_length    i_useByteBuf = true : Length in bytes
///                                                   false: Length in double words
/// @param[in]     i_oci_address_valid Indicator that oci_address is to be used
/// @param[in]     i_oci_address       OCI Address to be used for the operation
/// @param [out]   o_ocb_act_length    i_useByteBuf = true : Number of byte accessed
///                                                   false: Number of double words accessed
/// @param[in/out] io_ocb_buffer       Pointer to a container of type uint64_t
///                                    to store the data to be written into or
///                                    obtained from OCC SRAM
/// @param [in]  i_useByteBuf      true: data buffer is byte wide
///                                   false: data buffer is double word wide.
/// @return FAPI2_RC_SUCCESS on success, else error.
fapi2::ReturnCode p10_pm_ocb_indir_access_internal(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const ocb::PM_OCB_CHAN_NUM    i_ocb_chan,
    const ocb::PM_OCB_ACCESS_OP   i_ocb_op,
    const uint32_t                i_ocb_req_length,
    const bool                    i_oci_address_valid,
    const uint32_t                i_oci_address,
    uint32_t&                     o_ocb_act_length,
    uint64_t*                     io_ocb_buffer,
    const bool                    i_useByteBuf = false)
{
    FAPI_DBG("> p10_pm_ocb_indir_access - i_useByteBuf %d", i_useByteBuf);
    FAPI_DBG("Channel : %d, Operation : %d, No.of 8B Blocks of Data: %d",
             i_ocb_chan, i_ocb_op, i_ocb_req_length);

    uint64_t l_OCBAR_address   = 0;
    uint64_t l_OCBDR_address   = 0;
    uint64_t l_OCBCSR_address  = 0;

    uint64_t l_OCBSHCS_address = 0;
    o_ocb_act_length = 0;

    fapi2::buffer<uint64_t> l_data64;

    FAPI_DBG("Checking channel validity");

    bool l_push_ok_flag = false;

    uint32_t l_words_to_access = i_ocb_req_length;

    if (i_useByteBuf)
    {
        l_words_to_access = i_ocb_req_length % 8 ?
                            (i_ocb_req_length >> 3) + 1 : i_ocb_req_length >> 3; // 64-bit len
    }

    switch ( i_ocb_chan )
    {
        case ocb::OCB_CHAN0:
            l_OCBAR_address   = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0;
            l_OCBDR_address   = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR0;
            l_OCBCSR_address  = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_RO;
            l_OCBSHCS_address = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0;
            break;

        case ocb::OCB_CHAN1:
            l_OCBAR_address   = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1;
            l_OCBDR_address   = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR1;
            l_OCBCSR_address  = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_RO;
            l_OCBSHCS_address = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS1;
            break;

        case ocb::OCB_CHAN2:
            l_OCBAR_address   = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2;
            l_OCBDR_address   = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR2;
            l_OCBCSR_address  = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_RO;
            l_OCBSHCS_address = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2;
            break;

        case ocb::OCB_CHAN3:
            l_OCBAR_address   = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3;
            l_OCBDR_address   = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBDR3;
            l_OCBCSR_address  = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_RO;
            l_OCBSHCS_address = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3;
            break;
    }

    // Verify if a valid valid address provided
    // If the address is provided
    //     Use it for the Get / Put operation
    //     The following cases apply:
    //     Circular      : OCBAR is irrelevant; write it anyway
    //     Linear        : OCBAR will set the accessed location
    //     Linear Stream : OCBAR will establish the address from which
    //                     auto-increment will commence after the first access
    // Else
    //     Circular      : OCBAR is irrelevant
    //     Linear        : OCBAR will continue to access the same location
    //     Linear Stream : OCBAR will auto-increment
    if ( i_oci_address_valid )
    {
        FAPI_DBG(" OCI Address : 0x%08X", i_oci_address);
        l_data64.flush<0>().insert<0, 32>(i_oci_address);
        FAPI_TRY(fapi2::putScom(i_target, l_OCBAR_address, l_data64));
    }

    // PUT Operation: Write data to the SRAM in the given location
    //                via the OCB channel
    if ( i_ocb_op == ocb::OCB_PUT )
    {
        FAPI_INF("OCB access for data write operation");
        FAPI_ASSERT(io_ocb_buffer != NULL,
                    fapi2::PM_OCB_PUT_NO_DATA_ERROR().
                    set_CHANNEL(i_ocb_chan).
                    set_DATA_SIZE(i_ocb_req_length),
                    "No data provided for PUT operation");

        FAPI_TRY(fapi2::getScom(i_target, l_OCBCSR_address, l_data64));

        // The following check for circular mode is an additional check
        // performed to ensure a valid data access.
        if (l_data64.getBit<OCBSCR_STREAM_MODE_BIT>() &&
            l_data64.getBit<OCBSCR_STREAM_TYPE_BIT>())
        {
            FAPI_DBG("Circular mode detected.");
            // Check if push queue is enabled. If not, let the store occur
            // anyway to let the PIB error response return occur. (that is
            // what will happen if this checking code were not here)
            FAPI_TRY(fapi2::getScom(i_target, l_OCBSHCS_address, l_data64));

            if (l_data64.getBit<OCBSHCS_PUSH_ENABLE_BIT>())
            {
                FAPI_DBG("Poll for a non-full condition to a push queue to "
                         "avoid data corruption problem");
                uint8_t l_counter = 0;

                do
                {
                    // If the OCB_OCI_OCBSHCS0_PUSH_FULL bit (bit 0) is clear,
                    // proceed. Otherwise, poll
                    if (!l_data64.getBit<0>())
                    {
                        l_push_ok_flag = true;
                        FAPI_DBG("Push queue not full. Proceeding");
                        break;
                    }

                    // Delay, before next polling.
                    fapi2::delay(OCB_FULL_POLL_DELAY_HDW,
                                 OCB_FULL_POLL_DELAY_SIM);

                    FAPI_TRY(fapi2::getScom(i_target,
                                            l_OCBSHCS_address,
                                            l_data64));
                    l_counter++;
                }
                while (l_counter < OCB_FULL_POLL_MAX);


                switch ( i_ocb_chan )
                {
                    case ocb::OCB_CHAN0:
                        FAPI_ASSERT((true == l_push_ok_flag),
                                    fapi2::PM_OCB0_PUT_DATA_POLL_NOT_FULL_ERROR().
                                    set_CHANNEL(i_ocb_chan).
                                    set_DATA_SIZE(i_ocb_req_length).
                                    set_TARGET(i_target),
                                    "Polling timeout waiting on push non-full");
                        break;

                    case ocb::OCB_CHAN1:
                        FAPI_ASSERT((true == l_push_ok_flag),
                                    fapi2::PM_OCB1_PUT_DATA_POLL_NOT_FULL_ERROR().
                                    set_CHANNEL(i_ocb_chan).
                                    set_DATA_SIZE(i_ocb_req_length).
                                    set_TARGET(i_target),
                                    "Polling timeout waiting on push non-full");
                        break;

                    case ocb::OCB_CHAN2:
                        FAPI_ASSERT((true == l_push_ok_flag),
                                    fapi2::PM_OCB2_PUT_DATA_POLL_NOT_FULL_ERROR().
                                    set_CHANNEL(i_ocb_chan).
                                    set_DATA_SIZE(i_ocb_req_length).
                                    set_TARGET(i_target),
                                    "Polling timeout waiting on push non-full");
                        break;

                    case ocb::OCB_CHAN3:
                        FAPI_ASSERT((true == l_push_ok_flag),
                                    fapi2::PM_OCB3_PUT_DATA_POLL_NOT_FULL_ERROR().
                                    set_CHANNEL(i_ocb_chan).
                                    set_DATA_SIZE(i_ocb_req_length).
                                    set_TARGET(i_target),
                                    "Polling timeout waiting on push non-full");
                        break;
                }
            }
        }

        // Walk the input buffer (io_ocb_buffer) 8B (64bits) at a time to write
        // the channel data register
        for(uint32_t l_index = 0; l_index < l_words_to_access; l_index++)
        {
            fapi2::ReturnCode l_rc;
            getDataFromBuffer(i_useByteBuf, &io_ocb_buffer[l_index], l_data64());

            /* The data read is done via this getscom operation.
             * A data write failure will be logged off as a simple scom failure.
             * Need to find a way to distiniguish this error and collect
             * additional information incase of a failure.*/
            // @TODO RTC 173286 - FAPI2:  FAPI_TRY (or surrogate name)
            //                    that allows access to the return code for
            //                    HWP reactionFAPI_TRY(fapi2::getScom(i_target, l_OCBAR_address, l_data64));

            l_rc = fapi2::putScom(i_target, l_OCBDR_address, l_data64);

            if (l_rc)
            {
                switch ( i_ocb_chan )
                {
                    case ocb::OCB_CHAN0:
                        FAPI_ASSERT(false,
                                    fapi2::PM_OCB0_PUT_DATA_ERROR().
                                    set_CHANNEL(i_ocb_chan).
                                    set_DATA_SIZE(i_ocb_req_length).
                                    set_TARGET(i_target),
                                    "Get access to channel register failed");
                        break;

                    case ocb::OCB_CHAN1:
                        FAPI_ASSERT(false,
                                    fapi2::PM_OCB1_PUT_DATA_ERROR().
                                    set_CHANNEL(i_ocb_chan).
                                    set_DATA_SIZE(i_ocb_req_length).
                                    set_TARGET(i_target),
                                    "Get access to channel register failed");
                        break;

                    case ocb::OCB_CHAN2:
                        FAPI_ASSERT(false,
                                    fapi2::PM_OCB2_PUT_DATA_ERROR().
                                    set_CHANNEL(i_ocb_chan).
                                    set_DATA_SIZE(i_ocb_req_length).
                                    set_TARGET(i_target),
                                    "Get access to channel register failed");
                        break;

                    case ocb::OCB_CHAN3:
                        FAPI_ASSERT(false,
                                    fapi2::PM_OCB3_PUT_DATA_ERROR().
                                    set_CHANNEL(i_ocb_chan).
                                    set_DATA_SIZE(i_ocb_req_length).
                                    set_TARGET(i_target),
                                    "Get access to channel register failed");
                        break;
                }

                goto fapi_try_exit;
            } //end of l_rc

            o_ocb_act_length++;
            FAPI_DBG("data(64 bits): 0x%016lX written to channel data register",
                     io_ocb_buffer[l_index]);
        }

        FAPI_DBG("%d blocks(64bits each) of data put", o_ocb_act_length);
    }
    // GET Operation: Data read from the given location in SRAM via OCB channel
    else if( i_ocb_op == ocb::OCB_GET )
    {
        FAPI_INF("OCB access for data read operation");

        fapi2::buffer<uint64_t> l_data64;
        fapi2::ReturnCode l_rc;

        // Read data from the Channel Data Register in blocks of 64 bits.
        for (uint32_t l_loopCount = 0; l_loopCount < l_words_to_access;
             l_loopCount++)
        {
#ifndef __PPE__
            FAPI_TRY(fapi2::getScom(i_target, l_OCBAR_address, l_data64));
            FAPI_DBG(" Get OCI Address from 0x%08X: 0x%08X", l_OCBAR_address, l_data64 >> 32);
#endif
            /* The data read is done via this getscom operation.
             * A data read failure will be logged off as a simple scom failure.
             * Need to find a way to distiniguish this error and collect
             * additional information incase of a failure.*/
            // @TODO RTC 173286 - FAPI2:  FAPI_TRY (or surrogate name)
            //                    that allows access to the return code for
            //                    HWP reaction
            l_rc = fapi2::getScom(i_target, l_OCBDR_address, l_data64);

            if (l_rc)
            {
                FAPI_ERR("OCBDR%d getscom error;  rc = 0x%08X", i_ocb_chan, (uint32_t)l_rc);
#define FFDCREG(_m_addr, _m_string) \
    FAPI_TRY(fapi2::getScom(i_target, _m_addr, l_data64)); \
    FAPI_ERR("%-10s %d: 0x%016lX", #_m_string, l_data64);

                uint64_t l_OCBSLBR_address = 0;
                uint64_t l_OCBSLCS_address = 0;
                uint64_t l_OCBSHBR_address = 0;
                uint64_t l_OCBSES_address  = 0;
                uint64_t l_OCBLWCR_address = 0;
                uint64_t l_OCBLWSR_address = 0;
                uint64_t l_OCBESR_address  = 0;

                switch ( i_ocb_chan )
                {
                    case ocb::OCB_CHAN0:
                        l_OCBSLBR_address = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0;
                        l_OCBSLCS_address = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0;
                        l_OCBSHBR_address = TP_TPCHIP_OCC_OCI_OCB_OCBSHBR0;
                        l_OCBSES_address  = TP_TPCHIP_OCC_OCI_OCB_OCBSES0;
                        l_OCBLWCR_address = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0;
                        l_OCBLWSR_address = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR0;
                        l_OCBESR_address  = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0;
                        break;

                    case ocb::OCB_CHAN1:
                        l_OCBSLBR_address = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1;
                        l_OCBSLCS_address = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1;
                        l_OCBSHBR_address = TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1;
                        l_OCBSES_address  = TP_TPCHIP_OCC_OCI_OCB_OCBSES1;
                        l_OCBLWCR_address = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1;
                        l_OCBLWSR_address = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR1;
                        l_OCBESR_address  = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1;
                        break;

                    case ocb::OCB_CHAN2:
                        l_OCBSLBR_address = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2;
                        l_OCBSLCS_address = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2;
                        l_OCBSHBR_address = TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2;
                        l_OCBSES_address  = TP_TPCHIP_OCC_OCI_OCB_OCBSES2;
                        l_OCBLWCR_address = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2;
                        l_OCBLWSR_address = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR2;
                        l_OCBESR_address  = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2;
                        break;

                    case ocb::OCB_CHAN3:
                        l_OCBSLBR_address = TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3;
                        l_OCBSLCS_address = TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3;
                        l_OCBSHBR_address = TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3;
                        l_OCBSES_address  = TP_TPCHIP_OCC_OCI_OCB_OCBSES3;
                        l_OCBLWCR_address = TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3;
                        l_OCBLWSR_address = TP_TPCHIP_OCC_OCI_OCB_OCBLWSR3;
                        l_OCBESR_address  = TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3;
                        break;
                }

                FFDCREG(l_OCBAR_address  , OCBAR);
                FFDCREG(l_OCBCSR_address , OCBCSR);
                FFDCREG(l_OCBSLBR_address, OCBSLBR);
                FFDCREG(l_OCBSLCS_address, OCBSLCS);
                FFDCREG(l_OCBSHBR_address, OCBSHBR);
                FFDCREG(l_OCBSHCS_address, OCBSHCS);
                FFDCREG(l_OCBSES_address , OCBSES);
                FFDCREG(l_OCBLWCR_address, OCBLWCR);
                FFDCREG(l_OCBLWSR_address, OCBLWSR);
                FFDCREG(l_OCBESR_address , OCBESR);
                FFDCREG(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OEAR,  OEAR);
//              May want this to be a callback to gather the above registers
//              and add to an error log.

                switch ( i_ocb_chan )
                {
                    case ocb::OCB_CHAN0:
                        FAPI_ASSERT((true == l_push_ok_flag),
                                    fapi2::PM_OCB0_GET_DATA_ERROR().
                                    set_CHANNEL(i_ocb_chan).
                                    set_DATA_SIZE(i_ocb_req_length).
                                    set_TARGET(i_target),
                                    "Get access to channel register failed");
                        break;

                    case ocb::OCB_CHAN1:
                        FAPI_ASSERT((true == l_push_ok_flag),
                                    fapi2::PM_OCB1_GET_DATA_ERROR().
                                    set_CHANNEL(i_ocb_chan).
                                    set_DATA_SIZE(i_ocb_req_length).
                                    set_TARGET(i_target),
                                    "Get access to channel register failed");
                        break;

                    case ocb::OCB_CHAN2:
                        FAPI_ASSERT((true == l_push_ok_flag),
                                    fapi2::PM_OCB2_GET_DATA_ERROR().
                                    set_CHANNEL(i_ocb_chan).
                                    set_DATA_SIZE(i_ocb_req_length).
                                    set_TARGET(i_target),
                                    "Get access to channel register failed");
                        break;

                    case ocb::OCB_CHAN3:
                        FAPI_ASSERT((true == l_push_ok_flag),
                                    fapi2::PM_OCB3_GET_DATA_ERROR().
                                    set_CHANNEL(i_ocb_chan).
                                    set_DATA_SIZE(i_ocb_req_length).
                                    set_TARGET(i_target),
                                    "Get access to channel register failed");
                        break;
                }

                goto fapi_try_exit;
            }

            loadDataToBuffer(i_useByteBuf, l_data64(), &io_ocb_buffer[l_loopCount]);
            o_ocb_act_length++;
            FAPI_DBG("data(64 bits): 0x%016lX read from channel data register",
                     io_ocb_buffer[l_loopCount]);
        }

        FAPI_DBG("%d blocks(64bits each) of data retrieved",
                 o_ocb_act_length);
    }

    // Number of bytes accessed
    if (i_useByteBuf)
    {
        o_ocb_act_length = o_ocb_act_length * 8;
    }

fapi_try_exit:

    FAPI_DBG("< p10_pm_ocb_indir_access...");
    return fapi2::current_err;

}

////////////////////////////////////////////////////////////////////////////////
/// See doxygen in header file
fapi2::ReturnCode p10_pm_ocb_indir_access(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const ocb::PM_OCB_CHAN_NUM    i_ocb_chan,
    const ocb::PM_OCB_ACCESS_OP   i_ocb_op,
    const uint32_t                i_ocb_req_length,
    const bool                    i_oci_address_valid,
    const uint32_t                i_oci_address,
    uint32_t&                     o_ocb_act_length,
    uint64_t*                     io_ocb_buffer)
{
    FAPI_DBG("> p10_pm_ocb_indir_access");
    return (p10_pm_ocb_indir_access_internal(
                i_target,
                i_ocb_chan,
                i_ocb_op,
                i_ocb_req_length,
                i_oci_address_valid,
                i_oci_address,
                o_ocb_act_length,
                io_ocb_buffer));
}

////////////////////////////////////////////////////////////////////////////////
/// See doxygen in header file
fapi2::ReturnCode p10_pm_ocb_indir_access_bytes(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const ocb::PM_OCB_CHAN_NUM    i_ocb_chan,
    const ocb::PM_OCB_ACCESS_OP   i_ocb_op,
    const uint32_t                i_ocb_req_length,
    const bool                    i_oci_address_valid,
    const uint32_t                i_oci_address,
    uint32_t&                     o_ocb_act_length,
    uint8_t*                      io_ocb_buffer)
{
    FAPI_DBG("> p10_pm_ocb_indir_access_bytes");
    return (p10_pm_ocb_indir_access_internal(
                i_target,
                i_ocb_chan,
                i_ocb_op,
                i_ocb_req_length,
                i_oci_address_valid,
                i_oci_address,
                o_ocb_act_length,
                reinterpret_cast<uint64_t*>(io_ocb_buffer),
                true));
}
