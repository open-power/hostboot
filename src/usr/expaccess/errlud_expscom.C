/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/errlud_expscom.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/**
 *  @file errlud_expscom.C
 *  @brief Utility to add Explorer logs to your hostboot error
 */
#include "errlud_expscom.H"
#include "expscom_trace.H"
#include <errl/hberrltypes.H> // pelSectionHeader_t
#include <exp_fw_log_data.H>  // explorer log gathering tools
#include <exp_fw_log.H>       // explorer log variables
#include <exp_fw_adapter_properties.H> // explorer properties cmd
#include <fapi2/plat_hwp_invoker.H> // FAPI_INVOKE_HWP
#include <expscom/expscom_errlog.H> // functions to implement
#include <expscom/expscom_reasoncodes.H> // user-detail subsections
#include <errl/errlmanager.H> // errlCommit

using namespace EXPSCOM;

// Enable trace for debugging
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

/**
 * @brief   Helper function
 *          Determines if data is all same value
 * @param[in] i_val - value to check
 * @param[in] i_data - pointer to data
 * @param[in] i_dataSize - data size in bytes to check
 * @return true if data is all same, else false
 */
bool isDataSame(const uint8_t i_val, const uint8_t * i_data, const size_t i_dataSize)
{
    bool l_dataSame = true;
    for (size_t i = 0; i < i_dataSize; ++i)
    {
        if(i_data[i] != i_val)
        {
            l_dataSame = false;
            break;
        }
    }
    return l_dataSame;
}

/**
 * @brief Helper function
 *        Calls appropriate hwp to grab Explorer log data
 * @param[in/out] io_log_type - type of explorer log
 *                             (updates current/noncurrent saved log type to its appropriate A or B image)
 * @param[in]     i_ocmb - ocmb with log data
 * @param[in]     i_startOffset - offset to start grabbing data (used for Saved logs)
 * @param[in]     i_log_size - size of log to grab (used for Saved logs)
 * @param[out]    o_error_log_data - populated with explorer log data
 * @return errlHandl_t nullptr on success, else error log
 */
errlHndl_t grab_explorer_log_data( exp_log_type & io_log_type,
                                   TARGETING::Target * i_ocmb,
                                   const uint32_t i_startOffset,
                                   const uint32_t i_log_size,
                                   std::vector<uint8_t> & o_error_log_data )
{
    errlHndl_t l_errl = nullptr;
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target(i_ocmb);

    // create a buffer for data of size expected
    o_error_log_data.resize(i_log_size, 0);

    // vector for current/non-current saved log
    std::vector<uint8_t>l_error_log_dataB;

    // Make HWP call to grab explorer error log data
    switch (io_log_type)
    {
        case ACTIVE_LOG:
          // active log does not use offset or log size
          TRACFCOMP( g_trac_expscom, INFO_MRK "FAPI_INVOKE_HWP "
                        "exp_active_error_log");
          FAPI_INVOKE_HWP( l_errl, exp_active_log,
                         l_fapi_ocmb_target, o_error_log_data );
          break;

        case SAVED_LOG_A:
          TRACFCOMP( g_trac_expscom, INFO_MRK "FAPI_INVOKE_HWP "
              "exp_saved_log SAVED_LOG_A OCMB 0x%.8X with starting offset 0x%.08X and max data size: 0x%08X",
              get_huid(i_ocmb), i_startOffset, i_log_size );
          FAPI_INVOKE_HWP(l_errl, exp_saved_log, mss::exp::ib::EXP_IMAGE_A,
              i_startOffset, l_fapi_ocmb_target, o_error_log_data);
          break;

        case SAVED_LOG_B:
          TRACFCOMP( g_trac_expscom, INFO_MRK "FAPI_INVOKE_HWP "
              "exp_saved_log SAVED_LOG_B OCMB 0x%.8X with starting offset 0x%.08X and max data size: 0x%08X",
              get_huid(i_ocmb), i_startOffset, i_log_size );
          FAPI_INVOKE_HWP(l_errl, exp_saved_log, mss::exp::ib::EXP_IMAGE_B,
              i_startOffset, l_fapi_ocmb_target, o_error_log_data);
          break;

        case CURRENT_SAVED_LOG:
        case NONCURRENT_SAVED_LOG:
          // Grab both SAVED logs first, then decide which one is current
          // This is done so extra traces won't occur in the saved logs for
          // the fw_adapter_properties_get command
          TRACFCOMP( g_trac_expscom, INFO_MRK "FAPI_INVOKE_HWP "
              "exp_saved_log SAVED_LOG_A OCMB 0x%.8X with starting offset 0x%.08X and max data size: 0x%08X",
              get_huid(i_ocmb), i_startOffset, i_log_size );;
          FAPI_INVOKE_HWP(l_errl, exp_saved_log, mss::exp::ib::EXP_IMAGE_A,
              i_startOffset, l_fapi_ocmb_target, o_error_log_data);
          if (l_errl)
          {
              break;
          }
          l_error_log_dataB.resize(i_log_size, 0);
          TRACFCOMP( g_trac_expscom, INFO_MRK "FAPI_INVOKE_HWP "
              "exp_saved_log SAVED_LOG_B OCMB 0x%.8X with starting offset 0x%.08X and max data size: 0x%08X",
              get_huid(i_ocmb), i_startOffset, i_log_size );
          FAPI_INVOKE_HWP(l_errl, exp_saved_log, mss::exp::ib::EXP_IMAGE_B,
              i_startOffset, l_fapi_ocmb_target, l_error_log_dataB);
          break;
    }

    // determine which saved log to dump based on current image
    if ( ((io_log_type == CURRENT_SAVED_LOG) ||
          (io_log_type == NONCURRENT_SAVED_LOG)) && (!l_errl) )
    {
        TRACUCOMP( g_trac_expscom, INFO_MRK "Grab current side of explorer for saved log");
        FAPI_INVOKE_HWP(l_errl, mss::exp::ib::run_fw_adapter_properties_get, l_fapi_ocmb_target);
        if (!l_errl)
        {
            auto currentExpPartition =
                i_ocmb->getAttr<TARGETING::ATTR_MSS_EXP_FW_PARTITION_ID>();

            if (currentExpPartition == TARGETING::MSS_EXP_FW_PARTITION_ID_A)
            {
                // MSS_EXP_FW_PARTITION_ID_A is current image
                if (io_log_type == CURRENT_SAVED_LOG)
                {
                    TRACFCOMP(g_trac_expscom, INFO_MRK "Current side = A");
                    io_log_type = SAVED_LOG_A;
                }
                else
                {
                    // NONCURRENT = B
                    TRACFCOMP(g_trac_expscom, INFO_MRK "Non-current side = B");
                    io_log_type = SAVED_LOG_B;
                    o_error_log_data = l_error_log_dataB;
                }
            }
            else
            {
                // MSS_EXP_FW_PARTITION_ID_B is current image
                if (io_log_type == CURRENT_SAVED_LOG)
                {
                    TRACFCOMP(g_trac_expscom, INFO_MRK "Current side = B");
                    o_error_log_data = l_error_log_dataB;
                    io_log_type = SAVED_LOG_B;
                }
                else
                {
                    // NONCURRENT = A
                    TRACFCOMP(g_trac_expscom, INFO_MRK "Non-current side = A");
                    io_log_type = SAVED_LOG_A;
                }
            }
        }
    }

    return l_errl;
}

/**
 * @brief Helper function
 *        Processes active log data into hostboot error log sections
 *        Most recent trace logs are at the end of i_explog_data
 * @param[in]       i_explog_data - active explorer log data
 * @param[in/out]   io_bytesAvailableInErrorLog - how many bytes can be added to hostboot error log
 * @param[in/out]   io_errl - hostboot error log (active user data sections added to this)
 * @param[in/out]   io_last_packet - last user data packet number added (starts at 0)
 * @return bool - true if sections added, else false
 */
bool addActiveLogSections( std::vector<uint8_t> & i_explog_data,
                           uint32_t & io_bytesAvailableInErrorLog,
                           errlHndl_t & io_errl,
                           uint16_t & io_last_packet )
{
    bool l_logsAdded = false;
    explog_section_header_t l_header; // use 0 defaults
    l_header.packet_num = io_last_packet;

    // Meta data included with each section
    const uint32_t META_SECTION_SIZE = sizeof(l_header) +
                                       sizeof(ERRORLOG::pelSectionHeader_t);

    // cycle through data and add sections to io_errl
    // start with a smaller section size then use a larger one for rest
    l_header.error_data_size = FIRST_EXPLORER_DATA_SECTION_SIZE;

    uint32_t l_explorer_bytes_left = i_explog_data.size();
    const uint8_t * l_start_data_ptr = i_explog_data.data();
    if (io_last_packet > 0)
    {
        l_header.error_data_size = FOLLOWING_EXPLORER_DATA_SECTION_SIZE;
    }

    // index into i_explog_data, point to end of the next packet section of data
    uint32_t l_current_idx = l_explorer_bytes_left;

    // Remove filler bytes from logs after the useful data ends
    // skip 0x00's at the end of the ACTIVE log
    while ( (l_explorer_bytes_left > 1) &&
            (l_start_data_ptr[l_explorer_bytes_left-1] == 0x00) )
    {
        l_explorer_bytes_left--;
    }

    // most recent traces at end of data in ACTIVE log
    l_current_idx = l_explorer_bytes_left;

    TRACUCOMP( g_trac_expscom, "addActiveLogSections: starting index 0x%08X", l_current_idx );

    // while explorer data to append and room in error log
    while (l_explorer_bytes_left && io_bytesAvailableInErrorLog)
    {
        ////////////////////////////////////////////////////////////////
        // Figure out how much data to add for this next section
        // Fill in l_header.error_data_size with that value
        ////////////////////////////////////////////////////////////////

        TRACUCOMP( g_trac_expscom,
            "addActiveLogSections: l_bytesAvailableInLog: 0x%08X, META_SECTION_SIZE: 0x%08X",
            io_bytesAvailableInErrorLog, META_SECTION_SIZE );
        TRACUCOMP( g_trac_expscom, "addActiveLogSections: l_explorer_bytes_left: 0x%08X",
            l_explorer_bytes_left );
        TRACUCOMP( g_trac_expscom,
            "addActiveLogSections: BEFORE l_header.error_data_size: 0x%08X",
            l_header.error_data_size );


        // Can we add a full packet size of error data?
        if (io_bytesAvailableInErrorLog >= (l_header.error_data_size + META_SECTION_SIZE))
        {
            // Check if we don't have full packet of explorer log data
            if (l_explorer_bytes_left < l_header.error_data_size)
            {
                // Reduce the packet size to include the last of explorer log data
                l_header.error_data_size = l_explorer_bytes_left;
            }
        }
        else if ( io_bytesAvailableInErrorLog > META_SECTION_SIZE )  // Any room left for another section?
        {
            // Is there enough explorer error data for room available?
            if ( l_explorer_bytes_left >=
                 (io_bytesAvailableInErrorLog - META_SECTION_SIZE) )
            {
                // Not enough room is available for all the remaining explorer log data
                // Use up the rest of the space available
                l_header.error_data_size = io_bytesAvailableInErrorLog - META_SECTION_SIZE;
            }
            else
            {
                // Room is available but not enough explorer data for full packet size

                // Reduce the packet size to include the last of explorer log data
                l_header.error_data_size = l_explorer_bytes_left;
            }
        }
        else
        {
            // No more space available in hostboot error log
            TRACFCOMP(g_trac_expscom, "addActiveLogSections: "
                "no more space left in hostboot error log (0x%X bytes left)",
                io_bytesAvailableInErrorLog);
            break;
        }

        TRACUCOMP( g_trac_expscom, "addActiveLogSections: "
            "AFTER l_header.error_data_size: 0x%08X",
            l_header.error_data_size );
        if (l_header.error_data_size == 0)
        {
            TRACFCOMP(g_trac_expscom,"addActiveLogSections: Exitting as no more data to add.  Current index: 0x%08X, error log bytes left: 0x%08X",
                l_current_idx, io_bytesAvailableInErrorLog);
            break;
        }

        // Offset into explorer error log data returned
        TRACUCOMP( g_trac_expscom, "addActiveLogSections: offset_exp_log = 0x%08X - 0x%08X",
            l_current_idx,  l_header.error_data_size);
        if (l_header.error_data_size > l_current_idx)
        {
            l_header.error_data_size = l_current_idx;
        }
        // working way from back of the log
        l_header.offset_exp_log = l_current_idx - l_header.error_data_size;

        // Add the section entry to the HWP error log
        ExpscomActiveLogUD(l_header, l_start_data_ptr+l_header.offset_exp_log)
                  .addToLog(io_errl);
        l_logsAdded = true;

        // Update to next packet of Explorer error log data
        // point to end of data
        l_current_idx -= l_header.error_data_size;
        TRACUCOMP( g_trac_expscom, "addActiveLogSections: next index 0x%08X", l_current_idx );

        l_header.packet_num++;
        l_explorer_bytes_left -= l_header.error_data_size;
        if (io_bytesAvailableInErrorLog >= (META_SECTION_SIZE + l_header.error_data_size))
        {
            // remove added section from total bytes available in error log
            io_bytesAvailableInErrorLog -=
                        (META_SECTION_SIZE + l_header.error_data_size);
        }
        else
        {
            TRACUCOMP(g_trac_expscom, "addActiveLogSections: Last data added was "
              "over max size (0x%08X + META_SECTION_SIZE 0x%08X > 0x%08X)",
              l_header.error_data_size, META_SECTION_SIZE,
              io_bytesAvailableInErrorLog);
            break;
        }
        l_header.error_data_size = FOLLOWING_EXPLORER_DATA_SECTION_SIZE;
    }
    io_last_packet = l_header.packet_num;

    return l_logsAdded;
}

/**
 * @brief Helper function
 *        Processes explorer saved log data into hostboot error log sections
 *        Most recent trace logs are at the beginning of i_explog_data
 *
 * @param[in]       i_log_type - what type of saved log (SAVED_LOG_A or SAVED_LOG_B)
 * @param[in]       i_explog_data - saved explorer log data
 * @param[in/out]   io_bytesAvailableInErrorLog - how many bytes can be added to hostboot error log
 * @param[in]       i_expLog_offset - offset into explorer log where i_explog_data started
 * @param[in/out]   io_errl - hostboot error log (active user data sections added to this)
 * @param[in/out]   io_last_packet - last user data packet number added (starts at 0)
 * @return bool - true if sections added, else false
 */
bool addSavedLogSections( const exp_log_type i_log_type,
                          std::vector<uint8_t> & i_explog_data,
                          uint32_t & io_bytesAvailableInErrorLog,
                          uint32_t i_expLog_offset,
                          errlHndl_t & io_errl,
                          uint16_t & io_last_packet )
{
    bool l_logsAdded = false;
    explog_section_header_t l_header; // use 0 defaults
    l_header.packet_num = io_last_packet;

    // Meta data included with each section
    const uint32_t META_SECTION_SIZE = sizeof(l_header) +
                                       sizeof(ERRORLOG::pelSectionHeader_t);

    // cycle through data and add sections to io_errl
    // start with a smaller section size then use a larger one for rest
    l_header.error_data_size = FIRST_EXPLORER_DATA_SECTION_SIZE;
    if (io_last_packet > 0)
    {
        l_header.error_data_size = FOLLOWING_EXPLORER_DATA_SECTION_SIZE;
    }

    uint32_t l_explorer_bytes_left = i_explog_data.size();
    const uint8_t * l_start_data_ptr = i_explog_data.data();
    uint32_t l_current_idx = 0;

    // skip 0xFF's at the start of SAVED logs
    // leave one 0xFF if entire data is all 0xFFs
    while ( (l_current_idx < (l_explorer_bytes_left-1)) &&
            (l_start_data_ptr[l_current_idx] == 0xFF) )
    {
        l_current_idx++;
    }
    // SAVED log data left after starting from current index
    l_explorer_bytes_left -= l_current_idx;

    TRACUCOMP( g_trac_expscom, "addSavedLogSections: starting index 0x%08X", l_current_idx );

    // while explorer data to append and room in error log
    while (l_explorer_bytes_left && io_bytesAvailableInErrorLog)
    {
        ////////////////////////////////////////////////////////////////
        // Figure out how much data to add for this next section
        // Fill in l_header.error_data_size with that value
        ////////////////////////////////////////////////////////////////

        TRACUCOMP( g_trac_expscom, "addSavedLogSections: io_bytesAvailableInErrorLog: 0x%08X, META_SECTION_SIZE: 0x%08X",
              io_bytesAvailableInErrorLog, META_SECTION_SIZE );
        TRACUCOMP( g_trac_expscom, "addSavedLogSections: l_explorer_bytes_left: 0x%08X, current idx: 0x%08X",
              l_explorer_bytes_left, l_current_idx );

        TRACUCOMP( g_trac_expscom, "addSavedLogSections: BEFORE l_header.error_data_size: 0x%08X", l_header.error_data_size );

        // Can we add a full packet size of error data?
        if (io_bytesAvailableInErrorLog >= (l_header.error_data_size + META_SECTION_SIZE))
        {
            // Check if we don't have full packet of explorer error data
            if (l_explorer_bytes_left < l_header.error_data_size)
            {
                // Reduce the packet size to include the last of explorer error data
                l_header.error_data_size = l_explorer_bytes_left;
            }
        }
        else if ( io_bytesAvailableInErrorLog > META_SECTION_SIZE )  // Any room left for another section?
        {
            // Is there enough explorer error data for room available?
            if ( l_explorer_bytes_left >=
                 (io_bytesAvailableInErrorLog - META_SECTION_SIZE) )
            {
                // Not enough room is available for all the remaining explorer error data
                // Use up the rest of the space available
                l_header.error_data_size = io_bytesAvailableInErrorLog - META_SECTION_SIZE;
            }
            else
            {
                // Room is available but not enough explorer data for full packet size

                // Reduce the packet size to include the last of explorer error data
                l_header.error_data_size = l_explorer_bytes_left;
            }
        }
        else
        {
            // No more space available in hostboot error log
            TRACFCOMP(g_trac_expscom, "addSavedLogSections: "
                "no more space left in hostboot error log (0x%X bytes left)",
                io_bytesAvailableInErrorLog);
            break;
        }

        TRACUCOMP( g_trac_expscom,
            "addSavedLogSections: AFTER l_header.error_data_size: 0x%08X",
            l_header.error_data_size );

        if (l_header.error_data_size == 0)
        {
            break;
        }

        // Offset into explorer error log data returned
        l_header.offset_exp_log = l_current_idx + i_expLog_offset;

        // If this is NOT the first log section
        // Allow 0xFF for first section to denote empty log
        if (l_logsAdded)
        {
            // skip all 0xFF sections after first one
            if ( isDataSame(0xFF,
                           l_start_data_ptr+l_current_idx,
                           l_header.error_data_size) )
            {
                // Update to next packet of Explorer error log data
                // all zeroes for this first packet of data
                l_explorer_bytes_left -= l_header.error_data_size;

                // point to start of data
                l_current_idx += l_header.error_data_size;
                TRACUCOMP( g_trac_expscom,
                  "addSavedLogSections: Skipping 0x%.8X bytes of 0xFF data at exp log offset 0x%.8X, next index 0x%08X",
                  l_header.error_data_size, l_header.offset_exp_log,
                  l_current_idx );
                continue;
            }
        }

        // Add the section entry to the HWP error log
        if (i_log_type == SAVED_LOG_A)
        {
            ExpscomSavedLogUD(SAVED_IMAGE_A, l_header,
                  l_start_data_ptr+l_current_idx).addToLog(io_errl);
        }
        else
        {
            ExpscomSavedLogUD(SAVED_IMAGE_B, l_header,
                  l_start_data_ptr+l_current_idx).addToLog(io_errl);
        }
        l_logsAdded = true;

        // Update to next packet of Explorer error log data
        l_current_idx += l_header.error_data_size;
        TRACUCOMP( g_trac_expscom, "addSavedLogSections: next index 0x%08X", l_current_idx );

        l_header.packet_num++;
        l_explorer_bytes_left -= l_header.error_data_size;
        if (io_bytesAvailableInErrorLog >= (META_SECTION_SIZE + l_header.error_data_size))
        {
            // remove added section from total bytes available in error log
            io_bytesAvailableInErrorLog -=
                        (META_SECTION_SIZE + l_header.error_data_size);
        }
        else
        {
            TRACUCOMP(g_trac_expscom, "addSavedLogSections: Last data added was "
              "over max size (0x%08X + META_SECTION_SIZE 0x%08X > 0x%08X)",
              l_header.error_data_size, META_SECTION_SIZE, io_bytesAvailableInErrorLog);
            break;
        }
        l_header.error_data_size = FOLLOWING_EXPLORER_DATA_SECTION_SIZE;
    }
    io_last_packet = l_header.packet_num;

    return l_logsAdded;
}



// Main function to add Explorer logs to a HB error log
bool EXPSCOM::expAddLog( const exp_log_type i_log_type,
                         TARGETING::Target * i_ocmb,
                         uint32_t i_max_log_size,
                         errlHndl_t & io_errl )
{

    bool l_logsAdded = false;

    // Allow log type to change to a definitive saved log image A or B
    exp_log_type l_log_type = i_log_type;

    // Meta data included with each section
    const uint32_t META_SECTION_SIZE = sizeof(explog_section_header_t) +
                                       sizeof(ERRORLOG::pelSectionHeader_t);

    // @todo RTC 214628
    // Hopefully create a way to tell how much room is left in io_errl
    uint32_t l_bytesAvailableInLog = (4 * KILOBYTE) * 5;
    uint32_t l_exp_bytes_left_to_grab = i_max_log_size;
    uint32_t l_overall_explog_offset = 0;

    // Can only grab this much data at a time
    // Note: grab the full chunk size and then figure out how much is really
    // necessary to add into the hostboot error log after filtering out padding
    uint32_t l_chunk_size = 64 * KILOBYTE;
    if (l_log_type == ACTIVE_LOG)
    {
        l_chunk_size = FULL_ACTIVE_EXPLOG;
    }
    else
    {
        // l_log_type is some SAVED log type
        if (l_exp_bytes_left_to_grab > FULL_SAVED_EXPLOG)
        {
            l_exp_bytes_left_to_grab = FULL_SAVED_EXPLOG;
        }
    }

    // keep track of which chunk of data grabbed from overall explorer log
    uint32_t l_current_chunk = 1;

    // keep track of how many user-data explorer log sections have been added
    uint16_t l_packet_sections_added = 0;

    // While room in error log and still have explorer log bytes left to grab
    while ( (l_bytesAvailableInLog > META_SECTION_SIZE) &&
            l_exp_bytes_left_to_grab )
    {
        errlHndl_t l_errl = nullptr;
        std::vector<uint8_t>l_error_log_data; // explorer error entry data

        // Only grab up to as much explorer data that remains
        if (l_chunk_size > l_exp_bytes_left_to_grab)
        {
            l_chunk_size = l_exp_bytes_left_to_grab;
        }


        l_errl = grab_explorer_log_data( l_log_type,
                                         i_ocmb,
                                         l_overall_explog_offset,
                                         l_chunk_size,
                                         l_error_log_data );

        if (l_errl)
        {
            // Unable to grab explorer error log data
            TRACFCOMP( g_trac_expscom,
                ERR_MRK "expAddLog: %d) Unable to grab 0x%.8X bytes of explorer error log data at offset 0x%.08X",
                l_current_chunk, l_chunk_size, l_overall_explog_offset );
            l_errl->collectTrace(EXPSCOM_COMP_NAME);

            // This error is not a system critical failure, should be just noted
            l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);

            // Associate this error with the original explorer failure log
            l_errl->plid(io_errl->plid());
            errlCommit(l_errl, EXPSCOM_COMP_ID);

            break;
        }
        else
        {
            TRACUCOMP(g_trac_expscom,
                "expAddLog: %d) Grabbed 0x%.8X bytes of explorer data at offset 0x%.08X",
                l_current_chunk, l_error_log_data.size(),
                l_overall_explog_offset);

            if (l_log_type == ACTIVE_LOG)
            {
                l_logsAdded |= addActiveLogSections( l_error_log_data,
                                                     l_bytesAvailableInLog,
                                                     io_errl,
                                                     l_packet_sections_added );
            }
            else
            {
                l_logsAdded |= addSavedLogSections( l_log_type,
                                                    l_error_log_data,
                                                    l_bytesAvailableInLog,
                                                    l_overall_explog_offset,
                                                    io_errl,
                                                    l_packet_sections_added );
                // update full explorer log offset to start of next chunk of data
                l_overall_explog_offset += l_chunk_size;
            }

            // Chunk size will always be less than or equal to bytes left
            // so this subtraction will not underflow
            l_exp_bytes_left_to_grab -= l_chunk_size;

        }
        l_current_chunk++;
    }

    return l_logsAdded;
}

//------------------------------------------------------------------------------
//  Expscom Active Log User Details
//------------------------------------------------------------------------------
ExpscomActiveLogUD::ExpscomActiveLogUD(
                                const explog_section_header_t & i_header_info,
                                const uint8_t * i_data_portion )
{
    // Set up Ud instance variables
    iv_CompId = EXPSCOM_COMP_ID;
    iv_Version = 1;
    iv_SubSection = EXPSCOM_UDT_ACTIVE_LOG;

    uint8_t * l_pBuf = reallocUsrBuf( sizeof(i_header_info) +
                                      i_header_info.error_data_size );

    memcpy(l_pBuf, &i_header_info, sizeof(i_header_info));
    l_pBuf += sizeof(i_header_info);
    memcpy(l_pBuf, i_data_portion, i_header_info.error_data_size);
    l_pBuf += i_header_info.error_data_size;
}

ExpscomActiveLogUD::~ExpscomActiveLogUD()
{
}

//------------------------------------------------------------------------------
//  Expscom Saved Log User Details
//------------------------------------------------------------------------------
ExpscomSavedLogUD::ExpscomSavedLogUD(
                                const saved_exp_image i_image,
                                const explog_section_header_t & i_header_info,
                                const uint8_t * i_data_portion )
{
    // Set up Ud instance variables
    iv_CompId = EXPSCOM_COMP_ID;
    iv_Version = 1;
    iv_SubSection = EXPSCOM_UDT_SAVED_LOG_A;
    if (i_image == SAVED_IMAGE_B)
    {
        iv_SubSection = EXPSCOM_UDT_SAVED_LOG_B;
    }

    uint8_t * l_pBuf = reallocUsrBuf( sizeof(i_header_info) +
                                      i_header_info.error_data_size );

    memcpy(l_pBuf, &i_header_info, sizeof(i_header_info));
    l_pBuf += sizeof(i_header_info);
    memcpy(l_pBuf, i_data_portion, i_header_info.error_data_size);
    l_pBuf += i_header_info.error_data_size;
}

ExpscomSavedLogUD::~ExpscomSavedLogUD()
{
}
