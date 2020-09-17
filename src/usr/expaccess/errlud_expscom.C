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
#include <expscom/expscom_errlog.H> // expAddLog interface
#include <errl/hberrltypes.H> // pelSectionHeader_t
#include <exp_fw_log_data.H>  // explorer log gathering tools
#include <exp_fw_log.H>       // explorer log variables
#include <exp_fw_adapter_properties.H> // explorer properties cmd
#include <fapi2/plat_hwp_invoker.H> // FAPI_INVOKE_HWP
#include <expscom/expscom_reasoncodes.H> // user-detail subsections
#include <errl/errlmanager.H> // errlCommit

using namespace EXPSCOM;

// Enable trace for debugging
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

/**
 * @brief Determines if data is all same value
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

// Main function to add Explorer logs to a HB error log
bool EXPSCOM::expAddLog( const exp_log_type i_log_type,
                         TARGETING::Target * i_ocmb,
                         errlHndl_t & io_errl )
{
    bool l_logsAdded = false;
    explog_section_header_t l_header; // use 0 defaults
    exp_log_type l_log_type = i_log_type;

    // Meta data included with each section
    const uint32_t META_SECTION_SIZE = sizeof(l_header) +
                                       sizeof(ERRORLOG::pelSectionHeader_t);

    // @todo RTC 214628
    // Hopefully create a way to tell how much room is left in io_errl
    uint32_t l_bytesAvailableInLog = 4 * KILOBYTE;

    if (l_bytesAvailableInLog > META_SECTION_SIZE)
    {
        errlHndl_t l_errl = nullptr;
        std::vector<uint8_t>l_error_log_data; // explorer error entry data
        l_error_log_data.resize(l_bytesAvailableInLog);
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target(i_ocmb);
        std::vector<uint8_t>l_error_log_dataB; // vector for current_saved_log

        // Make HWP call to grab explorer error log data
        switch (l_log_type)
        {
            case ACTIVE_LOG:
              TRACFCOMP( g_trac_expscom, INFO_MRK "FAPI_INVOKE_HWP "
                            "exp_active_error_log");
              FAPI_INVOKE_HWP( l_errl, exp_active_log,
                             l_fapi_ocmb_target, l_error_log_data );
              break;

            case SAVED_LOG_A:
              TRACFCOMP( g_trac_expscom, INFO_MRK "FAPI_INVOKE_HWP "
                  "exp_saved_log SAVED_LOG_A with max data size: 0x%04X",
                  l_bytesAvailableInLog );
              FAPI_INVOKE_HWP(l_errl, exp_saved_log, mss::exp::ib::EXP_IMAGE_A,
                  0, l_fapi_ocmb_target, l_error_log_data);
              break;

            case SAVED_LOG_B:
              TRACFCOMP( g_trac_expscom, INFO_MRK "FAPI_INVOKE_HWP "
                  "exp_saved_log SAVED_LOG_B with max data size: 0x%04X",
                  l_bytesAvailableInLog );
              FAPI_INVOKE_HWP(l_errl, exp_saved_log, mss::exp::ib::EXP_IMAGE_B,
                  0, l_fapi_ocmb_target, l_error_log_data);
              break;

            case CURRENT_SAVED_LOG:
            case NONCURRENT_SAVED_LOG:
              // Grab both SAVED logs first, then decide which one is current
              // Grabbing both now, so extra traces won't occur in the saved
              // logs for the fw_adapter_properties_get command
              TRACFCOMP( g_trac_expscom, INFO_MRK "FAPI_INVOKE_HWP "
                  "exp_saved_log SAVED_LOG_A with max data size: 0x%04X",
                  l_bytesAvailableInLog );
              FAPI_INVOKE_HWP(l_errl, exp_saved_log, mss::exp::ib::EXP_IMAGE_A,
                  0, l_fapi_ocmb_target, l_error_log_data);
              if (l_errl)
              {
                  break;
              }
              l_error_log_dataB.resize(l_bytesAvailableInLog);
              TRACFCOMP( g_trac_expscom, INFO_MRK "FAPI_INVOKE_HWP "
                  "exp_saved_log SAVED_LOG_B with max data size: 0x%04X",
                  l_bytesAvailableInLog );
              FAPI_INVOKE_HWP(l_errl, exp_saved_log, mss::exp::ib::EXP_IMAGE_B,
                  0, l_fapi_ocmb_target, l_error_log_dataB);
              break;
        }

        // determine which saved log to dump based on current image
        if ( ((i_log_type == CURRENT_SAVED_LOG) ||
              (i_log_type == NONCURRENT_SAVED_LOG)) && (!l_errl) )
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
                    if (i_log_type == CURRENT_SAVED_LOG)
                    {
                        l_log_type = SAVED_LOG_A;
                    }
                    else
                    {
                        // NONCURRENT = B
                        l_log_type = SAVED_LOG_B;
                        l_error_log_data = l_error_log_dataB;
                    }
                }
                else
                {
                    // MSS_EXP_FW_PARTITION_ID_B is current image
                    if (i_log_type == CURRENT_SAVED_LOG)
                    {
                        l_error_log_data = l_error_log_dataB;
                        l_log_type = SAVED_LOG_B;
                    }
                    else
                    {
                        // NONCURRENT = A
                        l_log_type = SAVED_LOG_A;
                    }
                }
            }
            // l_errl is handled later
        }

        if (l_errl)
        {
            // Unable to grab explorer error log data
            TRACFCOMP( g_trac_expscom, ERR_MRK "Unable to grab explorer error log data");
            l_errl->collectTrace(EXPSCOM_COMP_NAME);

            // This error is not a system critical failure, should be just noted
            l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);

            // Associate this error with the original explorer failure log
            l_errl->plid(io_errl->plid());
            errlCommit(l_errl, EXPSCOM_COMP_ID);
        }
        else
        {
            // cycle through data and add sections to io_errl
            // start with a smaller section size then use a larger one for rest
            l_header.error_data_size = FIRST_EXPLORER_DATA_SECTION_SIZE;
            uint32_t l_explorer_bytes_left = l_error_log_data.size();
            const uint8_t * l_start_data_ptr = l_error_log_data.data();

            uint32_t l_current_idx = 0;


            // Remove filler bytes from logs before the useful data starts
            if (l_log_type == ACTIVE_LOG)
            {
                // skip 0x00's at the end of the ACTIVE log
                while ( (l_explorer_bytes_left > 1) &&
                        (l_start_data_ptr[l_explorer_bytes_left-1] == 0x00) )
                {
                    l_explorer_bytes_left--;
                }

                // most recent traces at end of data in ACTIVE log
                l_current_idx = l_explorer_bytes_left;
            }
            else
            {
                // skip 0xFF's at the start of SAVED log
                while ( (l_current_idx < (l_explorer_bytes_left-1)) &&
                        (l_start_data_ptr[l_current_idx] == 0xFF) )
                {
                    l_current_idx++;
                }

                // SAVED log data left after starting from current index
                l_explorer_bytes_left -= l_current_idx;
            }
            TRACUCOMP( g_trac_expscom, "expAddLog: starting index 0x%08X", l_current_idx );

            // while explorer data to append and room in error log
            while (l_explorer_bytes_left && l_bytesAvailableInLog)
            {
                ////////////////////////////////////////////////////////////////
                // Figure out how much data to add for this next section
                // Fill in l_header.error_data_size with that value
                ////////////////////////////////////////////////////////////////

                TRACUCOMP( g_trac_expscom, "l_bytesAvailableInLog: 0x%08X, META_SECTION_SIZE: 0x%08X",
                  l_bytesAvailableInLog, META_SECTION_SIZE );
                TRACUCOMP( g_trac_expscom, "l_explorer_bytes_left: 0x%08X", l_explorer_bytes_left );
                TRACUCOMP( g_trac_expscom, "BEFORE: l_header.error_data_size: 0x%08X", l_header.error_data_size );


                // Can we add a full packet size of error data?
                if (l_bytesAvailableInLog > (l_header.error_data_size + META_SECTION_SIZE))
                {
                    // Check if we don't have full packet of explorer error data
                    if (l_explorer_bytes_left < l_header.error_data_size)
                    {
                        // Reduce the packet size to include the last of explorer error data
                        l_header.error_data_size = l_explorer_bytes_left;
                    }
                }
                else if ( l_bytesAvailableInLog > META_SECTION_SIZE )  // Any room left for another section?
                {
                    // Is there enough explorer error data for room available?
                    if ( l_explorer_bytes_left >=
                         (l_bytesAvailableInLog - META_SECTION_SIZE) )
                    {
                        // Not enough room is available for all the remaining explorer error data
                        // Use up the rest of the space available
                        l_header.error_data_size = l_bytesAvailableInLog - META_SECTION_SIZE;
                    }
                    else
                    {
                        // Room is available but not enough explorer data for full packet size

                        // Don't exclude the most important section by adding this last section
                        // last section should be oldest data section, so least important
                        if ((l_header.packet_num > 2) &&
                            (l_explorer_bytes_left <= FIRST_EXPLORER_DATA_SECTION_SIZE))
                        {
                            TRACFCOMP( g_trac_expscom, "expAddLog: skip adding last section %d of size 0x%.8X",
                                l_header.packet_num, l_explorer_bytes_left);
                            break;
                        }
                        // Reduce the packet size to include the last of explorer error data
                        l_header.error_data_size = l_explorer_bytes_left;
                    }
                }
                else
                {
                    // No more space available in hostboot error log
                    break;
                }

                TRACUCOMP( g_trac_expscom, "AFTER: l_header.error_data_size: 0x%08X", l_header.error_data_size );
                if (l_header.error_data_size == 0)
                {
                    break;
                }

                // Offset into explorer error log data returned
                if (l_log_type == ACTIVE_LOG)
                {
                    // most recent traces at end of data in ACTIVE log
                    TRACUCOMP( g_trac_expscom, "expAddLog: offset_exp_log = 0x%08X - 0x%08X", l_current_idx,  l_header.error_data_size);
                    if (l_header.error_data_size > l_current_idx)
                    {
                        l_header.error_data_size = l_current_idx;
                    }
                    l_header.offset_exp_log = l_current_idx - l_header.error_data_size;
                }
                else
                {
                    l_header.offset_exp_log = l_current_idx;

                    // If this is NOT the first log section
                    // Allow 0xFF for first section to denote empty log
                    if (l_logsAdded)
                    {
                        // skip all 0xFF sections after first one
                        if ( isDataSame(0xFF,
                                       l_start_data_ptr+l_header.offset_exp_log,
                                       l_header.error_data_size) )
                        {
                            // Update to next packet of Explorer error log data
                            // all zeroes for this first packet of data
                            l_explorer_bytes_left -= l_header.error_data_size;

                            // point to start of data
                            l_current_idx += l_header.error_data_size;
                            TRACUCOMP( g_trac_expscom,
                              "expAddLog: Skipping 0x%.8X bytes of 0xFF data at offset 0x%.8X, next index 0x%08X",
                              l_header.error_data_size, l_header.offset_exp_log,
                              l_current_idx );
                            continue;
                        }
                    }
                }

                // Add the section entry to the HWP error log
                switch (l_log_type)
                {
                    case ACTIVE_LOG:
                      ExpscomActiveLogUD(l_header,
                          l_start_data_ptr+l_header.offset_exp_log).addToLog(io_errl);
                      break;

                    case SAVED_LOG_A:
                      ExpscomSavedLogUD(SAVED_IMAGE_A, l_header,
                          l_start_data_ptr+l_header.offset_exp_log).addToLog(io_errl);
                      break;

                    case SAVED_LOG_B:
                      ExpscomSavedLogUD(SAVED_IMAGE_B, l_header,
                          l_start_data_ptr+l_header.offset_exp_log).addToLog(io_errl);
                      break;
                    case CURRENT_SAVED_LOG:
                    case NONCURRENT_SAVED_LOG:
                      break; // not hit here
                }
                l_logsAdded = true;

                // Update to next packet of Explorer error log data
                if (l_log_type == ACTIVE_LOG)
                {
                    // point to end of data
                    l_current_idx -= l_header.error_data_size;
                }
                else
                {
                    // point to start of data
                    l_current_idx += l_header.error_data_size;
                }
                TRACUCOMP( g_trac_expscom, "expAddLog: next index 0x%08X", l_current_idx );

                l_header.packet_num++;
                l_explorer_bytes_left -= l_header.error_data_size;
                if (l_bytesAvailableInLog >= (META_SECTION_SIZE + l_header.error_data_size))
                {
                    l_bytesAvailableInLog -=
                                (META_SECTION_SIZE + l_header.error_data_size);
                }
                else
                {
                    TRACUCOMP(g_trac_expscom, "expAddLog: Last data added was "
                      "over max size (0x%08X + META_SECTION_SIZE 0x%08X > 0x%08X)",
                      l_header.error_data_size, META_SECTION_SIZE, l_bytesAvailableInLog);
                    break;
                }
                l_header.error_data_size = FOLLOWING_EXPLORER_DATA_SECTION_SIZE;
            }
        }
    }
    else
    {
        TRACFCOMP( g_trac_expscom, INFO_MRK
                   "expAddLog: Unable to add any %d type error logs,"
                   " only have %d bytes available in log",
                   i_log_type, l_bytesAvailableInLog );
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
