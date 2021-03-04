/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/ffdc/exp_collect_explorer_log.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
//------------------------------------------------------------------------------
/// @file  exp_collect_explorer_log.C
///
/// @brief Collects and adds Explorer logs to rc
//------------------------------------------------------------------------------
// *HWP HW Owner        : Matt Derksen
// *HWP HW Backup Owner :  <>
// *HWP FW Owner        :  <>
// *HWP Level           : 2
// *HWP Consumed by     : SE:HB
//------------------------------------------------------------------------------

#include <fapi2.H>
#include "exp_collect_explorer_log.H"
#include <exp_fw_log_data.H>

struct explog_section_header_t
{
    uint16_t packet_num;      // ordering byte (0 = first packet)
    uint32_t offset_exp_log;  // offset where data portion started in full explorer log
    uint16_t error_data_size; // size of data portion following header

    explog_section_header_t()
        : packet_num(0),
          offset_exp_log(0),
          error_data_size(0)
    {}
} __attribute__((__packed__));

// 1st entry is most relevant traces so make it a small size so
// it won't be truncated from HWP error log
const size_t FIRST_PACKET_SIZE     = 0x100;

// Use a larger packet size for the rest of the remaining error data
// These aren't as important since they are older trace logs
const size_t FOLLOWING_PACKET_SIZE = 0x200;

/**
 * @brief Explorer Log type?
 *
 * The firmware maintains the log in a circular buffer in RAM (ACTIVE_LOG) and
 * in the event of a processor exception, firmware assert, or other critical
 * condition the firmware saves the data in RAM to SPI flash (SAVED_LOG).
 * Having the log stored in non-volatile memory allows post-analysis
 * of the log even if it requires a power-cycle to recover the system.
 */
enum exp_log_type : uint8_t
{
    ACTIVE_LOG  = 1, // RAM error section
    SAVED_LOG_A = 2, // SPI flash error section from image A
    SAVED_LOG_B = 3  // SPI flash error section from image B
};

/**
 * @brief  Main procedure to grab log traces from Explorer chip
 *         and append the trace data to HWP error (o_rc)
 *
 * @param[in] i_ocmb_chip - OCMB chip target
 * @param[in] i_size - allowable total size (add entries upto this size)
 * @param[in] i_log_type - what kind of explorer log to grab
 * @param[out] o_rc - return code to add FFDC data to.
 *
 * @return FAPI2_RC_SUCCESS iff ok
 */
fapi2::ReturnCode exp_collect_explorer_logs(const fapi2::ffdc_t& i_ocmb_chip,
        const fapi2::ffdc_t& i_size,
        const exp_log_type i_log_type,
        fapi2::ReturnCode& o_rc)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // This variable is reused multiple times to build up a unique section
    // identifier to split the log data read from the OCMB before we add
    // each section to the HWP error
    explog_section_header_t l_header_meta;

    // target from which to grab the error log data
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_target_ocmb =
        *(reinterpret_cast<const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> *>
          (i_ocmb_chip.ptr()));

    // How much explorer log data are we allowed to add to the HWP error?
    uint32_t l_allowable_size = *(reinterpret_cast<const uint32_t*>(i_size.ptr()));

    // Just don't grab log if size is zero
    if (l_allowable_size == 0)
    {
        FAPI_INF("exp_collect_explorer_logs(%d) called with 0 size", i_log_type);
        return l_rc;
    }

    // verify not trying to grab more than allowed per explorer log
    if (l_allowable_size > mss::exp::ib::MAX_BYTES_PER_LOG)
    {
        // avoid assert within assert here, so just log this information
        FAPI_INF("exp_collect_explorer_logs: passed size 0x%.8X, max size allowed: 0x%.8X",
                 l_allowable_size, mss::exp::ib::MAX_BYTES_PER_LOG);

        // set to maximum allowed
        l_allowable_size =  mss::exp::ib::MAX_BYTES_PER_LOG;
    }

    std::vector<uint8_t>l_explorer_log_data; // full Explorer log data
    l_explorer_log_data.resize(l_allowable_size);
    fapi2::ffdc_t UNIT_FFDC_EXP_ERROR; // filled in for RC_EXPLORER_ERROR_LOG

    switch (i_log_type)
    {
        case ACTIVE_LOG:
            FAPI_INF( "exp_collect_explorer_logs: Entering ... "
                      "Grab ACTIVE_LOG with max data size: 0x%04X", l_allowable_size );
            FAPI_EXEC_HWP(l_rc, exp_active_log, l_target_ocmb,
                          l_explorer_log_data);
            break;

        case SAVED_LOG_A:
            FAPI_INF( "exp_collect_explorer_logs: Entering ... "
                      "Grab SAVED_LOG_A with max data size: 0x%04X", l_allowable_size );
            FAPI_EXEC_HWP(l_rc, exp_saved_log, mss::exp::ib::EXP_IMAGE_A, 0, l_target_ocmb,
                          l_explorer_log_data);
            break;

        case SAVED_LOG_B:
            FAPI_INF( "exp_collect_explorer_logs: Entering ... "
                      "Grab SAVED_LOG_B with max data size: 0x%04X", l_allowable_size );
            FAPI_EXEC_HWP(l_rc, exp_saved_log, mss::exp::ib::EXP_IMAGE_B, 0, l_target_ocmb,
                          l_explorer_log_data);
            break;
    }

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_ERR("exp_collect_explorer_logs: error 0x%04X from exp_%s_log",
                 (uint32_t)l_rc, i_log_type == ACTIVE_LOG ? "active" : "saved");
    }
    else
    {
        // Variable to store how much Explorer data we have remaining
        uint32_t l_explorer_bytes_left = l_explorer_log_data.size();

        // Add this much explorer log data (as maximum amount, could be less)
        l_header_meta.error_data_size = FIRST_PACKET_SIZE;

        // pointer to start of explorer data
        const uint8_t* l_start_data_ptr = l_explorer_log_data.data();

        uint32_t l_current_idx = 0;

        if (i_log_type == ACTIVE_LOG)
        {
            // Skip to the last entry in ACTIVE log
            // skip 0x00's at the end of the ACTIVE log
            // leave at least 1 byte of data so we know log was all 0x00's
            while ( (l_explorer_bytes_left > 1) &&
                    (l_start_data_ptr[l_explorer_bytes_left - 1] == 0x00) )
            {
                l_explorer_bytes_left--;
            }

            // most recent traces at end of data in ACTIVE log
            l_current_idx = l_explorer_bytes_left;
        }


        // This is where we start iterating through the Explorer log data
        // and break it into sections that are added to the HWP error
        // ACTIVE log data has most recent traces at the end
        // SAVED log data has the most recent traces at the beginning
        while ( l_explorer_bytes_left )
        {
            // ----------------------------------------------------------------
            // Calculate how much explorer data to add for this section entry
            // ----------------------------------------------------------------
            // Verify there is enough space left in the allowable HWP error
            // so we can add another full data section
            if ( l_explorer_bytes_left < l_header_meta.error_data_size)
            {
                FAPI_DBG("exp_collect_explorer_logs: %d) reduce packet size to include the last explorer log bytes"
                         "(l_explorer_bytes_left %d, Initial packet size %d)", l_header_meta.packet_num,
                         l_explorer_bytes_left, l_header_meta.error_data_size);

                // reduce the packet size to include the last explorer log bytes
                l_header_meta.error_data_size = l_explorer_bytes_left;
            }

            // Setup offset where the data is starting from out of the whole Explorer log data
            if (i_log_type == ACTIVE_LOG)
            {
                // check that offset won't wrap to huge number
                if (l_header_meta.error_data_size > l_current_idx)
                {
                    // avoid assert within assert here, so just log this information
                    FAPI_INF("exp_collect_explorer_logs: %d) ACTIVE log index %d is less than %d data size",
                             l_header_meta.packet_num, l_current_idx, l_header_meta.error_data_size);

                    // start at offset 0 and grab until l_current_idx
                    l_header_meta.error_data_size = l_current_idx;
                }

                l_header_meta.offset_exp_log = l_current_idx - l_header_meta.error_data_size;
            }
            else
            {
                l_header_meta.offset_exp_log = l_current_idx;

                // Save Errorlog space by starting SAVED logs where there is real data
                // Skip NULLs at beginning of SAVED logs
                // but leave at least one data packet
                if ( (l_header_meta.packet_num == 0) &&
                     (l_explorer_bytes_left != l_header_meta.error_data_size))
                {
                    // index into saved log packet
                    uint32_t l_pkt_idx = 0;

                    // check if first packet is all NULLs
                    while ((l_pkt_idx < l_header_meta.error_data_size)
                           && (l_start_data_ptr[l_current_idx + l_pkt_idx] == 0x00))
                    {
                        l_pkt_idx++;
                    }

                    if (l_pkt_idx == l_header_meta.error_data_size)
                    {
                        FAPI_DBG("exp_collect_explorer_logs: "
                                 "NULL packet at offset 0x%08X (data size: %d)",
                                 l_header_meta.offset_exp_log,
                                 l_header_meta.error_data_size);

                        l_explorer_bytes_left -= l_header_meta.error_data_size;
                        l_current_idx += l_header_meta.error_data_size;
                        continue;
                    }
                }
            }

            FAPI_DBG("exp_collect_explorer_logs: %d) starting offset 0x%08X "
                     "(data size: %d)", l_header_meta.packet_num,
                     l_header_meta.offset_exp_log, l_header_meta.error_data_size);

            // Adding header with meta data
            auto const ptr = reinterpret_cast<uint8_t*>(&l_header_meta);
            std::vector<uint8_t>l_error_log_entry ( ptr, ptr + sizeof(l_header_meta));

            // Now append the explorer error section to the section entry
            l_error_log_entry.insert( l_error_log_entry.end(),
                                      l_start_data_ptr + l_header_meta.offset_exp_log,
                                      l_start_data_ptr + l_header_meta.offset_exp_log + l_header_meta.error_data_size);

            // Add the section entry to the HWP error log
            UNIT_FFDC_EXP_ERROR.ptr() = l_error_log_entry.data();
            UNIT_FFDC_EXP_ERROR.size() = l_error_log_entry.size();

            switch (i_log_type)
            {
                case ACTIVE_LOG:
                    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_EXPLORER_ACTIVE_ERROR_LOG);
                    break;

                case SAVED_LOG_A:
                    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_EXPLORER_SAVED_IMAGEA_ERROR_LOG);
                    break;

                case SAVED_LOG_B:
                    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_EXPLORER_SAVED_IMAGEB_ERROR_LOG);
                    break;
            }

            // Update to next packet of Explorer error log data
            l_header_meta.packet_num++;
            l_explorer_bytes_left -= l_header_meta.error_data_size;

            if (i_log_type == ACTIVE_LOG)
            {
                // point to end of data
                l_current_idx -= l_header_meta.error_data_size;
            }
            else
            {
                // point to start of data
                l_current_idx += l_header_meta.error_data_size;
            }

            l_header_meta.error_data_size = FOLLOWING_PACKET_SIZE;
        }
    }

    FAPI_INF("exp_collect_explorer_logs: Exiting ...");

    return l_rc;
}

/// See header
fapi2::ReturnCode exp_collect_explorer_active_log(
    const fapi2::ffdc_t& i_ocmb_chip,
    const fapi2::ffdc_t& i_size,
    fapi2::ReturnCode& o_rc )
{
    return exp_collect_explorer_logs(i_ocmb_chip, i_size, ACTIVE_LOG, o_rc);
}

/// See header
fapi2::ReturnCode exp_collect_explorer_saved_A_log(
    const fapi2::ffdc_t& i_ocmb_chip,
    const fapi2::ffdc_t& i_size,
    fapi2::ReturnCode& o_rc )
{
    return exp_collect_explorer_logs(i_ocmb_chip, i_size, SAVED_LOG_A, o_rc);
}

fapi2::ReturnCode exp_collect_explorer_saved_B_log(
    const fapi2::ffdc_t& i_ocmb_chip,
    const fapi2::ffdc_t& i_size,
    fapi2::ReturnCode& o_rc )
{
    return exp_collect_explorer_logs(i_ocmb_chip, i_size, SAVED_LOG_B, o_rc);
}
