/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_ocb_indir_access.C $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// @file p9_pm_ocb_indir_access.C
/// @brief Performs the data transfer to/from an OCB indirect channel

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP HWP Backup Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : FSP:HS

///
/// High-level procedure flow:
/// @verbatim
///     1) Check if the channel for access is valid.
///     2) For the PUT operation, the data from the buffer will be written
///        into the OCB Data register in blocks of 64bits;
///        from where eventually the data will be written to SRAM.
///     3) For GET operation, the data read from the SRAM will be retrieved from
///        the DATA register and written into the buffer in blocks of 64bits.
/// @endverbatim
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_pm_ocb_indir_access.H>

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

enum
{
    OCB_FULL_POLL_MAX = 4,
    OCB_FULL_POLL_DELAY_HDW = 0,
    OCB_FULL_POLL_DELAY_SIM = 0
};

fapi2::ReturnCode p9_pm_ocb_indir_access(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9ocb::PM_OCB_CHAN_NUM  i_ocb_chan,
    const p9ocb::PM_OCB_ACCESS_OP i_ocb_op,
    const uint32_t                i_ocb_req_length,
    const bool                    i_oci_address_valid,
    const uint32_t                i_oci_address,
    uint32_t&                     o_ocb_act_length,
    fapi2::variable_buffer&       io_ocb_buffer)
{
    FAPI_IMP("Enter p9_pm_ocb_indir_access...");
    FAPI_DBG("i_target 0x%08llx, ocb_chan %d, ocb_op %d, ocb_req_length %d,"
             " i_oci_address_valid %d, i_oci_address 0x%08X", i_target.get(),
             i_ocb_chan, i_ocb_op, i_ocb_req_length, i_oci_address_valid,
             i_oci_address);

    uint64_t l_OCBAR_address   = 0;
    uint64_t l_OCBDR_address   = 0;
    uint64_t l_OCBCSR_address  = 0;
    uint64_t l_OCBSHCS_address = 0;

    FAPI_DBG("Checking channel validity");

    switch ( i_ocb_chan )
    {
        case p9ocb::OCB_CHAN0:
            l_OCBAR_address   = PU_OCB_PIB_OCBAR0;
            l_OCBDR_address   = PU_OCB_PIB_OCBDR0;
            l_OCBCSR_address  = PU_OCB_PIB_OCBCSR0_RO;
            l_OCBSHCS_address = PU_OCB_OCI_OCBSHCS0_OCI;
            break;

        case p9ocb::OCB_CHAN1:
            l_OCBAR_address   = PU_OCB_PIB_OCBAR1;
            l_OCBDR_address   = PU_OCB_PIB_OCBDR1;
            l_OCBCSR_address  = PU_OCB_PIB_OCBCSR1_RO;
            l_OCBSHCS_address = PU_OCB_OCI_OCBSHCS1_OCI;
            break;

        case p9ocb::OCB_CHAN2:
            l_OCBAR_address   = PU_OCB_PIB_OCBAR2;
            l_OCBDR_address   = PU_OCB_PIB_OCBDR2;
            l_OCBCSR_address  = PU_OCB_PIB_OCBCSR2_RO;
            l_OCBSHCS_address = PU_OCB_OCI_OCBSHCS2_OCI;
            break;

        case p9ocb::OCB_CHAN3:
            l_OCBAR_address   = PU_OCB_PIB_OCBAR3;
            l_OCBDR_address   = PU_OCB_PIB_OCBDR3;
            l_OCBCSR_address  = PU_OCB_PIB_OCBCSR0_RO;
            l_OCBSHCS_address = PU_OCB_OCI_OCBSHCS3_OCI;
            break;
    }

    // Deal with oci_address_valid condition.
    // If address is valid, write the relevant channel OCBAR
    if ( i_oci_address_valid )
    {
        // The following cases apply:
        //    Circular Channel:   OCBAR is irrelevant; write it anyway
        //    Linear:             OCBAR will set the accessed location
        //    Linear Stream:      OCBAR will establish the address from which
        //                            auto-increment will commence after
        //                            the first access
        fapi2::buffer<uint64_t> l_data64;
        l_data64.insert<0, 32>(i_oci_address);

        FAPI_TRY(fapi2::putScom(i_target, l_OCBAR_address, l_data64));

    }

    //  The else case is to not touch the OCBAR.
    //  The following cases apply:
    //     Circular Channel:   OCBAR is irrelevant
    //     Linear:             OCBAR will continue to access the same location
    //     Linear Stream:      OCBAR will auto-increment

    // Initialize output length
    o_ocb_act_length = 0;

    // Based on the op, perform the data access
    if ( i_ocb_op == p9ocb::OCB_PUT )
    {
        FAPI_INF("OCB access for data write operation");
        FAPI_ASSERT(io_ocb_buffer.getLength<uint64_t>() != 0,
                    fapi2::PROCPM_OCB_PUT_NO_DATA_ERROR(),
                    "No data provided for PUT operation");

        fapi2::buffer<uint64_t> l_data64;
        FAPI_TRY(fapi2::getScom(i_target, l_OCBCSR_address, l_data64));

        // The following check for circular mode is an additional check
        // performed to ensure a valid data access.
        if (l_data64.getBit<4>() && l_data64.getBit<5>())
        {
            FAPI_DBG("Circular mode detected.");

            // Check if push queue is enabled. If not, let the store occur
            // anyway to let the PIB error response return occur. (that is
            // what will happen if this checking code were not here)
            FAPI_TRY(fapi2::getScom(i_target, l_OCBSHCS_address, l_data64));

            if (l_data64.getBit<31>())
            {
                FAPI_DBG("Poll for a non-full condition to a push queue to "
                         "avoid data corruption problem");

                bool l_push_ok_flag = false;
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

                    // Point to put in any needed delay.
                    fapi2::delay(OCB_FULL_POLL_DELAY_HDW,
                                 OCB_FULL_POLL_DELAY_SIM);

                    FAPI_TRY(fapi2::getScom(i_target,
                                            l_OCBSHCS_address,
                                            l_data64));
                    l_counter++;

                }
                while (l_counter < OCB_FULL_POLL_MAX);

                FAPI_ASSERT((true == l_push_ok_flag),
                            fapi2::PROCPM_OCB_PUT_DATA_POLL_NOT_FULL_ERROR().
                            set_PUSHQ_STATE(l_data64),
                            "Polling timeout waiting on push non-full");
            }
        }


        // Walk the input buffer (io_ocb_buffer) 8B (64bits) at a time to write
        // the channel data register
        for(uint32_t l_bufferPtr = 0;
            l_bufferPtr < (i_ocb_req_length * 64);
            l_bufferPtr += 64)
        {
            uint64_t l_buf64 = 0;

            io_ocb_buffer.extract<uint64_t>(l_buf64, l_bufferPtr, 64);
            l_data64.insertFromRight(l_buf64, 0, 64);
            FAPI_TRY(fapi2::putScom(i_target, l_OCBDR_address, l_data64));
            o_ocb_act_length++;

            FAPI_DBG("64 bits of input data:0x%08X from buffer location: 0x%X",
                     l_buf64, l_bufferPtr);
        }

        FAPI_DBG("Length of data put:0x%08X", o_ocb_act_length);
    }
    else if( i_ocb_op == p9ocb::OCB_GET )
    {
        FAPI_INF("OCB access for data read operation");
        FAPI_DBG("Get: Setting the io_ocb_buffer size to %x bytes",
                 i_ocb_req_length);

        io_ocb_buffer.resize(i_ocb_req_length * 8);

        for(uint32_t l_bufferPtr = 0;
            l_bufferPtr < (i_ocb_req_length * 8);
            l_bufferPtr += 64)
        {
            fapi2::buffer<uint64_t> l_data64;
            uint64_t l_data;

            FAPI_TRY(fapi2::getScom(i_target, l_OCBDR_address, l_data64));
            FAPI_DBG("64 bits of data retrieved:0x%X; to buffer location:0x%X",
                     l_data64, l_bufferPtr);
            l_data64.extract(l_data, 0, 64);
            io_ocb_buffer.insertFromRight(l_data, l_bufferPtr, 64);
            o_ocb_act_length++;
            FAPI_DBG("Increment output length to %d ", o_ocb_act_length);
        }
    }

    // If not non-zero SCOM rc, check that the lengths match.
    FAPI_ASSERT((i_ocb_req_length == o_ocb_act_length),
                fapi2::PROCPM_OCB_ACCESS_LENGTH_CHECK()
                .set_LENGTH(i_ocb_req_length)
                .set_ACTUALLENGTH(o_ocb_act_length),
                "OCB access length check failure: input = %8X; output = %8X",
                i_ocb_req_length, o_ocb_act_length);

    FAPI_IMP("Exit p9_pm_ocb_indir_access...");

fapi_try_exit:
    return fapi2::current_err;

}
